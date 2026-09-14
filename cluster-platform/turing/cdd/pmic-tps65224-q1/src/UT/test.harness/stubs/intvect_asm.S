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

File Name        :  intvect_asm.S
Module Short Name:  intvect_asm.S
VOBName          :  
Author           :  
Description      :
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

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
    ldr    r11,osCallISRHooks_McuOsGptIsrAddr        /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr              /* branch to osCat2ISREntryASM */
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
    ldr    r11,osCallISRHooks_McuCan0RxTxIsrAddr        /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr              /* branch to osCat2ISREntryASM */
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
    ldr    r11,osCallISRHooks_McuCan1RxTxIsrAddr        /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr              /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_McuCddIpcMbxFromA53SS_0_0Isr
    .type osISRWrap_McuCddIpcMbxFromA53SS_0_0Isr,%function
/*****************************************************************************
*                          osISRWrap_McuCddIpcMbxFromA53SS_0_0Isr                              
*****************************************************************************/
osISRWrap_McuCddIpcMbxFromA53SS_0_0Isr :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #3
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_McuCddIpcMbxFromA53SS_0_0IsrAddr        /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr              /* branch to osCat2ISREntryASM */
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
    mov    r8, #4
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_McuSpi0NvmRxTxIsrAddr        /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr              /* branch to osCat2ISREntryASM */
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
    mov    r8, #5
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_McuDss0IsrAddr        /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr              /* branch to osCat2ISREntryASM */
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
    mov    r8, #6
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_McuI2c3IoIsrAddr        /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr              /* branch to osCat2ISREntryASM */
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
    mov    r8, #7
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Eth_TxIrqHdlr_0Addr        /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr              /* branch to osCat2ISREntryASM */
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
    mov    r8, #8
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Eth_RxIrqHdlr_0Addr        /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr              /* branch to osCat2ISREntryASM */
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
    mov    r8, #9
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Eth_MdioIrqHdlrAddr        /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr              /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_McuEsmIsr
    .type osISRWrap_McuEsmIsr,%function
/*****************************************************************************
*                          osISRWrap_McuEsmIsr                              
*****************************************************************************/
osISRWrap_McuEsmIsr :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #10
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_McuEsmIsrAddr        /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr              /* branch to osCat2ISREntryASM */
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
    mov    r8, #11
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_MCU_IntrISR_UART0Addr        /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr              /* branch to osCat2ISREntryASM */
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
    mov    r8, #12
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_McuI2c0PmicIsrAddr        /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr              /* branch to osCat2ISREntryASM */
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
    mov    r8, #13
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Gpt_Ch3IsrAddr        /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr              /* branch to osCat2ISREntryASM */
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
    mov    r8, #14
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Gpt_Ch4IsrAddr        /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr              /* branch to osCat2ISREntryASM */
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
    mov    r8, #15
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Spi_IrqUnitMcspi2TxRxAddr        /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr              /* branch to osCat2ISREntryASM */
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
    mov    r8, #16
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_MCU_ISR_6Addr        /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr              /* branch to osCat2ISREntryASM */
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
    mov    r8, #17
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_MAIN_ISR_34Addr        /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr              /* branch to osCat2ISREntryASM */
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
    mov    r8, #18
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_MAIN_ISR_35Addr        /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr              /* branch to osCat2ISREntryASM */
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
    mov    r8, #19
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_MCU_ISR_7Addr        /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr              /* branch to osCat2ISREntryASM */
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
*                 osCallISRHooks_McuCddIpcMbxFromA53SS_0_0Isr Reference                            
*****************************************************************************/
    .global osCallISRHooks_McuCddIpcMbxFromA53SS_0_0Isr
osCallISRHooks_McuCddIpcMbxFromA53SS_0_0IsrAddr: .long osCallISRHooks_McuCddIpcMbxFromA53SS_0_0Isr
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
*                 osCallISRHooks_McuEsmIsr Reference                            
*****************************************************************************/
    .global osCallISRHooks_McuEsmIsr
osCallISRHooks_McuEsmIsrAddr: .long osCallISRHooks_McuEsmIsr
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
*                      osCat2ISREntryASM Reference                            
*****************************************************************************/
    .global osCat2ISREntryASM
osCat2ISREntryASMAddr: .long osCat2ISREntryASM

#endif    /* */
/* end of file */
/****************************************************************
Created Time: 11-02-2025 19:34:25
****************************************************************/
