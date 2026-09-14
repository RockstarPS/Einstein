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
 * VXD Decoder Component function implementations
 */

#include "osal/inc/osa_mem.h"
#include "osal/inc/osa_err.h"

#include "decoder.h"
#include "dec_resources.h"
#include "dq.h"
#include "hw_control.h"
#include "h264fw_data.h"
#include "idgen_api.h"
#include "img_errors.h"
#ifdef HAS_JPEG
#include "jpegfw_data.h"
#endif
#include "lst.h"
#include "pool_api.h"
#include "resource.h"
#include "translation_api.h"
#include "vdecdd_utils.h"
#include "vdec_mmu_wrapper.h"
#include "vxd_dec.h"

#define CORE_NUM_DECODE_SLOTS 2

#define MAX_PLATFORM_SUPPORTED_HEIGHT 65536
#define MAX_PLATFORM_SUPPORTED_WIDTH 65536

#define MAX_CONCURRENT_STREAMS 16

/* Maximum number of unique picture ids within stream. */
#define DECODER_MAX_PICT_ID	GET_STREAM_PICTURE_ID(((1ULL << 32) - 1ULL))

/* Maximum number of concurrent pictures within stream. */
#define DECODER_MAX_CONCURRENT_PICT	0x100

static inline uint32 get_next_picture_id(uint32 cur_pict_id)
{
	return(cur_pict_id == FWIF_BIT_MASK(FWIF_NUMBITS_STREAM_PICTURE_ID) ?
	       1 : cur_pict_id + 1);
}

static inline uint32 get_prev_picture_id(uint32 cur_pict_id)
{
	return(cur_pict_id == 1 ?
	       FWIF_BIT_MASK(FWIF_NUMBITS_STREAM_PICTURE_ID) :
	       cur_pict_id - 1);
}

#define H264_SGM_BUFFER_BYTES_PER_MB  1
#define H264_SGM_MAX_MBS              3600

#define CONTEXT_BUFF_SIZE	(72)

/*
 * Number of bits in transaction ID used to represent
 * picture number in stream.
 */
#define FWIF_NUMBITS_STREAM_PICTURE_ID          16
/*
 * Number of bits in transaction ID used to represent
 * picture number in core.
 */
#define FWIF_NUMBITS_CORE_PICTURE_ID            4
/*
 * Number of bits in transaction ID used to represent
 * stream id.
 */
#define FWIF_NUMBITS_STREAM_ID                  8
/* Number of bits in transaction ID used to represent core id. */
#define FWIF_NUMBITS_CORE_ID                    4

/* Offset in transaction ID to picture number in stream. */
#define FWIF_OFFSET_STREAM_PICTURE_ID           0
/* Offset in transaction ID to picture number in core. */
#define FWIF_OFFSET_CORE_PICTURE_ID	(FWIF_OFFSET_STREAM_PICTURE_ID + \
					 FWIF_NUMBITS_STREAM_PICTURE_ID)
/* Offset in transaction ID to stream id. */
#define FWIF_OFFSET_STREAM_ID		(FWIF_OFFSET_CORE_PICTURE_ID + \
					 FWIF_NUMBITS_CORE_PICTURE_ID)
/* Offset in transaction ID to core id. */
#define FWIF_OFFSET_CORE_ID		(FWIF_OFFSET_STREAM_ID + \
					 FWIF_NUMBITS_STREAM_ID)

/* Maximum number of unique picture ids within stream. */
#define DECODER_MAX_PICT_ID GET_STREAM_PICTURE_ID(((1ULL << 32) - 1ULL))

/* Maximum number of concurrent pictures within stream. */
#define DECODER_MAX_CONCURRENT_PICT     0x100

#define CREATE_TRANSACTION_ID(core_id, stream_id, core_pic, stream_pic) \
		(SET_CORE_ID((core_id)) | SET_STREAM_ID((stream_id)) | \
		SET_CORE_PICTURE_ID((core_pic)) | SET_STREAM_PICTURE_ID((stream_pic)))

static inline struct dec_core_ctx *decoder_str_ctx_to_core_ctx(struct dec_str_ctx *decstrctx)
{
	if (decstrctx && decstrctx->decctx)
		return decstrctx->decctx->dec_core_ctx;

	else
		return NULL;
}

static const struct vdecdd_dd_devconfig def_dev_cfg = {
	CORE_NUM_DECODE_SLOTS,       /* ui32NumSlotsPerPipe; */
};

/*
 * This array defines names of the VDEC standards.
 * Shall be in sync with #VDEC_eVidStd
 * @brief  Names of the VDEC standards
 */
static const char *vid_std_names[] = {
	"VDEC_STD_UNDEFINED",
	"VDEC_STD_MPEG2",
	"VDEC_STD_MPEG4",
	"VDEC_STD_H263",
	"VDEC_STD_H264",
	"VDEC_STD_VC1",
	"VDEC_STD_AVS",
	"VDEC_STD_REAL",
	"VDEC_STD_JPEG",
	"VDEC_STD_VP6",
	"VDEC_STD_VP8",
	"VDEC_STD_SORENSON",
	"VDEC_STD_HEVC"
};

#ifdef ERROR_RECOVERY_SIMULATION
extern int fw_error_value;
#endif

/*
 * @Function decoder_set_device_config
 */
static int32
decoder_set_device_config(const struct vdecdd_dd_devconfig **dd_dev_config)
{
	struct vdecdd_dd_devconfig *local_dev_cfg;

	VDEC_ASSERT(dd_dev_config);

	/* Allocate device configuration structure */
	local_dev_cfg = osa_zalloc(sizeof(*local_dev_cfg), OSA_GFP_KERNEL);
	VDEC_ASSERT(local_dev_cfg);
	if (!local_dev_cfg)
		return IMG_ERROR_OUT_OF_MEMORY;

	/* Set the default device configuration */
	*local_dev_cfg = def_dev_cfg;

	*dd_dev_config = local_dev_cfg;

	return IMG_SUCCESS;
}

/*
 * @Function  decoder_set_feature_flags
 * @Description
 * This function sets the features flags from the core properties.
 * @Input     p                     : Pointer to core properties.
 * @Input     core_feat_flags : Pointer to core feature flags word.
 */
static void decoder_set_feature_flags(struct vxd_coreprops *core_props,
				      uint32 *core_feat_flags,
				      uint32 *pipe_feat_flags)
{
	uint8 pipe_minus_one;

	VDEC_ASSERT(core_props);
	VDEC_ASSERT(core_feat_flags);
	VDEC_ASSERT(pipe_feat_flags);

	for (pipe_minus_one = 0; pipe_minus_one < core_props->num_pixel_pipes;
	    pipe_minus_one++) {
		*core_feat_flags |= pipe_feat_flags[pipe_minus_one] |=
					core_props->h264[pipe_minus_one] ?
					VDECDD_COREFEATURE_H264 : 0;
#ifdef HAS_JPEG
		*core_feat_flags |= pipe_feat_flags[pipe_minus_one] |=
					core_props->jpeg[pipe_minus_one] ?
					VDECDD_COREFEATURE_JPEG : 0;
#endif
#ifdef HAS_HEVC
		*core_feat_flags |= pipe_feat_flags[pipe_minus_one] |=
					core_props->hevc[pipe_minus_one] ?
					VDECDD_COREFEATURE_HEVC : 0;
#endif
	}
}

/*
 * @Function  decoder_stream_get_context
 * @Description
 * This function returns the stream context structure for the given
 * stream handle.
 * @Return    struct dec_str_ctx : This function returns a pointer
 * to the stream
 *                            context structure or NULL if not found.
 */
static struct dec_str_ctx *decoder_stream_get_context(void *dec_str_context)
{
	return (struct dec_str_ctx *)dec_str_context;
}

/*
 * @Function decoder_core_enumerate
 * @Description
 * This function enumerates a decoder core and returns its handle.
 * Usage: before calls to other DECODE_Core or DECODE_Stream functions.
 * @Input     dec_context : Pointer to Decoder context.
 * @Input     dev_cfg : Device configuration.
 * @Return    This function returns either IMG_SUCCESS or an
 * error code.
 */
static int32 decoder_core_enumerate(struct dec_ctx *dec_context,
				  const struct vdecdd_dd_devconfig *dev_cfg,
				  uint32 *num_pipes)
{
	struct dec_core_ctx *dec_core_ctx_local;
	uint32 ret;
	uint32 ptd_align = DEV_MMU_PAGE_ALIGNMENT;

	/* Create the core. */
	dec_core_ctx_local = osa_zalloc(sizeof(*dec_core_ctx_local), OSA_GFP_KERNEL);
	if (!dec_core_ctx_local)
		return IMG_ERROR_OUT_OF_MEMORY;

	dec_core_ctx_local->dec_ctx = (struct dec_ctx *)dec_context;

	/* Initialise the hwctrl block here */
	ret = hwctrl_initialise(dec_core_ctx_local, dec_context->user_data,
				dev_cfg, &dec_core_ctx_local->core_props,
				&dec_core_ctx_local->hw_ctx);
	if (ret != IMG_SUCCESS)
		goto error;

	decoder_set_feature_flags(&dec_core_ctx_local->core_props,
				  &dec_core_ctx_local->core_features,
				  dec_core_ctx_local->pipe_features);

	/* Perform device setup for master core. */
	if (num_pipes)
		*num_pipes = dec_core_ctx_local->core_props.num_pixel_pipes;

	/* DEVA PVDEC FW requires PTD to be 64k aligned. */
	ptd_align = 0x10000;

	/* Create a device MMU context. */
	ret = mmu_device_create(dec_core_ctx_local->core_props.mmu_type,
				ptd_align, &dec_context->mmu_dev_handle);
	VDEC_ASSERT(ret == IMG_SUCCESS);
	if (ret != IMG_SUCCESS)
		goto error;

	dec_core_ctx_local->enumerated = osa_true;

	dec_context->dec_core_ctx = dec_core_ctx_local;

	return IMG_SUCCESS;

error:
	if (dec_core_ctx_local) {
		uint32 deinit_result = IMG_SUCCESS;

		/* Destroy a device MMU context. */
		if (dec_context->mmu_dev_handle) {
			deinit_result =
			mmu_device_destroy(dec_context->mmu_dev_handle);
			VDEC_ASSERT(deinit_result == IMG_SUCCESS);
			if (deinit_result != IMG_SUCCESS)
				OSA_PR_WARN("MMU_DeviceDestroy() failed to tidy-up after error");
		}

		osa_free(dec_core_ctx_local);
		dec_core_ctx_local = NULL;
	}

	return ret;
}

/*
 * @Function  decoder_initialise
 */
int32 decoder_initialise(void *user_init_data, uint32 int_heap_id,
		       struct vdecdd_dd_devconfig *dd_device_config,
		       uint32 *num_pipes,
		       void **dec_ctx_handle)
{
	struct dec_ctx *dec_context = (struct dec_ctx *)*dec_ctx_handle;
	int32 ret;

	if (!dec_context) {
		dec_context = osa_zalloc(sizeof(*dec_context), OSA_GFP_KERNEL);
		VDEC_ASSERT(dec_context);
		if (!dec_context)
			return IMG_ERROR_OUT_OF_MEMORY;

		*dec_ctx_handle = dec_context;
	}

	/* Determine which standards are supported. */
	memset(&dec_context->sup_stds, 0x0,
	       sizeof(dec_context->sup_stds[VDEC_STD_MAX]));

	dec_context->sup_stds[VDEC_STD_H264] = osa_true;
#ifdef HAS_HEVC
	dec_context->sup_stds[VDEC_STD_HEVC] = osa_true;
#endif
	if (!dec_context->inited) {
		/* Check and store input parameters. */
		dec_context->user_data = user_init_data;
		dec_context->dev_handle =
			((struct vdecdd_dddev_context *)user_init_data)->dev_handle;

		/* Initialise the context lists. */
		lst_init(&dec_context->str_list);

		/* Make sure POOL API is initialised */
		ret = pool_init();
		if (ret != IMG_SUCCESS)
			goto pool_init_error;

		ret = decoder_set_device_config(&dec_context->dev_cfg);
		VDEC_ASSERT(ret == IMG_SUCCESS);
		if (ret != IMG_SUCCESS)
			goto error;

		dec_context->internal_heap_id = int_heap_id;

		/* Enumerate the master core. */
		ret = decoder_core_enumerate(dec_context, dec_context->dev_cfg,
					     &dec_context->num_pipes);
		if (ret != IMG_SUCCESS)
			goto error;

		if (dd_device_config)
			*dd_device_config = *dec_context->dev_cfg;

		if (num_pipes)
			*num_pipes = dec_context->num_pipes;

		dec_context->inited = osa_true;
	}

	return IMG_SUCCESS;

error:
	pool_deinit();

pool_init_error:
	if (dec_context->dev_cfg) {
		 osa_free((void *)dec_context->dev_cfg);
		dec_context->dev_cfg = NULL;
	}

	osa_free(*dec_ctx_handle);
	*dec_ctx_handle = NULL;

	return ret;
}

/*
 * @Function  decoder_supported_features
 */
int32 decoder_supported_features(void *dec_ctx, struct vdec_features *features)
{
	struct dec_ctx *dec_context = (struct dec_ctx *)dec_ctx;
	struct dec_core_ctx *dec_core_ctx_local;

	/* Check input parameters. */
	VDEC_ASSERT(dec_context);
	VDEC_ASSERT(features);
	if (!dec_context || !features) {
		OSA_PR_ERR("Invalid parameters!");
		return IMG_ERROR_INVALID_PARAMETERS;
	}

	/* Ensure that Decoder component is initialised. */
	VDEC_ASSERT(dec_context->inited);

	/* Loop over all cores checking for support. */
	dec_core_ctx_local = dec_context->dec_core_ctx;
	VDEC_ASSERT(dec_core_ctx_local);

	/*
	 * Determine whether the required core attribute
	 * is present to support requested feature
	 */
	features->h264     |= (dec_core_ctx_local->core_features &
			       VDECDD_COREFEATURE_H264) ? osa_true : osa_false;
	features->mpeg2    |= (dec_core_ctx_local->core_features &
			       VDECDD_COREFEATURE_MPEG2) ? osa_true : osa_false;
	features->mpeg4    |= (dec_core_ctx_local->core_features &
			       VDECDD_COREFEATURE_MPEG4) ? osa_true : osa_false;
	features->vc1      |= (dec_core_ctx_local->core_features &
			       VDECDD_COREFEATURE_VC1) ? osa_true : osa_false;
	features->avs      |= (dec_core_ctx_local->core_features &
			       VDECDD_COREFEATURE_AVS) ? osa_true : osa_false;
	features->real     |= (dec_core_ctx_local->core_features &
			       VDECDD_COREFEATURE_REAL) ? osa_true : osa_false;
	features->jpeg     |= (dec_core_ctx_local->core_features &
			       VDECDD_COREFEATURE_JPEG) ? osa_true : osa_false;
	features->vp6      |= (dec_core_ctx_local->core_features &
			       VDECDD_COREFEATURE_VP6) ? osa_true : osa_false;
	features->vp8      |= (dec_core_ctx_local->core_features &
			       VDECDD_COREFEATURE_VP8) ? osa_true : osa_false;
	features->hd       |= (dec_core_ctx_local->core_features &
			       VDECDD_COREFEATURE_HD_DECODE) ? osa_true : osa_false;
	features->rotation |= (dec_core_ctx_local->core_features &
			       VDECDD_COREFEATURE_ROTATION) ? osa_true : osa_false;
	features->scaling  |= (dec_core_ctx_local->core_features &
			       VDECDD_COREFEATURE_SCALING) ? osa_true : osa_false;
	features->hevc     |= (dec_core_ctx_local->core_features &
			       VDECDD_COREFEATURE_HEVC) ? osa_true : osa_false;

	return IMG_SUCCESS;
}

/*
 * @Function decoder_stream_get_status
 */
int32 decoder_stream_get_status(void *dec_str_ctx_handle,
			      struct vdecdd_decstr_status *dec_str_st)
{
	struct dec_str_ctx *dec_str_ctx;
	struct dec_decoded_pict *decoded_pict;
	struct dec_core_ctx *dec_core_ctx;
	uint32 item;

	VDEC_ASSERT(dec_str_st);
	if (!dec_str_st) {
		OSA_PR_ERR("Invalid decoder streams status pointer!");
		return IMG_ERROR_INVALID_PARAMETERS;
	}

	dec_str_ctx = decoder_stream_get_context(dec_str_ctx_handle);
	VDEC_ASSERT(dec_str_ctx);
	if (!dec_str_ctx) {
		OSA_PR_ERR("Invalid decoder stream context handle!");
		return IMG_ERROR_INVALID_PARAMETERS;
	}

	/* Obtain the state of each core. */
	dec_core_ctx = decoder_str_ctx_to_core_ctx(dec_str_ctx);
	VDEC_ASSERT(dec_core_ctx);

	/*
	 * Obtain the display and release list of first unprocessed
	 * picture in decoded list
	 */
	dec_str_ctx->dec_str_st.display_pics = 0;
	dec_str_ctx->dec_str_st.release_pics = 0;
	decoded_pict = dq_first(&dec_str_ctx->str_decd_pict_list);
	while (decoded_pict) {
		/* if this is the first unprocessed picture */
		if (!decoded_pict->processed) {
			uint32 idx;
			struct vdecfw_buffer_control *buf_ctrl;

			VDEC_ASSERT(decoded_pict->pict_ref_res);
			buf_ctrl =
				(struct vdecfw_buffer_control *)decoded_pict->pict_ref_res->fw_ctrlbuf.cpu_virt;
			VDEC_ASSERT(buf_ctrl);

			/* Get display pictures */
			idx = decoded_pict->disp_idx;
			item = dec_str_ctx->dec_str_st.display_pics;
			while (idx < buf_ctrl->display_list_length &&
			       item < VDECFW_MAX_NUM_PICTURES) {
				dec_str_ctx->dec_str_st.next_display_items[item] =
								buf_ctrl->display_list[idx];
				dec_str_ctx->dec_str_st.next_display_item_parent[item] =
								decoded_pict->transaction_id;
				idx++;
				item++;
			}
			dec_str_ctx->dec_str_st.display_pics = item;

			/* Get release pictures */
			idx = decoded_pict->rel_idx;
			item = dec_str_ctx->dec_str_st.release_pics;
			while (idx < buf_ctrl->release_list_length &&
			       item < VDECFW_MAX_NUM_PICTURES) {
				dec_str_ctx->dec_str_st.next_release_items[item] =
								buf_ctrl->release_list[idx];
				dec_str_ctx->dec_str_st.next_release_item_parent[item] =
								decoded_pict->transaction_id;
				idx++;
				item++;
			}
			dec_str_ctx->dec_str_st.release_pics = item;
			break;
		}

		if (decoded_pict != dq_last(&dec_str_ctx->str_decd_pict_list))
			decoded_pict = dq_next(decoded_pict);
		else
			decoded_pict = NULL;
	}

	/* Get list of held decoded pictures */
	item = 0;
	decoded_pict = dq_first(&dec_str_ctx->str_decd_pict_list);
	while (decoded_pict) {
		dec_str_ctx->dec_str_st.decoded_picts[item] =
						decoded_pict->transaction_id;
		item++;

		if (decoded_pict != dq_last(&dec_str_ctx->str_decd_pict_list))
			decoded_pict = dq_next(decoded_pict);
		else
			decoded_pict = NULL;
	}

	VDEC_ASSERT(item == dec_str_ctx->dec_str_st.num_pict_decoded);
	*dec_str_st = dec_str_ctx->dec_str_st;

	return IMG_SUCCESS;
}

/*
 * @Function  decoder_deinitialise
 */
int32 decoder_deinitialise(void *dec_ctx)
{
	struct dec_ctx *dec_context = (struct dec_ctx *)dec_ctx;
	int32 ret;
	/*  Remove and free all core context structures */
	struct dec_decpict *dec_pict;

	if (dec_context && dec_context->inited) {
		struct dec_core_ctx *dec_core_ctx_local =
					dec_context->dec_core_ctx;

		if (!dec_core_ctx_local) {
			OSA_PR_WARN("%s %d NULL Decoder context passed", __func__, __LINE__);
			VDEC_ASSERT(0);
			return -OSA_EFAULT;
		}

		/* Stream list should be empty. */
		if (!lst_empty(&dec_context->str_list))
			OSA_PR_WARN("%s %d stream list should be empty", __func__, __LINE__);

		/*
		 * All cores should now be idle since there are no
		 * connections/streams.
		 */
		ret = hwctrl_peekheadpiclist(dec_core_ctx_local->hw_ctx,
					     &dec_pict);
		VDEC_ASSERT(ret != IMG_SUCCESS);

		/* Remove and free core context structure */
		dec_core_ctx_local = dec_context->dec_core_ctx;
		VDEC_ASSERT(dec_core_ctx_local);

		hwctrl_deinitialise(dec_core_ctx_local->hw_ctx);

		osa_free(dec_core_ctx_local);
		dec_core_ctx_local = NULL;

		VDEC_ASSERT(dec_context->dev_cfg);
		if (dec_context->dev_cfg)
			osa_free((void *)dec_context->dev_cfg);

		dec_context->user_data = NULL;

		pool_deinit();

		/* Destroy a device MMU context. */
		ret = mmu_device_destroy(dec_context->mmu_dev_handle);
		VDEC_ASSERT(ret == IMG_SUCCESS);
		if (ret != IMG_SUCCESS)
			return ret;

		dec_context->inited = osa_false;

		osa_free(dec_context);
	} else {
		OSA_PR_ERR("Decoder has not been initialised so cannot be de-initialised");
		return IMG_ERROR_NOT_INITIALISED;
	}

	OSA_PR_DEBUG("Decoder deinitialise successfully\n");
	return IMG_SUCCESS;
}

/*
 * @Function   decoder_picture_destroy
 * @Description
 * Free the picture container and optionally release image buffer back to
 * client.
 * Default is to decrement the reference count held by this picture.
 */
static int32 decoder_picture_destroy(struct dec_str_ctx *dec_str_ctx,
				   uint32 pict_id, uint8 release_image)
{
	struct vdecdd_picture *picture;
	int32 ret;

	VDEC_ASSERT(dec_str_ctx);

	ret = idgen_gethandle(dec_str_ctx->pict_idgen, pict_id,
			      (void **)&picture);
	if (ret == IMG_SUCCESS) {
		VDEC_ASSERT(picture);
		ret = idgen_freeid(dec_str_ctx->pict_idgen, pict_id);
		VDEC_ASSERT(ret == IMG_SUCCESS);
		if (ret != IMG_SUCCESS)
			return ret;

		if (picture->dec_pict_info) {
			/* Destroy the picture */
			osa_free(picture->dec_pict_info);
			picture->dec_pict_info = NULL;
		}

		/* Return unused picture and internal resources */
		if (picture->disp_pict_buf.pict_buf) {
			if (release_image)
				resource_item_release(&picture->disp_pict_buf.pict_buf->ddbuf_info.ref_count);
			else
				resource_item_return(&picture->disp_pict_buf.pict_buf->ddbuf_info.ref_count);

			memset(&picture->disp_pict_buf, 0,
			       sizeof(picture->disp_pict_buf));
		}

		if (picture->pict_res_int) {
			resource_item_return(&picture->pict_res_int->ref_cnt);
			picture->pict_res_int = NULL;
		}

		osa_free(picture);
		picture = NULL;
	} else {
		VDEC_ASSERT(ret == IMG_SUCCESS);
		return ret;
	}

	return IMG_SUCCESS;
}

/*
 * @Function decoder_decoded_picture_destroy
 */
static int32
decoder_decoded_picture_destroy(struct dec_str_ctx *dec_str_ctx,
				struct dec_decoded_pict *decoded_pict,
				uint8 release_image)
{
	int32 ret;

	VDEC_ASSERT(dec_str_ctx);
	VDEC_ASSERT(decoded_pict);

	if (decoded_pict->pict) {
		VDEC_ASSERT(decoded_pict->pict->pict_id ==
			    GET_STREAM_PICTURE_ID(decoded_pict->transaction_id));

		ret = decoder_picture_destroy(dec_str_ctx,
					      decoded_pict->pict->pict_id,
					      release_image);
		VDEC_ASSERT(ret == IMG_SUCCESS);
		if (ret != IMG_SUCCESS)
			return ret;

		decoded_pict->pict = NULL;
	}

	dq_remove(decoded_pict);
	dec_str_ctx->dec_str_st.num_pict_decoded--;

	resource_item_return(&decoded_pict->pict_ref_res->ref_cnt);

	OSA_PR_INFO("[USERSID=0x%08X] [TID=0x%08X] COMPLETE",
		GET_STREAM_ID(decoded_pict->transaction_id),
		decoded_pict->transaction_id);

	osa_free(decoded_pict->first_fld_fwmsg);
	decoded_pict->first_fld_fwmsg = NULL;

	osa_free(decoded_pict->second_fld_fwmsg);
	decoded_pict->second_fld_fwmsg = NULL;

	osa_free(decoded_pict);
	decoded_pict = NULL;

	return IMG_SUCCESS;
}

/*
 * @Function  decoder_stream_decode_resource_destroy
 */
static int32 decoder_stream_decode_resource_destroy(void *item,
						  void *free_cb_param)
{
	struct dec_pictdec_res *pict_dec_res = item;
	struct dec_str_ctx *dec_str_ctx_local =
		(struct dec_str_ctx *)free_cb_param;
	int32 ret;

	VDEC_ASSERT(pict_dec_res);
	VDEC_ASSERT(resource_item_isavailable(&pict_dec_res->ref_cnt));

	/* Free memory (device-based) to store fw contexts for stream. */
	ret = mmu_free_mem(dec_str_ctx_local->mmu_str_handle,
			   &pict_dec_res->fw_ctx_buf);
	VDEC_ASSERT(ret == IMG_SUCCESS);
	if (ret != IMG_SUCCESS)
		return ret;

	if (pict_dec_res->h264_sgm_buf.hndl_memory) {
		/* Free memory (device-based) to store SGM. */
		ret = mmu_free_mem(dec_str_ctx_local->mmu_str_handle,
				   &pict_dec_res->h264_sgm_buf);
		VDEC_ASSERT(ret == IMG_SUCCESS);
		if (ret != IMG_SUCCESS)
			return ret;
	}

	osa_free(pict_dec_res);

	return IMG_SUCCESS;
}

/*
 * @Function  decoder_stream_release_buffers
 */
int32 decoder_stream_release_buffers(void *dec_str_ctx_handle)
{
	struct dec_str_ctx *dec_str_ctx;
	struct dec_decoded_pict *decoded_pict;
	int32 ret;

	dec_str_ctx = decoder_stream_get_context(dec_str_ctx_handle);

	/* Decoding queue should be empty since we are stopped */
	VDEC_ASSERT(dec_str_ctx);
	if (!dec_str_ctx) {
		OSA_PR_ERR("Invalid decoder stream context handle!");
		return IMG_ERROR_INVALID_PARAMETERS;
	}
	VDEC_ASSERT(lst_empty(&dec_str_ctx->pend_strunit_list));

	/* Destroy all pictures in the decoded list */
	decoded_pict = dq_first(&dec_str_ctx->str_decd_pict_list);
	while (decoded_pict) {
		ret = decoder_decoded_picture_destroy(dec_str_ctx,
						      decoded_pict, osa_true);
		VDEC_ASSERT(ret == IMG_SUCCESS);
		if (ret != IMG_SUCCESS)
			return ret;

	decoded_pict = dq_first(&dec_str_ctx->str_decd_pict_list);
	}

	/* if and only if the output buffers were used for reference. */
	if (dec_str_ctx->last_be_pict_dec_res) {
		/*
		 * Clear the firmware context so that reference pictures
		 * are no longer referred to.
		 */
		memset(dec_str_ctx->last_be_pict_dec_res->fw_ctx_buf.cpu_virt,
		       0,
		       dec_str_ctx->last_be_pict_dec_res->fw_ctx_buf.buf_size);
	}

	return IMG_SUCCESS;
}

/*
 * @Function  decoder_stream_reference_resource_destroy
 */
static int32 decoder_stream_reference_resource_destroy(void *item,
						     void *free_cb_param)
{
	struct dec_pictref_res  *pict_ref_res = item;
	struct dec_str_ctx *dec_str_ctx_local =
		(struct dec_str_ctx *)free_cb_param;
	int32 ret;

	VDEC_ASSERT(pict_ref_res);
	VDEC_ASSERT(resource_item_isavailable(&pict_ref_res->ref_cnt));

	/* Free memory (device-based) to store fw contexts for stream */
	ret = mmu_free_mem(dec_str_ctx_local->mmu_str_handle,
			   &pict_ref_res->fw_ctrlbuf);
	VDEC_ASSERT(ret == IMG_SUCCESS);
	if (ret != IMG_SUCCESS)
		return ret;

	osa_free(pict_ref_res);

	return IMG_SUCCESS;
}

/*
 * @Function decoder_stream_destroy
 */
int32 decoder_stream_destroy(void *dec_str_context, uint8 abort)
{
	struct dec_str_ctx *dec_str_ctx_local;
	struct dec_str_unit *dec_str_unit_local;
	struct dec_decoded_pict *decoded_pict_local;
	uint32 i;
	int32 ret;
	uint32 pict_id;
	void **res_handle_local;

	/* Required for getting segments from decode picture to free */
	struct dec_decpict_seg *dec_pict_seg_local;
	struct dec_ctx *dec_context;
	struct dec_core_ctx *dec_core_ctx_local;

	/* Get the Decoder stream context. */
	dec_str_ctx_local = decoder_stream_get_context(dec_str_context);

	VDEC_ASSERT(dec_str_ctx_local);
	if (!dec_str_ctx_local) {
		OSA_PR_ERR("Invalid decoder stream context handle!");
		return osa_false;
	}
	VDEC_ASSERT(dec_str_ctx_local->decctx);

	/* Decrement the stream count */
	dec_str_ctx_local->decctx->str_cnt--;

	/*
	 * Ensure that there are no pictures for this stream outstanding
	 * on any decoder cores.
	 * This should not be removed, it is important to see it if
	 * it ever happens.
	 * In practice we see it many times with Application Timeout.
	 */
	if (!abort)
		VDEC_ASSERT(lst_empty(&dec_str_ctx_local->pend_strunit_list));

	/*
	 * At this point all resources for the stream are guaranteed to
	 * not be used and no further hardware interrupts will be received.
	 */

	/* Destroy all stream units submitted for processing. */
	dec_str_unit_local =
		lst_removehead(&dec_str_ctx_local->pend_strunit_list);
	while (dec_str_unit_local) {
		/* If the unit was submitted for decoding (picture)... */
		if (dec_str_unit_local->dec_pict) {
			/*
			 * Explicitly remove picture from core decode queue
			 * and destroy.
			 */
			struct dec_core_ctx *dec_core_ctx_local =
				decoder_str_ctx_to_core_ctx(dec_str_ctx_local);
			VDEC_ASSERT(dec_core_ctx_local);

			res_handle_local = &dec_str_ctx_local->resources;

			if(!dec_core_ctx_local) {
				VDEC_ASSERT(0);
				return -OSA_EINVAL;
			}

			hwctrl_removefrom_piclist(dec_core_ctx_local->hw_ctx,
						  dec_str_unit_local->dec_pict);

			/* Free decoder picture */
			osa_free(dec_str_unit_local->dec_pict->first_fld_fwmsg);
			dec_str_unit_local->dec_pict->first_fld_fwmsg = NULL;

			osa_free(dec_str_unit_local->dec_pict->second_fld_fwmsg);
			dec_str_unit_local->dec_pict->second_fld_fwmsg = NULL;

			dec_res_picture_detach(res_handle_local, dec_str_unit_local->dec_pict);

			/* Free all the segments of the picture */
			dec_pict_seg_local =
			lst_removehead(&dec_str_unit_local->dec_pict->dec_pict_seg_list);
			while (dec_pict_seg_local) {
				if (dec_pict_seg_local->internal_seg) {
					VDEC_ASSERT(dec_pict_seg_local->bstr_seg);
					osa_free(dec_pict_seg_local->bstr_seg);
					dec_pict_seg_local->bstr_seg = NULL;
				}

				osa_free(dec_pict_seg_local);
				dec_pict_seg_local = NULL;

				dec_pict_seg_local =
				lst_removehead(&dec_str_unit_local->dec_pict->dec_pict_seg_list);
			}

			VDEC_ASSERT(dec_str_unit_local->dec_pict->dec_str_ctx == dec_str_ctx_local);

			dec_str_ctx_local->dec_str_st.num_pict_decoding--;
			pict_id = GET_STREAM_PICTURE_ID(dec_str_unit_local->dec_pict->transaction_id);

			ret = decoder_picture_destroy(dec_str_ctx_local, pict_id, osa_true);
			VDEC_ASSERT(ret == IMG_SUCCESS);
			if (ret != IMG_SUCCESS)
				return ret;

			osa_free(dec_str_unit_local->dec_pict);
			dec_str_unit_local->dec_pict = NULL;
		}

		/* Free the picture container */
		osa_free(dec_str_unit_local);
		dec_str_unit_local = NULL;

		dec_str_unit_local = lst_removehead(&dec_str_ctx_local->pend_strunit_list);
	}

	/* Destroy all pictures in the decoded list */
	decoded_pict_local = dq_first(&dec_str_ctx_local->str_decd_pict_list);
	while (decoded_pict_local) {
		ret = decoder_decoded_picture_destroy(dec_str_ctx_local,
						      decoded_pict_local,
						      osa_true);
		VDEC_ASSERT(ret == IMG_SUCCESS);
		if (ret != IMG_SUCCESS)
			return ret;

		decoded_pict_local = dq_first(&dec_str_ctx_local->str_decd_pict_list);
	}

	/* Ensure all picture queues are empty */
	VDEC_ASSERT(lst_empty(&dec_str_ctx_local->pend_strunit_list));
	VDEC_ASSERT(dq_empty(&dec_str_ctx_local->str_decd_pict_list));

	/* Free memory to store stream context buffer. */
	ret = mmu_free_mem(dec_str_ctx_local->mmu_str_handle,
			   &dec_str_ctx_local->pvdec_fw_ctx_buf);
	VDEC_ASSERT(ret == IMG_SUCCESS);
	if (ret != IMG_SUCCESS)
		return ret;

	/* Release any fw contexts held by stream. */
	if (dec_str_ctx_local->prev_fe_pict_dec_res)
		resource_item_return(&dec_str_ctx_local->prev_fe_pict_dec_res->ref_cnt);

	if (dec_str_ctx_local->cur_fe_pict_dec_res)
		resource_item_return(&dec_str_ctx_local->cur_fe_pict_dec_res->ref_cnt);

	if (dec_str_ctx_local->last_be_pict_dec_res)
		resource_item_return(&dec_str_ctx_local->last_be_pict_dec_res->ref_cnt);

	/*
	 * Remove the device resources used for decoding and the two
	 * added to hold the last on front and back-end for stream.
	 */
	for (i = 0; i < dec_str_ctx_local->num_dec_res + 2; i++) {
		ret = resource_list_empty(&dec_str_ctx_local->dec_res_lst, osa_false,
					  decoder_stream_decode_resource_destroy,
					  dec_str_ctx_local);
		VDEC_ASSERT(ret == IMG_SUCCESS);
		if (ret != IMG_SUCCESS)
			return ret;
	}
	VDEC_ASSERT(lst_empty(&dec_str_ctx_local->dec_res_lst));

	/* Remove all stream decode resources. */
	ret = resource_list_empty(&dec_str_ctx_local->ref_res_lst, osa_false,
				  decoder_stream_reference_resource_destroy,
				  dec_str_ctx_local);

	VDEC_ASSERT(ret == IMG_SUCCESS);
	if (ret != IMG_SUCCESS)
		return ret;

	VDEC_ASSERT(lst_empty(&dec_str_ctx_local->ref_res_lst));

	idgen_destroycontext(dec_str_ctx_local->pict_idgen);

	dec_context = dec_str_ctx_local->decctx;
	dec_core_ctx_local = decoder_str_ctx_to_core_ctx(dec_str_ctx_local);

	VDEC_ASSERT(dec_context);
	VDEC_ASSERT(dec_core_ctx_local);

	res_handle_local = &dec_str_ctx_local->resources;

	if (*res_handle_local) {
		ret = dec_res_destroy(dec_str_ctx_local->mmu_str_handle,
				      *res_handle_local);
		if (ret != IMG_SUCCESS)
			OSA_PR_WARN("resourceS_Destroy() failed to tidy-up after error");

		*res_handle_local = NULL;
	}

	lst_remove(&dec_str_ctx_local->decctx->str_list, dec_str_ctx_local);

	osa_free(dec_str_ctx_local);
	dec_str_ctx_local = NULL;

	OSA_PR_DEBUG("decoder_stream_destroy successfully");
	return IMG_SUCCESS;
}

/*
 * @Function  decoder_init_avail_slots
 */
static int32 decoder_init_avail_slots(struct dec_str_ctx *dec_str_context)
{
	VDEC_ASSERT(dec_str_context);

	switch (dec_str_context->config.vid_std) {
	case VDEC_STD_H264:
		/*
		 * only first pipe can be master when decoding H264 in
		 * multipipe mode (FW restriction)
		 */
		dec_str_context->avail_slots =
			dec_str_context->decctx->dev_cfg->num_slots_per_pipe *
			dec_str_context->decctx->num_pipes;
		break;

	default:
		/* all pipes by default */
		dec_str_context->avail_slots =
			dec_str_context->decctx->dev_cfg->num_slots_per_pipe;
	break;
	}

	return IMG_SUCCESS;
}

/*
 * @Function  decoder_stream_decode_resource_create
 */
static int32
decoder_stream_decode_resource_create(struct dec_str_ctx *dec_str_context)
{
	struct dec_pictdec_res *pict_dec_res;
	int32 ret;
	uint32 mem_heap_id;
	enum sys_emem_attrib mem_attribs;

	uint8 fw_ctx_buf = osa_false;

	/* Validate input arguments */
	if((!dec_str_context) || (!dec_str_context->decctx) || (!dec_str_context->decctx->dev_cfg)) {
		VDEC_ASSERT(0);
		return -OSA_EINVAL;
	}

	mem_heap_id = dec_str_context->decctx->internal_heap_id;
	mem_attribs = (enum sys_emem_attrib)(SYS_MEMATTRIB_UNCACHED | SYS_MEMATTRIB_WRITECOMBINE);
	mem_attribs |= (enum sys_emem_attrib)SYS_MEMATTRIB_INTERNAL;

	/* Allocate the firmware context buffer info structure. */
	pict_dec_res = osa_zalloc(sizeof(*pict_dec_res), OSA_GFP_KERNEL);
	VDEC_ASSERT(pict_dec_res);
	if (!pict_dec_res)
		return IMG_ERROR_OUT_OF_MEMORY;

	/*
	 * Allocate the firmware context buffer to contain
	 * data required for subsequent picture.
	 */
	OSA_PR_INFO("%s:%d calling MMU_StreamMalloc", __func__, __LINE__);

	ret = mmu_stream_alloc(dec_str_context->mmu_str_handle,
			       MMU_HEAP_STREAM_BUFFERS, mem_heap_id,
			       (enum sys_emem_attrib)(mem_attribs | SYS_MEMATTRIB_CPU_READ |
			       SYS_MEMATTRIB_CPU_WRITE),
			       sizeof(union dec_fw_contexts),
			       DEV_MMU_PAGE_ALIGNMENT,
			       &pict_dec_res->fw_ctx_buf);

	VDEC_ASSERT(ret == IMG_SUCCESS);
	if (ret != IMG_SUCCESS)
		goto err_out_of_memory;

	fw_ctx_buf = osa_true;

	/*
	 * Clear the context data in preparation for first time
	 * use by the firmware.
	 */
	memset(pict_dec_res->fw_ctx_buf.cpu_virt, 0,
	       pict_dec_res->fw_ctx_buf.buf_size);

	switch (dec_str_context->config.vid_std) {
	case VDEC_STD_H264:
		/* Allocate the SGM buffer */
		OSA_PR_INFO("%s:%d calling MMU_StreamMalloc", __func__, __LINE__);
		ret = mmu_stream_alloc(dec_str_context->mmu_str_handle,
				       MMU_HEAP_STREAM_BUFFERS, mem_heap_id,
				       (enum sys_emem_attrib)(mem_attribs | SYS_MEMATTRIB_CPU_WRITE),
				       H264_SGM_BUFFER_BYTES_PER_MB *
				       H264_SGM_MAX_MBS,
				       DEV_MMU_PAGE_ALIGNMENT,
				       &pict_dec_res->h264_sgm_buf);
		VDEC_ASSERT(ret == IMG_SUCCESS);
		if (ret != IMG_SUCCESS)
			goto err_out_of_memory;

		/* Clear the SGM data. */
		memset(pict_dec_res->h264_sgm_buf.cpu_virt, 0,
		       pict_dec_res->h264_sgm_buf.buf_size);
		break;

	default:
		break;
	}

	pict_dec_res->ref_cnt = 1;

	ret = resource_list_add(&dec_str_context->dec_res_lst, pict_dec_res, 0,
				&pict_dec_res->ref_cnt);

	if (ret != IMG_SUCCESS) {
		OSA_PR_WARN("[USERSID=0x%08X] Failed to add resource",
			dec_str_context->config.user_str_id);
	}

	return IMG_SUCCESS;

err_out_of_memory:
	if (pict_dec_res) {
		if (fw_ctx_buf)
			mmu_free_mem(dec_str_context->mmu_str_handle,
				     &pict_dec_res->fw_ctx_buf);

		osa_free(pict_dec_res);
		pict_dec_res = NULL;
	}

	OSA_PR_ERR("[USERSID=0x%08X] Failed to allocate device memory for stream decode resources",
	       dec_str_context->config.user_str_id);

	return IMG_ERROR_OUT_OF_MEMORY;
}

/*
 * @Function  decoder_stream_create
 */
int32 decoder_stream_create(void *dec_ctx_arg,
			  struct vdec_str_configdata str_cfg,
			  uint32 km_str_id, void **mmu_str_handle,
			  void *vxd_dec_ctx, void *str_user_int_data,
			  void **dec_str_ctx_arg, void *decoder_cb,
			  void *query_cb)
{
	struct dec_ctx *dec_context = (struct dec_ctx *)dec_ctx_arg;
	struct dec_str_ctx *dec_str_ctx = NULL;
	uint32 i;
	int32 ret;
	uint32 mem_heap_id;
	enum sys_emem_attrib mem_attribs;
	struct dec_core_ctx *dec_core_ctx_local;

	/* Check input parameters. */
	VDEC_ASSERT(dec_ctx_arg);
	if (!dec_ctx_arg) {
		OSA_PR_ERR("Invalid parameters!");
		return IMG_ERROR_INVALID_PARAMETERS;
	}

	if (dec_context->str_cnt >= MAX_CONCURRENT_STREAMS) {
		OSA_PR_ERR("Device has too many concurrent streams. Number of Concurrent streams allowed: %d.",
		       MAX_CONCURRENT_STREAMS);
		return IMG_ERROR_DEVICE_UNAVAILABLE;
	}

	mem_heap_id = dec_context->internal_heap_id;
	mem_attribs = (enum sys_emem_attrib)(SYS_MEMATTRIB_UNCACHED | SYS_MEMATTRIB_WRITECOMBINE);
	mem_attribs |= (enum sys_emem_attrib)SYS_MEMATTRIB_INTERNAL;

	/* Allocate Decoder Stream Context */
	dec_str_ctx = osa_zalloc(sizeof(*dec_str_ctx), OSA_GFP_KERNEL);
	VDEC_ASSERT(dec_str_ctx);
	if (!dec_str_ctx)
		return IMG_ERROR_OUT_OF_MEMORY;

	/* Increment the stream counter */
	dec_context->str_cnt++;

	/*
	 * Initialise the context structure to NULL. Any non-zero
	 * default values should be set at this point.
	 */
	dec_str_ctx->config = str_cfg;
	dec_str_ctx->vxd_dec_ctx = vxd_dec_ctx;
	dec_str_ctx->usr_int_data = str_user_int_data;
	dec_str_ctx->decctx = dec_context;

	decoder_init_avail_slots(dec_str_ctx);

	dec_str_ctx->next_dec_pict_id = 1;
	dec_str_ctx->next_pict_id_expected = 1;

	dec_str_ctx->km_str_id = km_str_id;
	VDEC_ASSERT(dec_str_ctx->km_str_id > 0);

	lst_init(&dec_str_ctx->pend_strunit_list);
	dq_init(&dec_str_ctx->str_decd_pict_list);
	lst_init(&dec_str_ctx->ref_res_lst);
	lst_init(&dec_str_ctx->dec_res_lst);

	ret = idgen_createcontext(DECODER_MAX_PICT_ID + 1,
				  DECODER_MAX_CONCURRENT_PICT,
				  osa_true,
				  &dec_str_ctx->pict_idgen);
	VDEC_ASSERT(ret == IMG_SUCCESS);
	if (ret != IMG_SUCCESS)
		goto error;

	/* Create an MMU context for this stream. */
	ret = mmu_stream_create(dec_context->mmu_dev_handle,
				dec_str_ctx->km_str_id,
				dec_str_ctx->vxd_dec_ctx,
				&dec_str_ctx->mmu_str_handle);
	VDEC_ASSERT(ret == IMG_SUCCESS);
	if (ret != IMG_SUCCESS)
		goto error;

	dec_core_ctx_local = dec_context->dec_core_ctx;

	VDEC_ASSERT(dec_core_ctx_local);

	/* Create core resources */
	ret = dec_res_create(dec_str_ctx->mmu_str_handle,
			     &dec_core_ctx_local->core_props,
			     dec_context->dev_cfg->num_slots_per_pipe *
			     dec_context->num_pipes,
			     dec_context->internal_heap_id,
			     &dec_str_ctx->resources);
	VDEC_ASSERT(ret == IMG_SUCCESS);
	if (ret != IMG_SUCCESS)
		goto error;

	/* Allocate the PVDEC firmware context buffer */
	OSA_PR_INFO("%s:%d calling MMU_StreamMalloc", __func__, __LINE__);
	ret = mmu_stream_alloc(dec_str_ctx->mmu_str_handle,
			       MMU_HEAP_STREAM_BUFFERS,
			       mem_heap_id,
			       (enum sys_emem_attrib)(mem_attribs | SYS_MEMATTRIB_CPU_WRITE),
			       CONTEXT_BUFF_SIZE,
			       DEV_MMU_PAGE_ALIGNMENT,
			       &dec_str_ctx->pvdec_fw_ctx_buf);
	VDEC_ASSERT(ret == IMG_SUCCESS);
	if (ret != IMG_SUCCESS)
		goto error;

	/*
	 * Clear the context data in preparation for
	 * first time use by the firmware.
	 */
	memset(dec_str_ctx->pvdec_fw_ctx_buf.cpu_virt, 0,
	       dec_str_ctx->pvdec_fw_ctx_buf.buf_size);

	/*
	 * Create enough device resources to hold last context on
	 * front and back-end for stream.
	 */
	dec_str_ctx->num_dec_res =
		dec_str_ctx->decctx->dev_cfg->num_slots_per_pipe *
					dec_str_ctx->decctx->num_pipes;
	for (i = 0; i < dec_str_ctx->num_dec_res + 2; i++) {
		ret = decoder_stream_decode_resource_create(dec_str_ctx);
		VDEC_ASSERT(ret == IMG_SUCCESS);
		if (ret != IMG_SUCCESS)
			goto error;
	}

	dec_str_ctx->str_processed_cb = (strunit_processed_cb)decoder_cb;

	dec_str_ctx->core_query_cb = (core_gen_cb)query_cb;

	lst_add(&dec_context->str_list, dec_str_ctx);

	*dec_str_ctx_arg = (void *)dec_str_ctx;
	*mmu_str_handle = dec_str_ctx->mmu_str_handle;

	return IMG_SUCCESS;

	/* Roll back in case of errors. */
error:
	decoder_stream_destroy((void *)dec_str_ctx, osa_false);

	return ret;
}

/*
 * @Function  decoder_get_decoded_pict
 */
static struct dec_decoded_pict *decoder_get_decoded_pict(uint32 transaction_id,
							 struct dq_linkage_t *dq_list)
{
	struct dec_decoded_pict *decoded_pict;
	void *item = NULL;

	VDEC_ASSERT(dq_list);

	decoded_pict = dq_first(dq_list);
	while (decoded_pict) {
		if (decoded_pict->transaction_id == transaction_id) {
			item = decoded_pict;
			break;
		}

		if (decoded_pict != dq_last(dq_list))
			decoded_pict = dq_next(decoded_pict);
		else
			decoded_pict = NULL;
	}

	return item;
}

/*
 * @Function  decoder_get_decoded_pict_of_stream
 */
static
struct dec_decoded_pict *decoder_get_decoded_pict_of_stream(uint32 pict_id,
							    struct dq_linkage_t *dq_list)
{
	struct dec_decoded_pict *decoded_pict;
	void *item = NULL;

	VDEC_ASSERT(dq_list);

	decoded_pict = dq_first(dq_list);
	while (decoded_pict) {
		if (GET_STREAM_PICTURE_ID(decoded_pict->transaction_id) == pict_id) {
			item = decoded_pict;
			break;
		}

		if (decoded_pict != dq_last(dq_list))
			decoded_pict = dq_next(decoded_pict);
		else
			decoded_pict = NULL;
	}
	return item;
}

/*
 * @Function  decoder_get_next_decpict_contiguous
 */
static
struct dec_decoded_pict *decoder_get_next_decpict_contiguous(struct dec_decoded_pict *decoded_pict,
							     uint32 next_dec_pict_id,
							     struct dq_linkage_t *str_decoded_pict_list)
{
	struct dec_decoded_pict *next_dec_pict = NULL;
	struct dec_decoded_pict *result_dec_pict = NULL;

	VDEC_ASSERT(str_decoded_pict_list);
	if (!str_decoded_pict_list) {
		OSA_PR_ERR("Invalid parameter");
		return NULL;
	}

	if (decoded_pict) {
		if (decoded_pict != dq_last(str_decoded_pict_list)) {
			next_dec_pict = dq_next(decoded_pict);
			if(!next_dec_pict) {
				VDEC_ASSERT(0);
				return NULL;
			}


			if (next_dec_pict->pict) {
				/*
				 * If we have no holes in the decoded list
				 * (i.e. next decoded picture is next in
				 * bitstream decode order).
				 */
				if (HAS_X_REACHED_Y(next_dec_pict_id,
						    next_dec_pict->pict->pict_id,
						    1 << FWIF_NUMBITS_STREAM_PICTURE_ID, uint32)) {
					result_dec_pict = next_dec_pict;
				}
			}
		}
	}

	return result_dec_pict;
}

/*
 * @Function  decoder_next_picture
 * @Description
 * Returns the next unprocessed picture or NULL if the next picture is not
 * next in bitstream decode order or there are no more decoded pictures in the
 * list.

 * @Input     psCurrentDecodedPicture : Pointer to current decoded picture.

 * @Input     ui32NextDecPictId       : Picture ID of next picture in decode
 *					order.

 * @Input     psStrDecdPictList       : Pointer to decoded picture list.

 * @Return    DECODER_sDecodedPict *  : Pointer to next decoded picture to
 *					process.
 */
static
struct dec_decoded_pict *decoder_next_picture(struct dec_decoded_pict *cur_decoded_pict,
					      uint32 next_dec_pict_d,
					      struct dq_linkage_t *str_decodec_pict_list)
{
	struct dec_decoded_pict *ret = NULL;

	VDEC_ASSERT(str_decodec_pict_list);
	if (!str_decodec_pict_list)
		return NULL;

	if (!cur_decoded_pict)
		cur_decoded_pict = dq_first(str_decodec_pict_list);

	if (cur_decoded_pict &&
	    !cur_decoded_pict->process_failed) {
		/* Search for picture ID greater than picture in list */
		do {
			if (!cur_decoded_pict->processed) {
				/*
				 * Return the current one because it has not
				 * been processed
				 */
				ret = cur_decoded_pict;
				break;
			}

			/*
			 * Obtain a pointer to the next picture in bitstream
			 * decode order.
			 */
			cur_decoded_pict =
			decoder_get_next_decpict_contiguous(cur_decoded_pict,
							    next_dec_pict_d,
							    str_decodec_pict_list);
		} while (cur_decoded_pict &&
			 !cur_decoded_pict->process_failed);
	}
	return ret;
}

/*
 * @Function  decoder_picture_display
 */
static int32 decoder_picture_display(struct dec_str_ctx *dec_str_ctx,
				   uint32 pict_id, uint8 last)
{
	struct vdecdd_picture *picture;
	int32 ret;
	static uint32 display_num = 0;

	VDEC_ASSERT(dec_str_ctx);

	ret = idgen_gethandle(dec_str_ctx->pict_idgen, pict_id,
			      (void **)&picture);
	if (ret == IMG_SUCCESS) {
		struct vdecdd_ddbuf_mapinfo *pict_buf;

		/* validate pointers */
		if((!picture) || (!picture->dec_pict_info)) {
			VDEC_ASSERT(0);
			return -OSA_EIO;
		}

		pict_buf = picture->disp_pict_buf.pict_buf;
		VDEC_ASSERT(pict_buf);

		/*
		 * Indicate whether there are more pictures
		 * coming for display.
		 */
		picture->dec_pict_info->last_in_seq = last;

		/* Set decode order id */
		picture->dec_pict_info->decode_id = pict_id;

		/* Return the picture to the client for display */
		dec_str_ctx->dec_str_st.total_pict_displayed++;
		resource_item_use(&pict_buf->ddbuf_info.ref_count);
		display_num++;
		OSA_PR_INFO("[USERSID=0x%08X] DISPLAY(%d): PIC_ID[%d]",
			dec_str_ctx->config.user_str_id, display_num, pict_id);

		VDEC_ASSERT(dec_str_ctx->decctx);
		ret = dec_str_ctx->str_processed_cb(dec_str_ctx->usr_int_data,
						    VXD_CB_PICT_DISPLAY,
						    picture);

		VDEC_ASSERT(ret == IMG_SUCCESS);
		if (ret != IMG_SUCCESS)
			return ret;

		/*
		 * All handles will be freed after actually
		 * displaying the picture.
		 * Reset them to NULL here to avoid any confusion.
		 */
		memset(&picture->dec_pict_sup_data, 0,
		       sizeof(picture->dec_pict_sup_data));
	} else {
		OSA_PR_WARN("[USERSID=0x%08X] ERROR: DISPLAY PICTURE HAS AN EXPIRED ID",
			dec_str_ctx->config.user_str_id);
		VDEC_ASSERT(ret == IMG_SUCCESS);
	}

	return IMG_SUCCESS;
}

#ifdef ERROR_CONCEALMENT
/*
 * @Function              decoder_get_pict_processing_info
 */
static uint8 decoder_get_pict_processing_info(struct dec_core_ctx *dec_corectx,
					   struct dec_str_ctx *dec_strctx,
					   struct bspp_pict_hdr_info *pict_hdr_info,
					   struct dec_decoded_pict *decoded_pict,
					   struct dec_decpict *dec_pict,
					   uint32 *pict_last_mb)
{
	int32 ret = IMG_SUCCESS;
	uint8  pipe_minus1;
	struct hwctrl_state last_state;
	uint32 width_in_mb;
	uint32 height_in_mb;
	uint32 i;

	memset(&last_state, 0, sizeof(last_state));

	VDEC_ASSERT(pict_hdr_info);
	width_in_mb = (pict_hdr_info->coded_frame_size.width +
			(VDEC_MB_DIMENSION - 1)) / VDEC_MB_DIMENSION;
	height_in_mb = (pict_hdr_info->coded_frame_size.height +
			(VDEC_MB_DIMENSION - 1)) / VDEC_MB_DIMENSION;

	VDEC_ASSERT(pict_last_mb);
	*pict_last_mb = width_in_mb * height_in_mb;
	VDEC_ASSERT(decoded_pict);

	if (decoded_pict->first_fld_fwmsg->pict_attrs.pict_attrs.dwrfired ||
	    decoded_pict->second_fld_fwmsg->pict_attrs.pict_attrs.dwrfired ||
	    decoded_pict->first_fld_fwmsg->pict_attrs.pict_attrs.mmufault ||
	    decoded_pict->second_fld_fwmsg->pict_attrs.pict_attrs.mmufault) {
		struct dec_pict_attrs *pict_attrs = &decoded_pict->first_fld_fwmsg->pict_attrs;
		uint8 be_found = osa_false;
		uint32 mbs_dropped = 0;
		uint32 mbs_recovered = 0;
		uint32 no_be_wdt = 0;
		uint32 max_y = 0;
		uint32 row_drop = 0;

		VDEC_ASSERT(dec_corectx);
		/* Obtain the last available core status - cached before clocks where switched off */
		ret = hwctrl_getcore_cached_status(dec_corectx->hw_ctx, &last_state);
		if (ret != IMG_SUCCESS)
			return osa_false;

		/* Try to determine pipe where the last picture was decoded on (BE) */
		for (pipe_minus1 = 0; pipe_minus1 < VDEC_MAX_PIXEL_PIPES; pipe_minus1++) {
			for (i = VDECFW_CHECKPOINT_BE_END; i >= VDECFW_CHECKPOINT_BE_START; i--) {
				struct vxd_pipestate *pipe_state = &last_state.core_state.fw_state.pipe_state[pipe_minus1];

				if (!pipe_state->is_pipe_present)
					continue;

				if (pipe_state->acheck_point[i] == decoded_pict->transaction_id) {
					row_drop += width_in_mb - pipe_state->be_mb.x;
					if (pipe_state->be_mb.y > max_y)
						max_y = pipe_state->be_mb.y;

					if (pipe_state->be_mbs_dropped > mbs_dropped)
						mbs_dropped = pipe_state->be_mbs_dropped;

					if (pipe_state->be_mbs_recovered > mbs_recovered)
						mbs_recovered = pipe_state->be_mbs_recovered;

					no_be_wdt += pipe_state->be_errored_slices;
					be_found = osa_true;
				}
			}
			if (be_found)
				/* No need to check FE as we already have an info from BE */
				continue;

			/* If not found, we probbaly stuck on FE ? */
			for (i = VDECFW_CHECKPOINT_FE_END; i >= VDECFW_CHECKPOINT_FE_START; i--) {
				struct vxd_pipestate *pipe_state = &last_state.core_state.fw_state.pipe_state[pipe_minus1];

				if (!pipe_state->is_pipe_present)
					continue;

				if (pipe_state->acheck_point[i] == decoded_pict->transaction_id) {
					/* Mark all MBs as dropped */
					pict_attrs->mbs_dropped = *pict_last_mb;
					pict_attrs->mbs_recovered = 0;
					return osa_true;
				}
			}
		}

		if (be_found) {
			/* Calculate last macroblock number processed on BE */
			uint32 num_mb_processed = (max_y * width_in_mb) - row_drop;

			/* Sanity check, as HW may signal MbYX position beyond picture for corrupted streams */
			if (num_mb_processed > (*pict_last_mb))
				num_mb_processed = (*pict_last_mb); /* trim */

			if (((*pict_last_mb) - num_mb_processed) > mbs_dropped)
				mbs_dropped = (*pict_last_mb) - num_mb_processed;

			pict_attrs->mbs_dropped = mbs_dropped;
			pict_attrs->mbs_recovered = num_mb_processed;
			pict_attrs->no_be_wdt = no_be_wdt;
			return osa_true;
		}
		return osa_false;
	}
	/* Picture was decoded without DWR, so we have already the required info */
	return osa_true;
}
#endif

/*
 * @Function  decoder_picture_release
 */
static int32 decoder_picture_release(struct dec_str_ctx *dec_str_ctx,
				   uint32 pict_id,
				   uint8 displayed, uint8 merged)
{
	struct vdecdd_picture *picture;
	int32 ret;

	/* validate input arguments */
	if(!dec_str_ctx) {
		VDEC_ASSERT(0);
		return -OSA_EINVAL;
	}

	ret = idgen_gethandle(dec_str_ctx->pict_idgen, pict_id,
			      (void **)&picture);
	if (ret == IMG_SUCCESS) {
		if((!picture) || (!picture->dec_pict_info)) {
			VDEC_ASSERT(0);
			return -OSA_EINVAL;
		}

		/* Set decode order id */
		picture->dec_pict_info->decode_id = pict_id;

		VDEC_ASSERT(dec_str_ctx->decctx);

		OSA_PR_DEBUG("Decoder picture released pict_id = %d\n",pict_id);
		ret = dec_str_ctx->str_processed_cb(dec_str_ctx->usr_int_data,
						    VXD_CB_PICT_RELEASE,
						    picture);
		VDEC_ASSERT(ret == IMG_SUCCESS);
		if (ret != IMG_SUCCESS)
			return ret;

		/*
		 * All handles will be freed after actually displaying
		 * the picture. Reset them to NULL here to avoid any
		 * confusion.
		 */
		memset(&picture->dec_pict_sup_data, 0,
		       sizeof(picture->dec_pict_sup_data));
	} else {
		OSA_PR_ERR("[USERSID=0x%08X] ERROR: RELEASE PICTURE HAS AN EXPIRED ID",
		       dec_str_ctx->config.user_str_id);
		VDEC_ASSERT(ret == IMG_SUCCESS);
	}

	return IMG_SUCCESS;
}

/*
 * @Function decoder_stream_flush_process_dpb_h264
 */
static int32
decoder_stream_flush_process_dpb_h264(struct dec_str_ctx *dec_str_ctx,
				      struct dec_decoded_pict *decoded_pict,
				      uint8 discard_refs)
{
	int32 ret;

	struct h264fw_context_data *ctx_data =
		(struct h264fw_context_data *)dec_str_ctx->last_be_pict_dec_res->fw_ctx_buf.cpu_virt;
	uint8 found = osa_true;
	uint32 i;
	int32 min_cnt;
	int32 min_cnt_idx;
	uint32 num_display_pics = 0;
	uint32 num_pics_displayed = 0;
	struct dec_decoded_pict *display_pict = NULL;
	uint32 last_disp_pict_tid;
	uint32 pict_id;

	/* Determine how many display pictures reside in the DPB */
	if (ctx_data->dpb_size > H264FW_MAX_DPB_SIZE || ctx_data->dpb_size <= 0) {
		OSA_PR_INFO("[USERSID=0x%08X] Incorrect DPB size: %d",
			dec_str_ctx->config.user_str_id, ctx_data->dpb_size);
		ctx_data->dpb_size = H264FW_MAX_DPB_SIZE;
	}
	for (i = 0; i < ctx_data->dpb_size; i++) {
		if (ctx_data->dpb[i].transaction_id)
			if (ctx_data->dpb[i].needed_for_output)
				num_display_pics++;
	}

	last_disp_pict_tid =
		ctx_data->last_displayed_pic_data[0].transaction_id;
	/* Check for picture stuck outside the dpb */
	if (last_disp_pict_tid) {
		VDEC_ASSERT(last_disp_pict_tid != 0xffffffff);

		display_pict =
		decoder_get_decoded_pict(last_disp_pict_tid,
					 &dec_str_ctx->str_decd_pict_list);

		if (display_pict && display_pict->pict &&
		    display_pict->pict->dec_pict_info) {
			if (FLAG_IS_SET(ctx_data->prev_display_flags,
					VDECFW_BUFFLAG_DISPLAY_FIELD_CODED)) {
				if (!FLAG_IS_SET(ctx_data->prev_display_flags,
						 VDECFW_BUFFLAG_DISPLAY_SINGLE_FIELD))
					display_pict->pict->dec_pict_info->buf_type =
								IMG_BUFFERTYPE_PAIR;
				else
					display_pict->pict->dec_pict_info->buf_type =
						FLAG_IS_SET(ctx_data->prev_display_flags,
							    VDECFW_BUFFLAG_DISPLAY_BOTTOM_FIELD) ?
							    IMG_BUFFERTYPE_FIELD_BOTTOM :
							    IMG_BUFFERTYPE_FIELD_TOP;
			} else {
				display_pict->pict->dec_pict_info->buf_type =
								IMG_BUFFERTYPE_FRAME;
			}
		} else {
			VDEC_ASSERT(display_pict);
			VDEC_ASSERT(display_pict && display_pict->pict);
			VDEC_ASSERT(display_pict && display_pict->pict &&
				    display_pict->pict->dec_pict_info);
		}

		if (display_pict && !display_pict->displayed) {
			OSA_PR_INFO("[USERSID=0x%08X] [TID=0x%08X] DISPLAY",
				dec_str_ctx->config.user_str_id,
				last_disp_pict_tid);
			display_pict->displayed = osa_true;
			ret = decoder_picture_display(dec_str_ctx,
						      GET_STREAM_PICTURE_ID(last_disp_pict_tid),
						      osa_true);
			VDEC_ASSERT(ret == IMG_SUCCESS);
			if (ret != IMG_SUCCESS)
				return ret;
		}
	}

	while (found) {
		min_cnt = ((uint32)(1 << 31)) - 1;
		min_cnt_idx = -1;
		found = osa_false;

		/* Loop over the DPB to find the first in order */
		for (i = 0; i < ctx_data->dpb_size; i++) {
			if (ctx_data->dpb[i].transaction_id &&
			    (ctx_data->dpb[i].needed_for_output ||
			     discard_refs)) {
				if (ctx_data->dpb[i].top_field_order_count <
				    min_cnt) {
					min_cnt =
					ctx_data->dpb[i].top_field_order_count;
					min_cnt_idx = i;
					found = osa_true;
				}
			}
		}

		if (found) {
			uint32 umin_cnt_tid = ctx_data->dpb[min_cnt_idx].transaction_id;

			if (ctx_data->dpb[min_cnt_idx].needed_for_output) {
				VDEC_ASSERT(umin_cnt_tid != 0xffffffff);
				display_pict =
				decoder_get_decoded_pict(umin_cnt_tid,
							 &dec_str_ctx->str_decd_pict_list);

				if (display_pict && display_pict->pict &&
				    display_pict->pict->dec_pict_info) {
					if (FLAG_IS_SET(ctx_data->dpb[min_cnt_idx].display_flags,
							VDECFW_BUFFLAG_DISPLAY_FIELD_CODED)) {
						if (!FLAG_IS_SET(ctx_data->dpb[min_cnt_idx].display_flags,
								 VDECFW_BUFFLAG_DISPLAY_SINGLE_FIELD))
							display_pict->pict->dec_pict_info->buf_type =
										IMG_BUFFERTYPE_PAIR;
						else
							display_pict->pict->dec_pict_info->buf_type =
							FLAG_IS_SET(ctx_data->dpb[min_cnt_idx].display_flags,
								    VDECFW_BUFFLAG_DISPLAY_BOTTOM_FIELD) ?
								    IMG_BUFFERTYPE_FIELD_BOTTOM :
								    IMG_BUFFERTYPE_FIELD_TOP;
					} else {
						display_pict->pict->dec_pict_info->buf_type =
										IMG_BUFFERTYPE_FRAME;
					}

					display_pict->pict->dec_pict_info->view_id =
						ctx_data->dpb[min_cnt_idx].view_id;
				} else {
					VDEC_ASSERT(display_pict);
					VDEC_ASSERT(display_pict && display_pict->pict);
					VDEC_ASSERT(display_pict && display_pict->pict &&
						    display_pict->pict->dec_pict_info);
				}

				if (display_pict && !display_pict->displayed) {
					OSA_PR_INFO("[USERSID=0x%08X] [TID=0x%08X] DISPLAY",
						dec_str_ctx->config.user_str_id,
						umin_cnt_tid);
					display_pict->displayed = osa_true;
					num_pics_displayed++;
					ret =
					decoder_picture_display(dec_str_ctx,
								GET_STREAM_PICTURE_ID(umin_cnt_tid),
								num_pics_displayed == num_display_pics ?
								osa_true : osa_false);
					VDEC_ASSERT(ret == IMG_SUCCESS);
					if (ret != IMG_SUCCESS)
						return ret;
				}
				ctx_data->dpb[min_cnt_idx].needed_for_output = osa_false;
			}

			if (discard_refs) {
				decoded_pict =
				decoder_get_decoded_pict(umin_cnt_tid,
							 &dec_str_ctx->str_decd_pict_list);
				if (decoded_pict) {
					/* Signal releasing this picture to upper layers. */
					pict_id = GET_STREAM_PICTURE_ID(decoded_pict->transaction_id);
					decoder_picture_release(dec_str_ctx,
								pict_id,
								decoded_pict->displayed,
								decoded_pict->merged);
					/* Destroy the decoded picture. */
					ret = decoder_decoded_picture_destroy(dec_str_ctx,
									      decoded_pict,
									      osa_false);
					VDEC_ASSERT(ret == IMG_SUCCESS);
					if (ret != IMG_SUCCESS)
						return ret;
				}
				ctx_data->dpb[min_cnt_idx].transaction_id = 0;
			}

		}
	}

		VDEC_ASSERT(num_pics_displayed == num_display_pics);

	return IMG_SUCCESS;
}

#ifdef HAS_HEVC
/*
 * decoder_StreamFlushProcessDPB_HEVC
 */
static int32
decoder_stream_flush_process_dpb_hevc(struct dec_str_ctx *decstr_ctx,
				      struct dec_decoded_pict *decoded_pict,
				      uint8 discard_refs)
{
	int32 result;
	struct hevcfw_ctx_data *ctx = (struct hevcfw_ctx_data *)decstr_ctx->last_be_pict_dec_res->fw_ctx_buf.cpu_virt;
	struct hevcfw_decoded_picture_buffer *dpb;
	uint8 found = osa_true;
	uint8 idx;
	int32 min_poc_val;
	int8 dpb_idx;
	uint8 num_display_pics = 0;
	uint8 num_pics_displayed = 0;
	struct dec_decoded_pict *display_pict = NULL;

	/*
	 * Update the fw context for analysing the dpb in order
	 * to display or release any outstanding picture
	 */
	dpb = &ctx->dpb;

	/* Determine how many display pictures reside in the DPB. */
	for (idx = 0; idx < HEVCFW_MAX_DPB_SIZE; ++idx) {
		struct hevcfw_picture_in_dpb *dpb_pic = &dpb->pictures[idx];

		if (dpb_pic->valid && dpb_pic->needed_for_output)
			++num_display_pics;
	}

	while (found) {
		struct hevcfw_picture_in_dpb *dpb_pic;

		min_poc_val = 0x7fffffff;
		dpb_idx = HEVCFW_DPB_IDX_INVALID;
		found = osa_false;

		/* Loop over the DPB to find the first in order */
		for (idx = 0; idx < HEVCFW_MAX_DPB_SIZE; ++idx) {
			dpb_pic = &dpb->pictures[idx];
			if (dpb_pic->valid && (dpb_pic->needed_for_output || discard_refs)) {
				if (dpb_pic->picture.pic_order_cnt_val < min_poc_val) {
					min_poc_val = dpb_pic->picture.pic_order_cnt_val;
					dpb_idx = idx;
					found = osa_true;
				}
			}
		}

		if (!found)
			break;

		dpb_pic = &dpb->pictures[dpb_idx];

		if (dpb_pic->needed_for_output) {
			uint32 str_pic_id = GET_STREAM_PICTURE_ID(dpb_pic->picture.transaction_id);

			VDEC_ASSERT(dpb_pic->picture.transaction_id != 0xffffffff);
			display_pict = decoder_get_decoded_pict(dpb_pic->picture.transaction_id,
								&decstr_ctx->str_decd_pict_list);

			if (display_pict && display_pict->pict && display_pict->pict->dec_pict_info) {
				display_pict->pict->dec_pict_info->buf_type = IMG_BUFFERTYPE_FRAME;
			} else {
				VDEC_ASSERT(display_pict);
				VDEC_ASSERT(display_pict && display_pict->pict);
				VDEC_ASSERT(display_pict && display_pict->pict && display_pict->pict->dec_pict_info);

				dpb_pic->valid = osa_false;
				continue;
			}

			if (!display_pict->displayed) {
				display_pict->displayed = osa_true;
				++num_pics_displayed;
				result = decoder_picture_display(decstr_ctx, str_pic_id,
								 num_pics_displayed == num_display_pics);
				VDEC_ASSERT(result == IMG_SUCCESS);
				if (result != IMG_SUCCESS)
					return result;
			}
			dpb_pic->needed_for_output = osa_false;
		}

		if (discard_refs) {
			decoded_pict = decoder_get_decoded_pict(dpb_pic->picture.transaction_id,
								&decstr_ctx->str_decd_pict_list);

			if (decoded_pict) {
				/* Signal releasing this picture to upper layers. */
				decoder_picture_release(decstr_ctx,
							GET_STREAM_PICTURE_ID(decoded_pict->transaction_id),
							decoded_pict->displayed,
							decoded_pict->merged);
				/* Destroy the decoded picture. */
				result = decoder_decoded_picture_destroy(decstr_ctx, decoded_pict, osa_false);
				VDEC_ASSERT(result == IMG_SUCCESS);
				if (result != IMG_SUCCESS)
					return result;
			}
			dpb_pic->valid = osa_false;
		}
	}

	VDEC_ASSERT(num_pics_displayed == num_display_pics);

	return IMG_SUCCESS;
}
#endif

/*
 * @Function        decoder_stream_flush_process_dpb
 * @Description
 * Process DPB fetched from firmware, display and release relevant pictures.
 */
static int32
decoder_stream_flush_process_dpb(struct dec_str_ctx *dec_str_ctx,
				 struct dec_decoded_pict *decoded_pict,
				 uint8 discard_refs)
{
	int32 ret = 0;
	/* Get oldest reference to display. */
	decoded_pict = dq_last(&dec_str_ctx->str_decd_pict_list);
	if (decoded_pict) {
		switch (dec_str_ctx->config.vid_std) {
		case VDEC_STD_H264:
			ret =
			decoder_stream_flush_process_dpb_h264(dec_str_ctx,
							      decoded_pict,
							      discard_refs);

			break;
#ifdef HAS_HEVC
		case VDEC_STD_HEVC:
			decoder_stream_flush_process_dpb_hevc(dec_str_ctx,
							      decoded_pict,
							      discard_refs);
#endif
			break;

		default:
			break;
		}
	}

	return ret;
}

int32 decoder_stream_flush(void *dec_str_ctx_arg, uint8 discard_refs)
{
	struct dec_str_ctx *dec_str_ctx;
	struct dec_str_unit *dec_str_unit;
	struct dec_decoded_pict	*decoded_pict;
	int32 ret = 0;

	dec_str_ctx = decoder_stream_get_context(dec_str_ctx_arg);
	VDEC_ASSERT(dec_str_ctx);
	if (!dec_str_ctx) {
		OSA_PR_ERR("Invalid decoder stream context handle!");
		return IMG_ERROR_INVALID_PARAMETERS;
	}

	/*
	 * Since the stream should be stopped before flushing
	 * there should be no pictures in the stream list.
	 */
	dec_str_unit = lst_first(&dec_str_ctx->pend_strunit_list);
	while (dec_str_unit) {
		VDEC_ASSERT(dec_str_unit->str_unit->str_unit_type !=
			    VDECDD_STRUNIT_PICTURE_START);
		dec_str_unit = lst_next(dec_str_unit);
	}

	decoded_pict = dq_last(&dec_str_ctx->str_decd_pict_list);

	ret = decoder_stream_flush_process_dpb(dec_str_ctx, decoded_pict,
					       discard_refs);
	if (ret != IMG_SUCCESS)
		return ret;

	if (discard_refs) {
		while (!dq_empty(&dec_str_ctx->str_decd_pict_list)) {
			struct dec_decoded_pict *non_decoded_pict =
				dq_first(&dec_str_ctx->str_decd_pict_list);

			if(!non_decoded_pict) {
				VDEC_ASSERT(0);
				return -OSA_EINVAL;
			}

			OSA_PR_INFO("[USERSID=0x%08X] Decoded picture list contains item ID:0x%08x when DPB is empty",
				dec_str_ctx->config.user_str_id,
				non_decoded_pict->transaction_id);

			/* release the buffers back to vxd_decoder */
			decoder_picture_release(dec_str_ctx,
						GET_STREAM_PICTURE_ID(non_decoded_pict->transaction_id),
						osa_false, osa_false);

			ret = decoder_decoded_picture_destroy(dec_str_ctx,
							      non_decoded_pict,
							      osa_false);
			VDEC_ASSERT(ret == IMG_SUCCESS);
			if (ret != IMG_SUCCESS)
				return ret;
		}
		VDEC_ASSERT(dq_empty(&dec_str_ctx->str_decd_pict_list));

		if (dec_str_ctx->last_be_pict_dec_res)
			/*
			 * Clear the firmware context so that reference
			 * pictures are no longer referred to.
			 */
			memset(dec_str_ctx->last_be_pict_dec_res->fw_ctx_buf.cpu_virt,
			       0,
			       dec_str_ctx->last_be_pict_dec_res->fw_ctx_buf.buf_size);
	}

	OSA_PR_DEBUG("Decoder stream flushed successfully\n");
	return IMG_SUCCESS;
}

/*
 * @Function  decoder_stream_prepare_ctx
 */
int32 decoder_stream_prepare_ctx(void *dec_str_ctx_arg, uint8 flush_dpb)
{
	struct dec_str_ctx *dec_str_ctx =
			decoder_stream_get_context(dec_str_ctx_arg);
	int32 ret;

	VDEC_ASSERT(dec_str_ctx);
	if (!dec_str_ctx)
		return IMG_ERROR_INVALID_PARAMETERS;

	OSA_PR_INFO("[USERSID=0x%08X] [TID=0x%08X] Preparing stream context after seek",
		dec_str_ctx->config.user_str_id,
		dec_str_ctx->last_fe_transaction_id);

	if (flush_dpb) {
		ret = decoder_stream_flush(dec_str_ctx, osa_true);
		VDEC_ASSERT(ret == IMG_SUCCESS);
		if (ret != IMG_SUCCESS)
			return ret;
	}

	/* Reset front-end temporary pointers */
	if (dec_str_ctx->prev_fe_pict_dec_res) {
		resource_item_return(&dec_str_ctx->prev_fe_pict_dec_res->ref_cnt);
		dec_str_ctx->prev_fe_pict_dec_res = NULL;
	}
	if (dec_str_ctx->cur_fe_pict_dec_res) {
		resource_item_return(&dec_str_ctx->cur_fe_pict_dec_res->ref_cnt);
		dec_str_ctx->cur_fe_pict_dec_res = NULL;
	}

	return IMG_SUCCESS;
}

/*
 * @Function  decoder_get_load
 */
int32 decoder_get_load(void *dec_str_ctx_arg, uint32 *avail_slots)
{
	struct dec_str_ctx *dec_str_ctx =
			decoder_stream_get_context(dec_str_ctx_arg);
	struct dec_core_ctx *dec_core_ctx_local = NULL;

	/* Check input parameters. */
	VDEC_ASSERT(dec_str_ctx);
	if (!dec_str_ctx || !avail_slots) {
		OSA_PR_ERR("Invalid parameters!");
		return IMG_ERROR_INVALID_PARAMETERS;
	}

	dec_core_ctx_local = decoder_str_ctx_to_core_ctx(dec_str_ctx);
	if(!dec_core_ctx_local)  {
		VDEC_ASSERT(0);
		return -OSA_EIO;
	}

	if (dec_core_ctx_local->busy)
		*avail_slots = 0;
	else
		*avail_slots = dec_str_ctx->avail_slots;

	return IMG_SUCCESS;
}

static int32 decoder_check_ref_errors(struct dec_str_ctx *dec_str_ctx,
				    struct vdecfw_buffer_control *buf_ctrl,
				    struct vdecdd_picture *picture)
{
	struct dec_decoded_pict *ref_pict;
	uint32 i;

	if (!dec_str_ctx) {
		VDEC_ASSERT(0);
		return IMG_ERROR_INVALID_PARAMETERS;
	}

	if (!buf_ctrl || !picture) {
		OSA_PR_ERR("[USERSID=0x%08X] Invalid parameters for checking reference lists.",
		       dec_str_ctx->config.user_str_id);
		VDEC_ASSERT(0);
		return IMG_ERROR_INVALID_PARAMETERS;
	}

	for (i = 0; i < VDECFW_MAX_NUM_PICTURES && buf_ctrl->ref_list[i];
	     i++) {
		ref_pict =
		decoder_get_decoded_pict_of_stream(GET_STREAM_PICTURE_ID(buf_ctrl->ref_list[i]),
						   &dec_str_ctx->str_decd_pict_list);
		if (ref_pict && ref_pict->pict &&
		    ref_pict->pict->dec_pict_info &&
		    ref_pict->pict->dec_pict_info->err_flags) {
			picture->dec_pict_info->err_flags |=
					VDEC_ERROR_CORRUPTED_REFERENCE;
			OSA_PR_WARN("Picture decoded using corrupted reference: 0x%08X 0x%08X",
				ref_pict->transaction_id,
				ref_pict->pict->dec_pict_info->err_flags);
		}
	}

	return IMG_SUCCESS;
}

static void decoder_clean_bitstr_segments(struct lst_t *decpict_seglist)
{
	struct dec_decpict_seg *dec_pict_seg;

	while (NULL != (dec_pict_seg = lst_removehead(decpict_seglist))) {
		if (dec_pict_seg->internal_seg) {
			VDEC_ASSERT(dec_pict_seg->bstr_seg);
			osa_free(dec_pict_seg->bstr_seg);
			dec_pict_seg->bstr_seg = NULL;
		}
		osa_free(dec_pict_seg);
	}
}

static int32 decoder_wrap_bitstr_segments(struct lst_t *bitstr_seglist,
					struct lst_t *decpict_seglist,
					uint32 user_str_id)
{
	/* Required for attaching segments to the decode picture */
	struct bspp_bitstr_seg	*bit_str_seg;
	struct dec_decpict_seg	*dec_pict_seg;

	VDEC_ASSERT(bitstr_seglist);
	VDEC_ASSERT(decpict_seglist);

	/* Add the segments to the Decode Picture */
	bit_str_seg = lst_first(bitstr_seglist);
	while (bit_str_seg) {
		dec_pict_seg = osa_zalloc(sizeof(*dec_pict_seg), OSA_GFP_KERNEL);
		VDEC_ASSERT(dec_pict_seg);
		if (!dec_pict_seg)
			return IMG_ERROR_OUT_OF_MEMORY;

		dec_pict_seg->bstr_seg = bit_str_seg;
		dec_pict_seg->internal_seg = osa_false;
		lst_add(decpict_seglist, dec_pict_seg);

		bit_str_seg = lst_next(bit_str_seg);
	}
	return IMG_SUCCESS;
}

/*
 * @Function decoder_picture_decode
 */
static int32
decoder_picture_decode(struct dec_str_ctx *dec_str_ctx,
		       struct vdecdd_str_unit *str_unit,
		       struct dec_decpict **dec_pict_ptr)
{
	struct vdecdd_picture *picture;
	struct dec_core_ctx *dec_core_ctx;
	struct dec_decpict *dec_pict;
	int32 ret = IMG_SUCCESS;
	struct decoder_regsoffsets regs_offsets;

	/* Validate input arguments */
	if((!dec_str_ctx) || (!str_unit) || (!str_unit->pict_hdr_info) || (!dec_pict_ptr)) {
		VDEC_ASSERT(0);
		return -OSA_EIO;
	}

	picture = (struct vdecdd_picture *)str_unit->dd_pict_data;
	dec_core_ctx = decoder_str_ctx_to_core_ctx(dec_str_ctx);

	if((!picture) || (!dec_core_ctx)) {
		VDEC_ASSERT(0);
		return IMG_ERROR_INVALID_PARAMETERS;
	}

	/* Ensure this is a new picture */
	VDEC_ASSERT(!dec_str_ctx->cur_pict);
	VDEC_ASSERT(str_unit->str_unit_type == VDECDD_STRUNIT_PICTURE_START);

	dec_core_ctx->cum_pics++;

	/* Allocate a unique id to the picture */
	ret = idgen_allocid(dec_str_ctx->pict_idgen, picture,
			    &picture->pict_id);
	VDEC_ASSERT(ret == IMG_SUCCESS);
	if (ret != IMG_SUCCESS)
		return ret;

	/* Allocate the decoded picture information structure. */
	picture->dec_pict_info = osa_zalloc(sizeof(*picture->dec_pict_info),
					 OSA_GFP_KERNEL);
	VDEC_ASSERT(picture->dec_pict_info);
	if (!picture->dec_pict_info)
		return IMG_ERROR_OUT_OF_MEMORY;

	/* Extract decoded information from the stream unit */
	picture->dec_pict_info->err_flags = str_unit->err_flags;
	picture->dec_pict_info->first_fld_tag_container.pict_tag_param =
		(uintptr_t)(str_unit->str_unit_tag);
	picture->dec_pict_info->op_config = picture->op_config;
	picture->dec_pict_info->rend_info = picture->disp_pict_buf.rend_info;
	picture->dec_pict_info->disp_info = str_unit->pict_hdr_info->disp_info;

	/* Extract aux picture information from the stream unit */
	picture->dec_pict_aux_info.seq_hdr_id =
					str_unit->seq_hdr_info->sequ_hdr_id;
	picture->dec_pict_aux_info.pps_id =
				str_unit->pict_hdr_info->pict_aux_data.id;
	picture->dec_pict_aux_info.second_pps_id =
			str_unit->pict_hdr_info->second_pict_aux_data.id;

	/* Create a new decoder picture container. */
	dec_pict = osa_zalloc(sizeof(*dec_pict), OSA_GFP_KERNEL);
	VDEC_ASSERT(dec_pict);
	if (!dec_pict) {
		ret = IMG_ERROR_OUT_OF_MEMORY;
		goto error_dec_pict;
	}

	/* Attach decoder/picture context information. */
	dec_pict->dec_str_ctx = dec_str_ctx;

	/*
	 * Construct the transaction Id.
	 * This consists of stream and core number in addition to picture
	 * number in stream and a 4-bit value representing the picture number
	 * in core.
	 */
	dec_pict->transaction_id =
		CREATE_TRANSACTION_ID(0, dec_str_ctx->km_str_id,
				      dec_core_ctx->cum_pics,
				      picture->pict_id);

	/* Add picture to core decode list */
	dec_str_ctx->dec_str_st.num_pict_decoding++;

	/* Fake a FW message to process when decoded. */
	dec_pict->first_fld_fwmsg = osa_zalloc(sizeof(*dec_pict->first_fld_fwmsg),
					    OSA_GFP_KERNEL);
	VDEC_ASSERT(dec_pict->first_fld_fwmsg);
	if (!dec_pict->first_fld_fwmsg) {
		ret = IMG_ERROR_OUT_OF_MEMORY;
		goto error_fw_msg;
	}

	dec_pict->second_fld_fwmsg =
		osa_zalloc(sizeof(*dec_pict->second_fld_fwmsg), OSA_GFP_KERNEL);
	VDEC_ASSERT(dec_pict->second_fld_fwmsg);
	if (!dec_pict->second_fld_fwmsg) {
		ret = IMG_ERROR_OUT_OF_MEMORY;
		goto error_fw_msg;
	}

	/* Add the segments to the Decode Picture */
	ret = decoder_wrap_bitstr_segments(&str_unit->bstr_seg_list,
					   &dec_pict->dec_pict_seg_list,
					   dec_str_ctx->config.user_str_id);

	VDEC_ASSERT(ret == IMG_SUCCESS);
	if (ret != IMG_SUCCESS)
		goto error_segments;

	/*
	 * Shuffle the current and previous
	 * Hold a reference to the last context on the FE
	 */
	if (dec_str_ctx->prev_fe_pict_dec_res) {
		/* Return previous last FW context. */
		resource_item_return(&dec_str_ctx->prev_fe_pict_dec_res->ref_cnt);

		if (resource_item_isavailable(&dec_str_ctx->prev_fe_pict_dec_res->ref_cnt)) {
			resource_list_remove(&dec_str_ctx->dec_res_lst, dec_str_ctx->prev_fe_pict_dec_res);
			resource_list_add(&dec_str_ctx->dec_res_lst,
					  dec_str_ctx->prev_fe_pict_dec_res, 0,
					  &dec_str_ctx->prev_fe_pict_dec_res->ref_cnt);
		}
	}

	dec_str_ctx->prev_fe_pict_dec_res = dec_str_ctx->cur_fe_pict_dec_res;
	dec_pict->prev_pict_dec_res = dec_str_ctx->prev_fe_pict_dec_res;

	/* Get a new stream decode resource bundle for current picture. */
	dec_pict->cur_pict_dec_res =
			resource_list_get_avail(&dec_str_ctx->dec_res_lst);
	VDEC_ASSERT(dec_pict->cur_pict_dec_res);
	if (!dec_pict->cur_pict_dec_res) {
		ret = IMG_ERROR_UNEXPECTED_STATE;
		goto error_dec_res;
	}

	if (dec_str_ctx->config.vid_std == VDEC_STD_H264) {
		/* Copy any SGM for current picture. */
		if (str_unit->pict_hdr_info->pict_sgm_data.id !=
		    BSPP_INVALID) {
			VDEC_ASSERT(str_unit->pict_hdr_info->pict_sgm_data.size <=
				    dec_pict->cur_pict_dec_res->h264_sgm_buf.buf_size);
			/* Updated in translation_api */
			memcpy(dec_pict->cur_pict_dec_res->h264_sgm_buf.cpu_virt,
			       str_unit->pict_hdr_info->pict_sgm_data.pic_data,
			       str_unit->pict_hdr_info->pict_sgm_data.size);
		}
	}

	dec_pict->cur_pict_dec_res->transaction_id = dec_pict->transaction_id;
	dec_str_ctx->cur_fe_pict_dec_res = dec_pict->cur_pict_dec_res;
	resource_item_use(&dec_str_ctx->cur_fe_pict_dec_res->ref_cnt);

	/* Get a new control buffer */
	dec_pict->pict_ref_res =
		resource_list_get_avail(&dec_str_ctx->ref_res_lst);
	VDEC_ASSERT(dec_pict->pict_ref_res);
	if (!dec_pict->pict_ref_res) {
		ret = IMG_ERROR_UNEXPECTED_STATE;
		goto error_ref_res;
	}

	VDEC_ASSERT(dec_str_ctx->decctx);
	VDEC_ASSERT(dec_str_ctx->decctx->dev_cfg);

	dec_pict->str_pvdec_fw_ctxbuf = &dec_str_ctx->pvdec_fw_ctx_buf;
	dec_pict->pict_hdr_info = str_unit->pict_hdr_info;

	/* Obtain (core) resources for the picture */
	ret = dec_res_picture_attach(&dec_str_ctx->resources,
				     dec_str_ctx->config.vid_std, dec_pict);
	VDEC_ASSERT(ret == IMG_SUCCESS);
	if (ret != IMG_SUCCESS)
		goto error_res_attach;

	/* Clear fw context data for re-use */
	memset(dec_pict->cur_pict_dec_res->fw_ctx_buf.cpu_virt, 0,
	       dec_pict->cur_pict_dec_res->fw_ctx_buf.buf_size);

	/*
	 * Clear the control data in case the picture is discarded before
	 * being prepared by firmware.
	 */
	memset(dec_pict->pict_ref_res->fw_ctrlbuf.cpu_virt, 0,
	       dec_pict->pict_ref_res->fw_ctrlbuf.buf_size);

	ret = hwctrl_getregsoffset(dec_core_ctx->hw_ctx, &regs_offsets);
	VDEC_ASSERT(ret == IMG_SUCCESS);
	if (ret != IMG_SUCCESS)
		goto error_other;

	ret = translation_ctrl_alloc_prepare(&dec_str_ctx->config, str_unit,
					     dec_pict,
					     &dec_core_ctx->core_props,
					     &regs_offsets);

	VDEC_ASSERT(ret == IMG_SUCCESS);
	if (ret != IMG_SUCCESS)
		goto error_other;

	ret = hwctrl_picture_submitbatch(dec_core_ctx->hw_ctx, dec_pict,
					 dec_str_ctx->vxd_dec_ctx);
	VDEC_ASSERT(ret == IMG_SUCCESS);
	if (ret != IMG_SUCCESS)
		goto error_other;

	VDEC_ASSERT(dec_str_ctx->avail_slots > 0);
	dec_str_ctx->avail_slots--;

	VDEC_ASSERT(!dec_core_ctx->busy);
	dec_core_ctx->busy = osa_true;
	/* Store this transaction ID in stream context */
	dec_str_ctx->last_fe_transaction_id = dec_pict->transaction_id;
	dec_str_ctx->cur_pict = (struct dec_decpict *)dec_pict;

	dec_str_ctx->dec_str_st.features = str_unit->features;

	if (str_unit->eop)
		dec_pict->eop_found = osa_true;

	*dec_pict_ptr = dec_pict;

	return IMG_SUCCESS;

	/* Roll back in case of errors. */
error_other:
	dec_res_picture_detach(&dec_str_ctx->resources, dec_pict);
error_res_attach:
error_ref_res:
error_dec_res:
error_segments:
	decoder_clean_bitstr_segments(&dec_pict->dec_pict_seg_list);
	osa_free(dec_pict->first_fld_fwmsg);
	osa_free(dec_pict->second_fld_fwmsg);
error_fw_msg:
	osa_free(dec_pict);
error_dec_pict:
	osa_free(picture->dec_pict_info);

	return ret;
}

/*
 * @Function decoder_stream_reference_resource_create
 */
static int32
decoder_stream_reference_resource_create(struct dec_str_ctx *dec_str_ctx)
{
	struct dec_pictref_res  *pict_ref_res;
	int32 ret;
	uint32 mem_heap_id;
	enum sys_emem_attrib mem_attribs;

	if((!dec_str_ctx) || (!dec_str_ctx->decctx)) {
		VDEC_ASSERT(0);
		return -OSA_EINVAL;
	}

	mem_heap_id = dec_str_ctx->decctx->internal_heap_id;
	mem_attribs = (enum sys_emem_attrib)(SYS_MEMATTRIB_UNCACHED | SYS_MEMATTRIB_WRITECOMBINE);
	mem_attribs |= (enum sys_emem_attrib)SYS_MEMATTRIB_INTERNAL;

	/* Allocate the firmware context buffer info structure. */
	pict_ref_res = osa_zalloc(sizeof(*pict_ref_res), OSA_GFP_KERNEL);
	VDEC_ASSERT(pict_ref_res);
	if (!pict_ref_res)
		return IMG_ERROR_OUT_OF_MEMORY;

	/*
	 * Allocate the firmware context buffer to contain data required for
	 * subsequent picture.
	 */

	OSA_PR_INFO("%s:%d calling MMU_StreamMalloc", __func__, __LINE__);
	ret = mmu_stream_alloc(dec_str_ctx->mmu_str_handle,
			       MMU_HEAP_STREAM_BUFFERS, mem_heap_id,
			       (enum sys_emem_attrib)(mem_attribs | SYS_MEMATTRIB_CPU_READ |
			       SYS_MEMATTRIB_CPU_WRITE),
			       sizeof(struct vdecfw_buffer_control),
			       DEV_MMU_PAGE_ALIGNMENT,
			       &pict_ref_res->fw_ctrlbuf);
	VDEC_ASSERT(ret == IMG_SUCCESS);
	if (ret != IMG_SUCCESS)
		goto err_out_of_memory;

	/*
	 * Clear the context data in preparation for first time use by
	 * the firmware.
	 */
	memset(pict_ref_res->fw_ctrlbuf.cpu_virt, 0,
	       pict_ref_res->fw_ctrlbuf.buf_size);

	pict_ref_res->ref_cnt = 1;

	ret = resource_list_add(&dec_str_ctx->ref_res_lst, pict_ref_res, 0,
				&pict_ref_res->ref_cnt);
	if (ret != IMG_SUCCESS) {
		OSA_PR_ERR("[USERSID=0x%08X] Failed to add resource",
		       dec_str_ctx->config.user_str_id);
		return ret;
	}

	return IMG_SUCCESS;

err_out_of_memory:

	osa_free(pict_ref_res);
	pict_ref_res = NULL;

	OSA_PR_ERR("[USERSID=0x%08X] Failed to allocate device memory for stream reference resources",
	       dec_str_ctx->config.user_str_id);

	return IMG_ERROR_OUT_OF_MEMORY;
}

/*
 * @Function  decoder_picture_finalize
 */
static int32 decoder_picture_finalize(struct dec_str_ctx *dec_str_ctx,
				    struct vdecdd_str_unit *str_unit)
{
	struct dec_decpict *dec_pict;
	struct dec_core_ctx *dec_core_ctx = NULL;

	VDEC_ASSERT(dec_str_ctx);

	dec_pict = dec_str_ctx->cur_pict;
	if (!dec_pict) {
		OSA_PR_ERR("[USERSID=0x%08X] Unable to get the current picture from Decoder context",
		       dec_str_ctx->config.user_str_id);
		return IMG_ERROR_GENERIC_FAILURE;
	}

	dec_core_ctx = decoder_str_ctx_to_core_ctx(dec_str_ctx);

	if((!dec_core_ctx) || (!dec_core_ctx->busy)) {
		VDEC_ASSERT(0);
		return -OSA_EINVAL;
	}

	dec_core_ctx->busy = osa_false;

	/* Picture data are now complete, nullify pointer */
	dec_str_ctx->cur_pict = NULL;

	return IMG_SUCCESS;
}

/*
 * @Function  decoder_submit_fragment
 */
static int32 decoder_submit_fragment(struct dec_str_ctx *dec_str_context,
				   struct vdecdd_str_unit *str_unit, osa_bool eop)
{
	struct dec_core_ctx *dec_core_context = NULL;
	struct lst_t dec_fragment_seg_list;
	struct dec_decpict_seg *dec_pict_seg;
	struct dec_pict_fragment *pict_fragment;
	int32 ret = IMG_SUCCESS;

	if (!dec_str_context) {
		VDEC_ASSERT(0);
		return IMG_ERROR_GENERIC_FAILURE;
	}

	if (!dec_str_context->cur_pict) {
		OSA_PR_ERR("[USERSID=0x%08X] Unable to get the current picture from Decoder context",
		       dec_str_context->config.user_str_id);
		VDEC_ASSERT(0);
		return IMG_ERROR_GENERIC_FAILURE;
	}

	dec_core_context = decoder_str_ctx_to_core_ctx(dec_str_context);
	if(!dec_core_context)
	{
		VDEC_ASSERT(0);
		return IMG_ERROR_GENERIC_FAILURE;
	}

	pict_fragment = osa_zalloc(sizeof(*pict_fragment), OSA_GFP_KERNEL);
	VDEC_ASSERT(pict_fragment);
	if (!pict_fragment)
		return IMG_ERROR_OUT_OF_MEMORY;

	lst_init(&dec_fragment_seg_list);

	/* Add the segments to the temporary list */
	ret = decoder_wrap_bitstr_segments(&str_unit->bstr_seg_list,
					   &dec_fragment_seg_list,
					   dec_str_context->config.user_str_id);
	VDEC_ASSERT(ret == IMG_SUCCESS);
	if (ret != IMG_SUCCESS)
		goto error;

	/* Prepare ctr alloc for the fragment */
	ret = translation_fragment_prepare(dec_str_context->cur_pict,
					   &dec_fragment_seg_list, eop,
					   pict_fragment);
	VDEC_ASSERT(ret == IMG_SUCCESS);
	if (ret != IMG_SUCCESS)
		goto error;

	/*
	 * Move segments of the fragment from the temporary list to the picture
	 * segment list
	 */
	dec_pict_seg = lst_removehead(&dec_fragment_seg_list);
	while (dec_pict_seg) {
		lst_add(&dec_str_context->cur_pict->dec_pict_seg_list,
			dec_pict_seg);
		dec_pict_seg = lst_removehead(&dec_fragment_seg_list);
	}

	/* Submit fragment */
	ret = hwctrl_picture_submit_fragment(dec_core_context->hw_ctx,
					     pict_fragment,
					     dec_str_context->cur_pict,
					     dec_str_context->vxd_dec_ctx);
	VDEC_ASSERT(ret == IMG_SUCCESS);
	if (ret != IMG_SUCCESS)
		goto error;

	lst_add(&dec_str_context->cur_pict->fragment_list, pict_fragment);

	if (eop)
		dec_str_context->cur_pict->eop_found = osa_true;

	OSA_PR_INFO("[USERSID=0x%08X] [TID=0x%08X] FRAGMENT",
		dec_str_context->config.user_str_id,
		dec_str_context->last_fe_transaction_id);

	return IMG_SUCCESS;
error:
	osa_free(pict_fragment);

	return ret;
}

/*
 * @Function  decoder_stream_process_unit
 */
int32 decoder_stream_process_unit(void *dec_str_ctx_arg,
				struct vdecdd_str_unit *str_unit)
{
	struct dec_str_ctx *dec_str_ctx =
			decoder_stream_get_context(dec_str_ctx_arg);

	struct dec_str_unit *dec_str_unit;
	struct dec_decpict *dec_pict = NULL;
	uint8 processed = osa_false;
	int32 ret;

	VDEC_ASSERT(dec_str_ctx);
	VDEC_ASSERT(str_unit);

	if (!dec_str_ctx || !str_unit) {
		OSA_PR_ERR("Invalid decoder stream context handle!\n");
		return IMG_ERROR_INVALID_PARAMETERS;
	}
	OSA_PR_DEBUG("%s : stream unit type = %d\n"
		     ,__func__, str_unit->str_unit_type);
	/* Process the stream unit */
	switch (str_unit->str_unit_type) {
	case VDECDD_STRUNIT_SEQUENCE_END:
	case VDECDD_STRUNIT_ANONYMOUS:
	case VDECDD_STRUNIT_CLOSED_GOP:
	case VDECDD_STRUNIT_PICTURE_PORTENT:
	case VDECDD_STRUNIT_FENCE:
		/* Nothing more to do so mark the stream unit as processed */
		processed = osa_true;
		break;

	case VDECDD_STRUNIT_STOP:
		if (dec_str_ctx->cur_pict &&
		    !dec_str_ctx->cur_pict->eop_found) {
			ret = decoder_submit_fragment(dec_str_ctx, str_unit,
						      osa_true);
			VDEC_ASSERT(ret == IMG_SUCCESS);
			if (ret != IMG_SUCCESS)
				return ret;

			ret = decoder_picture_finalize(dec_str_ctx, str_unit);
			VDEC_ASSERT(ret == IMG_SUCCESS);
			if (ret != IMG_SUCCESS)
				return ret;

			OSA_PR_INFO("[USERSID=0x%08X] [TID=0x%08X] FORCED END",
				dec_str_ctx->config.user_str_id,
				dec_str_ctx->last_fe_transaction_id);
		}

		processed = osa_true;
		break;

	case VDECDD_STRUNIT_SEQUENCE_START:
		{
		uint32 max_num_activ_pict = 0;

		VDEC_ASSERT(str_unit->seq_hdr_info);
		/*
		 * Determine how many decoded pictures can be held for
		 * reference in the decoder for this stream.
		 */
		ret = vdecddutils_ref_pict_get_maxnum(&dec_str_ctx->config,
						      &str_unit->seq_hdr_info->com_sequ_hdr_info,
						      &max_num_activ_pict);
		if (ret != IMG_SUCCESS)
			return ret;

		/* Double for field coding */
		max_num_activ_pict *= 2;

		/*
		 * Ensure that there are enough resource to have pictures
		 * filling all slots on all cores.
		 */
		max_num_activ_pict +=
			dec_str_ctx->decctx->dev_cfg->num_slots_per_pipe *
			dec_str_ctx->decctx->num_pipes;

		/* Increase decoder stream resources if necessary. */
		while (dec_str_ctx->num_ref_res < max_num_activ_pict) {
			ret = decoder_stream_reference_resource_create(dec_str_ctx);
			VDEC_ASSERT(ret == IMG_SUCCESS);
			if (ret != IMG_SUCCESS)
				return ret;

			dec_str_ctx->num_ref_res++;
		}

		/* Nothing more to do so mark the stream unit as processed */
		processed = osa_true;
		break;
		}

	case VDECDD_STRUNIT_PICTURE_START:
		if (str_unit->decode) {
			/* Prepare and submit picture to decode. */
			ret = decoder_picture_decode(dec_str_ctx,
						     str_unit, &dec_pict);
			VDEC_ASSERT(ret == IMG_SUCCESS);
			if (ret != IMG_SUCCESS)
				return ret;

			OSA_PR_INFO("[USERSID=0x%08X] [TID=0x%08X] START",
				dec_str_ctx->config.user_str_id,
				dec_str_ctx->last_fe_transaction_id);
			} else {
				processed = osa_true;
		}
		break;

	case VDECDD_STRUNIT_PICTURE_END:
		if (str_unit->decode) {
			ret = decoder_picture_finalize(dec_str_ctx, str_unit);
			VDEC_ASSERT(ret == IMG_SUCCESS);
			if (ret != IMG_SUCCESS)
				return ret;
			OSA_PR_INFO("[USERSID=0x%08X] [TID=0x%08X] END",
				dec_str_ctx->config.user_str_id,
				dec_str_ctx->last_fe_transaction_id);
		} else {
			processed = osa_true;
		}
		break;

	default:
		VDEC_ASSERT(osa_false);
		break;
	}

	/*
	 * If this or any preceding stream unit(s) could not be
	 * completely processed, add this unit to the queue.
	 */
	if (!processed) {
		/* Add unit to stream decode list */
		dec_str_unit = osa_zalloc(sizeof(*dec_str_unit), OSA_GFP_KERNEL);
		VDEC_ASSERT(dec_str_unit);
		if (!dec_str_unit)
			return IMG_ERROR_OUT_OF_MEMORY;

		dec_str_unit->str_unit = str_unit;

		/* make PICTURE_START owner of dec_pict */
		if (dec_pict) {
			VDEC_ASSERT(str_unit->str_unit_type == VDECDD_STRUNIT_PICTURE_START);
			dec_str_unit->dec_pict = dec_pict;
		}

		lst_add(&dec_str_ctx->pend_strunit_list, dec_str_unit);
	} else {
		/*
		 * If there is nothing being decoded for this stream,
		 * immediately handle the unit (non-picture so doesn't need
		 * decoding). Report that this unit has been processed.
		 */
		VDEC_ASSERT(dec_str_ctx->decctx);
		ret = dec_str_ctx->str_processed_cb(dec_str_ctx->usr_int_data,
						    VXD_CB_STRUNIT_PROCESSED,
						    str_unit);
		VDEC_ASSERT(ret == IMG_SUCCESS);
		if (ret != IMG_SUCCESS)
			return ret;
	}

	return IMG_SUCCESS;
}

static int32
decoder_get_required_core_features(const struct vdec_str_configdata *str_cfg,
				   const struct vdec_str_opconfig *op_cfg,
				   uint32 *features)
{
	uint32 features_local = 0;

	VDEC_ASSERT(str_cfg);
	VDEC_ASSERT(features);

	/* Check Video Standard. */
	switch (str_cfg->vid_std) {
	case VDEC_STD_H264:
		features_local = VDECDD_COREFEATURE_H264;
		break;
#ifdef HAS_JPEG
	case VDEC_STD_JPEG:
		features_local = VDECDD_COREFEATURE_JPEG;
		break;
#endif
#ifdef HAS_HEVC
	case VDEC_STD_HEVC:
		features_local = VDECDD_COREFEATURE_HEVC;
		break;
#endif
	default:
		VDEC_ASSERT(osa_false);
		break;
	}

	*features = features_local;

	return IMG_SUCCESS;
}

/*
 * @Function  decoder_is_supported_by_atleast_onepipe
 */
static uint8 decoder_is_supported_by_atleast_onepipe(uint8 *features, uint32 num_pipes)
{
	uint32 i;

	VDEC_ASSERT(features);
	VDEC_ASSERT(num_pipes <= VDEC_MAX_PIXEL_PIPES);

	for (i = 0; i < num_pipes; i++) {
		if (features[i])
			return osa_true;
	}

	return osa_false;
}

/*
 * @Function  decoder_check_support
 */
int32
decoder_check_support(void *dec_ctx_arg,
		      const struct vdec_str_configdata *str_cfg,
		      const struct vdec_str_opconfig *str_op_cfg,
		      const struct vdecdd_ddpict_buf *disp_pict_buf,
		      const struct vdec_pict_rendinfo *req_pict_rendinfo,
		      const struct vdec_comsequ_hdrinfo *comseq_hdrinfo,
		      const struct bspp_pict_hdr_info *pict_hdrinfo,
		      const struct vdec_comsequ_hdrinfo *prev_comseq_hdrinfo,
		      const struct bspp_pict_hdr_info *prev_pict_hdrinfo,
		      uint8 non_cfg_req, struct vdec_unsupp_flags *unsupported,
		      uint32 *features)
{
	struct dec_ctx *dec_ctx = (struct dec_ctx *)dec_ctx_arg;
	struct dec_core_ctx *dec_core_ctx;
	struct vxd_coreprops *core_props;
	const struct vdec_pict_rendinfo *disp_pict_rendinfo = NULL;
	int32 ret = IMG_ERROR_NOT_SUPPORTED;

	/* Ensure input parameters are valid. */
	VDEC_ASSERT(dec_ctx_arg);
	VDEC_ASSERT(str_cfg);
	VDEC_ASSERT(unsupported);

	if (!dec_ctx_arg || !str_cfg || !unsupported) {
		OSA_PR_ERR("Invalid parameters!");
		return IMG_ERROR_INVALID_PARAMETERS;
	}

	if (disp_pict_buf)
		disp_pict_rendinfo = &disp_pict_buf->rend_info;

	/*
	 * Validate compatibility between the supplied configuration/state
	 * and the master core only at the moment (assumed to have superset
	 * of features).
	 * Some features may not be present on any slave cores which might
	 * cause poor utilisation of hardware.
	 */
	memset(unsupported, 0, sizeof(*unsupported));

	dec_core_ctx = dec_ctx->dec_core_ctx;
	VDEC_ASSERT(dec_core_ctx);

	core_props = &dec_core_ctx->core_props;
	VDEC_ASSERT(core_props);

		/* Check that the video standard is supported */
		switch (str_cfg->vid_std) {
		case VDEC_STD_H264:
			if (!decoder_is_supported_by_atleast_onepipe(core_props->h264,
								     core_props->num_pixel_pipes)) {
				OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[HW]: VIDEO STANDARD (H.264)",
					str_cfg->user_str_id);
				unsupported->str_cfg |=
					VDECDD_UNSUPPORTED_STRCONFIG_STD;
			}

			if (comseq_hdrinfo &&
			    (H264_PROFILE_MVC_HIGH ==
			     comseq_hdrinfo->codec_profile ||
			     H264_PROFILE_MVC_STEREO ==
			     comseq_hdrinfo->codec_profile) &&
			   comseq_hdrinfo->num_views >
			   VDEC_H264_MVC_MAX_VIEWS) {
				OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[SW]: NUMBER OF VIEWS",
					str_cfg->user_str_id);
				unsupported->seq_hdr |=
				VDECDD_UNSUPPORTED_SEQUHDR_NUM_OF_VIEWS;
			}
			break;
#ifdef HAS_HEVC
		case VDEC_STD_HEVC:
			if (!decoder_is_supported_by_atleast_onepipe(core_props->hevc, core_props->num_pixel_pipes)) {
				OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[HW]: VIDEO STANDARD (HEVC)",
					str_cfg->user_str_id);
				unsupported->str_cfg |= VDECDD_UNSUPPORTED_STRCONFIG_STD;
			}
			if (pict_hdrinfo && pict_hdrinfo->hevc_pict_hdr_info.range_ext_present)
				if ((pict_hdrinfo->hevc_pict_hdr_info.is_full_range_ext &&
				     !decoder_is_supported_by_atleast_onepipe(core_props->hevc_range_ext,
									      core_props->num_pixel_pipes)) ||
				    (!pict_hdrinfo->hevc_pict_hdr_info.is_full_range_ext &&
				     core_props->vidstd_props[str_cfg->vid_std].max_chroma_format == PIXEL_FORMAT_420)) {
					OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[HW]: HEVC RANGE EXTENSIONS",
						str_cfg->user_str_id);
					unsupported->pict_hdr |= VDECDD_UNSUPPORTED_PICTHDR_HEVC_RANGE_EXT;
			}
			break;
#endif
#ifdef HAS_JPEG
		case VDEC_STD_JPEG:
			if (!decoder_is_supported_by_atleast_onepipe(core_props->jpeg,
								     core_props->num_pixel_pipes)) {
				OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[HW]: VIDEO STANDARD (JPEG)",
					str_cfg->user_str_id);
				unsupported->str_cfg |=
					VDECDD_UNSUPPORTED_STRCONFIG_STD;
			}
			break;
#endif
		default:
			OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[HW]: VIDEO STANDARD (UNKNOWN)",
				str_cfg->user_str_id);
			unsupported->str_cfg |=
				VDECDD_UNSUPPORTED_STRCONFIG_STD;
			break;
		}

	if (str_op_cfg) {
		/*
		 * Ensure that each display feature is supported by the
		 * hardware.
		 */
		if (comseq_hdrinfo) {
			/* Validate display pixel format */
			if (non_cfg_req &&
			    prev_comseq_hdrinfo &&
			    vdec_size_nz(prev_comseq_hdrinfo->frame_size) &&
			    prev_comseq_hdrinfo->pixel_info.chroma_fmt_idc ==
			    str_op_cfg->pixel_info.chroma_fmt_idc &&
			    comseq_hdrinfo->pixel_info.chroma_fmt_idc !=
			    prev_comseq_hdrinfo->pixel_info.chroma_fmt_idc) {
				/*
				 * If this is a non-configuration request and
				 * it looks like a new sequence with
				 * sub-sampling change, just indicate output
				 * format mismatch without any error messages.
				 */
				unsupported->str_opcfg |=
				VDECDD_UNSUPPORTED_OUTPUTCONFIG_PIXFORMAT;
			} else {
				switch (str_op_cfg->pixel_info.chroma_fmt_idc) {
				case PIXEL_FORMAT_420:
					if (comseq_hdrinfo->pixel_info.chroma_fmt_idc ==
					   PIXEL_FORMAT_MONO) {
						OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[HW]: TRANSFORM PIXEL FORMAT FROM 400 TO 420",
							str_cfg->user_str_id);
						unsupported->str_opcfg |=
						VDECDD_UNSUPPORTED_OUTPUTCONFIG_PIXFORMAT;
					}
					break;

				case PIXEL_FORMAT_422:
					if (comseq_hdrinfo->pixel_info.chroma_fmt_idc ==
					   PIXEL_FORMAT_420) {
						if (str_op_cfg->pixel_info.num_planes > 1) {
							OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[HW]: REQUESTED NUMBER OF PLANES FOR 422 UPSAMPLING",
								str_cfg->user_str_id);
							unsupported->str_opcfg |=
								VDECDD_UNSUPPORTED_OUTPUTCONFIG_PIXFORMAT;
						}
					} else if (comseq_hdrinfo->pixel_info.chroma_fmt_idc ==
						  PIXEL_FORMAT_MONO) {
						OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[HW]: TRANSFORM PIXEL FORMAT FROM 400 TO 422",
							str_cfg->user_str_id);
						unsupported->str_opcfg |=
								VDECDD_UNSUPPORTED_OUTPUTCONFIG_PIXFORMAT;
					}
					break;

				default:
					break;
				}
			}
		}

		if (str_op_cfg->pixel_info.bitdepth_y >
		     core_props->vidstd_props[str_cfg->vid_std].max_luma_bitdepth ||
		     str_op_cfg->pixel_info.bitdepth_y < 8 ||
		     str_op_cfg->pixel_info.bitdepth_y == 9) {
			OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[HW]: DISPLAY PICTURE LUMA BIT DEPTH %d [RANGE: 8->%d for %s]",
				str_cfg->user_str_id,
				str_op_cfg->pixel_info.bitdepth_y,
				core_props->vidstd_props[str_cfg->vid_std].max_luma_bitdepth,
				vid_std_names[str_cfg->vid_std]);
			unsupported->str_opcfg |=
				VDECDD_UNSUPPORTED_OUTPUTCONFIG_PIXFORMAT;
		}

		if (str_op_cfg->pixel_info.chroma_fmt_idc !=
		    PIXEL_FORMAT_MONO &&
		    (str_op_cfg->pixel_info.bitdepth_c >
		    core_props->vidstd_props[str_cfg->vid_std].max_chroma_bitdepth ||
		    str_op_cfg->pixel_info.bitdepth_c < 8 ||
		    str_op_cfg->pixel_info.bitdepth_c == 9)) {
			OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[HW]: DISPLAY PICTURE CHROMA BIT DEPTH %d [RANGE: 8->%d for %s]",
				str_cfg->user_str_id,
				str_op_cfg->pixel_info.bitdepth_c,
				core_props->vidstd_props[str_cfg->vid_std].max_chroma_bitdepth,
				vid_std_names[str_cfg->vid_std]);
			unsupported->str_opcfg |=
				VDECDD_UNSUPPORTED_OUTPUTCONFIG_PIXFORMAT;
		}

#ifdef HAS_JPEG
		/* Validate display configuration against existing stream configuration.*/
		if (str_cfg->vid_std == VDEC_STD_JPEG) {
			if (str_op_cfg->force_oold) {
				OSA_PR_ERR("[USERSID=0x%08X] UNSUPPORTED[HW]: OOLD WITH JPEG \n",
						str_cfg->user_str_id);
				unsupported->str_opcfg |= VDECDD_UNSUPPORTED_OUTPUTCONFIG_X_WITH_JPEG;
			}
		}
#endif
	}

	if (disp_pict_rendinfo) {
		uint32 stride_alignment = VDEC_VXD_EXT_STRIDE_ALIGNMENT_DEFAULT;

		if (req_pict_rendinfo) {
			/*
			 * Picture size declared in buffer must be at least as
			 * large as that required by bitstream/output config.
			 */
			if (!vdec_size_ge(disp_pict_rendinfo->rend_pict_size,
					  req_pict_rendinfo->rend_pict_size)) {
				OSA_PR_WARN("[USERSID=0x%08X] Picture size of output picture buffer [%d x %d] is not large enough for sequence [%d x %d]",
					str_cfg->user_str_id,
					disp_pict_rendinfo->rend_pict_size.width,
					disp_pict_rendinfo->rend_pict_size.height,
					req_pict_rendinfo->rend_pict_size.width,
					req_pict_rendinfo->rend_pict_size.height);
				unsupported->str_opcfg |=
					VDECDD_UNSUPPORTED_OUTPUTBUFCONFIG_PICTURE_SIZE;
			}

			/*
			 * Size of each plane must be at least as large
			 * as that required.
			 */
			if (disp_pict_rendinfo->plane_info[VDEC_PLANE_VIDEO_Y].size <
			    req_pict_rendinfo->plane_info[VDEC_PLANE_VIDEO_Y].size) {
				OSA_PR_WARN("[USERSID=0x%08X] Y plane of output picture buffer [%d bytes] is not large enough for bitstream/config [%d bytes]",
					str_cfg->user_str_id,
					disp_pict_rendinfo->plane_info[VDEC_PLANE_VIDEO_Y].size,
					req_pict_rendinfo->plane_info[VDEC_PLANE_VIDEO_Y].size);
				unsupported->op_bufcfg |=
					VDECDD_UNSUPPORTED_OUTPUTBUFCONFIG_Y_SIZE;
			}

			/*
			 * Stride of each plane must be at least as large as that
			 * required.
			 */
			if (disp_pict_rendinfo->plane_info[VDEC_PLANE_VIDEO_Y].stride <
			    req_pict_rendinfo->plane_info[VDEC_PLANE_VIDEO_Y].stride) {
				OSA_PR_WARN("[USERSID=0x%08X] Y stride of output picture buffer [%d bytes] is not large enough for bitstream/config [%d bytes]",
					str_cfg->user_str_id,
					disp_pict_rendinfo->plane_info[VDEC_PLANE_VIDEO_Y].stride,
					req_pict_rendinfo->plane_info[VDEC_PLANE_VIDEO_Y].stride);
				unsupported->op_bufcfg |=
					VDECDD_UNSUPPORTED_OUTPUTBUFCONFIG_Y_STRIDE;
			}

			/*
			 * Size of each plane must be at least
			 * as large as that required.
			 */
			if (disp_pict_rendinfo->plane_info[VDEC_PLANE_VIDEO_UV].size <
			    req_pict_rendinfo->plane_info[VDEC_PLANE_VIDEO_UV].size) {
				OSA_PR_WARN("[USERSID=0x%08X] UV plane of output picture buffer [%d bytes] is not large enough for bitstream/config [%d bytes]",
					str_cfg->user_str_id,
					disp_pict_rendinfo->plane_info[VDEC_PLANE_VIDEO_UV].size,
					req_pict_rendinfo->plane_info[VDEC_PLANE_VIDEO_UV].size);
				unsupported->op_bufcfg |=
					VDECDD_UNSUPPORTED_OUTPUTBUFCONFIG_UV_SIZE;
			}

			/*
			 * Stride of each plane must be at least
			 * as large as that required.
			 */
			if (disp_pict_rendinfo->plane_info[VDEC_PLANE_VIDEO_UV].stride <
			    req_pict_rendinfo->plane_info[VDEC_PLANE_VIDEO_UV].stride) {
				OSA_PR_WARN("[USERSID=0x%08X] UV stride of output picture buffer [%d bytes] is not large enough for bitstream/config [%d bytes]",
					str_cfg->user_str_id,
				disp_pict_rendinfo->plane_info[VDEC_PLANE_VIDEO_UV].stride,
				req_pict_rendinfo->plane_info[VDEC_PLANE_VIDEO_UV].stride);
				unsupported->op_bufcfg |=
					VDECDD_UNSUPPORTED_OUTPUTBUFCONFIG_UV_STRIDE;
			}

			if ((req_pict_rendinfo->stride_alignment &
			    (VDEC_VXD_EXT_STRIDE_ALIGNMENT_DEFAULT - 1)) != 0) {
				OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[HW]: STRIDE ALIGNMENT [%d] must be a multiple of %d bytes",
					str_cfg->user_str_id,
					req_pict_rendinfo->stride_alignment,
					VDEC_VXD_EXT_STRIDE_ALIGNMENT_DEFAULT);
				unsupported->op_bufcfg |=
					VDECDD_UNSUPPORTED_OUTPUTBUFCONFIG_64BYTE_STRIDE;
			}

			if (req_pict_rendinfo->stride_alignment > 0)
				stride_alignment = req_pict_rendinfo->stride_alignment;
		}

		if ((disp_pict_rendinfo->plane_info[VDEC_PLANE_VIDEO_Y].stride % stride_alignment) != 0) {
			OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[HW]: Y STRIDE [%d] must be a multiple of %d bytes",
				str_cfg->user_str_id,
				disp_pict_rendinfo->plane_info[VDEC_PLANE_VIDEO_Y].stride,
				stride_alignment);
			unsupported->op_bufcfg |=
				VDECDD_UNSUPPORTED_OUTPUTBUFCONFIG_64BYTE_STRIDE;
		}

		if ((disp_pict_rendinfo->plane_info[VDEC_PLANE_VIDEO_UV].stride % stride_alignment) != 0) {
			OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[HW]: UV STRIDE [%d] must be a multiple of %d bytes",
				str_cfg->user_str_id,
				disp_pict_rendinfo->plane_info[VDEC_PLANE_VIDEO_UV].stride,
				stride_alignment);
			unsupported->op_bufcfg |=
				VDECDD_UNSUPPORTED_OUTPUTBUFCONFIG_64BYTE_STRIDE;
		}

		if ((disp_pict_rendinfo->plane_info[VDEC_PLANE_VIDEO_V].stride % stride_alignment) != 0) {
			OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[HW]: V STRIDE [%d] must be a multiple of %d bytes",
				str_cfg->user_str_id,
				disp_pict_rendinfo->plane_info[VDEC_PLANE_VIDEO_V].stride,
				stride_alignment);
			unsupported->op_bufcfg |=
				VDECDD_UNSUPPORTED_OUTPUTBUFCONFIG_64BYTE_STRIDE;
		}

		if (req_pict_rendinfo) {
			if (str_op_cfg) {
				if (str_cfg->vid_std != VDEC_STD_JPEG) {
				if (str_op_cfg->pixel_info.num_planes <= 2)
					/*
					 * V plane only required when chroma is
					 * separated.
					 */
					VDEC_ASSERT(req_pict_rendinfo->plane_info[VDEC_PLANE_VIDEO_V].size ==
						    0);

				if (str_op_cfg->pixel_info.num_planes <= 3)
					/* Alpha planes should not be required. */
					VDEC_ASSERT(req_pict_rendinfo->plane_info[VDEC_PLANE_VIDEO_A].size ==
						    0);
				}
			}

			/* Size of buffer must be at least as large as that required. */
			if (disp_pict_rendinfo->rendered_size <
			    req_pict_rendinfo->rendered_size) {
				OSA_PR_WARN("[USERSID=0x%08X] Output picture buffer [%d bytes] is not large enough for bitstream/config [%d bytes]",
					str_cfg->user_str_id,
					disp_pict_rendinfo->rendered_size,
					req_pict_rendinfo->rendered_size);
				unsupported->op_bufcfg |=
					VDECDD_UNSUPPORTED_OUTPUTBUFCONFIG_BUFFER_SIZE;
			}
		}

		if (str_op_cfg) {
			if (comseq_hdrinfo) {
				if (vdec_size_lt(disp_pict_rendinfo->rend_pict_size,
						 comseq_hdrinfo->max_frame_size)) {
					OSA_PR_WARN("[USERSID=0x%08X] Buffers [%d x %d] must be large enough to contain the maximum frame size [%d x %d] when not scaling",
						str_cfg->user_str_id,
						disp_pict_rendinfo->rend_pict_size.width,
						disp_pict_rendinfo->rend_pict_size.height,
						comseq_hdrinfo->max_frame_size.width,
						comseq_hdrinfo->max_frame_size.height);
					unsupported->op_bufcfg |=
					VDECDD_UNSUPPORTED_OUTPUTBUFCONFIG_PICTURE_SIZE;
				}
			}
		}
	}

	if (comseq_hdrinfo) {
		uint32 max_width =
		vdec_size_min(core_props->vidstd_props[str_cfg->vid_std].max_width,
			      MAX_PLATFORM_SUPPORTED_WIDTH);

		uint32 max_height =
		vdec_size_min(core_props->vidstd_props[str_cfg->vid_std].max_height,
			      MAX_PLATFORM_SUPPORTED_HEIGHT);

		if (comseq_hdrinfo->max_frame_size.width > max_width ||
		    comseq_hdrinfo->max_frame_size.height > max_height) {
			OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[HW]: FRAME WIDTH %dpx or HEIGHT %dpx are over maximum allowed value [%d, %d]",
				str_cfg->user_str_id,
				comseq_hdrinfo->max_frame_size.width,
				comseq_hdrinfo->max_frame_size.height,
				max_width, max_height);
			unsupported->seq_hdr |=
				VDECDD_UNSUPPORTED_SEQUHDR_SIZE;
		}

		if (comseq_hdrinfo->pixel_info.bitdepth_y >
		    core_props->vidstd_props[str_cfg->vid_std].max_luma_bitdepth ||
		    comseq_hdrinfo->pixel_info.bitdepth_y < 8 ||
		    comseq_hdrinfo->pixel_info.bitdepth_y == 9) {
			OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[HW]: CODED PICTURE LUMA BIT DEPTH %d [RANGE: 8->%d for %s]",
				str_cfg->user_str_id,
				comseq_hdrinfo->pixel_info.bitdepth_y,
				core_props->vidstd_props[str_cfg->vid_std].max_luma_bitdepth,
				vid_std_names[str_cfg->vid_std]);
			unsupported->seq_hdr |=
				VDECDD_UNSUPPORTED_SEQUHDR_PIXFORMAT_BIT_DEPTH;
		}

		if (comseq_hdrinfo->pixel_info.chroma_fmt_idc !=
		    PIXEL_FORMAT_MONO &&
		    (comseq_hdrinfo->pixel_info.bitdepth_c >
		     core_props->vidstd_props[str_cfg->vid_std].max_chroma_bitdepth ||
		     comseq_hdrinfo->pixel_info.bitdepth_c < 8 ||
		     comseq_hdrinfo->pixel_info.bitdepth_c == 9)) {
			OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[HW]: CODED PICTURE CHROMA BIT DEPTH %d [RANGE: 8->%d for %s]",
				str_cfg->user_str_id,
				comseq_hdrinfo->pixel_info.bitdepth_c,
				core_props->vidstd_props[str_cfg->vid_std].max_chroma_bitdepth,
				vid_std_names[str_cfg->vid_std]);
			unsupported->seq_hdr |=
				VDECDD_UNSUPPORTED_SEQUHDR_PIXFORMAT_BIT_DEPTH;
		}

		if (comseq_hdrinfo->pixel_info.chroma_fmt_idc !=
		    PIXEL_FORMAT_MONO &&
		    comseq_hdrinfo->pixel_info.bitdepth_y !=
		    comseq_hdrinfo->pixel_info.bitdepth_c) {
			OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[HW]: CODED PICTURE MIXED BIT DEPTH [%d vs %d]",
				str_cfg->user_str_id,
				comseq_hdrinfo->pixel_info.bitdepth_y,
				comseq_hdrinfo->pixel_info.bitdepth_c);
			unsupported->seq_hdr |=
				VDECDD_UNSUPPORTED_SEQUHDR_PIXFORMAT_BIT_DEPTH;
		}

		if (comseq_hdrinfo->pixel_info.chroma_fmt_idc >
		    core_props->vidstd_props[str_cfg->vid_std].max_chroma_format) {
			OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[HW]: CODED PIXEL FORMAT IDC %s [for %s]",
				str_cfg->user_str_id,
				comseq_hdrinfo->pixel_info.chroma_fmt_idc <
				ARRAY_SIZE(pix_fmt_idc_names) ?
				(uint8 *)pix_fmt_idc_names[comseq_hdrinfo->pixel_info.chroma_fmt_idc] :
				(uint8 *)"Invalid",
				vid_std_names[str_cfg->vid_std]);
			unsupported->seq_hdr |=
				VDECDD_UNSUPPORTED_SEQUHDR_PIXEL_FORMAT;
		}

		if (comseq_hdrinfo->pixel_info.chroma_fmt_idc ==
		    PIXEL_FORMAT_INVALID) {
			OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[SW]: UNKNOWN CODED PIXEL FORMAT",
				str_cfg->user_str_id);
				unsupported->seq_hdr |=
					VDECDD_UNSUPPORTED_SEQUHDR_PIXEL_FORMAT;
		}
	}

	if (pict_hdrinfo && comseq_hdrinfo) {
		uint32 coded_cmd_width;
		uint32 coded_cmd_height;
		uint32 min_width =
			core_props->vidstd_props[str_cfg->vid_std].min_width;
		uint32 min_height =
			OSA_ALIGN(core_props->vidstd_props[str_cfg->vid_std].min_height,
			      (pict_hdrinfo->field) ?
			      2 * VDEC_MB_DIMENSION : VDEC_MB_DIMENSION, uint32);
		uint32 pict_size_in_mbs;
		uint32 max_height = core_props->vidstd_props[str_cfg->vid_std].max_height;
		uint32 max_width = core_props->vidstd_props[str_cfg->vid_std].max_width;
		uint32 max_mbs = core_props->vidstd_props[str_cfg->vid_std].max_macroblocks;

#ifdef HAS_JPEG
		/* For JPEG, max picture size of four plane images is 16k*16k. */
		if (str_cfg->vid_std == VDEC_STD_JPEG) {
			if (comseq_hdrinfo->pixel_info.num_planes >= 4)
			{
				max_width = (max_width > 16*1024) ? 16*1024 : max_width;
				max_height = (max_height > 16*1024) ? 16*1024 : max_height;
			}
		}
#endif

		coded_cmd_width =
			OSA_ALIGN(pict_hdrinfo->coded_frame_size.width,
			      VDEC_MB_DIMENSION, uint32);
		coded_cmd_height =
			OSA_ALIGN(pict_hdrinfo->coded_frame_size.height,
			      pict_hdrinfo->field ?
			      2 * VDEC_MB_DIMENSION : VDEC_MB_DIMENSION, uint32);

		pict_size_in_mbs = (coded_cmd_width * coded_cmd_height) /
			(VDEC_MB_DIMENSION * VDEC_MB_DIMENSION);

		if ((str_cfg->vid_std == VDEC_STD_H264 &&
		     max_mbs && pict_size_in_mbs > max_mbs) ||
		    coded_cmd_width > max_width ||
		    coded_cmd_height > max_height) {
			OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[HW]: CODED PICTURE SIZE %d x %d [MAX: %d x %d or %d MBs]",
				str_cfg->user_str_id,
				coded_cmd_width, coded_cmd_height,
				max_width, max_height, max_mbs);
			unsupported->pict_hdr |= VDECDD_UNSUPPORTED_PICTHDR_RESOLUTION;
		}

		if (pict_hdrinfo->coded_frame_size.width < min_width ||
		    pict_hdrinfo->coded_frame_size.height < min_height) {
#ifdef USE_STRICT_MIN_PIC_SIZE_CHECK
			OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[HW]: CODED PICTURE SIZE %d x %d [MIN: %d x %d]",
				str_cfg->user_str_id,
				pict_hdrinfo->coded_frame_size.width,
				pict_hdrinfo->coded_frame_size.height,
				min_width, min_height);
			unsupported->pict_hdr |=
				VDECDD_UNSUPPORTED_PICTHDR_RESOLUTION;
#else /* ndef USE_STRICT_MIN_PIC_SIZE_CHECK */
			OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[HW]: CODED PICTURE SIZE %d x %d [MIN: %d x %d]",
				str_cfg->user_str_id,
				pict_hdrinfo->coded_frame_size.width,
				pict_hdrinfo->coded_frame_size.height,
				min_width, min_height);
#endif /* ndef USE_STRICT_MIN_PIC_SIZE_CHECK */
		}

		if (pict_hdrinfo->pict_sgm_data.id !=
		    BSPP_INVALID && pict_hdrinfo->coded_frame_size.width >
				     1280) {
			OSA_PR_WARN("[USERSID=0x%08X] UNSUPPORTED[HW]: SGM & coded frame width > 1280",
				str_cfg->user_str_id);
				unsupported->pict_hdr |=
				VDECDD_UNSUPPORTED_PICTHDR_OVERSIZED_SGM;
		}

		if (pict_hdrinfo->discontinuous_mbs)
			OSA_PR_INFO("Stream has Discontinuous Macroblocks");

		decoder_get_required_core_features(str_cfg, str_op_cfg, features);
	}

	if (unsupported->str_cfg == 0 && unsupported->str_opcfg == 0 &&
	    unsupported->op_bufcfg == 0 && unsupported->pict_hdr == 0)
		ret = IMG_SUCCESS;

	return ret;
}

/*
 * @Function  decoder_picture_decoded
 */
static int32
decoder_picture_decoded(struct dec_str_ctx *dec_str_ctx,
			struct dec_core_ctx *dec_core_ctx,
			struct vdecdd_picture *picture,
			struct dec_decpict *dec_pict,
			struct bspp_pict_hdr_info *pict_hdrinfo,
			struct vdecdd_str_unit *str_unit)
{
	struct dec_fwmsg *first_fld_fwmsg;
	struct dec_fwmsg *second_fld_fwmsg;
	struct dec_pictref_res  *pict_ref_res;
	uint32 transaction_id;
	struct dec_decoded_pict *decoded_pict;
	struct dec_decoded_pict *next_decoded_pict;
	struct vdecdd_ddbuf_mapinfo *pict_buf;
	struct dec_decoded_pict  *prev_decoded_pict;
	struct vdecfw_buffer_control *buf_control;
	struct vdec_comsequ_hdrinfo  *comseq_hdrinfo;
	uint32 res_limit = 0;
	uint32 dec_pict_num = 0;
	uint32 req_pict_num = 0;
	struct dec_decoded_pict *aux_decoded_pict;
	struct dec_decoded_pict *displayed_decoded_pict = NULL;
	int32 ret;
	uint32 pict_id;
	struct vdec_pict_tag_container *fld_tag_container;
#ifdef ERROR_CONCEALMENT
	uint32 first_field_err_level = 0;
	uint32 second_field_err_level = 0;
	uint32 pict_last_mb = 0;
#endif
	struct vxd_dec_ctx *ctx;
	uint32 error_flag = 0;
	VDEC_ASSERT(dec_str_ctx);
	VDEC_ASSERT(str_unit);
	VDEC_ASSERT(dec_pict);

	first_fld_fwmsg = dec_pict->first_fld_fwmsg;
	second_fld_fwmsg = dec_pict->second_fld_fwmsg;
	pict_ref_res = dec_pict->pict_ref_res;
	transaction_id = dec_pict->transaction_id;

	VDEC_ASSERT(picture);
	pict_buf = picture->disp_pict_buf.pict_buf;
	VDEC_ASSERT(pict_buf);
	comseq_hdrinfo = &pict_buf->ddstr_context->comseq_hdr_info;

	/* Create a container for decoded picture. */
	decoded_pict = osa_zalloc(sizeof(*decoded_pict), OSA_GFP_KERNEL);
	VDEC_ASSERT(decoded_pict);
	if (!decoded_pict)
		return IMG_ERROR_OUT_OF_MEMORY;

	decoded_pict->pict = picture;
	decoded_pict->first_fld_fwmsg = first_fld_fwmsg;
	decoded_pict->second_fld_fwmsg = second_fld_fwmsg;
	decoded_pict->pict_ref_res = pict_ref_res;
	decoded_pict->transaction_id = transaction_id;

	/* Populate the decoded picture information structure. */
	picture->dec_pict_info->pict_state = VDEC_PICT_STATE_DECODED;

	memcpy(&picture->dec_pict_info->first_fld_tag_container.pict_hwcrc,
	       &first_fld_fwmsg->pict_hwcrc,
	       sizeof(picture->dec_pict_info->first_fld_tag_container.pict_hwcrc));

	memcpy(&picture->dec_pict_info->second_fld_tag_container.pict_hwcrc,
	       &second_fld_fwmsg->pict_hwcrc,
	       sizeof(picture->dec_pict_info->second_fld_tag_container.pict_hwcrc));

	buf_control = (struct vdecfw_buffer_control *)decoded_pict->pict_ref_res->fw_ctrlbuf.cpu_virt;
	if (buf_control->second_field_of_pair) {
		/* Search the first field and fill the second_fld_tag_container */
		uint32 prev_dec_pict_id =
		get_prev_picture_id(GET_STREAM_PICTURE_ID(decoded_pict->transaction_id));
		prev_decoded_pict =
		decoder_get_decoded_pict_of_stream(prev_dec_pict_id,
						   &dec_str_ctx->str_decd_pict_list);

		if (prev_decoded_pict) {
			memcpy(&picture->dec_pict_info->second_fld_tag_container.pict_hwcrc,
			       &prev_decoded_pict->first_fld_fwmsg->pict_hwcrc,
			       sizeof(picture->dec_pict_info->second_fld_tag_container.pict_hwcrc));
		} else {
			OSA_PR_WARN("[USERSID=0x%08X] [TID 0x%08X] Failed to find decoded picture to attatch second_fld_tag_container",
				dec_str_ctx->config.user_str_id,
				decoded_pict->transaction_id);
		}
		prev_decoded_pict = NULL;
	}

	/* Report any issues in decoding */
	if (decoded_pict->pict->dec_pict_info->err_flags)
		OSA_PR_WARN("[USERSID=0x%08X] [PID=0x%08X] BSPP reported errors [flags: 0x%08X]",
			dec_str_ctx->config.user_str_id,
			decoded_pict->pict->pict_id,
			decoded_pict->pict->dec_pict_info->err_flags);

	if ((decoded_pict->first_fld_fwmsg->pict_attrs.fe_err &
	     FLAG_MASK(VDECFW_MSGFLAG_DECODED_FEERROR_ENTDECERROR)) ||
	     (decoded_pict->second_fld_fwmsg->pict_attrs.fe_err &
	     FLAG_MASK(VDECFW_MSGFLAG_DECODED_FEERROR_ENTDECERROR))) {
		OSA_PR_WARN("[USERSID=0x%08X] [TID 0x%08X] Front-end HW processing terminated prematurely due to an error.",
			dec_str_ctx->config.user_str_id,
			decoded_pict->transaction_id);
		picture->dec_pict_info->err_flags |= VDEC_ERROR_FEHW_DECODE;
	}

	if ((decoded_pict->first_fld_fwmsg->pict_attrs.fe_err &
	     FLAG_MASK(VDECFW_MSGFLAG_DECODED_FEERROR_SRERROR)) ||
	     (decoded_pict->second_fld_fwmsg->pict_attrs.fe_err &
	     FLAG_MASK(VDECFW_MSGFLAG_DECODED_FEERROR_SRERROR))) {
		OSA_PR_WARN("[USERSID=0x%08X] [TID 0x%08X] HW Shift Register access returned an error during FEHW parsing.",
			dec_str_ctx->config.user_str_id,
			decoded_pict->transaction_id);
		picture->dec_pict_info->err_flags |= VDEC_ERROR_SR_ERROR;
	}

	if ((decoded_pict->first_fld_fwmsg->pict_attrs.fe_err &
	     FLAG_MASK(VDECFW_MSGFLAG_DECODED_FEERROR_HWWDT)) ||
	     (decoded_pict->second_fld_fwmsg->pict_attrs.fe_err &
	     FLAG_MASK(VDECFW_MSGFLAG_DECODED_FEERROR_HWWDT))) {
		OSA_PR_WARN("[USERSID=0x%08X] [TID 0x%08X] Front-end HW processing timed-out.",
			dec_str_ctx->config.user_str_id,
			decoded_pict->transaction_id);
		picture->dec_pict_info->err_flags |= VDEC_ERROR_FEHW_TIMEOUT;
	}

	if ((decoded_pict->first_fld_fwmsg->pict_attrs.fe_err &
	     FLAG_MASK(VDECFW_MSGFLAG_DECODED_MISSING_REFERENCES)) ||
	     (decoded_pict->second_fld_fwmsg->pict_attrs.fe_err &
	     FLAG_MASK(VDECFW_MSGFLAG_DECODED_MISSING_REFERENCES))) {
		OSA_PR_WARN("[USERSID=0x%08X] [TID 0x%08X] There are missing references for the current frame. May have corruption",
			dec_str_ctx->config.user_str_id,
			decoded_pict->transaction_id);
		/*
		 * This is not a serious error, indicate host app to drop the
		 * frame as may have corruption.
		 */
		picture->dec_pict_info->err_flags |=
					VDEC_ERROR_MISSING_REFERENCES;
	}

	if ((decoded_pict->first_fld_fwmsg->pict_attrs.fe_err &
	     FLAG_MASK(VDECFW_MSGFLAG_DECODED_MMCO_ERROR)) ||
	     (decoded_pict->second_fld_fwmsg->pict_attrs.fe_err &
	     FLAG_MASK(VDECFW_MSGFLAG_DECODED_MMCO_ERROR))) {
		OSA_PR_WARN("[USERSID=0x%08X] [TID 0x%08X] MMCO error accured when processing the current frame. May have corruption",
			dec_str_ctx->config.user_str_id,
			decoded_pict->transaction_id);

		/*
		 * This is not a serious error, indicate host app to drop
		 * the frame as may have corruption.
		 */
		picture->dec_pict_info->err_flags |= VDEC_ERROR_MMCO;
	}

	if ((decoded_pict->first_fld_fwmsg->pict_attrs.fe_err &
	     FLAG_MASK(VDECFW_MSGFLAG_DECODED_MBS_DROPPED_ERROR)) ||
	     (decoded_pict->second_fld_fwmsg->pict_attrs.fe_err &
	     FLAG_MASK(VDECFW_MSGFLAG_DECODED_MBS_DROPPED_ERROR))) {
		OSA_PR_WARN("[USERSID=0x%08X] [TID 0x%08X] Some macroblocks were dropped when processing the current frame. May have corruption",
			dec_str_ctx->config.user_str_id,
			decoded_pict->transaction_id);

			/*
			 * This is not a serious error, indicate host app to
			 * drop the frame as may have corruption.
			 */
		picture->dec_pict_info->err_flags |= VDEC_ERROR_MBS_DROPPED;
	}

	if (decoded_pict->first_fld_fwmsg->pict_attrs.no_be_wdt > 0) {
		OSA_PR_WARN("[USERSID=0x%08X] [TID 0x%08X] Back-end HW processing timed-out. Aborted slices %d",
			dec_str_ctx->config.user_str_id,
			decoded_pict->transaction_id,
			decoded_pict->first_fld_fwmsg->pict_attrs.no_be_wdt);
		picture->dec_pict_info->err_flags |= VDEC_ERROR_BEHW_TIMEOUT;
	}

	if (decoded_pict->second_fld_fwmsg->pict_attrs.no_be_wdt > 0) {
		OSA_PR_WARN("[USERSID=0x%08X] [TID 0x%08X] Back-end HW processing timed-out. Aborted slices %d",
			dec_str_ctx->config.user_str_id,
			decoded_pict->transaction_id,
			decoded_pict->second_fld_fwmsg->pict_attrs.no_be_wdt);
		picture->dec_pict_info->err_flags |= VDEC_ERROR_BEHW_TIMEOUT;
	}

#ifdef ERROR_CONCEALMENT
	/* Estimate error level in percentage */
	if (decoder_get_pict_processing_info(dec_core_ctx, dec_str_ctx, pict_hdrinfo,
					     decoded_pict, dec_pict, &pict_last_mb) == osa_true) {
		if (pict_last_mb) {
			first_field_err_level = 100 - ((100 * (pict_last_mb -
							       decoded_pict->first_fld_fwmsg->pict_attrs.mbs_dropped +
							       decoded_pict->first_fld_fwmsg->pict_attrs.mbs_recovered)) /
							pict_last_mb);

			second_field_err_level = 100 - ((100 * (pict_last_mb -
								decoded_pict->second_fld_fwmsg->pict_attrs.mbs_dropped +
								decoded_pict->second_fld_fwmsg->pict_attrs.mbs_recovered)) /
							pict_last_mb);
		}

		/* does not work properly with discontinuous mbs */
		if (!pict_hdrinfo->discontinuous_mbs)
			picture->dec_pict_info->err_level = first_field_err_level > second_field_err_level ?
								first_field_err_level : second_field_err_level;

		VDEC_ASSERT(picture->dec_pict_info->err_level <= 100);
		if (picture->dec_pict_info->err_level)
			OSA_PR_WARN("[USERSID=0x%08X] [TID 0x%08X] Picture error level: %d(%%)",
				dec_str_ctx->config.user_str_id, decoded_pict->transaction_id,
				picture->dec_pict_info->err_level);
	}
#endif

	if (decoded_pict->first_fld_fwmsg->pict_attrs.pict_attrs.dwrfired ||
	    decoded_pict->second_fld_fwmsg->pict_attrs.pict_attrs.dwrfired) {
		OSA_PR_WARN("[USERSID=0x%08X] VXD Device Reset (Lockup).",
			dec_str_ctx->config.user_str_id);
		picture->dec_pict_info->err_flags |=
					VDEC_ERROR_SERVICE_TIMER_EXPIRY;
	}

	if (decoded_pict->first_fld_fwmsg->pict_attrs.pict_attrs.mmufault ||
	    decoded_pict->second_fld_fwmsg->pict_attrs.pict_attrs.mmufault) {
		OSA_PR_WARN("[USERSID=0x%08X] VXD Device Reset (MMU fault).",
			dec_str_ctx->config.user_str_id);
		picture->dec_pict_info->err_flags |= VDEC_ERROR_MMU_FAULT;
	}

	if (decoded_pict->first_fld_fwmsg->pict_attrs.pict_attrs.deverror ||
	    decoded_pict->second_fld_fwmsg->pict_attrs.pict_attrs.deverror) {
		OSA_PR_WARN("[USERSID=0x%08X] VXD Device Error (e.g. firmware load failed).",
			dec_str_ctx->config.user_str_id);
		picture->dec_pict_info->err_flags |= VDEC_ERROR_DEVICE;
	}

	/*
	 * Assigned error flag from the decoder error flag for error recovery.
	 */
	error_flag = picture->dec_pict_info->err_flags;
	/*
	 * Loop over references, for each one find the related picture
	 * on the decPictList, and propagate errors if needed
	 */
	ret =
	decoder_check_ref_errors(dec_str_ctx,
				 (struct vdecfw_buffer_control *)decoded_pict->pict_ref_res->fw_ctrlbuf.cpu_virt,
				 picture);
	VDEC_ASSERT(ret == IMG_SUCCESS);

	if (dec_str_ctx->config.vid_std == VDEC_STD_H264) {
		/* Attach the supplementary data to the decoded picture. */
		picture->dec_pict_sup_data.raw_vui_data =
				pict_hdrinfo->h264_pict_hdr_info.raw_vui_data;
		pict_hdrinfo->h264_pict_hdr_info.raw_vui_data = NULL;

		picture->dec_pict_sup_data.raw_sei_list_first_fld =
		pict_hdrinfo->h264_pict_hdr_info.raw_sei_data_list_first_field;
		pict_hdrinfo->h264_pict_hdr_info.raw_sei_data_list_first_field = NULL;

		picture->dec_pict_sup_data.raw_sei_list_second_fld =
			pict_hdrinfo->h264_pict_hdr_info.raw_sei_data_list_second_field;
		pict_hdrinfo->h264_pict_hdr_info.raw_sei_data_list_second_field = NULL;

		picture->dec_pict_sup_data.h264_pict_supl_data.nal_ref_idc =
				pict_hdrinfo->h264_pict_hdr_info.nal_ref_idc;

		picture->dec_pict_sup_data.h264_pict_supl_data.frame_num =
				pict_hdrinfo->h264_pict_hdr_info.frame_num;
	}

#ifdef HAS_HEVC
	if (dec_str_ctx->config.vid_std == VDEC_STD_HEVC) {
		/* Attach the supplementary data to the decoded picture. */
		picture->dec_pict_sup_data.raw_vui_data = pict_hdrinfo->hevc_pict_hdr_info.raw_vui_data;

		pict_hdrinfo->hevc_pict_hdr_info.raw_vui_data = NULL;

		picture->dec_pict_sup_data.raw_sei_list_first_fld =
				pict_hdrinfo->hevc_pict_hdr_info.raw_sei_datalist_firstfield;

		pict_hdrinfo->hevc_pict_hdr_info.raw_sei_datalist_firstfield = NULL;

		picture->dec_pict_sup_data.raw_sei_list_second_fld =
				pict_hdrinfo->hevc_pict_hdr_info.raw_sei_datalist_secondfield;

		pict_hdrinfo->hevc_pict_hdr_info.raw_sei_datalist_secondfield = NULL;

		picture->dec_pict_sup_data.hevc_pict_supl_data.pic_order_cnt = buf_control->hevc_data.pic_order_count;
	}
#endif

	if (!((buf_control->dec_pict_type == IMG_BUFFERTYPE_PAIR &&
	       VDECFW_PICMGMT_FIELD_CODED_PICTURE_EXECUTED(buf_control->picmgmt_flags)) ||
	       FLAG_IS_SET(buf_control->picmgmt_flags,
			   VDECFW_PICMGMTFLAG_PICTURE_EXECUTED))) {
		OSA_PR_WARN("[USERSID=0x%08X] [TID 0x%08X] Picture management was not executed for this picture; forcing display.",
			dec_str_ctx->config.user_str_id,
			decoded_pict->transaction_id);
		decoded_pict->force_display = osa_true;
	}

	dec_str_ctx->dec_str_st.total_pict_finished++;

	/*
	 * Use NextPictIdExpected to do this check. ui32NextPictId could be
	 * different from what expected at this point because we failed to
	 * process a picture the last time run this function (this is still
	 * an error (unless doing multi-core) but not the error reported here.
	 */
	if (picture->pict_id != dec_str_ctx->next_pict_id_expected) {
		OSA_PR_WARN("[USERSID=0x%08X] ERROR: MISSING DECODED PICTURE (%d)",
			dec_str_ctx->config.user_str_id,
			dec_str_ctx->next_dec_pict_id);
	}

	dec_str_ctx->next_dec_pict_id =
		get_next_picture_id(GET_STREAM_PICTURE_ID(decoded_pict->transaction_id));
	dec_str_ctx->next_pict_id_expected = dec_str_ctx->next_dec_pict_id;

	/* Add the picture itself to the decoded list */
	next_decoded_pict = dq_first(&dec_str_ctx->str_decd_pict_list);
	while (next_decoded_pict &&
	       !HAS_X_REACHED_Y(GET_STREAM_PICTURE_ID(next_decoded_pict->transaction_id),
				picture->pict_id,
				1 << FWIF_NUMBITS_STREAM_PICTURE_ID, uint32)) {
		if (next_decoded_pict !=
		    dq_last(&dec_str_ctx->str_decd_pict_list))
			next_decoded_pict = dq_next(next_decoded_pict);
		else
			next_decoded_pict = NULL;
	}

	if (next_decoded_pict)
		dq_addbefore(next_decoded_pict, decoded_pict);
	else
		dq_addtail(&dec_str_ctx->str_decd_pict_list, decoded_pict);

	dec_str_ctx->dec_str_st.num_pict_decoded++;

	OSA_PR_DEBUG("%s : number of picture decoded = %d\n"
		     ,__func__, dec_str_ctx->dec_str_st.num_pict_decoded);
	/* Process the decoded pictures in the encoded order */
	decoded_pict = dq_first(&dec_str_ctx->str_decd_pict_list);
	VDEC_ASSERT(decoded_pict);
	if (!decoded_pict)
		return IMG_ERROR_UNEXPECTED_STATE;

	ret = dec_str_ctx->str_processed_cb((void *)dec_str_ctx->usr_int_data,
					    VXD_CB_PICT_DECODED, (void *)picture);

	VDEC_ASSERT(ret == IMG_SUCCESS);
	if (ret != IMG_SUCCESS)
		return ret;
	/*
	 * Loop on the unprocessed pictures until we failed to process one
	 * or we have processed them all
	 */
	for (next_decoded_pict = decoder_next_picture(decoded_pict,
						      dec_str_ctx->next_dec_pict_id,
						      &dec_str_ctx->str_decd_pict_list);
	    next_decoded_pict;
	    next_decoded_pict = decoder_next_picture(decoded_pict,
						     dec_str_ctx->next_dec_pict_id,
						     &dec_str_ctx->str_decd_pict_list)) {
		uint32 i = 0;
		struct dec_decoded_pict *display_pict = NULL;
		struct dec_decoded_pict *release_pict = NULL;
		uint8 last_to_display_for_seq = osa_false;

		/*
		 * next_decoded_pict is used to temporarily store decoded_pict
		 * so that we can clear the bProcessFailed flag before
		 * returning
		 */
		decoded_pict = next_decoded_pict;
		if (!decoded_pict->force_display) {
			struct vdecfw_buffer_control *buf_ctrl = NULL;

			buf_ctrl =
				(struct vdecfw_buffer_control *)decoded_pict->pict_ref_res->fw_ctrlbuf.cpu_virt;

			if (buf_ctrl->real_data.width &&
			    buf_ctrl->real_data.height) {
				/*
				 * Firmware sets image size as it is in
				 * bitstream.
				 */
				picture->dec_pict_info->disp_info.disp_region.width =
									buf_ctrl->real_data.width;
				picture->dec_pict_info->disp_info.disp_region.height =
									buf_ctrl->real_data.height;
				picture->dec_pict_info->disp_info.disp_region.top_offset = 0;
				picture->dec_pict_info->disp_info.disp_region.left_offset = 0;

				picture->dec_pict_info->rend_info.rend_pict_size.width =
							picture->dec_pict_info->disp_info.disp_region.width;
				picture->dec_pict_info->rend_info.rend_pict_size.height =
							picture->dec_pict_info->disp_info.disp_region.height;

				/*
				 * Update encoded size with values coded in
				 * bitstream,so golden image can be loaded
				 * correctly
				 */
				picture->dec_pict_info->disp_info.enc_disp_region.width =
										buf_ctrl->real_data.width;
				picture->dec_pict_info->disp_info.enc_disp_region.height =
										buf_ctrl->real_data.height;
			}

			decoded_pict->pict->dec_pict_info->timestamp = buf_ctrl->real_data.timestamp;
			decoded_pict->pict->dec_pict_info->disp_info.top_fld_first =
										buf_ctrl->top_field_first;
			decoded_pict->pict->dec_pict_info->disp_info.top_fld_first =
										buf_ctrl->top_field_first;

			decoded_pict->pict->dec_pict_info->id_for_hwcrc_chk =
						GET_STREAM_PICTURE_ID(decoded_pict->transaction_id) - 1;
			decoded_pict->pict->dec_pict_info->id_for_hwcrc_chk +=
						dec_str_ctx->dec_str_st.flds_as_frm_decodes;

			if (buf_ctrl->dec_pict_type == IMG_BUFFERTYPE_PAIR &&
			    !buf_ctrl->second_field_of_pair)
				dec_str_ctx->dec_str_st.flds_as_frm_decodes++;

			if (buf_ctrl->second_field_of_pair) {
				/*
				 * Second field of pair is always complementary
				 * type to the eFirstPictTagType of the
				 * previous picture
				 */
				uint32 prev_dec_pict_id =
				get_prev_picture_id(GET_STREAM_PICTURE_ID(decoded_pict->transaction_id));

				prev_decoded_pict =
				decoder_get_decoded_pict_of_stream(prev_dec_pict_id,
								   &dec_str_ctx->str_decd_pict_list);
				if (prev_decoded_pict) {
					fld_tag_container =
						&prev_decoded_pict->pict->dec_pict_info->second_fld_tag_container;
					fld_tag_container->pict_tag_param =
					decoded_pict->pict->dec_pict_info->first_fld_tag_container.pict_tag_param;

					/*
					 * Copy the first field info in the
					 * proper place
					 */
					memcpy(&fld_tag_container->pict_hwcrc,
					       &first_fld_fwmsg->pict_hwcrc,
					       sizeof(fld_tag_container->pict_hwcrc));

					/*
					 * Attach the raw SEI data list for a
					 * second field to a picture.
					 */
					prev_decoded_pict->pict->dec_pict_sup_data.raw_sei_list_second_fld =
						decoded_pict->pict->dec_pict_sup_data.raw_sei_list_first_fld;

					prev_decoded_pict->pict->dec_pict_info->disp_info.top_fld_first =
						buf_ctrl->top_field_first;

					/* Mark this picture as merged fields. */
					prev_decoded_pict->pict->dec_pict_sup_data.merged_flds = osa_true;
					/* Mark the picture that was merged to the previous one. */
					decoded_pict->merged = osa_true;
				} else {
					OSA_PR_WARN("[USERSID=0x%08X] [TID 0x%08X] Failed to find decoded picture to attatch tag",
						dec_str_ctx->config.user_str_id,
						decoded_pict->transaction_id);
				}
			} else {
				/*
				 * Not Second-field-of-pair picture tag
				 * correlates its Tag to the its type by
				 * setting the eFirstPictTagType in the
				 * following way
				 */
				decoded_pict->pict->dec_pict_info->first_fld_tag_container.pict_type =
										buf_ctrl->dec_pict_type;
				memcpy(&picture->dec_pict_info->first_fld_tag_container.pict_hwcrc,
				       &first_fld_fwmsg->pict_hwcrc,
				       sizeof(picture->dec_pict_info->first_fld_tag_container.pict_hwcrc));
			}

			/*
			 * Update the id of the next picture to process. It has
			 * to be update always (even if we fail to process)
			 * This has to be a global flag because it will be
			 * passed in both decoder_NextPicture (and then to
			 * DECODER_NextDecPictContiguous inside it)
			 * and to the corner case check below
			 */
			dec_str_ctx->next_dec_pict_id =
				get_next_picture_id(GET_STREAM_PICTURE_ID(decoded_pict->transaction_id));

			/*
			 * Display all the picture in the list that have been
			 * decoded and signalled by the fw to be displayed
			 */
			for (i = decoded_pict->disp_idx;
			     i < buf_ctrl->display_list_length &&
			     !decoded_pict->process_failed;
			     i++, decoded_pict->disp_idx++) {
				/*
				 * Display picture if it has been decoded
				 * (i.e. in decoded list).
				 */
				display_pict = decoder_get_decoded_pict(buf_ctrl->display_list[i],
									&dec_str_ctx->str_decd_pict_list);
				if (display_pict) {
					if (FLAG_IS_SET(buf_ctrl->display_flags[i],
							VDECFW_BUFFLAG_DISPLAY_FIELD_CODED)) {
						if (!FLAG_IS_SET(buf_ctrl->display_flags[i],
								 VDECFW_BUFFLAG_DISPLAY_SINGLE_FIELD)) {
							display_pict->pict->dec_pict_info->buf_type =
											IMG_BUFFERTYPE_PAIR;
							if (FLAG_IS_SET(buf_ctrl->display_flags[i],
									VDECFW_BUFFLAG_DISPLAY_INTERLACED_FIELDS))
								display_pict->pict->dec_pict_info->interlaced_flds =
														osa_true;
						} else {
							display_pict->pict->dec_pict_info->buf_type =
							FLAG_IS_SET(buf_ctrl->display_flags[i],
								    VDECFW_BUFFLAG_DISPLAY_BOTTOM_FIELD) ?
								    IMG_BUFFERTYPE_FIELD_BOTTOM :
								    IMG_BUFFERTYPE_FIELD_TOP;
						}
					} else {
						display_pict->pict->dec_pict_info->buf_type = IMG_BUFFERTYPE_FRAME;
					}

					display_pict->pict->dec_pict_info->view_id =
							buf_ctrl->display_view_ids[i];

					/*
					 * When no reference pictures are left to
					 * display and this is the last display
					 * picture in response to the last decoded
					 * picture, signal.
					 */
					if (decoded_pict->pict->last_pict_in_seq &&
					    i == (buf_ctrl->display_list_length - 1))
						last_to_display_for_seq = osa_true;

					if (!display_pict->displayed) {
						OSA_PR_INFO("[USERSID=0x%08X] [TID=0x%08X] DISPLAY",
							dec_str_ctx->config.user_str_id,
							buf_ctrl->display_list[i]);
						display_pict->displayed = osa_true;
						pict_id = GET_STREAM_PICTURE_ID(buf_ctrl->display_list[i]);

						ret = decoder_picture_display(dec_str_ctx, pict_id,
									      last_to_display_for_seq);
						VDEC_ASSERT(ret == IMG_SUCCESS);
						if (ret != IMG_SUCCESS)
							return ret;
					}
				} else {
					/*
					 * In single core scenario should
					 * not come here.
					 */
					OSA_PR_WARN("[USERSID=0x%08X] Failed to find decoded picture [TID = 0x%08X] to send for display",
						dec_str_ctx->config.user_str_id,
						buf_ctrl->display_list[i]);
				}
			}

			/* Release all unused pictures (firmware request) */
			for (i = decoded_pict->rel_idx;
			     i < buf_ctrl->release_list_length &&
				!decoded_pict->process_failed;
			     i++,  decoded_pict->rel_idx++) {
				release_pict = decoder_get_decoded_pict(buf_ctrl->release_list[i],
									&dec_str_ctx->str_decd_pict_list);
				if (release_pict) {
					OSA_PR_INFO("[USERSID=0x%08X] RELEASE( ): PIC_ID[%d]",
						dec_str_ctx->config.user_str_id,
						release_pict->pict->pict_id);
					/*
					 * Signal releasing this picture to upper
					 * layers.
					 */
					decoder_picture_release(dec_str_ctx,
								GET_STREAM_PICTURE_ID(buf_ctrl->release_list[i]),
								release_pict->displayed,
								release_pict->merged);
					if (release_pict->processed) {
						/*
						 * If the decoded picture has been
						 * processed, destroy now.
						 */
						ret = decoder_decoded_picture_destroy(dec_str_ctx,
										      release_pict,
										      osa_false);
						VDEC_ASSERT(ret == IMG_SUCCESS);
						if (ret != IMG_SUCCESS)
							return ret;
					} else {
						/*
						 * If the decoded picture is not
						 * processed just destroy the
						 * containing picture.
						 */
						pict_id = GET_STREAM_PICTURE_ID(buf_ctrl->release_list[i]);
						ret = decoder_picture_destroy(dec_str_ctx,
									      pict_id, osa_false);
						VDEC_ASSERT(ret == IMG_SUCCESS);
						if (ret != IMG_SUCCESS)
							return ret;
						release_pict->pict = NULL;
					}
				} else {
					/*
					 * In single core scenario should not
					 * come here.
					 */
					OSA_PR_INFO("[USERSID=0x%08X] Failed to find decoded picture [TID = 0x%08X] to release",
					       dec_str_ctx->config.user_str_id, buf_ctrl->release_list[i]);
				}
			}
		} else {
			/* Always display the picture if we have no hardware */
			if (!decoded_pict->displayed) {
				OSA_PR_INFO("[USERSID=0x%08X] [TID=0x%08X] DISPLAY",
					dec_str_ctx->config.user_str_id,
					decoded_pict->transaction_id);
					decoded_pict->displayed = osa_true;
				ret = decoder_picture_display(dec_str_ctx,
							      decoded_pict->pict->pict_id,
							      decoded_pict->pict->last_pict_in_seq);
				VDEC_ASSERT(ret == IMG_SUCCESS);
				if (ret != IMG_SUCCESS)
					return ret;
			}

			/* Always release the picture if we have no hardware */
			ret = decoder_picture_destroy(dec_str_ctx,
						      decoded_pict->pict->pict_id,
						      osa_false);
			VDEC_ASSERT(ret == IMG_SUCCESS);
			if (ret != IMG_SUCCESS)
				return ret;

			decoded_pict->pict = NULL;
		}

		/* If we have processed the current picture */
		if (!decoded_pict->process_failed) {
			decoded_pict->processed = osa_true;

			/*
			 * If the current picture has been released then
			 * remove the container from the decoded list
			 */
			if (!decoded_pict->pict) {
				/*
				 * Only destroy the decoded picture once it is processed
				 * and the fw has instructed to release the picture.
				 */
				ret = decoder_decoded_picture_destroy(dec_str_ctx,
								      decoded_pict, osa_false);
				VDEC_ASSERT(ret == IMG_SUCCESS);
				if (ret != IMG_SUCCESS)
					return ret;

				decoded_pict = NULL;
			} /* end if (decoded_pict->pict == NULL) */
		} /* end if (!decoded_pict->process_failed) */
	} /* end for */

	/*
	 * Always clear the process_failed flag to ensure that this picture
	 * will be processed on the next function call
	 */
	if (decoded_pict)
		decoded_pict->process_failed = osa_false;

	/*
	 * Go through the list of decoded pictures to check if there are any
	 * pictures left for displaying and that are still not displayed due
	 * to picture management errors.
	 * Get the minimum required number of picture buffers.
	 */
	vdecddutils_ref_pict_get_maxnum(&dec_str_ctx->config,
					comseq_hdrinfo, &req_pict_num);
	req_pict_num += comseq_hdrinfo->interlaced_frames ? 2 : 1;

	ret = dec_str_ctx->core_query_cb(dec_str_ctx->usr_int_data,
					 DECODER_CORE_GET_RES_LIMIT,
					 &res_limit);

	/* Start the procedure only if there is enough resources available. */
	if (res_limit >= req_pict_num) {
		/* Allow for one picture buffer for display. */
		res_limit--;

		/*
		 * Count the number of decoded pictures that were not
		 * displayed yet.
		 */
		aux_decoded_pict = dq_first(&dec_str_ctx->str_decd_pict_list);
		while (aux_decoded_pict) {
			if (aux_decoded_pict->pict) {
				dec_pict_num++;
				if (!displayed_decoded_pict)
					displayed_decoded_pict =
							aux_decoded_pict;
			}
			if (aux_decoded_pict !=
			    dq_last(&dec_str_ctx->str_decd_pict_list))
				aux_decoded_pict = dq_next(aux_decoded_pict);
			else
				aux_decoded_pict = NULL;
		}
	}

	/* If there is at least one not displayed picture... */
	if (displayed_decoded_pict) {
		/*
		 * While the number of not displayed decoded pictures exceeds
		 * the number of maximum allowed number of pictures being held
		 * by VDEC...
		 */
		while (dec_pict_num > res_limit) {
			OSA_PR_WARN("[USERSID=0x%08X] Number of outstanding decoded pictures exceeded number of available pictures buffers.",
				dec_str_ctx->config.user_str_id);

			if(!displayed_decoded_pict) {
				VDEC_ASSERT(0);
				return -OSA_EINVAL;
			}
			/* Find the picture with the least picture id. */
			aux_decoded_pict = dq_next(displayed_decoded_pict);
			while (aux_decoded_pict) {
				if (aux_decoded_pict !=
				    dq_last(&dec_str_ctx->str_decd_pict_list)) {
					if (aux_decoded_pict->pict &&
					    aux_decoded_pict->pict->pict_id <
					    displayed_decoded_pict->pict->pict_id)
						displayed_decoded_pict =
								aux_decoded_pict;

					aux_decoded_pict = dq_next(aux_decoded_pict);
				} else {
					if (aux_decoded_pict->pict &&
					    aux_decoded_pict->pict->pict_id <
					    displayed_decoded_pict->pict->pict_id)
						displayed_decoded_pict = aux_decoded_pict;

					aux_decoded_pict = NULL;
				}
			}

			/* Display and release the picture with the least picture id. */
			if (!displayed_decoded_pict->displayed) {
				OSA_PR_WARN("[USERSID=0x%08X] [TID=0x%08X] DISPLAY FORCED",
					dec_str_ctx->config.user_str_id,
					displayed_decoded_pict->transaction_id);
				displayed_decoded_pict->displayed = osa_true;
				ret = decoder_picture_display(dec_str_ctx,
							      displayed_decoded_pict->pict->pict_id,
							      displayed_decoded_pict->pict->last_pict_in_seq);
				VDEC_ASSERT(ret == IMG_SUCCESS);
				if (ret != IMG_SUCCESS)
					return ret;
			}

			ret = decoder_picture_destroy(dec_str_ctx,
						      displayed_decoded_pict->pict->pict_id,
						      osa_false);
			VDEC_ASSERT(ret == IMG_SUCCESS);
			if (ret != IMG_SUCCESS)
				return ret;

			displayed_decoded_pict->pict = NULL;
			displayed_decoded_pict->processed = osa_true;

			ret = decoder_decoded_picture_destroy(dec_str_ctx,
							      displayed_decoded_pict,
							      osa_false);
			VDEC_ASSERT(ret == IMG_SUCCESS);
			if (ret != IMG_SUCCESS)
				return ret;

			displayed_decoded_pict = NULL;

			/*
			 * Decrease the number of not displayed decoded
			 * pictures.
			 */
			dec_pict_num--;
		}
	}

#ifdef ERROR_RECOVERY_SIMULATION
	/*
	 * This part of the code should execute only when, DEBUG_FW_ERR_RECOVERY
	 * flag is enabled. This basically reads the error flag attribute from
	 * user space to create fake errors for testing the firmware error
	 * recovery.
	 */
	if (fw_error_value != VDEC_ERROR_MAX) {
		error_flag = error_flag | (1 << fw_error_value);
		/* Now lets make it VDEC_ERROR_MAX */
		fw_error_value = VDEC_ERROR_MAX;

	}
#endif

	/*
	 * Whenever the error flag is set, we need to handle the error case.
	 * Need to forward this error to stream processed callback.
	 */
	if(error_flag) {
		OSA_PR_ERR("%s : %d err_flags: 0x%x\n",__func__, __LINE__, error_flag);
		ret = dec_str_ctx->str_processed_cb((void *)dec_str_ctx->usr_int_data,
				VXD_CB_ERROR_FATAL, &error_flag);
	}
	/*
	 * check for eos on bitstream and propagate the same to picture
	 * buffer
	 */
	ctx = dec_str_ctx->vxd_dec_ctx;
	ctx->num_decoding--;
	if (ctx->eos) {
		OSA_PR_INFO("EOS reached\n");

		ret = dec_str_ctx->str_processed_cb((void *)dec_str_ctx->usr_int_data,
						    VXD_CB_STR_END, NULL);
		VDEC_ASSERT(ret == IMG_SUCCESS);
	}

	return ret;
}

/*
 * @Function  decoder_service_firmware_response
 */
int32 decoder_service_firmware_response(void *dec_str_ctx_arg, uint32 *msg,
				      uint32 msg_size, uint32 msg_flags)
{
	int32 ret = IMG_SUCCESS;
	struct dec_decpict *dec_pict = NULL;
	uint8 head_of_queue = osa_true;
	struct dec_str_ctx *dec_str_ctx;
	struct dec_str_unit *dec_str_unit;
	uint8 pict_start = osa_false;
	enum vdecdd_str_unit_type str_unit_type;
	struct vdecdd_picture *picture;
	struct decoder_pict_fragment *pict_fragment;
	struct dec_str_ctx *dec_strctx;
	struct dec_core_ctx *dec_core_ctx;

	/* validate input arguments */
	if((!dec_str_ctx_arg) || (!msg)) {
		VDEC_ASSERT(0);
		return IMG_ERROR_INVALID_PARAMETERS;
	}

	dec_strctx = decoder_stream_get_context(dec_str_ctx_arg);

	dec_core_ctx = decoder_str_ctx_to_core_ctx(dec_strctx);

	if(!dec_core_ctx) {
		OSA_PR_ERR("%s: dec_core_ctx is NULL\n", __func__);
		VDEC_ASSERT(0);
		return IMG_ERROR_INVALID_PARAMETERS;
	}

	OSA_PR_DEBUG("%s : process firmware response\n",__func__);
	ret = hwctrl_process_msg(dec_core_ctx->hw_ctx, msg_flags, msg,
				 &dec_pict);
	VDEC_ASSERT(ret == IMG_SUCCESS);
	if (ret != IMG_SUCCESS)
		return ret;

	if (!dec_pict || (dec_pict->state != DECODER_PICTURE_STATE_DECODED &&
			  dec_pict->state != DECODER_PICTURE_STATE_TO_DISCARD))
		return IMG_ERROR_UNEXPECTED_STATE;

	/*
	 * Try and locate the stream context in the list of active
	 * streams.
	 */
	VDEC_ASSERT(dec_core_ctx->dec_ctx);
	dec_str_ctx = lst_first(&dec_core_ctx->dec_ctx->str_list);
	if(!dec_str_ctx) {
		VDEC_ASSERT(0);
		return -OSA_EINVAL;
	}

	while (dec_str_ctx) {
		if (dec_str_ctx == dec_pict->dec_str_ctx)
			break;

		dec_str_ctx = lst_next(dec_str_ctx);
	}

	/*
	 * If the stream is not in the list of active streams then
	 * it must have been destroyed.
	 * This interrupt should be ignored.
	 */
	if (dec_str_ctx != dec_pict->dec_str_ctx)
		return IMG_SUCCESS;

	/*
	 * Retrieve the picture from the head of the core decode queue
	 * primarily to obtain the correct stream context.
	 */
	hwctrl_removefrom_piclist(dec_core_ctx->hw_ctx, dec_pict);

	if(!dec_str_ctx) {
		VDEC_ASSERT(0);
		return -OSA_EINVAL;
	}
	dec_str_ctx->avail_slots++;
	VDEC_ASSERT(dec_str_ctx->avail_slots > 0);

	/*
	 * Store the stream context of the picture that has been
	 * decoded.
	 */
	dec_str_ctx = dec_pict->dec_str_ctx;
	VDEC_ASSERT(dec_str_ctx);

	if (!dec_str_ctx)
		return IMG_ERROR_UNEXPECTED_STATE;

	/*
	 * Picture has been discarded before EOP unit,
	 * recover the decoder to valid state
	 */
	if (!dec_pict->eop_found) {
		VDEC_ASSERT(dec_pict == dec_str_ctx->cur_pict);

		dec_core_ctx->busy = osa_false;
		dec_str_ctx->cur_pict = NULL;
	}

	/*
	 * Peek the first stream unit and validate against core
	 * queue to ensure that this really is the next picture
	 * for the stream.
	 */
	dec_str_unit = lst_first(&dec_str_ctx->pend_strunit_list);
	if (dec_str_unit) {
		if (dec_str_unit->dec_pict != dec_pict) {
			head_of_queue = osa_false;

			/*
			 * For pictures to be decoded
			 * out-of-order there must be
			 * more than one decoder core.
			 */
			VDEC_ASSERT(dec_str_ctx->decctx->num_pipes > 1);
			while (dec_str_unit) {
				dec_str_unit = lst_next(dec_str_unit);
				if (dec_str_unit && dec_str_unit->dec_pict == dec_pict)
					break;
			}
		}
		VDEC_ASSERT(dec_str_unit);
		if (!dec_str_unit)
			return IMG_ERROR_FATAL;

		VDEC_ASSERT(dec_str_unit->dec_pict == dec_pict);
		VDEC_ASSERT(dec_str_unit->str_unit->str_unit_type ==
			    VDECDD_STRUNIT_PICTURE_START);
	}

	/*
	 * Process all units from the pending stream list until
	 * the next picture start.
	 */
	while (dec_str_unit && !pict_start) {
		/*
		 * Actually remove the unit now from the
		 * pending stream list.
		 */
		lst_remove(&dec_str_ctx->pend_strunit_list, dec_str_unit);
		if (!dec_str_unit->str_unit || !dec_pict)
			break;

		str_unit_type = dec_str_unit->str_unit->str_unit_type;

		if (str_unit_type != VDECDD_STRUNIT_PICTURE_START)
			break;

		dec_str_ctx = dec_pict->dec_str_ctx;

		dec_str_ctx->dec_str_st.num_pict_decoding--;
		dec_str_ctx->dec_str_st.total_pict_decoded++;

		ret = idgen_gethandle(dec_str_ctx->pict_idgen,
				      GET_STREAM_PICTURE_ID(dec_str_unit->dec_pict->transaction_id),
							    (void **)&picture);
		VDEC_ASSERT(ret == IMG_SUCCESS);
		if (ret != IMG_SUCCESS || !picture) {
			OSA_PR_ERR("[USERSID=0x%08X] Failed to find picture from ID",
			       dec_str_ctx->config.user_str_id);
			return IMG_ERROR_INVALID_ID;
		}

		VDEC_ASSERT(picture == dec_str_unit->str_unit->dd_pict_data);

		/* Hold a reference to the last context on the BE */
		if (dec_str_ctx->last_be_pict_dec_res &&
		    HAS_X_PASSED_Y(picture->pict_id,
				   GET_STREAM_PICTURE_ID(dec_str_ctx->last_be_pict_dec_res->transaction_id),
				   1 << FWIF_NUMBITS_STREAM_PICTURE_ID, uint32)) {
			/* Return previous last FW context. */
			resource_item_return(&dec_str_ctx->last_be_pict_dec_res->ref_cnt);

			if (resource_item_isavailable(&dec_str_ctx->last_be_pict_dec_res->ref_cnt)) {
				resource_list_remove(&dec_str_ctx->dec_res_lst,
						     dec_str_ctx->last_be_pict_dec_res);
				resource_list_add(&dec_str_ctx->dec_res_lst,
						  dec_str_ctx->last_be_pict_dec_res,
						  0,
						  &dec_str_ctx->last_be_pict_dec_res->ref_cnt);
			}
		}
		if (dec_str_ctx->last_be_pict_dec_res ==
		    NULL || (dec_str_ctx->last_be_pict_dec_res &&
			     HAS_X_PASSED_Y(picture->pict_id,
					    GET_STREAM_PICTURE_ID(dec_str_ctx->last_be_pict_dec_res->transaction_id),
					    1 << FWIF_NUMBITS_STREAM_PICTURE_ID, uint32))) {
			/* Hold onto last FW context. */
			dec_str_ctx->last_be_pict_dec_res =
						dec_pict->cur_pict_dec_res;
			resource_item_use(&dec_str_ctx->last_be_pict_dec_res->ref_cnt);
		}
		resource_item_return(&dec_pict->cur_pict_dec_res->ref_cnt);

		if (resource_item_isavailable(&dec_pict->cur_pict_dec_res->ref_cnt)) {
			resource_list_remove(&dec_str_ctx->dec_res_lst,
					     dec_pict->cur_pict_dec_res);
			resource_list_add(&dec_str_ctx->dec_res_lst,
					  dec_pict->cur_pict_dec_res,
					  0,
					  &dec_pict->cur_pict_dec_res->ref_cnt);
		}

		OSA_PR_INFO("[USERSID=0x%08X] [TID=0x%08X] DECODED",
		       dec_str_ctx->config.user_str_id,
		       dec_pict->transaction_id);

		ret = decoder_picture_decoded(dec_str_ctx, dec_core_ctx,
					      picture, dec_pict,
					      dec_pict->pict_hdr_info,
					      dec_str_unit->str_unit);

		VDEC_ASSERT(ret == IMG_SUCCESS);
		if (ret != IMG_SUCCESS)
			return ret;

		dec_res_picture_detach(&dec_str_ctx->resources, dec_pict);

		/* Free the segments from the decode picture */
		decoder_clean_bitstr_segments(&dec_pict->dec_pict_seg_list);

		pict_fragment = lst_removehead(&dec_pict->fragment_list);
		while (pict_fragment) {
			osa_free(pict_fragment);
			pict_fragment =
				lst_removehead(&dec_pict->fragment_list);
		}

		pict_start = (!head_of_queue) ? osa_true : osa_false;

		ret = dec_str_ctx->str_processed_cb(dec_str_ctx->usr_int_data,
						    VXD_CB_STRUNIT_PROCESSED,
						    dec_str_unit->str_unit);

		VDEC_ASSERT(ret == IMG_SUCCESS);
		if (ret != IMG_SUCCESS) {
			/* Free decoder picture */
			osa_free(dec_pict);
			dec_pict = NULL;
			return ret;
		}

		/* Destroy the Decoder stream unit wrapper */
		osa_free(dec_str_unit);

		/* Peek at the next stream unit */
		dec_str_unit = lst_first(&dec_str_ctx->pend_strunit_list);
		if (dec_str_unit)
			pict_start = (dec_str_unit->str_unit->str_unit_type ==
				      VDECDD_STRUNIT_PICTURE_START &&
				      dec_str_unit->dec_pict != dec_pict);

		/* Free decoder picture */
		osa_free(dec_pict);
		dec_pict = NULL;
	}

	if (dec_str_unit) {
		lst_remove(&dec_str_ctx->pend_strunit_list, dec_str_unit);
		osa_free(dec_str_unit);
    }

	return ret;
}

/*
 * @Function  decoder_is_stream_idle
 */
uint8 decoder_is_stream_idle(void *dec_str_ctx_handle)
{
	struct dec_str_ctx *dec_str_ctx;

	dec_str_ctx = decoder_stream_get_context(dec_str_ctx_handle);
	VDEC_ASSERT(dec_str_ctx);
	if (!dec_str_ctx) {
		OSA_PR_ERR("Invalid decoder stream context handle!");
		return osa_false;
	}

	return lst_empty(&dec_str_ctx->pend_strunit_list);
}

