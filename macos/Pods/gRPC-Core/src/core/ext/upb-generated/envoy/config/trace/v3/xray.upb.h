/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/config/trace/v3/xray.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef ENVOY_CONFIG_TRACE_V3_XRAY_PROTO_UPB_H_
#define ENVOY_CONFIG_TRACE_V3_XRAY_PROTO_UPB_H_

#include "upb/msg_internal.h"
#include "upb/decode.h"
#include "upb/decode_fast.h"
#include "upb/encode.h"

#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

struct envoy_config_trace_v3_XRayConfig;
struct envoy_config_trace_v3_XRayConfig_SegmentFields;
typedef struct envoy_config_trace_v3_XRayConfig envoy_config_trace_v3_XRayConfig;
typedef struct envoy_config_trace_v3_XRayConfig_SegmentFields envoy_config_trace_v3_XRayConfig_SegmentFields;
extern const upb_MiniTable envoy_config_trace_v3_XRayConfig_msginit;
extern const upb_MiniTable envoy_config_trace_v3_XRayConfig_SegmentFields_msginit;
struct envoy_config_core_v3_DataSource;
struct envoy_config_core_v3_SocketAddress;
struct google_protobuf_Struct;
extern const upb_MiniTable envoy_config_core_v3_DataSource_msginit;
extern const upb_MiniTable envoy_config_core_v3_SocketAddress_msginit;
extern const upb_MiniTable google_protobuf_Struct_msginit;


/* envoy.config.trace.v3.XRayConfig */

UPB_INLINE envoy_config_trace_v3_XRayConfig
*
envoy_config_trace_v3_XRayConfig_new(upb_Arena
* arena) {
return (envoy_config_trace_v3_XRayConfig*)
_upb_Message_New(&envoy_config_trace_v3_XRayConfig_msginit, arena
);
}
UPB_INLINE envoy_config_trace_v3_XRayConfig
*

envoy_config_trace_v3_XRayConfig_parse(const char *buf, size_t size, upb_Arena *arena) {
    envoy_config_trace_v3_XRayConfig * ret = envoy_config_trace_v3_XRayConfig_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_config_trace_v3_XRayConfig_msginit, NULL, 0, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE envoy_config_trace_v3_XRayConfig
*

envoy_config_trace_v3_XRayConfig_parse_ex(const char *buf, size_t size,
                                          const upb_ExtensionRegistry *extreg,
                                          int options, upb_Arena *arena) {
    envoy_config_trace_v3_XRayConfig * ret = envoy_config_trace_v3_XRayConfig_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_config_trace_v3_XRayConfig_msginit, extreg, options,
                   arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *
envoy_config_trace_v3_XRayConfig_serialize(const envoy_config_trace_v3_XRayConfig *msg,
                                           upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_config_trace_v3_XRayConfig_msginit, 0, arena, &ptr, len);
    return ptr;
}

UPB_INLINE char *
envoy_config_trace_v3_XRayConfig_serialize_ex(const envoy_config_trace_v3_XRayConfig *msg,
                                              int options,
                                              upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_config_trace_v3_XRayConfig_msginit, options, arena, &ptr, len);
    return ptr;
}

UPB_INLINE bool
envoy_config_trace_v3_XRayConfig_has_daemon_endpoint(const envoy_config_trace_v3_XRayConfig *msg) {
    return _upb_hasbit(msg, 1);
}

UPB_INLINE void envoy_config_trace_v3_XRayConfig_clear_daemon_endpoint(
        const envoy_config_trace_v3_XRayConfig *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(4, 8),
    const upb_Message*) = NULL;
}

UPB_INLINE const struct envoy_config_core_v3_SocketAddress *
envoy_config_trace_v3_XRayConfig_daemon_endpoint(const envoy_config_trace_v3_XRayConfig *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(4, 8),
    const struct envoy_config_core_v3_SocketAddress*);
}

UPB_INLINE void
envoy_config_trace_v3_XRayConfig_clear_segment_name(const envoy_config_trace_v3_XRayConfig *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(8, 16), upb_StringView) = upb_StringView_FromDataAndSize(NULL, 0);
}

UPB_INLINE upb_StringView

envoy_config_trace_v3_XRayConfig_segment_name(const envoy_config_trace_v3_XRayConfig *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(8, 16), upb_StringView);
}

UPB_INLINE bool envoy_config_trace_v3_XRayConfig_has_sampling_rule_manifest(
        const envoy_config_trace_v3_XRayConfig *msg) {
    return _upb_hasbit(msg, 2);
}

UPB_INLINE void envoy_config_trace_v3_XRayConfig_clear_sampling_rule_manifest(
        const envoy_config_trace_v3_XRayConfig *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(16, 32),
    const upb_Message*) = NULL;
}

UPB_INLINE const struct envoy_config_core_v3_DataSource *
envoy_config_trace_v3_XRayConfig_sampling_rule_manifest(
        const envoy_config_trace_v3_XRayConfig *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(16, 32),
    const struct envoy_config_core_v3_DataSource*);
}

UPB_INLINE bool
envoy_config_trace_v3_XRayConfig_has_segment_fields(const envoy_config_trace_v3_XRayConfig *msg) {
    return _upb_hasbit(msg, 3);
}

UPB_INLINE void
envoy_config_trace_v3_XRayConfig_clear_segment_fields(const envoy_config_trace_v3_XRayConfig *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(20, 40),
    const upb_Message*) = NULL;
}

UPB_INLINE const envoy_config_trace_v3_XRayConfig_SegmentFields
*

envoy_config_trace_v3_XRayConfig_segment_fields(const envoy_config_trace_v3_XRayConfig *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(20, 40),
    const envoy_config_trace_v3_XRayConfig_SegmentFields*);
}

UPB_INLINE void envoy_config_trace_v3_XRayConfig_set_daemon_endpoint(
        envoy_config_trace_v3_XRayConfig * msg,
struct envoy_config_core_v3_SocketAddress *value
) {
_upb_sethas(msg,
1);
*
UPB_PTR_AT(msg, UPB_SIZE(4, 8),
struct envoy_config_core_v3_SocketAddress*) =
value;
}

UPB_INLINE struct envoy_config_core_v3_SocketAddress *
envoy_config_trace_v3_XRayConfig_mutable_daemon_endpoint(envoy_config_trace_v3_XRayConfig * msg,
                                                         upb_Arena * arena) {
    struct envoy_config_core_v3_SocketAddress *sub = (struct envoy_config_core_v3_SocketAddress *) envoy_config_trace_v3_XRayConfig_daemon_endpoint(
            msg);
    if (sub == NULL) {
        sub = (struct envoy_config_core_v3_SocketAddress *) _upb_Message_New(
                &envoy_config_core_v3_SocketAddress_msginit, arena);
        if (!sub) return NULL;
        envoy_config_trace_v3_XRayConfig_set_daemon_endpoint(msg, sub);
    }
    return sub;
}

UPB_INLINE void envoy_config_trace_v3_XRayConfig_set_segment_name(
        envoy_config_trace_v3_XRayConfig * msg, upb_StringView
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(8, 16), upb_StringView
) =
value;
}
UPB_INLINE void envoy_config_trace_v3_XRayConfig_set_sampling_rule_manifest(
        envoy_config_trace_v3_XRayConfig * msg,
struct envoy_config_core_v3_DataSource *value
) {
_upb_sethas(msg,
2);
*
UPB_PTR_AT(msg, UPB_SIZE(16, 32),
struct envoy_config_core_v3_DataSource*) =
value;
}

UPB_INLINE struct envoy_config_core_v3_DataSource *
envoy_config_trace_v3_XRayConfig_mutable_sampling_rule_manifest(
        envoy_config_trace_v3_XRayConfig * msg, upb_Arena * arena) {
    struct envoy_config_core_v3_DataSource *sub = (struct envoy_config_core_v3_DataSource *) envoy_config_trace_v3_XRayConfig_sampling_rule_manifest(
            msg);
    if (sub == NULL) {
        sub = (struct envoy_config_core_v3_DataSource *) _upb_Message_New(
                &envoy_config_core_v3_DataSource_msginit, arena);
        if (!sub) return NULL;
        envoy_config_trace_v3_XRayConfig_set_sampling_rule_manifest(msg, sub);
    }
    return sub;
}

UPB_INLINE void
envoy_config_trace_v3_XRayConfig_set_segment_fields(envoy_config_trace_v3_XRayConfig * msg,
                                                    envoy_config_trace_v3_XRayConfig_SegmentFields *
                                                    value) {
    _upb_sethas(msg, 3);
    *UPB_PTR_AT(msg, UPB_SIZE(20, 40), envoy_config_trace_v3_XRayConfig_SegmentFields * ) = value;
}

UPB_INLINE struct envoy_config_trace_v3_XRayConfig_SegmentFields *
envoy_config_trace_v3_XRayConfig_mutable_segment_fields(envoy_config_trace_v3_XRayConfig * msg,
                                                        upb_Arena * arena) {
    struct envoy_config_trace_v3_XRayConfig_SegmentFields *sub = (struct envoy_config_trace_v3_XRayConfig_SegmentFields *) envoy_config_trace_v3_XRayConfig_segment_fields(
            msg);
    if (sub == NULL) {
        sub = (struct envoy_config_trace_v3_XRayConfig_SegmentFields *) _upb_Message_New(
                &envoy_config_trace_v3_XRayConfig_SegmentFields_msginit, arena);
        if (!sub) return NULL;
        envoy_config_trace_v3_XRayConfig_set_segment_fields(msg, sub);
    }
    return sub;
}

/* envoy.config.trace.v3.XRayConfig.SegmentFields */

UPB_INLINE envoy_config_trace_v3_XRayConfig_SegmentFields
*
envoy_config_trace_v3_XRayConfig_SegmentFields_new(upb_Arena
* arena) {
return (envoy_config_trace_v3_XRayConfig_SegmentFields*)
_upb_Message_New(&envoy_config_trace_v3_XRayConfig_SegmentFields_msginit, arena
);
}
UPB_INLINE envoy_config_trace_v3_XRayConfig_SegmentFields
*

envoy_config_trace_v3_XRayConfig_SegmentFields_parse(const char *buf, size_t size,
                                                     upb_Arena *arena) {
    envoy_config_trace_v3_XRayConfig_SegmentFields *
    ret = envoy_config_trace_v3_XRayConfig_SegmentFields_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_config_trace_v3_XRayConfig_SegmentFields_msginit, NULL, 0,
                   arena) != kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE envoy_config_trace_v3_XRayConfig_SegmentFields
*

envoy_config_trace_v3_XRayConfig_SegmentFields_parse_ex(const char *buf, size_t size,
                                                        const upb_ExtensionRegistry *extreg,
                                                        int options, upb_Arena *arena) {
    envoy_config_trace_v3_XRayConfig_SegmentFields *
    ret = envoy_config_trace_v3_XRayConfig_SegmentFields_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_config_trace_v3_XRayConfig_SegmentFields_msginit, extreg,
                   options, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *envoy_config_trace_v3_XRayConfig_SegmentFields_serialize(
        const envoy_config_trace_v3_XRayConfig_SegmentFields *msg, upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_config_trace_v3_XRayConfig_SegmentFields_msginit, 0, arena, &ptr,
                      len);
    return ptr;
}

UPB_INLINE char *envoy_config_trace_v3_XRayConfig_SegmentFields_serialize_ex(
        const envoy_config_trace_v3_XRayConfig_SegmentFields *msg, int options,
        upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_config_trace_v3_XRayConfig_SegmentFields_msginit, options, arena,
                      &ptr, len);
    return ptr;
}

UPB_INLINE void envoy_config_trace_v3_XRayConfig_SegmentFields_clear_origin(
        const envoy_config_trace_v3_XRayConfig_SegmentFields *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(4, 8), upb_StringView) = upb_StringView_FromDataAndSize(NULL, 0);
}

UPB_INLINE upb_StringView

envoy_config_trace_v3_XRayConfig_SegmentFields_origin(
        const envoy_config_trace_v3_XRayConfig_SegmentFields *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(4, 8), upb_StringView);
}

UPB_INLINE bool envoy_config_trace_v3_XRayConfig_SegmentFields_has_aws(
        const envoy_config_trace_v3_XRayConfig_SegmentFields *msg) {
    return _upb_hasbit(msg, 1);
}

UPB_INLINE void envoy_config_trace_v3_XRayConfig_SegmentFields_clear_aws(
        const envoy_config_trace_v3_XRayConfig_SegmentFields *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(12, 24),
    const upb_Message*) = NULL;
}

UPB_INLINE const struct google_protobuf_Struct *envoy_config_trace_v3_XRayConfig_SegmentFields_aws(
        const envoy_config_trace_v3_XRayConfig_SegmentFields *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(12, 24),
    const struct google_protobuf_Struct*);
}

UPB_INLINE void envoy_config_trace_v3_XRayConfig_SegmentFields_set_origin(
        envoy_config_trace_v3_XRayConfig_SegmentFields * msg, upb_StringView
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(4, 8), upb_StringView
) =
value;
}
UPB_INLINE void envoy_config_trace_v3_XRayConfig_SegmentFields_set_aws(
        envoy_config_trace_v3_XRayConfig_SegmentFields * msg,
struct google_protobuf_Struct *value
) {
_upb_sethas(msg,
1);
*
UPB_PTR_AT(msg, UPB_SIZE(12, 24),
struct google_protobuf_Struct*) =
value;
}

UPB_INLINE struct google_protobuf_Struct *
envoy_config_trace_v3_XRayConfig_SegmentFields_mutable_aws(
        envoy_config_trace_v3_XRayConfig_SegmentFields * msg, upb_Arena * arena) {
    struct google_protobuf_Struct *sub = (struct google_protobuf_Struct *) envoy_config_trace_v3_XRayConfig_SegmentFields_aws(
            msg);
    if (sub == NULL) {
        sub = (struct google_protobuf_Struct *) _upb_Message_New(&google_protobuf_Struct_msginit,
                                                                 arena);
        if (!sub) return NULL;
        envoy_config_trace_v3_XRayConfig_SegmentFields_set_aws(msg, sub);
    }
    return sub;
}

extern const upb_MiniTable_File envoy_config_trace_v3_xray_proto_upb_file_layout;

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* ENVOY_CONFIG_TRACE_V3_XRAY_PROTO_UPB_H_ */
