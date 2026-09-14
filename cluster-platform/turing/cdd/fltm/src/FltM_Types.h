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
 * @file        FltM_Types.h
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
#ifndef  FLTM_TYPES_H_
#define  FLTM_TYPES_H_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Std_Types.h"

#define FLTM_SEC_CODE_START
#define FLTM_CORE_CONST_SEC_START
#define FLTM_CORE_DATA_SEC_START
#define FLTM_CORE_BSS_SEC_START

#include "MemMap.h"
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#define FLTM_MAX_LOG_LENGTH                                   5U

#define FLTM_INIT_API_ID                                      1U
#define FLTM_MAINFUNCTION_API_ID                              2U
#define FLTM_HANDLE_POST_RESET_API_ID                         3U
#define FLTM_REPORT_FAULT_API_ID                              4U
#define FLTM_GET_FAULT_STATUS_API_ID                          5U

#define FLTM_SOC_INIT_FAILED                                  1U
#define FLTM_FAULT_CONFIG_ERROR                               2U
#define FLTM_RSTM_COUNT_ERROR                                 3U
#define FLTM_NULL_PTR_ERROR                                   4U

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
/* Enumeration of error types that can be detected by the Fault Manager */
/* To be removed once RTE is generated */

/* Legacy log-severity enum retained for compatibility.
 * Current common-core runtime policy uses FltMLogLevel from configuration.
 */
typedef enum
{
    FLTM_FAULT_SEVERITY_INFO = 0,
    FLTM_FAULT_SEVERITY_WARN,
    FLTM_FAULT_SEVERITY_ERROR,
    FLTM_FAULT_SEVERITY_FATAL
} FltM_FaultSeverityType;


typedef enum {
   FLTM_FAULT_STATUS_GOOD = 0,
   FLTM_FAULT_STATUS_NG,
   FLTM_FAULT_STATUS_TRANSITION_TO_NG,
   FLTM_FAULT_STATUS_TRANSITION_TO_GOOD
} FltM_InternalFltMStatusType;

typedef enum
{
    FLTM_PUBLIC_STATUS_INACTIVE = 0U,
    FLTM_PUBLIC_STATUS_ACTIVE,
    FLTM_PUBLIC_STATUS_FAULT_DECLARED
} FltM_PublicFaultStatusType;

typedef enum
{
    FLTM_DEBOUNCE_TYPE_COUNTER = 0U,
    FLTM_DEBOUNCE_TYPE_TIME    = 1U
} FltM_DebounceTypeType;


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
Change Description:Initial Implementation
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :16-Jun-2025
By                :MSAVARIY
Traceability      :
Change Description:FltM, FltM_Common requirement implementation
                        https://visteon.atlassian.net/browse/PE4TI29141-8791
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :18-Nov-2025
By                :MSAVARIY
Traceability      :
Change Description:Time Debounce implementation
                       https://visteon.atlassian.net/browse/PE4TI29141-10705
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :09-May-2026
By                :MSAVARIY
Traceability      :
Change Description:Add public fault-status type and API identifiers for
                   compatibility-status polling.
-----------------------------------------------------------------------------*/
