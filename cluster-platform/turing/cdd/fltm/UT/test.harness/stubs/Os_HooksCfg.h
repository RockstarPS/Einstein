/******************************************************************************
**              CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2025. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have  jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation
**
******************************************************************************/

/******************************************************************************

File Name        :  Os_HooksCfg.h
Module Short Name:  Os_HooksCfg.h
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef OS_HOOKSCFG_H
#define OS_HOOKSCFG_H


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/
                                                                              
#include "Stubs.h"
#include "OsError.h"
#include "OsPrvTypes.h"
#include "Det.h"
 
                                                                              
                                                                              
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
*****************************************************************************/


#define OsCfgStartUpHook()       NULL_PTR
#define OsCfgShutdownHook()       UserShutdownHook()
#define OsCfgPreTaskHook()       UserPreTaskHook()
#define OsCfgPostTaskHook()       UserPostTaskHook()
#define OsCfgPreISRHook(x)       UserPreISRHook(x)
#define OsCfgPostISRHook(x)       UserPostISRHook(x)
#define OsCfgErrorHook(x)       FltMExt_UserErrorHook(x)
#define OsCfgProtectionHook(x)       FltMExt_UserProtectionHook(x)
#define OsCfgCriticalSectionStartHook()       NULL_PTR
#define OsCfgCriticalSectionStoptHook()       NULL_PTR
#define OsCfgCheckSelfTest()       NULL_PTR

#endif    /* */
/* end of file */
/****************************************************************
Created Time: 21-08-2025 13:13:07
****************************************************************/
