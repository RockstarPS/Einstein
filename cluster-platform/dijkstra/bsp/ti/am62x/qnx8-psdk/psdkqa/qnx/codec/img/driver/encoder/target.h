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
 * target interface header
 */

#if !defined (__TARGET_H__)
#define __TARGET_H__

#include "osal/inc/osa_types.h"

#define TARGET_NO_IRQ   (999) /* Interrupt number when no interrupt exists */

/*
 * The memory space types
 */
enum mem_space_type
{
	MEMSPACE_REGISTER,  /* Memory space is mapped to device registers */
	MEMSPACE_MEMORY,     /* Memory space is mapped to device memory */
	MEMSPACE_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * This structure contains all information about a device register
 */
struct mem_space_reg
{
	uint64 addr; /* Base address of device registers */
	uint32 size; /* Size of device register block */
	uint32 intr_num; /* The interrupt number */
};

/*
 * This structure contains all information about a device memory region
 */
struct mem_space_mem
{
	uint64 addr; /* Base address of memory region */
	uint64 size; /* Size of memory region */
	uint64 guard_band; /* Memory guard band */
};

/*
 * This structure contains all information about the device memory space
 */
struct mem_space
{
	osa_char *               name;     /* Memory space name */
	enum mem_space_type      type;     /* Memory space type */
	union
	{
		struct mem_space_reg reg;      /* Device register info */
		struct mem_space_mem mem;      /* Device memory region info */
	};

	uint_addr		cpu_addr; /* Cpu KM address for the mem space */
};

struct target_config
{
	uint32 num_mem_spaces;
	struct mem_space * mem_spaces;
};

#endif /* __TARGET_H__    */
