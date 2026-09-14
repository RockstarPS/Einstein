//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2016] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef __ECUWAKEUPM_H__
#define __ECUWAKEUPM_H__


//=====================================================================================================================
//  INCLUDED FILES
//=====================================================================================================================
#include "EcuWakeupM_Types.h"
#include "EcuWakeupM_Defines.h"
#include "EcuWakeupM_Version.h"
#include "EcuWakeupM_Cfg.h"


//----------------------------------------------------------------------------------------------------------------------
// Constant data
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Exported type
//----------------------------------------------------------------------------------------------------------------------
	   
//----------------------------------------------------------------------------------------------------------------------
// Exported data
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Constant exported data
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Exported Macros
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Exported functions
//----------------------------------------------------------------------------------------------------------------------
extern FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_Init(void);
extern FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_EnableWakeup(VAR(EcuWakeupM_ChannelType, AUTOMATIC) Channel,
	        VAR(EcuWakeupM_NotifyStatusType, AUTOMATIC) NotifyStatus);
extern FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_DisableWakeup(VAR(EcuWakeupM_ChannelType, AUTOMATIC) Channel);
extern FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_EnableAllWakeups(VAR(EcuWakeupM_NotifyStatusType, AUTOMATIC) NotifyStatus);
extern FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_DisableAllWakeups(void);
extern FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_SetNotification(VAR(EcuWakeupM_ChannelType, AUTOMATIC) Channel,
		    VAR(EcuWakeupM_NotifyStatusType, AUTOMATIC) NotifyStatus);
extern FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_ManageWakeup(VAR(EcuWakeupM_ChannelType,AUTOMATIC) Channel);
extern FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_CheckWakeup(VAR(EcuWakeupM_EcuMWakeupSourceType,AUTOMATIC) WakeupSource);
extern FUNC(void, ECUWAKEUPM_CODE)EcuWakeupM_GetWakeupChannel(VAR(EcuWakeupM_EcuMWakeupSourceType,AUTOMATIC) WakeupSource,
	        P2VAR(EcuWakeupM_ChannelType, AUTOMATIC, ECUWAKEUPM_APPL_DATA) ChannelData);
extern FUNC(void, ECUWAKEUPM_CODE)EcuWakeupM_ScanWakeupChannel(VAR(EcuWakeupM_ChannelType, AUTOMATIC) Channel);
extern FUNC(void, ECUWAKEUPM_CODE)EcuWakeupM_ScanAllWakeupChannels(void);
extern FUNC(EcuWakeupM_WakeupReportStatusType, ECUWAKEUPM_CODE)EcuWakeupM_ReportWakeupSource(VAR(EcuWakeupM_ChannelType, AUTOMATIC) Channel);
extern FUNC(void, ECUWAKEUPM_CODE)EcuWakeupM_ReportAllWakeupSources(void);

#endif  // __ECUWAKEUPM_H__

/*==============================================================================================================================================
Date              	: 13-11-23
CDSID             	: skiranku
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/
