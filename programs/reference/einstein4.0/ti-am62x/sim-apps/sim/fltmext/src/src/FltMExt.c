/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2025. Visteon Corporation owns all rights to           *
 * this work and intends to maintain it in confidence to preserve             *
 * its trade secret status. Visteon Corporation reserves the right,           *
 * under the copyright laws of the United States or those of any              *
 * other country that may have jurisdiction, to protect this work             *
 * as an unpublished work, in the event of an inadvertent or                  *
 * deliberate unauthorized publication. Visteon Corporation also              *
 * reserves its rights under all copyright laws to protect this               *
 * work as a published work, when appropriate. Those having access            *
 * to this work may not copy it, use it, modify it or disclose the            *
 * information contained in it without the written authorization              *
 * of Visteon Corporation.                                                    *
 *                                                                            *
 ******************************************************************************/
/*****************************************************************************
 *  File Name         :  FltMExt.c                                            *
 *  Module Short Name :  FltMExt                                               *
 *  Description       :  This file contains implementations of the Fault      *
 *                       Manager Extension Implementation                     *
 *                                                                            *
 * Organization     :  Driver Information Software Section,                   *
 *                     Visteon Software Operation                             *
 *                     Visteon Corporation                                    *
 *                                                                            *
 * ---------------------------------------------------------------------------*
 * Compiler Name    :  CLANG                                                  *
 * Target Hardware  :  Program Dependent                                      *
 *                                                                            *
 ******************************************************************************/
#ifndef FLTMEXT_C
#define FLTMEXT_C
/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
#include "FltMExt.h"
#include "Rte_CFltMExt.h"
#include "RstM.h"
#if(DLTEXT_UART_PRINT == STD_ON)
#include "SciDrv.h"
#endif

/******************************************************************************
 * .............................Global Variables                              *
 ******************************************************************************/
#if (FLTMEXT_VBATT_MONITOR == STD_ON)
static Boolean UnderVoltageFlag;
static Boolean OverVoltageFlag;
#endif

/******************************************************************************
 *                              Macro Definition                              *
 ******************************************************************************/

#define SDL_EXCEPTION_SYNC_PARITY_OR_ECC_ERROR_MASK 		                0x409u
#define SDL_EXCEPTION_ASYNC_PARITY_OR_ECC_ERROR_MASK 		                0x408u

/*****************************************************************************
 *                            Static  Declaration                             *
 ******************************************************************************/
static eFltM_FaultIdType FltMExt_MapProtErrorToFaultId(const ProtectionErrType *ProtectionErr);
static eFltM_FaultIdType FltMExt_MapOsFatalToFltmFaultId(const osErrParamType *pErrParam);
static eFltM_FaultIdType FltMExt_MapService(OsServiceIdType sid);
static eFltM_FaultIdType FltMExt_MapReason(StatusType reason);

/*****************************************************************************
 *                            Function Declaration                          *
 ******************************************************************************/

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_Init
 *  Service ID       : 0x01
 *  Synchronous      : Synchronous
 *  Reentrancy       : Non Reentrant
 *  Context          : Task
 *  Description      : Initializes the FltM Extension module state and
 *                     any SOC/board specific monitors required by FltMExt.
 *  Parameters (in)  : None
 *  Parameters (out) : None
 *  Return value     : void
 *  Preconditions    : System basic init completed; clocks/peripherals ready.
 *  Postconditions   : Module is ready; internal flags reset to defaults.
 *  Notes            : Call once during ECU startup before using other APIs.
 * --------------------------------------------------------------- */

void FltMExt_Init(void)
{

}

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_DeInit
 *  Service ID       : 0x02
 *  Synchronous      : Synchronous
 *  Reentrancy       : Non Reentrant
 *  Context          : Task
 *  Description      : De-initializes the FltM Extension module, releases
 *                     resources and resets internal state.
 *  Parameters (in)  : None
 *  Parameters (out) : None
 *  Return value     : void
 *  Preconditions    : FltMExt_Init has been called.
 *  Postconditions   : Module is stopped; no further processing performed.
 *  Notes            : Typically used during controlled shutdown.
 * --------------------------------------------------------------- */
void FltMExt_DeInit(void)
{

}

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_MainFunction
 *  Service ID       : 0x03
 *  Synchronous      : Synchronous
 *  Reentrancy       : Non Reentrant
 *  Context          : Task (periodic)
 *  Description      : Periodic processing for FltMExt. Polls platform
 *                     health (e.g., VBATT) and reports faults to FltM.
 *  Parameters (in)  : None
 *  Parameters (out) : None
 *  Return value     : void
 *  Preconditions    : FltMExt_Init has been called.
 *  Postconditions   : Faults may be reported to FltM based on sampling.
 *  Notes            : Invoke with a fixed cycle time (e.g., 10�100 ms).
 * --------------------------------------------------------------- */
void FltMExt_MainFunction(void)
{
#if (FLTMEXT_VBATT_MONITOR == STD_ON) 
  {
  uint8 logdata[5] = {0xAA, 0XAA, 0XAA, 0XAA, 0XAA};
    // Implementation of VBATT_MONITOR
    Rte_Read_CFltMExt_rpSR_BattMdl_AVP_LVSD1Flag(&UnderVoltageFlag);
    Rte_Read_CFltMExt_rpSR_BattMdl_AVP_HVSD1Flag(&OverVoltageFlag);

    if (FALSE != UnderVoltageFlag)
    {
      logdata[0] = 0x00;
      FltM_ReportFault(POWER_SUPPLY_FAULT, FLTM_ACTIVE, logdata, 5);
    }
    else if (FALSE != OverVoltageFlag)
    {
      logdata[0] = 0x11;
      FltM_ReportFault(POWER_SUPPLY_FAULT, FLTM_ACTIVE, logdata, 5);
    }
  }
#endif
}

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_InitialSafeAction
 *  Service ID       : 0x04
 *  Synchronous      : Synchronous
 *  Reentrancy       : Reentrant
 *  Context          : Task/ISR2 (implementation dependent)
 *  Description      : Executes the first/initial safe action configured
 *                     for the given FaultId (e.g., limit features).
 *  Parameters (in)  : FaultId  - FltM fault identifier
 *  Parameters (out) : None
 *  Return value     : Std_ReturnType
 *                     E_OK      - Action executed/accepted
 *                     E_NOT_OK  - Action rejected/failed
 *  Preconditions    : FltM has determined the initial action threshold met.
 *  Postconditions   : System may transition to a safer operating mode.
 *  Notes            : Keep execution bounded; avoid blocking calls.
 * --------------------------------------------------------------- */
Std_ReturnType FltMExt_InitialSafeAction (FltM_FaultIdType FaultId)
{
  (void)FaultId;
    // Implementation of initial safe action based on FaultId
    // This is a placeholder; actual implementation will depend on system requirements
    return E_OK; // Assuming E_OK is defined in Std_Types.h for successful operation
}

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_FinalSafeAction
 *  Service ID       : 0x05
 *  Synchronous      : Synchronous
 *  Reentrancy       : Reentrant
 *  Context          : Task/ISR2 (implementation dependent)
 *  Description      : Executes the final safe action configured for the
 *                     given FaultId (e.g., disable outputs, enter safe mode).
 *  Parameters (in)  : FaultId  - FltM fault identifier
 *  Parameters (out) : None
 *  Return value     : Std_ReturnType
 *                     E_OK      - Action executed/accepted
 *                     E_NOT_OK  - Action rejected/failed
 *  Preconditions    : FltM has determined the final action threshold met.
 *  Postconditions   : System transitions to final safe state if applicable.
 *  Notes            : Must be idempotent; avoid unbounded waits.
 * --------------------------------------------------------------- */
Std_ReturnType FltMExt_FinalSafeAction (FltM_FaultIdType FaultId)
{
    (void)FaultId;
    // Implementation of final safe action based on FaultId
    // This is a placeholder; actual implementation will depend on system requirements
    #if(DLTEXT_UART_PRINT == STD_ON)
    uint8 DltExt_Uart_TxBuf[] = "\r\nTaking FailSafe Action";
    (void)SciDrv_DisableChn(DLT_UART_CH);
    (void)SciDrv_SetAsyncMode(DLT_UART_CH, eSciDrvAsyncMode_Polling);
    (void)SciDrv_EnableChn(DLT_UART_CH);
    (void)SciDrv_SetupEB(DLT_UART_CH, \
                        eSciDrvDirection_Transmit, (uint8 *)DltExt_Uart_TxBuf, (eFltM_FaultIdType)sizeof(DltExt_Uart_TxBuf));
    (void)SciDrv_SyncTransmit(DLT_UART_CH);
    #endif

    while(1U)
    {
      // Simulate a halt or safe state
    } 
    return E_OK; // Assuming E_OK is defined in Std_Types.h for successful operation
}

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_UserProtectionHook
 *  Service ID       : 0x06
 *  Synchronous      : Synchronous
 *  Reentrancy       : Non Reentrant
 *  Context          : Exception/ISR2 (OS Protection Hook)
 *  Description      : SOC-specific handler invoked by the OS Protection Hook.
 *                     Maps the protection error to a FltM FaultId, stages a
 *                     minimal CPU dump (ProtErrorInfoType) via RstM, and
 *                     reports the fault to FltM for policy (fatal vs. log).
 *  Parameters (in)  : errInfo  - ProtectionErrType captured by OS
 *  Parameters (out) : None
 *  Return value     : uint8
 *                     PRO_IGNORE   - RstM/FltM will own escalation/reset
 *                     PRO_SHUTDOWN - Request OS shutdown (not typical here)
 *  Preconditions    : Called by OS via OS_PROTECTION_HOOK macro chain.
 *  Postconditions   : If configured fatal, FltM triggers RstM reset.
 *  Notes            : Keep execution minimal; no blocking; pointer/lifetime
 *                     safe because errInfo is passed by value (copied here).
 * --------------------------------------------------------------- */
/* Called from OS_PROTECTION_HOOK (UserProtectionHook) */

ProtectionRetType FltMExt_UserProtectionHook(ProtectionErrType errInfo)
{
  // ProtectionRetType RetVal = PRO_IGNORE;
  // eFltM_FaultIdType fid = FltMExt_MapProtErrorToFaultId(&errInfo);
  // uint32 dfsrValue = errInfo.os_faultFrame.DFSR;
  // uint32 ifsrValue = errInfo.os_faultFrame.IFSR;
  // uint32 Faultaddress = errInfo.os_faultFrame.FaultInstructionAddr;
  // uint8 logdata[5] = {0xAAU, 0xAAU, 0XAAU, 0XAAU, 0XAAU};

  // if ((errInfo.os_faultFrame.IFSR != 0U) &&
      // (errInfo.os_faultFrame.DFSR == 0U))
  // {
    // if (fid != 0xFFFFU)
    // {
      // (void)RstM_StageOsArmDump(fid, &errInfo.os_faultFrame, (eFltM_FaultIdType)sizeof(errInfo.os_faultFrame));
      // logdata[0] = (uint8)(((ifsrValue & 0x0FU) >> 0U) | ((ifsrValue & 0x400U) >> 6U));
      // logdata[1] = (uint8)((ifsrValue & (1U << 12U)) >> 12U);
      // (void)FltM_ReportFault(fid, FLTM_ACTIVE, logdata, 5U);
    // }
    // RetVal = PRO_IGNORE;
  // }
  // else if ((errInfo.os_faultFrame.DFSR != 0U) &&
           // (errInfo.os_faultFrame.IFSR == 0U))
  // {
    // if (fid != 0xFFFFU)
    // {
      // (void)RstM_StageOsArmDump(fid, &errInfo.os_faultFrame, (eFltM_FaultIdType)sizeof(errInfo.os_faultFrame));
      // logdata[0] = (uint8)((dfsrValue & 0xFU) >> 0U) | ((dfsrValue & 0x400U) >> 6U);
      // logdata[1] = (uint8)(dfsrValue & (1U << 11U)) >> 11U;
      // logdata[2] = (uint8)(dfsrValue & (1U << 12U)) >> 12U;
      // logdata[3] = (uint8)(dfsrValue & 0xF0U) >> 4U;
      // (void)FltM_ReportFault(fid, FLTM_ACTIVE, logdata, 5U);
    // }
    // RetVal = PRO_IGNORE;
  // }
  // else if ((errInfo.os_faultFrame.DFSR == 0U) &&
           // (errInfo.os_faultFrame.IFSR == 0U))
  // {
    // if (fid != 0xFFFFU)
    // {
      // (void)RstM_StageOsArmDump(fid, &errInfo.os_faultFrame, (eFltM_FaultIdType)sizeof(errInfo.os_faultFrame));
      // Faultaddress = errInfo.os_faultFrame.FaultInstructionAddr;
      // logdata[0] = errInfo.CallingTask;
      // logdata[1] = (uint8)((Faultaddress >> 24U) & 0xFFU);
      // logdata[2] = (uint8)((Faultaddress >> 16U) & 0xFFU);
      // logdata[3] = (uint8)((Faultaddress >> 8U) & 0xFFU);
      // logdata[4] = (uint8)(Faultaddress & 0xFFU);
      // (void)FltM_ReportFault(fid, FLTM_ACTIVE, logdata, 5U);
    // }
    // RetVal = PRO_IGNORE;
  // }
  // else
  // {
    // RetVal = PRO_IGNORE;
  // }
  // return RetVal;
}

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_UserErrorHook
 *  Service ID       : 0x07
 *  Synchronous      : Synchronous
 *  Reentrancy       : Non Reentrant
 *  Context          : Task (OS Fatal/Application Error Hook)
 *  Description      : CPU-agnostic OS error hook. Maps OS error information
 *                     to a FltM FaultId and reports it to FltM. Severity/
 *                     reset policy is governed by FltM configuration.
 *  Parameters (in)  : errParam - OS error parameters (by value)
 *  Parameters (out) : None
 *  Return value     : void
 *  Preconditions    : Invoked by OS_ERROR_HOOK macro chain.
 *  Postconditions   : Fault may be logged and/or escalated based on config.
 *  Notes            : Does not perform reset directly; FltM->RstM handles it.
 * --------------------------------------------------------------- */
static volatile uint32 fluserErrorHook = 0;
void FltMExt_UserErrorHook(const osErrParamType errParam)
{

  // eFltM_FaultIdType fid = FltMExt_MapOsFatalToFltmFaultId(&errParam);
  // uint8 logdata[5] = {0XAA, 0XAA, 0XAA, 0XAA, 0XAA};
  // /* Send to FltM; FltM_FaultConfig[] decides if this is FATAL (then calls RstM) */
  // if(fid != 0xFFFFU)
  // {
    // logdata[0] = (uint8)(errParam.OsServiceId & 0xFFU); 
    // logdata[1] = errParam.ErrReason;
    // logdata[2] = errParam.LastErrReason;
    // logdata[3] = errParam.CallingTask;
    // (void)FltM_ReportFault(fid, FLTM_ACTIVE, logdata, 5U);
  // }
  // fluserErrorHook++;
  // /* Note: For fatal error hook, OS likely calls osShutdownOS() after this.
     // If you later want RstM to own reset exclusively, youd need an OS option
     // to skip shutdown, which this hook signature doesnt provide. */
}

/*============================================================================
**
** Function Name    :   FltMExt_UserShutdownHook
**
** Visibility       :   Public
**
** Description      :   Action which must be performed when shutdown error hook is invoked from os 
**
** Inputs           :	None
**
** Outputs          :	None
**
** Critical Section :
**
**==========================================================================*/
void FltMExt_UserShutdownHook(void)
{   
    // eFltM_FaultIdType fid = FLTM_E_OS_SHUTDOWN;
    // uint8 logdata;
    
    // (void)FltM_ReportFault(fid, FLTM_ACTIVE, &logdata, 1U);
   
}

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_BuildAndReportOsArmDump
 *  Service ID       : 0x90  (static helper or public as per design)
 *  Synchronous      : Synchronous
 *  Reentrancy       : Non-Reentrant
 *  Context          : Privileged mode (SVC, IRQ, FIQ, Abort)
 *  Description      : Builds an ARM OS fault frame by reading CPU registers
 *                     (FaultInstructionAddr, LR, SPSR, DFSR, IFSR, MMAR) and
 *                     stages it for reset logging via RstM_StageOsArmDump.
 *  Parameters (in)  : None
 *  Parameters (out) : None
 *  Return value     : None
 *  Preconditions    : pFrame must not be NULL and must point to valid memory.
 *  Postconditions   : Fault frame is populated with current CPU state.
 *  Notes            : Used for non-OS triggered resets (e.g., ECC double-bit)
 *                     where OS does not provide the fault frame.
 * --------------------------------------------------------------- */
void FltMExt_BuildAndReportOsArmDump(eFltM_FaultIdType fid)
{
  // ProtErrorInfoType dump;

  // /* Clear dump */
  // dump.FaultInstructionAddr = 0U;
  // dump.lr = 0U;
  // dump.spsr = 0U;
  // dump.DFSR = 0U;
  // dump.IFSR = 0U;
  // dump.IsMMARValid = FALSE;
  // dump.MMARErrAddress = 0U;

  // /* Read CPU registers directly (same as OS does in its abort handlers) */
  // __asm volatile("mov %0, lr" : "=r"(dump.lr));
  // __asm volatile("mrs %0, spsr" : "=r"(dump.spsr));

  // /* Fault status registers (CP15 c5 for DFSR/IFSR, c6 for FAR) */
  // __asm volatile("mrc p15, 0, %0, c5, c0, 0" : "=r"(dump.DFSR)); /* DFSR */
  // __asm volatile("mrc p15, 0, %0, c5, c0, 1" : "=r"(dump.IFSR)); /* IFSR */

  // /* Fault address (IFAR / DFAR) */
  // __asm volatile("mrc p15, 0, %0, c6, c0, 0" : "=r"(dump.MMARErrAddress)); /* DFAR/IFAR */

  // /* Mark MMAR valid if not async aborts */
  // if (((dump.IFSR & ASYNC_EXT_ABORT) != ASYNC_EXT_ABORT) &&
      // ((dump.IFSR & ASYNC_ECC_ABORT) != ASYNC_ECC_ABORT))
  // {
    // dump.IsMMARValid = TRUE;
  // }

  // /* Stage dump into RstM */
  // (void)RstM_StageOsArmDump(fid, &dump, (eFltM_FaultIdType)sizeof(dump));
}

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_MapProtErrorToFaultId
 *  Service ID       : 0x80  (static helper)
 *  Synchronous      : Synchronous
 *  Reentrancy       : Reentrant
 *  Context          : Any (called from hook)
 *  Description      : Maps a ProtectionErrType (Cortex-R5) into one of the
 *                     three SOC exception FIDs: Prefetch Abort, Data Abort,
 *                     or Undefined Instruction. Returns 0xFFFF if unknown.
 *  Parameters (in)  : ProtectionErr - Pointer to OS protection error info
 *  Parameters (out) : None
 *  Return value     : eFltM_FaultIdType
 *  Preconditions    : None
 *  Postconditions   : None
 *  Notes            : Minimal policy�no ECC/Parity classification per spec.
 * --------------------------------------------------------------- */
/* Map ProtectionError + ErrorContext to a FltM faultId */
static eFltM_FaultIdType FltMExt_MapProtErrorToFaultId(const ProtectionErrType *ProtectionErr)
{
  // eFltM_FaultIdType faultId = 0xFFFFU; // Default to invalid fault ID

  // if (ProtectionErr == NULL_PTR)
  // {
    // faultId = 0xFFFF; // Invalid fault ID
    // return faultId;
  // }

  // /* Prefetch Abort path sets IFSR, clears DFSR */
  // if ((ProtectionErr->ProtectionError == E_OS_PROTECTION_MEMORY) &&
      // (ProtectionErr->os_faultFrame.IFSR != 0U) &&
      // (ProtectionErr->os_faultFrame.DFSR == 0U))
  // {
    // faultId = E_ARM_PREFETCH_ABORT_R5;
  // }

  // /* Data Abort path sets DFSR, clears IFSR */
  // if ((ProtectionErr->ProtectionError == E_OS_PROTECTION_MEMORY) &&
      // (ProtectionErr->os_faultFrame.DFSR != 0U) &&
      // (ProtectionErr->os_faultFrame.IFSR == 0U))
  // {
    // faultId = E_ARM_DATA_ABORT;
  // }

  // /* Undefined Instruction handler: both syndromes zero, exception type */
  // if ((ProtectionErr->ProtectionError == E_OS_PROTECTION_EXCEPTION) &&
      // (ProtectionErr->os_faultFrame.IFSR == 0U) &&
      // (ProtectionErr->os_faultFrame.DFSR == 0U))
  // {
    // faultId = E_ARM_UNDEFINED_INSTRUCTION;
  // }

  // return faultId; // Return the mapped fault ID
}

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_MapReason
 *  Service ID       : 0x81  (static helper)
 *  Synchronous      : Synchronous
 *  Reentrancy       : Reentrant
 *  Context          : Any
 *  Description      : Maps an OS error reason code (OS enum range 1..25,255)
 *                     to the FltM fault ID namespace (FLTM_E_OS_*).
 *  Parameters (in)  : reason  - OS reason code
 *  Parameters (out) : None
 *  Return value     : eFltM_FaultIdType (FLTM_E_OS_* or default)
 *  Preconditions    : None
 *  Postconditions   : None
 *  Notes            : Keep in sync with OS reason enumeration.
 * --------------------------------------------------------------- */
static eFltM_FaultIdType FltMExt_MapReason(StatusType reason)
{
    eFltM_FaultIdType fid;
    switch (reason)
    {
    case 1u:
        fid = FLTM_E_OS_ACCESS;
        break;
    case 2u:
        fid = FLTM_E_OS_CALLLEVEL; /* note: OS typo CALLEVEL vs CALLLEVEL? use your final name */
        break;
    case 3u:
        fid = FLTM_E_OS_ID;
        break;
    case 4u:
        fid = FLTM_E_OS_LIMIT;
        break;
    case 5u:
        fid = FLTM_E_OS_NOFUNC;
        break;
    case 6u:
        fid = FLTM_E_OS_RESOURCE;
        break;
    case 7u:
        fid = FLTM_E_OS_STATE;
        break;
    case 8u:
        fid = FLTM_E_OS_VALUE;
        break;
    case 9u:
        fid = FLTM_E_OS_SERVICEID;
        break;
    case 10u:
        fid = FLTM_E_OS_ILLEGAL_ADDRESS;
        break;
    case 11u:
        fid = FLTM_E_OS_MISSINGEND;
        break;
    case 12u:
        fid = FLTM_E_OS_DISABLEDINT;
        break;
    case 13u:
        fid = FLTM_E_OS_STACKFAULT;
        break;
    case 14u:
        fid = FLTM_E_OS_PROTECTION_MEMORY;
        break;
    case 15u:
        fid = FLTM_E_OS_PROTECTION_TIME;
        break;
    case 16u:
        fid = FLTM_E_OS_PROTECTION_ARRIVAL;
        break;
    case 17u:
        fid = FLTM_E_OS_PROTECTION_LOCKED;
        break;
    case 18u:
        fid = FLTM_E_OS_PROTECTION_EXCEPTION;
        break;
    case 19u:
        fid = FLTM_E_OS_INTERFERENCE_DEADLOCK;
        break; 
    case 20u:
        fid = FLTM_E_OS_NESTING_DEADLOCK;
        break;
    case 21u:
        fid = FLTM_E_OS_SPINLOCK; 
        break;
    case 22u:
        fid = FLTM_E_OS_CORE;
        break;
    case 23u:
        fid = FLTM_E_OS_PARAM_POINTER; 
        break;
    case 24u:
        fid = FLTM_E_OS_SHUTDOWN;
        break;
    case 25u:
        fid = FLTM_E_OS_SYS_API_ERROR;
        break;
    case 26u:
        fid = FLTM_E_OS_SYS_ASSERTION;
        break;
    case 27u:
        fid = FLTM_E_OS_SYS_DISABLED;
        break;
    case 28u:
        fid = FLTM_E_OS_SYS_NO_BARRIER_PARTICIPANT;
        break;
    case 29u:
        fid = FLTM_E_OS_SYS_UNIMPLEMENTED_FUNCTIONALITY;
        break;
    case 30u:
        fid = FLTM_E_OS_SYS_NO_NTFSTACK;
        break;    
    case 31u:
        fid = FLTM_E_OS_SYS_OVERFLOW;
        break;  
    case 32u:
        fid = FLTM_E_OS_SYS_KILL_KERNEL_OBJ;
        break;
    case 33u:
        fid = FLTM_E_OS_SYS_NO_RESTARTTASK;
        break;  
    case 34u:
        fid = FLTM_E_OS_SYS_CALL_NOT_ALLOWED;
        break;  
    case 35u:
        fid = FLTM_E_OS_SYS_FUNCTION_UNAVAILABLE;
        break; 
    case 36u:
        fid = FLTM_E_OS_SYS_PROTECTION_SYSCALL;
        break; 
    case 37u:
        fid = FLTM_E_OS_SYS_PROTECTION_IRQ;
        break; 
    case 38u:
        fid = FLTM_E_OS_SYS_OVERLOAD;
        break;  
    case 39u:
        fid = FLTM_E_OS_SYS_CROSS_CORE_REQUESTED;
        break;                                   
    default:
        fid = FLTM_E_OS_SYS_API_ERROR;
        break;
    }
    return fid; // Return the mapped fault ID
}

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_MapService
 *  Service ID       : 0x82  (static helper)
 *  Synchronous      : Synchronous
 *  Reentrancy       : Reentrant
 *  Context          : Any
 *  Description      : Fallback mapping: derives a generic FltM fault
 *                     category from the OS Service ID when the reason
 *                     code is generic/unavailable.
 *  Parameters (in)  : sid   - OS Service ID (Autosar/OSEK + impl-specific)
 *  Parameters (out) : None
 *  Return value     : eFltM_FaultIdType (FLTM_E_OS_* category)
 *  Preconditions    : None
 *  Postconditions   : None
 *  Notes            : Update when new service IDs are introduced.
 * --------------------------------------------------------------- */
/* Fallback categorization when Reason is unusable (should be rare) */
static eFltM_FaultIdType FltMExt_MapService(OsServiceIdType sid)
{
  eFltM_FaultIdType result = FLTM_E_OS_SYS_API_ERROR;  /* Default */
  
  switch (sid)
  {
    /* Task services */
    case OsDlt_OsActivateTask:
    case OsDlt_OsTerminateTask:
    case OsDlt_OsChainTask:
    case OsDlt_OsSchedule:
    case OsDlt_OsGetTaskID:
    case OsDlt_OsGetTaskState:
     /* Event services */
    case OsDlt_OsSetEvent:
    case OsDlt_OsClearEvent:
    case OsDlt_OsGetEvent:
    case OsDlt_OsWaitEvent:
      result = FLTM_E_OS_STATE;
      break;

    /* Resource services */
    case OsDlt_OsGetResource:
    case OsDlt_OsReleaseResource:
      result = FLTM_E_OS_RESOURCE;
      break;

    /* Alarm/Counter/ScheduleTable */
    case OsDlt_osSetRelAlarm:
    case OsDlt_osCancelAlarm:
    case OsDlt_osGetAlarm:
    case OsDlt_osSetAbsAlarm:
    case OsDlt_OsIncrementCounter:
    case OsDlt_OsGetCounterValue:
    case OsDlt_OsGetElapsedValue:
    case OsDlt_OsStartScheduleTableRel:
    case OsDlt_OsStartScheduleTableAbs:
    case OsDlt_OsStopScheduleTable:
    case OsDlt_OsGetScheduleTableStatus:
      result = FLTM_E_OS_VALUE;
      break;

    /* Interrupt control */
    case OsDlt_DisableInterruptSource:
    case OsDlt_EnableInterruptSource:
      result = FLTM_E_OS_SYS_PROTECTION_IRQ;
      break;

    /* App / trusted function */
    case OsDlt_OsGetApplicationState:
    case OsDlt_OsCallTrustedFunction:
      result = FLTM_E_OS_ACCESS;
      break;

    case OsDlt_osShutdownOS:
      result = FLTM_E_OS_SHUTDOWN;
      break;

    case OsDlt_OsInternalService:
    case OsDlt_OsInvalidService:
    default:
      result = FLTM_E_OS_SYS_API_ERROR;
      break;
  }
  
  return result;
}

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_MapOsFatalToFltmFaultId
 *  Service ID       : 0x83  (static helper)
 *  Synchronous      : Synchronous
 *  Reentrancy       : Reentrant
 *  Context          : Any
 *  Description      : Determines the FltM fault ID for an OS fatal error,
 *                     preferring explicit reason mapping and falling back
 *                     to service-based categorization when needed.
 *  Parameters (in)  : pErrParam - Pointer to OS fatal error params
 *  Parameters (out) : None
 *  Return value     : eFltM_FaultIdType
 *  Preconditions    : None
 *  Postconditions   : None
 *  Notes            : Single return at end per your style.
 * --------------------------------------------------------------- */
static eFltM_FaultIdType FltMExt_MapOsFatalToFltmFaultId(const osErrParamType *pErrParam)
{
  eFltM_FaultIdType fid = FLTM_E_OS_SYS_API_ERROR; /* default */

  if (pErrParam != NULL_PTR)
  {
    fid = FltMExt_MapReason(pErrParam->ErrReason);

    /* If still generic (and not explicit SYS_ABORT=21), fall back to service */
    if ((fid == FLTM_E_OS_SYS_API_ERROR) && (pErrParam->ErrReason != 21U))
    {
      fid = FltMExt_MapService(pErrParam->OsServiceId);
    }
    /* to be decide as this continuously coming - msavariy*/
    /*ErrReason - 0x04 = E_OS_LIMIT, OsServiceId - 0x30 = OsDlt_OsActivateTask */
    if((pErrParam->ErrReason == 0x04U) && (pErrParam->OsServiceId == 0x30U))
    {
      fid = 0xFFFFU;
    }
  }
  return fid;
}

#endif /* FLTMEXT_H */

/*============================================================================
**============================================================================
** R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
**===================================================================================================*/
/*---------------------------------------------------------------------------------------------------
Date               : 17-Jun-2025
CDSID              : MSAVARIY
Traceability       :
Change Description : FltMExt Initial Version
                      https://visteon.atlassian.net/browse/PE4TI29141-8791
------------------------------------------------------------------------------------------------------*/
/* end of file ======================================================================================*/