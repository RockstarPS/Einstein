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
 * Pixel processing functions header
 */

#ifndef __PIXEL_API_H__
#define __PIXEL_API_H__

#include "osal/inc/osa_types.h"

#include "img_errors.h"
#include "img_pixfmts.h"

#define PIXEL_MULTICHROME   osa_true
#define PIXEL_MONOCHROME    osa_false
#define IMG_MAX_NUM_PLANES  4
#define PIXEL_INVALID_BDC   8

extern uint8 pix_fmt_idc_names[6][16];

struct img_pixfmt_desc {
	uint8 planes[IMG_MAX_NUM_PLANES];
	uint32 bop_denom;
	uint32 bop_numer[IMG_MAX_NUM_PLANES];
	uint32 h_denom;
	uint32 v_denom;
	uint32 h_numer[IMG_MAX_NUM_PLANES];
	uint32 v_numer[IMG_MAX_NUM_PLANES];
};

/*
 * @brief This type defines memory chroma interleaved order
 */
enum pixel_chroma_interleaved {
	PIXEL_INVALID_CI  = 0,
	PIXEL_UV_ORDER    = 1,
	PIXEL_VU_ORDER    = 2,
	PIXEL_YAYB_ORDER  = 4,
	PIXEL_AYBY_ORDER  = 8,
	PIXEL_ORDER_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * @brief This macro translates enum pixel_chroma_interleaved values into
 * value that can be used to write HW registers directly.
 */
#define PIXEL_GET_HW_CHROMA_INTERLEAVED(value) \
	((value) & PIXEL_VU_ORDER ? osa_true : osa_false)

/*
 * @brief This type defines memory packing types
 */
enum pixel_mem_packing {
	PIXEL_BIT8_MP      = 0,
	PIXEL_BIT10_MSB_MP = 1,
	PIXEL_BIT10_LSB_MP = 2,
	PIXEL_BIT10_MP      = 3,
	PIXEL_DEFAULT_MP    = 0xff,
	PIXEL_DEFAULT_FORCE32BITS = 0x7FFFFFFFU
};

static inline uint8 pixel_get_hw_memory_packing(enum pixel_mem_packing value)
{
	return(value == PIXEL_BIT8_MP ? osa_false :
	       value == PIXEL_BIT10_MSB_MP ? osa_false :
	       value == PIXEL_BIT10_LSB_MP ? osa_false :
	       value == PIXEL_BIT10_MP ? osa_true : osa_false);
}

/*
 * @brief This type defines chroma formats
 */
enum pixel_fmt_idc {
	PIXEL_FORMAT_MONO = 0,
	PIXEL_FORMAT_411  = 1,
	PIXEL_FORMAT_420  = 2,
	PIXEL_FORMAT_422  = 3,
	PIXEL_FORMAT_444  = 4,
	PIXEL_FORMAT_INVALID = 0xFF,
	PIXEL_FORMAT_FORCE32BITS = 0x7FFFFFFFU
};

static inline int32 pixel_get_hw_chroma_format_idc(enum pixel_fmt_idc value)
{
	return(value == PIXEL_FORMAT_MONO ? 0 :
	       value == PIXEL_FORMAT_420 ? 1 :
	       value == PIXEL_FORMAT_422 ? 2 :
	       value == PIXEL_FORMAT_444 ? 3 :
	       PIXEL_FORMAT_INVALID);
}

/*
 * @brief This structure contains information about the pixel formats
 */
struct pixel_pixinfo {
	enum img_pixfmt			pixfmt;
	enum pixel_chroma_interleaved	chroma_interleave;
	uint8				chroma_fmt;
	enum pixel_mem_packing		mem_pkg;
	enum pixel_fmt_idc		chroma_fmt_idc;
	uint32				bitdepth_y;
	uint32				bitdepth_c;
	uint32				num_planes;
};

/*
 * @brief This type defines the image in memory
 */
struct pixel_info {
	uint32	pixels_in_bop;
	uint32	ybytes_in_bop;
	uint32	uvbytes_in_bop;
	uint32	vbytes_in_bop;
	uint32	alphabytes_in_bop;
	uint8	is_planar;
	uint8	uv_height_halved;
	uint32	uv_stride_ratio_times4;
	uint8	has_alpha;
};

struct pixel_pixinfo_table {
	enum img_pixfmt	pix_color_fmt;
	struct pixel_info	info;
};

struct pixel_pixinfo *pixel_get_pixinfo(const enum img_pixfmt pixfmt);

enum img_pixfmt pixel_get_pixfmt(enum pixel_fmt_idc chroma_fmt_idc,
				 enum pixel_chroma_interleaved
				 chroma_interleaved,
				 enum pixel_mem_packing mem_packing,
				 uint32 bitdepth_y, uint32 bitdepth_c,
				 uint32 num_planes);

int32 pixel_yuv_get_desc(struct pixel_pixinfo *pix_info,
		       struct img_pixfmt_desc *desc);

int32 pixel_get_fmt_desc(enum img_pixfmt pixfmt,
		       struct img_pixfmt_desc *fmt_desc);

int32 pixel_gen_pixfmt(enum img_pixfmt *pix_fmt, struct img_pixfmt_desc* pix_desc);

#endif

