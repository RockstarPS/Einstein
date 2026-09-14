//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2015] Visteon Corporation
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
// Date: Tue Nov 24 15:48:04 EET 2015
// User: YDOBREV
// Configuration: DIAGNOSTICS
// Comment:
//      Configuration for TA 1.4
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef TMEXT_CFG_H
#define TMEXT_CFG_H


//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
// <TmExt_Cfg.h - BEGIN GENERATED SECTION FOR TIMER>
#define cTIMER16_LIST \
    eTimerHandle0, \
    eStepperWowHandle1, \
    eStepperWowHandle2, \
    eBtnMdlHandle, \
    eNvmExtHandle, \
    eWrnCtrlHandleObsIterator, \
    eWrnCtrlHandleObsReady, \
    eWrnCtrlHandleMinDispTime, \
    eWrnCtrlHandleOldWrnTime, \
    eHmiCtrlHandleETMEntry, \
    eHmiCtrlHandleETMFunc, \
    eHmiCtrlHandleObserver, \
    eSndCdd_SleepTimeout_Handle, \

#define cTIMER32_LIST \
    eTimerHandle6, \
    eTimerHandleGdtCdd, \
    eBtnMdlHandleDINBTN1, \
    eBtnMdlHandleDINBTN2, \
    eBtnMdlHandleDINBTN3, \
    eBtnMdlHandleDINBTN4, \
    eBtnMdlHandleCINBTN1, \
    eBtnMdlHandleCINBTN2, \
    eBtnMdlHandleCINBTN3, \
    eBtnMdlHandleCINBTN4, \
    eBtnMdlHandleCINBTN5, \
    eBtnMdlHandleSTUCKDINBTN1, \
    eBtnMdlHandleSTUCKDINBTN2, \
    eBtnMdlHandleSTUCKDINBTN3, \
    eBtnMdlHandleSTUCKDINBTN4, \
    eBtnMdlHandleSTUCKCINBTN1, \
    eBtnMdlHandleSTUCKCINBTN2, \
    eBtnMdlHandleSTUCKCINBTN3, \
    eBtnMdlHandleSTUCKCINBTN4, \
    eBtnMdlHandleSTUCKCINBTN5, \
    eTimerHandleTripMdl, \
    eWrnCtrlHandleRepeatWrn, \
    eWrnCtrlHandleOldWrnCycleTime, \

typedef enum HTimer_t
{
    cTIMER16_LIST
    cTIMER32_LIST
    eTimerMax
}HTimer;

#define cTIMER16_COUNT      (13UL)
#define cTIMER32_COUNT      ((uint32)eTimerMax - cTIMER16_COUNT)

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
#define GET_SYSTEM_TIMER() 			osGetSystemCounter()
//Timer configured at 60 MHZ
#define cGPT_TIMER 					GptConf_GptChannelConfiguration_GptChCfg_60MHzFRT
#define cTIMER_ROLLOVER_VALUE 		0xFFFFFFFFUL

// Shift to obtain the resolution of 60MHz timer - 16 ns: shift with 4 bits
#define cTIMER_RESOLUTION_MIN  		4u

// Register for the GPT counter for direct access - allows faster execution of BusyWait. HW specific.
// If the GPT timer is changed, the register address should be changed also.
#define cGPT_COUNTER_REG ((uint32*)(0xB4820004UL))

void TmExt_UpdateFreeRunningCounter( void );

#endif  // TMEXT_CFG_H
