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
#ifndef UPD_VdtDecoder_H_
#define UPD_VdtDecoder_H_

#include "UPDi_GenDecoder.h"
#include "UPDi_Session.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

typedef enum
{
    eVdtLoadingHeader,
    eVdtLoadingControlBlock,
    eVdtLoadingComposedBlock,
    eVdtLoadingExtraBlock,
    eVdtDone,
} tUPDiVdtDecoderState;

typedef enum
{
	eVdtExpandingNonZero,
	eVdtExpandingInt,
	eVdtExpandingZero
} tUPDiVdtFilteringState;

typedef struct
{ 
    tUPDiGenDecoderRam Parent;// shall be first
    tUPDiVdtDecoderState State;
    uint32_t LastWritePos; // Size of the output image
    uint32_t WritePos; // Curent Write pointer
    int32_t ReadPos; // Curent Write pointer
    uint32_t ComposedSectionSize; // form the last control block
    uint32_t ExtraSectionSize;// form the last control block
    uint32_t SkipedSectionSize;// form the last control block
    uint64_t PackedInt;
    uint8_t  Shift;
    uint8_t  EndMarker;
    tUPDiVdtFilteringState TransformState;
} tUPDiVdtDecoderRam;

typedef const struct 
{ 
    tUPDiGenDecoder_Vtbl* Vtbl;
    tUPDiVdtDecoderRam* pRam;
} tUPDiVdtDecoder;

//=====================================================================================================================
//  Interface
//=====================================================================================================================
const char*    UPDiVdtDecoder_GetExtension(tUPDiVdtDecoder* This);
Std_ReturnType UPDiVdtDecoder_Start(tUPDiVdtDecoder* This, tUPDiInstallSession* pSession, const char* PackageName, uint32_t Size);
Std_ReturnType UPDiVdtDecoder_Exit(tUPDiVdtDecoder* This, tUPDiInstallSession* pSession);
Std_ReturnType UPDiVdtDecoder_Process(tUPDiVdtDecoder* This, tUPDiInstallSession* pSession);
Std_ReturnType UPDiVdtDecoder_InstallStart(tUPDiVdtDecoder* This, tUPDiInstallSession* pSession, const char* PackageName, uint32_t Size);
Std_ReturnType UPDiVdtDecoder_InstallExit(tUPDiVdtDecoder* This, tUPDiInstallSession* pSession);
Std_ReturnType UPDiVdtDecoder_Serialize(tUPDiVdtDecoder* This, tUPDStream *pStream);
Std_ReturnType UPDiVdtDecoder_Deserialize(tUPDiVdtDecoder* This, tUPDStream *pStream);
Std_ReturnType UPDiVdtDecoder_Transform(tUPDiVdtDecoder* This, uint8_t* pDataIn, uint32_t* pSizeIn, uint8_t** ppDataOut, uint32_t* pOutSize);

//=====================================================================================================================
//  VTBL
//=====================================================================================================================
extern tUPDiGenDecoder_Vtbl UPDVdtDecoder_Vtbl;

#endif 
