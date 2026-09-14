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
*    Auto generated code in vAUTOSAR TOOL by MNATRAMI at 2026-04-06 16:31:56.382885
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
const OsIsrConfigType OsIsrConfig_McuI2c3IoIsr =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 196,
	/*Stacksize			=*/ osStackSizeIsr_3,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_McuI2c3IoIsr,
	/*IsrAPIFunction	=*/ &McuI2c3IoIsrfunc,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_McuI2c3IoIsr)
};
const OsIsrConfigType OsIsrConfig_McuI2c0PmicIsr =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 197,
	/*Stacksize			=*/ osStackSizeIsr_4,
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
	/*Stacksize			=*/ osStackSizeIsr_5,
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
	/*Stacksize			=*/ osStackSizeIsr_6,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Gpt_Ch4Isr,
	/*IsrAPIFunction	=*/ &Gpt_Ch4Isrfunc,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Gpt_Ch4Isr)
};
const OsIsrConfigType OsIsrConfig_PmicCdd_nINTGpioInterrupt =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 106,
	/*Stacksize			=*/ osStackSizeIsr_7,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_PmicCdd_nINTGpioInterrupt,
	/*IsrAPIFunction	=*/ &PmicCdd_nINTGpioInterruptfunc,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_PmicCdd_nINTGpioInterrupt)
};
const OsIsrConfigType OsIsrConfig_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0 =
{
	/*IsrCategory		=*/ CAT2,
	/*IsrNesting		=*/ FALSE,
	/*IsrEnableSource	=*/ FALSE,
	/*IsrMapping		=*/ 0,
	/*IsrSource			=*/ 242,
	/*Stacksize			=*/ osStackSizeIsr_8,
	/*ResourceRef		=*/ NULL_PTR,
	/*PrioLevel			=*/ osIsrPrioLevel_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0,
	/*IsrAPIFunction	=*/ &Cdd_IpcIrqMbxFromWKUP_R5FSS0_0,
	/*ObjRef			=*/ (OsObjConfigRefType)(&OsObjConfig_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0)
};

const OsIsrConfigRefType OsIsrRefConfig[OsNumberOfIsr] = {
(OsIsrConfigRefType)&OsIsrConfig_McuOsGptIsr,
(OsIsrConfigRefType)&OsIsrConfig_McuCan0RxTxIsr,
(OsIsrConfigRefType)&OsIsrConfig_McuCan1RxTxIsr,
(OsIsrConfigRefType)&OsIsrConfig_McuI2c3IoIsr,
(OsIsrConfigRefType)&OsIsrConfig_McuI2c0PmicIsr,
(OsIsrConfigRefType)&OsIsrConfig_Gpt_Ch3Isr,
(OsIsrConfigRefType)&OsIsrConfig_Gpt_Ch4Isr,
(OsIsrConfigRefType)&OsIsrConfig_PmicCdd_nINTGpioInterrupt,
(OsIsrConfigRefType)&OsIsrConfig_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0
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
osStackStartAddressIsr_8
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
osStackSizeIsr_8
};



#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

