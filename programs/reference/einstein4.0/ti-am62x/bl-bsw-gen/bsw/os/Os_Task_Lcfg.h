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
*    @file Os_Task_Lcfg.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by MNATRAMI at 2026-04-06 16:31:56.335514900
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



extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_InitTask;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_Ucl;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_Diagnostics;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_CANFun;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_WdgMngt;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_IdleTask;
extern CONST (OsTaskConfigRefType, OS_CONST) OsCore0_OsTaskConfigRefList[OsNumberOfTasks];
extern const TaskType AutoStartTaskList[OsNumberOfAutoStartTasks];

extern const OsTaskConfigRefType TcbTaskRefConfig[OsNumberOfTasks];

/* Task function prototypes */
void InitTaskfunc(void);
void OsTask_Uclfunc(void);
void OsTask_Diagnosticsfunc(void);
void OsTask_CANFunfunc(void);
void OsTask_WdgMngtfunc(void);
void OsTask_IdleTaskfunc(void);


#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

