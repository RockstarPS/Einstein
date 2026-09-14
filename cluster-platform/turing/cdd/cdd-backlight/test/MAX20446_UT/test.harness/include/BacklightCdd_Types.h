//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2025] Visteon Corporation
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
#include <Std_Types.h> 
#include <Rte_Type.h>
#include <EcuPowerM_Types.h>
#include <IoHwAb_Pwm_Cfg.h>


typedef enum
{
    BACKLIGHTDRVCDD_POWER_STATE_IDLE = 0u,
    BACKLIGHTDRVCDD_POWER_STATE_POWER_ON,
}BacklightDrvCdd_PwrStType;


/** \brief Backlight driver APIs. */
typedef struct
{
    void (*pfInit)(void);
    void (*pfDeInit)(void);
    void (*pfMainFunction)(void);
    void (*pfSetBrightness)(uint8, uint16);
    boolean (*pfGetStatus)(uint8, EDeviceStatus);
    void (*pfRequestPower)(uint8, BacklightDrvCdd_PwrStType);
    void (*pfEnterSafeStatus)(void);
    void (*pfExitSafeStatus)(void);
} BacklightCdd_DescrType;


typedef IoHwAb_DOutSignalIdType BacklightCdd_DOutChannelType;
typedef IoHwAb_DInSignalIdType  BacklightCdd_DInChannelType;
//typedef IoHwAb_PwmChannelType  BacklightCdd_PwmChannelType;
typedef EDisplayType  BacklightCdd_PwmChannelType;

typedef P2FUNC(Std_ReturnType, BACKLIGHTCDD_CODE, BacklightCdd_ReadPin_t)(  VAR(BacklightCdd_DInChannelType, AUTOMATIC) channel,
																   		    P2VAR(uint8, AUTOMATIC, BACKLIGHTCDD_APPL_DATA)value,
																   			P2VAR(uint8, AUTOMATIC, BACKLIGHTCDD_APPL_DATA)error);

typedef P2FUNC(Std_ReturnType, BACKLIGHTCDD_CODE, BacklightCdd_SetPin_t)(   VAR(BacklightCdd_DOutChannelType, AUTOMATIC) channel,
																   		    VAR(EcuPowerM_ChannelValueType, AUTOMATIC)value,
																   			P2VAR(uint8, AUTOMATIC, BACKLIGHTCDD_APPL_DATA)error);

typedef P2FUNC(Std_ReturnType, BACKLIGHTCDD_CODE, BacklightCdd_SetDuty_t)( 	VAR(BacklightCdd_PwmChannelType, AUTOMATIC) channel,
																   		    VAR(uint16, AUTOMATIC)duty,
																   		    P2VAR(uint8, AUTOMATIC, BACKLIGHTCDD_APPL_DATA)error);

typedef P2FUNC(Std_ReturnType, BACKLIGHTCDD_CODE, BacklightCdd_SetDutyAndPeriod_t)( VAR(BacklightCdd_PwmChannelType, AUTOMATIC) channel,
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

//typedef P2CONST(BacklightCdd_IOFuncType, AUTOMATIC, BACKLIGHTCDD_APPL_CONST)  BacklightCdd_IOTable;

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

typedef struct
{
    BacklightCdd_I2cSeqType type;
    uint8 command;
    uint8 data;
    uint16 delayMs;
} BacklightCdd_I2cStepType;

typedef struct
{
    uint8 i2cChannel;
    const BacklightCdd_I2cStepType *initSeq;
    uint8 initLen;
    const uint8 *monitorRegs;
    uint8 monitorLen;
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

    uint16 PowerOnDelayCnt;
    uint16 ErrorRecoveryRetryCnt;

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

typedef enum 
{
    BACKLIGHTCDD_STATE_IDLE = 0,
    BACKLIGHTCDD_STATE_POWER_ON,
    BACKLIGHTCDD_STATE_POWER_ON_WAIT,
    BACKLIGHTCDD_STATE_CONFIGURE,
    BACKLIGHTCDD_STATE_ACTIVE,
    BACKLIGHTCDD_STATE_MONITOR,
    BACKLIGHTCDD_STATE_ERROR,
    BACKLIGHTCDD_STATE_SAFE
} BacklightCdd_OpStateType;



#endif/*End of File */