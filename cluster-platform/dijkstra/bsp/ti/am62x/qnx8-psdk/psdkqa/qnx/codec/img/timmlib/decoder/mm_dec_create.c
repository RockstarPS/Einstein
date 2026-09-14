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

#include <sys/neutrino.h>
#include <pthread.h>
#include "core.h"
#include "img_dec_common.h"
#include "vxd_pvdec_priv.h"
#include "vxd_dec.h"
#include "osal/inc/osa_mem.h"
#include "osal/inc/osa_idr.h"
#include "osal/inc/osa_err.h"
#include "osal/inc/osa_define.h"
#include "osal/inc/osa_page.h"
#include "osal/inc/osa_semaphore.h"
#include "osal/inc/osa_queue.h"
#include "osal/inc/osa_task.h"
#include "mm_dec_priv.h"
#include "mm_dec.h"

volatile int32 g_AssertFailLoop;

static int32 vxd_dec_s_fmt(struct mm_vxd_dec_fmt *pix_mp, uint32 chId)
{
	struct vxd_dec_ctx *ctx = g_MM_DEC_Inst.ch_obj[chId].mm_ctx;
	struct vxd_dec_q_data *q_data;
	struct vdec_str_configdata strcfgdata;
	int32 ret = 0;
	uint8 i = 0, j = 0;

	q_data = get_q_data(ctx, pix_mp->fmt->type);

	if (!q_data) {
		VDEC_ASSERT(0);
		return -OSA_EINVAL;
	}

	/*
	 * saving the orignal dimensions to pass to gstreamer (to remove the green
	 * padding on kmsink)
	 */
	ctx->width_orig = pix_mp->width;
	ctx->height_orig = pix_mp->height;

	ctx->width = pix_mp->width;
	ctx->height = ALIGN(pix_mp->height, HW_ALIGN);;

	q_data->width = pix_mp->width;
	q_data->height = ALIGN(pix_mp->height, HW_ALIGN);

	if (MM_TYPE_IS_OUTPUT((int)pix_mp->fmt->type)) {
		q_data->fmt = find_format(pix_mp, IMG_DEC_FMT_TYPE_OUTPUT);
		if(!q_data->fmt)
		{
			VDEC_ASSERT(0);
			return -OSA_EINVAL;
		}
		q_data->size_image[0] = pix_mp->sizeimage;

		if (!ctx->stream_created) {

			if ((q_data->fmt->std == VDEC_STD_UNDEFINED) || (q_data->fmt->std >= VDEC_STD_MAX)) {
				OSA_DEV_ERR(ctx->dev->dev, "Invalid input format\n");
				return -OSA_EINVAL;
			}

			strcfgdata.vid_std = q_data->fmt->std;

			strcfgdata.bstr_format = VDEC_BSTRFORMAT_ELEMENTARY;
			strcfgdata.user_str_id = ctx->stream.id;
			strcfgdata.update_yuv = osa_false;
			strcfgdata.bandwidth_efficient = osa_false;
			strcfgdata.disable_mvc = osa_false;
			strcfgdata.full_scan = osa_false;
			strcfgdata.immediate_decode = osa_true;
			strcfgdata.intra_frame_closed_gop = osa_true;

			ret = core_stream_create(ctx, &strcfgdata,
						 &ctx->res_str_id);
			if (ret) {
				OSA_DEV_ERR(ctx->dev->dev, "Core stream create failed\n");
				return -OSA_EINVAL;
			}
			ctx->stream_created = osa_true;
			if (ctx->opconfig_pending) {
				ret = vxd_dec_submit_opconfig(ctx);
				if (ret) {
					OSA_DEV_ERR(ctx->dev->dev, "Output config failed\n");
					return -OSA_EINVAL;
				}
			}

			vxd_dec_alloc_bspp_resource(ctx, strcfgdata.vid_std);
			ret = bspp_stream_create(&strcfgdata,
						 &ctx->bspp_context,
						 ctx->fw_sequ,
						 ctx->fw_pps);
			if (ret) {
				OSA_DEV_ERR(ctx->dev->dev, "BSPP stream create failed %d\n",
					ret);
				return ret;
			}
		} else if (q_data->fmt !=
				find_format(pix_mp, IMG_DEC_FMT_TYPE_OUTPUT)) {
			OSA_DEV_ERR(ctx->dev->dev, "Input format already set\n");
			return -OSA_EBUSY;
		}
	} else {
		q_data->fmt = find_format(pix_mp, IMG_DEC_FMT_TYPE_CAPTURE);
		if(!q_data->fmt)
		{
			VDEC_ASSERT(0);
			return -OSA_EINVAL;
		}
		for (i = 0; i < q_data->fmt->num_planes; i++) {
			q_data->size_image[i] =
				get_sizeimage(get_stride(pix_mp->width, q_data->fmt),
					      ctx->height, q_data->fmt);
		}

		ctx->str_opcfg.pixel_info.pixfmt = q_data->fmt->pixfmt;
		ctx->str_opcfg.pixel_info.chroma_interleave =
			q_data->fmt->interleave;
		ctx->str_opcfg.pixel_info.chroma_fmt = osa_true;
		ctx->str_opcfg.pixel_info.chroma_fmt_idc = q_data->fmt->idc;

		if (q_data->fmt->pixfmt == IMG_PIXFMT_420PL12YUV10_MSB ||
		    q_data->fmt->pixfmt == IMG_PIXFMT_422PL12YUV10_MSB) {
			ctx->str_opcfg.pixel_info.mem_pkg = PIXEL_BIT10_MSB_MP;
			ctx->str_opcfg.pixel_info.bitdepth_y = 10;
			ctx->str_opcfg.pixel_info.bitdepth_c = 10;
		} else {
			ctx->str_opcfg.pixel_info.mem_pkg = PIXEL_BIT8_MP;
			ctx->str_opcfg.pixel_info.bitdepth_y = 8;
			ctx->str_opcfg.pixel_info.bitdepth_c = 8;
		}

		ctx->str_opcfg.pixel_info.num_planes = 2;

		ctx->str_opcfg.force_oold = osa_false;

		ctx->pict_bufcfg.coded_width = pix_mp->width;
		ctx->pict_bufcfg.coded_height = pix_mp->height;
		ctx->pict_bufcfg.pixel_fmt = q_data->fmt->pixfmt;
		for (i = 0; i < pix_mp->fmt->num_planes; i++) {
			q_data->bytesperline[i] = get_stride(q_data->width,
							     q_data->fmt);
			if (q_data->bytesperline[i] <
					pix_mp->bytesperline)
				q_data->bytesperline[i] =
					ALIGN(pix_mp->bytesperline,
					      HW_ALIGN);
			pix_mp->bytesperline =
				q_data->bytesperline[i];
			ctx->pict_bufcfg.stride[i] = q_data->bytesperline[i];
		}
		for (j = i; j < IMG_MAX_NUM_PLANES; j++) {
			if ((i - 1) < 0)
				i++;
			ctx->pict_bufcfg.stride[j] =
				q_data->bytesperline[i - 1];
		}
		ctx->pict_bufcfg.stride_alignment = HW_ALIGN;
		ctx->pict_bufcfg.byte_interleave = osa_false;
		for (i = 0; i < pix_mp->fmt->num_planes; i++) {
			ctx->pict_bufcfg.buf_size += get_sizeimage(
					ctx->pict_bufcfg.stride[i],
					ALIGN(ctx->pict_bufcfg.coded_height, HW_ALIGN),
					q_data->fmt);
		}
		pix_mp->sizeimage = ctx->pict_bufcfg.buf_size;
		ctx->pict_bufcfg.packed = osa_true;
		ctx->pict_bufcfg.chroma_offset[0] = 0;
		ctx->pict_bufcfg.chroma_offset[1] = 0;

		vxd_dec_submit_opconfig(ctx);
	}

	return ret;
}

int32_t MM_DEC_BufPrepare(struct mm_buffer *buffer, uint32_t chId)
{
	struct vxd_dec_ctx *ctx = NULL;
	mm_vxd_buff *mm_buf = NULL;
	struct vxd_dec_q_data *q_data;
	int32 plane, num_planes, ret = 0;
	struct vxd_buffer *buf;
	struct sg_table sgt = {0};
	struct scatterlist sgl[MAX_PLANES + 1] = {0};
	struct page page[MAX_PLANES] = {0};
	struct vxd_buffer *vxd_buf;
	ulong aligned = 0x0FFF;

	if (chId >= MAX_NUM_CHANNELS)
	{
		OSA_PR_ERR("%s Wrong chId passed by App.!!!", __func__);
		return -OSA_EFAULT;
	}

	ctx = g_MM_DEC_Inst.ch_obj[chId].mm_ctx;
	mm_buf = g_MM_DEC_Inst.ch_obj[chId].mm_buf;

	if (buffer->chId != chId)
	{
		buffer->chId = chId;
		OSA_PR_ERR("%s buffer->chId is not set correctly, resetting here!!", __func__);
	}

	vxd_buf = vxd_get_buf(buffer, chId);
	if (vxd_buf != NULL)
	{
		OSA_PR_INFO("%s:This buffer is already mapped\n",__func__);
		return 0;
	}

	if (mm_buf->vxd_buf_index >= MAX_NUM_VXD_BUFFER_PER_CH)
	{
		OSA_PR_ERR("%s: Num buffers supported per ch exceeds the Max (%d) \n"
			,__func__, MAX_NUM_VXD_BUFFER_PER_CH);
		return -OSA_EINVAL;
	}

	buf = osa_zalloc(sizeof(*buf), OSA_GFP_KERNEL);
	if (!buf) {
		return -OSA_ENOMEM;
	}

	buf->buffer = buffer;

	q_data = get_q_data(ctx, buf->buffer->type);
	if (!q_data)
		return -OSA_EINVAL;

	num_planes = q_data->fmt->num_planes;

	for (plane = 0; plane < num_planes; plane++) {
		if (buf->buffer->size[plane] < q_data->size_image[plane]) {
			OSA_DEV_ERR(ctx->dev->dev, "data will not fit into plane (%lu < %lu)\n",
				buf->buffer->size[plane],
				(slong)q_data->size_image[plane]);
			return -OSA_EINVAL;
		}
	}

	if (buf->mapped)
		return 0;

	buf->buf_info.cpu_linear_addr = buf->buffer->buf_addr[0];
	buf->buf_info.buf_size = buf->buffer->size[0];
	buf->buf_info.fd = -1;

	sgt.sgl = &sgl[0];
	sgt.nents = 1;
	sgl[0].dma_address = buf->buffer->buf_addr[0];
	sgl[0].length = buf->buffer->size[0];
	page[0].sgt = &sgt;
	osa_sg_set_page(&sgl[0], &page[0], OSA_PAGE_SIZE, 0);


	if (MM_TYPE_IS_OUTPUT((int)buf->buffer->type)) {

		if(((ulong)(sgl[0].dma_address) & aligned) != 0)
		{
			OSA_DEV_ERR(ctx->dev->dev, "The given buffer=%p is not aligned with %d\n", sgl[0].dma_address, OSA_PAGE_SIZE);
			return OSA_EINVAL;
		}
		ret = core_stream_map_buf_sg(ctx->res_str_id,
					     VDEC_BUFTYPE_BITSTREAM,
					     &buf->buf_info, &sgt,
					     &buf->buf_map_id);
		if (ret) {
			OSA_DEV_ERR(ctx->dev->dev, "OUTPUT core_stream_map_buf_sg failed\n");
			return ret;
		}

		buf->bstr_info.buf_size = q_data->size_image[0];
		buf->bstr_info.cpu_virt_addr = buf->buf_info.cpu_linear_addr;
		buf->bstr_info.mem_attrib =
			(enum sys_emem_attrib)(SYS_MEMATTRIB_UNCACHED | SYS_MEMATTRIB_WRITECOMBINE |
			SYS_MEMATTRIB_INPUT | SYS_MEMATTRIB_CPU_WRITE);
		buf->bstr_info.bufmap_id = buf->buf_map_id;
		lst_init(&buf->seq_unit.bstr_seg_list);
		lst_init(&buf->pic_unit.bstr_seg_list);
		lst_init(&buf->end_unit.bstr_seg_list);

		osa_list_add_tail(&buf->list, &ctx->out_buffers);
	} else {

		for (plane = 1; plane < num_planes; plane++) {
			buf->buf_info.buf_size += buf->buffer->size[plane];
			sgt.nents += 1;
			sgl[plane].dma_address = buf->buffer->buf_addr[plane];
			sgl[plane].length = buf->buffer->size[plane];
			page[plane].sgt = &sgt;
			osa_sg_set_page(&sgl[plane], &page[plane], OSA_PAGE_SIZE, 0);
			if(((ulong)(sgl[plane].dma_address) & aligned) != 0)
			{
				OSA_DEV_ERR(ctx->dev->dev, "The given buffer=%p is not aligned with %d\n", sgl[plane].dma_address, OSA_PAGE_SIZE);
				return OSA_EINVAL;
			}
		}

		buf->buf_info.pictbuf_cfg = ctx->pict_bufcfg;
		ret = core_stream_map_buf_sg(ctx->res_str_id,
					     VDEC_BUFTYPE_PICTURE,
					     &buf->buf_info, &sgt,
					     &buf->buf_map_id);
		if (ret) {
			OSA_DEV_ERR(ctx->dev->dev, "CAPTURE core_stream_map_buf_sg failed\n");
			return ret;
		}
		osa_list_add_tail(&buf->list, &ctx->cap_buffers);
	}
	buf->mapped = osa_true;
	buf->reuse = osa_true;
	mm_buf->vxd_buf[mm_buf->vxd_buf_index] = buf;
	mm_buf->vxd_buf_index++;

	return 0;
}

/* This function is going to creating stream work-queue resource */
static void dec_release_stream_workqueue_resource(uint32 chId)
{
	mm_work_queue_handle *stream_work_queue = &g_MM_DEC_Inst.ch_obj[chId].stream_work_queue_handle;

	if(stream_work_queue->workq_task_handle)
	{
		osa_task_delete(stream_work_queue->workq_task_handle);
		stream_work_queue->workq_task_handle = NULL;
	}

	if(stream_work_queue->queue_handle)
	{
		osa_utils_quedelete(stream_work_queue->queue_handle);
		osa_free(stream_work_queue->queue_handle);
		stream_work_queue->queue_handle = NULL;
	}

	if(stream_work_queue->workq_sem_handle)
	{
		osa_semaphore_delete(stream_work_queue->workq_sem_handle);
		stream_work_queue->workq_sem_handle = NULL;
	}

	if(stream_work_queue->queueMem)
	{
		osa_free(stream_work_queue->queueMem);
		stream_work_queue->queueMem = NULL;
	}

}

static void stream_workqueue_Task(void *arg0, void *arg1)
{
    mm_work_queue_handle *stream_work_queue = (mm_work_queue_handle *)arg0;
	void *queue_handle = stream_work_queue->queue_handle;
	void *sem_handle = stream_work_queue->workq_sem_handle;
	struct work_struct *pBuf = NULL;

	pthread_setname_np(pthread_self(),"stream work task");
	if(ThreadCtl( _NTO_TCTL_IO_LEVEL, (void*)_NTO_IO_LEVEL_1 ) == -1) {
		OSA_PR_ERR("%s: Failed to set _NTO_TCTL_IO_LEVEL!", __func__);
	}
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
				osa_mutex_lock(pBuf->lock);
				pBuf->worker_func(pBuf->work);
				osa_mutex_unlock(pBuf->lock);
			}
		}
		pBuf = NULL;
	}
}

/* This function is going to creating stream work-queue */
static int dec_create_stream_worker_task(struct vxd_dec_ctx *ctx, uint32 chId)
{
	task_params params = {0};
	mm_work_queue_handle *stream_work_queue = &g_MM_DEC_Inst.ch_obj[chId].stream_work_queue_handle;

	/* Stream worker creation */
	stream_work_queue->queue_handle = osa_malloc(sizeof(osa_utils_quehandle), 0);
	if(NULL == stream_work_queue->queue_handle)
	{
		OSA_PR_ERR("%s: Failed to allocate memory for Queue!", __func__);
		return OSA_STATUS_EFAIL;
	}

	stream_work_queue->queueMem = osa_calloc(WORK_MAX_QUEUE_ELEMENTS, sizeof(void *), 0);
	if(NULL == stream_work_queue->queueMem)
	{
		OSA_PR_ERR("%s: Failed to allocate memory for holding Queue elements!", __func__);
		return OSA_STATUS_EFAIL;
	}

	osa_utils_quecreate(stream_work_queue->queue_handle,
			WORK_MAX_QUEUE_ELEMENTS,
			stream_work_queue->queueMem,
			OSA_UTILS_QUE_FLAG_BLOCK_QUE);

	stream_work_queue->workq_sem_handle = osa_semaphore_create(osa_semaphore_mode_binary, 0);
	if(NULL == stream_work_queue->workq_sem_handle)
	{
		OSA_PR_ERR("%s: Semaphore creation failed for WorkQueue!", __func__);
		return OSA_STATUS_EFAIL;
	}

	params.arg0 = stream_work_queue;
	params.priority = OSA_STREAM_WORKER_TASK_PRIORITY;
	stream_work_queue->workq_task_handle = osa_task_create(stream_workqueue_Task, &params);
	if(NULL == stream_work_queue->workq_task_handle)
	{
		OSA_PR_ERR("%s: Creating task for WorkQueue is failed!", __func__);
		return OSA_STATUS_EFAIL;
	}

	ctx->stream_worker_queue_handle = stream_work_queue->queue_handle;
	ctx->stream_worker_queue_sem_handle = stream_work_queue->workq_sem_handle;

	return OSA_STATUS_SOK;
}

int32_t MM_DEC_Create(mm_vid_create_params *params, mm_dec_ctrl_params *ctrl, uint32_t *ch_Id)
{
	struct vxd_dev *vxd = g_MM_DEC_Inst.mm_dev;
	struct vxd_dec_ctx *ctx;
	mm_vxd_buff *mm_buf;
	struct vxd_dec_q_data *s_q_data;
	struct mm_vxd_dec_fmt pix_mp;
	int32 i, ret = 0;
	uint32_t chId;

	*ch_Id = 0x7FFFFFFFU;

	osa_mutex_lock(vxd->mutex);

	for(i=0; i<MAX_NUM_CHANNELS; i++)
	{
		if ((0 == g_MM_DEC_Inst.ch_obj[i].is_used) &&
			(0x7FFFFFFFU == g_MM_DEC_Inst.ch_obj[i].ch_id))
		{
			g_MM_DEC_Inst.ch_obj[i].ch_id = i;
			g_MM_DEC_Inst.ch_obj[i].is_used = 1U;
			*ch_Id = i;
			break;
		}
	}
	chId = *ch_Id;
	if (chId >= MAX_NUM_CHANNELS)
	{
		OSA_PR_ERR("%s Error in allocating chId!!!", __func__);
		return -OSA_EFAULT;
	}

	memcpy(&g_MM_DEC_Inst.ch_obj[chId].create_prms, params, sizeof(mm_vid_create_params));
	OSA_DEV_DBG(vxd->dev, "%s:%d vxd %p\n", __func__, __LINE__, vxd);

	ctx = osa_zalloc(sizeof(*ctx), OSA_GFP_KERNEL);
	if (!ctx) {
		osa_mutex_unlock(vxd->mutex);
		return -OSA_ENOMEM;
	}

	mm_buf = osa_zalloc(sizeof(*mm_buf), OSA_GFP_KERNEL);
	if (!mm_buf) {
		osa_free(ctx);
		osa_mutex_unlock(vxd->mutex);
		return -OSA_ENOMEM;
	}

	ctx->dev = vxd;
	g_MM_DEC_Inst.ch_obj[chId].mm_ctx = ctx;
	g_MM_DEC_Inst.ch_obj[chId].mm_buf = mm_buf;
	mm_buf->vxd_buf_index = 0;

	osa_mutex_create(&ctx->lock);
	if(NULL == ctx->lock)
	{
		osa_free(ctx);
		osa_free(mm_buf);
		osa_mutex_unlock(vxd->mutex);
		return -OSA_ENOMEM;
	}

	ret = dec_create_stream_worker_task(ctx, chId);
	if(OSA_STATUS_SOK != ret) {
		osa_free(mm_buf);
		dec_release_stream_workqueue_resource(chId);
		osa_mutex_destroy(&ctx->lock);
		osa_free(ctx);
		osa_mutex_unlock(vxd->mutex);
		return ret;
	}

	s_q_data = &ctx->q_data[Q_DATA_SRC];
	s_q_data->fmt = &vxd_dec_formats[params->out_pixelformat -1];
	s_q_data->width = params->width;
	s_q_data->height = params->height;
	for (i = 0; i < s_q_data->fmt->num_planes; i++) {
		s_q_data->bytesperline[i] = s_q_data->width * s_q_data->fmt->bytes_pp;
		s_q_data->size_image[i] = s_q_data->bytesperline[i] * s_q_data->height;
	}

	ctx->q_data[Q_DATA_DST] = *s_q_data;

	ret = osa_idr_alloc_cyclic(vxd->streams, &ctx->stream, VXD_MIN_STREAM_ID,
			       VXD_MAX_STREAM_ID);
	if (ret < VXD_MIN_STREAM_ID || ret > VXD_MAX_STREAM_ID) {
		OSA_DEV_ERR(vxd->dev, "%s: stream id creation failed!\n",
			__func__);
		ret = -OSA_EFAULT;
		goto exit;
	}

	ctx->stream.id = ret;
	ctx->stream.ctx = ctx;

	ctx->stream_created = osa_false;
	ctx->stream_configured = osa_false;
	ctx->src_streaming = osa_false;
	ctx->dst_streaming = osa_false;
	ctx->core_streaming = osa_false;
	ctx->eos = osa_false;
	ctx->stop_initiated = osa_false;
	ctx->flag_last = osa_false;

	lst_init(&ctx->seg_list);
	for (i = 0; i < MAX_SEGMENTS; i++)
		lst_add(&ctx->seg_list, &ctx->bstr_segments[i]);

	if (vxd_create_ctx(vxd, ctx))
		goto out_idr_remove;

	ctx->stream.mmu_ctx = ctx->mmu_ctx;
	ctx->stream.ptd = ctx->ptd;

	osa_mutex_create(&ctx->mutex);
	if(NULL == ctx->mutex)
	{
		ret = -OSA_ENOMEM;
		goto out_idr_remove;
	}

	INIT_OSA_LIST_HEAD(&ctx->items_done);
	INIT_OSA_LIST_HEAD(&ctx->reuse_queue);
	INIT_OSA_LIST_HEAD(&ctx->return_queue);
	INIT_OSA_LIST_HEAD(&ctx->out_buffers);
	INIT_OSA_LIST_HEAD(&ctx->cap_buffers);

	osa_mutex_unlock(vxd->mutex);

	if (params->in_pixelformat == MM_PIX_FMT_H264 || params->in_pixelformat == MM_PIX_FMT_HEVC)
	{
		pix_mp.width = params->width;
		pix_mp.height = params->height;
		pix_mp.pixelformat = params->in_pixelformat;
		pix_mp.fmt = &vxd_dec_formats[params->in_pixelformat - 1];
		pix_mp.bytesperline = pix_mp.width * pix_mp.fmt->bytes_pp;
		pix_mp.sizeimage = pix_mp.bytesperline * pix_mp.height;
		ret = vxd_dec_s_fmt(&pix_mp, chId);
	}
	else
	{
		OSA_DEV_ERR(vxd->dev, "%s: Invalid in_pixelformat params!\n", __func__);
		ret = -OSA_EINVAL;
		goto out_idr_remove;
	}

	if ((params->out_pixelformat == MM_PIX_FMT_NV12)  ||
		(params->out_pixelformat == MM_PIX_FMT_NV12M) ||
		(params->out_pixelformat == MM_PIX_FMT_NV16)  ||
		(params->out_pixelformat == MM_PIX_FMT_YUV422P)  ||
		(params->out_pixelformat == MM_PIX_FMT_TI1210)||
		(params->out_pixelformat == MM_PIX_FMT_TI1610)||
		(params->out_pixelformat == MM_PIX_FMT_TI1210M))
	{
		pix_mp.width = params->width;
		pix_mp.height = params->height;
		pix_mp.pixelformat = params->out_pixelformat;
		pix_mp.fmt = &vxd_dec_formats[params->out_pixelformat -1];
		pix_mp.bytesperline = pix_mp.width * pix_mp.fmt->bytes_pp;
		pix_mp.sizeimage = pix_mp.bytesperline * pix_mp.height;
		ret = vxd_dec_s_fmt(&pix_mp, chId);
	}
	else
	{
		OSA_DEV_ERR(vxd->dev, "%s: Invalid out_pixelformat params!\n", __func__);
		ret = -OSA_EINVAL;
		goto out_idr_remove;
	}

	ctx->sem_eos = osa_semaphore_create(osa_semaphore_mode_binary, 0);
	if(NULL == ctx->sem_eos)
	{
		ret = -OSA_ENOMEM;
		goto out_idr_remove;
	}

	return ret;

out_idr_remove:
	osa_idr_remove(vxd->streams, ctx->stream.id);

exit:
	osa_get_work_buff(ctx->work, TRUE);
	osa_free(ctx->work);
	osa_free(ctx);
	osa_free(mm_buf);
	dec_release_stream_workqueue_resource(chId);
	osa_mutex_unlock(vxd->mutex);
	return ret;
}

int32_t MM_DEC_Destroy(uint32_t chId)
{
	struct vxd_dec_ctx *ctx;
	mm_vxd_buff *mm_buf;
	struct vxd_dev *vxd;
	struct bspp_ddbuf_array_info *fw_sequ;
	struct bspp_ddbuf_array_info *fw_pps;
	int32 i, ret = 0;
	struct vxd_dec_q_data *s_q_data;

	if (chId >= MAX_NUM_CHANNELS)
	{
		OSA_PR_ERR("%s Wrong chId passed by App.!!!", __func__);
		return -OSA_EFAULT;
	}

	ctx = g_MM_DEC_Inst.ch_obj[chId].mm_ctx;
	mm_buf = g_MM_DEC_Inst.ch_obj[chId].mm_buf;
	vxd = ctx->dev;
	fw_sequ = ctx->fw_sequ;
	fw_pps = ctx->fw_pps;

	s_q_data = &ctx->q_data[Q_DATA_SRC];

	if (ctx->stream_created) {
		bspp_stream_destroy(ctx->bspp_context);

		for (i = 0 ; i < MAX_SEQUENCES ; i++) {
			core_stream_unmap_buf(fw_sequ[i].ddbuf_info.bufmap_id);
			img_mem_free(ctx->mem_ctx,
				     fw_sequ[i].ddbuf_info.buf_id);
		}

		if(s_q_data->fmt->std != VDEC_STD_JPEG) {
		for (i = 0; i < MAX_PPSS; i++) {
			core_stream_unmap_buf(fw_pps[i].ddbuf_info.bufmap_id);
			img_mem_free(ctx->mem_ctx,
				     fw_pps[i].ddbuf_info.buf_id);
		}
		}
		core_stream_destroy(ctx->res_str_id);
		ctx->stream_created = osa_false;
	}

	osa_mutex_lock(vxd->mutex);

	vxd_destroy_ctx(vxd, ctx);

	osa_idr_remove(vxd->streams, ctx->stream.id);

	osa_mutex_destroy(&ctx->lock);

	osa_mutex_destroy(&ctx->mutex);

	osa_get_work_buff(ctx->work, TRUE);
	osa_free(ctx->work);

	for(i=0; i<mm_buf->vxd_buf_index; i++)
	{
		osa_free(mm_buf->vxd_buf[i]);
	}
	mm_buf->vxd_buf_index = 0;
	g_MM_DEC_Inst.ch_obj[chId].ch_id = 0x7FFFFFFFU;
	g_MM_DEC_Inst.ch_obj[chId].is_used = 0U;

	osa_free(mm_buf);
	dec_release_stream_workqueue_resource(chId);
	osa_semaphore_delete(ctx->sem_eos);
	osa_free(ctx);
	osa_mutex_unlock(vxd->mutex);

#ifdef DEBUG_OSA_MEM
	OSA_PR_ERR("##### At the end of MM_DEC_Destroy #####");
	osa_print_mem_leak();
#endif
	return ret;
}

void vxd_dec_return_all_buffers(struct vxd_dec_ctx *ctx)
{
/*
	struct vxd_buffer *buf;
	int32 i;

	for (;;) {
		buf = ctx->vxd_buf[i++];
		if (!buf)
			break;
		osa_list_del(&buf->list);
	}
*/
}

int32_t MM_DEC_StartStreaming(uint32_t chId, mm_buffertype type)
{
	int32 ret = 0;
	struct vxd_dec_ctx *ctx;

	if (chId >= MAX_NUM_CHANNELS)
	{
		OSA_PR_ERR("%s Wrong chId passed by App.!!!", __func__);
		return -OSA_EFAULT;
	}

	ctx = g_MM_DEC_Inst.ch_obj[chId].mm_ctx;

	if (MM_TYPE_IS_OUTPUT((int)type))
		ctx->dst_streaming = osa_true;
	else
		ctx->src_streaming = osa_true;

	if (ctx->dst_streaming && ctx->src_streaming && !ctx->core_streaming) {
		if (!ctx->stream_configured) {
			vxd_dec_return_all_buffers(ctx);
			return -OSA_EINVAL;
		}
		ret = core_stream_play(ctx->res_str_id);
		if (ret) {
			vxd_dec_return_all_buffers(ctx);
			return ret;
		}
		ctx->core_streaming = osa_true;
	}

	return 0;
}

int32_t MM_DEC_StopStreaming(uint32_t chId, mm_buffertype type)
{
	struct vxd_dec_ctx *ctx;

	struct clist_head *list;
	struct clist_head *temp;
	struct vxd_buffer *buf = NULL;

	if (chId >= MAX_NUM_CHANNELS)
	{
		OSA_PR_ERR("%s Wrong chId passed by App.!!!", __func__);
		return -OSA_EFAULT;
	}

	ctx = g_MM_DEC_Inst.ch_obj[chId].mm_ctx;

	if (ctx->num_decoding) {
		OSA_PR_INFO("buffers are still being decoded, so waiting for complete!\n");
		ctx->stop_initiated = osa_true;
		osa_semaphore_pend(ctx->sem_eos, 3000);
		vxd_return_resource((void *)ctx, VXD_CB_STR_END, 0);
	} else {
		if(osa_true != ctx->stop_initiated)
		{
			ctx->stop_initiated = osa_true;
			OSA_PR_INFO("All buffers are decoded\n");
			vxd_return_resource((void *)ctx, VXD_CB_STR_END, 0);
		}
	}

	if (MM_TYPE_IS_OUTPUT((int)type))
		ctx->dst_streaming = osa_false;
	else
		ctx->src_streaming = osa_false;

	if (ctx->core_streaming) {
		core_stream_stop(ctx->res_str_id);
		ctx->core_streaming = osa_false;

		core_stream_flush(ctx->res_str_id, osa_true);
	}

	if (MM_TYPE_IS_OUTPUT((int)type)) {
		osa_list_for_each(list, &ctx->out_buffers) {
			buf = osa_list_entry(list, struct vxd_buffer, list);
			core_stream_unmap_buf_sg(buf->buf_map_id);
		}
	} else {
		osa_list_for_each_safe(list, temp, &ctx->reuse_queue) {
			buf = osa_list_entry(list, struct vxd_buffer, list);
			osa_list_move_tail(&buf->list, &ctx->cap_buffers);
		}

		osa_list_for_each(list, &ctx->cap_buffers) {
			buf = osa_list_entry(list, struct vxd_buffer, list);
			core_stream_unmap_buf_sg(buf->buf_map_id);
		}
	}

	vxd_dec_return_all_buffers(ctx);

	return 0;
}
