/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/config/accesslog/v3/accesslog.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/msg_internal.h"
#include "envoy/config/accesslog/v3/accesslog.upb.h"
#include "envoy/config/core/v3/base.upb.h"
#include "envoy/config/route/v3/route_components.upb.h"
#include "envoy/type/matcher/v3/metadata.upb.h"
#include "envoy/type/v3/percent.upb.h"
#include "google/protobuf/any.upb.h"
#include "google/protobuf/wrappers.upb.h"
#include "udpa/annotations/status.upb.h"
#include "udpa/annotations/versioning.upb.h"
#include "validate/validate.upb.h"

#include "upb/port_def.inc"

static const upb_MiniTable_Sub envoy_config_accesslog_v3_AccessLog_submsgs[2] = {
        {.submsg = &envoy_config_accesslog_v3_AccessLogFilter_msginit},
        {.submsg = &google_protobuf_Any_msginit},
};

static const upb_MiniTable_Field envoy_config_accesslog_v3_AccessLog__fields[3] = {
        {1, UPB_SIZE(8, 8),   UPB_SIZE(0, 0),   kUpb_NoSub, 9,
                                                                kUpb_FieldMode_Scalar |
                                                                (kUpb_FieldRep_StringView
                                                                        << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(16, 24), UPB_SIZE(1, 1),   0,          11, kUpb_FieldMode_Scalar |
                                                                (kUpb_FieldRep_Pointer
                                                                        << kUpb_FieldRep_Shift)},
        {4, UPB_SIZE(20, 32), UPB_SIZE(-5, -5), 1,          11, kUpb_FieldMode_Scalar |
                                                                (kUpb_FieldRep_Pointer
                                                                        << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_accesslog_v3_AccessLog_msginit = {
        &envoy_config_accesslog_v3_AccessLog_submsgs[0],
        &envoy_config_accesslog_v3_AccessLog__fields[0],
        UPB_SIZE(24, 40), 3, kUpb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_accesslog_v3_AccessLogFilter_submsgs[12] = {
        {.submsg = &envoy_config_accesslog_v3_StatusCodeFilter_msginit},
        {.submsg = &envoy_config_accesslog_v3_DurationFilter_msginit},
        {.submsg = &envoy_config_accesslog_v3_NotHealthCheckFilter_msginit},
        {.submsg = &envoy_config_accesslog_v3_TraceableFilter_msginit},
        {.submsg = &envoy_config_accesslog_v3_RuntimeFilter_msginit},
        {.submsg = &envoy_config_accesslog_v3_AndFilter_msginit},
        {.submsg = &envoy_config_accesslog_v3_OrFilter_msginit},
        {.submsg = &envoy_config_accesslog_v3_HeaderFilter_msginit},
        {.submsg = &envoy_config_accesslog_v3_ResponseFlagFilter_msginit},
        {.submsg = &envoy_config_accesslog_v3_GrpcStatusFilter_msginit},
        {.submsg = &envoy_config_accesslog_v3_ExtensionFilter_msginit},
        {.submsg = &envoy_config_accesslog_v3_MetadataFilter_msginit},
};

static const upb_MiniTable_Field envoy_config_accesslog_v3_AccessLogFilter__fields[12] = {
        {1,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 0,  11,
                                                       kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
        {2,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 1,  11, kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
        {3,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 2,  11, kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
        {4,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 3,  11, kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
        {5,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 4,  11, kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
        {6,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 5,  11, kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
        {7,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 6,  11, kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
        {8,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 7,  11, kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
        {9,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 8,  11, kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
        {10, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 9,  11, kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
        {11, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 10, 11, kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
        {12, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 11, 11, kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_accesslog_v3_AccessLogFilter_msginit = {
        &envoy_config_accesslog_v3_AccessLogFilter_submsgs[0],
        &envoy_config_accesslog_v3_AccessLogFilter__fields[0],
        UPB_SIZE(8, 16), 12, kUpb_ExtMode_NonExtendable, 12, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_accesslog_v3_ComparisonFilter_submsgs[1] = {
        {.submsg = &envoy_config_core_v3_RuntimeUInt32_msginit},
};

static const upb_MiniTable_Field envoy_config_accesslog_v3_ComparisonFilter__fields[2] = {
        {1, UPB_SIZE(4, 4), UPB_SIZE(0, 0), kUpb_NoSub, 5,
                                                            kUpb_FieldMode_Scalar |
                                                            (kUpb_FieldRep_4Byte
                                                                    << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(8, 8), UPB_SIZE(1, 1), 0,          11, kUpb_FieldMode_Scalar |
                                                            (kUpb_FieldRep_Pointer
                                                                    << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_accesslog_v3_ComparisonFilter_msginit = {
        &envoy_config_accesslog_v3_ComparisonFilter_submsgs[0],
        &envoy_config_accesslog_v3_ComparisonFilter__fields[0],
        UPB_SIZE(16, 16), 2, kUpb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_accesslog_v3_StatusCodeFilter_submsgs[1] = {
        {.submsg = &envoy_config_accesslog_v3_ComparisonFilter_msginit},
};

static const upb_MiniTable_Field envoy_config_accesslog_v3_StatusCodeFilter__fields[1] = {
        {1, UPB_SIZE(4, 8), UPB_SIZE(1, 1), 0, 11,
         kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_accesslog_v3_StatusCodeFilter_msginit = {
        &envoy_config_accesslog_v3_StatusCodeFilter_submsgs[0],
        &envoy_config_accesslog_v3_StatusCodeFilter__fields[0],
        UPB_SIZE(8, 16), 1, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_accesslog_v3_DurationFilter_submsgs[1] = {
        {.submsg = &envoy_config_accesslog_v3_ComparisonFilter_msginit},
};

static const upb_MiniTable_Field envoy_config_accesslog_v3_DurationFilter__fields[1] = {
        {1, UPB_SIZE(4, 8), UPB_SIZE(1, 1), 0, 11,
         kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_accesslog_v3_DurationFilter_msginit = {
        &envoy_config_accesslog_v3_DurationFilter_submsgs[0],
        &envoy_config_accesslog_v3_DurationFilter__fields[0],
        UPB_SIZE(8, 16), 1, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

const upb_MiniTable envoy_config_accesslog_v3_NotHealthCheckFilter_msginit = {
        NULL,
        NULL,
        UPB_SIZE(0, 0), 0, kUpb_ExtMode_NonExtendable, 0, 255, 0,
};

const upb_MiniTable envoy_config_accesslog_v3_TraceableFilter_msginit = {
        NULL,
        NULL,
        UPB_SIZE(0, 0), 0, kUpb_ExtMode_NonExtendable, 0, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_accesslog_v3_RuntimeFilter_submsgs[1] = {
        {.submsg = &envoy_type_v3_FractionalPercent_msginit},
};

static const upb_MiniTable_Field envoy_config_accesslog_v3_RuntimeFilter__fields[3] = {
        {1, UPB_SIZE(4, 8),   UPB_SIZE(0, 0), kUpb_NoSub, 9,
                                                              kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_StringView
                                                                      << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(12, 24), UPB_SIZE(1, 1), 0,          11, kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_Pointer
                                                                      << kUpb_FieldRep_Shift)},
        {3, UPB_SIZE(1, 1),   UPB_SIZE(0, 0), kUpb_NoSub, 8,  kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_1Byte
                                                                      << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_accesslog_v3_RuntimeFilter_msginit = {
        &envoy_config_accesslog_v3_RuntimeFilter_submsgs[0],
        &envoy_config_accesslog_v3_RuntimeFilter__fields[0],
        UPB_SIZE(16, 32), 3, kUpb_ExtMode_NonExtendable, 3, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_accesslog_v3_AndFilter_submsgs[1] = {
        {.submsg = &envoy_config_accesslog_v3_AccessLogFilter_msginit},
};

static const upb_MiniTable_Field envoy_config_accesslog_v3_AndFilter__fields[1] = {
        {1, UPB_SIZE(0, 0), UPB_SIZE(0, 0), 0, 11,
         kUpb_FieldMode_Array | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_accesslog_v3_AndFilter_msginit = {
        &envoy_config_accesslog_v3_AndFilter_submsgs[0],
        &envoy_config_accesslog_v3_AndFilter__fields[0],
        UPB_SIZE(8, 8), 1, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_accesslog_v3_OrFilter_submsgs[1] = {
        {.submsg = &envoy_config_accesslog_v3_AccessLogFilter_msginit},
};

static const upb_MiniTable_Field envoy_config_accesslog_v3_OrFilter__fields[1] = {
        {2, UPB_SIZE(0, 0), UPB_SIZE(0, 0), 0, 11,
         kUpb_FieldMode_Array | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_accesslog_v3_OrFilter_msginit = {
        &envoy_config_accesslog_v3_OrFilter_submsgs[0],
        &envoy_config_accesslog_v3_OrFilter__fields[0],
        UPB_SIZE(8, 8), 1, kUpb_ExtMode_NonExtendable, 0, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_accesslog_v3_HeaderFilter_submsgs[1] = {
        {.submsg = &envoy_config_route_v3_HeaderMatcher_msginit},
};

static const upb_MiniTable_Field envoy_config_accesslog_v3_HeaderFilter__fields[1] = {
        {1, UPB_SIZE(4, 8), UPB_SIZE(1, 1), 0, 11,
         kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_accesslog_v3_HeaderFilter_msginit = {
        &envoy_config_accesslog_v3_HeaderFilter_submsgs[0],
        &envoy_config_accesslog_v3_HeaderFilter__fields[0],
        UPB_SIZE(8, 16), 1, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable_Field envoy_config_accesslog_v3_ResponseFlagFilter__fields[1] = {
        {1, UPB_SIZE(0, 0), UPB_SIZE(0, 0), kUpb_NoSub, 9,
         kUpb_FieldMode_Array | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_accesslog_v3_ResponseFlagFilter_msginit = {
        NULL,
        &envoy_config_accesslog_v3_ResponseFlagFilter__fields[0],
        UPB_SIZE(8, 8), 1, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable_Field envoy_config_accesslog_v3_GrpcStatusFilter__fields[2] = {
        {1, UPB_SIZE(4, 8), UPB_SIZE(0, 0), kUpb_NoSub, 5,
                                                           kUpb_FieldMode_Array |
                                                           kUpb_LabelFlags_IsPacked |
                                                           (kUpb_FieldRep_Pointer
                                                                   << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(0, 0), UPB_SIZE(0, 0), kUpb_NoSub, 8, kUpb_FieldMode_Scalar |
                                                           (kUpb_FieldRep_1Byte
                                                                   << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_accesslog_v3_GrpcStatusFilter_msginit = {
        NULL,
        &envoy_config_accesslog_v3_GrpcStatusFilter__fields[0],
        UPB_SIZE(8, 16), 2, kUpb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_accesslog_v3_MetadataFilter_submsgs[2] = {
        {.submsg = &envoy_type_matcher_v3_MetadataMatcher_msginit},
        {.submsg = &google_protobuf_BoolValue_msginit},
};

static const upb_MiniTable_Field envoy_config_accesslog_v3_MetadataFilter__fields[2] = {
        {1, UPB_SIZE(4, 8),  UPB_SIZE(1, 1), 0, 11,
                                                    kUpb_FieldMode_Scalar |
                                                    (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(8, 16), UPB_SIZE(2, 2), 1, 11, kUpb_FieldMode_Scalar |
                                                    (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_accesslog_v3_MetadataFilter_msginit = {
        &envoy_config_accesslog_v3_MetadataFilter_submsgs[0],
        &envoy_config_accesslog_v3_MetadataFilter__fields[0],
        UPB_SIZE(16, 24), 2, kUpb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_accesslog_v3_ExtensionFilter_submsgs[1] = {
        {.submsg = &google_protobuf_Any_msginit},
};

static const upb_MiniTable_Field envoy_config_accesslog_v3_ExtensionFilter__fields[2] = {
        {1, UPB_SIZE(4, 8),   UPB_SIZE(0, 0),   kUpb_NoSub, 9,
                                                                kUpb_FieldMode_Scalar |
                                                                (kUpb_FieldRep_StringView
                                                                        << kUpb_FieldRep_Shift)},
        {3, UPB_SIZE(12, 24), UPB_SIZE(-1, -1), 0,          11, kUpb_FieldMode_Scalar |
                                                                (kUpb_FieldRep_Pointer
                                                                        << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_accesslog_v3_ExtensionFilter_msginit = {
        &envoy_config_accesslog_v3_ExtensionFilter_submsgs[0],
        &envoy_config_accesslog_v3_ExtensionFilter__fields[0],
        UPB_SIZE(16, 32), 2, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable *messages_layout[15] = {
        &envoy_config_accesslog_v3_AccessLog_msginit,
        &envoy_config_accesslog_v3_AccessLogFilter_msginit,
        &envoy_config_accesslog_v3_ComparisonFilter_msginit,
        &envoy_config_accesslog_v3_StatusCodeFilter_msginit,
        &envoy_config_accesslog_v3_DurationFilter_msginit,
        &envoy_config_accesslog_v3_NotHealthCheckFilter_msginit,
        &envoy_config_accesslog_v3_TraceableFilter_msginit,
        &envoy_config_accesslog_v3_RuntimeFilter_msginit,
        &envoy_config_accesslog_v3_AndFilter_msginit,
        &envoy_config_accesslog_v3_OrFilter_msginit,
        &envoy_config_accesslog_v3_HeaderFilter_msginit,
        &envoy_config_accesslog_v3_ResponseFlagFilter_msginit,
        &envoy_config_accesslog_v3_GrpcStatusFilter_msginit,
        &envoy_config_accesslog_v3_MetadataFilter_msginit,
        &envoy_config_accesslog_v3_ExtensionFilter_msginit,
};

const upb_MiniTable_File envoy_config_accesslog_v3_accesslog_proto_upb_file_layout = {
        messages_layout,
        NULL,
        NULL,
        15,
        0,
        0,
};

#include "upb/port_undef.inc"

