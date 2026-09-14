/*****************************************************************************
*
*                CONFIDENTIAL VISTEON CORPORATION                        
*                                                                        
*   This is an unpublished work of authorship, which contains trade      
*   secrets, created in 2025. Visteon Corporation owns all rights to     
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
*   Description: Assembler functions for mOS ARM Cortex M0P (CLANG compiler)
*
*
*****************************************************************************/

/*****************************************************************************
* File settings
*****************************************************************************/
    .section ".OsCode","ax"
    .thumb


/*****************************************************************************
* Includes
*****************************************************************************/
    .include "OsAsm.inc"
    .include "OsCoreDefine.inc"

/*****************************************************************************
* Symbol export
*****************************************************************************/
    .global osStartOSasmArm
    .global osDispatchAsm
    .global osDispatchApi
    .global osSetupExceptionStacks
    .global osEnableNMIandAborts
    .global osGetCPSR
    .global osSuspendInterruptsAsm
    .global osResumeInterruptsAsm
    .global osCat2ISREntryASM
    .global osEnableGlobalInterruptAsm
    .global osDisableGlobalInterruptAsm
    .global osSVCHandlerAsm
    .global osGetPRIMASK

/*****************************************************************************
* Symbol import
*****************************************************************************/
    .global SysTick_Handler
    .global osStartOS
    .global osTimerInterrupt
    .global osIntSP
    .global IsrStackConfig
    .global osPrvLastLR
    .global osMissingTerminateError
    .global OsMemProt_MpuSwitch
    .global OsPrvSetTaskActiveParam
    .global OsPrvSetIsrActiveParam
    .global OsCpuHal_EnableGlobalMPU
    .global OsCpuHal_DisableGlobalMPU
    .global OsMemProt_ClearOSStateCntr

    #ifdef APM_ENABLED
    .warning "Apm cpu load measurement support is enabled"
    .global Apm_CpuLoadMeasurementFunction
    #endif
    .global osTaskStartHook
    .global osTaskStopHook
    .global osTaskResumeHook

/*****************************************************************************
* osStartOSasmArm                                                             
*****************************************************************************/
    .global osStartOSasmArm
    .type osStartOSasmArm,%function
osStartOSasmArm:
    /* ensure that the interupt vector table in not dead-stripped
     Switch to system mode and set the system stack pointer
     all other stack pointers are set it osInitialize() */

    bl      osDisableGlobalInterruptAsm
    
    ldr     r1,=OsSYSStack
    ldr     r0, [r1, #OsStackTypeStartAddrOffset]  
    mov sp,r0     
    
        
    ldr r0, [r1, #OsStackTypeEndAddrOffset]
    mov r1, sp   
    ldr r2, =osdStackCheckPattern
        
osPrvFillLoop:
    stm     r0!,{r2}
    cmp     r1,r0
    bne     osPrvFillLoop

    ldr     r0,=osStartOS
    bx      r0
/* this call never returns */

/*****************************************************************************
* osuint32 osGetCPSR()                                                        
*****************************************************************************/
    .global osGetCPSR
    .type osGetCPSR,%function
osGetCPSR:
   mrs    R0,XPSR
   bx lr

/*****************************************************************************
* osuint32 osGetPRIMASK()                                                     
*****************************************************************************/
    .global osGetPRIMASK
    .type osGetPRIMASK,%function
osGetPRIMASK:
   mrs    R0,PRIMASK
   bx lr

/*****************************************************************************
* osuint32 osSuspendInterruptsAsm()                                           
*****************************************************************************/
    .global osSuspendInterruptsAsm
    .type osSuspendInterruptsAsm,%function
osSuspendInterruptsAsm:
    mrs     r0, primask
    cpsid   i
    bx      lr

/*****************************************************************************
* osResumeInterruptsAsm(osuint32)                                             
*****************************************************************************/
    .global osResumeInterruptsAsm
    .type osResumeInterruptsAsm,%function
osResumeInterruptsAsm:
    msr   primask, r0
    bx    lr

/*****************************************************************************
* osDisableGlobalInterruptAsm                                                
* caution: This service disables the global interrupts and does not save
*          the interrupt status.
*           For Critical Sections use Suspend and Resume services
*****************************************************************************/
    .global osDisableGlobalInterruptAsm
    .type osDisableGlobalInterruptAsm,%function
osDisableGlobalInterruptAsm:
    cpsid   i
    bx      lr

/*****************************************************************************
* osEnableGlobalInterruptAsm                                                
* Caution: This service enables the global interrupts irrespective of the
*           previous interrupt state.
*           For Critical Sections use Suspend and Resume services
*****************************************************************************/
    .global osEnableGlobalInterruptAsm
    .type osEnableGlobalInterruptAsm,%function
osEnableGlobalInterruptAsm:
    cpsie   i
    bx      lr

/*****************************************************************************
* osSetupExceptionStacks 
*****************************************************************************/
/* This function must be called before allowing NMIs and Exceptions */
/* It must be called in System or SVC mode */
/* Since this function is only called by osInitialize, this is ensured: */ 
/* If user calls it before StartOS, then is is in System Mode. */
/* If the StartOS calls it calls, we are in SVC mode */
    .global osSetupExceptionStacks
    .type osSetupExceptionStacks,%function
osSetupExceptionStacks:
    push     {r2}
    push     {r1}
    ldr      r2, #OsStackTypeStartAddrOffset
    ldr      r1,=OsSYSStack
    ldr      r0, [r2,r1]
    mov      sp,r0   
    /* we only use Main Stack Pointer for both application and interrupt mode */
    pop      {r1}
    pop      {r2}
    bx lr

/*****************************************************************************
* osEnableNMIandAborts
*****************************************************************************/
    .global osEnableNMIandAborts
    .type osEnableNMIandAborts,%function
osEnableNMIandAborts:
   bx lr

/*****************************************************************************
* osDispatchAsm
*****************************************************************************/
    .global osPrvDispatchAsm
    .type osPrvDispatchAsm,%function
osPrvDispatchAsm:
   /* we reached here to dispatch a task (may be idle task too) */
    bl osDisableGlobalInterruptAsm
    bl osPrvDispatcher
    bl osEnableGlobalInterruptAsm
    
    bx lr

/*****************************************************************************
* osPrvDispatcher
*****************************************************************************/
osDispatchApi:
osPrvDispatcher:
    
    /*  coming here, we assume that the Dispatcher is Unlocked and Interrupt is always in enable state
        and hence we blindly disable interrupt and enable interrupt on exit of the Dispatcher
        are we coming from an inactive task
        (ossActiveTaskIndex != 0)? osFromActiveTask: osFromInActiveTask */
    cpsid   i                               /* Disable Interrupts to prevent Nesting */
    mrs     r1, control                     /* r1 = control */
    push    {r1-r2}                         /* push control and basepri to stack */
    movs     r2, #0
    msr     control, r2
    push    {r5}    /* register to work with */
    ldr     r5,=OsCtrlParam
    ldrb    r5, [r5, #OsCtrlParamTypeActiveTaskIndexOffset]   /* r5 = ActiveTaskIndex */
    cmp     r5,#INVALID_TASK
    beq     osPrvFromInActiveTask

osPrvComingFromActiveTask:
    push    {lr}
    push    {r0-r4,r6-r7}
    /* Enable the stack Monitoring during contex swtich. May cause MPU violation if MPU is enabled. Should Only be used for SC1 */
    .if osdEnableStackMonitoring == 1
    push  {r0-r7}  /* r0-r7 registers preserved as defensive statergy */
    mov r0, r5
    bl osCheckTaskStackOverflow
    pop  {r0-r7}
    .endif

osPrvDispatcherContextPushed:
    /* save ths SP in TcbTaskRefConfig[ActiveTaskIndex]->TaskParamRef->StackAddress
       The below registers will point to:
       r0 -
       r1 - &TcbTaskRefConfig
       r2 - 
       r3 -&(TcbTaskRefConfig[ActiveTaskIndex]->TaskParamRef->StackAddress)
       r4 -
       r5 - &TcbTaskRefConfig[ActiveTaskIndex]->TaskParamRef */

    ldr     r1,=TcbTaskRefConfig
    movs     r2, #sizeofOsTaskConfigRefType
    muls    r5,r2      
    adds    r5,r5,r1    /* r5 = (r5 * r2) + r1 => r5 = &&TcbTaskRefConfig[ActiveTaskIndex] */
    ldr     r5,[r5]                                            /* r5 = OsTaskConfig of Active Task */
    adds     r5,r5,#OsTaskConfigTypeTaskParamRefOffset     /* r5 = &(TcbTaskRefConfig[ActiveTaskIndex]->TaskParamRef) */
    ldr     r5,[r5]                                           /* r5 = TcbTaskRefConfig[ActiveTaskIndex]->TaskParamRef */
    mov     r3,r5           
    adds     r3,r3, #TaskParamTypeStackAddressOffset      /* = TcbTaskRefConfig[ActiveTaskIndex]->TaskParamRef->StackAddress */
    mov     r2,sp
    str     r2,[r3]
    adds     r5,r5, #TaskParamTypeStateOffset
    ldrb    r3,[r5]
    cmp     r3, #RUNNING
    bne     osPrvFromInActiveTask
    /* Now we have to make the current task to READY state */
    /* call Post Hook Now */
    push    {r0-r7}
    push    {lr}
    bl      osPrvAsmPostTaskHook
    /* call Post Task Hook as the current task gets inactivated */
    pop     {r0}
    mov     lr,r0
    pop     {r0-r7}
    movs     r3, #READY
    strb    r3,[r5]                            /* osState[ossActiveTaskIndex] = READY */
    /* Implicit continuation of execution if the current task was RUNNING */

osPrvFromInActiveTask:
osPrvFromNoTask:
    /* The below registers will point to:
     r0 - &OsCtrlParam
     r1 - &OsCtrlParam.ActiveTaskIndex
     r2 - &OsCtrlParam.RequestedTaskIndex
     r3 - &OsCtrlParam.ActiveTaskPriority
     r4 - &OsCtrlParam.RequestedTaskPriority */
   
    ldr     r0,=OsCtrlParam
    mov     r1,r0
    adds     r1,r1, #OsCtrlParamTypeActiveTaskIndexOffset
    mov     r2,r0
    adds     r2,r2, #OsCtrlParamTypeRequestedTaskIndexOffset
    mov     r3,r0
    adds     r3,r3, #OsCtrlParamTypeActiveTaskPriorityOffset
    mov     r4,r0
    adds     r4,r4, #OsCtrlParamTypeRequestedTaskPriorityOffset
    ldrb    r2,[r2]
    ldrb    r4,[r4]
    strb    r2,[r1]                             /* ActiveTaskIndex    = RequestedTaskIndex */
    strb    r4,[r3]                             /* ActiveTaskPriority = RequestedTaskPriority */
    push    {r0-r7}                             /* Push all registers */
    push    {lr}                                /* preserve linker */
    bl      OsPrvSetTaskActiveParam
    pop     {r1}                                /* pop lr to r1 */
    mov     lr,r1                               /* get linker back */
    pop     {r0-r7}                             /* pop all pushed registers back */
    /* RequestScheduler = 0 */
    /* Now r0 = &OsCtrlParam */
    movs     r4, #0
    movs     r2, #OsCtrlParamTypeRequestSchedulerOffset
    strb    r4,[r0,r2]
    /* do we have a valid task? */
    ldrb    r1,[r1]                             /* now r1 = ActiveTaskIndex */
    cmp     r1,#INVALID_TASK
    beq     osPrvIdleTask                       /* No Active Task, so go Idle */
    
    /* We have a valid task to dispatch
     Now look if we need to Start or Resume */
    ldr      r2,=TcbTaskRefConfig
    movs     r3, #sizeofOsTaskConfigRefType      /* #osSizeOfOsTaskConfigRefType */
    muls     r3,r1                              /* Note: r1 has ActiveTaskIndex */
    adds     r3,r3,r2                           /* r3 = &TcbTaskRefConfig[ActiveTaskIndex] */
    ldr     r3,[r3]                             /* r3 = OsTaskConfig of ActiveTask */
    mov      r5 ,r3                             /* r5 = &TcbTaskRefConfig[ActiveTaskIndex] used in osPrvStartTask */
    adds      r3,r3, #OsTaskConfigTypeTaskCategoryOffset 
    ldrb     r3,[r3]
    mov      r2,r0                              /* r0 holds &OsCtrlParam, copy to r2 for getting LockDispatcher */
    adds      r2,r2, #OsCtrlParamTypeLockDispatcherOffset
    movs      r0,#1
    eors     r3,r0                              /* XOR TcbTaskConfig[ActiveTaskIndex].TaskCategory ^ 1 */
    strb     r3,[r2]                            /* Set LockDispatcher if ActiveTask is Non Preemptive */
    
    /* we have the ActiveTaskIndex still in r1
     and &TcbTaskConfig[ActiveTaskIndex] in r5 */
    ldr     r2,=TcbTaskRefConfig
    movs     r3, #sizeofOsTaskConfigRefType    /* #osSizeOfOsTaskConfigRefType */
    muls    r3,r1                       /* r3=Offset of TcbTaskRefConfig[ActiveTaskIndex] */
    adds     r3,r3,r2                           /* r3 = &TcbTaskRefConfig[ActiveTaskIndex] */
    ldr     r3,[r3]                                           /* r3 = OsTaskConfig of ActiveTask */
    adds     r3,r3, #OsTaskConfigTypeTaskParamRefOffset    /* r3 = &TcbTaskRefConfig[ActiveTaskIndex]->TaskParamRef */
    ldr     r3,[r3]                                           /* r3 = TaskParam of ActiveTask */
    mov     r4,r3                       /* copy r3 to r4 for further manipulations */
   
    ldrb     r3,[r4, #TaskParamTypeStateOffset]
    movs     r6,#RUNNING
    strb    r6,[r4, #TaskParamTypeStateOffset]
    cmp     r3,#PRE_READY
    beq     osPrvStartTask
    /*************************************************/
osPrvResumeTask:
    /*Implicit continuation to Resume the task
    Task already moved to RUNNING State
    Now r4 = &TcbTaskRefConfig[ActiveTaskIndex]->TaskParamRef */
    /* Enable the stack Monitoring during contex swtich. May cause MPU violation if MPU is enabled. Should Only be used for SC1 */
    .if osdEnableStackMonitoring == 1
    push  {r0-r7}  
    mov r0, r1
    bl osCheckTaskStackOverflow
    pop  {r0-r7}
    .endif
    /****** Restore Context ******/
   
    ldr     r5,[r4, #TaskParamTypeStackAddressOffset]
    mov     sp,r5                       /* Restore Tasks Stack Pointer */

    push    {r0-r7}
    push    {lr}
    bl      osTaskResumeHook
    pop     {r0}
    mov     lr, r0
    pop     {r0-r7}

    /*  Now SP points to context pushed registers in below sequence
        R0-R4,R6-R7
        LR
        R5
        R1-R2
        Exception Frame */
    
    pop     {r0-r4,r6-r7}
    pop     {r0}                        /* pop LR to R0 register */
    mov     lr,r0                       /* Restore LR */
    pop     {r5}
    pop     {r1-r2}
    msr     control,r1                  /* Restore Control Register */
    cpsie   i                           /* Enable Global Interrupts */
    bx      lr                          /* Return from exception */

osResumeTaskError:
    bl      osResumeTaskError
    /* not expected to reach here */

    /********** end of Resume Task Routine *********************/

osPrvStartTask:
    /* Task already moved to RUNNING State
    Now r4 = &TcbTaskRefConfig[ActiveTaskIndex]->TaskParamRef
    r5 = &TcbTaskConfig[ActiveTaskIndex] r5 is preloaded with this pointer in Dispatcher flow */

    ldr     r0,=osMissingTerminateError
    mov     lr,r0
    ldr     r0,[r4, #TaskParamTypeStackAddressOffset]
    mov     sp,r0                       /* Initialize SP to new task stack pointer */
    isb                                 /* Barrier sync */
    dsb                                 /* Data Barrier Sync */
    ldr     r0,[r5, #OsTaskConfigTypeTaskStackStartAddressOffset]
    /* we do not need a legal comeback to this place */
    /* leave the LR as corrupted */
    /* switch back to thumb mode if required */
    push    {r0-r7}
    push    {lr}
    bl      osPrvAsmPreTaskHook
    pop     {r7}                        /* pop the LR from stack */
    mov     lr,r7                       /* Restore LR */
    pop     {r0-r7}                     /* pop all general purpose registers */

    /*Construct Exception Return Frame
     -------------------------------
    |             xPSR              |
     -------------------------------
    |        ReturnAddress          |
     -------------------------------
    |             R14               |
     -------------------------------
    |             R12               |
     -------------------------------
    |             R3                |
     -------------------------------
    |             R2                |
     -------------------------------
    |             R1                |
     -------------------------------
    |             R0                |
     ------------------------------- */
    movs     r0,#0x21   
    lsls    r0,r0,#24 
    push    {r0}                        /* xpsr */
    ldr     r0,[r5, #OsTaskConfigTypeTaskStartAddressOffset]
    push    {r0}                        /* push TaskStartAddress */
    push    {r14}                       /* Push osMissingTerminateError */
    push    {r5}                        /* Push dummy value for R12 */
    push    {r0-r3}                     /* Push R0 to R3 */
    /* Reset the control and enable interrupt */
    movs    r0,#0 
    msr     control,r0

    movs     r5,#6                      
    mvns    r5,r5                       
    mov     lr,r5
    cpsie   i
    bx      lr                          /* Return from Exception */

osPrvIdleTask:
    ldr	     r2, #OsStackTypeStartAddrOffset
    ldr      r1,=OsSYSStack
    ldr	     r0,[r2,r1]
    mov      sp,r0
    ldr	     r0,=OsCtrlParam
    adds	     r0,r0, #OsCtrlParamTypeLockDispatcherOffset
    movs	     r1,#0
    strb     r1,[r0]
    /* Reset the control and enable interrupts
    todo - this should be based on a tasks recommended value - from OsTaskConfigType */
    movs      r0,#0
    cpsie    i
    msr      control,r0
    /* Construct the Return from exception stack for Idle Task
     ldr     r14,=osIdleLoop */
    ldr      r0,=osIdleLoop
    mov      r14,r0
    movs      r0,#0x21     
    lsls     r0,r0,#24
    push     {r0}                        /* xpsr */
    ldr      r0,=osIdleLoop
    push     {r0}
    push     {r14}
    push     {r5}
    push     {r0-r3}
    movs      r0,#6
    mvns     r0,r0   
    bx       r0          

osIdleLoop:
    #ifdef APM_ENABLED
    bl     Apm_CpuLoadMeasurementFunction
    #endif
    b       osIdleLoop

osPrvAsmPostTaskHook:
    /* For debug and measurement support */
    mov      r0,r14
    push     {r0-r7}
    bl       osTaskStopHook
    pop      {r0-r7}
    mov      pc,r0

osPrvAsmPreTaskHook:
    mov      r6,r14
    push     {r0-r7} 
    bl       osTaskStartHook
    pop      {r0-r7}
    mov      pc,r6

/******************************************************************************
* osCat2ISREntryASM 
******************************************************************************/
    .global osCat2ISREntryASM
    .type osCat2ISREntryASM,%function
osCat2ISREntryASM:
    /* we get here with user registers r0-r3,r12,sp,lr pushed to interrupted process stack as part of exception frame
    Before entering this call, we are pushing primask and control
    except
    r0     - address of this function
    r1     - Address of the Application Interrupt Routine
    We are free to use r0,r2-r3,r12 pushed by exception frame */
    push    {r5}           /* push the registers r0-r12 and lr to interrupted process stack */
    push    {lr}
    push     {r0-r4,r6-r7}
    
    /* The below registers will point to:
     r0 - scratch Pad
     r1 - Application ISR Routine
     r2 - &OsCtrlParam.pActiveObjRef
     r3 - FREE
     r4 - &OsCtrlParam.LockDispatcher
     r5 - &OsCtrlParam.CurrentContext
     r6 - &OsCtrlParam
     r7 - &OsCtrlParam.ActiveISRId */
    
    ldr      r6,=OsCtrlParam
    mov      r4,r6
    adds      r4,r4, #OsCtrlParamTypeLockDispatcherOffset
    mov      r5,r6
    adds      r5,r5, #OsCtrlParamTypeCurrentContextOffset
    mov      r7,r6
    adds      r7,r7, #OsCtrlParamTypeActiveISRIdOffset
    mov      r2,r6
    adds      r2,r2, #OsCtrlParamTypepActiveObjRefOffset
    /* push the current context into stack */
    ldrb     r0,[r5]
    push     {r0}
    /* set the OsContext as osdCat2IsrContext */
    movs      r0,#osdCtxISRCat2
    strh     r0,[r5]
    /* push the current ObjRef to stack */
    ldr      r0,[r2]
    push     {r0}
    
    /* increment the LockDispatcher */
    ldrb     r0,[r4]
    adds      r0,r0,#1
    strb     r0,[r4]
    /* Update the ActiveISRId */
    movs      r0,#0                  /**************Need to be verified***************/
    str      r0,[r7]
    
    /* We have pushed required members of OsCtrlParam to Task Stack
       Now we are free to use r0,r2-r7
       r1 holds the actual ISR API
       Switch to Interrupt Stack now */
    ldr     r4,=osIntSP
    mov     r6,sp
    str     r6,[r4]                             /* Now osIntSP = Task SP */
    
    /* Update the Active App and Obj references
       We dont need to preserve any registers, let the called function use all registers needed */
    push  {r0-r7}
    bl      OsPrvSetIsrActiveParam              /* OsPrvSetIsrActiveParam(void) */
    pop   {r0-r7}
    /* We have updated the active app and objects
       Now, switch MPU so that we have ISR Memory protection settings */

    /* Now we are free to use r0,r2-r7 */
    ldr     r3,=IsrStackConfig
    ldr     r6,[r3]
    mov	    sp,r6                               /* Now we are at Interrupt Stack */

    push    {lr}
    /* service the application ISR */
    ldr     r4,=osCat2ISRExitASM
    mov     lr,r4

    bx      r1          /* Call the ISR */

/******************************************************************************
* osCat2ISRExitASM 
******************************************************************************/
    .global    osCat2ISRExitASM
    .type osCat2ISRExitASM,%function
osCat2ISRExitASM:
    /* Enable the stack Monitoring during contex swtich. May cause MPU violation if MPU is enabled. Should Only be used for SC1 */
    .if osdEnableStackMonitoring == 1
    push  {r0-r7}  
    movs r0, #0
    bl osCheckISRStackOverflow
    pop  {r0-r7}
    .endif

    pop     {r7}
    mov     lr,r7

    /* Now we are free to use r0-r7 */
    
    /* Getback to the OS Stack */
    ldr     r4,=osIntSP
    ldr	    r6,[r4]
    mov     sp,r6
    
    ldr     r4,=osPrvLastLR
    mov     r6,lr
    str     r6,[r4]
    
    /* Now Stack looks like
       SP    -> pActiveObjRef
       SP+4  -> CurrentContext */

    
    /* restore the previous object */
    pop     {r0}                                /* Now r0 - pActiveObjRef */
    /* Get the ActiveObjRef updated through the C Handlers */
    push    {r0-r7}
    bl      OsPrvSetActiveParam                 /* OsPrvSetActiveParam(pActiveObjRef) */
    pop     {r0-r7}
     
    ldr     r6,=OsCtrlParam
    /* Decrement the LockDispatcher */
    mov     r0,r6
    adds     r0,r0, #OsCtrlParamTypeLockDispatcherOffset
    ldrb    r2,[r0]
    subs    r2,r2,#1                            /* OsCtrlParam.LockDispatcher-- */
    strb    r2,[r0]                             /* r2 has the new LockDispatcher Value */
    /* restore the OsContext */
    pop     {r1}
    /* Now Stack has
       r0-r4,r6-r7
       lr
       r5
       control, primask
       exception frame */
    
    mov     r0,r6
    adds     r0,r0, #OsCtrlParamTypeCurrentContextOffset
    strh    r1,[r0]	  
    /* Check if we are in a nested interrupt sequence
       cmp    lr,#0xFFFFFFF1 */
    movs  r1,#0xE
    mvns  r1,r1
    cmp   lr,r1
    beq     osPrvCat2ExitNoDispatch
    /* if we reach here: (No nested Interrupt occured and LockDispatcher is decremented and stored to r2)
       r6  = OsCtrlParam
       r2  = LockDispatcher */
    cmp     r2,#0                       /* Check if LockDispatcher = 0 */
    bne     osPrvCat2ExitNoDispatch     /* anything other than 0 means dispatcher is locked, jump to osPrvCat2ExitNoDispatch */
    movs     r0, #OsCtrlParamTypeRequestSchedulerOffset  
    ldrb    r0,[r6,r0]
    cmp     r0,#0
    beq     osPrvCat2ExitNoDispatch     /* Request Scheduler NotSet, jump to osPrvCat2ExitNoDispatch */
    /* we reach here only if RequestScheduler==0 && LockDispatcher==0 */
    ldrb    r5,[r6, #OsCtrlParamTypeActiveTaskIndexOffset]
    cmp     r5,#INVALID_TASK
    beq     FromInActiveTask                   /* we do not have a valid ActiveTask */
    b       osPrvDispatcherContextPushed            /* we reach here to suspend the ActiveTask */
    

FromInActiveTask:
    b    osPrvFromInActiveTask

osPrvCat2ExitNoDispatch:
    
    /* we will reach here if dispatch is not required */
    /* return from interrupt normally */
          
    /* we are free to use r0 to r3 as these reg will be pushed/poped during exception entry/return
    Check if we came here from an interrupt context
    If yes, we have to jump back to Handler Mode and serve the pending work
    Probably we have to jump to Thread Mode when we are not from an interrupt context */
    
    pop     {r0-r4,r6-r7}           /* restore all registers */
    pop     {r0}                    /* pop LR to R0 register */
    mov     lr,r0                   /* Restore Linker */
    pop     {r5}
    pop     {r1-r2}
    msr     control,r1
    cpsie   i
    bx      lr    /* Jump to mode from where we came here */

/******************************************************************************
* osPrvDispatcher 
******************************************************************************/
    .global osSVCHandlerAsm
    .type osSVCHandlerAsm,%function
osSVCHandlerAsm:
    b   osDispatchApi
    bx  lr

/******************************************************************************
* osDispatchAsm 
******************************************************************************/
    .global osDispatchAsm
    .type osDispatchAsm,%function
osDispatchAsm:
    cpsie        i
    svc #0    
    bx lr



