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
#define GHS_CAT1_INTERRUPT          _Pragma("ghs nofloat interrupt")
#define GHS_CAT2_INTERRUPT

#define osdNumberOfIRQs                     512
#define osdNumberOfSysUserCpuIRQs           0
#define osdNumberOfConfiguredIRQs           10U
#define osdNumberOfFIQs                     32
#define osdNumberOfConfiguredFIQs           0
#define osdNumberOfCat2ISRs                 10U
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
                                                                              




#define osGenNumOfCat1IRQs         0U
#define osGenNumOfCat2IRQs         10U

/* ISR function prototypes */

void IRQSTEER_EXT_4_ISR_func(void);
void IRQSTEER_EXT_1_ISR_func(void);
void IRQSTEER_EXT_3_ISR_func(void);
void IRQSTEER_EXT_2_ISR_func(void);
void osTimerInterruptfunc(void);
void CanIsr_1func(void);
void ADC_SARADC_ISR_UNIT0(void);
void GPT_2_ISR(void);
void GPT_3_ISR(void);
void Spi_LPspi_IsrTDF_LPSPI_0(void);
void Spi_LPspi_IsrTDF_LPSPI_2(void);
void LPIT_0_ISRfunc(void);
void GPT_4_ISR(void);
void ICU_GPIO_0_ISR(void);


/* ISR Hook function prototypes */

GHS_CAT2_INTERRUPT void osCallISRHooks_SystemTimerISR(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_IRQSTEER_EXT_4_ISR(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_IRQSTEER_EXT_1_ISR(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_IRQSTEER_EXT_3_ISR(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_GPT_LPIT(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_IRQSTEER_EXT_2_ISR(void);


extern void osSetupConfiguredInterrupts (void);


extern void osISRWrap_SystemTimerISR (void);
extern void osISRWrap_IRQSTEER_EXT_4_ISR (void);
extern void osISRWrap_IRQSTEER_EXT_1_ISR (void);
extern void osISRWrap_IRQSTEER_EXT_3_ISR (void);
extern void osISRWrap_GPT_LPIT (void);
extern void osISRWrap_IRQSTEER_EXT_2_ISR (void);



#endif    /* */
/* end of file */
/****************************************************************
Created Time: 12/6/2023 9:54:58 PM
****************************************************************/
