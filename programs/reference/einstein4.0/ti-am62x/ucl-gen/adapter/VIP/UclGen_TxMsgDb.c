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
// Data Units list for message deployment ID: 1
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclPowerDomainStateReqMsg_DataUnits_Size    1u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclPowerDomainStateReqMsg_DataUnits[MsgDeployment_UclPowerDomainStateReqMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = PowerSystemStateReqChange_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_PowerSystemStateReqChange,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = PowerSystemStateReqChange_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclPowerDomainStateReqMsg_Work;    // Status of message deployment ID: 1

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 2
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclHealthDumpGetMsg_DataUnits_Size    2u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclHealthDumpGetMsg_DataUnits[MsgDeployment_UclHealthDumpGetMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = HealthDumpGetHdr_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_HealthDumpGetHdr,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = HealthDumpGetHdr_BufferSize    ///< Buffer Size (Message Based)
    },
    {
        .dataUnitId = HealthDumpGetData_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_HealthDumpGetData,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = HealthDumpGetData_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclHealthDumpGetMsg_Work;    // Status of message deployment ID: 2

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 3
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclDisplaySetPower_DataUnits_Size    1u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclDisplaySetPower_DataUnits[MsgDeployment_UclDisplaySetPower_DataUnits_Size]  =
{
    {
        .dataUnitId = DisplaySetPower_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_DisplaySetPower,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = DisplaySetPower_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclDisplaySetPower_Work;    // Status of message deployment ID: 3

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 4
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclTelltaleStatusMsg_DataUnits_Size    5u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclTelltaleStatusMsg_DataUnits[MsgDeployment_UclTelltaleStatusMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = TT_Status_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_TT_Status,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = TT_Status_BufferSize    ///< Buffer Size (Message Based)
    },
    {
        .dataUnitId = RTT_Toggle_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_RTT_Toggle,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = RTT_Toggle_BufferSize    ///< Buffer Size (Message Based)
    },
    {
        .dataUnitId = FRTT_Status_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_FRTT_Status,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = FRTT_Status_BufferSize    ///< Buffer Size (Message Based)
    },
    {
        .dataUnitId = RTT_Icon_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_RTT_Icon,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = RTT_Icon_BufferSize    ///< Buffer Size (Message Based)
    },
    {
        .dataUnitId = RTT_Status_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_RTT_Status,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = RTT_Status_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclTelltaleStatusMsg_Work;    // Status of message deployment ID: 4

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 5
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclWarningDisplayMsg_DataUnits_Size    2u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclWarningDisplayMsg_DataUnits[MsgDeployment_UclWarningDisplayMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = WarningExtDisplay_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_WarningExtDisplay,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = WarningExtDisplay_BufferSize    ///< Buffer Size (Message Based)
    },
    {
        .dataUnitId = WarningDisplay_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_WarningDisplay,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = WarningDisplay_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclWarningDisplayMsg_Work;    // Status of message deployment ID: 5

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 6
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclSlowGaugeMsg_DataUnits_Size    1u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclSlowGaugeMsg_DataUnits[MsgDeployment_UclSlowGaugeMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = SlowGaugeInfo_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_SlowGaugeInfo,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = SlowGaugeInfo_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclSlowGaugeMsg_Work;    // Status of message deployment ID: 6

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 7
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclFastGuageCustomMsg_DataUnits_Size    1u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclFastGuageCustomMsg_DataUnits[MsgDeployment_UclFastGuageCustomMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = FastGaugeInfo_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_FastGaugeInfo,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = FastGaugeInfo_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclFastGuageCustomMsg_Work;    // Status of message deployment ID: 7

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 8
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclShitPositionIndicatorMsg_DataUnits_Size    1u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclShitPositionIndicatorMsg_DataUnits[MsgDeployment_UclShitPositionIndicatorMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = ShiftPosIndStatus_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_ShiftPosIndStatus,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = ShiftPosIndStatus_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclShitPositionIndicatorMsg_Work;    // Status of message deployment ID: 8

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 9
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclIlluminationDataMsg_DataUnits_Size    1u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclIlluminationDataMsg_DataUnits[MsgDeployment_UclIlluminationDataMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = IlluminationData_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_IlluminationData,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = IlluminationData_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclIlluminationDataMsg_Work;    // Status of message deployment ID: 9

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 10
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
static SUclILMsgDbTxWork MsgDeployment_UpdateShortServiceReq_Work;    // Status of message deployment ID: 10

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 11
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
static SUclILMsgDbTxWork MsgDeployment_UpdateLongServiceReq_Work;    // Status of message deployment ID: 11

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 12
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclDiagRequest_DataUnits_Size    3u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclDiagRequest_DataUnits[MsgDeployment_UclDiagRequest_DataUnits_Size]  =
{
    {
        .dataUnitId = DiagDIDRequest_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_DiagDIDRequest,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = DiagDIDRequest_BufferSize    ///< Buffer Size (Message Based)
    },
    {
        .dataUnitId = DiagIOCtrlRequest_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_DiagIOCtrlRequest,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = DiagIOCtrlRequest_BufferSize    ///< Buffer Size (Message Based)
    },
    {
        .dataUnitId = DiagRoutineRequest_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_DiagRoutineRequest,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = DiagRoutineRequest_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclDiagRequest_Work;    // Status of message deployment ID: 12

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 13
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclDLTMessageReadRequest_DataUnits_Size    1u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclDLTMessageReadRequest_DataUnits[MsgDeployment_UclDLTMessageReadRequest_DataUnits_Size]  =
{
    {
        .dataUnitId = DLTMessageReadRequest_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_DLTMessageReadRequest,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = DLTMessageReadRequest_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclDLTMessageReadRequest_Work;    // Status of message deployment ID: 13

//---------------------------------------------------------------------------------------
// Data Units list for message deployment ID: 14
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclDLTControlMessageReponse_DataUnits_Size    1u
static const SUclILMsgDbTxDataUnit MsgDeployment_UclDLTControlMessageReponse_DataUnits[MsgDeployment_UclDLTControlMessageReponse_DataUnits_Size]  =
{
    {
        .dataUnitId = DLTControlMessageReponse_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .pMsgAdapterFunc = UclGen_Read_DLTControlMessageReponse,    ///< Adapter Function for Transmit DataUnits (Message Based)
        .msgSize = DLTControlMessageReponse_BufferSize    ///< Buffer Size (Message Based)
    }
};
static SUclILMsgDbTxWork MsgDeployment_UclDLTControlMessageReponse_Work;    // Status of message deployment ID: 14


//---------------------------------------------------------------------------------------
// Transmit DB
//---------------------------------------------------------------------------------------
const SUclILMsgDbTx UclILMsgDbTx[UclILMsgDbTx_Size] = 
{
    {
        .msgId = UclPowerDomainStateReqMsg_DID,
        .destNodeId = 1u,
        .periodictyMs = 10u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_High,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnChange,
        .notifyTxStatus = FALSE,
        .pWork = &MsgDeployment_UclPowerDomainStateReqMsg_Work,
        .pDataUnitList = MsgDeployment_UclPowerDomainStateReqMsg_DataUnits,
        .numDataUnits = MsgDeployment_UclPowerDomainStateReqMsg_DataUnits_Size
    },
    {
        .msgId = UclHealthDumpGetMsg_DID,
        .destNodeId = 1u,
        .periodictyMs = 30u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_Low,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnWrite,
        .notifyTxStatus = TRUE,
        .pWork = &MsgDeployment_UclHealthDumpGetMsg_Work,
        .pDataUnitList = MsgDeployment_UclHealthDumpGetMsg_DataUnits,
        .numDataUnits = MsgDeployment_UclHealthDumpGetMsg_DataUnits_Size
    },
    {
        .msgId = UclDisplaySetPower_DID,
        .destNodeId = 1u,
        .periodictyMs = 30u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_Critical,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnWrite,
        .notifyTxStatus = FALSE,
        .pWork = &MsgDeployment_UclDisplaySetPower_Work,
        .pDataUnitList = MsgDeployment_UclDisplaySetPower_DataUnits,
        .numDataUnits = MsgDeployment_UclDisplaySetPower_DataUnits_Size
    },
    {
        .msgId = UclTelltaleStatusMsg_DID,
        .destNodeId = 1u,
        .periodictyMs = 30u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_High,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnChange,
        .notifyTxStatus = FALSE,
        .pWork = &MsgDeployment_UclTelltaleStatusMsg_Work,
        .pDataUnitList = MsgDeployment_UclTelltaleStatusMsg_DataUnits,
        .numDataUnits = MsgDeployment_UclTelltaleStatusMsg_DataUnits_Size
    },
    {
        .msgId = UclWarningDisplayMsg_DID,
        .destNodeId = 1u,
        .periodictyMs = 30u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_High,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnChange,
        .notifyTxStatus = FALSE,
        .pWork = &MsgDeployment_UclWarningDisplayMsg_Work,
        .pDataUnitList = MsgDeployment_UclWarningDisplayMsg_DataUnits,
        .numDataUnits = MsgDeployment_UclWarningDisplayMsg_DataUnits_Size
    },
    {
        .msgId = UclSlowGaugeMsg_DID,
        .destNodeId = 1u,
        .periodictyMs = 30u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_Medium,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnChange,
        .notifyTxStatus = FALSE,
        .pWork = &MsgDeployment_UclSlowGaugeMsg_Work,
        .pDataUnitList = MsgDeployment_UclSlowGaugeMsg_DataUnits,
        .numDataUnits = MsgDeployment_UclSlowGaugeMsg_DataUnits_Size
    },
    {
        .msgId = UclFastGuageCustomMsg_DID,
        .destNodeId = 1u,
        .periodictyMs = 16u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_High,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnChange,
        .notifyTxStatus = FALSE,
        .pWork = &MsgDeployment_UclFastGuageCustomMsg_Work,
        .pDataUnitList = MsgDeployment_UclFastGuageCustomMsg_DataUnits,
        .numDataUnits = MsgDeployment_UclFastGuageCustomMsg_DataUnits_Size
    },
    {
        .msgId = UclShitPositionIndicatorMsg_DID,
        .destNodeId = 1u,
        .periodictyMs = 50u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_Low,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnChange,
        .notifyTxStatus = FALSE,
        .pWork = &MsgDeployment_UclShitPositionIndicatorMsg_Work,
        .pDataUnitList = MsgDeployment_UclShitPositionIndicatorMsg_DataUnits,
        .numDataUnits = MsgDeployment_UclShitPositionIndicatorMsg_DataUnits_Size
    },
    {
        .msgId = UclIlluminationDataMsg_DID,
        .destNodeId = 1u,
        .periodictyMs = 20u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_Low,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnChange,
        .notifyTxStatus = FALSE,
        .pWork = &MsgDeployment_UclIlluminationDataMsg_Work,
        .pDataUnitList = MsgDeployment_UclIlluminationDataMsg_DataUnits,
        .numDataUnits = MsgDeployment_UclIlluminationDataMsg_DataUnits_Size
    },
    {
        .msgId = UpdateShortServiceReq_DID,
        .destNodeId = 1u,
        .periodictyMs = 10u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_Low,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnWrite,
        .notifyTxStatus = TRUE,
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
        .notifyTxStatus = TRUE,
        .pWork = &MsgDeployment_UpdateLongServiceReq_Work,
        .pDataUnitList = MsgDeployment_UpdateLongServiceReq_DataUnits,
        .numDataUnits = MsgDeployment_UpdateLongServiceReq_DataUnits_Size
    },
    {
        .msgId = UclDiagRequest_DID,
        .destNodeId = 1u,
        .periodictyMs = 100u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_Low,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnWrite,
        .notifyTxStatus = TRUE,
        .pWork = &MsgDeployment_UclDiagRequest_Work,
        .pDataUnitList = MsgDeployment_UclDiagRequest_DataUnits,
        .numDataUnits = MsgDeployment_UclDiagRequest_DataUnits_Size
    },
    {
        .msgId = UclDLTMessageReadRequest_DID,
        .destNodeId = 1u,
        .periodictyMs = 20u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_Medium,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnWrite,
        .notifyTxStatus = FALSE,
        .sendOnInit = FALSE,
        .pWork = &MsgDeployment_UclDLTMessageReadRequest_Work,
        .pDataUnitList = MsgDeployment_UclDLTMessageReadRequest_DataUnits,
        .numDataUnits = MsgDeployment_UclDLTMessageReadRequest_DataUnits_Size
    },
    {
        .msgId = UclDLTControlMessageReponse_DID,
        .destNodeId = 1u,
        .periodictyMs = 20u,
        .securityLevel = eUclILMsgDbSecurityLevel_Unsecure,
        .priorityLevel = eUclILMsgDbPriorityLevel_Medium,
        .schedAttrib = eUclILMsgDbSchedAttrib_OnWrite,
        .notifyTxStatus = FALSE,
        .sendOnInit = FALSE,
        .pWork = &MsgDeployment_UclDLTControlMessageReponse_Work,
        .pDataUnitList = MsgDeployment_UclDLTControlMessageReponse_DataUnits,
        .numDataUnits = MsgDeployment_UclDLTControlMessageReponse_DataUnits_Size
    }
};

