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
#include "mm_dec_priv.h"
#include "mm_common.h"

struct MM_DEC_Inst g_MM_DEC_Inst = {0};
struct MM_COMMON_Inst g_MM_COMMON_Inst = {0};

struct vxd_dec_fmt vxd_dec_formats[] = {
	{
		.fourcc = MM_PIX_FMT_NV12,
		.num_planes = 1,
		.type = IMG_DEC_FMT_TYPE_CAPTURE,
		.std = VDEC_STD_UNDEFINED,
		.pixfmt = IMG_PIXFMT_420PL12YUV8,
		.interleave = PIXEL_UV_ORDER,
		.idc = PIXEL_FORMAT_420,
		.size_num = 3,
		.size_den = 2,
		.bytes_pp = 1,
	},
	{
		.fourcc = MM_PIX_FMT_NV12M,
		.num_planes = 2,
		.type = IMG_DEC_FMT_TYPE_CAPTURE,
		.std = VDEC_STD_UNDEFINED,
		.pixfmt = IMG_PIXFMT_420PL12YUV8,
		.interleave = PIXEL_UV_ORDER,
		.idc = PIXEL_FORMAT_420,
		.size_num = 1,
		.size_den = 1,
		.bytes_pp = 1,
	},
	{
		.fourcc = MM_PIX_FMT_NV16,
		.num_planes = 1,
		.type = IMG_DEC_FMT_TYPE_CAPTURE,
		.std = VDEC_STD_UNDEFINED,
		.pixfmt = IMG_PIXFMT_422PL12YUV8,
		.interleave = PIXEL_UV_ORDER,
		.idc = PIXEL_FORMAT_422,
		.size_num = 2,
		.size_den = 1,
		.bytes_pp = 1,
	},
	{
		.fourcc = MM_PIX_FMT_TI1210,
		.num_planes = 1,
		.type = IMG_DEC_FMT_TYPE_CAPTURE,
		.std = VDEC_STD_UNDEFINED,
		.pixfmt = IMG_PIXFMT_420PL12YUV10_MSB,
		.interleave = PIXEL_UV_ORDER,
		.idc = PIXEL_FORMAT_420,
		.size_num = 3,
		.size_den = 2,
		.bytes_pp = 2,
	},
	{
		.fourcc = MM_PIX_FMT_TI1210M,
		.num_planes = 2,
		.type = IMG_DEC_FMT_TYPE_CAPTURE,
		.std = VDEC_STD_UNDEFINED,
		.pixfmt = IMG_PIXFMT_420PL12YUV10_MSB,
		.interleave = PIXEL_UV_ORDER,
		.idc = PIXEL_FORMAT_420,
		.size_num = 1,
		.size_den = 1,
		.bytes_pp = 2,
	},
	{
		.fourcc = MM_PIX_FMT_TI1610,
		.num_planes = 1,
		.type = IMG_DEC_FMT_TYPE_CAPTURE,
		.std = VDEC_STD_UNDEFINED,
		.pixfmt = IMG_PIXFMT_422PL12YUV10_MSB,
		.interleave = PIXEL_UV_ORDER,
		.idc = PIXEL_FORMAT_422,
		.size_num = 2,
		.size_den = 1,
		.bytes_pp = 2,
	},
	{
		.fourcc = MM_PIX_FMT_H264,
		.num_planes = 1,
		.type = IMG_DEC_FMT_TYPE_OUTPUT,
		.std = VDEC_STD_H264,
		.pixfmt = IMG_PIXFMT_UNDEFINED,
		.interleave = PIXEL_INVALID_CI,
		.idc = PIXEL_FORMAT_INVALID,
		.size_num = 1,
		.size_den = 1,
		.bytes_pp = 1,
	},
	{
		.fourcc = MM_PIX_FMT_HEVC,
		.num_planes = 1,
		.type = IMG_DEC_FMT_TYPE_OUTPUT,
		.std = VDEC_STD_HEVC,
		.pixfmt = IMG_PIXFMT_UNDEFINED,
		.interleave = PIXEL_INVALID_CI,
		.idc = PIXEL_FORMAT_INVALID,
		.size_num = 1,
		.size_den = 1,
		.bytes_pp = 1,
	},
	{
		.fourcc = MM_PIX_FMT_MJPEG,
		.num_planes = 1,
		.type = IMG_DEC_FMT_TYPE_OUTPUT,
		.std = VDEC_STD_JPEG,
		.pixfmt = IMG_PIXFMT_UNDEFINED,
		.interleave = PIXEL_INVALID_CI,
		.idc = PIXEL_FORMAT_INVALID,
		.size_num = 1,
		.size_den = 1,
		.bytes_pp = 1,
	},
	{
		.fourcc = MM_PIX_FMT_YUV420M,
		.num_planes = 1,
		.type = IMG_DEC_FMT_TYPE_CAPTURE,
		.std = VDEC_STD_UNDEFINED,
		.pixfmt = (enum img_pixfmt)86031,
		.interleave = PIXEL_UV_ORDER,
		.idc = PIXEL_FORMAT_420,
		.size_num = 2,
		.size_den = 1,
		.bytes_pp = 1,
	},
	{
		.fourcc = MM_PIX_FMT_YUV422P,
		.num_planes = 1,
		.type = IMG_DEC_FMT_TYPE_CAPTURE,
		.std = VDEC_STD_UNDEFINED,
		.pixfmt = (enum img_pixfmt)81935,
		.interleave = PIXEL_UV_ORDER,
		.idc = PIXEL_FORMAT_422,
		.size_num = 3,
		.size_den = 1,
		.bytes_pp = 1,
	},
};

struct vxd_dec_fmt *find_format(struct mm_vxd_dec_fmt *f, uint32 type)
{
	int32 i;

	for (i = 0; i < ARRAY_SIZE(vxd_dec_formats); ++i) {
		if (vxd_dec_formats[i].fourcc == f->pixelformat &&
		    vxd_dec_formats[i].type == type)
			return &vxd_dec_formats[i];
	}
	return NULL;
}

struct vxd_buffer *find_buffer(uint32 buf_map_id, struct clist_head *head)
{
	struct clist_head *list;
	struct vxd_buffer *buf = NULL;

	osa_list_for_each(list, head) {
		buf = osa_list_entry(list, struct vxd_buffer, list);
		if (buf->buf_map_id == buf_map_id)
			break;
		buf = NULL;
	}
	return buf;
}

uint32 get_sizeimage(int32 w, int32 h, struct vxd_dec_fmt *fmt)
{
	return (w * h * fmt->size_num / fmt->size_den);
}

uint32 get_stride(int32 w, struct vxd_dec_fmt *fmt)
{
	return (ALIGN(w, HW_ALIGN) * fmt->bytes_pp);
}

struct vxd_dec_q_data *get_q_data(struct vxd_dec_ctx *ctx, uint32 type)
{
	switch (type) {
	case MM_BUF_TYPE_VIDEO_OUTPUT:
		return &ctx->q_data[Q_DATA_SRC];
	case MM_BUF_TYPE_VIDEO_INPUT:
		return &ctx->q_data[Q_DATA_DST];
	default:
		return NULL;
	}
}

int32 vxd_dec_submit_opconfig(struct vxd_dec_ctx *ctx)
{
	int32 ret = 0;

	if (ctx->stream_created) {
		ret = core_stream_set_output_config(ctx->res_str_id,
						    &ctx->str_opcfg,
						    &ctx->pict_bufcfg);
		if (ret) {
			OSA_DEV_ERR(ctx->dev->dev, "core_stream_set_output_config failed\n");
			ctx->opconfig_pending = osa_true;
			return ret;
		}
		ctx->opconfig_pending = osa_false;
		ctx->stream_configured = osa_true;
	} else {
		ctx->opconfig_pending = osa_true;
	}
	return ret;
}

struct vxd_buffer *vxd_get_buf(void *buf, uint32_t chId)
{
	mm_vxd_buff *mm_buf = g_MM_DEC_Inst.ch_obj[chId].mm_buf;
	int i = 0;

	for(i = 0; i <= mm_buf->vxd_buf_index; i++)
	{
		if(mm_buf->vxd_buf[i] != NULL && buf == mm_buf->vxd_buf[i]->buffer)
		{
			return mm_buf->vxd_buf[i];
		}
	}
	return NULL;
}

void vxd_error_recovery(struct vxd_dec_ctx *ctx)
{
	int32 ret = -1;

	/*
	 * In the previous frame decoding fatal error has been detected
	 * so we need to reload the firmware to make it alive.
	 */
	OSA_PR_DEBUG("Reloading the firmware because of previous error \n");
	vxd_clean_fw_resources(ctx->dev);
	ret = vxd_prepare_fw(ctx->dev);
	if (ret)
		OSA_PR_ERR("Reloading the firmware failed!!");

	return;
}
