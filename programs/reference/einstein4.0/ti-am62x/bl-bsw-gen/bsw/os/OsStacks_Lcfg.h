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
*    @file osStacks_Lcfg.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by MNATRAMI at 2026-04-06 16:31:56.312453
********************************************************************************************************************/

#ifndef OSSTACK_LCFG_H
#define OSSTACK_LCFG_H


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/



extern osStackDataType osFIQStack [64];

extern osStackDataType osIRQCat1Stack [128];

extern osStackDataType osSystemStack [1024];

extern osStackDataType osLevelStackCore0Level0 [512];


extern osStackDataType OsStack_InitTaskDyn [128];

extern osStackDataType OsStack_OsTask_UclDyn [512];

extern osStackDataType OsStack_OsTask_DiagnosticsDyn [512];

extern osStackDataType OsStack_OsTask_CANFunDyn [512];

extern osStackDataType OsStack_OsTask_WdgMngtDyn [512];

extern osStackDataType OsStack_OsTask_IdleTaskDyn [256];



#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

