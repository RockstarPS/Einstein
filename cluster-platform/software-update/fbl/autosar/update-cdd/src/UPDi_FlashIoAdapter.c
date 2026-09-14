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
#include "UPDi_FlashIoAdapter.h"
#include "UPDd.h"
#include <string.h> // memcpy
#include "UPD_ICry.h"

//=====================================================================================================================
/* CONSTANTS & TYPES */
//=======================================================================================================================
tUPDiIoAdapterVtbl UPDiFlashIoAdapterVtbl =
{
		(tUPDiIoAdapter_Task)UPDiFlashIoAdapter_Task,
		(tUPDiIoAdapter_StartWriting)UPDiFlashIoAdapter_StartWriting,
		(tUPDiIoAdapter_FinishWriting)UPDiFlashIoAdapter_FinishWriting,
		(tUPDiIoAdapter_Write)UPDiLocalIoAdapter_Write,
		(tUPDiIoAdapter_Copy)UPDiLocalIoAdapter_Copy,
		(tUPDiIoAdapter_Compose)UPDiLocalIoAdapter_Compose,
		(tUPDiIoAdapter_Read)UPDiFlashIoAdapter_Read,
		(tUPDiIoAdapter_Erase)UPDiFlashIoAdapter_Erase,
		(tUPDiIoAdapter_StartHashing)UPDiLocalIoAdapter_StartHashing,
		(tUPDiIoAdapter_Hash)UPDiLocalIoAdapter_Hash,
		(tUPDiIoAdapter_FinishHashing)UPDiLocalIoAdapter_FinishHashing
};

//=====================================================================================================================
//  Debug helper functions
//=====================================================================================================================
#if 0 // for debug purpose only, do not activate in production
	#include "UPDi_Session.h" //
	extern tUPDiInstallSession Session;
	extern void TestingStub_FlashDriver_IsBlank(uint32_t DestAddress, uint32_t Length);

	#define CHECK_SESSIONS_ADDRESS(This) checkSessionAddress(This)
	#define CHECK_ERASE_LIMIT(This) checkEraseLimit(This)

	static void checkSessionAddress(tUPDiFlashIoAdapter* This)
	{
		tUPDiFlashIoAdapter_Ram* pRam = This->pRam;
		uint32_t SessionAddress = Session.WritePos + pRam->pDestPartition->Address+pRam->SizeProcessed;
		uint32_t FilledSize = UPDiLocalIoAdapter_FilledSize((tUPDiLocalIoAdapter*)This);
		uint32_t AdapterAddress = pRam->CurentAddress + FilledSize;

		if( pRam->WriteState == UPDi_FLASHIOADAPTER_COMPARING)
		{
			 AdapterAddress = pRam->SectorAddress + FilledSize;

		}
		if( SessionAddress != AdapterAddress)
		{
			UPDd_WARNING("SessionAddress & AdapterAddress gap detected");
		}
	}

	static void checkEraseLimit(tUPDiFlashIoAdapter* This)
	{
		tUPDiFlashIoAdapter_Ram* pRam = This->pRam;
		uint32_t EraseLimit = max((pRam->CurentAddress),(pRam->EraseUntilAddress));
		uint32_t PartEnd = pRam->pDestPartition->Address+pRam->pDestPartition->Size;
		if( (EraseLimit != 0xFFFFFFFF) && (PartEnd-EraseLimit) )
		{
			TestingStub_FlashDriver_IsBlank(EraseLimit,PartEnd-EraseLimit);
		}
	}
#else
	#define CHECK_SESSIONS_ADDRESS(This)
	#define CHECK_ERASE_LIMIT(This)
#endif

//=====================================================================================================================
//  Static Functions
//=====================================================================================================================
inline static boolean IsInvalid(tUPDiFlashIoAdapter* This)
{
    boolean ret = TRUE;
#ifndef UPDd_POINTER_TEST_DISABLED
    if (This != NULL)
    {
        ret = (This->pVtbl == NULL) || (This->pRam == NULL) ;
    }
#else
    ret = FALSE;
#endif
    return ret;
}


/*===========================================================================================================================================
* uint32_t sectorSize getSector( tUPDiFlashIoAdapter* This, uint32_t Address, uint32_t* pSectorAddress )
* Function description : identify the sector that contains <Address>, return the sector Size, and the sector address (thru pSectorAddress)
* Input arguments      : Address
* Return               : sectorSize, *sectorAddress
*============================================================================================================================================*/
inline static uint32_t getSector( tUPDiFlashIoAdapter* This, uint32_t Address, uint32_t* pSectorAddress )
{
	uint8_t iArea;
	for(iArea=0; iArea<This->AreaCount;iArea++ )
	{
		tUPDiFlashArea* pAreas = &(This->pAreas[iArea]);
		if( Address >= pAreas->AreaAddress)
		{
			uint32_t Offset  = Address - pAreas->AreaAddress;
			if( Offset < (pAreas->SectorCount * pAreas->SectorSize) )
			{
				if( pSectorAddress )
				{
					*pSectorAddress = Address - (Offset % pAreas->SectorSize) ;
				}
				return pAreas->SectorSize;
			}
		}
	}
	return 0;
}

/*===========================================================================================================================================
* boolean isPageBlank(tUPDiFlashIoAdapter* This, uint32_t PageOffset)
* Function description : This function checks if a page pending on the buffer at the given offset is blank (i.e., filled with the erase value).
* Input arguments      : PageOffset in buffer
* Return               : true if blank
*============================================================================================================================================*/
inline static boolean isPageBlank(tUPDiFlashIoAdapter* This, uint32_t PageOffset)
{
	boolean isBlank = TRUE;
	tUPDiFlashIoAdapter_Ram* pRam = This->pRam;
	uint32_t i = (pRam->GetPos + PageOffset) % This->BufferSize;
	uint32_t iMax = i + This->PageSize;

	while ( i<iMax )
	{
		if (This->pBuffer[i++]!=This->BlankPattern )
		{
			isBlank = FALSE;
			break;
		}
	}
	return isBlank;
}

/*===========================================================================================================================================
*  void ProcessEraseResult(tUPDiFlashIoAdapter* This,MemIf_JobResultType JobStatus)
* Function description : This function react to the end of an erase job
* Input arguments      : Status of the erase job
* Return               : None
*============================================================================================================================================*/
static void ProcessEraseResult(tUPDiFlashIoAdapter* This,MemIf_JobResultType JobStatus)
{
	tUPDiFlashIoAdapter_Ram* pRam = This->pRam;
	if(JobStatus != MEMIF_JOB_OK)
	{
		pRam->WriteState = UPDi_FLASHIOADAPTER_ERASEERROR;
	}
	else
	{
		pRam->WriteState = UPDi_FLASHIOADAPTER_BUFFERING_PAGE;
	}
}

/*===========================================================================================================================================
* void MoveToNextSector(tUPDiFlashIoAdapter* This)
* Function description : This function is called during a writing session when the write address reach a sector end
* Input arguments      : Status of the erase job
* Return               : None
*============================================================================================================================================*/
static void MoveToNextSector(tUPDiFlashIoAdapter* This)
{
	tUPDiFlashIoAdapter_Ram* pRam = This->pRam;
	uint32_t SectorEndAddress = pRam->SectorAddress+pRam->SectorSize;
	uint32_t PartitionEndAddress = pRam->pDestPartition->Address+pRam->pDestPartition->Size;
	if (pRam->CurentAddress < PartitionEndAddress)
	{
		// we have reached the sector end, let'move to the next sector
		pRam->SectorSize = getSector(This,SectorEndAddress,&(pRam->SectorAddress));

		if( pRam->SectorSize == 0)
		{
			// there is no sector after this one
			UPDd_ERROR("UPDiFlashIoAdapter, The partition is not made of a contiguous sectors." );
			pRam->WriteState = UPDi_FLASHIOADAPTER_WRITEFAILED_UNCONTIGOUS_SECTOR;
		}
		else if( (pRam->CurentAddress+pRam->SectorSize) > PartitionEndAddress )
		{
			// the sector cross the partition end
			pRam->WriteState = UPDi_FLASHIOADAPTER_WRITEFAILED_INVALID_PARTITION_END;
		}
		else
		{
			pRam->WriteState = UPDi_FLASHIOADAPTER_SECTOR_START;
			CHECK_ERASE_LIMIT(This);
		}
	}
	else
	{
		// Partition end address is reached
		pRam->WriteState = UPDi_FLASHIOADAPTER_PARTITION_ENDED;
		pRam->CurentAddress = PartitionEndAddress;
		pRam->SectorAddress = PartitionEndAddress;
		pRam->SectorSize = 0;
		CHECK_SESSIONS_ADDRESS(This);
	}
}


/*===========================================================================================================================================
* void ProcessComparisonResult(tUPDiFlashIoAdapter* This, MemIf_JobResultType JobStatus)
* Function description :  This function react to the end of an compare job
* Input arguments      : Status of the erase job
* Return               : None
*============================================================================================================================================*/
static void ProcessComparisonResult(tUPDiFlashIoAdapter* This, MemIf_JobResultType JobStatus)
{
	tUPDiFlashIoAdapter_Ram* pRam = This->pRam;
	if( JobStatus == MEMIF_JOB_OK  )
	{
		// Comparison is successful, content is the same
		uint32_t SectorEndAddress = pRam->SectorAddress+pRam->SectorSize;
		if (pRam->CurentAddress < SectorEndAddress )
		{
			// the full sector has not been compared yet, let's wait new data and continue the comparison
			pRam->WriteState = UPDi_FLASHIOADAPTER_BUFFERING_SECTOR;
		}
		else
		{
			// the full sector has been compared, it contains the expected content
			// no need to re-flash it
			UPDiLocalIoAdapter_Consume((tUPDiLocalIoAdapter*)This, pRam->SectorSize ); // remove the sector data from the buffer
			MoveToNextSector(This);
		}
	}
	else
	{
		// Comparison failed, content is not the same
		// we need to erase the sector and re-flash it
		pRam->WriteState = UPDi_FLASHIOADAPTER_SECTOR_START;
		pRam->CurentAddress = pRam->SectorAddress;
	}
}

/*===========================================================================================================================================
* void ProcessWriteResult(tUPDiFlashIoAdapter* This, MemIf_JobResultType JobStatus)
* Function description :  This function react to the end of an write job
* Input arguments      : Status of the erase job
* Return               : None
*============================================================================================================================================*/
static void ProcessWriteResult(tUPDiFlashIoAdapter* This,MemIf_JobResultType JobStatus)
{
	tUPDiFlashIoAdapter_Ram* pRam = This->pRam;
	if(JobStatus != MEMIF_JOB_OK)
	{
		pRam->WriteState = UPDi_FLASHIOADAPTER_WRITEERROR;
	}
	else
	{
		UPDiLocalIoAdapter_Consume((tUPDiLocalIoAdapter*)This, pRam->CurentSize); // remove the page data from the buffer
		pRam->CurentAddress += pRam->CurentSize;

		if (pRam->CurentAddress >= (pRam->SectorSize + pRam->SectorAddress) )
		{
			MoveToNextSector(This);
		}
		else
		{
			// we have not reached the sector end, let's continue buffering new pages and writing
			pRam->WriteState = UPDi_FLASHIOADAPTER_BUFFERING_PAGE;
		}
	}
}

/*===========================================================================================================================================
* void FetchSectorData(tUPDiFlashIoAdapter* This)
* Function description : This function is called when the adapter buffers the sector data and compare it with the flash content
* Input arguments      : None
* Return               : None
*============================================================================================================================================*/
static void FetchSectorData(tUPDiFlashIoAdapter* This)
{
	tUPDiFlashIoAdapter_Ram* pRam = This->pRam;
	uint32_t ComparedInSector = pRam->CurentAddress - pRam->SectorAddress;

	uint32_t AvailableDataSize = UPDiLocalIoAdapter_FilledSize((tUPDiLocalIoAdapter*)This);
	if( AvailableDataSize > ComparedInSector )
	{
		uint8_t* pNewData= UPDiLocalIoAdapter_GetFilledData((tUPDiLocalIoAdapter*)This, pRam->CurentAddress-pRam->SectorAddress, &AvailableDataSize);
		uint32_t RemainsInSector = pRam->SectorSize - ComparedInSector;
		uint32_t Size = min( RemainsInSector,AvailableDataSize);
		if( This->FlashDriver->Compare(pRam->CurentAddress, pNewData, Size) == E_OK )
		{
			pRam->CurentAddress += Size;
			pRam->WriteState = UPDi_FLASHIOADAPTER_COMPARING;
		}
		else
		{
			pRam->WriteState = UPDi_FLASHIOADAPTER_WRITEERROR;
		}
	}
}

/*===========================================================================================================================================
* void FetchPageData(tUPDiFlashIoAdapter* This)
* Function description : This function is called when the adapter buffers the page before writing it
* Input arguments      : None
* Return               : None
*============================================================================================================================================*/
static void FetchPageData(tUPDiFlashIoAdapter* This)
{
	tUPDiFlashIoAdapter_Ram* pRam = This->pRam;
	uint32_t RemainsInSector = pRam->SectorSize + pRam->SectorAddress - pRam->CurentAddress;
	uint32_t PendingSize = min( RemainsInSector, UPDiLocalIoAdapter_ConsecutiveFilledSize((tUPDiLocalIoAdapter*)This));
	PendingSize = PendingSize - (PendingSize % This->PageSize); // we can only flash full pages.

	if( This->EnableBlankDetection )
	{
		// Check if the first pages of the buffer are filled with the erase pattern (/Blank pattern)
		// and eliminate them if any ( Blank stands for filled with the erase pattern)
		while( PendingSize )
		{
			if( isPageBlank(This, 0) )
			{
				UPDiLocalIoAdapter_Consume((tUPDiLocalIoAdapter*)This, This->PageSize);
				pRam->CurentSize = This->PageSize;
				pRam->CurentAddress += This->PageSize;
				PendingSize -= This->PageSize;
			}
			else
			{
				break;
			}
		}
		// let's determine the offset of first Blank page (First page is not Blank but next pages may be)
		uint32_t FirstBlankPageOffset=This->PageSize; // we know that first page is not Blank
		while( (FirstBlankPageOffset+This->PageSize) <= PendingSize )
		{
			if( isPageBlank(This, FirstBlankPageOffset) )
			{
				// Let's only flash the non-Blank page
				PendingSize = FirstBlankPageOffset;
				break;
			}
			else
			{
				FirstBlankPageOffset+=This->PageSize;
			}
		}
	}

	if( PendingSize )
	{
		if( This->FlashDriver->Write(pRam->CurentAddress, &This->pBuffer[pRam->GetPos], PendingSize) == E_OK )
		{
			pRam->CurentSize = PendingSize;
			//pRam->CurentAddress += pRam->CurentSize;
			pRam->WriteState = UPDi_FLASHIOADAPTER_WRITING;
		}
		else
		{
			pRam->WriteState = UPDi_FLASHIOADAPTER_WRITEERROR;
		}
	}
	else if( pRam->CurentAddress >= (pRam->SectorSize + pRam->SectorAddress) )
	{
		MoveToNextSector(This);
	}
}

/*===========================================================================================================================================
* void StartSector(tUPDiFlashIoAdapter* This, boolean UnkownSectorContent)
* Function description : This function is called when the adapter buffers the page before writing it
* Input arguments      : None
* Return               : None
*============================================================================================================================================*/
static void StartSector(tUPDiFlashIoAdapter* This, boolean UnkownSectorContent)
{
	tUPDiFlashIoAdapter_Ram* pRam = This->pRam;
	pRam->CurentAddress = pRam->SectorAddress;

	if( pRam->SectorAddress >= pRam->EraseUntilAddress )
	{
		CHECK_ERASE_LIMIT(This);

		// Current sector is before the erase limit.
		// It is already erased, no need to erase again
		pRam->WriteState = UPDi_FLASHIOADAPTER_BUFFERING_PAGE;
		FetchPageData(This);
	}
	else if( (This->EnableSectorBufferring == TRUE) && UnkownSectorContent )
	{
		// Sector buffering is enabled and the comparison was not yet done
		// let's make sure that the buffer is big enough for the sector size.
		if( This->BufferSize > pRam->SectorSize )
		{
			// Let's buffer the data & compare with the sector content
			pRam->WriteState = UPDi_FLASHIOADAPTER_BUFFERING_SECTOR;
			FetchSectorData(This);
		}
		else
		{
			UPDd_WARNING("Sector Buffering is enabled but BufferSize is too small to hold a sector of %d", pRam->SectorSize );
		}
	}

	// If erase is required but sector buffering is not possible, let's erase
	if( pRam->WriteState == UPDi_FLASHIOADAPTER_SECTOR_START)
	{
		if( This->FlashDriver->Erase(pRam->SectorAddress, pRam->SectorSize) == E_OK )
		{
			pRam->WriteState = UPDi_FLASHIOADAPTER_ERASING;

		}
		else
		{
			pRam->WriteState = UPDi_FLASHIOADAPTER_WRITEERROR;
		}
	}
}

/*===========================================================================================================================================
* void ProcessRequest(tUPDiFlashIoAdapter* This)
* Function description : This function executes pending read or earse requests
* Input arguments      : None
* Return               : None
*============================================================================================================================================*/
static void ProcessRequest(tUPDiFlashIoAdapter* This)
{
	tUPDiFlashIoAdapter_Ram* pRam = This->pRam;

	if( pRam->WriteState & UPDi_FLASHIOADAPTER_PROCESSING_MASK)
	{
		// let's wait the end of the write job
	}
	else if( (pRam->RequestState == UPDi_FLASHREQ_READ_PENDING) )
	{
		if( This->FlashDriver->Read(pRam->ReqPartition->Address+pRam->ReqOffset, pRam->ReqData, pRam->ReqSize) == E_OK )
		{
			pRam->RequestState = UPDi_FLASHREQ_READING;
			pRam->ReqStatus = This->FlashDriver->GetJobResult();
		}
	}
	else if( (pRam->RequestState == UPDi_FLASHREQ_ERASE_PENDING) )
	{
		pRam->SectorSize = getSector(This,pRam->ReqPartition->Address,&pRam->SectorAddress);
		if( This->FlashDriver->Erase(pRam->SectorAddress, pRam->SectorSize)==E_OK)
		{
			pRam->RequestState = UPDi_FLASHREQ_ERASING;
		}
	}
	else if( (pRam->RequestState != UPDi_FLASHREQ_NONE) && (pRam->ReqStatus==E_PENDING) )
	{
		pRam->ReqStatus = This->FlashDriver->GetJobResult();
		if( (pRam->RequestState == UPDi_FLASHREQ_ERASING ) && ( pRam->ReqStatus==MEMIF_JOB_OK) )
		{
			uint32_t SectorEndAddress = pRam->SectorAddress+pRam->SectorSize;
			if( SectorEndAddress< (pRam->ReqPartition->Address+pRam->ReqPartition->Size))
			{
				pRam->SectorSize = getSector(This,SectorEndAddress,&pRam->SectorAddress);
				if( This->FlashDriver->Erase(pRam->SectorAddress, pRam->SectorSize)==E_OK)
				{
					pRam->ReqStatus = E_PENDING;
				}
			}
		}
	}
}
//=====================================================================================================================
//  Public functions
//=====================================================================================================================

/*===========================================================================================================================================
* Std_ReturnType UPDiFlashIoAdapter_Init(tUPDiLocalIoAdapter* This)
* Function description : This function initialize the localIoAdpater
* Input arguments      : target , package name
* Return               : E_OK / E_NOT_OK - request accepted/rejected
*============================================================================================================================================*/
void UPDiFlashIoAdapter_Init(tUPDiFlashIoAdapter* This)
{
	if( !IsInvalid(This))
	{
		tUPDiFlashIoAdapter_Ram* pRam = This->pRam;
		memset(pRam,0,sizeof(*pRam) );
	}
}

/*===========================================================================================================================================
* Std_ReturnType UPDiFlashIoAdapter_StartWriting(tUPDiLocalIoAdapter* This, tUPDiPartition* pDestPartition, uint32_t DestOffset)
* Function description : This function initialize the localIoAdpater for writing
* Input arguments      : target , package name
* Return               : E_OK / E_NOT_OK - request accepted/rejected
*============================================================================================================================================*/
Std_ReturnType UPDiFlashIoAdapter_StartWriting(tUPDiFlashIoAdapter* This, tUPDiPartition* pDestPartition, uint32_t DestOffset, uint32_t EraseUntil)
{
	Std_ReturnType Status = E_NOT_OK;
	if( !IsInvalid(This))
	{
		tUPDiFlashIoAdapter_Ram* pRam = This->pRam;

		pRam->SectorSize = getSector(This,pDestPartition->Address+DestOffset,&pRam->SectorAddress);

		if( !pDestPartition )
		{}
		else if( DestOffset >= pDestPartition->Size )
		{
			UPDd_ERROR("UPDiFlashIoAdapter_StartWriting(): attempting to write after partition end." );
		}
		else if( pRam->SectorAddress!=pDestPartition->Address+DestOffset  )
		{
			UPDd_ERROR("UPDiFlashIoAdapter_StartWriting(): DestOffset shall be a sector start." );
		}
		else if( (This->BufferSize % This->PageSize) != 0 )
		{
			UPDd_ERROR("UPDiFlashIoAdapter_StartWriting(): BufferSize shall be multiple of PageSize." );
		}
		else if( This->BufferSize < This->PageSize )
		{
			UPDd_ERROR("UPDiFlashIoAdapter_StartWriting(): BufferSize shall be higher than PageSize." );
		}
		else if( pRam->RequestState != UPDi_FLASHREQ_NONE )
		{
			// An background erase job may be ongoing, it needs to finish first
			Status = E_PENDING;
			if(This->FlashDriver->GetJobResult() != MEMIF_JOB_PENDING)
			{
				pRam->RequestState = UPDi_FLASHREQ_NONE;
			}
		}
		else
		{
			if(pRam->pDestPartition )
			{
				UPDd_WARNING("UPDiLocalIoAdapter, a writing session have started before finalizing the previous writing session." );
			}
			if(pRam->Hash.HashType != eUPDiHash_Invalid )
			{
				UPDd_WARNING("UPDiLocalIoAdapter, a writing session have started before finalizing the previous hashing session." );
			}

			pRam->PutPos=0;
			pRam->GetPos=0;
			pRam->pDestPartition = pDestPartition;
			pRam->SizeProcessed =0;
			pRam->ReadSize=0;
			if(EraseUntil!=UPDi_ERASEALL)
			{
				pRam->EraseUntilAddress = EraseUntil + pDestPartition->Address;
				pRam->CurentAddress = pRam->SectorAddress;
				CHECK_ERASE_LIMIT(This);
			}
			else
			{
				pRam->EraseUntilAddress = UPDi_ERASEALL;
			}

			pRam->Hash.HashType = eUPDiHash_Invalid;
			pRam->Hash.HashSize = 0;
			pRam->Hash.pHash = NULL;

			pRam->WriteState = UPDi_FLASHIOADAPTER_SECTOR_START;
			pRam->CurentAddress = pRam->pDestPartition->Address+DestOffset;
			pRam->SectorSize =0;
			MoveToNextSector(This);
			CHECK_SESSIONS_ADDRESS(This);
			Status = E_OK;
		}
	}

	return Status;
}

/*===========================================================================================================================================
* Std_ReturnType UPDiLocalIoAdapter_FinishWriting (tUPDiLocalIoAdapter* This, boolean ProcessQueue, uint32_t* pResumeAt, uint32_t* pEraseUntil)
* Function description : This function Finish a writing session
* Input arguments      : target , package name
* Return               : E_OK / E_NOT_OK - request accepted/rejected
*                        E_PENDING - Some last operation need to finish
*============================================================================================================================================*/
Std_ReturnType UPDiFlashIoAdapter_FinishWriting (tUPDiFlashIoAdapter* This, boolean ProcessQueue, uint32_t* pResumeAt, uint32_t* pEraseUntil)
{
	Std_ReturnType Status = E_NOT_OK;

	UPDiFlashIoAdapter_Task(This);// give a chance to the task to request a last job before to finish
	// Without this call to Task() we may need to resume with more than one sector back

	if( !IsInvalid(This) )
	{
		tUPDiFlashIoAdapter_Ram* pRam = This->pRam;
		if( pRam->pDestPartition == NULL )
		{
			Status = E_NOT_OK;
		}
		else if( pRam->WriteState & UPDi_FLASHIOADAPTER_WRITEFAILURE_MASK )
		{
			Status = E_NOT_OK;
		}
		else if( (pRam->WriteState & UPDi_FLASHIOADAPTER_PROCESSING_MASK ) ||
				 (ProcessQueue && (UPDiLocalIoAdapter_FilledSize((tUPDiLocalIoAdapter*)This)!=0)) )
		{
			// an IO job is ongoing, it need to finish first
			Status = E_PENDING;
		}
		else
		{
			//TestingStub_FlashDriver_DumpPartition(pRam->pDestPartition);
			if( pResumeAt )
			{
				*pResumeAt = pRam->SectorAddress-pRam->pDestPartition->Address;
			}
			if( pEraseUntil )
			{
				// the client of the adapter may not know the last write position, there are two reasons :
				// 1 - because of the presence of the queue in adapter.
				// 2 - because if the last write operation returned PENDING, the adapter may have processed a part of it
				// It's the reason why we need to provide EraseUntilAddress
				if(pRam->EraseUntilAddress!=UPDi_ERASEALL)
				{
					*pEraseUntil = max( pRam->CurentAddress-pRam->pDestPartition->Address, pRam->EraseUntilAddress-pRam->pDestPartition->Address);
				}
				else
				{
					*pEraseUntil = pRam->EraseUntilAddress-pRam->pDestPartition->Address;
				}
			}

			pRam->pDestPartition = NULL;
			pRam->WriteState = UPDi_FLASHIOADAPTER_IDLE;
			pRam->SectorSize = 0;
			Status = E_OK;
		}
	}
	return Status;
}



/*===========================================================================================================================================
* Std_ReturnType UPDiFlashIoAdapter_Task (tUPDiFlashIoAdapter* This)
* Function description : This function is the main task for  FlashIoAdapter
* Input arguments      : none
* Return               : E_OK / E_NOT_OK - request accepted/rejected
*============================================================================================================================================*/
tUPDWorkload UPDiFlashIoAdapter_Task(tUPDiFlashIoAdapter* This)
{
	tUPDWorkload load = eUPD_eWlLow;
	if( !IsInvalid(This) )
	{
		tUPDiFlashIoAdapter_Ram* pRam = This->pRam;
		boolean UnkownSectorContent = TRUE;
		uint32_t FilledSize;

		// These macro are empty - used for Debug only
		CHECK_ERASE_LIMIT(This);
		CHECK_SESSIONS_ADDRESS(This);

		// ----------------------------------------------------------------------------
		// Let's check first if we need to query and process the status of a pending job
		// ----------------------------------------------------------------------------
		if( pRam->WriteState & UPDi_FLASHIOADAPTER_PROCESSING_MASK )
		{
			// A job is ongoing
			MemIf_JobResultType JobStatus = This->FlashDriver->GetJobResult();
			if(JobStatus == MEMIF_JOB_PENDING)
			{/* We're waiting the end of job*/}
			else if (pRam->WriteState == UPDi_FLASHIOADAPTER_COMPARING)
			{
				ProcessComparisonResult(This,JobStatus);
				UnkownSectorContent = FALSE;
			}
			else if (pRam->WriteState == UPDi_FLASHIOADAPTER_ERASING)
			{
				ProcessEraseResult(This,JobStatus);
			}
			else if( pRam->WriteState == UPDi_FLASHIOADAPTER_WRITING)
			{
				ProcessWriteResult(This,JobStatus);
			}
			else
			{
				UPDd_ERROR("Unknown job result received");
			}
		}

		// ----------------------------------------------------------------------------
		// Let's try to fetch data from the queue and request the next job
		// ----------------------------------------------------------------------------
		FilledSize= UPDiLocalIoAdapter_FilledSize((tUPDiLocalIoAdapter*)This);
		if(pRam->WriteState & UPDi_FLASHIOADAPTER_PROCESSING_MASK )
		{/* We're waiting the end of job*/}
		else if( (pRam->RequestState != UPDi_FLASHREQ_NONE) && (pRam->ReqStatus==E_PENDING) )
		{ /* a read or hashing job is ongoing*/
			ProcessRequest(This);
		}
		else if(FilledSize==0)
		{ /* no need to fetch data, the queue is empty*/}
		else if(pRam->WriteState == UPDi_FLASHIOADAPTER_SECTOR_START)
		{
			StartSector(This,UnkownSectorContent);
		}
		else if(pRam->WriteState == UPDi_FLASHIOADAPTER_BUFFERING_SECTOR)
		{
			FetchSectorData(This);
		}
		else if(pRam->WriteState == UPDi_FLASHIOADAPTER_BUFFERING_PAGE)
		{
			FetchPageData(This);
		}
		else if( pRam->WriteState & UPDi_FLASHIOADAPTER_WRITEFAILURE_MASK)
		{
			// we're in ERROR, let's flush the queue
			UPDiLocalIoAdapter_ConsumeAll((tUPDiLocalIoAdapter*)This);
		}
		else
		{
			// We don't expect to receive more data, we're in IDLE or in PARTITION_END state
			UPDd_WARNING("UPDiFlashIoAdapter: unexpected data received" );
			pRam->WriteState = UPDi_FLASHIOADAPTER_WRITEFAILED_UNEXPECTED_DATA;
		}
		CHECK_ERASE_LIMIT(This);
		// ----------------------------------------------------------------------------
		// Let's compute the business status
		// ----------------------------------------------------------------------------
		if((FilledSize==0) && (pRam->WriteState == UPDi_FLASHIOADAPTER_IDLE) && (pRam->RequestState==UPDi_FLASHREQ_NONE))
		{
			// Load = Idle indicates that there is no need to call the task
			load = eUPD_eWlIdle;
		}
		else if((FilledSize < This->LowBufferThreshold)) //|| (FilledSize < This->PageSize) )
		{
			// Load = Low indicates that new data will be required soon, it's time to start a new transfer batch
			load = eUPD_eWlLow;
		}
		else if(FilledSize > (This->BufferSize-This->PageSize) )
		{
			// Load = Full indicates that there is no need to request a new job
			load = eUPD_eWlFull;
		}
		else
		{
			// Load = High indicates that it's better to wait before a new transfer batch
			load = eUPD_eWlHigh;
		}
	}
	return load;
}


/*===========================================================================================================================================
Std_ReturnType UPDiFlashIoAdapter_Read(tUPDiFlashIoAdapter* This, tUPDiPartition* Partition, uint32_t Offset, uint32_t Size, uint8_t* Data)
* Function description : This function is the main task for  FlashIoAdapter
* Input arguments      : none
* Return               : E_OK / E_NOT_OK - request accepted/rejected
*============================================================================================================================================*/
Std_ReturnType UPDiFlashIoAdapter_Read(tUPDiFlashIoAdapter* This, tUPDiPartition* Partition, uint32_t Offset, uint32_t Size, uint8_t* Data)
{
	Std_ReturnType Status = E_NOT_OK;
	if( !IsInvalid(This)  )
	{
		tUPDiFlashIoAdapter_Ram* pRam = This->pRam;
		//MemIf_JobResultType JobStatus = MEMIF_JOB_FAILED;
		
		if( This->FlashDriver->Read == NULL)
		{
			// if FlashDriver.Read is NULL, the flash is directly accessible from the CPU address space
#if( UINTPTR_MAX == 0xffffffff )
			void* pSrc = Partition->Address+Offset;
			memcpy( Data, pSrc, Size);
			pRam->ReqStatus = MEMIF_JOB_OK;
#else
			UPDd_ERROR("UPDiFlashIoAdapter_Read(), cannot cannot read flash by pointer if the address space is not 32Bits" );
#endif
		}
		else 
		{
			if( pRam->RequestState == UPDi_FLASHREQ_NONE)
			{
				pRam->ReqOffset = Offset;
				pRam->ReqSize = Size;
				pRam->ReqData = Data;
				pRam->ReqPartition = Partition;
				pRam->RequestState = UPDi_FLASHREQ_READ_PENDING;
				pRam->ReqStatus = MEMIF_JOB_PENDING;
			}
			ProcessRequest(This);		
		}

		if( pRam->ReqStatus == MEMIF_JOB_PENDING )
		{
			Status = E_PENDING;
		}
		else if( pRam->ReqStatus == MEMIF_JOB_OK )
		{
			Status = E_OK;
			pRam->RequestState = UPDi_FLASHREQ_NONE;
			pRam->ReqPartition = NULL;
		}
		else
		{
			pRam->ReqStatus = E_NOT_OK;
			pRam->RequestState = UPDi_FLASHREQ_NONE;
			pRam->ReqPartition = NULL;
		}
	}
	return Status;
}

/*===========================================================================================================================================
Std_ReturnType UPDiFlashIoAdapter_Erase(tUPDiFlashIoAdapter* This, tUPDiPartition* Partition)
* Function description : Erase a full partition
* Input arguments      : none
* Return               : E_OK / E_NOT_OK - request accepted/rejected
*============================================================================================================================================*/
Std_ReturnType UPDiFlashIoAdapter_Erase(tUPDiFlashIoAdapter* This, tUPDiPartition* Partition)
{
	Std_ReturnType Status = E_NOT_OK;
	if( !IsInvalid(This)  )
	{
		tUPDiFlashIoAdapter_Ram* pRam = This->pRam;
		if( pRam->RequestState == UPDi_FLASHREQ_NONE)
		{
			pRam->ReqOffset = 0;
			pRam->ReqSize = 0;
			pRam->ReqData = 0;
			pRam->ReqPartition = Partition;
			pRam->RequestState = UPDi_FLASHREQ_ERASE_PENDING;
			pRam->ReqStatus = MEMIF_JOB_PENDING;
		}
		ProcessRequest(This);		

		if( pRam->ReqStatus == MEMIF_JOB_PENDING )
		{
			Status = E_PENDING;
		}
		else if( pRam->ReqStatus == MEMIF_JOB_OK )
		{
			Status = E_OK;
			pRam->RequestState = UPDi_FLASHREQ_NONE;
			pRam->ReqPartition = NULL;
		}
		else
		{
			pRam->ReqStatus = E_NOT_OK;
			pRam->RequestState = UPDi_FLASHREQ_NONE;
			pRam->ReqPartition = NULL;
		}
	}
	return Status;
}

