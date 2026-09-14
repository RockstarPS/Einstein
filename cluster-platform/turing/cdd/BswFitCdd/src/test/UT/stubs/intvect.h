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

#define osdNumberOfIRQs                     32
#define osdNumberOfSysUserCpuIRQs           795
#define osdNumberOfConfiguredIRQs           22U
#define osdNumberOfFIQs                     32
#define osdNumberOfConfiguredFIQs           0
#define osdNumberOfCat2ISRs                 22U
#define osdNumberOfExceptions               8

typedef void (*osVoidFunctionType)(void);
                                                                              
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
                                                                              


#define osIntvUserCpuIrq0           0U
#define osIntvUserCpuIrq1           1U
#define osIntvUserCpuIrq2           2U
#define osIntvUserCpuIrq3           3U
#define osIntvUserCpuIrq4           4U
#define osIntvUserCpuIrq5           5U
#define osIntvUserCpuIrq6           6U
#define osIntvUserCpuIrq7           7U
#define osIntvUserCpuIrqInvalid 0xFFFFU



typedef struct {
    osuint32          IrqId;
    osuint32          SysMapIrqId;
    osIntLevelType    PrioLevel;
}OsIrqConfigInfoType;



extern const OsIrqConfigInfoType OsIrqConfigInfoList[osdNumberOfConfiguredIRQs+1];






#define osGenNumOfCat1IRQs         0U
#define osGenNumOfCat2IRQs         22U

/* ISR function prototypes */

void osTimerInterruptfunc(void);
void Can_Interrupt_CANFD00_Cat2func(void);
void GPT_Isr_Vector_680_Cat2func(void);
void RtcDrvCdd_AlarmInterruptHandlerfunc(void);
void PDMA_Isr_Vector_472_Cat2func(void);
void PDMA_Isr_Vector_473_Cat2func(void);
void PDMA_Isr_Vector_474_Cat2func(void);
void PDMA_Isr_Vector_475_Cat2func(void);
void PDMA_Isr_Vector_476_Cat2func(void);
void CySldIpc_Isr_IpcDrv_Cat2(void);
void CyGfx_kInterruptHandlerGfx2d(void);
void CyGfx_kInterruptHandlerVideoio0(void);
void CyGfx_kInterruptHandlerVideoio1(void);
void PDMA_Isr_Vector_318_Cat2func(void);
void MDMA_Isr_Vector_289_Cat2func(void);
void MDMA_Isr_Vector_290_Cat2func(void);
void Can_Interrupt_CANFD10_Cat2func(void);
void Spi_Interrupt_SCB2_Cat2func(void);
void Icu_Isr_Vector_26_Cat2func(void);
void Icu_Isr_Vector_25_Cat2func(void);
void SysFaultDrv_ReportHandler(void);
void Mcu_Lvd_Isr_Cat2func(void);


/* ISR Hook function prototypes */

GHS_CAT2_INTERRUPT void osCallISRHooks_SystemTimerISR(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_CAN0_ISR(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_GPT_ISR(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_BACKUP(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_PDMA48(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_PDMA49(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_PDMA50(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_PDMA51(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_PDMA52(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_cpuss_interrupts_ipc_6_IRQn(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_ISR_GFX2D(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_ISR_VIDEOIO_0(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_ISR_VIDEOIO_1(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_ISR_PDMA22(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_ISR_MDMA1(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_ISR_MDMA2(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_CAN1_ISR(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_SCB2(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_IGN_ISR(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_CAN_WAKEUP_ISR(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_ECC_ERROR_ISR(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_MCU_LVD_ISR(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_CpuUserInt0_Handler(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_CpuUserInt1_Handler(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_CpuUserInt2_Handler(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_CpuUserInt3_Handler(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_CpuUserInt4_Handler(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_CpuUserInt5_Handler(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_CpuUserInt6_Handler(void);
GHS_CAT2_INTERRUPT void osCallISRHooks_CpuUserInt7_Handler(void);


extern void osSetupConfiguredInterrupts (void);
extern OsIrqConfigInfoType * OsIntVect_GetIsrConfig(ISRType IsrId);


extern void osISRWrap_SystemTimerISR(void);
extern void osISRWrap_CpuUserInt0_Handler (void);
extern void osISRWrap_CpuUserInt1_Handler (void);
extern void osISRWrap_CpuUserInt2_Handler (void);
extern void osISRWrap_CpuUserInt3_Handler (void);
extern void osISRWrap_CpuUserInt4_Handler (void);
extern void osISRWrap_CpuUserInt5_Handler (void);
extern void osISRWrap_CpuUserInt6_Handler (void);
extern void osISRWrap_CpuUserInt7_Handler (void);



#endif    /* */
/* end of file */
/****************************************************************
Created Time: 8/23/2024 4:07:48 PM
****************************************************************/
