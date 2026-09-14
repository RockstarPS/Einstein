/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2009. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**============================================================================
**
** Name:           warn_msgArbitrator.c
**
** Description:    Message Core component.  This module detects application
**                  message triggers and passes them to the sequencer for
**                  displaying to the user.
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**==========================================================================*/
#define warn_msgArbitrator_C

/*==========================================================================*/
/*  I N C L U D E   F I L E S                                               */
/*==========================================================================*/
#include "system.h"
#include "warn_msgArbitrator.h"
#include "warn_msgArbitrator.cfg"
#include "localSemaphores.h"

/*==========================================================================*/
/* I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S    */
/*==========================================================================*/


/*==========================================================================*/
/* I N T E R N A L   F U N C T I O N   P R O T O T Y P E S                  */
/*==========================================================================*/


/*==========================================================================*/
/* M E M O R Y   A L L O C A T I O N                                        */
/*==========================================================================*/
static LOCAL_SEMAPHORES(arb_MessageStatus, MSG_NUM_MESSAGES);
#define MSG_STATUS_INACTIVE (FALSE)
#define MSG_STATUS_ACTIVE   (TRUE)

/*==========================================================================*/
/* E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S      */
/*==========================================================================*/

void msg_ArbitratorInitialise(void)
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Initialise arbitrator data.
**
**  Parameters:     None.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 12/Apr/2010
**==========================================================================*/
{
  CLEAR_ALL_SEMAPHORES(arb_MessageStatus);
}


void msg_ArbitratorUpdate(UINT8 Ignition)
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Check state of all messages and pass on changes to the client.
**
**  Parameters:     None.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 12/Apr/2010
**==========================================================================*/
{
  UINT32 i;
  BOOLEAN  fl_msgStatus;
  UINT8 msgRemoved;
  UINT16  msgCurrentState = MSG_CONDITION_OFF;
#ifdef MSG_FREEZE_IGN_MODE
  BOOLEAN checkWarning;
#endif
  MSG_MESSAGE_STRUCT const * ptrMessage;
  SIF_STATUS conditionStatus;

  ptrMessage = &messageList[0];

  for (i=0UL; i < (UINT32)MSG_NUM_MESSAGES; i++)
  {
    TEST_INDICATE(i);
    fl_msgStatus = MSG_STATUS_INACTIVE;

#ifdef MSG_FREEZE_IGN_MODE
    /*------------------------------------------------------------------*/
    /* Check current IGN state to process all the warnings              */
    /*------------------------------------------------------------------*/

    if (TESTBIT(Ignition, MSG_FREEZE_IGN_MODE) )
    {
      /*--------------------------------------------------------------*/
      /* Check whether the warning is configured in Freeze state      */
      /*--------------------------------------------------------------*/
      if(TESTBIT(MSG_FREEZE_IGN_MODE, ptrMessage->ActiveStates) )
      {
        /*----------------------------------------------------------*/
        /* Message is configured in Freeze state, So set warning    */
        /* check is required as TRUE                                */
        /*----------------------------------------------------------*/
        checkWarning = TRUE;
      }
      else
      {
        /*----------------------------------------------------------*/
        /* Message is NOT configured in Freeze state, So set warning*/
        /* check is required as FALSE                               */
        /*----------------------------------------------------------*/
        checkWarning = FALSE;
      }
    }
    else
    {
      checkWarning = TRUE;
    }


    if (FALSE != checkWarning)
#endif
    {
      /*------------------------------------------------------------------*/
      /* Check current IGN state is configured for this warning message.  */
      /*------------------------------------------------------------------*/

      if (TESTBIT(Ignition, ptrMessage->ActiveStates) )
      {
#if MSG_NUM_INSTANCES > 1
        conditionStatus = SIF_EXEC_INST((ptrMessage->CheckActiveCondition),
          (msgCurrentState),
          (ptrMessage->ConditionQualifier),(ptrMessage->InstanceID));
#else
        conditionStatus = SIF_EXEC((ptrMessage->CheckActiveCondition),
          (msgCurrentState),
          (ptrMessage->ConditionQualifier));
#endif
        if (sif_OK != conditionStatus)
        {
          /*----------------------------------------------------------*/
          /* If returned status is not "OK" then we can't rely on     */
          /* the data so assume message request is FALSE              */
          /*----------------------------------------------------------*/
          msgCurrentState = MSG_CONDITION_OFF;
        }

        switch (msgCurrentState)
        {
        case MSG_CONDITION_RETRIGGER:
          /*----------------------------------------------------------*/
          /* Retrigger the message to restart the display timer to    */
          /* start the progress bar newly(if the same msg in display) */
          /*----------------------------------------------------------*/
          fl_msgStatus = MSG_STATUS_ACTIVE;
          MSG_ARBITRATOR_RETRIGGER(i);
          break;

        case MSG_CONDITION_FORCED:
          /*----------------------------------------------------------*/
          /* Forcing message to be ACTIVE and behave as though this   */
          /* is a new message request.                                */
          /*----------------------------------------------------------*/
          CLR_SEMAPHORE(arb_MessageStatus, (UINT16)i);    /* ### QAC WARNING:4130 ### */
          fl_msgStatus = MSG_STATUS_ACTIVE;
          MSG_ARBITRATOR_FORCEDACTIVE(i);
          break;

        case MSG_CONDITION_ACTIVE:
          /*----------------------------------------------------------*/
          /* Normal action when a message is ACTIVE.                  */
          /*----------------------------------------------------------*/
          fl_msgStatus = MSG_STATUS_ACTIVE;
          break;

        default:
          /*----------------------------------------------------------*/
          /* Nothing to do since the default is to set the            */
          /* message as INACTIVE                                      */
          /*----------------------------------------------------------*/
          break;
        }
      }

      /*------------------------------------------------------------------*/
      /* Notify client if message goes INACTIVE or becomes ACTIVE.        */
      /*------------------------------------------------------------------*/
      if (MSG_STATUS_INACTIVE != fl_msgStatus)
      {
        if (MSG_STATUS_INACTIVE == ((GET_SEMAPHORE(arb_MessageStatus, (UINT16)i))?TRUE:FALSE))
        {
          MSG_ARBITRATOR_ADD(i);
          SET_SEMAPHORE(arb_MessageStatus, (UINT16)i);
        }
      }
      else
      {
        if (MSG_STATUS_INACTIVE != ((GET_SEMAPHORE(arb_MessageStatus, (UINT16)i))?TRUE:FALSE))
        {
          msgRemoved = MSG_ARBITRATOR_REMOVE(i, Ignition);

          /*-------------------------------------------------------*/
          /* Clear the Msg Arbitration status flag only if message */
          /* is removal is accepted by Sequencer                   */
          /*-------------------------------------------------------*/
          if(0U != msgRemoved)
          {
            CLR_SEMAPHORE(arb_MessageStatus, (UINT16)i);    /* ### QAC WARNING:4130 ### */
          }
        }
      }
    }

    ptrMessage++;
  }
}

/*==========================================================================*/
/* R E V I S I O N    N O T E S                                             */
/*==========================================================================*/
/* For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**==========================================================================*/

/****************************************************************************
**  Date  : 06/Apr/2010
**  by    : AFERRIS2
**  Ref   : None.
**  Change: Initial version.
**
*****************************************************************************/

/****************************************************************************
**  Date: 06/May/2010     by: AFERRIS2        Ref: None.
**  Change: 1.  Add checking of status from the application message request
**              interfaces.
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 07/Jul/2010     by: AFERRIS2        Ref:
**  Change: 1.  Removed QAC warning from TESTBIT operation.
**          2.  2 warnings remain from the use of CLR_SEMAPHORE (cannot be eliminated)
**
**  Checks: COMPILER - NO WARNINGS       QAC - 2 WARNINGS
*****************************************************************************/

/****************************************************************************
**  Date: 12/Mar/2012     by: vsarava2        Ref:DCR 3190/3191
**  Change: 1. Freeze mode condition enabled before checking the warning state.
**             So, if warning is not configured for Freeze Ign mode, then warning
**             active state shall not be checked and the update not passed to client
**             if warning is configued for freezeign mode, then warning trigger
**             condition is checked and updated to client(sequencer).
**             This code shall be included only if FREEZE_IGN_MODE is defined.
**
**  Checks: COMPILER - NO WARNINGS       QAC - 2 WARNINGS
*****************************************************************************/

/****************************************************************************
**  Date: 12/Mar/2012     by: vsarava2        Ref: BSDI00112440 / BSDI00111853
**  Change: 1. Retrigger option added to restart the message again if it is
**             currently in display
**
**  Checks: COMPILER - NO WARNINGS       QAC - 2 WARNINGS
*****************************************************************************/

/****************************************************************************
**  Date: 10/Aug/2013     by: vsarava2        Ref: RTC 60620
**  Msg Arbitrator Remove function called with Ignition state and updated to
**  check sequencer remove status to update the Arbitration flags.
*****************************************************************************/

/****************************************************************************
**  Date: 28/Apr/2015     by: adevi        
**  Alignment corrected.
*****************************************************************************/

/****************************************************************************
**  Date: 29/Jun/2015     by: adevi        Ref: RTC 365702
**  Change: QAC warnings resolved for Honda THAA
*****************************************************************************/

/****************************************************************************
**  Date: 04/May/2017     by: arajase2        
**  Ref: RTC 859438: CMFB MISRA Warning fixes - message.core
**  Change: MISRA warnings resolved for CMFB
*****************************************************************************/

/* end of file =============================================================*/
