/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/type/matcher/v3/http_inputs.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef ENVOY_TYPE_MATCHER_V3_HTTP_INPUTS_PROTO_UPB_H_
#define ENVOY_TYPE_MATCHER_V3_HTTP_INPUTS_PROTO_UPB_H_

#include "upb/msg_internal.h"
#include "upb/decode.h"
#include "upb/decode_fast.h"
#include "upb/encode.h"

#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

struct envoy_type_matcher_v3_HttpRequestHeaderMatchInput;
struct envoy_type_matcher_v3_HttpRequestTrailerMatchInput;
struct envoy_type_matcher_v3_HttpResponseHeaderMatchInput;
struct envoy_type_matcher_v3_HttpResponseTrailerMatchInput;
typedef struct envoy_type_matcher_v3_HttpRequestHeaderMatchInput envoy_type_matcher_v3_HttpRequestHeaderMatchInput;
typedef struct envoy_type_matcher_v3_HttpRequestTrailerMatchInput envoy_type_matcher_v3_HttpRequestTrailerMatchInput;
typedef struct envoy_type_matcher_v3_HttpResponseHeaderMatchInput envoy_type_matcher_v3_HttpResponseHeaderMatchInput;
typedef struct envoy_type_matcher_v3_HttpResponseTrailerMatchInput envoy_type_matcher_v3_HttpResponseTrailerMatchInput;
extern const upb_MiniTable envoy_type_matcher_v3_HttpRequestHeaderMatchInput_msginit;
extern const upb_MiniTable envoy_type_matcher_v3_HttpRequestTrailerMatchInput_msginit;
extern const upb_MiniTable envoy_type_matcher_v3_HttpResponseHeaderMatchInput_msginit;
extern const upb_MiniTable envoy_type_matcher_v3_HttpResponseTrailerMatchInput_msginit;


/* envoy.type.matcher.v3.HttpRequestHeaderMatchInput */

UPB_INLINE envoy_type_matcher_v3_HttpRequestHeaderMatchInput
*
envoy_type_matcher_v3_HttpRequestHeaderMatchInput_new(upb_Arena
* arena) {
return (envoy_type_matcher_v3_HttpRequestHeaderMatchInput*)
_upb_Message_New(&envoy_type_matcher_v3_HttpRequestHeaderMatchInput_msginit, arena
);
}
UPB_INLINE envoy_type_matcher_v3_HttpRequestHeaderMatchInput
*

envoy_type_matcher_v3_HttpRequestHeaderMatchInput_parse(const char *buf, size_t size,
                                                        upb_Arena *arena) {
    envoy_type_matcher_v3_HttpRequestHeaderMatchInput *
    ret = envoy_type_matcher_v3_HttpRequestHeaderMatchInput_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_type_matcher_v3_HttpRequestHeaderMatchInput_msginit, NULL,
                   0, arena) != kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE envoy_type_matcher_v3_HttpRequestHeaderMatchInput
*

envoy_type_matcher_v3_HttpRequestHeaderMatchInput_parse_ex(const char *buf, size_t size,
                                                           const upb_ExtensionRegistry *extreg,
                                                           int options, upb_Arena *arena) {
    envoy_type_matcher_v3_HttpRequestHeaderMatchInput *
    ret = envoy_type_matcher_v3_HttpRequestHeaderMatchInput_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_type_matcher_v3_HttpRequestHeaderMatchInput_msginit,
                   extreg, options, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *envoy_type_matcher_v3_HttpRequestHeaderMatchInput_serialize(
        const envoy_type_matcher_v3_HttpRequestHeaderMatchInput *msg, upb_Arena *arena,
        size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_type_matcher_v3_HttpRequestHeaderMatchInput_msginit, 0, arena,
                      &ptr, len);
    return ptr;
}

UPB_INLINE char *envoy_type_matcher_v3_HttpRequestHeaderMatchInput_serialize_ex(
        const envoy_type_matcher_v3_HttpRequestHeaderMatchInput *msg, int options,
        upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_type_matcher_v3_HttpRequestHeaderMatchInput_msginit, options,
                      arena, &ptr, len);
    return ptr;
}

UPB_INLINE void envoy_type_matcher_v3_HttpRequestHeaderMatchInput_clear_header_name(
        const envoy_type_matcher_v3_HttpRequestHeaderMatchInput *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_StringView) = upb_StringView_FromDataAndSize(NULL, 0);
}

UPB_INLINE upb_StringView

envoy_type_matcher_v3_HttpRequestHeaderMatchInput_header_name(
        const envoy_type_matcher_v3_HttpRequestHeaderMatchInput *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_StringView);
}

UPB_INLINE void envoy_type_matcher_v3_HttpRequestHeaderMatchInput_set_header_name(
        envoy_type_matcher_v3_HttpRequestHeaderMatchInput * msg, upb_StringView
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_StringView
) =
value;
}

/* envoy.type.matcher.v3.HttpRequestTrailerMatchInput */

UPB_INLINE envoy_type_matcher_v3_HttpRequestTrailerMatchInput
*
envoy_type_matcher_v3_HttpRequestTrailerMatchInput_new(upb_Arena
* arena) {
return (envoy_type_matcher_v3_HttpRequestTrailerMatchInput*)
_upb_Message_New(&envoy_type_matcher_v3_HttpRequestTrailerMatchInput_msginit, arena
);
}
UPB_INLINE envoy_type_matcher_v3_HttpRequestTrailerMatchInput
*

envoy_type_matcher_v3_HttpRequestTrailerMatchInput_parse(const char *buf, size_t size,
                                                         upb_Arena *arena) {
    envoy_type_matcher_v3_HttpRequestTrailerMatchInput *
    ret = envoy_type_matcher_v3_HttpRequestTrailerMatchInput_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_type_matcher_v3_HttpRequestTrailerMatchInput_msginit,
                   NULL, 0, arena) != kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE envoy_type_matcher_v3_HttpRequestTrailerMatchInput
*

envoy_type_matcher_v3_HttpRequestTrailerMatchInput_parse_ex(const char *buf, size_t size,
                                                            const upb_ExtensionRegistry *extreg,
                                                            int options, upb_Arena *arena) {
    envoy_type_matcher_v3_HttpRequestTrailerMatchInput *
    ret = envoy_type_matcher_v3_HttpRequestTrailerMatchInput_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_type_matcher_v3_HttpRequestTrailerMatchInput_msginit,
                   extreg, options, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *envoy_type_matcher_v3_HttpRequestTrailerMatchInput_serialize(
        const envoy_type_matcher_v3_HttpRequestTrailerMatchInput *msg, upb_Arena *arena,
        size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_type_matcher_v3_HttpRequestTrailerMatchInput_msginit, 0, arena,
                      &ptr, len);
    return ptr;
}

UPB_INLINE char *envoy_type_matcher_v3_HttpRequestTrailerMatchInput_serialize_ex(
        const envoy_type_matcher_v3_HttpRequestTrailerMatchInput *msg, int options,
        upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_type_matcher_v3_HttpRequestTrailerMatchInput_msginit, options,
                      arena, &ptr, len);
    return ptr;
}

UPB_INLINE void envoy_type_matcher_v3_HttpRequestTrailerMatchInput_clear_header_name(
        const envoy_type_matcher_v3_HttpRequestTrailerMatchInput *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_StringView) = upb_StringView_FromDataAndSize(NULL, 0);
}

UPB_INLINE upb_StringView

envoy_type_matcher_v3_HttpRequestTrailerMatchInput_header_name(
        const envoy_type_matcher_v3_HttpRequestTrailerMatchInput *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_StringView);
}

UPB_INLINE void envoy_type_matcher_v3_HttpRequestTrailerMatchInput_set_header_name(
        envoy_type_matcher_v3_HttpRequestTrailerMatchInput * msg, upb_StringView
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_StringView
) =
value;
}

/* envoy.type.matcher.v3.HttpResponseHeaderMatchInput */

UPB_INLINE envoy_type_matcher_v3_HttpResponseHeaderMatchInput
*
envoy_type_matcher_v3_HttpResponseHeaderMatchInput_new(upb_Arena
* arena) {
return (envoy_type_matcher_v3_HttpResponseHeaderMatchInput*)
_upb_Message_New(&envoy_type_matcher_v3_HttpResponseHeaderMatchInput_msginit, arena
);
}
UPB_INLINE envoy_type_matcher_v3_HttpResponseHeaderMatchInput
*

envoy_type_matcher_v3_HttpResponseHeaderMatchInput_parse(const char *buf, size_t size,
                                                         upb_Arena *arena) {
    envoy_type_matcher_v3_HttpResponseHeaderMatchInput *
    ret = envoy_type_matcher_v3_HttpResponseHeaderMatchInput_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_type_matcher_v3_HttpResponseHeaderMatchInput_msginit,
                   NULL, 0, arena) != kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE envoy_type_matcher_v3_HttpResponseHeaderMatchInput
*

envoy_type_matcher_v3_HttpResponseHeaderMatchInput_parse_ex(const char *buf, size_t size,
                                                            const upb_ExtensionRegistry *extreg,
                                                            int options, upb_Arena *arena) {
    envoy_type_matcher_v3_HttpResponseHeaderMatchInput *
    ret = envoy_type_matcher_v3_HttpResponseHeaderMatchInput_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_type_matcher_v3_HttpResponseHeaderMatchInput_msginit,
                   extreg, options, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *envoy_type_matcher_v3_HttpResponseHeaderMatchInput_serialize(
        const envoy_type_matcher_v3_HttpResponseHeaderMatchInput *msg, upb_Arena *arena,
        size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_type_matcher_v3_HttpResponseHeaderMatchInput_msginit, 0, arena,
                      &ptr, len);
    return ptr;
}

UPB_INLINE char *envoy_type_matcher_v3_HttpResponseHeaderMatchInput_serialize_ex(
        const envoy_type_matcher_v3_HttpResponseHeaderMatchInput *msg, int options,
        upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_type_matcher_v3_HttpResponseHeaderMatchInput_msginit, options,
                      arena, &ptr, len);
    return ptr;
}

UPB_INLINE void envoy_type_matcher_v3_HttpResponseHeaderMatchInput_clear_header_name(
        const envoy_type_matcher_v3_HttpResponseHeaderMatchInput *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_StringView) = upb_StringView_FromDataAndSize(NULL, 0);
}

UPB_INLINE upb_StringView

envoy_type_matcher_v3_HttpResponseHeaderMatchInput_header_name(
        const envoy_type_matcher_v3_HttpResponseHeaderMatchInput *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_StringView);
}

UPB_INLINE void envoy_type_matcher_v3_HttpResponseHeaderMatchInput_set_header_name(
        envoy_type_matcher_v3_HttpResponseHeaderMatchInput * msg, upb_StringView
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_StringView
) =
value;
}

/* envoy.type.matcher.v3.HttpResponseTrailerMatchInput */

UPB_INLINE envoy_type_matcher_v3_HttpResponseTrailerMatchInput
*
envoy_type_matcher_v3_HttpResponseTrailerMatchInput_new(upb_Arena
* arena) {
return (envoy_type_matcher_v3_HttpResponseTrailerMatchInput*)
_upb_Message_New(&envoy_type_matcher_v3_HttpResponseTrailerMatchInput_msginit, arena
);
}
UPB_INLINE envoy_type_matcher_v3_HttpResponseTrailerMatchInput
*

envoy_type_matcher_v3_HttpResponseTrailerMatchInput_parse(const char *buf, size_t size,
                                                          upb_Arena *arena) {
    envoy_type_matcher_v3_HttpResponseTrailerMatchInput *
    ret = envoy_type_matcher_v3_HttpResponseTrailerMatchInput_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_type_matcher_v3_HttpResponseTrailerMatchInput_msginit,
                   NULL, 0, arena) != kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE envoy_type_matcher_v3_HttpResponseTrailerMatchInput
*

envoy_type_matcher_v3_HttpResponseTrailerMatchInput_parse_ex(const char *buf, size_t size,
                                                             const upb_ExtensionRegistry *extreg,
                                                             int options, upb_Arena *arena) {
    envoy_type_matcher_v3_HttpResponseTrailerMatchInput *
    ret = envoy_type_matcher_v3_HttpResponseTrailerMatchInput_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_type_matcher_v3_HttpResponseTrailerMatchInput_msginit,
                   extreg, options, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *envoy_type_matcher_v3_HttpResponseTrailerMatchInput_serialize(
        const envoy_type_matcher_v3_HttpResponseTrailerMatchInput *msg, upb_Arena *arena,
        size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_type_matcher_v3_HttpResponseTrailerMatchInput_msginit, 0, arena,
                      &ptr, len);
    return ptr;
}

UPB_INLINE char *envoy_type_matcher_v3_HttpResponseTrailerMatchInput_serialize_ex(
        const envoy_type_matcher_v3_HttpResponseTrailerMatchInput *msg, int options,
        upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_type_matcher_v3_HttpResponseTrailerMatchInput_msginit, options,
                      arena, &ptr, len);
    return ptr;
}

UPB_INLINE void envoy_type_matcher_v3_HttpResponseTrailerMatchInput_clear_header_name(
        const envoy_type_matcher_v3_HttpResponseTrailerMatchInput *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_StringView) = upb_StringView_FromDataAndSize(NULL, 0);
}

UPB_INLINE upb_StringView

envoy_type_matcher_v3_HttpResponseTrailerMatchInput_header_name(
        const envoy_type_matcher_v3_HttpResponseTrailerMatchInput *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_StringView);
}

UPB_INLINE void envoy_type_matcher_v3_HttpResponseTrailerMatchInput_set_header_name(
        envoy_type_matcher_v3_HttpResponseTrailerMatchInput * msg, upb_StringView
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_StringView
) =
value;
}

extern const upb_MiniTable_File envoy_type_matcher_v3_http_inputs_proto_upb_file_layout;

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* ENVOY_TYPE_MATCHER_V3_HTTP_INPUTS_PROTO_UPB_H_ */
