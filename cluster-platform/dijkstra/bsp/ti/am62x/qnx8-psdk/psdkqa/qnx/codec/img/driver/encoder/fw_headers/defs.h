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

#if !defined DEFS_H_
#define DEFS_H_

#include "osal/inc/osa_types.h"

/*
 * MACROS to insert values into fields within a word. The basename of the
 * field must have MASK_BASENAME and SHIFT_BASENAME constants.
 */
#define F_MASK(basename)  (MASK_##basename)
#define F_SHIFT(basename) (SHIFT_##basename)
/*
 * Extract a value from an instruction word.
 */
#define F_EXTRACT(val,basename) (((val)&(F_MASK(basename)))>>(F_SHIFT(basename)))

/*
 * Mask and shift a value to the position of a particular field.
 */
#define F_ENCODE(val,basename)  (((val)<<(F_SHIFT(basename)))&(F_MASK(basename)))
#define F_DECODE(val,basename)  (((val)&(F_MASK(basename)))>>(F_SHIFT(basename)))

/*
 * Insert a value into a word.
 */
#define F_INSERT(word,val,basename) (((word)&~(F_MASK(basename))) | (F_ENCODE((val),basename)))

/*
 * Extract a 2s complement value from an word, and make it the correct sign
 * Works by testing the top bit to see if the value is negative
 */
#define F_EXTRACT_2S_COMPLEMENT( value, field ) ((int32)(((((((F_MASK( field ) >> F_SHIFT( field )) >> 1) + 1) & (value >> F_SHIFT( field ))) == 0) ? F_EXTRACT( value, field ) : (-(int32)(((~value & F_MASK( field )) >> F_SHIFT( field )) + 1)))))

/*
 * B stands for 'bitfield', defines should be in the form
 * #define FIELD_NAME 10:8		(i.e. upper : lower, both inclusive)
 */
#define B_EXTRACT( data, bits ) (((data) & ((uint32)0xffffffff >> (31 - (1 ? bits)))) >> (0 ? bits))
#define B_MASK( bits ) ((((uint32)0xffffffff >> (31 - (1 ? bits))) >> (0 ? bits)) << (0 ? bits))
#define B_ENCODE( data, bits ) (((data) << (0 ? bits)) & (B_MASK( bits )))
#define B_INSERT( word, data, bits ) (((word) & ~(B_MASK( bits ))) | (B_ENCODE( data, bits )))

/*
 * B_BIT returns boolean true if the corresponding bit is set
 * defines must be in the form FIELD_NAME 10:8 as above, except
 * that the bitfield must obviously be only 1 bit wide
*/
#define B_BIT( word, bits ) ((((word) >> (0 ?bits)) & 1) == 1)

#endif
