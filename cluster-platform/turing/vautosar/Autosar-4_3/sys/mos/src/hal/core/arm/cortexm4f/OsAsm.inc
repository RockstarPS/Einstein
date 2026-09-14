;/*****************************************************************************
;
;                CONFIDENTIAL VISTEON CORPORATION                        
;                                                                        
;   This is an unpublished work of authorship, which contains trade      
;   secrets, created in 2013. Visteon Corporation owns all rights to     
;   this work and intends to maintain it in confidence to preserve       
;   its trade secret status. Visteon Corporation reserves the right,     
;   under the copyright laws of the United States or those of any        
;   other country that may have jurisdiction, to protect this work       
;   as an unpublished work, in the event of an inadvertent or            
;   deliberate unauthorized publication. Visteon Corporation also        
;   reserves its rights under all copyright laws to protect this         
;   work as a published work, when appropriate. Those having access      
;   to this work may not copy it, use it, modify it or disclose the      
;   information contained in it without the written authorization        
;   of Visteon Corporation.                                              
;
;
;
;
;
;   Project Name: mOS
;   File Name: OsAsm.inc;
;
;
;   Description: Assembler functions for mOS ARM Cortex M4 (GHS compiler)
;
;
;****************************************************************************/

;-+--------------------------------------------------------------------------
; Some Definitions                                                             
;----------------------------------------------------------------------------
osUserMode                     .equ    0b10000
osFIQMode                      .equ    0b10001
osIRQMode                      .equ    0b10010
osSVCMode                      .equ    0b10011
osAbortMode                    .equ    0b10111
osUndefMode                    .equ    0b11011
osSysMode                      .equ    0b11111
osModeMask                     .equ    0b11111

osdIntCfgMaxSystemPriority     .equ     0x20
osdIntCfgKernelPriority        .equ     0x80

osdNumberOfServices            .equ    66

osIFlag                        .equ    0b10000000

osdTaskStartCPSR_Usr           .equ    0b0000010000
osdTaskStartCPSR_Sys           .equ    0b0000011111

osdNoActiveTask                .equ    0xffffffff
osdInvalidIsrID                .equ    0xffffffff
osdORTINoService               .equ    0

PRE_READY                      .equ    0
RUNNING                        .equ    1
READY                          .equ    3

STANDARD_STATUS                .equ    0
EXTENDED_STATUS                .equ    1

osdPICMode                     .equ    0

osdCtxTask                     .equ    0x0001
osdCtxISRCat2                  .equ    0x0002
osdCtxPreTaskHook              .equ    0x0004
osdCtxPostTaskHook             .equ    0x0008
osdCtxErrorHook                .equ    0x0010
osdCtxApplErrorHook            .equ    0x0020
osdCtxEachErrorHook            .equ    0x0030
osdCtxStartupHook              .equ    0x0040
osdCtxShutdownHook             .equ    0x0080
osdCtxProtectionHook           .equ    0x0100
osdCtxCOMErrorHook             .equ    0x0200
osdCtxCOMCallback              .equ    0x0400
osdCtxStartComExtens           .equ    0x0800
osdCtxErrorHookFromStartupHook .equ    0x1000

osdStackWindowAccessRights     .equ    0x0000130b

osIRQ_BASE                     .equ 0xb040
osIRQ0_IRQHC                   .equ 0x0c48
osIRQ0_CSR                     .equ 0x0c98
osIRQ0_UNLOCK                  .equ 0x0d30
osIRQ0_IRQR0                   .equ 0x0b00

osdIRQ_UnlockValueTop          .equ 0x17AC
osdIRQ_UnlockValueBot          .equ 0xC911
osdIRQ_LockValueTop            .equ 0x17B1
osdIRQ_LockValueBot            .equ 0x0C11
osdIRQ_CSR_EnableBit           .equ 1

E_OS_DISABLEDINT               .equ 12
E_OS_STACKFAULT                .equ 13
E_OS_SYS_ASSERTION             .equ 20
E_OS_SYS_ABORT                 .equ 21
osdErrSYReturnFromNoISR        .equ 0xA402
osdErrIXIntAPIDisabled         .equ 0x2302
osdErrDPStartValidContext      .equ 0xA501
osdErrDPResumeInvalidContext   .equ 0xA502
osdErrNTNotEnoughStack         .equ 0xA601
osdErrNTReturnFromNoNTF        .equ 0xA602

osdMB9DF126                    .equ 0
osdMB9DF125                    .equ 1
osdMB9EF226                    .equ 2
osdS6J32xx                     .equ 3


INVALID_TASK                    .equ 0xFF
INVALID_PRIORITY                .equ 0xFF

TASK_NONPREEMPTIVE              .equ 0
TASK_PREEMPTIVE                 .equ 1

osSizeOfTaskParamStructure      .equ  16
osSizeOfTcbConfigStructure      .equ 12

osHandlesAllIsr                 .equ 0
osdStackCheckPattern            .equ   0xaaaaaaaa

SVC_DISPATCH                    .equ 0
SVC_TRAP_ENTRY                  .equ 1
SVC_TRAP_EXIT                   .equ 2
SVC_SET_PRIVILEGE               .equ 3

OS_INT_MPU_MPU_TYPE                 .equ   0xE000ED90
OS_INT_MPU_MPU_CTRL                 .equ   0xE000ED94
OS_INT_MPU_MPU_RNR                  .equ   0xE000ED98
OS_INT_MPU_MPU_RBAR                 .equ   0xE000ED9C
OS_INT_MPU_MPU_RASR                 .equ   0xE000EDA0

;-+--------------------------------------------------------------------------
; EOF
;----------------------------------------------------------------------------






































