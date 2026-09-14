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
 * osa time handling functions implementation for QNX
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

#include <string.h>

#include "../../inc/osa_semaphore.h"
#include "../../inc/osa_queue.h"
#include "../../inc/osa_define.h"
#include "../../inc/osa_interrupt.h"

#if defined (DEBUG_DECODER_DRIVER) || defined (DEBUG_ENCODER_DRIVER)
#define QUEUE_ASSERT(x)  { if((x) == 0){ \
            OSA_PR_ERR(" Assertion @ Line: %d in %s: failed !!!\n",\
                __LINE__, __FILE__);\
                while(1); }}
#else
#define QUEUE_ASSERT(x)  { if((x) == 0){ \
            OSA_PR_ERR(" Assertion @ Line: %d in %s: failed !!!\n",\
                __LINE__, __FILE__); }}
#endif

void osa_utils_quecreate(osa_utils_quehandle *handle,
              uint32 maxElements, void *queueMem, uint32 flags)
{
    /* init handle to 0's */
    memset(handle, 0, sizeof(osa_utils_quehandle));

    /* init handle with user parameters */
    handle->maxElements = maxElements;
    handle->flags = flags;

    /* queue data element memory cannot be NULL */
    QUEUE_ASSERT(queueMem != NULL);

    handle->queue = queueMem;

    if (handle->flags & OSA_UTILS_QUE_FLAG_BLOCK_QUE_GET) {
        /* user requested block on que get */

        /* create semaphore for it */
        handle->semRd = osa_semaphore_create(osa_semaphore_mode_binary, (uint32)0);
        QUEUE_ASSERT(handle->semRd != NULL);
    }

    if (handle->flags & OSA_UTILS_QUE_FLAG_BLOCK_QUE_PUT) {
        /* user requested block on que put */

        /* create semaphore for it */
        handle->semWr = osa_semaphore_create(osa_semaphore_mode_binary, (uint32)0);
        QUEUE_ASSERT(handle->semWr != NULL);
    }
    handle->blockedOnGet = (osa_bool)FALSE;
    handle->blockedOnPut = (osa_bool)FALSE;
    handle->forceUnblockGet = (osa_bool)FALSE;
    handle->forceUnblockPut = (osa_bool)FALSE;

    return;
}

int32 osa_utils_quedelete(osa_utils_quehandle *handle)
{
    if (handle->flags & OSA_UTILS_QUE_FLAG_BLOCK_QUE_GET)
    {
        /* user requested block on que get */

        /* delete associated semaphore */
        osa_semaphore_delete(handle->semRd);

    }
    if (handle->flags & OSA_UTILS_QUE_FLAG_BLOCK_QUE_PUT)
    {
        /* user requested block on que put */

        /* delete associated semaphore */
        osa_semaphore_delete(handle->semWr);
    }

    return OSA_STATUS_SOK;
}

int32 osa_utils_queput(osa_utils_quehandle *handle, void *data, uint32 timeout)
{
    int32 status = OSA_STATUS_EFAIL;
    ulong cookie;
    volatile osa_bool doBreak = FALSE;

    if ((uint32) osa_semaphore_wait_forever == timeout)
        timeout = osa_semaphore_wait_forever;
    else if ((uint32) osa_semaphore_no_wait == timeout)
        timeout = osa_semaphore_no_wait;

    do
    {
        /* disable interrupts */
        osa_local_irq_disable(&cookie);

        if (handle->count < handle->maxElements) {
            /* free space available in que */

            /* MISRA.PTR.ARITH
             * MISRAC_2004_Rule_11.1
             * MISRAC_WAIVER:
             * Pointer is accessed as an array.
             * Queue user always allocates queue of size maxElements, queue
             * will not be accessed out of bound.
             */
            /* insert element */
            handle->queue[handle->curWr] = data;

            /* increment put pointer */
            handle->curWr = (handle->curWr + 1) % handle->maxElements;

            /* increment count of number element in que */
            handle->count++;

            /* restore interrupts */
            osa_local_irq_enable(cookie);

            /* mark status as success */
            status = OSA_STATUS_SOK;

            if (handle->flags & OSA_UTILS_QUE_FLAG_BLOCK_QUE_GET) {
                /* blocking on que get enabled */

                /* post semaphore to unblock, blocked tasks */
                osa_semaphore_post(handle->semRd);
            }

            /* exit, with success */
            doBreak = (osa_bool)TRUE;
        }
        else {
            /* que is full */

            /* restore interrupts */
            osa_local_irq_enable(cookie);

            if (timeout == osa_semaphore_no_wait) {
                doBreak = (osa_bool)TRUE; /* non-blocking
                               * function call,
                               * exit with error
                               */
            }
            else if (handle->flags & OSA_UTILS_QUE_FLAG_BLOCK_QUE_PUT) {
                osa_bool semPendStatus;

                /* blocking on que put enabled */

                /*
                 * take semaphore and block until timeout occurs or
                 * semaphore is posted
                 */
                handle->blockedOnPut = (osa_bool)TRUE;
                semPendStatus = osa_semaphore_pend(handle->semWr, timeout);
                handle->blockedOnPut = (osa_bool)FALSE;
                if (semPendStatus) {
                    /* UNREACH.GEN :  MISRAC_2004_Rule_14.1
                     * Unreachable Code
                     * MISRAC_WAIVER:
                     * Value in the if condition is dependent on the
                     * return of a function osa_semaphore_pend and
                     * this function is implemented when OS BIOS is
                     * included/defined.
                     */
                    handle->forceUnblockPut = (osa_bool)FALSE;
                    doBreak = (osa_bool)TRUE; /* timeout
                                   * happend, exit
                                   * with error */
                }
                else if (handle->forceUnblockPut) {
                    handle->forceUnblockPut = (osa_bool)FALSE;
                    doBreak = (osa_bool)TRUE; /* timeout
                                   * happend, exit
                                   * with error */
                }
                else {
                    doBreak = (osa_bool)FALSE;
                }
                /*
                 * received semaphore, recheck for available
                 * space in the que
                 */
            }
            else {
                /* blocking on que put disabled */

                /* exit with error */
                doBreak = (osa_bool)TRUE;
            }
        }

        if ((osa_bool)TRUE == doBreak) {
            break;
        }
    } while (1);

    return status;
}

int32 osa_utils_queget(osa_utils_quehandle *handle, void **data,
               uint32 minCount, uint32 timeout)
{
    int32 status = OSA_STATUS_EFAIL; /* init status to error */
    ulong cookie;
    volatile osa_bool doBreak = (osa_bool)FALSE;

    /* adjust minCount between 1 and handle->maxElements */
    if (0U == minCount)
        minCount = 1U;

    if (minCount > handle->maxElements)
        minCount = handle->maxElements;

    do
    {
        /* disable interrupts */
        osa_local_irq_disable(&cookie);

        if (handle->count >= minCount) {
            /*
             * data elements available in que is >=
             * minimum data elements requested by user
             */

            /* extract the element */
            *data = handle->queue[handle->curRd];

            /* increment get pointer */
            handle->curRd = (handle->curRd + 1) % handle->maxElements;

            /* decrmeent number of elements in que */
            handle->count--;

            /* restore interrupts */
            osa_local_irq_enable(cookie);

            /* set status as success */
            status = OSA_STATUS_SOK;

            if (handle->flags & OSA_UTILS_QUE_FLAG_BLOCK_QUE_PUT) {
                /* blocking on que put enabled */
                if ((handle->count + 1U) == handle->maxElements) {
                    /* post semaphore to unblock, blocked tasks */
                    osa_semaphore_post(handle->semWr);
                }
            }

            /* exit with success */
            doBreak = (osa_bool)TRUE;
        }
        else {
            /*
             * no elements or not enough element (minCount) in que
             * to extract
             */

            /* restore interrupts */
            osa_local_irq_enable(cookie);

            if (timeout == osa_semaphore_no_wait) {
                doBreak = (osa_bool)TRUE; /* non-blocking
                               * function call,
                               * exit with error
                               */
                status = OSA_STATUS_EFAIL;
            }
            else if (handle->flags & OSA_UTILS_QUE_FLAG_BLOCK_QUE_GET) {
                osa_bool semPendStatus;

                /* blocking on que get enabled */

                /*
                 * take semaphore and block until timeout occurs or
                 * semaphore is posted
                 */

                handle->blockedOnGet = (osa_bool)TRUE;
                semPendStatus = osa_semaphore_pend(handle->semRd, timeout);
                handle->blockedOnGet = (osa_bool)FALSE;
                if (semPendStatus) {
                    /* UNREACH.GEN :  MISRAC_2004_Rule_14.1
                     * Unreachable Code
                     * MISRAC_WAIVER:
                     * Value in the if condition is dependent on the
                     * return of a function osa_semaphore_pend and
                     * this function is implemented when OS BIOS is
                     * included/defined.
                     */
                    handle->forceUnblockGet = (osa_bool)FALSE;
                    doBreak = (osa_bool)TRUE; /* timeout
                                   * happened, exit
                                   * with error */
                    status = OSA_STATUS_ETIMEOUT;
                }
                else if (handle->forceUnblockGet == (osa_bool)TRUE) {
                    handle->forceUnblockGet = (osa_bool)FALSE;
                    doBreak = (osa_bool)TRUE; /* timeout
                                   * happened, exit
                                   * with error */
                    status = OSA_STATUS_ETIMEOUT;
                }
                else {
                    doBreak = (osa_bool)FALSE;
                }
                /* received semaphore, check que again */
            }
            else {
                /* blocking on que get disabled */

                /* exit with error */
                doBreak = (osa_bool)TRUE;
            }
            }

        if ((osa_bool)TRUE == doBreak) {
            break;
        }
    }
    while (1);

    return status;
}

int32 osa_utils_quereset(osa_utils_quehandle *handle)
{
    ulong cookie;
    int32 status = OSA_STATUS_SOK;

    /* disable interrupts */
    osa_local_irq_disable(&cookie);

    /* Reset the queue */
    handle->count = 0;
    handle->curRd = 0;
    handle->curWr = 0;
    handle->blockedOnGet = (osa_bool)FALSE;
    handle->blockedOnPut = (osa_bool)FALSE;
    handle->forceUnblockGet = (osa_bool)FALSE;
    handle->forceUnblockPut = (osa_bool)FALSE;

    /* restore interrupts */
    osa_local_irq_enable(cookie);

    return status;
}


uint32 osa_utils_queisempty(const osa_utils_quehandle * handle)
{
    uint32 isEmpty;
    ulong cookie;

    /* disable interrupts */
    osa_local_irq_disable(&cookie);

    /* check if que is empty */
    if (handle->count)
        isEmpty = (uint32)FALSE;
    else
        isEmpty = (uint32)TRUE;

    /* restore interrupts */
    osa_local_irq_enable(cookie);

    return isEmpty;
}
