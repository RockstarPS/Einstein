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
#ifndef RTCDRVCDD_TEMPERATURECOMPENSATION_H
#define RTCDRVCDD_TEMPERATURECOMPENSATION_H

#include "RtcMgrCdd_Cfg.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================

//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================


extern void RtcDrvCdd_TemperatureCompensation_MainFunction(void);
extern void RtcDrvCdd_TemperatureCompensation_Init(void);
extern Std_ReturnType RtcDrvCdd_TemperatureCompensation_DeInit(void);
extern void RtcDrvCdd_TemperatureCompensation_SetTime(void);
extern void RtcDrvCdd_TemperatureCompensation_AlarmNotification(void);
extern void RtcDrvCdd_TemperatureCompensation_SleepMode(void);
extern void RtcDrvCdd_TemperatureCompensation_RunMode(void);
extern void RtcDrvCdd_TemperatureCompensation_Timeperiod_Init(void);
extern void RtcDrvCdd_TemperatureCompensation_SleepModeTimeperiod_Init(void);
extern void RtcDrvCdd_TemperatureCompensation_RunModeTimeperiod_Init(void); 

#ifdef RTCCDD_IMX8QXP
extern void RtcDrvCdd_TemperatureCompensation_ConfigureNvmParams(RtcNvmCalibParams_t nvmParams);
extern void RtcDrvCdd_TemperatureCompensation_ConfigureTemp(sint16 temp);
extern void RtcDrvCdd_TemperatureCompensation_ConfigureIpc(uint32 rtc_ipc);
extern Std_ReturnType RtcDrvCdd_TemperatureCompensation_ReadSnvs(void);
extern void RtcDrvCdd_TemperatureCompensation_CheckCompensation(sint16 temp);
extern void RtcDrvCdd_TemperatureCompensation_Compensate(void);
extern void RtcDrvCdd_TemperatureCompensation_IncrementSleepCompCounter(void);
extern void RtcDrvCdd_TemperatureCompensation_ResetSleepCompCounter(void);
#endif

#endif /* RTCDRVCDD_TEMPERATURECOMPENSATION_H */

