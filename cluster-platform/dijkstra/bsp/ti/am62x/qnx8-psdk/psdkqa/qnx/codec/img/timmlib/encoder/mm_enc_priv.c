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
#include "mm_enc_priv.h"
#include "mm_common.h"

struct MM_ENC_Inst g_MM_ENC_Inst = {0};
struct MM_COMMON_Inst g_MM_COMMON_Inst_Enc = {0};

struct vxe_enc_fmt vxe_enc_formats[] = {
	{
		.fourcc = MM_PIX_FMT_NV12,
		.num_planes = 1,
		.type = IMG_ENC_FMT_TYPE_OUTPUT,
		.fmt = IMG_CODEC_420_PL12,
		.min_bufs = 2,
		.size_num[0] = 3,
		.size_den[0] = 2,
		.bytes_pp = 1,
		.csc_preset = IMG_CSC_NONE,
	},
	{
		.fourcc = MM_PIX_FMT_NV12M,
		.num_planes = 2,
		.type = IMG_ENC_FMT_TYPE_OUTPUT,
		.fmt = IMG_CODEC_420_PL12,
		.min_bufs = 2,
		.size_num[0] = 1,
		.size_den[0] = 1,
		.size_num[1] = 1,
		.size_den[1] = 2,
		.bytes_pp = 1,
		.csc_preset = IMG_CSC_NONE,
	},
	{
		.fourcc = MM_PIX_FMT_H264,
		.num_planes = 1,
		.type = IMG_ENC_FMT_TYPE_CAPTURE,
		.std = IMG_STANDARD_H264,
		.min_bufs = 1,
		.size_num[0] = 1,
		.size_den[0] = 1,
		.bytes_pp = 1,
		.csc_preset = IMG_CSC_NONE,
	},
};

struct vxe_enc_fmt *vxe_find_format(struct mm_vxe_enc_fmt *f, uint32 type)
{
	int32 i;

	for (i = 0; i < ARRAY_SIZE(vxe_enc_formats); ++i) {
		if (vxe_enc_formats[i].fourcc == f->pixelformat &&
		    vxe_enc_formats[i].type == type)
			return &vxe_enc_formats[i];
	}
	return NULL;
}

struct vxe_enc_q_data *vxe_get_q_data(struct vxe_enc_ctx *ctx, uint32 type)
{
	switch (type) {
	case MM_BUF_TYPE_VIDEO_OUTPUT:
		return &ctx->q_data[Q_ENC_DATA_SRC];
	case MM_BUF_TYPE_VIDEO_INPUT:
		return &ctx->q_data[Q_ENC_DATA_DST];
	default:
		return NULL;
	}
}

struct vxe_buffer *vxe_get_buf(void *buf, uint32_t chId)
{
	mm_vxe_buff *mm_buf = g_MM_ENC_Inst.ch_obj[chId].mm_buf;
	int i = 0;

	for(i = 0; i <= mm_buf->vxe_buf_index; i++)
	{
		if(mm_buf->vxe_buf[i] != NULL && buf == mm_buf->vxe_buf[i]->buffer)
		{
			return mm_buf->vxe_buf[i];
		}
	}
	return NULL;
}
