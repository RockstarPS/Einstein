/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2026 by Visteon Corporation.       All rights reserved.         
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
*    @file WdgIf_Lcfg.h
*    @ingroup WdgIf Configuration
*    @brief This is WdgIf Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the WdgIf module.
*    Auto generated code in vAUTOSAR TOOL by ABASAVAR at 2026-08-04 15:06:05.778301900
********************************************************************************************************************/

#ifndef WDGIF_LCFG_H
#define WDGIF_LCFG_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "WdgIf_Types.h"
#include "Std_Types.h"
#include "WdgIf.h"
#include "PmicCdd.h"

/*****************************************************************************
*  						 	 Version Information                             *
******************************************************************************/
/* Software Version */
#define WDGIF_CFG_SW_MAJOR_VERSION                                     1U
#define WDGIF_CFG_SW_MINOR_VERSION                                     0U
#define WDGIF_CFG_SW_PATCH_VERSION                                     0U
/* Autosar Release */
#define WDGIF_CFG_AR_RELEASE_MAJOR_VERSION                             4U
#define WDGIF_CFG_AR_RELEASE_MINOR_VERSION                             3U
#define WDGIF_CFG_AR_RELEASE_REVISION_VERSION                          1U
/*****************************************************************************
*                            Macro Definitions                          	 *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#define WDGIF_NUMBER_OF_DEVICES_SUPPORTED                              1U
#define WDGIF_DEV_ERROR_DETECT                                         STD_ON
#define WDGIF_VERSION_INFO_API                                         STD_OFF

/*****************************************************************************
*                            Type Declarations                               *
******************************************************************************/
 
typedef struct
{
    void (*SetTriggerPointer)(uint16 Timeout);
    Std_ReturnType (*SetModePointer)(WdgIf_ModeType Mode);
} WdgIf_FunctionPointerType;

/*****************************************************************************
*                            Globally used Variable Declarations             *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info	 *
* about the variable.                                                        *
* Purpose, critical section, unit, and resolution                            *
******************************************************************************/

extern const WdgIf_FunctionPointerType WdgIF_FunctionPointer[WDGIF_NUMBER_OF_DEVICES_SUPPORTED];

/*****************************************************************************
*                            Locally used Variable Declarations              *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info	 *
* about the variable.                                                        *
* Purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                     		 Externally used Variable Declarations           *
******************************************************************************/
		
/*****************************************************************************
*                            Limited Scope Prototypes                        *
******************************************************************************/
		
/*****************************************************************************
*                            Functions                                       *
******************************************************************************/

#endif /* WDGIF_LCFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

