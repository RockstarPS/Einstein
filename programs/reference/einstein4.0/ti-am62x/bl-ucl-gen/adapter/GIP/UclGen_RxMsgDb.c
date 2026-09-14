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
#include "UclGen_VmfAdapter.h"


//---------------------------------------------------------------------------------------
// Data Units list for message deployment: UpdateShortServiceReq
//---------------------------------------------------------------------------------------
#define MsgDeployment_UpdateShortServiceReq_DataUnits_Size    1u
static const SUclILMsgDbRxDataUnit MsgDeployment_UpdateShortServiceReq_DataUnits[MsgDeployment_UpdateShortServiceReq_DataUnits_Size]  =
{
    {
        .dataUnitId = UpdateShortServiceReq_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = UpdateShortServiceReq_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_UpdateShortServiceReq    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UpdateShortServiceReq_Work;    // Status of message deployment: UpdateShortServiceReq

//---------------------------------------------------------------------------------------
// Data Units list for message deployment: UpdateLongServiceReq
//---------------------------------------------------------------------------------------
#define MsgDeployment_UpdateLongServiceReq_DataUnits_Size    1u
static const SUclILMsgDbRxDataUnit MsgDeployment_UpdateLongServiceReq_DataUnits[MsgDeployment_UpdateLongServiceReq_DataUnits_Size]  =
{
    {
        .dataUnitId = UpdateLongServiceReq_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = UpdateLongServiceReq_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_UpdateLongServiceReq    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UpdateLongServiceReq_Work;    // Status of message deployment: UpdateLongServiceReq


//---------------------------------------------------------------------------------------
// Receive DB
//---------------------------------------------------------------------------------------
const SUclILMsgDbRx UclILMsgDbRx[UclILMsgDbRx_Size] = 
{
    {
        .msgId = UpdateShortServiceReq_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UpdateShortServiceReq_Work,
        .numDataUnits = MsgDeployment_UpdateShortServiceReq_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UpdateShortServiceReq_DataUnits
    },
    {
        .msgId = UpdateLongServiceReq_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UpdateLongServiceReq_Work,
        .numDataUnits = MsgDeployment_UpdateLongServiceReq_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UpdateLongServiceReq_DataUnits
    }
};

