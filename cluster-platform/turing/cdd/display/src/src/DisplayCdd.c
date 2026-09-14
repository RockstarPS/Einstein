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

/*****************************************************************************
 *                                 Include Files                              *
 ******************************************************************************/
#include "DisplayCdd_Types.h"
#include "DisplayCdd_Cfg.h"
#include "DisplayMgrCdd.h"
#include "DisplayIfCdd.h"
#include "CmpLib.h"


#define CDisplayCdd_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include <CDisplayCdd_MemMap.h>
/*To Store Didplay AutoDetect Information*/
static sDisplayAutoDetect DisplayDetectInfo;

static uint8 DetectedDisplayId;

#define CDisplayCdd_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include <CDisplayCdd_MemMap.h>

/*! @brief  Instance of cmplib life-cycle */
CMPLIB_INSTANCE(DisplayCdd)

#define CDisplayCdd_START_SEC_CODE
#include <CDisplayCdd_MemMap.h>
/*!***************************************************************************************************************** 
*   @brief      Transitional initialization state
*   @param[in]  void
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed
********************************************************************************************************************/
static Std_ReturnType CmpInit(void)
{

	DisplayDetectInfo.DisplayCddInitState 				= DisplayInitNotStarted; /*Update Init state as not started*/
	DisplayDetectInfo.DisplayAutoDetectionEnabled 		= FALSE;
	DisplayDetectInfo.IdentifiedDeviceStatus 			= FALSE;
	DisplayDetectInfo.IdentifiedDeviceID 				= DISPLAYINVALID_ID;
	DetectedDisplayId 									= DISPLAYINVALID_ID;
	return E_OK;
}
/*!***************************************************************************************************************** 
*   @brief      Transitional De-initialization state
*   @param[in]  void
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed
********************************************************************************************************************/
static  Std_ReturnType CmpDeInit(void)
{ 
	DisplayDetectInfo.DisplayCddInitState				= DisplayInitNotStarted; /*Update Init state as not started*/
	DisplayDetectInfo.DisplayAutoDetectionEnabled 		= FALSE;
	DisplayDetectInfo.IdentifiedDeviceStatus 			= FALSE;
	DisplayDetectInfo.IdentifiedDeviceID 				= DISPLAYINVALID_ID;
	DetectedDisplayId 									= DISPLAYINVALID_ID;
	return E_OK;
}
/*!***************************************************************************************************************** 
*   @brief      Transitional Activation state
*   @param[in]  void
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed
********************************************************************************************************************/
static Std_ReturnType CmpDeActivation( void )
{

	DisplayCdd_Cfg_DeInit();
	DisplayIfCdd_DeInit();
	DisplayMgrCdd_DeInit();

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
	Std_ReturnType ActResult = E_NOT_OK;
	Std_ReturnType DispPreCheckStatus  = E_NOT_OK;

	/*PrecheckPtr is configurable, Return E_OK once All preconditions are succeeded */
	DispPreCheckStatus = DisplayInitCheck.displayPrecheck_ptr();
	if((uint8)E_NOT_OK != DispPreCheckStatus)
	{
		/*
		 1. After Precheck pass if NVM read displayID not require then switch state to start_init
		 2. If NVM_read DisplayID is reqired and displayId is valid switch state to start_init
		 3. If nvm_read DisplayID is invalid and not within maxconfigure switch to DisplayInitAutoDetect State
		*/

		if(DisplayInitCheck.displayReadNVMDisplayType != DISP_NULL)
		{

			(void)DisplayInitCheck.displayReadNVMDisplayType(DetectedDisplayId);
			if((DISPLAYINVALID_ID == DetectedDisplayId) || (cDISPLAYCDD_MAX_DEVICE <= DetectedDisplayId))// autodetct
			{
				DisplayDetectInfo.DisplayAutoDetectionEnabled = TRUE;
			
				DisplayDetectInfo.DisplayCddInitState = DisplayInitCompleted; /*Update Init state as completed to start state machine*/
				ActResult= E_OK;
			}
			else
			{
				/* Valid ID within Max Device */
				DisplayDetectInfo.IdentifiedDeviceID 				= DetectedDisplayId;
				DisplayDetectInfo.IdentifiedDeviceStatus 			= TRUE;
				DisplayDetectInfo.DisplayCddInitState = DisplayStartInit; /*Start Initializing Device*/
			}
		}
		else
		{
			/* NVM Read is not applicable then Start Initializing all connected Device*/
			DisplayDetectInfo.DisplayCddInitState =DisplayStartInit; 
		}
	}
	else
	{
		//stay in activation until precheck ptr returns E_OK
		ActResult = E_NOT_READY;
	}

	if(DisplayDetectInfo.DisplayCddInitState == DisplayStartInit)
	{
		DisplayMgrCdd_Init(); //Initialize DisplayMgrCdd
		DisplayIfCdd_Init(); //Initialize DisplayIfCdd and DisplayDrvCdd
		DisplayCdd_Cfg_Init(); //Initialize DisplayCddCfg
		DisplayDetectInfo.DisplayCddInitState = DisplayInitCompleted ; /* Update Init Status as Completed */
		ActResult = E_OK;

	}

	//Update Detect Device Status
	DisplayIfCdd_UpdateAutoDetect(DisplayDetectInfo);

 return  ActResult;
}
/*!***************************************************************************************************************** 
*   @brief      Transitional normal operations
*   @param[in]  void
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed
********************************************************************************************************************/
static Std_ReturnType CmpActive( void )
{
	/*Start main function once Init completed*/
	if(DisplayDetectInfo.DisplayCddInitState == DisplayInitCompleted)
	{	
    	DisplayMgrCdd_MainFunction();
	}
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
*   @brief      The function display used to set the display to ON or OFF state
*   @param[in]  EDisplayType this parameter specifies which display
*   @param[in]  EDisplayPowerState  this parameter is used to set tthe new power state - POWERON ,POWEROFF ,NORMAL,FAULT
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed
********************************************************************************************************************/
FUNC(Std_ReturnType, DisplayCdd_CODE) CDisplayCdd_SetState(EDisplayType DeviceID, EDisplayPowerState PowerState)
{
	Std_ReturnType DisplaySetStatusResult = E_NOT_OK;

	/*Invoke Mgr Layer*/
	DisplaySetStatusResult = DisplayMgrCdd_SetState(DeviceID, PowerState);
	
	return DisplaySetStatusResult;
	
}
/*!***************************************************************************************************************** 
*   @brief      The function gets the current status of the display
*   @param[in]  EDisplayType this parameter specifies which display
*   @param[out]  EDisplayCddStatus this parameter is used to get the status
*   @param[out]  EDisplayPowerState this parameter is used to get the present power state
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed 
********************************************************************************************************************/
FUNC(Std_ReturnType, DisplayCdd_CODE) CDisplayCdd_GetStatus(EDisplayType DeviceId, P2VAR(EDisplayCddStatus, AUTOMATIC, RTE_DISPLAYCDD_APPL_VAR) DeviceStatus, P2VAR(EDisplayPowerState, AUTOMATIC, RTE_DISPLAYCDD_APPL_VAR) DevicePowerState)
{
	Std_ReturnType DisplayGetStatusResult = E_NOT_OK;
	
	/*Invoke Mgr layer*/
	DisplayGetStatusResult = DispMgrCdd_GetDisplayStatus(DeviceId,DeviceStatus , DevicePowerState );
	
	return DisplayGetStatusResult;
}
/*!***************************************************************************************************************** 
*   @brief      The function is to perform the BIST test 
*   @param[in]  Device Id - For which the Bist test to be performed
*   @param[in]  BistPatternType - Pattern Identifier
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success 
********************************************************************************************************************/
FUNC(Std_ReturnType, DisplayCdd_CODE) CDisplayCdd_BistTest_Start(EDisplayType DeviceId, EBistPatternType BistPatternType, uint8 PatternHoldTime)

{
    Std_ReturnType BistResult = E_NOT_OK;

    BistResult = DisplayMgrCdd_BistTest_Start(DeviceId, BistPatternType, PatternHoldTime);

    return BistResult;
}

/*!***************************************************************************************************************** 
*   @brief      The function is to stop the BIST test 
*   @param[in]  Device Id - For which the Bist test to be disabled
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success 
********************************************************************************************************************/
FUNC(Std_ReturnType, DisplayCdd_CODE) CDisplayCdd_BistTest_Stop(EDisplayType DeviceId)
{
    Std_ReturnType BistResult = E_NOT_OK;

    BistResult = DisplayMgrCdd_BistTest_Stop(DeviceId);

    return BistResult;
}

#define CDisplayCdd_STOP_SEC_CODE
#include <CDisplayCdd_MemMap.h>

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
/*---------------------------------------------------------------------------------------
Date              : 2/Feb/2020
By                : nrajaman
Traceability      : RTC # 1199099
Change Description: Updated to support multi display during Run time
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 10/Nov/2021
By                : vkathir1
Traceability      : RTC #1487856
Change Description: Updated to support single display and Multiple display.
-----------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
Date              : 17/Jul/2023
By                : vvijaya5
Traceability      : RTC #
Change Description: Review comment fix and memmap addition
-------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
Date              : 21/Jan/2025
By                : kmadhuso
Traceability      : JIRA #REN31759-24956
Change Description: BIST Trigger and Stop interfaces added
-------------------------------------------------------------------------------*/

