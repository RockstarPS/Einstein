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
 * Self scaling hash tables.
 */
#ifndef _HASH_H_
#define _HASH_H_

#include "osal/inc/osa_types.h"
struct hash;

/*
 * @Function	VID_HASH_Initialise
 * @Description
 * To initialise the hash module.
 * @Input	 None
 * @Return	IMG_SUCCESS or an error code.
 */
int32 vid_hash_initialise(void);

/*
 * @Function	VID_HASH_Finalise
 * @Description
 * To finalise the hash module. All allocated hash tables should
 * be deleted before calling this function.
 * @Input	None
 * @Return	IMG_SUCCESS or an error code.
 */
int32 vid_hash_finalise(void);

/*
 * @Function	VID_HASH_Create
 * @Description
 * Create a self scaling hash table.
 * @Input	initial_size : Initial and minimum size of the hash table.
 * @Output	hash : Hash table handle or NULL.
 * @Return	IMG_SUCCESS or an error code.
 */
int32 vid_hash_create(uint32 initial_size,
		    struct hash ** const hash_hndl);

/*
 * @Function	VID_HASH_Delete
 * @Description
 * To delete a hash table, all entries in the table should be
 * removed before calling this function.
 * @Input	hash : Hash table pointer
 * @Return	IMG_SUCCESS or an error code.
 */
int32 vid_hash_delete(struct hash * const ps_hash);

/*
 * @Function	VID_HASH_Insert
 * @Description
 * To insert a key value pair into a hash table.
 * @Input	ps_hash : Hash table pointer
 * @Input	key : Key value
 * @Input	value : The value associated with the key.
 * @Return	IMG_SUCCESS or an error code.
 */
int32 vid_hash_insert(struct hash * const ps_hash,
		    uint64 key,
		    uint64 value);

/*
 * @Function	VID_HASH_Remove
 * @Description
 * To remove a key value pair from a hash table
 * @Input	ps_hash : Hash table pointer
 * @Input	key : Key value
 * @Input	result : 0 if the key is missing or the value
 *		associated with the key.
 * @Return	IMG_SUCCESS or an error code.
 */
int32 vid_hash_remove(struct hash * const ps_hash,
		    uint64 key,
		    ulong * const result);

#endif /* _HASH_H_ */

