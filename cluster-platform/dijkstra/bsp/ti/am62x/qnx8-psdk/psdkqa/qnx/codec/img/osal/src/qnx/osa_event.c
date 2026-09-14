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
 * osa delay functions implementation for QNX
 */

#include <pthread.h>
#include <sys/time.h>

#include "../../inc/osa_define.h"
#include "../../inc/osa_event.h"
#include "../../inc/osa_mem.h"
#include "../../inc/osa_string.h"
#include "img_errors.h"


/*!
 ******************************************************************************
 Event object structure
 ******************************************************************************/
struct osa_event
{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
};

int32 osa_create_event_obj(void ** event)
{
    int32 ret = 0;
    struct osa_event * p_event;

    /* Allocate a Sync structure...*/
    p_event = osa_malloc(sizeof(*p_event), OSA_GFP_KERNEL);
    IMG_DBG_ASSERT(p_event != NULL);
    if (p_event == NULL)
        return ENOMEM;

    osa_memset(p_event, 0, sizeof(*p_event));

    if ( (ret = pthread_mutex_init( &p_event->mutex, NULL)) != 0 ) {
        OSA_PR_ERR("%s pthread_mutex_init failed!",__func__);
        osa_free(p_event);
        return ret;
    }

    pthread_condattr_t attr;
    if ( (ret = pthread_condattr_init(&attr)) != 0) {
        osa_free(p_event);
        return ret;
    }
    if ( (ret = pthread_condattr_setclock(&attr, CLOCK_MONOTONIC)) != 0) {
        osa_free(p_event);
        return ret;
    }

    if ( (ret = pthread_cond_init( &p_event->cond, &attr)) != 0 ) {
        OSA_PR_ERR("%s pthread_cond_init failed!",__func__);
        osa_free(p_event);
        return ret;
    }
    pthread_condattr_destroy(&attr);
    /* Return the event structure...*/
    *event = (void *)p_event;

    return EOK;
}

void osa_destroy_event_obj(void * event)
{
    struct osa_event * p_event = (struct osa_event *)event;

    IMG_DBG_ASSERT(event != NULL);
    if (event == NULL)
        return;

    pthread_mutex_destroy(&p_event->mutex);
    pthread_cond_destroy(&p_event->cond);
    /* Free structure...*/
    osa_free(p_event);
}

int32 osa_wait_event_obj(void *event, osa_bool uninterruptible, uint32 timeout)
{
    struct osa_event *p_event = (struct osa_event *)event;

    IMG_DBG_ASSERT(event != NULL);
    if (event == NULL)
        return EINVAL;

    if (timeout == (uint32)(-1)) {
        pthread_mutex_lock(&p_event->mutex);
        pthread_cond_wait(&p_event->cond, &p_event->mutex);
        pthread_mutex_unlock(&p_event->mutex);
    }
    else {
        struct timespec to;
        clock_gettime(CLOCK_MONOTONIC, &to );
        nsec2timespec(&to, timespec2nsec( &to ) + timeout * 1000000);
        pthread_mutex_lock(&p_event->mutex);
        pthread_cond_timedwait(&p_event->cond, &p_event->mutex, &to);
        pthread_mutex_unlock(&p_event->mutex);
    }

    return IMG_SUCCESS;
}

void osa_signal_event_obj(void *event)
{
    struct osa_event *p_event = (struct osa_event *)event;

    IMG_DBG_ASSERT(event != NULL);
    if (event == NULL)
        return;

    pthread_mutex_lock(&p_event->mutex);
    pthread_cond_signal(&p_event->cond);
    pthread_mutex_unlock(&p_event->mutex);
}
