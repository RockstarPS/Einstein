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
*    @file Os_IsrLcfg.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by SGOPAL1 at 2026-03-31 13:17:24.389555600
********************************************************************************************************************/

#ifndef OS_ISRLCFG_H
#define OS_ISRLCFG_H


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/



/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
*****************************************************************************/


extern const OsIsrConfigType OsIsrConfig_McuOsGptIsr;
extern const OsIsrConfigType OsIsrConfig_McuCan0RxTxIsr;
extern const OsIsrConfigType OsIsrConfig_McuCan1RxTxIsr;
extern const OsIsrConfigType OsIsrConfig_McuSpi0NvmRxTxIsr;
extern const OsIsrConfigType OsIsrConfig_McuDss0Isr;
extern const OsIsrConfigType OsIsrConfig_McuI2c3IoIsr;
extern const OsIsrConfigType OsIsrConfig_Eth_TxIrqHdlr_0;
extern const OsIsrConfigType OsIsrConfig_Eth_RxIrqHdlr_0;
extern const OsIsrConfigType OsIsrConfig_Eth_MdioIrqHdlr;
extern const OsIsrConfigType OsIsrConfig_FltM_WkupEsmHiInterrupt;
extern const OsIsrConfigType OsIsrConfig_MCU_IntrISR_UART0;
extern const OsIsrConfigType OsIsrConfig_McuI2c0PmicIsr;
extern const OsIsrConfigType OsIsrConfig_Gpt_Ch3Isr;
extern const OsIsrConfigType OsIsrConfig_Gpt_Ch4Isr;
extern const OsIsrConfigType OsIsrConfig_Spi_IrqUnitMcspi2TxRx;
extern const OsIsrConfigType OsIsrConfig_MCU_ISR_6;
extern const OsIsrConfigType OsIsrConfig_MAIN_ISR_34;
extern const OsIsrConfigType OsIsrConfig_MAIN_ISR_35;
extern const OsIsrConfigType OsIsrConfig_MCU_ISR_7;
extern const OsIsrConfigType OsIsrConfig_FltM_WkupEsmCfgInterrupt;
extern const OsIsrConfigType OsIsrConfig_FltM_WkupEsmLowInterrupt;
extern const OsIsrConfigType OsIsrConfig_Spi_IrqUnitMcspi0TxRx;
extern const OsIsrConfigType OsIsrConfig_MainI2c2RtcIsr;
extern const OsIsrConfigType OsIsrConfig_MCU_ResetIsolationReq;
extern const OsIsrConfigType OsIsrConfig_FltM_FwlExceptionInterrupt;
extern const OsIsrConfigType OsIsrConfig_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0;
extern const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr64;
extern const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr65;
extern const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr66;
extern const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr67;
extern const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr68;
extern const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr69;
extern const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr70;
extern const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr71;
extern const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr72;
extern const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr73;
extern const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr74;
extern const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr75;
extern const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr76;
extern const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr77;
extern const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr78;
extern const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr79;
extern const OsIsrConfigType OsIsrConfig_MainI2c1DacIsr;
extern const OsIsrConfigRefType OsIsrRefConfig[OsNumberOfIsr];
extern const osStackPtrType IsrStackConfig[osdNumberOfCat2ISRs];
extern const osStackDataType IsrStackSize[osdNumberOfCat2ISRs];


extern void osTimerInterruptfunc(void);
extern void Can_0_Int0ISRfunc(void);
extern void Can_1_Int0ISRfunc(void);
extern void Spi_IrqUnitMcuMcspi0TxRxfunc(void);
extern void Dss_0_Isrfunc(void);
extern void McuI2c3IoIsrfunc(void);
extern void Eth_TxIrqHdlr_0func(void);
extern void Eth_RxIrqHdlr_0func(void);
extern void Eth_MdioIrqHdlrfunc(void);
extern void FltM_WkupEsmHiInterruptfunc(void);
extern void MCU_IntrISR_UART0func(void);
extern void McuI2c0PmicIsrfunc(void);
extern void Gpt_Ch3Isrfunc(void);
extern void Gpt_Ch4Isrfunc(void);
extern void Spi_IrqUnitMcspi2TxRxfunc(void);
extern void MCU_ISR_6func(void);
extern void MAIN_ISR_34func(void);
extern void MAIN_ISR_35func(void);
extern void MCU_ISR_7func(void);
extern void FltM_WkupEsmCfgInterruptfunc(void);
extern void FltM_WkupEsmLowInterruptfunc(void);
extern void Spi_IrqUnitMcspi0TxRxfunc(void);
extern void MainI2c2RtcIsrfunc(void);
extern void MCU_ResetIsolationReqfunc(void);
extern void FltM_FwlExceptionInterruptfunc(void);
extern void Cdd_IpcIrqMbxFromWKUP_R5FSS0_0func(void);
extern void Mcu_Udma_Vintr64func(void);
extern void Mcu_Udma_Vintr65func(void);
extern void Mcu_Udma_Vintr66func(void);
extern void Mcu_Udma_Vintr67func(void);
extern void Mcu_Udma_Vintr68func(void);
extern void Mcu_Udma_Vintr69func(void);
extern void Mcu_Udma_Vintr70func(void);
extern void Mcu_Udma_Vintr71func(void);
extern void Mcu_Udma_Vintr72func(void);
extern void Mcu_Udma_Vintr73func(void);
extern void Mcu_Udma_Vintr74func(void);
extern void Mcu_Udma_Vintr75func(void);
extern void Mcu_Udma_Vintr76func(void);
extern void Mcu_Udma_Vintr77func(void);
extern void Mcu_Udma_Vintr78func(void);
extern void Mcu_Udma_Vintr79func(void);
extern void MainI2c1DacIsrfunc(void);


#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

