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
 * encoder header generation interface header
 */

#include "fw_headers/topazscfwif.h"
#include "osal/inc/osa_types.h"
#include "topaz_api.h"
#include "vid_buf.h"

/*
 * enum describing slice/frame type (H264)
 */
enum slhp_sliceframe_type {
	SLHP_P_SLICEFRAME_TYPE,
	SLHP_B_SLICEFRAME_TYPE,
	SLHP_I_SLICEFRAME_TYPE,
	SLHP_SP_SLICEFRAME_TYPE,
	SLHP_SI_SLICEFRAME_TYPE,
	SLHP_IDR_SLICEFRAME_TYPE,
	SLHP_SLICE_FRAME_TYPE_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * struct describing scaling lists (H264)
 */
struct h264_scaling_matrix_params {
	uint8	scaling_lists4x4[6][16];
	uint8	scaling_lists8x8[2][64];
	uint32	list_mask;
};

/*
 * struct describing picture parameter set (H264)
 */
struct h264_picture_header_params {
	uint8	pic_parameter_set_id;
	uint8	seq_parameter_set_id;
	uint8	entropy_coding_mode_flag;
	uint8	weighted_pred_flag;
	uint8	weighted_bipred_idc;
	int8	chroma_qp_index_offset;
	uint8	constrained_intra_pred_flag;
	uint8	transform_8x8_mode_flag;
	uint8	pic_scaling_matrix_present_flag;
	uint8	use_default_scaling_list;
	int8	second_chroma_qp_index_offset;
};

/*
 * struct describing slice header (H264)
 */
struct h264_slice_header_params {
	uint8            startcode_prefix_size_bytes;
	enum slhp_sliceframe_type slice_frame_type;
	uint32           first_mb_address;
	uint8            frame_num_do;
	uint8            idr_pic_id;
	uint8            log2_max_pic_order_cnt;
	uint8            picture_num_do;
	uint8            disable_deblocking_filter_idc;
	osa_bool         pic_interlace;
	osa_bool         field_type;
	osa_bool         reference_picture;
	int8             deb_alpha_offset_div2;
	int8             deb_beta_offset_div2;
	osa_bool         direct_spatial_mv_pred_flag;
	uint8            num_ref_idx_l0_active_minus1;
	int8             diff_ref_pic_num[2]; /*when non-zero reorders reference pic list */
	osa_bool	 weighted_pred_flag;	/* Corresponds to field in the pps */
	uint8		 weighted_bipred_idc;
	int32		 luma_log2_weight_denom;
	int32		 chroma_log2_weight_denom;
	osa_bool	 luma_weight_l0_flag[2]; /* Support for 2 ref pictures on P, or 1 pic in each direction on B. */
	int32		 luma_weight_l0[2];
	int32		 luma_offset_l0[2];
	osa_bool	 chroma_weight_l0_flag[2];
	int32		 chromaB_weight_l0[2];
	int32		 chromaB_offset_l0[2];
	int32		 chromaR_weight_l0[2];
	int32		 chromaR_offset_l0[2];
	uint16		 mvc_view_idx;
	osa_bool         is_longterm_ref;
	uint8            longterm_ref_num;
	osa_bool         ref_is_longterm_ref[2]; /*Long term reference info for reference frames */
	uint8            ref_longterm_ref_num[2];
};

void generate_slice_params_template(struct img_enc_context *enc,
					struct vidio_ddbufinfo *mem_info,
					enum img_frame_template_type slice_type,
					osa_bool is_interlaced, int32 fine_y_search_size);

void h264_prepare_sequence_header(struct mtx_header_params *mtx_header, uint32 pic_width_in_mbs,
				uint32 pic_height_in_mbs, osa_bool vui_params_present, struct h264_vui_params *params,
				struct h264_crop_params	*crop,
				struct h264_sequence_header_params *sh_params,
				osa_bool aso);

void h264_prepare_mvc_sequence_header(struct mtx_header_params *mtx_header,
					uint32 pic_width_in_mbs, uint32 pic_height_in_mbs,
					osa_bool vui_params_present, struct h264_vui_params *params,
					struct h264_crop_params *crop, struct h264_sequence_header_params *sh_params);

void h264_prepare_aud_header(struct mtx_header_params *mtx_header);

void h264_prepare_picture_header(struct mtx_header_params *mtx_header,
				osa_bool cabac_enabled,
				osa_bool transform_8x8,
				osa_bool intra_constrained,
				int8     cqp_offset,
				osa_bool weighted_prediction,
				uint8	 weighted_bi_pred,
				osa_bool mvc_pps,
				osa_bool scaling_matrix,
				osa_bool scaling_lists);
