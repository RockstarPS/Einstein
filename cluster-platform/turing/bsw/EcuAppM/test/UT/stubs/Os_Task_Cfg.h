/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2025 by Visteon Corporation.       All rights reserved.         
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
*    @file Os_Task_Cfg.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by BJAYARA3 at 2025-12-12 17:15:15.717468700
********************************************************************************************************************/

#ifndef OS_TASK_CFG_H
#define OS_TASK_CFG_H


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/


                                                                              
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
*****************************************************************************/


#define OsNumberOfTasks                                   16U

/*****************************************************************************
*                        Task Ids                                            *
*****************************************************************************/
#define OsTask_BSW_COM_Periodic_2                         ((TaskType)0)
#define osTaskID_OsTask_BSW_COM_Periodic_2               ((TaskType)0)

#define OsTask_BSW_EventPeriodic_0                        ((TaskType)1)
#define osTaskID_OsTask_BSW_EventPeriodic_0              ((TaskType)1)

#define Init_Task                                         ((TaskType)2)
#define osTaskID_Init_Task                               ((TaskType)2)

#define IdleTask_OsCore_Core0                             ((TaskType)3)
#define osTaskID_IdleTask_OsCore_Core0                   ((TaskType)3)

#define OsTask_BSW_Periodic_0                             ((TaskType)4)
#define osTaskID_OsTask_BSW_Periodic_0                   ((TaskType)4)

#define OsTask_BSW_Periodic_1                             ((TaskType)5)
#define osTaskID_OsTask_BSW_Periodic_1                   ((TaskType)5)

#define OsTask_CAN_Periodic_0                             ((TaskType)6)
#define osTaskID_OsTask_CAN_Periodic_0                   ((TaskType)6)

#define OsTask_CDD_FitPeriodic_1                          ((TaskType)7)
#define osTaskID_OsTask_CDD_FitPeriodic_1                ((TaskType)7)

#define OsTask_CDD_Periodic_0                             ((TaskType)8)
#define osTaskID_OsTask_CDD_Periodic_0                   ((TaskType)8)

#define OsTask_COM_EventPeriodic_0                        ((TaskType)9)
#define osTaskID_OsTask_COM_EventPeriodic_0              ((TaskType)9)

#define OsTask_CanDataRx_0                                ((TaskType)10)
#define osTaskID_OsTask_CanDataRx_0                      ((TaskType)10)

#define OsTask_NvmSpeedup                                 ((TaskType)11)
#define osTaskID_OsTask_NvmSpeedup                       ((TaskType)11)

#define OsTask_SafeBsw_0                                  ((TaskType)12)
#define osTaskID_OsTask_SafeBsw_0                        ((TaskType)12)

#define OsTask_SafeBsw_1                                  ((TaskType)13)
#define osTaskID_OsTask_SafeBsw_1                        ((TaskType)13)

#define OsTask_LSH_16ms                                   ((TaskType)14)
#define osTaskID_OsTask_LSH_16ms                         ((TaskType)14)

#define OsTaskRender                                      ((TaskType)15)
#define osTaskID_OsTaskRender                            ((TaskType)15)



/* Object Names */
/* Task Object Names */
#define Object_OsTask_BSW_COM_Periodic_2                    ((ObjectIdType)0)
#define Object_OsTask_BSW_EventPeriodic_0                   ((ObjectIdType)1)
#define Object_Init_Task                                    ((ObjectIdType)2)
#define Object_IdleTask_OsCore_Core0                        ((ObjectIdType)3)
#define Object_OsTask_BSW_Periodic_0                        ((ObjectIdType)4)
#define Object_OsTask_BSW_Periodic_1                        ((ObjectIdType)5)
#define Object_OsTask_CAN_Periodic_0                        ((ObjectIdType)6)
#define Object_OsTask_CDD_FitPeriodic_1                     ((ObjectIdType)7)
#define Object_OsTask_CDD_Periodic_0                        ((ObjectIdType)8)
#define Object_OsTask_COM_EventPeriodic_0                   ((ObjectIdType)9)
#define Object_OsTask_CanDataRx_0                           ((ObjectIdType)10)
#define Object_OsTask_NvmSpeedup                            ((ObjectIdType)11)
#define Object_OsTask_SafeBsw_0                             ((ObjectIdType)12)
#define Object_OsTask_SafeBsw_1                             ((ObjectIdType)13)
#define Object_OsTask_LSH_16ms                              ((ObjectIdType)14)
#define Object_OsTaskRender                                 ((ObjectIdType)15)

/* Isr Object Names */
#define Object_SystemTimerISR                               ((ObjectIdType)16)
#define Object_CAN0_ISR                                     ((ObjectIdType)17)
#define Object_GPT_ISR                                      ((ObjectIdType)18)
#define Object_BACKUP                                       ((ObjectIdType)19)
#define Object_PDMA48                                       ((ObjectIdType)20)
#define Object_PDMA49                                       ((ObjectIdType)21)
#define Object_PDMA50                                       ((ObjectIdType)22)
#define Object_PDMA51                                       ((ObjectIdType)23)
#define Object_PDMA52                                       ((ObjectIdType)24)
#define Object_cpuss_interrupts_ipc_6_IRQn                  ((ObjectIdType)25)
#define Object_ISR_GFX2D                                    ((ObjectIdType)26)
#define Object_ISR_VIDEOIO_0                                ((ObjectIdType)27)
#define Object_ISR_VIDEOIO_1                                ((ObjectIdType)28)
#define Object_ISR_PDMA22                                   ((ObjectIdType)29)
#define Object_ISR_MDMA1                                    ((ObjectIdType)30)
#define Object_ISR_MDMA2                                    ((ObjectIdType)31)
#define Object_CAN1_ISR                                     ((ObjectIdType)32)
#define Object_SCB2                                         ((ObjectIdType)33)
#define Object_IGN_ISR                                      ((ObjectIdType)34)
#define Object_CAN_WAKEUP_ISR                               ((ObjectIdType)35)
#define Object_ECC_ERROR_ISR                                ((ObjectIdType)36)
#define Object_MCU_LVD_ISR                                  ((ObjectIdType)37)
#define Object_CSV_ERROR_ISR                                ((ObjectIdType)38)
#define Object_SSV_ERROR_ISR                                ((ObjectIdType)39)
/* Kernel Object Names */
#define Object_OsKernel_OsCoreAsr0                                   ((ObjectIdType)40)
#define Object_ObjectIdMax                                     ((ObjectIdType)41)

/* Object Ids */
#define Os_Object_Id_0                                       Object_OsTask_BSW_COM_Periodic_2
#define Os_Object_Id_1                                       Object_OsTask_BSW_EventPeriodic_0
#define Os_Object_Id_2                                       Object_Init_Task
#define Os_Object_Id_3                                       Object_IdleTask_OsCore_Core0
#define Os_Object_Id_4                                       Object_OsTask_BSW_Periodic_0
#define Os_Object_Id_5                                       Object_OsTask_BSW_Periodic_1
#define Os_Object_Id_6                                       Object_OsTask_CAN_Periodic_0
#define Os_Object_Id_7                                       Object_OsTask_CDD_FitPeriodic_1
#define Os_Object_Id_8                                       Object_OsTask_CDD_Periodic_0
#define Os_Object_Id_9                                       Object_OsTask_COM_EventPeriodic_0
#define Os_Object_Id_10                                      Object_OsTask_CanDataRx_0
#define Os_Object_Id_11                                      Object_OsTask_NvmSpeedup
#define Os_Object_Id_12                                      Object_OsTask_SafeBsw_0
#define Os_Object_Id_13                                      Object_OsTask_SafeBsw_1
#define Os_Object_Id_14                                      Object_OsTask_LSH_16ms
#define Os_Object_Id_15                                      Object_OsTaskRender
#define Os_Object_Id_16                                      Object_SystemTimerISR
#define Os_Object_Id_17                                      Object_CAN0_ISR
#define Os_Object_Id_18                                      Object_GPT_ISR
#define Os_Object_Id_19                                      Object_BACKUP
#define Os_Object_Id_20                                      Object_PDMA48
#define Os_Object_Id_21                                      Object_PDMA49
#define Os_Object_Id_22                                      Object_PDMA50
#define Os_Object_Id_23                                      Object_PDMA51
#define Os_Object_Id_24                                      Object_PDMA52
#define Os_Object_Id_25                                      Object_cpuss_interrupts_ipc_6_IRQn
#define Os_Object_Id_26                                      Object_ISR_GFX2D
#define Os_Object_Id_27                                      Object_ISR_VIDEOIO_0
#define Os_Object_Id_28                                      Object_ISR_VIDEOIO_1
#define Os_Object_Id_29                                      Object_ISR_PDMA22
#define Os_Object_Id_30                                      Object_ISR_MDMA1
#define Os_Object_Id_31                                      Object_ISR_MDMA2
#define Os_Object_Id_32                                      Object_CAN1_ISR
#define Os_Object_Id_33                                      Object_SCB2
#define Os_Object_Id_34                                      Object_IGN_ISR
#define Os_Object_Id_35                                      Object_CAN_WAKEUP_ISR
#define Os_Object_Id_36                                      Object_ECC_ERROR_ISR
#define Os_Object_Id_37                                      Object_MCU_LVD_ISR
#define Os_Object_Id_38                                      Object_CSV_ERROR_ISR
#define Os_Object_Id_39                                      Object_SSV_ERROR_ISR
#define Os_Object_Id_40                                      Object_OsKernel_OsCoreAsr0

/*****************************************************************************
*                                  Task Table                                *
******************************************************************************/


/********************* Task OsTask_BSW_COM_Periodic_2*********************/	
#define osTaskFunction_OsTask_BSW_COM_Periodic_2                (osTaskFuncRefType)&OsTask_BSW_COM_Periodic_2func
#define osStackStartAddressTask_OsTask_BSW_COM_Periodic_2       (osStackPtrType)osdOsTask_BSW_COM_Periodic_2_TOP
#define osStackSizeTask_OsTask_BSW_COM_Periodic_2               sizeof(OsStack_OsTask_BSW_COM_Periodic_2Dyn)
#define osPrioTask_OsTask_BSW_COM_Periodic_2                    4
#define osMaxActivationCount_OsTask_BSW_COM_Periodic_2          1
#define osCategoryTask_OsTask_BSW_COM_Periodic_2                TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_BSW_COM_Periodic_2                    TASK_EXTENDED

/********************* Task OsTask_BSW_EventPeriodic_0*********************/	
#define osTaskFunction_OsTask_BSW_EventPeriodic_0               (osTaskFuncRefType)&OsTask_BSW_EventPeriodic_0func
#define osStackStartAddressTask_OsTask_BSW_EventPeriodic_0      (osStackPtrType)osdOsTask_BSW_EventPeriodic_0_TOP
#define osStackSizeTask_OsTask_BSW_EventPeriodic_0              sizeof(OsStack_OsTask_BSW_EventPeriodic_0Dyn)
#define osPrioTask_OsTask_BSW_EventPeriodic_0                   5
#define osMaxActivationCount_OsTask_BSW_EventPeriodic_0         1
#define osCategoryTask_OsTask_BSW_EventPeriodic_0               TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_BSW_EventPeriodic_0                   TASK_EXTENDED

/********************* Task Init_Task*********************/	
#define osTaskFunction_Init_Task                                (osTaskFuncRefType)&Init_Taskfunc
#define osStackStartAddressTask_Init_Task                       (osStackPtrType)osdInit_Task_TOP
#define osStackSizeTask_Init_Task                               sizeof(OsStack_Init_TaskDyn)
#define osPrioTask_Init_Task                                    9
#define osMaxActivationCount_Init_Task                          3
#define osCategoryTask_Init_Task                                TASK_NONPREEMPTIVE
#define osTypeTask_Init_Task                                    TASK_BASIC

/********************* Task IdleTask_OsCore_Core0*********************/	
#define osTaskFunction_IdleTask_OsCore_Core0                    (osTaskFuncRefType)&IdleTask_OsCore_Core0func
#define osStackStartAddressTask_IdleTask_OsCore_Core0           (osStackPtrType)osdIdleTask_OsCore_Core0_TOP
#define osStackSizeTask_IdleTask_OsCore_Core0                   sizeof(OsStack_IdleTask_OsCore_Core0Dyn)
#define osPrioTask_IdleTask_OsCore_Core0                        15
#define osMaxActivationCount_IdleTask_OsCore_Core0              1
#define osCategoryTask_IdleTask_OsCore_Core0                    TASK_PREEMPTIVE
#define osTypeTask_IdleTask_OsCore_Core0                        TASK_EXTENDED

/********************* Task OsTask_BSW_Periodic_0*********************/	
#define osTaskFunction_OsTask_BSW_Periodic_0                    (osTaskFuncRefType)&OsTask_BSW_Periodic_0func
#define osStackStartAddressTask_OsTask_BSW_Periodic_0           (osStackPtrType)osdOsTask_BSW_Periodic_0_TOP
#define osStackSizeTask_OsTask_BSW_Periodic_0                   sizeof(OsStack_OsTask_BSW_Periodic_0Dyn)
#define osPrioTask_OsTask_BSW_Periodic_0                        3
#define osMaxActivationCount_OsTask_BSW_Periodic_0              1
#define osCategoryTask_OsTask_BSW_Periodic_0                    TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_BSW_Periodic_0                        TASK_BASIC

/********************* Task OsTask_BSW_Periodic_1*********************/	
#define osTaskFunction_OsTask_BSW_Periodic_1                    (osTaskFuncRefType)&OsTask_BSW_Periodic_1func
#define osStackStartAddressTask_OsTask_BSW_Periodic_1           (osStackPtrType)osdOsTask_BSW_Periodic_1_TOP
#define osStackSizeTask_OsTask_BSW_Periodic_1                   sizeof(OsStack_OsTask_BSW_Periodic_1Dyn)
#define osPrioTask_OsTask_BSW_Periodic_1                        7
#define osMaxActivationCount_OsTask_BSW_Periodic_1              1
#define osCategoryTask_OsTask_BSW_Periodic_1                    TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_BSW_Periodic_1                        TASK_BASIC

/********************* Task OsTask_CAN_Periodic_0*********************/	
#define osTaskFunction_OsTask_CAN_Periodic_0                    (osTaskFuncRefType)&OsTask_CAN_Periodic_0func
#define osStackStartAddressTask_OsTask_CAN_Periodic_0           (osStackPtrType)osdOsTask_CAN_Periodic_0_TOP
#define osStackSizeTask_OsTask_CAN_Periodic_0                   sizeof(OsStack_OsTask_CAN_Periodic_0Dyn)
#define osPrioTask_OsTask_CAN_Periodic_0                        6
#define osMaxActivationCount_OsTask_CAN_Periodic_0              1
#define osCategoryTask_OsTask_CAN_Periodic_0                    TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_CAN_Periodic_0                        TASK_BASIC

/********************* Task OsTask_CDD_FitPeriodic_1*********************/	
#define osTaskFunction_OsTask_CDD_FitPeriodic_1                 (osTaskFuncRefType)&OsTask_CDD_FitPeriodic_1func
#define osStackStartAddressTask_OsTask_CDD_FitPeriodic_1        (osStackPtrType)osdOsTask_CDD_FitPeriodic_1_TOP
#define osStackSizeTask_OsTask_CDD_FitPeriodic_1                sizeof(OsStack_OsTask_CDD_FitPeriodic_1Dyn)
#define osPrioTask_OsTask_CDD_FitPeriodic_1                     14
#define osMaxActivationCount_OsTask_CDD_FitPeriodic_1           1
#define osCategoryTask_OsTask_CDD_FitPeriodic_1                 TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_CDD_FitPeriodic_1                     TASK_EXTENDED

/********************* Task OsTask_CDD_Periodic_0*********************/	
#define osTaskFunction_OsTask_CDD_Periodic_0                    (osTaskFuncRefType)&OsTask_CDD_Periodic_0func
#define osStackStartAddressTask_OsTask_CDD_Periodic_0           (osStackPtrType)osdOsTask_CDD_Periodic_0_TOP
#define osStackSizeTask_OsTask_CDD_Periodic_0                   sizeof(OsStack_OsTask_CDD_Periodic_0Dyn)
#define osPrioTask_OsTask_CDD_Periodic_0                        11
#define osMaxActivationCount_OsTask_CDD_Periodic_0              1
#define osCategoryTask_OsTask_CDD_Periodic_0                    TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_CDD_Periodic_0                        TASK_BASIC

/********************* Task OsTask_COM_EventPeriodic_0*********************/	
#define osTaskFunction_OsTask_COM_EventPeriodic_0               (osTaskFuncRefType)&OsTask_COM_EventPeriodic_0func
#define osStackStartAddressTask_OsTask_COM_EventPeriodic_0      (osStackPtrType)osdOsTask_COM_EventPeriodic_0_TOP
#define osStackSizeTask_OsTask_COM_EventPeriodic_0              sizeof(OsStack_OsTask_COM_EventPeriodic_0Dyn)
#define osPrioTask_OsTask_COM_EventPeriodic_0                   8
#define osMaxActivationCount_OsTask_COM_EventPeriodic_0         1
#define osCategoryTask_OsTask_COM_EventPeriodic_0               TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_COM_EventPeriodic_0                   TASK_EXTENDED

/********************* Task OsTask_CanDataRx_0*********************/	
#define osTaskFunction_OsTask_CanDataRx_0                       (osTaskFuncRefType)&OsTask_CanDataRx_0func
#define osStackStartAddressTask_OsTask_CanDataRx_0              (osStackPtrType)osdOsTask_CanDataRx_0_TOP
#define osStackSizeTask_OsTask_CanDataRx_0                      sizeof(OsStack_OsTask_CanDataRx_0Dyn)
#define osPrioTask_OsTask_CanDataRx_0                           10
#define osMaxActivationCount_OsTask_CanDataRx_0                 1
#define osCategoryTask_OsTask_CanDataRx_0                       TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_CanDataRx_0                           TASK_EXTENDED

/********************* Task OsTask_NvmSpeedup*********************/	
#define osTaskFunction_OsTask_NvmSpeedup                        (osTaskFuncRefType)&OsTask_NvmSpeedupfunc
#define osStackStartAddressTask_OsTask_NvmSpeedup               (osStackPtrType)osdOsTask_NvmSpeedup_TOP
#define osStackSizeTask_OsTask_NvmSpeedup                       sizeof(OsStack_OsTask_NvmSpeedupDyn)
#define osPrioTask_OsTask_NvmSpeedup                            12
#define osMaxActivationCount_OsTask_NvmSpeedup                  1
#define osCategoryTask_OsTask_NvmSpeedup                        TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_NvmSpeedup                            TASK_BASIC

/********************* Task OsTask_SafeBsw_0*********************/	
#define osTaskFunction_OsTask_SafeBsw_0                         (osTaskFuncRefType)&OsTask_SafeBsw_0func
#define osStackStartAddressTask_OsTask_SafeBsw_0                (osStackPtrType)osdOsTask_SafeBsw_0_TOP
#define osStackSizeTask_OsTask_SafeBsw_0                        sizeof(OsStack_OsTask_SafeBsw_0Dyn)
#define osPrioTask_OsTask_SafeBsw_0                             1
#define osMaxActivationCount_OsTask_SafeBsw_0                   1
#define osCategoryTask_OsTask_SafeBsw_0                         TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_SafeBsw_0                             TASK_BASIC

/********************* Task OsTask_SafeBsw_1*********************/	
#define osTaskFunction_OsTask_SafeBsw_1                         (osTaskFuncRefType)&OsTask_SafeBsw_1func
#define osStackStartAddressTask_OsTask_SafeBsw_1                (osStackPtrType)osdOsTask_SafeBsw_1_TOP
#define osStackSizeTask_OsTask_SafeBsw_1                        sizeof(OsStack_OsTask_SafeBsw_1Dyn)
#define osPrioTask_OsTask_SafeBsw_1                             0
#define osMaxActivationCount_OsTask_SafeBsw_1                   1
#define osCategoryTask_OsTask_SafeBsw_1                         TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_SafeBsw_1                             TASK_EXTENDED

/********************* Task OsTask_LSH_16ms*********************/	
#define osTaskFunction_OsTask_LSH_16ms                          (osTaskFuncRefType)&OsTask_LSH_16msfunc
#define osStackStartAddressTask_OsTask_LSH_16ms                 (osStackPtrType)osdOsTask_LSH_16ms_TOP
#define osStackSizeTask_OsTask_LSH_16ms                         sizeof(OsStack_OsTask_LSH_16msDyn)
#define osPrioTask_OsTask_LSH_16ms                              2
#define osMaxActivationCount_OsTask_LSH_16ms                    1
#define osCategoryTask_OsTask_LSH_16ms                          TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_LSH_16ms                              TASK_EXTENDED

/********************* Task OsTaskRender*********************/	
#define osTaskFunction_OsTaskRender                             (osTaskFuncRefType)&OsTaskRenderfunc
#define osStackStartAddressTask_OsTaskRender                    (osStackPtrType)osdOsTaskRender_TOP
#define osStackSizeTask_OsTaskRender                            sizeof(OsStack_OsTaskRenderDyn)
#define osPrioTask_OsTaskRender                                 13
#define osMaxActivationCount_OsTaskRender                       1
#define osCategoryTask_OsTaskRender                             TASK_PREEMPTIVE
#define osTypeTask_OsTaskRender                                 TASK_EXTENDED


#define OsNumberOfAutoStartTasks                          3


#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

