/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2023. Visteon Corporation owns all rights to           *
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

#include "UPDi.h"
#include "UPDi_TarDecoder.h"
#include <string.h>

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

// TODO_EBX : Secured container
// TODO_EBX : Target container and container of targets
//=====================================================================================================================
//  Static Variables
//=====================================================================================================================
tUPDiGenDecoder_Vtbl UPDTarDecoder_Vtbl =
{
    .GetExtension   = (tpfGetExtension)UPDiTarDecoder_GetExtension,
    .InstallStart   = (tpfInstallStart)UPDiGenDecoder_InstallStart,
    .InstallData    = (tpfInstallData)UPDiGenDecoder_InstallData,
    .InstallExit    = (tpfInstallExit)UPDiGenDecoder_InstallExit,
    .Serialize      = (tpfSerialize)UPDiTarDecoder_Serialize,
    .Deserialize    = (tpfDeserialize)UPDiTarDecoder_Deserialize,
	.Rewind         = (tpfRewind)UPDiTarDecoder_Rewind,
    .DecoderStart   = (tpfGenDecoder_Start)UPDiTarDecoder_Start,
    .DecoderProcess = (tpfGenDecoder_Process)UPDiTarDecoder_Process,
    .DecoderExit    = (tpfGenDecoder_Exit)UPDiTarDecoder_Exit,
};

//=====================================================================================================================
//  Private functions
//=====================================================================================================================
static boolean UPDTarDecoder_IsInvalid(tUPDiTarDecoder* this)
{
    boolean ret = TRUE;
#ifndef UPDd_POINTER_TEST_DISABLED
    if (this != NULL)
    {
        ret = (this->Vtbl == NULL);
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
static uint32_t fromOctal(char* ptr, uint32_t size)
{
    uint32_t Val = 0;
    uint32_t i = 0;
    for (i = 0; i < size; i++)
    {
        char c = ptr[i];
        if (c >= '0' && c <= '7')
        {
            Val *= 8;
            Val += c - '0';
        }
        else if (c == 0)
        {
            return Val;
        }
    }
    return Val;
}
static boolean IsValidTarHeader(tUPDiTarDecoder* This, tUPDiTarHeader* pHeader)
{
    boolean IsValid = FALSE;

    // Make sure that the filename is NULL terminated.
    if (strnlen(pHeader->name, sizeof(pHeader->name)) >= sizeof(pHeader->name))
    {
    }
    else if (strnlen(pHeader->chksum, sizeof(pHeader->chksum)) >= sizeof(pHeader->chksum))
    {

    }
    else
    {
        // Calculate Checksum
        int32_t ChecksumOfSigned = 0;
        int32_t ChecksumOfUnsigned = 0;
        uint32_t Size = sizeof(tUPDiTarHeader);// UPDITAR_BLOCK_SIZE;
        uint8_t* ptr = (uint8_t*)pHeader;
        while (Size--)
        {
            ChecksumOfUnsigned += *ptr;
            ChecksumOfSigned += *(int32_t*)ptr;
            ptr++;
        }
        Size = sizeof(pHeader->chksum);
        ptr = (uint8_t*)&(pHeader->chksum);
        while (Size--)
        {
            ChecksumOfUnsigned -= *ptr;
            ChecksumOfSigned -= *(int32_t*)ptr;
            ptr++;
        }
        ChecksumOfUnsigned += ' ' * sizeof(pHeader->chksum);
        ChecksumOfSigned += ' ' * sizeof(pHeader->chksum);

        // Read checksum
        uint32_t ExpectedChecksum = fromOctal(pHeader->chksum, sizeof(pHeader->chksum));

        // Compare checksums
        if ((ChecksumOfUnsigned == ExpectedChecksum) || (ChecksumOfUnsigned == ExpectedChecksum))
        {
            IsValid = TRUE;
        }
    }
    return IsValid;
}

static boolean IsBlank(uint8_t* pBuffer, uint32_t size)
{
    boolean isBlank = TRUE;

    while ((size--) && (isBlank))
    {
        if (*pBuffer++)
        {
            isBlank = FALSE;
        }
    }
    return isBlank;
}


//=====================================================================================================================
//  Public functions
//=====================================================================================================================
const char* UPDiTarDecoder_GetExtension(tUPDiTarDecoder* This)
{
    return "tar";
}
Std_ReturnType UPDiTarDecoder_ParseHeader(tUPDiTarDecoder* This)
{
    Std_ReturnType Status = E_NOT_OK;
    tUPDiTarDecoderRam* pRam = This->pRam;
    tUPDiTarHeader* pHeader = (tUPDiTarHeader*)&pRam->Parent.LoadBuffer[0];

    if (IsBlank(&pRam->Parent.LoadBuffer[0], sizeof(tUPDiTarHeader)))
    {
        // A blank block indicate the end of archive
        UPDiGenDecoder_Load((tUPDiGenDecoder*)This, UPDITAR_BLOCK_SIZE);
        pRam->State = eTarLoadingEndOfArchive;
        pRam->PaddingSize = UPDITAR_BLOCK_SIZE;
        Status = E_OK;
    }
    else if (! IsValidTarHeader(This, pHeader))
    {
        UPDd_ERROR("UPDTarDecoder_InstallData() unrecognized header");
    }
    else
    {
        uint32_t FileSize = fromOctal(pHeader->size, sizeof(pHeader->size));
        UPDiGenDecoder_Install( (tUPDiGenDecoder*)This, &pHeader->name[0], FileSize);
        pRam->State = eTarInstallingFile;
        pRam->PaddingSize = (-FileSize % UPDITAR_BLOCK_SIZE);
        Status = E_OK;
    }

    return Status;
}
Std_ReturnType UPDiTarDecoder_LoadPadding(tUPDiTarDecoder* This)
{
    tUPDiTarDecoderRam* pRam = This->pRam;
    UPDiGenDecoder_Load((tUPDiGenDecoder*)This, pRam->PaddingSize);
    pRam->State = eTarLoadingPadding;
    return E_OK;
}
Std_ReturnType UPDiTarDecoder_ParsePadding(tUPDiTarDecoder* This)
{
    Std_ReturnType Status = E_NOT_OK;
    tUPDiTarDecoderRam* pRam = This->pRam;
    if (IsBlank(pRam->Parent.LoadBuffer,pRam->PaddingSize) )
    {
        UPDiGenDecoder_Load((tUPDiGenDecoder*)This, UPDITAR_BLOCK_SIZE);
        pRam->State = eTarLoadingHeader;
        Status = E_OK;
    }
    else
    {
        UPDd_ERROR("UPDiTarDecoder_ParsePadding() Invalid Padding");
    }
    return Status;
}
Std_ReturnType UPDiTarDecoder_ParseEndOfArchive(tUPDiTarDecoder* This)
{
    Std_ReturnType Status = E_NOT_OK;
    tUPDiTarDecoderRam* pRam = This->pRam;
    if (IsBlank(pRam->Parent.LoadBuffer, pRam->PaddingSize))
    {
        pRam->State = eTarDone;
        Status = E_OK;
    }
    else
    {
        UPDd_ERROR("UPDiTarDecoder_ParseEndOfArchive() Invalid Padding");
    }
    return Status;
}
Std_ReturnType UPDiTarDecoder_Start(tUPDiTarDecoder* This, tUPDiInstallSession* pSession, const char* PackageName, uint32_t Size)
{
    Std_ReturnType Status = E_NOT_OK;
    if (UPDTarDecoder_IsInvalid(This))
    {
    }
    else
    {
        tUPDiTarDecoderRam* pRam = This->pRam;
        UPDiGenDecoder_Load((tUPDiGenDecoder*)This, UPDITAR_BLOCK_SIZE);
        pRam->State = eTarLoadingHeader;
        Status = E_OK;
        // TODO_EBX Start Target
    }
    return Status;
}
Std_ReturnType UPDiTarDecoder_Process(tUPDiTarDecoder* This,tUPDiInstallSession* pSession)
{
    Std_ReturnType Status = E_NOT_OK;
    if (UPDTarDecoder_IsInvalid(This))
    {
    }
    else
    {
        tUPDiTarDecoderRam* pRam = This->pRam;
        switch (pRam->State)
        {
        case(eTarDone):
            //Nothing to do if eTarDone
            break;

        case(eTarLoadingHeader):
            Status = UPDiTarDecoder_ParseHeader(This);
            break;

        case(eTarInstallingFile):
            Status = UPDiTarDecoder_LoadPadding(This);
            break;

        case(eTarLoadingPadding):
            Status = UPDiTarDecoder_ParsePadding(This);
            break;

        case(eTarLoadingEndOfArchive):
            Status = UPDiTarDecoder_ParseEndOfArchive(This);
            break;
        }
    }
    return Status;
}
Std_ReturnType UPDiTarDecoder_Exit(tUPDiTarDecoder* This, tUPDiInstallSession* pSession)
{
    Std_ReturnType Status = E_NOT_OK;
    if (UPDTarDecoder_IsInvalid(This))
    {
    }
    else 
    {
        tUPDiTarDecoderRam* pRam = This->pRam;
        if (pRam->State == eTarDone)
        {
            return E_OK;
        }
    }
    return Status;
}
boolean UPDiTarDecoder_Rewind(tUPDiTarDecoder* This, uint32_t FlashOffset, uint32_t* pImageOffset )
{
    Std_ReturnType ContinueFlashing = FALSE;
    if (UPDTarDecoder_IsInvalid(This))
    {
    }
    else
    {
        tUPDiTarDecoderRam* pRam = This->pRam;
        if(pRam->Parent.Processed < FlashOffset)
		{
			// Unexpected situation, we are asked to return on the previous image area.
			// return at the beginning of full package
			UPDd_WARNING("Invalid Tar suspend request, cannot return above the ongoing TAR section");
			*pImageOffset = pRam->Parent.NextByte;
			 pRam->State = eTarLoadingHeader;
		}
        else
       	if(pRam->State == eTarInstallingFile)
        {
        	uint32_t ChildOffset = pRam->Parent.Processed;
        	ContinueFlashing = UPDAbstractInstaller_Rewind(pRam->Parent.pChild,FlashOffset,&ChildOffset);
        	if(ContinueFlashing )
        	{
				// return on the beginning of the previous Tar header
				*pImageOffset = ChildOffset;
				 pRam->Parent.ToProcess += ChildOffset;
				 pRam->Parent.Processed -= ChildOffset;
        	}
        	else
        	{
				// return on the beginning of the last tar header
				*pImageOffset = pRam->Parent.Processed + sizeof(tUPDiTarHeader);
				 pRam->State = eTarLoadingHeader;
				 pRam->Parent.ToProcess =0;
				 pRam->Parent.Processed = 0;
        	}
        }
        else if( (pRam->State == eTarLoadingHeader)       ||
        		 (pRam->State == eTarLoadingPadding)      ||
				 (pRam->State == eTarLoadingEndOfArchive) /*||
				 (pRam->State == eTarDone )*/                  )
        {
			// return on the beginning the data block (tar header or padding)
			*pImageOffset = pRam->Parent.Processed;
			 pRam->Parent.ToProcess = 0;
			 pRam->Parent.Processed = 0;
        }
        else if( pRam->State == eTarDone )
        {
			*pImageOffset = 0;
        }
        else
        {
        	// Unexpected state : return at the beginning of full package
        	*pImageOffset = pRam->Parent.NextByte;
        	UPDd_WARNING("Unexpected TAR State");
			pRam->State = eTarLoadingHeader;
        }
    }
	return ContinueFlashing;
}

Std_ReturnType UPDiTarDecoder_Serialize(tUPDiTarDecoder* This, tUPDStream *pStream)
{
    Std_ReturnType Status = E_NOT_OK;
    if (!UPDTarDecoder_IsInvalid(This) && pStream)
    {
        tUPDiTarDecoderRam* pRam = This->pRam;
		uint8_t ChildInstallerId = UPDi_GetInstallerId(pRam->Parent.pChild);

		UPDi_SERIALIZE(pStream, pRam->State);
		UPDi_SERIALIZE(pStream, pRam->PaddingSize);
		UPDi_SERIALIZE(pStream, pRam->Parent.Processed);
		UPDi_SERIALIZE(pStream, pRam->Parent.ToProcess);
		UPDi_SERIALIZE(pStream, ChildInstallerId);
    }
    return Status;
}
Std_ReturnType UPDiTarDecoder_Deserialize(tUPDiTarDecoder* This, tUPDStream *pStream)
{
    Std_ReturnType Status = E_NOT_OK;
    if (!UPDTarDecoder_IsInvalid(This) && pStream)
    {
        tUPDiTarDecoderRam* pRam = This->pRam;
        uint8_t ChildInstallerId;

        memset( pRam, 0, sizeof(*pRam));
		pRam->Parent.State = eGenIdle;

		UPDi_DESERIALIZE(pStream, pRam->State, eTarDone);
		UPDi_DESERIALIZE(pStream, pRam->PaddingSize, 0);
		UPDi_DESERIALIZE(pStream, pRam->Parent.Processed, 0);
		UPDi_DESERIALIZE(pStream, pRam->Parent.ToProcess, 0);
		UPDi_DESERIALIZE(pStream, ChildInstallerId, -1);

		if( pRam->State == eTarInstallingFile)
		{
	        pRam->Parent.State = eGenInstallingChild;
	        pRam->Parent.pChild = UPDi_GetInstallerbyId(ChildInstallerId);
		}
		else if( pRam->State == eTarLoadingHeader)
		{
			UPDiGenDecoder_Load((tUPDiGenDecoder*)This, UPDITAR_BLOCK_SIZE);
		}
		else if( pRam->State == eTarLoadingPadding)
		{
			UPDiGenDecoder_Load((tUPDiGenDecoder*)This, pRam->PaddingSize);
		}
		else if( pRam->State == eTarLoadingEndOfArchive)
		{
			UPDiGenDecoder_Load((tUPDiGenDecoder*)This, UPDITAR_BLOCK_SIZE);
			pRam->PaddingSize = UPDITAR_BLOCK_SIZE;
		}
		else if( pRam->State == eTarDone)
		{
			 pRam->Parent.State = eGenReady;
		}
		else
		{
			pStream->badData=TRUE;
			UPDd_WARNING("Deserializing unexpected Tar decoder state");
		}
	}
    return Status;
}
