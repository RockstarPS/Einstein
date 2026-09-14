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
*    @file Os_ResourceCfg.c
*    @ingroup Os Configuration
*    @brief This is Os link time configuration source file. It contains definitions of link time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by MNATRAMI at 2026-04-06 16:31:56.327436800
********************************************************************************************************************/

#ifndef OS_RESOURCELCFG_C
#define OS_RESOURCELCFG_C


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/
                                                                              
#include "Os_Lcfg.h"


const OsResConfigType OsResConfig_RES_SCHEDULER =
{
	/*ResId						= */ RES_SCHEDULER,
	/*Type						= */ OS_RES_TYPE_STANDARD,
	/*CeilingPrio				= */ 0U,
	/*pAppListRef				= */ (OsAppConfigRefType *)&OsRes0ApplicationRef,
	/*NumofpAppRef				= */ OsNumberOfApplicationsSchedRes0
};


const OsResConfigRefType OsResRefConfig[NumberOfResources] = {
(OsResConfigRefType)&OsResConfig_RES_SCHEDULER
};

const OsAppConfigRefType OsRes0ApplicationRef[OsNumberOfApplicationsSchedRes0]= {
			(OsAppConfigRefType)(&OsAppConfig_TrustedSystem)
};

const TaskPriorityType OsMaxPrioQueueCount[OsMaxPriorityLevel] ={
	osdMaxTaskOfPrio0,
	osdMaxTaskOfPrio1,
	osdMaxTaskOfPrio2,
	osdMaxTaskOfPrio3,
	osdMaxTaskOfPrio4,
	osdMaxTaskOfPrio5
};

static TaskType OsActivationQueuePrio0[osdMaxTaskOfPrio0+1]={0};
static TaskType OsActivationQueuePrio1[osdMaxTaskOfPrio1+1]={0};
static TaskType OsActivationQueuePrio2[osdMaxTaskOfPrio2+1]={0};
static TaskType OsActivationQueuePrio3[osdMaxTaskOfPrio3+1]={0};
static TaskType OsActivationQueuePrio4[osdMaxTaskOfPrio4+1]={0};
static TaskType OsActivationQueuePrio5[osdMaxTaskOfPrio5+1]={0};

OsprioQueueType OsPriorityQueueDyn[OsMaxPriorityLevel] = {
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio0
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio1
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio2
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio3
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio4
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio5
}
};

#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

