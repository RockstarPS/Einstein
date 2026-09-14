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
 * osa spinlock handling implementation for QNX
 */

#include <sys/neutrino.h>
#include "../../inc/osa_spin.h"
#include "../../inc/osa_define.h"
#include "../../inc/osa_mem.h"
#include "img_errors.h"

void osa_spin_lock_irqsave(void *lock, ulong *flags_args)
{
    intrspin_t *spinlock_ptr = NULL;

    /* Create a spinLock and lock interrupts */
    spinlock_ptr = malloc(sizeof(intrspin_t));
    if(spinlock_ptr  == NULL) {
        OSA_PR_ERR("osa_spin_lock_irqsave malloc failed");
        return;
    }
    memset( (void *) spinlock_ptr, 0, sizeof(intrspin_t) );

    InterruptLock(spinlock_ptr);
    *flags_args = (ulong)spinlock_ptr;
}

void osa_spin_unlock_irqrestore(void *lock, ulong flags)
{
    /*
     * restore interrupts
     */
    InterruptUnlock((intrspin_t *) flags);
    free((void *) flags);
}

void osa_spin_lock_create(void **lock_args, const int8 *name)
{
    /* dummy lock allocation to not to break common driver */
    uint32 **lock = (uint32 **)lock_args;

    *lock = osa_malloc(sizeof(uint32), 0);
}


void osa_spin_lock(void *lock)
{

}

int32 osa_spin_trylock(void *lock)
{
    return 0;
}

void osa_spin_unlock(void *lock)
{

}

int32 osa_spin_is_locked(void *lock)
{
    return 0;
}

void osa_spin_lock_irq(void *lock)
{

}

void osa_spin_unlock_irq(void *lock)
{

}

void osa_spin_destroy(void **lock_args)
{
    osa_free(*lock_args);
}
