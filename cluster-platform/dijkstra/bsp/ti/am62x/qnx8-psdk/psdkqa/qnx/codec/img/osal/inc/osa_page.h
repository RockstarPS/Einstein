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
 * osa scatter gather page handling definitions
 */

#ifndef OSA_PAGE_H_
#define OSA_PAGE_H_

#include "osa_types.h"

#define osa_virt_to_page(x) ((void *)x)
#define osa_page_address(x) ((void *)x)


/* osa_sg_page() used for looking up the page belonging
 *   to an sg entry.*/
void *osa_sg_page(void *sgt_args);


/* osa_free_page() used to free the pages */
void osa_free_page(void *page);


/**
 * osa_sg_next - return the next scatterlist entry in a list
 * @sg:     The current sg entry
 *
 * Description:
 *   Usually the next entry will be @sg@ + 1, but if this sg element is part
 *   of a chained scatterlist, it could jump to the start of a new
 *   scatterlist array.
 *
 **/
void *osa_sg_next(void *sg);


/**
 * osa_sg_free_table - Free a previously allocated sg table
 * @table:  The mapped sg table header
 *
 **/
void osa_sg_free_table(void *table);


/**
 * osa_sg_set_page - Set sg entry to point at given page
 * @sg:      SG entry
 * @page:    The page
 * @len:     Length of data
 * @offset:  Offset into page
 *
 * Description:
 *   Use this function to set an sg entry pointing at a page, never assign
 *   the page directly. We encode sg table information in the lower bits
 *   of the page pointer. See osa_sg_page() for looking up the page belonging
 *   to an sg entry.
 *
 **/
void osa_sg_set_page(void *sg, void *page, uint32 len, uint32 offset);


void osa_dma_unmap_page(void *dev, uint64 addr, size_t size, int32 dir);


int32 osa_dma_mapping_error(void *dev, uint64 dma_addr);


uint64 osa_dma_map_page(void *dev, void *page, size_t offset, size_t size,
        int32 dir);


uint64 osa_page_to_phys(void *page);


/*
 * Allocate pages
 */
void *osa_alloc_page(int64 gfp_mask, void *sgt);


/**
 * osa_sg_alloc_table - Allocate and initialize an sg table
 * @table:  The sg table header to use
 * @nents:  Number of entries in sg list
 * @gfp_mask:   GFP allocation mask
 *
 *  Description:
 *    Allocate and initialize an sg table. If @nents@ is larger than
 *    SG_MAX_SINGLE_ALLOC a chained sg table will be setup.
 *
 **/
int32 osa_sg_alloc_table(void *table, uint32 nents, int64 gfp_mask, size_t size, void *ptr);

void osa_get_pages(void **page_args, void *sgt_args);


/**
 * osa_sg_nents - return total count of entries in scatterlist
 * @sg:     The scatterlist
 *
 * Description:
 * Allows to know how many entries are in sg, taking into acount
 * chaining as well
 *
 **/
int32 osa_sg_nents(void *sg);


void *osa_get_sgl(void *sgt_args);


uint32 osa_get_orig_nents(void *sgt_args);


uint32 osa_get_size_sgt(void);


void osa_set_sgt_nents(void *sgt_args, int32 ret);


/*
 * osa_dma_maps_sg returns 0 on error and > 0 on success.
 * It should never return a value < 0.
 */
int32 osa_dma_map_sg(void *dev, void *sg, int32 nents, int32 dir);


void osa_dma_unmap_sg(void *dev, void *sg, int32 nents, int32 dir);


void osa_dma_sync_sg_for_cpu(void *dev, void *sg, int32 nelems, int32 dir);


void osa_dma_sync_sg_for_device(void *dev, void *sg, int32 nelems, int32 dir);

void osa_set_sg_table(void **sg_table_args, void *buffer);

/**
 * osa_sg_phys - Return physical address of an sg entry
 * @sg:      SG entry
 *
 * Description:
 *   This calls osa_page_to_phys() on the page in this sg entry, and adds the
 *   sg offset. The caller must know that it is legal to call osa_page_to_phys()
 *   on the sg page.
 *
 **/
uint64 osa_sg_phys(void *sg);

uint32 osa_get_sgl_length(void *sgl_args);

void osa_mb(void);

#endif /* OSA_PAGE_H_ */
