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

static uint8 Backlight_I2cRegTable_Data[REG_COUNT_I2C] = 
{
    0x00u,         /* IMODE */
    0x22u,         /* SETTINGS */
    0x00u,         /* DISABLE */
    0x00u,         /* MASK */
    0x00u,          /* DIAG */
    0x00u,
    0x00u,
    0x00u,   
    0x00u,
    0x00u,
    0x00u,
    0x00u,
    0x00u,
    0x00u,
    0x00u,
    0x00u,
    0x00u,
    0x00u,
    0X00u,
    0x38u,         /* ISET */
};

const uint8 Backlight_I2cRegTable_Address[REG_COUNT_I2C] = 
{
    0x03u,         /* IMODE */   
    0x12u,         /* SETTINGS */
    0x13u,         /* DISABLE */
    0x1Eu,         /* MASK */
    0x1Fu,          /* DIAG */
    0x04u,
    0x05u,
    0x06u,
    0x07u,
    0x08u,
    0x09u,
    0x0Au,
    0X0Bu,
    0X0Cu,
    0X0Du,
    0X0Eu,
    0X0Fu,
    0X10u,
    0X11u,
    0x02u,         /* ISET */
};

const BacklightCdd_RegAction Backlight_Monitor_I2cRegTable[] = 
{
    {0x1F, 0x00u, 0x04, BACKLIGHT_INIT, 100u},
};

//     /*Fault status reg, clear value*/
// const BacklightCdd_FaultStatus Backlight_FaultStatus_RegTable[] = 
// {
//     {0x1F, 0x00u},
// };

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
    .IoHwAbWriteChannel     = Backlight_IoHwAb_WriteWrapper, 
    .IoHwAbSetDuty          = NULL_PTR,
    .IoHwAbSetDutyAndPeriod = NULL_PTR
};


const BacklightCdd_I2cStepType BacklightCdd_I2CStepTable =
{
    .type             = BACKLIGHT_I2C_WRITE,
    .command          = 0u, 
    .delayMs          = 0u
};
/*Referece for i2c functions used previously in ABT when the backlight is up
in this common basline tag refer functions in cdd-backlight/src/lib_src/BacklightDrvCdd_I2C.c file
previously used-
I2c_SetupEB(I2cConf_I2cChannel_I2cChannel_BackLightDriver_Bank_0x2E_write, (I2c_DataType*) &BKL_TX_Buffer[0], NULL_PTR, 2u) )

I2c_AsyncTransmit(I2cConf_I2cSequence_I2cSequence_BackLightDriver_Bank_0x2E_writeOnly) )

I2c_GetSequenceResult(I2cConf_I2cSequence_I2cSequence_BackLightDriver_Bank_0x2E_writeOnly)

currenlty -

const BacklightCdd_DeviceConfigType *BkltDev = BacklightConfig.DeviceTable;
I2c_SetupEB(BkltDev->I2cCfg->i2cChannel, buf, NULL, BACKLIGHTDRVCDD_TWO , BACKLIGHTDRVCDD_ZERO, BkltDev->I2cCfg->deviceaddr)) //BkltDev->I2cCfg->i2cChannel  -> points to below table
I2c_AsyncTransmit(BkltDev->I2cCfg->i2cChannel)
I2c_GetSequenceResult(BkltDev->I2cCfg->i2cChannel)

cannot change the first parameter directly as it is decalred in -BacklightCdd_Types.h, need to check if we need to update the tag
*/

const BacklightCdd_I2cConfigType BacklightCdd_I2CCfgable =
{
    .i2cChannelWrite       = I2cConf_I2cChannel_I2cChannel_BackLightDriver_Bank_0x2E_write,         //10u     //inital value is 2u, need to change as per program specific
    .i2cSeqIdWrite     = I2cConf_I2cSequence_I2cSequence_BackLightDriver_Bank_0x2E_writeOnly,   //6u
    .i2cChannelRead        = I2cConf_I2cChannel_I2cChannel_BackLightDriver_Bank_0x2E_read,          //6u
    .i2cSeqIdRead         = I2cConf_I2cSequence_I2cSequence_BackLightDriver_Bank_0x2E_wr_rd,        //2u
    .initSeq                = NULL, 
    .initLen                = 20U,
    .RegTable               = &Backlight_I2cRegTable_Address[0],
    .monitorRegs            = &Backlight_Monitor_I2cRegTable[0],
    .data                   = &Backlight_I2cRegTable_Data[0],
    .monitorLen             = 1u,
    .deviceaddr             = 0x63U,
    //.faultStatusRegs        = &Backlight_FaultStatus_RegTable[0]
};

//---------------------------------------------------------------------------------------------------------------------
// DRIVER CONFIG TABLE 
//---------------------------------------------------------------------------------------------------------------------
// static const BacklightCdd_DriverConfigType BacklightDriverTbl[] =
// {
//     {
//         .FaultPersistThreshold  = 40u,
//         .FaultValidThreshold    = 4u,
//         .FaultReactionDelay     = 6u,
//         .FaultRetryThreshold    = 3u
//     }
// };

//---------------------------------------------------------------------------------------------------------------------
// DEVICE CONFIG TABLE (one PWM device example)
//---------------------------------------------------------------------------------------------------------------------
static const BacklightCdd_DeviceConfigType BacklightDevices[] =
{
    {
        .DeviceId               = 0u,
        .DriveMode              = BACKLIGHT_MODE_I2C,
        .Backlight_EnableDoutID = DOUT_BACKLIGHT_EN,
        .Backlight_FaultPinDInID= DIN_BACKLIGHT_FLT,
        .EnableLevel            = 1u,
        .DisableLevel           = 0u,
        .Backlight_FaultActiveLevel = BACKLIGHTDRVCDD_FAULT_ACTIVE_ON_HIGH,
        .Backlight_FaultMonDelayCnt = 4U,
        .PowerOnDelayCnt        = 10u,
        .ErrorRecoveryRetryCnt  = 3u,
        .PwmCfg                 = 0,
        .I2cCfg                 = &BacklightCdd_I2CCfgable
    }
};

//---------------------------------------------------------------------------------------------------------------------
// GLOBAL CONFIG
//---------------------------------------------------------------------------------------------------------------------
const BacklightCdd_ConfigType BacklightConfig =
{
    .DeviceTable = &BacklightDevices[0],
    //.DriverTable = &BacklightDriverTbl[0],
    .DeviceCount = (uint8)(sizeof(BacklightDevices)/sizeof(BacklightDevices[0]))
};

#define	BACKLIGHTCDD_I2C_CHIP_MAX20446


Std_ReturnType Backlight_DIn_GetProcessedValue(IoHwAb_DInSignalIdType InputId, boolean* ProcessedValue, IoHwAb_ErrorType* ErrorStatus)
{
    *ProcessedValue = FALSE;
    *ErrorStatus = E_OK;
    return E_OK;
}


FUNC(Std_ReturnType, BACKLIGHT_CODE)
Backlight_IoHwAb_WriteWrapper(uint8 ChannelId,
                              uint8 Level,
                              Std_ReturnType* ErrPtr)
{
    /* Call actual DIO API */
    Dio_WriteChannel((Dio_ChannelType)ChannelId,
                     (Dio_LevelType)Level);

    /* Report success (no error reporting in DIO driver) */
    if (ErrPtr != NULL_PTR)
    {
        *ErrPtr = E_OK;
    }

    return E_OK;
}
//check these 2 fun below, kept only for compilation
FUNC(Std_ReturnType, CBacklightCdd_CODE) BacklightCdd_ReadDigitalInputs(P2VAR(uint8, AUTOMATIC, RTE_CBACKLIGHTCDD_APPL_VAR) pArgP)
//Std_ReturnType BacklightCdd_ReadDigitalInputs(uint8 *pu8Value)
{
    *pArgP=0u;
    //*pu8Value=0u;
    return RTE_E_OK;
}

FUNC(Std_ReturnType, CBacklightCdd_CODE) BacklightCdd_ReadBacklightFaults(P2VAR(uint32, AUTOMATIC, RTE_CBACKLIGHTCDD_APPL_VAR) pArgP)
//Std_ReturnType BacklightCdd_ReadBacklightFaults(uint32 *pu32Value)
{
    *pArgP=0u;
    //*pu32Value = 0u;
    return RTE_E_OK;
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

