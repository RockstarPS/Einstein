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
*    @file Os_Application_Lcfg.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by SGOPAL1 at 2026-03-31 13:17:24.245694100
********************************************************************************************************************/

#ifndef OS_APPLICATIONLCFG_H
#define OS_APPLICATIONLCFG_H


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/



/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
*****************************************************************************/


extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_InitTask;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_AppFun;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_AudioFun;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_Can0DataRxEv;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_Can1DataRxEv;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_CANFun;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_DispFun;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_EthFun;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_FotaEv;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_FotaFun;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_GaugeFun;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_IdleTask;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_IndFun;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_LinFun;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_Mcal;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_ModeMgt;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_NvmSpeedup;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_SafeApp;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_TripFun;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_WarnFun;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_WdgMngt;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_Diagnostics;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_LSH_16ms;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_SafeBsw;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_MemSer;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_IpcUclEv;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTaskRender;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_McuOsGptIsr;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_McuCan0RxTxIsr;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_McuCan1RxTxIsr;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_McuSpi0NvmRxTxIsr;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_McuDss0Isr;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_McuI2c3IoIsr;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Eth_TxIrqHdlr_0;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Eth_RxIrqHdlr_0;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Eth_MdioIrqHdlr;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_FltM_WkupEsmHiInterrupt;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_MCU_IntrISR_UART0;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_McuI2c0PmicIsr;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Gpt_Ch3Isr;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Gpt_Ch4Isr;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Spi_IrqUnitMcspi2TxRx;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_MCU_ISR_6;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_MAIN_ISR_34;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_MAIN_ISR_35;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_MCU_ISR_7;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_FltM_WkupEsmCfgInterrupt;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_FltM_WkupEsmLowInterrupt;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Spi_IrqUnitMcspi0TxRx;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_MainI2c2RtcIsr;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_MCU_ResetIsolationReq;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_FltM_FwlExceptionInterrupt;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr64;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr65;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr66;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr67;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr68;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr69;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr70;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr71;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr72;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr73;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr74;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr75;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr76;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr77;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr78;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Mcu_Udma_Vintr79;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_MainI2c1DacIsr;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsKernel_OsCoreAsr0;

extern CONST(OsAppConfigType, OS_CONST) OsAppConfig_TrustedSystem;
extern CONST(OsAppConfigType, OS_CONST) OsAppConfig_QMSystem;

extern CONST (OsObjConfigRefType, OS_CONST) OsApplication_TrustedSystemObjConfigRef[48];
extern CONST (OsObjConfigRefType, OS_CONST) OsApplication_QMSystemObjConfigRef[23];

extern const OsObjConfigRefType  OsObjRefConfig[OsMaxNumOfObjectId];

extern OsAppConfigRefType OsAppRefListDyn[OsNumberOfApplications];


#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

