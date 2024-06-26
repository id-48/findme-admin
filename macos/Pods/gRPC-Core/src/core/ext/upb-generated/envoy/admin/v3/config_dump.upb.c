/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/admin/v3/config_dump.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/msg_internal.h"
#include "envoy/admin/v3/config_dump.upb.h"
#include "envoy/admin/v3/config_dump_shared.upb.h"
#include "envoy/config/bootstrap/v3/bootstrap.upb.h"
#include "google/protobuf/any.upb.h"
#include "google/protobuf/timestamp.upb.h"
#include "udpa/annotations/status.upb.h"
#include "udpa/annotations/versioning.upb.h"

#include "upb/port_def.inc"

static const upb_MiniTable_Sub envoy_admin_v3_ConfigDump_submsgs[1] = {
        {.submsg = &google_protobuf_Any_msginit},
};

static const upb_MiniTable_Field envoy_admin_v3_ConfigDump__fields[1] = {
        {1, UPB_SIZE(0, 0), UPB_SIZE(0, 0), 0, 11,
         kUpb_FieldMode_Array | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_admin_v3_ConfigDump_msginit = {
        &envoy_admin_v3_ConfigDump_submsgs[0],
        &envoy_admin_v3_ConfigDump__fields[0],
        UPB_SIZE(8, 8), 1, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable_Sub envoy_admin_v3_BootstrapConfigDump_submsgs[2] = {
        {.submsg = &envoy_config_bootstrap_v3_Bootstrap_msginit},
        {.submsg = &google_protobuf_Timestamp_msginit},
};

static const upb_MiniTable_Field envoy_admin_v3_BootstrapConfigDump__fields[2] = {
        {1, UPB_SIZE(4, 8),  UPB_SIZE(1, 1), 0, 11,
                                                    kUpb_FieldMode_Scalar |
                                                    (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(8, 16), UPB_SIZE(2, 2), 1, 11, kUpb_FieldMode_Scalar |
                                                    (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_admin_v3_BootstrapConfigDump_msginit = {
        &envoy_admin_v3_BootstrapConfigDump_submsgs[0],
        &envoy_admin_v3_BootstrapConfigDump__fields[0],
        UPB_SIZE(16, 24), 2, kUpb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable_Sub envoy_admin_v3_SecretsConfigDump_submsgs[3] = {
        {.submsg = &envoy_admin_v3_SecretsConfigDump_StaticSecret_msginit},
        {.submsg = &envoy_admin_v3_SecretsConfigDump_DynamicSecret_msginit},
        {.submsg = &envoy_admin_v3_SecretsConfigDump_DynamicSecret_msginit},
};

static const upb_MiniTable_Field envoy_admin_v3_SecretsConfigDump__fields[3] = {
        {1, UPB_SIZE(0, 0),  UPB_SIZE(0, 0), 0, 11,
                                                    kUpb_FieldMode_Array |
                                                    (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(4, 8),  UPB_SIZE(0, 0), 1, 11, kUpb_FieldMode_Array |
                                                    (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
        {3, UPB_SIZE(8, 16), UPB_SIZE(0, 0), 2, 11, kUpb_FieldMode_Array |
                                                    (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_admin_v3_SecretsConfigDump_msginit = {
        &envoy_admin_v3_SecretsConfigDump_submsgs[0],
        &envoy_admin_v3_SecretsConfigDump__fields[0],
        UPB_SIZE(16, 24), 3, kUpb_ExtMode_NonExtendable, 3, 255, 0,
};

static const upb_MiniTable_Sub envoy_admin_v3_SecretsConfigDump_DynamicSecret_submsgs[3] = {
        {.submsg = &google_protobuf_Timestamp_msginit},
        {.submsg = &google_protobuf_Any_msginit},
        {.submsg = &envoy_admin_v3_UpdateFailureState_msginit},
};

static const upb_MiniTable_Field envoy_admin_v3_SecretsConfigDump_DynamicSecret__fields[6] = {
        {1, UPB_SIZE(8, 8),   UPB_SIZE(0, 0), kUpb_NoSub, 9,
                                                              kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_StringView
                                                                      << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(16, 24), UPB_SIZE(0, 0), kUpb_NoSub, 9,  kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_StringView
                                                                      << kUpb_FieldRep_Shift)},
        {3, UPB_SIZE(24, 40), UPB_SIZE(1, 1), 0,          11, kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_Pointer
                                                                      << kUpb_FieldRep_Shift)},
        {4, UPB_SIZE(28, 48), UPB_SIZE(2, 2), 1,          11, kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_Pointer
                                                                      << kUpb_FieldRep_Shift)},
        {5, UPB_SIZE(32, 56), UPB_SIZE(3, 3), 2,          11, kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_Pointer
                                                                      << kUpb_FieldRep_Shift)},
        {6, UPB_SIZE(4, 4),   UPB_SIZE(0, 0), kUpb_NoSub, 5,  kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_4Byte
                                                                      << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_admin_v3_SecretsConfigDump_DynamicSecret_msginit = {
        &envoy_admin_v3_SecretsConfigDump_DynamicSecret_submsgs[0],
        &envoy_admin_v3_SecretsConfigDump_DynamicSecret__fields[0],
        UPB_SIZE(40, 64), 6, kUpb_ExtMode_NonExtendable, 6, 255, 0,
};

static const upb_MiniTable_Sub envoy_admin_v3_SecretsConfigDump_StaticSecret_submsgs[2] = {
        {.submsg = &google_protobuf_Timestamp_msginit},
        {.submsg = &google_protobuf_Any_msginit},
};

static const upb_MiniTable_Field envoy_admin_v3_SecretsConfigDump_StaticSecret__fields[3] = {
        {1, UPB_SIZE(4, 8),   UPB_SIZE(0, 0), kUpb_NoSub, 9,
                                                              kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_StringView
                                                                      << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(12, 24), UPB_SIZE(1, 1), 0,          11, kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_Pointer
                                                                      << kUpb_FieldRep_Shift)},
        {3, UPB_SIZE(16, 32), UPB_SIZE(2, 2), 1,          11, kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_Pointer
                                                                      << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_admin_v3_SecretsConfigDump_StaticSecret_msginit = {
        &envoy_admin_v3_SecretsConfigDump_StaticSecret_submsgs[0],
        &envoy_admin_v3_SecretsConfigDump_StaticSecret__fields[0],
        UPB_SIZE(24, 40), 3, kUpb_ExtMode_NonExtendable, 3, 255, 0,
};

static const upb_MiniTable *messages_layout[5] = {
        &envoy_admin_v3_ConfigDump_msginit,
        &envoy_admin_v3_BootstrapConfigDump_msginit,
        &envoy_admin_v3_SecretsConfigDump_msginit,
        &envoy_admin_v3_SecretsConfigDump_DynamicSecret_msginit,
        &envoy_admin_v3_SecretsConfigDump_StaticSecret_msginit,
};

const upb_MiniTable_File envoy_admin_v3_config_dump_proto_upb_file_layout = {
        messages_layout,
        NULL,
        NULL,
        5,
        0,
        0,
};

#include "upb/port_undef.inc"

