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
 *  File Name         :  FltMExt.h                                            *
 *  Module Short Name :  FltMExt                                              *
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
#ifndef FLTMEXT_H
#define FLTMEXT_H
/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
#include "FltM.h"
#include "Std_Types.h"
#include "Rte_IoHwAb_Type.h"

/*****************************************************************************
 *                            Macro Definitions                             *
 *****************************************************************************/
#define FLTMEXT_VBATT_MONITOR                                          STD_ON
#define LOGDATA                                                        5U

/*ProtectionHook error macros*/
#define FLTMEXT_ASYNC_EXT_ABORT (0x406U)
#define FLTMEXT_ASYNC_ECC_ABORT (0x408U)

typedef unsigned char  osuint8;
typedef osuint8 osbool;
typedef unsigned long  osuint32;

typedef struct
{
    osuint32 FaultInstructionAddr;    /* Address which triggered the fault */
    osuint32 lr;                      /* LR register content */
    osuint32 spsr;                    /* SPSR register content */
    osuint32 DFSR;                    /* DFSR register content */
    osuint32 IFSR;                    /* IFSR register content */
    osuint8  FaultException;          /* 0x1->Data_Abort 0x2->Prefetch_Abort 0x4->Undefined */
    osbool   IsMMARValid;             /* IS MMAR valid */
    osuint32 MMARErrAddress;          /* MMAR Error address, Valid only if IsMMARValid is TRUE */
    osuint32 r0;                      /* R0 during exception entry */
    osuint32 r1;                      /* R1 during exception entry */
    osuint32 r2;                      /* R2 during exception entry */
    osuint32 r3;                      /* R3 during exception entry */
    osuint32 r12;                     /* R12 during exception entry */
} FltMExt_ProtErrorInfoType;

/*****************************************************************************
 *                            IFunction Declaration                          *
 ******************************************************************************/
extern void FltMExt_Init(void);
extern void FltMExt_DeInit(void);
extern void FltMExt_MainFunction(void);
extern Std_ReturnType FltMExt_InitialSafeAction (FltM_FaultIdType FaultId);
extern Std_ReturnType FltMExt_FinalSafeAction (FltM_FaultIdType FaultId);
extern Std_ReturnType FltMExt_RecoveryAction (FltM_FaultIdType FaultId);

extern Std_ReturnType IoHwAb_DOut_SetOutputPin(IoHwAb_DOutSignalIdType OutputId, boolean OutputSignal, IoHwAb_ErrorType* ErrorStatus);  //#issue Review Problem ID NA: Function 'IoHwAb_DOut_SetOutputPin' is called but has no prototype

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
void FltMExt_BuildAndReportOsArmDump(eFltM_FaultIdType fid);

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

ProtectionReturnType FltMExt_UserProtectionHook(const StatusType errInfo);

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
void FltMExt_UserErrorHook(const Os_ErrorInformationType errParam, const StatusType errStatus);

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
void FltMExt_UserShutdownHook(void);

/*============================================================================
**
** Function Name    :   FltMExt_PanicHook
**
** Visibility       :   Public
**
** Description      :   Action which must be performed when panic error hook is invoked from os 
**
** Inputs           :	None
**
** Outputs          :	None
**
** Critical Section :
**
**==========================================================================*/
void FltMExt_PanicHook(const Os_PanicStatusType errParam);

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