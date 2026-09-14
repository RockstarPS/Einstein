/******************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2017. Visteon Corporation owns all rights to           *
 * this work and intends to maintain it in confidence to preserve             *
 * its trade secret status. Visteon Corporation reserves the right,           *
 * under the copyright laws of the United States or those of any              *
 * other country that may have jurisdiction, to protect this work             *
 * as an unpublished work, in the event of an inadvertent or                  *
 * deliberate unauthorized publication. Visteon Corporation also              *
 * reserves its rights under all copyright laws to protect this               *
 * work as a published work, when appropriate. Those having access            *
 * to this work may not copy it, use it, modify it or disclose the            *
 * information contained in it without the written authorization              *
 * of Visteon Corporation.                                                    *
 *                                                                            *
 ******************************************************************************/
/******************************************************************************
 *  File Name         :  Dlt_Cfg.c                                            *
 *  Module Short Name :  Dlt_Cfg.c                                            *
 *  Description       :  This file contains implementations of the Diagnostic *
 *                       Log and Trace Extension                              *
 *                                                                            *
 * Organization     :  Driver Information Software Section,                   *
 *                     Visteon Software Operation                             *
 *                     Visteon Corporation                                    *
 *                                                                            *
 * ---------------------------------------------------------------------------*
 * Compiler Name    :  GHS Multi                                              *
 * Target Hardware  :  Platform Independent                                   *
 *                                                                            *
 ******************************************************************************/
#ifndef DLT_CFG_C
#define DLT_CFG_C

/******************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
#include "Dlt_Cfg.h"
#include "Rte_Dlt.h"

/******************************************************************************
 *                            Configuration                                   *
 ******************************************************************************/
const tDlt_LocalConfigDataType DltConfig = 
{
    DLT_INIT,
    DLT_ACTIVE_SESSION,
    MSG_FILTER_ENABLE,
    0U
};

/* Dlt.DltConfigSet.DltLogLevelSetting */
VAR(DltLogLevelSetting_Type, Dlt_CONST) DltLogLevelSetting = 
{
    DLT_LOG_OFF,                    /* DltDefaultLogLevel*/
    DLT_LOG_OFF,                    /* DltLogLevelThreshold*/
};

VAR(DltTraceStatusAssignment_Type, Dlt_CONST) DltTraceStatusAssignment[DLT_NUM_TRACESTATUSASSIGNMENT] = 
{
    {
        FALSE,                     /* DltTraceStatus
        &DltSwcContext[DLT_CFG_INDEX_0],         /* DltTraceStatusAssignmentSwcContextRef*/
    },
};

/* Dlt.DltConfigSet.DltLogOutput */
VAR(DltTxPdu_Type, Dlt_CONST) DltTxPdu[DLT_NUM_TXPDU] =
{
    {
        DLT_TX_PDU_HANDLE_ID_30,    /* DltITxPduHandleId*/
        TRUE,                       /* DltITxPduUsesTp*/
    },
};

VAR(DltLogChannel_Type, Dlt_CONST)
DltDefaultLogChannelRef =
    {
        5.0f,                                             /* DltLogChannelBUfferOverflowTimer */
        DLT_CFG_BUF_SIZE_2048,                            /* DltLogChannelBUfferSize */
        {(uint8)'D', (uint8)'L', (uint8)'T', (uint8)'X'}, /* DltLogChannelId */
        DLT_CFG_MAX_MSG_LEN_8,                            /* DltLogChannelMaxMessageLength */
        DLT_CFG_MAX_RETRIES_3,                            /* DltLogChannelMaxNumOfRetries */
        DLT_LOG_OFF,                                      /* DltLogChannelThreshold */
        DLT_CFG_TRAFFIC_SHAPING_100,                      /* DltLogChannelTrafficShapingBandwidth */
        0.1f,                                             /* DltLogChannelTransmitCycle */
        TRUE,                                             /* DltLogTraceStatusFlag */
        &DltTxPdu[DLT_CFG_INDEX_0],                       /* DltTxPdu */
};
VAR(DltLogChannel_Type, Dlt_CONST)
DltLogChannelRef[DLT_NUM_LOGCHANNELREF] =
    {
        {
            5.0f,                                             /* DltLogChannelBUfferOverflowTimer */
            DLT_CFG_BUF_SIZE_2048,                            /* DltLogChannelBUfferSize */
            {(uint8)'D', (uint8)'L', (uint8)'T', (uint8)'X'}, /* DltLogChannelId */
            DLT_CFG_MAX_MSG_LEN_8,                            /* DltLogChannelMaxMessageLength */
            DLT_CFG_MAX_RETRIES_3,                            /* DltLogChannelMaxNumOfRetries */
            DLT_LOG_OFF,                                      /* DltLogChannelThreshold */
            DLT_CFG_TRAFFIC_SHAPING_100,                      /* DltLogChannelTrafficShapingBandwidth */
            0.1f,                                             /* DltLogChannelTransmitCycle */
            TRUE,                                             /* DltLogTraceStatusFlag */
            &DltTxPdu[DLT_CFG_INDEX_0],                       /* DltTxPdu */
        },
        {
            5.0f,                                             /* DltLogChannelBUfferOverflowTimer */
            DLT_CFG_BUF_SIZE_2048,                            /* DltLogChannelBUfferSize */
            {(uint8)'P', (uint8)'D', (uint8)'U', (uint8)'R'}, /* DltLogChannelId */
            DLT_CFG_MAX_MSG_LEN_512,                          /* DltLogChannelMaxMessageLength */
            DLT_CFG_MAX_RETRIES_3,                            /* DltLogChannelMaxNumOfRetries */
            DLT_LOG_OFF,                                      /* DltLogChannelThreshold */
            DLT_CFG_TRAFFIC_SHAPING_100,                      /* DltLogChannelTrafficShapingBandwidth */
            0.1f,                                             /* DltLogChannelTransmitCycle */
            TRUE,                                             /* DltLogTraceStatusFlag */
            &DltTxPdu[DLT_CFG_INDEX_0],                       /* DltTxPdu */
        },

};

VAR(DltLogChannelAssignment_Type, Dlt_CONST) DltLogChannelAssignment[DLT_NUM_LOGCHANNELASSIGNMENT] = 
{
    {
        &DltSwcContext[DLT_CFG_INDEX_0],          /*DltLogChannelAssignmentSwcContextRef*/
        &DltLogChannelRef[DLT_CFG_INDEX_0],       /*DltLogChannelRef*/
    },
    {
        &DltSwcContext[DLT_CFG_INDEX_1],          /*DltLogChannelAssignmentSwcContextRef*/
        &DltLogChannelRef[DLT_CFG_INDEX_0],       /*DltLogChannelRef*/
    },
    {
        &DltSwcContext[DLT_CFG_INDEX_2],          /* DltLogChannelAssignmentSwcContextRef*/
        &DltLogChannelRef[DLT_CFG_INDEX_0],       /* DltLogChannelRef*/
    },

};

/* Dlt.DltSwc.DltSwcContext */
VAR(DltSwcContext_Type, Dlt_CONST)
DltSwcContext[DLT_NUM_SWCCONTEXT] = {
    {
        {(uint8)'F', (uint8)'L', (uint8)'T', (uint8)'M'}, /* DltSwcApplicationId*/
        {(uint8)'F', (uint8)'L', (uint8)'T', (uint8)'M'}, /* DltSwcContextId*/
        DLT_LOG_OFF,                                      /* DltLogChannelThreshold*/
        FALSE,                                            /* DltLogTraceStatusFlag*/
    },
    {
        {(uint8)'R', (uint8)'S', (uint8)'T', (uint8)'M'}, /* DltSwcApplicationId*/
        {(uint8)'R', (uint8)'S', (uint8)'T', (uint8)'M'}, /* DltSwcContextId*/
        DLT_LOG_OFF,                                      /* DltLogChannelThreshold */
        FALSE,                                            /* DltLogTraceStatusFlag*/
    },
    {
        {(uint8)'R', (uint8)'S', (uint8)'T', (uint8)'M'}, /* DltSwcApplicationId*/
        {(uint8)'R', (uint8)'H', (uint8)'I', (uint8)'S'}, /* DltSwcContextId*/
        DLT_LOG_OFF,                                      /* DltLogChannelThreshold*/
        FALSE,                                            /* DltLogTraceStatusFlag*/
    },
};
/******************************************************************************
 *                            Functions                                       *
 ******************************************************************************/
Std_ReturnType PduR_DltTransmit(PduIdType TxPduId, PduInfoType PduInfoPtr)
{
    (void)TxPduId;
    (void)PduInfoPtr;
    /*TODO: Dummy - remove this function from here once available from PDUR module*/
    return DLT_E_OK;
}

/******************************************************************************
 *                            Stub Testing                                    *
 ******************************************************************************/
#if(DLT_TESTCODE_EN == STD_ON)
extern Std_ReturnType Dlt_SendLogMessage(Dlt_SessionIDType sessionId, const Dlt_MessageLogInfoType *logInfo, UInt8 *logData, UInt16 logDataLength);
extern void Dlt_TpTxConfirmation( PduIdType PduId, Std_ReturnType result );
void Dlt_testFunction(void)
{
    volatile uint8 testID = 0U;
    Dlt_SessionIDType sessionId = DLT_ACTIVE_SESSION;
    Dlt_MessageLogInfoType logInfo = {
        .argCount = 2U,
        .logLevel = DLT_LOG_INFO,
        .options = 0U,
        .appId = {(uint8)'D', (uint8)'E', (uint8)'M', DLT_CFG_INDEX_0},    /* Hex literals*/
        .contextId = {(uint8)'D', (uint8)'E', (uint8)'M', DLT_CFG_INDEX_1} /* Hex literals*/
    };
    uint8 logData[DLT_TEST_LOG_DATA_LEN] = {DLT_TEST_INIT_VAL, 3U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U};

    uint16 logDataLength = DLT_MAX_SAFE_PAYLOAD;

    if(testID == 1U)
    {
        (void)Dlt_SendLogMessage(sessionId, &logInfo, logData, logDataLength);
        testID = 0U;
    }

    if(testID == 2U)
    {
        Dlt_TpTxConfirmation(DLT_TX_PDU_HANDLE_ID_30, DLT_E_OK);
        testID = 0U;
    }
}
#endif

/*****************************************************************************
*                  EOF - End of file                                         *
******************************************************************************/
#endif /* DLT_CFG_C */

/*---------------------------------------------------------------------------------------------------
Date               : 12-Dec-2025
CDSID              : MSAVARIY
Traceability       : https://visteon.atlassian.net/browse/PE4TI29141-10843
Change Description : DltExt Updated for E4.0 platform - DLT Verbose header update for shared memory
------------------------------------------------------------------------------------------------------*/
