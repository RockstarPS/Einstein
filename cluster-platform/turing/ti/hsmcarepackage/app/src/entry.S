 ;@file    entry.S
; brief   Cortex-M4 Core Device startup for HSM Stub
;

;
; Copyright (c) 2022-2023 Texas Instruments, Inc.
;
;

;
; Exception vector table
;

    .global    __Vectors
    .global    __start_process_stack
    .global    __start_main_stack
    .global    SysTick_Handler
    .global    Reset_Handler
    .global    main
    .global    NMI_Handler
    .global    HardFault_Handler
    .global    MemManage_Handler
    .global    BusFault_Handler
    .global    UsageFault_Handler
    .global    SVC_Handler
    .global    DebugMon_Handler
    .global    PendSV_Handler
    .global    vtor_base
    .global    vtor_base_addr
    .global    _start_process_stack_addr
    .global    _start_main_stack_addr
    .global    mask_interrupts
    .global    Reserved_handler


__Vectors:
    ; Internal Interrupts
    .long      __start_main_stack      ; 0x000  thread stack end point 
    .long      Reset_Handler           ; 0x004  Reset Handler 
    .long      NMI_Handler             ; 0x008  NMI Handler 
    .long      HardFault_Handler       ; 0x00c  Hard Fault Handler 
    .long      MemManage_Handler       ; 0x010  MPU Fault Handler 
    .long      BusFault_Handler        ; 0x014  Bus failure 
    .long      UsageFault_Handler      ; 0x018  usage failure 
    .long      Reserved_handler        ; 0x01C  Reserved 
    .long      Reserved_handler        ; 0x020  Reserved 
    .long      Reserved_handler        ; 0x024  Reserved 
    .long      Reserved_handler        ; 0x028  Reserved 
    .long      SVC_Handler             ; 0x02c  SVCall Handler 
    .long      DebugMon_Handler        ; 0x030  Debug Monitor Handler
    .long      Reserved_handler        ; 0x034  Reserved 
    .long      PendSV_Handler          ; 0x038  PendSV Handler 
    .long      0                       ; 0x03c  SysTick Handler 
    .long      0         ; Int num = 16 
    .long      0         ; Int num = 17
    .long      0         ; Int num = 18
    .long      0         ; Int num = 19
    .long      0         ; Int num = 20
    .long      0         ; Int num = 21
    .long      0         ; Int num = 22
    .long      0         ; Int num = 23
    .long      0         ; Int num = 24
    .long      0         ; Int num = 25
    .long      0         ; Int num = 26
    .long      0         ; Int num = 27
    .long      0         ; Int num = 28
    .long      0         ; Int num = 29
    .long      0         ; Int num = 30
    .long      0         ; Int num = 31
    .long      0         ; Int num = 32
    .long      0         ; Int num = 33
    .long      0         ; Int num = 34
    .long      0         ; Int num = 35
    .long      0         ; Int num = 36
    .long      0         ; Int num = 37
    .long      0         ; Int num = 38
    .long      0         ; Int num = 39
    .long      0         ; Int num = 40
    .long      0         ; Int num = 41 
    .long      0         ; Int num = 42
    .long      0         ; Int num = 43
    .long      0         ; Int num = 44
    .long      0         ; Int num = 45
    .long      0         ; Int num = 46
    .long      0         ; Int num = 47
    .long      0         ; Int num = 48
    .long      0         ; Int num = 49
    .long      0         ; Int num = 50
    .long      0         ; Int num = 51
    .long      0         ; Int num = 52
    .long      0         ; Int num = 53
    .long      0         ; Int num = 54
    .long      0         ; Int num = 55
    .long      0         ; Int num = 56
    .long      0         ; Int num = 57
    .long      0         ; Int num = 58
    .long      0         ; Int num = 59
    .long      0         ; Int num = 60
    .long      0         ; Int num = 61
    .long      0         ; Int num = 62
    .long      0         ; Int num = 63
    .long      0         ; Int num = 64
    .long      0         ; Int num = 65
    .long      0         ; Int num = 66 
    .long      0         ; Int num = 67
    .long      0         ; Int num = 68
    .long      0         ; Int num = 69
    .long      0         ; Int num = 70
    .long      0         ; Int num = 71
    .long      0         ; Int num = 72
    .long      0         ; Int num = 73
    .long      0         ; Int num = 74
    .long      0         ; Int num = 75
    .long      0         ; Int num = 76
    .long      0         ; Int num = 77
    .long      0         ; Int num = 78
    .long      0         ; Int num = 79
    .long      0         ; Int num = 80
    .long      0         ; Int num = 81
    .long      0         ; Int num = 82
    .long      0         ; Int num = 83
    .long      0         ; Int num = 84
    .long      0         ; Int num = 85
    .long      0         ; Int num = 86
    .long      0         ; Int num = 87
    .long      0         ; Int num = 88
    .long      0         ; Int num = 89
    .long      0         ; Int num = 90
    .long      0         ; Int num = 91 
    .long      0         ; Int num = 92
    .long      0         ; Int num = 93
    .long      0         ; Int num = 94
    .long      0         ; Int num = 95
    .long      0         ; Int num = 96
    .long      0         ; Int num = 97
    .long      0         ; Int num = 98
    .long      0         ; Int num = 99
    .long      0         ; Int num = 100
    .long      0         ; Int num = 101
    .long      0         ; Int num = 102
    .long      0         ; Int num = 103
    .long      0         ; Int num = 104
    .long      0         ; Int num = 105
    .long      0         ; Int num = 106
    .long      0         ; Int num = 107
    .long      0         ; Int num = 108
    .long      0         ; Int num = 109
    .long      0         ; Int num = 110
    .long      0         ; Int num = 111
    .long      0         ; Int num = 112
    .long      0         ; Int num = 113
    .long      0         ; Int num = 114
    .long      0         ; Int num = 115
    .long      0         ; Int num = 116 
    .long      0         ; Int num = 117
    .long      0         ; Int num = 118
    .long      0         ; Int num = 119
    .long      0         ; Int num = 120
    .long      0         ; Int num = 121
    .long      0         ; Int num = 122
    .long      0         ; Int num = 123
    .long      0         ; Int num = 124
    .long      0         ; Int num = 125
    .long      0         ; Int num = 126
    .long      0         ; Int num = 127
    .long      0         ; Int num = 128
    .long      0         ; Int num = 129
    .long      0         ; Int num = 130
    .long      0         ; Int num = 131
    .long      0         ; Int num = 132
    .long      0         ; Int num = 133
    .long      0         ; Int num = 134
    .long      0         ; Int num = 135
    .long      0         ; Int num = 136
    .long      0         ; Int num = 137
    .long      0         ; Int num = 138
    .long      0         ; Int num = 139
    .long      0         ; Int num = 140
    .long      0         ; Int num = 141 
    .long      0         ; Int num = 142
    .long      0         ; Int num = 143
    .long      0         ; Int num = 144
    .long      0         ; Int num = 145
    .long      0         ; Int num = 146
    .long      0         ; Int num = 147
    .long      0         ; Int num = 148
    .long      0         ; Int num = 149
    .long      0         ; Int num = 150
    .long      0         ; Int num = 151
    .long      0         ; Int num = 152
    .long      0         ; Int num = 153
    .long      0         ; Int num = 154
    .long      0         ; Int num = 155
    .long      0         ; Int num = 156
    .long      0         ; Int num = 157
    .long      0         ; Int num = 158
    .long      0         ; Int num = 159
    .long      0         ; Int num = 160
    .long      0         ; Int num = 161
    .long      0         ; Int num = 162
    .long      0         ; Int num = 163
    .long      0         ; Int num = 164
    .long      0         ; Int num = 165
    .long      0         ; Int num = 166 
    .long      0         ; Int num = 167
    .long      0         ; Int num = 168
    .long      0         ; Int num = 169
    .long      0         ; Int num = 170
    .long      0         ; Int num = 171
    .long      0         ; Int num = 172
    .long      0         ; Int num = 173
    .long      0         ; Int num = 174
    .long      0         ; Int num = 175
    .long      0         ; Int num = 176
    .long      0         ; Int num = 177
    .long      0         ; Int num = 178
    .long      0         ; Int num = 179
    .long      0         ; Int num = 180
    .long      0         ; Int num = 181
    .long      0         ; Int num = 182
    .long      0         ; Int num = 183
    .long      0         ; Int num = 184
    .long      0         ; Int num = 185
    .long      0         ; Int num = 186
    .long      0         ; Int num = 187
    .long      0         ; Int num = 188
    .long      0         ; Int num = 189
    .long      0         ; Int num = 190
    .long      0         ; Int num = 191 
    .long      0         ; Int num = 192
    .long      0         ; Int num = 193
    .long      0         ; Int num = 194
    .long      0         ; Int num = 195
    .long      0         ; Int num = 196
    .long      0         ; Int num = 197
    .long      0         ; Int num = 198
    .long      0         ; Int num = 199
    .long      0         ; Int num = 200
    .long      0         ; Int num = 201
    .long      0         ; Int num = 202
    .long      0         ; Int num = 203
    .long      0         ; Int num = 204
    .long      0         ; Int num = 205
    .long      0         ; Int num = 206
    .long      0         ; Int num = 207
    .long      0         ; Int num = 208
    .long      0         ; Int num = 209
    .long      0         ; Int num = 210
    .long      0         ; Int num = 211
    .long      0         ; Int num = 212
    .long      0         ; Int num = 213
    .long      0         ; Int num = 214
    .long      0         ; Int num = 215
    .long      0         ; Int num = 216 
    .long      0         ; Int num = 217
    .long      0         ; Int num = 218
    .long      0         ; Int num = 219
    .long      0         ; Int num = 220
    .long      0         ; Int num = 221
    .long      0         ; Int num = 222
    .long      0         ; Int num = 223
    .long      0         ; Int num = 224
    .long      0         ; Int num = 225
    .long      0         ; Int num = 226
    .long      0         ; Int num = 227
    .long      0         ; Int num = 228
    .long      0         ; Int num = 229
    .long      0         ; Int num = 230
    .long      0         ; Int num = 231
    .long      0         ; Int num = 232
    .long      0         ; Int num = 233
    .long      0         ; Int num = 234
    .long      0         ; Int num = 235
    .long      0         ; Int num = 236
    .long      0         ; Int num = 237
    .long      0         ; Int num = 238
    .long      0         ; Int num = 239
    
    ; Constants 
vtor_base       .equ     0xe000ed08
scb_base        .equ     0xe000ed24

    ; Internal Handlers 
    ; Reset Handler 
    .text
    .thumb
Reset_Handler:
    ldr    r0, _vtor_base_addr
    ldr    r1, _vector_addr
    str    r1, [r0]
    
    bl      mask_interrupts

    ldr    r0, _scb_basead
    ldr    r1, [r0]
    orr    r1, r1, #(1 << 16)  ;MEMFAULTENA
    orr    r1, r1, #(1 << 17)  ;BUSFAULTENA 
    orr    r1, r1, #(1 << 18)  ;USGFAULTENA 
    str    r1, [r0]

    ; Stack init 
    ldr     r3, _start_process_stack_addr
    msr     PSP, r3
    mrs     r3, CONTROL
    orr.w   r3, r3, #2
    msr     CONTROL, r3
    isb     
    ldr     r3, _start_main_stack_addr
    msr     MSP, r3


    ; Jump to main 
    bl     main

_vector_addr:
    .word __Vectors
_vtor_base_addr:
    .word vtor_base
_scb_basead:
    .word scb_base
_start_process_stack_addr:
    .word __start_process_stack
_start_main_stack_addr:
    .word __start_main_stack

zeros:
    .long 0x00000000
    .long 0x00000000
    .long 0x00000000
    .long 0x00000000
    .long 0x00000000
    .long 0x00000000
    .long 0x00000000
    .long 0x00000000

    ; Default Handlers for other exceptions 
    .align 1

IRQ_Handler:
    bl      Reset_Handler
SysTick_Handler:
    b      SysTick_Handler

