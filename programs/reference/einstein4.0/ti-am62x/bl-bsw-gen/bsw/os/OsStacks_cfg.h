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
*    @file osStacks_cfg.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by MNATRAMI at 2026-04-06 16:31:56.312453
********************************************************************************************************************/

#ifndef OSSTACK_CFG_H
#define OSSTACK_CFG_H


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/


#define osdInitTask_BOT osBottomOfStack(OsStack_InitTaskDyn)
#define osdInitTask_TOP osAssignStack(OsStack_InitTaskDyn)

#define osdOsTask_Ucl_BOT osBottomOfStack(OsStack_OsTask_UclDyn)
#define osdOsTask_Ucl_TOP osAssignStack(OsStack_OsTask_UclDyn)

#define osdOsTask_Diagnostics_BOT osBottomOfStack(OsStack_OsTask_DiagnosticsDyn)
#define osdOsTask_Diagnostics_TOP osAssignStack(OsStack_OsTask_DiagnosticsDyn)

#define osdOsTask_CANFun_BOT osBottomOfStack(OsStack_OsTask_CANFunDyn)
#define osdOsTask_CANFun_TOP osAssignStack(OsStack_OsTask_CANFunDyn)

#define osdOsTask_WdgMngt_BOT osBottomOfStack(OsStack_OsTask_WdgMngtDyn)
#define osdOsTask_WdgMngt_TOP osAssignStack(OsStack_OsTask_WdgMngtDyn)

#define osdOsTask_IdleTask_BOT osBottomOfStack(OsStack_OsTask_IdleTaskDyn)
#define osdOsTask_IdleTask_TOP osAssignStack(OsStack_OsTask_IdleTaskDyn)


#define osdFIQStack_BOT osBottomOfStack(osFIQStack)
#define osdFIQStack_TOP osAssignStack(osFIQStack)

#define osdIRQCat1Stack_BOT osBottomOfStack(osIRQCat1Stack)
#define osdIRQCat1Stack_TOP osAssignStack(osIRQCat1Stack)

#define osdSystemStack_BOT osBottomOfStack(osSystemStack)
#define osdSystemStack_TOP osAssignStack(osSystemStack)

#define osdMcuOsGptIsr_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcuOsGptIsr_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMcuCan0RxTxIsr_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcuCan0RxTxIsr_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMcuCan1RxTxIsr_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcuCan1RxTxIsr_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMcuI2c3IoIsr_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcuI2c3IoIsr_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMcuI2c0PmicIsr_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcuI2c0PmicIsr_TOP osAssignStack(osLevelStackCore0Level0)

#define osdGpt_Ch3Isr_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdGpt_Ch3Isr_TOP osAssignStack(osLevelStackCore0Level0)

#define osdGpt_Ch4Isr_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdGpt_Ch4Isr_TOP osAssignStack(osLevelStackCore0Level0)

#define osdPmicCdd_nINTGpioInterrupt_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdPmicCdd_nINTGpioInterrupt_TOP osAssignStack(osLevelStackCore0Level0)

#define osdCdd_IpcIrqMbxFromWKUP_R5FSS0_0_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdCdd_IpcIrqMbxFromWKUP_R5FSS0_0_TOP osAssignStack(osLevelStackCore0Level0)



#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

