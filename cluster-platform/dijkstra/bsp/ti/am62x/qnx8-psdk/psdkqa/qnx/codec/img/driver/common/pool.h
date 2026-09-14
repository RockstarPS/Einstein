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
 * Object Pool Memory Allocator header
 */
#ifndef _pool_h_
#define _pool_h_

#include "osal/inc/osa_types.h"
struct pool;

/*
 * @Function	pool_create
 * @Description
 * Create an sObject pool
 * @Input	name : Name of sObject pool for diagnostic purposes
 * @Input	obj_size : size of each sObject in the pool in bytes
 * @Output	pool : Will contain NULL or sObject pool handle
 * @Return	IMG_SUCCESS or an error code.
 */
int32 pool_create(const uint8 * const name,
		uint32 obj_size,
		struct pool ** const pool);

/*
 * @Function	pool_delete
 * @Description
 * Delete an sObject pool. All psObjects allocated from the pool must
 * be free'd with pool_free() before deleting the sObject pool.
 * @Input	pool : Object Pool pointer
 * @Return IMG_SUCCESS or an error code.
 */
int32 pool_delete(struct pool * const pool);

/*
 * @Function	pool_alloc
 * @Description
 * Allocate an Object from an Object pool.
 * @Input	pool : Object Pool
 * @Output	obj_hdnl : Pointer containing the handle to the
 * object created or IMG_NULL
 * @Return    IMG_SUCCESS or an error code.
 */
int32 pool_alloc(struct pool * const pool,
	       void ** const obj_hdnl);

/*
 * @Function	pool_free
 * @Description
 * Free an sObject previously allocated from an sObject pool.
 * @Input	pool : Object Pool pointer.
 * @Output	obj_hdnl : Handle to the object to be freed.
 * @Return	IMG_SUCCESS or an error code.
 */
int32 pool_free(struct pool * const pool,
	      void * const obj_hdnl);

#endif /* _pool_h_ */
