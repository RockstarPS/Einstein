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

/** \brief Holds EcuPowerM init status. */
typedef enum
{
	/* Illegal initialization value. */
	ECUBATTERYM_S_ILLEGAL = 0,
	/* EcuPowerM was not initialized. */
	ECUBATTERYM_S_UNINITIALIZED,
	/* EcuPowerM successfully initialized. */
	ECUBATTERYM_S_INITIALIZED

} EcuBatteryM_InitStatusType;

/** \brief channel category API type. */
typedef enum
{
 	/* channel type Analog. */
 	ECUBATTERYM_CHANNEL_TYPE_ANALOG=0,
 	/* channel type INVALID. */
 	ECUBATTERYM_CHANNEL_TYPE_INVALID
} EcuBatteryM_ChannelCategoryType;

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
	uint16 debounceCounter;
	uint8  state;
} EcuBatteryM_ChannelStateType;



typedef P2FUNC(Std_ReturnType, ECUBATTERYM_CODE, EcuBatteryM_VoltageSourcePtrType)(VAR(EcuBatteryM_IoHwAbsChannelType, AUTOMATIC) channel,
																   		P2VAR(void, AUTOMATIC,ECUBATTERYM_APPL_DATA)value,
																   		P2VAR(uint8, AUTOMATIC, ECUBATTERYM_APPL_DATA)error);

typedef struct
{
	EcuBatteryM_ChannelMonitoringType  monitoringType;
	EcuBatteryM_IoHwAbsChannelType enableid;
	EcuBatteryM_IoHwAbsChannelType hwid; 
	uint8 initialstate;
	uint16 onThreshold;
	uint16 offThreshold;
	uint16 onToOffDebounce;
	uint16 offToOnDebounce;
	EcuBatteryM_VoltageSourcePtrType VoltageSourceApi;
} EcuBatteryM_ChannelConfigDataType;

typedef P2CONST(EcuBatteryM_ChannelConfigDataType, AUTOMATIC, ECUPOWERM_APPL_CONST) EcuBatteryM_ChannelConfigDataptrType; 






#endif /*End of File */

/*==============================================================================================================================================
Date              	: 21-02-2025
CDSID             	: tgunasek
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/
