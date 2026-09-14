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
 * osa scatter gather page list handling implementation for QNX
 *
 * Copyright (c) Imagination Technologies Ltd.
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com/
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation version 2.
 *
 * This program is distributed "as is" WITHOUT ANY WARRANTY of any
 * kind, whether express or implied; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <inttypes.h>
#include <sys/types.h>
#include <sys/mman.h>

#include "../../inc/osa_define.h"
#include "../../inc/osa_page.h"
#include "../../inc/osa_mem.h"

#define SG_CHAIN	0x01UL
#define SG_END		0x02UL

void osa_get_pages(void **page_args, void *sgt_args)
{
    struct page **pages = (struct page **)page_args;
    struct sg_table *sgt = sgt_args;
    struct scatterlist *sgl = sgt->sgl;
    int32 i;

    i = 0;
    while (sgl) {
        pages[i++] = osa_sg_page(sgl);
        sgl = osa_sg_next(sgl);
    }
}

void *osa_sg_page(void *sg)
{
    struct scatterlist *sgl = sg;
    /* As only one page for each buffer in QNX, this should be NULL */
    return (struct page *)((sgl)->page_link & ~(SG_CHAIN | SG_END));
}

void osa_free_page(void *page)
{
    struct page *pagePtr = page;
    pagePtr->sgt = NULL;
    osa_free((void*)pagePtr);
}

void *osa_sg_next(void *sg)
{
    struct scatterlist *new_sg = sg;

    if (new_sg->end)
        return NULL;

    ++new_sg;
    return new_sg;
}

void osa_sg_free_table(void *table)
{
    struct sg_table *sgt = table;
    if (sgt->sgl->is_alloc_inside == 1)
    {
        munmap(sgt->sgl->dma_address, sgt->sgl->length);
        sgt->sgl->dma_address = NULL;
    }
    osa_free((void*)sgt->sgl);
    sgt->sgl = NULL;
}

void osa_sg_set_page(void *sg, void *page,
        uint32 len, uint32 offset)
{
    struct scatterlist *sgl = sg;
    struct page *pagePtr = page;
    unsigned long page_link = sgl->page_link & (SG_CHAIN | SG_END);

    /*
     * In order for the low bit stealing approach to work, pages
     * must be aligned at a 32-bit boundary as a minimum.
     */
    sgl->page_link = page_link | (unsigned long) pagePtr;
    sgl->offset = offset;
}

void osa_dma_unmap_page(void *dev,
        uint64 addr, size_t size,
        int32 dir)
{
    /* Nothing to do for QNX */
    return;
}

int32 osa_dma_mapping_error(void *dev, uint64 dma_addr)
{
    return 0;
}

uint64 osa_dma_map_page(void *dev,
        void *page,
        size_t offset, size_t size,
        int32 dir)
{
    int ret;
    int64_t addr = 0;
    size_t len = 0;
    struct sg_table *sgt = ((struct page *)page)->sgt;
    struct scatterlist *sgl = sgt->sgl;

    sgl->offset = offset;
    ret = mem_offset64(sgl->dma_address, NOFD, sgl->length, &addr, &len);
    if (ret) {
        OSA_PR_ERR("osa_page_to_phys: mem_offset failed");
        return 0;
    }
    return addr;
}

uint64 osa_page_to_phys(void *page)
{
    int ret;
    int64_t addr = 0;
    size_t len = 0;
    struct sg_table *sgt = ((struct page *)page)->sgt;
    struct scatterlist *sgl = sgt->sgl;

    ret = mem_offset64(sgl->dma_address, NOFD, sgl->length, &addr, &len);
    if (ret) {
        OSA_PR_ERR("osa_page_to_phys: mem_offset failed");
        return 0;
    }
    return addr;
}

void *osa_alloc_page(int64 gfp_mask, void *sgt)
{
    int64 flags = 0;

    struct page *page = osa_malloc((uint64)sizeof(struct page), flags);
    if(page != NULL)
        page->sgt = (struct sg_table*) sgt;

    return (page);
}

int32 osa_sg_alloc_table(void *table, uint32 nents, int64 gfp_mask, size_t size, void *ptr)
{
    int ret = 0;
    int64_t paddr;
    struct sg_table *sgt = table;
    struct scatterlist *sgl;
    int64 flags = 0;
    size_t len = 0;

    if (nents < 1)
    {
        return -1;
    }

    sgt->nents = nents;
    sgt->orig_nents = nents -1;

    sgl = osa_malloc((uint64)sizeof(struct scatterlist) * nents, flags);
    if(sgl == NULL)
    {
        OSA_PR_ERR("osa_sg_alloc_table: osa_malloc failed");
        return -1;
    }
    memset(sgl, 0, sizeof(*sgl) * nents);
    sgl[nents - 1].end = true;

    sgt->sgl = sgl;
    sgl->page_link = 0;

    if (size != 0 && ptr == NULL)
    {
        sgl->dma_address = mmap64(NULL, size,
                PROT_NOCACHE | PROT_READ | PROT_WRITE,
#if ZEROINIT_CHUNKS
                MAP_ANON | MAP_PHYS | MAP_SHARED,
#else
                MAP_ANON | MAP_PHYS | MAP_SHARED | MAP_NOINIT,
#endif
                NOFD,
                0);

        if (sgl->dma_address == MAP_FAILED) {
            sgl->dma_address = NULL;
            osa_free(sgl);
            return -1;
        }
        /* Make sure the memory is contiguous */
        ret = mem_offset64(sgl->dma_address, NOFD, size, &paddr, &len);
        if (ret || (len != size)) {
            munmap(sgl->dma_address, size);
            sgl->dma_address = NULL;
            osa_free(sgl);
            return -1;
        }
        else {
            sgt->nents = 1;
            sgl[0].end = true;
        }
        sgl->is_alloc_inside = 1;
    }
    else
    {
        sgl->dma_address = ptr;
        sgl->is_alloc_inside = 0;
    }
    sgl->offset = 0;
    sgl->length = size;

    return ret;
}

int32 osa_dma_map_sg(void *dev, void *sg, int32 nents, int32 dir)
{
    /* Nothing to do for QNX */

    return 1;
}

int32 osa_set_sgl_entry(void *sg, void *addr, uint32_t length)
{
    int ret;
    int64_t pa_addr;
    size_t len;
    struct scatterlist *sgl = sg;

    ret = mem_offset64(addr, NOFD, length, &pa_addr, &len);
    if (ret) {
        OSA_PR_ERR("osa_set_sgl_entry: mem_offset failed");
        return -1;
    }
    sgl->dma_address = addr;
    sgl->length = len;
    return 0;
}

uint32_t osa_get_nents(void *addr, uint32_t len)
{
    uint32_t bytes = len;
    struct scatterlist sgl;
    uint32_t offset = 0;
    uint32_t nents = 0;

    while (bytes) {
        osa_set_sgl_entry(&sgl, addr + offset, bytes);
        offset += sgl.length;
        bytes -= sgl.length;
        nents++;
    }

    return nents;
}

int32 osa_sg_nents(void *sg)
{
    struct page *page = (struct page *)osa_sg_page(sg);
    return page->sgt->nents;
}

void *osa_get_sgl(void *sgt_args)
{
    struct sg_table *sgt = sgt_args;
    return sgt->sgl;
}

uint32 osa_get_orig_nents(void *sgt_args)
{
    struct sg_table *sgt = sgt_args;
    return sgt->orig_nents;
}

uint32 osa_get_size_sgt(void)
{
    return sizeof(struct sg_table);
}

void osa_set_sgt_nents(void *sgt_args, int32 ret)
{
    struct sg_table *sgt = sgt_args;
    sgt->nents = ret;
}

void osa_dma_unmap_sg(void *dev, void *sg, int32 nents, int32 dir)
{
    /* Nothing to do for QNX */

    return;
}

void osa_dma_sync_sg_for_cpu(void *dev, void *sg, int32 nelems, int32 dir)
{
    /* Nothing to do for QNX */
    return;
}

void osa_dma_sync_sg_for_device(void *dev, void *sg, int32 nelems, int32 dir)
{
    /* Nothing to do for QNX */
    return;
}

void osa_set_sg_table(void **sg_table_args, void *buffer)
{
    struct sg_table **sg_table = (struct sg_table **)sg_table_args;
    *sg_table = buffer;
}

uint64 osa_sg_phys(void *sg)
{
    int ret;
    int64_t addr;
    size_t len;
    struct scatterlist *sgl = sg;

    ret = mem_offset64(sgl->dma_address, NOFD, sgl->length, &addr, &len);
    if (ret) {
        OSA_PR_ERR("osa_sg_page: mem_offset failed");
        return 0;
    }
    return (addr + sgl->offset);
}

uint32 osa_get_sgl_length(void *sgl_args)
{
    struct scatterlist *sgl = (struct scatterlist *)sgl_args;
    return sgl->length;
}

void osa_mb(void)
{
    /* Nothing to do for QNX */
    return;
}
