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
#include "Rte_CCtrl_Telltale.h"
#include "CmpLib.h"
#include "Ctrl_TT_Cfg.h"
#include "Ctrl_Telltale.h"
#include "Ctrl_Telltale_blinkctrl.h"
#include "Ctrl_Telltale_Cfg.h"
#include "Ctrl_Telltale_TypeCfg.h"

#ifndef CTRL_TT_READIGN_STATUS
#error "Ctrl_TT_Cfg.h: CTRL_TT_READIGN_STATUS function macro definition is missing. Configure the respective Rte interface in Excel utility "
#endif

#ifndef CTRLTT_VOLTAGE_LVI_HVI
#error "Ctrl_TT_Cfg.h: CTRLTT_VOLTAGE_LVI_HVI function macro definition is missing. Configure the respective Rte interface in Excel utility "
#endif

#ifndef CTRLTT_OUTPUT_Interface
#error "Ctrl_TT_Cfg.h: CTRLTT_OUTPUT_Interface function macro definition is missing. Configure the respective Rte interface in Excel utility "
#endif

#ifndef POST_TTSTATUS_ARRAY_THRU_RTE
#error "Ctrl_TT_Cfg.h: POST_TTSTATUS_ARRAY_THRU_RTE function macro definition is missing. Configure the respective Rte interface in Excel utility "
#endif

//@brief  Instance of life-cycle state-machine
CMPLIB_INSTANCE(Ctrl_Telltale)


//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

static uint8 CtrlTtIgnSts = IgnOff;
static uint8 battery_status = TT_TURN_OFF;

//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional initialization state
///
/// @return E_OK:           Succeed
///< br>     E_NOT_READY:    In progress. Keeps the component in this state.
///< br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpInit(void)
{
    uint8 index;
    Std_ReturnType result = E_OK;
    for (index = 0; index < TT_TOTAL_NUM_OF_TELLTALES; index++)
    {
        CtrlTtSts[index] = TT_TURN_OFF;
        TTInfoTable[index].TTOnOffCntr = 0;
        TTInfoTable[index].TTMinFlashCntr = 0;
        TTInfoTable[index].TTMaxFlashCntr = 0;
        TTInfoTable[index].TTInputStatus = cTT_PHASE_OFF;
        TTInfoTable[index].PrevTTInputStatus = cTT_PHASE_OFF;
        TTInfoTable[index].TTPhase = cTT_PHASE_OFF;
        TTInfoTable[index].PatternSize = cTT_PHASE_PATTERN_SIZE;
        TTInfoTable[index].OnePatternFinished = FALSE;
    }

  return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional de-initialization state
///
/// @return E_OK:           Succeed
///< br>     E_NOT_READY:    In progress. Keeps the component in this state.
///< br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDeInit(void)
{
    Std_ReturnType result = E_OK;
    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional activation state
///
/// @return E_OK:           Succeed
///< br>     E_NOT_READY:    In progress. Keeps the component in this state.
///< br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpActivation(void)
{
    Std_ReturnType result = E_OK;
    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional de-activation state
///
/// @return E_OK:           Succeed
///< br>     E_NOT_READY:    In progress
///< br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDeActivation(void)
{
    Std_ReturnType result = E_OK;
    return result;
}

/*============================================================================
** Function Name:      static uint8 CtrlTtGetStateByte(uint8 IgnSts, uint8 tt_state_byte)
** Description:        This function will return the battery status
** Input Parameters:   IgnSts, tt_state_byte
** Outputs:            STATE_BYTE
**==========================================================================*/
static uint8 CtrlTtGetStateByte(uint8 IgnSts, uint8 tt_state_byte)
{
    /*locally assigning tt_state_byte into a Local Variable */
      uint8 STATE_BYTE =  tt_state_byte;

      if (IgnSts == TT_TURN_ON)
      {
          STATE_BYTE |= cTT_RUN;
      }
      else if (IgnSts == TT_TURN_OFF)
      {
          STATE_BYTE |= cTT_OFF;
      }
     else if (IgnSts == cIGN_ACC)
      {
          STATE_BYTE |= cTT_ACC;
      }
      else if (IgnSts == cIGN_CRANK)
      {
          STATE_BYTE |= cTT_CRANK;
      }
      else
      {
          /*
          ** No code is required in this 'else' statement.  It has been added for defensive
          ** programming purposes.
          */
      }
  
      return STATE_BYTE;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  State for normal operations
///
/// @return The return value is disregarded. Say E_OK
//---------------------------------------------------------------------------------------------------------------------

static Std_ReturnType CmpActive(void)
{
    Std_ReturnType result = E_OK;
    uint8 HMI_Ready_Status=eHMI_NOT_READY;
    /*Read HMI ready status */
    Rte_Read_rpHmiReadyState_HMI_ReadyStatus(&HMI_Ready_Status);

    if(eHMI_READY==HMI_Ready_Status)
    {
        InputProcess();
        Process_Ctrl_Telltale();
    }else
    {
        /*Wait for the HMI ready */
    }
    
    return result;
}

/*============================================================================
** Function Name:      static void InputProcess(void)
** Description:        function will return the tt active status to enter the cluster into sleep
** Input Parameters:   Telltale Status (TT_TURN_ON, TT_TURN_OFF and
**                     Falshing macros defined in the header file )
** Outputs:            CtrlTtIgnSts,battery_status
**==========================================================================*/
static void InputProcess(void)
{
    (void)CTRL_TT_READIGN_STATUS(&CtrlTtIgnSts);
     battery_status = CTRLTT_VOLTAGE_LVI_HVI();
}

/*============================================================================
** Function Name:      void Ctrl_TelltaleProcess(void)
** Description:        This Function updates the Telltale output array to View Telltale
** Input Parameters:   void   
** Outputs:            CtrlTTStatus_Array
**==========================================================================*/
static void Process_Ctrl_Telltale(void)
{
    uint8 index = TT_TURN_OFF;
    uint8 l_turn_on_off = TT_TURN_OFF;
    uint8 tt_state_byte = cTT_OFF;
    boolean fl_EtmEnabled_bool = FALSE;

    CTRL_TT_INITPROVEOUT(CtrlTtIgnSts);

    tt_state_byte = CTRL_TT_GET_STATEBYTE(CtrlTtIgnSts, tt_state_byte);
    //GET_ETM_STATUS(&fl_EtmEnabled_bool);

    for (index = 0; index < TT_TOTAL_NUM_OF_TELLTALES; index++)
    {
        if (((tt_ctrl_ttconfig[index].Operational_states) & tt_state_byte) != 0x00u)
        {
          if( FALSE == fl_EtmEnabled_bool)
          {

            /*Assigning the telltale status from the array from models*/
            l_turn_on_off = CtrlTtSts[index];

            /*TT is not configured ,we should OFF the telltale for proveout*/
            if (cTT_CONFIGURED_OFF == CtrlTtSts[index])
            {
              l_turn_on_off = TT_TURN_OFF;
            }
            else
            {
                /*Update the telltale status based on battery and proveout conditions and configurations
                  before passing it to View_Telltale*/
                if (battery_status != eBatteryState_Normal)
                {
                 l_turn_on_off = CTRL_TT_CHECK_BATTERY_STATUS(index, l_turn_on_off, battery_status);
                } 
                else
                {
                 l_turn_on_off = CTRL_TT_CHECK_PROVEOUT(index, l_turn_on_off, tt_state_byte);
                }
             }
           }else
           {
                l_turn_on_off = TT_TURN_OFF;
           }
        }
        else
        {
            l_turn_on_off = TT_TURN_OFF;
        }

        (void)CTRLTT_OUTPUT_Interface(index, l_turn_on_off);

    }

    /* All Telltale blink operations will be handled here */
    BlinkCtrl_Update_Output();
  
    POST_TTSTATUS_ARRAY_THRU_RTE(&(CtrlTTStatus_Array[0]));
 
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Diagnostic state
///
/// @return E_OK:           Diagnostic has completed. Go to DiagReturn state.
///< br>     E_NOT_READY:    Keeps the component in this state.
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiag(void)
{
    Std_ReturnType result = E_OK;
    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional state to clean up after diagnostic state. Component behaviour to be restored.
///
/// @return E_OK:           Diagnostic clean-up has completed. Return to the previous state (Active or Inactive).
///< br>     E_NOT_READY:    Keeps the component in this state.
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiagReturn(void)
{
    Std_ReturnType result = E_OK;
    return result;
}

/*============================================================================
 ** Function Name       : void CTtCtrl_SetTelltaleStatus(uint8 index, uint8 tt_status)
 ** Description         : This function is used to update the
 **                        TT status in the array all the telltales from Models.
 ** Input Parameters:   : index, tt_status
 ** Outputs             :
 **==========================================================================*/
void CtrlTt_CtrlTtUpdateStatus(uint8 index, uint8 tt_status)
{
     if (index < TT_TOTAL_NUM_OF_TELLTALES)
     {
         CtrlTtSts[index] = tt_status;
     }
}

/*============================================================================
 ** Function Name       : CtrlTt_CtrlTtGetStatus(uint8 index, uint8 *tt_status)
 ** Description         : This function is used to check the current telltale status based on
 **                        index
 ** Input Parameters:   : index, l_turn_on_off:
 **==========================================================================*/
void CtrlTt_CtrlTtGetStatus(uint8 index, uint8 *tt_status)
{
     if (index < TT_TOTAL_NUM_OF_TELLTALES)
     {
         *tt_status = CtrlTtSts[index];
     }
}

/*============================================================================
 ** Function Name       : CtrlTtStatus_Output_Array(uint8 index, uint8 l_turn_on_off )
 ** Description         : This function will update the output telltale status in the 
 **                        array CtrlTTStatus_Array
 ** Input Parameters:   : index, l_turn_on_off
 ** Outputs             : CtrlTTStatus_Array
 **==========================================================================*/
void CtrlTtStatus_Output_Array(uint8 index, uint8 TT_Phase)
{
    CtrlTTStatus_Array[index] = TT_Phase;
}



/*============================================================================
 **============================================================================*/
/***  P V C S    R E V I S I O N    N O T E S**/
/**----------------------------------------------------------------------------
 **  For each change to this file, be sure to record:
 **  1.  who made the change and when the change was made
 **  2.  why the change was made and the intended result
 **
 **  Date          By          Reason for Change
 **  09/13/2024    ckulothu    Ctrl_Telltale Bookshelf Updates
 **----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
Date              : 30-04-2024
CDSID             : abetager
Traceability      : HONDA28384-13930: MainScreen-TFT Telltales manager from Bookshelf
Change Description: Ctrl_Telltale file updated for Telltale manager.
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
Date              : 16-07-2024
CDSID             : ckulothu
Traceability      : Ctrl_telltale Bookshelf
Change Description: Ctrl_Telltale file updated for Telltale manager.
-----------------------------------------------------------------------------*/

/* end of file */
