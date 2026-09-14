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
//------------------------------------------------------------------------------------------------------------------------
#ifndef __CDD_BACKLIGHT_CFG_H__
#define __CDD_BACKLIGHT_CFG_H__

#include "BacklightCdd_Types.h"
#include "Dio_Cfg.h"
#include "IoHwAb_DOut_Cfg.h"
#include "I2c.h"
#include "EcuPowerM_Types.h"


extern Std_ReturnType Backlight_DIn_GetProcessedValue(IoHwAb_DInSignalIdType InputId, boolean* ProcessedValue, IoHwAb_ErrorType* ErrorStatus);

#define	CBacklightCdd_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define BACKLIGHTCDD_DEV_ERROR_DETECT               STD_ON

#define BACKLIGHTCDD_PERIOD_MSEC                    ((uint8)10u)
#define BACKLIGHTCDD_DEVICE_ID                      ((uint8)0u)
#define BACKLIGHTCDD_MAX_NUM_OF_DEVICES             ((uint8)1u)
#define cBACKLIGHTDRVCDD_INIT_DELAY_ONE				((uint32)120u)
#define cBACKLIGHTDRVCDD_RECOVERY_DELAY				((uint32)240u)
#define BACKLIGHTCDD_I2C_CHANNEL_ID                 ((uint8)2U)
#define BACKLIGHTCDD_I2C_SLAVE_ADDRESS              ((uint8)0x63U)

#define REG_COUNT_I2C 0x14u
#define REG_COUNT_PWM 0x0Cu

#define BACKLIGHTCDD_MAX_MON_REGS 1u   /*Make sure monitorLen and this matches*/

extern const BacklightCdd_ConfigType BacklightConfig;
extern const BacklightCdd_DescrType BacklightCdd_DrvTable;

#define DOUT_BACKLIGHT_EN    DioConf_DioChannel_DO_CID_BKL_EN
#define DIN_BACKLIGHT_FLT    DioConf_DioChannel_DI_CID_BKL_FAULT
/*Map with proper DIO/eIO signal  DioConf_DioChannel_DO_CID_BKL_DIM*//*CHECK WITH MCAL FOR PIN CONFIG IN Dio.h*/
#define DOUT_BACKLIGHT_DMN   



/*Map with proper PWM signal eIO_PWM_DO_FPK_BKL_DIMMING*/
#define PWM_DO_FPK_BKL_DIMMING         1

#define OperatingVoltage_Normal                      ((uint8)1u)

/*CBACKLIGHTCDD_OPERATINGMODE need to map with function from EcumatteryM for voltage validation*/
#define CBACKLIGHTCDD_OPERATINGMODE() OperatingVoltage_Normal

extern const BacklightCdd_IOFuncType BacklightCdd_IOTable;
FUNC(Std_ReturnType, BACKLIGHT_CODE)
Backlight_IoHwAb_WriteWrapper(uint8 ChannelId,
                              uint8 Level,
                              Std_ReturnType* ErrPtr);

//to be checked
//Std_ReturnType BacklightCdd_ReadDigitalInputs(uint8 *pu8Value);
FUNC(Std_ReturnType, CBacklightCdd_CODE) BacklightCdd_ReadDigitalInputs(P2VAR(uint8, AUTOMATIC, RTE_CBACKLIGHTCDD_APPL_VAR) pArgP);
//Std_ReturnType BacklightCdd_ReadBacklightFaults(uint32 *pu32Value);
FUNC(Std_ReturnType, CBacklightCdd_CODE) BacklightCdd_ReadBacklightFaults(P2VAR(uint32, AUTOMATIC, RTE_CBACKLIGHTCDD_APPL_VAR) pArgP);
#define	CBacklightCdd_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


#endif /* BACKLIGHTCDD_CFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      
********************************************************************************************************************/

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

