/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/type/matcher/v3/path.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/msg_internal.h"
#include "envoy/type/matcher/v3/path.upb.h"
#include "envoy/type/matcher/v3/string.upb.h"
#include "udpa/annotations/status.upb.h"
#include "udpa/annotations/versioning.upb.h"
#include "validate/validate.upb.h"

#include "upb/port_def.inc"

static const upb_MiniTable_Sub envoy_type_matcher_v3_PathMatcher_submsgs[1] = {
        {.submsg = &envoy_type_matcher_v3_StringMatcher_msginit},
};

static const upb_MiniTable_Field envoy_type_matcher_v3_PathMatcher__fields[1] = {
        {1, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 0, 11,
         kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_type_matcher_v3_PathMatcher_msginit = {
        &envoy_type_matcher_v3_PathMatcher_submsgs[0],
        &envoy_type_matcher_v3_PathMatcher__fields[0],
        UPB_SIZE(8, 16), 1, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable *messages_layout[1] = {
        &envoy_type_matcher_v3_PathMatcher_msginit,
};

const upb_MiniTable_File envoy_type_matcher_v3_path_proto_upb_file_layout = {
        messages_layout,
        NULL,
        NULL,
        1,
        0,
        0,
};

#include "upb/port_undef.inc"

