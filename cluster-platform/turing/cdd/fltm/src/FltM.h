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
 * @file        FltM.h
 * @details     <b> Fault Manager Component to handle all types of faults in 
                    the system which includes both application faults and soc
                    faults. </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2025
 *
 */
#ifndef  FLTM_H_
#define  FLTM_H_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "FltM_Types.h"
#include "FltM_Cfg.h"

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
#define FLTM_UINT16_MAX   0xFFFFu

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
/*****************************************************************************
*                               Functions                                    *
******************************************************************************/
/*============================================================================
**
** Function Name    :   FltM_Init
**
** Visibility       :   Public
**
** Description      :   The Init function is called to initialise the Global
**                      and Static variables of this module.
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
void FltM_Init(void);

/*============================================================================
**
** Function Name    :   FltM_HandlePostReset
**
** Visibility       :   Public
**
** Description      :   Restores cross-reset fault context after the reset
**                      manager has provided the last reset reason. If the
**                      mapped fault row enables diagnostic-event reporting,
**                      this API also requests the corresponding event status
**                      update.
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
void FltM_HandlePostReset(void);

/*============================================================================
**
** Function Name    :   FltM_MainFunction
**
** Visibility       :   Public
**
** Description      :   Periodic processing function for Fault Manager.
**                      Waits for last reset reason, replays queued startup
**                      faults after initialization, evaluates time-based
**                      debounce, and services the SoC fault-handler layer.
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
void FltM_MainFunction(void);

/*============================================================================
**
** Function Name    :   FltM_ReportFault
**
** Visibility       :   Public
**
** Description      :   Reports a logical fault condition to Fault Manager.
**                      The fault row is resolved from configuration and then
**                      processed according to the configured debounce and
**                      reaction policy.
**
** Invocation       :   Application
**
** Inputs           :   FaultId      - Logical fault identifier
**                      FaultStatus  - ACTIVE or INACTIVE report status
**                      LogData      - Optional pointer to fault-specific
**                                     runtime payload
**                      LogLength    - Length of LogData in bytes
**
** Outputs          :   E_OK / E_NOT_OK
**
** Critical Section :   Yes
**
**==========================================================================*/
Std_ReturnType FltM_ReportFault(FltM_FaultIdType FaultId,
                                eFltM_FaultStatusType FaultStatus,
                                uint8 *LogData, uint16 LogLength);

/*============================================================================
**
** Function Name    :   FltM_GetFaultStatus
**
** Visibility       :   Public
**
** Description      :   Returns the evaluated public fault status for the
**                      requested logical fault. The returned state is the
**                      compatibility/public view of the internal E4 fault
**                      state machine and shall not be treated as the latest
**                      raw report.
**
** Invocation       :   Application
**
** Inputs           :   FaultId      - Logical fault identifier
**                      FaultStatus  - Pointer to evaluated public status
**
** Outputs          :   E_OK / E_NOT_OK
**
** Critical Section :   Yes
**
**==========================================================================*/
Std_ReturnType FltM_GetFaultStatus(FltM_FaultIdType FaultId,
                                   FltM_PublicFaultStatusType *FaultStatus);

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
Date              :03-Jun-2025
By                :RRAJAGO2
Traceability      :
Change Description:Initial Framework Implementation
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :16-Jun-2025
By                :MSAVARIY
Traceability      :
Change Description:FltM, FltM_Common requirement implementation
                        https://visteon.atlassian.net/browse/PE4TI29141-8791
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :09-May-2026
By                :MSAVARIY
Traceability      :
Change Description:Add public evaluated fault-status API for compatibility
                   status polling.
-----------------------------------------------------------------------------*/
