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

#include <UclILAdapter.h>
#include <UclILSched.h>
#include <UclALOs.h>
#include <UclALDebug.h>
#include <UclGen_VmfAdapter.h>
#include <UclGen_VmfAdapterIds.h>
#include <UclVmfMsgQueue.h>

//---------------------------------------------------------------------------------------
// Message indexes inside transmit deployments
//---------------------------------------------------------------------------------------
#define PowerSystemState_UclPowerDomainStateMsg_Index    ((uint8)0u)
#define PowerExtendShutdownTime_UclPowerDomainReqMsg_Index    ((uint8)0u)
#define PowerKeepSystemAwake_UclPowerDomainReqMsg_Index    ((uint8)1u)
#define HealthDomainHeartbeat_UclHealthHeartBeatMsg_Index    ((uint8)0u)
#define HealthDomainFatalError_UclHealthErrorMsg_Index    ((uint8)0u)
#define HealthEventRecord_UclHealthEeventMsg_Index    ((uint8)0u)
#define HealthDumpHdrInfo_UclHealthDumpDataMsg_Index    ((uint8)0u)
#define HealthDumpData_UclHealthDumpDataMsg_Index    ((uint8)1u)
#define DisplayCurrentState_UclDisplayCurrentState_Index    ((uint8)0u)
#define EmmcErrorNotifier_UclEmmcErrorNotifierMsg_Index    ((uint8)0u)
#define WarningDisplayAvailable_UclWarningStatusMsg_Index    ((uint8)0u)
#define WarningStatus_UclWarningStatusMsg_Index    ((uint8)1u)
#define SafeHMIReadyStatus_UclSubSystemStatus_Index    ((uint8)0u)
#define MainHMIReadyStatus_UclSubSystemStatus_Index    ((uint8)1u)
#define UpdateShortServiceResp_UpdateShortServiceResp_Index    ((uint8)0u)
#define DiagResponse_UclDiagResponse_Index    ((uint8)0u)
#define DLTMessageReadAck_UclDLTMessageReadAck_Index    ((uint8)0u)
#define DLTControlMessageRequest_UclDLTControlMessageRequest_Index    ((uint8)0u)

//---------------------------------------------------------------------------------------
// Message indexes inside receive deployments
//---------------------------------------------------------------------------------------
#define PowerSystemStateReqChange_UclPowerDomainStateReqMsg_Index    ((uint8)0u)
#define HealthDumpGetHdr_UclHealthDumpGetMsg_Index    ((uint8)0u)
#define HealthDumpGetData_UclHealthDumpGetMsg_Index    ((uint8)1u)
#define DisplaySetPower_UclDisplaySetPower_Index    ((uint8)0u)
#define TT_Status_UclTelltaleStatusMsg_Index    ((uint8)0u)
#define RTT_Toggle_UclTelltaleStatusMsg_Index    ((uint8)1u)
#define FRTT_Status_UclTelltaleStatusMsg_Index    ((uint8)2u)
#define RTT_Icon_UclTelltaleStatusMsg_Index    ((uint8)3u)
#define RTT_Status_UclTelltaleStatusMsg_Index    ((uint8)4u)
#define WarningExtDisplay_UclWarningDisplayMsg_Index    ((uint8)0u)
#define WarningDisplay_UclWarningDisplayMsg_Index    ((uint8)1u)
#define SlowGaugeInfo_UclSlowGaugeMsg_Index    ((uint8)0u)
#define FastGaugeInfo_UclFastGuageCustomMsg_Index    ((uint8)0u)
#define ShiftPosIndStatus_UclShitPositionIndicatorMsg_Index    ((uint8)0u)
#define IlluminationData_UclIlluminationDataMsg_Index    ((uint8)0u)
#define UpdateShortServiceReq_UpdateShortServiceReq_Index    ((uint8)0u)
#define UpdateLongServiceReq_UpdateLongServiceReq_Index    ((uint8)0u)
#define DiagDIDRequest_UclDiagRequest_Index    ((uint8)0u)
#define DiagIOCtrlRequest_UclDiagRequest_Index    ((uint8)1u)
#define DiagRoutineRequest_UclDiagRequest_Index    ((uint8)2u)
#define DLTMessageReadRequest_UclDLTMessageReadRequest_Index    ((uint8)0u)
#define DLTControlMessageReponse_UclDLTControlMessageReponse_Index    ((uint8)0u)

//---------------------------------------------------------------------------------------
// Transmit deployment indexes
//---------------------------------------------------------------------------------------
#define Tx_UclPowerDomainStateMsg_Index    ((uint8)0u)
#define Tx_UclPowerDomainReqMsg_Index    ((uint8)1u)
#define Tx_UclHealthHeartBeatMsg_Index    ((uint8)2u)
#define Tx_UclHealthErrorMsg_Index    ((uint8)3u)
#define Tx_UclHealthEeventMsg_Index    ((uint8)4u)
#define Tx_UclHealthDumpDataMsg_Index    ((uint8)5u)
#define Tx_UclDisplayCurrentState_Index    ((uint8)6u)
#define Tx_UclEmmcErrorNotifierMsg_Index    ((uint8)7u)
#define Tx_UclWarningStatusMsg_Index    ((uint8)8u)
#define Tx_UclSubSystemStatus_Index    ((uint8)9u)
#define Tx_UpdateShortServiceResp_Index    ((uint8)10u)
#define Tx_UclDiagResponse_Index    ((uint8)11u)
#define Tx_UclDLTMessageReadAck_Index    ((uint8)12u)
#define Tx_UclDLTControlMessageRequest_Index    ((uint8)13u)

//---------------------------------------------------------------------------------------
// Receive deployment indexes
//---------------------------------------------------------------------------------------
#define Rx_UclPowerDomainStateReqMsg_Index    ((uint8)0u)
#define Rx_UclHealthDumpGetMsg_Index    ((uint8)1u)
#define Rx_UclDisplaySetPower_Index    ((uint8)2u)
#define Rx_UclTelltaleStatusMsg_Index    ((uint8)3u)
#define Rx_UclWarningDisplayMsg_Index    ((uint8)4u)
#define Rx_UclSlowGaugeMsg_Index    ((uint8)5u)
#define Rx_UclFastGuageCustomMsg_Index    ((uint8)6u)
#define Rx_UclShitPositionIndicatorMsg_Index    ((uint8)7u)
#define Rx_UclIlluminationDataMsg_Index    ((uint8)8u)
#define Rx_UpdateShortServiceReq_Index    ((uint8)9u)
#define Rx_UpdateLongServiceReq_Index    ((uint8)10u)
#define Rx_UclDiagRequest_Index    ((uint8)11u)
#define Rx_UclDLTMessageReadRequest_Index    ((uint8)12u)
#define Rx_UclDLTControlMessageReponse_Index    ((uint8)13u)

//---------------------------------------------------------------------------------------
// Mixed transmit deployment & message indexes 
//---------------------------------------------------------------------------------------
#define Tx_UclPowerDomainStateMsg_PowerSystemState_MergedIndex    ((((uint16)Tx_UclPowerDomainStateMsg_Index) << 8) | ((uint16)PowerSystemState_UclPowerDomainStateMsg_Index))
#define Tx_UclPowerDomainReqMsg_PowerExtendShutdownTime_MergedIndex    ((((uint16)Tx_UclPowerDomainReqMsg_Index) << 8) | ((uint16)PowerExtendShutdownTime_UclPowerDomainReqMsg_Index))
#define Tx_UclPowerDomainReqMsg_PowerKeepSystemAwake_MergedIndex    ((((uint16)Tx_UclPowerDomainReqMsg_Index) << 8) | ((uint16)PowerKeepSystemAwake_UclPowerDomainReqMsg_Index))
#define Tx_UclHealthHeartBeatMsg_HealthDomainHeartbeat_MergedIndex    ((((uint16)Tx_UclHealthHeartBeatMsg_Index) << 8) | ((uint16)HealthDomainHeartbeat_UclHealthHeartBeatMsg_Index))
#define Tx_UclHealthErrorMsg_HealthDomainFatalError_MergedIndex    ((((uint16)Tx_UclHealthErrorMsg_Index) << 8) | ((uint16)HealthDomainFatalError_UclHealthErrorMsg_Index))
#define Tx_UclHealthEeventMsg_HealthEventRecord_MergedIndex    ((((uint16)Tx_UclHealthEeventMsg_Index) << 8) | ((uint16)HealthEventRecord_UclHealthEeventMsg_Index))
#define Tx_UclHealthDumpDataMsg_HealthDumpHdrInfo_MergedIndex    ((((uint16)Tx_UclHealthDumpDataMsg_Index) << 8) | ((uint16)HealthDumpHdrInfo_UclHealthDumpDataMsg_Index))
#define Tx_UclHealthDumpDataMsg_HealthDumpData_MergedIndex    ((((uint16)Tx_UclHealthDumpDataMsg_Index) << 8) | ((uint16)HealthDumpData_UclHealthDumpDataMsg_Index))
#define Tx_UclDisplayCurrentState_DisplayCurrentState_MergedIndex    ((((uint16)Tx_UclDisplayCurrentState_Index) << 8) | ((uint16)DisplayCurrentState_UclDisplayCurrentState_Index))
#define Tx_UclEmmcErrorNotifierMsg_EmmcErrorNotifier_MergedIndex    ((((uint16)Tx_UclEmmcErrorNotifierMsg_Index) << 8) | ((uint16)EmmcErrorNotifier_UclEmmcErrorNotifierMsg_Index))
#define Tx_UclWarningStatusMsg_WarningDisplayAvailable_MergedIndex    ((((uint16)Tx_UclWarningStatusMsg_Index) << 8) | ((uint16)WarningDisplayAvailable_UclWarningStatusMsg_Index))
#define Tx_UclWarningStatusMsg_WarningStatus_MergedIndex    ((((uint16)Tx_UclWarningStatusMsg_Index) << 8) | ((uint16)WarningStatus_UclWarningStatusMsg_Index))
#define Tx_UclSubSystemStatus_SafeHMIReadyStatus_MergedIndex    ((((uint16)Tx_UclSubSystemStatus_Index) << 8) | ((uint16)SafeHMIReadyStatus_UclSubSystemStatus_Index))
#define Tx_UclSubSystemStatus_MainHMIReadyStatus_MergedIndex    ((((uint16)Tx_UclSubSystemStatus_Index) << 8) | ((uint16)MainHMIReadyStatus_UclSubSystemStatus_Index))
#define Tx_UpdateShortServiceResp_UpdateShortServiceResp_MergedIndex    ((((uint16)Tx_UpdateShortServiceResp_Index) << 8) | ((uint16)UpdateShortServiceResp_UpdateShortServiceResp_Index))
#define Tx_UclDiagResponse_DiagResponse_MergedIndex    ((((uint16)Tx_UclDiagResponse_Index) << 8) | ((uint16)DiagResponse_UclDiagResponse_Index))
#define Tx_UclDLTMessageReadAck_DLTMessageReadAck_MergedIndex    ((((uint16)Tx_UclDLTMessageReadAck_Index) << 8) | ((uint16)DLTMessageReadAck_UclDLTMessageReadAck_Index))
#define Tx_UclDLTControlMessageRequest_DLTControlMessageRequest_MergedIndex    ((((uint16)Tx_UclDLTControlMessageRequest_Index) << 8) | ((uint16)DLTControlMessageRequest_UclDLTControlMessageRequest_Index))

//---------------------------------------------------------------------------------------
// Transmit deployments queue sizes
//---------------------------------------------------------------------------------------
#define UclPowerDomainReqMsg_QueueSize    ((uint16)5u)
#define UclHealthHeartBeatMsg_QueueSize    ((uint16)5u)
#define UclHealthErrorMsg_QueueSize    ((uint16)2u)
#define UclHealthEeventMsg_QueueSize    ((uint16)2u)
#define UclHealthDumpDataMsg_QueueSize    ((uint16)1u)
#define UclSubSystemStatus_QueueSize    ((uint16)5u)
#define UpdateShortServiceResp_QueueSize    ((uint16)2u)
#define UclDiagResponse_QueueSize    ((uint16)2u)

//---------------------------------------------------------------------------------------
// Sizes of serialized message types
//---------------------------------------------------------------------------------------
#define PowerSystemState_BufferSize    ((uint16)2u)
#define PowerExtendShutdownTime_BufferSize    ((uint16)5u)
#define PowerKeepSystemAwake_BufferSize    ((uint16)5u)
#define HealthDomainHeartbeat_BufferSize    ((uint16)5u)
#define HealthDomainFatalError_BufferSize    ((uint16)5u)
#define HealthEventRecord_BufferSize    ((uint16)10u)
#define HealthDumpHdrInfo_BufferSize    ((uint16)4u)
#define HealthDumpData_BufferSize    ((uint16)36u)
#define DisplayCurrentState_BufferSize    ((uint16)5u)
#define EmmcErrorNotifier_BufferSize    ((uint16)4u)
#define WarningDisplayAvailable_BufferSize    ((uint16)1u)
#define WarningStatus_BufferSize    ((uint16)13u)
#define SafeHMIReadyStatus_BufferSize    ((uint16)1u)
#define MainHMIReadyStatus_BufferSize    ((uint16)1u)
#define UpdateShortServiceResp_BufferSize    ((uint16)73u)
#define DiagResponse_BufferSize    ((uint16)259u)
#define DLTMessageReadAck_BufferSize    ((uint16)2u)
#define DLTControlMessageRequest_BufferSize    ((uint16)2u)

//---------------------------------------------------------------------------------------
// Message buffers
//---------------------------------------------------------------------------------------
static uint8 TxPowerSystemStateBuffer_new[PowerSystemState_BufferSize] = { 0x00 };
static uint8 TxPowerExtendShutdownTimeBuffer_new[UclPowerDomainReqMsg_QueueSize * PowerExtendShutdownTime_BufferSize] = { 0x00 };
static uint8 TxPowerKeepSystemAwakeBuffer_new[UclPowerDomainReqMsg_QueueSize * PowerKeepSystemAwake_BufferSize] = { 0x00 };
static uint8 TxHealthDomainHeartbeatBuffer_new[UclHealthHeartBeatMsg_QueueSize * HealthDomainHeartbeat_BufferSize] = { 0x00 };
static uint8 TxHealthDomainFatalErrorBuffer_new[UclHealthErrorMsg_QueueSize * HealthDomainFatalError_BufferSize] = { 0x00 };
static uint8 TxHealthEventRecordBuffer_new[UclHealthEeventMsg_QueueSize * HealthEventRecord_BufferSize] = { 0x00 };
static uint8 TxHealthDumpHdrInfoBuffer_new[UclHealthDumpDataMsg_QueueSize * HealthDumpHdrInfo_BufferSize] = { 0x00 };
static uint8 TxHealthDumpDataBuffer_new[UclHealthDumpDataMsg_QueueSize * HealthDumpData_BufferSize] = { 0x00 };
static uint8 TxDisplayCurrentStateBuffer_new[DisplayCurrentState_BufferSize] = { 0x00 };
static uint8 TxEmmcErrorNotifierBuffer_new[EmmcErrorNotifier_BufferSize] = { 0x00 };
static uint8 TxWarningDisplayAvailableBuffer_new[WarningDisplayAvailable_BufferSize] = { 0x00 };
static uint8 TxWarningStatusBuffer_new[WarningStatus_BufferSize] = { 0x00 };
static uint8 TxSafeHMIReadyStatusBuffer_new[UclSubSystemStatus_QueueSize * SafeHMIReadyStatus_BufferSize] = { 0x00 };
static uint8 TxMainHMIReadyStatusBuffer_new[UclSubSystemStatus_QueueSize * MainHMIReadyStatus_BufferSize] = { 0x00 };
static uint8 TxUpdateShortServiceRespBuffer_new[UpdateShortServiceResp_QueueSize * UpdateShortServiceResp_BufferSize] = { 0x00 };
static uint8 TxDiagResponseBuffer_new[UclDiagResponse_QueueSize * DiagResponse_BufferSize] = { 0x00 };
static uint8 TxDLTMessageReadAckBuffer_new[DLTMessageReadAck_BufferSize] = { 0x00 };
static uint8 TxDLTControlMessageRequestBuffer_new[DLTControlMessageRequest_BufferSize] = { 0x00 };

//---------------------------------------------------------------------------------------
// Configuration of queued transmit messages
//---------------------------------------------------------------------------------------
const SUclVmfMsgQueueConfig UclVmfMsgQueueConfig[UclVmfMsgQueueCount] =
{
    #define PowerExtendShutdownTime_QueueIndex    ((uint32)0u)
    {
        .pBuffer = TxPowerExtendShutdownTimeBuffer_new,
        .msgSize = PowerExtendShutdownTime_BufferSize,
        .maxMessages = UclPowerDomainReqMsg_QueueSize
    },
    #define PowerKeepSystemAwake_QueueIndex    ((uint32)1u)
    {
        .pBuffer = TxPowerKeepSystemAwakeBuffer_new,
        .msgSize = PowerKeepSystemAwake_BufferSize,
        .maxMessages = UclPowerDomainReqMsg_QueueSize
    },
    #define HealthDomainHeartbeat_QueueIndex    ((uint32)2u)
    {
        .pBuffer = TxHealthDomainHeartbeatBuffer_new,
        .msgSize = HealthDomainHeartbeat_BufferSize,
        .maxMessages = UclHealthHeartBeatMsg_QueueSize
    },
    #define HealthDomainFatalError_QueueIndex    ((uint32)3u)
    {
        .pBuffer = TxHealthDomainFatalErrorBuffer_new,
        .msgSize = HealthDomainFatalError_BufferSize,
        .maxMessages = UclHealthErrorMsg_QueueSize
    },
    #define HealthEventRecord_QueueIndex    ((uint32)4u)
    {
        .pBuffer = TxHealthEventRecordBuffer_new,
        .msgSize = HealthEventRecord_BufferSize,
        .maxMessages = UclHealthEeventMsg_QueueSize
    },
    #define HealthDumpHdrInfo_QueueIndex    ((uint32)5u)
    {
        .pBuffer = TxHealthDumpHdrInfoBuffer_new,
        .msgSize = HealthDumpHdrInfo_BufferSize,
        .maxMessages = UclHealthDumpDataMsg_QueueSize
    },
    #define HealthDumpData_QueueIndex    ((uint32)6u)
    {
        .pBuffer = TxHealthDumpDataBuffer_new,
        .msgSize = HealthDumpData_BufferSize,
        .maxMessages = UclHealthDumpDataMsg_QueueSize
    },
    #define SafeHMIReadyStatus_QueueIndex    ((uint32)7u)
    {
        .pBuffer = TxSafeHMIReadyStatusBuffer_new,
        .msgSize = SafeHMIReadyStatus_BufferSize,
        .maxMessages = UclSubSystemStatus_QueueSize
    },
    #define MainHMIReadyStatus_QueueIndex    ((uint32)8u)
    {
        .pBuffer = TxMainHMIReadyStatusBuffer_new,
        .msgSize = MainHMIReadyStatus_BufferSize,
        .maxMessages = UclSubSystemStatus_QueueSize
    },
    #define UpdateShortServiceResp_QueueIndex    ((uint32)9u)
    {
        .pBuffer = TxUpdateShortServiceRespBuffer_new,
        .msgSize = UpdateShortServiceResp_BufferSize,
        .maxMessages = UpdateShortServiceResp_QueueSize
    },
    #define DiagResponse_QueueIndex    ((uint32)10u)
    {
        .pBuffer = TxDiagResponseBuffer_new,
        .msgSize = DiagResponse_BufferSize,
        .maxMessages = UclDiagResponse_QueueSize
    }};

SUclVmfMsgQueueRuntime UclVmfMsgQueueRuntime[UclVmfMsgQueueCount];

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Common callout to retrieve message for transmission.
///
/// @param  pMsgBuff:      Buffer to store the message for transmission
/// @param  pMsgBuff_new:  Buffer that contains the latest data, received from the VMF
/// @param  pMsgBuff_sent: Buffer that contains the latest data, sent to the VIP through the UCL
/// @param  BuffSize:      Size of the message buffers
/// @param  pBytesCopied:  Incremented with number of used bytes
/// @param  returnType:    See enumerator description
/// @param  pUpdated:      Per message update flag
///
/// @return TRUE:  Data is retrieved successfully
///         FALSE: Invalid 'returnType'
///                No new data in case of 'eUclILAdapterDataType_OnChange'
//---------------------------------------------------------------------------------------------------------------------
static uint8 UclCommon_Read_Message(uint8 *pMsgBuff, uint8 *pMsgBuff_new, uint8 *pMsgBuff_sent, const uint16 BuffSize, uint16 *pBytesCopied, const EUclILAdapterDataType returnType, uint8 *pUpdated)
{
    uint8 result = FALSE;
    Ucl_ReturnType memResult = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != *pUpdated)
            {
                memResult = UclALOs_Memcpy(0u, pMsgBuff, pMsgBuff_sent, BuffSize);
                if(UCL_E_OK == memResult)
                {
                    *pBytesCopied += BuffSize;
                    result = TRUE;
                }
            }
            break;

        case eUclILAdapterDataType_Always:        ///< Adapter to return if the data is changed
            *pUpdated = TRUE;
            memResult = UclALOs_Memcpy(0u, pMsgBuff_sent, pMsgBuff_new, BuffSize);
            if(UCL_E_OK == memResult)
            {
                memResult = UclALOs_Memcpy(0u, pMsgBuff, pMsgBuff_sent, BuffSize);
                if(UCL_E_OK == memResult)
                {
                    *pBytesCopied += BuffSize;
                    result = TRUE;
                }
            }
            break;

        case eUclILAdapterDataType_OnChange:          ///< Adapter to return the latest data, if available
            *pUpdated = FALSE;
            memResult = UclALOs_Memcmp(0u, pMsgBuff_sent, pMsgBuff_new, BuffSize);
            if(UCL_E_OK != memResult)
            {
                *pUpdated = TRUE;
                memResult = UclALOs_Memcpy(0u, pMsgBuff_sent, pMsgBuff_new, BuffSize);
                if(UCL_E_OK == memResult)
                {
                    memResult = UclALOs_Memcpy(0u, pMsgBuff, pMsgBuff_sent, BuffSize);
                    if(UCL_E_OK == memResult)
                    {
                        *pBytesCopied += BuffSize;
                        result = TRUE;
                    }
                }
            }
            break;

        default:
            break;
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Will be called by UclVmfProxy when new message is received
///
/// @param  msgIdx:   Message deployment index
/// @param  duIdx:    Message index
/// @param  pPayload: Payload of the message
/// @param  Size:     Size of the message
///
/// @return See UclALOs_Memcpy
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_NotifyNewMessageReceived(uint8 msgIdx, uint8 duIdx, uint8 *pPayload, uint16 Size)
{
    uint8 result = FALSE;
    uint16 buffIndex = ((((uint16)msgIdx) << 8) | ((uint16)duIdx));

    switch (buffIndex) 
    {
        case Tx_UclPowerDomainStateMsg_PowerSystemState_MergedIndex: //DbIndex + DuIndex
            result = (UCL_E_OK == UclALOs_Memcpy(0u, TxPowerSystemStateBuffer_new, pPayload, sizeof(TxPowerSystemStateBuffer_new)));
            break;

        case Tx_UclPowerDomainReqMsg_PowerExtendShutdownTime_MergedIndex: //DbIndex + DuIndex
            result = (UCL_E_OK == UclVmfMsgQueue_Put(PowerExtendShutdownTime_QueueIndex, pPayload, Size));
            if(FALSE != result)
            {
                (void)UclILSched_NotifyMessageUpdate(0u, msgIdx, duIdx, NULL, 0u);    // For OnWrite / OnChange deployments
            }
            break;

        case Tx_UclPowerDomainReqMsg_PowerKeepSystemAwake_MergedIndex: //DbIndex + DuIndex
            result = (UCL_E_OK == UclVmfMsgQueue_Put(PowerKeepSystemAwake_QueueIndex, pPayload, Size));
            if(FALSE != result)
            {
                (void)UclILSched_NotifyMessageUpdate(0u, msgIdx, duIdx, NULL, 0u);    // For OnWrite / OnChange deployments
            }
            break;





        case Tx_UclHealthHeartBeatMsg_HealthDomainHeartbeat_MergedIndex: //DbIndex + DuIndex
            result = (UCL_E_OK == UclVmfMsgQueue_Put(HealthDomainHeartbeat_QueueIndex, pPayload, Size));
            if(FALSE != result)
            {
                (void)UclILSched_NotifyMessageUpdate(0u, msgIdx, duIdx, NULL, 0u);    // For OnWrite / OnChange deployments
            }
            break;

        case Tx_UclHealthErrorMsg_HealthDomainFatalError_MergedIndex: //DbIndex + DuIndex
            result = (UCL_E_OK == UclVmfMsgQueue_Put(HealthDomainFatalError_QueueIndex, pPayload, Size));
            if(FALSE != result)
            {
                (void)UclILSched_NotifyMessageUpdate(0u, msgIdx, duIdx, NULL, 0u);    // For OnWrite / OnChange deployments
            }
            break;

        case Tx_UclHealthEeventMsg_HealthEventRecord_MergedIndex: //DbIndex + DuIndex
            result = (UCL_E_OK == UclVmfMsgQueue_Put(HealthEventRecord_QueueIndex, pPayload, Size));
            if(FALSE != result)
            {
                (void)UclILSched_NotifyMessageUpdate(0u, msgIdx, duIdx, NULL, 0u);    // For OnWrite / OnChange deployments
            }
            break;

        case Tx_UclHealthDumpDataMsg_HealthDumpHdrInfo_MergedIndex: //DbIndex + DuIndex
            result = (UCL_E_OK == UclVmfMsgQueue_Put(HealthDumpHdrInfo_QueueIndex, pPayload, Size));
            if(FALSE != result)
            {
                (void)UclILSched_NotifyMessageUpdate(0u, msgIdx, duIdx, NULL, 0u);    // For OnWrite / OnChange deployments
            }
            break;

        case Tx_UclHealthDumpDataMsg_HealthDumpData_MergedIndex: //DbIndex + DuIndex
            result = (UCL_E_OK == UclVmfMsgQueue_Put(HealthDumpData_QueueIndex, pPayload, Size));
            if(FALSE != result)
            {
                (void)UclILSched_NotifyMessageUpdate(0u, msgIdx, duIdx, NULL, 0u);    // For OnWrite / OnChange deployments
            }
            break;



        case Tx_UclDisplayCurrentState_DisplayCurrentState_MergedIndex: //DbIndex + DuIndex
            result = (UCL_E_OK == UclALOs_Memcpy(0u, TxDisplayCurrentStateBuffer_new, pPayload, sizeof(TxDisplayCurrentStateBuffer_new)));
            (void)UclILSched_NotifyMessageUpdate(0u, msgIdx, duIdx, NULL, 0u);    // For OnWrite / OnChange deployments
            break;

        case Tx_UclEmmcErrorNotifierMsg_EmmcErrorNotifier_MergedIndex: //DbIndex + DuIndex
            result = (UCL_E_OK == UclALOs_Memcpy(0u, TxEmmcErrorNotifierBuffer_new, pPayload, sizeof(TxEmmcErrorNotifierBuffer_new)));
            (void)UclILSched_NotifyMessageUpdate(0u, msgIdx, duIdx, NULL, 0u);    // For OnWrite / OnChange deployments
            break;

        case Tx_UclWarningStatusMsg_WarningDisplayAvailable_MergedIndex: //DbIndex + DuIndex
            result = (UCL_E_OK == UclALOs_Memcpy(0u, TxWarningDisplayAvailableBuffer_new, pPayload, sizeof(TxWarningDisplayAvailableBuffer_new)));
            (void)UclILSched_NotifyMessageUpdate(0u, msgIdx, duIdx, NULL, 0u);    // For OnWrite / OnChange deployments
            break;

        case Tx_UclWarningStatusMsg_WarningStatus_MergedIndex: //DbIndex + DuIndex
            result = (UCL_E_OK == UclALOs_Memcpy(0u, TxWarningStatusBuffer_new, pPayload, sizeof(TxWarningStatusBuffer_new)));
            (void)UclILSched_NotifyMessageUpdate(0u, msgIdx, duIdx, NULL, 0u);    // For OnWrite / OnChange deployments
            break;

        case Tx_UclSubSystemStatus_SafeHMIReadyStatus_MergedIndex: //DbIndex + DuIndex
            result = (UCL_E_OK == UclVmfMsgQueue_Put(SafeHMIReadyStatus_QueueIndex, pPayload, Size));
            if(FALSE != result)
            {
                (void)UclILSched_NotifyMessageUpdate(0u, msgIdx, duIdx, NULL, 0u);    // For OnWrite / OnChange deployments
            }
            break;

        case Tx_UclSubSystemStatus_MainHMIReadyStatus_MergedIndex: //DbIndex + DuIndex
            result = (UCL_E_OK == UclVmfMsgQueue_Put(MainHMIReadyStatus_QueueIndex, pPayload, Size));
            if(FALSE != result)
            {
                (void)UclILSched_NotifyMessageUpdate(0u, msgIdx, duIdx, NULL, 0u);    // For OnWrite / OnChange deployments
            }
            break;

        case Tx_UpdateShortServiceResp_UpdateShortServiceResp_MergedIndex: //DbIndex + DuIndex
            result = (UCL_E_OK == UclVmfMsgQueue_Put(UpdateShortServiceResp_QueueIndex, pPayload, Size));
            if(FALSE != result)
            {
                (void)UclILSched_NotifyMessageUpdate(0u, msgIdx, duIdx, NULL, 0u);    // For OnWrite / OnChange deployments
            }
            break;

        case Tx_UclDiagResponse_DiagResponse_MergedIndex: //DbIndex + DuIndex
            result = (UCL_E_OK == UclVmfMsgQueue_Put(DiagResponse_QueueIndex, pPayload, Size));
            if(FALSE != result)
            {
                (void)UclILSched_NotifyMessageUpdate(0u, msgIdx, duIdx, NULL, 0u);    // For OnWrite / OnChange deployments
            }
            break;

        case Tx_UclDLTMessageReadAck_DLTMessageReadAck_MergedIndex: //DbIndex + DuIndex
            result = (UCL_E_OK == UclALOs_Memcpy(0u, TxDLTMessageReadAckBuffer_new, pPayload, sizeof(TxDLTMessageReadAckBuffer_new)));
            (void)UclILSched_NotifyMessageUpdate(0u, msgIdx, duIdx, NULL, 0u);    // For OnWrite / OnChange deployments
            break;

        case Tx_UclDLTControlMessageRequest_DLTControlMessageRequest_MergedIndex: //DbIndex + DuIndex
            result = (UCL_E_OK == UclALOs_Memcpy(0u, TxDLTControlMessageRequestBuffer_new, pPayload, sizeof(TxDLTControlMessageRequestBuffer_new)));
            (void)UclILSched_NotifyMessageUpdate(0u, msgIdx, duIdx, NULL, 0u);    // For OnWrite / OnChange deployments
            break;
    }
    return result;
}

//---------------------------------------------------------------------------------------------------------------------
// Callouts for transmit messages
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message PowerSystemState
//---------------------------------------------------------------------------------------------------------------------
static uint8 TxPowerSystemStateBuffer_sent[PowerSystemState_BufferSize] = { 0x00 };
static uint8 iS_PowerSystemStateBuffer_updated = FALSE;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: PowerSystemState
///
/// @param  pMsgBuff:     Buffer to store the message for transmission
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return See UclCommon_Read_Message
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_PowerSystemState(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    return UclCommon_Read_Message(pMsgBuff, TxPowerSystemStateBuffer_new, TxPowerSystemStateBuffer_sent, sizeof(TxPowerSystemStateBuffer_sent), pBytesCopied, returnType, &iS_PowerSystemStateBuffer_updated);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message PowerExtendShutdownTime
//---------------------------------------------------------------------------------------------------------------------
static uint8 TxPowerExtendShutdownTimeBuffer_sent[PowerExtendShutdownTime_BufferSize] = { 0x00 };
static uint8 iS_PowerExtendShutdownTimeBuffer_updated = FALSE;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: PowerExtendShutdownTime
///
/// @param  pMsgBuff:     Buffer to store the message for transmission
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return See UclCommon_Read_Message
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_PowerExtendShutdownTime(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    uint8 TxPowerExtendShutdownTimeBuffer_local[PowerExtendShutdownTime_BufferSize];
    uint8 result = TRUE;

    // Read the queue only if previous data is sent
    if(eUclILAdapterDataType_Retry != returnType)
    {
        result = (UCL_E_OK == UclVmfMsgQueue_Get(PowerExtendShutdownTime_QueueIndex, TxPowerExtendShutdownTimeBuffer_local, sizeof(TxPowerExtendShutdownTimeBuffer_local)));
    }

    if(FALSE != result)
    {                              
        result = UclCommon_Read_Message(pMsgBuff, TxPowerExtendShutdownTimeBuffer_local, TxPowerExtendShutdownTimeBuffer_sent, sizeof(TxPowerExtendShutdownTimeBuffer_sent), pBytesCopied, returnType, &iS_PowerExtendShutdownTimeBuffer_updated);                                   
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message PowerKeepSystemAwake
//---------------------------------------------------------------------------------------------------------------------
static uint8 TxPowerKeepSystemAwakeBuffer_sent[PowerKeepSystemAwake_BufferSize] = { 0x00 };
static uint8 iS_PowerKeepSystemAwakeBuffer_updated = FALSE;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: PowerKeepSystemAwake
///
/// @param  pMsgBuff:     Buffer to store the message for transmission
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return See UclCommon_Read_Message
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_PowerKeepSystemAwake(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    uint8 TxPowerKeepSystemAwakeBuffer_local[PowerKeepSystemAwake_BufferSize];
    uint8 result = TRUE;

    // Read the queue only if previous data is sent
    if(eUclILAdapterDataType_Retry != returnType)
    {
        result = (UCL_E_OK == UclVmfMsgQueue_Get(PowerKeepSystemAwake_QueueIndex, TxPowerKeepSystemAwakeBuffer_local, sizeof(TxPowerKeepSystemAwakeBuffer_local)));
    }

    if(FALSE != result)
    {                              
        result = UclCommon_Read_Message(pMsgBuff, TxPowerKeepSystemAwakeBuffer_local, TxPowerKeepSystemAwakeBuffer_sent, sizeof(TxPowerKeepSystemAwakeBuffer_sent), pBytesCopied, returnType, &iS_PowerKeepSystemAwakeBuffer_updated);                                   
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message HealthDomainHeartbeat
//---------------------------------------------------------------------------------------------------------------------
static uint8 TxHealthDomainHeartbeatBuffer_sent[HealthDomainHeartbeat_BufferSize] = { 0x00 };
static uint8 iS_HealthDomainHeartbeatBuffer_updated = FALSE;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: HealthDomainHeartbeat
///
/// @param  pMsgBuff:     Buffer to store the message for transmission
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return See UclCommon_Read_Message
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_HealthDomainHeartbeat(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    uint8 TxHealthDomainHeartbeatBuffer_local[HealthDomainHeartbeat_BufferSize];
    uint8 result = TRUE;

    // Read the queue only if previous data is sent
    if(eUclILAdapterDataType_Retry != returnType)
    {
        result = (UCL_E_OK == UclVmfMsgQueue_Get(HealthDomainHeartbeat_QueueIndex, TxHealthDomainHeartbeatBuffer_local, sizeof(TxHealthDomainHeartbeatBuffer_local)));
    }

    if(FALSE != result)
    {                              
        result = UclCommon_Read_Message(pMsgBuff, TxHealthDomainHeartbeatBuffer_local, TxHealthDomainHeartbeatBuffer_sent, sizeof(TxHealthDomainHeartbeatBuffer_sent), pBytesCopied, returnType, &iS_HealthDomainHeartbeatBuffer_updated);                                   
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message HealthDomainFatalError
//---------------------------------------------------------------------------------------------------------------------
static uint8 TxHealthDomainFatalErrorBuffer_sent[HealthDomainFatalError_BufferSize] = { 0x00 };
static uint8 iS_HealthDomainFatalErrorBuffer_updated = FALSE;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: HealthDomainFatalError
///
/// @param  pMsgBuff:     Buffer to store the message for transmission
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return See UclCommon_Read_Message
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_HealthDomainFatalError(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    uint8 TxHealthDomainFatalErrorBuffer_local[HealthDomainFatalError_BufferSize];
    uint8 result = TRUE;

    // Read the queue only if previous data is sent
    if(eUclILAdapterDataType_Retry != returnType)
    {
        result = (UCL_E_OK == UclVmfMsgQueue_Get(HealthDomainFatalError_QueueIndex, TxHealthDomainFatalErrorBuffer_local, sizeof(TxHealthDomainFatalErrorBuffer_local)));
    }

    if(FALSE != result)
    {                              
        result = UclCommon_Read_Message(pMsgBuff, TxHealthDomainFatalErrorBuffer_local, TxHealthDomainFatalErrorBuffer_sent, sizeof(TxHealthDomainFatalErrorBuffer_sent), pBytesCopied, returnType, &iS_HealthDomainFatalErrorBuffer_updated);                                   
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message HealthEventRecord
//---------------------------------------------------------------------------------------------------------------------
static uint8 TxHealthEventRecordBuffer_sent[HealthEventRecord_BufferSize] = { 0x00 };
static uint8 iS_HealthEventRecordBuffer_updated = FALSE;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: HealthEventRecord
///
/// @param  pMsgBuff:     Buffer to store the message for transmission
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return See UclCommon_Read_Message
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_HealthEventRecord(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    uint8 TxHealthEventRecordBuffer_local[HealthEventRecord_BufferSize];
    uint8 result = TRUE;

    // Read the queue only if previous data is sent
    if(eUclILAdapterDataType_Retry != returnType)
    {
        result = (UCL_E_OK == UclVmfMsgQueue_Get(HealthEventRecord_QueueIndex, TxHealthEventRecordBuffer_local, sizeof(TxHealthEventRecordBuffer_local)));
    }

    if(FALSE != result)
    {                              
        result = UclCommon_Read_Message(pMsgBuff, TxHealthEventRecordBuffer_local, TxHealthEventRecordBuffer_sent, sizeof(TxHealthEventRecordBuffer_sent), pBytesCopied, returnType, &iS_HealthEventRecordBuffer_updated);                                   
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message HealthDumpHdrInfo
//---------------------------------------------------------------------------------------------------------------------
static uint8 TxHealthDumpHdrInfoBuffer_sent[HealthDumpHdrInfo_BufferSize] = { 0x00 };
static uint8 iS_HealthDumpHdrInfoBuffer_updated = FALSE;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: HealthDumpHdrInfo
///
/// @param  pMsgBuff:     Buffer to store the message for transmission
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return See UclCommon_Read_Message
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_HealthDumpHdrInfo(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    uint8 TxHealthDumpHdrInfoBuffer_local[HealthDumpHdrInfo_BufferSize];
    uint8 result = TRUE;

    // Read the queue only if previous data is sent
    if(eUclILAdapterDataType_Retry != returnType)
    {
        result = (UCL_E_OK == UclVmfMsgQueue_Get(HealthDumpHdrInfo_QueueIndex, TxHealthDumpHdrInfoBuffer_local, sizeof(TxHealthDumpHdrInfoBuffer_local)));
    }

    if(FALSE != result)
    {                              
        result = UclCommon_Read_Message(pMsgBuff, TxHealthDumpHdrInfoBuffer_local, TxHealthDumpHdrInfoBuffer_sent, sizeof(TxHealthDumpHdrInfoBuffer_sent), pBytesCopied, returnType, &iS_HealthDumpHdrInfoBuffer_updated);                                   
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message HealthDumpData
//---------------------------------------------------------------------------------------------------------------------
static uint8 TxHealthDumpDataBuffer_sent[HealthDumpData_BufferSize] = { 0x00 };
static uint8 iS_HealthDumpDataBuffer_updated = FALSE;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: HealthDumpData
///
/// @param  pMsgBuff:     Buffer to store the message for transmission
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return See UclCommon_Read_Message
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_HealthDumpData(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    uint8 TxHealthDumpDataBuffer_local[HealthDumpData_BufferSize];
    uint8 result = TRUE;

    // Read the queue only if previous data is sent
    if(eUclILAdapterDataType_Retry != returnType)
    {
        result = (UCL_E_OK == UclVmfMsgQueue_Get(HealthDumpData_QueueIndex, TxHealthDumpDataBuffer_local, sizeof(TxHealthDumpDataBuffer_local)));
    }

    if(FALSE != result)
    {                              
        result = UclCommon_Read_Message(pMsgBuff, TxHealthDumpDataBuffer_local, TxHealthDumpDataBuffer_sent, sizeof(TxHealthDumpDataBuffer_sent), pBytesCopied, returnType, &iS_HealthDumpDataBuffer_updated);                                   
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message DisplayCurrentState
//---------------------------------------------------------------------------------------------------------------------
static uint8 TxDisplayCurrentStateBuffer_sent[DisplayCurrentState_BufferSize] = { 0x00 };
static uint8 iS_DisplayCurrentStateBuffer_updated = FALSE;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: DisplayCurrentState
///
/// @param  pMsgBuff:     Buffer to store the message for transmission
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return See UclCommon_Read_Message
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_DisplayCurrentState(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    return UclCommon_Read_Message(pMsgBuff, TxDisplayCurrentStateBuffer_new, TxDisplayCurrentStateBuffer_sent, sizeof(TxDisplayCurrentStateBuffer_sent), pBytesCopied, returnType, &iS_DisplayCurrentStateBuffer_updated);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message EmmcErrorNotifier
//---------------------------------------------------------------------------------------------------------------------
static uint8 TxEmmcErrorNotifierBuffer_sent[EmmcErrorNotifier_BufferSize] = { 0x00 };
static uint8 iS_EmmcErrorNotifierBuffer_updated = FALSE;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: EmmcErrorNotifier
///
/// @param  pMsgBuff:     Buffer to store the message for transmission
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return See UclCommon_Read_Message
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_EmmcErrorNotifier(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    return UclCommon_Read_Message(pMsgBuff, TxEmmcErrorNotifierBuffer_new, TxEmmcErrorNotifierBuffer_sent, sizeof(TxEmmcErrorNotifierBuffer_sent), pBytesCopied, returnType, &iS_EmmcErrorNotifierBuffer_updated);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message WarningDisplayAvailable
//---------------------------------------------------------------------------------------------------------------------
static uint8 TxWarningDisplayAvailableBuffer_sent[WarningDisplayAvailable_BufferSize] = { 0x00 };
static uint8 iS_WarningDisplayAvailableBuffer_updated = FALSE;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: WarningDisplayAvailable
///
/// @param  pMsgBuff:     Buffer to store the message for transmission
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return See UclCommon_Read_Message
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_WarningDisplayAvailable(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    return UclCommon_Read_Message(pMsgBuff, TxWarningDisplayAvailableBuffer_new, TxWarningDisplayAvailableBuffer_sent, sizeof(TxWarningDisplayAvailableBuffer_sent), pBytesCopied, returnType, &iS_WarningDisplayAvailableBuffer_updated);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message WarningStatus
//---------------------------------------------------------------------------------------------------------------------
static uint8 TxWarningStatusBuffer_sent[WarningStatus_BufferSize] = { 0x00 };
static uint8 iS_WarningStatusBuffer_updated = FALSE;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: WarningStatus
///
/// @param  pMsgBuff:     Buffer to store the message for transmission
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return See UclCommon_Read_Message
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_WarningStatus(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    return UclCommon_Read_Message(pMsgBuff, TxWarningStatusBuffer_new, TxWarningStatusBuffer_sent, sizeof(TxWarningStatusBuffer_sent), pBytesCopied, returnType, &iS_WarningStatusBuffer_updated);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message SafeHMIReadyStatus
//---------------------------------------------------------------------------------------------------------------------
static uint8 TxSafeHMIReadyStatusBuffer_sent[SafeHMIReadyStatus_BufferSize] = { 0x00 };
static uint8 iS_SafeHMIReadyStatusBuffer_updated = FALSE;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: SafeHMIReadyStatus
///
/// @param  pMsgBuff:     Buffer to store the message for transmission
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return See UclCommon_Read_Message
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_SafeHMIReadyStatus(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    uint8 TxSafeHMIReadyStatusBuffer_local[SafeHMIReadyStatus_BufferSize];
    uint8 result = TRUE;

    // Read the queue only if previous data is sent
    if(eUclILAdapterDataType_Retry != returnType)
    {
        result = (UCL_E_OK == UclVmfMsgQueue_Get(SafeHMIReadyStatus_QueueIndex, TxSafeHMIReadyStatusBuffer_local, sizeof(TxSafeHMIReadyStatusBuffer_local)));
    }

    if(FALSE != result)
    {                              
        result = UclCommon_Read_Message(pMsgBuff, TxSafeHMIReadyStatusBuffer_local, TxSafeHMIReadyStatusBuffer_sent, sizeof(TxSafeHMIReadyStatusBuffer_sent), pBytesCopied, returnType, &iS_SafeHMIReadyStatusBuffer_updated);                                   
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message MainHMIReadyStatus
//---------------------------------------------------------------------------------------------------------------------
static uint8 TxMainHMIReadyStatusBuffer_sent[MainHMIReadyStatus_BufferSize] = { 0x00 };
static uint8 iS_MainHMIReadyStatusBuffer_updated = FALSE;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: MainHMIReadyStatus
///
/// @param  pMsgBuff:     Buffer to store the message for transmission
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return See UclCommon_Read_Message
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_MainHMIReadyStatus(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    uint8 TxMainHMIReadyStatusBuffer_local[MainHMIReadyStatus_BufferSize];
    uint8 result = TRUE;

    // Read the queue only if previous data is sent
    if(eUclILAdapterDataType_Retry != returnType)
    {
        result = (UCL_E_OK == UclVmfMsgQueue_Get(MainHMIReadyStatus_QueueIndex, TxMainHMIReadyStatusBuffer_local, sizeof(TxMainHMIReadyStatusBuffer_local)));
    }

    if(FALSE != result)
    {                              
        result = UclCommon_Read_Message(pMsgBuff, TxMainHMIReadyStatusBuffer_local, TxMainHMIReadyStatusBuffer_sent, sizeof(TxMainHMIReadyStatusBuffer_sent), pBytesCopied, returnType, &iS_MainHMIReadyStatusBuffer_updated);                                   
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message UpdateShortServiceResp
//---------------------------------------------------------------------------------------------------------------------
static uint8 TxUpdateShortServiceRespBuffer_sent[UpdateShortServiceResp_BufferSize] = { 0x00 };
static uint8 iS_UpdateShortServiceRespBuffer_updated = FALSE;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: UpdateShortServiceResp
///
/// @param  pMsgBuff:     Buffer to store the message for transmission
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return See UclCommon_Read_Message
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_UpdateShortServiceResp(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    uint8 TxUpdateShortServiceRespBuffer_local[UpdateShortServiceResp_BufferSize];
    uint8 result = TRUE;

    // Read the queue only if previous data is sent
    if(eUclILAdapterDataType_Retry != returnType)
    {
        result = (UCL_E_OK == UclVmfMsgQueue_Get(UpdateShortServiceResp_QueueIndex, TxUpdateShortServiceRespBuffer_local, sizeof(TxUpdateShortServiceRespBuffer_local)));
    }

    if(FALSE != result)
    {                              
        result = UclCommon_Read_Message(pMsgBuff, TxUpdateShortServiceRespBuffer_local, TxUpdateShortServiceRespBuffer_sent, sizeof(TxUpdateShortServiceRespBuffer_sent), pBytesCopied, returnType, &iS_UpdateShortServiceRespBuffer_updated);                                   
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message DiagResponse
//---------------------------------------------------------------------------------------------------------------------
static uint8 TxDiagResponseBuffer_sent[DiagResponse_BufferSize] = { 0x00 };
static uint8 iS_DiagResponseBuffer_updated = FALSE;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: DiagResponse
///
/// @param  pMsgBuff:     Buffer to store the message for transmission
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return See UclCommon_Read_Message
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_DiagResponse(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    uint8 TxDiagResponseBuffer_local[DiagResponse_BufferSize];
    uint8 result = TRUE;

    // Read the queue only if previous data is sent
    if(eUclILAdapterDataType_Retry != returnType)
    {
        result = (UCL_E_OK == UclVmfMsgQueue_Get(DiagResponse_QueueIndex, TxDiagResponseBuffer_local, sizeof(TxDiagResponseBuffer_local)));
    }

    if(FALSE != result)
    {                              
        result = UclCommon_Read_Message(pMsgBuff, TxDiagResponseBuffer_local, TxDiagResponseBuffer_sent, sizeof(TxDiagResponseBuffer_sent), pBytesCopied, returnType, &iS_DiagResponseBuffer_updated);                                   
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message DLTMessageReadAck
//---------------------------------------------------------------------------------------------------------------------
static uint8 TxDLTMessageReadAckBuffer_sent[DLTMessageReadAck_BufferSize] = { 0x00 };
static uint8 iS_DLTMessageReadAckBuffer_updated = FALSE;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: DLTMessageReadAck
///
/// @param  pMsgBuff:     Buffer to store the message for transmission
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return See UclCommon_Read_Message
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_DLTMessageReadAck(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    return UclCommon_Read_Message(pMsgBuff, TxDLTMessageReadAckBuffer_new, TxDLTMessageReadAckBuffer_sent, sizeof(TxDLTMessageReadAckBuffer_sent), pBytesCopied, returnType, &iS_DLTMessageReadAckBuffer_updated);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message DLTControlMessageRequest
//---------------------------------------------------------------------------------------------------------------------
static uint8 TxDLTControlMessageRequestBuffer_sent[DLTControlMessageRequest_BufferSize] = { 0x00 };
static uint8 iS_DLTControlMessageRequestBuffer_updated = FALSE;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: DLTControlMessageRequest
///
/// @param  pMsgBuff:     Buffer to store the message for transmission
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return See UclCommon_Read_Message
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_DLTControlMessageRequest(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    return UclCommon_Read_Message(pMsgBuff, TxDLTControlMessageRequestBuffer_new, TxDLTControlMessageRequestBuffer_sent, sizeof(TxDLTControlMessageRequestBuffer_sent), pBytesCopied, returnType, &iS_DLTControlMessageRequestBuffer_updated);
}

//---------------------------------------------------------------------------------------------------------------------
// Callouts for received messages
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message PowerSystemStateReqChange. Send message content to VMF server.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Message added to transmit queue
///         FALSE: See CUclVmfProxy::addVmfMsgToTxQueue 
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_PowerSystemStateReqChange(uint8 *pMsgBuff, uint16 Size)
{
    return UclVmfProxy_AddVmfMsgToTxQueue(Gx_PowerSystemStateReqChange_Rx, Ex_PowerSystemStateReqChange_Rx, pMsgBuff, Size);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message HealthDumpGetHdr. Send message content to VMF server.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Message added to transmit queue
///         FALSE: See CUclVmfProxy::addVmfMsgToTxQueue 
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_HealthDumpGetHdr(uint8 *pMsgBuff, uint16 Size)
{
    return UclVmfProxy_AddVmfMsgToTxQueue(Gx_HealthDumpGetHdr_Rx, Ex_HealthDumpGetHdr_Rx, pMsgBuff, Size);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message HealthDumpGetData. Send message content to VMF server.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Message added to transmit queue
///         FALSE: See CUclVmfProxy::addVmfMsgToTxQueue 
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_HealthDumpGetData(uint8 *pMsgBuff, uint16 Size)
{
    return UclVmfProxy_AddVmfMsgToTxQueue(Gx_HealthDumpGetData_Rx, Ex_HealthDumpGetData_Rx, pMsgBuff, Size);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message DisplaySetPower. Send message content to VMF server.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Message added to transmit queue
///         FALSE: See CUclVmfProxy::addVmfMsgToTxQueue 
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_DisplaySetPower(uint8 *pMsgBuff, uint16 Size)
{
    return UclVmfProxy_AddVmfMsgToTxQueue(Gx_DisplaySetPower_Rx, Ex_DisplaySetPower_Rx, pMsgBuff, Size);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message TT_Status. Send message content to VMF server.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Message added to transmit queue
///         FALSE: See CUclVmfProxy::addVmfMsgToTxQueue 
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_TT_Status(uint8 *pMsgBuff, uint16 Size)
{
    return UclVmfProxy_AddVmfMsgToTxQueue(Gx_TT_Status_Rx, Ex_TT_Status_Rx, pMsgBuff, Size);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message RTT_Toggle. Send message content to VMF server.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Message added to transmit queue
///         FALSE: See CUclVmfProxy::addVmfMsgToTxQueue 
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_RTT_Toggle(uint8 *pMsgBuff, uint16 Size)
{
    return UclVmfProxy_AddVmfMsgToTxQueue(Gx_RTT_Toggle_Rx, Ex_RTT_Toggle_Rx, pMsgBuff, Size);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message FRTT_Status. Send message content to VMF server.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Message added to transmit queue
///         FALSE: See CUclVmfProxy::addVmfMsgToTxQueue 
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_FRTT_Status(uint8 *pMsgBuff, uint16 Size)
{
    return UclVmfProxy_AddVmfMsgToTxQueue(Gx_FRTT_Status_Rx, Ex_FRTT_Status_Rx, pMsgBuff, Size);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message RTT_Icon. Send message content to VMF server.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Message added to transmit queue
///         FALSE: See CUclVmfProxy::addVmfMsgToTxQueue 
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_RTT_Icon(uint8 *pMsgBuff, uint16 Size)
{
    return UclVmfProxy_AddVmfMsgToTxQueue(Gx_RTT_Icon_Rx, Ex_RTT_Icon_Rx, pMsgBuff, Size);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message RTT_Status. Send message content to VMF server.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Message added to transmit queue
///         FALSE: See CUclVmfProxy::addVmfMsgToTxQueue 
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_RTT_Status(uint8 *pMsgBuff, uint16 Size)
{
    return UclVmfProxy_AddVmfMsgToTxQueue(Gx_RTT_Status_Rx, Ex_RTT_Status_Rx, pMsgBuff, Size);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message WarningExtDisplay. Send message content to VMF server.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Message added to transmit queue
///         FALSE: See CUclVmfProxy::addVmfMsgToTxQueue 
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_WarningExtDisplay(uint8 *pMsgBuff, uint16 Size)
{
    return UclVmfProxy_AddVmfMsgToTxQueue(Gx_WarningExtDisplay_Rx, Ex_WarningExtDisplay_Rx, pMsgBuff, Size);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message WarningDisplay. Send message content to VMF server.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Message added to transmit queue
///         FALSE: See CUclVmfProxy::addVmfMsgToTxQueue 
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_WarningDisplay(uint8 *pMsgBuff, uint16 Size)
{
    return UclVmfProxy_AddVmfMsgToTxQueue(Gx_WarningDisplay_Rx, Ex_WarningDisplay_Rx, pMsgBuff, Size);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message SlowGaugeInfo. Send message content to VMF server.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Message added to transmit queue
///         FALSE: See CUclVmfProxy::addVmfMsgToTxQueue 
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_SlowGaugeInfo(uint8 *pMsgBuff, uint16 Size)
{
    return UclVmfProxy_AddVmfMsgToTxQueue(Gx_SlowGaugeInfo_Rx, Ex_SlowGaugeInfo_Rx, pMsgBuff, Size);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message FastGaugeInfo. Send message content to VMF server.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Message added to transmit queue
///         FALSE: See CUclVmfProxy::addVmfMsgToTxQueue 
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_FastGaugeInfo(uint8 *pMsgBuff, uint16 Size)
{
    return UclVmfProxy_AddVmfMsgToTxQueue(Gx_FastGaugeInfo_Rx, Ex_FastGaugeInfo_Rx, pMsgBuff, Size);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message ShiftPosIndStatus. Send message content to VMF server.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Message added to transmit queue
///         FALSE: See CUclVmfProxy::addVmfMsgToTxQueue 
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_ShiftPosIndStatus(uint8 *pMsgBuff, uint16 Size)
{
    return UclVmfProxy_AddVmfMsgToTxQueue(Gx_ShiftPosIndStatus_Rx, Ex_ShiftPosIndStatus_Rx, pMsgBuff, Size);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message IlluminationData. Send message content to VMF server.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Message added to transmit queue
///         FALSE: See CUclVmfProxy::addVmfMsgToTxQueue 
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_IlluminationData(uint8 *pMsgBuff, uint16 Size)
{
    return UclVmfProxy_AddVmfMsgToTxQueue(Gx_IlluminationData_Rx, Ex_IlluminationData_Rx, pMsgBuff, Size);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message UpdateShortServiceReq. Send message content to VMF server.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Message added to transmit queue
///         FALSE: See CUclVmfProxy::addVmfMsgToTxQueue 
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_UpdateShortServiceReq(uint8 *pMsgBuff, uint16 Size)
{
    return UclVmfProxy_AddVmfMsgToTxQueue(Gx_UpdateShortServiceReq_Rx, Ex_UpdateShortServiceReq_Rx, pMsgBuff, Size);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message UpdateLongServiceReq. Send message content to VMF server.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Message added to transmit queue
///         FALSE: See CUclVmfProxy::addVmfMsgToTxQueue 
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_UpdateLongServiceReq(uint8 *pMsgBuff, uint16 Size)
{
    return UclVmfProxy_AddVmfMsgToTxQueue(Gx_UpdateLongServiceReq_Rx, Ex_UpdateLongServiceReq_Rx, pMsgBuff, Size);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message DiagDIDRequest. Send message content to VMF server.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Message added to transmit queue
///         FALSE: See CUclVmfProxy::addVmfMsgToTxQueue 
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_DiagDIDRequest(uint8 *pMsgBuff, uint16 Size)
{
    return UclVmfProxy_AddVmfMsgToTxQueue(Gx_DiagDIDRequest_Rx, Ex_DiagDIDRequest_Rx, pMsgBuff, Size);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message DiagIOCtrlRequest. Send message content to VMF server.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Message added to transmit queue
///         FALSE: See CUclVmfProxy::addVmfMsgToTxQueue 
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_DiagIOCtrlRequest(uint8 *pMsgBuff, uint16 Size)
{
    return UclVmfProxy_AddVmfMsgToTxQueue(Gx_DiagIOCtrlRequest_Rx, Ex_DiagIOCtrlRequest_Rx, pMsgBuff, Size);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message DiagRoutineRequest. Send message content to VMF server.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Message added to transmit queue
///         FALSE: See CUclVmfProxy::addVmfMsgToTxQueue 
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_DiagRoutineRequest(uint8 *pMsgBuff, uint16 Size)
{
    return UclVmfProxy_AddVmfMsgToTxQueue(Gx_DiagRoutineRequest_Rx, Ex_DiagRoutineRequest_Rx, pMsgBuff, Size);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message DLTMessageReadRequest. Send message content to VMF server.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Message added to transmit queue
///         FALSE: See CUclVmfProxy::addVmfMsgToTxQueue 
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_DLTMessageReadRequest(uint8 *pMsgBuff, uint16 Size)
{
    return UclVmfProxy_AddVmfMsgToTxQueue(Gx_DLTMessageReadRequest_Rx, Ex_DLTMessageReadRequest_Rx, pMsgBuff, Size);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message DLTControlMessageReponse. Send message content to VMF server.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Message added to transmit queue
///         FALSE: See CUclVmfProxy::addVmfMsgToTxQueue 
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_DLTControlMessageReponse(uint8 *pMsgBuff, uint16 Size)
{
    return UclVmfProxy_AddVmfMsgToTxQueue(Gx_DLTControlMessageReponse_Rx, Ex_DLTControlMessageReponse_Rx, pMsgBuff, Size);
}


//---------------------------------------------------------------------------------------------------------------------
// Status notifications
//---------------------------------------------------------------------------------------------------------------------
void UclGen_Adapter_ErrorNotification(uint8 DLInst, sint32 ErrorCode) 
{
    LOGI(0u, "UclGen", "ErrorNotification %d, %d", DLInst, ErrorCode);
#ifdef UCL_ERROR_NOTIFY
	UclVmfProxy_AddVmfMsgToTxQueue(Gx_Ucl_Error_Notify_Rx, Ex_Ucl_Error_Notify_Rx, (uint8 *)(&ErrorCode), sizeof(ErrorCode));
#endif
}

void UclGen_Adapter_LinkStatusChanged(uint8 DLInst, sint32 Status) 
{
    LOGI(0u, "UclGen", "LinkStatusChanged %d, %d", DLInst, Status);
#ifdef UCL_LINK_STATUS
	UclVmfProxy_AddVmfMsgToTxQueue(Gx_Ucl_Link_Status_Rx, Ex_Ucl_Link_Status_Rx, (uint8 *)(&Status), sizeof(Status));
#endif
}

void UclGen_Adapter_MessageTransmitStatus(uint16 MsgId, sint32 Status) 
{
    LOGI(0u, "UclGen", "MessageTransmitStatus 0x%02x, %d", MsgId, Status);
    switch (MsgId)
    {
        case UclPowerDomainReqMsg_DID:

            // Scheduler notification for queued and nonperiodic messages
            (void)UclILSched_NotifyMessageUpdate(0u, Tx_UclPowerDomainReqMsg_Index, PowerExtendShutdownTime_UclPowerDomainReqMsg_Index, NULL, 0u);
            (void)UclILSched_NotifyMessageUpdate(0u, Tx_UclPowerDomainReqMsg_Index, PowerKeepSystemAwake_UclPowerDomainReqMsg_Index, NULL, 0u);
            break;

        case UclHealthHeartBeatMsg_DID:

            // Scheduler notification for queued and nonperiodic messages
            (void)UclILSched_NotifyMessageUpdate(0u, Tx_UclHealthHeartBeatMsg_Index, HealthDomainHeartbeat_UclHealthHeartBeatMsg_Index, NULL, 0u);
            break;

        case UclHealthErrorMsg_DID:

            // Scheduler notification for queued and nonperiodic messages
            (void)UclILSched_NotifyMessageUpdate(0u, Tx_UclHealthErrorMsg_Index, HealthDomainFatalError_UclHealthErrorMsg_Index, NULL, 0u);
            break;

        case UclHealthEeventMsg_DID:

            // Scheduler notification for queued and nonperiodic messages
            (void)UclILSched_NotifyMessageUpdate(0u, Tx_UclHealthEeventMsg_Index, HealthEventRecord_UclHealthEeventMsg_Index, NULL, 0u);
            break;

        case UclHealthDumpDataMsg_DID:

            // Scheduler notification for queued and nonperiodic messages
            (void)UclILSched_NotifyMessageUpdate(0u, Tx_UclHealthDumpDataMsg_Index, HealthDumpHdrInfo_UclHealthDumpDataMsg_Index, NULL, 0u);
            (void)UclILSched_NotifyMessageUpdate(0u, Tx_UclHealthDumpDataMsg_Index, HealthDumpData_UclHealthDumpDataMsg_Index, NULL, 0u);
            break;

        case UclSubSystemStatus_DID:

            // Scheduler notification for queued and nonperiodic messages
            (void)UclILSched_NotifyMessageUpdate(0u, Tx_UclSubSystemStatus_Index, SafeHMIReadyStatus_UclSubSystemStatus_Index, NULL, 0u);
            (void)UclILSched_NotifyMessageUpdate(0u, Tx_UclSubSystemStatus_Index, MainHMIReadyStatus_UclSubSystemStatus_Index, NULL, 0u);
            break;

        case UpdateShortServiceResp_DID:

            // Scheduler notification for queued and nonperiodic messages
            (void)UclILSched_NotifyMessageUpdate(0u, Tx_UpdateShortServiceResp_Index, UpdateShortServiceResp_UpdateShortServiceResp_Index, NULL, 0u);
            break;

        case UclDiagResponse_DID:

            // Scheduler notification for queued and nonperiodic messages
            (void)UclILSched_NotifyMessageUpdate(0u, Tx_UclDiagResponse_Index, DiagResponse_UclDiagResponse_Index, NULL, 0u);
            break;
    }
}

void UclGen_Adapter_ReceiveMissingStatus(uint16 MsgId, sint32 Status) 
{
    LOGI(0u, "UclGen", "ReceiveMissingStatus 0x%02x, %d", MsgId, Status);
    switch (MsgId)
    {
    }
}

