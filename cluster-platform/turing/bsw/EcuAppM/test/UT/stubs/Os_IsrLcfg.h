/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2025 by Visteon Corporation.       All rights reserved.         
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
*    Auto generated code in vAUTOSAR TOOL by TGUNASEK at 2025-08-04 15:28:12.930381900
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


extern const OsIsrConfigType OsIsrConfig_SystemTimerISR;
extern const OsIsrConfigType OsIsrConfig_CAN0_ISR;
extern const OsIsrConfigType OsIsrConfig_GPT_ISR;
extern const OsIsrConfigType OsIsrConfig_BACKUP;
extern const OsIsrConfigType OsIsrConfig_PDMA48;
extern const OsIsrConfigType OsIsrConfig_PDMA49;
extern const OsIsrConfigType OsIsrConfig_PDMA50;
extern const OsIsrConfigType OsIsrConfig_PDMA51;
extern const OsIsrConfigType OsIsrConfig_PDMA52;
extern const OsIsrConfigType OsIsrConfig_cpuss_interrupts_ipc_6_IRQn;
extern const OsIsrConfigType OsIsrConfig_ISR_GFX2D;
extern const OsIsrConfigType OsIsrConfig_ISR_VIDEOIO_0;
extern const OsIsrConfigType OsIsrConfig_ISR_VIDEOIO_1;
extern const OsIsrConfigType OsIsrConfig_ISR_PDMA22;
extern const OsIsrConfigType OsIsrConfig_ISR_MDMA1;
extern const OsIsrConfigType OsIsrConfig_ISR_MDMA2;
extern const OsIsrConfigType OsIsrConfig_CAN1_ISR;
extern const OsIsrConfigType OsIsrConfig_SCB2;
extern const OsIsrConfigType OsIsrConfig_IGN_ISR;
extern const OsIsrConfigType OsIsrConfig_CAN_WAKEUP_ISR;
extern const OsIsrConfigType OsIsrConfig_ECC_ERROR_ISR;
extern const OsIsrConfigType OsIsrConfig_MCU_LVD_ISR;
extern const OsIsrConfigType OsIsrConfig_CSV_ERROR_ISR;
extern const OsIsrConfigType OsIsrConfig_SSV_ERROR_ISR;
extern const OsIsrConfigRefType OsIsrRefConfig[OsNumberOfIsr];
extern const osStackPtrType IsrStackConfig[osdNumberOfCat2ISRs];
extern const osStackDataType IsrStackSize[osdNumberOfCat2ISRs];


extern void osTimerInterruptfunc(void);
extern void Can_Interrupt_CANFD00_Cat2func(void);
extern void GPT_Isr_Vector_680_Cat2func(void);
extern void RtcDrvCdd_AlarmInterruptHandlerfunc(void);
extern void PDMA_Isr_Vector_472_Cat2func(void);
extern void PDMA_Isr_Vector_473_Cat2func(void);
extern void PDMA_Isr_Vector_474_Cat2func(void);
extern void PDMA_Isr_Vector_475_Cat2func(void);
extern void PDMA_Isr_Vector_476_Cat2func(void);
extern void CySldIpc_Isr_IpcDrv_Cat2(void);
extern void CyGfx_kInterruptHandlerGfx2d(void);
extern void CyGfx_kInterruptHandlerVideoio0(void);
extern void CyGfx_kInterruptHandlerVideoio1(void);
extern void PDMA_Isr_Vector_318_Cat2func(void);
extern void MDMA_Isr_Vector_289_Cat2func(void);
extern void MDMA_Isr_Vector_290_Cat2func(void);
extern void Can_Interrupt_CANFD10_Cat2func(void);
extern void Spi_Interrupt_SCB2_Cat2func(void);
extern void Icu_Isr_Vector_26_Cat2func(void);
extern void Icu_Isr_Vector_25_Cat2func(void);
extern void SysFaultDrv_Report1Handler(void);
extern void Mcu_Lvd_Isr_Cat2func(void);
extern void SysFaultDrv_Report2Handler(void);
extern void SysFaultDrv_Report3Handler(void);


#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

