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

File Name        :  NvMExt.h
Module Short Name:  NvMExt
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef NVM_EXT_H
#define NVM_EXT_H

/*#include "EcuMExt.h" - compiler warning #47-D Fix.*/
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
typedef enum
{
	NVMEXT_IDLE = 0,
	NVMEXT_PENDING,
	NVMEXT_SHUTDOWN_COMPLETED
}NvMExt_ShutdownType;

typedef enum
{
	NVMEXT_CHECK_RESTORE_RESULT_IDLE,
	NVMEXT_CHECK_RESTORE_RESULT_READALL,
	NVMEXT_CHECK_RESTORE_RESULT_RESTOREONE,
	NVMEXT_CHECK_RESTORE_RESULT_RESTOREALL,
	NVMEXT_CHECK_RESTORE_RESULT_TIMEOUT,
	NVMEXT_CHECK_RESTORE_RESULT_FAIL
}NvMExt_CheckRestoreResultType;


extern void MemAbs_NotifyHardResetEntry(void);
extern Std_ReturnType MemAbs_ReadyToHardReset(void);
extern void MemAbs_NotifyNVMTestStatus(boolean NvMExt_NVMTestRunning);

//void NvMExt_CancelAllBlockWrite(void); - compiler fix 
Std_ReturnType NvMExt_ReadBlock(NvM_BlockIdType NvmBlockId, uint8* NvMDstPtr);
Std_ReturnType NvMExt_GetErrorStatus(NvM_BlockIdType NvmBlockId, NvM_RequestResultType* RequestResultPtr);
FUNC(Std_ReturnType, NvMExt_CODE) NvMExt_WriteBlock(NvM_BlockIdType NvmBlockId, P2VAR(UInt8, AUTOMATIC, RTE_NVMEXT_APPL_VAR) NvM_SrcPtr);
Std_ReturnType NvMExt_RestoreBlockDefaults(NvM_BlockIdType NvmBlockId, uint8* NvMDestPtr);
Std_ReturnType NvMExt_CancelSleepCompleted(void);
Std_ReturnType NvMExt_LVI_ProcessCompletionStatus(void);
Std_ReturnType NvMExt_ReleaseLVI(void);
Std_ReturnType NvMExt_RequestLVI(void);
Std_ReturnType NvMExt_ProtectFurtherWrite(void);
Std_ReturnType NvMExt_GetNvMIdleState(uint8* IdleState);
void InformNvmExt_HardResetEntry(void);
void NvmExt_GetNvMReadAllStatus(Boolean *Status);
void NvMExt_NotfyJobEnd_Retention_RAM_Gp_0(void);
void NvMExt_NotfyJobEnd_Retention_RAM_Gp_2(void);
void NvMExt_NotfyJobEnd_Retention_RAM_Gp_1(void);
void NvMExt_NotfyJobEnd_Retention_RAM_Gp_3(void);
void NvMExt_NotfyJobEnd_RetentionBlockStatus(void);
void NvMExt_NotfyJobEnd_Retention_Group1(void);

Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Config_Copy1_JobFinished (uint8 ServiceId, NvM_RequestResultType JobResult);
Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Config_Copy2_JobFinished (uint8 ServiceId, NvM_RequestResultType JobResult);
Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Illumination_Copy1_JobFinished (uint8 ServiceId, NvM_RequestResultType JobResult);
Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_Illumination_Copy2_JobFinished (uint8 ServiceId, NvM_RequestResultType JobResult);
Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIApps_FuntionalSafetyKAM_Copy1_JobFinished (uint8 ServiceId, NvM_RequestResultType JobResult);
Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_DIApps_FuntionalSafetyKAM_Copy2_JobFinished (uint8 ServiceId, NvM_RequestResultType JobResult);
Std_ReturnType NvMExt_NotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_ICPlantCfg_Copy1_JobFinished(uint8 JobId, NvM_RequestResultType Result);
Std_ReturnType NvMExt_NotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_ICPlantCfg_Copy2_JobFinished(uint8 JobId, NvM_RequestResultType Result);
Std_ReturnType NvMExt_NotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_ICPlantCfg_JobFinished(uint8 JobId, NvM_RequestResultType Result);
Std_ReturnType NvMExt_MultipleJobEndNotification(uint8 JobId, NvM_RequestResultType Result);
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

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

/*****************************************************************************
 *                              Limited Scope Prototypes                      *
 ******************************************************************************/

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
** Outputs          :	None
**
** Critical Section :
**
**==========================================================================*/
void NvMExt_Init(void);

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
void NvMExt_ReadAll(void);

/*============================================================================
**
** Function Name    :   NvMExt_NVMConsistencyCheck
**
** Visibility       :   Public
**
** Description      :   To test DATA validity in all NVM blocks
**
** Invocation       :   Function is called in application context after checking
**                      NvM will be ready to process all read requests
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void NvMExt_NVMConsistencyCheck(void);

/*============================================================================
**
** Function Name    :   NvMExt_RestoreBlock
**
** Visibility       :   Public
**
** Description      :   To restore default data in any NVM block
**
** Invocation       :   Function is called in application context after checking
**                      NvM will be ready to process all write requests
**
** Inputs           :   BlockId - NVM Block ID to erase
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void NvMExt_RestoreBlock(NvM_BlockIdType BlockId);

/*============================================================================
**
** Function Name    :   NvMExt_RestoreAllBlocks
**
** Visibility       :   Public
**
** Description      :   To restore default data in all NVM blocks
**
** Invocation       :   Function is called in application context after checking
**                      NvM will be ready to process all write requests
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void NvMExt_RestoreAllBlocks(void);

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
void NvMExt_MainFunction(void);

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
void NvMExt_RequestSpeedup(void);

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
void NvMExt_ReleaseSpeedup(void);

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
Std_ReturnType NvMExt_RequestSleep(void);

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
Std_ReturnType NvMExt_CancelSleep(void);

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
Std_ReturnType NvMExt_ReadytoSleep(void);
/*============================================================================
**
** Function Name    :   NvMExt_GetBlockRequestStatus
**
** Visibility       :   Public
**
** Description      :
**
** Invocation       :   Function is called in NvMExtSf
**
** Inputs           :   JobId pointer and MultiIndex pointer
**
** Outputs          :   Std_ReturnType
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType NvMExt_GetBlockRequestStatus (uint8* JobId, uint8* MultiIndex);

#endif    /* */
/* end of file */
