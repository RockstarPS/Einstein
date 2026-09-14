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
 * encoder private defintions
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

#ifndef MM_ENC_PRIV_H_
#define MM_ENC_PRIV_H_

#include "osal/inc/osa_define.h"
#include "vxe_enc.h"
#include "mm_enc.h"

#define MAX_NUM_VXE_BUFFER_PER_CH	(25)

#define MAX_NUM_CHANNELS			(8)

#define MAX_SLICES_PER_PICTURE		(2)

#define MAX_BASE_PIPE				(1)

#define MM_TYPE_IS_OUTPUT(x) (((x) == (uint32)(IMG_ENC_FMT_TYPE_OUTPUT)) ? (1) : (0))

#define WORK_MAX_QUEUE_ELEMENTS		(25)

#define MAX_NUM_FORMATS_SUPPORTED (3)

extern struct MM_ENC_Inst g_MM_ENC_Inst;
extern struct MM_COMMON_Inst g_MM_COMMON_Inst;

extern struct vxe_enc_fmt vxe_enc_formats[MAX_NUM_FORMATS_SUPPORTED];


struct mm_vxe_enc_fmt {
	uint32 width;
	uint32 height;
	uint32 pixelformat;
	uint32 sizeimage;
	uint32 bytesperline;
	uint8  basepipe;
	struct vxe_enc_fmt *fmt;
};


typedef struct {
	/* This semaphore variable used for interrupt handler synchronization */
	void *intr_sem_handle;

	/* This variable used to holds interrupt handler pointer */
	void *intr_handle;

	/* This variable holds the task handler for interrupt */
	void *intr_task_handle;

} mm_intr_handle;

typedef struct {
	/* This variable holds the task handler for work-queue*/
	void *workq_task_handle;

	/* This semaphore variable used for Work-Queue synchronization */
	void *workq_sem_handle;

	/* Address of queue element data area */
	void *queueMem;

	void *queue_handle;

} mm_work_queue_handle;

typedef struct {
	uint32 vxe_buf_index;
	struct vxe_buffer *vxe_buf[MAX_NUM_VXE_BUFFER_PER_CH];
} mm_vxe_buff;

typedef struct {
	uint32 ch_id;
	uint32 is_used;
	mm_vxe_buff *mm_buf;
	struct vxe_enc_ctx *mm_ctx;
	mm_vid_create_params create_prms;
	mm_work_queue_handle stream_work_queue_handle;
} mm_vxe_ch_obj;

struct MM_ENC_Inst {
	struct vxe_dev *mm_dev;
	mm_intr_handle intr_handle;
	mm_work_queue_handle vxe_work_queue_handle;
	mm_vxe_ch_obj ch_obj[MAX_NUM_CHANNELS];
};

struct vxe_enc_fmt *vxe_find_format(struct mm_vxe_enc_fmt *f, uint32 type);
struct vxe_enc_q_data *vxe_get_q_data(struct vxe_enc_ctx *ctx, uint32 type);
struct vxe_buffer *vxe_get_buf(void *mm_buf, uint32_t chId);

#endif /* MM_ENC_PRIV_H_ */
