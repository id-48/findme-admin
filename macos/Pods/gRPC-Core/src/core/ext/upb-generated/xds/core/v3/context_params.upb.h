/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     xds/core/v3/context_params.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef XDS_CORE_V3_CONTEXT_PARAMS_PROTO_UPB_H_
#define XDS_CORE_V3_CONTEXT_PARAMS_PROTO_UPB_H_

#include "upb/msg_internal.h"
#include "upb/decode.h"
#include "upb/decode_fast.h"
#include "upb/encode.h"

#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

struct xds_core_v3_ContextParams;
struct xds_core_v3_ContextParams_ParamsEntry;
typedef struct xds_core_v3_ContextParams xds_core_v3_ContextParams;
typedef struct xds_core_v3_ContextParams_ParamsEntry xds_core_v3_ContextParams_ParamsEntry;
extern const upb_MiniTable xds_core_v3_ContextParams_msginit;
extern const upb_MiniTable xds_core_v3_ContextParams_ParamsEntry_msginit;


/* xds.core.v3.ContextParams */

UPB_INLINE xds_core_v3_ContextParams
*
xds_core_v3_ContextParams_new(upb_Arena
* arena) {
return (xds_core_v3_ContextParams*)
_upb_Message_New(&xds_core_v3_ContextParams_msginit, arena
);
}
UPB_INLINE xds_core_v3_ContextParams
*

xds_core_v3_ContextParams_parse(const char *buf, size_t size, upb_Arena *arena) {
    xds_core_v3_ContextParams * ret = xds_core_v3_ContextParams_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &xds_core_v3_ContextParams_msginit, NULL, 0, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE xds_core_v3_ContextParams
*

xds_core_v3_ContextParams_parse_ex(const char *buf, size_t size,
                                   const upb_ExtensionRegistry *extreg,
                                   int options, upb_Arena *arena) {
    xds_core_v3_ContextParams * ret = xds_core_v3_ContextParams_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &xds_core_v3_ContextParams_msginit, extreg, options, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *
xds_core_v3_ContextParams_serialize(const xds_core_v3_ContextParams *msg, upb_Arena *arena,
                                    size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &xds_core_v3_ContextParams_msginit, 0, arena, &ptr, len);
    return ptr;
}

UPB_INLINE char *
xds_core_v3_ContextParams_serialize_ex(const xds_core_v3_ContextParams *msg, int options,
                                       upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &xds_core_v3_ContextParams_msginit, options, arena, &ptr, len);
    return ptr;
}

UPB_INLINE bool xds_core_v3_ContextParams_has_params(const xds_core_v3_ContextParams *msg) {
    return _upb_has_submsg_nohasbit(msg, UPB_SIZE(0, 0));
}

UPB_INLINE void xds_core_v3_ContextParams_clear_params(const xds_core_v3_ContextParams *msg) {
    _upb_array_detach(msg, UPB_SIZE(0, 0));
}

UPB_INLINE size_t

xds_core_v3_ContextParams_params_size(const xds_core_v3_ContextParams *msg) {
    return _upb_msg_map_size(msg, UPB_SIZE(0, 0));
}

UPB_INLINE bool
xds_core_v3_ContextParams_params_get(const xds_core_v3_ContextParams *msg, upb_StringView key,
                                     upb_StringView *val) {
    return _upb_msg_map_get(msg, UPB_SIZE(0, 0), &key, 0, val, 0);
}

UPB_INLINE const xds_core_v3_ContextParams_ParamsEntry
*

xds_core_v3_ContextParams_params_next(const xds_core_v3_ContextParams *msg, size_t *iter) {
    return (const xds_core_v3_ContextParams_ParamsEntry *) _upb_msg_map_next(msg, UPB_SIZE(0, 0),
                                                                             iter);
}

UPB_INLINE void
xds_core_v3_ContextParams_params_clear(xds_core_v3_ContextParams * msg) { _upb_msg_map_clear(msg,
                                                                                             UPB_SIZE(
                                                                                                     0,
                                                                                                     0));
}

UPB_INLINE bool xds_core_v3_ContextParams_params_set(xds_core_v3_ContextParams * msg, upb_StringView
key,
upb_StringView val, upb_Arena
* a) {
return
_upb_msg_map_set(msg, UPB_SIZE(0, 0), &key,
0, &val, 0, a);
}
UPB_INLINE bool xds_core_v3_ContextParams_params_delete(xds_core_v3_ContextParams * msg,
                                                        upb_StringView
key) {
return
_upb_msg_map_delete(msg, UPB_SIZE(0, 0), &key,
0);
}
UPB_INLINE xds_core_v3_ContextParams_ParamsEntry
*
xds_core_v3_ContextParams_params_nextmutable(xds_core_v3_ContextParams
* msg,
size_t *iter
) {
return (xds_core_v3_ContextParams_ParamsEntry*)
_upb_msg_map_next(msg, UPB_SIZE(0, 0), iter
);
}

/* xds.core.v3.ContextParams.ParamsEntry */

UPB_INLINE upb_StringView

xds_core_v3_ContextParams_ParamsEntry_key(const xds_core_v3_ContextParams_ParamsEntry *msg) {
    upb_StringView ret;
    _upb_msg_map_key(msg, &ret, 0);
    return ret;
}

UPB_INLINE upb_StringView

xds_core_v3_ContextParams_ParamsEntry_value(const xds_core_v3_ContextParams_ParamsEntry *msg) {
    upb_StringView ret;
    _upb_msg_map_value(msg, &ret, 0);
    return ret;
}

UPB_INLINE void xds_core_v3_ContextParams_ParamsEntry_set_value(
        xds_core_v3_ContextParams_ParamsEntry * msg, upb_StringView
value) {
_upb_msg_map_set_value(msg, &value,
0);
}

extern const upb_MiniTable_File xds_core_v3_context_params_proto_upb_file_layout;

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* XDS_CORE_V3_CONTEXT_PARAMS_PROTO_UPB_H_ */
