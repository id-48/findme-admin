/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/config/listener/v3/udp_listener_config.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef ENVOY_CONFIG_LISTENER_V3_UDP_LISTENER_CONFIG_PROTO_UPBDEFS_H_
#define ENVOY_CONFIG_LISTENER_V3_UDP_LISTENER_CONFIG_PROTO_UPBDEFS_H_

#include "upb/def.h"
#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

#include "upb/def.h"

#include "upb/port_def.inc"

extern _upb_DefPool_Init envoy_config_listener_v3_udp_listener_config_proto_upbdefinit;

UPB_INLINE const upb_MessageDef
*
envoy_config_listener_v3_UdpListenerConfig_getmsgdef(upb_DefPool
*s) {
_upb_DefPool_LoadDefInit(s, &envoy_config_listener_v3_udp_listener_config_proto_upbdefinit
);
return
upb_DefPool_FindMessageByName(s,
"envoy.config.listener.v3.UdpListenerConfig");
}

UPB_INLINE const upb_MessageDef
*
envoy_config_listener_v3_ActiveRawUdpListenerConfig_getmsgdef(upb_DefPool
*s) {
_upb_DefPool_LoadDefInit(s, &envoy_config_listener_v3_udp_listener_config_proto_upbdefinit
);
return
upb_DefPool_FindMessageByName(s,
"envoy.config.listener.v3.ActiveRawUdpListenerConfig");
}

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* ENVOY_CONFIG_LISTENER_V3_UDP_LISTENER_CONFIG_PROTO_UPBDEFS_H_ */
