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
# ifndef UPD_IoAdapter_H
# define UPD_IoAdapter_H

# include "UPDi_Types.h"

//=====================================================================================================================
/* CONSTANTS & TYPES */
//=====================================================================================================================
struct sUPDiIoAdapter;
enum
{
	eUPDi_COMPOSITION_BYTEWIZE_ADD,
};
typedef uint8_t tUPDiIoAdapter_CompositionType;

#define UPDi_ERASEALL ((uint32_t)0xFFFFFFFF)

typedef tUPDWorkload   (*tUPDiIoAdapter_Task) (const struct sUPDiIoAdapter* This);
typedef Std_ReturnType (*tUPDiIoAdapter_StartWriting) (const struct sUPDiIoAdapter* This, tUPDiPartition* pDestPartition, uint32_t DestOffset, uint32_t EraseUntil);
typedef Std_ReturnType (*tUPDiIoAdapter_FinishWriting) (const struct sUPDiIoAdapter* This, boolean ProcessQueue, uint32_t* pResumeAt, uint32_t* pEraseUntil);
typedef Std_ReturnType (*tUPDiIoAdapter_Write)(const struct sUPDiIoAdapter* This, uint32_t Size, uint8_t* Data);
typedef Std_ReturnType (*tUPDiIoAdapter_Copy) (const struct sUPDiIoAdapter* This, tUPDiPartition* pSrcPartition, uint32_t SrcOffset, uint32_t Size);
typedef Std_ReturnType (*tUPDiIoAdapter_Compose) (const struct sUPDiIoAdapter* This, tUPDiPartition* pSrcPartition, uint32_t SrcOffset, uint32_t Size, uint8_t* Data, tUPDiIoAdapter_CompositionType type);
typedef Std_ReturnType (*tUPDiIoAdapter_Read)(const struct sUPDiIoAdapter* This, tUPDiPartition* Partition, uint32_t Offset, uint32_t Size, uint8_t* Data);
typedef Std_ReturnType (*tUPDiIoAdapter_Erase)(const struct sUPDiIoAdapter* This, tUPDiPartition* Partition);
typedef Std_ReturnType (*tUPDiIoAdapter_StartHashing) (const struct sUPDiIoAdapter* This, tUPDHashingType Type, uint8_t HashSize);
typedef Std_ReturnType (*tUPDiIoAdapter_Hash)(const struct sUPDiIoAdapter* This, tUPDiPartition* pPartition, uint32_t Offset, uint32_t Size);
typedef Std_ReturnType (*tUPDiIoAdapter_FinishHashing)(const struct sUPDiIoAdapter* This, tUPDHashInfo* pHash);

typedef const struct sUPDiIoAdapterVtbl
{
	tUPDiIoAdapter_Task  Task;
	tUPDiIoAdapter_StartWriting StartWriting;
	tUPDiIoAdapter_FinishWriting FinishWriting;
	tUPDiIoAdapter_Write Write;
	tUPDiIoAdapter_Copy Copy;
	tUPDiIoAdapter_Compose Compose;
	tUPDiIoAdapter_Read Read;
	tUPDiIoAdapter_Erase Erase;
	tUPDiIoAdapter_StartHashing StartHashing;
	tUPDiIoAdapter_Hash Hash;
	tUPDiIoAdapter_FinishHashing FinishHashing;
} tUPDiIoAdapterVtbl;

typedef const struct sUPDiIoAdapter
{
	tUPDiIoAdapterVtbl* pVtbl;
} tUPDiIoAdapter;

//=====================================================================================================================
//  User Public functions
//=====================================================================================================================
tUPDWorkload   UPDiIoAdapter_Task (tUPDiIoAdapter* Adapter);

// Writing API
Std_ReturnType UPDiIoAdapter_StartWriting (tUPDiIoAdapter* This, tUPDiPartition* pDestPartition, uint32_t DestOffset, uint32_t EraseUntil);
Std_ReturnType UPDiIoAdapter_Write(tUPDiIoAdapter* This, uint32_t Size, uint8_t* Data);
Std_ReturnType UPDiIoAdapter_Copy (tUPDiIoAdapter* This, tUPDiPartition* pSrcPartition, uint32_t SrcOffset, uint32_t Size);
Std_ReturnType UPDiIoAdapter_Compose (tUPDiIoAdapter* This, tUPDiPartition* pSrcPartition, uint32_t SrcOffset, uint32_t Size, uint8_t* Data, tUPDiIoAdapter_CompositionType type);
Std_ReturnType UPDiIoAdapter_FinishWriting (tUPDiIoAdapter* This, boolean ProcessQueue, uint32_t* pResumeAt, uint32_t* pEraseUntil);

// Reading API
Std_ReturnType UPDiIoAdapter_Read(tUPDiIoAdapter* This, tUPDiPartition* Partition, uint32_t Offset, uint32_t Size, uint8_t* Data);
Std_ReturnType UPDiIoAdapter_Erase(tUPDiIoAdapter* This, tUPDiPartition* Partition); // Optional, IoAdapter can erase by its own

// Hashing API
Std_ReturnType UPDiIoAdapter_StartHashing (tUPDiIoAdapter* This, tUPDHashingType Type, uint8_t HashSize);
Std_ReturnType UPDiIoAdapter_Hash(tUPDiIoAdapter* This, tUPDiPartition* pPartition, uint32_t Offset, uint32_t Size);
Std_ReturnType UPDiIoAdapter_FinishHashing(tUPDiIoAdapter* This, tUPDHashInfo* pHash);

#endif /*UPD_IoAdapter_H*/
