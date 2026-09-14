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
 * topaz utility header
 */

#include "osal/inc/osa_types.h"
#include "topaz_api.h"

/*
 * Calculates the correct number of macroblocks per kick and kicks per BU
 */
void calculate_kick_and_bu_size(uint32 width_in_mbs, uint32 height_in_mbs, osa_bool is_interlaced, uint32 max_bu_per_frame,
				uint32 *kick_size, uint32 *kicks_per_bu,  uint32 *min_slice_height);

uint32 calculate_stride(enum img_format format, uint16 requested_stride_bytes, uint16 width);

void topaz_setup_input_format(struct img_video_context *video, struct img_vxe_scaler_setup *scaler_setup);

void topaz_setup_input_csc(struct img_video_context *video, struct img_vxe_scaler_setup *scaler_setup,
			   struct img_vxe_csc_setup *csc_setup, enum img_csc_preset csc_preset);

uint32 topaz_get_packed_buffer_strides(uint16 buffer_stride_bytes, enum img_format format,
				       osa_bool enable_scaler, osa_bool is_interlaced,
				       osa_bool is_interleaved);

void prepare_mv_estimates(struct img_enc_context *enc);

void adjust_pic_flags(struct img_enc_context *enc, struct img_rc_params *prc_params,
		      osa_bool first_pic, uint32 *flags);

void setup_rc_data(struct img_video_context *video, struct pic_params *pic_params,
		   struct img_rc_params *rc_params);

void patch_hw_profile(struct img_video_params *video_params, struct img_video_context *video);
