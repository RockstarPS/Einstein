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
 * Public data structures for the h264 parser firmware module.
 */

#include "jpegfw_data_shared.h"

#ifndef _JPEGFW_DATA_H_
#define _JPEGFW_DATA_H_

#define MAX_CODE_WORDS 256
#define JPEG_VDEC_8x8_DCT_SIZE             64 //!< Number of elements in 8x8 DCT
#define JPEG_VDEC_MAX_COMPONENTS           4  //!< Maximum number of component in JPEG
#define JPEG_VDEC_MAX_SETS_HUFFMAN_TABLES  2  //!< Maximum set of huffman table in JPEG
#define JPEG_VDEC_MAX_QUANT_TABLES         4  //!< Maximum set of quantisation table in JPEG
#define JPEG_VDEC_QUANT_TBL_ELEMS          16 //!< Maximum number of elements in quantisation table in JPEG
#define JPEG_VDEC_TABLE_CLASS_NUM          2  //!< Maximum set of class of huffman table in JPEG
#define JPEG_VDEC_PLANE_MAX                4  //!< Maximum number of planes

struct hentry {
	uint16 code;
	uint8 codelen;
	uint8 value;
};

/*
 * This structure contains JPEG huffmant table
 * NOTE: Should only contain JPEG specific information.
 * @brief  JPEG Huffman Table Information
 */
struct vdec_jpeg_huffman_tableinfo {
	/* number of bits */
	uint8 bits[16];
	/* codeword value */
	uint8 values[256];
};

/*
 * This structure contains JPEG DeQunatisation table
 * NOTE: Should only contain JPEG specific information.
 * @brief  JPEG Dequantisation Table Information
 */
struct vdec_jpeg_de_quant_tableinfo {
	/* Qunatisation precision */
	uint8 precision;
	/* Qunatisation Value for 8x8 DCT  */
	uint16 elements[64];
};

/*
 * This describes the JPEG parser component "Header data", shown in the
 * Firmware Memory Layout diagram. This data is required by the JPEG firmware
 * and should be supplied by the Host.
 */
struct jpegfw_header_data {
	/* Primary decode buffer base addresses */
	struct vdecfw_image_buffer primary;
	/* Reference (output) picture base addresses */
	uint32 plane_offsets[JPEG_VDEC_PLANE_MAX];
	/* SOS fields count value */
	uint8 hdr_sos_count;
};

/*
 * This describes the JPEG  parser component "Context data".
 * JPEG does not need any data to be saved between pictures, this structure
 * is needed only to fit in firmware framework.
 */
struct jpegfw_context_data {
	uint32 dummy;
};

#endif /* _JPEGFW_DATA_H_ */
