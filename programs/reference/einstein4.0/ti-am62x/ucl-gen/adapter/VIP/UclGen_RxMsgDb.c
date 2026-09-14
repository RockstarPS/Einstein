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
// Date: Wed Sep 17 12:27:28 IST 2025
// User: SSRINI28
// Gateway: UCL_GW
// Configuration: Platform
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.10
//
//---------------------------------------------------------------------------------------------------------------------

#include <Ucl_Types.h>
#include <UclILMsgDb_Types.h>
#include "UclGen_AsrAdapter.h"


//---------------------------------------------------------------------------------------
// Data Units list for message deployment: UclPowerDomainStateMsg
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclPowerDomainStateMsg_DataUnits_Size    1u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclPowerDomainStateMsg_DataUnits[MsgDeployment_UclPowerDomainStateMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = PowerSystemState_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = PowerSystemState_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_PowerSystemState    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclPowerDomainStateMsg_Work;    // Status of message deployment: UclPowerDomainStateMsg

//---------------------------------------------------------------------------------------
// Data Units list for message deployment: UclPowerDomainReqMsg
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclPowerDomainReqMsg_DataUnits_Size    2u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclPowerDomainReqMsg_DataUnits[MsgDeployment_UclPowerDomainReqMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = PowerExtendShutdownTime_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = PowerExtendShutdownTime_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_PowerExtendShutdownTime    ///< Adapter Function for Received DataUnits (Message Based)
    },
    {
        .dataUnitId = PowerKeepSystemAwake_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = PowerKeepSystemAwake_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_PowerKeepSystemAwake    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclPowerDomainReqMsg_Work;    // Status of message deployment: UclPowerDomainReqMsg

//---------------------------------------------------------------------------------------
// Data Units list for message deployment: UclHealthHeartBeatMsg
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclHealthHeartBeatMsg_DataUnits_Size    1u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclHealthHeartBeatMsg_DataUnits[MsgDeployment_UclHealthHeartBeatMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = HealthDomainHeartbeat_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = HealthDomainHeartbeat_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_HealthDomainHeartbeat    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclHealthHeartBeatMsg_Work;    // Status of message deployment: UclHealthHeartBeatMsg

//---------------------------------------------------------------------------------------
// Data Units list for message deployment: UclHealthErrorMsg
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclHealthErrorMsg_DataUnits_Size    1u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclHealthErrorMsg_DataUnits[MsgDeployment_UclHealthErrorMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = HealthDomainFatalError_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = HealthDomainFatalError_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_HealthDomainFatalError    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclHealthErrorMsg_Work;    // Status of message deployment: UclHealthErrorMsg

//---------------------------------------------------------------------------------------
// Data Units list for message deployment: UclHealthEeventMsg
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclHealthEeventMsg_DataUnits_Size    1u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclHealthEeventMsg_DataUnits[MsgDeployment_UclHealthEeventMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = HealthEventRecord_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = HealthEventRecord_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_HealthEventRecord    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclHealthEeventMsg_Work;    // Status of message deployment: UclHealthEeventMsg

//---------------------------------------------------------------------------------------
// Data Units list for message deployment: UclHealthDumpDataMsg
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclHealthDumpDataMsg_DataUnits_Size    2u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclHealthDumpDataMsg_DataUnits[MsgDeployment_UclHealthDumpDataMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = HealthDumpHdrInfo_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = HealthDumpHdrInfo_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_HealthDumpHdrInfo    ///< Adapter Function for Received DataUnits (Message Based)
    },
    {
        .dataUnitId = HealthDumpData_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = HealthDumpData_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_HealthDumpData    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclHealthDumpDataMsg_Work;    // Status of message deployment: UclHealthDumpDataMsg

//---------------------------------------------------------------------------------------
// Data Units list for message deployment: UclDisplayCurrentState
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclDisplayCurrentState_DataUnits_Size    1u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclDisplayCurrentState_DataUnits[MsgDeployment_UclDisplayCurrentState_DataUnits_Size]  =
{
    {
        .dataUnitId = DisplayCurrentState_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = DisplayCurrentState_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_DisplayCurrentState    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclDisplayCurrentState_Work;    // Status of message deployment: UclDisplayCurrentState

//---------------------------------------------------------------------------------------
// Data Units list for message deployment: UclEmmcErrorNotifierMsg
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclEmmcErrorNotifierMsg_DataUnits_Size    1u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclEmmcErrorNotifierMsg_DataUnits[MsgDeployment_UclEmmcErrorNotifierMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = EmmcErrorNotifier_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = EmmcErrorNotifier_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_EmmcErrorNotifier    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclEmmcErrorNotifierMsg_Work;    // Status of message deployment: UclEmmcErrorNotifierMsg

//---------------------------------------------------------------------------------------
// Data Units list for message deployment: UclWarningStatusMsg
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclWarningStatusMsg_DataUnits_Size    2u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclWarningStatusMsg_DataUnits[MsgDeployment_UclWarningStatusMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = WarningDisplayAvailable_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = WarningDisplayAvailable_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_WarningDisplayAvailable    ///< Adapter Function for Received DataUnits (Message Based)
    },
    {
        .dataUnitId = WarningStatus_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = WarningStatus_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_WarningStatus    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclWarningStatusMsg_Work;    // Status of message deployment: UclWarningStatusMsg

//---------------------------------------------------------------------------------------
// Data Units list for message deployment: UclSubSystemStatus
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclSubSystemStatus_DataUnits_Size    2u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclSubSystemStatus_DataUnits[MsgDeployment_UclSubSystemStatus_DataUnits_Size]  =
{
    {
        .dataUnitId = SafeHMIReadyStatus_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = SafeHMIReadyStatus_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_SafeHMIReadyStatus    ///< Adapter Function for Received DataUnits (Message Based)
    },
    {
        .dataUnitId = MainHMIReadyStatus_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = MainHMIReadyStatus_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_MainHMIReadyStatus    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclSubSystemStatus_Work;    // Status of message deployment: UclSubSystemStatus

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
// Data Units list for message deployment: UclDiagResponse
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclDiagResponse_DataUnits_Size    1u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclDiagResponse_DataUnits[MsgDeployment_UclDiagResponse_DataUnits_Size]  =
{
    {
        .dataUnitId = DiagResponse_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = DiagResponse_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_DiagResponse    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclDiagResponse_Work;    // Status of message deployment: UclDiagResponse

//---------------------------------------------------------------------------------------
// Data Units list for message deployment: UclDLTMessageReadAck
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclDLTMessageReadAck_DataUnits_Size    1u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclDLTMessageReadAck_DataUnits[MsgDeployment_UclDLTMessageReadAck_DataUnits_Size]  =
{
    {
        .dataUnitId = DLTMessageReadAck_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = DLTMessageReadAck_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_DLTMessageReadAck    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclDLTMessageReadAck_Work;    // Status of message deployment: UclDLTMessageReadAck

//---------------------------------------------------------------------------------------
// Data Units list for message deployment: UclDLTControlMessageRequest
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclDLTControlMessageRequest_DataUnits_Size    1u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclDLTControlMessageRequest_DataUnits[MsgDeployment_UclDLTControlMessageRequest_DataUnits_Size]  =
{
    {
        .dataUnitId = DLTControlMessageRequest_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = DLTControlMessageRequest_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_DLTControlMessageRequest    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclDLTControlMessageRequest_Work;    // Status of message deployment: UclDLTControlMessageRequest


//---------------------------------------------------------------------------------------
// Receive DB
//---------------------------------------------------------------------------------------
const SUclILMsgDbRx UclILMsgDbRx[UclILMsgDbRx_Size] = 
{
    {
        .msgId = UclPowerDomainStateMsg_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclPowerDomainStateMsg_Work,
        .numDataUnits = MsgDeployment_UclPowerDomainStateMsg_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclPowerDomainStateMsg_DataUnits
    },
    {
        .msgId = UclPowerDomainReqMsg_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclPowerDomainReqMsg_Work,
        .numDataUnits = MsgDeployment_UclPowerDomainReqMsg_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclPowerDomainReqMsg_DataUnits
    },
    {
        .msgId = UclHealthHeartBeatMsg_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclHealthHeartBeatMsg_Work,
        .numDataUnits = MsgDeployment_UclHealthHeartBeatMsg_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclHealthHeartBeatMsg_DataUnits
    },
    {
        .msgId = UclHealthErrorMsg_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclHealthErrorMsg_Work,
        .numDataUnits = MsgDeployment_UclHealthErrorMsg_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclHealthErrorMsg_DataUnits
    },
    {
        .msgId = UclHealthEeventMsg_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclHealthEeventMsg_Work,
        .numDataUnits = MsgDeployment_UclHealthEeventMsg_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclHealthEeventMsg_DataUnits
    },
    {
        .msgId = UclHealthDumpDataMsg_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclHealthDumpDataMsg_Work,
        .numDataUnits = MsgDeployment_UclHealthDumpDataMsg_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclHealthDumpDataMsg_DataUnits
    },
    {
        .msgId = UclDisplayCurrentState_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclDisplayCurrentState_Work,
        .numDataUnits = MsgDeployment_UclDisplayCurrentState_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclDisplayCurrentState_DataUnits
    },
    {
        .msgId = UclEmmcErrorNotifierMsg_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclEmmcErrorNotifierMsg_Work,
        .numDataUnits = MsgDeployment_UclEmmcErrorNotifierMsg_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclEmmcErrorNotifierMsg_DataUnits
    },
    {
        .msgId = UclWarningStatusMsg_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclWarningStatusMsg_Work,
        .numDataUnits = MsgDeployment_UclWarningStatusMsg_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclWarningStatusMsg_DataUnits
    },
    {
        .msgId = UclSubSystemStatus_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclSubSystemStatus_Work,
        .numDataUnits = MsgDeployment_UclSubSystemStatus_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclSubSystemStatus_DataUnits
    },
    {
        .msgId = UpdateShortServiceResp_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UpdateShortServiceResp_Work,
        .numDataUnits = MsgDeployment_UpdateShortServiceResp_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UpdateShortServiceResp_DataUnits
    },
    {
        .msgId = UclDiagResponse_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclDiagResponse_Work,
        .numDataUnits = MsgDeployment_UclDiagResponse_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclDiagResponse_DataUnits
    },
    {
        .msgId = UclDLTMessageReadAck_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclDLTMessageReadAck_Work,
        .numDataUnits = MsgDeployment_UclDLTMessageReadAck_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclDLTMessageReadAck_DataUnits
    },
    {
        .msgId = UclDLTControlMessageRequest_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclDLTControlMessageRequest_Work,
        .numDataUnits = MsgDeployment_UclDLTControlMessageRequest_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclDLTControlMessageRequest_DataUnits
    }
};

