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
*    @file WdgIf_Lcfg.c
*    @ingroup WdgIf Configuration
*    @brief This is WdgIf link time configuration source file. It contains definitions of link time
*    configuration parameters for the WdgIf module.
*    Auto generated code in vAUTOSAR TOOL by ABASAVAR at 2026-08-04 15:06:05.782240600
********************************************************************************************************************/

#ifndef WDGIF_LCFG_C
#define WDGIF_LCFG_C

/******************************************************************************
*                            Include files                                    *
*******************************************************************************/
#include "WdgIf_Lcfg.h"
#include "WdgMExt.h"
/*****************************************************************************
*                            Macro Definitions                               *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/*****************************************************************************
*                            Type Declarations                               *
******************************************************************************/

/*****************************************************************************
*                            Globally used Variable Declarations             *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info	 *
* about the variable.                                                        *
* Purpose, critical section, unit, and resolution                            *
******************************************************************************/
const WdgIf_FunctionPointerType WdgIF_FunctionPointer[WDGIF_NUMBER_OF_DEVICES_SUPPORTED] =
{
	/* 
	{ 
		Trigger Condition, 
		Mode
	} 
	*/
	{ 
		WdgmExt_SetTriggerCondition,
		WdgmExt_SetMode 
	}
};

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

#endif /* WDGIF_LCFG_C */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

