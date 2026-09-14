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
 * VXD DEC Resource manager implementations
 */

#include "osal/inc/osa_mem.h"
#include "osal/inc/osa_types.h"
#include "osal/inc/osa_define.h"
#include "dq.h"
#include "img_errors.h"
#include "lst.h"
#include "resource.h"

struct resource_list_elem {
	struct dq_linkage_t	link;
	void *item;
	uint32 id;
	uint32 *refcnt;
};

/*
 * marks an item as used by incrementing the reference count
 */
int32 resource_item_use(uint32 *refcnt)
{
	if (refcnt)
		(*refcnt)++;

	return 0;
}

/*
 * returns an item by decrementing the reference count
 */
void resource_item_return(uint32 *refcnt)
{
	if (refcnt && *refcnt > 0)
		(*refcnt)--;

	return;
}

/*
 * releases an item by setting reference count to 1 (original owner)
 */
int32 resource_item_release(uint32 *refcnt)
{
	if (refcnt)
		*refcnt = 1;

	return 0;
}

/*
 * indicates whether an item is free to be used (no owners)
 */
int32 resource_item_isavailable(uint32 *refcnt)
{
	if (refcnt)
		return (*refcnt == 0) ? 1 : 0;
	else
		return 0;
}

/*
 * adds an item (and associated id) to a resource list
 */
int32 resource_list_add(struct lst_t *list, void *item, uint32 id, uint32 *refcnt)
{
	struct resource_list_elem *listelem = NULL;
	int32 bfound = 0;
	uint32 result = 0;

	if (!list || !item) {
		result = IMG_ERROR_INVALID_PARAMETERS;
		goto error;
	}

	/*
	 * Decrement the reference count on the item
	 * to signal that the owner has relinquished it.
	 */
	resource_item_return(refcnt);

	/*
	 *  Determine whether this buffer is already in the list.
	 */
	listelem = lst_first(list);
	while (listelem) {
		if (listelem->item == item) {
			bfound = 1;
			break;
		}

		listelem = lst_next(listelem);
	}

	if (!bfound) {
		/*
		 * allocate the image buffer list element structure.
		 */
		listelem = osa_malloc(sizeof(*(listelem)), OSA_GFP_KERNEL);
		if (!listelem) {
			result = IMG_ERROR_OUT_OF_MEMORY;
			goto error;
		}
		memset(listelem, 0, sizeof(*(listelem)));

		/*
		 * setup the list element.
		 */
		listelem->item = item;
		listelem->id = id;
		listelem->refcnt = refcnt;

		/*
		 * add the element to the list.
		 */
		lst_add(list, (void *)listelem);
	}

	return 0;

error:
	return result;
}

/*
 * obtains pointer to item at head of resource list
 */
void *resource_list_pickhead(struct lst_t *list)
{
	struct resource_list_elem *listelem = NULL;
	void *item = NULL;

	if (!list)
		goto error;
	/*
	 * peek the head item of the list.
	 */
	listelem = lst_first(list);
	if (listelem)
		item = listelem->item;

error:
	return item;
}

/*
 * removes item from resource list
 */
int32 resource_list_remove(struct lst_t *list, void *item)
{
	struct resource_list_elem *listelem = NULL;
	uint32 result = 0;

	if (!list || !item) {
		result = IMG_ERROR_INVALID_PARAMETERS;
		goto error;
	}

	/*
	 * find the specified item in the list.
	 */
	listelem = lst_first(list);
	while (listelem) {
		if (listelem->item == item) {
			if (*listelem->refcnt != 0)
				OSA_PR_WARN("item remove from list still in use\n");

			/*
			 * Remove the item from the list.
			 */
			lst_remove(list, listelem);
			/*
			 * Free the stream unit queue element.
			 */
			osa_free(listelem);
			listelem = NULL;
			return 0;
		}

		listelem = lst_next(listelem);
	}

	OSA_PR_INFO("item could not be located to remove from RESOURCE list\n");

	return IMG_ERROR_COULD_NOT_OBTAIN_RESOURCE;

error:
	return result;
}

/*
 * removes item at head of resource list
 */
void *resource_list_removehead(struct lst_t *list)
{
	struct resource_list_elem *listelem = NULL;
	void *item = NULL;

	if (!list)
		goto error;

	/*
	 * peek the head item of the list.
	 */
	listelem = lst_removehead(list);
	if (listelem) {
		item = listelem->item;
		osa_free(listelem);
		listelem = NULL;
	}

error:
	return item;
}

/*
 * removes next available item from resource list.
 * item is freed if no longer used
 */
int32 resource_list_remove_nextavail(struct lst_t *list,
				   resource_pfn_freeitem fn_freeitem,
				   void *free_cb_param)
{
	struct resource_list_elem *listelem = NULL;
	uint32 result = IMG_ERROR_COULD_NOT_OBTAIN_RESOURCE;

	if (!list) {
		result = IMG_ERROR_INVALID_PARAMETERS;
		goto error;
	}

	/*
	 * find the next unused item in the list.
	 */
	listelem = lst_first(list);
	while (listelem) {
		if (resource_item_isavailable(listelem->refcnt)) {
			resource_item_return(listelem->refcnt);

			if(*listelem->refcnt == 0) {
				if (fn_freeitem)
					fn_freeitem(listelem->item,
							free_cb_param);
				else
					osa_free(listelem->item);

				listelem->item = NULL;
			}

			/*
			 * get the next element from the list.
			 */
			lst_remove(list, listelem);

			/*
			 * free the buffer list element.
			 */
			osa_free(listelem);
			listelem = NULL;

			result = 0;
			break;
		}

		listelem = lst_next(listelem);
	}

	if (result == IMG_ERROR_COULD_NOT_OBTAIN_RESOURCE)
		OSA_PR_DEBUG("failed to locate an available resource element to remove\n");

error:
	return result;
}

/*
 * obtains pointer to an available item from the resource list
 */
void *resource_list_get_avail(struct lst_t *list)
{
	struct resource_list_elem *listelem = NULL;
	void *item = NULL;

	if (!list)
		goto error;

	/*
	 * find the next unused item in the list.
	 */
	listelem = lst_first(list);
	while (listelem) {
		if (resource_item_isavailable(listelem->refcnt)) {
			resource_item_use(listelem->refcnt);
			item = listelem->item;
			break;
		}
		listelem = lst_next(listelem);
	}

error:
	return item;
}

/*
 * signal duplicate use of specified item with resource list
 */
void *resource_list_reuseitem(struct lst_t *list, void *item)
{
	struct resource_list_elem *listelem = NULL;
	void *ret_item  = NULL;

	if (!list || !item)
		goto error;

	/*
	 * find the specified item in the list.
	 */
	listelem = lst_first(list);

	while (listelem) {
		if (listelem->item == item) {
			resource_item_use(listelem->refcnt);
			ret_item = item;
			break;
		}

		listelem = lst_next(listelem);
	}

error:
	return ret_item;
}

/*
 * obtain pointer to item from resource list with id
 */
void *resource_list_getbyid(struct lst_t *list, uint32 id)
{
	struct resource_list_elem *listelem = NULL;
	void *item  = NULL;

	if (!list)
		goto error;

	/*
	 * find the next unused buffer in the list.
	 */
	listelem = lst_first(list);
	while (listelem) {
		if (listelem->id == id) {
			resource_item_use(listelem->refcnt);
			item = listelem->item;
			break;
		}

		listelem = lst_next(listelem);
	}

error:
	return item;
}

/*
 * obtain the number of available (unused) items within list.
 */
int32 resource_list_getnumavail(struct lst_t *list)
{
	struct resource_list_elem *listelem = NULL;
	uint32 num_items = 0;

	if (!list)
		goto error;

	/*
	 * find the next unused buffer in the list.
	 */
	listelem = lst_first(list);
	while (listelem) {
		if (resource_item_isavailable(listelem->refcnt))
			num_items++;

		listelem = lst_next(listelem);
	}

error:
	return num_items;
}

/*
 * Obtain the number of items within list
 */
int32 resource_list_getnum(struct lst_t *list)
{
	struct resource_list_elem *listelem = NULL;
	uint32 num_items = 0;

	if (!list)
		goto error;

	/*
	 * find the next unused buffer in the list.
	 */
	listelem = lst_first(list);
	while (listelem) {
		num_items++;
		listelem = lst_next(listelem);
	}

error:
	return num_items;
}

/*
 * replaces an item (of specified id) within a resource list
 */
int32 resource_list_replace(struct lst_t *list, void *item, uint32 id, uint32 *refcnt,
			  resource_pfn_freeitem fn_freeitem,
			  void *free_cb_param)
{
	struct resource_list_elem *listelem = NULL;
	uint32 result = 0;

	if (!list || !item) {
		result = IMG_ERROR_INVALID_PARAMETERS;
		goto error;
	}

	/*
	 * determine whether this sequence header is already in the list
	 */
	listelem = lst_first(list);
	while (listelem) {
		if (listelem->id == id) {
			resource_item_return(listelem->refcnt);
			if (*listelem->refcnt == 0) {
				if (fn_freeitem)
					fn_freeitem(listelem->item,
						    free_cb_param);
				else
					osa_free(listelem->item);
				listelem->item = NULL;
			}

			lst_remove(list, listelem);
			break;
		}

		listelem = lst_next(listelem);
	}

	if (!listelem) {
		/*
		 * Allocate the sequence header list element structure.
		 */
		listelem = osa_malloc(sizeof(*(listelem)), OSA_GFP_KERNEL);
		if (!listelem) {
			result = IMG_ERROR_OUT_OF_MEMORY;
			goto error;
		}
		memset(listelem, 0, sizeof(*(listelem)));
	}

	/*
	 * setup the sequence header list element.
	 */
	resource_item_use(refcnt);

	listelem->item = item;
	listelem->id = id;
	listelem->refcnt = refcnt;

	/*
	 * Add the sequence header list element to the sequence header list.
	 */
	lst_add(list, (void *)listelem);

	return 0;

error:
	return result;
}

/*
 * removes all items from a resource list.
 */
int32 resource_list_empty(struct lst_t *list, uint32 release_item,
			resource_pfn_freeitem fn_freeitem,
			void *free_cb_param)
{
	struct resource_list_elem *listelem = NULL;
	uint32 result = 0;

	if (!list) {
		result = IMG_ERROR_INVALID_PARAMETERS;
		goto error;
	}

	/*
	 * remove all the buffer list elements from the image buffer list
	 */
	listelem = lst_removehead(list);
	while (listelem) {
		if (release_item) {
			resource_item_release(listelem->refcnt);
		} else {
			/*
			 * Return and free.
			 */
			resource_item_return(listelem->refcnt);

			if (!listelem->refcnt || *listelem->refcnt == 0) {
				if (fn_freeitem)
					fn_freeitem(listelem->item,
						    free_cb_param);
				else
					osa_free(listelem->item);
				listelem->item = NULL;
			}
		}

		/*
		 * free the buffer list element.
		 */
		osa_free(listelem);
		listelem = NULL;

		/*
		 * Get the next element from the list.
		 */
		listelem = lst_removehead(list);
	}

	return 0;

error:
	return result;
}

/*
 * obtain the number of pictures within list
 */
int32 resource_getnumpict(struct lst_t *list)
{
	struct resource_list_elem *listelem = NULL;
	uint32 num_pict = 0;

	if (!list)
		goto error;

	/*
	 * find the next unused buffer in the list.
	 */
	listelem = lst_first(list);
	while (listelem) {
		num_pict++;
		listelem = lst_next(listelem);
	}

error:
	return num_pict;
}
