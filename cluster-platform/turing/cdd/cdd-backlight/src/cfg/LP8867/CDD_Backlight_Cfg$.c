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
#include "CDD_Backlight_Cfg.h"
#include "BacklightCdd_Types.h"
#include "BacklightDrvCdd.h"



#define CBacklightCdd_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

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
    .IoHwAbReadChannel      = Rte_Call_rpIoHwAb_Din_GetProcessedInput, 
    .IoHwAbWriteChannel     = Rte_Call_rpIoHwAb_DOut_SetOutputPin, 
    .IoHwAbSetDuty          = Rte_Call_rpIoHwAb_PWM_PwmSetDuty,
    .IoHwAbSetDutyAndPeriod = Rte_Call_rpIoHwAb_PWM_PwmSetDutyAndPeriod
};


//---------------------------------------------------------------------------------------------------------------------
// PWM CONFIG
//---------------------------------------------------------------------------------------------------------------------
static const BacklightCdd_PwmConfigType BacklightPwmCfg =
{
    .Backlight_PwmId = eIO_PWM_DO_FPK_BKL_DIMMING,
    .InitDuty        = 0u
};

//---------------------------------------------------------------------------------------------------------------------
// DEVICE CONFIG TABLE (one PWM device example)
//---------------------------------------------------------------------------------------------------------------------
static const BacklightCdd_DeviceConfigType BacklightDevices[] =
{
    {
        .DeviceId               = 0u,
        .DriveMode              = BACKLIGHT_MODE_PWM,
        .Backlight_EnableDoutID = eIOPinOutId_DO_FPK_BKL_EN,
        .Backlight_FaultPinDInID= eIOPinInId_DI_FPK_BKL_FAULT,
        .EnableLevel            = 1u,
        .DisableLevel           = 0u,
        .Backlight_FaultActiveLevel = BACKLIGHTDRVCDD_FAULT_ACTIVE_ON_HIGH,
        .Backlight_FaultMonDelayCnt = 5U,
        .PowerOnDelayCnt        = 1u,
        .ErrorRecoveryRetryCnt  = 3u,
        .PwmCfg                 = &BacklightPwmCfg,
        .I2cCfg                 = 0
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
