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
# ifndef UPDI_BLOCKDEVIOADAPTER_H
# define UPDI_BLOCKDEVIOADAPTER_H

#include "UPDi_LocalIoAdapter.h"
#include "stdio.h"

//=====================================================================================================================
/* MACRO : Construction helper */
//=====================================================================================================================
#define UPD_DECLARE_BLOCKDEV_IOADAPTER(_name_, _Areas, _DriverVtbl, _BufferSize, _LowBufferThreshold, _PageSize,_EnableBlankDetection,_BlankPattern,_EnableSectorBufferring) \
uint8_t  _name_##_Buffer[_BufferSize];\
tUPDiBlockDevIoAdapter_Ram  _name_##_ram;\
tUPDiBlockDevIoAdapter   _name_ =\
{\
	.pVtbl = &UPDiBlockDevIoAdapterVtbl,\
	.pRam = &_name_##_ram,\
	.pBuffer = &_name_##_Buffer[0],\
	.BufferSize = sizeof( _name_##_Buffer),\
	.FlashDriver = NULL,\
	.PageSize = _PageSize,\
	.LowBufferThreshold = _LowBufferThreshold,\
	.pAreas = NULL,\
	.AreaCount = 0,\
	.BlankPattern = _BlankPattern,\
	.EnableBlankDetection=_EnableBlankDetection,\
	.EnableSectorBufferring=_EnableSectorBufferring,\
}

//=====================================================================================================================
/* CONSTANTS & TYPES */
//=====================================================================================================================
typedef Std_ReturnType (*tUPDBlockDev_Erase)(uint32_t DestAddress, uint32_t Length);
typedef Std_ReturnType (*tUPDBlockDev_Write)(uint32_t DestAddress, uint8_t* SrcAddress, uint32_t Length);
typedef Std_ReturnType (*tUPDBlockDev_Compare)(uint32_t SrcAddress,  uint8_t* DestAddress, uint32_t Length);
typedef Std_ReturnType (*tUPDBlockDev_Read) (uint32_t SrcAddress, uint8_t* DestAddress, uint32_t Length);
typedef Std_ReturnType (*tUPDBlockDev_GetJobResult) (void);

typedef const struct sBlockDevDriverVtbl
{
	tUPDBlockDev_Erase Erase;
	tUPDBlockDev_Write Write;
	tUPDBlockDev_Compare Compare;
	tUPDBlockDev_Read  Read;
	Std_ReturnType GetJobResult;
} tBlockDevDriverVtbl;

enum // for WriteState
{
	UPDi_BLOCKDEVIOADAPTER_IDLE=0,

	// Flashing states - no operation
	UPDi_BLOCKDEVIOADAPTER_BUFFERING_MASK = 0x10,
	UPDi_BLOCKDEVIOADAPTER_SECTOR_START,//0x11
	UPDi_BLOCKDEVIOADAPTER_BUFFERING_SECTOR,//0x12
	UPDi_BLOCKDEVIOADAPTER_BUFFERING_PAGE,//0x3

	// Flashing states - ongoing job
	UPDi_BLOCKDEVIOADAPTER_PROCESSING_MASK = 0x20,
	UPDi_BLOCKDEVIOADAPTER_COMPARING,//0x21
	UPDi_BLOCKDEVIOADAPTER_ERASING,//0x22
	UPDi_BLOCKDEVIOADAPTER_WRITING,//0x23

	UPDi_BLOCKDEVIOADAPTER_PARTITION_ENDED = 0x40,

	UPDi_BLOCKDEVIOADAPTER_WRITEFAILURE_MASK = 0x80,
	UPDi_BLOCKDEVIOADAPTER_WRITEERROR,//0x81
	UPDi_BLOCKDEVIOADAPTER_ERASEERROR,//0x82
	UPDi_BLOCKDEVIOADAPTER_WRITEFAILED_UNCONTIGOUS_SECTOR,//0x83
	UPDi_BLOCKDEVIOADAPTER_WRITEFAILED_INVALID_PARTITION_END,//0x84
	UPDi_BLOCKDEVIOADAPTER_WRITEFAILED_UNEXPECTED_DATA,//0x85
};

enum // for RequestState
{
	UPDi_BLOCKDEVREQ_NONE=0,
	UPDi_BLOCKDEVREQ_READ_PENDING,
	UPDi_BLOCKDEVREQ_READING,
	UPDi_BLOCKDEVREQ_READDONE,
	UPDi_BLOCKDEVREQ_ERASING,
	UPDi_BLOCKDEVREQ_ERASE_PENDING,
};

typedef const struct sUPDiBlockDevArea
{
	uint32_t AreaAddress;
	uint32_t SectorSize;
	uint32_t SectorCount;
} tUPDiBlockDevArea;

typedef struct sUPDiBlockDevIoAdapter_Ram
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
	Std_ReturnType ReqStatus;
	uint32_t EraseUntilAddress;
	FILE* fOut;
	FILE* fIn;

} tUPDiBlockDevIoAdapter_Ram;

typedef const struct sUPDiBlockDevIoAdapter
{
	tUPDiIoAdapterVtbl* pVtbl;
	tUPDiBlockDevIoAdapter_Ram* pRam;
	uint8_t* pBuffer;
	uint32_t BufferSize; // have to be multiple of the page size,
	// shall be bigger than a sector if EnableSectorBufferring is TRUE

	tBlockDevDriverVtbl* FlashDriver;

	uint32_t PageSize;
	// Define the the size of data chunk to for write operation
	// Some HW may propose different page sizes, with different write speed
	// Buffer page size is generally faster, but also requires bigger buffer.

	uint32_t LowBufferThreshold; // Threshold to indicate to the client that new input data will be required soon
	// This threshold is defined is Bytes and shall be one page or more.
	// is SectorBufferring is enabled it shall be one sector or more

	tUPDiBlockDevArea* pAreas;
	uint8_t  AreaCount;
	uint8_t  BlankPattern; // Generally 0xFF, used if BlankPatternDetection is enabled

	boolean EnableBlankDetection; // When enabled, blank pages are not flashed, because flash is supposed to be blank after erase.
	// Note that enabling BlankDetection may not compatible with all HW,
	// some HW impose writing once after erase (for initializing ECC redundant bits for example)

	boolean EnableSectorBufferring; // When enabled the sector is buffered first in RAM,
	// before erasing the sector is compared with the buffer and erasing to skipped if the content matches.
} tUPDiBlockDevIoAdapter;

//=====================================================================================================================
//  User Public functions
//=====================================================================================================================
void UPDiBlockDevIoAdapter_Init(tUPDiBlockDevIoAdapter* This);

Std_ReturnType UPDiBlockDevIoAdapter_StartWriting (tUPDiBlockDevIoAdapter* This, tUPDiPartition* pDestPartition, uint32_t DestOffset, uint32_t EraseUntil);
Std_ReturnType UPDiBlockDevIoAdapter_FinishWriting (tUPDiBlockDevIoAdapter* This, boolean ProcessQueue, uint32_t* pResumeAt, uint32_t* pEraseUntil);

tUPDWorkload   UPDiBlockDevIoAdapter_Task (tUPDiBlockDevIoAdapter* This);
Std_ReturnType UPDiBlockDevIoAdapter_Read(tUPDiBlockDevIoAdapter* This, tUPDiPartition* Partition, uint32_t Offset, uint32_t Size, uint8_t* Data);
Std_ReturnType UPDiBlockDevIoAdapter_Erase(tUPDiBlockDevIoAdapter* This, tUPDiPartition* Partition);

//=====================================================================================================================
//  VTBL
//=====================================================================================================================
extern tUPDiIoAdapterVtbl UPDiBlockDevIoAdapterVtbl;

#endif /*UPD_LocalIoAdapter_H*/
