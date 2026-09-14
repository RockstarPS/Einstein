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
*    @file com.visteon.bsw.generator.os.Os_Invect_ASM@5f7f5d11.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by MNATRAMI at 2026-04-06 16:31:56.351151300
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
    mov    r8, #3
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_McuI2c3IoIsrAddr    /* R11 =  &IsrHandler */
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
    mov    r8, #4
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
    mov    r8, #5
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
    mov    r8, #6
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Gpt_Ch4IsrAddr    /* R11 =  &IsrHandler */
    ldr    r0,osCat2ISREntryASMAddr               /* branch to osCat2ISREntryASM */
    bx     r0


    .global osISRWrap_PmicCdd_nINTGpioInterrupt
    .type osISRWrap_PmicCdd_nINTGpioInterrupt,%function
/*****************************************************************************
*                          osISRWrap_PmicCdd_nINTGpioInterrupt                              
*****************************************************************************/
osISRWrap_PmicCdd_nINTGpioInterrupt :
    sub    lr,lr,#4                               /* adjust return address */
    srsfd  sp!,#osSysMode                         /* push LRirq=PCsys and SPSRirq=CPSRsys to interrupted process stack */
    cps    #osSysMode                             /* switch to System Mode (IRQs remain disabled) */
    /* if a data abort occurs with the instruction above, it was an asynchronous abort caused by the interrupted process */
    stmfd  sp!,{r10}                              /* push the registers r0-r12 and lr to interrupted process stack */
    stmfd  sp!,{r0-r9,r11,r12,lr}                 /* r10 must be pushed first so that we have the same order as in the dispatcher */
    mov    r8, #7
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_PmicCdd_nINTGpioInterruptAddr    /* R11 =  &IsrHandler */
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
    mov    r8, #8
    mov    r9, #0b0010011111                      /* System Mode, IRQs masked */
    ldr    r11,osCallISRHooks_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0Addr    /* R11 =  &IsrHandler */
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
*                 osCallISRHooks_McuI2c3IoIsr Reference                            
*****************************************************************************/
    .global osCallISRHooks_McuI2c3IoIsr
osCallISRHooks_McuI2c3IoIsrAddr: .long osCallISRHooks_McuI2c3IoIsr

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
*                 osCallISRHooks_PmicCdd_nINTGpioInterrupt Reference                            
*****************************************************************************/
    .global osCallISRHooks_PmicCdd_nINTGpioInterrupt
osCallISRHooks_PmicCdd_nINTGpioInterruptAddr: .long osCallISRHooks_PmicCdd_nINTGpioInterrupt

/*****************************************************************************
*                 osCallISRHooks_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0 Reference                            
*****************************************************************************/
    .global osCallISRHooks_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0
osCallISRHooks_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0Addr: .long osCallISRHooks_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0

/*****************************************************************************
*                      osCat2ISREntryASM Reference                            
*****************************************************************************/
    .global osCat2ISREntryASM
osCat2ISREntryASMAddr: .long osCat2ISREntryASM



#endif    /* */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

