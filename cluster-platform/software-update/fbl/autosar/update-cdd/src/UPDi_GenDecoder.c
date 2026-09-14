
#include "UPDi_GenDecoder.h"
#include "UPDd.h"
#include "UPDi.h"
#include <string.h>

//=====================================================================================================================
//  Private functions
//=====================================================================================================================
static boolean IsInvalid(tUPDiGenDecoder* This)
{
    boolean ret = TRUE;
#ifndef UPDd_POINTER_TEST_DISABLED
    if (This != NULL)
    {
        ret = (This->Vtbl == NULL) || ( This->pRam == NULL);
    }
    if (ret)
    {
        UPDd_ERROR("UPDiGenDecoder IsInvalid()");
    }
#else
    ret = FALSE;
#endif
    return ret;
}

static Std_ReturnType InstallData_Loading(tUPDiGenDecoder* This, tUPDiInstallSession* pSession, uint8_t* Data, uint32_t* pInSize, uint32_t* pOutSize)
{
    tUPDiGenDecoderRam* pRam = This->pRam;
    *pOutSize = *pInSize = min(*pInSize, pRam->ToProcess);
    memcpy(&pRam->LoadBuffer[pRam->Processed], Data, *pInSize);
    return E_OK;
}
static Std_ReturnType InstallData_LoadingStream(tUPDiGenDecoder* This, tUPDiInstallSession* pSession, uint8_t* Data, uint32_t* pInSize, uint32_t* pOutSize)
{
    tUPDiGenDecoderRam* pRam = This->pRam;
    Std_ReturnType Status = E_OK;
    pRam->ChunkSize = min(min(*pInSize, pRam->ToProcess), sizeof(This->pRam->LoadBuffer));
    (*pOutSize) = (*pInSize) = pRam->ChunkSize;
    memcpy(&pRam->LoadBuffer[0], Data, *pInSize);

    if ( (*pInSize) < pRam->ToProcess)
    {
        Status = This->Vtbl->DecoderProcess(This, pSession);
        if( Status == E_PENDING )
        {
            *pInSize = 0;
        }
    }
    return Status;
}
static Std_ReturnType InstallData_LoadingFilteringStream(tUPDiGenDecoder* This, tUPDiInstallSession* pSession, uint8_t* Data, uint32_t* pInSize, uint32_t* pOutSize)
{
    tUPDiGenDecoderRam* pRam = This->pRam;
    Std_ReturnType Status = E_OK;

    if ( This->Vtbl->Transform )
    {
        if (pRam->pTransformBuffer != NULL)
        {
			Status = This->Vtbl->DecoderProcess(This, pSession);
            if (Status == E_OK)
            {
                pRam->pTransformBuffer = NULL;
            }
            *pInSize = 0;
        }
        else 
        {
			uint8_t* OutBuf =  &pRam->LoadBuffer[0];
			*pOutSize = min(pRam->ToProcess, sizeof(pRam->LoadBuffer));
			Status = This->Vtbl->Transform(This, Data, pInSize, &OutBuf, pOutSize);
            pRam->ToProcess -= *pOutSize;
            pRam->Processed += *pOutSize;

			pRam->ChunkSize = *pOutSize;

			if ( (pRam->ToProcess != 0 ) && (pRam->ChunkSize) )
			{
				Status = This->Vtbl->DecoderProcess(This, pSession);
				if (Status == E_OK)
				{
					pRam->pTransformBuffer = NULL; // pTransformBuffer have been processed, let's clear it
				}
				else if (Status == E_PENDING)
				{
					// pTransformBuffer have not been processed, but we will try again on next call
					pRam->pTransformBuffer = &pRam->LoadBuffer[0];
				}
			}
        }
    }
    return Status;
}
static Std_ReturnType InstallData_InstallingChild(tUPDiGenDecoder* This, tUPDiInstallSession* pSession, uint8_t* Data, uint32_t* pInSize, uint32_t* pOutSize)
{
    Std_ReturnType Status = E_NOT_OK;
    tUPDiGenDecoderRam* pRam = This->pRam;

    if (pRam->pChild)
    {
        *pInSize = min(*pInSize, pRam->ToProcess);
        Status = UPDAbstractInstaller_InstallData(pRam->pChild, pSession, Data, *pInSize);
        *pOutSize = *pInSize;
    }
    return Status;
}

static Std_ReturnType InstallData_TransformingToChild(tUPDiGenDecoder* This, tUPDiInstallSession* pSession, uint8_t* Data, uint32_t* pInSize, uint32_t* pOutSize)
{
    Std_ReturnType Status = E_NOT_OK;
    tUPDiGenDecoderRam* pRam = This->pRam;

    if ( (pRam->pChild) && (This->Vtbl->Transform) )
    {
        if (pRam->pTransformBuffer != NULL)
        {
        	// the last call to InstallData() returned E_PENDING, transformation buffer was not processed
            Status = UPDAbstractInstaller_InstallData(pRam->pChild, pSession, pRam->pTransformBuffer, *pOutSize);
            if (Status == E_OK)
            {
                pRam->ToProcess -= *pOutSize;
                pRam->Processed += *pOutSize;
                pRam->pTransformBuffer = NULL;
            }
            *pInSize = 0; // No new input byte processed
            }
            else
            {
    			//UPDAbstractInstaller_TraceCall(NULL, "Transform", "" );
                Status = This->Vtbl->Transform(This, Data, pInSize, &pRam->pTransformBuffer, pOutSize);
            	//UPDAbstractInstaller_TraceReturn( Status );
            if ((pRam->pTransformBuffer != NULL) && (Status==E_OK) )
                {
                	// Lzma decoder dont know the exact output size
                	*pOutSize = min(*pOutSize, pRam->ToProcess);

                    Status = UPDAbstractInstaller_InstallData(pRam->pChild, pSession, pRam->pTransformBuffer, *pOutSize);
                    if (Status == E_OK)
                    {
                    pRam->pTransformBuffer = NULL; // pTransformBuffer have been processed, let's clear it
                        pRam->ToProcess -= *pOutSize;
                        pRam->Processed += *pOutSize;
                }
            }
        }
    }
    return Status;
}


static Std_ReturnType InitChild(tUPDiGenDecoder* This, tUPDiInstallSession* pSession, tUPDiGenDecoderState NextState)
{
    Std_ReturnType Status = E_NOT_OK;
    tUPDiGenDecoderRam* pRam = This->pRam;

    tUPDdPackageName ChildPackageName;
#if 1
    memcpy(ChildPackageName, pRam->ChildPackageName, sizeof(tUPDdPackageName));
    char* pDot = strrchr(ChildPackageName, '.');
    pRam->pChild = NULL;
    if( pDot != NULL )
    {
    	char* pExtention = pDot + 1;
    	*pDot = 0;
        pRam->pChild = UPDi_AcquireInstaller(pExtention, sizeof(tUPDdPackageName) + ChildPackageName - pExtention);
    }
#else
    pRam->pChild = UPDAbstractInstaller_FindInstaller(pRam->ChildPackageName, &ChildPackageName);

#endif
    if (pRam->pChild == NULL)
    {
        pRam->State = eGenFailed;
    }
    else if ((Status = UPDAbstractInstaller_InstallStart(pRam->pChild, pSession, &ChildPackageName[0], pRam->ToProcess)) != E_OK)
    {
        UPDd_ERROR("UPDAbstractInstaller_InstallStart() installer failed ");
        pRam->State = eGenFailed;
    }

    if (Status == E_OK)
    {
        pRam->State = NextState;
    }
    else if (Status == E_NOT_OK)
    {
        pRam->State = eGenFailed;
    }          
    return Status;
}
static Std_ReturnType deinitChild(tUPDiGenDecoder* This, tUPDiInstallSession* pSession)
{
    Std_ReturnType Status = E_NOT_OK;
    tUPDiGenDecoderRam* pRam = This->pRam;

    Status = UPDAbstractInstaller_InstallExit(pRam->pChild, pSession);
    if (Status == E_NOT_OK)
    {
        pRam->State = eGenFailed;
    }
    else if (Status == E_OK)
    {
        pRam->pChild = NULL;
        pRam->State = eGenNotifyngChild;
        //UPDAbstractInstaller_TraceState("GenDecoderState", "eGenNotifyngChild" );
    }
    return Status;
}
static Std_ReturnType InstallData(tUPDiGenDecoder* This, tUPDiInstallSession* pSession, uint8_t* Data, uint32_t* pInSize, uint32_t* pOutSize)
{
    Std_ReturnType Status = E_OK;
    tUPDiGenDecoderRam* pRam = This->pRam;

    if (Status == E_OK)
    {
        switch (pRam->State)
        {
        case(eGenLoading):
			//UPDAbstractInstaller_TraceCall(NULL, "InstallData_Loading", "" );
            Status = InstallData_Loading(This, pSession, Data, pInSize, pOutSize);
        	//UPDAbstractInstaller_TraceReturn( Status );
            if (Status == E_OK)
            {
                pRam->ToProcess -= *pOutSize;
                pRam->Processed += *pOutSize;
                if (pRam->ToProcess == 0)
                {
                    pRam->State = eGenNotifyngChild;
                    //UPDAbstractInstaller_TraceState("GenDecoderState", "eGenNotifyngChild" );
                }
            }
            else if (Status == E_PENDING)
            {
                *pInSize=0;
            }

            break;
        case(eGenLoadingStream):
			//UPDAbstractInstaller_TraceCall(NULL, "InstallData_LoadingStream", "" );
            Status = InstallData_LoadingStream(This, pSession, Data, pInSize, pOutSize);
        	//UPDAbstractInstaller_TraceReturn( Status );
            if (Status == E_OK)
            {
                pRam->ToProcess -= *pOutSize;
                pRam->Processed += *pOutSize;
                if (pRam->ToProcess == 0)
                {
                    pRam->State = eGenNotifyngChild;
                    //UPDAbstractInstaller_TraceState("GenDecoderState", "eGenNotifyngChild" );
                }
            }
            break;
        case(eGenLoadingFilteringStream):
            Status = InstallData_LoadingFilteringStream(This, pSession, Data, pInSize, pOutSize);
        	//*pOutSize = *pInSize = 0;
			if (Status == E_OK)
			{
				if (pRam->ToProcess == 0)
				{
					pRam->State = eGenNotifyngChild;
				}
			}
            break;

        case(eGenStartInstallingChild):
            Status = InitChild(This, pSession, eGenInstallingChild);
            *pOutSize = *pInSize = 0;
            break;

        case(eGenInstallingChild):
            Status = InstallData_InstallingChild(This, pSession, Data, pInSize, pOutSize);
            if (Status == E_OK)
            {
                pRam->ToProcess -= *pOutSize;
                pRam->Processed += *pOutSize;
                if (pRam->ToProcess == 0)
                {
                    pRam->State = eGenExitInstallingChild;
                }
            }
            else if (Status == E_PENDING)
            {
                *pInSize=0;
            }
            break;

        case(eGenExitTransformingToChild):
        case(eGenExitInstallingChild):
			//UPDAbstractInstaller_TraceCall(NULL, "InstallData_ExitInstallingChild", "" );
            Status = deinitChild(This, pSession);
			//UPDAbstractInstaller_TraceReturn( Status );
            *pOutSize = *pInSize = 0;
            break;

        case(eGenStartTransformingToChild):
			//UPDAbstractInstaller_TraceCall(NULL, "InstallData_StartTransformingToChild", "" );
            Status = InitChild(This, pSession, eGenTransformingToChild);
			//UPDAbstractInstaller_TraceReturn( Status );
            *pOutSize = *pInSize = 0;
            break;

        case(eGenTransformingToChild):
			//UPDAbstractInstaller_TraceCall(NULL, "InstallData_TransformingToChild", "" );
            Status = InstallData_TransformingToChild(This, pSession, Data, pInSize, pOutSize);
			//UPDAbstractInstaller_TraceReturn( Status );
            if (Status == E_OK)
            {
                if (pRam->ToProcess == 0)
                {
                    pRam->State = eGenExitTransformingToChild;
                }
            }
            break;

        case(eGenNotifyngChild):
            pRam->State = eGenReady;
        	//UPDAbstractInstaller_TraceCall(NULL, "InstallData_NotifyngChildg", "" );
            Status = This->Vtbl->DecoderProcess(This, pSession);
            //UPDAbstractInstaller_TraceReturn( Status );
            *pOutSize = *pInSize = 0;
            if (Status == E_NOT_OK)
            {
                pRam->State = eGenFailed;
            }
            else if (Status == E_PENDING)
            {
                pRam->State = eGenNotifyngChild;
            }

            break;

        case(eGenReady):
            if (*pInSize)
            {
                // We are receiving data, but there no nothing to decode
                Status = E_OK; // TODO : Would should return E_NOT_OK here, but sometime LZMA file are followed by 6 unused BYTES;
            }
            break;

        default:
            // Status is E_NOT_OK
            UPDd_ERROR("UPDi_GenDecoider InstallData, unexpected state");
            Status = E_NOT_OK;
            break;
        }
        //UPDAbstractInstaller_TraceStateInt("GenDecoderToProcess", pRam->ToProcess );
    }
    return Status;
}

//=====================================================================================================================
//  Public functions
//=====================================================================================================================
void  UPDiGenDecoder_Init(tUPDiGenDecoder* This)
{
    if (IsInvalid(This))
    {
    }
    else
    {
        tUPDiGenDecoderRam* pRam = This->pRam;
        pRam->State = eGenIdle;
    }
}

Std_ReturnType UPDiGenDecoder_InstallStart(tUPDiGenDecoder* This, tUPDiInstallSession* pSession, const char* PackageName, uint32_t Size)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This))
    {
    }
    else
    {
        tUPDiGenDecoderRam* pRam = This->pRam;
        memset(pRam,0,sizeof(*pRam));
        pRam->State = eGenReady;
        pRam->ToProcess = 0;
        pRam->Processed = 0;
        pRam->ResumeAt = 0;
        pRam->OutSizeProcessed = 0;
        pRam->pTransformBuffer = NULL;
        strncpy(pRam->PackageName, PackageName, sizeof(pRam->PackageName));
        Status = This->Vtbl->DecoderStart(This, pSession, PackageName, Size );
    }
    return Status;
}
Std_ReturnType UPDiGenDecoder_InstallData(tUPDiGenDecoder* This, tUPDiInstallSession* pSession, uint8_t* Data, uint32_t Size)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This))
    {
    }
    else if (Size < This->pRam->ResumeAt)
    {
        UPDd_ERROR("UPDiGenDecoder_InstallData() invalid size");
    }
    else if(Size == 0)
    {
        Status = E_OK;
    }
    else
    {
        tUPDiGenDecoderState prevState;
        tUPDiGenDecoderRam* pRam = This->pRam;
        Size -= pRam->ResumeAt;
        Data += pRam->ResumeAt;
        do 
        {
            // Process the next pack of data
            uint32_t InSizeProcessed = Size;
            prevState = pRam->State;
            Status = InstallData(This, pSession, Data, &InSizeProcessed, &pRam->OutSizeProcessed);

            if((Status != E_OK) && (Status != E_PENDING))
            {
                pRam->State = eGenFailed;
            }
            else
            {
                // Iterate in the input buffer
                Size -= InSizeProcessed;
                Data += InSizeProcessed;
                //UPDAbstractInstaller_TraceStateInt("GenDecoderRemainingSize", Size );
                pRam->ResumeAt += InSizeProcessed;
            }
        } 
        while ( ((pRam->State != prevState) || Size) && (Status == E_OK));

        if (Status != E_PENDING)
        {
            pRam->ResumeAt = 0;
        }
    }
    return Status;
}
Std_ReturnType UPDiGenDecoder_InstallExit(tUPDiGenDecoder* This, tUPDiInstallSession* pSession)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This))
    {
    }
    else if ((This->pRam->State != eGenReady) && (This->pRam->State != eGenTransformingToChild)&& (This->pRam->State != eGenLoadingFilteringStream) )
    {
         UPDd_ERROR("UPDiGenDecoder_InstallExit() Invalid Generic decoder state");
    }
    else
    {
        tUPDiGenDecoderRam* pRam = This->pRam;
        if (This->pRam->State == eGenTransformingToChild)
        {
            uint32_t SizeIn = 0;
			//UPDAbstractInstaller_TraceCall(NULL, "InstallData_TransformingToChild", "" );
            Status = InstallData_TransformingToChild(This, pSession, NULL, &SizeIn, &pRam->OutSizeProcessed);
			//UPDAbstractInstaller_TraceReturn( Status );
            if (Status == E_OK)
            {
                Status = deinitChild(This, pSession);
            }
        }
        if (This->pRam->State == eGenLoadingFilteringStream)
        {
            uint32_t SizeIn = 0;
			//UPDAbstractInstaller_TraceCall(NULL, "InstallData_LoadingFilteringStream", "" );
            Status = InstallData_LoadingFilteringStream(This, pSession, NULL, &SizeIn, &pRam->OutSizeProcessed);
			//UPDAbstractInstaller_TraceReturn( Status );
        }
        if (This->pRam->State == eGenReady)
        {
            Status = This->Vtbl->DecoderExit(This,  pSession);
            if (Status != E_PENDING)
            {
                This->pRam->State = eGenIdle;
            }
        }

    }
    return Status;
}
Std_ReturnType UPDiGenDecoder_Serialize(tUPDiGenDecoder* This, tUPDStream *pStream)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This))
    {
    }
    else
    {
    }
    return Status;
}
Std_ReturnType UPDiGenDecoder_DeSerialize(tUPDiGenDecoder* This, tUPDStream *pStream)
{
    Std_ReturnType Status = E_NOT_OK;
    if (IsInvalid(This))
    {
    }
    else
    {
    }
    return Status;
}

// Specific class method
void UPDiGenDecoder_Install(tUPDiGenDecoder* This, const char* PackageName, uint32_t ChildrenSize)
{
    if (IsInvalid(This))
    {
    }
    else
    {
        tUPDiGenDecoderRam* pRam = This->pRam;
        pRam->State = eGenStartInstallingChild;
        pRam->ToProcess = ChildrenSize;
        pRam->Processed = 0;
        strncpy(pRam->ChildPackageName, PackageName, sizeof(pRam->ChildPackageName));
    }
}
void UPDiGenDecoder_Load(tUPDiGenDecoder* This, uint32_t Size)
{
    if (IsInvalid(This))
    {
    }
    else if (Size > sizeof(This->pRam->LoadBuffer))
    {
        UPDd_ERROR("UPDiGenDecoder_Load() LoadBuffer is too small");
    }
    else
    {
        tUPDiGenDecoderRam* pRam = This->pRam;
        pRam->State = eGenLoading;
        //UPDAbstractInstaller_TraceState("GenDecoderState", "eGenLoading" );
        pRam->ToProcess = Size;
        //UPDAbstractInstaller_TraceStateInt("GenDecoderToProcess", pRam->ToProcess );
        pRam->Processed = 0;
        pRam->ChunkSize = 0;
    }
}
void UPDiGenDecoder_LoadStream(tUPDiGenDecoder* This, uint32_t Size)
{
    if (IsInvalid(This))
    {
    }
    else
    {
        tUPDiGenDecoderRam* pRam = This->pRam;
        pRam->State = eGenLoadingStream;
        //UPDAbstractInstaller_TraceState("GenDecoderState", "eGenLoadingStream" );
        pRam->ToProcess = Size;
        //UPDAbstractInstaller_TraceStateInt("GenDecoderToProcess", pRam->ToProcess );
        pRam->Processed = 0;
        pRam->ChunkSize = 0;
    }
}
void UPDiGenDecoder_LoadFilterStream(tUPDiGenDecoder* This, uint32_t Size)
{
    if (IsInvalid(This))
    {
    }
    else
    {
        tUPDiGenDecoderRam* pRam = This->pRam;
        pRam->State = eGenLoadingFilteringStream;
        pRam->ToProcess = Size;
        pRam->Processed = 0;
        pRam->ChunkSize = 0;
    }
}
void UPDiGenDecoder_Transform(tUPDiGenDecoder* This, uint32_t ChildrenSize)
{
    if (IsInvalid(This))
    {
    }
    else
    {
        tUPDiGenDecoderRam* pRam = This->pRam;
        pRam->State = eGenStartTransformingToChild;
        //UPDAbstractInstaller_TraceState("GenDecoderState", "eGenStartTransformingToChild" );
        pRam->ToProcess = ChildrenSize;
        pRam->Processed = 0;
        strncpy(pRam->ChildPackageName, pRam->PackageName, sizeof(pRam->ChildPackageName));
    }
}
