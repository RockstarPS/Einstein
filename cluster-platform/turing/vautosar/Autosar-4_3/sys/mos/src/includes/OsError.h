/**
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2013. Visteon Corporation owns all rights to
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
 * @file        OsError.h
 * @details     <b> File externs the generic APIs of the OS  </b>
 * @note
 *              Compiler    : GHS \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2021
 *
 */

#ifndef OS_ERR_H
#define OS_ERR_H

#include "OsTypes.h"


extern void EcuM_Shutdown(void);
extern OsServiceIdType OsErr_GetServiceId (void);
 
#define OSErrorGetServiceId()       OsErr_GetServiceId() /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

extern void OsError_InitMemory(void);

typedef enum
{
  PRO_IGNORE,
  PRO_TERMINATETASKISR,
  PRO_TERMINATEAPPL,
  PRO_TERMINATEAPPL_RESTART,
  PRO_SHUTDOWN,
} ProtectionRetType; /*MISRA RULE 2.3 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

typedef enum
{
  SELF_TEST_INACTIVE,
  SELF_TEST_ACTIVE
} SelftestActType; /*MISRA RULE 2.3 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

/* All errors of API services (inherited from OSEK spec) */
/*      E_OK                        0  now defined in OsMain.h */
#define E_OS_ACCESS                 1
#define E_OS_CALLEVEL               2
#define E_OS_ID                     3
#define E_OS_LIMIT                  4
#define E_OS_NOFUNC                 5
#define E_OS_RESOURCE               6
#define E_OS_STATE                  7
#define E_OS_VALUE                  8

/* errors of API services (Autosar specification v3.0) */
/* fullfills [SR:311] of $\AutosarOS\general\Generation5\_doc\12_SystemRequirements\RequirementsSpec_MicrosarOS.doc */
#define E_OS_SERVICEID              9
#define E_OS_ILLEGAL_ADDRESS        10
#define E_OS_MISSINGEND             11
#define E_OS_DISABLEDINT            12
#define E_OS_STACKFAULT             13
#define E_OS_PROTECTION_MEMORY      14U
#define E_OS_PROTECTION_TIME        15 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define E_OS_PROTECTION_ARRIVAL     16 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define E_OS_PROTECTION_LOCKED      17 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define E_OS_PROTECTION_EXCEPTION   18U

#define E_OS_SYS_ASSERTION          20
#define E_OS_SYS_ABORT              21
/*E_OS_SYS_DIS_INT replaced by E_O  S_DISABLEDINT, no No. 22*/
#define E_OS_SYS_API_ERROR          23 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define E_OS_SYS_ALARM_MANAGEMENT   24 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define E_OS_SYS_WARNING            25 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define E_OS_OVERLOAD               26U

#define E_OS_INVALID                255

#endif

/*============================================================================
**============================================================================
** R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
**===========================================================================*/
/*---------------------------------------------------------------------------
Date               : 09-Sep-16
CDSID              : ssukuma1
Traceability       : 
Change Description : Initial version
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/
