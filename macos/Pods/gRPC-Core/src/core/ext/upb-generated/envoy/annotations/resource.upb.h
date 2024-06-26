/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/annotations/resource.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef ENVOY_ANNOTATIONS_RESOURCE_PROTO_UPB_H_
#define ENVOY_ANNOTATIONS_RESOURCE_PROTO_UPB_H_

#include "upb/msg_internal.h"
#include "upb/decode.h"
#include "upb/decode_fast.h"
#include "upb/encode.h"

#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

struct envoy_annotations_ResourceAnnotation;
typedef struct envoy_annotations_ResourceAnnotation envoy_annotations_ResourceAnnotation;
extern const upb_MiniTable envoy_annotations_ResourceAnnotation_msginit;
extern const upb_MiniTable_Extension envoy_annotations_resource_ext;
struct google_protobuf_ServiceOptions;
extern const upb_MiniTable google_protobuf_ServiceOptions_msginit;


/* envoy.annotations.ResourceAnnotation */

UPB_INLINE envoy_annotations_ResourceAnnotation
*
envoy_annotations_ResourceAnnotation_new(upb_Arena
* arena) {
return (envoy_annotations_ResourceAnnotation*)
_upb_Message_New(&envoy_annotations_ResourceAnnotation_msginit, arena
);
}
UPB_INLINE envoy_annotations_ResourceAnnotation
*

envoy_annotations_ResourceAnnotation_parse(const char *buf, size_t size, upb_Arena *arena) {
    envoy_annotations_ResourceAnnotation * ret = envoy_annotations_ResourceAnnotation_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_annotations_ResourceAnnotation_msginit, NULL, 0, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE envoy_annotations_ResourceAnnotation
*

envoy_annotations_ResourceAnnotation_parse_ex(const char *buf, size_t size,
                                              const upb_ExtensionRegistry *extreg,
                                              int options, upb_Arena *arena) {
    envoy_annotations_ResourceAnnotation * ret = envoy_annotations_ResourceAnnotation_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_annotations_ResourceAnnotation_msginit, extreg, options,
                   arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *
envoy_annotations_ResourceAnnotation_serialize(const envoy_annotations_ResourceAnnotation *msg,
                                               upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_annotations_ResourceAnnotation_msginit, 0, arena, &ptr, len);
    return ptr;
}

UPB_INLINE char *
envoy_annotations_ResourceAnnotation_serialize_ex(const envoy_annotations_ResourceAnnotation *msg,
                                                  int options,
                                                  upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_annotations_ResourceAnnotation_msginit, options, arena, &ptr,
                      len);
    return ptr;
}

UPB_INLINE void
envoy_annotations_ResourceAnnotation_clear_type(const envoy_annotations_ResourceAnnotation *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_StringView) = upb_StringView_FromDataAndSize(NULL, 0);
}

UPB_INLINE upb_StringView

envoy_annotations_ResourceAnnotation_type(const envoy_annotations_ResourceAnnotation *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_StringView);
}

UPB_INLINE void envoy_annotations_ResourceAnnotation_set_type(
        envoy_annotations_ResourceAnnotation * msg, upb_StringView
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_StringView
) =
value;
}

UPB_INLINE bool envoy_annotations_has_resource(const struct google_protobuf_ServiceOptions *msg) {
    return _upb_Message_Getext(msg, &envoy_annotations_resource_ext) != NULL;
}

UPB_INLINE void envoy_annotations_clear_resource(struct google_protobuf_ServiceOptions *msg) {
    _upb_Message_Clearext(msg, &envoy_annotations_resource_ext);
}

UPB_INLINE const envoy_annotations_ResourceAnnotation
*

envoy_annotations_resource(const struct google_protobuf_ServiceOptions *msg) {
    const upb_Message_Extension *ext = _upb_Message_Getext(msg, &envoy_annotations_resource_ext);
    UPB_ASSERT(ext);
    return *UPB_PTR_AT(&ext->data, 0,
    const envoy_annotations_ResourceAnnotation*);
}

UPB_INLINE void envoy_annotations_set_resource(struct google_protobuf_ServiceOptions *msg,
                                               const envoy_annotations_ResourceAnnotation *ext,
                                               upb_Arena *arena) {
    const upb_Message_Extension *msg_ext =
            _upb_Message_GetOrCreateExtension(msg, &envoy_annotations_resource_ext, arena);
    UPB_ASSERT(msg_ext);
    *UPB_PTR_AT(&msg_ext->data, 0,
    const envoy_annotations_ResourceAnnotation*) = ext;
}

extern const upb_MiniTable_File envoy_annotations_resource_proto_upb_file_layout;

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* ENVOY_ANNOTATIONS_RESOURCE_PROTO_UPB_H_ */
