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
*    @file Os_IntvectCfg.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by MNATRAMI at 2026-04-06 16:31:56.351151300
********************************************************************************************************************/

#ifndef INTVECT_H
#define INTVECT_H
#include "OsMain.h"

/*****************************************************************************
*                                 Constant Declarations                      *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the constant.                                                        *
* purpose, unit, and resolution                                              *
*****************************************************************************/

/*****************************************************************************
*                                 Global Macro Definitions                   *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
*****************************************************************************/
#define CLANG_CAT1_INTERRUPT			__attribute__((interrupt))
#define CLANG_CAT2_INTERRUPT
#define osdNumberOfIRQs						256
#define osdNumberOfSysUserCpuIRQs			0
#define osdNumberOfConfiguredIRQs			9U
#define osdNumberOfFIQs						32
#define osdNumberOfConfiguredFIQs			0
#define osdNumberOfExceptions				8



/*****************************************************************************
*                                 Type Decleration                           *
*----------------------------------------------------------------------------*
* Decleration of type shall be accompanied by a comment that explains the    *
* purpose and usage of the type.                                             *
*****************************************************************************/



typedef struct {
	osuint16		osIPNumber;
	osIntLevelType	osIPLevel;
}osIntPrioType;


/*****************************************************************************
*                                 Global Variable Declarations               *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
*****************************************************************************/

extern const osVoidFunctionType osIRQTable[osdNumberOfIRQs];
extern const osIntPrioType osIRQPrioTable[osdNumberOfConfiguredIRQs+1];
extern const osVoidFunctionType osFIQTable[osdNumberOfFIQs];
extern const osVoidFunctionType osExceptionTable[osdNumberOfExceptions];


/*****************************************************************************
*                                 Global Function Prototypes                 *
*****************************************************************************/


/* ISR function prototypes */

void osTimerInterruptfunc(void);
void Can_0_Int0ISRfunc(void);
void Can_1_Int0ISRfunc(void);
void McuI2c3IoIsrfunc(void);
void McuI2c0PmicIsrfunc(void);
void Gpt_Ch3Isrfunc(void);
void Gpt_Ch4Isrfunc(void);
void PmicCdd_nINTGpioInterruptfunc(void);
void Cdd_IpcIrqMbxFromWKUP_R5FSS0_0(void);

/* ISR Hook function prototypes */

CLANG_CAT2_INTERRUPT void osCallISRHooks_McuOsGptIsr(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_McuCan0RxTxIsr(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_McuCan1RxTxIsr(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_McuI2c3IoIsr(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_McuI2c0PmicIsr(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_Gpt_Ch3Isr(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_Gpt_Ch4Isr(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_PmicCdd_nINTGpioInterrupt(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0(void);


extern void UserPreISRHook(ISRType x);
extern void UserPostISRHook(ISRType x);
extern void osSetupConfiguredInterrupts (void);

extern void osISRWrap_McuOsGptIsr(void);
extern void osISRWrap_McuCan0RxTxIsr(void);
extern void osISRWrap_McuCan1RxTxIsr(void);
extern void osISRWrap_McuI2c3IoIsr(void);
extern void osISRWrap_McuI2c0PmicIsr(void);
extern void osISRWrap_Gpt_Ch3Isr(void);
extern void osISRWrap_Gpt_Ch4Isr(void);
extern void osISRWrap_PmicCdd_nINTGpioInterrupt(void);
extern void osISRWrap_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0(void);


#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

