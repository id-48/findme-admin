/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/extensions/filters/http/router/v3/router.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/msg_internal.h"
#include "envoy/extensions/filters/http/router/v3/router.upb.h"
#include "envoy/config/accesslog/v3/accesslog.upb.h"
#include "google/protobuf/wrappers.upb.h"
#include "udpa/annotations/status.upb.h"
#include "udpa/annotations/versioning.upb.h"
#include "validate/validate.upb.h"

#include "upb/port_def.inc"

static const upb_MiniTable_Sub envoy_extensions_filters_http_router_v3_Router_submsgs[2] = {
        {.submsg = &google_protobuf_BoolValue_msginit},
        {.submsg = &envoy_config_accesslog_v3_AccessLog_msginit},
};

static const upb_MiniTable_Field envoy_extensions_filters_http_router_v3_Router__fields[7] = {
        {1, UPB_SIZE(8, 8),   UPB_SIZE(1, 1), 0,          11,
                                                              kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_Pointer
                                                                      << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(1, 1),   UPB_SIZE(0, 0), kUpb_NoSub, 8,  kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_1Byte
                                                                      << kUpb_FieldRep_Shift)},
        {3, UPB_SIZE(12, 16), UPB_SIZE(0, 0), 1,          11, kUpb_FieldMode_Array |
                                                              (kUpb_FieldRep_Pointer
                                                                      << kUpb_FieldRep_Shift)},
        {4, UPB_SIZE(2, 2),   UPB_SIZE(0, 0), kUpb_NoSub, 8,  kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_1Byte
                                                                      << kUpb_FieldRep_Shift)},
        {5, UPB_SIZE(16, 24), UPB_SIZE(0, 0), kUpb_NoSub, 9,  kUpb_FieldMode_Array |
                                                              (kUpb_FieldRep_Pointer
                                                                      << kUpb_FieldRep_Shift)},
        {6, UPB_SIZE(3, 3),   UPB_SIZE(0, 0), kUpb_NoSub, 8,  kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_1Byte
                                                                      << kUpb_FieldRep_Shift)},
        {7, UPB_SIZE(4, 4),   UPB_SIZE(0, 0), kUpb_NoSub, 8,  kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_1Byte
                                                                      << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_extensions_filters_http_router_v3_Router_msginit = {
        &envoy_extensions_filters_http_router_v3_Router_submsgs[0],
        &envoy_extensions_filters_http_router_v3_Router__fields[0],
        UPB_SIZE(24, 32), 7, kUpb_ExtMode_NonExtendable, 7, 255, 0,
};

static const upb_MiniTable *messages_layout[1] = {
        &envoy_extensions_filters_http_router_v3_Router_msginit,
};

const upb_MiniTable_File envoy_extensions_filters_http_router_v3_router_proto_upb_file_layout = {
        messages_layout,
        NULL,
        NULL,
        1,
        0,
        0,
};

#include "upb/port_undef.inc"

