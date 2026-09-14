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
 * osa register io definitions
 *
 * Copyright (c) Imagination Technologies Ltd.
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com/
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation version 2.
 *
 * This program is distributed "as is" WITHOUT ANY WARRANTY of any
 * kind, whether express or implied; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef OSA_REG_IO_H_
#define OSA_REG_IO_H_

#include "osa_types.h"

#define ENCODER0_REG_SIZE 0x100000
/**
 * osa_reg32_write - Write a value to a 32-bit register
 *
 * @val: 32-bit value to write to the register
 * @addr: Address of the register to write
 *
 * Write the 32-bit value specified in val to the register
 * address specified in addr.
 */
void osa_reg32_write (uint32 val, uint_addr addr);

/**
 * osa_reg32_read - Read the value from a 32-bit register
 *
 * @addr: Address of the register to read
 *
 * Read the value from the register specified by addr.
 * Returns the 32-bit value read from the register.
 */
uint32 osa_reg32_read (uint_addr addr);

/**
 * osa_reg32_poll_iseq - Poll for a register to have a certain value
 *
 * @addr: Address of the register to poll
 * @req_val: Required value of the register
 * @mask: Mask to be used on the result of the register read before checking
 * @cnt: Number of times to poll
 *
 * Poll the register cnt times or until the masked value read from the register
 * is equal to req_val.
 * Returns 0 upon success.
 * Returns -1 upon timeout.
 */
int32 osa_reg32_poll_iseq(uint_addr addr, uint32 req_val, uint32 mask, uint32 cnt);

/* return the base address of decoder register */
void *osa_get_decoder_base_reg_addr(void);

void *osa_get_encoder_base_reg_addr(void);


#endif /* OSA_REG_IO_H_ */
