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
 */
#include <semaphore.h>
#include <errno.h>
#include <time.h>

#include "../../inc/osa_define.h"
#include "../../inc/osa_types.h"
#include "../../inc/osa_semaphore.h"

void *osa_semaphore_create(enum osa_semaphore_mode mode, uint32 count)
{
    sem_t *handle;

    /* Creates a COUNTING named semaphore */
    handle = sem_open(NULL, O_ANON, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH, count);
    if (handle == SEM_FAILED)
    {
        OSA_PR_ERR("sem_open for QNX Failed - errno-%d", errno);
        return NULL;
    }

    return handle;
}

int32 osa_semaphore_delete(void *handle)
{
    OSA_WARN_ON(handle == NULL);

    int ret;

    ret = sem_close((sem_t *)handle);
    if (ret < 0) {
        OSA_PR_ERR("sem_close for QNX Failed - errno-%d", errno);
    }

    return ret;
}

int32 osa_semaphore_pend(void *handle, uint32 timeout)
{
    OSA_WARN_ON(handle == NULL);

    int ret;
    struct timespec ts;

    if (timeout == (uint32)osa_semaphore_wait_forever) {
        ret = sem_wait((sem_t *)handle);
    } else {
        uint64_t timeout_ns = (uint64_t)timeout*1000000;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        ts.tv_sec += (timeout_ns)/1000000000;
        ts.tv_nsec += timeout_ns%1000000000;

        ret = sem_timedwait_monotonic((sem_t *)handle, &ts);
    }

    return ret;
}

int32 osa_semaphore_post(void *handle)
{
    OSA_WARN_ON(handle == NULL);

    return sem_post((sem_t *)handle);
}
