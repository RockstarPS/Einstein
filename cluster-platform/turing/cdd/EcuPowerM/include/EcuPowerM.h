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
#ifndef __ECUPOWERM_H__
#define __ECUPOWERM_H__


//=====================================================================================================================
//  INCLUDED FILES
//=====================================================================================================================
#include "EcuPowerM_Types.h"
#include "EcuPowerM_Defines.h"
#include "EcuPowerM_Version.h"
#include "EcuPowerM_LowlevelDrv.h"
#include "EcuPowerM_Det.h"
#include "EcuPowerM_Cfg.h"


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
extern FUNC(void, ECUPOWERM_CODE) EcuPowerM_Init(void);
extern FUNC(void, ECUPOWERM_CODE) EcuPowerM_DeInit(void);
extern FUNC(void, ECUPOWERM_CODE) EcuPowerM_InitInternalMemory(void);
extern FUNC(Std_ReturnType, ECUPOWERM_CODE) EcuPowerM_RequestPower(	VAR(uint8, AUTOMATIC) deviceId,
																   	VAR(EcuPowerM_DevicePwrRqstType, AUTOMATIC) request);
extern FUNC(void, ECUPOWERM_CODE) EcuPowerM_MainFunction(void);
extern FUNC(Std_ReturnType, ECUPOWERM_CODE) EcuPowerM_GetDeviceStatus(	VAR(uint8, AUTOMATIC) deviceId, 
																		P2VAR(EcuPowerM_DevicePwrStatusType, AUTOMATIC, ECUPOWERM_APPL_DATA) status);
extern FUNC(void, ECUPOWERM_CODE) EcuPowerM_UserCallback( VAR(EcuPowerM_HardwareIdType, AUTOMATIC) hwid, VAR(uint8, AUTOMATIC) status);

 
	   

#endif  // __ECUPOWERM_H__

/*==============================================================================================================================================
Date              	: 13-11-23
CDSID             	: skiranku
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/
