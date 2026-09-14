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
 * VXD Decoder CORE and V4L2 Node Interface header
 */

#ifndef __CORE_H__
#define __CORE_H__

#include "osal/inc/osa_types.h"
#include "decoder.h"

int32 core_initialise(void *dev_handle, uint32 internal_heap_id,
		    void *cb);

int32 core_deinitialise(void);

int32 core_supported_features(struct vdec_features *features);

int32 core_stream_create(void *vxd_dec_ctx_arg,
		       const struct vdec_str_configdata *str_cfgdata,
		       uint32 *res_str_id);

int32 core_stream_destroy(uint32 res_str_id);

int32 core_stream_play(uint32 res_str_id);

int32 core_stream_stop(uint32 res_str_id);

int32 core_stream_map_buf(uint32 res_str_id, enum vdec_buf_type buf_type,
			struct vdec_buf_info *buf_info, uint32 *buf_map_id);

int32 core_stream_map_buf_sg(uint32 res_str_id,
			   enum vdec_buf_type buf_type,
			   struct vdec_buf_info *buf_info,
			   void *sgt, uint32 *buf_map_id);

int32 core_stream_unmap_buf(uint32 buf_map_id);

int32 core_stream_unmap_buf_sg(uint32 buf_map_id);

int32 core_stream_submit_unit(uint32 res_str_id,
			    struct vdecdd_str_unit *str_unit);

int32 core_stream_fill_pictbuf(uint32 buf_map_id);

/* This function to be called before stream play */
int32 core_stream_set_output_config(uint32 res_str_id,
				  struct vdec_str_opconfig *str_opcfg,
				  struct vdec_pict_bufconfig *pict_bufcg);

int32 core_stream_flush(uint32 res_str_id, uint8 discard_refs);

int32 core_stream_release_bufs(uint32 res_str_id,
			     enum vdec_buf_type buf_type);

int32 core_stream_get_status(uint32 res_str_id,
			   struct vdecdd_decstr_status *str_status);

#endif
