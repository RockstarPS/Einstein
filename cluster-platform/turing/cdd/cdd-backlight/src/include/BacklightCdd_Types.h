//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2026] Visteon Corporation
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
#ifndef BACKLIGHTCDD_TYPES_H
#define BACKLIGHTCDD_TYPES_H
//------------------------------------------------------------------------------------------------------------------------
// Included files
//------------------------------------------------------------------------------------------------------------------------

#include <EcuPowerM_Types.h>
#include <IoHwAb_Pwm_Cfg.h>
#include "Rte_CBacklightCdd.h"


typedef enum
{
    BACKLIGHTDRVCDD_POWER_STATE_IDLE = 0u,
    BACKLIGHTDRVCDD_POWER_STATE_POWER_ON,
    BACKLIGHTDRVCDD_POWER_STATE_POWER_OFF,
}BacklightDrvCdd_PwrStType;

typedef enum
{
    BACKLIGHTDRVCDD_FAULT_ACTIVE_ON_HIGH = 0u,
    BACKLIGHTDRVCDD_FAULT_ACTIVE_ON_LOW,
}BacklightDrvCdd_FaultActiveLevelType;


/** \brief Backlight driver APIs. */
typedef struct
{
    void (*pfInit)(void);
    void (*pfDeInit)(void);
    void (*pfMainFunction)(void);
    Std_ReturnType (*pfSetBrightness)(uint8 deviceId, uint16 duty);
    EDeviceStatus (*pfGetStatus)(uint8 deviceId);
    Std_ReturnType (*pfRequestPower)(uint8 deviceId, BacklightDrvCdd_PwrStType state);
    void (*pfEnterSafeStatus)(void);
    void (*pfExitSafeStatus)(void);
} BacklightCdd_DescrType;


typedef IoHwAb_DOutSignalIdType BacklightCdd_DOutChannelType;
typedef IoHwAb_DInSignalIdType  BacklightCdd_DInChannelType;
typedef EDisplayType  BacklightCdd_PwmChannelType;
typedef EDisplayType  BacklightCdd_I2CChannelType;

typedef P2FUNC(Std_ReturnType, CBacklightCdd_CODE, BacklightCdd_ReadPin_t)(  VAR(BacklightCdd_DInChannelType, AUTOMATIC) channel,
																   		    P2VAR(uint8, AUTOMATIC, BACKLIGHTCDD_APPL_DATA)value,
																   			P2VAR(uint8, AUTOMATIC, BACKLIGHTCDD_APPL_DATA)error);

typedef P2FUNC(Std_ReturnType, CBacklightCdd_CODE, BacklightCdd_SetPin_t)(   VAR(BacklightCdd_DOutChannelType, AUTOMATIC) channel,
																   		    VAR(EcuPowerM_ChannelValueType, AUTOMATIC)value,
																   			P2VAR(uint8, AUTOMATIC, BACKLIGHTCDD_APPL_DATA)error);

typedef P2FUNC(Std_ReturnType, CBacklightCdd_CODE, BacklightCdd_SetDuty_t)( 	VAR(BacklightCdd_PwmChannelType, AUTOMATIC) channel,
																   		    VAR(uint16, AUTOMATIC)duty,
																   		    P2VAR(uint8, AUTOMATIC, BACKLIGHTCDD_APPL_DATA)error);

typedef P2FUNC(Std_ReturnType, CBacklightCdd_CODE, BacklightCdd_SetDutyAndPeriod_t)( VAR(BacklightCdd_PwmChannelType, AUTOMATIC) channel,
																   				    VAR(uint32, AUTOMATIC)period,
																   				    VAR(uint16, AUTOMATIC)duty,
																   				    P2VAR(uint8, AUTOMATIC, BACKLIGHTCDD_APPL_DATA)error);                                                                                

typedef struct 
{
    BacklightCdd_ReadPin_t IoHwAbReadChannel;
    BacklightCdd_SetPin_t IoHwAbWriteChannel;
    BacklightCdd_SetDuty_t IoHwAbSetDuty;
    BacklightCdd_SetDutyAndPeriod_t IoHwAbSetDutyAndPeriod; 
} BacklightCdd_IOFuncType;



//------------------------------------------------------------------------------------------------------------------------
// Duty Info (single, canonical version)
//------------------------------------------------------------------------------------------------------------------------
typedef struct
{
	uint16          CurrentDutyValue;
	uint16          LastDutyValue;
} BacklightdCd_DutyOutInfoType;

//------------------------------------------------------------------------------------------------------------------------
// Drive modes
//------------------------------------------------------------------------------------------------------------------------
typedef enum
{
    BACKLIGHT_MODE_PWM = 0u,
    BACKLIGHT_MODE_I2C
} BacklightCdd_DriveModeType;

//------------------------------------------------------------------------------------------------------------------------
// I2C Types
//------------------------------------------------------------------------------------------------------------------------
typedef enum
{
    BACKLIGHT_I2C_WRITE,
    BACKLIGHT_I2C_READ
} BacklightCdd_I2cSeqType;

typedef enum
{
    BACKLIGHT_INIT,
    BACKLIGHT_SAFESTATE
} BacklightCdd_FaultActionType;

typedef enum
{
    REGMON_IDLE    = 0u,
    REGMON_PENDING = 1u,
    REGMON_BUSY    = 2u
} BacklightCdd_RegMonStateType;

typedef struct
{
    uint16 timer;              /* countdown ticks */
    BacklightCdd_RegMonStateType state;      /* IDLE / PENDING / BUSY */
} BacklightCdd_RegMonCfg;

typedef struct
{
    BacklightCdd_I2cSeqType type;
    uint8 command;
    uint16 delayMs;
} BacklightCdd_I2cStepType;

typedef struct
{
    uint8 Reg;
    uint8 CfgVal;
    uint8 mask;
    const BacklightCdd_FaultActionType SafetyAction;
    uint16 monitorTime;        /*in milli seconds*/
} BacklightCdd_RegAction;

typedef struct
{
    uint8 i2cChannelWrite;
    uint8 i2cSeqIdWrite;
    uint8 i2cChannelRead;
    uint8 i2cSeqIdRead;
    const BacklightCdd_I2cStepType *initSeq;
    uint8 initLen;
    const uint8 *RegTable;
    const BacklightCdd_RegAction *monitorRegs;
    uint8 *data;
    uint8 monitorLen;
    uint8 deviceaddr;
} BacklightCdd_I2cConfigType;

//------------------------------------------------------------------------------------------------------------------------
// PWM Config
//------------------------------------------------------------------------------------------------------------------------
typedef struct
{
	BacklightCdd_PwmChannelType Backlight_PwmId; 
    uint16 InitDuty;
} BacklightCdd_PwmConfigType;

//------------------------------------------------------------------------------------------------------------------------
// Device Configuration
//------------------------------------------------------------------------------------------------------------------------
typedef struct
{
    uint8 DeviceId;
    BacklightCdd_DriveModeType DriveMode;

    BacklightCdd_DOutChannelType Backlight_EnableDoutID;
    BacklightCdd_DInChannelType  Backlight_FaultPinDInID;

    uint8 EnableLevel;
    uint8 DisableLevel;

    BacklightDrvCdd_FaultActiveLevelType Backlight_FaultActiveLevel;
    uint32 Backlight_FaultMonDelayCnt;

    uint16 PowerOnDelayCnt;
    uint16 ErrorRecoveryRetryCnt;
    uint16 PowerOnRecoveryMaxRetryCnt;
    uint16 I2cFailMaxRetryCount;

    const BacklightCdd_PwmConfigType *PwmCfg;
    const BacklightCdd_I2cConfigType *I2cCfg;
} BacklightCdd_DeviceConfigType;

//------------------------------------------------------------------------------------------------------------------------
// Global Table
//------------------------------------------------------------------------------------------------------------------------
typedef struct
{
    const BacklightCdd_DeviceConfigType *DeviceTable;
    uint8 DeviceCount;
} BacklightCdd_ConfigType;




#endif/*End of File */

/**********************************************************************************************************************************************
*                                 END OF FILE                                                                      
***********************************************************************************************************************************************/

/*---------------------------------------------------------------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------------------------------------------------------------*/
/*==============================================================================================================================================
Date              	: 03-12-25
CDSID             	: yviswana
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/
/*==============================================================================================================================================
Date              	: 03-17-26
CDSID             	: bmahesan
Traceability      	: ASCDD-241
Change Description	: Updated Version for MAX20446B/LP8867.
================================================================================================================================================*/
/*==============================================================================================================================================
Date              	: 04-07-26
CDSID             	: mmahend2
Traceability      	: ASCDD-106 ,ASCDD-357
Change Description	: 1) Fixed KW warnings. 2) Updated Backlight Fault monitoring Logic.
================================================================================================================================================*/


