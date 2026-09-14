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
 * osa memory management defintions
 */

#ifndef MM_DEC_PRIV_H_
#define MM_DEC_PRIV_H_

#include "osal/inc/osa_define.h"
#include "vxd_dec.h"
#include "mm_dec.h"
#include "mm_common.h"


#define MAX_NUM_VXD_BUFFER_PER_CH	(25)

#define MAX_NUM_CHANNELS			(8)

#define MM_TYPE_IS_OUTPUT(x) (((x) == (IMG_DEC_FMT_TYPE_OUTPUT)) ? (1) : (0))

#define WORK_MAX_QUEUE_ELEMENTS		(25)

#define CODEC_CFG_PRINT_BUF_LEN		((uint32_t) 1024U)

extern struct MM_DEC_Inst g_MM_DEC_Inst;
extern struct MM_COMMON_Inst g_MM_COMMON_Inst;

extern struct vxd_dec_fmt vxd_dec_formats[];

struct mm_vxd_dec_fmt {
	uint32 width;
	uint32 height;
	uint32 pixelformat;
	uint32 sizeimage;
	uint32 bytesperline;
	struct vxd_dec_fmt *fmt;
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
	uint32 vxd_buf_index;
	struct vxd_buffer *vxd_buf[MAX_NUM_VXD_BUFFER_PER_CH];
} mm_vxd_buff;

typedef struct {
	uint32 ch_id;
	uint32 is_used;
	mm_vxd_buff *mm_buf;
	struct vxd_dec_ctx *mm_ctx;
	mm_vid_create_params create_prms;
	mm_work_queue_handle stream_work_queue_handle;
} mm_vxd_ch_obj;

struct MM_DEC_Inst {
	struct vxd_dev *mm_dev;
	mm_intr_handle intr_handle;
	mm_work_queue_handle vxd_work_queue_handle;
	mm_vxd_ch_obj ch_obj[MAX_NUM_CHANNELS];
	struct mm_osa_cfg osa_params;
	char printBuf[CODEC_CFG_PRINT_BUF_LEN];
};

struct vxd_dec_fmt *find_format(struct mm_vxd_dec_fmt *f, uint32 type);
struct vxd_buffer *find_buffer(uint32 buf_map_id, struct clist_head *head);
uint32 get_sizeimage(int32 w, int32 h, struct vxd_dec_fmt *fmt);
uint32 get_stride(int32 w, struct vxd_dec_fmt *fmt);
struct vxd_dec_q_data *get_q_data(struct vxd_dec_ctx *ctx, uint32 type);
int32 vxd_dec_submit_opconfig(struct vxd_dec_ctx *ctx);
struct vxd_buffer *vxd_get_buf(void *mm_buf, uint32_t chId);
void vxd_return_resource(void *ctx_handle, enum vxd_cb_type type, uint32 buf_map_id);
void vxd_error_recovery(struct vxd_dec_ctx *ctx);

#endif /* MM_DEC_PRIV_H_ */
