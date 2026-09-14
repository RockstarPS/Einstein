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
 * IMG DEC TIMMLIB Interface function implementations
 */

#include <errno.h>

#include "core.h"
#include "vxd_pvdec_priv.h"
#include "vxd_dec.h"
#include "osa_idr.h"
#include "osa_list.h"
#include "osa_time.h"
#include "osa_semaphore.h"
#include "osa_queue.h"
#include "osa_hwi.h"
#include "osa_module.h"
#include "osa_reg_io.h"
#include "osa_task.h"
#include "mm_dec_priv.h"
#include "mm_dec.h"

static struct vxd_dev *vxd = NULL;

static struct heap_config vxd_dec_heap_configs[] = { { .type =
		MEM_HEAP_TYPE_UNIFIED, .options.unified = { .gfp_type = 0, },
		.to_dev_addr = NULL, }, };

static void dec_intr_handler(uintptr_t arg)
{
	void *intr_sem_handle = (void *)arg;
	if( OSA_IRQ_WAKE_THREAD == vxd_handle_irq(vxd))
	{
		osa_semaphore_post(intr_sem_handle);
	}
}

static void *dec_soft_thread_irq(void *arg0)
{
	void *intr_sem_handle = arg0;
	uint32 semaphore_timeout = 10000000; //10s

	while(1)
	{
		int32 ret = osa_semaphore_pend(intr_sem_handle, semaphore_timeout);
		if(ret == -1) {
			OSA_PR_ERR("%s:%d osa_semaphore_pend returned err (%s)",
					__func__, __LINE__, strerror(errno));
			break;
		}
		vxd_handle_thread_irq(vxd);
	}
	return NULL;
}

#if ENABLE_PROFILING
static void profile_dec_driver(struct vxd_return *res)
{
	struct vxd_dec_ctx *ctx;
	struct osa_timespec time;
	int32 loop;

	ctx = res->ctx;
	osa_getnstimeofday(&time);
	for (loop = 0; loop < ARRAY_SIZE(ctx->dev->time_drv); loop++) {
		if (ctx->dev->time_drv[loop].id == res->buf_map_id) {
			ctx->dev->time_drv[loop].end_time = osa_timespec_to_ns(&time);
			OSA_PR_ERR(
					"%s:%d picture buf decode time is %llu us for msg_id x%0x\n",
					__func__, __LINE__,
					div_s64(
							ctx->dev->time_drv[loop].end_time
									- ctx->dev->time_drv[loop].start_time,
							1000), res->buf_map_id);
			ctx->dev->time_drv[loop].id = 0;
			break;
		}
	}
	if (loop == ARRAY_SIZE(ctx->dev->time_drv))
		OSA_PR_ERR(
				"%s: picture buf decode for buf_map_id x%0x is not measured\n",
				__func__, res->buf_map_id);
}
#endif

void vxd_return_resource(void *ctx_handle, enum vxd_cb_type type,
				uint32 buf_map_id)
{
#if ENABLE_PROFILING
	struct vxd_return res;
#endif
	uint32 error_flags;
	struct vxd_buffer *buf = NULL;
	struct vxd_dec_ctx *ctx = (struct vxd_dec_ctx *) ctx_handle;
	void (* mm_ret_resource)(void *item, mm_dec_process_cb cb_type, void *cb_ctx);

	mm_ret_resource = (void (*)(void *item, mm_dec_process_cb cb_type, void *cb_ctx))ctx->mm_return_resource;

	if((osa_true == ctx->stop_initiated) && (0 == ctx->num_decoding))
	{
		osa_semaphore_post(ctx->sem_eos);
	}

	switch (type) {
	case VXD_CB_STRUNIT_PROCESSED:

		buf = find_buffer(buf_map_id, &ctx->out_buffers);
		if (!buf) {
			OSA_PR_WARN(
					"Could not locate buf_map_id=0x%x in OUTPUT buffers list\n", buf_map_id);
		}
		else {
			mm_ret_resource((void*)buf->buffer, MM_CB_STRUNIT_PROCESSED, ctx->mm_cb_ctx);
		}
		break;
	case VXD_CB_PICT_DECODED:
#if ENABLE_PROFILING
		res.ctx = ctx;
		res.buf_map_id = buf_map_id;
		profile_dec_driver(&res);
#endif
		mm_ret_resource(NULL, MM_CB_PICT_DECODED, ctx->mm_cb_ctx);
		break;
	case VXD_CB_PICT_DISPLAY:
		buf = find_buffer(buf_map_id, &ctx->cap_buffers);
		if (!buf) {
			OSA_PR_WARN(
					"Could not locate buf_map_id=0x%x in CAPTURE buffers list\n", buf_map_id);
			break;
		}
		else {
			mm_ret_resource((void*)buf->buffer, MM_CB_PICT_DISPLAY, ctx->mm_cb_ctx);
		}
		buf->reuse = osa_false;
		break;
	case VXD_CB_PICT_RELEASE:
		buf = find_buffer(buf_map_id, &ctx->reuse_queue);
		if (buf) {
			buf->reuse = osa_true;
			osa_list_move_tail(&buf->list, &ctx->cap_buffers);
			break;
		}
		buf = find_buffer(buf_map_id, &ctx->cap_buffers);
		if (!buf) {
			OSA_PR_WARN(
					"Could not locate buf_map_id=0x%x in CAPTURE buffers list\n", buf_map_id);

			break;
		}
		else {
				mm_ret_resource((void*)buf->buffer, MM_CB_PICT_RELEASE, ctx->mm_cb_ctx);
		}
		buf->reuse = osa_true;

		break;
	case VXD_CB_PICT_END:
		mm_ret_resource(NULL, MM_CB_PICT_END, ctx->mm_cb_ctx);
		break;
	case VXD_CB_STR_END:
		ctx->flag_last = osa_true;
		mm_ret_resource(NULL, MM_CB_STR_END, ctx->mm_cb_ctx);
		break;
	case VXD_CB_ERROR_FATAL:
		error_flags = buf_map_id;
		if( (error_flags & VDEC_ERROR_SERVICE_TIMER_EXPIRY) ||
			(error_flags & VDEC_ERROR_MMU_FAULT) ||
		(error_flags & VDEC_ERROR_DEVICE)) {
			/*
			 * There has been FW error, so we need to reload the firmware.
			 */
			vxd_error_recovery(ctx);
		}
		mm_ret_resource((void *)&error_flags, MM_CB_ERROR, ctx->mm_cb_ctx);
		break;
	default:
		break;
	}
}

/* This function is going to register hardware interrupt */
static int dec_reg_interrupt(void)
{
	task_params params = {0};
	mm_intr_handle *intr = &g_MM_DEC_Inst.intr_handle;

	intr->intr_sem_handle = osa_semaphore_create(osa_semaphore_mode_counting, 0);
	if(NULL == intr->intr_sem_handle)
	{
		OSA_PR_ERR("%s: Semaphore creation failed!", __func__);
		return OSA_STATUS_EFAIL;
	}

	params.arg0 = intr->intr_sem_handle;
	params.priority = OSA_INTERRUPT_TASK_PRIORITY;
	intr->intr_task_handle = osa_task_create(dec_soft_thread_irq, &params);
	if(NULL == intr->intr_task_handle)
	{
		OSA_PR_ERR("%s: Creating task for interrupt is failed!", __func__);
		return OSA_STATUS_EFAIL;
	}

	intr->intr_handle = osa_hwi_create(dec_intr_handler, intr->intr_sem_handle, HWA_DECODER);
	if(NULL == intr->intr_handle)
	{
		OSA_PR_ERR("%s: Failed to register hardware interrupt!", __func__);
		return OSA_STATUS_EFAIL;
	}

	return OSA_STATUS_SOK;
}

static void vxd_workqueue_Task(void *arg0, void *arg1)
{
	void *queue_handle = (void *)arg0;
	void *sem_handle = arg1;
	struct work_struct *pBuf = NULL;

	while(1)
	{
		osa_utils_queget(queue_handle, (void **)&pBuf, 1U, (uint32)osa_semaphore_wait_forever);
		if(NULL != pBuf)
		{
			if(pBuf->work_complete)
			{
				osa_free(pBuf);
				osa_semaphore_post(sem_handle);
				break;
			}
			else
			{
				pBuf->worker_func(pBuf->work);
			}
		}
		pBuf = NULL;
	}
}

/* This function is going to creating vxd work-queue */
static int dec_create_vxd_worker_task(void)
{
	task_params params = {0};
	mm_work_queue_handle *vxd_work_queue = &g_MM_DEC_Inst.vxd_work_queue_handle;

	/* VXD worker creation */
	vxd_work_queue->queue_handle = osa_malloc(sizeof(osa_utils_quehandle), 0);
	if(NULL == vxd_work_queue->queue_handle)
	{
		OSA_PR_ERR("%s: Failed to allocate memory for Queue!", __func__);
		return OSA_STATUS_EFAIL;
	}

	vxd_work_queue->queueMem = osa_calloc(WORK_MAX_QUEUE_ELEMENTS, sizeof(void *), 0);
	if(NULL == vxd_work_queue->queueMem)
	{
		OSA_PR_ERR("%s: Failed to allocate memory for holding Queue elements!", __func__);
		return OSA_STATUS_EFAIL;
	}

	osa_utils_quecreate(vxd_work_queue->queue_handle,
			WORK_MAX_QUEUE_ELEMENTS,
			vxd_work_queue->queueMem,
			OSA_UTILS_QUE_FLAG_BLOCK_QUE);

	vxd_work_queue->workq_sem_handle = osa_semaphore_create(osa_semaphore_mode_binary, 0);
	if(NULL == vxd_work_queue->workq_sem_handle)
	{
		OSA_PR_ERR("%s: Semaphore creation failed for WorkQueue!", __func__);
		return OSA_STATUS_EFAIL;
	}

	params.arg0 = vxd_work_queue->queue_handle;
	params.arg1 = vxd_work_queue->workq_sem_handle;
	params.priority = OSA_VXD_WORKER_TASK_PRIORITY;
	vxd_work_queue->workq_task_handle = osa_task_create(vxd_workqueue_Task, &params);
	if(NULL == vxd_work_queue->workq_task_handle)
	{
		OSA_PR_ERR("%s: Creating task for WorkQueue is failed!", __func__);
		return OSA_STATUS_EFAIL;
	}

	vxd->vxd_worker_queue_handle = vxd_work_queue->queue_handle;
	vxd->vxd_worker_queue_sem_handle = vxd_work_queue->workq_sem_handle;

	return OSA_STATUS_SOK;
}

/* This function is going to release hardware interrupt resource */
static void dec_release_interrupt_resource(void)
{
	mm_intr_handle *intr = &g_MM_DEC_Inst.intr_handle;

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
}

/* This function is going to release vxd work-queue resource */
static void dec_release_vxd_workqueue_resource(void)
{
	mm_work_queue_handle *vxd_work_queue = &g_MM_DEC_Inst.vxd_work_queue_handle;

	if(vxd_work_queue->workq_task_handle)
	{
		osa_task_delete(vxd_work_queue->workq_task_handle);
		vxd_work_queue->workq_task_handle = NULL;
	}

	if(vxd_work_queue->queue_handle)
	{
		osa_utils_quedelete(vxd_work_queue->queue_handle);
		osa_free(vxd_work_queue->queue_handle);
		vxd_work_queue->queue_handle = NULL;
	}

	if(vxd_work_queue->workq_sem_handle)
	{
		osa_semaphore_delete(vxd_work_queue->workq_sem_handle);
		vxd_work_queue->workq_sem_handle = NULL;
	}

	if(vxd_work_queue->queueMem)
	{
		osa_free(vxd_work_queue->queueMem);
		vxd_work_queue->queueMem = NULL;
	}
}

int32 MM_DEC_Init(void) {
	int32 ret;

	struct heap_config *heap_configs;
	int32 num_heaps, i;
	int32 i_heap_id;

	ret = osa_pm_set_module_state_decoder_on();
	if(0 != ret)
	{
		OSA_PR_ERR("%s: failed to power-on decoder hardware!\n", __func__);
		return ret;
	}

	vxd = osa_calloc(sizeof(*vxd), sizeof(uint8), 0);
	if (!vxd)
	{
		ret = osa_pm_set_module_state_decoder_off();
		return -OSA_ENOMEM;
	}

	vxd->dev = vxd;
	vxd->plat_dev = (struct platform_device *)vxd;

	vxd->reg_base = osa_get_decoder_base_reg_addr();

	heap_configs = vxd_dec_heap_configs;
	num_heaps = ARRAY_SIZE(vxd_dec_heap_configs);

	osa_mutex_create(&vxd->mutex);
	if (NULL == vxd->mutex) {
		osa_free(vxd);
		ret = osa_pm_set_module_state_decoder_off();
		return -OSA_ENOMEM;
	}

	ret = dec_reg_interrupt();
	if(OSA_STATUS_SOK != ret)
	{
		goto exit;
	}

	ret = dec_create_vxd_worker_task();
	if(OSA_STATUS_SOK != ret)
	{
		goto exit;
	}

	/* Read HW properties */
	ret = vxd_pvdec_get_props(NULL, vxd->reg_base, &vxd->props);
	if (ret) {
		OSA_PR_ERR("%s: failed to fetch core properties!\n", __func__);
		ret = -OSA_ENXIO;
		goto exit;
	}
	vxd->mmu_config_addr_width = VXD_EXTRN_ADDR_WIDTH(vxd->props);
	OSA_PR_INFO(
			"hw:%u.%u.%u, num_pix: %d, num_ent: %d, mmu: %d, MTX RAM: %d\n",
			VXD_MAJ_REV(vxd->props), VXD_MIN_REV(vxd->props),
			VXD_MAINT_REV(vxd->props), VXD_NUM_PIX_PIPES(vxd->props),
			VXD_NUM_ENT_PIPES(vxd->props), VXD_EXTRN_ADDR_WIDTH(vxd->props),
			vxd->props.mtx_ram_size);

	INIT_OSA_LIST_HEAD(&vxd->msgs);
	INIT_OSA_LIST_HEAD(&vxd->pend);

	/* initialize memory manager */
	ret = img_mem_init(vxd);
	if (ret) {
		OSA_PR_ERR("Failed to initialize memory\n");
		ret = -OSA_ENOMEM;
		goto exit;
	}

	osa_idr_init(&vxd->streams);
	if(NULL == vxd->streams)
	{
		OSA_PR_ERR("Failed to initialize idr\n");
		ret = -OSA_ENOMEM;
		goto out_init;
	}

	ret = vxd_init(NULL, vxd, heap_configs, num_heaps);
	if (ret) {
		OSA_PR_ERR("%s: main component initialization failed!\n",
				__func__);
		goto out_idr_init;
	}

	/* initialize core */
	i_heap_id = vxd_g_internal_heap_id();
	if (i_heap_id < 0) {
		OSA_PR_ERR("%s: Invalid internal heap id", __func__);
		goto out_vxd_init;
	}
	ret = core_initialise(vxd, i_heap_id, vxd_return_resource);
	if (ret) {
		OSA_PR_ERR("%s: core initialization failed!", __func__);
		goto out_vxd_init;
	}

	vxd->fw_refcnt = 0;
	vxd->hw_on = 0;
	vxd->hw_pm_delay = 1000;
	vxd->hw_dwr_period = 1000;

	ret = vxd_prepare_fw(vxd);
	if (ret) {
		OSA_PR_ERR("%s fw acquire failed!", __func__);
		goto out_core_init;
	}

	g_MM_DEC_Inst.mm_dev = vxd;
	for(i=0; i<MAX_NUM_CHANNELS; i++)
	{
		g_MM_DEC_Inst.ch_obj[i].ch_id = 0x7FFFFFFFU;
		g_MM_DEC_Inst.ch_obj[i].is_used = 0U;
	}

	return 0;

	out_core_init:
		core_deinitialise();

	out_vxd_init:
		vxd_deinit(vxd);

	out_idr_init:
		osa_idr_destroy(vxd->streams);

	out_init:
		img_mem_exit();

	exit:
		osa_mutex_destroy(&vxd->mutex);
		dec_release_interrupt_resource();
		dec_release_vxd_workqueue_resource();
		osa_free(vxd);
		osa_pm_set_module_state_decoder_off();
	return ret;
}

int32 MM_DEC_Deinit(void)
{
	core_deinitialise();
	vxd_clean_fw_resources(vxd);
	vxd_deinit(vxd);
	osa_idr_destroy(vxd->streams);
	osa_free(vxd->dwork);
	img_mem_exit();
	osa_mutex_destroy(&vxd->mutex);
	dec_release_interrupt_resource();
	dec_release_vxd_workqueue_resource();
	osa_free(vxd);
	osa_pm_set_module_state_decoder_off();
#ifdef DEBUG_OSA_MEM
	OSA_PR_ERR("##### At the end of MM_DEC_Deinit #####");
	osa_print_mem_leak();
#endif
	return 0;
}
