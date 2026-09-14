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

#ifndef RTCDRVCDD_CFG_H
#define RTCDRVCDD_CFG_H
#include "Os.h"
//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
#define RTCCDD_ENTER_CRITICAL_SECTION()           SuspendAllInterrupts()
#define RTCCDD_EXIT_CRITICAL_SECTION()            ResumeAllInterrupts()

#define cRTCCDD_IoHwAB_GetAsyncRawAdc(adcId, adcVal, status) Rte_Call_rp_CS_IoHwAb_ADC_GetAsyncRawAdc(adcId, adcVal, status)
#define cRTCCDD_MemAbstract_GetFastRTCSamplingPeriod(fastSampPer) Rte_Call_rp_CS_MemAbsGet_Get_NV_FastRTCSamplingPeriod(fastSampPer)
#define cRTCCDD_MemAbstract_GetSlowRTCSamplingPeriod(slowSampPer) Rte_Call_rp_CS_MemAbsGet_Get_NV_SlowRTCSamplingPeriod(slowSampPer)
#define cRTCCDD_MemAbstract_GetRTCCoolingDelay(rtcCoolingDelay) Rte_Call_rp_CS_MemAbsGet_Get_NV_RTCCoolingDelay(rtcCoolingDelay)
#define cRTCCDD_MemAbstract_GetRTCCompensationDelay(rtcCompDelay) Rte_Call_rp_CS_MemAbsGet_Get_NV_RTCCompensationDelay(rtcCompDelay)
#define cRTCCDD_MemAbstract_GetRtcCalibration_E_R_FC(rtcCalib_E_R_FC) Rte_Call_rp_CS_MemAbsGet_Get_NV_RtcCalibration_E_R_FC(rtcCalib_E_R_FC)
#define cRTCCDD_MemAbstract_GetRtcCalibration_K(rtcCalib_K) Rte_Call_rp_CS_MemAbsGet_Get_NV_RtcCalibration_K(rtcCalib_K)
#define cRTCCDD_MemAbstract_GetRtcCalibration_Tc(rtcCalib_Tc) Rte_Call_rp_CS_MemAbsGet_Get_NV_RtcCalibration_Tc(rtcCalib_Tc)
#define RTCDRVCDD_TEMP_READ_DELAY      (uint8)10 // 100ms

#define cRTCCDD_TIME_TYPE Rtc_TimeType

#define cRTCCDD_ALARM_TIME_TYPE Rtc_AlarmType

#define cRTCCDD_PERIODIC_ALARM_TIME_TYPE Rtc_PeriodicAlarmType

#define RTC_ALARM_FUNCTIONALITY_ENABLED

//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================

//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================

#endif

