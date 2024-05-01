/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/service/load_stats/v3/lrs.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef ENVOY_SERVICE_LOAD_STATS_V3_LRS_PROTO_UPB_H_
#define ENVOY_SERVICE_LOAD_STATS_V3_LRS_PROTO_UPB_H_

#include "upb/msg_internal.h"
#include "upb/decode.h"
#include "upb/decode_fast.h"
#include "upb/encode.h"

#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

struct envoy_service_load_stats_v3_LoadStatsRequest;
struct envoy_service_load_stats_v3_LoadStatsResponse;
typedef struct envoy_service_load_stats_v3_LoadStatsRequest envoy_service_load_stats_v3_LoadStatsRequest;
typedef struct envoy_service_load_stats_v3_LoadStatsResponse envoy_service_load_stats_v3_LoadStatsResponse;
extern const upb_MiniTable envoy_service_load_stats_v3_LoadStatsRequest_msginit;
extern const upb_MiniTable envoy_service_load_stats_v3_LoadStatsResponse_msginit;
struct envoy_config_core_v3_Node;
struct envoy_config_endpoint_v3_ClusterStats;
struct google_protobuf_Duration;
extern const upb_MiniTable envoy_config_core_v3_Node_msginit;
extern const upb_MiniTable envoy_config_endpoint_v3_ClusterStats_msginit;
extern const upb_MiniTable google_protobuf_Duration_msginit;


/* envoy.service.load_stats.v3.LoadStatsRequest */

UPB_INLINE envoy_service_load_stats_v3_LoadStatsRequest
*
envoy_service_load_stats_v3_LoadStatsRequest_new(upb_Arena
* arena) {
return (envoy_service_load_stats_v3_LoadStatsRequest*)
_upb_Message_New(&envoy_service_load_stats_v3_LoadStatsRequest_msginit, arena
);
}
UPB_INLINE envoy_service_load_stats_v3_LoadStatsRequest
*

envoy_service_load_stats_v3_LoadStatsRequest_parse(const char *buf, size_t size, upb_Arena *arena) {
    envoy_service_load_stats_v3_LoadStatsRequest *
    ret = envoy_service_load_stats_v3_LoadStatsRequest_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_service_load_stats_v3_LoadStatsRequest_msginit, NULL, 0,
                   arena) != kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE envoy_service_load_stats_v3_LoadStatsRequest
*

envoy_service_load_stats_v3_LoadStatsRequest_parse_ex(const char *buf, size_t size,
                                                      const upb_ExtensionRegistry *extreg,
                                                      int options, upb_Arena *arena) {
    envoy_service_load_stats_v3_LoadStatsRequest *
    ret = envoy_service_load_stats_v3_LoadStatsRequest_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_service_load_stats_v3_LoadStatsRequest_msginit, extreg,
                   options, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *envoy_service_load_stats_v3_LoadStatsRequest_serialize(
        const envoy_service_load_stats_v3_LoadStatsRequest *msg, upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_service_load_stats_v3_LoadStatsRequest_msginit, 0, arena, &ptr,
                      len);
    return ptr;
}

UPB_INLINE char *envoy_service_load_stats_v3_LoadStatsRequest_serialize_ex(
        const envoy_service_load_stats_v3_LoadStatsRequest *msg, int options,
        upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_service_load_stats_v3_LoadStatsRequest_msginit, options, arena,
                      &ptr, len);
    return ptr;
}

UPB_INLINE bool envoy_service_load_stats_v3_LoadStatsRequest_has_node(
        const envoy_service_load_stats_v3_LoadStatsRequest *msg) {
    return _upb_hasbit(msg, 1);
}

UPB_INLINE void envoy_service_load_stats_v3_LoadStatsRequest_clear_node(
        const envoy_service_load_stats_v3_LoadStatsRequest *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(4, 8),
    const upb_Message*) = NULL;
}

UPB_INLINE const struct envoy_config_core_v3_Node *
envoy_service_load_stats_v3_LoadStatsRequest_node(
        const envoy_service_load_stats_v3_LoadStatsRequest *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(4, 8),
    const struct envoy_config_core_v3_Node*);
}

UPB_INLINE bool envoy_service_load_stats_v3_LoadStatsRequest_has_cluster_stats(
        const envoy_service_load_stats_v3_LoadStatsRequest *msg) {
    return _upb_has_submsg_nohasbit(msg, UPB_SIZE(8, 16));
}

UPB_INLINE void envoy_service_load_stats_v3_LoadStatsRequest_clear_cluster_stats(
        const envoy_service_load_stats_v3_LoadStatsRequest *msg) {
    _upb_array_detach(msg, UPB_SIZE(8, 16));
}

UPB_INLINE const struct envoy_config_endpoint_v3_ClusterStats *const *
envoy_service_load_stats_v3_LoadStatsRequest_cluster_stats(
        const envoy_service_load_stats_v3_LoadStatsRequest *msg, size_t *len) {
    return (const struct envoy_config_endpoint_v3_ClusterStats *const *) _upb_array_accessor(msg,
                                                                                             UPB_SIZE(
                                                                                                     8,
                                                                                                     16),
                                                                                             len);
}

UPB_INLINE void envoy_service_load_stats_v3_LoadStatsRequest_set_node(
        envoy_service_load_stats_v3_LoadStatsRequest * msg,
struct envoy_config_core_v3_Node *value
) {
_upb_sethas(msg,
1);
*
UPB_PTR_AT(msg, UPB_SIZE(4, 8),
struct envoy_config_core_v3_Node*) =
value;
}

UPB_INLINE struct envoy_config_core_v3_Node *
envoy_service_load_stats_v3_LoadStatsRequest_mutable_node(
        envoy_service_load_stats_v3_LoadStatsRequest * msg, upb_Arena * arena) {
    struct envoy_config_core_v3_Node *sub = (struct envoy_config_core_v3_Node *) envoy_service_load_stats_v3_LoadStatsRequest_node(
            msg);
    if (sub == NULL) {
        sub = (struct envoy_config_core_v3_Node *) _upb_Message_New(
                &envoy_config_core_v3_Node_msginit, arena);
        if (!sub) return NULL;
        envoy_service_load_stats_v3_LoadStatsRequest_set_node(msg, sub);
    }
    return sub;
}

UPB_INLINE struct envoy_config_endpoint_v3_ClusterStats **
envoy_service_load_stats_v3_LoadStatsRequest_mutable_cluster_stats(
        envoy_service_load_stats_v3_LoadStatsRequest * msg, size_t * len) {
    return (struct envoy_config_endpoint_v3_ClusterStats **) _upb_array_mutable_accessor(msg,
                                                                                         UPB_SIZE(8,
                                                                                                  16),
                                                                                         len);
}

UPB_INLINE struct envoy_config_endpoint_v3_ClusterStats **envoy_service_load_stats_v3_LoadStatsRequest_resize_cluster_stats(
        envoy_service_load_stats_v3_LoadStatsRequest * msg, size_t
len,
upb_Arena *arena
) {
return (struct envoy_config_endpoint_v3_ClusterStats**)
_upb_Array_Resize_accessor2(msg, UPB_SIZE(8, 16), len, UPB_SIZE(2, 3), arena
);
}

UPB_INLINE struct envoy_config_endpoint_v3_ClusterStats *
envoy_service_load_stats_v3_LoadStatsRequest_add_cluster_stats(
        envoy_service_load_stats_v3_LoadStatsRequest * msg, upb_Arena * arena) {
    struct envoy_config_endpoint_v3_ClusterStats *sub = (struct envoy_config_endpoint_v3_ClusterStats *) _upb_Message_New(
            &envoy_config_endpoint_v3_ClusterStats_msginit, arena);
    bool ok = _upb_Array_Append_accessor2(msg, UPB_SIZE(8, 16), UPB_SIZE(2, 3), &sub, arena);
    if (!ok) return NULL;
    return sub;
}

/* envoy.service.load_stats.v3.LoadStatsResponse */

UPB_INLINE envoy_service_load_stats_v3_LoadStatsResponse
*
envoy_service_load_stats_v3_LoadStatsResponse_new(upb_Arena
* arena) {
return (envoy_service_load_stats_v3_LoadStatsResponse*)
_upb_Message_New(&envoy_service_load_stats_v3_LoadStatsResponse_msginit, arena
);
}
UPB_INLINE envoy_service_load_stats_v3_LoadStatsResponse
*

envoy_service_load_stats_v3_LoadStatsResponse_parse(const char *buf, size_t size,
                                                    upb_Arena *arena) {
    envoy_service_load_stats_v3_LoadStatsResponse *
    ret = envoy_service_load_stats_v3_LoadStatsResponse_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_service_load_stats_v3_LoadStatsResponse_msginit, NULL, 0,
                   arena) != kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE envoy_service_load_stats_v3_LoadStatsResponse
*

envoy_service_load_stats_v3_LoadStatsResponse_parse_ex(const char *buf, size_t size,
                                                       const upb_ExtensionRegistry *extreg,
                                                       int options, upb_Arena *arena) {
    envoy_service_load_stats_v3_LoadStatsResponse *
    ret = envoy_service_load_stats_v3_LoadStatsResponse_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_service_load_stats_v3_LoadStatsResponse_msginit, extreg,
                   options, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *envoy_service_load_stats_v3_LoadStatsResponse_serialize(
        const envoy_service_load_stats_v3_LoadStatsResponse *msg, upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_service_load_stats_v3_LoadStatsResponse_msginit, 0, arena, &ptr,
                      len);
    return ptr;
}

UPB_INLINE char *envoy_service_load_stats_v3_LoadStatsResponse_serialize_ex(
        const envoy_service_load_stats_v3_LoadStatsResponse *msg, int options,
        upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_service_load_stats_v3_LoadStatsResponse_msginit, options, arena,
                      &ptr, len);
    return ptr;
}

UPB_INLINE void envoy_service_load_stats_v3_LoadStatsResponse_clear_clusters(
        const envoy_service_load_stats_v3_LoadStatsResponse *msg) {
    _upb_array_detach(msg, UPB_SIZE(4, 8));
}

UPB_INLINE upb_StringView
const*

envoy_service_load_stats_v3_LoadStatsResponse_clusters(
        const envoy_service_load_stats_v3_LoadStatsResponse *msg, size_t *len) {
    return (upb_StringView const*)_upb_array_accessor(msg, UPB_SIZE(4, 8), len);
}

UPB_INLINE bool envoy_service_load_stats_v3_LoadStatsResponse_has_load_reporting_interval(
        const envoy_service_load_stats_v3_LoadStatsResponse *msg) {
    return _upb_hasbit(msg, 1);
}

UPB_INLINE void envoy_service_load_stats_v3_LoadStatsResponse_clear_load_reporting_interval(
        const envoy_service_load_stats_v3_LoadStatsResponse *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(8, 16),
    const upb_Message*) = NULL;
}

UPB_INLINE const struct google_protobuf_Duration *
envoy_service_load_stats_v3_LoadStatsResponse_load_reporting_interval(
        const envoy_service_load_stats_v3_LoadStatsResponse *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(8, 16),
    const struct google_protobuf_Duration*);
}

UPB_INLINE void envoy_service_load_stats_v3_LoadStatsResponse_clear_report_endpoint_granularity(
        const envoy_service_load_stats_v3_LoadStatsResponse *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(1, 1), bool) = 0;
}

UPB_INLINE bool envoy_service_load_stats_v3_LoadStatsResponse_report_endpoint_granularity(
        const envoy_service_load_stats_v3_LoadStatsResponse *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(1, 1), bool);
}

UPB_INLINE void envoy_service_load_stats_v3_LoadStatsResponse_clear_send_all_clusters(
        const envoy_service_load_stats_v3_LoadStatsResponse *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(2, 2), bool) = 0;
}

UPB_INLINE bool envoy_service_load_stats_v3_LoadStatsResponse_send_all_clusters(
        const envoy_service_load_stats_v3_LoadStatsResponse *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(2, 2), bool);
}

UPB_INLINE upb_StringView
*
envoy_service_load_stats_v3_LoadStatsResponse_mutable_clusters(envoy_service_load_stats_v3_LoadStatsResponse
* msg,
size_t *len
) {
return (upb_StringView*)
_upb_array_mutable_accessor(msg, UPB_SIZE(4, 8), len
);
}
UPB_INLINE upb_StringView
*
envoy_service_load_stats_v3_LoadStatsResponse_resize_clusters(envoy_service_load_stats_v3_LoadStatsResponse
* msg,
size_t len, upb_Arena
* arena) {
return (upb_StringView*)
_upb_Array_Resize_accessor2(msg, UPB_SIZE(4, 8), len, UPB_SIZE(3, 4), arena
);
}
UPB_INLINE bool envoy_service_load_stats_v3_LoadStatsResponse_add_clusters(
        envoy_service_load_stats_v3_LoadStatsResponse * msg, upb_StringView
val,
upb_Arena *arena
) {
return
_upb_Array_Append_accessor2(msg, UPB_SIZE(4, 8), UPB_SIZE(3, 4), &val, arena
);
}
UPB_INLINE void envoy_service_load_stats_v3_LoadStatsResponse_set_load_reporting_interval(
        envoy_service_load_stats_v3_LoadStatsResponse * msg,
struct google_protobuf_Duration *value
) {
_upb_sethas(msg,
1);
*
UPB_PTR_AT(msg, UPB_SIZE(8, 16),
struct google_protobuf_Duration*) =
value;
}

UPB_INLINE struct google_protobuf_Duration *
envoy_service_load_stats_v3_LoadStatsResponse_mutable_load_reporting_interval(
        envoy_service_load_stats_v3_LoadStatsResponse * msg, upb_Arena * arena) {
    struct google_protobuf_Duration *sub = (struct google_protobuf_Duration *) envoy_service_load_stats_v3_LoadStatsResponse_load_reporting_interval(
            msg);
    if (sub == NULL) {
        sub = (struct google_protobuf_Duration *) _upb_Message_New(
                &google_protobuf_Duration_msginit, arena);
        if (!sub) return NULL;
        envoy_service_load_stats_v3_LoadStatsResponse_set_load_reporting_interval(msg, sub);
    }
    return sub;
}

UPB_INLINE void envoy_service_load_stats_v3_LoadStatsResponse_set_report_endpoint_granularity(
        envoy_service_load_stats_v3_LoadStatsResponse * msg, bool
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(1, 1),
bool) =
value;
}
UPB_INLINE void envoy_service_load_stats_v3_LoadStatsResponse_set_send_all_clusters(
        envoy_service_load_stats_v3_LoadStatsResponse * msg, bool
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(2, 2),
bool) =
value;
}

extern const upb_MiniTable_File envoy_service_load_stats_v3_lrs_proto_upb_file_layout;

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* ENVOY_SERVICE_LOAD_STATS_V3_LRS_PROTO_UPB_H_ */
