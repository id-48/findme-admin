/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/config/overload/v3/overload.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/msg_internal.h"
#include "envoy/config/overload/v3/overload.upb.h"
#include "envoy/type/v3/percent.upb.h"
#include "google/protobuf/any.upb.h"
#include "google/protobuf/duration.upb.h"
#include "udpa/annotations/status.upb.h"
#include "udpa/annotations/versioning.upb.h"
#include "validate/validate.upb.h"

#include "upb/port_def.inc"

static const upb_MiniTable_Sub envoy_config_overload_v3_ResourceMonitor_submsgs[1] = {
        {.submsg = &google_protobuf_Any_msginit},
};

static const upb_MiniTable_Field envoy_config_overload_v3_ResourceMonitor__fields[2] = {
        {1, UPB_SIZE(4, 8),   UPB_SIZE(0, 0),   kUpb_NoSub, 9,
                                                                kUpb_FieldMode_Scalar |
                                                                (kUpb_FieldRep_StringView
                                                                        << kUpb_FieldRep_Shift)},
        {3, UPB_SIZE(12, 24), UPB_SIZE(-1, -1), 0,          11, kUpb_FieldMode_Scalar |
                                                                (kUpb_FieldRep_Pointer
                                                                        << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_overload_v3_ResourceMonitor_msginit = {
        &envoy_config_overload_v3_ResourceMonitor_submsgs[0],
        &envoy_config_overload_v3_ResourceMonitor__fields[0],
        UPB_SIZE(16, 32), 2, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable_Field envoy_config_overload_v3_ThresholdTrigger__fields[1] = {
        {1, UPB_SIZE(0, 0), UPB_SIZE(0, 0), kUpb_NoSub, 1,
         kUpb_FieldMode_Scalar | (kUpb_FieldRep_8Byte << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_overload_v3_ThresholdTrigger_msginit = {
        NULL,
        &envoy_config_overload_v3_ThresholdTrigger__fields[0],
        UPB_SIZE(8, 8), 1, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable_Field envoy_config_overload_v3_ScaledTrigger__fields[2] = {
        {1, UPB_SIZE(0, 0), UPB_SIZE(0, 0), kUpb_NoSub, 1,
                                                           kUpb_FieldMode_Scalar |
                                                           (kUpb_FieldRep_8Byte
                                                                   << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(8, 8), UPB_SIZE(0, 0), kUpb_NoSub, 1, kUpb_FieldMode_Scalar |
                                                           (kUpb_FieldRep_8Byte
                                                                   << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_overload_v3_ScaledTrigger_msginit = {
        NULL,
        &envoy_config_overload_v3_ScaledTrigger__fields[0],
        UPB_SIZE(16, 16), 2, kUpb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_overload_v3_Trigger_submsgs[2] = {
        {.submsg = &envoy_config_overload_v3_ThresholdTrigger_msginit},
        {.submsg = &envoy_config_overload_v3_ScaledTrigger_msginit},
};

static const upb_MiniTable_Field envoy_config_overload_v3_Trigger__fields[3] = {
        {1, UPB_SIZE(4, 8),   UPB_SIZE(0, 0),   kUpb_NoSub, 9,
                                                                kUpb_FieldMode_Scalar |
                                                                (kUpb_FieldRep_StringView
                                                                        << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(12, 24), UPB_SIZE(-1, -1), 0,          11, kUpb_FieldMode_Scalar |
                                                                (kUpb_FieldRep_Pointer
                                                                        << kUpb_FieldRep_Shift)},
        {3, UPB_SIZE(12, 24), UPB_SIZE(-1, -1), 1,          11, kUpb_FieldMode_Scalar |
                                                                (kUpb_FieldRep_Pointer
                                                                        << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_overload_v3_Trigger_msginit = {
        &envoy_config_overload_v3_Trigger_submsgs[0],
        &envoy_config_overload_v3_Trigger__fields[0],
        UPB_SIZE(16, 32), 3, kUpb_ExtMode_NonExtendable, 3, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_overload_v3_ScaleTimersOverloadActionConfig_submsgs[1] = {
        {.submsg = &envoy_config_overload_v3_ScaleTimersOverloadActionConfig_ScaleTimer_msginit},
};

static const upb_MiniTable_Field envoy_config_overload_v3_ScaleTimersOverloadActionConfig__fields[1] = {
        {1, UPB_SIZE(0, 0), UPB_SIZE(0, 0), 0, 11,
         kUpb_FieldMode_Array | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_overload_v3_ScaleTimersOverloadActionConfig_msginit = {
        &envoy_config_overload_v3_ScaleTimersOverloadActionConfig_submsgs[0],
        &envoy_config_overload_v3_ScaleTimersOverloadActionConfig__fields[0],
        UPB_SIZE(8, 8), 1, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_overload_v3_ScaleTimersOverloadActionConfig_ScaleTimer_submsgs[2] = {
        {.submsg = &google_protobuf_Duration_msginit},
        {.submsg = &envoy_type_v3_Percent_msginit},
};

static const upb_MiniTable_Field envoy_config_overload_v3_ScaleTimersOverloadActionConfig_ScaleTimer__fields[3] = {
        {1, UPB_SIZE(0, 0), UPB_SIZE(0, 0),   kUpb_NoSub, 5,
                                                              kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_4Byte
                                                                      << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(8, 8), UPB_SIZE(-5, -5), 0,          11, kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_Pointer
                                                                      << kUpb_FieldRep_Shift)},
        {3, UPB_SIZE(8, 8), UPB_SIZE(-5, -5), 1,          11, kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_Pointer
                                                                      << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_overload_v3_ScaleTimersOverloadActionConfig_ScaleTimer_msginit = {
        &envoy_config_overload_v3_ScaleTimersOverloadActionConfig_ScaleTimer_submsgs[0],
        &envoy_config_overload_v3_ScaleTimersOverloadActionConfig_ScaleTimer__fields[0],
        UPB_SIZE(16, 16), 3, kUpb_ExtMode_NonExtendable, 3, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_overload_v3_OverloadAction_submsgs[2] = {
        {.submsg = &envoy_config_overload_v3_Trigger_msginit},
        {.submsg = &google_protobuf_Any_msginit},
};

static const upb_MiniTable_Field envoy_config_overload_v3_OverloadAction__fields[3] = {
        {1, UPB_SIZE(4, 8),   UPB_SIZE(0, 0), kUpb_NoSub, 9,
                                                              kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_StringView
                                                                      << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(12, 24), UPB_SIZE(0, 0), 0,          11, kUpb_FieldMode_Array |
                                                              (kUpb_FieldRep_Pointer
                                                                      << kUpb_FieldRep_Shift)},
        {3, UPB_SIZE(16, 32), UPB_SIZE(1, 1), 1,          11, kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_Pointer
                                                                      << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_overload_v3_OverloadAction_msginit = {
        &envoy_config_overload_v3_OverloadAction_submsgs[0],
        &envoy_config_overload_v3_OverloadAction__fields[0],
        UPB_SIZE(24, 40), 3, kUpb_ExtMode_NonExtendable, 3, 255, 0,
};

static const upb_MiniTable_Field envoy_config_overload_v3_BufferFactoryConfig__fields[1] = {
        {1, UPB_SIZE(0, 0), UPB_SIZE(0, 0), kUpb_NoSub, 13,
         kUpb_FieldMode_Scalar | (kUpb_FieldRep_4Byte << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_overload_v3_BufferFactoryConfig_msginit = {
        NULL,
        &envoy_config_overload_v3_BufferFactoryConfig__fields[0],
        UPB_SIZE(8, 8), 1, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_overload_v3_OverloadManager_submsgs[4] = {
        {.submsg = &google_protobuf_Duration_msginit},
        {.submsg = &envoy_config_overload_v3_ResourceMonitor_msginit},
        {.submsg = &envoy_config_overload_v3_OverloadAction_msginit},
        {.submsg = &envoy_config_overload_v3_BufferFactoryConfig_msginit},
};

static const upb_MiniTable_Field envoy_config_overload_v3_OverloadManager__fields[4] = {
        {1, UPB_SIZE(4, 8),   UPB_SIZE(1, 1), 0, 11,
                                                     kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer
                                                             << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(8, 16),  UPB_SIZE(0, 0), 1, 11, kUpb_FieldMode_Array | (kUpb_FieldRep_Pointer
                << kUpb_FieldRep_Shift)},
        {3, UPB_SIZE(12, 24), UPB_SIZE(0, 0), 2, 11, kUpb_FieldMode_Array | (kUpb_FieldRep_Pointer
                << kUpb_FieldRep_Shift)},
        {4, UPB_SIZE(16, 32), UPB_SIZE(2, 2), 3, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer
                << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_overload_v3_OverloadManager_msginit = {
        &envoy_config_overload_v3_OverloadManager_submsgs[0],
        &envoy_config_overload_v3_OverloadManager__fields[0],
        UPB_SIZE(24, 40), 4, kUpb_ExtMode_NonExtendable, 4, 255, 0,
};

static const upb_MiniTable *messages_layout[9] = {
        &envoy_config_overload_v3_ResourceMonitor_msginit,
        &envoy_config_overload_v3_ThresholdTrigger_msginit,
        &envoy_config_overload_v3_ScaledTrigger_msginit,
        &envoy_config_overload_v3_Trigger_msginit,
        &envoy_config_overload_v3_ScaleTimersOverloadActionConfig_msginit,
        &envoy_config_overload_v3_ScaleTimersOverloadActionConfig_ScaleTimer_msginit,
        &envoy_config_overload_v3_OverloadAction_msginit,
        &envoy_config_overload_v3_BufferFactoryConfig_msginit,
        &envoy_config_overload_v3_OverloadManager_msginit,
};

const upb_MiniTable_File envoy_config_overload_v3_overload_proto_upb_file_layout = {
        messages_layout,
        NULL,
        NULL,
        9,
        0,
        0,
};

#include "upb/port_undef.inc"

