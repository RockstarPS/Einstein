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
*    @file Os_Alarm_Lcfg.c
*    @ingroup Os Configuration
*    @brief This is Os link time configuration source file. It contains definitions of link time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by MNATRAMI at 2026-04-06 16:31:56.335514900
********************************************************************************************************************/

#ifndef OSALARM_LCFG_C
#define OSALARM_LCFG_C


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/

#include "Os_Lcfg.h"

VAR(OsAlarmParamType, OS_VAR) OsAlarmParam_Rte_Al_TE2_OsTask_Diagnostics_0_10msDyn = {0};
VAR(OsAlarmParamType, OS_VAR) OsAlarmParam_Rte_Al_TE2_OsTask_Ucl_0_4msDyn = {0};
VAR(OsAlarmParamType, OS_VAR) OsAlarmParam_Rte_Al_TE2_OsTask_CANFun_0_10msDyn = {0};
VAR(OsAlarmParamType, OS_VAR) OsAlarmParam_Rte_Al_TE2_OsTask_WdgMngt_0_500msDyn = {0};


const AlarmConfigType AlarmConfig_Rte_Al_TE2_OsTask_Diagnostics_0_10ms =
{
	(OsAppConfigRefType)NULL_PTR, /*OsAlarmAccessingApplication*/
	(CounterConfigRefType)&CounterConfig_SystemTimer          , /*OsAlarmCounterRef*/
	NULL_PTR                                , /*OsAlarmActivateTaskRef*/
	(OsAlarmParamRefType)(&OsAlarmParam_Rte_Al_TE2_OsTask_Diagnostics_0_10msDyn)          , /*OsAlarmAutostart*/
	osCbkOfAlarm_0                          , /*OsAlarmCallbackName*/
	NULL_PTR                                , /*OsAlarmIncrementCounterRef*/
	osTaskIdOfAlarm_0                       , /*OsAlarmSetEventTaskRef*/
	osActionOfAlarm_0                       , /*osActionOfAlarm*/
	osEventIdOfAlarm_0                       /*OsAlarmSetEventRef*/
};

const AlarmConfigType AlarmConfig_Rte_Al_TE2_OsTask_Ucl_0_4ms =
{
	(OsAppConfigRefType)NULL_PTR, /*OsAlarmAccessingApplication*/
	(CounterConfigRefType)&CounterConfig_SystemTimer          , /*OsAlarmCounterRef*/
	NULL_PTR                                , /*OsAlarmActivateTaskRef*/
	(OsAlarmParamRefType)(&OsAlarmParam_Rte_Al_TE2_OsTask_Ucl_0_4msDyn)          , /*OsAlarmAutostart*/
	osCbkOfAlarm_1                          , /*OsAlarmCallbackName*/
	NULL_PTR                                , /*OsAlarmIncrementCounterRef*/
	osTaskIdOfAlarm_1                       , /*OsAlarmSetEventTaskRef*/
	osActionOfAlarm_1                       , /*osActionOfAlarm*/
	osEventIdOfAlarm_1                       /*OsAlarmSetEventRef*/
};

const AlarmConfigType AlarmConfig_Rte_Al_TE2_OsTask_CANFun_0_10ms =
{
	(OsAppConfigRefType)NULL_PTR, /*OsAlarmAccessingApplication*/
	(CounterConfigRefType)&CounterConfig_SystemTimer          , /*OsAlarmCounterRef*/
	NULL_PTR                                , /*OsAlarmActivateTaskRef*/
	(OsAlarmParamRefType)(&OsAlarmParam_Rte_Al_TE2_OsTask_CANFun_0_10msDyn)          , /*OsAlarmAutostart*/
	osCbkOfAlarm_2                          , /*OsAlarmCallbackName*/
	NULL_PTR                                , /*OsAlarmIncrementCounterRef*/
	osTaskIdOfAlarm_2                       , /*OsAlarmSetEventTaskRef*/
	osActionOfAlarm_2                       , /*osActionOfAlarm*/
	osEventIdOfAlarm_2                       /*OsAlarmSetEventRef*/
};

const AlarmConfigType AlarmConfig_Rte_Al_TE2_OsTask_WdgMngt_0_500ms =
{
	(OsAppConfigRefType)NULL_PTR, /*OsAlarmAccessingApplication*/
	(CounterConfigRefType)&CounterConfig_SystemTimer          , /*OsAlarmCounterRef*/
	NULL_PTR                                , /*OsAlarmActivateTaskRef*/
	(OsAlarmParamRefType)(&OsAlarmParam_Rte_Al_TE2_OsTask_WdgMngt_0_500msDyn)          , /*OsAlarmAutostart*/
	osCbkOfAlarm_3                          , /*OsAlarmCallbackName*/
	NULL_PTR                                , /*OsAlarmIncrementCounterRef*/
	osTaskIdOfAlarm_3                       , /*OsAlarmSetEventTaskRef*/
	osActionOfAlarm_3                       , /*osActionOfAlarm*/
	osEventIdOfAlarm_3                       /*OsAlarmSetEventRef*/
};





const AlarmConfigRefType AlarmRefConfig[OsNumberOfAlarms] =
{
(AlarmConfigRefType)&AlarmConfig_Rte_Al_TE2_OsTask_Diagnostics_0_10ms,
(AlarmConfigRefType)&AlarmConfig_Rte_Al_TE2_OsTask_Ucl_0_4ms,
(AlarmConfigRefType)&AlarmConfig_Rte_Al_TE2_OsTask_CANFun_0_10ms,
(AlarmConfigRefType)&AlarmConfig_Rte_Al_TE2_OsTask_WdgMngt_0_500ms
};



#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

