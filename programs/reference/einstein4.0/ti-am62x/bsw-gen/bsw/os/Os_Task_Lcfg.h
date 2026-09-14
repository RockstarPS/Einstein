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
*    Auto generated code in vAUTOSAR TOOL by SGOPAL1 at 2026-03-31 13:17:24.275123700
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
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_AppFun;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_AudioFun;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_Can0DataRxEv;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_Can1DataRxEv;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_CANFun;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_DispFun;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_EthFun;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_FotaEv;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_FotaFun;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_GaugeFun;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_IdleTask;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_IndFun;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_LinFun;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_Mcal;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_ModeMgt;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_NvmSpeedup;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_SafeApp;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_TripFun;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_WarnFun;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_WdgMngt;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_Diagnostics;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_LSH_16ms;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_SafeBsw;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_MemSer;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTask_IpcUclEv;
extern CONST (OsTaskConfigType, OS_CONST) OsTaskConfig_OsTaskRender;
extern CONST (OsTaskConfigRefType, OS_CONST) OsCore0_OsTaskConfigRefList[OsNumberOfTasks];
extern const TaskType AutoStartTaskList[OsNumberOfAutoStartTasks];

extern const OsTaskConfigRefType TcbTaskRefConfig[OsNumberOfTasks];

/* Task function prototypes */
void InitTaskfunc(void);
void OsTask_AppFunfunc(void);
void OsTask_AudioFunfunc(void);
void OsTask_Can0DataRxEvfunc(void);
void OsTask_Can1DataRxEvfunc(void);
void OsTask_CANFunfunc(void);
void OsTask_DispFunfunc(void);
void OsTask_EthFunfunc(void);
void OsTask_FotaEvfunc(void);
void OsTask_FotaFunfunc(void);
void OsTask_GaugeFunfunc(void);
void OsTask_IdleTaskfunc(void);
void OsTask_IndFunfunc(void);
void OsTask_LinFunfunc(void);
void OsTask_Mcalfunc(void);
void OsTask_ModeMgtfunc(void);
void OsTask_NvmSpeedupfunc(void);
void OsTask_SafeAppfunc(void);
void OsTask_TripFunfunc(void);
void OsTask_WarnFunfunc(void);
void OsTask_WdgMngtfunc(void);
void OsTask_Diagnosticsfunc(void);
void OsTask_LSH_16msfunc(void);
void OsTask_SafeBswfunc(void);
void OsTask_MemSerfunc(void);
void OsTask_IpcUclEvfunc(void);
void OsTaskRenderfunc(void);


#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

