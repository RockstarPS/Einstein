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
*    @file Os_Alarm_Cfg.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by SGOPAL1 at 2026-03-31 13:17:24.279153700
********************************************************************************************************************/

#ifndef OS_ALARMCFG_H
#define OS_ALARMCFG_H


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/



/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
*****************************************************************************/

#define OsNumberOfAlarms                                  35U

/* Alarms */
#define Rte_Al_TE2_OsTask_CANFun_0_10ms                   (0U)
#define Rte_Al_TE2_OsTask_Diagnostics_0_10ms              (1U)
#define Rte_Al_TE2_OsTask_Mcal_10msLP_0_10ms              (2U)
#define Rte_Al_TE2_OsTask_MemSer_0_10ms                   (3U)
#define Rte_Al_TE2_OsTask_ModeMgt_0_10ms                  (4U)
#define Rte_Al_TE2_OsTask_ModeMgt_5msLP_0_5ms             (5U)
#define Rte_Al_TE2_OsTask_SafeBsw_0_10ms                  (6U)
#define Rte_Al_TE_DmnMgr_CDmnMgr_Impl_MainFunction        (7U)
#define Rte_Al_TE_Ea_Ea_MainFunction                      (8U)
#define Rte_Al_TE_IoHwAb_IoHwAb_OsTask_SafeBsw_WdgM_CheckPoint_20ms          (9U)
#define Rte_Al_TE_NvMExt_NvMExt_SpeedupRunnable           (10U)
#define Rte_Al_TE_OsTask_AppFun_0_10ms                    (11U)
#define Rte_Al_TE_OsTask_CANFun_0_10ms                    (12U)
#define Rte_Al_TE_OsTask_Diagnostics_0_100ms              (13U)
#define Rte_Al_TE_OsTask_Diagnostics_0_10ms               (14U)
#define Rte_Al_TE_OsTask_Diagnostics_0_20ms               (15U)
#define Rte_Al_TE_OsTask_DispFun_0_10ms                   (16U)
#define Rte_Al_TE_OsTask_DispFun_0_5ms                    (17U)
#define Rte_Al_TE_OsTask_EthFun_0_10ms                    (18U)
#define Rte_Al_TE_OsTask_GaugeFun_0_20ms                  (19U)
#define Rte_Al_TE_OsTask_IndFun_0_30ms                    (20U)
#define Rte_Al_TE_OsTask_LSH_16ms_0_16ms                  (21U)
#define Rte_Al_TE_OsTask_Mcal_0_10ms                      (22U)
#define Rte_Al_TE_OsTask_MemSer_0_10ms                    (23U)
#define Rte_Al_TE_OsTask_ModeMgt_0_10ms                   (24U)
#define Rte_Al_TE_OsTask_SafeApp_0_30ms                   (25U)
#define Rte_Al_TE_OsTask_SafeBsw_0_10ms                   (26U)
#define Rte_Al_TE_OsTask_TripFun_0_50ms                   (27U)
#define Rte_Al_TE_OsTask_WarnFun_0_32ms                   (28U)
#define Rte_Al_TE_OsTask_WdgMngt_0_10ms                   (29U)
#define Rte_Al_TE_SlowGaugeAdapter_SlowGaugeAdapter_Task  (30U)
#define Rte_Al_TE_Test_Comp_AudioTaskStubRunnable         (31U)
#define Rte_Al_TE_Test_Comp_FotaTaskStubRunnable          (32U)
#define Rte_Al_TE_Test_Comp_LinTaskStubRunnable           (33U)
#define Rte_Al_TE_UclProxyCdd_CUclProxyCdd_Impl_MainFunction          (34U)

/* Num of applications in alarm */
#define OsNumberOfApplicationsAlarm0                        0
#define OsNumberOfApplicationsAlarm1                        0
#define OsNumberOfApplicationsAlarm2                        0
#define OsNumberOfApplicationsAlarm3                        0
#define OsNumberOfApplicationsAlarm4                        0
#define OsNumberOfApplicationsAlarm5                        0
#define OsNumberOfApplicationsAlarm6                        0
#define OsNumberOfApplicationsAlarm7                        0
#define OsNumberOfApplicationsAlarm8                        0
#define OsNumberOfApplicationsAlarm9                        0
#define OsNumberOfApplicationsAlarm10                       0
#define OsNumberOfApplicationsAlarm11                       0
#define OsNumberOfApplicationsAlarm12                       0
#define OsNumberOfApplicationsAlarm13                       0
#define OsNumberOfApplicationsAlarm14                       0
#define OsNumberOfApplicationsAlarm15                       0
#define OsNumberOfApplicationsAlarm16                       0
#define OsNumberOfApplicationsAlarm17                       0
#define OsNumberOfApplicationsAlarm18                       0
#define OsNumberOfApplicationsAlarm19                       0
#define OsNumberOfApplicationsAlarm20                       0
#define OsNumberOfApplicationsAlarm21                       0
#define OsNumberOfApplicationsAlarm22                       0
#define OsNumberOfApplicationsAlarm23                       0
#define OsNumberOfApplicationsAlarm24                       0
#define OsNumberOfApplicationsAlarm25                       0
#define OsNumberOfApplicationsAlarm26                       0
#define OsNumberOfApplicationsAlarm27                       0
#define OsNumberOfApplicationsAlarm28                       0
#define OsNumberOfApplicationsAlarm29                       0
#define OsNumberOfApplicationsAlarm30                       0
#define OsNumberOfApplicationsAlarm31                       0
#define OsNumberOfApplicationsAlarm32                       0
#define OsNumberOfApplicationsAlarm33                       0
#define OsNumberOfApplicationsAlarm34                       0


/*****************************************************************************
*                                 Alarm Table                                *
******************************************************************************/


/********************* Alarm 0 Rte_Al_TE2_OsTask_CANFun_0_10ms *********************/	

#define osCounterIdOfAlarm_0                    SystemTimer
#define osActivateTaskIdOfAlarm_0               NULL
#define osCbkOfAlarm_0                          NULL
#define osTaskIdOfAlarm_0                       OsTask_CANFun
#define osActionOfAlarm_0                       ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_0                      Rte_Ev_Cyclic2_OsTask_CANFun_0_10ms

/********************* Alarm 1 Rte_Al_TE2_OsTask_Diagnostics_0_10ms *********************/	

#define osCounterIdOfAlarm_1                    SystemTimer
#define osActivateTaskIdOfAlarm_1               NULL
#define osCbkOfAlarm_1                          NULL
#define osTaskIdOfAlarm_1                       OsTask_Diagnostics
#define osActionOfAlarm_1                       ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_1                      Rte_Ev_Cyclic2_OsTask_Diagnostics_0_10ms

/********************* Alarm 2 Rte_Al_TE2_OsTask_Mcal_10msLP_0_10ms *********************/	

#define osCounterIdOfAlarm_2                    SystemTimer
#define osActivateTaskIdOfAlarm_2               OsTask_Mcal
#define osCbkOfAlarm_2                          NULL
#define osTaskIdOfAlarm_2                       NULL
#define osActionOfAlarm_2                       ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_2                      NULL

/********************* Alarm 3 Rte_Al_TE2_OsTask_MemSer_0_10ms *********************/	

#define osCounterIdOfAlarm_3                    SystemTimer
#define osActivateTaskIdOfAlarm_3               NULL
#define osCbkOfAlarm_3                          NULL
#define osTaskIdOfAlarm_3                       OsTask_MemSer
#define osActionOfAlarm_3                       ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_3                      Rte_Ev_Cyclic2_OsTask_MemSer_0_10ms

/********************* Alarm 4 Rte_Al_TE2_OsTask_ModeMgt_0_10ms *********************/	

#define osCounterIdOfAlarm_4                    SystemTimer
#define osActivateTaskIdOfAlarm_4               NULL
#define osCbkOfAlarm_4                          NULL
#define osTaskIdOfAlarm_4                       OsTask_ModeMgt
#define osActionOfAlarm_4                       ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_4                      Rte_Ev_Cyclic2_OsTask_ModeMgt_0_10ms

/********************* Alarm 5 Rte_Al_TE2_OsTask_ModeMgt_5msLP_0_5ms *********************/	

#define osCounterIdOfAlarm_5                    SystemTimer
#define osActivateTaskIdOfAlarm_5               OsTask_ModeMgt
#define osCbkOfAlarm_5                          NULL
#define osTaskIdOfAlarm_5                       NULL
#define osActionOfAlarm_5                       ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_5                      NULL

/********************* Alarm 6 Rte_Al_TE2_OsTask_SafeBsw_0_10ms *********************/	

#define osCounterIdOfAlarm_6                    SystemTimer
#define osActivateTaskIdOfAlarm_6               NULL
#define osCbkOfAlarm_6                          NULL
#define osTaskIdOfAlarm_6                       OsTask_SafeBsw
#define osActionOfAlarm_6                       ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_6                      Rte_Ev_Cyclic2_OsTask_SafeBsw_0_10ms

/********************* Alarm 7 Rte_Al_TE_DmnMgr_CDmnMgr_Impl_MainFunction *********************/	

#define osCounterIdOfAlarm_7                    SystemTimer
#define osActivateTaskIdOfAlarm_7               NULL
#define osCbkOfAlarm_7                          NULL
#define osTaskIdOfAlarm_7                       OsTask_IpcUclEv
#define osActionOfAlarm_7                       ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_7                      Rte_Ev_Run_DmnMgr_CDmnMgr_Impl_MainFunction

/********************* Alarm 8 Rte_Al_TE_Ea_Ea_MainFunction *********************/	

#define osCounterIdOfAlarm_8                    SystemTimer
#define osActivateTaskIdOfAlarm_8               NULL
#define osCbkOfAlarm_8                          NULL
#define osTaskIdOfAlarm_8                       OsTask_MemSer
#define osActionOfAlarm_8                       ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_8                      Rte_Ev_Run_Ea_Ea_MainFunction

/********************* Alarm 9 Rte_Al_TE_IoHwAb_IoHwAb_OsTask_SafeBsw_WdgM_CheckPoint_20ms *********************/	

#define osCounterIdOfAlarm_9                    SystemTimer
#define osActivateTaskIdOfAlarm_9               NULL
#define osCbkOfAlarm_9                          NULL
#define osTaskIdOfAlarm_9                       OsTask_SafeBsw
#define osActionOfAlarm_9                       ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_9                      Rte_Ev_Run_IoHwAb_IoHwAb_OsTask_SafeBsw_WdgM_CheckPoint_20ms

/********************* Alarm 10 Rte_Al_TE_NvMExt_NvMExt_SpeedupRunnable *********************/	

#define osCounterIdOfAlarm_10                   SystemTimer
#define osActivateTaskIdOfAlarm_10              NULL
#define osCbkOfAlarm_10                         NULL
#define osTaskIdOfAlarm_10                      OsTask_NvmSpeedup
#define osActionOfAlarm_10                      ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_10                     Rte_Ev_Run_NvMExt_NvMExt_SpeedupRunnable

/********************* Alarm 11 Rte_Al_TE_OsTask_AppFun_0_10ms *********************/	

#define osCounterIdOfAlarm_11                   SystemTimer
#define osActivateTaskIdOfAlarm_11              OsTask_AppFun
#define osCbkOfAlarm_11                         NULL
#define osTaskIdOfAlarm_11                      NULL
#define osActionOfAlarm_11                      ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_11                     NULL

/********************* Alarm 12 Rte_Al_TE_OsTask_CANFun_0_10ms *********************/	

#define osCounterIdOfAlarm_12                   SystemTimer
#define osActivateTaskIdOfAlarm_12              NULL
#define osCbkOfAlarm_12                         NULL
#define osTaskIdOfAlarm_12                      OsTask_CANFun
#define osActionOfAlarm_12                      ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_12                     Rte_Ev_Cyclic_OsTask_CANFun_0_10ms

/********************* Alarm 13 Rte_Al_TE_OsTask_Diagnostics_0_100ms *********************/	

#define osCounterIdOfAlarm_13                   SystemTimer
#define osActivateTaskIdOfAlarm_13              NULL
#define osCbkOfAlarm_13                         NULL
#define osTaskIdOfAlarm_13                      OsTask_Diagnostics
#define osActionOfAlarm_13                      ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_13                     Rte_Ev_Cyclic_OsTask_Diagnostics_0_100ms

/********************* Alarm 14 Rte_Al_TE_OsTask_Diagnostics_0_10ms *********************/	

#define osCounterIdOfAlarm_14                   SystemTimer
#define osActivateTaskIdOfAlarm_14              NULL
#define osCbkOfAlarm_14                         NULL
#define osTaskIdOfAlarm_14                      OsTask_Diagnostics
#define osActionOfAlarm_14                      ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_14                     Rte_Ev_Cyclic_OsTask_Diagnostics_0_10ms

/********************* Alarm 15 Rte_Al_TE_OsTask_Diagnostics_0_20ms *********************/	

#define osCounterIdOfAlarm_15                   SystemTimer
#define osActivateTaskIdOfAlarm_15              NULL
#define osCbkOfAlarm_15                         NULL
#define osTaskIdOfAlarm_15                      OsTask_Diagnostics
#define osActionOfAlarm_15                      ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_15                     Rte_Ev_Cyclic_OsTask_Diagnostics_0_20ms

/********************* Alarm 16 Rte_Al_TE_OsTask_DispFun_0_10ms *********************/	

#define osCounterIdOfAlarm_16                   SystemTimer
#define osActivateTaskIdOfAlarm_16              NULL
#define osCbkOfAlarm_16                         NULL
#define osTaskIdOfAlarm_16                      OsTask_DispFun
#define osActionOfAlarm_16                      ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_16                     Rte_Ev_Cyclic_OsTask_DispFun_0_10ms

/********************* Alarm 17 Rte_Al_TE_OsTask_DispFun_0_5ms *********************/	

#define osCounterIdOfAlarm_17                   SystemTimer
#define osActivateTaskIdOfAlarm_17              NULL
#define osCbkOfAlarm_17                         NULL
#define osTaskIdOfAlarm_17                      OsTask_DispFun
#define osActionOfAlarm_17                      ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_17                     Rte_Ev_Cyclic_OsTask_DispFun_0_5ms

/********************* Alarm 18 Rte_Al_TE_OsTask_EthFun_0_10ms *********************/	

#define osCounterIdOfAlarm_18                   SystemTimer
#define osActivateTaskIdOfAlarm_18              OsTask_EthFun
#define osCbkOfAlarm_18                         NULL
#define osTaskIdOfAlarm_18                      NULL
#define osActionOfAlarm_18                      ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_18                     NULL

/********************* Alarm 19 Rte_Al_TE_OsTask_GaugeFun_0_20ms *********************/	

#define osCounterIdOfAlarm_19                   SystemTimer
#define osActivateTaskIdOfAlarm_19              OsTask_GaugeFun
#define osCbkOfAlarm_19                         NULL
#define osTaskIdOfAlarm_19                      NULL
#define osActionOfAlarm_19                      ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_19                     NULL

/********************* Alarm 20 Rte_Al_TE_OsTask_IndFun_0_30ms *********************/	

#define osCounterIdOfAlarm_20                   SystemTimer
#define osActivateTaskIdOfAlarm_20              OsTask_IndFun
#define osCbkOfAlarm_20                         NULL
#define osTaskIdOfAlarm_20                      NULL
#define osActionOfAlarm_20                      ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_20                     NULL

/********************* Alarm 21 Rte_Al_TE_OsTask_LSH_16ms_0_16ms *********************/	

#define osCounterIdOfAlarm_21                   SystemTimer
#define osActivateTaskIdOfAlarm_21              NULL
#define osCbkOfAlarm_21                         NULL
#define osTaskIdOfAlarm_21                      OsTask_LSH_16ms
#define osActionOfAlarm_21                      ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_21                     Rte_Ev_Cyclic_OsTask_LSH_16ms_0_16ms

/********************* Alarm 22 Rte_Al_TE_OsTask_Mcal_0_10ms *********************/	

#define osCounterIdOfAlarm_22                   SystemTimer
#define osActivateTaskIdOfAlarm_22              OsTask_Mcal
#define osCbkOfAlarm_22                         NULL
#define osTaskIdOfAlarm_22                      NULL
#define osActionOfAlarm_22                      ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_22                     NULL

/********************* Alarm 23 Rte_Al_TE_OsTask_MemSer_0_10ms *********************/	

#define osCounterIdOfAlarm_23                   SystemTimer
#define osActivateTaskIdOfAlarm_23              NULL
#define osCbkOfAlarm_23                         NULL
#define osTaskIdOfAlarm_23                      OsTask_MemSer
#define osActionOfAlarm_23                      ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_23                     Rte_Ev_Cyclic_OsTask_MemSer_0_10ms

/********************* Alarm 24 Rte_Al_TE_OsTask_ModeMgt_0_10ms *********************/	

#define osCounterIdOfAlarm_24                   SystemTimer
#define osActivateTaskIdOfAlarm_24              NULL
#define osCbkOfAlarm_24                         NULL
#define osTaskIdOfAlarm_24                      OsTask_ModeMgt
#define osActionOfAlarm_24                      ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_24                     Rte_Ev_Cyclic_OsTask_ModeMgt_0_10ms

/********************* Alarm 25 Rte_Al_TE_OsTask_SafeApp_0_30ms *********************/	

#define osCounterIdOfAlarm_25                   SystemTimer
#define osActivateTaskIdOfAlarm_25              OsTask_SafeApp
#define osCbkOfAlarm_25                         NULL
#define osTaskIdOfAlarm_25                      NULL
#define osActionOfAlarm_25                      ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_25                     NULL

/********************* Alarm 26 Rte_Al_TE_OsTask_SafeBsw_0_10ms *********************/	

#define osCounterIdOfAlarm_26                   SystemTimer
#define osActivateTaskIdOfAlarm_26              NULL
#define osCbkOfAlarm_26                         NULL
#define osTaskIdOfAlarm_26                      OsTask_SafeBsw
#define osActionOfAlarm_26                      ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_26                     Rte_Ev_Cyclic_OsTask_SafeBsw_0_10ms

/********************* Alarm 27 Rte_Al_TE_OsTask_TripFun_0_50ms *********************/	

#define osCounterIdOfAlarm_27                   SystemTimer
#define osActivateTaskIdOfAlarm_27              OsTask_TripFun
#define osCbkOfAlarm_27                         NULL
#define osTaskIdOfAlarm_27                      NULL
#define osActionOfAlarm_27                      ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_27                     NULL

/********************* Alarm 28 Rte_Al_TE_OsTask_WarnFun_0_32ms *********************/	

#define osCounterIdOfAlarm_28                   SystemTimer
#define osActivateTaskIdOfAlarm_28              OsTask_WarnFun
#define osCbkOfAlarm_28                         NULL
#define osTaskIdOfAlarm_28                      NULL
#define osActionOfAlarm_28                      ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_28                     NULL

/********************* Alarm 29 Rte_Al_TE_OsTask_WdgMngt_0_10ms *********************/	

#define osCounterIdOfAlarm_29                   SystemTimer
#define osActivateTaskIdOfAlarm_29              OsTask_WdgMngt
#define osCbkOfAlarm_29                         NULL
#define osTaskIdOfAlarm_29                      NULL
#define osActionOfAlarm_29                      ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_29                     NULL

/********************* Alarm 30 Rte_Al_TE_SlowGaugeAdapter_SlowGaugeAdapter_Task *********************/	

#define osCounterIdOfAlarm_30                   SystemTimer
#define osActivateTaskIdOfAlarm_30              NULL
#define osCbkOfAlarm_30                         NULL
#define osTaskIdOfAlarm_30                      OsTask_DispFun
#define osActionOfAlarm_30                      ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_30                     Rte_Ev_Run_SlowGaugeAdapter_SlowGaugeAdapter_Task

/********************* Alarm 31 Rte_Al_TE_Test_Comp_AudioTaskStubRunnable *********************/	

#define osCounterIdOfAlarm_31                   SystemTimer
#define osActivateTaskIdOfAlarm_31              OsTask_AudioFun
#define osCbkOfAlarm_31                         NULL
#define osTaskIdOfAlarm_31                      NULL
#define osActionOfAlarm_31                      ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_31                     NULL

/********************* Alarm 32 Rte_Al_TE_Test_Comp_FotaTaskStubRunnable *********************/	

#define osCounterIdOfAlarm_32                   SystemTimer
#define osActivateTaskIdOfAlarm_32              OsTask_FotaFun
#define osCbkOfAlarm_32                         NULL
#define osTaskIdOfAlarm_32                      NULL
#define osActionOfAlarm_32                      ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_32                     NULL

/********************* Alarm 33 Rte_Al_TE_Test_Comp_LinTaskStubRunnable *********************/	

#define osCounterIdOfAlarm_33                   SystemTimer
#define osActivateTaskIdOfAlarm_33              OsTask_LinFun
#define osCbkOfAlarm_33                         NULL
#define osTaskIdOfAlarm_33                      NULL
#define osActionOfAlarm_33                      ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_33                     NULL

/********************* Alarm 34 Rte_Al_TE_UclProxyCdd_CUclProxyCdd_Impl_MainFunction *********************/	

#define osCounterIdOfAlarm_34                   SystemTimer
#define osActivateTaskIdOfAlarm_34              NULL
#define osCbkOfAlarm_34                         NULL
#define osTaskIdOfAlarm_34                      OsTask_IpcUclEv
#define osActionOfAlarm_34                      ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_34                     Rte_Ev_Run_UclProxyCdd_CUclProxyCdd_Impl_MainFunction




/* Alarm Callback function prototypes */


#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

