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
 * VDECDD translation API's.
 */
#ifndef __TRANSLATION_API_H__
#define __TRANSLATION_API_H__

#include "decoder.h"
#include "hw_control.h"
#include "vdecdd_defs.h"
#include "vdec_defs.h"
#include "vxd_props.h"

/*
 * This function submits a stream unit for translation
 * into a control allocation buffer used in PVDEC operation.
 */
int32 translation_ctrl_alloc_prepare
		(struct vdec_str_configdata *psstr_config_data,
		 struct vdecdd_str_unit *psstrunit,
		 struct dec_decpict *psdecpict,
		 const struct vxd_coreprops *core_props,
		 struct decoder_regsoffsets *regs_offset);

/*
 * TRANSLATION_FragmentPrepare.
 */
int32 translation_fragment_prepare(struct dec_decpict *psdecpict,
				 struct lst_t *decpic_seg_list, int32 eop,
				 struct dec_pict_fragment *pict_fragement);

#endif /* __TRANSLATION_API_H__ */
