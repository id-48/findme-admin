/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/annotations/deprecation.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/msg_internal.h"
#include "envoy/annotations/deprecation.upb.h"
#include "google/protobuf/descriptor.upb.h"

#include "upb/port_def.inc"

extern const upb_MiniTable google_protobuf_EnumValueOptions_msginit;
extern const upb_MiniTable google_protobuf_FieldOptions_msginit;
const upb_MiniTable_Extension envoy_annotations_disallowed_by_default_ext = {
        {189503207, UPB_SIZE(0, 0), UPB_SIZE(0, 0), kUpb_NoSub, 8,
         kUpb_FieldMode_Scalar | kUpb_LabelFlags_IsExtension |
         (kUpb_FieldRep_1Byte << kUpb_FieldRep_Shift)},
        &google_protobuf_FieldOptions_msginit,
        {.submsg = NULL},

};
const upb_MiniTable_Extension envoy_annotations_deprecated_at_minor_version_ext = {
        {157299826, UPB_SIZE(0, 0), UPB_SIZE(0, 0), kUpb_NoSub, 12,
         kUpb_FieldMode_Scalar | kUpb_LabelFlags_IsExtension |
         (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)},
        &google_protobuf_FieldOptions_msginit,
        {.submsg = NULL},

};
const upb_MiniTable_Extension envoy_annotations_disallowed_by_default_enum_ext = {
        {70100853, UPB_SIZE(0, 0), UPB_SIZE(0, 0), kUpb_NoSub, 8,
         kUpb_FieldMode_Scalar | kUpb_LabelFlags_IsExtension |
         (kUpb_FieldRep_1Byte << kUpb_FieldRep_Shift)},
        &google_protobuf_EnumValueOptions_msginit,
        {.submsg = NULL},

};
const upb_MiniTable_Extension envoy_annotations_deprecated_at_minor_version_enum_ext = {
        {181198657, UPB_SIZE(0, 0), UPB_SIZE(0, 0), kUpb_NoSub, 12,
         kUpb_FieldMode_Scalar | kUpb_LabelFlags_IsExtension |
         (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)},
        &google_protobuf_EnumValueOptions_msginit,
        {.submsg = NULL},

};

static const upb_MiniTable_Extension *extensions_layout[4] = {
        &envoy_annotations_disallowed_by_default_ext,
        &envoy_annotations_deprecated_at_minor_version_ext,
        &envoy_annotations_disallowed_by_default_enum_ext,
        &envoy_annotations_deprecated_at_minor_version_enum_ext,
};

const upb_MiniTable_File envoy_annotations_deprecation_proto_upb_file_layout = {
        NULL,
        NULL,
        extensions_layout,
        0,
        0,
        4,
};

#include "upb/port_undef.inc"

