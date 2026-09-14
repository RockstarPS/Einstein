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
 * This component is used to track decoder resources,
 * and share them across other components.
 */

#include "osal/inc/osa_mem.h"
#include "osal/inc/osa_mutex.h"
#include "osal/inc/osa_define.h"
#include "dq.h"
#include "idgen_api.h"
#include "rman_api.h"

/*
 * The following macros are used to build/decompose the composite resource Id
 * made up from the bucket index + 1 and the allocated resource Id.
 */
#define RMAN_CRESID_BUCKET_INDEX_BITS	(8)
#define RMAN_CRESID_RES_ID_BITS		(32 - RMAN_CRESID_BUCKET_INDEX_BITS)
#define RMAN_CRESID_MAX_RES_ID		((1 << RMAN_CRESID_RES_ID_BITS) - 1)
#define RMAN_CRESID_RES_ID_MASK		(RMAN_CRESID_MAX_RES_ID)
#define RMAN_CRESID_BUCKET_SHIFT	(RMAN_CRESID_RES_ID_BITS)
#define RMAN_CRESID_MAX_BUCKET_INDEX	\
			((1 << RMAN_CRESID_BUCKET_INDEX_BITS) - 1)

#define RMAN_MAX_ID		4096
#define RMAN_ID_BLOCKSIZE	256

/* global state variable */
static uint8 inited = 0;
static struct rman_bucket *bucket_array[RMAN_CRESID_MAX_BUCKET_INDEX] = {0};
static struct rman_bucket *global_res_bucket = NULL;
static struct rman_bucket *shared_res_bucket = NULL;
static void *shared_res_mutex_handle = NULL;
static void *global_mutex = NULL;

/*
 * This structure contains the bucket information.
 */
struct rman_bucket {
	void		**link; /* to be part of single linked list */
	struct dq_linkage_t	res_list;
	uint32		bucket_idx;
	void		*id_gen;
	uint32		res_cnt;
};

/*
 * This structure contains the resource details for a resource registered with
 * the resource manager.
 */
struct rman_res {
	struct dq_linkage_t	link; /* to be part of double linked list */
	struct rman_bucket	*bucket;
	uint32			type_id;
	rman_fn_free		fn_free;
	void			*param;
	uint32			res_id;
	void *mutex_handle; /*resource mutex */
	uint8			*res_name;
	struct rman_res		*shared_res;
	uint32			ref_cnt;
};

/*
 * initialization
 */
int32 rman_initialise(void)
{
	uint32 ret;

	if (!inited) {
		osa_mutex_create(&shared_res_mutex_handle);
		if(NULL == shared_res_mutex_handle)
		{
			return IMG_ERROR_OUT_OF_MEMORY;
		}

		/* Set initialised flag */
		inited = osa_true;

		/* Create the global resource bucket */
		ret = rman_create_bucket((void **)&global_res_bucket);
		IMG_DBG_ASSERT(ret == IMG_SUCCESS);
		if (ret != IMG_SUCCESS)
			return ret;

		/* Create the shared resource bucket */
		ret = rman_create_bucket((void **)&shared_res_bucket);
		IMG_DBG_ASSERT(ret == IMG_SUCCESS);
		if (ret != IMG_SUCCESS)
			return ret;


		osa_mutex_create(&global_mutex);
		if(NULL == global_mutex)
		{
			return IMG_ERROR_OUT_OF_MEMORY;
		}
	}
	return IMG_SUCCESS;
}

/*
 * deinitialization
 */
void rman_deinitialise(void)
{
	uint32	i;

	if (inited) {
		/* Destroy the golbal resource bucket */
		rman_destroy_bucket(global_res_bucket);

		/* Destroy the shared resource bucket */
		rman_destroy_bucket(shared_res_bucket);

		/* Make sure we destroy the mutex after destroying the bucket */
		osa_mutex_destroy(&global_mutex);
		global_mutex = NULL;

		/* Destroy mutex */
		osa_mutex_destroy(&shared_res_mutex_handle);
		shared_res_mutex_handle = NULL;

		/* Check all buckets destroyed */
		for (i = 0; i < RMAN_CRESID_MAX_BUCKET_INDEX; i++)
			IMG_DBG_ASSERT(!bucket_array[i]);

		/* Reset initialised flag */
		inited = osa_false;
	}
}

int32 rman_create_bucket(void **res_bucket_handle)
{
	struct rman_bucket	*bucket;
	uint32			i;
	int32			ret;

	IMG_DBG_ASSERT(inited);

	/* Allocate a bucket structure */
	bucket = osa_zalloc(sizeof(*bucket), OSA_GFP_KERNEL);
	IMG_DBG_ASSERT(bucket);
	if (!bucket)
		return IMG_ERROR_OUT_OF_MEMORY;

	/* Initialise the resource list */
	dq_init(&bucket->res_list);

	/* Then start allocating resource ids at the first */
	ret = idgen_createcontext(RMAN_MAX_ID, RMAN_ID_BLOCKSIZE, osa_false,
				  &bucket->id_gen);
	if (ret != IMG_SUCCESS) {
		osa_free(bucket);
		IMG_DBG_ASSERT("failed to create IDGEN context" == NULL);
		return ret;
	}

	/* Locate free bucket index within the table */
	osa_mutex_lock_nested(shared_res_mutex_handle, OSA_SUBCLASS_RMAN);
	for (i = 0; i < RMAN_CRESID_MAX_BUCKET_INDEX; i++) {
		if (!bucket_array[i])
			break;
	}
	if (i >= RMAN_CRESID_MAX_BUCKET_INDEX) {
		osa_mutex_unlock(shared_res_mutex_handle);
		idgen_destroycontext(bucket->id_gen);
		osa_free(bucket);
		IMG_DBG_ASSERT("No free buckets left" == NULL);
		return IMG_ERROR_GENERIC_FAILURE;
	}

	/* Allocate bucket index */
	bucket->bucket_idx = i;
	bucket_array[i] = bucket;

	osa_mutex_unlock(shared_res_mutex_handle);

	/* Return the bucket handle */
	*res_bucket_handle = bucket;

	return IMG_SUCCESS;
}

void rman_destroy_bucket(void *res_bucket_handle)
{
	struct rman_bucket *bucket = (struct rman_bucket *)res_bucket_handle;

	IMG_DBG_ASSERT(inited);

	IMG_DBG_ASSERT(bucket);
	if (!bucket)
		return;

	IMG_DBG_ASSERT(bucket->bucket_idx < RMAN_CRESID_MAX_BUCKET_INDEX);
	IMG_DBG_ASSERT(bucket_array[bucket->bucket_idx]);

	/* Free all resources from the bucket */
	rman_free_resources(res_bucket_handle, RMAN_TYPE_P1);
	rman_free_resources(res_bucket_handle, RMAN_TYPE_P2);
	rman_free_resources(res_bucket_handle, RMAN_TYPE_P3);
	rman_free_resources(res_bucket_handle, RMAN_ALL_TYPES);

	/* free sticky resources last: other resources are dependent on them */
	rman_free_resources(res_bucket_handle, RMAN_STICKY);
	/* Use proper locking around global buckets.  */
	osa_mutex_lock_nested(shared_res_mutex_handle, OSA_SUBCLASS_RMAN);

	/* Free from array of bucket pointers */
	bucket_array[bucket->bucket_idx] = NULL;

	osa_mutex_unlock(shared_res_mutex_handle);

	/* Free the bucket itself */
	idgen_destroycontext(bucket->id_gen);
	osa_free(bucket);
}

void *rman_get_global_bucket(void)
{
	IMG_DBG_ASSERT(inited);
	IMG_DBG_ASSERT(global_res_bucket);

	/* Return the handle of the global resource bucket */
	return global_res_bucket;
}

int32 rman_register_resource(void *res_bucket_handle, uint32 type_id,
			   rman_fn_free fnfree, void *param,
			   void **res_handle, uint32 *res_id)
{
	struct rman_bucket *bucket = (struct rman_bucket *)res_bucket_handle;
	struct rman_res		*res;
	int32			 ret;

	IMG_DBG_ASSERT(inited);
	IMG_DBG_ASSERT(type_id != RMAN_ALL_TYPES);

	IMG_DBG_ASSERT(res_bucket_handle);
	if (!res_bucket_handle)
		return IMG_ERROR_GENERIC_FAILURE;

	/* Allocate a resource structure */
	res = osa_zalloc(sizeof(*res), OSA_GFP_KERNEL);
	IMG_DBG_ASSERT(res);
	if (!res)
		return IMG_ERROR_OUT_OF_MEMORY;

	/* Fill in the resource structure */
	res->bucket	= bucket;
	res->type_id	= type_id;
	res->fn_free	= fnfree;
	res->param	= param;

	/* Allocate resource Id */
	osa_mutex_lock_nested(global_mutex, OSA_SUBCLASS_RMAN);
	ret = idgen_allocid(bucket->id_gen, res, &res->res_id);
	osa_mutex_unlock(global_mutex);
	if (ret != IMG_SUCCESS) {
		IMG_DBG_ASSERT("failed to allocate RMAN id" == NULL);
		return ret;
	}
	IMG_DBG_ASSERT(res->res_id <= RMAN_CRESID_MAX_RES_ID);

	/* add this resource to the bucket */
	osa_mutex_lock_nested(shared_res_mutex_handle, OSA_SUBCLASS_RMAN);
	dq_addtail(&bucket->res_list, res);

	/* Update count of resources */
	bucket->res_cnt++;
	osa_mutex_unlock(shared_res_mutex_handle);

	/* If resource handle required */
	if (res_handle)
		*res_handle = res;

	/* If resource id required */
	if (res_id)
		*res_id = rman_get_resource_id(res);

	return IMG_SUCCESS;
}

uint32 rman_get_resource_id(void *res_handle)
{
	struct rman_res *res = res_handle;
	uint32		ext_res_id;

	IMG_DBG_ASSERT(res_handle);
	if (!res_handle)
		return 0;

	IMG_DBG_ASSERT(res->res_id <= RMAN_CRESID_MAX_RES_ID);
	IMG_DBG_ASSERT(res->bucket->bucket_idx < RMAN_CRESID_MAX_BUCKET_INDEX);
	if (res->bucket->bucket_idx >= RMAN_CRESID_MAX_BUCKET_INDEX)
		return 0;

	ext_res_id = (((res->bucket->bucket_idx + 1) <<
			 RMAN_CRESID_BUCKET_SHIFT) | res->res_id);

	return ext_res_id;
}

static void *rman_getresource_int(void *res_bucket_handle, uint32 res_id,
				  uint32 type_id, void **res_handle)
{
	struct rman_bucket *bucket = (struct rman_bucket *)res_bucket_handle;
	struct rman_res	*res;
	int32		ret;

	IMG_DBG_ASSERT(res_id <= RMAN_CRESID_MAX_RES_ID);

	/* Loop over the resources in this bucket till we find the required id */
	osa_mutex_lock_nested(global_mutex, OSA_SUBCLASS_RMAN);
	ret = idgen_gethandle(bucket->id_gen, res_id, (void **)&res);
	osa_mutex_unlock(global_mutex);
	if (ret != IMG_SUCCESS) {
		IMG_DBG_ASSERT("failed to get RMAN resource" == NULL);
		return NULL;
	}

	/* If the resource handle is required */
	if (res_handle)
		*res_handle = res; /* Return it */

	/* If the resource was not found */
	IMG_DBG_ASSERT(res);
	IMG_DBG_ASSERT((void *)res != &bucket->res_list);
	if (!res || ((void *)res == &bucket->res_list))
		return NULL;

	/* Cross check the type */
	IMG_DBG_ASSERT(type_id == res->type_id);

	/* Return the resource. */
	return res->param;
}

int32 rman_get_resource(uint32 res_id, uint32 type_id, void **param,
		      void **res_handle)
{
	uint32	bucket_idx = (res_id >> RMAN_CRESID_BUCKET_SHIFT) - 1;
	uint32	int_res_id = (res_id & RMAN_CRESID_RES_ID_MASK);
	void	*local_param;

	IMG_DBG_ASSERT(bucket_idx < RMAN_CRESID_MAX_BUCKET_INDEX);
	if (bucket_idx >= RMAN_CRESID_MAX_BUCKET_INDEX)
		return IMG_ERROR_INVALID_ID; /* Happens when bucket_idx == 0 */

	IMG_DBG_ASSERT(bucket_array[bucket_idx]);
	if (!bucket_array[bucket_idx])
		return IMG_ERROR_INVALID_ID;

	local_param = rman_getresource_int(bucket_array[bucket_idx],
					   int_res_id, type_id,
					   res_handle);

	/* If we didn't find the resource */
	if (!local_param)
		return IMG_ERROR_INVALID_ID;

	/* Return the resource */
	if (param)
		*param = local_param;

	return IMG_SUCCESS;
}

int32 rman_get_named_resource(uint8 *res_name, rman_fn_alloc fn_alloc,
			    void *alloc_info, void *res_bucket_handle,
			    uint32 type_id, rman_fn_free fn_free,
			    void **param, void **res_handle, uint32 *res_id)
{
	struct rman_bucket *bucket = res_bucket_handle;
	struct rman_res	*res;
	uint32		ret;
	void	*local_param;
	uint8	found = osa_false;

	IMG_DBG_ASSERT(inited);

	IMG_DBG_ASSERT(res_bucket_handle);
	if (!res_bucket_handle)
		return IMG_ERROR_GENERIC_FAILURE;

	/* Lock the shared resources */
	osa_mutex_lock_nested(shared_res_mutex_handle, OSA_SUBCLASS_RMAN);
	res = (struct rman_res *)dq_first(&bucket->res_list);
	while (res && ((void *)res != &bucket->res_list)) {
		/* If resource already in the shared list */
		if (res->res_name && (strcmp((const char *)res_name,
					     (const char *)res->res_name) == 0)) {
			IMG_DBG_ASSERT(res->fn_free == fn_free);
			found = osa_true;
			break;
		}

		/* Move to next resource */
		res = (struct rman_res *)dq_next(res);
	}
	osa_mutex_unlock(shared_res_mutex_handle);

	/* If the named resource was not found */
	if (!found) {
		/* Allocate the resource */
		ret = fn_alloc(alloc_info, &local_param);
		IMG_DBG_ASSERT(ret == IMG_SUCCESS);
		if (ret != IMG_SUCCESS)
			return ret;

		/* Register the named resource */
		ret = rman_register_resource(res_bucket_handle, type_id,
					     fn_free, local_param,
					     (void **)&res, NULL);
		IMG_DBG_ASSERT(ret == IMG_SUCCESS);
		if (ret != IMG_SUCCESS)
			return ret;

		osa_mutex_lock_nested(shared_res_mutex_handle, OSA_SUBCLASS_RMAN);
		res->res_name = res_name;
		osa_mutex_unlock(shared_res_mutex_handle);
	}

	/* Return the pvParam value */
	*param = res->param;

	/* If resource handle required */
	if (res_handle)
		*res_handle = res;

	/* If resource id required */
	if (res_id)
		*res_id = rman_get_resource_id(res);

	/* Exit */
	return IMG_SUCCESS;
}

static void rman_free_resource_int(struct rman_res *res)
{
	struct rman_bucket *bucket = res->bucket;

	/* Remove the resource from the active list */
	osa_mutex_lock_nested(shared_res_mutex_handle, OSA_SUBCLASS_RMAN);

	/* Remove from list */
	dq_remove(res);

	/* Update count of resources */
	bucket->res_cnt--;

	osa_mutex_unlock(shared_res_mutex_handle);

	/* If mutex associated with the resource */
	if (res->mutex_handle) {
		/* Destroy mutex */
		osa_mutex_destroy(&res->mutex_handle);
		res->mutex_handle = NULL;
	}

	/* If this resource is not already shared */
	if (res->shared_res) {
		/* Lock the shared resources */
		osa_mutex_lock_nested(shared_res_mutex_handle, OSA_SUBCLASS_RMAN);

		/* Update the reference count */
		IMG_DBG_ASSERT(res->shared_res->ref_cnt != 0);
		res->shared_res->ref_cnt--;

		/* If this is the last free for the shared resource */
		if (res->shared_res->ref_cnt == 0)
			/* Free the shared resource */
			rman_free_resource_int(res->shared_res);

		/* UnLock the shared resources */
		osa_mutex_unlock(shared_res_mutex_handle);
	} else {
		/* If there is a free callback function. */
		if (res->fn_free)
			/* Call resource free callback */
			res->fn_free(res->param);
	}

	/* If the resource has a name then free it */
	if (res->res_name)
		osa_free(res->res_name);

	/* Free the resource ID. */
	osa_mutex_lock_nested(global_mutex, OSA_SUBCLASS_RMAN);
	idgen_freeid(bucket->id_gen, res->res_id);
	osa_mutex_unlock(global_mutex);

	/* Free a resource structure */
	osa_free(res);
}

void rman_free_resource(void *res_handle)
{
	struct rman_res *res;

	IMG_DBG_ASSERT(inited);

	IMG_DBG_ASSERT(res_handle);
	if (!res_handle)
		return;

	/* Get access to the resource structure */
	res = (struct rman_res *)res_handle;

	/* Free resource */
	rman_free_resource_int(res);
}

void rman_lock_resource(void *res_handle)
{
	struct rman_res	*res;

	IMG_DBG_ASSERT(inited);

	IMG_DBG_ASSERT(res_handle);
	if (!res_handle)
		return;

	/* Get access to the resource structure */
	res = (struct rman_res *)res_handle;

	/* If this is a shared resource */
	if (res->shared_res)
		/* We need to lock/unlock the underlying shared resource */
		res = res->shared_res;

	/* If no mutex associated with this resource */
	if (NULL == res->mutex_handle) {
		/* Create one */

		osa_mutex_create(&res->mutex_handle);
		if(NULL == res->mutex_handle)
		{
			return;
		}
	}

	/* lock it */
	osa_mutex_lock(res->mutex_handle);
}

void rman_unlock_resource(void *res_handle)
{
	struct rman_res *res;

	IMG_DBG_ASSERT(inited);

	IMG_DBG_ASSERT(res_handle);
	if (!res_handle)
		return;

	/* Get access to the resource structure */
	res = (struct rman_res *)res_handle;

	/* If this is a shared resource */
	if (res->shared_res)
		/* We need to lock/unlock the underlying shared resource */
		res = res->shared_res;

	IMG_DBG_ASSERT(res->mutex_handle);

	/* Unlock mutex */
	osa_mutex_unlock(res->mutex_handle);
}

void rman_free_resources(void *res_bucket_handle, uint32 type_id)
{
	struct rman_bucket *bucket = (struct rman_bucket *)res_bucket_handle;
	struct rman_res		*res;

	IMG_DBG_ASSERT(inited);

	IMG_DBG_ASSERT(res_bucket_handle);
	if (!res_bucket_handle)
		return;

	/* Scan the active list looking for the resources to be freed */
	osa_mutex_lock_nested(shared_res_mutex_handle, OSA_SUBCLASS_RMAN);
	res = (struct rman_res *)dq_first(&bucket->res_list);
	while ((res) && ((void *)res != &bucket->res_list)) {
		/* If this is resource is to be removed */
		if ((type_id == RMAN_ALL_TYPES  &&
		     res->type_id != RMAN_STICKY) ||
		     res->type_id == type_id) {
			/* Yes, remove it, Free current resource */
			osa_mutex_unlock(shared_res_mutex_handle);
			rman_free_resource_int(res);
			osa_mutex_lock_nested(shared_res_mutex_handle, OSA_SUBCLASS_RMAN);

			/* Restart from the beginning of the list */
			res = (struct rman_res *)dq_first(&bucket->res_list);
		} else {
			/* Move to next resource */
			res = (struct rman_res *)lst_next(res);
		}
	}
	osa_mutex_unlock(shared_res_mutex_handle);
}
