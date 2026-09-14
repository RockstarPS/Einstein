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
 * h.264 secure data unit parsing API.
 */
#ifndef __H264SECUREPARSER_H__
#define __H264SECUREPARSER_H__

#include "bspp_int.h"
#include "vdec_defs.h"

/*
 * enum h264_nalunittype
 * @Description Contains H264 NAL unit types
 */
enum h264_nalunittype {
	H264_NALTYPE_UNSPECIFIED = 0,
	H264_NALTYPE_SLICE = 1,
	H264_NALTYPE_SLICE_PARTITION_A = 2,
	H264_NALTYPE_SLICE_PARTITION_B = 3,
	H264_NALTYPE_SLICE_PARTITION_C = 4,
	H264_NALTYPE_IDR_SLICE = 5,
	H264_NALTYPE_SUPPLEMENTAL_ENHANCEMENT_INFO = 6,
	H264_NALTYPE_SEQUENCE_PARAMETER_SET = 7,
	H264_NALTYPE_PICTURE_PARAMETER_SET = 8,
	H264_NALTYPE_ACCESS_UNIT_DELIMITER = 9,
	H264_NALTYPE_END_OF_SEQUENCE = 10,
	H264_NALTYPE_END_OF_STREAM = 11,
	H264_NALTYPE_FILLER_DATA = 12,
	H264_NALTYPE_SEQUENCE_PARAMETER_SET_EXTENSION = 13,
	H264_NALTYPE_SLICE_PREFIX = 14,
	H264_NALTYPE_SUBSET_SPS = 15,
	H264_NALTYPE_AUXILIARY_SLICE = 19,
	H264_NALTYPE_SLICE_SCALABLE = 20,
	H264_NALTYPE_SLICE_IDR_SCALABLE = 21,
	H264_NALTYPE_MAX = 31,
	H264_NALTYPE_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * struct bspp_h264_sps_info
 * @Description	H264 SPS parsed information
 */
struct bspp_h264_sps_info {
	uint32 profile_idc;
	uint32 constraint_set_flags;
	uint32 level_idc;
	uint8 seq_parameter_set_id;
	uint8 chroma_format_idc;
	int32 separate_colour_plane_flag;
	uint32 bit_depth_luma_minus8;
	uint32 bit_depth_chroma_minus8;
	uint8 qpprime_y_zero_transform_bypass_flag;
	int32 seq_scaling_matrix_present_flag;
	uint8 seq_scaling_list_present_flag[12];
	uint32 log2_max_frame_num_minus4;
	uint32 pic_order_cnt_type;
	uint32 log2_max_pic_order_cnt_lsb_minus4;
	int32 delta_pic_order_always_zero_flag;
	int32 offset_for_non_ref_pic;
	int32 offset_for_top_to_bottom_field;
	uint32 num_ref_frames_in_pic_order_cnt_cycle;
	uint32 *offset_for_ref_frame;
	uint32 max_num_ref_frames;
	int32 gaps_in_frame_num_value_allowed_flag;
	uint32 pic_width_in_mbs_minus1;
	uint32 pic_height_in_map_units_minus1;
	int32 frame_mbs_only_flag;
	int32 mb_adaptive_frame_field_flag;
	int32 direct_8x8_inference_flag;
	int32 frame_cropping_flag;
	uint32 frame_crop_left_offset;
	uint32 frame_crop_right_offset;
	uint32 frame_crop_top_offset;
	uint32 frame_crop_bottom_offset;
	int32 vui_parameters_present_flag;
	/* mvc_vui_parameters_present_flag;   UNUSED */
	int32 bmvcvuiparameterpresentflag;
	/*
	 * scaling lists are derived from both SPS and PPS information
	 * but will change whenever the PPS changes
	 * The derived set of tables are associated here with the PPS
	 * NB: These are in H.264 order
	 */
	/* derived from SPS and PPS - 8 bit each */
	uint8 *scllst4x4seq;
	/* derived from SPS and PPS - 8 bit each */
	uint8 *scllst8x8seq;
	/* This is not direct parsed data, though it is extracted */
	uint8 usedefaultscalingmatrixflag_seq[12];
};

struct bspp_h264_hrdparam_info {
	uint8     cpb_cnt_minus1;
	uint8     bit_rate_scale;
	uint8     cpb_size_scale;
	uint32	*bit_rate_value_minus1;
	uint32	*cpb_size_value_minus1;
	uint8	*cbr_flag;
	uint8	initial_cpb_removal_delay_length_minus1;
	uint8	cpb_removal_delay_length_minus1;
	uint8	dpb_output_delay_length_minus1;
	uint8	time_offset_length;
};

struct bspp_h264_vui_info {
	uint8                aspect_ratio_info_present_flag;
	uint32              aspect_ratio_idc;
	uint32              sar_width;
	uint32              sar_height;
	uint8                overscan_info_present_flag;
	uint8                overscan_appropriate_flag;
	uint8                video_signal_type_present_flag;
	uint32              video_format;
	uint8                video_full_range_flag;
	uint8                colour_description_present_flag;
	uint32              colour_primaries;
	uint32              transfer_characteristics;
	uint32              matrix_coefficients;
	uint8                chroma_location_info_present_flag;
	uint32              chroma_sample_loc_type_top_field;
	uint32              chroma_sample_loc_type_bottom_field;
	uint8                timing_info_present_flag;
	uint32              num_units_in_tick;
	uint32              time_scale;
	uint8                fixed_frame_rate_flag;
	uint8                nal_hrd_parameters_present_flag;
	struct bspp_h264_hrdparam_info  nal_hrd_parameters;
	uint8                vcl_hrd_parameters_present_flag;
	struct bspp_h264_hrdparam_info  vcl_hrd_parameters;
	uint8                low_delay_hrd_flag;
	uint8                pic_struct_present_flag;
	uint8                bitstream_restriction_flag;
	uint8                motion_vectors_over_pic_boundaries_flag;
	uint32              max_bytes_per_pic_denom;
	uint32              max_bits_per_mb_denom;
	uint32              log2_max_mv_length_vertical;
	uint32              log2_max_mv_length_horizontal;
	uint32              num_reorder_frames;
	uint32              max_dec_frame_buffering;
};

/*
 * struct bspp_h264_seq_hdr_info
 * @Description	Contains everything parsed from the Sequence Header.
 */
struct bspp_h264_seq_hdr_info {
	/* Video sequence header information */
	struct bspp_h264_sps_info sps_info;
	struct bspp_h264_vui_info         vui_info;        /* VUI sequence header information.            */
};

/*
 * struct bspp_h264_ppssgm_info
 * @Description	This structure contains H264 PPS parse data.
 */
struct bspp_h264_ppssgm_info {
	uint8 *slice_group_id;
	uint16 slicegroupidnum;
};

/*
 * struct bspp_h264_pps_info
 * @Description	This structure contains H264 PPS parse data.
 */
struct bspp_h264_pps_info {
	/* pic_parameter_set_id: defines the PPS ID of the current PPS */
	int32 pps_id;
	/* seq_parameter_set_id: defines the SPS that current PPS points to */
	int32 seq_parameter_set_id;
	int32 entropy_coding_mode_flag;
	int32 pic_order_present_flag;
	uint8 num_slice_groups_minus1;
	uint8 slice_group_map_type;
	uint16 run_length_minus1[8];
	uint16 top_left[8];
	uint16 bottom_right[8];
	int32 slice_group_change_direction_flag;
	uint16 slice_group_change_rate_minus1;
	uint16 pic_size_in_map_unit;
	struct bspp_h264_ppssgm_info h264_ppssgm_info;
	uint8 num_ref_idx_lx_active_minus1[H264FW_MAX_REFPIC_LISTS];
	int32 weighted_pred_flag;
	uint8 weighted_bipred_idc;
	int32 pic_init_qp_minus26;
	int32 pic_init_qs_minus26;
	int32 chroma_qp_index_offset;
	int32 deblocking_filter_control_present_flag;
	int32 constrained_intra_pred_flag;
	int32 redundant_pic_cnt_present_flag;
	int32 transform_8x8_mode_flag;
	int32 pic_scaling_matrix_present_flag;
	uint8 pic_scaling_list_present_flag[12];
	int32 second_chroma_qp_index_offset;

	/*
	 * scaling lists are derived from both SPS and PPS information
	 * but will change whenever the PPS changes
	 * The derived set of tables are associated here with the PPS
	 * NB: These are in H.264 order
	 */
	/* derived from SPS and PPS - 8 bit each */
	uint8 *scllst4x4pic;
	/* derived from SPS and PPS - 8 bit each */
	uint8 *scllst8x8pic;
	/* This is not direct parsed data, though it is extracted */
	uint8 usedefaultscalingmatrixflag_pic[12];
};

/*
 * enum bspp_h264_slice_type
 * @Description	contains H264 slice types
 */
enum bspp_h264_slice_type {
	P_SLICE = 0,
	B_SLICE,
	I_SLICE,
	SP_SLICE,
	SI_SLICE,
	SLICE_TYPE_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * struct bspp_h264_slice_hdr_info
 * @Description This structure contains H264 slice header information
 */
struct bspp_h264_slice_hdr_info {
	uint16 first_mb_in_slice;
	enum bspp_h264_slice_type slice_type;

	/* data to ID new picture */
	uint32 pps_id;
	uint32 frame_num;
	uint8 colour_plane_id;
	uint8 field_pic_flag;
	uint8 bottom_field_flag;
	uint32 idr_pic_id;
	uint32 pic_order_cnt_lsb;
	int32 delta_pic_order_cnt_bottom;
	int32 delta_pic_order_cnt[2];
	uint32 redundant_pic_cnt;

	/* Things we need to read out when doing In Secure */
	uint8 num_ref_idx_active_override_flag;
	uint8 num_ref_idx_lx_active_minus1[2];
	uint16 slice_group_change_cycle;
};

/*
 * @Function	bspp_h264_set_parser_config
 * @Description	Sets the parser configuration
 */
int32 bspp_h264_set_parser_config(enum vdec_bstr_format bstr_format,
				struct bspp_vid_std_features *pvidstd_features,
				struct bspp_swsr_ctx *pswsr_ctx,
				struct bspp_parser_callbacks *pparser_callbacks,
				struct bspp_inter_pict_data *pinterpict_data);

/*
 * @Function	bspp_h264_determine_unittype
 * @Description	This function determines the BSPP unit type based on the
 *		provided bitstream (H264 specific) unit type
 */
void bspp_h264_determine_unittype(uint8 bitstream_unittype,
				  int32 disable_mvc,
				  enum bspp_unit_type *pbsppunittype);

#endif /*__H264SECUREPARSER_H__ */
