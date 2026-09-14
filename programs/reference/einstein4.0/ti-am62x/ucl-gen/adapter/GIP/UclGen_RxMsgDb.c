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
// Data Units list for message deployment: UclPowerDomainStateReqMsg
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclPowerDomainStateReqMsg_DataUnits_Size    1u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclPowerDomainStateReqMsg_DataUnits[MsgDeployment_UclPowerDomainStateReqMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = PowerSystemStateReqChange_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = PowerSystemStateReqChange_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_PowerSystemStateReqChange    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclPowerDomainStateReqMsg_Work;    // Status of message deployment: UclPowerDomainStateReqMsg

//---------------------------------------------------------------------------------------
// Data Units list for message deployment: UclHealthDumpGetMsg
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclHealthDumpGetMsg_DataUnits_Size    2u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclHealthDumpGetMsg_DataUnits[MsgDeployment_UclHealthDumpGetMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = HealthDumpGetHdr_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = HealthDumpGetHdr_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_HealthDumpGetHdr    ///< Adapter Function for Received DataUnits (Message Based)
    },
    {
        .dataUnitId = HealthDumpGetData_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = HealthDumpGetData_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_HealthDumpGetData    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclHealthDumpGetMsg_Work;    // Status of message deployment: UclHealthDumpGetMsg

//---------------------------------------------------------------------------------------
// Data Units list for message deployment: UclDisplaySetPower
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclDisplaySetPower_DataUnits_Size    1u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclDisplaySetPower_DataUnits[MsgDeployment_UclDisplaySetPower_DataUnits_Size]  =
{
    {
        .dataUnitId = DisplaySetPower_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = DisplaySetPower_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_DisplaySetPower    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclDisplaySetPower_Work;    // Status of message deployment: UclDisplaySetPower

//---------------------------------------------------------------------------------------
// Data Units list for message deployment: UclTelltaleStatusMsg
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclTelltaleStatusMsg_DataUnits_Size    5u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclTelltaleStatusMsg_DataUnits[MsgDeployment_UclTelltaleStatusMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = TT_Status_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = TT_Status_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_TT_Status    ///< Adapter Function for Received DataUnits (Message Based)
    },
    {
        .dataUnitId = RTT_Toggle_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = RTT_Toggle_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_RTT_Toggle    ///< Adapter Function for Received DataUnits (Message Based)
    },
    {
        .dataUnitId = FRTT_Status_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = FRTT_Status_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_FRTT_Status    ///< Adapter Function for Received DataUnits (Message Based)
    },
    {
        .dataUnitId = RTT_Icon_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = RTT_Icon_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_RTT_Icon    ///< Adapter Function for Received DataUnits (Message Based)
    },
    {
        .dataUnitId = RTT_Status_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = RTT_Status_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_RTT_Status    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclTelltaleStatusMsg_Work;    // Status of message deployment: UclTelltaleStatusMsg

//---------------------------------------------------------------------------------------
// Data Units list for message deployment: UclWarningDisplayMsg
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclWarningDisplayMsg_DataUnits_Size    2u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclWarningDisplayMsg_DataUnits[MsgDeployment_UclWarningDisplayMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = WarningExtDisplay_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = WarningExtDisplay_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_WarningExtDisplay    ///< Adapter Function for Received DataUnits (Message Based)
    },
    {
        .dataUnitId = WarningDisplay_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = WarningDisplay_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_WarningDisplay    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclWarningDisplayMsg_Work;    // Status of message deployment: UclWarningDisplayMsg

//---------------------------------------------------------------------------------------
// Data Units list for message deployment: UclSlowGaugeMsg
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclSlowGaugeMsg_DataUnits_Size    1u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclSlowGaugeMsg_DataUnits[MsgDeployment_UclSlowGaugeMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = SlowGaugeInfo_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = SlowGaugeInfo_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_SlowGaugeInfo    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclSlowGaugeMsg_Work;    // Status of message deployment: UclSlowGaugeMsg

//---------------------------------------------------------------------------------------
// Data Units list for message deployment: UclFastGuageCustomMsg
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclFastGuageCustomMsg_DataUnits_Size    1u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclFastGuageCustomMsg_DataUnits[MsgDeployment_UclFastGuageCustomMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = FastGaugeInfo_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = FastGaugeInfo_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_FastGaugeInfo    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclFastGuageCustomMsg_Work;    // Status of message deployment: UclFastGuageCustomMsg

//---------------------------------------------------------------------------------------
// Data Units list for message deployment: UclShitPositionIndicatorMsg
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclShitPositionIndicatorMsg_DataUnits_Size    1u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclShitPositionIndicatorMsg_DataUnits[MsgDeployment_UclShitPositionIndicatorMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = ShiftPosIndStatus_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = ShiftPosIndStatus_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_ShiftPosIndStatus    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclShitPositionIndicatorMsg_Work;    // Status of message deployment: UclShitPositionIndicatorMsg

//---------------------------------------------------------------------------------------
// Data Units list for message deployment: UclIlluminationDataMsg
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclIlluminationDataMsg_DataUnits_Size    1u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclIlluminationDataMsg_DataUnits[MsgDeployment_UclIlluminationDataMsg_DataUnits_Size]  =
{
    {
        .dataUnitId = IlluminationData_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = IlluminationData_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_IlluminationData    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclIlluminationDataMsg_Work;    // Status of message deployment: UclIlluminationDataMsg

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
// Data Units list for message deployment: UclDiagRequest
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclDiagRequest_DataUnits_Size    3u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclDiagRequest_DataUnits[MsgDeployment_UclDiagRequest_DataUnits_Size]  =
{
    {
        .dataUnitId = DiagDIDRequest_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = DiagDIDRequest_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_DiagDIDRequest    ///< Adapter Function for Received DataUnits (Message Based)
    },
    {
        .dataUnitId = DiagIOCtrlRequest_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = DiagIOCtrlRequest_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_DiagIOCtrlRequest    ///< Adapter Function for Received DataUnits (Message Based)
    },
    {
        .dataUnitId = DiagRoutineRequest_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = DiagRoutineRequest_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_DiagRoutineRequest    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclDiagRequest_Work;    // Status of message deployment: UclDiagRequest

//---------------------------------------------------------------------------------------
// Data Units list for message deployment: UclDLTMessageReadRequest
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclDLTMessageReadRequest_DataUnits_Size    1u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclDLTMessageReadRequest_DataUnits[MsgDeployment_UclDLTMessageReadRequest_DataUnits_Size]  =
{
    {
        .dataUnitId = DLTMessageReadRequest_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = DLTMessageReadRequest_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_DLTMessageReadRequest    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclDLTMessageReadRequest_Work;    // Status of message deployment: UclDLTMessageReadRequest

//---------------------------------------------------------------------------------------
// Data Units list for message deployment: UclDLTControlMessageReponse
//---------------------------------------------------------------------------------------
#define MsgDeployment_UclDLTControlMessageReponse_DataUnits_Size    1u
static const SUclILMsgDbRxDataUnit MsgDeployment_UclDLTControlMessageReponse_DataUnits[MsgDeployment_UclDLTControlMessageReponse_DataUnits_Size]  =
{
    {
        .dataUnitId = DLTControlMessageReponse_MID,    ///< Data UnitId
        .numSignals = 0u,    ///< Number of Signals (Signal Based)
        .pSignalList = NULL,    ///< Signal List (Signal Based)
        .msgSize = DLTControlMessageReponse_BufferSize,    ///< Size of the message (Message Based)
        .pMsgAdapterFunc = UclGen_Send_DLTControlMessageReponse    ///< Adapter Function for Received DataUnits (Message Based)
    }
};
static SUclILMsgDbRxWork MsgDeployment_UclDLTControlMessageReponse_Work;    // Status of message deployment: UclDLTControlMessageReponse


//---------------------------------------------------------------------------------------
// Receive DB
//---------------------------------------------------------------------------------------
const SUclILMsgDbRx UclILMsgDbRx[UclILMsgDbRx_Size] = 
{
    {
        .msgId = UclPowerDomainStateReqMsg_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclPowerDomainStateReqMsg_Work,
        .numDataUnits = MsgDeployment_UclPowerDomainStateReqMsg_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclPowerDomainStateReqMsg_DataUnits
    },
    {
        .msgId = UclHealthDumpGetMsg_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclHealthDumpGetMsg_Work,
        .numDataUnits = MsgDeployment_UclHealthDumpGetMsg_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclHealthDumpGetMsg_DataUnits
    },
    {
        .msgId = UclDisplaySetPower_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclDisplaySetPower_Work,
        .numDataUnits = MsgDeployment_UclDisplaySetPower_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclDisplaySetPower_DataUnits
    },
    {
        .msgId = UclTelltaleStatusMsg_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclTelltaleStatusMsg_Work,
        .numDataUnits = MsgDeployment_UclTelltaleStatusMsg_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclTelltaleStatusMsg_DataUnits
    },
    {
        .msgId = UclWarningDisplayMsg_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclWarningDisplayMsg_Work,
        .numDataUnits = MsgDeployment_UclWarningDisplayMsg_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclWarningDisplayMsg_DataUnits
    },
    {
        .msgId = UclSlowGaugeMsg_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclSlowGaugeMsg_Work,
        .numDataUnits = MsgDeployment_UclSlowGaugeMsg_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclSlowGaugeMsg_DataUnits
    },
    {
        .msgId = UclFastGuageCustomMsg_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclFastGuageCustomMsg_Work,
        .numDataUnits = MsgDeployment_UclFastGuageCustomMsg_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclFastGuageCustomMsg_DataUnits
    },
    {
        .msgId = UclShitPositionIndicatorMsg_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclShitPositionIndicatorMsg_Work,
        .numDataUnits = MsgDeployment_UclShitPositionIndicatorMsg_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclShitPositionIndicatorMsg_DataUnits
    },
    {
        .msgId = UclIlluminationDataMsg_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclIlluminationDataMsg_Work,
        .numDataUnits = MsgDeployment_UclIlluminationDataMsg_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclIlluminationDataMsg_DataUnits
    },
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
    },
    {
        .msgId = UclDiagRequest_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclDiagRequest_Work,
        .numDataUnits = MsgDeployment_UclDiagRequest_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclDiagRequest_DataUnits
    },
    {
        .msgId = UclDLTMessageReadRequest_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclDLTMessageReadRequest_Work,
        .numDataUnits = MsgDeployment_UclDLTMessageReadRequest_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclDLTMessageReadRequest_DataUnits
    },
    {
        .msgId = UclDLTControlMessageReponse_DID, 
        .periodictyMs = 0u,
        .notifyRxMissingStatus = FALSE,
        .pWork = &MsgDeployment_UclDLTControlMessageReponse_Work,
        .numDataUnits = MsgDeployment_UclDLTControlMessageReponse_DataUnits_Size,
        .pDataUnitList = MsgDeployment_UclDLTControlMessageReponse_DataUnits
    }
};

