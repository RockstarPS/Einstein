/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2013. Visteon Corporation owns all rights to           *
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
*  File Name         :  EcuM_Cbk.h                                           *
*  Module Short Name :  EcuM_Cbk_H                                           *
*  Description       :  This file contains prototypes for callbacks from     *
*                       EcuMgr                                               *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  Indpendent                                             *
*                                                                            *
******************************************************************************/
#ifndef ECUM_CBK_H
#define ECUM_CBK_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "EcuM_Types.h"
# include "Rte_EcuM_Type.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/* Autosar Version */
# define ECUM_CBK_AR_RELEASE_MAJOR_VERSION	(4u)
# define ECUM_CBK_AR_RELEASE_MINOR_VERSION	(2u)

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

#define ECUM_START_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern void EcuM_CheckWakeup ( EcuM_WakeupSourceType wakeupSource );
extern void EcuM_SetWakeupEvent(EcuM_WakeupSourceType sources);
extern void EcuM_ValidateWakeupEvent(EcuM_WakeupSourceType sources);
extern void EcuM_CB_NfyNvMJobEnd(uint8 ServiceId,NvM_RequestResultType JobResult);

#define ECUM_STOP_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

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
Date               : 20-Aug-2015
CDSID              : ssukuma1
Traceability       : RTC #396021
Change Description : Initial Framework version of EcuMgr
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 28-Mar-2020
CDSID              : ssebast1
Traceability       : RTC #806059
Change Description : Autosar Version Added
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/


