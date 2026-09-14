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
*    Auto generated code in vAUTOSAR TOOL by MNATRAMI at 2026-04-06 16:31:56.335514900
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

#define OsNumberOfAlarms                                  4U

/* Alarms */
#define Rte_Al_TE2_OsTask_Diagnostics_0_10ms              (0U)
#define Rte_Al_TE2_OsTask_Ucl_0_4ms                       (1U)
#define Rte_Al_TE2_OsTask_CANFun_0_10ms                   (2U)
#define Rte_Al_TE2_OsTask_WdgMngt_0_500ms                 (3U)

/* Num of applications in alarm */
#define OsNumberOfApplicationsAlarm0                        0
#define OsNumberOfApplicationsAlarm1                        0
#define OsNumberOfApplicationsAlarm2                        0
#define OsNumberOfApplicationsAlarm3                        0


/*****************************************************************************
*                                 Alarm Table                                *
******************************************************************************/


/********************* Alarm 0 Rte_Al_TE2_OsTask_Diagnostics_0_10ms *********************/	

#define osCounterIdOfAlarm_0                    SystemTimer
#define osActivateTaskIdOfAlarm_0               NULL
#define osCbkOfAlarm_0                          NULL
#define osTaskIdOfAlarm_0                       OsTask_Diagnostics
#define osActionOfAlarm_0                       ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_0                      Rte_Ev_Cyclic2_OsTask_Diagnostics_0_10ms

/********************* Alarm 1 Rte_Al_TE2_OsTask_Ucl_0_4ms *********************/	

#define osCounterIdOfAlarm_1                    SystemTimer
#define osActivateTaskIdOfAlarm_1               NULL
#define osCbkOfAlarm_1                          NULL
#define osTaskIdOfAlarm_1                       OsTask_Ucl
#define osActionOfAlarm_1                       ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_1                      Rte_Ev_Cyclic2_OsTask_Ucl_0_4ms

/********************* Alarm 2 Rte_Al_TE2_OsTask_CANFun_0_10ms *********************/	

#define osCounterIdOfAlarm_2                    SystemTimer
#define osActivateTaskIdOfAlarm_2               NULL
#define osCbkOfAlarm_2                          NULL
#define osTaskIdOfAlarm_2                       OsTask_CANFun
#define osActionOfAlarm_2                       ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_2                      Rte_Ev_Cyclic2_OsTask_CANFun_0_10ms

/********************* Alarm 3 Rte_Al_TE2_OsTask_WdgMngt_0_500ms *********************/	

#define osCounterIdOfAlarm_3                    SystemTimer
#define osActivateTaskIdOfAlarm_3               NULL
#define osCbkOfAlarm_3                          NULL
#define osTaskIdOfAlarm_3                       OsTask_WdgMngt
#define osActionOfAlarm_3                       ALARM_SET_EVENT_ACTION
#define osEventIdOfAlarm_3                      Rte_Ev_Cyclic2_OsTask_WdgMngt_0_500ms




/* Alarm Callback function prototypes */


#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

