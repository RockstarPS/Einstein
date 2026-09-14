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
#ifndef UPD_LzmaDecoder_H
#define UPD_LzmaDecoder_H

#include "UPDi_GenDecoder.h"
#include "LzmaDec.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

typedef uint8_t tUPDiLzmaPoolBuffer[UPDd_LZMA_MEMORY_POOL_SIZE];
typedef uint8_t tUPDiLzmaDecoderBuffer[UPDd_LOAD_BUFFER_SIZE];

typedef enum
{
    eLzmaLoadingHeader,
    eLzmaDecompressing,
    eLzmaDone,
} tUPDiLzmaDecoderState;

typedef struct __attribute__((packed))
{
    uint8_t Props[LZMA_PROPS_SIZE];
    uint8_t Size[sizeof(uint64_t)];
}  tUPDiLzmaHeader;

typedef struct
{
    uint8_t* Buffer;
    uint32_t Size;
    uint32_t Used;
}  tUPDiLzmaMemoryPool;

typedef struct stUPDiLzmaDecoder
{
    tUPDiGenDecoderRam Parent;
    //tUPDiAbstractInstaller* Child;
    //tUPDdPackageName ChildPackageName;
    //tUPDiLzmaHeader Header;
    tUPDiLzmaPoolBuffer PoolBuffer;
    tUPDiLzmaDecoderBuffer Buffer;
    uint32_t BufferPos; // Size curently used in the buffer
    CLzmaDec Decoder;
    tUPDiLzmaDecoderState State;
    uint32_t UncompressedSize;
    uint32_t UncompressedSize_HIGH;
    //uint32_t SizeProcessed;// Compressed size processed 
    //uint32_t OutputSizeProcessed; // Global uncompressed size
} tUPDiLzmaDecoderRam;

typedef const struct sUPDiLzmaDecoder
{
    tUPDiGenDecoder_Vtbl* Vtbl;
    tUPDiLzmaDecoderRam* pRam;

} tUPDiLzmaDecoder;

extern tUPDiGenDecoder_Vtbl UPDiLzmaDecoder_VTBL;

//=====================================================================================================================
//  Interface
//=====================================================================================================================
char* UPDiLzmaDecoder_GetExtension(tUPDiLzmaDecoder* This);

Std_ReturnType UPDiLzmaDecoder_Start(tUPDiLzmaDecoder* This, tUPDiInstallSession* pSession, const char* PackageName, uint32_t Size);
Std_ReturnType UPDiLzmaDecoder_Exit(tUPDiLzmaDecoder* this, tUPDiInstallSession* pSession);
Std_ReturnType UPDiLzmaDecoder_Process(tUPDiLzmaDecoder* this, tUPDiInstallSession* pSession);
Std_ReturnType UPDiLzmaDecoder_Transform(tUPDiLzmaDecoder* This, uint8_t* pDataIn, uint32_t* pSizeIn, uint8_t** ppTransformBuffer, uint32_t* pTransformSize);
Std_ReturnType UPDiLzmaDecoder_Serialize(tUPDiLzmaDecoder* This, tUPDStream *pStream);
Std_ReturnType UPDiLzmaDecoder_Deserialize(tUPDiLzmaDecoder* This, tUPDStream *pStream);

#endif
