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

#ifndef _REGCONV_H_topaz_db_regs_h
#define _REGCONV_H_topaz_db_regs_h

/* Register CR_DB_ALPHA_BETA_OFFSET */
#define TOPAZ_DB_CR_DB_ALPHA_BETA_OFFSET 0x0004
#define MASK_TOPAZ_DB_CR_H264_ALPHA_OFFSET 0x0000001F
#define SHIFT_TOPAZ_DB_CR_H264_ALPHA_OFFSET 0
#define REGNUM_TOPAZ_DB_CR_H264_ALPHA_OFFSET 0x0004
#define SIGNED_TOPAZ_DB_CR_H264_ALPHA_OFFSET 0

#define MASK_TOPAZ_DB_CR_H264_BETA_OFFSET 0x000003E0
#define SHIFT_TOPAZ_DB_CR_H264_BETA_OFFSET 5
#define REGNUM_TOPAZ_DB_CR_H264_BETA_OFFSET 0x0004
#define SIGNED_TOPAZ_DB_CR_H264_BETA_OFFSET 0

/* Register CR_DB_BUF_STATE */
#define TOPAZ_DB_CR_DB_BUF_STATE    0x0008
#define MASK_TOPAZ_DB_CR_BUSY       0x08000000
#define SHIFT_TOPAZ_DB_CR_BUSY      27
#define REGNUM_TOPAZ_DB_CR_BUSY     0x0008
#define SIGNED_TOPAZ_DB_CR_BUSY     0

/* Register CR_DB_CMD_FIFO_SIG */
#define TOPAZ_DB_CR_DB_CMD_FIFO_SIG 0x000C
#define MASK_TOPAZ_DB_CR_CMD_IN_SIGNATURE 0xFFFFFFFF
#define SHIFT_TOPAZ_DB_CR_CMD_IN_SIGNATURE 0
#define REGNUM_TOPAZ_DB_CR_CMD_IN_SIGNATURE 0x000C
#define SIGNED_TOPAZ_DB_CR_CMD_IN_SIGNATURE 0

/* Register CR_DB_INPUT_SIG */
#define TOPAZ_DB_CR_DB_INPUT_SIG    0x0010
#define MASK_TOPAZ_DB_CR_DATA_IN_SIGNATURE 0xFFFFFFFF
#define SHIFT_TOPAZ_DB_CR_DATA_IN_SIGNATURE 0
#define REGNUM_TOPAZ_DB_CR_DATA_IN_SIGNATURE 0x0010
#define SIGNED_TOPAZ_DB_CR_DATA_IN_SIGNATURE 0

/* Register CR_DB_OUTPUT_SIG */
#define TOPAZ_DB_CR_DB_OUTPUT_SIG   0x0014
#define MASK_TOPAZ_DB_CR_DATA_OUT_SIGNATURE 0xFFFFFFFF
#define SHIFT_TOPAZ_DB_CR_DATA_OUT_SIGNATURE 0
#define REGNUM_TOPAZ_DB_CR_DATA_OUT_SIGNATURE 0x0014
#define SIGNED_TOPAZ_DB_CR_DATA_OUT_SIGNATURE 0

/* Register CR_DB_DIAG */
#define TOPAZ_DB_CR_DB_DIAG         0x0018
#define MASK_TOPAZ_DB_CR_DIAG       0xFFFFFFFF
#define SHIFT_TOPAZ_DB_CR_DIAG      0
#define REGNUM_TOPAZ_DB_CR_DIAG     0x0018
#define SIGNED_TOPAZ_DB_CR_DIAG     0

/* Register CR_DB_SIG_ADDR */
#define TOPAZ_DB_CR_DB_SIG_ADDR     0x001C
#define MASK_TOPAZ_DB_CR_ADDR_OUT_SIGNATURE 0xFFFFFFFF
#define SHIFT_TOPAZ_DB_CR_ADDR_OUT_SIGNATURE 0
#define REGNUM_TOPAZ_DB_CR_ADDR_OUT_SIGNATURE 0x001C
#define SIGNED_TOPAZ_DB_CR_ADDR_OUT_SIGNATURE 0

/* Register CR_DB_START */
#define TOPAZ_DB_CR_DB_START        0x0020
#define MASK_TOPAZ_DB_CR_START      0x00000001
#define SHIFT_TOPAZ_DB_CR_START     0
#define REGNUM_TOPAZ_DB_CR_START    0x0020
#define SIGNED_TOPAZ_DB_CR_START    0

#define MASK_TOPAZ_DB_CR_FLUSH      0x00000002
#define SHIFT_TOPAZ_DB_CR_FLUSH     1
#define REGNUM_TOPAZ_DB_CR_FLUSH    0x0020
#define SIGNED_TOPAZ_DB_CR_FLUSH    0

/* Register CR_DB_RESET */
#define TOPAZ_DB_CR_DB_RESET        0x0024
#define MASK_TOPAZ_DB_CR_RESET      0x00000001
#define SHIFT_TOPAZ_DB_CR_RESET     0
#define REGNUM_TOPAZ_DB_CR_RESET    0x0024
#define SIGNED_TOPAZ_DB_CR_RESET    0

/* Register CR_DB_DISABLE_DEBLOCK_IDC */
#define TOPAZ_DB_CR_DB_DISABLE_DEBLOCK_IDC 0x002C
#define MASK_TOPAZ_DB_CR_DISABLE_DEBLOCK_IDC 0x00000003
#define SHIFT_TOPAZ_DB_CR_DISABLE_DEBLOCK_IDC 0
#define REGNUM_TOPAZ_DB_CR_DISABLE_DEBLOCK_IDC 0x002C
#define SIGNED_TOPAZ_DB_CR_DISABLE_DEBLOCK_IDC 0

#define MASK_TOPAZ_DB_CR_DISABLE_FILTER_SLICETOP 0x00000004
#define SHIFT_TOPAZ_DB_CR_DISABLE_FILTER_SLICETOP 2
#define REGNUM_TOPAZ_DB_CR_DISABLE_FILTER_SLICETOP 0x002C
#define SIGNED_TOPAZ_DB_CR_DISABLE_FILTER_SLICETOP 0

/* Register CR_DB_STATUS */
#define TOPAZ_DB_CR_DB_STATUS       0x0030
#define MASK_TOPAZ_DB_CR_V_PLANE_DONE 0x00000001
#define SHIFT_TOPAZ_DB_CR_V_PLANE_DONE 0
#define REGNUM_TOPAZ_DB_CR_V_PLANE_DONE 0x0030
#define SIGNED_TOPAZ_DB_CR_V_PLANE_DONE 0

#define MASK_TOPAZ_DB_CR_U_PLANE_DONE 0x00000002
#define SHIFT_TOPAZ_DB_CR_U_PLANE_DONE 1
#define REGNUM_TOPAZ_DB_CR_U_PLANE_DONE 0x0030
#define SIGNED_TOPAZ_DB_CR_U_PLANE_DONE 0

#define MASK_TOPAZ_DB_CR_Y_PLANE_DONE 0x00000004
#define SHIFT_TOPAZ_DB_CR_Y_PLANE_DONE 2
#define REGNUM_TOPAZ_DB_CR_Y_PLANE_DONE 0x0030
#define SIGNED_TOPAZ_DB_CR_Y_PLANE_DONE 0

#define MASK_TOPAZ_DB_CR_MODULE_BUSY 0x00000008
#define SHIFT_TOPAZ_DB_CR_MODULE_BUSY 3
#define REGNUM_TOPAZ_DB_CR_MODULE_BUSY 0x0030
#define SIGNED_TOPAZ_DB_CR_MODULE_BUSY 0

/* Register CR_DB_PERFORMANCE_0 */
#define TOPAZ_DB_CR_DB_PERFORMANCE_0 0x0034
#define MASK_TOPAZ_DB_CR_WORST_MB_CYCLES 0x0000FFFF
#define SHIFT_TOPAZ_DB_CR_WORST_MB_CYCLES 0
#define REGNUM_TOPAZ_DB_CR_WORST_MB_CYCLES 0x0034
#define SIGNED_TOPAZ_DB_CR_WORST_MB_CYCLES 0

#define MASK_TOPAZ_DB_CR_WORST_MB_TYPE 0x00030000
#define SHIFT_TOPAZ_DB_CR_WORST_MB_TYPE 16
#define REGNUM_TOPAZ_DB_CR_WORST_MB_TYPE 0x0034
#define SIGNED_TOPAZ_DB_CR_WORST_MB_TYPE 0

/* Register CR_DB_PERFORMANCE_1 */
#define TOPAZ_DB_CR_DB_PERFORMANCE_1 0x0038
#define MASK_TOPAZ_DB_CR_WORST_MB_NUMBER 0x003FFFFF
#define SHIFT_TOPAZ_DB_CR_WORST_MB_NUMBER 0
#define REGNUM_TOPAZ_DB_CR_WORST_MB_NUMBER 0x0038
#define SIGNED_TOPAZ_DB_CR_WORST_MB_NUMBER 0

/* Register CR_DB_PERFORMANCE_RESET */
#define TOPAZ_DB_CR_DB_PERFORMANCE_RESET 0x003C
#define MASK_TOPAZ_DB_CR_WORST_MB_RESET 0x00000001
#define SHIFT_TOPAZ_DB_CR_WORST_MB_RESET 0
#define REGNUM_TOPAZ_DB_CR_WORST_MB_RESET 0x003C
#define SIGNED_TOPAZ_DB_CR_WORST_MB_RESET 0

#define MASK_TOPAZ_DB_CR_DISABLE_COUNTERS 0x00000002
#define SHIFT_TOPAZ_DB_CR_DISABLE_COUNTERS 1
#define REGNUM_TOPAZ_DB_CR_DISABLE_COUNTERS 0x003C
#define SIGNED_TOPAZ_DB_CR_DISABLE_COUNTERS 0

/*
	Byte range covering the group TOPAZHP_DB file
*/

#define TOPAZ_DB_TOPAZHP_DB_REGISTERS_START		0x00000004
#define TOPAZ_DB_TOPAZHP_DB_REGISTERS_END  		0x0000003F

/*
	Byte range covering the whole register file
*/

#define TOPAZ_DB_REGISTERS_START		0x00000004
#define TOPAZ_DB_REGISTERS_END  		0x0000003F
#define TOPAZ_DB_REG_DEFAULT_TABLE struct {\
			IMG_UINT16 uRegOffset;\
			IMG_UINT32 uRegDefault;\
			IMG_UINT32 uRegMask;\
			bool bReadonly;\
			const char* pszName;\
		} TOPAZ_DB_Defaults[] = {\
	{0x0004, 0x00000000, 0x000003FF, 0, "CR_DB_ALPHA_BETA_OFFSET" } ,\
	{0x0008, 0x00000000, 0x08000000, 1, "CR_DB_BUF_STATE" } ,\
	{0x000C, 0x00000000, 0xFFFFFFFF, 1, "CR_DB_CMD_FIFO_SIG" } ,\
	{0x0010, 0x00000000, 0xFFFFFFFF, 1, "CR_DB_INPUT_SIG" } ,\
	{0x0014, 0x00000000, 0xFFFFFFFF, 1, "CR_DB_OUTPUT_SIG" } ,\
	{0x0018, 0x11000000, 0xFFFFFFFF, 1, "CR_DB_DIAG" } ,\
	{0x001C, 0x00000000, 0xFFFFFFFF, 1, "CR_DB_SIG_ADDR" } ,\
	{0x0020, 0x00000000, 0x00000003, 0, "CR_DB_START" } ,\
	{0x0024, 0x00000000, 0x00000001, 0, "CR_DB_RESET" } ,\
	{0x002C, 0x00000000, 0x00000007, 0, "CR_DB_DISABLE_DEBLOCK_IDC" } ,\
	{0x0030, 0x00000000, 0x0000000F, 1, "CR_DB_STATUS" } ,\
	{0x0034, 0x00000000, 0x0003FFFF, 1, "CR_DB_PERFORMANCE_0" } ,\
	{0x0038, 0x00000000, 0x003FFFFF, 1, "CR_DB_PERFORMANCE_1" } ,\
	{0x003C, 0x00000000, 0x00000003, 0, "CR_DB_PERFORMANCE_RESET" } ,\
{ 0 }}

#define TOPAZ_DB_REGS_INIT(uBase) \
	{ \
		int n;\
		TOPAZ_DB_REG_DEFAULT_TABLE;\
		for (n = 0; n < sizeof(TOPAZ_DB_Defaults)/ sizeof(TOPAZ_DB_Defaults[0] ) -1; n++)\
		{\
			RegWriteNoTrap(TOPAZ_DB_Defaults[n].uRegOffset + uBase, TOPAZ_DB_Defaults[n].uRegDefault); \
		}\
	}
#endif
