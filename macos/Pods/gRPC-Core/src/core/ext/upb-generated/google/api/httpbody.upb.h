/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     google/api/httpbody.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef GOOGLE_API_HTTPBODY_PROTO_UPB_H_
#define GOOGLE_API_HTTPBODY_PROTO_UPB_H_

#include "upb/msg_internal.h"
#include "upb/decode.h"
#include "upb/decode_fast.h"
#include "upb/encode.h"

#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

struct google_api_HttpBody;
typedef struct google_api_HttpBody google_api_HttpBody;
extern const upb_MiniTable google_api_HttpBody_msginit;
struct google_protobuf_Any;
extern const upb_MiniTable google_protobuf_Any_msginit;


/* google.api.HttpBody */

UPB_INLINE google_api_HttpBody
*
google_api_HttpBody_new(upb_Arena
* arena) {
return (google_api_HttpBody*)
_upb_Message_New(&google_api_HttpBody_msginit, arena
);
}
UPB_INLINE google_api_HttpBody
*

google_api_HttpBody_parse(const char *buf, size_t size, upb_Arena *arena) {
    google_api_HttpBody * ret = google_api_HttpBody_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &google_api_HttpBody_msginit, NULL, 0, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE google_api_HttpBody
*

google_api_HttpBody_parse_ex(const char *buf, size_t size,
                             const upb_ExtensionRegistry *extreg,
                             int options, upb_Arena *arena) {
    google_api_HttpBody * ret = google_api_HttpBody_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &google_api_HttpBody_msginit, extreg, options, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *
google_api_HttpBody_serialize(const google_api_HttpBody *msg, upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &google_api_HttpBody_msginit, 0, arena, &ptr, len);
    return ptr;
}

UPB_INLINE char *google_api_HttpBody_serialize_ex(const google_api_HttpBody *msg, int options,
                                                  upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &google_api_HttpBody_msginit, options, arena, &ptr, len);
    return ptr;
}

UPB_INLINE void google_api_HttpBody_clear_content_type(const google_api_HttpBody *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_StringView) = upb_StringView_FromDataAndSize(NULL, 0);
}

UPB_INLINE upb_StringView

google_api_HttpBody_content_type(const google_api_HttpBody *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_StringView);
}

UPB_INLINE void google_api_HttpBody_clear_data(const google_api_HttpBody *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(8, 16), upb_StringView) = upb_StringView_FromDataAndSize(NULL, 0);
}

UPB_INLINE upb_StringView

google_api_HttpBody_data(const google_api_HttpBody *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(8, 16), upb_StringView);
}

UPB_INLINE bool google_api_HttpBody_has_extensions(const google_api_HttpBody *msg) {
    return _upb_has_submsg_nohasbit(msg, UPB_SIZE(16, 32));
}

UPB_INLINE void google_api_HttpBody_clear_extensions(const google_api_HttpBody *msg) {
    _upb_array_detach(msg, UPB_SIZE(16, 32));
}

UPB_INLINE const struct google_protobuf_Any *const *
google_api_HttpBody_extensions(const google_api_HttpBody *msg, size_t *len) {
    return (const struct google_protobuf_Any *const *) _upb_array_accessor(msg, UPB_SIZE(16, 32),
                                                                           len);
}

UPB_INLINE void google_api_HttpBody_set_content_type(google_api_HttpBody * msg, upb_StringView
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_StringView
) =
value;
}
UPB_INLINE void google_api_HttpBody_set_data(google_api_HttpBody * msg, upb_StringView
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(8, 16), upb_StringView
) =
value;
}

UPB_INLINE struct google_protobuf_Any **
google_api_HttpBody_mutable_extensions(google_api_HttpBody * msg, size_t * len) {
    return (struct google_protobuf_Any **) _upb_array_mutable_accessor(msg, UPB_SIZE(16, 32), len);
}

UPB_INLINE struct google_protobuf_Any **google_api_HttpBody_resize_extensions(
        google_api_HttpBody * msg, size_t
len,
upb_Arena *arena
) {
return (struct google_protobuf_Any**)
_upb_Array_Resize_accessor2(msg, UPB_SIZE(16, 32), len, UPB_SIZE(2, 3), arena
);
}

UPB_INLINE struct google_protobuf_Any *
google_api_HttpBody_add_extensions(google_api_HttpBody * msg, upb_Arena * arena) {
    struct google_protobuf_Any *sub = (struct google_protobuf_Any *) _upb_Message_New(
            &google_protobuf_Any_msginit, arena);
    bool ok = _upb_Array_Append_accessor2(msg, UPB_SIZE(16, 32), UPB_SIZE(2, 3), &sub, arena);
    if (!ok) return NULL;
    return sub;
}

extern const upb_MiniTable_File google_api_httpbody_proto_upb_file_layout;

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* GOOGLE_API_HTTPBODY_PROTO_UPB_H_ */
