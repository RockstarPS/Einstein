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

#ifndef UPD_GenDecoder_H
#define UPD_GenDecoder_H

#include "UPDi_AbstractInstaller.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

struct sUPDiGenDecoder;
typedef Std_ReturnType (*tpfGenDecoder_Start)(const struct sUPDiGenDecoder* This, tUPDiInstallSession* pSession, const char* PackageName, uint32_t Size);
typedef Std_ReturnType (*tpfGenDecoder_Exit)(const struct sUPDiGenDecoder* this, tUPDiInstallSession* pSession);
typedef Std_ReturnType(*tpfGenDecoder_Process)(const struct sUPDiGenDecoder* this, tUPDiInstallSession* pSession);
typedef Std_ReturnType(*tpfGenDecoder_Transform)(const struct sUPDiGenDecoder* this, uint8_t* Data, uint32_t* pSize, uint8_t** ppTransformBuffer, uint32_t* pTransformSize);

typedef const struct sUPDiGenDecoder_Vtbl
{
    // From AbstractInstaller
    tpfGetExtension GetExtension;
    tpfInstallStart InstallStart;
    tpfInstallData InstallData;
    tpfInstallExit InstallExit;
    tpfSerialize Serialize;
    tpfDeserialize Deserialize;
    tpfRewind Rewind;
    // From GenDecoder
    tpfGenDecoder_Start DecoderStart;
    tpfGenDecoder_Process DecoderProcess;
    tpfGenDecoder_Exit DecoderExit;
    tpfGenDecoder_Transform Transform;
} tUPDiGenDecoder_Vtbl;

typedef enum
{
    eGenIdle,
    eGenReady,
    eGenLoading,
    eGenLoadingStream,
	eGenLoadingFilteringStream,
    eGenInstallingChild,
    eGenTransformingToChild,
    eGenStartInstallingChild,
    eGenStartTransformingToChild,
    eGenExitInstallingChild,
    eGenExitTransformingToChild,
    eGenNotifyngChild,
    eGenBusy,
    eGenFailed
} tUPDiGenDecoderState;

typedef struct 
{ 
    // From AbstractInstaller
    uint32_t NextByte; // next byte to be installed
    // From GenDecoder
    tUPDiAbstractInstaller* pChild;
    tUPDdPackageName PackageName;
    tUPDdPackageName ChildPackageName;
    tUPDiGenDecoderState State;
    uint32_t Processed;
    uint32_t ToProcess;
    uint32_t ChunkSize;
    uint32_t ResumeAt;
    uint8_t LoadBuffer[UPDd_LOAD_BUFFER_SIZE];
    uint8_t* pTransformBuffer;
    uint32_t OutSizeProcessed;
} tUPDiGenDecoderRam;

typedef const struct sUPDiGenDecoder
{ 
    tUPDiGenDecoder_Vtbl* Vtbl;
    tUPDiGenDecoderRam* pRam;
} tUPDiGenDecoder;

//=====================================================================================================================
//  Interface
//=====================================================================================================================

// from Abstract installer
void  UPDiGenDecoder_Init(tUPDiGenDecoder* This);
Std_ReturnType UPDiGenDecoder_InstallStart(tUPDiGenDecoder* This, tUPDiInstallSession* pSession, const char* PackageName, uint32_t Size);
Std_ReturnType UPDiGenDecoder_InstallData(tUPDiGenDecoder* This, tUPDiInstallSession* pSession, uint8_t* Data, uint32_t Size);
Std_ReturnType UPDiGenDecoder_InstallExit(tUPDiGenDecoder* This, tUPDiInstallSession* pSession);
Std_ReturnType UPDiGenDecoder_Serialize(tUPDiGenDecoder* This, tUPDStream *pStream);
Std_ReturnType UPDiGenDecoder_DeSerialize(tUPDiGenDecoder* This, tUPDStream *pStream);

// Specific class method
void UPDiGenDecoder_Install(tUPDiGenDecoder* This, const char* PackageName, uint32_t Size);
void UPDiGenDecoder_Load(tUPDiGenDecoder* This, uint32_t Size);// load the requested ammount of data in cache, max size is limited by the cache
void UPDiGenDecoder_LoadStream(tUPDiGenDecoder* This, uint32_t Size); // load data by chunk, size is unlimited
void UPDiGenDecoder_LoadFilterStream(tUPDiGenDecoder* This, uint32_t Size); // load data by chunk, size is unlimited
void UPDiGenDecoder_Transform(tUPDiGenDecoder* This, uint32_t Size);


//=====================================================================================================================
//  VTB>L
//=====================================================================================================================
// No VTBL, class is abstract

#endif 
