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
* Some Definitions
*****************************************************************************/

    .set    osUserMode                         ,0b10000
    .set    osFIQMode                          ,0b10001
    .set    osIRQMode                          ,0b10010
    .set    osSVCMode                          ,0b10011
    .set    osAbortMode                        ,0b10111
    .set    osUndefMode                        ,0b11011
    .set    osSysMode                          ,0b11111
    .set    osModeMask                         ,0b11111

    .set    osdIntCfgMaxSystemPriority         ,0x20
    .set    osdIntCfgKernelPriority            ,0x80

    .set    osdNumberOfServices                ,66

    .set    osIFlag                            ,0b10000000

    .set    osdTaskStartCPSR_Usr               ,0b0000010000
    .set    osdTaskStartCPSR_Sys               ,0b0000011111

    .set    osdNoActiveTask                    ,0xffffffff
    .set    osdInvalidIsrID                    ,0xffffffff
    .set    osdORTINoService                   ,0

    .set    PRE_READY                          ,0
    .set    RUNNING                            ,1
    .set    READY                              ,3

    .set    STANDARD_STATUS                    ,0
    .set    EXTENDED_STATUS                    ,1

    .set    osdPICMode                         ,0

    .set    osdCtxTask                         ,0x0001
    .set    osdCtxISRCat2                      ,0x0002
    .set    osdCtxPreTaskHook                  ,0x0004
    .set    osdCtxPostTaskHook                 ,0x0008
    .set    osdCtxErrorHook                    ,0x0010
    .set    osdCtxApplErrorHook                ,0x0020
    .set    osdCtxEachErrorHook                ,0x0030
    .set    osdCtxStartupHook                  ,0x0040
    .set    osdCtxShutdownHook                 ,0x0080
    .set    osdCtxProtectionHook               ,0x0100
    .set    osdCtxCOMErrorHook                 ,0x0200
    .set    osdCtxCOMCallback                  ,0x0400
    .set    osdCtxStartComExtens               ,0x0800
    .set    osdCtxErrorHookFromStartupHook     ,0x1000

    .set    osdStackWindowAccessRights         ,0x0000130b

    .set    osIRQ_BASE                         ,0xb040
    .set    osIRQ0_IRQHC                       ,0x0c48
    .set    osIRQ0_CSR                         ,0x0c98
    .set    osIRQ0_UNLOCK                      ,0x0d30
    .set    osIRQ0_IRQR0                       ,0x0b00

    .set    osdIRQ_UnlockValueTop              ,0x17AC
    .set    osdIRQ_UnlockValueBot              ,0xC911
    .set    osdIRQ_LockValueTop                ,0x17B1
    .set    osdIRQ_LockValueBot                ,0x0C11
    .set    osdIRQ_CSR_EnableBit               ,1

    .set    E_OS_DISABLEDINT                   ,12
    .set    E_OS_STACKFAULT                    ,13
    .set    E_OS_SYS_ASSERTION                 ,20
    .set    E_OS_SYS_ABORT                     ,21
    .set    osdErrSYReturnFromNoISR            ,0xA402
    .set    osdErrIXIntAPIDisabled             ,0x2302
    .set    osdErrDPStartValidContext          ,0xA501
    .set    osdErrDPResumeInvalidContext       ,0xA502
    .set    osdErrNTNotEnoughStack             ,0xA601
    .set    osdErrNTReturnFromNoNTF            ,0xA602

    .set    osdMB9DF126                        ,0
    .set    osdMB9DF125                        ,1
    .set    osdMB9EF226                        ,2
    .set    osdS6J32xx                         ,3

    .set    INVALID_TASK                       ,0xFF
    .set    INVALID_PRIORITY                   ,0xFF

    .set    TASK_NONPREEMPTIVE                 ,0
    .set    TASK_PREEMPTIVE                    ,1

    .set    osSizeOfTaskParamStructure         ,16
    .set    osSizeOfTcbConfigStructure         ,12

    .set    osHandlesAllIsr                    ,0

    .set    osdStackCheckPattern               ,0xaaaaaaaa
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
/*****************************************************************************
* EOF
*****************************************************************************/







































