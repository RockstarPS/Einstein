///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2017] Visteon Corporation
/// All Rights Reserved.
///
/// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
/// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
/// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
/// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
/// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
/// under all copyright laws to protect this work as a published work, when appropriate.
/// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
/// without the written authorization of Visteon Corporation.
///---------------------------------------------------------------------------------------------------------------------
#include "UclTestUclDL_Impl.h"
#include "UclALOs.h"
#include "UclDL.h"

static void *UclTestUclDL_Impl_TimerTask(void *pData);

//Implementation for provided port IUclTest
void UclTestUclDL_Impl_IUclTest_Initialize(SUclTestUclDLInst *pInst, uint8 InstId)
{
    SUclTestUclDLCfg *pCfg = (SUclTestUclDLCfg *)pInst->pCfg;
    uint16 it;

    for (it = 0u; it < pCfg->txMsgMaxLen; it++)
    {
        pCfg->pTestData[it] = 0xA5;
    }

    for (it = 0u; it < pCfg->maxTestClients; it++)
    {
        pCfg->pTestClients[it].txMsgId = pCfg->txMsgIdStart + it;
        pCfg->pTestClients[it].txMsgLen = 64u;
        pCfg->pTestClients[it].txPassCnt = 0u;
        pCfg->pTestClients[it].txFailCnt = 0u;
        pCfg->pTestClients[it].txAckPassCnt = 0u;
        pCfg->pTestClients[it].txAckFailCnt = 0u;
        pCfg->pTestClients[it].txWaitForAck = 0u;
    }

    pInst->testRunning = FALSE;
    pInst->lastClientIdx = 0;

    (void)UclALOs_TimerCreate(0, &pInst->testTimerId, UclTestUclDL_Impl_TimerTask, (void *)pInst,
                              eUclOsTimerType_Periodic);
}

void UclTestUclDL_Impl_IUclTest_Shutdown(SUclTestUclDLInst *pInst, uint8 InstId)
{
    pInst->testRunning = FALSE;
}

void UclTestUclDL_Impl_IUclTest_Start(SUclTestUclDLInst *pInst, uint8 InstId)
{
    if (FALSE == pInst->testRunning)
    {
        (void)UclALOs_TimerStart(0, pInst->testTimerId, 16);

        pInst->testRunning = TRUE;
    }
}

void UclTestUclDL_Impl_IUclTest_Stop(SUclTestUclDLInst *pInst, uint8 InstId)
{
    (void)UclALOs_TimerStop(0, pInst->testTimerId);

    pInst->testRunning = FALSE;
}

//Implementation for provided port IUclDLCbk
void UclTestUclDL_Impl_IUclDLCbk_FatalError(SUclTestUclDLInst *pInst, uint8 InstId, uint8 Status)
{
}

void UclTestUclDL_Impl_IUclDLCbk_MsgReceived(SUclTestUclDLInst *pInst, uint8 InstId, EUclDLRxStatus Status,
                                             SUclDLMsg *pMsg)
{
}

void UclTestUclDL_Impl_IUclDLCbk_MsgTransmitStatus(SUclTestUclDLInst *pInst, uint8 InstId, uint16 MsgId,
                                                   EUclDLAckStatus Status)
{
    SUclTestUclDLCfg *pCfg = (SUclTestUclDLCfg *)pInst->pCfg;
    uint16 it;

    if (pCfg->txMsgIdStart == (MsgId & pCfg->txMsgIdStart))
    {
        for (it = 0u; it < pCfg->maxTestClients; it++)
        {
            if ((MsgId == pCfg->pTestClients[it].txMsgId) && (TRUE == pCfg->pTestClients[it].txWaitForAck))
            {
                pCfg->pTestClients[it].txWaitForAck = FALSE;

                if (eUclDLAckStatus_Ok == Status)
                {
                    pCfg->pTestClients[it].txAckPassCnt++;
                }
                else
                {
                    pCfg->pTestClients[it].txAckFailCnt++;
                }
            }
        }
    }
}

void UclTestUclDL_Impl_IUclDLCbk_LinkStatusChanged(SUclTestUclDLInst *pInst, uint8 InstId, EUclDLLinkStatus Status)
{
}

static void *UclTestUclDL_Impl_TimerTask(void *pData)
{
    SUclTestUclDLInst *pInst = (SUclTestUclDLInst *)pData;
    SUclTestUclDLCfg *pCfg = (SUclTestUclDLCfg *)pInst->pCfg;
    Ucl_ReturnType Ret;
    uint16 it;

    if (TRUE == pInst->testRunning)
    {
        for (it = 0u; it < pCfg->txMsgClientPerIteration; it++)
        {
            if (FALSE == pCfg->pTestClients[pInst->lastClientIdx].txWaitForAck)
            {
                SUclDLMsg Msg;
                Msg.MsgHdr = 0;
                Msg.MsgId = pCfg->pTestClients[pInst->lastClientIdx].txMsgId;
                Msg.pPayload = pCfg->pTestData;
                Msg.Size = pCfg->pTestClients[pInst->lastClientIdx].txMsgLen;

                Ret = UclDL_Send(0, &Msg);

                if (UCL_E_OK == Ret)
                {
                    pCfg->pTestClients[pInst->lastClientIdx].txPassCnt++;
                    pCfg->pTestClients[pInst->lastClientIdx].txWaitForAck = TRUE;
                }
                else
                {
                    pCfg->pTestClients[pInst->lastClientIdx].txFailCnt++;
                }
            }

            pInst->lastClientIdx++;

            if (pInst->lastClientIdx == pCfg->maxTestClients)
            {
                pInst->lastClientIdx = 0u;
            }
        }
    }

    return NULL;
}
