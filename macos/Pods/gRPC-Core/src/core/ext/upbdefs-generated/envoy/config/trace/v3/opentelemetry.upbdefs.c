/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/config/trace/v3/opentelemetry.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include "upb/def.h"
#include "envoy/config/trace/v3/opentelemetry.upbdefs.h"
#include "envoy/config/trace/v3/opentelemetry.upb.h"

extern _upb_DefPool_Init envoy_config_core_v3_grpc_service_proto_upbdefinit;
extern _upb_DefPool_Init udpa_annotations_status_proto_upbdefinit;
extern _upb_DefPool_Init validate_validate_proto_upbdefinit;
static const char descriptor[414] = {'\n', ')', 'e', 'n', 'v', 'o', 'y', '/', 'c', 'o', 'n', 'f',
                                     'i', 'g', '/', 't', 'r', 'a', 'c', 'e', '/', 'v', '3', '/',
                                     'o',
                                     'p', 'e', 'n', 't', 'e', 'l', 'e', 'm', 'e', 't', 'r', 'y',
                                     '.', 'p', 'r', 'o', 't', 'o', '\022', '\025', 'e', 'n', 'v',
                                     'o', 'y',
                                     '.', 'c', 'o', 'n', 'f', 'i', 'g', '.', 't', 'r', 'a', 'c',
                                     'e', '.', 'v', '3', '\032', '\'', 'e', 'n', 'v', 'o', 'y', '/',
                                     'c',
                                     'o', 'n', 'f', 'i', 'g', '/', 'c', 'o', 'r', 'e', '/', 'v',
                                     '3', '/', 'g', 'r', 'p', 'c', '_', 's', 'e', 'r', 'v', 'i',
                                     'c',
                                     'e', '.', 'p', 'r', 'o', 't', 'o', '\032', '\035', 'u', 'd',
                                     'p', 'a', '/', 'a', 'n', 'n', 'o', 't', 'a', 't', 'i', 'o',
                                     'n', 's',
                                     '/', 's', 't', 'a', 't', 'u', 's', '.', 'p', 'r', 'o', 't',
                                     'o', '\032', '\027', 'v', 'a', 'l', 'i', 'd', 'a', 't', 'e',
                                     '/', 'v',
                                     'a', 'l', 'i', 'd', 'a', 't', 'e', '.', 'p', 'r', 'o', 't',
                                     'o', '\"', 'e', '\n', '\023', 'O', 'p', 'e', 'n', 'T', 'e',
                                     'l', 'e',
                                     'm', 'e', 't', 'r', 'y', 'C', 'o', 'n', 'f', 'i', 'g', '\022',
                                     'N', '\n', '\014', 'g', 'r', 'p', 'c', '_', 's', 'e', 'r', 'v',
                                     'i',
                                     'c', 'e', '\030', '\001', ' ', '\001', '(', '\013', '2', '!',
                                     '.', 'e', 'n', 'v', 'o', 'y', '.', 'c', 'o', 'n', 'f', 'i',
                                     'g', '.', 'c',
                                     'o', 'r', 'e', '.', 'v', '3', '.', 'G', 'r', 'p', 'c', 'S',
                                     'e', 'r', 'v', 'i', 'c', 'e', 'B', '\010', '\372', 'B', '\005',
                                     '\212', '\001',
                                     '\002', '\020', '\001', 'R', '\013', 'g', 'r', 'p', 'c', 'S',
                                     'e', 'r', 'v', 'i', 'c', 'e', 'B', '\211', '\001', '\n', '#',
                                     'i', 'o', '.', 'e',
                                     'n', 'v', 'o', 'y', 'p', 'r', 'o', 'x', 'y', '.', 'e', 'n',
                                     'v', 'o', 'y', '.', 'c', 'o', 'n', 'f', 'i', 'g', '.', 't',
                                     'r',
                                     'a', 'c', 'e', '.', 'v', '3', 'B', '\022', 'O', 'p', 'e', 'n',
                                     't', 'e', 'l', 'e', 'm', 'e', 't', 'r', 'y', 'P', 'r', 'o',
                                     't',
                                     'o', 'P', '\001', 'Z', 'D', 'g', 'i', 't', 'h', 'u', 'b', '.',
                                     'c', 'o', 'm', '/', 'e', 'n', 'v', 'o', 'y', 'p', 'r', 'o',
                                     'x',
                                     'y', '/', 'g', 'o', '-', 'c', 'o', 'n', 't', 'r', 'o', 'l',
                                     '-', 'p', 'l', 'a', 'n', 'e', '/', 'e', 'n', 'v', 'o', 'y',
                                     '/',
                                     'c', 'o', 'n', 'f', 'i', 'g', '/', 't', 'r', 'a', 'c', 'e',
                                     '/', 'v', '3', ';', 't', 'r', 'a', 'c', 'e', 'v', '3', '\272',
                                     '\200',
                                     '\310', '\321', '\006', '\002', '\020', '\002', 'b', '\006',
                                     'p', 'r', 'o', 't', 'o', '3',
};

static _upb_DefPool_Init *deps[4] = {
        &envoy_config_core_v3_grpc_service_proto_upbdefinit,
        &udpa_annotations_status_proto_upbdefinit,
        &validate_validate_proto_upbdefinit,
        NULL
};

_upb_DefPool_Init envoy_config_trace_v3_opentelemetry_proto_upbdefinit = {
        deps,
        &envoy_config_trace_v3_opentelemetry_proto_upb_file_layout,
        "envoy/config/trace/v3/opentelemetry.proto",
        UPB_STRINGVIEW_INIT(descriptor, 414)
};