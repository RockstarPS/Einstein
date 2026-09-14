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
//-----------------------------------------------------------------------------------------------------------------------

/* header includes */
#include "Rte_CBacklightCdd.h"
#include "CDD_Backlight_Cfg.h"
#include "BacklightDrvCdd.h"

#define	CBacklightCdd_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

const uint8 Backlight_I2cRegTable_Data[REG_COUNT_I2C] = 
{
    0x38u,         /* ISET */
    0x00u,         /* IMODE */
    0x22u,         /* SETTINGS */
    0x00u,         /* DISABLE */
    0x00u,         /* MASK */
    0x00u,          /* DIAG */
};

const uint8 Backlight_I2cRegTable_Address[REG_COUNT_I2C] = 
{
    0x02u,         /* ISET */
    0x03u,         /* IMODE */
    0x12u,         /* SETTINGS */
    0x13u,         /* DISABLE */
    0x1Eu,         /* MASK */
    0x1Fu,          /* DIAG */
};

    /*Reg, CfgVal,  mask, action, periodicity */
const BacklightCdd_RegAction Backlight_Monitor_I2cRegTable[] = 
{
    {0x1F, 0x00u, 0x04, BACKLIGHT_INIT, 100u},
};

//---------------------------------------------------------------------------------------------------------------------
// DRIVER API TABLE
//---------------------------------------------------------------------------------------------------------------------
CONST(BacklightCdd_DescrType, BACKLIGHTCDD_APPL_CONST) BacklightCdd_DrvTable =
{
    BacklightDrvCdd_Init,
    BacklightDrvCdd_DeInit,
    BacklightDrvCdd_MainFunction,
    BacklightDrvCdd_SetBrightness,
    BacklightDrvCdd_GetStatus,
    BacklightDrvCdd_RequestPower,
    BacklightDrvCdd_EnterSafeState,
    BacklightDrvCdd_ExitSafeState
};

//---------------------------------------------------------------------------------------------------------------------
// IO FUNCTION TABLE
//---------------------------------------------------------------------------------------------------------------------
const BacklightCdd_IOFuncType BacklightCdd_IOTable =
{
    .IoHwAbReadChannel      = Backlight_DIn_GetProcessedValue, 
    .IoHwAbWriteChannel     = Rte_Call_rpIoHwAb_DOut_SetOutputPin, 
    .IoHwAbSetDuty          = Rte_Call_rpIoHwAb_PWM_PwmSetDuty,
    .IoHwAbSetDutyAndPeriod = Rte_Call_rpIoHwAb_PWM_PwmSetDutyAndPeriod
};


const BacklightCdd_I2cStepType BacklightCdd_I2CStepTable =
{
    .type             = BACKLIGHT_I2C_WRITE,
    .command          = NULL, 
    .delayMs          = 0u
};

const BacklightCdd_I2cConfigType BacklightCdd_I2CCfgable =
{
    .i2cChannelWrite        = 1u,       
    .i2cSeqIdWrite          = 2u,   
    .i2cChannelRead         = 3u,   
    .i2cSeqIdRead           = 4u,    
    .initSeq                = NULL, 
    .initLen                = 20U,
    .RegTable               = &Backlight_I2cRegTable_Address[0],
    .monitorRegs            = &Backlight_Monitor_I2cRegTable[0],
    .data                   = &Backlight_I2cRegTable_Data[0],
    .monitorLen             = 1u,
    .deviceaddr             = 0x63U
};


//---------------------------------------------------------------------------------------------------------------------
// DEVICE CONFIG TABLE (one PWM device example)
//---------------------------------------------------------------------------------------------------------------------
static const BacklightCdd_DeviceConfigType BacklightDevices[] =
{
    {
        .DeviceId                   = 0u,
        .DriveMode                  = BACKLIGHT_MODE_I2C,
        .Backlight_EnableDoutID     = DOUT_BACKLIGHT_EN,
        .Backlight_FaultPinDInID    = DIN_BACKLIGHT_FLT,
        .EnableLevel                = 1u,
        .DisableLevel               = 0u,
        .Backlight_FaultActiveLevel = BACKLIGHTDRVCDD_FAULT_ACTIVE_ON_HIGH,
        .Backlight_FaultMonDelayCnt = 4U,
        .PowerOnDelayCnt            = 10u,
        .ErrorRecoveryRetryCnt      = 3u,
        .PwmCfg                     = 0,
        .I2cCfg                     = &BacklightCdd_I2CCfgable,
        .PowerOnRecoveryMaxRetryCnt    = 100u,
        .I2cFailMaxRetryCount           = 3u
    }
};

//---------------------------------------------------------------------------------------------------------------------
// GLOBAL CONFIG
//---------------------------------------------------------------------------------------------------------------------
const BacklightCdd_ConfigType BacklightConfig =
{
    .DeviceTable = &BacklightDevices[0],
    .DeviceCount = (uint8)(sizeof(BacklightDevices)/sizeof(BacklightDevices[0]))
};

#define	BACKLIGHTCDD_I2C_CHIP_MAX20446


Std_ReturnType Backlight_DIn_GetProcessedValue(IoHwAb_DInSignalIdType InputId, boolean* ProcessedValue, IoHwAb_ErrorType* ErrorStatus)
{
    *ProcessedValue = FALSE;
    *ErrorStatus = E_OK;
    return E_OK;
}


#define	CBacklightCdd_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

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
Traceability      	: ASCDD-357
Change Description	: ASCDD-357 - Updated Backlight Fault monitoring Logic.
================================================================================================================================================*/



