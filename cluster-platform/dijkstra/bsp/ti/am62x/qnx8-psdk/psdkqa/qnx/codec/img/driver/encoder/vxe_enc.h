/* SPDX-License-Identifier: GPL-2.0 */
/*
 * encoder interface header
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

#ifndef _VXE_ENC_H
#define _VXE_ENC_H

#include "osal/inc/osa_define.h"
#include "topaz_api.h"

#define HW_ALIGN 64
#define MB_SIZE 16
#define VXE_INVALID_ID (-1)
#define OCM_RAM_POOL_CHUNK_SIZE (32*1024)

enum {
	Q_ENC_DATA_SRC = 0,
	Q_ENC_DATA_DST = 1,
	Q_ENC_DATA_FORCE32BITS = 0x7FFFFFFFU
};

enum {
	IMG_ENC_FMT_TYPE_CAPTURE = 0x01,
	IMG_ENC_FMT_TYPE_OUTPUT = 0x10,
	IMG_ENC_FMT_TYPE_FORCE32BITS = 0x7FFFFFFFU
};

enum vxe_map_flags {
	VXE_MAP_FLAG_NONE = 0x0,
	VXE_MAP_FLAG_READ_ONLY = 0x1,
	VXE_MAP_FLAG_WRITE_ONLY = 0x2,
	VXE_MAP_FLAG_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * struct vxe_enc_fmt - contains info for each supported video format
 */
struct vxe_enc_fmt {
	uint32 fourcc;
	uint32 num_planes;
	uint32 type;
	union {
		enum img_standard std;
		enum img_format fmt;
	};
	uint32 min_bufs;
	uint32 size_num[MAX_PLANES];
	uint32 size_den[MAX_PLANES];
	uint32 bytes_pp;
	enum img_csc_preset csc_preset;
};

/*
 * struct vxe_buffer - contains info for all buffers
 */
struct vxe_buffer
{
	m2m_buffer buffer;
	uint32 index;
	uint32 buf_map_id;
	struct vidio_ddbufinfo buf_info;
	union {
		struct img_frame src_frame;
		struct img_coded_buffer coded_buffer;
	};
	struct img_buffer y_buffer;
	struct img_buffer u_buffer;
	struct img_buffer v_buffer;
	uint8 src_slot_num;
	uint8 mapped;
};

/*
 * struct vxe_heap - node for heaps list
 * @id:   heap id
 * @list: Entry in <struct vxe_drv:heaps>
 */
struct vxe_heap {
	int32 id;
	struct clist_head list;
};

/* Driver context */
struct vxe_drv_ctx {
	/* Available memory heaps. List of <struct vxe_heap> */
	struct clist_head heaps;
	/* heap id for all internal allocations */
	int32 internal_heap_id;
	/* Memory Management context for driver */
	struct mem_ctx *mem_ctx;
	/* MMU context for driver */
	struct mmu_ctx *mmu_ctx;
	/* PTD */
	uint32 ptd;
};

/*
 * struct vxe_dev - The struct containing encoder driver internal parameters.
 */
struct vxe_dev {
	void *dev;
	struct video_device *vfd;
	ti_device ti_vxe_dev;
	struct platform_device *plat_dev;
	m2m_dev *m2m_dev;
	void *mutex;
	int module_irq;
	void *streams;
	void __iomem *reg_base;
	void *topaz_dev_ctx;
	struct vxe_drv_ctx drv_ctx;
	/* dummy context for MMU mappings and allocations */
	struct vxe_enc_ctx *ctx;
	uint32 num_pipes;

	/* The variables defined below are used in RTOS only. */
	/* This variable holds queue handler */
	void *vxe_worker_queue_handle;
	void *vxe_worker_queue_sem_handle;

	/* On Chip Memory Pool for above MB params struct */
	/* Supporting only 2 max instances (upto 1080p resolutions) to make use of this */
	void *ocm_ram_chunk[2]; //each chunk of 32KB
	void *ram_chunk_owner[2];

};

#define S_FMT_FLAG_OUT_RECV 0x1
#define S_FMT_FLAG_CAP_RECV 0x2
#define S_FMT_FLAG_STREAM_CREATED 0x4

/*
 * struct vxe_enc_q_data - contains queue data information
 *
 * @fmt: format info
 * @width: frame width
 * @height: frame height
 * @bytesperline: bytes per line in memory
 * @size_image: image size in memory
 */
struct vxe_enc_q_data {
	struct vxe_enc_fmt *fmt;
	uint32 width;
	uint32 height;
	uint32 bytesperline[MAX_PLANES];
	uint32 size_image[MAX_PLANES];
	osa_bool streaming;
};

#ifdef ENABLE_PROFILING
struct enc_drv_latency
{
	uint32 start_time;
	uint32 end_time;
};
#endif

/*
 * struct vxe_ctx - The struct containing stream context parameters.
 */
struct vxe_enc_ctx {
	file_hndl fh;
	struct vxe_dev *dev;
	void **enc_context;
	void *topaz_str_context;
	void *mutex;
	struct img_enc_caps caps;
	struct img_rc_params rc;
	struct img_video_params vparams;
	struct vxe_enc_q_data out_queue;
	struct vxe_enc_q_data cap_queue;
	struct mem_ctx *mem_ctx;
	struct mmu_ctx *mmu_ctx;
	/* list open_slots*/
	uint8 s_fmt_flags;
	struct h264_vui_params vui_params;
	struct h264_crop_params crop_params;
	struct h264_sequence_header_params sh_params;
	osa_bool eos;
	osa_bool flag_last;
	uint32 coded_packages_per_frame; /* How many slices per frame */
	uint32 available_coded_packages;
	uint32 available_source_frames;
	uint32 frames_encoding;
	uint32 frame_num;
	uint32 last_frame_num;

	/* The below variable used only in Rtos */
	void *mm_return_resource; /* Place holder for CB to application */
	void *cb_ctx; /*context for CB*/
	void *stream_worker_queue_handle;
	void *stream_worker_queue_sem_handle;
	void *work;
	struct vxe_enc_q_data q_data[2];

	struct sg_table above_mb_params_sgt[2];

#ifdef ENABLE_PROFILING
	struct enc_drv_latency drv_lat;
#endif
};

int vxe_init_mem(struct vxe_dev *vxe);
void vxe_deinit_mem(struct vxe_dev *vxe);
void vxe_create_ctx(struct vxe_dev *vxe, struct vxe_enc_ctx *ctx);
int32 calculate_h264_level(uint32 width, uint32 height, uint32 framerate,
			    osa_bool rc_enable, uint32 bitrate,
			    osa_bool lossless,
			    enum sh_profile_type profile_type,
			    uint32 max_num_ref_frames);
enum sh_profile_type find_h264_profile(osa_bool lossless,
				       osa_bool h264_use_default_scaling_list,
				       uint32 custom_quant_mask,
				       osa_bool h264_8x8_transform,
				       osa_bool enable_mvc,
				       uint32 b_frame_count,
				       osa_bool interlaced,
				       osa_bool h264_cabac,
				       uint32 weighted_prediction_mode,
				       uint32 weighted_implicit_bi_pred);
void vxe_fill_default_src_frame_params(struct vxe_buffer *buf);
void vxe_fill_default_params(struct vxe_enc_ctx *ctx);
uint32 vxe_get_sizeimage(int32 w, int32 h, struct vxe_enc_fmt *fmt, uint8 plane_id);
uint32 vxe_get_stride(int32 w, struct vxe_enc_fmt *fmt);


#endif /* _VXE_ENC_H */
