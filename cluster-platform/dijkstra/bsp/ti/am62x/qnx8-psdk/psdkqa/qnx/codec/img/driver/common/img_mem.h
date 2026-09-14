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
 * Typedefs for memory pool and attributes
 */
#ifndef __IMG_MEM__
#define __IMG_MEM__

/*
 * This type defines the memory attributes.
 * @0x00000001: Memory to be allocated as cached
 * @0x00000002: Memory to be allocated as uncached
 * @0x00000004: Memory to be allocated as write-combined
 *	(or equivalent buffered/burst writes mechanism)
 * @0x00001000: Memory can be read only by the core
 * @0x00002000: Memory can be written only by the core
 * @0x00010000: Memory should be readable by the cpu
 * @0x00020000: Memory should be writable by the cpu
 */
enum sys_emem_attrib {
	SYS_MEMATTRIB_CACHED             = 0x00000001,
	SYS_MEMATTRIB_UNCACHED           = 0x00000002,
	SYS_MEMATTRIB_WRITECOMBINE       = 0x00000004,
	SYS_MEMATTRIB_SECURE             = 0x00000010,
	SYS_MEMATTRIB_INPUT              = 0x00000100,
	SYS_MEMATTRIB_OUTPUT             = 0x00000200,
	SYS_MEMATTRIB_INTERNAL           = 0x00000400,
	SYS_MEMATTRIB_CORE_READ_ONLY     = 0x00001000,
	SYS_MEMATTRIB_CORE_WRITE_ONLY    = 0x00002000,
	SYS_MEMATTRIB_CPU_READ           = 0x00010000,
	SYS_MEMATTRIB_CPU_WRITE          = 0x00020000,
	SYS_MEMATTRIB_FORCE32BITS = 0x7FFFFFFFU
};

#endif /* __IMG_MEM__ */
