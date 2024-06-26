/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     xds/data/orca/v3/orca_load_report.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/msg_internal.h"
#include "xds/data/orca/v3/orca_load_report.upb.h"
#include "validate/validate.upb.h"

#include "upb/port_def.inc"

static const upb_MiniTable_Sub xds_data_orca_v3_OrcaLoadReport_submsgs[2] = {
        {.submsg = &xds_data_orca_v3_OrcaLoadReport_RequestCostEntry_msginit},
        {.submsg = &xds_data_orca_v3_OrcaLoadReport_UtilizationEntry_msginit},
};

static const upb_MiniTable_Field xds_data_orca_v3_OrcaLoadReport__fields[5] = {
        {1, UPB_SIZE(8, 16),  UPB_SIZE(0, 0), kUpb_NoSub, 1,
                                                              kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_8Byte
                                                                      << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(16, 24), UPB_SIZE(0, 0), kUpb_NoSub, 1,  kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_8Byte
                                                                      << kUpb_FieldRep_Shift)},
        {3, UPB_SIZE(24, 32), UPB_SIZE(0, 0), kUpb_NoSub, 4,  kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_8Byte
                                                                      << kUpb_FieldRep_Shift)},
        {4, UPB_SIZE(0, 0),   UPB_SIZE(0, 0), 0,          11, kUpb_FieldMode_Map |
                                                              (kUpb_FieldRep_Pointer
                                                                      << kUpb_FieldRep_Shift)},
        {5, UPB_SIZE(4, 8),   UPB_SIZE(0, 0), 1,          11, kUpb_FieldMode_Map |
                                                              (kUpb_FieldRep_Pointer
                                                                      << kUpb_FieldRep_Shift)},
};

const upb_MiniTable xds_data_orca_v3_OrcaLoadReport_msginit = {
        &xds_data_orca_v3_OrcaLoadReport_submsgs[0],
        &xds_data_orca_v3_OrcaLoadReport__fields[0],
        UPB_SIZE(32, 40), 5, kUpb_ExtMode_NonExtendable, 5, 255, 0,
};

static const upb_MiniTable_Field xds_data_orca_v3_OrcaLoadReport_RequestCostEntry__fields[2] = {
        {1, UPB_SIZE(0, 0),  UPB_SIZE(0, 0), kUpb_NoSub, 12,
                                                            kUpb_FieldMode_Scalar |
                                                            (kUpb_FieldRep_1Byte
                                                                    << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(8, 16), UPB_SIZE(0, 0), kUpb_NoSub, 1, kUpb_FieldMode_Scalar |
                                                            (kUpb_FieldRep_1Byte
                                                                    << kUpb_FieldRep_Shift)},
};

const upb_MiniTable xds_data_orca_v3_OrcaLoadReport_RequestCostEntry_msginit = {
        NULL,
        &xds_data_orca_v3_OrcaLoadReport_RequestCostEntry__fields[0],
        UPB_SIZE(16, 32), 2, kUpb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable_Field xds_data_orca_v3_OrcaLoadReport_UtilizationEntry__fields[2] = {
        {1, UPB_SIZE(0, 0),  UPB_SIZE(0, 0), kUpb_NoSub, 12,
                                                            kUpb_FieldMode_Scalar |
                                                            (kUpb_FieldRep_1Byte
                                                                    << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(8, 16), UPB_SIZE(0, 0), kUpb_NoSub, 1, kUpb_FieldMode_Scalar |
                                                            (kUpb_FieldRep_1Byte
                                                                    << kUpb_FieldRep_Shift)},
};

const upb_MiniTable xds_data_orca_v3_OrcaLoadReport_UtilizationEntry_msginit = {
        NULL,
        &xds_data_orca_v3_OrcaLoadReport_UtilizationEntry__fields[0],
        UPB_SIZE(16, 32), 2, kUpb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable *messages_layout[3] = {
        &xds_data_orca_v3_OrcaLoadReport_msginit,
        &xds_data_orca_v3_OrcaLoadReport_RequestCostEntry_msginit,
        &xds_data_orca_v3_OrcaLoadReport_UtilizationEntry_msginit,
};

const upb_MiniTable_File xds_data_orca_v3_orca_load_report_proto_upb_file_layout = {
        messages_layout,
        NULL,
        NULL,
        3,
        0,
        0,
};

#include "upb/port_undef.inc"

