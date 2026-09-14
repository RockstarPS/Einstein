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
 * IMG MSVDX core Registers
 * This file contains the MSVDX_CORE_REGS_H Definitions
 */

#ifndef REG_IO2_H_
#define REG_IO2_H_

#define IMG_ASSERT(expected) (void)((expected) || \
		(OSA_PR_ERR("Assertion failed: %s, file %s, line %d\n", \
		#expected, __FILE__, __LINE__), OSA_DUMP_STACK, 0))

/* This macro is used to extract a field from a register. */
#define REGIO_READ_FIELD(regval, group, reg, field)	\
	(((regval) & group##_##reg##_##field##_MASK) >> \
			group##_##reg##_##field##_SHIFT)

/* This macro is used to extract the value of a repeated from a register. */
#define REGIO_READ_REPEATED_FIELD(regval, group, reg, field, repidx, type) ({ \
	type __repidx = repidx; \
	(IMG_ASSERT((__repidx) < group##_##reg##_##field##_NO_REPS), \
	(((regval) & (group##_##reg##_##field##_MASK >> \
	((group##_##reg##_##field##_NO_REPS - \
	(__repidx) - 1) * group##_##reg##_##field##_SIZE))) >> \
	(group##_##reg##_##field##_SHIFT - \
	((group##_##reg##_##field##_NO_REPS - (__repidx) - 1) * \
	group##_##reg##_##field##_SIZE)))); })

#if (defined WIN32 || defined __linux__) && !defined NO_REGIO_CHECK_FIELD_VALUE
	/*
	 * Only provide register field range checking for Windows and
	 * Linux builds
	 * Simple range check that ensures that if bits outside the valid field
	 * range are set, that the provided value is at least consistent with a
	 * negative value (i.e.: all top bits are set to 1).
	 * Cannot perform more comprehensive testing without knowing
	 * whether field
	 * should be interpreted as signed or unsigned.
	 */
	#define REGIO_CHECK_VALUE_FITS_WITHIN_FIELD(group, reg, field, value, type) \
	{								\
	type __value = value; \
	uint32 temp = (uint32)(__value);					\
		if (temp > group##_##reg##_##field##_LSBMASK) {	\
			IMG_ASSERT((((uint32)__value) & \
			(uint32)~(group##_##reg##_##field##_LSBMASK)) ==	\
			(uint32)~(group##_##reg##_##field##_LSBMASK));	\
		}							\
	}
#else
	#define REGIO_CHECK_VALUE_FITS_WITHIN_FIELD(group, reg, field, value, type)
#endif

/* This macro is used to update the value of a field in a register. */
#define REGIO_WRITE_FIELD(regval, group, reg, field, value, reg_type, val_type)	\
{								\
	reg_type __regval = regval; \
	val_type __value = value; \
	REGIO_CHECK_VALUE_FITS_WITHIN_FIELD(group, reg, field, __value, val_type); \
	(regval) =							\
	((__regval) & ~(group##_##reg##_##field##_MASK)) |		\
		(((uint32)(__value) << (group##_##reg##_##field##_SHIFT)) & \
				(group##_##reg##_##field##_MASK));	\
}

/* This macro is used to update the value of a field in a register. */
#define REGIO_WRITE_FIELD_LITE(regval, group, reg, field, value, type)	\
{									\
	type __value = value; \
	REGIO_CHECK_VALUE_FITS_WITHIN_FIELD(group, reg, field, __value, type); \
	(regval) |= ((uint32)(__value) << (group##_##reg##_##field##_SHIFT)); \
}

/*
 * This macro shifts a value to its correct position in a register. This is
 * used for statically defining register values
 */
#define REGIO_ENCODE_FIELD(group, reg, field, value)    \
		((uint32)(value) << (group##_##reg##_##field##_SHIFT))

#endif /* REG_IO2_H_ */
