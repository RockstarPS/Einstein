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
#ifndef UCLGEN_ASRSERIALIZE_H
#define UCLGEN_ASRSERIALIZE_H

#ifdef __cplusplus
extern "C"
{
#endif


Ucl_ReturnType UclCmnSerialize_SUpdateShortServiceReq( SUpdateShortServiceReq *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnSerialize_data_u8_64( data_u8_64 data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnSerialize_SUpdateLongServiceReq( SUpdateLongServiceReq *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnSerialize_data_u8_2048( data_u8_2048 data, uint8 *pBuffer, uint16 *pBytesCopied );


Ucl_ReturnType UclCmnDeserialize_SUpdateShortServiceResp( SUpdateShortServiceResp *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnDeserialize_data_u8_64( data_u8_64 *data, uint8 *pBuffer, uint16 *pBytesCopied );


#ifdef __cplusplus
}
#endif

#endif //UCLGEN_ASRSERIALIZE_H

