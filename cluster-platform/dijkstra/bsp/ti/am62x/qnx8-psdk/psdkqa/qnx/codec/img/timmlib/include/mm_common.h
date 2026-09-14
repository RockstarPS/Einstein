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
 * RTOS Codec User API definitions
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

#ifndef MM_COMMON_H_
#define MM_COMMON_H_

#define CODEC_CFG_PRINT_BUF_LEN		((uint32_t) 1024U)

extern struct MM_COMMON_Inst g_MM_COMMON_Inst;

#define MAX_PLANES	3
/**
 * \defgroup TI MM API based H.264 Decoder
 *
 * \brief H.264 Decoder APIs. Valid only for **TI-RTOS**
 *
 * \ingroup TI_MM_APIs
 *
 * @{
 */

/** @enum mapper::mm_pixelformat
 *  @brief MM Pixel Format
 *  @var mapper::mm_pixelformat::MM_PIX_FMT_NV12
 *  0x01
 *  @var mapper::mm_pixelformat::MM_PIX_FMT_NV12M
 *  0x02
 *  @var mapper::mm_pixelformat::MM_PIX_FMT_NV16
 *  0x03
 *  @var mapper::mm_pixelformat::MM_PIX_FMT_TI1210
 *  0x04
 *  @var mapper::mm_pixelformat::MM_PIX_FMT_TI1210M
 *  0x05
 *  @var mapper::mm_pixelformat::MM_PIX_FMT_TI1610
 *  0x06
 *  @var mapper::mm_pixelformat::MM_PIX_FMT_H264
 *  0x07
 *  @var mapper::mm_pixelformat::MM_PIX_FMT_HEVC
 *  0x08
 *  @var mapper::mm_pixelformat::MM_PIX_FMT_MJPEG
 *  0x09
 *  @var mapper::mm_pixelformat::MM_PIX_FMT_YUV420M
 *  0x0A
 *  @var mapper::mm_pixelformat::MM_PIX_FMT_YUV422P
 *  0x0B
 *  @var mapper::mm_pixelformat::MM_PIX_FMT_FORCE32BITS
 *  0x7FFFFFFFU
 */
/**
 * \verbatim
 *  MM Pixel Format, only below options are supported as of today
 *  Input Format
 *     - MM_PIX_FMT_H264
 *  Output Format
 *     - MM_PIX_FMT_NV12
 *     - MM_PIX_FMT_TI1210 \endverbatim
 */
enum mm_pixelformat {
	MM_PIX_FMT_NV12 = 0x01,
	MM_PIX_FMT_NV12M = 0x02,
	MM_PIX_FMT_NV16 = 0x03,
	MM_PIX_FMT_TI1210 = 0x04,
	MM_PIX_FMT_TI1210M = 0x05,
	MM_PIX_FMT_TI1610 = 0x06,
	MM_PIX_FMT_H264 = 0x07,
	MM_PIX_FMT_HEVC = 0x08,
	MM_PIX_FMT_MJPEG = 0x09,
	MM_PIX_FMT_YUV420M = 0x0A,
	MM_PIX_FMT_YUV422P = 0x0B,
	MM_PIX_FMT_FORCE32BITS = 0x7FFFFFFFU
};

/** @enum mapper::mm_buffertype
 *  @brief MM Buffer types
 *  @var mapper::mm_buffertype::MM_BUF_TYPE_VIDEO_INPUT
 *  0x10
 *  @var mapper::mm_buffertype::MM_BUF_TYPE_VIDEO_OUTPUT
 *  0x01
 *  @var mapper::mm_buffertype::MM_BUF_TYPE_VIDEO_FORCE32BITS
 *  0x7FFFFFFFU
 */
/**
 *  \verbatim
 *  MM Buffer, supported types - input or output
 *  To be set by application \endverbatim
 */
typedef enum {
	MM_BUF_TYPE_VIDEO_INPUT = 0x10,
	MM_BUF_TYPE_VIDEO_OUTPUT = 0x01,
	MM_BUF_TYPE_VIDEO_FORCE32BITS = 0x7FFFFFFFU
} mm_buffertype;

/**
 * \verbatim
 *  MM Decoder create time paramters, to be set/configured by application
 *  before MM_DEC_Create() \endverbatim
 */
typedef struct {
	/** Video frame width */
	uint32_t width;
	/** Video frame height */
	uint32_t height;
	/** Video frame rate*/
	uint32_t framerate;
	/** Refer enum mm_pixelformat for supported in_pixelformat values */
	uint32_t in_pixelformat;
	/** Refer enum mm_pixelformat for supported out_pixelformat values */
	uint32_t out_pixelformat;
} mm_vid_create_params;

/**
 * \verbatim
 *  MM buffer Object, to be filled by application \endverbatim
 */
struct mm_buffer {
	/** Channel ID */
	uint32_t chId;
	/** Refer enum mm_buffertype for the supported values */
	mm_buffertype type;
	/** Size of the data in bytes */
	uint32_t size[MAX_PLANES];
	/** Size of the buffer in bytes */
	uint32_t alloc_size[MAX_PLANES];
	/** Buffer address */
	void *buf_addr[MAX_PLANES];
	/** Physic address */
	uintptr_t physic_addr[MAX_PLANES];
	uint32_t num_planes;
	/** pointer of private data associate with the buffer*/
	/** In the OpenMAXIL case, this can be OMX BufHeader*/
	void *buf_private;
	/** this is for IPC communication between resource manager and client*/
	void *rm_private;
};

/**
 * \verbatim
 *  MM OSA CFG, Callbacks for mem & logging,
 *  to be filled by application \endverbatim
 */
struct mm_osa_cfg {
	/** Call back for the memory allocation, to be set by application */
	void* (*memAlloc)(uint32_t size);
	/** Call back for the memory free, to be set by application */
	void (*memFree)(void *ptr, uint32_t size);
	/** Call back for logging, to be set by application */
	void (*printFxn)(const char *format, ...);
}; 

struct MM_COMMON_Inst {
	struct mm_osa_cfg osa_params;
	char printBuf[CODEC_CFG_PRINT_BUF_LEN];
};

/**
 *  \brief MM_DEC_OsaInit - To set callback for mem & logging feature
 *  This function should called only once before any other MM APIs.
 *  \verbatim
 *  params: Structure holds application callbacks.\endverbatim
 */
void MM_COMMON_OsaInit(struct mm_osa_cfg *params);

/*@}*/
#endif /* MM_COMMON_H_ */
