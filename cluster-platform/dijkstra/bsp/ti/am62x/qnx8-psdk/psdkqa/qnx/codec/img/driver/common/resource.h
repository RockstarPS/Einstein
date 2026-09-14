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
 * VXD DEC SYSDEV and UI Interface header
 */

#ifndef _VXD_RESOURCE_H
#define _VXD_RESOURCE_H

typedef int32 (*resource_pfn_freeitem)(void *item, void *free_cb_param);

int32 resource_item_use(uint32 *refcnt);

void resource_item_return(uint32 *refcnt);

int32 resource_item_release(uint32 *refcnt);

int32 resource_item_isavailable(uint32 *refcnt);

int32 resource_list_add(struct lst_t *list, void *item, uint32 id, uint32 *refcnt);

void *resource_list_pickhead(struct lst_t *list);

int32 resource_list_remove(struct lst_t *list, void *item);

void *resource_list_removehead(struct lst_t *list);

int32 resource_list_remove_nextavail(struct lst_t *list,
				   resource_pfn_freeitem fn_freeitem,
				   void *free_cb_param);

void *resource_list_get_avail(struct lst_t *list);

void *resource_list_reuseitem(struct lst_t *list, void *item);

void *resource_list_getbyid(struct lst_t *list, uint32 id);

int32 resource_list_getnumavail(struct lst_t *list);

int32 resource_list_getnum(struct lst_t *list);

int32 resource_list_replace(struct lst_t *list, void *item, uint32 id, uint32 *refcnt,
			  resource_pfn_freeitem fn_freeitem,
			  void *free_cb_param);

int32 resource_list_empty(struct lst_t *list, uint32 release_item,
			resource_pfn_freeitem fn_freeitem,
			void *free_cb_param);

int32 resource_getnumpict(struct lst_t *list);

#endif /* _VXD_RESOURCE_H */
