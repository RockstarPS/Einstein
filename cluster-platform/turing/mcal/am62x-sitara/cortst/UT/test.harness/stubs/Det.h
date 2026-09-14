/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2019. Visteon Corporation owns all rights to           *
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

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

extern void Det_Init(Det_ConfigType* ConfigPtr);
extern void Det_Start(void);
extern void Det_InitMemory(void);
extern Std_ReturnType Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);
extern Std_ReturnType Det_ReportRuntimeError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );
extern Std_ReturnType Det_ReportTransientFault( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );


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
/* end of file =============================================================*/


