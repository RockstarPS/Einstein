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
 * buffer sizes calculation
 */

#include "topaz_api.h"
#include "fw_headers/defs.h"

void plane_size(enum img_format color_format, uint32 stride,
		uint32 height, uint32 *y_size, uint32 *u_size,
		uint32 *v_size)
{
	*y_size = *u_size = *v_size = 0;

	switch (color_format) {
		case IMG_CODEC_420_PL8:
			/* allocate frame for 4:2:0 planar format */
			*y_size = stride * height;
			*u_size = stride * height / 4;
			*v_size = stride * height / 4;
			break;
		case IMG_CODEC_420_PL12:
			/* allocate frame for 4:2:0 planar format (chroma interleaved) */
			*y_size = stride * height;
			*u_size = stride * height / 2;
			break;
		case IMG_CODEC_422_YUV:
		case IMG_CODEC_422_YV12:
		case IMG_CODEC_422_IMC2:
			/* allocate frame for 4:2:2 format */
			*y_size = stride * height * 2;
			break;
		case IMG_CODEC_422_PL8:
			/* allocate frame for 4:2:2 planar format */
			*y_size = stride * height;
			*u_size = stride * height / 2;
			*v_size = stride * height / 2;
			break;
		case IMG_CODEC_422_PL12:
			/* allocate frame for 4:2:2 planar format (chroma interleaved) */
			*y_size = stride * height;
			*u_size = stride * height;
			break;
		case IMG_CODEC_Y0UY1V_8888:
		case IMG_CODEC_UY0VY1_8888:
		case IMG_CODEC_Y0VY1U_8888:
		case IMG_CODEC_VY0UY1_8888:
			/* allocate frame for 4:2:2 format */
			*y_size = stride * height;
			break;
		case IMG_CODEC_444_YUV:
		case IMG_CODEC_444_YV12:
		case IMG_CODEC_444_IMC2:
			/* allocate frame for 4:2:2 format */
			*y_size = stride * height * 3;
			break;
		case IMG_CODEC_444_PL8:
			/* allocate frame for 4:2:2 planar format */
			*y_size = stride * height;
			*u_size = stride * height;
			*v_size = stride * height;
			break;
		case IMG_CODEC_444_PL12:
			/* allocate frame for 4:2:2 planar format (chroma interleaved) */
			*y_size = stride * height;
			*u_size = stride * height * 2;
			break;
		case IMG_CODEC_ABCX:
		case IMG_CODEC_XBCA:
		case IMG_CODEC_ABC565:
			/* allocate frame for RGB interleaved format */
			*y_size = stride * height;
			break;
		case IMG_CODEC_420_YUV:
		case IMG_CODEC_420_YV12:
		case IMG_CODEC_420_IMC2:
		case IMG_CODEC_420_PL12_PACKED:
		case IMG_CODEC_420_PL21_PACKED:
			/* allocate frame for 4:2:0 format */
			*y_size = stride * height * 3 / 2;
			break;
		default:
			*y_size = 0;
			*u_size = 0;
			*v_size = 0;
			break;
	}
	return;
}
