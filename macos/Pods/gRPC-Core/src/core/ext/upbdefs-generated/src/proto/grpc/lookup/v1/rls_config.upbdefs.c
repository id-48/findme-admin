/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     src/proto/grpc/lookup/v1/rls_config.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include "upb/def.h"
#include "src/proto/grpc/lookup/v1/rls_config.upbdefs.h"
#include "src/proto/grpc/lookup/v1/rls_config.upb.h"

extern _upb_DefPool_Init google_protobuf_duration_proto_upbdefinit;
static const char descriptor[1816] = {'\n', ')', 's', 'r', 'c', '/', 'p', 'r', 'o', 't', 'o', '/',
                                      'g', 'r', 'p', 'c', '/', 'l', 'o', 'o', 'k', 'u', 'p', '/',
                                      'v',
                                      '1', '/', 'r', 'l', 's', '_', 'c', 'o', 'n', 'f', 'i', 'g',
                                      '.', 'p', 'r', 'o', 't', 'o', '\022', '\016', 'g', 'r', 'p',
                                      'c', '.',
                                      'l', 'o', 'o', 'k', 'u', 'p', '.', 'v', '1', '\032', '\036',
                                      'g', 'o', 'o', 'g', 'l', 'e', '/', 'p', 'r', 'o', 't', 'o',
                                      'b', 'u',
                                      'f', '/', 'd', 'u', 'r', 'a', 't', 'i', 'o', 'n', '.', 'p',
                                      'r', 'o', 't', 'o', '\"', '\\', '\n', '\013', 'N', 'a', 'm',
                                      'e', 'M',
                                      'a', 't', 'c', 'h', 'e', 'r', '\022', '\020', '\n', '\003',
                                      'k', 'e', 'y', '\030', '\001', ' ', '\001', '(', '\t', 'R',
                                      '\003', 'k', 'e', 'y', '\022',
                                      '\024', '\n', '\005', 'n', 'a', 'm', 'e', 's', '\030', '\002',
                                      ' ', '\003', '(', '\t', 'R', '\005', 'n', 'a', 'm', 'e', 's',
                                      '\022', '%', '\n', '\016',
                                      'r', 'e', 'q', 'u', 'i', 'r', 'e', 'd', '_', 'm', 'a', 't',
                                      'c', 'h', '\030', '\003', ' ', '\001', '(', '\010', 'R', '\r',
                                      'r', 'e', 'q',
                                      'u', 'i', 'r', 'e', 'd', 'M', 'a', 't', 'c', 'h', '\"',
                                      '\360', '\003', '\n', '\016', 'G', 'r', 'p', 'c', 'K', 'e',
                                      'y', 'B', 'u', 'i',
                                      'l', 'd', 'e', 'r', '\022', '9', '\n', '\005', 'n', 'a', 'm',
                                      'e', 's', '\030', '\001', ' ', '\003', '(', '\013', '2', '#',
                                      '.', 'g', 'r', 'p',
                                      'c', '.', 'l', 'o', 'o', 'k', 'u', 'p', '.', 'v', '1', '.',
                                      'G', 'r', 'p', 'c', 'K', 'e', 'y', 'B', 'u', 'i', 'l', 'd',
                                      'e',
                                      'r', '.', 'N', 'a', 'm', 'e', 'R', '\005', 'n', 'a', 'm', 'e',
                                      's', '\022', 'G', '\n', '\n', 'e', 'x', 't', 'r', 'a', '_',
                                      'k', 'e',
                                      'y', 's', '\030', '\003', ' ', '\001', '(', '\013', '2', '(',
                                      '.', 'g', 'r', 'p', 'c', '.', 'l', 'o', 'o', 'k', 'u', 'p',
                                      '.', 'v', '1',
                                      '.', 'G', 'r', 'p', 'c', 'K', 'e', 'y', 'B', 'u', 'i', 'l',
                                      'd', 'e', 'r', '.', 'E', 'x', 't', 'r', 'a', 'K', 'e', 'y',
                                      's',
                                      'R', '\t', 'e', 'x', 't', 'r', 'a', 'K', 'e', 'y', 's',
                                      '\022', '5', '\n', '\007', 'h', 'e', 'a', 'd', 'e', 'r', 's',
                                      '\030', '\002', ' ',
                                      '\003', '(', '\013', '2', '\033', '.', 'g', 'r', 'p', 'c',
                                      '.', 'l', 'o', 'o', 'k', 'u', 'p', '.', 'v', '1', '.', 'N',
                                      'a', 'm', 'e',
                                      'M', 'a', 't', 'c', 'h', 'e', 'r', 'R', '\007', 'h', 'e', 'a',
                                      'd', 'e', 'r', 's', '\022', 'U', '\n', '\r', 'c', 'o', 'n',
                                      's', 't',
                                      'a', 'n', 't', '_', 'k', 'e', 'y', 's', '\030', '\004', ' ',
                                      '\003', '(', '\013', '2', '0', '.', 'g', 'r', 'p', 'c', '.',
                                      'l', 'o', 'o',
                                      'k', 'u', 'p', '.', 'v', '1', '.', 'G', 'r', 'p', 'c', 'K',
                                      'e', 'y', 'B', 'u', 'i', 'l', 'd', 'e', 'r', '.', 'C', 'o',
                                      'n',
                                      's', 't', 'a', 'n', 't', 'K', 'e', 'y', 's', 'E', 'n', 't',
                                      'r', 'y', 'R', '\014', 'c', 'o', 'n', 's', 't', 'a', 'n', 't',
                                      'K',
                                      'e', 'y', 's', '\032', '8', '\n', '\004', 'N', 'a', 'm', 'e',
                                      '\022', '\030', '\n', '\007', 's', 'e', 'r', 'v', 'i', 'c',
                                      'e', '\030', '\001', ' ',
                                      '\001', '(', '\t', 'R', '\007', 's', 'e', 'r', 'v', 'i', 'c',
                                      'e', '\022', '\026', '\n', '\006', 'm', 'e', 't', 'h', 'o',
                                      'd', '\030', '\002', ' ',
                                      '\001', '(', '\t', 'R', '\006', 'm', 'e', 't', 'h', 'o', 'd',
                                      '\032', 'Q', '\n', '\t', 'E', 'x', 't', 'r', 'a', 'K', 'e',
                                      'y', 's', '\022',
                                      '\022', '\n', '\004', 'h', 'o', 's', 't', '\030', '\001', ' ',
                                      '\001', '(', '\t', 'R', '\004', 'h', 'o', 's', 't', '\022',
                                      '\030', '\n', '\007', 's', 'e',
                                      'r', 'v', 'i', 'c', 'e', '\030', '\002', ' ', '\001', '(',
                                      '\t', 'R', '\007', 's', 'e', 'r', 'v', 'i', 'c', 'e', '\022',
                                      '\026', '\n', '\006', 'm',
                                      'e', 't', 'h', 'o', 'd', '\030', '\003', ' ', '\001', '(',
                                      '\t', 'R', '\006', 'm', 'e', 't', 'h', 'o', 'd', '\032', '?',
                                      '\n', '\021', 'C', 'o',
                                      'n', 's', 't', 'a', 'n', 't', 'K', 'e', 'y', 's', 'E', 'n',
                                      't', 'r', 'y', '\022', '\020', '\n', '\003', 'k', 'e', 'y',
                                      '\030', '\001', ' ',
                                      '\001', '(', '\t', 'R', '\003', 'k', 'e', 'y', '\022', '\024',
                                      '\n', '\005', 'v', 'a', 'l', 'u', 'e', '\030', '\002', ' ',
                                      '\001', '(', '\t', 'R', '\005',
                                      'v', 'a', 'l', 'u', 'e', ':', '\002', '8', '\001', '\"',
                                      '\361', '\002', '\n', '\016', 'H', 't', 't', 'p', 'K', 'e',
                                      'y', 'B', 'u', 'i', 'l',
                                      'd', 'e', 'r', '\022', '#', '\n', '\r', 'h', 'o', 's', 't',
                                      '_', 'p', 'a', 't', 't', 'e', 'r', 'n', 's', '\030', '\001',
                                      ' ', '\003', '(',
                                      '\t', 'R', '\014', 'h', 'o', 's', 't', 'P', 'a', 't', 't',
                                      'e', 'r', 'n', 's', '\022', '#', '\n', '\r', 'p', 'a', 't',
                                      'h', '_', 'p',
                                      'a', 't', 't', 'e', 'r', 'n', 's', '\030', '\002', ' ',
                                      '\003', '(', '\t', 'R', '\014', 'p', 'a', 't', 'h', 'P', 'a',
                                      't', 't', 'e', 'r',
                                      'n', 's', '\022', 'F', '\n', '\020', 'q', 'u', 'e', 'r', 'y',
                                      '_', 'p', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r', 's', '\030',
                                      '\003', ' ',
                                      '\003', '(', '\013', '2', '\033', '.', 'g', 'r', 'p', 'c',
                                      '.', 'l', 'o', 'o', 'k', 'u', 'p', '.', 'v', '1', '.', 'N',
                                      'a', 'm', 'e',
                                      'M', 'a', 't', 'c', 'h', 'e', 'r', 'R', '\017', 'q', 'u', 'e',
                                      'r', 'y', 'P', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r', 's',
                                      '\022',
                                      '5', '\n', '\007', 'h', 'e', 'a', 'd', 'e', 'r', 's', '\030',
                                      '\004', ' ', '\003', '(', '\013', '2', '\033', '.', 'g', 'r',
                                      'p', 'c', '.', 'l',
                                      'o', 'o', 'k', 'u', 'p', '.', 'v', '1', '.', 'N', 'a', 'm',
                                      'e', 'M', 'a', 't', 'c', 'h', 'e', 'r', 'R', '\007', 'h', 'e',
                                      'a',
                                      'd', 'e', 'r', 's', '\022', 'U', '\n', '\r', 'c', 'o', 'n',
                                      's', 't', 'a', 'n', 't', '_', 'k', 'e', 'y', 's', '\030',
                                      '\005', ' ', '\003',
                                      '(', '\013', '2', '0', '.', 'g', 'r', 'p', 'c', '.', 'l', 'o',
                                      'o', 'k', 'u', 'p', '.', 'v', '1', '.', 'H', 't', 't', 'p',
                                      'K',
                                      'e', 'y', 'B', 'u', 'i', 'l', 'd', 'e', 'r', '.', 'C', 'o',
                                      'n', 's', 't', 'a', 'n', 't', 'K', 'e', 'y', 's', 'E', 'n',
                                      't',
                                      'r', 'y', 'R', '\014', 'c', 'o', 'n', 's', 't', 'a', 'n', 't',
                                      'K', 'e', 'y', 's', '\032', '?', '\n', '\021', 'C', 'o', 'n',
                                      's', 't',
                                      'a', 'n', 't', 'K', 'e', 'y', 's', 'E', 'n', 't', 'r', 'y',
                                      '\022', '\020', '\n', '\003', 'k', 'e', 'y', '\030', '\001',
                                      ' ', '\001', '(', '\t',
                                      'R', '\003', 'k', 'e', 'y', '\022', '\024', '\n', '\005', 'v',
                                      'a', 'l', 'u', 'e', '\030', '\002', ' ', '\001', '(', '\t',
                                      'R', '\005', 'v', 'a', 'l',
                                      'u', 'e', ':', '\002', '8', '\001', '\"', '\246', '\004',
                                      '\n', '\021', 'R', 'o', 'u', 't', 'e', 'L', 'o', 'o', 'k',
                                      'u', 'p', 'C', 'o', 'n',
                                      'f', 'i', 'g', '\022', 'I', '\n', '\020', 'h', 't', 't', 'p',
                                      '_', 'k', 'e', 'y', 'b', 'u', 'i', 'l', 'd', 'e', 'r', 's',
                                      '\030', '\001',
                                      ' ', '\003', '(', '\013', '2', '\036', '.', 'g', 'r', 'p',
                                      'c', '.', 'l', 'o', 'o', 'k', 'u', 'p', '.', 'v', '1', '.',
                                      'H', 't', 't',
                                      'p', 'K', 'e', 'y', 'B', 'u', 'i', 'l', 'd', 'e', 'r', 'R',
                                      '\017', 'h', 't', 't', 'p', 'K', 'e', 'y', 'b', 'u', 'i', 'l',
                                      'd',
                                      'e', 'r', 's', '\022', 'I', '\n', '\020', 'g', 'r', 'p', 'c',
                                      '_', 'k', 'e', 'y', 'b', 'u', 'i', 'l', 'd', 'e', 'r', 's',
                                      '\030', '\002',
                                      ' ', '\003', '(', '\013', '2', '\036', '.', 'g', 'r', 'p',
                                      'c', '.', 'l', 'o', 'o', 'k', 'u', 'p', '.', 'v', '1', '.',
                                      'G', 'r', 'p',
                                      'c', 'K', 'e', 'y', 'B', 'u', 'i', 'l', 'd', 'e', 'r', 'R',
                                      '\017', 'g', 'r', 'p', 'c', 'K', 'e', 'y', 'b', 'u', 'i', 'l',
                                      'd',
                                      'e', 'r', 's', '\022', '%', '\n', '\016', 'l', 'o', 'o', 'k',
                                      'u', 'p', '_', 's', 'e', 'r', 'v', 'i', 'c', 'e', '\030',
                                      '\003', ' ', '\001',
                                      '(', '\t', 'R', '\r', 'l', 'o', 'o', 'k', 'u', 'p', 'S', 'e',
                                      'r', 'v', 'i', 'c', 'e', '\022', 'O', '\n', '\026', 'l', 'o',
                                      'o', 'k',
                                      'u', 'p', '_', 's', 'e', 'r', 'v', 'i', 'c', 'e', '_', 't',
                                      'i', 'm', 'e', 'o', 'u', 't', '\030', '\004', ' ', '\001',
                                      '(', '\013', '2',
                                      '\031', '.', 'g', 'o', 'o', 'g', 'l', 'e', '.', 'p', 'r', 'o',
                                      't', 'o', 'b', 'u', 'f', '.', 'D', 'u', 'r', 'a', 't', 'i',
                                      'o',
                                      'n', 'R', '\024', 'l', 'o', 'o', 'k', 'u', 'p', 'S', 'e', 'r',
                                      'v', 'i', 'c', 'e', 'T', 'i', 'm', 'e', 'o', 'u', 't', '\022',
                                      '2',
                                      '\n', '\007', 'm', 'a', 'x', '_', 'a', 'g', 'e', '\030',
                                      '\005', ' ', '\001', '(', '\013', '2', '\031', '.', 'g', 'o',
                                      'o', 'g', 'l', 'e', '.',
                                      'p', 'r', 'o', 't', 'o', 'b', 'u', 'f', '.', 'D', 'u', 'r',
                                      'a', 't', 'i', 'o', 'n', 'R', '\006', 'm', 'a', 'x', 'A', 'g',
                                      'e',
                                      '\022', '6', '\n', '\t', 's', 't', 'a', 'l', 'e', '_', 'a',
                                      'g', 'e', '\030', '\006', ' ', '\001', '(', '\013', '2',
                                      '\031', '.', 'g', 'o', 'o',
                                      'g', 'l', 'e', '.', 'p', 'r', 'o', 't', 'o', 'b', 'u', 'f',
                                      '.', 'D', 'u', 'r', 'a', 't', 'i', 'o', 'n', 'R', '\010', 's',
                                      't',
                                      'a', 'l', 'e', 'A', 'g', 'e', '\022', '(', '\n', '\020', 'c',
                                      'a', 'c', 'h', 'e', '_', 's', 'i', 'z', 'e', '_', 'b', 'y',
                                      't', 'e',
                                      's', '\030', '\007', ' ', '\001', '(', '\003', 'R', '\016',
                                      'c', 'a', 'c', 'h', 'e', 'S', 'i', 'z', 'e', 'B', 'y', 't',
                                      'e', 's', '\022', '#',
                                      '\n', '\r', 'v', 'a', 'l', 'i', 'd', '_', 't', 'a', 'r', 'g',
                                      'e', 't', 's', '\030', '\010', ' ', '\003', '(', '\t', 'R',
                                      '\014', 'v', 'a',
                                      'l', 'i', 'd', 'T', 'a', 'r', 'g', 'e', 't', 's', '\022', '%',
                                      '\n', '\016', 'd', 'e', 'f', 'a', 'u', 'l', 't', '_', 't',
                                      'a', 'r',
                                      'g', 'e', 't', '\030', '\t', ' ', '\001', '(', '\t', 'R',
                                      '\r', 'd', 'e', 'f', 'a', 'u', 'l', 't', 'T', 'a', 'r', 'g',
                                      'e', 't', 'J',
                                      '\004', '\010', '\n', '\020', '\013', 'R', '\033', 'r', 'e',
                                      'q', 'u', 'e', 's', 't', '_', 'p', 'r', 'o', 'c', 'e', 's',
                                      's', 'i', 'n', 'g',
                                      '_', 's', 't', 'r', 'a', 't', 'e', 'g', 'y', '\"', 'p', '\n',
                                      '\033', 'R', 'o', 'u', 't', 'e', 'L', 'o', 'o', 'k', 'u', 'p',
                                      'C',
                                      'l', 'u', 's', 't', 'e', 'r', 'S', 'p', 'e', 'c', 'i', 'f',
                                      'i', 'e', 'r', '\022', 'Q', '\n', '\023', 'r', 'o', 'u', 't',
                                      'e', '_',
                                      'l', 'o', 'o', 'k', 'u', 'p', '_', 'c', 'o', 'n', 'f', 'i',
                                      'g', '\030', '\001', ' ', '\001', '(', '\013', '2', '!', '.',
                                      'g', 'r', 'p',
                                      'c', '.', 'l', 'o', 'o', 'k', 'u', 'p', '.', 'v', '1', '.',
                                      'R', 'o', 'u', 't', 'e', 'L', 'o', 'o', 'k', 'u', 'p', 'C',
                                      'o',
                                      'n', 'f', 'i', 'g', 'R', '\021', 'r', 'o', 'u', 't', 'e', 'L',
                                      'o', 'o', 'k', 'u', 'p', 'C', 'o', 'n', 'f', 'i', 'g', 'B',
                                      'S',
                                      '\n', '\021', 'i', 'o', '.', 'g', 'r', 'p', 'c', '.', 'l',
                                      'o', 'o', 'k', 'u', 'p', '.', 'v', '1', 'B', '\016', 'R', 'l',
                                      's', 'C',
                                      'o', 'n', 'f', 'i', 'g', 'P', 'r', 'o', 't', 'o', 'P', '\001',
                                      'Z', ',', 'g', 'o', 'o', 'g', 'l', 'e', '.', 'g', 'o', 'l',
                                      'a',
                                      'n', 'g', '.', 'o', 'r', 'g', '/', 'g', 'r', 'p', 'c', '/',
                                      'l', 'o', 'o', 'k', 'u', 'p', '/', 'g', 'r', 'p', 'c', '_',
                                      'l',
                                      'o', 'o', 'k', 'u', 'p', '_', 'v', '1', 'b', '\006', 'p', 'r',
                                      'o', 't', 'o', '3',
};

static _upb_DefPool_Init *deps[2] = {
        &google_protobuf_duration_proto_upbdefinit,
        NULL
};

_upb_DefPool_Init src_proto_grpc_lookup_v1_rls_config_proto_upbdefinit = {
        deps,
        &src_proto_grpc_lookup_v1_rls_config_proto_upb_file_layout,
        "src/proto/grpc/lookup/v1/rls_config.proto",
        UPB_STRINGVIEW_INIT(descriptor, 1816)
};
