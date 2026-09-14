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
#ifndef __BACKLIGHTDRVCDD_I2C_MAX20446_H___
#define __BACKLIGHTDRVCDD_I2C_MAX20446_H___

//=====================================================================================================================
//  INCLUDED FILES
//=====================================================================================================================
#include "BacklightCdd_Types.h"
#include "BacklightDrvCdd.h"

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

//----------------------------------------------------------------------------------------------------------------------
// Exported functions
//----------------------------------------------------------------------------------------------------------------------

FUNC (void, CBacklightCdd_CODE) BacklightDrvCdd_I2C_Init(void);
extern const BacklightChipType* BacklightChipHandler;

#endif  // __BACKLIGHTDRVCDD_I2C_MAX20446_H___

/*==============================================================================================================================================
Date              	: 03-04-26
CDSID             	: bmahesan
Traceability      	: ASCDD-189
Change Description	: initial version
================================================================================================================================================*/
/*==============================================================================================================================================
Date              	: 04-07-26
CDSID             	: mmahend2
Traceability      	: ASCDD-106 ,ASCDD-357
Change Description	: 1) Fixed KW warnings. 2) Updated Backlight Fault monitoring Logic
================================================================================================================================================*/

