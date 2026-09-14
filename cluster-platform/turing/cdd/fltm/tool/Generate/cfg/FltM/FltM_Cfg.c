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
 * @file        FltM_Cfg.c
 * @details     <b> Fault Manager to handle TI SDL - ESM </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2024
 *
 */

#ifndef  FLTM_CFG_C_
#define  FLTM_CFG_C_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "FltM_Cfg.h"
#include "FltM_Types.h"
#include "FltMExt.h"          // FltMExt functions

#define FLTM_SEC_CODE_START
#define FLTM_CORE_CONST_SEC_START
#define FLTM_CORE_DATA_SEC_START
#define FLTM_CORE_BSS_SEC_START

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
 * @brief DLT metadata table for all faults (common entries)
 */
const FltM_Dlt_MessageLogInfoType FltM_Dlt_MessageLogInfo[FLTM_NUMBER_OF_DLT_LOGINFO] =
{
  /* Session Id, argCount, options, appId, contextId */
  { 0U, 2U, 0U, { 'F','L','T','M' }, { 'F','L','T','M' } },
  { 0U, 2U, 0U, { 'F','L','T','M' }, { 'F','L','T','M' } }
};

/**
 * @brief Fault Manager configuration table
 */
const FltM_FaultConfigType FltM_FaultConfig[FLTM_MAX_NUM_FAULTS] =
{
  /* FaultId, FltMLogLevel, DltLogInfoIndex, FirstSafeActionThreshold, FinalSafeActionThreshold, FltM_FirstSafeAction, FltM_FinalSafeAction, LogDtc, DemEventId */
  { DCC_FAIL, DLT_LOG_FATAL, 1U, 0U, 3U, NULL_PTR, NULL_PTR, 0U, 1U },
  { ECC_FAULT, DLT_LOG_FATAL, 1U, 0U, 3U, NULL_PTR, NULL_PTR, 0U, 2U },
  { OCOC_FAIL, DLT_LOG_FATAL, 1U, 0U, 3U, NULL_PTR, NULL_PTR, 0U, 1U },
  { POK_FAULT, DLT_LOG_FATAL, 1U, 0U, 3U, NULL_PTR, NULL_PTR, 0U, 2U },
  { TIFS_SAFETY_CHECK_FWL_FAIL, DLT_LOG_FATAL, 1U, 0U, 3U, NULL_PTR, NULL_PTR, 0U, 1U },
  { POWER_ON_RESET, DLT_LOG_FATAL, 1U, 0U, 3U, NULL_PTR, NULL_PTR, 0U, 1U },
  { 0xF70A, DLT_LOG_FATAL, 1U, 0U, 3U, NULL_PTR, NULL_PTR, 0U, 1U },
  { POWER_SUPPLY_FAULT, DLT_LOG_FATAL, 1U, 2U, 3U, NULL_PTR, NULL_PTR, 0U, 1U },
  { EXT_WDG_RESET, DLT_LOG_FATAL, 1U, 0U, 3U, NULL_PTR, NULL_PTR, 0U, 1U },
  { EXT_WDG_COMM_ERROR, DLT_LOG_FATAL, 1U, 0U, 3U, NULL_PTR, NULL_PTR, 0U, 1U },
  { E_ARM_PREFETCH_ABORT_R5, DLT_LOG_FATAL, 1U, 0U, 3U, NULL_PTR, NULL_PTR, 0U, 1U },
  { E_ARM_DATA_ABORT, DLT_LOG_FATAL, 1U, 0U, 3U, NULL_PTR, NULL_PTR, 0U, 1U },
  { E_ARM_UNDEFINED_INSTRUCTION, DLT_LOG_FATAL, 1U, 0U, 3U, NULL_PTR, NULL_PTR, 0U, 1U },
  { DMNMGR_GIPHEALTH_ERROR, DLT_LOG_FATAL, 1U, 0U, 3U, NULL_PTR, NULL_PTR, 0U, 1U },
  { SW_MAIN_WARMRSTz, DLT_LOG_FATAL, 1U, 0U, 3U, NULL_PTR, NULL_PTR, 0U, 1U },
  { FALSH_INTEGRITY_FAIL, DLT_LOG_FATAL, 1U, 0U, 3U, NULL_PTR, NULL_PTR, 0U, 1U },
  { PMIC_ABIST_FAIL, DLT_LOG_FATAL, 1U, 0U, 3U, NULL_PTR, NULL_PTR, 0U, 1U },
  { FLTM_E_OS_STATE, DLT_LOG_OFF, 1U, 0U, 3U, NULL_PTR, NULL_PTR, 0U, 1U }
};


void FltM_Det_ReportError(uint8 ApiId, uint8 ErrorId)
{
    (void)Det_ReportError(65224U,0x01, ApiId, ErrorId);
    while(1);
}

#define FLTM_SEC_CODE_STOP
#define FLTM_CORE_CONST_SEC_END
#define FLTM_CORE_DATA_SEC_END
#define FLTM_CORE_BSS_SEC_END

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
