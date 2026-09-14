/*****************************************************************************
*
* Copyright (c) Imagination Technologies Ltd.
* Copyright (c) 2018-22 Texas Instruments Incorporated - http://www.ti.com/
*
* The contents of this file are subject to the MIT license as set out below.
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHERa
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
* Alternatively, the contents of this file may be used under the terms of the
* GNU General Public License Version 2 ("GPL")in which case the provisions of
* GPL are applicable instead of those above.
*
* If you wish to allow use of your version of this file only under the terms
* of GPL, and not to allow others to use your version of this file under the
* terms of the MIT license, indicate your decision by deleting the provisions
* above and replace them with the notice and other provisions required by GPL
* as set out in the file called "GPLHEADER" included in this distribution. If
* you do not delete the provisions above, a recipient may use your version of
* this file under the terms of either the MIT license or GPL.
*
* This License is also included in this distribution in the file called
* "MIT_COPYING".
*
*****************************************************************************/
/*
 * osa idr definitions
 */

#ifndef OSA_IDR_H_
#define OSA_IDR_H_

#include "osa_types.h"
/**
 * osa_idr_alloc() - Allocate an ID.
 * @idr: IDR handle.
 * @ptr: Pointer to be associated with the new ID.
 * @start: The minimum ID (inclusive).
 * @end: The maximum ID (exclusive).
 *
 * Allocates an unused ID in the range specified by @start and @end.  If
 * @end is <= 0, it is treated as one larger than %INT_MAX.  This allows
 * callers to use @start + N as @end as long as N is within integer range.
 *
 * The caller should provide their own locking to ensure that two
 * concurrent modifications to the IDR are not possible.  Read-only
 * accesses to the IDR may be done under the RCU read lock or may
 * exclude simultaneous writers.
 *
 * Return: The newly allocated ID, -ENOMEM if memory allocation failed,
 * or -ENOSPC if no free IDs could be found.
 */
int32 osa_idr_alloc(void *idr, void *ptr, int32 start, int32 end);


/**
 * osa_idr_alloc_cyclic() - Allocate an ID cyclically.
 * @idr: IDR handle.
 * @ptr: Pointer to be associated with the new ID.
 * @start: The minimum ID (inclusive).
 * @end: The maximum ID (exclusive).
 *
 * Allocates an unused ID in the range specified by @nextid and @end.  If
 * @end is <= 0, it is treated as one larger than %INT_MAX.  This allows
 * callers to use @start + N as @end as long as N is within integer range.
 * The search for an unused ID will start at the last ID allocated and will
 * wrap around to @start if no free IDs are found before reaching @end.
 *
 * The caller should provide their own locking to ensure that two
 * concurrent modifications to the IDR are not possible.  Read-only
 * accesses to the IDR may be done under the RCU read lock or may
 * exclude simultaneous writers.
 *
 * Return: The newly allocated ID, -ENOMEM if memory allocation failed,
 * or -ENOSPC if no free IDs could be found.
 */
int32 osa_idr_alloc_cyclic(void *idr, void *ptr, int32 start, int32 end);


/**
 * osa_osa_idr_remove() - Remove an ID from the IDR.
 * @idr: IDR handle.
 * @id: Pointer ID.
 *
 * Removes this ID from the IDR.  If the ID was not previously in the IDR,
 * this function returns %NULL.
 *
 * Since this function modifies the IDR, the caller should provide their
 * own locking to ensure that concurrent modification of the same IDR is
 * not possible.
 *
 * Return: The pointer formerly associated with this ID.
 */
void *osa_idr_remove(void *idr, int32 id);


/**
 * osa_osa_idr_find() - Return pointer for given ID.
 * @idr: IDR handle.
 * @id: Pointer ID.
 *
 * Looks up the pointer associated with this ID.  A %NULL pointer may
 * indicate that @id is not allocated or that the %NULL pointer was
 * associated with this ID.
 *
 * This function can be called under rcu_read_lock(), given that the leaf
 * pointers lifetimes are correctly managed.
 *
 * Return: The pointer associated with this ID.
 */
void *osa_idr_find(void *idr, int32 id);


/**
 * osa_osa_idr_get_next() - Find next populated entry.
 * @idr: IDR handle.
 * @nextid: Pointer to an ID.
 *
 * Returns the next populated entry in the tree with an ID greater than
 * or equal to the value pointed to by @nextid.  On exit, @nextid is updated
 * to the ID of the found value.  To use in a loop, the value pointed to by
 * nextid must be incremented by the user.
 */
void *osa_idr_get_next(void *idr, int32 *nextid);


/**
 * osa_osa_idr_destroy - release all internal memory from an IDR
 * @idr: idr handle
 *
 * After this function is called, the IDR is empty, and may be reused or
 * the data structure containing it may be freed.
 */
void osa_idr_destroy(void *idr);


/**
 * osa_osa_idr_init() - Initialise an IDR.
 * @idr: IDR handle.
 *
 * Initialise a dynamically allocated IDR.
 */
void osa_idr_init(void **idr);

#endif /* OSA_IDR_H_ */
