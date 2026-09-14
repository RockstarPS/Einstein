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
///
///---------------------------------------------------------------------------------------------------------------------
/// @file
/// @ingroup UclTest
/// UCL Test Implementation to test UclDL_Impl. APIs in this file are not to called directly by the users
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLTEST_UCLDL_IMPL_H
#define UCLTEST_UCLDL_IMPL_H

#include "UclTest_Types.h"
#include "UclDLCbk_Types.h"

typedef struct SUclTestUclDLInst_t SUclTestUclDLInst;

typedef struct SUclTestUclDLClient_t
{
    uint32 txPassCnt;
    uint32 txFailCnt;
    uint32 txAckPassCnt;
    uint32 txAckFailCnt;
    uint16 txMsgId;
    uint16 txMsgLen;
    uint16 txWaitForAck;
} SUclTestUclDLClient;

typedef struct SUclTestUclDLCfg_t
{
    uint16 txMsgIdStart;
    uint16 txMsgMaxLen;
    uint8 txMsgClientPerIteration;
    uint8 maxTestClients;
    uint8 *pTestData;
    SUclTestUclDLClient *pTestClients; ///< Test Clients Array
} SUclTestUclDLCfg;

///
/// @brief Private instance data for UclTest_UclDL_Impl. \n
/// @ingroup UclTest
///
/// The SUclTestUclDLInst structure defines the private instance data for UclTest_UclDL_Impl class.
///
struct SUclTestUclDLInst_t
{
    uint8 numIUclDL;
    uint8 *pIUclDL;

    uint8 testRunning;
    uint8 lastClientIdx;
    uint32 testTimerId;
    const SUclTestUclDLCfg *pCfg; ///< Configuration for the UclDL_Impl instance
};

//Implementation for provided port IUclTest
void UclTestUclDL_Impl_IUclTest_Initialize(SUclTestUclDLInst *pInst, uint8 InstId);
void UclTestUclDL_Impl_IUclTest_Shutdown(SUclTestUclDLInst *pInst, uint8 InstId);
void UclTestUclDL_Impl_IUclTest_Start(SUclTestUclDLInst *pInst, uint8 InstId);
void UclTestUclDL_Impl_IUclTest_Stop(SUclTestUclDLInst *pInst, uint8 InstId);

//Implementation for provided port IUclDLCbk
void UclTestUclDL_Impl_IUclDLCbk_FatalError(SUclTestUclDLInst *pInst, uint8 InstId, uint8 Status);
void UclTestUclDL_Impl_IUclDLCbk_MsgReceived(SUclTestUclDLInst *pInst, uint8 InstId, EUclDLRxStatus Status,
                                             SUclDLMsg *pMsg);
void UclTestUclDL_Impl_IUclDLCbk_MsgTransmitStatus(SUclTestUclDLInst *pInst, uint8 InstId, uint16 MsgId,
                                                   EUclDLAckStatus Status);
void UclTestUclDL_Impl_IUclDLCbk_LinkStatusChanged(SUclTestUclDLInst *pInst, uint8 InstId, EUclDLLinkStatus Status);

#endif //UCLTEST_UCLDL_IMPL_H
