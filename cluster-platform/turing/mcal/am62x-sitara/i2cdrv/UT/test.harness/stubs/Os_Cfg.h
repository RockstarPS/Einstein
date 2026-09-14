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

File Name        :  Os_Cfg.h
Module Short Name:  Os_Cfg.h
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef OS_CFG_H
#define OS_CFG_H


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/
                                                                              
#include "OsMain.h"
#include "Os_TrustedServiceCfg.h"
#include "Os_ResourceCfg.h"


                                                                              
                                                                              
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
*****************************************************************************/

#define OS_CFG_OS_STATUS               OS_STATUS_EXTENDED

#define MOS_VERSION_INFO_API           STD_ON

#define MOS_USE_SCHED_LOG              STD_OFF

#define OS_TESTING_LOCAL               STD_OFF



/******** OS Hook Routines are Enabled *************************************/
#define OS_CFG_SUPPORT_DBG_HOOKS
#define OS_ENABLE_OSAPI_ERR_HOOK

#define OS_API_ERROR_HOOK(x,y)          //pouplate user defined error hook here


/******** OS MemMap are Enabled *******************************/
#define OS_CFG_MEMMAP_ENABLED


/* OS SC3 Functionalities is STD_ON or STD_OFF */
#define OS_CFG_MEMORY_PROTECTION     STD_OFF

#define OS_CFG_MPU_SWITCH_APP        STD_OFF

#define OS_CFG_MPU_SWITCH_OBJ        STD_OFF


#define OsNumberOfCores             1U
#define OsNumberOfApplications      3U
#define OsNumberOfTrustedFns        0U
#define OsMaxAccessGroupIds         0U


/* CoreId Type */
#define OS_CFG_CORE_CORE_0        OsCoreAsr0
#define OsCoreAsr0             0UL
#define OS_CFG_CORE_COREINVALID               1UL


/* Application Type  */
#define OS_CFG_OSAPPLICATION_TRUSTEDSYSTEM            0UL
#define OS_CFG_OSAPPLICATION_QM            1UL
#define OS_CFG_OSAPPLICATION_SECUREDSYSTEM            2UL
#define OS_CFG_APPLICATION_INVALID      0xFFU


/* AccessRightsIdType */
#define OS_CFG_MPU_REGION_INVALID       0xFFFFFFFFU


#define OS_CFG_MPU_STACK_REGION_NUM     0U


/* Num of applications in core */
#define OsNumberOfApplicationsCore0        3


/* OsApp count accessing given resource */
#define OsNumberOfApplicationsSchedRes0    3


#define OsNumberOfTasks              5U
#define OsNumberOfAlarms             3U
#define OsMaxPriorityLevel           5U
#define OsNumberOfAutoStartTasks     2
#define osMaxCounterId               2U
#define OsNumberOfIsr                6U
#define OsMaxNumOfObjectId           (OsNumberOfTasks + OsNumberOfIsr)
#define OsNumberOfRes                1U


/* Resource IDs */


#define OsCounter_0                         ((CounterType) 0)
#define OsCounter_1                         ((CounterType) 1)


#define CC_TYPE                      ECC1
#define OS_MS2TICKS_SystemTimer(x)     ( (TickType) (((((uint32)(x)) * 1) + 0) / 1) )


/*****************************************************************************
*                        Task Ids                                            *
*****************************************************************************/
#define InitTask                  ((TaskType)0)
#define OsTask_MemSer                  ((TaskType)1)
#define TaskName_1                  ((TaskType)2)
#define TaskName_2                  ((TaskType)3)
#define IdleTask                  ((TaskType)4)


/* Object Names */
/* Task Object Names */
#define Object_InitTask            ((ObjectIdType)0)
#define Object_OsTask_MemSer            ((ObjectIdType)1)
#define Object_TaskName_1            ((ObjectIdType)2)
#define Object_TaskName_2            ((ObjectIdType)3)
#define Object_IdleTask            ((ObjectIdType)4)


/* Isr Object Names */
#define Object_OsIsr_SystemTimer            ((ObjectIdType)5)
#define Object_Can_0_Int0ISR            ((ObjectIdType)6)
#define Object_Can_1_Int0ISR            ((ObjectIdType)7)
#define Object_Cdd_IpcIrqMbxFromA53SS_0_0            ((ObjectIdType)8)
#define Object_Spi_IrqUnitMcuMcspi0TxRx            ((ObjectIdType)9)
#define Object_McuI2c_InterruptHandler            ((ObjectIdType)10)
#define Object_ObjectIdMax        ((ObjectIdType)11)


/* Object Ids */
#define Os_Object_Id_0          Object_InitTask
#define Os_Object_Id_1          Object_OsTask_MemSer
#define Os_Object_Id_2          Object_TaskName_1
#define Os_Object_Id_3          Object_TaskName_2
#define Os_Object_Id_4          Object_IdleTask
#define Os_Object_Id_5          Object_OsIsr_SystemTimer
#define Os_Object_Id_6          Object_Can_0_Int0ISR
#define Os_Object_Id_7          Object_Can_1_Int0ISR
#define Os_Object_Id_8          Object_Cdd_IpcIrqMbxFromA53SS_0_0
#define Os_Object_Id_9          Object_Spi_IrqUnitMcuMcspi0TxRx
#define Os_Object_Id_10          Object_McuI2c_InterruptHandler


/* Alarms */

#define Rte_Al_TE2_AppTask_10msLP_0_10ms (0U)
#define Rte_Al_TE2_AppTask_10msLP_0_20ms (1U)
#define Rte_Al_TE2_MemSer_10msLP_0_10ms (2U)


/* Events */

#define Rte_Ev_Cyclic2_AppTask_10msLP_0_10ms     ((EventMaskType)1ULL)
#define Rte_Ev_Cyclic2_AppTask_10msLP_0_20ms     ((EventMaskType)2ULL)
#define Rte_Ev_Cyclic2_OsTask_BSW_0_10ms     ((EventMaskType)4ULL)
#define Rte_Ev_Cyclic_AppTask_10msLP_0_10ms     ((EventMaskType)8ULL)
#define Rte_Ev_Cyclic_MemSer_10msLP_0_10ms   ((EventMaskType)16ULL)


/* Schedule Tables */
#define MainScheduleTable_OsTask_NvM_Stack (0U)
/*****************************************************************************
*                           Auto Start Task Ids                              *
******************************************************************************/
#define OsTaskAutoStart_0                InitTask
#define OsTaskAutoStart_1                IdleTask


/*****************************************************************************
*                                  Task Table                                *
******************************************************************************/


/********************* Task 0*********************/

#define osStartAddressTask_0                (osTaskFuncRefType)&InitTaskfunc
#define osStackStartAddressTask_0           (osStackPtrType)osdInitTask_TOP
#define osStackSizeTask_0                   sizeof(osTaskStackOsApplication0)
#define osPrioTask_0                        1
#define osMaxActivationCount_0              3
#define osCategoryTask_0                    TASK_NONPREEMPTIVE
#define osTypeTask_0                        TASK_BASIC


/********************* Task 1*********************/

#define osStartAddressTask_1                (osTaskFuncRefType)&OsTask_MemSerfunc
#define osStackStartAddressTask_1           (osStackPtrType)osdOsTask_MemSer_TOP
#define osStackSizeTask_1                   sizeof(osTaskStackOsApplication1)
#define osPrioTask_1                        0
#define osMaxActivationCount_1              1
#define osCategoryTask_1                    TASK_NONPREEMPTIVE
#define osTypeTask_1                        TASK_EXTENDED


/********************* Task 2*********************/

#define osStartAddressTask_2                (osTaskFuncRefType)&TaskName_1func
#define osStackStartAddressTask_2           (osStackPtrType)osdTaskName_1_TOP
#define osStackSizeTask_2                   sizeof(osTaskStackOsApplication2)
#define osPrioTask_2                        2
#define osMaxActivationCount_2              1
#define osCategoryTask_2                    TASK_NONPREEMPTIVE
#define osTypeTask_2                        TASK_EXTENDED


/********************* Task 3*********************/

#define osStartAddressTask_3                (osTaskFuncRefType)&TaskName_2func
#define osStackStartAddressTask_3           (osStackPtrType)osdTaskName_2_TOP
#define osStackSizeTask_3                   sizeof(osTaskStackOsApplication3)
#define osPrioTask_3                        3
#define osMaxActivationCount_3              1
#define osCategoryTask_3                    TASK_NONPREEMPTIVE
#define osTypeTask_3                        TASK_BASIC


/********************* Task 4*********************/

#define osStartAddressTask_4                (osTaskFuncRefType)&IdleTaskfunc
#define osStackStartAddressTask_4           (osStackPtrType)osdIdleTask_TOP
#define osStackSizeTask_4                   sizeof(osTaskStackOsApplication4)
#define osPrioTask_4                        4
#define osMaxActivationCount_4              1
#define osCategoryTask_4                    TASK_PREEMPTIVE
#define osTypeTask_4                        TASK_EXTENDED


/*****************************************************************************
*                                 Alarm Table                                *
******************************************************************************/


/********************** Alarm 0 ***********************/
#define osCbkOfAlarm_0                    NULL
#define osTaskIdOfAlarm_0                 TaskName_1
#define osActionOfAlarm_0                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_0                Rte_Ev_Cyclic2_AppTask_10msLP_0_10ms
/********************** Alarm 1 ***********************/
#define osCbkOfAlarm_1                    NULL
#define osTaskIdOfAlarm_1                 TaskName_2
#define osActionOfAlarm_1                 ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_1                0
/********************** Alarm 2 ***********************/
#define osCbkOfAlarm_2                    NULL
#define osTaskIdOfAlarm_2                 OsTask_MemSer
#define osActionOfAlarm_2                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_2                Rte_Ev_Cyclic_MemSer_10msLP_0_10ms


/*****************************************************************************
*                               Isr Stack Table                              *
******************************************************************************/


#define osStackStartAddressIsr_0           (osStackPtrType)osdOsIsr_SystemTimer_TOP
#define osStackSizeIsr_0                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_1           (osStackPtrType)osdCan_0_Int0ISR_TOP
#define osStackSizeIsr_1                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_2           (osStackPtrType)osdCan_1_Int0ISR_TOP
#define osStackSizeIsr_2                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_3           (osStackPtrType)osdCdd_IpcIrqMbxFromA53SS_0_0_TOP
#define osStackSizeIsr_3                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_4           (osStackPtrType)osdSpi_IrqUnitMcuMcspi0TxRx_TOP
#define osStackSizeIsr_4                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_5           (osStackPtrType)osdMcuI2c_InterruptHandler_TOP
#define osStackSizeIsr_5                   (osStackDataType)sizeof(osLevelStackCore0Level2)



/*****************************************************************************
*                               Isr Configs                                  *
******************************************************************************/
/********************** Isr 0***********************/
#define osIsrId_OsIsr_SystemTimer 0UL
#define osIsrPrioLevel_OsIsr_SystemTimer 2UL
#define osIsrServiceRoutine_OsIsr_SystemTimer osTimerInterruptfunc

/********************** Isr 1***********************/
#define osIsrId_Can_0_Int0ISR 1UL
#define osIsrPrioLevel_Can_0_Int0ISR 3UL
#define osIsrServiceRoutine_Can_0_Int0ISR Can_0_Int0ISRfunc

/********************** Isr 2***********************/
#define osIsrId_Can_1_Int0ISR 2UL
#define osIsrPrioLevel_Can_1_Int0ISR 4UL
#define osIsrServiceRoutine_Can_1_Int0ISR Can_1_Int0ISRfunc

/********************** Isr 3***********************/
#define osIsrId_Cdd_IpcIrqMbxFromA53SS_0_0 3UL
#define osIsrPrioLevel_Cdd_IpcIrqMbxFromA53SS_0_0 5UL
#define osIsrServiceRoutine_Cdd_IpcIrqMbxFromA53SS_0_0 Cdd_IpcIrqMbxFromA53SS_0_0func

/********************** Isr 4***********************/
#define osIsrId_Spi_IrqUnitMcuMcspi0TxRx 4UL
#define osIsrPrioLevel_Spi_IrqUnitMcuMcspi0TxRx 6UL
#define osIsrServiceRoutine_Spi_IrqUnitMcuMcspi0TxRx Spi_IrqUnitMcuMcspi0TxRxfunc

/********************** Isr 5***********************/
#define osIsrId_McuI2c_InterruptHandler 5UL
#define osIsrPrioLevel_McuI2c_InterruptHandler 7UL
#define osIsrServiceRoutine_McuI2c_InterruptHandler McuI2c_InterruptHandlerfunc



/* Task function prototypes */

void InitTaskfunc(void);
void OsTask_MemSerfunc(void);
void TaskName_1func(void);
void TaskName_2func(void);
void IdleTaskfunc(void);
/* Alarm Callback function prototypes */

extern const OsAppConfigType OsAppConfig[OsNumberOfApplications];
extern const OsAppConfigRefType OsCore0ApplicationRef[OsNumberOfApplicationsCore0];
extern const OsCoreConfigType OsCoreConfig[OsNumberOfCores];
extern const OsObjConfigType  OsObjConfig[OsMaxNumOfObjectId];
extern const OsObjConfigRefType OsApplication_TrustedSystemObjConfigRef[];
extern const OsObjConfigRefType OsApplication_QMObjConfigRef[];
extern const OsObjConfigRefType OsApplication_SecuredSystemObjConfigRef[];
#if(OS_CFG_MEMORY_PROTECTION == STD_ON)
extern const OsTrustedCallConfigType OsCfgTrustedCallConfig[OsNumberOfTrustedFns];
#endif
extern const OsMPUAccessGroupConfigType OsMPUAccessGroupConfig[OsMaxAccessGroupIds];
extern const OsMpuAccessGroupDiffType OsMpuAccessGroupDiff[OsMaxAccessGroupIds][OsMaxAccessGroupIds];
extern OsprioQueueType OsPriorityQueueDyn[OsMaxPriorityLevel];
extern const OsResConfigType OsResConfig[OsNumberOfRes];
extern const TaskPriorityType OsMaxPrioQueueCount[OsMaxPriorityLevel];

extern OsAppConfigRefType OsAppRefListDyn[OsNumberOfApplicationsCore0];



/************* OsMessage Configurations ******************************/
#define OsNumberOfTotalMessageQueues         0  /* 1,2,3,4,6 */
#define OsNumberOfRxMessages                 0  /* 0 to 6 */
#define OsNumberOfTxMessages                 0  /* 0,1,2,3,4 */
#define OsNumberOfMsgFlagNotifications       0 /* 0 */
#define OsNumberOfMsgCallbackNotifications   0 /* 2,5 */

#define OsComStartComExtension         1 /* 0 - Standard; 1 - Extended */

#if (OsNumberOfTxMessages>0)
#define osStartCOMExtension() E_OK

#if OsNumberOfMsgFlagNotifications
extern osuint8 osMsgFlags[OsNumberOfMsgFlagNotifications];
#endif
/* DataBuffer[Queue][DataLength] */
extern osuint8  OsMsgDataBuffer0[1][2];
extern osuint8  OsMsgDataBuffer1[2][2];
extern osuint8  OsMsgDataBuffer2[5][1];
extern osuint8  OsMsgDataBuffer3[5][1];
extern osuint8  OsMsgDataBuffer4[5][1];
extern osuint8  OsMsgDataBuffer5[1][2];
extern osuint8  OsMsgDataBuffer6[1][2];

extern osuint8 ReadFlag_Flag0(void);
extern void ClearFlag_Flag0(void);
#endif //OsNumberOfTxMessages

#endif    /* */
/* end of file */
/****************************************************************
Created Time: 2/19/2024 9:51:31 AM
****************************************************************/
