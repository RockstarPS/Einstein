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
 * topaz mmu function implementations
 */

#include "fw_headers/defs.h"
#include "img_errors.h"
#include "img_mem.h"
#include "img_mem_man.h"
#include "osal/inc/osa_define.h"
#include "osal/inc/osa_mem.h"
#include "osal/inc/osa_spin.h"
#include "osal/inc/osa_mutex.h"
#include "target_config.h"
#include "talmmu_api.h"
#include "topazmmu.h"
#include "vxe_public_regdefs.h"

/* Global */
extern struct mem_space topaz_mem_space[];
extern void *g_lock;

int use_extended_addressing = 0;
uint32 mmu_control_val;
osa_bool device_initialized = osa_false;

/*
 * These determine the sizes of the MMU heaps we are using.
 * The tiled heap is set arbitrarily large at present.
 */
#define GENERALMMUHEAPLENGTH 0x40000000

/*
 * This describes the heaps - the separate areas mapped by the MMU
 * Currently we only use a single large heap as Topaz Core has no
 * MMU specific memory features.
 */
struct talmmu_heap_info mmu_heap_info [HEAP_ID_NO_OF_HEAPS]=
{
	{ MMU_GENERAL_HEAP_ID, TALMMU_HEAP_PERCONTEXT, TALMMU_HEAPFLAGS_NONE, "MEMSYSMEM", 0x00400000 , GENERALMMUHEAPLENGTH }
};

/* This describes the memory being mapped by the MMU */
struct talmmu_devmem_info mmu_device_memory_info = {
	/* ui32DeviceId */
	1,
	/* eMMUType */
	TALMMU_MMUTYPE_4K_PAGES_32BIT_ADDR,
	/* eDevFlags */
	TALMMU_DEVFLAGS_NONE,
	/* pszPageDirMemSpaceName */
	"MEMSYSMEM",
	/* pszPageTableMemSpaceName */
	"MEMSYSMEM",
	/* ui32PageSize */
	4096,
	/* ui32PageTableDirAlignment */
	0
};

/*
 * mmu template is global. so we don't need to worry about maintaining device
 * context
 */
void* mmu_template = NULL;

/*
 * Stream context is global. Can be modified in future to handle list of streams.
 */
struct mmu_str_context *str_ctx;

/*
 * Called once during initialization to initialize the MMU hardware, create
 * the template and define the MMU heap.
 * This is where talmmu initialization and template will be created.
 *
 * NOTE : We are not taking care of alignment here, need to be updated in
 * mmu_device_memory_info.
 */
int topaz_mmu_device_create(struct topaz_mmu_context *mmu_context, uint32 mmu_flags)
{
	void* topaz_multi_core_regid;
	uint32 hw_rev;
	int32 result, i;

	use_extended_addressing = (mmu_flags & MMU_EXTENDED_ADDR_FLAG);

	/* Initialize TALMMU API and create a template */
	result = talmmu_init();
	IMG_DBG_ASSERT(result == 0);

	if (result != 0) {
		OSA_PR_ERR("talmmu_init failed!\n");
		return IMG_ERROR_COULD_NOT_OBTAIN_RESOURCE;
	}

	/*
	 * We are reading the register and finding the mmu type, if needed this
	 * can be passed from the upper layers directly.
	 */

	topaz_multi_core_regid = (void *)topaz_mem_space[REG_TOPAZHP_MULTICORE].cpu_addr;

	hw_rev = VXE_RD_REG32(topaz_multi_core_regid, TOPAZHP_TOP_CR_TOPAZHP_CORE_REV);
	hw_rev &= (MASK_TOPAZHP_TOP_CR_TOPAZHP_MAINT_REV | MASK_TOPAZHP_TOP_CR_TOPAZHP_MINOR_REV | MASK_TOPAZHP_TOP_CR_TOPAZHP_MAJOR_REV);

	if (use_extended_addressing) {
		uint32 reg_val;

		/* Versions 3.6 and above may be 32-bit, 36-bit or 40-bit */
		reg_val = VXE_RD_REG32(topaz_multi_core_regid, TOPAZHP_TOP_CR_MULTICORE_HW_CFG);

		switch (F_DECODE(reg_val, TOPAZHP_TOP_CR_EXTENDED_ADDR_RANGE)) {
			case 0:
				mmu_device_memory_info.mmu_type = TALMMU_MMUTYPE_4K_PAGES_32BIT_ADDR;
			break;
			case 4:
				mmu_device_memory_info.mmu_type = TALMMU_MMUTYPE_4K_PAGES_36BIT_ADDR;
			break;
			case 8:
				mmu_device_memory_info.mmu_type = TALMMU_MMUTYPE_4K_PAGES_40BIT_ADDR;
			break;
			default:
				OSA_PR_ERR("Unsupported MMU mode requested\n");
				return IMG_ERROR_NOT_SUPPORTED;
		}
	}

	result = talmmu_devmem_template_create (&mmu_device_memory_info, &mmu_template);
	IMG_DBG_ASSERT(result == 0);
	if (result != 0) {
		OSA_PR_ERR("talmmu_devmem_template_create failed!\n");
		talmmu_deinit();
		return IMG_ERROR_COULD_NOT_OBTAIN_RESOURCE;
	}

	/* Add heaps to the template */
	for (i = 0 ; i < HEAP_ID_NO_OF_HEAPS; i++) {
		result = talmmu_devmem_heap_add (mmu_template, &(mmu_heap_info[i]));
		IMG_DBG_ASSERT(result == 0);
		if (result != 0) {
			OSA_PR_ERR("talmmu_devmem_heap_add failed!\n");
			talmmu_devmem_template_destroy(mmu_template);
			talmmu_deinit();
			return IMG_ERROR_COULD_NOT_OBTAIN_RESOURCE;
		}
	}

	/* Create a context from the template */
	/* (Template, User allocated user ID) */
	result = talmmu_devmem_ctx_create(mmu_template, 1, &mmu_context->mmu_context_handle);
	IMG_DBG_ASSERT(result == 0);
	if (result != 0) {
		OSA_PR_ERR("talmmu_devmem_ctx_create failed!\n");
		talmmu_devmem_template_destroy(mmu_template);
		talmmu_deinit();
		return IMG_ERROR_COULD_NOT_OBTAIN_RESOURCE;
	}

	topaz_core_mmu_flush_cache();

	/* Initialise stream list. */
	lst_init(&mmu_context->str_list);

	device_initialized = osa_true;

	return IMG_SUCCESS;
}

/*
 * This function is used to destroy the MMU device context.
 * NOTE: Destroy device automatically destroys any streams and frees and
 * memory allocated using MMU_StreamMalloc().
 */
int32 topaz_mmu_device_destroy(struct topaz_mmu_context *mmu_context)
{
	uint32 result = 0;
	struct mmu_str_context *str_ctx;

	/* Destroy all streams associated with the device. */
	str_ctx = lst_first(&mmu_context->str_list);
	while (str_ctx) {
		/* remove stream to list. */
		lst_remove(&mmu_context->str_list, str_ctx);
		topaz_mmu_stream_destroy(mmu_context, str_ctx);

		/* See if there are more streams. */
		str_ctx = lst_first(&mmu_context->str_list);
	}

	/* Destroy the device context */
	result = talmmu_devmem_ctx_destroy(mmu_context->mmu_context_handle);
	if (result != IMG_SUCCESS)
		return result;

	/* Destroy the template. */
	return (talmmu_devmem_template_destroy(mmu_template));
}

/*
 * This function is used to create and initialize the MMU stream context.
 */
int32 topaz_mmu_stream_create(struct topaz_mmu_context *mmu_context, uint32 km_str_id, void *vxe_enc_ctx_arg, void **mmu_str_ctx)
{
	struct mmu_str_context *str_ctx;

	/* Validate inputs. */
	if (!device_initialized)
		return IMG_ERROR_INVALID_PARAMETERS;

	/* Allocate a stream context structure */
	str_ctx = osa_zalloc(sizeof(*str_ctx), OSA_GFP_KERNEL);
	if (!str_ctx)
		return IMG_ERROR_OUT_OF_MEMORY;

	str_ctx->km_str_id = km_str_id;
	str_ctx->int_reg_num = 32;
	str_ctx->vxe_enc_context = (struct vxe_enc_ctx *)vxe_enc_ctx_arg;

	/* copy the mmu context created earlier */
	str_ctx->mmu_context_handle = mmu_context->mmu_context_handle;

	*mmu_str_ctx = str_ctx;

	/* Add stream to list. */
	lst_add(&mmu_context->str_list, str_ctx);

	return IMG_SUCCESS;
}

/*
 * This function is used to destroy the MMU stream context.
 * NOTE: Destroy automatically frees and memory allocated using
 *	mmu_stream_malloc().
 */
int32 topaz_mmu_stream_destroy(struct topaz_mmu_context *mmu_context, struct mmu_str_context *str_ctx)
{
	/* Validate inputs. */
	if (!str_ctx)
		return IMG_ERROR_INVALID_PARAMETERS;

	/* remove stream to list. */
	lst_remove(&mmu_context->str_list, str_ctx);

	osa_free(str_ctx);

	return IMG_SUCCESS;
}

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

int32 topaz_mmu_alloc(void *mmu_context_handle, struct vxe_enc_ctx *vxe_enc_ctx_arg,
		enum topaz_mmu_eheap_id heap_id, uint32 mem_heap_id,
		enum sys_emem_attrib mem_attrib,  uint32 size, uint32 alignment,
		struct vidio_ddbufinfo *ddbuf_info)
{
	int result = 0;
	void *devmem_heap_hndl;
	struct vxe_enc_ctx *ctx;
	struct vxe_dev *vxe;
	uint32 flags = 0;
	uint32 attributes = 0;

	if (!mmu_context_handle)
		return IMG_ERROR_INVALID_PARAMETERS;

	/* Set buffer size. */
	ddbuf_info->buf_size = size;

	/* Round size up to next multiple of physical pages */
	if ((size % HOST_MMU_PAGE_SIZE) != 0)
		size = ((size / HOST_MMU_PAGE_SIZE) + 1) * HOST_MMU_PAGE_SIZE;

	/* Allocate memory */
	ctx = vxe_enc_ctx_arg;
	vxe = ctx->dev;

	attributes = set_attributes(mem_attrib);

	result = img_mem_alloc(vxe->dev, ctx->mem_ctx, mem_heap_id,
			       size, (enum mem_attr)attributes, (int32 *) &ddbuf_info->buff_id);
	if (result != IMG_SUCCESS)
		goto error_alloc;

	ddbuf_info->is_internal = 1;

	/* TODO need to check more on attributes from memmgr_km */
	if (mem_attrib & SYS_MEMATTRIB_SECURE) {
		ddbuf_info->cpu_virt = NULL;
	} else {
		/* Map the buffer to CPU */
		result = img_mem_map_km(ctx->mem_ctx, ddbuf_info->buff_id);
		if (result) {
			OSA_DEV_ERR(vxe->dev, "%s: failed to map buf to cpu!(%d)\n",
				    __func__, result);
			goto error_get_heap_handle;
		}
		ddbuf_info->cpu_virt = img_mem_get_kptr(ctx->mem_ctx,
		ddbuf_info->buff_id);
	}

	/* Get heap handle */
	result = talmmu_get_heap_handle(heap_id, mmu_context_handle, &devmem_heap_hndl);
	if (result != IMG_SUCCESS)
		goto error_get_heap_handle;

	/* Allocate device "virtual" memory. */
	result = talmmu_devmem_addr_alloc(mmu_context_handle, devmem_heap_hndl,
					  size, alignment, &ddbuf_info->hndl_memory);
	if (result != IMG_SUCCESS)
		goto error_mem_map_ext_mem;

	/* Get the device virtual address. */
	result = talmmu_get_dev_virt_addr(ddbuf_info->hndl_memory, &ddbuf_info->dev_virt);
	if (result != IMG_SUCCESS)
		goto error_get_dev_virt_addr;

	result = img_mmu_map(ctx->mmu_ctx, ctx->mem_ctx, ddbuf_info->buff_id, ddbuf_info->dev_virt, flags);
	if (result != IMG_SUCCESS)
		goto error_map_dev;

	return IMG_SUCCESS;

error_map_dev:
error_get_dev_virt_addr:
	talmmu_devmem_addr_free(ddbuf_info->hndl_memory);
	ddbuf_info->hndl_memory = NULL;
error_mem_map_ext_mem:
error_get_heap_handle:
	img_mem_free(ctx->mem_ctx, ddbuf_info->buff_id);
error_alloc:
	return result;
}

/*
 * mmu_stream_malloc
 */
int32 topaz_mmu_stream_alloc(void *mmu_str_hndl, enum topaz_mmu_eheap_id heap_id,
		       uint32 mem_heap_id, enum sys_emem_attrib mem_attrib,
		       uint32 size, uint32 alignment,
		       struct vidio_ddbufinfo *ddbuf_info)
{
	struct mmu_str_context *str_ctx;

	/* Validate inputs. */
	if (!mmu_str_hndl)
		return IMG_ERROR_INVALID_PARAMETERS;

	str_ctx = (struct mmu_str_context *)mmu_str_hndl;

	/* Check if device level heap. */
	switch (heap_id) {
		case MMU_GENERAL_HEAP_ID:
		break;

		default:
			return IMG_ERROR_INVALID_PARAMETERS;
	}

	ddbuf_info->kmstr_id = str_ctx->km_str_id;

	/* Allocate device memory. */
	return (topaz_mmu_alloc(str_ctx->mmu_context_handle, str_ctx->vxe_enc_context,
			  heap_id, mem_heap_id, mem_attrib, size, alignment, ddbuf_info));
}

/*
 * mmu_stream_map_ext_sg
 */
int32 topaz_mmu_stream_map_ext_sg(void *mmu_str_hndl, enum topaz_mmu_eheap_id heap_id,
			    void *sgt, uint32 size, uint32 alignment,
			    enum sys_emem_attrib mem_attrib, void *cpu_linear_addr,
			    struct vidio_ddbufinfo *ddbuf_info, uint32 *buff_id)
{
	int32 result;
	void *devmem_heap_hndl;
	struct mmu_str_context *str_ctx;
	struct vxe_enc_ctx *ctx;
	struct vxe_dev *vxe;

	if (!mmu_str_hndl)
		return IMG_ERROR_INVALID_PARAMETERS;

	str_ctx = (struct mmu_str_context *)mmu_str_hndl;

	ctx = str_ctx->vxe_enc_context;
	vxe = ctx->dev;

	/* Check if device level heap. */
	switch (heap_id) {
		case MMU_GENERAL_HEAP_ID:
		break;

		default:
			return IMG_ERROR_INVALID_PARAMETERS;
	}

	if (!str_ctx->mmu_context_handle)
		return IMG_ERROR_INVALID_PARAMETERS;

	/* Set buffer size. */
	ddbuf_info->buf_size = size;

	/* Round size up to next multiple of physical pages */
	if ((size % HOST_MMU_PAGE_SIZE) != 0)
		size = ((size / HOST_MMU_PAGE_SIZE) + 1) * HOST_MMU_PAGE_SIZE;

	result = img_mem_import(vxe->dev, ctx->mem_ctx, ddbuf_info->buf_size,
				(enum mem_attr)set_attributes(mem_attrib), (int32 *) buff_id);
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
	result = talmmu_get_heap_handle(heap_id, str_ctx->mmu_context_handle, &devmem_heap_hndl);
	if (result != IMG_SUCCESS)
		return result;

	/* Allocate device "virtual" memory. */
	result = talmmu_devmem_addr_alloc(str_ctx->mmu_context_handle, devmem_heap_hndl,
					  size, alignment, &ddbuf_info->hndl_memory);
	if (result != IMG_SUCCESS)
		return result;

	/* Get the device virtual address. */
	result = talmmu_get_dev_virt_addr(ddbuf_info->hndl_memory, &ddbuf_info->dev_virt);
	if (result != IMG_SUCCESS)
		goto error_get_dev_virt_addr;

	result = img_mmu_map_sg(ctx->mmu_ctx, ctx->mem_ctx, ddbuf_info->buff_id, sgt,
				ddbuf_info->dev_virt, mem_attrib);
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
 * topaz_mmu_stream_map_ext
 */
int32 topaz_mmu_stream_map_ext(void *mmu_str_hndl, enum topaz_mmu_eheap_id heap_id,
			 uint32 buff_id, uint32 size, uint32 alignment,
			 enum sys_emem_attrib mem_attrib, void *cpu_linear_addr,
			 struct vidio_ddbufinfo *ddbuf_info)
{
	int32 result = 0;
	void *devmem_heap_hndl;
	struct vxe_enc_ctx *ctx;
	struct mmu_str_context *str_ctx;

	if (!mmu_str_hndl)
		return IMG_ERROR_INVALID_PARAMETERS;

	str_ctx = (struct mmu_str_context *)mmu_str_hndl;

	/* Check if device level heap. */
	switch (heap_id) {
		case MMU_GENERAL_HEAP_ID:
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
	result = talmmu_get_heap_handle(heap_id, str_ctx->mmu_context_handle,
					&devmem_heap_hndl);
	if (result != IMG_SUCCESS)
		return result;

	/* Allocate device "virtual" memory. */
	result = talmmu_devmem_addr_alloc(str_ctx->mmu_context_handle,
					  devmem_heap_hndl, size, alignment,
					  &ddbuf_info->hndl_memory);
	if (result != IMG_SUCCESS)
		return result;

	/* Get the device virtual address. */
	result = talmmu_get_dev_virt_addr(ddbuf_info->hndl_memory, &ddbuf_info->dev_virt);
	if (result != IMG_SUCCESS)
		return result;

	/*
	 * Map device memory (allocated from outside VDEC)
	 * into the stream PTD.
	 */
	ctx = str_ctx->vxe_enc_context;

	return (img_mmu_map(ctx->mmu_ctx, ctx->mem_ctx, ddbuf_info->buff_id, ddbuf_info->dev_virt, mem_attrib));
}

/*
 * topaz_mmu_free
 */
int32 topaz_mmu_free(struct vxe_enc_ctx *vxe_enc_ctx_arg, struct vidio_ddbufinfo *ddbuf_info)
{
	int result = 0;
	struct vxe_enc_ctx *ctx;

	/* Validate inputs. */
	if (!ddbuf_info)
		return IMG_ERROR_INVALID_PARAMETERS;

	/* Unmap the memory mapped to the device */
	ctx = vxe_enc_ctx_arg;
	result = img_mmu_unmap(ctx->mmu_ctx, ctx->mem_ctx, ddbuf_info->buff_id);

	/*
	 * Unmapping the memory mapped to the device - done
	 * Free the memory.
	 */
	result = talmmu_devmem_addr_free(ddbuf_info->hndl_memory);

	if (ddbuf_info->is_internal)
	 img_mem_free(ctx->mem_ctx, ddbuf_info->buff_id);

	return result;
}

/*
 * topaz_mmu_free_mem.
 * This should be used only to free the stream memory.
 */
int32 topaz_mmu_stream_free(void *mmu_str_hndl, struct vidio_ddbufinfo *ddbuf_info)
{
	struct mmu_str_context *str_ctx;

	if (!mmu_str_hndl)
		return IMG_ERROR_INVALID_PARAMETERS;

	str_ctx = (struct mmu_str_context *)mmu_str_hndl;

	return topaz_mmu_free(str_ctx->vxe_enc_context, ddbuf_info);
}

/*
 * topaz_mmu_free_mem_sg.
 * This should be used only to free the stream memory.
 */
int32 topaz_mmu_stream_free_sg(void *mmu_str_hndl, struct vidio_ddbufinfo *ddbuf_info)
{
	int result = 0;
	struct vxe_enc_ctx *ctx;
	struct mmu_str_context *str_ctx;


	/* Validate inputs. */
	if (!ddbuf_info || !mmu_str_hndl)
		return IMG_ERROR_INVALID_PARAMETERS;

	str_ctx = (struct mmu_str_context *)mmu_str_hndl;

	/* Unmap the memory mapped to the device */
	ctx = str_ctx->vxe_enc_context;

	result = img_mmu_unmap(ctx->mmu_ctx, ctx->mem_ctx, ddbuf_info->buff_id);

	/*
	 * Unmapping the memory mapped to the device - done
	 * Free the memory.
	 */
	result = talmmu_devmem_addr_free(ddbuf_info->hndl_memory);

	/*
	 * for external mem manager buffers, just cleanup the idr list and
	 * buffer objects
	 */
	img_mem_free_bufid(ctx->mem_ctx, ddbuf_info->buff_id);

	return result;
}

int topaz_update_device_mem(struct vxe_enc_ctx *vxe_enc_ctx_arg,
		      struct vidio_ddbufinfo *ddbuf_info)
{
	struct vxe_enc_ctx *ctx = vxe_enc_ctx_arg;

	return img_mem_sync_cpu_to_device(ctx->mem_ctx,
					  ddbuf_info->buff_id);
}

int32 topaz_update_host_mem(struct vxe_enc_ctx *vxe_enc_ctx_arg,
		      struct vidio_ddbufinfo *ddbuf_info)
{
	struct vxe_enc_ctx *ctx = vxe_enc_ctx_arg;

	return img_mem_sync_device_to_cpu(ctx->mem_ctx,
					  ddbuf_info->buff_id);
}

/*
 * Called for each Topaz core when MMU support is activated, sets up the MMU
 * hardware for the specified core.
 */
int topaz_core_mmu_hw_setup(struct topaz_mmu_context *mmu_context, void* core_reg)
{
	uint32 cmd;

	/* Bypass all requesters while MMU is being configured */
	cmd = F_ENCODE(1, TOPAZHP_TOP_CR_MMU_BYPASS_TOPAZ);
	VXE_WR_REG32 ( core_reg, TOPAZHP_TOP_CR_MMU_CONTROL0, cmd );

	VXE_WR_REG32(core_reg, TOPAZHP_TOP_CR_MMU_DIR_LIST_BASE(0), mmu_context->ptd_phys_addr);

	cmd = VXE_RD_REG32(core_reg,TOPAZHP_TOP_CR_MMU_DIR_LIST_BASE(0));

	OSA_PR_INFO("Page table directory at physical address 0x%08x\n", cmd);
	/*
	 * Set up the Index Register (to point to the base register)
	 * We're setting all fields to zero (all flags pointing to directory bank 0)
	 */
	cmd = 0;

	/*  Now enable MMU access for all requesters */
	cmd = F_ENCODE(use_extended_addressing ? 1 : 0, TOPAZHP_TOP_CR_MMU_ENABLE_36BIT_ADDRESSING); /* 36-bit actually means "not 32-bit" */
	VXE_WR_REG32(core_reg, TOPAZHP_TOP_CR_MMU_CONTROL2, cmd);

	mmu_control_val = cmd= F_ENCODE(0, TOPAZHP_TOP_CR_MMU_BYPASS_TOPAZ);

	VXE_WR_REG32 ( core_reg, TOPAZHP_TOP_CR_MMU_CONTROL0, cmd );

	return 0;
}

/*
 * topaz_core_mmu_flush_cache
 */
int topaz_core_mmu_flush_cache(void)
{
	static void* core_reg = NULL;
	uint32 reg_value;
	ulong flags;

	if (core_reg == NULL)
		core_reg = (void *)topaz_mem_space[REG_TOPAZHP_MULTICORE].cpu_addr;

	/* TODO we can have global mutex or local based on need */
	osa_spin_lock_irqsave(g_lock, &flags);

	reg_value = VXE_RD_REG32( core_reg, TOPAZHP_TOP_CR_MMU_CONTROL0);

	/* PAUSE */
	reg_value |= F_ENCODE(1, TOPAZHP_TOP_CR_MMU_PAUSE);
	VXE_WR_REG32 ( core_reg, TOPAZHP_TOP_CR_MMU_CONTROL0, reg_value);

	{
		uint32 i, mem_req_reg;
		wait_till_idle:
		for (i = 0; i < 10; i++) {
			mem_req_reg = VXE_RD_REG32 (core_reg, TOPAZHP_TOP_CR_MMU_MEM_REQ);
			if (mem_req_reg != 0)
				goto wait_till_idle;
		}
	}

	/* Set invalidate */
	reg_value |= F_ENCODE(1, TOPAZHP_TOP_CR_MMU_INVALDC);
	VXE_WR_REG32 ( core_reg, TOPAZHP_TOP_CR_MMU_CONTROL0, reg_value);

	/* Clear invalidate */
	reg_value &= ~((uint32)F_ENCODE(1, TOPAZHP_TOP_CR_MMU_INVALDC));
	VXE_WR_REG32 ( core_reg, TOPAZHP_TOP_CR_MMU_CONTROL0, reg_value);


	/* UNPAUSE */
	reg_value &= ~((uint32)F_ENCODE(1, TOPAZHP_TOP_CR_MMU_PAUSE));
	VXE_WR_REG32 ( core_reg, TOPAZHP_TOP_CR_MMU_CONTROL0, reg_value);

	/* TODO we can have global mutex or local based on need */
	osa_spin_unlock_irqrestore(g_lock, flags);

	return 0;
}
