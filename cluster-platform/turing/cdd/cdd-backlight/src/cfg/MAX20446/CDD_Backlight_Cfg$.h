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

extern Std_ReturnType Backlight_DIn_GetProcessedValue(IoHwAb_DInSignalIdType InputId, boolean* ProcessedValue, IoHwAb_ErrorType* ErrorStatus);

#define	CBacklightCdd_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define BACKLIGHTCDD_DEV_ERROR_DETECT               STD_OFF

#define BACKLIGHTCDD_PERIOD_MSEC                    ((uint8)10u)
#define BACKLIGHTCDD_DEVICE_ID                      ((uint8)0u)
#define BACKLIGHTCDD_MAX_NUM_OF_DEVICES             ((uint8)1u)
#define cBACKLIGHTDRVCDD_INIT_DELAY_ONE				((uint32)120u)
#define cBACKLIGHTDRVCDD_RECOVERY_DELAY				((uint32)240u)
#define BACKLIGHTCDD_I2C_CHANNEL_ID                 ((uint8)2U)
#define BACKLIGHTCDD_I2C_SLAVE_ADDRESS              ((uint8)0x63U)

#define REG_COUNT_I2C 0x06u
#define REG_COUNT_PWM 0x0Cu

#define BACKLIGHTCDD_MAX_MON_REGS 1u   /*Make sure monitorLen and this matches*/

extern const BacklightCdd_ConfigType BacklightConfig;
extern const BacklightCdd_DescrType BacklightCdd_DrvTable;

#define DOUT_BACKLIGHT_EN    eIO_DOUT_DO_MD_BKLT_EN
#define DIN_BACKLIGHT_FLT    DioConf_DioChannel_DI_MD_BKLT_FAULT
#define DOUT_BACKLIGHT_DMN   eIO_DOUT_DO_MD_BKLT_DIM



/*Map with proper PWM signal eIO_PWM_DO_FPK_BKL_DIMMING*/
#define PWM_DO_FPK_BKL_DIMMING         1

#define OperatingVoltage_Normal                      ((uint8)1u)

/*CBACKLIGHTCDD_OPERATINGMODE need to map with function from EcumatteryM for voltage validation*/
#define CBACKLIGHTCDD_OPERATINGMODE() OperatingVoltage_Normal

extern const BacklightCdd_IOFuncType BacklightCdd_IOTable;


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

