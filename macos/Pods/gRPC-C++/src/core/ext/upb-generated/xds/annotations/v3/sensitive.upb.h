/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     xds/annotations/v3/sensitive.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef XDS_ANNOTATIONS_V3_SENSITIVE_PROTO_UPB_H_
#define XDS_ANNOTATIONS_V3_SENSITIVE_PROTO_UPB_H_

#include "upb/msg_internal.h"
#include "upb/decode.h"
#include "upb/decode_fast.h"
#include "upb/encode.h"

#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

extern const upb_MiniTable_Extension xds_annotations_v3_sensitive_ext;
struct google_protobuf_FieldOptions;
extern const upb_MiniTable google_protobuf_FieldOptions_msginit;


UPB_INLINE bool xds_annotations_v3_has_sensitive(const struct google_protobuf_FieldOptions *msg) {
    return _upb_Message_Getext(msg, &xds_annotations_v3_sensitive_ext) != NULL;
}

UPB_INLINE void xds_annotations_v3_clear_sensitive(struct google_protobuf_FieldOptions *msg) {
    _upb_Message_Clearext(msg, &xds_annotations_v3_sensitive_ext);
}

UPB_INLINE bool xds_annotations_v3_sensitive(const struct google_protobuf_FieldOptions *msg) {
    const upb_Message_Extension *ext = _upb_Message_Getext(msg, &xds_annotations_v3_sensitive_ext);
    return ext ? *UPB_PTR_AT(&ext->data, 0, bool) : false;
}

extern const upb_MiniTable_File xds_annotations_v3_sensitive_proto_upb_file_layout;

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* XDS_ANNOTATIONS_V3_SENSITIVE_PROTO_UPB_H_ */
