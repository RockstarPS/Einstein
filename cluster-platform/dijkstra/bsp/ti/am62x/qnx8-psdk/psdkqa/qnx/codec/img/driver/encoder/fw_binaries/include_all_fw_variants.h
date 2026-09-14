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

#ifndef __INCLUDE_ALL_VARIANTS_INC_INCLUDED__
#define __INCLUDE_ALL_VARIANTS_INC_INCLUDED__

#define INCLUDE_ALL_VARIANTS_TEMPLATE_VERSION (1)

#define FW_BIN_FORMAT_VERSION (2)

struct IMG_COMPILED_FW_BIN_RECORD {

	uint32 text_size, data_size;
	uint32 data_origin, text_origin;
	uint32 text_reloc_size, data_reloc_size;

	uint32 pipes;
	osa_char *fmt, *rc_mode;
	uint32 formats_mask, hw_config;

	uint32 int_define_cnt;
	osa_char **int_define_names;
	uint32 *int_defines;

	uint32 *text, *data;
	uint32 *text_reloc, *data_reloc;
	uint32 *text_reloc_full_addr, *text_reloc_type;
};

#include "ALL_CODECS_FW_ALL_pipes_2_contexts_8_hwconfig_1_bin.c"

uint32 all_fw_binaries_cnt = 1;
struct IMG_COMPILED_FW_BIN_RECORD *all_fw_binaries[] = {
	&sIMG_COMPILED_ALL_CODECS_FW_ALL_pipes_2_contexts_8_hwconfig_1,
};

#endif
