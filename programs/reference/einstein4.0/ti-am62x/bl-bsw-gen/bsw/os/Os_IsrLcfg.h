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
*    Auto generated code in vAUTOSAR TOOL by MNATRAMI at 2026-04-06 16:31:56.382885
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
extern const OsIsrConfigType OsIsrConfig_McuI2c3IoIsr;
extern const OsIsrConfigType OsIsrConfig_McuI2c0PmicIsr;
extern const OsIsrConfigType OsIsrConfig_Gpt_Ch3Isr;
extern const OsIsrConfigType OsIsrConfig_Gpt_Ch4Isr;
extern const OsIsrConfigType OsIsrConfig_PmicCdd_nINTGpioInterrupt;
extern const OsIsrConfigType OsIsrConfig_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0;
extern const OsIsrConfigRefType OsIsrRefConfig[OsNumberOfIsr];
extern const osStackPtrType IsrStackConfig[osdNumberOfCat2ISRs];
extern const osStackDataType IsrStackSize[osdNumberOfCat2ISRs];


extern void osTimerInterruptfunc(void);
extern void Can_0_Int0ISRfunc(void);
extern void Can_1_Int0ISRfunc(void);
extern void McuI2c3IoIsrfunc(void);
extern void McuI2c0PmicIsrfunc(void);
extern void Gpt_Ch3Isrfunc(void);
extern void Gpt_Ch4Isrfunc(void);
extern void PmicCdd_nINTGpioInterruptfunc(void);
extern void Cdd_IpcIrqMbxFromWKUP_R5FSS0_0(void);


#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

