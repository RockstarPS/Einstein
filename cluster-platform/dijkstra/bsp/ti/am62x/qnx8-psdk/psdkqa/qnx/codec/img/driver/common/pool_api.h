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
#ifndef __POOLAPI_H__
#define __POOLAPI_H__

#include "img_errors.h"
#include "lst.h"

/*
 * This is the prototype for "free" callback functions.  This function
 * is called when resources are returned to the pools list of free resources.
 * NOTE: The "freed" resource is then allocated and passed to the callback
 * function.
 */
typedef void (*pfrecalbkpntr)(uint32 ui32resid, void *resparam);

/*
 * This is the prototype for "destructor" callback functions.  This function
 * is called when a resource registered with the resource pool manager is to
 * be destroyed.
 */
typedef void (*pdestcallbkptr)(void *resparam, void *cb_handle);

/*
 * This function is used to initializes the resource pool manager component
 * and should be called at start-up.
 */
int32 pool_init(void);

/*
 * This function is used to deinitialises the resource pool manager component
 * and would normally be called at shutdown.
 */
void pool_deinit(void);

/*
 * This function is used to create a resource pool into which resources can be
 * placed.
 */
int32 pool_api_create(void **poolhndle);

/*
 * This function is used to destroy a resource pool.
 * NOTE: Destroying a resource pool destroys all of the resources within the
 * pool by calling the associated destructor function #POOL_pfnDestructor
 * defined when the resource what registered using POOL_ResRegister().
 *
 * NOTE: All of the pools resources must be in the pools free list - the
 * allocated list must be empty.
 */
int32 pool_destroy(void *poolhndle);

/*
 * This function is used to set or remove a free callback function on a pool.
 * The free callback function gets call for any resources already in the
 * pools free list or for any resources that subsequently get freed.
 * NOTE: The resource passed to the callback function has been allocated before
 * the callback is made.
 */
int32 pool_setfreecalbck(void *poolhndle, pfrecalbkpntr pfnfree);

/*
 * This function is used to register a resource within a resource pool.  The
 * resource is added to the pools allocated or free list based on the value
 * of bAlloc.
 */
int32 pool_resreg(void *poolhndle, pdestcallbkptr fndestructor,
		void *resparam, uint32 resparamsize,
		int32 balloc, uint32 *residptr,
		void **poolreshndle, void *cb_handle);

/*
 * This function is used to destroy a resource.
 */
int32 pool_resdestroy(void *poolreshndle, int32 bforce);

/*
 * This function is used to get/allocate a resource from a pool.  This moves
 * the resource from the free to allocated list.
 */
int32 pool_resalloc(void *poolhndle, void *poolreshndle);

/*
 * This function is used to free a resource and return it to the pools lists of
 * free resources.
 * NOTE: The resources is only moved to the free list when all references to
 * the resource have been freed.
 */
int32 pool_resfree(void *poolreshndle);

/*
 * This function is used to clone a resource - this creates an additional
 * reference to the resource.
 * NOTE: The resources is only moved to the free list when all references to
 * the resource have been freed.
 * NOTE: If this function is used to clone the resource's pvParam data then
 * the clone of the data is freed when the clone of the resource is freed.
 * The resource destructor is NOT used for this - simply an IMG_FREE.
 */
int32 pool_resclone(void *poolreshndle, void **clonereshndle, void **resparam);
#endif /* __POOLAPI_H__ */
