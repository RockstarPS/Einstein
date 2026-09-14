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
 * IMG PVDEC pixel Registers
 */

#ifndef _MEM_IO_H
#define _MEM_IO_H

#include "osal/inc/osa_types.h"
#include "reg_io2.h"

#define RND_TO_WORDS(size) ((((size) + 3) / 4) * 4)

#define MEMIO_CHECK_ALIGNMENT(vpmem)        \
		IMG_ASSERT((vpmem))

#define MEMIO_READ_FIELD(vpmem, field) \
	((((*((field##_TYPE *)(((uintptr_t)(vpmem)) + field##_OFFSET))) & \
			field##_MASK) >> field##_SHIFT))

#define MEMIO_READ_TABLE_FIELD(vpmem, field, tabidx) \
	((((*((field##_TYPE *)(((uintptr_t)(vpmem)) + field##_OFFSET + \
	(field##_STRIDE * (tabidx))))) & field##_MASK) >> field##_SHIFT)) \

#define MEMIO_READ_REPEATED_FIELD(vpmem, field, repidx, type) ({ \
	type __repidx = repidx; \
	((((*((field##_TYPE *)(((uintptr_t)(vpmem)) + field##_OFFSET))) & \
	(field##_MASK >> ((__repidx) * field##_SIZE))) >> \
	(field##_SHIFT - ((__repidx) * field##_SIZE)))); }) \

#define MEMIO_READ_TABLE_REPEATED_FIELD(vpmem, field, tabidx, repidx, type) ({ \
	type __repidx = repidx; \
	((((*((field##_TYPE *)(((uintptr_t)(vpmem)) + field##_OFFSET + \
	(field##_STRIDE * (tabidx))))) & (field##_MASK >> \
	((__repidx) * field##_SIZE))) >> (field##_SHIFT - \
	((__repidx) * field##_SIZE)))); }) \

#define MEMIO_WRITE_FIELD(vpmem, field, value, type) \
	do { \
		type __vpmem = vpmem; \
		MEMIO_CHECK_ALIGNMENT(__vpmem); \
		(*((field##_TYPE *)(((uintptr_t)(__vpmem)) + \
		field##_OFFSET))) = \
		(field##_TYPE)(((*((field##_TYPE *)(((uintptr_t)(__vpmem)) + \
		field##_OFFSET))) & ~(field##_TYPE)field##_MASK) | \
		(field##_TYPE)(((value) << field##_SHIFT) & field##_MASK)); \
	} while (0) \

#define MEMIO_WRITE_FIELD_LITE(vpmem, field, value, type) \
	do { \
		type __vpmem = vpmem; \
		MEMIO_CHECK_ALIGNMENT(__vpmem); \
		(*((field##_TYPE *)(((uintptr_t)(__vpmem)) + \
		field##_OFFSET))) = \
		((*((field##_TYPE *)(((uintptr_t)(__vpmem)) + \
		field##_OFFSET))) |\
		(field##_TYPE) (((value) << field##_SHIFT))); \
	} while (0) \

#define MEMIO_WRITE_TABLE_FIELD(vpmem, field, tabidx, value, vp_type, ta_type) \
	do { \
		vp_type __vpmem = vpmem; \
		ta_type __tabidx = tabidx; \
		MEMIO_CHECK_ALIGNMENT(__vpmem); \
		IMG_ASSERT(((__tabidx) < field##_NO_ENTRIES) || \
		(field##_NO_ENTRIES == 0)); \
		(*((field##_TYPE *)(((uintptr_t)(__vpmem)) + field##_OFFSET + \
		(field##_STRIDE * (__tabidx))))) =  \
		((*((field##_TYPE *)(((uintptr_t)(__vpmem)) + field##_OFFSET + \
		(field##_STRIDE * (__tabidx))))) & \
		(field##_TYPE)~field##_MASK) | \
		(field##_TYPE)(((value) << field##_SHIFT) & field##_MASK); \
	} while (0) \

#define MEMIO_WRITE_REPEATED_FIELD(vpmem, field, repidx, value, vp_type, re_type) \
	do { \
		vp_type __vpmem = vpmem; \
		re_type __repidx = repidx; \
		MEMIO_CHECK_ALIGNMENT(__vpmem); \
		IMG_ASSERT((__repidx) < field##_NO_REPS); \
		(*((field##_TYPE *)(((uintptr_t)(__vpmem)) + \
		field##_OFFSET))) = \
		((*((field##_TYPE *)(((uintptr_t)(__vpmem)) + \
		field##_OFFSET))) & \
		(field##_TYPE)~(field##_MASK >> ((__repidx) * field##_SIZE)) | \
		(field##_TYPE)(((value) << (field##_SHIFT - \
		((__repidx) * field##_SIZE))) & (field##_MASK >> \
		((__repidx) * field##_SIZE)))); \
	} while (0) \

#define MEMIO_WRITE_TABLE_REPEATED_FIELD(vpmem, field, tabidx, repidx, value, vp_type, ta_type, re_type) \
	do { \
		vp_type __vpmem = vpmem; \
		ta_type __tabidx = tabidx; \
		re_type __repidx = repidx; \
		MEMIO_CHECK_ALIGNMENT(__vpmem); \
		IMG_ASSERT(((__tabidx) < field##_NO_ENTRIES) || \
		(field##_NO_ENTRIES == 0)); \
		IMG_ASSERT((__repidx) < field##_NO_REPS); \
		(*((field##_TYPE *)(((uintptr_t)(__vpmem)) + field##_OFFSET + \
		(field##_STRIDE * (__tabidx))))) = \
		((*((field##_TYPE *)(((uintptr_t)(__vpmem)) + field##_OFFSET + \
		(field##_STRIDE * (__tabidx))))) & \
		(field##_TYPE)~(field##_MASK >> \
		((__repidx) * field##_SIZE))) | (field##_TYPE)(((value) << \
		(field##_SHIFT - ((__repidx) * field##_SIZE))) & \
		(field##_MASK >> ((__repidx) * field##_SIZE))); \
	} while (0) \

#endif /* _MEM_IO_H */
