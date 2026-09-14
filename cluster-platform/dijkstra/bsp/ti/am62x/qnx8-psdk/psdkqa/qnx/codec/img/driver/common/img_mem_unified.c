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
 * IMG DEC Memory Manager for unified memory
 */

#include "osal/inc/osa_mem.h"
#include "osal/inc/osa_err.h"
#include "osal/inc/osa_page.h"
#include "osal/inc/osa_define.h"
#include "img_mem_man.h"

static int32 unified_alloc(void *device, struct heap *heap,
			 size_t size, enum mem_attr attr,
			 struct buffer *buffer)
{
	void *sgt;
	void *sgl;
	int32 pages;
	int32 ret;

	OSA_DEV_DBG(device, "%s:%d buffer %d (0x%p)\n", __func__, __LINE__,
		buffer->id, buffer);

	sgt = osa_malloc(osa_get_size_sgt(), OSA_GFP_KERNEL);
	if (!sgt)
		return -OSA_ENOMEM;

	pages = (size + OSA_PAGE_SIZE - 1) / OSA_PAGE_SIZE;

	ret = osa_sg_alloc_table(sgt, pages, OSA_GFP_KERNEL, buffer->actual_size, NULL);
	if (ret)
		goto sg_alloc_table_failed;

	sgl = osa_get_sgl(sgt);
	while (sgl) {
		void *page;
		uint64 dma_addr;

		page = osa_alloc_page(heap->options.unified.gfp_type, sgt);
		if (!page) {
			OSA_DEV_ERR(device, "%s alloc_page failed!\n", __func__);
			ret = -OSA_ENOMEM;
			goto alloc_page_failed;
		}

		/*
		 * dma_map_page() is probably going to fail if alloc flags are
		 * GFP_HIGHMEM, since it is not mapped to CPU. Hopefully, this
		 * will never happen because memory of this sort cannot be used
		 * for DMA anyway. To check if this is the case, build with
		 * debug, set trace_physical_pages=1 and check if page_address
		 * printed above is NULL
		 */
		dma_addr = osa_dma_map_page(device, page, 0, OSA_PAGE_SIZE,
					OSA_DMA_BIDIRECTIONAL);
		if (osa_dma_mapping_error(device, dma_addr)) {
			osa_free_page(page);
			OSA_DEV_ERR(device, "%s dma_map_page failed!\n", __func__);
			ret = -OSA_EIO;
			goto alloc_page_failed;
		}
		osa_dma_unmap_page(device, dma_addr, OSA_PAGE_SIZE, OSA_DMA_BIDIRECTIONAL);

		osa_sg_set_page(sgl, page, OSA_PAGE_SIZE, 0);

		sgl = osa_sg_next(sgl);
	}

	buffer->priv = sgt;
	return 0;

alloc_page_failed:
	sgl = osa_get_sgl(sgt);
	while (sgl) {
		void *page = osa_sg_page(sgl);

		if (page)
			osa_free_page(page);

		sgl = osa_sg_next(sgl);
	}
	osa_sg_free_table(sgt);
sg_alloc_table_failed:
	osa_free(sgt);
	return ret;
}

static void unified_free(struct heap *heap, struct buffer *buffer)
{
	void *dev = buffer->device;
	void *sgt = buffer->priv;
	void *sgl;

	OSA_DEV_DBG(dev, "%s:%d buffer %d (0x%p)\n", __func__, __LINE__,
		buffer->id, buffer);

	if (buffer->kptr) {
		OSA_DEV_DBG(dev, "%s vunmap 0x%p\n", __func__, buffer->kptr);
		osa_dma_unmap_sg(dev, osa_get_sgl(sgt), osa_get_orig_nents(sgt), DMA_FROM_DEVICE);
		osa_vunmap(buffer->kptr);
	}

	sgl = osa_get_sgl(sgt);
	while (sgl) {
		osa_free_page(osa_sg_page(sgl));
		sgl = osa_sg_next(sgl);
	}
	osa_sg_free_table(sgt);
	osa_free(sgt);
}

static int32 unified_map_km(struct heap *heap, struct buffer *buffer)
{
	void *dev = buffer->device;
	void *sgt = buffer->priv;
	void *sgl = osa_get_sgl(sgt);
	uint32 num_pages = osa_sg_nents(sgl);
	uint32 orig_nents = osa_get_orig_nents(sgt);
	void **pages;
	int32 ret;

	OSA_DEV_DBG(dev, "%s:%d buffer %d (0x%p)\n", __func__, __LINE__,
		buffer->id, buffer);

	if (buffer->kptr) {
		OSA_DEV_WARN(dev, "%s called for already mapped buffer %d\n",
			 __func__, buffer->id);
		return 0;
	}

	pages = osa_malloc_array(num_pages, sizeof(void *), OSA_GFP_KERNEL);
	if (!pages)
		return -OSA_ENOMEM;

	osa_get_pages(pages, sgt);

	buffer->kptr = osa_vmap((void **)pages, num_pages);
	osa_free(pages);
	if (!buffer->kptr) {
		OSA_DEV_ERR(dev, "%s vmap failed!\n", __func__);
		return -OSA_EFAULT;
	}

	ret = osa_dma_map_sg(dev, sgl, orig_nents, DMA_FROM_DEVICE);

	if (ret <= 0) {
		OSA_DEV_ERR(dev, "%s dma_map_sg failed!\n", __func__);
		osa_vunmap(buffer->kptr);
		return -OSA_EFAULT;
	}
	OSA_DEV_DBG(dev, "%s:%d buffer %d orig_nents %d nents %d\n", __func__,
		__LINE__, buffer->id, orig_nents, ret);

	osa_set_sgt_nents(sgt, ret);

	OSA_DEV_DBG(dev, "%s:%d buffer %d vmap to 0x%p\n", __func__, __LINE__,
		buffer->id, buffer->kptr);

	return 0;
}

static int32 unified_get_sg_table(struct heap *heap, struct buffer *buffer,
				void **sg_table)
{
    osa_set_sg_table(sg_table, buffer->priv);
	return 0;
}

static void unified_sync_cpu_to_dev(struct heap *heap, struct buffer *buffer)
{
	void *dev = buffer->device;
	void *sgt = buffer->priv;

	if (!buffer->kptr)
		return;

	OSA_DEV_DBG(dev, "%s:%d buffer %d (0x%p)\n", __func__, __LINE__,
		buffer->id, buffer);

	osa_dma_sync_sg_for_device(dev, osa_get_sgl(sgt), osa_get_orig_nents(sgt), OSA_DMA_TO_DEVICE);
}

static void unified_sync_dev_to_cpu(struct heap *heap, struct buffer *buffer)
{
	void *dev = buffer->device;
	void *sgt = buffer->priv;

	if (!buffer->kptr)
		return;

	OSA_DEV_DBG(dev, "%s:%d buffer %d (0x%p)\n", __func__, __LINE__,
		buffer->id, buffer);

	osa_dma_sync_sg_for_cpu(dev, osa_get_sgl(sgt), osa_get_orig_nents(sgt), OSA_DMA_FROM_DEVICE);
}

static void unified_heap_destroy(struct heap *heap)
{
}

static struct heap_ops unified_heap_ops = {
	.alloc = unified_alloc,
	.free = unified_free,
	.map_km = unified_map_km,
	.get_sg_table = unified_get_sg_table,
	.sync_cpu_to_dev = unified_sync_cpu_to_dev,
	.sync_dev_to_cpu = unified_sync_dev_to_cpu,
	.destroy = unified_heap_destroy,
};

int32 img_mem_unified_init(const struct heap_config *heap_cfg,
			 struct heap *heap)
{
	heap->ops = &unified_heap_ops;
	return 0;
}
