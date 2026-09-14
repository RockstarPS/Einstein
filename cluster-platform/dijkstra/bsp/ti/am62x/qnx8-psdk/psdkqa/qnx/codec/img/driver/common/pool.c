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
 * Object Pool Memory Allocator
 */

#include "osal/inc/osa_mem.h"
#include "osal/inc/osa_define.h"
#include "img_errors.h"
#include "pool.h"

#define BUFF_MAX_SIZE 4096
#define BUFF_MAX_GROW 32

/* 64 bits */
#define ALIGN_SIZE (sizeof(int64) - 1)

struct pool {
	uint8 *name;
	uint32 size;
	uint32 grow;
	struct buffer *buffers;
	struct object *objects;
};

struct buffer {
	struct buffer *next;
};

struct object {
	struct object *next;
};

static inline uint8 *strdup_cust(const uint8 *str)
{
	uint8 *r = osa_malloc(strlen((const char *)str) + 1, OSA_GFP_KERNEL);

	if (r)
		strcpy((char *)r, (const char *)str);
	return r;
}

/*
 * @Function	pool_create
 * @Description
 * Create an sObject pool
 * @Input	name : Name of sObject pool for diagnostic purposes
 * @Input	obj_size : size of each sObject in the pool in bytes
 * @Output	pps_pool : Will contain NULL or sObject pool handle
 * @Return	IMG_SUCCESS or an error code.
 */
int32 pool_create(const uint8 * const name,
		uint32 obj_size,
		struct pool ** const pool_hdnl)
{
	struct pool *local_pool = NULL;
	uint32 result = IMG_ERROR_FATAL;

	if (!name || !pool_hdnl) {
		result = IMG_ERROR_INVALID_PARAMETERS;
		return result;
	}

	local_pool = osa_malloc((sizeof(*local_pool)), OSA_GFP_KERNEL);
	if (!local_pool) {
		result = IMG_ERROR_INVALID_PARAMETERS;
		return result;
	}

	local_pool->name = strdup_cust((uint8 *)name);
	local_pool->size = obj_size;
	local_pool->buffers = NULL;
	local_pool->objects = NULL;
	local_pool->grow =
		(BUFF_MAX_SIZE - sizeof(struct buffer)) /
		(obj_size + ALIGN_SIZE);

	if (local_pool->grow == 0)
		local_pool->grow = 1;
	else if (local_pool->grow > BUFF_MAX_GROW)
		local_pool->grow = BUFF_MAX_GROW;

	*pool_hdnl = local_pool;
	result = IMG_SUCCESS;

	return result;
}

/*
 * @Function	pool_delete
 * @Description
 * Delete an sObject pool. All psObjects allocated from the pool must
 * be free'd with pool_free() before deleting the sObject pool.
 * @Input	pool : Object Pool pointer
 * @Return IMG_SUCCESS or an error code.
 */
int32 pool_delete(struct pool * const pool_arg)
{
	struct buffer *local_buf = NULL;
	uint32 result = IMG_ERROR_FATAL;

	if (!pool_arg) {
		result = IMG_ERROR_INVALID_PARAMETERS;
		return result;
	}

	local_buf = pool_arg->buffers;
	while (local_buf) {
		local_buf = local_buf->next;
		osa_free(pool_arg->buffers);
		pool_arg->buffers = local_buf;
	}

	osa_free(pool_arg->name);
	pool_arg->name = NULL;

	osa_free(pool_arg);
	result = IMG_SUCCESS;

	return result;
}

/*
 * @Function	pool_alloc
 * @Description
 * Allocate an sObject from an sObject pool.
 * @Input	pool_arg : Object Pool
 * @Output	obj_hndl : Pointer containing the handle to the
 * object created or IMG_NULL
 * @Return    IMG_SUCCESS or an error code.
 */
int32 pool_alloc(struct pool * const pool_arg,
	       void ** const obj_hndl)
{
	struct object *local_obj1 = NULL;
	struct buffer *local_buf = NULL;
	uint32 idx = 0;
	uint32 sz = 0;
	uint32 result = IMG_ERROR_FATAL;

	if (!pool_arg || !obj_hndl) {
		result = IMG_ERROR_INVALID_PARAMETERS;
		return result;
	}

	if (!pool_arg->objects) {
		sz = (pool_arg->size + ALIGN_SIZE);
		sz *= (pool_arg->grow + sizeof(struct buffer));
		local_buf = osa_malloc(sz, OSA_GFP_KERNEL);
		if (!local_buf) {
			result = IMG_ERROR_MALLOC_FAILED;
			return result;
		}

		local_buf->next = pool_arg->buffers;
		pool_arg->buffers = local_buf;

		for (idx = 0; idx < pool_arg->grow; idx++) {
			struct object *local_obj2;
			uint8 *temp_ptr = NULL;

			local_obj2 = (struct object *)(((uint8 *)(local_buf + 1))
				+ (idx * (pool_arg->size + ALIGN_SIZE)));

			temp_ptr = (uint8 *)local_obj2;
			if ((uintptr_t)temp_ptr & ALIGN_SIZE) {
				temp_ptr += ((ALIGN_SIZE + 1)
					- ((uintptr_t)temp_ptr & ALIGN_SIZE));
				local_obj2 = (struct object *)temp_ptr;
			}

			local_obj2->next = pool_arg->objects;
			pool_arg->objects = local_obj2;
		}
	}

	if (!pool_arg->objects) {
		result = IMG_ERROR_UNEXPECTED_STATE;
		return result;
	}

	local_obj1 = pool_arg->objects;
	pool_arg->objects = local_obj1->next;

	*obj_hndl = (void *)(local_obj1);
	result = IMG_SUCCESS;

	return result;
}

/*
 * @Function	pool_free
 * @Description
 * Free an sObject previously allocated from an sObject pool.
 * @Input	pool_arg : Object Pool pointer.
 * @Output	h_object : Handle to the object to be freed.
 * @Return	IMG_SUCCESS or an error code.
 */
int32 pool_free(struct pool * const pool_arg,
	      void * const obj_hndl)
{
	struct object *object = NULL;
	uint32 result = IMG_ERROR_FATAL;

	if (!pool_arg || !obj_hndl) {
		result = IMG_ERROR_INVALID_PARAMETERS;
		return result;
	}

	object = (struct object *)obj_hndl;
	object->next = pool_arg->objects;
	pool_arg->objects = object;

	result = IMG_SUCCESS;

	return result;
}
