/******************************************************************************
**              CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2012. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have  jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation
**
******************************************************************************/

/******************************************************************************

File Name        :  NvMExt.c
Module Short Name:  NvMExt
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef NVM_EXT_C
#define NVM_EXT_C

#include "Std_Types.h"
#include "Os.h"
#include "NvM.h"
#include "Rte_NvMExt.h"
#include "NvMExt.h"
#include "NvMExt_Cfg.h"
#include "Mcu.h"
#include "MemLib.h"
#include "Ea_Cfg.h"
#include "Ea.h"
#include "Dio.h"
#include "EcuAppM_Callouts.h"
#ifdef BOOT_KPI_LOG_EN
#include "stddef.h"
#include "boot_kpi_r5_asr.h"
#endif   /*BOOT_KPI_LOG_EN*/
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/* This macro is used to prevent warnings about the unused parameters. */
static inline void NvMExt_UnusedPtr(uint8 x)   //#issue Review Problem ID 69178: Function-like macro definition
{ 
    (void)x; 
}



/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef enum
{
    NVMEXT_SLEEP_IDLE,
    NVMEXT_SLEEP_REQUESTED,
    NVMEXT_SLEEP_CANCEL_REQUESTED,
    NVMEXT_SLEEP_CANCEL_IN_PROGRESS,
    NVMEXT_SLEEP_BLOCKWRITE_IN_PROGRESS,
    NVMEXT_SLEEP_BLOCKWRITE_COMPLETED,
    NVMEXT_SLEEP_UPDATE_RETENTION_STATUS,
    NVMEXT_SLEEP_UPDATE_RETENTION_STATUS_WAIT,
    NVMEXT_SLEEP_PROCESS_PENDING_REQUEST,
    NVMEXT_SLEEP_APP_BLOCK_PENDING,
    NVMEXT_SLEEP_READY
}NvMExt_SleepStateType;

typedef enum
{
    NVMEXT_LVI_IDLE,
    NVMEXT_LVI_REQUESTED,
    NVMEXT_LVI_APP_BLOCK_PENDING,
    NVMEXT_LVI_READY
}NvMExt_LVIStateType;

typedef enum
{
    NVMEXT_READ_IDLE,
    NVMEXT_READ_READALL,
    NVMEXT_READ_READALL_COMPLETED,
    NVMEXT_READ_PHASE_BLOCK_READ_STRAT,
    NVMEXT_READ_PHASE_INPROGRESS,
    NVMEXT_READ_PHASE_BLOCK_READ_COMPLETED,
    NVMEXT_READ_RETENTION_STATUS_UPDATE,
    NVMEXT_READ_RETENTION_STATUS_UPDATE_WAIT
}NvMExt_ReadStateType;

typedef enum
{
    NVMEXT_MULTIPLE_BUFFER_IDLE,
    NVMEXT_MULTIPLE_BUFFER_ORIGINAL_WRITE_COMPLETED,
    NVMEXT_MULTIPLE_BUFFER_COPY_WRITE_REQUEST,
    NVMEXT_MULTIPLE_BUFFER_COPY_WRITE_REQUEST_WAIT,
    NVMEXT_MULTIPLE_BUFFER_COPY_WRITE_REQUEST_COMPLETED,
    NVMEXT_MULTIPLE_BUFFER_ORIGINAL_READ_COMPLETED,
    NVMEXT_MULTIPLE_BUFFER_COPY_READ_REQUEST,
    NVMEXT_MULTIPLE_BUFFER_COPY_READ_REQUEST_WAIT,
    NVMEXT_MULTIPLE_BUFFER_COPY_READ_REQUEST_COMPLETED,
	NVMEXT_MULTIPLE_BUFFER_DIRTY_BLOCK_MANAGE,
}NvMExt_MultipleBufferStateType;

typedef enum
{
    NVMEXT_MULTIPLE_BUFFER_JOB_IDLE,
    NVMEXT_MULTIPLE_BUFFER_JOB_WRITE,
    NVMEXT_MULTIPLE_BUFFER_JOB_READ,
}NvMExt_MultipleBufferPendingJobType;


typedef uint16 DirtyBlockType;


typedef struct
{
    NvMExt_MultipleBufferStateType      State;
    NvMExt_MultipleBufferPendingJobType PendingJob;
    uint8                               *ProcessingBuffer;
    NvM_BlockIdType                     ProcessingBlockId;
	uint8								ValidBlockIndex;
    uint8                               ProcessingIndex;
	DirtyBlockType						DirtyBlockStatus;
}NvMExtMultipleBufferManagementType;

typedef struct
{
    NvM_BlockIdType NvMExt_CurrentReadBlockId;
   volatile NvMExt_ReadStateType  NvMExt_ReadState;
    uint8 NvMExt_CurrentReadPhase;    
    uint16 NvMExt_CurrentPhaseTotalBlocks;
    uint8 NvMExt_CurrentReadIndex;
    volatile uint8 NvMExt_ReadAllCompleted;
    uint8 JobStatus;
}NvMExt_PhaseReadManagementDataType;

typedef enum
{
    NVMEXT_CHECK_RESTORE_STATE_IDLE,
    NVMEXT_CHECK_RESTORE_STATE_READALL,
	NVMEXT_CHECK_RESTORE_STATE_RESTOREONE,
	NVMEXT_CHECK_RESTORE_STATE_RESTOREALL,
	NVMEXT_CHECK_RESTORE_STATE_READALL_COMPLETED,
	NVMEXT_CHECK_RESTORE_STATE_RESTOREONE_COMPLETED,
	NVMEXT_CHECK_RESTORE_STATE_RESTOREALL_COMPLETED
}NvMExt_CheckRestoreStateType;

#define NVMEXT_VALID_RETENTION_BLOCKS       0x5A5AU
#define NVMEXT_INVALID_RETENTION_BLOCKS     0xA5A5U

#define NVMEXT_COUNTER_5SECS                     (500U)
#define BLOCK_ONE                                (1U)
#define NVMEXT_RESETCOUNTER_10SECS               (1000U)

#define NVMEXT_NVM_FIRST_BLOCK                   (2U)
#define NVMEXT_NUM_OF_NVM_BLOCKS                 (NVM_NUM_OF_BLOCKS+1U)

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
uint8 Retention_RAM_Gp_3_Marker[8];
uint8 Retention_RAM_Gp_0_Marker[8];
uint8 Retention_RAM_Gp_1_Marker[8];
uint8 Retention_RAM_Gp_2_Marker[8];
typedef uint8 Retention_group1_Type[128];


__attribute__((section(".RetentionRAM_Group1"))) 
Retention_group1_Type Retention_Group1;

uint16 RetentionBlockStatus = NVMEXT_INVALID_RETENTION_BLOCKS;

const uint16 RetentionBlockStatusDefault = NVMEXT_INVALID_RETENTION_BLOCKS; 

static NvMExtMultipleBufferManagementType NvMExtMultipleBufferManagement[NVMEXT_NUM_OF_CONFIG_SETS];

static uint8 NvMExt_UpdateRetentionBlockStatus = FALSE;

//#issue Review Problem ID 69291: Name 'NvmHardResetFlag' visibility is too wide.
//#issue Review Problem ID 136297: Static global variable 'NvmHardResetFlag' only used in 'InformNvmExt_HardResetEntry' has a wide visibility

boolean NvMExt_Phase1ReadComplete = FALSE;
boolean NvMExt_Phase2ReadComplete = FALSE;
boolean NvMExt_Phase3ReadComplete = FALSE;
/*****************************************************************************
 *                                 Locally used Variable Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/
static NvMExt_SleepStateType NvMExt_SleepState;
static NvMExt_LVIStateType NvMExt_LviState;
static NvM_BlockIdType NvMExtPendingBlock;
//#issue Review Problem ID 69094: Static global variable 'NvMExt_SleepBlockWriteIndex' only used in 'NvMExt_ProcessSleepState' has a wide visibility
static NvMExt_PhaseReadManagementDataType NvMExt_PhaseReadManagementData;
static uint8 NvMExt_SpeedupFlag;


#ifdef NVM_CHECK_RESTORE_API_TEST
volatile uint8 NvmExt_CheckRestoreTest_ApiNum = 0;
volatile NvM_BlockIdType NvmExt_CheckRestoreTest_BlockId = (NvM_BlockIdType)5;
volatile NvMExt_CheckRestoreResultType NvMExt_CheckRestoreTest_Results[NVM_NUM_OF_BLOCKS] = {NVMEXT_CHECK_RESTORE_RESULT_IDLE};
#define UPDATE_BLOCK_RESULT(a,b) NvMExt_CheckRestoreTest_Results[a] = b
#else
static inline void UPDATE_BLOCK_RESULT_FIX(uint32 a, uint32 b) 
{
    (void)a;
    (void)b;
}
#endif

/*****************************************************************************
 *                              Limited Scope Prototypes                      *
 ******************************************************************************/
/*static void NvMExt_SpeedupProcess(void); compiler warning 172-d fix */
static void NvMExt_PhaseReadProcess(void);
static void NvMExt_ProcessSleepState(void);
static void NvMExt_DisableWriteProtectAll(void);
static void NvMExt_EnableWriteProtectAll(void);
static void NvMExt_CancelAllBlockWrite(void);
static void NvMExtGetPendingBlockID(void);
static void NvMExt_MultipleBufferProcessState(void);
static Std_ReturnType CheckPreConditionReadForBlock(void);
static void NvMExt_PrvHandleCallOut(NvMExt_PhaseReadManagementDataType *pPhaseParam);
static void NvMExt_ProcessLVI(void);
static void NvMExt_CheckAndRestoreProcess(void);
static void NvmExt_DELAY_4MS(void);
static void Service_Watchdog(void);

static void NvMExt_MultipleBufferCallback(uint16 Index, NvM_RequestResultType Result);

extern void McuExt_PerformReset(void);

#ifdef NVM_READALL_METRICS
void NvM_MetricsCaptureTimeStamp(uint8 TimeStampID, uint8 Status);
#endif
/*****************************************************************************
 *                   Functions                                                *
 ******************************************************************************/

/*============================================================================
**
** Function Name    :   NvMExt_Init
**
** Visibility       :   Public
**
** Description      :   Service for NvMExt initialization
**
** Invocation       :   Function is called in EcuM context
**
** Inputs           :   None
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
void NvMExt_Init(void)
{
    NvMExt_SpeedupFlag = FALSE;
    NvMExt_SleepState = NVMEXT_SLEEP_IDLE;
	NvMExt_UpdateRetentionBlockStatus = FALSE;
    NvMExt_PhaseReadManagementData.NvMExt_ReadAllCompleted = FALSE;
    NvMExt_PhaseReadManagementData.NvMExt_ReadState = NVMEXT_READ_IDLE;
    NvMExt_PhaseReadManagementData.JobStatus = E_NOT_OK;
}

/*============================================================================
**
** Function Name    :   NvMExt_ReadAll
**
** Visibility       :   Public
**
** Description      :   To Request NvM Read All. This functionality abstracts the dependedncy 
**                      to other modules to perform Speedup functionality
**
** Invocation       :   Function is called in application context after checking 
**                      NvM will be ready to process read all requests
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void NvMExt_ReadAll(void)
{
#ifdef NVM_READALL_METRICS
    NvM_MetricsCaptureTimeStamp(0,0);
#endif
    NvM_ReadAll();
    NvMExt_PhaseReadManagementData.NvMExt_ReadAllCompleted = FALSE;
    NvMExt_PhaseReadManagementData.NvMExt_ReadState = NVMEXT_READ_READALL;
	NvMExt_RequestSpeedup();
}


/*============================================================================
**
** Function Name    :   NvMExt_MainFunction
**
** Visibility       :   Public
**
** Description      :   MainFunction for this module
**
** Invocation       :   RTE containers
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void NvMExt_MainFunction(void)
{
    NvMExt_PhaseReadProcess();
    NvMExt_ProcessSleepState();
	NvMExt_ProcessLVI();
}

/*============================================================================
**
** Function Name    :   NvMExt_RequestSpeedup
**
** Visibility       :   Public
**
** Description      :   To request NvMExt to initiate Speedup
**
** Invocation       :   BSW
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void NvMExt_RequestSpeedup(void)
{
    (void)CancelAlarm(Rte_Al_TE_NvMExt_NvMExt_SpeedupRunnable);
    (void)SetEvent(OsTask_NvmSpeedup,Rte_Ev_Run_NvMExt_NvMExt_SpeedupRunnable);
    NvMExt_SpeedupFlag = TRUE;
}

/*============================================================================
**
** Function Name    :   NvMExt_ReleaseSpeedup
**
** Visibility       :   Public
**
** Description      :   To request NvMExt to release Speedup
**
** Invocation       :   BSW
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void NvMExt_ReleaseSpeedup(void)
{
    if (NvMExt_SpeedupFlag != FALSE)
    {
        (void)SetRelAlarm(Rte_Al_TE_NvMExt_NvMExt_SpeedupRunnable, OS_MS2TICKS_SystemTimer(0U) + (TickType)1, OS_MS2TICKS_SystemTimer(10U));
        NvMExt_SpeedupFlag = FALSE;
    }
}

/*============================================================================
**
** Function Name    :   NvMExt_RequestSleep
**
** Visibility       :   Public
**
** Description      :   
**
** Invocation       :   Function is called in EcuM context
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType NvMExt_RequestSleep(void)
{
   NvMExt_SleepState = NVMEXT_SLEEP_REQUESTED;
   return E_OK;
}

Std_ReturnType NvMExt_RequestLVI(void)
{
    NvMExt_LviState = NVMEXT_LVI_REQUESTED;
    NvMExt_RequestSpeedup();
   return E_OK;
}

Std_ReturnType NvMExt_ProtectFurtherWrite(void)
{
    NvMExt_EnableWriteProtectAll();
    return E_OK;
}

Std_ReturnType NvMExt_GetNvMIdleState(uint8* IdleState)
{
    NvMExtGetPendingBlockID();
    if(NvMExtPendingBlock == 0U)
    {
        *IdleState = TRUE;
    }
    else
    {
        *IdleState = FALSE;
    }
    return E_OK;
}

Std_ReturnType NvMExt_LVI_ProcessCompletionStatus(void)
{
    Std_ReturnType RetVal;
    if(NvMExt_LviState == NVMEXT_LVI_READY)
    {
        RetVal = E_OK;
    }
    else
    {
        RetVal = E_NOT_OK;
    }
   return RetVal;
}
Std_ReturnType NvMExt_ReleaseLVI(void)
{
   NvMExt_LviState = NVMEXT_LVI_IDLE;
   NvMExt_DisableWriteProtectAll();
   return E_OK;
}


/*============================================================================
**
** Function Name    :   NvMExt_CancelSleep
**
** Visibility       :   Public
**
** Description      :   
**
** Invocation       :   Function is called in EcuM context
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType NvMExt_CancelSleep(void)
{
    NvMExt_SleepState = NVMEXT_SLEEP_CANCEL_REQUESTED;
    return E_OK;
}

/*============================================================================
**
** Function Name    :   NvMExt_ReadytoSleep
**
** Visibility       :   Public
**
** Description      :   
**
** Invocation       :   Function is called in EcuM context
**
** Inputs           :   None
**
** Outputs          :   Sleep Ready state
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType NvMExt_ReadytoSleep(void)
{
    Std_ReturnType RetVal;
    if(NvMExt_SleepState == NVMEXT_SLEEP_READY)
    {
        RetVal = E_OK;
    }
    else
    {
        RetVal = E_NOT_OK;
    }
    return RetVal;
}

Std_ReturnType NvMExt_CancelSleepCompleted(void)
{
    Std_ReturnType RetVal;
    if(NvMExt_SleepState == NVMEXT_SLEEP_IDLE)
    {
        RetVal = E_OK;
    }
    else
    {
        RetVal = E_NOT_OK;
    }
    return RetVal;
}



/*============================================================================
**
** Function Name    :   NvMExt_SpeedupRunnable
**
** Visibility       :   Public
**
** Description      :   
**
** Invocation       :   Function is called in EcuM context
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

void NvMExt_SpeedupRunnable(void)
{
	// if NvM_ReadAll is not finished, activate task with NvM stack main functions to speed up reading of NvM
    if(NvMExt_SpeedupFlag != FALSE)
    {	  
       (void)SetEvent(OsTask_MemSer, (Rte_Ev_Cyclic2_OsTask_MemSer_0_10ms | Rte_Ev_Cyclic_OsTask_MemSer_0_10ms | Rte_Ev_Run_Ea_Ea_MainFunction));	  
       (void)Schedule();	  
       (void)SetEvent(OsTask_NvmSpeedup,Rte_Ev_Run_NvMExt_NvMExt_SpeedupRunnable);
    }
}

static void NvMExt_PrvHandleCallOut(NvMExt_PhaseReadManagementDataType *pPhaseParam)
{
    const NvMExt_PhaseReadConfigType * const pPhaseConfig = &NvMExt_PhaseReadConfig[pPhaseParam->NvMExt_CurrentReadPhase];
    
    if(pPhaseConfig->PhaseCallout != NULL_PTR)
    {
        pPhaseConfig->PhaseCallout(pPhaseParam->JobStatus);
    }
    //reset the Job Status for having the next phase status intact
    pPhaseParam->JobStatus = E_OK;
}

/*============================================================================
**
** Function Name    :   NvMExt_PhaseReadProcess
**
** Visibility       :   Public
**
** Description      :   
**
** Invocation       :   Function is called in EcuM context
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static void NvMExt_PhaseReadProcess(void)
{
    NvM_RequestResultType BlockStatus=NVM_REQ_NOT_OK;

    switch(NvMExt_PhaseReadManagementData.NvMExt_ReadState)
    {
        case NVMEXT_READ_IDLE:
            /*failsafe*/
            NvMExt_ReleaseSpeedup();
            /* Do Nothing */
        break;

        case NVMEXT_READ_READALL:
            /* Do Nothing */
            /* Wait For NvM Read All Completed */
        break;

        case NVMEXT_READ_READALL_COMPLETED:
            if(NUM_OF_PHASES > 0U)
            {
                NvMExt_PhaseReadManagementData.NvMExt_CurrentReadPhase = 1U;
                NvMExt_PhaseReadManagementData.NvMExt_CurrentReadIndex = 0U;
                NvMExt_PhaseReadManagementData.NvMExt_CurrentPhaseTotalBlocks = \
                        NvMExt_PhaseReadConfig[NvMExt_PhaseReadManagementData.NvMExt_CurrentReadPhase].NoOfBlocks;
                NvMExt_PhaseReadManagementData.NvMExt_CurrentReadBlockId = \
                        (NvM_BlockIdType)NvMExt_PhaseReadConfig[NvMExt_PhaseReadManagementData.NvMExt_CurrentReadPhase].BlockIdListPtr[NvMExt_PhaseReadManagementData.NvMExt_CurrentReadIndex];

                NvMExt_PhaseReadManagementData.NvMExt_ReadState = NVMEXT_READ_PHASE_BLOCK_READ_STRAT;
                NvMExt_PhaseReadManagementData.JobStatus = E_OK;
            }
            else
            {
                NvMExt_PhaseReadManagementData.NvMExt_ReadState = NVMEXT_READ_RETENTION_STATUS_UPDATE;
                NvMExt_ReleaseSpeedup();
            }

        break;

        case NVMEXT_READ_PHASE_BLOCK_READ_STRAT:
            if(E_OK == CheckPreConditionReadForBlock())
            {
                if(E_OK == NvM_GetErrorStatus(NvMExt_PhaseReadManagementData.NvMExt_CurrentReadBlockId, &BlockStatus))
                {
                    if(NVM_REQ_PENDING != BlockStatus)
                    {
                        if(E_OK == NvM_ReadBlock(NvMExt_PhaseReadManagementData.NvMExt_CurrentReadBlockId, NULL_PTR))
                        {
                            NvMExt_PhaseReadManagementData.NvMExt_ReadState = NVMEXT_READ_PHASE_INPROGRESS; 
                        }
                    }
                }
            }
            else
            {
                if(NvMExt_PhaseReadManagementData.NvMExt_CurrentReadIndex < NvMExt_PhaseReadManagementData.NvMExt_CurrentPhaseTotalBlocks)
                {
                    NvMExt_PhaseReadManagementData.NvMExt_CurrentReadIndex++;
                }
                if(NvMExt_PhaseReadManagementData.NvMExt_CurrentReadIndex >= NvMExt_PhaseReadManagementData.NvMExt_CurrentPhaseTotalBlocks)
                {
                    NvMExt_PrvHandleCallOut(&NvMExt_PhaseReadManagementData);

                    NvMExt_PhaseReadManagementData.NvMExt_CurrentReadPhase++;
                    if(NvMExt_PhaseReadManagementData.NvMExt_CurrentReadPhase <= NUM_OF_PHASES)
                    {
                        NvMExt_PhaseReadManagementData.NvMExt_CurrentReadIndex = 0U;
                        NvMExt_PhaseReadManagementData.NvMExt_CurrentPhaseTotalBlocks = \
                                NvMExt_PhaseReadConfig[NvMExt_PhaseReadManagementData.NvMExt_CurrentReadPhase].NoOfBlocks;
                        NvMExt_PhaseReadManagementData.NvMExt_CurrentReadBlockId = \
                                (NvM_BlockIdType)NvMExt_PhaseReadConfig[NvMExt_PhaseReadManagementData.NvMExt_CurrentReadPhase].BlockIdListPtr[NvMExt_PhaseReadManagementData.NvMExt_CurrentReadIndex];
                    }
                    else
                    {
                        NvMExt_PhaseReadManagementData.NvMExt_ReadState = NVMEXT_READ_RETENTION_STATUS_UPDATE;
                        NvMExt_ReleaseSpeedup();
                    }
                }
				else
                {
                    NvMExt_PhaseReadManagementData.NvMExt_CurrentReadBlockId = \
                            (NvM_BlockIdType)NvMExt_PhaseReadConfig[NvMExt_PhaseReadManagementData.NvMExt_CurrentReadPhase].BlockIdListPtr[NvMExt_PhaseReadManagementData.NvMExt_CurrentReadIndex];
                }
            }
        break;

        case NVMEXT_READ_PHASE_INPROGRESS:
            if(E_OK == NvM_GetErrorStatus(NvMExt_PhaseReadManagementData.NvMExt_CurrentReadBlockId, &BlockStatus))
            {
                if(NVM_REQ_PENDING != BlockStatus)
                {
                    if(NVM_REQ_OK != BlockStatus)
                    {
                        NvMExt_PhaseReadManagementData.JobStatus = E_NOT_OK;
                    }
                    NvMExt_PhaseReadManagementData.NvMExt_ReadState = NVMEXT_READ_PHASE_BLOCK_READ_COMPLETED; 
                }
            }
        break;

        case NVMEXT_READ_PHASE_BLOCK_READ_COMPLETED:
                if(NvMExt_PhaseReadManagementData.NvMExt_CurrentReadIndex < NvMExt_PhaseReadManagementData.NvMExt_CurrentPhaseTotalBlocks)
                {
                    NvMExt_PhaseReadManagementData.NvMExt_CurrentReadIndex++;
                }
                if(NvMExt_PhaseReadManagementData.NvMExt_CurrentReadIndex >= NvMExt_PhaseReadManagementData.NvMExt_CurrentPhaseTotalBlocks)
                {
                    /* Provide Callout */
                    NvMExt_PrvHandleCallOut(&NvMExt_PhaseReadManagementData);
                    
                    NvMExt_PhaseReadManagementData.NvMExt_CurrentReadPhase++;
                    if(NvMExt_PhaseReadManagementData.NvMExt_CurrentReadPhase <= NUM_OF_PHASES)
                    {
                        NvMExt_PhaseReadManagementData.NvMExt_CurrentReadIndex = 0U;
                        NvMExt_PhaseReadManagementData.NvMExt_CurrentPhaseTotalBlocks = \
                                NvMExt_PhaseReadConfig[NvMExt_PhaseReadManagementData.NvMExt_CurrentReadPhase].NoOfBlocks;
                        NvMExt_PhaseReadManagementData.NvMExt_CurrentReadBlockId = \
                                (NvM_BlockIdType)NvMExt_PhaseReadConfig[NvMExt_PhaseReadManagementData.NvMExt_CurrentReadPhase].BlockIdListPtr[NvMExt_PhaseReadManagementData.NvMExt_CurrentReadIndex];
                        NvMExt_PhaseReadManagementData.NvMExt_ReadState = NVMEXT_READ_PHASE_BLOCK_READ_STRAT;
                    }
                    else
                    {
                        NvMExt_PhaseReadManagementData.NvMExt_ReadState = NVMEXT_READ_RETENTION_STATUS_UPDATE;
                        NvMExt_ReleaseSpeedup();
                    }
                }
                else
                {
                    NvMExt_PhaseReadManagementData.NvMExt_CurrentReadBlockId = \
                            (NvM_BlockIdType)NvMExt_PhaseReadConfig[NvMExt_PhaseReadManagementData.NvMExt_CurrentReadPhase].BlockIdListPtr[NvMExt_PhaseReadManagementData.NvMExt_CurrentReadIndex];

                    NvMExt_PhaseReadManagementData.NvMExt_ReadState = NVMEXT_READ_PHASE_BLOCK_READ_STRAT;                
                }
        break;

        case NVMEXT_READ_RETENTION_STATUS_UPDATE:
            if(NUM_SLEEP_RETENTION_BLOCKS > 0U)
            {
                RetentionBlockStatus = NVMEXT_INVALID_RETENTION_BLOCKS;
                if(E_OK == NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RetentionBlockStatus,NULL_PTR))
                {
                    NvMExt_PhaseReadManagementData.NvMExt_ReadState = NVMEXT_READ_RETENTION_STATUS_UPDATE_WAIT;
                }
                else
                {
                    NvMExt_PhaseReadManagementData.NvMExt_ReadState = NVMEXT_READ_IDLE;
                }
            }
            else
            {
                NvMExt_PhaseReadManagementData.NvMExt_ReadState = NVMEXT_READ_IDLE;
            }
        break;

        case NVMEXT_READ_RETENTION_STATUS_UPDATE_WAIT:
            if(E_OK == NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RetentionBlockStatus, &BlockStatus))
            {
                if(NVM_REQ_PENDING != BlockStatus)
                {
                    NvMExt_PhaseReadManagementData.NvMExt_ReadState = NVMEXT_READ_IDLE; 
                }
            }
        break;
        default:
            /* Do Nothing */
        break;

    }
}
static void NvMExt_ProcessLVI(void)
{
NvM_RequestResultType JobResult = 0U;
    switch(NvMExt_LviState)
    {
        case NVMEXT_LVI_IDLE:
        break;

        case NVMEXT_LVI_REQUESTED:
            NvMExt_EnableWriteProtectAll();
            NvMExt_CancelAllBlockWrite();
            NvMExtGetPendingBlockID();
            if(NvMExtPendingBlock != 0U)
            {
                NvMExt_LviState = NVMEXT_LVI_APP_BLOCK_PENDING;
            }
            else
            {
                NvMExt_LviState = NVMEXT_LVI_READY;
            }
        break;

        case NVMEXT_LVI_APP_BLOCK_PENDING:
            (void)NvM_GetErrorStatus(NvMExtPendingBlock, &JobResult);

            if(JobResult != NVM_REQ_PENDING)
            {
                NvMExt_LviState = NVMEXT_LVI_READY;
                NvMExt_ReleaseSpeedup();
            }
        break;

        case NVMEXT_LVI_READY:
        break;

        default:
        break;
    }
}
/*============================================================================
**
** Function Name    :   NvMExt_ProcessSleepState
**
** Visibility       :   Public
**
** Description      :   
**
** Invocation       :   Function is called in EcuM context
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static void NvMExt_ProcessSleepState(void)
{
    static NvM_BlockIdType NvMExt_SleepBlockWriteId;
    static uint8 NvMExt_SleepBlockWriteIndex;
    NvM_RequestResultType JobResult = 0U;

    switch (NvMExt_SleepState)
    {
        case NVMEXT_SLEEP_IDLE:
        break;

        case NVMEXT_SLEEP_REQUESTED:
            if(NUM_SLEEP_RETENTION_BLOCKS > 0U)
            {
                NvMExt_SleepBlockWriteIndex = 0U;
                NvMExt_SleepBlockWriteId = NvMExt_MasterRetentionList[NvMExt_SleepBlockWriteIndex];
                if(E_OK == NvM_WriteBlock(NvMExt_SleepBlockWriteId,NULL_PTR))
                {
                    NvMExt_SleepState = NVMEXT_SLEEP_BLOCKWRITE_IN_PROGRESS;
                }
            }        
            else
            {
                NvMExt_SleepState = NVMEXT_SLEEP_PROCESS_PENDING_REQUEST;
            }
        break;

        case NVMEXT_SLEEP_BLOCKWRITE_IN_PROGRESS:
            (void)NvM_GetErrorStatus(NvMExt_SleepBlockWriteId,&JobResult);
            if(JobResult != NVM_REQ_PENDING)
            {
                NvMExt_SleepState = NVMEXT_SLEEP_BLOCKWRITE_COMPLETED;
            }
        break;

        case NVMEXT_SLEEP_BLOCKWRITE_COMPLETED:
            NvMExt_SleepBlockWriteIndex++;
            if(NvMExt_SleepBlockWriteIndex < NUM_SLEEP_RETENTION_BLOCKS)
            {
                NvMExt_SleepBlockWriteId = NvMExt_MasterRetentionList[NvMExt_SleepBlockWriteIndex];
                if(E_OK == NvM_WriteBlock(NvMExt_SleepBlockWriteId,NULL_PTR))
                {
                    NvMExt_SleepState = NVMEXT_SLEEP_BLOCKWRITE_IN_PROGRESS;
                }
            }
            else
            {
                NvMExt_SleepState = NVMEXT_SLEEP_UPDATE_RETENTION_STATUS;
            }
        break;

        case NVMEXT_SLEEP_UPDATE_RETENTION_STATUS:
            RetentionBlockStatus = NVMEXT_VALID_RETENTION_BLOCKS;
            if(E_OK == NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RetentionBlockStatus,NULL_PTR))
            {
                NvMExt_SleepState = NVMEXT_SLEEP_UPDATE_RETENTION_STATUS_WAIT;
                NvMExt_UpdateRetentionBlockStatus = TRUE;
            }
            else
            {
                NvMExt_SleepState = NVMEXT_SLEEP_PROCESS_PENDING_REQUEST;
            }
        break;

        case NVMEXT_SLEEP_UPDATE_RETENTION_STATUS_WAIT:
            if(E_OK == NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RetentionBlockStatus, &JobResult))
            {
                if(NVM_REQ_PENDING != JobResult)
                {
                    NvMExt_SleepState = NVMEXT_SLEEP_PROCESS_PENDING_REQUEST; 
                }
            }
        break;

        case NVMEXT_SLEEP_CANCEL_REQUESTED:
            if(E_OK == NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RetentionBlockStatus, &JobResult))
            {
                if(NVM_REQ_PENDING != JobResult)
                { 
                    if(FALSE != NvMExt_UpdateRetentionBlockStatus)
                    {
                        RetentionBlockStatus = NVMEXT_INVALID_RETENTION_BLOCKS;
                        if(E_OK == NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RetentionBlockStatus,NULL_PTR))
                        {
                            NvMExt_SleepState = NVMEXT_SLEEP_CANCEL_IN_PROGRESS;
                        }
                        else
                        {
                            NvMExt_DisableWriteProtectAll();
                            NvMExt_SleepState = NVMEXT_SLEEP_IDLE;
							NvMExt_UpdateRetentionBlockStatus = FALSE;
                        }
                    }
                    else
                    {
                        NvMExt_DisableWriteProtectAll();
                        NvMExt_SleepState = NVMEXT_SLEEP_IDLE;
						NvMExt_UpdateRetentionBlockStatus = FALSE;
                    }
                }
            }
        break;

        case NVMEXT_SLEEP_CANCEL_IN_PROGRESS:
            if(E_OK == NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RetentionBlockStatus, &JobResult))
            {
                if(NVM_REQ_PENDING != JobResult)
                {
                    NvMExt_DisableWriteProtectAll();
                    NvMExt_SleepState = NVMEXT_SLEEP_IDLE;
					NvMExt_UpdateRetentionBlockStatus = FALSE;
                }
            }
        break;

        case NVMEXT_SLEEP_PROCESS_PENDING_REQUEST:
            NvMExt_EnableWriteProtectAll();
            NvMExtGetPendingBlockID();
            if(NvMExtPendingBlock != 0U)
            {
                NvMExt_SleepState = NVMEXT_SLEEP_APP_BLOCK_PENDING;
            }
            else
            {
                NvMExt_SleepState = NVMEXT_SLEEP_READY;
				NvMExt_UpdateRetentionBlockStatus = FALSE;
            }
        break;

        case NVMEXT_SLEEP_APP_BLOCK_PENDING:
            (void)NvM_GetErrorStatus(NvMExtPendingBlock, &JobResult);

            if(JobResult != NVM_REQ_PENDING)
            {
                NvMExt_SleepState = NVMEXT_SLEEP_PROCESS_PENDING_REQUEST;
            }
        break;

        case NVMEXT_SLEEP_READY:
        break;
        default:
            /* Do Nothing */
        break;


    }
}

/*============================================================================
**
** Function Name    :   NvMExt_DisableWriteProtectAll
**
** Visibility       :   Public
**
** Description      :   
**
** Invocation       :   Function is called in EcuM context
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static void NvMExt_DisableWriteProtectAll(void)
{
    uint16 BlockId;
    for(BlockId = 2U; BlockId < NVM_NUM_OF_BLOCKS; BlockId ++)
    {
        (void)NvM_SetBlockProtection(BlockId, FALSE);
    }
    NvMExt_SleepState = NVMEXT_SLEEP_IDLE;
	NvMExt_UpdateRetentionBlockStatus = FALSE;
}

/*============================================================================
**
** Function Name    :   NvMExt_EnableWriteProtectAll
**
** Visibility       :   Public
**
** Description      :   
**
** Invocation       :   Function is called in EcuM context
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static void NvMExt_EnableWriteProtectAll(void)
{
    uint16 BlockId;
    for(BlockId = 2U; BlockId < NVM_NUM_OF_BLOCKS; BlockId ++)
    {
        (void)NvM_SetBlockProtection(BlockId, TRUE);
    }
}

/*============================================================================
**
** Function Name    :   NvMExt_CancelAllBlockWrite
**
** Visibility       :   Public
**
** Description      :   
**
** Invocation       :   Function is called in EcuM context
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static void NvMExt_CancelAllBlockWrite(void)
{
    uint16 BlockId;
    for(BlockId = 2U; BlockId < NVM_NUM_OF_BLOCKS; BlockId ++)
    {
        (void)NvM_CancelJobs(BlockId);
    }
}

/*============================================================================
**
** Function Name    :   NvMExtGetPendingBlockID
**
** Visibility       :   Public
**
** Description      :   
**
** Invocation       :   Function is called in EcuM context
**
** Inputs           :   ConfigPtr
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
static void NvMExtGetPendingBlockID(void)
{
    NvM_RequestResultType BlockStatus = 0;
    uint16 BlockId;
    NvMExtPendingBlock = 0U;
    for(BlockId = 2U; BlockId < NVM_NUM_OF_BLOCKS; BlockId ++)
    {
        (void)NvM_GetErrorStatus(BlockId, &BlockStatus);
        if(BlockStatus == NVM_REQ_PENDING)
        {
            NvMExtPendingBlock = BlockId;
            break;
        }
    }
}

/*============================================================================
**
** Function Name    :   CheckPreConditionReadForBlock
**
** Visibility       :   Public
**
** Description      :   
**
** Invocation       :   Function is called in EcuM context
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static Std_ReturnType CheckPreConditionReadForBlock(void)
{
    Std_ReturnType RetVal;
    uint8 CurrentPhase;
    uint8 CurrentIndex;
    RetVal = E_NOT_OK;

    CurrentPhase = NvMExt_PhaseReadManagementData.NvMExt_CurrentReadPhase;
    CurrentIndex = NvMExt_PhaseReadManagementData.NvMExt_CurrentReadIndex;
    if(FALSE != NvMExt_PhaseReadConfig[CurrentPhase].RetentionStatePtr[CurrentIndex])
    {
        if(RetentionBlockStatus == NVMEXT_VALID_RETENTION_BLOCKS)
        {
            RetVal = E_OK;
        }
        else
        {
            RetVal = E_NOT_OK;
        }
    }
	else
	{
        RetVal = E_OK;
	}
    return RetVal;
}

/*============================================================================
**
** Function Name    :   NvMExt_RestoreBlockDefaults
**
** Visibility       :   Public
**
** Description      :   Service to restore the default data to its corresponding RAM block
**
** Invocation       :   Function is called from meetcdd
**
** Inputs           :   NvmBlockId, NvMDestPtr
**
** Return type      :   Std_ReturnType
                        E_OK: request has been accepted
                        E_NOT_OK: request has not been accepted
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType NvMExt_RestoreBlockDefaults( NvM_BlockIdType NvmBlockId, uint8* NvMDestPtr)
{
    Std_ReturnType RetVal;
    NvM_RequestResultType BlockStatus=NVM_REQ_NOT_OK;

    RetVal = E_NOT_OK;

    if (E_OK == NvM_GetErrorStatus(NvmBlockId, &BlockStatus))
    {
        if (NVM_REQ_PENDING != BlockStatus)
        {
            RetVal = NvM_RestoreBlockDefaults(NvmBlockId,NvMDestPtr);
        }
    }

    return RetVal;
}

/*============================================================================
**
** Function Name    :   NvMExt_ReadBlock
**
** Visibility       :   Public
**
** Description      :   This function used to trigger NvM_ReadBlock for the
**                      requested block
**
** Invocation       :   Function is called from meetcdd
**
** Inputs           :   NvmBlockId, NvMDstPtr
**
** Return type      :   Std_ReturnType
                        E_OK: request has been accepted
                        E_NOT_OK: request has not been accepted
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType NvMExt_ReadBlock(NvM_BlockIdType NvmBlockId,uint8* NvMDstPtr)
{
    Std_ReturnType RetVal;
    NvM_RequestResultType BlockStatus=NVM_REQ_NOT_OK;

    RetVal = E_NOT_OK;

    if (E_OK == NvM_GetErrorStatus(NvmBlockId, &BlockStatus))
    {
        if (NVM_REQ_PENDING != BlockStatus)
        {
            RetVal = NvM_ReadBlock(NvmBlockId,NvMDstPtr);
        }
    }

    return RetVal;
}


/*============================================================================
**
** Function Name    :   NvMExt_WriteBlock
**
** Visibility       :   Public
**
** Description      :   This function used to trigger NvM_WriteBlock
**
** Invocation       :   Function is called from meetcdd
**
** Inputs           :   BlockId, NvM_SrcPtr
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(Std_ReturnType, NvMExt_CODE) NvMExt_WriteBlock(NvM_BlockIdType NvmBlockId, P2VAR(UInt8, AUTOMATIC, RTE_NVMEXT_APPL_VAR) NvM_SrcPtr)
 //#issue Review Problem ID 69256: Identifiers used in declaration and definition of function 'NvMExt_WriteBlock' are not identical
{
    Std_ReturnType RetVal;
    NvM_RequestResultType BlockStatus=NVM_REQ_NOT_OK;

    RetVal = E_NOT_OK;

    if (E_OK == NvM_GetErrorStatus(NvmBlockId, &BlockStatus))
    {
        if (NVM_REQ_PENDING != BlockStatus)
        {
            RetVal = NvM_WriteBlock(NvmBlockId,NvM_SrcPtr);
        }
    }

    return RetVal;
}

/*============================================================================
**
** Function Name    :   NvMExt_GetErrorStatus
**
** Visibility       :   Public
**
** Description      :   This function used to get the error status of requested
**                      block from nvm
**
** Invocation       :   Function is called from meetcdd
**
** Inputs           :   BlockId, RequestResultPtr
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType NvMExt_GetErrorStatus( NvM_BlockIdType NvmBlockId, NvM_RequestResultType* RequestResultPtr)
{
    Std_ReturnType RetVal;

    RetVal = NvM_GetErrorStatus(NvmBlockId, RequestResultPtr);

    return RetVal;
}

/*============================================================================
**
** Function Name    :   NvMExt_MultipleJobEndNotification
**
** Visibility       :   Public
**
** Description      :   
**
** Invocation       :   Function is called in EcuM context
**
** Inputs           :   JobId, JobResult
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
extern void NvM_MultiBlockJobEndNotification(uint8 JobId, NvM_RequestResultType Result);
Std_ReturnType NvMExt_MultipleJobEndNotification(uint8 JobId, NvM_RequestResultType Result)
{
    NvM_MultiBlockJobEndNotification(JobId, Result);
    if(JobId == NVM_READ_ALL)
    {
#ifdef NVM_READALL_METRICS
        NvM_MetricsCaptureTimeStamp(0,1);
#endif
    #ifdef BOOT_KPI_LOG_EN
        BOOT_KPI_LOG(KPI_ID_VIP_NVM_READALL_FINISH, "READALL_FINISH");
    #endif   /*BOOT_KPI_LOG_EN*/ 
        NvMExt_PhaseReadManagementData.NvMExt_ReadAllCompleted = TRUE;
        NvMExt_PhaseReadManagementData.NvMExt_ReadState = NVMEXT_READ_READALL_COMPLETED;
    }
    return E_OK;
}

/************************************************************************************************************************************/
/*Tripple Buffer management start*/
/************************************************************************************************************************************/
static void NvMExt_MultipleBufferCallback(uint16 Index, NvM_RequestResultType Result)/*CERT C 17806237*/
{
    static uint8 NvMExt_MultiJobId = 0u;
    static uint16 NvMExt_MultiIndex = 0u;   
    static uint8 NvMExt_MultiMagicFlag = FALSE;

    (void)Result;
    //if(NvMExt_MultipleBlockConfig[Index].BlockCallback != NULL)
    //{
        if(NvMExtMultipleBufferManagement[Index].PendingJob == NVMEXT_MULTIPLE_BUFFER_JOB_WRITE)
        {
			NvMExt_MultiIndex = Index;
			NvMExt_MultiJobId = NVM_WRITE_BLOCK;
			NvMExt_MultiMagicFlag = TRUE;
           // NvMExt_MultipleBlockConfig[Index].BlockCallback(NVM_WRITE_BLOCK,Result);
        }
        if(NvMExtMultipleBufferManagement[Index].PendingJob == NVMEXT_MULTIPLE_BUFFER_JOB_READ)
        {
            if(NvMExt_PhaseReadManagementData.NvMExt_ReadState == NVMEXT_READ_READALL)
            {
				NvMExt_MultiIndex = Index;
				NvMExt_MultiJobId = NVM_READ_ALL;
				NvMExt_MultiMagicFlag = TRUE;
                //NvMExt_MultipleBlockConfig[Index].BlockCallback(NVM_READ_ALL,Result);
            }
            else
            {
				NvMExt_MultiIndex = Index;
				NvMExt_MultiJobId = NVM_READ_BLOCK;
				NvMExt_MultiMagicFlag = TRUE;
               // NvMExt_MultipleBlockConfig[Index].BlockCallback(NVM_READ_BLOCK,Result);
            }
        }
    //}
}

/*============================================================================
**
** Function Name    :   NvMExt_MultipleBufferProcessState
**
** Visibility       :   Public
**
** Description      :   This function used to get the read all status
**
** Invocation       :   Function is called from modemgr
**
** Inputs           :
**
** Outputs          :   status
**
** Critical Section :
**
**==========================================================================*/

static void NvMExt_MultipleBufferProcessState(void)
{
	uint16 StateIteration;
	uint16 fl_ProccessingIndex;
	NvM_BlockIdType fl_ValidBlockIndex;
	uint8 DirtyBlockIndex;
    Std_ReturnType RetVal;
    NvM_RequestResultType NvM_Result=NVM_REQ_NOT_OK;

    for(StateIteration = 0U; StateIteration < (uint16)NVMEXT_NUM_OF_MULTIPLE_BLOCKS; StateIteration++)
    {
        switch(NvMExtMultipleBufferManagement[StateIteration].State)
        {
            case NVMEXT_MULTIPLE_BUFFER_IDLE:
            break;

            case NVMEXT_MULTIPLE_BUFFER_ORIGINAL_WRITE_COMPLETED:                                                              
				fl_ValidBlockIndex = NvMExtMultipleBufferManagement[StateIteration].ValidBlockIndex;                                    
                fl_ProccessingIndex = NvMExtMultipleBufferManagement[StateIteration].ProcessingIndex;                          
                NvMExtMultipleBufferManagement[StateIteration].ProcessingBlockId = NvMExt_MultipleBlockConfig[StateIteration].MultipleCopiesIndexBuffer[fl_ValidBlockIndex];
                NvMExtMultipleBufferManagement[StateIteration].ProcessingBuffer = (uint8 *)NvMExt_MultipleBlockConfig[StateIteration].RamBufferArray[fl_ProccessingIndex];
                NvMExtMultipleBufferManagement[StateIteration].State = NVMEXT_MULTIPLE_BUFFER_COPY_READ_REQUEST; 
            break;                                                                                                             

            case NVMEXT_MULTIPLE_BUFFER_COPY_WRITE_REQUEST:
                RetVal = NvM_WriteBlock(NvMExtMultipleBufferManagement[StateIteration].ProcessingBlockId, NvMExtMultipleBufferManagement[StateIteration].ProcessingBuffer);
                if(RetVal == E_OK)
                {
                    NvMExtMultipleBufferManagement[StateIteration].State = NVMEXT_MULTIPLE_BUFFER_COPY_WRITE_REQUEST_WAIT;
                }
            break;

            case NVMEXT_MULTIPLE_BUFFER_COPY_WRITE_REQUEST_WAIT:
                RetVal = NvM_GetErrorStatus(NvMExtMultipleBufferManagement[StateIteration].ProcessingBlockId, &NvM_Result);
                if(RetVal == E_OK)
                {
                    if(NVM_REQ_PENDING != NvM_Result)
                    {
                        if(NVM_REQ_OK != NvM_Result)
                        {
                            NvMExt_MultipleBufferCallback(StateIteration, NvM_Result);
                            NvMExtMultipleBufferManagement[StateIteration].State = NVMEXT_MULTIPLE_BUFFER_IDLE;
							NvMExtMultipleBufferManagement[StateIteration].PendingJob = NVMEXT_MULTIPLE_BUFFER_JOB_IDLE;
                        }
                        else
                        {
                            NvMExtMultipleBufferManagement[StateIteration].State = NVMEXT_MULTIPLE_BUFFER_COPY_WRITE_REQUEST_COMPLETED;
                        }
                    }
                }
            break;

            case NVMEXT_MULTIPLE_BUFFER_COPY_WRITE_REQUEST_COMPLETED:
                if(NvMExtMultipleBufferManagement[StateIteration].PendingJob == NVMEXT_MULTIPLE_BUFFER_JOB_WRITE)
                {
					fl_ValidBlockIndex = NvMExtMultipleBufferManagement[StateIteration].ValidBlockIndex;
					NvMExtMultipleBufferManagement[StateIteration].ProcessingIndex++;
					if(NvMExtMultipleBufferManagement[StateIteration].ProcessingIndex < NvMExt_MultipleBlockConfig[StateIteration].NumberOfCopies)
					{
	                    NvMExtMultipleBufferManagement[StateIteration].ProcessingBlockId = NvMExt_MultipleBlockConfig[StateIteration].MultipleCopiesIndexBuffer[fl_ValidBlockIndex];

	                    NvMExtMultipleBufferManagement[StateIteration].ProcessingBuffer = (uint8 *)NvMExt_MultipleBlockConfig[StateIteration].RamBufferArray[NvMExtMultipleBufferManagement[StateIteration].ProcessingIndex];

						NvMExtMultipleBufferManagement[StateIteration].State = NVMEXT_MULTIPLE_BUFFER_COPY_READ_REQUEST;
					}
					else
					{
                            NvMExt_MultipleBufferCallback(StateIteration, NVM_REQ_OK);
                            NvMExtMultipleBufferManagement[StateIteration].State = NVMEXT_MULTIPLE_BUFFER_IDLE;
                            NvMExtMultipleBufferManagement[StateIteration].PendingJob = NVMEXT_MULTIPLE_BUFFER_JOB_IDLE;
					}
                }
				else
				{
					NvMExtMultipleBufferManagement[StateIteration].DirtyBlockStatus &= (DirtyBlockType)(~((uint32)0x01U << NvMExtMultipleBufferManagement[StateIteration].ProcessingIndex));
					NvMExtMultipleBufferManagement[StateIteration].State = NVMEXT_MULTIPLE_BUFFER_DIRTY_BLOCK_MANAGE;
				}
            break;

            case NVMEXT_MULTIPLE_BUFFER_ORIGINAL_READ_COMPLETED:                                                                        

                fl_ProccessingIndex = NvMExtMultipleBufferManagement[StateIteration].ProcessingIndex;                          
                                                                                                                               
                NvMExtMultipleBufferManagement[StateIteration].ProcessingBlockId = NvMExt_MultipleBlockConfig[StateIteration].MultipleCopiesIndexBuffer[fl_ProccessingIndex];
                                                                                                                               
                NvMExtMultipleBufferManagement[StateIteration].ProcessingBuffer =  (uint8 *)NvMExt_MultipleBlockConfig[StateIteration].RamBufferArray[fl_ProccessingIndex];
                                                                                                                               
                NvMExtMultipleBufferManagement[StateIteration].State = NVMEXT_MULTIPLE_BUFFER_COPY_READ_REQUEST; 
            break;                                                                                                                      

            case NVMEXT_MULTIPLE_BUFFER_COPY_READ_REQUEST:
                
                RetVal = NvM_ReadBlock(NvMExtMultipleBufferManagement[StateIteration].ProcessingBlockId, NvMExtMultipleBufferManagement[StateIteration].ProcessingBuffer);
                if(RetVal == E_OK)
                {
                    NvMExtMultipleBufferManagement[StateIteration].State = NVMEXT_MULTIPLE_BUFFER_COPY_READ_REQUEST_WAIT;
                }
            break;

            case NVMEXT_MULTIPLE_BUFFER_COPY_READ_REQUEST_WAIT:
                RetVal = NvM_GetErrorStatus(NvMExtMultipleBufferManagement[StateIteration].ProcessingBlockId, &NvM_Result);

                if(RetVal == E_OK)
                {
                    if(NVM_REQ_PENDING != NvM_Result)
                    {
                        if(NVM_REQ_OK != NvM_Result)
                        {
			                if(NvMExtMultipleBufferManagement[StateIteration].PendingJob == NVMEXT_MULTIPLE_BUFFER_JOB_WRITE)
			                {
	                            NvMExt_MultipleBufferCallback(StateIteration, NvM_Result);
	                            NvMExtMultipleBufferManagement[StateIteration].State = NVMEXT_MULTIPLE_BUFFER_IDLE;
                                NvMExtMultipleBufferManagement[StateIteration].PendingJob = NVMEXT_MULTIPLE_BUFFER_JOB_IDLE;
							}
							else
							{
								NvMExtMultipleBufferManagement[StateIteration].State = NVMEXT_MULTIPLE_BUFFER_COPY_READ_REQUEST_COMPLETED;
								NvMExtMultipleBufferManagement[StateIteration].DirtyBlockStatus |= (DirtyBlockType)((uint32)0x01U << NvMExtMultipleBufferManagement[StateIteration].ProcessingIndex);
							}
                        }
                        else
                        {
                            if(NvMExtMultipleBufferManagement[StateIteration].ValidBlockIndex == 0xFFU)
							{
								NvMExtMultipleBufferManagement[StateIteration].ValidBlockIndex = NvMExtMultipleBufferManagement[StateIteration].ProcessingIndex;
							}
                            NvMExtMultipleBufferManagement[StateIteration].State = NVMEXT_MULTIPLE_BUFFER_COPY_READ_REQUEST_COMPLETED;
                        }
                    }
                }
            break;

            case NVMEXT_MULTIPLE_BUFFER_COPY_READ_REQUEST_COMPLETED:
                if(NvMExtMultipleBufferManagement[StateIteration].PendingJob == NVMEXT_MULTIPLE_BUFFER_JOB_WRITE)
                {
                    NvMExtMultipleBufferManagement[StateIteration].ProcessingBlockId = NvMExt_MultipleBlockConfig[StateIteration].MultipleCopiesIndexBuffer[NvMExtMultipleBufferManagement[StateIteration].ProcessingIndex];

                    NvMExtMultipleBufferManagement[StateIteration].ProcessingBuffer = (uint8 *)NvMExt_MultipleBlockConfig[StateIteration].RamBufferArray[NvMExtMultipleBufferManagement[StateIteration].ProcessingIndex];

                    NvMExtMultipleBufferManagement[StateIteration].State = NVMEXT_MULTIPLE_BUFFER_COPY_WRITE_REQUEST;
                }
				else
				{
					NvMExtMultipleBufferManagement[StateIteration].ProcessingIndex++;
					if(NvMExtMultipleBufferManagement[StateIteration].ProcessingIndex < NvMExt_MultipleBlockConfig[StateIteration].NumberOfCopies)
					{
	                    NvMExtMultipleBufferManagement[StateIteration].ProcessingBlockId = NvMExt_MultipleBlockConfig[StateIteration].MultipleCopiesIndexBuffer[NvMExtMultipleBufferManagement[StateIteration].ProcessingIndex];

	                    NvMExtMultipleBufferManagement[StateIteration].ProcessingBuffer = (uint8 *)NvMExt_MultipleBlockConfig[StateIteration].RamBufferArray[NvMExtMultipleBufferManagement[StateIteration].ProcessingIndex];

						NvMExtMultipleBufferManagement[StateIteration].State = NVMEXT_MULTIPLE_BUFFER_COPY_READ_REQUEST;
					}
					else
					{
						NvMExtMultipleBufferManagement[StateIteration].State = NVMEXT_MULTIPLE_BUFFER_DIRTY_BLOCK_MANAGE;
					}
				}
            break;

            case NVMEXT_MULTIPLE_BUFFER_DIRTY_BLOCK_MANAGE:
		
				if(NvMExtMultipleBufferManagement[StateIteration].ValidBlockIndex != 0xFFU)
				{
					if(FALSE != NvMExtMultipleBufferManagement[StateIteration].DirtyBlockStatus)
					{
						for(DirtyBlockIndex = 0; DirtyBlockIndex < NvMExt_MultipleBlockConfig[StateIteration].NumberOfCopies; DirtyBlockIndex++)
						{
							if(FALSE != (NvMExtMultipleBufferManagement[StateIteration].DirtyBlockStatus & (DirtyBlockType)((uint32)0x01U << DirtyBlockIndex)))
							{
								NvMExtMultipleBufferManagement[StateIteration].ProcessingIndex = DirtyBlockIndex;
								/* MemCopy to store data from valid Block Buffer */
                                MemLib_MemCpy((uint8 *)NvMExt_MultipleBlockConfig[StateIteration].RamBufferArray[NvMExtMultipleBufferManagement[StateIteration].ProcessingIndex], \
                                              (uint8 *)NvMExt_MultipleBlockConfig[StateIteration].RamBufferArray[NvMExtMultipleBufferManagement[StateIteration].ValidBlockIndex], \
                                              (uint32)NvMExt_MultipleBlockConfig[StateIteration].Length);/*CERT C 17806068*/

			                    NvMExtMultipleBufferManagement[StateIteration].ProcessingBlockId = NvMExt_MultipleBlockConfig[StateIteration].MultipleCopiesIndexBuffer[NvMExtMultipleBufferManagement[StateIteration].ProcessingIndex];

			                    NvMExtMultipleBufferManagement[StateIteration].ProcessingBuffer = (uint8 *)NvMExt_MultipleBlockConfig[StateIteration].RamBufferArray[NvMExtMultipleBufferManagement[StateIteration].ProcessingIndex];
								
								NvMExtMultipleBufferManagement[StateIteration].State = NVMEXT_MULTIPLE_BUFFER_COPY_WRITE_REQUEST;
							}
						}
					}
					else
					{
	                    NvMExt_MultipleBufferCallback(StateIteration, NVM_REQ_OK);
	                    NvMExtMultipleBufferManagement[StateIteration].State = NVMEXT_MULTIPLE_BUFFER_IDLE;
                        NvMExtMultipleBufferManagement[StateIteration].PendingJob = NVMEXT_MULTIPLE_BUFFER_JOB_IDLE;
					}
				}
				else
				{
                    NvMExt_MultipleBufferCallback(StateIteration, NVM_REQ_NOT_OK);
                    NvMExtMultipleBufferManagement[StateIteration].State = NVMEXT_MULTIPLE_BUFFER_IDLE;
                    NvMExtMultipleBufferManagement[StateIteration].PendingJob = NVMEXT_MULTIPLE_BUFFER_JOB_IDLE;
				}
			break;

			default:
				/* Do Nothing */
			break;
        }
    }
}


Std_ReturnType NvMExt_NotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_ICPlantCfg_JobFinished(uint8 JobId, NvM_RequestResultType Result)
{
    if(NvMExtMultipleBufferManagement[0].PendingJob == NVMEXT_MULTIPLE_BUFFER_JOB_IDLE)
    {
	    if((JobId == NVM_READ_BLOCK) || (JobId == NVM_READ_ALL))
	    {
		    if(NVM_REQ_OK == Result)
		    {
			    NvMExtMultipleBufferManagement[0].ValidBlockIndex = 0U;
			    NvMExtMultipleBufferManagement[0].ProcessingIndex = 1U;
			    NvMExtMultipleBufferManagement[0].State = NVMEXT_MULTIPLE_BUFFER_ORIGINAL_READ_COMPLETED;
		    }
			else if (NVM_REQ_PENDING == Result)
		    {
				(void)NvMExt_MultipleBlockConfig[0].BlockCallback(JobId,Result);
		    }
		    else
		    {
			    NvMExtMultipleBufferManagement[0].ValidBlockIndex = 0xFFU;
			    NvMExtMultipleBufferManagement[0].ProcessingIndex = 1U;
			    NvMExtMultipleBufferManagement[0].State = NVMEXT_MULTIPLE_BUFFER_ORIGINAL_READ_COMPLETED;
                NvMExtMultipleBufferManagement[0].DirtyBlockStatus = 0x01U;
		    }
		    NvMExtMultipleBufferManagement[0].PendingJob = NVMEXT_MULTIPLE_BUFFER_JOB_READ;
	    }
	    if(JobId == NVM_WRITE_BLOCK)
	    {
		    if(NVM_REQ_OK == Result)
		    {
			    NvMExtMultipleBufferManagement[0].PendingJob = NVMEXT_MULTIPLE_BUFFER_JOB_WRITE;
			    NvMExtMultipleBufferManagement[0].ValidBlockIndex = 0U;
			    NvMExtMultipleBufferManagement[0].ProcessingIndex = 1U;
			    NvMExtMultipleBufferManagement[0].State = NVMEXT_MULTIPLE_BUFFER_ORIGINAL_WRITE_COMPLETED;
		    }
			else if (NVM_REQ_PENDING == Result)
		    {
				(void)NvMExt_MultipleBlockConfig[0].BlockCallback(JobId,Result);
		    }
		    else
		    {
                NvMExt_MultipleBufferCallback(0, Result);
                NvMExtMultipleBufferManagement[0].State = NVMEXT_MULTIPLE_BUFFER_IDLE;
			    NvMExtMultipleBufferManagement[0].PendingJob = NVMEXT_MULTIPLE_BUFFER_JOB_IDLE;
		    }
	    }
    }
    return E_OK;
}



Std_ReturnType NvMExt_NotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_ICPlantCfg_Copy1_JobFinished(uint8 JobId, NvM_RequestResultType Result)
{
    NvMExt_UnusedPtr(JobId);
    NvMExt_UnusedPtr(Result);
    return E_OK;
}

Std_ReturnType NvMExt_NotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_ICPlantCfg_Copy2_JobFinished(uint8 JobId, NvM_RequestResultType Result)
{
    NvMExt_UnusedPtr(JobId);
    NvMExt_UnusedPtr(Result);
    return E_OK;
}

/************************************************************************************************************************************/
/*Tripple Buffer management end*/
/************************************************************************************************************************************/

/*============================================================================
**
** Function Name    :   NvmExt_GetNvMReadAllStatus
**
** Visibility       :   Public
**
** Description      :   This function used to get the read all status
**
** Invocation       :   Function is called from modemgr
**
** Inputs           :
**
** Outputs          :   status
**
** Critical Section :
**
**==========================================================================*/
void NvmExt_GetNvMReadAllStatus(Boolean *Status)
{
    *Status = NvMExt_PhaseReadManagementData.NvMExt_ReadAllCompleted;
}

void NvMExt_NotfyJobEnd_Retention_RAM_Gp_0(void)
{

}

void NvMExt_NotfyJobEnd_Retention_RAM_Gp_2(void)
{

}

void NvMExt_NotfyJobEnd_Retention_RAM_Gp_1(void)
{

}

void NvMExt_NotfyJobEnd_Retention_RAM_Gp_3(void)
{

}
void NvMExt_NotfyJobEnd_RetentionBlockStatus(void)
{

}
void NvMExt_NotfyJobEnd_Retention_Group1(void)
{
}



Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Config_Copy1_JobFinished (uint8 ServiceId, NvM_RequestResultType JobResult)
{
    NvMExt_UnusedPtr(ServiceId);
    NvMExt_UnusedPtr(JobResult);
	return E_OK;
}
Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Config_Copy2_JobFinished (uint8 ServiceId, NvM_RequestResultType JobResult)
{
    NvMExt_UnusedPtr(ServiceId);
    NvMExt_UnusedPtr(JobResult);
	return E_OK;
}
Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Illumination_Copy1_JobFinished (uint8 ServiceId, NvM_RequestResultType JobResult)
{
    NvMExt_UnusedPtr(ServiceId);
    NvMExt_UnusedPtr(JobResult);
	return E_OK;
}
Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Illumination_Copy2_JobFinished (uint8 ServiceId, NvM_RequestResultType JobResult)
{
    NvMExt_UnusedPtr(ServiceId);
    NvMExt_UnusedPtr(JobResult);
	return E_OK;
}
Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIApps_FuntionalSafetyKAM_Copy1_JobFinished (uint8 ServiceId, NvM_RequestResultType JobResult)
{
    NvMExt_UnusedPtr(ServiceId);
    NvMExt_UnusedPtr(JobResult);
	return E_OK;
}
Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIApps_FuntionalSafetyKAM_Copy2_JobFinished (uint8 ServiceId, NvM_RequestResultType JobResult)
{
    NvMExt_UnusedPtr(ServiceId);
    NvMExt_UnusedPtr(JobResult);
	return E_OK;
}
void InformNvmExt_HardResetEntry(void)
{
    static uint8 NvmHardResetFlag = 0;
    NvmHardResetFlag = 1u;
}
void NvMExt_Phase1ReadCompletionNotification(uint8 Status)
{
    (void)Status;
    NvMExt_Phase1ReadComplete = TRUE;
    Rte_Write_ppSRPhasedRead_Status_phase1readcompleted_PhasedRead_Status_phase1readcompleted(NvMExt_Phase1ReadComplete);    
}

void NvMExt_Phase2ReadCompletionNotification(uint8 Status)
{
    (void)Status;
    NvMExt_Phase2ReadComplete = TRUE;
    Rte_Write_ppSRPhasedRead_Status_phase2readcompleted_PhasedRead_Status_phase2readcompleted(NvMExt_Phase2ReadComplete);
}

void NvMExt_Phase3ReadCompletionNotification(uint8 Status)
{
    (void)Status;
    NvMExt_Phase3ReadComplete = TRUE;
    Rte_Write_ppSRPhasedRead_Status_phase3readcompleted_PhasedRead_Status_phase3readcompleted(NvMExt_Phase3ReadComplete);
}

void NvMExt_GetPhase1ReadCompletionNotification(uint8 *Status)
{
*Status = (uint8)NvMExt_Phase1ReadComplete;
}

void NvMExt_GetPhase2ReadCompletionNotification(uint8 *Status)
{
*Status = (uint8)NvMExt_Phase2ReadComplete;
}

void NvMExt_GetPhase3ReadCompletionNotification(uint8 *Status)
{
*Status = (uint8)NvMExt_Phase3ReadComplete;
}

#endif

/*============================================================================
**============================================================================
** R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
**===========================================================================*/
/*---------------------------------------------------------------------------
Date               : 09-Apr-2024
CDSID              : vbalakr3
Traceability       : 
Change Description : Initial version of NvMExt
-----------------------------------------------------------------------------*/

