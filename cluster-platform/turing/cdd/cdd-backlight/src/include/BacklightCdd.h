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
#ifndef BACKLIGHTCDD_H
#define BACKLIGHTCDD_H

//=====================================================================================================================
//  INCLUDED FILES
//=====================================================================================================================
#include "BacklightCdd_Types.h"
#include "BacklightCdd_Defines.h"
#include "BacklightCdd_Version.h"
#include "BacklightCdd_ErrorHandler.h"


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
extern FUNC(void, CBacklightCdd_CODE) BacklightCdd_Init(void);
extern FUNC(void, CBacklightCdd_CODE) BacklightCdd_DeInit(void);
extern FUNC(Std_ReturnType, CBacklightCdd_CODE) CBacklightCdd_RequestPower(VAR(uint8, AUTOMATIC)deviceId, 
	                                                                  VAR(BacklightDrvCdd_PwrStType, AUTOMATIC)state);
extern FUNC(void, CBacklightCdd_CODE) BacklightCdd_MainFunction(void);
extern FUNC(void, CBacklightCdd_CODE) CBacklightCdd_EnterSafeState(void);
extern FUNC(void, CBacklightCdd_CODE) CBacklightCdd_ExitSafeState(void);


#endif  // __BACKLIGHTCDD_H__

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

