/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2020. Visteon Corporation owns all rights to           *
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
#ifndef E2E_C
#define E2E_C
/*****************************************************************************
*  File Name         :  E2E.c                                                *
*  Module Short Name :  E2E                                                  *
*  Description       :  This file contains E2E Module Implementation         *
*                       		                                             *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "E2E.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define E2E_VERSION_INFO_API              (STD_ON)
#define E2E_VENDOR_ID                     (0x33U)
#define E2E_MODULE_ID                     (207u)

#define E2E_AR_RELEASE_MAJOR_VERSION      (4u)
#define E2E_AR_RELEASE_MINOR_VERSION      (2u)
#define E2E_AR_RELEASE_REVISION_VERSION   (1u)

#define E2E_SW_MAJOR_VERSION				(0u)
#define E2E_SW_MINOR_VERSION				(0u)
#define E2E_SW_PATCH_VERSION				(22u)
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
#define E2E_CODE_SEC_START
#include "MemMap.h"

/*============================================================================
**
** Function Name    :   E2E_GetVersionInfo
**
** Visibility       :   Public
**
** Description      :   This function returns the Version informations
**                      of this module.
**
** Invocation       :
**
** Inputs           :   Std_VersionInfoType * VersionInfo - Pointer to a VersionInfo type.
**
** Outputs          :	Void
**
** Critical Section :	NA
**
**==========================================================================*/
#if (E2E_VERSION_INFO_API == STD_ON)
void E2E_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
    if (VersionInfo != NULL_PTR)
    {
        VersionInfo->vendorID = E2E_VENDOR_ID;
        VersionInfo->moduleID = E2E_MODULE_ID;
        VersionInfo->sw_major_version = E2E_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = E2E_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = E2E_SW_PATCH_VERSION;
    }
}
#endif

#define E2E_CODE_SEC_END
#include "MemMap.h"
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
Date               : 17-Apr-2020
CDSID              : ssebast1
Traceability       : RTC #794879
Change Description : Initial Framework version of E2E Module with Profile2
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 23-May-2022
CDSID              : eganesan
Traceability       : RTC #1667456
Change Description : Bsw General Requirement supported
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 09-Jun-2022
CDSID              : dbalasub
Traceability       : RTC #1683388
Change Description : Audit fix
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/
