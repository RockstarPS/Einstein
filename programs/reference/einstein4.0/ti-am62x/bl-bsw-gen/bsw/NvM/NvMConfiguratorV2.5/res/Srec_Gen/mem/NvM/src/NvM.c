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
*  File Name         :  NvM.c                                                *
*  Module Short Name :  NvMMgr                                               *
*  VOBName           :                                                       *
*  Author            : vbalakr3                                              *
*  Description       : This file contains the NvM Manager Request handling   *
*                       functionalities and invokes Fee/Ea                    *
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
#ifndef NVM_C
#define NVM_C
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "NvM.h"
#include "NvM_Types.h"
#include "NvM_Cbk.h"
#include "MemIf.h"
#include "MemLib.h"

#define NVM_CODE_SEC_START
#include "MemMap.h"

#define NVM_DATA_SEC_START
#include "MemMap.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define NV_WRITE_BLOCK       1
#define NV_READ_BLOCK        2
#define NV_INVALIDATE_BLOCK  3
#define NV_CANCEL_BLOCK		 4
#define NV_RESTORE_BLOCK_DEFAULTS   5
#define MAX_UINT8_VALUE      (uint8)255u

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

typedef enum
{
    NVM_STATE_UNINIT=0,
    NVM_STATE_IDLE,
    NVM_STATE_WRITE_BLOCK,
    NVM_STATE_READ_BLOCK,
    NVM_STATE_WRITE_ALL,
    NVM_STATE_READ_ALL,
    NVM_STATE_INVALIDATE,
    NVM_STATE_RESTORE_BLOCK_DEFAULTS
}NvM_StatusType;

typedef enum
{
    NVM_JOB_STATE_IDLE=0,
    NVM_JOB_STATE_WRITE,
    NVM_JOB_STATE_READ,
    NVM_JOB_STATE_INVALIDATE,
    NVM_JOB_RESTORE_BLOCK_DEFAULTS
}NvM_JobStateType;


typedef enum
{
    NVM_JOB_SUBSTATE_IDLE = 0,
    NVM_JOB_SUBSTATE_WRITE_CRC_CALC,
    NVM_JOB_SUBSTATE_WRITE,
    NVM_JOB_SUBSTATE_WRITE_WAIT,
    NVM_JOB_SUBSTATE_VERIFY_READ,
    NVM_JOB_SUBSTATE_VERIFY_READ_WAIT,
    NVM_JOB_SUBSTATE_READ,
    NVM_JOB_SUBSTATE_READ_WAIT,
    NVM_JOB_SUBSTATE_READ_CRC_CALC,
    NVM_JOB_SUBSTATE_READ_CRC_VALIDATE,
    NVM_JOB_SUBSTATE_INVALIDATE,
    NVM_JOB_SUBSTATE_INVALIDATE_CBK_WAIT,
    NVM_JOB_SUBSTATE_RESTORE_BLOCK_DEFAULTS,
    NVM_JOB_SUBSTATE_PROCESS_WRITE_ALL,
#if (NVM_JOB_PRIORITIZATION == STD_ON)
    NVM_JOB_SUBSTATE_CANCEL_WAIT
#endif
}NvM_JobSubStateType;




/* NvM Immediate Queue Parameters */
typedef struct
{
    uint8 CurrentQueueIndex;
    uint8 CurrentQueueSize;
}NvM_ImmediateQueueType;





/* Ongoing Job variables */
typedef struct
{
    uint8* RamBuffer;
    uint16 BlockId;
    uint16 BlockOffset;
    uint16 NvDescriptor;
    uint16 ReadLength;
    uint16 CurrentNvIndex;
    uint16 DirtyNvIndex;
    uint8  RequestType;
    uint8  WriteRetryCount;
    uint8  ReadRetryCount;
    uint8  ReadAllBlockStatus;
    NvM_RequestResultType JobStatus;
    NvM_JobStateType JobState;
    NvM_JobSubStateType JobSubState;
    boolean ProcessState;
}NvM_CurrJobType;


/* Blcok Status Variable */
typedef struct
{
    uint16  ValidNvIndex;
    uint8   BlockProcessStatus;
    uint8   DataSetIndex;
    boolean BlockModifiedStatus;
    boolean BlockValidStatus;
    boolean BlockWriteProt;
    boolean BlockLockedStatus;
}NvM_AdminBlockType;


/* NvM Handling Variables */
typedef struct
{
    uint16 ApiFlags;
    NvM_StatusType NvMState;
    boolean ReadAllRequest;
    boolean WriteAllRequest;
    boolean MemIf_InternalBusy;
    uint8 MemIf_InternalJobState;
    uint32 JobPriorityBits;
#if (NVM_JOB_PRIORITIZATION == STD_ON)
    boolean PreemptedJobFlag;
#endif
}NvM_DataStructType;

typedef struct
{
    uint8*  DataPtr;
    uint32  Length;
    uint32  CrcValue;
    boolean IsFirstCall;
}NvM_CrcStructType;

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

static NvM_AdminBlockType NvM_AdminBlock[NVM_NUM_OF_BLOCKS+1];

static NvM_CurrJobType NvM_CurrentJob;

static NvM_DataStructType NvM_DataStruct;

static NvM_QueueType NvM_JobQueueEntity;

#if (NVM_JOB_PRIORITIZATION == STD_ON)
static NvM_QueueType NvM_PreemptedJobEntity;
#endif

static NvM_CrcStructType NvM_CrcStruct; 

static uint8 NvM_WriteVerificationBuffer[NVM_WRITE_VERIFICATION_DATASIZE];

static uint8 NvM_MirrorRam[NVM_WRITE_VERIFICATION_DATASIZE + 4];
/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/
static NvM_RequestResultType NvM_GetJobResult(void);

static Std_ReturnType NvM_WriteVerifyReadData(void);

static void NvM_ProcessJobSubState(void);

static void NvM_InitRead(void);
static void NvM_ReadCbkWait(void);
static void NvM_ReadCrcCalculate(void);
static void NvM_ReadCrcValidate(void);
static void NvM_ProcessReadAll(void);

static void NvM_CheckNewRequest(void);

static void NvM_WriteCrcCalculate(void);
static void NvM_InitWrite(void);
static void NvM_WriteCbkWait(void);
static void NvM_WriteVerify(void);
static void NvM_WriteVerifyCbkWait(void);
static void NvM_ProcessWriteAll(void);

static void NvM_InitInvalidateBlock(void);
static void NvM_InitInvalidateBlockCbkWait(void);

static void NvM_InternalRestoreBlockDefaults(void);

static void NvM_MirrorRAMCopy(uint8 *Src,uint8 *Dest, uint16 length);
static uint32 NvM_CrcCalculate(uint8 *CrcDataPtr, uint32 CrcLength, uint32 CrcStartValue, boolean CrcIsFirstCall);

static boolean NvM_CheckQueueIsFull(uint8 BlockId);
static void NvM_EnqueueRequestedJob(void);
static Std_ReturnType NvM_DequeueNextJob(void);
static uint8 NvM_GetNextHighPriority (void);
#if (NVM_JOB_PRIORITIZATION == STD_ON)
static Std_ReturnType NvM_PreemptCurrentJob(void);
static void NvM_CancelWait(void);
#endif
Std_ReturnType NvM_CheckForHighPrioRead(uint8 fl_NextPrio);

/*****************************************************************************
*                   Functions                                                *
******************************************************************************/

/**************************************************************************
Function name   : void NvM_Init(void)
Arguments       : void
Return type     : void
Description     : This function is called by App/Scheduler when there is an
                  init required. 
**************************************************************************/
void NvM_Init(void)
{
    uint8 fl_iteration;
    uint16 fl_JobQueueSize;
    NvM_QueueType* fl_JobQueueAddress;
    uint8 fl_internal;

    NvM_DataStruct.NvMState = NVM_STATE_UNINIT;
    /* NvM Admin block initialisation */
    for(fl_iteration=0U; fl_iteration< (NVM_NUM_OF_BLOCKS+1); fl_iteration++)
    {
        NvM_AdminBlock[fl_iteration].BlockModifiedStatus = 0U;
        NvM_AdminBlock[fl_iteration].BlockProcessStatus = 0U;
        NvM_AdminBlock[fl_iteration].BlockValidStatus = 0U;
        NvM_AdminBlock[fl_iteration].ValidNvIndex = 0xFFFFU;
        if(NvM_BlockConfig[fl_iteration].WriteBlockOnce == TRUE)
        {
            NvM_AdminBlock[fl_iteration].BlockWriteProt = FALSE;
        }
        else
        {
            NvM_AdminBlock[fl_iteration].BlockWriteProt = NvM_BlockConfig[fl_iteration].BlockWriteProt;
        }
        NvM_AdminBlock[fl_iteration].DataSetIndex = 0U;
    }
    /* Current Job structure initialise */
    NvM_CurrentJob.BlockId = 0U;
    NvM_CurrentJob.BlockOffset = 0U;
    NvM_CurrentJob.NvDescriptor = 0U;
    NvM_CurrentJob.RamBuffer = NULL;
    NvM_CurrentJob.ReadLength = 0U;
    NvM_CurrentJob.RequestType = 0U;
    NvM_CurrentJob.CurrentNvIndex = 0U;
    NvM_CurrentJob.DirtyNvIndex = 0U;

    /* NvM handling data structure initialise */
    NvM_DataStruct.ApiFlags = 0U;
    NvM_DataStruct.MemIf_InternalBusy = FALSE;
    NvM_DataStruct.ReadAllRequest = FALSE;
    NvM_DataStruct.WriteAllRequest = FALSE;
    NvM_DataStruct.MemIf_InternalJobState = NVM_MEMIF_END_INTERNAL_JOB;
    NvM_DataStruct.JobPriorityBits = 0U;
#if (NVM_JOB_PRIORITIZATION == STD_ON)
    NvM_DataStruct.PreemptedJobFlag = FALSE;

    /* Preempted Job structure initialise */
    NvM_PreemptedJobEntity.BlockId = 0U;
    NvM_PreemptedJobEntity.BlockOffset = 0U;
    NvM_PreemptedJobEntity.DataPointer = NULL;
    NvM_PreemptedJobEntity.RequestType = 0U;
    NvM_PreemptedJobEntity.ReadLength = 0U;
#endif

    for(fl_iteration=0U; fl_iteration < NVM_NUM_OF_PRIORITY; fl_iteration++)
    {
        NvM_JobQueueParameter[fl_iteration].CurrentQueueIndex = 0U;
        NvM_JobQueueParameter[fl_iteration].CurrentQueueSize = 0U;
        NvM_JobQueueParameter[fl_iteration].RequestQueueIndex = 0U;
    }
    for(fl_iteration=0U; fl_iteration < NVM_MAX_JOB_PRIORITY; fl_iteration++)
    {
        if (NULL != NvM_JobQueueManagementTable[fl_iteration].JobQueueAddress)
        {
            fl_JobQueueSize = NvM_JobQueueManagementTable[fl_iteration].JobQueueSize;
            fl_JobQueueAddress = NvM_JobQueueManagementTable[fl_iteration].JobQueueAddress;
            for(fl_internal = 0U; fl_internal < fl_JobQueueSize; fl_internal++ )
            {
                fl_JobQueueAddress[fl_internal].BlockId = 0U;
                fl_JobQueueAddress[fl_internal].BlockOffset = 0U;
                fl_JobQueueAddress[fl_internal].DataPointer = NULL;
                fl_JobQueueAddress[fl_internal].ReadLength = 0U;
                fl_JobQueueAddress[fl_internal].RequestType = 0U;
            }
        }
    }

    NvM_JobQueueEntity.BlockId = 0U;
    NvM_JobQueueEntity.BlockOffset = 0U;
    NvM_JobQueueEntity.DataPointer = NULL;
    NvM_JobQueueEntity.RequestType = 0U;
    NvM_JobQueueEntity.ReadLength = 0U;


    NvM_CrcStruct.DataPtr = NULL;
    NvM_CrcStruct.Length = 0U;
    NvM_CrcStruct.CrcValue = 0xFFFFU;
    NvM_CrcStruct.IsFirstCall = TRUE;



    NvM_DataStruct.NvMState = NVM_STATE_IDLE;

}

/**************************************************************************
Function name   : Std_ReturnType NvM_SetDataIndex(NvM_BlockIdType BlockId, uint8 DataIndex)
Arguments       : void
Return type     : void
Description     : This function is used to set the Data set index of the DatasetBlock 
**************************************************************************/
Std_ReturnType NvM_SetDataIndex(NvM_BlockIdType BlockId, uint8 DataIndex)
{
    Std_ReturnType fl_RetVal = E_OK;
    if 
    (
        (BlockId > NVM_NUM_OF_BLOCKS) || \
        (NVM_STATE_UNINIT == NvM_DataStruct.NvMState) || \
        (NVM_DATASET_BLOCK != NvM_BlockConfig[BlockId].BlockManagementType) || \
		(NVM_REQ_PENDING == NvM_AdminBlock[BlockId].BlockProcessStatus) || \
        (DataIndex >= (NvM_BlockConfig[BlockId].NvBlockNum + NvM_BlockConfig[BlockId].RomBlockNum)) 
    )
    {
        fl_RetVal = E_NOT_OK;
    }
    
    if(fl_RetVal == E_OK)
    {
        NvM_AdminBlock[BlockId].DataSetIndex = DataIndex;
    }
    return fl_RetVal;
}


/**************************************************************************
Function name   : Std_ReturnType NvM_GetDataIndex( NvM_BlockIdType BlockId, uint8* DataIndexPtr)
Arguments       : NvM_BlockIdType BlockId, uint8* DataIndexPtr
Return type     : Std_ReturnType
                  E_OK: The index position has been retrieved successfully.
                  E_NOT_OK: An error occurred
Description     : Service for getting the currently set DataIndex of a dataset NVRAM block
**************************************************************************/
Std_ReturnType NvM_GetDataIndex( NvM_BlockIdType BlockId, uint8* DataIndexPtr)
{
    *DataIndexPtr = 0u;
    Std_ReturnType fl_RetVal = E_OK;
    if
    (
        (BlockId > NVM_NUM_OF_BLOCKS) || \
        (NVM_STATE_UNINIT == NvM_DataStruct.NvMState) || \
		(NVM_DATASET_BLOCK != NvM_BlockConfig[BlockId].BlockManagementType)  
    )
    {
        fl_RetVal = E_NOT_OK;
    }
    if(fl_RetVal == E_OK)
    {
        *DataIndexPtr = NvM_AdminBlock[BlockId].DataSetIndex;
    }
    return fl_RetVal;
}

/**************************************************************************
Function name   : Std_ReturnType NvM_SetBlockProtection(NvM_BlockIdType BlockId, boolean ProtectionEnabled)
Arguments       : NvM_BlockIdType BlockId, boolean ProtectionEnabled
Return type     : Std_ReturnType
                  E_OK: The block was enabled/disabled as requested
                  E_NOT_OK: An error occured
Description     : Service for setting/resetting the write protection for a NV block
**************************************************************************/
Std_ReturnType NvM_SetBlockProtection(NvM_BlockIdType BlockId, boolean ProtectionEnabled)
{
    Std_ReturnType fl_RetVal = E_OK;
    if(BlockId <= NVM_NUM_OF_BLOCKS)
    {
        if(NvM_BlockConfig[BlockId].WriteBlockOnce == TRUE)
        {
            fl_RetVal = E_NOT_OK;
        }
        if(NvM_DataStruct.NvMState == NVM_STATE_UNINIT)
        {
            fl_RetVal = E_NOT_OK;
        }
        if(fl_RetVal == E_OK)
        {
            NvM_AdminBlock[BlockId].BlockWriteProt = ProtectionEnabled;
        }
    }
    else
    {
        fl_RetVal = E_NOT_OK;
    }
    return fl_RetVal;
}

/**************************************************************************
Function name   : Std_ReturnType NvM_GetErrorStatus( NvM_BlockIdType BlockId, NvM_RequestResultType* RequestResultPtr)
Arguments       : NvM_BlockIdType BlockId, NvM_RequestResultType* RequestResultPtr
Return type     : Std_ReturnType
                  E_OK: The block dependent error/status information was read successfully.
                  E_NOT_OK: An error occured.
Description     : Service to read the block dependent error/status information
**************************************************************************/
Std_ReturnType NvM_GetErrorStatus( NvM_BlockIdType BlockId, NvM_RequestResultType* RequestResultPtr)
{
    Std_ReturnType fl_RetVal = E_OK;

    if(BlockId <= NVM_NUM_OF_BLOCKS)
    {
        if(NvM_DataStruct.NvMState == NVM_STATE_UNINIT)
        {
            fl_RetVal = E_NOT_OK;
        }
        if(fl_RetVal == E_OK)
        {
            *RequestResultPtr = NvM_AdminBlock[BlockId].BlockProcessStatus;
        }
    }
    else
    {
        fl_RetVal = E_NOT_OK;
		*RequestResultPtr = NVM_REQ_NOT_OK;
    }
    return fl_RetVal;
}

/**************************************************************************
Function name   : void NvM_GetVersionInfo( Std_VersionInfoType* versioninfo)
Arguments       : Std_VersionInfoType* versioninfo
Return type     : void
Description     : Service to get the version information of the NvM module.
**************************************************************************/    
void NvM_GetVersionInfo( Std_VersionInfoType* versioninfo)
{
}

/**************************************************************************
Function name   : Std_ReturnType NvM_SetRamBlockStatus( NvM_BlockIdType BlockId, boolean BlockChanged)
Arguments       : NvM_BlockIdType BlockId, boolean BlockChanged
Return type     : Std_ReturnType
                  E_OK: The status of the RAM-Block was changed as requested.
                  E_NOT_OK: An error occurred.
Description     : Service for setting the RAM block status of an NVRAM block.
**************************************************************************/
Std_ReturnType NvM_SetRamBlockStatus( NvM_BlockIdType BlockId, boolean BlockChanged)
{
    Std_ReturnType fl_RetVal = E_OK;
    if(BlockId <= NVM_NUM_OF_BLOCKS)
    {
        if
        (
            NVM_STATE_UNINIT == NvM_DataStruct.NvMState ||\
            NULL_PTR == NvM_BlockConfig[BlockId].RamBlockDataAddress ||\
            FALSE == NvM_BlockConfig[BlockId].BlockUseSetRamBlockStatus ||\
            NVM_REQ_PENDING == NvM_AdminBlock[BlockId].BlockProcessStatus 
        )
        {
            fl_RetVal = E_NOT_OK;
        }
        if(fl_RetVal == E_OK)
        {
            if(FALSE != BlockChanged)
            {
                NvM_AdminBlock[BlockId].BlockModifiedStatus = BlockChanged;
            }
        }
    }
    else
    {
        fl_RetVal = E_NOT_OK;
    }
    return fl_RetVal;
}

/**************************************************************************
Function name   : void NvM_SetBlockLockStatus( NvM_BlockIdType BlockId, boolean BlockLocked)
Arguments       : NvM_BlockIdType BlockId, boolean BlockLocked
Return type     : void
Description     : Service for setting the lock status of a permanent RAM block or of the explicit
                  synchronization of a NVRAM block.
**************************************************************************/
void NvM_SetBlockLockStatus( NvM_BlockIdType BlockId, boolean BlockLocked)
{
    if(BlockId <= NVM_NUM_OF_BLOCKS)
    {
        NvM_AdminBlock[BlockId].BlockLockedStatus = BlockLocked;
    }
}

/**************************************************************************
Function name   : Std_ReturnType NvM_CancelJobs( NvM_BlockIdType BlockId)
Arguments       : NvM_BlockIdType BlockId
Return type     : Std_ReturnType
                  E_OK: The job was successfully removed from queue.
                  E_NOT_OK: The job could not be found in the queue.
Description     : Service to cancel all jobs pending for a NV block.
***********************************************************************/
Std_ReturnType NvM_CancelJobs( NvM_BlockIdType BlockId)
{
    Std_ReturnType fl_RetVal = E_NOT_OK;

    if(BlockId <= NVM_NUM_OF_BLOCKS)
    {
        if(NVM_REQ_PENDING == NvM_AdminBlock[BlockId].BlockProcessStatus)
        {
            if((NvM_CurrentJob.JobState != NVM_JOB_STATE_IDLE) && (NvM_CurrentJob.BlockId != BlockId))
            {
                NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_CANCELED;
                MemIf_Cancel(NvM_BlockConfig[BlockId].NvRamDeviceId);
                if(NULL != NvM_BlockConfig[BlockId].SingleBlockCallback)
                {
                    (void) NvM_BlockConfig[BlockId].SingleBlockCallback(NVM_CANCEL_JOBS,NVM_REQ_CANCELED);
                }
                fl_RetVal = E_OK;
            }
        }
    }
    return fl_RetVal;
}


/**************************************************************************
Function name   : Std_ReturnType NvM_ReadBlock( NvM_BlockIdType BlockId,void* NvM_DstPtr)
Arguments       : NvM_BlockIdType BlockId,void* NvM_DstPtr
Return type     : Std_ReturnType
                   E_OK: request has been accepted
                   E_NOT_OK: request has not been accepted
Description     : Service to copy the data of the NV block to its corresponding RAM block
***********************************************************************/
Std_ReturnType NvM_ReadBlock( NvM_BlockIdType BlockId,void* NvM_DstPtr)
{
    Std_ReturnType NvM_RetVal = E_NOT_OK;
    if(NvM_AdminBlock[BlockId].BlockProcessStatus != NVM_REQ_PENDING)
    {
        if(BlockId <= NVM_NUM_OF_BLOCKS)
        {
            NvM_EnterCriticalSection();
            if(NvM_CheckQueueIsFull(BlockId))
            {
                NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
                NvM_RetVal = E_NOT_OK;
            }
            else
            {
                NvM_JobQueueEntity.BlockId = BlockId;
                NvM_JobQueueEntity.RequestType = NV_READ_BLOCK;
                NvM_JobQueueEntity.ReadLength = NvM_BlockConfig[BlockId].NvBlockLength;
                if(NvM_DstPtr == NULL)
                {
                    NvM_JobQueueEntity.DataPointer = NvM_BlockConfig[BlockId].RamBlockDataAddress;
                }
                else
                {
                    NvM_JobQueueEntity.DataPointer = (uint8*)NvM_DstPtr;
                }
                NvM_EnqueueRequestedJob();
                NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_PENDING;
                NvM_RetVal = E_OK;
            }
            NvM_ExitCriticalSection();
        }
    }
    return NvM_RetVal;
}

/**************************************************************************
Function name   : Std_ReturnType NvM_WriteBlock(NvM_BlockIdType BlockId, const void* NvM_SrcPtr)
Arguments       : NvM_BlockIdType BlockId, const void* NvM_SrcPtr
Return type     : Std_ReturnType
                   E_OK: request has been accepted
                   E_NOT_OK: request has not been accepted
Description     : Service to copy the data of the RAM block to its corresponding NV block.
***********************************************************************/
Std_ReturnType NvM_WriteBlock(NvM_BlockIdType BlockId, const void* NvM_SrcPtr)
{
    Std_ReturnType NvM_RetVal = E_NOT_OK;
    if(NvM_AdminBlock[BlockId].BlockProcessStatus != NVM_REQ_PENDING)
    {
        if(BlockId <= NVM_NUM_OF_BLOCKS)
        {
            NvM_EnterCriticalSection();
            if
			(
				(FALSE != NvM_AdminBlock[BlockId].BlockWriteProt)    || \
	            (FALSE != NvM_AdminBlock[BlockId].BlockLockedStatus)  || \
	            (NvM_CheckQueueIsFull(BlockId)) || \
	            (NVM_DATASET_BLOCK == NvM_BlockConfig[BlockId].BlockManagementType  && NvM_AdminBlock[BlockId].DataSetIndex >= NvM_BlockConfig[BlockId].NvBlockNum)
            )
			{
                NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
                NvM_RetVal = E_NOT_OK;
            }
            else
            {
                NvM_JobQueueEntity.BlockId = BlockId;
                NvM_JobQueueEntity.RequestType = NV_WRITE_BLOCK;
                NvM_JobQueueEntity.ReadLength = NvM_BlockConfig[BlockId].NvBlockLength;
                if(NvM_SrcPtr == NULL)
                {
                    NvM_JobQueueEntity.DataPointer = NvM_BlockConfig[BlockId].RamBlockDataAddress;
                }
                else
                {
                    NvM_JobQueueEntity.DataPointer = (uint8*)NvM_SrcPtr;
                }
                NvM_EnqueueRequestedJob();
                NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_PENDING;
                NvM_RetVal = E_OK;
            }
            NvM_ExitCriticalSection();
        }
    }
    return NvM_RetVal;
}

/**************************************************************************
Function name   : Std_ReturnType NvM_RestoreBlockDefaults( NvM_BlockIdType BlockId, void* NvM_DestPtr)
Arguments       : NvM_BlockIdType BlockId, void* NvM_DestPtr
Return type     : Std_ReturnType
                   E_OK: request has been accepted
                   E_NOT_OK: request has not been accepted
Description     : Service to restore the default data to its corresponding RAM block
***********************************************************************/
Std_ReturnType NvM_RestoreBlockDefaults( NvM_BlockIdType BlockId, void* NvM_DestPtr)
{
    Std_ReturnType NvM_RetVal = E_NOT_OK;
    if(BlockId <= NVM_NUM_OF_BLOCKS)
    {
        if(NvM_AdminBlock[BlockId].BlockProcessStatus != NVM_REQ_PENDING)
        {
            NvM_EnterCriticalSection();
            if
			(
				(FALSE != NvM_AdminBlock[BlockId].BlockWriteProt)    || \
	            (FALSE != NvM_AdminBlock[BlockId].BlockLockedStatus)  || \
	            (NvM_CheckQueueIsFull(BlockId)) || \
	            (0u ==  NvM_BlockConfig[BlockId].RomBlockNum && NULL == NvM_BlockConfig[BlockId].InitCallback) || \
	            (NVM_DATASET_BLOCK == NvM_BlockConfig[BlockId].BlockManagementType && NvM_AdminBlock[BlockId].DataSetIndex  < NvM_BlockConfig[BlockId].NvBlockNum)
			)     
            {
                NvM_RetVal = E_NOT_OK;
            }
            else
            {
                NvM_JobQueueEntity.BlockId = BlockId;
                NvM_JobQueueEntity.RequestType = NV_RESTORE_BLOCK_DEFAULTS;
                NvM_JobQueueEntity.ReadLength = NvM_BlockConfig[BlockId].NvBlockLength;
                if(NvM_DestPtr == NULL)
                {
                    NvM_JobQueueEntity.DataPointer = NvM_BlockConfig[BlockId].RamBlockDataAddress;
                }
                else
                {
                    NvM_JobQueueEntity.DataPointer = (uint8*)NvM_DestPtr;
                }
                NvM_EnqueueRequestedJob();
                NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_PENDING;
                NvM_RetVal = E_OK;
            }
            NvM_ExitCriticalSection();
        }
    }
    return NvM_RetVal;
}

/**************************************************************************
Function name   : Std_ReturnType NvM_EraseNvBlock(NvM_BlockIdType BlockId)
Arguments       : NvM_BlockIdType BlockId
Return type     : Std_ReturnType
                   E_OK: request has been accepted
                   E_NOT_OK: request has not been accepted
Description     : Service to erase a NV block.
***********************************************************************/
Std_ReturnType NvM_EraseNvBlock(NvM_BlockIdType BlockId)
{
    return E_OK;
}

/**************************************************************************
Function name   : void NvM_CancelWriteAll(void)
Arguments       : void
Return type     : void
Description     : Service to cancel a running NvM_WriteAll request.
***********************************************************************/
void NvM_CancelWriteAll(void)
{
    NvM_DataStruct.WriteAllRequest =  FALSE;
}

/**************************************************************************
Function name   : Std_ReturnType NvM_InvalidateNvBlock(NvM_BlockIdType BlockId)
Arguments       : NvM_BlockIdType BlockId
Return type     : Std_ReturnType
                   E_OK: request has been accepted
                   E_NOT_OK: request has not been accepted
Description     : Service to invalidate a NV block.
***********************************************************************/
Std_ReturnType NvM_InvalidateNvBlock(NvM_BlockIdType BlockId)
{
    Std_ReturnType NvM_RetVal = E_NOT_OK;
    if(BlockId <= NVM_NUM_OF_BLOCKS)
    {
        NvM_EnterCriticalSection();
        if
		(
			(FALSE != NvM_AdminBlock[BlockId].BlockWriteProt)    || \
	        (FALSE != NvM_AdminBlock[BlockId].BlockLockedStatus)  || \
	        (NvM_CheckQueueIsFull(BlockId)) || \
	        (NVM_DATASET_BLOCK == NvM_BlockConfig[BlockId].BlockManagementType && NvM_AdminBlock[BlockId].DataSetIndex >= NvM_BlockConfig[BlockId].NvBlockNum)
		)
        {
            NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
            NvM_RetVal = E_NOT_OK;
        }
        else
        {
            NvM_JobQueueEntity.BlockId = BlockId;
            NvM_JobQueueEntity.RequestType = NV_INVALIDATE_BLOCK;
            NvM_JobQueueEntity.DataPointer = NvM_BlockConfig[BlockId].RamBlockDataAddress;
            NvM_EnqueueRequestedJob();
            NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_PENDING;
            NvM_RetVal = E_OK;
        }
        NvM_ExitCriticalSection();
    }
    return NvM_RetVal;

}

/**************************************************************************
Function name   : Std_ReturnType NvM_ReadPRAMBlock(NvM_BlockIdType BlockId)
Arguments       : NvM_BlockIdType BlockId
Return type     : Std_ReturnType
                   E_OK: request has been accepted
                   E_NOT_OK: request has not been accepted
Description     : Service to copy the data of the NV block to its corresponding 
                  permanent RAM block.
***********************************************************************/
Std_ReturnType NvM_ReadPRAMBlock(NvM_BlockIdType BlockId)
{
    Std_ReturnType NvM_RetVal = E_NOT_OK;
    if(BlockId <= NVM_NUM_OF_BLOCKS)
    {
        NvM_EnterCriticalSection();
        if(NvM_BlockConfig[BlockId].RamBlockDataAddress == NULL)
        {
            NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
        }
        else
        {
            if(NvM_CheckQueueIsFull(BlockId))
            {
                NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
            }
            else
            {
                NvM_JobQueueEntity.BlockId = BlockId;
                NvM_JobQueueEntity.RequestType = NV_READ_BLOCK;
                NvM_JobQueueEntity.DataPointer = NvM_BlockConfig[BlockId].RamBlockDataAddress;
                NvM_JobQueueEntity.ReadLength = NvM_BlockConfig[BlockId].NvBlockLength;
                NvM_RetVal = E_OK;
                NvM_EnqueueRequestedJob();
                NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_PENDING;
            }
        }
        NvM_ExitCriticalSection();
    }
    return NvM_RetVal;
}

/**************************************************************************
Function name   : Std_ReturnType NvM_WritePRAMBlock(NvM_BlockIdType BlockId)
Arguments       : NvM_BlockIdType BlockId
Return type     : Std_ReturnType
                   E_OK: request has been accepted
                   E_NOT_OK: request has not been accepted
Description     : Service to copy the data of the RAM block to its corresponding 
                  permanent RAM Block
***********************************************************************/
Std_ReturnType NvM_WritePRAMBlock(NvM_BlockIdType BlockId)
{
    Std_ReturnType NvM_RetVal = E_NOT_OK;
    if(BlockId <= NVM_NUM_OF_BLOCKS)
    {
        NvM_EnterCriticalSection();
        if
		(
			(NvM_BlockConfig[BlockId].RamBlockDataAddress == NULL) || \
	        (NVM_DATASET_BLOCK == NvM_BlockConfig[BlockId].BlockManagementType && NvM_AdminBlock[BlockId].DataSetIndex >= NvM_BlockConfig[BlockId].NvBlockNum)
		)
        {
            NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
            NvM_RetVal = E_NOT_OK;
        }
        else
        {
            if(NvM_CheckQueueIsFull(BlockId))
            {
                NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
                NvM_RetVal = E_NOT_OK;
            }
            else
            {
                NvM_JobQueueEntity.BlockId = BlockId;
                NvM_JobQueueEntity.RequestType = NV_WRITE_BLOCK;
                NvM_JobQueueEntity.DataPointer = NvM_BlockConfig[BlockId].RamBlockDataAddress;
                NvM_JobQueueEntity.ReadLength = NvM_BlockConfig[BlockId].NvBlockLength;
                NvM_RetVal = E_OK;
                NvM_EnqueueRequestedJob();
                NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_PENDING;
            }
        }
        NvM_ExitCriticalSection();
    }
    return NvM_RetVal;
}

/**************************************************************************
Function name   : Std_ReturnType NvM_RestorePRAMBlockDefaults(NvM_BlockIdType BlockId)
Arguments       : NvM_BlockIdType BlockId
Return type     : Std_ReturnType
                   E_OK: request has been accepted
                   E_NOT_OK: request has not been accepted
Description     : Service to restore the default data to its corresponding permanent RAM block.
***********************************************************************/
Std_ReturnType NvM_RestorePRAMBlockDefaults(NvM_BlockIdType BlockId)
{
    Std_ReturnType NvM_RetVal = E_NOT_OK;
    if(BlockId <= NVM_NUM_OF_BLOCKS)
    {
        if(NvM_AdminBlock[BlockId].BlockProcessStatus != NVM_REQ_PENDING)
        {
            if
			(
				(FALSE != NvM_AdminBlock[BlockId].BlockWriteProt)    || \
	            (FALSE != NvM_AdminBlock[BlockId].BlockLockedStatus)  || \
	            (NvM_CheckQueueIsFull(BlockId)) || \
                (NULL == NvM_BlockConfig[BlockId].RamBlockDataAddress)||\
	            (0u ==  NvM_BlockConfig[BlockId].RomBlockNum && NULL == NvM_BlockConfig[BlockId].InitCallback) || \
	            (NVM_DATASET_BLOCK == NvM_BlockConfig[BlockId].BlockManagementType && NvM_AdminBlock[BlockId].DataSetIndex  < NvM_BlockConfig[BlockId].NvBlockNum)
			)     
            {
                NvM_RetVal = E_NOT_OK;
            }
            else
            {
                NvM_EnterCriticalSection();
                NvM_JobQueueEntity.BlockId = BlockId;
                NvM_JobQueueEntity.RequestType = NV_RESTORE_BLOCK_DEFAULTS;
                NvM_JobQueueEntity.ReadLength = NvM_BlockConfig[BlockId].NvBlockLength;
                NvM_JobQueueEntity.DataPointer = NvM_BlockConfig[BlockId].RamBlockDataAddress;
                NvM_EnqueueRequestedJob();
                NvM_AdminBlock[BlockId].BlockProcessStatus = NVM_REQ_PENDING;
                NvM_RetVal = E_OK;
                NvM_ExitCriticalSection();
            }
        }
    }
    return NvM_RetVal;
}

/**************************************************************************
Function name   : void NvM_ReadAll(void)
Arguments       : void
Return type     : void
Description     : Initiates a multi block read request.
***********************************************************************/
void NvM_ReadAll(void)
{
    NvM_DataStruct.ReadAllRequest = TRUE;
    NvM_CurrentJob.ReadAllBlockStatus = NVM_REQ_OK;
}

/**************************************************************************
Function name   : void NvM_WriteAll(void)
Arguments       : void
Return type     : void
Description     : Initiates a multi block write request.
***********************************************************************/
void NvM_WriteAll(void)
{
    NvM_DataStruct.WriteAllRequest = TRUE;
}

/**************************************************************************
Function name   : void NvM_ValidateAll(void)
Arguments       : void
Return type     : void
Description     : Initiates a multi block validation request
***********************************************************************/
void NvM_ValidateAll(void)
{
}

/**************************************************************************
Function name   : void NvM_JobEndNotification(void)
Arguments       : void
Return type     : void
Description     : Function to be used by the underlying memory abstraction 
                  to signal end of job without error
***********************************************************************/
void NvM_JobEndNotification(void)
{
    NvM_RequestResultType fl_RequestResult;
    fl_RequestResult = NvM_GetJobResult();
    NvM_CurrentJob.JobStatus = fl_RequestResult;
}

/**************************************************************************
Function name   : void NvM_JobErrorNotification(void)
Arguments       : void
Return type     : void
Description     : Function to be used by the underlying memory abstraction 
                  to signal end of job with error
***********************************************************************/
void NvM_JobErrorNotification(void)
{
    NvM_RequestResultType fl_RequestResult;
    fl_RequestResult = NvM_GetJobResult();
    NvM_CurrentJob.JobStatus = fl_RequestResult;
}

/**************************************************************************
Function name   : void NvM_Memif_Internal_Notification(uint8 status)
Arguments       : status
Return type     : void
Description     : Service to Notify MemIf Internal Job.
***********************************************************************/
void NvM_Memif_Internal_Notification(uint8 status)
{
    switch(status)
    {
        case NVM_MEMIF_START_INTERNAL_JOB:
            NvM_DataStruct.MemIf_InternalBusy = TRUE;
            NvM_DataStruct.MemIf_InternalJobState = NVM_MEMIF_START_INTERNAL_JOB;
        break;

        case NVM_MEMIF_END_INTERNAL_JOB:
            NvM_DataStruct.MemIf_InternalBusy = FALSE;
            NvM_DataStruct.MemIf_InternalJobState = NVM_MEMIF_END_INTERNAL_JOB;        
        break;

        case NVM_MEMIF_SUSPEND_INTERNAL_JOB:
            NvM_DataStruct.MemIf_InternalBusy = FALSE;
            NvM_DataStruct.MemIf_InternalJobState = NVM_MEMIF_SUSPEND_INTERNAL_JOB;
        break;

        case NVM_MEMIF_RESUME_INTERNAL_JOB:
            NvM_DataStruct.MemIf_InternalBusy = TRUE;
            NvM_DataStruct.MemIf_InternalJobState = NVM_MEMIF_RESUME_INTERNAL_JOB;
        break;

        default:
        break;
    }
}

/**************************************************************************
Function name   : void NvM_JobErrorNotification(void)
Arguments       : void
Return type     : NvM_RequestResultType
Description     : Function to get the job result
***********************************************************************/
static NvM_RequestResultType NvM_GetJobResult(void)
{
    MemIf_JobResultType fl_JobResult;
    NvM_RequestResultType fl_RetVal;
    uint8 DeviceId = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvRamDeviceId;
    fl_JobResult = MemIf_GetJobResult(DeviceId);
    switch(fl_JobResult)
    {
        case MEMIF_JOB_PENDING:
        fl_RetVal = NVM_REQ_PENDING;
        break;

        case MEMIF_JOB_OK:
        fl_RetVal = NVM_REQ_OK;
        break;

        case MEMIF_JOB_FAILED:
        fl_RetVal = NVM_REQ_NOT_OK;
        break;

        case MEMIF_JOB_CANCELED:
        fl_RetVal = NVM_REQ_CANCELED;
        break;

        case MEMIF_BLOCK_INVALID:
        fl_RetVal = NVM_REQ_NV_INVALIDATED;
        break;

        case MEMIF_BLOCK_INCONSISTENT:
        fl_RetVal = NVM_REQ_INTEGRITY_FAILED;
        break;

        default:
        fl_RetVal = NVM_REQ_NOT_OK;
        break;
    }
    return fl_RetVal;
}


/**************************************************************************
Function name   : void NvM_MainFunction(void)
Arguments       : void
Return type     : void
Description     : Service for performing the processing of the NvM jobs.
***********************************************************************/
void NvM_MainFunction(void)
{
    NvM_CheckNewRequest();
    do
    {
        
        //printf("HELLO_NvM\n");
        NvM_ProcessJobSubState();
    }while(FALSE != NvM_CurrentJob.ProcessState);
}

/**************************************************************************
Function name   : void NvM_CheckNewRequest(void)
Arguments       : void
Return type     : void
Description     : Check the New Request
**************************************************************************/
static void NvM_CheckNewRequest(void)
{
    uint8 fl_NextPrio = 0xFF;
    if((MEMIF_IDLE == MemIf_GetStatus(MEMIF_FEE)) && (MEMIF_IDLE == MemIf_GetStatus(MEMIF_EA)) && (MEMIF_IDLE == MemIf_GetStatus(MEMIF_SNVM))) 
    {
        if(NvM_DataStruct.NvMState == NVM_STATE_IDLE)
        {
            if(E_OK == NvM_DequeueNextJob())
            {
                NvM_CurrentJob.BlockId = NvM_JobQueueEntity.BlockId;
                NvM_CurrentJob.BlockOffset = NvM_JobQueueEntity.BlockOffset;
                NvM_CurrentJob.RamBuffer = NvM_JobQueueEntity.DataPointer;
                NvM_CurrentJob.ReadLength = NvM_JobQueueEntity.ReadLength;
                NvM_CurrentJob.RequestType = NvM_JobQueueEntity.RequestType;
                NvM_CurrentJob.WriteRetryCount = NvM_BlockConfig[NvM_CurrentJob.BlockId].MaxNumWriteRetries + (uint8)1u;
                NvM_CurrentJob.ReadRetryCount = NvM_BlockConfig[NvM_CurrentJob.BlockId].MaxNumReadRetries + (uint8)1u;
                if(NVM_REQ_CANCELED != NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockProcessStatus)
                {
                    switch(NvM_CurrentJob.RequestType)
                    {
                        case NV_WRITE_BLOCK:
                            NvM_DataStruct.NvMState = NVM_STATE_WRITE_BLOCK;
                            NvM_CurrentJob.JobState = NVM_JOB_STATE_WRITE;
                            NvM_CrcStruct.IsFirstCall = TRUE;
                            NvM_CrcStruct.DataPtr =  NvM_CurrentJob.RamBuffer;
                            NvM_CrcStruct.Length =  NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockLength;
                            NvM_CrcStruct.CrcValue = 0xFFFFU;
                            NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE_CRC_CALC;
                            NvM_CurrentJob.ProcessState = TRUE;
                            if(NVM_REDUNDANT_BLOCK == NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockManagementType)
                            {
                                NvM_CurrentJob.DirtyNvIndex = 0x03;
                                if(FALSE == NvM_AdminBlock[NvM_CurrentJob.BlockId].ValidNvIndex)
                                {
                                    NvM_CurrentJob.NvDescriptor = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockBaseNumber + 1U;
                                    NvM_CurrentJob.CurrentNvIndex = 1U;
                                }
                                else
                                {
                                    NvM_CurrentJob.NvDescriptor = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockBaseNumber;
                                    NvM_CurrentJob.CurrentNvIndex = 0U;
                                }
                                NvM_AdminBlock[NvM_CurrentJob.BlockId].ValidNvIndex = 0xFFFF;
                            }
                            else
                            {
                                NvM_CurrentJob.NvDescriptor = (NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockBaseNumber + NvM_AdminBlock[NvM_CurrentJob.BlockId].DataSetIndex);
                                NvM_CurrentJob.CurrentNvIndex = 0U;
                            }
                            if(NULL != NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback)
                            {
                                (void) NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback(NVM_WRITE_BLOCK,NVM_REQ_PENDING);
                            }
                        #ifdef MEM_TESTING_ENABLED
                            NVM_JOB_START_HOOK(NVM_WRITE_BLOCK,NvM_CurrentJob.BlockId);
                        #endif
                            break;

                        case NV_READ_BLOCK:
                            if(NvM_AdminBlock[NvM_CurrentJob.BlockId].DataSetIndex < NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockNum)
                            {
                                NvM_DataStruct.NvMState = NVM_STATE_READ_BLOCK;
                                NvM_CurrentJob.JobState = NVM_JOB_STATE_READ;
                                NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_READ;
                                NvM_CurrentJob.ProcessState = TRUE;
                                NvM_CurrentJob.NvDescriptor = (NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockBaseNumber + NvM_AdminBlock[NvM_CurrentJob.BlockId].DataSetIndex);
                                NvM_CurrentJob.CurrentNvIndex = 0U;
                            }
                            else
                            {
                                NvM_DataStruct.NvMState = NVM_STATE_RESTORE_BLOCK_DEFAULTS;
                                NvM_CurrentJob.JobState = NVM_JOB_RESTORE_BLOCK_DEFAULTS;
                                NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_RESTORE_BLOCK_DEFAULTS;
                                NvM_CurrentJob.ProcessState = TRUE;
                            }
                        #ifdef MEM_TESTING_ENABLED
                            NVM_JOB_START_HOOK(NVM_READ_BLOCK,NvM_CurrentJob.BlockId);
                        #endif
                            break;

                        case NV_INVALIDATE_BLOCK:
                            NvM_DataStruct.NvMState = NVM_STATE_INVALIDATE;
                            NvM_CurrentJob.JobState = NVM_JOB_STATE_INVALIDATE;
                            NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_INVALIDATE;
                            NvM_CurrentJob.ProcessState = TRUE;
                        #ifdef MEM_TESTING_ENABLED
                            NVM_JOB_START_HOOK(NVM_INVALIDATE_NV_BLOCK,NvM_CurrentJob.BlockId);
                        #endif
                            break;

                        case NV_RESTORE_BLOCK_DEFAULTS:
                            NvM_DataStruct.NvMState = NVM_STATE_RESTORE_BLOCK_DEFAULTS;
                            NvM_CurrentJob.JobState = NVM_JOB_RESTORE_BLOCK_DEFAULTS;
                            NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_RESTORE_BLOCK_DEFAULTS;
                            NvM_CurrentJob.ProcessState = TRUE;
                        #ifdef MEM_TESTING_ENABLED
                            NVM_JOB_START_HOOK(NVM_RESTORE_BLOCK_DEFAULTS,NvM_CurrentJob.BlockId);
                        #endif
                            break;


                        default:
                            /* do nothing */
                        break;
                    }
                }
            }
            else
            {
                if(NvM_DataStruct.WriteAllRequest == TRUE)
                {
                    NvM_CurrentJob.BlockId = 2U;
                    NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_PROCESS_WRITE_ALL;
                    NvM_CurrentJob.ProcessState = TRUE;
                #ifdef MEM_TESTING_ENABLED
                    NVM_JOB_START_HOOK(NVM_WRITE_ALL,NvM_CurrentJob.BlockId);
                #endif
                }
                else
                {
                    if(NvM_DataStruct.ReadAllRequest == TRUE)
                    {
                        NvM_CurrentJob.BlockId = 2U;
                        NvM_CurrentJob.BlockOffset = 0U;
                        NvM_CurrentJob.RamBuffer = NvM_BlockConfig[NvM_CurrentJob.BlockId].RamBlockDataAddress;
                        NvM_CurrentJob.ReadLength = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockLength;
                        NvM_CurrentJob.RequestType = NVM_READ_ALL;
                        NvM_CurrentJob.WriteRetryCount = NvM_BlockConfig[NvM_CurrentJob.BlockId].MaxNumWriteRetries + (uint8)1u;
                        NvM_CurrentJob.ReadRetryCount = NvM_BlockConfig[NvM_CurrentJob.BlockId].MaxNumReadRetries + (uint8)1u;
                        NvM_DataStruct.NvMState = NVM_STATE_READ_ALL;
                        NvM_CurrentJob.JobState = NVM_JOB_STATE_READ;
                        NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_READ;
                        NvM_CurrentJob.ProcessState = TRUE;
                        NvM_CurrentJob.NvDescriptor = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockBaseNumber;
                        NvM_CurrentJob.CurrentNvIndex = 0U;
                    #ifdef MEM_TESTING_ENABLED
                        NVM_JOB_START_HOOK(NVM_READ_ALL,NvM_CurrentJob.BlockId);
                    #endif
                    }
                }
            }
        }
    }
    else if (MEMIF_BUSY_INTERNAL == MemIf_GetStatus(MEMIF_FEE))
    {
        if(NvM_DataStruct.NvMState == NVM_STATE_IDLE)
        {
            fl_NextPrio = NvM_GetNextHighPriority();
            if(fl_NextPrio < NVM_TRESHOLD_JOB_PRIORITY)
            {
                if ((0u == fl_NextPrio) || (E_OK == NvM_CheckForHighPrioRead(fl_NextPrio)))
                {
                    MemIf_SuspendInternalJob();
                }
            }
        }
    }
}


/**************************************************************************
Function name   : void NvM_ProcessJobSubState(void)
Arguments       : void
Return type     : void
Description     : Job Process State Machine
**************************************************************************/
static void NvM_ProcessJobSubState(void)
{
    switch(NvM_CurrentJob.JobSubState)
    {
        case NVM_JOB_SUBSTATE_IDLE:
        break;

        case NVM_JOB_SUBSTATE_WRITE_CRC_CALC:
        NvM_WriteCrcCalculate();
        break;

        case NVM_JOB_SUBSTATE_WRITE:
        NvM_InitWrite();
        break;

        case NVM_JOB_SUBSTATE_WRITE_WAIT:
        NvM_WriteCbkWait();
        break;

        case NVM_JOB_SUBSTATE_VERIFY_READ:
        NvM_WriteVerify();
        break;

        case NVM_JOB_SUBSTATE_VERIFY_READ_WAIT:
        NvM_WriteVerifyCbkWait();
        break;

        case NVM_JOB_SUBSTATE_READ:
        NvM_InitRead();
        break;

        case NVM_JOB_SUBSTATE_READ_WAIT:
        NvM_ReadCbkWait();
        break;

        case NVM_JOB_SUBSTATE_READ_CRC_CALC:
        NvM_ReadCrcCalculate();
        break;

        case NVM_JOB_SUBSTATE_READ_CRC_VALIDATE:
        NvM_ReadCrcValidate();
        break;

        case NVM_JOB_SUBSTATE_INVALIDATE:
        NvM_InitInvalidateBlock();
        break;

        case NVM_JOB_SUBSTATE_INVALIDATE_CBK_WAIT:
        NvM_InitInvalidateBlockCbkWait();
        break;

        case NVM_JOB_SUBSTATE_RESTORE_BLOCK_DEFAULTS:
        NvM_InternalRestoreBlockDefaults();
        break;

        case NVM_JOB_SUBSTATE_PROCESS_WRITE_ALL:
        NvM_ProcessWriteAll();
		break;

#if (NVM_JOB_PRIORITIZATION == STD_ON)
        case NVM_JOB_SUBSTATE_CANCEL_WAIT:
        NvM_CancelWait();
        break;
#endif

        default:
        //do nothing
        break;
  }
}


/**************************************************************************
Function name   : void NvM_InternalRestoreBlockDefaults(void)
Arguments       : void
Return type     : void
Description     : Restore Block Defaults
**************************************************************************/

static void NvM_InternalRestoreBlockDefaults(void)
{
    NvM_RequestResultType fl_JobResult;
    if((NvM_CurrentJob.RamBuffer == NULL_PTR) || \
        ((NvM_BlockConfig[NvM_CurrentJob.BlockId].RomBlockDataAddress == NULL_PTR) && (NvM_BlockConfig[NvM_CurrentJob.BlockId].InitCallback == NULL_PTR)))
    {
        fl_JobResult = NVM_REQ_NOT_OK;
    }
    else if (NULL_PTR != NvM_BlockConfig[NvM_CurrentJob.BlockId].RomBlockDataAddress)
    {
        MemLib_MemCpy(NvM_CurrentJob.RamBuffer, NvM_BlockConfig[NvM_CurrentJob.BlockId].RomBlockDataAddress, NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockLength);
        fl_JobResult = NVM_REQ_RESTORED_FROM_ROM;
    }
    else
    {
        fl_JobResult = NvM_BlockConfig[NvM_CurrentJob.BlockId].InitCallback();
        if (NVM_REQ_OK != fl_JobResult)
        {
            fl_JobResult = NVM_REQ_NOT_OK;
        }
    }
    if(NULL != NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback)
    {
        (void) NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback(NVM_RESTORE_BLOCK_DEFAULTS,fl_JobResult);
    }
    NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockProcessStatus = NVM_REQ_RESTORED_FROM_ROM;
    NvM_DataStruct.NvMState = NVM_STATE_IDLE;
    NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
    NvM_CurrentJob.ProcessState = FALSE;
    NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
    if (NVM_MEMIF_SUSPEND_INTERNAL_JOB == NvM_DataStruct.MemIf_InternalJobState)
    {
        MemIf_ResumeInternalJob();
    }
#ifdef MEM_TESTING_ENABLED
    NVM_JOB_END_HOOK(NVM_RESTORE_BLOCK_DEFAULTS,NvM_CurrentJob.BlockId);
#endif
}

/**************************************************************************
Function name   : void NvM_WriteCrcCalculate(void)
Arguments       : void
Return type     : void
Description     : Calculate CRC
**************************************************************************/
static void NvM_WriteCrcCalculate(void)
{
    uint32 CrcLength;
    uint16  Length;
#if (NVM_JOB_PRIORITIZATION == STD_ON)
    if(0u == NvM_GetNextHighPriority() && 0u != NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockJobPriority)
    {
        if (E_OK == NvM_PreemptCurrentJob())
        {
            NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
            NvM_DataStruct.NvMState = NVM_STATE_IDLE;
            NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
            NvM_CurrentJob.ProcessState = FALSE;
        }
    }
    else
#endif
    {
        /* Calculate CRC only for required block */
        if (FALSE == NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockUseCrc)
        {
            /* Copy the SWC RAM buffer to Nvm_MirrorRam buffer */
            NvM_MirrorRAMCopy(NvM_CurrentJob.RamBuffer,(uint8 *)&NvM_MirrorRam[0],NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockLength);
            NvM_CurrentJob.JobSubState  = NVM_JOB_SUBSTATE_WRITE;
            NvM_CurrentJob.ProcessState = TRUE;
        }
        else
        {
            if( NvM_CrcStruct.Length  > NVM_CRC_CALC_MAX_LEN)
            {
                NvM_CrcStruct.Length -= NVM_CRC_CALC_MAX_LEN;
                CrcLength = NVM_CRC_CALC_MAX_LEN;
            }
            else
            {
                CrcLength  =  NvM_CrcStruct.Length ;
                NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE;
                NvM_CurrentJob.ProcessState = TRUE;
            }
            if(FALSE != NvM_CrcStruct.IsFirstCall)
            {
                /* Copy the SWC RAM buffer to Nvm_MirrorRam buffer */
                NvM_MirrorRAMCopy(NvM_CurrentJob.RamBuffer,(uint8 *)&NvM_MirrorRam[0],NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockLength);
                /* Calculate CRC */
                NvM_CrcStruct.CrcValue = NvM_CrcCalculate(NvM_CrcStruct.DataPtr,CrcLength,NvM_CrcStruct.CrcValue,NvM_CrcStruct.IsFirstCall);
                NvM_CrcStruct.IsFirstCall = FALSE;
            }
            else
            {
                NvM_CrcStruct.DataPtr += NVM_CRC_CALC_MAX_LEN;
                NvM_CrcStruct.CrcValue = NvM_CrcCalculate(NvM_CrcStruct.DataPtr,CrcLength,NvM_CrcStruct.CrcValue,NvM_CrcStruct.IsFirstCall);
            }
            if(NvM_CrcStruct.Length <= NVM_CRC_CALC_MAX_LEN)
            {
                Length = NvM_CurrentJob.ReadLength;
                if( NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockCrcType == CRC_32)
                {
                    /* Append the CRC value before writing the data */
                    NvM_MirrorRam[Length]   = (uint8) (NvM_CrcStruct.CrcValue & 0x000000FFU);
                    NvM_MirrorRam[Length+1u] = (uint8)((uint32)(NvM_CrcStruct.CrcValue & 0x0000FF00U) >> (uint32)8u); /*CERT C 17224313, 17225178*/
                    NvM_MirrorRam[Length+2u] = (uint8)((NvM_CrcStruct.CrcValue & 0x00FF0000U) >> 16); /*CERT C 17224313, 17225178*/
                    NvM_MirrorRam[Length+3u] = (uint8)((NvM_CrcStruct.CrcValue & 0xFF000000U) >> 24); /*CERT C 17224313, 17225178*/
                }
                else if( NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockCrcType == CRC_16)
                {
                    /* Append the CRC value before writing the data */
                    NvM_MirrorRam[Length]   = (uint8) (NvM_CrcStruct.CrcValue & 0x000000FFU);
                    NvM_MirrorRam[Length+1u] = (uint8)((NvM_CrcStruct.CrcValue & 0x0000FF00U) >> 8);/*CERT C17224313, 17225178*/
                    NvM_MirrorRam[Length+2u] = 0x00U;/*CERT C 17224313, 17225178*/
                    NvM_MirrorRam[Length+3u] = 0x00U;/*CERT C 17224313, 17225178*/
                }
                else
                {
                    /* Append the CRC value before writing the data */
                    NvM_MirrorRam[Length]   = (uint8) (NvM_CrcStruct.CrcValue & 0x000000FFU);
                    NvM_MirrorRam[Length+1u] = 0x00U;/*CERT C 17224313, 17225178*/
                    NvM_MirrorRam[Length+2u] = 0x00U;/*CERT C 17224313, 17225178*/
                    NvM_MirrorRam[Length+3u] = 0x00U;/*CERT C 17224313, 17225178*/
                }
            }
        }
    } 
}
/**************************************************************************
Function name   : void NvM_InitWrite(void)
Arguments       : void
Return type     : void
Description     : Initiate the Write Request 
**************************************************************************/
static void NvM_InitWrite(void)
{
    // printf("HELLO_NvM_init_Write\n");
    Std_ReturnType fl_RequestStatus;
    uint8 DeviceId;
    uint8 JobId = NVM_INVALIDATE_NV_BLOCK; /*CERT C 17225622*/
    uint8 fl_CurrentBlockStatus;
    if (FALSE != NvM_DataStruct.MemIf_InternalBusy)
    {
        //Wait For MemIf Internal Job to complete.
        NvM_CurrentJob.ProcessState = FALSE;
    // printf("HELLO_NvM_init_Write_1\n");

    }
    else
    {
        if (MEMIF_SNVM == NvM_BlockConfig[NvM_CurrentJob.BlockId].NvRamDeviceId)  
        {
            MemIf_SuspendInternalJob(); 
        }
        if(NvM_CurrentJob.JobState == NVM_JOB_STATE_WRITE)
        {
            if(NvM_DataStruct.WriteAllRequest == TRUE)
            {
                JobId = NVM_WRITE_ALL;
            }
            else
            {
                JobId = NVM_WRITE_BLOCK;
            }
        }
        if(NvM_CurrentJob.JobState == NVM_JOB_STATE_READ)
        {
            if(NvM_DataStruct.ReadAllRequest == TRUE)
            {
                JobId = NVM_READ_ALL;
            }
            else
            {
                JobId = NVM_READ_BLOCK;
            }
        }
        if(NvM_CurrentJob.WriteRetryCount > 0U)
        {
            NvM_CurrentJob.JobStatus = NVM_REQ_PENDING;
            DeviceId = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvRamDeviceId;

            /* Write the MirrorRam data buffer along with calculated CRC value */
            fl_RequestStatus = MemIf_Write(DeviceId,NvM_CurrentJob.NvDescriptor,(uint8 *)&NvM_MirrorRam[0]);

            if(fl_RequestStatus == E_OK)
            {
                NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE_WAIT;
                NvM_CurrentJob.ProcessState = FALSE;
            }
            else
            {
                NvM_CurrentJob.WriteRetryCount--;
                NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE;
                NvM_CurrentJob.ProcessState = FALSE;
            }
        }
        else
        {
            NvM_CurrentJob.DirtyNvIndex &= (uint16)~(0x01 << NvM_CurrentJob.CurrentNvIndex);
            /* Check for block type redundant */
            if((NVM_REDUNDANT_BLOCK == NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockManagementType)
                &&(FALSE != NvM_CurrentJob.DirtyNvIndex))
            {
                NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE;
                NvM_CurrentJob.ProcessState = TRUE;
                if(0x01 == NvM_CurrentJob.DirtyNvIndex)
                {
                    NvM_CurrentJob.CurrentNvIndex = 0;
                }
                else
                {
                    NvM_CurrentJob.CurrentNvIndex = 1;
                }
                NvM_CurrentJob.NvDescriptor = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockBaseNumber + NvM_CurrentJob.CurrentNvIndex;
                NvM_CurrentJob.WriteRetryCount = NvM_BlockConfig[NvM_CurrentJob.BlockId].MaxNumWriteRetries+1;
            }
            else
            {
                if(0xFFFF != NvM_AdminBlock[NvM_CurrentJob.BlockId].ValidNvIndex)
                {
                    fl_CurrentBlockStatus = NVM_REQ_OK;
                }
                else
                {
                    fl_CurrentBlockStatus = NVM_REQ_NOT_OK;
                }
                if(NULL != NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback)
                {
                    (void) NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback(JobId,fl_CurrentBlockStatus);
                }
                NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockProcessStatus = fl_CurrentBlockStatus;
                if(NvM_DataStruct.NvMState == NVM_STATE_WRITE_ALL)
                {
                    NvM_CurrentJob.BlockId = NvM_CurrentJob.BlockId+1U;
                    NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_PROCESS_WRITE_ALL;
                    NvM_CurrentJob.ProcessState = TRUE;
                }
                else if(NvM_DataStruct.ReadAllRequest == TRUE)
                {
                    NvM_ProcessReadAll();
                }
                else
                {
                    NvM_DataStruct.NvMState = NVM_STATE_IDLE;
                    NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
                    NvM_CurrentJob.ProcessState = FALSE;
                    NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
                    if (NVM_MEMIF_SUSPEND_INTERNAL_JOB == NvM_DataStruct.MemIf_InternalJobState)
                    {
                        MemIf_ResumeInternalJob();
                    }
                #ifdef MEM_TESTING_ENABLED
                    NVM_JOB_END_HOOK(JobId,NvM_CurrentJob.BlockId);
                #endif
                }
            }
        }
    }
}
/**************************************************************************
Function name   : static void NvM_ProcessWriteAll(void)
Arguments       : void
Return type     : void
Description     : process write all
**************************************************************************/
static void NvM_ProcessWriteAll()
{
    boolean fl_RequestWriteBlock;
    if(NvM_DataStruct.WriteAllRequest == TRUE)
    {
        if(NvM_CurrentJob.BlockId < NVM_NUM_OF_BLOCKS)
        {
            fl_RequestWriteBlock = TRUE;
            if(FALSE == NvM_BlockConfig[NvM_CurrentJob.BlockId].SelectBlockForWriteAll)
            {
                fl_RequestWriteBlock = FALSE;
            }
            if(FALSE != NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockUseSetRamBlockStatus)
            {
                if (FALSE == NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockModifiedStatus)
                {
                    fl_RequestWriteBlock = FALSE;
                }
            }
            if((FALSE != NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockLockedStatus) || \
            (FALSE != NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockWriteProt))
            {
                fl_RequestWriteBlock = FALSE;
            }
            if(FALSE != fl_RequestWriteBlock)
            {
                NvM_CurrentJob.JobStatus = NVM_REQ_PENDING;
                NvM_CurrentJob.BlockOffset = 0U;
                NvM_CurrentJob.RamBuffer = NvM_BlockConfig[NvM_CurrentJob.BlockId].RamBlockDataAddress;
                NvM_CurrentJob.ReadLength = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockLength;
                NvM_CurrentJob.RequestType = NVM_WRITE_ALL;
                NvM_CurrentJob.WriteRetryCount = NvM_BlockConfig[NvM_CurrentJob.BlockId].MaxNumWriteRetries + (uint8)1u;
                NvM_CurrentJob.ReadRetryCount = NvM_BlockConfig[NvM_CurrentJob.BlockId].MaxNumReadRetries + (uint8)1u;
                NvM_CurrentJob.JobState = NVM_JOB_STATE_WRITE;
                NvM_CrcStruct.IsFirstCall = TRUE;
                NvM_CrcStruct.DataPtr =  NvM_CurrentJob.RamBuffer;
                NvM_CrcStruct.Length =  NvM_CurrentJob.ReadLength;
                NvM_CrcStruct.CrcValue = 0xFFFFU;
                NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE_CRC_CALC;
                NvM_CurrentJob.ProcessState = TRUE;
                if(NVM_REDUNDANT_BLOCK == NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockManagementType)
                {
                    NvM_CurrentJob.DirtyNvIndex = 0x03;
                    if(FALSE == NvM_AdminBlock[NvM_CurrentJob.BlockId].ValidNvIndex)
                    {
                        NvM_CurrentJob.NvDescriptor = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockBaseNumber + 1U;
                        NvM_CurrentJob.CurrentNvIndex = 1U;
                    }
                    else
                    {
                        NvM_CurrentJob.NvDescriptor = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockBaseNumber;
                        NvM_CurrentJob.CurrentNvIndex = 0U;
                    }
                    NvM_AdminBlock[NvM_CurrentJob.BlockId].ValidNvIndex = 0xFFFF;
                }
                else
                {
                    NvM_CurrentJob.NvDescriptor = (NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockBaseNumber + NvM_AdminBlock[NvM_CurrentJob.BlockId].DataSetIndex);
                    NvM_CurrentJob.CurrentNvIndex = 0U;
                }
            }
            else
            {
                NvM_CurrentJob.BlockId = NvM_CurrentJob.BlockId+1U;
                NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_PROCESS_WRITE_ALL;
                NvM_CurrentJob.ProcessState = TRUE;
            }
        }
        else
        {
            NvM_DataStruct.WriteAllRequest = FALSE;
            NvM_DataStruct.NvMState = NVM_STATE_IDLE;
            NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
            NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
            NvM_CurrentJob.ProcessState = FALSE;
            NvM_MultiBlockCallbackFunction(NVM_WRITE_ALL,NVM_REQ_OK);
            if (NVM_MEMIF_SUSPEND_INTERNAL_JOB == NvM_DataStruct.MemIf_InternalJobState)
            {
                MemIf_ResumeInternalJob();
            }
        #ifdef MEM_TESTING_ENABLED
            NVM_JOB_END_HOOK(NVM_WRITE_ALL,NvM_CurrentJob.BlockId);
        #endif
        }
    }
    else
    {
        NvM_DataStruct.NvMState = NVM_STATE_IDLE;
        NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
        NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
        NvM_CurrentJob.ProcessState = FALSE;
        NvM_MultiBlockCallbackFunction(NVM_WRITE_ALL,NVM_REQ_CANCELED);
        if (NVM_MEMIF_SUSPEND_INTERNAL_JOB == NvM_DataStruct.MemIf_InternalJobState)
        {
            MemIf_ResumeInternalJob();
        }
    #ifdef MEM_TESTING_ENABLED
        NVM_JOB_END_HOOK(NVM_WRITE_ALL,NvM_CurrentJob.BlockId);
    #endif
    }
}


/**************************************************************************
Function name   : void NvM_WriteCbkWait(void)
Arguments       : void
Return type     : void
Description     : wait for callback
**************************************************************************/
static void NvM_WriteCbkWait()
{
    if(NvM_CurrentJob.JobStatus != NVM_REQ_PENDING)
    {
#if (NVM_JOB_PRIORITIZATION == STD_ON)
        if(0u == NvM_GetNextHighPriority() && 0u != NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockJobPriority)
        {
            if (E_OK == NvM_PreemptCurrentJob())
            {
                NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
                NvM_DataStruct.NvMState = NVM_STATE_IDLE;
                NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
                NvM_CurrentJob.ProcessState = FALSE;
            }
        }
        else
#endif
        {
            if(NvM_CurrentJob.JobStatus != NVM_REQ_OK)
            {
                /* NvM Write request is not successful, needs to retry based on the  */
                /* write retry count                                                 */
                if( NvM_CurrentJob.WriteRetryCount > 0 )
                {
                    NvM_CurrentJob.WriteRetryCount--;
                }
                NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE;
                NvM_CurrentJob.ProcessState = FALSE;
            }
            else
            {
                NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_VERIFY_READ;
                NvM_CurrentJob.ProcessState = TRUE;
            }
        }
    }
    else
    {
        NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE_WAIT;
        NvM_CurrentJob.ProcessState = FALSE;
#if (NVM_JOB_PRIORITIZATION == STD_ON)
        if(0u == NvM_GetNextHighPriority() && 0u != NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockJobPriority)
        {
            if (E_OK == NvM_PreemptCurrentJob())
            {
                NvM_CurrentJob.JobStatus = NVM_REQ_PENDING;
                MemIf_Cancel(NvM_BlockConfig[NvM_CurrentJob.BlockId].NvRamDeviceId);
                NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_CANCEL_WAIT;
            }
        }
#endif
    }
}
/**************************************************************************
Function name   : void NvM_WriteVerify(void)
Arguments       : void
Return type     : void
Description     : read the data
**************************************************************************/
static void NvM_WriteVerify()
{
    Std_ReturnType fl_RequestStatus;
    uint8 DeviceId;
    NvM_CurrentJob.BlockOffset = 0U;
    NvM_CurrentJob.JobStatus = NVM_REQ_PENDING;
    DeviceId = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvRamDeviceId;
    if (FALSE != NvM_DataStruct.MemIf_InternalBusy)
    {
        //Wait For MemIf Internal Job to complete.
        NvM_CurrentJob.ProcessState = FALSE;
    }
    else
    {
        if (MEMIF_SNVM == NvM_BlockConfig[NvM_CurrentJob.BlockId].NvRamDeviceId)  
        {
            MemIf_SuspendInternalJob(); 
        }
        if(NvM_CurrentJob.ReadRetryCount > 0)
        {
            fl_RequestStatus = MemIf_Read(DeviceId, NvM_CurrentJob.NvDescriptor,NvM_CurrentJob.BlockOffset,\
                                            (uint8 *)&NvM_WriteVerificationBuffer,NvM_CurrentJob.ReadLength);
            if(fl_RequestStatus == E_OK)
            {
                NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_VERIFY_READ_WAIT;
                NvM_CurrentJob.ProcessState = FALSE;
            }
            else
            {
                    NvM_CurrentJob.ReadRetryCount--;
                    NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_VERIFY_READ;
                    NvM_CurrentJob.ProcessState = FALSE;
            }
        }
        else
        {
                /* NvM read request is not successful after the read retries, needs to retry write based on the  */
                /* write retry count                                                 */
				if( NvM_CurrentJob.WriteRetryCount > 0 )
				{
					NvM_CurrentJob.WriteRetryCount--;
				}
                NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE;
                NvM_CurrentJob.ProcessState = FALSE;
        }
    }
}

/**************************************************************************
Function name   : void NvM_WriteVerifyCbkWait(void)
Arguments       : void
Return type     : void
Description     : wait for write verify call back wait
**************************************************************************/
static void NvM_WriteVerifyCbkWait()
{
    uint8 Result;
    uint8 fl_CurrentBlockStatus;
    uint8 JobId = NVM_INVALIDATE_NV_BLOCK; /*CERT C 17226066*/
    if(NvM_CurrentJob.JobState == NVM_JOB_STATE_WRITE)
    {
        if(NvM_DataStruct.WriteAllRequest == TRUE)
        {
            JobId = NVM_WRITE_ALL;
        }
        else
        {
            JobId = NVM_WRITE_BLOCK;
        }
    }
    if(NvM_CurrentJob.JobState == NVM_JOB_STATE_READ)
    {
        if(NvM_DataStruct.ReadAllRequest == TRUE)
        {
            JobId = NVM_READ_ALL;
        }
        else
        {
            JobId = NVM_READ_BLOCK;
        }
    }
    if(NvM_CurrentJob.JobStatus != NVM_REQ_PENDING)
    {
#if (NVM_JOB_PRIORITIZATION == STD_ON)
        if(0u == NvM_GetNextHighPriority() && 0u != NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockJobPriority)
        {
            if (E_OK == NvM_PreemptCurrentJob())
            {
                NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
                NvM_DataStruct.NvMState = NVM_STATE_IDLE;
                NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
                NvM_CurrentJob.ProcessState = FALSE;
            }
        }
    else
#endif
        {
            if(NvM_CurrentJob.JobStatus != NVM_REQ_OK)
            {
                if(NVM_REQ_NOT_OK == NvM_CurrentJob.JobStatus)
                {
                    if( NvM_CurrentJob.ReadRetryCount > 0 )
                    {
                        NvM_CurrentJob.ReadRetryCount--;
                    }
                    NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_VERIFY_READ;
                    NvM_CurrentJob.ProcessState = FALSE;
                }
                else
                {
                    NvM_CurrentJob.ReadRetryCount = 0U;
                    NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_VERIFY_READ;
                    NvM_CurrentJob.ProcessState = TRUE;
                }
            }
            else
            {
                Result = NvM_WriteVerifyReadData();
                if(FALSE != Result)
                {
                    NvM_AdminBlock[NvM_CurrentJob.BlockId].ValidNvIndex = NvM_CurrentJob.CurrentNvIndex;
                    NvM_CurrentJob.DirtyNvIndex &= (uint16)~(0x01 << NvM_CurrentJob.CurrentNvIndex);
                    /* Check for block type redundant */
                    if ((NVM_REDUNDANT_BLOCK == NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockManagementType) &&
                        (FALSE != NvM_CurrentJob.DirtyNvIndex))
                    {
                        NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE;
                        NvM_CurrentJob.ProcessState = TRUE;
                        if(0x01 == NvM_CurrentJob.DirtyNvIndex)
                        {
                            NvM_CurrentJob.CurrentNvIndex = 0;
                        }
                        else
                        {
                            NvM_CurrentJob.CurrentNvIndex = 1;
                        }
                        NvM_CurrentJob.NvDescriptor = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockBaseNumber + NvM_CurrentJob.CurrentNvIndex;
                        NvM_CurrentJob.WriteRetryCount = NvM_BlockConfig[NvM_CurrentJob.BlockId].MaxNumWriteRetries + 1U;
                    }
                    else
                    {
                        if(0xFFFF != NvM_AdminBlock[NvM_CurrentJob.BlockId].ValidNvIndex)
                        {
                            fl_CurrentBlockStatus = NVM_REQ_OK;
                        }
                        else
                        {
                            fl_CurrentBlockStatus = NVM_REQ_NOT_OK;
                        }
                        /* Regular Read Request; Callback needs to be called */
                        if(NULL != NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback)
                        {
                            (void) NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback(JobId,fl_CurrentBlockStatus);
                        }
                        NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockProcessStatus = fl_CurrentBlockStatus; /*Verification Success*/
                        if(NvM_DataStruct.NvMState == NVM_STATE_WRITE_ALL)
                        {
                            NvM_CurrentJob.BlockId = NvM_CurrentJob.BlockId+1U;
                            NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_PROCESS_WRITE_ALL;
                            NvM_CurrentJob.ProcessState = TRUE;
                        }
                        else if (NvM_DataStruct.ReadAllRequest == TRUE)
                        {
                            NvM_ProcessReadAll();
                        }
                        else
                        {
                            NvM_DataStruct.NvMState = NVM_STATE_IDLE;
                            NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
                            NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
                            NvM_CurrentJob.ProcessState = FALSE;
                            if (NVM_MEMIF_SUSPEND_INTERNAL_JOB == NvM_DataStruct.MemIf_InternalJobState)
                            {
                                MemIf_ResumeInternalJob();
                            }
                        #ifdef MEM_TESTING_ENABLED
                            NVM_JOB_END_HOOK(JobId,NvM_CurrentJob.BlockId);
                        #endif
                        }
                    }
                }
                else
                {
                if ( NvM_CurrentJob.WriteRetryCount > 0 )
                {
                    NvM_CurrentJob.WriteRetryCount--;
                }
                NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE; /* Verification Failed */
                NvM_CurrentJob.ProcessState = TRUE;
                }
            }
        }
    }
    else
    {
        NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_VERIFY_READ_WAIT;
        NvM_CurrentJob.ProcessState = FALSE;
#if (NVM_JOB_PRIORITIZATION == STD_ON)
        if(0u == NvM_GetNextHighPriority() && 0u != NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockJobPriority)
        {
            if (E_OK == NvM_PreemptCurrentJob())
            {
                NvM_CurrentJob.JobStatus = NVM_REQ_PENDING;
                MemIf_Cancel(NvM_BlockConfig[NvM_CurrentJob.BlockId].NvRamDeviceId);
                NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_CANCEL_WAIT;
            }
        }
#endif
    }
}

/**************************************************************************
Function name   : Std_ReturnType NvM_WriteVerifyReadData(void)
Arguments       : void
Return type     : boolean
Description     : Verify the write data
**************************************************************************/
static boolean NvM_WriteVerifyReadData(void)
{
    uint8* WriteBuff = (uint8 *)&NvM_MirrorRam[0];
    uint8* ReadBuff = (uint8 *)&NvM_WriteVerificationBuffer;
    uint16 CompareLength;
    uint16 Iter;
    boolean RetVal = TRUE;
    CompareLength = NvM_CurrentJob.ReadLength;
    for(Iter=0U; Iter < CompareLength; Iter++)
    {
        if((*WriteBuff) != (*ReadBuff))
        {
            RetVal = FALSE;
            break;
        }
        WriteBuff++;
        ReadBuff++;
    }
    return(RetVal);
}

/**************************************************************************
Function name   : void NvM_InitRead(void)
Arguments       : void
Return type     : void
Description     : Initiate the Read Request
**************************************************************************/
static void NvM_InitRead(void)
{
    Std_ReturnType fl_RequestStatus;
    boolean fl_RequestReadBlock;
    uint8 DeviceId;
    uint16  Length;
    uint8 JobId;
    if (FALSE != NvM_DataStruct.MemIf_InternalBusy)
    {
        if (NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockJobPriority < NVM_TRESHOLD_JOB_PRIORITY)  
        {
            MemIf_SuspendInternalJob(); 
        }
        else
        {
            //Wait For MemIf Internal Job to complete.
        }
        NvM_CurrentJob.ProcessState = FALSE;
    }
    else
    {
        if (MEMIF_SNVM == NvM_BlockConfig[NvM_CurrentJob.BlockId].NvRamDeviceId)  
        {
            MemIf_SuspendInternalJob(); 
        }
        fl_RequestReadBlock = TRUE;
        if(NvM_DataStruct.NvMState == NVM_STATE_READ_ALL)
        {
            if(FALSE == NvM_BlockConfig[NvM_CurrentJob.BlockId].SelectBlockForReadAll)
            {
                fl_RequestReadBlock = FALSE;
                NvM_ProcessReadAll();
            }
        }
        if(FALSE != fl_RequestReadBlock)
        {
            if(NvM_CurrentJob.ReadRetryCount > 0)
            {
                NvM_CurrentJob.JobStatus = NVM_REQ_PENDING;
                DeviceId = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvRamDeviceId;
                /* To Read swc data along with stored CRC value*/
                Length = NvM_CurrentJob.ReadLength + 4;
                /* Read swc data along with crc value  */
                fl_RequestStatus = MemIf_Read(DeviceId,NvM_CurrentJob.NvDescriptor ,NvM_CurrentJob.BlockOffset,\
                                            &NvM_MirrorRam[0],Length);
                if(fl_RequestStatus == E_OK)
                {
                    NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_READ_WAIT;
                    NvM_CurrentJob.ProcessState = FALSE;
                }
                else
                {
                    NvM_CurrentJob.ReadRetryCount--;
                    NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_READ;
                    NvM_CurrentJob.ProcessState = FALSE;
                }
            }
            else
            {
                if((NVM_REDUNDANT_BLOCK == NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockManagementType)
                && (NvM_CurrentJob.CurrentNvIndex == 0))
                {
                    NvM_CurrentJob.CurrentNvIndex = NvM_CurrentJob.CurrentNvIndex +1;
                    NvM_CurrentJob.JobSubState    = NVM_JOB_SUBSTATE_READ;
                    NvM_CurrentJob.ProcessState   = TRUE;
                    NvM_CurrentJob.NvDescriptor   = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockBaseNumber + (uint16)1u;
                    NvM_CurrentJob.ReadRetryCount = NvM_BlockConfig[NvM_CurrentJob.BlockId].MaxNumReadRetries + (uint8)1u;
                }
                else
                {
                    if(NvM_DataStruct.NvMState == NVM_STATE_READ_ALL)
                    {
                        JobId = NVM_READ_ALL;
                    }
                    else
                    {
                        JobId = NVM_READ_BLOCK;
                    }
                    NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
                    
                    if (NVM_DATASET_BLOCK == NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockManagementType)
                    {
                        if(NULL != NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback)
                        {
                            (void) NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback(JobId,NVM_REQ_NOT_OK);
                        }
                    }
                    else
                    {
                        if((NvM_CurrentJob.RamBuffer != NULL_PTR) && \
                            ((NvM_BlockConfig[NvM_CurrentJob.BlockId].RomBlockDataAddress != NULL_PTR) || (NvM_BlockConfig[NvM_CurrentJob.BlockId].InitCallback != NULL_PTR)))
                        {
                            if(NULL != NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback)
                            {
                                (void) NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback(JobId,NVM_REQ_RESTORED_FROM_ROM);
                            }
                            if (NULL_PTR != NvM_BlockConfig[NvM_CurrentJob.BlockId].RomBlockDataAddress)
                            {
                                MemLib_MemCpy(NvM_CurrentJob.RamBuffer, NvM_BlockConfig[NvM_CurrentJob.BlockId].RomBlockDataAddress, NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockLength);
                            }
                            else
                            {
                                (void)NvM_BlockConfig[NvM_CurrentJob.BlockId].InitCallback();
                            }
                        }
                    }
                    if(NvM_CurrentJob.ReadAllBlockStatus == NVM_REQ_OK)
                    {
                        /* At least one block read failed */
                        NvM_CurrentJob.ReadAllBlockStatus = NVM_REQ_NOT_OK;
                    }
                    if(NvM_DataStruct.NvMState == NVM_STATE_READ_ALL)
                    {
                        NvM_ProcessReadAll();
                    }
                    else
                    {
                        NvM_DataStruct.NvMState = NVM_STATE_IDLE;
                        NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
                        NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
                        NvM_CurrentJob.ProcessState = FALSE;
                        if (NVM_MEMIF_SUSPEND_INTERNAL_JOB == NvM_DataStruct.MemIf_InternalJobState)
                        {
                            MemIf_ResumeInternalJob();
                        }
                    #ifdef MEM_TESTING_ENABLED
                        NVM_JOB_END_HOOK(JobId,NvM_CurrentJob.BlockId);
                    #endif
                    }
                }
            }
        }
    }
}
/**************************************************************************
Function name   : void NvM_ProcessReadAll()
Arguments       : void
Return type     : void
Description     : Initiate the Read Request
**************************************************************************/
static void NvM_ProcessReadAll(void)
{
    if(NvM_DataStruct.ReadAllRequest == TRUE)
    {
        if(NvM_CurrentJob.BlockId < NVM_NUM_OF_BLOCKS)
        {
            NvM_CurrentJob.JobStatus = NVM_REQ_PENDING;
            NvM_CurrentJob.BlockId = NvM_CurrentJob.BlockId+1U;
            NvM_CurrentJob.BlockOffset = 0U;
            NvM_CurrentJob.RamBuffer = NvM_BlockConfig[NvM_CurrentJob.BlockId].RamBlockDataAddress;
            NvM_CurrentJob.ReadLength = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockLength;
            NvM_CurrentJob.RequestType = NVM_READ_ALL;
            NvM_CurrentJob.WriteRetryCount = NvM_BlockConfig[NvM_CurrentJob.BlockId].MaxNumWriteRetries + (uint8)1u;
            NvM_CurrentJob.ReadRetryCount = NvM_BlockConfig[NvM_CurrentJob.BlockId].MaxNumReadRetries + (uint8)1u;
            NvM_CurrentJob.NvDescriptor = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockBaseNumber;
            NvM_CurrentJob.CurrentNvIndex = 0U;
            NvM_CurrentJob.JobState = NVM_JOB_STATE_READ;
            NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_READ;
            NvM_CurrentJob.ProcessState = TRUE;
        }
        else
        {
            NvM_DataStruct.ReadAllRequest = FALSE;
            NvM_DataStruct.NvMState = NVM_STATE_IDLE;
            NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
            NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
            NvM_CurrentJob.ProcessState = FALSE;
            if (NVM_MEMIF_SUSPEND_INTERNAL_JOB == NvM_DataStruct.MemIf_InternalJobState)
            {
                MemIf_ResumeInternalJob();
            }
            if(NvM_CurrentJob.ReadAllBlockStatus != NVM_REQ_NOT_OK)
            {
                NvM_MultiBlockCallbackFunction(NVM_READ_ALL,NVM_REQ_OK);
            }
            else
            {
                NvM_MultiBlockCallbackFunction(NVM_READ_ALL,NVM_REQ_NOT_OK);
            }
        #ifdef MEM_TESTING_ENABLED
            NVM_JOB_END_HOOK(NVM_READ_ALL,NvM_CurrentJob.BlockId);
        #endif
        }
    }
}
/**************************************************************************
Function name   : void NvM_ReadCbkWait(void)
Arguments       : void
Return type     : void
Description     : wait for callback
**************************************************************************/
static void NvM_ReadCbkWait(void)
{
    uint8 JobId;
    if(NvM_CurrentJob.JobStatus != NVM_REQ_PENDING)
    {
#if (NVM_JOB_PRIORITIZATION == STD_ON)
        if(0u == NvM_GetNextHighPriority() && 0u != NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockJobPriority)
        {
            if (E_OK == NvM_PreemptCurrentJob())
            {
                NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
                NvM_DataStruct.NvMState = NVM_STATE_IDLE;
                NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
                NvM_CurrentJob.ProcessState = FALSE;
            }
        }
        else
#endif
        {
            switch(NvM_CurrentJob.JobStatus)
            {
                case NVM_REQ_NOT_OK:
                /* NvM Read request is not successful, needs to retry based on the  */
                /* read retry count                                                 */
                if( NvM_CurrentJob.ReadRetryCount > 0 )
                {
                    NvM_CurrentJob.ReadRetryCount--;
                }
                NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_READ;
                NvM_CurrentJob.ProcessState = TRUE;
                break;

                case NVM_REQ_OK:
                /* Check whether CRC is required for current block or not */
                if(TRUE == NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockUseCrc)
                {
                    NvM_CrcStruct.IsFirstCall = TRUE;
                    /* Calculate CRC from MirrorRam buffer */
                    NvM_CrcStruct.DataPtr = &NvM_MirrorRam[0];
                    NvM_CrcStruct.Length =  NvM_CurrentJob.ReadLength;
                    NvM_CrcStruct.CrcValue = 0xFFFFU;
                    /* Move the state to calculate CRC */
                    NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_READ_CRC_CALC;
                }
                else
                {
                    if(NvM_DataStruct.NvMState == NVM_STATE_READ_ALL)
                    {
                        JobId = NVM_READ_ALL;
                    }
                    else
                    {
                        JobId = NVM_READ_BLOCK;
                    }
                    /* Regular Read Request; Callback needs to be called */
                    NvM_MirrorRAMCopy((uint8 *)&NvM_MirrorRam[0], NvM_CurrentJob.RamBuffer,NvM_CurrentJob.ReadLength);
                    NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockProcessStatus = NVM_REQ_OK;
                    if(NULL != NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback)
                    {
                        NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback(JobId,NVM_REQ_OK);
                    }
                    if(NvM_DataStruct.NvMState != NVM_STATE_READ_ALL)
                    {
                        NvM_DataStruct.NvMState = NVM_STATE_IDLE;
                        NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
                        NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
                        NvM_CurrentJob.ProcessState = FALSE;
                        if (NVM_MEMIF_SUSPEND_INTERNAL_JOB == NvM_DataStruct.MemIf_InternalJobState)
                        {
                            MemIf_ResumeInternalJob();
                        }
                    #ifdef MEM_TESTING_ENABLED
                        NVM_JOB_END_HOOK(JobId,NvM_CurrentJob.BlockId);
                    #endif
                    }
                    else
                    {
                        /* Check whether Read all is in progress if so load next block */
                        NvM_ProcessReadAll();
                    }
                }
                break;

                case NVM_REQ_NV_INVALIDATED:
                case NVM_REQ_INTEGRITY_FAILED:
                    NvM_CurrentJob.ReadRetryCount = 0U;
                    NvM_CurrentJob.JobSubState    = NVM_JOB_SUBSTATE_READ;
                    NvM_CurrentJob.ProcessState   = TRUE;
                break;

                default:
                /* do nothing */
                break;
            }
        }
    }
    else
    {
        NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_READ_WAIT;
        NvM_CurrentJob.ProcessState = FALSE;
#if (NVM_JOB_PRIORITIZATION == STD_ON)
        if(0u == NvM_GetNextHighPriority() && 0u != NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockJobPriority)
        {
            if (E_OK == NvM_PreemptCurrentJob())
            {
                NvM_CurrentJob.JobStatus = NVM_REQ_PENDING;
                MemIf_Cancel(NvM_BlockConfig[NvM_CurrentJob.BlockId].NvRamDeviceId);
                NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_CANCEL_WAIT;
            }
        }
#endif
    }
}

/**************************************************************************
Function name   : void NvM_ReadCrcCalculate(void)
Arguments       : void
Return type     : void
Description     : Calculate CRC
**************************************************************************/
static void NvM_ReadCrcCalculate(void)
{
    uint32 CrcLength =  NvM_CrcStruct.Length ;
    if( CrcLength  > NVM_CRC_CALC_MAX_LEN)
    {
        NvM_CrcStruct.Length -= NVM_CRC_CALC_MAX_LEN;
        CrcLength = NVM_CRC_CALC_MAX_LEN;
    }
    else
    {
        NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_READ_CRC_VALIDATE;
        NvM_CurrentJob.ProcessState = TRUE;
    }
    if(FALSE != NvM_CrcStruct.IsFirstCall)
    {
        NvM_CrcStruct.CrcValue = NvM_CrcCalculate(NvM_CrcStruct.DataPtr,CrcLength,NvM_CrcStruct.CrcValue,NvM_CrcStruct.IsFirstCall);
        NvM_CrcStruct.IsFirstCall = FALSE;
    }
    else
    {
        NvM_CrcStruct.DataPtr += NVM_CRC_CALC_MAX_LEN;
        NvM_CrcStruct.CrcValue = NvM_CrcCalculate(NvM_CrcStruct.DataPtr,CrcLength,NvM_CrcStruct.CrcValue,NvM_CrcStruct.IsFirstCall);

    }
}

/**************************************************************************
Function name   : void NvM_ReadCrcValidate(void)
Arguments       : void
Return type     : void
Description     : Validate CRC
**************************************************************************/
static void NvM_ReadCrcValidate(void)
{
    uint32 ReadCrcValue;
    uint8* Buff;
    uint16  Length;
    uint8 JobId;

    Length = NvM_CurrentJob.ReadLength;
    Buff = &NvM_MirrorRam[Length]; /* Stored CRC - read value*/
    ReadCrcValue = 0U;

    if( NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockCrcType == CRC_32)
    {
        ReadCrcValue |= (uint32)(*Buff);
        Buff++;
        ReadCrcValue |= (uint32)((uint32)(*Buff) << (uint32)8u); /*CERT C 17226145*/
        Buff++;
        ReadCrcValue |= (uint32)((uint32)(*Buff) << (uint32)16u); /*CERT C 17226145*/
        Buff++;
        ReadCrcValue |= (uint32)((uint32)(*Buff) << (uint32)24u); /*CERT C 17226145*/
    }
    else if(NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockCrcType == CRC_16)
    {
        ReadCrcValue |= (uint32)(*Buff);
        Buff++;
        ReadCrcValue |= (uint32)((uint32)(*Buff) << (uint32)8u); /*CERT C 17226145*/
    }
    else
    {
        ReadCrcValue |= (uint32)(*Buff);
    }
    if(NvM_CrcStruct.CrcValue == ReadCrcValue)
    {
        /* Copy the data from MirrorRam to SWC buffer */
        NvM_MirrorRAMCopy((uint8 *)&NvM_MirrorRam[0], NvM_CurrentJob.RamBuffer,NvM_CurrentJob.ReadLength);
        NvM_AdminBlock[NvM_CurrentJob.BlockId].ValidNvIndex = NvM_CurrentJob.CurrentNvIndex;
        /* Check for block type redundant */
        if((NVM_REDUNDANT_BLOCK == NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockManagementType)
         &&(0U != NvM_CurrentJob.CurrentNvIndex))
        {
            NvM_CurrentJob.CurrentNvIndex = 0U;
            NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_WRITE;
            NvM_CurrentJob.ProcessState = TRUE;
            NvM_CurrentJob.NvDescriptor = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockBaseNumber + NvM_CurrentJob.CurrentNvIndex;
            NvM_CurrentJob.WriteRetryCount = NvM_BlockConfig[NvM_CurrentJob.BlockId].MaxNumWriteRetries + 1U;
        }
        else
        {
            if(NvM_DataStruct.NvMState == NVM_STATE_READ_ALL)
            {
                JobId = NVM_READ_ALL;
            }
            else
            {
                JobId = NVM_READ_BLOCK;
            }
            NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockProcessStatus = NVM_REQ_OK;
            if(NULL != NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback)
            {
                (void) NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback(JobId,NVM_REQ_OK);
            }
            if(NvM_DataStruct.NvMState != NVM_STATE_READ_ALL)
            {
                NvM_DataStruct.NvMState = NVM_STATE_IDLE;
                NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
                NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
                NvM_CurrentJob.ProcessState = FALSE;
                if (NVM_MEMIF_SUSPEND_INTERNAL_JOB == NvM_DataStruct.MemIf_InternalJobState)
                {
                    MemIf_ResumeInternalJob();
                }
            #ifdef MEM_TESTING_ENABLED
                NVM_JOB_END_HOOK(JobId,NvM_CurrentJob.BlockId);
            #endif
            }
            else
            {
                /* Check whether Read all is in progress if so load next block */
                NvM_ProcessReadAll();
            }
        }
    }
    else
    {
        NvM_CurrentJob.ReadRetryCount = 0U;
        NvM_CurrentJob.JobSubState    = NVM_JOB_SUBSTATE_READ;
        NvM_CurrentJob.ProcessState   = TRUE;
    }
}
/**************************************************************************
Function name   : void NvM_InitInvalidateBlock(void)
Arguments       : void
Return type     : void
Description     : Invalidate block
**************************************************************************/
static void NvM_InitInvalidateBlock(void)
{
  uint16 fl_Nvdescriptor;
  Std_ReturnType fl_RequestStatus;
  uint8 DeviceId;

    fl_Nvdescriptor = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvBlockBaseNumber;
    NvM_CurrentJob.JobStatus = NVM_REQ_PENDING;
    DeviceId = NvM_BlockConfig[NvM_CurrentJob.BlockId].NvRamDeviceId;
    fl_RequestStatus = MemIf_InvalidateBlock(DeviceId, fl_Nvdescriptor); 
    if(fl_RequestStatus == E_OK)
    {
        NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_INVALIDATE_CBK_WAIT;
        NvM_CurrentJob.ProcessState = FALSE;
    }
    else
    {
        if(NULL != NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback)
        {
            (void) NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback(NVM_INVALIDATE_NV_BLOCK,NVM_REQ_NOT_OK);
        }
        NvM_DataStruct.NvMState = NVM_STATE_IDLE;
        NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
        NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
        NvM_CurrentJob.ProcessState = FALSE;
        NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
        if (NVM_MEMIF_SUSPEND_INTERNAL_JOB == NvM_DataStruct.MemIf_InternalJobState)
        {
            MemIf_ResumeInternalJob();
        }
        #ifdef MEM_TESTING_ENABLED
            NVM_JOB_END_HOOK(NVM_INVALIDATE_NV_BLOCK,NvM_CurrentJob.BlockId);
        #endif
    }
}

/**************************************************************************
Function name   : void NvM_InitInvalidateBlockCbkWait(void)
Arguments       : void
Return type     : void
Description     : Invalidate block cbk wait
**************************************************************************/
static void NvM_InitInvalidateBlockCbkWait()
{
    if(NvM_CurrentJob.JobStatus != NVM_REQ_PENDING)
    {
        if(NvM_CurrentJob.JobStatus != NVM_REQ_OK)
        {
            if(NULL != NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback)
            {
                (void) NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback(NVM_INVALIDATE_NV_BLOCK,NVM_REQ_NOT_OK);
            }
            NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockProcessStatus = NVM_REQ_NOT_OK;
        }
        else
        {
            NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockValidStatus = FALSE;
            NvM_AdminBlock[NvM_CurrentJob.BlockId].BlockProcessStatus = NVM_REQ_OK;
            if(NULL != NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback)
            {
                (void) NvM_BlockConfig[NvM_CurrentJob.BlockId].SingleBlockCallback(NVM_INVALIDATE_NV_BLOCK,NVM_REQ_OK);
            }
        }
        NvM_DataStruct.NvMState = NVM_STATE_IDLE;
        NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
        NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
        NvM_CurrentJob.ProcessState = FALSE;
        if (NVM_MEMIF_SUSPEND_INTERNAL_JOB == NvM_DataStruct.MemIf_InternalJobState)
        {
            MemIf_ResumeInternalJob();
        }
    #ifdef MEM_TESTING_ENABLED
        NVM_JOB_END_HOOK(NVM_INVALIDATE_NV_BLOCK,NvM_CurrentJob.BlockId);
    #endif
    }
}

#if (NVM_JOB_PRIORITIZATION == STD_ON)
/**************************************************************************
Function name   : void NvM_CancelWait(void)
Arguments       : void
Return type     : void
Description     : Cancel Job cbk wait.
***********************************************************************/
static void NvM_CancelWait(void)
{
    if(NvM_CurrentJob.JobStatus != NVM_REQ_PENDING)
    {
        NvM_CurrentJob.JobSubState = NVM_JOB_SUBSTATE_IDLE;
        NvM_DataStruct.NvMState = NVM_STATE_IDLE;
        NvM_CurrentJob.JobState = NVM_JOB_STATE_IDLE;
    }
	NvM_CurrentJob.ProcessState = FALSE;
}
#endif

static void NvM_MirrorRAMCopy(uint8 *SrcPtr,uint8 *DestPtr, uint16 length)
{
    uint16 fl_temp;
    if((SrcPtr != NULL) && (DestPtr != NULL))
    {
        for(fl_temp = 0; fl_temp< length; fl_temp++)
        {
            *DestPtr = *SrcPtr;
            DestPtr++;
            SrcPtr++;
        }
    }
}

/**************************************************************************
Function name   : boolean NvM_CheckQueueIsFull(uint8 BlockId)
Arguments       : BlockId
Return type     : boolean
Description     : Service to check if Queue is Full.
***********************************************************************/
static boolean NvM_CheckQueueIsFull(uint8 BlockId)
{
    uint8 fl_JobPriority;
    uint8 fl_Index;
    boolean fl_return = FALSE;
    fl_JobPriority = NvM_BlockConfig[BlockId].BlockJobPriority;
    fl_Index = NvM_JobQueueManagementTable[fl_JobPriority].Index;
    if (NvM_JobQueueParameter[fl_Index].CurrentQueueSize >= NvM_JobQueueManagementTable[fl_JobPriority].JobQueueSize)
    {
        fl_return = TRUE;
    }
    return fl_return;
}

/**************************************************************************
Function name   : void NvM_EnqueueRequestedJob(void)
Arguments       : void
Return type     : void
Description     : Service to Enqueue Requested Job.
**************************************************************************/
static void NvM_EnqueueRequestedJob(void)
{
    uint8 fl_JobPriority;
    uint8 fl_Index;
    NvM_QueueType* fl_JobQueueAddress;
    fl_JobPriority = NvM_BlockConfig[NvM_JobQueueEntity.BlockId].BlockJobPriority;
    fl_Index = NvM_JobQueueManagementTable[fl_JobPriority].Index;
    fl_JobQueueAddress = NvM_JobQueueManagementTable[fl_JobPriority].JobQueueAddress;
    
	if( NvM_JobQueueParameter[fl_Index].CurrentQueueSize < 0xFF )
	{
		NvM_JobQueueParameter[fl_Index].CurrentQueueSize+=1U;
	}
    fl_JobQueueAddress[NvM_JobQueueParameter[fl_Index].RequestQueueIndex].BlockId = NvM_JobQueueEntity.BlockId;
    fl_JobQueueAddress[NvM_JobQueueParameter[fl_Index].RequestQueueIndex].RequestType = NvM_JobQueueEntity.RequestType;
    fl_JobQueueAddress[NvM_JobQueueParameter[fl_Index].RequestQueueIndex].ReadLength = NvM_JobQueueEntity.ReadLength;
    fl_JobQueueAddress[NvM_JobQueueParameter[fl_Index].RequestQueueIndex].DataPointer = NvM_JobQueueEntity.DataPointer;
    fl_JobQueueAddress[NvM_JobQueueParameter[fl_Index].RequestQueueIndex].BlockOffset = NvM_JobQueueEntity.BlockOffset;
	NvM_JobQueueParameter[fl_Index].RequestQueueIndex+=1U;
		
    if(NvM_JobQueueParameter[fl_Index].RequestQueueIndex >= NvM_JobQueueManagementTable[fl_JobPriority].JobQueueSize)
    {
        NvM_JobQueueParameter[fl_Index].RequestQueueIndex = 0U;
    }
    NvM_DataStruct.JobPriorityBits |= (1U<<fl_JobPriority);
}

/**************************************************************************
Function name   : Std_ReturnType NvM_DequeueNextJob(void)
Arguments       : void
Return type     : Std_ReturnType
Description     : Service to Dequeue Next Job.
**************************************************************************/
static Std_ReturnType NvM_DequeueNextJob(void)
{
    Std_ReturnType fl_return = E_NOT_OK;
    uint8 fl_JobPriority = 0xFF;
    uint8 fl_Index;
    NvM_QueueType* fl_JobQueueAddress;
    fl_JobPriority = NvM_GetNextHighPriority();
#if (NVM_JOB_PRIORITIZATION == STD_ON)
    if (fl_JobPriority != IMMEDIATE_JOB_QUEUE_INDEX && FALSE != NvM_DataStruct.PreemptedJobFlag)
    {
        NvM_JobQueueEntity.BlockId = NvM_PreemptedJobEntity.BlockId;
        NvM_JobQueueEntity.BlockOffset = NvM_PreemptedJobEntity.BlockOffset;
        NvM_JobQueueEntity.DataPointer = NvM_PreemptedJobEntity.DataPointer;
        NvM_JobQueueEntity.ReadLength = NvM_PreemptedJobEntity.ReadLength;
        NvM_JobQueueEntity.RequestType = NvM_PreemptedJobEntity.RequestType;
        NvM_DataStruct.PreemptedJobFlag = FALSE;
        fl_return = E_OK;
    }
    else
    {
#endif
        if (FALSE != NvM_DataStruct.JobPriorityBits && fl_JobPriority < NVM_MAX_JOB_PRIORITY)
        {
            fl_Index = NvM_JobQueueManagementTable[fl_JobPriority].Index;
            fl_JobQueueAddress = NvM_JobQueueManagementTable[fl_JobPriority].JobQueueAddress;

            if((NvM_JobQueueParameter[fl_Index].CurrentQueueSize > 0U) && (fl_JobQueueAddress != NULL))
            {
                NvM_JobQueueEntity.BlockId = fl_JobQueueAddress[NvM_JobQueueParameter[fl_Index].CurrentQueueIndex].BlockId;
                NvM_JobQueueEntity.BlockOffset = fl_JobQueueAddress[NvM_JobQueueParameter[fl_Index].CurrentQueueIndex].BlockOffset;
                NvM_JobQueueEntity.DataPointer = fl_JobQueueAddress[NvM_JobQueueParameter[fl_Index].CurrentQueueIndex].DataPointer;
                NvM_JobQueueEntity.ReadLength = fl_JobQueueAddress[NvM_JobQueueParameter[fl_Index].CurrentQueueIndex].ReadLength;
                NvM_JobQueueEntity.RequestType = fl_JobQueueAddress[NvM_JobQueueParameter[fl_Index].CurrentQueueIndex].RequestType;

                NvM_EnterCriticalSection();
                NvM_JobQueueParameter[fl_Index].CurrentQueueSize -= 1U;
                NvM_ExitCriticalSection();
                NvM_JobQueueParameter[fl_Index].CurrentQueueIndex += 1U;
                if(NvM_JobQueueParameter[fl_Index].CurrentQueueIndex >= NvM_JobQueueManagementTable[fl_JobPriority].JobQueueSize)
                {
                    NvM_JobQueueParameter[fl_Index].CurrentQueueIndex = 0U;
                }
                if(0u == NvM_JobQueueParameter[fl_Index].CurrentQueueSize)
                {
                    NvM_DataStruct.JobPriorityBits &= ~(1U<<fl_JobPriority);
                }
                fl_return = E_OK;
            }
        }
#if (NVM_JOB_PRIORITIZATION == STD_ON)
    }
#endif
    return fl_return;

}

/**************************************************************************
Function name   : uint8 NvM_GetNextHighPriority(void)
Arguments       : void
Return type     : uint8
Description     : Service to get the next Highest Priority Job.
**************************************************************************/
static uint8 NvM_GetNextHighPriority (void)
{
    uint8 fl_JobPriority = 0;
    uint32 fl_PriorityBits = NvM_DataStruct.JobPriorityBits;
    if ((fl_PriorityBits & 0xffff) == 0)
    {
        fl_JobPriority += 16;
        fl_PriorityBits >>= 16;
    }
    if ((fl_PriorityBits & 0xff) == 0)
    {
        fl_JobPriority += 8;
        fl_PriorityBits >>= 8;
    }
    if ((fl_PriorityBits & 0xf) == 0)
    {
        fl_JobPriority += 4;
        fl_PriorityBits >>= 4;
    }
    if ((fl_PriorityBits & 0x3) == 0)
    {
        fl_JobPriority += 2;
        fl_PriorityBits >>= 2;
    }
    if ((fl_PriorityBits & 0x1) == 0)
    {   
        fl_JobPriority += 1;
    }
    return fl_JobPriority;
}

/**************************************************************************
Function name   : uint8 NvM_GetNextRequestType(uint8 fl_NextPrio)
Arguments       : fl_NextPrio
Return type     : uint8
Description     : Service return the next request type.
**************************************************************************/

Std_ReturnType NvM_CheckForHighPrioRead(uint8 fl_NextPrio)
{
    Std_ReturnType fl_return = E_NOT_OK;
    uint8 fl_reqType = 0xFF;
    uint8 fl_Index;
    NvM_QueueType* fl_JobQueueAddress;

    if (FALSE == NvM_DataStruct.PreemptedJobFlag)
    {
        fl_Index = NvM_JobQueueManagementTable[fl_NextPrio].Index;
        fl_JobQueueAddress = NvM_JobQueueManagementTable[fl_NextPrio].JobQueueAddress;
        if((NvM_JobQueueParameter[fl_Index].CurrentQueueSize > 0U) && (fl_JobQueueAddress != NULL))
        {
            fl_reqType = fl_JobQueueAddress[NvM_JobQueueParameter[fl_Index].CurrentQueueIndex].RequestType;
            if (NVM_READ_BLOCK == fl_reqType)
            {
                fl_return = E_OK;
            }
        }
    }
    return fl_return;
}

#if (NVM_JOB_PRIORITIZATION == STD_ON)
/**************************************************************************
Function name   : Std_ReturnType NvM_PreemptCurrentJob(void)
Arguments       : void
Return type     : Std_ReturnType
Description     : Service to cancel the current Job.
**************************************************************************/
static Std_ReturnType NvM_PreemptCurrentJob(void)
{
    Std_ReturnType fl_return = E_NOT_OK;
    if (NVM_READ_ALL  != NvM_CurrentJob.RequestType &&
        NVM_WRITE_ALL != NvM_CurrentJob.RequestType &&
        FALSE != NvM_DataStruct.PreemptedJobFlag)
    {
        fl_return = E_NOT_OK;
    }
    else 
    {
        NvM_PreemptedJobEntity.BlockId =  NvM_CurrentJob.BlockId;
        NvM_PreemptedJobEntity.BlockOffset = NvM_CurrentJob.BlockOffset;
        NvM_PreemptedJobEntity.DataPointer = NvM_CurrentJob.RamBuffer;
        NvM_PreemptedJobEntity.ReadLength = NvM_CurrentJob.ReadLength;
        NvM_PreemptedJobEntity.RequestType = NvM_CurrentJob.RequestType;
        NvM_DataStruct.PreemptedJobFlag = TRUE;
        fl_return = E_OK;
    }
    return fl_return;
} 
#endif
/**************************************************************************
Function name   : uint32 NvM_CrcCalculate(uint8 *CrcDataPtr, uint32 CrcLength, uint32 CrcStartValue, boolean CrcIsFirstCall)
Arguments       : void
Return type     : void
Description     : To Invoke CRC calculation
**************************************************************************/
static uint32 NvM_CrcCalculate(uint8 *CrcDataPtr, uint32 CrcLength, uint32 CrcStartValue, boolean CrcIsFirstCall)
{
    uint32 CrcValue;
    /* Check the block CRC type */
    if(NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockCrcType == CRC_32)
    {
        CrcValue = Crc_CalculateCRC32(CrcDataPtr,CrcLength,CrcStartValue,CrcIsFirstCall);
    }
    else if(NvM_BlockConfig[NvM_CurrentJob.BlockId].BlockCrcType == CRC_16)
    {
        CrcValue = Crc_CalculateCRC16(CrcDataPtr,CrcLength,(uint16)CrcStartValue,CrcIsFirstCall); /*CERT C 17224647*/
    }
    else
    {
        CrcValue = Crc_CalculateCRC8(CrcDataPtr,CrcLength,(uint8)CrcStartValue,CrcIsFirstCall);/*CERT C 17224163*/
    }
    return CrcValue;
}

#define NVM_DATA_SEC_END
#include "MemMap.h"

#define NVM_CODE_SEC_END
#include "MemMap.h"
#endif /* NVM_C */
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
/*Date              : 21-08-2015                                            */
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
/*Change Description:Queue and Write Verification implemented               */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 18-03-2020                                            */
/*Version           :                                                       */
/*By                : ssebast1                                              */
/*Traceability      : RTC#817466                                            */
/*Change Description:Erase Failure Handling	and Cancel Request			    */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 22-06-2020                                            */
/*Version           :                                                       */
/*By                : lthanga1                                              */
/*Traceability      : RTC#907140                                            */
/*Change Description: CRC design update                                     */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 23-11-2020                                            */
/*Version           :                                                       */
/*By                : vbalakr3                                              */
/*Traceability      : RTC#1129629                                           */
/*Change Description: Restore Block Defaults Update                         */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 16-06-2021                                            */
/*Version           :                                                       */
/*By                : vbalakr3                                              */
/*Traceability      : RTC#1363417                                           */
/*Change Description: Redundant write has been updated as per Autosar Spec  */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 26-08-2021                                            */
/*Version           :                                                       */
/*By                : jponsing                                              */
/*Traceability      : RTC#1407871                                           */
/*Change Description: Block management type NVM_BLOCK_DATASET implimented   */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 14-01-2022                                            */
/*Version           :                                                       */
/*By                : jponsing                                              */
/*Traceability      : RTC#1543928                                           */
/*Change Description: 1. NvM Job Priority is Implemented                    */
/*                    2. MemIf Internal Busy Support in NvM                 */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 07-02-2022                                            */
/*Version           :                                                       */
/*By                : jponsing                                              */
/*Traceability      : RTC#1573675                                           */
/*Change Description: InitCallback and Trace Apis are supported             */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 28-03-2022                                            */
/*Version           :                                                       */
/*By                : gthanapp                                              */
/*Traceability      : RTC#1564070                                           */
/*Change Description: Cert-C warning analysis and fix                       */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 13-04-2022                                            */
/*Version           :                                                       */
/*By                : dbalasub                                              */
/*Traceability      : RTC#1577738 and 1578526                               */
/*Change Description: NVM_GetErrorStatus-RequestResult parameter are updated*/
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 13-05-2022                                            */
/*Version           :                                                       */
/*By                : jponsing                                              */
/*Traceability      : RTC#1643018                                           */
/*Change Description: Immediate Job Priority was Implemented                */
/*--------------------------------------------------------------------------*/
