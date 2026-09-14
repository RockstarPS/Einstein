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

#include "Ctrl_Telltale_blinkctrl.h"
#include "Ctrl_Telltale.h"


//---------------------------------------------------------------------------------------------------------------------
/// @brief  BlinkCtrl_TtViewUpdateStatus
///
/// @return None
//---------------------------------------------------------------------------------------------------------------------
void BlinkCtrl_TtViewUpdateStatus(uint8 index, uint8 tt_status)
{
    if (index < cTOTAL_TT_CONFIGURED)
    {
        TTInfoTable[index].TTInputStatus = tt_status;
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  BlinkCtrl_Flash_Min_Max_Cntr_Process
///
/// @return None
//---------------------------------------------------------------------------------------------------------------------
static void BlinkCtrl_Flash_Min_Max_Cntr_Process(uint8 Tt_index)
{
    if (Tt_index < cTOTAL_TT_CONFIGURED)
    {
        if (FALSE != TTInfoTable[Tt_index].OnePatternFinished)

        {
            /* Check and decrement TT Minimum and Maximum Flash counters */
            if (0x00u != TTInfoTable[Tt_index].TTMinFlashCntr)
            {
                TTInfoTable[Tt_index].TTMinFlashCntr--;
            }

            if ((0x00u != TTInfoTable[Tt_index].TTMaxFlashCntr) &&
                (cTT_MAX_FLASH_NA != TTInfoTable[Tt_index].TTMaxFlashCntr))
            {
                TTInfoTable[Tt_index].TTMaxFlashCntr--;

                if (0x00u == TTInfoTable[Tt_index].TTMaxFlashCntr)
                {
                    /*
                      TT has finished flashing for maximum flash times configured.
                      Forcibly switch the state from 'FLASH' -> 'OFF' and clear the counters.
                     */

                    TTInfoTable[Tt_index].TTPhase = TT_TURN_OFF;
                }
            }
        }
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  BlinkCtrl_Asynchronous_Flash_Process
///
/// @return None
//---------------------------------------------------------------------------------------------------------------------
static void BlinkCtrl_Asynchronous_Flash_Process(uint8 Tt_index)
{
    uint8 CurrentPhase;
    /* Check whether the TT index is with in the range */
    if (Tt_index < cTOTAL_TT_CONFIGURED)
    {
        uint8 prev_requestedFreq_index = TTInfoTable[Tt_index].PrevTTInputStatus;

        if (0x00u != TTInfoTable[Tt_index].TTMaxFlashCntr)
        {
            /* Validate Counter to process Flash */
            if (0x00u != TTInfoTable[Tt_index].TTOnOffCntr)
            {
                /* Decrement counter */
                TTInfoTable[Tt_index].TTOnOffCntr--;
                /* Maintain TT Phase */
                CurrentPhase = TTInfoTable[Tt_index].TTPhase;
            }
            if(0x00u == TTInfoTable[Tt_index].TTOnOffCntr)
            {
                /* Switch TT Phase because Previous Phase is finished */
                CurrentPhase = (uint8)(cTT_CHANGE_PHASE ^ TTInfoTable[Tt_index].TTPhase);
                /*
                  Validate Pattern Size
                  Each TT will have two phases 'OFF' and 'ON' in Flash state.
                  When TT is completed both 'OFF' and 'ON' phases it is decided as 'One Pattern'
                  Pattern size is initially loaded with '2' when ever there is a fresh FLASH request.
                  One for 'OFF' phase and other for 'ON' phase.
                  Pattern size is decremented by '1' every time a phase is finished.
                  Pattern size is reloaded when one pattern is finished in order to repeat the pattern
                */

                /* Defensive check added before decrement*/
                if (0x00u != TTInfoTable[Tt_index].PatternSize)
                {
                    TTInfoTable[Tt_index].PatternSize--;
                }

                if (0x00u == TTInfoTable[Tt_index].PatternSize)
                {
                    /* Re load Pattern Size to repeat the pattern */
                    TTInfoTable[Tt_index].PatternSize = cTT_PHASE_PATTERN_SIZE;
                    TTInfoTable[Tt_index].OnePatternFinished = TRUE;
                }

                /* Re Load Flash Counter with new value based on current phase */
                if (TTInfoTable[Tt_index].PrevTTInputStatus <= cTT_MAX_SUPPORTED_STATES) /*10369641*/
                {
                    if (CurrentPhase == cTT_PHASE_OFF)
                    {
                        TTInfoTable[Tt_index].TTOnOffCntr = TTConfigTable[prev_requestedFreq_index].FlashOffPhaseCntr;
                    }
                    else
                    {
                        TTInfoTable[Tt_index].TTOnOffCntr = TTConfigTable[prev_requestedFreq_index].FlashOnPhaseCntr;
                    }
                }
                TTInfoTable[Tt_index].TTPhase = CurrentPhase;
            }
        }
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  BlinkCtrl_Different_Flash_Process
///
/// @return None
//---------------------------------------------------------------------------------------------------------------------
static void BlinkCtrl_Different_Flash_Process(uint8 Tt_index)
{

    
    if (Tt_index < cTOTAL_TT_CONFIGURED)
    {
      uint8 requestedFreq_index = TTInfoTable[Tt_index].TTInputStatus;
      uint8 prev_requestedFreq_index = TTInfoTable[Tt_index].PrevTTInputStatus;
        /* Check whether 'ON' or 'OFF' phase is finished */
        if (TTInfoTable[Tt_index].PrevTTInputStatus <= cTT_MAX_SUPPORTED_STATES) /*7451865*/
        {
            if ((TTInfoTable[Tt_index].TTOnOffCntr == TTConfigTable[prev_requestedFreq_index].FlashOnPhaseCntr) ||
                (TTInfoTable[Tt_index].TTOnOffCntr == TTConfigTable[prev_requestedFreq_index].FlashOffPhaseCntr))
            {
                /* Load the Flash Counter based on TT Phase */
                if (TTInfoTable[Tt_index].TTPhase == cTT_PHASE_OFF)
                {
                    if (TTInfoTable[Tt_index].TTInputStatus <= cTT_MAX_SUPPORTED_STATES) /*7452256*/
                    {
                        TTInfoTable[Tt_index].TTOnOffCntr = TTConfigTable[requestedFreq_index].FlashOffPhaseCntr;
                    }
                }
                else
                {
                    if (TTInfoTable[Tt_index].TTInputStatus <= cTT_MAX_SUPPORTED_STATES) /*7452256*/
                    {
                        TTInfoTable[Tt_index].TTOnOffCntr = TTConfigTable[requestedFreq_index].FlashOnPhaseCntr;
                    }
                }

                /* Re Load the patterm size to indicate fresh FLASH */
                TTInfoTable[Tt_index].PatternSize = cTT_PHASE_PATTERN_SIZE;

                /*  Re Load minimum and maximum flash durations for the new flash. */
                if (TTInfoTable[Tt_index].TTInputStatus <= cTT_MAX_SUPPORTED_STATES) /*7452256*/
                {
                    TTInfoTable[Tt_index].TTMinFlashCntr = TTConfigTable[requestedFreq_index].MinFlashCntr;
                    TTInfoTable[Tt_index].TTMaxFlashCntr = TTConfigTable[requestedFreq_index].MaxFlashCntr;

                    /* Update State */
                    TTInfoTable[Tt_index].PrevTTInputStatus = TTInfoTable[Tt_index].TTInputStatus;
                }
            }
        }
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  BlinkCtrl_Same_Flash_Process
///
/// @return None
//---------------------------------------------------------------------------------------------------------------------
static void BlinkCtrl_Same_Flash_Process(uint8 Tt_index)
{
    /* Do Nothing*/
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  BlinkCtrl_Prepare_Flash_Process
///
/// @return None
//---------------------------------------------------------------------------------------------------------------------
static void BlinkCtrl_Prepare_Flash_Process(uint8 Tt_index, uint8 Tt_target_phase)
{
   
    if (Tt_index < cTOTAL_TT_CONFIGURED)
    {
        uint8 requestedFreq_index =  TTInfoTable[Tt_index].TTInputStatus;
        TTInfoTable[Tt_index].PatternSize = cTT_PHASE_PATTERN_SIZE;
        TTInfoTable[Tt_index].TTPhase = Tt_target_phase;

        if (TTInfoTable[Tt_index].TTInputStatus <= cTT_MAX_SUPPORTED_STATES)
        {
            if(TTInfoTable[Tt_index].TTPhase == cTT_PHASE_OFF)
            {
              TTInfoTable[Tt_index].TTOnOffCntr = TTConfigTable[requestedFreq_index].FlashOffPhaseCntr; 
            }
            else 
            {
              TTInfoTable[Tt_index].TTOnOffCntr = TTConfigTable[requestedFreq_index].FlashOnPhaseCntr;
            }
           
            TTInfoTable[Tt_index].TTMinFlashCntr = TTConfigTable[requestedFreq_index].MinFlashCntr;
            TTInfoTable[Tt_index].TTMaxFlashCntr = TTConfigTable[requestedFreq_index].MaxFlashCntr;
        }
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  BlinkCtrl_Update_Output
///
/// @return The return value is disregarded. Say E_OK
//---------------------------------------------------------------------------------------------------------------------
void BlinkCtrl_Update_Output(void)
{
    uint8 index;
    uint8 TT_Phase;
    /*
      Loop until 'Number of TTs' configured and process below
        1) TT OFF -> ON
        2) TT OFF -> FLASH
        3) TT ON -> OFF
        4) TT ON -> FLASH
        5) TT FALSH -> OFF
        6) TT FLASH -> ON
        7) TT FLASH -> FLASH (Switch from one frequency to another)
    */
    for (index = 0; index < cTOTAL_TT_CONFIGURED; index++)
    {
        if (TTInfoTable[index].PrevTTInputStatus == TT_TURN_ON)
        {
            Process_PrevONState_TT(index);
        }
        else if ((TTInfoTable[index].PrevTTInputStatus != TT_TURN_OFF) &&
                 (TTInfoTable[index].PrevTTInputStatus <= cTT_MAX_SUPPORTED_STATES))
        {
            Process_PrevBlinkState_TT(index);
        }
        else
        {
            Process_PrevOFFState_TT(index);
        }
        TT_Phase = TTInfoTable[index].TTPhase;
    
        CTRLTTSTATUS_OUTPUT_ARRAY(index, TT_Phase);
    } /* End of For Loop */
   
}
   
//---------------------------------------------------------------------------------------------------------------------
/// @brief  assignTTStatus
///
/// @return None
//---------------------------------------------------------------------------------------------------------------------
static void assignTTStatus(uint8 index, uint8 status)
{
     TTInfoTable[index].TTPhase = status;
     TTInfoTable[index].PrevTTInputStatus = TTInfoTable[index].TTInputStatus;
 
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Process_PrevOFFState_TT
///
/// @return None
//---------------------------------------------------------------------------------------------------------------------
static void Process_PrevOFFState_TT(uint8 index)
{

    if (TTInfoTable[index].TTInputStatus == TT_TURN_ON)
    {
        /*
           State Transition - OFF -> ON
            When TT is in 'OFF' State, and 'ON' state is requested,
             TT shall be switched to 'ON' immediately.
        */
         assignTTStatus(index, cTT_PHASE_ON);
    }
    else if ((TTInfoTable[index].TTInputStatus > TT_TURN_ON) &&
             (TTInfoTable[index].TTInputStatus <= cTT_MAX_SUPPORTED_STATES))
    {
        /*
         State Transition - OFF -> FLASH
           When TT is in 'OFF' State, and 'FLASH' state is requested,
            switch to 'FLASH' state  and start Flash with On Phase.
        */
        BlinkCtrl_Prepare_Flash_Process(index, cTT_PHASE_ON);
        TTInfoTable[index].PrevTTInputStatus = TTInfoTable[index].TTInputStatus;
    }
    else
    {
        /*
           No State Transition .Maintain previous state.
        */
        assignTTStatus(index, cTT_PHASE_OFF);
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Process_PrevONState_TT
///
/// @return None
//---------------------------------------------------------------------------------------------------------------------
static void Process_PrevONState_TT(uint8 index)
{
    if (TTInfoTable[index].TTInputStatus == TT_TURN_OFF)
    {
        /*
           State Transition - ON -> OFF
            When TT is in 'ON' State, and 'OFF' state is requested,
             TT shall be switched to 'OFF' immediately.
        */
       
        assignTTStatus(index, cTT_PHASE_OFF);

    }
    else if ((TTInfoTable[index].TTInputStatus > TT_TURN_ON) &&
             (TTInfoTable[index].TTInputStatus <= cTT_MAX_SUPPORTED_STATES))
    {
        /*
         State Transition - ON -> FLASH
           When TT is in 'ON' State, and 'FLASH' state is requested,
            switch to 'FLASH' state  and start Flash with Off Phase.
        */
        BlinkCtrl_Prepare_Flash_Process(index, cTT_PHASE_OFF);
        TTInfoTable[index].PrevTTInputStatus = TTInfoTable[index].TTInputStatus;
    }
    else
    {
        /*
           No State Transition. Maintain previous state and update output accordingly.
        */
        assignTTStatus(index, cTT_PHASE_ON);
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Process_PrevBlinkState_TT
///
/// @return None
//---------------------------------------------------------------------------------------------------------------------
static void Process_PrevBlinkState_TT(uint8 index)
{
   
    BlinkCtrl_Asynchronous_Flash_Process(index);

    /* Process Minimum and Maximum Flash Counter for each TT */
    BlinkCtrl_Flash_Min_Max_Cntr_Process(index);
    if(TTInfoTable[index].TTInputStatus == TT_TURN_OFF)
    {
        /*
          State Transition - FLASH -> OFF
           When TT is in 'FLASH' State, and 'OFF' state is requested,
            TT shall be stopped after finishing minimum Flash times configured.
        */
        if (0x00u == TTInfoTable[index].TTMinFlashCntr)
        {
             assignTTStatus(index, cTT_PHASE_OFF);
        }
        else
        {
            /*Do Nothing*/
        }
    }
    else if (TTInfoTable[index].TTInputStatus == TT_TURN_ON)
    {
        /*
          State Transition - FLASH -> ON
            When TT is in 'FLASH' State, and 'ON' state is requested,
             If TT is in 'ON' Phase, then TT shall be Switched to 'ON' Immediately.
             If TT is in 'OFF' Phase, then TT shall be Switched to 'ON' only after finishing 'OFF' phase..
        */
        isOnAllowed(index);
       
    }
    else
    {
        if ((TTInfoTable[index].PrevTTInputStatus > TT_TURN_ON) &&
            (TTInfoTable[index].PrevTTInputStatus <= cTT_MAX_SUPPORTED_STATES) &&
            (TTInfoTable[index].PrevTTInputStatus != TTInfoTable[index].TTInputStatus))
        {
            /*
              State Transition - FLASH -> FLASH
              When TT is in 'FLASH' State, and 'FLASH' with different frequency is requested,
               If TT is in 'ON' Phase, complete 'ON' phase and start new FLASH.
               If TT is in 'OFF' Phase, complete 'OFF' phase and start new FLASH.
            */
            BlinkCtrl_Different_Flash_Process(index);
        }
        else
        {
            /* No State Change. Same FLASH is in progress. Maintain Previous state */
            BlinkCtrl_Same_Flash_Process(index);
        } /*End of Same Flash Process*/
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  isOnAllowed
///
/// @return None
//---------------------------------------------------------------------------------------------------------------------
static void isOnAllowed(uint8 index)
{
    uint8 prev_requestedFreq_index = TTInfoTable[index].PrevTTInputStatus;

    if ((TTInfoTable[index].TTPhase == TT_TURN_ON) ||
       ((TTInfoTable[index].TTOnOffCntr == TTConfigTable[prev_requestedFreq_index].FlashOffPhaseCntr) ||
       (TTInfoTable[index].TTOnOffCntr == TTConfigTable[prev_requestedFreq_index].FlashOnPhaseCntr)))
    {
        assignTTStatus(index, cTT_PHASE_ON);
    }

}
