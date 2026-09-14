/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2026 by Visteon Corporation.       All rights reserved.         
*                                                                                                                    
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                   
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve              
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States     
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,             
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its       
* rights under all copyright laws to protect this work as a published work, when appropriate.                        
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it   
* without the written authorization of Visteon Corporation.                                                          
********************************************************************************************************************/

/*******************************************************************************************************************
*    @file Os_Task_Lcfg.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by MNATRAMI at 2026-04-06 16:31:56.335514900
********************************************************************************************************************/

#ifndef OS_TASK_LCFG_C
#define OS_TASK_LCFG_C


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/

#include "Os_Lcfg.h"

VAR(OsTaskParamType, OS_VAR) OsTaskParam_InitTaskDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_UclDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_DiagnosticsDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_CANFunDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_WdgMngtDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_IdleTaskDyn = {0};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_InitTask = {
		/* .TaskFunction			= */ osTaskFunction_InitTask,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_InitTask,
		/* .TaskStackSize			= */ osStackSizeTask_InitTask,
		/* .TaskPriority			= */ osPrioTask_InitTask,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_InitTask,
		/* .TaskCategory			= */ osCategoryTask_InitTask,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_InitTask),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_TrustedSystem),
		/* .TaskType				= */ osTypeTask_InitTask,
		/* .TaskID					= */ osTaskID_InitTask,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_InitTaskDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_Ucl = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_Ucl,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_Ucl,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_Ucl,
		/* .TaskPriority			= */ osPrioTask_OsTask_Ucl,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_Ucl,
		/* .TaskCategory			= */ osCategoryTask_OsTask_Ucl,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_Ucl),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_TrustedSystem),
		/* .TaskType				= */ osTypeTask_OsTask_Ucl,
		/* .TaskID					= */ osTaskID_OsTask_Ucl,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_UclDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_Diagnostics = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_Diagnostics,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_Diagnostics,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_Diagnostics,
		/* .TaskPriority			= */ osPrioTask_OsTask_Diagnostics,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_Diagnostics,
		/* .TaskCategory			= */ osCategoryTask_OsTask_Diagnostics,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_Diagnostics),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_TrustedSystem),
		/* .TaskType				= */ osTypeTask_OsTask_Diagnostics,
		/* .TaskID					= */ osTaskID_OsTask_Diagnostics,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_DiagnosticsDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_CANFun = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_CANFun,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_CANFun,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_CANFun,
		/* .TaskPriority			= */ osPrioTask_OsTask_CANFun,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_CANFun,
		/* .TaskCategory			= */ osCategoryTask_OsTask_CANFun,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_CANFun),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_TrustedSystem),
		/* .TaskType				= */ osTypeTask_OsTask_CANFun,
		/* .TaskID					= */ osTaskID_OsTask_CANFun,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_CANFunDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_WdgMngt = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_WdgMngt,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_WdgMngt,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_WdgMngt,
		/* .TaskPriority			= */ osPrioTask_OsTask_WdgMngt,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_WdgMngt,
		/* .TaskCategory			= */ osCategoryTask_OsTask_WdgMngt,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_WdgMngt),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_TrustedSystem),
		/* .TaskType				= */ osTypeTask_OsTask_WdgMngt,
		/* .TaskID					= */ osTaskID_OsTask_WdgMngt,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_WdgMngtDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_IdleTask = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_IdleTask,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_IdleTask,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_IdleTask,
		/* .TaskPriority			= */ osPrioTask_OsTask_IdleTask,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_IdleTask,
		/* .TaskCategory			= */ osCategoryTask_OsTask_IdleTask,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_IdleTask),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_TrustedSystem),
		/* .TaskType				= */ osTypeTask_OsTask_IdleTask,
		/* .TaskID					= */ osTaskID_OsTask_IdleTask,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_IdleTaskDyn
};


CONST (OsTaskConfigRefType, OS_CONST) OsCore0_OsTaskConfigRefList[OsNumberOfTasks] = {
			(OsTaskConfigRefType)&OsTaskConfig_InitTask,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_Ucl,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_Diagnostics,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_CANFun,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_WdgMngt,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_IdleTask
};

const TaskType AutoStartTaskList[OsNumberOfAutoStartTasks] = 
{
osTaskID_InitTask,
osTaskID_OsTask_IdleTask
};

const OsTaskConfigRefType TcbTaskRefConfig[OsNumberOfTasks] = {
(OsTaskConfigRefType)&OsTaskConfig_InitTask,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_Ucl,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_Diagnostics,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_CANFun,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_WdgMngt,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_IdleTask
};




#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

