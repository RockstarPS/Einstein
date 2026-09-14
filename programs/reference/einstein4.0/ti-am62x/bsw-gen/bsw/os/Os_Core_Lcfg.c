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
*    @file Os_Core_Lcfg.c
*    @ingroup Os Configuration
*    @brief This is Os link time configuration source file. It contains definitions of link time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by SGOPAL1 at 2026-03-31 13:17:24.241157200
********************************************************************************************************************/

#ifndef OSCORE_LCFG_C
#define OSCORE_LCFG_C


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/

#include "Os_Lcfg.h"


CONST (OsCoreConfigType, OS_CONST) OsCoreConfig_OsCoreAsr0 =
{
	/*CoreId					= */ OS_CFG_CORE_CORE_0,
	/*IsAsrCore					= */ TRUE,
	/*NumOfApp					= */ OsNumberOfApplicationsCore0,
	/*pAppListRef				= */ (OsAppConfigRefType)OsCore0ApplicationRef,
	/*pOsCoreAppRef				= */ (OsAppConfigRefType)&(OsAppConfig_TrustedSystem),
	/*pOsCoreObjRef				= */ (OsObjConfigRefType)&OsObjConfig_OsKernel_OsCoreAsr0,
	/*OsHookConfigRefType		= */ (OsHookConfigRefType)&OsHookConfigList_Core0
};


CONST (OsAppConfigRefType, OS_CONST) OsCore0ApplicationRef[OsNumberOfApplicationsCore0] = {
    (OsAppConfigRefType)(&OsAppConfig_TrustedSystem),
    (OsAppConfigRefType)(&OsAppConfig_QMSystem)
};


const OsCoreConfigRefType OsCoreRefConfig[OsNumberOfCores] = 
{
(OsCoreConfigRefType)(&OsCoreConfig_OsCoreAsr0)
};




#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

