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
 * encoder interface definitions
 *
 * Copyright (c) Imagination Technologies Ltd.
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com/
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

/**
 *  \file     mm_enc.h
 *
 *  \brief    This file contains interface header for TI MM API encoder
 *
 */

#ifndef MM_ENC_H_
#define MM_ENC_H_

#include "mm_common.h"

/** @enum mapper::mm_enc_process_cb
 *  @brief callbacks from codec library
 *  @var mapper::mm_enc_process_cb::MM_CB_CODED_BUFF_READY
 *  0
 *  @var mapper::mm_enc_process_cb::MM_CB_SRC_FRAME_RELEASE
 *  1
 *  @var mapper::mm_enc_process_cb::MM_CB_ENC_STR_END
 *  2
 *  @var mapper::mm_enc_process_cb::MM_CB_ENC_ERROR_FATAL
 *  3
 *  @var mapper::mm_enc_process_cb::MM_CB_ENC_FORCE32BITS
 *  0x7FFFFFFFU
 */
/**
 * \verbatim
 *  MM Encoder supported callback types
 *  Application shall use this type to free/display input/output buffers \endverbatim
 */
typedef enum {
	MM_CB_CODED_BUFF_READY,
	MM_CB_SRC_FRAME_RELEASE,
	MM_CB_ENC_STR_END,
	MM_CB_ENC_ERROR_FATAL,
	MM_CB_ENC_FORCE32BITS = 0x7FFFFFFFU
} mm_enc_process_cb;

/**
 * \verbatim
 *  MM Encoder supported features
 *  Application shall use this type to configure encoder features \endverbatim
 */
typedef enum {
	MM_ENC_FEATURE_CABAC = 0x0001,
	MM_ENC_FEATURE_8x8 = 0x0002,
	MM_ENC_FEATURE_DISABLE_INTRA4x4 = 0x0004,
	MM_ENC_FEATURE_DISABLE_INTRA8x8 = 0x0008,
	MM_ENC_FEATURE_DISABLE_INTRA16x16 = 0x0010,
	MM_ENC_FEATURE_DISABLE_INTER8x8 = 0x0020,
	MM_ENC_FEATURE_RESTRICT_INTER4x4 = 0x0040,
	MM_ENC_FEATURE_DISABLE_8x16_MV_DETECT = 0x0080,
	MM_ENC_FEATURE_DISABLE_16x8_MV_DETECT = 0x0100
} mm_enc_features;

/**
 * \verbatim
 *  MM Encoder supported RC Modes
 *  Application shall use this type to configure encoder RC mode \endverbatim
 */
typedef enum {
	MM_ENC_VBR,
	MM_ENC_SVBR
} mm_enc_rcmode;

/**
 * \verbatim
 *  Enum describing smallest blocksize used during motion search
 *  MM_ENC_BLK_SZ_DEFAULT: Driver picks the best possible block size for this encode session
 *  MM_ENC_BLK_SZ_16x16: Use 16x16 block size for motion search. This is the smallest for h.263
 *  MM_ENC_BLK_SZ_8x8: Use 'upto' 8x8 block size for motion search. This is the smallest for MPEG-4
 *  MM_ENC_BLK_SZ_4x4: Use 'upto' 4x4 block size for motion search. This is the smallest for H.264
 */
typedef enum {
	MM_ENC_BLK_SZ_DEFAULT = 0,
	MM_ENC_BLK_SZ_16x16,
	MM_ENC_BLK_SZ_8x8,
	MM_ENC_BLK_SZ_4x4
} mm_enc_minblocksize;

/**
 * \verbatim
 *  MM Encoder Control Parameters, to be set/configured by application
 *  before MM_ENC_Create() \endverbatim
 */
typedef struct {
	/** Bit flags for encoding features */
	uint32_t features;
	/** RC Mode */
	mm_enc_rcmode rcmode;
	/** IDR-period */
	uint32_t idr_period;
	/** I-period */
	uint32_t i_period;
	/** Bitrate */
	uint32_t bitrate;
	/** Framerate */
	uint8_t framerate;
	/** Crop settings */
	uint32_t crop_left;
	uint32_t crop_right;
	uint32_t crop_top;
	uint32_t crop_bottom;
	/** # Slices */
	uint8_t nslices;
	/** base pipe */
	uint8_t base_pipe;
	/** Qp Settings */
	uint32_t initial_qp_i;
	uint32_t initial_qp_p;
	uint32_t initial_qp_b;
	uint32_t min_qp;
	uint32_t max_qp;
	/** Min Block Size for motion search */
	mm_enc_minblocksize min_blk_size;
	/** Controls H264COMP_INTRA_PRED_MODES register. Leave 0 for default. See TRM for details */
	uint32_t intra_pred_modes;
} mm_enc_ctrl_params;

/**
 * \verbatim
 *  MM Encoder Init Parameters, to be set/configured by application
 *  before MM_ENC_Init() \endverbatim
 */
typedef struct {
	void *ocm_ram_addr;
	uint32_t ocm_ram_size;
} mm_enc_init_params;


static inline void MM_ENC_SetDefaultInitParams(mm_enc_init_params *init_params)
{
	init_params->ocm_ram_addr = NULL;
	init_params->ocm_ram_size = 0;
};


/**
 *  \brief MM_ENC_Init - Initialize the encoder
 *  This function should called only once.
 *  \verbatim
 *  Return: 0          -> Success
 *  Return: -ve values -> Failure \endverbatim
 */
int32_t MM_ENC_Init(mm_enc_init_params *init_params);

/**
 *  \brief MM_ENC_Control - Set encoder controls
 *  This function should only be called before MM_ENC_Create
 *  \verbatim
 *  Return: 0          -> Success
 *  Return: -ve values -> Failure \endverbatime
 */
int32_t MM_ENC_Control();

/**
 *  \brief MM_ENC_Create - Create the encoder instance (channel specific API)
 *  \verbatim
 *  params: MM Encoder create params
 *  chId  : Channel ID
 *  Return: 0 -> Success
 *  Return:-1 -> Failure \endverbatim
 */
int32_t MM_ENC_Create(mm_vid_create_params *params, mm_enc_ctrl_params *ctrl, uint32_t *chId);

/**
 *  \brief MM_ENC_RegisterCb - Register Callback (channel specific API)
 *  This is the callback function when encoder completes frame encoding
 *  \verbatim
 *  buf     : Encoder output buffer (frame buffer)
 *  cb_type : callback Type
 *  chId	: Channel ID
 *  Return  : 0 -> Success
 *  Return  :-1 -> Failure \endverbatim
 */
int32_t MM_ENC_RegisterCb(
		void (*mm_ret_resource)(struct mm_buffer *buf, mm_enc_process_cb cb_type, void *cb_ctx),
		uint32_t chId, void *cb_ctx);

/**
 *  \brief MM_ENC_StartStreaming - Start the instance (channel specific API)
 *  \verbatim
 *  chId  : Channel ID
 *  type  : buffer type, input or output
 *  Return: 0 -> Success
 *  Return:-1 -> Failure \endverbatim
 */
int32_t MM_ENC_StartStreaming(uint32_t chId, mm_buffertype type);

/**
 *  \brief MM_ENC_BufPrepare - Alloc/Prepare the encoder buffers (channel specific API)
 *  This needs to be called for all input and output buffers atleast
 *  once to map the buffer with VXD MMU.
 *  \verbatim
 *  buffer: Buffer Object
 *  chId  : Channel ID
 *  Return: 0 -> Success
 *  Return:-1 -> Failure \endverbatim
 */
int32_t MM_ENC_BufPrepare(struct mm_buffer *buffer, uint32_t chId);

/**
 *  \brief MM_ENC_Process - Perform the encode Process (channel specific API)
 *  Non-blocking API, Encode completion is notified by callback
 *  \verbatim
 *  in_buf  : Input Buffer Object
 *  out_buf : Output Buffer Object
 *  chId    : Channel ID
 *  Return  : 0 -> Success
 *  Return  :-1 -> Failure\endverbatim
 */
int32_t MM_ENC_Process(struct mm_buffer *in_buf,
		struct mm_buffer *out_buf_slice1, struct mm_buffer *out_buf_slice2, uint32_t chId);

/**
 *  \brief MM_ENC_StopStreaming - Stop the instance (channel specific API)
 *  \verbatim
 *  chId  : Channel ID
 *  type  : buffer type, input or output
 *  Return: 0 -> Success
 *  Return:-1 -> Failure \endverbatim
 */
int32_t MM_ENC_StopStreaming(uint32_t chId, mm_buffertype type);

/**
 *  \brief MM_ENC_Destroy - Destroy the encoder instance (channel specific API)
 *  \verbatim
 *  chId  : Channel ID
 *  Return: 0 -> Success
 *  Return:-1 -> Failure \endverbatim
 */
int32_t MM_ENC_Destroy(uint32_t chId);

/**
 *  \brief MM_ENC_Deinit - De-initialize the encoder
 *  This function should called only once.
 *  \verbatim
 *  Return: 0 -> Success
 *  Return:-1 -> Failure \endverbatim
 */
int32_t MM_ENC_Deinit(void);

int32_t MM_ENC_QueryBufInfo(uint32_t chId, uint32_t *nbuffers, uint32_t *max_size);
/*@}*/
#endif /* MM_ENC_H_ */
