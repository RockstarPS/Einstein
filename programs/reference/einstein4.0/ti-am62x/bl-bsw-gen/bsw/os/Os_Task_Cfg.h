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
*    @file Os_Task_Cfg.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by MNATRAMI at 2026-04-06 16:31:56.335514900
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


#define OsNumberOfTasks                                   6U

/*****************************************************************************
*                        Task Ids                                            *
*****************************************************************************/
#define InitTask                                          ((TaskType)0)
#define osTaskID_InitTask                                ((TaskType)0)

#define OsTask_Ucl                                        ((TaskType)1)
#define osTaskID_OsTask_Ucl                              ((TaskType)1)

#define OsTask_Diagnostics                                ((TaskType)2)
#define osTaskID_OsTask_Diagnostics                      ((TaskType)2)

#define OsTask_CANFun                                     ((TaskType)3)
#define osTaskID_OsTask_CANFun                           ((TaskType)3)

#define OsTask_WdgMngt                                    ((TaskType)4)
#define osTaskID_OsTask_WdgMngt                          ((TaskType)4)

#define OsTask_IdleTask                                   ((TaskType)5)
#define osTaskID_OsTask_IdleTask                         ((TaskType)5)



/* Object Names */
/* Task Object Names */
#define Object_InitTask                                     ((ObjectIdType)0)
#define Object_OsTask_Ucl                                   ((ObjectIdType)1)
#define Object_OsTask_Diagnostics                           ((ObjectIdType)2)
#define Object_OsTask_CANFun                                ((ObjectIdType)3)
#define Object_OsTask_WdgMngt                               ((ObjectIdType)4)
#define Object_OsTask_IdleTask                              ((ObjectIdType)5)

/* Isr Object Names */
#define Object_McuOsGptIsr                                  ((ObjectIdType)6)
#define Object_McuCan0RxTxIsr                               ((ObjectIdType)7)
#define Object_McuCan1RxTxIsr                               ((ObjectIdType)8)
#define Object_McuI2c3IoIsr                                 ((ObjectIdType)9)
#define Object_McuI2c0PmicIsr                               ((ObjectIdType)10)
#define Object_Gpt_Ch3Isr                                   ((ObjectIdType)11)
#define Object_Gpt_Ch4Isr                                   ((ObjectIdType)12)
#define Object_PmicCdd_nINTGpioInterrupt                    ((ObjectIdType)13)
#define Object_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0               ((ObjectIdType)14)
/* Kernel Object Names */
#define Object_OsKernel_OsCoreAsr0                                   ((ObjectIdType)15)
#define Object_ObjectIdMax                                     ((ObjectIdType)16)

/* Object Ids */
#define Os_Object_Id_0                                       Object_InitTask
#define Os_Object_Id_1                                       Object_OsTask_Ucl
#define Os_Object_Id_2                                       Object_OsTask_Diagnostics
#define Os_Object_Id_3                                       Object_OsTask_CANFun
#define Os_Object_Id_4                                       Object_OsTask_WdgMngt
#define Os_Object_Id_5                                       Object_OsTask_IdleTask
#define Os_Object_Id_6                                       Object_McuOsGptIsr
#define Os_Object_Id_7                                       Object_McuCan0RxTxIsr
#define Os_Object_Id_8                                       Object_McuCan1RxTxIsr
#define Os_Object_Id_9                                       Object_McuI2c3IoIsr
#define Os_Object_Id_10                                      Object_McuI2c0PmicIsr
#define Os_Object_Id_11                                      Object_Gpt_Ch3Isr
#define Os_Object_Id_12                                      Object_Gpt_Ch4Isr
#define Os_Object_Id_13                                      Object_PmicCdd_nINTGpioInterrupt
#define Os_Object_Id_14                                      Object_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0
#define Os_Object_Id_15                                      Object_OsKernel_OsCoreAsr0

/*****************************************************************************
*                                  Task Table                                *
******************************************************************************/


/********************* Task InitTask*********************/	
#define osTaskFunction_InitTask                                 (osTaskFuncRefType)&InitTaskfunc
#define osStackStartAddressTask_InitTask                        (osStackPtrType)osdInitTask_TOP
#define osStackSizeTask_InitTask                                sizeof(OsStack_InitTaskDyn)
#define osPrioTask_InitTask                                     0
#define osMaxActivationCount_InitTask                           5
#define osCategoryTask_InitTask                                 TASK_NONPREEMPTIVE
#define osTypeTask_InitTask                                     TASK_BASIC

/********************* Task OsTask_Ucl*********************/	
#define osTaskFunction_OsTask_Ucl                               (osTaskFuncRefType)&OsTask_Uclfunc
#define osStackStartAddressTask_OsTask_Ucl                      (osStackPtrType)osdOsTask_Ucl_TOP
#define osStackSizeTask_OsTask_Ucl                              sizeof(OsStack_OsTask_UclDyn)
#define osPrioTask_OsTask_Ucl                                   1
#define osMaxActivationCount_OsTask_Ucl                         1
#define osCategoryTask_OsTask_Ucl                               TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_Ucl                                   TASK_EXTENDED

/********************* Task OsTask_Diagnostics*********************/	
#define osTaskFunction_OsTask_Diagnostics                       (osTaskFuncRefType)&OsTask_Diagnosticsfunc
#define osStackStartAddressTask_OsTask_Diagnostics              (osStackPtrType)osdOsTask_Diagnostics_TOP
#define osStackSizeTask_OsTask_Diagnostics                      sizeof(OsStack_OsTask_DiagnosticsDyn)
#define osPrioTask_OsTask_Diagnostics                           2
#define osMaxActivationCount_OsTask_Diagnostics                 1
#define osCategoryTask_OsTask_Diagnostics                       TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_Diagnostics                           TASK_EXTENDED

/********************* Task OsTask_CANFun*********************/	
#define osTaskFunction_OsTask_CANFun                            (osTaskFuncRefType)&OsTask_CANFunfunc
#define osStackStartAddressTask_OsTask_CANFun                   (osStackPtrType)osdOsTask_CANFun_TOP
#define osStackSizeTask_OsTask_CANFun                           sizeof(OsStack_OsTask_CANFunDyn)
#define osPrioTask_OsTask_CANFun                                3
#define osMaxActivationCount_OsTask_CANFun                      1
#define osCategoryTask_OsTask_CANFun                            TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_CANFun                                TASK_EXTENDED

/********************* Task OsTask_WdgMngt*********************/	
#define osTaskFunction_OsTask_WdgMngt                           (osTaskFuncRefType)&OsTask_WdgMngtfunc
#define osStackStartAddressTask_OsTask_WdgMngt                  (osStackPtrType)osdOsTask_WdgMngt_TOP
#define osStackSizeTask_OsTask_WdgMngt                          sizeof(OsStack_OsTask_WdgMngtDyn)
#define osPrioTask_OsTask_WdgMngt                               4
#define osMaxActivationCount_OsTask_WdgMngt                     1
#define osCategoryTask_OsTask_WdgMngt                           TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_WdgMngt                               TASK_EXTENDED

/********************* Task OsTask_IdleTask*********************/	
#define osTaskFunction_OsTask_IdleTask                          (osTaskFuncRefType)&OsTask_IdleTaskfunc
#define osStackStartAddressTask_OsTask_IdleTask                 (osStackPtrType)osdOsTask_IdleTask_TOP
#define osStackSizeTask_OsTask_IdleTask                         sizeof(OsStack_OsTask_IdleTaskDyn)
#define osPrioTask_OsTask_IdleTask                              5
#define osMaxActivationCount_OsTask_IdleTask                    1
#define osCategoryTask_OsTask_IdleTask                          TASK_PREEMPTIVE
#define osTypeTask_OsTask_IdleTask                              TASK_BASIC


#define OsNumberOfAutoStartTasks                          2


#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

