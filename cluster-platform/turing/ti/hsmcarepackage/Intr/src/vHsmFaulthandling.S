 ;@file    vHsmFaulthandling.S
; brief   Cortex-M4 HSM Fault Handling 
;

;
; Copyright (c) 2025 Visteon
;

    .global vHsmFaultLogging
    .global vHsmFault_Logger

vHsmFaultLogging:
    TST     LR, #4          ; Check bit 2 of EXC_RETURN (LR)
    BEQ     use_msp         ; If 0, MSP was in use
    MRS     R0, PSP         ; Else, use PSP
    B       call_logger

use_msp:
    MRS     R0, MSP         ; Use MSP

call_logger:
    B       vHsmFault_Logger  ; Call C logger with R0 = stack pointer