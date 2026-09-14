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
*    Auto generated code in vAUTOSAR TOOL by KPORKODI at 2026-06-15 15:53:48.405100500
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


#define OsNumberOfTasks                                   27U

/*****************************************************************************
*                        Task Ids                                            *
*****************************************************************************/
#define InitTask                                          ((TaskType)0)
#define osTaskID_InitTask                                ((TaskType)0)

#define OsTask_AppFun                                     ((TaskType)1)
#define osTaskID_OsTask_AppFun                           ((TaskType)1)

#define OsTask_AudioFun                                   ((TaskType)2)
#define osTaskID_OsTask_AudioFun                         ((TaskType)2)

#define OsTask_Can0DataRxEv                               ((TaskType)3)
#define osTaskID_OsTask_Can0DataRxEv                     ((TaskType)3)

#define OsTask_Can1DataRxEv                               ((TaskType)4)
#define osTaskID_OsTask_Can1DataRxEv                     ((TaskType)4)

#define OsTask_CANFun                                     ((TaskType)5)
#define osTaskID_OsTask_CANFun                           ((TaskType)5)

#define OsTask_DispFun                                    ((TaskType)6)
#define osTaskID_OsTask_DispFun                          ((TaskType)6)

#define OsTask_EthFun                                     ((TaskType)7)
#define osTaskID_OsTask_EthFun                           ((TaskType)7)

#define OsTask_FotaEv                                     ((TaskType)8)
#define osTaskID_OsTask_FotaEv                           ((TaskType)8)

#define OsTask_FotaFun                                    ((TaskType)9)
#define osTaskID_OsTask_FotaFun                          ((TaskType)9)

#define OsTask_GaugeFun                                   ((TaskType)10)
#define osTaskID_OsTask_GaugeFun                         ((TaskType)10)

#define OsTask_IdleTask                                   ((TaskType)11)
#define osTaskID_OsTask_IdleTask                         ((TaskType)11)

#define OsTask_IndFun                                     ((TaskType)12)
#define osTaskID_OsTask_IndFun                           ((TaskType)12)

#define OsTask_LinFun                                     ((TaskType)13)
#define osTaskID_OsTask_LinFun                           ((TaskType)13)

#define OsTask_Mcal                                       ((TaskType)14)
#define osTaskID_OsTask_Mcal                             ((TaskType)14)

#define OsTask_ModeMgt                                    ((TaskType)15)
#define osTaskID_OsTask_ModeMgt                          ((TaskType)15)

#define OsTask_NvmSpeedup                                 ((TaskType)16)
#define osTaskID_OsTask_NvmSpeedup                       ((TaskType)16)

#define OsTask_SafeApp                                    ((TaskType)17)
#define osTaskID_OsTask_SafeApp                          ((TaskType)17)

#define OsTask_TripFun                                    ((TaskType)18)
#define osTaskID_OsTask_TripFun                          ((TaskType)18)

#define OsTask_WarnFun                                    ((TaskType)19)
#define osTaskID_OsTask_WarnFun                          ((TaskType)19)

#define OsTask_WdgMngt                                    ((TaskType)20)
#define osTaskID_OsTask_WdgMngt                          ((TaskType)20)

#define OsTask_Diagnostics                                ((TaskType)21)
#define osTaskID_OsTask_Diagnostics                      ((TaskType)21)

#define OsTask_LSH_16ms                                   ((TaskType)22)
#define osTaskID_OsTask_LSH_16ms                         ((TaskType)22)

#define OsTask_SafeBsw                                    ((TaskType)23)
#define osTaskID_OsTask_SafeBsw                          ((TaskType)23)

#define OsTask_MemSer                                     ((TaskType)24)
#define osTaskID_OsTask_MemSer                           ((TaskType)24)

#define OsTask_IpcUclEv                                   ((TaskType)25)
#define osTaskID_OsTask_IpcUclEv                         ((TaskType)25)

#define OsTaskRender                                      ((TaskType)26)
#define osTaskID_OsTaskRender                            ((TaskType)26)



/* Object Names */
/* Task Object Names */
#define Object_InitTask                                     ((ObjectIdType)0)
#define Object_OsTask_AppFun                                ((ObjectIdType)1)
#define Object_OsTask_AudioFun                              ((ObjectIdType)2)
#define Object_OsTask_Can0DataRxEv                          ((ObjectIdType)3)
#define Object_OsTask_Can1DataRxEv                          ((ObjectIdType)4)
#define Object_OsTask_CANFun                                ((ObjectIdType)5)
#define Object_OsTask_DispFun                               ((ObjectIdType)6)
#define Object_OsTask_EthFun                                ((ObjectIdType)7)
#define Object_OsTask_FotaEv                                ((ObjectIdType)8)
#define Object_OsTask_FotaFun                               ((ObjectIdType)9)
#define Object_OsTask_GaugeFun                              ((ObjectIdType)10)
#define Object_OsTask_IdleTask                              ((ObjectIdType)11)
#define Object_OsTask_IndFun                                ((ObjectIdType)12)
#define Object_OsTask_LinFun                                ((ObjectIdType)13)
#define Object_OsTask_Mcal                                  ((ObjectIdType)14)
#define Object_OsTask_ModeMgt                               ((ObjectIdType)15)
#define Object_OsTask_NvmSpeedup                            ((ObjectIdType)16)
#define Object_OsTask_SafeApp                               ((ObjectIdType)17)
#define Object_OsTask_TripFun                               ((ObjectIdType)18)
#define Object_OsTask_WarnFun                               ((ObjectIdType)19)
#define Object_OsTask_WdgMngt                               ((ObjectIdType)20)
#define Object_OsTask_Diagnostics                           ((ObjectIdType)21)
#define Object_OsTask_LSH_16ms                              ((ObjectIdType)22)
#define Object_OsTask_SafeBsw                               ((ObjectIdType)23)
#define Object_OsTask_MemSer                                ((ObjectIdType)24)
#define Object_OsTask_IpcUclEv                              ((ObjectIdType)25)
#define Object_OsTaskRender                                 ((ObjectIdType)26)

/* Isr Object Names */
#define Object_McuOsGptIsr                                  ((ObjectIdType)27)
#define Object_McuCan0RxTxIsr                               ((ObjectIdType)28)
#define Object_McuCan1RxTxIsr                               ((ObjectIdType)29)
#define Object_McuSpi0NvmRxTxIsr                            ((ObjectIdType)30)
#define Object_McuDss0Isr                                   ((ObjectIdType)31)
#define Object_McuI2c3IoIsr                                 ((ObjectIdType)32)
#define Object_Eth_TxIrqHdlr_0                              ((ObjectIdType)33)
#define Object_Eth_RxIrqHdlr_0                              ((ObjectIdType)34)
#define Object_Eth_MdioIrqHdlr                              ((ObjectIdType)35)
#define Object_FltM_WkupEsmHiInterrupt                      ((ObjectIdType)36)
#define Object_MCU_IntrISR_UART0                            ((ObjectIdType)37)
#define Object_McuI2c0PmicIsr                               ((ObjectIdType)38)
#define Object_Gpt_Ch3Isr                                   ((ObjectIdType)39)
#define Object_Gpt_Ch4Isr                                   ((ObjectIdType)40)
#define Object_Spi_IrqUnitMcspi2TxRx                        ((ObjectIdType)41)
#define Object_MCU_ISR_6                                    ((ObjectIdType)42)
#define Object_MAIN_ISR_34                                  ((ObjectIdType)43)
#define Object_MAIN_ISR_35                                  ((ObjectIdType)44)
#define Object_MCU_ISR_7                                    ((ObjectIdType)45)
#define Object_FltM_WkupEsmCfgInterrupt                     ((ObjectIdType)46)
#define Object_FltM_WkupEsmLowInterrupt                     ((ObjectIdType)47)
#define Object_Spi_IrqUnitMcspi0TxRx                        ((ObjectIdType)48)
#define Object_MainI2c2RtcIsr                               ((ObjectIdType)49)
#define Object_MCU_ResetIsolationReq                        ((ObjectIdType)50)
#define Object_FltM_FwlExceptionInterrupt                   ((ObjectIdType)51)
#define Object_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0               ((ObjectIdType)52)
#define Object_Mcu_Udma_Vintr64                             ((ObjectIdType)53)
#define Object_Mcu_Udma_Vintr65                             ((ObjectIdType)54)
#define Object_Mcu_Udma_Vintr66                             ((ObjectIdType)55)
#define Object_Mcu_Udma_Vintr67                             ((ObjectIdType)56)
#define Object_Mcu_Udma_Vintr68                             ((ObjectIdType)57)
#define Object_Mcu_Udma_Vintr69                             ((ObjectIdType)58)
#define Object_Mcu_Udma_Vintr70                             ((ObjectIdType)59)
#define Object_Mcu_Udma_Vintr71                             ((ObjectIdType)60)
#define Object_Mcu_Udma_Vintr72                             ((ObjectIdType)61)
#define Object_Mcu_Udma_Vintr73                             ((ObjectIdType)62)
#define Object_Mcu_Udma_Vintr74                             ((ObjectIdType)63)
#define Object_Mcu_Udma_Vintr75                             ((ObjectIdType)64)
#define Object_Mcu_Udma_Vintr76                             ((ObjectIdType)65)
#define Object_Mcu_Udma_Vintr77                             ((ObjectIdType)66)
#define Object_Mcu_Udma_Vintr78                             ((ObjectIdType)67)
#define Object_Mcu_Udma_Vintr79                             ((ObjectIdType)68)
#define Object_MainI2c1DacIsr                               ((ObjectIdType)69)
/* Kernel Object Names */
#define Object_OsKernel_OsCoreAsr0                                   ((ObjectIdType)70)
#define Object_ObjectIdMax                                     ((ObjectIdType)71)

/* Object Ids */
#define Os_Object_Id_0                                       Object_InitTask
#define Os_Object_Id_1                                       Object_OsTask_AppFun
#define Os_Object_Id_2                                       Object_OsTask_AudioFun
#define Os_Object_Id_3                                       Object_OsTask_Can0DataRxEv
#define Os_Object_Id_4                                       Object_OsTask_Can1DataRxEv
#define Os_Object_Id_5                                       Object_OsTask_CANFun
#define Os_Object_Id_6                                       Object_OsTask_DispFun
#define Os_Object_Id_7                                       Object_OsTask_EthFun
#define Os_Object_Id_8                                       Object_OsTask_FotaEv
#define Os_Object_Id_9                                       Object_OsTask_FotaFun
#define Os_Object_Id_10                                      Object_OsTask_GaugeFun
#define Os_Object_Id_11                                      Object_OsTask_IdleTask
#define Os_Object_Id_12                                      Object_OsTask_IndFun
#define Os_Object_Id_13                                      Object_OsTask_LinFun
#define Os_Object_Id_14                                      Object_OsTask_Mcal
#define Os_Object_Id_15                                      Object_OsTask_ModeMgt
#define Os_Object_Id_16                                      Object_OsTask_NvmSpeedup
#define Os_Object_Id_17                                      Object_OsTask_SafeApp
#define Os_Object_Id_18                                      Object_OsTask_TripFun
#define Os_Object_Id_19                                      Object_OsTask_WarnFun
#define Os_Object_Id_20                                      Object_OsTask_WdgMngt
#define Os_Object_Id_21                                      Object_OsTask_Diagnostics
#define Os_Object_Id_22                                      Object_OsTask_LSH_16ms
#define Os_Object_Id_23                                      Object_OsTask_SafeBsw
#define Os_Object_Id_24                                      Object_OsTask_MemSer
#define Os_Object_Id_25                                      Object_OsTask_IpcUclEv
#define Os_Object_Id_26                                      Object_OsTaskRender
#define Os_Object_Id_27                                      Object_McuOsGptIsr
#define Os_Object_Id_28                                      Object_McuCan0RxTxIsr
#define Os_Object_Id_29                                      Object_McuCan1RxTxIsr
#define Os_Object_Id_30                                      Object_McuSpi0NvmRxTxIsr
#define Os_Object_Id_31                                      Object_McuDss0Isr
#define Os_Object_Id_32                                      Object_McuI2c3IoIsr
#define Os_Object_Id_33                                      Object_Eth_TxIrqHdlr_0
#define Os_Object_Id_34                                      Object_Eth_RxIrqHdlr_0
#define Os_Object_Id_35                                      Object_Eth_MdioIrqHdlr
#define Os_Object_Id_36                                      Object_FltM_WkupEsmHiInterrupt
#define Os_Object_Id_37                                      Object_MCU_IntrISR_UART0
#define Os_Object_Id_38                                      Object_McuI2c0PmicIsr
#define Os_Object_Id_39                                      Object_Gpt_Ch3Isr
#define Os_Object_Id_40                                      Object_Gpt_Ch4Isr
#define Os_Object_Id_41                                      Object_Spi_IrqUnitMcspi2TxRx
#define Os_Object_Id_42                                      Object_MCU_ISR_6
#define Os_Object_Id_43                                      Object_MAIN_ISR_34
#define Os_Object_Id_44                                      Object_MAIN_ISR_35
#define Os_Object_Id_45                                      Object_MCU_ISR_7
#define Os_Object_Id_46                                      Object_FltM_WkupEsmCfgInterrupt
#define Os_Object_Id_47                                      Object_FltM_WkupEsmLowInterrupt
#define Os_Object_Id_48                                      Object_Spi_IrqUnitMcspi0TxRx
#define Os_Object_Id_49                                      Object_MainI2c2RtcIsr
#define Os_Object_Id_50                                      Object_MCU_ResetIsolationReq
#define Os_Object_Id_51                                      Object_FltM_FwlExceptionInterrupt
#define Os_Object_Id_52                                      Object_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0
#define Os_Object_Id_53                                      Object_Mcu_Udma_Vintr64
#define Os_Object_Id_54                                      Object_Mcu_Udma_Vintr65
#define Os_Object_Id_55                                      Object_Mcu_Udma_Vintr66
#define Os_Object_Id_56                                      Object_Mcu_Udma_Vintr67
#define Os_Object_Id_57                                      Object_Mcu_Udma_Vintr68
#define Os_Object_Id_58                                      Object_Mcu_Udma_Vintr69
#define Os_Object_Id_59                                      Object_Mcu_Udma_Vintr70
#define Os_Object_Id_60                                      Object_Mcu_Udma_Vintr71
#define Os_Object_Id_61                                      Object_Mcu_Udma_Vintr72
#define Os_Object_Id_62                                      Object_Mcu_Udma_Vintr73
#define Os_Object_Id_63                                      Object_Mcu_Udma_Vintr74
#define Os_Object_Id_64                                      Object_Mcu_Udma_Vintr75
#define Os_Object_Id_65                                      Object_Mcu_Udma_Vintr76
#define Os_Object_Id_66                                      Object_Mcu_Udma_Vintr77
#define Os_Object_Id_67                                      Object_Mcu_Udma_Vintr78
#define Os_Object_Id_68                                      Object_Mcu_Udma_Vintr79
#define Os_Object_Id_69                                      Object_MainI2c1DacIsr
#define Os_Object_Id_70                                      Object_OsKernel_OsCoreAsr0

/*****************************************************************************
*                                  Task Table                                *
******************************************************************************/


/********************* Task InitTask*********************/	
#define osTaskFunction_InitTask                                 (osTaskFuncRefType)&InitTaskfunc
#define osStackStartAddressTask_InitTask                        (osStackPtrType)osdInitTask_TOP
#define osStackSizeTask_InitTask                                sizeof(OsStack_InitTaskDyn)
#define osPrioTask_InitTask                                     0
#define osMaxActivationCount_InitTask                           3
#define osCategoryTask_InitTask                                 TASK_NONPREEMPTIVE
#define osTypeTask_InitTask                                     TASK_BASIC

/********************* Task OsTask_AppFun*********************/	
#define osTaskFunction_OsTask_AppFun                            (osTaskFuncRefType)&OsTask_AppFunfunc
#define osStackStartAddressTask_OsTask_AppFun                   (osStackPtrType)osdOsTask_AppFun_TOP
#define osStackSizeTask_OsTask_AppFun                           sizeof(OsStack_OsTaskStackSharingDyn)
#define osPrioTask_OsTask_AppFun                                21
#define osMaxActivationCount_OsTask_AppFun                      1
#define osCategoryTask_OsTask_AppFun                            TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_AppFun                                TASK_BASIC

/********************* Task OsTask_AudioFun*********************/	
#define osTaskFunction_OsTask_AudioFun                          (osTaskFuncRefType)&OsTask_AudioFunfunc
#define osStackStartAddressTask_OsTask_AudioFun                 (osStackPtrType)osdOsTask_AudioFun_TOP
#define osStackSizeTask_OsTask_AudioFun                         sizeof(OsStack_OsTaskStackSharingDyn)
#define osPrioTask_OsTask_AudioFun                              15
#define osMaxActivationCount_OsTask_AudioFun                    1
#define osCategoryTask_OsTask_AudioFun                          TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_AudioFun                              TASK_BASIC

/********************* Task OsTask_Can0DataRxEv*********************/	
#define osTaskFunction_OsTask_Can0DataRxEv                      (osTaskFuncRefType)&OsTask_Can0DataRxEvfunc
#define osStackStartAddressTask_OsTask_Can0DataRxEv             (osStackPtrType)osdOsTask_Can0DataRxEv_TOP
#define osStackSizeTask_OsTask_Can0DataRxEv                     sizeof(OsStack_OsTask_Can0DataRxEvDyn)
#define osPrioTask_OsTask_Can0DataRxEv                          7
#define osMaxActivationCount_OsTask_Can0DataRxEv                1
#define osCategoryTask_OsTask_Can0DataRxEv                      TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_Can0DataRxEv                          TASK_EXTENDED

/********************* Task OsTask_Can1DataRxEv*********************/	
#define osTaskFunction_OsTask_Can1DataRxEv                      (osTaskFuncRefType)&OsTask_Can1DataRxEvfunc
#define osStackStartAddressTask_OsTask_Can1DataRxEv             (osStackPtrType)osdOsTask_Can1DataRxEv_TOP
#define osStackSizeTask_OsTask_Can1DataRxEv                     sizeof(OsStack_OsTask_Can1DataRxEvDyn)
#define osPrioTask_OsTask_Can1DataRxEv                          8
#define osMaxActivationCount_OsTask_Can1DataRxEv                1
#define osCategoryTask_OsTask_Can1DataRxEv                      TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_Can1DataRxEv                          TASK_EXTENDED

/********************* Task OsTask_CANFun*********************/	
#define osTaskFunction_OsTask_CANFun                            (osTaskFuncRefType)&OsTask_CANFunfunc
#define osStackStartAddressTask_OsTask_CANFun                   (osStackPtrType)osdOsTask_CANFun_TOP
#define osStackSizeTask_OsTask_CANFun                           sizeof(OsStack_OsTask_CANFunDyn)
#define osPrioTask_OsTask_CANFun                                6
#define osMaxActivationCount_OsTask_CANFun                      1
#define osCategoryTask_OsTask_CANFun                            TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_CANFun                                TASK_EXTENDED

/********************* Task OsTask_DispFun*********************/	
#define osTaskFunction_OsTask_DispFun                           (osTaskFuncRefType)&OsTask_DispFunfunc
#define osStackStartAddressTask_OsTask_DispFun                  (osStackPtrType)osdOsTask_DispFun_TOP
#define osStackSizeTask_OsTask_DispFun                          sizeof(OsStack_OsTask_DispFunDyn)
#define osPrioTask_OsTask_DispFun                               2
#define osMaxActivationCount_OsTask_DispFun                     1
#define osCategoryTask_OsTask_DispFun                           TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_DispFun                               TASK_EXTENDED

/********************* Task OsTask_EthFun*********************/	
#define osTaskFunction_OsTask_EthFun                            (osTaskFuncRefType)&OsTask_EthFunfunc
#define osStackStartAddressTask_OsTask_EthFun                   (osStackPtrType)osdOsTask_EthFun_TOP
#define osStackSizeTask_OsTask_EthFun                           sizeof(OsStack_OsTaskStackSharingDyn)
#define osPrioTask_OsTask_EthFun                                9
#define osMaxActivationCount_OsTask_EthFun                      1
#define osCategoryTask_OsTask_EthFun                            TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_EthFun                                TASK_BASIC

/********************* Task OsTask_FotaEv*********************/	
#define osTaskFunction_OsTask_FotaEv                            (osTaskFuncRefType)&OsTask_FotaEvfunc
#define osStackStartAddressTask_OsTask_FotaEv                   (osStackPtrType)osdOsTask_FotaEv_TOP
#define osStackSizeTask_OsTask_FotaEv                           sizeof(OsStack_OsTask_FotaEvDyn)
#define osPrioTask_OsTask_FotaEv                                23
#define osMaxActivationCount_OsTask_FotaEv                      1
#define osCategoryTask_OsTask_FotaEv                            TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_FotaEv                                TASK_EXTENDED

/********************* Task OsTask_FotaFun*********************/	
#define osTaskFunction_OsTask_FotaFun                           (osTaskFuncRefType)&OsTask_FotaFunfunc
#define osStackStartAddressTask_OsTask_FotaFun                  (osStackPtrType)osdOsTask_FotaFun_TOP
#define osStackSizeTask_OsTask_FotaFun                          sizeof(OsStack_OsTask_FotaFunDyn)
#define osPrioTask_OsTask_FotaFun                               22
#define osMaxActivationCount_OsTask_FotaFun                     1
#define osCategoryTask_OsTask_FotaFun                           TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_FotaFun                               TASK_BASIC

/********************* Task OsTask_GaugeFun*********************/	
#define osTaskFunction_OsTask_GaugeFun                          (osTaskFuncRefType)&OsTask_GaugeFunfunc
#define osStackStartAddressTask_OsTask_GaugeFun                 (osStackPtrType)osdOsTask_GaugeFun_TOP
#define osStackSizeTask_OsTask_GaugeFun                         sizeof(OsStack_OsTaskStackSharingDyn)
#define osPrioTask_OsTask_GaugeFun                              12
#define osMaxActivationCount_OsTask_GaugeFun                    1
#define osCategoryTask_OsTask_GaugeFun                          TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_GaugeFun                              TASK_BASIC

/********************* Task OsTask_IdleTask*********************/	
#define osTaskFunction_OsTask_IdleTask                          (osTaskFuncRefType)&OsTask_IdleTaskfunc
#define osStackStartAddressTask_OsTask_IdleTask                 (osStackPtrType)osdOsTask_IdleTask_TOP
#define osStackSizeTask_OsTask_IdleTask                         sizeof(OsStack_OsTask_IdleTaskDyn)
#define osPrioTask_OsTask_IdleTask                              26
#define osMaxActivationCount_OsTask_IdleTask                    1
#define osCategoryTask_OsTask_IdleTask                          TASK_PREEMPTIVE
#define osTypeTask_OsTask_IdleTask                              TASK_BASIC

/********************* Task OsTask_IndFun*********************/	
#define osTaskFunction_OsTask_IndFun                            (osTaskFuncRefType)&OsTask_IndFunfunc
#define osStackStartAddressTask_OsTask_IndFun                   (osStackPtrType)osdOsTask_IndFun_TOP
#define osStackSizeTask_OsTask_IndFun                           sizeof(OsStack_OsTaskStackSharingDyn)
#define osPrioTask_OsTask_IndFun                                16
#define osMaxActivationCount_OsTask_IndFun                      1
#define osCategoryTask_OsTask_IndFun                            TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_IndFun                                TASK_BASIC

/********************* Task OsTask_LinFun*********************/	
#define osTaskFunction_OsTask_LinFun                            (osTaskFuncRefType)&OsTask_LinFunfunc
#define osStackStartAddressTask_OsTask_LinFun                   (osStackPtrType)osdOsTask_LinFun_TOP
#define osStackSizeTask_OsTask_LinFun                           sizeof(OsStack_OsTaskStackSharingDyn)
#define osPrioTask_OsTask_LinFun                                13
#define osMaxActivationCount_OsTask_LinFun                      1
#define osCategoryTask_OsTask_LinFun                            TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_LinFun                                TASK_BASIC

/********************* Task OsTask_Mcal*********************/	
#define osTaskFunction_OsTask_Mcal                              (osTaskFuncRefType)&OsTask_Mcalfunc
#define osStackStartAddressTask_OsTask_Mcal                     (osStackPtrType)osdOsTask_Mcal_TOP
#define osStackSizeTask_OsTask_Mcal                             sizeof(OsStack_OsTaskStackSharingDyn)
#define osPrioTask_OsTask_Mcal                                  5
#define osMaxActivationCount_OsTask_Mcal                        1
#define osCategoryTask_OsTask_Mcal                              TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_Mcal                                  TASK_BASIC

/********************* Task OsTask_ModeMgt*********************/	
#define osTaskFunction_OsTask_ModeMgt                           (osTaskFuncRefType)&OsTask_ModeMgtfunc
#define osStackStartAddressTask_OsTask_ModeMgt                  (osStackPtrType)osdOsTask_ModeMgt_TOP
#define osStackSizeTask_OsTask_ModeMgt                          sizeof(OsStack_OsTask_ModeMgtDyn)
#define osPrioTask_OsTask_ModeMgt                               1
#define osMaxActivationCount_OsTask_ModeMgt                     1
#define osCategoryTask_OsTask_ModeMgt                           TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_ModeMgt                               TASK_EXTENDED

/********************* Task OsTask_NvmSpeedup*********************/	
#define osTaskFunction_OsTask_NvmSpeedup                        (osTaskFuncRefType)&OsTask_NvmSpeedupfunc
#define osStackStartAddressTask_OsTask_NvmSpeedup               (osStackPtrType)osdOsTask_NvmSpeedup_TOP
#define osStackSizeTask_OsTask_NvmSpeedup                       sizeof(OsStack_OsTask_NvmSpeedupDyn)
#define osPrioTask_OsTask_NvmSpeedup                            19
#define osMaxActivationCount_OsTask_NvmSpeedup                  1
#define osCategoryTask_OsTask_NvmSpeedup                        TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_NvmSpeedup                            TASK_EXTENDED

/********************* Task OsTask_SafeApp*********************/	
#define osTaskFunction_OsTask_SafeApp                           (osTaskFuncRefType)&OsTask_SafeAppfunc
#define osStackStartAddressTask_OsTask_SafeApp                  (osStackPtrType)osdOsTask_SafeApp_TOP
#define osStackSizeTask_OsTask_SafeApp                          sizeof(OsStack_OsTaskStackSharingDyn)
#define osPrioTask_OsTask_SafeApp                               11
#define osMaxActivationCount_OsTask_SafeApp                     1
#define osCategoryTask_OsTask_SafeApp                           TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_SafeApp                               TASK_BASIC

/********************* Task OsTask_TripFun*********************/	
#define osTaskFunction_OsTask_TripFun                           (osTaskFuncRefType)&OsTask_TripFunfunc
#define osStackStartAddressTask_OsTask_TripFun                  (osStackPtrType)osdOsTask_TripFun_TOP
#define osStackSizeTask_OsTask_TripFun                          sizeof(OsStack_OsTaskStackSharingDyn)
#define osPrioTask_OsTask_TripFun                               20
#define osMaxActivationCount_OsTask_TripFun                     1
#define osCategoryTask_OsTask_TripFun                           TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_TripFun                               TASK_BASIC

/********************* Task OsTask_WarnFun*********************/	
#define osTaskFunction_OsTask_WarnFun                           (osTaskFuncRefType)&OsTask_WarnFunfunc
#define osStackStartAddressTask_OsTask_WarnFun                  (osStackPtrType)osdOsTask_WarnFun_TOP
#define osStackSizeTask_OsTask_WarnFun                          sizeof(OsStack_OsTaskStackSharingDyn)
#define osPrioTask_OsTask_WarnFun                               17
#define osMaxActivationCount_OsTask_WarnFun                     1
#define osCategoryTask_OsTask_WarnFun                           TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_WarnFun                               TASK_BASIC

/********************* Task OsTask_WdgMngt*********************/	
#define osTaskFunction_OsTask_WdgMngt                           (osTaskFuncRefType)&OsTask_WdgMngtfunc
#define osStackStartAddressTask_OsTask_WdgMngt                  (osStackPtrType)osdOsTask_WdgMngt_TOP
#define osStackSizeTask_OsTask_WdgMngt                          sizeof(OsStack_OsTaskStackSharingDyn)
#define osPrioTask_OsTask_WdgMngt                               3
#define osMaxActivationCount_OsTask_WdgMngt                     1
#define osCategoryTask_OsTask_WdgMngt                           TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_WdgMngt                               TASK_BASIC

/********************* Task OsTask_Diagnostics*********************/	
#define osTaskFunction_OsTask_Diagnostics                       (osTaskFuncRefType)&OsTask_Diagnosticsfunc
#define osStackStartAddressTask_OsTask_Diagnostics              (osStackPtrType)osdOsTask_Diagnostics_TOP
#define osStackSizeTask_OsTask_Diagnostics                      sizeof(OsStack_OsTask_DiagnosticsDyn)
#define osPrioTask_OsTask_Diagnostics                           14
#define osMaxActivationCount_OsTask_Diagnostics                 1
#define osCategoryTask_OsTask_Diagnostics                       TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_Diagnostics                           TASK_EXTENDED

/********************* Task OsTask_LSH_16ms*********************/	
#define osTaskFunction_OsTask_LSH_16ms                          (osTaskFuncRefType)&OsTask_LSH_16msfunc
#define osStackStartAddressTask_OsTask_LSH_16ms                 (osStackPtrType)osdOsTask_LSH_16ms_TOP
#define osStackSizeTask_OsTask_LSH_16ms                         sizeof(OsStack_OsTask_LSH_16msDyn)
#define osPrioTask_OsTask_LSH_16ms                              25
#define osMaxActivationCount_OsTask_LSH_16ms                    1
#define osCategoryTask_OsTask_LSH_16ms                          TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_LSH_16ms                              TASK_EXTENDED

/********************* Task OsTask_SafeBsw*********************/	
#define osTaskFunction_OsTask_SafeBsw                           (osTaskFuncRefType)&OsTask_SafeBswfunc
#define osStackStartAddressTask_OsTask_SafeBsw                  (osStackPtrType)osdOsTask_SafeBsw_TOP
#define osStackSizeTask_OsTask_SafeBsw                          sizeof(OsStack_OsTask_SafeBswDyn)
#define osPrioTask_OsTask_SafeBsw                               10
#define osMaxActivationCount_OsTask_SafeBsw                     1
#define osCategoryTask_OsTask_SafeBsw                           TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_SafeBsw                               TASK_EXTENDED

/********************* Task OsTask_MemSer*********************/	
#define osTaskFunction_OsTask_MemSer                            (osTaskFuncRefType)&OsTask_MemSerfunc
#define osStackStartAddressTask_OsTask_MemSer                   (osStackPtrType)osdOsTask_MemSer_TOP
#define osStackSizeTask_OsTask_MemSer                           sizeof(OsStack_OsTask_MemSerDyn)
#define osPrioTask_OsTask_MemSer                                4
#define osMaxActivationCount_OsTask_MemSer                      1
#define osCategoryTask_OsTask_MemSer                            TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_MemSer                                TASK_EXTENDED

/********************* Task OsTask_IpcUclEv*********************/	
#define osTaskFunction_OsTask_IpcUclEv                          (osTaskFuncRefType)&OsTask_IpcUclEvfunc
#define osStackStartAddressTask_OsTask_IpcUclEv                 (osStackPtrType)osdOsTask_IpcUclEv_TOP
#define osStackSizeTask_OsTask_IpcUclEv                         sizeof(OsStack_OsTask_IpcUclEvDyn)
#define osPrioTask_OsTask_IpcUclEv                              18
#define osMaxActivationCount_OsTask_IpcUclEv                    1
#define osCategoryTask_OsTask_IpcUclEv                          TASK_NONPREEMPTIVE
#define osTypeTask_OsTask_IpcUclEv                              TASK_EXTENDED

/********************* Task OsTaskRender*********************/	
#define osTaskFunction_OsTaskRender                             (osTaskFuncRefType)&OsTaskRenderfunc
#define osStackStartAddressTask_OsTaskRender                    (osStackPtrType)osdOsTaskRender_TOP
#define osStackSizeTask_OsTaskRender                            sizeof(OsStack_OsTaskRenderDyn)
#define osPrioTask_OsTaskRender                                 24
#define osMaxActivationCount_OsTaskRender                       1
#define osCategoryTask_OsTaskRender                             TASK_PREEMPTIVE
#define osTypeTask_OsTaskRender                                 TASK_EXTENDED


#define OsNumberOfAutoStartTasks                          3


#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

