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

#ifndef RTE_STUB_H_
#define RTE_STUB_H_

//#include "OsMain.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

/* ssebast1; IoHwAb Typedefs */
#if 0
#  define Rte_TypeDef_EIOCurrentInId
typedef sint32 EIOCurrentInId;

#  define Rte_TypeDef_EIODutyInId
typedef sint32 EIODutyInId;

#  define Rte_TypeDef_EIODutyOutId
typedef uint8 EIODutyOutId;

#  define Rte_TypeDef_EIOGroupInId
typedef sint32 EIOGroupInId;

#  define Rte_TypeDef_EIOGroupOutId
typedef sint32 EIOGroupOutId;

#  define Rte_TypeDef_EIOMapStat
typedef uint8 EIOMapStat;

#  define Rte_TypeDef_EIOMapStatInId
typedef sint32 EIOMapStatInId;

#  define Rte_TypeDef_EIOPeriodInId
typedef sint32 EIOPeriodInId;

#  define Rte_TypeDef_EIOPeriodOutId
typedef sint32 EIOPeriodOutId;

#  define Rte_TypeDef_EIOPinInId
typedef uint8 EIOPinInId;

#  define Rte_TypeDef_EIOPinOutId
typedef uint8 EIOPinOutId;

#  define Rte_TypeDef_EIOResistanceInId
typedef sint32 EIOResistanceInId;

#  define Rte_TypeDef_EIOVoltageOutId
typedef sint32 EIOVoltageOutId;

#  define Rte_TypeDef_TIOAppData
typedef sint32 TIOAppData;

# define Rte_TypeDef_EIOVoltageInId
typedef sint32 EIOVoltageInId;
#endif

//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================


#endif  // RTE_STUB_H_

//varumuga
#define COM_SIGNAL_AMBIENTLIGHTINGBRIGHTNESSSTATUS2_1417_8B8C 1
#define COM_SIGNAL_BCM_WAKEUPSLEEPCOMMAND_1144_16E9           1
#define COM_SIGNAL_ETS_MODELAMP_569_8789 					  1
#define COM_SIGNAL_FLUENTDRIVINGINDICATOR_1120_BE57 		  1
#define COM_SIGNAL_STOPAUTOPHASE_116_FF31 					  1

#define ComConf_ComSignal_AmbientLightingBrightnessStatus2_fde9b3ac COM_SIGNAL_AMBIENTLIGHTINGBRIGHTNESSSTATUS2_1417_8B8C
#define ComConf_ComSignal_ETS_ModeLamp_bf72e99a COM_SIGNAL_ETS_MODELAMP_569_8789
#define ComConf_ComSignal_FluentDrivingIndicator_e69d0077 COM_SIGNAL_FLUENTDRIVINGINDICATOR_1120_BE57
#define ComConf_ComSignal_StopAutoPhase_40d931b6 COM_SIGNAL_STOPAUTOPHASE_116_FF31
#define ComConf_ComSignal_BCM_WakeUpSleepCommand_836390c2 COM_SIGNAL_BCM_WAKEUPSLEEPCOMMAND_1144_16E9

//srajago6
#define ComConf_ComSignal_CRC_AVM_A120_7ed2ac87 1
#define ComConf_ComSignal_EcoAdviceTirePressureFL_1326146c 1
#define ComConf_ComSignal_LowBeamFailureDisplay_v3_6f2eb103 1
#define ComConf_ComSignal_MBLfailureDisplay_7e16257e 1
#define ComConf_ComSignal_OldPressureFL_46c4ae4c 1
#define ComConf_ComSignal_TSR_ConfidenceLevel_600abfcb 1
#define ComConf_ComSignal_TripComputer_ResetRequest_12897325 1
#define ComConf_ComSignal_VSPstatusDisplay_517616e1 1