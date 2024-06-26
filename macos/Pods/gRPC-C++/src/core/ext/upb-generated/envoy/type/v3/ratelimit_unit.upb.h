/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/type/v3/ratelimit_unit.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef ENVOY_TYPE_V3_RATELIMIT_UNIT_PROTO_UPB_H_
#define ENVOY_TYPE_V3_RATELIMIT_UNIT_PROTO_UPB_H_

#include "upb/msg_internal.h"
#include "upb/decode.h"
#include "upb/decode_fast.h"
#include "upb/encode.h"

#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    envoy_type_v3_UNKNOWN = 0,
    envoy_type_v3_SECOND = 1,
    envoy_type_v3_MINUTE = 2,
    envoy_type_v3_HOUR = 3,
    envoy_type_v3_DAY = 4
} envoy_type_v3_RateLimitUnit;


extern const upb_MiniTable_File envoy_type_v3_ratelimit_unit_proto_upb_file_layout;

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* ENVOY_TYPE_V3_RATELIMIT_UNIT_PROTO_UPB_H_ */
