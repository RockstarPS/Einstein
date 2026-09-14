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
*    Auto generated code in vAUTOSAR TOOL by SGOPAL1 at 2026-03-31 13:17:24.169460600
********************************************************************************************************************/

#ifndef OSSTACK_CFG_H
#define OSSTACK_CFG_H


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/


#define osdInitTask_BOT osBottomOfStack(OsStack_InitTaskDyn)
#define osdInitTask_TOP osAssignStack(OsStack_InitTaskDyn)

#define osdOsTask_AppFun_BOT osBottomOfStack(OsStack_OsTaskStackSharingDyn)
#define osdOsTask_AppFun_TOP osAssignStack(OsStack_OsTaskStackSharingDyn)

#define osdOsTask_AudioFun_BOT osBottomOfStack(OsStack_OsTaskStackSharingDyn)
#define osdOsTask_AudioFun_TOP osAssignStack(OsStack_OsTaskStackSharingDyn)

#define osdOsTask_Can0DataRxEv_BOT osBottomOfStack(OsStack_OsTask_Can0DataRxEvDyn)
#define osdOsTask_Can0DataRxEv_TOP osAssignStack(OsStack_OsTask_Can0DataRxEvDyn)

#define osdOsTask_Can1DataRxEv_BOT osBottomOfStack(OsStack_OsTask_Can1DataRxEvDyn)
#define osdOsTask_Can1DataRxEv_TOP osAssignStack(OsStack_OsTask_Can1DataRxEvDyn)

#define osdOsTask_CANFun_BOT osBottomOfStack(OsStack_OsTask_CANFunDyn)
#define osdOsTask_CANFun_TOP osAssignStack(OsStack_OsTask_CANFunDyn)

#define osdOsTask_DispFun_BOT osBottomOfStack(OsStack_OsTask_DispFunDyn)
#define osdOsTask_DispFun_TOP osAssignStack(OsStack_OsTask_DispFunDyn)

#define osdOsTask_EthFun_BOT osBottomOfStack(OsStack_OsTaskStackSharingDyn)
#define osdOsTask_EthFun_TOP osAssignStack(OsStack_OsTaskStackSharingDyn)

#define osdOsTask_FotaEv_BOT osBottomOfStack(OsStack_OsTask_FotaEvDyn)
#define osdOsTask_FotaEv_TOP osAssignStack(OsStack_OsTask_FotaEvDyn)

#define osdOsTask_FotaFun_BOT osBottomOfStack(OsStack_OsTask_FotaFunDyn)
#define osdOsTask_FotaFun_TOP osAssignStack(OsStack_OsTask_FotaFunDyn)

#define osdOsTask_GaugeFun_BOT osBottomOfStack(OsStack_OsTaskStackSharingDyn)
#define osdOsTask_GaugeFun_TOP osAssignStack(OsStack_OsTaskStackSharingDyn)

#define osdOsTask_IdleTask_BOT osBottomOfStack(OsStack_OsTask_IdleTaskDyn)
#define osdOsTask_IdleTask_TOP osAssignStack(OsStack_OsTask_IdleTaskDyn)

#define osdOsTask_IndFun_BOT osBottomOfStack(OsStack_OsTaskStackSharingDyn)
#define osdOsTask_IndFun_TOP osAssignStack(OsStack_OsTaskStackSharingDyn)

#define osdOsTask_LinFun_BOT osBottomOfStack(OsStack_OsTaskStackSharingDyn)
#define osdOsTask_LinFun_TOP osAssignStack(OsStack_OsTaskStackSharingDyn)

#define osdOsTask_Mcal_BOT osBottomOfStack(OsStack_OsTaskStackSharingDyn)
#define osdOsTask_Mcal_TOP osAssignStack(OsStack_OsTaskStackSharingDyn)

#define osdOsTask_ModeMgt_BOT osBottomOfStack(OsStack_OsTask_ModeMgtDyn)
#define osdOsTask_ModeMgt_TOP osAssignStack(OsStack_OsTask_ModeMgtDyn)

#define osdOsTask_NvmSpeedup_BOT osBottomOfStack(OsStack_OsTask_NvmSpeedupDyn)
#define osdOsTask_NvmSpeedup_TOP osAssignStack(OsStack_OsTask_NvmSpeedupDyn)

#define osdOsTask_SafeApp_BOT osBottomOfStack(OsStack_OsTaskStackSharingDyn)
#define osdOsTask_SafeApp_TOP osAssignStack(OsStack_OsTaskStackSharingDyn)

#define osdOsTask_TripFun_BOT osBottomOfStack(OsStack_OsTaskStackSharingDyn)
#define osdOsTask_TripFun_TOP osAssignStack(OsStack_OsTaskStackSharingDyn)

#define osdOsTask_WarnFun_BOT osBottomOfStack(OsStack_OsTaskStackSharingDyn)
#define osdOsTask_WarnFun_TOP osAssignStack(OsStack_OsTaskStackSharingDyn)

#define osdOsTask_WdgMngt_BOT osBottomOfStack(OsStack_OsTaskStackSharingDyn)
#define osdOsTask_WdgMngt_TOP osAssignStack(OsStack_OsTaskStackSharingDyn)

#define osdOsTask_Diagnostics_BOT osBottomOfStack(OsStack_OsTask_DiagnosticsDyn)
#define osdOsTask_Diagnostics_TOP osAssignStack(OsStack_OsTask_DiagnosticsDyn)

#define osdOsTask_LSH_16ms_BOT osBottomOfStack(OsStack_OsTask_LSH_16msDyn)
#define osdOsTask_LSH_16ms_TOP osAssignStack(OsStack_OsTask_LSH_16msDyn)

#define osdOsTask_SafeBsw_BOT osBottomOfStack(OsStack_OsTask_SafeBswDyn)
#define osdOsTask_SafeBsw_TOP osAssignStack(OsStack_OsTask_SafeBswDyn)

#define osdOsTask_MemSer_BOT osBottomOfStack(OsStack_OsTask_MemSerDyn)
#define osdOsTask_MemSer_TOP osAssignStack(OsStack_OsTask_MemSerDyn)

#define osdOsTask_IpcUclEv_BOT osBottomOfStack(OsStack_OsTask_IpcUclEvDyn)
#define osdOsTask_IpcUclEv_TOP osAssignStack(OsStack_OsTask_IpcUclEvDyn)

#define osdOsTaskRender_BOT osBottomOfStack(OsStack_OsTaskRenderDyn)
#define osdOsTaskRender_TOP osAssignStack(OsStack_OsTaskRenderDyn)


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

#define osdMcuSpi0NvmRxTxIsr_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcuSpi0NvmRxTxIsr_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMcuDss0Isr_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcuDss0Isr_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMcuI2c3IoIsr_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcuI2c3IoIsr_TOP osAssignStack(osLevelStackCore0Level0)

#define osdEth_TxIrqHdlr_0_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdEth_TxIrqHdlr_0_TOP osAssignStack(osLevelStackCore0Level0)

#define osdEth_RxIrqHdlr_0_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdEth_RxIrqHdlr_0_TOP osAssignStack(osLevelStackCore0Level0)

#define osdEth_MdioIrqHdlr_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdEth_MdioIrqHdlr_TOP osAssignStack(osLevelStackCore0Level0)

#define osdFltM_WkupEsmHiInterrupt_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdFltM_WkupEsmHiInterrupt_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMCU_IntrISR_UART0_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMCU_IntrISR_UART0_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMcuI2c0PmicIsr_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcuI2c0PmicIsr_TOP osAssignStack(osLevelStackCore0Level0)

#define osdGpt_Ch3Isr_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdGpt_Ch3Isr_TOP osAssignStack(osLevelStackCore0Level0)

#define osdGpt_Ch4Isr_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdGpt_Ch4Isr_TOP osAssignStack(osLevelStackCore0Level0)

#define osdSpi_IrqUnitMcspi2TxRx_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdSpi_IrqUnitMcspi2TxRx_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMCU_ISR_6_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMCU_ISR_6_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMAIN_ISR_34_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMAIN_ISR_34_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMAIN_ISR_35_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMAIN_ISR_35_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMCU_ISR_7_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMCU_ISR_7_TOP osAssignStack(osLevelStackCore0Level0)

#define osdFltM_WkupEsmCfgInterrupt_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdFltM_WkupEsmCfgInterrupt_TOP osAssignStack(osLevelStackCore0Level0)

#define osdFltM_WkupEsmLowInterrupt_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdFltM_WkupEsmLowInterrupt_TOP osAssignStack(osLevelStackCore0Level0)

#define osdSpi_IrqUnitMcspi0TxRx_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdSpi_IrqUnitMcspi0TxRx_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMainI2c2RtcIsr_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMainI2c2RtcIsr_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMCU_ResetIsolationReq_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMCU_ResetIsolationReq_TOP osAssignStack(osLevelStackCore0Level0)

#define osdFltM_FwlExceptionInterrupt_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdFltM_FwlExceptionInterrupt_TOP osAssignStack(osLevelStackCore0Level0)

#define osdCdd_IpcIrqMbxFromWKUP_R5FSS0_0_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdCdd_IpcIrqMbxFromWKUP_R5FSS0_0_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMcu_Udma_Vintr64_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcu_Udma_Vintr64_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMcu_Udma_Vintr65_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcu_Udma_Vintr65_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMcu_Udma_Vintr66_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcu_Udma_Vintr66_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMcu_Udma_Vintr67_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcu_Udma_Vintr67_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMcu_Udma_Vintr68_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcu_Udma_Vintr68_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMcu_Udma_Vintr69_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcu_Udma_Vintr69_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMcu_Udma_Vintr70_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcu_Udma_Vintr70_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMcu_Udma_Vintr71_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcu_Udma_Vintr71_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMcu_Udma_Vintr72_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcu_Udma_Vintr72_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMcu_Udma_Vintr73_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcu_Udma_Vintr73_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMcu_Udma_Vintr74_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcu_Udma_Vintr74_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMcu_Udma_Vintr75_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcu_Udma_Vintr75_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMcu_Udma_Vintr76_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcu_Udma_Vintr76_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMcu_Udma_Vintr77_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcu_Udma_Vintr77_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMcu_Udma_Vintr78_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcu_Udma_Vintr78_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMcu_Udma_Vintr79_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMcu_Udma_Vintr79_TOP osAssignStack(osLevelStackCore0Level0)

#define osdMainI2c1DacIsr_BOT osBottomOfStack(osLevelStackCore0Level0)
#define osdMainI2c1DacIsr_TOP osAssignStack(osLevelStackCore0Level0)



#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

