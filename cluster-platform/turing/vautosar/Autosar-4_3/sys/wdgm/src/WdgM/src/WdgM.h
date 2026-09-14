/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2017. Visteon Corporation owns all rights to           *
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
*  File Name         :  WdgM.h                                               *
*  Module Short Name :  WdgM_H                                               *
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
#ifndef WDGM_H
#define WDGM_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Std_Types.h"
#include "WdgM_Types.h"
#include "WdgM_PrivateCfg.h"
#include "WdgM_Cfg.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define WDGM_VENDOR_ID						0x33U
#define WDGM_MODULE_ID                      13U
#define WDGM_AR_RELEASE_MAJOR_VERSION       4U
#define WDGM_AR_RELEASE_MINOR_VERSION       3U
#define WDGM_AR_RELEASE_REVISION_VERSION    1U
#define WDGM_SW_MAJOR_VERSION               1U
#define WDGM_SW_MINOR_VERSION               0U
#define WDGM_SW_PATCH_VERSION               0U
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
#define WDGMGR_CODE_SEC_START
#include "MemMap.h"

#if (WDGM_VERSION_INFO_API == TRUE)
extern FUNC(void, WDGMGR_CODE_SEC_START)WdgM_GetVersionInfo(Std_VersionInfoType* VersionInfo);
#endif
extern FUNC(void, WDGMGR_CODE_SEC_START)WdgM_Init (const WdgM_ConfigType* ConfigPtr);
extern FUNC(void, WDGMGR_CODE_SEC_START) WdgM_DeInit(void);
extern FUNC(Std_ReturnType, WDGMGR_CODE_SEC_START) WdgM_SetMode(WdgM_ModeType Mode, uint16 CallerID);
extern FUNC(Std_ReturnType, WDGMGR_CODE_SEC_START) WdgM_GetMode(WdgM_ModeType* Mode);
extern FUNC(Std_ReturnType, WDGMGR_CODE_SEC_START) WdgM_CheckpointReached(WdgM_SupervisedEntityIdType SEID, WdgM_CheckpointIdType CheckpointID);
extern FUNC(Std_ReturnType, WDGMGR_CODE_SEC_START) WdgM_GetLocalStatus(WdgM_SupervisedEntityIdType SEID, WdgM_LocalStatusType* Status);
extern FUNC(Std_ReturnType, WDGMGR_CODE_SEC_START) WdgM_GetGlobalStatus(WdgM_GlobalStatusType* Status);
extern FUNC(Std_ReturnType, WDGMGR_CODE_SEC_START) WdgM_GetFirstExpiredSEID(WdgM_SupervisedEntityIdType* SEID);
extern FUNC(void, WDGMGR_CODE_SEC_START) WdgM_MainFunction(void);
extern FUNC(void, WDGMGR_CODE_SEC_START) WdgM_PerformReset(void );

#define WDGMGR_CODE_SEC_END
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
Date               : 21-Aug-2015
CDSID              : ssebast1
Traceability       : RTC #396019
Change Description : Initial Framework version of WdgM
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/


