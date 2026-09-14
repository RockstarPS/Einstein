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
 * osa mutex definitions
 */

#ifndef OSA_MUTEX_H_
#define OSA_MUTEX_H_

#include "osa_types.h"

/* Mutex subclasses */
#define OSA_SUBCLASS_BASE       0
#define OSA_SUBCLASS_VXD_V4L2   1
#define OSA_SUBCLASS_VXE_V4L2   1
#define OSA_SUBCLASS_BSPP       1
#define OSA_SUBCLASS_ADDR_ALLOC 7
#define OSA_SUBCLASS_IMGMEM     6
#define OSA_SUBCLASS_RMAN       1
#define OSA_SUBCLASS_TALMMU     5
#define OSA_SUBCLASS_VXD_CORE   2
#define OSA_SUBCLASS_POOL       3
#define OSA_SUBCLASS_POOL_RES   5
#define OSA_SUBCLASS_TOPAZ_API  2
#define OSA_SUBCLASS_TOPAZDD_TX 4
#define OSA_SUBCLASS_TOPAZDD    3

/**
 * osa_mutex_create - allocate and initializes the mutex
 *
 * @mutex_args: Mutex variable
 *
 * Initialize the mutex to unlocked state.
 */
void osa_mutex_create (void **mutex_args);


/**
 * osa_mutex_unlock - release the mutex
 * @mutex_args: Mutex variable
 *
 * This is used to unlock/release a mutex that has been locked by a task previously.
 */
void osa_mutex_unlock (void *mutex_args);


/**
 * osa_mutex_lock - acquire the mutex
 * @mutex_args: Mutex variable
 *
 * This is used to lock/acquire the mutex exclusively for the current task.
 * If the mutex is not available, the current task will sleep until it acquires the Mutex.
 */
void osa_mutex_lock (void *mutex_args);


/**
 * osa_mutex_lock_nested - acquire the nested mutex
 * @mutex_args: Mutex variable
 * @subclass: Subclass
 *
 * This is used to lock/aquire the mutex exclusively for the current task.
 * If the mutex is not available, the current task will sleep until it acquires the mutex.
 * The subclass variable is given for use with kernel lockdep debugging enabled.
 */
void osa_mutex_lock_nested(void *mutex_args, uint32 subclass);

/**
 * osa_mut_destroy - destroy and release the mutex object
 * @mutex_args: Mutex variable
 *
 * This function marks the mutex uninitialized, and any subsequent
 * use of the mutex is forbidden. The mutex must not be locked when
 * this function is called.
 */
void osa_mutex_destroy(void **mutex_args);


/**
 * osa_mutex_lockinterruptible - acquire the mutex unless interrupted
 * @mutex_args: Mutex variable
 *
 * Locks the mutex like mutex_lock, and returns 0 if the mutex has been acquired or
 * sleep until the mutex becomes available.
 * If a signal arrives while waiting for the lock then this function returns -OSA_EINTR.
 */
int32 osa_mutex_lockinterruptible (void *mutex_args);

/**
 * osa_mutex_lockinterruptible - acquire the mutex unless interrupted
 * @mutex_args: Mutex variable
 * @subclass: subclass
 *
 * Locks the mutex like mutex_lock, and returns 0 if the mutex has been acquired or
 * sleep until the mutex becomes available.
 * If a signal arrives while waiting for the lock then this function returns -OSA_EINTR.
 * The subclass variable is given for use with kernel lockdep debugging enabled.
 */
int32 osa_mutex_lockinterruptible_nested (void *mutex_args, uint32 subclass);

/**
 * osa_mutex_trylock - try to acquire the mutex, without waiting
 * @mutex_args: Mutex variable
 *
 * This will try to acquire the mutex, without waiting
 * (will attempt to obtain the lock, but will not sleep).
 * Returns 1 if the mutex has been acquired successfully, and 0 on contention.
 */
int32 osa_mutex_trylock (void *mutex_args);


/**
 * osa_mutex_is_locked - This function is used to check whether mutex has been locked or not
 * @mutex_args: Mutex variable
 *
 * Returns 1 if the mutex is locked, 0 if unlocked.
 */
int32 osa_mutex_is_locked (void *mutex_args);

/**
 * osa_mutex_lock_killable() - Acquire the mutex, interruptible by fatal signals.
 * @mutex_args: Mutex variable
 *
 * Lock the mutex like osa_mutex_lock().  If a signal which will be fatal to
 * the current process is delivered while the process is sleeping, this
 * function will return without acquiring the mutex.
 *
 * Context: Process context.
 * Return: 0 if the lock was successfully acquired or %-OSA_EINTR if a
 * fatal signal arrived.
 */
int32  osa_mutex_lock_killable(void *mutex_args);

/**
 * osa_mutex_lock_io() - Acquire the mutex and mark the process as waiting for I/O
 * @mutex_args: Mutex variable
 *
 * Lock the mutex like osa_mutex_lock().  While the task is waiting for this
 * mutex, it will be accounted as being in the IO wait state by the
 * scheduler.
 *
 * Context: Process context.
 */
void  osa_mutex_lock_io(void *mutex_args);

/**
 * osa_mut_ret() - Return the mutex variable to the called function
 * @mutex_args: Mutex variable
 */

#endif /* OSA_MUTEX_H_ */
