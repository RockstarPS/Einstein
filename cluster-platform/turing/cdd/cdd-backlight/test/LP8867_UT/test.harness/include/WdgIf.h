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
/*****************************************************************************
*  File Name         :  WdgIf.h                                              *
*  Module Short Name :  WdgIf_H                                              *
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
#ifndef WDGIF_H
#define WDGIF_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Std_Types.h"
#include "WdgIf_Types.h"
#include "WdgIf_Cfg.h"
#include "WdgIf_Lcfg.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define WDGIF_VERSION_INFO_API              STD_ON

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
#if (WDGIF_VERSION_INFO_API == STD_ON)
extern void WdgIf_GetVersionInfo(Std_VersionInfoType* VersionInfo);
#endif
extern void WdgIf_SetTriggerCondition(uint8 DeviceIndex, uint16 Timeout);

extern Std_ReturnType WdgIf_SetMode(uint8 DeviceIndex, WdgIf_ModeType WdgMode);

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
Date               : 21-Aug-2015
CDSID              : ssebast1
Traceability       : RTC #396019
Change Description : Initial Framework version of WdgM
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/


