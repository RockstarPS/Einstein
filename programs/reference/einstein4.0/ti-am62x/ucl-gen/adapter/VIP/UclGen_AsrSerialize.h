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
#ifndef UCLGEN_ASRSERIALIZE_H
#define UCLGEN_ASRSERIALIZE_H

#ifdef __cplusplus
extern "C"
{
#endif


Ucl_ReturnType UclCmnSerialize_SPowerSystemStateReqChange( SPowerSystemStateReqChange *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnSerialize_SDisplaySetPower( SDisplaySetPower *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnSerialize_data_u8_15( data_u8_15 data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnSerialize_SRTT_Toggle( SRTT_Toggle *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnSerialize_data_u8_2( data_u8_2 data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnSerialize_SWarningExtDisplay( SWarningExtDisplay *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnSerialize_data_u8_8( data_u8_8 data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnSerialize_SWarningDisplay( SWarningDisplay *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnSerialize_SGaugeInfo_2( SGaugeInfo_2 data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnSerialize_SGaugeInfo( SGaugeInfo *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnSerialize_SGaugeInfo_u32dyn_3( SGaugeInfo_u32dyn_3 data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnSerialize_SGaugeInfo_u32dyn( SGaugeInfo_u32dyn *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnSerialize_SShiftInd( SShiftInd *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnSerialize_SIlluminationData( SIlluminationData *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnSerialize_SUpdateShortServiceReq( SUpdateShortServiceReq *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnSerialize_data_u8_64( data_u8_64 data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnSerialize_SUpdateLongServiceReq( SUpdateLongServiceReq *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnSerialize_data_u8_2048( data_u8_2048 data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnSerialize_SDiagDIDRequest( SDiagDIDRequest *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnSerialize_data_u8_256( data_u8_256 data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnSerialize_SDiagIOCtrlRequest( SDiagIOCtrlRequest *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnSerialize_SDiagRoutineRequest( SDiagRoutineRequest *data, uint8 *pBuffer, uint16 *pBytesCopied );


Ucl_ReturnType UclCmnDeserialize_SPowerSystemState( SPowerSystemState *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnDeserialize_SPowerExtendShutdownTime( SPowerExtendShutdownTime *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnDeserialize_SPowerKeepSystemAwake( SPowerKeepSystemAwake *data, uint8 *pBuffer, uint16 *pBytesCopied );


Ucl_ReturnType UclCmnDeserialize_SHealthDomainHeartbeat( SHealthDomainHeartbeat *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnDeserialize_SHealthDomainFatalError( SHealthDomainFatalError *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnDeserialize_SHealthEventRecord( SHealthEventRecord *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnDeserialize_data_u8_8( data_u8_8 *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnDeserialize_SHealthDumpData( SHealthDumpData *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnDeserialize_data_u8_32( data_u8_32 *data, uint8 *pBuffer, uint16 *pBytesCopied );


Ucl_ReturnType UclCmnDeserialize_data_u8_256( data_u8_256 *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnDeserialize_SDisplayCurrentState( SDisplayCurrentState *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnDeserialize_SWarningStatus( SWarningStatus *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnDeserialize_data_u8_10( data_u8_10 *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnDeserialize_SUpdateShortServiceResp( SUpdateShortServiceResp *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnDeserialize_data_u8_64( data_u8_64 *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnDeserialize_SDiagResponse( SDiagResponse *data, uint8 *pBuffer, uint16 *pBytesCopied );

Ucl_ReturnType UclCmnDeserialize_data_u8_2( data_u8_2 *data, uint8 *pBuffer, uint16 *pBytesCopied );


#ifdef __cplusplus
}
#endif

#endif //UCLGEN_ASRSERIALIZE_H

