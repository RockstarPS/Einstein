/*****************************************************************************
*
*                CONFIDENTIAL VISTEON CORPORATION                        
*                                                                        
*   This is an unpublished work of authorship, which contains trade      
*   secrets, created in 2024. Visteon Corporation owns all rights to     
*   this work and intends to maintain it in confidence to preserve       
*   its trade secret status. Visteon Corporation reserves the right,     
*   under the copyright laws of the United States or those of any        
*   other country that may have jurisdiction, to protect this work       
*   as an unpublished work, in the event of an inadvertent or            
*   deliberate unauthorized publication. Visteon Corporation also        
*   reserves its rights under all copyright laws to protect this         
*   work as a published work, when appropriate. Those having access      
*   to this work may not copy it, use it, modify it or disclose the      
*   information contained in it without the written authorization        
*   of Visteon Corporation.                                              
*
*   Project Name: Einstein4.0
*   File Name: Cortstcpu.S;
*   Description: Assembler functions for CorTst ARM Cortex R5F (CLANG compiler)
*
****************************************************************************/


//****************************************************************************
//* File settings
//****************************************************************************
        .arm
        .align 2 

//***************************************************************
//* FUNCTION DEF: retcpuregister
//***************************************************************
retcpuregister:
        BL Cortst_CpuTestFail
        POP    {r14}
        POP    {r12}
        POP    {r11}
        POP    {r10}
        POP    {r9}
        POP    {r8}
        POP    {r7}
        POP    {r6}
        POP    {r5}
        POP    {r4}
        POP    {r3}
        POP    {r2}
        POP    {r1}
        POP    {r0}
        BX  lr

//***************************************************************
//* FUNCTION DEF: CorTst_TestRegister
//***************************************************************
CorTst_TestRegister:
        PUSH    {r0}
        PUSH    {r1}
        PUSH    {r2}
        PUSH    {r3}
        PUSH    {r4}
        PUSH    {r5}
        PUSH    {r6}
        PUSH    {r7}
        PUSH    {r8}
        PUSH    {r9}
        PUSH    {r10}
        PUSH    {r11}
        PUSH    {r12}
        PUSH    {r14}
        MOV r0, #1   
        CMP r0, #1
        BNE retcpuregister
        MOV r1, #1
        CMP r1, #1
        BNE retcpuregister
        MOV r2, #1
        CMP r2, #1
        BNE     retcpuregister
        MOV r3, #1
        CMP r3, #1
        BNE     retcpuregister
        MOV r4, #1
        CMP r4, #1
        BNE     retcpuregister
        MOV r5, #1
        CMP r5, #1
        BNE     retcpuregister
        MOV r6, #1
        CMP r6, #1
        BNE     retcpuregister
        MOV r7, #1
        CMP r7, #1
        BNE     retcpuregister
        MOV r8, #1
        CMP r8, #1
        BNE     retcpuregister
        MOV r9, #1
        CMP r9, #1
        BNE     retcpuregister
        MOV r10, #1
        CMP r10, #1
        BNE     retcpuregister
        MOV r11, #1
        CMP r11, #1
        BNE     retcpuregister
        MOV r12, #1
        CMP r12, #1
        BNE     retcpuregister
        POP    {r14}
        POP    {r12}
        POP    {r11}
        POP    {r10}
        POP    {r9}
        POP    {r8}
        POP    {r7}
        POP    {r6}
        POP    {r5}
        POP    {r4}
        POP    {r3}
        POP    {r2}
        POP    {r1}
        POP    {r0}
        BX  lr


//****************************************************************************
//* CorTst_TestAddrGeneration                                                 
//****************************************************************************
addrgen:
        MOV r0, #2
        BX  lr

CorTst_TestAddrGeneration:
        PUSH    {r0}
        PUSH    {r14}
        MOV r0, #1
        CMP r0, #1
        BNE cortst_AddrGenerationFunc
        MOV r0, #2
        CMP r0, #2
        BNE cortst_AddrGenerationFunc
        POP     {r14}
        POP     {r0}
        BX  lr


cortst_AddrGenerationFunc:
        BL  Cortst_AddressGenerationFail
        POP {r14}
        POP {r0}
        BX  lr


//****************************************************************************
//* CorTst_TestMemIf                                                          
//****************************************************************************

CorTst_TestMemIf:
        PUSH {r0}
        PUSH {r1}
        PUSH {r2}
        LDR  r0, =cortst_memtestAddr
        LDR  r0, [r0]
        LDR  r1, [r0]
        MOV r2, #7
        PUSH {r14}
        CMP r1,r2
        BNE cortst_MemIfFunc
        POP {r14}
        POP {r2}
        POP {r1}
        POP {r0}
        BX  lr

cortst_MemIfFunc:
        BL  Cortst_MemoryInterfaceFail
        POP {r14}
        POP {r2}
        POP {r1}
        POP {r0}
        BX  lr


//***************************************************************
//* CONSTANTS USED BY THIS MODULE
//***************************************************************
cortst_memtestAddr: .long cortst_memtest

//***************************************************************
//* UNDEFINED REFERENCES
//***************************************************************
        .global CorTst_TestRegister
        .global CorTst_TestAddrGeneration
        .global CorTst_TestMemIf
        .global CorTst_TestCache
        .global Cortst_CpuTestFail
        .global Cortst_AddressGenerationFail
        .global Cortst_MemoryInterfaceFail
        .global cortst_memtest


