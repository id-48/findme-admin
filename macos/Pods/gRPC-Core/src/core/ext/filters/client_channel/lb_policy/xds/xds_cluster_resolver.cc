//
// Copyright 2018 gRPC authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include <grpc/support/port_platform.h>

#include <inttypes.h>
#include <stddef.h>

#include <algorithm>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include "absl/memory/memory.h"
#include "absl/status/status.h"
#include "absl/status/statusor.h"
#include "absl/strings/str_cat.h"
#include "absl/strings/str_join.h"
#include "absl/strings/string_view.h"
#include "absl/types/optional.h"

#include <grpc/impl/codegen/connectivity_state.h>
#include <grpc/impl/codegen/grpc_types.h>
#include <grpc/support/log.h>

#include "src/core/ext/filters/client_channel/lb_policy/address_filtering.h"
#include "src/core/ext/filters/client_channel/lb_policy/child_policy_handler.h"
#include "src/core/ext/filters/client_channel/lb_policy/outlier_detection/outlier_detection.h"
#include "src/core/ext/filters/client_channel/lb_policy/ring_hash/ring_hash.h"
#include "src/core/ext/filters/client_channel/lb_policy/xds/xds.h"
#include "src/core/ext/filters/client_channel/lb_policy/xds/xds_channel_args.h"
#include "src/core/ext/filters/client_channel/resolver/fake/fake_resolver.h"
#include "src/core/ext/xds/xds_bootstrap.h"
#include "src/core/ext/xds/xds_client.h"
#include "src/core/ext/xds/xds_client_grpc.h"
#include "src/core/ext/xds/xds_client_stats.h"
#include "src/core/ext/xds/xds_endpoint.h"
#include "src/core/ext/xds/xds_resource_type_impl.h"
#include "src/core/lib/channel/channel_args.h"
#include "src/core/lib/config/core_configuration.h"
#include "src/core/lib/debug/trace.h"
#include "src/core/lib/gpr/string.h"
#include "src/core/lib/gprpp/debug_location.h"
#include "src/core/lib/gprpp/orphanable.h"
#include "src/core/lib/gprpp/ref_counted_ptr.h"
#include "src/core/lib/gprpp/work_serializer.h"
#include "src/core/lib/iomgr/error.h"
#include "src/core/lib/iomgr/pollset_set.h"
#include "src/core/lib/json/json.h"
#include "src/core/lib/load_balancing/lb_policy.h"
#include "src/core/lib/load_balancing/lb_policy_factory.h"
#include "src/core/lib/load_balancing/lb_policy_registry.h"
#include "src/core/lib/load_balancing/subchannel_interface.h"
#include "src/core/lib/resolver/resolver.h"
#include "src/core/lib/resolver/resolver_registry.h"
#include "src/core/lib/resolver/server_address.h"
#include "src/core/lib/transport/connectivity_state.h"
#include "src/core/lib/transport/error_utils.h"

#define GRPC_EDS_DEFAULT_FALLBACK_TIMEOUT 10000

namespace grpc_core {

    TraceFlag grpc_lb_xds_cluster_resolver_trace(false, "xds_cluster_resolver_lb");

    const char *kXdsLocalityNameAttributeKey = "xds_locality_name";

    namespace {

        constexpr absl::string_view
        kXdsClusterResolver =
        "xds_cluster_resolver_experimental";

// Config for EDS LB policy.
        class XdsClusterResolverLbConfig : public LoadBalancingPolicy::Config {
        public:
            struct DiscoveryMechanism {
                std::string cluster_name;
                absl::optional <XdsBootstrap::XdsServer> lrs_load_reporting_server;
                uint32_t max_concurrent_requests;
                enum DiscoveryMechanismType {
                    EDS,
                    LOGICAL_DNS,
                };
                DiscoveryMechanismType type;
                std::string eds_service_name;
                std::string dns_hostname;
                absl::optional <Json::Object> outlier_detection_lb_config;

                bool operator==(const DiscoveryMechanism &other) const {
                    return (cluster_name == other.cluster_name &&
                            lrs_load_reporting_server == other.lrs_load_reporting_server &&
                            max_concurrent_requests == other.max_concurrent_requests &&
                            type == other.type &&
                            eds_service_name == other.eds_service_name &&
                            dns_hostname == other.dns_hostname &&
                            outlier_detection_lb_config == other.outlier_detection_lb_config);
                }
            };

            XdsClusterResolverLbConfig(
                    std::vector <DiscoveryMechanism> discovery_mechanisms, Json xds_lb_policy)
                    : discovery_mechanisms_(std::move(discovery_mechanisms)),
                      xds_lb_policy_(std::move(xds_lb_policy)) {}

            absl::string_view name() const override { return kXdsClusterResolver; }

            const std::vector <DiscoveryMechanism> &discovery_mechanisms() const {
                return discovery_mechanisms_;
            }

            const Json &xds_lb_policy() const { return xds_lb_policy_; }

        private:
            std::vector <DiscoveryMechanism> discovery_mechanisms_;
            Json xds_lb_policy_;
        };

// Xds Cluster Resolver LB policy.
        class XdsClusterResolverLb : public LoadBalancingPolicy {
        public:
            XdsClusterResolverLb(RefCountedPtr <XdsClient> xds_client, Args args);

            absl::string_view name() const override { return kXdsClusterResolver; }

            void UpdateLocked(UpdateArgs args) override;

            void ResetBackoffLocked() override;

            void ExitIdleLocked() override;

        private:
            // Discovery Mechanism Base class
            //
            // Implemented by EDS and LOGICAL_DNS.
            //
            // Implementations are responsible for calling the LB policy's
            // OnEndpointChanged(), OnError(), and OnResourceDoesNotExist()
            // methods when the corresponding events occur.
            //
            // Must implement Orphan() method to cancel the watchers.
            class DiscoveryMechanism : public InternallyRefCounted<DiscoveryMechanism> {
            public:
                DiscoveryMechanism(
                        RefCountedPtr <XdsClusterResolverLb> xds_cluster_resolver_lb,
                        size_t index)
                        : parent_(std::move(xds_cluster_resolver_lb)), index_(index) {}

                XdsClusterResolverLb *parent() const { return parent_.get(); }

                size_t index() const { return index_; }

                virtual void Start() = 0;

                virtual Json::Array override_child_policy() = 0;

                virtual bool disable_reresolution() = 0;

            private:
                RefCountedPtr <XdsClusterResolverLb> parent_;
                // Stores its own index in the vector of DiscoveryMechanism.
                size_t index_;
            };

            class EdsDiscoveryMechanism : public DiscoveryMechanism {
            public:
                EdsDiscoveryMechanism(
                        RefCountedPtr <XdsClusterResolverLb> xds_cluster_resolver_lb,
                        size_t index)
                        : DiscoveryMechanism(std::move(xds_cluster_resolver_lb), index) {}

                void Start() override;

                void Orphan() override;

                Json::Array override_child_policy() override { return Json::Array{}; }

                bool disable_reresolution() override { return true; }

            private:
                class EndpointWatcher : public XdsEndpointResourceType::WatcherInterface {
                public:
                    explicit EndpointWatcher(
                            RefCountedPtr <EdsDiscoveryMechanism> discovery_mechanism)
                            : discovery_mechanism_(std::move(discovery_mechanism)) {}

                    ~EndpointWatcher() override {
                        discovery_mechanism_.reset(DEBUG_LOCATION, "EndpointWatcher");
                    }

                    void OnResourceChanged(XdsEndpointResource update) override {
                        Ref().release();  // ref held by callback
                        discovery_mechanism_->parent()->work_serializer()->Run(
                                // TODO(yashykt): When we move to C++14, capture update with
                                // std::move
                                [this, update]() mutable {
                                    OnResourceChangedHelper(std::move(update));
                                    Unref();
                                },
                                DEBUG_LOCATION);
                    }

                    void OnError(absl::Status status) override {
                        Ref().release();  // ref held by callback
                        discovery_mechanism_->parent()->work_serializer()->Run(
                                [this, status]() {
                                    OnErrorHelper(status);
                                    Unref();
                                },
                                DEBUG_LOCATION);
                    }

                    void OnResourceDoesNotExist() override {
                        Ref().release();  // ref held by callback
                        discovery_mechanism_->parent()->work_serializer()->Run(
                                [this]() {
                                    OnResourceDoesNotExistHelper();
                                    Unref();
                                },
                                DEBUG_LOCATION);
                    }

                private:
                    // Code accessing protected methods of `DiscoveryMechanism` need to be
                    // in methods of this class rather than in lambdas to work around an MSVC
                    // bug.
                    void OnResourceChangedHelper(XdsEndpointResource update) {
                        std::string resolution_note;
                        if (update.priorities.empty()) {
                            resolution_note = absl::StrCat(
                                    "EDS resource ", discovery_mechanism_->GetEdsResourceName(),
                                    " contains no localities");
                        } else {
                            std::set <std::string> empty_localities;
                            for (const auto &priority: update.priorities) {
                                for (const auto &p: priority.localities) {
                                    if (p.second.endpoints.empty()) {
                                        empty_localities.insert(p.first->AsHumanReadableString());
                                    }
                                }
                            }
                            if (!empty_localities.empty()) {
                                resolution_note = absl::StrCat(
                                        "EDS resource ", discovery_mechanism_->GetEdsResourceName(),
                                        " contains empty localities: [",
                                        absl::StrJoin(empty_localities, "; "), "]");
                            }
                        }
                        discovery_mechanism_->parent()->OnEndpointChanged(
                                discovery_mechanism_->index(), std::move(update),
                                std::move(resolution_note));
                    }

                    void OnErrorHelper(absl::Status status) {
                        discovery_mechanism_->parent()->OnError(
                                discovery_mechanism_->index(),
                                absl::StrCat("EDS watcher error for resource ",
                                             discovery_mechanism_->GetEdsResourceName(), " (",
                                             status.ToString(), ")"));
                    }

                    void OnResourceDoesNotExistHelper() {
                        discovery_mechanism_->parent()->OnResourceDoesNotExist(
                                discovery_mechanism_->index(),
                                absl::StrCat("EDS resource ",
                                             discovery_mechanism_->GetEdsResourceName(),
                                             " does not exist"));
                    }

                    RefCountedPtr <EdsDiscoveryMechanism> discovery_mechanism_;
                };

                // This is necessary only because of a bug in msvc where nested class
                // cannot access protected member in base class.
                friend class EndpointWatcher;

                absl::string_view GetEdsResourceName() const {
                    auto &config = parent()->config_->discovery_mechanisms()[index()];
                    if (!config.eds_service_name.empty()) return config.eds_service_name;
                    return config.cluster_name;
                }

                // Note that this is not owned, so this pointer must never be dereferenced.
                EndpointWatcher *watcher_ = nullptr;
            };

            class LogicalDNSDiscoveryMechanism : public DiscoveryMechanism {
            public:
                LogicalDNSDiscoveryMechanism(
                        RefCountedPtr <XdsClusterResolverLb> xds_cluster_resolver_lb,
                        size_t index)
                        : DiscoveryMechanism(std::move(xds_cluster_resolver_lb), index) {}

                void Start() override;

                void Orphan() override;

                Json::Array override_child_policy() override {
                    return Json::Array{
                            Json::Object{
                                    {"pick_first", Json::Object()},
                            },
                    };
                }

                bool disable_reresolution() override { return false; };

            private:
                class ResolverResultHandler : public Resolver::ResultHandler {
                public:
                    explicit ResolverResultHandler(
                            RefCountedPtr <LogicalDNSDiscoveryMechanism> discovery_mechanism)
                            : discovery_mechanism_(std::move(discovery_mechanism)) {}

                    ~ResolverResultHandler() override {}

                    void ReportResult(Resolver::Result result) override;

                private:
                    RefCountedPtr <LogicalDNSDiscoveryMechanism> discovery_mechanism_;
                };

                // This is necessary only because of a bug in msvc where nested class cannot
                // access protected member in base class.
                friend class ResolverResultHandler;

                absl::string_view GetDnsHostname() const {
                    auto &config = parent()->config_->discovery_mechanisms()[index()];
                    return config.dns_hostname;
                }

                OrphanablePtr <Resolver> resolver_;
            };

            struct DiscoveryMechanismEntry {
                OrphanablePtr <DiscoveryMechanism> discovery_mechanism;
                // Most recent update reported by the discovery mechanism.
                absl::optional <XdsEndpointResource> latest_update;
                // Last resolution note reported by the discovery mechanism, if any.
                std::string resolution_note;
                // State used to retain child policy names for priority policy.
                std::vector <size_t /*child_number*/> priority_child_numbers;
                size_t next_available_child_number = 0;

                const XdsClusterResolverLbConfig::DiscoveryMechanism &config() const;

                // Returns the child policy name for a given priority.
                std::string GetChildPolicyName(size_t priority) const;
            };

            class Helper : public ChannelControlHelper {
            public:
                explicit Helper(
                        RefCountedPtr <XdsClusterResolverLb> xds_cluster_resolver_policy)
                        : xds_cluster_resolver_policy_(std::move(xds_cluster_resolver_policy)) {
                }

                ~Helper() override {
                    xds_cluster_resolver_policy_.reset(DEBUG_LOCATION, "Helper");
                }

                RefCountedPtr <SubchannelInterface> CreateSubchannel(
                        ServerAddress address, const ChannelArgs &args) override;

                void UpdateState(grpc_connectivity_state state, const absl::Status &status,
                                 std::unique_ptr <SubchannelPicker> picker) override;

                // This is a no-op, because we get the addresses from the xds
                // client, which is a watch-based API.
                void RequestReresolution() override {}

                absl::string_view GetAuthority() override;

                void AddTraceEvent(TraceSeverity severity,
                                   absl::string_view message) override;

            private:
                RefCountedPtr <XdsClusterResolverLb> xds_cluster_resolver_policy_;
            };

            ~XdsClusterResolverLb() override;

            void ShutdownLocked() override;

            void OnEndpointChanged(size_t index, XdsEndpointResource update,
                                   std::string resolution_note);

            void OnError(size_t index, std::string resolution_note);

            void OnResourceDoesNotExist(size_t index, std::string resolution_note);

            void MaybeDestroyChildPolicyLocked();

            void UpdateChildPolicyLocked();

            OrphanablePtr <LoadBalancingPolicy> CreateChildPolicyLocked(
                    const ChannelArgs &args);

            ServerAddressList CreateChildPolicyAddressesLocked();

            std::string CreateChildPolicyResolutionNoteLocked();

            RefCountedPtr <Config> CreateChildPolicyConfigLocked();

            ChannelArgs CreateChildPolicyArgsLocked(const ChannelArgs &args_in);

            // The xds client and endpoint watcher.
            RefCountedPtr <XdsClient> xds_client_;

            // Current channel args and config from the resolver.
            ChannelArgs args_;
            RefCountedPtr <XdsClusterResolverLbConfig> config_;

            // Internal state.
            bool shutting_down_ = false;

            // Vector of discovery mechansism entries in priority order.
            std::vector <DiscoveryMechanismEntry> discovery_mechanisms_;

            OrphanablePtr <LoadBalancingPolicy> child_policy_;
        };

//
// XdsClusterResolverLb::Helper
//

        RefCountedPtr <SubchannelInterface>
        XdsClusterResolverLb::Helper::CreateSubchannel(ServerAddress address,
                                                       const ChannelArgs &args) {
            if (xds_cluster_resolver_policy_->shutting_down_) return nullptr;
            return xds_cluster_resolver_policy_->channel_control_helper()
                    ->CreateSubchannel(std::move(address), args);
        }

        void XdsClusterResolverLb::Helper::UpdateState(
                grpc_connectivity_state state, const absl::Status &status,
                std::unique_ptr <SubchannelPicker> picker) {
            if (xds_cluster_resolver_policy_->shutting_down_ ||
                xds_cluster_resolver_policy_->child_policy_ == nullptr) {
                return;
            }
            if (GRPC_TRACE_FLAG_ENABLED(grpc_lb_xds_cluster_resolver_trace)) {
                gpr_log(GPR_INFO,
                        "[xds_cluster_resolver_lb %p] child policy updated state=%s (%s) "
                        "picker=%p",
                        xds_cluster_resolver_policy_.get(), ConnectivityStateName(state),
                        status.ToString().c_str(), picker.get());
            }
            xds_cluster_resolver_policy_->channel_control_helper()->UpdateState(
                    state, status, std::move(picker));
        }

        absl::string_view XdsClusterResolverLb::Helper::GetAuthority() {
            return xds_cluster_resolver_policy_->channel_control_helper()->GetAuthority();
        }

        void XdsClusterResolverLb::Helper::AddTraceEvent(TraceSeverity severity,
                                                         absl::string_view message) {
            if (xds_cluster_resolver_policy_->shutting_down_) return;
            xds_cluster_resolver_policy_->channel_control_helper()->AddTraceEvent(
                    severity, message);
        }

//
// XdsClusterResolverLb::EdsDiscoveryMechanism
//

        void XdsClusterResolverLb::EdsDiscoveryMechanism::Start() {
            if (GRPC_TRACE_FLAG_ENABLED(grpc_lb_xds_cluster_resolver_trace)) {
                gpr_log(GPR_INFO,
                        "[xds_cluster_resolver_lb %p] eds discovery mechanism %"
                PRIuPTR
                ":%p starting xds watch for %s",
                        parent(), index(), this, std::string(GetEdsResourceName()).c_str());
            }
            auto watcher = MakeRefCounted<EndpointWatcher>(
                    Ref(DEBUG_LOCATION, "EdsDiscoveryMechanism"));
            watcher_ = watcher.get();
            XdsEndpointResourceType::StartWatch(parent()->xds_client_.get(),
                                                GetEdsResourceName(), std::move(watcher));
        }

        void XdsClusterResolverLb::EdsDiscoveryMechanism::Orphan() {
            if (GRPC_TRACE_FLAG_ENABLED(grpc_lb_xds_cluster_resolver_trace)) {
                gpr_log(GPR_INFO,
                        "[xds_cluster_resolver_lb %p] eds discovery mechanism %"
                PRIuPTR
                ":%p cancelling xds watch for %s",
                        parent(), index(), this, std::string(GetEdsResourceName()).c_str());
            }
            XdsEndpointResourceType::CancelWatch(parent()->xds_client_.get(),
                                                 GetEdsResourceName(), watcher_);
            Unref();
        }

//
// XdsClusterResolverLb::LogicalDNSDiscoveryMechanism
//

        void XdsClusterResolverLb::LogicalDNSDiscoveryMechanism::Start() {
            std::string target;
            ChannelArgs args = parent()->args_;
            auto *fake_resolver_response_generator =
                    args.GetPointer<FakeResolverResponseGenerator>(
                            GRPC_ARG_XDS_LOGICAL_DNS_CLUSTER_FAKE_RESOLVER_RESPONSE_GENERATOR);
            if (fake_resolver_response_generator != nullptr) {
                target = absl::StrCat("fake:", GetDnsHostname());
                args = args.SetObject(fake_resolver_response_generator->Ref());
            } else {
                target = absl::StrCat("dns:", GetDnsHostname());
            }
            resolver_ = CoreConfiguration::Get().resolver_registry().CreateResolver(
                    target.c_str(), args, parent()->interested_parties(),
                    parent()->work_serializer(),
                    absl::make_unique<ResolverResultHandler>(
                            Ref(DEBUG_LOCATION, "LogicalDNSDiscoveryMechanism")));
            if (resolver_ == nullptr) {
                parent()->OnResourceDoesNotExist(
                        index(),
                        absl::StrCat("error creating DNS resolver for ", GetDnsHostname()));
                return;
            }
            resolver_->StartLocked();
            if (GRPC_TRACE_FLAG_ENABLED(grpc_lb_xds_cluster_resolver_trace)) {
                gpr_log(GPR_INFO,
                        "[xds_cluster_resolver_lb %p] logical DNS discovery mechanism "
                        "%"
                PRIuPTR
                ":%p starting dns resolver %p",
                        parent(), index(), this, resolver_.get());
            }
        }

        void XdsClusterResolverLb::LogicalDNSDiscoveryMechanism::Orphan() {
            if (GRPC_TRACE_FLAG_ENABLED(grpc_lb_xds_cluster_resolver_trace)) {
                gpr_log(
                        GPR_INFO,
                        "[xds_cluster_resolver_lb %p] logical DNS discovery mechanism %"
                PRIuPTR
                ":%p shutting down dns resolver %p",
                        parent(), index(), this, resolver_.get());
            }
            resolver_.reset();
            Unref();
        }

//
// XdsClusterResolverLb::LogicalDNSDiscoveryMechanism::ResolverResultHandler
//

        void XdsClusterResolverLb::LogicalDNSDiscoveryMechanism::ResolverResultHandler::
        ReportResult(Resolver::Result result) {
            XdsClusterResolverLb *lb_policy = discovery_mechanism_->parent();
            size_t index = discovery_mechanism_->index();
            if (!result.addresses.ok()) {
                if (result.resolution_note.empty()) {
                    result.resolution_note = absl::StrCat(
                            "DNS resolution failed for ", discovery_mechanism_->GetDnsHostname(),
                            " (", result.addresses.status().ToString(), ")");
                }
                lb_policy->OnError(index, result.resolution_note);
                return;
            }
            // Convert resolver result to EDS update.
            XdsEndpointResource update;
            XdsEndpointResource::Priority::Locality locality;
            locality.name = MakeRefCounted<XdsLocalityName>("", "", "");
            locality.lb_weight = 1;
            locality.endpoints = std::move(*result.addresses);
            XdsEndpointResource::Priority priority;
            priority.localities.emplace(locality.name.get(), std::move(locality));
            update.priorities.emplace_back(std::move(priority));
            lb_policy->OnEndpointChanged(index, std::move(update),
                                         std::move(result.resolution_note));
        }

//
// XdsClusterResolverLb::DiscoveryMechanismEntry
//

        const XdsClusterResolverLbConfig::DiscoveryMechanism &
        XdsClusterResolverLb::DiscoveryMechanismEntry::config() const {
            return discovery_mechanism->parent()
                    ->config_->discovery_mechanisms()[discovery_mechanism->index()];
        }

        std::string XdsClusterResolverLb::DiscoveryMechanismEntry::GetChildPolicyName(
                size_t priority) const {
            return absl::StrCat("{cluster=", config().cluster_name,
                                ", child_number=", priority_child_numbers[priority], "}");
        }

//
// XdsClusterResolverLb public methods
//

        XdsClusterResolverLb::XdsClusterResolverLb(RefCountedPtr <XdsClient> xds_client,
                                                   Args args)
                : LoadBalancingPolicy(std::move(args)), xds_client_(std::move(xds_client)) {
            if (GRPC_TRACE_FLAG_ENABLED(grpc_lb_xds_cluster_resolver_trace)) {
                gpr_log(GPR_INFO, "[xds_cluster_resolver_lb %p] created -- xds_client=%p",
                        this, xds_client_.get());
            }
        }

        XdsClusterResolverLb::~XdsClusterResolverLb() {
            if (GRPC_TRACE_FLAG_ENABLED(grpc_lb_xds_cluster_resolver_trace)) {
                gpr_log(GPR_INFO,
                        "[xds_cluster_resolver_lb %p] destroying xds_cluster_resolver LB "
                        "policy",
                        this);
            }
        }

        void XdsClusterResolverLb::ShutdownLocked() {
            if (GRPC_TRACE_FLAG_ENABLED(grpc_lb_xds_cluster_resolver_trace)) {
                gpr_log(GPR_INFO, "[xds_cluster_resolver_lb %p] shutting down", this);
            }
            shutting_down_ = true;
            MaybeDestroyChildPolicyLocked();
            discovery_mechanisms_.clear();
            xds_client_.reset(DEBUG_LOCATION, "XdsClusterResolverLb");
            args_ = ChannelArgs();
        }

        void XdsClusterResolverLb::MaybeDestroyChildPolicyLocked() {
            if (child_policy_ != nullptr) {
                grpc_pollset_set_del_pollset_set(child_policy_->interested_parties(),
                                                 interested_parties());
                child_policy_.reset();
            }
        }

        void XdsClusterResolverLb::UpdateLocked(UpdateArgs args) {
            if (GRPC_TRACE_FLAG_ENABLED(grpc_lb_xds_cluster_resolver_trace)) {
                gpr_log(GPR_INFO, "[xds_cluster_resolver_lb %p] Received update", this);
            }
            const bool is_initial_update = args_ == ChannelArgs();
            // Update config.
            auto old_config = std::move(config_);
            config_ = std::move(args.config);
            // Update args.
            args_ = std::move(args.args);
            // Update child policy if needed.
            if (child_policy_ != nullptr) UpdateChildPolicyLocked();
            // Create endpoint watcher if needed.
            if (is_initial_update) {
                for (const auto &config: config_->discovery_mechanisms()) {
                    DiscoveryMechanismEntry entry;
                    if (config.type == XdsClusterResolverLbConfig::DiscoveryMechanism::
                    DiscoveryMechanismType::EDS) {
                        entry.discovery_mechanism = MakeOrphanable<EdsDiscoveryMechanism>(
                                Ref(DEBUG_LOCATION, "EdsDiscoveryMechanism"),
                                discovery_mechanisms_.size());
                    } else if (config.type == XdsClusterResolverLbConfig::DiscoveryMechanism::
                    DiscoveryMechanismType::LOGICAL_DNS) {
                        entry.discovery_mechanism =
                                MakeOrphanable<LogicalDNSDiscoveryMechanism>(
                                        Ref(DEBUG_LOCATION, "LogicalDNSDiscoveryMechanism"),
                                        discovery_mechanisms_.size());
                    } else {
                        GPR_ASSERT(0);
                    }
                    discovery_mechanisms_.push_back(std::move(entry));
                }
                // Call start() on all discovery mechanisms after creation.
                for (const auto &discovery_mechanism: discovery_mechanisms_) {
                    discovery_mechanism.discovery_mechanism->Start();
                }
            }
        }

        void XdsClusterResolverLb::ResetBackoffLocked() {
            if (child_policy_ != nullptr) {
                child_policy_->ResetBackoffLocked();
            }
        }

        void XdsClusterResolverLb::ExitIdleLocked() {
            if (child_policy_ != nullptr) child_policy_->ExitIdleLocked();
        }

        void XdsClusterResolverLb::OnEndpointChanged(size_t index,
                                                     XdsEndpointResource update,
                                                     std::string resolution_note) {
            if (shutting_down_) return;
            if (GRPC_TRACE_FLAG_ENABLED(grpc_lb_xds_cluster_resolver_trace)) {
                gpr_log(GPR_INFO,
                        "[xds_cluster_resolver_lb %p] Received update from xds client"
                        " for discovery mechanism %"
                PRIuPTR
                " (resolution_note=\"%s\")",
                        this, index, resolution_note.c_str());
            }
            DiscoveryMechanismEntry &discovery_entry = discovery_mechanisms_[index];
            // We need at least one priority for each discovery mechanism, just so that we
            // have a child in which to create the xds_cluster_impl policy.  This ensures
            // that we properly handle the case of a discovery mechanism dropping 100% of
            // calls, the OnError() case, and the OnResourceDoesNotExist() case.
            if (update.priorities.empty()) update.priorities.emplace_back();
            // Update priority_child_numbers, reusing old child numbers in an
            // intelligent way to avoid unnecessary churn.
            // First, build some maps from locality to child number and the reverse
            // from the old data in the entry's update and priority_child_numbers.
            std::map < XdsLocalityName * , size_t /*child_number*/, XdsLocalityName::Less >
                                                                    locality_child_map;
            std::map <size_t, std::set<XdsLocalityName *, XdsLocalityName::Less>>
                    child_locality_map;
            if (discovery_entry.latest_update.has_value()) {
                const auto &prev_priority_list = discovery_entry.latest_update->priorities;
                for (size_t priority = 0; priority < prev_priority_list.size();
                     ++priority) {
                    size_t child_number = discovery_entry.priority_child_numbers[priority];
                    const auto &localities = prev_priority_list[priority].localities;
                    for (const auto &p: localities) {
                        XdsLocalityName *locality_name = p.first;
                        locality_child_map[locality_name] = child_number;
                        child_locality_map[child_number].insert(locality_name);
                    }
                }
            }
            // Construct new list of children.
            std::vector <size_t> priority_child_numbers;
            for (size_t priority = 0; priority < update.priorities.size(); ++priority) {
                const auto &localities = update.priorities[priority].localities;
                absl::optional <size_t> child_number;
                // If one of the localities in this priority already existed, reuse its
                // child number.
                for (const auto &p: localities) {
                    XdsLocalityName *locality_name = p.first;
                    if (!child_number.has_value()) {
                        auto it = locality_child_map.find(locality_name);
                        if (it != locality_child_map.end()) {
                            child_number = it->second;
                            locality_child_map.erase(it);
                            // Remove localities that *used* to be in this child number, so
                            // that we don't incorrectly reuse this child number for a
                            // subsequent priority.
                            for (XdsLocalityName *old_locality:
                                    child_locality_map[*child_number]) {
                                locality_child_map.erase(old_locality);
                            }
                        }
                    } else {
                        // Remove all localities that are now in this child number, so
                        // that we don't accidentally reuse this child number for a
                        // subsequent priority.
                        locality_child_map.erase(locality_name);
                    }
                }
                // If we didn't find an existing child number, assign a new one.
                if (!child_number.has_value()) {
                    for (child_number = discovery_entry.next_available_child_number;
                         child_locality_map.find(*child_number) != child_locality_map.end();
                         ++(*child_number)) {
                    }
                    discovery_entry.next_available_child_number = *child_number + 1;
                    // Add entry so we know that the child number is in use.
                    // (Don't need to add the list of localities, since we won't use them.)
                    child_locality_map[*child_number];
                }
                priority_child_numbers.push_back(*child_number);
            }
            // Save update.
            discovery_entry.latest_update = std::move(update);
            discovery_entry.resolution_note = std::move(resolution_note);
            discovery_entry.priority_child_numbers = std::move(priority_child_numbers);
            // If any discovery mechanism has not received its first update,
            // wait until that happens before creating the child policy.
            // TODO(roth): If this becomes problematic in the future (e.g., a
            // secondary discovery mechanism delaying us from starting up at all),
            // we can consider some sort of optimization whereby we can create the
            // priority policy with only a subset of its children.  But we need to
            // make sure not to get into a situation where the priority policy
            // will put the channel into TRANSIENT_FAILURE instead of CONNECTING
            // while we're still waiting for the other discovery mechanism(s).
            for (DiscoveryMechanismEntry &mechanism: discovery_mechanisms_) {
                if (!mechanism.latest_update.has_value()) return;
            }
            // Update child policy.
            UpdateChildPolicyLocked();
        }

        void XdsClusterResolverLb::OnError(size_t index, std::string resolution_note) {
            gpr_log(GPR_ERROR,
                    "[xds_cluster_resolver_lb %p] discovery mechanism %"
            PRIuPTR
            " reported error: %s",
                    this, index, resolution_note.c_str());
            if (shutting_down_) return;
            if (!discovery_mechanisms_[index].latest_update.has_value()) {
                // Call OnEndpointChanged() with an empty update just like
                // OnResourceDoesNotExist().
                OnEndpointChanged(index, XdsEndpointResource(), std::move(resolution_note));
            }
        }

        void XdsClusterResolverLb::OnResourceDoesNotExist(size_t index,
                                                          std::string resolution_note) {
            gpr_log(GPR_ERROR,
                    "[xds_cluster_resolver_lb %p] discovery mechanism %"
            PRIuPTR
            " resource does not exist: %s",
                    this, index, resolution_note.c_str());
            if (shutting_down_) return;
            // Call OnEndpointChanged() with an empty update.
            OnEndpointChanged(index, XdsEndpointResource(), std::move(resolution_note));
        }

//
// child policy-related methods
//

        ServerAddressList XdsClusterResolverLb::CreateChildPolicyAddressesLocked() {
            ServerAddressList addresses;
            for (const auto &discovery_entry: discovery_mechanisms_) {
                for (size_t priority = 0;
                     priority < discovery_entry.latest_update->priorities.size();
                     ++priority) {
                    const auto &priority_entry =
                            discovery_entry.latest_update->priorities[priority];
                    std::string priority_child_name =
                            discovery_entry.GetChildPolicyName(priority);
                    for (const auto &p: priority_entry.localities) {
                        const auto &locality_name = p.first;
                        const auto &locality = p.second;
                        std::vector <std::string> hierarchical_path = {
                                priority_child_name, locality_name->AsHumanReadableString()};
                        for (const auto &endpoint: locality.endpoints) {
                            const ServerAddressWeightAttribute *weight_attribute = static_cast<
                                    const ServerAddressWeightAttribute *>(endpoint.GetAttribute(
                                            ServerAddressWeightAttribute::kServerAddressWeightAttributeKey));
                            uint32_t weight = locality.lb_weight;
                            if (weight_attribute != nullptr) {
                                weight = locality.lb_weight * weight_attribute->weight();
                            }
                            addresses.emplace_back(
                                    endpoint
                                            .WithAttribute(
                                                    kHierarchicalPathAttributeKey,
                                                    MakeHierarchicalPathAttribute(
                                                            hierarchical_path))
                                            .WithAttribute(kXdsLocalityNameAttributeKey,
                                                           absl::make_unique<XdsLocalityAttribute>(
                                                                   locality_name->Ref()))
                                            .WithAttribute(
                                                    ServerAddressWeightAttribute::
                                                    kServerAddressWeightAttributeKey,
                                                    absl::make_unique<ServerAddressWeightAttribute>(
                                                            weight)));
                        }
                    }
                }
            }
            return addresses;
        }

        std::string XdsClusterResolverLb::CreateChildPolicyResolutionNoteLocked() {
            std::vector <absl::string_view> resolution_notes;
            for (const auto &discovery_entry: discovery_mechanisms_) {
                if (!discovery_entry.resolution_note.empty()) {
                    resolution_notes.push_back(discovery_entry.resolution_note);
                }
            }
            return absl::StrJoin(resolution_notes, "; ");
        }

        RefCountedPtr <LoadBalancingPolicy::Config>
        XdsClusterResolverLb::CreateChildPolicyConfigLocked() {
            Json::Object priority_children;
            Json::Array priority_priorities;
            for (const auto &discovery_entry: discovery_mechanisms_) {
                const auto &discovery_config = discovery_entry.config();
                for (size_t priority = 0;
                     priority < discovery_entry.latest_update->priorities.size();
                     ++priority) {
                    const auto &priority_entry =
                            discovery_entry.latest_update->priorities[priority];
                    Json child_policy;
                    if (!discovery_entry.discovery_mechanism->override_child_policy()
                            .empty()) {
                        child_policy =
                                discovery_entry.discovery_mechanism->override_child_policy();
                    } else {
                        const auto &xds_lb_policy = config_->xds_lb_policy().object_value();
                        if (xds_lb_policy.find("ROUND_ROBIN") != xds_lb_policy.end()) {
                            const auto &localities = priority_entry.localities;
                            Json::Object weighted_targets;
                            for (const auto &p: localities) {
                                XdsLocalityName *locality_name = p.first;
                                const auto &locality = p.second;
                                // Add weighted target entry.
                                weighted_targets[locality_name->AsHumanReadableString()] =
                                        Json::Object{
                                                {"weight", locality.lb_weight},
                                                {"childPolicy",
                                                           Json::Array{
                                                                   Json::Object{
                                                                           {"round_robin",
                                                                            Json::Object()},
                                                                   },
                                                           }},
                                        };
                            }
                            // Construct locality-picking policy.
                            // Start with field from our config and add the "targets" field.
                            child_policy = Json::Array{
                                    Json::Object{
                                            {"weighted_target_experimental",
                                             Json::Object{
                                                     {"targets", Json::Object()},
                                             }},
                                    },
                            };
                            Json::Object &config =
                                    *(*child_policy.mutable_array())[0].mutable_object();
                            auto it = config.begin();
                            GPR_ASSERT(it != config.end());
                            (*it->second.mutable_object())["targets"] =
                                    std::move(weighted_targets);
                        } else {
                            auto it = xds_lb_policy.find("RING_HASH");
                            GPR_ASSERT(it != xds_lb_policy.end());
                            Json::Object ring_hash_experimental_policy =
                                    it->second.object_value();
                            child_policy = Json::Array{
                                    Json::Object{
                                            {"ring_hash_experimental",
                                             ring_hash_experimental_policy},
                                    },
                            };
                        }
                    }
                    // Wrap it in the drop policy.
                    Json::Array drop_categories;
                    if (discovery_entry.latest_update->drop_config != nullptr) {
                        for (const auto &category:
                                discovery_entry.latest_update->drop_config->drop_category_list()) {
                            drop_categories.push_back(Json::Object{
                                    {"category",             category.name},
                                    {"requests_per_million", category.parts_per_million},
                            });
                        }
                    }
                    Json::Object xds_cluster_impl_config = {
                            {"clusterName",           discovery_config.cluster_name},
                            {"childPolicy",           std::move(child_policy)},
                            {"dropCategories",        std::move(drop_categories)},
                            {"maxConcurrentRequests", discovery_config.max_concurrent_requests},
                    };
                    if (!discovery_config.eds_service_name.empty()) {
                        xds_cluster_impl_config["edsServiceName"] =
                                discovery_config.eds_service_name;
                    }
                    if (discovery_config.lrs_load_reporting_server.has_value()) {
                        xds_cluster_impl_config["lrsLoadReportingServer"] =
                                discovery_config.lrs_load_reporting_server->ToJson();
                    }
                    Json locality_picking_policy;
                    if (XdsOutlierDetectionEnabled()) {
                        Json::Object outlier_detection_config;
                        if (discovery_entry.config().outlier_detection_lb_config.has_value()) {
                            outlier_detection_config =
                                    discovery_entry.config().outlier_detection_lb_config.value();
                        }
                        outlier_detection_config["childPolicy"] = Json::Array{Json::Object{
                                {"xds_cluster_impl_experimental",
                                 std::move(xds_cluster_impl_config)},
                        }};
                        locality_picking_policy = Json::Array{Json::Object{
                                {"outlier_detection_experimental",
                                 std::move(outlier_detection_config)},
                        }};
                    } else {
                        locality_picking_policy = Json::Array{Json::Object{
                                {"xds_cluster_impl_experimental",
                                 std::move(xds_cluster_impl_config)},
                        }};
                    }
                    // Add priority entry, with the appropriate child name.
                    std::string child_name = discovery_entry.GetChildPolicyName(priority);
                    priority_priorities.emplace_back(child_name);
                    Json::Object child_config = {
                            {"config", std::move(locality_picking_policy)},
                    };
                    if (discovery_entry.discovery_mechanism->disable_reresolution()) {
                        child_config["ignore_reresolution_requests"] = true;
                    }
                    priority_children[child_name] = std::move(child_config);
                }
            }
            Json json = Json::Array{Json::Object{
                    {"priority_experimental",
                     Json::Object{
                             {"children",   std::move(priority_children)},
                             {"priorities", std::move(priority_priorities)},
                     }},
            }};
            if (GRPC_TRACE_FLAG_ENABLED(grpc_lb_xds_cluster_resolver_trace)) {
                std::string json_str = json.Dump(/*indent=*/1);
                gpr_log(
                        GPR_INFO,
                        "[xds_cluster_resolver_lb %p] generated config for child policy: %s",
                        this, json_str.c_str());
            }
            auto config = LoadBalancingPolicyRegistry::ParseLoadBalancingConfig(json);
            if (!config.ok()) {
                // This should never happen, but if it does, we basically have no
                // way to fix it, so we put the channel in TRANSIENT_FAILURE.
                gpr_log(GPR_ERROR,
                        "[xds_cluster_resolver_lb %p] error parsing generated child policy "
                        "config -- "
                        "will put channel in TRANSIENT_FAILURE: %s",
                        this, config.status().ToString().c_str());
                absl::Status status = absl::InternalError(
                        "xds_cluster_resolver LB policy: error parsing generated child policy "
                        "config");
                channel_control_helper()->UpdateState(
                        GRPC_CHANNEL_TRANSIENT_FAILURE, status,
                        absl::make_unique<TransientFailurePicker>(status));
                return nullptr;
            }
            return std::move(*config);
        }

        void XdsClusterResolverLb::UpdateChildPolicyLocked() {
            if (shutting_down_) return;
            UpdateArgs update_args;
            update_args.config = CreateChildPolicyConfigLocked();
            if (update_args.config == nullptr) return;
            update_args.addresses = CreateChildPolicyAddressesLocked();
            update_args.resolution_note = CreateChildPolicyResolutionNoteLocked();
            update_args.args = CreateChildPolicyArgsLocked(args_);
            if (child_policy_ == nullptr) {
                child_policy_ = CreateChildPolicyLocked(update_args.args);
            }
            if (GRPC_TRACE_FLAG_ENABLED(grpc_lb_xds_cluster_resolver_trace)) {
                gpr_log(GPR_INFO, "[xds_cluster_resolver_lb %p] Updating child policy %p",
                        this, child_policy_.get());
            }
            child_policy_->UpdateLocked(std::move(update_args));
        }

        ChannelArgs XdsClusterResolverLb::CreateChildPolicyArgsLocked(
                const ChannelArgs &args) {
            // Inhibit client-side health checking, since the balancer does this
            // for us.
            return args.Set(GRPC_ARG_INHIBIT_HEALTH_CHECKING, 1);
        }

        OrphanablePtr <LoadBalancingPolicy>
        XdsClusterResolverLb::CreateChildPolicyLocked(const ChannelArgs &args) {
            LoadBalancingPolicy::Args lb_policy_args;
            lb_policy_args.work_serializer = work_serializer();
            lb_policy_args.args = args;
            lb_policy_args.channel_control_helper =
                    absl::make_unique<Helper>(Ref(DEBUG_LOCATION, "Helper"));
            OrphanablePtr <LoadBalancingPolicy> lb_policy =
                    LoadBalancingPolicyRegistry::CreateLoadBalancingPolicy(
                            "priority_experimental", std::move(lb_policy_args));
            if (GPR_UNLIKELY(lb_policy == nullptr)) {
                gpr_log(GPR_ERROR,
                        "[xds_cluster_resolver_lb %p] failure creating child policy", this);
                return nullptr;
            }
            if (GRPC_TRACE_FLAG_ENABLED(grpc_lb_xds_cluster_resolver_trace)) {
                gpr_log(GPR_INFO,
                        "[xds_cluster_resolver_lb %p]: Created new child policy %p", this,
                        lb_policy.get());
            }
            // Add our interested_parties pollset_set to that of the newly created
            // child policy. This will make the child policy progress upon activity on
            // this policy, which in turn is tied to the application's call.
            grpc_pollset_set_add_pollset_set(lb_policy->interested_parties(),
                                             interested_parties());
            return lb_policy;
        }

//
// factory
//

        class XdsClusterResolverLbFactory : public LoadBalancingPolicyFactory {
        public:
            OrphanablePtr <LoadBalancingPolicy> CreateLoadBalancingPolicy(
                    LoadBalancingPolicy::Args args) const override {
                auto xds_client = args.args.GetObjectRef<GrpcXdsClient>(
                        DEBUG_LOCATION, "XdsClusterResolverLbFactory");
                if (xds_client == nullptr) {
                    gpr_log(GPR_ERROR,
                            "XdsClient not present in channel args -- cannot instantiate "
                            "xds_cluster_resolver LB policy");
                    return nullptr;
                }
                return MakeOrphanable<XdsClusterResolverChildHandler>(std::move(xds_client),
                                                                      std::move(args));
            }

            absl::string_view name() const override { return kXdsClusterResolver; }

            absl::StatusOr <RefCountedPtr<LoadBalancingPolicy::Config>>
            ParseLoadBalancingConfig(const Json &json) const override {
                if (json.type() == Json::Type::JSON_NULL) {
                    // xds_cluster_resolver was mentioned as a policy in the deprecated
                    // loadBalancingPolicy field or in the client API.
                    return absl::InvalidArgumentError(
                            "field:loadBalancingPolicy error:xds_cluster_resolver policy "
                            "requires configuration. "
                            "Please use loadBalancingConfig field of service config instead.");
                }
                std::vector <grpc_error_handle> error_list;
                std::vector <XdsClusterResolverLbConfig::DiscoveryMechanism>
                        discovery_mechanisms;
                auto it = json.object_value().find("discoveryMechanisms");
                if (it == json.object_value().end()) {
                    error_list.push_back(GRPC_ERROR_CREATE_FROM_STATIC_STRING(
                            "field:discoveryMechanisms error:required field missing"));
                } else if (it->second.type() != Json::Type::ARRAY) {
                    error_list.push_back(GRPC_ERROR_CREATE_FROM_STATIC_STRING(
                            "field:discoveryMechanisms error:type should be array"));
                } else {
                    const Json::Array &array = it->second.array_value();
                    for (size_t i = 0; i < array.size(); ++i) {
                        XdsClusterResolverLbConfig::DiscoveryMechanism discovery_mechanism;
                        std::vector <grpc_error_handle> discovery_mechanism_errors =
                                ParseDiscoveryMechanism(array[i], &discovery_mechanism);
                        if (!discovery_mechanism_errors.empty()) {
                            grpc_error_handle error = GRPC_ERROR_CREATE_FROM_CPP_STRING(
                                    absl::StrCat("field:discovery_mechanism element: ", i,
                                                 " error"));
                            for (const grpc_error_handle &discovery_mechanism_error:
                                    discovery_mechanism_errors) {
                                error = grpc_error_add_child(error, discovery_mechanism_error);
                            }
                            error_list.push_back(error);
                        }
                        discovery_mechanisms.emplace_back(std::move(discovery_mechanism));
                    }
                }
                if (discovery_mechanisms.empty()) {
                    error_list.push_back(GRPC_ERROR_CREATE_FROM_STATIC_STRING(
                            "field:discovery_mechanism error:list is missing or empty"));
                }
                Json xds_lb_policy = Json::Object{
                        {"ROUND_ROBIN", Json::Object()},
                };
                it = json.object_value().find("xdsLbPolicy");
                if (it != json.object_value().end()) {
                    if (it->second.type() != Json::Type::ARRAY) {
                        error_list.push_back(GRPC_ERROR_CREATE_FROM_STATIC_STRING(
                                "field:xdsLbPolicy error:type should be array"));
                    } else {
                        const Json::Array &array = it->second.array_value();
                        for (size_t i = 0; i < array.size(); ++i) {
                            if (array[i].type() != Json::Type::OBJECT) {
                                error_list.push_back(GRPC_ERROR_CREATE_FROM_STATIC_STRING(
                                        "field:xdsLbPolicy error:element should be of type object"));
                                continue;
                            }
                            const Json::Object &policy = array[i].object_value();
                            auto policy_it = policy.find("ROUND_ROBIN");
                            if (policy_it != policy.end()) {
                                if (policy_it->second.type() != Json::Type::OBJECT) {
                                    error_list.push_back(GRPC_ERROR_CREATE_FROM_STATIC_STRING(
                                            "field:ROUND_ROBIN error:type should be object"));
                                }
                                break;
                            }
                            policy_it = policy.find("RING_HASH");
                            if (policy_it != policy.end()) {
                                xds_lb_policy = array[i];
                                auto config = ParseRingHashLbConfig(policy_it->second);
                                if (!config.ok()) {
                                    error_list.emplace_back(
                                            absl_status_to_grpc_error(config.status()));
                                }
                            }
                        }
                    }
                }
                // Construct config.
                if (error_list.empty()) {
                    return MakeRefCounted<XdsClusterResolverLbConfig>(
                            std::move(discovery_mechanisms), std::move(xds_lb_policy));
                } else {
                    grpc_error_handle error = GRPC_ERROR_CREATE_FROM_VECTOR(
                            "xds_cluster_resolver_experimental LB policy config", &error_list);
                    absl::Status status = grpc_error_to_absl_status(error);
                    GRPC_ERROR_UNREF(error);
                    return status;
                }
            }

        private:
            static std::vector <grpc_error_handle> ParseDiscoveryMechanism(
                    const Json &json,
                    XdsClusterResolverLbConfig::DiscoveryMechanism *discovery_mechanism) {
                std::vector <grpc_error_handle> error_list;
                if (json.type() != Json::Type::OBJECT) {
                    error_list.push_back(GRPC_ERROR_CREATE_FROM_STATIC_STRING(
                            "value should be of type object"));
                    return error_list;
                }
                // Cluster name.
                auto it = json.object_value().find("clusterName");
                if (it == json.object_value().end()) {
                    error_list.push_back(GRPC_ERROR_CREATE_FROM_STATIC_STRING(
                            "field:clusterName error:required field missing"));
                } else if (it->second.type() != Json::Type::STRING) {
                    error_list.push_back(GRPC_ERROR_CREATE_FROM_STATIC_STRING(
                            "field:clusterName error:type should be string"));
                } else {
                    discovery_mechanism->cluster_name = it->second.string_value();
                }
                // LRS load reporting server name.
                it = json.object_value().find("lrsLoadReportingServer");
                if (it != json.object_value().end()) {
                    if (it->second.type() != Json::Type::OBJECT) {
                        error_list.push_back(GRPC_ERROR_CREATE_FROM_STATIC_STRING(
                                "field:lrsLoadReportingServer error:type should be object"));
                    } else {
                        grpc_error_handle parse_error;
                        discovery_mechanism->lrs_load_reporting_server.emplace(
                                XdsBootstrap::XdsServer::Parse(it->second, &parse_error));
                        if (!GRPC_ERROR_IS_NONE(parse_error)) {
                            error_list.push_back(GRPC_ERROR_CREATE_FROM_CPP_STRING(
                                    absl::StrCat("errors parsing lrs_load_reporting_server")));
                            error_list.push_back(parse_error);
                        }
                    }
                }
                // Max concurrent requests.
                discovery_mechanism->max_concurrent_requests = 1024;
                it = json.object_value().find("max_concurrent_requests");
                if (it != json.object_value().end()) {
                    if (it->second.type() != Json::Type::NUMBER) {
                        error_list.push_back(GRPC_ERROR_CREATE_FROM_STATIC_STRING(
                                "field:max_concurrent_requests error:must be of type number"));
                    } else {
                        discovery_mechanism->max_concurrent_requests =
                                gpr_parse_nonnegative_int(it->second.string_value().c_str());
                    }
                }
                if (XdsOutlierDetectionEnabled()) {
                    it = json.object_value().find("outlierDetection");
                    if (it != json.object_value().end()) {
                        if (it->second.type() != Json::Type::OBJECT) {
                            error_list.push_back(GRPC_ERROR_CREATE_FROM_STATIC_STRING(
                                    "field:outlierDetection error:type should be object"));
                        } else {
                            // No need to validate the contents of the outlier detection config,
                            // because in this particular case, the JSON is generated by the CDS
                            // policy instead of coming from service config, so it's not actually
                            // any better to catch the problem here than it is to catch it in the
                            // outlier_detection policy itself, so here we just act as a
                            // pass-through.
                            discovery_mechanism->outlier_detection_lb_config =
                                    it->second.object_value();
                        }
                    }
                }
                // Discovery Mechanism type
                it = json.object_value().find("type");
                if (it == json.object_value().end()) {
                    error_list.push_back(GRPC_ERROR_CREATE_FROM_STATIC_STRING(
                            "field:type error:required field missing"));
                } else if (it->second.type() != Json::Type::STRING) {
                    error_list.push_back(GRPC_ERROR_CREATE_FROM_STATIC_STRING(
                            "field:type error:type should be string"));
                } else {
                    if (it->second.string_value() == "EDS") {
                        discovery_mechanism->type = XdsClusterResolverLbConfig::
                        DiscoveryMechanism::DiscoveryMechanismType::EDS;
                        it = json.object_value().find("edsServiceName");
                        if (it != json.object_value().end()) {
                            if (it->second.type() != Json::Type::STRING) {
                                error_list.push_back(GRPC_ERROR_CREATE_FROM_STATIC_STRING(
                                        "field:edsServiceName error:type should be string"));
                            } else {
                                discovery_mechanism->eds_service_name = it->second.string_value();
                            }
                        }
                    } else if (it->second.string_value() == "LOGICAL_DNS") {
                        discovery_mechanism->type = XdsClusterResolverLbConfig::
                        DiscoveryMechanism::DiscoveryMechanismType::LOGICAL_DNS;
                        it = json.object_value().find("dnsHostname");
                        if (it == json.object_value().end()) {
                            error_list.push_back(GRPC_ERROR_CREATE_FROM_STATIC_STRING(
                                    "field:dnsHostname error:required field missing"));
                        } else if (it->second.type() != Json::Type::STRING) {
                            error_list.push_back(GRPC_ERROR_CREATE_FROM_STATIC_STRING(
                                    "field:dnsHostname error:type should be string"));
                        } else {
                            discovery_mechanism->dns_hostname = it->second.string_value();
                        }
                    } else {
                        error_list.push_back(GRPC_ERROR_CREATE_FROM_STATIC_STRING(
                                "field:type error:invalid type"));
                    }
                }
                return error_list;
            }

            class XdsClusterResolverChildHandler : public ChildPolicyHandler {
            public:
                XdsClusterResolverChildHandler(RefCountedPtr <XdsClient> xds_client,
                                               Args args)
                        : ChildPolicyHandler(std::move(args),
                                             &grpc_lb_xds_cluster_resolver_trace),
                          xds_client_(std::move(xds_client)) {}

                ~XdsClusterResolverChildHandler() override {
                    xds_client_.reset(DEBUG_LOCATION, "XdsClusterResolverChildHandler");
                }

                bool ConfigChangeRequiresNewPolicyInstance(
                        LoadBalancingPolicy::Config *old_config,
                        LoadBalancingPolicy::Config *new_config) const override {
                    GPR_ASSERT(old_config->name() == kXdsClusterResolver);
                    GPR_ASSERT(new_config->name() == kXdsClusterResolver);
                    XdsClusterResolverLbConfig *old_xds_cluster_resolver_config =
                            static_cast<XdsClusterResolverLbConfig *>(old_config);
                    XdsClusterResolverLbConfig *new_xds_cluster_resolver_config =
                            static_cast<XdsClusterResolverLbConfig *>(new_config);
                    if (old_xds_cluster_resolver_config->discovery_mechanisms().size() !=
                        new_xds_cluster_resolver_config->discovery_mechanisms().size()) {
                        return true;
                    }
                    for (size_t i = 0;
                         i < old_xds_cluster_resolver_config->discovery_mechanisms().size();
                         ++i) {
                        auto &old_discovery_mechanism =
                                old_xds_cluster_resolver_config->discovery_mechanisms()[i];
                        auto &new_discovery_mechanism =
                                new_xds_cluster_resolver_config->discovery_mechanisms()[i];
                        if (old_discovery_mechanism.type != new_discovery_mechanism.type ||
                            old_discovery_mechanism.cluster_name !=
                            new_discovery_mechanism.cluster_name ||
                            old_discovery_mechanism.eds_service_name !=
                            new_discovery_mechanism.eds_service_name ||
                            old_discovery_mechanism.dns_hostname !=
                            new_discovery_mechanism.dns_hostname ||
                            !(old_discovery_mechanism.lrs_load_reporting_server ==
                              new_discovery_mechanism.lrs_load_reporting_server)) {
                            return true;
                        }
                    }
                    return false;
                }

                OrphanablePtr <LoadBalancingPolicy> CreateLoadBalancingPolicy(
                        absl::string_view /*name*/,
                        LoadBalancingPolicy::Args args) const override {
                    return MakeOrphanable<XdsClusterResolverLb>(
                            xds_client_->Ref(DEBUG_LOCATION, "XdsClusterResolverLb"),
                            std::move(args));
                }

            private:
                RefCountedPtr <XdsClient> xds_client_;
            };
        };

    }  // namespace

}  // namespace grpc_core

//
// Plugin registration
//

void grpc_lb_policy_xds_cluster_resolver_init() {
    grpc_core::LoadBalancingPolicyRegistry::Builder::
    RegisterLoadBalancingPolicyFactory(
            absl::make_unique<grpc_core::XdsClusterResolverLbFactory>());
}

void grpc_lb_policy_xds_cluster_resolver_shutdown() {}