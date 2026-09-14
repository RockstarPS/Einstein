#include "UPDi_DeltaDecoder.h"
#include "UPDd.h"
#include <string.h> // memcpy
#include <stdint.h>

//=====================================================================================================================
//  Private functions
//=====================================================================================================================
static boolean IsInvalid(tUPDiDeltaDecoder* This)
{
    boolean ret = TRUE;
#ifndef UPDd_POINTER_TEST_DISABLED
    if (This != NULL)
    {
        ret = (This->Vtbl == NULL) || ( This->pRam == NULL);
    }
    if (ret)
    {
        UPDd_ERROR("UPDiDeltaDecoder IsInvalid()");
    }
#else
    ret = FALSE;
#endif
    return ret;
}

const char* UPDiDeltaDecoder_GetExtension(tUPDiDeltaDecoder* This)
{
    return "dt";
}

Std_ReturnType UPDiDeltaDecoder_ParseHeader(tUPDiDeltaDecoder* This, tUPDiInstallSession* pSession)
{
    Std_ReturnType Status = E_NOT_OK;
    tUPDiDeltaDecoderRam* pRam = This->pRam;
    tUPDiDeltaHeader* pHeader = (tUPDiDeltaHeader*)&pRam->Parent.LoadBuffer[0];

    if (memcmp(pHeader->FileTypeIdent, "ENDSLEY/BSDIFF43", sizeof(pHeader->FileTypeIdent)) != 0)
    {
        UPDd_ERROR("UPDiDeltaInstaller: Wrong header");
    }
    else if (0) // TBD check destination partition size
    {
        UPDd_ERROR("UPDiDeltaInstaller: Buffer is too small");
    }
    else if (pHeader->NewSize_HIGH != 0)
    {
        UPDd_ERROR("UPDiDeltaInstaller: size above 4GB are not supported");
    }
    else
    {
        UPDiGenDecoder_Load((tUPDiGenDecoder*)This, sizeof(tUPDiDeltaControl));
        pRam->State = eDeltaLoadingControlBlock;    

        Status = UPDiSession_StartPartitionUpdate(pSession, pRam->Parent.PackageName, pHeader->NewSize, TRUE);
        pRam->ReadPos  = pSession->WritePos;
        pRam->WritePos = pSession->WritePos;
        pRam->LastWritePos  = pHeader->NewSize + pSession->WritePos;
    }

    return Status;
}

Std_ReturnType UPDiDeltaDecoder_ParseControlBlock(tUPDiDeltaDecoder* This, tUPDiInstallSession* pSession)
{
    Std_ReturnType Status = E_NOT_OK;
    tUPDiDeltaDecoderRam* pRam = This->pRam;
    tUPDiDeltaControl* pCB = (tUPDiDeltaControl*)&pRam->Parent.LoadBuffer[0];

    if (pCB->SkipedSectionSize_HIGH & 0x80000000)
    {
        pCB->SkipedSectionSize_HIGH &= ~0x80000000;
        pCB->SkipedSectionSize *= -1;
    }
    // Verfiy the Control block validity
     if ((pCB->ComposedSectionSize_HIGH != 0x00) || (pCB->ExtraSectionSize_HIGH != 0x00) || (pCB->SkipedSectionSize_HIGH != 0x00))
    {
        UPDd_ERROR("UPDiDeltaInstaller: Size above 32bits");
    }
    else
    {
        pRam->ComposedSectionSize = pCB->ComposedSectionSize;
        pRam->ExtraSectionSize = pCB->ExtraSectionSize;
        pRam->SkipedSectionSize = pCB->SkipedSectionSize;

        pRam->State = eDeltaLoadingComposedBlock;
        UPDiGenDecoder_LoadStream((tUPDiGenDecoder*)This, pRam->ComposedSectionSize );

        Status = E_OK;
    }
    return Status;
}

Std_ReturnType UPDiDeltaDecoder_ProcessComposedBlock(tUPDiDeltaDecoder* This, tUPDiInstallSession* pSession)
{
    Std_ReturnType Status = E_NOT_OK;
    tUPDiDeltaDecoderRam* pRam = This->pRam;
    
    Status = UPDiSession_ComposeNext(pSession,pRam->ReadPos, pRam->Parent.LoadBuffer, pRam->Parent.ChunkSize);
    if (Status == E_OK)
    {
        pRam->WritePos += pRam->Parent.ChunkSize;
        pRam->ReadPos += pRam->Parent.ChunkSize;
        if (pRam->Parent.State != eGenLoadingStream)
        {
            // Composition block is done
            UPDiGenDecoder_LoadStream((tUPDiGenDecoder*)This,  pRam->ExtraSectionSize);
            pRam->State = eDeltaLoadingExtraBlock;
        }
    }
    return Status;
}

Std_ReturnType UPDiDeltaDecoder_ProcessExtraBlock(tUPDiDeltaDecoder* This, tUPDiInstallSession* pSession)
{
    Std_ReturnType Status = E_NOT_OK;
    tUPDiDeltaDecoderRam* pRam = This->pRam;

    Status = UPDiSession_WriteNext(pSession, /*pRam->WritePos,*/ pRam->Parent.LoadBuffer, pRam->Parent.ChunkSize);
    if (Status == E_OK)
    {
        pRam->WritePos += pRam->Parent.ChunkSize;
        if (pRam->Parent.State == eGenLoadingStream)
        {
            //Extra block is not done
        }
        else if(pRam->WritePos<pRam->LastWritePos)
        {
            // Extra block is done but patch is not completed
            pRam->ReadPos += pRam->SkipedSectionSize;
            UPDiGenDecoder_Load((tUPDiGenDecoder*)This, sizeof(tUPDiDeltaControl));
            pRam->State = eDeltaLoadingControlBlock;
        }
        else
        { 
            // Patch is not completed
            pRam->State = eDeltaDone;
        }
    }
    return Status;
}
//=====================================================================================================================
//  Public functions
//=====================================================================================================================
tUPDiGenDecoder_Vtbl UPDDeltaDecoder_Vtbl =
{
    .GetExtension   = (tpfGetExtension)UPDiDeltaDecoder_GetExtension,
    .InstallStart   = (tpfInstallStart)UPDiGenDecoder_InstallStart,
    .InstallData    = (tpfInstallData)UPDiGenDecoder_InstallData,
    .InstallExit    = (tpfInstallExit)UPDiGenDecoder_InstallExit,
    .Serialize      = (tpfSerialize)UPDiDeltaDecoder_Serialize,
    .Deserialize    = (tpfDeserialize)UPDiDeltaDecoder_Deserialize,
    .DecoderStart   = (tpfGenDecoder_Start)UPDiDeltaDecoder_Start,
    .DecoderProcess = (tpfGenDecoder_Process)UPDiDeltaDecoder_Process,
    .DecoderExit    = (tpfGenDecoder_Exit)UPDiDeltaDecoder_Exit,
};

Std_ReturnType UPDiDeltaDecoder_Start(tUPDiDeltaDecoder* This, tUPDiInstallSession* pSession, const char* PackageName, uint32_t Size)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This))
    {
    }
    else
    {
        tUPDiDeltaDecoderRam* pRam = This->pRam;
        UPDiGenDecoder_Load((tUPDiGenDecoder*)This, sizeof(tUPDiDeltaHeader));
        pRam->State = eDeltaLoadingHeader;
        Status = E_OK;
    }
    return Status;
}

Std_ReturnType UPDiDeltaDecoder_Process(tUPDiDeltaDecoder* This, tUPDiInstallSession* pSession)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This))
    {
    }
    else
    {
        tUPDiDeltaDecoderRam* pRam = This->pRam;
        switch (pRam->State)
        {
        case(eDeltaLoadingHeader):
            Status = UPDiDeltaDecoder_ParseHeader(This, pSession);
            break;

        case(eDeltaLoadingControlBlock):
            Status = UPDiDeltaDecoder_ParseControlBlock(This, pSession);
            break;

        case(eDeltaLoadingComposedBlock):
            Status = UPDiDeltaDecoder_ProcessComposedBlock(This, pSession);
            break;

        case(eDeltaLoadingExtraBlock):
            Status = UPDiDeltaDecoder_ProcessExtraBlock(This, pSession);
            break;

        default :
            Status = E_NOT_OK;
            break;
        }
    }
    return Status;
}

Std_ReturnType UPDiDeltaDecoder_Exit(tUPDiDeltaDecoder* This, tUPDiInstallSession* pSession)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This))
    {
    }
    else 
    {
        tUPDiDeltaDecoderRam* pRam = This->pRam;
        if (pRam->State == eDeltaDone)
        {
            Status = UPDiSession_FinishPartitionUpdate(pSession);
        }
        else
        {
            Status = E_NOT_OK;
        }
    }
    return Status;
}

Std_ReturnType UPDiDeltaDecoder_Serialize(tUPDiDeltaDecoder* This, tUPDStream *pStream)
{
	return E_OK;
}

Std_ReturnType UPDiDeltaDecoder_Deserialize(tUPDiDeltaDecoder* This, tUPDStream *pStream)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This))
    {
    }
    else
    {
        tUPDiDeltaDecoderRam* pRam = This->pRam;
        memset(pRam,0, sizeof(tUPDiDeltaDecoderRam));
    }
    return Status;
}

