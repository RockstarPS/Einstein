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
*    @file Os_IsrLcfg.c
*    @ingroup Os Configuration
*    @brief This is Os link time configuration source file. It contains definitions of link time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by SGOPAL1 at 2026-03-31 13:17:24.380038300
********************************************************************************************************************/

#ifndef OSISR_LCFG_C
#define OSISR_LCFG_C


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/

#include "Os_Lcfg.h"

const OsIsrConfigType OsIsrConfig_McuOsGptIsr =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 28,
	/*Stacksize			=*/ osStackSizeIsr_0,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_McuOsGptIsr,
	/*IsrAPIFunction	=*/ &osTimerInterruptfunc,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_McuOsGptIsr)
};
const OsIsrConfigType OsIsrConfig_McuCan0RxTxIsr =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 43,
	/*Stacksize			=*/ osStackSizeIsr_1,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_McuCan0RxTxIsr,
	/*IsrAPIFunction	=*/ &Can_0_Int0ISRfunc,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_McuCan0RxTxIsr)
};
const OsIsrConfigType OsIsrConfig_McuCan1RxTxIsr =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 46,
	/*Stacksize			=*/ osStackSizeIsr_2,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_McuCan1RxTxIsr,
	/*IsrAPIFunction	=*/ &Can_1_Int0ISRfunc,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_McuCan1RxTxIsr)
};
const OsIsrConfigType OsIsrConfig_McuSpi0NvmRxTxIsr =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 207,
	/*Stacksize			=*/ osStackSizeIsr_3,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_McuSpi0NvmRxTxIsr,
	/*IsrAPIFunction	=*/ &Spi_IrqUnitMcuMcspi0TxRxfunc,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_McuSpi0NvmRxTxIsr)
};
const OsIsrConfigType OsIsrConfig_McuDss0Isr =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 40,
	/*Stacksize			=*/ osStackSizeIsr_4,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_McuDss0Isr,
	/*IsrAPIFunction	=*/ &Dss_0_Isrfunc,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_McuDss0Isr)
};
const OsIsrConfigType OsIsrConfig_McuI2c3IoIsr =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 196,
	/*Stacksize			=*/ osStackSizeIsr_5,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_McuI2c3IoIsr,
	/*IsrAPIFunction	=*/ &McuI2c3IoIsrfunc,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_McuI2c3IoIsr)
};
const OsIsrConfigType OsIsrConfig_Eth_TxIrqHdlr_0 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 66,
	/*Stacksize			=*/ osStackSizeIsr_6,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Eth_TxIrqHdlr_0,
	/*IsrAPIFunction	=*/ &Eth_TxIrqHdlr_0func,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Eth_TxIrqHdlr_0)
};
const OsIsrConfigType OsIsrConfig_Eth_RxIrqHdlr_0 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 67,
	/*Stacksize			=*/ osStackSizeIsr_7,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Eth_RxIrqHdlr_0,
	/*IsrAPIFunction	=*/ &Eth_RxIrqHdlr_0func,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Eth_RxIrqHdlr_0)
};
const OsIsrConfigType OsIsrConfig_Eth_MdioIrqHdlr =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 135,
	/*Stacksize			=*/ osStackSizeIsr_8,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Eth_MdioIrqHdlr,
	/*IsrAPIFunction	=*/ &Eth_MdioIrqHdlrfunc,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Eth_MdioIrqHdlr)
};
const OsIsrConfigType OsIsrConfig_FltM_WkupEsmHiInterrupt =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 141,
	/*Stacksize			=*/ osStackSizeIsr_9,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_FltM_WkupEsmHiInterrupt,
	/*IsrAPIFunction	=*/ &FltM_WkupEsmHiInterruptfunc,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_FltM_WkupEsmHiInterrupt)
};
const OsIsrConfigType OsIsrConfig_MCU_IntrISR_UART0 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 217,
	/*Stacksize			=*/ osStackSizeIsr_10,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_MCU_IntrISR_UART0,
	/*IsrAPIFunction	=*/ &MCU_IntrISR_UART0func,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_MCU_IntrISR_UART0)
};
const OsIsrConfigType OsIsrConfig_McuI2c0PmicIsr =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 197,
	/*Stacksize			=*/ osStackSizeIsr_11,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_McuI2c0PmicIsr,
	/*IsrAPIFunction	=*/ &McuI2c0PmicIsrfunc,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_McuI2c0PmicIsr)
};
const OsIsrConfigType OsIsrConfig_Gpt_Ch3Isr =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 138,
	/*Stacksize			=*/ osStackSizeIsr_12,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Gpt_Ch3Isr,
	/*IsrAPIFunction	=*/ &Gpt_Ch3Isrfunc,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Gpt_Ch3Isr)
};
const OsIsrConfigType OsIsrConfig_Gpt_Ch4Isr =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 139,
	/*Stacksize			=*/ osStackSizeIsr_13,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Gpt_Ch4Isr,
	/*IsrAPIFunction	=*/ &Gpt_Ch4Isrfunc,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Gpt_Ch4Isr)
};
const OsIsrConfigType OsIsrConfig_Spi_IrqUnitMcspi2TxRx =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 206,
	/*Stacksize			=*/ osStackSizeIsr_14,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Spi_IrqUnitMcspi2TxRx,
	/*IsrAPIFunction	=*/ &Spi_IrqUnitMcspi2TxRxfunc,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Spi_IrqUnitMcspi2TxRx)
};
const OsIsrConfigType OsIsrConfig_MCU_ISR_6 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 106,
	/*Stacksize			=*/ osStackSizeIsr_15,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_MCU_ISR_6,
	/*IsrAPIFunction	=*/ &MCU_ISR_6func,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_MCU_ISR_6)
};
const OsIsrConfigType OsIsrConfig_MAIN_ISR_34 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 32,
	/*Stacksize			=*/ osStackSizeIsr_16,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_MAIN_ISR_34,
	/*IsrAPIFunction	=*/ &MAIN_ISR_34func,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_MAIN_ISR_34)
};
const OsIsrConfigType OsIsrConfig_MAIN_ISR_35 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 33,
	/*Stacksize			=*/ osStackSizeIsr_17,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_MAIN_ISR_35,
	/*IsrAPIFunction	=*/ &MAIN_ISR_35func,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_MAIN_ISR_35)
};
const OsIsrConfigType OsIsrConfig_MCU_ISR_7 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 107,
	/*Stacksize			=*/ osStackSizeIsr_18,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_MCU_ISR_7,
	/*IsrAPIFunction	=*/ &MCU_ISR_7func,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_MCU_ISR_7)
};
const OsIsrConfigType OsIsrConfig_FltM_WkupEsmCfgInterrupt =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 140,
	/*Stacksize			=*/ osStackSizeIsr_19,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_FltM_WkupEsmCfgInterrupt,
	/*IsrAPIFunction	=*/ &FltM_WkupEsmCfgInterruptfunc,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_FltM_WkupEsmCfgInterrupt)
};
const OsIsrConfigType OsIsrConfig_FltM_WkupEsmLowInterrupt =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 142,
	/*Stacksize			=*/ osStackSizeIsr_20,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_FltM_WkupEsmLowInterrupt,
	/*IsrAPIFunction	=*/ &FltM_WkupEsmLowInterruptfunc,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_FltM_WkupEsmLowInterrupt)
};
const OsIsrConfigType OsIsrConfig_Spi_IrqUnitMcspi0TxRx =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 204,
	/*Stacksize			=*/ osStackSizeIsr_21,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Spi_IrqUnitMcspi0TxRx,
	/*IsrAPIFunction	=*/ &Spi_IrqUnitMcspi0TxRxfunc,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Spi_IrqUnitMcspi0TxRx)
};
const OsIsrConfigType OsIsrConfig_MainI2c2RtcIsr =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 195,
	/*Stacksize			=*/ osStackSizeIsr_22,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_MainI2c2RtcIsr,
	/*IsrAPIFunction	=*/ &MainI2c2RtcIsrfunc,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_MainI2c2RtcIsr)
};
const OsIsrConfigType OsIsrConfig_MCU_ResetIsolationReq =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 101,
	/*Stacksize			=*/ osStackSizeIsr_23,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_MCU_ResetIsolationReq,
	/*IsrAPIFunction	=*/ &MCU_ResetIsolationReqfunc,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_MCU_ResetIsolationReq)
};
const OsIsrConfigType OsIsrConfig_FltM_FwlExceptionInterrupt =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 20,
	/*Stacksize			=*/ osStackSizeIsr_24,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_FltM_FwlExceptionInterrupt,
	/*IsrAPIFunction	=*/ &FltM_FwlExceptionInterruptfunc,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_FltM_FwlExceptionInterrupt)
};
const OsIsrConfigType OsIsrConfig_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 242,
	/*Stacksize			=*/ osStackSizeIsr_25,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0,
	/*IsrAPIFunction	=*/ &Cdd_IpcIrqMbxFromWKUP_R5FSS0_0func,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0)
};
const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr64 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 64,
	/*Stacksize			=*/ osStackSizeIsr_26,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Mcu_Udma_Vintr64,
	/*IsrAPIFunction	=*/ &Mcu_Udma_Vintr64func,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr64)
};
const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr65 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 65,
	/*Stacksize			=*/ osStackSizeIsr_27,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Mcu_Udma_Vintr65,
	/*IsrAPIFunction	=*/ &Mcu_Udma_Vintr65func,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr65)
};
const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr66 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 66,
	/*Stacksize			=*/ osStackSizeIsr_28,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Mcu_Udma_Vintr66,
	/*IsrAPIFunction	=*/ &Mcu_Udma_Vintr66func,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr66)
};
const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr67 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 67,
	/*Stacksize			=*/ osStackSizeIsr_29,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Mcu_Udma_Vintr67,
	/*IsrAPIFunction	=*/ &Mcu_Udma_Vintr67func,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr67)
};
const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr68 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 68,
	/*Stacksize			=*/ osStackSizeIsr_30,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Mcu_Udma_Vintr68,
	/*IsrAPIFunction	=*/ &Mcu_Udma_Vintr68func,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr68)
};
const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr69 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 69,
	/*Stacksize			=*/ osStackSizeIsr_31,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Mcu_Udma_Vintr69,
	/*IsrAPIFunction	=*/ &Mcu_Udma_Vintr69func,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr69)
};
const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr70 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 70,
	/*Stacksize			=*/ osStackSizeIsr_32,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Mcu_Udma_Vintr70,
	/*IsrAPIFunction	=*/ &Mcu_Udma_Vintr70func,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr70)
};
const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr71 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 71,
	/*Stacksize			=*/ osStackSizeIsr_33,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Mcu_Udma_Vintr71,
	/*IsrAPIFunction	=*/ &Mcu_Udma_Vintr71func,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr71)
};
const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr72 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 72,
	/*Stacksize			=*/ osStackSizeIsr_34,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Mcu_Udma_Vintr72,
	/*IsrAPIFunction	=*/ &Mcu_Udma_Vintr72func,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr72)
};
const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr73 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 73,
	/*Stacksize			=*/ osStackSizeIsr_35,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Mcu_Udma_Vintr73,
	/*IsrAPIFunction	=*/ &Mcu_Udma_Vintr73func,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr73)
};
const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr74 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 74,
	/*Stacksize			=*/ osStackSizeIsr_36,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Mcu_Udma_Vintr74,
	/*IsrAPIFunction	=*/ &Mcu_Udma_Vintr74func,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr74)
};
const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr75 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 75,
	/*Stacksize			=*/ osStackSizeIsr_37,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Mcu_Udma_Vintr75,
	/*IsrAPIFunction	=*/ &Mcu_Udma_Vintr75func,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr75)
};
const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr76 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 76,
	/*Stacksize			=*/ osStackSizeIsr_38,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Mcu_Udma_Vintr76,
	/*IsrAPIFunction	=*/ &Mcu_Udma_Vintr76func,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr76)
};
const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr77 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 77,
	/*Stacksize			=*/ osStackSizeIsr_39,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Mcu_Udma_Vintr77,
	/*IsrAPIFunction	=*/ &Mcu_Udma_Vintr77func,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr77)
};
const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr78 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 78,
	/*Stacksize			=*/ osStackSizeIsr_40,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Mcu_Udma_Vintr78,
	/*IsrAPIFunction	=*/ &Mcu_Udma_Vintr78func,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr78)
};
const OsIsrConfigType OsIsrConfig_Mcu_Udma_Vintr79 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 79,
	/*Stacksize			=*/ osStackSizeIsr_41,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Mcu_Udma_Vintr79,
	/*IsrAPIFunction	=*/ &Mcu_Udma_Vintr79func,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Mcu_Udma_Vintr79)
};
const OsIsrConfigType OsIsrConfig_MainI2c1DacIsr =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 194,
	/*Stacksize			=*/ osStackSizeIsr_42,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_MainI2c1DacIsr,
	/*IsrAPIFunction	=*/ &MainI2c1DacIsrfunc,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_MainI2c1DacIsr)
};

const OsIsrConfigRefType OsIsrRefConfig[OsNumberOfIsr] = {
(OsIsrConfigRefType)&OsIsrConfig_McuOsGptIsr,
(OsIsrConfigRefType)&OsIsrConfig_McuCan0RxTxIsr,
(OsIsrConfigRefType)&OsIsrConfig_McuCan1RxTxIsr,
(OsIsrConfigRefType)&OsIsrConfig_McuSpi0NvmRxTxIsr,
(OsIsrConfigRefType)&OsIsrConfig_McuDss0Isr,
(OsIsrConfigRefType)&OsIsrConfig_McuI2c3IoIsr,
(OsIsrConfigRefType)&OsIsrConfig_Eth_TxIrqHdlr_0,
(OsIsrConfigRefType)&OsIsrConfig_Eth_RxIrqHdlr_0,
(OsIsrConfigRefType)&OsIsrConfig_Eth_MdioIrqHdlr,
(OsIsrConfigRefType)&OsIsrConfig_FltM_WkupEsmHiInterrupt,
(OsIsrConfigRefType)&OsIsrConfig_MCU_IntrISR_UART0,
(OsIsrConfigRefType)&OsIsrConfig_McuI2c0PmicIsr,
(OsIsrConfigRefType)&OsIsrConfig_Gpt_Ch3Isr,
(OsIsrConfigRefType)&OsIsrConfig_Gpt_Ch4Isr,
(OsIsrConfigRefType)&OsIsrConfig_Spi_IrqUnitMcspi2TxRx,
(OsIsrConfigRefType)&OsIsrConfig_MCU_ISR_6,
(OsIsrConfigRefType)&OsIsrConfig_MAIN_ISR_34,
(OsIsrConfigRefType)&OsIsrConfig_MAIN_ISR_35,
(OsIsrConfigRefType)&OsIsrConfig_MCU_ISR_7,
(OsIsrConfigRefType)&OsIsrConfig_FltM_WkupEsmCfgInterrupt,
(OsIsrConfigRefType)&OsIsrConfig_FltM_WkupEsmLowInterrupt,
(OsIsrConfigRefType)&OsIsrConfig_Spi_IrqUnitMcspi0TxRx,
(OsIsrConfigRefType)&OsIsrConfig_MainI2c2RtcIsr,
(OsIsrConfigRefType)&OsIsrConfig_MCU_ResetIsolationReq,
(OsIsrConfigRefType)&OsIsrConfig_FltM_FwlExceptionInterrupt,
(OsIsrConfigRefType)&OsIsrConfig_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0,
(OsIsrConfigRefType)&OsIsrConfig_Mcu_Udma_Vintr64,
(OsIsrConfigRefType)&OsIsrConfig_Mcu_Udma_Vintr65,
(OsIsrConfigRefType)&OsIsrConfig_Mcu_Udma_Vintr66,
(OsIsrConfigRefType)&OsIsrConfig_Mcu_Udma_Vintr67,
(OsIsrConfigRefType)&OsIsrConfig_Mcu_Udma_Vintr68,
(OsIsrConfigRefType)&OsIsrConfig_Mcu_Udma_Vintr69,
(OsIsrConfigRefType)&OsIsrConfig_Mcu_Udma_Vintr70,
(OsIsrConfigRefType)&OsIsrConfig_Mcu_Udma_Vintr71,
(OsIsrConfigRefType)&OsIsrConfig_Mcu_Udma_Vintr72,
(OsIsrConfigRefType)&OsIsrConfig_Mcu_Udma_Vintr73,
(OsIsrConfigRefType)&OsIsrConfig_Mcu_Udma_Vintr74,
(OsIsrConfigRefType)&OsIsrConfig_Mcu_Udma_Vintr75,
(OsIsrConfigRefType)&OsIsrConfig_Mcu_Udma_Vintr76,
(OsIsrConfigRefType)&OsIsrConfig_Mcu_Udma_Vintr77,
(OsIsrConfigRefType)&OsIsrConfig_Mcu_Udma_Vintr78,
(OsIsrConfigRefType)&OsIsrConfig_Mcu_Udma_Vintr79,
(OsIsrConfigRefType)&OsIsrConfig_MainI2c1DacIsr
};

const osStackPtrType IsrStackConfig[osdNumberOfCat2ISRs] =
{
osStackStartAddressIsr_0,
osStackStartAddressIsr_1,
osStackStartAddressIsr_2,
osStackStartAddressIsr_3,
osStackStartAddressIsr_4,
osStackStartAddressIsr_5,
osStackStartAddressIsr_6,
osStackStartAddressIsr_7,
osStackStartAddressIsr_8,
osStackStartAddressIsr_9,
osStackStartAddressIsr_10,
osStackStartAddressIsr_11,
osStackStartAddressIsr_12,
osStackStartAddressIsr_13,
osStackStartAddressIsr_14,
osStackStartAddressIsr_15,
osStackStartAddressIsr_16,
osStackStartAddressIsr_17,
osStackStartAddressIsr_18,
osStackStartAddressIsr_19,
osStackStartAddressIsr_20,
osStackStartAddressIsr_21,
osStackStartAddressIsr_22,
osStackStartAddressIsr_23,
osStackStartAddressIsr_24,
osStackStartAddressIsr_25,
osStackStartAddressIsr_26,
osStackStartAddressIsr_27,
osStackStartAddressIsr_28,
osStackStartAddressIsr_29,
osStackStartAddressIsr_30,
osStackStartAddressIsr_31,
osStackStartAddressIsr_32,
osStackStartAddressIsr_33,
osStackStartAddressIsr_34,
osStackStartAddressIsr_35,
osStackStartAddressIsr_36,
osStackStartAddressIsr_37,
osStackStartAddressIsr_38,
osStackStartAddressIsr_39,
osStackStartAddressIsr_40,
osStackStartAddressIsr_41,
osStackStartAddressIsr_42
};

const osStackDataType IsrStackSize[osdNumberOfCat2ISRs] =
{
osStackSizeIsr_0,
osStackSizeIsr_1,
osStackSizeIsr_2,
osStackSizeIsr_3,
osStackSizeIsr_4,
osStackSizeIsr_5,
osStackSizeIsr_6,
osStackSizeIsr_7,
osStackSizeIsr_8,
osStackSizeIsr_9,
osStackSizeIsr_10,
osStackSizeIsr_11,
osStackSizeIsr_12,
osStackSizeIsr_13,
osStackSizeIsr_14,
osStackSizeIsr_15,
osStackSizeIsr_16,
osStackSizeIsr_17,
osStackSizeIsr_18,
osStackSizeIsr_19,
osStackSizeIsr_20,
osStackSizeIsr_21,
osStackSizeIsr_22,
osStackSizeIsr_23,
osStackSizeIsr_24,
osStackSizeIsr_25,
osStackSizeIsr_26,
osStackSizeIsr_27,
osStackSizeIsr_28,
osStackSizeIsr_29,
osStackSizeIsr_30,
osStackSizeIsr_31,
osStackSizeIsr_32,
osStackSizeIsr_33,
osStackSizeIsr_34,
osStackSizeIsr_35,
osStackSizeIsr_36,
osStackSizeIsr_37,
osStackSizeIsr_38,
osStackSizeIsr_39,
osStackSizeIsr_40,
osStackSizeIsr_41,
osStackSizeIsr_42
};



#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

