/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/config/core/v3/substitution_format_string.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/msg_internal.h"
#include "envoy/config/core/v3/substitution_format_string.upb.h"
#include "envoy/config/core/v3/base.upb.h"
#include "envoy/config/core/v3/extension.upb.h"
#include "google/protobuf/struct.upb.h"
#include "envoy/annotations/deprecation.upb.h"
#include "udpa/annotations/status.upb.h"
#include "validate/validate.upb.h"

#include "upb/port_def.inc"

static const upb_MiniTable_Sub envoy_config_core_v3_SubstitutionFormatString_submsgs[3] = {
        {.submsg = &google_protobuf_Struct_msginit},
        {.submsg = &envoy_config_core_v3_DataSource_msginit},
        {.submsg = &envoy_config_core_v3_TypedExtensionConfig_msginit},
};

static const upb_MiniTable_Field envoy_config_core_v3_SubstitutionFormatString__fields[6] = {
        {1, UPB_SIZE(8, 8),   UPB_SIZE(-5, -5), kUpb_NoSub, 9,
                                                                kUpb_FieldMode_Scalar |
                                                                (kUpb_FieldRep_StringView
                                                                        << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(8, 8),   UPB_SIZE(-5, -5), 0,          11, kUpb_FieldMode_Scalar |
                                                                (kUpb_FieldRep_Pointer
                                                                        << kUpb_FieldRep_Shift)},
        {3, UPB_SIZE(0, 0),   UPB_SIZE(0, 0),   kUpb_NoSub, 8,  kUpb_FieldMode_Scalar |
                                                                (kUpb_FieldRep_1Byte
                                                                        << kUpb_FieldRep_Shift)},
        {4, UPB_SIZE(16, 24), UPB_SIZE(0, 0),   kUpb_NoSub, 9,  kUpb_FieldMode_Scalar |
                                                                (kUpb_FieldRep_StringView
                                                                        << kUpb_FieldRep_Shift)},
        {5, UPB_SIZE(8, 8),   UPB_SIZE(-5, -5), 1,          11, kUpb_FieldMode_Scalar |
                                                                (kUpb_FieldRep_Pointer
                                                                        << kUpb_FieldRep_Shift)},
        {6, UPB_SIZE(24, 40), UPB_SIZE(0, 0),   2,          11, kUpb_FieldMode_Array |
                                                                (kUpb_FieldRep_Pointer
                                                                        << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_core_v3_SubstitutionFormatString_msginit = {
        &envoy_config_core_v3_SubstitutionFormatString_submsgs[0],
        &envoy_config_core_v3_SubstitutionFormatString__fields[0],
        UPB_SIZE(32, 48), 6, kUpb_ExtMode_NonExtendable, 6, 255, 0,
};

static const upb_MiniTable *messages_layout[1] = {
        &envoy_config_core_v3_SubstitutionFormatString_msginit,
};

const upb_MiniTable_File envoy_config_core_v3_substitution_format_string_proto_upb_file_layout = {
        messages_layout,
        NULL,
        NULL,
        1,
        0,
        0,
};

#include "upb/port_undef.inc"

