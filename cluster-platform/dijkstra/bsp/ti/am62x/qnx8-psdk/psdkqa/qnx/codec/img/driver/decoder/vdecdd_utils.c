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
 * VXD Decoder device driver utility functions implementation
 */

#include "osal/inc/osa_mem.h"
#include "osal/inc/osa_define.h"
#include "bspp.h"
#include "vdecdd_utils.h"

/*
 * @Function              VDECDDUTILS_FreeStrUnit
 */
int32 vdecddutils_free_strunit(struct vdecdd_str_unit *str_unit)
{
	struct bspp_bitstr_seg *bstr_seg;

	/* Loop over bit stream segments */
	bstr_seg = (struct bspp_bitstr_seg *)
			lst_removehead(&str_unit->bstr_seg_list);
	while (bstr_seg) {
		/* Free segment. */
		osa_free(bstr_seg);

		/* Get next segment. */
		bstr_seg = (struct bspp_bitstr_seg *)
				lst_removehead(&str_unit->bstr_seg_list);
	}

	/* Free the sequence header */
	if (str_unit->seq_hdr_info) {
		str_unit->seq_hdr_info->ref_count--;
		if (str_unit->seq_hdr_info->ref_count == 0) {
			osa_free(str_unit->seq_hdr_info);
			str_unit->seq_hdr_info = NULL;
		}
	}

	/* Free the picture header... */
	if (str_unit->pict_hdr_info) {
		osa_free(str_unit->pict_hdr_info->pict_sgm_data.pic_data);
		str_unit->pict_hdr_info->pict_sgm_data.pic_data = NULL;

		osa_free(str_unit->pict_hdr_info);
		str_unit->pict_hdr_info = NULL;
	}

	/* Free stream unit. */
	osa_free(str_unit);
	str_unit = NULL;

	/* Return success */
	return IMG_SUCCESS;
}

/*
 * @Function: VDECDDUTILS_CreateStrUnit
 * @Description: this function allocate a structure for a complete data unit
 */
int32 vdecddutils_create_strunit(struct vdecdd_str_unit **str_unit_handle,
			       struct lst_t *bs_list)
{
	struct vdecdd_str_unit *str_unit;
	struct bspp_bitstr_seg *bstr_seg;

	str_unit = osa_zalloc(sizeof(*str_unit), OSA_GFP_KERNEL);
	VDEC_ASSERT(str_unit);
	if (!str_unit)
		return IMG_ERROR_OUT_OF_MEMORY;

	if (bs_list) {
		/* copy BS list to this list */
		lst_init(&str_unit->bstr_seg_list);
		for (bstr_seg = lst_first(bs_list); bstr_seg;
		     bstr_seg = lst_first(bs_list)) {
			bstr_seg = lst_removehead(bs_list);
			lst_add(&str_unit->bstr_seg_list, bstr_seg);
		}
	}

	*str_unit_handle = str_unit;

	return IMG_SUCCESS;
}

