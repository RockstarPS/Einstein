//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2023] Visteon Corporation
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
#ifndef ECUBATTERYM_TYPES_H
#define ECUBATTERYM_TYPES_H
//------------------------------------------------------------------------------------------------------------------------
// Included files
//------------------------------------------------------------------------------------------------------------------------
#include <Std_Types.h>

/** \brief IoHwAbs channel type. */
typedef uint8 EcuBatteryM_IoHwAbsChannelType;

/** \brief Virtual Channel ID type. */
typedef uint16 EcuBatteryM_ChannelIdType;
/** \brief Hardware Channel ID. */
typedef uint16 EcuBatteryM_HardwareIdType;

/** \brief Holds EcuBatteryM init status. */
typedef enum
{
	/* Illegal initialization value. */
	ECUBATTERYM_S_ILLEGAL = 0,
	/* EcuPowerM was not initialized. */
	ECUBATTERYM_S_UNINITIALIZED,
	/* EcuPowerM successfully initialized. */
	ECUBATTERYM_S_INITIALIZED

} EcuBatteryM_InitStatusType;

/** \brief Threshold type. */
typedef enum
{
 	/* ON Threshold */
 	ECUBATTERYM_THRESHOLD_TYPE_ON=0,
 	/* OFF Threshold */
 	ECUBATTERYM_THRESHOLD_TYPE_OFF=1,
 	/* INVALID Threshold */
 	ECUBATTERYM_THRESHOLD_TYPE_INVALID

} EcuBatteryM_ThresholdType;

/** \brief Enable Polarity type. */
typedef enum
{
 	/* LOW POLARITY */
 	ECUBATTERYM_POLARITY_TYPE_LOW=0,
 	/* HIGH PLOARITY */
 	ECUBATTERYM_POLARITY_TYPE_HIGH=1,
 	/* INVALID POLARITY */
 	ECUBATTERYM_POLARITY_TYPE_INVALID

} EcuBatteryM_PolarityType;


/** \brief channel monitoring type. */
typedef enum
{
 	/* monitoring type Analog. */
 	ECUBATTERYM_MONITORING_TYPE_NONE=0,
 	ECUBATTERYM_MONITORING_TYPE_HIGH=1,
 	ECUBATTERYM_MONITORING_TYPE_LOW=2,
    ECUBATTERYM_MONITORING_TYPE_PGOOD=3,
 	/* monitoring type INVALID. */
 	ECUBATTERYM_MONITORING_TYPE_INVALID
} EcuBatteryM_ChannelMonitoringType;

typedef struct
{
	uint16 monitorDelayTimer;
	uint16 debounceCounter;
	uint8  monitorState;
	uint8  rawState;
	uint8  state;
	
} EcuBatteryM_ChannelStateType;



typedef P2FUNC(Std_ReturnType, ECUBATTERYM_CODE, EcuBatteryM_VoltageSourcePtrType)(VAR(EcuBatteryM_IoHwAbsChannelType, AUTOMATIC) channel,
																   		P2VAR(void, AUTOMATIC,ECUBATTERYM_APPL_DATA)value,
																   		P2VAR(uint8, AUTOMATIC, ECUBATTERYM_APPL_DATA)error);

typedef P2FUNC(Std_ReturnType, ECUBATTERYM_CODE, EcuBatteryM_GetThresholdValuePtrType)(P2VAR(void, AUTOMATIC,ECUBATTERYM_APPL_DATA)value);
typedef P2FUNC(Std_ReturnType, ECUBATTERYM_CODE, EcuBatteryM_GetHysteresisValuePtrType)(P2VAR(void, AUTOMATIC,ECUBATTERYM_APPL_DATA)value);

typedef struct
{
	EcuBatteryM_ChannelMonitoringType  		monitoringType;
	uint16 			                        enableid;
	EcuBatteryM_IoHwAbsChannelType 			hwid;
	EcuBatteryM_PolarityType  				enablePolarity;
	uint8  									defaultMonitoringState;
	uint8  									initialstate;
	uint32 									onThreshold;
	uint32 									onHysteresis;
	uint32 									offThreshold;
	uint32 									offHysteresis;
	uint16 									offToOnDebounce;
	uint16 									onToOffDebounce;
	uint16 									monitorDelayTime;
	uint8                                   faultId;
	EcuBatteryM_VoltageSourcePtrType 		VoltageSourceApi;
	EcuBatteryM_GetThresholdValuePtrType	OnThresholdValueApi;
	EcuBatteryM_GetHysteresisValuePtrType   OnHysteresisValueApi;
	EcuBatteryM_GetThresholdValuePtrType	OffThresholdValueApi;
	EcuBatteryM_GetHysteresisValuePtrType   OffHysteresisValueApi;

} EcuBatteryM_ChannelConfigDataType;

typedef P2CONST(EcuBatteryM_ChannelConfigDataType, AUTOMATIC, ECUPOWERM_APPL_CONST) EcuBatteryM_ChannelConfigDataptrType; 






#endif /*End of File */

/*==============================================================================================================================================
Date              	: 21-02-2025
CDSID             	: tgunasek
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/
