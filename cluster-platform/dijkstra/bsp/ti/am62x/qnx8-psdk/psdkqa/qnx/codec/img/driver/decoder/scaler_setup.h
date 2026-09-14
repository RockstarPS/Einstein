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
 * VXD DEC constants calculation and scalling coefficients
 */
#ifndef _SCALER_SETUP_H
#define _SCALER_SETUP_H

#define LOWP				11
#define HIGHP				14

#define FIXED(a, digits)		((int32)((a) * (1 << (digits))))

struct scaler_params {
	uint32  vert_pitch;
	uint32  vert_startpos;
	uint32  vert_pitch_chroma;
	uint32  vert_startpos_chroma;
	uint32  horz_pitch;
	uint32  horz_startpos;
	uint32  horz_pitch_chroma;
	uint32  horz_startpos_chroma;
	uint8   fixed_point_shift;
};

struct scaler_filter {
	uint8 bhoriz_bilinear;
	uint8 bvert_bilinear;
};

struct scaler_pitch {
	int32 horiz_luma;
	int32 vert_luma;
	int32 horiz_chroma;
	int32 vert_chroma;
};

struct scaler_config {
	enum vdec_vid_std vidstd;
	const struct vxd_coreprops *coreprops;
	struct pixel_pixinfo *in_pixel_info;
	const struct pixel_pixinfo *out_pixel_info;
	uint8 bfield_coded;
	uint8 bseparate_chroma_planes;
	uint32 recon_width;
	uint32 recon_height;
	uint32 mb_width;
	uint32 mb_height;
	uint32 scale_width;
	uint32 scale_height;
};

#endif /* _SCALER_SETUP_H */
