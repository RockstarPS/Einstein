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
# ifndef UPD_LocalAdapter_H
# define UPD_LocalAdapter_H

#include "UPDi_IoAdapter.h"

//=====================================================================================================================
/* CONSTANTS & TYPES */
//=====================================================================================================================
typedef struct sUPDiLocalIoAdapter_Ram
{
	uint32_t PutPos;
	uint32_t GetPos;
	tUPDiPartition* pDestPartition;
	uint32_t SizeProcessed;
	uint32_t ReadSize;
	tUPDHashInfo Hash;
} tUPDiLocalIoAdapter_Ram;

typedef const struct sUPDiLocalIoAdapter
{
	tUPDiIoAdapterVtbl* pVtbl;
	tUPDiLocalIoAdapter_Ram* pRam;
	uint8_t* pBuffer;
	uint32_t BufferSize;
} tUPDiLocalIoAdapter;

//=====================================================================================================================
//  User Public functions
//=====================================================================================================================
// Writing API
// pure abstract for LocalIoAdapter -- Std_ReturnType UPDiLocalIoAdapter_StartWriting (tUPDiLocalIoAdapter* This, tUPDiPartition* pDestPartition, uint32_t DestOffset, uint32_t EraseUntil);
// pure abstract for LocalIoAdapter -- Std_ReturnType UPDiLocalIoAdapter_FinishWriting (tUPDiLocalIoAdapter* This, boolean ProcessQueue, uint32_t* pResumeAt, uint32_t* pEraseUntil);

Std_ReturnType UPDiLocalIoAdapter_Write(tUPDiLocalIoAdapter* This, uint32_t Size, uint8_t* Data);
Std_ReturnType UPDiLocalIoAdapter_Copy (tUPDiLocalIoAdapter* This, tUPDiPartition* pSrcPartition, uint32_t SrcOffset, uint32_t Size);
Std_ReturnType UPDiLocalIoAdapter_Compose (tUPDiLocalIoAdapter* This, tUPDiPartition* pSrcPartition, uint32_t SrcOffset, uint32_t Size, uint8_t* Data, tUPDiIoAdapter_CompositionType type);

// Reading API
// Read is pure abstract for LocalIoAdapter -- Std_ReturnType UPDiLocalIoAdapter_Read(tUPDiLocalIoAdapter* This, tUPDiPartition* Partition, uint32_t Offset, uint32_t Size, uint8_t* Data);

// Hashing API
Std_ReturnType UPDiLocalIoAdapter_StartHashing (tUPDiLocalIoAdapter* This, tUPDHashingType Type, uint8_t HashSize);
Std_ReturnType UPDiLocalIoAdapter_Hash(tUPDiLocalIoAdapter* This, tUPDiPartition* pPartition, uint32_t Offset, uint32_t Size);
Std_ReturnType UPDiLocalIoAdapter_FinishHashing(tUPDiLocalIoAdapter* This, tUPDHashInfo* ppHash);

//=====================================================================================================================
//  Buffer management helper functions -  these function are Protected/Reserved to child classes
//=====================================================================================================================
uint32_t UPDiLocalIoAdapter_FilledSize(tUPDiLocalIoAdapter* This);
uint32_t UPDiLocalIoAdapter_FreeSize(tUPDiLocalIoAdapter* This);
uint32_t UPDiLocalIoAdapter_ConsecutiveFreeSize(tUPDiLocalIoAdapter* This);
uint32_t UPDiLocalIoAdapter_ConsecutiveFilledSize(tUPDiLocalIoAdapter* This);
uint8_t* UPDiLocalIoAdapter_GetFilledData(tUPDiLocalIoAdapter* This, uint32_t Offset, uint32_t* Size);
void   UPDiLocalIoAdapter_Consume(tUPDiLocalIoAdapter* This, uint32_t Size);
void   UPDiLocalIoAdapter_ConsumeAll(tUPDiLocalIoAdapter* This);

//=====================================================================================================================
//  VTBL
//=====================================================================================================================

// there is no VTBL, this class is abstract

#endif /*UPD_LocalIoAdapter_H*/
