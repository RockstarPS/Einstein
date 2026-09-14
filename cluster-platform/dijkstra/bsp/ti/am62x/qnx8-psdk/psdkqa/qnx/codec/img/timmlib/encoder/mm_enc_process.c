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

#include "vxe_enc.h"
#include "osal/inc/osa_mem.h"
#include "osal/inc/osa_idr.h"
#include "osal/inc/osa_err.h"
#include "osal/inc/osa_define.h"
#include "osal/inc/osa_time.h"
#include "osal/inc/osa_mutex.h"
#include "mm_enc_priv.h"


int32_t MM_ENC_Process(struct mm_buffer *in_buf,
		struct mm_buffer *out_buf_sl1, struct mm_buffer *out_buf_sl2, uint32_t chId)
{
	struct vxe_enc_ctx *ctx;
	struct vxe_buffer *src_vxeb = NULL;
	struct vxe_buffer *dst_vxeb_sl1 = NULL;
        struct vxe_buffer *dst_vxeb_sl2 = NULL;
	int ret = 0;
#ifdef ENABLE_PROFILING
	struct osa_timespec time;
#endif
	if (chId >= MAX_NUM_CHANNELS)
	{
		OSA_PR_ERR("%s Wrong chId passed by App.!!!", __func__);
		return -OSA_EINVAL;
	}

	if (in_buf->chId != chId)
	{
		in_buf->chId = chId;
		OSA_PR_ERR("%s in_buf->chId is not set correctly, resetting here!!", __func__);
	}

	src_vxeb = vxe_get_buf(in_buf, chId);
	if (src_vxeb == NULL)
	{
		OSA_PR_ERR("%s:Failed to get input buffer from index\n",__func__);
		return ret;
	}

	if (out_buf_sl1->chId != chId)
	{
		out_buf_sl1->chId = chId;
		OSA_PR_ERR("%s out_buf->chId is not set correctly, resetting here!!", __func__);
	}

	dst_vxeb_sl1 = vxe_get_buf(out_buf_sl1, chId);
	if (dst_vxeb_sl1 == NULL)
	{
		OSA_PR_ERR("%s:Failed to get 1st output buffer from index\n",__func__);
		return ret;
	}

	ctx = g_MM_ENC_Inst.ch_obj[chId].mm_ctx;

	if (ctx->vparams.slices_per_picture > 1)
	{
		if (!out_buf_sl2)
		{
			OSA_PR_ERR("%s:encoder configures for 2 slice mode, but failed to provide the 2nd slice buffer for output\n",__func__);
			return -OSA_EINVAL;
		}
		else
		{
			dst_vxeb_sl2 = vxe_get_buf(out_buf_sl2, chId);
			if (dst_vxeb_sl2 == NULL)
			{
				OSA_PR_ERR("%s:Failed to get 2nd output buffer from index\n",__func__);
				return -OSA_EINVAL;
			}
		}
	}

	osa_mutex_lock(ctx->mutex);

#ifdef ENABLE_PROFILING
	osa_getnstimeofday(&time);
	ctx->drv_lat.start_time = osa_timespec_to_ns(&time);
#endif

	if ((0 < topaz_query_empty_coded_slots(ctx->topaz_str_context)) &&
	       (0 < topaz_query_empty_source_slots(ctx->topaz_str_context))) {
		/*
		 * Submit src and dst buffers one to one
		 * Note: Will have to revisit for B frame support
		 */
		/* Handle EOS */
		if (ctx->eos) {
			OSA_PR_DEBUG("%s eos found\n", __func__);
			ret = topaz_end_of_stream(ctx->topaz_str_context,
						  ctx->frame_num + 1);
			if (ret)
				OSA_DEV_ERR(ctx->dev, "Failed to send EOS to topaz %d\n",
					    ret);
			ctx->last_frame_num = ctx->frame_num + 1;
		}

		/* Submit coded package */
		ret = topaz_reserve_coded_package_slot(ctx->topaz_str_context);
		if (ret)
			OSA_DEV_ERR(ctx->dev, "Failed to reserve coded package slot %d\n",
				    ret);
		ret = topaz_send_coded_package(ctx->topaz_str_context,
					       &dst_vxeb_sl1->coded_buffer);
		if (ret)
			OSA_DEV_ERR(ctx->dev, "Failed to send coded package %d\n",
				    ret);
		if (!ret)
			ctx->available_coded_packages++;
		if (dst_vxeb_sl2) {
		/* Submit coded package */
		ret = topaz_reserve_coded_package_slot(ctx->topaz_str_context);
		if (ret)
			OSA_DEV_ERR(ctx->dev, "Failed to reserve coded package slot %d\n",
				    ret);
		ret = topaz_send_coded_package(ctx->topaz_str_context,
					       &dst_vxeb_sl2->coded_buffer);
		if (ret)
			OSA_DEV_ERR(ctx->dev, "Failed to send coded package %d\n",
				    ret);
		if (!ret)
			ctx->available_coded_packages++;
		}



		/* Submit source frame */
		ret = topaz_reserve_source_slot(ctx->topaz_str_context,
						&src_vxeb->src_slot_num);
		if (ret)
			OSA_DEV_ERR(ctx->dev, "Failed to reserve source slot %d\n",
				    ret);
		ret = topaz_send_source_frame(ctx->topaz_str_context, &src_vxeb->src_frame,
					      ctx->frame_num, (uint64) ctx);
		if (ret)
			OSA_DEV_ERR(ctx->dev, "Failed to send source frame %d\n",
				    ret);
		ctx->frame_num++;
		if (!ret)
			ctx->available_source_frames++;
	}

	if ((0 < ctx->available_source_frames) &&
	       (0 < ctx->available_coded_packages)) {
		OSA_PR_DEBUG("Calling topaz_encode_frame #src=%d #coded=%d frames_encoding=%d\n",
			ctx->available_source_frames,
			ctx->available_coded_packages,
			ctx->frames_encoding);
		ret = topaz_encode_frame(ctx->topaz_str_context);
		if (ret) {
			OSA_DEV_ERR(ctx->dev, "Failed to send encode_frame command %d\n",
				    ret);
		} else {
			/* TODO: Account for scenarios where these are not 1 */
			ctx->available_source_frames--;
			ctx->available_coded_packages--;
			ctx->frames_encoding++;
		}
	}

	osa_mutex_unlock(ctx->mutex);
	return 0;
}

int32_t MM_ENC_RegisterCb(
		void (*mm_ret_resource)(struct mm_buffer *buf, mm_enc_process_cb cb_type, void *cb_ctx),
		uint32_t chId, void *cb_ctx)
{
	struct vxe_enc_ctx *ctx;

	if (chId >= MAX_NUM_CHANNELS)
	{
		OSA_PR_ERR("%s Wrong chId passed by App.!!!", __func__);
		return -OSA_EFAULT;
	}

	if(mm_ret_resource == NULL)
		return -1;

	ctx = g_MM_ENC_Inst.ch_obj[chId].mm_ctx;
	ctx->mm_return_resource = mm_ret_resource;
	ctx->cb_ctx = cb_ctx;
	return 0;

}

