/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/admin/v3/listeners.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef ENVOY_ADMIN_V3_LISTENERS_PROTO_UPBDEFS_H_
#define ENVOY_ADMIN_V3_LISTENERS_PROTO_UPBDEFS_H_

#include "upb/def.h"
#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

#include "upb/def.h"

#include "upb/port_def.inc"

extern _upb_DefPool_Init envoy_admin_v3_listeners_proto_upbdefinit;

UPB_INLINE const upb_MessageDef
*
envoy_admin_v3_Listeners_getmsgdef(upb_DefPool
*s) {
_upb_DefPool_LoadDefInit(s, &envoy_admin_v3_listeners_proto_upbdefinit
);
return
upb_DefPool_FindMessageByName(s,
"envoy.admin.v3.Listeners");
}

UPB_INLINE const upb_MessageDef
*
envoy_admin_v3_ListenerStatus_getmsgdef(upb_DefPool
*s) {
_upb_DefPool_LoadDefInit(s, &envoy_admin_v3_listeners_proto_upbdefinit
);
return
upb_DefPool_FindMessageByName(s,
"envoy.admin.v3.ListenerStatus");
}

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* ENVOY_ADMIN_V3_LISTENERS_PROTO_UPBDEFS_H_ */
