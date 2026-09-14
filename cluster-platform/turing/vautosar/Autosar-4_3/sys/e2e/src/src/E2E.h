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
#ifndef E2E_H
#define E2E_H
/*****************************************************************************
*  File Name         :  E2E.h                                               *
*  Module Short Name :  E2E_H                                               *
*  Description       :                                                       *
*                                                                            *
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
#include "Std_Types.h"
#include "E2E_P01.h"
#include "E2E_P02.h"
#include "E2E_P04.h"
#include "E2E_P05.h"
#include "E2E_P06.h"
#include "Crc.h"
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
*                            External Function Declarations	     		     *
******************************************************************************/
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
void E2E_GetVersionInfo(Std_VersionInfoType* VersionInfo);



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
/* end of file =============================================================*/
