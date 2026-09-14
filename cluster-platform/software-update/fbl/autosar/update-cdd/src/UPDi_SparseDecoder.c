#include <string.h>
#include "sparse_file.h"
#include "UPDi_SparseDecoder.h"
#include "UPDCdd_cfg.h"
#include "UPDi.h"

//=====================================================================================================================
//  Private functions
//=====================================================================================================================
static boolean IsInvalid(tUPDiSparseDecoder *This)
{
    boolean ret = TRUE;
#ifndef UPDd_POINTER_TEST_DISABLED
    if (This != NULL)
    {
        ret = (This->Vtbl == NULL) || (This->pRam == NULL);
    }
    if (ret)
    {
        UPDd_ERROR("UPDiLzmaDecoder IsInvalid()");
    }
#else
    ret = FALSE;
#endif
    return ret;
}

static void UPDiSparseDecoder_StartDecoding(tUPDiSparseDecoder *This)
{
    UPDiGenDecoder_Transform((tUPDiGenDecoder*)This, This->pRam->file_size);
    This->pRam->State = eSparsetransformChunkHeader;
}

static Std_ReturnType UPDiSparseDecoder_ProcessChunk(tUPDiSparseDecoder *This,
                                                     uint8_t *pDataIn,
                                                     uint32_t *pSizeIn,
                                                     uint8_t **ppTransformBuffer,
                                                     uint32_t *pTransformSize)
{
    Std_ReturnType Status = E_NOT_OK;
    tUPDiSparseDecoderRam *pRam = This->pRam;
    switch(pRam->curr_chunk_type)
    {
    // Load memory and pass to child
    case CHUNK_TYPE_RAW:
    {
        *pTransformSize = min(*pSizeIn, pRam->curr_chunk_pending_size);
        *ppTransformBuffer = pDataIn;
        pRam->curr_chunk_pending_size -= *pTransformSize;
        *pSizeIn = *pTransformSize;
        Status = E_OK;
        break;
    }
    // Generate date from fill character
    case CHUNK_TYPE_FILL:
    {
        uint32_t consumed_data_size = 0;

        // Receive first 3 bytes (4 Byte Character offset)
        if(pRam->fill_data_off < FILL_CHAR_OFF_THR)
        {
            consumed_data_size = min((FILL_CHAR_OFF_THR - pRam->fill_data_off), *pSizeIn);
            pRam->fill_data_off += consumed_data_size;
            *pSizeIn -= consumed_data_size;
        }

        // Proceed if we have the at least 1 data additional
        if(*pSizeIn >= 1)
        {
            // Initialize the fill buffer only once the first time
            if(UPDI_SPARSE_FILL_CHARACTER_MARKER == pRam->curr_chunk_fill_char)
            {
                pRam->curr_chunk_fill_char = (uint16_t)*(pDataIn);
                memset(pRam->Buffer, pRam->curr_chunk_fill_char, sizeof(pRam->Buffer));
            }

            *pTransformSize = min(sizeof(pRam->Buffer), pRam->curr_chunk_pending_size);
            *ppTransformBuffer = pRam->Buffer;
            pRam->curr_chunk_pending_size -= *pTransformSize;

            // Only consume the last fill byte when block has been completed
            if(0 == pRam->curr_chunk_pending_size)
            {
                pRam->fill_data_off++;
                consumed_data_size++;
            }
        }

        *pSizeIn = consumed_data_size;

        Status = E_OK;
        break;
    }
    // Nothing to do
    case CHUNK_TYPE_DONT_CARE:
    {
        *pSizeIn = 0;
        pRam->curr_chunk_pending_size = 0;
        Status = E_OK;
        break;
    }
    // CRC is not implemented using SPARSE
    case CHUNK_TYPE_CRC32:
    {
        uint32_t consumed_data_size = 0;
        // receive the first 3 CRC data bytes
        if(pRam->fill_data_off < FILL_CHAR_OFF_THR)
        {
            consumed_data_size = min((FILL_CHAR_OFF_THR - pRam->fill_data_off), *pSizeIn);
            pRam->fill_data_off += consumed_data_size;
            *pSizeIn -= consumed_data_size;
        }
        // Proceed if we have the at least 1 data byte more
        if(*pSizeIn >= 1)
        {
            pRam->curr_chunk_pending_size = 0;
        }

        *pSizeIn = consumed_data_size;
        Status = E_OK;
        break;
    }
    default:
    {
        break;
    }
    }
    return Status;
}

static Std_ReturnType UPDiSparseDecoder_ParseHeader(tUPDiSparseDecoder *This)
{
    Std_ReturnType Status = E_NOT_OK;
    tUPDiSparseDecoderRam *pRam = This->pRam;
    sparse_header_t *sparse_header = (sparse_header_t*) &pRam->Parent.LoadBuffer[0];

    if (sparse_header->magic != SPARSE_HEADER_MAGIC)
    {
        UPDd_ERROR("Invalid Sparse Header Magic");
    }
    else if (sparse_header->major_version != SPARSE_HEADER_MAJOR_VER)
    {
        UPDd_ERROR("invalid header major version");
    }
    else if (sparse_header->file_hdr_sz < SPARSE_HEADER_LEN)
    {
        UPDd_ERROR("Incompatible file header size");
    }

    else if (sparse_header->chunk_hdr_sz < CHUNK_HEADER_LEN)
    {
        UPDd_ERROR("Incompatible chunk header size");
    }
    else
    {
    	uint16_t overflow_len;

        pRam->block_size = sparse_header->blk_sz;
        pRam->file_size = (uint64_t)sparse_header->total_blks * sparse_header->blk_sz;
        pRam->chunk_header_size = sparse_header->chunk_hdr_sz;
        pRam->pending_chunks = sparse_header->total_chunks;
        pRam->file_header_size = sparse_header->file_hdr_sz;

        // Load and skip the empty header
        overflow_len = pRam->file_header_size - SPARSE_HEADER_LEN;
        if(0 != overflow_len)
        {
            UPDiGenDecoder_Load((tUPDiGenDecoder*) This, overflow_len);
            pRam->State = eSparseLoadingHeaderSkip;
        }
        // Start Decoding
        else
        {
            UPDiSparseDecoder_StartDecoding(This);
        }
        Status = E_OK;
    }

    return Status;
}

static uint32_t UPDAbstractInstaller_getImageRewindOff(tUPDiSparseDecoder *This, uint32_t FlashOffset)
{
    tUPDiSparseDecoderRam *pRam = This->pRam;
    uint32_t RewinfOff = 0;

    switch(pRam->curr_chunk_type)
    {
    // For Raw chunks rewind the data size
    case CHUNK_TYPE_RAW:
    {
        RewinfOff = FlashOffset;
        break;
    }
    // For fill chunk rewind the fill character
    case CHUNK_TYPE_FILL:
    {
        RewinfOff = pRam->fill_data_off;
        break;
    }
    // For CRC chunk rewind the fill character
    case CHUNK_TYPE_CRC32:
    {
        RewinfOff = pRam->fill_data_off;
        break;
    }
    case CHUNK_TYPE_DONT_CARE:
    default:
    {
        RewinfOff = 0;
        break;
    }
    }

    return RewinfOff;
}

static boolean UPDAbstractInstaller_RewindChunk(tUPDiSparseDecoder *This, uint32_t FlashOffset, uint32_t* pImageOffset)
{
    boolean ContinueFlashing = TRUE;
    tUPDiSparseDecoderRam *pRam = This->pRam;
    uint32_t ImageRewOff = 0;
    uint32_t chunkReceived = pRam->curr_chunk_size - pRam->curr_chunk_pending_size;
    uint32_t chunkProcessed = pRam->Parent.Processed - pRam->last_chunk_off;
    uint32_t toRewind = FlashOffset;

    if(0 < chunkReceived)
    {
        // Image has been received
        if(pRam->Parent.Processed >= pRam->last_chunk_off)
        {
            // We are loading the current chunk
            toRewind += (chunkReceived - chunkProcessed);
        }
        else
        {
            // We are processing a data in a new chunk before the child has processed the previous
            UPDd_ERROR("Invalid rewind state");
            ContinueFlashing = FALSE;
        }
    }
    else
    {
        // Image hasn't been received we must be finishing the chunk or starting a new chunk
        if(pRam->Parent.Processed <= pRam->last_chunk_off)
        {
            // Rewind the data from the previous chunk that has not been yet processed by the Child (If Any)
            toRewind += (pRam->last_chunk_off - pRam->Parent.Processed);
        }
        else
        {
            UPDd_ERROR("Invalid rewind state");
            ContinueFlashing = FALSE;
        }
    }

    uint32_t genImgRewOff = 0;

    if(ContinueFlashing)
    {
        *pImageOffset = 0;
        do
        {
            chunkReceived = pRam->curr_chunk_size - pRam->curr_chunk_pending_size;

            // Can we rewind data in current chunk
            if( 0 < chunkReceived )
            {
                // Adjust the flash offset to the received offset
                genImgRewOff = min(chunkReceived, toRewind);
                ImageRewOff += UPDAbstractInstaller_getImageRewindOff(This, genImgRewOff);
                pRam->curr_chunk_pending_size += genImgRewOff;
                toRewind -= genImgRewOff;
            }
            // If we don't have data we but we must rewind, we may have to rewind the current header
            // (In the middle of receiving the header)
            else if(toRewind == 0)
            {
                // Rewind the chunk header only if we don't have the full header yet
                if(pRam->chunk_header_off < pRam->chunk_header_size)
                {
                    ImageRewOff += pRam->chunk_header_off;

                    // Delete current Chunk header
                    pRam->curr_chunk_size = 0;
                    pRam->curr_chunk_type = 0;
                    pRam->curr_chunk_fill_char = UPDI_SPARSE_FILL_CHARACTER_MARKER;
                    pRam->curr_chunk_pending_size = 0;
                    pRam->chunk_header_off = 0;
                    pRam->State = eSparsetransformChunkHeader;
                }
            }
            // I we must rewind at least 1 Byte and we didn't have data, we must restore the previous chunk
            // and loop again
            else if(0 != pRam->prev_chunk_type)
            {
                ImageRewOff += pRam->chunk_header_off;

                // Restore previous Chunk
                pRam->curr_chunk_size = pRam->prev_chunk_size;
                pRam->curr_chunk_type = pRam->prev_chunk_type;
                pRam->curr_chunk_fill_char = pRam->prev_chunk_fill_char;
                pRam->curr_chunk_pending_size = 0;
                pRam->chunk_header_off = pRam->chunk_header_size;
                pRam->last_chunk_off -= pRam->curr_chunk_size;
                pRam->pending_chunks++;
                pRam->prev_chunk_size = 0;
                pRam->prev_chunk_type = 0;
                pRam->prev_chunk_fill_char = UPDI_SPARSE_FILL_CHARACTER_MARKER;
                pRam->State = eSparsetransformChunk;
                pRam->fill_data_off = FILL_CHAR_OFF_SIZE;
            }
            // Decoder is asked to rewind to non existent previous chunk
            else
            {
            	UPDd_WARNING("Sparse Decoder suspend failed, decoder is asked to rewind to non existent previous chunk");
                ContinueFlashing = FALSE;
                break;
            }
        } while(0 != toRewind);
    }

    if(ContinueFlashing)
    {
        *pImageOffset = ImageRewOff;
        pRam->Parent.ToProcess += FlashOffset;
        pRam->Parent.Processed -= FlashOffset;
    }

    return ContinueFlashing;
}

//=====================================================================================================================
//  Public functions
//=====================================================================================================================
tUPDiGenDecoder_Vtbl UPDiSparseDecoder_VTBL = { .GetExtension   = (tpfGetExtension)         UPDiSparseDecoder_GetExtension,
                                                .InstallStart   = (tpfInstallStart)         UPDiGenDecoder_InstallStart,
                                                .InstallData    = (tpfInstallData)          UPDiGenDecoder_InstallData,
                                                .InstallExit    = (tpfInstallExit)          UPDiGenDecoder_InstallExit,
                                                .Serialize      = (tpfSerialize)            UPDiSparseDecoder_Serialize,
                                                .Deserialize    = (tpfDeserialize)          UPDiSparseDecoder_DeSerialize,
                                                .Rewind         = (tpfRewind)               UPDiSparseDecoder_Rewind,
                                                .DecoderStart   = (tpfGenDecoder_Start)     UPDiSparseDecoder_Start,
                                                .DecoderProcess = (tpfGenDecoder_Process)   UPDiSparseDecoder_Process,
                                                .DecoderExit    = (tpfGenDecoder_Exit)      UPDiSparseDecoder_Exit,
                                                .Transform      = (tpfGenDecoder_Transform) UPDiSparseDecoder_Transform
};

Std_ReturnType UPDiSparseDecoder_Transform(tUPDiSparseDecoder *This,
                                           uint8_t *pDataIn,
                                           uint32_t *pSizeIn,
                                           uint8_t **ppTransformBuffer,
                                           uint32_t *pTransformSize)
{
    Std_ReturnType Status = E_NOT_OK;
    tUPDiSparseDecoderRam *pRam = NULL;
    uint16_t chunk_header_avail;

    if (IsInvalid(This))
    {
    }
    else
    {
        pRam = This->pRam;

        switch(pRam->State)
        {
        case eSparsetransformChunkHeader:
        {
            // Compute the size of the chunk
            chunk_header_avail = min(CHUNK_HEADER_LEN - pRam->chunk_header_off, *pSizeIn);
            memcpy(((uint8_t*)(&(pRam->chunk_header)) +  pRam->chunk_header_off), pDataIn, chunk_header_avail);
            pRam->chunk_header_off += chunk_header_avail;
            *pSizeIn = chunk_header_avail;

            // Header is available
            if(pRam->chunk_header_off >= CHUNK_HEADER_LEN)
            {
                pRam->curr_chunk_type = pRam->chunk_header.chunk_type;
                pRam->curr_chunk_size = pRam->chunk_header.chunk_sz * pRam->block_size;
                pRam->curr_chunk_pending_size = pRam->curr_chunk_size;
                if(pRam->chunk_header_size > CHUNK_HEADER_LEN)
                {
                    pRam->State = eSparsetransformChunkHeaderSkip;
                }
                else
                {
                    pRam->State = eSparsetransformChunk;
                }
            }
            Status = E_OK;
            break;
        case eSparsetransformChunkHeaderSkip:
        {
            //just skip
            chunk_header_avail = min(pRam->chunk_header_size-pRam->chunk_header_off, *pSizeIn);
            pRam->chunk_header_off += chunk_header_avail;
            *pSizeIn = chunk_header_avail;
            if(pRam->chunk_header_size == pRam->chunk_header_off)
            {
                pRam->State = eSparsetransformChunk;
            }
            Status = E_OK;
            break;
        }
        case eSparsetransformChunk:
        {
            Status = UPDiSparseDecoder_ProcessChunk(This, pDataIn, pSizeIn, ppTransformBuffer, pTransformSize);
            if((E_OK == Status) && (0 == pRam->curr_chunk_pending_size))
            {
                pRam->last_chunk_off += pRam->curr_chunk_size;
                pRam->prev_chunk_size = pRam->curr_chunk_size;
                pRam->prev_chunk_type = pRam->curr_chunk_type;
                pRam->prev_chunk_fill_char = pRam->curr_chunk_fill_char;
                pRam->curr_chunk_size = 0;
                pRam->curr_chunk_type = 0;
                pRam->curr_chunk_fill_char = UPDI_SPARSE_FILL_CHARACTER_MARKER;
                pRam->chunk_header_off = 0;
                pRam->fill_data_off = 0;
                if(0 == (--pRam->pending_chunks))
                {
                    pRam->State = eSparseDone;
                }
                else
                {
                    pRam->State = eSparsetransformChunkHeader;
                }
            }

            break;
        }
        default:
        {
            UPDd_ERROR("Invalid state %d in transform request for Sparse decoder", pRam->State)
            break;
        }
        }
        }
    }
    return Status;
}

char* UPDiSparseDecoder_GetExtension(tUPDiSparseDecoder *This)
{
    return SPARSE_DECODER_EXT_NAME;
}

Std_ReturnType UPDiSparseDecoder_Start(tUPDiSparseDecoder *This,
                                       tUPDiInstallSession *pSession,
                                       const char *PackageName,
                                       uint32_t Size)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This))
    {
    }
    else
    {
        tUPDiSparseDecoderRam *pRam = This->pRam;
        pRam->chunk_header_off = 0;
        UPDiGenDecoder_Load((tUPDiGenDecoder*) This, sizeof(sparse_header_t));
        pRam->State = eSparseLoadingHeader;
        pRam->chunk_header_size = 0;
        pRam->last_chunk_off = 0;
        pRam->file_size = 0;
        pRam->block_size = 0;
        pRam->pending_chunks = 0;
        pRam->curr_chunk_pending_size = 0;
        pRam->curr_chunk_type = 0;
        pRam->curr_chunk_size = 0;
        pRam->curr_chunk_fill_char = UPDI_SPARSE_FILL_CHARACTER_MARKER;
        pRam->prev_chunk_type = 0;
        pRam->prev_chunk_size = 0;
        pRam->prev_chunk_fill_char = UPDI_SPARSE_FILL_CHARACTER_MARKER;
        pRam->fill_data_off = 0;
        Status = E_OK;
    }
    return Status;
}

Std_ReturnType UPDiSparseDecoder_Process(tUPDiSparseDecoder *This,
                                         tUPDiInstallSession *pSession)
{
    Std_ReturnType Status = E_NOT_OK;

    tUPDiSparseDecoderRam *pRam = NULL;
    if (!IsInvalid(This))
    {
        pRam = This->pRam;
        switch (pRam->State)
        {
        case (eSparseLoadingHeader):
        {
            Status = UPDiSparseDecoder_ParseHeader(This);
            break;
        }
        case (eSparseLoadingHeaderSkip):
        {
            //Nothing to do, just consume the data and start decoding
            UPDiSparseDecoder_StartDecoding(This);
            Status = E_OK;
            break;
        }
        case (eSparseDone):
        {
            //Nothing to do
            Status = E_OK;
            break;
        }
        default:
        {
            UPDd_ERROR("Invalid state %d in process request for Sparse decoder", pRam->State)
        }
        }
    }

    return Status;
}

Std_ReturnType UPDiSparseDecoder_Exit(tUPDiSparseDecoder *This,
                                      tUPDiInstallSession *pSession)
{
    Std_ReturnType Status = E_NOT_OK;

     if (IsInvalid(This))
     {
     }
     else
     {
         tUPDiSparseDecoderRam *pRam = This->pRam;
         if (eSparseDone == pRam->State)
         {
             pRam->curr_chunk_pending_size = 0;
             pRam->curr_chunk_type = 0;
             pRam->curr_chunk_size = 0;
             pRam->curr_chunk_fill_char = UPDI_SPARSE_FILL_CHARACTER_MARKER;
             pRam->prev_chunk_type = 0;
             pRam->prev_chunk_size = 0;
             pRam->prev_chunk_fill_char = UPDI_SPARSE_FILL_CHARACTER_MARKER;
             return E_OK;
         }
     }
    return Status;
}

boolean UPDiSparseDecoder_Rewind(tUPDiSparseDecoder* This, uint32_t FlashOffset, uint32_t* pImageOffset)
{
    boolean ContinueFlashing = FALSE;
    if (IsInvalid(This))
    {
    }
    else
    {
        tUPDiSparseDecoderRam *pRam = This->pRam;

        switch(pRam->State)
        {
        case eSparseLoadingHeader:
        case eSparseLoadingHeaderSkip:
        {
            // If we are loading the image header sill, no need to rewind
            // Just start over
            pRam->State = eSparseLoadingHeader;
            pRam->Parent.ToProcess = 0;
            pRam->Parent.Processed = 0;

            break;
        }
        case eSparsetransformChunkHeader:
        case eSparsetransformChunkHeaderSkip:
        case eSparsetransformChunk:
        {
            uint32_t ChildOffset = pRam->Parent.Processed;

            // Ask the child to rewind
            ContinueFlashing = UPDAbstractInstaller_Rewind(pRam->Parent.pChild, FlashOffset, &ChildOffset);

            // If the child can rewind
            if(ContinueFlashing)
            {
                // If verify if the child need to rewind
                ContinueFlashing = UPDAbstractInstaller_RewindChunk(This, ChildOffset, pImageOffset);
            }

            break;
        }
        case eSparseDone:
        {
            // Otherwise, Reset the decoder
            pRam->Parent.State = eGenReady;

            break;
        }
        default:
        {
            // By default Reset the decoder
            UPDd_ERROR("Unknown state %u", pRam->State);
            pRam->Parent.State = eGenReady;

            break;
        }
        }

        if(!ContinueFlashing)
        {
            pRam->State = eSparseDone;
            pRam->Parent.ToProcess = 0;
            pRam->Parent.Processed = 0;
            ContinueFlashing = FALSE;
        }
    }
    return ContinueFlashing;
}

Std_ReturnType UPDiSparseDecoder_Serialize(tUPDiSparseDecoder* This, tUPDStream *pStream)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This) && pStream)
    {
    }
    else
    {
        tUPDiSparseDecoderRam *pRam = This->pRam;
        uint8_t ChildInstallerId = UPDi_GetInstallerId(pRam->Parent.pChild);

        UPDi_SERIALIZE(pStream, pRam->State);
        UPDi_SERIALIZE(pStream, pRam->file_size);
        UPDi_SERIALIZE(pStream, pRam->file_header_size);
        UPDi_SERIALIZE(pStream, pRam->block_size);
        UPDi_SERIALIZE(pStream, pRam->pending_chunks);
        UPDi_SERIALIZE(pStream, pRam->last_chunk_off);
        UPDi_SERIALIZE(pStream, pRam->chunk_header_size);
        UPDi_SERIALIZE(pStream, pRam->curr_chunk_type);
        UPDi_SERIALIZE(pStream, pRam->curr_chunk_size);
        UPDi_SERIALIZE(pStream, pRam->curr_chunk_fill_char);
        UPDi_SERIALIZE(pStream, pRam->Parent.Processed);
        UPDi_SERIALIZE(pStream, pRam->Parent.ToProcess);
        UPDi_SERIALIZE(pStream, ChildInstallerId);
        Status = E_OK;
    }
    return Status;
}

Std_ReturnType UPDiSparseDecoder_DeSerialize(tUPDiSparseDecoder* This, tUPDStream *pStream)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This) && pStream)
    {
    }
    else
    {
        tUPDiSparseDecoderRam *pRam = This->pRam;
        uint8_t ChildInstallerId;

        UPDi_DESERIALIZE(pStream, pRam->State, eSparseDone);
        UPDi_DESERIALIZE(pStream, pRam->file_size, 0);
        UPDi_DESERIALIZE(pStream, pRam->file_header_size, 0);
        UPDi_DESERIALIZE(pStream, pRam->block_size, 0);
        UPDi_DESERIALIZE(pStream, pRam->pending_chunks, 0);
        UPDi_DESERIALIZE(pStream, pRam->last_chunk_off, 0);
        UPDi_DESERIALIZE(pStream, pRam->chunk_header_size, 0);
        UPDi_DESERIALIZE(pStream, pRam->curr_chunk_type, 0);
        UPDi_DESERIALIZE(pStream, pRam->curr_chunk_size, 0);
        UPDi_DESERIALIZE(pStream, pRam->curr_chunk_fill_char, UPDI_SPARSE_FILL_CHARACTER_MARKER);
        UPDi_DESERIALIZE(pStream, pRam->Parent.Processed, 0);
        UPDi_DESERIALIZE(pStream, pRam->Parent.ToProcess, 0);
        UPDi_DESERIALIZE(pStream, ChildInstallerId, -1);

        // If the chunk type is known, the header was available at rewind, otherwise the type would have been 0
        // Restore the chunk header offset.
        if(pRam->curr_chunk_size == 0)
        {
            pRam->chunk_header_off = 0;
        }
        else
        {
            pRam->chunk_header_off = pRam->chunk_header_size;
        }

        pRam->curr_chunk_pending_size =  pRam->curr_chunk_size - (pRam->Parent.Processed - pRam->last_chunk_off);
        pRam->prev_chunk_type = 0;
        pRam->prev_chunk_size = 0;
        pRam->prev_chunk_fill_char = UPDI_SPARSE_FILL_CHARACTER_MARKER;
        pRam->fill_data_off = 0;

        switch(pRam->State)
        {
        case eSparseLoadingHeader:
        case eSparseLoadingHeaderSkip:
        {
            // Load from the start the sparse file header
            UPDiGenDecoder_Load((tUPDiGenDecoder*) This, sizeof(sparse_header_t));
            break;
        }
        case eSparsetransformChunkHeader:
        case eSparsetransformChunkHeaderSkip:
        case eSparsetransformChunk:
        {
            // Restore Transform state
            pRam->Parent.State = eGenTransformingToChild;
            pRam->Parent.pChild = UPDi_GetInstallerbyId(ChildInstallerId);
            break;
        }
        case eSparseDone:
        {
            pRam->Parent.State = eGenReady;
            break;
        }
        default:
        {
            UPDd_ERROR("Unknown state %u\n", pRam->State);
            pRam->State = eSparseDone;
            pRam->Parent.State = eGenReady;
            break;
        }
        }

        pRam->Parent.pTransformBuffer = NULL;
        pRam->Parent.ResumeAt = 0;
        Status = E_OK;
    }
    return Status;
}
