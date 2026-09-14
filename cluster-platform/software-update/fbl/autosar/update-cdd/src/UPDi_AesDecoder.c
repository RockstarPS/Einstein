/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2024. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
//#include <memory.h>
#include <string.h>
#include "UPDi_AesDecoder.h"
#include "UPDi.h"
#include "UPD_ICry.h"

#if (STD_ON == UPD_AES_DECODER)
//=====================================================================================================================
/* CONSTANTS & TYPES */
//=====================================================================================================================
#if ENABLE_AES_CBC_SUSPEND_IV_WORKARROUND
#define ADDITIONAL_SKIP_BYTES AES_DECRYPT_BLOCK_LEN
#else
#define ADDITIONAL_SKIP_BYTES 0
#endif /* ENABLE_AES_CBC_SUSPEND_IV_WORKARROUND */

//=====================================================================================================================
/*Global variables and functions*/
//=====================================================================================================================
char*          UPDiAESDecoder_GetExtension(tUPDiAESDecoder* This);
Std_ReturnType UPDiAESDecoder_Start(tUPDiAESDecoder* This, tUPDiInstallSession* pSession, const char* PackageName, uint32 Size);
Std_ReturnType UPDiAESDecoder_Exit(tUPDiAESDecoder* This, tUPDiInstallSession* pSession);
Std_ReturnType UPDiAESDecoder_Process(tUPDiAESDecoder* This, tUPDiInstallSession* pSession);
Std_ReturnType UPDiAESDecoder_Transform(tUPDiAESDecoder* This, uint8* pDataIn, uint32* pSizeIn, uint8** ppTransformBuffer, uint32* pTransformSize);
boolean        UPDiAESDecoder_Rewind(tUPDiAESDecoder* This, uint32 FlashOffset, uint32* pImageOffset);
Std_ReturnType UPDiAESDecoder_Serialize(tUPDiAESDecoder* This, tUPDStream *pStream);
Std_ReturnType UPDiAESDecoder_DeSerialize(tUPDiAESDecoder* This, tUPDStream *pStream);
boolean        UPDiAESDecoder_Rewind(tUPDiAESDecoder* This, uint32 FlashOffset, uint32* pImageOffset);

tUPDiGenDecoder_Vtbl UPDiAESDecoder_VTBL = {    .GetExtension   = (tpfGetExtension)         UPDiAESDecoder_GetExtension,
                                                .InstallStart   = (tpfInstallStart)         UPDiGenDecoder_InstallStart,
                                                .InstallData    = (tpfInstallData)          UPDiGenDecoder_InstallData,
                                                .InstallExit    = (tpfInstallExit)          UPDiGenDecoder_InstallExit,
                                                .Serialize      = (tpfSerialize)            UPDiAESDecoder_Serialize,
                                                .Deserialize    = (tpfDeserialize)          UPDiAESDecoder_DeSerialize,
                                                .Rewind         = (tpfRewind)               UPDiAESDecoder_Rewind,
                                                .DecoderStart   = (tpfGenDecoder_Start)     UPDiAESDecoder_Start,
                                                .DecoderProcess = (tpfGenDecoder_Process)   UPDiAESDecoder_Process,
                                                .DecoderExit    = (tpfGenDecoder_Exit)      UPDiAESDecoder_Exit,
                                                .Transform      = (tpfGenDecoder_Transform) UPDiAESDecoder_Transform
};

//=====================================================================================================================
/* Private Declarations */
//=====================================================================================================================
static boolean UPDiAESDecoder_RewindChunk(tUPDiAESDecoder *This, uint32 FlashOffset, uint32* pImageOffset);
static Std_ReturnType UPDiAESDecoder_InitDecoder(tUPDiAESDecoder* This);

//=====================================================================================================================
//  Vtbl functions
//=====================================================================================================================
static boolean IsInvalid(tUPDiAESDecoder *This)
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

char* UPDiAESDecoder_GetExtension(tUPDiAESDecoder* This)
{
    return AES128_DECODER_EXT_NAME;
}

Std_ReturnType UPDiAESDecoder_Start(tUPDiAESDecoder* This, tUPDiInstallSession* pSession, const char* PackageName, uint32 Size)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This))
    {
    }
    else
    {
        tUPDiAESDecoderRam *pRam = This->pRam;
        pRam->ImgSize = Size;
        pRam->ImgPending = pRam->ImgSize;
        pRam->BytesToSkip = 0;

        Status = UPDiAESDecoder_InitDecoder(This);

    }
    return Status;
}

Std_ReturnType UPDiAESDecoder_Process(tUPDiAESDecoder* This, tUPDiInstallSession* pSession)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This))
    {
    }
    else
    {
        tUPDiAESDecoderRam *pRam = This->pRam;
        if(AES_FINISHED == pRam->State)
        {
            Status = E_OK;
        }
        else
        {
            UPDd_ERROR("Unexpected Process call current state: %d", pRam->State);
            pRam->State = AES_ERROR;
        }

    }
    return Status;
}

Std_ReturnType UPDiAESDecoder_Transform(tUPDiAESDecoder* This, uint8* pDataIn, uint32* pSizeIn, uint8** ppTransformBuffer, uint32* pTransformSize)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This))
    {
    }
    //Ensure data is available
    else if(*pSizeIn > 0)
    {
        tUPDiAESDecoderRam *pRam = This->pRam;

        if(AES_TRANSFORM == pRam->State)
        {
            uint32 size_in = min(*pSizeIn, pRam->ImgPending);

            if(E_OK == UPD_ICry_Decrypt_Update(pDataIn, size_in, pRam->buffer, pTransformSize))
            {
                // Skip the bytes required in case we are comming from a suspend
                uint32 offset = min(pRam->BytesToSkip, *pTransformSize);

                *ppTransformBuffer = pRam->buffer + offset;
                *pTransformSize -= offset;
                pRam->BytesToSkip -= offset;
                pRam->ImgPending -= (size_in - offset);
                if(0 == pRam->ImgPending)
                {
                    pRam->State = AES_FINISHED;//AES_FINISHING;
                    // Hold 1 byte to force cypher finish to be called.
                    //*pSizeIn -= 1;
                }
                Status = E_OK;
            }
            else
            {
                pRam->State = AES_ERROR;
                UPDd_ERROR("Error during AES decryption");
            }
        }
        else if(AES_FINISHING == pRam->State)
        {
            if(E_OK == UPD_ICry_Decrypt_Final(pRam->buffer, pTransformSize))
            {
                *ppTransformBuffer = pRam->buffer;
                // Exhaust the data by not modifying pSizeIn.
                pRam->State = AES_FINISHED;
                Status = E_OK;
            }
            else
            {
                pRam->State = AES_ERROR;
                UPDd_ERROR("Error Finalizing AES decryption");
            }
        }
        else
        {
            pRam->State = AES_ERROR;
            UPDd_ERROR("Incorret state for AES Decoder: %u", pRam->State);
        }
    }
    return Status;
}

Std_ReturnType UPDiAESDecoder_Exit(tUPDiAESDecoder* This, tUPDiInstallSession* pSession)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This))
    {
    }
    else
    {
        tUPDiAESDecoderRam *pRam = This->pRam;
        if(AES_FINISHED == pRam->State)
        {
            Status = E_OK;
        }
        else
        {
            UPDd_ERROR("Incorret state for AES Decoder when calling exit: %u", pRam->State);
            This->pRam->State = AES_ERROR;
        }
    }
    return Status;
}

boolean UPDiAESDecoder_Rewind(tUPDiAESDecoder* This, uint32 FlashOffset, uint32* pImageOffset)
{
    boolean ContinueFlashing = FALSE;
    if (IsInvalid(This))
    {
    }
    else
    {
        tUPDiAESDecoderRam *pRam = This->pRam;
        switch (pRam->State)
        {
        case AES_FINISHING:
        case AES_FINISHED:
        {
            // Ensure the total image size is received as offset
            *pImageOffset = pRam->ImgSize;
            ContinueFlashing = TRUE;
            break;
        }
        case AES_TRANSFORM:
        {
            ContinueFlashing = TRUE;
            break;
        }
        // By default cannot rewind
        default:
            break;
        }

        if (ContinueFlashing)
        {
            uint32_t ChildOffset = pRam->Parent.Processed;

            // Ask the child to rewind up to the size where it has processed.
            ContinueFlashing = UPDAbstractInstaller_Rewind(pRam->Parent.pChild, FlashOffset, (uint32_t*)pImageOffset);

            // If the child can rewind
            // if(ContinueFlashing)
            // {
                // If verify if the child need to rewind
                ContinueFlashing = UPDiAESDecoder_RewindChunk(This, ChildOffset, pImageOffset);
                if(*pImageOffset)
                {
                    pRam->State = AES_TRANSFORM;
                }
            // }
        }
    }
    return ContinueFlashing;
}

Std_ReturnType UPDiAESDecoder_Serialize(tUPDiAESDecoder* This, tUPDStream *pStream)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This) && pStream)
    {
    }
    else
    {
        tUPDiAESDecoderRam *pRam = This->pRam;
        uint8 ChildInstallerId = UPDi_GetInstallerId(pRam->Parent.pChild);
        UPDi_SERIALIZE(pStream, pRam->ImgSize);
        UPDi_SERIALIZE(pStream, pRam->ImgPending);
        UPDi_SERIALIZE(pStream, pRam->BytesToSkip);
        UPDi_SERIALIZE(pStream, pRam->State);
        UPDi_SERIALIZE(pStream, ChildInstallerId);
        Status = E_OK;
    }
    return Status;
}

Std_ReturnType UPDiAESDecoder_DeSerialize(tUPDiAESDecoder* This, tUPDStream *pStream)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This) && pStream)
    {
    }
    else
    {
        tUPDiAESDecoderRam *pRam = This->pRam;
        uint8 ChildInstallerId;

        UPDi_DESERIALIZE(pStream, pRam->ImgSize, 0);
        UPDi_DESERIALIZE(pStream, pRam->ImgPending, 0);
        UPDi_DESERIALIZE(pStream, pRam->BytesToSkip, 0);
        UPDi_DESERIALIZE(pStream, pRam->State, AES_FINISHED);
        UPDi_DESERIALIZE(pStream, ChildInstallerId, -1);

        switch(pRam->State)
        {
            case AES_TRANSFORM:
            case AES_FINISHING:
            {
                // Restore Transform state
                pRam->Parent.State = eGenTransformingToChild;
                pRam->Parent.pChild = UPDi_GetInstallerbyId(ChildInstallerId);
                Status = UPDiAESDecoder_InitDecoder(This);
                break;
            }
            default:
            {
                UPDd_INFO("AES Decoder resetting from state: %u\n", pRam->State);
                pRam->State = AES_FINISHED;
                pRam->Parent.State = eGenReady;
                pRam->Parent.pTransformBuffer = NULL;
                pRam->Parent.ResumeAt = 0;
                break;
            }
        }
        Status = E_OK;
    }
    return Status;
}

//=====================================================================================================================
//  Private functions
//=====================================================================================================================
Std_ReturnType UPDiAESDecoder_InitDecoder(tUPDiAESDecoder* This)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This))
    {
    }
    else
    {
        tUPDiAESDecoderRam *pRam = This->pRam;
        if (E_OK == UPD_ICry_Decrypt_Init())
        {
            UPDiGenDecoder_Transform((tUPDiGenDecoder*)This, pRam->ImgPending);
            pRam->State = AES_TRANSFORM;
            Status = E_OK;
        }
        else
        {
            /* Error */
            pRam->State = AES_ERROR;
            UPDd_ERROR("Error initializing the AESdecryption context");
        }
    }
    return Status;
}

boolean UPDiAESDecoder_RewindChunk(tUPDiAESDecoder *This, uint32 FlashOffset, uint32* pImageOffset)
{
     boolean ContinueFlashing = FALSE;
    if (IsInvalid(This))
    {
    }
    else
    {
        tUPDiAESDecoderRam *pRam = This->pRam;
        // Determine by how much we shall rewind the encrypted image to aligh to the AES block size.
        uint32 childImageOff = pRam->Parent.Processed - FlashOffset;
        // Determine by how much we shall rewind the encrypted image to aligh to the AES block size.
        uint32_t encImgAlignRewSize = (childImageOff % AES_DECRYPT_BLOCK_LEN) + ADDITIONAL_SKIP_BYTES;
        // Determine by how much the encrypted image must be rewound
        uint32 encImgRewSize = *pImageOffset - childImageOff + encImgAlignRewSize;
        // Store the amount of bytes to skip when resuming the download
        pRam->BytesToSkip = 0;
        // Store the size of child image pending to be downloaded
        pRam->ImgPending = pRam->ImgSize - childImageOff;

        // ensure that we are able to rewind by the amount of bytes we need.
        // By calculating that we have received at least encImgRewSize bytes,
        // Otherwise just restart from the begining.
        // if(*pImageOffset > encImgRewSize)
        // {
        //     *pImageOffset = encImgRewSize;
        //     ContinueFlashing = TRUE;
        // }
    }
    return ContinueFlashing;
}
#endif /* UPD_AES_DECODER */
