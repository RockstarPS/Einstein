//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2020] Visteon Corporation
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
#ifndef _SLEEPMANAGER_C
#define _SLEEPMANAGER_C

#include "SleepManager.h"
#include "EcuAppM_Cfg.h"
#include "CmpLib.h"
#include "ComM.h"
//#include "ComMExt.h"


/// @brief  Instance of life-cycle state-machine
CMPLIB_INSTANCE(SleepManager)

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================


static uint8 Sleep_Status = ECUAPPM_REFUSE_TO_SLEEP;
/* static uint8 Application_SleepStatus; */
/* static uint16 SleepManager_WakeupReason; */
/* static uint8 RTC_Calibration_Status; */   // this flag is used to differentiate between normal wakeup and partial wakeup for NVM read.

//extern FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_RequestCommunication(UInt8 Channel);
//extern FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_ReleaseCommunication(UInt8 Channel);


//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================

//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional initialization state
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpInit(void)
{

	return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional de-initialization state
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDeInit(void)
{
	return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional activation state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpActivation(void)
{
	return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional de-activation state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDeActivation( void )
{
	return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  State for normal operations
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpActive(void)
{
	SleepManager_Judgement();
	return E_OK;	
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Diagnostic state
///
/// @return E_OK:           Diagnostic has completed. Go to DiagReturn state.
///<br>     E_NOT_READY:    Keeps the component in this state.
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiag( void )
{
    return E_NOT_OK; /// No diag support for now
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional state to clean up after diagnostic state. Component behaviour to be restored.
///
/// @return E_OK:           Diagnostic clean-up has completed. Return to the previous state (Active or Inactive).
///<br>     E_NOT_READY:    Keeps the component in this state.
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiagReturn( void )
{
    return E_NOT_OK;/// No diag support for now
}
/****************************************************************************
** Function Name     : void SleepManager_Judgement(void)
**
** Description       : 

**
** Invocation        : SleepManager.c
**
** Parameters        :
**
** Return Value      : None
**
** Critical Section  : none
******************************************************************************/
void SleepManager_Judgement(void)
{
	volatile uint8 fl_Ign_IoHab_Status_S32 = E_NOT_OK;
	
	if(fl_Ign_IoHab_Status_S32 == E_NOT_OK)
	{
		Sleep_Status = ECUAPPM_REFUSE_TO_SLEEP;
	}
	else
	{
		Sleep_Status = ECUAPPM_READY_TO_SLEEP;
	}
}

/****************************************************************************
** Function Name     : void SleepManager_RTCCalibrationStatus(uint8 status)
**
** Description       : 

**
** Invocation        :
**
** Parameters        :
**
** Return Value      : None
**
** Critical Section  : none
******************************************************************************/
/* void SleepManager_RTCCalibrationStatus(uint8 status)
{
	RTC_Calibration_Status = status;
} */

/****************************************************************************
** Function Name     : uint8 SleepManager_JudgementStatus(void)
**
** Description       : 

**
** Invocation        :
**
** Parameters        :
**
** Return Value      : uint8
**
** Critical Section  : none
******************************************************************************/
 uint8 SleepManager_JudgementStatus(void)
{
	return Sleep_Status;
}
/****************************************************************************
** Function Name     : uint16 SleepManager_GetWakeupReason(void)
**
** Description       : 

**
** Invocation        :
**
** Parameters        :
**
** Return Value      : uint8
**
** Critical Section  : none
******************************************************************************/
/* void SleepManager_GetWakeupReason(uint16 WakeupSource)
{
	SleepManager_WakeupReason = WakeupSource;
} */

#endif/* End Of the File */
