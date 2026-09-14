//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2022] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
//
// File generated automatically using Visteon DiCore UCL configuration generator 1.3.3
// Date: Tue Oct 01 15:54:36 IST 2024
// User: KRAMESH5
// Gateway: UCL_GW
// Configuration: Platform_Recovery
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.2
//
//---------------------------------------------------------------------------------------------------------------------

#include <Ucl_Types.h>
#include <UclILMsgDb_Types.h>
#include "UclGen_AsrAdapter.h"


//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 1
//---------------------------------------------------------------------------------------
#define MsgDeployment_UpdateShortServiceReq_DataUnits_Size    1u
static const SUclILMsgDbTxDataUnit MsgDeployment_UpdateShortServiceReq_DataUnits[MsgDeployment_UpdateShortServiceReq_DataUnits_Size]  =
{
    {
        .dataUnitId = UpdateShortServiceReq_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_UpdateShortServiceReq,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = UpdateShortServiceReq_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UpdateShortServiceReq_Work;    // Status of message deployment ID: 1

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 2
//---------------------------------------------------------------------------------------
#define MsgDeployment_UpdateLongServiceReq_DataUnits_Size    1u
static const SUclILMsgDbTxDataUnit MsgDeployment_UpdateLongServiceReq_DataUnits[MsgDeployment_UpdateLongServiceReq_DataUnits_Size]  =
{
    {
        .dataUnitId = UpdateLongServiceReq_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_UpdateLongServiceReq,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = UpdateLongServiceReq_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UpdateLongServiceReq_Work;    // Status of message deployment ID: 2


//---------------------------------------------------------------------------------------
// Transmit DB
//---------------------------------------------------------------------------------------
const SUclILMsgDbTx UclILMsgDbTx[UclILMsgDbTx_Size] = 
{
    {
        .msgId = UpdateShortServiceReq_DID,
        .destNodeId = 1u,
        .periodictyMs = 10u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_Low,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnWrite,
        .notifyTxStatus = FALSE,
        .sendOnInit = FALSE,
        .pWork = &MsgDeployment_UpdateShortServiceReq_Work,
        .pDataUnitList = MsgDeployment_UpdateShortServiceReq_DataUnits,
        .numDataUnits = MsgDeployment_UpdateShortServiceReq_DataUnits_Size
    },
    {
        .msgId = UpdateLongServiceReq_DID,
        .destNodeId = 1u,
        .periodictyMs = 10u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_Low,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnWrite,
        .notifyTxStatus = FALSE,
        .sendOnInit = FALSE,
        .pWork = &MsgDeployment_UpdateLongServiceReq_Work,
        .pDataUnitList = MsgDeployment_UpdateLongServiceReq_DataUnits,
        .numDataUnits = MsgDeployment_UpdateLongServiceReq_DataUnits_Size
    }
};

