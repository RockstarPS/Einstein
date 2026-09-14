//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2020] Visteon Corporation
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

#ifndef _SLEEPMANAGER_H
#define _SLEEPMANAGER_H

#include "Std_Types.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
#  ifndef eRtcCddCalibSts_Completed
#   define eRtcCddCalibSts_Completed (3U)
#  endif

#  ifndef eIO_ADC_IGN_AD
#   define eIO_ADC_IGN_AD (2U)
#  endif

#define IGNON_VALUE ((uint8)2)

#define ECUAPPM_READY_TO_SLEEP 0u

#define ECUAPPM_REFUSE_TO_SLEEP 1u

/*#define ECUM_WKSOURCE_RTC    (uint32)(64u)*/
//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================

//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================
//void SleepManager_RTCCalibrationStatus(uint8 status);
uint8 SleepManager_JudgementStatus(void);
void SleepManager_Judgement(void);
extern Std_ReturnType IoHwAb_GetProcessedAdc(uint8 AdcId, sint32* ProcessedAdc, uint8* ErrorStatus);
//void SleepManager_GetWakeupReason(uint16 WakeupSource);

#endif

