/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/config/rbac/v3/rbac.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/msg_internal.h"
#include "envoy/config/rbac/v3/rbac.upb.h"
#include "envoy/config/core/v3/address.upb.h"
#include "envoy/config/core/v3/extension.upb.h"
#include "envoy/config/route/v3/route_components.upb.h"
#include "envoy/type/matcher/v3/metadata.upb.h"
#include "envoy/type/matcher/v3/path.upb.h"
#include "envoy/type/matcher/v3/string.upb.h"
#include "envoy/type/v3/range.upb.h"
#include "google/api/expr/v1alpha1/checked.upb.h"
#include "google/api/expr/v1alpha1/syntax.upb.h"
#include "envoy/annotations/deprecation.upb.h"
#include "udpa/annotations/migrate.upb.h"
#include "udpa/annotations/status.upb.h"
#include "udpa/annotations/versioning.upb.h"
#include "validate/validate.upb.h"

#include "upb/port_def.inc"

static const upb_MiniTable_Sub envoy_config_rbac_v3_RBAC_submsgs[1] = {
        {.submsg = &envoy_config_rbac_v3_RBAC_PoliciesEntry_msginit},
};

static const upb_MiniTable_Field envoy_config_rbac_v3_RBAC__fields[2] = {
        {1, UPB_SIZE(0, 0), UPB_SIZE(0, 0), kUpb_NoSub, 5,
                                                            kUpb_FieldMode_Scalar |
                                                            (kUpb_FieldRep_4Byte
                                                                    << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(4, 8), UPB_SIZE(0, 0), 0,          11, kUpb_FieldMode_Map |
                                                            (kUpb_FieldRep_Pointer
                                                                    << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_rbac_v3_RBAC_msginit = {
        &envoy_config_rbac_v3_RBAC_submsgs[0],
        &envoy_config_rbac_v3_RBAC__fields[0],
        UPB_SIZE(8, 16), 2, kUpb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_rbac_v3_RBAC_PoliciesEntry_submsgs[1] = {
        {.submsg = &envoy_config_rbac_v3_Policy_msginit},
};

static const upb_MiniTable_Field envoy_config_rbac_v3_RBAC_PoliciesEntry__fields[2] = {
        {1, UPB_SIZE(0, 0),  UPB_SIZE(0, 0), kUpb_NoSub, 12,
                                                             kUpb_FieldMode_Scalar |
                                                             (kUpb_FieldRep_1Byte
                                                                     << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(8, 16), UPB_SIZE(0, 0), 0,          11, kUpb_FieldMode_Scalar |
                                                             (kUpb_FieldRep_1Byte
                                                                     << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_rbac_v3_RBAC_PoliciesEntry_msginit = {
        &envoy_config_rbac_v3_RBAC_PoliciesEntry_submsgs[0],
        &envoy_config_rbac_v3_RBAC_PoliciesEntry__fields[0],
        UPB_SIZE(16, 32), 2, kUpb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_rbac_v3_Policy_submsgs[4] = {
        {.submsg = &envoy_config_rbac_v3_Permission_msginit},
        {.submsg = &envoy_config_rbac_v3_Principal_msginit},
        {.submsg = &google_api_expr_v1alpha1_Expr_msginit},
        {.submsg = &google_api_expr_v1alpha1_CheckedExpr_msginit},
};

static const upb_MiniTable_Field envoy_config_rbac_v3_Policy__fields[4] = {
        {1, UPB_SIZE(4, 8),   UPB_SIZE(0, 0), 0, 11,
                                                     kUpb_FieldMode_Array | (kUpb_FieldRep_Pointer
                                                             << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(8, 16),  UPB_SIZE(0, 0), 1, 11, kUpb_FieldMode_Array | (kUpb_FieldRep_Pointer
                << kUpb_FieldRep_Shift)},
        {3, UPB_SIZE(12, 24), UPB_SIZE(1, 1), 2, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer
                << kUpb_FieldRep_Shift)},
        {4, UPB_SIZE(16, 32), UPB_SIZE(2, 2), 3, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer
                << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_rbac_v3_Policy_msginit = {
        &envoy_config_rbac_v3_Policy_submsgs[0],
        &envoy_config_rbac_v3_Policy__fields[0],
        UPB_SIZE(24, 40), 4, kUpb_ExtMode_NonExtendable, 4, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_rbac_v3_Permission_submsgs[10] = {
        {.submsg = &envoy_config_rbac_v3_Permission_Set_msginit},
        {.submsg = &envoy_config_rbac_v3_Permission_Set_msginit},
        {.submsg = &envoy_config_route_v3_HeaderMatcher_msginit},
        {.submsg = &envoy_config_core_v3_CidrRange_msginit},
        {.submsg = &envoy_type_matcher_v3_MetadataMatcher_msginit},
        {.submsg = &envoy_config_rbac_v3_Permission_msginit},
        {.submsg = &envoy_type_matcher_v3_StringMatcher_msginit},
        {.submsg = &envoy_type_matcher_v3_PathMatcher_msginit},
        {.submsg = &envoy_type_v3_Int32Range_msginit},
        {.submsg = &envoy_config_core_v3_TypedExtensionConfig_msginit},
};

static const upb_MiniTable_Field envoy_config_rbac_v3_Permission__fields[12] = {
        {1,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 0,          11,
                                                               kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_Pointer
                                                                       << kUpb_FieldRep_Shift)},
        {2,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 1,          11, kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_Pointer
                                                                       << kUpb_FieldRep_Shift)},
        {3,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), kUpb_NoSub, 8,  kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_1Byte
                                                                       << kUpb_FieldRep_Shift)},
        {4,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 2,          11, kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_Pointer
                                                                       << kUpb_FieldRep_Shift)},
        {5,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 3,          11, kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_Pointer
                                                                       << kUpb_FieldRep_Shift)},
        {6,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), kUpb_NoSub, 13, kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_4Byte
                                                                       << kUpb_FieldRep_Shift)},
        {7,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 4,          11, kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_Pointer
                                                                       << kUpb_FieldRep_Shift)},
        {8,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 5,          11, kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_Pointer
                                                                       << kUpb_FieldRep_Shift)},
        {9,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 6,          11, kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_Pointer
                                                                       << kUpb_FieldRep_Shift)},
        {10, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 7,          11, kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_Pointer
                                                                       << kUpb_FieldRep_Shift)},
        {11, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 8,          11, kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_Pointer
                                                                       << kUpb_FieldRep_Shift)},
        {12, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 9,          11, kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_Pointer
                                                                       << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_rbac_v3_Permission_msginit = {
        &envoy_config_rbac_v3_Permission_submsgs[0],
        &envoy_config_rbac_v3_Permission__fields[0],
        UPB_SIZE(8, 16), 12, kUpb_ExtMode_NonExtendable, 12, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_rbac_v3_Permission_Set_submsgs[1] = {
        {.submsg = &envoy_config_rbac_v3_Permission_msginit},
};

static const upb_MiniTable_Field envoy_config_rbac_v3_Permission_Set__fields[1] = {
        {1, UPB_SIZE(0, 0), UPB_SIZE(0, 0), 0, 11,
         kUpb_FieldMode_Array | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_rbac_v3_Permission_Set_msginit = {
        &envoy_config_rbac_v3_Permission_Set_submsgs[0],
        &envoy_config_rbac_v3_Permission_Set__fields[0],
        UPB_SIZE(8, 8), 1, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_rbac_v3_Principal_submsgs[10] = {
        {.submsg = &envoy_config_rbac_v3_Principal_Set_msginit},
        {.submsg = &envoy_config_rbac_v3_Principal_Set_msginit},
        {.submsg = &envoy_config_rbac_v3_Principal_Authenticated_msginit},
        {.submsg = &envoy_config_core_v3_CidrRange_msginit},
        {.submsg = &envoy_config_route_v3_HeaderMatcher_msginit},
        {.submsg = &envoy_type_matcher_v3_MetadataMatcher_msginit},
        {.submsg = &envoy_config_rbac_v3_Principal_msginit},
        {.submsg = &envoy_type_matcher_v3_PathMatcher_msginit},
        {.submsg = &envoy_config_core_v3_CidrRange_msginit},
        {.submsg = &envoy_config_core_v3_CidrRange_msginit},
};

static const upb_MiniTable_Field envoy_config_rbac_v3_Principal__fields[11] = {
        {1,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 0,          11,
                                                               kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_Pointer
                                                                       << kUpb_FieldRep_Shift)},
        {2,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 1,          11, kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_Pointer
                                                                       << kUpb_FieldRep_Shift)},
        {3,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), kUpb_NoSub, 8,  kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_1Byte
                                                                       << kUpb_FieldRep_Shift)},
        {4,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 2,          11, kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_Pointer
                                                                       << kUpb_FieldRep_Shift)},
        {5,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 3,          11, kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_Pointer
                                                                       << kUpb_FieldRep_Shift)},
        {6,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 4,          11, kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_Pointer
                                                                       << kUpb_FieldRep_Shift)},
        {7,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 5,          11, kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_Pointer
                                                                       << kUpb_FieldRep_Shift)},
        {8,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 6,          11, kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_Pointer
                                                                       << kUpb_FieldRep_Shift)},
        {9,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 7,          11, kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_Pointer
                                                                       << kUpb_FieldRep_Shift)},
        {10, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 8,          11, kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_Pointer
                                                                       << kUpb_FieldRep_Shift)},
        {11, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 9,          11, kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_Pointer
                                                                       << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_rbac_v3_Principal_msginit = {
        &envoy_config_rbac_v3_Principal_submsgs[0],
        &envoy_config_rbac_v3_Principal__fields[0],
        UPB_SIZE(8, 16), 11, kUpb_ExtMode_NonExtendable, 11, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_rbac_v3_Principal_Set_submsgs[1] = {
        {.submsg = &envoy_config_rbac_v3_Principal_msginit},
};

static const upb_MiniTable_Field envoy_config_rbac_v3_Principal_Set__fields[1] = {
        {1, UPB_SIZE(0, 0), UPB_SIZE(0, 0), 0, 11,
         kUpb_FieldMode_Array | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_rbac_v3_Principal_Set_msginit = {
        &envoy_config_rbac_v3_Principal_Set_submsgs[0],
        &envoy_config_rbac_v3_Principal_Set__fields[0],
        UPB_SIZE(8, 8), 1, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_rbac_v3_Principal_Authenticated_submsgs[1] = {
        {.submsg = &envoy_type_matcher_v3_StringMatcher_msginit},
};

static const upb_MiniTable_Field envoy_config_rbac_v3_Principal_Authenticated__fields[1] = {
        {2, UPB_SIZE(4, 8), UPB_SIZE(1, 1), 0, 11,
         kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_rbac_v3_Principal_Authenticated_msginit = {
        &envoy_config_rbac_v3_Principal_Authenticated_submsgs[0],
        &envoy_config_rbac_v3_Principal_Authenticated__fields[0],
        UPB_SIZE(8, 16), 1, kUpb_ExtMode_NonExtendable, 0, 255, 0,
};

static const upb_MiniTable_Field envoy_config_rbac_v3_Action__fields[2] = {
        {1, UPB_SIZE(4, 8), UPB_SIZE(0, 0), kUpb_NoSub, 9,
                                                           kUpb_FieldMode_Scalar |
                                                           (kUpb_FieldRep_StringView
                                                                   << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(0, 0), UPB_SIZE(0, 0), kUpb_NoSub, 5, kUpb_FieldMode_Scalar |
                                                           (kUpb_FieldRep_4Byte
                                                                   << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_rbac_v3_Action_msginit = {
        NULL,
        &envoy_config_rbac_v3_Action__fields[0],
        UPB_SIZE(16, 24), 2, kUpb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable *messages_layout[9] = {
        &envoy_config_rbac_v3_RBAC_msginit,
        &envoy_config_rbac_v3_RBAC_PoliciesEntry_msginit,
        &envoy_config_rbac_v3_Policy_msginit,
        &envoy_config_rbac_v3_Permission_msginit,
        &envoy_config_rbac_v3_Permission_Set_msginit,
        &envoy_config_rbac_v3_Principal_msginit,
        &envoy_config_rbac_v3_Principal_Set_msginit,
        &envoy_config_rbac_v3_Principal_Authenticated_msginit,
        &envoy_config_rbac_v3_Action_msginit,
};

const upb_MiniTable_File envoy_config_rbac_v3_rbac_proto_upb_file_layout = {
        messages_layout,
        NULL,
        NULL,
        9,
        0,
        0,
};

#include "upb/port_undef.inc"

