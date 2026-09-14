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
#include "UPDi_LocalIoAdapter.h"
#include "UPDd.h"
#include <string.h> // memcpy
#include "UPD_ICry.h"

//=====================================================================================================================
/* CONSTANTS & TYPES */
//=======================================================================================================================
/*Static Variables*/

//=====================================================================================================================
//  Static Functions
//=====================================================================================================================
inline static boolean IsInvalid(tUPDiLocalIoAdapter* This)
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
* uint32 UPDiLocalIoAdapter_FilledSize(tUPDiLocalIoAdapter* This)
* Function description : Computes the size filled / pending within the FIFO Buffer
* Input arguments      : This pointer
* Return               : number of bytes pending in the FIFO
*============================================================================================================================================*/
uint32_t UPDiLocalIoAdapter_FilledSize(tUPDiLocalIoAdapter* This)
{
	tUPDiLocalIoAdapter_Ram* pRam = This->pRam;
	uint32_t  FilledSize = ( This->BufferSize + pRam->PutPos - pRam->GetPos) % This->BufferSize;
	return FilledSize;
}

/*===========================================================================================================================================
* uint32_t UPDiLocalIoAdapter_FreeSize(tUPDiLocalIoAdapter* This)
* Function description : Computes the free buffer size
* Input arguments      : This pointer
* Return               : number of bytes free in the FIFO
*============================================================================================================================================*/
uint32_t UPDiLocalIoAdapter_FreeSize(tUPDiLocalIoAdapter* This)
{
	uint32_t  FreeSize =  This->BufferSize - UPDiLocalIoAdapter_FilledSize(This) - 1;
	// the last byte cannot be used otherwize buffer full or empty would lead to getPos == putPos
	return FreeSize;
}


/*===========================================================================================================================================
* uint32_t UPDiLocalIoAdapter_ConsecutiveFreeSize(tUPDiLocalIoAdapter* This)
* Function description : Computes the size the next free consecutive set of byte.
*                        As we use a rolling buffer, the free size may be available in 2 parts
* Input arguments      : This pointer
* Return               : number of consecutive bytes free in the FIFO
*============================================================================================================================================*/
uint32_t UPDiLocalIoAdapter_ConsecutiveFreeSize(tUPDiLocalIoAdapter* This)
{
	tUPDiLocalIoAdapter_Ram* pRam = This->pRam;
	uint32_t Size;
	if(pRam->GetPos > pRam->PutPos )
	{
		Size = pRam->GetPos - pRam->PutPos - 1;
	}
	else if(pRam->GetPos != 0 )
	{
		Size = This->BufferSize - pRam->PutPos;
	}
	else
	{
		Size = This->BufferSize - pRam->PutPos - 1;
	}
	return  Size ;
}

/*===========================================================================================================================================
* uint32 UPDiLocalIoAdapter_ConsecutiveFilledSize(tUPDiLocalIoAdapter* This)
* Function description : Computes the size the next filled consecutive set of byte.
*                        As we use a rolling buffer, the free size may be available in 2 parts
* Input arguments      : This pointer
* Return               : number of consecutive bytes filled in the FIFO
*============================================================================================================================================*/
uint32_t UPDiLocalIoAdapter_ConsecutiveFilledSize(tUPDiLocalIoAdapter* This)
{
	tUPDiLocalIoAdapter_Ram* pRam = This->pRam;
	uint32_t Limit;
	if(pRam->PutPos > pRam->GetPos )
	{
		Limit = pRam->PutPos;
	}
	else
	{
		Limit = This->BufferSize;
	}
	return  Limit - pRam->GetPos;
}

/*===========================================================================================================================================
* uint32_t UPDiLocalIoAdapter_GetFilledData(tUPDiLocalIoAdapter* This)
* Function description : Similar as UPDiLocalIoAdapter_ConsecutiveFilledSize() but returns the size and pointer
* Input arguments      : Offset in the FIFO
* Return               : number of consecutive bytes filled in the FIFO from the offset / Pointer to the buffer Offset
*============================================================================================================================================*/
uint8_t* UPDiLocalIoAdapter_GetFilledData(tUPDiLocalIoAdapter* This, uint32_t Offset, uint32_t* Size)
{
	tUPDiLocalIoAdapter_Ram* pRam = This->pRam;
	uint32_t GetPos = (pRam->GetPos + Offset) % This->BufferSize;
	uint32_t Limit;
	if(pRam->PutPos > GetPos )
	{
		Limit = pRam->PutPos;
	}
	else
	{
		Limit = This->BufferSize;
	}
	*Size =  Limit - pRam->GetPos;
	return &This->pBuffer[GetPos];
}


/*===========================================================================================================================================
* void UPDiLocalIoAdapter_Consume(tUPDiLocalIoAdapter* This, uint32 Size)
* Function description : remove the number of bytes specified from the FIFO
* Input arguments      : number of bytes to remove
* Return               : none
*============================================================================================================================================*/
void UPDiLocalIoAdapter_Consume(tUPDiLocalIoAdapter* This, uint32_t Size)
{
	tUPDiLocalIoAdapter_Ram* pRam = This->pRam;
	uint32_t filledSize = ( This->BufferSize + pRam->PutPos - pRam->GetPos) % This->BufferSize;
	if( Size <= filledSize )
	{
		pRam->GetPos = (pRam->GetPos + Size) % This->BufferSize;
	}
	else
	{
		// Consume what is available
		pRam->GetPos = (pRam->GetPos + filledSize) % This->BufferSize;
		UPDd_ERROR("UPDiLocalIoAdapter_Consume(), cannot consume more than available." );
	}
}

/*===========================================================================================================================================
* void UPDiLocalIoAdapter_ConsumeAll(tUPDiLocalIoAdapter* This)
* Function description : remove all bytes from the FIFO
* Input arguments      : none
* Return               : none
*============================================================================================================================================*/
void UPDiLocalIoAdapter_ConsumeAll(tUPDiLocalIoAdapter* This)
{
	tUPDiLocalIoAdapter_Ram* pRam = This->pRam;
	pRam->GetPos = pRam->PutPos;
}

/*===========================================================================================================================================
* void MemCompose( uint8* pDest, uint8* pSrc, uint32 Size, tUPDiIoAdapter_CompositionType type )
* Function description : implement the composition algorithms for delta update
* Input arguments      : pointer and size to source and destination buffer, composition type
* Return               : none
*============================================================================================================================================*/
inline static void MemCompose( uint8_t* pDest, uint8_t* pSrc, uint32_t Size, tUPDiIoAdapter_CompositionType type )
{
	if( type == eUPDi_COMPOSITION_BYTEWIZE_ADD)
	{
		while(Size--)
		{
			*pDest += *pSrc;
			pDest++;
			pSrc++;
		}
	}
	else
	{

	}
}

//=====================================================================================================================
//  Public functions
//=====================================================================================================================

/*===========================================================================================================================================
* Std_ReturnType UPDiLocalIoAdapter_Write(tUPDiLocalIoAdapter* This, uint32 Size, uint8* Data)
* Function description : This function request writing data at the curent offset and shift the offset by the size
* Input arguments      : target , package name
* Return               : E_OK / E_NOT_OK - request accepted/rejected
*                        E_PENDING - there is not enought free space in the Buffer, the request need to be re-iterated later
*============================================================================================================================================*/
Std_ReturnType UPDiLocalIoAdapter_Write(tUPDiLocalIoAdapter* This, uint32_t Size, uint8_t* Data)
{
	Std_ReturnType Status = E_NOT_OK;
	if( !IsInvalid(This))
	{
		tUPDiLocalIoAdapter_Ram* pRam = This->pRam;
		if( (pRam->pDestPartition != NULL) && (Data!= NULL) )
		{
			uint32_t SizeProcessed =  min( Size-pRam->SizeProcessed, UPDiLocalIoAdapter_FreeSize(This));
			if( SizeProcessed )
			{
				uint32_t Size1 = min( UPDiLocalIoAdapter_ConsecutiveFreeSize(This), SizeProcessed );
				uint32_t Size2 = SizeProcessed-Size1;

				memcpy( &This->pBuffer[pRam->PutPos], &Data[pRam->SizeProcessed], Size1);

				if(Size2 )
				{
					memcpy( &This->pBuffer[0], &Data[pRam->SizeProcessed+Size1], Size2);
				}

				pRam->PutPos = (pRam->PutPos + SizeProcessed) % This->BufferSize;
				pRam->SizeProcessed += SizeProcessed;

			}
			if( pRam->SizeProcessed == Size)
			{
				pRam->SizeProcessed = 0;
				Status = E_OK;
			}
			else
			{
				Status = E_PENDING;
			}
		}
		else
		{
			UPDd_ERROR("UPDiLocalIoAdapter_Write() : no write session initiated");
		}
	}
	return Status;
}
/*===========================================================================================================================================
* Std_ReturnType UPDiLocalIoAdapter_Copy (tUPDiLocalIoAdapter* This, tUPDiPartition* pSrcPartition, uint32 SrcOffset, uint32 Size)
* Function description : This function request to copy the data at the curent offset and shift the offset by the size
* Input arguments      : pSrcPartition/SrcOffset = Partion and offset to read from
* 					   : Size = Size to read & write
* Return               : E_OK / E_NOT_OK - request accepted/rejected
*                        E_PENDING - there is not enought free space in the Buffer, the request need to be re-iterated later
*============================================================================================================================================*/
Std_ReturnType UPDiLocalIoAdapter_Copy (tUPDiLocalIoAdapter* This, tUPDiPartition* pSrcPartition, uint32_t SrcOffset, uint32_t Size)
{
	Std_ReturnType Status = E_NOT_OK;
	if( !IsInvalid(This))
	{
		tUPDiLocalIoAdapter_Ram* pRam = This->pRam;
		if( (pRam->pDestPartition != NULL) && (pSrcPartition!=NULL))
		{
			// Determine what is the remaining size
			uint32_t RemainsToProcess = Size - pRam->SizeProcessed;
			Status = E_OK;		
			while( (RemainsToProcess!=0) && (Status==E_OK) )
			{
				// if pRam->ReadSize is not 0, the last read call returned E_PENDING.
				// in that case, we need to re-iterate the read request with the same input.
				// we cannot re-calculate the size because the free space may have changed.
				if( pRam->ReadSize == 0 )
				{
					// determine what size we can process in one go
					pRam->ReadSize = min( RemainsToProcess, UPDiLocalIoAdapter_ConsecutiveFreeSize(This) );
				}
				if( pRam->ReadSize!=0 )
				{
					// There is free space in the write buffer,  let's read 
					Status = UPDiIoAdapter_Read(pSrcPartition->IoAdapter, pSrcPartition, SrcOffset+pRam->SizeProcessed, pRam->ReadSize, &This->pBuffer[pRam->PutPos] );
					if( Status==E_OK )
					{
						pRam->PutPos = (pRam->PutPos + pRam->ReadSize) % This->BufferSize;
						pRam->SizeProcessed += pRam->ReadSize;
						RemainsToProcess    -= pRam->ReadSize;
						pRam->ReadSize = 0;
					}
				}
				else
				{
					Status = E_PENDING;// write buffer if full
				}
			}
		}
		if( Status!=E_PENDING)
		{
			pRam->SizeProcessed = 0;
			pRam->ReadSize = 0;
		}
	}
	return Status;
}

/*===========================================================================================================================================
* Std_ReturnType UPDiLocalIoAdapter_Compose (tUPDiLocalIoAdapter* This, tUPDiPartition* pSrcPartition, uint32 SrcOffset, uint32 Size, uint8* Data)
* Function description : This function request to copy the data at the curent offset and shift the offset by the size
* Input arguments      : pSrcPartition/SrcOffset = Partion and offset to read from
* 					   : Size = Size to read & write
* Return               : E_OK / E_NOT_OK - request accepted/rejected
*                        E_PENDING - there is not enought free space in the Buffer, the request need to be re-iterated later
*============================================================================================================================================*/
Std_ReturnType UPDiLocalIoAdapter_Compose(tUPDiLocalIoAdapter* This, tUPDiPartition* pSrcPartition, uint32_t SrcOffset, uint32_t Size, uint8_t* Data, tUPDiIoAdapter_CompositionType type)
{
	Std_ReturnType Status = E_NOT_OK;
	if( !IsInvalid(This))
	{
		tUPDiLocalIoAdapter_Ram* pRam = This->pRam;
		if( (pRam->pDestPartition != NULL) && (pSrcPartition!=NULL) && (Data!=NULL) )
		{
			// Determine what is the remaining size
			uint32_t RemainsToProcess = Size - pRam->SizeProcessed;
			Status = E_OK;		
			while( (RemainsToProcess!=0) && (Status==E_OK) )
			{
				// if pRam->ReadSize is not 0, the last read call returned E_PENDING.
				// in that case, we need to re-iterate the read request with the same input.
				// we cannot re-calculate the size because the free space may have changed.
				if( pRam->ReadSize == 0 )
				{
					// determine what size we can process in one go
					pRam->ReadSize = min( RemainsToProcess, UPDiLocalIoAdapter_ConsecutiveFreeSize(This) );
				}
				if( pRam->ReadSize!=0 )
				{
					// There is free space in the write buffer,  let's read 
					Status = UPDiIoAdapter_Read(pSrcPartition->IoAdapter, pSrcPartition, SrcOffset+pRam->SizeProcessed, pRam->ReadSize, &This->pBuffer[pRam->PutPos] );
					if( Status==E_OK )
					{
						MemCompose( &This->pBuffer[pRam->PutPos], &Data[pRam->SizeProcessed], pRam->ReadSize, type );
						pRam->PutPos = (pRam->PutPos + pRam->ReadSize) % This->BufferSize;
						pRam->SizeProcessed += pRam->ReadSize;
						RemainsToProcess    -= pRam->ReadSize;
						pRam->ReadSize = 0;

					}
				}
				else
				{
					Status = E_PENDING;// write buffer if full
				}
			}
		}
		if( Status!=E_PENDING)
		{
			pRam->SizeProcessed = 0;
			pRam->ReadSize = 0;
		}

	}
	return Status;
}

/*===========================================================================================================================================
* Std_ReturnType UPDiLocalIoAdapter_StartHashing(tUPDiLocalIoAdapter* This, tUPDHashingType HashType, uint8 HashSize)
* Function description : This function initialize the localIoAdpater for hashing
* Input arguments      : HashType, HashSize
* Return               : E_OK / E_NOT_OK - request accepted/rejected
*============================================================================================================================================*/
Std_ReturnType UPDiLocalIoAdapter_StartHashing(tUPDiLocalIoAdapter* This, tUPDHashingType HashType, uint8_t HashSize)
{
	Std_ReturnType Status = E_NOT_OK;
	if( !IsInvalid(This) && (This->BufferSize > HashSize))
	{
		if(This->BufferSize > (HashSize+sizeof(uint32_t))  )
		{
			tUPDiLocalIoAdapter_Ram* pRam = This->pRam;
			if(pRam->pDestPartition )
			{
				UPDd_WARNING("UPDiLocalIoAdapter, an hashing session have started before finalizing the previous writing session." );
			}
			if(pRam->Hash.HashType != eUPDiHash_Invalid )
			{
				UPDd_WARNING("UPDiLocalIoAdapter, an hashing session have started before finalizing the previous hashing session." );
			}

			memset(pRam,0,sizeof(*pRam) );
			pRam->Hash.HashType = HashType;
			pRam->Hash.HashSize = HashSize;
			pRam->Hash.pHash = This->pBuffer;

			Status = UPD_ICry_Hash_Init(&pRam->Hash);
		}
		else
		{
			UPDd_ERROR("UPDiLocalIoAdapter_StartHashing(): Hash size is too big, it cannot fit in the IOAdapter buffer." );
		}
	}
	return Status;
}

/*===========================================================================================================================================
* Std_ReturnType UPDiLocalIoAdapter_Compose (tUPDiLocalIoAdapter* This, tUPDiPartition* pSrcPartition, uint32 SrcOffset, uint32 Size, uint8* Data)
* Function description : This function request to copy the data at the curent offset and shift the offset by the size
* Input arguments      : pSrcPartition/SrcOffset = Partion and offset to read from
* 					   : Size = Size to read & write
* Return               : E_OK / E_NOT_OK - request accepted/rejected
*                        E_PENDING - there is not enought free space in the Buffer, the request need to be re-iterated later
*============================================================================================================================================*/
Std_ReturnType UPDiLocalIoAdapter_Hash(tUPDiLocalIoAdapter* This, tUPDiPartition* pPartition, uint32_t Offset, uint32_t Size)
{
	Std_ReturnType Status = E_NOT_OK;
	if( !IsInvalid(This))
	{
		tUPDiLocalIoAdapter_Ram* pRam = This->pRam;
		if( (pPartition!=NULL) && (pRam->Hash.HashType != eUPDiHash_Invalid) )
		{
			// Determine what is the remainig size 
			uint32_t RemainsToProcess = Size - pRam->SizeProcessed;
			uint32_t ProcessedInThisCall = 0;
			
			Status = E_OK;		
			while( (RemainsToProcess!=0) && (Status==E_OK) )
			{
				// determine what size we can process in one go
				uint32_t SizeProcessed = min( RemainsToProcess, This->BufferSize - pRam->Hash.HashSize );
			    Status = UPDiIoAdapter_Read(pPartition->IoAdapter, pPartition, Offset+pRam->SizeProcessed, SizeProcessed, &This->pBuffer[pRam->Hash.HashSize] );
				if( Status==E_OK )
				{
					UPD_ICry_Hash_Update(&pRam->Hash, &This->pBuffer[pRam->Hash.HashSize], SizeProcessed);
					
					pRam->SizeProcessed += SizeProcessed;
					RemainsToProcess    -= SizeProcessed;
					ProcessedInThisCall += SizeProcessed;
					if(ProcessedInThisCall > UPDd_MAX_HASHABLE_SIZE_PER_CALL )
					{
						Status =E_PENDING;
					}
				}
			}
		}

		if( Status!=E_PENDING)
		{
			pRam->SizeProcessed = 0;
		}
	}
	return Status;
}

/*===========================================================================================================================================
* Std_ReturnType UPDiLocalIoAdapter_FinishHashing(tUPDiLocalIoAdapter* This, tUPDHashInfo** ppHash)
* Function description : This function finalize the hash computation
* Input arguments      : ppHash use to return a pointer to the hash
* Return               : E_OK / E_NOT_OK - request accepted/rejected
*============================================================================================================================================*/
Std_ReturnType UPDiLocalIoAdapter_FinishHashing(tUPDiLocalIoAdapter* This, tUPDHashInfo* pHash)
{
	Std_ReturnType Status = E_NOT_OK;
	if( !IsInvalid(This) && (pHash!=NULL) )
	{
		tUPDiLocalIoAdapter_Ram* pRam = This->pRam;
		if( pRam->Hash.HashType != eUPDiHash_Invalid  )
		{
			Status = UPD_ICry_Hash_Final(&pRam->Hash);
			if( Status == E_OK )
			{
				pHash->HashSize = pRam->Hash.HashSize;
				pHash->HashType = pRam->Hash.HashType;
				pHash->pHash = pRam->Hash.pHash;
				pRam->Hash.HashType = eUPDiHash_Invalid;

			}
		}
	}
	return Status;
}

