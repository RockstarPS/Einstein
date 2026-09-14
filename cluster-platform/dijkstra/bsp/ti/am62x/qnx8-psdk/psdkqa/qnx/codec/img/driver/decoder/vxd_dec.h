/* SPDX-License-Identifier: GPL-2.0 */
/*
 * IMG DEC SYSDEV and UI Interface header
 *
 * Copyright (c) Imagination Technologies Ltd.
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef _VXD_DEC_H
#define _VXD_DEC_H

#include "bspp.h"
#include "img_dec_common.h"
#include "img_mem_man.h"
#include "img_pixfmts.h"
#include "pixel_api.h"
#include "vdecdd_defs.h"
#include "vdec_defs.h"
#include "osal/inc/osa_workqueue.h"
#include "osal/inc/osa_interrupt.h"
#include "osal/inc/osa_spin.h"
#include "osal/inc/osa_types.h"
#include "osal/inc/osa_define.h"

#define VXD_MIN_STREAM_ID 1
#define VXD_MAX_STREAMS_PER_DEV 254
#define VXD_MAX_STREAM_ID (VXD_MIN_STREAM_ID + VXD_MAX_STREAMS_PER_DEV)

#define CODEC_NONE -1
#define CODEC_H264_DEC 0
#define CODEC_MPEG4_DEC 1
#define CODEC_VP8_DEC 2
#define CODEC_VC1_DEC 3
#define CODEC_MPEG2_DEC 4
#define CODEC_JPEG_DEC 5
#define CODEC_VP9_DEC 6
#define CODEC_HEVC_DEC 7

#define MAX_SEGMENTS 6
#define HW_ALIGN 64

#define MAX_BUF_TRACE 30

#define MAX_CAPBUFS_H264 16
#define DISPLAY_LAG 3
#define HEVC_MAX_LUMA_PS 35651584

enum {
	Q_DATA_SRC = 0,
	Q_DATA_DST = 1,
	Q_DATA_FORCE32BITS = 0x7FFFFFFFU
};

enum {
	IMG_DEC_FMT_TYPE_CAPTURE = 0x01,
	IMG_DEC_FMT_TYPE_OUTPUT = 0x10,
	IMG_DEC_FMT_TYPE_FORCE32BITS = 0x7FFFFFFFU
};

enum vxd_map_flags {
	VXD_MAP_FLAG_NONE = 0x0,
	VXD_MAP_FLAG_READ_ONLY = 0x1,
	VXD_MAP_FLAG_WRITE_ONLY = 0x2,
	VXD_MAP_FLAG_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * struct vxd_fw_msg - This structure holds the information about the message
 *                     exchanged in read/write between Kernel and firmware.
 *
 * @out_flags: indicating the type of message
 * @payload_size: size of payload in bytes
 * @payload: data which is send to firmware
 */
struct vxd_fw_msg {
	uint32 out_flags;
	uint32 payload_size;
	uint32 payload[0];
};

/* HW state */
struct vxd_hw_state {
	uint32 fw_counter;
	uint32 fe_status[VXD_MAX_PIPES];
	uint32 be_status[VXD_MAX_PIPES];
	uint32 dmac_status[VXD_MAX_PIPES][2]; /* Cover DMA chan 2/3*/
	uint32 irq_status;
};

/*
 * struct vxd_state - contains VXD HW state
 *
 * @hw_state: HW state
 * @msg_id_tail: msg id of the oldest item being processed
 */
struct vxd_state {
	struct vxd_hw_state hw_state;
	uint16 msg_id_tail;
};

/*
 * struct vxd_dec_fmt - contains info for each of the supported video format
 *
 * @fourcc: V4L2 pixel format FCC identifier
 * @num_planes: number of planes required for luma and chroma
 * @type: CAPTURE or OUTPUT
 * @std: VDEC video standard
 * @pixfmt: IMG pixel format
 * @interleave: Chroma interleave order
 * @idc: Chroma format
 * @size_num: Numberator used to calculate image size
 * @size_den: Denominator used to calculate image size
 * @bytes_pp: Bytes per pixel for this format
 */
struct vxd_dec_fmt {
	uint32 fourcc;
	uint32 num_planes;
	uint8 type;
	enum vdec_vid_std std;
	enum img_pixfmt pixfmt;
	enum pixel_chroma_interleaved interleave;
	enum pixel_fmt_idc idc;
	int32 size_num;
	int32 size_den;
	int32 bytes_pp;
};

/*
 * struct vxd_item - contains information about the item sent to fw
 *
 * @list: item to be linked list to items_done, msgs, or pend.
 * @stream_id: stream id
 * @msg_id: message id
 * @destroy: item belongs to the stream which is destroyed
 * @msg: contains msg between kernel and fw
 */
struct vxd_item {
	struct clist_head list;
	uint32 stream_id;
	uint32 msg_id;
	struct {
		unsigned destroy:1;
	};
	struct vxd_fw_msg msg;
};

enum vxd_cb_type {
	VXD_CB_STRUNIT_PROCESSED,
	VXD_CB_SPS_RELEASE,
	VXD_CB_PPS_RELEASE,
	VXD_CB_PICT_DECODED,
	VXD_CB_PICT_DISPLAY,
	VXD_CB_PICT_RELEASE,
	VXD_CB_PICT_END,
	VXD_CB_STR_END,
	VXD_CB_ERROR_FATAL,
	VXD_CB_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * vxd_cb - Return a resource to vxd
 *
 * @ctx: the vxd stream context
 * @type: the type of message
 * @buf_map_id: the buf_map_id of the resource being returned
 */
typedef void (*vxd_cb)(void *ctx, enum vxd_cb_type type, uint32 buf_map_id);

/*
 * struct vxd_return - contains information about items returning from core
 *
 * @type: Type of item being returned
 * @buf_map_id: mmu mapped id of buffer being returned
 */
struct vxd_return {
	void *work;
	struct vxd_dec_ctx *ctx;
	enum vxd_cb_type type;
	uint32 buf_map_id;
};

/*
 * struct vxd_dec_q_data - contains queue data information
 *
 * @fmt: format info
 * @width: frame width
 * @height: frame height
 * @bytesperline: bytes per line in memory
 * @size_image: image size in memory
 */
struct vxd_dec_q_data {
	struct vxd_dec_fmt *fmt;
	uint32 width;
	uint32 height;
	uint32 bytesperline[MAX_PLANES];
	uint32 size_image[MAX_PLANES];
};

/*
 * struct time_prof - contains time taken by decoding information
 *
 * @id: id info
 * @start_time: start time
 * @end_time: end time
 */
struct time_prof {
	uint32 id;
	int64 start_time;
	int64 end_time;
};

/*
 * struct vxd_dev - The struct containing decoder driver internal parameters.
 *
 * @v4l2_dev: main struct of V4L2 device drivers
 * @dev: platform device driver
 * @vfd_dec: video device structure to create and manage the V4L2 device node.
 * @plat_dev: linux platform device
 * @m2m_dev: mem2mem device
 * @mutex: mutex to protect certain ongoing operation.
 * @module_irq: a threaded request IRQ for the device
 * @reg_base: base address of the IMG VXD hw registers
 * @props: contains HW properties
 * @mmu_config_addr_width: indicates the number of extended address bits
 *                         (above 32) that the external memory interface
 *                         uses, based on EXTENDED_ADDR_RANGE field of
 *                         MMU_CONFIG0
 * @rendec_buf_id: buffer id for rendec buffer allocation
 * @firmware: firmware information based on vxd_dev_fw structure
 * @firmware_loading_complete: loading completion
 * @no_fw: Just to check if firmware is present in /lib
 * @fw_refcnt: firmware reference counter
 * @hw_on: indication if hw is on or off
 * @hw_dead: indication if hw is dead
 * @lock: basic primitive for locking through spinlock
 * @state: internal state handling of vxd state
 * @msgs: linked list of msgs with vxd_item
 * @pend: linked list of pending msgs to be sent to fw
 * @msg_cnt: counter of messages submitted to VXD. Wraps every VXD_MSG_ID_MASK
 * @freq_khz: Core clock frequency measured during boot of firmware
 * @streams: unique id for the stream
 * @mem_ctx: memory management context for HW buffers
 * @dwork: use for Power Management and Watchdog
 * @work_sched_at: the time of the last work has been scheduled at
 * @emergency: indicates if emergency condition occurred
 * @dbgfs_ctx: pointer to debug FS context.
 * @hw_pm_delay: delay before performaing PM
 * @hw_dwr_period: period for checking for dwr
 * @pm_start: time, in jiffies, when core become idle
 * @dwr_start: time, in jiffies, when dwr has been started
 */
struct vxd_dev {
	ti_device v4l2_dev;
	void *dev;
	struct video_device *vfd_dec;
	struct platform_device *plat_dev;
	m2m_dev *m2m_dev;
	void *mutex; /* Per device mutex */
	int32 module_irq;
	void __iomem *reg_base;
	struct vxd_core_props props;
	uint32 mmu_config_addr_width;
	int32 rendec_buf_id;
	struct vxd_dev_fw firmware;
	void *firmware_loading_complete;
	uint8 no_fw;
	uint8 fw_refcnt;
	uint32 hw_on;
	uint32 hw_dead;
	void *lock; /* basic device level spinlock */
	struct vxd_state state;
	struct clist_head msgs;
	struct clist_head pend;
	int32 msg_cnt;
	uint32 freq_khz;
	void *streams;
	struct mem_ctx *mem_ctx;
	void *dwork;
	uint64 work_sched_at;
	uint32 emergency;
	void *dbgfs_ctx;
	uint32 hw_pm_delay;
	uint32 hw_dwr_period;
	uint64 pm_start;
	uint64 dwr_start;
	struct time_prof time_fw[MAX_BUF_TRACE];
	struct time_prof time_drv[MAX_BUF_TRACE];

	/* The variables defined below are used in RTOS only. */
	/* This variable holds queue handler */
	void *vxd_worker_queue_handle;
	void *vxd_worker_queue_sem_handle;
};

/*
 * struct vxd_stream - holds stream-related info
 *
 * @ctx: associated vxd_dec_ctx
 * @mmu_ctx: MMU context for this stream
 * @ptd: ptd for the stream
 * @id: unique stream id
 */
struct vxd_stream {
	struct vxd_dec_ctx *ctx;
	struct mmu_ctx *mmu_ctx;
	uint32 ptd;
	uint32 id;
};

/*
 * struct vxd_buffer - holds per buffer info.
 * @buffer: the vb2_v4l2_buffer
 * @list: list head for gathering in linked list
 * @mapped: is this buffer mapped yet
 * @reuse: is the buffer ready for reuse
 * @buf_map_id: the mapped buffer id
 * @buf_info: the buffer info for submitting to map
 * @bstr_info: the buffer info for submitting to bspp
 * @seq_unit: the str_unit for submitting sps
 * @seq_unit: the str_unit for submitting pps and segments
 * @seq_unit: the str_unit for submitting picture_end
 */
struct vxd_buffer {
	m2m_buffer buffer;
	struct clist_head list;
	uint8 mapped;
	uint8 reuse;
	uint32 buf_map_id;
	struct vdec_buf_info buf_info;
	struct bspp_ddbuf_info bstr_info;
	struct vdecdd_str_unit seq_unit;
	struct vdecdd_str_unit pic_unit;
	struct vdecdd_str_unit end_unit;
	struct bspp_preparsed_data preparsed_data;
};

typedef void (*decode_cb)(int32 res_str_id, uint32 *msg, uint32 msg_size,
			  uint32 msg_flags);

/*
 * struct vxd_dec_ctx - holds per stream data. Each playback has its own
 *                      vxd_dec_ctx
 *
 * @fh: V4L2 file handler
 * @dev: pointer to the device main information.
 * @ctrl_hdl_dec: v4l2 custom control command for video decoder
 * @mem_ctx: mem context for this stream
 * @mmu_ctx: MMU context for this stream
 * @ptd: page table information
 * @items_done: linked list of items is ready
 * @width: frame width
 * @height: frame height
 * @width_orig: original frame width (before padding)
 * @height_orig: original frame height (before padding)
 * @q_data: Queue data information of src[0] and dst[1]
 * @stream: stream-related info
 * @work: work queue for message handling
 * @return_queue: list of resources returned from core
 * @out_buffers: list of all output buffers
 * @cap_buffers: list of all capture buffers except those in reuse_queue
 * @reuse_queue: list of capture buffers waiting for core to signal reuse
 * @res_str_id: Core stream id
 * @stream_created: Core stream is created
 * @stream_configured: Core stream is configured
 * @opconfig_pending: Core opconfig is pending stream_create
 * @src_streaming: V4L2 src stream is streaming
 * @dst_streaming: V4L2 dst stream is streaming
 * @core_streaming: core is streaming
 * @aborting: signal job abort on next irq
 * @str_opcfg: core output config
 * @pict_bufcfg: core picture buffer config
 * @bspp_context: BSPP Stream context handle
 * @seg_list: list of bspp_bitstr_seg for submitting to BSPP
 * @fw_sequ: BSPP sps resource
 * @fw_pps: BSPP pps resource
 * @cb: registered callback for incoming messages
 * @mutex: mutex to protect context specific state machine
 */
struct vxd_dec_ctx {
	file_hndl fh;
	struct vxd_dev *dev;
	struct mem_ctx *mem_ctx;
	struct mmu_ctx *mmu_ctx;
	uint32 ptd;
	struct clist_head items_done;
	uint32 width;
	uint32 height;
	uint32 width_orig;
	uint32 height_orig;
	struct vxd_dec_q_data q_data[2];
	struct vxd_stream stream;
	void *work;
	struct clist_head return_queue;
	struct clist_head out_buffers;
	struct clist_head cap_buffers;
	struct clist_head reuse_queue;
	uint32 res_str_id;
	uint8 stream_created;
	uint8 stream_configured;
	uint8 opconfig_pending;
	uint8 src_streaming;
	uint8 dst_streaming;
	uint8 core_streaming;
	uint8 aborting;
	uint8 eos;
	uint8 stop_initiated;
	uint8 flag_last;
	uint8 num_decoding;
	uint32 max_num_ref_frames;
	struct vdec_str_opconfig str_opcfg;
	struct vdec_pict_bufconfig pict_bufcfg;
	void *bspp_context;
	struct bspp_bitstr_seg bstr_segments[MAX_SEGMENTS];
	struct lst_t seg_list;
	struct bspp_ddbuf_array_info fw_sequ[MAX_SEQUENCES];
	struct bspp_ddbuf_array_info fw_pps[MAX_PPSS];
	decode_cb cb;
	void *mutex; /* Per stream mutex */

	/* The below variable used only in Rtos */
	void *mm_return_resource; /* Place holder for CB to application */
	void *mm_cb_ctx; /* Place holder for CB context*/
	void *stream_worker_queue_handle;
	void *stream_worker_queue_sem_handle;
	// lock is used to synchronize the stream worker and process function
	void *lock;
	/* "sem_eos" this semaphore variable used to wait until all frame decoded */
	void *sem_eos;
};

osa_irqreturn_t vxd_handle_irq(void *dev);
osa_irqreturn_t vxd_handle_thread_irq(void *dev);
int32 vxd_init(void *dev, struct vxd_dev *vxd,
	     const struct heap_config heap_configs[], int32 heaps);
int32 vxd_g_internal_heap_id(void);
void vxd_deinit(struct vxd_dev *vxd);
int32 vxd_prepare_fw(struct vxd_dev *vxd);
void vxd_clean_fw_resources(struct vxd_dev *vxd);
int32 vxd_send_msg(struct vxd_dec_ctx *ctx, struct vxd_fw_msg *msg);
int32 vxd_suspend_dev(void *dev);
int32 vxd_resume_dev(void *dev);

int32 vxd_create_ctx(struct vxd_dev *vxd, struct vxd_dec_ctx *ctx);
void vxd_destroy_ctx(struct vxd_dev *vxd, struct vxd_dec_ctx *ctx);

int32 vxd_map_buffer_sg(struct vxd_dev *vxd, struct vxd_dec_ctx *ctx,
		      uint32 str_id, uint32 buff_id, void *sgt,
		      uint32 virt_addr, uint32 map_flags);
int32 vxd_map_buffer(struct vxd_dev *vxd, struct vxd_dec_ctx *ctx, uint32 str_id,
		   uint32 buff_id, uint32 virt_addr, uint32 map_flags);
int32 vxd_unmap_buffer(struct vxd_dev *vxd, struct vxd_dec_ctx *ctx,
		     uint32 str_id, uint32 buff_id);

uint32 get_nbuffers(enum vdec_vid_std std, int32 w, int32 h,
		    uint32 max_num_ref_frames);

int32 vxd_dec_alloc_bspp_resource(struct vxd_dec_ctx *ctx,
				       enum vdec_vid_std vid_std);

#ifdef ERROR_RECOVERY_SIMULATION
/* sysfs read write functions */
ssize_t vxd_sysfs_show(struct kobject *vxd_dec_kobject,
		struct kobj_attribute *attr, char *buf);

ssize_t vxd_sysfs_store(struct kobject *vxd_dec_kobject,
		struct kobj_attribute *attr, const char *buf, size_t count);
#endif
#endif /* _VXD_DEC_H */
