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
 * @file        OsMemProtection.h
 * @details     <b>file externs the generic APIs of the OS</b>
 * @note
 *              Compiler    : GHS \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2021
 *
 */
#ifndef OS_MEMPROTECTION_H
#define OS_MEMPROTECTION_H

#include "OsMain.h"
#include "OsHal_CpuCore.h"



/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/



extern void OsMemProtect_Init (void);
extern void OsMemProtPrv_AppMpuSwitch (AccessRightsIdType Prev, AccessRightsIdType Next);
extern void OsMemProtPrv_ObjMpuSwitch (AccessRightsIdType Prev, AccessRightsIdType Next);
extern OsMpuAccessGroupConfigRefType OsMemProt_GetAccessRights(AccessRightsIdType Id);
extern void OsMemProt_SaveMpuSwitchToOs (OsMPUAccessRightsIdRefType pCallerRights);
extern void OsMemProt_RestoreMpuSwitchFromOs (OsMPUAccessRightsIdRefType pCallerRights);
extern void OsMemProt_MpuSwitch(void);
extern void OsMemProt_MpuSwitchFromISR(void);
extern void OsMemProt_ClearOSStateCntr (void);
extern void OsMemProt_MpuSwitchTrustedCall (AccessRightsIdType Prev, AccessRightsIdType Next);

#endif

/*----------------------------------------------------------------------------------**
**  ------------------------------------------------------------------------------- **
**   ****************************************************************************   **
**      for each change to this file, be sure to record:                            **
**         1.  who made the change and when the change was made                     **
**         2.  why the change was made and the intended result                      **
**      Following block needs to be repeated for each change                        **
**   ****************************************************************************   **
**      Note: In the traceability column we need to trace back to the Design Doc.   **
**      For the initial version it is traced to the Design Document section.        **
**      For further changes it shall trace to the source of the change which may    **
**      be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any     **
**      other reason                                                                **
**   ****************************************************************************   **
**   ------------------------------------------------------------------------------ **
**   Date              : 06-Jun-2020                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : 920651                                                     **
**   Change Description: OS SC3 Support - Initial Version                           **
**----------------------------------------------------------------------------------*/
