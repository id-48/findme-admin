/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/admin/v3/listeners.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef ENVOY_ADMIN_V3_LISTENERS_PROTO_UPB_H_
#define ENVOY_ADMIN_V3_LISTENERS_PROTO_UPB_H_

#include "upb/msg_internal.h"
#include "upb/decode.h"
#include "upb/decode_fast.h"
#include "upb/encode.h"

#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

struct envoy_admin_v3_Listeners;
struct envoy_admin_v3_ListenerStatus;
typedef struct envoy_admin_v3_Listeners envoy_admin_v3_Listeners;
typedef struct envoy_admin_v3_ListenerStatus envoy_admin_v3_ListenerStatus;
extern const upb_MiniTable envoy_admin_v3_Listeners_msginit;
extern const upb_MiniTable envoy_admin_v3_ListenerStatus_msginit;
struct envoy_config_core_v3_Address;
extern const upb_MiniTable envoy_config_core_v3_Address_msginit;


/* envoy.admin.v3.Listeners */

UPB_INLINE envoy_admin_v3_Listeners
*
envoy_admin_v3_Listeners_new(upb_Arena
* arena) {
return (envoy_admin_v3_Listeners*)
_upb_Message_New(&envoy_admin_v3_Listeners_msginit, arena
);
}
UPB_INLINE envoy_admin_v3_Listeners
*

envoy_admin_v3_Listeners_parse(const char *buf, size_t size, upb_Arena *arena) {
    envoy_admin_v3_Listeners * ret = envoy_admin_v3_Listeners_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_admin_v3_Listeners_msginit, NULL, 0, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE envoy_admin_v3_Listeners
*

envoy_admin_v3_Listeners_parse_ex(const char *buf, size_t size,
                                  const upb_ExtensionRegistry *extreg,
                                  int options, upb_Arena *arena) {
    envoy_admin_v3_Listeners * ret = envoy_admin_v3_Listeners_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_admin_v3_Listeners_msginit, extreg, options, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *
envoy_admin_v3_Listeners_serialize(const envoy_admin_v3_Listeners *msg, upb_Arena *arena,
                                   size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_admin_v3_Listeners_msginit, 0, arena, &ptr, len);
    return ptr;
}

UPB_INLINE char *
envoy_admin_v3_Listeners_serialize_ex(const envoy_admin_v3_Listeners *msg, int options,
                                      upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_admin_v3_Listeners_msginit, options, arena, &ptr, len);
    return ptr;
}

UPB_INLINE bool
envoy_admin_v3_Listeners_has_listener_statuses(const envoy_admin_v3_Listeners *msg) {
    return _upb_has_submsg_nohasbit(msg, UPB_SIZE(0, 0));
}

UPB_INLINE void
envoy_admin_v3_Listeners_clear_listener_statuses(const envoy_admin_v3_Listeners *msg) {
    _upb_array_detach(msg, UPB_SIZE(0, 0));
}

UPB_INLINE const envoy_admin_v3_ListenerStatus
* const*

envoy_admin_v3_Listeners_listener_statuses(const envoy_admin_v3_Listeners *msg, size_t *len) {
    return (const envoy_admin_v3_ListenerStatus *const *) _upb_array_accessor(msg, UPB_SIZE(0, 0),
                                                                              len);
}

UPB_INLINE envoy_admin_v3_ListenerStatus
**
envoy_admin_v3_Listeners_mutable_listener_statuses(envoy_admin_v3_Listeners
* msg,
size_t *len
) {
return (envoy_admin_v3_ListenerStatus**)
_upb_array_mutable_accessor(msg, UPB_SIZE(0, 0), len
);
}
UPB_INLINE envoy_admin_v3_ListenerStatus
**
envoy_admin_v3_Listeners_resize_listener_statuses(envoy_admin_v3_Listeners
* msg,
size_t len, upb_Arena
* arena) {
return (envoy_admin_v3_ListenerStatus**)
_upb_Array_Resize_accessor2(msg, UPB_SIZE(0, 0), len, UPB_SIZE(2, 3), arena
);
}

UPB_INLINE struct envoy_admin_v3_ListenerStatus *
envoy_admin_v3_Listeners_add_listener_statuses(envoy_admin_v3_Listeners * msg, upb_Arena * arena) {
    struct envoy_admin_v3_ListenerStatus *sub = (struct envoy_admin_v3_ListenerStatus *) _upb_Message_New(
            &envoy_admin_v3_ListenerStatus_msginit, arena);
    bool ok = _upb_Array_Append_accessor2(msg, UPB_SIZE(0, 0), UPB_SIZE(2, 3), &sub, arena);
    if (!ok) return NULL;
    return sub;
}

/* envoy.admin.v3.ListenerStatus */

UPB_INLINE envoy_admin_v3_ListenerStatus
*
envoy_admin_v3_ListenerStatus_new(upb_Arena
* arena) {
return (envoy_admin_v3_ListenerStatus*)
_upb_Message_New(&envoy_admin_v3_ListenerStatus_msginit, arena
);
}
UPB_INLINE envoy_admin_v3_ListenerStatus
*

envoy_admin_v3_ListenerStatus_parse(const char *buf, size_t size, upb_Arena *arena) {
    envoy_admin_v3_ListenerStatus * ret = envoy_admin_v3_ListenerStatus_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_admin_v3_ListenerStatus_msginit, NULL, 0, arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE envoy_admin_v3_ListenerStatus
*

envoy_admin_v3_ListenerStatus_parse_ex(const char *buf, size_t size,
                                       const upb_ExtensionRegistry *extreg,
                                       int options, upb_Arena *arena) {
    envoy_admin_v3_ListenerStatus * ret = envoy_admin_v3_ListenerStatus_new(arena);
    if (!ret) return NULL;
    if (upb_Decode(buf, size, ret, &envoy_admin_v3_ListenerStatus_msginit, extreg, options,
                   arena) !=
        kUpb_DecodeStatus_Ok) {
        return NULL;
    }
    return ret;
}

UPB_INLINE char *
envoy_admin_v3_ListenerStatus_serialize(const envoy_admin_v3_ListenerStatus *msg, upb_Arena *arena,
                                        size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_admin_v3_ListenerStatus_msginit, 0, arena, &ptr, len);
    return ptr;
}

UPB_INLINE char *
envoy_admin_v3_ListenerStatus_serialize_ex(const envoy_admin_v3_ListenerStatus *msg, int options,
                                           upb_Arena *arena, size_t *len) {
    char *ptr;
    (void) upb_Encode(msg, &envoy_admin_v3_ListenerStatus_msginit, options, arena, &ptr, len);
    return ptr;
}

UPB_INLINE void envoy_admin_v3_ListenerStatus_clear_name(const envoy_admin_v3_ListenerStatus *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(4, 8), upb_StringView) = upb_StringView_FromDataAndSize(NULL, 0);
}

UPB_INLINE upb_StringView

envoy_admin_v3_ListenerStatus_name(const envoy_admin_v3_ListenerStatus *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(4, 8), upb_StringView);
}

UPB_INLINE bool
envoy_admin_v3_ListenerStatus_has_local_address(const envoy_admin_v3_ListenerStatus *msg) {
    return _upb_hasbit(msg, 1);
}

UPB_INLINE void
envoy_admin_v3_ListenerStatus_clear_local_address(const envoy_admin_v3_ListenerStatus *msg) {
    *UPB_PTR_AT(msg, UPB_SIZE(12, 24),
    const upb_Message*) = NULL;
}

UPB_INLINE const struct envoy_config_core_v3_Address *
envoy_admin_v3_ListenerStatus_local_address(const envoy_admin_v3_ListenerStatus *msg) {
    return *UPB_PTR_AT(msg, UPB_SIZE(12, 24),
    const struct envoy_config_core_v3_Address*);
}

UPB_INLINE bool envoy_admin_v3_ListenerStatus_has_additional_local_addresses(
        const envoy_admin_v3_ListenerStatus *msg) {
    return _upb_has_submsg_nohasbit(msg, UPB_SIZE(16, 32));
}

UPB_INLINE void envoy_admin_v3_ListenerStatus_clear_additional_local_addresses(
        const envoy_admin_v3_ListenerStatus *msg) {
    _upb_array_detach(msg, UPB_SIZE(16, 32));
}

UPB_INLINE const struct envoy_config_core_v3_Address *const *
envoy_admin_v3_ListenerStatus_additional_local_addresses(const envoy_admin_v3_ListenerStatus *msg,
                                                         size_t *len) {
    return (const struct envoy_config_core_v3_Address *const *) _upb_array_accessor(msg,
                                                                                    UPB_SIZE(16,
                                                                                             32),
                                                                                    len);
}

UPB_INLINE void envoy_admin_v3_ListenerStatus_set_name(envoy_admin_v3_ListenerStatus * msg,
                                                       upb_StringView
value) {
*
UPB_PTR_AT(msg, UPB_SIZE(4, 8), upb_StringView
) =
value;
}
UPB_INLINE void envoy_admin_v3_ListenerStatus_set_local_address(envoy_admin_v3_ListenerStatus * msg,
struct envoy_config_core_v3_Address *value
) {
_upb_sethas(msg,
1);
*
UPB_PTR_AT(msg, UPB_SIZE(12, 24),
struct envoy_config_core_v3_Address*) =
value;
}

UPB_INLINE struct envoy_config_core_v3_Address *
envoy_admin_v3_ListenerStatus_mutable_local_address(envoy_admin_v3_ListenerStatus * msg,
                                                    upb_Arena * arena) {
    struct envoy_config_core_v3_Address *sub = (struct envoy_config_core_v3_Address *) envoy_admin_v3_ListenerStatus_local_address(
            msg);
    if (sub == NULL) {
        sub = (struct envoy_config_core_v3_Address *) _upb_Message_New(
                &envoy_config_core_v3_Address_msginit, arena);
        if (!sub) return NULL;
        envoy_admin_v3_ListenerStatus_set_local_address(msg, sub);
    }
    return sub;
}

UPB_INLINE struct envoy_config_core_v3_Address **
envoy_admin_v3_ListenerStatus_mutable_additional_local_addresses(
        envoy_admin_v3_ListenerStatus * msg, size_t * len) {
    return (struct envoy_config_core_v3_Address **) _upb_array_mutable_accessor(msg,
                                                                                UPB_SIZE(16, 32),
                                                                                len);
}

UPB_INLINE struct envoy_config_core_v3_Address **envoy_admin_v3_ListenerStatus_resize_additional_local_addresses(
        envoy_admin_v3_ListenerStatus * msg, size_t
len,
upb_Arena *arena
) {
return (struct envoy_config_core_v3_Address**)
_upb_Array_Resize_accessor2(msg, UPB_SIZE(16, 32), len, UPB_SIZE(2, 3), arena
);
}

UPB_INLINE struct envoy_config_core_v3_Address *
envoy_admin_v3_ListenerStatus_add_additional_local_addresses(envoy_admin_v3_ListenerStatus * msg,
                                                             upb_Arena * arena) {
    struct envoy_config_core_v3_Address *sub = (struct envoy_config_core_v3_Address *) _upb_Message_New(
            &envoy_config_core_v3_Address_msginit, arena);
    bool ok = _upb_Array_Append_accessor2(msg, UPB_SIZE(16, 32), UPB_SIZE(2, 3), &sub, arena);
    if (!ok) return NULL;
    return sub;
}

extern const upb_MiniTable_File envoy_admin_v3_listeners_proto_upb_file_layout;

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* ENVOY_ADMIN_V3_LISTENERS_PROTO_UPB_H_ */
