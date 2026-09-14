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
#ifndef UCLGEN_ASRADAPTER_H
#define UCLGEN_ASRADAPTER_H

#ifdef __cplusplus
extern "C"
{
#endif

//---------------------------------------------------------------------------------------
// Transmit Deployments IDs
//---------------------------------------------------------------------------------------
#define UclPowerDomainStateReqMsg_DID    ((uint16)1u)
#define UclHealthDumpGetMsg_DID    ((uint16)2u)
#define UclDisplaySetPower_DID    ((uint16)3u)
#define UclTelltaleStatusMsg_DID    ((uint16)4u)
#define UclWarningDisplayMsg_DID    ((uint16)5u)
#define UclSlowGaugeMsg_DID    ((uint16)6u)
#define UclFastGuageCustomMsg_DID    ((uint16)7u)
#define UclShitPositionIndicatorMsg_DID    ((uint16)8u)
#define UclIlluminationDataMsg_DID    ((uint16)9u)
#define UpdateShortServiceReq_DID    ((uint16)10u)
#define UpdateLongServiceReq_DID    ((uint16)11u)
#define UclDiagRequest_DID    ((uint16)12u)
#define UclDLTMessageReadRequest_DID    ((uint16)13u)
#define UclDLTControlMessageReponse_DID    ((uint16)14u)

//---------------------------------------------------------------------------------------
// Receive Deployments IDs
//---------------------------------------------------------------------------------------
#define UclPowerDomainStateMsg_DID    ((uint16)1u)
#define UclPowerDomainReqMsg_DID    ((uint16)2u)
#define UclHealthHeartBeatMsg_DID    ((uint16)3u)
#define UclHealthErrorMsg_DID    ((uint16)4u)
#define UclHealthEeventMsg_DID    ((uint16)5u)
#define UclHealthDumpDataMsg_DID    ((uint16)6u)
#define UclDisplayCurrentState_DID    ((uint16)7u)
#define UclEmmcErrorNotifierMsg_DID    ((uint16)8u)
#define UclWarningStatusMsg_DID    ((uint16)9u)
#define UclSubSystemStatus_DID    ((uint16)10u)
#define UpdateShortServiceResp_DID    ((uint16)11u)
#define UclDiagResponse_DID    ((uint16)12u)
#define UclDLTMessageReadAck_DID    ((uint16)13u)
#define UclDLTControlMessageRequest_DID    ((uint16)14u)

//---------------------------------------------------------------------------------------
// Messages IDs
//---------------------------------------------------------------------------------------
#define DLTControlMessageReponse_MID    ((uint16)0x8901u)
#define DLTControlMessageRequest_MID    ((uint16)0x8A01u)
#define DLTMessageReadAck_MID    ((uint16)0x8A00u)
#define DLTMessageReadRequest_MID    ((uint16)0x8900u)
#define DiagDIDRequest_MID    ((uint16)0x6901u)
#define DiagIOCtrlRequest_MID    ((uint16)0x6903u)
#define DiagResponse_MID    ((uint16)0x6904u)
#define DiagRoutineRequest_MID    ((uint16)0x6902u)
#define DisplayCurrentState_MID    ((uint16)0x3F00u)
#define DisplaySetPower_MID    ((uint16)0x3E00u)
#define EmmcErrorNotifier_MID    ((uint16)0xE303u)
#define FRTT_Status_MID    ((uint16)0x3502u)
#define FastGaugeInfo_MID    ((uint16)0x3601u)
#define HealthDomainFatalError_MID    ((uint16)0xE301u)
#define HealthDomainHeartbeat_MID    ((uint16)0xE300u)
#define HealthDumpData_MID    ((uint16)0xE201u)
#define HealthDumpGetData_MID    ((uint16)0xE101u)
#define HealthDumpGetHdr_MID    ((uint16)0xE100u)
#define HealthDumpHdrInfo_MID    ((uint16)0xE200u)
#define HealthEventRecord_MID    ((uint16)0xE302u)
#define IlluminationData_MID    ((uint16)0x5600u)
#define MainHMIReadyStatus_MID    ((uint16)0x4300u)
#define PowerExtendShutdownTime_MID    ((uint16)0xC001u)
#define PowerKeepSystemAwake_MID    ((uint16)0xC002u)

#define PowerSystemState_MID    ((uint16)0xC000u)
#define PowerSystemStateReqChange_MID    ((uint16)0xC100u)

#define RTT_Icon_MID    ((uint16)0x3504u)
#define RTT_Status_MID    ((uint16)0x3501u)
#define RTT_Toggle_MID    ((uint16)0x3503u)
#define SafeHMIReadyStatus_MID    ((uint16)0x4301u)
#define ShiftPosIndStatus_MID    ((uint16)0x6900u)
#define SlowGaugeInfo_MID    ((uint16)0x3600u)
#define TT_Status_MID    ((uint16)0x3500u)
#define UclErrorNotify_MID    ((uint16)0xE001u)
#define UclLinkStatus_MID    ((uint16)0xE000u)
#define UpdateLongServiceReq_MID    ((uint16)0xBE01u)
#define UpdateShortServiceReq_MID    ((uint16)0xBE00u)
#define UpdateShortServiceResp_MID    ((uint16)0xBF02u)
#define WarningDisplay_MID    ((uint16)0x3300u)
#define WarningDisplayAvailable_MID    ((uint16)0x3401u)
#define WarningExtDisplay_MID    ((uint16)0x3301u)
#define WarningStatus_MID    ((uint16)0x3400u)

//---------------------------------------------------------------------------------------
// Sizes of serialized message types
//---------------------------------------------------------------------------------------
#define PowerSystemState_BufferSize    ((uint16)2u)
#define PowerSystemState_BufferSizeWithSignalIds    ((uint16)(PowerSystemState_BufferSize + 2u))
#define PowerExtendShutdownTime_BufferSize    ((uint16)5u)
#define PowerExtendShutdownTime_BufferSizeWithSignalIds    ((uint16)(PowerExtendShutdownTime_BufferSize + 2u))
#define PowerKeepSystemAwake_BufferSize    ((uint16)5u)
#define PowerKeepSystemAwake_BufferSizeWithSignalIds    ((uint16)(PowerKeepSystemAwake_BufferSize + 2u))
#define HealthDomainHeartbeat_BufferSize    ((uint16)5u)
#define HealthDomainHeartbeat_BufferSizeWithSignalIds    ((uint16)(HealthDomainHeartbeat_BufferSize + 2u))
#define HealthDomainFatalError_BufferSize    ((uint16)5u)
#define HealthDomainFatalError_BufferSizeWithSignalIds    ((uint16)(HealthDomainFatalError_BufferSize + 2u))
#define HealthEventRecord_BufferSize    ((uint16)10u)
#define HealthEventRecord_BufferSizeWithSignalIds    ((uint16)(HealthEventRecord_BufferSize + 3u))
#define HealthDumpHdrInfo_BufferSize    ((uint16)4u)
#define HealthDumpHdrInfo_BufferSizeWithSignalIds    ((uint16)(HealthDumpHdrInfo_BufferSize + 1u))
#define HealthDumpData_BufferSize    ((uint16)36u)
#define HealthDumpData_BufferSizeWithSignalIds    ((uint16)(HealthDumpData_BufferSize + 2u))
#define DisplayCurrentState_BufferSize    ((uint16)5u)
#define DisplayCurrentState_BufferSizeWithSignalIds    ((uint16)(DisplayCurrentState_BufferSize + 2u))
#define EmmcErrorNotifier_BufferSize    ((uint16)4u)
#define EmmcErrorNotifier_BufferSizeWithSignalIds    ((uint16)(EmmcErrorNotifier_BufferSize + 1u))
#define WarningDisplayAvailable_BufferSize    ((uint16)1u)
#define WarningDisplayAvailable_BufferSizeWithSignalIds    ((uint16)(WarningDisplayAvailable_BufferSize + 1u))
#define WarningStatus_BufferSize    ((uint16)13u)
#define WarningStatus_BufferSizeWithSignalIds    ((uint16)(WarningStatus_BufferSize + 3u))
#define SafeHMIReadyStatus_BufferSize    ((uint16)1u)
#define SafeHMIReadyStatus_BufferSizeWithSignalIds    ((uint16)(SafeHMIReadyStatus_BufferSize + 1u))
#define MainHMIReadyStatus_BufferSize    ((uint16)1u)
#define MainHMIReadyStatus_BufferSizeWithSignalIds    ((uint16)(MainHMIReadyStatus_BufferSize + 1u))
#define UpdateShortServiceResp_BufferSize    ((uint16)73u)
#define UpdateShortServiceResp_BufferSizeWithSignalIds    ((uint16)(UpdateShortServiceResp_BufferSize + 7u))
#define DiagResponse_BufferSize    ((uint16)259u)
#define DiagResponse_BufferSizeWithSignalIds    ((uint16)(DiagResponse_BufferSize + 3u))
#define DLTMessageReadAck_BufferSize    ((uint16)2u)
#define DLTMessageReadAck_BufferSizeWithSignalIds    ((uint16)(DLTMessageReadAck_BufferSize + 1u))
#define DLTControlMessageRequest_BufferSize    ((uint16)2u)
#define DLTControlMessageRequest_BufferSizeWithSignalIds    ((uint16)(DLTControlMessageRequest_BufferSize + 1u))
#define PowerSystemStateReqChange_BufferSize    ((uint16)2u)
#define PowerSystemStateReqChange_BufferSizeWithSignalIds    ((uint16)(PowerSystemStateReqChange_BufferSize + 2u))
#define HealthDumpGetHdr_BufferSize    ((uint16)1u)
#define HealthDumpGetHdr_BufferSizeWithSignalIds    ((uint16)(HealthDumpGetHdr_BufferSize + 1u))
#define HealthDumpGetData_BufferSize    ((uint16)1u)
#define HealthDumpGetData_BufferSizeWithSignalIds    ((uint16)(HealthDumpGetData_BufferSize + 1u))
#define DisplaySetPower_BufferSize    ((uint16)5u)
#define DisplaySetPower_BufferSizeWithSignalIds    ((uint16)(DisplaySetPower_BufferSize + 2u))
#define TT_Status_BufferSize    ((uint16)15u)
#define TT_Status_BufferSizeWithSignalIds    ((uint16)(TT_Status_BufferSize + 1u))
#define RTT_Toggle_BufferSize    ((uint16)2u)
#define RTT_Toggle_BufferSizeWithSignalIds    ((uint16)(RTT_Toggle_BufferSize + 2u))
#define FRTT_Status_BufferSize    ((uint16)2u)
#define FRTT_Status_BufferSizeWithSignalIds    ((uint16)(FRTT_Status_BufferSize + 1u))
#define RTT_Icon_BufferSize    ((uint16)2u)
#define RTT_Icon_BufferSizeWithSignalIds    ((uint16)(RTT_Icon_BufferSize + 1u))
#define RTT_Status_BufferSize    ((uint16)2u)
#define RTT_Status_BufferSizeWithSignalIds    ((uint16)(RTT_Status_BufferSize + 1u))
#define WarningExtDisplay_BufferSize    ((uint16)11u)
#define WarningExtDisplay_BufferSizeWithSignalIds    ((uint16)(WarningExtDisplay_BufferSize + 3u))
#define WarningDisplay_BufferSize    ((uint16)11u)
#define WarningDisplay_BufferSizeWithSignalIds    ((uint16)(WarningDisplay_BufferSize + 3u))
#define SlowGaugeInfo_BufferSize    ((uint16)20u)
#define SlowGaugeInfo_BufferSizeWithSignalIds    ((uint16)(SlowGaugeInfo_BufferSize + 1u))
#define FastGaugeInfo_BufferSize    ((uint16)36u)
#define FastGaugeInfo_BufferSizeWithSignalIds    ((uint16)(FastGaugeInfo_BufferSize + 1u))
#define ShiftPosIndStatus_BufferSize    ((uint16)6u)
#define ShiftPosIndStatus_BufferSizeWithSignalIds    ((uint16)(ShiftPosIndStatus_BufferSize + 1u))
#define IlluminationData_BufferSize    ((uint16)4u)
#define IlluminationData_BufferSizeWithSignalIds    ((uint16)(IlluminationData_BufferSize + 4u))
#define UpdateShortServiceReq_BufferSize    ((uint16)75u)
#define UpdateShortServiceReq_BufferSizeWithSignalIds    ((uint16)(UpdateShortServiceReq_BufferSize + 7u))
#define UpdateLongServiceReq_BufferSize    ((uint16)523u)
#define UpdateLongServiceReq_BufferSizeWithSignalIds    ((uint16)(UpdateLongServiceReq_BufferSize + 7u))
#define DiagDIDRequest_BufferSize    ((uint16)261u)
#define DiagDIDRequest_BufferSizeWithSignalIds    ((uint16)(DiagDIDRequest_BufferSize + 4u))
#define DiagIOCtrlRequest_BufferSize    ((uint16)261u)
#define DiagIOCtrlRequest_BufferSizeWithSignalIds    ((uint16)(DiagIOCtrlRequest_BufferSize + 4u))
#define DiagRoutineRequest_BufferSize    ((uint16)261u)
#define DiagRoutineRequest_BufferSizeWithSignalIds    ((uint16)(DiagRoutineRequest_BufferSize + 4u))
#define DLTMessageReadRequest_BufferSize    ((uint16)2u)
#define DLTMessageReadRequest_BufferSizeWithSignalIds    ((uint16)(DLTMessageReadRequest_BufferSize + 1u))
#define DLTControlMessageReponse_BufferSize    ((uint16)2u)
#define DLTControlMessageReponse_BufferSizeWithSignalIds    ((uint16)(DLTControlMessageReponse_BufferSize + 1u))

//---------------------------------------------------------------------------------------
// Rx DB call-outs
//---------------------------------------------------------------------------------------
uint8 UclGen_Send_PowerSystemState(uint8 *pMsgBuff, uint16 Size);
uint8 UclGen_Send_PowerExtendShutdownTime(uint8 *pMsgBuff, uint16 Size);
uint8 UclGen_Send_PowerKeepSystemAwake(uint8 *pMsgBuff, uint16 Size);

uint8 UclGen_Send_HealthDomainHeartbeat(uint8 *pMsgBuff, uint16 Size);
uint8 UclGen_Send_HealthDomainFatalError(uint8 *pMsgBuff, uint16 Size);
uint8 UclGen_Send_HealthEventRecord(uint8 *pMsgBuff, uint16 Size);
uint8 UclGen_Send_HealthDumpHdrInfo(uint8 *pMsgBuff, uint16 Size);
uint8 UclGen_Send_HealthDumpData(uint8 *pMsgBuff, uint16 Size);
uint8 UclGen_Send_DisplayCurrentState(uint8 *pMsgBuff, uint16 Size);
uint8 UclGen_Send_EmmcErrorNotifier(uint8 *pMsgBuff, uint16 Size);
uint8 UclGen_Send_WarningDisplayAvailable(uint8 *pMsgBuff, uint16 Size);
uint8 UclGen_Send_WarningStatus(uint8 *pMsgBuff, uint16 Size);
uint8 UclGen_Send_SafeHMIReadyStatus(uint8 *pMsgBuff, uint16 Size);
uint8 UclGen_Send_MainHMIReadyStatus(uint8 *pMsgBuff, uint16 Size);
uint8 UclGen_Send_UpdateShortServiceResp(uint8 *pMsgBuff, uint16 Size);
uint8 UclGen_Send_DiagResponse(uint8 *pMsgBuff, uint16 Size);
uint8 UclGen_Send_DLTMessageReadAck(uint8 *pMsgBuff, uint16 Size);
uint8 UclGen_Send_DLTControlMessageRequest(uint8 *pMsgBuff, uint16 Size);

//---------------------------------------------------------------------------------------
// Tx DB call-outs
//---------------------------------------------------------------------------------------
uint8 UclGen_Read_PowerSystemStateReqChange(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType);
uint8 UclGen_Read_HealthDumpGetHdr(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType);
uint8 UclGen_Read_HealthDumpGetData(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType);
uint8 UclGen_Read_DisplaySetPower(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType);
uint8 UclGen_Read_TT_Status(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType);
uint8 UclGen_Read_RTT_Toggle(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType);
uint8 UclGen_Read_FRTT_Status(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType);
uint8 UclGen_Read_RTT_Icon(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType);
uint8 UclGen_Read_RTT_Status(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType);
uint8 UclGen_Read_WarningExtDisplay(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType);
uint8 UclGen_Read_WarningDisplay(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType);
uint8 UclGen_Read_SlowGaugeInfo(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType);
uint8 UclGen_Read_FastGaugeInfo(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType);
uint8 UclGen_Read_ShiftPosIndStatus(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType);
uint8 UclGen_Read_IlluminationData(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType);
uint8 UclGen_Read_UpdateShortServiceReq(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType);
uint8 UclGen_Read_UpdateLongServiceReq(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType);
uint8 UclGen_Read_DiagDIDRequest(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType);
uint8 UclGen_Read_DiagIOCtrlRequest(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType);
uint8 UclGen_Read_DiagRoutineRequest(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType);
uint8 UclGen_Read_DLTMessageReadRequest(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType);
uint8 UclGen_Read_DLTControlMessageReponse(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType);

//---------------------------------------------------------------------------------------
// Tx DB size
//---------------------------------------------------------------------------------------
#define UclILMsgDbTx_Size    14u

//---------------------------------------------------------------------------------------
// Rx DB size
//---------------------------------------------------------------------------------------
#define UclILMsgDbRx_Size    14u


#ifdef __cplusplus
}
#endif

#endif //UCLGEN_ASRADAPTER_H

