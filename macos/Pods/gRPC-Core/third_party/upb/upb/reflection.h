/*
 * Copyright (c) 2009-2021, Google LLC
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Google LLC nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL Google LLC BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef UPB_REFLECTION_H_
#define UPB_REFLECTION_H_

#include "upb/array.h"
#include "upb/def.h"
#include "upb/map.h"
#include "upb/msg.h"
#include "upb/port_def.inc"
#include "upb/upb.h"

#ifdef __cplusplus
extern "C" {
#endif

upb_MessageValue upb_FieldDef_Default(const upb_FieldDef *f);

/** upb_Message
 * *******************************************************************/

/* Creates a new message of the given type in the given arena. */
upb_Message *upb_Message_New(const upb_MessageDef *m, upb_Arena *a);

/* Returns the value associated with this field. */
upb_MessageValue upb_Message_Get(const upb_Message *msg, const upb_FieldDef *f);

/* Returns a mutable pointer to a map, array, or submessage value.  If the given
 * arena is non-NULL this will construct a new object if it was not previously
 * present.  May not be called for primitive fields. */
upb_MutableMessageValue upb_Message_Mutable(upb_Message *msg,
                                            const upb_FieldDef *f,
                                            upb_Arena *a);

/* May only be called for fields where upb_FieldDef_HasPresence(f) == true. */
bool upb_Message_Has(const upb_Message *msg, const upb_FieldDef *f);

/* Returns the field that is set in the oneof, or NULL if none are set. */
const upb_FieldDef *upb_Message_WhichOneof(const upb_Message *msg,
                                           const upb_OneofDef *o);

/* Sets the given field to the given value.  For a msg/array/map/string, the
 * caller must ensure that the target data outlives |msg| (by living either in
 * the same arena or a different arena that outlives it).
 *
 * Returns false if allocation fails. */
bool upb_Message_Set(upb_Message *msg, const upb_FieldDef *f,
                     upb_MessageValue val, upb_Arena *a);

/* Clears any field presence and sets the value back to its default. */
void upb_Message_ClearField(upb_Message *msg, const upb_FieldDef *f);

/* Clear all data and unknown fields. */
void upb_Message_Clear(upb_Message *msg, const upb_MessageDef *m);

/* Iterate over present fields.
 *
 * size_t iter = kUpb_Message_Begin;
 * const upb_FieldDef *f;
 * upb_MessageValue val;
 * while (upb_Message_Next(msg, m, ext_pool, &f, &val, &iter)) {
 *   process_field(f, val);
 * }
 *
 * If ext_pool is NULL, no extensions will be returned.  If the given symtab
 * returns extensions that don't match what is in this message, those extensions
 * will be skipped.
 */

#define kUpb_Message_Begin -1

bool upb_Message_Next(const upb_Message *msg, const upb_MessageDef *m,
                      const upb_DefPool *ext_pool, const upb_FieldDef **f,
                      upb_MessageValue *val, size_t *iter);

/* Clears all unknown field data from this message and all submessages. */
bool upb_Message_DiscardUnknown(upb_Message *msg, const upb_MessageDef *m,
                                int maxdepth);

#ifdef __cplusplus
} /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif /* UPB_REFLECTION_H_ */
