#include "UPDi_LzmaDecoder.h"
#include "LzmaDec.h"
#include "UPDd.h"
#include <string.h>

//=====================================================================================================================
//  Private functions
//=====================================================================================================================
static boolean IsInvalid(tUPDiLzmaDecoder* This)
{
    boolean ret = TRUE;
#ifndef UPDd_POINTER_TEST_DISABLED
    if (This != NULL)
    {
        ret = (This->Vtbl == NULL) || ( This->pRam == NULL);
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

static tUPDiLzmaMemoryPool* pMemoryPool;
static void *LzmaDecoder_Alloc(ISzAllocPtr p, size_t size)
{
    void * ptr = NULL;
    (void)p;
    if (pMemoryPool != NULL)
    {
        uint32_t NewUsed = pMemoryPool->Used + size;
        if (NewUsed <= pMemoryPool->Size)
        {
            ptr = pMemoryPool->Buffer + pMemoryPool->Used;
            pMemoryPool->Used = NewUsed;
        }
        else
        {
        	UPDd_INFO("Missing %lu Bytes for the LZMA allocation, please extend UPDd_LZMA_MEMORY_POOL_SIZE accordingly",(unsigned long)(NewUsed - pMemoryPool->Size));
        }
    }
    return ptr;
}
static void LzmaDecoder_Free(ISzAllocPtr p, void *address)
{
    (void)p; (void)address;
}
static const ISzAlloc g_LzmaAlloc = { LzmaDecoder_Alloc,  LzmaDecoder_Free };

//=====================================================================================================================
//  Public functions
//=====================================================================================================================
tUPDiGenDecoder_Vtbl UPDiLzmaDecoder_VTBL =
{
    .GetExtension   = (tpfGetExtension)UPDiLzmaDecoder_GetExtension,
    .InstallStart   = (tpfInstallStart)UPDiGenDecoder_InstallStart,
    .InstallData    = (tpfInstallData)UPDiGenDecoder_InstallData,
    .InstallExit    = (tpfInstallExit)UPDiGenDecoder_InstallExit,
    .Serialize      = (tpfSerialize)UPDiLzmaDecoder_Serialize,
    .Deserialize    = (tpfDeserialize)UPDiLzmaDecoder_Deserialize,
    .DecoderStart   = (tpfGenDecoder_Start)UPDiLzmaDecoder_Start,
    .DecoderProcess = (tpfGenDecoder_Process)UPDiLzmaDecoder_Process,
    .DecoderExit    = (tpfGenDecoder_Exit)UPDiLzmaDecoder_Exit,
    .Transform      = (tpfGenDecoder_Transform)UPDiLzmaDecoder_Transform
};




Std_ReturnType UPDiLzmaDecoder_ParseHeader(tUPDiLzmaDecoder* This)
{
    Std_ReturnType Status = E_NOT_OK;
    tUPDiLzmaDecoderRam* pRam = This->pRam;
    int i;
    pRam->UncompressedSize = 0;
    pRam->UncompressedSize_HIGH = 0;
    //pRam->OutputSizeProcessed = 0;

    tUPDiLzmaHeader* pHeader = (tUPDiLzmaHeader*)&pRam->Parent.LoadBuffer[0];

    for (i = 0; i < sizeof(uint32_t); i++)
    {
        pRam->UncompressedSize += (uint64_t)pHeader->Size[i] << (i * 8);
        pRam->UncompressedSize_HIGH += (uint64_t)pHeader->Size[i + sizeof(uint32_t)] << (i * 8);
    }
    if (pRam->UncompressedSize_HIGH == 0)
    {
        //pRam->SizeProcessed = sizeof(tUPDiLzmaHeader);

        tUPDiLzmaMemoryPool TmpPool;
        pMemoryPool = &TmpPool;
        pMemoryPool->Buffer = &pRam->PoolBuffer[0];
        pMemoryPool->Size = sizeof(tUPDiLzmaPoolBuffer);
        pMemoryPool->Used = 0;
        SRes res = LzmaDec_Allocate(&pRam->Decoder, (Byte*)&pHeader->Props, sizeof(pHeader->Props), &g_LzmaAlloc);
        pMemoryPool = NULL;

        if (res == SZ_OK)
        {
            LzmaDec_Init(&pRam->Decoder);
            UPDiGenDecoder_Transform((tUPDiGenDecoder*)This, pRam->UncompressedSize);
            pRam->State = eLzmaDecompressing;
            Status = E_OK;
        }
        else
        {
            UPDd_ERROR("UPDiLzmaDecoder_InstallData() LZMA Memory Allocation failed");
        }
    }
    else
    {
        UPDd_ERROR("UPDiLzmaDecoder_InstallData() UncompressedSize_HIGH is not 0");
    }
    return Status;
}

Std_ReturnType UPDiLzmaDecoder_Transform(tUPDiLzmaDecoder* This, uint8_t* pDataIn, uint32_t* pSizeIn, uint8_t** ppTransformBuffer, uint32_t* pTransformSize)
{
    tUPDiLzmaDecoderRam* pRam = This->pRam;
    Std_ReturnType Status = E_NOT_OK;
    ELzmaStatus lzStatus;

    SizeT destLen = sizeof(tUPDiLzmaDecoderBuffer);
    SizeT srcLen = *pSizeIn;
    *ppTransformBuffer = pRam->Buffer;
    SRes res = LzmaDec_DecodeToBuf(&pRam->Decoder, *ppTransformBuffer, &destLen, pDataIn, &srcLen, LZMA_FINISH_ANY, &lzStatus);
    *pTransformSize = (uint32_t)destLen;
    *pSizeIn = srcLen;

    if (res != SZ_OK)
    {
        UPDd_ERROR("UPDiLzmaDecoder_InstallData() LzmaDec_DecodeToBuf() failed");
        Status = E_NOT_OK;
    }
    else if (lzStatus == LZMA_STATUS_NOT_FINISHED)
    {
        Status = E_OK;
    }
    else if (lzStatus == LZMA_STATUS_NEEDS_MORE_INPUT)
    {
        Status = E_OK;
    }
    else if (lzStatus == LZMA_STATUS_MAYBE_FINISHED_WITHOUT_MARK)
    {
        Status = E_OK;
    }
    else if (lzStatus == LZMA_STATUS_FINISHED_WITH_MARK)
    {
        Status = E_OK;
    }
    else
    {
        UPDd_ERROR("UPDiLzmaDecoder_InstallData() LzmaDec_DecodeToBuf() failed");
        Status = E_NOT_OK;
    }
    return Status;
}

char* UPDiLzmaDecoder_GetExtension(tUPDiLzmaDecoder* This) { return "x2"; }

Std_ReturnType UPDiLzmaDecoder_Start(tUPDiLzmaDecoder* This, tUPDiInstallSession* pSession, const char* PackageName, uint32_t Size)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This))
    {
    }
    else
    {
        tUPDiLzmaDecoderRam* pRam = This->pRam;
        UPDiGenDecoder_Load((tUPDiGenDecoder*)This, sizeof(tUPDiLzmaHeader));
        pRam->State = eLzmaLoadingHeader;
        Status = E_OK;
    }
    return Status;
}

Std_ReturnType UPDiLzmaDecoder_Process(tUPDiLzmaDecoder* This, tUPDiInstallSession* pSession)
{
    Std_ReturnType Status = E_NOT_OK;
    tUPDiLzmaDecoderRam* pRam = This->pRam;
    if (!IsInvalid(This))
    {
        switch (pRam->State)
        {
        case(eLzmaLoadingHeader):
            Status = UPDiLzmaDecoder_ParseHeader(This);
            break;

        case(eLzmaDecompressing):
            Status = E_OK; // nothing to do, we are done
            pRam->State = eLzmaDone;
            break;

        case(eLzmaDone):
        		// Nothing to do
        	break;
        }
    }
    return Status;
}

Std_ReturnType UPDiLzmaDecoder_Exit(tUPDiLzmaDecoder* This, tUPDiInstallSession* pSession)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This))
    {
    }
    else
    {
        tUPDiLzmaDecoderRam* pRam = This->pRam;
        if (pRam->State == eLzmaDone)
        {
            return E_OK;
        }
    }
    return Status;
}

Std_ReturnType UPDiLzmaDecoder_Serialize(tUPDiLzmaDecoder* This, tUPDStream *pStream)
{
	return E_OK;
}

Std_ReturnType UPDiLzmaDecoder_Deserialize(tUPDiLzmaDecoder* This, tUPDStream *pStream)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This))
    {
    }
    else
    {
        tUPDiLzmaDecoderRam* pRam = This->pRam;
        memset(pRam,0, sizeof(tUPDiLzmaDecoderRam));
    }
    return Status;
}


