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
 * decoder interface definitions
 */

/**
 *  \file     mm_dec.h
 *
 *  \brief    This file contains interface header for TI MM API decoder
 *
 */

#ifndef MM_DEC_H_
#define MM_DEC_H_

#include "mm_common.h"


/** @enum mapper::mm_dec_process_cb
 *  @brief callbacks from codec library
 *  @var mapper::mm_dec_process_cb::MM_CB_STRUNIT_PROCESSED
 *  0
 *  @var mapper::mm_dec_process_cb::MM_CB_SPS_RELEASE
 *  1
 *  @var mapper::mm_dec_process_cb::MM_CB_PPS_RELEASE
 *  2
 *  @var mapper::mm_dec_process_cb::MM_CB_PICT_DECODED
 *  3
 *  @var mapper::mm_dec_process_cb::MM_CB_PICT_DISPLAY
 *  4
 *  @var mapper::mm_dec_process_cb::MM_CB_PICT_RELEASE
 *  5
 *  @var mapper::mm_dec_process_cb::MM_CB_PICT_END
 *  6
 *  @var mapper::mm_dec_process_cb::MM_CB_STR_END
 *  7
 *  @var mapper::mm_dec_process_cb::MM_CB_ERROR
 *  8
 *  @var mapper::mm_dec_process_cb::MM_CB_FORCE32BITS
 *  0x7FFFFFFFU
 */
/**
 * \verbatim
 *  MM Decoder supported callback types
 *  Application shall use this type to free/display input/output buffers \endverbatim
 */
typedef enum {
	MM_CB_STRUNIT_PROCESSED,
	MM_CB_SPS_RELEASE,
	MM_CB_PPS_RELEASE,
	MM_CB_PICT_DECODED,
	MM_CB_PICT_DISPLAY,
	MM_CB_PICT_RELEASE,
	MM_CB_PICT_END,
	MM_CB_STR_END,
	MM_CB_ERROR,
	MM_CB_FORCE32BITS = 0x7FFFFFFFU
} mm_dec_process_cb;

/*
 * mm_error_type is a link to vdec_error_type in vdec_defs.h
 * Please keep them strictly in sync
 * @brief  MM parsing/decoding error  Information
 */
enum mm_error_type {
	MM_ERROR_NONE			= (0),
	MM_ERROR_SR_ERROR		= (1 << 0),
	MM_ERROR_FEHW_TIMEOUT		= (1 << 1),
	MM_ERROR_FEHW_DECODE		= (1 << 2),
	MM_ERROR_BEHW_TIMEOUT		= (1 << 3),
	MM_ERROR_SERVICE_TIMER_EXPIRY	= (1 << 4),
	MM_ERROR_MISSING_REFERENCES	= (1 << 5),
	MM_ERROR_MMU_FAULT		= (1 << 6),
	MM_ERROR_DEVICE		= (1 << 7),
	MM_ERROR_CORRUPTED_REFERENCE	= (1 << 8),
	MM_ERROR_MMCO			= (1 << 9),
	MM_ERROR_MBS_DROPPED		= (1 << 10),
	MM_ERROR_MAX			= (1 << 11),
	MM_ERROR_FORCE32BITS = 0x7FFFFFFFU
};

typedef struct {
	/** Placeholder for empty struct */
	uint32_t placeholder;
} mm_dec_ctrl_params;

/**
 *  \brief MM_DEC_Init - Initialize the decoder
 *  This function should called only once.
 *  \verbatim
 *  Return: 0          -> Success
 *  Return: -ve values -> Failure \endverbatim
 */
int32_t MM_DEC_Init(void);

/**
 *  \brief MM_DEC_Create - Create the decoder instance (channel specific API)
 *  \verbatim
 *  params: MM Decoder create params
 *  chId  : Channel ID
 *  Return: 0 -> Success
 *  Return:-1 -> Failure \endverbatim
 */
int32_t MM_DEC_Create(mm_vid_create_params *params, mm_dec_ctrl_params *ctrl, uint32_t *chId);

/**
 *  \brief MM_DEC_RegisterCb - Register Callback (channel specific API)
 *  This is the callback function when decoder completes frame decoding
 *  \verbatim
 *  buf     : Decoder output buffer (frame buffer)
 *  cb_type : callback Type
 *  chId	: Channel ID
 *  cb_ctx	: Context associates with the caller
 *  Return  : 0 -> Success
 *  Return  :-1 -> Failure \endverbatim
 */
int32_t MM_DEC_RegisterCb(
		void (*mm_ret_resource)(void *item, mm_dec_process_cb cb_type, void *cb_ctx),
		uint32_t chId, void *cb_ctx);

/**
 *  \brief MM_DEC_StartStreaming - Start the instance (channel specific API)
 *  \verbatim
 *  chId  : Channel ID
 *  type  : buffer type, input or output
 *  Return: 0 -> Success
 *  Return:-1 -> Failure \endverbatim
 */
int32_t MM_DEC_StartStreaming(uint32_t chId, mm_buffertype type);

/**
 *  \brief MM_DEC_BufPrepare - Alloc/Prepare the decoder buffers (channel specific API)
 *  This needs to be called for all input and output buffers atleast
 *  once to map the buffer with VXD MMU.
 *  \verbatim
 *  buffer: Buffer Object
 *  chId  : Channel ID
 *  Return: 0 -> Success
 *  Return:-1 -> Failure \endverbatim
 */
int32_t MM_DEC_BufPrepare(struct mm_buffer *buffer, uint32_t chId);

/**
 *  \brief MM_DEC_Process - Perform the decode Process (channel specific API)
 *  Non-blocking API, Decode completion is notified by callback
 *  \verbatim
 *  in_buf  : Input Buffer Object
 *  out_buf : Output Buffer Object
 *  chId    : Channel ID
 *  Return  : 0 -> Success
 *  Return  :-1 -> Failure\endverbatim
 */
int32_t MM_DEC_Process(struct mm_buffer *in_buf,
		struct mm_buffer *out_buf, uint32_t chId);

/**
 *  \brief MM_DEC_StopStreaming - Stop the instance (channel specific API)
 *  \verbatim
 *  chId  : Channel ID
 *  type  : buffer type, input or output
 *  Return: 0 -> Success
 *  Return:-1 -> Failure \endverbatim
 */
int32_t MM_DEC_StopStreaming(uint32_t chId, mm_buffertype type);

/**
 *  \brief MM_DEC_Destroy - Destroy the decoder instance (channel specific API)
 *  \verbatim
 *  chId  : Channel ID
 *  Return: 0 -> Success
 *  Return:-1 -> Failure \endverbatim
 */
int32_t MM_DEC_Destroy(uint32_t chId);

/**
 *  \brief MM_DEC_Deinit - De-initialize the decoder
 *  This function should called only once.
 *  \verbatim
 *  Return: 0 -> Success
 *  Return:-1 -> Failure \endverbatim
 */
int32_t MM_DEC_Deinit(void);

/*@}*/
#endif /* MM_DEC_H_ */
