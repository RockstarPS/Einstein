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
 * osa spinlock definitions
 */

#ifndef OSA_SPIN_H_
#define OSA_SPIN_H_

#include "osa_types.h"

void *appMemMap_2(void *phys_ptr, uint32_t size);

 /**
  * osa_spin_lock_create -  Allocate memory and initializing spin-lock to unlocked state
  *
  * @lock: spin-lock variable
  * @name: Pointer to a name for the new spinlock. Only the pointer,
  * but not the whole name, is copied into the spinlock.
  * The name is used for diagnostics purposes only.
  * This argument used in RTOS platform
  */
void osa_spin_lock_create(void **lock_args, const int8 *name);

/**
 * osa_spin_lock -  This will take the lock if it is free,
 * otherwise it’ll spin until that lock is free (Keep trying).
 *
 * @lock: Spin-lock variable
 */
void osa_spin_lock(void *lock);

/**
 * osa_spin_trylock -  Locks the spinlock if it is not already locked.
 * If unable to obtain the lock it exits with an error and do not spin.
 *
 * @lock: spin-lock variable
 *
 * It returns non-zero if obtains the lock otherwise returns zero.
 */
int32 osa_spin_trylock(void *lock);

/**
 * osa_spin_unlock -  It does the reverse of lock.
 *
 * @lock: spin-lock variable
 */
void osa_spin_unlock(void *lock);

/**
 * osa_spin_is_locked -  This is used to check whether the lock is available or not.
 *
 * @lock: spin-lock variable
 *
 * It returns non-zero if the lock is currently acquired. otherwise returns zero.
 */
int32 osa_spin_is_locked(void *lock);

/**
 * osa_spin_lock_irqsave - This will save whether interrupts
 * were on or off in a flags word and grab the lock.
 *
 * @lock: spin-lock variable
 * @flags: flag to save the interrupt status
 */
void osa_spin_lock_irqsave(void *lock, ulong *flags);

/**
 * osa_spin_unlock_irqrestore - This will releases the spinlock and restores
 * the interrupts using the flags argument.
 *
 * @lock: spin-lock variable
 * @flags: flag contains interrupt status
 */
void osa_spin_unlock_irqrestore(void *lock, ulong flags);

/**
 * osa_spin_lock_irq - This will disable interrupts on that cpu,
 * then grab the lock.
 *
 * @lock: spin-lock variable
 */
void osa_spin_lock_irq(void *lock);

/**
 * osa_spin_unlock_irq -  It will release the lock and re-enables
 * the interrupts which is disabled by above call.
 *
 * @lock: spin-lock variable
 */
void osa_spin_unlock_irq(void *lock);

/**
 * osa_spin_destroy - destroy and release the spin object
 * @spin_args: spin variable
 *
 * This function marks the spin uninitialized, and any subsequent
 * use of the spin is forbidden.
 */
void osa_spin_destroy(void **lock_args);

#endif /* OSA_SPIN_H_ */
