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
*    Auto generated code in vAUTOSAR TOOL by MNATRAMI at 2026-04-06 16:31:56.335514900
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
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(9) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^9 = 1kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_Ucl =
{
	/*ObjectId						= */ Os_Object_Id_1,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdOsTask_Ucl_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_Ucl,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_Diagnostics =
{
	/*ObjectId						= */ Os_Object_Id_2,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdOsTask_Diagnostics_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_Diagnostics,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_CANFun =
{
	/*ObjectId						= */ Os_Object_Id_3,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdOsTask_CANFun_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_CANFun,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_WdgMngt =
{
	/*ObjectId						= */ Os_Object_Id_4,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdOsTask_WdgMngt_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_WdgMngt,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_IdleTask =
{
	/*ObjectId						= */ Os_Object_Id_5,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_TASK,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*) &(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdOsTask_IdleTask_BOT,
	/*StackSize						= */ osStackSizeTask_OsTask_IdleTask,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(10) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^10 = 1kB */
};


CONST(OsObjConfigType, OS_CONST) OsObjConfig_McuOsGptIsr =
{
	/*ObjectId						= */ Os_Object_Id_6,
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
	/*ObjectId						= */ Os_Object_Id_7,
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
	/*ObjectId						= */ Os_Object_Id_8,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcuCan1RxTxIsr_BOT,
	/*StackSize						= */ osStackSizeIsr_2,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_McuI2c3IoIsr =
{
	/*ObjectId						= */ Os_Object_Id_9,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcuI2c3IoIsr_BOT,
	/*StackSize						= */ osStackSizeIsr_3,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_McuI2c0PmicIsr =
{
	/*ObjectId						= */ Os_Object_Id_10,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdMcuI2c0PmicIsr_BOT,
	/*StackSize						= */ osStackSizeIsr_4,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Gpt_Ch3Isr =
{
	/*ObjectId						= */ Os_Object_Id_11,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdGpt_Ch3Isr_BOT,
	/*StackSize						= */ osStackSizeIsr_5,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Gpt_Ch4Isr =
{
	/*ObjectId						= */ Os_Object_Id_12,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdGpt_Ch4Isr_BOT,
	/*StackSize						= */ osStackSizeIsr_6,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_PmicCdd_nINTGpioInterrupt =
{
	/*ObjectId						= */ Os_Object_Id_13,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdPmicCdd_nINTGpioInterrupt_BOT,
	/*StackSize						= */ osStackSizeIsr_7,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};

CONST(OsObjConfigType, OS_CONST) OsObjConfig_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0 =
{
	/*ObjectId						= */ Os_Object_Id_14,
	/*CoreId						= */ OS_CFG_CORE_CORE_0,
	/*ObjectType					= */ OS_OBJECT_ISR,
	/*AccessRightsIdType			= */ OS_CFG_MPU_REGION_OsMpu_TrustedSystem,
	/*pAppRef						= */ (OsAppConfigType*)&(OsAppConfig_TrustedSystem),
	/*StackStartAddress				= */ osdCdd_IpcIrqMbxFromWKUP_R5FSS0_0_BOT,
	/*StackSize						= */ osStackSizeIsr_8,
	/*StackRegAttribute				= */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/*StackSizeAndEnable			= */ OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(11) | OS_INT_MPU_REGION_SIZE_ENABLE /* 2^11 = 2kB */
};


CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsKernel_OsCoreAsr0 =
{
	/*ObjectId						= */ Os_Object_Id_15,
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
CONST (OsObjConfigRefType, OS_CONST) OsApplication_TrustedSystemObjConfigRef[16] =  {
	(OsObjConfigRefType)(&OsObjConfig_OsTask_CANFun),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_IdleTask),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_Diagnostics),
	(OsObjConfigRefType)(&OsObjConfig_InitTask),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_Ucl),
	(OsObjConfigRefType)(&OsObjConfig_OsTask_WdgMngt),
	(OsObjConfigRefType)(&OsObjConfig_McuOsGptIsr),
	(OsObjConfigRefType)(&OsObjConfig_McuCan0RxTxIsr),
	(OsObjConfigRefType)(&OsObjConfig_McuCan1RxTxIsr),
	(OsObjConfigRefType)(&OsObjConfig_McuI2c3IoIsr),
	(OsObjConfigRefType)(&OsObjConfig_McuI2c0PmicIsr),
	(OsObjConfigRefType)(&OsObjConfig_Gpt_Ch3Isr),
	(OsObjConfigRefType)(&OsObjConfig_Gpt_Ch4Isr),
	(OsObjConfigRefType)(&OsObjConfig_PmicCdd_nINTGpioInterrupt),
	(OsObjConfigRefType)(&OsObjConfig_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0),
	(OsObjConfigRefType)(&OsObjConfig_OsKernel_OsCoreAsr0)
};



const OsObjConfigRefType OsObjRefConfig[OsMaxNumOfObjectId] = {
	(OsObjConfigRefType)&OsObjConfig_InitTask,
	(OsObjConfigRefType)&OsObjConfig_OsTask_Ucl,
	(OsObjConfigRefType)&OsObjConfig_OsTask_Diagnostics,
	(OsObjConfigRefType)&OsObjConfig_OsTask_CANFun,
	(OsObjConfigRefType)&OsObjConfig_OsTask_WdgMngt,
	(OsObjConfigRefType)&OsObjConfig_OsTask_IdleTask,
	(OsObjConfigRefType)&OsObjConfig_McuOsGptIsr,
	(OsObjConfigRefType)&OsObjConfig_McuCan0RxTxIsr,
	(OsObjConfigRefType)&OsObjConfig_McuCan1RxTxIsr,
	(OsObjConfigRefType)&OsObjConfig_McuI2c3IoIsr,
	(OsObjConfigRefType)&OsObjConfig_McuI2c0PmicIsr,
	(OsObjConfigRefType)&OsObjConfig_Gpt_Ch3Isr,
	(OsObjConfigRefType)&OsObjConfig_Gpt_Ch4Isr,
	(OsObjConfigRefType)&OsObjConfig_PmicCdd_nINTGpioInterrupt,
	(OsObjConfigRefType)&OsObjConfig_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0,
	(OsObjConfigRefType)(&OsObjConfig_OsKernel_OsCoreAsr0)
};

OsAppConfigRefType OsAppRefListDyn[OsNumberOfApplications] = {
	(OsAppConfigRefType)(&OsAppConfig_TrustedSystem)
};



#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

