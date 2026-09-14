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
 * VXD Decoder Component header
 */

#ifndef __DECODER_H__
#define __DECODER_H__

#include "bspp.h"
#include "dq.h"
#ifdef HAS_JPEG
#include "jpegfw_data.h"
#endif
#include "lst.h"
#include "vdecdd_defs.h"
#include "vdec_defs.h"
#include "vid_buf.h"
#include "vxd_ext.h"
#include "vxd_props.h"
#include "hevcfw_data.h"

#define MAX_CONCURRENT_STREAMS 16

enum dec_pict_states {
	DECODER_PICTURE_STATE_TO_DECODE = 0,
	DECODER_PICTURE_STATE_DECODED,
	DECODER_PICTURE_STATE_TO_DISCARD,
	DECODER_PICTURE_STATE_MAX,
	DECODER_PICTURE_FORCE32BITS = 0x7FFFFFFFU
};

enum dec_res_type {
	DECODER_RESTYPE_TRANSACTION = 0,
	DECODER_RESTYPE_HDR,
	DECODER_RESTYPE_BATCH_MSG,
#ifdef HAS_HEVC
	DECODER_RESTYPE_PVDEC_BUF,
#endif
	DECODER_RESTYPE_MAX,
	DECODER_RESTYPE_FORCE32BITS = 0x7FFFFFFFU
};

enum dec_core_query_type {
	DECODER_CORE_GET_RES_LIMIT = 0,
	DECODER_CORE_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * @Function              pfnRefPicGetMaxNum
 * @Description
 * This is the prototype for functions calculating the maximum number
 * of reference pictures required per video standard.
 *
 * @Input    psComSequHdrInfo  : A pointer to the common VSH information
 * structure.
 *
 * @Output   pui32MaxRefPicNum :  A pointer used to return the maximum number
 *                               of reference frames required.
 *
 * @Return   IMG_RESULT : This function returns either IMG_SUCCESS or
 * an error code.
 */
typedef int32 (*ref_pic_get_maximum)
	(const struct vdec_comsequ_hdrinfo *comseq_hdr_info,
	 uint32 *max_ref_pict_num);

typedef int32 (*strunit_processed_cb)(void *handle, int32 cb_type, void *item);

typedef int32 (*core_gen_cb)(void *handle, int32 query, void *item);

struct dec_ctx;

/*
 * This structure contains the core context.
 * @brief  Decoder Core Context
 */
struct dec_core_ctx {
	void		**link; /* to be part of single linked list */
	struct dec_ctx	*dec_ctx;
	uint8		enumerated;
	uint8		master;
	uint8		configured;
	uint32		core_features;
	uint32		pipe_features[VDEC_MAX_PIXEL_PIPES];
	struct vxd_coreprops	core_props;
	void			*resources;
	void			*hw_ctx;
	uint32			cum_pics;
	uint8			busy;
};

struct dec_ctx {
	uint8		inited;
	void		*user_data;
	const struct vdecdd_dd_devconfig	*dev_cfg;
	uint32				num_pipes;
	struct dec_core_ctx		*dec_core_ctx;
	struct lst_t			str_list;
	void				*mmu_dev_handle;
	void				*dev_handle;
	struct vidio_ddbufinfo		ptd_buf_info;
	uint8				sup_stds[VDEC_STD_MAX];
	uint32				internal_heap_id;
	uint32				str_cnt;
};

/*
 * This structure contains the device decode resource (used for decoding and
 * held for subsequent decoding).
 * @brief  Decoder Device Resource
 */
struct dec_pictdec_res {
	void	**link; /* to be part of single linked list */
	uint32	transaction_id;
	struct vidio_ddbufinfo	fw_ctx_buf;
	struct vidio_ddbufinfo	h264_sgm_buf;
	uint32			ref_cnt;
};

struct dec_decpict;

/*
 *
 * This structure contains the stream context.
 * @brief  Decoder Stream Context
 */
struct dec_str_ctx {
	void	**link; /* to be part of single linked list */
	int32	km_str_id;
	struct vdec_str_configdata	config;
	struct dec_ctx			*decctx;
	void				*vxd_dec_ctx;
	void				*usr_int_data;
	void				*mmu_str_handle;
	void				*pict_idgen;
	struct lst_t			pend_strunit_list;
	struct dq_linkage_t		str_decd_pict_list;
	uint32				num_ref_res;
	struct lst_t			ref_res_lst;
	uint32				num_dec_res;
	struct lst_t			dec_res_lst;
	uint32				avail_pipes;
	uint32				avail_slots;
	struct vdecdd_decstr_status	dec_str_st;
	struct vidio_ddbufinfo		pvdec_fw_ctx_buf;
	uint32				last_fe_transaction_id;
	uint32				next_dec_pict_id;
	uint32				next_pict_id_expected;
	struct dec_pictdec_res		*cur_fe_pict_dec_res;
	struct dec_pictdec_res		*prev_fe_pict_dec_res;
	struct dec_pictdec_res		*last_be_pict_dec_res;
	struct dec_decpict		*cur_pict;
	void				*resources;
	strunit_processed_cb		str_processed_cb;
	core_gen_cb			core_query_cb;
};

/*
 * Resource Structure for DECODER_sDdResourceInfo to be used with pools
 */
struct res_resinfo {
	void			**link; /* to be part of single linked list */
	void			*res;
	struct vidio_ddbufinfo	*ddbuf_info;
};

struct vdecdd_ddstr_ctx;

/*
 * This structure contains the Decoded attributes
 * @brief Decoded attributes
 */
struct dec_pict_attrs {
	uint8		first_fld_rcvd;
	uint32		fe_err;
	uint32		no_be_wdt;
	uint32		mbs_dropped;
	uint32		mbs_recovered;
	struct vxd_pict_attrs	pict_attrs;
};

/*
 * This union contains firmware contexts. Used to allocate buffers for firmware
 * context.
 */
union dec_fw_contexts {
	struct h264fw_context_data	h264_context;
#ifdef HAS_JPEG
	struct jpegfw_context_data	jpeg_context;
#endif
#ifdef HAS_HEVC
	struct hevcfw_ctx_data	hevc_context;
#endif
};

/*
 * for debug
 */
struct dec_fwmsg {
	void			**link;
	struct dec_pict_attrs	pict_attrs;
	struct vdec_pict_hwcrc	pict_hwcrc;
};

/*
 * This structure contains the stream decode resource (persistent for
 * longer than decoding).
 * @brief  Decoder Stream Resource
 */
struct dec_pictref_res {
	void			**link; /* to be part of single linked list */
	struct vidio_ddbufinfo	fw_ctrlbuf;
	uint32			ref_cnt;
};

/*
 * This structure defines the decode picture.
 * @brief  Decoder Picture
 */
struct dec_decpict {
	void				**link;
	uint32				transaction_id;
	void				*dec_str_ctx;
	uint8				twopass;
	uint8				first_fld_rcvd;
	struct res_resinfo		*transaction_info;
	struct res_resinfo		*hdr_info;
#ifdef HAS_HEVC
	struct res_resinfo		*pvdec_info;
	uint32				temporal_out_addr;
#endif
	struct vdecdd_ddpict_buf	*recon_pict;
	struct vdecdd_ddpict_buf	*alt_pict;
	struct res_resinfo		*batch_msginfo;
	struct vidio_ddbufinfo		*intra_bufinfo;
	struct vidio_ddbufinfo		*auxline_bufinfo;
	struct vidio_ddbufinfo		*vlc_tables_bufinfo;
	struct vidio_ddbufinfo		*vlc_idx_tables_bufinfo;
	struct vidio_ddbufinfo		*start_code_bufinfo;
	struct dec_fwmsg		*first_fld_fwmsg;
	struct dec_fwmsg		*second_fld_fwmsg;
	struct bspp_pict_hdr_info	*pict_hdr_info;
	struct dec_pictdec_res		*cur_pict_dec_res;
	struct dec_pictdec_res		*prev_pict_dec_res;
	struct dec_pictref_res		*pict_ref_res;
	struct lst_t			dec_pict_seg_list;
	struct lst_t			fragment_list;
	uint8				eop_found;
	uint32				operating_op;
	uint16				genc_id;
	struct vdecdd_ddbuf_mapinfo	**genc_bufs;
	struct vdecdd_ddbuf_mapinfo	*genc_fragment_buf;
	uint32				ctrl_alloc_bytes;
	uint32				ctrl_alloc_offset;
	enum dec_pict_states		state;
	struct vidio_ddbufinfo		*str_pvdec_fw_ctxbuf;
};

/*
 *
 * This structure defines the decode picture reference.
 * @brief  Decoder Picture Reference
 */
struct dec_str_unit {
	void			**link; /* to be part of single linked list */
	struct dec_decpict	*dec_pict;
	struct vdecdd_str_unit	*str_unit;
};

/*
 * This structure defines the decoded picture.
 * @brief  Decoded Picture
 */
struct dec_decoded_pict {
	struct dq_linkage_t	link; /* to be part of double linked list */
	uint32			transaction_id;
	uint8			processed;
	uint8			process_failed;
	uint8			force_display;
	uint8			displayed;
	uint8			merged;
	uint32			disp_idx;
	uint32			rel_idx;
	struct vdecdd_picture	*pict;
	struct dec_fwmsg	*first_fld_fwmsg;
	struct dec_fwmsg	*second_fld_fwmsg;
	struct dec_pictref_res	*pict_ref_res;
};

struct dec_pict_fragment {
	void	**link; /* to be part of single linked list */
	/* Control allocation size in bytes */
	uint32	ctrl_alloc_bytes;
	/* Control allocation offset in bytes */
	uint32	ctrl_alloc_offset;
};

/*
 * This structure contains the pointer to the picture segment.
 * All the segments could be added to the list in struct dec_decpict,
 * but because list items cannot belong to more than one list this wrapper
 * is used which is added in the list sDecPictSegList inside struct dec_decpict
 * @brief  Decoder Picture Segment
 */
struct dec_decpict_seg {
	void			**link; /* to be part of single linked list */
	struct bspp_bitstr_seg	*bstr_seg;
	uint8			internal_seg;
};

struct decoder_regsoffsets {
	uint32	vdmc_cmd_offset;
	uint32	vec_offset;
	uint32	entropy_offset;
	uint32	vec_be_regs_offset;
	uint32	vdec_be_codec_regs_offset;
};

int32 decoder_initialise(void *init_usr_data, uint32 internal_heap_id,
		       struct vdecdd_dd_devconfig *dd_devcfg, uint32 *num_pipes,
		       void **dec_ctx);

int32 decoder_deinitialise(void *dec_ctx);

int32 decoder_supported_features(void *dec_ctx, struct vdec_features *features);

int32 decoder_stream_destroy(void *dec_str_ctx, uint8  abort);

int32 decoder_stream_create(void *dec_ctx, struct vdec_str_configdata str_cfg,
			  uint32 kmstr_id, void **mmu_str_handle,
			  void *vxd_dec_ctx, void *str_usr_int_data,
			  void **dec_str_ctx, void *decoder_cb, void *query_cb);

int32 decoder_stream_prepare_ctx(void *dec_str_ctx, uint8 flush_dpb);

int32 decoder_stream_process_unit(void *dec_str_ctx,
				struct vdecdd_str_unit *str_unit);

int32 decoder_get_load(void *dec_str_ctx, uint32 *avail_slots);

int32
decoder_check_support(void *dec_ctx,
		      const struct vdec_str_configdata *str_cfg,
		      const struct vdec_str_opconfig *op_cfg,
		      const struct vdecdd_ddpict_buf *disp_pictbuf,
		      const struct vdec_pict_rendinfo *req_pict_rendinfo,
		      const struct vdec_comsequ_hdrinfo *comseq_hdrinfo,
		      const struct bspp_pict_hdr_info *pict_hdrinfo,
		      const struct vdec_comsequ_hdrinfo *prev_comseq_hdrinfo,
		      const struct bspp_pict_hdr_info *prev_pict_hdrinfo,
		      uint8 non_cfg_req, struct vdec_unsupp_flags *unsupported,
		      uint32 *features);

uint8 decoder_is_stream_idle(void *dec_str_ctx);

int32 decoder_stream_flush(void *dec_str_ctx, uint8 discard_refs);

int32 decoder_stream_release_buffers(void *dec_str_ctx);

int32 decoder_stream_get_status(void *dec_str_ctx,
			      struct vdecdd_decstr_status *dec_str_st);

int32 decoder_service_firmware_response(void *dec_str_ctx_arg, uint32 *msg,
				      uint32 msg_size, uint32 msg_flags);

#endif
