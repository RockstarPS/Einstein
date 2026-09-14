/**
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2025. Visteon Corporation owns all rights to
 this work and intends to maintain it in confidence to preserve
 its trade secret status. Visteon Corporation reserves the right,
 under the copyright laws of the United States or those of any
 other country that may have jurisdiction, to protect this work
 as an unpublished work, in the event of an inadvertent or
 deliberate unauthorized publication. Visteon Corporation also
 reserves its rights under all copyright laws to protect this
 work as a published work, when appropriate. Those having access
 to this work may not copy it, use it, modify it or disclose the
 information contained in it without the written authorization
 of Visteon Corporation.
 * @endverbatim
 * @file        RstM_Cfg.c
 * @details     <b> Fault Manager to handle TI SDL - ESM </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2024
 *
 */
#ifndef  RSTM_CFG_C_
#define  RSTM_CFG_C_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "RstM_Cfg.h"
#include "RstM_Types.h"
#include "FltMExt.h"          // FltMExt OS ARM dump callout

#define RSTM_SEC_CODE_START
#define RSTM_CORE_CONST_SEC_START
#define RSTM_CORE_DATA_SEC_START
#define RSTM_CORE_BSS_SEC_START

#include "MemMap.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/



/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
/**
 * @brief Reset Manager fault-to-reset-request configuration table
 */
const RstM_FaultConfigType RstM_FaultConfig[RSTM_MAX_NUM_FAULTS] =
{
  /* FaultId                                      ResetRequestType */
  { DCC_FAIL,                                     PMIC_RESET },
  { ECC_FAULT,                                    PMIC_RESET },
  { ECC_1BIT_ERROR,                               PMIC_RESET },
  { ECC_2BIT_ERROR,                               PMIC_RESET },
  { OCOC_FAIL,                                    PMIC_RESET },
  { POK_FAULT,                                    PMIC_RESET },
  { TIFS_SAFETY_CHECK_FWL_FAIL,                   PMIC_RESET },
  { EXT_WDG_RESET,                                PMIC_RESET },
  { EXT_WDG_COMM_ERROR,                           PMIC_RESET },
  { E_ARM_PREFETCH_ABORT_R5,                      PMIC_RESET },
  { E_ARM_DATA_ABORT,                             PMIC_RESET },
  { E_ARM_UNDEFINED_INSTRUCTION,                  PMIC_RESET },
  { FLTM_E_DMNMGR_GIP_FIRSTHB_MISS,               PMIC_RESET },
  { SW_MAIN_WARMRSTz,                             PMIC_RESET },
  { FALSH_INTEGRITY_FAIL,                         PMIC_RESET },
  { WDGM_ALIVE_FAIL,                              PMIC_RESET },
  { FLTM_E_OS_STATE,                              PMIC_RESET },
  { FLTM_E_OS_CALLLEVEL,                          PMIC_RESET },
  { FLTM_E_OS_ACCESS,                             PMIC_RESET },
  { FLTM_E_OS_ID,                                 PMIC_RESET },
  { FLTM_E_OS_LIMIT,                              PMIC_RESET },
  { FLTM_E_OS_NOFUNC,                             PMIC_RESET },
  { FLTM_E_OS_RESOURCE,                           PMIC_RESET },
  { FLTM_E_OS_VALUE,                              PMIC_RESET },
  { FLTM_E_OS_SERVICEID,                          PMIC_RESET },
  { FLTM_E_OS_ILLEGAL_ADDRESS,                    PMIC_RESET },
  { FLTM_E_OS_MISSINGEND,                         PMIC_RESET },
  { FLTM_E_OS_DISABLEDINT,                        PMIC_RESET },
  { FLTM_E_OS_STACKFAULT,                         PMIC_RESET },
  { FLTM_E_OS_PROTECTION_MEMORY,                  PMIC_RESET },
  { FLTM_E_OS_PROTECTION_TIME,                    PMIC_RESET },
  { FLTM_E_OS_PROTECTION_ARRIVAL,                 PMIC_RESET },
  { FLTM_E_OS_PROTECTION_LOCKED,                  PMIC_RESET },
  { FLTM_E_OS_PROTECTION_EXCEPTION,               PMIC_RESET },
  { FLTM_E_OS_INTERFERENCE_DEADLOCK,              PMIC_RESET },
  { FLTM_E_OS_NESTING_DEADLOCK,                   PMIC_RESET },
  { FLTM_E_OS_SPINLOCK,                           PMIC_RESET },
  { FLTM_E_OS_CORE,                               PMIC_RESET },
  { FLTM_E_OS_PARAM_POINTER,                      PMIC_RESET },
  { FLTM_E_OS_SHUTDOWN,                           PMIC_RESET },
  { FLTM_E_OS_SYS_API_ERROR,                      PMIC_RESET },
  { FLTM_E_OS_SYS_ASSERTION,                      PMIC_RESET },
  { FLTM_E_OS_SYS_DISABLED,                       PMIC_RESET },
  { FLTM_E_OS_SYS_NO_BARRIER_PARTICIPANT,         PMIC_RESET },
  { FLTM_E_OS_SYS_UNIMPLEMENTED_FUNCTIONALITY,    PMIC_RESET },
  { FLTM_E_OS_SYS_NO_NTFSTACK,                    PMIC_RESET },
  { FLTM_E_OS_SYS_OVERFLOW,                       PMIC_RESET },
  { FLTM_E_OS_SYS_KILL_KERNEL_OBJ,                PMIC_RESET },
  { FLTM_E_OS_SYS_NO_RESTARTTASK,                 PMIC_RESET },
  { FLTM_E_OS_SYS_CALL_NOT_ALLOWED,               PMIC_RESET },
  { FLTM_E_OS_SYS_FUNCTION_UNAVAILABLE,           PMIC_RESET },
  { FLTM_E_OS_SYS_PROTECTION_SYSCALL,             PMIC_RESET },
  { FLTM_E_OS_SYS_PROTECTION_IRQ,                 PMIC_RESET },
  { FLTM_E_OS_SYS_OVERLOAD,                       PMIC_RESET },
  { FLTM_E_OS_SYS_CROSS_CORE_REQUESTED,           PMIC_RESET },
  { DET_ERROR,                                    PMIC_RESET },
  { HSM_WDG_FAIL,                                 PMIC_RESET },
  { DM_WDG_FAIL,                                  PMIC_RESET },
  { FLTM_E_DMNMGR_GIP_HB_MISS,                    PMIC_RESET },
  { FLTM_E_DMNMGR_GIP_LINKUP_FAILED,              PMIC_RESET },
  { FLTM_E_DMNMGR_GIP_HEALTH_FATAL_ERROR,         PMIC_RESET },
  { PERIODIC_READBACK_FAIL,                       PMIC_RESET },
  { POWER_SUPPLY_FAULT,                           PMIC_RESET }
#if (FLTM_SAME_FAULT_RESET_LOOP_HW_TEST_ENABLE == STD_ON)
  ,
  { FLTM_SAME_FAULT_HW_TEST_FAULT_ID,              PMIC_RESET }
#endif
};

/**
 * @brief Reset Manager DLT log metadata
 */
const RstM_Dlt_MessageLogInfoType RstM_Dlt_MessageLogInfo =
{
  0U,
  DLT_LOG_FATAL,
  1U,
  DLT_ISMSGVERBOSEMODE_BIT,
  { (uint8)'R', (uint8)'S', (uint8)'T', (uint8)'M' },
  { (uint8)'R', (uint8)'S', (uint8)'T', (uint8)'M' }
};

void RstM_Det_ReportError(uint8 ApiId, uint8 ErrorId)
{
  (void)Det_ReportError((uint16)65228U, 0x01u, ApiId, ErrorId);
  while(1);
}

void RstM_Callout_FltMExt_BuildAndReportOsArmDump(eFltM_FaultIdType fid)
{
  /* Call FltMExt function to build the OS ARM dump and report to DET */
  FltMExt_BuildAndReportOsArmDump(fid);
}

#define RSTM_SEC_CODE_STOP
#define RSTM_CORE_CONST_SEC_END
#define RSTM_CORE_DATA_SEC_END
#define RSTM_CORE_BSS_SEC_END

#include "MemMap.h"

#endif

/*****************************************************************************
*     End of File
*
*******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/*----------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  
By                :  
Traceability      : 
Change Description: 
-----------------------------------------------------------------------------*/
