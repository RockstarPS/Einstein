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
 * VDEC MMU Functions
 */

#include "osal/inc/osa_mem.h"
#include "img_dec_common.h"
#include "lst.h"
#include "talmmu_api.h"
#include "vdec_defs.h"
#include "vdec_mmu_wrapper.h"
#include "vxd_dec.h"

#define GUARD_BAND  0x1000

struct mmuheap {
	char *name;
	enum mmu_eheap_id heap_id;
	enum talmmu_heap_type heap_type;
	uint32 start_offset;
	uint32 size;
	char *mem_space;
	osa_bool use_guard_band;
	osa_bool image_buffers;
};

static const struct mmuheap mmu_heaps[MMU_HEAP_MAX] = {
	{ "Image untiled", MMU_HEAP_IMAGE_BUFFERS_UNTILED,
		TALMMU_HEAP_PERCONTEXT, PVDEC_HEAP_UNTILED_START,
		PVDEC_HEAP_UNTILED_SIZE, "MEMBE", 1, 1 },

	{ "Bitstream", MMU_HEAP_BITSTREAM_BUFFERS,
		TALMMU_HEAP_PERCONTEXT, PVDEC_HEAP_BITSTREAM_START,
		PVDEC_HEAP_BITSTREAM_SIZE, "MEMDMAC_02", 1, 0 },

	{ "Stream", MMU_HEAP_STREAM_BUFFERS,
		TALMMU_HEAP_PERCONTEXT, PVDEC_HEAP_STREAM_START,
		PVDEC_HEAP_STREAM_SIZE, "MEM", 1, 0 },
};

/*
 * @Heap ID
 * @Heap type
 * @Heap flags
 * @Memory space name
 * @Start address (virtual)
 * @Size of heap, in bytes
 */
static struct talmmu_heap_info heap_info = {
	MMU_HEAP_IMAGE_BUFFERS_UNTILED,
	TALMMU_HEAP_PERCONTEXT,
	TALMMU_HEAPFLAGS_NONE,
	"MEMBE",
	0,
	0,
};

/*
 * This structure contains the device context.
 * @brief  VDECDD MMU Device Context
 * @devmem_template_hndl: Handle for MMU template.
 * @devmem_ctx_hndl: Handle for MMU context.
 * @str_list: List of streams.
 */
struct mmu_dev_context {
	void *devmem_template_hndl;
	void *devmem_ctx_hndl;
	struct lst_t str_list;
	uint32 ctx_id;
	uint32 next_ctx_id;
};

/*
 * This structure contains the stream context.
 * @brief  VDECDD MMU Stream Context
 * @LST_LINK: List link (allows the structure to be part of a MeOS list).
 * @devmem_ctx_hndl: Handle for MMU context.
 * @dev_ctx: Pointer to device context.
 * @ctx_id: MMU context Id.
 * km_str_id: Stream ID used in communication with new KM interface
 */
struct mmu_str_context {
	void **link;
	void *devmem_ctx_hndl;
	struct mmu_dev_context *dev_ctx;
	uint32 ctx_id;
	void *ptd_memspace_hndl;
	uint32 int_reg_num;
	uint32 km_str_id;
	struct vxd_dec_ctx *vxd_dec_context;
};

static uint32 set_attributes(enum sys_emem_attrib mem_attrib)
{
	uint32 attrib = 0;

	if (mem_attrib & SYS_MEMATTRIB_CACHED)
		attrib |= MEM_ATTR_CACHED;

	if (mem_attrib & SYS_MEMATTRIB_UNCACHED)
		attrib |= MEM_ATTR_UNCACHED;

	if (mem_attrib & SYS_MEMATTRIB_WRITECOMBINE)
		attrib |= MEM_ATTR_WRITECOMBINE;

	if (mem_attrib & SYS_MEMATTRIB_SECURE)
		attrib |= MEM_ATTR_SECURE;

	return attrib;
}

/*
 * @Function	mmu_dev_mem_context_create
 */
static int32 mmu_devmem_context_create(struct mmu_dev_context *dev_ctx,
				     void **mmu_ctx_hndl)
{
	int32 result;
	void *devmem_heap_hndl;
	union talmmu_heap_options heap_opt1;
	uint32 i;
	osa_bool use_guardband;
	enum talmmu_heap_option_id heap_option_id;

	dev_ctx->next_ctx_id++;

	/* Create a context from the template */
	result = talmmu_devmem_ctx_create(dev_ctx->devmem_template_hndl,
					  dev_ctx->next_ctx_id,
					  mmu_ctx_hndl);
	if (result != IMG_SUCCESS)
		return result;

	/* Apply options to heaps. */
	heap_opt1.guardband_opt.guardband = GUARD_BAND;

	for (i = 0; i < MMU_HEAP_MAX; i++) {
		result = talmmu_get_heap_handle(mmu_heaps[i].heap_id,
						*mmu_ctx_hndl,
						&devmem_heap_hndl);
		if (result != IMG_SUCCESS)
			return result;

		use_guardband = mmu_heaps[i].use_guard_band;
		heap_option_id = TALMMU_HEAP_OPT_ADD_GUARD_BAND;
		if (use_guardband) {
			talmmu_devmem_heap_options(devmem_heap_hndl,
							    heap_option_id,
							    heap_opt1);
		}
	}

	return IMG_SUCCESS;
}

/*
 * @Function	mmu_device_create
 */
int32 mmu_device_create(enum mmu_etype mmu_type_arg,
		      uint32 ptd_alignment,
		      void **mmudev_handle)
{
	int32 result = IMG_SUCCESS;
	enum talmmu_mmu_type talmmu_type =
		TALMMU_MMUTYPE_4K_PAGES_32BIT_ADDR;
	uint32 i;
	struct mmu_dev_context *dev_ctx;
	struct talmmu_devmem_info dev_mem_info;

	/* Set the TAL MMU type. */
	switch (mmu_type_arg) {
	case MMU_TYPE_32BIT:
		talmmu_type = TALMMU_MMUTYPE_4K_PAGES_32BIT_ADDR;
		break;

	case MMU_TYPE_36BIT:
		talmmu_type = TALMMU_MMUTYPE_4K_PAGES_36BIT_ADDR;
		break;

	case MMU_TYPE_40BIT:
		talmmu_type = TALMMU_MMUTYPE_4K_PAGES_40BIT_ADDR;
		break;

	default:
		return IMG_ERROR_INVALID_PARAMETERS;
	}

	/* Allocate a device context structure */
	dev_ctx = osa_zalloc(sizeof(*dev_ctx), OSA_GFP_KERNEL);
	if (!dev_ctx)
		return IMG_ERROR_OUT_OF_MEMORY;

	/* Initialise stream list. */
	lst_init(&dev_ctx->str_list);

	/* Initialise TALMMU. */
	result = talmmu_init();
	if (result != IMG_SUCCESS)
		goto error_tal_init;

	dev_mem_info.device_id = 0;
	dev_mem_info.mmu_type = talmmu_type;
	dev_mem_info.dev_flags = TALMMU_DEVFLAGS_NONE;
	dev_mem_info.pagedir_memspace_name = "MEM";
	dev_mem_info.pagetable_memspace_name = NULL;
	dev_mem_info.page_size = DEV_MMU_PAGE_SIZE;
	dev_mem_info.ptd_alignment = ptd_alignment;

	result = talmmu_devmem_template_create(&dev_mem_info,
					       &dev_ctx->devmem_template_hndl);
	if (result != IMG_SUCCESS)
		goto error_tal_template;

	/* Add heaps to template */
	for (i = 0; i < MMU_HEAP_MAX; i++) {
		heap_info.heap_id = mmu_heaps[i].heap_id;
		heap_info.heap_type = mmu_heaps[i].heap_type;
		heap_info.memspace_name = mmu_heaps[i].name;
		heap_info.size = mmu_heaps[i].size;
		heap_info.basedev_virtaddr = mmu_heaps[i].start_offset;

		result = talmmu_devmem_heap_add(dev_ctx->devmem_template_hndl,
						&heap_info);
		if (result != IMG_SUCCESS)
			goto error_tal_heap;
	}

	/* Create the device context. */
	result = mmu_devmem_context_create(dev_ctx, &dev_ctx->devmem_ctx_hndl);
	if (result != IMG_SUCCESS)
		goto error_mmu_context;

	dev_ctx->ctx_id = dev_ctx->next_ctx_id;

	/* Return the device context. */
	*mmudev_handle = dev_ctx;

	return IMG_SUCCESS;

	/* Roll back in case of errors. */
error_mmu_context:
error_tal_heap:
	talmmu_devmem_template_destroy(dev_ctx->devmem_template_hndl);
error_tal_template:
	talmmu_deinit();
error_tal_init:
	osa_free(dev_ctx);
	return result;
}

/*
 * @Function	mmu_device_destroy
 */
int32 mmu_device_destroy(void *mmudev_handle)
{
	struct mmu_dev_context *dev_ctx = mmudev_handle;
	uint32 result;
	struct mmu_str_context *str_ctx;

	/* Validate inputs. */
	if (!mmudev_handle)
		return IMG_ERROR_INVALID_PARAMETERS;

	/* Destroy all streams associated with the device. */
	str_ctx = lst_first(&dev_ctx->str_list);
	while (str_ctx) {
		result = mmu_stream_destroy(str_ctx);
		if (result != IMG_SUCCESS)
			return result;
		/* See if there are more streams. */
		str_ctx = lst_first(&dev_ctx->str_list);
	}

	/* Destroy the device context */
	result = talmmu_devmem_ctx_destroy(dev_ctx->devmem_ctx_hndl);
	if (result != IMG_SUCCESS)
		return result;

	/* Destroy the template. */
	result = talmmu_devmem_template_destroy(dev_ctx->devmem_template_hndl);
	if (result != IMG_SUCCESS)
		return result;

	talmmu_deinit();

	osa_free(dev_ctx);
	return IMG_SUCCESS;
}

/*
 * @Function	mmu_stream_create
 * @Description
 * This function is used to create and initialise the MMU stream context.
 * @Input	mmudev_handle : The MMU device handle.
 * @Input	km_str_id : Stream Id used in communication with KM driver.
 * @Output	mmu_str_hndl : A pointer used to return the MMU stream
 *		handle.
 * @Return	IMG_SUCCESS or an error code.
 */
int32 mmu_stream_create(void *mmudev_handle,
		      uint32 km_str_id,
		      void *vxd_dec_ctx_arg,
		      void **mmu_str_hndl)
{
	struct mmu_dev_context *dev_ctx = mmudev_handle;
	struct mmu_str_context *str_ctx;
	int32 res;

	/* Validate inputs. */
	if (!mmudev_handle)
		return IMG_ERROR_INVALID_PARAMETERS;

	/* Allocate a stream context structure */
	str_ctx = osa_zalloc(sizeof(*str_ctx), OSA_GFP_KERNEL);
	if (!str_ctx)
		return IMG_ERROR_OUT_OF_MEMORY;

	str_ctx->km_str_id = km_str_id;
	str_ctx->dev_ctx = dev_ctx;
	str_ctx->int_reg_num = 32;
	str_ctx->vxd_dec_context = (struct vxd_dec_ctx *)vxd_dec_ctx_arg;

	/* Create a stream context. */
	res = mmu_devmem_context_create(dev_ctx,
					&str_ctx->devmem_ctx_hndl);
	if (res != IMG_SUCCESS) {
		osa_free(str_ctx);
		return res;
	}

	str_ctx->ctx_id = dev_ctx->next_ctx_id;

	/* Add stream to list. */
	lst_add(&dev_ctx->str_list, str_ctx);

	*mmu_str_hndl = str_ctx;

	return IMG_SUCCESS;
}

/*
 * @Function	mmu_stream_destroy
 * @Description
 * This function is used to create and initialise the MMU stream context.
 * NOTE: Destroy automatically frees and memory allocated using
 *	mmu_stream_malloc().
 * @Input	mmu_str_hndl : The MMU stream handle.
 * @Return	IMG_SUCCESS or an error code.
 */
int32 mmu_stream_destroy(void *mmu_str_hndl)
{
	struct mmu_str_context *str_ctx = mmu_str_hndl;
	int32 res;

	/* Validate inputs. */
	if (!mmu_str_hndl)
		return IMG_ERROR_INVALID_PARAMETERS;

	/* remove stream to list. */
	lst_remove(&str_ctx->dev_ctx->str_list, str_ctx);

	/* Destroy the device context */
	res = talmmu_devmem_ctx_destroy(str_ctx->devmem_ctx_hndl);
	if (res != IMG_SUCCESS)
		return res;

	osa_free(str_ctx);

	return IMG_SUCCESS;
}

/*
 * @Function	mmu_malloc
 */
static int32 mmu_alloc(void *devmem_ctx_hndl,
		     struct vxd_dec_ctx *vxd_dec_ctx_arg,
		     enum mmu_eheap_id heap_id,
		     uint32 mem_heap_id,
		     enum sys_emem_attrib mem_attrib,
		     uint32 size,
		     uint32 alignment,
		     struct vidio_ddbufinfo *ddbuf_info)
{
	int32 result;
	void *devmem_heap_hndl;
	struct vxd_free_data free_data;
	struct vxd_dec_ctx *ctx;
	struct vxd_dev *vxd;
	struct vxd_alloc_data alloc_data;
	uint32 flags;

	if (!devmem_ctx_hndl)
		return IMG_ERROR_INVALID_PARAMETERS;

	/* Set buffer size. */
	ddbuf_info->buf_size = size;

	/* Round size up to next multiple of physical pages */
	if ((size % HOST_MMU_PAGE_SIZE) != 0)
		size = ((size / HOST_MMU_PAGE_SIZE) + 1) * HOST_MMU_PAGE_SIZE;

	/* Allocate memory */
	ctx = vxd_dec_ctx_arg;
	vxd = ctx->dev;

	alloc_data.heap_id = mem_heap_id;
	alloc_data.size = ddbuf_info->buf_size;

	alloc_data.attributes = set_attributes(mem_attrib);

	result = img_mem_alloc(vxd->dev,
			       ctx->mem_ctx,
			       alloc_data.heap_id,
			       alloc_data.size,
			       (enum mem_attr)alloc_data.attributes,
			       (int32 *)&ddbuf_info->buff_id);
	if (result != IMG_SUCCESS)
		goto error_alloc;

	ddbuf_info->is_internal = 1;

	if (mem_attrib & SYS_MEMATTRIB_SECURE) {
		ddbuf_info->cpu_virt = NULL;
	} else {
		/* Map the buffer to CPU */
		result = img_mem_map_km(ctx->mem_ctx, ddbuf_info->buff_id);
		if (result) {
			OSA_DEV_ERR(vxd->dev, "%s: failed to map buf to cpu!(%d)\n",
				__func__, result);
			goto error_get_heap_handle;
		}
		ddbuf_info->cpu_virt = img_mem_get_kptr(ctx->mem_ctx,
							ddbuf_info->buff_id);
	}

	/* Get heap handle */
	result = talmmu_get_heap_handle(heap_id,
					devmem_ctx_hndl,
					&devmem_heap_hndl);
	if (result != IMG_SUCCESS)
		goto error_get_heap_handle;

	/* Allocate device "virtual" memory. */
	result = talmmu_devmem_addr_alloc(devmem_ctx_hndl,
					  devmem_heap_hndl,
					  size,
					  alignment,
					  &ddbuf_info->hndl_memory);
	if (result != IMG_SUCCESS)
		goto error_mem_map_ext_mem;

	/* Get the device virtual address. */
	result = talmmu_get_dev_virt_addr(ddbuf_info->hndl_memory,
					  &ddbuf_info->dev_virt);
	if (result != IMG_SUCCESS)
		goto error_get_dev_virt_addr;

	flags = VXD_MAP_FLAG_NONE;

	if (mem_attrib & SYS_MEMATTRIB_CORE_READ_ONLY)
		flags |= VXD_MAP_FLAG_READ_ONLY;

	if (mem_attrib & SYS_MEMATTRIB_CORE_WRITE_ONLY)
		flags |= VXD_MAP_FLAG_WRITE_ONLY;

	result = vxd_map_buffer(vxd,
				ctx,
				ddbuf_info->kmstr_id,
				ddbuf_info->buff_id,
				ddbuf_info->dev_virt,
				flags);

	if (result != IMG_SUCCESS)
		goto error_map_dev;

	return IMG_SUCCESS;

error_map_dev:
error_get_dev_virt_addr:
	talmmu_devmem_addr_free(ddbuf_info->hndl_memory);
	ddbuf_info->hndl_memory = NULL;
error_mem_map_ext_mem:
error_get_heap_handle:
	free_data.buf_id = ddbuf_info->buff_id;
	img_mem_free(ctx->mem_ctx, free_data.buf_id);
error_alloc:
	return result;
}

/*
 * @Function	mmu_stream_malloc
 */
int32 mmu_stream_alloc(void *mmu_str_hndl,
		     enum mmu_eheap_id heap_id,
		     uint32 mem_heap_id,
		     enum sys_emem_attrib mem_attrib,
		     uint32 size,
		     uint32 alignment,
		     struct vidio_ddbufinfo *ddbuf_info)
{
	struct mmu_str_context *str_ctx =
		(struct mmu_str_context *)mmu_str_hndl;
	int32 result;

	/* Validate inputs. */
	if (!mmu_str_hndl)
		return IMG_ERROR_INVALID_PARAMETERS;

	/* Check if device level heap. */
	switch (heap_id) {
	case MMU_HEAP_IMAGE_BUFFERS_UNTILED:
	case MMU_HEAP_BITSTREAM_BUFFERS:
	case MMU_HEAP_STREAM_BUFFERS:
		break;

	default:
		return IMG_ERROR_INVALID_PARAMETERS;
	}

	ddbuf_info->kmstr_id = str_ctx->km_str_id;

	/* Allocate device memory. */
	result = mmu_alloc(str_ctx->devmem_ctx_hndl,
			   str_ctx->vxd_dec_context,
			   heap_id,
			   mem_heap_id,
			   mem_attrib,
			   size,
			   alignment,
			   ddbuf_info);
	if (result != IMG_SUCCESS)
		return result;

	return IMG_SUCCESS;
}

/*
 * @Function	mmu_stream_map_ext_sg
 */
int32 mmu_stream_map_ext_sg(void *mmu_str_hndl,
			  enum mmu_eheap_id heap_id,
			  void *sgt,
			  uint32 size,
			  uint32 alignment,
			  enum sys_emem_attrib mem_attrib,
			  void *cpu_linear_addr,
			  struct vidio_ddbufinfo *ddbuf_info,
			  uint32 *buff_id)
{
	struct mmu_str_context *str_ctx =
		(struct mmu_str_context *)mmu_str_hndl;
	int32 result;
	void *devmem_heap_hndl;
	uint32 flags;

	struct vxd_dec_ctx *ctx = str_ctx->vxd_dec_context;
	struct vxd_dev *vxd = ctx->dev;

	/* Validate inputs. */
	if (!mmu_str_hndl)
		return IMG_ERROR_INVALID_PARAMETERS;

	/* Check if device level heap. */
	switch (heap_id) {
	case MMU_HEAP_IMAGE_BUFFERS_UNTILED:
	case MMU_HEAP_BITSTREAM_BUFFERS:
	case MMU_HEAP_STREAM_BUFFERS:
		break;

	default:
		return IMG_ERROR_INVALID_PARAMETERS;
	}

	if (!str_ctx->devmem_ctx_hndl)
		return IMG_ERROR_INVALID_PARAMETERS;

	/* Set buffer size. */
	ddbuf_info->buf_size = size;

	/* Round size up to next multiple of physical pages */
	if ((size % HOST_MMU_PAGE_SIZE) != 0)
		size = ((size / HOST_MMU_PAGE_SIZE) + 1) * HOST_MMU_PAGE_SIZE;

	result = img_mem_import(vxd->dev,
				ctx->mem_ctx,
				ddbuf_info->buf_size,
				(enum mem_attr)set_attributes(mem_attrib),
				(int32 *)buff_id);
	if (result != IMG_SUCCESS)
		return result;

	if (mem_attrib & SYS_MEMATTRIB_SECURE)
		ddbuf_info->cpu_virt = NULL;

	ddbuf_info->buff_id = *buff_id;
	ddbuf_info->is_internal = 0;

	ddbuf_info->kmstr_id = str_ctx->km_str_id;

	/* Set buffer size. */
	ddbuf_info->buf_size = size;

	/* Ensure the address of the buffer is at least page aligned. */
	ddbuf_info->cpu_virt = cpu_linear_addr;

	/* Get heap handle */
	result = talmmu_get_heap_handle(heap_id,
					str_ctx->devmem_ctx_hndl,
					&devmem_heap_hndl);
	if (result != IMG_SUCCESS)
		return result;

	/* Allocate device "virtual" memory. */
	result = talmmu_devmem_addr_alloc(str_ctx->devmem_ctx_hndl,
					  devmem_heap_hndl,
					  size,
					  alignment,
					  &ddbuf_info->hndl_memory);
	if (result != IMG_SUCCESS)
		return result;

	/* Get the device virtual address. */
	result = talmmu_get_dev_virt_addr(ddbuf_info->hndl_memory,
					  &ddbuf_info->dev_virt);
	if (result != IMG_SUCCESS)
		goto error_get_dev_virt_addr;

	/* Map memory to the device */
	flags = VXD_MAP_FLAG_NONE;

	if (mem_attrib & SYS_MEMATTRIB_CORE_READ_ONLY)
		flags |= VXD_MAP_FLAG_READ_ONLY;

	if (mem_attrib & SYS_MEMATTRIB_CORE_WRITE_ONLY)
		flags |= VXD_MAP_FLAG_WRITE_ONLY;

	result = vxd_map_buffer_sg(vxd, ctx,
				   ddbuf_info->kmstr_id,
				   ddbuf_info->buff_id,
				   sgt,
				   ddbuf_info->dev_virt,
				   flags);

	if (result != IMG_SUCCESS)
		goto error_map_dev;

	return IMG_SUCCESS;

error_map_dev:
error_get_dev_virt_addr:
	talmmu_devmem_addr_free(ddbuf_info->hndl_memory);
	ddbuf_info->hndl_memory = NULL;
	return result;
}

/*
 * @Function	mmu_stream_map_ext
 */
int32 mmu_stream_map_ext(void *mmu_str_hndl,
		       enum mmu_eheap_id heap_id,
		       uint32 buff_id,
		       uint32 size,
		       uint32 alignment,
		       enum sys_emem_attrib mem_attrib,
		       void *cpu_linear_addr,
		       struct vidio_ddbufinfo *ddbuf_info)
{
	struct mmu_str_context *str_ctx =
		(struct mmu_str_context *)mmu_str_hndl;
	int32 result;
	void *devmem_heap_hndl;
	struct vxd_dec_ctx *ctx;
	struct vxd_dev *vxd;
	uint32 flags;

	/* Validate inputs. */
	if (!mmu_str_hndl)
		return IMG_ERROR_INVALID_PARAMETERS;

	/* Check if device level heap. */
	switch (heap_id) {
	case MMU_HEAP_IMAGE_BUFFERS_UNTILED:
	case MMU_HEAP_BITSTREAM_BUFFERS:
	case MMU_HEAP_STREAM_BUFFERS:
		break;

	default:
		return IMG_ERROR_INVALID_PARAMETERS;
	}

	/* Round size up to next multiple of physical pages */
	if ((size % HOST_MMU_PAGE_SIZE) != 0)
		size = ((size / HOST_MMU_PAGE_SIZE) + 1) * HOST_MMU_PAGE_SIZE;

	ddbuf_info->buff_id = buff_id;
	ddbuf_info->is_internal = 0;

	ddbuf_info->kmstr_id = str_ctx->km_str_id;

	/* Set buffer size. */
	ddbuf_info->buf_size = size;

	/* Ensure the address of the buffer is at least page aligned. */
	ddbuf_info->cpu_virt = cpu_linear_addr;

	/* Get heap handle */
	result = talmmu_get_heap_handle(heap_id,
					str_ctx->devmem_ctx_hndl,
					&devmem_heap_hndl);
	if (result != IMG_SUCCESS)
		return result;

	/* Allocate device "virtual" memory. */
	result = talmmu_devmem_addr_alloc(str_ctx->devmem_ctx_hndl,
					  devmem_heap_hndl,
					  size,
					  alignment,
					  &ddbuf_info->hndl_memory);
	if (result != IMG_SUCCESS)
		return result;

	/* Get the device virtual address. */
	result = talmmu_get_dev_virt_addr(ddbuf_info->hndl_memory,
					  &ddbuf_info->dev_virt);
	if (result != IMG_SUCCESS)
		return result;

	/*
	 * Map device memory (allocated from outside VDEC)
	 * into the stream PTD.
	 */
	ctx = str_ctx->vxd_dec_context;
	vxd = ctx->dev;

	flags = VXD_MAP_FLAG_NONE;

	if (mem_attrib & SYS_MEMATTRIB_CORE_READ_ONLY)
		flags |= VXD_MAP_FLAG_READ_ONLY;

	if (mem_attrib & SYS_MEMATTRIB_CORE_WRITE_ONLY)
		flags |= VXD_MAP_FLAG_WRITE_ONLY;

	result = vxd_map_buffer(vxd,
				ctx,
				ddbuf_info->kmstr_id,
				ddbuf_info->buff_id,
				ddbuf_info->dev_virt,
				flags);
	if (result != IMG_SUCCESS)
		return result;

	return IMG_SUCCESS;
}

/*
 * @Function	mmu_free_mem
 */
int32 mmu_free_mem(void *mmustr_hndl,
		 struct vidio_ddbufinfo *ddbuf_info)
{
	int32 tmp_result;
	int32 result = IMG_SUCCESS;
	struct vxd_dec_ctx *ctx;
	struct vxd_dev *vxd;

	struct mmu_str_context *str_ctx =
		(struct mmu_str_context *)mmustr_hndl;

	/* Validate inputs. */
	if (!ddbuf_info)
		return IMG_ERROR_INVALID_PARAMETERS;

	if (!str_ctx)
		return IMG_ERROR_INVALID_PARAMETERS;

	/* Unmap the memory mapped to the device */
	ctx = str_ctx->vxd_dec_context;
	vxd = ctx->dev;

	tmp_result = vxd_unmap_buffer(vxd,
				      ctx,
				      ddbuf_info->kmstr_id,
				      ddbuf_info->buff_id);
	if (tmp_result != IMG_SUCCESS)
		result = tmp_result;

	/*
	 * Unmapping the memory mapped to the device - done
	 * Free the memory.
	 */
	tmp_result = talmmu_devmem_addr_free(ddbuf_info->hndl_memory);
	if (tmp_result != IMG_SUCCESS)
		result = tmp_result;

	if (ddbuf_info->is_internal) {
		struct vxd_free_data free_data = { ddbuf_info->buff_id };

		img_mem_free(ctx->mem_ctx, free_data.buf_id);
	}

	return result;
}

/*
 * @Function	mmu_free_mem
 */
int32 mmu_free_mem_sg(void *mmustr_hndl,
		    struct vidio_ddbufinfo *ddbuf_info)
{
	int32 tmp_result;
	int32 result = IMG_SUCCESS;
	struct vxd_dec_ctx *ctx;
	struct vxd_dev *vxd;
	struct vxd_free_data free_data;

	struct mmu_str_context *str_ctx =
		(struct mmu_str_context *)mmustr_hndl;

	/* Validate inputs. */
	if (!ddbuf_info)
		return IMG_ERROR_INVALID_PARAMETERS;

	if (!str_ctx)
		return IMG_ERROR_INVALID_PARAMETERS;

	free_data.buf_id = ddbuf_info->buff_id;
	/* Unmap the memory mapped to the device */
	ctx = str_ctx->vxd_dec_context;
	vxd = ctx->dev;

	tmp_result = vxd_unmap_buffer(vxd,
				      ctx,
				      ddbuf_info->kmstr_id,
				      ddbuf_info->buff_id);
	if (tmp_result != IMG_SUCCESS)
		result = tmp_result;

	/*
	 * Unmapping the memory mapped to the device - done
	 * Free the memory.
	 */
	tmp_result = talmmu_devmem_addr_free(ddbuf_info->hndl_memory);
	if (tmp_result != IMG_SUCCESS)
		result = tmp_result;

	/*
	 * for external mem manager buffers, just cleanup the idr list and
	 * buffer objects
	 */
	img_mem_free_bufid(ctx->mem_ctx, free_data.buf_id);

	return result;
}

/*
 * @Function                MMU_GetHeap
 */
int32 mmu_get_heap(uint32 image_stride, enum mmu_eheap_id *heap_id)
{
	uint32 i;
	uint8 found = osa_false;

	for (i = 0; i < MMU_HEAP_MAX; i++) {
		if (mmu_heaps[i].image_buffers) {
			*heap_id = mmu_heaps[i].heap_id;
			found = osa_true;
			break;
		}
	}

	VDEC_ASSERT(found);
	if (!found)
		return IMG_ERROR_COULD_NOT_OBTAIN_RESOURCE;

	return IMG_SUCCESS;
}

