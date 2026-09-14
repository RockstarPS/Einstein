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
 * V-DEC MMU Definitions
 */

#ifndef _VXD_MMU_DEF_H_
#define _VXD_MMU_DEF_H_

/*
 * This type defines MMU variant.
 */
enum mmu_etype {
	MMU_TYPE_NONE = 0,
	MMU_TYPE_32BIT,
	MMU_TYPE_36BIT,
	MMU_TYPE_40BIT,
	MMU_TYPE_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * This type defines the MMU heaps.
 * @0:	Heap for untiled video buffers
 * @1:	Heap for bitstream buffers
 * @2:	Heap for Stream buffers
 * @3:	Number of heaps
 */
enum mmu_eheap_id {
	MMU_HEAP_IMAGE_BUFFERS_UNTILED = 0x00,
	MMU_HEAP_BITSTREAM_BUFFERS,
	MMU_HEAP_STREAM_BUFFERS,
	MMU_HEAP_MAX,
	MMU_HEAP_FORCE32BITS = 0x7FFFFFFFU
};

#endif /* _VXD_MMU_DEFS_H_ */
