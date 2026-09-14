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
#include "UclGen_VmfAdapter.h"


//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 1
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclPowerDomainStateMsg_DataUnits_Size    1u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclPowerDomainStateMsg_DataUnits[MsgDeployment_UclPowerDomainStateMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = PowerSystemState_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_PowerSystemState,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = PowerSystemState_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclPowerDomainStateMsg_Work;    // Status of message deployment ID: 1

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 2
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclPowerDomainReqMsg_DataUnits_Size    2u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclPowerDomainReqMsg_DataUnits[MsgDeployment_UclPowerDomainReqMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = PowerExtendShutdownTime_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_PowerExtendShutdownTime,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = PowerExtendShutdownTime_BufferSize    ///< Buffer Size (Message Based)
    },
    {
        .dataUnitId = PowerKeepSystemAwake_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_PowerKeepSystemAwake,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = PowerKeepSystemAwake_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclPowerDomainReqMsg_Work;    // Status of message deployment ID: 2

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 3
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclHealthHeartBeatMsg_DataUnits_Size    1u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclHealthHeartBeatMsg_DataUnits[MsgDeployment_UclHealthHeartBeatMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = HealthDomainHeartbeat_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_HealthDomainHeartbeat,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = HealthDomainHeartbeat_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclHealthHeartBeatMsg_Work;    // Status of message deployment ID: 3

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 4
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclHealthErrorMsg_DataUnits_Size    1u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclHealthErrorMsg_DataUnits[MsgDeployment_UclHealthErrorMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = HealthDomainFatalError_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_HealthDomainFatalError,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = HealthDomainFatalError_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclHealthErrorMsg_Work;    // Status of message deployment ID: 4

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 5
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclHealthEeventMsg_DataUnits_Size    1u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclHealthEeventMsg_DataUnits[MsgDeployment_UclHealthEeventMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = HealthEventRecord_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_HealthEventRecord,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = HealthEventRecord_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclHealthEeventMsg_Work;    // Status of message deployment ID: 5

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 6
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclHealthDumpDataMsg_DataUnits_Size    2u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclHealthDumpDataMsg_DataUnits[MsgDeployment_UclHealthDumpDataMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = HealthDumpHdrInfo_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_HealthDumpHdrInfo,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = HealthDumpHdrInfo_BufferSize    ///< Buffer Size (Message Based)
    },
    {
        .dataUnitId = HealthDumpData_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_HealthDumpData,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = HealthDumpData_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclHealthDumpDataMsg_Work;    // Status of message deployment ID: 6

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 7
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclDisplayCurrentState_DataUnits_Size    1u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclDisplayCurrentState_DataUnits[MsgDeployment_UclDisplayCurrentState_DataUnits_Size]  =
{
    {
        .dataUnitId = DisplayCurrentState_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_DisplayCurrentState,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = DisplayCurrentState_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclDisplayCurrentState_Work;    // Status of message deployment ID: 7

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 8
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclEmmcErrorNotifierMsg_DataUnits_Size    1u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclEmmcErrorNotifierMsg_DataUnits[MsgDeployment_UclEmmcErrorNotifierMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = EmmcErrorNotifier_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_EmmcErrorNotifier,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = EmmcErrorNotifier_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclEmmcErrorNotifierMsg_Work;    // Status of message deployment ID: 8

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 9
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclWarningStatusMsg_DataUnits_Size    2u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclWarningStatusMsg_DataUnits[MsgDeployment_UclWarningStatusMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = WarningDisplayAvailable_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_WarningDisplayAvailable,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = WarningDisplayAvailable_BufferSize    ///< Buffer Size (Message Based)
    },
    {
        .dataUnitId = WarningStatus_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_WarningStatus,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = WarningStatus_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclWarningStatusMsg_Work;    // Status of message deployment ID: 9

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 10
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclSubSystemStatus_DataUnits_Size    2u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclSubSystemStatus_DataUnits[MsgDeployment_UclSubSystemStatus_DataUnits_Size]  =
{
    {
        .dataUnitId = SafeHMIReadyStatus_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_SafeHMIReadyStatus,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = SafeHMIReadyStatus_BufferSize    ///< Buffer Size (Message Based)
    },
    {
        .dataUnitId = MainHMIReadyStatus_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_MainHMIReadyStatus,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = MainHMIReadyStatus_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclSubSystemStatus_Work;    // Status of message deployment ID: 10

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 11
//---------------------------------------------------------------------------------------
#define MsgDeployment_UpdateShortServiceResp_DataUnits_Size    1u
static const SUclILMsgDbTxDataUnit MsgDeployment_UpdateShortServiceResp_DataUnits[MsgDeployment_UpdateShortServiceResp_DataUnits_Size]  =
{
    {
        .dataUnitId = UpdateShortServiceResp_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_UpdateShortServiceResp,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = UpdateShortServiceResp_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UpdateShortServiceResp_Work;    // Status of message deployment ID: 11

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 12
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclDiagResponse_DataUnits_Size    1u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclDiagResponse_DataUnits[MsgDeployment_UclDiagResponse_DataUnits_Size]  =
{
    {
        .dataUnitId = DiagResponse_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_DiagResponse,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = DiagResponse_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclDiagResponse_Work;    // Status of message deployment ID: 12

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 13
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclDLTMessageReadAck_DataUnits_Size    1u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclDLTMessageReadAck_DataUnits[MsgDeployment_UclDLTMessageReadAck_DataUnits_Size]  =
{
    {
        .dataUnitId = DLTMessageReadAck_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_DLTMessageReadAck,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = DLTMessageReadAck_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclDLTMessageReadAck_Work;    // Status of message deployment ID: 13

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 14
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclDLTControlMessageRequest_DataUnits_Size    1u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclDLTControlMessageRequest_DataUnits[MsgDeployment_UclDLTControlMessageRequest_DataUnits_Size]  =
{
    {
        .dataUnitId = DLTControlMessageRequest_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_DLTControlMessageRequest,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = DLTControlMessageRequest_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclDLTControlMessageRequest_Work;    // Status of message deployment ID: 14


//---------------------------------------------------------------------------------------
// Transmit DB
//---------------------------------------------------------------------------------------
const SUclILMsgDbTx UclILMsgDbTx[UclILMsgDbTx_Size] = 
{
    {
        .msgId = UclPowerDomainStateMsg_DID,
        .destNodeId = 0u,
        .periodictyMs = 100u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_High,
        .schedAttrib = eUclILMsgDbSchedAttrib_Periodic,
        .notifyTxStatus = FALSE,
        .pWork = &MsgDeployment_UclPowerDomainStateMsg_Work,
        .pDataUnitList = MsgDeployment_UclPowerDomainStateMsg_DataUnits,
        .numDataUnits = MsgDeployment_UclPowerDomainStateMsg_DataUnits_Size
    },
    {
        .msgId = UclPowerDomainReqMsg_DID,
        .destNodeId = 0u,
        .periodictyMs = 30u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_High,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnWrite,
        .notifyTxStatus = TRUE,
        .pWork = &MsgDeployment_UclPowerDomainReqMsg_Work,
        .pDataUnitList = MsgDeployment_UclPowerDomainReqMsg_DataUnits,
        .numDataUnits = MsgDeployment_UclPowerDomainReqMsg_DataUnits_Size
    },
    {
        .msgId = UclHealthHeartBeatMsg_DID,
        .destNodeId = 0u,
        .periodictyMs = 40u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_Critical,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnWrite,
        .notifyTxStatus = TRUE,
        .pWork = &MsgDeployment_UclHealthHeartBeatMsg_Work,
        .pDataUnitList = MsgDeployment_UclHealthHeartBeatMsg_DataUnits,
        .numDataUnits = MsgDeployment_UclHealthHeartBeatMsg_DataUnits_Size
    },
    {
        .msgId = UclHealthErrorMsg_DID,
        .destNodeId = 0u,
        .periodictyMs = 30u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_Low,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnWrite,
        .notifyTxStatus = TRUE,
        .pWork = &MsgDeployment_UclHealthErrorMsg_Work,
        .pDataUnitList = MsgDeployment_UclHealthErrorMsg_DataUnits,
        .numDataUnits = MsgDeployment_UclHealthErrorMsg_DataUnits_Size
    },
    {
        .msgId = UclHealthEeventMsg_DID,
        .destNodeId = 0u,
        .periodictyMs = 30u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_Medium,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnWrite,
        .notifyTxStatus = TRUE,
        .pWork = &MsgDeployment_UclHealthEeventMsg_Work,
        .pDataUnitList = MsgDeployment_UclHealthEeventMsg_DataUnits,
        .numDataUnits = MsgDeployment_UclHealthEeventMsg_DataUnits_Size
    },
    {
        .msgId = UclHealthDumpDataMsg_DID,
        .destNodeId = 0u,
        .periodictyMs = 30u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_Low,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnWrite,
        .notifyTxStatus = TRUE,
        .pWork = &MsgDeployment_UclHealthDumpDataMsg_Work,
        .pDataUnitList = MsgDeployment_UclHealthDumpDataMsg_DataUnits,
        .numDataUnits = MsgDeployment_UclHealthDumpDataMsg_DataUnits_Size
    },
    {
        .msgId = UclDisplayCurrentState_DID,
        .destNodeId = 0u,
        .periodictyMs = 30u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_Critical,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnWrite,
        .notifyTxStatus = FALSE,
        .pWork = &MsgDeployment_UclDisplayCurrentState_Work,
        .pDataUnitList = MsgDeployment_UclDisplayCurrentState_DataUnits,
        .numDataUnits = MsgDeployment_UclDisplayCurrentState_DataUnits_Size
    },
    {
        .msgId = UclEmmcErrorNotifierMsg_DID,
        .destNodeId = 0u,
        .periodictyMs = 30u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_Medium,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnWrite,
        .notifyTxStatus = FALSE,
        .pWork = &MsgDeployment_UclEmmcErrorNotifierMsg_Work,
        .pDataUnitList = MsgDeployment_UclEmmcErrorNotifierMsg_DataUnits,
        .numDataUnits = MsgDeployment_UclEmmcErrorNotifierMsg_DataUnits_Size
    },
    {
        .msgId = UclWarningStatusMsg_DID,
        .destNodeId = 0u,
        .periodictyMs = 30u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_Medium,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnWrite,
        .notifyTxStatus = FALSE,
        .pWork = &MsgDeployment_UclWarningStatusMsg_Work,
        .pDataUnitList = MsgDeployment_UclWarningStatusMsg_DataUnits,
        .numDataUnits = MsgDeployment_UclWarningStatusMsg_DataUnits_Size
    },
    {
        .msgId = UclSubSystemStatus_DID,
        .destNodeId = 0u,
        .periodictyMs = 20u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_Medium,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnWrite,
        .notifyTxStatus = TRUE,
        .pWork = &MsgDeployment_UclSubSystemStatus_Work,
        .pDataUnitList = MsgDeployment_UclSubSystemStatus_DataUnits,
        .numDataUnits = MsgDeployment_UclSubSystemStatus_DataUnits_Size
    },
    {
        .msgId = UpdateShortServiceResp_DID,
        .destNodeId = 0u,
        .periodictyMs = 10u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_Low,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnWrite,
        .notifyTxStatus = TRUE,
        .pWork = &MsgDeployment_UpdateShortServiceResp_Work,
        .pDataUnitList = MsgDeployment_UpdateShortServiceResp_DataUnits,
        .numDataUnits = MsgDeployment_UpdateShortServiceResp_DataUnits_Size
    },
    {
        .msgId = UclDiagResponse_DID,
        .destNodeId = 0u,
        .periodictyMs = 100u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_Low,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnWrite,
        .notifyTxStatus = TRUE,
        .pWork = &MsgDeployment_UclDiagResponse_Work,
        .pDataUnitList = MsgDeployment_UclDiagResponse_DataUnits,
        .numDataUnits = MsgDeployment_UclDiagResponse_DataUnits_Size
    },
    {
        .msgId = UclDLTMessageReadAck_DID,
        .destNodeId = 0u,
        .periodictyMs = 20u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_Medium,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnWrite,
        .notifyTxStatus = FALSE,
        .sendOnInit = FALSE,
        .pWork = &MsgDeployment_UclDLTMessageReadAck_Work,
        .pDataUnitList = MsgDeployment_UclDLTMessageReadAck_DataUnits,
        .numDataUnits = MsgDeployment_UclDLTMessageReadAck_DataUnits_Size
    },
    {
        .msgId = UclDLTControlMessageRequest_DID,
        .destNodeId = 0u,
        .periodictyMs = 20u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_Medium,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnWrite,
        .notifyTxStatus = FALSE,
        .sendOnInit = FALSE,
        .pWork = &MsgDeployment_UclDLTControlMessageRequest_Work,
        .pDataUnitList = MsgDeployment_UclDLTControlMessageRequest_DataUnits,
        .numDataUnits = MsgDeployment_UclDLTControlMessageRequest_DataUnits_Size
    }
};

