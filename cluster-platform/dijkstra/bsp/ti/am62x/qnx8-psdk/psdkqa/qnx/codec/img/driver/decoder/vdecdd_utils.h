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
 * VXD Decoder device driver utility header
 */

#ifndef __VDECDD_UTILS_H__
#define __VDECDD_UTILS_H__

#include "img_errors.h"
#include "vdecdd_defs.h"

/* The picture buffer alignment (in bytes) for VXD. */
#define VDEC_VXD_PICTBUF_ALIGNMENT		(64)
/* The buffer alignment (in bytes) for VXD. */
#define VDEC_VXD_BUF_ALIGNMENT			(4096)
/* The extended stride alignment for VXD.  */
#define VDEC_VXD_EXT_STRIDE_ALIGNMENT_DEFAULT	(64)
/* Macroblock dimension (width and height) in pixels. */
#define VDEC_MB_DIMENSION			(16)

static inline uint32 vdec_size_min(uint32 a, uint32 b)
{
	return(a <= b ? a : b);
}

static inline uint8 vdec_size_lt(struct vdec_pict_size sa,
			      struct vdec_pict_size sb)
{
	return((sa.width < sb.width && sa.height <= sb.height) ||
	       (sa.width <= sb.width && sa.height < sb.height));
}

static inline uint8 vdec_size_ge(struct vdec_pict_size sa,
			      struct vdec_pict_size sb)
{
	return(sa.width >= sb.width && sa.height >= sb.height);
}

static inline uint8 vdec_size_ne(struct vdec_pict_size sa,
			      struct vdec_pict_size sb)
{
	return(sa.width != sb.width || sa.height != sb.height);
}

static inline uint8 vdec_size_nz(struct vdec_pict_size sa)
{
	return(sa.width != 0 && sa.height != 0);
}

int32 vdecddutils_free_strunit(struct vdecdd_str_unit *str_unit);

int32 vdecddutils_create_strunit(struct vdecdd_str_unit **str_unit_handle,
			       struct lst_t *bs_list);

int32 vdecddutils_ref_pict_get_maxnum
	(const struct vdec_str_configdata *str_cfg_data,
	 const struct vdec_comsequ_hdrinfo *comseq_hdr_info,
	 uint32 *num_picts);

int32 vdecddutils_get_minrequired_numpicts
	(const struct vdec_str_configdata *str_cfg_data,
	 const struct vdec_comsequ_hdrinfo *comseq_hdr_info,
	 const struct vdec_str_opconfig *op_cfg,
	 uint32 *num_picts);

int32 vdecddutils_pictbuf_getconfig
	(const struct vdec_str_configdata *str_cfg_data,
	 const struct vdec_pict_rend_config *pict_rend_cfg,
	 const struct vdec_str_opconfig *str_opcfg,
	 struct vdec_pict_bufconfig *pict_bufcfg);

int32 vdecddutils_pictbuf_getinfo
	(const struct vdec_str_configdata *str_cfg_data,
	 const struct vdec_pict_rend_config *pict_rend_cfg,
	 const struct vdec_str_opconfig *str_opcfg,
	 struct vdec_pict_rendinfo *pict_rend_info);

int32 vdecddutils_convert_buffer_config
	(const struct vdec_str_configdata *str_cfg_data,
	 const struct vdec_pict_bufconfig *pict_bufcfg,
	 struct vdec_pict_rendinfo *pict_rend_info);

int32 vdecddutils_get_display_region
	(const struct vdec_pict_size *coded_size,
	 const struct vdec_rect *orig_disp_region,
	 struct vdec_rect *disp_region);

void vdecddutils_buf_vxd_adjust_size(uint32 *buf_size);

int32 vdecddutils_ref_pic_hevc_get_maxnum(const struct vdec_comsequ_hdrinfo *comseq_hdrinfo,
					       uint32 *max_ref_picnum);

#endif
