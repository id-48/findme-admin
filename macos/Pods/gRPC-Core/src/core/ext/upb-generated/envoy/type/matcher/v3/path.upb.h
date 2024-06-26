/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/type/matcher/v3/path.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef ENVOY_TYPE_MATCHER_V3_PATH_PROTO_UPB_H_
#define ENVOY_TYPE_MATCHER_V3_PATH_PROTO_UPB_H_

#include "upb/msg_internal.h"
#include "upb/decode.h"
#include "upb/decode_fast.h"
#include "upb/encode.h"

#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

struct envoy_type_matcher_v3_PathMatcher;
typedef struct envoy_type_matcher_v3_PathMatcher envoy_type_matcher_v3_PathMatcher;
extern const upb_MiniTable envoy_type_matcher_v3_PathMatcher_msginit;
struct envoy_type_matcher_v3_StringMatcher;
extern const upb_MiniTable envoy_type_matcher_v3_StringMatcher_msginit;


/* envoy.type.matcher.v3.PathMatcher */

UPB_INLINE envoy_type_matcher_v3_PathMatcher
*
envoy_type_matcher_v3_PathMatcher_new(upb_Arena
* arena) {
return (envoy_type_matcher_v3_PathMatcher*)
_upb_Message_New(&envoy_type_matcher_v3_PathMatcher_msginit, arena
);
}
UPB_INLINE envoy_type_matcher_v3_PathMatcher
*

envoy_type_matcher_v3_PathMatcher_parse(const char *buf, size_t size, upb_Arena *arena) {
    envoy_type_matcher_v3_PathMatcher * ret = envoy_type_matcher_v3_PathMatcher_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_type_matcher_v3_PathMatcher_msginit, NULL, 0, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE envoy_type_matcher_v3_PathMatcher
*

envoy_type_matcher_v3_PathMatcher_parse_ex(const char *buf, size_t size,
                                           const upb_ExtensionRegistry *extreg,
                                           int options, upb_Arena *arena) {
    envoy_type_matcher_v3_PathMatcher * ret = envoy_type_matcher_v3_PathMatcher_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_type_matcher_v3_PathMatcher_msginit, extreg, options,
                   arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *
envoy_type_matcher_v3_PathMatcher_serialize(const envoy_type_matcher_v3_PathMatcher *msg,
                                            upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_type_matcher_v3_PathMatcher_msginit, 0, arena, &ptr, len);
    return ptr;
}

UPB_INLINE char *
envoy_type_matcher_v3_PathMatcher_serialize_ex(const envoy_type_matcher_v3_PathMatcher *msg,
                                               int options,
                                               upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_type_matcher_v3_PathMatcher_msginit, options, arena, &ptr, len);
    return ptr;
}

typedef enum {
    envoy_type_matcher_v3_PathMatcher_rule_path = 1,
    envoy_type_matcher_v3_PathMatcher_rule_NOT_SET = 0
} envoy_type_matcher_v3_PathMatcher_rule_oneofcases;
UPB_INLINE envoy_type_matcher_v3_PathMatcher_rule_oneofcases

envoy_type_matcher_v3_PathMatcher_rule_case(const envoy_type_matcher_v3_PathMatcher *msg) {
    return (envoy_type_matcher_v3_PathMatcher_rule_oneofcases) *UPB_PTR_AT(msg, UPB_SIZE(0, 0),
                                                                           int32_t);
}

UPB_INLINE bool
envoy_type_matcher_v3_PathMatcher_has_path(const envoy_type_matcher_v3_PathMatcher *msg) {
    return _upb_getoneofcase(msg, UPB_SIZE(0, 0)) == 1;
}

UPB_INLINE void
envoy_type_matcher_v3_PathMatcher_clear_path(const envoy_type_matcher_v3_PathMatcher *msg) {
    UPB_WRITE_ONEOF(msg,
    struct envoy_type_matcher_v3_StringMatcher*, UPB_SIZE(4, 8), 0, UPB_SIZE(0,
                                                                             0), envoy_type_matcher_v3_PathMatcher_rule_NOT_SET);
}

UPB_INLINE const struct envoy_type_matcher_v3_StringMatcher *
envoy_type_matcher_v3_PathMatcher_path(const envoy_type_matcher_v3_PathMatcher *msg) {
    return UPB_READ_ONEOF(msg,
    const struct envoy_type_matcher_v3_StringMatcher*, UPB_SIZE(4, 8), UPB_SIZE(0, 0), 1, NULL);
}

UPB_INLINE void envoy_type_matcher_v3_PathMatcher_set_path(envoy_type_matcher_v3_PathMatcher * msg,
struct envoy_type_matcher_v3_StringMatcher *value
) {
UPB_WRITE_ONEOF(msg,
struct envoy_type_matcher_v3_StringMatcher*, UPB_SIZE(4, 8), value, UPB_SIZE(0, 0), 1);
}

UPB_INLINE struct envoy_type_matcher_v3_StringMatcher *
envoy_type_matcher_v3_PathMatcher_mutable_path(envoy_type_matcher_v3_PathMatcher * msg,
                                               upb_Arena * arena) {
    struct envoy_type_matcher_v3_StringMatcher *sub = (struct envoy_type_matcher_v3_StringMatcher *) envoy_type_matcher_v3_PathMatcher_path(
            msg);
    if (sub == NULL) {
        sub = (struct envoy_type_matcher_v3_StringMatcher *) _upb_Message_New(
                &envoy_type_matcher_v3_StringMatcher_msginit, arena);
        if (!sub) return NULL;
        envoy_type_matcher_v3_PathMatcher_set_path(msg, sub);
    }
    return sub;
}

extern const upb_MiniTable_File envoy_type_matcher_v3_path_proto_upb_file_layout;

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* ENVOY_TYPE_MATCHER_V3_PATH_PROTO_UPB_H_ */
