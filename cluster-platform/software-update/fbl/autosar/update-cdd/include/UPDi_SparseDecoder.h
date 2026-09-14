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
#ifndef UPD_SparseDecoder_H
#define UPD_SparseDecoder_H

#include "UPDi_GenDecoder.h"
#include "sparse_format.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
#define UPDI_SPARSE_FILL_CHARACTER_MARKER ((uint16_t)0xFFFF)

typedef uint8_t tUPDiSparseDecoderBuffer[UPDd_SPARSE_BLOCK_SIZE];

typedef enum
{
    // Decoder finished
    eSparseDone,
    // Load the file header
    eSparseLoadingHeader,
        // Skip the not required header data
        eSparseLoadingHeaderSkip,
    // Load the chunk header
    eSparsetransformChunkHeader,
        // Skip the not required chunk header data
        eSparsetransformChunkHeaderSkip,
        // Process the chunk
        eSparsetransformChunk,
} tUPDiSparseDecoderState;

typedef struct stUPDiSparseDecoder
{
    tUPDiGenDecoderRam Parent;
    tUPDiSparseDecoderBuffer Buffer;
    tUPDiSparseDecoderState State;
    chunk_header_t chunk_header;
    uint64_t file_size;
    uint32_t block_size;
    uint32_t pending_chunks;
    uint32_t last_chunk_off;
    uint32_t curr_chunk_pending_size;
    uint32_t curr_chunk_size;
    uint32_t prev_chunk_size;
    uint16_t curr_chunk_type;
    uint16_t prev_chunk_type;
    uint16_t file_header_size;
    uint16_t chunk_header_size;
    uint16_t chunk_header_off;
    uint16_t curr_chunk_fill_char;
    uint16_t  prev_chunk_fill_char;
    uint8_t  fill_data_off;
} tUPDiSparseDecoderRam;

typedef const struct sUPDiSparseDecoder
{
    tUPDiGenDecoder_Vtbl* Vtbl;
    tUPDiSparseDecoderRam* pRam;

} tUPDiSparseDecoder;

extern tUPDiGenDecoder_Vtbl UPDiSparseDecoder_VTBL;

//=====================================================================================================================
//  Interface
//=====================================================================================================================
char* UPDiSparseDecoder_GetExtension(tUPDiSparseDecoder* This);

Std_ReturnType UPDiSparseDecoder_Start(tUPDiSparseDecoder* This, tUPDiInstallSession* pSession, const char* PackageName, uint32_t Size);
Std_ReturnType UPDiSparseDecoder_Exit(tUPDiSparseDecoder* this, tUPDiInstallSession* pSession);
Std_ReturnType UPDiSparseDecoder_Process(tUPDiSparseDecoder* this, tUPDiInstallSession* pSession);
Std_ReturnType UPDiSparseDecoder_Transform(tUPDiSparseDecoder* This, uint8_t* pDataIn, uint32_t* pSizeIn, uint8_t** ppTransformBuffer, uint32_t* pTransformSize);
boolean        UPDiSparseDecoder_Rewind(tUPDiSparseDecoder* This, uint32_t FlashOffset, uint32_t* pImageOffset);
Std_ReturnType UPDiSparseDecoder_Serialize(tUPDiSparseDecoder* This, tUPDStream *pStream);
Std_ReturnType UPDiSparseDecoder_DeSerialize(tUPDiSparseDecoder* This, tUPDStream *pStream);

#endif
