/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/config/core/v3/udp_socket_config.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef ENVOY_CONFIG_CORE_V3_UDP_SOCKET_CONFIG_PROTO_UPB_H_
#define ENVOY_CONFIG_CORE_V3_UDP_SOCKET_CONFIG_PROTO_UPB_H_

#include "upb/msg_internal.h"
#include "upb/decode.h"
#include "upb/decode_fast.h"
#include "upb/encode.h"

#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

struct envoy_config_core_v3_UdpSocketConfig;
typedef struct envoy_config_core_v3_UdpSocketConfig envoy_config_core_v3_UdpSocketConfig;
extern const upb_MiniTable envoy_config_core_v3_UdpSocketConfig_msginit;
struct google_protobuf_BoolValue;
struct google_protobuf_UInt64Value;
extern const upb_MiniTable google_protobuf_BoolValue_msginit;
extern const upb_MiniTable google_protobuf_UInt64Value_msginit;


/* envoy.config.core.v3.UdpSocketConfig */

UPB_INLINE envoy_config_core_v3_UdpSocketConfig
*
envoy_config_core_v3_UdpSocketConfig_new(upb_Arena
* arena) {
return (envoy_config_core_v3_UdpSocketConfig*)
_upb_Message_New(&envoy_config_core_v3_UdpSocketConfig_msginit, arena
);
}
UPB_INLINE envoy_config_core_v3_UdpSocketConfig
*

envoy_config_core_v3_UdpSocketConfig_parse(const char *buf, size_t size, upb_Arena *arena) {
    envoy_config_core_v3_UdpSocketConfig * ret = envoy_config_core_v3_UdpSocketConfig_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_config_core_v3_UdpSocketConfig_msginit, NULL, 0, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE envoy_config_core_v3_UdpSocketConfig
*

envoy_config_core_v3_UdpSocketConfig_parse_ex(const char *buf, size_t size,
                                              const upb_ExtensionRegistry *extreg,
                                              int options, upb_Arena *arena) {
    envoy_config_core_v3_UdpSocketConfig * ret = envoy_config_core_v3_UdpSocketConfig_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_config_core_v3_UdpSocketConfig_msginit, extreg, options,
                   arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *
envoy_config_core_v3_UdpSocketConfig_serialize(const envoy_config_core_v3_UdpSocketConfig *msg,
                                               upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_config_core_v3_UdpSocketConfig_msginit, 0, arena, &ptr, len);
    return ptr;
}

UPB_INLINE char *
envoy_config_core_v3_UdpSocketConfig_serialize_ex(const envoy_config_core_v3_UdpSocketConfig *msg,
                                                  int options,
                                                  upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_config_core_v3_UdpSocketConfig_msginit, options, arena, &ptr,
                      len);
    return ptr;
}

UPB_INLINE bool envoy_config_core_v3_UdpSocketConfig_has_max_rx_datagram_size(
        const envoy_config_core_v3_UdpSocketConfig *msg) {
    return _upb_hasbit(msg, 1);
}

UPB_INLINE void envoy_config_core_v3_UdpSocketConfig_clear_max_rx_datagram_size(
        const envoy_config_core_v3_UdpSocketConfig *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(4, 8),
    const upb_Message*) = NULL;
}

UPB_INLINE const struct google_protobuf_UInt64Value *
envoy_config_core_v3_UdpSocketConfig_max_rx_datagram_size(
        const envoy_config_core_v3_UdpSocketConfig *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(4, 8),
    const struct google_protobuf_UInt64Value*);
}

UPB_INLINE bool envoy_config_core_v3_UdpSocketConfig_has_prefer_gro(
        const envoy_config_core_v3_UdpSocketConfig *msg) {
    return _upb_hasbit(msg, 2);
}

UPB_INLINE void envoy_config_core_v3_UdpSocketConfig_clear_prefer_gro(
        const envoy_config_core_v3_UdpSocketConfig *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(8, 16),
    const upb_Message*) = NULL;
}

UPB_INLINE const struct google_protobuf_BoolValue *
envoy_config_core_v3_UdpSocketConfig_prefer_gro(const envoy_config_core_v3_UdpSocketConfig *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(8, 16),
    const struct google_protobuf_BoolValue*);
}

UPB_INLINE void envoy_config_core_v3_UdpSocketConfig_set_max_rx_datagram_size(
        envoy_config_core_v3_UdpSocketConfig * msg,
struct google_protobuf_UInt64Value *value
) {
_upb_sethas(msg,
1);
*
UPB_PTR_AT(msg, UPB_SIZE(4, 8),
struct google_protobuf_UInt64Value*) =
value;
}

UPB_INLINE struct google_protobuf_UInt64Value *
envoy_config_core_v3_UdpSocketConfig_mutable_max_rx_datagram_size(
        envoy_config_core_v3_UdpSocketConfig * msg, upb_Arena * arena) {
    struct google_protobuf_UInt64Value *sub = (struct google_protobuf_UInt64Value *) envoy_config_core_v3_UdpSocketConfig_max_rx_datagram_size(
            msg);
    if (sub == NULL) {
        sub = (struct google_protobuf_UInt64Value *) _upb_Message_New(
                &google_protobuf_UInt64Value_msginit, arena);
        if (!sub) return NULL;
        envoy_config_core_v3_UdpSocketConfig_set_max_rx_datagram_size(msg, sub);
    }
    return sub;
}

UPB_INLINE void envoy_config_core_v3_UdpSocketConfig_set_prefer_gro(
        envoy_config_core_v3_UdpSocketConfig * msg,
struct google_protobuf_BoolValue *value
) {
_upb_sethas(msg,
2);
*
UPB_PTR_AT(msg, UPB_SIZE(8, 16),
struct google_protobuf_BoolValue*) =
value;
}

UPB_INLINE struct google_protobuf_BoolValue *
envoy_config_core_v3_UdpSocketConfig_mutable_prefer_gro(envoy_config_core_v3_UdpSocketConfig * msg,
                                                        upb_Arena * arena) {
    struct google_protobuf_BoolValue *sub = (struct google_protobuf_BoolValue *) envoy_config_core_v3_UdpSocketConfig_prefer_gro(
            msg);
    if (sub == NULL) {
        sub = (struct google_protobuf_BoolValue *) _upb_Message_New(
                &google_protobuf_BoolValue_msginit, arena);
        if (!sub) return NULL;
        envoy_config_core_v3_UdpSocketConfig_set_prefer_gro(msg, sub);
    }
    return sub;
}

extern const upb_MiniTable_File envoy_config_core_v3_udp_socket_config_proto_upb_file_layout;

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* ENVOY_CONFIG_CORE_V3_UDP_SOCKET_CONFIG_PROTO_UPB_H_ */
