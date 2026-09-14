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

#include "topaz_api.h"
#include "osal/inc/osa_mem.h"
#include "osal/inc/osa_idr.h"
#include "osal/inc/osa_err.h"
#include "osal/inc/osa_define.h"
#include "osal/inc/osa_page.h"
#include "osal/inc/osa_semaphore.h"
#include "osal/inc/osa_queue.h"
#include "osal/inc/osa_task.h"
#include "osal/inc/osa_types.h"
#include "osal/inc/osa_mutex.h"
#include "osal/inc/osa_workqueue.h"
#include "mm_enc_priv.h"
#include "mm_enc.h"

#define MAX(a, b, type) ({ \
		type __a = a; \
		type __b = b; \
		(((__a) >= (__b)) ? (__a) : (__b)); })

volatile int32 g_AssertFailLoop;

static int32 vxe_enc_s_parm(mm_enc_ctrl_params *parm, uint32 chId)
{
	struct vxe_enc_ctx *ctx = g_MM_ENC_Inst.ch_obj[chId].mm_ctx;

		/* Bitflags for encoding features */
	if (parm->features & MM_ENC_FEATURE_CABAC)
		ctx->vparams.cabac_enabled = osa_true;
	else
		ctx->vparams.cabac_enabled = osa_false;

	if (parm->features & MM_ENC_FEATURE_8x8)
		ctx->vparams.h264_8x8 = osa_true;
	else
		ctx->vparams.h264_8x8 = osa_false;

	if (parm->features & MM_ENC_FEATURE_DISABLE_INTRA4x4)
		ctx->vparams.enc_features.disable_intra4x4 = osa_true;
	else
		ctx->vparams.enc_features.disable_intra4x4 = osa_false;

	if (parm->features & MM_ENC_FEATURE_DISABLE_INTRA8x8)
		ctx->vparams.enc_features.disable_intra8x8 = osa_true;
	else
		ctx->vparams.enc_features.disable_intra8x8 = osa_false;

	if (parm->features & MM_ENC_FEATURE_DISABLE_INTRA16x16)
		ctx->vparams.enc_features.disable_intra16x16 = osa_true;
	else
		ctx->vparams.enc_features.disable_intra16x16 = osa_false;

	if (parm->features & MM_ENC_FEATURE_DISABLE_INTER8x8)
		ctx->vparams.enc_features.disable_inter8x8 = osa_true;
	else
		ctx->vparams.enc_features.disable_inter8x8 = osa_false;

	if (parm->features & MM_ENC_FEATURE_RESTRICT_INTER4x4)
		ctx->vparams.enc_features.restrict_inter4x4 = osa_true;
	else
		ctx->vparams.enc_features.restrict_inter4x4 = osa_false;

	if (parm->features & MM_ENC_FEATURE_DISABLE_8x16_MV_DETECT)
		ctx->vparams.enc_features.enable_8x16_mv_detect = osa_false;
	else
		ctx->vparams.enc_features.enable_8x16_mv_detect = osa_true;

	if (parm->features & MM_ENC_FEATURE_DISABLE_16x8_MV_DETECT)
		ctx->vparams.enc_features.enable_16x8_mv_detect = osa_false;
	else
		ctx->vparams.enc_features.enable_16x8_mv_detect = osa_true;

	/* Set RC Mode */
	switch (parm->rcmode)
	{
		case MM_ENC_VBR:
			ctx->rc.rc_mode = IMG_RCMODE_VBR;
			ctx->vparams.disable_bit_stuffing = osa_true;
			break;
		case MM_ENC_SVBR:
			ctx->rc.rc_mode = IMG_RCMODE_CBR;
			ctx->vparams.disable_bit_stuffing = osa_true;
			break;
		default:
			OSA_PR_ERR("%s: Invalid RC Mode from App\n", __func__);
			return -1;
	}

	/* Set IDR and I periods */
	ctx->vparams.idr_period = parm->idr_period;
	ctx->rc.intra_freq = parm->i_period;
	ctx->vparams.intra_cnt = parm->i_period;

	/* Set Bitrate */
	ctx->rc.bits_per_second = parm->bitrate; /* 10mbps */
	ctx->rc.transfer_bits_per_second = ctx->rc.bits_per_second;
	ctx->rc.frame_rate = parm->framerate;

	/* Set crop */
	if (parm->crop_left || parm->crop_right ||
		parm->crop_top || parm->crop_bottom)
		ctx->crop_params.clip = osa_true;
	else
		ctx->crop_params.clip = osa_false;

	ctx->crop_params.left_crop_offset = parm->crop_left / 2;
	ctx->crop_params.right_crop_offset = parm->crop_right / 2;
	ctx->crop_params.top_crop_offset = parm->crop_top / 2;
	ctx->crop_params.bottom_crop_offset = parm->crop_bottom / 2;

	/* Set slices */
	if (parm->nslices > MAX_SLICES_PER_PICTURE) {
		OSA_PR_ERR("%s: App selected %d slices, greater than Max %d\n",
				   __func__, parm->nslices, MAX_SLICES_PER_PICTURE);
		return -1;
	} else {
		ctx->vparams.slices_per_picture = parm->nslices;
	}

	/* Initial QP I/P/B */
	ctx->rc.initial_qp_i = parm->initial_qp_i;
	ctx->rc.initial_qp_p = parm->initial_qp_p;
	ctx->rc.initial_qp_b = parm->initial_qp_b;

	/* Min/Max Qp */
	ctx->rc.min_qp = parm->min_qp;
	ctx->rc.max_qp = parm->max_qp;

	/* Min Block Size */
	switch (parm->min_blk_size)
	{
		case MM_ENC_BLK_SZ_DEFAULT:
			ctx->vparams.enc_features.min_blk_sz = BLK_SZ_DEFAULT;
			break;
		case MM_ENC_BLK_SZ_16x16:
			ctx->vparams.enc_features.min_blk_sz = BLK_SZ_16x16;
			break;
		case MM_ENC_BLK_SZ_8x8:
			ctx->vparams.enc_features.min_blk_sz = BLK_SZ_8x8;
			break;
		case MM_ENC_BLK_SZ_4x4:
			ctx->vparams.enc_features.min_blk_sz = BLK_SZ_4x4;
			break;
		default:
			OSA_PR_ERR("%s: Invalid Min Block Size from App\n", __func__);
			return -1;
	}

	/* Intra Pred Modes */
	ctx->vparams.intra_pred_modes = parm->intra_pred_modes;

	return 0;
}

static int32 vxe_enc_s_fmt(struct mm_vxe_enc_fmt *pix_mp, uint32 chId)
{
	struct vxe_enc_ctx *ctx = g_MM_ENC_Inst.ch_obj[chId].mm_ctx;
	struct vxe_enc_q_data *queue;
	uint8 i = 0;
	uint32 bits_per_frm;
	uint32 level_h264;

	queue = vxe_get_q_data(ctx, pix_mp->fmt->type);

	if (!queue)
		return -OSA_EINVAL;

	queue->width = pix_mp->width;
	queue->height = pix_mp->height;
	queue->fmt = pix_mp->fmt;

	if (MM_TYPE_IS_OUTPUT(pix_mp->fmt->type)) {
		ctx->vparams.format = pix_mp->fmt->fmt;
		ctx->vparams.source_width = pix_mp->width;
		ctx->vparams.source_frame_height = pix_mp->height;
		ctx->vparams.csc_preset = pix_mp->fmt->csc_preset;
		if (ctx->vparams.csc_preset != IMG_CSC_NONE)
			ctx->vparams.enable_scaler = osa_true;

		OSA_PR_DEBUG("img_video_params: format=%d\n", ctx->vparams.format);
		OSA_PR_DEBUG("img_video_params: source_width=%d\n", ctx->vparams.source_width);
		OSA_PR_DEBUG("img_video_params: source_frame_height=%d\n", ctx->vparams.source_frame_height);
		OSA_PR_DEBUG("img_video_params: csc_preset=%d\n", ctx->vparams.csc_preset);
		OSA_PR_DEBUG("img_video_params: enable_scaler=%s\n", ctx->vparams.enable_scaler ? "true" : "false");

		for (i = 0; i < pix_mp->fmt->num_planes; i++) {
			queue->bytesperline[i] = vxe_get_stride(queue->width, pix_mp->fmt);

			queue->size_image[i] = vxe_get_sizeimage(pix_mp->bytesperline, queue->height, pix_mp->fmt, i);

		}

		ctx->rc.bu_size = 0;
		ctx->rc.buffer_size = ctx->rc.transfer_bits_per_second;

		bits_per_frm = (ctx->rc.bits_per_second + ctx->rc.frame_rate / 2) / ctx->rc.frame_rate;
		ctx->rc.initial_level = (3 * ctx->rc.buffer_size) >> 4;
		ctx->rc.initial_level = ((ctx->rc.initial_level + (bits_per_frm / 2)) / bits_per_frm) * bits_per_frm;
		ctx->rc.initial_level = MAX((uint32)ctx->rc.initial_level,
					    (uint32)bits_per_frm, uint32);
		ctx->rc.initial_delay = ctx->rc.buffer_size - ctx->rc.initial_level;
		ctx->rc.bframes = 0;

		OSA_PR_DEBUG("img_rc_params: initial_level=%d\n", ctx->rc.initial_level);
		OSA_PR_DEBUG("img_rc_params: initial_delay=%d\n", ctx->rc.initial_delay);

		ctx->sh_params.profile = find_h264_profile(osa_false, /* TODO Figure out which lossless to use */
							   ctx->vparams.use_default_scaling_list,
							   osa_false,
							   ctx->vparams.h264_8x8,
							   ctx->vparams.enable_mvc,
							   ctx->rc.bframes,
							   ctx->vparams.is_interlaced,
							   ctx->vparams.cabac_enabled,
							   ctx->vparams.weighted_prediction,
							   ctx->vparams.vp_weighted_implicit_bi_pred);
		ctx->sh_params.max_num_ref_frames = 1; //TODO Need more logic

		level_h264 = calculate_h264_level(pix_mp->width, pix_mp->height,
						  ctx->rc.frame_rate,
						  ctx->rc.rc_enable,
						  ctx->rc.bits_per_second,
						  osa_false, /* TODO Figure out which lossless to use */
						  ctx->sh_params.profile,
						  ctx->sh_params.max_num_ref_frames);
		OSA_PR_DEBUG("level_h264=%d\n", level_h264);

		ctx->vparams.vert_mv_limit = 255;
		if (level_h264 >= 110)
			ctx->vparams.vert_mv_limit = 511;
		if (level_h264 >= 210)
			ctx->vparams.vert_mv_limit = 1023;
		if (level_h264 >= 310)
			ctx->vparams.vert_mv_limit = 2047;

		if (level_h264 >= 300)
			ctx->vparams.limit_num_vectors = osa_true;
		else
			ctx->vparams.limit_num_vectors = osa_false;

		OSA_PR_DEBUG("ctx->vparams.vert_mv_limit=%d\n", ctx->vparams.vert_mv_limit);
		OSA_PR_DEBUG("ctx->vparams.limit_num_vectors=%d\n", ctx->vparams.limit_num_vectors);

		/* VUI parameters */
		ctx->vui_params.time_scale = ctx->rc.frame_rate * 2;
		ctx->vui_params.bit_rate_value_minus1 = (ctx->rc.bits_per_second / 64)
							- 1;
		ctx->vui_params.cbp_size_value_minus1 = (ctx->rc.buffer_size / 64) - 1;
		ctx->vui_params.aspect_ratio_info_present_flag = osa_false;
		ctx->vui_params.aspect_ratio_idc = 0;
		ctx->vui_params.sar_width = 0;
		ctx->vui_params.sar_height = 0;
		ctx->vui_params.cbr = (IMG_RCMODE_CBR == ctx->rc.rc_mode) ?
				      osa_true : osa_false;
		ctx->vui_params.initial_cpb_removal_delay_length_minus1 =
			BPH_SEI_NAL_INITIAL_CPB_REMOVAL_DELAY_SIZE - 1;
		ctx->vui_params.cpb_removal_delay_length_minus1 =
			PTH_SEI_NAL_CPB_REMOVAL_DELAY_SIZE - 1;
		ctx->vui_params.dpb_output_delay_length_minus1 =
			PTH_SEI_NAL_DPB_OUTPUT_DELAY_SIZE - 1;
		ctx->vui_params.time_offset_length = 24;
		ctx->vui_params.num_reorder_frames = 0; //TODO
		ctx->vui_params.max_dec_frame_buffering = 0;

		OSA_PR_DEBUG("h264_vui_params: time_scale=%d\n", ctx->vui_params.time_scale);
		OSA_PR_DEBUG("h264_vui_params: bit_rate_value_minus1=%d\n", ctx->vui_params.bit_rate_value_minus1);
		OSA_PR_DEBUG("h264_vui_params: cbp_size_value_minus1=%d\n", ctx->vui_params.cbp_size_value_minus1);
		OSA_PR_DEBUG("h264_vui_params: cbr=%d\n", ctx->vui_params.cbr);
		OSA_PR_DEBUG("h264_vui_params: initial_cpb_removal_delay_length_minus1=%d\n", ctx->vui_params.initial_cpb_removal_delay_length_minus1);
		OSA_PR_DEBUG("h264_vui_params: cpb_removal_delay_length_minus1=%d\n", ctx->vui_params.cpb_removal_delay_length_minus1);
		OSA_PR_DEBUG("h264_vui_params: dpb_output_delay_length_minus1=%d\n", ctx->vui_params.dpb_output_delay_length_minus1);

		/* Sequence Header parameters */
		switch (level_h264)
		{
			case  100:
				ctx->sh_params.level = SH_LEVEL_1;
				break;
			case 101:
				ctx->sh_params.level = SH_LEVEL_1B;
				break;
			case 110:
				ctx->sh_params.level = SH_LEVEL_11;
				break;
			case 120:
				ctx->sh_params.level = SH_LEVEL_12;
				break;
			case 130:
				ctx->sh_params.level = SH_LEVEL_13;
				break;
			case 200:
				ctx->sh_params.level = SH_LEVEL_2;
				break;
			case 210:
				ctx->sh_params.level = SH_LEVEL_21;
				break;
			case 220:
				ctx->sh_params.level = SH_LEVEL_22;
				break;
			case 300:
				ctx->sh_params.level = SH_LEVEL_3;
				break;
			case 310:
				ctx->sh_params.level = SH_LEVEL_31;
				break;
			case 320:
				ctx->sh_params.level = SH_LEVEL_32;
				break;
			case 400:
				ctx->sh_params.level = SH_LEVEL_4;
				break;
			case 410:
				ctx->sh_params.level = SH_LEVEL_41;
				break;
			case 420:
				ctx->sh_params.level = SH_LEVEL_42;
				break;
			case 500:
				ctx->sh_params.level = SH_LEVEL_5;
				break;
			case 510:
				ctx->sh_params.level = SH_LEVEL_51;
				break;
			case 520:
				ctx->sh_params.level = SH_LEVEL_52;
				break;
			default:
				OSA_PR_ERR("Error invalid h264 level %d\n", level_h264);
				return -OSA_EINVAL;
		}

		if (MM_TYPE_IS_OUTPUT(pix_mp->fmt->type)) {
			ctx->sh_params.width_in_mbs_minus1 =
				(queue->width / MB_SIZE) - 1;
			ctx->sh_params.height_in_maps_units_minus1 =
				(queue->height / MB_SIZE) - 1;
			OSA_PR_DEBUG("h264_sequence_header_params: width_in_mbs_minus1=%d\n", ctx->sh_params.width_in_mbs_minus1);
			OSA_PR_DEBUG("h264_sequence_header_params: height_in_maps_units_minus1=%d\n", ctx->sh_params.height_in_maps_units_minus1);
		}
		ctx->sh_params.log2_max_pic_order_cnt = 6; //hard coded
		ctx->sh_params.gaps_in_frame_num_value = osa_false;
		ctx->sh_params.frame_mbs_only_flag = ctx->vparams.is_interlaced ?
						     osa_false : osa_true;
		ctx->sh_params.vui_params_present = (IMG_RCMODE_NONE == ctx->rc.rc_mode)
						    ? osa_false: osa_true;
		ctx->sh_params.seq_scaling_matrix_present_flag = osa_false;
		ctx->sh_params.use_default_scaling_list = osa_false;
		ctx->sh_params.is_lossless = osa_false;
		ctx->sh_params.vui_params = ctx->vui_params;

		OSA_PR_DEBUG("h264_sequence_header_params: frame_mbs_only_flag=%d\n", ctx->sh_params.frame_mbs_only_flag);
		OSA_PR_DEBUG("h264_sequence_header_params: vui_params_present=%d\n", ctx->sh_params.vui_params_present);

		ctx->s_fmt_flags |= S_FMT_FLAG_OUT_RECV;
	} else {
		for (i = 0; i < pix_mp->fmt->num_planes; i++) {
			queue->bytesperline[i] = 0;
			queue->size_image[i] =
				topaz_get_coded_buffer_max_size(ctx->topaz_str_context,
								queue->fmt->std,
								queue->width,
								queue->height,
								&ctx->rc);
		}
		ctx->vparams.standard = pix_mp->fmt->std;
		ctx->vparams.width = pix_mp->width;
		/*
		 * Note: Do not halve height for interlaced.
		 * App should take care of this.
		 */
		ctx->vparams.frame_height = pix_mp->height;

		OSA_PR_DEBUG("img_video_params: standard=%d\n", ctx->vparams.standard);
		OSA_PR_DEBUG("img_video_params: width=%d\n", ctx->vparams.width);
		OSA_PR_DEBUG("img_video_params: frame_height=%d\n", ctx->vparams.frame_height);

		ctx->s_fmt_flags |= S_FMT_FLAG_CAP_RECV;
	}
	ctx->vparams.is_interlaced = osa_false;

	ctx->vparams.buffer_stride_bytes = 0;
	ctx->vparams.buffer_height = 0;

	ctx->vparams.crop_left = 0;
	ctx->vparams.crop_right = 0;
	ctx->vparams.crop_top = 0;
	ctx->vparams.crop_bottom = 0;

	OSA_PR_DEBUG("s_fmt_flags=%#08x\n", ctx->s_fmt_flags);
	if ((ctx->s_fmt_flags & S_FMT_FLAG_OUT_RECV) &&
	    (ctx->s_fmt_flags & S_FMT_FLAG_CAP_RECV))
	{
		topaz_stream_create(ctx, &ctx->vparams, pix_mp->basepipe, ctx->vparams.slices_per_picture, &ctx->rc,
				    &ctx->topaz_str_context);

		topaz_h264_prepare_sequence_header(ctx->topaz_str_context,
						   ctx->sh_params.width_in_mbs_minus1 + 1,
						   ctx->sh_params.height_in_maps_units_minus1 + 1,
						   osa_true, &ctx->vui_params,
						   &ctx->crop_params,
						   &ctx->sh_params, osa_false);
		/* Note: cqp_offset looks unset in img */
		topaz_h264_prepare_picture_header(ctx->topaz_str_context, 0);

		topaz_load_context(ctx->topaz_str_context);

		ctx->s_fmt_flags |= S_FMT_FLAG_STREAM_CREATED;
	}

	return 0;
}

int32_t MM_ENC_BufPrepare(struct mm_buffer *buffer, uint32_t chId)
{
	struct vxe_enc_ctx *ctx;
	mm_vxe_buff *mm_buf;
	struct vxe_enc_q_data *queue;
	int32 plane, num_planes, ret = 0;
	struct vxe_buffer *vxe_buf;

	struct vxe_buffer *buf;
	struct sg_table sgt = {0};
	struct scatterlist sgl[MAX_PLANES + 1] = {0};
	struct page page[MAX_PLANES] = {0};
	ulong aligned = 0x0FFF;

	if (chId >= MAX_NUM_CHANNELS)
	{
		OSA_PR_ERR("%s Wrong chId passed by App.!!!", __func__);
		return -OSA_EFAULT;
	}

	if (buffer->chId != chId)
	{
		buffer->chId = chId;
		OSA_PR_ERR("%s buffer->chId is not set correctly, resetting here!!", __func__);
	}

	ctx = g_MM_ENC_Inst.ch_obj[chId].mm_ctx;
	mm_buf = g_MM_ENC_Inst.ch_obj[chId].mm_buf;

	vxe_buf = vxe_get_buf(buffer, chId);

	if (vxe_buf != NULL)
	{
		OSA_PR_INFO("%s:This buffer is already mapped\n",__func__);
		return 0;
	}

	if (mm_buf->vxe_buf_index >= MAX_NUM_VXE_BUFFER_PER_CH)
	{
		OSA_PR_ERR("%s: Num buffers supported per ch exceeds the Max (%d) \n"
			,__func__, MAX_NUM_VXE_BUFFER_PER_CH);
		return -OSA_EINVAL;
	}

	buf = osa_zalloc(sizeof(*buf), OSA_GFP_KERNEL);
	if (!buf) {
		return -OSA_ENOMEM;
	}

	buf->buffer = buffer;

	queue = vxe_get_q_data(ctx, buf->buffer->type);
	if (!queue)
		return -OSA_EINVAL;

	num_planes = queue->fmt->num_planes;

	for (plane = 0; plane < num_planes; plane++) {
		if (buf->buffer->size[plane] < queue->size_image[plane]) {
			OSA_DEV_ERR(ctx->dev, "data will not fit into plane (%lu < %lu)\n",
				(slong)buf->buffer->size[plane],
				(slong)queue->size_image[plane]);
			return -OSA_EINVAL;
		}
	}

	if (buf->mapped)
		return 0;


	buf->buf_info.cpu_virt = buf->buffer->buf_addr[0];
	buf->buf_info.buf_size = ALIGN(buf->buffer->size[0], OSA_PAGE_SIZE);

#ifdef DEBUG_ENCODER_DRIVER
	OSA_PR_INFO("%s printing contents of buffer %d at %#08x\n",
		__func__, mm_buf->vxe_buf_index, vxe_buf->buf_info.cpu_virt);
	uint32 i;

	for (i = 0; i < 50; i = i + 8) {
		OSA_PR_INFO("[%d] 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x,\n",
		       ((i + 1) / 8),
		       ((char*)buf->buf_info.cpu_virt)[i+0],
		       ((char*)buf->buf_info.cpu_virt)[i+1],
		       ((char*)buf->buf_info.cpu_virt)[i+2],
		       ((char*)buf->buf_info.cpu_virt)[i+3],
		       ((char*)buf->buf_info.cpu_virt)[i+4],
		       ((char*)buf->buf_info.cpu_virt)[i+5],
		       ((char*)buf->buf_info.cpu_virt)[i+6],
		       ((char*)buf->buf_info.cpu_virt)[i+7]);
	}
#endif


	sgt.nents = 1;
	sgt.orig_nents = 0;
	sgt.sgl = &sgl[0];
	sgl[0].page_link = 0;
	sgl[0].dma_address = buf->buffer->buf_addr[0];

	sgl[0].offset = 0;
	sgl[0].length = ALIGN(buf->buffer->size[0], OSA_PAGE_SIZE);

	page[0].sgt = &sgt;
	osa_sg_set_page(&sgl[0], &page[0], OSA_PAGE_SIZE, 0);

	if(((ulong)(sgl[0].dma_address) & aligned) != 0)
	{
		OSA_DEV_ERR(ctx->dev, "The given buffer=%p is not aligned with %d\n", sgl[0].dma_address, OSA_PAGE_SIZE);
		return OSA_EINVAL;
	}

	if (MM_TYPE_IS_OUTPUT(buf->buffer->type)) {
		for (plane = 1; plane < num_planes; plane++) {
			buf->buf_info.buf_size += ALIGN(buf->buffer->size[plane], OSA_PAGE_SIZE);
			sgt.nents += 1;
			sgl[plane].dma_address = buf->buffer->buf_addr[plane];
			sgl[plane].length = ALIGN(buf->buffer->size[plane], OSA_PAGE_SIZE);

			page[plane].sgt = &sgt;
			osa_sg_set_page(&sgl[plane], &page[plane], OSA_PAGE_SIZE, 0);
			if(((ulong)(sgl[plane].dma_address) & aligned) != 0)
			{
				OSA_DEV_ERR(ctx->dev, "The given buffer=%p is not aligned with %d\n", sgl[plane].dma_address, OSA_PAGE_SIZE);
				return OSA_EINVAL;
			}
		}

		ret = topaz_stream_map_buf_sg(ctx->topaz_str_context,
					      VENC_BUFTYPE_PICTURE,
					      &buf->buf_info, &sgt);
		if (ret) {
			OSA_DEV_ERR(ctx->dev, "OUTPUT topaz_stream_map_buf_sg failed\n");
			return ret;
		}
		OSA_PR_DEBUG("Picture buffer mapped successfully, buf_id[%d], dev_virt[%x]\n", buf->buf_info.buff_id, buf->buf_info.dev_virt);

		vxe_fill_default_src_frame_params(buf);

		buf->y_buffer.mem_info = buf->buf_info;
		buf->y_buffer.lock = BUFFER_FREE;
		buf->y_buffer.size = 0; /* IMG has 0 */
		buf->y_buffer.bytes_written = 0;

		/* TODO Fill U/V img buffers if necessary */
		buf->src_frame.y_plane_buffer = &buf->y_buffer;
		buf->src_frame.u_plane_buffer = NULL;
		buf->src_frame.v_plane_buffer = NULL;
		buf->src_frame.y_component_offset = 0;

		if (queue->fmt->fourcc == MM_PIX_FMT_NV12M) {
			buf->src_frame.u_component_offset = ALIGN(queue->bytesperline[0] * queue->height, OSA_PAGE_SIZE);
			buf->src_frame.v_component_offset = ALIGN(queue->bytesperline[0] * queue->height, OSA_PAGE_SIZE);
		} else if (queue->fmt->fourcc == MM_PIX_FMT_NV12) {
			buf->src_frame.u_component_offset = queue->bytesperline[0] * queue->height;
			buf->src_frame.v_component_offset = queue->bytesperline[0] * queue->height;
		}

		buf->src_frame.width_bytes = queue->bytesperline[0];
		buf->src_frame.height = queue->height;
		buf->src_frame.src_y_stride_bytes = queue->bytesperline[0];
		buf->src_frame.src_uv_stride_bytes = queue->bytesperline[0];
	} else {
		ret = topaz_stream_map_buf_sg(ctx->topaz_str_context,
					      VENC_BUFTYPE_BITSTREAM,
					      &buf->buf_info, &sgt);
		if (ret) {
			OSA_DEV_ERR(ctx->dev, "CAPTURE core_stream_map_buf_sg failed\n");
			return ret;
		}
		OSA_PR_DEBUG("Bit-stream buffer mapped successfully, buf_id[%d], dev_virt[%x]\n", buf->buf_info.buff_id, buf->buf_info.dev_virt);

		buf->coded_buffer.mem_info = buf->buf_info;
		buf->coded_buffer.lock = BUFFER_FREE;
		buf->coded_buffer.size = buf->buffer->size[0]; //SN: TBD: Revisit the size calculation here
		buf->coded_buffer.bytes_written = 0;
	}

	buf->mapped = osa_true;
	mm_buf->vxe_buf[mm_buf->vxe_buf_index] = buf;
	mm_buf->vxe_buf_index++;

	return 0;
}

/* This function is going to creating stream work-queue resource */
static void enc_release_stream_workqueue_resource(uint32 chId)
{
	mm_work_queue_handle *stream_work_queue = &g_MM_ENC_Inst.ch_obj[chId].stream_work_queue_handle;

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

static void stream_workqueue_Task(void *arg0)
{
    mm_work_queue_handle *stream_work_queue = (mm_work_queue_handle *)arg0;
	struct work_struct *pBuf = NULL;

	while(1)
	{
	    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
		osa_utils_queget(stream_work_queue->queue_handle, (void **)&pBuf, 1U, (uint32)osa_semaphore_wait_forever);
		if(NULL != pBuf)
		{
			if(pBuf->work_complete)
			{
				osa_free(pBuf);
				osa_semaphore_post(stream_work_queue->workq_sem_handle);
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
	    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	}
}

/* This function is going to creating stream work-queue */
static int enc_create_stream_worker_task(struct vxe_enc_ctx *ctx, uint32 chId)
{
	task_params params = {0};
	mm_work_queue_handle *stream_work_queue = &g_MM_ENC_Inst.ch_obj[chId].stream_work_queue_handle;

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

int32_t MM_ENC_Create(mm_vid_create_params *params, mm_enc_ctrl_params *ctrl, uint32_t *ch_Id)
{
	struct vxe_dev *vxe = g_MM_ENC_Inst.mm_dev;
	struct vxe_enc_ctx *ctx;
	mm_vxe_buff *mm_buf;
	int32 i, ret = 0;
	uint32_t chId;
	struct mm_vxe_enc_fmt pix_mp;
	uint8_t *ram_chunk = NULL;

	*ch_Id = 0x7FFFFFFFU;
	osa_mutex_lock(vxe->mutex);

	for (i = 0; i < MAX_NUM_CHANNELS; i++) {
		if ((0 == g_MM_ENC_Inst.ch_obj[i].is_used) &&
			(0x7FFFFFFFU == g_MM_ENC_Inst.ch_obj[i].ch_id))
		{
			g_MM_ENC_Inst.ch_obj[i].ch_id = i;
			g_MM_ENC_Inst.ch_obj[i].is_used = 1U;
			*ch_Id = i;
			break;
		}
	}
	chId = *ch_Id;

	if (chId >= MAX_NUM_CHANNELS)
	{
		OSA_PR_ERR("%s Error in allocating chId!!!", __func__);
		osa_mutex_unlock(vxe->mutex);
		return -OSA_EFAULT;
	}

	memcpy(&g_MM_ENC_Inst.ch_obj[chId].create_prms, params, sizeof(mm_vid_create_params));
	OSA_DEV_DBG(vxe->dev, "%s:%d vxd %p\n", __func__, __LINE__, vxe);

	ctx = osa_zalloc(sizeof(*ctx), OSA_GFP_KERNEL);
	if (!ctx) {
		osa_mutex_unlock(vxe->mutex);
		return -OSA_ENOMEM;
	}

	mm_buf = osa_zalloc(sizeof(*mm_buf), OSA_GFP_KERNEL);
	if (!mm_buf) {
		osa_free(ctx);
		osa_mutex_unlock(vxe->mutex);
		return -OSA_ENOMEM;
	}

	ctx->dev = vxe;
	ctx->s_fmt_flags = 0;
	ctx->eos = osa_false;
	ctx->flag_last = osa_false;
	ctx->available_coded_packages = 0;
	ctx->available_source_frames = 0;
	ctx->frames_encoding = 0;
	ctx->frame_num = 0;
	ctx->out_queue.streaming = osa_false;
	ctx->cap_queue.streaming = osa_false;

	g_MM_ENC_Inst.ch_obj[chId].mm_ctx = ctx;
	g_MM_ENC_Inst.ch_obj[chId].mm_buf = mm_buf;
	mm_buf->vxe_buf_index = 0;

	osa_mutex_create(&ctx->mutex);
	if(NULL == ctx->mutex)
	{
		osa_free(ctx);
		osa_free(mm_buf);
		osa_mutex_unlock(vxe->mutex);
		return -OSA_ENOMEM;
	}

	ret = enc_create_stream_worker_task(ctx, chId);
	if(OSA_STATUS_SOK != ret) {
		osa_free(mm_buf);
		enc_release_stream_workqueue_resource(chId);
		osa_mutex_destroy(&ctx->mutex);
		osa_free(ctx);
		osa_mutex_unlock(vxe->mutex);
		return ret;
	}

	vxe_fill_default_params(ctx);
	vxe_create_ctx(vxe, ctx);

	for (i = 0; i < ARRAY_SIZE(vxe_enc_formats); i++) {
		if (vxe_enc_formats[i].type ==
		    IMG_ENC_FMT_TYPE_OUTPUT) {
			ctx->out_queue.fmt = &vxe_enc_formats[i];
			break;
		}
	}
	for (i = 0; i < ARRAY_SIZE(vxe_enc_formats); i++) {
		if (vxe_enc_formats[i].type ==
		    IMG_ENC_FMT_TYPE_CAPTURE) {
			ctx->cap_queue.fmt = &vxe_enc_formats[i];
			break;
		}
	}

	OSA_PR_DEBUG("%s: ctrl->features = %08x\n", __func__, ctrl->features);

	vxe_enc_s_parm(ctrl, chId);

	if (vxe->ocm_ram_chunk[0] && !vxe->ram_chunk_owner[0]) {
		ram_chunk = (uint8_t *)vxe->ocm_ram_chunk[0];
		vxe->ram_chunk_owner[0] = ctx;
	} else if (vxe->ocm_ram_chunk[1] && !vxe->ram_chunk_owner[1]) {
		ram_chunk = (uint8_t *)vxe->ocm_ram_chunk[1];
		vxe->ram_chunk_owner[1] = ctx;
	}

	if (ram_chunk) {
		/* use ram chunk to map above mb params */
		for (i = 0; i < 2 /*max cores*/; i++) {
			struct scatterlist *sgl;
			sgl = osa_zalloc(sizeof(*sgl), OSA_GFP_KERNEL);
			if (sgl) {
				struct page page[MAX_PLANES] = {0};
				ulong aligned = 0x0FFF;

				ctx->above_mb_params_sgt[i].nents = 1;
				ctx->above_mb_params_sgt[i].orig_nents = 0;
				ctx->above_mb_params_sgt[i].sgl = sgl;
				sgl->page_link = 0;
				sgl->dma_address = ram_chunk;
				sgl->offset = 0;
				sgl->length = ALIGN((OCM_RAM_POOL_CHUNK_SIZE / 2), OSA_PAGE_SIZE);
				page[0].sgt = &ctx->above_mb_params_sgt[i];
				osa_sg_set_page(sgl, &page[0], OSA_PAGE_SIZE, 0);

				if(((ulong)(sgl->dma_address) & aligned) != 0) {
					OSA_DEV_ERR(vxe->dev, "The given buffer=%p is not aligned with %d\n", sgl->dma_address, OSA_PAGE_SIZE);
					osa_mutex_unlock(vxe->mutex);
					return OSA_EINVAL;
				}
				ram_chunk += (OCM_RAM_POOL_CHUNK_SIZE / 2);
			}
		}
	}

	if (params->in_pixelformat == MM_PIX_FMT_NV12)
	{
		pix_mp.width = params->width;
		pix_mp.height = params->height;
		pix_mp.pixelformat = params->in_pixelformat;
		pix_mp.fmt = &vxe_enc_formats[0]; //Hardcoding the format

		pix_mp.bytesperline = pix_mp.width * pix_mp.fmt->bytes_pp;

		pix_mp.sizeimage = pix_mp.bytesperline * pix_mp.height;

		ret = vxe_enc_s_fmt(&pix_mp, chId);
	}
	else if (params->in_pixelformat == MM_PIX_FMT_NV12M)
	{
		pix_mp.width = params->width;
		pix_mp.height = params->height;
		pix_mp.pixelformat = params->in_pixelformat;
		pix_mp.fmt = &vxe_enc_formats[1]; //Hardcoding the format

		pix_mp.bytesperline = pix_mp.width * pix_mp.fmt->bytes_pp;

		pix_mp.sizeimage = pix_mp.bytesperline * pix_mp.height;

		ret = vxe_enc_s_fmt(&pix_mp, chId);
	}
	else
	{
		OSA_DEV_ERR(vxe->dev, "%s: Invalid in_pixelformat params!\n", __func__);
		ret = -OSA_EINVAL;
		osa_free(mm_buf);
		enc_release_stream_workqueue_resource(chId);
		osa_mutex_destroy(&ctx->mutex);
		osa_free(ctx);
		osa_mutex_unlock(vxe->mutex);
		return ret;
	}

	if (params->out_pixelformat == MM_PIX_FMT_H264)
	{
		pix_mp.width = params->width;
		pix_mp.height = params->height;
		pix_mp.pixelformat = params->out_pixelformat;
		pix_mp.fmt = &vxe_enc_formats[2]; //hardcoding the format
		pix_mp.bytesperline = pix_mp.width * pix_mp.fmt->bytes_pp;
		pix_mp.sizeimage = pix_mp.bytesperline * pix_mp.height;

		if (ctrl->base_pipe <= MAX_BASE_PIPE)
		{
			pix_mp.basepipe = ctrl->base_pipe;
		}
		else
		{
			OSA_DEV_ERR(vxe->dev, "%s: Invalid base_pipe!\n", __func__);
			ret = -OSA_EINVAL;
			osa_free(mm_buf);
			enc_release_stream_workqueue_resource(chId);
			osa_mutex_destroy(&ctx->mutex);
			osa_free(ctx);
			osa_mutex_unlock(vxe->mutex);
			return ret;
		}

		ret = vxe_enc_s_fmt(&pix_mp, chId);
	}
	else
	{
		OSA_DEV_ERR(vxe->dev, "%s: Invalid out_pixelformat params!\n", __func__);
		ret = -OSA_EINVAL;
		osa_free(mm_buf);
		enc_release_stream_workqueue_resource(chId);
		osa_mutex_destroy(&ctx->mutex);
		osa_free(ctx);
		osa_mutex_unlock(vxe->mutex);
		return ret;
	}

	osa_mutex_unlock(vxe->mutex);
	return ret;
}

int32_t MM_ENC_Destroy(uint32_t chId)
{
	struct vxe_enc_ctx *ctx;
	struct vxe_dev *vxe;
	mm_vxe_buff *mm_buf;
	int32 i;

	if (chId >= MAX_NUM_CHANNELS)
	{
		OSA_PR_ERR("%s Wrong chId passed by App.!!!", __func__);
		return -OSA_EFAULT;
	}

	ctx = g_MM_ENC_Inst.ch_obj[chId].mm_ctx;
	vxe = ctx->dev;
	mm_buf = g_MM_ENC_Inst.ch_obj[chId].mm_buf;

	osa_mutex_lock(vxe->mutex);

	if (vxe->ram_chunk_owner[0] == ctx)
		vxe->ram_chunk_owner[0] = NULL;
	else if (vxe->ram_chunk_owner[1] == ctx)
		vxe->ram_chunk_owner[1] = NULL;

	osa_free(ctx->above_mb_params_sgt[0].sgl);
	osa_free(ctx->above_mb_params_sgt[1].sgl);

	/* unmap all i/o buffers */
	for(i = 0; i <= mm_buf->vxe_buf_index; i++)
	{
		if(mm_buf->vxe_buf[i])
		{
			topaz_stream_unmap_buf_sg(ctx->topaz_str_context, &mm_buf->vxe_buf[i]->buf_info);
			osa_free(mm_buf->vxe_buf[i]);
		}
	}

	if (ctx->s_fmt_flags & S_FMT_FLAG_STREAM_CREATED)
		topaz_stream_destroy(ctx->topaz_str_context);

	ctx->topaz_str_context = NULL;

	mm_buf->vxe_buf_index = 0;
	g_MM_ENC_Inst.ch_obj[chId].ch_id = 0x7FFFFFFFU;
	g_MM_ENC_Inst.ch_obj[chId].is_used = 0U;

	osa_free(mm_buf);
	enc_release_stream_workqueue_resource(chId);
	osa_mutex_destroy(&ctx->mutex);

	osa_free(ctx);
	osa_mutex_unlock(vxe->mutex);

#ifdef DEBUG_OSA_MEM
	OSA_PR_ERR("##### At the end of MM_ENC_Destroy #####");
	osa_print_mem_leak();
#endif

	return 0;
}

int32_t MM_ENC_StartStreaming(uint32_t chId, mm_buffertype type)
{
	struct vxe_enc_ctx *ctx;
	struct vxe_enc_q_data *queue;

	if (chId >= MAX_NUM_CHANNELS)
	{
		OSA_PR_ERR("%s Wrong chId passed by App.!!!", __func__);
		return -OSA_EFAULT;
	}

	ctx = g_MM_ENC_Inst.ch_obj[chId].mm_ctx;
	queue = vxe_get_q_data(ctx, type);

	if (queue)
		queue->streaming = osa_true;

	return 0;
}

int32_t MM_ENC_StopStreaming(uint32_t chId, mm_buffertype type)
{
	struct vxe_enc_ctx *ctx;
	struct vxe_enc_q_data *queue;

	if (chId >= MAX_NUM_CHANNELS)
	{
		OSA_PR_ERR("%s Wrong chId passed by App.!!!", __func__);
		return -OSA_EFAULT;
	}

	ctx = g_MM_ENC_Inst.ch_obj[chId].mm_ctx;

	osa_mutex_lock(ctx->mutex);
	if ((0 < ctx->available_source_frames) ||
		   (0 < ctx->frames_encoding)) {
		/*
		 * Buffers are still in firmware for encode. Tell topaz
		 * that last frame sent is last frame in stream
		 */
		topaz_end_of_stream(ctx->topaz_str_context, ctx->frame_num);
		ctx->last_frame_num = ctx->frame_num;
		osa_mutex_unlock(ctx->mutex);
	} else {
		/* All buffers are encoded, so issue dummy stream end */
		osa_mutex_unlock(ctx->mutex);
		topaz_flush_stream(ctx->topaz_str_context, ctx->last_frame_num);
	}

	queue = vxe_get_q_data(ctx, type);
	if (queue)
		queue->streaming = osa_false;

	return 0;
}

int32_t MM_ENC_Control()
{
    return 0;
}

int32_t MM_ENC_QueryBufInfo(uint32_t chId, uint32_t *nbuffers, uint32_t *max_size)
{
	struct vxe_enc_ctx *ctx;
	struct vxe_enc_q_data *queue;

	if (chId >= MAX_NUM_CHANNELS)
	{
		OSA_PR_ERR("%s Wrong chId passed by App.!!!", __func__);
		return -OSA_EFAULT;
	}


	ctx = g_MM_ENC_Inst.ch_obj[chId].mm_ctx;

	queue = vxe_get_q_data(ctx, MM_BUF_TYPE_VIDEO_OUTPUT);
	if (!queue)
		return -OSA_EINVAL;

	*nbuffers = topaz_get_coded_package_max_num(ctx->topaz_str_context,
			queue->fmt->std,
			queue->width,
			queue->height,
			&ctx->rc);
	*max_size = topaz_get_coded_buffer_max_size(ctx->topaz_str_context,
			queue->fmt->std,
			queue->width,
			queue->height,
			&ctx->rc);
	return 0;
}
