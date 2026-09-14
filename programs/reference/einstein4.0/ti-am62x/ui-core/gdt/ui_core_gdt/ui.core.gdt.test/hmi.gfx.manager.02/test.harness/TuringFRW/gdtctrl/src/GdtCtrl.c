//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2015] Visteon Corporation
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

#include <Rte_GdtCtrl.h>
#include "Rte_GdtCtrl_Type.h"
#include <CmpLib.h>
#include <Os.h>
#include <TmExt_Cfg.h>
#include "WrnCtrl_Cfg.h"
#include "hmi_logic_state_handler.h"
#include "hmi_view_manager_02_autocode.h"
#include "hmi_language_interface.h"
#include "hmi_gfx_mgr02_if.h"
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_rte_interface.h"

/// @brief  Instance of life-cycle state-machine
CMPLIB_INSTANCE(GdtCtrl)

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
#define WRN_CYCLE_TIME_MS	4000
#define WRN_INVALID_ID		((TWrnId)eWrnId_Count)

#define WRN_LIST_NEW_CHANGED	1
#define WRN_LIST_OLD_CHANGED	2
// needed for calculating in miles
#define FRACTION 10

//Masks describing the status bits of the warnings from WrnCtrl
//New correspond to warnings with active bit 1 and reset and old bits to 0
#define eWrnListMask_New       ((TWrnListMask)0x71u)
//Old corresponds to warnings with active and old bits to 1 and reset bit to 0
#define eWrnListMask_Old       ((TWrnListMask)0x73u)
//Reset corresponds to warnings with active and reset bits to 1 regardless of value of old bit
#define eWrnListMask_Reset     ((TWrnListMask)0x55u)
//All active are all warnings with active bit to on regardless of value of reset and old bits
#define eWrnListMask_AllActive ((TWrnListMask)0x11u)

//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================
static TWrnId currDispWrnID;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional initialization state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpInit( void )
{
    // Place invocation to "hmi_gdt_ctrl_app_init()" and "hmi_lsh_initialize(0)" here !!
    hmi_language_initialize();
    
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional de-initialization state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDeInit( void )
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
static Std_ReturnType CmpActivation( void )
{
    currDispWrnID = WRN_INVALID_ID;
    HmiSetEtmScreen(eHmiEtmScreenMax);
    HmiSetDiagPattern(eHmiDiagPatternMax);

    hmi_lsh_initialize((UINT8)0);

    hmi_lsh_post_button_event((UINT8)WELCOME_EV, (UINT8)BTN_EV_PRESS);
    // Place invocation to "hmi_lsh_post_button_event(HMI_ADD_WELCOME_EV)" here !!
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
    currDispWrnID = WRN_INVALID_ID;

    hmi_lsh_post_button_event((UINT8)WELCOME_EV, (UINT8)BTN_EV_RELEASE);
    // Place invocation to "hmi_lsh_post_button_event(HMI_GOODBYE_EV)" here !!
    return  E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  State for normal operations
///
/// @return The return value is disregarded. Say E_OK
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpActive( void )
{
    // This function is invoked on 8 ms when the Component (GdtCtrl) is in state "Active" ! (It is periodic "Task" function !)
    // Do periodic tasks/processing here !
	// In the SWA this is named as HmiViewManagerTask

    //Example how to activate the render task, which is in GdtCdd
    //It is not active until it receives event from GdtCtrl
    //GdtCtrl waits for corresponding event from the render task

    EBtnState State;
    uint32 Miles = (UINT32)1000;
    sTrcOut TripOut;
    static EBtnState oldStates[6];
    // Button pressed as follow:
    // 0 - eEBtnState_NotPressed
    // 1 - eEBtnState_Pressed    - Normal
    // 2 - eEBtnState_ShortPress - Short press
    // 3 - eEBtnState_LongPress1 - Long press

    
    // up
    (void)Rte_Read_rpSR_pBtnState_B3_TIBtnMdl_State_State(&State);
    if (State == 1 && oldStates[0] != State)
    {
        oldStates[0] = State;
        hmi_lsh_post_button_event((UINT8)UP_BTN_EV, (UINT8)BTN_EV_PRESS);
    }
    else if (State == 0)
    {
        oldStates[0] = State;
    }
    
    // right
    (void)Rte_Read_rpSR_pBtnState_B4_TIBtnMdl_State_State(&State);
    if (State == 1 && oldStates[1] != State)
    {
        oldStates[1] = State;
        hmi_lsh_post_button_event((UINT8)RIGHT_BTN_EV, (UINT8)BTN_EV_PRESS);
    }
    else if (State == 0)
    {
        oldStates[1] = State;
    }
    
    // down
    (void)Rte_Read_rpSR_pBtnState_B5_TIBtnMdl_State_State(&State);
    if (State == 1 && oldStates[2] != State)
    {
        oldStates[2] = State;
        hmi_lsh_post_button_event((UINT8)DOWN_BTN_EV, (UINT8)BTN_EV_PRESS);
    }
    else if (State == 0)
    {
        oldStates[2] = State;
    }
    
    // left
    (void)Rte_Read_rpSR_pBtnState_B6_TIBtnMdl_State_State(&State);
    if (State == 1 && oldStates[3] != State)
    {
        oldStates[3] = State;
        hmi_lsh_post_button_event((UINT8)LEFT_BTN_EV, (UINT8)BTN_EV_PRESS);
    }
    else if (State == 0)
    {
        oldStates[3] = State;
    }
    
    // ok
    (void)Rte_Read_rpSR_pBtnState_B7_TIBtnMdl_State_State(&State);
    if (State == 1 && oldStates[4] != State)
    {
        oldStates[4] = State;
        hmi_lsh_post_button_event((UINT8)BTN_ID_ENTER, (UINT8)BTN_EV_PRESS);
        
        // reset trip distance
        Rte_Call_itCS_TripMdl_ResetTrip();
    }
    else if (State == 0)
    {
        oldStates[4] = State;
    }

    (void)Rte_Read_tiSR_OdoOutMiles_Miles(&Miles);
    set_odo(Miles/(UINT32)FRACTION);

    (void)Rte_Read_GdtCtrl_tiSR_TrcOut_deTrcOut(&TripOut);
    set_trip_time(TripOut.TripTime);
    set_trip_distance(TripOut.TripDistance/(UINT32)FRACTION);
    set_trip_dte(TripOut.TripDTE/(UINT32)FRACTION);
    set_trip_afe(TripOut.TripAFE);
    set_fuel_info_dte(TripOut.DTE/(UINT32)FRACTION);
    set_fuel_info_afe(TripOut.AFE);

    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Diagnostic state
///
/// @return E_OK:           Diagnostic has completed. Go to DiagReturn state.
///<br>     E_NOT_READY:    Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiag( void )
{
    return E_NOT_OK;    // No Diagnostics Support, Currently !!
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional state to clean up after diagnostic state. Component behaviour to be restored.
///
/// @return E_OK:           Diagnostic clean-up has completed. Return to the previous state (Active or Inactive).
///<br>     E_NOT_READY:    Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiagReturn( void )
{
    return E_OK;
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief Iterates the warning states and gets the first warning ID that correspond to the required mask
///
/// @param ListMask   -   Mask containing the search criteria.
///                       It is not exclusive, e.g. searching for active warnings will return all active warnings, regardless what other state there are in.
/// @param   pID        -   Return parameter containing the ID of the required warning.
///
/// @return E_OK:         Warning found.
///<br>     E_NOT_OK:     Warning is not found.
//---------------------------------------------------------------------------------------------------------------------
static void GetFirstWarning(TWrnListMask ListMask, TWrnId* pId, sint32* pCounter)
{
	Std_ReturnType result = Rte_Call_rpCS_rList_TIWrnCtrl_Lists_GetFirst(ListMask, pId);

	if (result != E_OK)
	{
		*pId = WRN_INVALID_ID;
	}
    (*pCounter)++;

}
//---------------------------------------------------------------------------------------------------------------------
/// @brief Iterates the warning states and gets next warning ID that correspond to the required mask, realtive to the supplied warning ID.
///         Call should be preceded by call to GetFirst.
///
/// @param ListMask   -   Mask containing the search criteria.
///                       It is not exclusive, e.g. searching for active warnings will return all active warnings, regardless what other state there are in.
/// @param    pID     -   Return parameter containing the ID of the required warning.
/// @return E_OK:         Warning found.
///<br>     E_NOT_OK:     Warning is not found.
//---------------------------------------------------------------------------------------------------------------------
static void GetNextWarning(TWrnListMask ListMask, TWrnId* pId)
{
	Std_ReturnType result =  Rte_Call_rpCS_rList_TIWrnCtrl_Lists_GetNext(ListMask, pId);

	if (result != E_OK)
	{
		*pId = WRN_INVALID_ID;
	}
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief Iterates the warning states and gets next warning ID that correspond to the required mask, realtive to the supplied warning ID.
///         Call should be preceded by call to GetFirst.
///
/// @param ListMask   -   Mask containing the search criteria.
///                       It is not exclusive, e.g. searching for active warnings will return all active warnings, regardless what other state there are in.
/// @param    pID     -   Return parameter containing the ID of the required warning.
/// @return E_OK:         Warning found.
///<br>     E_NOT_OK:     Warning is not found.
//---------------------------------------------------------------------------------------------------------------------
static void ReleaseWarningIterator(sint32 counter)
{
	while (counter > 0)
	{
		Rte_Call_rpCS_rList_TIWrnCtrl_Lists_Release();

		counter--;
	}
}
//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Initiate a request to prepare for issue of a Warning with given Id.
///
/// @param  Id:  Id (Handle) of the Warning that is concerned
///
/// @return Std_ReturnType:   E_OK  - Succeed, The requested Warning is ready to be issued (shown, played).
///<br>     E_NOT_READY:    The requested Warning is NOT ready to be issued.
///<br>     E_NOT_OK:       The request has Failed !
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType GdtCtrl_Prepare(EWrnReason Reason, TWrnId Id)
{
    Std_ReturnType Rslt = E_NOT_OK;

    if (eWrnId_Count > Id)
    {
        Rslt = E_OK;
    }

    return Rslt;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Cancel previous request for a Warning with given Id.
///
/// @param  Id:  Id (Handle) of the Warning that is concerned
///
/// @return None:  Function is of type void.
//---------------------------------------------------------------------------------------------------------------------
void GdtCtrl_Cancel(EWrnReason Reason, TWrnId Id)
{
	currDispWrnID = WRN_INVALID_ID;
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Start (issue) previously prepared Warning with given Id.
///
/// @param  Id:  Id (Handle) of the Warning that is concerned
///
/// @return None:  Function is of type void.
//---------------------------------------------------------------------------------------------------------------------
void GdtCtrl_Latch(EWrnReason Reason, TWrnId Id)
{
    if (eWrnId_Count > Id)
    {
    	currDispWrnID = Id;
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Start (issue) previously prepared Warning with given Id.
///
/// @param  Id:  Id (Handle) of the Warning that is concerned
///
/// @return None:  Function is of type void.
//---------------------------------------------------------------------------------------------------------------------
void GdtCtrl_ListChange(TWrnListMask ListMask)
{
    //if warning acknowledged
    if( ( ListMask & 0x04) == 0x04 )
    {
        TWrnId warningID;
        sint32 iterCounter = 0;

        GetFirstWarning(eWrnListMask_New, &warningID, &iterCounter);
        ReleaseWarningIterator(iterCounter);

        currDispWrnID = warningID;    
    }
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Notification function when "SpeedData" DataPool element is written.
///
/// @param  None:  Function has no parameters.
///
/// @return None:  Function is of type void.
//---------------------------------------------------------------------------------------------------------------------
uint32 GdtCtrl_GetCurrentWarning(void)
{
	return (UINT32)currDispWrnID;
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Notification function when "SpeedData" DataPool element is written.
///
/// @param  None:  Function has no parameters.
///
/// @return None:  Function is of type void.
//---------------------------------------------------------------------------------------------------------------------
void GdtCtrl_GetListOfActiveWarnings(uint32* pArr, uint32* pArrSize)
{
	uint32 inArrSize = *pArrSize;

	(*pArrSize) = 0x00000000U;

	if (inArrSize >= eWrnId_Count)
	{
		TWrnId warningID;
		sint32 iterCounter = 0;

		GetFirstWarning(eWrnListMask_AllActive, &warningID, &iterCounter);

		while (warningID != WRN_INVALID_ID)
		{
			pArr[(*pArrSize)] = warningID;
			(*pArrSize)++;

			GetNextWarning(eWrnListMask_AllActive, &warningID);
		}

		ReleaseWarningIterator(iterCounter);
	}
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Notification function when "SpeedData" DataPool element is written.
///
/// @param  None:  Function has no parameters.
///
/// @return None:  Function is of type void.
//---------------------------------------------------------------------------------------------------------------------
void GdtCtrl_GetListOfStorredWarnings(uint32* pArr, uint32* pArrSize)
{
	uint32 inArrSize = *pArrSize;

	(*pArrSize) = 0x00000000U;

	if (inArrSize >= eWrnId_Count)
	{
		sint32 index;
		TWrnId warningID;
		sint32 numOldWarn;
		sint32 iterCounter = 0;
		TWrnListMask maskWrn = 0x22U; // old warnings only

		GetFirstWarning(maskWrn, &warningID, &iterCounter);

		while (warningID != WRN_INVALID_ID)
		{
			pArr[(*pArrSize)] = warningID;
			(*pArrSize)++;

			GetNextWarning(maskWrn, &warningID);
		}

		numOldWarn = (sint32)(*pArrSize);
		maskWrn = 0x44U; // reset warnings only

		GetFirstWarning(maskWrn, &warningID, &iterCounter);

		while (warningID != WRN_INVALID_ID)
		{
			for (index = 0; index < numOldWarn; index++)
			{
				if (pArr[index] == warningID)
				{
					break; // warning already in the list
				}
			}

			if (index >= numOldWarn)
			{
				pArr[(*pArrSize)] = warningID;
				(*pArrSize)++;
			}

			GetNextWarning(maskWrn, &warningID);
		}

		ReleaseWarningIterator(iterCounter);
	}
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @param  None:  Function has no parameters.
///
/// @return None:  Function is of type void.
//---------------------------------------------------------------------------------------------------------------------
void GdtCtrl_AcknowledgeWarning(uint32 warningID)
{
	Rte_Call_rpCS_rAck_TIWrnCtrl_Ack_Acknowledge((UINT16)warningID);
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Notification function when "SpeedData" DataPool element is written.
///
/// @param  None:  Function has no parameters.
///
/// @return None:  Function is of type void.
//---------------------------------------------------------------------------------------------------------------------
void GdtCtrlRef_SpeedDataRx ( void )
{
    // Do Some Processing HeRe !!
    // This notification function is invoked when SpdMdl component writes filtered value for "Vehicle Speed" to RTE (DataPool).
    // Read from DataPool the (eventually) changed value of SpeedData DataPool element and pass it to Gdt entity for processing !
    // Reading from RTE is accomplished with macro "Rte_Read_rpSR_rSpd_TISpdMdl_Out_Speed( &SpdF );"

}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Notification function when "TachoData" DataPool element is written.
///
/// @param  None:  Function has no parameters.
///
/// @return None:  Function is of type void.
//---------------------------------------------------------------------------------------------------------------------
void GdtCtrlRef_TachoDataRx ( void )
{
    // Do Some Processing HeRe !!
    // This notification function is invoked when EngMdl component writes filtered value for "Engine RPM" to RTE (DataPool).
    // Read from DataPool the (eventually) changed value of TachoData DataPool element and pass it to Gdt entity for processing !
    // Reading from RTE is accomplished with macro "Rte_Read_rpSR_rEng_TIEngMdl_Out_Tacho( &TachoF );"

}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Notification function from TmExt component when Pulse channel changes its phase (Low->High and High->Low).
///
/// @param  Notification:  A pointer to structure "SPulseNotification"
///
/// @return None:  Function is of type void.
//---------------------------------------------------------------------------------------------------------------------
void CGdtCtrl_Impl_Notification ( const SPulseNotification *Notification )
{
    // The GdtCtrl component may receive notifications for several pulse channels through this function.
    // Turn indicators blinking is implemented with "ePulseChannel1Hz" channel !
    if (( NULL_PTR != Notification ) && ( Notification->Channel == ePulseChannelChnl1Hz ))
    {
        // This notification function is invoked when Pulse channel of TmExt changes its phase - query "Notification->Phase" member for current phase.
        // It should be used to implement turn indicators blinking.
        // Do Some Processing HeRe !!
    }

}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Called from HmiCtrl so GUI to be prepared for "Welcome".
///
/// @param  Id:  Id of HMI sub
///
/// @return E_OK:  GUI is ready for "Welcome"
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType CGdtCtrl_Impl_PrepareSub ( EHmiSubId Id )
{
    // TODO prepare for "Welcome"

    // when ready notify HmiCtrl
	Std_ReturnType retval = E_OK;
    return retval;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Start GUI. Called from HmiCtrl.
///
/// @param  Id:  Id of HMI sub
//---------------------------------------------------------------------------------------------------------------------
void CGdtCtrl_Impl_Start ( EHmiSubId Id )
{
	switch (Id)
	{
		case eHmiSubId_Welcome:

			break;

		case eHmiSubId_ETM100:

		    HmiSetEtmScreen(eHmiEtmScreen100);
			break;

		case eHmiSubId_ETM110:

		    HmiSetEtmScreen(eHmiEtmScreen110);
			break;

		case eHmiSubId_ETM120:

		    HmiSetEtmScreen(eHmiEtmScreen120);
			break;

		case eHmiSubId_ETM130:

		    HmiSetEtmScreen(eHmiEtmScreen130);
			break;

		case eHmiSubId_ETM230:

		    HmiSetEtmScreen(eHmiEtmScreen230);
			break;

		case eHmiSubId_ETM233:

		    HmiSetEtmScreen(eHmiEtmScreen233);
			break;

		default:;
	}
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Notifies GdtCtrl about change in warning list
///
/// @param  ListMask: Indicates what types of warnings have changed
//---------------------------------------------------------------------------------------------------------------------
void GdtCtrl_Stop ( EHmiSubId Id )
{
	switch (Id)
	{
		case eHmiSubId_Welcome:

			break;

		case eHmiSubId_ETM100:
		case eHmiSubId_ETM110:
		case eHmiSubId_ETM120:
		case eHmiSubId_ETM130:
		case eHmiSubId_ETM230:
		case eHmiSubId_ETM233:

		    HmiSetEtmScreen(eHmiEtmScreenMax);
			break;

		default:;
	}
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  GdtCtrl Diagnostic Port Runable 
///
/// @param  ListMask: Handle Diagnostic Service Requests processed by the component GdtCtrl
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType GdtCtrl_DiagAction(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) Lenght, uint32 Id)
{
    Std_ReturnType Res = E_NOT_OK;

    if (eDcmExt_IOCtrl == Action)
    {
        // TODO: Process the Diagnostoic requests. Valid values for parameter Id are 0xFE0A and 0xFE0B
        switch (Id)
        {
        case 0xFE0A:

            if (Data[0] == 3)
            {
                if ((tHmiDiagPattern)Data[1] < eHmiDiagPattern5)
                {
                    HmiSetDiagPattern((tHmiDiagPattern)Data[1]);

                    Res = CmpLib_Command(&oCmp, eCmpCmd_DiagStart);
                }
            }
            else if (Data[0] == 0)
            {
                HmiSetDiagPattern(eHmiDiagPatternMax);

                Res = CmpLib_Command(&oCmp, eCmpCmd_DiagStop);
            }
            else
            {

            }
            break;

        case 0xFE0B:

            if (Data[0] == 3)
            {
                UINT32 color;

                color = (UINT32)255;    // A
                color <<= 8;
                color |= Data[1];// R
                color <<= 8;
                color |= Data[2];// G
                color <<= 8;
                color |= Data[3];// B

                HmiSetDiagColor(color);
                HmiSetDiagPattern(eHmiDiagPattern5);

                Res = CmpLib_Command(&oCmp, eCmpCmd_DiagStart);
            }
            else if (Data[0] == 0)
            {
                HmiSetDiagPattern(eHmiDiagPatternMax);

                Res = CmpLib_Command(&oCmp, eCmpCmd_DiagStop);
            }
            else
            {
            }
            break;

        default:;
        }
    }
    return Res;
}

