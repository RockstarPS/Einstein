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
*    @file Os_CountersLcfg.c
*    @ingroup Os Configuration
*    @brief This is Os link time configuration source file. It contains definitions of link time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by MNATRAMI at 2026-04-06 16:31:56.372821600
********************************************************************************************************************/

#ifndef OSCOUNTERS_LCFG_C
#define OSCOUNTERS_LCFG_C


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/

#include "Os_Lcfg.h"


VAR(CounterParamType, OS_VAR) OsCounterParam_OsCounter_0Dyn = {0};
VAR(CounterParamType, OS_VAR) OsCounterParam_SystemTimerDyn = {0};


const CounterConfigType CounterConfig_OsCounter_0 =
{
OsCounter_0                             , /*OsCounterId*/
0xFFFF                                  , /*OsCounterMaxAllowedValue*/
0x1                                     , /*OsCounterMinCycle*/
0x1                                     , /*OsCounterTicksPerBase*/
HARDWARE                                , /*OsCounterType*/
0.001                                   , /*OsSecondsPerTick*/
(OsAppConfigRefType)NULL_PTR, /*OsCounterAccessingApplication*/
(CounterParamRefType)(&OsCounterParam_OsCounter_0Dyn)
};

const CounterConfigType CounterConfig_SystemTimer =
{
SystemTimer                             , /*OsCounterId*/
0xFFFF                                  , /*OsCounterMaxAllowedValue*/
0x1                                     , /*OsCounterMinCycle*/
0x1                                     , /*OsCounterTicksPerBase*/
HARDWARE                                , /*OsCounterType*/
0.001                                   , /*OsSecondsPerTick*/
(OsAppConfigRefType)NULL_PTR, /*OsCounterAccessingApplication*/
(CounterParamRefType)(&OsCounterParam_SystemTimerDyn)
};


const CounterConfigRefType CounterRefConfig[osMaxCounterId] = {
(CounterConfigRefType)&CounterConfig_OsCounter_0,
(CounterConfigRefType)&CounterConfig_SystemTimer
};




#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

