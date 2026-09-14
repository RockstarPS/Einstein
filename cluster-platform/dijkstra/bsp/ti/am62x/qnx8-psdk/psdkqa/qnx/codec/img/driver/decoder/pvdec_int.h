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
 * Low-level PVDEC interface component.
 */
#ifndef __PVDEC_INT_H__
#define __PVDEC_INT_H__

#include "hw_control.h"
#include "vxd_ext.h"
#include "vxd_props.h"

/* How many VLC IDX addresses fits in single address register */
#define PVDECIO_VLC_IDX_ADDR_PARTS 2
/*
 * Mask for VLC IDX address field. We're taking [0][0] here, as it corresponds
 * to unshifted mask
 */
#define PVDECIO_VLC_IDX_ADDR_MASK	\
		MSVDX_VEC_CR_VEC_VLC_TABLE_ADDR0_VLC_TABLE_ADDR0_MASK
/*
 * Length (shift) of VLC IDX address field. We're taking [0][1] here, as it
 * corresponds to shift of one element
 */
#define PVDECIO_VLC_IDX_ADDR_SHIFT	\
		MSVDX_VEC_CR_VEC_VLC_TABLE_ADDR0_VLC_TABLE_ADDR1_SHIFT

/* How many VLC IDX initial fits in single width register */
#define PVDECIO_VLC_IDX_WIDTH_PARTS 10
/*
 * Mask for VLC IDX width field. We're taking [0][0] here, as it corresponds
 * to unshifted mask
 */
#define PVDECIO_VLC_IDX_WIDTH_MASK	\
	MSVDX_VEC_CR_VEC_VLC_TABLE_INITIAL_WIDTH0_VLC_TABLE_INITIAL_WIDTH0_MASK
/*
 * Length (shift) of VLC IDX width field. We're taking [0][1] here, as it
 * corresponds to shift of one element
 */
#define PVDECIO_VLC_IDX_WIDTH_SHIFT	\
	MSVDX_VEC_CR_VEC_VLC_TABLE_INITIAL_WIDTH0_VLC_TABLE_INITIAL_WIDTH1_SHIFT

/* How many VLC IDX initial opcodes fits in single opcode register */
#define PVDECIO_VLC_IDX_OPCODE_PARTS 16
/*
 * Mask for VLC IDX opcode field. We're taking [0][0] here, as it corresponds
 * to unshifted mask
 */
#define PVDECIO_VLC_IDX_OPCODE_MASK	\
MSVDX_VEC_CR_VEC_VLC_TABLE_INITIAL_OPCODE0_VLC_TABLE_INITIAL_OPCODE0_MASK
/*
 * Length (shift) of VLC IDX opcode field. We're taking [0][1] here, as it
 * corresponds to shift of one element
 */
#define PVDECIO_VLC_IDX_OPCODE_SHIFT	\
MSVDX_VEC_CR_VEC_VLC_TABLE_INITIAL_OPCODE0_VLC_TABLE_INITIAL_OPCODE1_SHIFT

#define PVDECIO_VLC_IDX_ADDR_ID 2
#define PVDECIO_VLC_IDX_WIDTH_ID 1
#define PVDECIO_VLC_IDX_OPCODE_ID 0
/* This comes from DEVA PVDEC FW */
#define CTRL_ALLOC_MAX_SEGMENT_SIZE 1024

#endif /* __PVDEC_INT_H__ */
