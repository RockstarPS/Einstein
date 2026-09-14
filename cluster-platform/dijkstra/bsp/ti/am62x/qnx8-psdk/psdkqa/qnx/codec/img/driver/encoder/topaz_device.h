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
 * topaz driver data strcutures
 */

#if !defined (__TOPAZ_DEVICE_H__)
#define __TOPAZ_DEVICE_H__

#include "fw_headers/topazscfwif.h"
#include "fw_headers/mtx_fwif.h"
#include "osal/inc/osa_interrupt.h"
#include "topazmmu.h"
#include "vid_buf.h"
#include "topaz_api.h"

#       define CODEC_MASK_JPEG          0x0001
#       define CODEC_MASK_MPEG2         0x0002
#       define CODEC_MASK_MPEG4         0x0004
#       define CODEC_MASK_H263          0x0008
#       define CODEC_MASK_H264          0x0010
#       define CODEC_MASK_H264MVC       0x0020
#       define CODEC_MASK_VP8           0x0040
#       define CODEC_MASK_H265          0x0080
#       define CODEC_MASK_FAKE          0x007F

struct img_comm_socket;

/* prototype for callback for incoming message */
typedef void (*enc_cb)(struct img_writeback_msg *msg, void *priv);

#ifdef ENABLE_PROFILING
struct enc_fw_latency
{
	uint32 start_time;
	uint32 end_time;
};
#endif

struct mtx_tohost_msg
{
	enum mtx_message_id cmd_id;
	uint32 input_cmd_word;
	uint8 coded_pkg_idx;
	uint32 wb_val;
	uint32 data;
	struct vidio_ddbufinfo * command_data_buf;
};

struct mtx_tomtx_msg
{
	enum mtx_cmd_id cmd_id;
	uint32 data;
	struct vidio_ddbufinfo * command_data_buf;
};

/*
 * This structure contains the device context.
 */
struct topaz_dev_ctx
{
	/* Parent context, needed to pass to mmu_alloc */
	void * vxe_arg;

	/* KM addresses for mem spaces */
	void * multi_core_mem_addr;
	void * hp_core_reg_addr[TOPAZHP_MAX_NUM_PIPES];
	void * vlc_reg_addr[TOPAZHP_MAX_NUM_PIPES];

	osa_bool initialized; /*!< Indicates that the device driver has been initialised */

	uint32 used_socks;
	struct img_comm_socket *socks[TOPAZHP_MAX_POSSIBLE_STREAMS];

	uint32 fw_uploaded;
	struct img_fw_context fw_ctx;

	void *lock; /* basic device level spinlock */
	void *comm_tx_mutex;
	void *comm_rx_mutex;

	uint32 ptd;
	struct topaz_mmu_context topaz_mmu_ctx;
};

#define COMM_INCOMING_FIFO_SIZE	(WB_FIFO_SIZE * 2)
struct img_comm_socket
{
	uint8	id;
	uint32	low_cmd_cnt;  /* count of low-priority commands sent to TOPAZ */
	uint32	high_cmd_cnt; /* count of high-priority commands sent to TOPAZ */
	uint32	last_sync;    /* Last sync value sent */
	struct  img_writeback_msg in_fifo[COMM_INCOMING_FIFO_SIZE];
	uint32  in_fifo_consumer;
	uint32  in_fifo_producer;
	void *  work;

	enc_cb  cb; /* User-provided callback function */
	struct topaz_stream_context *str_ctx; /* User-provided callback data */

	void * event;
	osa_bool sync_waiting;
	uint32 sync_wb_val;
	void *sync_wb_mutex;

	uint32	 msgs_sent;
	uint32	 ack_recv;
	osa_bool is_serialized;

	uint32  codec;

	struct topaz_dev_ctx *ctx;
#ifdef ENABLE_PROFILING
	struct enc_fw_latency fw_lat;
#endif
};

osa_bool topazdd_threaded_isr(void * data);
osa_irqreturn_t topazdd_isr(void * data);

int32 topazdd_init(uint_addr reg_base, uint32 reg_size, uint32 mmu_flags,
		   void * vxe_arg, uint32 ptd, void ** data);
void topazdd_deinit(void * data);
uint32 topazdd_get_num_pipes(struct topaz_dev_ctx *ctx);
uint32 topazdd_get_core_rev(void);
uint32 topazdd_get_core_des1(void);
osa_bool topazdd_is_idle(struct img_comm_socket *sock);

int32 topazdd_upload_firmware(struct topaz_dev_ctx *ctx,
                              enum img_codec codec);
int32 topazdd_create_stream_context(struct topaz_dev_ctx *ctx, enum img_codec codec,
			  enc_cb cb, void * cb_priv,
			  void **dd_str_ctx, struct vidio_ddbufinfo **wb_data_info);
void topazdd_destroy_stream_ctx(void *dd_str_ctx);
int32 topazdd_setup_stream_ctx(void *dd_str_ctx, uint16 height,
                         uint16 width, uint8 *ctx_num, uint32 *used_sock);
int32 topazdd_send_msg(void *dd_str_ctx, enum mtx_cmd_id cmd_id,
                       uint32 data, struct vidio_ddbufinfo *cmd_data_buf,
                       uint32 *wb_val);
int32 topazdd_send_msg_with_sync(void *dd_str_ctx, enum mtx_cmd_id cmd_id,
				 uint32 data,
				 struct vidio_ddbufinfo *cmd_data_buf);

#endif /* __TOPAZ_DEVICE_H__	*/
