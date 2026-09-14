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
*    @file Os_Alarm_Cfg.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by TGUNASEK at 2025-09-02 15:21:43.431421700
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

#define OsNumberOfAlarms                                  22U

/* Alarms */
#define Rte_Al_TE2_OsTask_BSW_EventPeriodic_0_0_10ms      (0U)
#define Rte_Al_TE2_OsTask_BSW_Periodic_0_1_10ms           (1U)
#define Rte_Al_TE2_OsTask_CAN_Periodic_0_4_10ms           (2U)
#define Rte_Al_TE2_OsTask_COM_EventPeriodic_0_2_10ms      (3U)
#define Rte_Al_TE2_OsTask_COM_EventPeriodic_0_2_20ms      (4U)
#define Rte_Al_TE2_OsTask_COM_EventPeriodic_0_2_5ms       (5U)
#define Rte_Al_TE_Bsw_Stubs_Bsw_stubs_MainFunction        (6U)
#define Rte_Al_TE_CMeetCdd_CMeetCdd_Task                  (7U)
#define Rte_Al_TE_OsTask_SafeBsw_1_0_10ms                 (8U)
#define Rte_Al_TE_EcuMExt_EcuMExt_MainFunction            (9U)
#define Rte_Al_TE_NvMExt_NvMExt_SpeedupRunnable           (10U)
#define Rte_Al_TE_OsTask_BSW_COM_Periodic_2_6_10ms        (11U)
#define Rte_Al_TE_OsTask_BSW_EventPeriodic_0_0_100ms      (12U)
#define Rte_Al_TE_OsTask_BSW_EventPeriodic_0_0_10ms       (13U)
#define Rte_Al_TE_OsTask_BSW_Periodic_1_3_10ms            (14U)
#define Rte_Al_TE_OsTask_CDD_FitPeriodic_1_0_20ms         (15U)
#define Rte_Al_TE_OsTask_CDD_Periodic_0_5_10ms            (16U)
#define Rte_Al_TE_OsTask_LSH_16ms_0_16ms                  (17U)
#define Rte_Al_TE_OsTask_SafeBsw_0_10_10ms                (18U)
#define Rte_Al_TE_RamTst_RamTst_MainFunction              (19U)
#define Rte_Al_TE_CSndCdd_CSndCdd_ToneProcess             (20U)
#define Rte_Al_TE_OsTask_BSW_EventPeriodic_0_0_16ms       (21U)

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


/*****************************************************************************
*                                 Alarm Table                                *
******************************************************************************/


/********************* Alarm 0 Rte_Al_TE2_OsTask_BSW_EventPeriodic_0_0_10ms *********************/	

#define osCounterIdOfAlarm_0                    SystemTimer
#define osActivateTaskIdOfAlarm_0               NULL
#define osCbkOfAlarm_0                          NULL
#define osTaskIdOfAlarm_0                       OsTask_BSW_EventPeriodic_0
#define osActionOfAlarm_0                       ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_0                      Rte_Ev_Cyclic2_OsTask_BSW_EventPeriodic_0_0_10ms

/********************* Alarm 1 Rte_Al_TE2_OsTask_BSW_Periodic_0_1_10ms *********************/	

#define osCounterIdOfAlarm_1                    SystemTimer
#define osActivateTaskIdOfAlarm_1               OsTask_BSW_Periodic_0
#define osCbkOfAlarm_1                          NULL
#define osTaskIdOfAlarm_1                       NULL
#define osActionOfAlarm_1                       ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_1                      NULL

/********************* Alarm 2 Rte_Al_TE2_OsTask_CAN_Periodic_0_4_10ms *********************/	

#define osCounterIdOfAlarm_2                    SystemTimer
#define osActivateTaskIdOfAlarm_2               OsTask_CAN_Periodic_0
#define osCbkOfAlarm_2                          NULL
#define osTaskIdOfAlarm_2                       NULL
#define osActionOfAlarm_2                       ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_2                      NULL

/********************* Alarm 3 Rte_Al_TE2_OsTask_COM_EventPeriodic_0_2_10ms *********************/	

#define osCounterIdOfAlarm_3                    SystemTimer
#define osActivateTaskIdOfAlarm_3               NULL
#define osCbkOfAlarm_3                          NULL
#define osTaskIdOfAlarm_3                       OsTask_COM_EventPeriodic_0
#define osActionOfAlarm_3                       ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_3                      Rte_Ev_Cyclic2_OsTask_COM_EventPeriodic_0_2_10ms

/********************* Alarm 4 Rte_Al_TE2_OsTask_COM_EventPeriodic_0_2_20ms *********************/	

#define osCounterIdOfAlarm_4                    SystemTimer
#define osActivateTaskIdOfAlarm_4               NULL
#define osCbkOfAlarm_4                          NULL
#define osTaskIdOfAlarm_4                       OsTask_COM_EventPeriodic_0
#define osActionOfAlarm_4                       ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_4                      Rte_Ev_Cyclic2_OsTask_COM_EventPeriodic_0_2_20ms

/********************* Alarm 5 Rte_Al_TE2_OsTask_COM_EventPeriodic_0_2_5ms *********************/	

#define osCounterIdOfAlarm_5                    SystemTimer
#define osActivateTaskIdOfAlarm_5               NULL
#define osCbkOfAlarm_5                          NULL
#define osTaskIdOfAlarm_5                       OsTask_COM_EventPeriodic_0
#define osActionOfAlarm_5                       ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_5                      Rte_Ev_Cyclic2_OsTask_COM_EventPeriodic_0_2_5ms

/********************* Alarm 6 Rte_Al_TE_Bsw_Stubs_Bsw_stubs_MainFunction *********************/	

#define osCounterIdOfAlarm_6                    SystemTimer
#define osActivateTaskIdOfAlarm_6               NULL
#define osCbkOfAlarm_6                          NULL
#define osTaskIdOfAlarm_6                       OsTask_BSW_COM_Periodic_2
#define osActionOfAlarm_6                       ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_6                      Rte_Ev_Run_Bsw_Stubs_Bsw_stubs_MainFunction

/********************* Alarm 7 Rte_Al_TE_CMeetCdd_CMeetCdd_Task *********************/	

#define osCounterIdOfAlarm_7                    SystemTimer
#define osActivateTaskIdOfAlarm_7               NULL
#define osCbkOfAlarm_7                          NULL
#define osTaskIdOfAlarm_7                       OsTask_BSW_EventPeriodic_0
#define osActionOfAlarm_7                       ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_7                      Rte_Ev_Run_CMeetCdd_CMeetCdd_Task

/********************* Alarm 8 Rte_Al_TE_OsTask_SafeBsw_1_0_10ms *********************/	

#define osCounterIdOfAlarm_8                    SystemTimer
#define osActivateTaskIdOfAlarm_8               NULL
#define osCbkOfAlarm_8                          NULL
#define osTaskIdOfAlarm_8                       OsTask_SafeBsw_1
#define osActionOfAlarm_8                       ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_8                      Rte_Ev_Cyclic_OsTask_SafeBsw_1_0_10ms

/********************* Alarm 9 Rte_Al_TE_EcuMExt_EcuMExt_MainFunction *********************/	

#define osCounterIdOfAlarm_9                    SystemTimer
#define osActivateTaskIdOfAlarm_9               NULL
#define osCbkOfAlarm_9                          NULL
#define osTaskIdOfAlarm_9                       OsTask_BSW_EventPeriodic_0
#define osActionOfAlarm_9                       ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_9                      Rte_Ev_Run_EcuMExt_EcuMExt_MainFunction

/********************* Alarm 10 Rte_Al_TE_NvMExt_NvMExt_SpeedupRunnable *********************/	

#define osCounterIdOfAlarm_10                   SystemTimer
#define osActivateTaskIdOfAlarm_10              OsTask_NvmSpeedup
#define osCbkOfAlarm_10                         NULL
#define osTaskIdOfAlarm_10                      NULL
#define osActionOfAlarm_10                      ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_10                     NULL

/********************* Alarm 11 Rte_Al_TE_OsTask_BSW_COM_Periodic_2_6_10ms *********************/	

#define osCounterIdOfAlarm_11                   SystemTimer
#define osActivateTaskIdOfAlarm_11              NULL
#define osCbkOfAlarm_11                         NULL
#define osTaskIdOfAlarm_11                      OsTask_BSW_COM_Periodic_2
#define osActionOfAlarm_11                      ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_11                     Rte_Ev_Cyclic_OsTask_BSW_COM_Periodic_2_6_10ms

/********************* Alarm 12 Rte_Al_TE_OsTask_BSW_EventPeriodic_0_0_100ms *********************/	

#define osCounterIdOfAlarm_12                   SystemTimer
#define osActivateTaskIdOfAlarm_12              NULL
#define osCbkOfAlarm_12                         NULL
#define osTaskIdOfAlarm_12                      OsTask_BSW_EventPeriodic_0
#define osActionOfAlarm_12                      ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_12                     Rte_Ev_Cyclic_OsTask_BSW_EventPeriodic_0_0_100ms

/********************* Alarm 13 Rte_Al_TE_OsTask_BSW_EventPeriodic_0_0_10ms *********************/	

#define osCounterIdOfAlarm_13                   SystemTimer
#define osActivateTaskIdOfAlarm_13              NULL
#define osCbkOfAlarm_13                         NULL
#define osTaskIdOfAlarm_13                      OsTask_BSW_EventPeriodic_0
#define osActionOfAlarm_13                      ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_13                     Rte_Ev_Cyclic_OsTask_BSW_EventPeriodic_0_0_10ms

/********************* Alarm 14 Rte_Al_TE_OsTask_BSW_Periodic_1_3_10ms *********************/	

#define osCounterIdOfAlarm_14                   SystemTimer
#define osActivateTaskIdOfAlarm_14              OsTask_BSW_Periodic_1
#define osCbkOfAlarm_14                         NULL
#define osTaskIdOfAlarm_14                      NULL
#define osActionOfAlarm_14                      ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_14                     NULL

/********************* Alarm 15 Rte_Al_TE_OsTask_CDD_FitPeriodic_1_0_20ms *********************/	

#define osCounterIdOfAlarm_15                   SystemTimer
#define osActivateTaskIdOfAlarm_15              NULL
#define osCbkOfAlarm_15                         NULL
#define osTaskIdOfAlarm_15                      OsTask_CDD_FitPeriodic_1
#define osActionOfAlarm_15                      ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_15                     Rte_Ev_Cyclic_OsTask_CDD_FitPeriodic_1_0_20ms

/********************* Alarm 16 Rte_Al_TE_OsTask_CDD_Periodic_0_5_10ms *********************/	

#define osCounterIdOfAlarm_16                   SystemTimer
#define osActivateTaskIdOfAlarm_16              OsTask_CDD_Periodic_0
#define osCbkOfAlarm_16                         NULL
#define osTaskIdOfAlarm_16                      NULL
#define osActionOfAlarm_16                      ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_16                     NULL

/********************* Alarm 17 Rte_Al_TE_OsTask_LSH_16ms_0_16ms *********************/	

#define osCounterIdOfAlarm_17                   SystemTimer
#define osActivateTaskIdOfAlarm_17              NULL
#define osCbkOfAlarm_17                         NULL
#define osTaskIdOfAlarm_17                      OsTask_LSH_16ms
#define osActionOfAlarm_17                      ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_17                     Rte_Ev_Cyclic_OsTask_LSH_16ms_0_16ms

/********************* Alarm 18 Rte_Al_TE_OsTask_SafeBsw_0_10_10ms *********************/	

#define osCounterIdOfAlarm_18                   SystemTimer
#define osActivateTaskIdOfAlarm_18              OsTask_SafeBsw_0
#define osCbkOfAlarm_18                         NULL
#define osTaskIdOfAlarm_18                      NULL
#define osActionOfAlarm_18                      ALARM_ACTIVATE_TASK_ACTION
#define osEventIdOfAlarm_18                     NULL

/********************* Alarm 19 Rte_Al_TE_RamTst_RamTst_MainFunction *********************/	

#define osCounterIdOfAlarm_19                   SystemTimer
#define osActivateTaskIdOfAlarm_19              NULL
#define osCbkOfAlarm_19                         NULL
#define osTaskIdOfAlarm_19                      OsTask_SafeBsw_1
#define osActionOfAlarm_19                      ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_19                     Rte_Ev_Run_RamTst_RamTst_MainFunction

/********************* Alarm 20 Rte_Al_TE_CSndCdd_CSndCdd_ToneProcess *********************/	

#define osCounterIdOfAlarm_20                   SystemTimer
#define osActivateTaskIdOfAlarm_20              NULL
#define osCbkOfAlarm_20                         NULL
#define osTaskIdOfAlarm_20                      OsTask_BSW_EventPeriodic_0
#define osActionOfAlarm_20                      ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_20                     Rte_Ev_Run_CSndCdd_CSndCdd_ToneProcess

/********************* Alarm 21 Rte_Al_TE_OsTask_BSW_EventPeriodic_0_0_16ms *********************/	

#define osCounterIdOfAlarm_21                   SystemTimer
#define osActivateTaskIdOfAlarm_21              NULL
#define osCbkOfAlarm_21                         NULL
#define osTaskIdOfAlarm_21                      OsTask_BSW_EventPeriodic_0
#define osActionOfAlarm_21                      ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_21                     Rte_Ev_Cyclic_OsTask_BSW_EventPeriodic_0_0_16ms




/* Alarm Callback function prototypes */


#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

