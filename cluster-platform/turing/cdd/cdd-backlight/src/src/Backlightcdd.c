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
#include "Rte_CBacklightCdd.h"
#include "CDD_Backlight_Cfg.h"
#include "BacklightCdd.h"
#include "BacklightDrvCdd.h"

//=====================================================================================================================
//  PREPROCEESSORS
//=====================================================================================================================

//=====================================================================================================================
//  LOCAL FUNCTIONS
//=====================================================================================================================

//=====================================================================================================================
//  CONST DATA DECLARATIONS (.ROM)
//=====================================================================================================================

//=====================================================================================================================
//  INITIALIZED DATA DECLARATIONS (.DATA)
//=====================================================================================================================
static VAR(uint8, 							CBacklightCdd_VAR_INIT) 	BacklightCdd_InitStatus 				= BACKLIGHTCDD_S_UNINITIALIZED;

//=====================================================================================================================
//  UNINITIALIZED DATA DECLARATIONS(.BSS)
//=====================================================================================================================



//======================================================================================================================
/** \brief BacklightCdd_Init
 **
 ** This function initializes Backlight driver.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, CBacklightCdd_CODE)  BacklightCdd_Init(void)
{
	if(BACKLIGHTCDD_S_INITIALIZED == BacklightCdd_InitStatus )
    {
        /* Report an error */
        BacklightCdd_ReportError(BACKLIGHTCDD_API_INIT, BACKLIGHTCDD_E_ALREADY_INITIALIZED);
    }
    else
    {   
        BacklightCdd_DrvTable.pfInit();
        BacklightCdd_InitStatus = BACKLIGHTCDD_S_INITIALIZED;
    }
}
//======================================================================================================================
/** \brief BacklightCdd_DeInit
 **
 ** This function De-initializes Backlight driver.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, CBacklightCdd_CODE) BacklightCdd_DeInit(void)
{
    if (BACKLIGHTCDD_S_UNINITIALIZED == BacklightCdd_InitStatus)
    {
        /* Report an error */
        BacklightCdd_ReportError(BACKLIGHTCDD_API_DEINIT, BACKLIGHTCDD_E_UNINIT);
    }
    else
    {
        BacklightCdd_DrvTable.pfDeInit();
        BacklightCdd_InitStatus = BACKLIGHTCDD_S_UNINITIALIZED;
    }
}

//======================================================================================================================
/** \brief CBacklightCdd_RequestPower
 **
 ** This function requests device power.
 **
 ** \param[in] device        device Id.
 ** \param[in] state         Target power state

 **
 ** \return    E_OK          Request accepted.
 **            E_NOT_OK      Device busy, Request not accepted
 **
 ** */
//======================================================================================================================
FUNC(Std_ReturnType, CBacklightCdd_CODE) CBacklightCdd_RequestPower
(
	VAR(uint8, AUTOMATIC)deviceId, 
	VAR(BacklightDrvCdd_PwrStType, AUTOMATIC)state
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = E_NOT_OK;
	
	if(BACKLIGHTCDD_S_UNINITIALIZED == BacklightCdd_InitStatus)
	{
        /* Report an error */
        BacklightCdd_ReportError(BACKLIGHTCDD_API_REQUEST_POWER, BACKLIGHTCDD_E_UNINIT);
	}
	else if(BACKLIGHTCDD_MAX_NUM_OF_DEVICES <= deviceId)
	{
        /* Report an error */
        BacklightCdd_ReportError(BACKLIGHTCDD_API_REQUEST_POWER, BACKLIGHTCDD_E_PARAM_DEVICE);
	}
	else
	{
		ret = BacklightCdd_DrvTable.pfRequestPower(deviceId, state);
	}

	return ret;
}
//======================================================================================================================
/** \brief CBacklightCdd_SetBrightnessValue
 **
 ** This function requests device power.
 **
 ** \param[in] DeviceName              device Id.
 ** \param[in] BrightnessPercentValue  target brightness value     

 **
 ** \return    E_OK          Request accepted.
 **            E_NOT_OK      Device busy, Request not accepted
 **
 ** */
//======================================================================================================================
FUNC(Std_ReturnType, CBacklightCdd_CODE) CBacklightCdd_SetBrightnessValue
(
	VAR(EDisplayType, AUTOMATIC)DeviceName, 
	VAR(uint16, AUTOMATIC)BrightnessPercentValue
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = E_NOT_OK;

	if(BACKLIGHTCDD_S_UNINITIALIZED == BacklightCdd_InitStatus)
	{
        /* Report an error */
        BacklightCdd_ReportError(BACKLIGHTCDD_API_SET_BRIGHTNESS, BACKLIGHTCDD_E_UNINIT);
	}
	else if(BACKLIGHTCDD_MAX_NUM_OF_DEVICES <= DeviceName)
	{
        /* Report an error */
        BacklightCdd_ReportError(BACKLIGHTCDD_API_SET_BRIGHTNESS, BACKLIGHTCDD_E_PARAM_DEVICE);
	}
	// else if(BACKLIGHTCDD_MAX_DUTY <= duty)
	// {
    //     /* Report an error */
    //     BacklightCdd_ReportError(BACKLIGHTCDD_API_SET_BRIGHTNESS, BACKLIGHTCDD_E_PARAM_DUTY);
	// }
	else
	{
		ret = BacklightCdd_DrvTable.pfSetBrightness(DeviceName, BrightnessPercentValue);
	}

	return ret;
}
//======================================================================================================================
/** \brief CBacklightCdd_EnterSafeState
 **
 ** This function requests enter safe status.
 **
 ** \param[in] None
 ** \    

 **
 ** \return None
 **           
 **
 ** */
//======================================================================================================================
FUNC(void, CBacklightCdd_CODE) CBacklightCdd_EnterSafeState(void)
{
	if(BACKLIGHTCDD_S_UNINITIALIZED == BacklightCdd_InitStatus)
	{
        /* Report an error */
        BacklightCdd_ReportError(BACKLIGHTCDD_API_ENTER_SAFE_STATE, BACKLIGHTCDD_E_UNINIT);
	}
	else
	{
		BacklightCdd_DrvTable.pfEnterSafeStatus();
	}
}
//======================================================================================================================
/** \brief CBacklightCdd_ExitSafeState
 **
 ** This function requests exit safe status.
 **
 ** \param[in] None
 ** 

 **
 ** \return None
 **           
 **
 ** */
//======================================================================================================================
FUNC(void, CBacklightCdd_CODE) CBacklightCdd_ExitSafeState(void)
{
	if(BACKLIGHTCDD_S_UNINITIALIZED == BacklightCdd_InitStatus)
	{
        /* Report an error */
        BacklightCdd_ReportError(BACKLIGHTCDD_API_EXIT_SAFE_STATE, BACKLIGHTCDD_E_UNINIT);
	}
	else
	{
		BacklightCdd_DrvTable.pfExitSafeStatus();
	}
}
//======================================================================================================================
/** \brief BacklightCdd_MainFunction
 **
 ** Periodic function to service device power requests.
 **
 ** \param[in] None        
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, CBacklightCdd_CODE) BacklightCdd_MainFunction(void)
{
	if (BACKLIGHTCDD_S_UNINITIALIZED == BacklightCdd_InitStatus)
    {
        /* Report an error */
        BacklightCdd_ReportError(BACKLIGHTCDD_API_DEINIT, BACKLIGHTCDD_E_UNINIT);
    }
    else
    {
        BacklightCdd_DrvTable.pfMainFunction();
    }
}

//======================================================================================================================
/** \brief CBacklightCdd_GetStatus
 **
 ** This function returns device current status.
 **
 ** \param[in] device        device Id.
 ** \param[in\out] DeviceStatus  Current status of device      
 **
 ** \return    E_OK          Request accepted.
 **            E_NOT_OK      Device busy, Request not accepted
 **
 ** */
//======================================================================================================================
FUNC(Std_ReturnType, CBacklightCdd_CODE) CBacklightCdd_GetStatus
(
	VAR(EDisplayType, AUTOMATIC) DeviceName, 
	P2VAR(EDeviceStatus, AUTOMATIC, AUTOMATIC) DeviceStatus
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = E_NOT_OK;
	
	if(BACKLIGHTCDD_MAX_NUM_OF_DEVICES <= DeviceName)
	{
		/* Report an error */
        BacklightCdd_ReportError(BACKLIGHTCDD_API_GET_STATUS, BACKLIGHTCDD_E_PARAM_DEVICE);

	}
	else
	{
		*DeviceStatus = BacklightCdd_DrvTable.pfGetStatus(DeviceName);
		ret = E_OK;
	}
	

	return ret;	
}

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
