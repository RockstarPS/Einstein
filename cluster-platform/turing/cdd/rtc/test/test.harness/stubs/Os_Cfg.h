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
                                                                              
                                                                              
                                                                              
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
*****************************************************************************/



/******** OS Hook Routines are Enabled *************************************/
#define OS_CFG_SUPPORT_DBG_HOOKS


/******** OS MemMap are Enabled *******************************/
#define OS_CFG_MEMMAP_ENABLED

#define OsNumberOfTasks              13
#define OsNumberOfAlarms             21
#define OsMaxPriorityLevel           13
#define OsNumberOfAutoStartTasks     2
#define osMaxCounterId               2




#define OsCounter_0                         ((CounterType) 0)
#define OsCounter_1                         ((CounterType) 1)


#define osdTimerReloadValue          
#define osdTimerChannel              
#define CC_TYPE                      ECC1
#define OS_MS2TICKS_SystemTimer(x)     ( (TickType) (((((uint32)(x)) * 1) + 0) / 1) )


/*****************************************************************************
*                        Task Ids                                            *
*****************************************************************************/
#define InitTask                  ((TaskType)0)
#define OsTask_IdleTask                  ((TaskType)1)
#define OsTask_10ms_SWC                  ((TaskType)2)
#define OsTask_20ms_SWC                  ((TaskType)3)
#define OsTask_50ms_SWC                  ((TaskType)4)
#define OsTask_BswCtrl_10ms                  ((TaskType)5)
#define OsTask_Bsw_10ms                  ((TaskType)6)
#define OsTask_Comm1_10ms                  ((TaskType)7)
#define OsTask_NvmSpeedup_10ms                  ((TaskType)8)
#define OsTask_UclProxyEvent_10ms                  ((TaskType)9)
#define OsTask_Ucl_4ms                  ((TaskType)10)
#define SampleTask                  ((TaskType)11)
#define OsTask_CDD_10ms                  ((TaskType)12)


/* Alarms */

#define Rte_Al_TE2_OsTask_BswCtrl_10ms_0_10ms (0U)
#define Rte_Al_TE2_OsTask_Bsw_10ms_0_10ms (1U)
#define Rte_Al_TE2_OsTask_Bsw_10ms_2_10ms (2U)
#define Rte_Al_TE2_OsTask_Comm1_10ms_0_10ms (3U)
#define Rte_Al_TE2_OsTask_Comm1_10ms_0_20ms (4U)
#define Rte_Al_TE_COATMdl_COATMdl_Impl_MainFunction (5U)
#define Rte_Al_TE_CanSM_CanSM_MainFunction (6U)
#define Rte_Al_TE_EcumExt_EcumExt_NvM_ReadAll_SpeedUp (7U)
#define Rte_Al_TE_LinCdd_CLinCdd_Impl_MainFunction (8U)
#define Rte_Al_TE_MemAbstractStub_MemAbstract_MainFunction (9U)
#define Rte_Al_TE_OsTask_10ms_SWC_0_10ms (10U)
#define Rte_Al_TE_OsTask_10ms_SWC_0_20ms (11U)
#define Rte_Al_TE_OsTask_20ms_SWC_0_20ms (12U)
#define Rte_Al_TE_OsTask_50ms_SWC_0_10ms (13U)
#define Rte_Al_TE_OsTask_BswCtrl_10ms_0_10ms (14U)
#define Rte_Al_TE_OsTask_Bsw_10ms_0_10ms (15U)
#define Rte_Al_TE_OsTask_Comm1_10ms_0_10ms (16U)
#define Rte_Al_TE_Rte_Rte_ComSendSignalProxyPeriodic (17U)
#define Rte_Al_TE_SeatbeltMdl_CSeatbeltMdl_Impl_MainFunction (18U)
#define Rte_Al_TE_TimeMdl_CTimeMdl_Impl_MainFunction (19U)
#define Rte_Al_TE_UclProxyCdd_CUclProxyCdd_Impl_MainFunction (20U)


/* Events */

# define Rte_Ev_Cyclic2_OsTask_BswCtrl_10ms_0_10ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic2_OsTask_Bsw_10ms_0_10ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic2_OsTask_Bsw_10ms_2_10ms     ((EventMaskType)2ULL)
# define Rte_Ev_Cyclic2_OsTask_Comm1_10ms_0_10ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic2_OsTask_Comm1_10ms_0_20ms     ((EventMaskType)2ULL)
# define Rte_Ev_Cyclic_OsTask_10ms_SWC_0_10ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic_OsTask_10ms_SWC_0_20ms     ((EventMaskType)2ULL)
# define Rte_Ev_Cyclic_OsTask_20ms_SWC_0_20ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic_OsTask_50ms_SWC_0_10ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic_OsTask_BswCtrl_10ms_0_10ms     ((EventMaskType)2ULL)
# define Rte_Ev_Cyclic_OsTask_Bsw_10ms_0_10ms     ((EventMaskType)4ULL)
# define Rte_Ev_Cyclic_OsTask_Comm1_10ms_0_10ms     ((EventMaskType)4ULL)
# define Rte_Ev_Run_COATMdl_COATMdl_Impl_MainFunction     ((EventMaskType)2ULL)
# define Rte_Ev_Run_CanSM_CanSM_MainFunction     ((EventMaskType)8ULL)
# define Rte_Ev_Run_LinCdd_CLinCdd_Impl_MainFunction     ((EventMaskType)1ULL)
# define Rte_Ev_Run_MemAbstractStub_MemAbstract_MainFunction     ((EventMaskType)1ULL)
# define Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable     ((EventMaskType)4ULL)
# define Rte_Ev_Run_Rte_Rte_ComSendSignalProxyPeriodic     ((EventMaskType)4ULL)
# define Rte_Ev_Run_SeatbeltMdl_CSeatbeltMdl_Impl_MainFunction     ((EventMaskType)4ULL)
# define Rte_Ev_Run_TimeMdl_CTimeMdl_Impl_MainFunction     ((EventMaskType)2ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DkMsgButtonState     ((EventMaskType)1ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DkMsgChime     ((EventMaskType)2ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DkMsgDimmingEnable     ((EventMaskType)4ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DkMsgDimmingSetBacklight     ((EventMaskType)8ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DkMsgDimmingSetMaxBrightness     ((EventMaskType)16ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DkMsgDimmingSetMode     ((EventMaskType)32ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DkMsgLinCdd     ((EventMaskType)64ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DkMsgPowerMode     ((EventMaskType)128ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DkMsgPowerSystemStateReqChange     ((EventMaskType)256ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DkMsgTT     ((EventMaskType)512ULL)
# define Rte_Ev_Run_UclProxyCdd_OnDre_DkMsgWarning     ((EventMaskType)1024ULL)
# define Rte_Ev_Run_Upcl_CUpcl_OnDre_BCANSleepModeMsgTT     ((EventMaskType)2048ULL)
# define Rte_Ev_Run_Upcl_CUpcl_OnDre_IgnMsgTT     ((EventMaskType)4096ULL)
# define Rte_Ev_Run_Upcl_CUpcl_OnDre_ImmoBiMsgTT     ((EventMaskType)8192ULL)
# define Rte_Ev_Run_Upcl_CUpcl_OnDre_StandardMsgTT     ((EventMaskType)16384ULL)
# define Rte_Ev_Run_Upcl_CUpcl_OnDre_UltrasonicMsgTT     ((EventMaskType)32768ULL)


/* Schedule Tables */
#define MainScheduleTable_OsTask_NvM_Stack (0U)
/*****************************************************************************
*                           Auto Start Task Ids                              *
******************************************************************************/
#define OsTaskAutoStart_0                InitTask
#define OsTaskAutoStart_1                OsTask_IdleTask


/*****************************************************************************
*                                  Task Table                                *
******************************************************************************/


/********************* Task 0*********************/

#define osStartAddressTask_0                (osTaskFuncRefType)&InitTaskfunc
#define osStackStartAddressTask_0           (osStackPtrType)osdInitTask_TOP
#define osStackSizeTask_0                   sizeof(osTaskStackOsApplication0)
#define osPrioTask_0                        0
#define osMaxActivationCount_0              10
#define osCategoryTask_0                    TASK_NONPREEMPTIVE


/********************* Task 1*********************/

#define osStartAddressTask_1                (osTaskFuncRefType)&OsTask_IdleTaskfunc
#define osStackStartAddressTask_1           (osStackPtrType)osdOsTask_IdleTask_TOP
#define osStackSizeTask_1                   sizeof(osTaskStackOsApplication1)
#define osPrioTask_1                        12
#define osMaxActivationCount_1              10
#define osCategoryTask_1                    TASK_PREEMPTIVE


/********************* Task 2*********************/

#define osStartAddressTask_2                (osTaskFuncRefType)&OsTask_10ms_SWCfunc
#define osStackStartAddressTask_2           (osStackPtrType)osdOsTask_10ms_SWC_TOP
#define osStackSizeTask_2                   sizeof(osTaskStackOsApplication2)
#define osPrioTask_2                        6
#define osMaxActivationCount_2              10
#define osCategoryTask_2                    TASK_NONPREEMPTIVE


/********************* Task 3*********************/

#define osStartAddressTask_3                (osTaskFuncRefType)&OsTask_20ms_SWCfunc
#define osStackStartAddressTask_3           (osStackPtrType)osdOsTask_20ms_SWC_TOP
#define osStackSizeTask_3                   sizeof(osTaskStackOsApplication3)
#define osPrioTask_3                        9
#define osMaxActivationCount_3              10
#define osCategoryTask_3                    TASK_NONPREEMPTIVE


/********************* Task 4*********************/

#define osStartAddressTask_4                (osTaskFuncRefType)&OsTask_50ms_SWCfunc
#define osStackStartAddressTask_4           (osStackPtrType)osdOsTask_50ms_SWC_TOP
#define osStackSizeTask_4                   sizeof(osTaskStackOsApplication4)
#define osPrioTask_4                        10
#define osMaxActivationCount_4              10
#define osCategoryTask_4                    TASK_NONPREEMPTIVE


/********************* Task 5*********************/

#define osStartAddressTask_5                (osTaskFuncRefType)&OsTask_BswCtrl_10msfunc
#define osStackStartAddressTask_5           (osStackPtrType)osdOsTask_BswCtrl_10ms_TOP
#define osStackSizeTask_5                   sizeof(osTaskStackOsApplication5)
#define osPrioTask_5                        1
#define osMaxActivationCount_5              10
#define osCategoryTask_5                    TASK_NONPREEMPTIVE


/********************* Task 6*********************/

#define osStartAddressTask_6                (osTaskFuncRefType)&OsTask_Bsw_10msfunc
#define osStackStartAddressTask_6           (osStackPtrType)osdOsTask_Bsw_10ms_TOP
#define osStackSizeTask_6                   sizeof(osTaskStackOsApplication6)
#define osPrioTask_6                        2
#define osMaxActivationCount_6              10
#define osCategoryTask_6                    TASK_NONPREEMPTIVE


/********************* Task 7*********************/

#define osStartAddressTask_7                (osTaskFuncRefType)&OsTask_Comm1_10msfunc
#define osStackStartAddressTask_7           (osStackPtrType)osdOsTask_Comm1_10ms_TOP
#define osStackSizeTask_7                   sizeof(osTaskStackOsApplication7)
#define osPrioTask_7                        3
#define osMaxActivationCount_7              10
#define osCategoryTask_7                    TASK_NONPREEMPTIVE


/********************* Task 8*********************/

#define osStartAddressTask_8                (osTaskFuncRefType)&OsTask_NvmSpeedup_10msfunc
#define osStackStartAddressTask_8           (osStackPtrType)osdOsTask_NvmSpeedup_10ms_TOP
#define osStackSizeTask_8                   sizeof(osTaskStackOsApplication8)
#define osPrioTask_8                        11
#define osMaxActivationCount_8              10
#define osCategoryTask_8                    TASK_NONPREEMPTIVE


/********************* Task 9*********************/

#define osStartAddressTask_9                (osTaskFuncRefType)&OsTask_UclProxyEvent_10msfunc
#define osStackStartAddressTask_9           (osStackPtrType)osdOsTask_UclProxyEvent_10ms_TOP
#define osStackSizeTask_9                   sizeof(osTaskStackOsApplication9)
#define osPrioTask_9                        5
#define osMaxActivationCount_9              10
#define osCategoryTask_9                    TASK_NONPREEMPTIVE


/********************* Task 10*********************/

#define osStartAddressTask_10                (osTaskFuncRefType)&OsTask_Ucl_4msfunc
#define osStackStartAddressTask_10           (osStackPtrType)osdOsTask_Ucl_4ms_TOP
#define osStackSizeTask_10                   sizeof(osTaskStackOsApplication10)
#define osPrioTask_10                        4
#define osMaxActivationCount_10              10
#define osCategoryTask_10                    TASK_NONPREEMPTIVE


/********************* Task 11*********************/

#define osStartAddressTask_11                (osTaskFuncRefType)&SampleTaskfunc
#define osStackStartAddressTask_11           (osStackPtrType)osdSampleTask_TOP
#define osStackSizeTask_11                   sizeof(osTaskStackOsApplication11)
#define osPrioTask_11                        7
#define osMaxActivationCount_11              10
#define osCategoryTask_11                    TASK_NONPREEMPTIVE


/********************* Task 12*********************/

#define osStartAddressTask_12                (osTaskFuncRefType)&OsTask_CDD_10msfunc
#define osStackStartAddressTask_12           (osStackPtrType)osdOsTask_CDD_10ms_TOP
#define osStackSizeTask_12                   sizeof(osTaskStackOsApplication12)
#define osPrioTask_12                        8
#define osMaxActivationCount_12              10
#define osCategoryTask_12                    TASK_NONPREEMPTIVE


/*****************************************************************************
*                                 Alarm Table                                *
******************************************************************************/


/********************** Alarm 0 ***********************/
#define osCbkOfAlarm_0                    NULL
#define osTaskIdOfAlarm_0                 OsTask_BswCtrl_10ms
#define osActionOfAlarm_0                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_0                Rte_Ev_Cyclic2_OsTask_BswCtrl_10ms_0_10ms
/********************** Alarm 1 ***********************/
#define osCbkOfAlarm_1                    NULL
#define osTaskIdOfAlarm_1                 OsTask_Bsw_10ms
#define osActionOfAlarm_1                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_1                Rte_Ev_Cyclic2_OsTask_Bsw_10ms_0_10ms
/********************** Alarm 2 ***********************/
#define osCbkOfAlarm_2                    NULL
#define osTaskIdOfAlarm_2                 OsTask_Bsw_10ms
#define osActionOfAlarm_2                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_2                Rte_Ev_Cyclic2_OsTask_Bsw_10ms_2_10ms
/********************** Alarm 3 ***********************/
#define osCbkOfAlarm_3                    NULL
#define osTaskIdOfAlarm_3                 OsTask_Comm1_10ms
#define osActionOfAlarm_3                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_3                Rte_Ev_Cyclic2_OsTask_Comm1_10ms_0_10ms
/********************** Alarm 4 ***********************/
#define osCbkOfAlarm_4                    NULL
#define osTaskIdOfAlarm_4                 OsTask_Comm1_10ms
#define osActionOfAlarm_4                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_4                Rte_Ev_Cyclic2_OsTask_Comm1_10ms_0_20ms
/********************** Alarm 5 ***********************/
#define osCbkOfAlarm_5                    NULL
#define osTaskIdOfAlarm_5                 OsTask_20ms_SWC
#define osActionOfAlarm_5                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_5                Rte_Ev_Run_COATMdl_COATMdl_Impl_MainFunction
/********************** Alarm 6 ***********************/
#define osCbkOfAlarm_6                    NULL
#define osTaskIdOfAlarm_6                 OsTask_Comm1_10ms
#define osActionOfAlarm_6                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_6                Rte_Ev_Run_CanSM_CanSM_MainFunction
/********************** Alarm 7 ***********************/
#define osCbkOfAlarm_7                    NULL
#define osTaskIdOfAlarm_7                 OsTask_NvmSpeedup_10ms
#define osActionOfAlarm_7                 ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_7                0
/********************** Alarm 8 ***********************/
#define osCbkOfAlarm_8                    NULL
#define osTaskIdOfAlarm_8                 OsTask_CDD_10ms
#define osActionOfAlarm_8                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_8                Rte_Ev_Run_LinCdd_CLinCdd_Impl_MainFunction
/********************** Alarm 9 ***********************/
#define osCbkOfAlarm_9                    NULL
#define osTaskIdOfAlarm_9                 SampleTask
#define osActionOfAlarm_9                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_9                Rte_Ev_Run_MemAbstractStub_MemAbstract_MainFunction
/********************** Alarm 10 ***********************/
#define osCbkOfAlarm_10                    NULL
#define osTaskIdOfAlarm_10                 OsTask_10ms_SWC
#define osActionOfAlarm_10                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_10                Rte_Ev_Cyclic_OsTask_10ms_SWC_0_10ms
/********************** Alarm 11 ***********************/
#define osCbkOfAlarm_11                    NULL
#define osTaskIdOfAlarm_11                 OsTask_10ms_SWC
#define osActionOfAlarm_11                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_11                Rte_Ev_Cyclic_OsTask_10ms_SWC_0_20ms
/********************** Alarm 12 ***********************/
#define osCbkOfAlarm_12                    NULL
#define osTaskIdOfAlarm_12                 OsTask_20ms_SWC
#define osActionOfAlarm_12                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_12                Rte_Ev_Cyclic_OsTask_20ms_SWC_0_20ms
/********************** Alarm 13 ***********************/
#define osCbkOfAlarm_13                    NULL
#define osTaskIdOfAlarm_13                 OsTask_50ms_SWC
#define osActionOfAlarm_13                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_13                Rte_Ev_Cyclic_OsTask_50ms_SWC_0_10ms
/********************** Alarm 14 ***********************/
#define osCbkOfAlarm_14                    NULL
#define osTaskIdOfAlarm_14                 OsTask_BswCtrl_10ms
#define osActionOfAlarm_14                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_14                Rte_Ev_Cyclic_OsTask_BswCtrl_10ms_0_10ms
/********************** Alarm 15 ***********************/
#define osCbkOfAlarm_15                    NULL
#define osTaskIdOfAlarm_15                 OsTask_Bsw_10ms
#define osActionOfAlarm_15                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_15                Rte_Ev_Cyclic_OsTask_Bsw_10ms_0_10ms
/********************** Alarm 16 ***********************/
#define osCbkOfAlarm_16                    NULL
#define osTaskIdOfAlarm_16                 OsTask_Comm1_10ms
#define osActionOfAlarm_16                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_16                Rte_Ev_Cyclic_OsTask_Comm1_10ms_0_10ms
/********************** Alarm 17 ***********************/
#define osCbkOfAlarm_17                    NULL
#define osTaskIdOfAlarm_17                 OsTask_10ms_SWC
#define osActionOfAlarm_17                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_17                Rte_Ev_Run_Rte_Rte_ComSendSignalProxyPeriodic
/********************** Alarm 18 ***********************/
#define osCbkOfAlarm_18                    NULL
#define osTaskIdOfAlarm_18                 OsTask_20ms_SWC
#define osActionOfAlarm_18                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_18                Rte_Ev_Run_SeatbeltMdl_CSeatbeltMdl_Impl_MainFunction
/********************** Alarm 19 ***********************/
#define osCbkOfAlarm_19                    NULL
#define osTaskIdOfAlarm_19                 OsTask_50ms_SWC
#define osActionOfAlarm_19                 ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_19                Rte_Ev_Run_TimeMdl_CTimeMdl_Impl_MainFunction
/********************** Alarm 20 ***********************/
#define osCbkOfAlarm_20                    NULL
#define osTaskIdOfAlarm_20                 OsTask_Ucl_4ms
#define osActionOfAlarm_20                 ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_20                0


/*****************************************************************************
*                               Isr Stack Table                              *
******************************************************************************/


#define osStackStartAddressIsr_0           (osStackPtrType)osdSystemTimerISR_TOP
#define osStackSizeIsr_0                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_1           (osStackPtrType)osdI2c3_INT_TOP
#define osStackSizeIsr_1                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_2           (osStackPtrType)osdCan_ISR_A_TOP
#define osStackSizeIsr_2                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_3           (osStackPtrType)osdCan_ISR_C_TOP
#define osStackSizeIsr_3                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_4           (osStackPtrType)osdIRQSTEER_EXT_1_ISR_TOP
#define osStackSizeIsr_4                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_5           (osStackPtrType)osdCan_ISR_B_TOP
#define osStackSizeIsr_5                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_6           (osStackPtrType)osdADC_ISR_0_TOP
#define osStackSizeIsr_6                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_7           (osStackPtrType)osdUART3_INT_TOP
#define osStackSizeIsr_7                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_8           (osStackPtrType)osdUART2_INT_TOP
#define osStackSizeIsr_8                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_9           (osStackPtrType)osdGPT_2_TOP
#define osStackSizeIsr_9                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_10           (osStackPtrType)osdGPT_4_TOP
#define osStackSizeIsr_10                   (osStackDataType)sizeof(osLevelStackCore0Level1)

#define osStackStartAddressIsr_11           (osStackPtrType)osdGPT_5_TOP
#define osStackSizeIsr_11                   (osStackDataType)sizeof(osLevelStackCore0Level1)



/*****************************************************************************
*                                 Type Declarations                          *
*****************************************************************************/
                                                                              
/* OS type definitions */
/* Begin osTypeDefinitions (default) */
#ifndef osTypesDefined
#define osTypesDefined
typedef unsigned char  osuint8;
typedef unsigned short osuint16;
typedef unsigned long  osuint32;
typedef unsigned long  long osuint64;
typedef signed   char  osint8;
typedef signed   short osint16;
typedef signed   long  osint32;
typedef signed   long  long osint64;
/* End osTypeDefinitions */
#endif


//to be generated for cpu specific
typedef osuint32        osCpuStackType;
typedef osuint32        osCpuTaskAddressType;
typedef osuint32        osCpuTaskPriorityBitType;
typedef osuint32        osCpuIntGlobalType;


/* Task function prototypes */

void InitTaskfunc(void);
void OsTask_IdleTaskfunc(void);
void OsTask_10ms_SWCfunc(void);
void OsTask_20ms_SWCfunc(void);
void OsTask_50ms_SWCfunc(void);
void OsTask_BswCtrl_10msfunc(void);
void OsTask_Bsw_10msfunc(void);
void OsTask_Comm1_10msfunc(void);
void OsTask_NvmSpeedup_10msfunc(void);
void OsTask_UclProxyEvent_10msfunc(void);
void OsTask_Ucl_4msfunc(void);
void SampleTaskfunc(void);
void OsTask_CDD_10msfunc(void);


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
Created Time: 14-09-2020 16:23:57
****************************************************************/
