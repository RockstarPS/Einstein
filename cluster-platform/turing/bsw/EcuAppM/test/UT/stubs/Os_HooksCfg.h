/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2025 by Visteon Corporation.       All rights reserved.         
*                                                                                                                    
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                   
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve              
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States     
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,             
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its       
* rights under all copyright laws to protect this work as a published work, when appropriate.                        
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it   
* without the written authorization of Visteon Corporation.                                                          
********************************************************************************************************************/

/*******************************************************************************************************************
*    @file Os_HooksCfg.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by SJOHNY at 2025-12-05 15:58:47.348231800
********************************************************************************************************************/

#ifndef OS_HOOKSCFG_H
#define OS_HOOKSCFG_H


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/

#include "Stubs.h"
#include "Det.h"

#ifndef WIN32
#include "SafeBsw.h"
#endif

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
*****************************************************************************/

#define OsCfgStartUpHook()				Dummy_StartUpHook()
#define OsCfgShutdownHook()				EcuM_Shutdown()
#define OsCfgPreTaskHook()				PreTaskHook()
#define OsCfgPostTaskHook()				PostTaskHook()
#define OsCfgPreISRHook(x)				UserPreISRHook(x)
#define OsCfgPostISRHook(x)				UserPostISRHook(x)
#define OsCfgErrorHook(x)				Dummy_ErrorHook()
#define OsCfgProtectionHook(x)			SafeBswHook_OsProtectionErrorHook(x)
#define OsCfgCriticalSectionStartHook()			Dummy_Critical_StartHook()
#define OsCfgCriticalSectionStoptHook()			Dummy_Critical_StoptHook()
#define OsCfgCheckSelfTest()		SELF_TEST_ACTIVE

#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

