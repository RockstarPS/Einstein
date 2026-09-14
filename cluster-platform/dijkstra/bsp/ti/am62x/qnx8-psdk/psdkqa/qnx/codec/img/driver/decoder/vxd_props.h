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
 * Low-level VXD interface component
 */

#ifndef _VXD_PROPS_H
#define _VXD_PROPS_H

#include "vdec_defs.h"
#include "imgmmu.h"

#define VDEC_MAX_PIXEL_PIPES 2

#define VXD_MAX_CORES    1
#define VER_STR_LEN      64

#define CORE_REVISION(maj, min, maint) \
	((((maj) & 0xff) << 16) | (((min) & 0xff) << 8) | (((maint) & 0xff)))
#define MAJOR_REVISION(rev)	(((rev) >> 16) & 0xff)
#define MINOR_REVISION(rev)	(((rev) >> 8) & 0xff)
#define MAINT_REVISION(rev)	((rev) & 0xff)

#define FROM_REV(maj, min, maint, type) ({ \
		type __maj = maj; \
		type __min = min; \
		(((maj_rev) > (__maj)) || \
		(((maj_rev) == (__maj)) && ((min_rev) > (__min))) || \
		(((maj_rev) == (__maj)) && ((min_rev) == (__min)) && \
		((int32)(maint_rev) >= (maint)))); })

#define BEFORE_REV(maj, min, maint, type) ({ \
	type __maj = maj; \
	type __min = min; \
	(((int32)(maj_rev) < (__maj)) || \
	(((maj_rev) == (__maj)) && ((int32)(min_rev) < (__min))) || \
	(((maj_rev) == (__maj)) && ((min_rev) == (__min)) && \
	((int32)(maint_rev) < (maint)))); })

#define AT_REV(maj, min, maint)	(((maj_rev) == (uint32)maj) && \
	((min_rev) == (uint32)min) && ((maint_rev) == (uint32)maint))

struct vxd_vidstd_props {
	enum vdec_vid_std vidstd;
	uint32      core_rev;
	uint32      min_width;
	uint32      min_height;
	uint32      max_width;
	uint32      max_height;
	uint32      max_macroblocks;
	uint32      max_luma_bitdepth;
	uint32      max_chroma_bitdepth;
	enum pixel_fmt_idc max_chroma_format;
};

struct vxd_coreprops {
	uint8 aversion[VER_STR_LEN];
	uint8 mpeg2[VDEC_MAX_PIXEL_PIPES];
	uint8 mpeg4[VDEC_MAX_PIXEL_PIPES];
	uint8 h264[VDEC_MAX_PIXEL_PIPES];
	uint8 vc1[VDEC_MAX_PIXEL_PIPES];
	uint8 avs[VDEC_MAX_PIXEL_PIPES];
	uint8 real[VDEC_MAX_PIXEL_PIPES];
	uint8 jpeg[VDEC_MAX_PIXEL_PIPES];
	uint8 vp6[VDEC_MAX_PIXEL_PIPES];
	uint8 vp8[VDEC_MAX_PIXEL_PIPES];
	uint8 hevc[VDEC_MAX_PIXEL_PIPES];
	uint8 rotation_support[VDEC_MAX_PIXEL_PIPES];
	uint8 scaling_support[VDEC_MAX_PIXEL_PIPES];
	uint8 hd_support;
	uint32 num_streams[VDEC_MAX_PIXEL_PIPES];
	uint32 num_entropy_pipes;
	uint32 num_pixel_pipes;
	struct vxd_vidstd_props vidstd_props[VDEC_STD_MAX];
	enum mmu_etype mmu_type;
	uint8 mmu_support_stride_per_context;
	uint8 mmu_support_secure;
	/* Range extensions supported by hw -> used only by hevc */
	uint8 hevc_range_ext[VDEC_MAX_PIXEL_PIPES];
};

#endif /* _VXD_PROPS_H */
