/*---------------------------------------------------------------------------------------------------------------------

VISTEON CORPORATION CONFIDENTIAL
_______________________________

[2019] Visteon Corporation
All Rights Reserved.

NOTICE: This is an unpublished work of authorship, which contains trade secrets.
Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
under all copyright laws to protect this work as a published work, when appropriate.
Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
without the written authorization of Visteon Corporation.

---------------------------------------------------------------------------------------------------------------------*/
/*!*****************************************************************************************************************
*    @file DisplayIfCdd.c
*    @ingroup DisplayCdd
*    @brief This file provides the Definitions of the DisplayIfCdd APIs. This header file should be included by other  
*    modules that use these APIs.
********************************************************************************************************************/
/*****************************************************************************
 *                                 Include Files                              *
 ******************************************************************************/
 
#include "DisplayCdd_Types.h" 
#include "DisplayCdd_Cfg.h"
#include "DisplayIfCdd.h"
#include "DisplayDrvCdd.h"

#define CDisplayCdd_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include <CDisplayCdd_MemMap.h>

/*To store If layer AutoDetect Status*/
static sDisplayAutoDetect DisplayIfCddDetectInfo;

/*To store Displaystatus and its power state*/
static SDisplayInfo DisplayInfoTable[cDISPLAYCDD_MAX_DEVICE];

#define CDisplayCdd_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include <CDisplayCdd_MemMap.h>


#define CDisplayCdd_START_SEC_CODE
#include <CDisplayCdd_MemMap.h>
/*!***************************************************************************************************************** 
*   @brief      The function initialize the displayIfCdd layer
*   @param[in]  void
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success
********************************************************************************************************************/
void DisplayIfCdd_Init(void)
{
	uint8 Device_No;

	/*Display Identified then Initialize Identified_Dev_ID else Initialize all*/
	if((FALSE != DisplayIfCddDetectInfo.IdentifiedDeviceStatus) && (cDISPLAYCDD_MAX_DEVICE > DisplayIfCddDetectInfo.IdentifiedDeviceID))
	{
		/*Initialize the Identified device Id */
		DisplayInfoTable[DisplayIfCddDetectInfo.IdentifiedDeviceID].DeviceStatus        		= eDeviceNotReady;
		DisplayInfoTable[DisplayIfCddDetectInfo.IdentifiedDeviceID].DevicePowerState      	= eDisplayIdle;
		DisplayDrvCdd_Init(DisplayIfCddDetectInfo.IdentifiedDeviceID);
	}
	else
	{
		/*Initialize all Configured devices */
		for(Device_No = cDISPLAYCDD_DEVICE_0; Device_No < cDISPLAYCDD_MAX_DEVICE; Device_No++)
		{
			DisplayInfoTable[Device_No].DeviceStatus        			= eDeviceNotReady;
			DisplayInfoTable[Device_No].DevicePowerState      			= eDisplayIdle;
			DisplayInfoTable[Device_No].DisplayNotifiedState			= eDisplayNotify_Idle;
			/*Initialize the Drv structures*/
			DisplayDrvCdd_Init(Device_No);
		}
	}
	
}
/*!***************************************************************************************************************** 
*   @brief      The function de-initialize the displayIfCdd layer
*   @param[in]  void
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success
********************************************************************************************************************/
void DisplayIfCdd_DeInit( void)
{
	uint8 Device_No;

	//Deactivate all device Id's
	for(Device_No = cDISPLAYCDD_DEVICE_0; Device_No < cDISPLAYCDD_MAX_DEVICE; Device_No++)
	{
		DisplayInfoTable[Device_No].DeviceStatus          			= eDeviceNotReady;
		DisplayInfoTable[Device_No].DevicePowerState      			= eDisplayIdle;
		DisplayInfoTable[Device_No].DisplayNotifiedState			= eDisplayNotify_Idle;
		
		/*DeInitialize the Drv structures*/
		DisplayDrvCdd_DeInit(Device_No);
	}
	
}

/*!***************************************************************************************************************** 
*   @brief      Periodic function  is used to perform power handling and fault monitor 
*   @param[in]  void
*   @return  	Void
********************************************************************************************************************/
void DisplayIfCdd_MainFunction(void)
{
	uint8 Device_No;

	/*Check for Auto Detection*/
	if(FALSE != DisplayIfCddDetectInfo.DisplayAutoDetectionEnabled)
	{
		/*If Device Identified then, start main function of identified device ID */
		if(FALSE != DisplayIfCddDetectInfo.IdentifiedDeviceStatus)
		{
			DisplayDrvCdd_MainFunction(DisplayIfCddDetectInfo.IdentifiedDeviceID);
		}
		/*Else identify the device ID and start its statemachine*/
		else 
		{
			if(eDisplayBootStrap == DisplayInitCheck.DisplayDetectMethod)
			{
				//Init should be one of the state for bootsrap statemachine. 
				//Upon bootsrap completed If needed device should enter into i2cmode
				//If not required upon completion and found device ID notify if cdd as display Identified and with Id
				DisplayDrvCdd_MainFunction(cDisplayBootStrapID);
			}
			else if(eDisplayI2Cdetect == DisplayInitCheck.DisplayDetectMethod)
			{
				//I2Cdetect method return OK Once Device is Identified successfully. Else DisplayId stays with invalid Value
				DisplayDetectI2CMethod();
				//Upon completion of I2C method Identified status will be updated to true.
			}
			else
			{
				//do nothing
			}
		}
	}
	else
	{
		for(Device_No = cDISPLAYCDD_DEVICE_0; Device_No < cDISPLAYCDD_MAX_DEVICE; Device_No++)
		{
			/*Invoke the Driver layer main function to perform Display power , fault sequence */
			DisplayDrvCdd_MainFunction(Device_No);
		}
	}

}

/*!***************************************************************************************************************** 
*   @brief      Function used to update Identified Structure from wrapperlayer 
*   @param[in]  sDisplayAutoDetect structure
*   @return  	Void
********************************************************************************************************************/
void DisplayIfCdd_UpdateAutoDetect(sDisplayAutoDetect AutoDetect_strctPtr)
{
	if(DisplayStartInit == DisplayIfCddDetectInfo.DisplayCddInitState)
	{
		DisplayIfCddDetectInfo.IdentifiedDeviceStatus 		= AutoDetect_strctPtr.IdentifiedDeviceStatus;
		DisplayIfCddDetectInfo.DisplayCddInitState    		= AutoDetect_strctPtr.DisplayCddInitState;
    	DisplayIfCddDetectInfo.DisplayAutoDetectionEnabled  = AutoDetect_strctPtr.DisplayAutoDetectionEnabled;
    	DisplayIfCddDetectInfo.IdentifiedDeviceID			= AutoDetect_strctPtr.IdentifiedDeviceID;
		//Other way is : - DisplayIfCddDetectInfo = AutoDetect_strctPtr;
	}
}

/*!***************************************************************************************************************** 
*   @brief      Function used to update Identified Device statua from Other layer 
*   @param[in]  IdentifiedDeviceID, IdentifiedDevStatus
*   @return  	void 
********************************************************************************************************************/

void DisplayIfCdd_UpdateIdentifiedDeviceStatus(EDisplayType IdentifiedDeviceID, boolean IdentifiedDevStatus)
{
	if(IdentifiedDeviceID < cDISPLAYCDD_MAX_DEVICE)
	{

		DisplayIfCddDetectInfo.IdentifiedDeviceID= IdentifiedDeviceID;
		DisplayIfCddDetectInfo.IdentifiedDeviceStatus = IdentifiedDevStatus;
	}
}
/*!***************************************************************************************************************** 
*   @brief      The function is used to the new state to particular display
*   @param[in]  DeviceId - Device ID - Tianma 8inch , Tianma 12 inch , Sharp , Truly 
*               NewState  - New state as POWERON , POWEROFF , FAUTLTHANDLE       
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed 
********************************************************************************************************************/
Std_ReturnType DisplayIfCdd_SetState(EDisplayType DeviceId, EDisplayPowerState NewState )
{
	Std_ReturnType Dispif_status = E_NOT_OK;

	/*Requested Powerstate should be within min and max*/
	if((NewState > eDisplayIdle) && (NewState < eDisplayMaxPowerState) && (cDISPLAYCDD_MAX_DEVICE > DeviceId))
	{	
		/*-----------------ALGO----------------------
		1. Check the device is not busy so it wont accept new request
		2. Requested State and current Device PowerState should not be equal
		3. The requested PowerState should be equal to ON/OFF. Other states like fault and Normal is not acceptable and it will return E_NOT_OK*/

		if((eDisplayBusy != DisplayInfoTable[DeviceId].DeviceStatus) && \
		(NewState != DisplayInfoTable[DeviceId].DevicePowerState))
		{
			if((eDisplayPowerON == NewState) || (eDisplayPowerOFF == NewState))
        	{
				/*Set the particular display status as busy indicating , going to perform the requested power state transistion*/
				DisplayInfoTable[DeviceId].DeviceStatus = eDisplayBusy;
				/*Call the driver layer to execute the new power state*/
				Dispif_status = DisplayDrvCdd_SetState(DeviceId, NewState);
			}
		}
		else
		{
			//Need to check whether we need to store it in buffer
		}
	}
	return Dispif_status;
	
}


/*!***************************************************************************************************************** 
*   @brief      The function gets the current status of the display
*   @param[in]  EDisplayType this parameter specifies which display
*   @param[out]  EDisplayCddStatus this parameter is used to get the status
*   @param[out]  EDisplayPowerState this parameter is used to get the present power state
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed 
********************************************************************************************************************/
Std_ReturnType DispIfCdd_GetDisplayStatus(EDisplayType DeviceId, EDisplayStatus *GetDeviceStatus , EDisplayPowerState *GetPresentPowerState )
{
	Std_ReturnType Status = E_NOT_OK;

	if( cDISPLAYCDD_MAX_DEVICE > DeviceId)
	{
		*GetPresentPowerState = DisplayInfoTable[DeviceId].DevicePowerState;
		
		*GetDeviceStatus = DisplayInfoTable[DeviceId].DeviceStatus;

		Status= E_OK;
	}

	return Status;
}


/*!***************************************************************************************************************** 
*   @brief      
*   @param[in]  DeviceId - Device ID - Tianma 8inch , Tianma 12 inch , Sharp , Truly 
*               NewState  - New state as POWERON , POWEROFF , FAUTLTHANDLE       
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed 
********************************************************************************************************************/
void DispIfCdd_UpdateDisplayStatus(uint8 DeviceIndex,EDisplayPowerState CompletedPowerState, EDisplayCddStatus Devicestatus)
{
	if(cDISPLAYCDD_MAX_DEVICE > DeviceIndex)
	{
		DisplayInfoTable[DeviceIndex].DeviceStatus = Devicestatus;		
		DisplayInfoTable[DeviceIndex].DevicePowerState = CompletedPowerState;	
	}	
	
}

/*!***************************************************************************************************************** 
*   @brief      The function is to perform the BIST test 
*   @param[in]  Device Id - For which the Bist test to be performed
*   @param[in]  BistPatternType - Pattern Identifier
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success 
********************************************************************************************************************/
FUNC(Std_ReturnType, DisplayCdd_CODE) DispIfCdd_BistTest_Start(EDisplayType DeviceId, EBistPatternType BistPatternType, uint8 PatternHoldTime)
{
    Std_ReturnType BistResult = E_NOT_OK;

    BistResult = DisplayDrvCdd_BistTest_Start(DeviceId, BistPatternType, PatternHoldTime);
    return BistResult;
}

/*!***************************************************************************************************************** 
*   @brief      The function is to stop the BIST test 
*   @param[in]  Device Id - For which the Bist test to be disabled
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success 
********************************************************************************************************************/
FUNC(Std_ReturnType, DisplayCdd_CODE) DispIfCdd_BistTest_Stop(EDisplayType DeviceId)
{
    Std_ReturnType BistResult = E_NOT_OK;

    BistResult = DisplayDrvCdd_BistTest_Stop(DeviceId);
    return BistResult;
}

#define CDisplayCdd_STOP_SEC_CODE
#include <CDisplayCdd_MemMap.h> 
/* DISPLAYIFCDD_C */

/*----------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
Date              : 6/Apr/2020
By                : sgarg1
Traceability      : RTC #
Change Description: Initial Version
-------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
Date              : 17/Jul/2023
By                : vvijaya5
Traceability      : RTC #
Change Description: Review comment fix and memmap addition
-------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 21/Jan/2025
By                : kmadhuso
Traceability      : JIRA #REN31759-24956
Change Description: BIST Trigger and Stop interfaces added
-----------------------------------------------------------------------------------------*/
