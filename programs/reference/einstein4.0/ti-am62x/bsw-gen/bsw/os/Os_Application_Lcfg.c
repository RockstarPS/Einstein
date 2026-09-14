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
*    @file Os_Application_Lcfg.c
*    @ingroup Os Configuration
*    @brief This is Os link time configuration source file. It contains definitions of link time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by KPORKODI at 2026-06-15 15:53:48.405100500
********************************************************************************************************************/

#ifndef OS_APPLICATION_LCFG_C
#define OS_APPLICATION_LCFG_C


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/

#include "Os_Lcfg.h"

CONST(OsAppConfigType, OS_CONST) OsAppConfig_TrustedSystem = 
{
	/*AppId						= */ OS_CFG_OSAPPLICATION_TRUSTEDSYSTEM,
	/*AccessId					= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*AccessLevel				= */ OS_ACCESS_PRIVILEGED,
	/*OsCoreConfigRef			= */ (OsCoreConfigType*)&(OsCoreConfig_OsCoreAsr0),
	/*pObjListRef				= */ (OsObjConfigRefType)(OsApplication_TrustedSystemObjConfigRef),
	/*pHookRef					= */ (OsHookConfigRefType)&OsHookConfigList_App_TrustedSystem
};

CONST(OsAppConfigType, OS_CONST) OsAppConfig_QMSystem = 
{
	/*AppId						= */ OS_CFG_OSAPPLICATION_QMSYSTEM,
	/*AccessId					= */ OS_CFG_MPU_REGION_OsMpu_QMSystem,
	/*AccessLevel				= */ OS_ACCESS_UNPRIVILEGED,
	/*OsCoreConfigRef			= */ (OsCoreConfigType*)&(OsCoreConfig_OsCoreAsr0),
	/*pObjListRef				= */ (OsObjConfigRefType)(OsApplication_QMSystemObjConfigRef),
	/*pHookRef					= */ (OsHookConfigRefType)&OsHookConfigList_App_QMSystem
};



CONST(OsObjConfigType, OS_CONST) OsObjConfig_InitTask =
{
	/*ObjectId						= */ Os_Object_Id_0,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdInitTask_BOT,
	/*StackSize						= */ osStackSizeTask_InitTask,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_AppFun =
{
	/*ObjectId						= */ Os_Object_Id_1,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_QMSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_QMSystem),
	/*StackStartAddress				= */ osdOsTask_AppFun_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_AppFun,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_AudioFun =
{
	/*ObjectId						= */ Os_Object_Id_2,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_QMSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_QMSystem),
	/*StackStartAddress				= */ osdOsTask_AudioFun_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_AudioFun,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_Can0DataRxEv =
{
	/*ObjectId						= */ Os_Object_Id_3,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_QMSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_QMSystem),
	/*StackStartAddress				= */ osdOsTask_Can0DataRxEv_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_Can0DataRxEv,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(10) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^10 = 1kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_Can1DataRxEv =
{
	/*ObjectId						= */ Os_Object_Id_4,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_QMSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_QMSystem),
	/*StackStartAddress				= */ osdOsTask_Can1DataRxEv_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_Can1DataRxEv,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(10) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^10 = 1kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_CANFun =
{
	/*ObjectId						= */ Os_Object_Id_5,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_QMSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_QMSystem),
	/*StackStartAddress				= */ osdOsTask_CANFun_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_CANFun,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(10) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^10 = 1kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_DispFun =
{
	/*ObjectId						= */ Os_Object_Id_6,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_QMSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_QMSystem),
	/*StackStartAddress				= */ osdOsTask_DispFun_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_DispFun,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(10) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^10 = 1kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_EthFun =
{
	/*ObjectId						= */ Os_Object_Id_7,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_QMSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_QMSystem),
	/*StackStartAddress				= */ osdOsTask_EthFun_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_EthFun,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_FotaEv =
{
	/*ObjectId						= */ Os_Object_Id_8,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_QMSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_QMSystem),
	/*StackStartAddress				= */ osdOsTask_FotaEv_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_FotaEv,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(10) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^10 = 1kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_FotaFun =
{
	/*ObjectId						= */ Os_Object_Id_9,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_QMSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_QMSystem),
	/*StackStartAddress				= */ osdOsTask_FotaFun_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_FotaFun,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(10) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^10 = 1kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_GaugeFun =
{
	/*ObjectId						= */ Os_Object_Id_10,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_QMSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_QMSystem),
	/*StackStartAddress				= */ osdOsTask_GaugeFun_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_GaugeFun,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_IdleTask =
{
	/*ObjectId						= */ Os_Object_Id_11,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_QMSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_QMSystem),
	/*StackStartAddress				= */ osdOsTask_IdleTask_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_IdleTask,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(10) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^10 = 1kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_IndFun =
{
	/*ObjectId						= */ Os_Object_Id_12,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_QMSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_QMSystem),
	/*StackStartAddress				= */ osdOsTask_IndFun_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_IndFun,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_LinFun =
{
	/*ObjectId						= */ Os_Object_Id_13,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_QMSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_QMSystem),
	/*StackStartAddress				= */ osdOsTask_LinFun_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_LinFun,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_Mcal =
{
	/*ObjectId						= */ Os_Object_Id_14,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_QMSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_QMSystem),
	/*StackStartAddress				= */ osdOsTask_Mcal_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_Mcal,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_ModeMgt =
{
	/*ObjectId						= */ Os_Object_Id_15,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_QMSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_QMSystem),
	/*StackStartAddress				= */ osdOsTask_ModeMgt_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_ModeMgt,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(10) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^10 = 1kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_NvmSpeedup =
{
	/*ObjectId						= */ Os_Object_Id_16,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_QMSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_QMSystem),
	/*StackStartAddress				= */ osdOsTask_NvmSpeedup_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_NvmSpeedup,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(10) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^10 = 1kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_SafeApp =
{
	/*ObjectId						= */ Os_Object_Id_17,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdOsTask_SafeApp_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_SafeApp,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_TripFun =
{
	/*ObjectId						= */ Os_Object_Id_18,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_QMSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_QMSystem),
	/*StackStartAddress				= */ osdOsTask_TripFun_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_TripFun,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_WarnFun =
{
	/*ObjectId						= */ Os_Object_Id_19,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_QMSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_QMSystem),
	/*StackStartAddress				= */ osdOsTask_WarnFun_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_WarnFun,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_WdgMngt =
{
	/*ObjectId						= */ Os_Object_Id_20,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdOsTask_WdgMngt_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_WdgMngt,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_Diagnostics =
{
	/*ObjectId						= */ Os_Object_Id_21,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_QMSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_QMSystem),
	/*StackStartAddress				= */ osdOsTask_Diagnostics_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_Diagnostics,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_LSH_16ms =
{
	/*ObjectId						= */ Os_Object_Id_22,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_QMSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_QMSystem),
	/*StackStartAddress				= */ osdOsTask_LSH_16ms_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_LSH_16ms,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_SafeBsw =
{
	/*ObjectId						= */ Os_Object_Id_23,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdOsTask_SafeBsw_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_SafeBsw,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_MemSer =
{
	/*ObjectId						= */ Os_Object_Id_24,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_QMSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_QMSystem),
	/*StackStartAddress				= */ osdOsTask_MemSer_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_MemSer,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(12) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^12 = 4kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_IpcUclEv =
{
	/*ObjectId						= */ Os_Object_Id_25,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_QMSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_QMSystem),
	/*StackStartAddress				= */ osdOsTask_IpcUclEv_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_IpcUclEv,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(12) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^12 = 4kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTaskRender =
{
	/*ObjectId						= */ Os_Object_Id_26,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_QMSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_QMSystem),
	/*StackStartAddress				= */ osdOsTaskRender_BOT,
	/*StackSize						= */ osStackSizeTask_OsTaskRender,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(12) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^12 = 4kB */
};


CONST(OsObjConfigType, OS_CONST) OsObjConfig_McuOsGptIsr =
{
	/*ObjectId						= */ Os_Object_Id_27,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcuOsGptIsr_BOT,
	/*StackSize						= */ osStackSizeIsr_0,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_McuCan0RxTxIsr =
{
	/*ObjectId						= */ Os_Object_Id_28,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcuCan0RxTxIsr_BOT,
	/*StackSize						= */ osStackSizeIsr_1,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_McuCan1RxTxIsr =
{
	/*ObjectId						= */ Os_Object_Id_29,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcuCan1RxTxIsr_BOT,
	/*StackSize						= */ osStackSizeIsr_2,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_McuSpi0NvmRxTxIsr =
{
	/*ObjectId						= */ Os_Object_Id_30,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcuSpi0NvmRxTxIsr_BOT,
	/*StackSize						= */ osStackSizeIsr_3,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_McuDss0Isr =
{
	/*ObjectId						= */ Os_Object_Id_31,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcuDss0Isr_BOT,
	/*StackSize						= */ osStackSizeIsr_4,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_McuI2c3IoIsr =
{
	/*ObjectId						= */ Os_Object_Id_32,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcuI2c3IoIsr_BOT,
	/*StackSize						= */ osStackSizeIsr_5,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Eth_TxIrqHdlr_0 =
{
	/*ObjectId						= */ Os_Object_Id_33,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdEth_TxIrqHdlr_0_BOT,
	/*StackSize						= */ osStackSizeIsr_6,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Eth_RxIrqHdlr_0 =
{
	/*ObjectId						= */ Os_Object_Id_34,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdEth_RxIrqHdlr_0_BOT,
	/*StackSize						= */ osStackSizeIsr_7,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Eth_MdioIrqHdlr =
{
	/*ObjectId						= */ Os_Object_Id_35,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdEth_MdioIrqHdlr_BOT,
	/*StackSize						= */ osStackSizeIsr_8,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_FltM_WkupEsmHiInterrupt =
{
	/*ObjectId						= */ Os_Object_Id_36,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdFltM_WkupEsmHiInterrupt_BOT,
	/*StackSize						= */ osStackSizeIsr_9,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_MCU_IntrISR_UART0 =
{
	/*ObjectId						= */ Os_Object_Id_37,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMCU_IntrISR_UART0_BOT,
	/*StackSize						= */ osStackSizeIsr_10,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_McuI2c0PmicIsr =
{
	/*ObjectId						= */ Os_Object_Id_38,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcuI2c0PmicIsr_BOT,
	/*StackSize						= */ osStackSizeIsr_11,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Gpt_Ch3Isr =
{
	/*ObjectId						= */ Os_Object_Id_39,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdGpt_Ch3Isr_BOT,
	/*StackSize						= */ osStackSizeIsr_12,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Gpt_Ch4Isr =
{
	/*ObjectId						= */ Os_Object_Id_40,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdGpt_Ch4Isr_BOT,
	/*StackSize						= */ osStackSizeIsr_13,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Spi_IrqUnitMcspi2TxRx =
{
	/*ObjectId						= */ Os_Object_Id_41,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdSpi_IrqUnitMcspi2TxRx_BOT,
	/*StackSize						= */ osStackSizeIsr_14,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_MCU_ISR_6 =
{
	/*ObjectId						= */ Os_Object_Id_42,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMCU_ISR_6_BOT,
	/*StackSize						= */ osStackSizeIsr_15,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_MAIN_ISR_34 =
{
	/*ObjectId						= */ Os_Object_Id_43,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMAIN_ISR_34_BOT,
	/*StackSize						= */ osStackSizeIsr_16,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_MAIN_ISR_35 =
{
	/*ObjectId						= */ Os_Object_Id_44,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMAIN_ISR_35_BOT,
	/*StackSize						= */ osStackSizeIsr_17,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_MCU_ISR_7 =
{
	/*ObjectId						= */ Os_Object_Id_45,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMCU_ISR_7_BOT,
	/*StackSize						= */ osStackSizeIsr_18,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_FltM_WkupEsmCfgInterrupt =
{
	/*ObjectId						= */ Os_Object_Id_46,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdFltM_WkupEsmCfgInterrupt_BOT,
	/*StackSize						= */ osStackSizeIsr_19,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_FltM_WkupEsmLowInterrupt =
{
	/*ObjectId						= */ Os_Object_Id_47,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdFltM_WkupEsmLowInterrupt_BOT,
	/*StackSize						= */ osStackSizeIsr_20,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Spi_IrqUnitMcspi0TxRx =
{
	/*ObjectId						= */ Os_Object_Id_48,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdSpi_IrqUnitMcspi0TxRx_BOT,
	/*StackSize						= */ osStackSizeIsr_21,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_MainI2c2RtcIsr =
{
	/*ObjectId						= */ Os_Object_Id_49,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMainI2c2RtcIsr_BOT,
	/*StackSize						= */ osStackSizeIsr_22,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_MCU_ResetIsolationReq =
{
	/*ObjectId						= */ Os_Object_Id_50,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMCU_ResetIsolationReq_BOT,
	/*StackSize						= */ osStackSizeIsr_23,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_FltM_FwlExceptionInterrupt =
{
	/*ObjectId						= */ Os_Object_Id_51,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdFltM_FwlExceptionInterrupt_BOT,
	/*StackSize						= */ osStackSizeIsr_24,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0 =
{
	/*ObjectId						= */ Os_Object_Id_52,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdCdd_IpcIrqMbxFromWKUP_R5FSS0_0_BOT,
	/*StackSize						= */ osStackSizeIsr_25,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr64 =
{
	/*ObjectId						= */ Os_Object_Id_53,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcu_Udma_Vintr64_BOT,
	/*StackSize						= */ osStackSizeIsr_26,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr65 =
{
	/*ObjectId						= */ Os_Object_Id_54,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcu_Udma_Vintr65_BOT,
	/*StackSize						= */ osStackSizeIsr_27,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr66 =
{
	/*ObjectId						= */ Os_Object_Id_55,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcu_Udma_Vintr66_BOT,
	/*StackSize						= */ osStackSizeIsr_28,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr67 =
{
	/*ObjectId						= */ Os_Object_Id_56,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcu_Udma_Vintr67_BOT,
	/*StackSize						= */ osStackSizeIsr_29,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr68 =
{
	/*ObjectId						= */ Os_Object_Id_57,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcu_Udma_Vintr68_BOT,
	/*StackSize						= */ osStackSizeIsr_30,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr69 =
{
	/*ObjectId						= */ Os_Object_Id_58,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcu_Udma_Vintr69_BOT,
	/*StackSize						= */ osStackSizeIsr_31,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr70 =
{
	/*ObjectId						= */ Os_Object_Id_59,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcu_Udma_Vintr70_BOT,
	/*StackSize						= */ osStackSizeIsr_32,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr71 =
{
	/*ObjectId						= */ Os_Object_Id_60,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcu_Udma_Vintr71_BOT,
	/*StackSize						= */ osStackSizeIsr_33,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr72 =
{
	/*ObjectId						= */ Os_Object_Id_61,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcu_Udma_Vintr72_BOT,
	/*StackSize						= */ osStackSizeIsr_34,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr73 =
{
	/*ObjectId						= */ Os_Object_Id_62,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcu_Udma_Vintr73_BOT,
	/*StackSize						= */ osStackSizeIsr_35,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr74 =
{
	/*ObjectId						= */ Os_Object_Id_63,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcu_Udma_Vintr74_BOT,
	/*StackSize						= */ osStackSizeIsr_36,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr75 =
{
	/*ObjectId						= */ Os_Object_Id_64,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcu_Udma_Vintr75_BOT,
	/*StackSize						= */ osStackSizeIsr_37,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr76 =
{
	/*ObjectId						= */ Os_Object_Id_65,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcu_Udma_Vintr76_BOT,
	/*StackSize						= */ osStackSizeIsr_38,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr77 =
{
	/*ObjectId						= */ Os_Object_Id_66,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcu_Udma_Vintr77_BOT,
	/*StackSize						= */ osStackSizeIsr_39,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr78 =
{
	/*ObjectId						= */ Os_Object_Id_67,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcu_Udma_Vintr78_BOT,
	/*StackSize						= */ osStackSizeIsr_40,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr79 =
{
	/*ObjectId						= */ Os_Object_Id_68,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcu_Udma_Vintr79_BOT,
	/*StackSize						= */ osStackSizeIsr_41,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_MainI2c1DacIsr =
{
	/*ObjectId						= */ Os_Object_Id_69,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMainI2c1DacIsr_BOT,
	/*StackSize						= */ osStackSizeIsr_42,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};


CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsKernel_OsCoreAsr0 =
{
	/*ObjectId						= */ Os_Object_Id_70,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_KERNEL,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdSystemStack_BOT,
	/*StackSize						= */ 0x1000U,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_ALLOWED | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(12) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^12 = 4kB */
};

//OsApplication_0 -- OS_CFG_OSAPPLICATION_TRUSTEDSYSTEM Objects
CONST (OsObjConfigRefType, OS_CONST) OsApplication_TrustedSystemObjConfigRef[48] =  {
	(OsObjConfigRefType)(&OsObjConfig_OsTask_SafeApp),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_WdgMngt),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_SafeBsw),
	(OsObjConfigRefType)(&OsObjConfig_InitTask),
	(OsObjConfigRefType)(&OsObjConfig_McuOsGptIsr),
	(OsObjConfigRefType)(&OsObjConfig_McuCan0RxTxIsr),
	(OsObjConfigRefType)(&OsObjConfig_McuCan1RxTxIsr),
	(OsObjConfigRefType)(&OsObjConfig_McuSpi0NvmRxTxIsr),
	(OsObjConfigRefType)(&OsObjConfig_McuDss0Isr),
	(OsObjConfigRefType)(&OsObjConfig_McuI2c3IoIsr),
	(OsObjConfigRefType)(&OsObjConfig_Eth_TxIrqHdlr_0),
	(OsObjConfigRefType)(&OsObjConfig_Eth_RxIrqHdlr_0),
	(OsObjConfigRefType)(&OsObjConfig_Eth_MdioIrqHdlr),
	(OsObjConfigRefType)(&OsObjConfig_FltM_WkupEsmHiInterrupt),
	(OsObjConfigRefType)(&OsObjConfig_MCU_IntrISR_UART0),
	(OsObjConfigRefType)(&OsObjConfig_McuI2c0PmicIsr),
	(OsObjConfigRefType)(&OsObjConfig_Gpt_Ch3Isr),
	(OsObjConfigRefType)(&OsObjConfig_Gpt_Ch4Isr),
	(OsObjConfigRefType)(&OsObjConfig_Spi_IrqUnitMcspi2TxRx),
	(OsObjConfigRefType)(&OsObjConfig_MCU_ISR_6),
	(OsObjConfigRefType)(&OsObjConfig_MAIN_ISR_34),
	(OsObjConfigRefType)(&OsObjConfig_MAIN_ISR_35),
	(OsObjConfigRefType)(&OsObjConfig_MCU_ISR_7),
	(OsObjConfigRefType)(&OsObjConfig_FltM_WkupEsmCfgInterrupt),
	(OsObjConfigRefType)(&OsObjConfig_FltM_WkupEsmLowInterrupt),
	(OsObjConfigRefType)(&OsObjConfig_Spi_IrqUnitMcspi0TxRx),
	(OsObjConfigRefType)(&OsObjConfig_MainI2c2RtcIsr),
	(OsObjConfigRefType)(&OsObjConfig_MCU_ResetIsolationReq),
	(OsObjConfigRefType)(&OsObjConfig_FltM_FwlExceptionInterrupt),
	(OsObjConfigRefType)(&OsObjConfig_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0),
	(OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr64),
	(OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr65),
	(OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr66),
	(OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr67),
	(OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr68),
	(OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr69),
	(OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr70),
	(OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr71),
	(OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr72),
	(OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr73),
	(OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr74),
	(OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr75),
	(OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr76),
	(OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr77),
	(OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr78),
	(OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr79),
	(OsObjConfigRefType)(&OsObjConfig_MainI2c1DacIsr),
	(OsObjConfigRefType)(&OsObjConfig_OsKernel_OsCoreAsr0)
};


//OsApplication_1 -- OS_CFG_OSAPPLICATION_QMSYSTEM Objects
CONST (OsObjConfigRefType, OS_CONST) OsApplication_QMSystemObjConfigRef[23] =  {
	(OsObjConfigRefType)(&OsObjConfig_OsTask_AppFun),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_AudioFun),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_Can0DataRxEv),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_Can1DataRxEv),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_CANFun),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_DispFun),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_EthFun),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_FotaEv),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_FotaFun),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_GaugeFun),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_IdleTask),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_IndFun),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_LinFun),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_Mcal),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_ModeMgt),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_NvmSpeedup),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_TripFun),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_WarnFun),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_Diagnostics),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_LSH_16ms),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_MemSer),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_IpcUclEv),
	(OsObjConfigRefType)(&OsObjConfig_OsTaskRender)
};



const OsObjConfigRefType OsObjRefConfig[OsMaxNumOfObjectId] = {
	(OsObjConfigRefType)&OsObjConfig_InitTask,
	(OsObjConfigRefType)&OsObjConfig_OsTask_AppFun,
	(OsObjConfigRefType)&OsObjConfig_OsTask_AudioFun,
	(OsObjConfigRefType)&OsObjConfig_OsTask_Can0DataRxEv,
	(OsObjConfigRefType)&OsObjConfig_OsTask_Can1DataRxEv,
	(OsObjConfigRefType)&OsObjConfig_OsTask_CANFun,
	(OsObjConfigRefType)&OsObjConfig_OsTask_DispFun,
	(OsObjConfigRefType)&OsObjConfig_OsTask_EthFun,
	(OsObjConfigRefType)&OsObjConfig_OsTask_FotaEv,
	(OsObjConfigRefType)&OsObjConfig_OsTask_FotaFun,
	(OsObjConfigRefType)&OsObjConfig_OsTask_GaugeFun,
	(OsObjConfigRefType)&OsObjConfig_OsTask_IdleTask,
	(OsObjConfigRefType)&OsObjConfig_OsTask_IndFun,
	(OsObjConfigRefType)&OsObjConfig_OsTask_LinFun,
	(OsObjConfigRefType)&OsObjConfig_OsTask_Mcal,
	(OsObjConfigRefType)&OsObjConfig_OsTask_ModeMgt,
	(OsObjConfigRefType)&OsObjConfig_OsTask_NvmSpeedup,
	(OsObjConfigRefType)&OsObjConfig_OsTask_SafeApp,
	(OsObjConfigRefType)&OsObjConfig_OsTask_TripFun,
	(OsObjConfigRefType)&OsObjConfig_OsTask_WarnFun,
	(OsObjConfigRefType)&OsObjConfig_OsTask_WdgMngt,
	(OsObjConfigRefType)&OsObjConfig_OsTask_Diagnostics,
	(OsObjConfigRefType)&OsObjConfig_OsTask_LSH_16ms,
	(OsObjConfigRefType)&OsObjConfig_OsTask_SafeBsw,
	(OsObjConfigRefType)&OsObjConfig_OsTask_MemSer,
	(OsObjConfigRefType)&OsObjConfig_OsTask_IpcUclEv,
	(OsObjConfigRefType)&OsObjConfig_OsTaskRender,
	(OsObjConfigRefType)&OsObjConfig_McuOsGptIsr,
	(OsObjConfigRefType)&OsObjConfig_McuCan0RxTxIsr,
	(OsObjConfigRefType)&OsObjConfig_McuCan1RxTxIsr,
	(OsObjConfigRefType)&OsObjConfig_McuSpi0NvmRxTxIsr,
	(OsObjConfigRefType)&OsObjConfig_McuDss0Isr,
	(OsObjConfigRefType)&OsObjConfig_McuI2c3IoIsr,
	(OsObjConfigRefType)&OsObjConfig_Eth_TxIrqHdlr_0,
	(OsObjConfigRefType)&OsObjConfig_Eth_RxIrqHdlr_0,
	(OsObjConfigRefType)&OsObjConfig_Eth_MdioIrqHdlr,
	(OsObjConfigRefType)&OsObjConfig_FltM_WkupEsmHiInterrupt,
	(OsObjConfigRefType)&OsObjConfig_MCU_IntrISR_UART0,
	(OsObjConfigRefType)&OsObjConfig_McuI2c0PmicIsr,
	(OsObjConfigRefType)&OsObjConfig_Gpt_Ch3Isr,
	(OsObjConfigRefType)&OsObjConfig_Gpt_Ch4Isr,
	(OsObjConfigRefType)&OsObjConfig_Spi_IrqUnitMcspi2TxRx,
	(OsObjConfigRefType)&OsObjConfig_MCU_ISR_6,
	(OsObjConfigRefType)&OsObjConfig_MAIN_ISR_34,
	(OsObjConfigRefType)&OsObjConfig_MAIN_ISR_35,
	(OsObjConfigRefType)&OsObjConfig_MCU_ISR_7,
	(OsObjConfigRefType)&OsObjConfig_FltM_WkupEsmCfgInterrupt,
	(OsObjConfigRefType)&OsObjConfig_FltM_WkupEsmLowInterrupt,
	(OsObjConfigRefType)&OsObjConfig_Spi_IrqUnitMcspi0TxRx,
	(OsObjConfigRefType)&OsObjConfig_MainI2c2RtcIsr,
	(OsObjConfigRefType)&OsObjConfig_MCU_ResetIsolationReq,
	(OsObjConfigRefType)&OsObjConfig_FltM_FwlExceptionInterrupt,
	(OsObjConfigRefType)&OsObjConfig_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0,
	(OsObjConfigRefType)&OsObjConfig_Mcu_Udma_Vintr64,
	(OsObjConfigRefType)&OsObjConfig_Mcu_Udma_Vintr65,
	(OsObjConfigRefType)&OsObjConfig_Mcu_Udma_Vintr66,
	(OsObjConfigRefType)&OsObjConfig_Mcu_Udma_Vintr67,
	(OsObjConfigRefType)&OsObjConfig_Mcu_Udma_Vintr68,
	(OsObjConfigRefType)&OsObjConfig_Mcu_Udma_Vintr69,
	(OsObjConfigRefType)&OsObjConfig_Mcu_Udma_Vintr70,
	(OsObjConfigRefType)&OsObjConfig_Mcu_Udma_Vintr71,
	(OsObjConfigRefType)&OsObjConfig_Mcu_Udma_Vintr72,
	(OsObjConfigRefType)&OsObjConfig_Mcu_Udma_Vintr73,
	(OsObjConfigRefType)&OsObjConfig_Mcu_Udma_Vintr74,
	(OsObjConfigRefType)&OsObjConfig_Mcu_Udma_Vintr75,
	(OsObjConfigRefType)&OsObjConfig_Mcu_Udma_Vintr76,
	(OsObjConfigRefType)&OsObjConfig_Mcu_Udma_Vintr77,
	(OsObjConfigRefType)&OsObjConfig_Mcu_Udma_Vintr78,
	(OsObjConfigRefType)&OsObjConfig_Mcu_Udma_Vintr79,
	(OsObjConfigRefType)&OsObjConfig_MainI2c1DacIsr,
	(OsObjConfigRefType)(&OsObjConfig_OsKernel_OsCoreAsr0)
};

OsAppConfigRefType OsAppRefListDyn[OsNumberOfApplications] = {
	(OsAppConfigRefType)(&OsAppConfig_TrustedSystem),
	(OsAppConfigRefType)(&OsAppConfig_QMSystem)
};



#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

