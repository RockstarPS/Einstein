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
#ifndef __BACKLIGHTDRVCDD_I2C_H___
#define __BACKLIGHTDRVCDD_I2C_H___

//=====================================================================================================================
//  INCLUDED FILES
//=====================================================================================================================
#include "BacklightCdd_Types.h"
#include "BacklightCdd_Defines.h"
#include "BacklightDrvCdd.h"
#include "I2c.h"

//----------------------------------------------------------------------------------------------------------------------
// Constant data
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Exported type
//----------------------------------------------------------------------------------------------------------------------
	   
//----------------------------------------------------------------------------------------------------------------------
// Exported data
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Constant exported data
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Exported Macros
//----------------------------------------------------------------------------------------------------------------------

#define BACKLIGHTCDDI2CADAPTER_VARIANT_VISTEON_TV2_NEW     0x00u
#define BACKLIGHTCDDI2CADAPTER_VARIANT_VISTEON_TV2_OLD     0x01u
#define BACKLIGHTCDDI2CADAPTER_VARIANT_TI                  0x02u


//----------------------------------------------------------------------------------------------------------------------
// Exported functions
//----------------------------------------------------------------------------------------------------------------------

Std_ReturnType BacklightCdd_I2cWriteReg(uint8 reg, uint8 val);
BACKLIGHTCDD_InitRegCfgStateType BacklightDrvCdd_ManageConfigRegI2CTransmission( uint16 targetBrightness);
FUNC (void, CBacklightCdd_CODE) BacklightDrvCdd_I2C_Init();
FUNC(Std_ReturnType, CBacklightCdd_CODE) BacklightDrvCdd_Process_Set_Brightness(uint16 targetBrightness);
Std_ReturnType BacklightCdd_I2cAsyncRegRead(uint8 reg, uint8 index);
void BacklightCdd_I2cGetRxData(uint8 *val, uint8 index);
I2c_SeqResultType BacklightCdd_I2cGetSeqResult(uint8 seq);
void BacklightCdd_I2cCancel(uint8 seq);

#endif  // __BACKLIGHTDRVCDD_I2C_H___

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

