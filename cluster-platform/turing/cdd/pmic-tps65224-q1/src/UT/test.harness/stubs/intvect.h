/******************************************************************************
**              CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2012. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have  jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation
**
******************************************************************************/

/******************************************************************************

File Name        :  intvect.h
Module Short Name:  intvect.h
VOBName          :  
Author           :  
Description      :
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

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
#define CLANG_CAT1_INTERRUPT          __attribute__((interrupt))
#define CLANG_CAT2_INTERRUPT

#define osdNumberOfIRQs                     256
#define osdNumberOfSysUserCpuIRQs           0
#define osdNumberOfConfiguredIRQs           20U
#define osdNumberOfFIQs                     32
#define osdNumberOfConfiguredFIQs           0
#define osdNumberOfExceptions               8


                                                                              
/*****************************************************************************
*                                 Type Decleration                           *
*----------------------------------------------------------------------------*
* Decleration of type shall be accompanied by a comment that explains the    *
* purpose and usage of the type.                                             *
*****************************************************************************/
                                                                              
typedef osuint8        osIntLevelType;


typedef struct {
    osuint16        osIPNumber;
    osIntLevelType  osIPLevel;
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
void Cdd_IpcIrqMbxFromA53SS_0_0func(void);
void Spi_IrqUnitMcuMcspi0TxRxfunc(void);
void Dss_0_Isrfunc(void);
void McuI2c3IoIsrfunc(void);
void Eth_TxIrqHdlr_0func(void);
void Eth_RxIrqHdlr_0func(void);
void Eth_MdioIrqHdlrfunc(void);
void WkupEsmIntrfunc(void);
void MCU_IntrISR_UART0func(void);
void McuI2c0PmicIsrfunc(void);
void Gpt_Ch3Isrfunc(void);
void Gpt_Ch4Isrfunc(void);
void Spi_IrqUnitMcspi2TxRxfunc(void);
void MCU_ISR_6func(void);
void MAIN_ISR_34func(void);
void MAIN_ISR_35func(void);
void MCU_ISR_7func(void);


/* ISR Hook function prototypes */

CLANG_CAT2_INTERRUPT void osCallISRHooks_McuOsGptIsr(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_McuCan0RxTxIsr(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_McuCan1RxTxIsr(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_McuCddIpcMbxFromA53SS_0_0Isr(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_McuSpi0NvmRxTxIsr(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_McuDss0Isr(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_McuI2c3IoIsr(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_Eth_TxIrqHdlr_0(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_Eth_RxIrqHdlr_0(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_Eth_MdioIrqHdlr(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_McuEsmIsr(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_MCU_IntrISR_UART0(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_McuI2c0PmicIsr(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_Gpt_Ch3Isr(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_Gpt_Ch4Isr(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_Spi_IrqUnitMcspi2TxRx(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_MCU_ISR_6(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_MAIN_ISR_34(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_MAIN_ISR_35(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_MCU_ISR_7(void);


extern void UserPreISRHook(ISRType x);
extern void UserPostISRHook(ISRType x);
extern void osSetupConfiguredInterrupts (void);


extern void osISRWrap_McuOsGptIsr (void);
extern void osISRWrap_McuCan0RxTxIsr (void);
extern void osISRWrap_McuCan1RxTxIsr (void);
extern void osISRWrap_McuCddIpcMbxFromA53SS_0_0Isr (void);
extern void osISRWrap_McuSpi0NvmRxTxIsr (void);
extern void osISRWrap_McuDss0Isr (void);
extern void osISRWrap_McuI2c3IoIsr (void);
extern void osISRWrap_Eth_TxIrqHdlr_0 (void);
extern void osISRWrap_Eth_RxIrqHdlr_0 (void);
extern void osISRWrap_Eth_MdioIrqHdlr (void);
extern void osISRWrap_McuEsmIsr (void);
extern void osISRWrap_MCU_IntrISR_UART0 (void);
extern void osISRWrap_McuI2c0PmicIsr (void);
extern void osISRWrap_Gpt_Ch3Isr (void);
extern void osISRWrap_Gpt_Ch4Isr (void);
extern void osISRWrap_Spi_IrqUnitMcspi2TxRx (void);
extern void osISRWrap_MCU_ISR_6 (void);
extern void osISRWrap_MAIN_ISR_34 (void);
extern void osISRWrap_MAIN_ISR_35 (void);
extern void osISRWrap_MCU_ISR_7 (void);



#endif    /* */
/* end of file */
/****************************************************************
Created Time: 10-02-2025 11:13:58
****************************************************************/
