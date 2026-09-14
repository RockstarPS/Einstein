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
#include "UPDi_IoAdapter.h"
#include <string.h>

//=====================================================================================================================
/* CONSTANTS & TYPES */
//=======================================================================================================================
/*Static Variables*/
//=====================================================================================================================
//  Static Functions
//=====================================================================================================================
static boolean IsInvalid(tUPDiIoAdapter* This)
{
    boolean ret = TRUE;
#ifndef UPDd_POINTER_TEST_DISABLED
    if (This != NULL)
    {
        ret = (This->pVtbl == NULL);
    }
#else
    ret = FALSE;
#endif
    return ret;
}

//=====================================================================================================================
//  Public functions
//=====================================================================================================================
tUPDWorkload UPDiIoAdapter_Task (tUPDiIoAdapter* This)
{
	Std_ReturnType Status = eUPD_eWlIdle;
	if( !IsInvalid(This))
	{
		Status = This->pVtbl->Task(This);
	}
	return Status;
}

Std_ReturnType UPDiIoAdapter_StartWriting(tUPDiIoAdapter* This, tUPDiPartition* pDestPartition, uint32_t DestOffset, uint32_t EraseUntil)
{
	Std_ReturnType Status = E_NOT_OK;
	if( !IsInvalid(This))
	{
		Status = This->pVtbl->StartWriting(This, pDestPartition, DestOffset, EraseUntil);
	}
	return Status;
}
Std_ReturnType UPDiIoAdapter_FinishWriting (tUPDiIoAdapter* This, boolean ProcessQueue, uint32_t* pResumeAt, uint32_t* pEraseUntil)
{
	Std_ReturnType Status = E_NOT_OK;
	if( !IsInvalid(This))
	{
		Status = This->pVtbl->FinishWriting (This, ProcessQueue, pResumeAt,pEraseUntil);
	}
	return Status;
}
Std_ReturnType UPDiIoAdapter_Write(tUPDiIoAdapter* This, uint32_t Size, uint8_t* Data)
{
	Std_ReturnType Status = E_NOT_OK;
	if( !IsInvalid(This))
	{
		Status = This->pVtbl->Write(This, Size, Data);
	}
	return Status;
}
Std_ReturnType UPDiIoAdapter_Copy (tUPDiIoAdapter* This, tUPDiPartition* pSrcPartition, uint32_t SrcOffset, uint32_t Size)
{
	Std_ReturnType Status = E_NOT_OK;
	if( !IsInvalid(This))
	{
		Status = This->pVtbl->Copy (This, pSrcPartition, SrcOffset, Size);
	}
	return Status;
}
Std_ReturnType UPDiIoAdapter_Compose (tUPDiIoAdapter* This, tUPDiPartition* pSrcPartition, uint32_t SrcOffset, uint32_t Size, uint8_t* Data,tUPDiIoAdapter_CompositionType type)
{
	Std_ReturnType Status = E_NOT_OK;
	if( !IsInvalid(This))
	{
		Status = This->pVtbl->Compose (This, pSrcPartition, SrcOffset, Size, Data, type);
	}
	return Status;
}
Std_ReturnType UPDiIoAdapter_Read(tUPDiIoAdapter* This, tUPDiPartition* Partition, uint32_t Offset, uint32_t Size, uint8_t* Data)
{
	Std_ReturnType Status = E_NOT_OK;
	if( !IsInvalid(This))
	{
		Status = This->pVtbl->Read(This, Partition, Offset, Size, Data);
	}
	return Status;
}
Std_ReturnType UPDiIoAdapter_Erase(tUPDiIoAdapter* This, tUPDiPartition* Partition)
{
	Std_ReturnType Status = E_NOT_OK;
	if( !IsInvalid(This))
	{
		Status = This->pVtbl->Erase(This, Partition);
	}
	return Status;
}
Std_ReturnType UPDiIoAdapter_StartHashing (tUPDiIoAdapter* This, tUPDHashingType Type, uint8_t HashSize)
{
	Std_ReturnType Status = E_NOT_OK;
	if( !IsInvalid(This))
	{
		Status = This->pVtbl->StartHashing (This, Type, HashSize);
	}
	return Status;
}
Std_ReturnType UPDiIoAdapter_Hash(tUPDiIoAdapter* This, tUPDiPartition* pPartition, uint32_t Offset, uint32_t Size)
{
	Std_ReturnType Status = E_NOT_OK;
	if( !IsInvalid(This))
	{
		Status = This->pVtbl->Hash(This, pPartition, Offset, Size);
	}
	return Status;
}
Std_ReturnType UPDiIoAdapter_FinishHashing(tUPDiIoAdapter* This, tUPDHashInfo* pHash)
{
	Std_ReturnType Status = E_NOT_OK;
	if( !IsInvalid(This))
	{
		Status = This->pVtbl->FinishHashing(This, pHash);
	}
	return Status;
}

