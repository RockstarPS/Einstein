/*****************************************************************************
*
*                CONFIDENTIAL VISTEON CORPORATION                        
*                                                                        
*   This is an unpublished work of authorship, which contains trade      
*   secrets, created in 2013. Visteon Corporation owns all rights to     
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
*
*   Project Name: mOS Turing-B Non-Autosar
*   File Name: OsAsm.S
*
*
*   Description: Assembler functions for mOS ARM Cortex R5 (CLANG compiler)
*
*
*****************************************************************************/
    .section ".OsCode","ax",%progbits
    .arm
    .align 2

/*****************************************************************************
* Includes
*****************************************************************************/
    .include "OsCoreDefine.inc"
    
    .set    osUserMode                        ,0b10000
    .set    osFIQMode                         ,0b10001
    .set    osIRQMode                         ,0b10010
    .set    osSVCMode                         ,0b10011
    .set    osAbortMode                       ,0b10111
    .set    osUndefMode                       ,0b11011
    .set    osSysMode                         ,0b11111
    .set    osModeMask                        ,0b11111

    .set    osdNumberOfServices               ,66

    .set    osIFlag                           ,0b10000000

    .set    osdTaskStartCPSR_Usr              ,0b0000010000
    .set    osdTaskStartCPSR_Sys              ,0b0000011111

    .set    osdNoActiveTask                   ,0xffffffff
    .set    osdInvalidIsrID                   ,0xffffffff
    .set    osdORTINoService                  ,0

    .set    PRE_READY                         ,0
    .set    RUNNING                           ,1
    .set    READY                             ,3

    .set    STANDARD_STATUS                   ,0
    .set    EXTENDED_STATUS                   ,1

    .set    osdPICMode                        ,0

    .set    osdCtxTask                        ,0x0001
    .set    osdCtxISRCat2                     ,0x0002
    .set    osdCtxPreTaskHook                 ,0x0004
    .set    osdCtxPostTaskHook                ,0x0008
    .set    osdCtxErrorHook                   ,0x0010
    .set    osdCtxApplErrorHook               ,0x0020
    .set    osdCtxEachErrorHook               ,0x0030
    .set    osdCtxStartupHook                 ,0x0040
    .set    osdCtxShutdownHook                ,0x0080
    .set    osdCtxProtectionHook              ,0x0100
    .set    osdCtxCOMErrorHook                ,0x0200
    .set    osdCtxCOMCallback                 ,0x0400
    .set    osdCtxStartComExtens              ,0x0800
    .set    osdCtxErrorHookFromStartupHook    ,0x1000

    .set    osdStackWindowAccessRights        ,0x0000130b

    .set    osIRQ_BASE                        ,0x07FF
    .set    osIRQ0_IRQHC                      ,0x0404
    .set    osIRQ0_CSR                        ,0x0c98
    .set    osIRQ0_UNLOCK                     ,0x0d30
    .set    osIRQ0_IRQR0                      ,0x0410

    .set    osdIRQ_UnlockValueTop             ,0x17AC
    .set    osdIRQ_UnlockValueBot             ,0xC911
    .set    osdIRQ_LockValueTop               ,0x17B1
    .set    osdIRQ_LockValueBot               ,0x0C11
    .set    osdIRQ_CSR_EnableBit              ,1

    .set    E_OS_DISABLEDINT                  ,12
    .set    E_OS_STACKFAULT                   ,13
    .set    E_OS_SYS_ASSERTION                ,20
    .set    E_OS_SYS_ABORT                    ,21
    .set    osdErrSYReturnFromNoISR           ,0xA402
    .set    osdErrIXIntAPIDisabled            ,0x2302
    .set    osdErrDPStartValidContext         ,0xA501
    .set    osdErrDPResumeInvalidContext      ,0xA502
    .set    osdErrNTNotEnoughStack            ,0xA601
    .set    osdErrNTReturnFromNoNTF           ,0xA602

    .set    osdMB9DF126                       ,0
    .set    osdMB9DF125                       ,1
    .set    osdMB9EF226                       ,2
    .set    osdS6J32xx                        ,3

    .set    INVALID_TASK                      ,0xFF
    .set    INVALID_PRIORITY                  ,0xFF

    .set    TASK_NONPREEMPTIVE                ,0
    .set    TASK_PREEMPTIVE                   ,1

    .set    osSizeOfTaskParamStructure        ,16
    .set    osSizeOfTcbConfigStructure        ,12

    .set    osHandlesAllIsr                   ,0

    .set    OS_CFG_SUPPORT_DBG_HOOKS_ASM      ,0
    .set    RTM_ENABLED_ASM                   ,0
    .set    osdStackCheckPattern              ,0xaaaaaaaa
/* Reference to Offset and Sizeof values */
    .set    OsStackTypeStartAddrOffset                      ,0
    .set    OsStackTypeEndAddrOffset                        ,4
    .set    TaskParamTypeWaitEventMaskOffset                ,0
    .set    TaskParamTypeSetEventMaskOffset                 ,8
    .set    TaskParamTypeStackAddressOffset                 ,16
    .set    TaskParamTypeStateOffset                        ,20
    .set    TaskParamTypeActivationCntOffset                ,21
    .set    OsTaskConfigTypeTaskStartAddressOffset          ,0
    .set    OsTaskConfigTypeTaskStackStartAddressOffset     ,4
    .set    OsTaskConfigTypeTaskCategoryOffset              ,14
    .set    OsTaskConfigTypeTaskParamRefOffset              ,28
    .set    OsCtrlParamTypeActiveISRIdOffset                ,12
    .set    OsCtrlParamTypepLastObjRefOffset                ,16
    .set    OsCtrlParamTypepActiveObjRefOffset              ,20
    .set    OsCtrlParamTypeActiveTaskIndexOffset            ,24
    .set    OsCtrlParamTypeRequestedTaskIndexOffset         ,25
    .set    OsCtrlParamTypeActiveTaskPriorityOffset         ,26
    .set    OsCtrlParamTypeRequestedTaskPriorityOffset      ,27
    .set    OsCtrlParamTypeRequestSchedulerOffset           ,36
    .set    OsCtrlParamTypeLockDispatcherOffset             ,37
    .set    OsCtrlParamTypeIntSaveDisableRequestCounterOffset  ,38
    .set    OsCtrlParamTypeCurrentContextOffset             ,48
    .set    sizeofTaskParamType                             ,24
    .set    sizeofOsTaskConfigRefType                       ,4
    .set    OsObjConfigTypeStackStartAddressOffset          ,16
    .set    OsObjConfigTypeStackSizeOffset                  ,20
    .set    OsObjConfigTypeStackRegAttributeOffset          ,24
    .set    OsObjConfigTypeStackRegnSizeAndEnableOffset     ,28
/*****************************************************************************
* Macros                                                             
*****************************************************************************/
.macro OS_CPU_HAL_ASM_SWITCH_STACK pObjRef, StackAddr
    .if osdMPUProtection == 1
        /* Switch Mpu setting for Active Task */
        ldr    r1, =osdMPUStackRegNum    /* Load MPU region number for stack into r1 */
        mcr    p15, #0, r1, c6, c2, #0             /* select MPU region */
        mov    r1, #0
        mcr    p15, #0, r1, c6, c1, #2             /* Region disabled */
        /* Load StackStartAddress into R1 */
        ldr    r1, [\pObjRef, #OsObjConfigTypeStackStartAddressOffset]
        mcr    p15, #0, r1, c6, c1, #0             /* set region base address */
        /* Load StackRegAttribute into R1 */
        ldr    r1, [\pObjRef, #OsObjConfigTypeStackRegAttributeOffset]
        mcr    p15, #0, r1, c6, c1, #4            /* set protection attributes */
        /* Load StackRegnSizeAndEnable into r1 */
        ldr    r1, [\pObjRef, #OsObjConfigTypeStackRegnSizeAndEnableOffset]
        mcr    p15, #0, r1, c6, c1, #2             /* set region size and enable bit */
    .endif
    /* switch stack pointer */
    mov sp, \StackAddr
    dsb    /* data barrier sync */
    isb    /* instruction barrier sync */
.endm
/*****************************************************************************
* osStartOSasmArm                                                             
*****************************************************************************/
    .global osStartOSasmArm
    .type osStartOSasmArm,%function
    
osStartOSasmArm:
/*  Switch to system mode and set the system stack pointer
    all other stack pointers are set it osInitialize() */
    CPSID      i, #osSysMode               /*( IRQ are disabled from here on)*/

    LDR r1, OsSYSStackAddr
    LDR sp, [r1, #OsStackTypeStartAddrOffset]

    LDR r0, [r1, #OsStackTypeEndAddrOffset]
    mov r1,sp
    LDR r2, =osdStackCheckPattern /* osdStackCheckPattern */
        
osPrvFillLoop:
    stmfd   r1!,{r2}
    cmp     r1,r0
    bne     osPrvFillLoop

    ldr     r0, osStartOSAddr
    bx      r0
/* this call never returns */

/******************************************************************************
*  ARM Core SCTLR register
******************************************************************************/
/* set some bits in the SCTLR register */
    .global osSetBitsARMCoreSCTLR
    .type osSetBitsARMCoreSCTLR,%function
osSetBitsARMCoreSCTLR:
   MOV        R1, #0                          /* R1 = 0 */
   MRC        p15, #0, R1, c1, c0, #0         /* R1 = SCTLR */
   ORR        R1, R1, R0                      /* R1 |= R0   (R0 is the passed parameter) */ 
   MCR        p15, #0, R1, c1, c0, #0         /* SCTLR = R1 */
   BX         lr

/* clear some bits in the SCTLR register*/
    .global osClearBitsARMCoreSCTLR
    .type osClearBitsARMCoreSCTLR,%function
osClearBitsARMCoreSCTLR:
   MOV        R1, #0                          /* R1 = 0 */
   MRC        p15, #0, R1, c1, c0, #0         /* R1 = SCTLR */
   BIC        R1, R1, R0                      /* R1 &= ~R0   (R0 is the passed parameter) */
   MCR        p15, #0, R1, c1, c0, #0         /* SCTLR = R1 */
   BX         lr



/******************************************************************************
* osuint32 osGetCPSR()
******************************************************************************/
    .global osGetCPSR
    .type osGetCPSR,%function
osGetCPSR:
   mrs    R0,CPSR
   BX         lr

/******************************************************************************
* osuint32 osSuspendInterruptsAsm()
******************************************************************************/
    .global osSuspendInterruptsAsm
    .type osSuspendInterruptsAsm,%function
osSuspendInterruptsAsm:
    mrs     r0,CPSR
    cpsid   i
    and     r0,r0,#0x80
    BX         lr
   
/******************************************************************************
*  osResumeInterruptsAsm(osuint32)
******************************************************************************/
    .global osResumeInterruptsAsm
    .type osResumeInterruptsAsm,%function
osResumeInterruptsAsm:
   ands     r0,r0,#0x80
   cmp      r0,#0x80
   beq      osPrvSkipIntEnable
   cpsie    i
osPrvSkipIntEnable:
   BX         lr


/******************************************************************************
* osDisableGlobalInterruptAsm                                                
******************************************************************************/
    .global osDisableGlobalInterruptAsm
    .type osDisableGlobalInterruptAsm,%function
osDisableGlobalInterruptAsm:
    cpsid       i
    BX         lr

/******************************************************************************
* osEnableGlobalInterruptAsm                                                
******************************************************************************/
    .global osEnableGlobalInterruptAsm
    .type osEnableGlobalInterruptAsm,%function
osEnableGlobalInterruptAsm:
    cpsie       i
    BX         lr



/******************************************************************************
* osSetupExceptionStacks 
******************************************************************************/
/* This function must be called before allowing NMIs and Exceptions
 It must be called in System or SVC mode
 Since this function is only called by osInitialize, this is ensured: 
 If user calls it before StartOS, then is is in System Mode. 
 If the StartOS calls it calls, we are in SVC mode */
    .global osSetupExceptionStacks
    .type osSetupExceptionStacks,%function
osSetupExceptionStacks:
   push     {r2}
   push     {r1}
   push     {r0}
   mrs      r0,CPSR               /* save original mode */
   
  /* if current mode == SVC mode: do not initialize SVC mode anymore */
   ands     r1, r0, #osModeMask           
   cmp      r1, #osSVCMode
   beq      osSkipSVCModeInit
   cps      #osSVCMode

    ldr      r1,OsSYSStackAddr
    ldr      sp, [r1, #OsStackTypeStartAddrOffset]
   
osSkipSVCModeInit:
    cps      #osIRQMode
    ldr      r1, OsIRQStackAddr
    ldr      sp, [r1, #OsStackTypeStartAddrOffset]
    
    cps      #osFIQMode
    ldr      r1, OsFIQStackAddr
    ldr      sp, [r1, #OsStackTypeStartAddrOffset]
    
    cps      #osAbortMode
    ldr      r1,OsSYSStackAddr
    ldr      sp, [r1, #OsStackTypeStartAddrOffset]
    cps      #osUndefMode

    ldr      sp, [r1, #OsStackTypeStartAddrOffset]

   msr      CPSR_cf,r0       /* Restore original mode */
   pop      {r0}
   pop      {r1}
   pop      {r2}
   
   BX         lr


/******************************************************************************
* osEnableNMIandAborts
******************************************************************************/
    .global osEnableNMIandAborts
    .type osEnableNMIandAborts,%function
osEnableNMIandAborts:
   cpsie af
/* Note: if an Data Abort occurs here, it was a asynchronous abort, that was triggered earlier but 
       was defered until here */
   BX         lr

/******************************************************************************
* osDispatchAsm 
******************************************************************************/
    .global osPrvDispatchAsm
    .type osPrvDispatchAsm,%function
osPrvDispatchAsm:
    /* we reached here to dispatch a task (may be idle task too) */
    cpsid i     /* #osSysMode */
    bl osPrvDispatcher
    cpsie i
    
    BX         lr

/******************************************************************************
* osPrvDispatcher 
******************************************************************************/
osDispatchApi:
osPrvDispatcher:
    /*  coming here, we assume that the Dispatcher is Unlocked
        are we coming from an inactive task
        (ossActiveTaskIndex != 0)? osFromActiveTask: osFromInActiveTask; */
    srsfd   sp!, #osSysMode          /* push SPSRsvc=CPSRsys and LRsvc=PCsys on task stack       */
    cps     #osSysMode              /* change to SystemMode (restores Task Stack Pointer SPsys) */
    push    {r10}       /* register to work with */
    ldr     r10, OsCtrlParamAddr
    ldrb    r10, [r10, #OsCtrlParamTypeActiveTaskIndexOffset] /* r10 = ActiveTaskIndex */
    cmp     r10, #INVALID_TASK
    beq     osPrvFromInActiveTask

osPrvComingFromActiveTask:
    stmfd sp!,{r0-r9,r11,r12,lr}
    .if osdFPUSupport == 1
        vmrs   r0, FPSCR
        push   {r0}
        vmrs   r0, FPEXC
        push   {r0}
        vpush  {d0-d15}
    .endif

osPrvDispatcherContextPushed:
    /* save ths SP in TcbTaskRefConfig[ActiveTaskIndex]->TaskParamRef->StackAddress */
    ldr     r1, TcbTaskRefConfigAddr
    mov     r2, #sizeofOsTaskConfigRefType
    mla     r3, r10, r2, r1   /* r3 = (r10 * r2) + r1 => r3 = &TcbTaskRefConfig[ActiveTaskIndex] */
    ldr     r3, [r3]          /* r3 = TcbTaskRefConfig[ActiveTaskIndex] */
    add     r3, #OsTaskConfigTypeTaskParamRefOffset    /* r3 = &(TcbTaskRefConfig[ActiveTaskIndex]->TaskParamRef) */
    ldr     r3, [r3]          /* r3 = TcbTaskRefConfig[ActiveTaskIndex]->TaskParamRef */
    add     r4, r3, #TaskParamTypeStackAddressOffset    /* r4 = TcbTaskRefConfig[ActiveTaskIndex]->TaskParamRef->StackAddress */
    str     sp, [r4]        /* store the current task stack pointer here */
    add     r3, r3, #TaskParamTypeStateOffset
    ldrb    r4, [r3]
    cmp     r4, #RUNNING
    bne     osPrvFromInActiveTask
    /* Now we have to make the current task to READY state */
    push    {lr}
    bl      osPrvAsmPostTaskHook         /* call Post Task Hook as the current task gets inactivated */
    pop     {lr}
    mov     r4, #READY
    str     r4, [r3]                      /* osState[ossActiveTaskIndex] = READY */
    /*Implicit continuation of execution if the current task was RUNNING */

osPrvFromInActiveTask:
osPrvFromNoTask:
    ldr     r0, OsCtrlParamAddr
    add     r1, r0, #OsCtrlParamTypeActiveTaskIndexOffset
    add     r2, r0, #OsCtrlParamTypeRequestedTaskIndexOffset
    add     r3, r0, #OsCtrlParamTypeActiveTaskPriorityOffset
    add     r4, r0, #OsCtrlParamTypeRequestedTaskPriorityOffset

    ldrb     r2, [r2]
    ldrb     r4, [r4]
    strb     r2, [r1]   /* ActiveTaskIndex    = RequestedTaskIndex    */
    strb     r4, [r3]   /* ActiveTaskPriority = RequestedTaskPriority */

    push    {r0-r4}
    bl       OsPrvSetTaskActiveParam
    pop     {r0-r4}

    /* RequestScheduler = 0 */
    mov     r4, #0
    strb    r4, [r0, #OsCtrlParamTypeRequestSchedulerOffset]

    /* do we have a valid task? */
    ldrb     r1, [r1]                /* now r1 = ActiveTaskIndex */
    cmp      r1, #INVALID_TASK
    beq      osPrvIdleTask           /* No Active Task, so go Idle */

    /* We have a valid task to dispatch */
    /* Now look if we need to Start or Resume */
    ldr     r2, TcbTaskRefConfigAddr
    mov     r3, #sizeofOsTaskConfigRefType    /* #osSizeOfTcbTaskRefConfigType */
    mla     r4, r1, r3, r2     /* r4=(r1*r3)+r2 =>  r4 = TcbTaskRefConfig[ActiveTaskIndex] */
    ldr     r4, [r4]             /* Load OsTaskConfig_ActiveTask address */
    mov     r5, r4             /* copy r4 to r5 we may need it if we are going to start a new task */
    add     r3, r4, #OsTaskConfigTypeTaskCategoryOffset
    ldrb    r3, [r3]
    add     r2, r0, #OsCtrlParamTypeLockDispatcherOffset
    eor     r3, r3, #1    /* (TcbConfig.TaskCategory==PREEMPTIVE)?Unlock Dispatcher : LockDisptacher */
    strb    r3, [r2]

    /* we have the ActiveTaskIndex still in r1 */
    ldr     r2, TcbTaskRefConfigAddr
    mov     r3, #sizeofOsTaskConfigRefType    /* #sizeofOsTaskConfigRefType */
    mla     r4, r3, r1, r2     /* r4 = (r3 * r1) + r2 (ie., r4 = &TcbTaskRefConfig[ActiveTaskIndex] */
    ldr     r4, [r4]          /* r4 = TcbTaskRefConfig[ActiveTaskIndex] */
    ldr     r4, [r4, #OsTaskConfigTypeTaskParamRefOffset]    /* r4 = TcbTaskRefConfig[ActiveTaskIndex]->TaskParamRef */
    ldrb    r3, [r4, #TaskParamTypeStateOffset]
    cmp     r3, #PRE_READY

    mov     r3, #RUNNING
    strb    r3, [r4, #TaskParamTypeStateOffset]

    beq     osPrvStartTask
osPrvResumeTask:
    /* The TaskState should be READY
       Implicit continuation to Resume the task
       Change state to RUNNING
       mov     r3,#RUNNING
       str     r3,[r4,OffsetOf(OsTaskParamType,State)]
    */
    /* switch MPU so that we have access to the Task MPU setting from here
     OsCtrlParam.pLastObjRef-> Points to the object active before the dispatcher entry
     OsCtrlParam.pActiveObjRef -> Points to the New Object that is scheduled to RUN */
    bl      OsMemProt_MpuSwitch

    /* Get Current Active Object */
    ldr    r0,=OsCtrlParam
    ldr    r0, [r0, #OsCtrlParamTypepActiveObjRefOffset]
    /* Stack pointer to restore context */
    ldr    r3,[r4, #TaskParamTypeStackAddressOffset]
    /* Switch stack MPU setting for Active Object */
    /* Registers r0-r1 modified in the below macro */
    OS_CPU_HAL_ASM_SWITCH_STACK r0, r3

    /* restore task context from task stack */
    .if osdFPUSupport == 1
        vpop   {d0-d15}
        pop    {r0}
        vmrs   r0, FPEXC
        pop    {r0}
        vmrs   r0, FPSCR
    .endif
    /* task context on Task stack: (lowest) ... R0-R9, R11, R12, LRusr, R10, PCusr, CPSRusr, ... task stack ... (highest address) */
    
    push {lr}
    blx osTaskResumeHook
    pop {lr}


    ldmfd  sp!,{r0-r9,r11,r12,lr}
    pop    {r10}

    rfefd    sp!    /* nchellap for checking the Exception */
    /*
    push {r1}
    ldr r1, [r13, #8]
    msr CPSR, r1
    pop {r1}
    ldr lr, [r13]
    bx lr
    */

osPrvStartTask:
    /* state of task is updated as RUNNING */
    /* cps     #osUserMode */
    ldr     r0,[r5,#OsTaskConfigTypeTaskStackStartAddressOffset] /* r0= TcbTaskConfig[ActiveTaskIndex].TaskStackStartAddress */
    add     r1,r4,#TaskParamTypeStackAddressOffset        /* r1= &TcbTaskConfig[ActiveTaskIndex]->TaskParamRef->StackAddress */
    str     r0,[r1]
    
    /* switch MPU so that we have access to the Task MPU setting from here
     OsCtrlParam.pLastObjRef-> Points to the object active before the dispatcher entry
     OsCtrlParam.pActiveObjRef -> Points to the New Object that is scheduled to RUN */
    bl      OsMemProt_MpuSwitch
    
    /* Get Current Active Object */
    ldr     r0,=OsCtrlParam
    ldr     r0, [r0, #OsCtrlParamTypepActiveObjRefOffset]
    /* Stack pointer to start task */
    ldr     r3,[r4, #TaskParamTypeStackAddressOffset]
    /* Switch stack MPU setting for Active Object */
    /* Registers r0-r1 modified in the below macro */
    OS_CPU_HAL_ASM_SWITCH_STACK r0, r3
    
    /*
    we do not need a legal comeback to this place
    leave the LR as corrupted
    switch back to thumb mode if required
    */

    push {lr}
    blx osPrvAsmPreTaskHook
    pop  {lr}
    bl      OsPrvGetCurrAppAccessLevel
    ldr     lr, osMissingTerminateErrorAddr
    cmp    r0, #1
    beq    OsSwitchUserModeExit
    ldr     r0, [r5, #OsTaskConfigTypeTaskStartAddressOffset]
    cpsie   i
    bx      r0
OsSwitchUserModeExit:
    mrs    r0, cpsr                /* Move CPSR to r0 */
    bic    r0, r0, #0x9F           /* Clear the I,M bits */
    orr    r0, r0, #0x10           /* Set the mode bits to User mode (0x10) */
    msr    cpsr, r0                /* Write the modified CPSR back */
    ldr    r0, [r5, #OsTaskConfigTypeTaskStartAddressOffset]
    bx     r0

osPrvIdleTask:
    ldr     r1, OsSYSStackAddr
    ldr     sp, [r1, #OsStackTypeStartAddrOffset]
    ldr     r0, OsCtrlParamAddr
    add     r0, r0, #OsCtrlParamTypeLockDispatcherOffset
    mov     r1, #0
    strb    r1, [r0]
    cpsie   i
    
osIdleLoop:
    .if RTM_ENABLED_ASM
        blx     Rtm_CpuLoadMeasurementFunction
    .endif
    b       osIdleLoop


osPrvAsmPostTaskHook:
    /* For debug and measurement support */
    push {r0-r12,r14}
    bl  osTaskStopHook
    pop {r0-r12,r14}
    mov pc,lr
    
osPrvAsmPreTaskHook:
    push {r0-r12,lr}
    bl osTaskStartHook
    pop {r0-r12,lr}
    mov pc,lr

/******************************************************************************
* osCat2ISREntryASM 
******************************************************************************/
    .global osCat2ISREntryASM
    .type osCat2ISREntryASM,%function
osCat2ISREntryASM:
    /* we get here with user registers r0-r12,lr pushed to interrupted process stack
       except
       r0     - address of this function
       r8     - logical index of the interrupt
       r9     - CPSR value from ISR Wrapper
       r11    - Address of the Application Interrupt Routine
       rest registers are free for work
    */
    .if osdFPUSupport == 1
        vmrs   r0, FPSCR
        push   {r0}
        vmrs   r0, FPEXC
        push   {r0}
        vpush  {d0-d15}
    .endif
    
    ldr     r6, OsCtrlParamAddr
    add     r4, r6, #OsCtrlParamTypeLockDispatcherOffset
    add     r5, r6, #OsCtrlParamTypeCurrentContextOffset
    add     r7, r6, #OsCtrlParamTypeActiveISRIdOffset
    add     r2, r6, #OsCtrlParamTypepActiveObjRefOffset
    
    /* push the current context into stack */
    ldrb    r1, [r5]
    push    {r1}
    /* set the OsContext as osdCat2IsrContext */
    mov     r1, #osdCtxISRCat2
    strh    r1, [r5]
    /* push the current ObjRef to stack */
    ldr     r1, [r2]
    push    {r1}
    /* increment the LockDispatcher */
    ldrb    r1, [r4]
    add     r1, r1, #1
    strb    r1, [r4]

    /*
    movw   r1, #osIRQ0_IRQR0
    movt   r1, #osIRQ_BASE
    mov    r3, #0
    str    r3, [r1]                //  clear the Software interrupt flag 
    */
    /* Save the DynApp of CurrObj */
    bl      OsPrvGetDynApp
    push    {r0}
    
    /* assuming no nesting of interrupt happens, save current sp to r4 */
    ldr    r4, osIntSPAddr
    str    sp,[r4]
    /* str    sp,[r4, r8, lsl #1] */

    mov    r4, #0x3FF
    cmp    r8, r4                   /* check for invalid ISR */
    beq    invalidPendingISR        /* if ISR is invalid, skip MPU and Stack switch */
    
    
    /* Update the ActiveISRId */
    str     r8,[r7]
    
    /* Update the Active App and Obj references */
    bl      OsPrvSetIsrActiveParam
    
    /* We have updated the active app and objects
    Now, switch MPU so that we have ISR Memory protection settings */
    bl      OsMemProt_MpuSwitchFromISR

    /* Get Current Active Object */
    ldr    r0,=OsCtrlParam
    ldr    r0, [r0, #OsCtrlParamTypepActiveObjRefOffset]
    
    ldr    r3, IsrStackConfigAddr
    /* Todo: Update intvect_asm to pass the Isr Id in register
    Interim: As Isr Id is unavailable and Nesting is not supported, all Isrs run in IsrStackConfig[0] */
    ldr     r3,[r3]
    /* Switch stack MPU setting for Active Object */
    /* Registers r0-r1 modified in the below macro */
    OS_CPU_HAL_ASM_SWITCH_STACK r0, r3

invalidPendingISR:
    push    {lr}
    /* service the application ISR */
    msr    cpsr_cxsf, r9
    ldr    lr,osCat2ISRExitASMAddr
    bx     r11

/******************************************************************************
* osCat2ISRExitASM 
******************************************************************************/
    .global    osCat2ISRExitASM
    .type osCat2ISRExitASM,%function
    /* from hereon r11 can be used as working register */
osCat2ISRExitASM:
    bl OsCheckIntDisEnPair

    pop     {lr}         /* pop LR */
    
    /* Getback to the OS Stack */
    ldr    r4, osIntSPAddr
    ldr    r4,[r4]

    /* Get Last Object before Interrupt */
    ldr     r0,=OsCtrlParam
    ldr     r0, [r0, #OsCtrlParamTypepLastObjRefOffset]
    /* Switch stack MPU setting for Last Object */
    /* Registers r0-r1 modified in the below macro */
    OS_CPU_HAL_ASM_SWITCH_STACK r0, r4
    
    ldr     r10,osPrvLastLRAddr
    str     lr,[r10]
    
    pop     {r0}   /* Get stored DynApp from stack    */
    mov     r2,r0  /* save r0(DynApp) to r2 as we are going to use r0 for next call */

    /* restore the previous object */
    pop     {r0}  /* pObjRef */
    push    {r2}  /* push the r2 (DynApp) to stack */

    /* Get the ActiveObjRef updated through the C Handlers */
    bl      OsPrvSetActiveParam         /* OsPrvSetActiveParam(pObjRef) */
    
    pop     {r2}  /* Get stored DynApp from stack */
    mov     r0,r2 /* Pass r0(DynApp) to OsPrvSetDynApp */
    /* Restore the DynApp of CurrObj */
    bl      OsPrvSetDynApp
    bl      OsMemProt_MpuSwitchFromISR

    ldr     r10, OsCtrlParamAddr

    /* Decrement the LockDispatcher */
    add     r0,r10, #OsCtrlParamTypeLockDispatcherOffset
    ldrb    r2,[r0]
    subs    r2,r2,#1   /* OsCtrlParam.LockDispatcher-- */
    strb    r2,[r0]    /* r2 has the new LockDispatcher Value */

    /* restore the OsContext */
    pop     {r1}
    add     r0,r10, #OsCtrlParamTypeCurrentContextOffset
    strh    r1,[r0]
    
    /* from hereon:
       pActiveObjRef-> Active Object before this ISR
       pLastObjRef-> This ISR Object
       Check if we are in a nested interrupt sequence 
    */
    cmp     lr,#0xFFFFFFF1
    beq     osPrvCat2ExitNoDispatch

    /* if we reach here: (No nested Interrupt occured and LockDispatcher is decremented and stored to r2)
       r10 = OsCtrlParam
       r2  = LockDispatcher
    */
    cmp     r2,#0                       /* Check if LockDispatcher = 0 */
    bne     osPrvCat2ExitNoDispatch     /* anything other than 0 means dispatcher is locked, jump to osPrvCat2ExitNoDispatch */
    
    ldrb    r0,[r10, #OsCtrlParamTypeRequestSchedulerOffset]
    cmp     r0,#0
    beq     osPrvCat2ExitNoDispatch    /* Request Scheduler NotSet, jump to osPrvCat2ExitNoDispatch */


    /* we reach here only if RequestScheduler==0 && LockDispatcher==0 */
    ldrb    r10,[r10, #OsCtrlParamTypeActiveTaskIndexOffset]
    cmp     r10,#INVALID_TASK
    beq     osPrvFromInActiveTask                /* we do not have a valid ActiveTask */
    b       osPrvDispatcherContextPushed         /* we reach here to suspend the ActiveTask */


osPrvCat2ExitNoDispatch:
    /* we will reach here if dispatch is not required
       return from interrupt normally
    */
    .if osdFPUSupport == 1
        vpop   {d0-d15}
        pop    {r0}
        vmrs   r0, FPEXC
        pop    {r0}
        vmrs   r0, FPSCR
    .endif
    /*
    we are free to use r0 to r3 as these reg will be pushed/poped during exception entry/return
    Check if we came here from an interrupt context
    If yes, we have to jump back to Handler Mode and serve the pending work
    Probably we have to jump to Thread Mode when we are not from an interrupt context
    */
    ldr     r1, OsCtrlParamAddr
    mov     r0,#0
    add     r0,r1,#OsCtrlParamTypeCurrentContextOffset
    ldrb    r1,[r0]

    /* We have updated the active Obj
       Now, switch MPU so that we Restore the ActiveObj Memory protection settings
    */
    /* bl      OsMemProt_MpuSwitch */
    
    ldmfd  sp!, {r0-r9,r11,r12,lr}       /* restore all registers */
    ldmfd  sp!, {r10}
    rfefd  sp!                           /* return from interrupt */

/******************************************************************************
* osPrvDispatcher 
******************************************************************************/
    .global osSVCHandlerAsm
    .type osSVCHandlerAsm,%function
osSVCHandlerAsm:
    cmp r4,#0
    beq osDispatchApi
    cmp r4,#1
    beq osTrapEntryAsm
    cmp r4,#2
    beq osTrapExitAsm
    cmp r4,#3
    beq osSetPrivilegeModeAsm
    cmp r4,#4
    beq osExitPrivilegeModeAsm
    movs pc,lr
    /* movs pc,R14_SVC */

/******************************************************************************
* osTrapEntryAsm 
******************************************************************************/
    .global osTrapEntryAsm
    .type osTrapEntryAsm,%function
osTrapEntryAsm:

    srsfd   sp!, #osSysMode        /* push SPSRsvc=CPSRsys and LRsvc=PCsys on task stack       */
    cps     #osSysMode             /* change to SystemMode (restores Task Stack Pointer SPsys) */
    
    ldr     r3, [sp, #4]           /* load the saved spsr value during svc entry */
    and     r3, r3, #0xE0          /* Mask to retain I,F,T bit from the saved SPSR during exception entry */
    orr     r3, r3, #0x0000001F    /* Set mode bits to system mode (0x1F) to service trap call */
    push    {r3}                   /* Push modified cpsr */
    ldr     r3,=OsHal_TrapHandler
    push    {r3}                   /* Push PC to service Trap Handler */
    ldr     lr,=OsHal_ExitTrap     /* Update LR with Exit Trap address */
    rfefd sp!                      /* Return from exception to execute trap */ 

/******************************************************************************
* osTrapExitAsm 
******************************************************************************/
    .global osTrapExitAsm
    .type osTrapExitAsm,%function
osTrapExitAsm:
    srsfd   sp!, #osSysMode          /* push SPSRsvc=CPSRsys and LRsvc=PCsys on task stack       */
    cps     #osSysMode              /* change to SystemMode (restores Task Stack Pointer SPsys) */

    add sp, sp, #8        /* Offset added to skip exit privilege exception frame */

    ldr r2, OsCtrlParamAddr          /* r2 = OsCtrlParam */
    ldrb    r3, [r2, #OsCtrlParamTypeLockDispatcherOffset]    /* r3  = LockDispatcher */
    cmp     r3,#0                       /* Check if LockDispatcher = 0 */
    bne     osTrapExitNoDispatch        /* anything other than 0 means dispatcher is locked, jump to osTrapExitNoDispatch */
    
    ldrb    r3, [r2, #OsCtrlParamTypeRequestSchedulerOffset]    /* r3  = RequestScheduler */
    cmp     r3,#0
    beq     osTrapExitNoDispatch     /* Request Scheduler NotSet, jump to osTrapExitNoDispatch */

    /* we reach here only if RequestScheduler!=0 && LockDispatcher==0 */
    push    {r10}                   /* r10 pushed to have same order during pop */
    ldrb    r10,[r2, #OsCtrlParamTypeActiveTaskIndexOffset]
    cmp     r10,#INVALID_TASK
    beq     osPrvFromInActiveTask                   /* we do not have a valid ActiveTask */
    stmfd   sp!, {r0-r9,r11,r12,lr}          /* push to caller stack */
    .if osdFPUSupport == 1
        vmrs   r0, FPSCR
        push   {r0}
        vmrs   r0, FPEXC
        push   {r0}
        vpush  {d0-d15}
    .endif
    b       osPrvDispatcherContextPushed            /* we reach here to suspend the ActiveTask */

/******************************************************************************
* osTrapExitNoDispatch 
******************************************************************************/
    .global osTrapExitNoDispatch
    .type osTrapExitNoDispatch,%function
osTrapExitNoDispatch:
    ldr r2, OsCtrlParamAddr          /* r2 = OsCtrlParam */
    ldrb    r3,[r2, #OsCtrlParamTypeIntSaveDisableRequestCounterOffset]       /* r3  = IntSaveDisableRequestCounter */
    cmp    r3,#0
    beq    EnableIrqExit
    b      DisableIrqExit
    rfefd sp! /* Return from exception */

EnableIrqExit:
    ldr     r3, [sp, #4]           /* load pushed CPSR value from stack */
    and     r3, r3, #0xFFFFFF7F    /* Mask to clear the Irq bit to Enable Interrupts */
    str     r3, [sp, #4]           /* Store modifed CPSR value to stack */
    rfefd   sp!                    /* Return from exception */

DisableIrqExit:
    ldr     r3, [sp, #4]           /* load pushed CPSR value from stack */
    orr     r3, r3, #0x80          /* Mask to set the Irq bit to Disable Interrupts */
    str     r3, [sp, #4]           /* Store modifed CPSR value to stack */
    rfefd   sp!                    /* Return from exception */

/******************************************************************************
* osDispatchAsm 
******************************************************************************/
    .global osDispatchAsm
    .type osDispatchAsm,%function
osDispatchAsm:
   stmfd      sp!,{r4,r8,r10,lr}   /* push to caller stack */
   mov        r4, #0
   svc #0
   ldmfd      sp!,{r4,r8,r10,lr}
   BX         lr

/******************************************************************************
* OsHal_ExitTrap 
******************************************************************************/
    .global OsHal_ExitTrap
    .type OsHal_ExitTrap,%function
OsHal_ExitTrap:
   mov  r4, #2
   svc #2    /* Call to exit trap */
   BX  lr

/******************************************************************************
* osSetPrivilegeModeAsm 
******************************************************************************/
    .global osSetPrivilegeModeAsm
    .type osSetPrivilegeModeAsm,%function
osSetPrivilegeModeAsm:

    srsfd   sp!, #osSysMode        /* push SPSRsvc=CPSRsys and LRsvc=PCsys on task stack       */
    cps     #osSysMode             /* change to SystemMode (restores Task Stack Pointer SPsys) */
    ldr     r4, [sp, #4]           /* load pushed CPSR value from stack */
    orr     r4, r4, #0x1F          /* Set Arm mode bits to system mode (0x1F) */
    str     r4, [sp, #4]           /* Store modifed CPSR value to stack */
    rfefd   sp!                    /* Return from exception after switching to System mode */

/******************************************************************************
* osExitPrivilegeModeAsm 
******************************************************************************/
    .global osExitPrivilegeModeAsm
    .type osExitPrivilegeModeAsm,%function
osExitPrivilegeModeAsm:

    srsfd   sp!, #osSysMode        /* push SPSRsvc=CPSRsys and LRsvc=PCsys on task stack       */
    cps     #osSysMode             /* change to SystemMode (restores Task Stack Pointer SPsys) */
    ldr     r4, [sp, #4]           /* load pushed CPSR value from stack */
    bic     r4, r4, #0x1F          /* Clear the Mode bits */
    orr     r4, r4, #0x10          /* Set Arm mode bits to User mode (0x10) */
    str     r4, [sp, #4]           /* Store modifed CPSR value to stack */
    rfefd   sp!                    /* Return from exception after switching to User mode */

/******************************************************************************
* osGetCONTROL 
******************************************************************************/
    .global osGetCONTROL
    .type osGetCONTROL,%function
osGetCONTROL:
    BX         lr

/******************************************************************************
* void osMpuEnableAsm(void) 
******************************************************************************/
        .global osMpuEnableAsm
        .type osMpuEnableAsm,%function
osMpuEnableAsm:
        mrc     p15, #0, r0, c1, c0, #0  /* read SCTLR register */
        orr     r0, r0, #0x1             /* set bit 0 in r0 */
        dsb
        mcr     p15, #0, r0, c1, c0, #0  /* MPU enabled (bit 0 = 1) */
        isb                              /* flush instruction pipeline */
        bx      LR

/******************************************************************************
* void osMpuDisableAsm(void) 
******************************************************************************/
        .global osMpuDisableAsm
        .type osMpuDisableAsm,%function
osMpuDisableAsm:
        mrc     p15, #0, r0, c1, c0, #0  /* read SCTLR register */
        bic     r0, r0, #0x1             /* clear bit 0 in r0 */
        dsb
        mcr     p15, #0, r0, c1, c0, #0  /* MPU disabled (bit 0 = 0) */
        isb                              /* flush instruction pipeline */
        bx      LR

/******************************************************************************
* void osMpuEnableBRAsm(void) 
******************************************************************************/
        .global osMpuEnableBRAsm
        .type osMpuEnableBRAsm,%function
osMpuEnableBRAsm:
        mrc     p15, #0, r0, c1, c0, #0  /* read SCTLR register */
        orr     r0, r0, #0x20000         /* set bit 17 in r0 */
        mcr     p15, #0, r0, c1, c0, #0  /* background region enabled */
        bx      LR

/******************************************************************************
* void osMpuDisableBRAsm(void) 
******************************************************************************/
        .global osMpuDisableBRAsm
        .type osMpuDisableBRAsm,%function
osMpuDisableBRAsm:
        mrc     p15, #0, r0, c1, c0, #0  /* read SCTLR register */
        bic     r0, r0, #0x20000         /* clear bit 17 in r0 */
        mcr     p15, #0, r0, c1, c0, #0  /* disable background region */
        bx      LR

/******************************************************************************
* void osMpuIsEnabledAsm(void) 
******************************************************************************/
        .global osMpuIsEnabledAsm
        .type osMpuIsEnabledAsm,%function
osMpuIsEnabledAsm:
        mov     r0, #0
        mrc     p15, #0, r1, c1, c0, #0  /* read SCTLR register to r1 */
        tst     r1, #0x1                 /* test bit 0 */
        movne   r0, #1                   /* if not 0, MPU is enabled */
        bx      LR

/******************************************************************************
* void osMpuSetRegionAsm(
*                osuint32 regionId, osuint32 regionBaseAddr, 
*                osuint32 sizeAndEnble, osuint32 regionAttrs)
* r0 = regionId
* r1 = regionBaseAddr
* r2 = sizeAndEnable
* r3 = regionAttrs
******************************************************************************/
        .global osMpuSetRegionAsm
        .type osMpuSetRegionAsm,%function
osMpuSetRegionAsm:
        mcr     p15, #0, r0, c6, c2, #0  /* select MPU region */
        mcr     p15, #0, r1, c6, c1, #0  /* set region base address */
        mcr     p15, #0, r3, c6, c1, #4  /* set protection attributes */
        mcr     p15, #0, r2, c6, c1, #2  /* set region size and enable it */
        bx      LR

/******************************************************************************
* osuint32 osMpuGetMpuTypeAsm(void) 
******************************************************************************/
        .global osMpuGetMpuTypeAsm
        .type osMpuGetMpuTypeAsm,%function
osMpuGetMpuTypeAsm:
        MRC     p15, #0, r0, c0, c0, #4  /* Read MPUIR */
        bx      LR

/******************************************************************************
* void osMpuRegionDisableAsm(osuint8 RegionId, osuint32 RegionDisableValue) 
******************************************************************************/
        .global osMpuRegionDisableAsm
        .type osMpuRegionDisableAsm,%function
osMpuRegionDisableAsm:
        mcr     p15, #0, r0, c6, c2, #0  /* select MPU region */
        mcr     p15, #0, r1, c6, c1, #2  /* set region size and enable it */
        bx      LR

/******************************************************************************
*   Get Data Fault Status Register (DFSR) value
******************************************************************************/
    .global osGetDFSR
    .type osGetDFSR,%function
osGetDFSR:
    MRC p15, #0, r0, c5, c0, #0
    BX      lr

/******************************************************************************
*   Get Data Fault Address Register (DFAR) value
******************************************************************************/
    .global osGetDFAR
    .type osGetDFAR,%function
osGetDFAR:
    MRC p15, #0, r0, c6, c0, #0
    BX      lr

/******************************************************************************
*   Get Instruction Fault Status Register Register (IFSR) value
******************************************************************************/
    .global osGetIFSR
    .type osGetIFSR,%function
osGetIFSR:
    MRC p15, #0, r0, c5, c0, #1
    BX      lr

/******************************************************************************
*   Get Instruction Fault Address Register Register (IFAR) value
******************************************************************************/
    .global osGetIFAR
    .type osGetIFAR,%function
osGetIFAR:
    MRC p15, #0, r0, c6, c0, #2
    BX      lr

/******************************************************************************
*   Data Abort Exception Handler
******************************************************************************/
    .global osDataAbortHandler
    .type osDataAbortHandler,%function
osDataAbortHandler:
    ldr    r13, =ProtErrorInfo      /* Load ProtErrorInfo Address */
    add    r13, #8                  /* r13->osfaultframe */
    str    lr, [r13, #4]            /* osfaultframe.lr = LRabort */
    str    r0, [r13, #0x1C]            /* osfaultframe.r0 = r0 */
    str    r1, [r13, #0x20]            /* osfaultframe.r1 = r1 */
    str    r2, [r13, #0x24]            /* osfaultframe.r2 = r2 */
    str    r3, [r13, #0x28]            /* osfaultframe.r3 = r3 */
    str    r12, [r13, #0x2C]           /* osfaultframe.r12 = r12 */
    mrs    r0, spsr
    str    r0, [r13, #8]            /* osfaultframe.spsr = SPSRabort */
    mov    r0, #0x1                 /* Move r0 with 0x1 value */
    str    r0, [r13, #0x14]        /* osfaultframe.FaultExcMode = 0x1(Data Abort) */
    ldr    r0, [r13, #4]            /* r0 = osfaultframe.lr */
    sub    r0, r0, #8              /* Get Fault instruction address LR minus 8 */
    str    r0, [r13]                /* osfaultframe.FaultInstructionAddr = r0 */
    b    Fault_Handler
    bx lr

/******************************************************************************
*   Prefetch Abort Exception Handler
******************************************************************************/
    .global osMemProtectionFault
    .type osMemProtectionFault,%function
osMemProtectionFault:
    ldr    r13, =ProtErrorInfo      /* Load ProtErrorInfo Address */
    add    r13, #8                  /* r13->osfaultframe */
    str    lr, [r13, #4]            /* osfaultframe.lr = LRabort */
    str    r0, [r13, #0x1C]            /* osfaultframe.r0 = r0 */
    str    r1, [r13, #0x20]            /* osfaultframe.r1 = r1 */
    str    r2, [r13, #0x24]            /* osfaultframe.r2 = r2 */
    str    r3, [r13, #0x28]            /* osfaultframe.r3 = r3 */
    str    r12, [r13, #0x2C]           /* osfaultframe.r12 = r12 */
    mrs    r0, spsr
    str    r0, [r13, #8]            /* osfaultframe.spsr = SPSRabort */
    mov    r0, #0x2                 /* Move r0 with 0x2 value */
    str    r0, [r13, #0x14]        /* osfaultframe.FaultExcMode = 0x2(Prefetch Abort) */
    ldr    r0, [r13, #4]            /* r0 = osfaultframe.lr */
    sub    r0, r0, #4              /* Get Fault instruction address LR minus 4*/
    str    r0, [r13]                /* osfaultframe.FaultInstructionAddr = r0 */
    b    Fault_Handler
    bx lr


/******************************************************************************
*   Undefined Instruction Exception Handler
******************************************************************************/
    .global osUndefinedInstructionException
    .type osUndefinedInstructionException,%function
osUndefinedInstructionException:
    ldr    r13, =ProtErrorInfo      /* Load ProtErrorInfo Address */
    add    r13, #8                  /* r13->osfaultframe */
    str    lr, [r13, #4]            /* osfaultframe.lr = LRundef */
    str    r0, [r13, #0x1C]            /* osfaultframe.r0 = r0 */
    str    r1, [r13, #0x20]            /* osfaultframe.r1 = r1 */
    str    r2, [r13, #0x24]            /* osfaultframe.r2 = r2 */
    str    r3, [r13, #0x28]            /* osfaultframe.r3 = r3 */
    str    r12, [r13, #0x2C]           /* osfaultframe.r12 = r12 */
    mrs    r0, spsr
    str    r0, [r13, #8]            /* osfaultframe.spsr = SPSRundef */
    mov    r0, #0x4                 /* Move r0 with 0x4 value */
    str    r0, [r13, #0x14]        /* osfaultframe.FaultExcMode = 0x4(Undefined) */
    ldr    r0, [r13, #4]            /* r0 = osfaultframe.lr */
    sub    r0, r0, #2              /* If Thumb mode then fault address will be LR minus 2 */
    ldr    r1, [r13, #8]            /* r1 = osfaultframe.spsr */
    ands   r2, r1, #0x20           /* Check whether thumb or arm mode */
    subne  r0, r0, #2              /* If Arm mode then fault address will be LR minus 4 */
    str    r0, [r13]                /* osfaultframe.FaultInstructionAddr = r0 */
    b    Fault_Handler
    bx lr


Fault_Handler:
    ldr     r12,=OsCtrlParam
    ldr     r12,[r12,#OsCtrlParamTypepActiveObjRefOffset]
    ldrb    r12,[r12,#4]     /* now r12 = ActiveObj CoreId */
    ldr     r1,=OsCoreRefConfig
    mov     r2,#4         /* sizeof(OsCoreConfigRefType) */
    mla     r3,r12,r2,r1    /* r3 = (r12 * r2) + r1 => r3 = &OsCoreRefConfig[ActiveObjCoreId] */
    ldr     r3,[r3]                                           /* r3 = OsCoreConfig of Active Obj Core Id */
    ldr     r0,[r3,#0x0C]  /* r3 = OsCoreConfig[ActiveCore]->pOsCoreObjRef */
    /* switch stack pointer */
    ldr    r1, [r0, #OsObjConfigTypeStackStartAddressOffset]   /* Load StackStartAddress */
    ldr    r2, [r0, #OsObjConfigTypeStackSizeOffset]   /* Load StackSize */
    add    r3, r1, r2       /* Get the Stack pointer address to be loaded */
    /* Register r1 will be modified below */
    OS_CPU_HAL_ASM_SWITCH_STACK r0, r3
    stmfd sp!,{r4-r11,lr} /* push registers */
    blx  OsFaultHandler   /* Call FaultHandler */
    ldmfd sp!,{r4-r11,lr} /* pop registers */
    ldr     r0,=OsCtrlParam
    ldr     r0,[r0,#OsCtrlParamTypepActiveObjRefOffset]
    .if osdMPUProtection == 1
        /* Switch Mpu setting for Active Task */
        ldr    r1, =osdMPUStackRegNum    /* Load MPU region number for stack into r1 */
        mcr    p15, #0, r1, c6, c2, #0             /* select MPU region */
        mov    r1, #0
        mcr    p15, #0, r1, c6, c1, #2             /* Region disabled */
        /* Load StackStartAddress into R1 */
        ldr    r1, [r0, #OsObjConfigTypeStackStartAddressOffset]
        mcr    p15, #0, r1, c6, c1, #0             /* set region base address */
        /* Load StackRegAttribute into R1 */
        ldr    r1, [r0, #OsObjConfigTypeStackRegAttributeOffset]
        mcr    p15, #0, r1, c6, c1, #4            /* set protection attributes */
        /* Load StackRegnSizeAndEnable into r1 */
        ldr    r1, [r0, #OsObjConfigTypeStackRegnSizeAndEnableOffset]
        mcr    p15, #0, r1, c6, c1, #2             /* set region size and enable bit */
    .endif
    ldr     r12, =ProtErrorInfo      /* Load ProtErrorInfo Address */
    add     r12, #8                  /* r12->osfaultframe */
    ldr    lr, [r12, #4]               /* lr = osfaultframe.lr */
    ldr    r0, [r12, #0x1C]            /* r0 = osfaultframe.r0 */
    ldr    r1, [r12, #0x20]            /* r1 = osfaultframe.r1 */
    ldr    r2, [r12, #0x24]            /* r2 = osfaultframe.r2 */
    ldr    r3, [r12, #0x28]            /* r3 = osfaultframe.r3 */
    ldr    r12, [r12, #0x2C]           /* r12 = osfaultframe.r12 */
    movs   pc, lr    /* Return by skipping the fault instruction with the lr stored during exception entry */


/******************************************************************************
* CONSTANTS USED BY THIS MODULE
******************************************************************************/
OsSYSStackAddr:                 .long    OsSYSStack
osStartOSAddr:                  .long    osStartOS
OsCtrlParamAddr:                .long    OsCtrlParam
osIntSPAddr:                    .long    osIntSP
osIsrIdTableAddr:               .long    osIsrIdTable
IsrStackConfigAddr:             .long    IsrStackConfig
OsFIQStackAddr:                 .long    OsFIQStack
OsIRQStackAddr:                 .long    OsIRQStack
TcbTaskRefConfigAddr:           .long    TcbTaskRefConfig
osMissingTerminateErrorAddr:    .long    osMissingTerminateError
osCat2ISRExitASMAddr:           .long    osCat2ISRExitASM
osPrvLastLRAddr:                .long    osPrvLastLR



/******************************************************************************
* UNDEFINED REFERENCES
******************************************************************************/
    .global OsSYSStack
    .global OsCtrlParam
    .global osIsrIdTable
    .global OsIRQStack
    .global OsFIQStack
    .global TcbTaskRefConfig
    .global osIntSP
    .global IsrStackConfig
    .global osStartOS
    .global osPrvLastLR
    .global ProtErrorInfo
    .global osTaskStartHook
    .global osTaskStopHook
    .global osMissingTerminateError
    .global OsPrvGetDynApp
    .global OsPrvSetIsrActiveParam
    .global OsCheckIntDisEnPair
    .global OsPrvSetActiveParam
    .global OsPrvSetDynApp
    .global OsMemProt_MpuSwitch
    .global OsMemProt_MpuSwitchFromISR
    .global OsPrvSetTaskActiveParam
    .global osDataAbortHandler
    .global osMemProtectionFault
    .global osUndefinedInstructionException

    .end
