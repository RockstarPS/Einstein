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
 * IMG ENC TIMMLIB Interface function implementations
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
#include <pthread.h>

#include "osa_idr.h"
#include "osa_list.h"
#include "osa_time.h"
#include "osa_semaphore.h"
#include "osa_queue.h"
#include "osa_err.h"
#include "osa_hwi.h"
#include "osa_module.h"
#include "osa_reg_io.h"
#include "osa_task.h"
#include "osa_define.h"
#include "fw_headers/vxe_common.h"
#include "target_config.h"
#include "topaz_device.h"
#include "vxe_enc.h"
#include "mm_enc.h"
#include "mm_enc_priv.h"
#include "img_mem_man.h"

#include "target_config.h"
#include "topaz_device.h"

#define IMG_VXE_ENC_MODULE_NAME "vxe-enc"

static struct vxe_dev *vxe = NULL;

static struct heap_config vxe_enc_heap_configs[] = { { .type =
		MEM_HEAP_TYPE_UNIFIED, .options.unified = { .gfp_type = 0, },
		.to_dev_addr = NULL, }, };

static void enc_intr_handler(void *arg)
{
	void *intr_sem_handle = arg;
	if( OSA_IRQ_WAKE_THREAD == topazdd_isr(&vxe->topaz_dev_ctx))
	{
		osa_semaphore_post(intr_sem_handle);
	}
}

static void *enc_soft_thread_irq(void *arg0)
{
    mm_intr_handle *intr = (mm_intr_handle *)arg0;

	while(1)
	{
        osa_mutex_lock(vxe->mutex);
        void *intr_sem_handle = intr->intr_sem_handle;
        osa_mutex_unlock(vxe->mutex);
	    if(intr_sem_handle == NULL) {
	        OSA_DEV_INFO(vxe->dev, "%s:%d exit thread",__func__,__LINE__);
	        break;
	    }
	    else {
	        osa_semaphore_pend(intr_sem_handle, (uint32)osa_semaphore_wait_forever);
	        pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	        topazdd_threaded_isr(&vxe->topaz_dev_ctx);
	        pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	    }
	}
	return NULL;
}

static void vxe_eos(struct vxe_enc_ctx *ctx)
{
	void (* mm_ret_resource)(struct mm_buffer *buf, mm_enc_process_cb cb_type, void *cb_ctx);
	mm_ret_resource = (void (*)(struct mm_buffer *buf, mm_enc_process_cb cb_type, void *cb_ctx))ctx->mm_return_resource;
	mm_ret_resource(NULL, MM_CB_ENC_STR_END, ctx->cb_ctx);
}

static void vxe_return_resource(void *ctx_handle, enum vxe_cb_type type,
				void *img_buf_ref, uint32 size,
				uint32 coded_frm_cnt)
{
	struct vxe_buffer *buf = NULL;
	struct vxe_enc_ctx *ctx = ctx_handle;
#ifdef ENABLE_PROFILING
	struct osa_timespec time;
#endif

	void (* mm_ret_resource)(struct mm_buffer *buf, mm_enc_process_cb cb_type, void *cb_ctx);

	mm_ret_resource = (void (*)(struct mm_buffer *buf, mm_enc_process_cb cb_type, void *cb_ctx))ctx->mm_return_resource;

	switch (type) {
		case VXE_CB_CODED_BUFF_READY:
			if (!img_buf_ref)
				OSA_DEV_ERR(ctx->dev, "VXE_CB_CODED_BUFF_READY had no buffer\n");

			buf = osa_container_of((struct img_coded_buffer *)img_buf_ref,
					       struct vxe_buffer, coded_buffer);

			if (!buf) {
				OSA_DEV_ERR(ctx->dev,
					"Could not locate coded buffer in the list\n");
			} else {
				buf->buffer->size[0] = size;
#ifdef ENABLE_PROFILING
				osa_getnstimeofday(&time);
				ctx->drv_lat.end_time = osa_timespec_to_ns(&time);

				OSA_PR_ERR("driver encode time is %llu us\n",
					div_s64(ctx->drv_lat.end_time -
					ctx->drv_lat.start_time, 1000));
#endif

				mm_ret_resource(buf->buffer, MM_CB_CODED_BUFF_READY, ctx->cb_ctx);
			}

			if (coded_frm_cnt == ctx->last_frame_num) {
				vxe_eos(ctx);
			}
			break;
		case VXE_CB_SRC_FRAME_RELEASE:
			if (!img_buf_ref)
				OSA_DEV_ERR(ctx->dev, "VXE_CB_FRAME_RELEASE had no buffer\n");

			buf = osa_container_of((struct img_frame *)img_buf_ref,
					       struct vxe_buffer, src_frame);

			if (!buf) {
				OSA_DEV_ERR(ctx->dev,
					"Could not locate SRC Frame in the list %p\n", img_buf_ref);
			} else {
				ctx->frames_encoding--;
				mm_ret_resource(buf->buffer, MM_CB_SRC_FRAME_RELEASE, ctx->cb_ctx);
			}

			break;
		case VXE_CB_ERROR_FATAL:
		    mm_ret_resource(NULL, MM_CB_ENC_ERROR_FATAL, ctx->cb_ctx);
			break;
		default:
			break;
	}
}

/* This function is going to register hardware interrupt */
static int enc_reg_interrupt(void)
{
	task_params params = {0};
	mm_intr_handle *intr = &g_MM_ENC_Inst.intr_handle;

	intr->intr_sem_handle = osa_semaphore_create(osa_semaphore_mode_counting, 0);
	if(NULL == intr->intr_sem_handle)
	{
		OSA_PR_ERR("%s: Semaphore creation failed!", __func__);
		return OSA_STATUS_EFAIL;
	}

	params.arg0 = intr;
	params.priority = OSA_INTERRUPT_TASK_PRIORITY;
	intr->intr_task_handle = osa_task_create(enc_soft_thread_irq, &params);
	if(NULL == intr->intr_task_handle)
	{
		OSA_PR_ERR("%s: Creating task for interrupt is failed!", __func__);
		return OSA_STATUS_EFAIL;
	}

	intr->intr_handle = osa_hwi_create(enc_intr_handler, intr->intr_sem_handle, HWA_ENCODER);
	if(NULL == intr->intr_handle)
	{
		OSA_PR_ERR("%s: Failed to register hardware interrupt!", __func__);
		return OSA_STATUS_EFAIL;
	}

	return OSA_STATUS_SOK;
}

/* This function is going to release hardware interrupt resource */
static void enc_release_interrupt_resource(void)
{
	struct vxe_dev *vxe = g_MM_ENC_Inst.mm_dev;
	mm_intr_handle *intr = &g_MM_ENC_Inst.intr_handle;

	osa_mutex_lock(vxe->mutex);
	if(intr->intr_handle)
	{
	    osa_hwi_delete(intr->intr_handle);
	    intr->intr_handle = NULL;
	}

	if(intr->intr_task_handle)
	{
	    osa_task_delete(intr->intr_task_handle);
	    intr->intr_task_handle = NULL;
	}

	if(intr->intr_sem_handle)
	{
	    osa_semaphore_delete(intr->intr_sem_handle);
	    intr->intr_sem_handle = NULL;
	}
	osa_mutex_unlock(vxe->mutex);

}

int32 MM_ENC_Init(mm_enc_init_params *init_params) {
	int32 ret;
	struct vxe_enc_ctx *ctx;
	struct heap_config *heap_configs = vxe_enc_heap_configs;
	int32 num_heaps = ARRAY_SIZE(vxe_enc_heap_configs);
	uint32 i;
	uint8_t *ram = NULL;
	uint32_t ram_size = 0;

	ret = osa_pm_set_module_state_encoder_on();
	if(0 != ret)
	{
		OSA_PR_ERR("%s: failed to power-on encoder hardware!\n", __func__);
		return ret;
	}

	vxe = osa_calloc(sizeof(*vxe), sizeof(uint8), 0);
	if (!vxe)
	{
		ret = osa_pm_set_module_state_encoder_off();
		return -OSA_ENOMEM;
	}

	vxe->dev = vxe;
	vxe->plat_dev = (struct platform_device *)vxe;

	vxe->reg_base = osa_get_encoder_base_reg_addr();
	vxe->ram_chunk_owner[0] = NULL;
	vxe->ram_chunk_owner[1] = NULL;
	vxe->ocm_ram_chunk[0] = NULL;
	vxe->ocm_ram_chunk[1] = NULL;

	if (init_params)
	{
		ram = (uint8_t *)init_params->ocm_ram_addr;
		ram_size = init_params->ocm_ram_size;

		switch (ram_size / OCM_RAM_POOL_CHUNK_SIZE) {
			case 2:
				vxe->ocm_ram_chunk[1] = ram;
				ram = ram + OCM_RAM_POOL_CHUNK_SIZE;
				/* fall through */
			case 1:
				vxe->ocm_ram_chunk[0] = ram;
				break;
			default:
				OSA_PR_WARN("%s: No OCM RAM pool available, fallback to DDR mode for above mp params\n", __func__);
		}
	}

	ret = img_mem_init(vxe->dev);
	if (ret) {
		OSA_DEV_ERR(vxe->dev, "Failed to initialize memory\n");
		goto exit;
	}

	INIT_OSA_LIST_HEAD(&vxe->drv_ctx.heaps);
	vxe->drv_ctx.internal_heap_id = VXE_INVALID_ID;

	/* Initialise memory management component */
	for (i = 0; i < num_heaps; i++) {
		struct vxe_heap *heap;

		OSA_DEV_INFO(vxe->dev, "%s: adding heap of type %d\n",
			 __func__, heap_configs[i].type);

		heap = osa_zalloc(sizeof(*heap), OSA_GFP_KERNEL);
		if (!heap) {
			ret = -OSA_ENOMEM;
			goto out_heap_added;
		}

		ret = img_mem_add_heap(&heap_configs[i], &heap->id);
		if (ret < 0) {
			OSA_DEV_ERR(vxe->dev, "%s: failed to init heap (type %d)!\n",
				__func__, heap_configs[i].type);
			osa_free(heap);
			goto out_heap_added;
		}
		osa_list_add(&heap->list, &vxe->drv_ctx.heaps);

		/* Implicitly, first heap is used for internal allocations */
		if (vxe->drv_ctx.internal_heap_id < 0) {
			vxe->drv_ctx.internal_heap_id = heap->id;
			OSA_DEV_INFO(vxe->dev, "%s: using heap %d for internal alloc\n",
				__func__, vxe->drv_ctx.internal_heap_id);
		}
	}

	/* Do not proceed if internal heap not defined */
	if (vxe->drv_ctx.internal_heap_id < 0) {
		OSA_DEV_ERR(vxe->dev, "%s: failed to locate heap for internal alloc\n",
			__func__);
		ret = -OSA_EINVAL;
		/* Loop registered heaps just for sanity */
		goto out_heap_added;
	}

	ret = vxe_init_mem(vxe);
	if (ret) {
		OSA_DEV_ERR(vxe->dev, "Failed to initialize memory\n");
		goto out_heap_added;
	}

	osa_mutex_create(&vxe->mutex);
	if (NULL == vxe->mutex) {
		ret = osa_pm_set_module_state_encoder_off();
		goto out_init;
	}

	ret = enc_reg_interrupt();
	if(OSA_STATUS_SOK != ret)
	{
		goto out_free_irq;
	}

	ctx = osa_zalloc(sizeof(*ctx), OSA_GFP_KERNEL);
	if (!ctx) {
		return -OSA_ENOMEM;
	}
	ctx->dev = vxe;

	vxe_fill_default_params(ctx);

	ctx->mem_ctx = vxe->drv_ctx.mem_ctx;
	ctx->mmu_ctx = vxe->drv_ctx.mmu_ctx;

	vxe->ctx = ctx;

	ret = topazdd_init((uint_addr)vxe->reg_base, ENCODER0_REG_SIZE,
			   (MMU_USE_MMU_FLAG | MMU_EXTENDED_ADDR_FLAG),
			   ctx, vxe->drv_ctx.ptd, &vxe->topaz_dev_ctx);
	if (ret)
		goto out_free_irq;

	osa_idr_init(&vxe->streams);
	if (NULL == vxe->streams) {
		ret = OSA_ENOMEM;
		goto out_topazdd_deinit;
	}

	ret = init_topaz_core(vxe->topaz_dev_ctx, &vxe->num_pipes,
			      (MMU_USE_MMU_FLAG | MMU_EXTENDED_ADDR_FLAG),
			      vxe_return_resource);
	if (ret) {
		OSA_DEV_ERR(&ctx->dev, "Failed to initialize topaz core\n");
		goto out_topaz_core_deinit;
	}

	g_MM_ENC_Inst.mm_dev = vxe;
	for(i=0; i<MAX_NUM_CHANNELS; i++)
	{
		g_MM_ENC_Inst.ch_obj[i].ch_id = 0x7FFFFFFFU;
		g_MM_ENC_Inst.ch_obj[i].is_used = 0U;
	}

	return 0;

out_topaz_core_deinit:
		deinit_topaz_core();

out_topazdd_deinit:
		topazdd_deinit(vxe->topaz_dev_ctx);

out_free_irq:
		osa_free(vxe->ctx);
		enc_release_interrupt_resource();
		osa_mutex_destroy(vxe->mutex);

out_init:
		vxe_deinit_mem(vxe);

out_heap_added:
		while (!osa_list_empty(&vxe->drv_ctx.heaps)) {
			struct vxe_heap *heap;

			heap = osa_list_first_entry(&vxe->drv_ctx.heaps, struct vxe_heap, list);
			osa_list_del(&heap->list);
			img_mem_del_heap(heap->id);
			osa_free(heap);
		}
		vxe->drv_ctx.internal_heap_id = VXE_INVALID_ID;

exit:
		osa_pm_set_module_state_encoder_off();
		osa_free(vxe);

return ret;
}

int32 MM_ENC_Deinit(void)
{
	deinit_topaz_core();
	topazdd_deinit(vxe->topaz_dev_ctx);
	osa_idr_destroy(vxe->streams);
	osa_free(vxe->ctx);
	img_mem_exit();
	enc_release_interrupt_resource();
	osa_mutex_destroy(&vxe->mutex);
	osa_free(vxe);
	osa_pm_set_module_state_encoder_off();
#ifdef DEBUG_OSA_MEM
	OSA_PR_ERR("##### At the end of MM_ENC_Deinit #####");
	osa_print_mem_leak();
#endif
	return 0;
}
