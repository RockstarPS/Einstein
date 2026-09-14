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
# ifndef UPD_FlashAdapter_H
# define UPD_FlashAdapter_H

#include "UPDi_LocalIoAdapter.h"
#include "MemIf_Types.h"

//=====================================================================================================================
/* MACRO : Construction helper */
//=====================================================================================================================
#define UPD_DECLARE_FLASH_IOADAPTER(_name_, _Areas, _DriverVtbl, _BufferSize, _LowBufferThreshold, _PageSize,_EnableBlankDetection,_BlankPattern,_EnableSectorBufferring) \
uint8_t  _name_##_Buffer[_BufferSize];\
tUPDiFlashIoAdapter_Ram  _name_##_ram;\
tUPDiFlashIoAdapter   _name_ =\
{\
	.pVtbl = &UPDiFlashIoAdapterVtbl,\
	.pRam = &_name_##_ram,\
	.pBuffer = &_name_##_Buffer[0],\
	.BufferSize = sizeof( _name_##_Buffer),\
	.FlashDriver = &_DriverVtbl,\
	.PageSize = _PageSize,\
	.LowBufferThreshold = _LowBufferThreshold,\
	.pAreas = &_Areas[0],\
	.AreaCount = sizeof( _Areas)/sizeof(tUPDiFlashArea),\
	.BlankPattern = _BlankPattern,\
	.EnableBlankDetection=_EnableBlankDetection,\
	.EnableSectorBufferring=_EnableSectorBufferring,\
}

//=====================================================================================================================
/* CONSTANTS & TYPES */
//=====================================================================================================================
typedef Std_ReturnType (*tUPDFlash_Erase)(uint32_t DestAddress, uint32_t Length);
typedef Std_ReturnType (*tUPDFlash_Write)(uint32_t DestAddress, uint8_t* SrcAddress, uint32_t Length);
typedef Std_ReturnType (*tUPDFlash_Compare)(uint32_t SrcAddress,  uint8_t* DestAddress, uint32_t Length);
typedef Std_ReturnType (*tUPDFlash_Read) (uint32_t SrcAddress, uint8_t* DestAddress, uint32_t Length);
typedef MemIf_JobResultType (*tUPDFlash_GetJobResult) (void);

typedef const struct sFlashDriverVtbl
{
	tUPDFlash_Erase Erase;
	tUPDFlash_Write Write;
	tUPDFlash_Compare Compare;
	tUPDFlash_Read  Read;
	tUPDFlash_GetJobResult GetJobResult;
} tFlashDriverVtbl;

enum // for WriteState
{
	UPDi_FLASHIOADAPTER_IDLE=0,

	// Flashing states - no operation
	UPDi_FLASHIOADAPTER_BUFFERING_MASK = 0x10,
	UPDi_FLASHIOADAPTER_SECTOR_START,//0x11
	UPDi_FLASHIOADAPTER_BUFFERING_SECTOR,//0x12
	UPDi_FLASHIOADAPTER_BUFFERING_PAGE,//0x3

	// Flashing states - ongoing job
	UPDi_FLASHIOADAPTER_PROCESSING_MASK = 0x20,
	UPDi_FLASHIOADAPTER_COMPARING,//0x21
	UPDi_FLASHIOADAPTER_ERASING,//0x22
	UPDi_FLASHIOADAPTER_WRITING,//0x23

	UPDi_FLASHIOADAPTER_PARTITION_ENDED = 0x40,

	UPDi_FLASHIOADAPTER_WRITEFAILURE_MASK = 0x80,
	UPDi_FLASHIOADAPTER_WRITEERROR,//0x81
	UPDi_FLASHIOADAPTER_ERASEERROR,//0x82
	UPDi_FLASHIOADAPTER_WRITEFAILED_UNCONTIGOUS_SECTOR,//0x83
	UPDi_FLASHIOADAPTER_WRITEFAILED_INVALID_PARTITION_END,//0x84
	UPDi_FLASHIOADAPTER_WRITEFAILED_UNEXPECTED_DATA,//0x85
};

enum // for RequestState
{
	UPDi_FLASHREQ_NONE=0,
	UPDi_FLASHREQ_READ_PENDING,
	UPDi_FLASHREQ_READING,
	UPDi_FLASHREQ_READDONE,
	UPDi_FLASHREQ_ERASING,
	UPDi_FLASHREQ_ERASE_PENDING,
};

typedef const struct sUPDiFlashArea
{
	uint32_t AreaAddress;
	uint32_t SectorSize;
	uint32_t SectorCount;
} tUPDiFlashArea;

typedef struct sUPDiFlashIoAdapter_Ram
{
	uint32_t PutPos;
	uint32_t GetPos;
	tUPDiPartition* pDestPartition;
	uint32_t SizeProcessed;
	uint32_t ReadSize;
	tUPDHashInfo Hash;

	// Flashing machine
	uint32_t SectorAddress;
	uint32_t SectorSize;
	uint32_t CurentAddress;
	uint32_t CurentSize;
	uint8_t  WriteState;

	// Request machine - for explicit read & erase
	uint8_t  RequestState;
	tUPDiPartition* ReqPartition;
	uint32_t ReqOffset;
	uint32_t ReqSize;
	uint8_t* ReqData;
	MemIf_JobResultType ReqStatus;
	uint32_t EraseUntilAddress;

} tUPDiFlashIoAdapter_Ram;

typedef const struct sUPDiFlashIoAdapter
{
	tUPDiIoAdapterVtbl* pVtbl;
	tUPDiFlashIoAdapter_Ram* pRam;
	uint8_t* pBuffer;
	uint32_t BufferSize; // have to be multiple of the page size,
	// shall be bigger than a sector if EnableSectorBufferring is TRUE

	tFlashDriverVtbl* FlashDriver;

	uint32_t PageSize;
	// Define the the size of data chunk to for write operation
	// Some HW may propose different page sizes, with different write speed
	// Buffer page size is generally faster, but also requires bigger buffer.

	uint32_t LowBufferThreshold; // Threshold to indicate to the client that new input data will be required soon
	// This threshold is defined is Bytes and shall be one page or more.
	// is SectorBufferring is enabled it shall be one sector or more

	tUPDiFlashArea* pAreas;
	uint8_t  AreaCount;
	uint8_t  BlankPattern; // Generally 0xFF, used if BlankPatternDetection is enabled

	boolean EnableBlankDetection; // When enabled, blank pages are not flashed, because flash is supposed to be blank after erase.
	// Note that enabling BlankDetection may not compatible with all HW,
	// some HW impose writing once after erase (for initializing ECC redundant bits for example)

	boolean EnableSectorBufferring; // When enabled the sector is buffered first in RAM,
	// before erasing the sector is compared with the buffer and erasing to skipped if the content matches.
} tUPDiFlashIoAdapter;

//=====================================================================================================================
//  User Public functions
//=====================================================================================================================
void UPDiFlashIoAdapter_Init(tUPDiFlashIoAdapter* This);

Std_ReturnType UPDiFlashIoAdapter_StartWriting (tUPDiFlashIoAdapter* This, tUPDiPartition* pDestPartition, uint32_t DestOffset, uint32_t EraseUntil);
Std_ReturnType UPDiFlashIoAdapter_FinishWriting (tUPDiFlashIoAdapter* This, boolean ProcessQueue, uint32_t* pResumeAt, uint32_t* pEraseUntil);

tUPDWorkload   UPDiFlashIoAdapter_Task (tUPDiFlashIoAdapter* This);
Std_ReturnType UPDiFlashIoAdapter_Read(tUPDiFlashIoAdapter* This, tUPDiPartition* Partition, uint32_t Offset, uint32_t Size, uint8_t* Data);
Std_ReturnType UPDiFlashIoAdapter_Erase(tUPDiFlashIoAdapter* This, tUPDiPartition* Partition);

//=====================================================================================================================
//  VTBL
//=====================================================================================================================
extern tUPDiIoAdapterVtbl UPDiFlashIoAdapterVtbl;

#endif /*UPD_LocalIoAdapter_H*/
