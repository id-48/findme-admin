/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/config/trace/v3/lightstep.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef ENVOY_CONFIG_TRACE_V3_LIGHTSTEP_PROTO_UPB_H_
#define ENVOY_CONFIG_TRACE_V3_LIGHTSTEP_PROTO_UPB_H_

#include "upb/msg_internal.h"
#include "upb/decode.h"
#include "upb/decode_fast.h"
#include "upb/encode.h"

#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

struct envoy_config_trace_v3_LightstepConfig;
typedef struct envoy_config_trace_v3_LightstepConfig envoy_config_trace_v3_LightstepConfig;
extern const upb_MiniTable envoy_config_trace_v3_LightstepConfig_msginit;
struct envoy_config_core_v3_DataSource;
extern const upb_MiniTable envoy_config_core_v3_DataSource_msginit;

typedef enum {
    envoy_config_trace_v3_LightstepConfig_ENVOY = 0,
    envoy_config_trace_v3_LightstepConfig_LIGHTSTEP = 1,
    envoy_config_trace_v3_LightstepConfig_B3 = 2,
    envoy_config_trace_v3_LightstepConfig_TRACE_CONTEXT = 3
} envoy_config_trace_v3_LightstepConfig_PropagationMode;


/* envoy.config.trace.v3.LightstepConfig */

UPB_INLINE envoy_config_trace_v3_LightstepConfig
*
envoy_config_trace_v3_LightstepConfig_new(upb_Arena
* arena) {
return (envoy_config_trace_v3_LightstepConfig*)
_upb_Message_New(&envoy_config_trace_v3_LightstepConfig_msginit, arena
);
}
UPB_INLINE envoy_config_trace_v3_LightstepConfig
*

envoy_config_trace_v3_LightstepConfig_parse(const char *buf, size_t size, upb_Arena *arena) {
    envoy_config_trace_v3_LightstepConfig * ret = envoy_config_trace_v3_LightstepConfig_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_config_trace_v3_LightstepConfig_msginit, NULL, 0,
                   arena) != kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE envoy_config_trace_v3_LightstepConfig
*

envoy_config_trace_v3_LightstepConfig_parse_ex(const char *buf, size_t size,
                                               const upb_ExtensionRegistry *extreg,
                                               int options, upb_Arena *arena) {
    envoy_config_trace_v3_LightstepConfig * ret = envoy_config_trace_v3_LightstepConfig_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_config_trace_v3_LightstepConfig_msginit, extreg, options,
                   arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *
envoy_config_trace_v3_LightstepConfig_serialize(const envoy_config_trace_v3_LightstepConfig *msg,
                                                upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_config_trace_v3_LightstepConfig_msginit, 0, arena, &ptr, len);
    return ptr;
}

UPB_INLINE char *
envoy_config_trace_v3_LightstepConfig_serialize_ex(const envoy_config_trace_v3_LightstepConfig *msg,
                                                   int options,
                                                   upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_config_trace_v3_LightstepConfig_msginit, options, arena, &ptr,
                      len);
    return ptr;
}

UPB_INLINE void envoy_config_trace_v3_LightstepConfig_clear_collector_cluster(
        const envoy_config_trace_v3_LightstepConfig *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(4, 8), upb_StringView) = upb_StringView_FromDataAndSize(NULL, 0);
}

UPB_INLINE upb_StringView

envoy_config_trace_v3_LightstepConfig_collector_cluster(
        const envoy_config_trace_v3_LightstepConfig *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(4, 8), upb_StringView);
}

UPB_INLINE void envoy_config_trace_v3_LightstepConfig_clear_access_token_file(
        const envoy_config_trace_v3_LightstepConfig *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(12, 24), upb_StringView) = upb_StringView_FromDataAndSize(NULL, 0);
}

UPB_INLINE upb_StringView

envoy_config_trace_v3_LightstepConfig_access_token_file(
        const envoy_config_trace_v3_LightstepConfig *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(12, 24), upb_StringView);
}

UPB_INLINE void envoy_config_trace_v3_LightstepConfig_clear_propagation_modes(
        const envoy_config_trace_v3_LightstepConfig *msg) {
    _upb_array_detach(msg, UPB_SIZE(20, 40));
}

UPB_INLINE int32_t
const*

envoy_config_trace_v3_LightstepConfig_propagation_modes(
        const envoy_config_trace_v3_LightstepConfig *msg, size_t *len) {
    return (int32_t const*)_upb_array_accessor(msg, UPB_SIZE(20, 40), len);
}

UPB_INLINE bool envoy_config_trace_v3_LightstepConfig_has_access_token(
        const envoy_config_trace_v3_LightstepConfig *msg) {
    return _upb_hasbit(msg, 1);
}

UPB_INLINE void envoy_config_trace_v3_LightstepConfig_clear_access_token(
        const envoy_config_trace_v3_LightstepConfig *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(24, 48),
    const upb_Message*) = NULL;
}

UPB_INLINE const struct envoy_config_core_v3_DataSource *
envoy_config_trace_v3_LightstepConfig_access_token(
        const envoy_config_trace_v3_LightstepConfig *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(24, 48),
    const struct envoy_config_core_v3_DataSource*);
}

UPB_INLINE void envoy_config_trace_v3_LightstepConfig_set_collector_cluster(
        envoy_config_trace_v3_LightstepConfig * msg, upb_StringView
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(4, 8), upb_StringView
) =
value;
}
UPB_INLINE void envoy_config_trace_v3_LightstepConfig_set_access_token_file(
        envoy_config_trace_v3_LightstepConfig * msg, upb_StringView
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(12, 24), upb_StringView
) =
value;
}
UPB_INLINE int32_t
*
envoy_config_trace_v3_LightstepConfig_mutable_propagation_modes(envoy_config_trace_v3_LightstepConfig
* msg,
size_t *len
) {
return (int32_t*)
_upb_array_mutable_accessor(msg, UPB_SIZE(20, 40), len
);
}
UPB_INLINE int32_t
*
envoy_config_trace_v3_LightstepConfig_resize_propagation_modes(envoy_config_trace_v3_LightstepConfig
* msg,
size_t len, upb_Arena
* arena) {
return (int32_t*)
_upb_Array_Resize_accessor2(msg, UPB_SIZE(20, 40), len,
2, arena);
}
UPB_INLINE bool envoy_config_trace_v3_LightstepConfig_add_propagation_modes(
        envoy_config_trace_v3_LightstepConfig * msg, int32_t
val,
upb_Arena *arena
) {
return
_upb_Array_Append_accessor2(msg, UPB_SIZE(20, 40),
2, &val, arena);
}
UPB_INLINE void envoy_config_trace_v3_LightstepConfig_set_access_token(
        envoy_config_trace_v3_LightstepConfig * msg,
struct envoy_config_core_v3_DataSource *value
) {
_upb_sethas(msg,
1);
*
UPB_PTR_AT(msg, UPB_SIZE(24, 48),
struct envoy_config_core_v3_DataSource*) =
value;
}

UPB_INLINE struct envoy_config_core_v3_DataSource *
envoy_config_trace_v3_LightstepConfig_mutable_access_token(
        envoy_config_trace_v3_LightstepConfig * msg, upb_Arena * arena) {
    struct envoy_config_core_v3_DataSource *sub = (struct envoy_config_core_v3_DataSource *) envoy_config_trace_v3_LightstepConfig_access_token(
            msg);
    if (sub == NULL) {
        sub = (struct envoy_config_core_v3_DataSource *) _upb_Message_New(
                &envoy_config_core_v3_DataSource_msginit, arena);
        if (!sub) return NULL;
        envoy_config_trace_v3_LightstepConfig_set_access_token(msg, sub);
    }
    return sub;
}

extern const upb_MiniTable_File envoy_config_trace_v3_lightstep_proto_upb_file_layout;

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* ENVOY_CONFIG_TRACE_V3_LIGHTSTEP_PROTO_UPB_H_ */
