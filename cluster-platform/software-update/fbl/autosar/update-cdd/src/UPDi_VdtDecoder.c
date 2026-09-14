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
#include "UPDi_VdtDecoder.h"
#include "UPDd.h"
#include <string.h> //for memcpy()
#include <stdint.h>

//#define VDT_DBG 1

#define OPTION_ENDBIT_MSK 0x01
//=====================================================================================================================
//  VTBL
//=====================================================================================================================
tUPDiGenDecoder_Vtbl UPDVdtDecoder_Vtbl =
{
    .GetExtension   = (tpfGetExtension)UPDiVdtDecoder_GetExtension,
    .InstallStart   = (tpfInstallStart)UPDiGenDecoder_InstallStart,
    .InstallData    = (tpfInstallData)UPDiGenDecoder_InstallData,
    .InstallExit    = (tpfInstallExit)UPDiGenDecoder_InstallExit,
    .Serialize      = (tpfSerialize)UPDiVdtDecoder_Serialize,
    .Deserialize    = (tpfDeserialize)UPDiVdtDecoder_Deserialize,
    .DecoderStart   = (tpfGenDecoder_Start)UPDiVdtDecoder_Start,
    .DecoderProcess = (tpfGenDecoder_Process)UPDiVdtDecoder_Process,
    .DecoderExit    = (tpfGenDecoder_Exit)UPDiVdtDecoder_Exit,
	.Transform      = (tpfGenDecoder_Transform)UPDiVdtDecoder_Transform,
};

//=====================================================================================================================
//  Private types
//=====================================================================================================================
typedef struct __attribute__((packed))
{
	char   id[3];
	uint8_t  headerSize;
	uint8_t  version;
	uint8_t  options;
	uint8_t  newSize[6];
	uint8_t  oldHash[4];
} tVdtHeader; // header of the VDT File

typedef struct __attribute__((packed)) sDeltaControl
{
    uint32_t ComposedSectionSize;
    uint32_t ComposedSectionSize_HIGH;
    uint32_t ExtraSectionSize;
    uint32_t ExtraSectionSize_HIGH;
    int32_t SkipedSectionSize; //can be negative
    int32_t SkipedSectionSize_HIGH;
} tVdlControlBlock;

//=====================================================================================================================
//  Private functions
//=====================================================================================================================
static boolean IsInvalid(tUPDiVdtDecoder* This)
{
    boolean ret = TRUE;
#ifndef UPDd_POINTER_TEST_DISABLED
    if (This != NULL)
    {
        ret = (This->Vtbl == NULL) || ( This->pRam == NULL);
    }
    if (ret)
    {
        UPDd_ERROR("UPDiVdtDecoder IsInvalid()");
    }
#else
    ret = FALSE;
#endif
    return ret;
}

/*=====================================================================================================================
* Std_ReturnType ExpandPackedInt(tUPDiVdtDecoder* This, uint8_t* pDataIn, uint32_t* pInSize, uint8_t* pDataOut, uint32_t* pOutSize)
* Function description : decode a packed integer from the VDT stream
* Return : Status
*=====================================================================================================================*/
Std_ReturnType ExpandPackedInt(tUPDiVdtDecoder* This, uint8_t* pDataIn, uint32_t* pInSize, uint8_t* pDataOut, uint32_t* pOutSize)
{
    Std_ReturnType Status = E_PENDING;
    tUPDiVdtDecoderRam* pRam = This->pRam;
    uint32_t Size = *pInSize;

    while(Size)
    {
    	uint8_t Byte = *pDataIn++;
    	pRam->PackedInt += (Byte & 0x7F) << pRam->Shift;
    	pRam->Shift+=7;
    	Size--;

        if ((Byte & 0x80) == pRam->EndMarker)
        {
		    // end marker found
        	Status = E_OK;
        	break;
        }
        else if(pRam->Shift>=64 )
        {
        	Status = E_NOT_OK;
        	break;
        }
    }

    *pInSize -= Size;
    *pOutSize = 0;

    return Status;
}

/*=====================================================================================================================
* Std_ReturnType ExpandNonZero(tUPDiVdtDecoder* This, uint8_t* pDataIn, uint32_t* pInSize, uint8_t* pDataOut, uint32_t* pOutSize)
* Function description : extract raw byte from the VDT stream, stop after the first zero
* Return : Status
*=====================================================================================================================*/
Std_ReturnType ExpandNonZero(tUPDiVdtDecoder* This, uint8_t* pDataIn, uint32_t* pInSize, uint8_t* pDataOut, uint32_t* pOutSize)
{
    Std_ReturnType Status = E_PENDING;
    uint32_t Size = min(*pOutSize,*pInSize);
    *pOutSize = 0;
    *pInSize = 0;

    // copy the data from In to Out and stop at the first 0
    while( Size-- )
    {
		*pDataOut++ = *pDataIn;
		(*pOutSize)++;
        (*pInSize)++;

		if(*pDataIn++==0)
    	{
			Status = E_OK;
    		break;
    	}
    }
    return Status;
}

/*=====================================================================================================================
* void ExpandZeros(tUPDiVdtDecoder* This, uint8_t* pDataIn, uint32_t* pInSize, uint8_t* pDataOut, uint32_t* pOutSize)
* Function description : expend consecutive zeros
* Return : None
*=====================================================================================================================*/
void ExpandZeros(tUPDiVdtDecoder* This, uint8_t* pDataIn, uint32_t* pInSize, uint8_t* pDataOut, uint32_t* pOutSize)
{
    tUPDiVdtDecoderRam* pRam = This->pRam;
	uint32_t Size = min(*pOutSize,pRam->PackedInt);
    *pOutSize = Size;
    *pInSize = 0;
    pRam->PackedInt-=Size;

    while( Size-- )
    {
    	*pDataOut++ = 0;
    }
}

//=====================================================================================================================
//  Public functions
//=====================================================================================================================


/*=====================================================================================================================
* const char* UPDiVdtDecoder_GetExtension(tUPDiVdtDecoder* This)
* Function description : return the specific file extension for this specific decoder
* Return : file extension
*=====================================================================================================================*/
const char* UPDiVdtDecoder_GetExtension(tUPDiVdtDecoder* This)
{
    return "vdt";
}

/*=====================================================================================================================
* Std_ReturnType UPDiVdtDecoder_ParseHeader(tUPDiVdtDecoder* This, tUPDiInstallSession* pSession)
* Function description : This function is called one the file header buffering is done
* 	It shall parse the header and accept or reject the request.
* Return : Status
*=====================================================================================================================*/
Std_ReturnType UPDiVdtDecoder_ParseHeader(tUPDiVdtDecoder* This, tUPDiInstallSession* pSession)
{
    Std_ReturnType Status = E_NOT_OK;
    tUPDiVdtDecoderRam* pRam = This->pRam;
    tVdtHeader* pHeader = (tVdtHeader*)&pRam->Parent.LoadBuffer[0];

    if (memcmp(pHeader->id, (void*)"vdt", sizeof(pHeader->id)) != 0)
    {
        UPDd_ERROR("UPDiDeltaInstaller: Wrong header");
    }
    else if (pHeader->headerSize != sizeof(tVdtHeader))
    {
        UPDd_ERROR("UPDiDeltaInstaller: Wrong header");
    }
    else if ((pHeader->newSize[4] != 0) || (pHeader->newSize[5] != 0))
    {
        UPDd_ERROR("UPDiDeltaInstaller: file size above 4GB are not supported");
    }
    else
    {
    	uint32_t i=sizeof(uint32_t);
    	uint32_t Size=0;
        while(i--)
        {
        	Size <<= 8;
        	Size += pHeader->newSize[i] ;
        }

        pRam->EndMarker = (pHeader->options & OPTION_ENDBIT_MSK) == OPTION_ENDBIT_MSK;
        // the incoming stream need to be filtered/transform on the fly
        // VDT encodes consecutive zeros symbolically, such zero need to be re-generated
        UPDiGenDecoder_LoadFilterStream((tUPDiGenDecoder*)This, sizeof(tVdlControlBlock));
        pRam->State = eVdtLoadingControlBlock;
        pRam->TransformState = eVdtExpandingInt;
        pRam->Shift =0;
        pRam->PackedInt =0;

        // Start the partition update
        Status = UPDiSession_StartPartitionUpdate(pSession, pRam->Parent.PackageName, Size, TRUE);
        pRam->ReadPos  = pSession->WritePos;
        pRam->WritePos = pSession->WritePos;
        pRam->LastWritePos  = Size + pSession->WritePos;
    }
    return Status;
}

/*=====================================================================================================================
* Std_ReturnType UPDiVdtDecoder_ParseControlBlock(tUPDiVdtDecoder* This, tUPDiInstallSession* pSession)
* Function description : This function is called one a VDT control block buffering is done
* 	The control block indicate the size of the next VDT Block with the composition & extra areas
* Return : Status
*=====================================================================================================================*/
Std_ReturnType UPDiVdtDecoder_ParseControlBlock(tUPDiVdtDecoder* This, tUPDiInstallSession* pSession)
{
    Std_ReturnType Status = E_NOT_OK;
    tUPDiVdtDecoderRam* pRam = This->pRam;
    tVdlControlBlock* pCB = (tVdlControlBlock*)&pRam->Parent.LoadBuffer[0];

    // SkipedSectionSize can be negative, the sign is encoded with the LSB bit
    if (pCB->SkipedSectionSize & 0x01)
    {
    	pCB->SkipedSectionSize --;
        pCB->SkipedSectionSize *= -1;
        pCB->SkipedSectionSize >>=1;
    }
    else
    {
        pCB->SkipedSectionSize >>=1;
    }
#if VDT_DBG
    printf(" - %d %d\n", pRam->WritePos,pRam->ReadPos);
    printf("[%d %d %d]", pCB->ComposedSectionSize,pCB->ExtraSectionSize,pCB->SkipedSectionSize);
    fflush(stdout);
#endif

    // Verify the Control block validity
    if ((pCB->ComposedSectionSize_HIGH != 0) || (pCB->ExtraSectionSize_HIGH != 0) || (pCB->SkipedSectionSize_HIGH != 0))
    {
        UPDd_ERROR("UPDiDeltaInstaller: Size above 32bits");
    }
    else
    {
        pRam->ComposedSectionSize = pCB->ComposedSectionSize;
        pRam->ExtraSectionSize = pCB->ExtraSectionSize;
        pRam->SkipedSectionSize = pCB->SkipedSectionSize;

        pRam->State = eVdtLoadingComposedBlock;
        pRam->TransformState = eVdtExpandingNonZero;
        UPDiGenDecoder_LoadFilterStream((tUPDiGenDecoder*)This, pRam->ComposedSectionSize);

        Status = E_OK;
    }
    return Status;
}

/*=====================================================================================================================
* Std_ReturnType UPDiVdtDecoder_Transform(tUPDiVdtDecoder* This, uint8_t* pDataIn, uint32_t* pSizeIn, uint8_t** ppDataOut, uint32_t* pOutSize)
* Function description : main filtering function, it controls the curent filtering state and request the specific extraction
* Return : Status
*=====================================================================================================================*/
Std_ReturnType UPDiVdtDecoder_Transform(tUPDiVdtDecoder* This, uint8_t* pDataIn, uint32_t* pSizeIn, uint8_t** ppDataOut, uint32_t* pOutSize)
{
    Std_ReturnType Status = E_OK;
	tUPDiVdtDecoderRam* pRam = This->pRam;
    uint8_t* pDataOut =  *ppDataOut;
	uint32_t remaingIn=*pSizeIn;
	uint32_t remaingOut=*pOutSize;
	uint32_t processedIn=0;
	uint32_t processedOut=0;

	while( (remaingIn || (pRam->TransformState==eVdtExpandingZero)) && remaingOut )

	{
		uint32_t In=remaingIn;
		uint32_t Out=remaingOut;

		switch (pRam->TransformState)
		{
		case(eVdtExpandingNonZero):
			Status =ExpandNonZero(This, pDataIn, &In, pDataOut, &Out);
#if VDT_DBG
			printf(" %d",(int)Out);
#endif
			// all inputs data have been processed, let's read the number of zero
			if(Status==E_OK)
			{
				pRam->TransformState = eVdtExpandingInt;
				pRam->PackedInt = 0;
				pRam->Shift =0;
			}
			else if(Status==E_PENDING)
			{
				Status=E_OK;
			}
			break;

		case(eVdtExpandingInt):
			(*pOutSize) =0;
			Status = ExpandPackedInt(This, pDataIn, &In, pDataOut, &Out);
			if(Status==E_PENDING)
			{
				Status=E_OK;
			}
			else if( Status!=E_OK )
			{
				// it's an Invalid vdt stream
				break;
			}
			else if (pRam->State == eVdtLoadingControlBlock)
			{
				// let's store the control block data in the output buffer
				*(uint64_t*)(&pRam->Parent.LoadBuffer[pRam->Parent.Processed+processedOut]) = pRam->PackedInt;
				Out=sizeof(pRam->PackedInt);
				pRam->PackedInt = 0;
				pRam->Shift =0;
#if VDT_DBG
			printf(".");
#endif

			}
			else if(pRam->PackedInt)
			{
				pRam->TransformState = eVdtExpandingZero;
			}
			else
			{
				pRam->TransformState = eVdtExpandingNonZero;
			}
		break;

		case(eVdtExpandingZero):
			ExpandZeros(This, pDataIn, &In, pDataOut, &Out);
#if VDT_DBG
			printf("[%d]",(int)Out);
#endif
			if(pRam->PackedInt==0)
			{
				// All zeros as been generated, let's continue the data extraction
				pRam->TransformState = eVdtExpandingNonZero;
			}
			break;

		default :
			break;
		}
		processedIn  +=In;
		remaingIn    -=In;
		pDataIn      +=In;
		processedOut +=Out;
		remaingOut   -=Out;
		pDataOut     +=Out;
	}

#if VDT_DBG
	if( remaingIn==0 )
	{
		printf("-no in-");
		if(pRam->TransformState==eVdtExpandingInt)
			printf(" ");
	}
	if( remaingOut==0 )
		printf("-no out-");
#endif

	*pSizeIn  = processedIn;
	*pOutSize = processedOut;
    return Status;
}

/*=====================================================================================================================
* Std_ReturnType UPDiVdtDecoder_ProcessComposedBlock(tUPDiVdtDecoder* This, tUPDiInstallSession* pSession)
* Function description : This function is called once a chunk of a composed block have been filtered and extracted
*  it requires the composition to the session class
* Return : Status
*=====================================================================================================================*/
Std_ReturnType UPDiVdtDecoder_ProcessComposedBlock(tUPDiVdtDecoder* This, tUPDiInstallSession* pSession)
{
    Std_ReturnType Status = E_NOT_OK;
    tUPDiVdtDecoderRam* pRam = This->pRam;
    
    Status = UPDiSession_ComposeNext(pSession,pRam->ReadPos, pRam->Parent.LoadBuffer, pRam->Parent.ChunkSize);
    if (Status == E_OK)
    {
        pRam->WritePos += pRam->Parent.ChunkSize;
        pRam->ReadPos += pRam->Parent.ChunkSize;
        if (pRam->Parent.State != eGenLoadingFilteringStream)
        {
            // Composition block is done
        	UPDiGenDecoder_LoadStream((tUPDiGenDecoder*)This,  pRam->ExtraSectionSize);
            pRam->State = eVdtLoadingExtraBlock;
        }
    }
    return Status;
}

/*=====================================================================================================================
* Std_ReturnType UPDiVdtDecoder_ProcessExtraBlock(tUPDiVdtDecoder* This, tUPDiInstallSession* pSession)
* Function description : This function is called once a chunk of an extra block have been extracted
*  it requires the flashing to the session class
* Return : Status
*=====================================================================================================================*/
Std_ReturnType UPDiVdtDecoder_ProcessExtraBlock(tUPDiVdtDecoder* This, tUPDiInstallSession* pSession)
{
    Std_ReturnType Status = E_NOT_OK;
    tUPDiVdtDecoderRam* pRam = This->pRam;

    Status = UPDiSession_WriteNext(pSession, pRam->Parent.LoadBuffer, pRam->Parent.ChunkSize);
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

            UPDiGenDecoder_LoadFilterStream((tUPDiGenDecoder*)This, sizeof(tVdlControlBlock));
            pRam->State = eVdtLoadingControlBlock;
            pRam->TransformState = eVdtExpandingInt;
            pRam->Shift =0;
            pRam->PackedInt =0;
        }
        else
        { 
            // Patch is now completed
            pRam->State = eVdtDone;
        }
    }
    return Status;
}

/*=====================================================================================================================
* Std_ReturnType UPDiVdtDecoder_Start(tUPDiVdtDecoder* This, tUPDiInstallSession* pSession, const char* PackageName, uint32_t Size)
* Function description : This function is called when the decoding of a VDT image need to start
* Return : Status
*=====================================================================================================================*/
Std_ReturnType UPDiVdtDecoder_Start(tUPDiVdtDecoder* This, tUPDiInstallSession* pSession, const char* PackageName, uint32_t Size)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This))
    {
    }
    else
    {
        tUPDiVdtDecoderRam* pRam = This->pRam;
        UPDiGenDecoder_Load((tUPDiGenDecoder*)This, sizeof(tVdtHeader));
        pRam->State = eVdtLoadingHeader;
        Status = E_OK;
    }
    return Status;
}

/*=====================================================================================================================
* Std_ReturnType UPDiVdtDecoder_Process(tUPDiVdtDecoder* This, tUPDiInstallSession* pSession)
* Function description : Main function of the decoder, it's called when on each decoding event
* Return : Status
*=====================================================================================================================*/
Std_ReturnType UPDiVdtDecoder_Process(tUPDiVdtDecoder* This, tUPDiInstallSession* pSession)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This))
    {
    }
    else
    {
        tUPDiVdtDecoderRam* pRam = This->pRam;
        switch (pRam->State)
        {
        case(eVdtLoadingHeader):
            Status = UPDiVdtDecoder_ParseHeader(This, pSession);
            break;

        case(eVdtLoadingControlBlock):
			if( pRam->Parent.Processed==sizeof(tVdlControlBlock))
			{
				Status = UPDiVdtDecoder_ParseControlBlock(This, pSession);
			}
			else
			{
				Status=E_OK;
			}
            break;

        case(eVdtLoadingComposedBlock):
            Status = UPDiVdtDecoder_ProcessComposedBlock(This, pSession);
            break;

        case(eVdtLoadingExtraBlock):
            Status = UPDiVdtDecoder_ProcessExtraBlock(This, pSession);
            break;

        default :
            Status = E_NOT_OK;
            break;
        }
    }
    return Status;
}

/*=====================================================================================================================
* Std_ReturnType UPDiVdtDecoder_Process(tUPDiVdtDecoder* This, tUPDiInstallSession* pSession)
* Function description : Main function is called when the image decoding finish
* Return : Status
*=====================================================================================================================*/
Std_ReturnType UPDiVdtDecoder_Exit(tUPDiVdtDecoder* This, tUPDiInstallSession* pSession)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This))
    {
    }
    else 
    {
        tUPDiVdtDecoderRam* pRam = This->pRam;
        if (pRam->State == eVdtDone)
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

/*=====================================================================================================================
* Std_ReturnType UPDiVdtDecoder_Serialize(tUPDiVdtDecoder* This, tUPDStream *pStream)
* Function description : Serialize the persistent state of the decoder
* As VDT do not support suspend & resume, this function is empty
* Return : Status
*=====================================================================================================================*/
Std_ReturnType UPDiVdtDecoder_Serialize(tUPDiVdtDecoder* This, tUPDStream *pStream)
{
	return E_OK;
}

/*=====================================================================================================================
* Std_ReturnType Std_ReturnType UPDiVdtDecoder_Deserialize(tUPDiVdtDecoder* This, tUPDStream *pStream)
* Function description : Deserialize the persistent state of the decoder
* As VDT do not support suspend & resume, this initialize the attributes in RAM
* Return : Status
*=====================================================================================================================*/
Std_ReturnType UPDiVdtDecoder_Deserialize(tUPDiVdtDecoder* This, tUPDStream *pStream)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This))
    {
    }
    else
    {
        tUPDiVdtDecoderRam* pRam = This->pRam;
        memset(pRam,0, sizeof(tUPDiVdtDecoderRam));
    }
    return Status;
}

