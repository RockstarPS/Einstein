/****************************************************************
*              CONFIDENTIAL VISTEON CORPORATION
*
* This is an unpublished work of authorship, which contains trade secrets,
* created in 2012. Visteon Corporation owns all rights to this work and
* intends to maintain it in confidence to preserve its trade secret status.
* Visteon Corporation reserves the right, under the copyright laws of the
* United States or those of any other country that may have  jurisdiction,
* to protect this work as an unpublished work, in the event of an
* inadvertent or deliberate unauthorized publication. Visteon Corporation
* also reserves its rights under all copyright laws to protect this work as
* a published work, when appropriate. Those having access to this work may
* not copy it, use it, modify it or disclose the information contained in
* it without the written authorization of Visteon Corporation
*
****************************************************************/
#ifndef LINTRCVCDD_PAR_CFG_H
#define LINTRCVCDD_PAR_CFG_H

#include "LinTrcv_Types.h"
/*=============================================================================
*
*  Name:               LinTrcv_Par_Cfg.h
*
*  Description:
*
*  Comments:
*
*
*  Organization:       Driver Information Core Software,
*                      Visteon Automotive Systems
**==========================================================================*/

//=====================================================================================================================
//  P U B LI C    M A C R O
//=====================================================================================================================
#define LINTRCV_TRCVMODE_NORMAL LINTRCV_OP_MODE_NORMAL
#define LINTRCV_TRCVMODE_SLEEP  LINTRCV_OP_MODE_SLEEP

#define LinTrcv_GetChannelUsedOfPCConfig()             LinTrcv_ChannelUsed
#define LinTrcv_GetInitStateConfigurationofPCConfig()  LinTrcv_InitState
#define LinTrcv_GetDioConfigurationOfPCConfig()        LinTrcv_DioConfiguration
#define LinTrcv_GetICUChannelOfPCConfig()              LinTrcv_Icu_Channel
#define LinTrcv_GetIsWakeupByBusUsedOfPCConfig()       LinTrcv_WakeupByBusUsed
#define LinTrcv_GetIsWakeupByPinUsedOfPCConfig()       LinTrcv_WakeupByPinUsed
#define LinTrcv_GetEcuMWakeupSourceIdOfPCConfig()      LinTrcv_WakeSourceId

#endif
/*============================================================================
**Date               : 22-Jul-2019
**CDSID              : ABAVALAT
**Traceability       : 
**Change Description : Initial Version.
**============================================================================*/

