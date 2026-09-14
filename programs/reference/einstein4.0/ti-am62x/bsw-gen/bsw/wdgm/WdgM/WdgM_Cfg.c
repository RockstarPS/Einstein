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
*    @file WdgM_Cfg.c
*    @ingroup WdgM Configuration
*    @brief This is WdgM link time configuration source file. It contains definitions of link time
*    configuration parameters for the WdgM module.
*    Auto generated code in vAUTOSAR TOOL by ABASAVAR at 2026-08-04 14:40:34.221660
********************************************************************************************************************/

#ifndef WDGM_CFG_C
#define WDGM_CFG_C

/******************************************************************************
*                            Include files                                    *
*******************************************************************************/
#include "WdgM_Cfg.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*	{Num of Transitions, Transition Index}	*/
#define WDGM_DEADLINE_TRANSITION_LIST \
		{ 0, 0 } \

/*	{DeadlineMax, DeadlineMin, SourceCPID}	*/
#define WDGM_DEADLINE_SUPERVISION_LIST \
		{ 65535, 255, 0 } \

/*	{Expected, Max, Min, SupRefCycle}	*/
/*
	Expected - Expected alive count in reference Supervision cycle
	Max - Expected Upper Range (Max + Expected) is the max range
	Min - Expecetd Lower Range (Expecetd - Min) is the min range
	SupRefCycle - Alive check will be done every SupRefCycle*WdgM_MainFunction periodicity
*/
#define WDGM_ALIVE_SUPERVISION_LIST \
		{ 10, 12, 8, 10 }, \
		{ 10, 12, 8, 20 }, \
		{ 10, 12, 8, 30 }, \
		{ 10, 12, 8, 10 } \

/*	{WatchDog Trigger Condition Value}	*/
#define WDGM_TRIGGER_VALUE_LIST \
		{ 75 } \

/*	{Watchdog Mode, Alive Failed Tolerance, Deadline Failed Tolerance, Alive SE, Deadline SE,
	 Alive Supervision Index, Deadline Supervision Index, Local State Change Callback} 
*/
#define WDGM_SUPERVISED_ENTITY_LIST \
	    { WDGIF_SLOW_MODE, 0, 0, 4, 0, 0, 0, 0 } \

/*	{Initial Mode, OS Counter function pointer, Global State Change Callback, Num of SE, 
     Num of Watchdog Devices, Expired SE Tolerance, SE Reference, Trigger Reference}
*/
#define WDGM_CONFIG_PARAM_LIST \
		{ WDGIF_SLOW_MODE, NULL, NULL, 1, 1, 0, WdgMSupervisedEntity, WdgMTrigger } \

/*	{Watchdog Timeout Value}	*/
#define WDGM_TIMEOUT_VALUE_LIST \
	    { 512 } \

const WdgMDeadlineSupervisionType   WdgMDeadlineSupervision[WDGM_NO_OF_DEADLINE_ENTITIES] = \
                                    {WDGM_DEADLINE_SUPERVISION_LIST};

const WdgMDeadlineTransitionType    WdgMDeadlineTransition[WDGM_NO_OF_DEADLINE_TRANSITIONS] = \
                                    {WDGM_DEADLINE_TRANSITION_LIST};

const WdgMAliveSupervisionType      WdgMAliveSupervision[WDGM_NO_OF_ALIVE_ENTITIES] = \
                                    {WDGM_ALIVE_SUPERVISION_LIST};

const WdgMTriggerType               WdgMTrigger[WDGM_NO_OF_WDG_DEVICES] = \
                                    {WDGM_TRIGGER_VALUE_LIST};

const WdgMSupervisedEntityType      WdgMSupervisedEntity[WDGM_NO_OF_SUPERVISION_ENTITIES] = \
                                    {WDGM_SUPERVISED_ENTITY_LIST};

const WdgM_ConfigType               WdgM_ConfigParam[WDGM_NO_OF_CONFIGURATION_VARIANTS] = \
                                    {WDGM_CONFIG_PARAM_LIST};

const Wdgm_Timeout_Type 			Wdgm_Timeout[WDGM_NO_OF_WDG_DEVICES] = \
									{WDGM_TIMEOUT_VALUE_LIST};

/*****************************************************************************
*                               Functions                                    *
******************************************************************************/
#define WDGMGR_CODE_SEC_START
#include "MemMap.h"
void WdgM_EnterCriticalSection(void)
{
   	SuspendAllInterrupts();
}
void WdgM_ExitCriticalSection(void)
{
   	ResumeAllInterrupts();
}
#define WDGMGR_CODE_SEC_END
#include "MemMap.h"

#endif	

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

