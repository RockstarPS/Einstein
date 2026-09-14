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
#ifndef UCLGEN_VMFADAPTER_H
#define UCLGEN_VMFADAPTER_H

#ifdef __cplusplus
extern "C"
{
#endif

//---------------------------------------------------------------------------------------
// Transmit Deployments IDs
//---------------------------------------------------------------------------------------
#define UpdateShortServiceResp_DID    ((uint16)1u)

//---------------------------------------------------------------------------------------
// Receive Deployments IDs
//---------------------------------------------------------------------------------------
#define UpdateShortServiceReq_DID    ((uint16)1u)
#define UpdateLongServiceReq_DID    ((uint16)2u)

//---------------------------------------------------------------------------------------
// Messages IDs
//---------------------------------------------------------------------------------------
#define UpdateLongServiceReq_MID    ((uint16)0xBE01u)
#define UpdateShortServiceReq_MID    ((uint16)0xBE00u)
#define UpdateShortServiceResp_MID    ((uint16)0xBF02u)

//---------------------------------------------------------------------------------------
// Sizes of serialized message types
//---------------------------------------------------------------------------------------
#define UpdateShortServiceReq_BufferSize    ((uint16)75u)
#define UpdateShortServiceReq_BufferSizeWithSignalIds    ((uint16)(UpdateShortServiceReq_BufferSize + 7u))
#define UpdateLongServiceReq_BufferSize    ((uint16)2059u)
#define UpdateLongServiceReq_BufferSizeWithSignalIds    ((uint16)(UpdateLongServiceReq_BufferSize + 7u))
#define UpdateShortServiceResp_BufferSize    ((uint16)73u)
#define UpdateShortServiceResp_BufferSizeWithSignalIds    ((uint16)(UpdateShortServiceResp_BufferSize + 7u))

//---------------------------------------------------------------------------------------
// Rx DB call-outs
//---------------------------------------------------------------------------------------
uint8 UclGen_Send_UpdateShortServiceReq(uint8 *pMsgBuff, uint16 Size);
uint8 UclGen_Send_UpdateLongServiceReq(uint8 *pMsgBuff, uint16 Size);

//---------------------------------------------------------------------------------------
// Tx DB call-outs
//---------------------------------------------------------------------------------------
uint8 UclGen_Read_UpdateShortServiceResp(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType);

//---------------------------------------------------------------------------------------
// Tx DB size
//---------------------------------------------------------------------------------------
#define UclILMsgDbTx_Size    1u

//---------------------------------------------------------------------------------------
// Rx DB size
//---------------------------------------------------------------------------------------
#define UclILMsgDbRx_Size    2u

#define UclVmfMsgQueueCount 0u

#ifdef __cplusplus
}
#endif

#endif //UCLGEN_VMFADAPTER_H

