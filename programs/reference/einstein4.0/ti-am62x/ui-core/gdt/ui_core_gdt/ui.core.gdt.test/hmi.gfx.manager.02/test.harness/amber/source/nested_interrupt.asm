;************************************************************************
;*                                                                      *
;*  assembler definitions for enabling nested interrupts                *
;*                                                                      *
;************************************************************************

;************************************************************************
;* 1  Disclaimer                                                        *
;************************************************************************
;* __DISCLAIMER_START__                                                 *
;************************************************************************
;* Copyright (C) 2014 Spansion LLC. All Rights Reserved. 
;*
;* This software is owned and published by: 
;* Spansion LLC, 915 DeGuigne Dr. Sunnyvale, CA  94088-3453 ("Spansion").
;*
;* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND 
;* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
;*
;* This software contains source code for use with Spansion 
;* components. This software is licensed by Spansion to be adapted only 
;* for use in systems utilizing Spansion components. Spansion shall not be 
;* responsible for misuse or illegal use of this software for devices not 
;* supported herein.  Spansion is providing this software "AS IS" and will 
;* not be responsible for issues arising from incorrect user implementation 
;* of the software.  
;*
;* SPANSION MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
;* REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS), 
;* ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING, 
;* WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED 
;* WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED 
;* WARRANTY OF NONINFRINGEMENT.  
;* SPANSION SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT, 
;* NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT 
;* LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION, 
;* LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR 
;* INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT, 
;* INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA, 
;* SAVINGS OR PROFITS, 
;* EVEN IF SPANSION HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. 
;* YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
;* INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED 
;* FROM, THE SOFTWARE.  
;*
;* This software may be replicated in part or whole for the licensed use, 
;* with the restriction that this Disclaimer and Copyright notice must be 
;* included with each copy of this software, whether used in part or whole, 
;* at all times.
;************************************************************************
; __DISCLAIMER_END__                                                    *
;************************************************************************
;************************************************************************
;* 2  Contents                                                          *
;************************************************************************
;*  1  Disclaimer                                                       *
;*  2  Contents                                                         *
;*  3  History                                                          *
;*  4  Local definitions                                                *
;*  5  Assembler macro code                                             *
;************************************************************************
;* 3  History                                                           *
;************************************************************************
;* Version Date        Author   Description                             *
;* V0.01   2014-04-10  HS       Initial version for Traveo              *


;************************************************************************
;* 4  Local definitions                                                 *
;************************************************************************

;* define register address
ADDRESS_OF_IRC0_CSR    .equ    0xb0400c98
ADDRESS_OF_IRQST_nIRQ  .equ    0xb1100078
ADDRESS_OF_IRC0_IRQHC  .equ    0xb0400c48


;************************************************************************
;* 5  Assembler macro code                                              *
;************************************************************************
;* This macro can be used to define a nested IRQ handler.
;* Currently GHS comliler does not support IRQ nesting,
;* so it is necessary to code in assembly language to define nested IRQ handler.
;*
;* Parameters:
;*  irq_handler_name: IRQ handler name.This macro generates a hanlder named irq_handler_name.
;*  isr_name        : Interrup service routine name which called by the irq_handler_name.
;*  irq_num         : IRQ number
;*
;* How to use:
;*  Define hanlders using the steps explained below.
;*
;*  - At first, make new assembler file.
;*  - Next include this file from new file.
;*  - Then Define handlers using this macro.
;*  - Implement Interrupt service routine "isr_name".
;*    "isr_name" can be coded in C or assembly language.
;*  - Assign irq_handler_name to INTERRUPTS_IRQ_ISR_??? which is defined in interrupts.h.
;*
;* example:
;*      - In new file
;*          .include    "nested_interrupt.asm"
;*
;*          .text       ;* Declare code section. (Change section if you need.)
;*          .nothumb    ;* use ARM mode.
;*
;*          define_nested_irq_handler irq_handler_0, irq_isr_0, 0
;*
;*          END
;*
;*      - In any file
;*          // implement ISR
;*          void irq_isr_0(void)
;*          {
;*              // code to handle the IRQ
;*              // clear IRQ flag at source (peripheral or software interrupt)
;*          }
;*
;*      - In interrupts.h
;*        // assign INTERRUPTS_IRQ_ISR_0
;*        #define INTERRUPTS_IRQ_ISR_0        irq_handler_0  ///< IRQ#0
;*
.macro define_nested_irq_handler irq_handler_name, isr_name, irq_num

    .macrolocal IRQST_check_loop
    .export     irq_handler_name
    .import     isr_name

irq_handler_name:
    SUB     lr, lr, #4                              ;* Save LR_irq and SPS_irq on system stack
    SRSFD   sp!, #0x1f                              ;* 
    CPS     #0x1f                                   ;* Switch to system mode
    PUSH    {r0-r3, r12}                            ;* Store remaining AAPCS register on system stack
    AND     r1, sp, #4                              ;* Ensure stack is 8-byte aligned
    SUB     sp, sp, r1                              ;* 
    PUSH    {r1, lr}                                ;* Save LR_sys and stack adjusted value

    CPSIE   i                                       ;* Enable IRQ

    ;* Dummy write to IRC0_CSR (for enable IRQ)
    ;* Normally, IRQEN is "1" when jump to IRQ handler.
    MOVW    r1, #(ADDRESS_OF_IRC0_CSR & 0xFFFF)     ;* Load register address (lower 16bit)
    MOVT    r1, #(ADDRESS_OF_IRC0_CSR >> 16)        ;* Load register address (upper 16bit)
    MOV     r0, #1                                  ;* Set IRQEN bit to "1" (enable IRQ)
    STR     r0, [r1]                                ;* 

    ;* Call interrupt service routine
    LDR     r1, =isr_name
    BLX     r1

    ;* Check IRQST
    MOVW    r1, #(ADDRESS_OF_IRQST_nIRQ & 0xFFFF)   ;* Load register address (lower 16bit)
    MOVT    r1, #(ADDRESS_OF_IRQST_nIRQ >> 16)      ;* Load register address (upper 16bit)
IRQST_check_loop:
    LDRB    r0, [r1]                                ;* Read register value
    CMP     r0, #0
    BEQ     IRQST_check_loop                        ;* Loop while nIRQ == 0

    CPSID   i                                       ;* Disable IRQ

    ;* Clear hold bit
    MOVW    r0, #(irq_num & 0x1FF)                  ;* Set to IRQ number (valid range: 0 to 511)
    MOVW    r1, #(ADDRESS_OF_IRC0_IRQHC & 0xFFFF)   ;* Load register address (lower 16bit)
    MOVT    r1, #(ADDRESS_OF_IRC0_IRQHC >> 16)      ;* Load register address (upper 16bit)
    STR     r0, [r1]                                ;* Clear hold bit

    POP     {r1, lr}                                ;* Restore LR_sys and unajust stack
    ADD     sp, sp, r1                              ;* 
    POP     {r0-r3, r12}                            ;* Restore AAPCS register
    RFEFD   sp!                                     ;* Return from system stack mode

.endm

