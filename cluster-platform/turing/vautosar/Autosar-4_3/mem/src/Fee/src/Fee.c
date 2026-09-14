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
#include "FeeExt.h"
#include "Fee_Cbk.h"
#include "MemLib.h"
#include "Crc.h"
#include "Os.h"
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

#define FEE_READ_RETRY_COUNT    5U
#define FEE_PAGE_SIZE           4U
#define FEE_BLANK_CHECK_RETRY_COUNT    5U


#define FEE_RESET_INFO_FOOTER_0 0x28A63D82UL
#define FEE_RESET_INFO_FOOTER_1 0xA628823DUL

#define FEE_RESET_INFO_HEADER_0 0x5A36A563UL
#define FEE_RESET_INFO_HEADER_1 0x365A63A5UL

#define FEE_RESET_INFO_BLOCK_LEN 8U

#define FEE_RESET_INFO_SECTOR_HEADER_SIZE   8U
#define FEE_RESET_INFO_SECTOR_FOOTER_SIZE   8U
#define FEE_MAX_ERASE_BLOCK_ARRAY		2U
#define FEE_UINT32_MAX_VALUE            0xFFFFFFFFu
#define FEE_UINT16_MAX_VALUE            0xFFFFu
#define FEE_UINT_MIN_VALUE              0x0u

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
    FEE_JOB_STATE_CHECK_WRITE_REQUEST,
    FEE_JOB_STATE_UPDT_WRITE_RESET_INFO,
    FEE_JOB_STATE_UPDT_WRITE_RESET_INFO_WAIT,
    FEE_JOB_STATE_WRITE_HEADER1,
    FEE_JOB_STATE_WRITE_HEADER1_WAIT,
    FEE_JOB_STATE_WRITE_PAYLOAD,
    FEE_JOB_STATE_WRITE_PAYLOAD_WAIT,
    FEE_JOB_STATE_WRITE_HEADER2,
    FEE_JOB_STATE_WRITE_HEADER2_WAIT,
    FEE_JOB_STATE_UPDT_IDLE_RESET_INFO,
    FEE_JOB_STATE_UPDT_IDLE_RESET_INFO_WAIT,
    FEE_JOB_STATE_READ_HEADER,
    FEE_JOB_STATE_READ_HEADER_WAIT,
    FEE_JOB_STATE_READ_PAYLOAD,
    FEE_JOB_STATE_READ_PAYLOAD_WAIT,
    FEE_JOB_STATE_TRAVERSE_READ,
    FEE_JOB_STATE_TRAVERSE_READ_WAIT,
    FEE_JOB_STATE_TRAVERSE_VALIDATE,
    FEE_JOB_STATE_TRAVERSE_VALIDATE_WAIT
}Fee_JobStateType;


typedef enum
{
    FEE_SECTOR_SWITCH_STATE_IDLE = 0,
    FEE_SECTOR_SWITCH_STATE_UPDT_RESET_INFO,
    FEE_SECTOR_SWITCH_STATE_UPDT_RESET_INFO_WAIT,
    FEE_SECTOR_SWITCH_STATE_HEADER_WRITE,
    FEE_SECTOR_SWITCH_STATE_HEADER_WRITE_WAIT,
    FEE_SECTOR_SWITCH_STATE_SEARCH_NEXT_BLOCK,
    FEE_SECTOR_SWITCH_STATE_BLOCK_READ,
    FEE_SECTOR_SWITCH_STATE_BLOCK_READ_WAIT,
    FEE_SECTOR_SWITCH_STATE_BLOCK_READ_VALIDATE,
    FEE_SECTOR_SWITCH_STATE_BLOCK_TRAVERSE_READ,
    FEE_SECTOR_SWITCH_STATE_BLOCK_TRAVERSE_READ_WAIT,
    FEE_SECTOR_SWITCH_STATE_BLOCK_TRAVERSE_VALIDATE,
    FEE_SECTOR_SWITCH_STATE_BLOCK_TRAVERSE_VALIDATE_WAIT,
    FEE_SECTOR_SWITCH_STATE_BLOCK_WRITE,
    FEE_SECTOR_SWITCH_STATE_BLOCK_WRITE_WAIT,
    FEE_SECTOR_SWITCH_STATE_SECTOR_FOOTER_WRITE,
    FEE_SECTOR_SWITCH_STATE_SECTOR_FOOTER_WRITE_WAIT,
    FEE_SECTOR_SWITCH_STATE_SUSPENDED
}Fee_SectorSwitchStateType;


typedef enum
{
    FEE_PARTITION_STATE_IDLE = 0,
    FEE_PARTITION_STATE_SECTOR_HEADER_CHECK,
    FEE_PARTITION_STATE_SECTOR_HEADER_CHECK_WAIT,
    FEE_PARTITION_STATE_SECTOR_FOOTER_CHECK,
    FEE_PARTITION_STATE_SECTOR_FOOTER_CHECK_WAIT,
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
    FEE_PARTITION_SECTOR_BLOCK_READ_FAIL_SAFE_TRIGGER,
    FEE_PARTITION_SECTOR_BLOCK_READ_FAIL_SAFE_READ,
    FEE_PARTITION_SECTOR_BLOCK_READ_FAIL_SAFE_READ_WAIT
}Fee_PartitionStateType;


typedef enum
{
    FEE_SECTOR_ERASE_STATE_IDLE = 0,
    FEE_SECTOR_ERASE_STATE_UPDT_RESET_INFO,
    FEE_SECTOR_ERASE_STATE_UPDT_RESET_INFO_WAIT,
    FEE_SECTOR_ERASE_STATE_ERASE,
    FEE_SECTOR_ERASE_STATE_ERASE_WAIT,
    FEE_SECTOR_ERASE_STATE_UPDT_IDLE_RESET_INFO,
    FEE_SECTOR_ERASE_STATE_UPDT_IDLE_RESET_INFO_WAIT,
    FEE_SECTOR_ERASE_STATE_PROCESS_DEFERRED_ERASE,
    FEE_SECTOR_ERASE_STATE_SUSPENDED
}Fee_SectorEraseType;

typedef enum
{
    FEE_PROCESS_RESET_INFO_IDLE=0,
    FEE_PROCESS_RESET_READ_HEADER,
    FEE_PROCESS_RESET_READ_HEADER_WAIT,
    FEE_PROCESS_RESET_READ_FOOTER,
    FEE_PROCESS_RESET_READ_FOOTER_WAIT,
    FEE_PROCESS_RESET_VALIDATE_HEADER,
    FEE_PROCESS_RESET_READ_BACKUP_INFO,
    FEE_PROCESS_RESET_READ_BACKUP_INFO_WAIT,
    FEE_PROCESS_RESET_INFO_SEARCH_NEXT_INFO,
    FEE_PROCESS_RESET_INFO_SEARCH_NEXT_INFO_WAIT,
    FEE_PROCESS_RESET_INFO_READ_RESET_INFO,
    FEE_PROCESS_RESET_INFO_READ_RESET_INFO_WAIT,
    FEE_PROCESS_RESET_INFO_VALIDATE,
    FEE_PROCESS_RESET_INFO_ERASE,
    FEE_PROCESS_RESET_INFO_JOB_COMPLETED,
}Fee_ResetInfoStateType;

typedef enum
{
    FEE_RESET_INFO_INTERNAL_JOB_IDLE=0,
    FEE_RESET_INFO_INTERNAL_JOB_REQUEST_ERASE,
    FEE_RESET_INFO_INTERNAL_JOB_BACKUP_HEALTH_CHECK,
    FEE_RESET_INFO_INTERNAL_JOB_BACKUP_HEALTH_CHECK_WAIT,
    FEE_RESET_INFO_INTERNAL_JOB_BACKUP_ERASE,
    FEE_RESET_INFO_INTERNAL_JOB_BACKUP_ERASE_WAIT,
    FEE_RESET_INFO_INTERNAL_JOB_BACKUP_WRITE,
    FEE_RESET_INFO_INTERNAL_JOB_BACKUP_WRITE_WAIT,
    FEE_RESET_INFO_INTERNAL_JOB_INITAITE_ERASE,
    FEE_RESET_INFO_INTERNAL_JOB_ERASE_WAIT,
    FEE_RESET_INFO_INTERNAL_JOB_HEADER_WRITE,
    FEE_RESET_INFO_INTERNAL_JOB_HEADER_WRITE_WAIT,
    FEE_RESET_INFO_INTERNAL_JOB_INSTANCE_WRITE,
    FEE_RESET_INFO_INTERNAL_JOB_INSTANCE_WRITE_WAIT,
    FEE_RESET_INFO_INTERNAL_JOB_FOOTER_WRITE,
    FEE_RESET_INFO_INTERNAL_JOB_FOOTER_WRITE_WAIT,
    FEE_RESET_INFO_INTERNAL_JOB_BACKUP_SECTOR_PREPARE,
    FEE_RESET_INFO_INTERNAL_JOB_BACKUP_SECTOR_PREPARE_WAIT,
}Fee_ResetInfoInternalJobStateType;

typedef enum
{
    FEE_INTERRUPTED_JOB_IDLE = 0,
    FEE_WRITE_JOB_INTERRUPTED,
    FEE_SECTORSWITCH_JOB_INTERRUPTED,
    FEE_SECTOR_ERASE_JOB_INTERRUPTED
}Fee_InteruptedJobType;

typedef enum
{
    FEE_SECTOR_EMPTY = 0,
    FEE_SECTOR_VALID,
    FEE_SECTOR_INVALID
}Fee_SectorHealthType;
typedef struct 
{
    uint32 Address;
    Fee_ResetInfoStateType ResetInfoState;
    boolean TraverseErrorDetected;
}Fee_ResetInfoAdminDataType;

typedef struct
{
    Fee_InteruptedJobType InterruptedJob;
    uint8 InterruptedJobSectorId;
}Fee_InterruptedJobAdminDataType;


typedef struct
{
    uint16 HeadPattern; 
    uint16 PartitionState;
    uint16 InterruptedJobSectorState;
    uint16 Crc16;
}Fee_ResetInfoDataType;

typedef struct  
{
    uint32 NextFreeAddress;
    uint32 FailSafeTraverseAddress;
    uint32 FailSafeEndAddress;
    Fee_PartitionStatusType Status;
    uint8 OldSectorId;
    uint8 CurrentSectorId;
    uint8 EraseSectorId;
    uint8 count;
    uint8 PossibleInterruptWrite;
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
    uint8 ProcessInternalJob;
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
typedef Fee_BlockHeaderType Arr_Fee_BlockHeaderType[2];
Arr_Fee_BlockHeaderType ErasedBlock = {0xFFu};

typedef struct  
{
    uint16 TraverseBlockId;
    uint32 TraverseAddress;
    uint32 EndAddress;
    uint32 ValidBlockAddress;
}Fee_SectorSwitchTraverseType;

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
    Fee_SectorHealthType StartSectorHealth;
    Fee_SectorHealthType EndSectorHealth;
    boolean BlankHeader;
    boolean BlankFooter;
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

typedef struct
{
    uint32 StartTimeStamp;
    uint32 ElapsedTimeStamp;
    uint8 TimerIsRunning;
    uint8 TimerIsExpired;
    uint8 ReadRetryCount;
    uint8 EraseRetryCount;
    uint8 SectorSwitchRetryCount;
    uint8 BlankCheckRetryCount;
}Fee_RetryManagementDataType;

typedef struct  
{
    uint16 TraverseBlockId;
    uint32 TraverseAddress;
    uint32 EndAddress;
    uint32 ValidBlockAddress;
}Fee_TraverseType;
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

#define FEE_RETENTION_BSS_START
#include "NvM_MemMap.h"

static Fee_BlockInformationType Fee_BlockInformation[FEE_NUM_BLOCKS];
static Fee_PartitionType Fee_Partition[FEE_NUM_PARTITIONS];

#define FEE_RETENTION_BSS_END
/* MISRA C-2012 Rule 20.1 : As per visteon coding standards MemMap.h  is used in NvM. It is used to map the memory segments. It will not have any functional Impact */
#include "NvM_MemMap.h"
static Fee_BlockInformationType Fee_BlockInformation_cpy[FEE_NUM_BLOCKS];

static Fee_JobType Fee_Job;
static Fee_JobType Fee_JobCpy;
static Fee_SectorSearchType Fee_SectorSearch;
static Fee_BlockType Fee_SectorSwitchBlockBuffer;

static Fee_PartitionSectorPendingEraseType Fee_PartitionPendingSectorErase[FEE_NUM_PARTITIONS];

static Fee_PartitionSectorPendingHeaderWriteType Fee_PartitionSectorPendingHeaderWrite[FEE_NUM_PARTITIONS];
static Fee_ResetInfoAdminDataType Fee_ResetInfoAdminData;
static Fee_ResetInfoDataType Fee_ResetInfoData;
static Fee_ResetInfoInternalJobStateType Fee_ResetInfoInternalJobState; 

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
static Arr_Fee_BlockHeaderType Fee_BlockHeader;

static Fee_SectorSwitchTraverseType Fee_SectorSwitchTraverseData;
static Fee_RetryManagementDataType Fee_RetryManagementData;
static Fee_TraverseType Fee_TraverseData;
static Fee_InterruptedJobAdminDataType Fee_InterruptedJobAdminData[FEE_NUM_PARTITIONS];

static uint32 Fee_ResetInfoHeader[2];
static uint32 Fee_ResetInfoFooter[2];

uint8 TraverseRead_PayloadBuffer[FEE_MAX_LENGTH];
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
static void Fee_PartitionSectorBlockReadFailSafeTrigger(void);
static void Fee_PartitionSectorBlockReadFailSafeRead(void);
static void Fee_PartitionSectorBlockReadFailSafeReadWait(void);
static void Fee_PartitionSectorHeaderCheck(void);
static void Fee_PartitionSectorHeaderCheckWait(void);
static void Fee_PartitionSectorFooterCheck(void);
static void Fee_PartitionSectorFooterCheckWait(void);
static void Fee_JobCheckWriteRequest(void);
static void Fee_JobUpdateWriteResetInfo(void);
static void Fee_JobUpdateWriteResetInfoWait(void);
static void Fee_JobUpdateWriteIdleResetInfo(void);
static void Fee_JobUpdateWriteIdleResetInfoWait(void);
static void Fee_JobUpdateSecSwitchResetInfo(void);
static void Fee_JobUpdateSecSwitchResetInfoWait(void);
static void Fee_JobUpdateEraseResetInfo(void);
static void Fee_JobUpdateEraseResetInfoWait(void);
static void Fee_JobUpdateEraseIdleResetInfo(void);
static void Fee_JobUpdateEraseIdleResetInfoWait(void);
static void Fee_SectorSwitchBlockTraverseRead(void);
static void Fee_SectorSwitchBlockTraverseReadWait(void);
static void Fee_SectorSwitchBlockTraverseValidate(void);
static void Fee_SectorSwitchBlockTraverseValidateWait(void);
static void Fee_SectorSwitchBlockReadValidate(void);
static void Fee_CpyFeeBlockInformation (uint8 p_Partition_No);
static void Fee_RestoreFeeBlockInformation (uint8 p_Partition_No);
static Std_ReturnType Fee_IsResetInfoInternalJobPending(void);
static void Fee_ProcessResetInfoInternalJob(void);
static Std_ReturnType Fee_CheckResetInfoRange(void);
static void Fee_InitiateResetInfoInternalJob(void);
static Std_ReturnType Fee_IsResetInfoRangeAvailable(void);
static void Fee_PrefillHeader (void);

/*****************************************************************************
*                   Functions                                                *
******************************************************************************/

/**************************************************************************
Function name   : void Fee_Init(void)
Arguments       : void
Return type     : void
Description     : Service to initialize the FEE module. 
**************************************************************************/
static void Fee_ResetRetryTimer(void)
{
    Fee_RetryManagementData.TimerIsRunning = FALSE;
    Fee_RetryManagementData.TimerIsExpired = FALSE;
}
static void Fee_RetryTimeoutProcess(void)
{
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 Delay;
    /*
        Start OS based timer, If not already started.
    */
    if(FALSE == Fee_RetryManagementData.TimerIsRunning)
    {
        /* Timer is not yet started, So Taking TimeStamp of Os Tick*/
        (void)GetCounterValue(SystemTimer,(TickRefType)(&Fee_RetryManagementData.StartTimeStamp));
        /*Mark as timer running*/
        Fee_RetryManagementData.TimerIsRunning = TRUE;
    }
    else
    {
        /* Timer is started, So we are checking for timer expiry*/
        (void)GetCounterValue(SystemTimer,(TickRefType)(&Fee_RetryManagementData.ElapsedTimeStamp));
        StartTime = Fee_RetryManagementData.StartTimeStamp;
        ElapsedTime = Fee_RetryManagementData.ElapsedTimeStamp;
        
        if( ElapsedTime < StartTime )
        {
            Delay = (uint32)(0xFFFFFFFFU - StartTime ) + ElapsedTime;
        }
        else
        {
            Delay = (uint32)( ElapsedTime - StartTime );
        }

        if(Delay >= FEE_RETRY_TIMEOUT_MS)
        {
            Fee_RetryManagementData.TimerIsExpired = TRUE;
        }

    }
}
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
    Fee_Job.ProcessInternalJob = FEE_BSS_INTERNAL_LOCK_SET_BIT;
    Fee_Job.CancelFlag = FALSE;
    Fee_Job.InternalJobTimer = FEE_RELOAD_TIMER;
    Fee_Job.FirstWrite = FALSE;
    Fee_Job.CurPartition = 0U;
    Fee_Job.SearchBlockId = 0U;
    Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
    Fee_Job.ResumeSectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
    Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_IDLE;
    Fee_Job.ResumeSectorSwitchState = FEE_SECTOR_SWITCH_STATE_IDLE;

    MemLib_MemCpy (&Fee_JobCpy , &Fee_Job, sizeof(Fee_JobCpy) );

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
            /* MISRA C-2012 Rule 10.3 : Calculated Values of Fee_PartitionPendingSectorErase[fl_PartionNo].SectorEraseFlag[fl_SectorNo] and FALSE were well within the range.It will not have any functional impact */
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
    Fee_SectorSwitchTraverseData.TraverseBlockId = 0xFFFFUL;
    Fee_SectorSwitchTraverseData.TraverseAddress = 0xFFFFFFFFUL;
    Fee_SectorSwitchTraverseData.EndAddress = 0xFFFFFFFFUL;
    Fee_SectorSwitchTraverseData.ValidBlockAddress = 0xFFFFFFFFUL;
    Fee_ResetInfoAdminData.Address = Fee_InternalSectorConfig.SectorStartAddress;
    Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_READ_HEADER;
    Fee_Job.JobActiveId = FEE_JOB_INTERNAL_BUSY;
    Fee_NotifyInternalJobStatus(FEE_START_INTERNAL_JOB);
    #ifdef FEE_TRACE_ENABLE
    FEE_TRACE(FEE_INIT,0,0);
    #endif
}

/**************************************************************************
Function name   : void Fee_SetMode(MemIf_ModeType Mode)
Arguments       : MemIf_ModeType Mode
Return type     : void
Description     : Service to call the Fls_SetMode function of the underlying flash driver. 
**************************************************************************/
void Fee_SetMode(MemIf_ModeType Mode)
{
    (void)Mode;
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
    Std_ReturnType fl_RetVal = E_NOT_OK;
    (void)Length;
    if(Fee_Job.JobActiveId == FEE_JOB_IDLE)
    {
        /* Process Fee Read only if BlockNumber and ReadBuffer are valid */
        if(FEE_NUM_BLOCKS > BlockNumber)
        {
            if(NULL_PTR != DataBufferPtr)
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
                #ifdef FEE_TRACE_ENABLE
                if(FALSE != NvM_Test_ReadAll_Notify())
                {
                    FEE_TRACE(READ_ACCEPTED,0,BlockNumber);
                }
                #endif
            }
        }
    }
    else
    {
        #ifdef FEE_TRACE_ENABLE
        if(FALSE != NvM_Test_ReadAll_Notify())
        {
            FEE_TRACE(READ_REJECTED_BUSY,0,0);
        }
        #endif
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

    if(FEE_NUM_BLOCKS > BlockNumber)
    {
        if(Fee_Job.JobActiveId == FEE_JOB_IDLE)  /* check if job state is in idle. if it is idle accept the job */
        {
            Fee_Job.InternalJobTimer = FEE_RELOAD_TIMER;
            Fee_Job.JobActiveId = FEE_JOB_WRITE;   /* update the job Active ID to FEE_JOB_WRITE */
            Fee_Job.BlockId = BlockNumber;           /* given by nvm in which block it should write */
            Fee_Job.JobResult = MEMIF_JOB_PENDING;   /* Update the Jb result as pending till the write option completes */
            Fee_Job.JobState = FEE_JOB_STATE_CHECK_WRITE_REQUEST;  
            Fee_Job.Length = Fee_BlockConfig[BlockNumber].BlockSize;
            /* MISRA C-2012 Rule 11.8 : DataBufferPtr is based on Pointer Index Calculation. It will not have any functional Impact */
            Fee_Job.RamAddress = (uint8 *)DataBufferPtr;
            Fee_Job.Offset = 0U;
            fl_RetVal = E_OK;
            #ifdef FEE_TRACE_ENABLE
            FEE_TRACE(WRITE_ACCEPTED,0,BlockNumber);
            #endif
        }
        else                                   
        {
            #ifdef FEE_TRACE_ENABLE
            FEE_TRACE(WRITE_REJECTED_BUSY,0,0);
            #endif
            fl_RetVal = E_NOT_OK;
        }
    }
    else                                   /* check if job state is in idle. if it is not in idle dont accept the job. return E_NOT_OK */
    {
        #ifdef FEE_TRACE_ENABLE
        FEE_TRACE(WRITE_REJECTED_OUT_OF_RANGE,0,0);
        #endif
        fl_RetVal = E_NOT_OK;
    }
    return fl_RetVal;                     /* return the job accepted status */
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
    if((Fee_Job.JobActiveId == FEE_JOB_INTERNAL_BUSY) && (Fee_Job.JobState == FEE_JOB_STATE_CHECK_WRITE_REQUEST))  /* case : Foreground Sector Switch & Diff Erase*/
    { 
        Fee_Job.JobResult = MEMIF_JOB_CANCELED;
        Fee_Job.JobState = FEE_JOB_STATE_IDLE;
        FEE_NVM_JOB_ERROR_NOTIFICATION();
    }
    else if ((Fee_Job.PartitionState >= FEE_PARTITION_STATE_SECTOR_HEADER_WRITE) &&\
             (Fee_Job.PartitionState <= FEE_PARTITION_STATE_SECTOR_FOOTER_WRITE_WAIT)) /* case : Sector Preperation */
    {
        Fee_Job.CancelFlag = TRUE;
    }
    else if (Fee_Job.PartitionState != FEE_PARTITION_STATE_IDLE) /* case : Partition Init */
    {
        if (MEMIF_JOB_PENDING == FLS_GET_JOB_RESULT())
        {
            FLS_CANCEL();
        }
        if (FEE_NUM_BLOCKS > Fee_Job.BlockId)
        {
            fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
            if (FEE_NUM_PARTITIONS > fl_PartionNo)
            {
                Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_UNINIT;
            }
            else 
            {
                FEE_DEBUG_ERROR(FALSE);
            }
        }
        else 
        {
            FEE_DEBUG_ERROR(FALSE);
        }
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
        /*Do Nothing*/
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
    (void)BlockNumber;
    return E_NOT_OK;
}

/**************************************************************************
Function name   : void Fee_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr)
Arguments       : Std_VersionInfoType* VersionInfoPtr
Return type     : void
Description     : Service to return the version information of the FEE module.
**************************************************************************/
/* MISRA C-2012 Rule 8.13 : As per Autosar standard VersionInfoPtr is used in NvM. It will not have any functional impact */
void Fee_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr)
{
    (void)VersionInfoPtr;
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
    (void)BlockNumber;
    return E_NOT_OK;
}

/**************************************************************************
Function name   : void Fee_JobEndNotification(void)
Arguments       : void
Return type     : void
Description     : Service to report to this module the successful end of an asynchronous operation.
**************************************************************************/
/* MISRA C-2012 Rule 8.7 : As per autosar standard, Fee_JobEndNotification is defined. It will not have any functional impact */
void Fee_JobEndNotification(void)
{
    /* Implementation of FEE supports only polling option for requests between
       Fee and Fls. So this function is not used.
    */
}

/**************************************************************************
Function name   : void Fee_JobErrorNotification(void)
Arguments       : void
Return type     : void
Description     : Service to report to this module the failure of an asynchronous operation.
**************************************************************************/
/* MISRA C-2012 Rule 8.7 : As per autosar standard, Fee_JobErrorNotification is defined. It will not have any functional impact */
void Fee_JobErrorNotification(void)
{
    /* Implementation of FEE supports only polling option for requests between
       Fee and Fls. So this function is not used.
    */
}
/**************************************************************************
Function name   : void Fee_SuspendInternalJob(void)
Arguments       : void
Return type     : void
Description     : Service to Suspend all Internal Jobs.
**************************************************************************/
void Fee_SuspendInternalJob(void)
{
    Fee_Job.ProcessInternalJob |= FEE_BSS_INTERNAL_LOCK_SET_BIT;
    if((Fee_Job.SectorSwitchState == FEE_SECTOR_SWITCH_STATE_IDLE) && \
        (Fee_ResetInfoAdminData.ResetInfoState == FEE_PROCESS_RESET_INFO_IDLE) && \
        (Fee_Job.SectorEraseState == FEE_SECTOR_ERASE_STATE_IDLE))
    {
        Fee_NotifyInternalJobStatus(FEE_SUSPEND_INTERNAL_JOB);
        #ifdef MEM_TESTING_ENABLED
        FEE_JOB_HOOK(FEE_SUSPEND_INTERNAL_JOB,Fee_Job.CurPartition);
        #endif
    }
}
/**************************************************************************
Function name   : void Fee_LockInternalJob(boolean)
Arguments       : Status
                   TRUE : Enable Lock
                   FALSE : Disable Lock
Return type     : void
Description     : Service to Suspend all Internal Jobs.
**************************************************************************/
Std_ReturnType Fee_LockInternalJob(boolean Status)
{
    Std_ReturnType fl_Return = E_NOT_OK;
    if (FALSE != Status)
    {
        if (FEE_JOB_IDLE == Fee_Job.JobActiveId)
        {
            Fee_Job.ProcessInternalJob |= FEE_BSS_EXTERNAL_LOCK_SET_BIT;
            fl_Return = E_OK;
        }
    }
    else
    {
        Fee_Job.ProcessInternalJob &= FEE_BSS_EXTERNAL_LOCK_RELEASE_BIT;
        fl_Return = E_OK;
    }
    return fl_Return;
}

/**************************************************************************
Function name   : void Fee_ResumeInternalJob(void)
Arguments       : void
Return type     : void
Description     : Service to Resume all Internal Jobs.
**************************************************************************/
void Fee_ResumeInternalJob(void)
{
    if (FALSE != Fee_Job.FirstWrite)
    {
        Fee_Job.ProcessInternalJob &= FEE_BSS_INTERNAL_LOCK_RELEASE_BIT;
    }
    if(Fee_Job.SectorSwitchState == FEE_SECTOR_SWITCH_STATE_SUSPENDED)
    {
        if (FEE_BSS_INTERNAL_NO_LOCK == Fee_Job.ProcessInternalJob)
        {
            Fee_RestoreJobState();
            Fee_Job.JobActiveId = FEE_JOB_INTERNAL_BUSY;
            Fee_Job.SectorSwitchState = Fee_Job.ResumeSectorSwitchState;
            Fee_Job.ResumeSectorSwitchState = FEE_SECTOR_SWITCH_STATE_IDLE;
            Fee_NotifyInternalJobStatus(FEE_RESUME_INTERNAL_JOB);
        #ifdef MEM_TESTING_ENABLED
            FEE_JOB_HOOK(FEE_RESUME_INTERNAL_JOB,Fee_Job.CurPartition);
        #endif
        }
    }
    if(Fee_Job.SectorEraseState == FEE_SECTOR_ERASE_STATE_SUSPENDED)
    {
        if (FEE_BSS_INTERNAL_NO_LOCK == Fee_Job.ProcessInternalJob)
        {
            Fee_RestoreJobState();
            Fee_Job.JobActiveId = FEE_JOB_INTERNAL_BUSY;
            Fee_Job.SectorEraseState = Fee_Job.ResumeSectorEraseState;
            Fee_Job.ResumeSectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
            Fee_NotifyInternalJobStatus(FEE_RESUME_INTERNAL_JOB);
        #ifdef MEM_TESTING_ENABLED
            FEE_JOB_HOOK(FEE_RESUME_INTERNAL_JOB,Fee_Job.CurPartition);
        #endif
        }
    }
    if((Fee_Job.SectorSwitchState == FEE_SECTOR_SWITCH_STATE_IDLE) && (Fee_Job.SectorEraseState == FEE_SECTOR_ERASE_STATE_IDLE))
    {
        Fee_NotifyInternalJobStatus(FEE_END_INTERNAL_JOB);
        #ifdef MEM_TESTING_ENABLED
        FEE_JOB_HOOK(FEE_END_INTERNAL_JOB,Fee_Job.CurPartition);
        #endif
    }
}

/**************************************************************************
Function name   : void Fee_JobCheckWriteRequest(void)
Arguments       : void
Return type     : void
Description     : Service to Check and Initiate The Write Pocess.
**************************************************************************/
static void Fee_JobCheckWriteRequest(void)
{
    if (FALSE == Fee_Job.FirstWrite)
    {
        Fee_Job.FirstWrite = TRUE;
        Fee_Job.ProcessInternalJob &= FEE_BSS_INTERNAL_LOCK_RELEASE_BIT;
    }
    uint8 fl_PartionNo; 
    Std_ReturnType fl_SectorSwitchRequired;
    if (FEE_NUM_BLOCKS > Fee_Job.BlockId)
    {
        fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
        if (FEE_NUM_PARTITIONS > fl_PartionNo)
        {
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
                Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_HEADER_CHECK;
                Fee_Job.RepeatStateMachine = TRUE;
            }
            /* MISRA C-2012 Rule 10.4 : Calculated Values of FALSE and Fee_PartitionPendingSectorErase[fl_PartionNo].SectorEraseEnable were well within the range.It will not have any functional impact */
            else if(FALSE != Fee_PartitionPendingSectorErase[fl_PartionNo].SectorEraseEnable)
            {
                Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_PROCESS_DEFERRED_ERASE;
                Fee_Job.JobActiveId = FEE_JOB_INTERNAL_BUSY;
                Fee_Job.CurPartition = fl_PartionNo;
                Fee_Job.RepeatStateMachine = TRUE;
            }
            /* MISRA C-2012 Rule 10.4 : Calculated Values of FALSE and Fee_PartitionSectorPendingHeaderWrite[fl_PartionNo].HeaderWritePending were well within the range.It will not have any functional impact */
            else if(FALSE != Fee_PartitionSectorPendingHeaderWrite[fl_PartionNo].HeaderWritePending)
            {
                Fee_Partition[fl_PartionNo].CurrentSectorId = Fee_PartitionSectorPendingHeaderWrite[fl_PartionNo].HeaderWriteSectorId;
                Fee_Partition[fl_PartionNo].count = 0U;
                /* MISRA C-2012 Rule 10.3 : Calculated Values of HeaderWritePending and FALSE were well within the range.It will not have any functional impact */
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
                if (FEE_BSS_INTERNAL_NO_LOCK == Fee_Job.ProcessInternalJob)
                {
                    Fee_Job.CurPartition = fl_PartionNo;
                    Fee_Job.JobActiveId = FEE_JOB_INTERNAL_BUSY;
                    Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_UPDT_RESET_INFO;
                    Fee_NotifyInternalJobStatus(FEE_START_INTERNAL_JOB);
                    #ifdef MEM_TESTING_ENABLED
                    FEE_JOB_HOOK(FEE_START_INTERNAL_JOB,Fee_Job.CurPartition);
                    #endif
                    Fee_Job.RepeatStateMachine = TRUE;
                }
            }
            else
            {
                Fee_Job.JobState = FEE_JOB_STATE_UPDT_WRITE_RESET_INFO;
            }
        }
        else
        {
            FEE_DEBUG_ERROR(FALSE);
        }
    }
    else
    {
        FEE_DEBUG_ERROR(FALSE);
    }
}

/**************************************************************************
Function name   : Std_ReturnType Fee_IsResetInfoInternalJobPending(void)
Arguments       : void
Return type     : Std_ReturnType
                    E_OK : Internal job is pending
                    E_NOT_OK : No Internal job is pending
Description     : Service to Check if internal job(Erase) is pending
**************************************************************************/
static Std_ReturnType Fee_IsResetInfoInternalJobPending(void)
{
    Std_ReturnType fl_RetVal = E_NOT_OK;
    
    if(FEE_RESET_INFO_INTERNAL_JOB_IDLE != Fee_ResetInfoInternalJobState)
    {
        fl_RetVal = E_OK;
    }

    return fl_RetVal;
}

/**************************************************************************
Function name   : void Fee_ProcessResetInfoInternalJob(void)
Arguments       : void
Return type     : void
Description     : Service to process internal Erase job
**************************************************************************/
static void Fee_ProcessResetInfoInternalJob(void)
{
    Std_ReturnType fl_RequestStatus;
    MemIf_JobResultType fl_JobResult;
    uint32 fl_Address = 0U;
    switch(Fee_ResetInfoInternalJobState)
    {
        case FEE_RESET_INFO_INTERNAL_JOB_IDLE:
            /*Do nothing*/
        break;

        case FEE_RESET_INFO_INTERNAL_JOB_REQUEST_ERASE:
            /*
                Primary sector has been identified as full, we need to store the backup
                and prepare this sector for further erase.
            */
            /* To store in the backup sector, we need to first verify if the sector is writable
               So doing a blank check
            */
           Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_BACKUP_HEALTH_CHECK;
        break;

        case FEE_RESET_INFO_INTERNAL_JOB_BACKUP_HEALTH_CHECK:
            fl_RequestStatus = FLS_BLANK_CHECK(Fee_InternalSectorConfig.BackupSectorAddress, FEE_RESET_INFO_BLOCK_LEN);
            if(E_OK == fl_RequestStatus)
            {
                Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_BACKUP_HEALTH_CHECK_WAIT;
            }
            else
            {
                /* Erase the backup sector*/
                Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_BACKUP_ERASE;
            }
        break;

        case FEE_RESET_INFO_INTERNAL_JOB_BACKUP_HEALTH_CHECK_WAIT:
            fl_JobResult = FLS_GET_JOB_RESULT();
            if(fl_JobResult != MEMIF_JOB_PENDING)
            {
                if(MEMIF_JOB_OK == fl_JobResult)
                {
                    Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_BACKUP_WRITE;
                }
                else
                {
                    Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_BACKUP_ERASE;
                }
            }
        break;

        case FEE_RESET_INFO_INTERNAL_JOB_BACKUP_ERASE:
            fl_RequestStatus = FLS_ERASE(Fee_InternalSectorConfig.BackupSectorAddress, Fee_InternalSectorConfig.BackupSectorSize);
            if(E_OK == fl_RequestStatus)
            {
                Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_BACKUP_ERASE_WAIT;
            }
            else
            {
                /* Erase the backup sector*/
                Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_BACKUP_ERASE;
            }
        break;

        case FEE_RESET_INFO_INTERNAL_JOB_BACKUP_ERASE_WAIT:
            fl_JobResult = FLS_GET_JOB_RESULT();
            if(fl_JobResult != MEMIF_JOB_PENDING)
            {
                if(MEMIF_JOB_OK == fl_JobResult)
                {
                    Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_BACKUP_WRITE;
                }
                else
                {
                    Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_BACKUP_ERASE;
                }
            }
        break;

        case FEE_RESET_INFO_INTERNAL_JOB_BACKUP_WRITE:
            fl_RequestStatus = FLS_WRITE(Fee_InternalSectorConfig.BackupSectorAddress, (uint8 *)&Fee_ResetInfoData.HeadPattern, FEE_RESET_INFO_BLOCK_LEN);
            if(E_OK == fl_RequestStatus)
            {
                Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_BACKUP_WRITE_WAIT;
            }
            else
            {
                /* Erase the backup sector*/
                Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_BACKUP_ERASE;
            }
        break;

        case FEE_RESET_INFO_INTERNAL_JOB_BACKUP_WRITE_WAIT:
            fl_JobResult = FLS_GET_JOB_RESULT();
            if(fl_JobResult != MEMIF_JOB_PENDING)
            {
                if(MEMIF_JOB_OK == fl_JobResult)
                {
                    Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_INITAITE_ERASE;
                }
                else
                {
                    Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_BACKUP_ERASE;
                }
            }
        break;

        case FEE_RESET_INFO_INTERNAL_JOB_INITAITE_ERASE:
            fl_RequestStatus = FLS_ERASE(Fee_InternalSectorConfig.SectorStartAddress, Fee_InternalSectorConfig.SectorSize);
            if (E_OK == fl_RequestStatus)
            {
                Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_ERASE_WAIT;
            }
        break;

        case FEE_RESET_INFO_INTERNAL_JOB_ERASE_WAIT:
            fl_JobResult = FLS_GET_JOB_RESULT();
            if(fl_JobResult != MEMIF_JOB_PENDING)
            {
                if(MEMIF_JOB_OK == fl_JobResult)
                {
                    Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_HEADER_WRITE;
                }
                else
                {
                    /* As Reset Info address has not changed, this will be above threshold, 
                       hence Erase will retry again*/
                    Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_INITAITE_ERASE;
                }
            }
        break;

        case FEE_RESET_INFO_INTERNAL_JOB_HEADER_WRITE:
            Fee_ResetInfoHeader[0] = FEE_RESET_INFO_HEADER_0;
            Fee_ResetInfoHeader[1] = FEE_RESET_INFO_HEADER_1;
            fl_RequestStatus = FLS_WRITE(Fee_InternalSectorConfig.SectorStartAddress, (uint8 *)&Fee_ResetInfoHeader[0],FEE_RESET_INFO_SECTOR_HEADER_SIZE);
            if (E_OK == fl_RequestStatus)
            {
                Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_HEADER_WRITE_WAIT;
            }
            else
            {
                /* Job is failed, So retrying primary sector with erase*/
                Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_INITAITE_ERASE;
            }
        break;

        case FEE_RESET_INFO_INTERNAL_JOB_HEADER_WRITE_WAIT:
            fl_JobResult = FLS_GET_JOB_RESULT();
            if(fl_JobResult != MEMIF_JOB_PENDING)
            {
                if(MEMIF_JOB_OK == fl_JobResult)
                {
                    Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_INSTANCE_WRITE;
                }
                else
                {
                    /* Job is failed, So retrying primary sector with erase*/
                    Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_INITAITE_ERASE;
                }
            }
        break;

        case FEE_RESET_INFO_INTERNAL_JOB_INSTANCE_WRITE:
            if(FEE_UINT32_MAX_VALUE > Fee_InternalSectorConfig.SectorStartAddress)
            {
                fl_Address = Fee_InternalSectorConfig.SectorStartAddress + FEE_RESET_INFO_SECTOR_HEADER_SIZE;
            }
            else
            {
                FEE_DEBUG_ERROR(FALSE);
            }
            fl_RequestStatus = FLS_WRITE(fl_Address, (uint8 *)&Fee_ResetInfoData.HeadPattern,FEE_RESET_INFO_BLOCK_LEN);
            if (E_OK == fl_RequestStatus)
            {
                Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_INSTANCE_WRITE_WAIT;
            }
            else
            {
                /* Job is failed, So retrying primary sector with erase*/
                Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_INITAITE_ERASE;
            }
        break;

        case FEE_RESET_INFO_INTERNAL_JOB_INSTANCE_WRITE_WAIT:
            fl_JobResult = FLS_GET_JOB_RESULT();
            if(fl_JobResult != MEMIF_JOB_PENDING)
            {
                if(MEMIF_JOB_OK == fl_JobResult)
                {
                    /* Load the footer address*/

                    Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_FOOTER_WRITE;
                }
                else
                {
                    /* Job is failed, So retrying primary sector with erase*/
                    Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_INITAITE_ERASE;
                }
            }
        break;

        case FEE_RESET_INFO_INTERNAL_JOB_FOOTER_WRITE:
            Fee_ResetInfoFooter[0] = FEE_RESET_INFO_FOOTER_0;
            Fee_ResetInfoFooter[1] = FEE_RESET_INFO_FOOTER_1;
            if(FEE_UINT32_MAX_VALUE > Fee_InternalSectorConfig.SectorStartAddress)
            {
                fl_Address = Fee_InternalSectorConfig.SectorStartAddress + Fee_InternalSectorConfig.SectorSize -\
                           FEE_RESET_INFO_SECTOR_FOOTER_SIZE;
            }
            else
            {
                FEE_DEBUG_ERROR(FALSE);
            }
            fl_RequestStatus = FLS_WRITE(fl_Address, (uint8 *)&Fee_ResetInfoFooter[0],FEE_RESET_INFO_SECTOR_FOOTER_SIZE);
            if (E_OK == fl_RequestStatus)
            {
                Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_FOOTER_WRITE_WAIT;
            }
            else
            {
                /* Job is failed, So retrying primary sector with erase*/
                Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_INITAITE_ERASE;
            }
        break;

        case FEE_RESET_INFO_INTERNAL_JOB_FOOTER_WRITE_WAIT:
            fl_JobResult = FLS_GET_JOB_RESULT();
            if(fl_JobResult != MEMIF_JOB_PENDING)
            {
                if(MEMIF_JOB_OK == fl_JobResult)
                {
                    Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_BACKUP_SECTOR_PREPARE;
                    if(FEE_UINT32_MAX_VALUE > Fee_InternalSectorConfig.SectorStartAddress)
                    {
                        Fee_ResetInfoAdminData.Address = Fee_InternalSectorConfig.SectorStartAddress + (FEE_RESET_INFO_SECTOR_HEADER_SIZE + FEE_RESET_INFO_BLOCK_LEN);
                    }
                    else
                    {
                        FEE_DEBUG_ERROR(FALSE);
                    }
                }
                else
                {
                    /* Job is failed, So retrying primary sector with erase*/
                    Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_INITAITE_ERASE;
                }
            }
        break;

        case FEE_RESET_INFO_INTERNAL_JOB_BACKUP_SECTOR_PREPARE:
            fl_RequestStatus = FLS_ERASE(Fee_InternalSectorConfig.BackupSectorAddress, Fee_InternalSectorConfig.BackupSectorSize);
            if(E_OK == fl_RequestStatus)
            {
                Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_BACKUP_SECTOR_PREPARE_WAIT;
            }
            else
            {
                /* Erase the backup sector*/
                Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_IDLE;
            }
        break;

        case FEE_RESET_INFO_INTERNAL_JOB_BACKUP_SECTOR_PREPARE_WAIT:
            fl_JobResult = FLS_GET_JOB_RESULT();
            if(fl_JobResult != MEMIF_JOB_PENDING)
            {
                Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_IDLE;
            }
        break;

        default:
            /*Do nothing*/
        break;

    }
}

/**************************************************************************
Function name   : Std_ReturnType Fee_CheckResetInfoRange(void)
Arguments       : void
Return type     : Std_ReturnType
                    E_OK : Reset info partition is having enough space 
                            to store Reset info.
                    E_NOT_OK : Reset info partition is full. 
                                Does not have enough space.
Description     : Service to Check the availablity of space in 
                    Reset info partition
**************************************************************************/
static Std_ReturnType Fee_CheckResetInfoRange(void)
{
    Std_ReturnType fl_RetVal = 0U;
    uint32 fl_CurrentResetInfoAddress = 0U;
    uint32 fl_ResetInfoEndAddress = 0U;
    uint32 fl_ResetInfoThreshold = 0U;
    fl_CurrentResetInfoAddress = Fee_ResetInfoAdminData.Address;
    if(FEE_UINT32_MAX_VALUE > Fee_InternalSectorConfig.SectorStartAddress)
    {
        fl_ResetInfoEndAddress = (uint32)(Fee_InternalSectorConfig.SectorStartAddress + Fee_InternalSectorConfig.SectorSize);
    }
    else
    {
        FEE_DEBUG_ERROR(FALSE);
    }
    if(FEE_UINT_MIN_VALUE < fl_ResetInfoEndAddress)
    {
        fl_ResetInfoThreshold = (uint32)(fl_ResetInfoEndAddress - (FEE_RESET_INFO_BLOCK_LEN * 6U) );
    }
    else
    {
        FEE_DEBUG_ERROR(FALSE);
    }
    if( fl_CurrentResetInfoAddress > fl_ResetInfoThreshold)
    {
        fl_RetVal = E_NOT_OK;
    }
    else
    {
        fl_RetVal = E_OK;
    }

    return fl_RetVal;
}

/**************************************************************************
Function name   : void Fee_InitiateResetInfoInternalJob(void)
Arguments       : void
Return type     : void
Description     : Service to Check and Initiate The Write Process.
**************************************************************************/
static void Fee_InitiateResetInfoInternalJob(void)
{
    /*This function will get called only whrn the ResetInfo internal job is idle and ResetInfo block needs to be erased*/
    Fee_ResetInfoInternalJobState = FEE_RESET_INFO_INTERNAL_JOB_REQUEST_ERASE;
}

/**************************************************************************
Function name   : Std_ReturnType Fee_IsResetInfoRangeAvailable(void)
Arguments       : void
Return type     : Std_ReturnType
Description     : Service to Check and Initiate The Write Pocess.
**************************************************************************/
static Std_ReturnType Fee_IsResetInfoRangeAvailable(void)
{
    Std_ReturnType fl_RetVal = E_NOT_OK;
    if(E_OK == Fee_IsResetInfoInternalJobPending())
    {
        Fee_ProcessResetInfoInternalJob();
    }
    else
    {
        if(E_OK == Fee_CheckResetInfoRange())
        {
            fl_RetVal = E_OK;
        }
        else
        {
            Fee_InitiateResetInfoInternalJob();
        }
    }
    return fl_RetVal;
}

static void Fee_FillResetInfoData(Fee_InteruptedJobType InteruptedJobState, uint8 p_PartitionId, uint8 p_SectorId)
{
    uint16 fl_crc_16 = 0U;
    uint8 fl_SectorIndex = 0U;
    fl_SectorIndex = p_SectorId % 2U;
    /* MISRA C-2012 Rule 10.3 : Calculated Values of Fee_ResetInfoData.HeadPattern and FEE_HEADER_RESET_PATTERN were well within the range.It will not have any functional impact */
    Fee_ResetInfoData.HeadPattern = FEE_HEADER_RESET_PATTERN;
    Fee_ResetInfoData.PartitionState &= ~(uint16)(0x03U << (p_PartitionId*2U));
    /* MISRA C-2012 Rule 10.1 : It is an intentional design. Enum InteruptedJobState used were executed and verified. It will not have any functional impact */
    Fee_ResetInfoData.PartitionState |= (uint16)(InteruptedJobState << (p_PartitionId*2U));
    Fee_ResetInfoData.InterruptedJobSectorState &= ~(uint16)(0x03U << (p_PartitionId*2U));
    if(FEE_INTERRUPTED_JOB_IDLE != InteruptedJobState)
    {
        if(fl_SectorIndex == 0U)
        {
            Fee_ResetInfoData.InterruptedJobSectorState |= (uint16)(0x01U << (p_PartitionId*2U));
        }
        else
        {
            Fee_ResetInfoData.InterruptedJobSectorState |= (uint16)(0x02U << (p_PartitionId*2U));
        }
    }
    fl_crc_16 = Crc_CalculateCRC16((const uint8*)&Fee_ResetInfoData,( sizeof(Fee_ResetInfoData) - sizeof(uint16)), 0U, TRUE);
    Fee_ResetInfoData.Crc16 = fl_crc_16;
    
    #ifdef FEE_TRACE_ENABLE
    FEE_TRACE(RESET_INFO_PART,12U,Fee_ResetInfoData.PartitionState);
    FEE_TRACE(RESET_INFO_PART,12U,Fee_ResetInfoData.InterruptedJobSectorState);
    #endif
}

/**************************************************************************
Function name   : void Fee_JobUpdateWriteResetInfo(void)
Arguments       : void
Return type     : void
Description     : Service to Initialize Write Reset Info Write.
**************************************************************************/
static void Fee_JobUpdateWriteResetInfo(void)
{
    uint8 fl_PartionNo = 0U;
    Std_ReturnType fl_RequestStatus = E_NOT_OK;
    uint8 fl_SectorId = 0xFFU;
    if(FEE_NUM_BLOCKS > Fee_Job.BlockId)
    {
        fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
    }
    else
    {
        FEE_DEBUG_ERROR(FALSE);
    }
    if(FEE_NUM_PARTITIONS > fl_PartionNo)
    {
        fl_SectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
    }
    else
    {
        FEE_DEBUG_ERROR(FALSE);
    }
    if(E_OK == Fee_IsResetInfoRangeAvailable())
    {
        Fee_FillResetInfoData(FEE_WRITE_JOB_INTERRUPTED, fl_PartionNo, fl_SectorId);
        fl_RequestStatus = FLS_WRITE(Fee_ResetInfoAdminData.Address,(uint8 *)&Fee_ResetInfoData.HeadPattern,FEE_RESET_INFO_BLOCK_LEN);
        if(fl_RequestStatus == E_OK)
        {
            #ifdef FEE_TRACE_ENABLE
            FEE_TRACE(WRITE_RESET_INFO_JOB_ACCEPTED,0,Fee_ResetInfoAdminData.Address);
            #endif
            if(FEE_UINT32_MAX_VALUE > Fee_ResetInfoAdminData.Address)
            {
                Fee_ResetInfoAdminData.Address += FEE_RESET_INFO_BLOCK_LEN;
                Fee_Job.JobState = FEE_JOB_STATE_UPDT_WRITE_RESET_INFO_WAIT;
            }
            else
            {
                FEE_DEBUG_ERROR(FALSE);
            }
        }
        else
        {
          #ifdef FEE_TRACE_ENABLE
          FEE_TRACE(WRITE_RESET_INFO_JOB_REJECTED,0,Fee_ResetInfoAdminData.Address);
          #endif
          Fee_Job.JobResult = MEMIF_JOB_FAILED;
          FEE_NVM_JOB_ERROR_NOTIFICATION();
          Fee_Job.JobActiveId = FEE_JOB_IDLE;
          Fee_Job.JobState = FEE_JOB_STATE_IDLE;
          Fee_Job.RepeatStateMachine = FALSE;
        }
    }
}

/**************************************************************************
Function name   : void Fee_JobUpdateWriteResetInfoWait(void)
Arguments       : void
Return type     : void
Description     :  Service to Check the Flash Driver Job Result
**************************************************************************/
static void Fee_JobUpdateWriteResetInfoWait(void)
{
    MemIf_JobResultType fl_FlsJobStatus;
    fl_FlsJobStatus = FLS_GET_JOB_RESULT();
    if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
    {
        if(MEMIF_JOB_OK != fl_FlsJobStatus)
        {
          #ifdef FEE_TRACE_ENABLE
          FEE_TRACE(WRITE_RESET_INFO_JOB_FAILED,0,Fee_ResetInfoAdminData.Address);
          #endif
          Fee_Job.JobResult = MEMIF_JOB_FAILED;
          FEE_NVM_JOB_ERROR_NOTIFICATION();
          Fee_Job.JobActiveId = FEE_JOB_IDLE;
          Fee_Job.JobState = FEE_JOB_STATE_IDLE;
          Fee_Job.RepeatStateMachine = FALSE;
        }
        else
        {
          Fee_Job.JobState = FEE_JOB_STATE_WRITE_HEADER1;
        }
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
    Std_ReturnType fl_RequestStatus = E_NOT_OK;
    uint8 fl_PartionNo = 0U;
    if(FEE_NUM_BLOCKS > Fee_Job.BlockId)
    {
        fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
    }
    else
    {
        FEE_DEBUG_ERROR(FALSE);
    }
    Fee_BlockHeader[0].BlockId = Fee_Job.BlockId;
    Fee_BlockHeader[0].PayloadLength = Fee_Job.Length;
    Fee_BlockHeader[0].Reserved1 = 0xFFFFU;
    Fee_BlockHeader[0].Reserved2 = 0xFFU;
    Fee_BlockHeader[0].ValidityFlag = FEE_BLOCK_VALIDITY_FLAG_VALID;
    if(FEE_NUM_PARTITIONS > fl_PartionNo)
    {
        fl_RequestStatus = FLS_WRITE(Fee_Partition[fl_PartionNo].NextFreeAddress,(uint8 *)&Fee_BlockHeader[0].BlockId,FEE_HEADER_SIZE);    /* where write in fls begin */
    }
    else
    {
        /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */
        FEE_DEBUG_ERROR(FALSE);
    }
    if(fl_RequestStatus == E_OK)
    {
        #ifdef FEE_TRACE_ENABLE
        FEE_TRACE(WRITE_HEADER_JOB_ACCEPTED, Fee_Partition[fl_PartionNo].CurrentSectorId, (uint16)Fee_Partition[fl_PartionNo].NextFreeAddress);
        #endif
        if(FEE_NUM_PARTITIONS > fl_PartionNo)
        {
            Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_Partition[fl_PartionNo].NextFreeAddress + (FEE_HEADER_SIZE << 1);
        }
        else
        {
            /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */
            FEE_DEBUG_ERROR(FALSE);
        }
        Fee_Job.JobState = FEE_JOB_STATE_WRITE_HEADER1_WAIT;
        Fee_Job.RepeatStateMachine = FALSE;
    }
    else
    {
        #ifdef FEE_TRACE_ENABLE
        FEE_TRACE(WRITE_JOB_REJECTED,Fee_Partition[fl_PartionNo].CurrentSectorId,(uint16)Fee_Partition[fl_PartionNo].NextFreeAddress);
        #endif
        Fee_Job.JobResult = MEMIF_JOB_FAILED;
        FEE_NVM_JOB_ERROR_NOTIFICATION();
        Fee_Job.JobActiveId = FEE_JOB_IDLE;
        Fee_Job.JobState = FEE_JOB_STATE_IDLE;
        Fee_Job.RepeatStateMachine = FALSE;
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
    Std_ReturnType fl_RetVal = E_NOT_OK;
    uint8 fl_CurrentSectorId;
    if (FEE_NUM_PARTITIONS > fl_PartionNo)
    {
        fl_CurrentSectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
        if (FEE_NUM_OF_SECTORS > fl_CurrentSectorId)
        {
            /* MISRA C-2012 Rule 10.3 : Calculated Values of Fee_Partition[fl_PartionNo].NextFreeAddress and Fee_SectorConfig[fl_CurrentSectorId].SectorSize were well within the range.It will not have any functional impact */
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
        }
        else
        {
            FEE_DEBUG_ERROR(FALSE);
        }
    }
    else
    {
        FEE_DEBUG_ERROR(FALSE);
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
    if (FEE_NUM_BLOCKS > Fee_Job.BlockId)
    {
        fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
        if (FEE_NUM_PARTITIONS > fl_PartionNo)
        {
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
                    #ifdef FEE_TRACE_ENABLE
                    FEE_TRACE(WRITE_JOB_FAILED,0,0);
                    #endif
                    if((FEE_NUM_OF_SECTORS > Fee_Partition[fl_PartionNo].CurrentSectorId))
                    {
                        if(FEE_UINT32_MAX_VALUE > Fee_SectorConfig[Fee_Partition[fl_PartionNo].CurrentSectorId].SectorStartAddress)
                        {
                            Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_SectorConfig[Fee_Partition[fl_PartionNo].CurrentSectorId].SectorStartAddress + \
                                                        Fee_SectorConfig[Fee_Partition[fl_PartionNo].CurrentSectorId].SectorSize - FEE_SECTOR_FOOTER_SIZE;
                        }
                        else
                        {
                            FEE_DEBUG_ERROR(FALSE);
                        }
                    }
                    else
                    {
                        /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */
                       FEE_DEBUG_ERROR(FALSE);
                    }
                    Fee_Job.JobResult = MEMIF_JOB_FAILED;
                    Fee_Job.JobState = FEE_JOB_STATE_UPDT_IDLE_RESET_INFO;
                    Fee_Job.RepeatStateMachine = FALSE;
                }
            }
            else
            {
                /* Wait for Next State Machine */
                Fee_Job.RepeatStateMachine = FALSE;
            }
        }
        else 
        {
            FEE_DEBUG_ERROR(FALSE);
        }
    }
    else 
    {
        FEE_DEBUG_ERROR(FALSE);
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
    if (FEE_NUM_BLOCKS > Fee_Job.BlockId)
    {
        fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
        if (FEE_NUM_PARTITIONS > fl_PartionNo)
        {
            fl_RequestType = FLS_WRITE(Fee_Partition[fl_PartionNo].NextFreeAddress,(uint8 *)Fee_Job.RamAddress,Fee_Job.Length);
            if(fl_RequestType == E_OK)
            {
                Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_Partition[fl_PartionNo].NextFreeAddress - FEE_HEADER_SIZE;
                Fee_Job.JobState = FEE_JOB_STATE_WRITE_PAYLOAD_WAIT;
                Fee_Job.RepeatStateMachine = FALSE;
            }
            else
            { 
                #ifdef FEE_TRACE_ENABLE
                FEE_TRACE(WRITE_PAYLOAD_JOB_REJECTED,0,0);
                #endif
                Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_Partition[fl_PartionNo].NextFreeAddress + Fee_Job.Length;
                Fee_Job.JobResult = MEMIF_JOB_FAILED;
                Fee_Job.JobState = FEE_JOB_STATE_UPDT_IDLE_RESET_INFO;
                Fee_Job.RepeatStateMachine = FALSE;
            }
        }
        else 
        {
            FEE_DEBUG_ERROR(FALSE);
        }
    }
    else 
    {
        FEE_DEBUG_ERROR(FALSE);
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
    uint8 fl_PartionNo = 0xFFU;
    MemIf_JobResultType fl_FlsJobStatus = MEMIF_JOB_FAILED;
    if (FEE_NUM_BLOCKS > Fee_Job.BlockId)
    {
        fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
    }
    else 
    {
        /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */
        FEE_DEBUG_ERROR(FALSE);
    }
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
            if((FEE_NUM_PARTITIONS > fl_PartionNo) && (FEE_NUM_OF_SECTORS > Fee_Partition[fl_PartionNo].CurrentSectorId))
            {
                if(FEE_UINT32_MAX_VALUE > Fee_SectorConfig[Fee_Partition[fl_PartionNo].CurrentSectorId].SectorStartAddress)
                {
                    Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_SectorConfig[Fee_Partition[fl_PartionNo].CurrentSectorId].SectorStartAddress + \
                                                Fee_SectorConfig[Fee_Partition[fl_PartionNo].CurrentSectorId].SectorSize - FEE_SECTOR_FOOTER_SIZE;
                }
                else
                {
                    FEE_DEBUG_ERROR(FALSE);
                }
            }
            else
            {
                FEE_DEBUG_ERROR(FALSE);
            }
            #ifdef FEE_TRACE_ENABLE
            FEE_TRACE(WRITE_PAYLOAD_JOB_FAILED,0,0);
            #endif
            Fee_Job.JobResult = MEMIF_JOB_FAILED;
            Fee_Job.JobState = FEE_JOB_STATE_UPDT_IDLE_RESET_INFO;
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
    Std_ReturnType fl_RequestType = E_NOT_OK;
    if (FEE_NUM_BLOCKS > Fee_Job.BlockId)
    {
        fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
        if (FEE_NUM_PARTITIONS > fl_PartionNo)
        {
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
        }
        else 
        {
            FEE_DEBUG_ERROR(FALSE);
        }
    }
    else 
    {
        FEE_DEBUG_ERROR(FALSE);
    }
    if(fl_RequestType == E_OK)
    {
        Fee_Job.JobState = FEE_JOB_STATE_WRITE_HEADER2_WAIT;
        Fee_Job.RepeatStateMachine = FALSE;
    }
    else
    {
        #ifdef FEE_TRACE_ENABLE
        FEE_TRACE(WRITE_HEADER2_JOB_REJECTED,0,0);
        #endif
        Fee_Job.JobResult = MEMIF_JOB_FAILED;
        Fee_Job.RepeatStateMachine = FALSE;
        Fee_Job.JobState = FEE_JOB_STATE_UPDT_IDLE_RESET_INFO;
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
    if (FEE_NUM_BLOCKS > Fee_Job.BlockId)
    {
        fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
        if(FEE_NUM_PARTITIONS > fl_PartionNo)
        {
            fl_FlsJobStatus = FLS_GET_JOB_RESULT();
            if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
            {
                if(fl_FlsJobStatus == MEMIF_JOB_OK)
                {
                    if (FALSE != Fee_Job.CancelFlag)
                    {
                        Fee_Job.JobResult = MEMIF_JOB_CANCELED;
                        Fee_Job.CancelFlag = FALSE;
                    }
                    else
                    {
                        Fee_Job.JobResult = MEMIF_JOB_OK;
                        if(FEE_UINT_MIN_VALUE < Fee_Partition[fl_PartionNo].NextFreeAddress)
                        {
                            Fee_BlockInformation[Fee_Job.BlockId].LatestAddress = Fee_Partition[fl_PartionNo].NextFreeAddress - (FEE_HEADER_SIZE << 1) - Fee_Job.Length;
                        }
                        else
                        {
                            FEE_DEBUG_ERROR(FALSE);
                        }
                    }
                    Fee_Job.RepeatStateMachine = FALSE;
                }
                else
                {
                    #ifdef FEE_TRACE_ENABLE
                    FEE_TRACE(WRITE_HEADER2_JOB_FAILED,0,0);
                    #endif
                    if((FEE_NUM_OF_SECTORS > Fee_Partition[fl_PartionNo].CurrentSectorId) && (FEE_UINT32_MAX_VALUE > Fee_SectorConfig[Fee_Partition[fl_PartionNo].CurrentSectorId].SectorStartAddress))
                    {
                        Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_SectorConfig[Fee_Partition[fl_PartionNo].CurrentSectorId].SectorStartAddress + \
                                                                        Fee_SectorConfig[Fee_Partition[fl_PartionNo].CurrentSectorId].SectorSize - FEE_SECTOR_FOOTER_SIZE;  
                    }
                    else
                    {
                        /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */
                        FEE_DEBUG_ERROR(FALSE);
                    }
                    Fee_Job.JobResult = MEMIF_JOB_FAILED;
                    Fee_Job.RepeatStateMachine = FALSE;
                }
                Fee_Job.JobState = FEE_JOB_STATE_UPDT_IDLE_RESET_INFO;
            }
            else
            {
                /* Wait for Next State Machine */
                Fee_Job.RepeatStateMachine = FALSE;
            }
        }
        else 
        {
            FEE_DEBUG_ERROR(FALSE);
            Fee_Job.JobResult = MEMIF_JOB_FAILED;
            Fee_Job.RepeatStateMachine = FALSE;
        }
    }
    else 
    {
        FEE_DEBUG_ERROR(FALSE);
        Fee_Job.JobResult = MEMIF_JOB_FAILED;
        Fee_Job.RepeatStateMachine = FALSE;
    }
}

/**************************************************************************
Function name   : void Fee_JobUpdateWriteIdleResetInfo(void)
Arguments       : void
Return type     : void
Description     :  Service to Initialise Reset Info Write
**************************************************************************/
static void Fee_JobUpdateWriteIdleResetInfo(void)
{
    Std_ReturnType fl_RequestStatus = E_NOT_OK;
    uint8 fl_PartionNo = 0U;
    uint8 fl_SectorId = 0xFFU;
    if(FEE_NUM_BLOCKS > Fee_Job.BlockId)
    {
        fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
        if(FEE_NUM_PARTITIONS > fl_PartionNo)
        {
            fl_SectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
            Fee_FillResetInfoData(FEE_INTERRUPTED_JOB_IDLE, fl_PartionNo, fl_SectorId);
            fl_RequestStatus = FLS_WRITE(Fee_ResetInfoAdminData.Address,(uint8 *)&Fee_ResetInfoData.HeadPattern,FEE_RESET_INFO_BLOCK_LEN);  
        }
        else
        {
            /*MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any fucntional impact*/
            FEE_DEBUG_ERROR(FALSE);
        }
    }
    else
    {
        FEE_DEBUG_ERROR(FALSE);
    }
    if(fl_RequestStatus == E_OK)
    {
        #ifdef FEE_TRACE_ENABLE
        FEE_TRACE(WRITE_IDLE_RESET_INFO_JOB_ACCEPTED,0,(uint16)Fee_ResetInfoAdminData.Address);
        #endif
        if(FEE_UINT32_MAX_VALUE > Fee_ResetInfoAdminData.Address)
        {
            Fee_ResetInfoAdminData.Address += FEE_RESET_INFO_BLOCK_LEN;
        }
        else
        {
            FEE_DEBUG_ERROR(FALSE);
        }
        Fee_Job.JobState = FEE_JOB_STATE_UPDT_IDLE_RESET_INFO_WAIT;
    }
    else
    {
        #ifdef FEE_TRACE_ENABLE
        FEE_TRACE(WRITE_IDLE_RESET_INFO_JOB_REJECTED,0,(uint16)Fee_ResetInfoAdminData.Address);
        #endif
        Fee_Job.JobState = FEE_JOB_STATE_IDLE;
        Fee_Job.JobActiveId = FEE_JOB_IDLE;
        if (MEMIF_JOB_OK == Fee_Job.JobResult)
        {
            FEE_NVM_JOB_END_NOTIFICATION();
        }
        else
        {
            FEE_NVM_JOB_ERROR_NOTIFICATION();
        }
    }
}

/**************************************************************************
Function name   : void Fee_JobUpdateWriteIdleResetInfoWait(void)
Arguments       : void
Return type     : void
Description     :  Service to Check the Flash Driver Job Result
**************************************************************************/
static void Fee_JobUpdateWriteIdleResetInfoWait(void)
{
    MemIf_JobResultType fl_FlsJobStatus;
    fl_FlsJobStatus = FLS_GET_JOB_RESULT();
    if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
    {
        Fee_Job.JobState = FEE_JOB_STATE_IDLE;
        Fee_Job.JobActiveId = FEE_JOB_IDLE;
        if (MEMIF_JOB_OK == Fee_Job.JobResult)
        {
            FEE_NVM_JOB_END_NOTIFICATION();
        }
        else
        {
            #ifdef FEE_TRACE_ENABLE
            FEE_TRACE(WRITE_IDLE_RESET_INFO_JOB_FAILED,0,0);
            #endif
            FEE_NVM_JOB_ERROR_NOTIFICATION();
        }
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
    if (FEE_NUM_BLOCKS > Fee_Job.BlockId)
    {
        fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
        if (FEE_NUM_PARTITIONS > fl_PartionNo)
        {
            if(Fee_Partition[fl_PartionNo].Status == FEE_PARTITION_UNINIT)
            {
                Fee_Partition[fl_PartionNo].Status = FEE_PARTITION_INIT_PROGRESS;
                Fee_SectorSearch.ValidSectorId = 0xFFU;
                Fee_SectorSearch.CurrentSectorId = Fee_PartitionConfig[fl_PartionNo].StartingSectorId;
                Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_HEADER_CHECK;
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
                    if(Fee_RetryManagementData.ReadRetryCount > FEE_READ_RETRY_COUNT)
                    {
                        Fee_RetryManagementData.ReadRetryCount = 0;
                        Fee_Job.JobResult = MEMIF_JOB_FAILED;
                        FEE_NVM_JOB_ERROR_NOTIFICATION();
                        Fee_Job.JobActiveId = FEE_JOB_IDLE;
                        Fee_Job.JobState = FEE_JOB_STATE_IDLE;
                        Fee_Job.RepeatStateMachine = FALSE;
                    }
                    else
                    {
                        Fee_RetryManagementData.ReadRetryCount += 1U;
                        Fee_Job.JobState = FEE_JOB_STATE_READ_HEADER;
                    }
                }
            }
        }
        else 
        {
            FEE_DEBUG_ERROR(FALSE);
            Fee_Job.JobResult = MEMIF_JOB_FAILED;
            FEE_NVM_JOB_ERROR_NOTIFICATION();
            Fee_Job.JobActiveId = FEE_JOB_IDLE;
            Fee_Job.JobState = FEE_JOB_STATE_IDLE;
            Fee_Job.RepeatStateMachine = FALSE;
        }
    }
    else
    {
        FEE_DEBUG_ERROR(FALSE);
        Fee_Job.JobResult = MEMIF_JOB_FAILED;
        FEE_NVM_JOB_ERROR_NOTIFICATION();
        Fee_Job.JobActiveId = FEE_JOB_IDLE;
        Fee_Job.JobState = FEE_JOB_STATE_IDLE;
        Fee_Job.RepeatStateMachine = FALSE;
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
    uint8 fl_PartionNo = 0u;
    uint8 fl_CurrentSectorId = 0u;
    if(FEE_NUM_BLOCKS > Fee_Job.BlockId)
    {
        fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
    }
    else
    {
        DEBUG_ASSERT(FALSE);
    }
    if(FEE_NUM_PARTITIONS > fl_PartionNo)
    {
        fl_CurrentSectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
    }
    else
    {
        DEBUG_ASSERT(FALSE);
    }
    if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
    {
        if(fl_FlsJobStatus == MEMIF_JOB_OK)
        {
            Fee_ResetRetryTimer();
            Fee_RetryManagementData.ReadRetryCount = 0;
            fl_HeaderValidity = Fee_HeaderValidate();
            if(fl_HeaderValidity == FEE_BLOCK_EXIST)
            {
                Fee_Job.JobState = FEE_JOB_STATE_READ_PAYLOAD;
                Fee_Job.RepeatStateMachine = TRUE;
            }
            else
            {
                Fee_TraverseData.TraverseBlockId = Fee_Job.BlockId;
                if(FEE_NUM_OF_SECTORS > fl_CurrentSectorId)
                {
                    Fee_TraverseData.TraverseAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress + FEE_SECTOR_HEADER_SIZE;
                    Fee_TraverseData.EndAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress + Fee_SectorConfig[fl_CurrentSectorId].SectorSize - FEE_SECTOR_FOOTER_SIZE;
                }
                else
                {
                    DEBUG_ASSERT(FALSE);
                }
                Fee_TraverseData.ValidBlockAddress = 0;
                Fee_Job.JobState = FEE_JOB_STATE_TRAVERSE_READ;
                Fee_Job.RepeatStateMachine = TRUE;
            }
        }
        else
        {
            Fee_RetryTimeoutProcess();
            if(Fee_RetryManagementData.ReadRetryCount > FEE_READ_RETRY_COUNT)
            {
                if(FALSE != Fee_RetryManagementData.TimerIsExpired)
                {
                    Fee_ResetRetryTimer();
                    Fee_RetryManagementData.ReadRetryCount = 0;
                    if(FEE_NUM_OF_SECTORS > fl_CurrentSectorId)
                    {
                        Fee_TraverseData.TraverseAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress + FEE_SECTOR_HEADER_SIZE;
                        Fee_TraverseData.EndAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress + Fee_SectorConfig[fl_CurrentSectorId].SectorSize - FEE_SECTOR_FOOTER_SIZE;
                    }
                    else
                    {
                        DEBUG_ASSERT(FALSE);
                    }
                    Fee_TraverseData.TraverseBlockId = Fee_Job.BlockId;
                    Fee_TraverseData.ValidBlockAddress = 0;
                    Fee_Job.JobState = FEE_JOB_STATE_TRAVERSE_READ;
                    Fee_Job.RepeatStateMachine = TRUE;
                }
                else
                {
                    Fee_RetryManagementData.ReadRetryCount = 0U;
                    Fee_Job.JobState = FEE_JOB_STATE_READ_HEADER;
                }
            }
            else
            {
                Fee_RetryManagementData.ReadRetryCount += 1U;
                Fee_Job.JobState = FEE_JOB_STATE_READ_HEADER;
            }
        }
    }
    else
    {
        /* Wait for Next State Machine */
        Fee_Job.RepeatStateMachine = FALSE;
    }
}

/**************************************************************************
Function name   : Fee_JobTraverseRead
Arguments       : void
Return type     : void
Description     : Service to Start Traverse to Find Valid Block
**************************************************************************/
static void Fee_JobTraverseRead(void)
{
    Std_ReturnType fl_RequestStatus;
    if (Fee_TraverseData.TraverseAddress < Fee_TraverseData.EndAddress) /*If Traverse is not completed*/
    {
        fl_RequestStatus = FLS_READ(Fee_TraverseData.TraverseAddress, (uint8 *)&Fee_BlockHeader[0].BlockId, (FEE_HEADER_SIZE << 1));
        if(fl_RequestStatus == E_OK)
        {
            Fee_Job.JobState = FEE_JOB_STATE_TRAVERSE_READ_WAIT;
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
        if (0U != Fee_TraverseData.ValidBlockAddress) /*If Traverse Completed and a Valid Instance Found*/
        {
            if(FEE_NUM_BLOCKS > Fee_TraverseData.TraverseBlockId)
            {
                Fee_BlockInformation[Fee_TraverseData.TraverseBlockId].LatestAddress = Fee_TraverseData.ValidBlockAddress;
            }
            else
            {
                FEE_DEBUG_ERROR(FALSE);
            }
            Fee_Job.JobState = FEE_JOB_STATE_READ_HEADER;
        }
        else /*If Traverse Completed and No Valid Instance Found*/
        {
            if(FEE_NUM_BLOCKS > Fee_TraverseData.TraverseBlockId)
            {
                Fee_BlockInformation[Fee_TraverseData.TraverseBlockId].LatestAddress = 0;
            }
            else
            {
                FEE_DEBUG_ERROR(FALSE);
            }
            Fee_Job.JobResult = MEMIF_JOB_FAILED;
            FEE_NVM_JOB_ERROR_NOTIFICATION();
            Fee_Job.JobActiveId = FEE_JOB_IDLE;
            Fee_Job.JobState = FEE_JOB_STATE_IDLE;
            Fee_Job.RepeatStateMachine = FALSE;
        }
    }  
}

/**************************************************************************
Function name   : Fee_JobTraverseReadWait
Arguments       : void
Return type     : void
Description     : Service to check the Flash driver operation
**************************************************************************/
static void Fee_JobTraverseReadWait(void)
{
    MemIf_JobResultType fl_FlsJobStatus;
    Fee_BlockStatusType fl_BlockValid;
    fl_FlsJobStatus = FLS_GET_JOB_RESULT();
    if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
    {
        if(fl_FlsJobStatus == MEMIF_JOB_OK)
        {
            Fee_ResetRetryTimer();
            Fee_RetryManagementData.ReadRetryCount = 0;
            fl_BlockValid = Fee_HeaderValidate();
            if (fl_BlockValid != FEE_BLOCK_NOT_EXIST)
            {
                if (Fee_BlockHeader[0].BlockId == Fee_TraverseData.TraverseBlockId)
                {
                    if (fl_BlockValid == FEE_BLOCK_EXIST)
                    {
                        Fee_Job.JobState = FEE_JOB_STATE_TRAVERSE_VALIDATE;
                    }
                    else
                    {
                        Fee_TraverseData.TraverseAddress += ((FEE_HEADER_SIZE << 1) + Fee_BlockHeader[0].PayloadLength);
                        Fee_Job.JobState = FEE_JOB_STATE_TRAVERSE_READ;
                    }
                }
                else 
                {
                    Fee_TraverseData.TraverseAddress += ((FEE_HEADER_SIZE << 1) + Fee_BlockHeader[0].PayloadLength);
                    Fee_Job.JobState = FEE_JOB_STATE_TRAVERSE_READ;
                }
            }
            else
            {
                Fee_TraverseData.TraverseAddress += FEE_HEADER_SIZE << 1;
                Fee_Job.JobState = FEE_JOB_STATE_TRAVERSE_READ;
            }
        }
        else
        {
            Fee_RetryTimeoutProcess();
            if(Fee_RetryManagementData.ReadRetryCount > FEE_READ_RETRY_COUNT)
            {
                if(FALSE != Fee_RetryManagementData.TimerIsExpired)
                {
                    Fee_ResetRetryTimer();
                    Fee_RetryManagementData.ReadRetryCount = 0;
                    Fee_TraverseData.TraverseAddress += FEE_HEADER_SIZE << 1;
                    Fee_Job.JobState = FEE_JOB_STATE_TRAVERSE_READ;
                    Fee_Job.RepeatStateMachine = TRUE;
                }
                else
                {
                    Fee_RetryManagementData.ReadRetryCount = 0;
                    Fee_Job.JobState = FEE_JOB_STATE_TRAVERSE_READ;
                }
            }
            else
            {
                Fee_RetryManagementData.ReadRetryCount += 1U;
                Fee_Job.JobState = FEE_JOB_STATE_TRAVERSE_READ;
            }

        }
    }
    else
    {
        Fee_Job.RepeatStateMachine = FALSE;
    }
}

/**************************************************************************
Function name   : Fee_JobTraverseValidate
Arguments       : void
Return type     : void
Description     : Service to validate block
**************************************************************************/
static void Fee_JobTraverseValidate(void)
{
    Std_ReturnType fl_RequestStatus = E_NOT_OK;
    if(FEE_NUM_BLOCKS > Fee_TraverseData.TraverseBlockId)
    {
        fl_RequestStatus = FLS_READ(Fee_TraverseData.TraverseAddress + (FEE_HEADER_SIZE << 1),
                                (uint8 *)&TraverseRead_PayloadBuffer[0], Fee_BlockConfig[Fee_TraverseData.TraverseBlockId].BlockSize);
    }
    else
    {
        FEE_DEBUG_ERROR(FALSE);
    }
    if(fl_RequestStatus == E_OK)
    {
        Fee_Job.JobState = FEE_JOB_STATE_TRAVERSE_VALIDATE_WAIT;
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
Function name   : Fee_JobTraverseValidateWait
Arguments       : void
Return type     : void
Description     : Service to check the Flash driver operation
**************************************************************************/
static void Fee_JobTraverseValidateWait(void)
{
    MemIf_JobResultType fl_FlsJobStatus = MEMIF_JOB_FAILED;
    fl_FlsJobStatus = FLS_GET_JOB_RESULT();
    if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
    {
        if(fl_FlsJobStatus == MEMIF_JOB_OK)
        {
            Fee_ResetRetryTimer();
            Fee_RetryManagementData.ReadRetryCount = 0;
            Fee_TraverseData.ValidBlockAddress = Fee_TraverseData.TraverseAddress; 

            if(FEE_NUM_BLOCKS > Fee_TraverseData.TraverseBlockId)
            {
                
                Fee_TraverseData.TraverseAddress += Fee_BlockConfig[Fee_TraverseData.TraverseBlockId].BlockSize + (FEE_HEADER_SIZE << 1);
            }
            else
            {
                FEE_DEBUG_ERROR(FALSE);
            }
            Fee_Job.JobState = FEE_JOB_STATE_TRAVERSE_READ;
            Fee_Job.RepeatStateMachine = TRUE;
        }
        else 
        {
            Fee_RetryTimeoutProcess();
            if(Fee_RetryManagementData.ReadRetryCount > FEE_READ_RETRY_COUNT)
            {
                if(FALSE != Fee_RetryManagementData.TimerIsExpired)
                {
                    Fee_ResetRetryTimer();
                    Fee_RetryManagementData.ReadRetryCount = 0;
                    if(FEE_NUM_BLOCKS > Fee_TraverseData.TraverseBlockId)
                    {
                        Fee_TraverseData.TraverseAddress += Fee_BlockConfig[Fee_TraverseData.TraverseBlockId].BlockSize + (FEE_HEADER_SIZE << 1);
                    }
                    else
                    {
                        FEE_DEBUG_ERROR(FALSE);
                    }
                    Fee_Job.JobState = FEE_JOB_STATE_TRAVERSE_READ;
                    Fee_Job.RepeatStateMachine = TRUE;
                }
                else
                {
                    Fee_RetryManagementData.ReadRetryCount = 0;
                    Fee_Job.JobState = FEE_JOB_STATE_TRAVERSE_VALIDATE;
                }
            }
            else
            {
                Fee_RetryManagementData.ReadRetryCount += 1U;
                Fee_Job.JobState = FEE_JOB_STATE_TRAVERSE_VALIDATE;
            }
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
            /* If blocks id is not less than num of blocks */
            if(FEE_NUM_BLOCKS <= Fee_BlockHeader[0].BlockId)
            {
                fl_RetVal = FEE_BLOCK_NOT_EXIST;
            }
            else if(Fee_BlockHeader[0].ValidityFlag == FEE_BLOCK_VALIDITY_FLAG_INVALID)
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
    Std_ReturnType fl_RequestStatus = E_NOT_OK;
    if (FEE_NUM_BLOCKS > Fee_Job.BlockId)
    {
        fl_PayLoadAddress = Fee_BlockInformation[Fee_Job.BlockId].LatestAddress + (FEE_HEADER_SIZE << 1) + Fee_Job.Offset;
        fl_RequestStatus = FLS_READ_WITHOUT_BLANKCHECK(fl_PayLoadAddress, (uint8 *)Fee_Job.RamAddress, Fee_Job.Length);
    }
    else 
    {
        FEE_DEBUG_ERROR(FALSE);
    }
    if(fl_RequestStatus == E_OK)
    {
        Fee_Job.JobState = FEE_JOB_STATE_READ_PAYLOAD_WAIT;
        Fee_Job.RepeatStateMachine = FALSE;
    }
    else
    {
        if(Fee_RetryManagementData.ReadRetryCount > FEE_READ_RETRY_COUNT)
        {
            Fee_RetryManagementData.ReadRetryCount = 0;
            Fee_Job.JobResult = MEMIF_JOB_FAILED;
            FEE_NVM_JOB_ERROR_NOTIFICATION();
            Fee_Job.JobActiveId = FEE_JOB_IDLE;
            Fee_Job.JobState = FEE_JOB_STATE_IDLE;
            Fee_Job.RepeatStateMachine = FALSE;
        }
        else
        {
            Fee_RetryManagementData.ReadRetryCount += 1U;
            Fee_Job.JobState = FEE_JOB_STATE_READ_PAYLOAD;
        }
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
            Fee_ResetRetryTimer();
            Fee_RetryManagementData.ReadRetryCount = 0;
            Fee_Job.JobResult = MEMIF_JOB_OK;
            FEE_NVM_JOB_END_NOTIFICATION();
            Fee_Job.JobActiveId = FEE_JOB_IDLE;
            Fee_Job.JobState = FEE_JOB_STATE_IDLE;
            Fee_Job.RepeatStateMachine = FALSE;
        }
        else
        {
            Fee_RetryTimeoutProcess();
            if(Fee_RetryManagementData.ReadRetryCount > FEE_READ_RETRY_COUNT)
            {
                if(FALSE != Fee_RetryManagementData.TimerIsExpired)
                {
                    Fee_ResetRetryTimer();
                    Fee_RetryManagementData.ReadRetryCount = 0;
                    Fee_Job.JobResult = MEMIF_JOB_FAILED;
                    FEE_NVM_JOB_ERROR_NOTIFICATION();
                    Fee_Job.JobActiveId = FEE_JOB_IDLE;
                    Fee_Job.JobState = FEE_JOB_STATE_IDLE;
                    Fee_Job.RepeatStateMachine = FALSE;
                }
                else 
                {
                    Fee_RetryManagementData.ReadRetryCount = 0U;
                    Fee_Job.JobState = FEE_JOB_STATE_READ_PAYLOAD;
                }
            }
            else
            {
                Fee_RetryManagementData.ReadRetryCount += 1U;
                Fee_Job.JobState = FEE_JOB_STATE_READ_PAYLOAD;
            }
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

            case FEE_JOB_STATE_CHECK_WRITE_REQUEST:          
            Fee_JobCheckWriteRequest(); 
            break;

            case FEE_JOB_STATE_UPDT_WRITE_RESET_INFO:
            Fee_JobUpdateWriteResetInfo();
            break;

            case FEE_JOB_STATE_UPDT_WRITE_RESET_INFO_WAIT:
            Fee_JobUpdateWriteResetInfoWait();
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

            case FEE_JOB_STATE_UPDT_IDLE_RESET_INFO:
            Fee_JobUpdateWriteIdleResetInfo();
            break;

            case FEE_JOB_STATE_UPDT_IDLE_RESET_INFO_WAIT:
            Fee_JobUpdateWriteIdleResetInfoWait();
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
            
            case FEE_JOB_STATE_TRAVERSE_READ:
            Fee_JobTraverseRead();
            break;
            
            case FEE_JOB_STATE_TRAVERSE_READ_WAIT:
            Fee_JobTraverseReadWait();
            break;
            
            case FEE_JOB_STATE_TRAVERSE_VALIDATE:
            Fee_JobTraverseValidate();
            break;
            
            case FEE_JOB_STATE_TRAVERSE_VALIDATE_WAIT:
            Fee_JobTraverseValidateWait();
            break;
            
            default:
                /*do nothing*/
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
static boolean Fee_ProcessJobStateMachine(void)
{
    boolean fl_return = FALSE;
    if( (FEE_PARTITION_STATE_IDLE == Fee_Job.PartitionState) && \
        (FEE_SECTOR_SWITCH_STATE_IDLE == Fee_Job.SectorSwitchState) && \
        (FEE_SECTOR_ERASE_STATE_IDLE == Fee_Job.SectorEraseState) )
    {
        fl_return = TRUE;
    }
    else if( (FEE_JOB_READ == Fee_Job.JobActiveId) && \
                ( (FEE_SECTOR_SWITCH_STATE_SUSPENDED == Fee_Job.SectorSwitchState) || \
                 (FEE_SECTOR_ERASE_STATE_SUSPENDED == Fee_Job.SectorEraseState) )
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
Function name   : void Fee_PartitionSectorHeaderCheck(void)
Arguments       : void
Return type     : void
Description     : Sector Header Read init
**************************************************************************/
static void Fee_PartitionSectorHeaderCheck(void)
{
    uint32 fl_SectorHeaderAddress = FEE_NUM_OF_SECTORS;
    Std_ReturnType fl_RequestStatus;
    uint8 fl_CurrentSectorId;
    fl_CurrentSectorId = Fee_SectorSearch.CurrentSectorId;

    if(FEE_NUM_OF_SECTORS > fl_CurrentSectorId)
    {
        fl_SectorHeaderAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress;
    }
    else
    {
        /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */
        FEE_DEBUG_ERROR(FALSE);
    }
    fl_RequestStatus = FLS_BLANK_CHECK(fl_SectorHeaderAddress,FEE_SECTOR_HEADER_SIZE);
    if(fl_RequestStatus == E_OK)
    {
        Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_HEADER_CHECK_WAIT;
        Fee_Job.RepeatStateMachine = FALSE;
    }
    else
    {
        if(Fee_RetryManagementData.BlankCheckRetryCount > FEE_BLANK_CHECK_RETRY_COUNT)
        {
            Fee_RetryManagementData.BlankCheckRetryCount = 0;
            Fee_Job.JobResult = MEMIF_JOB_FAILED;
            FEE_NVM_JOB_ERROR_NOTIFICATION();
            Fee_Job.JobActiveId = FEE_JOB_IDLE;
            Fee_Job.JobState = FEE_JOB_STATE_IDLE;
            Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
            Fee_Job.RepeatStateMachine = FALSE;
        }
        else
        {
            Fee_RetryManagementData.BlankCheckRetryCount += 1U;
            Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_HEADER_CHECK;
        }
    }
}

/**************************************************************************
Function name   : void Fee_PartitionSectorHeaderReadWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result 
**************************************************************************/
static void Fee_PartitionSectorHeaderCheckWait(void)
{
    MemIf_JobResultType fl_FlsJobStatus;
    fl_FlsJobStatus = FLS_GET_JOB_RESULT();
    if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
    {
        if(fl_FlsJobStatus == MEMIF_JOB_OK)
        {
            Fee_SectorSearch.BlankHeader = TRUE;
        }
        else
        {
            Fee_SectorSearch.BlankHeader = FALSE;
        }
        Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_FOOTER_CHECK;
        Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
        /* Wait for Next State Machine */
        Fee_Job.RepeatStateMachine = FALSE;
    }
}

/**************************************************************************
Function name   : void Fee_PartitionSectorHeaderCheck(void)
Arguments       : void
Return type     : void
Description     : Sector Header Read init
**************************************************************************/
static void Fee_PartitionSectorFooterCheck(void)
{
    uint32 fl_SectorFooterAddress = 0U;
    Std_ReturnType fl_RequestStatus;
    uint8 fl_CurrentSectorId;

    fl_CurrentSectorId = Fee_SectorSearch.CurrentSectorId;
    if((FEE_NUM_OF_SECTORS > fl_CurrentSectorId) && (FEE_UINT32_MAX_VALUE > Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress))
    {
        fl_SectorFooterAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress + \
                            Fee_SectorConfig[fl_CurrentSectorId].SectorSize - FEE_SECTOR_FOOTER_SIZE;
    }
    else
    {
        /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */
        FEE_DEBUG_ERROR(FALSE);
    }
    fl_RequestStatus = FLS_BLANK_CHECK(fl_SectorFooterAddress,FEE_SECTOR_HEADER_SIZE);
    if(fl_RequestStatus == E_OK)
    {
        Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_FOOTER_CHECK_WAIT;
        Fee_Job.RepeatStateMachine = FALSE;
    }
    else
    {
        if(Fee_RetryManagementData.BlankCheckRetryCount > FEE_BLANK_CHECK_RETRY_COUNT)
        {
            Fee_RetryManagementData.BlankCheckRetryCount = 0;
            Fee_Job.JobResult = MEMIF_JOB_FAILED;
            FEE_NVM_JOB_ERROR_NOTIFICATION();
            Fee_Job.JobActiveId = FEE_JOB_IDLE;
            Fee_Job.JobState = FEE_JOB_STATE_IDLE;
            Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
            Fee_Job.RepeatStateMachine = FALSE;
        }
        else
        {
            Fee_RetryManagementData.BlankCheckRetryCount += 1U;
            Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_FOOTER_CHECK;
        }
    }
}

/**************************************************************************
Function name   : void Fee_PartitionSectorHeaderReadWait(void)
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result 
**************************************************************************/
static void Fee_PartitionSectorFooterCheckWait(void)
{

    MemIf_JobResultType fl_FlsJobStatus;
    fl_FlsJobStatus = FLS_GET_JOB_RESULT();
    if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
    {
        if(fl_FlsJobStatus == MEMIF_JOB_OK)
        {
            Fee_SectorSearch.BlankFooter = TRUE;
        }
        else
        {
            Fee_SectorSearch.BlankFooter = FALSE;
        }
        Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_HEADER_READ;
        Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
        /* Wait for Next State Machine */
        Fee_Job.RepeatStateMachine = FALSE;
    }
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
    Std_ReturnType fl_RequestStatus = E_NOT_OK;
    uint8 fl_CurrentSectorId;
    fl_CurrentSectorId = Fee_SectorSearch.CurrentSectorId;
    if (FEE_NUM_OF_SECTORS > fl_CurrentSectorId)
    {
        fl_SectorHeaderAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress;
        fl_RequestStatus = FLS_READ(fl_SectorHeaderAddress,(uint8 *)&Fee_SectorHeader.SectorId,FEE_SECTOR_HEADER_SIZE);
    }
    else 
    {
        FEE_DEBUG_ERROR(FALSE);
    }
    if(fl_RequestStatus == E_OK)
    {
        Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_HEADER_READ_WAIT;
        Fee_Job.RepeatStateMachine = FALSE;
    }
    else
    {
        if(Fee_RetryManagementData.ReadRetryCount > FEE_READ_RETRY_COUNT)
        {
            Fee_RetryManagementData.ReadRetryCount = 0;
            Fee_Job.JobResult = MEMIF_JOB_FAILED;
            FEE_NVM_JOB_ERROR_NOTIFICATION();
            Fee_Job.JobActiveId = FEE_JOB_IDLE;
            Fee_Job.JobState = FEE_JOB_STATE_IDLE;
            Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
            Fee_Job.RepeatStateMachine = FALSE;
        }
        else
        {
            Fee_RetryManagementData.ReadRetryCount += 1U;
            Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_HEADER_READ;
        }
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
            Fee_ResetRetryTimer();
            Fee_RetryManagementData.ReadRetryCount = 0;
            Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_FOOTER_READ;
            Fee_Job.RepeatStateMachine = TRUE;
        }
        else
        {
            #ifdef FEE_TRACE_ENABLE
			FEE_TRACE(READ_PARTITION_SEC_HEAD_FAILED,(uint8)Fee_RetryManagementData.ReadRetryCount,Fee_SectorHeader.SectorId);
            #endif
            Fee_RetryTimeoutProcess();
            if(Fee_RetryManagementData.ReadRetryCount > FEE_READ_RETRY_COUNT)
            {
                if(FALSE != Fee_RetryManagementData.TimerIsExpired)
                {
                    Fee_ResetRetryTimer();
                    Fee_RetryManagementData.ReadRetryCount = 0;
                    /* Update the invalid value So Validate sector will take up the Sector Preparation */
                    Fee_SectorHeader.SectorId = 0x5A;
                    Fee_SectorHeader.count = 0x5A;
                    Fee_SectorFooter.SectorId = 0x5A;
                    Fee_SectorFooter.count = 0x5A;
                    Fee_Job.PartitionState = FEE_PARTITION_STATE_VALIDATE_SECTOR;
                    Fee_Job.RepeatStateMachine = TRUE;
                }
                else
                {
                    Fee_RetryManagementData.ReadRetryCount = 0;
                    Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_HEADER_READ;
                }
            }
            else
            {
                Fee_RetryManagementData.ReadRetryCount += 1U;
                Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_HEADER_READ;
            }
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
    Std_ReturnType fl_RequestStatus = E_NOT_OK;
    uint8 fl_SectorId;
    fl_SectorId = Fee_SectorSearch.CurrentSectorId;
    if (FEE_NUM_OF_SECTORS > fl_SectorId)
    {
        fl_SectorFooterAddress = Fee_SectorConfig[fl_SectorId].SectorStartAddress + \
                                    Fee_SectorConfig[fl_SectorId].SectorSize - FEE_SECTOR_FOOTER_SIZE;

        fl_RequestStatus = FLS_READ(fl_SectorFooterAddress,(uint8 *)&Fee_SectorFooter.SectorId,FEE_SECTOR_FOOTER_SIZE);
    }
    else 
    {
        FEE_DEBUG_ERROR(FALSE);
    }
    if(fl_RequestStatus == E_OK)
    {
        Fee_Job.PartitionState = FEE_PARTITION_STATE_WAIT_SECTOR_FOOTER_READ;
        Fee_Job.RepeatStateMachine = FALSE;
    }
    else
    {
        if(Fee_RetryManagementData.ReadRetryCount > FEE_READ_RETRY_COUNT)
        {
            Fee_RetryManagementData.ReadRetryCount = 0;
            /* Footer Read failed */
            Fee_Job.JobResult = MEMIF_JOB_FAILED;
            FEE_NVM_JOB_ERROR_NOTIFICATION();
            Fee_Job.JobActiveId = FEE_JOB_IDLE;
            Fee_Job.JobState = FEE_JOB_STATE_IDLE;
            Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
            Fee_Job.RepeatStateMachine = FALSE;
        }
        else
        {
            Fee_RetryManagementData.ReadRetryCount += 1U;
            Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_FOOTER_READ;
        }
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
            Fee_ResetRetryTimer();
            Fee_RetryManagementData.ReadRetryCount = 0U;
            Fee_Job.PartitionState = FEE_PARTITION_STATE_VALIDATE_SECTOR;
            Fee_Job.RepeatStateMachine = TRUE;
        }
        else
        {
            #ifdef FEE_TRACE_ENABLE
		    FEE_TRACE(READ_PARTITION_SEC_FOOT_FAILED,(uint8)Fee_RetryManagementData.ReadRetryCount,Fee_SectorHeader.SectorId);
            #endif 
            Fee_RetryTimeoutProcess();
            if(Fee_RetryManagementData.ReadRetryCount > FEE_READ_RETRY_COUNT)
            {
                if(FALSE != Fee_RetryManagementData.TimerIsExpired)
                {
                    Fee_ResetRetryTimer();
                    Fee_RetryManagementData.ReadRetryCount = 0U;
                    /* Update the invalid value So Validate sector will take up the Sector Preparation */
                    Fee_SectorHeader.SectorId = 0x5A;
                    Fee_SectorHeader.count = 0x5A;
                    Fee_SectorFooter.SectorId = 0x5A;
                    Fee_SectorFooter.count = 0x5A;
                    Fee_Job.PartitionState = FEE_PARTITION_STATE_VALIDATE_SECTOR;
                    Fee_Job.RepeatStateMachine = TRUE;
                }
                else
                {
                    Fee_RetryManagementData.ReadRetryCount = 0;
                    Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_HEADER_READ;
                }
            }
            else
            {
                Fee_RetryManagementData.ReadRetryCount += 1U;
                Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_FOOTER_READ;
            }
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
    if((FEE_NUM_PARTITIONS > PartitionNo) && (FEE_NUM_OF_SECTORS > SectorNo))
    {
        if(Fee_Job.JobActiveId != FEE_JOB_READ)
        {
            Fee_Partition[PartitionNo].EraseSectorId = SectorNo;
            Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_UPDT_RESET_INFO;
        }
        else
        {
            /* MISRA C-2012 Rule 10.3 : Calculated Values of Fee_PartitionPendingSectorErase[PartitionNo].SectorEraseFlag[SectorNo] and TRUE were well within the range.It will not have any functional impact */
            Fee_PartitionPendingSectorErase[PartitionNo].SectorEraseFlag[SectorNo] = TRUE;
            Fee_PartitionPendingSectorErase[PartitionNo].NumberOfSectorsToErase++;
            Fee_PartitionPendingSectorErase[PartitionNo].SectorEraseEnable = TRUE;
        }
    }
}

/**************************************************************************
Function name   : Fee_PrepareDifEraseSector
Arguments       : PartitionNo, SectorNo
Return type     : void
Description     : Service to Prepare Differed Erase
**************************************************************************/
static void Fee_PrepareDifEraseSector(uint8 PartitionNo, uint8 SectorNo)
{
    if((FEE_NUM_PARTITIONS > PartitionNo) && (FEE_NUM_OF_SECTORS > SectorNo))
    {
        /* MISRA C-2012 Rule 10.3 : Calculated Values of SectorEraseFlag[SectorNo] and TRUE were well within the range.It will not have any functional impact */
        Fee_PartitionPendingSectorErase[PartitionNo].SectorEraseFlag[SectorNo] = TRUE; 
        Fee_PartitionPendingSectorErase[PartitionNo].NumberOfSectorsToErase++;  
        Fee_PartitionPendingSectorErase[PartitionNo].SectorEraseEnable = TRUE;
    }
    else
    {
        /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */
        FEE_DEBUG_ERROR(FALSE);
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
    if (FEE_NUM_PARTITIONS > PartitionNo)
    {
        if (FEE_NUM_OF_SECTORS > SectorNo)
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
                /* MISRA C-2012 Rule 10.3 : Calculated Values of Fee_PartitionSectorPendingHeaderWrite[PartitionNo].HeaderWritePending and TRUE were well within the range.It will not have any functional impact */
                Fee_PartitionSectorPendingHeaderWrite[PartitionNo].HeaderWritePending = TRUE;
                Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
            }
        }
        else 
        {
            FEE_DEBUG_ERROR(FALSE);
        }
    }
    else 
    {
        FEE_DEBUG_ERROR(FALSE);
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
    uint8 fl_EndSectorId;
    uint8 fl_sectorId;
    uint8 fl_CurrentSectorId;
    uint8 fl_SectorCount;
    boolean fl_SectorValid;
    boolean fl_SectorEmpty;

    fl_SectorValid = FALSE;
    fl_SectorEmpty = FALSE;
    if (FEE_NUM_BLOCKS > Fee_Job.BlockId)
    {
        fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
        if (FEE_NUM_PARTITIONS > fl_PartionNo)
        {
            if ((FALSE != Fee_SectorSearch.BlankHeader) && (FALSE != Fee_SectorSearch.BlankFooter))
            {
                /* Both Fee_SectorSearch.BlankHeader and Fee_SectorSearch.BlankFooter are True,
                    So Header and footer is blank. Hence marking this sector as Erased.
                */
                fl_SectorEmpty = TRUE;
            }
            if (FALSE == Fee_SectorSearch.BlankHeader)
            {
                /* Header is not balnk So we are checking for Footer blank*/
                if (FALSE == Fee_SectorSearch.BlankFooter)
                {
                    /* Both Header and Footer is not blank, we are validating Header and footer*/
                    if(Fee_SectorHeader.SectorId == (uint8)~Fee_SectorFooter.SectorId)
                    {
                        if(Fee_SectorHeader.count == (uint8)~Fee_SectorFooter.count)
                        {
                            /* Sector Header and footer are matched with inverse pattern
                                For additional check we are validating Fee_SectorHeader.SectorId against maximum available Sector
                            */
                            if(FEE_NUM_OF_SECTORS > Fee_SectorHeader.SectorId)
                            {
                                /* All verifications are passed. Hence marking this Sector as Valid.*/
                                fl_SectorValid = TRUE;
                            }
                        }
                    }
                }
            }
            if(FALSE == fl_SectorEmpty)
            {
                /* Sector is not empty, we are checking again for validity*/
                if(FALSE != fl_SectorValid)
                {
                    /* Sector is valid, We are further processing this sector to 
                    decide about active Sector(CurrentSectorId)*/
                    if(Fee_SectorSearch.ValidSectorId != 0xFFU)
                    {
                        /*Both Sector is valid, As per design always only one active sector will be available
                        Since both sector is valid, Sector switch is not completed.
                        So, Do Nothing, Reset Info Process will handle this case to erase one sector 
                        and repeat Sector switch.
                        */
                    }
                    else
                    {
                        Fee_SectorSearch.ValidSectorId = Fee_SectorHeader.SectorId;
                        Fee_SectorSearch.count = Fee_SectorHeader.count;
                    }
                }
                else
                {
                    /* Check the current partition has interrupted job, if so proceed for Erase check   
                        Use case :
                            If the reset has happened when the Fls driver is erasing the sector, 
                            then this sector will be identified as invalid and it will be covered in this logic.

                            In case of use case, Driver has not yet started the operation, still sector needs to be erased, the same will be taken in checking of Reset data at finalising valid sector logic.
                    */
                    if(FEE_SECTOR_ERASE_JOB_INTERRUPTED == Fee_InterruptedJobAdminData[fl_PartionNo].InterruptedJob )
                    {
                        /* Check this sector is interrupted with Sector erase sequence, 
                        if so queue this sector for erase
                        */
                        if(Fee_SectorSearch.CurrentSectorId == Fee_InterruptedJobAdminData[fl_PartionNo].InterruptedJobSectorId)
                        {
                            /* This sector is verified as interrupted sector erase sector, 
                            So queueing this sector for sector Erase.
                            */
                            Fee_PrepareEraseSector(fl_PartionNo, Fee_SectorSearch.CurrentSectorId);
                        }
                    }
                }
            }
            /* Action has been taken for read sector, traversing through partition until final sector
            Although only two sector for one partition is realised and tested.
            */
            fl_StartSectorId = Fee_PartitionConfig[fl_PartionNo].StartingSectorId;
            fl_EndSectorId = Fee_PartitionConfig[fl_PartionNo].StartingSectorId + 1U;
            fl_CurrentSectorId = Fee_SectorSearch.CurrentSectorId;
            fl_SectorCount = fl_CurrentSectorId - fl_StartSectorId + 1U;
            if(Fee_PartitionConfig[fl_PartionNo].NumberOfSectors  > fl_SectorCount )
            {
                /* Partition Traverse is not completed initiating  read for next Sector*/
                if(FALSE != fl_SectorEmpty)
                {
                    Fee_SectorSearch.StartSectorHealth = FEE_SECTOR_EMPTY;
                }
                else if(FALSE != fl_SectorValid)
                {
                    Fee_SectorSearch.StartSectorHealth = FEE_SECTOR_VALID;
                }
                else
                {
                    Fee_SectorSearch.StartSectorHealth = FEE_SECTOR_INVALID;
                }
                Fee_SectorSearch.CurrentSectorId = fl_CurrentSectorId + 1U;
                Fee_Job.PartitionState = FEE_PARTITION_STATE_SECTOR_HEADER_CHECK;
                Fee_Job.RepeatStateMachine = TRUE;
            }
            else
            {
                /* Traversed all the sectors in this partition, finalysing sector and partition states
                with Reset info for Sectors
                */
                if(FALSE != fl_SectorEmpty)
                {
                /* No Valid sector is found initiating erase for starting sector */
                    Fee_SectorSearch.EndSectorHealth = FEE_SECTOR_EMPTY;
                }
                else if(FALSE != fl_SectorValid)
                {
                    Fee_SectorSearch.EndSectorHealth = FEE_SECTOR_VALID;
                }
                else
                {
                    Fee_SectorSearch.EndSectorHealth = FEE_SECTOR_INVALID;
                }
                    /* Check if any backlog operations for Sector switch or Sector Erase 
                        over multiple resets. If so take actions accordingly
                    */
                    
                    /* Use case: 
                        Sector switch and Sector erase are supposed to be happened consequetively
                        (unless there is a maintanance/pending reset from previous power cycles)

                        Reset info design is to store the Sector switch start at the beginning of sector switch
                        and after copying all blocks, while placing the sector erase implicitly clearing the sector switch pending operation.
                        
                        Before starting sector switch, we are processing pending sector erase and 
                        before accepting write requests also we are processing pending erase requests.

                        In short, For a partition, it is not possible to have both sector switch and sector erase pending operations

                    */
                    
                    /* Use case: 
                        In case of both sector are valid,
                            if there is a reset after copying the blocks in sector switch and before placing Reset info for Erase, 
                            or during Reset info for erase. 
                            Reset info will have Sector switch as pending till erase is registerd as per Reset info design.
                            this will be covered in condition check of FEE_SECTORSWITCH_JOB_INTERRUPTED
                            
                            If the sector switch is cleared, then Sector erase will be set in Reset info. 
                            this will be covered in condition check of FEE_SECTOR_ERASE_JOB_INTERRUPTED
                    */
                    
                    /* Checking for Sector erase interruption job in this partition*/
                if(FEE_SECTOR_ERASE_JOB_INTERRUPTED == Fee_InterruptedJobAdminData[fl_PartionNo].InterruptedJob )
                {
                    /* If sector Erase job is interrupted, interrupted job sector id is erasing sector id.
                    So, we have to mark the other sector id as valid sector ID.
                    Since Fee supports only two sectors per partition we are checking interrupted job id against partitions starting id
                    */
                    if(Fee_InterruptedJobAdminData[fl_PartionNo].InterruptedJobSectorId == Fee_PartitionConfig[fl_PartionNo].StartingSectorId)
                    {
                        /*  if the interrupted job sector ID is starting sector ID marking other sector as vald sector ID*/
                        Fee_SectorSearch.ValidSectorId = Fee_PartitionConfig[fl_PartionNo].StartingSectorId + 1U;
                    }
                    else
                    {
                        /* If the interrupted job sector id is not starting sector id, marking starting sector as valid sector id*/
                        Fee_SectorSearch.ValidSectorId = Fee_PartitionConfig[fl_PartionNo].StartingSectorId;
                    }
                    /* Sector erase is interrupted, It is not possible to use this sector, So Queueing the erase for interrupted job sector id*/
                    Fee_PrepareEraseSector(fl_PartionNo, Fee_InterruptedJobAdminData[fl_PartionNo].InterruptedJobSectorId);
                }
                    /* Checking for Sector switch interruption in this partition. */
                if(FEE_SECTORSWITCH_JOB_INTERRUPTED == Fee_InterruptedJobAdminData[fl_PartionNo].InterruptedJob )
                {
                    /* we are in middle of sector switch, so making interrupted job id as valid sector id. */
                    Fee_SectorSearch.ValidSectorId = Fee_InterruptedJobAdminData[fl_PartionNo].InterruptedJobSectorId;
                    /* The other sector needs to be erased. */
                    if(Fee_InterruptedJobAdminData[fl_PartionNo].InterruptedJobSectorId == Fee_PartitionConfig[fl_PartionNo].StartingSectorId)
                    {
                        /* If the interrupted job sector id is starting sector id, the next sector id needs to be erased*/
                        fl_sectorId =  Fee_PartitionConfig[fl_PartionNo].StartingSectorId + 1U;
                    }
                    else
                    {
                        /* If the interrupted job sector id is starting sector id, the starting sector id needs to be erased*/
                        fl_sectorId = Fee_PartitionConfig[fl_PartionNo].StartingSectorId;
                    }
                    Fee_PrepareEraseSector(fl_PartionNo, fl_sectorId);
                }
                if(FEE_WRITE_JOB_INTERRUPTED == Fee_InterruptedJobAdminData[fl_PartionNo].InterruptedJob )
                {
                    /* If a write job is interrupted, we need to force the sector switch, 
                    This use case does not influence in decision of valid sector/Eraseing a sector. 
                    So 'Do Nothing' here.*/
                    Fee_SectorSearch.ValidSectorId = Fee_InterruptedJobAdminData[fl_PartionNo].InterruptedJobSectorId;
                }
                if(FEE_INTERRUPTED_JOB_IDLE == Fee_InterruptedJobAdminData[fl_PartionNo].InterruptedJob )
                {
                        /* There is no interrupted job detected, We are good to go with already derived valid sector
                        So 'Do Nothing' here.*/
                   if(0xFFU == Fee_SectorSearch.ValidSectorId)
                   {
                        if( (Fee_SectorSearch.StartSectorHealth == FEE_SECTOR_EMPTY) &&
                            (Fee_SectorSearch.EndSectorHealth == FEE_SECTOR_EMPTY) )
                        {
                            /*Do Nothing*/
                        }
                        else
                        {
                            if(Fee_SectorSearch.StartSectorHealth == FEE_SECTOR_INVALID)
                            {
                                Fee_SectorSearch.ValidSectorId = fl_StartSectorId;
                            }
                            if(Fee_SectorSearch.EndSectorHealth == FEE_SECTOR_INVALID)
                            {
                                Fee_SectorSearch.ValidSectorId = fl_EndSectorId;
                            }
                        }
                   }
                }
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
                    if (FEE_NUM_OF_SECTORS > fl_CurrentSectorId)
                    {
                        Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress + FEE_SECTOR_HEADER_SIZE;
                    }
                    else 
                    {
                        FEE_DEBUG_ERROR(FALSE);
                    }
                    Fee_Job.PartitionState = FEE_PARTITION_STATE_BLOCK_READ_HEADER;
                    Fee_Job.RepeatStateMachine = TRUE;
                }
                #ifdef FEE_TRACE_ENABLE
                FEE_TRACE(PART_TRAVERSE_RESULT,fl_PartionNo,(uint16)Fee_Partition[fl_PartionNo].CurrentSectorId);
                FEE_TRACE(PART_RESET_INFO, Fee_InterruptedJobAdminData[fl_PartionNo].InterruptedJob,(uint16)Fee_InterruptedJobAdminData[fl_PartionNo].InterruptedJobSectorId);
                #endif
            }
        }
        else
        {
            FEE_DEBUG_ERROR(FALSE);
        }
    }
    else
    {
        FEE_DEBUG_ERROR(FALSE);
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
    Std_ReturnType fl_RequestStatus = E_NOT_OK;
    uint8 fl_CurrentSectorId;
    if (FEE_NUM_BLOCKS > Fee_Job.BlockId)
    {
        fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
        if (FEE_NUM_PARTITIONS > fl_PartionNo)
        {
            fl_CurrentSectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;

            Fee_SectorHeader.SectorId = fl_CurrentSectorId;
            Fee_SectorHeader.count = Fee_Partition[fl_PartionNo].count;
            Fee_SectorHeader.Reserved1 = 0xFFFFU;
            Fee_SectorHeader.Reserved2 = 0xFFFFU;
            Fee_SectorHeader.Reserved3 = 0xFFFFU;
            if (FEE_NUM_OF_SECTORS > fl_CurrentSectorId)
            {
                fl_SectorStartAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress;
                fl_RequestStatus = FeeExt_Write_1(fl_SectorStartAddress,(uint8 *)&Fee_SectorHeader.SectorId,FEE_SECTOR_HEADER_SIZE);
            }
            else 
            {
                FEE_DEBUG_ERROR(FALSE);
            }
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
        else 
        {
            FEE_DEBUG_ERROR(FALSE);
        }
    }
    else 
    {
        FEE_DEBUG_ERROR(FALSE);
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
    if (FEE_NUM_BLOCKS > Fee_Job.BlockId)
    {
        fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
        if (FEE_NUM_PARTITIONS > fl_PartionNo)
        {        
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
        else 
        {
            FEE_DEBUG_ERROR(FALSE);
        }
    }
    else 
    {
        FEE_DEBUG_ERROR(FALSE);
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
    uint32 fl_FooterStartAddress = 0xFFFFFFFFUL;
    uint8 fl_PartionNo = 0xFFU;
    Std_ReturnType fl_RequestStatus = E_NOT_OK;
    uint8 fl_CurrentSectorId = 0xFFU;
    if (FEE_NUM_BLOCKS > Fee_Job.BlockId)
    {
        fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
        if (FEE_NUM_PARTITIONS > fl_PartionNo)
        {
            fl_CurrentSectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;

            if (FEE_NUM_OF_SECTORS > fl_CurrentSectorId)
            {
                Fee_SectorFooter.SectorId = (uint8)~fl_CurrentSectorId;
                Fee_SectorFooter.count = (uint8)~Fee_Partition[fl_PartionNo].count;
                Fee_SectorFooter.Reserved1 = 0U;
                Fee_SectorFooter.Reserved2 = 0U;
                Fee_SectorFooter.Reserved3 = 0U;

                fl_FooterStartAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress + \
                                        Fee_SectorConfig[fl_CurrentSectorId].SectorSize - FEE_SECTOR_FOOTER_SIZE;

                fl_RequestStatus = FeeExt_Write_1(fl_FooterStartAddress,(uint8 *)&Fee_SectorFooter.SectorId,FEE_SECTOR_FOOTER_SIZE);
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
            else
            {
                FEE_DEBUG_ERROR(FALSE);
                Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
            }
        }
        else
        {
            FEE_DEBUG_ERROR(FALSE);
            Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
        }
    }
    else
    {
        FEE_DEBUG_ERROR(FALSE);
        Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
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
    if (FEE_NUM_BLOCKS > Fee_Job.BlockId)
    {
        fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
        if (FEE_NUM_PARTITIONS > fl_PartionNo)
        {
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
        else 
        {
            FEE_DEBUG_ERROR(FALSE);
        }
    }
    else 
    {
        FEE_DEBUG_ERROR(FALSE);
    }
}

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
    if (FEE_NUM_BLOCKS > Fee_Job.BlockId)
    {
        fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
        if (FEE_NUM_PARTITIONS > fl_PartionNo)
        {
            fl_RequestStatus = FLS_READ(Fee_Partition[fl_PartionNo].NextFreeAddress, (uint8 *)&Fee_BlockHeader[0].BlockId, (FEE_HEADER_SIZE << 1));
            if(fl_RequestStatus == E_OK)
            {
                Fee_Job.PartitionState = FEE_PARTITION_STATE_BLOCK_READ_HEADER_WAIT;
                Fee_Job.RepeatStateMachine = FALSE;
            }
            else
            {
                if(Fee_RetryManagementData.ReadRetryCount > FEE_READ_RETRY_COUNT)
                {
                    Fee_RetryManagementData.ReadRetryCount = 0;
                    Fee_Partition[fl_PartionNo].FailSafeTraverseAddress = Fee_Partition[fl_PartionNo].NextFreeAddress + FEE_PAGE_SIZE;  
                    fl_CurrentSectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
                    if(FEE_NUM_OF_SECTORS > fl_CurrentSectorId)
                    {
                        Fee_Partition[fl_PartionNo].FailSafeEndAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress + \
                                                                        Fee_SectorConfig[fl_CurrentSectorId].SectorSize - FEE_SECTOR_FOOTER_SIZE - 1U;
                    }
                    else
                    {
                        /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */
                        FEE_DEBUG_ERROR(FALSE);
                    }
                    Fee_Job.PartitionState = FEE_PARTITION_SECTOR_BLOCK_READ_FAIL_SAFE_TRIGGER;
                    Fee_Job.RepeatStateMachine = FALSE;
                }
                else
                {
                    Fee_RetryManagementData.ReadRetryCount += 1U;
                    Fee_Job.PartitionState = FEE_PARTITION_STATE_BLOCK_READ_HEADER;
                    Fee_Job.RepeatStateMachine = FALSE;
                }
            }
        }
        else 
        {
            FEE_DEBUG_ERROR(FALSE);
        }
    }
    else 
    {
        FEE_DEBUG_ERROR(FALSE);
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
    if (FEE_NUM_BLOCKS > Fee_Job.BlockId)
    {
        fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
        fl_FlsJobStatus = FLS_GET_JOB_RESULT();
        if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
        {
            if(fl_FlsJobStatus == MEMIF_JOB_OK)
            {
                Fee_ResetRetryTimer();
                Fee_RetryManagementData.ReadRetryCount = 0;
                Fee_Job.PartitionState = FEE_PARTITION_STATE_BLOCK_READ_HEADER_VALIDATE;
                Fee_Job.RepeatStateMachine = TRUE;
            }
            else
            {
                #ifdef FEE_TRACE_ENABLE
    			FEE_TRACE(READ_PARTITION_BLOCK_HEAD_FAILED,(uint8)Fee_RetryManagementData.ReadRetryCount,Fee_Job.BlockId);
                #endif 
                Fee_RetryTimeoutProcess();
                if(Fee_RetryManagementData.ReadRetryCount > FEE_READ_RETRY_COUNT)
                {
                    if(FALSE != Fee_RetryManagementData.TimerIsExpired)
                    {
                        Fee_ResetRetryTimer();
                        Fee_RetryManagementData.ReadRetryCount = 0;
                        if(FEE_NUM_PARTITIONS > fl_PartionNo)
                        {
                            Fee_Partition[fl_PartionNo].FailSafeTraverseAddress = Fee_Partition[fl_PartionNo].NextFreeAddress + FEE_PAGE_SIZE;  
                            fl_CurrentSectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
                            if(FEE_NUM_OF_SECTORS > fl_CurrentSectorId)
                            {
                                Fee_Partition[fl_PartionNo].FailSafeEndAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress + \
                                                                                Fee_SectorConfig[fl_CurrentSectorId].SectorSize - FEE_SECTOR_FOOTER_SIZE - 1U;
                            }
                            else
                            {
                                /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */
                                FEE_DEBUG_ERROR(FALSE);
                            }
                        }
                        else
                        {
                        /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */    
                        FEE_DEBUG_ERROR(FALSE);
                        }
                        Fee_Job.PartitionState = FEE_PARTITION_SECTOR_BLOCK_READ_FAIL_SAFE_TRIGGER;
                        Fee_Job.RepeatStateMachine = TRUE;
                    }
                    else
                    {
                        Fee_RetryManagementData.ReadRetryCount = 0U;
                        Fee_Job.PartitionState = FEE_PARTITION_STATE_BLOCK_READ_HEADER;
                        Fee_Job.RepeatStateMachine = FALSE;
                    }

                }
                else
                {
                    Fee_RetryManagementData.ReadRetryCount += 1U;
                    Fee_Job.PartitionState = FEE_PARTITION_STATE_BLOCK_READ_HEADER;
                    Fee_Job.RepeatStateMachine = FALSE;
                }
            }
        }
        else
        {
            /* Wait for Next State Machine */
            Fee_Job.RepeatStateMachine = FALSE;
        }
    }
    else
    {
        FEE_DEBUG_ERROR(FALSE);
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
    
    boolean EraseState;
    if (FEE_NUM_BLOCKS > Fee_Job.BlockId)
    {
        fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
        if (FEE_NUM_PARTITIONS > fl_PartionNo)
        {
            fl_CurrentSectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
            if (FEE_NUM_OF_SECTORS > fl_CurrentSectorId)
            {
                fl_BlockId = Fee_BlockHeader[0].BlockId;

                Fee_PrefillHeader();
                EraseState = MemLib_MemCmp ((const void *)&ErasedBlock, (const void *)&Fee_BlockHeader, sizeof(Arr_Fee_BlockHeaderType) );
                

                if(FALSE == EraseState)
                {
                    fl_BlockValid = Fee_HeaderValidate();
                    if((fl_BlockValid == FEE_BLOCK_EXIST) && (fl_BlockId < FEE_NUM_BLOCKS))
                    {
                        Fee_BlockInformation[fl_BlockId].LatestAddress = Fee_Partition[fl_PartionNo].NextFreeAddress;
                        Fee_Partition[fl_PartionNo].NextFreeAddress =  Fee_Partition[fl_PartionNo].NextFreeAddress + Fee_BlockConfig[fl_BlockId].BlockSize + (FEE_HEADER_SIZE << 1);
                        Fee_Job.PartitionState = FEE_PARTITION_STATE_BLOCK_READ_HEADER;
                        Fee_Job.RepeatStateMachine = TRUE;
                    }
                    else if (((fl_BlockValid == FEE_BLOCK_CANCELLED) || (fl_BlockValid == FEE_BLOCK_INVALIDATED)) && (fl_BlockId < FEE_NUM_BLOCKS))
                    {
                        Fee_Partition[fl_PartionNo].NextFreeAddress =  Fee_Partition[fl_PartionNo].NextFreeAddress + Fee_BlockConfig[fl_BlockId].BlockSize + (FEE_HEADER_SIZE << 1);
                        Fee_Job.PartitionState = FEE_PARTITION_STATE_BLOCK_READ_HEADER;
                        Fee_Job.RepeatStateMachine = TRUE;
                    }
                    else
                    {
                        Fee_Partition[fl_PartionNo].FailSafeTraverseAddress = Fee_Partition[fl_PartionNo].NextFreeAddress; 
                        Fee_Partition[fl_PartionNo].FailSafeEndAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress + \
                                                                            Fee_SectorConfig[fl_CurrentSectorId].SectorSize - FEE_SECTOR_FOOTER_SIZE - 1U;
                        /* MISRA C-2012 Rule 10.3 : Calculated Values of Fee_Partition[fl_PartionNo].PossibleInterruptWrite and TRUE were well within the range.It will not have any functional impact */
                        Fee_Partition[fl_PartionNo].PossibleInterruptWrite = TRUE;
                        Fee_Job.PartitionState = FEE_PARTITION_SECTOR_BLOCK_READ_FAIL_SAFE_TRIGGER;
                        Fee_Job.RepeatStateMachine = TRUE;
                    }
                }
                else
                {
                    /* Traverse has completed. So we are checking the reset info for interrupted Sector switch or interrupted operation.
                    */
                    /*
                    Interrupted write use cases : 
                        In most cases, if there is any resets while writing in FlsDrv fails, traverse will get initiated.
                        In case of resets between the response and requests window, validation will get failed, traverse will get initiated.
                        Incase of block write is completed but reset info is not updated, Traverse will not get initiated. Still forcing sector switch
                    Interrupted Sector Switch use cases :
                        In Fee_ValidateSector, interrupted sector switch will be detected, partially copied sector(Invalid) will be queued to erase.
                        Also this has to be initiated for forced sector switch. After setting the Valid sector,
                        Block traversing of old sector(Valid, untouched) will lead here. Forcing sector switch to prepare for next write requests.
                        
                    To consolidate, we are forcing sector switch if the interrupted operation is not erase. for Erase no action required.
                    As this has been taken care in Fee_ValidateSector
                    */
                    if(FEE_INTERRUPTED_JOB_IDLE != Fee_InterruptedJobAdminData[fl_PartionNo].InterruptedJob )
                    {
                        if(FEE_SECTOR_ERASE_JOB_INTERRUPTED != Fee_InterruptedJobAdminData[fl_PartionNo].InterruptedJob )
                        {
                            Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress + \
                            Fee_SectorConfig[fl_CurrentSectorId].SectorSize - FEE_SECTOR_FOOTER_SIZE;
                        }
                    }
                    Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
                    Fee_Job.RepeatStateMachine = TRUE;
                }
            }
            else 
            {
                FEE_DEBUG_ERROR(FALSE);
                Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
            }
        }
        else 
        {
            FEE_DEBUG_ERROR(FALSE);
            Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
        }
    }
    else 
    {
        FEE_DEBUG_ERROR(FALSE);
        Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE;
    }
}

/**************************************************************************
Function name   : Fee_PartitionSectorBlockReadFailSafeTrigger
Arguments       : void
Return type     : void
Description     : Service to initiate Fail Safe Search Process
**************************************************************************/
/*MISRA C-2012 Directive 4.5 : Function name and macro name were differentiated using uppercase and underscore. It will not have any functional impact*/
static void Fee_PartitionSectorBlockReadFailSafeTrigger(void)
{
    uint8 fl_PartionNo = 0U;
    uint8 fl_CurrentSectorId;
    if(FEE_NUM_BLOCKS > Fee_Job.BlockId)
    {
        fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
    }
    else
    {
        FEE_DEBUG_ERROR(FALSE);
    }
    if(FEE_NUM_PARTITIONS > fl_PartionNo)
    {
        if(Fee_Partition[fl_PartionNo].FailSafeTraverseAddress < Fee_Partition[fl_PartionNo].FailSafeEndAddress) 
        {
            Fee_Partition[fl_PartionNo].FailSafeTraverseAddress = Fee_Partition[fl_PartionNo].FailSafeTraverseAddress + FEE_PAGE_SIZE;
            Fee_Job.PartitionState = FEE_PARTITION_SECTOR_BLOCK_READ_FAIL_SAFE_READ;
        }
        else
        {
            /*
                Traverse is finished after initiating fail safe read. 
                Hence forcing sector switch to self correct the possible errors in current sector
            */
            fl_CurrentSectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
            if((FEE_NUM_OF_SECTORS > fl_CurrentSectorId) && (FEE_UINT32_MAX_VALUE > Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress))
            {
                Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress + \
                                                                Fee_SectorConfig[fl_CurrentSectorId].SectorSize - FEE_SECTOR_FOOTER_SIZE;
            }
            else
            {
                /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */
                FEE_DEBUG_ERROR(FALSE);
            }
            Fee_Job.PartitionState = FEE_PARTITION_STATE_IDLE ;
        }
    }
    else
    {
        FEE_DEBUG_ERROR(FALSE);
    }
}

/**************************************************************************
Function name   : Fee_PartitionSectorBlockReadFailSafeRead
Arguments       : void
Return type     : void
Description     : Service to initiate Fail Safe Search Read
**************************************************************************/
/* MISRA C-2012 Directive 4.5 : Function name and macro name were differentiated using uppercase and underscore. It will not have any functional impact */
static void Fee_PartitionSectorBlockReadFailSafeRead(void)
{
    uint8 fl_PartionNo = 0U;
    Std_ReturnType fl_RequestStatus = 0U;
    if(FEE_NUM_BLOCKS > Fee_Job.BlockId)
    {
        fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
    }
    else
    {
        /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */
        FEE_DEBUG_ERROR(FALSE);
    }
    if(FEE_NUM_PARTITIONS > fl_PartionNo)
    {
        fl_RequestStatus = FLS_READ(Fee_Partition[fl_PartionNo].FailSafeTraverseAddress, 
                                    (uint8 *)&Fee_BlockHeader[0].BlockId, (FEE_HEADER_SIZE<<1));
    }
    else
    {
        FEE_DEBUG_ERROR(FALSE);
    }
    if(fl_RequestStatus == E_OK)
    {
        Fee_Job.PartitionState = FEE_PARTITION_SECTOR_BLOCK_READ_FAIL_SAFE_READ_WAIT;
        Fee_Job.RepeatStateMachine = FALSE;
    }
    else
    {
        if(Fee_RetryManagementData.ReadRetryCount > FEE_READ_RETRY_COUNT)
        {
            Fee_RetryManagementData.ReadRetryCount = 0;
            if(FEE_NUM_PARTITIONS > fl_PartionNo)
            {
                Fee_Partition[fl_PartionNo].FailSafeTraverseAddress = Fee_Partition[fl_PartionNo].FailSafeTraverseAddress + FEE_PAGE_SIZE;
            }
            Fee_Job.RepeatStateMachine = TRUE;
        }
        else
        {
            Fee_RetryManagementData.ReadRetryCount += 1U;
            Fee_Job.PartitionState = FEE_PARTITION_SECTOR_BLOCK_READ_FAIL_SAFE_READ;
        }
    }
}

/**************************************************************************
Function name   : Fee_PartitionSectorBlockReadFailSafeRead
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result
**************************************************************************/
/* MISRA C-2012 Directive 4.5 : Function name and macro name were differentiated using uppercase and underscore. It will not have any functional impact */
static void Fee_PartitionSectorBlockReadFailSafeReadWait(void)
{
    MemIf_JobResultType fl_FlsJobStatus;
    Fee_BlockStatusType fl_HeaderValidity;
    uint8 fl_PartionNo = 0U;
    uint16 fl_TraverseBlockID = Fee_BlockHeader[0].BlockId;
    uint16 fl_TraverseBlockLength = Fee_BlockHeader[0].PayloadLength;

    if(FEE_NUM_BLOCKS > Fee_Job.BlockId)
    {
        fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
    }
    else
    {
        /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */
        FEE_DEBUG_ERROR(FALSE);
    }
    fl_FlsJobStatus = FLS_GET_JOB_RESULT();
    if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
    {
        if(fl_FlsJobStatus == MEMIF_JOB_OK)
        {
            Fee_ResetRetryTimer();
            Fee_RetryManagementData.ReadRetryCount = 0;
            fl_HeaderValidity = Fee_HeaderValidate();
            if(fl_HeaderValidity == FEE_BLOCK_EXIST)
            {
                if(FEE_NUM_BLOCKS > fl_TraverseBlockID)
                {
                    if( (Fee_BlockConfig[fl_TraverseBlockID].BlockSize == fl_TraverseBlockLength) &&
                        (Fee_BlockConfig[fl_TraverseBlockID].PartitionNo == fl_PartionNo) )  
                    {
                        if(FEE_NUM_PARTITIONS > fl_PartionNo)
                        {
                            Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_Partition[fl_PartionNo].FailSafeTraverseAddress;
                        }
                        else
                        {
                            FEE_DEBUG_ERROR(FALSE);
                        }
                        Fee_Job.PartitionState = FEE_PARTITION_STATE_BLOCK_READ_HEADER;
                    }
                    else
                    {
                        Fee_Job.PartitionState = FEE_PARTITION_SECTOR_BLOCK_READ_FAIL_SAFE_TRIGGER;
                    }
                }
                else
                {
                    FEE_DEBUG_ERROR(FALSE);
                }
            }
            else
            {
                Fee_Job.PartitionState = FEE_PARTITION_SECTOR_BLOCK_READ_FAIL_SAFE_TRIGGER;
            }
        }
        else
        {
            #ifdef FEE_TRACE_ENABLE
		    FEE_TRACE(READ_PARTITION_BLOCK_READ_FST_FAILED,(uint8)Fee_RetryManagementData.ReadRetryCount,fl_TraverseBlockID);
            #endif
            Fee_RetryTimeoutProcess();
            if(Fee_RetryManagementData.ReadRetryCount > FEE_READ_RETRY_COUNT)
            {
                if(FALSE != Fee_RetryManagementData.TimerIsExpired)
                {
                    Fee_ResetRetryTimer();
                    Fee_RetryManagementData.ReadRetryCount = 0;
                    Fee_Job.PartitionState = FEE_PARTITION_SECTOR_BLOCK_READ_FAIL_SAFE_TRIGGER;
                    Fee_Job.RepeatStateMachine = TRUE;
                }
                else
                {
                    Fee_RetryManagementData.ReadRetryCount = 0U;
                    Fee_Job.PartitionState = FEE_PARTITION_SECTOR_BLOCK_READ_FAIL_SAFE_READ;
                }
            }
            else
            {
                Fee_RetryManagementData.ReadRetryCount += 1U;
                Fee_Job.PartitionState = FEE_PARTITION_SECTOR_BLOCK_READ_FAIL_SAFE_READ;
            }
        }
        Fee_Job.RepeatStateMachine = TRUE;
    }
    else
    {
        Fee_Job.RepeatStateMachine = FALSE;
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

        case FEE_PARTITION_STATE_SECTOR_HEADER_CHECK:
            Fee_PartitionSectorHeaderCheck();
        break;

        case FEE_PARTITION_STATE_SECTOR_HEADER_CHECK_WAIT:
            Fee_PartitionSectorHeaderCheckWait();
        break;

        case FEE_PARTITION_STATE_SECTOR_FOOTER_CHECK:
            Fee_PartitionSectorFooterCheck();
        break;

        case FEE_PARTITION_STATE_SECTOR_FOOTER_CHECK_WAIT:
            Fee_PartitionSectorFooterCheckWait();
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

        case FEE_PARTITION_SECTOR_BLOCK_READ_FAIL_SAFE_TRIGGER:
            Fee_PartitionSectorBlockReadFailSafeTrigger();
        break;

        case FEE_PARTITION_SECTOR_BLOCK_READ_FAIL_SAFE_READ:
            Fee_PartitionSectorBlockReadFailSafeRead();
        break;

        case FEE_PARTITION_SECTOR_BLOCK_READ_FAIL_SAFE_READ_WAIT:
            Fee_PartitionSectorBlockReadFailSafeReadWait();
        break;

        default:
        /*do nothing*/
        break;
        }
    }
}

/**************************************************************************
Function name   : Fee_JobUpdateEraseResetInfo
Arguments       : void
Return type     : void
Description     : Service to Initiate Reset Info Write
**************************************************************************/
static void Fee_JobUpdateEraseResetInfo(void)
{
    uint8 fl_PartionNo = FEE_NUM_PARTITIONS;
    Std_ReturnType fl_RequestStatus = E_NOT_OK;
    uint8 fl_SectorId = 0xFFU;
    fl_PartionNo = Fee_Job.CurPartition;
    if(FEE_NUM_PARTITIONS > fl_PartionNo)
    {
        fl_SectorId = Fee_Partition[fl_PartionNo].EraseSectorId;
        if(E_OK == Fee_IsResetInfoRangeAvailable())
        {
            Fee_FillResetInfoData(FEE_SECTOR_ERASE_JOB_INTERRUPTED, fl_PartionNo, fl_SectorId);
            fl_RequestStatus = FLS_WRITE(Fee_ResetInfoAdminData.Address,(uint8 *)&Fee_ResetInfoData.HeadPattern,FEE_RESET_INFO_BLOCK_LEN);  
            if(fl_RequestStatus == E_OK)
            {
                #ifdef FEE_TRACE_ENABLE
                FEE_TRACE(ERASE_RESET_INFO_JOB_ACCEPTED,0,(uint16)Fee_ResetInfoAdminData.Address);
                #endif
                if(FEE_UINT32_MAX_VALUE > Fee_ResetInfoAdminData.Address)
                {
                    Fee_ResetInfoAdminData.Address += FEE_RESET_INFO_BLOCK_LEN;
                    Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_UPDT_RESET_INFO_WAIT;
                }
                else
                {
                    FEE_DEBUG_ERROR(FALSE);
                }
            }
            else
            {
                #ifdef FEE_TRACE_ENABLE
                FEE_TRACE(ERASE_RESET_INFO_JOB_REJECTED,0,(uint16)Fee_ResetInfoAdminData.Address);
                #endif
                Fee_Job.JobResult = MEMIF_JOB_FAILED;
                if (FEE_JOB_STATE_CHECK_WRITE_REQUEST == Fee_Job.JobState)
                {
                    FEE_NVM_JOB_ERROR_NOTIFICATION();
                }
                Fee_Job.JobActiveId = FEE_JOB_IDLE;
                Fee_Job.JobState = FEE_JOB_STATE_IDLE;
                Fee_NotifyInternalJobStatus(FEE_END_INTERNAL_JOB);
                Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
            }
        }
    }
    else
    {
     /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */   
        FEE_DEBUG_ERROR(FALSE);
    }
}

/**************************************************************************
Function name   : Fee_JobUpdateEraseResetInfoWait
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result
**************************************************************************/
static void Fee_JobUpdateEraseResetInfoWait(void)
{
    MemIf_JobResultType fl_FlsJobStatus;
    fl_FlsJobStatus = FLS_GET_JOB_RESULT();
    if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
    {
        if(fl_FlsJobStatus != MEMIF_JOB_OK)
        {
            #ifdef FEE_TRACE_ENABLE
            FEE_TRACE(ERASE_RESET_INFO_JOB_FAILED,0,0);
            #endif
            Fee_Job.JobResult = MEMIF_JOB_FAILED;
            if (FEE_JOB_STATE_CHECK_WRITE_REQUEST == Fee_Job.JobState)
            {
                FEE_NVM_JOB_ERROR_NOTIFICATION();
            }
            Fee_Job.JobActiveId = FEE_JOB_IDLE;
            Fee_Job.JobState = FEE_JOB_STATE_IDLE;
            Fee_NotifyInternalJobStatus(FEE_END_INTERNAL_JOB);
            Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
        }
        else
        {
            #ifdef FEE_TRACE_ENABLE
            FEE_TRACE(ERASE_RESET_INFO_JOB_SUCCESS,0,0);
            #endif
            Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_ERASE;
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
    if (FEE_BSS_INTERNAL_NO_LOCK != Fee_Job.ProcessInternalJob)
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
        Std_ReturnType fl_RequestStatus = E_NOT_OK;
        uint8 fl_EraseSectorId;
        fl_PartionNo = Fee_Job.CurPartition;
        if (FEE_NUM_PARTITIONS > fl_PartionNo)
        {
            fl_EraseSectorId = Fee_Partition[fl_PartionNo].EraseSectorId;
            if (FEE_NUM_OF_SECTORS > fl_EraseSectorId)
            {
                fl_EraseAddress = Fee_SectorConfig[fl_EraseSectorId].SectorStartAddress;
                fl_EraseSize = Fee_SectorConfig[fl_EraseSectorId].SectorSize;
                fl_RequestStatus = FLS_ERASE(fl_EraseAddress,fl_EraseSize);
            }
            else 
            {
                FEE_DEBUG_ERROR(FALSE);
            }
        }
        else 
        {
            FEE_DEBUG_ERROR(FALSE);
        }
        if(fl_RequestStatus == E_OK)
        {
            #ifdef FEE_TRACE_ENABLE
            FEE_TRACE(SECTOR_ERASE_ACCEPTED,fl_EraseSectorId,(uint16)fl_EraseAddress);
            #endif
            Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_ERASE_WAIT;
            Fee_Job.RepeatStateMachine = TRUE;
        }
        else
        {
            #ifdef FEE_TRACE_ENABLE
            FEE_TRACE(SECTOR_ERASE_REJECTED,fl_EraseSectorId,(uint16)fl_EraseAddress);
            #endif
            /* Erase Not Success */
            Fee_Job.JobResult = MEMIF_JOB_FAILED;
            Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_UPDT_IDLE_RESET_INFO;
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
    uint8 fl_PartionNo = 0U;
    MemIf_JobResultType fl_FlsJobStatus;

    fl_FlsJobStatus = FLS_GET_JOB_RESULT();
    fl_PartionNo = Fee_Job.CurPartition;
    if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
    {
        if(fl_FlsJobStatus != MEMIF_JOB_OK)
        {
            if(FEE_NUM_PARTITIONS > fl_PartionNo)
            {
                Fee_PrepareDifEraseSector(fl_PartionNo, Fee_Partition[fl_PartionNo].EraseSectorId);
            }
            else
            {
                /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */
                FEE_DEBUG_ERROR(FALSE);
            }
            /* Erase Not Success */
            #ifdef FEE_TRACE_ENABLE
            FEE_TRACE(SECTOR_ERASE_FAILED,0,0);
            #endif
            Fee_Job.JobResult = MEMIF_JOB_FAILED;
        }
        #ifdef FEE_TRACE_ENABLE
        FEE_TRACE(SECTOR_ERASE_COMPLETED,0,0);
        #endif
        Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_UPDT_IDLE_RESET_INFO;
    }
    else
    {
        /* Wait for Next State Machine */
        Fee_Job.RepeatStateMachine = FALSE;
    }
}

/**************************************************************************
Function name   : Fee_SectorEraseWait
Arguments       : void
Return type     : void
Description     : Service to Initiate Reset Info Write Process
**************************************************************************/
static void Fee_JobUpdateEraseIdleResetInfo(void)
{
    uint8 fl_PartionNo = FEE_NUM_PARTITIONS;
    Std_ReturnType fl_RequestStatus = E_NOT_OK;
    uint8 fl_SectorId = 0xFFU;
    fl_PartionNo = Fee_Job.CurPartition;
    if(FEE_NUM_PARTITIONS > fl_PartionNo)
    {
        fl_SectorId = Fee_Partition[fl_PartionNo].EraseSectorId;
        Fee_FillResetInfoData(FEE_INTERRUPTED_JOB_IDLE, fl_PartionNo, fl_SectorId);
        fl_RequestStatus = FLS_WRITE(Fee_ResetInfoAdminData.Address,(uint8 *)&Fee_ResetInfoData.HeadPattern,FEE_RESET_INFO_BLOCK_LEN);  
    }
    else
    {
        /*misra_c_2012_rule_10_5_violation : Value of the macro FALSE used here is within the range. It will not have any fucntional impact*/
        FEE_DEBUG_ERROR(FALSE);
    }
    if(fl_RequestStatus == E_OK)
    {
        #ifdef FEE_TRACE_ENABLE
        FEE_TRACE(ERASE_IDLE_RESET_INFO_JOB_ACCEPTED,0,(uint16)Fee_ResetInfoAdminData.Address);
        #endif
        if(FEE_UINT32_MAX_VALUE > Fee_ResetInfoAdminData.Address)
        {
            Fee_ResetInfoAdminData.Address += FEE_RESET_INFO_BLOCK_LEN;
            Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_UPDT_IDLE_RESET_INFO_WAIT;
        }
        else
        {
            FEE_DEBUG_ERROR(FALSE);
        }
    }
    else
    {
        #ifdef FEE_TRACE_ENABLE
        FEE_TRACE(ERASE_IDLE_RESET_INFO_JOB_REJECTED,0,(uint16)Fee_ResetInfoAdminData.Address);
        #endif
        if (MEMIF_JOB_FAILED == Fee_Job.JobResult)
        {
            if (FEE_JOB_STATE_CHECK_WRITE_REQUEST == Fee_Job.JobState)
            {
                FEE_NVM_JOB_ERROR_NOTIFICATION();
            }
            Fee_Job.JobActiveId = FEE_JOB_IDLE;
            Fee_Job.JobState = FEE_JOB_STATE_IDLE;
        }
        else
        {
            if (FEE_JOB_STATE_CHECK_WRITE_REQUEST == Fee_Job.JobState)
            {
                Fee_Job.JobActiveId = FEE_JOB_WRITE;
                Fee_Job.RepeatStateMachine = TRUE;
            }
            else
            {
                Fee_Job.JobActiveId = FEE_JOB_IDLE;
                Fee_Job.RepeatStateMachine = FALSE;
            }
        }
        Fee_NotifyInternalJobStatus(FEE_END_INTERNAL_JOB);
        Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
    }
}

/**************************************************************************
Function name   : Fee_JobUpdateEraseIdleResetInfoWait
Arguments       : void
Return type     : void
Description     : Service to Check the Flash Driver Job Result 
**************************************************************************/
static void Fee_JobUpdateEraseIdleResetInfoWait(void)
{
    MemIf_JobResultType fl_FlsJobStatus;
    fl_FlsJobStatus = FLS_GET_JOB_RESULT();
    if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
    {
        if (MEMIF_JOB_FAILED == Fee_Job.JobResult)
        {
            #ifdef FEE_TRACE_ENABLE
            FEE_TRACE(ERASE_IDLE_RESET_INFO_JOB_FAILED,0,0);
            #endif
            if (FEE_JOB_STATE_CHECK_WRITE_REQUEST == Fee_Job.JobState)
            {
                FEE_NVM_JOB_ERROR_NOTIFICATION();
            }
            Fee_Job.JobActiveId = FEE_JOB_IDLE;
            Fee_Job.JobState = FEE_JOB_STATE_IDLE;
        }
        else
        {
            #ifdef FEE_TRACE_ENABLE
            FEE_TRACE(ERASE_IDLE_RESET_INFO_JOB_SUCCESS,0,0);
            #endif
            if (FEE_JOB_STATE_CHECK_WRITE_REQUEST == Fee_Job.JobState)
            {
                Fee_Job.JobActiveId = FEE_JOB_WRITE;
                Fee_Job.RepeatStateMachine = TRUE;
            }
            else
            {
                Fee_Job.JobActiveId = FEE_JOB_IDLE;
                Fee_Job.JobState = FEE_JOB_STATE_IDLE;
                Fee_Job.RepeatStateMachine = FALSE;
            }
        }
        Fee_NotifyInternalJobStatus(FEE_END_INTERNAL_JOB);
        Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
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
    if (FEE_NUM_PARTITIONS > fl_PartionNo)
    {
        if(Fee_PartitionPendingSectorErase[fl_PartionNo].NumberOfSectorsToErase > 0U)
        {
            TotalSectors = FEE_NUM_OF_SECTORS;
            for(fl_SectorTraverse = 0; fl_SectorTraverse < TotalSectors; fl_SectorTraverse ++)
            {
                /* MISRA C-2012 Rule 10.4 : Calculated Values of FALSE and Fee_PartitionPendingSectorErase[fl_PartionNo].SectorEraseFlag[fl_SectorTraverse] were well within the range.It will not have any functional impact */
                if(FALSE != (boolean)Fee_PartitionPendingSectorErase[fl_PartionNo].SectorEraseFlag[fl_SectorTraverse])
                {
                    Fee_Partition[fl_PartionNo].EraseSectorId = fl_SectorTraverse;
                    Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_UPDT_RESET_INFO;
                    Fee_PartitionPendingSectorErase[fl_PartionNo].SectorEraseFlag[fl_SectorTraverse] = FALSE;
                    Fee_PartitionPendingSectorErase[fl_PartionNo].NumberOfSectorsToErase--;
                    Fee_Job.RepeatStateMachine = TRUE;
                    break;
                }
            }
            if(Fee_Job.SectorEraseState != FEE_SECTOR_ERASE_STATE_UPDT_RESET_INFO)
            {
                Fee_PartitionPendingSectorErase[fl_PartionNo].NumberOfSectorsToErase = 0;
                Fee_Job.RepeatStateMachine = TRUE;
            }
        }
        else
        {
            /* MISRA C-2012 Rule 10.3 : Calculated Values of Fee_PartitionPendingSectorErase[fl_PartionNo].SectorEraseEnable and FALSE were well within the range.It will not have any functional impact */
            Fee_PartitionPendingSectorErase[fl_PartionNo].SectorEraseEnable = FALSE;
            Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
            if (FEE_JOB_STATE_CHECK_WRITE_REQUEST == Fee_Job.JobState)
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
    else 
    {
        FEE_DEBUG_ERROR(FALSE);
        Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
        if (FEE_JOB_STATE_CHECK_WRITE_REQUEST == Fee_Job.JobState)
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
        /*Do Nothing*/
    break;

    case FEE_SECTOR_ERASE_STATE_UPDT_RESET_INFO:
        Fee_JobUpdateEraseResetInfo();
    break;

    case FEE_SECTOR_ERASE_STATE_UPDT_RESET_INFO_WAIT:
        Fee_JobUpdateEraseResetInfoWait();
    break;

    case FEE_SECTOR_ERASE_STATE_ERASE:
        Fee_SectorErase();
    break;

    case FEE_SECTOR_ERASE_STATE_ERASE_WAIT:
        Fee_SectorEraseWait();
    break;

    case FEE_SECTOR_ERASE_STATE_UPDT_IDLE_RESET_INFO:
        Fee_JobUpdateEraseIdleResetInfo();
    break;

    case FEE_SECTOR_ERASE_STATE_UPDT_IDLE_RESET_INFO_WAIT:
        Fee_JobUpdateEraseIdleResetInfoWait();
    break;

    case FEE_SECTOR_ERASE_STATE_PROCESS_DEFERRED_ERASE:
        Fee_SecotorEraseProcessDeferredErase();
    break;
    
    case FEE_SECTOR_ERASE_STATE_SUSPENDED:
        /*On Resume Internal Job, This case will be hadled synchronously to avoid race condition. So This case action is Do Nothing*/
    break;

    default:
    /*Do Nothing*/
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
    if((Fee_Job.JobActiveId == FEE_JOB_IDLE) && (FEE_BSS_INTERNAL_NO_LOCK == Fee_Job.ProcessInternalJob)) 
    {
        if (FEE_TIMER_WAIT_TIME > Fee_Job.InternalJobTimer)
        {
            Fee_Job.InternalJobTimer += 1U;
        }
        else
        {
            for (fl_partition = 0; fl_partition < FEE_NUM_PARTITIONS; fl_partition++)
            {
                if (FALSE != Fee_PartitionConfig[fl_partition].BackgroundSectorSwitch)
                {
                    if (Fee_SectorSwitchRequired(fl_partition, Fee_PartitionConfig[fl_partition].MaxLength) == E_OK)
                    {
                        /* MISRA C-2012 Rule 10.4 : Calculated Values of FALSE and Fee_PartitionPendingSectorErase[fl_PartionNo].SectorEraseEnable were well within the range.It will not have any functional impact */
                        if(FALSE != Fee_PartitionPendingSectorErase[fl_partition].SectorEraseEnable)
                        {
                            Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_PROCESS_DEFERRED_ERASE;
                        }
                        else
                        {
                            Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_UPDT_RESET_INFO;
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
Function name   : Fee_CpyFeeBlockInformation
Arguments       : p_Partition_No
Return type     : void
Description     : Service to Copy Latest Address 
**************************************************************************/
static void Fee_CpyFeeBlockInformation (uint8 p_Partition_No)
{
    uint16 fl_itr = 0;
    for (fl_itr = 0; fl_itr < FEE_NUM_BLOCKS; fl_itr++)
    {
        if (Fee_BlockConfig[fl_itr].PartitionNo == p_Partition_No)
        {
            Fee_BlockInformation_cpy[fl_itr] = Fee_BlockInformation[fl_itr];
        }
    }
} 
/**************************************************************************
Function name   : Fee_RestoreFeeBlockInformation
Arguments       : p_Partition_No
Return type     : void
Description     : Service to Restore Latest Address 
**************************************************************************/
static void Fee_RestoreFeeBlockInformation (uint8 p_Partition_No)
{
    uint16 fl_itr = 0;
    for (fl_itr = 0; fl_itr < FEE_NUM_BLOCKS; fl_itr++)
    {
        if (Fee_BlockConfig[fl_itr].PartitionNo == p_Partition_No)
        {
            Fee_BlockInformation[fl_itr] = Fee_BlockInformation_cpy[fl_itr];
        }
    }
} 

/**************************************************************************
Function name   : Fee_ReportSectorSwitchFailure
Arguments       : void
Return type     : void
Description     : Service to Take Failure Action During Sector Switch
**************************************************************************/
static void Fee_ReportSectorSwitchFailure(void)
{
    uint8 fl_PartionNo = Fee_Job.CurPartition;
    if(FEE_NUM_PARTITIONS > fl_PartionNo)
    {
        if(FEE_NUM_OF_SECTORS > Fee_Partition[fl_PartionNo].CurrentSectorId)
        {
            Fee_RestoreFeeBlockInformation(fl_PartionNo);
            Fee_PrepareDifEraseSector(fl_PartionNo,  Fee_Partition[fl_PartionNo].CurrentSectorId);
            Fee_Partition[fl_PartionNo].CurrentSectorId = Fee_Partition[fl_PartionNo].OldSectorId;
            if(FEE_UINT32_MAX_VALUE > Fee_SectorConfig[Fee_Partition[fl_PartionNo].CurrentSectorId].SectorStartAddress)
            {
                Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_SectorConfig[Fee_Partition[fl_PartionNo].CurrentSectorId].SectorStartAddress + \
                Fee_SectorConfig[Fee_Partition[fl_PartionNo].CurrentSectorId].SectorSize - FEE_SECTOR_FOOTER_SIZE;
            }
            else
            {
                FEE_DEBUG_ERROR(FALSE);
            }
        }
        else
        {
            /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */
            FEE_DEBUG_ERROR(FALSE);
        }
    }
    else
    {
        /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */
        FEE_DEBUG_ERROR(FALSE);
    }
    Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_IDLE;
    Fee_Job.JobResult = MEMIF_JOB_FAILED;
    if (FEE_JOB_STATE_CHECK_WRITE_REQUEST == Fee_Job.JobState)
    {
        FEE_NVM_JOB_ERROR_NOTIFICATION();
    }
    Fee_Job.JobActiveId = FEE_JOB_IDLE;
    Fee_Job.JobState = FEE_JOB_STATE_IDLE;
    Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
    Fee_Job.RepeatStateMachine = FALSE;
    Fee_NotifyInternalJobStatus(FEE_END_INTERNAL_JOB);
    #ifdef MEM_TESTING_ENABLED
        FEE_JOB_HOOK(FEE_END_INTERNAL_JOB,Fee_Job.CurPartition);
    #endif
}

/**************************************************************************
Function name   : Fee_JobUpdateSecSwitchResetInfo
Arguments       : void
Return type     : void
Description     : Service to Initiate Reset Info Write
**************************************************************************/
static void Fee_JobUpdateSecSwitchResetInfo(void)
{
    uint8 fl_PartionNo = 0U;
    Std_ReturnType fl_RequestStatus = E_NOT_OK;
    uint8 fl_SectorId = 0xFFU;
    fl_PartionNo = Fee_Job.CurPartition;
    if(FEE_NUM_PARTITIONS > fl_PartionNo)
    {
        fl_SectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
    }
    else
    {
        /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */
        FEE_DEBUG_ERROR(FALSE);
    }
    if(E_OK == Fee_IsResetInfoRangeAvailable())
    {
        Fee_FillResetInfoData(FEE_SECTORSWITCH_JOB_INTERRUPTED, fl_PartionNo, fl_SectorId);
        fl_RequestStatus = FLS_WRITE(Fee_ResetInfoAdminData.Address,(uint8 *)&Fee_ResetInfoData.HeadPattern,FEE_RESET_INFO_BLOCK_LEN);  
        if(fl_RequestStatus == E_OK)
        {
            #ifdef FEE_TRACE_ENABLE
            FEE_TRACE(SECTOR_SW_RESET_INFO_JOB_ACCEPTED,0,(uint16)Fee_ResetInfoAdminData.Address);
            #endif
            if(FEE_UINT32_MAX_VALUE > Fee_ResetInfoAdminData.Address)
            {
                Fee_ResetInfoAdminData.Address += FEE_RESET_INFO_BLOCK_LEN;
            }
            else
            {
                FEE_DEBUG_ERROR(FALSE);
            }
            Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_UPDT_RESET_INFO_WAIT;
        }
        else
        {
            #ifdef FEE_TRACE_ENABLE
            FEE_TRACE(SECTOR_SW_RESET_INFO_JOB_REJECTED,0,(uint16)Fee_ResetInfoAdminData.Address);
            #endif
            Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_IDLE;
            Fee_Job.JobResult = MEMIF_JOB_FAILED;
            if (FEE_JOB_STATE_CHECK_WRITE_REQUEST == Fee_Job.JobState)
            {
                FEE_NVM_JOB_ERROR_NOTIFICATION();
            }
            Fee_Job.JobActiveId = FEE_JOB_IDLE;
            Fee_Job.JobState = FEE_JOB_STATE_IDLE;
            Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
            Fee_Job.RepeatStateMachine = FALSE;
            Fee_NotifyInternalJobStatus(FEE_END_INTERNAL_JOB);
        }
    }
}

/**************************************************************************
Function name   : Fee_JobUpdateSecSwitchResetInfo
Arguments       : void
Return type     : void
Description     : Service to Check Flash Driver Operation
**************************************************************************/
static void Fee_JobUpdateSecSwitchResetInfoWait(void)
{
    MemIf_JobResultType fl_FlsJobStatus;
    fl_FlsJobStatus = FLS_GET_JOB_RESULT();
    if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
    {
        if(MEMIF_JOB_OK != fl_FlsJobStatus)
        {
            #ifdef FEE_TRACE_ENABLE
            FEE_TRACE(SECTOR_SW_RESET_INFO_JOB_FAILED,0,0);
            #endif
            Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_IDLE;
            Fee_Job.JobResult = MEMIF_JOB_FAILED;
            if (FEE_JOB_STATE_CHECK_WRITE_REQUEST == Fee_Job.JobState)
            {
                FEE_NVM_JOB_ERROR_NOTIFICATION();
            }
            Fee_Job.JobActiveId = FEE_JOB_IDLE;
            Fee_Job.JobState = FEE_JOB_STATE_IDLE;
            Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
            Fee_Job.RepeatStateMachine = FALSE;
            Fee_NotifyInternalJobStatus(FEE_END_INTERNAL_JOB);
        }
        else 
        {
            #ifdef FEE_TRACE_ENABLE
            FEE_TRACE(SECTOR_SW_RESET_INFO_JOB_SUCCESS,0,0);
            #endif
            Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_HEADER_WRITE;
        }
    }
}
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
    Std_ReturnType fl_RequestStatus = E_NOT_OK;

    fl_PartionNo = Fee_Job.CurPartition;
    if ( FEE_NUM_PARTITIONS > fl_PartionNo)
    {
        Fee_CpyFeeBlockInformation(fl_PartionNo);
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
        if (FEE_NUM_OF_SECTORS > fl_CurrentSectorId)
        {
            fl_SectorWriteAddress = Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress;
            fl_RequestStatus = FLS_WRITE(fl_SectorWriteAddress,(uint8 *)&Fee_SectorHeader.SectorId,FEE_SECTOR_HEADER_SIZE);
            if(fl_RequestStatus == E_OK)
            {
                #ifdef FEE_TRACE_ENABLE
                FEE_TRACE(SECTOR_SW_HEADER_WRITE_ACCEPTED,fl_CurrentSectorId,(uint16)fl_SectorWriteAddress);
                #endif
                Fee_Partition[fl_PartionNo].NextFreeAddress = fl_SectorWriteAddress + FEE_SECTOR_HEADER_SIZE;
                Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_HEADER_WRITE_WAIT;
                Fee_Job.RepeatStateMachine = FALSE;
            }
            else
            {
                #ifdef FEE_TRACE_ENABLE
                FEE_TRACE(SECTOR_SW_HEADER_WRITE_REJECTED,fl_CurrentSectorId,(uint16)fl_SectorWriteAddress);
                #endif
                Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_IDLE;
                Fee_Job.JobResult = MEMIF_JOB_FAILED;
                if (FEE_JOB_STATE_CHECK_WRITE_REQUEST == Fee_Job.JobState)
                {
                    FEE_NVM_JOB_ERROR_NOTIFICATION();
                }
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
            FEE_DEBUG_ERROR(FALSE);
            Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_IDLE;
            Fee_Job.JobResult = MEMIF_JOB_FAILED;
            if (FEE_JOB_STATE_CHECK_WRITE_REQUEST == Fee_Job.JobState)
            {
                FEE_NVM_JOB_ERROR_NOTIFICATION();
            }
            Fee_Job.JobActiveId = FEE_JOB_IDLE;
            Fee_Job.JobState = FEE_JOB_STATE_IDLE;
            Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
            Fee_Job.RepeatStateMachine = FALSE;
            Fee_NotifyInternalJobStatus(FEE_END_INTERNAL_JOB);
        }
    }
    else 
    {
        FEE_DEBUG_ERROR(FALSE);
        Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_IDLE;
        Fee_Job.JobResult = MEMIF_JOB_FAILED;
        if (FEE_JOB_STATE_CHECK_WRITE_REQUEST == Fee_Job.JobState)
        {
            FEE_NVM_JOB_ERROR_NOTIFICATION();
        }
        Fee_Job.JobActiveId = FEE_JOB_IDLE;
        Fee_Job.JobState = FEE_JOB_STATE_IDLE;
        Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_IDLE;
        Fee_Job.RepeatStateMachine = FALSE;
        Fee_NotifyInternalJobStatus(FEE_END_INTERNAL_JOB);
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
            #ifdef FEE_TRACE_ENABLE
            FEE_TRACE(SECTOR_SW_HEADER_WRITE_SUCCESS,0,0);
            #endif
            Fee_Job.SearchBlockId = 1;
            if(Fee_BlockConfig[Fee_Job.SearchBlockId].PartitionNo == fl_PartionNo)
            {
                if (FEE_BSS_INTERNAL_NO_LOCK != Fee_Job.ProcessInternalJob)
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
                if (FEE_BSS_INTERNAL_NO_LOCK != Fee_Job.ProcessInternalJob)
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
            #ifdef FEE_TRACE_ENABLE
            FEE_TRACE(SECTOR_SW_HEADER_WRITE_FAILED,0,0);
            #endif
            Fee_ReportSectorSwitchFailure();
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
    if (FEE_NUM_BLOCKS > Fee_Job.SearchBlockId)
    {
        if(Fee_BlockInformation[Fee_Job.SearchBlockId].LatestAddress != 0U)
        {
            /* MISRA C-2012 Rule 10.8 : Fee_BlockConfig[Fee_Job.SearchBlockId].BlockSize Value calculated here is within the range. It will not have any functional impact */
            fl_RequestStatus = FLS_READ(Fee_BlockInformation[Fee_Job.SearchBlockId].LatestAddress, (uint8 *)&Fee_SectorSwitchBlockBuffer.Header.BlockId, (uint32)(Fee_BlockConfig[Fee_Job.SearchBlockId].BlockSize + (FEE_HEADER_SIZE << 1)));
            if(fl_RequestStatus == E_OK)
            {
                Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_READ_WAIT;
                Fee_Job.RepeatStateMachine = FALSE;
            }
            else
            {
                #ifdef FEE_TRACE_ENABLE
                FEE_TRACE(SECTOR_SW_BLOCK_READ_JOB_REJECTED,0,0);
                #endif
                Fee_ReportSectorSwitchFailure();  
            }
        }
        else
        {
            Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_SEARCH_NEXT_BLOCK;
            Fee_Job.RepeatStateMachine = TRUE;
        }
    }
    else 
    {
        FEE_DEBUG_ERROR(FALSE);
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
    uint8   fl_SectorId = 0U;
    MemIf_JobResultType fl_FlsJobStatus;
    fl_FlsJobStatus = FLS_GET_JOB_RESULT();
    if(FEE_NUM_PARTITIONS > Fee_Job.CurPartition)
    {
        fl_SectorId = Fee_Partition[Fee_Job.CurPartition].OldSectorId;
    }
    else
    {
        /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */
        FEE_DEBUG_ERROR(FALSE);
    }
    if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
    {
        if(fl_FlsJobStatus == MEMIF_JOB_OK)
        {
            Fee_ResetRetryTimer();
            Fee_RetryManagementData.ReadRetryCount = 0;
            Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_READ_VALIDATE;
            Fee_Job.RepeatStateMachine = TRUE;
        }
        else
        {
            Fee_RetryTimeoutProcess();
            if(Fee_RetryManagementData.ReadRetryCount > FEE_READ_RETRY_COUNT)
            {
                if(FALSE != Fee_RetryManagementData.TimerIsExpired)
                {
                    Fee_ResetRetryTimer();
                    Fee_RetryManagementData.ReadRetryCount = 0;
                    #ifdef FEE_TRACE_ENABLE
                    FEE_TRACE(SECTOR_SW_BLOCK_READ_JOB_FAILED,0,Fee_Job.SearchBlockId);
                    #endif
                    Fee_SectorSwitchTraverseData.TraverseBlockId = Fee_Job.SearchBlockId;
                    if((FEE_NUM_OF_SECTORS > fl_SectorId) && (FEE_UINT32_MAX_VALUE > Fee_SectorConfig[fl_SectorId].SectorStartAddress))
                    {
                        Fee_SectorSwitchTraverseData.TraverseAddress = Fee_SectorConfig[fl_SectorId].SectorStartAddress + FEE_SECTOR_HEADER_SIZE;
                    }
                    else
                    {
                        FEE_DEBUG_ERROR(FALSE);
                    }
                    if(FEE_NUM_BLOCKS > Fee_Job.SearchBlockId)
                    {
                        Fee_SectorSwitchTraverseData.EndAddress = Fee_BlockInformation[Fee_Job.SearchBlockId].LatestAddress;
                    }
                    else
                    {
                        FEE_DEBUG_ERROR(FALSE);
                    }
                    Fee_SectorSwitchTraverseData.ValidBlockAddress = 0;
                    Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_TRAVERSE_READ;
                    Fee_Job.RepeatStateMachine = TRUE;
                }
                else
                {
                    Fee_RetryManagementData.ReadRetryCount = 0;
                    Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_READ;
                }
            }
            else
            {
                Fee_RetryManagementData.ReadRetryCount += 1U;
                Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_READ;
            }
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
static void Fee_SectorSwitchBlockReadValidate(void)
{
    uint8   fl_SectorId = 0U;
    if(FEE_NUM_PARTITIONS > Fee_Job.CurPartition)
    {
        fl_SectorId = Fee_Partition[Fee_Job.CurPartition].OldSectorId;
    }
    else
    {
        /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */
        FEE_DEBUG_ERROR(FALSE);
    }
    if( (Fee_SectorSwitchBlockBuffer.Header.BlockId != 0xFFFFU) &&\
        (Fee_SectorSwitchBlockBuffer.Header.BlockId == (uint16)~ Fee_SectorSwitchBlockBuffer.Footer.BlockId) &&\
        (Fee_SectorSwitchBlockBuffer.Header.PayloadLength == (uint16)~ Fee_SectorSwitchBlockBuffer.Footer.PayloadLength) &&\
        (Fee_SectorSwitchBlockBuffer.Header.ValidityFlag != FEE_BLOCK_VALIDITY_FLAG_INVALID)&&\
        (Fee_SectorSwitchBlockBuffer.Footer.ValidityFlag != FEE_BLOCK_VALIDITY_FLAG_INVALID) )
    {
        
        Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_WRITE;
    }
    else 
    {

        Fee_SectorSwitchTraverseData.TraverseBlockId = Fee_Job.SearchBlockId;
        if((FEE_NUM_OF_SECTORS > fl_SectorId) && (FEE_UINT32_MAX_VALUE > Fee_SectorConfig[fl_SectorId].SectorStartAddress))
        {
            Fee_SectorSwitchTraverseData.TraverseAddress = Fee_SectorConfig[fl_SectorId].SectorStartAddress + FEE_SECTOR_HEADER_SIZE;
        }
        else
        {
            FEE_DEBUG_ERROR(FALSE);
        }
        if(FEE_NUM_BLOCKS > Fee_Job.SearchBlockId)
        {
        Fee_SectorSwitchTraverseData.EndAddress = Fee_BlockInformation[Fee_Job.SearchBlockId].LatestAddress;
        }
        else
        {
            FEE_DEBUG_ERROR(FALSE);
        }
        Fee_SectorSwitchTraverseData.ValidBlockAddress = 0;
        Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_TRAVERSE_READ;
        Fee_Job.RepeatStateMachine = TRUE;
        #ifdef FEE_TRACE_ENABLE
        FEE_TRACE(SECTOR_SW_BLOCK_READ_JOB_VALIDATION_FAILED,0,Fee_Job.SearchBlockId);
        #endif
    }
}

/**************************************************************************
Function name   : Fee_SectorSwitchBlockTraverseRead
Arguments       : void
Return type     : void
Description     : Service to Start Traverse to Find Valid Block
**************************************************************************/
static void Fee_SectorSwitchBlockTraverseRead(void)
{
    Std_ReturnType fl_RequestStatus;
    if (Fee_SectorSwitchTraverseData.TraverseAddress <= Fee_SectorSwitchTraverseData.EndAddress) /*If Traverse is not completed*/
    {
        fl_RequestStatus = FLS_READ(Fee_SectorSwitchTraverseData.TraverseAddress, (uint8 *)&Fee_BlockHeader[0].BlockId, (FEE_HEADER_SIZE << 1));
        if(fl_RequestStatus == E_OK)
        {
            Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_TRAVERSE_READ_WAIT;
            Fee_Job.RepeatStateMachine = FALSE;
        }
        else
        {
            #ifdef FEE_TRACE_ENABLE
            FEE_TRACE(SECTOR_SW_TRAVERSE_READ_JOB_REJECTED,0,0);
            #endif
            Fee_ReportSectorSwitchFailure();  
        }
    }
    else 
    {
        if (0U != Fee_SectorSwitchTraverseData.ValidBlockAddress) /*If Traverse Completed and a Valid Instance Found*/
        {
            if(FEE_NUM_BLOCKS > Fee_SectorSwitchTraverseData.TraverseBlockId)
            {
                Fee_BlockInformation[Fee_SectorSwitchTraverseData.TraverseBlockId].LatestAddress = Fee_SectorSwitchTraverseData.ValidBlockAddress;
            }
            else
            {
                FEE_DEBUG_ERROR(FALSE);
            }
            Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_READ;
        }
        else /*If Traverse Completed and No Valid Instance Found*/
        {
            #ifdef FEE_TRACE_ENABLE
            FEE_TRACE(SECTOR_SW_TRAVERSE_READ_FINISHED_NO_FOUND,0,Fee_Job.SearchBlockId);
            #endif
            if(FEE_NUM_BLOCKS > Fee_SectorSwitchTraverseData.TraverseBlockId)
            {
                Fee_BlockInformation[Fee_SectorSwitchTraverseData.TraverseBlockId].LatestAddress = 0;
            }
            else
            {
                /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */
                FEE_DEBUG_ERROR(FALSE);
            }
            Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_SEARCH_NEXT_BLOCK;

        }
    }  
}

/**************************************************************************
Function name   : Fee_SectorSwitchBlockTraverseReadWait
Arguments       : void
Return type     : void
Description     : Service to check the Flash driver operation
**************************************************************************/
static void Fee_SectorSwitchBlockTraverseReadWait(void)
{
    MemIf_JobResultType fl_FlsJobStatus;
    Fee_BlockStatusType fl_BlockValid;
    fl_FlsJobStatus = FLS_GET_JOB_RESULT();
    if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
    {
        if(fl_FlsJobStatus == MEMIF_JOB_OK)
        {
            Fee_ResetRetryTimer();
            Fee_RetryManagementData.ReadRetryCount = 0;
            fl_BlockValid = Fee_HeaderValidate();
            if (fl_BlockValid != FEE_BLOCK_NOT_EXIST)
            {
                if (Fee_BlockHeader[0].BlockId == Fee_SectorSwitchTraverseData.TraverseBlockId)
                {
                    if (fl_BlockValid == FEE_BLOCK_EXIST)
                    {
                        Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_TRAVERSE_VALIDATE;
                    }
                    else
                    {
                        /* MISRA C-2012 Rule 10.7 : Values calculated for variables Fee_SectorSwitchTraverseData.TraverseAddress and Fee_BlockHeader[0].PayloadLength were well within the range. 
                                                    It will not have any functional impact */
                        Fee_SectorSwitchTraverseData.TraverseAddress += ((FEE_HEADER_SIZE << 1) + Fee_BlockHeader[0].PayloadLength);
                        Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_TRAVERSE_READ;
                    }
                }
                else 
                {
                    Fee_SectorSwitchTraverseData.TraverseAddress += ((FEE_HEADER_SIZE << 1) + Fee_BlockHeader[0].PayloadLength);
                    Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_TRAVERSE_READ;
                }
            }
            else
            {
                if(FEE_UINT32_MAX_VALUE > Fee_SectorSwitchTraverseData.TraverseAddress)
                {
                    Fee_SectorSwitchTraverseData.TraverseAddress += FEE_HEADER_SIZE << 1;
                    Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_TRAVERSE_READ;
                }
                else
                {
                    FEE_DEBUG_ERROR(FALSE);
                }
                
            }
        }
        else
        {
            #ifdef FEE_TRACE_ENABLE
		    FEE_TRACE(READ_SEC_SWITCH_BLOCK_READ_TRV_FAILED,(uint8)Fee_SectorSwitchTraverseData.TraverseBlockId,Fee_SectorSwitchTraverseData.TraverseAddress);
            #endif
            Fee_RetryTimeoutProcess();
            if(Fee_RetryManagementData.ReadRetryCount > FEE_READ_RETRY_COUNT)
            {
                if(FALSE != Fee_RetryManagementData.TimerIsExpired)
                {
                    Fee_ResetRetryTimer();
                    Fee_RetryManagementData.ReadRetryCount = 0U;
                    if(FEE_UINT32_MAX_VALUE > Fee_SectorSwitchTraverseData.TraverseAddress)
                    {
                        Fee_SectorSwitchTraverseData.TraverseAddress += FEE_HEADER_SIZE << 1U;
                    }
                    else
                    {
                        FEE_DEBUG_ERROR(FALSE);
                    }
                    Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_TRAVERSE_READ;
                    Fee_Job.RepeatStateMachine = TRUE;
                }
                else
                {
                    Fee_RetryManagementData.ReadRetryCount = 0;
                    Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_TRAVERSE_READ;
                }
            }
            else
            {
                Fee_RetryManagementData.ReadRetryCount += 1U;
                Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_TRAVERSE_READ;
            }

        }
    }
    else
    {
        Fee_Job.RepeatStateMachine = FALSE;
    }
}

/**************************************************************************
Function name   : Fee_SectorSwitchBlockTraverseValidate
Arguments       : void
Return type     : void
Description     : Service to validate block
**************************************************************************/
static void Fee_SectorSwitchBlockTraverseValidate(void)
{
    Std_ReturnType fl_RequestStatus = E_NOT_OK;
    if(FEE_NUM_BLOCKS > Fee_SectorSwitchTraverseData.TraverseBlockId)
    {
        fl_RequestStatus = FLS_READ(Fee_SectorSwitchTraverseData.TraverseAddress + (FEE_HEADER_SIZE << 1),
                                (uint8 *)&Fee_SectorSwitchBlockBuffer.PayloadBuffer[0], Fee_BlockConfig[Fee_SectorSwitchTraverseData.TraverseBlockId].BlockSize);
    }
    else
    {
        /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */
        FEE_DEBUG_ERROR(FALSE);
    }
    if(fl_RequestStatus == E_OK)
    {
        Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_TRAVERSE_VALIDATE_WAIT;
        Fee_Job.RepeatStateMachine = FALSE;
    }
    else
    {
        #ifdef FEE_TRACE_ENABLE
        FEE_TRACE(SECTOR_SWITCH_TRAVERSE_VALIDATE_JOB_REJECTED,0,0);
        #endif
        Fee_ReportSectorSwitchFailure();
        Fee_Job.RepeatStateMachine = FALSE;  
    }
}

/**************************************************************************
Function name   : Fee_SectorSwitchBlockTraverseValidateWait
Arguments       : void
Return type     : void
Description     : Service to check the Flash driver operation
**************************************************************************/
static void Fee_SectorSwitchBlockTraverseValidateWait(void)
{
    MemIf_JobResultType fl_FlsJobStatus = MEMIF_JOB_FAILED;
    fl_FlsJobStatus = FLS_GET_JOB_RESULT();
    if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
    {
        if(fl_FlsJobStatus == MEMIF_JOB_OK)
        {
            Fee_ResetRetryTimer();
            Fee_RetryManagementData.ReadRetryCount = 0;
            Fee_SectorSwitchTraverseData.ValidBlockAddress = Fee_SectorSwitchTraverseData.TraverseAddress; 

            if((FEE_NUM_BLOCKS > Fee_SectorSwitchTraverseData.TraverseBlockId) && (FEE_UINT16_MAX_VALUE > Fee_BlockConfig[Fee_SectorSwitchTraverseData.TraverseBlockId].BlockSize))
            {
                /*MISRA C-2012 Rule 10.7 : Values calculated for variables Fee_SectorSwitchTraverseData.TraverseAddress was well within the range. It will not have any functional impact */
                Fee_SectorSwitchTraverseData.TraverseAddress += Fee_BlockConfig[Fee_SectorSwitchTraverseData.TraverseBlockId].BlockSize + (FEE_HEADER_SIZE << 1);
            }
            else
            {
                /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */
                FEE_DEBUG_ERROR(FALSE);
            }
            Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_TRAVERSE_READ;
            #ifdef FEE_TRACE_ENABLE
            FEE_TRACE(SECTOR_SW_TRAVERSE_READ_JOB_FAILED,0,Fee_Job.SearchBlockId);
            #endif
            Fee_Job.RepeatStateMachine = TRUE;
        }
        else 
        {
            #ifdef FEE_TRACE_ENABLE
    		FEE_TRACE(READ_SEC_SWITCH_BLOCK_READ_TRV_VALIDATE_FAILED,(uint8)Fee_SectorSwitchTraverseData.TraverseBlockId,Fee_SectorSwitchTraverseData.TraverseAddress);
            #endif
            Fee_RetryTimeoutProcess();
            if(Fee_RetryManagementData.ReadRetryCount > FEE_READ_RETRY_COUNT)
            {
                if(FALSE != Fee_RetryManagementData.TimerIsExpired)
                {
                    Fee_ResetRetryTimer();
                    Fee_RetryManagementData.ReadRetryCount = 0;
                    if((FEE_NUM_BLOCKS > Fee_SectorSwitchTraverseData.TraverseBlockId) && (FEE_UINT16_MAX_VALUE > Fee_BlockConfig[Fee_SectorSwitchTraverseData.TraverseBlockId].BlockSize))
                    {
                        /*MISRA C-2012 Rule 10.7 : Values calculated for variables Fee_SectorSwitchTraverseData.TraverseAddress was well within the range. It will not have any functional impact */
                        Fee_SectorSwitchTraverseData.TraverseAddress += Fee_BlockConfig[Fee_SectorSwitchTraverseData.TraverseBlockId].BlockSize + (FEE_HEADER_SIZE << 1);
                    }
                    else
                    {
                        /* MISRA C-2012 Rule 10.5 : Value of the macro FALSE used here is within the range. It will not have any functional impact */
                        FEE_DEBUG_ERROR(FALSE);
                    }
                    Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_TRAVERSE_READ;
                    #ifdef FEE_TRACE_ENABLE
                    FEE_TRACE(SECTOR_SW_TRAVERSE_READ_JOB_FAILED,0,Fee_Job.SearchBlockId);
                    #endif
                    Fee_Job.RepeatStateMachine = TRUE;
                }
                else
                {
                    Fee_RetryManagementData.ReadRetryCount = 0;
                    Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_TRAVERSE_VALIDATE;
                }
            }
            else
            {
                Fee_RetryManagementData.ReadRetryCount += 1U;
                Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_TRAVERSE_VALIDATE;
            }
        }
    }
    else
    {
        /* Wait for Next State Machine */
        Fee_Job.RepeatStateMachine = FALSE;
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
    if (FEE_NUM_PARTITIONS > fl_PartionNo)
    {
        if (FEE_NUM_BLOCKS > Fee_Job.SearchBlockId)
        {
            fl_RequestStatus = FLS_WRITE(Fee_Partition[fl_PartionNo].NextFreeAddress, (uint8 *)&Fee_SectorSwitchBlockBuffer.Header.BlockId, ((uint32)Fee_BlockConfig[Fee_Job.SearchBlockId].BlockSize + (FEE_HEADER_SIZE << 1)));
            if(fl_RequestStatus == E_OK)
            {                      
                Fee_Partition[fl_PartionNo].NextFreeAddress = Fee_Partition[fl_PartionNo].NextFreeAddress + Fee_BlockConfig[Fee_Job.SearchBlockId].BlockSize + (FEE_HEADER_SIZE << 1);
                Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_BLOCK_WRITE_WAIT;
                Fee_Job.RepeatStateMachine = FALSE;
            }
            else
            {
                #ifdef FEE_TRACE_ENABLE
                FEE_TRACE(SECTOR_SW_BLOCK_WRITE_JOB_REJECTED,0,Fee_Job.SearchBlockId);
                #endif
                Fee_ReportSectorSwitchFailure();
            }
        }  
        else 
        {
            FEE_DEBUG_ERROR(FALSE);
            Fee_ReportSectorSwitchFailure();
        }  
    }
    else 
    {
        FEE_DEBUG_ERROR(FALSE);
        Fee_ReportSectorSwitchFailure();
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
            if (FEE_NUM_PARTITIONS > fl_PartionNo)
            {            
                if (FEE_NUM_BLOCKS > Fee_Job.SearchBlockId)
                {
                    Fee_BlockInformation[Fee_Job.SearchBlockId].LatestAddress = Fee_Partition[fl_PartionNo].NextFreeAddress - Fee_BlockConfig[Fee_Job.SearchBlockId].BlockSize - (FEE_HEADER_SIZE << 1);
                }
                else 
                {
                    FEE_DEBUG_ERROR(FALSE);
                }
            }
            else 
            {
                FEE_DEBUG_ERROR(FALSE);
            }
            if (FEE_BSS_INTERNAL_NO_LOCK != Fee_Job.ProcessInternalJob)
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
            #ifdef FEE_TRACE_ENABLE
            FEE_TRACE(SECTOR_SW_BLOCK_WRITE_JOB_FAILED,0,Fee_Job.SearchBlockId);
            #endif
            Fee_ReportSectorSwitchFailure();
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
    Std_ReturnType fl_RequestStatus = E_NOT_OK;
    uint8 fl_CurrentSectorId;
    fl_PartionNo = Fee_Job.CurPartition;
    if (FEE_NUM_PARTITIONS > fl_PartionNo)
    {
        fl_CurrentSectorId = Fee_Partition[fl_PartionNo].CurrentSectorId;
        if (FEE_NUM_OF_SECTORS > fl_CurrentSectorId)
        {
            Fee_SectorFooter.SectorId = (uint8)~Fee_Partition[fl_PartionNo].CurrentSectorId;
            Fee_SectorFooter.count = (uint8)~Fee_Partition[fl_PartionNo].count;
            Fee_SectorFooter.Reserved1 = 0U;
            Fee_SectorFooter.Reserved2 = 0U;
            Fee_SectorFooter.Reserved3 = 0U;

            fl_SectorWriteAddress= Fee_SectorConfig[fl_CurrentSectorId].SectorStartAddress + \
                                    Fee_SectorConfig[fl_CurrentSectorId].SectorSize - FEE_SECTOR_FOOTER_SIZE;


            fl_RequestStatus = FLS_WRITE(fl_SectorWriteAddress, (uint8 *)&Fee_SectorFooter.SectorId, FEE_SECTOR_FOOTER_SIZE);
        }
        else
        {
            FEE_DEBUG_ERROR(FALSE);
        }
    }
    else
    {
        FEE_DEBUG_ERROR(FALSE);
    }
    if(fl_RequestStatus == E_OK)
    {
        #ifdef FEE_TRACE_ENABLE
        FEE_TRACE(SECTOR_SW_FOOTER_WRITE_JOB_ACCEPTED,fl_CurrentSectorId,(uint16)fl_SectorWriteAddress);
        #endif
        Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_SECTOR_FOOTER_WRITE_WAIT;
        Fee_Job.RepeatStateMachine = FALSE;
    }
    else
    {
        #ifdef FEE_TRACE_ENABLE
        FEE_TRACE(SECTOR_SW_FOOTER_WRITE_JOB_REJECTED,fl_CurrentSectorId,(uint16)fl_SectorWriteAddress);
        #endif
        Fee_ReportSectorSwitchFailure();
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
            #ifdef FEE_TRACE_ENABLE
            FEE_TRACE(SECTOR_SW_FOOTER_WRITE_JOB_SUCCESS,0,0);
            #endif
            Fee_Job.SectorSwitchState = FEE_SECTOR_SWITCH_STATE_IDLE;
            if (FEE_NUM_PARTITIONS > fl_PartionNo)
            {
                Fee_Partition[fl_PartionNo].EraseSectorId = Fee_Partition[fl_PartionNo].OldSectorId;
            }
            else 
            {
                FEE_DEBUG_ERROR(FALSE);
            }
            Fee_Job.SectorEraseState = FEE_SECTOR_ERASE_STATE_UPDT_RESET_INFO;
            Fee_Job.RepeatStateMachine = TRUE;
        }
        else
        {
            #ifdef FEE_TRACE_ENABLE
            FEE_TRACE(SECTOR_SW_FOOTER_WRITE_JOB_FAILED,0,0);
            #endif
            Fee_ReportSectorSwitchFailure();
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

            case FEE_SECTOR_SWITCH_STATE_UPDT_RESET_INFO:
            Fee_JobUpdateSecSwitchResetInfo();
            break;

            case FEE_SECTOR_SWITCH_STATE_UPDT_RESET_INFO_WAIT:
            Fee_JobUpdateSecSwitchResetInfoWait();
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

            case FEE_SECTOR_SWITCH_STATE_BLOCK_TRAVERSE_READ:
            Fee_SectorSwitchBlockTraverseRead();
            break;
            case FEE_SECTOR_SWITCH_STATE_BLOCK_TRAVERSE_READ_WAIT:
            Fee_SectorSwitchBlockTraverseReadWait();
            break;
            case FEE_SECTOR_SWITCH_STATE_BLOCK_TRAVERSE_VALIDATE:
            Fee_SectorSwitchBlockTraverseValidate();
            break;
            case FEE_SECTOR_SWITCH_STATE_BLOCK_TRAVERSE_VALIDATE_WAIT:
            Fee_SectorSwitchBlockTraverseValidateWait();
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
                /*On Resume Internal Job, This case will be hadled synchronously to avoid race condition. So This case action is Do Nothing*/
            break;

            default:
            /*do nothing*/
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
    uint8 fl_State = State;
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
    if ((FEE_END_INTERNAL_JOB == State) && (FEE_BSS_INTERNAL_NO_LOCK != Fee_Job.ProcessInternalJob))
    {
        fl_State = FEE_SUSPEND_INTERNAL_JOB;
    }
    FEE_NVM_INTERNAL_NOTIFICATION(fl_State);
}

/**************************************************************************
Function name   : void Fee_RestoreJobState(uint8 State)
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
    Fee_Job.JobActiveId = FEE_JOB_INTERNAL_BUSY;
    Fee_Job.JobState = Fee_JobCpy.JobState;
    Fee_Job.SectorSwitchState = Fee_JobCpy.SectorSwitchState;
    Fee_Job.PartitionState = Fee_JobCpy.PartitionState;
    Fee_Job.SectorEraseState =Fee_JobCpy.SectorEraseState;
    Fee_Job.JobResult = Fee_JobCpy.JobResult;
    Fee_Job.ResumeSectorSwitchState = Fee_JobCpy.ResumeSectorSwitchState;
    Fee_Job.ResumeSectorEraseState = Fee_JobCpy.ResumeSectorEraseState;
    Fee_Job.CurPartition = Fee_JobCpy.CurPartition;
}


static void Fee_UpdateDefaultResetInfoAdminData(void)
{
    uint8 fl_PartitionIter;
    uint16 fl_crc_16;
    for(fl_PartitionIter = 0; fl_PartitionIter < FEE_NUM_PARTITIONS; fl_PartitionIter++)
    {
        /* Loading No interruption detected.*/
        Fee_InterruptedJobAdminData[fl_PartitionIter].InterruptedJob = FEE_INTERRUPTED_JOB_IDLE;
        /* By design, if no interruption detected, InterruptedJobSectorId will not be used, 
            Still for protection setting InterruptedJobSectorId as 0xFF;
        */
        Fee_InterruptedJobAdminData[fl_PartitionIter].InterruptedJobSectorId = 0xFF;
    }
    Fee_ResetInfoData.HeadPattern = FEE_HEADER_RESET_PATTERN;
    Fee_ResetInfoData.PartitionState = 0;
    Fee_ResetInfoData.InterruptedJobSectorState = 0;
    
    fl_crc_16 = Crc_CalculateCRC16((const uint8*)&Fee_ResetInfoData,( sizeof(Fee_ResetInfoData) - sizeof(uint16)), 0U, TRUE);
    Fee_ResetInfoData.Crc16 = fl_crc_16;
}

static void Fee_UpdateResetInfoAdminData(void)
{
    uint8 fl_PartitionIter;
    uint16 StoredPartitionState = 0U;
    uint16 StoredSectorId;
    #ifdef FEE_TRACE_ENABLE
    FEE_TRACE(RESET_INFO_PART,25U,Fee_ResetInfoData.PartitionState);
    FEE_TRACE(RESET_INFO_PART,25U,Fee_ResetInfoData.InterruptedJobSectorState);
    #endif
    for(fl_PartitionIter = 0U; fl_PartitionIter < FEE_NUM_PARTITIONS; fl_PartitionIter++)
    {
        /* Stored partition is initialised with zero. Left shifting 0x03 for number of partitions * 2,
           then making and operation. This will eleminate other partitions bit
           example:
           Partition 0
           PartitionState = 1100 0110 1110 0010
           0x03 << 0 = 0x03
           StoredPartitionState = 0000 0000 0000 0011 & 1100 0110 1110 0010 = 0000 0000 0000 0010
           StoredPartitionState >> 0 (0*2) = 0000 0000 0000 0010 = 2

           Partition 3
           PartitionState = 1100 0110 1110 0010
           0x03 << 6 = 0x03
           StoredPartitionState = 0000 0000 1100 0000 & 1100 0110 1110 0010 = 0000 0000 1100 0000
           StoredPartitionState >> 6 (3*2) = 0000 0000 0000 0011 = 3

           Sector IDs also caluclated in same way.

        */
        StoredPartitionState = Fee_ResetInfoData.PartitionState & (0x03UL << (fl_PartitionIter*2U));
        StoredPartitionState = StoredPartitionState >> (fl_PartitionIter * 2U);
        switch(StoredPartitionState)
        {
            case 0:
                Fee_InterruptedJobAdminData[fl_PartitionIter].InterruptedJob = FEE_INTERRUPTED_JOB_IDLE;
            break;

            case 1:
                Fee_InterruptedJobAdminData[fl_PartitionIter].InterruptedJob = FEE_WRITE_JOB_INTERRUPTED;
            break;

            case 2:
                Fee_InterruptedJobAdminData[fl_PartitionIter].InterruptedJob = FEE_SECTORSWITCH_JOB_INTERRUPTED;
            break;

            case 3:
                Fee_InterruptedJobAdminData[fl_PartitionIter].InterruptedJob = FEE_SECTOR_ERASE_JOB_INTERRUPTED;
            break;
            
            default:
                /*do nothing*/
            break;

        }
        StoredSectorId = Fee_ResetInfoData.InterruptedJobSectorState & (0x03UL << (fl_PartitionIter*2U));
        StoredSectorId = StoredSectorId >> (fl_PartitionIter * 2U);
        if(StoredSectorId == 1U)
        {
            Fee_InterruptedJobAdminData[fl_PartitionIter].InterruptedJobSectorId = Fee_PartitionConfig[fl_PartitionIter].StartingSectorId;
        }
        if(StoredSectorId == 2U)
        {
            Fee_InterruptedJobAdminData[fl_PartitionIter].InterruptedJobSectorId = Fee_PartitionConfig[fl_PartitionIter].StartingSectorId + 1U;
        }
        StoredPartitionState = 0U;
        StoredSectorId = 0U;
    }
}

static Std_ReturnType ResetInfoHeaderValidate(void)
{
    Std_ReturnType fl_RequestStatus = E_NOT_OK;
    if(FEE_RESET_INFO_HEADER_0 == Fee_ResetInfoHeader[0])
    {
        if(FEE_RESET_INFO_HEADER_1 == Fee_ResetInfoHeader[1])
        {
            if(FEE_RESET_INFO_FOOTER_0 == Fee_ResetInfoFooter[0])
            {
                if(FEE_RESET_INFO_FOOTER_1 == Fee_ResetInfoFooter[1])
                {
                    fl_RequestStatus = E_OK;
                }
            }
        }
    }
    return fl_RequestStatus;
}
static Std_ReturnType Fee_ResetInfoValidateCrc(void)
{
    uint16 CalculatedCrcVal;
    Std_ReturnType fl_RequestStatus = E_NOT_OK;
    CalculatedCrcVal = Crc_CalculateCRC16((const uint8*)&Fee_ResetInfoData, ( sizeof(Fee_ResetInfoData) - sizeof(uint16)), 0, TRUE);
    if(CalculatedCrcVal == Fee_ResetInfoData.Crc16)
    {
        fl_RequestStatus = E_OK;
    }
    return fl_RequestStatus;
}
/**************************************************************************
Function name   : Fee_PrefillHeader
Arguments       : void
Return type     : void
Description     : Function to load Erased Block with default values
**************************************************************************/
static void Fee_PrefillHeader (void)
{
	uint8 BlockID_Count = 0u;
    for(BlockID_Count = 0U ; BlockID_Count < FEE_MAX_ERASE_BLOCK_ARRAY; BlockID_Count++)
    {
        ErasedBlock[BlockID_Count].BlockId = 0xFFFFu;
        ErasedBlock[BlockID_Count].PayloadLength = 0xFFFFu;
        ErasedBlock[BlockID_Count].Reserved1 = 0xFFFFu;
        ErasedBlock[BlockID_Count].Reserved2 = 0xFFu;
        ErasedBlock[BlockID_Count].ValidityFlag = 0xFFu;
    }
}
/**************************************************************************
Function name   : Fee_ProcessInternalResetData
Arguments       : void
Return type     : void
Description     : Service to process Reset Data Operation
**************************************************************************/
static void Fee_ProcessInternalResetData (void)
{
    MemIf_JobResultType fl_JobStatus; 
    Std_ReturnType fl_RequestStatus;
    uint32 fl_FooterAddress;
    switch(Fee_ResetInfoAdminData.ResetInfoState)
    {
        case FEE_PROCESS_RESET_INFO_IDLE:
        break;

        case FEE_PROCESS_RESET_READ_HEADER:
            fl_RequestStatus = FLS_READ(Fee_InternalSectorConfig.SectorStartAddress, (uint8 *)&Fee_ResetInfoHeader[0], FEE_RESET_INFO_SECTOR_HEADER_SIZE);
            if (E_OK == fl_RequestStatus)
            {
                Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_READ_HEADER_WAIT;
            }
            else
            {
                /* Failiure or primary ResetInfo sector is detected, setting flag to force 
                    this sector Erase
                */
                Fee_ResetInfoAdminData.TraverseErrorDetected = TRUE;
                /* Header read is failed, Initiating read for backup sector*/
                Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_READ_BACKUP_INFO;
            } 
        break;

        case FEE_PROCESS_RESET_READ_HEADER_WAIT:
            fl_JobStatus = FLS_GET_JOB_RESULT();
            if(fl_JobStatus != MEMIF_JOB_PENDING)
            {
                if(fl_JobStatus == MEMIF_JOB_OK)
                {
                    Fee_ResetRetryTimer();
                    Fee_RetryManagementData.ReadRetryCount = 0;
                    /* Header is read successful, Assigning state to read footer*/
                    Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_READ_FOOTER;
                }
                else
                {
                    Fee_RetryTimeoutProcess();
                    if(Fee_RetryManagementData.ReadRetryCount > FEE_READ_RETRY_COUNT)
                    {
                        if(FALSE != Fee_RetryManagementData.TimerIsExpired)
                        {
                            Fee_ResetRetryTimer();
                            Fee_RetryManagementData.ReadRetryCount = 0;
                            /* Failiure or primary ResetInfo sector is detected, setting flag to force 
                            this sector Erase
                            */
                            Fee_ResetInfoAdminData.TraverseErrorDetected = TRUE;
                            /* Header read is failed, Initiating read for backup sector*/
                            Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_READ_BACKUP_INFO;
                        }
                        else
                        {
                            Fee_RetryManagementData.ReadRetryCount = 0U;
                            Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_READ_HEADER;
                        }
                    }
                    else
                    {
                        Fee_RetryManagementData.ReadRetryCount += 1U;
                        Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_READ_HEADER;
                    }
                }
            }
        break;

        case FEE_PROCESS_RESET_READ_FOOTER:
            fl_FooterAddress = Fee_InternalSectorConfig.SectorStartAddress + Fee_InternalSectorConfig.SectorSize - (FEE_RESET_INFO_SECTOR_FOOTER_SIZE);
            fl_RequestStatus = FLS_READ(fl_FooterAddress, (uint8 *)&Fee_ResetInfoFooter[0], FEE_RESET_INFO_SECTOR_FOOTER_SIZE);
            if (E_OK == fl_RequestStatus)
            {
                Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_READ_FOOTER_WAIT;
            }
            else
            {
                /* Failiure or primary ResetInfo sector is detected, setting flag to force 
                    this sector Erase
                */
                Fee_ResetInfoAdminData.TraverseErrorDetected = TRUE;
                /* Footer read is failed, Initiating read for backup sector*/
                Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_READ_BACKUP_INFO;
            } 
        break;

        case FEE_PROCESS_RESET_READ_FOOTER_WAIT:
            fl_JobStatus = FLS_GET_JOB_RESULT();
            if(fl_JobStatus != MEMIF_JOB_PENDING)
            {
                if(fl_JobStatus == MEMIF_JOB_OK)
                {
                    Fee_ResetRetryTimer();
                    Fee_RetryManagementData.ReadRetryCount = 0;
                    /* Footer read is success proceeding for validation of Header and Footer */
                    Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_VALIDATE_HEADER;
                }
                else
                {
                    Fee_RetryTimeoutProcess();
                    if(Fee_RetryManagementData.ReadRetryCount > FEE_READ_RETRY_COUNT)
                    {
                        if(FALSE != Fee_RetryManagementData.TimerIsExpired)
                        {
                            Fee_ResetRetryTimer();
                            Fee_RetryManagementData.ReadRetryCount = 0;
                            /* Failiure or primary ResetInfo sector is detected, setting flag to force 
                            this sector Erase
                            */
                            Fee_ResetInfoAdminData.TraverseErrorDetected = TRUE;
                            /* Footer read is failed, Initiating read for backup sector*/
                            Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_READ_BACKUP_INFO;
                        }
                        else 
                        {
                            Fee_RetryManagementData.ReadRetryCount = 0;
                            Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_READ_FOOTER;
                        }
                    }
                    else
                    {
                        Fee_RetryManagementData.ReadRetryCount += 0U;
                        Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_READ_FOOTER;
                    }
                        
                }
            }
        break;

        case FEE_PROCESS_RESET_VALIDATE_HEADER:
            if(E_OK == ResetInfoHeaderValidate())
            {
                /* Reset info sector header and footer is valid 
                   not required to read backup sector So finding the last written location.
                */
                /* 
                    Here we need to find the last written location. We are traversing from End of the ResetInfo sector to Start of the Reset Info Sector.
                    So Loading the address from (StartAddress+Size)-FooterSize.
                */
               if(FEE_UINT32_MAX_VALUE > Fee_InternalSectorConfig.SectorStartAddress)
               {
                    Fee_ResetInfoAdminData.Address = Fee_InternalSectorConfig.SectorStartAddress + Fee_InternalSectorConfig.SectorSize - FEE_RESET_INFO_SECTOR_FOOTER_SIZE;
                    Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_INFO_SEARCH_NEXT_INFO;
               }
               else
               {
                    FEE_DEBUG_ERROR(FALSE);
               }
            }
            else
            {
                /* Header and footer is not valid So we need to look in the backup sector*/
                    /* Failiure of primary ResetInfo sector is detected, setting flag to force 
                       this sector Erase before use.
                    */
                    Fee_ResetInfoAdminData.TraverseErrorDetected = TRUE;
                    Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_READ_BACKUP_INFO;
            }
        break;

        case FEE_PROCESS_RESET_READ_BACKUP_INFO:
            fl_RequestStatus = FLS_READ(Fee_InternalSectorConfig.BackupSectorAddress, (uint8 *)&Fee_ResetInfoData.HeadPattern, FEE_RESET_INFO_BLOCK_LEN);
            if (E_OK == fl_RequestStatus)
            {
                Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_READ_BACKUP_INFO_WAIT;
            }
            else
            {
                /* We are not able to retrive data from Secondry data, So we dont have Reset info 
                   neither from Primary sector nor from Secondry sector. So Clearing ResetInfoAdminData
                   and relying on validating the partition from its own Header and Footer
                */
                Fee_UpdateDefaultResetInfoAdminData();
                #ifdef FEE_TRACE_ENABLE
                FEE_TRACE(UPDATE_RESET_INFO_COMPLETED,1,0);
                #endif
                Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_INFO_JOB_COMPLETED;
            } 
        break;

        case FEE_PROCESS_RESET_READ_BACKUP_INFO_WAIT:
            fl_JobStatus = FLS_GET_JOB_RESULT();
            if(fl_JobStatus != MEMIF_JOB_PENDING)
            {
                if(fl_JobStatus == MEMIF_JOB_OK)
                {
                    Fee_ResetRetryTimer();
                    Fee_RetryManagementData.ReadRetryCount = 0;
                    /* Validating CRC*/
                    if(E_OK == Fee_ResetInfoValidateCrc())
                    {
                        /*Validation of CRC is success, So we are building Fee_InterruptedJobAdminData structure*/
                        Fee_UpdateResetInfoAdminData();
                        /* Fee_InterruptedJobAdminData is ready */
                        /* At this point, we have retrived info from secondary partition, 
                           As per the sequence Primary sector error flag is set, and at completed state, 
                           primary sector is forced to erase before next Reset info write.
                           Still setting error flag to ensure.
                        */
                        Fee_ResetInfoAdminData.TraverseErrorDetected = TRUE;
                        /* Setting state machine to finalise the ResetInfo Traverse process*/
                        #ifdef FEE_TRACE_ENABLE
                        FEE_TRACE(UPDATE_RESET_INFO_COMPLETED,2,0);
                        #endif
                        Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_INFO_JOB_COMPLETED;
                    }
                    else
                    {
                        /*Validation of CRC is failure, this is the use case where Primary Reset info sector 
                        is invalid and also ResetInfo data stored in backup sector also invalid.
                        So we are setting TraverseError and completing the ResetinfoStateProcess
                        */
                        Fee_ResetInfoAdminData.TraverseErrorDetected = TRUE;
                        /* We are not able to retrive data from Secondry data, So we dont have Reset info 
                        neither from Primary sector nor from Secondry sector. So Clearing ResetInfoAdminData
                        and relying on validating the partition from its own Header and Footer
                        */
                        Fee_UpdateDefaultResetInfoAdminData();
                        #ifdef FEE_TRACE_ENABLE
                        FEE_TRACE(UPDATE_RESET_INFO_COMPLETED,3,0);	
                        #endif
                        /* Setting state machine to finalise the ResetInfo Traverse process*/
                        Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_INFO_JOB_COMPLETED;
                    }
                }
                else
                {
                    Fee_RetryTimeoutProcess();
                    if(Fee_RetryManagementData.ReadRetryCount > FEE_READ_RETRY_COUNT)
                    {
                        if(FALSE != Fee_RetryManagementData.TimerIsExpired)
                        {
                            Fee_ResetRetryTimer();
                            Fee_RetryManagementData.ReadRetryCount = 0;
                            /* Not able to retrive the data from backup sector,
                            As per the design this scenario, should not occur.
                            Use case :
                                This location will be written only before erase request of Primary reset info.
                                Also this location will be erased only after writing header, 
                                one valid RestInfoData and Footer in Primary ResetInfo sector.
                                If this location write or erase is interrupted, which means, 
                                we do have a valid Reset info on Primary ResetInfo sector.
                                However, We are updating the status as completed.
                                Erasing of this sector will be taken care before writing first ResetInfo,
                                in primary sector.
                            */
                            /*
                                We will read the backup sector only if the primary sector is corrupted.
                                So if the backup sector read fails even after multiple retries, it means that,
                                we are not able to retrive the resetinfo. 
                                So updating default reset info, marking error and making reset info job as completed.
                            */
                            #ifdef FEE_TRACE_ENABLE
                            FEE_TRACE(UPDATE_RESET_INFO_COMPLETED,4,0);
                            #endif
                            Fee_UpdateDefaultResetInfoAdminData();
                            Fee_ResetInfoAdminData.TraverseErrorDetected = TRUE;
                            Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_INFO_JOB_COMPLETED;
                        }
                        else
                        {
                            Fee_RetryManagementData.ReadRetryCount = 0;
                            Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_READ_BACKUP_INFO;
                        }
                    }
                    else
                    {
                        Fee_RetryManagementData.ReadRetryCount += 1U;
                        Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_READ_BACKUP_INFO;
                    }
                }
            }
        break;

        case FEE_PROCESS_RESET_INFO_SEARCH_NEXT_INFO:
            fl_RequestStatus = FLS_BLANK_CHECK(Fee_ResetInfoAdminData.Address, FEE_RESET_INFO_BLOCK_LEN);
            if (E_OK == fl_RequestStatus)
            {
                Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_INFO_SEARCH_NEXT_INFO_WAIT;
            }
        break;

        case FEE_PROCESS_RESET_INFO_SEARCH_NEXT_INFO_WAIT:
            fl_JobStatus = FLS_GET_JOB_RESULT();
            if(fl_JobStatus != MEMIF_JOB_PENDING)
            {
                if(fl_JobStatus == MEMIF_JOB_OK)
                {
                    /*
                        Location is blank we need to check previous location. So decrementing Address.
                    */
                    Fee_ResetInfoAdminData.Address -= FEE_RESET_INFO_BLOCK_LEN;
                    Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_INFO_SEARCH_NEXT_INFO;
                    
                }
                else 
                {
                    /*
                        Location is not Blank. So this is the location we need to read and CRC validate for ResetInfo.
                        So we are not changing the address.
                    */
                    Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_INFO_READ_RESET_INFO;
                }
            }
        break;

        case FEE_PROCESS_RESET_INFO_READ_RESET_INFO:
            fl_RequestStatus = FLS_READ(Fee_ResetInfoAdminData.Address, (uint8 *)&Fee_ResetInfoData.HeadPattern, FEE_RESET_INFO_BLOCK_LEN);
            if (E_OK == fl_RequestStatus)
            {
                Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_INFO_READ_RESET_INFO_WAIT;
            }
        break;

        case FEE_PROCESS_RESET_INFO_READ_RESET_INFO_WAIT:
            fl_JobStatus = FLS_GET_JOB_RESULT();
            if(fl_JobStatus != MEMIF_JOB_PENDING)
            {
                if(fl_JobStatus == MEMIF_JOB_OK)
                {
                    Fee_ResetRetryTimer();
                    Fee_RetryManagementData.ReadRetryCount = 0;
                    Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_INFO_VALIDATE;
                }
                else
                {
                    Fee_RetryTimeoutProcess();
                    if(Fee_RetryManagementData.ReadRetryCount > FEE_READ_RETRY_COUNT)
                    {
                        if(FALSE != Fee_RetryManagementData.TimerIsExpired)
                        {
                            Fee_ResetRetryTimer();
                            Fee_RetryManagementData.ReadRetryCount = 0;
                        /*  
                            Read is failed even after multiple retries, So we need to get the previous data
                            We need to traverse in back as long as we do have valid data.
                            Use case: 
                                We have validated Header and footer, So this sector is not erase interrupted.
                                The reason we do have single or multiple blank check failiure is,
                                multiple reset states has been continously reset.
                                So we need to travel for the latest valid data
                        */
                            /*
                                We have detected a read error even after multiple retries.
                                It indicates the possible write interruption or memory corruption. 
                                We will traverse towards start of the sector to find a valid ResetInfo.
                                Still, we need to clean up this sector So marking a error.
                            */
                            
                            Fee_ResetInfoAdminData.TraverseErrorDetected = TRUE;
                            /* Until the first possible instance we are traversing backwards*/
                            if(Fee_ResetInfoAdminData.Address > (Fee_InternalSectorConfig.SectorStartAddress + FEE_RESET_INFO_SECTOR_HEADER_SIZE + FEE_RESET_INFO_BLOCK_LEN))
                            {
                                Fee_ResetInfoAdminData.Address -= FEE_RESET_INFO_BLOCK_LEN;
                                Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_INFO_READ_RESET_INFO;
                            }
                            else
                            {
                                #ifdef FEE_TRACE_ENABLE
                                FEE_TRACE(UPDATE_RESET_INFO_COMPLETED,5,0);
                                #endif
                                /*  Even if the first address doesnt have proper value, we are completing the job
                                    Error is already marked.
                                    Loading the default ResetInfo Data
                                */
                                Fee_UpdateDefaultResetInfoAdminData();
                                Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_INFO_JOB_COMPLETED;
                            }
                        }
                        else
                        {
                            Fee_RetryManagementData.ReadRetryCount = 0;
                            Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_INFO_READ_RESET_INFO;
                            
                        }
                    }
                    else
                    {
                        Fee_RetryManagementData.ReadRetryCount += 1U;
                        Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_INFO_READ_RESET_INFO;
                        Fee_ResetInfoAdminData.Address -= FEE_RESET_INFO_BLOCK_LEN;
                    }
                }
            }
        break;


        case FEE_PROCESS_RESET_INFO_VALIDATE:
            /* Validating CRC*/
            if(E_OK == Fee_ResetInfoValidateCrc())
            {
                #ifdef FEE_TRACE_ENABLE
                FEE_TRACE(UPDATE_RESET_INFO_COMPLETED,6,0);
                #endif
                /*Validation of CRC is success, So we are building Fee_InterruptedJobAdminData structure*/
                
                /* Fee_InterruptedJobAdminData is ready */
                Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_INFO_JOB_COMPLETED;
                /* after validating CRC we are constructing the ResetInfoAdminData from Read ResetInfoData*/
                Fee_UpdateResetInfoAdminData();
            }
            else
            {
                /*Validation of CRC is failure, So we need to get the previous data
                  We need to traverse in back as long as we do have valid data.
                  Use case: 
                    We have validated Header and footer, So this sector is not erase interrupted.
                    The reason we do have single or multiple blank check failiure is,
                    multiple reset states has been continously reset.
                    So we need to travel for the latest valid data
                */
                Fee_ResetInfoAdminData.TraverseErrorDetected = TRUE;
                /* Until the first possible instance we are traversing backwards*/
                if(Fee_ResetInfoAdminData.Address > (Fee_InternalSectorConfig.SectorStartAddress + FEE_RESET_INFO_SECTOR_HEADER_SIZE + FEE_RESET_INFO_BLOCK_LEN))
                {
                    Fee_ResetInfoAdminData.Address -= FEE_RESET_INFO_BLOCK_LEN;
                    Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_INFO_READ_RESET_INFO;
                }
                else
                {
                    /*
                        We have traversed till the start of the sector from last written value.
                        We are not able to find a valid reset Info. 
                        Error is already marked.
                        Loading the default ResetInfo Data.
                    */
                    Fee_UpdateDefaultResetInfoAdminData();
                    Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_INFO_JOB_COMPLETED;
                }
                
            }
        break;

        case FEE_PROCESS_RESET_INFO_JOB_COMPLETED:
            /* After construction Fee_InterruptedJobAdminData we are checdking for if any 
               read or crc failiure, which indicates that write interruption on this sector. 
               So we are forcing the ResetInfo address as last of this sector.
               It will force the sector erase with backup value storage, before writing next ResetInfo.
            */
            if(FALSE != Fee_ResetInfoAdminData.TraverseErrorDetected)
            {
                if(FEE_UINT32_MAX_VALUE > Fee_InternalSectorConfig.SectorStartAddress)
                {
                    Fee_ResetInfoAdminData.Address = Fee_InternalSectorConfig.SectorStartAddress + Fee_InternalSectorConfig.SectorSize - FEE_RESET_INFO_SECTOR_FOOTER_SIZE;
                }
                else
                {
                    FEE_DEBUG_ERROR(FALSE);
                }
            }
            /* Notification to upper layer(NvM) that internal job is completed, and NvM can place requests 
                while initialising same has been notified with FEE_START_INTERNAL_JOB,
                to block requests from NvM until Reset info is traversed and 
                Fee_InterruptedJobAdminData needs to be constructed.
            */
            Fee_ResetInfoAdminData.ResetInfoState = FEE_PROCESS_RESET_INFO_IDLE;
            /* Setting JobActiveId from InternalBusy to Idle to allow Fee to accept requests*/
            Fee_Job.JobActiveId = FEE_JOB_IDLE;
            Fee_NotifyInternalJobStatus(FEE_END_INTERNAL_JOB);
        break;

        default:
        /*Do Nothing*/
        break;
    }
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
    Fee_JobStateProcess();
    Fee_PartitionStateProcess();
    Fee_SectorEraseStateProcess();
    Fee_SectorSwitchStateProcess();
    Fee_ProcessInternalResetData();
}
#define FEE_DATA_SEC_END
/* MISRA C-2012 Rule 20.1 : As per visteon coding standards MemMap.h  is used in NvM. It is used to map the memory segments. It will not have any functional Impact */
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
/*Change Description:Erase Failure Handling                                 */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 30-06-2020                                            */
/*Version           :                                                       */
/*By                : lthanga1                                              */
/*Traceability      : RTC#456722                                            */
/*Change Description: Renesas Application note findings fix                 */
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
/*Traceability      :                                                       */
/*Change Description: defect fix                                            */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 24-12-2021                                            */
/*Version           :                                                       */
/*By                : vbalakr3                                              */
/*Traceability      :                                                       */
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
/*Change Description: Fee Cancel  Implemented                               */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 2-12-2022                                             */
/*Version           :                                                       */
/*By                : gthanapp                                              */
/*Traceability      : RTC#1843812                                           */
/*Change Description: Fee Quality                                           */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 16-02-2023                                            */
/*Version           :                                                       */
/*By                : gthanapp                                              */
/*Traceability      : RTC#1918256                                           */
/*Change Description: Fee Coverity High warning fix                         */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 22-02-2023                                            */
/*Version           :                                                       */
/*By                : jponsing                                              */
/*Traceability      : RTC#1925563                                           */
/*Change Description: Sector Switch Fail Case Improvement                   */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 17-Apr-2023                                           */
/*Version           :                                                       */
/*By                : vbalakr3                                              */
/*Traceability      :                                                       */
/*Change Description: Reset Info retain across multiple resets              */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 25-Apr-2023                                           */
/*Version           :                                                       */
/*By                : gthanapp                                              */
/*Traceability      :                                                       */
/*Change Description: Fee Coverity Misra warning Fix                        */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 13-Jul-2023                                           */
/*Version           :                                                       */
/*By                : gthanapp                                              */
/*Traceability      :                                                       */
/*Change Description: Fee Coverity High warning Fix                         */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 19-Jul-2023                                           */
/*Version           :                                                       */
/*By                : gthanapp                                              */
/*Traceability      :                                                       */
/*Change Description: Fee Coverity,Misra,Certc Low warning Fix              */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 15-11-2023                                            */
/*Version           :                                                       */
/*By                : vbalakr3                                              */
/*Traceability      : DICVA-725                                             */
/*Change Description: Quality fix                                           */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 29-05-2024                                            */
/*Version           :                                                       */
/*By                : gthanapp                                              */
/*Traceability      : DICVA-7517                                            */
/*Change Description: Quality fix                                           */
/*--------------------------------------------------------------------------*/

