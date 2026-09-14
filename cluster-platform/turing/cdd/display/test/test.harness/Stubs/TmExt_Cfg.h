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

/*!*************************************************************************************************
   @file TmExt_Cfg.$h
   @brief Timer Extension Configuration Parameters.
***************************************************************************************************/

#ifndef TMEXT_CFG_H
#define TMEXT_CFG_H
#include "Os.h"
#include "Gpt.h"
#include "Rte_Type.h"
/***************************************************************************************************
*    P U B L I C   M A C R O  D E F I N I T I O N S                                                *
***************************************************************************************************/
#ifndef VCONST
#define VCONST  const

#endif

#define UINT32_MX_VALUE   0xFFFFFFFFU

//User has to configure the 16bit & 32bit timers list in the "HTimer" data type in DaVinci.
//user has to also update the total number of 16bit timers count in the configuration parameter "eMaxNumof16BitTimers" in DaVinci
//Also user needs to update the total timers count in the configuration parameter "eTimerMax" in DaVinci.

//User could configure maximum of 100timers only


typedef struct Gpt_ChannelConfigTypeStruct
{
  volatile CONSTP2VAR(uint32, GPT_CONST, REGSPACE)  BaseAddr;           /* base address */
}Gpt_ChannelConfig;


#define Gpt_ConfigType Gpt_ConfigType2
#undef Gpt_ConfigType2

typedef struct
{
    uint32 TMExt_TmStartTime;
    uint32 TMExt_TmCurrentTime;
    uint32 TMExt_TmElapsedTime;
}TMExt_AdminDataType;

typedef struct
{
  P2CONST(Gpt_ChannelConfig, AUTOMATIC, GPT_CONST)     channels;    /* channel's configuration information */
  uint8                                                    nChannels;   /* number of channel */
  uint8                                                    ApbIfFlag;   /* APB interface flag */
} Gpt_ConfigType;

extern Gpt_ConfigType* Gpt_GetConfigData(void);

/*Markers to measure the timings*/
typedef enum{
eStartupMarker_CANFirstTXTranmission = 0,
eStartupMarker_CANFirstRXReception,
eStartupMarker_NvMReadAllStart,
eStartupMarker_CXPIFirstTxTransmission,
eStartupMarker_ModeMgrPowerUpCompletion,
eStartupMarker_NvMPhase1ReadCompletion,
eStartupMarker_NvMReadCompletion,
eStartupMarker_BacklightBrightnessUp,
eStartupMarker_AllAppStarted,
eStartupMarker_HMIOn_ScreenRenderStarted,
eStartupMarker_HMI_FullScreenUp,
estartupMarker_Max
}startupmarkers;

typedef struct
{
uint32 timestamp;
}timer_marker;

extern timer_marker timer_startupmarker[estartupMarker_Max];
 
/*ssebast1; Dummy define for build... Need to remove once generated from RTE */
#define Rte_Call_tiCS_TITmExt_Notify_Notification(x) (x=0)

#ifndef Rte_TypeDef_EPulsePhase
# define Rte_TypeDef_EPulsePhase
typedef uint8 EPulsePhase;
#endif

#ifndef Rte_TypeDef_TPulseChannelId
# define Rte_TypeDef_TPulseChannelId
typedef uint8 TPulseChannelId;
#endif

#ifndef Rte_TypeDef_TPulseClientId
#define Rte_TypeDef_TPulseClientId
typedef uint8 TPulseClientId;
#endif

#ifndef Rte_TypeDef_SPulseNotification
# define Rte_TypeDef_SPulseNotification
typedef struct
{
  TPulseChannelId Channel;
  EPulsePhase Phase;
} SPulseNotification;
#endif

#  ifndef ePulsePhase_Off
#   define ePulsePhase_Off (0U)
#  endif

#  ifndef ePulsePhase_On
#   define ePulsePhase_On (1U)
#  endif

#  ifndef ePulsePhase_Any
#   define ePulsePhase_Any (2U)
#  endif

#  ifndef eMaxNumof16BitTimers
#   define eMaxNumof16BitTimers (2U)
#  endif

#  ifndef eTimerMax
#   define eTimerMax (5U)
#  endif
/**
* @brief Periodicity of TmExt MainFunction in milliseconds
*/
#define TMEXT_MAINFUNCTION_PERIODICITY   10
#define TM_EXT_TIMER_FRQ                       60     /*MHz*/
#define TMEXT_GET_CURRENT_TIME_IN_US           (Gpt_GetTimeElapsed (GptConf_GptChannelConfiguration_TmExt))/TM_EXT_TIMER_FRQ

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

/**
* @brief Os Interface for getting the system timer value in milliseconds
*/
#define GET_SYSTEM_TIMER(Value) 			(void)GetCounterValue(SystemTimer,(TickRefType)(Value))

/**
* @brief GPT Free Running Timer channel ID
*/
//Timer configured at 60 MHZ
#define cGPT_TIMER 					GptConf_GptChannelConfiguration_TmExt


/**
* @brief Timer Rollover or max count value
*/
#define cTIMER_ROLLOVER_VALUE 		0xFFFFFFFFUL


/**
* @brief Timer Resolution - Shift to obtain the resolution of 60MHz timer - 16 ns: shift with 4 bits
*/
//
#define cTIMER_RESOLUTION_MIN  		4u

/**
* @brief 	Service ID defined.
*/
#define TMEXT_API_BUSYWAIT1NS          (0x00U)
#define TMEXT_API_MAINFUNCTION         (0x01U)
#define TMEXT_API_SYNCCHANNELS          (0x02U)

/**
* @brief 	Error information defined.
*/
#define TMEXT_E_PARAM_POINTER          (0x01U) /* Pointer is a NULL pointer */

/**
* @brief 	GPT FRT Timer callback notification.
*/
void TmExt_UpdateFreeRunningCounter( void );

/**
* @brief 	Det error report .
*/
void TmExt_ReportDetError(uint32 ApiId, uint32 ErrorID); 
#endif  // TMEXT_CFG_H

/*---------------------------------------------------------------------------
Date              : 11-May-2018
CDSID             : asivalin
Traceability      : RTC-1109220, 1199221, 1116707, 1116694
Change Description: Timer Elapsed Defectes Fix & QAC, Coverity Warnings Fix and doxygen documentation.
Version           : 3:turing_bsw_tmext_0.2
-----------------------------------------------------------------------------*/
