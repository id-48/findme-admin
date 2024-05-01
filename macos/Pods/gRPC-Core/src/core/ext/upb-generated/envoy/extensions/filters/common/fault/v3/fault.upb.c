/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/extensions/filters/common/fault/v3/fault.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/msg_internal.h"
#include "envoy/extensions/filters/common/fault/v3/fault.upb.h"
#include "envoy/type/v3/percent.upb.h"
#include "google/protobuf/duration.upb.h"
#include "udpa/annotations/status.upb.h"
#include "udpa/annotations/versioning.upb.h"
#include "validate/validate.upb.h"

#include "upb/port_def.inc"

static const upb_MiniTable_Sub envoy_extensions_filters_common_fault_v3_FaultDelay_submsgs[3] = {
        {.submsg = &google_protobuf_Duration_msginit},
        {.submsg = &envoy_type_v3_FractionalPercent_msginit},
        {.submsg = &envoy_extensions_filters_common_fault_v3_FaultDelay_HeaderDelay_msginit},
};

static const upb_MiniTable_Field envoy_extensions_filters_common_fault_v3_FaultDelay__fields[3] = {
        {3, UPB_SIZE(12, 16), UPB_SIZE(-5, -5), 0, 11,
                                                       kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
        {4, UPB_SIZE(8, 8),   UPB_SIZE(1, 1),   1, 11, kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
        {5, UPB_SIZE(12, 16), UPB_SIZE(-5, -5), 2, 11, kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_extensions_filters_common_fault_v3_FaultDelay_msginit = {
        &envoy_extensions_filters_common_fault_v3_FaultDelay_submsgs[0],
        &envoy_extensions_filters_common_fault_v3_FaultDelay__fields[0],
        UPB_SIZE(16, 24), 3, kUpb_ExtMode_NonExtendable, 0, 255, 0,
};

const upb_MiniTable envoy_extensions_filters_common_fault_v3_FaultDelay_HeaderDelay_msginit = {
        NULL,
        NULL,
        UPB_SIZE(0, 0), 0, kUpb_ExtMode_NonExtendable, 0, 255, 0,
};

static const upb_MiniTable_Sub envoy_extensions_filters_common_fault_v3_FaultRateLimit_submsgs[3] = {
        {.submsg = &envoy_extensions_filters_common_fault_v3_FaultRateLimit_FixedLimit_msginit},
        {.submsg = &envoy_type_v3_FractionalPercent_msginit},
        {.submsg = &envoy_extensions_filters_common_fault_v3_FaultRateLimit_HeaderLimit_msginit},
};

static const upb_MiniTable_Field envoy_extensions_filters_common_fault_v3_FaultRateLimit__fields[3] = {
        {1, UPB_SIZE(12, 16), UPB_SIZE(-5, -5), 0, 11,
                                                       kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(8, 8),   UPB_SIZE(1, 1),   1, 11, kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
        {3, UPB_SIZE(12, 16), UPB_SIZE(-5, -5), 2, 11, kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_extensions_filters_common_fault_v3_FaultRateLimit_msginit = {
        &envoy_extensions_filters_common_fault_v3_FaultRateLimit_submsgs[0],
        &envoy_extensions_filters_common_fault_v3_FaultRateLimit__fields[0],
        UPB_SIZE(16, 24), 3, kUpb_ExtMode_NonExtendable, 3, 255, 0,
};

static const upb_MiniTable_Field envoy_extensions_filters_common_fault_v3_FaultRateLimit_FixedLimit__fields[1] = {
        {1, UPB_SIZE(0, 0), UPB_SIZE(0, 0), kUpb_NoSub, 4,
         kUpb_FieldMode_Scalar | (kUpb_FieldRep_8Byte << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_extensions_filters_common_fault_v3_FaultRateLimit_FixedLimit_msginit = {
        NULL,
        &envoy_extensions_filters_common_fault_v3_FaultRateLimit_FixedLimit__fields[0],
        UPB_SIZE(8, 8), 1, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

const upb_MiniTable envoy_extensions_filters_common_fault_v3_FaultRateLimit_HeaderLimit_msginit = {
        NULL,
        NULL,
        UPB_SIZE(0, 0), 0, kUpb_ExtMode_NonExtendable, 0, 255, 0,
};

static const upb_MiniTable *messages_layout[5] = {
        &envoy_extensions_filters_common_fault_v3_FaultDelay_msginit,
        &envoy_extensions_filters_common_fault_v3_FaultDelay_HeaderDelay_msginit,
        &envoy_extensions_filters_common_fault_v3_FaultRateLimit_msginit,
        &envoy_extensions_filters_common_fault_v3_FaultRateLimit_FixedLimit_msginit,
        &envoy_extensions_filters_common_fault_v3_FaultRateLimit_HeaderLimit_msginit,
};

const upb_MiniTable_File envoy_extensions_filters_common_fault_v3_fault_proto_upb_file_layout = {
        messages_layout,
        NULL,
        NULL,
        5,
        0,
        0,
};

#include "upb/port_undef.inc"

