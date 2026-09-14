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
 * IMG DEC Memory Manager
 */

#include "osal/inc/osa_mem.h"
#include "osal/inc/osa_mutex.h"
#include "osal/inc/osa_list.h"
#include "osal/inc/osa_err.h"
#include "./osal/inc/osa_idr.h"
#include "./osal/inc/osa_page.h"
#include "osal/inc/osa_define.h"
#include "imgmmu.h"
#include "img_mem_man.h"

#define VXD_MMU_SHIFT 8 /* assume 40-bit MMU */
/* heaps ids (global) */
#define MIN_HEAP 1
#define MAX_HEAP 16

/*
 * struct dev_mem_man - the device memory management
 * @heaps: idr list of heap for the device memory manager
 * @mem_ctxs: contains lists of mem_ctx
 * @mutex: mutex for this device
 */
struct mem_man {
	void *dev;
	void *heaps;
	struct clist_head mem_ctxs;
	void *mutex; /* mutex for this device */
};

static struct mem_man mem_man_data = {0};

/*
 * struct mmu_page - the mmu page information for the buffer
 * @buffer: buffer pointer for the particular mmu_page
 * @page_cfg: mmu page configuration of physical and virtual addr
 * @addr_shift: address shifting information
 */
struct mmu_page {
	struct buffer *buffer;
	struct mmu_page_cfg page_cfg;
	uint32 addr_shift;
};

static void _img_mem_free(struct buffer *buffer);
static void _img_mmu_unmap(struct mmu_ctx_mapping *mapping);
static void _img_mmu_ctx_destroy(struct mmu_ctx *ctx);

#if defined (DEBUG_DECODER_DRIVER) | defined (DEBUG_ENCODER_DRIVER)
static uint8 *get_heap_name(enum heap_type type)
{
	switch (type) {
	case MEM_HEAP_TYPE_UNIFIED:
		return (uint8*)"unified";
	default:
		return (uint8*)"unknown";
	}
}
#endif

int32 img_mem_add_heap(const struct heap_config *heap_cfg, int32 *heap_id)
{
	struct mem_man *mem_man = &mem_man_data;
	struct heap *heap;
	int32 (*init_fn)(const struct heap_config *heap_cfg, struct heap *heap);
	int32 ret;

	switch (heap_cfg->type) {
	case MEM_HEAP_TYPE_UNIFIED:
		init_fn = img_mem_unified_init;
		break;
	default:
		OSA_DEV_ERR(mem_man->dev, "%s: heap type %d unknown\n", __func__,
			heap_cfg->type);
		return -OSA_EINVAL;
	}

	heap = osa_malloc(sizeof(*heap), OSA_GFP_KERNEL);
	if (!heap)
		return -OSA_ENOMEM;

	ret = osa_mutex_lockinterruptible_nested(mem_man->mutex, OSA_SUBCLASS_IMGMEM);
	if (ret)
		goto lock_failed;

	ret = osa_idr_alloc(mem_man->heaps, heap, MIN_HEAP, MAX_HEAP);
	if (ret < 0) {
		OSA_DEV_ERR(mem_man->dev, "%s: idr_alloc failed\n", __func__);
		goto alloc_id_failed;
	}

	heap->id = ret;
	heap->type = heap_cfg->type;
	heap->options = heap_cfg->options;
	heap->to_dev_addr = heap_cfg->to_dev_addr;
	heap->priv = NULL;

	ret = init_fn(heap_cfg, heap);
	if (ret) {
		OSA_DEV_ERR(mem_man->dev, "%s: heap init failed\n", __func__);
		goto heap_init_failed;
	}

	*heap_id = heap->id;
	osa_mutex_unlock(mem_man->mutex);

#if defined (DEBUG_DECODER_DRIVER) | defined (DEBUG_ENCODER_DRIVER)
	OSA_DEV_INFO(mem_man->dev, "%s created heap %d type %d (%s)\n",
		 __func__, *heap_id, heap_cfg->type, get_heap_name(heap->type));
#endif
	return 0;

heap_init_failed:
	osa_idr_remove(mem_man->heaps, heap->id);
alloc_id_failed:
	osa_mutex_unlock(mem_man->mutex);
lock_failed:
	osa_free(heap);
	return ret;
}

static void _img_mem_del_heap(struct heap *heap)
{
	struct mem_man *mem_man = &mem_man_data;

	if (heap->ops->destroy)
		heap->ops->destroy(heap);

	osa_idr_remove(mem_man->heaps, heap->id);
}

void img_mem_del_heap(int32 heap_id)
{
	struct mem_man *mem_man = &mem_man_data;
	struct heap *heap;

	osa_mutex_lock_nested(mem_man->mutex, OSA_SUBCLASS_IMGMEM);

	heap = osa_idr_find(mem_man->heaps, heap_id);
	if (!heap) {
		OSA_DEV_WARN(mem_man->dev, "%s heap %d not found!\n", __func__,
			 heap_id);
		osa_mutex_unlock(mem_man->mutex);
		return;
	}

	_img_mem_del_heap(heap);

	osa_mutex_unlock(mem_man->mutex);

	osa_free(heap);
}

int32 img_mem_create_ctx(struct mem_ctx **new_ctx)
{
	struct mem_man *mem_man = &mem_man_data;
	struct mem_ctx *ctx;

	ctx = osa_zalloc(sizeof(*ctx), OSA_GFP_KERNEL);
	if (!ctx)
		return -OSA_ENOMEM;

	osa_idr_init(&ctx->buffers);
	if(NULL == ctx->buffers)
	{
		return OSA_ENOMEM;
	}

	INIT_OSA_LIST_HEAD(&ctx->mmu_ctxs);

	osa_mutex_lock_nested(mem_man->mutex, OSA_SUBCLASS_IMGMEM);
	osa_list_add(&ctx->mem_man_entry, &mem_man->mem_ctxs);
	osa_mutex_unlock(mem_man->mutex);

	*new_ctx = ctx;
	return 0;
}

static void _img_mem_destroy_ctx(struct mem_ctx *ctx)
{
	struct mem_man *mem_man = &mem_man_data;
	struct buffer *buffer;
	int32 buff_id;

	/* free derelict mmu contexts */
	while (!osa_list_empty(&ctx->mmu_ctxs)) {
		struct mmu_ctx *mc;

		mc = osa_list_first_entry(&ctx->mmu_ctxs,
				      struct mmu_ctx, mem_ctx_entry);
		OSA_DEV_WARN(mem_man->dev, "%s: found derelict mmu context %p\n",
			 __func__, mc);
		_img_mmu_ctx_destroy(mc);
		osa_free(mc);
	}

	/* free derelict buffers */
	buff_id = MEM_MAN_MIN_BUFFER;
	buffer = osa_idr_get_next(ctx->buffers, &buff_id);
	while (buffer) {
		OSA_DEV_WARN(mem_man->dev, "%s: found derelict buffer %d\n",
			 __func__, buff_id);
		if (buffer->heap)
			_img_mem_free(buffer);
		else
			osa_idr_remove(ctx->buffers, buffer->id);
		osa_free(buffer);
		buff_id = MEM_MAN_MIN_BUFFER;
		buffer = osa_idr_get_next(ctx->buffers, &buff_id);
	}

	osa_idr_destroy(ctx->buffers);
	osa_list_del(&ctx->mem_man_entry);
}

void img_mem_destroy_ctx(struct mem_ctx *ctx)
{
	struct mem_man *mem_man = &mem_man_data;

	osa_mutex_lock_nested(mem_man->mutex, OSA_SUBCLASS_IMGMEM);
	_img_mem_destroy_ctx(ctx);
	osa_mutex_unlock(mem_man->mutex);

	osa_free(ctx);
}

static int32 _img_mem_alloc(void *device, struct mem_ctx *ctx,
			  struct heap *heap, size_t size,
			  enum mem_attr attr, struct buffer **buffer_new)
{
	struct buffer *buffer;
	int32 ret;

	if (size == 0) {
		OSA_DEV_ERR(device, "%s: buffer size is zero\n", __func__);
		return -OSA_EINVAL;
	}

	if (!heap->ops || !heap->ops->alloc) {
		OSA_DEV_ERR(device, "%s: no alloc function in heap %d!\n",
			__func__, heap->id);
		return -OSA_EINVAL;
	}

	buffer = osa_zalloc(sizeof(*buffer), OSA_GFP_KERNEL);
	if (!buffer)
		return -OSA_ENOMEM;

	ret = osa_idr_alloc(ctx->buffers, buffer,
			MEM_MAN_MIN_BUFFER, MEM_MAN_MAX_BUFFER);
	if (ret < 0) {
		OSA_DEV_ERR(device, "%s: idr_alloc failed\n", __func__);
		goto idr_alloc_failed;
	}

	buffer->id = ret;
	buffer->request_size = size;
	buffer->actual_size = ((size + OSA_PAGE_SIZE - 1) / OSA_PAGE_SIZE) * OSA_PAGE_SIZE;
	buffer->device = device;
	buffer->mem_ctx = ctx;
	buffer->heap = heap;
	INIT_OSA_LIST_HEAD(&buffer->mappings);
	buffer->kptr = NULL;
	buffer->priv = NULL;

	ret = heap->ops->alloc(device, heap, buffer->actual_size, attr,
		buffer);
	if (ret) {
		OSA_DEV_ERR(device, "%s: heap %d alloc failed\n", __func__,
			heap->id);
		goto heap_alloc_failed;
	}

	*buffer_new = buffer;

	OSA_DEV_DBG(device, "%s heap %p ctx %p created buffer %d (%p) actual_size %zu\n",
		__func__, heap, ctx, buffer->id, buffer, buffer->actual_size);
	return 0;

heap_alloc_failed:
	osa_idr_remove(ctx->buffers, buffer->id);
idr_alloc_failed:
	osa_free(buffer);
	return ret;
}

int32 img_mem_alloc(void *device, struct mem_ctx *ctx, int32 heap_id,
		  size_t size, enum mem_attr attr, int32 *buf_id)
{
	struct mem_man *mem_man = &mem_man_data;
	struct heap *heap;
	struct buffer *buffer;
	int32 ret;

	OSA_DEV_DBG(device, "%s heap %d ctx %p size %zu\n", __func__, heap_id,
		ctx, size);

	ret = osa_mutex_lockinterruptible_nested(mem_man->mutex, OSA_SUBCLASS_IMGMEM);
	if (ret)
		return ret;

	heap = osa_idr_find(mem_man->heaps, heap_id);
	if (!heap) {
		OSA_DEV_ERR(device, "%s: heap id %d not found\n", __func__,
			heap_id);
		osa_mutex_unlock(mem_man->mutex);
		return -OSA_EINVAL;
	}

	ret = _img_mem_alloc(device, ctx, heap, size, attr, &buffer);
	if (ret) {
		osa_mutex_unlock(mem_man->mutex);
		return ret;
	}

	*buf_id = buffer->id;
	osa_mutex_unlock(mem_man->mutex);

	OSA_DEV_DBG(device, "%s heap %d ctx %p created buffer %d (%p) size %zu\n",
		__func__, heap_id, ctx, *buf_id, buffer, size);
	return ret;
}

static int32 _img_mem_import(void *device, struct mem_ctx *ctx,
			   size_t size, enum mem_attr attr, struct buffer **buffer_new)
{
	struct buffer *buffer;
	int32 ret;

	if (size == 0) {
		OSA_DEV_ERR(device, "%s: buffer size is zero\n", __func__);
		return -OSA_EINVAL;
	}

	buffer = osa_zalloc(sizeof(*buffer), OSA_GFP_KERNEL);
	if (!buffer)
		return -OSA_ENOMEM;

	ret = osa_idr_alloc(ctx->buffers, buffer,
			MEM_MAN_MIN_BUFFER, MEM_MAN_MAX_BUFFER);
	if (ret < 0) {
		OSA_DEV_ERR(device, "%s: idr_alloc failed\n", __func__);
		goto idr_alloc_failed;
	}

	buffer->id = ret;
	buffer->request_size = size;
	buffer->actual_size = ((size + OSA_PAGE_SIZE - 1) / OSA_PAGE_SIZE) * OSA_PAGE_SIZE;
	buffer->device = device;
	buffer->mem_ctx = ctx;
	buffer->heap = NULL;
	INIT_OSA_LIST_HEAD(&buffer->mappings);
	buffer->kptr = NULL;
	buffer->priv = NULL;

	*buffer_new = buffer;

	OSA_DEV_DBG(device, "%s ctx %p created buffer %d (%p) actual_size %zu\n",
		__func__, ctx, buffer->id, buffer, buffer->actual_size);
	return 0;

idr_alloc_failed:
	osa_free(buffer);
	return ret;
}

int32 img_mem_import(void *device, struct mem_ctx *ctx,
		   size_t size, enum mem_attr attr, int32 *buf_id)
{
	struct mem_man *mem_man = &mem_man_data;
	struct buffer *buffer;
	int32 ret;

	OSA_DEV_DBG(device, "%s ctx %p size %zu\n", __func__, ctx, size);

	ret = osa_mutex_lockinterruptible_nested(mem_man->mutex, OSA_SUBCLASS_IMGMEM);
	if (ret)
		return ret;

	ret = _img_mem_import(device, ctx, size, attr, &buffer);
	if (ret) {
		osa_mutex_unlock(mem_man->mutex);
		return ret;
	}

	*buf_id = buffer->id;
	osa_mutex_unlock(mem_man->mutex);

	OSA_DEV_DBG(device, "%s ctx %p created buffer %d (%p) size %zu\n",
		__func__, ctx, *buf_id, buffer, size);
	return ret;
}

static void _img_mem_free(struct buffer *buffer)
{
	void *dev = buffer->device;
	struct heap *heap = buffer->heap;
	struct mem_ctx *ctx = buffer->mem_ctx;

	if (!heap->ops || !heap->ops->free) {
		OSA_DEV_ERR(dev, "%s: no free function in heap %d!\n",
			__func__, heap->id);
		return;
	}

	while (!osa_list_empty(&buffer->mappings)) {
		struct mmu_ctx_mapping *map;

		map = osa_list_first_entry(&buffer->mappings,
				       struct mmu_ctx_mapping, buffer_entry);
		OSA_DEV_WARN(dev, "%s: found mapping for buffer %d (size %zu)\n",
			 __func__, map->buffer->id, map->buffer->actual_size);

		_img_mmu_unmap(map);

		osa_free(map);
	}

	heap->ops->free(heap, buffer);

	osa_idr_remove(ctx->buffers, buffer->id);
}

void img_mem_free(struct mem_ctx *ctx, int32 buff_id)
{
	struct mem_man *mem_man = &mem_man_data;
	struct buffer *buffer;

	osa_mutex_lock_nested(mem_man->mutex, OSA_SUBCLASS_IMGMEM);

	buffer = osa_idr_find(ctx->buffers, buff_id);
	if (!buffer) {
		OSA_DEV_ERR(mem_man->dev, "%s: buffer id %d not found\n",
			__func__, buff_id);
		osa_mutex_unlock(mem_man->mutex);
		return;
	}

	_img_mem_free(buffer);

	osa_mutex_unlock(mem_man->mutex);

	osa_free(buffer);
}

void img_mem_free_bufid(struct mem_ctx *ctx, int32 buff_id)
{
	struct mem_man *mem_man = &mem_man_data;
	struct buffer *buffer;

	osa_mutex_lock_nested(mem_man->mutex, OSA_SUBCLASS_IMGMEM);

	buffer = osa_idr_find(ctx->buffers, buff_id);
	if (!buffer) {
		OSA_DEV_ERR(mem_man->dev, "%s: buffer id %d not found\n",
			__func__, buff_id);
		osa_mutex_unlock(mem_man->mutex);
		return;
	}

	osa_idr_remove(ctx->buffers, buffer->id);

	osa_mutex_unlock(mem_man->mutex);

	osa_free(buffer);
}

static int32 _img_mem_map_km(struct buffer *buffer)
{
	void *dev = buffer->device;
	struct heap *heap = buffer->heap;

	if (!heap->ops || !heap->ops->map_km) {
		OSA_DEV_ERR(dev, "%s: no map_km in heap %d!\n", __func__, heap->id);
		return -OSA_EINVAL;
	}

	return heap->ops->map_km(heap, buffer);
}

int32 img_mem_map_km(struct mem_ctx *ctx, int32 buff_id)
{
	struct mem_man *mem_man = &mem_man_data;
	struct buffer *buffer;
	int32 ret;

	osa_mutex_lock_nested(mem_man->mutex, OSA_SUBCLASS_IMGMEM);
	buffer = osa_idr_find(ctx->buffers, buff_id);
	if (!buffer) {
		OSA_DEV_ERR(mem_man->dev, "%s: buffer id %d not found\n",
			__func__, buff_id);
		osa_mutex_unlock(mem_man->mutex);
		return -OSA_EINVAL;
	}

	ret = _img_mem_map_km(buffer);

	osa_mutex_unlock(mem_man->mutex);

	return ret;
}

void *img_mem_get_kptr(struct mem_ctx *ctx, int32 buff_id)
{
	struct mem_man *mem_man = &mem_man_data;
	struct buffer *buffer;
	void *kptr;

	osa_mutex_lock_nested(mem_man->mutex, OSA_SUBCLASS_IMGMEM);
	buffer = osa_idr_find(ctx->buffers, buff_id);
	if (!buffer) {
		OSA_DEV_ERR(mem_man->dev, "%s: buffer id %d not found\n", __func__,
			buff_id);
		osa_mutex_unlock(mem_man->mutex);
		return NULL;
	}
	kptr = buffer->kptr;
	osa_mutex_unlock(mem_man->mutex);
	return kptr;
}

static void _img_mem_sync_cpu_to_device(struct buffer *buffer)
{
	struct heap *heap = buffer->heap;

	if (heap->ops && heap->ops->sync_cpu_to_dev)
		heap->ops->sync_cpu_to_dev(heap, buffer);

	/* sync to device memory */
	osa_mb();
}

int32 img_mem_sync_cpu_to_device(struct mem_ctx *ctx, int32 buff_id)
{
	struct mem_man *mem_man = &mem_man_data;
	struct buffer *buffer;

	osa_mutex_lock_nested(mem_man->mutex, OSA_SUBCLASS_IMGMEM);
	buffer = osa_idr_find(ctx->buffers, buff_id);
	if (!buffer) {
		OSA_DEV_ERR(mem_man->dev, "%s: buffer id %d not found\n", __func__,
			buff_id);
		osa_mutex_unlock(mem_man->mutex);
		return -OSA_EINVAL;
	}

	_img_mem_sync_cpu_to_device(buffer);

	osa_mutex_unlock(mem_man->mutex);
	return 0;
}

static void _img_mem_sync_device_to_cpu(struct buffer *buffer)
{
	struct heap *heap = buffer->heap;

	if (heap->ops && heap->ops->sync_dev_to_cpu)
		heap->ops->sync_dev_to_cpu(heap, buffer);
}

int32 img_mem_sync_device_to_cpu(struct mem_ctx *ctx, int32 buff_id)
{
	struct mem_man *mem_man = &mem_man_data;
	struct buffer *buffer;

	osa_mutex_lock_nested(mem_man->mutex, OSA_SUBCLASS_IMGMEM);
	buffer = osa_idr_find(ctx->buffers, buff_id);
	if (!buffer) {
		OSA_DEV_ERR(mem_man->dev, "%s: buffer id %d not found\n", __func__,
			buff_id);
		osa_mutex_unlock(mem_man->mutex);
		return -OSA_EINVAL;
	}

	_img_mem_sync_device_to_cpu(buffer);

	osa_mutex_unlock(mem_man->mutex);
	return 0;
}

static struct mmu_page_cfg *mmu_page_alloc(void *arg)
{
	struct mem_man *mem_man = &mem_man_data;
	struct mmu_ctx *mmu_ctx = arg;
	struct mmu_page *page;
	struct buffer *buffer;
	struct heap *heap;
	int32 ret;

	OSA_DEV_DBG(mmu_ctx->device, "%s:%d arg %p\n", __func__, __LINE__, arg);

	OSA_WARN_ON(!osa_mutex_is_locked(mem_man->mutex));

	page = osa_zalloc(sizeof(*page), OSA_GFP_KERNEL);
	if (!page)
		return NULL;

	ret = _img_mem_alloc(mmu_ctx->device, mmu_ctx->mem_ctx,
			     mmu_ctx->heap, OSA_PAGE_SIZE, (enum mem_attr)0, &buffer);
	if (ret) {
		OSA_DEV_ERR(mmu_ctx->device, "%s: img_mem_alloc failed (%d)\n",
			__func__, ret);
		goto free_page;
	}

	ret = _img_mem_map_km(buffer);
	if (ret) {
		OSA_DEV_ERR(mmu_ctx->device, "%s: img_mem_map_km failed (%d)\n",
			__func__, ret);
		goto free_buffer;
	}

	page->addr_shift = mmu_ctx->mmu_config_addr_width - 32;
	page->buffer = buffer;
	page->page_cfg.cpu_virt_addr = (uintptr_t)buffer->kptr;

	heap = buffer->heap;
	if (heap->ops && heap->ops->get_sg_table) {
		void *sgt;

		ret = heap->ops->get_sg_table(heap, buffer, &sgt);
		if (ret) {
			OSA_DEV_ERR(mmu_ctx->device,
				"%s: heap %d buffer %d no sg_table!\n",
				__func__, heap->id, buffer->id);
			ret = -OSA_EINVAL;
			goto free_buffer;
		}
		page->page_cfg.phys_addr = osa_sg_phys(osa_get_sgl(sgt));
	} else {
		OSA_DEV_ERR(mmu_ctx->device, "%s: heap %d buffer %d no get_sg!\n",
			__func__, heap->id, buffer->id);
		ret = -OSA_EINVAL;
		goto free_buffer;
	}

	OSA_DEV_DBG(mmu_ctx->device, "%s:%d virt addr %#lx\n", __func__, __LINE__,
		page->page_cfg.cpu_virt_addr);
	OSA_DEV_DBG(mmu_ctx->device, "%s:%d phys addr %#llx\n", __func__, __LINE__,
		page->page_cfg.phys_addr);
	return &page->page_cfg;

free_buffer:
	_img_mem_free(buffer);
	osa_free(buffer);
free_page:
	osa_free(page);
	return NULL;
}

static void mmu_page_free(struct mmu_page_cfg *arg)
{
	struct mem_man *mem_man = &mem_man_data;
	struct mmu_page *page;

	page = osa_container_of(arg, struct mmu_page, page_cfg);

	OSA_WARN_ON(!osa_mutex_is_locked(mem_man->mutex));

	_img_mem_free(page->buffer);
	osa_free(page->buffer);
	osa_free(page);
}

static void mmu_page_write(struct mmu_page_cfg *page_cfg,
			   uint32 offset, uint64 addr,
			   uint32 flags)
{
	uint32 *mem = (uint32 *)page_cfg->cpu_virt_addr;
	struct mmu_page *mmu_page;
	struct heap *heap;

	mmu_page = osa_container_of(page_cfg, struct mmu_page, page_cfg);
	heap = mmu_page->buffer->heap;

	/* skip translation when flags are zero, assuming address is invalid */
	if (flags && heap->to_dev_addr)
		addr = heap->to_dev_addr(&heap->options, addr);
	addr >>= mmu_page->addr_shift;

	mem[offset] = addr | flags;
}

static void mmu_update_page(struct mmu_page_cfg *arg)
{
	struct mem_man *mem_man = &mem_man_data;
	struct mmu_page *page;

	page = osa_container_of(arg, struct mmu_page, page_cfg);

	OSA_WARN_ON(!osa_mutex_is_locked(mem_man->mutex));

	_img_mem_sync_cpu_to_device(page->buffer);
}

int32 img_mmu_ctx_create(void *device, uint32 mmu_config_addr_width,
		       struct mem_ctx *mem_ctx, int32 heap_id,
		       void (*callback_fn)(enum mmu_callback_type type,
					   int32 buff_id, void *data),
		       void *callback_data, struct mmu_ctx **mmu_ctx)
{
	struct mem_man *mem_man = &mem_man_data;

	static struct mmu_info mmu_functions = {
		.pfn_page_alloc = mmu_page_alloc,
		.pfn_page_free = mmu_page_free,
		.pfn_page_write = mmu_page_write,
		.pfn_page_update = mmu_update_page,
	};
	struct mmu_ctx *ctx;
	int32 ret;

	if (mmu_config_addr_width < 32) {
		OSA_DEV_ERR(device,
			"%s: invalid addr_width (%d) must be >= 32 !\n",
			__func__, mmu_config_addr_width);
		return -OSA_EINVAL;
	}

	ctx = osa_zalloc(sizeof(*ctx), OSA_GFP_KERNEL);
	if (!ctx)
		return -OSA_ENOMEM;

	ctx->device = device;
	ctx->mem_ctx = mem_ctx;
	ctx->mmu_config_addr_width = mmu_config_addr_width;

	osa_mutex_lock_nested(mem_man->mutex, OSA_SUBCLASS_IMGMEM);

	ctx->heap = osa_idr_find(mem_man->heaps, heap_id);
	if (!ctx->heap) {
		OSA_DEV_ERR(device, "%s: invalid heap_id (%d)!\n", __func__,
			heap_id);
		osa_mutex_unlock(mem_man->mutex);
		osa_free(ctx);
		return -OSA_EINVAL;
	}

	mmu_functions.alloc_ctx = ctx;
	ctx->mmu_dir = mmu_create_directory(&mmu_functions);
	if (OSA_IS_ERR(ctx->mmu_dir)) {
		ret = OSA_PTR_ERR(ctx->mmu_dir);
		OSA_DEV_ERR(device, "%s: directory create failed (%d)!\n", __func__,
			ret);
		ctx->mmu_dir = NULL;
		osa_mutex_unlock(mem_man->mutex);
		osa_free(ctx);
		return ret;
	}

	osa_list_add(&ctx->mem_ctx_entry, &mem_ctx->mmu_ctxs);
	INIT_OSA_LIST_HEAD(&ctx->mappings);

	ctx->callback_fn = callback_fn;
	ctx->callback_data = callback_data;

	*mmu_ctx = ctx;

	osa_mutex_unlock(mem_man->mutex);

	return 0;
}

static void _img_mmu_ctx_destroy(struct mmu_ctx *ctx)
{
	struct mem_man *mem_man = &mem_man_data;
	int32 ret;

	while (!osa_list_empty(&ctx->mappings)) {
		struct mmu_ctx_mapping *map;

		map = osa_list_first_entry(&ctx->mappings,
				       struct mmu_ctx_mapping, mmu_ctx_entry);
		OSA_DEV_INFO(ctx->device,
			 "%s: found mapped buffer %d (size %zu)\n",
			 __func__, map->buffer->id, map->buffer->request_size);

		_img_mmu_unmap(map);

		osa_free(map);
	}

	ret = mmu_destroy_directory(ctx->mmu_dir);
	if (ret)
		OSA_DEV_ERR(mem_man->dev, "mmu_destroy_directory failed (%d)!\n",
			ret);
	osa_list_del(&ctx->mem_ctx_entry);
}

void img_mmu_ctx_destroy(struct mmu_ctx *ctx)
{
	struct mem_man *mem_man = &mem_man_data;

	osa_mutex_lock_nested(mem_man->mutex, OSA_SUBCLASS_IMGMEM);
	_img_mmu_ctx_destroy(ctx);
	osa_mutex_unlock(mem_man->mutex);

	osa_free(ctx);
}

int32 img_mmu_map_sg(struct mmu_ctx *mmu_ctx, struct mem_ctx *mem_ctx,
		   int32 buff_id, void *sgt, uint32 virt_addr,
		   uint32 map_flags)
{
	struct mem_man *mem_man = &mem_man_data;
	struct mmu_ctx_mapping *mapping;
	struct mmu_heap_alloc heap_alloc;
	struct buffer *buffer;
	int32 ret = 0;

	OSA_DEV_DBG(mmu_ctx->device, "%s sgt %p virt_addr %#x\n", __func__,
		sgt, virt_addr);

	mapping = osa_zalloc(sizeof(*mapping), OSA_GFP_KERNEL);
	if (!mapping)
		return -OSA_ENOMEM;

	osa_mutex_lock_nested(mem_man->mutex, OSA_SUBCLASS_IMGMEM);
	buffer = osa_idr_find(mem_ctx->buffers, buff_id);
	if (!buffer) {
		OSA_DEV_ERR(mmu_ctx->device, "%s: buffer id %d not found\n",
			__func__, buff_id);
		ret = -OSA_EINVAL;
		goto error;
	}
	OSA_DEV_DBG(mmu_ctx->device, "%s buffer %d 0x%p size %zu virt_addr %#x\n",
		__func__, buff_id, buffer, buffer->request_size, virt_addr);

	heap_alloc.virt_addr = virt_addr;
	heap_alloc.alloc_size = buffer->actual_size;

	mapping->mmu_ctx = mmu_ctx;
	mapping->buffer = buffer;
	mapping->virt_addr = virt_addr;

	if (sgt) {
		mapping->map = mmu_directory_map_sg(mmu_ctx->mmu_dir, osa_get_sgl(sgt),
						    &heap_alloc, map_flags);
		if (OSA_IS_ERR(mapping->map)) {
			ret = OSA_PTR_ERR(mapping->map);
			mapping->map = NULL;
		}
	} else {
		OSA_DEV_ERR(mmu_ctx->device, "%s: buffer %d no get_sg!\n",
			__func__, buffer->id);
		ret = -OSA_EINVAL;
		goto error;
	}
	if (ret) {
		OSA_DEV_ERR(mmu_ctx->device, "mmu_directory_map_sg failed (%d)!\n",
			ret);
		goto error;
	}

	osa_list_add(&mapping->mmu_ctx_entry, &mmu_ctx->mappings);
	osa_list_add(&mapping->buffer_entry, &mapping->buffer->mappings);

	if (mmu_ctx->callback_fn)
		mmu_ctx->callback_fn(MMU_CALLBACK_MAP, buffer->id,
				     mmu_ctx->callback_data);

	osa_mutex_unlock(mem_man->mutex);
	return 0;

error:
	osa_mutex_unlock(mem_man->mutex);
	osa_free(mapping);
	return ret;
}

int32 img_mmu_map(struct mmu_ctx *mmu_ctx, struct mem_ctx *mem_ctx,
		int32 buff_id, uint32 virt_addr, uint32 map_flags)
{
	struct mem_man *mem_man = &mem_man_data;
	struct mmu_ctx_mapping *mapping;
	struct mmu_heap_alloc heap_alloc;
	struct buffer *buffer;
	struct heap *heap;
	int32 ret;

	OSA_DEV_DBG(mmu_ctx->device, "%s buffer %d virt_addr %#x\n", __func__,
		buff_id, virt_addr);

	mapping = osa_zalloc(sizeof(*mapping), OSA_GFP_KERNEL);
	if (!mapping)
		return -OSA_ENOMEM;

	osa_mutex_lock_nested(mem_man->mutex, OSA_SUBCLASS_IMGMEM);
	buffer = osa_idr_find(mem_ctx->buffers, buff_id);
	if (!buffer) {
		OSA_DEV_ERR(mmu_ctx->device, "%s: buffer id %d not found\n",
			__func__, buff_id);
		ret = -OSA_EINVAL;
		goto error;
	}
	OSA_DEV_DBG(mmu_ctx->device, "%s buffer %d 0x%p size %zu virt_addr %#x\n",
		__func__, buff_id, buffer, buffer->request_size, virt_addr);

	heap_alloc.virt_addr = virt_addr;
	heap_alloc.alloc_size = buffer->actual_size;

	mapping->mmu_ctx = mmu_ctx;
	mapping->buffer = buffer;
	mapping->virt_addr = virt_addr;

	heap = buffer->heap;
	if (heap->ops && heap->ops->get_sg_table) {
		void *sgt;

		ret = heap->ops->get_sg_table(heap, buffer, &sgt);
		if (ret) {
			OSA_DEV_ERR(mmu_ctx->device,
				"%s: heap %d buffer %d no sg_table!\n",
				__func__, heap->id, buffer->id);
			goto error;
		}

		mapping->map = mmu_directory_map_sg(mmu_ctx->mmu_dir, osa_get_sgl(sgt),
						    &heap_alloc, map_flags);
		if (OSA_IS_ERR(mapping->map)) {
			ret = OSA_PTR_ERR(mapping->map);
			mapping->map = NULL;
		}
	} else {
		OSA_DEV_ERR(mmu_ctx->device, "%s: heap %d buffer %d no get_sg!\n",
			__func__, heap->id, buffer->id);
		ret = -OSA_EINVAL;
		goto error;
	}
	if (ret) {
		OSA_DEV_ERR(mmu_ctx->device, "mmu_directory_map failed (%d)!\n",
			ret);
		goto error;
	}

	osa_list_add(&mapping->mmu_ctx_entry, &mmu_ctx->mappings);
	osa_list_add(&mapping->buffer_entry, &mapping->buffer->mappings);

	if (mmu_ctx->callback_fn)
		mmu_ctx->callback_fn(MMU_CALLBACK_MAP, buffer->id,
				     mmu_ctx->callback_data);

	osa_mutex_unlock(mem_man->mutex);
	return 0;

error:
	osa_mutex_unlock(mem_man->mutex);
	osa_free(mapping);
	return ret;
}

static void _img_mmu_unmap(struct mmu_ctx_mapping *mapping)
{
	struct mmu_ctx *ctx = mapping->mmu_ctx;
	int32 res;

	OSA_DEV_DBG(ctx->device, "%s:%d mapping %p buffer %d\n", __func__,
		__LINE__, mapping, mapping->buffer->id);

	res = mmu_directory_unmap(mapping->map);
	if (res)
		OSA_DEV_WARN(ctx->device, "mmu_directory_unmap failed (%d)!\n",
			 res);

	osa_list_del(&mapping->mmu_ctx_entry);
	osa_list_del(&mapping->buffer_entry);

	if (ctx->callback_fn)
		ctx->callback_fn(MMU_CALLBACK_UNMAP, mapping->buffer->id,
				 ctx->callback_data);
}

int32 img_mmu_unmap(struct mmu_ctx *mmu_ctx, struct mem_ctx *mem_ctx,
		  int32 buff_id)
{
	struct mem_man *mem_man = &mem_man_data;
	struct mmu_ctx_mapping *mapping;
	struct clist_head *lst;

	OSA_DEV_DBG(mmu_ctx->device, "%s:%d buffer %d\n", __func__, __LINE__,
		buff_id);

	osa_mutex_lock_nested(mem_man->mutex, OSA_SUBCLASS_IMGMEM);

	mapping = NULL;
	osa_list_for_each(lst, &mmu_ctx->mappings) {
		struct mmu_ctx_mapping *m;

		m = osa_list_entry(lst, struct mmu_ctx_mapping, mmu_ctx_entry);
		if (m->buffer->id == buff_id) {
			mapping = m;
			break;
		}
	}

	if (!mapping) {
		OSA_DEV_ERR(mmu_ctx->device, "%s: buffer id %d not found\n",
			__func__, buff_id);
		osa_mutex_unlock(mem_man->mutex);
		return -OSA_EINVAL;
	}

	_img_mmu_unmap(mapping);

	osa_mutex_unlock(mem_man->mutex);
	osa_free(mapping);
	return 0;
}

int32 img_mmu_get_ptd(const struct mmu_ctx *ctx, uint32 *ptd)
{
	struct mem_man *mem_man = &mem_man_data;
	struct mmu_page_cfg *page_cfg;
	uint64 addr;

	osa_mutex_lock_nested(mem_man->mutex, OSA_SUBCLASS_IMGMEM);

	page_cfg = mmu_directory_get_page(ctx->mmu_dir);
	if (!page_cfg) {
		osa_mutex_unlock(mem_man->mutex);
		return -OSA_EINVAL;
	}

	addr = page_cfg->phys_addr;
	if (ctx->heap->to_dev_addr)
		addr = ctx->heap->to_dev_addr(&ctx->heap->options, addr);

	osa_mutex_unlock(mem_man->mutex);

	*ptd = (uint32)(addr >>= VXD_MMU_SHIFT);

	OSA_DEV_DBG(ctx->device, "%s: addr %#llx ptd %#x\n", __func__,
		page_cfg->phys_addr, *ptd);
	return 0;
}


int32 img_mmu_get_pagetable_entry(const struct mmu_ctx *ctx, uintptr_t dev_virt_addr)
{
	if (!ctx)
		return 0xFFFFFF;

	return mmu_directory_get_pagetable_entry(ctx->mmu_dir, dev_virt_addr);
}

/*
 * Initialisation
 */
int32 img_mem_init(void *dev)
{
	struct mem_man *mem_man = &mem_man_data;

	mem_man->dev = dev;
	osa_idr_init(&mem_man->heaps);
	if(NULL == mem_man->heaps)
	{
		return OSA_ENOMEM;
	}
	INIT_OSA_LIST_HEAD(&mem_man->mem_ctxs);
	osa_mutex_create(&mem_man->mutex);
	if(NULL == mem_man->mutex)
	{
		return OSA_ENOMEM;
	}

	return 0;
}

void img_mem_exit(void)
{
	struct mem_man *mem_man = &mem_man_data;
	struct heap *heap;
	int32 heap_id;

	/* keeps mutex checks (OSA_WARN_ON) happy, this will never actually wait */
	osa_mutex_lock_nested(mem_man->mutex, OSA_SUBCLASS_IMGMEM);

	while (!osa_list_empty(&mem_man->mem_ctxs)) {
		struct mem_ctx *mc;

		mc = osa_list_first_entry(&mem_man->mem_ctxs,
				      struct mem_ctx, mem_man_entry);
		OSA_DEV_WARN(mem_man->dev, "%s derelict memory context %p!\n",
			 __func__, mc);
		_img_mem_destroy_ctx(mc);
		osa_free(mc);
	}

	heap_id = MIN_HEAP;
	heap = osa_idr_get_next(mem_man->heaps, &heap_id);
	while (heap) {
		OSA_DEV_WARN(mem_man->dev, "%s derelict heap %d!\n", __func__,
			 heap_id);
		_img_mem_del_heap(heap);
		osa_free(heap);
		heap_id = MIN_HEAP;
		heap = osa_idr_get_next(mem_man->heaps, &heap_id);
	}
	osa_idr_destroy(mem_man->heaps);

	osa_mutex_unlock(mem_man->mutex);

	osa_mutex_destroy(&mem_man->mutex);
}
