/*
 *  Copyright (c) Texas Instruments Incorporated 2024
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 *  \file ipc_soc.c
 *
 *  \brief File containing the IPC driver - soc specific implementation.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <CddIpc/ipc_baremetal_hw/ipc.h>
#include <CddIpc/ipc_baremetal_hw/src/ipc_mailbox.h>

#if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2) || defined (SOC_J784S4) || defined (SOC_J742S2)
#include <ti/drv/sciclient/sciclient.h>
#endif

/**
 * \ Dependencies from pdk Sciclient
 */



#define NAVSS_INTRTR_INPUT_MAILBOX0_USER0   (436U)
#define NAVSS_INTRTR_INPUT_MAILBOX1_USER0   (432U)
#define NAVSS_INTRTR_INPUT_MAILBOX2_USER0   (428U)
#define NAVSS_INTRTR_INPUT_MAILBOX3_USER0   (424U)
#define NAVSS_INTRTR_INPUT_MAILBOX4_USER0   (420U)
#define NAVSS_INTRTR_INPUT_MAILBOX5_USER0   (416U)
#define NAVSS_INTRTR_INPUT_MAILBOX6_USER0   (412U)
#define NAVSS_INTRTR_INPUT_MAILBOX7_USER0   (408U)
#define NAVSS_INTRTR_INPUT_MAILBOX8_USER0   (404U)
#define NAVSS_INTRTR_INPUT_MAILBOX9_USER0   (400U)
#define NAVSS_INTRTR_INPUT_MAILBOX10_USER0  (396U)
#define NAVSS_INTRTR_INPUT_MAILBOX11_USER0  (392U)

#define CDD_IPC_START_SEC_VAR_INIT_32
#include "Cdd_Ipc_MemMap.h"

/**
 * \brief Main NavSS512 - Mailbox input line
 */


uint32 g_Navss512MbInput[IPC_MAILBOX_CLUSTER_CNT] =
{
    #if defined (SOC_AM62X)
    NAVSS_INTRTR_INPUT_MAILBOX0_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX1_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX2_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX3_USER0
    #endif
    #if defined (SOC_AM62AX) || defined(SOC_AM62DX) || defined (SOC_AM62PX)
    NAVSS_INTRTR_INPUT_MAILBOX0_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX1_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX2_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX3_USER0
    #endif
    #if defined (SOC_J722S)
    NAVSS_INTRTR_INPUT_MAILBOX0_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX1_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX2_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX3_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX4_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX5_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX6_USER0
    #endif
    #if defined(SOC_AM275X) 
    NAVSS_INTRTR_INPUT_MAILBOX0_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX1_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX2_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX3_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX4_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX5_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX6_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX7_USER0
    #endif
    #if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2) || defined (SOC_J784S4) || defined (SOC_J742S2)
    NAVSS_INTRTR_INPUT_MAILBOX0_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX1_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX2_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX3_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX4_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX5_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX6_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX7_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX8_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX9_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX10_USER0,
    NAVSS_INTRTR_INPUT_MAILBOX11_USER0
    #endif
};

#define CDD_IPC_STOP_SEC_VAR_INIT_32
#include "Cdd_Ipc_MemMap.h"

#define CDD_IPC_START_SEC_CODE
#include "Cdd_Ipc_MemMap.h"

uint32 Ipc_getNavss512MailboxInputIntr(uint32 clusterId, uint32 userId);
sint32 Ipc_setCoreEventId(uint32 selfId, Ipc_MbConfig* cfg, uint32 intrCnt);
sint32 Ipc_sciclientIrqTranslate(uint16 coreId, uint32 eventId,
        uint16 *procIrq);

sint32 Ipc_getMailboxInfoTx(uint32 selfId, uint32 remoteId,
                 uint32 *clusterId, uint32 *userId, uint32 *queueId)
{
    sint32 retVal = -1;

    /**
    * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic coverage for the "false condition" branch cannot be covered as SelfId and RemoteId are fixed enums which cannot be changed.

    * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
    */
    if( (selfId < IPC_MAX_PROCS) &&
        (remoteId < IPC_MAX_PROCS))
    /* TI_COVERAGE_GAP_STOP */
    {
        Ipc_MailboxInfo   *pMailboxInfo = &g_IPC_MailboxInfo[selfId][remoteId];

        *clusterId = pMailboxInfo->tx.cluster;
        *userId    = pMailboxInfo->tx.user;
        *queueId   = pMailboxInfo->tx.fifo;
        retVal = 0;
    }

    return retVal;
}

sint32 Ipc_getMailboxInfoRx(uint32 selfId, uint32 remoteId,
                 uint32 *clusterId, uint32 *userId, uint32 *queueId)
{
    sint32 retVal = -1;

    /** 
    * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic coverage for the "false condition" branch elfId and RemoteId are fixed enums which cannot be changed.

    * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
    */
    if( (selfId < IPC_MAX_PROCS) &&
        (remoteId < IPC_MAX_PROCS))
    /* TI_COVERAGE_GAP_STOP */
    {

        Ipc_MailboxInfo   *pMailboxInfo = &g_IPC_MailboxInfo[selfId][remoteId];

        *clusterId = pMailboxInfo->rx.cluster;
        *userId    = pMailboxInfo->rx.user;
        *queueId   = pMailboxInfo->rx.fifo;
        retVal = 0;
    }

    return retVal;

}

uint32 Ipc_getMailboxBaseAddr(uint32 clusterId)
{
    uint32 baseAddr = 0x00000000U;

    if( clusterId < IPC_MAILBOX_CLUSTER_CNT)
    {
        baseAddr = IPC_Mailbox_BasePhyAddr[clusterId];
    }

    return baseAddr;
}

const sint8* Ipc_getCoreName(uint32 procId)
{
    sint8*     p = (sint8*)0;
    uint32 id = procId;

    /**
     * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage for the
     * function Ipc_getCoreName() is not achievable because procId is always within
     * valid range (0 to IPC_MAX_PROCS-1) in existing test configurations, so the
     * error-path else branch (returning NULL) is not exercised.
     *
     * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
     */
    if(id < IPC_MAX_PROCS)
    {
       p = (sint8 *)g_Ipc_mp_procInfo[id].name;
    }
    /* TI_COVERAGE_GAP_STOP */
    return p;
}

/**
* TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage for Ipc_getNavss512MailboxInputIntr is internally called by Ipc_getMailboxIntrRouterCfg - This API is used in ETH driver, so it will be covered in ETH LDRA
- MCAL-9188(JIRA task)

* TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
*/
uint32 Ipc_getNavss512MailboxInputIntr(uint32 clusterId, uint32 userId)
{
    uint32  mailboxIntrNum = 0U;


    if( (clusterId != MAILBOX_CLUSTER_INVALID) &&
        (clusterId < IPC_MAILBOX_CLUSTER_CNT)  &&
        (userId != MAILBOX_USER_INVALID)       &&
        (userId < IPC_MAILBOX_USER_CNT))
    
    {
        mailboxIntrNum = g_Navss512MbInput[clusterId] + userId;
    }
    return mailboxIntrNum;
}
/* TI_COVERAGE_GAP_STOP */

#define CDD_IPC_STOP_SEC_CODE
#include "Cdd_Ipc_MemMap.h"




