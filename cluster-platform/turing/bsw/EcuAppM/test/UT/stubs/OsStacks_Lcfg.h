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
*    @file osStacks_Lcfg.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by BJAYARA3 at 2025-12-12 17:15:15.670593200
********************************************************************************************************************/

#ifndef OSSTACK_LCFG_H
#define OSSTACK_LCFG_H


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/



extern osStackDataType osFIQStack [64];

extern osStackDataType osIRQCat1Stack [128];

extern osStackDataType osSystemStack [256];

extern osStackDataType osLevelStackCore0Level0 [256];


extern osStackDataType OsStack_OsTask_BSW_COM_Periodic_2Dyn [256];

extern osStackDataType OsStack_OsTask_BSW_EventPeriodic_0Dyn [512];

extern osStackDataType OsStack_Init_TaskDyn [512];

extern osStackDataType OsStack_IdleTask_OsCore_Core0Dyn [512];

extern osStackDataType OsStack_OsTask_BSW_Periodic_0Dyn [512];

extern osStackDataType OsStack_OsTask_BSW_Periodic_1Dyn [512];

extern osStackDataType OsStack_OsTask_CAN_Periodic_0Dyn [512];

extern osStackDataType OsStack_OsTask_CDD_FitPeriodic_1Dyn [512];

extern osStackDataType OsStack_OsTask_CDD_Periodic_0Dyn [512];

extern osStackDataType OsStack_OsTask_COM_EventPeriodic_0Dyn [512];

extern osStackDataType OsStack_OsTask_CanDataRx_0Dyn [512];

extern osStackDataType OsStack_OsTask_NvmSpeedupDyn [512];

extern osStackDataType OsStack_OsTask_SafeBsw_0Dyn [512];

extern osStackDataType OsStack_OsTask_SafeBsw_1Dyn [512];

extern osStackDataType OsStack_OsTask_LSH_16msDyn [512];

extern osStackDataType OsStack_OsTaskRenderDyn [4096];



#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

