/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/extensions/filters/http/rbac/v3/rbac.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include "upb/def.h"
#include "envoy/extensions/filters/http/rbac/v3/rbac.upbdefs.h"
#include "envoy/extensions/filters/http/rbac/v3/rbac.upb.h"

extern _upb_DefPool_Init envoy_config_rbac_v3_rbac_proto_upbdefinit;
extern _upb_DefPool_Init xds_annotations_v3_status_proto_upbdefinit;
extern _upb_DefPool_Init xds_type_matcher_v3_matcher_proto_upbdefinit;
extern _upb_DefPool_Init udpa_annotations_migrate_proto_upbdefinit;
extern _upb_DefPool_Init udpa_annotations_status_proto_upbdefinit;
extern _upb_DefPool_Init udpa_annotations_versioning_proto_upbdefinit;
static const char descriptor[1080] = {'\n', '0', 'e', 'n', 'v', 'o', 'y', '/', 'e', 'x', 't', 'e',
                                      'n', 's', 'i', 'o', 'n', 's', '/', 'f', 'i', 'l', 't', 'e',
                                      'r',
                                      's', '/', 'h', 't', 't', 'p', '/', 'r', 'b', 'a', 'c', '/',
                                      'v', '3', '/', 'r', 'b', 'a', 'c', '.', 'p', 'r', 'o', 't',
                                      'o',
                                      '\022', '%', 'e', 'n', 'v', 'o', 'y', '.', 'e', 'x', 't', 'e',
                                      'n', 's', 'i', 'o', 'n', 's', '.', 'f', 'i', 'l', 't', 'e',
                                      'r',
                                      's', '.', 'h', 't', 't', 'p', '.', 'r', 'b', 'a', 'c', '.',
                                      'v', '3', '\032', '\037', 'e', 'n', 'v', 'o', 'y', '/', 'c',
                                      'o', 'n',
                                      'f', 'i', 'g', '/', 'r', 'b', 'a', 'c', '/', 'v', '3', '/',
                                      'r', 'b', 'a', 'c', '.', 'p', 'r', 'o', 't', 'o', '\032',
                                      '\037', 'x',
                                      'd', 's', '/', 'a', 'n', 'n', 'o', 't', 'a', 't', 'i', 'o',
                                      'n', 's', '/', 'v', '3', '/', 's', 't', 'a', 't', 'u', 's',
                                      '.',
                                      'p', 'r', 'o', 't', 'o', '\032', '!', 'x', 'd', 's', '/', 't',
                                      'y', 'p', 'e', '/', 'm', 'a', 't', 'c', 'h', 'e', 'r', '/',
                                      'v',
                                      '3', '/', 'm', 'a', 't', 'c', 'h', 'e', 'r', '.', 'p', 'r',
                                      'o', 't', 'o', '\032', '\036', 'u', 'd', 'p', 'a', '/', 'a',
                                      'n', 'n',
                                      'o', 't', 'a', 't', 'i', 'o', 'n', 's', '/', 'm', 'i', 'g',
                                      'r', 'a', 't', 'e', '.', 'p', 'r', 'o', 't', 'o', '\032',
                                      '\035', 'u',
                                      'd', 'p', 'a', '/', 'a', 'n', 'n', 'o', 't', 'a', 't', 'i',
                                      'o', 'n', 's', '/', 's', 't', 'a', 't', 'u', 's', '.', 'p',
                                      'r',
                                      'o', 't', 'o', '\032', '!', 'u', 'd', 'p', 'a', '/', 'a', 'n',
                                      'n', 'o', 't', 'a', 't', 'i', 'o', 'n', 's', '/', 'v', 'e',
                                      'r',
                                      's', 'i', 'o', 'n', 'i', 'n', 'g', '.', 'p', 'r', 'o', 't',
                                      'o', '\"', '\335', '\003', '\n', '\004', 'R', 'B', 'A', 'C',
                                      '\022', 'I', '\n',
                                      '\005', 'r', 'u', 'l', 'e', 's', '\030', '\001', ' ', '\001',
                                      '(', '\013', '2', '\032', '.', 'e', 'n', 'v', 'o', 'y', '.',
                                      'c', 'o', 'n', 'f',
                                      'i', 'g', '.', 'r', 'b', 'a', 'c', '.', 'v', '3', '.', 'R',
                                      'B', 'A', 'C', 'B', '\027', '\362', '\230', '\376', '\217',
                                      '\005', '\021', '\022', '\017',
                                      'r', 'u', 'l', 'e', 's', '_', 's', 'p', 'e', 'c', 'i', 'f',
                                      'i', 'e', 'r', 'R', '\005', 'r', 'u', 'l', 'e', 's', '\022',
                                      'W', '\n',
                                      '\007', 'm', 'a', 't', 'c', 'h', 'e', 'r', '\030', '\004',
                                      ' ', '\001', '(', '\013', '2', '\034', '.', 'x', 'd', 's',
                                      '.', 't', 'y', 'p', 'e',
                                      '.', 'm', 'a', 't', 'c', 'h', 'e', 'r', '.', 'v', '3', '.',
                                      'M', 'a', 't', 'c', 'h', 'e', 'r', 'B', '\037', '\362',
                                      '\230', '\376', '\217',
                                      '\005', '\021', '\022', '\017', 'r', 'u', 'l', 'e', 's', '_',
                                      's', 'p', 'e', 'c', 'i', 'f', 'i', 'e', 'r', '\322', '\306',
                                      '\244', '\341', '\006', '\002',
                                      '\010', '\001', 'R', '\007', 'm', 'a', 't', 'c', 'h', 'e',
                                      'r', '\022', ']', '\n', '\014', 's', 'h', 'a', 'd', 'o', 'w',
                                      '_', 'r', 'u', 'l',
                                      'e', 's', '\030', '\002', ' ', '\001', '(', '\013', '2',
                                      '\032', '.', 'e', 'n', 'v', 'o', 'y', '.', 'c', 'o', 'n', 'f',
                                      'i', 'g', '.', 'r',
                                      'b', 'a', 'c', '.', 'v', '3', '.', 'R', 'B', 'A', 'C', 'B',
                                      '\036', '\362', '\230', '\376', '\217', '\005', '\030',
                                      '\022', '\026', 's', 'h', 'a', 'd',
                                      'o', 'w', '_', 'r', 'u', 'l', 'e', 's', '_', 's', 'p', 'e',
                                      'c', 'i', 'f', 'i', 'e', 'r', 'R', '\013', 's', 'h', 'a', 'd',
                                      'o',
                                      'w', 'R', 'u', 'l', 'e', 's', '\022', 'k', '\n', '\016', 's',
                                      'h', 'a', 'd', 'o', 'w', '_', 'm', 'a', 't', 'c', 'h', 'e',
                                      'r', '\030',
                                      '\005', ' ', '\001', '(', '\013', '2', '\034', '.', 'x', 'd',
                                      's', '.', 't', 'y', 'p', 'e', '.', 'm', 'a', 't', 'c', 'h',
                                      'e', 'r', '.',
                                      'v', '3', '.', 'M', 'a', 't', 'c', 'h', 'e', 'r', 'B', '&',
                                      '\362', '\230', '\376', '\217', '\005', '\030', '\022',
                                      '\026', 's', 'h', 'a', 'd', 'o',
                                      'w', '_', 'r', 'u', 'l', 'e', 's', '_', 's', 'p', 'e', 'c',
                                      'i', 'f', 'i', 'e', 'r', '\322', '\306', '\244', '\341',
                                      '\006', '\002', '\010', '\001',
                                      'R', '\r', 's', 'h', 'a', 'd', 'o', 'w', 'M', 'a', 't', 'c',
                                      'h', 'e', 'r', '\022', '7', '\n', '\030', 's', 'h', 'a', 'd',
                                      'o', 'w',
                                      '_', 'r', 'u', 'l', 'e', 's', '_', 's', 't', 'a', 't', '_',
                                      'p', 'r', 'e', 'f', 'i', 'x', '\030', '\003', ' ', '\001',
                                      '(', '\t', 'R',
                                      '\025', 's', 'h', 'a', 'd', 'o', 'w', 'R', 'u', 'l', 'e', 's',
                                      'S', 't', 'a', 't', 'P', 'r', 'e', 'f', 'i', 'x', ':', ',',
                                      '\232',
                                      '\305', '\210', '\036', '\'', '\n', '%', 'e', 'n', 'v', 'o',
                                      'y', '.', 'c', 'o', 'n', 'f', 'i', 'g', '.', 'f', 'i', 'l',
                                      't', 'e', 'r',
                                      '.', 'h', 't', 't', 'p', '.', 'r', 'b', 'a', 'c', '.', 'v',
                                      '2', '.', 'R', 'B', 'A', 'C', '\"', '\213', '\001', '\n',
                                      '\014', 'R', 'B',
                                      'A', 'C', 'P', 'e', 'r', 'R', 'o', 'u', 't', 'e', '\022', '?',
                                      '\n', '\004', 'r', 'b', 'a', 'c', '\030', '\002', ' ', '\001',
                                      '(', '\013', '2',
                                      '+', '.', 'e', 'n', 'v', 'o', 'y', '.', 'e', 'x', 't', 'e',
                                      'n', 's', 'i', 'o', 'n', 's', '.', 'f', 'i', 'l', 't', 'e',
                                      'r',
                                      's', '.', 'h', 't', 't', 'p', '.', 'r', 'b', 'a', 'c', '.',
                                      'v', '3', '.', 'R', 'B', 'A', 'C', 'R', '\004', 'r', 'b', 'a',
                                      'c',
                                      ':', '4', '\232', '\305', '\210', '\036', '/', '\n', '-', 'e',
                                      'n', 'v', 'o', 'y', '.', 'c', 'o', 'n', 'f', 'i', 'g', '.',
                                      'f', 'i', 'l',
                                      't', 'e', 'r', '.', 'h', 't', 't', 'p', '.', 'r', 'b', 'a',
                                      'c', '.', 'v', '2', '.', 'R', 'B', 'A', 'C', 'P', 'e', 'r',
                                      'R',
                                      'o', 'u', 't', 'e', 'J', '\004', '\010', '\001', '\020',
                                      '\002', 'B', '\237', '\001', '\n', '3', 'i', 'o', '.', 'e',
                                      'n', 'v', 'o', 'y', 'p', 'r',
                                      'o', 'x', 'y', '.', 'e', 'n', 'v', 'o', 'y', '.', 'e', 'x',
                                      't', 'e', 'n', 's', 'i', 'o', 'n', 's', '.', 'f', 'i', 'l',
                                      't',
                                      'e', 'r', 's', '.', 'h', 't', 't', 'p', '.', 'r', 'b', 'a',
                                      'c', '.', 'v', '3', 'B', '\t', 'R', 'b', 'a', 'c', 'P', 'r',
                                      'o',
                                      't', 'o', 'P', '\001', 'Z', 'S', 'g', 'i', 't', 'h', 'u', 'b',
                                      '.', 'c', 'o', 'm', '/', 'e', 'n', 'v', 'o', 'y', 'p', 'r',
                                      'o',
                                      'x', 'y', '/', 'g', 'o', '-', 'c', 'o', 'n', 't', 'r', 'o',
                                      'l', '-', 'p', 'l', 'a', 'n', 'e', '/', 'e', 'n', 'v', 'o',
                                      'y',
                                      '/', 'e', 'x', 't', 'e', 'n', 's', 'i', 'o', 'n', 's', '/',
                                      'f', 'i', 'l', 't', 'e', 'r', 's', '/', 'h', 't', 't', 'p',
                                      '/',
                                      'r', 'b', 'a', 'c', '/', 'v', '3', ';', 'r', 'b', 'a', 'c',
                                      'v', '3', '\272', '\200', '\310', '\321', '\006', '\002',
                                      '\020', '\002', 'b', '\006', 'p',
                                      'r', 'o', 't', 'o', '3',
};

static _upb_DefPool_Init *deps[7] = {
        &envoy_config_rbac_v3_rbac_proto_upbdefinit,
        &xds_annotations_v3_status_proto_upbdefinit,
        &xds_type_matcher_v3_matcher_proto_upbdefinit,
        &udpa_annotations_migrate_proto_upbdefinit,
        &udpa_annotations_status_proto_upbdefinit,
        &udpa_annotations_versioning_proto_upbdefinit,
        NULL
};

_upb_DefPool_Init envoy_extensions_filters_http_rbac_v3_rbac_proto_upbdefinit = {
        deps,
        &envoy_extensions_filters_http_rbac_v3_rbac_proto_upb_file_layout,
        "envoy/extensions/filters/http/rbac/v3/rbac.proto",
        UPB_STRINGVIEW_INIT(descriptor, 1080)
};
