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


#define BACKLIGHTCDD_DEV_ERROR_DETECT               STD_OFF

#define BACKLIGHTCDD_PERIOD_MSEC                    ((uint8)10u)
#define BACKLIGHTCDD_DEVICE_ID                      ((uint8)0u)
#define BACKLIGHTCDD_MAX_NUM_OF_DEVICES             ((uint8)1u)

extern const BacklightCdd_ConfigType BacklightConfig;
extern const BacklightCdd_DescrType BacklightCdd_DrvTable;


#define PWM_BACKLIGHT                                ((uint8)1u)

#define OperatingVoltage_Normal                      ((uint8)1u)

/*CBACKLIGHTCDD_OPERATINGMODE need to map with function from EcumatteryM for voltage validation*/
#define CBACKLIGHTCDD_OPERATINGMODE() OperatingVoltage_Normal

extern const BacklightCdd_IOFuncType BacklightCdd_IOTable;

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
