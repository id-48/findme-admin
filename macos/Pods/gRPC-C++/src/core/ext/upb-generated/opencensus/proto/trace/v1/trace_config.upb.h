/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     opencensus/proto/trace/v1/trace_config.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef OPENCENSUS_PROTO_TRACE_V1_TRACE_CONFIG_PROTO_UPB_H_
#define OPENCENSUS_PROTO_TRACE_V1_TRACE_CONFIG_PROTO_UPB_H_

#include "upb/msg_internal.h"
#include "upb/decode.h"
#include "upb/decode_fast.h"
#include "upb/encode.h"

#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

struct opencensus_proto_trace_v1_TraceConfig;
struct opencensus_proto_trace_v1_ProbabilitySampler;
struct opencensus_proto_trace_v1_ConstantSampler;
struct opencensus_proto_trace_v1_RateLimitingSampler;
typedef struct opencensus_proto_trace_v1_TraceConfig opencensus_proto_trace_v1_TraceConfig;
typedef struct opencensus_proto_trace_v1_ProbabilitySampler opencensus_proto_trace_v1_ProbabilitySampler;
typedef struct opencensus_proto_trace_v1_ConstantSampler opencensus_proto_trace_v1_ConstantSampler;
typedef struct opencensus_proto_trace_v1_RateLimitingSampler opencensus_proto_trace_v1_RateLimitingSampler;
extern const upb_MiniTable opencensus_proto_trace_v1_TraceConfig_msginit;
extern const upb_MiniTable opencensus_proto_trace_v1_ProbabilitySampler_msginit;
extern const upb_MiniTable opencensus_proto_trace_v1_ConstantSampler_msginit;
extern const upb_MiniTable opencensus_proto_trace_v1_RateLimitingSampler_msginit;

typedef enum {
    opencensus_proto_trace_v1_ConstantSampler_ALWAYS_OFF = 0,
    opencensus_proto_trace_v1_ConstantSampler_ALWAYS_ON = 1,
    opencensus_proto_trace_v1_ConstantSampler_ALWAYS_PARENT = 2
} opencensus_proto_trace_v1_ConstantSampler_ConstantDecision;


/* opencensus.proto.trace.v1.TraceConfig */

UPB_INLINE opencensus_proto_trace_v1_TraceConfig
*
opencensus_proto_trace_v1_TraceConfig_new(upb_Arena
* arena) {
return (opencensus_proto_trace_v1_TraceConfig*)
_upb_Message_New(&opencensus_proto_trace_v1_TraceConfig_msginit, arena
);
}
UPB_INLINE opencensus_proto_trace_v1_TraceConfig
*

opencensus_proto_trace_v1_TraceConfig_parse(const char *buf, size_t size, upb_Arena *arena) {
    opencensus_proto_trace_v1_TraceConfig * ret = opencensus_proto_trace_v1_TraceConfig_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &opencensus_proto_trace_v1_TraceConfig_msginit, NULL, 0,
                   arena) != kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE opencensus_proto_trace_v1_TraceConfig
*

opencensus_proto_trace_v1_TraceConfig_parse_ex(const char *buf, size_t size,
                                               const upb_ExtensionRegistry *extreg,
                                               int options, upb_Arena *arena) {
    opencensus_proto_trace_v1_TraceConfig * ret = opencensus_proto_trace_v1_TraceConfig_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &opencensus_proto_trace_v1_TraceConfig_msginit, extreg, options,
                   arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *
opencensus_proto_trace_v1_TraceConfig_serialize(const opencensus_proto_trace_v1_TraceConfig *msg,
                                                upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &opencensus_proto_trace_v1_TraceConfig_msginit, 0, arena, &ptr, len);
    return ptr;
}

UPB_INLINE char *
opencensus_proto_trace_v1_TraceConfig_serialize_ex(const opencensus_proto_trace_v1_TraceConfig *msg,
                                                   int options,
                                                   upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &opencensus_proto_trace_v1_TraceConfig_msginit, options, arena, &ptr,
                      len);
    return ptr;
}

typedef enum {
    opencensus_proto_trace_v1_TraceConfig_sampler_probability_sampler = 1,
    opencensus_proto_trace_v1_TraceConfig_sampler_constant_sampler = 2,
    opencensus_proto_trace_v1_TraceConfig_sampler_rate_limiting_sampler = 3,
    opencensus_proto_trace_v1_TraceConfig_sampler_NOT_SET = 0
} opencensus_proto_trace_v1_TraceConfig_sampler_oneofcases;
UPB_INLINE opencensus_proto_trace_v1_TraceConfig_sampler_oneofcases

opencensus_proto_trace_v1_TraceConfig_sampler_case(
        const opencensus_proto_trace_v1_TraceConfig *msg) {
    return (opencensus_proto_trace_v1_TraceConfig_sampler_oneofcases) *UPB_PTR_AT(msg,
                                                                                  UPB_SIZE(0, 0),
                                                                                  int32_t);
}

UPB_INLINE bool opencensus_proto_trace_v1_TraceConfig_has_probability_sampler(
        const opencensus_proto_trace_v1_TraceConfig *msg) {
    return _upb_getoneofcase(msg, UPB_SIZE(0, 0)) == 1;
}

UPB_INLINE void opencensus_proto_trace_v1_TraceConfig_clear_probability_sampler(
        const opencensus_proto_trace_v1_TraceConfig *msg) {
    UPB_WRITE_ONEOF(msg, opencensus_proto_trace_v1_ProbabilitySampler * , UPB_SIZE(4, 8), 0,
                    UPB_SIZE(0, 0), opencensus_proto_trace_v1_TraceConfig_sampler_NOT_SET);
}

UPB_INLINE const opencensus_proto_trace_v1_ProbabilitySampler
*

opencensus_proto_trace_v1_TraceConfig_probability_sampler(
        const opencensus_proto_trace_v1_TraceConfig *msg) {
    return UPB_READ_ONEOF(msg,
    const opencensus_proto_trace_v1_ProbabilitySampler*, UPB_SIZE(4, 8), UPB_SIZE(0, 0), 1, NULL);
}

UPB_INLINE bool opencensus_proto_trace_v1_TraceConfig_has_constant_sampler(
        const opencensus_proto_trace_v1_TraceConfig *msg) {
    return _upb_getoneofcase(msg, UPB_SIZE(0, 0)) == 2;
}

UPB_INLINE void opencensus_proto_trace_v1_TraceConfig_clear_constant_sampler(
        const opencensus_proto_trace_v1_TraceConfig *msg) {
    UPB_WRITE_ONEOF(msg, opencensus_proto_trace_v1_ConstantSampler * , UPB_SIZE(4, 8), 0,
                    UPB_SIZE(0, 0), opencensus_proto_trace_v1_TraceConfig_sampler_NOT_SET);
}

UPB_INLINE const opencensus_proto_trace_v1_ConstantSampler
*

opencensus_proto_trace_v1_TraceConfig_constant_sampler(
        const opencensus_proto_trace_v1_TraceConfig *msg) {
    return UPB_READ_ONEOF(msg,
    const opencensus_proto_trace_v1_ConstantSampler*, UPB_SIZE(4, 8), UPB_SIZE(0, 0), 2, NULL);
}

UPB_INLINE bool opencensus_proto_trace_v1_TraceConfig_has_rate_limiting_sampler(
        const opencensus_proto_trace_v1_TraceConfig *msg) {
    return _upb_getoneofcase(msg, UPB_SIZE(0, 0)) == 3;
}

UPB_INLINE void opencensus_proto_trace_v1_TraceConfig_clear_rate_limiting_sampler(
        const opencensus_proto_trace_v1_TraceConfig *msg) {
    UPB_WRITE_ONEOF(msg, opencensus_proto_trace_v1_RateLimitingSampler * , UPB_SIZE(4, 8), 0,
                    UPB_SIZE(0, 0), opencensus_proto_trace_v1_TraceConfig_sampler_NOT_SET);
}

UPB_INLINE const opencensus_proto_trace_v1_RateLimitingSampler
*

opencensus_proto_trace_v1_TraceConfig_rate_limiting_sampler(
        const opencensus_proto_trace_v1_TraceConfig *msg) {
    return UPB_READ_ONEOF(msg,
    const opencensus_proto_trace_v1_RateLimitingSampler*, UPB_SIZE(4, 8), UPB_SIZE(0, 0), 3, NULL);
}

UPB_INLINE void opencensus_proto_trace_v1_TraceConfig_clear_max_number_of_attributes(
        const opencensus_proto_trace_v1_TraceConfig *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(8, 16), int64_t) = 0;
}

UPB_INLINE int64_t

opencensus_proto_trace_v1_TraceConfig_max_number_of_attributes(
        const opencensus_proto_trace_v1_TraceConfig *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(8, 16), int64_t);
}

UPB_INLINE void opencensus_proto_trace_v1_TraceConfig_clear_max_number_of_annotations(
        const opencensus_proto_trace_v1_TraceConfig *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(16, 24), int64_t) = 0;
}

UPB_INLINE int64_t

opencensus_proto_trace_v1_TraceConfig_max_number_of_annotations(
        const opencensus_proto_trace_v1_TraceConfig *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(16, 24), int64_t);
}

UPB_INLINE void opencensus_proto_trace_v1_TraceConfig_clear_max_number_of_message_events(
        const opencensus_proto_trace_v1_TraceConfig *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(24, 32), int64_t) = 0;
}

UPB_INLINE int64_t

opencensus_proto_trace_v1_TraceConfig_max_number_of_message_events(
        const opencensus_proto_trace_v1_TraceConfig *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(24, 32), int64_t);
}

UPB_INLINE void opencensus_proto_trace_v1_TraceConfig_clear_max_number_of_links(
        const opencensus_proto_trace_v1_TraceConfig *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(32, 40), int64_t) = 0;
}

UPB_INLINE int64_t

opencensus_proto_trace_v1_TraceConfig_max_number_of_links(
        const opencensus_proto_trace_v1_TraceConfig *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(32, 40), int64_t);
}

UPB_INLINE void opencensus_proto_trace_v1_TraceConfig_set_probability_sampler(
        opencensus_proto_trace_v1_TraceConfig * msg,
        opencensus_proto_trace_v1_ProbabilitySampler * value) {
    UPB_WRITE_ONEOF(msg, opencensus_proto_trace_v1_ProbabilitySampler * , UPB_SIZE(4, 8), value,
                    UPB_SIZE(0, 0), 1);
}

UPB_INLINE struct opencensus_proto_trace_v1_ProbabilitySampler *
opencensus_proto_trace_v1_TraceConfig_mutable_probability_sampler(
        opencensus_proto_trace_v1_TraceConfig * msg, upb_Arena * arena) {
    struct opencensus_proto_trace_v1_ProbabilitySampler *sub = (struct opencensus_proto_trace_v1_ProbabilitySampler *) opencensus_proto_trace_v1_TraceConfig_probability_sampler(
            msg);
    if (sub == NULL) {
        sub = (struct opencensus_proto_trace_v1_ProbabilitySampler *) _upb_Message_New(
                &opencensus_proto_trace_v1_ProbabilitySampler_msginit, arena);
        if (!sub) return NULL;
        opencensus_proto_trace_v1_TraceConfig_set_probability_sampler(msg, sub);
    }
    return sub;
}

UPB_INLINE void opencensus_proto_trace_v1_TraceConfig_set_constant_sampler(
        opencensus_proto_trace_v1_TraceConfig * msg,
        opencensus_proto_trace_v1_ConstantSampler * value) {
    UPB_WRITE_ONEOF(msg, opencensus_proto_trace_v1_ConstantSampler * , UPB_SIZE(4, 8), value,
                    UPB_SIZE(0, 0), 2);
}

UPB_INLINE struct opencensus_proto_trace_v1_ConstantSampler *
opencensus_proto_trace_v1_TraceConfig_mutable_constant_sampler(
        opencensus_proto_trace_v1_TraceConfig * msg, upb_Arena * arena) {
    struct opencensus_proto_trace_v1_ConstantSampler *sub = (struct opencensus_proto_trace_v1_ConstantSampler *) opencensus_proto_trace_v1_TraceConfig_constant_sampler(
            msg);
    if (sub == NULL) {
        sub = (struct opencensus_proto_trace_v1_ConstantSampler *) _upb_Message_New(
                &opencensus_proto_trace_v1_ConstantSampler_msginit, arena);
        if (!sub) return NULL;
        opencensus_proto_trace_v1_TraceConfig_set_constant_sampler(msg, sub);
    }
    return sub;
}

UPB_INLINE void opencensus_proto_trace_v1_TraceConfig_set_rate_limiting_sampler(
        opencensus_proto_trace_v1_TraceConfig * msg,
        opencensus_proto_trace_v1_RateLimitingSampler * value) {
    UPB_WRITE_ONEOF(msg, opencensus_proto_trace_v1_RateLimitingSampler * , UPB_SIZE(4, 8), value,
                    UPB_SIZE(0, 0), 3);
}

UPB_INLINE struct opencensus_proto_trace_v1_RateLimitingSampler *
opencensus_proto_trace_v1_TraceConfig_mutable_rate_limiting_sampler(
        opencensus_proto_trace_v1_TraceConfig * msg, upb_Arena * arena) {
    struct opencensus_proto_trace_v1_RateLimitingSampler *sub = (struct opencensus_proto_trace_v1_RateLimitingSampler *) opencensus_proto_trace_v1_TraceConfig_rate_limiting_sampler(
            msg);
    if (sub == NULL) {
        sub = (struct opencensus_proto_trace_v1_RateLimitingSampler *) _upb_Message_New(
                &opencensus_proto_trace_v1_RateLimitingSampler_msginit, arena);
        if (!sub) return NULL;
        opencensus_proto_trace_v1_TraceConfig_set_rate_limiting_sampler(msg, sub);
    }
    return sub;
}

UPB_INLINE void opencensus_proto_trace_v1_TraceConfig_set_max_number_of_attributes(
        opencensus_proto_trace_v1_TraceConfig * msg, int64_t
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(8, 16), int64_t
) =
value;
}
UPB_INLINE void opencensus_proto_trace_v1_TraceConfig_set_max_number_of_annotations(
        opencensus_proto_trace_v1_TraceConfig * msg, int64_t
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(16, 24), int64_t
) =
value;
}
UPB_INLINE void opencensus_proto_trace_v1_TraceConfig_set_max_number_of_message_events(
        opencensus_proto_trace_v1_TraceConfig * msg, int64_t
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(24, 32), int64_t
) =
value;
}
UPB_INLINE void opencensus_proto_trace_v1_TraceConfig_set_max_number_of_links(
        opencensus_proto_trace_v1_TraceConfig * msg, int64_t
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(32, 40), int64_t
) =
value;
}

/* opencensus.proto.trace.v1.ProbabilitySampler */

UPB_INLINE opencensus_proto_trace_v1_ProbabilitySampler
*
opencensus_proto_trace_v1_ProbabilitySampler_new(upb_Arena
* arena) {
return (opencensus_proto_trace_v1_ProbabilitySampler*)
_upb_Message_New(&opencensus_proto_trace_v1_ProbabilitySampler_msginit, arena
);
}
UPB_INLINE opencensus_proto_trace_v1_ProbabilitySampler
*

opencensus_proto_trace_v1_ProbabilitySampler_parse(const char *buf, size_t size, upb_Arena *arena) {
    opencensus_proto_trace_v1_ProbabilitySampler *
    ret = opencensus_proto_trace_v1_ProbabilitySampler_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &opencensus_proto_trace_v1_ProbabilitySampler_msginit, NULL, 0,
                   arena) != kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE opencensus_proto_trace_v1_ProbabilitySampler
*

opencensus_proto_trace_v1_ProbabilitySampler_parse_ex(const char *buf, size_t size,
                                                      const upb_ExtensionRegistry *extreg,
                                                      int options, upb_Arena *arena) {
    opencensus_proto_trace_v1_ProbabilitySampler *
    ret = opencensus_proto_trace_v1_ProbabilitySampler_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &opencensus_proto_trace_v1_ProbabilitySampler_msginit, extreg,
                   options, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *opencensus_proto_trace_v1_ProbabilitySampler_serialize(
        const opencensus_proto_trace_v1_ProbabilitySampler *msg, upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &opencensus_proto_trace_v1_ProbabilitySampler_msginit, 0, arena, &ptr,
                      len);
    return ptr;
}

UPB_INLINE char *opencensus_proto_trace_v1_ProbabilitySampler_serialize_ex(
        const opencensus_proto_trace_v1_ProbabilitySampler *msg, int options,
        upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &opencensus_proto_trace_v1_ProbabilitySampler_msginit, options, arena,
                      &ptr, len);
    return ptr;
}

UPB_INLINE void opencensus_proto_trace_v1_ProbabilitySampler_clear_samplingProbability(
        const opencensus_proto_trace_v1_ProbabilitySampler *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(0, 0), double) = 0;
}

UPB_INLINE double opencensus_proto_trace_v1_ProbabilitySampler_samplingProbability(
        const opencensus_proto_trace_v1_ProbabilitySampler *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(0, 0), double);
}

UPB_INLINE void opencensus_proto_trace_v1_ProbabilitySampler_set_samplingProbability(
        opencensus_proto_trace_v1_ProbabilitySampler * msg, double
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(0, 0),
double) =
value;
}

/* opencensus.proto.trace.v1.ConstantSampler */

UPB_INLINE opencensus_proto_trace_v1_ConstantSampler
*
opencensus_proto_trace_v1_ConstantSampler_new(upb_Arena
* arena) {
return (opencensus_proto_trace_v1_ConstantSampler*)
_upb_Message_New(&opencensus_proto_trace_v1_ConstantSampler_msginit, arena
);
}
UPB_INLINE opencensus_proto_trace_v1_ConstantSampler
*

opencensus_proto_trace_v1_ConstantSampler_parse(const char *buf, size_t size, upb_Arena *arena) {
    opencensus_proto_trace_v1_ConstantSampler * ret = opencensus_proto_trace_v1_ConstantSampler_new(
            arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &opencensus_proto_trace_v1_ConstantSampler_msginit, NULL, 0,
                   arena) != kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE opencensus_proto_trace_v1_ConstantSampler
*

opencensus_proto_trace_v1_ConstantSampler_parse_ex(const char *buf, size_t size,
                                                   const upb_ExtensionRegistry *extreg,
                                                   int options, upb_Arena *arena) {
    opencensus_proto_trace_v1_ConstantSampler * ret = opencensus_proto_trace_v1_ConstantSampler_new(
            arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &opencensus_proto_trace_v1_ConstantSampler_msginit, extreg,
                   options, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *opencensus_proto_trace_v1_ConstantSampler_serialize(
        const opencensus_proto_trace_v1_ConstantSampler *msg, upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &opencensus_proto_trace_v1_ConstantSampler_msginit, 0, arena, &ptr, len);
    return ptr;
}

UPB_INLINE char *opencensus_proto_trace_v1_ConstantSampler_serialize_ex(
        const opencensus_proto_trace_v1_ConstantSampler *msg, int options,
        upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &opencensus_proto_trace_v1_ConstantSampler_msginit, options, arena, &ptr,
                      len);
    return ptr;
}

UPB_INLINE void opencensus_proto_trace_v1_ConstantSampler_clear_decision(
        const opencensus_proto_trace_v1_ConstantSampler *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(0, 0), int32_t) = 0;
}

UPB_INLINE int32_t

opencensus_proto_trace_v1_ConstantSampler_decision(
        const opencensus_proto_trace_v1_ConstantSampler *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(0, 0), int32_t);
}

UPB_INLINE void opencensus_proto_trace_v1_ConstantSampler_set_decision(
        opencensus_proto_trace_v1_ConstantSampler * msg, int32_t
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(0, 0), int32_t
) =
value;
}

/* opencensus.proto.trace.v1.RateLimitingSampler */

UPB_INLINE opencensus_proto_trace_v1_RateLimitingSampler
*
opencensus_proto_trace_v1_RateLimitingSampler_new(upb_Arena
* arena) {
return (opencensus_proto_trace_v1_RateLimitingSampler*)
_upb_Message_New(&opencensus_proto_trace_v1_RateLimitingSampler_msginit, arena
);
}
UPB_INLINE opencensus_proto_trace_v1_RateLimitingSampler
*

opencensus_proto_trace_v1_RateLimitingSampler_parse(const char *buf, size_t size,
                                                    upb_Arena *arena) {
    opencensus_proto_trace_v1_RateLimitingSampler *
    ret = opencensus_proto_trace_v1_RateLimitingSampler_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &opencensus_proto_trace_v1_RateLimitingSampler_msginit, NULL, 0,
                   arena) != kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE opencensus_proto_trace_v1_RateLimitingSampler
*

opencensus_proto_trace_v1_RateLimitingSampler_parse_ex(const char *buf, size_t size,
                                                       const upb_ExtensionRegistry *extreg,
                                                       int options, upb_Arena *arena) {
    opencensus_proto_trace_v1_RateLimitingSampler *
    ret = opencensus_proto_trace_v1_RateLimitingSampler_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &opencensus_proto_trace_v1_RateLimitingSampler_msginit, extreg,
                   options, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *opencensus_proto_trace_v1_RateLimitingSampler_serialize(
        const opencensus_proto_trace_v1_RateLimitingSampler *msg, upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &opencensus_proto_trace_v1_RateLimitingSampler_msginit, 0, arena, &ptr,
                      len);
    return ptr;
}

UPB_INLINE char *opencensus_proto_trace_v1_RateLimitingSampler_serialize_ex(
        const opencensus_proto_trace_v1_RateLimitingSampler *msg, int options,
        upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &opencensus_proto_trace_v1_RateLimitingSampler_msginit, options, arena,
                      &ptr, len);
    return ptr;
}

UPB_INLINE void opencensus_proto_trace_v1_RateLimitingSampler_clear_qps(
        const opencensus_proto_trace_v1_RateLimitingSampler *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(0, 0), int64_t) = 0;
}

UPB_INLINE int64_t

opencensus_proto_trace_v1_RateLimitingSampler_qps(
        const opencensus_proto_trace_v1_RateLimitingSampler *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(0, 0), int64_t);
}

UPB_INLINE void opencensus_proto_trace_v1_RateLimitingSampler_set_qps(
        opencensus_proto_trace_v1_RateLimitingSampler * msg, int64_t
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(0, 0), int64_t
) =
value;
}

extern const upb_MiniTable_File opencensus_proto_trace_v1_trace_config_proto_upb_file_layout;

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* OPENCENSUS_PROTO_TRACE_V1_TRACE_CONFIG_PROTO_UPB_H_ */
