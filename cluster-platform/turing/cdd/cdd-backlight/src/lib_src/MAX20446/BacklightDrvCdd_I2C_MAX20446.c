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


//=====================================================================================================================
//  INCLUDED FILES
//=====================================================================================================================
#include "BacklightDrvCdd_I2C.h"
#include "Rte_Type.h"
#include "BacklightCdd_ErrorHandler.h"
#include "BacklightDrvCdd_I2C_MAX20446.h"
//=====================================================================================================================
//  PREPROCEESSORS
//=====================================================================================================================


//=====================================================================================================================
//  LOCAL FUNCTIONS
//=====================================================================================================================


void MAX20446_CalcDutyRegisters (uint16 targetBrightness , uint8* txBuf);

//=====================================================================================================================
//  INITIALIZED DATA DECLARATIONS (.DATA)
//=====================================================================================================================

const BacklightChipType* BacklightChipHandler = NULL;

const BacklightChipType BacklightChip_MAX20446 =
{
	.CalcDutyRegisters = MAX20446_CalcDutyRegisters
};


#define CBacklightCdd_START_SEC_CODE
#include "MemMap.h"

//======================================================================================================================
/** \brief BacklightDrvCdd_I2C_Init
 **
 ** This function initializes I2C chip handler.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC (void,CBacklightCdd_CODE ) BacklightDrvCdd_I2C_Init(void)
{
	BacklightChipHandler = &BacklightChip_MAX20446;
}

//======================================================================================================================
/** \brief MAX20446_CalcDutyRegisters
 **
 ** This function update register data for I2C.
 **
 ** \param[in] targetBrightness Target brightness value.
 **            txBuf            Buffer holding target brightness value after scaling
 **           
 ** \return    None.
 **
 ** */
//======================================================================================================================
void MAX20446_CalcDutyRegisters (uint16 targetBrightness , uint8* txBuf)
{
	uint8 pwm1_0, pwm9_2, pwm17_10;

	uint32 duty;

	duty =  (uint32) ((targetBrightness * BACKLIGHTMGRCDD_PWM_BIT_RESOLUTION)/100U);

	pwm1_0 = (uint8)( duty & (uint32)0x03);
    pwm9_2 = (uint8)( duty >> 2u) & 0xFFu;
    pwm17_10 = (uint8)( duty >> 10u) & 0xFFu;

	txBuf[0] = 0x04u;		// starting register address
    txBuf[1] = pwm17_10;	// 0x04 - TONH1 - PWM1[17:10]
    txBuf[2] = pwm9_2;		// 0x05 - TONL1 - PWM1[9:2]
    txBuf[3] = pwm17_10; 	// 0x06 - TONH2 - PWM2[17:10]
    txBuf[4] = pwm9_2; 		// 0x07 - TONL2 - PWM2[9:2]
    txBuf[5] = pwm17_10;  	// 0x08 - TONH3 - PWM3[17:10]
    txBuf[6] = pwm9_2; 		// 0x09 - TONL3 - PWM3[9:2]
    txBuf[7] = pwm17_10;  	// 0x0A - TONH4 - PWM4[17:10]
    txBuf[8] = pwm9_2; 		// 0x0B - TONL4 - PWM4[9:2]
    txBuf[9] = (pwm1_0 | (uint8) (pwm1_0 << 2u) | (uint8) (pwm1_0 << 4u) | (uint8) (pwm1_0 << 6u));
    txBuf[10] = pwm17_10;  	// 0x0D - TONH5 - PWM5[17:10]
    txBuf[11] = pwm9_2;  	// 0x0E - TONL5 - PWM5[9:2]
    txBuf[12] = pwm17_10;  	// 0x0F - TONH6 - PWM6[17:10]
    txBuf[13] = pwm9_2;  	// 0x10 - TONL6 - PWM6[9:2]
    txBuf[14] = (pwm1_0 | (uint8) (pwm1_0 << 2u));  // 0x11 - TON5-6LSB - PWM6[1:0],PWM5[1:0]

}


#define CBacklightCdd_STOP_SEC_CODE
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
Traceability      	: ASCDD-106
Change Description	: Fixed KW warnings.
================================================================================================================================================*/


