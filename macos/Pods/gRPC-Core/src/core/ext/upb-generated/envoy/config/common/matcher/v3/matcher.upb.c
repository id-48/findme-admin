/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/config/common/matcher/v3/matcher.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/msg_internal.h"
#include "envoy/config/common/matcher/v3/matcher.upb.h"
#include "envoy/config/core/v3/extension.upb.h"
#include "envoy/config/route/v3/route_components.upb.h"
#include "envoy/type/matcher/v3/string.upb.h"
#include "xds/annotations/v3/status.upb.h"
#include "udpa/annotations/status.upb.h"
#include "validate/validate.upb.h"

#include "upb/port_def.inc"

static const upb_MiniTable_Sub envoy_config_common_matcher_v3_Matcher_submsgs[3] = {
        {.submsg = &envoy_config_common_matcher_v3_Matcher_MatcherList_msginit},
        {.submsg = &envoy_config_common_matcher_v3_Matcher_MatcherTree_msginit},
        {.submsg = &envoy_config_common_matcher_v3_Matcher_OnMatch_msginit},
};

static const upb_MiniTable_Field envoy_config_common_matcher_v3_Matcher__fields[3] = {
        {1, UPB_SIZE(12, 16), UPB_SIZE(-5, -5), 0, 11,
                                                       kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(12, 16), UPB_SIZE(-5, -5), 1, 11, kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
        {3, UPB_SIZE(8, 8),   UPB_SIZE(1, 1),   2, 11, kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_common_matcher_v3_Matcher_msginit = {
        &envoy_config_common_matcher_v3_Matcher_submsgs[0],
        &envoy_config_common_matcher_v3_Matcher__fields[0],
        UPB_SIZE(16, 24), 3, kUpb_ExtMode_NonExtendable, 3, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_common_matcher_v3_Matcher_OnMatch_submsgs[2] = {
        {.submsg = &envoy_config_common_matcher_v3_Matcher_msginit},
        {.submsg = &envoy_config_core_v3_TypedExtensionConfig_msginit},
};

static const upb_MiniTable_Field envoy_config_common_matcher_v3_Matcher_OnMatch__fields[2] = {
        {1, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 0, 11,
                                                     kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer
                                                             << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 1, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer
                << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_common_matcher_v3_Matcher_OnMatch_msginit = {
        &envoy_config_common_matcher_v3_Matcher_OnMatch_submsgs[0],
        &envoy_config_common_matcher_v3_Matcher_OnMatch__fields[0],
        UPB_SIZE(8, 16), 2, kUpb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_common_matcher_v3_Matcher_MatcherList_submsgs[1] = {
        {.submsg = &envoy_config_common_matcher_v3_Matcher_MatcherList_FieldMatcher_msginit},
};

static const upb_MiniTable_Field envoy_config_common_matcher_v3_Matcher_MatcherList__fields[1] = {
        {1, UPB_SIZE(0, 0), UPB_SIZE(0, 0), 0, 11,
         kUpb_FieldMode_Array | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_common_matcher_v3_Matcher_MatcherList_msginit = {
        &envoy_config_common_matcher_v3_Matcher_MatcherList_submsgs[0],
        &envoy_config_common_matcher_v3_Matcher_MatcherList__fields[0],
        UPB_SIZE(8, 8), 1, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_common_matcher_v3_Matcher_MatcherList_Predicate_submsgs[4] = {
        {.submsg = &envoy_config_common_matcher_v3_Matcher_MatcherList_Predicate_SinglePredicate_msginit},
        {.submsg = &envoy_config_common_matcher_v3_Matcher_MatcherList_Predicate_PredicateList_msginit},
        {.submsg = &envoy_config_common_matcher_v3_Matcher_MatcherList_Predicate_PredicateList_msginit},
        {.submsg = &envoy_config_common_matcher_v3_Matcher_MatcherList_Predicate_msginit},
};

static const upb_MiniTable_Field envoy_config_common_matcher_v3_Matcher_MatcherList_Predicate__fields[4] = {
        {1, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 0, 11,
                                                     kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer
                                                             << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 1, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer
                << kUpb_FieldRep_Shift)},
        {3, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 2, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer
                << kUpb_FieldRep_Shift)},
        {4, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 3, 11, kUpb_FieldMode_Scalar | (kUpb_FieldRep_Pointer
                << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_common_matcher_v3_Matcher_MatcherList_Predicate_msginit = {
        &envoy_config_common_matcher_v3_Matcher_MatcherList_Predicate_submsgs[0],
        &envoy_config_common_matcher_v3_Matcher_MatcherList_Predicate__fields[0],
        UPB_SIZE(8, 16), 4, kUpb_ExtMode_NonExtendable, 4, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_common_matcher_v3_Matcher_MatcherList_Predicate_SinglePredicate_submsgs[3] = {
        {.submsg = &envoy_config_core_v3_TypedExtensionConfig_msginit},
        {.submsg = &envoy_type_matcher_v3_StringMatcher_msginit},
        {.submsg = &envoy_config_core_v3_TypedExtensionConfig_msginit},
};

static const upb_MiniTable_Field envoy_config_common_matcher_v3_Matcher_MatcherList_Predicate_SinglePredicate__fields[3] = {
        {1, UPB_SIZE(8, 8),   UPB_SIZE(1, 1),   0, 11,
                                                       kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(12, 16), UPB_SIZE(-5, -5), 1, 11, kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
        {3, UPB_SIZE(12, 16), UPB_SIZE(-5, -5), 2, 11, kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_common_matcher_v3_Matcher_MatcherList_Predicate_SinglePredicate_msginit = {
        &envoy_config_common_matcher_v3_Matcher_MatcherList_Predicate_SinglePredicate_submsgs[0],
        &envoy_config_common_matcher_v3_Matcher_MatcherList_Predicate_SinglePredicate__fields[0],
        UPB_SIZE(16, 24), 3, kUpb_ExtMode_NonExtendable, 3, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_common_matcher_v3_Matcher_MatcherList_Predicate_PredicateList_submsgs[1] = {
        {.submsg = &envoy_config_common_matcher_v3_Matcher_MatcherList_Predicate_msginit},
};

static const upb_MiniTable_Field envoy_config_common_matcher_v3_Matcher_MatcherList_Predicate_PredicateList__fields[1] = {
        {1, UPB_SIZE(0, 0), UPB_SIZE(0, 0), 0, 11,
         kUpb_FieldMode_Array | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_common_matcher_v3_Matcher_MatcherList_Predicate_PredicateList_msginit = {
        &envoy_config_common_matcher_v3_Matcher_MatcherList_Predicate_PredicateList_submsgs[0],
        &envoy_config_common_matcher_v3_Matcher_MatcherList_Predicate_PredicateList__fields[0],
        UPB_SIZE(8, 8), 1, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_common_matcher_v3_Matcher_MatcherList_FieldMatcher_submsgs[2] = {
        {.submsg = &envoy_config_common_matcher_v3_Matcher_MatcherList_Predicate_msginit},
        {.submsg = &envoy_config_common_matcher_v3_Matcher_OnMatch_msginit},
};

static const upb_MiniTable_Field envoy_config_common_matcher_v3_Matcher_MatcherList_FieldMatcher__fields[2] = {
        {1, UPB_SIZE(4, 8),  UPB_SIZE(1, 1), 0, 11,
                                                    kUpb_FieldMode_Scalar |
                                                    (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(8, 16), UPB_SIZE(2, 2), 1, 11, kUpb_FieldMode_Scalar |
                                                    (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_common_matcher_v3_Matcher_MatcherList_FieldMatcher_msginit = {
        &envoy_config_common_matcher_v3_Matcher_MatcherList_FieldMatcher_submsgs[0],
        &envoy_config_common_matcher_v3_Matcher_MatcherList_FieldMatcher__fields[0],
        UPB_SIZE(16, 24), 2, kUpb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_common_matcher_v3_Matcher_MatcherTree_submsgs[4] = {
        {.submsg = &envoy_config_core_v3_TypedExtensionConfig_msginit},
        {.submsg = &envoy_config_common_matcher_v3_Matcher_MatcherTree_MatchMap_msginit},
        {.submsg = &envoy_config_common_matcher_v3_Matcher_MatcherTree_MatchMap_msginit},
        {.submsg = &envoy_config_core_v3_TypedExtensionConfig_msginit},
};

static const upb_MiniTable_Field envoy_config_common_matcher_v3_Matcher_MatcherTree__fields[4] = {
        {1, UPB_SIZE(8, 8),   UPB_SIZE(1, 1),   0, 11,
                                                       kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(12, 16), UPB_SIZE(-5, -5), 1, 11, kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
        {3, UPB_SIZE(12, 16), UPB_SIZE(-5, -5), 2, 11, kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
        {4, UPB_SIZE(12, 16), UPB_SIZE(-5, -5), 3, 11, kUpb_FieldMode_Scalar |
                                                       (kUpb_FieldRep_Pointer
                                                               << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_common_matcher_v3_Matcher_MatcherTree_msginit = {
        &envoy_config_common_matcher_v3_Matcher_MatcherTree_submsgs[0],
        &envoy_config_common_matcher_v3_Matcher_MatcherTree__fields[0],
        UPB_SIZE(16, 24), 4, kUpb_ExtMode_NonExtendable, 4, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_common_matcher_v3_Matcher_MatcherTree_MatchMap_submsgs[1] = {
        {.submsg = &envoy_config_common_matcher_v3_Matcher_MatcherTree_MatchMap_MapEntry_msginit},
};

static const upb_MiniTable_Field envoy_config_common_matcher_v3_Matcher_MatcherTree_MatchMap__fields[1] = {
        {1, UPB_SIZE(0, 0), UPB_SIZE(0, 0), 0, 11,
         kUpb_FieldMode_Map | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_common_matcher_v3_Matcher_MatcherTree_MatchMap_msginit = {
        &envoy_config_common_matcher_v3_Matcher_MatcherTree_MatchMap_submsgs[0],
        &envoy_config_common_matcher_v3_Matcher_MatcherTree_MatchMap__fields[0],
        UPB_SIZE(8, 8), 1, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_common_matcher_v3_Matcher_MatcherTree_MatchMap_MapEntry_submsgs[1] = {
        {.submsg = &envoy_config_common_matcher_v3_Matcher_OnMatch_msginit},
};

static const upb_MiniTable_Field envoy_config_common_matcher_v3_Matcher_MatcherTree_MatchMap_MapEntry__fields[2] = {
        {1, UPB_SIZE(0, 0),  UPB_SIZE(0, 0), kUpb_NoSub, 12,
                                                             kUpb_FieldMode_Scalar |
                                                             (kUpb_FieldRep_1Byte
                                                                     << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(8, 16), UPB_SIZE(0, 0), 0,          11, kUpb_FieldMode_Scalar |
                                                             (kUpb_FieldRep_1Byte
                                                                     << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_common_matcher_v3_Matcher_MatcherTree_MatchMap_MapEntry_msginit = {
        &envoy_config_common_matcher_v3_Matcher_MatcherTree_MatchMap_MapEntry_submsgs[0],
        &envoy_config_common_matcher_v3_Matcher_MatcherTree_MatchMap_MapEntry__fields[0],
        UPB_SIZE(16, 32), 2, kUpb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_common_matcher_v3_MatchPredicate_submsgs[9] = {
        {.submsg = &envoy_config_common_matcher_v3_MatchPredicate_MatchSet_msginit},
        {.submsg = &envoy_config_common_matcher_v3_MatchPredicate_MatchSet_msginit},
        {.submsg = &envoy_config_common_matcher_v3_MatchPredicate_msginit},
        {.submsg = &envoy_config_common_matcher_v3_HttpHeadersMatch_msginit},
        {.submsg = &envoy_config_common_matcher_v3_HttpHeadersMatch_msginit},
        {.submsg = &envoy_config_common_matcher_v3_HttpHeadersMatch_msginit},
        {.submsg = &envoy_config_common_matcher_v3_HttpHeadersMatch_msginit},
        {.submsg = &envoy_config_common_matcher_v3_HttpGenericBodyMatch_msginit},
        {.submsg = &envoy_config_common_matcher_v3_HttpGenericBodyMatch_msginit},
};

static const upb_MiniTable_Field envoy_config_common_matcher_v3_MatchPredicate__fields[10] = {
        {1,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 0,          11,
                                                               kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_Pointer
                                                                       << kUpb_FieldRep_Shift)},
        {2,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 1,          11, kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_Pointer
                                                                       << kUpb_FieldRep_Shift)},
        {3,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), 2,          11, kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_Pointer
                                                                       << kUpb_FieldRep_Shift)},
        {4,  UPB_SIZE(4, 8), UPB_SIZE(-1, -1), kUpb_NoSub, 8,  kUpb_FieldMode_Scalar |
                                                               (kUpb_FieldRep_1Byte
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
};

const upb_MiniTable envoy_config_common_matcher_v3_MatchPredicate_msginit = {
        &envoy_config_common_matcher_v3_MatchPredicate_submsgs[0],
        &envoy_config_common_matcher_v3_MatchPredicate__fields[0],
        UPB_SIZE(8, 16), 10, kUpb_ExtMode_NonExtendable, 10, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_common_matcher_v3_MatchPredicate_MatchSet_submsgs[1] = {
        {.submsg = &envoy_config_common_matcher_v3_MatchPredicate_msginit},
};

static const upb_MiniTable_Field envoy_config_common_matcher_v3_MatchPredicate_MatchSet__fields[1] = {
        {1, UPB_SIZE(0, 0), UPB_SIZE(0, 0), 0, 11,
         kUpb_FieldMode_Array | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_common_matcher_v3_MatchPredicate_MatchSet_msginit = {
        &envoy_config_common_matcher_v3_MatchPredicate_MatchSet_submsgs[0],
        &envoy_config_common_matcher_v3_MatchPredicate_MatchSet__fields[0],
        UPB_SIZE(8, 8), 1, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_common_matcher_v3_HttpHeadersMatch_submsgs[1] = {
        {.submsg = &envoy_config_route_v3_HeaderMatcher_msginit},
};

static const upb_MiniTable_Field envoy_config_common_matcher_v3_HttpHeadersMatch__fields[1] = {
        {1, UPB_SIZE(0, 0), UPB_SIZE(0, 0), 0, 11,
         kUpb_FieldMode_Array | (kUpb_FieldRep_Pointer << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_common_matcher_v3_HttpHeadersMatch_msginit = {
        &envoy_config_common_matcher_v3_HttpHeadersMatch_submsgs[0],
        &envoy_config_common_matcher_v3_HttpHeadersMatch__fields[0],
        UPB_SIZE(8, 8), 1, kUpb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable_Sub envoy_config_common_matcher_v3_HttpGenericBodyMatch_submsgs[1] = {
        {.submsg = &envoy_config_common_matcher_v3_HttpGenericBodyMatch_GenericTextMatch_msginit},
};

static const upb_MiniTable_Field envoy_config_common_matcher_v3_HttpGenericBodyMatch__fields[2] = {
        {1, UPB_SIZE(0, 0), UPB_SIZE(0, 0), kUpb_NoSub, 13,
                                                            kUpb_FieldMode_Scalar |
                                                            (kUpb_FieldRep_4Byte
                                                                    << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(4, 8), UPB_SIZE(0, 0), 0,          11, kUpb_FieldMode_Array |
                                                            (kUpb_FieldRep_Pointer
                                                                    << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_common_matcher_v3_HttpGenericBodyMatch_msginit = {
        &envoy_config_common_matcher_v3_HttpGenericBodyMatch_submsgs[0],
        &envoy_config_common_matcher_v3_HttpGenericBodyMatch__fields[0],
        UPB_SIZE(8, 16), 2, kUpb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable_Field envoy_config_common_matcher_v3_HttpGenericBodyMatch_GenericTextMatch__fields[2] = {
        {1, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), kUpb_NoSub, 9,
                                                              kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_StringView
                                                                      << kUpb_FieldRep_Shift)},
        {2, UPB_SIZE(4, 8), UPB_SIZE(-1, -1), kUpb_NoSub, 12, kUpb_FieldMode_Scalar |
                                                              (kUpb_FieldRep_StringView
                                                                      << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_common_matcher_v3_HttpGenericBodyMatch_GenericTextMatch_msginit = {
        NULL,
        &envoy_config_common_matcher_v3_HttpGenericBodyMatch_GenericTextMatch__fields[0],
        UPB_SIZE(16, 24), 2, kUpb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable *messages_layout[15] = {
        &envoy_config_common_matcher_v3_Matcher_msginit,
        &envoy_config_common_matcher_v3_Matcher_OnMatch_msginit,
        &envoy_config_common_matcher_v3_Matcher_MatcherList_msginit,
        &envoy_config_common_matcher_v3_Matcher_MatcherList_Predicate_msginit,
        &envoy_config_common_matcher_v3_Matcher_MatcherList_Predicate_SinglePredicate_msginit,
        &envoy_config_common_matcher_v3_Matcher_MatcherList_Predicate_PredicateList_msginit,
        &envoy_config_common_matcher_v3_Matcher_MatcherList_FieldMatcher_msginit,
        &envoy_config_common_matcher_v3_Matcher_MatcherTree_msginit,
        &envoy_config_common_matcher_v3_Matcher_MatcherTree_MatchMap_msginit,
        &envoy_config_common_matcher_v3_Matcher_MatcherTree_MatchMap_MapEntry_msginit,
        &envoy_config_common_matcher_v3_MatchPredicate_msginit,
        &envoy_config_common_matcher_v3_MatchPredicate_MatchSet_msginit,
        &envoy_config_common_matcher_v3_HttpHeadersMatch_msginit,
        &envoy_config_common_matcher_v3_HttpGenericBodyMatch_msginit,
        &envoy_config_common_matcher_v3_HttpGenericBodyMatch_GenericTextMatch_msginit,
};

const upb_MiniTable_File envoy_config_common_matcher_v3_matcher_proto_upb_file_layout = {
        messages_layout,
        NULL,
        NULL,
        15,
        0,
        0,
};

#include "upb/port_undef.inc"

