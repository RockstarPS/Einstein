/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2012. Visteon Corporation owns all rights to           *
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
/*****************************************************************************
*  File Name         :  Fee.c                                                *
*  Module Short Name :  Fee                                                  *
*  VOBName           :                                                       *
*  Author            : vbalakr3                                              *
*  Description       : Request handling of Fee data module                   *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :                                                         *
*                                                                            *
******************************************************************************/
#ifndef FEE_C
#define FEE_C
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Fee.h"
#include "SchM_NvM.h"
#define FEE_CODE_SEC_START
#include "MemMap.h"
#define FEE_DATA_SEC_START
#include "MemMap.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

typedef enum
{
  FEE_PARTITION_UNINIT = 0,
  FEE_PARTITION_READY,
  FEE_PARTITION_ERROR,
  FEE_PARTITION_INIT_PROGRESS
}Fee_PartitionStatusType;

typedef enum
{
  FEE_BLOCK_EXIST = 0,
  FEE_BLOCK_NOT_EXIST,
  FEE_BLOCK_CANCELLED,
  FEE_BLOCK_INVALIDATED
}Fee_BlockStatusType;

typedef enum
{
  FEE_JOB_IDLE = 0,
  FEE_JOB_WRITE,
  FEE_JOB_READ,
  FEE_JOB_UNINIT,
  FEE_JOB_INTERNAL_BUSY
}Fee_JobActiveIdType;

typedef enum
{
  FEE_JOB_STATE_IDLE = 0,
  FEE_JOB_STATE_WRITE_HEADER1,
  FEE_JOB_STATE_WRITE_HEADER1_WAIT,
  FEE_JOB_STATE_WRITE_PAYLOAD,
  FEE_JOB_STATE_WRITE_PAYLOAD_WAIT,
  FEE_JOB_STATE_WRITE_HEADER2,
  FEE_JOB_STATE_WRITE_HEADER2_WAIT,
  FEE_JOB_STATE_READ_HEADER,
  FEE_JOB_STATE_READ_HEADER_WAIT,
  FEE_JOB_STATE_READ_PAYLOAD,
  FEE_JOB_STATE_READ_PAYLOAD_WAIT
}Fee_JobStateType;


typedef enum
{
  FEE_SECTOR_SWITCH_STATE_IDLE = 0,
  FEE_SECTOR_SWITCH_STATE_HEADER_WRITE,
  FEE_SECTOR_SWITCH_STATE_HEADER_WRITE_WAIT,
  FEE_SECTOR_SWITCH_STATE_SEARCH_NEXT_BLOCK,
  FEE_SECTOR_SWITCH_STATE_BLOCK_READ,
  FEE_SECTOR_SWITCH_STATE_BLOCK_READ_WAIT,
  FEE_SECTOR_SWITCH_STATE_BLOCK_READ_VALIDATE,
  FEE_SECTOR_SWITCH_STATE_BLOCK_WRITE,
  FEE_SECTOR_SWITCH_STATE_BLOCK_WRITE_WAIT,
  FEE_SECTOR_SWITCH_STATE_SECTOR_FOOTER_WRITE,
  FEE_SECTOR_SWITCH_STATE_SECTOR_FOOTER_WRITE_WAIT,
  FEE_SECTOR_SWITCH_STATE_SUSPENDED
}Fee_SectorSwitchStateType;


typedef enum
{
  FEE_PARTITION_STATE_IDLE = 0,
  FEE_PARTITION_STATE_SECTOR_HEADER_READ,
  FEE_PARTITION_STATE_SECTOR_HEADER_READ_WAIT,
  FEE_PARTITION_STATE_SECTOR_FOOTER_READ,
  FEE_PARTITION_STATE_WAIT_SECTOR_FOOTER_READ,
  FEE_PARTITION_STATE_VALIDATE_SECTOR,
  FEE_PARTITION_STATE_SECTOR_HEADER_WRITE,
  FEE_PARTITION_STATE_SECTOR_HEADER_WRITE_WAIT,
  FEE_PARTITION_STATE_SECTOR_FOOTER_WRITE,
  FEE_PARTITION_STATE_SECTOR_FOOTER_WRITE_WAIT,
  FEE_PARTITION_STATE_BLOCK_READ_HEADER,
  FEE_PARTITION_STATE_BLOCK_READ_HEADER_WAIT,
  FEE_PARTITION_STATE_BLOCK_READ_HEADER_VALIDATE,
#if (STD_ON == FEE_USE_BLANKCHECK)
  FEE_PARTITION_STATE_BLANK_CHECK_NEXTFREEADDRESS,
  FEE_PARTITION_STATE_BLANK_CHECK_NEXTFREEADDRESS_WAIT,
#endif
}Fee_PartitionStateType;


typedef enum
{
  FEE_SECTOR_ERASE_STATE_IDLE = 0,
  FEE_SECTOR_ERASE_STATE_ERASE,
  FEE_SECTOR_ERASE_STATE_ERASE_WAIT,
  FEE_SECTOR_ERASE_STATE_PROCESS_DEFERRED_ERASE,
  FEE_SECTOR_ERASE_STATE_SUSPENDED
}Fee_SectorEraseType;


typedef struct  
{
  uint32 NextFreeAddress;
  Fee_PartitionStatusType Status;
  uint8 OldSectorId;
  uint8 CurrentSectorId;
  uint8 EraseSectorId;
  uint8 count;
}Fee_PartitionType;

typedef struct  
{
	uint8* RamAddress;
	uint16 BlockId;
	uint16 Offset;
	uint16 Length;
	uint16 SearchBlockId;
	uint8 DataIndex;
	boolean CancelFlag;
	boolean FirstWrite;
	Fee_JobActiveIdType JobActiveId;
	Fee_JobStateType JobState;
	Fee_SectorSwitchStateType SectorSwitchState;
	Fee_PartitionStateType PartitionState;
	Fee_SectorEraseType SectorEraseState;
	MemIf_JobResultType JobResult;
	boolean RepeatStateMachine;
	Fee_SectorSwitchStateType ResumeSectorSwitchState;
	Fee_SectorEraseType ResumeSectorEraseState;
	boolean ProcessInternalJob;
	uint8 InternalJobTimer;
	uint8 CurPartition;
}Fee_JobType;

typedef struct  
{
	uint16 BlockId;
	uint16 PayloadLength;
	uint16 Reserved1;
	uint8 Reserved2;
	uint8 ValidityFlag;
}Fee_BlockHeaderType;


typedef struct  
{
	uint8 SectorId;
	uint8 count;
	uint16 Reserved1;
	uint16 Reserved2;
	uint16 Reserved3;
}Fee_SectorHeaderType;


typedef struct 
{
	uint8 SectorId;
	uint8 count;
	uint16 Reserved1;
	uint16 Reserved2;
	uint16 Reserved3;
}Fee_SectorFooterType;

typedef struct  
{
	Fee_BlockHeaderType Header;
	Fee_BlockHeaderType Footer;
	uint8  PayloadBuffer[FEE_MAX_LENGTH];
}Fee_BlockType;

typedef struct
{
	uint8 ValidSectorId;
	uint8 count;
	uint8 CurrentSectorId;
}Fee_SectorSearchType;


typedef struct 
{
	uint32 LatestAddress;
}Fee_BlockInformationType;


typedef struct
{
    uint8 ValidId;
    uint8 SectorEraseFlag[FEE_NUM_OF_SECTORS];
    uint8 SectorEraseEnable;
    uint8 NumberOfSectorsToErase;
}Fee_PartitionSectorPendingEraseType;


typedef struct
{
    uint8 HeaderWriteSectorId;
    uint8 count;
    uint8 HeaderWritePending;
}Fee_PartitionSectorPendingHeaderWriteType;


/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
static Fee_JobType Fee_Job;
static Fee_JobType Fee_JobCpy;
static Fee_BlockInformationType Fee_BlockInformation[FEE_NUM_BLOCKS];
static Fee_PartitionType Fee_Partition[FEE_NUM_PARTITIONS];
static Fee_SectorSearchType Fee_SectorSearch;
static Fee_BlockType Fee_SectorSwitchBlockBuffer;

static Fee_PartitionSectorPendingEraseType Fee_PartitionPendingSectorErase[FEE_NUM_PARTITIONS];

static Fee_PartitionSectorPendingHeaderWriteType Fee_PartitionSectorPendingHeaderWrite[FEE_NUM_PARTITIONS];

#ifdef __ghs__
#pragma alignvar (8)
#endif
static Fee_SectorHeaderType Fee_SectorHeader;
#ifdef __ghs__
#pragma alignvar (8)
#endif
static Fee_SectorFooterType Fee_SectorFooter;
#ifdef __ghs__
#pragma alignvar (8)
#endif
static Fee_BlockHeaderType Fee_BlockHeader[2];

/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/
static void Fee_JobWriteHeader1(void);
static void Fee_JobWriteHeader1Wait(void);
static void Fee_JobWritePayload(void);
static void Fee_JobWritePayloadWait(void);
static void Fee_JobWriteHeader2(void);
static void Fee_JobWriteHeader2Wait(void);
static void Fee_JobReadHeader(void);
static void Fee_JobReadHeaderWait(void);
static Fee_BlockStatusType Fee_HeaderValidate(void);
static void Fee_JobReadPayload(void);
static void Fee_JobReadPayloadWait(void);
static void Fee_JobStateProcess(void);
static void Fee_PartitionSectorHeaderRead(void);
static void Fee_PartitionSectorHeaderReadWait(void);
static void Fee_PartitionSectorFooterRead(void);
static void Fee_PartitionSectorFooterReadWait(void);
static void Fee_ValidateSector(void);
static void Fee_PartitionSectorHeaderWrite(void);
static void Fee_PartitionSectorHeaderWriteWait(void);
static void Fee_PartitionSectorFooterWrite(void);
static void Fee_PartitionSectorFooterWriteWait(void);
static void Fee_PartitionBlockReadHeader(void);
static void Fee_PartitionBlockReadHeaderWait(void);
static void Fee_PartitionBlockValidate(void);
static void Fee_PartitionStateProcess(void);
static void Fee_SectorErase(void);
static void Fee_SectorEraseWait(void);
static void Fee_SectorEraseStateProcess(void);
#if FEE_BACKGROUND_SECTORSWITCH == STD_ON
static void Fee_BackgroundSectorSwitch(void);
#endif
static void Fee_SectorSwitchHeaderWrite(void);
static void Fee_SectorSwitchHeaderWriteWait(void);
static void Fee_SectorSwitchSearchNextBlock(void);
static void Fee_SectorSwitchBlockRead(void);
static void Fee_SectorSwitchBlockReadWait(void);
static void Fee_SectorSwitchBlockWrite(void);
static void Fee_SectorSwitchBlockWriteWait(void);
static void Fee_SectorSwitchSectorFooterWrite(void);
static void Fee_SectorSwitchSectorFooterWriteWait(void);
static void Fee_SectorSwitchStateProcess(void);
static Std_ReturnType Fee_SectorSwitchRequired(uint8 fl_PartionNo, uint16 fl_Length);
static void Fee_NotifyInternalJobStatus(uint8 State);
static void Fee_RestoreJobState(void);
static boolean Fee_ProcessJobStateMachine(void);
#if (STD_ON == FEE_USE_BLANKCHECK)
static void Fee_PartitionBlankCheckNextFreeAddress(void);
static void Fee_PartitionBlankCheckNextFreeAddressWait(void);
#endif
 


/*****************************************************************************
*                   Functions                                                *
******************************************************************************/

/**************************************************************************
Function name   : void Fee_Init(void)
Arguments       : void
Return type     : void
Description     : Service to initialize the FEE module. 
**************************************************************************/
void Fee_Init(void)
{
  uint16 fl_BlockId;
  uint8 fl_PartionNo;
  uint8 fl_SectorNo;
  Fee_Job.JobActiveId = FEE_JOB_UNINIT;
  Fee_Job.BlockId = 0U;
  Fee_Job.DataIndex = 0U;
  Fee_Job.JobResult = MEMIF_JOB_OK;
  Fee_Job.JobState = FEE_JOB_STATE_IDLE;
  Fee_Job.Length = 0U;
  Fee_Job.Offset = 0U;
  Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
  Fee_Job.RamAddress = NULL;
  Fee_Job.RepeatStateMachine = FALSE;
  Fee_Job.ProcessInternalJob = FALSE;
  Fee_Job.CancelFlag = FALSE;
  Fee_Job.InternalJobTimer = FEE_RELOAD_TIMER;
  Fee_Job.FirstWrite = FALSE;
  Fee_Job.CurPartition = 0U;
  Fee_Job.SearchBlockId = 0U;
  Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
  Fee_Job.ResumeSectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
  Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_IDLE;
  Fee_Job.ResumeSectorSwitchState = FEE_SECTOR_SWITCH_STATE_IDLE;

  
  for(fl_PartionNo = 0U; fl_PartionNo < FEE_NUM_PARTITIONS; fl_PartionNo++)
  {
    Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_UNINIT;
    Fee_Partition[fl_PartionNo].NextFreeAddress = 0U;
    Fee_Partition[fl_PartionNo].count = 0U;
    Fee_Partition[fl_PartionNo].CurrentSectorId = 0U;
    Fee_Partition[fl_PartionNo].OldSectorId = 0U;
    Fee_Partition[fl_PartionNo].EraseSectorId = 0U;

    Fee_PartitionSectorPendingHeaderWrite[fl_PartionNo].count = 0U;
    Fee_PartitionSectorPendingHeaderWrite[fl_PartionNo].HeaderWriteSectorId = 0U;
    Fee_PartitionSectorPendingHeaderWrite[fl_PartionNo].HeaderWritePending = FALSE;

    Fee_PartitionPendingSectorErase[fl_PartionNo].SectorEraseEnable = FALSE;
    Fee_PartitionPendingSectorErase[fl_PartionNo].ValidId = 0xFFU;
    Fee_PartitionPendingSectorErase[fl_PartionNo].NumberOfSectorsToErase = 0U;

    for(fl_SectorNo = 0U; fl_SectorNo < FEE_NUM_OF_SECTORS; fl_SectorNo++)
    {
        Fee_PartitionPendingSectorErase[fl_PartionNo].SectorEraseFlag[fl_SectorNo] = FALSE;
    }

  }

  for(fl_BlockId = 0U; fl_BlockId < FEE_NUM_BLOCKS; fl_BlockId++)
  {
    Fee_BlockInformation[fl_BlockId].LatestAddress = 0U;
  }
  Fee_SectorSearch.CurrentSectorId = 0U;
  Fee_SectorSearch.count =0U;
  Fee_SectorSearch.ValidSectorId = 0xFFU;

  Fee_Job.JobActiveId = FEE_JOB_IDLE;
}

/**************************************************************************
Function name   : void Fee_SetMode(MemIf_ModeType Mode)
Arguments       : MemIf_ModeType Mode
Return type     : void
Description     : Service to call the Fls_SetMode function of the underlying flash driver. 
**************************************************************************/
void Fee_SetMode(MemIf_ModeType Mode)
{
}

/**************************************************************************
Function name   : Std_ReturnType Fee_Read(uint16 BlockNumber, uint16 BlockOffset, uint8* DataBufferPtr, uint16 Length);
Arguments       : uint16 BlockNumber, uint16 BlockOffset, uint8* DataBufferPtr, uint16 Length
Return type     : Std_ReturnType
                    E_OK: The requested job has been accepted by the module.
                    E_NOT_OK: The requested job has not been accepted by the module.
Description     : Service to initiate a read job.
**************************************************************************/
Std_ReturnType Fee_Read(uint16 BlockNumber, uint16 BlockOffset, uint8* DataBufferPtr, uint16 Length)
{
  Std_ReturnType fl_RetVal;
  
  if(Fee_Job.JobActiveId == FEE_JOB_IDLE)
  {
    Fee_Job.InternalJobTimer = FEE_RELOAD_TIMER;
    Fee_Job.JobActiveId = FEE_JOB_READ;
    Fee_Job.BlockId = BlockNumber;
    Fee_Job.JobResult = MEMIF_JOB_PENDING;
    Fee_Job.JobState = FEE_JOB_STATE_READ_HEADER;
    Fee_Job.Length = Fee_BlockConfig[BlockNumber].BlockSize;
    Fee_Job.RamAddress = (uint8 *)DataBufferPtr;
    Fee_Job.Offset = BlockOffset;
    fl_RetVal = E_OK;
  }
  else
  {
    fl_RetVal = E_NOT_OK;
  }
  
  return fl_RetVal;
}

/**************************************************************************
Function name   : Std_ReturnType Fee_Write(uint16 BlockNumber, const uint8* DataBufferPtr);
Arguments       : uint16 BlockNumber, const uint8* DataBufferPtr
Return type     : Std_ReturnType
                    E_OK: The requested job has been accepted by the module.
                    E_NOT_OK: The requested job has not been accepted by the module.
Description     : Service to initiate a write job.
**************************************************************************/
Std_ReturnType Fee_Write(uint16 BlockNumber, const uint8* DataBufferPtr)
{
  Std_ReturnType fl_RetVal;
  
  if(Fee_Job.JobActiveId == FEE_JOB_IDLE)  //check if job state is in idle. if it is idle accept the job
  {
    Fee_Job.InternalJobTimer = FEE_RELOAD_TIMER;
    Fee_Job.JobActiveId = FEE_JOB_WRITE;   // update the job Active ID to FEE_JOB_WRITE
    Fee_Job.BlockId = BlockNumber;           //given by nvm in which block it should write
    Fee_Job.JobResult = MEMIF_JOB_PENDING;   // Update the Jb result as pending till the write option completes
    Fee_Job.JobState = FEE_JOB_STATE_WRITE_HEADER1;  
    Fee_Job.Length = Fee_BlockConfig[BlockNumber].BlockSize;
    Fee_Job.RamAddress = (uint8 *)DataBufferPtr;
    Fee_Job.Offset = 0U;
    fl_RetVal = E_OK;
  }
  else                                   //check if job state is in idle. if it is not in idle dont accept the job. return E_NOT_OK
  {
    fl_RetVal = E_NOT_OK;
  }

  return fl_RetVal;                     // return the job accepted status
}


/**************************************************************************
Function name   : Std_ReturnType Fee_Write(uint16 BlockNumber, const uint8* DataBufferPtr);
Arguments       : void
Return type     : void
Description     : Service to Cancel.
**************************************************************************/
void Fee_Cancel(void)
{
	uint8 fl_PartionNo;
    if(Fee_Job.JobActiveId == FEE_JOB_INTERNAL_BUSY && Fee_Job.JobState == FEE_JOB_STATE_WRITE_HEADER1)  /* case : Foreground Sector Switch & Diff Erase*/
    { 
		Fee_Job.JobResult = MEMIF_JOB_CANCELED;
		Fee_Job.JobState = FEE_JOB_STATE_IDLE;
		//Fee_Job.JobActiveId = FEE_JOB_IDLE;
		FEE_NVM_JOB_ERROR_NOTIFICATION();
    }
	else if (Fee_Job.PartitionState >= FEE_PARTITION_STATE_SECTOR_HEADER_WRITE &&\
			Fee_Job.PartitionState <= FEE_PARTITION_STATE_SECTOR_FOOTER_WRITE_WAIT) /* case : Sector Preperation */
	{
		Fee_Job.CancelFlag = TRUE;
	}
	else if (Fee_Job.PartitionState != FEE_PARTITION_STATE_IDLE) /* case : Partition Init */
	{
		if (MEMIF_JOB_PENDING == FLS_GET_JOB_RESULT())
		{
			FLS_CANCEL();
		}
		fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
		Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_UNINIT;
		Fee_Job.JobResult = MEMIF_JOB_CANCELED;
		Fee_Job.JobState = FEE_JOB_STATE_IDLE;
		Fee_Job.JobActiveId = FEE_JOB_IDLE;
		Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
		FEE_NVM_JOB_ERROR_NOTIFICATION();
	}
	else if (Fee_Job.JobActiveId == FEE_JOB_READ) /* case : Fee Read */
	{
		if (MEMIF_JOB_PENDING == FLS_GET_JOB_RESULT())
		{
			FLS_CANCEL();
		}
		Fee_Job.JobResult = MEMIF_JOB_CANCELED;
		Fee_Job.JobState = FEE_JOB_STATE_IDLE;
		Fee_Job.JobActiveId = FEE_JOB_IDLE;
		Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
		FEE_NVM_JOB_ERROR_NOTIFICATION();
	}
	else if (Fee_Job.JobActiveId == FEE_JOB_WRITE) /* case : Fee Write */
	{
		Fee_Job.CancelFlag = TRUE;
	}
    else 
    {
        //DO NOTHING
    }
}
/**************************************************************************
Function name   : MemIf_StatusType Fee_GetStatus(void)
Arguments       : void
Return type     : Memif_StatusType
                  MEMIF_UNINIT: The FEE module has not been initialized.
                  MEMIF_IDLE: The FEE module is currently idle.
                  MEMIF_BUSY: The FEE module is currently busy.
                  MEMIF_BUSY_INTERNAL: The FEE module is busy with internal management operations.
Description     : Service to return the status.
**************************************************************************/
MemIf_StatusType Fee_GetStatus(void)
{
  MemIf_StatusType fl_RetVal;
  if(Fee_Job.JobActiveId == FEE_JOB_UNINIT)
  {
    fl_RetVal = MEMIF_UNINIT;
  }
  else if(Fee_Job.JobActiveId == FEE_JOB_IDLE)
  {
    fl_RetVal = MEMIF_IDLE;
  }
  else if(Fee_Job.JobActiveId == FEE_JOB_INTERNAL_BUSY)
  {
    fl_RetVal = MEMIF_BUSY_INTERNAL;
  }
  else
  {
    fl_RetVal = MEMIF_BUSY;
  }
  return fl_RetVal;
}

/**************************************************************************
Function name   : MemIf_JobResultType Fee_GetJobResult(void)
Arguments       : void
Return type     : MemIf_JobResultType
                  MEMIF_JOB_OK: The last job has been finished successfully.
                  MEMIF_JOB_PENDING: The last job is waiting for execution or currently being executed.
                  MEMIF_JOB_CANCELED: The last job has been canceled (which means it failed).
                  MEMIF_JOB_FAILED: The last job has not been finished successfully (it failed).
                  MEMIF_BLOCK_INCONSISTENT: The requested block is inconsistent, it may contain corrupted data.
                  MEMIF_BLOCK_INVALID: The requested block has been invalidated, the requested read operation can not be performed.
Description     : Service to query the result of the last accepted job issued by the upper layer software.
**************************************************************************/
MemIf_JobResultType Fee_GetJobResult(void)
{
  return Fee_Job.JobResult;
}

/**************************************************************************
Function name   : Std_ReturnType Fee_InvalidateBlock( uint16 BlockNumber)
Arguments       : uint16 BlockNumber
Return type     : Std_ReturnType
                  E_OK: The requested job has been accepted by the module.
                  E_NOT_OK - only if DET is enabled: The requested job has not been accepted by the module.
Description     : Service to invalidate a logical block
**************************************************************************/
Std_ReturnType Fee_InvalidateBlock( uint16 BlockNumber)
{
  return E_NOT_OK;
}

/**************************************************************************
Function name   : void Fee_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr)
Arguments       : Std_VersionInfoType* VersionInfoPtr
Return type     : void
Description     : Service to return the version information of the FEE module.
**************************************************************************/
void Fee_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr)
{
}

/**************************************************************************
Function name   : Std_ReturnType Fee_EraseImmediateBlock(uint16 BlockNumber)
Arguments       : uint16 BlockNumber
Return type     : Std_ReturnType
                  E_OK: The requested job has been accepted by the module.
                  E_NOT_OK - only if DET is enabled: The requested job has not been accepted by the module.
Description     : This function is called by App/Scheduler when there is an
                  init required. 
**************************************************************************/
Std_ReturnType Fee_EraseImmediateBlock(uint16 BlockNumber)
{
  return E_NOT_OK;
}

/**************************************************************************
Function name   : void Fee_JobEndNotification(void)
Arguments       : void
Return type     : void
Description     : Service to report to this module the successful end of an asynchronous operation.
**************************************************************************/
void Fee_JobEndNotification(void)
{
}

/**************************************************************************
Function name   : void void Fee_JobErrorNotification(void)
Arguments       : void
Return type     : void
Description     : Service to report to this module the failure of an asynchronous operation.
**************************************************************************/
void Fee_JobErrorNotification(void)
{
}
/**************************************************************************
Function name   : void Fee_SuspendInternalJob(void)
Arguments       : void
Return type     : void
Description     : Service to Suspend all Internal Jobs.
**************************************************************************/
void Fee_SuspendInternalJob(void)
{
  	Fee_Job.ProcessInternalJob = FALSE;
    if((Fee_Job.SectorSwitchState == FEE_SECTOR_SWITCH_STATE_IDLE) && (Fee_Job.SectorEraseState == FEE_SECTOR_ERASE_STATE_IDLE))
    {
      Fee_NotifyInternalJobStatus(FEE_SUSPEND_INTERNAL_JOB);
  #ifdef MEM_TESTING_ENABLED
    //FEE_JOB_HOOK(FEE_SUSPEND_INTERNAL_JOB,Fee_Job.CurPartition);
  #endif
    }
}

/**************************************************************************
Function name   : void void Fee_ResumeInternalJob(void)
Arguments       : void
Return type     : void
Description     : Service to Resume all Internal Jobs.
**************************************************************************/
void Fee_ResumeInternalJob(void)
{
  if (FALSE != Fee_Job.FirstWrite)
  {
    Fee_Job.ProcessInternalJob = TRUE;
  }
  if((Fee_Job.SectorSwitchState == FEE_SECTOR_SWITCH_STATE_SUSPENDED) || (Fee_Job.SectorEraseState == FEE_SECTOR_ERASE_STATE_SUSPENDED))
  {
	Fee_RestoreJobState();
  }
  if((Fee_Job.SectorSwitchState == FEE_SECTOR_SWITCH_STATE_IDLE) && (Fee_Job.SectorEraseState == FEE_SECTOR_ERASE_STATE_IDLE))
  {
    Fee_NotifyInternalJobStatus(FEE_END_INTERNAL_JOB);
#ifdef MEM_TESTING_ENABLED
    //FEE_JOB_HOOK(FEE_END_INTERNAL_JOB,Fee_Job.CurPartition);
#endif
  }
}

/**************************************************************************
Function name   : void Fee_JobWriteHeader1(void)
Arguments       : void
Return type     : void
Description     : Service to initialize the Header Write
**************************************************************************/
static void Fee_JobWriteHeader1(void)
{
	if (FALSE == Fee_Job.FirstWrite)
	{
		Fee_Job.FirstWrite = TRUE;
		Fee_Job.ProcessInternalJob = TRUE;
	}
	uint8 fl_PartionNo;
	Std_ReturnType fl_SectorSwitchRequired;
	Std_ReturnType fl_RequestStatus;
	fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
	fl_SectorSwitchRequired = Fee_SectorSwitchRequired(fl_PartionNo, Fee_Job.Length + (FEE_HEADER_SIZE << 1));
	if (FALSE != Fee_Job.CancelFlag)
	{
		Fee_Job.JobResult = MEMIF_JOB_CANCELED;
		FEE_NVM_JOB_ERROR_NOTIFICATION();
		Fee_Job.JobState = FEE_JOB_STATE_IDLE;
		Fee_Job.JobActiveId = FEE_JOB_IDLE;
		Fee_Job.CancelFlag = FALSE;
		Fee_Job.RepeatStateMachine = FALSE;
	}
	else if(Fee_Partition[fl_PartionNo].Status == FEE_PARTITION_UNINIT)
	{
		Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_INIT_PROGRESS;
		Fee_SectorSearch.ValidSectorId = 0xFFU;
		Fee_SectorSearch.CurrentSectorId = Fee_PartitionConfig[fl_PartionNo].StartingSectorId;
		Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_HEADER_READ;
		Fee_Job.RepeatStateMachine = TRUE;
	}
	else if(FALSE != Fee_PartitionPendingSectorErase[fl_PartionNo].SectorEraseEnable)
	{
		Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_PROCESS_DEFERRED_ERASE;
		Fee_Job.JobActiveId = FEE_JOB_INTERNAL_BUSY;
		Fee_Job.CurPartition = fl_PartionNo;
		Fee_Job.RepeatStateMachine = TRUE;
	}
	else if(FALSE != Fee_PartitionSectorPendingHeaderWrite[fl_PartionNo].HeaderWritePending)
	{
		Fee_Partition[fl_PartionNo].CurrentSectorId = Fee_PartitionSectorPendingHeaderWrite[fl_PartionNo].HeaderWriteSectorId;
		Fee_Partition[fl_PartionNo].count = 0U;
		Fee_PartitionSectorPendingHeaderWrite[fl_PartionNo].HeaderWritePending = FALSE;
		Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_HEADER_WRITE;
	}
	else if (Fee_Partition[fl_PartionNo].Status == FEE_PARTITION_ERROR)
	{
		Fee_Job.JobResult = MEMIF_BLOCK_INVALID;
		FEE_NVM_JOB_ERROR_NOTIFICATION();
		Fee_Job.JobActiveId = FEE_JOB_IDLE;
		Fee_Job.JobState = FEE_JOB_STATE_IDLE;
		Fee_Job.RepeatStateMachine = FALSE;
	}
	else if (fl_SectorSwitchRequired == E_OK)
	{
		if (FALSE != Fee_Job.ProcessInternalJob)
		{
            Fee_Job.CurPartition = fl_PartionNo;
			Fee_Job.JobActiveId = FEE_JOB_INTERNAL_BUSY;
			Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_HEADER_WRITE;
			Fee_NotifyInternalJobStatus(FEE_START_INTERNAL_JOB);
		#ifdef MEM_TESTING_ENABLED
			FEE_JOB_HOOK(FEE_START_INTERNAL_JOB,Fee_Job.CurPartition);
		#endif
			Fee_Job.RepeatStateMachine = TRUE;
		}
	}
	else
	{
		Fee_BlockHeader[0].BlockId = Fee_Job.BlockId;
		Fee_BlockHeader[0].PayloadLength = Fee_Job.Length;
		Fee_BlockHeader[0].Reserved1 = 0xFFFFU;
		Fee_BlockHeader[0].Reserved2 = 0xFFU;
		Fee_BlockHeader[0].ValidityFlag = FEE_BLOCK_VALIDITY_FLAG_VALID;
		fl_RequestStatus = FLS_WRITE(Fee_Partition[fl_PartionNo].NextFreeAddress,(uint8 *)&Fee_BlockHeader[0].BlockId,FEE_HEADER_SIZE);    //  where write in fls begin
		if(fl_RequestStatus == E_OK)
		{
			Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_Partition[fl_PartionNo].NextFreeAddress + (FEE_HEADER_SIZE << 1);
			Fee_Job.JobState = FEE_JOB_STATE_WRITE_HEADER1_WAIT;
			Fee_Job.RepeatStateMachine = FALSE;
		}
		else
		{
			Fee_Job.JobResult = MEMIF_JOB_FAILED;
			FEE_NVM_JOB_ERROR_NOTIFICATION();
			Fee_Job.JobActiveId = FEE_JOB_IDLE;
			Fee_Job.JobState = FEE_JOB_STATE_IDLE;
			Fee_Job.RepeatStateMachine = FALSE;
		}
	}
}

/**************************************************************************
Function name   : Std_ReturnType Fee_SectorSwitchRequired(uint8 fl_PartionNo, uint16 fl_Length)
Arguments       : fl_PartionNo, fl_Length
Return type     : Std_ReturnType
Description     : Service to Check the Sector Sith required. 
                  E_OK - Sector Switch Required
                  E_NOT_OK - Sector Switch Not Required.
**************************************************************************/
static Std_ReturnType Fee_SectorSwitchRequired(uint8 fl_PartionNo, uint16 fl_Length)
{
  uint16 fl_RemainingDataBytes;
  Std_ReturnType fl_RetVal;
  uint8 fl_CurrentSectorId;
							
	fl_CurrentSectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
	
	fl_RemainingDataBytes = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress + \
							 Fee_SectorConfig[fl_CurrentSectorId].SectorSize - FEE_SECTOR_FOOTER_SIZE - \
							 Fee_Partition[fl_PartionNo].NextFreeAddress;
	
  if(fl_RemainingDataBytes < fl_Length)
  {
    fl_RetVal = E_OK;
  }
  else
  {
    fl_RetVal = E_NOT_OK;
  }
  return fl_RetVal;
} 

/**************************************************************************
Function name   : void Fee_JobWriteHeader1Wait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result 
**************************************************************************/
static void Fee_JobWriteHeader1Wait(void)
{
	uint8 fl_PartionNo;
	MemIf_JobResultType fl_FlsJobStatus;
	fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
	fl_FlsJobStatus = FLS_GET_JOB_RESULT();
	if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
	{
		if(fl_FlsJobStatus == MEMIF_JOB_OK)
		{
			if (FALSE != Fee_Job.CancelFlag)
			{
				Fee_Job.JobState = FEE_JOB_STATE_WRITE_HEADER2;
				Fee_Job.RepeatStateMachine = TRUE;
			}
			else 
			{
				Fee_Job.JobState = FEE_JOB_STATE_WRITE_PAYLOAD;
				Fee_Job.RepeatStateMachine = TRUE;
			}
		}
		else
		{ 
			Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_Partition[fl_PartionNo].NextFreeAddress + Fee_Job.Length;
			Fee_Job.JobResult = MEMIF_JOB_FAILED;
			FEE_NVM_JOB_ERROR_NOTIFICATION();
			Fee_Job.JobActiveId = FEE_JOB_IDLE;
			Fee_Job.JobState = FEE_JOB_STATE_IDLE;
			Fee_Job.RepeatStateMachine = FALSE;
		}
	}
	else
	{
		/* Wait for Next State Machine */
		Fee_Job.RepeatStateMachine = FALSE;
	}
}

/**************************************************************************
Function name   : void Fee_JobWritePayload(void)
Arguments       : void
Return type     : void
Description     : Write Payload request
**************************************************************************/
static void Fee_JobWritePayload(void)
{
  uint8 fl_PartionNo;
  Std_ReturnType fl_RequestType;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_RequestType = FLS_WRITE(Fee_Partition[fl_PartionNo].NextFreeAddress,(uint8 *)Fee_Job.RamAddress,Fee_Job.Length);
  if(fl_RequestType == E_OK)
  {
    Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_Partition[fl_PartionNo].NextFreeAddress - FEE_HEADER_SIZE;
    Fee_Job.JobState = FEE_JOB_STATE_WRITE_PAYLOAD_WAIT;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else
  { 
    Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_Partition[fl_PartionNo].NextFreeAddress + Fee_Job.Length;
    Fee_Job.JobResult = MEMIF_JOB_FAILED;
    FEE_NVM_JOB_ERROR_NOTIFICATION();
    Fee_Job.JobActiveId = FEE_JOB_IDLE;
    Fee_Job.JobState = FEE_JOB_STATE_IDLE;
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_JobWritePayloadWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result
**************************************************************************/
static void Fee_JobWritePayloadWait(void)
{
	uint8 fl_PartionNo;
	MemIf_JobResultType fl_FlsJobStatus;
	fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
	fl_FlsJobStatus = FLS_GET_JOB_RESULT();
	if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
		{
		if(fl_FlsJobStatus == MEMIF_JOB_OK)
		{
			Fee_Job.JobState = FEE_JOB_STATE_WRITE_HEADER2;
			Fee_Job.RepeatStateMachine = TRUE;
		}
		else
		{
			Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_Partition[fl_PartionNo].NextFreeAddress + FEE_HEADER_SIZE + Fee_Job.Length;
			Fee_Job.JobResult = MEMIF_JOB_FAILED;
			FEE_NVM_JOB_ERROR_NOTIFICATION();
			Fee_Job.JobActiveId = FEE_JOB_IDLE;
			Fee_Job.JobState = FEE_JOB_STATE_IDLE;
			Fee_Job.RepeatStateMachine = FALSE;
		}
	}
	else
	{
		if (FALSE != Fee_Job.CancelFlag)
		{
			FLS_CANCEL();
			Fee_Job.JobState = FEE_JOB_STATE_WRITE_HEADER2;
			Fee_Job.RepeatStateMachine = TRUE;
		}
		else 
		{
			/* Wait for Next State Machine */
			Fee_Job.RepeatStateMachine = FALSE;
		}
	}
}

/**************************************************************************
Function name   : void Fee_JobWriteHeader2(void)
Arguments       : void
Return type     : void
Description     : Request write Header2
**************************************************************************/
static void Fee_JobWriteHeader2(void)
{
	uint8 fl_PartionNo;
	Std_ReturnType fl_RequestType;
	fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
	Fee_BlockHeader[1].BlockId = (uint16)~Fee_Job.BlockId;
	Fee_BlockHeader[1].PayloadLength = (uint16)~Fee_Job.Length;
	Fee_BlockHeader[1].Reserved1 = 0x0000U;
	Fee_BlockHeader[1].Reserved2 = 0x00U;
	if (FALSE != Fee_Job.CancelFlag)
	{
		Fee_BlockHeader[1].ValidityFlag = FEE_BLOCK_VALIDITY_FLAG_INVALID;
	}
	else
	{
		Fee_BlockHeader[1].ValidityFlag = FEE_BLOCK_VALIDITY_FLAG_VALID;
	}
	fl_RequestType = FLS_WRITE(Fee_Partition[fl_PartionNo].NextFreeAddress,(uint8 *)&Fee_BlockHeader[1].BlockId,FEE_HEADER_SIZE);
	Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_Partition[fl_PartionNo].NextFreeAddress + FEE_HEADER_SIZE + Fee_Job.Length;
	if(fl_RequestType == E_OK)
	{
		Fee_Job.JobState = FEE_JOB_STATE_WRITE_HEADER2_WAIT;
		Fee_Job.RepeatStateMachine = FALSE;
	}
	else
	{
		Fee_Job.JobResult = MEMIF_JOB_FAILED;
		FEE_NVM_JOB_ERROR_NOTIFICATION();
		Fee_Job.JobActiveId = FEE_JOB_IDLE;
		Fee_Job.JobState = FEE_JOB_STATE_IDLE;
		Fee_Job.RepeatStateMachine = FALSE;
	}
}

/**************************************************************************
Function name   : void Fee_JobWriteHeader2Wait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result 
**************************************************************************/
static void Fee_JobWriteHeader2Wait(void)
{
	uint8 fl_PartionNo;
	MemIf_JobResultType fl_FlsJobStatus;
	fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
	fl_FlsJobStatus = FLS_GET_JOB_RESULT();
	if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
	{
		if(fl_FlsJobStatus == MEMIF_JOB_OK)
		{
			if (FALSE != Fee_Job.CancelFlag)
			{
				Fee_Job.JobResult = MEMIF_JOB_CANCELED;
				Fee_Job.CancelFlag = FALSE;
				FEE_NVM_JOB_ERROR_NOTIFICATION();
			}
			else
			{
				Fee_Job.JobResult = MEMIF_JOB_OK;
				Fee_BlockInformation[Fee_Job.BlockId].LatestAddress = Fee_Partition[fl_PartionNo].NextFreeAddress - (FEE_HEADER_SIZE << 1) - Fee_Job.Length;
				FEE_NVM_JOB_END_NOTIFICATION();
			}
			Fee_Job.JobActiveId = FEE_JOB_IDLE;
			Fee_Job.JobState = FEE_JOB_STATE_IDLE;
			Fee_Job.RepeatStateMachine = FALSE;
		}
		else
		{
			Fee_Job.JobResult = MEMIF_JOB_FAILED;
			FEE_NVM_JOB_ERROR_NOTIFICATION();
			Fee_Job.JobActiveId = FEE_JOB_IDLE;
			Fee_Job.JobState = FEE_JOB_STATE_IDLE;
			Fee_Job.RepeatStateMachine = FALSE;
		}
	}
	else
	{
	/* Wait for Next State Machine */
	Fee_Job.RepeatStateMachine = FALSE;
	}
}

/**************************************************************************
Function name   : void Fee_JobReadHeader(void)
Arguments       : void
Return type     : void
Description     : Request Read Header
**************************************************************************/
static void Fee_JobReadHeader(void)
{
  uint8 fl_PartionNo;
  Std_ReturnType fl_RequestStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  if(Fee_Partition[fl_PartionNo].Status == FEE_PARTITION_UNINIT)
  {
    Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_INIT_PROGRESS;
    Fee_SectorSearch.ValidSectorId = 0xFFU;
	  Fee_SectorSearch.CurrentSectorId = Fee_PartitionConfig[fl_PartionNo].StartingSectorId;  //vbalakr3
    Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_HEADER_READ;
    Fee_Job.RepeatStateMachine = TRUE;
  }
  else if (Fee_Partition[fl_PartionNo].Status == FEE_PARTITION_ERROR)
  {
    Fee_Job.JobResult = MEMIF_BLOCK_INVALID;
    FEE_NVM_JOB_ERROR_NOTIFICATION();
    Fee_Job.JobActiveId = FEE_JOB_IDLE;
    Fee_Job.JobState = FEE_JOB_STATE_IDLE;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else if (Fee_BlockInformation[Fee_Job.BlockId].LatestAddress == 0U)
  {
    Fee_Job.JobResult = MEMIF_BLOCK_INVALID;
    FEE_NVM_JOB_ERROR_NOTIFICATION();
    Fee_Job.JobActiveId = FEE_JOB_IDLE;
    Fee_Job.JobState = FEE_JOB_STATE_IDLE;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else
  {
    fl_RequestStatus = FLS_READ_WITHOUT_BLANKCHECK(Fee_BlockInformation[Fee_Job.BlockId].LatestAddress, (uint8 *)&Fee_BlockHeader[0].BlockId, (FEE_HEADER_SIZE<<1));
    if(fl_RequestStatus == E_OK)
    {
      Fee_Job.JobState = FEE_JOB_STATE_READ_HEADER_WAIT;
      Fee_Job.RepeatStateMachine = FALSE;
    }
    else
    {
      Fee_Job.JobResult = MEMIF_JOB_FAILED;
      FEE_NVM_JOB_ERROR_NOTIFICATION();
      Fee_Job.JobActiveId = FEE_JOB_IDLE;
      Fee_Job.JobState = FEE_JOB_STATE_IDLE;
      Fee_Job.RepeatStateMachine = FALSE;
    }
  }
}

/**************************************************************************
Function name   : void Fee_JobReadHeaderWait(void)
Arguments       : void
Return type     : void
Description     :Service to Check the Flash Driver Job Result
**************************************************************************/
static void Fee_JobReadHeaderWait(void)
{
  MemIf_JobResultType fl_FlsJobStatus;
  Fee_BlockStatusType fl_HeaderValidity;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
      fl_HeaderValidity = Fee_HeaderValidate();
      if(fl_HeaderValidity == FEE_BLOCK_EXIST)
      {
        Fee_Job.JobState = FEE_JOB_STATE_READ_PAYLOAD;
        Fee_Job.RepeatStateMachine = TRUE;
      }
      else
      {
        Fee_Job.JobResult = MEMIF_BLOCK_INCONSISTENT;
        FEE_NVM_JOB_ERROR_NOTIFICATION();
        Fee_Job.JobActiveId = FEE_JOB_IDLE;
        Fee_Job.JobState = FEE_JOB_STATE_IDLE;
        Fee_Job.RepeatStateMachine = FALSE;
      }
    }
    else
    {
      Fee_Job.JobResult = MEMIF_JOB_FAILED;
      FEE_NVM_JOB_ERROR_NOTIFICATION();
      Fee_Job.JobActiveId = FEE_JOB_IDLE;
      Fee_Job.JobState = FEE_JOB_STATE_IDLE;
      Fee_Job.RepeatStateMachine = FALSE;
    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_HeaderValidate(void)
Arguments       : void
Return type     : Fee_BlockStatusType
Description     : Validate the Block
**************************************************************************/
static Fee_BlockStatusType Fee_HeaderValidate(void)
{
	Fee_BlockStatusType fl_RetVal;
	fl_RetVal = FEE_BLOCK_NOT_EXIST;
	if(Fee_BlockHeader[0].BlockId == (uint16)~Fee_BlockHeader[1].BlockId )
	{
		if(Fee_BlockHeader[0].PayloadLength == (uint16)~Fee_BlockHeader[1].PayloadLength)
		{
			if(Fee_BlockHeader[0].ValidityFlag == FEE_BLOCK_VALIDITY_FLAG_INVALID)
			{
				fl_RetVal = FEE_BLOCK_INVALIDATED;
			}
			else if(Fee_BlockHeader[1].ValidityFlag == FEE_BLOCK_VALIDITY_FLAG_INVALID)
			{
				fl_RetVal = FEE_BLOCK_CANCELLED;
			}
			else
			{
				fl_RetVal = FEE_BLOCK_EXIST;
			}
		}
	}
	return fl_RetVal;
}

/**************************************************************************
Function name   : void Fee_JobReadPayload(void)
Arguments       : void
Return type     : void
Description     : Request Read Payload
**************************************************************************/
static void Fee_JobReadPayload(void)
{
  uint32 fl_PayLoadAddress;
  Std_ReturnType fl_RequestStatus;
  fl_PayLoadAddress = Fee_BlockInformation[Fee_Job.BlockId].LatestAddress + (FEE_HEADER_SIZE << 1) + Fee_Job.Offset;
  fl_RequestStatus = FLS_READ_WITHOUT_BLANKCHECK(fl_PayLoadAddress, (uint8 *)Fee_Job.RamAddress, Fee_Job.Length);
  if(fl_RequestStatus == E_OK)
  {
    Fee_Job.JobState = FEE_JOB_STATE_READ_PAYLOAD_WAIT;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else
  {
    Fee_Job.JobResult = MEMIF_JOB_FAILED;
    FEE_NVM_JOB_ERROR_NOTIFICATION();
    Fee_Job.JobActiveId = FEE_JOB_IDLE;
    Fee_Job.JobState = FEE_JOB_STATE_IDLE;
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_JobReadPayloadWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result 
**************************************************************************/
static void Fee_JobReadPayloadWait(void)
{
  MemIf_JobResultType fl_FlsJobStatus;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
      Fee_Job.JobResult = MEMIF_JOB_OK;
      FEE_NVM_JOB_END_NOTIFICATION();
      Fee_Job.JobActiveId = FEE_JOB_IDLE;
      Fee_Job.JobState = FEE_JOB_STATE_IDLE;
      Fee_Job.RepeatStateMachine = FALSE;
    }
    else
    {
      Fee_Job.JobResult = MEMIF_JOB_FAILED;
      FEE_NVM_JOB_ERROR_NOTIFICATION();
      Fee_Job.JobActiveId = FEE_JOB_IDLE;
      Fee_Job.JobState = FEE_JOB_STATE_IDLE;
      Fee_Job.RepeatStateMachine = FALSE;
    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}


/**************************************************************************
Function name   : void Fee_JobStateProcess(void)
Arguments       : void
Return type     : void
Description     : Job State machine Process
**************************************************************************/
static void Fee_JobStateProcess(void)
{
  if(Fee_ProcessJobStateMachine())
  {
    switch(Fee_Job.JobState)
    {
      case FEE_JOB_STATE_IDLE:
      break;
    
      case FEE_JOB_STATE_WRITE_HEADER1:
        Fee_JobWriteHeader1();
      break;
      
      case FEE_JOB_STATE_WRITE_HEADER1_WAIT:
        Fee_JobWriteHeader1Wait();
      break;
    
      case FEE_JOB_STATE_WRITE_PAYLOAD:
        Fee_JobWritePayload();
      break;
    
      case FEE_JOB_STATE_WRITE_PAYLOAD_WAIT:
        Fee_JobWritePayloadWait();
      break;
    
      case FEE_JOB_STATE_WRITE_HEADER2:
        Fee_JobWriteHeader2();
      break;
      
      case FEE_JOB_STATE_WRITE_HEADER2_WAIT:
        Fee_JobWriteHeader2Wait();
      break;
    
      case FEE_JOB_STATE_READ_HEADER:
        Fee_JobReadHeader();
      break;
    
      case FEE_JOB_STATE_READ_HEADER_WAIT:
        Fee_JobReadHeaderWait();
      break;
    
      case FEE_JOB_STATE_READ_PAYLOAD:
        Fee_JobReadPayload();
      break;
      
      case FEE_JOB_STATE_READ_PAYLOAD_WAIT:
        Fee_JobReadPayloadWait();
      break;

      default:
      //do nothing
      break;
    }
  }
  else
  {
    /* Wait until Sector Switch or Partition Init is completed */
  }
}

/**************************************************************************
Function name   : void Fee_ProcessJobStateMachine(void)
Arguments       : boolean
Return type     : void
Description     : Check to confirm the process of Job State Machine
**************************************************************************/
boolean Fee_ProcessJobStateMachine(void)
{
	boolean fl_return = FALSE;
	if(
		(FEE_PARTITION_STATE_IDLE == Fee_Job.PartitionState) && \
      	(FEE_SECTOR_SWITCH_STATE_IDLE == Fee_Job.SectorSwitchState) && \
      	(FEE_SECTOR_ERASE_STATE_IDLE == Fee_Job.SectorEraseState)
	)
	{
		fl_return = TRUE;
	}
	else if(
		(FEE_JOB_READ == Fee_Job.JobActiveId) && \
		((FEE_SECTOR_SWITCH_STATE_SUSPENDED == Fee_Job.SectorSwitchState) || \
		(FEE_SECTOR_ERASE_STATE_SUSPENDED == Fee_Job.SectorEraseState))
	)
	{
		fl_return = TRUE;
	}
	else 
	{
		fl_return = FALSE;
	}
	return fl_return;
}

/**************************************************************************
Function name   : void Fee_PartitionSectorHeaderRead(void)
Arguments       : void
Return type     : void
Description     : Sector Header Read init
**************************************************************************/
static void Fee_PartitionSectorHeaderRead(void)
{
  uint32 fl_SectorHeaderAddress;
  Std_ReturnType fl_RequestStatus;
  uint8 fl_CurrentSectorId;

  fl_CurrentSectorId = Fee_SectorSearch.CurrentSectorId;
  fl_SectorHeaderAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress;  //vbalakr3
  fl_RequestStatus = FLS_READ(fl_SectorHeaderAddress,(uint8 *)&Fee_SectorHeader.SectorId,FEE_SECTOR_HEADER_SIZE);
  if(fl_RequestStatus == E_OK)
  {
    Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_HEADER_READ_WAIT;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else
  {
    Fee_Job.JobResult = MEMIF_JOB_FAILED;
    FEE_NVM_JOB_ERROR_NOTIFICATION();
    Fee_Job.JobActiveId = FEE_JOB_IDLE;
    Fee_Job.JobState = FEE_JOB_STATE_IDLE;
    Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_PartitionSectorHeaderReadWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result 
**************************************************************************/
static void Fee_PartitionSectorHeaderReadWait(void)
{

  MemIf_JobResultType fl_FlsJobStatus;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
      Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_FOOTER_READ;
      Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
        /* Update the invalid value So Validate sector will take up the Sector Preparation */
        Fee_SectorHeader.SectorId = 0x5A;
        Fee_SectorHeader.count = 0x5A;
        Fee_SectorFooter.SectorId = 0x5A;
        Fee_SectorFooter.count = 0x5A;
        Fee_Job.PartitionState = FEE_PARTITION_STATE_VALIDATE_SECTOR;
        Fee_Job.RepeatStateMachine = TRUE;
    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_PartitionSectorFooterRead(void)
Arguments       : void
Return type     : void
Description     : Request Footer Read
**************************************************************************/
static void Fee_PartitionSectorFooterRead(void)
{
  uint32 fl_SectorFooterAddress;
  Std_ReturnType fl_RequestStatus;
  uint8 fl_SectorId;
  fl_SectorId = Fee_SectorSearch.CurrentSectorId;
  

	fl_SectorFooterAddress = Fee_SectorConfig[fl_SectorId].SectorStartAddress + \
							 Fee_SectorConfig[fl_SectorId].SectorSize - FEE_SECTOR_FOOTER_SIZE;

  fl_RequestStatus = FLS_READ(fl_SectorFooterAddress,(uint8 *)&Fee_SectorFooter.SectorId,FEE_SECTOR_FOOTER_SIZE);
  if(fl_RequestStatus == E_OK)
  {
    Fee_Job.PartitionState = FEE_PARTITION_STATE_WAIT_SECTOR_FOOTER_READ;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else
  {
    /* Footer Read failed */
    Fee_Job.JobResult = MEMIF_JOB_FAILED;
    FEE_NVM_JOB_ERROR_NOTIFICATION();
    Fee_Job.JobActiveId = FEE_JOB_IDLE;
    Fee_Job.JobState = FEE_JOB_STATE_IDLE;
    Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_PartitionSectorFooterReadWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result 
**************************************************************************/
static void Fee_PartitionSectorFooterReadWait(void)
{
  MemIf_JobResultType fl_FlsJobStatus;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
      Fee_Job.PartitionState = FEE_PARTITION_STATE_VALIDATE_SECTOR;
      Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
        /* Update the invalid value So Validate sector will take up the Sector Preparation */
        Fee_SectorHeader.SectorId = 0x5A;
        Fee_SectorHeader.count = 0x5A;
        Fee_SectorFooter.SectorId = 0x5A;
        Fee_SectorFooter.count = 0x5A;
        Fee_Job.PartitionState = FEE_PARTITION_STATE_VALIDATE_SECTOR;
        Fee_Job.RepeatStateMachine = TRUE;
    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_PrepareEraseSector(void)
Arguments       : void
Return type     : void
Description     : Prepare sector erase
                    1. If Read Job defer the sector erase
                    2  Else Proceed with Sector Erase
**************************************************************************/
static void Fee_PrepareEraseSector(uint8 PartitionNo, uint8 SectorNo)
{
    if(Fee_Job.JobActiveId != FEE_JOB_READ)
    {
        Fee_Partition[PartitionNo].EraseSectorId = SectorNo;
        Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_ERASE;
    }
    else
    {
        Fee_PartitionPendingSectorErase[PartitionNo].SectorEraseFlag[SectorNo] = TRUE;
        Fee_PartitionPendingSectorErase[PartitionNo].NumberOfSectorsToErase++;
        Fee_PartitionPendingSectorErase[PartitionNo].SectorEraseEnable = TRUE;
    }
}

/**************************************************************************
Function name   : void Fee_PrepareSctorHeader(void)
Arguments       : void
Return type     : void
Description     : Prepare sector erase
                    1. If Read Job defer the sector erase
                    2  Else Proceed with Sector Erase
**************************************************************************/
static void Fee_PrepareSctorHeader(uint8 PartitionNo, uint8 SectorNo)
{
    if(Fee_Job.JobActiveId != FEE_JOB_READ)
    {
      Fee_Partition[PartitionNo].CurrentSectorId = SectorNo;
      Fee_Partition[PartitionNo].count = 0U;
      Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_HEADER_WRITE;
    }
    else
    {
        Fee_PartitionSectorPendingHeaderWrite[PartitionNo].HeaderWriteSectorId = SectorNo;
        Fee_PartitionSectorPendingHeaderWrite[PartitionNo].HeaderWritePending = TRUE;
        Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
    }
}





/**************************************************************************
Function name   : void Fee_ValidateSector(void)
Arguments       : void
Return type     : void
Description     : Validate the latest sector
**************************************************************************/
static void Fee_ValidateSector(void)
{
  uint8 fl_PartionNo;
  uint8 fl_StartSectorId;
  uint8 fl_CurrentSectorId;
  uint8 fl_SectorCount;
  boolean fl_SectorValid;
  boolean fl_SectorEmpty;

  fl_SectorValid = FALSE;
  fl_SectorEmpty = FALSE;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  if((Fee_SectorHeader.SectorId == 0xFFU) && (Fee_SectorHeader.count == 0xFFU))
  {
    if((Fee_SectorFooter.SectorId == 0xFFU) && (Fee_SectorFooter.count == 0xFFU))
    {
      fl_SectorEmpty = TRUE;
    }
  }
  if(Fee_SectorHeader.SectorId == (uint8)~Fee_SectorFooter.SectorId)
  {
    if(Fee_SectorHeader.count == (uint8)~Fee_SectorFooter.count)
    {
      fl_SectorValid = TRUE;
    }
  }
  if(FALSE == fl_SectorEmpty)
  {
    if(FALSE != fl_SectorValid)
    {
      if(Fee_SectorSearch.ValidSectorId != 0xFFU)
      {
        if(Fee_SectorSearch.count > Fee_SectorHeader.count)
        {
          if((Fee_SectorSearch.count - Fee_SectorHeader.count) > 1)
          {
            Fee_PrepareEraseSector(fl_PartionNo, Fee_SectorSearch.ValidSectorId);
            Fee_SectorSearch.ValidSectorId = Fee_SectorHeader.SectorId;
            Fee_SectorSearch.count = Fee_SectorHeader.SectorId;
            Fee_Job.RepeatStateMachine = TRUE;
          }
          else
          {
            Fee_PrepareEraseSector(fl_PartionNo, Fee_SectorHeader.SectorId);
            Fee_Job.RepeatStateMachine = TRUE;
          }
        }
        else
        {
          if((Fee_SectorHeader.count - Fee_SectorSearch.count) > 1)
          {
            Fee_PrepareEraseSector(fl_PartionNo, Fee_SectorHeader.SectorId);
            Fee_Job.RepeatStateMachine = TRUE;
          }
          else
          {
            Fee_PrepareEraseSector(fl_PartionNo, Fee_SectorSearch.ValidSectorId);
            Fee_SectorSearch.ValidSectorId = Fee_SectorHeader.SectorId;
            Fee_SectorSearch.count = Fee_SectorHeader.SectorId;
            Fee_Job.RepeatStateMachine = TRUE;
          }
        }
      }
      else
      {
        Fee_SectorSearch.ValidSectorId = Fee_SectorHeader.SectorId;
        Fee_SectorSearch.count = Fee_SectorHeader.SectorId;
      }
    }
    else
    {
        Fee_PrepareEraseSector(fl_PartionNo, Fee_SectorSearch.CurrentSectorId);
    }
  }
  fl_StartSectorId = Fee_PartitionConfig[fl_PartionNo].StartingSectorId; //vbalakr3
  fl_CurrentSectorId = Fee_SectorSearch.CurrentSectorId;
  fl_SectorCount = fl_CurrentSectorId - fl_StartSectorId + 1U;
  if(Fee_PartitionConfig[fl_PartionNo].NumberOfSectors  > fl_SectorCount )
  {
    Fee_SectorSearch.CurrentSectorId = fl_CurrentSectorId + 1U;
    Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_HEADER_READ;
    Fee_Job.RepeatStateMachine = TRUE;
  }
  else
  {
    if(Fee_SectorSearch.ValidSectorId == 0xFFU)
    {
      Fee_PrepareSctorHeader(fl_PartionNo, fl_StartSectorId);
      Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
      Fee_Partition[fl_PartionNo].CurrentSectorId = Fee_SectorSearch.ValidSectorId;
      Fee_Partition[fl_PartionNo].count = Fee_SectorSearch.count;
      fl_CurrentSectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
	    Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress + FEE_SECTOR_HEADER_SIZE; //vbalakr3
#if (STD_ON == FEE_USE_BLANKCHECK)
		Fee_Job.PartitionState = FEE_PARTITION_STATE_BLANK_CHECK_NEXTFREEADDRESS;
#else
	    Fee_Job.PartitionState = FEE_PARTITION_STATE_BLOCK_READ_HEADER;
#endif
      Fee_Job.RepeatStateMachine = TRUE;
    }
  }
}

/**************************************************************************
Function name   : void Fee_PartitionSectorHeaderWrite(void)
Arguments       : void
Return type     : void
Description     : Request Header Write
**************************************************************************/
static void Fee_PartitionSectorHeaderWrite(void)
{
  uint32 fl_SectorStartAddress;
  uint8 fl_PartionNo;
  Std_ReturnType fl_RequestStatus;
  uint8 fl_CurrentSectorId;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_CurrentSectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
  
  Fee_SectorHeader.SectorId = fl_CurrentSectorId;
  Fee_SectorHeader.count = Fee_Partition[fl_PartionNo].count;
  Fee_SectorHeader.Reserved1 = 0xFFFFU;
  Fee_SectorHeader.Reserved2 = 0xFFFFU;
  Fee_SectorHeader.Reserved3 = 0xFFFFU;
  
  fl_SectorStartAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress;
  fl_RequestStatus = FLS_WRITE(fl_SectorStartAddress,(uint8 *)&Fee_SectorHeader.SectorId,FEE_SECTOR_HEADER_SIZE);
  if(fl_RequestStatus == E_OK)
  {
    Fee_Partition[fl_PartionNo].NextFreeAddress = fl_SectorStartAddress + FEE_SECTOR_HEADER_SIZE;
    Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_HEADER_WRITE_WAIT;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else
  {
    Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_ERROR;
    Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
    Fee_Job.RepeatStateMachine = TRUE;
  }
}

/**************************************************************************
Function name   : void Fee_PartitionSectorHeaderWriteWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result 
**************************************************************************/
static void Fee_PartitionSectorHeaderWriteWait(void)
{
  uint8 fl_PartionNo;
  MemIf_JobResultType fl_FlsJobStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
      Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_FOOTER_WRITE;
      Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
      Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_ERROR;
      Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
      Fee_Job.RepeatStateMachine = TRUE;
    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_PartitionSectorFooterWrite(void)
Arguments       : void
Return type     : void
Description     : Request Footer Write
**************************************************************************/
static void Fee_PartitionSectorFooterWrite(void)
{
  uint32 fl_FooterStartAddress;
  uint8 fl_PartionNo;
  Std_ReturnType fl_RequestStatus;
  uint8 fl_CurrentSectorId;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_CurrentSectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
  
  
  Fee_SectorFooter.SectorId = (uint8)~fl_CurrentSectorId;
  Fee_SectorFooter.count = (uint8)~Fee_Partition[fl_PartionNo].count;
  Fee_SectorFooter.Reserved1 = 0U;
  Fee_SectorFooter.Reserved2 = 0U;
  Fee_SectorFooter.Reserved3 = 0U;
 
    fl_FooterStartAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress + \
						    Fee_SectorConfig[fl_CurrentSectorId].SectorSize - FEE_SECTOR_FOOTER_SIZE;
  
  fl_RequestStatus = FLS_WRITE(fl_FooterStartAddress,(uint8 *)&Fee_SectorFooter.SectorId,FEE_SECTOR_FOOTER_SIZE);
  if(fl_RequestStatus == E_OK)
  {
    Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_FOOTER_WRITE_WAIT;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else
  {
    Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_ERROR;
    Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
    Fee_Job.RepeatStateMachine = TRUE;
  }
}

/**************************************************************************
Function name   : void Fee_PartitionSectorFooterWriteWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result. 
**************************************************************************/
static void Fee_PartitionSectorFooterWriteWait(void)
{
  uint8 fl_PartionNo;
  MemIf_JobResultType fl_FlsJobStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
      Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_READY;
      Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
      Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
      Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_ERROR;
      Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
      Fee_Job.RepeatStateMachine = TRUE;
    }
	if (FALSE != Fee_Job.CancelFlag)
	{
		Fee_Job.JobResult = MEMIF_JOB_CANCELED;
		Fee_Job.JobState = FEE_JOB_STATE_IDLE;
		Fee_Job.JobActiveId = FEE_JOB_IDLE;
		Fee_Job.CancelFlag = FALSE;
		FEE_NVM_JOB_ERROR_NOTIFICATION();
		Fee_Job.RepeatStateMachine = FALSE;
	}
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}
#if (STD_ON == FEE_USE_BLANKCHECK)
/**************************************************************************
Function name   : void Fee_PartitionBlankCheckNextFreeAddress(void)
Arguments       : void
Return type     : void
Description     : Request Blank Check in Next Free Adress
**************************************************************************/
static void Fee_PartitionBlankCheckNextFreeAddress(void)
{
	uint8 fl_PartionNo;
	Std_ReturnType fl_RequestStatus;
	uint8 fl_CurrentSectorId;
	fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
	fl_RequestStatus = FLS_BLANKCHECK(Fee_Partition[fl_PartionNo].NextFreeAddress, FEE_BLANKCHECK_LENGTH);
	if(fl_RequestStatus == E_OK)
	{
		Fee_Job.PartitionState = FEE_PARTITION_STATE_BLANK_CHECK_NEXTFREEADDRESS_WAIT;
		Fee_Job.RepeatStateMachine = FALSE;
	}
	else
	{
		fl_CurrentSectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
		Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress + \
														Fee_SectorConfig[fl_CurrentSectorId].SectorSize - FEE_SECTOR_FOOTER_SIZE - 1U;
		Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE ;
		Fee_Job.RepeatStateMachine = TRUE;
	}
}

/**************************************************************************
Function name   : void Fee_PartitionBlankCheckNextFreeAddressWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result 
**************************************************************************/
static void Fee_PartitionBlankCheckNextFreeAddressWait(void)
{
  uint8 fl_PartionNo;
  // uint8 fl_CurrentSectorId;
  MemIf_JobResultType fl_FlsJobStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
	if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
	{
		if(fl_FlsJobStatus == MEMIF_JOB_OK)
		{
			Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE ;
			Fee_Job.RepeatStateMachine = TRUE;
		}
		else
		{
			Fee_Job.PartitionState = FEE_PARTITION_STATE_BLOCK_READ_HEADER;
			Fee_Job.RepeatStateMachine = TRUE;
		}
	}
	else
	{
		/* Wait for Next State Machine */
		Fee_Job.RepeatStateMachine = FALSE;
	}
}
#endif 
/**************************************************************************
Function name   : void Fee_PartitionBlockReadHeader(void)
Arguments       : void
Return type     : void
Description     : Request Block Read
**************************************************************************/
static void Fee_PartitionBlockReadHeader(void)
{
	uint8 fl_PartionNo;
	Std_ReturnType fl_RequestStatus;
	uint8 fl_CurrentSectorId;
	fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
	fl_RequestStatus = FLS_READ(Fee_Partition[fl_PartionNo].NextFreeAddress, (uint8 *)&Fee_BlockHeader[0].BlockId, (FEE_HEADER_SIZE << 1));
	if(fl_RequestStatus == E_OK)
	{
		Fee_Job.PartitionState = FEE_PARTITION_STATE_BLOCK_READ_HEADER_WAIT;
		Fee_Job.RepeatStateMachine = FALSE;
	}
	else
	{
		fl_CurrentSectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
		Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress + \
														Fee_SectorConfig[fl_CurrentSectorId].SectorSize - FEE_SECTOR_FOOTER_SIZE - 1U;
		Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE ;
		Fee_Job.RepeatStateMachine = TRUE;
	}
}

/**************************************************************************
Function name   : void Fee_PartitionBlockReadHeaderWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result 
**************************************************************************/
static void Fee_PartitionBlockReadHeaderWait(void)
{
  uint8 fl_PartionNo;
  uint8 fl_CurrentSectorId;
  MemIf_JobResultType fl_FlsJobStatus;
  fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
      Fee_Job.PartitionState = FEE_PARTITION_STATE_BLOCK_READ_HEADER_VALIDATE;
      Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
		fl_CurrentSectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
		Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress + \
													   Fee_SectorConfig[fl_CurrentSectorId].SectorSize - FEE_SECTOR_FOOTER_SIZE - 1U;
    Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE ;
    Fee_Job.RepeatStateMachine = TRUE;

    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_PartitionBlockValidate(void)
Arguments       : void
Return type     : void
Description     : Validate Block
**************************************************************************/
static void Fee_PartitionBlockValidate(void)
{
	uint16 fl_BlockId;
	uint8 fl_PartionNo;
	uint8 fl_CurrentSectorId;
	Fee_BlockStatusType fl_BlockValid;
	fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
	fl_BlockId = Fee_BlockHeader[0].BlockId;
	if(fl_BlockId != 0xFFFFU)
	{
		fl_BlockValid = Fee_HeaderValidate();
		if(fl_BlockValid == FEE_BLOCK_EXIST && fl_BlockId < FEE_NUM_BLOCKS)
		{
			Fee_BlockInformation[fl_BlockId].LatestAddress = Fee_Partition[fl_PartionNo].NextFreeAddress;
			Fee_Partition[fl_PartionNo].NextFreeAddress =  Fee_Partition[fl_PartionNo].NextFreeAddress + Fee_BlockConfig[fl_BlockId].BlockSize + (FEE_HEADER_SIZE << 1);
#if (STD_ON == FEE_USE_BLANKCHECK)
			Fee_Job.PartitionState = FEE_PARTITION_STATE_BLANK_CHECK_NEXTFREEADDRESS;
#else
		    Fee_Job.PartitionState = FEE_PARTITION_STATE_BLOCK_READ_HEADER;
#endif
			Fee_Job.RepeatStateMachine = TRUE;

		}
		else if ((fl_BlockValid == FEE_BLOCK_CANCELLED || fl_BlockValid == FEE_BLOCK_INVALIDATED) && fl_BlockId < FEE_NUM_BLOCKS)
		{
			Fee_Partition[fl_PartionNo].NextFreeAddress =  Fee_Partition[fl_PartionNo].NextFreeAddress + Fee_BlockConfig[fl_BlockId].BlockSize + (FEE_HEADER_SIZE << 1);
#if (STD_ON == FEE_USE_BLANKCHECK)
			Fee_Job.PartitionState = FEE_PARTITION_STATE_BLANK_CHECK_NEXTFREEADDRESS;
#else
		    Fee_Job.PartitionState = FEE_PARTITION_STATE_BLOCK_READ_HEADER;
#endif
			Fee_Job.RepeatStateMachine = TRUE;
		}
		else
		{
			fl_CurrentSectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
			Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress + \
									Fee_SectorConfig[fl_CurrentSectorId].SectorSize - FEE_SECTOR_FOOTER_SIZE - 1U;
			Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE ;
			Fee_Job.RepeatStateMachine = TRUE;
		}
	}
	else
	{
		Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
		Fee_Job.RepeatStateMachine = TRUE;
	}
}

/**************************************************************************
Function name   : void Fee_PartitionStateProcess(void)
Arguments       : void
Return type     : void
Description     : Partition initialisation State machine
**************************************************************************/
static void Fee_PartitionStateProcess(void)
{
  if(Fee_Job.SectorEraseState == FEE_SECTOR_ERASE_STATE_IDLE)
  {
    switch(Fee_Job.PartitionState)
    {
      case FEE_PARTITION_STATE_IDLE:
      break;
    
      case FEE_PARTITION_STATE_SECTOR_HEADER_READ:
        Fee_PartitionSectorHeaderRead();
      break;
  
      case FEE_PARTITION_STATE_SECTOR_HEADER_READ_WAIT:
        Fee_PartitionSectorHeaderReadWait();
      break;
  
      case FEE_PARTITION_STATE_SECTOR_FOOTER_READ:
        Fee_PartitionSectorFooterRead();
      break;
  
      case FEE_PARTITION_STATE_WAIT_SECTOR_FOOTER_READ:
        Fee_PartitionSectorFooterReadWait();
      break;
  
      case FEE_PARTITION_STATE_VALIDATE_SECTOR:
        Fee_ValidateSector();
      break;
    
      case FEE_PARTITION_STATE_SECTOR_HEADER_WRITE:
        Fee_PartitionSectorHeaderWrite();
      break;
    
      case FEE_PARTITION_STATE_SECTOR_HEADER_WRITE_WAIT:
        Fee_PartitionSectorHeaderWriteWait();
      break;
    
      case FEE_PARTITION_STATE_SECTOR_FOOTER_WRITE:
        Fee_PartitionSectorFooterWrite();
      break;

      case FEE_PARTITION_STATE_SECTOR_FOOTER_WRITE_WAIT:
        Fee_PartitionSectorFooterWriteWait();
      break;
    
      case FEE_PARTITION_STATE_BLOCK_READ_HEADER:
        Fee_PartitionBlockReadHeader();
      break;
    
      case FEE_PARTITION_STATE_BLOCK_READ_HEADER_WAIT:
        Fee_PartitionBlockReadHeaderWait();
      break;
    
      case FEE_PARTITION_STATE_BLOCK_READ_HEADER_VALIDATE:
        Fee_PartitionBlockValidate();
      break;

#if (STD_ON == FEE_USE_BLANKCHECK)
		case FEE_PARTITION_STATE_BLANK_CHECK_NEXTFREEADDRESS:
			Fee_PartitionBlankCheckNextFreeAddress();
		break;

		case FEE_PARTITION_STATE_BLANK_CHECK_NEXTFREEADDRESS_WAIT:
			Fee_PartitionBlankCheckNextFreeAddressWait();
		break;
#endif

		default:
		//do nothing
		break;
    	}
  	}
}

/**************************************************************************
Function name   : void Fee_SectorErase(void)
Arguments       : void
Return type     : void
Description     : Request Sector Erase
**************************************************************************/
static void Fee_SectorErase(void)
{
	if (FALSE == Fee_Job.ProcessInternalJob)
	{
		Fee_Job.JobActiveId = FEE_JOB_IDLE;
		Fee_Job.ResumeSectorEraseState = FEE_SECTOR_ERASE_STATE_ERASE;
		Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_SUSPENDED;
		Fee_NotifyInternalJobStatus(FEE_SUSPEND_INTERNAL_JOB);
	#ifdef MEM_TESTING_ENABLED
		FEE_JOB_HOOK(FEE_SUSPEND_INTERNAL_JOB,Fee_Job.CurPartition);
	#endif
		Fee_Job.RepeatStateMachine = FALSE;
	}
	else
	{
		uint32 fl_EraseAddress;
		uint16 fl_EraseSize;
		uint8 fl_PartionNo;
		Std_ReturnType fl_RequestStatus;
		uint8 fl_EraseSectorId;
		fl_PartionNo = Fee_Job.CurPartition;
		fl_EraseSectorId = Fee_Partition[fl_PartionNo].EraseSectorId;
		fl_EraseAddress = Fee_SectorConfig[fl_EraseSectorId].SectorStartAddress;
		fl_EraseSize = Fee_SectorConfig[fl_EraseSectorId].SectorSize;
		
		fl_RequestStatus = FLS_ERASE(fl_EraseAddress,fl_EraseSize);
		if(fl_RequestStatus == E_OK)
		{
			Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_ERASE_WAIT;
			Fee_Job.RepeatStateMachine = TRUE;
		}
		else
		{
			/* Erase Not Success */
			Fee_Job.JobResult = MEMIF_JOB_FAILED;
    		if (FEE_JOB_STATE_WRITE_HEADER1 == Fee_Job.JobState)
				FEE_NVM_JOB_ERROR_NOTIFICATION();
			Fee_Job.JobActiveId = FEE_JOB_IDLE;
			Fee_Job.JobState = FEE_JOB_STATE_IDLE;
			Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
			Fee_Job.RepeatStateMachine = FALSE;
      		Fee_NotifyInternalJobStatus(FEE_END_INTERNAL_JOB);
#ifdef MEM_TESTING_ENABLED
	  		FEE_JOB_HOOK(FEE_END_INTERNAL_JOB,Fee_Job.CurPartition);
#endif
		}
	}
}

/**************************************************************************
Function name   : void Fee_SectorEraseWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result 
**************************************************************************/
static void Fee_SectorEraseWait(void)
{
  MemIf_JobResultType fl_FlsJobStatus;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus != MEMIF_JOB_OK)
    {
	  /* Erase Not Success */
		Fee_Job.JobResult = MEMIF_JOB_FAILED;
		if (FEE_JOB_STATE_WRITE_HEADER1 == Fee_Job.JobState)
			FEE_NVM_JOB_ERROR_NOTIFICATION();
		Fee_Job.JobActiveId = FEE_JOB_IDLE;
		Fee_Job.JobState = FEE_JOB_STATE_IDLE;
    }
    if (FEE_JOB_STATE_WRITE_HEADER1 == Fee_Job.JobState)
    {
      Fee_Job.JobActiveId = FEE_JOB_WRITE;
      Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
      Fee_Job.JobActiveId = FEE_JOB_IDLE;
      Fee_Job.RepeatStateMachine = FALSE;
    }
	  Fee_NotifyInternalJobStatus(FEE_END_INTERNAL_JOB);
#ifdef MEM_TESTING_ENABLED
	  FEE_JOB_HOOK(FEE_END_INTERNAL_JOB,Fee_Job.CurPartition);
#endif
	  Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_SecotorEraseProcessDeferredErase(void)
Arguments       : void
Return type     : void
Description     : Process if any pending Sector Erase
**************************************************************************/
static void Fee_SecotorEraseProcessDeferredErase(void)
{
  uint8 fl_PartionNo;
  uint8 fl_SectorTraverse;
  uint8 TotalSectors;
  fl_PartionNo = Fee_Job.CurPartition;
  if(Fee_PartitionPendingSectorErase[fl_PartionNo].NumberOfSectorsToErase > 0)
  {
    TotalSectors = FEE_NUM_OF_SECTORS;
    for(fl_SectorTraverse = 0; fl_SectorTraverse < TotalSectors; fl_SectorTraverse ++)
    {
        if(FALSE != Fee_PartitionPendingSectorErase[fl_PartionNo].SectorEraseFlag[fl_SectorTraverse])
        {
            Fee_Partition[fl_PartionNo].EraseSectorId = fl_SectorTraverse;
            Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_ERASE;
            Fee_PartitionPendingSectorErase[fl_PartionNo].SectorEraseFlag[fl_SectorTraverse] = FALSE;
            Fee_PartitionPendingSectorErase[fl_PartionNo].NumberOfSectorsToErase--;
            Fee_Job.RepeatStateMachine = TRUE;
            break;
        }
    }
  }
  else
  {
    Fee_PartitionPendingSectorErase[fl_PartionNo].SectorEraseEnable = FALSE;
    Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
    if (FEE_JOB_STATE_WRITE_HEADER1 == Fee_Job.JobState)
    {
      Fee_Job.JobActiveId = FEE_JOB_WRITE;
      Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
      Fee_Job.JobActiveId = FEE_JOB_IDLE;
      Fee_Job.RepeatStateMachine = FALSE;
    }
      Fee_NotifyInternalJobStatus(FEE_END_INTERNAL_JOB);
#ifdef MEM_TESTING_ENABLED
	  FEE_JOB_HOOK(FEE_END_INTERNAL_JOB,Fee_Job.CurPartition);
#endif
  }
}

/**************************************************************************
Function name   : void Fee_SectorEraseStateProcess(void)
Arguments       : void
Return type     : void
Description     : Sector Erase State machine 
**************************************************************************/
static void Fee_SectorEraseStateProcess(void)
{
  switch(Fee_Job.SectorEraseState)
  {
    case FEE_SECTOR_ERASE_STATE_IDLE:
    break;
    
    case FEE_SECTOR_ERASE_STATE_ERASE:
      	Fee_SectorErase();
    break;
  
    case FEE_SECTOR_ERASE_STATE_ERASE_WAIT:
      Fee_SectorEraseWait();
    break;

    case FEE_SECTOR_ERASE_STATE_PROCESS_DEFERRED_ERASE:
      Fee_SecotorEraseProcessDeferredErase();
    break;
	case FEE_SECTOR_ERASE_STATE_SUSPENDED:
		if (FALSE != Fee_Job.ProcessInternalJob)
		{
			Fee_Job.JobActiveId = FEE_JOB_INTERNAL_BUSY;
			Fee_Job.SectorEraseState = Fee_Job.ResumeSectorEraseState;
			Fee_Job.ResumeSectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
			Fee_NotifyInternalJobStatus(FEE_RESUME_INTERNAL_JOB);
		#ifdef MEM_TESTING_ENABLED
			FEE_JOB_HOOK(FEE_RESUME_INTERNAL_JOB,Fee_Job.CurPartition);
		#endif
		}
	break;
    
    default:
    //do nothing
    break;
  }
}

#if FEE_BACKGROUND_SECTORSWITCH == STD_ON
/**************************************************************************
Function name   : void Fee_BackgroundSectorSwitch(void)
Arguments       : void
Return type     : void
Description     : Service To Invoke Background Sector Switch
**************************************************************************/
static void Fee_BackgroundSectorSwitch(void)
{
  uint8 fl_partition;
  if(Fee_Job.JobActiveId == FEE_JOB_IDLE && FALSE != Fee_Job.ProcessInternalJob) 
  {
    if (FEE_TIMER_WAIT_TIME > Fee_Job.InternalJobTimer)
    {
      Fee_Job.InternalJobTimer += 1;
    }
    else
    {
      for (fl_partition = 0; fl_partition < FEE_NUM_PARTITIONS; fl_partition++)
      {
        if (FALSE != Fee_PartitionConfig[fl_partition].BackgroundSectorSwitch)
        {
          if (Fee_SectorSwitchRequired(fl_partition, Fee_PartitionConfig[fl_partition].MaxLength) == E_OK)
          {
            if(FALSE != Fee_PartitionPendingSectorErase[fl_partition].SectorEraseEnable)
            {
              Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_PROCESS_DEFERRED_ERASE;
            }
            else
            {
              Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_HEADER_WRITE;
            }
              Fee_Job.JobActiveId = FEE_JOB_INTERNAL_BUSY;
              Fee_Job.CurPartition = fl_partition;
              Fee_Job.RepeatStateMachine = TRUE;
              Fee_NotifyInternalJobStatus(FEE_START_INTERNAL_JOB);
            #ifdef MEM_TESTING_ENABLED
              FEE_JOB_HOOK(FEE_START_INTERNAL_JOB,Fee_Job.CurPartition);
            #endif
              break;
          }
        }
      }
    }
  }
}
#endif

/**************************************************************************
Function name   : void Fee_SectorSwitchHeaderWrite(void)
Arguments       : void
Return type     : void
Description     : Request Sector Header Write
**************************************************************************/
static void Fee_SectorSwitchHeaderWrite(void)
{
  uint32 fl_SectorWriteAddress;
  uint8 fl_PartionNo;
  uint8 fl_StartSectorId;
  uint8 fl_CurrentSectorId;
  uint8 fl_PartitionCurrentSectorId;
  Std_ReturnType fl_RequestStatus;
  
  fl_PartionNo = Fee_Job.CurPartition;
  Fee_Partition[fl_PartionNo].OldSectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
  
  Fee_Partition[fl_PartionNo].count = Fee_Partition[fl_PartionNo].count + 1U;
  Fee_Partition[fl_PartionNo].CurrentSectorId = Fee_Partition[fl_PartionNo].CurrentSectorId +1U;
  
  fl_StartSectorId = Fee_PartitionConfig[fl_PartionNo].StartingSectorId;
  fl_CurrentSectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
  
  fl_PartitionCurrentSectorId = fl_CurrentSectorId - fl_StartSectorId;
  if(Fee_PartitionConfig[fl_PartionNo].NumberOfSectors <= fl_PartitionCurrentSectorId)
  {
    Fee_Partition[fl_PartionNo].CurrentSectorId = fl_StartSectorId;
               fl_CurrentSectorId = fl_StartSectorId;
  }
  Fee_SectorHeader.SectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
  Fee_SectorHeader.count = Fee_Partition[fl_PartionNo].count;
  Fee_SectorHeader.Reserved1 = 0xFFFFU;
  Fee_SectorHeader.Reserved2 = 0xFFFFU;
  Fee_SectorHeader.Reserved3 = 0xFFFFU;
  
  fl_SectorWriteAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress;
  fl_RequestStatus = FLS_WRITE(fl_SectorWriteAddress,(uint8 *)&Fee_SectorHeader.SectorId,FEE_SECTOR_HEADER_SIZE);
  if(fl_RequestStatus == E_OK)
  {
    Fee_Partition[fl_PartionNo].NextFreeAddress = fl_SectorWriteAddress + FEE_SECTOR_HEADER_SIZE;
    Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_HEADER_WRITE_WAIT;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else
  {
    Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_IDLE;
    Fee_Job.JobResult = MEMIF_JOB_FAILED;
    if (FEE_JOB_STATE_WRITE_HEADER1 == Fee_Job.JobState)
		FEE_NVM_JOB_ERROR_NOTIFICATION();
    Fee_Job.JobActiveId = FEE_JOB_IDLE;
    Fee_Job.JobState = FEE_JOB_STATE_IDLE;
    Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
    Fee_Job.RepeatStateMachine = FALSE;
    Fee_NotifyInternalJobStatus(FEE_END_INTERNAL_JOB);
#ifdef MEM_TESTING_ENABLED
	  FEE_JOB_HOOK(FEE_END_INTERNAL_JOB,Fee_Job.CurPartition);
#endif
  }
}


/**************************************************************************
Function name   : void Fee_SectorSwitchHeaderWriteWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result 
**************************************************************************/
static void Fee_SectorSwitchHeaderWriteWait(void)
{
  uint8 fl_PartionNo;
  MemIf_JobResultType fl_FlsJobStatus;
  fl_PartionNo = Fee_Job.CurPartition;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
      Fee_Job.SearchBlockId = 1;
      if(Fee_BlockConfig[Fee_Job.SearchBlockId].PartitionNo == fl_PartionNo)
      {
		if (FALSE == Fee_Job.ProcessInternalJob)
		{
			Fee_Job.JobActiveId = FEE_JOB_IDLE;
			Fee_Job.ResumeSectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_READ;
        	Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_SUSPENDED;
			Fee_NotifyInternalJobStatus(FEE_SUSPEND_INTERNAL_JOB);
		#ifdef MEM_TESTING_ENABLED
			FEE_JOB_HOOK(FEE_SUSPEND_INTERNAL_JOB,Fee_Job.CurPartition);
		#endif
			Fee_Job.RepeatStateMachine = FALSE;
		}
		else
		{
        	Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_READ;
        	Fee_Job.RepeatStateMachine = TRUE;
		}
      }
      else
      {
		if (FALSE == Fee_Job.ProcessInternalJob)
		{
			Fee_Job.JobActiveId = FEE_JOB_IDLE;
			Fee_Job.ResumeSectorSwitchState = FEE_SECTOR_SWITCH_STATE_SEARCH_NEXT_BLOCK;
        	Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_SUSPENDED;
			Fee_NotifyInternalJobStatus(FEE_SUSPEND_INTERNAL_JOB);
		#ifdef MEM_TESTING_ENABLED
			FEE_JOB_HOOK(FEE_SUSPEND_INTERNAL_JOB,Fee_Job.CurPartition);
		#endif
			Fee_Job.RepeatStateMachine = FALSE;
		}
		else
		{
        	Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_SEARCH_NEXT_BLOCK;
        	Fee_Job.RepeatStateMachine = TRUE;
		}
      }
    }
    else
    {
		Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_IDLE;
		Fee_Job.JobResult = MEMIF_JOB_FAILED;
		if (FEE_JOB_STATE_WRITE_HEADER1 == Fee_Job.JobState)
			FEE_NVM_JOB_ERROR_NOTIFICATION();
		Fee_Job.JobActiveId = FEE_JOB_IDLE;
		Fee_Job.JobState = FEE_JOB_STATE_IDLE;
		Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
		Fee_Job.RepeatStateMachine = FALSE;
    Fee_NotifyInternalJobStatus(FEE_END_INTERNAL_JOB);
#ifdef MEM_TESTING_ENABLED
	  FEE_JOB_HOOK(FEE_END_INTERNAL_JOB,Fee_Job.CurPartition);
#endif
    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_SectorSwitchSearchNextBlock(void)
Arguments       : void
Return type     : void
Description     : Search Next Block
**************************************************************************/
static void Fee_SectorSwitchSearchNextBlock(void)
{
  uint8 fl_PartionNo;
  fl_PartionNo = Fee_Job.CurPartition;
  Fee_Job.SearchBlockId = Fee_Job.SearchBlockId + 1U;
  if(Fee_Job.SearchBlockId >= FEE_NUM_BLOCKS)
  {
    Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_SECTOR_FOOTER_WRITE;
    Fee_Job.RepeatStateMachine = TRUE;
  }
  else
  {
    if(Fee_BlockConfig[Fee_Job.SearchBlockId].PartitionNo == fl_PartionNo)
    {
      Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_READ;
      Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
      Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_SEARCH_NEXT_BLOCK;
      Fee_Job.RepeatStateMachine = TRUE;
    }
  }
}

/**************************************************************************
Function name   : void Fee_SectorSwitchBlockRead(void)
Arguments       : void
Return type     : void
Description     : Request Block Read
**************************************************************************/
static void Fee_SectorSwitchBlockRead(void)
{
  Std_ReturnType fl_RequestStatus;
  if(Fee_BlockInformation[Fee_Job.SearchBlockId].LatestAddress != 0U)
  {
    fl_RequestStatus = FLS_READ(Fee_BlockInformation[Fee_Job.SearchBlockId].LatestAddress, (uint8 *)&Fee_SectorSwitchBlockBuffer.Header.BlockId, (Fee_BlockConfig[Fee_Job.SearchBlockId].BlockSize + (FEE_HEADER_SIZE << 1)));
    if(fl_RequestStatus == E_OK)
    {
      Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_READ_WAIT;
      Fee_Job.RepeatStateMachine = FALSE;
    }
    else
    {
		Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_IDLE;
		Fee_Job.JobResult = MEMIF_JOB_FAILED;
        if (FEE_JOB_STATE_WRITE_HEADER1 == Fee_Job.JobState)
			FEE_NVM_JOB_ERROR_NOTIFICATION();
		Fee_Job.JobActiveId = FEE_JOB_IDLE;
		Fee_Job.JobState = FEE_JOB_STATE_IDLE;
		Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
		Fee_Job.RepeatStateMachine = FALSE;
    Fee_NotifyInternalJobStatus(FEE_END_INTERNAL_JOB);
#ifdef MEM_TESTING_ENABLED
	  FEE_JOB_HOOK(FEE_END_INTERNAL_JOB,Fee_Job.CurPartition);
#endif
    }
  }
  else
  {
      Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_SEARCH_NEXT_BLOCK;
      Fee_Job.RepeatStateMachine = TRUE;
  }
}

/**************************************************************************
Function name   : void Fee_SectorSwitchBlockReadWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result
**************************************************************************/
static void Fee_SectorSwitchBlockReadWait(void)
{
  MemIf_JobResultType fl_FlsJobStatus;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
      Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_READ_VALIDATE;
      Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
		Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_IDLE;
		Fee_Job.JobResult = MEMIF_JOB_FAILED;
		if (FEE_JOB_STATE_WRITE_HEADER1 == Fee_Job.JobState)
			FEE_NVM_JOB_ERROR_NOTIFICATION();
		Fee_Job.JobActiveId = FEE_JOB_IDLE;
		Fee_Job.JobState = FEE_JOB_STATE_IDLE;
		Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
		Fee_Job.RepeatStateMachine = FALSE;
    Fee_NotifyInternalJobStatus(FEE_END_INTERNAL_JOB);
#ifdef MEM_TESTING_ENABLED
	  FEE_JOB_HOOK(FEE_END_INTERNAL_JOB,Fee_Job.CurPartition);
#endif
    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_SectorSwitchBlockReadValidate(void)
Arguments       : void
Return type     : void
Description     : Service to validate the header of the block
**************************************************************************/
void Fee_SectorSwitchBlockReadValidate(void)
{
	Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_SEARCH_NEXT_BLOCK;
	if
	(
		(Fee_SectorSwitchBlockBuffer.Header.BlockId != 0xFFFFU) &&\
		(Fee_SectorSwitchBlockBuffer.Header.BlockId == (uint16)~ Fee_SectorSwitchBlockBuffer.Footer.BlockId) &&\
		(Fee_SectorSwitchBlockBuffer.Header.PayloadLength == (uint16)~ Fee_SectorSwitchBlockBuffer.Footer.PayloadLength) &&\
		(Fee_SectorSwitchBlockBuffer.Header.ValidityFlag != FEE_BLOCK_VALIDITY_FLAG_INVALID)&&\
		(Fee_SectorSwitchBlockBuffer.Footer.ValidityFlag != FEE_BLOCK_VALIDITY_FLAG_INVALID)
	)
	{
		Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_WRITE;
	}
}
/**************************************************************************
Function name   : void Fee_SectorSwitchBlockWrite(void)
Arguments       : void
Return type     : void
Description     : Request Block Write
**************************************************************************/
static void Fee_SectorSwitchBlockWrite(void)
{
  uint8 fl_PartionNo;
  Std_ReturnType fl_RequestStatus;
  fl_PartionNo = Fee_Job.CurPartition;
  fl_RequestStatus = FLS_WRITE(Fee_Partition[fl_PartionNo].NextFreeAddress, (uint8 *)&Fee_SectorSwitchBlockBuffer.Header.BlockId, (Fee_SectorSwitchBlockBuffer.Header.PayloadLength + (FEE_HEADER_SIZE << 1)));
  if(fl_RequestStatus == E_OK)
  {
    Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_Partition[fl_PartionNo].NextFreeAddress + Fee_BlockConfig[Fee_Job.SearchBlockId].BlockSize + (FEE_HEADER_SIZE << 1);
    Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_WRITE_WAIT;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else
  {
		Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_IDLE;
		Fee_Job.JobResult = MEMIF_JOB_FAILED;
		if (FEE_JOB_STATE_WRITE_HEADER1 == Fee_Job.JobState)
			FEE_NVM_JOB_ERROR_NOTIFICATION();
		Fee_Job.JobActiveId = FEE_JOB_IDLE;
		Fee_Job.JobState = FEE_JOB_STATE_IDLE;
		Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
		Fee_Job.RepeatStateMachine = FALSE;
    Fee_NotifyInternalJobStatus(FEE_END_INTERNAL_JOB);
#ifdef MEM_TESTING_ENABLED
	  FEE_JOB_HOOK(FEE_END_INTERNAL_JOB,Fee_Job.CurPartition);
#endif
  }
}

/**************************************************************************
Function name   : void Fee_SectorSwitchBlockWriteWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result
**************************************************************************/
static void Fee_SectorSwitchBlockWriteWait(void)
{
  uint8 fl_PartionNo;
  MemIf_JobResultType fl_FlsJobStatus;
  fl_PartionNo = Fee_Job.CurPartition;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
		Fee_BlockInformation[Fee_Job.SearchBlockId].LatestAddress = Fee_Partition[fl_PartionNo].NextFreeAddress - Fee_BlockConfig[Fee_Job.SearchBlockId].BlockSize - (FEE_HEADER_SIZE << 1);
		if (FALSE == Fee_Job.ProcessInternalJob)
		{
			Fee_Job.JobActiveId = FEE_JOB_IDLE;
			Fee_Job.ResumeSectorSwitchState = FEE_SECTOR_SWITCH_STATE_SEARCH_NEXT_BLOCK;
			Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_SUSPENDED;
			Fee_NotifyInternalJobStatus(FEE_SUSPEND_INTERNAL_JOB);
		#ifdef MEM_TESTING_ENABLED
			FEE_JOB_HOOK(FEE_SUSPEND_INTERNAL_JOB,Fee_Job.CurPartition);
		#endif
			Fee_Job.RepeatStateMachine = FALSE;
		}
		else
		{
			Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_SEARCH_NEXT_BLOCK;
			Fee_Job.RepeatStateMachine = TRUE;
		}
    }
    else
    {
		Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_IDLE;
		Fee_Job.JobResult = MEMIF_JOB_FAILED;
		if (FEE_JOB_STATE_WRITE_HEADER1 == Fee_Job.JobState)
			FEE_NVM_JOB_ERROR_NOTIFICATION();
		Fee_Job.JobActiveId = FEE_JOB_IDLE;
		Fee_Job.JobState = FEE_JOB_STATE_IDLE;
		Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
		Fee_Job.RepeatStateMachine = FALSE;
    Fee_NotifyInternalJobStatus(FEE_END_INTERNAL_JOB);
#ifdef MEM_TESTING_ENABLED
	  FEE_JOB_HOOK(FEE_END_INTERNAL_JOB,Fee_Job.CurPartition);
#endif
    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_SectorSwitchSectorFooterWrite(void)
Arguments       : void
Return type     : void
Description     : Request Sector Footer Write
**************************************************************************/
static void Fee_SectorSwitchSectorFooterWrite(void)
{
  uint32 fl_SectorWriteAddress;
  uint8 fl_PartionNo;
  Std_ReturnType fl_RequestStatus;
  uint8 fl_CurrentSectorId;
  fl_PartionNo = Fee_Job.CurPartition;
  ////fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
  fl_CurrentSectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
  
  
  
  Fee_SectorFooter.SectorId = (uint8)~Fee_Partition[fl_PartionNo].CurrentSectorId;
  Fee_SectorFooter.count = (uint8)~Fee_Partition[fl_PartionNo].count;
  Fee_SectorFooter.Reserved1 = 0U;
  Fee_SectorFooter.Reserved2 = 0U;
  Fee_SectorFooter.Reserved3 = 0U;
  
  fl_SectorWriteAddress= Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress + \
						 Fee_SectorConfig[fl_CurrentSectorId].SectorSize - FEE_SECTOR_FOOTER_SIZE;
  
  
  fl_RequestStatus = FLS_WRITE(fl_SectorWriteAddress, (uint8 *)&Fee_SectorFooter.SectorId, FEE_SECTOR_FOOTER_SIZE);
  if(fl_RequestStatus == E_OK)
  {
    Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_SECTOR_FOOTER_WRITE_WAIT;
    Fee_Job.RepeatStateMachine = FALSE;
  }
  else
	{
		Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_IDLE;
		Fee_Job.JobResult = MEMIF_JOB_FAILED;
		if (FEE_JOB_STATE_WRITE_HEADER1 == Fee_Job.JobState)
			FEE_NVM_JOB_ERROR_NOTIFICATION();
		Fee_Job.JobActiveId = FEE_JOB_IDLE;
		Fee_Job.JobState = FEE_JOB_STATE_IDLE;
		Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
		Fee_Job.RepeatStateMachine = FALSE;
    Fee_NotifyInternalJobStatus(FEE_END_INTERNAL_JOB);
#ifdef MEM_TESTING_ENABLED
	  FEE_JOB_HOOK(FEE_END_INTERNAL_JOB,Fee_Job.CurPartition);
#endif
	}
}

/**************************************************************************
Function name   : void Fee_SectorSwitchSectorFooterWriteWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result
**************************************************************************/
static void Fee_SectorSwitchSectorFooterWriteWait(void)
{
  uint8 fl_PartionNo;
  MemIf_JobResultType fl_FlsJobStatus;
  fl_PartionNo = Fee_Job.CurPartition;
  fl_FlsJobStatus = FLS_GET_JOB_RESULT();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
  {
    if(fl_FlsJobStatus == MEMIF_JOB_OK)
    {
		Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_IDLE;
		Fee_Partition[fl_PartionNo].EraseSectorId = Fee_Partition[fl_PartionNo].OldSectorId;
		Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_ERASE;
		Fee_Job.RepeatStateMachine = TRUE;
	}
    else
    {
      Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_IDLE;
      Fee_Job.JobResult = MEMIF_JOB_FAILED;
      if (FEE_JOB_STATE_WRITE_HEADER1 == Fee_Job.JobState)
        FEE_NVM_JOB_ERROR_NOTIFICATION();
      Fee_Job.JobActiveId = FEE_JOB_IDLE;
      Fee_Job.JobState = FEE_JOB_STATE_IDLE;
      Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
      Fee_Job.RepeatStateMachine = FALSE;
      Fee_NotifyInternalJobStatus(FEE_END_INTERNAL_JOB);
#ifdef MEM_TESTING_ENABLED
	    FEE_JOB_HOOK(FEE_END_INTERNAL_JOB,Fee_Job.CurPartition);
#endif
    }
  }
  else
  {
    /* Wait for Next State Machine */
    Fee_Job.RepeatStateMachine = FALSE;
  }
}

/**************************************************************************
Function name   : void Fee_SectorSwitchStateProcess(void)
Arguments       : void
Return type     : void
Description     : Sector Switch State machine
**************************************************************************/
static void Fee_SectorSwitchStateProcess(void)
{
	if(Fee_Job.SectorEraseState == FEE_SECTOR_ERASE_STATE_IDLE)
	{
		switch(Fee_Job.SectorSwitchState)
		{
			case FEE_SECTOR_SWITCH_STATE_IDLE:
		#if FEE_BACKGROUND_SECTORSWITCH == STD_ON
			Fee_BackgroundSectorSwitch();
		#endif
			break;

			case FEE_SECTOR_SWITCH_STATE_HEADER_WRITE:
			Fee_SectorSwitchHeaderWrite();
			break;

			case FEE_SECTOR_SWITCH_STATE_HEADER_WRITE_WAIT:
			Fee_SectorSwitchHeaderWriteWait();
			break;

			case FEE_SECTOR_SWITCH_STATE_SEARCH_NEXT_BLOCK:
			Fee_SectorSwitchSearchNextBlock();
			break;

			case FEE_SECTOR_SWITCH_STATE_BLOCK_READ:
			Fee_SectorSwitchBlockRead();
			break;

			case FEE_SECTOR_SWITCH_STATE_BLOCK_READ_WAIT:
			Fee_SectorSwitchBlockReadWait();
			break;

			case FEE_SECTOR_SWITCH_STATE_BLOCK_READ_VALIDATE:
			Fee_SectorSwitchBlockReadValidate();
			break;
			case FEE_SECTOR_SWITCH_STATE_BLOCK_WRITE:
			Fee_SectorSwitchBlockWrite();
			break;

			case FEE_SECTOR_SWITCH_STATE_BLOCK_WRITE_WAIT:
			Fee_SectorSwitchBlockWriteWait();
			break;

			case FEE_SECTOR_SWITCH_STATE_SECTOR_FOOTER_WRITE:
			Fee_SectorSwitchSectorFooterWrite();
			break;

			case FEE_SECTOR_SWITCH_STATE_SECTOR_FOOTER_WRITE_WAIT:
			Fee_SectorSwitchSectorFooterWriteWait();
			break;

			case FEE_SECTOR_SWITCH_STATE_SUSPENDED:
		    if (FALSE != Fee_Job.ProcessInternalJob)
			{
				Fee_Job.JobActiveId = FEE_JOB_INTERNAL_BUSY;
				Fee_Job.SectorSwitchState = Fee_Job.ResumeSectorSwitchState;
				Fee_Job.ResumeSectorSwitchState = FEE_SECTOR_SWITCH_STATE_IDLE;
				Fee_NotifyInternalJobStatus(FEE_RESUME_INTERNAL_JOB);
			#ifdef MEM_TESTING_ENABLED
				FEE_JOB_HOOK(FEE_RESUME_INTERNAL_JOB,Fee_Job.CurPartition);
			#endif
			}
			break;

			default:
			//do nothing
			break;
		}
	}
}

/**************************************************************************
Function name   : void Fee_NotifyInternalJobStatus(uint8 State)
Arguments       : uint8
Return type     : void
Description     : Takes the copy of internal data before suspend
**************************************************************************/
static void Fee_NotifyInternalJobStatus(uint8 State)
{
	if(State == FEE_SUSPEND_INTERNAL_JOB)
	{
		/*Copy Internal Data*/
    Fee_JobCpy.RamAddress = Fee_Job.RamAddress;
    Fee_JobCpy.BlockId = Fee_Job.BlockId;
    Fee_JobCpy.Offset = Fee_Job.Offset;
    Fee_JobCpy.Length = Fee_Job.Length;
    Fee_JobCpy.SearchBlockId = Fee_Job.SearchBlockId;
    Fee_JobCpy.DataIndex = Fee_Job.DataIndex;
    Fee_JobCpy.JobActiveId = Fee_Job.JobActiveId;
    Fee_JobCpy.JobState = Fee_Job.JobState;
    Fee_JobCpy.SectorSwitchState = Fee_Job.SectorSwitchState;
    Fee_JobCpy.PartitionState = Fee_Job.PartitionState;
    Fee_JobCpy.SectorEraseState =Fee_Job.SectorEraseState;
    Fee_JobCpy.JobResult = Fee_Job.JobResult;
    Fee_JobCpy.ResumeSectorSwitchState = Fee_Job.ResumeSectorSwitchState;
    Fee_JobCpy.ResumeSectorEraseState = Fee_Job.ResumeSectorEraseState;
    Fee_JobCpy.CurPartition = Fee_Job.CurPartition;
	}

	if (FEE_END_INTERNAL_JOB == State && FALSE == Fee_Job.ProcessInternalJob)
	{
		State = FEE_SUSPEND_INTERNAL_JOB;
	}
	FEE_NVM_INTERNAL_NOTIFICATION(State);
}

/**************************************************************************
Function name   : void Fee_NotifyInternalJobStatus(uint8 State)
Arguments       : uint8
Return type     : void
Description     : restores the coppied internal data before resume
**************************************************************************/

static void Fee_RestoreJobState(void)
{
  Fee_Job.RamAddress = Fee_JobCpy.RamAddress;
  Fee_Job.BlockId = Fee_JobCpy.BlockId;
  Fee_Job.Offset = Fee_JobCpy.Offset;
  Fee_Job.Length = Fee_JobCpy.Length;
  Fee_Job.SearchBlockId = Fee_JobCpy.SearchBlockId;
  Fee_Job.DataIndex = Fee_JobCpy.DataIndex;
  Fee_Job.JobActiveId = Fee_JobCpy.JobActiveId;
  Fee_Job.JobState = Fee_JobCpy.JobState;
  Fee_Job.SectorSwitchState = Fee_JobCpy.SectorSwitchState;
  Fee_Job.PartitionState = Fee_JobCpy.PartitionState;
  Fee_Job.SectorEraseState =Fee_JobCpy.SectorEraseState;
  Fee_Job.JobResult = Fee_JobCpy.JobResult;
  Fee_Job.ResumeSectorSwitchState = Fee_JobCpy.ResumeSectorSwitchState;
  Fee_Job.ResumeSectorEraseState = Fee_JobCpy.ResumeSectorEraseState;
  Fee_Job.CurPartition = Fee_JobCpy.CurPartition;
}


/**************************************************************************
Function name   : void Fee_MainFunction(void)
Arguments       : void
Return type     : void
Description     : Service to handle the requested read / write / erase jobs and the 
                  internal management operations
**************************************************************************/
void Fee_MainFunction(void)
{
  do
  {
    // printf("HELLO_FEE\n");
    Fee_JobStateProcess();
    Fee_PartitionStateProcess();
    Fee_SectorEraseStateProcess();
    Fee_SectorSwitchStateProcess();
  }while(FALSE != Fee_Job.RepeatStateMachine);
}
#define FEE_DATA_SEC_END
#include "MemMap.h"

#define FEE_CODE_SEC_END
#include "MemMap.h"


#endif /* FEE_C */
/*****************************************************************************
*     End of File
*
*******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 05-02-2016                                            */
/*Version           :                                                       */
/*By                : vbalakr3                                              */
/*Traceability      :                                                       */
/*Change Description: Datadesign And Framework implemented, Initial Version */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 23-02-2016                                            */
/*Version           :                                                       */
/*By                : vbalakr3                                              */
/*Traceability      :                                                       */
/*Change Description:Write, Read, Sector Switch, Partition init implemented */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 18-03-2020                                            */
/*Version           :                                                       */
/*By                : ssebast1                                              */
/*Traceability      : RTC#817466                                            */
/*Change Description:Erase Failure Handling								    */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 30-06-2020                                            */
/*Version           :                                                       */
/*By                : lthanga1                                              */
/*Traceability      : RTC#456722                                             */
/*Change Description: Renesas Application note findings fix*/
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 23-10-2020                                            */
/*Version           :                                                       */
/*By                : vbalakr3                                              */
/*Traceability      : RTC#1099632                                           */
/*Change Description: Warning Fix                                           */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 24-02-2021                                            */
/*Version           :                                                       */
/*By                : vbalakr3                                              */
/*Traceability      : 			                                            */
/*Change Description: defect fix                                            */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 24-12-2021                                            */
/*Version           :                                                       */
/*By                : vbalakr3                                              */
/*Traceability      : 			                                            */
/*Change Description: defect fix                                            */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 25-01-2022                                            */
/*Version           :                                                       */
/*By                : jponsing                                              */
/*Traceability      : RTC#1543928                                           */
/*Change Description: Background Sector Switch Implimentation               */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 15-05-2022                                            */
/*Version           :                                                       */
/*By                : jponsing                                              */
/*Traceability      : RTC#1643018                                           */
/*Change Description: Fee Cancel  Implemented				                */
/*--------------------------------------------------------------------------*/

