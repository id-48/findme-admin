/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/admin/v3/clusters.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef ENVOY_ADMIN_V3_CLUSTERS_PROTO_UPB_H_
#define ENVOY_ADMIN_V3_CLUSTERS_PROTO_UPB_H_

#include "upb/msg_internal.h"
#include "upb/decode.h"
#include "upb/decode_fast.h"
#include "upb/encode.h"

#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

struct envoy_admin_v3_Clusters;
struct envoy_admin_v3_ClusterStatus;
struct envoy_admin_v3_HostStatus;
struct envoy_admin_v3_HostHealthStatus;
typedef struct envoy_admin_v3_Clusters envoy_admin_v3_Clusters;
typedef struct envoy_admin_v3_ClusterStatus envoy_admin_v3_ClusterStatus;
typedef struct envoy_admin_v3_HostStatus envoy_admin_v3_HostStatus;
typedef struct envoy_admin_v3_HostHealthStatus envoy_admin_v3_HostHealthStatus;
extern const upb_MiniTable envoy_admin_v3_Clusters_msginit;
extern const upb_MiniTable envoy_admin_v3_ClusterStatus_msginit;
extern const upb_MiniTable envoy_admin_v3_HostStatus_msginit;
extern const upb_MiniTable envoy_admin_v3_HostHealthStatus_msginit;
struct envoy_admin_v3_SimpleMetric;
struct envoy_config_cluster_v3_CircuitBreakers;
struct envoy_config_core_v3_Address;
struct envoy_config_core_v3_Locality;
struct envoy_type_v3_Percent;
extern const upb_MiniTable envoy_admin_v3_SimpleMetric_msginit;
extern const upb_MiniTable envoy_config_cluster_v3_CircuitBreakers_msginit;
extern const upb_MiniTable envoy_config_core_v3_Address_msginit;
extern const upb_MiniTable envoy_config_core_v3_Locality_msginit;
extern const upb_MiniTable envoy_type_v3_Percent_msginit;


/* envoy.admin.v3.Clusters */

UPB_INLINE envoy_admin_v3_Clusters
*
envoy_admin_v3_Clusters_new(upb_Arena
* arena) {
return (envoy_admin_v3_Clusters*)
_upb_Message_New(&envoy_admin_v3_Clusters_msginit, arena
);
}
UPB_INLINE envoy_admin_v3_Clusters
*

envoy_admin_v3_Clusters_parse(const char *buf, size_t size, upb_Arena *arena) {
    envoy_admin_v3_Clusters * ret = envoy_admin_v3_Clusters_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_admin_v3_Clusters_msginit, NULL, 0, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE envoy_admin_v3_Clusters
*

envoy_admin_v3_Clusters_parse_ex(const char *buf, size_t size,
                                 const upb_ExtensionRegistry *extreg,
                                 int options, upb_Arena *arena) {
    envoy_admin_v3_Clusters * ret = envoy_admin_v3_Clusters_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_admin_v3_Clusters_msginit, extreg, options, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *
envoy_admin_v3_Clusters_serialize(const envoy_admin_v3_Clusters *msg, upb_Arena *arena,
                                  size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_admin_v3_Clusters_msginit, 0, arena, &ptr, len);
    return ptr;
}

UPB_INLINE char *
envoy_admin_v3_Clusters_serialize_ex(const envoy_admin_v3_Clusters *msg, int options,
                                     upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_admin_v3_Clusters_msginit, options, arena, &ptr, len);
    return ptr;
}

UPB_INLINE bool envoy_admin_v3_Clusters_has_cluster_statuses(const envoy_admin_v3_Clusters *msg) {
    return _upb_has_submsg_nohasbit(msg, UPB_SIZE(0, 0));
}

UPB_INLINE void envoy_admin_v3_Clusters_clear_cluster_statuses(const envoy_admin_v3_Clusters *msg) {
    _upb_array_detach(msg, UPB_SIZE(0, 0));
}

UPB_INLINE const envoy_admin_v3_ClusterStatus
* const*

envoy_admin_v3_Clusters_cluster_statuses(const envoy_admin_v3_Clusters *msg, size_t *len) {
    return (const envoy_admin_v3_ClusterStatus *const *) _upb_array_accessor(msg, UPB_SIZE(0, 0),
                                                                             len);
}

UPB_INLINE envoy_admin_v3_ClusterStatus
**
envoy_admin_v3_Clusters_mutable_cluster_statuses(envoy_admin_v3_Clusters
* msg,
size_t *len
) {
return (envoy_admin_v3_ClusterStatus**)
_upb_array_mutable_accessor(msg, UPB_SIZE(0, 0), len
);
}
UPB_INLINE envoy_admin_v3_ClusterStatus
**
envoy_admin_v3_Clusters_resize_cluster_statuses(envoy_admin_v3_Clusters
* msg,
size_t len, upb_Arena
* arena) {
return (envoy_admin_v3_ClusterStatus**)
_upb_Array_Resize_accessor2(msg, UPB_SIZE(0, 0), len, UPB_SIZE(2, 3), arena
);
}

UPB_INLINE struct envoy_admin_v3_ClusterStatus *
envoy_admin_v3_Clusters_add_cluster_statuses(envoy_admin_v3_Clusters * msg, upb_Arena * arena) {
    struct envoy_admin_v3_ClusterStatus *sub = (struct envoy_admin_v3_ClusterStatus *) _upb_Message_New(
            &envoy_admin_v3_ClusterStatus_msginit, arena);
    bool ok = _upb_Array_Append_accessor2(msg, UPB_SIZE(0, 0), UPB_SIZE(2, 3), &sub, arena);
    if (!ok) return NULL;
    return sub;
}

/* envoy.admin.v3.ClusterStatus */

UPB_INLINE envoy_admin_v3_ClusterStatus
*
envoy_admin_v3_ClusterStatus_new(upb_Arena
* arena) {
return (envoy_admin_v3_ClusterStatus*)
_upb_Message_New(&envoy_admin_v3_ClusterStatus_msginit, arena
);
}
UPB_INLINE envoy_admin_v3_ClusterStatus
*

envoy_admin_v3_ClusterStatus_parse(const char *buf, size_t size, upb_Arena *arena) {
    envoy_admin_v3_ClusterStatus * ret = envoy_admin_v3_ClusterStatus_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_admin_v3_ClusterStatus_msginit, NULL, 0, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE envoy_admin_v3_ClusterStatus
*

envoy_admin_v3_ClusterStatus_parse_ex(const char *buf, size_t size,
                                      const upb_ExtensionRegistry *extreg,
                                      int options, upb_Arena *arena) {
    envoy_admin_v3_ClusterStatus * ret = envoy_admin_v3_ClusterStatus_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_admin_v3_ClusterStatus_msginit, extreg, options, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *
envoy_admin_v3_ClusterStatus_serialize(const envoy_admin_v3_ClusterStatus *msg, upb_Arena *arena,
                                       size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_admin_v3_ClusterStatus_msginit, 0, arena, &ptr, len);
    return ptr;
}

UPB_INLINE char *
envoy_admin_v3_ClusterStatus_serialize_ex(const envoy_admin_v3_ClusterStatus *msg, int options,
                                          upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_admin_v3_ClusterStatus_msginit, options, arena, &ptr, len);
    return ptr;
}

UPB_INLINE void envoy_admin_v3_ClusterStatus_clear_name(const envoy_admin_v3_ClusterStatus *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(4, 8), upb_StringView) = upb_StringView_FromDataAndSize(NULL, 0);
}

UPB_INLINE upb_StringView

envoy_admin_v3_ClusterStatus_name(const envoy_admin_v3_ClusterStatus *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(4, 8), upb_StringView);
}

UPB_INLINE void
envoy_admin_v3_ClusterStatus_clear_added_via_api(const envoy_admin_v3_ClusterStatus *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(1, 1), bool) = 0;
}

UPB_INLINE bool
envoy_admin_v3_ClusterStatus_added_via_api(const envoy_admin_v3_ClusterStatus *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(1, 1), bool);
}

UPB_INLINE bool envoy_admin_v3_ClusterStatus_has_success_rate_ejection_threshold(
        const envoy_admin_v3_ClusterStatus *msg) {
    return _upb_hasbit(msg, 1);
}

UPB_INLINE void envoy_admin_v3_ClusterStatus_clear_success_rate_ejection_threshold(
        const envoy_admin_v3_ClusterStatus *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(12, 24),
    const upb_Message*) = NULL;
}

UPB_INLINE const struct envoy_type_v3_Percent *
envoy_admin_v3_ClusterStatus_success_rate_ejection_threshold(
        const envoy_admin_v3_ClusterStatus *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(12, 24),
    const struct envoy_type_v3_Percent*);
}

UPB_INLINE bool
envoy_admin_v3_ClusterStatus_has_host_statuses(const envoy_admin_v3_ClusterStatus *msg) {
    return _upb_has_submsg_nohasbit(msg, UPB_SIZE(16, 32));
}

UPB_INLINE void
envoy_admin_v3_ClusterStatus_clear_host_statuses(const envoy_admin_v3_ClusterStatus *msg) {
    _upb_array_detach(msg, UPB_SIZE(16, 32));
}

UPB_INLINE const envoy_admin_v3_HostStatus
* const*

envoy_admin_v3_ClusterStatus_host_statuses(const envoy_admin_v3_ClusterStatus *msg, size_t *len) {
    return (const envoy_admin_v3_HostStatus *const *) _upb_array_accessor(msg, UPB_SIZE(16, 32),
                                                                          len);
}

UPB_INLINE bool envoy_admin_v3_ClusterStatus_has_local_origin_success_rate_ejection_threshold(
        const envoy_admin_v3_ClusterStatus *msg) {
    return _upb_hasbit(msg, 2);
}

UPB_INLINE void envoy_admin_v3_ClusterStatus_clear_local_origin_success_rate_ejection_threshold(
        const envoy_admin_v3_ClusterStatus *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(20, 40),
    const upb_Message*) = NULL;
}

UPB_INLINE const struct envoy_type_v3_Percent *
envoy_admin_v3_ClusterStatus_local_origin_success_rate_ejection_threshold(
        const envoy_admin_v3_ClusterStatus *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(20, 40),
    const struct envoy_type_v3_Percent*);
}

UPB_INLINE bool
envoy_admin_v3_ClusterStatus_has_circuit_breakers(const envoy_admin_v3_ClusterStatus *msg) {
    return _upb_hasbit(msg, 3);
}

UPB_INLINE void
envoy_admin_v3_ClusterStatus_clear_circuit_breakers(const envoy_admin_v3_ClusterStatus *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(24, 48),
    const upb_Message*) = NULL;
}

UPB_INLINE const struct envoy_config_cluster_v3_CircuitBreakers *
envoy_admin_v3_ClusterStatus_circuit_breakers(const envoy_admin_v3_ClusterStatus *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(24, 48),
    const struct envoy_config_cluster_v3_CircuitBreakers*);
}

UPB_INLINE void
envoy_admin_v3_ClusterStatus_clear_observability_name(const envoy_admin_v3_ClusterStatus *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(28, 56), upb_StringView) = upb_StringView_FromDataAndSize(NULL, 0);
}

UPB_INLINE upb_StringView

envoy_admin_v3_ClusterStatus_observability_name(const envoy_admin_v3_ClusterStatus *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(28, 56), upb_StringView);
}

UPB_INLINE void envoy_admin_v3_ClusterStatus_set_name(envoy_admin_v3_ClusterStatus * msg,
                                                      upb_StringView
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(4, 8), upb_StringView
) =
value;
}
UPB_INLINE void envoy_admin_v3_ClusterStatus_set_added_via_api(envoy_admin_v3_ClusterStatus * msg,
                                                               bool
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(1, 1),
bool) =
value;
}
UPB_INLINE void envoy_admin_v3_ClusterStatus_set_success_rate_ejection_threshold(
        envoy_admin_v3_ClusterStatus * msg,
struct envoy_type_v3_Percent *value
) {
_upb_sethas(msg,
1);
*
UPB_PTR_AT(msg, UPB_SIZE(12, 24),
struct envoy_type_v3_Percent*) =
value;
}

UPB_INLINE struct envoy_type_v3_Percent *
envoy_admin_v3_ClusterStatus_mutable_success_rate_ejection_threshold(
        envoy_admin_v3_ClusterStatus * msg, upb_Arena * arena) {
    struct envoy_type_v3_Percent *sub = (struct envoy_type_v3_Percent *) envoy_admin_v3_ClusterStatus_success_rate_ejection_threshold(
            msg);
    if (sub == NULL) {
        sub = (struct envoy_type_v3_Percent *) _upb_Message_New(&envoy_type_v3_Percent_msginit,
                                                                arena);
        if (!sub) return NULL;
        envoy_admin_v3_ClusterStatus_set_success_rate_ejection_threshold(msg, sub);
    }
    return sub;
}

UPB_INLINE envoy_admin_v3_HostStatus
**
envoy_admin_v3_ClusterStatus_mutable_host_statuses(envoy_admin_v3_ClusterStatus
* msg,
size_t *len
) {
return (envoy_admin_v3_HostStatus**)
_upb_array_mutable_accessor(msg, UPB_SIZE(16, 32), len
);
}
UPB_INLINE envoy_admin_v3_HostStatus
**
envoy_admin_v3_ClusterStatus_resize_host_statuses(envoy_admin_v3_ClusterStatus
* msg,
size_t len, upb_Arena
* arena) {
return (envoy_admin_v3_HostStatus**)
_upb_Array_Resize_accessor2(msg, UPB_SIZE(16, 32), len, UPB_SIZE(2, 3), arena
);
}

UPB_INLINE struct envoy_admin_v3_HostStatus *
envoy_admin_v3_ClusterStatus_add_host_statuses(envoy_admin_v3_ClusterStatus * msg,
                                               upb_Arena * arena) {
    struct envoy_admin_v3_HostStatus *sub = (struct envoy_admin_v3_HostStatus *) _upb_Message_New(
            &envoy_admin_v3_HostStatus_msginit, arena);
    bool ok = _upb_Array_Append_accessor2(msg, UPB_SIZE(16, 32), UPB_SIZE(2, 3), &sub, arena);
    if (!ok) return NULL;
    return sub;
}

UPB_INLINE void envoy_admin_v3_ClusterStatus_set_local_origin_success_rate_ejection_threshold(
        envoy_admin_v3_ClusterStatus * msg,
struct envoy_type_v3_Percent *value
) {
_upb_sethas(msg,
2);
*
UPB_PTR_AT(msg, UPB_SIZE(20, 40),
struct envoy_type_v3_Percent*) =
value;
}

UPB_INLINE struct envoy_type_v3_Percent *
envoy_admin_v3_ClusterStatus_mutable_local_origin_success_rate_ejection_threshold(
        envoy_admin_v3_ClusterStatus * msg, upb_Arena * arena) {
    struct envoy_type_v3_Percent *sub = (struct envoy_type_v3_Percent *) envoy_admin_v3_ClusterStatus_local_origin_success_rate_ejection_threshold(
            msg);
    if (sub == NULL) {
        sub = (struct envoy_type_v3_Percent *) _upb_Message_New(&envoy_type_v3_Percent_msginit,
                                                                arena);
        if (!sub) return NULL;
        envoy_admin_v3_ClusterStatus_set_local_origin_success_rate_ejection_threshold(msg, sub);
    }
    return sub;
}

UPB_INLINE void envoy_admin_v3_ClusterStatus_set_circuit_breakers(
        envoy_admin_v3_ClusterStatus * msg,
struct envoy_config_cluster_v3_CircuitBreakers *value
) {
_upb_sethas(msg,
3);
*
UPB_PTR_AT(msg, UPB_SIZE(24, 48),
struct envoy_config_cluster_v3_CircuitBreakers*) =
value;
}

UPB_INLINE struct envoy_config_cluster_v3_CircuitBreakers *
envoy_admin_v3_ClusterStatus_mutable_circuit_breakers(envoy_admin_v3_ClusterStatus * msg,
                                                      upb_Arena * arena) {
    struct envoy_config_cluster_v3_CircuitBreakers *sub = (struct envoy_config_cluster_v3_CircuitBreakers *) envoy_admin_v3_ClusterStatus_circuit_breakers(
            msg);
    if (sub == NULL) {
        sub = (struct envoy_config_cluster_v3_CircuitBreakers *) _upb_Message_New(
                &envoy_config_cluster_v3_CircuitBreakers_msginit, arena);
        if (!sub) return NULL;
        envoy_admin_v3_ClusterStatus_set_circuit_breakers(msg, sub);
    }
    return sub;
}

UPB_INLINE void envoy_admin_v3_ClusterStatus_set_observability_name(
        envoy_admin_v3_ClusterStatus * msg, upb_StringView
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(28, 56), upb_StringView
) =
value;
}

/* envoy.admin.v3.HostStatus */

UPB_INLINE envoy_admin_v3_HostStatus
*
envoy_admin_v3_HostStatus_new(upb_Arena
* arena) {
return (envoy_admin_v3_HostStatus*)
_upb_Message_New(&envoy_admin_v3_HostStatus_msginit, arena
);
}
UPB_INLINE envoy_admin_v3_HostStatus
*

envoy_admin_v3_HostStatus_parse(const char *buf, size_t size, upb_Arena *arena) {
    envoy_admin_v3_HostStatus * ret = envoy_admin_v3_HostStatus_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_admin_v3_HostStatus_msginit, NULL, 0, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE envoy_admin_v3_HostStatus
*

envoy_admin_v3_HostStatus_parse_ex(const char *buf, size_t size,
                                   const upb_ExtensionRegistry *extreg,
                                   int options, upb_Arena *arena) {
    envoy_admin_v3_HostStatus * ret = envoy_admin_v3_HostStatus_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_admin_v3_HostStatus_msginit, extreg, options, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *
envoy_admin_v3_HostStatus_serialize(const envoy_admin_v3_HostStatus *msg, upb_Arena *arena,
                                    size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_admin_v3_HostStatus_msginit, 0, arena, &ptr, len);
    return ptr;
}

UPB_INLINE char *
envoy_admin_v3_HostStatus_serialize_ex(const envoy_admin_v3_HostStatus *msg, int options,
                                       upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_admin_v3_HostStatus_msginit, options, arena, &ptr, len);
    return ptr;
}

UPB_INLINE bool envoy_admin_v3_HostStatus_has_address(const envoy_admin_v3_HostStatus *msg) {
    return _upb_hasbit(msg, 1);
}

UPB_INLINE void envoy_admin_v3_HostStatus_clear_address(const envoy_admin_v3_HostStatus *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(12, 16),
    const upb_Message*) = NULL;
}

UPB_INLINE const struct envoy_config_core_v3_Address *
envoy_admin_v3_HostStatus_address(const envoy_admin_v3_HostStatus *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(12, 16),
    const struct envoy_config_core_v3_Address*);
}

UPB_INLINE bool envoy_admin_v3_HostStatus_has_stats(const envoy_admin_v3_HostStatus *msg) {
    return _upb_has_submsg_nohasbit(msg, UPB_SIZE(16, 24));
}

UPB_INLINE void envoy_admin_v3_HostStatus_clear_stats(const envoy_admin_v3_HostStatus *msg) {
    _upb_array_detach(msg, UPB_SIZE(16, 24));
}

UPB_INLINE const struct envoy_admin_v3_SimpleMetric *const *
envoy_admin_v3_HostStatus_stats(const envoy_admin_v3_HostStatus *msg, size_t *len) {
    return (const struct envoy_admin_v3_SimpleMetric *const *) _upb_array_accessor(msg,
                                                                                   UPB_SIZE(16, 24),
                                                                                   len);
}

UPB_INLINE bool envoy_admin_v3_HostStatus_has_health_status(const envoy_admin_v3_HostStatus *msg) {
    return _upb_hasbit(msg, 2);
}

UPB_INLINE void
envoy_admin_v3_HostStatus_clear_health_status(const envoy_admin_v3_HostStatus *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(20, 32),
    const upb_Message*) = NULL;
}

UPB_INLINE const envoy_admin_v3_HostHealthStatus
*

envoy_admin_v3_HostStatus_health_status(const envoy_admin_v3_HostStatus *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(20, 32),
    const envoy_admin_v3_HostHealthStatus*);
}

UPB_INLINE bool envoy_admin_v3_HostStatus_has_success_rate(const envoy_admin_v3_HostStatus *msg) {
    return _upb_hasbit(msg, 3);
}

UPB_INLINE void envoy_admin_v3_HostStatus_clear_success_rate(const envoy_admin_v3_HostStatus *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(24, 40),
    const upb_Message*) = NULL;
}

UPB_INLINE const struct envoy_type_v3_Percent *
envoy_admin_v3_HostStatus_success_rate(const envoy_admin_v3_HostStatus *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(24, 40),
    const struct envoy_type_v3_Percent*);
}

UPB_INLINE void envoy_admin_v3_HostStatus_clear_weight(const envoy_admin_v3_HostStatus *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(4, 4), uint32_t) = 0;
}

UPB_INLINE uint32_t

envoy_admin_v3_HostStatus_weight(const envoy_admin_v3_HostStatus *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(4, 4), uint32_t);
}

UPB_INLINE void envoy_admin_v3_HostStatus_clear_hostname(const envoy_admin_v3_HostStatus *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(28, 48), upb_StringView) = upb_StringView_FromDataAndSize(NULL, 0);
}

UPB_INLINE upb_StringView

envoy_admin_v3_HostStatus_hostname(const envoy_admin_v3_HostStatus *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(28, 48), upb_StringView);
}

UPB_INLINE void envoy_admin_v3_HostStatus_clear_priority(const envoy_admin_v3_HostStatus *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(8, 8), uint32_t) = 0;
}

UPB_INLINE uint32_t

envoy_admin_v3_HostStatus_priority(const envoy_admin_v3_HostStatus *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(8, 8), uint32_t);
}

UPB_INLINE bool
envoy_admin_v3_HostStatus_has_local_origin_success_rate(const envoy_admin_v3_HostStatus *msg) {
    return _upb_hasbit(msg, 4);
}

UPB_INLINE void
envoy_admin_v3_HostStatus_clear_local_origin_success_rate(const envoy_admin_v3_HostStatus *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(36, 64),
    const upb_Message*) = NULL;
}

UPB_INLINE const struct envoy_type_v3_Percent *
envoy_admin_v3_HostStatus_local_origin_success_rate(const envoy_admin_v3_HostStatus *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(36, 64),
    const struct envoy_type_v3_Percent*);
}

UPB_INLINE bool envoy_admin_v3_HostStatus_has_locality(const envoy_admin_v3_HostStatus *msg) {
    return _upb_hasbit(msg, 5);
}

UPB_INLINE void envoy_admin_v3_HostStatus_clear_locality(const envoy_admin_v3_HostStatus *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(40, 72),
    const upb_Message*) = NULL;
}

UPB_INLINE const struct envoy_config_core_v3_Locality *
envoy_admin_v3_HostStatus_locality(const envoy_admin_v3_HostStatus *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(40, 72),
    const struct envoy_config_core_v3_Locality*);
}

UPB_INLINE void envoy_admin_v3_HostStatus_set_address(envoy_admin_v3_HostStatus * msg,
struct envoy_config_core_v3_Address *value
) {
_upb_sethas(msg,
1);
*
UPB_PTR_AT(msg, UPB_SIZE(12, 16),
struct envoy_config_core_v3_Address*) =
value;
}

UPB_INLINE struct envoy_config_core_v3_Address *
envoy_admin_v3_HostStatus_mutable_address(envoy_admin_v3_HostStatus * msg, upb_Arena * arena) {
    struct envoy_config_core_v3_Address *sub = (struct envoy_config_core_v3_Address *) envoy_admin_v3_HostStatus_address(
            msg);
    if (sub == NULL) {
        sub = (struct envoy_config_core_v3_Address *) _upb_Message_New(
                &envoy_config_core_v3_Address_msginit, arena);
        if (!sub) return NULL;
        envoy_admin_v3_HostStatus_set_address(msg, sub);
    }
    return sub;
}

UPB_INLINE struct envoy_admin_v3_SimpleMetric **
envoy_admin_v3_HostStatus_mutable_stats(envoy_admin_v3_HostStatus * msg, size_t * len) {
    return (struct envoy_admin_v3_SimpleMetric **) _upb_array_mutable_accessor(msg,
                                                                               UPB_SIZE(16, 24),
                                                                               len);
}

UPB_INLINE struct envoy_admin_v3_SimpleMetric **envoy_admin_v3_HostStatus_resize_stats(
        envoy_admin_v3_HostStatus * msg, size_t
len,
upb_Arena *arena
) {
return (struct envoy_admin_v3_SimpleMetric**)
_upb_Array_Resize_accessor2(msg, UPB_SIZE(16, 24), len, UPB_SIZE(2, 3), arena
);
}

UPB_INLINE struct envoy_admin_v3_SimpleMetric *
envoy_admin_v3_HostStatus_add_stats(envoy_admin_v3_HostStatus * msg, upb_Arena * arena) {
    struct envoy_admin_v3_SimpleMetric *sub = (struct envoy_admin_v3_SimpleMetric *) _upb_Message_New(
            &envoy_admin_v3_SimpleMetric_msginit, arena);
    bool ok = _upb_Array_Append_accessor2(msg, UPB_SIZE(16, 24), UPB_SIZE(2, 3), &sub, arena);
    if (!ok) return NULL;
    return sub;
}

UPB_INLINE void envoy_admin_v3_HostStatus_set_health_status(envoy_admin_v3_HostStatus * msg,
                                                            envoy_admin_v3_HostHealthStatus *
                                                            value) {
    _upb_sethas(msg, 2);
    *UPB_PTR_AT(msg, UPB_SIZE(20, 32), envoy_admin_v3_HostHealthStatus * ) = value;
}

UPB_INLINE struct envoy_admin_v3_HostHealthStatus *
envoy_admin_v3_HostStatus_mutable_health_status(envoy_admin_v3_HostStatus * msg,
                                                upb_Arena * arena) {
    struct envoy_admin_v3_HostHealthStatus *sub = (struct envoy_admin_v3_HostHealthStatus *) envoy_admin_v3_HostStatus_health_status(
            msg);
    if (sub == NULL) {
        sub = (struct envoy_admin_v3_HostHealthStatus *) _upb_Message_New(
                &envoy_admin_v3_HostHealthStatus_msginit, arena);
        if (!sub) return NULL;
        envoy_admin_v3_HostStatus_set_health_status(msg, sub);
    }
    return sub;
}

UPB_INLINE void envoy_admin_v3_HostStatus_set_success_rate(envoy_admin_v3_HostStatus * msg,
struct envoy_type_v3_Percent *value
) {
_upb_sethas(msg,
3);
*
UPB_PTR_AT(msg, UPB_SIZE(24, 40),
struct envoy_type_v3_Percent*) =
value;
}

UPB_INLINE struct envoy_type_v3_Percent *
envoy_admin_v3_HostStatus_mutable_success_rate(envoy_admin_v3_HostStatus * msg, upb_Arena * arena) {
    struct envoy_type_v3_Percent *sub = (struct envoy_type_v3_Percent *) envoy_admin_v3_HostStatus_success_rate(
            msg);
    if (sub == NULL) {
        sub = (struct envoy_type_v3_Percent *) _upb_Message_New(&envoy_type_v3_Percent_msginit,
                                                                arena);
        if (!sub) return NULL;
        envoy_admin_v3_HostStatus_set_success_rate(msg, sub);
    }
    return sub;
}

UPB_INLINE void envoy_admin_v3_HostStatus_set_weight(envoy_admin_v3_HostStatus * msg, uint32_t
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(4, 4), uint32_t
) =
value;
}
UPB_INLINE void envoy_admin_v3_HostStatus_set_hostname(envoy_admin_v3_HostStatus * msg,
                                                       upb_StringView
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(28, 48), upb_StringView
) =
value;
}
UPB_INLINE void envoy_admin_v3_HostStatus_set_priority(envoy_admin_v3_HostStatus * msg, uint32_t
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(8, 8), uint32_t
) =
value;
}
UPB_INLINE void envoy_admin_v3_HostStatus_set_local_origin_success_rate(
        envoy_admin_v3_HostStatus * msg,
struct envoy_type_v3_Percent *value
) {
_upb_sethas(msg,
4);
*
UPB_PTR_AT(msg, UPB_SIZE(36, 64),
struct envoy_type_v3_Percent*) =
value;
}

UPB_INLINE struct envoy_type_v3_Percent *
envoy_admin_v3_HostStatus_mutable_local_origin_success_rate(envoy_admin_v3_HostStatus * msg,
                                                            upb_Arena * arena) {
    struct envoy_type_v3_Percent *sub = (struct envoy_type_v3_Percent *) envoy_admin_v3_HostStatus_local_origin_success_rate(
            msg);
    if (sub == NULL) {
        sub = (struct envoy_type_v3_Percent *) _upb_Message_New(&envoy_type_v3_Percent_msginit,
                                                                arena);
        if (!sub) return NULL;
        envoy_admin_v3_HostStatus_set_local_origin_success_rate(msg, sub);
    }
    return sub;
}

UPB_INLINE void envoy_admin_v3_HostStatus_set_locality(envoy_admin_v3_HostStatus * msg,
struct envoy_config_core_v3_Locality *value
) {
_upb_sethas(msg,
5);
*
UPB_PTR_AT(msg, UPB_SIZE(40, 72),
struct envoy_config_core_v3_Locality*) =
value;
}

UPB_INLINE struct envoy_config_core_v3_Locality *
envoy_admin_v3_HostStatus_mutable_locality(envoy_admin_v3_HostStatus * msg, upb_Arena * arena) {
    struct envoy_config_core_v3_Locality *sub = (struct envoy_config_core_v3_Locality *) envoy_admin_v3_HostStatus_locality(
            msg);
    if (sub == NULL) {
        sub = (struct envoy_config_core_v3_Locality *) _upb_Message_New(
                &envoy_config_core_v3_Locality_msginit, arena);
        if (!sub) return NULL;
        envoy_admin_v3_HostStatus_set_locality(msg, sub);
    }
    return sub;
}

/* envoy.admin.v3.HostHealthStatus */

UPB_INLINE envoy_admin_v3_HostHealthStatus
*
envoy_admin_v3_HostHealthStatus_new(upb_Arena
* arena) {
return (envoy_admin_v3_HostHealthStatus*)
_upb_Message_New(&envoy_admin_v3_HostHealthStatus_msginit, arena
);
}
UPB_INLINE envoy_admin_v3_HostHealthStatus
*

envoy_admin_v3_HostHealthStatus_parse(const char *buf, size_t size, upb_Arena *arena) {
    envoy_admin_v3_HostHealthStatus * ret = envoy_admin_v3_HostHealthStatus_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_admin_v3_HostHealthStatus_msginit, NULL, 0, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE envoy_admin_v3_HostHealthStatus
*

envoy_admin_v3_HostHealthStatus_parse_ex(const char *buf, size_t size,
                                         const upb_ExtensionRegistry *extreg,
                                         int options, upb_Arena *arena) {
    envoy_admin_v3_HostHealthStatus * ret = envoy_admin_v3_HostHealthStatus_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_admin_v3_HostHealthStatus_msginit, extreg, options,
                   arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *
envoy_admin_v3_HostHealthStatus_serialize(const envoy_admin_v3_HostHealthStatus *msg,
                                          upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_admin_v3_HostHealthStatus_msginit, 0, arena, &ptr, len);
    return ptr;
}

UPB_INLINE char *
envoy_admin_v3_HostHealthStatus_serialize_ex(const envoy_admin_v3_HostHealthStatus *msg,
                                             int options,
                                             upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_admin_v3_HostHealthStatus_msginit, options, arena, &ptr, len);
    return ptr;
}

UPB_INLINE void envoy_admin_v3_HostHealthStatus_clear_failed_active_health_check(
        const envoy_admin_v3_HostHealthStatus *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(0, 0), bool) = 0;
}

UPB_INLINE bool envoy_admin_v3_HostHealthStatus_failed_active_health_check(
        const envoy_admin_v3_HostHealthStatus *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(0, 0), bool);
}

UPB_INLINE void envoy_admin_v3_HostHealthStatus_clear_failed_outlier_check(
        const envoy_admin_v3_HostHealthStatus *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(1, 1), bool) = 0;
}

UPB_INLINE bool
envoy_admin_v3_HostHealthStatus_failed_outlier_check(const envoy_admin_v3_HostHealthStatus *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(1, 1), bool);
}

UPB_INLINE void envoy_admin_v3_HostHealthStatus_clear_eds_health_status(
        const envoy_admin_v3_HostHealthStatus *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(4, 4), int32_t) = 0;
}

UPB_INLINE int32_t

envoy_admin_v3_HostHealthStatus_eds_health_status(const envoy_admin_v3_HostHealthStatus *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(4, 4), int32_t);
}

UPB_INLINE void envoy_admin_v3_HostHealthStatus_clear_failed_active_degraded_check(
        const envoy_admin_v3_HostHealthStatus *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(8, 8), bool) = 0;
}

UPB_INLINE bool envoy_admin_v3_HostHealthStatus_failed_active_degraded_check(
        const envoy_admin_v3_HostHealthStatus *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(8, 8), bool);
}

UPB_INLINE void envoy_admin_v3_HostHealthStatus_clear_pending_dynamic_removal(
        const envoy_admin_v3_HostHealthStatus *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(9, 9), bool) = 0;
}

UPB_INLINE bool envoy_admin_v3_HostHealthStatus_pending_dynamic_removal(
        const envoy_admin_v3_HostHealthStatus *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(9, 9), bool);
}

UPB_INLINE void envoy_admin_v3_HostHealthStatus_clear_pending_active_hc(
        const envoy_admin_v3_HostHealthStatus *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(10, 10), bool) = 0;
}

UPB_INLINE bool
envoy_admin_v3_HostHealthStatus_pending_active_hc(const envoy_admin_v3_HostHealthStatus *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(10, 10), bool);
}

UPB_INLINE void envoy_admin_v3_HostHealthStatus_clear_excluded_via_immediate_hc_fail(
        const envoy_admin_v3_HostHealthStatus *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(11, 11), bool) = 0;
}

UPB_INLINE bool envoy_admin_v3_HostHealthStatus_excluded_via_immediate_hc_fail(
        const envoy_admin_v3_HostHealthStatus *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(11, 11), bool);
}

UPB_INLINE void envoy_admin_v3_HostHealthStatus_clear_active_hc_timeout(
        const envoy_admin_v3_HostHealthStatus *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(12, 12), bool) = 0;
}

UPB_INLINE bool
envoy_admin_v3_HostHealthStatus_active_hc_timeout(const envoy_admin_v3_HostHealthStatus *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(12, 12), bool);
}

UPB_INLINE void envoy_admin_v3_HostHealthStatus_set_failed_active_health_check(
        envoy_admin_v3_HostHealthStatus * msg, bool
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(0, 0),
bool) =
value;
}
UPB_INLINE void envoy_admin_v3_HostHealthStatus_set_failed_outlier_check(
        envoy_admin_v3_HostHealthStatus * msg, bool
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(1, 1),
bool) =
value;
}
UPB_INLINE void envoy_admin_v3_HostHealthStatus_set_eds_health_status(
        envoy_admin_v3_HostHealthStatus * msg, int32_t
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(4, 4), int32_t
) =
value;
}
UPB_INLINE void envoy_admin_v3_HostHealthStatus_set_failed_active_degraded_check(
        envoy_admin_v3_HostHealthStatus * msg, bool
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(8, 8),
bool) =
value;
}
UPB_INLINE void envoy_admin_v3_HostHealthStatus_set_pending_dynamic_removal(
        envoy_admin_v3_HostHealthStatus * msg, bool
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(9, 9),
bool) =
value;
}
UPB_INLINE void envoy_admin_v3_HostHealthStatus_set_pending_active_hc(
        envoy_admin_v3_HostHealthStatus * msg, bool
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(10, 10),
bool) =
value;
}
UPB_INLINE void envoy_admin_v3_HostHealthStatus_set_excluded_via_immediate_hc_fail(
        envoy_admin_v3_HostHealthStatus * msg, bool
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(11, 11),
bool) =
value;
}
UPB_INLINE void envoy_admin_v3_HostHealthStatus_set_active_hc_timeout(
        envoy_admin_v3_HostHealthStatus * msg, bool
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(12, 12),
bool) =
value;
}

extern const upb_MiniTable_File envoy_admin_v3_clusters_proto_upb_file_layout;

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* ENVOY_ADMIN_V3_CLUSTERS_PROTO_UPB_H_ */
