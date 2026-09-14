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
*    @file osStacks_Lcfg.c
*    @ingroup Os Configuration
*    @brief This is Os link time configuration source file. It contains definitions of link time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by MNATRAMI at 2026-04-06 16:31:56.312453
********************************************************************************************************************/

#ifndef OSSTACK_LCFG_C
#define OSSTACK_LCFG_C


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/

#include "Os_Lcfg.h"

#pragma clang section bss=".osFIQStack"
osStackDataType osFIQStack [64];
#pragma clang section bss=""


#pragma clang section bss=".osIRQCat1Stack"
osStackDataType osIRQCat1Stack [128];
#pragma clang section bss=""


#pragma clang section bss=".osSystemStack"
osStackDataType osSystemStack [1024];
#pragma clang section bss=""

const OsStackType OsSYSStack    = {osdSystemStack_TOP, osdSystemStack_BOT};
const OsStackType OsIRQStack    = {osdIRQCat1Stack_TOP, osdIRQCat1Stack_BOT};
const OsStackType OsFIQStack    = {osdFIQStack_TOP, osdFIQStack_BOT};

#pragma clang section bss=".osLevelStackCore0Level0"
osStackDataType osLevelStackCore0Level0 [512];
#pragma clang section bss=""


/*Define Stack: OsStack_InitTaskDyn */
#pragma clang section bss=".OsStack_InitTaskDyn"
osStackDataType OsStack_InitTaskDyn [128];
#pragma clang section bss=""

/*Define Stack: OsStack_OsTask_UclDyn */
#pragma clang section bss=".OsStack_OsTask_UclDyn"
osStackDataType OsStack_OsTask_UclDyn [512];
#pragma clang section bss=""

/*Define Stack: OsStack_OsTask_DiagnosticsDyn */
#pragma clang section bss=".OsStack_OsTask_DiagnosticsDyn"
osStackDataType OsStack_OsTask_DiagnosticsDyn [512];
#pragma clang section bss=""

/*Define Stack: OsStack_OsTask_CANFunDyn */
#pragma clang section bss=".OsStack_OsTask_CANFunDyn"
osStackDataType OsStack_OsTask_CANFunDyn [512];
#pragma clang section bss=""

/*Define Stack: OsStack_OsTask_WdgMngtDyn */
#pragma clang section bss=".OsStack_OsTask_WdgMngtDyn"
osStackDataType OsStack_OsTask_WdgMngtDyn [512];
#pragma clang section bss=""

/*Define Stack: OsStack_OsTask_IdleTaskDyn */
#pragma clang section bss=".OsStack_OsTask_IdleTaskDyn"
osStackDataType OsStack_OsTask_IdleTaskDyn [256];
#pragma clang section bss=""



#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

