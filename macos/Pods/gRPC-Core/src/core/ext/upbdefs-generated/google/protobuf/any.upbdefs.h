/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     google/protobuf/any.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef GOOGLE_PROTOBUF_ANY_PROTO_UPBDEFS_H_
#define GOOGLE_PROTOBUF_ANY_PROTO_UPBDEFS_H_

#include "upb/def.h"
#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

#include "upb/def.h"

#include "upb/port_def.inc"

extern _upb_DefPool_Init google_protobuf_any_proto_upbdefinit;

UPB_INLINE const upb_MessageDef
*
google_protobuf_Any_getmsgdef(upb_DefPool
*s) {
_upb_DefPool_LoadDefInit(s, &google_protobuf_any_proto_upbdefinit
);
return
upb_DefPool_FindMessageByName(s,
"google.protobuf.Any");
}

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* GOOGLE_PROTOBUF_ANY_PROTO_UPBDEFS_H_ */
