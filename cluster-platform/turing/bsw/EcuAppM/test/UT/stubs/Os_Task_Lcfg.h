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
*    @file Os_Task_Lcfg.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by TGUNASEK at 2025-06-17 16:35:54.663346300
********************************************************************************************************************/

#ifndef OS_TASKLCFG_H
#define OS_TASKLCFG_H


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/




/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
*****************************************************************************/



extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_BSW_COM_Periodic_2;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_BSW_EventPeriodic_0;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_Init_Task;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_IdleTask_OsCore_Core0;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_BSW_Periodic_0;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_BSW_Periodic_1;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_CAN_Periodic_0;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_CDD_FitPeriodic_1;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_CDD_Periodic_0;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_COM_EventPeriodic_0;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_CanDataRx_0;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_NvmSpeedup;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_SafeBsw_0;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_SafeBsw_1;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_LSH_16ms;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTaskRender;
extern CONST (OsTaskConfigRefType, OS_CONST) OsCore0_OsTaskConfigRefList[OsNumberOfTasks];
extern const TaskType AutoStartTaskList[OsNumberOfAutoStartTasks];

extern const OsTaskConfigRefType TcbTaskRefConfig[OsNumberOfTasks];

/* Task function prototypes */
void OsTask_BSW_COM_Periodic_2func(void);
void OsTask_BSW_EventPeriodic_0func(void);
void Init_Taskfunc(void);
void IdleTask_OsCore_Core0func(void);
void OsTask_BSW_Periodic_0func(void);
void OsTask_BSW_Periodic_1func(void);
void OsTask_CAN_Periodic_0func(void);
void OsTask_CDD_FitPeriodic_1func(void);
void OsTask_CDD_Periodic_0func(void);
void OsTask_COM_EventPeriodic_0func(void);
void OsTask_CanDataRx_0func(void);
void OsTask_NvmSpeedupfunc(void);
void OsTask_SafeBsw_0func(void);
void OsTask_SafeBsw_1func(void);
void OsTask_LSH_16msfunc(void);
void OsTaskRenderfunc(void);


#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

