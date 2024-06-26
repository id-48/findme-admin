/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     src/proto/grpc/gcp/altscontext.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/msg_internal.h"
#include "src/proto/grpc/gcp/altscontext.upb.h"
#include "src/proto/grpc/gcp/transport_security_common.upb.h"

#include "upb/port_def.inc"

static const upb_MiniTable_Sub grpc_gcp_AltsContext_submsgs[2] = {
        {.submsg = &grpc_gcp_RpcProtocolVersions_msginit},
        {.submsg = &grpc_gcp_AltsContext_PeerAttributesEntry_msginit},
};

static const upb_MiniTable_Field grpc_gcp_AltsContext__fields[7] = {
        {1, UPB_SIZE(8, 8),   UPB_SIZE(0, 0), kUpb_NoSub, 9,
                                                              kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_StringView
                                                                      << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(16, 24), UPB_SIZE(0, 0), kUpb_NoSub, 9,  kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_StringView
                                                                      << kUpb_FieldRep_Shift)},
        {3, UPB_SIZE(4, 4),   UPB_SIZE(0, 0), kUpb_NoSub, 5,  kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_4Byte
                                                                      << kUpb_FieldRep_Shift)},
        {4, UPB_SIZE(24, 40), UPB_SIZE(0, 0), kUpb_NoSub, 9,  kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_StringView
                                                                      << kUpb_FieldRep_Shift)},
        {5, UPB_SIZE(32, 56), UPB_SIZE(0, 0), kUpb_NoSub, 9,  kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_StringView
                                                                      << kUpb_FieldRep_Shift)},
        {6, UPB_SIZE(40, 72), UPB_SIZE(1, 1), 0,          11, kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_Pointer
                                                                      << kUpb_FieldRep_Shift)},
        {7, UPB_SIZE(44, 80), UPB_SIZE(0, 0), 1,          11, kUpb_FieldMode_Map |
                                                              (kUpb_FieldRep_Pointer
                                                                      << kUpb_FieldRep_Shift)},
};

const upb_MiniTable grpc_gcp_AltsContext_msginit = {
        &grpc_gcp_AltsContext_submsgs[0],
        &grpc_gcp_AltsContext__fields[0],
        UPB_SIZE(48, 88), 7, kUpb_ExtMode_NonExtendable, 7, 255, 0,
};

static const upb_MiniTable_Field grpc_gcp_AltsContext_PeerAttributesEntry__fields[2] = {
        {1, UPB_SIZE(0, 0),  UPB_SIZE(0, 0), kUpb_NoSub, 12,
                                                             kUpb_FieldMode_Scalar |
                                                             (kUpb_FieldRep_1Byte
                                                                     << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(8, 16), UPB_SIZE(0, 0), kUpb_NoSub, 12, kUpb_FieldMode_Scalar |
                                                             (kUpb_FieldRep_1Byte
                                                                     << kUpb_FieldRep_Shift)},
};

const upb_MiniTable grpc_gcp_AltsContext_PeerAttributesEntry_msginit = {
        NULL,
        &grpc_gcp_AltsContext_PeerAttributesEntry__fields[0],
        UPB_SIZE(16, 32), 2, kUpb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable *messages_layout[2] = {
        &grpc_gcp_AltsContext_msginit,
        &grpc_gcp_AltsContext_PeerAttributesEntry_msginit,
};

const upb_MiniTable_File src_proto_grpc_gcp_altscontext_proto_upb_file_layout = {
        messages_layout,
        NULL,
        NULL,
        2,
        0,
        0,
};

#include "upb/port_undef.inc"

