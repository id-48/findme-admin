/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/admin/v3/memory.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef ENVOY_ADMIN_V3_MEMORY_PROTO_UPB_H_
#define ENVOY_ADMIN_V3_MEMORY_PROTO_UPB_H_

#include "upb/msg_internal.h"
#include "upb/decode.h"
#include "upb/decode_fast.h"
#include "upb/encode.h"

#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

struct envoy_admin_v3_Memory;
typedef struct envoy_admin_v3_Memory envoy_admin_v3_Memory;
extern const upb_MiniTable envoy_admin_v3_Memory_msginit;


/* envoy.admin.v3.Memory */

UPB_INLINE envoy_admin_v3_Memory
*
envoy_admin_v3_Memory_new(upb_Arena
* arena) {
return (envoy_admin_v3_Memory*)
_upb_Message_New(&envoy_admin_v3_Memory_msginit, arena
);
}
UPB_INLINE envoy_admin_v3_Memory
*

envoy_admin_v3_Memory_parse(const char *buf, size_t size, upb_Arena *arena) {
    envoy_admin_v3_Memory * ret = envoy_admin_v3_Memory_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_admin_v3_Memory_msginit, NULL, 0, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE envoy_admin_v3_Memory
*

envoy_admin_v3_Memory_parse_ex(const char *buf, size_t size,
                               const upb_ExtensionRegistry *extreg,
                               int options, upb_Arena *arena) {
    envoy_admin_v3_Memory * ret = envoy_admin_v3_Memory_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_admin_v3_Memory_msginit, extreg, options, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *
envoy_admin_v3_Memory_serialize(const envoy_admin_v3_Memory *msg, upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_admin_v3_Memory_msginit, 0, arena, &ptr, len);
    return ptr;
}

UPB_INLINE char *envoy_admin_v3_Memory_serialize_ex(const envoy_admin_v3_Memory *msg, int options,
                                                    upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_admin_v3_Memory_msginit, options, arena, &ptr, len);
    return ptr;
}

UPB_INLINE void envoy_admin_v3_Memory_clear_allocated(const envoy_admin_v3_Memory *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(0, 0), uint64_t) = 0;
}

UPB_INLINE uint64_t

envoy_admin_v3_Memory_allocated(const envoy_admin_v3_Memory *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(0, 0), uint64_t);
}

UPB_INLINE void envoy_admin_v3_Memory_clear_heap_size(const envoy_admin_v3_Memory *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(8, 8), uint64_t) = 0;
}

UPB_INLINE uint64_t

envoy_admin_v3_Memory_heap_size(const envoy_admin_v3_Memory *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(8, 8), uint64_t);
}

UPB_INLINE void envoy_admin_v3_Memory_clear_pageheap_unmapped(const envoy_admin_v3_Memory *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(16, 16), uint64_t) = 0;
}

UPB_INLINE uint64_t

envoy_admin_v3_Memory_pageheap_unmapped(const envoy_admin_v3_Memory *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(16, 16), uint64_t);
}

UPB_INLINE void envoy_admin_v3_Memory_clear_pageheap_free(const envoy_admin_v3_Memory *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(24, 24), uint64_t) = 0;
}

UPB_INLINE uint64_t

envoy_admin_v3_Memory_pageheap_free(const envoy_admin_v3_Memory *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(24, 24), uint64_t);
}

UPB_INLINE void envoy_admin_v3_Memory_clear_total_thread_cache(const envoy_admin_v3_Memory *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(32, 32), uint64_t) = 0;
}

UPB_INLINE uint64_t

envoy_admin_v3_Memory_total_thread_cache(const envoy_admin_v3_Memory *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(32, 32), uint64_t);
}

UPB_INLINE void envoy_admin_v3_Memory_clear_total_physical_bytes(const envoy_admin_v3_Memory *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(40, 40), uint64_t) = 0;
}

UPB_INLINE uint64_t

envoy_admin_v3_Memory_total_physical_bytes(const envoy_admin_v3_Memory *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(40, 40), uint64_t);
}

UPB_INLINE void envoy_admin_v3_Memory_set_allocated(envoy_admin_v3_Memory * msg, uint64_t
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(0, 0), uint64_t
) =
value;
}
UPB_INLINE void envoy_admin_v3_Memory_set_heap_size(envoy_admin_v3_Memory * msg, uint64_t
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(8, 8), uint64_t
) =
value;
}
UPB_INLINE void envoy_admin_v3_Memory_set_pageheap_unmapped(envoy_admin_v3_Memory * msg, uint64_t
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(16, 16), uint64_t
) =
value;
}
UPB_INLINE void envoy_admin_v3_Memory_set_pageheap_free(envoy_admin_v3_Memory * msg, uint64_t
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(24, 24), uint64_t
) =
value;
}
UPB_INLINE void envoy_admin_v3_Memory_set_total_thread_cache(envoy_admin_v3_Memory * msg, uint64_t
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(32, 32), uint64_t
) =
value;
}
UPB_INLINE void envoy_admin_v3_Memory_set_total_physical_bytes(envoy_admin_v3_Memory * msg, uint64_t
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(40, 40), uint64_t
) =
value;
}

extern const upb_MiniTable_File envoy_admin_v3_memory_proto_upb_file_layout;

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* ENVOY_ADMIN_V3_MEMORY_PROTO_UPB_H_ */
