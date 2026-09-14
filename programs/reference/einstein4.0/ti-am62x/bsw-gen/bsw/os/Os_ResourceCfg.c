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
*    Auto generated code in vAUTOSAR TOOL by SGOPAL1 at 2026-03-31 13:17:24.224064500
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
			(OsAppConfigRefType)(&OsAppConfig_TrustedSystem),
			(OsAppConfigRefType)(&OsAppConfig_QMSystem)
};

const TaskPriorityType OsMaxPrioQueueCount[OsMaxPriorityLevel] ={
	osdMaxTaskOfPrio0,
	osdMaxTaskOfPrio1,
	osdMaxTaskOfPrio2,
	osdMaxTaskOfPrio3,
	osdMaxTaskOfPrio4,
	osdMaxTaskOfPrio5,
	osdMaxTaskOfPrio6,
	osdMaxTaskOfPrio7,
	osdMaxTaskOfPrio8,
	osdMaxTaskOfPrio9,
	osdMaxTaskOfPrio10,
	osdMaxTaskOfPrio11,
	osdMaxTaskOfPrio12,
	osdMaxTaskOfPrio13,
	osdMaxTaskOfPrio14,
	osdMaxTaskOfPrio15,
	osdMaxTaskOfPrio16,
	osdMaxTaskOfPrio17,
	osdMaxTaskOfPrio18,
	osdMaxTaskOfPrio19,
	osdMaxTaskOfPrio20,
	osdMaxTaskOfPrio21,
	osdMaxTaskOfPrio22,
	osdMaxTaskOfPrio23,
	osdMaxTaskOfPrio24,
	osdMaxTaskOfPrio25,
	osdMaxTaskOfPrio26
};

static TaskType OsActivationQueuePrio0[osdMaxTaskOfPrio0+1]={0};
static TaskType OsActivationQueuePrio1[osdMaxTaskOfPrio1+1]={0};
static TaskType OsActivationQueuePrio2[osdMaxTaskOfPrio2+1]={0};
static TaskType OsActivationQueuePrio3[osdMaxTaskOfPrio3+1]={0};
static TaskType OsActivationQueuePrio4[osdMaxTaskOfPrio4+1]={0};
static TaskType OsActivationQueuePrio5[osdMaxTaskOfPrio5+1]={0};
static TaskType OsActivationQueuePrio6[osdMaxTaskOfPrio6+1]={0};
static TaskType OsActivationQueuePrio7[osdMaxTaskOfPrio7+1]={0};
static TaskType OsActivationQueuePrio8[osdMaxTaskOfPrio8+1]={0};
static TaskType OsActivationQueuePrio9[osdMaxTaskOfPrio9+1]={0};
static TaskType OsActivationQueuePrio10[osdMaxTaskOfPrio10+1]={0};
static TaskType OsActivationQueuePrio11[osdMaxTaskOfPrio11+1]={0};
static TaskType OsActivationQueuePrio12[osdMaxTaskOfPrio12+1]={0};
static TaskType OsActivationQueuePrio13[osdMaxTaskOfPrio13+1]={0};
static TaskType OsActivationQueuePrio14[osdMaxTaskOfPrio14+1]={0};
static TaskType OsActivationQueuePrio15[osdMaxTaskOfPrio15+1]={0};
static TaskType OsActivationQueuePrio16[osdMaxTaskOfPrio16+1]={0};
static TaskType OsActivationQueuePrio17[osdMaxTaskOfPrio17+1]={0};
static TaskType OsActivationQueuePrio18[osdMaxTaskOfPrio18+1]={0};
static TaskType OsActivationQueuePrio19[osdMaxTaskOfPrio19+1]={0};
static TaskType OsActivationQueuePrio20[osdMaxTaskOfPrio20+1]={0};
static TaskType OsActivationQueuePrio21[osdMaxTaskOfPrio21+1]={0};
static TaskType OsActivationQueuePrio22[osdMaxTaskOfPrio22+1]={0};
static TaskType OsActivationQueuePrio23[osdMaxTaskOfPrio23+1]={0};
static TaskType OsActivationQueuePrio24[osdMaxTaskOfPrio24+1]={0};
static TaskType OsActivationQueuePrio25[osdMaxTaskOfPrio25+1]={0};
static TaskType OsActivationQueuePrio26[osdMaxTaskOfPrio26+1]={0};

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
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio6
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio7
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio8
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio9
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio10
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio11
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio12
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio13
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio14
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio15
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio16
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio17
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio18
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio19
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio20
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio21
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio22
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio23
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio24
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio25
},
{
	/*.Head    =*/0,
	/*.Tail    =*/0,
	/*.pQueue  =*/OsActivationQueuePrio26
}
};

#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

