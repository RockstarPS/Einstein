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
*    Auto generated code in vAUTOSAR TOOL by SGOPAL1 at 2026-03-31 13:17:24.271043900
********************************************************************************************************************/

#ifndef OS_TASK_LCFG_C
#define OS_TASK_LCFG_C


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/

#include "Os_Lcfg.h"

VAR(OsTaskParamType, OS_VAR) OsTaskParam_InitTaskDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_AppFunDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_AudioFunDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_Can0DataRxEvDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_Can1DataRxEvDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_CANFunDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_DispFunDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_EthFunDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_FotaEvDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_FotaFunDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_GaugeFunDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_IdleTaskDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_IndFunDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_LinFunDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_McalDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_ModeMgtDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_NvmSpeedupDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_SafeAppDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_TripFunDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_WarnFunDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_WdgMngtDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_DiagnosticsDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_LSH_16msDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_SafeBswDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_MemSerDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTask_IpcUclEvDyn = {0};
VAR(OsTaskParamType, OS_VAR) OsTaskParam_OsTaskRenderDyn = {0};

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

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_AppFun = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_AppFun,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_AppFun,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_AppFun,
		/* .TaskPriority			= */ osPrioTask_OsTask_AppFun,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_AppFun,
		/* .TaskCategory			= */ osCategoryTask_OsTask_AppFun,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_AppFun),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_QMSystem),
		/* .TaskType				= */ osTypeTask_OsTask_AppFun,
		/* .TaskID					= */ osTaskID_OsTask_AppFun,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_AppFunDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_AudioFun = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_AudioFun,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_AudioFun,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_AudioFun,
		/* .TaskPriority			= */ osPrioTask_OsTask_AudioFun,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_AudioFun,
		/* .TaskCategory			= */ osCategoryTask_OsTask_AudioFun,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_AudioFun),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_QMSystem),
		/* .TaskType				= */ osTypeTask_OsTask_AudioFun,
		/* .TaskID					= */ osTaskID_OsTask_AudioFun,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_AudioFunDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_Can0DataRxEv = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_Can0DataRxEv,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_Can0DataRxEv,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_Can0DataRxEv,
		/* .TaskPriority			= */ osPrioTask_OsTask_Can0DataRxEv,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_Can0DataRxEv,
		/* .TaskCategory			= */ osCategoryTask_OsTask_Can0DataRxEv,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_Can0DataRxEv),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_QMSystem),
		/* .TaskType				= */ osTypeTask_OsTask_Can0DataRxEv,
		/* .TaskID					= */ osTaskID_OsTask_Can0DataRxEv,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_Can0DataRxEvDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_Can1DataRxEv = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_Can1DataRxEv,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_Can1DataRxEv,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_Can1DataRxEv,
		/* .TaskPriority			= */ osPrioTask_OsTask_Can1DataRxEv,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_Can1DataRxEv,
		/* .TaskCategory			= */ osCategoryTask_OsTask_Can1DataRxEv,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_Can1DataRxEv),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_QMSystem),
		/* .TaskType				= */ osTypeTask_OsTask_Can1DataRxEv,
		/* .TaskID					= */ osTaskID_OsTask_Can1DataRxEv,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_Can1DataRxEvDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_CANFun = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_CANFun,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_CANFun,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_CANFun,
		/* .TaskPriority			= */ osPrioTask_OsTask_CANFun,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_CANFun,
		/* .TaskCategory			= */ osCategoryTask_OsTask_CANFun,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_CANFun),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_QMSystem),
		/* .TaskType				= */ osTypeTask_OsTask_CANFun,
		/* .TaskID					= */ osTaskID_OsTask_CANFun,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_CANFunDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_DispFun = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_DispFun,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_DispFun,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_DispFun,
		/* .TaskPriority			= */ osPrioTask_OsTask_DispFun,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_DispFun,
		/* .TaskCategory			= */ osCategoryTask_OsTask_DispFun,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_DispFun),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_QMSystem),
		/* .TaskType				= */ osTypeTask_OsTask_DispFun,
		/* .TaskID					= */ osTaskID_OsTask_DispFun,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_DispFunDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_EthFun = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_EthFun,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_EthFun,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_EthFun,
		/* .TaskPriority			= */ osPrioTask_OsTask_EthFun,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_EthFun,
		/* .TaskCategory			= */ osCategoryTask_OsTask_EthFun,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_EthFun),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_QMSystem),
		/* .TaskType				= */ osTypeTask_OsTask_EthFun,
		/* .TaskID					= */ osTaskID_OsTask_EthFun,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_EthFunDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_FotaEv = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_FotaEv,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_FotaEv,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_FotaEv,
		/* .TaskPriority			= */ osPrioTask_OsTask_FotaEv,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_FotaEv,
		/* .TaskCategory			= */ osCategoryTask_OsTask_FotaEv,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_FotaEv),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_QMSystem),
		/* .TaskType				= */ osTypeTask_OsTask_FotaEv,
		/* .TaskID					= */ osTaskID_OsTask_FotaEv,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_FotaEvDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_FotaFun = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_FotaFun,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_FotaFun,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_FotaFun,
		/* .TaskPriority			= */ osPrioTask_OsTask_FotaFun,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_FotaFun,
		/* .TaskCategory			= */ osCategoryTask_OsTask_FotaFun,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_FotaFun),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_QMSystem),
		/* .TaskType				= */ osTypeTask_OsTask_FotaFun,
		/* .TaskID					= */ osTaskID_OsTask_FotaFun,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_FotaFunDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_GaugeFun = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_GaugeFun,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_GaugeFun,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_GaugeFun,
		/* .TaskPriority			= */ osPrioTask_OsTask_GaugeFun,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_GaugeFun,
		/* .TaskCategory			= */ osCategoryTask_OsTask_GaugeFun,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_GaugeFun),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_QMSystem),
		/* .TaskType				= */ osTypeTask_OsTask_GaugeFun,
		/* .TaskID					= */ osTaskID_OsTask_GaugeFun,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_GaugeFunDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_IdleTask = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_IdleTask,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_IdleTask,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_IdleTask,
		/* .TaskPriority			= */ osPrioTask_OsTask_IdleTask,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_IdleTask,
		/* .TaskCategory			= */ osCategoryTask_OsTask_IdleTask,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_IdleTask),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_QMSystem),
		/* .TaskType				= */ osTypeTask_OsTask_IdleTask,
		/* .TaskID					= */ osTaskID_OsTask_IdleTask,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_IdleTaskDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_IndFun = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_IndFun,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_IndFun,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_IndFun,
		/* .TaskPriority			= */ osPrioTask_OsTask_IndFun,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_IndFun,
		/* .TaskCategory			= */ osCategoryTask_OsTask_IndFun,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_IndFun),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_QMSystem),
		/* .TaskType				= */ osTypeTask_OsTask_IndFun,
		/* .TaskID					= */ osTaskID_OsTask_IndFun,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_IndFunDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_LinFun = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_LinFun,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_LinFun,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_LinFun,
		/* .TaskPriority			= */ osPrioTask_OsTask_LinFun,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_LinFun,
		/* .TaskCategory			= */ osCategoryTask_OsTask_LinFun,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_LinFun),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_QMSystem),
		/* .TaskType				= */ osTypeTask_OsTask_LinFun,
		/* .TaskID					= */ osTaskID_OsTask_LinFun,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_LinFunDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_Mcal = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_Mcal,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_Mcal,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_Mcal,
		/* .TaskPriority			= */ osPrioTask_OsTask_Mcal,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_Mcal,
		/* .TaskCategory			= */ osCategoryTask_OsTask_Mcal,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_Mcal),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_QMSystem),
		/* .TaskType				= */ osTypeTask_OsTask_Mcal,
		/* .TaskID					= */ osTaskID_OsTask_Mcal,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_McalDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_ModeMgt = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_ModeMgt,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_ModeMgt,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_ModeMgt,
		/* .TaskPriority			= */ osPrioTask_OsTask_ModeMgt,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_ModeMgt,
		/* .TaskCategory			= */ osCategoryTask_OsTask_ModeMgt,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_ModeMgt),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_QMSystem),
		/* .TaskType				= */ osTypeTask_OsTask_ModeMgt,
		/* .TaskID					= */ osTaskID_OsTask_ModeMgt,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_ModeMgtDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_NvmSpeedup = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_NvmSpeedup,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_NvmSpeedup,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_NvmSpeedup,
		/* .TaskPriority			= */ osPrioTask_OsTask_NvmSpeedup,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_NvmSpeedup,
		/* .TaskCategory			= */ osCategoryTask_OsTask_NvmSpeedup,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_NvmSpeedup),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_QMSystem),
		/* .TaskType				= */ osTypeTask_OsTask_NvmSpeedup,
		/* .TaskID					= */ osTaskID_OsTask_NvmSpeedup,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_NvmSpeedupDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_SafeApp = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_SafeApp,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_SafeApp,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_SafeApp,
		/* .TaskPriority			= */ osPrioTask_OsTask_SafeApp,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_SafeApp,
		/* .TaskCategory			= */ osCategoryTask_OsTask_SafeApp,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_SafeApp),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_TrustedSystem),
		/* .TaskType				= */ osTypeTask_OsTask_SafeApp,
		/* .TaskID					= */ osTaskID_OsTask_SafeApp,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_SafeAppDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_TripFun = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_TripFun,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_TripFun,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_TripFun,
		/* .TaskPriority			= */ osPrioTask_OsTask_TripFun,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_TripFun,
		/* .TaskCategory			= */ osCategoryTask_OsTask_TripFun,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_TripFun),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_QMSystem),
		/* .TaskType				= */ osTypeTask_OsTask_TripFun,
		/* .TaskID					= */ osTaskID_OsTask_TripFun,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_TripFunDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_WarnFun = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_WarnFun,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_WarnFun,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_WarnFun,
		/* .TaskPriority			= */ osPrioTask_OsTask_WarnFun,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_WarnFun,
		/* .TaskCategory			= */ osCategoryTask_OsTask_WarnFun,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_WarnFun),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_QMSystem),
		/* .TaskType				= */ osTypeTask_OsTask_WarnFun,
		/* .TaskID					= */ osTaskID_OsTask_WarnFun,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_WarnFunDyn
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

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_Diagnostics = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_Diagnostics,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_Diagnostics,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_Diagnostics,
		/* .TaskPriority			= */ osPrioTask_OsTask_Diagnostics,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_Diagnostics,
		/* .TaskCategory			= */ osCategoryTask_OsTask_Diagnostics,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_Diagnostics),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_QMSystem),
		/* .TaskType				= */ osTypeTask_OsTask_Diagnostics,
		/* .TaskID					= */ osTaskID_OsTask_Diagnostics,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_DiagnosticsDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_LSH_16ms = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_LSH_16ms,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_LSH_16ms,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_LSH_16ms,
		/* .TaskPriority			= */ osPrioTask_OsTask_LSH_16ms,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_LSH_16ms,
		/* .TaskCategory			= */ osCategoryTask_OsTask_LSH_16ms,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_LSH_16ms),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_QMSystem),
		/* .TaskType				= */ osTypeTask_OsTask_LSH_16ms,
		/* .TaskID					= */ osTaskID_OsTask_LSH_16ms,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_LSH_16msDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_SafeBsw = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_SafeBsw,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_SafeBsw,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_SafeBsw,
		/* .TaskPriority			= */ osPrioTask_OsTask_SafeBsw,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_SafeBsw,
		/* .TaskCategory			= */ osCategoryTask_OsTask_SafeBsw,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_SafeBsw),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_TrustedSystem),
		/* .TaskType				= */ osTypeTask_OsTask_SafeBsw,
		/* .TaskID					= */ osTaskID_OsTask_SafeBsw,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_SafeBswDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_MemSer = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_MemSer,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_MemSer,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_MemSer,
		/* .TaskPriority			= */ osPrioTask_OsTask_MemSer,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_MemSer,
		/* .TaskCategory			= */ osCategoryTask_OsTask_MemSer,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_MemSer),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_QMSystem),
		/* .TaskType				= */ osTypeTask_OsTask_MemSer,
		/* .TaskID					= */ osTaskID_OsTask_MemSer,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_MemSerDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_IpcUclEv = {
		/* .TaskFunction			= */ osTaskFunction_OsTask_IpcUclEv,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTask_IpcUclEv,
		/* .TaskStackSize			= */ osStackSizeTask_OsTask_IpcUclEv,
		/* .TaskPriority			= */ osPrioTask_OsTask_IpcUclEv,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTask_IpcUclEv,
		/* .TaskCategory			= */ osCategoryTask_OsTask_IpcUclEv,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTask_IpcUclEv),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_QMSystem),
		/* .TaskType				= */ osTypeTask_OsTask_IpcUclEv,
		/* .TaskID					= */ osTaskID_OsTask_IpcUclEv,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTask_IpcUclEvDyn
};

CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTaskRender = {
		/* .TaskFunction			= */ osTaskFunction_OsTaskRender,
		/* .TaskStackStartAddress	= */ osStackStartAddressTask_OsTaskRender,
		/* .TaskStackSize			= */ osStackSizeTask_OsTaskRender,
		/* .TaskPriority			= */ osPrioTask_OsTaskRender,
		/* .TaskMaxActivationCount	= */ osMaxActivationCount_OsTaskRender,
		/* .TaskCategory			= */ osCategoryTask_OsTaskRender,
		/* .pObjRef					= */ (OsObjConfigRefType)&(OsObjConfig_OsTaskRender),
		/* .pAppRef					= */ (OsAppConfigRefType)&(OsAppConfig_QMSystem),
		/* .TaskType				= */ osTypeTask_OsTaskRender,
		/* .TaskID					= */ osTaskID_OsTaskRender,
		/* .TaskParamRAM 			= */ (OsTaskParamRefType)&OsTaskParam_OsTaskRenderDyn
};


CONST (OsTaskConfigRefType, OS_CONST) OsCore0_OsTaskConfigRefList[OsNumberOfTasks] = {
			(OsTaskConfigRefType)&OsTaskConfig_InitTask,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_AppFun,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_AudioFun,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_Can0DataRxEv,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_Can1DataRxEv,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_CANFun,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_DispFun,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_EthFun,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_FotaEv,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_FotaFun,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_GaugeFun,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_IdleTask,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_IndFun,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_LinFun,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_Mcal,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_ModeMgt,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_NvmSpeedup,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_SafeApp,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_TripFun,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_WarnFun,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_WdgMngt,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_Diagnostics,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_LSH_16ms,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_SafeBsw,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_MemSer,
			(OsTaskConfigRefType)&OsTaskConfig_OsTask_IpcUclEv,
			(OsTaskConfigRefType)&OsTaskConfig_OsTaskRender
};

const TaskType AutoStartTaskList[OsNumberOfAutoStartTasks] = 
{
osTaskID_InitTask,
osTaskID_OsTask_IdleTask,
osTaskID_OsTaskRender
};

const OsTaskConfigRefType TcbTaskRefConfig[OsNumberOfTasks] = {
(OsTaskConfigRefType)&OsTaskConfig_InitTask,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_AppFun,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_AudioFun,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_Can0DataRxEv,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_Can1DataRxEv,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_CANFun,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_DispFun,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_EthFun,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_FotaEv,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_FotaFun,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_GaugeFun,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_IdleTask,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_IndFun,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_LinFun,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_Mcal,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_ModeMgt,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_NvmSpeedup,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_SafeApp,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_TripFun,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_WarnFun,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_WdgMngt,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_Diagnostics,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_LSH_16ms,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_SafeBsw,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_MemSer,
(OsTaskConfigRefType)&OsTaskConfig_OsTask_IpcUclEv,
(OsTaskConfigRefType)&OsTaskConfig_OsTaskRender
};




#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

