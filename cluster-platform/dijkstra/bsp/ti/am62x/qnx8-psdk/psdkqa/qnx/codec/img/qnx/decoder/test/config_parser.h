/*
 * Copyright 2022, QNX Software Systems.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject
 * to the following conditions:
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef VXDDEC_CONFIG_PARSER_H_
#define VXDDEC_CONFIG_PARSER_H_

typedef struct {
	int32_t width;
	int32_t height;
	int32_t par_x;
	int32_t par_y;
	uint32_t num_units_in_tick;
	uint32_t time_scale;
	uint32_t fixed_frame_rate_flag;
} decoder_info_t;

// H.264 AVC-specific return data. (fourcc "AVC1")
typedef struct avc_param_set
{
	uint8_t*   string;
	uint8_t*   nalu;
	int16_t    len;
	int16_t    nalu_length;
	int16_t    mmbuffer_offset;
} avc1_param_set_t;

typedef struct avc_crop_info
{
	uint32_t               crop_left;
	uint32_t               crop_right;
	uint32_t               crop_top;
	uint32_t               crop_bottom;
} avc1_crop_info_t;

typedef struct avc_config
{
	uint8_t                profile_indication;
	uint8_t                profile_compatibility;
	uint8_t                level_indication;
	int8_t                 size_length;
	int8_t                 sps_count;
	int8_t                 pps_count;
	decoder_info_t*        sps_info;
	avc1_param_set_t*      sps;
	avc1_param_set_t*      pps;
	avc1_crop_info_t       cropping;
	int32_t                num_ref_frames;
	uint8_t                frame_mbs_only_flag;
	uint8_t                video_full_range_flag;
	int32_t                chroma_format_idc;
} avc1_decoder_specific_t;

int32_t h264_parse_decoder_config(const uint8_t* raw_avcc, uint32_t avcc_size, decoder_info_t *info_out, avc1_decoder_specific_t** avcc_out);
#endif //VXDDEC_CONFIG_PARSER_H_
