/***************************************************************************** 
* * 
* CONFIDENTIAL VISTEON CORPORATION * 
* * 
* This is an unpublished work of authorship, which contains trade * 
* secrets, created in 2023. Visteon Corporation owns all rights to * 
* this work and intends to maintain it in confidence to preserve * 
* its trade secret status. Visteon Corporation reserves the right, * 
* under the copyright laws of the United States or those of any * 
* other country that may have jurisdiction, to protect this work * 
* as an unpublished work, in the event of an inadvertent or * 
* deliberate unauthorized publication. Visteon Corporation also * 
* reserves its rights under all copyright laws to protect this * 
* work as a published work, when appropriate. Those having access * 
* to this work may not copy it, use it, modify it or disclose the * 
* information contained in it without the written authorization * 
* of Visteon Corporation. * 
* * 
******************************************************************************/ 
#ifndef UPD_QSPIIOADAPTER_H 
#define UPD_QSPIIOADAPTER_H 
#include "UPDi_LocalIoAdapter.h" 
#include "MemIf_Types.h" 

//===================================================================================================================== 
/* MACRO : Construction helper */ 
//===================================================================================================================== 
#define UPD_DECLARE_QSPI_IOADAPTER(_name_, _Areas, _DriverVtbl, _BufferSize, _LowBufferThreshold, _PageSize, _EnableBlankDetection, _BlankPattern, _EnableSectorBufferring) \
uint8_t  _name_##_Buffer[_BufferSize];\
tUPDiQSPIIoAdapter_Ram  _name_##_ram;\
tUPDiQSPIIoAdapter   _name_ =\
{\
    .pVtbl = &UPDiQSPIIoAdapterVtbl,\
    .pRam = &_name_##_ram,\
    .pBuffer = &_name_##_Buffer[0],\
    .BufferSize = sizeof(_name_##_Buffer),\
    .QSPIFlashDriver = &_DriverVtbl,\
    .PageSize = _PageSize,\
    .LowBufferThreshold = _LowBufferThreshold,\
    .pAreas = &_Areas[0],\
    .AreaCount = sizeof(_Areas) / sizeof(tUPDiQSPIArea),\
    .BlankPattern = _BlankPattern,\
    .EnableBlankDetection = _EnableBlankDetection,\
    .EnableSectorBufferring = _EnableSectorBufferring,\
} 

//===================================================================================================================== 
/* CONSTANTS & TYPES */ 
//===================================================================================================================== 
typedef Std_ReturnType (*tUPDQSPI_Erase)(uint8_t DeviceNo, uint32_t DestAddress, uint32_t Length, boolean IsChipErase); 
typedef Std_ReturnType (*tUPDQSPI_Write)(uint8_t DeviceNo, uint32_t DestAddress, uint8_t* SrcAddress, uint32_t Length); 
typedef Std_ReturnType (*tUPDQSPI_Compare)(uint32_t SrcAddress, uint8_t* DestAddress, uint32_t Length); 
typedef Std_ReturnType (*tUPDQSPI_Read)(uint32_t SrcAddress, uint8_t* DestAddress, uint32_t Length); 
typedef MemIf_JobResultType (*tUPDQSPI_GetJobResult)(uint8_t DeviceNo); 

typedef const struct sQSPIFlashDriverVtbl 
{ 
    tUPDQSPI_Erase Erase; 
    tUPDQSPI_Write Write; 
    tUPDQSPI_Compare Compare; 
    tUPDQSPI_Read Read; 
    tUPDQSPI_GetJobResult GetJobResult; 
} tQSPIFlashDriverVtbl; 

enum // for WriteState 
{ 
    UPDi_QSPIIOADAPTER_IDLE = 0, 
    UPDi_QSPIIOADAPTER_BUFFERING_MASK = 0x10, 
    UPDi_QSPIIOADAPTER_SECTOR_START, 
    UPDi_QSPIIOADAPTER_BUFFERING_SECTOR, 
    UPDi_QSPIIOADAPTER_BUFFERING_PAGE, 
    UPDi_QSPIIOADAPTER_PROCESSING_MASK = 0x20, 
    UPDi_QSPIIOADAPTER_COMPARING, 
    UPDi_QSPIIOADAPTER_ERASING, 
    UPDi_QSPIIOADAPTER_WRITING, 
    UPDi_QSPIIOADAPTER_PARTITION_ENDED = 0x40, 
    UPDi_QSPIIOADAPTER_WRITEFAILURE_MASK = 0x80, 
    UPDi_QSPIIOADAPTER_WRITEERROR, 
    UPDi_QSPIIOADAPTER_ERASEERROR, 
    UPDi_QSPIIOADAPTER_WRITEFAILED_UNCONTIGOUS_SECTOR, 
    UPDi_QSPIIOADAPTER_WRITEFAILED_INVALID_PARTITION_END, 
    UPDi_QSPIIOADAPTER_WRITEFAILED_UNEXPECTED_DATA, 
}; 

enum // for RequestState 
{ 
    UPDi_QSPIREQ_NONE = 0, 
    UPDi_QSPIREQ_READ_PENDING, 
    UPDi_QSPIREQ_READING, 
    UPDi_QSPIREQ_READDONE, 
    UPDi_QSPIREQ_ERASING, 
    UPDi_QSPIREQ_ERASE_PENDING, 
}; 

typedef const struct sUPDiQSPIArea 
{ 
    uint32_t AreaAddress; 
    uint32_t SectorSize; 
    uint32_t SectorCount; 
} tUPDiQSPIArea; 

typedef struct sUPDiQSPIIoAdapter_Ram 
{ 
    uint32_t PutPos; 
    uint32_t GetPos; 
    tUPDiPartition* pDestPartition; 
    uint32_t SizeProcessed; 
    uint32_t ReadSize; 
    tUPDHashInfo Hash; 
    uint32_t SectorAddress; 
    uint32_t SectorSize; 
    uint32_t CurentAddress; 
    uint32_t CurentSize; 
    uint8_t WriteState; 
    uint8_t RequestState; 
    tUPDiPartition* ReqPartition; 
    uint32_t ReqOffset; 
    uint32_t ReqSize; 
    uint8_t* ReqData; 
    MemIf_JobResultType ReqStatus; 
    uint32_t EraseUntilAddress; 
} tUPDiQSPIIoAdapter_Ram; 

typedef const struct sUPDiQSPIIoAdapter 
{ 
    tUPDiIoAdapterVtbl* pVtbl; 
    tUPDiQSPIIoAdapter_Ram* pRam; 
    uint8_t* pBuffer; 
    uint32_t BufferSize; 
    tQSPIFlashDriverVtbl* QSPIFlashDriver; 
    uint32_t PageSize; 
    uint32_t LowBufferThreshold; 
    tUPDiQSPIArea* pAreas; 
    uint8_t AreaCount; 
    uint8_t BlankPattern; 
    boolean EnableBlankDetection; 
    boolean EnableSectorBufferring; 
} tUPDiQSPIIoAdapter; 

typedef enum
{
    QSPIIF_JOB_OK = 1,
    QSPIIF_JOB_PENDING,
    QSPIIF_JOB_FAILED,
    QSPIIF_JOB_CANCELED,
    QSPIIF_BLOCK_INCONSISTENT,
    QSPIIF_BLOCK_INVALID
}QSPIIf_JobResultType;

//===================================================================================================================== 
// User Public functions 
//===================================================================================================================== 
void UPDiQSPIIoAdapter_Init(tUPDiQSPIIoAdapter* This); 
Std_ReturnType UPDiQSPIIoAdapter_StartWriting(tUPDiQSPIIoAdapter* This, tUPDiPartition* pDestPartition, uint32_t DestOffset, uint32_t EraseUntil); 
Std_ReturnType UPDiQSPIIoAdapter_FinishWriting(tUPDiQSPIIoAdapter* This, boolean ProcessQueue, uint32_t* pResumeAt, uint32_t* pEraseUntil); 
tUPDWorkload UPDiQSPIIoAdapter_Task(tUPDiQSPIIoAdapter* This); 
Std_ReturnType UPDiQSPIIoAdapter_Read(tUPDiQSPIIoAdapter* This, tUPDiPartition* Partition, uint32_t Offset, uint32_t Size, uint8_t* Data); 
Std_ReturnType UPDiQSPIIoAdapter_Erase(tUPDiQSPIIoAdapter* This, tUPDiPartition* Partition); 

//===================================================================================================================== 
// VTBL 
//===================================================================================================================== 
extern tUPDiIoAdapterVtbl UPDiQSPIIoAdapterVtbl; 

#endif /* UPD_QSPIIOADAPTER_H */ 
