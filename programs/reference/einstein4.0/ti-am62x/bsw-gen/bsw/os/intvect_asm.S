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
*    @file com.visteon.bsw.generator.os.Os_Invect_ASM@4bffc362.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by VBARAD at 2026-08-06 12:06:35.049085800
********************************************************************************************************************/

#ifndef INTVECT_ASM_S
#define INTVECT_ASM_S
/*****************************************************************************
* File settings
*****************************************************************************/
    .arm
    .section ".oscode","ax"
    .align 2 

    .set    osSysMode,    0b11111

    .global osISRWrap_McuOsGptIsr
    .type osISRWrap_McuOsGptIsr,%function
/*****************************************************************************
*                          osISRWrap_McuOsGptIsr                              
*****************************************************************************/
osISRWrap_McuOsGptIsr :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #0
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_McuOsGptIsrAddr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_McuCan0RxTxIsr
    .type osISRWrap_McuCan0RxTxIsr,%function
/*****************************************************************************
*                          osISRWrap_McuCan0RxTxIsr                              
*****************************************************************************/
osISRWrap_McuCan0RxTxIsr :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #1
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_McuCan0RxTxIsrAddr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_McuCan1RxTxIsr
    .type osISRWrap_McuCan1RxTxIsr,%function
/*****************************************************************************
*                          osISRWrap_McuCan1RxTxIsr                              
*****************************************************************************/
osISRWrap_McuCan1RxTxIsr :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #2
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_McuCan1RxTxIsrAddr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_McuSpi0NvmRxTxIsr
    .type osISRWrap_McuSpi0NvmRxTxIsr,%function
/*****************************************************************************
*                          osISRWrap_McuSpi0NvmRxTxIsr                              
*****************************************************************************/
osISRWrap_McuSpi0NvmRxTxIsr :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #3
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_McuSpi0NvmRxTxIsrAddr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_McuDss0Isr
    .type osISRWrap_McuDss0Isr,%function
/*****************************************************************************
*                          osISRWrap_McuDss0Isr                              
*****************************************************************************/
osISRWrap_McuDss0Isr :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #4
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_McuDss0IsrAddr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_McuI2c3IoIsr
    .type osISRWrap_McuI2c3IoIsr,%function
/*****************************************************************************
*                          osISRWrap_McuI2c3IoIsr                              
*****************************************************************************/
osISRWrap_McuI2c3IoIsr :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #5
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_McuI2c3IoIsrAddr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_Eth_TxIrqHdlr_0
    .type osISRWrap_Eth_TxIrqHdlr_0,%function
/*****************************************************************************
*                          osISRWrap_Eth_TxIrqHdlr_0                              
*****************************************************************************/
osISRWrap_Eth_TxIrqHdlr_0 :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #6
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Eth_TxIrqHdlr_0Addr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_Eth_RxIrqHdlr_0
    .type osISRWrap_Eth_RxIrqHdlr_0,%function
/*****************************************************************************
*                          osISRWrap_Eth_RxIrqHdlr_0                              
*****************************************************************************/
osISRWrap_Eth_RxIrqHdlr_0 :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #7
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Eth_RxIrqHdlr_0Addr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_Eth_MdioIrqHdlr
    .type osISRWrap_Eth_MdioIrqHdlr,%function
/*****************************************************************************
*                          osISRWrap_Eth_MdioIrqHdlr                              
*****************************************************************************/
osISRWrap_Eth_MdioIrqHdlr :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #8
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Eth_MdioIrqHdlrAddr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_FltM_WkupEsmHiInterrupt
    .type osISRWrap_FltM_WkupEsmHiInterrupt,%function
/*****************************************************************************
*                          osISRWrap_FltM_WkupEsmHiInterrupt                              
*****************************************************************************/
osISRWrap_FltM_WkupEsmHiInterrupt :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #9
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_FltM_WkupEsmHiInterruptAddr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_MCU_IntrISR_UART0
    .type osISRWrap_MCU_IntrISR_UART0,%function
/*****************************************************************************
*                          osISRWrap_MCU_IntrISR_UART0                              
*****************************************************************************/
osISRWrap_MCU_IntrISR_UART0 :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #10
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_MCU_IntrISR_UART0Addr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_McuI2c0PmicIsr
    .type osISRWrap_McuI2c0PmicIsr,%function
/*****************************************************************************
*                          osISRWrap_McuI2c0PmicIsr                              
*****************************************************************************/
osISRWrap_McuI2c0PmicIsr :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #11
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_McuI2c0PmicIsrAddr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_Gpt_Ch3Isr
    .type osISRWrap_Gpt_Ch3Isr,%function
/*****************************************************************************
*                          osISRWrap_Gpt_Ch3Isr                              
*****************************************************************************/
osISRWrap_Gpt_Ch3Isr :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #12
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Gpt_Ch3IsrAddr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_Gpt_Ch4Isr
    .type osISRWrap_Gpt_Ch4Isr,%function
/*****************************************************************************
*                          osISRWrap_Gpt_Ch4Isr                              
*****************************************************************************/
osISRWrap_Gpt_Ch4Isr :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #13
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Gpt_Ch4IsrAddr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_Spi_IrqUnitMcspi2TxRx
    .type osISRWrap_Spi_IrqUnitMcspi2TxRx,%function
/*****************************************************************************
*                          osISRWrap_Spi_IrqUnitMcspi2TxRx                              
*****************************************************************************/
osISRWrap_Spi_IrqUnitMcspi2TxRx :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #14
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Spi_IrqUnitMcspi2TxRxAddr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_MCU_ISR_6
    .type osISRWrap_MCU_ISR_6,%function
/*****************************************************************************
*                          osISRWrap_MCU_ISR_6                              
*****************************************************************************/
osISRWrap_MCU_ISR_6 :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #15
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_MCU_ISR_6Addr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_MAIN_ISR_34
    .type osISRWrap_MAIN_ISR_34,%function
/*****************************************************************************
*                          osISRWrap_MAIN_ISR_34                              
*****************************************************************************/
osISRWrap_MAIN_ISR_34 :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #16
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_MAIN_ISR_34Addr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_MAIN_ISR_35
    .type osISRWrap_MAIN_ISR_35,%function
/*****************************************************************************
*                          osISRWrap_MAIN_ISR_35                              
*****************************************************************************/
osISRWrap_MAIN_ISR_35 :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #17
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_MAIN_ISR_35Addr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_MCU_ISR_7
    .type osISRWrap_MCU_ISR_7,%function
/*****************************************************************************
*                          osISRWrap_MCU_ISR_7                              
*****************************************************************************/
osISRWrap_MCU_ISR_7 :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #18
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_MCU_ISR_7Addr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_FltM_WkupEsmCfgInterrupt
    .type osISRWrap_FltM_WkupEsmCfgInterrupt,%function
/*****************************************************************************
*                          osISRWrap_FltM_WkupEsmCfgInterrupt                              
*****************************************************************************/
osISRWrap_FltM_WkupEsmCfgInterrupt :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #19
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_FltM_WkupEsmCfgInterruptAddr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_FltM_WkupEsmLowInterrupt
    .type osISRWrap_FltM_WkupEsmLowInterrupt,%function
/*****************************************************************************
*                          osISRWrap_FltM_WkupEsmLowInterrupt                              
*****************************************************************************/
osISRWrap_FltM_WkupEsmLowInterrupt :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #20
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_FltM_WkupEsmLowInterruptAddr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_Spi_IrqUnitMcspi0TxRx
    .type osISRWrap_Spi_IrqUnitMcspi0TxRx,%function
/*****************************************************************************
*                          osISRWrap_Spi_IrqUnitMcspi0TxRx                              
*****************************************************************************/
osISRWrap_Spi_IrqUnitMcspi0TxRx :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #21
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Spi_IrqUnitMcspi0TxRxAddr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_MainI2c2RtcIsr
    .type osISRWrap_MainI2c2RtcIsr,%function
/*****************************************************************************
*                          osISRWrap_MainI2c2RtcIsr                              
*****************************************************************************/
osISRWrap_MainI2c2RtcIsr :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #22
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_MainI2c2RtcIsrAddr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_MCU_ResetIsolationReq
    .type osISRWrap_MCU_ResetIsolationReq,%function
/*****************************************************************************
*                          osISRWrap_MCU_ResetIsolationReq                              
*****************************************************************************/
osISRWrap_MCU_ResetIsolationReq :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #23
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_MCU_ResetIsolationReqAddr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_FltM_FwlExceptionInterrupt
    .type osISRWrap_FltM_FwlExceptionInterrupt,%function
/*****************************************************************************
*                          osISRWrap_FltM_FwlExceptionInterrupt                              
*****************************************************************************/
osISRWrap_FltM_FwlExceptionInterrupt :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #24
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_FltM_FwlExceptionInterruptAddr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0
    .type osISRWrap_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0,%function
/*****************************************************************************
*                          osISRWrap_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0                              
*****************************************************************************/
osISRWrap_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0 :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #25
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0Addr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_Mcu_Udma_Vintr64
    .type osISRWrap_Mcu_Udma_Vintr64,%function
/*****************************************************************************
*                          osISRWrap_Mcu_Udma_Vintr64                              
*****************************************************************************/
osISRWrap_Mcu_Udma_Vintr64 :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #26
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Mcu_Udma_Vintr64Addr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_Mcu_Udma_Vintr65
    .type osISRWrap_Mcu_Udma_Vintr65,%function
/*****************************************************************************
*                          osISRWrap_Mcu_Udma_Vintr65                              
*****************************************************************************/
osISRWrap_Mcu_Udma_Vintr65 :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #27
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Mcu_Udma_Vintr65Addr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_Mcu_Udma_Vintr66
    .type osISRWrap_Mcu_Udma_Vintr66,%function
/*****************************************************************************
*                          osISRWrap_Mcu_Udma_Vintr66                              
*****************************************************************************/
osISRWrap_Mcu_Udma_Vintr66 :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #28
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Mcu_Udma_Vintr66Addr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_Mcu_Udma_Vintr67
    .type osISRWrap_Mcu_Udma_Vintr67,%function
/*****************************************************************************
*                          osISRWrap_Mcu_Udma_Vintr67                              
*****************************************************************************/
osISRWrap_Mcu_Udma_Vintr67 :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #29
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Mcu_Udma_Vintr67Addr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_Mcu_Udma_Vintr68
    .type osISRWrap_Mcu_Udma_Vintr68,%function
/*****************************************************************************
*                          osISRWrap_Mcu_Udma_Vintr68                              
*****************************************************************************/
osISRWrap_Mcu_Udma_Vintr68 :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #30
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Mcu_Udma_Vintr68Addr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_Mcu_Udma_Vintr69
    .type osISRWrap_Mcu_Udma_Vintr69,%function
/*****************************************************************************
*                          osISRWrap_Mcu_Udma_Vintr69                              
*****************************************************************************/
osISRWrap_Mcu_Udma_Vintr69 :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #31
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Mcu_Udma_Vintr69Addr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_Mcu_Udma_Vintr70
    .type osISRWrap_Mcu_Udma_Vintr70,%function
/*****************************************************************************
*                          osISRWrap_Mcu_Udma_Vintr70                              
*****************************************************************************/
osISRWrap_Mcu_Udma_Vintr70 :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #32
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Mcu_Udma_Vintr70Addr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_Mcu_Udma_Vintr71
    .type osISRWrap_Mcu_Udma_Vintr71,%function
/*****************************************************************************
*                          osISRWrap_Mcu_Udma_Vintr71                              
*****************************************************************************/
osISRWrap_Mcu_Udma_Vintr71 :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #33
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Mcu_Udma_Vintr71Addr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_Mcu_Udma_Vintr72
    .type osISRWrap_Mcu_Udma_Vintr72,%function
/*****************************************************************************
*                          osISRWrap_Mcu_Udma_Vintr72                              
*****************************************************************************/
osISRWrap_Mcu_Udma_Vintr72 :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #34
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Mcu_Udma_Vintr72Addr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_Mcu_Udma_Vintr73
    .type osISRWrap_Mcu_Udma_Vintr73,%function
/*****************************************************************************
*                          osISRWrap_Mcu_Udma_Vintr73                              
*****************************************************************************/
osISRWrap_Mcu_Udma_Vintr73 :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #35
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Mcu_Udma_Vintr73Addr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_Mcu_Udma_Vintr74
    .type osISRWrap_Mcu_Udma_Vintr74,%function
/*****************************************************************************
*                          osISRWrap_Mcu_Udma_Vintr74                              
*****************************************************************************/
osISRWrap_Mcu_Udma_Vintr74 :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #36
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Mcu_Udma_Vintr74Addr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_Mcu_Udma_Vintr75
    .type osISRWrap_Mcu_Udma_Vintr75,%function
/*****************************************************************************
*                          osISRWrap_Mcu_Udma_Vintr75                              
*****************************************************************************/
osISRWrap_Mcu_Udma_Vintr75 :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #37
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Mcu_Udma_Vintr75Addr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_Mcu_Udma_Vintr76
    .type osISRWrap_Mcu_Udma_Vintr76,%function
/*****************************************************************************
*                          osISRWrap_Mcu_Udma_Vintr76                              
*****************************************************************************/
osISRWrap_Mcu_Udma_Vintr76 :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #38
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Mcu_Udma_Vintr76Addr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_Mcu_Udma_Vintr77
    .type osISRWrap_Mcu_Udma_Vintr77,%function
/*****************************************************************************
*                          osISRWrap_Mcu_Udma_Vintr77                              
*****************************************************************************/
osISRWrap_Mcu_Udma_Vintr77 :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #39
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Mcu_Udma_Vintr77Addr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_Mcu_Udma_Vintr78
    .type osISRWrap_Mcu_Udma_Vintr78,%function
/*****************************************************************************
*                          osISRWrap_Mcu_Udma_Vintr78                              
*****************************************************************************/
osISRWrap_Mcu_Udma_Vintr78 :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #40
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Mcu_Udma_Vintr78Addr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_Mcu_Udma_Vintr79
    .type osISRWrap_Mcu_Udma_Vintr79,%function
/*****************************************************************************
*                          osISRWrap_Mcu_Udma_Vintr79                              
*****************************************************************************/
osISRWrap_Mcu_Udma_Vintr79 :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #41
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Mcu_Udma_Vintr79Addr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_MainI2c1DacIsr
    .type osISRWrap_MainI2c1DacIsr,%function
/*****************************************************************************
*                          osISRWrap_MainI2c1DacIsr                              
*****************************************************************************/
osISRWrap_MainI2c1DacIsr :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #42
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_MainI2c1DacIsrAddr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0



/*****************************************************************************
*                 osCallISRHooks_McuOsGptIsr Reference                            
*****************************************************************************/
    .global osCallISRHooks_McuOsGptIsr
osCallISRHooks_McuOsGptIsrAddr: .long osCallISRHooks_McuOsGptIsr

/*****************************************************************************
*                 osCallISRHooks_McuCan0RxTxIsr Reference                            
*****************************************************************************/
    .global osCallISRHooks_McuCan0RxTxIsr
osCallISRHooks_McuCan0RxTxIsrAddr: .long osCallISRHooks_McuCan0RxTxIsr

/*****************************************************************************
*                 osCallISRHooks_McuCan1RxTxIsr Reference                            
*****************************************************************************/
    .global osCallISRHooks_McuCan1RxTxIsr
osCallISRHooks_McuCan1RxTxIsrAddr: .long osCallISRHooks_McuCan1RxTxIsr

/*****************************************************************************
*                 osCallISRHooks_McuSpi0NvmRxTxIsr Reference                            
*****************************************************************************/
    .global osCallISRHooks_McuSpi0NvmRxTxIsr
osCallISRHooks_McuSpi0NvmRxTxIsrAddr: .long osCallISRHooks_McuSpi0NvmRxTxIsr

/*****************************************************************************
*                 osCallISRHooks_McuDss0Isr Reference                            
*****************************************************************************/
    .global osCallISRHooks_McuDss0Isr
osCallISRHooks_McuDss0IsrAddr: .long osCallISRHooks_McuDss0Isr

/*****************************************************************************
*                 osCallISRHooks_McuI2c3IoIsr Reference                            
*****************************************************************************/
    .global osCallISRHooks_McuI2c3IoIsr
osCallISRHooks_McuI2c3IoIsrAddr: .long osCallISRHooks_McuI2c3IoIsr

/*****************************************************************************
*                 osCallISRHooks_Eth_TxIrqHdlr_0 Reference                            
*****************************************************************************/
    .global osCallISRHooks_Eth_TxIrqHdlr_0
osCallISRHooks_Eth_TxIrqHdlr_0Addr: .long osCallISRHooks_Eth_TxIrqHdlr_0

/*****************************************************************************
*                 osCallISRHooks_Eth_RxIrqHdlr_0 Reference                            
*****************************************************************************/
    .global osCallISRHooks_Eth_RxIrqHdlr_0
osCallISRHooks_Eth_RxIrqHdlr_0Addr: .long osCallISRHooks_Eth_RxIrqHdlr_0

/*****************************************************************************
*                 osCallISRHooks_Eth_MdioIrqHdlr Reference                            
*****************************************************************************/
    .global osCallISRHooks_Eth_MdioIrqHdlr
osCallISRHooks_Eth_MdioIrqHdlrAddr: .long osCallISRHooks_Eth_MdioIrqHdlr

/*****************************************************************************
*                 osCallISRHooks_FltM_WkupEsmHiInterrupt Reference                            
*****************************************************************************/
    .global osCallISRHooks_FltM_WkupEsmHiInterrupt
osCallISRHooks_FltM_WkupEsmHiInterruptAddr: .long osCallISRHooks_FltM_WkupEsmHiInterrupt

/*****************************************************************************
*                 osCallISRHooks_MCU_IntrISR_UART0 Reference                            
*****************************************************************************/
    .global osCallISRHooks_MCU_IntrISR_UART0
osCallISRHooks_MCU_IntrISR_UART0Addr: .long osCallISRHooks_MCU_IntrISR_UART0

/*****************************************************************************
*                 osCallISRHooks_McuI2c0PmicIsr Reference                            
*****************************************************************************/
    .global osCallISRHooks_McuI2c0PmicIsr
osCallISRHooks_McuI2c0PmicIsrAddr: .long osCallISRHooks_McuI2c0PmicIsr

/*****************************************************************************
*                 osCallISRHooks_Gpt_Ch3Isr Reference                            
*****************************************************************************/
    .global osCallISRHooks_Gpt_Ch3Isr
osCallISRHooks_Gpt_Ch3IsrAddr: .long osCallISRHooks_Gpt_Ch3Isr

/*****************************************************************************
*                 osCallISRHooks_Gpt_Ch4Isr Reference                            
*****************************************************************************/
    .global osCallISRHooks_Gpt_Ch4Isr
osCallISRHooks_Gpt_Ch4IsrAddr: .long osCallISRHooks_Gpt_Ch4Isr

/*****************************************************************************
*                 osCallISRHooks_Spi_IrqUnitMcspi2TxRx Reference                            
*****************************************************************************/
    .global osCallISRHooks_Spi_IrqUnitMcspi2TxRx
osCallISRHooks_Spi_IrqUnitMcspi2TxRxAddr: .long osCallISRHooks_Spi_IrqUnitMcspi2TxRx

/*****************************************************************************
*                 osCallISRHooks_MCU_ISR_6 Reference                            
*****************************************************************************/
    .global osCallISRHooks_MCU_ISR_6
osCallISRHooks_MCU_ISR_6Addr: .long osCallISRHooks_MCU_ISR_6

/*****************************************************************************
*                 osCallISRHooks_MAIN_ISR_34 Reference                            
*****************************************************************************/
    .global osCallISRHooks_MAIN_ISR_34
osCallISRHooks_MAIN_ISR_34Addr: .long osCallISRHooks_MAIN_ISR_34

/*****************************************************************************
*                 osCallISRHooks_MAIN_ISR_35 Reference                            
*****************************************************************************/
    .global osCallISRHooks_MAIN_ISR_35
osCallISRHooks_MAIN_ISR_35Addr: .long osCallISRHooks_MAIN_ISR_35

/*****************************************************************************
*                 osCallISRHooks_MCU_ISR_7 Reference                            
*****************************************************************************/
    .global osCallISRHooks_MCU_ISR_7
osCallISRHooks_MCU_ISR_7Addr: .long osCallISRHooks_MCU_ISR_7

/*****************************************************************************
*                 osCallISRHooks_FltM_WkupEsmCfgInterrupt Reference                            
*****************************************************************************/
    .global osCallISRHooks_FltM_WkupEsmCfgInterrupt
osCallISRHooks_FltM_WkupEsmCfgInterruptAddr: .long osCallISRHooks_FltM_WkupEsmCfgInterrupt

/*****************************************************************************
*                 osCallISRHooks_FltM_WkupEsmLowInterrupt Reference                            
*****************************************************************************/
    .global osCallISRHooks_FltM_WkupEsmLowInterrupt
osCallISRHooks_FltM_WkupEsmLowInterruptAddr: .long osCallISRHooks_FltM_WkupEsmLowInterrupt

/*****************************************************************************
*                 osCallISRHooks_Spi_IrqUnitMcspi0TxRx Reference                            
*****************************************************************************/
    .global osCallISRHooks_Spi_IrqUnitMcspi0TxRx
osCallISRHooks_Spi_IrqUnitMcspi0TxRxAddr: .long osCallISRHooks_Spi_IrqUnitMcspi0TxRx

/*****************************************************************************
*                 osCallISRHooks_MainI2c2RtcIsr Reference                            
*****************************************************************************/
    .global osCallISRHooks_MainI2c2RtcIsr
osCallISRHooks_MainI2c2RtcIsrAddr: .long osCallISRHooks_MainI2c2RtcIsr

/*****************************************************************************
*                 osCallISRHooks_MCU_ResetIsolationReq Reference                            
*****************************************************************************/
    .global osCallISRHooks_MCU_ResetIsolationReq
osCallISRHooks_MCU_ResetIsolationReqAddr: .long osCallISRHooks_MCU_ResetIsolationReq

/*****************************************************************************
*                 osCallISRHooks_FltM_FwlExceptionInterrupt Reference                            
*****************************************************************************/
    .global osCallISRHooks_FltM_FwlExceptionInterrupt
osCallISRHooks_FltM_FwlExceptionInterruptAddr: .long osCallISRHooks_FltM_FwlExceptionInterrupt

/*****************************************************************************
*                 osCallISRHooks_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0 Reference                            
*****************************************************************************/
    .global osCallISRHooks_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0
osCallISRHooks_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0Addr: .long osCallISRHooks_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0

/*****************************************************************************
*                 osCallISRHooks_Mcu_Udma_Vintr64 Reference                            
*****************************************************************************/
    .global osCallISRHooks_Mcu_Udma_Vintr64
osCallISRHooks_Mcu_Udma_Vintr64Addr: .long osCallISRHooks_Mcu_Udma_Vintr64

/*****************************************************************************
*                 osCallISRHooks_Mcu_Udma_Vintr65 Reference                            
*****************************************************************************/
    .global osCallISRHooks_Mcu_Udma_Vintr65
osCallISRHooks_Mcu_Udma_Vintr65Addr: .long osCallISRHooks_Mcu_Udma_Vintr65

/*****************************************************************************
*                 osCallISRHooks_Mcu_Udma_Vintr66 Reference                            
*****************************************************************************/
    .global osCallISRHooks_Mcu_Udma_Vintr66
osCallISRHooks_Mcu_Udma_Vintr66Addr: .long osCallISRHooks_Mcu_Udma_Vintr66

/*****************************************************************************
*                 osCallISRHooks_Mcu_Udma_Vintr67 Reference                            
*****************************************************************************/
    .global osCallISRHooks_Mcu_Udma_Vintr67
osCallISRHooks_Mcu_Udma_Vintr67Addr: .long osCallISRHooks_Mcu_Udma_Vintr67

/*****************************************************************************
*                 osCallISRHooks_Mcu_Udma_Vintr68 Reference                            
*****************************************************************************/
    .global osCallISRHooks_Mcu_Udma_Vintr68
osCallISRHooks_Mcu_Udma_Vintr68Addr: .long osCallISRHooks_Mcu_Udma_Vintr68

/*****************************************************************************
*                 osCallISRHooks_Mcu_Udma_Vintr69 Reference                            
*****************************************************************************/
    .global osCallISRHooks_Mcu_Udma_Vintr69
osCallISRHooks_Mcu_Udma_Vintr69Addr: .long osCallISRHooks_Mcu_Udma_Vintr69

/*****************************************************************************
*                 osCallISRHooks_Mcu_Udma_Vintr70 Reference                            
*****************************************************************************/
    .global osCallISRHooks_Mcu_Udma_Vintr70
osCallISRHooks_Mcu_Udma_Vintr70Addr: .long osCallISRHooks_Mcu_Udma_Vintr70

/*****************************************************************************
*                 osCallISRHooks_Mcu_Udma_Vintr71 Reference                            
*****************************************************************************/
    .global osCallISRHooks_Mcu_Udma_Vintr71
osCallISRHooks_Mcu_Udma_Vintr71Addr: .long osCallISRHooks_Mcu_Udma_Vintr71

/*****************************************************************************
*                 osCallISRHooks_Mcu_Udma_Vintr72 Reference                            
*****************************************************************************/
    .global osCallISRHooks_Mcu_Udma_Vintr72
osCallISRHooks_Mcu_Udma_Vintr72Addr: .long osCallISRHooks_Mcu_Udma_Vintr72

/*****************************************************************************
*                 osCallISRHooks_Mcu_Udma_Vintr73 Reference                            
*****************************************************************************/
    .global osCallISRHooks_Mcu_Udma_Vintr73
osCallISRHooks_Mcu_Udma_Vintr73Addr: .long osCallISRHooks_Mcu_Udma_Vintr73

/*****************************************************************************
*                 osCallISRHooks_Mcu_Udma_Vintr74 Reference                            
*****************************************************************************/
    .global osCallISRHooks_Mcu_Udma_Vintr74
osCallISRHooks_Mcu_Udma_Vintr74Addr: .long osCallISRHooks_Mcu_Udma_Vintr74

/*****************************************************************************
*                 osCallISRHooks_Mcu_Udma_Vintr75 Reference                            
*****************************************************************************/
    .global osCallISRHooks_Mcu_Udma_Vintr75
osCallISRHooks_Mcu_Udma_Vintr75Addr: .long osCallISRHooks_Mcu_Udma_Vintr75

/*****************************************************************************
*                 osCallISRHooks_Mcu_Udma_Vintr76 Reference                            
*****************************************************************************/
    .global osCallISRHooks_Mcu_Udma_Vintr76
osCallISRHooks_Mcu_Udma_Vintr76Addr: .long osCallISRHooks_Mcu_Udma_Vintr76

/*****************************************************************************
*                 osCallISRHooks_Mcu_Udma_Vintr77 Reference                            
*****************************************************************************/
    .global osCallISRHooks_Mcu_Udma_Vintr77
osCallISRHooks_Mcu_Udma_Vintr77Addr: .long osCallISRHooks_Mcu_Udma_Vintr77

/*****************************************************************************
*                 osCallISRHooks_Mcu_Udma_Vintr78 Reference                            
*****************************************************************************/
    .global osCallISRHooks_Mcu_Udma_Vintr78
osCallISRHooks_Mcu_Udma_Vintr78Addr: .long osCallISRHooks_Mcu_Udma_Vintr78

/*****************************************************************************
*                 osCallISRHooks_Mcu_Udma_Vintr79 Reference                            
*****************************************************************************/
    .global osCallISRHooks_Mcu_Udma_Vintr79
osCallISRHooks_Mcu_Udma_Vintr79Addr: .long osCallISRHooks_Mcu_Udma_Vintr79

/*****************************************************************************
*                 osCallISRHooks_MainI2c1DacIsr Reference                            
*****************************************************************************/
    .global osCallISRHooks_MainI2c1DacIsr
osCallISRHooks_MainI2c1DacIsrAddr: .long osCallISRHooks_MainI2c1DacIsr

/*****************************************************************************
*                      osCat2ISREntryASM Reference                            
*****************************************************************************/
    .global osCat2ISREntryASM
osCat2ISREntryASMAddr: .long osCat2ISREntryASM



#endif    /* */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

