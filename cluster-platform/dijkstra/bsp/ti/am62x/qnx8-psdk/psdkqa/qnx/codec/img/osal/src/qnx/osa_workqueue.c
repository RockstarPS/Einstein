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
 * osa work queue handling for QNX
 */
#include <time.h>
#include <sys/neutrino.h>
#include <pthread.h>
#include <sys/netmgr.h>

#include "../../inc/osa_workqueue.h"
#include "../../inc/osa_mem.h"
#include "../../inc/osa_define.h"
#include "../../inc/osa_queue.h"
#include "../../inc/osa_semaphore.h"
#include "../../inc/osa_time.h"
#include "vxd_dec.h"
#include "vxe_enc.h"
#include "topaz_device.h"
#include "topaz_api.h"

#define TIMERS_PULSE_CODE _PULSE_CODE_MINAVAIL
#define TIMERS_PULSE_CLOSE (_PULSE_CODE_MINAVAIL + 1)
#define INVALID_TIMER_ID  (-1)
#define TIMERS_SIGEV_PRIORITY (21)

enum osa_timer_status_e
{
    osa_timerp_idle,
    osa_timerp_start
};

typedef void *(timer_callback)(void *arg);

typedef struct qnx_timer_s {
    pthread_t thread; /** Timer thread */

    timer_t timeid; /** Timer ID */
    struct sigevent ev; /** Sig event */
    int chid; /** Channel ID */
    int connectionid;

    timer_callback *callback;
    void *cb_arg;
} qnx_timer_t;

void osa_timer_isr(void *arg)
{
    struct work_struct *work = (struct work_struct *)arg;

    osa_mutex_lock(work->lock);
    osa_utils_queput(work->queue_handle, work, osa_semaphore_no_wait);
    work->timer_status = osa_timerp_idle;
    osa_mutex_unlock(work->lock);
}

static void *timer_pulses_thread(void *arg)
{
    qnx_timer_t *qnx_timer = (qnx_timer_t *)arg;
    struct _pulse pulse;
    int ret;

    pthread_setname_np(pthread_self(),"workqueue timer thread");

    if(ThreadCtl( _NTO_TCTL_IO_LEVEL, (void*)_NTO_IO_LEVEL_1 ) == -1) {
        OSA_PR_ERR("%s: Failed to set _NTO_TCTL_IO_LEVEL!", __func__);
    }
    struct sched_param params;
    params.sched_priority = TIMERS_SIGEV_PRIORITY;

    /* Attempt to set real-time priority */
    ret = pthread_setschedparam(pthread_self(), SCHED_FIFO, &params);
    if (ret != 0) {
        OSA_PR_ERR("pthread_setschedparam fail with %d", ret);
    }

    do {
        ret = MsgReceive_r(qnx_timer->chid, &pulse, sizeof(pulse), NULL);

        if ( ret == 0 ) {
            if(pulse.code == TIMERS_PULSE_CODE)
                qnx_timer->callback(qnx_timer->cb_arg);
            else if(pulse.code == TIMERS_PULSE_CLOSE)
                break;
        }
        else {
            OSA_PR_ERR("timer_pulses_thread Error ret %d", ret);
            break;
        }
    } while (1);

    pthread_exit((void*) arg);
}

static void *osa_create_timer(void *timer_isr, void *arg)
{
    qnx_timer_t *qnx_timer = calloc(sizeof(*qnx_timer), 1);
    if (!qnx_timer) {
        OSA_PR_ERR("%s: calloc out of memory ", __func__);
        return NULL;
    }

    qnx_timer->chid = ChannelCreate(_NTO_CHF_PRIVATE);
    if (qnx_timer->chid == -1) {
        OSA_PR_ERR("%s ChannelCreate failed", __func__);
        free(qnx_timer);
        return NULL;
    }
    qnx_timer->connectionid = ConnectAttach(ND_LOCAL_NODE, 0,
            qnx_timer->chid, _NTO_SIDE_CHANNEL, 0);
    if (qnx_timer->connectionid == -1) {
        OSA_PR_ERR("%s: ConnectAttach failed", __func__);
        goto destroy_channel;
    }


    SIGEV_PULSE_INIT(&qnx_timer->ev, qnx_timer->connectionid, TIMERS_SIGEV_PRIORITY,
            TIMERS_PULSE_CODE, 0);

    int ret = timer_create(CLOCK_MONOTONIC, &qnx_timer->ev, &qnx_timer->timeid);
    if (ret) {
        OSA_PR_ERR("%s: timer_create failed", __func__);
        qnx_timer->timeid = INVALID_TIMER_ID;
        goto detach_conn;
    }

    qnx_timer->callback = timer_isr;
    qnx_timer->cb_arg = arg;

    ret = pthread_create(&qnx_timer->thread,
            NULL, timer_pulses_thread, qnx_timer);
    if (ret) {
        OSA_PR_ERR("%s ERROR; pthread_create failed with %d code", __func__, ret);
        goto delete_timer;
    }

    return qnx_timer;

delete_timer:
    timer_delete(qnx_timer->timeid);
detach_conn:
    ConnectDetach(qnx_timer->connectionid);
destroy_channel:
    ChannelDestroy(qnx_timer->chid);
    free(qnx_timer);
    return NULL;
}

static int osa_set_timer(qnx_timer_t *timer, uint64 delay_ms)
{
    int ret;
    struct itimerspec time_spec;

    if(timer->timeid == INVALID_TIMER_ID) {
        ret = timer_create(CLOCK_MONOTONIC, &timer->ev, &timer->timeid);
        if (ret) {
            OSA_PR_ERR("%s: timer_create failed", __func__);
            return ret;
        }
    }

    memset(&time_spec, 0, sizeof(time_spec));
    time_spec.it_value.tv_sec = delay_ms / 1000;
    time_spec.it_value.tv_nsec = (delay_ms % 1000) * 1000000;

    ret = timer_settime(timer->timeid, 0, &time_spec, NULL);
    if (ret) {
        OSA_PR_ERR("osa_set_timer timer_settime error(%d)", ret);
    }

    return ret;
}

static void osa_cancel_timer(qnx_timer_t *timer)
{
    if(timer->timeid != INVALID_TIMER_ID) {
        timer_delete(timer->timeid);
        timer->timeid = INVALID_TIMER_ID;
    }
}

void osa_free_timer(qnx_timer_t *timer)
{
    int ret;

    if (!timer) {
        return;
    }

    if( (ret = MsgSendPulse(timer->ev.sigev_coid, -1, TIMERS_PULSE_CLOSE, 0)) == -1) {
        OSA_PR_ERR("%s MsgSendPulse failed with %d",__func__, ret);
    }
    ret = pthread_join(timer->thread, NULL);
    if (ret) {
        OSA_PR_ERR("%s pthread_join failed with %d", __func__, ret);
    }

    ret = ConnectDetach(timer->ev.sigev_coid);
    if (ret) {
        OSA_PR_ERR("%s: ConnectDetach failed", __func__);
    }

    ret = ChannelDestroy(timer->chid);
    if (ret) {
        OSA_PR_ERR("%s: ChannelDestroy failed", __func__);
    }

    if (timer->timeid != INVALID_TIMER_ID) {
        timer_delete(timer->timeid);
    }

    free(timer);
}


void osa_init_work(void **work_args, void *work_fn, uint8_t hwa_id)
{
    struct work_struct **work = (struct work_struct **)work_args;
    *work = osa_calloc(1, sizeof(struct work_struct), 0);
    if(NULL == *work) {
        OSA_PR_ERR("%s : Memory allocation failed for work_queue\n", __func__);
        return;
    }

    switch (hwa_id) {
        case HWA_DECODER:
            {
                struct vxd_dec_ctx *ctx = NULL;
                ctx = osa_container_of(work, struct vxd_dec_ctx, work);

                (*work)->worker_func = (void (*)( void *))work_fn;
                (*work)->work = work_args;
                (*work)->work_complete = FALSE;
                (*work)->queue_handle = ctx->stream_worker_queue_handle;
                (*work)->workq_sem_handle = ctx->stream_worker_queue_sem_handle;
                (*work)->lock = ctx->lock;
            }
            break;

        case HWA_ENCODER:
            {
                struct topaz_stream_context *str_ctx = NULL;
                struct img_comm_socket *sock;
                sock = osa_container_of(work, struct img_comm_socket, work);

                str_ctx = sock->str_ctx;

                (*work)->worker_func = (void (*)( void *))work_fn;
                (*work)->work = work_args;
                (*work)->work_complete = FALSE;
                (*work)->queue_handle = str_ctx->vxe_ctx->stream_worker_queue_handle;
                (*work)->workq_sem_handle = str_ctx->vxe_ctx->stream_worker_queue_sem_handle;
                (*work)->lock = str_ctx->vxe_ctx->mutex;
            }
            break;

        default:
            return;
    }
    return;
}

void osa_init_delayed_work(void **work_args, void *work_fn, uint8_t hwa_id)
{
    struct work_struct **work = (struct work_struct **)work_args;
    *work = osa_calloc(1, sizeof(struct work_struct), 0);
    if(NULL == *work) {
        OSA_PR_ERR("%s : ERR Memory allocation failed for delayed work_queue\n", __func__);
        return;
    }

    switch (hwa_id) {
        case HWA_DECODER:
            {
                struct vxd_dev *vxd = NULL;

                vxd = osa_container_of(work, struct vxd_dev, dwork);

                (*work)->worker_func = (void (*)( void *))work_fn;
                (*work)->work = work;
                (*work)->work_complete = FALSE;
                (*work)->queue_handle = vxd->vxd_worker_queue_handle;
                (*work)->workq_sem_handle = vxd->vxd_worker_queue_sem_handle;
                (*work)->timer_handle = osa_create_timer(osa_timer_isr, *work);
                (*work)->timer_status = osa_timerp_idle;
                (*work)->lock = vxd->mutex;
            }
            break;

        case HWA_ENCODER:
            //to be implemented. Not required right now.
            break;

        default:
            return;
    }
    return;
}

int32 osa_schedule_work(void *work_args)
{
    struct work_struct *work = (struct work_struct *)work_args;

    osa_utils_queput(work->queue_handle, work, (uint32)osa_semaphore_wait_forever);

    return 0;
}

int32 osa_schedule_delayed_work(void *dwork, uint64 delay)
{
    int32 ret = 0;
    struct work_struct *work = (struct work_struct *)dwork;

    if(osa_timerp_idle == work->timer_status)
    {
        work->timer_status = osa_timerp_start;
        ret = osa_false;
    }
    else
    {
        ret = osa_true;
    }
    osa_set_timer((qnx_timer_t *)work->timer_handle, delay);
    return ret;
}

int32 osa_flush_work(void *work_args)
{
    struct work_struct *work = NULL;

    work = osa_malloc(sizeof(struct work_struct), 0);
    if(NULL != work)
    {
        memcpy(work, work_args, sizeof(struct work_struct));
        work->work_complete = TRUE;
        osa_utils_queput(work->queue_handle, work, (uint32)osa_semaphore_wait_forever);
        osa_semaphore_pend(work->workq_sem_handle, osa_semaphore_wait_forever);
    }

    return 0;
}

int32 osa_cancel_delayed_work_sync(void *dwork)
{
    struct work_struct *work = NULL;

    work = osa_malloc(sizeof(struct work_struct), 0);
    if(NULL != work)
    {
        memcpy(work, dwork, sizeof(struct work_struct));
        if(work->timer_handle) {
            osa_free_timer((qnx_timer_t*)work->timer_handle);
            work->timer_handle = NULL;
        }
        osa_utils_quereset(work->queue_handle);
        work->work_complete = TRUE;
        osa_utils_queput(work->queue_handle, work, (uint32)osa_semaphore_wait_forever);
    }
    return 0;
}

int32 osa_cancel_delayed_work(void *dwork)
{
    struct work_struct *work = (struct work_struct *)dwork;

    osa_utils_quereset(work->queue_handle);
    if(work->timer_handle) {
        osa_cancel_timer((qnx_timer_t*)work->timer_handle);
    }
    work->timer_status = osa_timerp_idle;
    return 0;
}

int32 osa_mod_delayed_work(void*wq, void *dwork, uint64 delay)
{
    int32 ret;
    struct work_struct *work = (struct work_struct *)dwork;

    ret = osa_set_timer((qnx_timer_t *)work->timer_handle, delay);
    if (ret) {
        OSA_PR_ERR("%s : ERR Coult not start the timer \n", __func__);
        return osa_false;
    }
    return osa_true;
}

void *osa_get_global_workqueue_struct(void)
{
    /* Dummy implementation for QNX */
    return NULL;
}

void *osa_get_work_buff(void *key, int8 flag)
{
    return key;
}

void *osa_get_delayed_work_buff(void *key, int8 flag)
{
    return key;
}
