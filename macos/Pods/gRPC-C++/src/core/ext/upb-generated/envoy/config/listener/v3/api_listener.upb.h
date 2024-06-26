/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/config/listener/v3/api_listener.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef ENVOY_CONFIG_LISTENER_V3_API_LISTENER_PROTO_UPB_H_
#define ENVOY_CONFIG_LISTENER_V3_API_LISTENER_PROTO_UPB_H_

#include "upb/msg_internal.h"
#include "upb/decode.h"
#include "upb/decode_fast.h"
#include "upb/encode.h"

#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

struct envoy_config_listener_v3_ApiListener;
typedef struct envoy_config_listener_v3_ApiListener envoy_config_listener_v3_ApiListener;
extern const upb_MiniTable envoy_config_listener_v3_ApiListener_msginit;
struct google_protobuf_Any;
extern const upb_MiniTable google_protobuf_Any_msginit;


/* envoy.config.listener.v3.ApiListener */

UPB_INLINE envoy_config_listener_v3_ApiListener
*
envoy_config_listener_v3_ApiListener_new(upb_Arena
* arena) {
return (envoy_config_listener_v3_ApiListener*)
_upb_Message_New(&envoy_config_listener_v3_ApiListener_msginit, arena
);
}
UPB_INLINE envoy_config_listener_v3_ApiListener
*

envoy_config_listener_v3_ApiListener_parse(const char *buf, size_t size, upb_Arena *arena) {
    envoy_config_listener_v3_ApiListener * ret = envoy_config_listener_v3_ApiListener_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_config_listener_v3_ApiListener_msginit, NULL, 0, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE envoy_config_listener_v3_ApiListener
*

envoy_config_listener_v3_ApiListener_parse_ex(const char *buf, size_t size,
                                              const upb_ExtensionRegistry *extreg,
                                              int options, upb_Arena *arena) {
    envoy_config_listener_v3_ApiListener * ret = envoy_config_listener_v3_ApiListener_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_config_listener_v3_ApiListener_msginit, extreg, options,
                   arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *
envoy_config_listener_v3_ApiListener_serialize(const envoy_config_listener_v3_ApiListener *msg,
                                               upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_config_listener_v3_ApiListener_msginit, 0, arena, &ptr, len);
    return ptr;
}

UPB_INLINE char *
envoy_config_listener_v3_ApiListener_serialize_ex(const envoy_config_listener_v3_ApiListener *msg,
                                                  int options,
                                                  upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_config_listener_v3_ApiListener_msginit, options, arena, &ptr,
                      len);
    return ptr;
}

UPB_INLINE bool envoy_config_listener_v3_ApiListener_has_api_listener(
        const envoy_config_listener_v3_ApiListener *msg) {
    return _upb_hasbit(msg, 1);
}

UPB_INLINE void envoy_config_listener_v3_ApiListener_clear_api_listener(
        const envoy_config_listener_v3_ApiListener *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(4, 8),
    const upb_Message*) = NULL;
}

UPB_INLINE const struct google_protobuf_Any *
envoy_config_listener_v3_ApiListener_api_listener(const envoy_config_listener_v3_ApiListener *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(4, 8),
    const struct google_protobuf_Any*);
}

UPB_INLINE void envoy_config_listener_v3_ApiListener_set_api_listener(
        envoy_config_listener_v3_ApiListener * msg,
struct google_protobuf_Any *value
) {
_upb_sethas(msg,
1);
*
UPB_PTR_AT(msg, UPB_SIZE(4, 8),
struct google_protobuf_Any*) =
value;
}

UPB_INLINE struct google_protobuf_Any *envoy_config_listener_v3_ApiListener_mutable_api_listener(
        envoy_config_listener_v3_ApiListener * msg, upb_Arena * arena) {
    struct google_protobuf_Any *sub = (struct google_protobuf_Any *) envoy_config_listener_v3_ApiListener_api_listener(
            msg);
    if (sub == NULL) {
        sub = (struct google_protobuf_Any *) _upb_Message_New(&google_protobuf_Any_msginit, arena);
        if (!sub) return NULL;
        envoy_config_listener_v3_ApiListener_set_api_listener(msg, sub);
    }
    return sub;
}

extern const upb_MiniTable_File envoy_config_listener_v3_api_listener_proto_upb_file_layout;

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* ENVOY_CONFIG_LISTENER_V3_API_LISTENER_PROTO_UPB_H_ */
