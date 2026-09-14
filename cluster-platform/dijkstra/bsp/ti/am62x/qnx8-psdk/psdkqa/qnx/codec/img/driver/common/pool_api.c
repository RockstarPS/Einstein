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
 * Resource pool manager API.
 */

#include "osal/inc/osa_mem.h"
#include "osal/inc/osa_define.h"
#include "osal/inc/osa_types.h"
#include "osal/inc/osa_err.h"
#include "osal/inc/osa_mutex.h"
#include "idgen_api.h"
#include "lst.h"
#include "pool_api.h"

/*
 * list can be modified by different instances. So please,
 * make sure to acquire mutex lock before initializing the list.
 */
static void *shared_res_mutex_handle = NULL;

/*
 * Max resource ID's.
 */
#define POOL_IDGEN_MAX_ID	   (0xFFFFFFFF)
/*
 * Size of blocks used for ID's.
 */
#define POOL_IDGEN_BLOCK_SIZE  (50)

/*
 * Indicates if the pool API has been indialized or not.
 * zero if not done. 1 if done.
 */
static int32 poolinitdone = 0;

/* list of resource pool */
static struct lst_t poollist = {0};

/*
 * Structure contains resource list information.
 */
struct poollist {
	void **link; /* to be able to part of single linked list */
	void *pool_mutex;
	/* list of free resource structure */
	struct lst_t freereslst;
	/* list of active resource structure */
	struct lst_t actvreslst;
	/* pool free callback function */
	pfrecalbkpntr pfnfree;
	/* ID generator context handle */
	void *idgenhandle;
};

/*
 * This structure contains pool resource.
 */
struct poolres {
	void **link; /* to be able to part of single linked list */
	/* Resource id */
	uint32 resid;
	/* Pointer to destructor function */
	pdestcallbkptr desfunc;
	/* resource param */
	void *resparam;
	/* size of resource param in bytes */
	uint32 resparmsize;
	/* pointer to resource pool list */
	struct poollist *respoollst;
	/* 1 if this is a clone of the original resource */
	int32 isclone;
	/* pointer to original resource */
	struct poolres *origres;
	/* list of cloned resource structures. Only used on the original */
	struct lst_t clonereslst;
	/* reference count. Only used on the original resource */
	uint32 refcnt;
	void *cb_handle;
};

/*
 * This function initializes the list if not done earlier.
 */
int32 pool_init(void)
{
	/* Check if list already initialized */
	if (!poolinitdone) {
		/*
		 * list can be modified by different instances. So please,
		 * make sure to acquire mutex lock before initializing the list.
		 */

		osa_mutex_create(&shared_res_mutex_handle);
		if(NULL == shared_res_mutex_handle)
		{
			return OSA_ENOMEM;
		}

		/* initialize the list of pools */
		lst_init(&poollist);
		/* Get initialized flag to true */
		poolinitdone = 1;
	}

	return 0;
}

/*
 * This function de-initializes the list.
 */
void pool_deinit(void)
{
	struct poollist *respoollist;

	/* Check if list initialized */
	if (poolinitdone) {
		/* destroy any active pools */
		respoollist = (struct poollist *)lst_first(&poollist);
		while (respoollist) {
			pool_destroy(respoollist);
			respoollist = (struct poollist *)lst_first(&poollist);
		}

		/* Destroy mutex */
		osa_mutex_destroy(&shared_res_mutex_handle);
		shared_res_mutex_handle = NULL;

		/* set initialized flag to 0 */
		poolinitdone = 0;
	}
}

/*
 * This function creates pool.
 */
int32 pool_api_create(void **poolhndle)
{
	struct poollist *respoollist;
	uint32 result = 0;

	/* Allocate a pool structure */
	respoollist = osa_zalloc(sizeof(*respoollist), OSA_GFP_KERNEL);
	if (!respoollist)
		return IMG_ERROR_OUT_OF_MEMORY;

	/* Initialize the pool info */
	lst_init(&respoollist->freereslst);
	lst_init(&respoollist->actvreslst);

	/* Create mutex */
	osa_mutex_create(&respoollist->pool_mutex);
	if(NULL == respoollist->pool_mutex)
	{
		result = OSA_ENOMEM;
		goto error_create_context;
	}

	/* Create context for the Id generator */
	result = idgen_createcontext(POOL_IDGEN_MAX_ID,
				     POOL_IDGEN_BLOCK_SIZE, 0,
				     &respoollist->idgenhandle);
	if (result != IMG_SUCCESS)
		goto error_create_context;

	/* Disable interrupts */
	osa_mutex_lock_nested(shared_res_mutex_handle, OSA_SUBCLASS_POOL_RES);

	/* Add to list of pools */
	lst_add(&poollist, respoollist);

	/* Enable interrupts */
	osa_mutex_unlock(shared_res_mutex_handle);

	/* Return handle to pool */
	*poolhndle = respoollist;

	return IMG_SUCCESS;

	/* Error handling. */
error_create_context:
	osa_free(respoollist);

	return result;
}

/*
 * This function destroys the pool.
 */
int32 pool_destroy(void *poolhndle)
{
	struct poollist *respoollist = poolhndle;
	struct poolres *respool;
	struct poolres *clonerespool;
	uint32 result = 0;

	if (!poolinitdone || !respoollist) {
		result = IMG_ERROR_INVALID_PARAMETERS;
		goto	error_nolock;
	}

	/* Lock the pool */
	osa_mutex_lock_nested(respoollist->pool_mutex, OSA_SUBCLASS_POOL);

	/* Disable interrupts */
	/*
	 * We need to check if we really need to check disable,
	 * interrupts because before deleting we need to make sure the
	 * pool lst is not being used other process. As of now getting ipl
	 * global mutex
	 */
	osa_mutex_lock_nested(shared_res_mutex_handle, OSA_SUBCLASS_POOL_RES);

	/* Remove the pool from the active list */
	lst_remove(&poollist, respoollist);

	/* Enable interrupts */
	osa_mutex_unlock(shared_res_mutex_handle);

	/* Destroy any resources in the free list */
	respool = (struct poolres *)lst_removehead(&respoollist->freereslst);
	while (respool) {
		respool->desfunc(respool->resparam, respool->cb_handle);
		osa_free(respool);
		respool = (struct poolres *)
				lst_removehead(&respoollist->freereslst);
	}

	/* Destroy any resources in the active list */
	respool = (struct poolres *)lst_removehead(&respoollist->actvreslst);
	while (respool) {
		clonerespool = (struct poolres *)
				lst_removehead(&respool->clonereslst);
		while (clonerespool) {
			/*
			 * If we created a copy of the resources pvParam
			 * then free it.
			 * osa_free(NULL) is safe and this check is probably not
			 * required
			 */
			osa_free(clonerespool->resparam);

			osa_free(clonerespool);
			clonerespool = (struct poolres *)
					lst_removehead(&respool->clonereslst);
		}

		/* Call the resource destructor */
		respool->desfunc(respool->resparam, respool->cb_handle);
		osa_free(respool);
		respool = (struct poolres *)
				lst_removehead(&respoollist->actvreslst);
	}
	/* Destroy the context for the Id generator */
	if (respoollist->idgenhandle)
		result = idgen_destroycontext(respoollist->idgenhandle);

	/* Unlock the pool */
	osa_mutex_unlock(respoollist->pool_mutex);

	/* Destroy mutex */
	osa_mutex_destroy(&respoollist->pool_mutex);

	/* Free the pool structure */
	osa_free(respoollist);

	return IMG_SUCCESS;

error_nolock:
	return result;
}

int32 pool_setfreecalbck(void *poolhndle, pfrecalbkpntr pfnfree)
{
	struct poollist *respoollist = poolhndle;
	struct poolres *respool;
	uint32 result = 0;

	if (!poolinitdone || !respoollist) {
		result = IMG_ERROR_INVALID_PARAMETERS;
		goto error_nolock;
	}

	/* Lock the pool */
	osa_mutex_lock_nested(respoollist->pool_mutex, OSA_SUBCLASS_POOL);

	respoollist->pfnfree = pfnfree;

	/* If free callback set */
	if (respoollist->pfnfree) {
		/* Move resources from free to active list */
		respool = (struct poolres *)
				lst_removehead(&respoollist->freereslst);
		while (respool) {
			/* Add to active list */
			lst_add(&respoollist->actvreslst, respool);
			respool->refcnt++;

			/* Unlock the pool */
			osa_mutex_unlock(respoollist->pool_mutex);

			/* Call the free callback */
			respoollist->pfnfree(respool->resid, respool->resparam);

			/* Lock the pool */
			osa_mutex_lock_nested(respoollist->pool_mutex, OSA_SUBCLASS_POOL);

			/* Get next free resource */
			respool = (struct poolres *)
				lst_removehead(&respoollist->freereslst);
		}
	}

	/* Unlock the pool */
	osa_mutex_unlock(respoollist->pool_mutex);

	/* Return IMG_SUCCESS */
	return IMG_SUCCESS;

error_nolock:
	return result;
}

int32 pool_resreg(void *poolhndle, pdestcallbkptr fndestructor,
		void *resparam, uint32 resparamsize,
		int32 balloc, uint32 *residptr,
		void **poolreshndle, void *cb_handle)
{
	struct poollist *respoollist = poolhndle;
	struct poolres *respool;
	uint32 result = 0;

	if (!poolinitdone || !respoollist) {
		result = IMG_ERROR_INVALID_PARAMETERS;
		goto	error_nolock;
	}

	/* Allocate a resource structure */
	respool = osa_zalloc(sizeof(*respool), OSA_GFP_KERNEL);
	if (!respool)
		return IMG_ERROR_OUT_OF_MEMORY;

	/* Setup the resource */
	respool->desfunc  = fndestructor;
	respool->cb_handle = cb_handle;
	respool->resparam = resparam;
	respool->resparmsize = resparamsize;
	respool->respoollst = respoollist;
	lst_init(&respool->clonereslst);

	/* Lock the pool */
	osa_mutex_lock_nested(respoollist->pool_mutex, OSA_SUBCLASS_POOL);

	/* Set resource id */
	result = idgen_allocid(respoollist->idgenhandle,
			       (void *)respool, &respool->resid);
	if (result != IMG_SUCCESS) {
		osa_free(respool);
		/* Unlock the pool */
		osa_mutex_unlock(respoollist->pool_mutex);
		return result;
	}

	/* If allocated or free callback not set */
	if (balloc || respoollist->pfnfree) {
		/* Add to active list */
		lst_add(&respoollist->actvreslst, respool);
		respool->refcnt++;
	} else {
		/* Add to free list */
		lst_add(&respoollist->freereslst, respool);
	}

	/* Return the resource id */
	if (residptr)
		*residptr = respool->resid;

	/* Return the handle to the resource */
	if (poolreshndle)
		*poolreshndle = respool;

	/* Unlock the pool */
	osa_mutex_unlock(respoollist->pool_mutex);

	/* If free callback set */
	if (respoollist->pfnfree) {
		/* Call the free callback */
		respoollist->pfnfree(respool->resid, respool->resparam);
	}

	/* Return IMG_SUCCESS */
	return IMG_SUCCESS;

error_nolock:
	return result;
}

int32 pool_resdestroy(void *poolreshndle, int32 bforce)
{
	struct poolres *respool = poolreshndle;
	struct poollist *respoollist;
	struct poolres *origrespool;
	uint32 result = 0;

	if (!poolinitdone || !respool) {
		result = IMG_ERROR_INVALID_PARAMETERS;
		goto error_nolock;
	}

	respoollist = respool->respoollst;

	/* If this is a clone */
	if (respool->isclone) {
		/* Get access to the original */
		origrespool = respool->origres;
		if (!origrespool) {
			result = IMG_ERROR_UNEXPECTED_STATE;
			goto error_nolock;
		}

		if (origrespool->isclone) {
			result = IMG_ERROR_UNEXPECTED_STATE;
			goto error_nolock;
		}

		/* Remove from the clone list */
		lst_remove(&origrespool->clonereslst, respool);

		/* Free resource id */
		result = idgen_freeid(respoollist->idgenhandle,
				      respool->resid);
		if (result != IMG_SUCCESS)
			return result;

		/*
		 * If we created a copy of the resources pvParam then free it
		 * osa_free(NULL) is safe and this check is probably not required.
		 */
		osa_free(respool->resparam);

		/* Free the clone resource structure */
		osa_free(respool);

		/* Set resource to be "freed" to the original */
		respool = origrespool;
	}

	/* If there are still outstanding references */
	if (!bforce && respool->refcnt != 0) {
		/*
		 * We may need to mark the resource and destroy it when
		 * there are no outstanding references
		 */
		return IMG_SUCCESS;
	}

	/* Has the resource outstanding references */
	if (respool->refcnt != 0) {
		/* Remove the resource from the active list */
		lst_remove(&respoollist->actvreslst, respool);
	} else {
		/* Remove the resource from the free list */
		lst_remove(&respoollist->freereslst, respool);
	}

	/* Free resource id */
	result = idgen_freeid(respoollist->idgenhandle,
			      respool->resid);
	if (result != IMG_SUCCESS)
		return result;

	/* Call the resource destructor */
	respool->desfunc(respool->resparam, respool->cb_handle);
	osa_free(respool);

	return IMG_SUCCESS;

error_nolock:
	return result;
}

int32 pool_resalloc(void *poolhndle, void *poolreshndle)
{
	struct poollist *respoollist = poolhndle;
	struct poolres *respool = poolreshndle;
	uint32 result = 0;

	if (!poolinitdone || !respoollist || !poolreshndle) {
		result = IMG_ERROR_INVALID_PARAMETERS;
		goto error_nolock;
	}

	/* Lock the pool */
	osa_mutex_lock_nested(respoollist->pool_mutex, OSA_SUBCLASS_POOL);

	/* Remove resource from free list */
	lst_remove(&respoollist->freereslst, respool);

	/* Add to active list */
	lst_add(&respoollist->actvreslst, respool);
	respool->refcnt++;

	/* Unlock the pool */
	osa_mutex_unlock(respoollist->pool_mutex);

	/* Return IMG_SUCCESS */
	return IMG_SUCCESS;

error_nolock:
	return result;
}

int32 pool_resfree(void *poolreshndle)
{
	struct poolres *respool = poolreshndle;
	struct poollist *respoollist;
	struct poolres *origrespool;
	uint32 result = 0;

	if (!poolinitdone || !respool) {
		result = IMG_ERROR_INVALID_PARAMETERS;
		goto error_nolock;
	}

	respoollist = respool->respoollst;

	/* Lock the pool */
	osa_mutex_lock_nested(respoollist->pool_mutex, OSA_SUBCLASS_POOL);

	/* If this is a clone */
	if (respool->isclone) {
		/* Get access to the original */
		origrespool = respool->origres;
		if (!origrespool) {
			osa_mutex_unlock(respoollist->pool_mutex);
			return IMG_ERROR_INVALID_PARAMETERS;
		}

		/* Remove from the clone list */
		lst_remove(&origrespool->clonereslst, respool);

		/* Free resource id */
		result = idgen_freeid(respoollist->idgenhandle,
				      respool->resid);
		if (result != IMG_SUCCESS) {
			/* Unlock the pool */
			osa_mutex_unlock(respoollist->pool_mutex);
			return result;
		}

		/*
		 * If we created a copy of the resources pvParam then free it
		 * osa_free(NULL) is safe and this check is probably not required.
		 */
		osa_free(respool->resparam);

		/* Free the clone resource structure */
		osa_free(respool);

		/* Set resource to be "freed" to the original */
		respool = origrespool;
	}

	/* Update the reference count */
	respool->refcnt--;

	/* If there are still outstanding references */
	if (respool->refcnt != 0) {
		/* Unlock the pool */
		osa_mutex_unlock(respoollist->pool_mutex);
		/* Return IMG_SUCCESS */
		return IMG_SUCCESS;
	}

	/* Remove the resource from the active list */
	lst_remove(&respoollist->actvreslst, respool);

	/* If free callback set */
	if (respoollist->pfnfree) {
		/* Add to active list */
		lst_add(&respoollist->actvreslst, respool);
		respool->refcnt++;
	} else {
		/* Add to free list */
		lst_add(&respoollist->freereslst, respool);
	}

	/* Unlock the pool */
	osa_mutex_unlock(respoollist->pool_mutex);

	/* If free callback set */
	if (respoollist->pfnfree) {
		/* Call the free callback */
		respoollist->pfnfree(respool->resid, respool->resparam);
	}

	/* Return IMG_SUCCESS */
	return IMG_SUCCESS;

error_nolock:
	return result;
}

int32 pool_resclone(void *poolreshndle, void **clonereshndle, void **resparam)
{
	struct poolres *respool = poolreshndle;
	struct poollist *respoollist;
	struct poolres *origrespool = respool;
	struct poolres *clonerespool;
	uint32 result = 0;

	if (!poolinitdone || !respool) {
		result = IMG_ERROR_INVALID_PARAMETERS;
		goto error_nolock;
	}

	/* Allocate a resource structure */
	clonerespool = osa_zalloc(sizeof(*clonerespool), OSA_GFP_KERNEL);
	if (!clonerespool)
		return IMG_ERROR_OUT_OF_MEMORY;

	respoollist = respool->respoollst;
	if (!respoollist)
		return IMG_ERROR_FATAL;

	/* Lock the pool */
	osa_mutex_lock_nested(respoollist->pool_mutex, OSA_SUBCLASS_POOL);

	/* Set resource id */
	result = idgen_allocid(respoollist->idgenhandle,
			       (void *)clonerespool, &clonerespool->resid);
	if (result != IMG_SUCCESS)
		goto error_alloc_id;

	/* If this is a clone, set the original */
	if (respool->isclone)
		origrespool = respool->origres;

	/* Setup the cloned resource */
	clonerespool->isclone = 1;
	clonerespool->respoollst = respoollist;
	clonerespool->origres = origrespool;

	/* Add to clone list */
	lst_add(&origrespool->clonereslst, clonerespool);
	origrespool->refcnt++;

	/* If ppvParam is not IMG_NULL */
	if (resparam) {
		/* If the size of the original vParam is 0 */
		if (origrespool->resparmsize == 0) {
			*resparam = NULL;
		} else {
			/* Allocate memory for a copy of the original vParam */
			/*
			 * kmemdup allocates memory of length
			 * origrespool->resparmsize and to resparam and copy
			 * origrespool->resparam to resparam of the allocated
			 * length
			 */
			*resparam = osa_memdup(origrespool->resparam,
					    origrespool->resparmsize,
					    OSA_GFP_KERNEL);
			if (!(*resparam)) {
				result = IMG_ERROR_OUT_OF_MEMORY;
				goto error_copy_param;
			}
		}
	}

	/* Unlock the pool */
	osa_mutex_unlock(respoollist->pool_mutex);

	/* Return the cloned resource */
	*clonereshndle = clonerespool;

	/* Return IMG_SUCCESS */
	return IMG_SUCCESS;

	/* Error handling. */
error_copy_param:
	lst_remove(&origrespool->clonereslst, clonerespool);
	origrespool->refcnt--;
error_alloc_id:
	osa_free(clonerespool);

	/* Unlock the pool */
	osa_mutex_unlock(respoollist->pool_mutex);

error_nolock:
	return result;
}
