//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2023] Visteon Corporation
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
#ifndef ECUBATTERYM_H
#define ECUBATTERYM_H


//=====================================================================================================================
//  INCLUDED FILES
//=====================================================================================================================
#include "EcuBatteryM_Types.h"
#include "EcuBatteryM_Defines.h"
#include "EcuBatteryM_Version.h"
#include "EcuBatteryM_Det.h"
#include "EcuBatteryM_Cfg.h"


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
extern FUNC(void, ECUBATTERYM_CODE) EcuBatteryM_Init(void);
extern FUNC(void, ECUBATTERYM_CODE) EcuBatteryM_DeInit(void);
extern FUNC(void, ECUBATTERYM_CODE) EcuBatteryM_MonitorChannels(void);
extern FUNC(void, ECUBATTERYM_CODE) EcuBatteryM_MonitorChannel(uint8 channel);
extern FUNC(Std_ReturnType, ECUBATTERYM_CODE) EcuBatteryM_GetChannelStatus(VAR(uint8, AUTOMATIC) channel, 
	                                                                      P2VAR(uint8, AUTOMATIC, ECUBATTERYM_APPL_DATA) status
                                                                         );
 
	   

#endif  // __ECUBATTERYM_H__

/*==============================================================================================================================================
Date              	: 21-02-2025
CDSID             	: tgunasek
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/
