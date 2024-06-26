/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     google/protobuf/duration.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef GOOGLE_PROTOBUF_DURATION_PROTO_UPB_H_
#define GOOGLE_PROTOBUF_DURATION_PROTO_UPB_H_

#include "upb/msg_internal.h"
#include "upb/decode.h"
#include "upb/decode_fast.h"
#include "upb/encode.h"

#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

struct google_protobuf_Duration;
typedef struct google_protobuf_Duration google_protobuf_Duration;
extern const upb_MiniTable google_protobuf_Duration_msginit;


/* google.protobuf.Duration */

UPB_INLINE google_protobuf_Duration
*
google_protobuf_Duration_new(upb_Arena
* arena) {
return (google_protobuf_Duration*)
_upb_Message_New(&google_protobuf_Duration_msginit, arena
);
}
UPB_INLINE google_protobuf_Duration
*

google_protobuf_Duration_parse(const char *buf, size_t size, upb_Arena *arena) {
    google_protobuf_Duration * ret = google_protobuf_Duration_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &google_protobuf_Duration_msginit, NULL, 0, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE google_protobuf_Duration
*

google_protobuf_Duration_parse_ex(const char *buf, size_t size,
                                  const upb_ExtensionRegistry *extreg,
                                  int options, upb_Arena *arena) {
    google_protobuf_Duration * ret = google_protobuf_Duration_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &google_protobuf_Duration_msginit, extreg, options, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *
google_protobuf_Duration_serialize(const google_protobuf_Duration *msg, upb_Arena *arena,
                                   size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &google_protobuf_Duration_msginit, 0, arena, &ptr, len);
    return ptr;
}

UPB_INLINE char *
google_protobuf_Duration_serialize_ex(const google_protobuf_Duration *msg, int options,
                                      upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &google_protobuf_Duration_msginit, options, arena, &ptr, len);
    return ptr;
}

UPB_INLINE void google_protobuf_Duration_clear_seconds(const google_protobuf_Duration *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(8, 8), int64_t) = 0;
}

UPB_INLINE int64_t

google_protobuf_Duration_seconds(const google_protobuf_Duration *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(8, 8), int64_t);
}

UPB_INLINE void google_protobuf_Duration_clear_nanos(const google_protobuf_Duration *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(0, 0), int32_t) = 0;
}

UPB_INLINE int32_t

google_protobuf_Duration_nanos(const google_protobuf_Duration *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(0, 0), int32_t);
}

UPB_INLINE void google_protobuf_Duration_set_seconds(google_protobuf_Duration * msg, int64_t
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(8, 8), int64_t
) =
value;
}
UPB_INLINE void google_protobuf_Duration_set_nanos(google_protobuf_Duration * msg, int32_t
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(0, 0), int32_t
) =
value;
}

extern const upb_MiniTable_File google_protobuf_duration_proto_upb_file_layout;

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* GOOGLE_PROTOBUF_DURATION_PROTO_UPB_H_ */
