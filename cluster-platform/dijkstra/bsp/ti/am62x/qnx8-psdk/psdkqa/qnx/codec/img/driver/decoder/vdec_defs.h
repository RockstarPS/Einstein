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
 * VXD Decoder common header
 */

#ifndef __VDEC_DEFS_H__
#define __VDEC_DEFS_H__

#include "img_mem.h"
#include "img_pixfmts.h"
#ifdef HAS_JPEG
#include "jpegfw_data.h"
#endif
#include "pixel_api.h"
#include "vdecfw_shared.h"

#define VDEC_MAX_PANSCAN_WINDOWS	4
#define VDEC_MB_DIMENSION		(16)

#define MAX_PICS_IN_SYSTEM	(8)
#define SEQUENCE_SLOTS		(8)
#define PPS_SLOTS		(8)
/* Only for HEVC */
#define VPS_SLOTS		(16)
#define MAX_VPSS		(MAX_PICS_IN_SYSTEM + VPS_SLOTS)
#define MAX_SEQUENCES		(MAX_PICS_IN_SYSTEM + SEQUENCE_SLOTS)
#define MAX_PPSS		(MAX_PICS_IN_SYSTEM + PPS_SLOTS)

#define VDEC_H264_MAXIMUMVALUEOFCPB_CNT	32
#define VDEC_H264_MAX_SLICE_GROUPMBS	65536
#define VDEC_H264_MVC_MAX_VIEWS		(H264FW_MAX_NUM_VIEWS)
#define VDEC_H264_MVC_MAX_REFS		(H264FW_MAX_NUM_MVC_REFS)
#define VDEC_H264_MVC_MAX_LEVELS	(16UL)
#define VDEC_H264_MVC_MAX_APP_OP_TID	(16UL)
#define VDEC_H264_MVC_MAX_TARGET_VIEW	(8UL)

#define VDEC_H264_MVC_REF_LIST_ANCHOR_L0	0
#define VDEC_H264_MVC_REF_LIST_ANCHOR_L1	1
#define VDEC_H264_MVC_REF_LIST_NON_ANCHOR_L0	0
#define VDEC_H264_MVC_REF_LIST_NON_ANCHOR_L1	1

#define VDEC_ASSERT(expected) ({OSA_WARN_ON(!(expected)); 0; })

#define VDEC_ALIGN_SIZE(_val, _alignment, val_type, align_type) ({ \
		val_type val = _val; \
		align_type alignment = _alignment; \
		(((val) + (alignment) - 1) & ~((alignment) - 1)); })

/*
 * This type defines the video standard.
 * @brief  VDEC Video Standards
 */
enum vdec_vid_std {
	VDEC_STD_UNDEFINED = 0,
	VDEC_STD_MPEG2,
	VDEC_STD_MPEG4,
	VDEC_STD_H263,
	VDEC_STD_H264,
	VDEC_STD_VC1,
	VDEC_STD_AVS,
	VDEC_STD_REAL,
	VDEC_STD_JPEG,
	VDEC_STD_VP6,
	VDEC_STD_VP8,
	VDEC_STD_SORENSON,
	VDEC_STD_HEVC,
	VDEC_STD_MAX,
	VDEC_STD_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * This type defines the bitstream format. Should be done at the
 * start of decoding.
 * @brief  VDEC Bitstream Format
 */
enum vdec_bstr_format {
	VDEC_BSTRFORMAT_UNDEFINED = 0,
	VDEC_BSTRFORMAT_ELEMENTARY,
	VDEC_BSTRFORMAT_DEMUX_BYTESTREAM,
	VDEC_BSTRFORMAT_DEMUX_SIZEDELIMITED,
	VDEC_BSTRFORMAT_MAX,
	VDEC_BSTRFORMAT_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * This type defines the Type of payload. Could change with every buffer.
 * @brief  VDEC Bitstream Element Type
 */
enum vdec_bstr_element_type {
	VDEC_BSTRELEMENT_UNDEFINED = 0,
	VDEC_BSTRELEMENT_UNSPECIFIED,
	VDEC_BSTRELEMENT_CODEC_CONFIG,
	VDEC_BSTRELEMENT_PICTURE_DATA,
	VDEC_BSTRELEMENT_MAX,
	VDEC_BSTRELEMENT_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * This structure contains the stream configuration details.
 * @brief  VDEC Stream Configuration Information
 */
struct vdec_str_configdata {
	enum vdec_vid_std	vid_std;
	enum vdec_bstr_format	bstr_format;
	uint32			user_str_id;
	uint8			update_yuv;
	uint8		bandwidth_efficient;
	uint8		disable_mvc;
	uint8		full_scan;
	uint8		immediate_decode;
	uint8		intra_frame_closed_gop;
};

/*
 * This type defines the buffer type categories.
 * @brief  Buffer Types
 */
enum vdec_buf_type {
	VDEC_BUFTYPE_BITSTREAM,
	VDEC_BUFTYPE_PICTURE,
	VDEC_BUFTYPE_ALL,
	VDEC_BUFTYPE_MAX,
	VDEC_BUFTYPE_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * This structure contains information related to a picture plane.
 * @brief  Picture Plane Information
 */
struct vdec_plane_info {
	uint32	offset;
	uint32	stride;
	uint32	size;
};

/*
 * This structure describes the VDEC picture dimensions.
 * @brief  VDEC Picture Size
 */
struct vdec_pict_size {
	uint32	width;
	uint32	height;
};

/*
 * This enumeration defines the colour plane indices.
 * @brief  Colour Plane Indices
 */
enum vdec_color_planes {
	VDEC_PLANE_VIDEO_Y	= 0,
	VDEC_PLANE_VIDEO_YUV	= 0,
	VDEC_PLANE_VIDEO_U	= 1,
	VDEC_PLANE_VIDEO_UV	= 1,
	VDEC_PLANE_VIDEO_V	= 2,
	VDEC_PLANE_VIDEO_A	= 3,
	VDEC_PLANE_LIGHT_R	= 0,
	VDEC_PLANE_LIGHT_G	= 1,
	VDEC_PLANE_LIGHT_B	= 2,
	VDEC_PLANE_INK_C	= 0,
	VDEC_PLANE_INK_M	= 1,
	VDEC_PLANE_INK_Y	= 2,
	VDEC_PLANE_INK_K	= 3,
	VDEC_PLANE_MAX		= 4,
	VDEC_PLANE_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * This structure describes the rendered region of a picture buffer (i.e. where
 * the image data is written.
 * @brief  Picture Buffer Render Information
 */
struct vdec_pict_rendinfo {
	uint32			rendered_size;
	struct vdec_plane_info	plane_info[VDEC_PLANE_MAX];
	uint32			stride_alignment;
	struct vdec_pict_size	rend_pict_size;
};

/*
 * This structure contains information required to configure the picture
 * buffers
 * @brief  Picture Buffer Configuration
 */
struct vdec_pict_bufconfig {
	uint32	coded_width;
	uint32	coded_height;
	enum img_pixfmt	pixel_fmt;
	uint32		stride[IMG_MAX_NUM_PLANES];
	uint32		stride_alignment;
	uint8		byte_interleave;
	uint32		buf_size;
	uint8		packed;
	uint32		chroma_offset[IMG_MAX_NUM_PLANES];
	uint32		plane_size[IMG_MAX_NUM_PLANES];
};

/*
 * This structure describes the VDEC Display Rectangle.
 * @brief  VDEC Display Rectangle
 */
struct vdec_rect {
	uint32	top_offset;
	uint32	left_offset;
	uint32	width;
	uint32	height;
};

/*
 * This structure contains the Color Space Description that may be present
 * in SequenceDisplayExtn(MPEG2), VUI parameters(H264), Visual Object(MPEG4)
 * for the application to use.
 * @brief  Stream Color Space Properties
 */
struct vdec_color_space_desc {
	uint8	is_present;
	uint8	color_primaries;
	uint8	transfer_characteristics;
	uint8	matrix_coefficients;
};

/*
 * This structure contains common (standard agnostic) sequence header
 * information, which is required for image buffer allocation and display.
 * @brief  Sequence Header Information (common)
 */
struct vdec_comsequ_hdrinfo {
	uint32		codec_profile;
	uint32		codec_level;
	uint32		bitrate;
	slong		frame_rate;
	uint32		frame_rate_num;
	uint32		frame_rate_den;
	uint32		aspect_ratio_num;
	uint32		aspect_ratio_den;
	uint8		interlaced_frames;
	struct pixel_pixinfo	pixel_info;
	struct vdec_pict_size	max_frame_size;
	uint32 			max_ref_frame_num;
	struct vdec_pict_size	frame_size;
	uint8			field_codec_mblocks;
	uint32			min_pict_buf_num;
	uint8			picture_reordering;
	uint8			post_processing;
	struct vdec_rect	orig_display_region;
	struct vdec_rect	raw_display_region;
	uint32			num_views;
	uint32			max_reorder_picts;
	uint8			separate_chroma_planes;
	uint8			not_dpb_flush;
	struct vdec_color_space_desc	color_space_info;
};

/*
 * This structure contains the standard specific codec configuration
 * @brief Codec configuration
 */
struct vdec_codec_config {
	uint32	default_height;
	uint32	default_width;
};

/*
 * This structure describes the decoded picture attributes (relative to the
 * encoded, where necessary, e.g. rotation angle).
 * @brief  Stream Output Configuration
 */
struct vdec_str_opconfig {
	struct pixel_pixinfo	pixel_info;
	uint8			force_oold;
};

/*
 * This type defines the "play" mode.
 * @brief  Play Mode
 */
enum vdec_play_mode {
	VDEC_PLAYMODE_PARSE_ONLY,
	VDEC_PLAYMODE_NORMAL_DECODE,
	VDEC_PLAYMODE_MAX,
	VDEC_PLAYMODE_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * This type defines the bitstream processing error info.
 * @brief  Bitstream Processing Error Info
 */
struct vdec_bstr_err_info {
	uint32	sequence_err;
	uint32	picture_err;
	uint32	other_err;
};

/*
 * This structure describes the VDEC Pan Scan Window.
 * @brief  VDEC Pan Scan Window
 */
struct vdec_window {
	uint32	ui32topoffset;
	uint32	ui32leftoffset;
	uint32	ui32width;
	uint32	ui32height;
};

/*
 * This structure contains the VDEC picture display properties.
 * @brief  VDEC Picture Display Properties
 */
struct vdec_pict_disp_info {
	struct vdec_rect	enc_disp_region;
	struct vdec_rect	disp_region;
	struct vdec_rect	raw_disp_region;
	uint8			top_fld_first;
	uint8			out_top_fld_first;
	uint32			max_frm_repeat;
	uint32			repeat_first_fld;
	uint32			num_pan_scan_windows;
	struct vdec_window	pan_scan_windows[VDEC_MAX_PANSCAN_WINDOWS];
};

/*
 * This structure contains VXD hardware signatures.
 * @brief  VXD Hardware signatures
 */
struct vdec_pict_hwcrc {
	uint8	first_fld_rcvd;
	uint32	crc_vdmc_pix_recon;
	uint32	vdeb_sysmem_wrdata;
};

struct vdec_features {
	uint8	valid;
	uint8	mpeg2;
	uint8	mpeg4;
	uint8	h264;
	uint8	vc1;
	uint8	avs;
	uint8	real;
	uint8	jpeg;
	uint8	vp6;
	uint8	vp8;
	uint8	hevc;
	uint8	hd;
	uint8	rotation;
	uint8	scaling;
	uint8	scaling_oold;
	uint8	scaling_extnd_strides;
};

/*
 * This type defines the auxiliary info for picture queued for decoding.
 * @brief  Auxiliary Decoding Picture Info
 */
struct vdec_dec_pict_auxinfo {
	uint32	seq_hdr_id;
	uint32	pps_id;
	uint32	second_pps_id;
	uint8	not_decoded;
};

/*
 * This type defines the decoded picture state.
 * @brief  Decoded Picture State
 */
enum vdec_pict_state {
	VDEC_PICT_STATE_NOT_DECODED,
	VDEC_PICT_STATE_DECODED,
	VDEC_PICT_STATE_TERMINATED,
	VDEC_PICT_STATE_MAX,
	VDEC_PICT_STATE_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * This type defines the container for various picture tags.
 * @brief  Picture Tag Container
 */
struct vdec_pict_tag_container {
	enum img_buffer_type		pict_type;
	uint64				pict_tag_param;
	uint64				sideband_info;
	struct vdec_pict_hwcrc		pict_hwcrc;
};

/*
 * This structure describes raw bitstream data chunk.
 * @brief  Raw Bitstream Data Chunk
 */
struct vdec_raw_bstr_data {
	uint32				size;
	uint32				bit_offset;
	uint8				*data;
	struct vdec_raw_bstr_data	*next;
};

/*
 * This type defines the supplementary picture data.
 * @brief  Supplementary Picture Data
 */
struct vdec_pict_supl_data {
	struct vdec_raw_bstr_data	*raw_vui_data;
	struct vdec_raw_bstr_data	*raw_sei_list_first_fld;
	struct vdec_raw_bstr_data	*raw_sei_list_second_fld;
	union {
		struct h264_pict_supl_data {
			uint8	nal_ref_idc;
			uint16	frame_num;
		} data;
	};
};

/*
 * This structure contains decoded picture information for display.
 * @brief  Decoded Picture Information
 */
struct vdec_dec_pict_info {
	enum vdec_pict_state	pict_state;
	enum img_buffer_type	buf_type;
	uint8			interlaced_flds;
	uint32			err_flags;
	uint32			err_level;
	struct vdec_pict_tag_container	first_fld_tag_container;
	struct vdec_pict_tag_container	second_fld_tag_container;
	struct vdec_str_opconfig	op_config;
	struct vdec_pict_rendinfo	rend_info;
	struct vdec_pict_disp_info	disp_info;
	uint32				last_in_seq;
	uint32				decode_id;
	uint32				id_for_hwcrc_chk;
	uint16				view_id;
	uint32				timestamp;
	struct vdec_pict_supl_data  pict_supl_data;
};

struct vdec_pict_rend_config {
	struct vdec_pict_size	coded_pict_size;
	uint8			packed;
	uint8			byte_interleave;
	uint32			stride_alignment;
};

/*
 * This structure contains unsupported feature flags.
 * @brief  Unsupported Feature Flags
 */
struct vdec_unsupp_flags {
	uint32 str_cfg;
	uint32 str_opcfg;
	uint32 op_bufcfg;
	uint32 seq_hdr;
	uint32 pict_hdr;
};

/*
 * This type defines the error , error in parsing, error in decoding etc.
 * @brief  VDEC parsing/decoding error  Information
 */
enum vdec_error_type {
	VDEC_ERROR_NONE			= (0),
	VDEC_ERROR_SR_ERROR		= (1 << 0),
	VDEC_ERROR_FEHW_TIMEOUT		= (1 << 1),
	VDEC_ERROR_FEHW_DECODE		= (1 << 2),
	VDEC_ERROR_BEHW_TIMEOUT		= (1 << 3),
	VDEC_ERROR_SERVICE_TIMER_EXPIRY	= (1 << 4),
	VDEC_ERROR_MISSING_REFERENCES	= (1 << 5),
	VDEC_ERROR_MMU_FAULT		= (1 << 6),
	VDEC_ERROR_DEVICE		= (1 << 7),
	VDEC_ERROR_CORRUPTED_REFERENCE	= (1 << 8),
	VDEC_ERROR_MMCO			= (1 << 9),
	VDEC_ERROR_MBS_DROPPED		= (1 << 10),
	VDEC_ERROR_MAX			= (1 << 11),
	VDEC_ERROR_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * This structure contains information relating to a buffer.
 * @brief  Buffer Information
 */
struct vdec_buf_info {
	void	*cpu_linear_addr;
	uint32	buf_id;
	struct vdec_pict_bufconfig	pictbuf_cfg;
	int32	fd;
	/* The following are fields used internally within VDEC... */
	uint32	buf_size;
	enum sys_emem_attrib	mem_attrib;
	void	*buf_alloc_handle;
	void	*buf_map_handle;
};

#ifdef HAS_JPEG
/*
 * This structure contains JPEG sequence header information.
 * NOTE: Should only contain JPEG specific information.
 * @brief  JPEG sequence header Information
 */
struct vdec_jpeg_sequ_hdr_info {
	/* total component in jpeg */
	uint8 num_component;
	/* precision */
	uint8 precision;
};

/*
 * This structure contains JPEG start of frame segment header
 * NOTE: Should only contain JPEG specific information.
 * @brief  JPEG SOF header Information
 */
struct vdec_jpeg_sof_component_hdr {
	/* component identifier. */
	uint8 identifier;
	/* Horizontal scaling. */
	uint8 horz_factor;
	/* Verticale scaling */
	uint8 vert_factor;
	/* Qunatisation tables . */
	uint8 quant_table;
};

/*
 * This structure contains JPEG start of scan segment header
 * NOTE: Should only contain JPEG specific information.
 * @brief  JPEG SOS header Information
 */
struct vdec_jpeg_sos_component_hdr {
	/* component identifier. */
	uint8 component_index;
	/* Huffman DC tables. */
	uint8 dc_table;
	/* Huffman AC table .*/
	uint8 ac_table;
};

struct vdec_jpeg_pict_hdr_info {
	/* Start of frame component header */
	struct vdec_jpeg_sof_component_hdr sof_comp[JPEG_VDEC_MAX_COMPONENTS];
	/* Start of Scan component header */
	struct vdec_jpeg_sos_component_hdr sos_comp[JPEG_VDEC_MAX_COMPONENTS];
	/* Huffman tables */
	struct vdec_jpeg_huffman_tableinfo huff_tables[JPEG_VDEC_TABLE_CLASS_NUM][JPEG_VDEC_MAX_SETS_HUFFMAN_TABLES];
	/* Quantization tables */
	struct vdec_jpeg_de_quant_tableinfo quant_tables[JPEG_VDEC_MAX_QUANT_TABLES];
	/* Number of MCU in the restart interval */
	uint16 interval;
	uint32 test;
};
#endif

#endif
