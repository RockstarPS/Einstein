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

#include "core.h"
#include "img_dec_common.h"
#include "vxd_pvdec_priv.h"
#include "vxd_dec.h"
#include "osal/inc/osa_mem.h"
#include "osal/inc/osa_idr.h"
#include "osal/inc/osa_err.h"
#include "osal/inc/osa_define.h"
#include "osal/inc/osa_time.h"
#include "mm_dec_priv.h"


int32_t MM_DEC_Process(struct mm_buffer *in_buf,
		struct mm_buffer *out_buf, uint32_t chId)
{
	struct vxd_dec_ctx *ctx = NULL;
	struct vxd_dev *vxd_dev = NULL;
	struct vxd_buffer *src_vxdb;
	struct vxd_buffer *dst_vxdb;
	struct bspp_bitstr_seg *item = NULL, *next = NULL;
	struct bspp_preparsed_data *preparsed_data;
	int32 ret = -1;
	struct osa_timespec time;
	static int32 cnt = 0;
	int i;

	if (chId >= MAX_NUM_CHANNELS)
	{
		OSA_PR_ERR("%s Wrong chId passed by App.!!!", __func__);
		return -OSA_EFAULT;
	}

	ctx = g_MM_DEC_Inst.ch_obj[chId].mm_ctx;
	vxd_dev = ctx->dev;

	if (in_buf->chId != chId)
	{
		in_buf->chId = chId;
		OSA_PR_ERR("%s in_buf->chId is not set correctly, resetting here!!", __func__);
	}

	src_vxdb = vxd_get_buf(in_buf, chId);
	if (src_vxdb == NULL)
	{
		OSA_PR_ERR("%s:Failed to get input buffer from index\n",__func__);
		return ret;
	}

	if (out_buf->chId != chId)
	{
		out_buf->chId = chId;
		OSA_PR_ERR("%s out_buf->chId is not set correctly, resetting here!!", __func__);
	}

	dst_vxdb = vxd_get_buf(out_buf, chId);
	if (dst_vxdb == NULL)
	{
		OSA_PR_ERR("%s:Failed to get input buffer from index\n",__func__);
		return ret;
	}

	osa_mutex_lock(ctx->lock);
	osa_mutex_lock(ctx->mutex);
	ctx->num_decoding++;

	preparsed_data = &src_vxdb->preparsed_data;

	ret = bspp_stream_submit_buffer(ctx->bspp_context,
					&src_vxdb->bstr_info,
					src_vxdb->buf_map_id,
					in_buf->size[0], NULL,
					VDEC_BSTRELEMENT_UNSPECIFIED);
	if (ret)
		OSA_PR_ERR(" %s: bspp_stream_submit_buffer failed %d\n",__func__, ret);

	osa_mutex_unlock(ctx->mutex);

	ret = bspp_stream_preparse_buffers(ctx->bspp_context, NULL, 0,
					   &ctx->seg_list,
					   preparsed_data, ctx->eos);
	if (ret)
		OSA_PR_ERR("%s:bspp_stream_preparse_buffers failed %d\n",__func__, ret);

	if ((preparsed_data->sequ_hdr_info.com_sequ_hdr_info.max_frame_size.height >
			g_MM_DEC_Inst.ch_obj[chId].create_prms.height) ||
		(preparsed_data->sequ_hdr_info.com_sequ_hdr_info.max_frame_size.width >
			g_MM_DEC_Inst.ch_obj[chId].create_prms.width))
	{
		OSA_PR_ERR("%s: MM_DEC_Process Failed!! stream resolution > Create-time resolution\n",__func__);
		return -1;
	}

	osa_getnstimeofday(&time);
	vxd_dev->time_drv[cnt].start_time = osa_timespec_to_ns(&time);
	vxd_dev->time_drv[cnt].id = dst_vxdb->buf_map_id;
	cnt++;

	if (cnt >= ARRAY_SIZE(vxd_dev->time_drv))
		cnt = 0;

	ret = core_stream_fill_pictbuf(dst_vxdb->buf_map_id);
	if (ret)
			OSA_PR_ERR("%s:core_stream_fill_pictbuf failed %d\n",__func__, ret);

	if (preparsed_data->new_sequence) {
		src_vxdb->seq_unit.str_unit_type =
			VDECDD_STRUNIT_SEQUENCE_START;
		src_vxdb->seq_unit.str_unit_handle = ctx;
		src_vxdb->seq_unit.err_flags = 0;
		src_vxdb->seq_unit.dd_data = NULL;
		src_vxdb->seq_unit.seq_hdr_info =
			&preparsed_data->sequ_hdr_info;
		src_vxdb->seq_unit.seq_hdr_id = 0;
		src_vxdb->seq_unit.closed_gop = osa_true;
		src_vxdb->seq_unit.eop = osa_false;
		src_vxdb->seq_unit.pict_hdr_info = NULL;
		src_vxdb->seq_unit.dd_pict_data = NULL;
		src_vxdb->seq_unit.last_pict_in_seq = osa_false;
		src_vxdb->seq_unit.str_unit_tag = NULL;
		src_vxdb->seq_unit.decode = osa_false;
		src_vxdb->seq_unit.features = 0;
		ret = core_stream_submit_unit(ctx->res_str_id, &src_vxdb->seq_unit);
		if (ret)
				OSA_PR_ERR("%s:core_stream_submit_unit failed %d\n",__func__, ret);
	}

	src_vxdb->pic_unit.str_unit_type = VDECDD_STRUNIT_PICTURE_START;
	src_vxdb->pic_unit.str_unit_handle = ctx;
	src_vxdb->pic_unit.err_flags = 0;
	/* Move the processed segments to the submission buffer */
	for (i = 0; i < BSPP_MAX_PICTURES_PER_BUFFER; i++) {
		item = lst_first(&preparsed_data->picture_data.pre_pict_seg_list[i]);
		while (item) {
			next = lst_next(item);
			lst_remove(&preparsed_data->picture_data.pre_pict_seg_list[i],
					item);
			lst_add(&src_vxdb->pic_unit.bstr_seg_list, item);
			item = next;
		}
		/* Move the processed segments to the submission buffer */
		item = lst_first(&preparsed_data->picture_data.pict_seg_list[i]);
		while (item) {
			next = lst_next(item);
			lst_remove(&preparsed_data->picture_data.pict_seg_list[i],
					item);
			lst_add(&src_vxdb->pic_unit.bstr_seg_list, item);
			item = next;
		}
	}

	src_vxdb->pic_unit.dd_data = NULL;
	src_vxdb->pic_unit.seq_hdr_info = NULL;
	src_vxdb->pic_unit.seq_hdr_id = 0;
	if (preparsed_data->new_sequence)
		src_vxdb->pic_unit.closed_gop = osa_true;
	else
		src_vxdb->pic_unit.closed_gop = osa_false;
	src_vxdb->pic_unit.eop = osa_true;
	src_vxdb->pic_unit.eos = ctx->eos;
	src_vxdb->pic_unit.pict_hdr_info =
		&preparsed_data->picture_data.pict_hdr_info;
	src_vxdb->pic_unit.dd_pict_data = NULL;
	src_vxdb->pic_unit.last_pict_in_seq = osa_false;
	src_vxdb->pic_unit.str_unit_tag = NULL;
	src_vxdb->pic_unit.decode = osa_false;
	src_vxdb->pic_unit.features = 0;
	ret = core_stream_submit_unit(ctx->res_str_id, &src_vxdb->pic_unit);
	if (ret)
		OSA_PR_ERR("%s:core_stream_submit_unit failed %d\n",__func__, ret);

	src_vxdb->end_unit.str_unit_type = VDECDD_STRUNIT_PICTURE_END;
	src_vxdb->end_unit.str_unit_handle = ctx;
	src_vxdb->end_unit.err_flags = 0;
	src_vxdb->end_unit.dd_data = NULL;
	src_vxdb->end_unit.seq_hdr_info = NULL;
	src_vxdb->end_unit.seq_hdr_id = 0;
	src_vxdb->end_unit.closed_gop = osa_false;
	src_vxdb->end_unit.eop = osa_false;
	src_vxdb->end_unit.eos = ctx->eos;
	src_vxdb->end_unit.pict_hdr_info = NULL;
	src_vxdb->end_unit.dd_pict_data = NULL;
	src_vxdb->end_unit.last_pict_in_seq = osa_false;
	src_vxdb->end_unit.str_unit_tag = NULL;
	src_vxdb->end_unit.decode = osa_false;
	src_vxdb->end_unit.features = 0;
	ret = core_stream_submit_unit(ctx->res_str_id, &src_vxdb->end_unit);
	if (ret)
			OSA_PR_ERR("%s:core_stream_submit_unit failed %d\n",__func__, ret);
	osa_mutex_unlock(ctx->lock);
	return ret;
}

int32_t MM_DEC_RegisterCb(
		void (*mm_ret_resource)(void *item, mm_dec_process_cb cb_type, void *cb_ctx),
		uint32_t chId, void *cb_ctx)
{
	struct vxd_dec_ctx *ctx = NULL;

	if (chId >= MAX_NUM_CHANNELS)
	{
		OSA_PR_ERR("%s Wrong chId passed by App.!!!", __func__);
		return -OSA_EFAULT;
	}

	ctx = g_MM_DEC_Inst.ch_obj[chId].mm_ctx;

	if(mm_ret_resource == NULL)
		return -1;

	ctx->mm_return_resource = mm_ret_resource;
	ctx->mm_cb_ctx = cb_ctx;
	return 0;

}
