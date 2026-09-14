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
#ifndef UPD_DeltaDecoder_H_
#define UPD_DeltaDecoder_H_

#include "UPDi_GenDecoder.h"
#include "UPDi_Session.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

typedef enum
{
    eDeltaLoadingHeader,
    eDeltaLoadingControlBlock,
    eDeltaLoadingComposedBlock,
    eDeltaLoadingExtraBlock,
    eDeltaDone,
} tUPDiDeltaDecoderState;

typedef struct __attribute__((packed)) sDiffHeader
{
    char FileTypeIdent[16];
    uint32_t NewSize;
    uint32_t NewSize_HIGH;
} tUPDiDeltaHeader;

typedef struct __attribute__((packed)) sDeltaControl
{
    uint32_t ComposedSectionSize;
    uint32_t ComposedSectionSize_HIGH;
    uint32_t ExtraSectionSize;
    uint32_t ExtraSectionSize_HIGH;
    int32_t SkipedSectionSize; //can be negative
    int32_t SkipedSectionSize_HIGH;
} tUPDiDeltaControl;

typedef struct 
{ 
    tUPDiGenDecoderRam Parent;// shall be first
    tUPDiDeltaDecoderState State;
    uint32_t LastWritePos; // Size of the output image
    uint32_t WritePos; // Curent Write pointer
    int32_t ReadPos; // Curent Write pointer
    uint32_t ComposedSectionSize; // form the last control block
    uint32_t ExtraSectionSize;// form the last control block
    uint32_t SkipedSectionSize;// form the last control block
} tUPDiDeltaDecoderRam;

typedef const struct 
{ 
    tUPDiGenDecoder_Vtbl* Vtbl;
    tUPDiDeltaDecoderRam* pRam;
} tUPDiDeltaDecoder;

//=====================================================================================================================
//  Interface
//=====================================================================================================================
const char*    UPDiDeltaDecoder_GetExtension(tUPDiDeltaDecoder* This);
Std_ReturnType UPDiDeltaDecoder_Start(tUPDiDeltaDecoder* This, tUPDiInstallSession* pSession, const char* PackageName, uint32_t Size);
Std_ReturnType UPDiDeltaDecoder_Exit(tUPDiDeltaDecoder* This, tUPDiInstallSession* pSession);
Std_ReturnType UPDiDeltaDecoder_Process(tUPDiDeltaDecoder* This, tUPDiInstallSession* pSession);
Std_ReturnType UPDiDeltaDecoder_InstallStart(tUPDiDeltaDecoder* This, tUPDiInstallSession* pSession, const char* PackageName, uint32_t Size);
Std_ReturnType UPDiDeltaDecoder_InstallExit(tUPDiDeltaDecoder* This, tUPDiInstallSession* pSession);
Std_ReturnType UPDiDeltaDecoder_Serialize(tUPDiDeltaDecoder* This, tUPDStream *pStream);
Std_ReturnType UPDiDeltaDecoder_Deserialize(tUPDiDeltaDecoder* This, tUPDStream *pStream);

//=====================================================================================================================
//  VTBL
//=====================================================================================================================
extern tUPDiGenDecoder_Vtbl UPDDeltaDecoder_Vtbl;

#endif 
