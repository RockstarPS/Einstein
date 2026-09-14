/*---------------------------------------------------------------------------------------------------------------------

VISTEON CORPORATION CONFIDENTIAL
_______________________________

[2019] Visteon Corporation
All Rights Reserved.

NOTICE: This is an unpublished work of authorship, which contains trade secrets.
Visteon Corporat/ion owns all rights to this work and intends to maintain it in confidence to preserve
its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
under all copyright laws to protect this work as a published work, when appropriate.
Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
without the written authorization of Visteon Corporation.

---------------------------------------------------------------------------------------------------------------------*/
/*!*****************************************************************************************************************
*    @file DisplayMgrCdd.c
*    @ingroup DisplayCdd
*    @brief This file provides the Definitions of the DisplayMgrCdd APIs, which can be used to Activate and decativate and display
********************************************************************************************************************/
 #define DISPLAYCDD_C
/*****************************************************************************
 *                                 Include Files                              *
 ******************************************************************************/


#include "DisplayCdd_Types.h"

#include "DisplayCdd_Cfg.h"

#include "DisplayMgrCdd.h"
#include "DisplayIfCdd.h"

#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TIANMA
#include "DisplayDrvCdd_Tianma.h"
#endif

#ifdef CDISPLAYCDD_ENABLE_DISPLAY_SHARP
#include "DisplayDrvCdd_Sharp.h"
#endif

#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TRULY
#include "DisplayDrvCdd_Truly.h"
#endif

#include "CmpLib.h"

/*
void DisplayCdd_MainFunc(void);
Std_ReturnType DisplayCdd_Init(void);
*/

/*! @brief  Instance of cmplib life-cycle */
CMPLIB_INSTANCE(DisplayCdd)

/*!***************************************************************************************************************** 
*   @brief      Transitional initialization state
*   @param[in]  void
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed
********************************************************************************************************************/
static Std_ReturnType CmpInit(void)
{
	Std_ReturnType InitResult = E_NOT_OK;
	
	InitResult = DisplayMgrCdd_Init();
	if(E_OK == InitResult)
	{
		InitResult = DisplayIfCdd_Init();
		if(E_OK == InitResult)
		{
			InitResult = DisplayDrvCdd_Init();
		}
	}
	
    return InitResult;
}
/*!***************************************************************************************************************** 
*   @brief      Transitional De-initialization state
*   @param[in]  void
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed
********************************************************************************************************************/
static  Std_ReturnType CmpDeInit(void)
{ 
	Std_ReturnType DeInitResult = E_NOT_OK; 

	DeInitResult = DisplayDrvCdd_DeInit();
	DeInitResult = DisplayIfCdd_DeInit();
	DeInitResult = DisplayMgrCdd_DeInit();
	
	return DeInitResult;
}
/*!***************************************************************************************************************** 
*   @brief      Transitional Activation state
*   @param[in]  void
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed
********************************************************************************************************************/
static Std_ReturnType CmpDeActivation( void )
{
    
	return E_OK;
}
/*!***************************************************************************************************************** 
*   @brief      Transitional De-Activational state
*   @param[in]  void
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed
********************************************************************************************************************/
static Std_ReturnType CmpActivation( void )
{
    return  E_OK;
}
/*!***************************************************************************************************************** 
*   @brief      Transitional normal operations
*   @param[in]  void
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed
********************************************************************************************************************/
static Std_ReturnType CmpActive( void )
{
    DisplayMgrCdd_MainFunction();
	return  E_OK;
}
/*!***************************************************************************************************************** 
*   @brief      Transitional Diag operations
*   @param[in]  void
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed
********************************************************************************************************************/
static Std_ReturnType CmpDiag( void )
{
    return E_OK;
}
/*!***************************************************************************************************************** 
*   @brief      Transitional Diag operations
*   @param[in]  void
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed
********************************************************************************************************************/
static Std_ReturnType CmpDiagReturn( void )
{
    return E_OK;
}

/*!***************************************************************************************************************** 
*   @brief      The function de initialize the Deactivation of the display
*   @param[in]  EDisplayType this parameter specifies which display
*   @param[out]  EDisplayPowerState  this parameter is used to set tthe new power state - POWERON ,POWEROFF ,NORMAL,FAULT
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed
********************************************************************************************************************/
FUNC(Std_ReturnType, DisplayCdd_CODE) CDisplayCdd_SetState(EDisplayType DeviceID, EDisplayPowerState PowerState)
{
	Std_ReturnType SetStatusResult = E_NOT_OK;

	SetStatusResult = DisplayMgrCdd_SetState( DeviceID, PowerState);
	
	return SetStatusResult;
	
}
/*!***************************************************************************************************************** 
*   @brief      The function gets the current status of the display
*   @param[in]  EDisplayType this parameter specifies which display
*   @param[out]  EDisplayStatus this parameter is used to get the status
*   @param[out]  EDisplayPowerState this parameter is used to get the present power state
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed 
********************************************************************************************************************/
FUNC(Std_ReturnType, DisplayCdd_CODE) CDisplayCdd_GetStatus(EDisplayType DeviceId, P2VAR(EDisplayStatus, AUTOMATIC, RTE_DISPLAYCDD_APPL_VAR) DeviceStatus, P2VAR(EDisplayPowerState, AUTOMATIC, RTE_DISPLAYCDD_APPL_VAR) DevicePowerState)
{
	Std_ReturnType DisplayStatusResult = E_NOT_OK;
	
	DisplayStatusResult = DisplayMgrCdd_GetStatus( DeviceId,  DeviceStatus , DevicePowerState );
	
	return DisplayStatusResult;
}

#ifdef CDISPLAYCDD_ENABLEBISTTEST
/*!***************************************************************************************************************** 
*   @brief      The function is perorm the BIST test 
*   @param[in]  Device Id - For whihc the Bist test to be performed
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success 
********************************************************************************************************************/
FUNC(Std_ReturnType, DisplayCdd_CODE) CDisplayCdd_BistTest(EDisplayType DeviceId)
{
	Std_ReturnType BistResult = E_NOT_OK;
	
	BistResult = DisplayMgrCdd_BISTTest(DeviceId);
	
	return BistResult;
	
}
#endif

#ifdef CDISPLAYCDD_ENABLE_GAMMA_CORRECTION
/*!***************************************************************************************************************** 
*   @brief      To trigger the gamma correction operation
*   @param[in]  GmaSetPtr - Pointer having the gamma correction settings to be updated
*   @return  Std_ReturnType E_NOT_OK - Request not accepted
*                           E_OK - Request accepted
********************************************************************************************************************/
Std_ReturnType CDisplayCdd_SetGammaCorrection(uint8 *GmaSetPtr, uint8 datalength)
{
	Std_ReturnType RetVal;
	
	RetVal = DisplayMgrCdd_SetGammaCorrection(GmaSetPtr, datalength);
	return RetVal;
}

/*!***************************************************************************************************************** 
*   @brief      To get the current status of triggered gamma correction operation
*   @param[out]  GmaCrStatus - Pointer to update the gamma correction status
********************************************************************************************************************/
void CDisplayCdd_GetGammaCorrectionStatus(EGammaCorrectionStatus *GmaCrStatus)
{
	DisplayMgrCdd_GetGammaCorrectionStatus(GmaCrStatus);
}
/*
Std_ReturnType DisplayCdd_Init(void)
{
	Std_ReturnType RetVal;
	RetVal = CmpInit();
	return RetVal;
}

void DisplayCdd_MainFunc(void)
{
	CmpActive();
}
*/
#endif

/*----------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
Date              : 6/Apr/2020
By                : sgarg1
Traceability      : RTC #
Change Description: Initial Version
-------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 22/June/2020
By                : nrajaman
Traceability      : RTC # 835355
Change Description: Added Power and SPI sequence for 12 inch tianma display. 
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 22/June/2020
By                : nrajaman
Traceability      : RTC # 835355
Change Description: Updated PR comments 
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 8/July/2020
By                : nrajaman
Traceability      : RTC # 956295
Change Description: Fixed Coverity and Misra Warnings 
-----------------------------------------------------------------------------------------*/


