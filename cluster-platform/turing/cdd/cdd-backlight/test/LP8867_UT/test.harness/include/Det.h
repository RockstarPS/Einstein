/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2024. Visteon Corporation owns all rights to           *
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
*  File Name         :  Det.h                                               *
*  Module Short Name :  DET_H                                               *
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
#ifndef DET_H
#define DET_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
# include "Std_Types.h"
# include "Det_Cfg.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/* Autosar Version */
#define DET_AR_RELEASE_MAJOR_VERSION 		4
#define DET_AR_RELEASE_MINOR_VERSION        2

#define DET_VENDOR_ID                       (51u)
#define DET_MODULE_ID                       (15u)
#define DET_INSTANCE_ID                     (0U)
#define DET_SW_MAJOR_VERSION                (1u)
#define DET_SW_MINOR_VERSION                (0u)    
#define DET_SW_PATCH_VERSION                (0u)

#define DET_INIT                             1U
#define DET_UNINIT                           0U
#define DET_GETVERSIONINFO_API               0x03U
#define DET_E_PARAM_POINTER                  0x01U

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

#define DET_CODE_SEC_START
#include "MemMap.h"

extern FUNC(void, DET_CODE_SEC_START) Det_Init(Det_ConfigType* ConfigPtr);
extern FUNC(void, DET_CODE_SEC_START) Det_Start(void);
extern FUNC(void, DET_CODE_SEC_START) Det_InitMemory(void);
extern FUNC(Std_ReturnType, DET_CODE_SEC_START) Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);
extern FUNC(Std_ReturnType, DET_CODE_SEC_START) Det_ReportRuntimeError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );
extern FUNC(Std_ReturnType, DET_CODE_SEC_START) Det_ReportTransientFault( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );

#if (DET_VERSION_INFO_API == TRUE)
extern FUNC(void, DET_CODE_SEC_START) Det_GetVersionInfo (Std_VersionInfoType* VersionInfo);
#endif

#define DET_CODE_SEC_STOP
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
Date               : 22-Aug-2019
CDSID              : ssebast1
Traceability       : 
Change Description : Initial Framework version of Det
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 28-Mar-2020
CDSID              : ssebast1
Traceability       : RTC #806059
Change Description : Autosar Version Added
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 14-Dec-2022
CDSID              : sjain10
Traceability       : 1790320: [Basic8_MP23] DiId_04d@4082- Identifikation nicht verfügbar
Change Description : Version Info and Vendor ID Update
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 25-Mar-2024
CDSID              : eganesan
Traceability       : DICVA-1945 : 4.3 Migration
Change Description : vAutosar 4.3 Migration
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/


