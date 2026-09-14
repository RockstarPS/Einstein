//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2017] Visteon Corporation
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
//
// File generated automatically using Visteon TmExt Configurator 1.0
// Date:           Tue May 30 11:41:40 EEST 2017
// User:           iulivero
// Configuration:  RSA1025
// Comment:
//      Configuration for TA 1.5
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef TMEXT_CFG_H
#define TMEXT_CFG_H

#define TMEXT_MAINFUNCTION_PERIODICITY  10
//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
// <TmExt_Cfg.h - BEGIN GENERATED SECTION FOR TIMER>

// <TmExt_Cfg.h - END GENERATED SECTION FOR TIMER>

//----------------------------------------------------------------------------------------------------------------------
// TmExt_Pulse configuration
//----------------------------------------------------------------------------------------------------------------------

// <TmExt_Cfg.h - BEGIN GENERATED SECTION FOR PULSE>


//----------------------------------------------------------------------------------------------------------------------
// UML::TPulseClientId
//----------------------------------------------------------------------------------------------------------------------
#define eClientUnitTest1        ((TPulseClientId) 0)
#define eClientUnitTest2        ((TPulseClientId) 1)
#define eClientUnitTest3        ((TPulseClientId) 2)
#define eClientUnitTest4        ((TPulseClientId) 3)
#define eClientGdtCtrl        ((TPulseClientId) 4)
#define eClientSndView        ((TPulseClientId) 5)
#define eClientTtView        ((TPulseClientId) 6)
#define eClientCount        ((TPulseClientId) 7)

//----------------------------------------------------------------------------------------------------------------------
// UML::TPulseChannelId
//----------------------------------------------------------------------------------------------------------------------
#define ePulseChannelTestChannel0        ((TPulseChannelId) 0 )
#define ePulseChannelTestChannel1        ((TPulseChannelId) 1 )
#define ePulseChannelTestChannel2        ((TPulseChannelId) 2 )
#define ePulseChannelTestChannel3        ((TPulseChannelId) 3 )
#define ePulseChannelChnl1Hz        ((TPulseChannelId) 4 )
#define ePulseChannelCount        ((TPulseChannelId) 5)



// <TmExt_Cfg.h - END GENERATED SECTION FOR PULSE>

//----------------------------------------------------------------------------------------------------------------------
// TmExt_BusyWait configuration
//----------------------------------------------------------------------------------------------------------------------
// HW specific options:

#define GET_SYSTEM_TIMER(Value) 			(void)GetCounterValue(SystemTimer,(Value))
//Timer configured
#define cGPT_TIMER 					GptConf_GptChannelConfiguration_GptChCfg_60MHzFRT
#define cTIMER_ROLLOVER_VALUE 		0xFFFFFFFFUL

// Resolution of the timer
#define cTIMER_RESOLUTION_MIN  		13u // Time of the tick of the timer in [ns]

void TmExt_UpdateFreeRunningCounter( void );

#endif  // TMEXT_CFG_H
