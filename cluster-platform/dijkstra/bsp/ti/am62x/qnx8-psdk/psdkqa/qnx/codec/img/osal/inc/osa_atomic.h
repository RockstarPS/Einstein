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
 * osa atomic definitions
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

#ifndef OSA_ATOMIC_H_
#define OSA_ATOMIC_H_

#include "osa_types.h"

/**
 * osa_atomic_create - allocate and initializes the mutex
 *
 * @atomic_args: Atomic variable
 *
 * Allocate and initialize the atomic variable.
 * Returns error if fails to allocate.
 */
int32 osa_atomic_create (void **atomic_args);


/**
 * osa_atomic_destroy - destroy and release the atomic object
 * @atomic_args: Atomic variable
 *
 * This function marks the atomic variable uninitialized, and any subsequent
 * use is forbidden.
 */
void osa_atomic_destroy(void **atomic_args);


/**
 * osa_atomic_read - read the value of the atomic variable
 * @atomic_args: Atomic variable
 *
 * Returns the value of the atomic variable. Returns -1 if fails.
 */
int32 osa_atomic_read(void *atomic_args);


/**
 * osa_atomic_set - set the value of the atomic variable
 * @atomic_args: Atomic variable
 *
 * Sets the value of the atomic variable.
 */
void osa_atomic_set(void *atomic_args, int32 val);


/**
 * osa_atomic_inc_ret - Increment the atomic var and return the value.
 * @atomic_args: Atomic variable
 *
 * Returns the value of the atomic variable after adding 1.
 * Returns -1 if fails.
 */
int32 osa_atomic_inc_ret(void *atomic_args);


/**
 * osa_atomic_dec_ret - Decrement the atomic var and return the value.
 * @atomic_args: Atomic variable
 *
 * Returns the value of the atomic variable after subtracting 1.
 * Returns -1 if fails.
 */
int32 osa_atomic_dec_ret(void *atomic_args);

#endif /* OSA_ATOMIC_H_ */
