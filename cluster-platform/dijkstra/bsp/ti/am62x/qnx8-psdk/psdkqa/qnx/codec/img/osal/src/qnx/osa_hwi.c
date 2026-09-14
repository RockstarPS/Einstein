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
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/neutrino.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#include <ti/csl/soc.h>

#include "osa_define.h"
#include "osa_hwi.h"

typedef void (*HwiP_Fxn)(void *arg);

typedef struct
{
    uint32_t evtId;
    int chid;
    struct sigevent isr_event;
    uint32_t coreIntrNum;
    uint32_t intrPriority;
    HwiP_Fxn isrFxn;
    uint32_t irq_autoEnable;
    pthread_t      tid;
    void     *arg;
} qnx_osal_hwi_info;

#define DECODER0_IRQ  (CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_DECODER0_IRQ_0)
#define ENCODER0_IRQ  (CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_ENCODER0_IRQ_0)
#define QNX_OSAL_MAX_INTR_COUNT           (16)
#define ISR_PULSE                          _PULSE_CODE_MINAVAIL
#define PULSE_CLOSE                        (_PULSE_CODE_MINAVAIL + 1)

static qnx_osal_hwi_info      g_hwi[QNX_OSAL_MAX_INTR_COUNT];
static uint8_t                g_currIntrCount = 0;

/*
 *  ======== isr_thread ========
 */
/* Thread level ISR handler */
static void *isr_thread (void *arg)
{
    qnx_osal_hwi_info *hwi = (qnx_osal_hwi_info *)arg;
    int             rcvid;
    struct _pulse   pulse;
    uintptr_t       interruptNum;

    while (1) {
        rcvid = MsgReceivePulse(hwi->chid, &pulse, sizeof(struct _pulse), NULL);
        if (rcvid != -1) {
            OSA_PR_INFO("MsgReceivePulse pulse code=%d", pulse.code);
            switch (pulse.code) {
                case ISR_PULSE:
                    interruptNum = pulse.value.sival_int;

                    /* Call the callback function */
                    hwi->isrFxn(hwi->arg);

                    /* Check if application wants interrupt re-enabled */
                    if(hwi->irq_autoEnable == 1) {
                        /* Unmask interrupt */
                        InterruptUnmask (interruptNum, -1);
                    }
                    break;
                case PULSE_CLOSE:
                    OSA_PR_INFO("MsgReceivePulse close");
                    return NULL;
                default:
                    OSA_PR_WARN("Rx Unknown pulse %d received", pulse.code);
                    break;
            }
        }
        else {
            OSA_PR_ERR("MsgReceivePulse failed");
            delay(20);
        }
    }
    return NULL;
}

void *osa_hwi_create(void *hwi_fxn, void *arg, uint8_t hwa_id)
{
    pthread_attr_t thread_attr;
    struct sched_param  param;
    qnx_osal_hwi_info  *hwi = NULL;
    char threadName[128];
    uint32_t intrPriority;
    uint32_t interrupt_id = 0;

    switch (hwa_id) {
        case HWA_DECODER:
            interrupt_id = DECODER0_IRQ;
            break;
        case HWA_ENCODER:
            interrupt_id = ENCODER0_IRQ;
            break;
        default:
            return NULL;
    }

    /*TODO Clear out any pending interrupts */
    // NOTE: Override the interrupt priority pass as params->priority
    intrPriority = 21;

    if (g_currIntrCount >= QNX_OSAL_MAX_INTR_COUNT) {
        OSA_PR_ERR("MAXed out on the hwi structure");
        OSA_WARN_ON(1);
    }
    hwi = &g_hwi[g_currIntrCount];
    g_currIntrCount++;


    hwi->chid = ChannelCreate(0);
    if(hwi->chid == -1)
    {
        OSA_PR_ERR("Failed to create chid:%d", hwi->chid);
        OSA_WARN_ON(1);
    }

    pthread_attr_init(&thread_attr);
    pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
    param.sched_priority = intrPriority;
    pthread_attr_setschedparam(&thread_attr, &param);

    if (pthread_create(&hwi->tid, &thread_attr, (void *)isr_thread, (void *)hwi) != EOK) {
        OSA_PR_ERR("Unable to create isr thread");
        OSA_WARN_ON(1);
    }
    sprintf(threadName, "IntrThread_%d", interrupt_id);
    pthread_setname_np(hwi->tid, threadName);

    /* Store pointer to the hwi structure */
    hwi->isrFxn = hwi_fxn;
    hwi->coreIntrNum = interrupt_id;
    hwi->intrPriority = intrPriority;
    hwi->arg = arg;
    hwi->irq_autoEnable = osa_true;

    /* Init the pulse for interrupt event */
    hwi->isr_event.sigev_notify = SIGEV_PULSE;
    hwi->isr_event.sigev_code = _PULSE_CODE_MINAVAIL;
    hwi->isr_event.sigev_coid = ConnectAttach(0, 0, hwi->chid, _NTO_SIDE_CHANNEL, 0);
    hwi->isr_event.sigev_priority = intrPriority;     /* service interrupts at a higher priority then client requests */
    hwi->isr_event.sigev_value.sival_int = interrupt_id;

    /*
     * Attach interrupt handler (thread level)
     *
     * _NTO_INTR_FLAGS_TRK_MSK - Track mask/unmask
     * _NTO_INTR_FLAGS_NO_UNMASK - Start with interrupt masked
     */
    hwi->evtId = InterruptAttachEvent (interrupt_id, &hwi->isr_event,  0 /*_NTO_INTR_FLAGS_NO_UNMASK*/);
    if(hwi->evtId == -1)
    {
        OSA_PR_ERR("InterruptAttachEvent failed");
        OSA_WARN_ON(1);
    }
    else
    {
        //printf("%s: InterruptAttachEvent succeed irq/%d\n",__FUNCTION__, interrupt_id);
    }

    return hwi;
}

int32 osa_hwi_delete(void *handle)
{
    qnx_osal_hwi_info  *hwi = (qnx_osal_hwi_info *)handle;
    if(MsgSendPulse(hwi->chid, -1, PULSE_CLOSE, 0) == -1)
        pthread_join(hwi->tid, NULL);
    return 0;
}
