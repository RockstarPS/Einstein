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
*    @file osStacks_cfg.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by TGUNASEK at 2025-08-04 15:28:12.586846200
********************************************************************************************************************/

#ifndef OSSTACK_CFG_H
#define OSSTACK_CFG_H


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/


#define osdOsTask_BSW_COM_Periodic_2_BOT osBottomOfStack(OsStack_OsTask_BSW_COM_Periodic_2Dyn)
#define osdOsTask_BSW_COM_Periodic_2_TOP osAssignStack(OsStack_OsTask_BSW_COM_Periodic_2Dyn)

#define osdOsTask_BSW_EventPeriodic_0_BOT osBottomOfStack(OsStack_OsTask_BSW_EventPeriodic_0Dyn)
#define osdOsTask_BSW_EventPeriodic_0_TOP osAssignStack(OsStack_OsTask_BSW_EventPeriodic_0Dyn)

#define osdInit_Task_BOT osBottomOfStack(OsStack_Init_TaskDyn)
#define osdInit_Task_TOP osAssignStack(OsStack_Init_TaskDyn)

#define osdIdleTask_OsCore_Core0_BOT osBottomOfStack(OsStack_IdleTask_OsCore_Core0Dyn)
#define osdIdleTask_OsCore_Core0_TOP osAssignStack(OsStack_IdleTask_OsCore_Core0Dyn)

#define osdOsTask_BSW_Periodic_0_BOT osBottomOfStack(OsStack_OsTask_BSW_Periodic_0Dyn)
#define osdOsTask_BSW_Periodic_0_TOP osAssignStack(OsStack_OsTask_BSW_Periodic_0Dyn)

#define osdOsTask_BSW_Periodic_1_BOT osBottomOfStack(OsStack_OsTask_BSW_Periodic_1Dyn)
#define osdOsTask_BSW_Periodic_1_TOP osAssignStack(OsStack_OsTask_BSW_Periodic_1Dyn)

#define osdOsTask_CAN_Periodic_0_BOT osBottomOfStack(OsStack_OsTask_CAN_Periodic_0Dyn)
#define osdOsTask_CAN_Periodic_0_TOP osAssignStack(OsStack_OsTask_CAN_Periodic_0Dyn)

#define osdOsTask_CDD_FitPeriodic_1_BOT osBottomOfStack(OsStack_OsTask_CDD_FitPeriodic_1Dyn)
#define osdOsTask_CDD_FitPeriodic_1_TOP osAssignStack(OsStack_OsTask_CDD_FitPeriodic_1Dyn)

#define osdOsTask_CDD_Periodic_0_BOT osBottomOfStack(OsStack_OsTask_CDD_Periodic_0Dyn)
#define osdOsTask_CDD_Periodic_0_TOP osAssignStack(OsStack_OsTask_CDD_Periodic_0Dyn)

#define osdOsTask_COM_EventPeriodic_0_BOT osBottomOfStack(OsStack_OsTask_COM_EventPeriodic_0Dyn)
#define osdOsTask_COM_EventPeriodic_0_TOP osAssignStack(OsStack_OsTask_COM_EventPeriodic_0Dyn)

#define osdOsTask_CanDataRx_0_BOT osBottomOfStack(OsStack_OsTask_CanDataRx_0Dyn)
#define osdOsTask_CanDataRx_0_TOP osAssignStack(OsStack_OsTask_CanDataRx_0Dyn)

#define osdOsTask_NvmSpeedup_BOT osBottomOfStack(OsStack_OsTask_NvmSpeedupDyn)
#define osdOsTask_NvmSpeedup_TOP osAssignStack(OsStack_OsTask_NvmSpeedupDyn)

#define osdOsTask_SafeBsw_0_BOT osBottomOfStack(OsStack_OsTask_SafeBsw_0Dyn)
#define osdOsTask_SafeBsw_0_TOP osAssignStack(OsStack_OsTask_SafeBsw_0Dyn)

#define osdOsTask_SafeBsw_1_BOT osBottomOfStack(OsStack_OsTask_SafeBsw_1Dyn)
#define osdOsTask_SafeBsw_1_TOP osAssignStack(OsStack_OsTask_SafeBsw_1Dyn)

#define osdOsTask_LSH_16ms_BOT osBottomOfStack(OsStack_OsTask_LSH_16msDyn)
#define osdOsTask_LSH_16ms_TOP osAssignStack(OsStack_OsTask_LSH_16msDyn)

#define osdOsTaskRender_BOT osBottomOfStack(OsStack_OsTaskRenderDyn)
#define osdOsTaskRender_TOP osAssignStack(OsStack_OsTaskRenderDyn)


#define osdFIQStack_BOT osBottomOfStack(osFIQStack)
#define osdFIQStack_TOP osAssignStack(osFIQStack)

#define osdIRQCat1Stack_BOT osBottomOfStack(osIRQCat1Stack)
#define osdIRQCat1Stack_TOP osAssignStack(osIRQCat1Stack)

#define osdSystemStack_BOT osBottomOfStack(osSystemStack)
#define osdSystemStack_TOP osAssignStack(osSystemStack)

#define osdSystemTimerISR_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdSystemTimerISR_TOP osAssignStack(osLevelStackCore0Level0)

#define osdCAN0_ISR_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdCAN0_ISR_TOP osAssignStack(osLevelStackCore0Level0)

#define osdGPT_ISR_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdGPT_ISR_TOP osAssignStack(osLevelStackCore0Level0)

#define osdBACKUP_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdBACKUP_TOP osAssignStack(osLevelStackCore0Level0)

#define osdPDMA48_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdPDMA48_TOP osAssignStack(osLevelStackCore0Level0)

#define osdPDMA49_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdPDMA49_TOP osAssignStack(osLevelStackCore0Level0)

#define osdPDMA50_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdPDMA50_TOP osAssignStack(osLevelStackCore0Level0)

#define osdPDMA51_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdPDMA51_TOP osAssignStack(osLevelStackCore0Level0)

#define osdPDMA52_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdPDMA52_TOP osAssignStack(osLevelStackCore0Level0)

#define osdcpuss_interrupts_ipc_6_IRQn_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdcpuss_interrupts_ipc_6_IRQn_TOP osAssignStack(osLevelStackCore0Level0)

#define osdISR_GFX2D_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdISR_GFX2D_TOP osAssignStack(osLevelStackCore0Level0)

#define osdISR_VIDEOIO_0_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdISR_VIDEOIO_0_TOP osAssignStack(osLevelStackCore0Level0)

#define osdISR_VIDEOIO_1_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdISR_VIDEOIO_1_TOP osAssignStack(osLevelStackCore0Level0)

#define osdISR_PDMA22_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdISR_PDMA22_TOP osAssignStack(osLevelStackCore0Level0)

#define osdISR_MDMA1_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdISR_MDMA1_TOP osAssignStack(osLevelStackCore0Level0)

#define osdISR_MDMA2_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdISR_MDMA2_TOP osAssignStack(osLevelStackCore0Level0)

#define osdCAN1_ISR_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdCAN1_ISR_TOP osAssignStack(osLevelStackCore0Level0)

#define osdSCB2_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdSCB2_TOP osAssignStack(osLevelStackCore0Level0)

#define osdIGN_ISR_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdIGN_ISR_TOP osAssignStack(osLevelStackCore0Level0)

#define osdCAN_WAKEUP_ISR_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdCAN_WAKEUP_ISR_TOP osAssignStack(osLevelStackCore0Level0)

#define osdECC_ERROR_ISR_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdECC_ERROR_ISR_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMCU_LVD_ISR_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMCU_LVD_ISR_TOP osAssignStack(osLevelStackCore0Level0)

#define osdCSV_ERROR_ISR_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdCSV_ERROR_ISR_TOP osAssignStack(osLevelStackCore0Level0)

#define osdSSV_ERROR_ISR_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdSSV_ERROR_ISR_TOP osAssignStack(osLevelStackCore0Level0)



#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

