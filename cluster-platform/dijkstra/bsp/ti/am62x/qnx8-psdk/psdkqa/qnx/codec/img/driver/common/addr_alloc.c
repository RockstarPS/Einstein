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
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
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
 * Address allocation APIs - used to manage address allocation
 * with a number of predefined regions.
 */

#include "osal/inc/osa_mutex.h"
#include "osal/inc/osa_define.h"
#include "osal/inc/osa_err.h"
#include "addr_alloc.h"
#include "hash.h"
#include "img_errors.h"

/* Global context. */
static struct addr_context global_ctx = {0};
/* Sub-system initialized. */
static int32 global_initialized = 0;
/* Count of contexts. */
static uint32 num_ctx = 0;
/* Global mutex */
static void *global_lock = NULL;

int32 addr_initialise(void)
{
	uint32 result = IMG_ERROR_ALREADY_INITIALISED;

	/* If we are not initialized */
	if (!global_initialized)
		result = addr_cx_initialise(&global_ctx);
	return result;
}

int32 addr_cx_initialise(struct addr_context * const context)
{
	uint32 result = IMG_ERROR_FATAL;

	if (!context)
		return IMG_ERROR_INVALID_PARAMETERS;

	if (!global_initialized) {
		/* Initialise context */
		memset(context, 0x00, sizeof(struct addr_context));

		/* If no mutex associated with this resource */
		if (NULL == global_lock) {
			/* Create one */

			osa_mutex_create(&global_lock);
			if(NULL == global_lock)
			{
				return OSA_ENOMEM;
			}
		}

		osa_mutex_lock_nested(global_lock, OSA_SUBCLASS_ADDR_ALLOC);

		/* Initialise the hash functions. */
		result = vid_hash_initialise();
		if (result != IMG_SUCCESS) {
			osa_mutex_unlock(global_lock);
			return IMG_ERROR_UNEXPECTED_STATE;
		}

		/* Initialise the arena functions */
		result = vid_ra_initialise();
		if (result != IMG_SUCCESS) {
			osa_mutex_unlock(global_lock);
			result = vid_hash_finalise();
			return IMG_ERROR_UNEXPECTED_STATE;
		}

		/* We are now initialized */
		global_initialized = TRUE;
		result = IMG_SUCCESS;
	} else {
		osa_mutex_lock_nested(global_lock, OSA_SUBCLASS_ADDR_ALLOC);
	}

	num_ctx++;
	osa_mutex_unlock(global_lock);

	return result;
}

int32 addr_deinitialise(void)
{
	return addr_cx_deinitialise(&global_ctx);
}

int32 addr_cx_deinitialise(struct addr_context * const context)
{
	struct addr_region *tmp_region = NULL;
	uint32 result = IMG_ERROR_FATAL;

	if (!context)
		return IMG_ERROR_INVALID_PARAMETERS;

	if (global_initialized) {
		osa_mutex_lock_nested(global_lock, OSA_SUBCLASS_ADDR_ALLOC);

		tmp_region = context->regions;

		/* Delete all arena structure */
		if (context->default_region)
			result = vid_ra_delete(context->default_region->arena);

		while (tmp_region) {
			result = vid_ra_delete(tmp_region->arena);
			tmp_region = tmp_region->nxt_region;
		}

		if (num_ctx != 0)
			num_ctx--;

		result = IMG_SUCCESS;
		if (num_ctx == 0) {
			/* Free off resources */
			result = vid_hash_finalise();
			result = vid_ra_deinit();
			global_initialized = FALSE;

			osa_mutex_unlock(global_lock);
			osa_mutex_destroy(&global_lock);
		} else {
			osa_mutex_unlock(global_lock);
		}
	}

	return result;
}

int32 addr_define_mem_region(struct addr_region * const region)
{
	return addr_cx_define_mem_region(&global_ctx, region);
}

int32 addr_cx_define_mem_region(struct addr_context * const context,
			      struct addr_region * const region)
{
	struct addr_region *tmp_region = NULL;
	uint32 result = IMG_SUCCESS;

	if (!context || !region)
		return IMG_ERROR_INVALID_PARAMETERS;

	osa_mutex_lock_nested(global_lock, OSA_SUBCLASS_ADDR_ALLOC);

	tmp_region = context->regions;

	/* Ensure the link to the next is NULL */
	region->nxt_region = NULL;

	/* If this is the default memory region */
	if (!region->name) {
		/* Should not previously have been defined */
		if (context->default_region) {
			osa_mutex_unlock(global_lock);
			return IMG_ERROR_UNEXPECTED_STATE;
		}

		context->default_region = region;
		context->no_regions++;

		/*
		 * Create an arena for memory allocation
		 * name of resource arena for debug
		 * start of resource
		 * size of resource
		 * allocation quantum
		 * import allocator
		 * import deallocator
		 * import handle
		 */
		result = vid_ra_create((const uint8 * const)"memory",
				       region->base_addr,
				       region->size,
				       1,
				       NULL,
				       NULL,
				       NULL,
				       &region->arena);

		if (result != IMG_SUCCESS) {
			osa_mutex_unlock(global_lock);
			return IMG_ERROR_UNEXPECTED_STATE;
		}
	} else {
		/*
		 * Run down the list of existing named regions
		 * to check if there is a region with this name
		 */
		while (tmp_region &&
		       (strcmp((const char *)region->name, (const char *)tmp_region->name) != 0) &&
		       tmp_region->nxt_region) {
			tmp_region = tmp_region->nxt_region;
		}

		/* If we have items in the list */
		if (tmp_region) {
			/*
			 * Check we didn't stop because the name
			 * clashes with one already defined.
			 */

			if (strcmp((const char *)region->name, (const char *)tmp_region->name) == 0 ||
			    tmp_region->nxt_region) {
				osa_mutex_unlock(global_lock);
				return IMG_ERROR_UNEXPECTED_STATE;
			}

			/* Add to end of list */
			tmp_region->nxt_region = region;
		} else {
			/* Add to head of list */
			context->regions = region;
		}

		context->no_regions++;

		/*
		 * Create an arena for memory allocation
		 * name of resource arena for debug
		 * start of resource
		 * size of resource
		 * allocation quantum
		 * import allocator
		 * import deallocator
		 * import handle
		 */
		result = vid_ra_create(region->name,
				       region->base_addr,
				       region->size,
				       1,
				       NULL,
				       NULL,
				       NULL,
				       &region->arena);

		if (result != IMG_SUCCESS) {
			osa_mutex_unlock(global_lock);
			return IMG_ERROR_UNEXPECTED_STATE;
		}
	}

	osa_mutex_unlock(global_lock);

	/* Check the arean was created OK */
	if (!region->arena)
		return IMG_ERROR_UNEXPECTED_STATE;

	return result;
}

int32 addr_malloc(const uint8 * const name,
		uint64 size,
		uint64 * const base_adr)
{
	return addr_cx_malloc(&global_ctx, name, size, base_adr);
}

int32 addr_cx_malloc(struct addr_context * const context,
		   const uint8 * const name,
		   uint64 size,
		   uint64 * const base_adr)
{
	uint32 result = IMG_ERROR_FATAL;
	struct addr_region *tmp_region = NULL;

	if (!context || !base_adr || !name)
		return IMG_ERROR_INVALID_PARAMETERS;

	*(base_adr) = (uint64)-1LL;

	osa_mutex_lock_nested(global_lock, OSA_SUBCLASS_ADDR_ALLOC);

	tmp_region = context->regions;

	/*
	 * Run down the list of existing named
	 * regions to locate this
	 */
	while (tmp_region &&
			(strcmp((const char *)name, (const char *)tmp_region->name) != 0) &&
			(tmp_region->nxt_region)) {
		tmp_region = tmp_region->nxt_region;
	}
	/* If there was no match. */
	if (!tmp_region ||
			(strcmp((const char *)name, (const char *)tmp_region->name) != 0)) {
		/* Use the default */
		if (!context->default_region) {
			osa_mutex_unlock(global_lock);
			return IMG_ERROR_UNEXPECTED_STATE;
		}

		tmp_region = context->default_region;
	}

	if (!tmp_region) {
		osa_mutex_unlock(global_lock);
		return IMG_ERROR_UNEXPECTED_STATE;
	}

	/* Allocate size + guard band */
	result = vid_ra_alloc(tmp_region->arena,
			      size + tmp_region->guard_band,
			      NULL,
			      NULL,
			      SEQUENTIAL_ALLOCATION,
			      1,
			      base_adr);
	if (result != IMG_SUCCESS) {
		osa_mutex_unlock(global_lock);
		return IMG_ERROR_OUT_OF_MEMORY;
	}

	osa_mutex_unlock(global_lock);

	return result;
}

int32 addr_cx_malloc_res(struct addr_context * const context,
		       const uint8 * const name,
		       uint64 size,
		       uint64 * const base_adr)
{
	uint32 result = IMG_ERROR_FATAL;
	struct addr_region *tmp_region = NULL;

	if (!context || !base_adr || !name)
		return IMG_ERROR_INVALID_PARAMETERS;

	osa_mutex_lock_nested(global_lock, OSA_SUBCLASS_ADDR_ALLOC);

	tmp_region = context->regions;
	/* If the allocation is for the default region */
	/*
	 * Run down the list of existing named
	 * regions to locate this
	 */
	while (tmp_region && (strcmp((const char *)name, (const char *)tmp_region->name) != 0)
			&& (tmp_region->nxt_region)) {
		tmp_region = tmp_region->nxt_region;
	}
	/* If there was no match. */
	if (!tmp_region || (strcmp((const char *)name, (const char *)tmp_region->name) != 0)) {
		/* Use the default */
		if (!context->default_region) {
			osa_mutex_unlock(global_lock);
			return IMG_ERROR_UNEXPECTED_STATE;
		}
		tmp_region = context->default_region;
	}
	if (!tmp_region) {
		osa_mutex_unlock(global_lock);
		return IMG_ERROR_UNEXPECTED_STATE;
	}
	/* Allocate size + guard band */
	result = vid_ra_alloc(tmp_region->arena, size + tmp_region->guard_band,
						NULL, NULL, SEQUENTIAL_ALLOCATION, 1, base_adr);
	if (result != IMG_SUCCESS) {
		osa_mutex_unlock(global_lock);
		return IMG_ERROR_OUT_OF_MEMORY;
	}
	osa_mutex_unlock(global_lock);

	return result;
}

int32 addr_cx_malloc_align_res(struct addr_context * const context,
			     const uint8 * const name,
			     uint64 size,
			     uint64 alignment,
			     uint64 * const base_adr)
{
	uint32 result;
	struct addr_region *tmp_region = NULL;

	if (!context || !base_adr || !name)
		return IMG_ERROR_INVALID_PARAMETERS;

	osa_mutex_lock_nested(global_lock, OSA_SUBCLASS_ADDR_ALLOC);

	tmp_region = context->regions;

	/*
	 * Run down the list of existing named
	 * regions to locate this
	 */
	while (tmp_region &&
	       (strcmp((const char *)name, (const char *)tmp_region->name) != 0) &&
	       (tmp_region->nxt_region)) {
		tmp_region = tmp_region->nxt_region;
	}
	/* If there was no match. */
	if (!tmp_region ||
	    (strcmp((const char *)name, (const char *)tmp_region->name) != 0)) {
		/* Use the default */
		if (!context->default_region) {
			osa_mutex_unlock(global_lock);
			return IMG_ERROR_UNEXPECTED_STATE;
		}

		tmp_region = context->default_region;
	}

	if (!tmp_region) {
		osa_mutex_unlock(global_lock);
		return IMG_ERROR_UNEXPECTED_STATE;
	}
	/* Allocate size + guard band */
	result = vid_ra_alloc(tmp_region->arena,
			      size + tmp_region->guard_band,
			      NULL,
			      NULL,
			      SEQUENTIAL_ALLOCATION,
			      alignment,
			      base_adr);
	if (result != IMG_SUCCESS) {
		osa_mutex_unlock(global_lock);
		return IMG_ERROR_OUT_OF_MEMORY;
	}

	osa_mutex_unlock(global_lock);

	return result;
}

int32 addr_free(const uint8 * const name, uint64 addr)
{
	return addr_cx_free(&global_ctx, name, addr);
}

int32 addr_cx_free(struct addr_context * const context,
		 const uint8 * const name,
		 uint64 addr)
{
	struct addr_region *tmp_region;
	uint32 result;

	if (!context)
		return IMG_ERROR_INVALID_PARAMETERS;

	tmp_region = context->regions;

	osa_mutex_lock_nested(global_lock, OSA_SUBCLASS_ADDR_ALLOC);

	/* If the allocation is for the default region */
	if (!name) {
		if (!context->default_region) {
			result = IMG_ERROR_INVALID_PARAMETERS;
			goto error;
		}
		tmp_region = context->default_region;
	} else {
		/*
		 * Run down the list of existing named
		 * regions to locate this
		 */
		while (tmp_region &&
		       (strcmp((const char *)name, (const char *)tmp_region->name) != 0) &&
		       tmp_region->nxt_region) {
			tmp_region = tmp_region->nxt_region;
		}

		/* If there was no match */
		if (!tmp_region || (strcmp((const char *)name, (const char *)tmp_region->name) != 0)) {
			/* Use the default */
			if (!context->default_region) {
				result = IMG_ERROR_INVALID_PARAMETERS;
				goto error;
			}
			tmp_region = context->default_region;
		}
	}

	/* Free the address */
	result = vid_ra_free(tmp_region->arena, addr);

error:
	osa_mutex_unlock(global_lock);
	return result;
}
