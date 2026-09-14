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
// Data Units list for message deployment: UpdateShortServiceResp
//---------------------------------------------------------------------------------------
#define MsgDeployment_UpdateShortServiceResp_DataUnits_Size    1u
static const SUclILMsgDbRxDataUnit MsgDeployment_UpdateShortServiceResp_DataUnits[MsgDeployment_UpdateShortServiceResp_DataUnits_Size]  =
{
    {
        .dataUnitId = UpdateShortServiceResp_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = UpdateShortServiceResp_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_UpdateShortServiceResp    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UpdateShortServiceResp_Work;    // Status of message deployment: UpdateShortServiceResp


//---------------------------------------------------------------------------------------
// Receive DB
//---------------------------------------------------------------------------------------
const SUclILMsgDbRx UclILMsgDbRx[UclILMsgDbRx_Size] = 
{
    {
        .msgId = UpdateShortServiceResp_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UpdateShortServiceResp_Work,
        .numDataUnits = MsgDeployment_UpdateShortServiceResp_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UpdateShortServiceResp_DataUnits
    }
};

