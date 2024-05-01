/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/config/trace/v3/http_tracer.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/msg_internal.h"
#include "envoy/config/trace/v3/http_tracer.upb.h"
#include "google/protobuf/any.upb.h"
#include "udpa/annotations/status.upb.h"
#include "udpa/annotations/versioning.upb.h"
#include "validate/validate.upb.h"

#include "upb/port_def.inc"

static const upb_MiniTable_Sub envoy_config_trace_v3_Tracing_submsgs[1] = {
        {.submsg = &envoy_config_trace_v3_Tracing_Http_msginit},
};

static const upb_MiniTable_Field envoy_config_trace_v3_Tracing__fields[1] = {
        {1, UPB_SIZE(4, 8), UPB_SIZE(1, 1), 0, 11,
         kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_trace_v3_Tracing_msginit = {
        &envoy_config_trace_v3_Tracing_submsgs[0],
        &envoy_config_trace_v3_Tracing__fields[0],
        UPB_SIZE(8, 16), 1, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_trace_v3_Tracing_Http_submsgs[1] = {
        {.submsg = &google_protobuf_Any_msginit},
};

static const upb_MiniTable_Field envoy_config_trace_v3_Tracing_Http__fields[2] = {
        {1, UPB_SIZE(4, 8),   UPB_SIZE(0, 0),   kUpb_NoSub, 9,
                                                                kUpb_FieldMode_Scalar |
                                                                (kUpb_FieldRep_StringView
                                                                        << kUpb_FieldRep_Shift)},
        {3, UPB_SIZE(12, 24), UPB_SIZE(-1, -1), 0,          11, kUpb_FieldMode_Scalar |
                                                                (kUpb_FieldRep_Pointer
                                                                        << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_trace_v3_Tracing_Http_msginit = {
        &envoy_config_trace_v3_Tracing_Http_submsgs[0],
        &envoy_config_trace_v3_Tracing_Http__fields[0],
        UPB_SIZE(16, 32), 2, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable *messages_layout[2] = {
        &envoy_config_trace_v3_Tracing_msginit,
        &envoy_config_trace_v3_Tracing_Http_msginit,
};

const upb_MiniTable_File envoy_config_trace_v3_http_tracer_proto_upb_file_layout = {
        messages_layout,
        NULL,
        NULL,
        2,
        0,
        0,
};

#include "upb/port_undef.inc"

