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
#define osdNumberOfConfiguredIRQs           6U
#define osdNumberOfFIQs                     32
#define osdNumberOfConfiguredFIQs           0
#define osdNumberOfCat2ISRs                 6U
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
void McuI2c_InterruptHandlerfunc(void);


/* ISR Hook function prototypes */

CLANG_CAT2_INTERRUPT void osCallISRHooks_OsIsr_SystemTimer(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_Can_0_Int0ISR(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_Can_1_Int0ISR(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_Cdd_IpcIrqMbxFromA53SS_0_0(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_Spi_IrqUnitMcuMcspi0TxRx(void);
CLANG_CAT2_INTERRUPT void osCallISRHooks_McuI2c_InterruptHandler(void);


extern void UserPreISRHook(ISRType x);
extern void UserPostISRHook(ISRType x);
extern void osSetupConfiguredInterrupts (void);


extern void osISRWrap_OsIsr_SystemTimer (void);
extern void osISRWrap_Can_0_Int0ISR (void);
extern void osISRWrap_Can_1_Int0ISR (void);
extern void osISRWrap_Cdd_IpcIrqMbxFromA53SS_0_0 (void);
extern void osISRWrap_Spi_IrqUnitMcuMcspi0TxRx (void);
extern void osISRWrap_McuI2c_InterruptHandler (void);



#endif    /* */
/* end of file */
/****************************************************************
Created Time: 2/19/2024 9:51:31 AM
****************************************************************/
