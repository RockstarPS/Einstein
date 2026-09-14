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
 * firmware header
 */

#ifndef _REGCONV_H_topazhp_multicore_regs_old_h
#define _REGCONV_H_topazhp_multicore_regs_old_h

/* Register CR_LAMBDA_DC_TABLE */
#define TOPAZHP_TOP_CR_LAMBDA_DC_TABLE 0x0120
#define MASK_TOPAZHP_TOP_CR_QPC_OR_DC_SCALE_LUMA_TABLE 0x000000FF
#define SHIFT_TOPAZHP_TOP_CR_QPC_OR_DC_SCALE_LUMA_TABLE 0
#define REGNUM_TOPAZHP_TOP_CR_QPC_OR_DC_SCALE_LUMA_TABLE 0x0120
#define SIGNED_TOPAZHP_TOP_CR_QPC_OR_DC_SCALE_LUMA_TABLE 0

#define MASK_TOPAZHP_TOP_CR_SATD_LAMBDA_OR_DC_SCALE_CHROMA_TABLE 0x0000FF00
#define SHIFT_TOPAZHP_TOP_CR_SATD_LAMBDA_OR_DC_SCALE_CHROMA_TABLE 8
#define REGNUM_TOPAZHP_TOP_CR_SATD_LAMBDA_OR_DC_SCALE_CHROMA_TABLE 0x0120
#define SIGNED_TOPAZHP_TOP_CR_SATD_LAMBDA_OR_DC_SCALE_CHROMA_TABLE 0

#define MASK_TOPAZHP_TOP_CR_SAD_LAMBDA_TABLE 0x007F0000
#define SHIFT_TOPAZHP_TOP_CR_SAD_LAMBDA_TABLE 16
#define REGNUM_TOPAZHP_TOP_CR_SAD_LAMBDA_TABLE 0x0120
#define SIGNED_TOPAZHP_TOP_CR_SAD_LAMBDA_TABLE 0


/* Register CR_MVCALC_COLOCATED (from topazhp_core_regs.h) */
#define MASK_TOPAZHP_CR_TEMPORAL_BLEND 0x001F0000
#define SHIFT_TOPAZHP_CR_TEMPORAL_BLEND 16
#define REGNUM_TOPAZHP_CR_TEMPORAL_BLEND 0x0174
#define SIGNED_TOPAZHP_CR_TEMPORAL_BLEND 0

#endif
