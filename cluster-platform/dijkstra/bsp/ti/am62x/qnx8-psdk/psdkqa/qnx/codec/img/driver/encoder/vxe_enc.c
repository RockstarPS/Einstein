// SPDX-License-Identifier: GPL-2.0
/*
 * Encoder Interface API function implementations
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

#include "img_mem_man.h"
#include "osal/inc/osa_define.h"
#include "osal/inc/osa_types.h"
#include "topazmmu.h"
#include "vxe_enc.h"

#define MAX(a, b, type) ({ \
		type __a = a; \
		type __b = b; \
		(((__a) >= (__b)) ? (__a) : (__b)); })

void mmu_callback(enum mmu_callback_type callback_type,
		  int32 buff_id, void *data)
{
        topaz_core_mmu_flush_cache();
}

int vxe_init_mem(struct vxe_dev *vxe)
{
	int32 ret;

	/* Create memory management context for HW buffers */
	ret = img_mem_create_ctx(&vxe->drv_ctx.mem_ctx);
	if (ret) {
		OSA_DEV_ERR(vxe->dev, "%s: failed to create mem context (err:%d)!\n",
			    __func__, ret);
		goto create_mem_context_failed;
	}

	ret = img_mmu_ctx_create(vxe->dev, 40 /* mmu_addr_width is 40 */,
                                 vxe->drv_ctx.mem_ctx, vxe->drv_ctx.internal_heap_id,
                                 mmu_callback, vxe, &vxe->drv_ctx.mmu_ctx);
        if (ret) {
                OSA_DEV_ERR(vxe->dev, "%s:%d: failed to create mmu ctx\n",
                        __func__, __LINE__);
                goto create_mmu_context_failed;
        }

	ret = img_mmu_get_ptd(vxe->drv_ctx.mmu_ctx, &vxe->drv_ctx.ptd);
        if (ret) {
                OSA_DEV_ERR(vxe->dev, "%s:%d: failed to get PTD\n",
                        __func__, __LINE__);
                goto get_ptd_failed;
        }

	return 0;

get_ptd_failed:
	img_mmu_ctx_destroy(vxe->drv_ctx.mmu_ctx);
create_mmu_context_failed:
	img_mem_destroy_ctx(vxe->drv_ctx.mem_ctx);
create_mem_context_failed:
	return ret;
}

void vxe_deinit_mem(struct vxe_dev *vxe)
{
	if (vxe->drv_ctx.mmu_ctx) {
		img_mmu_ctx_destroy(vxe->drv_ctx.mmu_ctx);
		vxe->drv_ctx.mmu_ctx = NULL;
	}

	if (vxe->drv_ctx.mem_ctx) {
		img_mem_destroy_ctx(vxe->drv_ctx.mem_ctx);
		vxe->drv_ctx.mem_ctx = NULL;
	}

	/* Deinitialize memory management component */
	while (!osa_list_empty(&vxe->drv_ctx.heaps)) {
		struct vxe_heap *heap;

		heap = osa_list_first_entry(&vxe->drv_ctx.heaps, struct vxe_heap, list);
		osa_list_del(&heap->list);
		img_mem_del_heap(heap->id);
		osa_free(heap);
	}

	vxe->drv_ctx.internal_heap_id = VXE_INVALID_ID;

	img_mem_exit();
}

void vxe_create_ctx(struct vxe_dev *vxe, struct vxe_enc_ctx *ctx)
{
	ctx->mem_ctx = vxe->drv_ctx.mem_ctx;
	ctx->mmu_ctx = vxe->drv_ctx.mmu_ctx;
	return;
}

int32 calculate_h264_level(uint32 width, uint32 height, uint32 framerate,
			    osa_bool rc_enable, uint32 bitrate,
			    osa_bool lossless,
			    enum sh_profile_type profile_type,
			    uint32 max_num_ref_frames)
{
	uint32 level = 0, mbf = 0, mbs = 0, temp_level = 0, dpb_mbs;
	uint32 num = 1, den = 1;
	uint32 lossless_min_level = 320;

	mbf = (width * height) / 256;
	mbs = mbf * framerate;

	if (mbf > 36864) {
		OSA_PR_WARN("WARNING: Frame size is too high for maximum supported level!\n");
		level = 520;
	} else if (mbf > 22080) {
		level = 510;
	} else if (mbf > 8704) {
		level = 500;
	} else if (mbf > 8192) {
		level = 420;
	} else if (mbf > 5120) {
		level = 400;
	} else if (mbf > 3600) {
		level = 320;
	} else if (mbf > 1620) {
		level = 310;
	} else if (mbf > 792) {
		level = 220;
	} else if (mbf > 396) {
		level = 210;
	} else if (mbf > 99) {
		level = 110;
	} else {
		level = 100;
	}

	dpb_mbs = mbf * max_num_ref_frames;

	if (dpb_mbs > 184320) {
		OSA_PR_WARN("ERROR: Decoded picture buffer is too high for supported level!\n");
		return -1;
	} else if (dpb_mbs > 110400) {
		temp_level = 510;
	} else if (dpb_mbs > 34816) {
		temp_level = 500;
	} else if (dpb_mbs > 32768) {
		temp_level = 420;
	} else if (dpb_mbs > 20480) {
		temp_level = 400;
	} else if (dpb_mbs > 18000) {
		temp_level = 320;
	} else if (dpb_mbs > 8100) {
		temp_level = 310;
	} else if (dpb_mbs > 4752) {
		temp_level = 220;
	} else if (dpb_mbs > 2376) {
		temp_level = 210;
	} else if (dpb_mbs > 900) {
		temp_level = 120;
	} else if (dpb_mbs > 396) {
		temp_level = 110;
	} else {
		temp_level = 100;
	}

	level = MAX(level, temp_level, uint32);

	/* now restrict based on the number of macroblocks per second */
	if (mbs > 2073600) {
		OSA_PR_ERR("ERROR: Macroblock processing rate is too high for supported level!\n");
		return -1;
	} else if (mbs > 983040) {
		temp_level = 520;
	} else if (mbs > 589824) {
		temp_level = 510;
	} else if (mbs > 522240) {
		temp_level = 500;
	} else if (mbs > 245760) {
		temp_level = 420;
	} else if (mbs > 216000) {
		temp_level = 400;
	} else if (mbs > 108000) {
		temp_level = 320;
	} else if (mbs > 40500) {
		temp_level = 310;
	} else if (mbs > 20250) {
		temp_level = 300;
	} else if (mbs > 19800) {
		temp_level = 220;
	} else if (mbs > 11880) {
		temp_level = 210;
	} else if (mbs > 6000) {
		temp_level = 130;
	} else if (mbs > 3000) {
		temp_level = 120;
	} else if (mbs > 1485) {
		temp_level = 110;
	} else {
		temp_level = 100;
	}

	level = MAX(level, temp_level, uint32);

	if (rc_enable) {
		/*
		 * SH_PROFILE_H10P and SH_PROFILE_H422P are
		 * not valid choices for HW_3_X, skipping
		 */
		if (profile_type == SH_PROFILE_HP) {
			num = 5;
			den = 4;
		} else if (profile_type == SH_PROFILE_H444P) {
			num = 4;
			den = 1;
		}

		if (bitrate > ((135000000 * num) / den)) {
			temp_level = 510;
		} else if (bitrate > ((50000000 * num) / den)) {
			temp_level = 500;
		} else if (bitrate > ((20000000 * num) / den)) {
			temp_level = 410;
		} else if (bitrate > ((14000000 * num) / den)) {
			temp_level = 320;
		} else if (bitrate > ((10000000 * num) / den)) {
			temp_level = 310;
		} else if (bitrate > ((4000000 * num) / den)) {
			temp_level = 300;
		} else if (bitrate > ((2000000 * num) / den)) {
			temp_level = 210;
		} else if (bitrate > ((768000 * num) / den)) {
			temp_level = 200;
		} else if (bitrate > ((384000 * num) / den)) {
			temp_level = 130;
		} else if (bitrate > ((192000 * num) / den)) {
			temp_level = 120;
		} else if (bitrate > ((128000 * num) / den)) {
			temp_level = 110;
		} else if (bitrate > ((64000 * num) / den)) {
			temp_level = 101;
		} else {
			temp_level = 100;
		}

		level = MAX(level, temp_level, uint32);
	} else {
		level = 510;
	}

	if (lossless) {
		level = MAX(level, lossless_min_level, uint32);
	}

	return level;
}

enum sh_profile_type find_h264_profile(osa_bool lossless,
				       osa_bool h264_use_default_scaling_list,
				       uint32 custom_quant_mask,
				       osa_bool h264_8x8_transform,
				       osa_bool enable_mvc,
				       uint32 b_frame_count,
				       osa_bool interlaced,
				       osa_bool h264_cabac,
				       uint32 weighted_prediction_mode,
				       uint32 weighted_implicit_bi_pred)
{
	enum sh_profile_type profile = SH_PROFILE_BP;

	if (lossless)
		profile = SH_PROFILE_H444P;
	else if (h264_use_default_scaling_list || custom_quant_mask ||
		   h264_8x8_transform || enable_mvc)
		profile = SH_PROFILE_HP;
	else if ((b_frame_count > 0) || interlaced || h264_cabac ||
		   weighted_prediction_mode || weighted_implicit_bi_pred)
		profile = SH_PROFILE_MP;

	return profile;
}

void vxe_fill_default_src_frame_params(struct vxe_buffer *buf)
{
	buf->src_frame.component_count = 0; /* Unset in IMG */
	buf->src_frame.format = IMG_CODEC_420_YUV; /* Unset in IMG */
	buf->src_frame.component_offset[0] = 0;
	buf->src_frame.component_offset[1] = 0;
	buf->src_frame.component_offset[2] = 0;
	buf->src_frame.bottom_component_offset[0] = 0; /* Unset in IMG */
	buf->src_frame.bottom_component_offset[1] = 0; /* Unset in IMG */
	buf->src_frame.bottom_component_offset[2] = 0; /* Unset in IMG */
	buf->src_frame.component_info[0].step = 0;
	buf->src_frame.component_info[0].width = 0;
	buf->src_frame.component_info[0].height = 0;
	buf->src_frame.component_info[0].phys_width = 0;
	buf->src_frame.component_info[0].phys_height = 0;
	buf->src_frame.component_info[1].step = 0;
	buf->src_frame.component_info[1].width = 0;
	buf->src_frame.component_info[1].height = 0;
	buf->src_frame.component_info[1].phys_width = 0;
	buf->src_frame.component_info[1].phys_height = 0;
	buf->src_frame.component_info[2].step = 0;
	buf->src_frame.component_info[2].width = 0;
	buf->src_frame.component_info[2].height = 0;
	buf->src_frame.component_info[2].phys_width = 0;
	buf->src_frame.component_info[2].phys_height = 0;
	buf->src_frame.field0_y_offset = 0;
	buf->src_frame.field1_y_offset = 0;
	buf->src_frame.field0_u_offset = 0;
	buf->src_frame.field1_u_offset = 0;
	buf->src_frame.field0_v_offset = 0;
	buf->src_frame.field1_v_offset = 0;
	buf->src_frame.imported = osa_false;
}

void vxe_fill_default_params(struct vxe_enc_ctx *ctx)
{
	int32 i, j;
	uint16 h264_rounding_offsets[18][4] = {
		{683, 683, 683, 683}, /* 0 I-Slice - INTRA4 LUMA */
		{683, 683, 683, 683}, /* 1 P-Slice - INTRA4 LUMA */
		{683, 683, 683, 683}, /* 2 B-Slice - INTRA4 LUMA */

		{683, 683, 683, 683}, /* 3 I-Slice - INTRA8 LUMA */
		{683, 683, 683, 683}, /* 4 P-Slice - INTRA8 LUMA */
		{683, 683, 683, 683}, /* 5 B-Slice - INTRA8 LUMA */

		{341, 341, 341, 341}, /* 6 P-Slice - INTER8 LUMA */
		{341, 341, 341, 341}, /* 7 B-Slice - INTER8 LUMA */

		{683, 683, 683, 000}, /* 8 I-Slice - INTRA16 LUMA */
		{683, 683, 683, 000}, /* 9 P-Slice - INTRA16 LUMA */
		{683, 683, 683, 000}, /* 10 B-Slice - INTRA16 LUMA */

		{341, 341, 341, 341}, /* 11 P-Slice - INTER16 LUMA */
		{341, 341, 341, 341}, /* 12 B-Slice - INTER16 LUMA */

		{683, 683, 683, 000}, /* 13 I-Slice - INTRA16 CR */
		{683, 683, 683, 000}, /* 14 P-Slice - INTRA16 CR */
		{683, 683, 683, 000}, /* 15 B-Slice - INTRA16 CR */

		{341, 341, 341, 000 }, /* 16 P-Slice - INTER16 CHROMA */
		{341, 341, 341, 000 } /* 17 B-Slice - INTER16 CHROMA */
	};

	ctx->vparams.csc_preset = IMG_CSC_NONE;
	ctx->vparams.slices_per_picture = 1;
	ctx->vparams.is_interleaved = osa_false;
	ctx->vparams.constrained_intra = osa_false;
	ctx->vparams.h264_8x8 = osa_true;
	ctx->vparams.bottom_field_first = osa_false;
	ctx->vparams.arbitrary_so = osa_false;
	ctx->vparams.cabac_enabled = osa_true;
	ctx->vparams.cabac_bin_limit = 2800;
	ctx->vparams.cabac_bin_flex = 2800;
	ctx->vparams.deblock_idc = 0;
	ctx->vparams.output_reconstructed = osa_false;
	ctx->vparams.f_code = 4;
	ctx->vparams.fine_y_search_size = 2;
	ctx->vparams.no_offscreen_mv = osa_false;
	ctx->vparams.idr_period = 1800; /* 60 * 30fps */
	ctx->vparams.intra_cnt = 30;
	ctx->vparams.vop_time_resolution = 15;
	ctx->vparams.enc_features.disable_bpic_ref1 = osa_false;
	ctx->vparams.enc_features.disable_bpic_ref0 = osa_false;
	ctx->vparams.enc_features.disable_bframes = osa_false;
	ctx->vparams.enc_features.restricted_intra_pred = osa_false;
	ctx->vparams.enable_sel_stats_flags = 0;
	ctx->vparams.enable_inp_ctrl = osa_false;
	ctx->vparams.enable_air = osa_false;
	ctx->vparams.num_air_mbs = -1;
	ctx->vparams.air_threshold = -1;
	ctx->vparams.air_skip_cnt = -1;
	ctx->vparams.enable_cumulative_biases = osa_false;
	ctx->vparams.enable_host_bias = osa_true;
	ctx->vparams.enable_host_qp = osa_false;
	ctx->vparams.use_default_scaling_list = osa_false;
	ctx->vparams.use_custom_scaling_lists = 0;
	ctx->vparams.pps_scaling = 0;
	ctx->vparams.disable_bit_stuffing = osa_true;
	ctx->vparams.coded_skipped_index = 3;
	ctx->vparams.inter_intra_index = 3;
	ctx->vparams.mpeg2_intra_dc_precision = 0;
	ctx->vparams.carc = 0;
	ctx->vparams.carc_baseline = 0;
	ctx->vparams.carc_threshold = 1;
	ctx->vparams.carc_cutoff = 15;
	ctx->vparams.carc_neg_range = 5;
	ctx->vparams.carc_neg_scale = 12;
	ctx->vparams.carc_pos_range = 5;
	ctx->vparams.carc_pos_scale = 12;
	ctx->vparams.carc_shift = 3;
	ctx->vparams.weighted_prediction = osa_false;
	ctx->vparams.vp_weighted_implicit_bi_pred = 0;
	ctx->vparams.insert_hrd_params = osa_false;
	ctx->vparams.intra_refresh = 0;
	ctx->vparams.chunks_per_mb = 64;
	ctx->vparams.max_chunks = 160;
	ctx->vparams.priority_chunks = 64;
	ctx->vparams.mbps = 0;
	ctx->vparams.multi_reference_p = osa_false;
	ctx->vparams.ref_spacing = 0;
	ctx->vparams.spatial_direct = osa_false;
	ctx->vparams.vp_adaptive_rounding_disable = 0;

	for (i = 0; i < 18; i++) {
		for (j = 0; j < 4; j++) {
			ctx->vparams.vp_adaptive_rounding_offsets[i][j] =
				h264_rounding_offsets[i][j];
		}
	}

	ctx->vparams.debug_crcs = 0;
	ctx->vparams.enable_mvc = osa_false;
	ctx->vparams.mvc_view_idx = 65535;
	ctx->vparams.high_latency = osa_true;
	ctx->vparams.disable_bh_rounding = osa_false;
	ctx->vparams.no_sequence_headers = osa_false;
	ctx->vparams.auto_encode = osa_false;
	ctx->vparams.slice_level = osa_false;
	ctx->vparams.coded_header_per_slice = osa_false;
	ctx->vparams.auto_expand_pipes = osa_false;
	ctx->vparams.enable_lossless = osa_false;
	ctx->vparams.lossless_8x8_prefilter = osa_false;
	ctx->vparams.enable_scaler = osa_false;
	ctx->vparams.line_counter_enabled = osa_false;

	ctx->rc.initial_qp_i = 0;
	ctx->rc.initial_qp_p = 0;
	ctx->rc.initial_qp_b = 0;

	ctx->rc.min_qp = 0;
	ctx->rc.max_qp = 0;
	ctx->rc.rc_enable = osa_true;

	ctx->rc.hierarchical = osa_false;

	ctx->rc.enable_slice_bob = osa_false;
	ctx->rc.max_slice_bob = 2;
	ctx->rc.slice_bob_qp = 44;

	ctx->rc.qcp_offset = 0;
	ctx->rc.sc_detect_disable = osa_false;
	ctx->rc.slice_byte_limit = 0;
	ctx->rc.slice_mb_limit = 0;
	ctx->rc.rc_mode = IMG_RCMODE_VBR;
	ctx->rc.rc_vcm_mode = IMG_RC_VCM_MODE_DEFAULT;
	ctx->rc.rc_cfs_max_margin_perc = 9;
	ctx->rc.disable_frame_skipping = osa_false;
	ctx->rc.disable_vcm_hardware = osa_false;

	ctx->s_fmt_flags = 0;

	ctx->above_mb_params_sgt[0].sgl = NULL;
	ctx->above_mb_params_sgt[1].sgl = NULL;
}

uint32 vxe_get_sizeimage(int32 w, int32 h, struct vxe_enc_fmt *fmt, uint8 plane_id)
{
	return (w * h * fmt->size_num[plane_id] / fmt->size_den[plane_id]);
}

uint32 vxe_get_stride(int32 w, struct vxe_enc_fmt *fmt)
{
	return (ALIGN(w * fmt->bytes_pp, HW_ALIGN));
}
