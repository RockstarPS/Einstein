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
*    @file EcuM_Cfg.c 
*    @ingroup EcuM Configuration
*    @brief This is EcuM link time configuration source file. It contains definitions of link time
*    configuration parameters for the EcuM module.
*    Auto generated code in vAUTOSAR TOOL by ABASAVAR at 2026-08-17 19:03:24.823802900
********************************************************************************************************************/

#ifndef ECUM_CFG_C
#define ECUM_CFG_C

/******************************************************************************
*                            Include files                                    *
*******************************************************************************/
#include "EcuM_Cfg.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/*	{ ValidationTimeInMs, ComMChannel } WakeupSrc */
#define ECUM_WAKEUP_SOURCE_LIST \
	{ ECUM_NO_VALIDATION, ECUM_NO_COMM_CHANNEL },	\
	{ ECUM_NO_VALIDATION, ECUM_NO_COMM_CHANNEL },	\
	{ ECUM_NO_VALIDATION, ECUM_NO_COMM_CHANNEL },	\
	{ ECUM_NO_VALIDATION, ECUM_NO_COMM_CHANNEL },	\
	{ ECUM_NO_VALIDATION, ECUM_NO_COMM_CHANNEL },	\
	{ ECUM_NO_VALIDATION, ECUM_NO_COMM_CHANNEL },	\
	{ ECUM_NO_VALIDATION, ECUM_NO_COMM_CHANNEL },	\
	{ ECUM_NO_VALIDATION, ECUM_NO_COMM_CHANNEL },	\
	{ ECUM_NO_VALIDATION, ECUM_NO_COMM_CHANNEL }
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
/*	{ WakeupSources, McuMode, IsPollingAllowed }	*/
#define ECUM_SLEEP_MODE_LIST \
		{ (EcuM_WakeupSourceType)0xFFUL, ECUM_DEFAULT_SLEEP_MODE_REF, FALSE },	\
		{ (EcuM_WakeupSourceType)0x1FUL, ECUM_DEFAULT_SLEEP_MODE_REF, TRUE }	\

#define ECUM_COMM_CHANNEL_LIST \
		ECUM_NO_COMM_CHANNEL

#define ECUM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

const EcuM_WakeupSourceListType EcuM_WakeupSourceList[ECUM_MAX_NUM_WAKEUP_SOURCE] = {ECUM_WAKEUP_SOURCE_LIST};
const EcuM_SleepModeListType    EcuM_SleepModeList[ECUM_MAX_NUM_SLEEP_MODE] = {ECUM_SLEEP_MODE_LIST};
const EcuM_ComMChannelsType     EcuM_ComMChannels[ECUM_MAX_COM_CHANNELS] = {ECUM_COMM_CHANNEL_LIST};
const EcuM_ConfigType           EcuM_ConfigPtr = {NULL};
#if (ECUM_COMM_COMMUNICATION_ALLOWED != FALSE)
const EcuM_ComMChannelsType     EcuM_ComMAllowedChannels[ECUM_COMM_MAX_ALLOWED_LIST] = {ECUM_COMM_COMMUNICATION_ALLOWED_LIST};
#endif

#define ECUM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#endif

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

