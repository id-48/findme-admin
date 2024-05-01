/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     xds/annotations/v3/status.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef XDS_ANNOTATIONS_V3_STATUS_PROTO_UPB_H_
#define XDS_ANNOTATIONS_V3_STATUS_PROTO_UPB_H_

#include "upb/msg_internal.h"
#include "upb/decode.h"
#include "upb/decode_fast.h"
#include "upb/encode.h"

#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

struct xds_annotations_v3_FileStatusAnnotation;
struct xds_annotations_v3_MessageStatusAnnotation;
struct xds_annotations_v3_FieldStatusAnnotation;
struct xds_annotations_v3_StatusAnnotation;
typedef struct xds_annotations_v3_FileStatusAnnotation xds_annotations_v3_FileStatusAnnotation;
typedef struct xds_annotations_v3_MessageStatusAnnotation xds_annotations_v3_MessageStatusAnnotation;
typedef struct xds_annotations_v3_FieldStatusAnnotation xds_annotations_v3_FieldStatusAnnotation;
typedef struct xds_annotations_v3_StatusAnnotation xds_annotations_v3_StatusAnnotation;
extern const upb_MiniTable xds_annotations_v3_FileStatusAnnotation_msginit;
extern const upb_MiniTable xds_annotations_v3_MessageStatusAnnotation_msginit;
extern const upb_MiniTable xds_annotations_v3_FieldStatusAnnotation_msginit;
extern const upb_MiniTable xds_annotations_v3_StatusAnnotation_msginit;
extern const upb_MiniTable_Extension xds_annotations_v3_file_status_ext;
extern const upb_MiniTable_Extension xds_annotations_v3_message_status_ext;
extern const upb_MiniTable_Extension xds_annotations_v3_field_status_ext;
struct google_protobuf_FieldOptions;
struct google_protobuf_FileOptions;
struct google_protobuf_MessageOptions;
extern const upb_MiniTable google_protobuf_FieldOptions_msginit;
extern const upb_MiniTable google_protobuf_FileOptions_msginit;
extern const upb_MiniTable google_protobuf_MessageOptions_msginit;

typedef enum {
    xds_annotations_v3_UNKNOWN = 0,
    xds_annotations_v3_FROZEN = 1,
    xds_annotations_v3_ACTIVE = 2,
    xds_annotations_v3_NEXT_MAJOR_VERSION_CANDIDATE = 3
} xds_annotations_v3_PackageVersionStatus;


/* xds.annotations.v3.FileStatusAnnotation */

UPB_INLINE xds_annotations_v3_FileStatusAnnotation
*
xds_annotations_v3_FileStatusAnnotation_new(upb_Arena
* arena) {
return (xds_annotations_v3_FileStatusAnnotation*)
_upb_Message_New(&xds_annotations_v3_FileStatusAnnotation_msginit, arena
);
}
UPB_INLINE xds_annotations_v3_FileStatusAnnotation
*

xds_annotations_v3_FileStatusAnnotation_parse(const char *buf, size_t size, upb_Arena *arena) {
    xds_annotations_v3_FileStatusAnnotation * ret = xds_annotations_v3_FileStatusAnnotation_new(
            arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &xds_annotations_v3_FileStatusAnnotation_msginit, NULL, 0,
                   arena) != kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE xds_annotations_v3_FileStatusAnnotation
*

xds_annotations_v3_FileStatusAnnotation_parse_ex(const char *buf, size_t size,
                                                 const upb_ExtensionRegistry *extreg,
                                                 int options, upb_Arena *arena) {
    xds_annotations_v3_FileStatusAnnotation * ret = xds_annotations_v3_FileStatusAnnotation_new(
            arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &xds_annotations_v3_FileStatusAnnotation_msginit, extreg,
                   options, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *xds_annotations_v3_FileStatusAnnotation_serialize(
        const xds_annotations_v3_FileStatusAnnotation *msg, upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &xds_annotations_v3_FileStatusAnnotation_msginit, 0, arena, &ptr, len);
    return ptr;
}

UPB_INLINE char *xds_annotations_v3_FileStatusAnnotation_serialize_ex(
        const xds_annotations_v3_FileStatusAnnotation *msg, int options,
        upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &xds_annotations_v3_FileStatusAnnotation_msginit, options, arena, &ptr,
                      len);
    return ptr;
}

UPB_INLINE void xds_annotations_v3_FileStatusAnnotation_clear_work_in_progress(
        const xds_annotations_v3_FileStatusAnnotation *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(0, 0), bool) = 0;
}

UPB_INLINE bool xds_annotations_v3_FileStatusAnnotation_work_in_progress(
        const xds_annotations_v3_FileStatusAnnotation *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(0, 0), bool);
}

UPB_INLINE void xds_annotations_v3_FileStatusAnnotation_set_work_in_progress(
        xds_annotations_v3_FileStatusAnnotation * msg, bool
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(0, 0),
bool) =
value;
}

/* xds.annotations.v3.MessageStatusAnnotation */

UPB_INLINE xds_annotations_v3_MessageStatusAnnotation
*
xds_annotations_v3_MessageStatusAnnotation_new(upb_Arena
* arena) {
return (xds_annotations_v3_MessageStatusAnnotation*)
_upb_Message_New(&xds_annotations_v3_MessageStatusAnnotation_msginit, arena
);
}
UPB_INLINE xds_annotations_v3_MessageStatusAnnotation
*

xds_annotations_v3_MessageStatusAnnotation_parse(const char *buf, size_t size, upb_Arena *arena) {
    xds_annotations_v3_MessageStatusAnnotation *
    ret = xds_annotations_v3_MessageStatusAnnotation_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &xds_annotations_v3_MessageStatusAnnotation_msginit, NULL, 0,
                   arena) != kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE xds_annotations_v3_MessageStatusAnnotation
*

xds_annotations_v3_MessageStatusAnnotation_parse_ex(const char *buf, size_t size,
                                                    const upb_ExtensionRegistry *extreg,
                                                    int options, upb_Arena *arena) {
    xds_annotations_v3_MessageStatusAnnotation *
    ret = xds_annotations_v3_MessageStatusAnnotation_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &xds_annotations_v3_MessageStatusAnnotation_msginit, extreg,
                   options, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *xds_annotations_v3_MessageStatusAnnotation_serialize(
        const xds_annotations_v3_MessageStatusAnnotation *msg, upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &xds_annotations_v3_MessageStatusAnnotation_msginit, 0, arena, &ptr,
                      len);
    return ptr;
}

UPB_INLINE char *xds_annotations_v3_MessageStatusAnnotation_serialize_ex(
        const xds_annotations_v3_MessageStatusAnnotation *msg, int options,
        upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &xds_annotations_v3_MessageStatusAnnotation_msginit, options, arena,
                      &ptr, len);
    return ptr;
}

UPB_INLINE void xds_annotations_v3_MessageStatusAnnotation_clear_work_in_progress(
        const xds_annotations_v3_MessageStatusAnnotation *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(0, 0), bool) = 0;
}

UPB_INLINE bool xds_annotations_v3_MessageStatusAnnotation_work_in_progress(
        const xds_annotations_v3_MessageStatusAnnotation *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(0, 0), bool);
}

UPB_INLINE void xds_annotations_v3_MessageStatusAnnotation_set_work_in_progress(
        xds_annotations_v3_MessageStatusAnnotation * msg, bool
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(0, 0),
bool) =
value;
}

/* xds.annotations.v3.FieldStatusAnnotation */

UPB_INLINE xds_annotations_v3_FieldStatusAnnotation
*
xds_annotations_v3_FieldStatusAnnotation_new(upb_Arena
* arena) {
return (xds_annotations_v3_FieldStatusAnnotation*)
_upb_Message_New(&xds_annotations_v3_FieldStatusAnnotation_msginit, arena
);
}
UPB_INLINE xds_annotations_v3_FieldStatusAnnotation
*

xds_annotations_v3_FieldStatusAnnotation_parse(const char *buf, size_t size, upb_Arena *arena) {
    xds_annotations_v3_FieldStatusAnnotation * ret = xds_annotations_v3_FieldStatusAnnotation_new(
            arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &xds_annotations_v3_FieldStatusAnnotation_msginit, NULL, 0,
                   arena) != kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE xds_annotations_v3_FieldStatusAnnotation
*

xds_annotations_v3_FieldStatusAnnotation_parse_ex(const char *buf, size_t size,
                                                  const upb_ExtensionRegistry *extreg,
                                                  int options, upb_Arena *arena) {
    xds_annotations_v3_FieldStatusAnnotation * ret = xds_annotations_v3_FieldStatusAnnotation_new(
            arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &xds_annotations_v3_FieldStatusAnnotation_msginit, extreg,
                   options, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *xds_annotations_v3_FieldStatusAnnotation_serialize(
        const xds_annotations_v3_FieldStatusAnnotation *msg, upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &xds_annotations_v3_FieldStatusAnnotation_msginit, 0, arena, &ptr, len);
    return ptr;
}

UPB_INLINE char *xds_annotations_v3_FieldStatusAnnotation_serialize_ex(
        const xds_annotations_v3_FieldStatusAnnotation *msg, int options,
        upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &xds_annotations_v3_FieldStatusAnnotation_msginit, options, arena, &ptr,
                      len);
    return ptr;
}

UPB_INLINE void xds_annotations_v3_FieldStatusAnnotation_clear_work_in_progress(
        const xds_annotations_v3_FieldStatusAnnotation *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(0, 0), bool) = 0;
}

UPB_INLINE bool xds_annotations_v3_FieldStatusAnnotation_work_in_progress(
        const xds_annotations_v3_FieldStatusAnnotation *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(0, 0), bool);
}

UPB_INLINE void xds_annotations_v3_FieldStatusAnnotation_set_work_in_progress(
        xds_annotations_v3_FieldStatusAnnotation * msg, bool
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(0, 0),
bool) =
value;
}

/* xds.annotations.v3.StatusAnnotation */

UPB_INLINE xds_annotations_v3_StatusAnnotation
*
xds_annotations_v3_StatusAnnotation_new(upb_Arena
* arena) {
return (xds_annotations_v3_StatusAnnotation*)
_upb_Message_New(&xds_annotations_v3_StatusAnnotation_msginit, arena
);
}
UPB_INLINE xds_annotations_v3_StatusAnnotation
*

xds_annotations_v3_StatusAnnotation_parse(const char *buf, size_t size, upb_Arena *arena) {
    xds_annotations_v3_StatusAnnotation * ret = xds_annotations_v3_StatusAnnotation_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &xds_annotations_v3_StatusAnnotation_msginit, NULL, 0, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE xds_annotations_v3_StatusAnnotation
*

xds_annotations_v3_StatusAnnotation_parse_ex(const char *buf, size_t size,
                                             const upb_ExtensionRegistry *extreg,
                                             int options, upb_Arena *arena) {
    xds_annotations_v3_StatusAnnotation * ret = xds_annotations_v3_StatusAnnotation_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &xds_annotations_v3_StatusAnnotation_msginit, extreg, options,
                   arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *
xds_annotations_v3_StatusAnnotation_serialize(const xds_annotations_v3_StatusAnnotation *msg,
                                              upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &xds_annotations_v3_StatusAnnotation_msginit, 0, arena, &ptr, len);
    return ptr;
}

UPB_INLINE char *
xds_annotations_v3_StatusAnnotation_serialize_ex(const xds_annotations_v3_StatusAnnotation *msg,
                                                 int options,
                                                 upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &xds_annotations_v3_StatusAnnotation_msginit, options, arena, &ptr, len);
    return ptr;
}

UPB_INLINE void xds_annotations_v3_StatusAnnotation_clear_work_in_progress(
        const xds_annotations_v3_StatusAnnotation *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(0, 0), bool) = 0;
}

UPB_INLINE bool xds_annotations_v3_StatusAnnotation_work_in_progress(
        const xds_annotations_v3_StatusAnnotation *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(0, 0), bool);
}

UPB_INLINE void xds_annotations_v3_StatusAnnotation_clear_package_version_status(
        const xds_annotations_v3_StatusAnnotation *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(4, 4), int32_t) = 0;
}

UPB_INLINE int32_t

xds_annotations_v3_StatusAnnotation_package_version_status(
        const xds_annotations_v3_StatusAnnotation *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(4, 4), int32_t);
}

UPB_INLINE void xds_annotations_v3_StatusAnnotation_set_work_in_progress(
        xds_annotations_v3_StatusAnnotation * msg, bool
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(0, 0),
bool) =
value;
}
UPB_INLINE void xds_annotations_v3_StatusAnnotation_set_package_version_status(
        xds_annotations_v3_StatusAnnotation * msg, int32_t
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(4, 4), int32_t
) =
value;
}

UPB_INLINE bool xds_annotations_v3_has_file_status(const struct google_protobuf_FileOptions *msg) {
    return _upb_Message_Getext(msg, &xds_annotations_v3_file_status_ext) != NULL;
}

UPB_INLINE void xds_annotations_v3_clear_file_status(struct google_protobuf_FileOptions *msg) {
    _upb_Message_Clearext(msg, &xds_annotations_v3_file_status_ext);
}

UPB_INLINE const xds_annotations_v3_FileStatusAnnotation
*

xds_annotations_v3_file_status(const struct google_protobuf_FileOptions *msg) {
    const upb_Message_Extension *ext = _upb_Message_Getext(msg,
                                                           &xds_annotations_v3_file_status_ext);
    UPB_ASSERT(ext);
    return *UPB_PTR_AT(&ext->data, 0,
    const xds_annotations_v3_FileStatusAnnotation*);
}

UPB_INLINE void xds_annotations_v3_set_file_status(struct google_protobuf_FileOptions *msg,
                                                   const xds_annotations_v3_FileStatusAnnotation *ext,
                                                   upb_Arena *arena) {
    const upb_Message_Extension *msg_ext =
            _upb_Message_GetOrCreateExtension(msg, &xds_annotations_v3_file_status_ext, arena);
    UPB_ASSERT(msg_ext);
    *UPB_PTR_AT(&msg_ext->data, 0,
    const xds_annotations_v3_FileStatusAnnotation*) = ext;
}

UPB_INLINE bool
xds_annotations_v3_has_message_status(const struct google_protobuf_MessageOptions *msg) {
    return _upb_Message_Getext(msg, &xds_annotations_v3_message_status_ext) != NULL;
}

UPB_INLINE void
xds_annotations_v3_clear_message_status(struct google_protobuf_MessageOptions *msg) {
    _upb_Message_Clearext(msg, &xds_annotations_v3_message_status_ext);
}

UPB_INLINE const xds_annotations_v3_MessageStatusAnnotation
*

xds_annotations_v3_message_status(const struct google_protobuf_MessageOptions *msg) {
    const upb_Message_Extension *ext = _upb_Message_Getext(msg,
                                                           &xds_annotations_v3_message_status_ext);
    UPB_ASSERT(ext);
    return *UPB_PTR_AT(&ext->data, 0,
    const xds_annotations_v3_MessageStatusAnnotation*);
}

UPB_INLINE void xds_annotations_v3_set_message_status(struct google_protobuf_MessageOptions *msg,
                                                      const xds_annotations_v3_MessageStatusAnnotation *ext,
                                                      upb_Arena *arena) {
    const upb_Message_Extension *msg_ext =
            _upb_Message_GetOrCreateExtension(msg, &xds_annotations_v3_message_status_ext, arena);
    UPB_ASSERT(msg_ext);
    *UPB_PTR_AT(&msg_ext->data, 0,
    const xds_annotations_v3_MessageStatusAnnotation*) = ext;
}

UPB_INLINE bool
xds_annotations_v3_has_field_status(const struct google_protobuf_FieldOptions *msg) {
    return _upb_Message_Getext(msg, &xds_annotations_v3_field_status_ext) != NULL;
}

UPB_INLINE void xds_annotations_v3_clear_field_status(struct google_protobuf_FieldOptions *msg) {
    _upb_Message_Clearext(msg, &xds_annotations_v3_field_status_ext);
}

UPB_INLINE const xds_annotations_v3_FieldStatusAnnotation
*

xds_annotations_v3_field_status(const struct google_protobuf_FieldOptions *msg) {
    const upb_Message_Extension *ext = _upb_Message_Getext(msg,
                                                           &xds_annotations_v3_field_status_ext);
    UPB_ASSERT(ext);
    return *UPB_PTR_AT(&ext->data, 0,
    const xds_annotations_v3_FieldStatusAnnotation*);
}

UPB_INLINE void xds_annotations_v3_set_field_status(struct google_protobuf_FieldOptions *msg,
                                                    const xds_annotations_v3_FieldStatusAnnotation *ext,
                                                    upb_Arena *arena) {
    const upb_Message_Extension *msg_ext =
            _upb_Message_GetOrCreateExtension(msg, &xds_annotations_v3_field_status_ext, arena);
    UPB_ASSERT(msg_ext);
    *UPB_PTR_AT(&msg_ext->data, 0,
    const xds_annotations_v3_FieldStatusAnnotation*) = ext;
}

extern const upb_MiniTable_File xds_annotations_v3_status_proto_upb_file_layout;

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* XDS_ANNOTATIONS_V3_STATUS_PROTO_UPB_H_ */