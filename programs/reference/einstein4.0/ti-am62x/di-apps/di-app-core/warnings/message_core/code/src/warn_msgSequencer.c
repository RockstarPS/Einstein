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
** Name:           warn_msgSequencer.c
**
** Description:     Core message component.  This module selects new messages to
**                  be displayed to the driver.
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**==========================================================================*/
#define warn_msgSequencer_C

/*==========================================================================*/
/*  I N C L U D E   F I L E S                                               */
/*==========================================================================*/
#include "warn_msgSequencer.h"
#include "warn_msgSequencer.cfg"
#include "localSemaphores.h"
#include "warn_msgInstConfig.h"


/*==========================================================================*/
/* I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S    */
/*==========================================================================*/


/*----------------------------------------------------------------------*/
/* Set optimisation OFF (useful for debugging)                          */
/*----------------------------------------------------------------------*/
/* #pragma optimization_level 0 */


/*==========================================================================*/
/* I N T E R N A L   F U N C T I O N   P R O T O T Y P E S                  */
/*==========================================================================*/
static void seq_InitIndex(UINT8 inst);
static void seq_InitList(UINT8 inst);
static void seq_InitView(UINT8 inst);

static void seq_UpdateViewer(eMessageIdentity MessageID, UINT32 MsgIndex,UINT8 inst);
static UINT32 seq_InsertMessage(const MSG_MESSAGE_STRUCT *theMessage, eMessageIdentity MessageID);
static BOOLEAN seq_RemoveMessage(eMessageIdentity MessageID);
static void seq_IndexUp(UINT16 BaseCategory,UINT8 inst);
static void seq_IndexDown(UINT16 BaseCategory,UINT8 inst);
static void seq_Delete(UINT32 Index,UINT8 inst);
static void seq_Insert(UINT32 Index, eMessageIdentity MessageID);
static void seq_GetViewMessage(MSG_VIEWINFO_T *ViewInfo,UINT8 inst);
static void seq_SetViewMessage(eMessageIdentity MessageID,UINT8 inst);
static UINT16 seq_GetViewCount(UINT32 CategoryMask,UINT8 inst);
static UINT16 seq_GetViewIndex(eMessageIdentity MessageID, UINT32 CategoryMask,UINT8 inst);

static UINT32 seq_FindFirstIndex(UINT32 CategoryMask,UINT8 inst);
static UINT32 seq_FindNextIndex(UINT32 Start, UINT32 CategoryMask,UINT8 inst);
static UINT32 seq_FindPreviousIndex(UINT32 Start, UINT32 CategoryMask,UINT8 inst);

static void seq_Callback(eMessageIdentity MessageID, UINT16 Action);
static void seq_RemoveHoldMessage(UINT8 inst);
static eMessageIdentity seq_GetTopMostMessage(UINT8 inst);
static eMessageIdentity seq_GetNewMessage(eMessageCategory Category,UINT8 inst);
static eMessageIdentity seq_GetLowerCategoryMessage(eMessageCategory Category,UINT8 inst);
static eMessageIdentity seq_GetNextMessage(eMessageCategory Category, eMessageIdentity Message,UINT8 inst);
static eMessageIdentity seq_FindActiveMessage(eMessageCategory Category, eMessageIdentity Message,UINT8 inst);
#ifdef ALTERNATELY_SHOW_MSG_FRM_CATEGORY
#define CATEGORYMASK_TO_BE_SHOWN_ALTERNATELY     1<<CATEGORY_TO_BE_SHOWN_ALTERNATELY
static eMessageIdentity seq_GetMsgToBeShownAlternately(eMessageIdentity l_MessageID, UINT8 l_dispIndTimerStatus,UINT8 inst);
#endif
#ifdef  ALLOW_UNDISPLAYED_MSG_IMMEDIATELY
static eMessageIdentity seq_GetHighPrioNewMessage(eMessageCategory Category,UINT8 inst);
static void seq_SetLowerCategoryMsgDispOnce(eMessageCategory p_Category,UINT8 inst);
#endif
#ifdef MSG_CYCLE_OPTION_WITH_TIMEOUT
static UINT16 seq_MsgDisplayTime(eMessageIdentity MessageID);
#endif
/*==========================================================================*/
/* M E M O R Y   A L L O C A T I O N                                        */
/*==========================================================================*/

static LOCAL_SEMAPHORES(seq_NewMessageFlags, MSG_NUM_MESSAGES);
static LOCAL_SEMAPHORES(seq_DisplayedOnceFlags, MSG_NUM_MESSAGES);
#ifdef MSG_CYCLE_OPTION_WITH_TIMEOUT
/* Counter array to store total display time out value for each warning.*/
static UINT16 seq_DsplyTimeList[MSG_NUM_MESSAGES + 1];
#endif


#ifdef WARN_MSG_ENABLE_NEW_MESSAGE_SEQ_QUEUE_TIMEOUT
/*--------------------------------------------------------------------------*/
/* Timeout counter array to maintain/store new message queue timeout value  */
/* for each warning                                                         */
/* If this array index hold 0xffff means the new msg timeout is not         */
/* applicable for that message.                                             */
/* The array value is based on multiples of timeout value*the rate at which */
/* the timer function is executing. Need to take care the timeout value     */
/* shall not exceed U16 max value.                                          */
/*--------------------------------------------------------------------------*/
static UINT8 Seq_NewMsgQTimeout_U8[MSG_NUM_MESSAGES + 1];
#endif

#ifdef MSG_OLD_WRNG_REPETITION
/*--------------------------------------------------------------------------*/
/* Array that holds the old warning repetition duration of every message  */
/*--------------------------------------------------------------------------*/
static UINT16 seq_Old_Wrng_RepDuration[MSG_NUM_MESSAGES + 1];
#endif

/*--------------------------------------------------------------------------*/
/* Bitfield flag to indicte whether message is recycled or shown first time */
/*--------------------------------------------------------------------------*/
static LOCAL_SEMAPHORES(seq_MsgRecycleFlags, MSG_NUM_MESSAGES);

static UINT32 seq_ViewMask;

#if defined ENABLE_PRIVATE_TIMERS
#if MSG_NUM_INSTANCES > 1
#error "Instance configuration support not provided for private timers"
#else
static TIMER  seq_DisplayTimer;
static TIMER  seq_HoldTimer;
static TIMER  seq_CycleTimer;
static TIMER  seq_DispIndTimer;
static TIMER  seq_AckAftMinToutTimer;
#ifdef MSG_CYCLE_OPTION_WITH_TIMEOUT
static TIMER  seq_1secTimer;
#endif
#ifdef WARN_MSG_ENABLE_NEW_MESSAGE_SEQ_QUEUE_TIMEOUT
static TIMER  seq_MsgQTimeout_1SecTimer;
#endif
#ifdef MSG_OLD_WRNG_REPETITION
/* Timer used for 1 second calculation for old warning repetition */
static TIMER  seq_OldWrng_Rep_1SecTimer;
#endif
#endif
#endif


typedef struct {
  eMessageIdentity seq_CurrentMessageID;
  eMessageIdentity seq_HoldMessageID;
  eMessageIdentity seq_RetriggerMessageID;
  eMessageIdentity seq_ForcedActiveMessageID;
#ifdef CYCLE_IN_ORDER_WITHIN_CATEGORY
  eMessageIdentity seq_NextCycleMessageID;
#endif 
#ifdef ALTERNATELY_SHOW_MSG_FRM_CATEGORY
  eMessageIdentity seq_PrevMessageID;
#endif
#ifdef DISP_TOUT_NO_TOUT_MSG_BY_PRIORITY
  BOOLEAN CurrentlyDisplayingNewMsgFlag;
  eMessageIdentity NextMessageID;
#endif
  eMessageIdentity seq_MessageList[MSG_NUM_MESSAGES + 1];
  UINT16 seq_Categories[MSG_NUM_MESSAGE_CATEGORIES + 1];
  MSG_VIEWINFO_T   seq_ViewMessage;
}MSG_INST_CONFIG_T;


static MSG_INST_CONFIG_T  l_msg_instance_array[MSG_NUM_INSTANCES];


#define SEQ_LAST_INDEX(inst)  (l_msg_instance_array[(inst)].seq_Categories[MSG_NUM_MESSAGE_CATEGORIES])



/*==========================================================================*/
/* E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S      */
/*==========================================================================*/

void msg_SequencerInitialise(UINT8 inst)
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Message sequencer initialisation
**
**  Parameters:     None.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 12/Apr/2010
**==========================================================================*/
{
  if(inst < MSG_NUM_INSTANCES)
  {
    seq_InitIndex(inst);
    seq_InitList(inst);

    l_msg_instance_array[inst].seq_CurrentMessageID = MSG_INDEX_UNDEFINED;
#ifdef ALTERNATELY_SHOW_MSG_FRM_CATEGORY
    l_msg_instance_array[inst].seq_PrevMessageID  = MSG_INDEX_UNDEFINED;
#endif
#ifdef CYCLE_IN_ORDER_WITHIN_CATEGORY
    l_msg_instance_array[inst].seq_NextCycleMessageID = MSG_INDEX_UNDEFINED;
#endif 
    l_msg_instance_array[inst].seq_HoldMessageID = MSG_INDEX_UNDEFINED;
    l_msg_instance_array[inst].seq_RetriggerMessageID = MSG_INDEX_UNDEFINED;
    l_msg_instance_array[inst].seq_ForcedActiveMessageID = MSG_INDEX_UNDEFINED;

    seq_InitView(inst);


    MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_DisplayTimer);
    MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_HoldTimer);
    MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_AckAftMinToutTimer);


#ifdef MSG_CYCLE_OPTION_WITH_TIMEOUT
    MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_1secTimer);
#endif
#ifdef WARN_MSG_ENABLE_NEW_MESSAGE_SEQ_QUEUE_TIMEOUT
    MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_MsgQTimeout_1SecTimer);
#endif

#ifdef MSG_OLD_WRNG_REPETITION
    /* Timer used for 1 second calculation for old warning repetition */
    MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_OldWrng_Rep_1SecTimer);
#endif
#ifdef DISP_TOUT_NO_TOUT_MSG_BY_PRIORITY
    l_msg_instance_array[inst].CurrentlyDisplayingNewMsgFlag = FALSE;
    l_msg_instance_array[inst].NextMessageID = MSG_INDEX_UNDEFINED;
#endif
    MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_DispIndTimer);

    CLEAR_ALL_SEMAPHORES(seq_NewMessageFlags);
    CLEAR_ALL_SEMAPHORES(seq_MsgRecycleFlags);
    CLEAR_ALL_SEMAPHORES(seq_DisplayedOnceFlags);
  }
}

#ifdef MSG_ACK_WRNG_REPETITION
void msg_ClearNewMessageFlag(eMessageIdentity MessageID)
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Clear the new message flag of the MessageID passed.
**
**  Parameters:     eMessageIdentity MessageID.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: adevi 17/Dec/2013
**==========================================================================*/
{
  /* Clear the newmessage flag of the message ID passed */
  CLR_SEMAPHORE(seq_NewMessageFlags, MessageID);
}

#ifdef MSG_OLD_WRNG_REPETITION
void msg_SetOldWrngRepDur(eMessageIdentity MessageID)
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Set the old warning repetition duration of MessageID.
**
**  Parameters:     eMessageIdentity MessageID.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: adevi 17/Dec/2013
**==========================================================================*/
{
  const MSG_MESSAGE_STRUCT *pMessage;

  pMessage = &messageList[MessageID];
  if(TESTBIT(pMessage->Options, (UINT32)MSG_OPTION_OLD_WRNG_REPEAT))
  {
    /*--------------------------------------------------------------*/
    /* The warning has now become old so load old warning repeat    */
    /* duration in the seq_Old_Wrng_RepDuration array               */
    /*--------------------------------------------------------------*/
    seq_Old_Wrng_RepDuration[MessageID] = HMI_MSG_OLD_WRNG_REP_DUR;
  }
}
#endif
#endif


void msg_SequencerUpdate(UINT8 Ignition, UINT8 inst)
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Message sequencer update.  Two actions are performed:
**                  1. Activate a new message when the highest priority message
**                      changes.
**                  2. Handle the timeout of the currently selected message.
**                  3. Based on the options enabled allow low priority message
**                     to be sent to display.
**                  4. Special handling when an alert is interrupted by another
**                     equal priority alert.
**
**  Parameters:     None.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 12/Apr/2010
**==========================================================================*/
{
  const MSG_MESSAGE_STRUCT *pMessage;
  const MSG_MESSAGE_STRUCT *currentMessage = MSG_NULL_PTR;
  eMessageIdentity MessageID;
  eMessageIdentity fl_ValidTopMessageID;
  eMessageIdentity lowCategoryMessageID = MSG_INDEX_UNDEFINED;
  eMessageCategory category;
#ifdef ALTERNATELY_SHOW_MSG_FRM_CATEGORY
  UINT16 count;
#endif
  UINT32 currentMessageOptions = 0;
  UINT8 cycleTimerStatus;
  UINT8 holdTimerStatus;
  UINT8 displayTimerStatus;
  UINT8 dispIndTimerStatus;
  eMessageIdentity fl_newMessageInCategory;
#ifdef ALLOW_UNDISPLAYED_MSG_IMMEDIATELY
  UINT32 thisIndex;
#endif

#ifdef MSG_CYCLE_OPTION_WITH_TIMEOUT
  UINT16 displayTimeout;
  UINT8 msg1secTimerStatus;
#endif

  if(inst < MSG_NUM_INSTANCES)
  {
    holdTimerStatus = MSG_CHECK_SW_TIMER(hmi_msg_inst_config_table[inst].seq_HoldTimer);
    displayTimerStatus = MSG_CHECK_SW_TIMER(hmi_msg_inst_config_table[inst].seq_DisplayTimer);
    dispIndTimerStatus = MSG_CHECK_SW_TIMER(hmi_msg_inst_config_table[inst].seq_DispIndTimer);


    /*----------------------------------------------------------------------*/
    /* Process hold message (if defined)                                    */
    /*----------------------------------------------------------------------*/
    if (MSG_INDEX_UNDEFINED != l_msg_instance_array[inst].seq_HoldMessageID)
    {
#ifdef MSG_REMOVE_HOLD_MSG_IN_NA_IGN_MODE
      pMessage = &messageList[l_msg_instance_array[inst].seq_HoldMessageID];
#else
      HMI_MSG_UNUSED_VAR(Ignition);
#endif
      /*------------------------------------------------------------------*/
      /* Remove message if timer has expired or current message has       */
      /* changed.                                                         */
      /*------------------------------------------------------------------*/
      if ((TIMER_RUNNING != holdTimerStatus)
#ifdef MSG_REMOVE_HOLD_MSG_IN_NA_IGN_MODE
        || (!TESTBIT(Ignition, pMessage->ActiveStates))
#endif
        )
      {
        seq_RemoveHoldMessage(inst);
      }
    }

    /*----------------------------------------------------------------------*/
    /* process current message timeouts                                     */
    /*----------------------------------------------------------------------*/
    if ((MSG_INDEX_UNDEFINED != l_msg_instance_array[inst].seq_CurrentMessageID) && (l_msg_instance_array[inst].seq_CurrentMessageID < MSG_NUM_MESSAGES))
    {

      UINT16 fl_HoldTimeout;

      pMessage = &messageList[l_msg_instance_array[inst].seq_CurrentMessageID];

#ifdef MSG_GET_DYN_HOLD_TIME
      fl_HoldTimeout = pMessage->HoldTimeout(l_msg_instance_array[inst].seq_CurrentMessageID);
#else
      fl_HoldTimeout = pMessage->HoldTimeout;
#endif
      /*--------------------------------------------------------------*/
      /* If the T2 timer is running then the new msg flag is reset    */
      /* only when the timer expires.                                 */
      /*--------------------------------------------------------------*/
      if(TESTBIT(pMessage->Options, (UINT32)MSG_OPTION_DISP_INDICATIONTIME))
      {
        if ((TIMER_EXPIRED == dispIndTimerStatus) && (FALSE != GET_SEMAPHORE(seq_NewMessageFlags, l_msg_instance_array[inst].seq_CurrentMessageID)))
        {
#ifdef MSG_OLD_WRNG_REPETITION
          /*----------------------------------------------------------------------------*/
          /* If MSG_OPTION_OLD_WRNG_REPEAT is not enabled then clear the newMessageFlag */
          /*----------------------------------------------------------------------------*/
          if(!TESTBIT(pMessage->Options, (UINT32)MSG_OPTION_OLD_WRNG_REPEAT))
          {
#endif
            CLR_SEMAPHORE(seq_NewMessageFlags, l_msg_instance_array[inst].seq_CurrentMessageID);
#ifdef MSG_OLD_WRNG_REPETITION
          }
          /*-----------------------------------------------------------------------*/
          /* If MSG_OPTION_OLD_WRNG_REPEAT is enabled then new message flag should */
          /* not be cleared when the value is 0 so invalid array value is checked  */
          /*-----------------------------------------------------------------------*/
          else if((TESTBIT(pMessage->Options,(UINT32) MSG_OPTION_OLD_WRNG_REPEAT)) &&
            (seq_Old_Wrng_RepDuration[l_msg_instance_array[inst].seq_CurrentMessageID] == HMI_MSG_OLD_WRNG_REP_INVALID_U16))
          {
            /*--------------------------------------------------------------*/
            /* The warning has now become old so load old warning repeat    */
            /* duration in the seq_Old_Wrng_RepDuration array               */
            /*--------------------------------------------------------------*/
            seq_Old_Wrng_RepDuration[l_msg_instance_array[inst].seq_CurrentMessageID] = HMI_MSG_OLD_WRNG_REP_DUR;
            CLR_SEMAPHORE(seq_NewMessageFlags, l_msg_instance_array[inst].seq_CurrentMessageID);
          }
          else
          {
            /* Do nothing */
          }
#endif
          seq_Callback(l_msg_instance_array[inst].seq_CurrentMessageID, MSG_EVENT_OLD);
          MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_DispIndTimer);
        }
      }
      /*--------------------------------------------------------------*/
      /* If the hold timer has expired then message is no longer "NEW"*/
      /*--------------------------------------------------------------*/

      /* Even for messages for which hold timer is not configured due to timer status check the new message flag gets cleared */
      /* To avoid this the hold timeout value is also checked before clearing new message flag */
      else if ((TIMER_RUNNING != holdTimerStatus) && ((UINT16)MSG_NO_TIMEOUT != fl_HoldTimeout))
      {
        CLR_SEMAPHORE(seq_NewMessageFlags, l_msg_instance_array[inst].seq_CurrentMessageID); /* ### QAC WARNING:4130 ### */
      }
      else
      {
        /*-------------*/
        /* Do nothing  */
        /*-------------*/
      }
#ifdef MSG_CYCLE_OPTION_WITH_TIMEOUT
      /*--------------------------------------------------------------*/
      /* Read the Seq.current msg options,Current msg may be different*/
      /* from the message which is in top of Seq Q.                   */
      /*--------------------------------------------------------------*/
      pMessage = &messageList[l_msg_instance_array[inst].seq_CurrentMessageID];
      displayTimeout = pMessage->DisplayTimeout;
#endif

      /*--------------------------------------------------------------*/
      /* Message has not changed.  Check for display timeout.         */
      /*--------------------------------------------------------------*/
      if ((TIMER_EXPIRED == displayTimerStatus)
#ifdef MSG_CYCLE_OPTION_WITH_TIMEOUT
        || ((seq_DsplyTimeList[l_msg_instance_array[inst].seq_CurrentMessageID] == 0) &&
        (0 != displayTimeout)) /* i.e. NO_TIMEOUT */
        /*i.e. The 1 sec counter (display time list) is applicable only if message has valid timeout. */
#endif
        )

      {
        BOOLEAN isDeactivated;

        UINT32 msgIndex = seq_GetViewIndex(l_msg_instance_array[inst].seq_CurrentMessageID, MSG_ALL_CATEGORIES,inst);
#ifdef DISP_TOUT_NO_TOUT_MSG_BY_PRIORITY
        /*--------------------------------------------------------------*/
        /* Since the l_msg_instance_array[inst].seq_CurrentMessageID will be removed from the      */
        /* message queue store the message next to l_msg_instance_array[inst].seq_CurrentMessageID */
        /*--------------------------------------------------------------*/
        currentMessage = &messageList[l_msg_instance_array[inst].seq_CurrentMessageID];
        category = currentMessage->Category;
        l_msg_instance_array[inst].NextMessageID = seq_GetNextMessage(category, l_msg_instance_array[inst].seq_CurrentMessageID,inst);
#endif
        /*----------------------------------------------------------*/
        /* Remove message if the timer has expired, but don't change*/
        /* the current message ID.  This will be done below.        */
        /*----------------------------------------------------------*/
        isDeactivated = seq_RemoveMessage(l_msg_instance_array[inst].seq_CurrentMessageID);
        seq_Callback(l_msg_instance_array[inst].seq_CurrentMessageID, MSG_EVENT_TIMEOUT);
        if (FALSE != isDeactivated)
        {
          seq_UpdateViewer(l_msg_instance_array[inst].seq_CurrentMessageID, msgIndex,inst);
          MSG_SEQUENCER_CLIENT_ADD(l_msg_instance_array[inst].seq_CurrentMessageID);
        }
      }
    }

    /*----------------------------------------------------------------------*/
    /* Check the Cycle Timer status. This might be changed during removal   */
    /* of HOLD message. Due to this, it moved here.                         */
    /*----------------------------------------------------------------------*/
    cycleTimerStatus = MSG_CHECK_SW_TIMER(hmi_msg_inst_config_table[inst].seq_CycleTimer);

#ifdef MSG_CYCLE_OPTION_WITH_TIMEOUT
    /*----------------------------------------------------------------------*/
    /* Check the onesec message timer status.                               */
    /*----------------------------------------------------------------------*/
    msg1secTimerStatus = MSG_CHECK_SW_TIMER(hmi_msg_inst_config_table[inst].seq_1secTimer);
#endif

    /*----------------------------------------------------------------------*/
    /* Get message to be displayed                                          */
    /*----------------------------------------------------------------------*/
    fl_ValidTopMessageID = seq_GetTopMostMessage(inst);
    MessageID = fl_ValidTopMessageID;

    if ((MSG_INDEX_UNDEFINED != fl_ValidTopMessageID) && (fl_ValidTopMessageID < MSG_NUM_MESSAGES))
    {
      eMessageIdentity seq_tempCurrentMessageID = l_msg_instance_array[inst].seq_CurrentMessageID;
      /*------------------------------------------------------------------*/
      /* Work out which message should be displayed.                      */
      /*------------------------------------------------------------------*/
      pMessage = &messageList[fl_ValidTopMessageID];
      category = pMessage->Category;
      /* Coverity fix - Prevention of Invalid seq_CurrentMessageID */
      if((MSG_INDEX_UNDEFINED != seq_tempCurrentMessageID) && (seq_tempCurrentMessageID < MSG_NUM_MESSAGES))
      {
        currentMessage = &messageList[seq_tempCurrentMessageID];
        currentMessageOptions = currentMessage->Options;
      }
#ifdef DISP_TOUT_NO_TOUT_MSG_BY_PRIORITY
      /*------------------------------------------------------------------*/
      /* When there are no more new messages in the category then check   */
      /* for cycling option.                                              */
      /*------------------------------------------------------------------*/
      if(MSG_INDEX_UNDEFINED == seq_GetNewMessage(category,inst))
      {
#ifdef MSG_ACK_WRNG_REPETITION
        /* When there are no messages in seq_MessageList and when a msg */
        /* is added from store queue due to ack warning repetition then */
        /* seq_CurrentMessageID would be MSG_INDEX_UNDEFINED so consider*/
        /* the options of seq_MessageList[0]                            */
        if((MSG_INDEX_UNDEFINED == l_msg_instance_array[inst].seq_CurrentMessageID) &&(MessageID < MSG_NUM_MESSAGES))
        {
          currentMessage = &messageList[MessageID];
          currentMessageOptions = currentMessage->Options;
        }
#endif
        if (TESTBIT(currentMessageOptions, (UINT32)(MSG_OPTION_CYCLE)))
#else
      if (TESTBIT(pMessage->Options, (UINT32)MSG_OPTION_CYCLE))
#endif
      {
        /*--------------------------------------------------------------*/
        /* Category is cycling...                                       */
        /* Check for a different message if the cycle timer has expired */
        /*--------------------------------------------------------------*/
        if (TIMER_RUNNING != cycleTimerStatus)
        {
          MessageID = seq_GetNewMessage(category,inst);
          if (MSG_INDEX_UNDEFINED == MessageID)
          {
#ifdef DISP_TOUT_NO_TOUT_MSG_BY_PRIORITY
            /*------------------------------------------------------------------*/
            /* If the seq_CurrentMessageID is a new message and its not the     */
            /* topmost msg of the queue then start cycling from the first msg.  */
            /*------------------------------------------------------------------*/
            if ((FALSE != l_msg_instance_array[inst].CurrentlyDisplayingNewMsgFlag) &&
              (l_msg_instance_array[inst].seq_CurrentMessageID != fl_ValidTopMessageID))
            {
              MessageID = fl_ValidTopMessageID;
            }
            /*------------------------------------------------------------------*/
            /* If the seq_CurrentMessageID is a new message and its the topmost */
            /* msg of the queue then start cycling from the next msg. Else the  */
            /* topmost msg will be on display always                            */
            /*------------------------------------------------------------------*/
            else
#endif
            {
#ifdef ALTERNATELY_SHOW_MSG_FRM_CATEGORY
              count = seq_GetViewCount(CATEGORYMASK_TO_BE_SHOWN_ALTERNATELY,inst);
              if(count > (UINT16)0)
              {
                /*------------------------------------------------------*/
                /* When the message from a category gets alternately    */
                /* displayed then the seq_CurrentMessageID would be the */
                /* msg alternately shown.  While cycling the next msg   */
                /* from the category should be next to seq_PrevMessageID*/
                /*------------------------------------------------------*/
                MessageID = seq_GetNextMessage(category, l_msg_instance_array[inst].seq_PrevMessageID,inst);
              }
              else
#endif
              {
                /*------------------------------------------------------*/
                /* No new messages, so get next one in this category    */
                /*------------------------------------------------------*/
                MessageID = seq_GetNextMessage(category, l_msg_instance_array[inst].seq_CurrentMessageID,inst);
#ifdef CYCLE_IN_ORDER_WITHIN_CATEGORY
                /*------------------------------------------------------*/
                /* If the currently displaying message is no more active*/                     
                /*------------------------------------------------------*/
                if(seq_FindActiveMessage(currentMessage->Category, l_msg_instance_array[inst].seq_CurrentMessageID, inst) != l_msg_instance_array[inst].seq_CurrentMessageID)
                {
                  /*------------------------------------------------------*/
                  /*The next message saved during removal of the current  */ 
                  /*message should reach the display                      */
                  /*------------------------------------------------------*/
                  if(l_msg_instance_array[inst].seq_NextCycleMessageID != MSG_INDEX_UNDEFINED)
                  {
                    MessageID = l_msg_instance_array[inst].seq_NextCycleMessageID;
                  }
                }                  
#endif 
              }
            }
            /*------------------------------------------------------*/
            /* Indicate the message is RECYCLED                     */
            /*------------------------------------------------------*/
            if(MessageID < MSG_NUM_MESSAGES)
            {
              SET_SEMAPHORE(seq_MsgRecycleFlags,MessageID); /* ### QAC WARNING:1253 ### */
            }
          }
#ifdef MSG_CYCLE_OPTION_WITH_TIMEOUT
          /*------------------------------------------------------*/
          /* check for the counter value of the current message       */
          /* If it is greater that 0, start one sec timer             */
          /* If only one message in Seq Q, then the 1 sec timer need  */
          /* to be started here.                                      */
          /*----------------------------------------------------------*/
          if ((seq_DsplyTimeList[MessageID] > 0) && (TIMER_RUNNING != msg1secTimerStatus))
          {
            MSG_START_SW_TIMER(HMI_MSG_1SEC_TIME, hmi_msg_inst_config_table[inst].seq_1secTimer);
            /*------------------------------------------------------*/
            /* When it comes first time, for any new message, the   */
            /* timer shall not be decremented                       */
            /*------------------------------------------------------*/
            if (TIMER_CLEAR != msg1secTimerStatus)
            {
              if (seq_DsplyTimeList[MessageID] >= HMI_MSG_1SEC_TIME)
              {
                seq_DsplyTimeList[MessageID] = (seq_DsplyTimeList[MessageID] - HMI_MSG_1SEC_TIME);
              }
              else
              {
                seq_DsplyTimeList[MessageID] = 0;
              }
            }
          }
#endif
        }
        else
        {
          /*----------------------------------------------------------*/
          /* Use current message (or next priority if current is no   */
          /* longer active.                                           */
          /*----------------------------------------------------------*/
          MessageID = seq_FindActiveMessage(category, l_msg_instance_array[inst].seq_CurrentMessageID, inst);

#ifdef MSG_CYCLE_OPTION_WITH_TIMEOUT
          /*----------------------------------------------------------*/
          /*            Check one sec timerstatus.                    */
          /*----------------------------------------------------------*/
          /* The seq_DsplyTimeList[] counter shall be reduced only if */
          /* the current message msg has valid timeout.Otherwise don't*/
          /* change the message ID. It will be changed after CYCLE    */
          /* TIMER Expiry.                                            */
          /*----------------------------------------------------------*/
          if ((MSG_INDEX_UNDEFINED != seq_tempCurrentMessageID) && (seq_tempCurrentMessageID < MSG_NUM_MESSAGES))
          {
            pMessage = &messageList[seq_tempCurrentMessageID];
            displayTimeout = pMessage->DisplayTimeout;
          }
          else
          {
            displayTimeout = 0;
          }

          if ((TIMER_RUNNING != msg1secTimerStatus) && (0 != displayTimeout))
          {
            /*--------------------------------------------------------*/
            /* Dcrement the counter value by 1 if it is greater than 0*/
            /*--------------------------------------------------------*/
            if (seq_DsplyTimeList[MessageID] > 0)
            {
              if (seq_DsplyTimeList[MessageID] >= HMI_MSG_1SEC_TIME)
              {
                seq_DsplyTimeList[MessageID] = (seq_DsplyTimeList[MessageID] - HMI_MSG_1SEC_TIME);
                MSG_START_SW_TIMER(HMI_MSG_1SEC_TIME, hmi_msg_inst_config_table[inst].seq_1secTimer);
              }
              else
              {
                seq_DsplyTimeList[MessageID] = 0;
              }
            }
            else
            {
              /*-------------------------------------------------------*/
              /* get the new message for cycel                         */
              /*-------------------------------------------------------*/
              MessageID = seq_GetNewMessage(category,inst);
              if (MSG_INDEX_UNDEFINED == MessageID)
              {
                /*------------------------------------------------------*/
                /* No new messages, so get next one in this category    */
                /*------------------------------------------------------*/
                MessageID = seq_GetNextMessage(category, l_msg_instance_array[inst].seq_CurrentMessageID,inst);

                /*------------------------------------------------------*/
                /* Indicate the message is RECYCLED                     */
                /*------------------------------------------------------*/
                if(MessageID < MSG_NUM_MESSAGES)
                {
                  SET_SEMAPHORE(seq_MsgRecycleFlags, MessageID); /* ### QAC WARNING:1253 ### */
                }
              }

            }
          }
#endif
        }
      }
      else
      {
#ifdef DISP_TOUT_NO_TOUT_MSG_BY_PRIORITY
        /*------------------------------------------------------------------------*/
        /* When the display timer has expired select the next msg to be displayed */
        /*------------------------------------------------------------------------*/
        /* Even for messages for which display timer is not configured due to timer status check the new message flag gets cleared */
        /* To avoid this the display timeout value is also checked before clearing new message flag */
        if ((TIMER_RUNNING != displayTimerStatus) &&
          (currentMessage != NULL) &&
          ((UINT16)MSG_NO_TIMEOUT != currentMessage->DisplayTimeout))
        {
          if (FALSE != l_msg_instance_array[inst].CurrentlyDisplayingNewMsgFlag)
          {
            MessageID = fl_ValidTopMessageID;
          }
          else
          {
            MessageID = l_msg_instance_array[inst].NextMessageID;
          }
          if(MessageID < MSG_NUM_MESSAGES)
          {
            SET_SEMAPHORE(seq_MsgRecycleFlags, MessageID);
          }
        }
        else
        {
          MessageID = seq_FindActiveMessage(category, l_msg_instance_array[inst].seq_CurrentMessageID, inst);
        }
      }
#else
        /*--------------------------------------------------------------*/
        /* category is not cycling.  Use highest priority message.      */
        /*--------------------------------------------------------------*/
        MessageID = fl_ValidTopMessageID;
#endif
      }

      pMessage = &messageList[fl_ValidTopMessageID];
      /* If display for display indication time option is enabled for this msg */
      if(TESTBIT(pMessage->Options, (UINT32)MSG_OPTION_DISP_INDICATIONTIME))
      {
#ifdef ALLOW_UNDISPLAYED_MSG_IMMEDIATELY
        fl_newMessageInCategory = seq_GetHighPrioNewMessage(category,inst);
        /* Loop through all the messages in the current category and make it displayed once so that it is not interrupted 
        by messages in the same category. To allow immediate interruption from messages of other categories,
        displayed once flag is set for messages in the same category */ 
        thisIndex = l_msg_instance_array[inst].seq_Categories[(UINT32)category];
        while( thisIndex < l_msg_instance_array[inst].seq_Categories[(UINT32)category+ 1UL])
        {
          if(l_msg_instance_array[inst].seq_MessageList[thisIndex] != fl_newMessageInCategory)
          {
            SET_SEMAPHORE(seq_DisplayedOnceFlags, l_msg_instance_array[inst].seq_MessageList[thisIndex]);
          }
          thisIndex++;
        }
        if (!(GET_SEMAPHORE(seq_DisplayedOnceFlags, fl_ValidTopMessageID)))
        {
          seq_SetLowerCategoryMsgDispOnce(category,inst);
        }
#else
        fl_newMessageInCategory = seq_GetNewMessage(category,inst);
#endif
        /* check if the current high priority msg allows lower priority msg */
        /* to be displayed */
        if(TESTBIT(pMessage->Options, (UINT32)MSG_OPTION_ALLOW_LOW))
        {
          lowCategoryMessageID = seq_GetLowerCategoryMessage(category,inst);
        }
        else
        {
          /* do nothing */
        }
#ifdef ALLOW_UNDISPLAYED_MSG_IMMEDIATELY
        /* Starting from the lowest priority cateogory messages that have never been
        displayed once will be brought to display one after another in every cycle */
        if (MSG_INDEX_UNDEFINED != lowCategoryMessageID)
        {
          MessageID = lowCategoryMessageID;
        }
        /* when there are no more low priority messages that need to be displayed then
        high priority message that was never displayed once will be brought to display.*/
        else if (MSG_INDEX_UNDEFINED != fl_newMessageInCategory)
        {
          MessageID = fl_newMessageInCategory;
        }
        /* When there are no more messages to be displayed once, then the lower priority
        message on the display will continue to be in display till it becomes old */
        else if((TESTBIT(pMessage->Options,(UINT32) MSG_OPTION_ALLOW_LOW)) &&
          (TESTBIT(currentMessageOptions, (UINT32)MSG_OPTION_OVERRIDE_HIGH)) &&
          ((MSG_INDEX_UNDEFINED != l_msg_instance_array[inst].seq_CurrentMessageID) &&
          (GET_SEMAPHORE(seq_NewMessageFlags, l_msg_instance_array[inst].seq_CurrentMessageID))))
        {
          MessageID = l_msg_instance_array[inst].seq_CurrentMessageID;
        }
#else
        /* If the currently displayed msg can over ride high priority msg */
        /* then it should not be removed from display */
        if((TESTBIT(pMessage->Options, (UINT32)MSG_OPTION_ALLOW_LOW)) &&
          (TESTBIT(currentMessageOptions, (UINT32)MSG_OPTION_OVERRIDE_HIGH)) &&
          ((MSG_INDEX_UNDEFINED != l_msg_instance_array[inst].seq_CurrentMessageID) && (l_msg_instance_array[inst].seq_CurrentMessageID < MSG_NUM_MESSAGES) &&
          (FALSE != (BOOLEAN)GET_SEMAPHORE(seq_NewMessageFlags, l_msg_instance_array[inst].seq_CurrentMessageID))))
        {
          MessageID = l_msg_instance_array[inst].seq_CurrentMessageID;
        }
        /* If any new msg with option display indication time enters the category */
        else if(MSG_INDEX_UNDEFINED != fl_newMessageInCategory)
        {
#ifdef ALLOW_CURRENT_DURING_DISP_INDICATION_TIME
          /*----------------------------------------------------------------------*/
          /* If any high priority msg should not override the currently displayed */
          /* msg then check for new message flag of seq_CurrentMessageID          */
          /*----------------------------------------------------------------------*/
          if ((MSG_INDEX_UNDEFINED != l_msg_instance_array[inst].seq_CurrentMessageID)&&
            (GET_SEMAPHORE(seq_NewMessageFlags, l_msg_instance_array[inst].seq_CurrentMessageID)))
          {
            MessageID = l_msg_instance_array[inst].seq_CurrentMessageID;
          }
          else
#endif
          {
            /*----------------------------------------------------------------------*/
            /* Send the new msg in the category for display.                        */
            /* If display indication timer is running then new msg flag will be set.*/
            /*----------------------------------------------------------------------*/
            MessageID = fl_newMessageInCategory;
          }
        }
        /* After displaying all the new msg for T2 in high priority category */
        /* display the low priority msg that can override high priority msg */
        else if (MSG_INDEX_UNDEFINED != lowCategoryMessageID)
        {
          MessageID = lowCategoryMessageID;
        }
#endif
        else
        {
          /* do nothing */
        }
      }
#ifdef MSG_OLD_WRNG_REPETITION
      /* Coverity Warning fix for Honda Thaa */
      if((MSG_INDEX_UNDEFINED != MessageID) && (MessageID < MSG_NUM_MESSAGES))
      {
        pMessage = &messageList[MessageID];
        currentMessageOptions = pMessage->Options;
      }
      else
      {
        currentMessageOptions = 0UL;
      }
#endif    

    }

#ifdef ALTERNATELY_SHOW_MSG_FRM_CATEGORY
    count = seq_GetViewCount(CATEGORYMASK_TO_BE_SHOWN_ALTERNATELY,inst);
    if(count > (UINT16)0)
    {
      MessageID = seq_GetMsgToBeShownAlternately(MessageID, dispIndTimerStatus,inst);
    }
    else
    {
      /* Do nothing */
    }
#endif

    /*----------------------------------------------------------------------*/
    /* Is message retrigger requested for the current message ID            */
    /*----------------------------------------------------------------------*/
    if ((MSG_INDEX_UNDEFINED != l_msg_instance_array[inst].seq_RetriggerMessageID) &&
      (MessageID == l_msg_instance_array[inst].seq_RetriggerMessageID))
    {
      /*------------------------------------------------------------------*/
      /* Retrigger is requested for the highest message ID in Seq_Q       */
      /* Set current mes ID as undefined, So that the retrigger msg ID is */
      /* treated as new message ID to activate the message                */
      /*------------------------------------------------------------------*/
      l_msg_instance_array[inst].seq_CurrentMessageID = MSG_INDEX_UNDEFINED;
    }

    /*----------------------------------------------------------------------*/
    /* Retrigger request is processed for the current sequencer update cycle*/
    /*----------------------------------------------------------------------*/
    l_msg_instance_array[inst].seq_RetriggerMessageID = MSG_INDEX_UNDEFINED;

    /*----------------------------------------------------------------------*/
    /* Is Forced Active requested for the current message ID                */
    /*----------------------------------------------------------------------*/
    if ((MSG_INDEX_UNDEFINED != l_msg_instance_array[inst].seq_ForcedActiveMessageID) &&
      (MessageID == l_msg_instance_array[inst].seq_ForcedActiveMessageID))
    {
      /*------------------------------------------------------------------*/
      /* Forced Active is requested for the highest message ID in Seq_Q   */
      /* Set current mes ID as undefined, So that the Forced  msg ID is   */
      /* treated as new message ID to activate the message                */
      /*------------------------------------------------------------------*/
      l_msg_instance_array[inst].seq_CurrentMessageID = MSG_INDEX_UNDEFINED;
    }

    /*----------------------------------------------------------------------*/
    /* Forced Active request is processed for the current sequencer update cycle*/
    /*----------------------------------------------------------------------*/
    l_msg_instance_array[inst].seq_ForcedActiveMessageID = MSG_INDEX_UNDEFINED;

    /*----------------------------------------------------------------------*/
    /* Show or hide message                                                 */
    /*----------------------------------------------------------------------*/
    if ((MessageID != l_msg_instance_array[inst].seq_CurrentMessageID)
#ifdef MSG_OLD_WRNG_REPETITION
      || ((MSG_INDEX_UNDEFINED != MessageID) &&
      (TESTBIT(currentMessageOptions, (UINT32)(MSG_OPTION_OLD_WRNG_REPEAT)) &&
      (0U == seq_Old_Wrng_RepDuration[MessageID])))
      /*----------------------------------------------------------------------------*/
      /* When the old warning repeat duration expires for the  seq_CurrentMessageID */
      /* then there will be no change in seq_CurrentMessageID but the timers need   */
      /* need to be restarted                                                       */
      /*----------------------------------------------------------------------------*/
#endif
      )
    {
      /*------------------------------------------------------------------*/
      /* Change in message detected.                                      */
      /*------------------------------------------------------------------*/
      MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_DisplayTimer);
      /* T2 timer of current message need to be stopped */
      MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_DispIndTimer);
      MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_AckAftMinToutTimer);
#ifdef DISP_TOUT_NO_TOUT_MSG_BY_PRIORITY
      MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_CycleTimer);
#endif

      if (MSG_INDEX_UNDEFINED != MessageID)
      {
        MSG_VIEWINFO_T fl_alertInfo;
        if((MSG_INDEX_UNDEFINED != l_msg_instance_array[inst].seq_CurrentMessageID)  && (l_msg_instance_array[inst].seq_CurrentMessageID < MSG_NUM_MESSAGES))
        {
          /*--------------------------------------------------------------*/
          /* Get the category of the seq_CurrentMessageID */
          /*--------------------------------------------------------------*/
          currentMessage = &messageList[l_msg_instance_array[inst].seq_CurrentMessageID];
          category = currentMessage->Category;
          /*--------------------------------------------------------------*/
          /* If the seq_CurrentMessageID is currently active in msg queue */
          /*--------------------------------------------------------------*/
          if (l_msg_instance_array[inst].seq_CurrentMessageID == seq_FindActiveMessage(category, l_msg_instance_array[inst].seq_CurrentMessageID, inst))
          {
#ifdef MSG_NO_REDISPLAY_AFTER_INTERRUPTION		
            if(TESTBIT(currentMessage->Options,(UINT32)MSG_OPTION_STASH_LOW))
            {
              (void)msg_SequencerRemove(l_msg_instance_array[inst].seq_CurrentMessageID,Ignition);
              seq_Callback(l_msg_instance_array[inst].seq_CurrentMessageID, MSG_EVENT_INACTIVE);
            }
            else
            {
               if((TESTBIT(currentMessage->Options,(UINT32)MSG_OPTION_FORCE_OLD))
                #ifdef MSG_RETAIN_NEW_MSG_DURING_HOLD
                && (TIMER_RUNNING != holdTimerStatus)
                #endif
                )
                {
                  seq_Callback(l_msg_instance_array[inst].seq_CurrentMessageID, MSG_EVENT_OLD);
                  CLR_SEMAPHORE(seq_NewMessageFlags, l_msg_instance_array[inst].seq_CurrentMessageID);
                  MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_DispIndTimer);
                }
                else 
                {
                  seq_Callback(l_msg_instance_array[inst].seq_CurrentMessageID, MSG_EVENT_HIDDEN);
                }           
            }
#else
            seq_Callback(l_msg_instance_array[inst].seq_CurrentMessageID, MSG_EVENT_HIDDEN);
#endif 
          }
          else
          {
            seq_Callback(l_msg_instance_array[inst].seq_CurrentMessageID, MSG_EVENT_INACTIVE);
          }
        }

#ifdef ALTERNATELY_SHOW_MSG_FRM_CATEGORY
        l_msg_instance_array[inst].seq_PrevMessageID = l_msg_instance_array[inst].seq_CurrentMessageID;
#endif
        /*--------------------------------------------------------------*/
        /* Message has just become ACTIVE.                              */
        /*--------------------------------------------------------------*/
        l_msg_instance_array[inst].seq_CurrentMessageID = MessageID;
        seq_Callback(l_msg_instance_array[inst].seq_CurrentMessageID, MSG_EVENT_ACTIVE);
        fl_alertInfo.Id = l_msg_instance_array[inst].seq_CurrentMessageID;
        fl_alertInfo.Count = SEQ_LAST_INDEX(inst);
        fl_alertInfo.Position = 0;
        fl_alertInfo.Status = 0;
        fl_alertInfo.InstanceID = inst;
        if (l_msg_instance_array[inst].seq_CurrentMessageID < MSG_NUM_MESSAGES)
        {
#ifdef DISP_TOUT_NO_TOUT_MSG_BY_PRIORITY
          /*--------------------------------------------------------------*/
          /* When there is a change in the seq_CurrentMessageID update    */
          /* CurrentlyDisplayingNewMsgFlag with the new msg flag status   */
          /*--------------------------------------------------------------*/
          l_msg_instance_array[inst].CurrentlyDisplayingNewMsgFlag = (GET_SEMAPHORE(seq_NewMessageFlags,l_msg_instance_array[inst].seq_CurrentMessageID)) ? TRUE : FALSE;
#endif
          /*--------------------------------------------------------------*/
          /* Set the Recycle bit based on recycle flags condition         */
          /*--------------------------------------------------------------*/
          if (FALSE != (BOOLEAN)GET_SEMAPHORE(seq_MsgRecycleFlags, l_msg_instance_array[inst].seq_CurrentMessageID))
          {
            SETBIT(fl_alertInfo.Status, (UINT8)MSG_RECYCLE);
          }

          /*--------------------------------------------------------------*/
          /* Set the newmessgae flag  bit based on newmsessage flags condition         */
          /*--------------------------------------------------------------*/
        if (FALSE != (BOOLEAN)GET_SEMAPHORE(seq_NewMessageFlags, l_msg_instance_array[inst].seq_CurrentMessageID))
          {
            SETBIT(fl_alertInfo.Status, (UINT8)MSG_NEW);
          }
          /*--------------------------------------------------------------*/
          /* Set the MSG_DISPLAYED_ONCE flag  bit based on Display once
          ** flags condition, i.e when this msg lost focus by other high
          ** priority warning and gain the focus after removing high priorty
          ** warning this flag gives an information that it was previously
          ** displayed once and application can take appropriate actions  */
          /*--------------------------------------------------------------*/
        if (FALSE != (BOOLEAN)GET_SEMAPHORE(seq_DisplayedOnceFlags, l_msg_instance_array[inst].seq_CurrentMessageID))
          {
            SETBIT(fl_alertInfo.Status, (UINT8)MSG_DISPLAYED_ONCE);
          }
        }

#ifdef MSG_CYCLE_OPTION_WITH_TIMEOUT
        MSG_START_SW_TIMER(HMI_MSG_1SEC_TIME, hmi_msg_inst_config_table[inst].seq_1secTimer);
#endif

#ifdef WARN_MSG_ENABLE_NEW_MESSAGE_SEQ_QUEUE_TIMEOUT
        /*--------------------------------------------------------------*/
        /* Message is just start displaying, so load Invalid count, so  */
        /* that it won't be removed from from Seq by NewMsgQ Timeout    */
        /*--------------------------------------------------------------*/
        if(MessageID <= MSG_NUM_MESSAGES)
        {
          Seq_NewMsgQTimeout_U8[MessageID] = HMI_MSG_SEQ_TIMEOUT_INVALID_U8;
        }
#endif

        MSG_DISPLAY_SHOW(&fl_alertInfo);
      }
      else
      {
        /*--------------------------------------------------------------*/
        /* Message has just become INACTIVE.                            */
        /*--------------------------------------------------------------*/
        /* Coverity warning 11219 fix for Honda Thaa */
        if (MSG_INDEX_UNDEFINED != l_msg_instance_array[inst].seq_CurrentMessageID)
        {
          seq_Callback(l_msg_instance_array[inst].seq_CurrentMessageID, MSG_EVENT_INACTIVE);
          MSG_DISPLAY_HIDE(l_msg_instance_array[inst].seq_CurrentMessageID);
        }
        l_msg_instance_array[inst].seq_CurrentMessageID = MSG_INDEX_UNDEFINED;
#ifdef DISP_TOUT_NO_TOUT_MSG_BY_PRIORITY
        /*--------------------------------------------------------------*/
        /* When there is a change in the seq_CurrentMessageID to        */
        /* MSG_INDEX_UNDEFINED then clear CurrentlyDisplayingNewMsgFlag */
        /*--------------------------------------------------------------*/
        l_msg_instance_array[inst].CurrentlyDisplayingNewMsgFlag = FALSE;
#endif
      }
    }
  }
}

#ifdef ALTERNATELY_SHOW_MSG_FRM_CATEGORY
static eMessageIdentity seq_GetMsgToBeShownAlternately(eMessageIdentity l_MessageID, UINT8 l_dispIndTimerStatus,UINT8 inst)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Get message to be shown alternately. If 
**                  ALTERNATELY_SHOW_MSG_FRM_CATEGORY_ENABLED is TRUE then
**                  msg from CATEGORY_TO_BE_SHOWN_ALTERNATELY need to displayed
**                  always in between the active messages i.e twice for once.
**
**  Parameters:     dispIndTimerStatus:   Display indication timer status.
**
**  Returns:        ID of message.
**----------------------------------------------------------------------------
** Created: ADEVI 05/06/2014
**==========================================================================*/
{
  eMessageIdentity retMessageID = l_MessageID;
  eMessageIdentity msgToBeShownAlternately;
  UINT32 indexOfMsgToBeShownAlternately;
  BOOLEAN MsgNewStatus;
  UINT8 l_cycleTimerStatus;
  const MSG_MESSAGE_STRUCT *l_MessageStruct;

  l_MessageStruct = &messageList[retMessageID];
  inst = l_MessageStruct->InstanceID;
  if(inst < MSG_NUM_INSTANCES)
  {
    indexOfMsgToBeShownAlternately = seq_FindFirstIndex(CATEGORYMASK_TO_BE_SHOWN_ALTERNATELY,inst);
    msgToBeShownAlternately = l_msg_instance_array[inst].seq_MessageList[indexOfMsgToBeShownAlternately];
    /* If the MessageID finalised by msg_SequencerUpdate is same as msgToBeShownAlternately */
    /* then it need not be changed.  If DisplayTimeout is configured then high priority     */
    /* msg is on display so MessageID need not be changed.                                  */
    if ((retMessageID == msgToBeShownAlternately) || (l_MessageStruct->DisplayTimeout != NO_TIMEOUT))
    {
      /* Do nothing */
    }
    else
    {
      MsgNewStatus = (GET_SEMAPHORE(seq_NewMessageFlags, msgToBeShownAlternately))?TRUE:FALSE;
      l_cycleTimerStatus = MSG_CHECK_SW_TIMER(hmi_msg_inst_config_table[inst].seq_CycleTimer);
      /* seq_NewMessageFlags of msgToBeShownAlternately is set as 1 */
      if(FALSE != MsgNewStatus)
      {
        /* If the display indication timer is not running then high priority msg has      */
        /* completed its display indication time so msgToBeShownAlternately can be        */
        /* brought to display.  When msgToBeShownAlternately is on display                */
        /* seq_CurrentMessageID will be msgToBeShownAlternately.  When display indication */
        /* time of msgToBeShownAlternately gets over seq_NewMessageFlags will be FALSE.   */
        if ((l_dispIndTimerStatus != TIMER_RUNNING) ||
          (l_msg_instance_array[inst].seq_CurrentMessageID == msgToBeShownAlternately))
        {
          retMessageID = msgToBeShownAlternately;
        }
        else
        {
          /* Do nothing */
        }
      }
      /* seq_NewMessageFlags of msgToBeShownAlternately is not set */
      else
      {
        /* If cycle timer and display indication timer is not running then it means the high           */
        /* priority message has finished its display.  If msgToBeShownAlternately is not the           */
        /* seq_CurrentMessageID then it should be brought to display now. When msgToBeShownAlternately */
        /* has got the display and if cycle timer is running then msgToBeShownAlternately should       */
        /* hold the display */
        if (((l_cycleTimerStatus != TIMER_RUNNING) && (l_dispIndTimerStatus != TIMER_RUNNING) &&
          (l_msg_instance_array[inst].seq_CurrentMessageID != msgToBeShownAlternately)) ||
          ((l_msg_instance_array[inst].seq_CurrentMessageID == msgToBeShownAlternately) && (l_cycleTimerStatus == TIMER_RUNNING)))
        {
          retMessageID = msgToBeShownAlternately;
          if(retMessageID < MSG_NUM_MESSAGES)
          {
            SET_SEMAPHORE(seq_MsgRecycleFlags, retMessageID);
          }
        }
        else
        {
          /* Do nothing */
        }
      }
    }
  }
  return retMessageID;
}
#endif

#ifdef ALLOW_UNDISPLAYED_MSG_IMMEDIATELY 
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Set DisplayedOnce flags for the lower category messages.
**                  The search begins with the category next to the input given.
**                  All the high priority messages in all the lower categories
**                  are found and the seq_DisplayedOnceFlags is set.
**
**  Parameters:     Category:   Category from where search starts.
**
**  Returns:        None.
**==========================================================================*/
static void seq_SetLowerCategoryMsgDispOnce(eMessageCategory p_Category,UINT8 inst)
{
  if(inst < MSG_NUM_INSTANCES)
  {
    eMessageIdentity fl_newMessageInCategory;
    p_Category++;
    while(p_Category < (UINT32)MSG_NUM_MESSAGE_CATEGORIES)
    {
      fl_newMessageInCategory = seq_GetHighPrioNewMessage((eMessageCategory)(p_Category),inst);
      if(MSG_INDEX_UNDEFINED != fl_newMessageInCategory)
      {
        SET_SEMAPHORE(seq_DisplayedOnceFlags, fl_newMessageInCategory);
      }
      p_Category++;
    }
  }
}
#endif

static eMessageIdentity seq_GetLowerCategoryMessage(eMessageCategory Category,UINT8 inst)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Get New message to be displayed from the lower category.
**
**  Parameters:     Category:   Category from where search starts.
**
**  Returns:        ID of message.
**----------------------------------------------------------------------------
** Created: AFERRIS2 27/04/2011
**==========================================================================*/
{
  UINT32 i;
  UINT32 thisIndex;
  eMessageIdentity retMessage = MSG_INDEX_UNDEFINED;
  eMessageIdentity aMessage;
  eMessageIdentity fl_newMessageInCategory;
  MSG_MESSAGE_STRUCT const *ptrMessage;

  if(inst < MSG_NUM_INSTANCES)
  {
    for (i=(UINT32)(Category) + 1UL; i < (UINT32)MSG_NUM_MESSAGE_CATEGORIES; i++)
    {
      thisIndex = l_msg_instance_array[inst].seq_Categories[i];
      if (thisIndex <= hmi_msg_inst_config_count[inst])
      {
        aMessage = l_msg_instance_array[inst].seq_MessageList[thisIndex];
        if (aMessage < MSG_NUM_MESSAGES)
        {
          ptrMessage = &messageList[aMessage];
#ifdef ALLOW_UNDISPLAYED_MSG_IMMEDIATELY
          fl_newMessageInCategory = seq_GetHighPrioNewMessage((eMessageCategory)(i),inst);
#else
          fl_newMessageInCategory = seq_GetNewMessage((eMessageCategory)(i),inst);
#endif 
          /* Check if the low priority msg can override the high priority msg */
          /* And the low priority msg is new to be displayed                  */
          if(TESTBIT((ptrMessage->Options), ((UINT32)MSG_OPTION_OVERRIDE_HIGH)))
          {
            if(MSG_INDEX_UNDEFINED != fl_newMessageInCategory)
            {
              retMessage = fl_newMessageInCategory;
#ifdef ALLOW_UNDISPLAYED_MSG_IMMEDIATELY
              seq_SetLowerCategoryMsgDispOnce((eMessageCategory)(i),inst);
#endif
              break;
            }
          }
        }
      }
    }
  }
  return retMessage;
}

void msg_SequencerAdd(eMessageIdentity MessageID)
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Adds a new message into the sequencer.  Action is dependant
**                  on the message options.  If MSG_OPTION_SEQUENCE is set, the
**                  message is added to the sequencer, otherwise the message is
**                  transferred directly to the sequencer client.
**
**  Parameters:     MessageID:  ID of the message to be added.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 12/Apr/2010
**==========================================================================*/
{
  MSG_MESSAGE_STRUCT const * thisMessage;
  UINT32 thisIndex;
#ifdef ALTERNATELY_SHOW_MSG_FRM_CATEGORY
  UINT16 seq_msg_Count;
#endif
  /* When MSG_CYCLE_OPTION_ALL_CATEGORY is enabled cycle timer needs to be */
  /* cleared for every addition of a new message                           */
  UINT8 inst = 0u;

  if (MessageID < MSG_NUM_MESSAGES)
  { 
    thisMessage = &messageList[MessageID];
    inst = thisMessage->InstanceID;
    if(inst < MSG_NUM_INSTANCES)
    {
#ifndef MSG_CYCLE_OPTION_ALL_CATEGORY
      eMessageCategory curMsgCategory;
      if(l_msg_instance_array[inst].seq_CurrentMessageID != MSG_INDEX_UNDEFINED)
      {
        MSG_MESSAGE_STRUCT const * curMessage;
        curMessage = &messageList[l_msg_instance_array[inst].seq_CurrentMessageID];
        curMsgCategory = curMessage->Category;
      }
      else
      {
        curMsgCategory = mcMaximum;
      }
#endif


      if (TESTBIT(thisMessage->Options, (UINT32)MSG_OPTION_SEQUENCE) )
      {
        /*------------------------------------------------------------------*/
        /* Remove this message from here and the client (message could be   */
        /* active if being re-triggered or previously had timed-out or been */
        /* acknowledged)                                                    */
        /*------------------------------------------------------------------*/
        (void)seq_RemoveMessage(MessageID);
        (void)MSG_SEQUENCER_CLIENT_REMOVE(MessageID);

        /*------------------------------------------------------------------*/
        /* If this message is being HELD, then clear the HOLD message ID so */
        /* that it will not get removed when the HOLD timer expires.        */
        /*------------------------------------------------------------------*/
        if (MessageID == l_msg_instance_array[inst].seq_HoldMessageID)
        {
          l_msg_instance_array[inst].seq_HoldMessageID = MSG_INDEX_UNDEFINED;
        }

        /*------------------------------------------------------------------*/
        /* Insert Message into sequencer list.                              */
        /*------------------------------------------------------------------*/
        thisIndex = seq_InsertMessage(thisMessage, MessageID);

#ifdef MSG_CYCLE_OPTION_WITH_TIMEOUT
        /*-----------------------------------------------------------------*/
        /* updating the counter array of cuurently active wraning with     */
        /* total display time out                                          */
        /*-----------------------------------------------------------------*/
        seq_DsplyTimeList[MessageID] = seq_MsgDisplayTime(MessageID);
#endif

#ifdef WARN_MSG_ENABLE_NEW_MESSAGE_SEQ_QUEUE_TIMEOUT
        if(TESTBIT(thisMessage->Options, (UINT32)MSG_OPTION_NEW_MSG_SEQ_Q_TIMEOUT))
        {
          /*--------------------------------------------------------------*/
          /* Load the New Msg Seq Q Timeout value from the message def    */
          /* structure.                                                   */
          /*--------------------------------------------------------------*/
          UINT16 fl_Seq_NewMsgQTimeout_U16;
          fl_Seq_NewMsgQTimeout_U16 = thisMessage->SeqQTimeout * HMI_MSG_SEQ_TIMER_RESLN_FACTOR;
          if(fl_Seq_NewMsgQTimeout_U16 < HMI_MSG_SEQ_TIMEOUT_INVALID_U8)
          {
            Seq_NewMsgQTimeout_U8[MessageID] = (UINT8)(fl_Seq_NewMsgQTimeout_U16);
          }
          else
          {
            Seq_NewMsgQTimeout_U8[MessageID] = HMI_MSG_SEQ_TIMEOUT_INVALID_U8;
          }
        }
#endif

#ifdef MSG_OLD_WRNG_REPETITION
        if(TESTBIT(thisMessage->Options,(UINT32)MSG_OPTION_OLD_WRNG_REPEAT))
        {
          /*--------------------------------------------------------------*/
          /* Load invalid value in old warning repetition duration array  */
          /*--------------------------------------------------------------*/
          seq_Old_Wrng_RepDuration[MessageID] = HMI_MSG_OLD_WRNG_REP_INVALID_U16;
        }
#endif

        SET_SEMAPHORE(seq_NewMessageFlags, MessageID);
        /* This message is not yet displayed, hence clear the flag seq_DisplayedOnceFlags */
        CLR_SEMAPHORE(seq_DisplayedOnceFlags, MessageID);

#ifdef ALTERNATELY_SHOW_MSG_FRM_CATEGORY    
        /* When the msg to be alternately shown is active then if cycle timer */
        /* gets cleared for every new addition of msg in sequencer then the   */
        /* msg alternately shown will lose the display since cycle timer gets */
        /* stopped.  So cycle timer not cleared in this case alone.           */
        seq_msg_Count = seq_GetViewCount(CATEGORYMASK_TO_BE_SHOWN_ALTERNATELY,inst);
#endif
        if (TESTBIT(thisMessage->Options, (UINT32)MSG_OPTION_CYCLE)
#ifdef ALTERNATELY_SHOW_MSG_FRM_CATEGORY
          && (0U == seq_msg_Count)
#endif
#ifdef MSG_ACK_WRNG_REPETITION
          && (l_MsgAddedFromStoreQueue[inst] == (BOOLEAN)MSG_NOT_ADDED_FROM_STORE_QUEUE)
#endif
#ifndef MSG_CYCLE_OPTION_ALL_CATEGORY
          /* Cycle timer is cleared only when the high priority category msg is added */
          /* or when same category message is added                                   */
          && (curMsgCategory >= thisMessage->Category)
#endif
          )
        {
          MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_CycleTimer);

#ifdef MSG_CYCLE_OPTION_WITH_TIMEOUT
          /* clearing the one sec timer*/
          MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_1secTimer);
#endif
        }

        /*------------------------------------------------------------------*/
        /* Invalidate view message index if this message has a higher       */
        /* priority.                                                        */
        /*------------------------------------------------------------------*/
        if (thisIndex <= l_msg_instance_array[inst].seq_ViewMessage.Position)
        {
          UINT32 index;

          index = seq_FindFirstIndex(seq_ViewMask,inst);
          if (index <= hmi_msg_inst_config_count[inst])
          {
            seq_SetViewMessage(l_msg_instance_array[inst].seq_MessageList[index],inst);
            MSG_SEQUENCER_NOTIFY_VIEWER();
          }
        }
      }
      else
      {
        /*------------------------------------------------------------------*/
        /* Message is not sequenced.  Transfer to client.                   */
        /*------------------------------------------------------------------*/
        MSG_SEQUENCER_CLIENT_ADD(MessageID);
      }
    }

    /*----------------------------------------------------------------------*/
    /* Indicate the Message is not recycling                                */
    /*----------------------------------------------------------------------*/
    CLR_SEMAPHORE(seq_MsgRecycleFlags, MessageID); /* ### QAC WARNING:4130 ### */
  }
}

UINT8 msg_SequencerRemove(eMessageIdentity MessageID, UINT8 Ignition)
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Remove a message from the sequencer based on Options and
**                  current Ignition mode set for that message
**
**  Parameters:     MessageID:  ID of the message to be removed.
**                  Ignition :  Current Ignition state
**
**  Returns:        1 = Message is removed.
**                  0 = Message not removed.
**----------------------------------------------------------------------------
** Created: AFERRIS2 12/Apr/2010
**==========================================================================*/
{
  const MSG_MESSAGE_STRUCT *pMessage;
  UINT8 holdStatus;
  UINT8 msgRemoveStatus;
  BOOLEAN found;      
  UINT8 inst = 0u;

  msgRemoveStatus = 0;

  if (MessageID < MSG_NUM_MESSAGES)
  {
    pMessage = &messageList[MessageID];
    inst = pMessage->InstanceID;
    if(inst < MSG_NUM_INSTANCES)
    {
      /*-----------------------------------------------------------------------*/
      /* If MSG_OPTION_ALLOW_INACTIVE_TO_TIMEOUT is enabled then do not remove */
      /* the deactivated message from the message queue in configured powermode*/
      /*-----------------------------------------------------------------------*/
      if( (TESTBIT(pMessage->Options,(UINT32)MSG_OPTION_ALLOW_INACTIVE_TO_TIMEOUT)) && \
        (TESTBIT(Ignition, pMessage->ActiveStates)) )
      {
        /*-------------------------------------------------------------------*/
        /* Is the requested MessageID is currently active in msg queue       */
        /*-------------------------------------------------------------------*/
        if(MessageID == seq_FindActiveMessage(pMessage->Category, MessageID, inst))
        {
          /*--------------------------------------------------------------*/
          /* Message is active. So, send msg remove status as 0           */
          /*--------------------------------------------------------------*/
        }
        else
        {
          /*--------------------------------------------------------------*/
          /* Message is removed from Seq msg Q.Indicate this to Arbitrator*/
          /* to update the flags. So, that, next time this message can be */
          /* added to Seq msg Q if newly triggered.                       */
          /*--------------------------------------------------------------*/
          msgRemoveStatus = 1U;
        }
      }
      else if((TESTBIT(pMessage->Options,(UINT32)MSG_OPTION_REM_FRM_SEQ_IN_NA_IGN_MODE)) &&
        (!TESTBIT(Ignition, pMessage->ActiveStates)))
      {
        /*-------------------------------------------------------------------*/
        /* Is the requested MessageID is currently active in msg queue       */
        /*-------------------------------------------------------------------*/
        found = seq_RemoveMessage(MessageID);

        if (FALSE != found)	
        {
          msgRemoveStatus = 1U;
        }
      }
      else
      {
        /*------------------------------------------------------------------*/
        /* Special action if this message is being displayed and the        */
        /* display hold timer is still running.                             */
        /*------------------------------------------------------------------*/
        holdStatus = MSG_CHECK_SW_TIMER(hmi_msg_inst_config_table[inst].seq_HoldTimer);

        if((MessageID == l_msg_instance_array[inst].seq_CurrentMessageID) && (TESTBIT(pMessage->Options, (UINT32)MSG_OPTION_DISP_INDICATIONTIME))
#ifdef MSG_RETAIN_NEW_MSG_DURING_HOLD
          && (TIMER_RUNNING != holdStatus)
#endif
          )
        {
          CLR_SEMAPHORE(seq_NewMessageFlags, l_msg_instance_array[inst].seq_CurrentMessageID);
          MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_DispIndTimer);
        }

        if ((MessageID == l_msg_instance_array[inst].seq_CurrentMessageID) && (TIMER_RUNNING == holdStatus))
        {
          /*--------------------------------------------------------------*/
          /* Save message ID so that we can remove the message when the   */
          /* hold timer expires.                                          */
          /*--------------------------------------------------------------*/
          l_msg_instance_array[inst].seq_HoldMessageID = MessageID;
        }
        else
        {
          UINT32 msgIndex = seq_GetViewIndex(MessageID, MSG_ALL_CATEGORIES,inst);
          found = seq_RemoveMessage(MessageID);

          if (FALSE != found)
          {
            seq_UpdateViewer(MessageID, msgIndex,inst);
          }
          else
          {
            /*--------------------------------------------------------------*/
            /* Remove from client if not found here.                        */
            /*--------------------------------------------------------------*/
            (void)MSG_SEQUENCER_CLIENT_REMOVE(MessageID);
          }
        }
        msgRemoveStatus = 1U;
      }
    }
  }
  return(msgRemoveStatus);
}

#if MSG_NUM_INSTANCES > 1
void msg_SequencerShow(UINT8 p_inst)
#else 
void msg_SequencerShow(void)
#endif
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Called by client to indicate that the message is being
**                  displayed. If the message has a defined timeout then the
**                  sequencer timer is started with the message timeout.  If no
**                  timeout is defined we force the timer to be cleared so that
**                  only the user can remove the message display.
**
**  Parameters:     None.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 12/Apr/2010
**==========================================================================*/
{
  const MSG_MESSAGE_STRUCT *pMessage;

#if (MSG_NUM_INSTANCES > 1)
  UINT8 inst = p_inst;
  if(inst < MSG_NUM_INSTANCES)
#else 
  UINT8 inst = 0u;
#endif
  {
    if ((MSG_INDEX_UNDEFINED != l_msg_instance_array[inst].seq_CurrentMessageID) && (l_msg_instance_array[inst].seq_CurrentMessageID < MSG_NUM_MESSAGES))
    {

      UINT16 fl_HoldTimeout;

      seq_Callback(l_msg_instance_array[inst].seq_CurrentMessageID, MSG_EVENT_SHOW);

      pMessage = &messageList[l_msg_instance_array[inst].seq_CurrentMessageID];

#ifdef MSG_GET_DYN_HOLD_TIME
      fl_HoldTimeout = pMessage->HoldTimeout(l_msg_instance_array[inst].seq_CurrentMessageID);
#else
      fl_HoldTimeout = pMessage->HoldTimeout;
#endif
      /*------------------------------------------------------------------*/
      /* Start the Hold timer whenever the message comes to display. The  */
      /* minimum hold time shall be maintained irrespective of first      */
      /* appearance or reappearance of warning                            */
      /*------------------------------------------------------------------*/
      if (GET_SEMAPHORE(seq_NewMessageFlags, l_msg_instance_array[inst].seq_CurrentMessageID))
      {
        /*------------------------------------------------------------------*/
        /* Get timeout for this message.  If a valid time then we start     */
        /* the timer otherwise the timer is cleared.                        */
        /*------------------------------------------------------------------*/
        if ((UINT16)MSG_NO_TIMEOUT != fl_HoldTimeout)
        {
          MSG_START_SW_TIMER(fl_HoldTimeout, hmi_msg_inst_config_table[inst].seq_HoldTimer);
        }
        else
        {
          MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_HoldTimer);
        }
      }

      if ((GET_SEMAPHORE(seq_NewMessageFlags, l_msg_instance_array[inst].seq_CurrentMessageID)) &&
          (TESTBIT(pMessage->Options, (UINT32)MSG_OPTION_DISP_INDICATIONTIME)))
      {
#ifdef HMI_MSG_UNIQUE_DISP_IND_TIME
        /*------------------------------------------------------------------*/
        /* Get timeout for this message.  If a valid time then we start     */
        /* the timer otherwise the timer is cleared.                        */
        /*------------------------------------------------------------------*/
        if ((UINT16)MSG_NO_TIMEOUT != pMessage->DispIndTimeout)
        {
          MSG_START_SW_TIMER(pMessage->DispIndTimeout, hmi_msg_inst_config_table[inst].seq_DispIndTimer);
        }
        else
        {
          MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_DispIndTimer);
        }
#else
        MSG_START_SW_TIMER(HMI_MSG_DISP_IND_TIME, hmi_msg_inst_config_table[inst].seq_DispIndTimer);
#endif

#ifdef MSG_OLD_WRNG_REPETITION
        if (TESTBIT(pMessage->Options, (UINT32)MSG_OPTION_OLD_WRNG_REPEAT))
        {
          /*--------------------------------------------------------------*/
          /* Load invalid value in old warning repetition duration array  */
          /*--------------------------------------------------------------*/
          seq_Old_Wrng_RepDuration[l_msg_instance_array[inst].seq_CurrentMessageID] = HMI_MSG_OLD_WRNG_REP_INVALID_U16;
        }
#endif
      }
      /*------------------------------------------------------------------*/
      /* Remove hold message may clear Cycle Timer if any valid Hold msg  */
      /* is present. So start Cycle Timer after removal of hold message   */
      /*------------------------------------------------------------------*/
      seq_RemoveHoldMessage(inst);

      if (TESTBIT(pMessage->Options, (UINT32)MSG_OPTION_CYCLE))
      {
        MSG_START_SW_TIMER(HMI_MSG_CYCLE_TIME, hmi_msg_inst_config_table[inst].seq_CycleTimer);
      }

      /*------------------------------------------------------------------*/
      /* Start AckAftMin timer - Do not allow any button presses to       */
      /* acknowledge the warning until minimum timeout is expired after   */
      /* the warning start to display                                     */
      /*------------------------------------------------------------------*/
      if (TESTBIT(pMessage->Options, (UINT32)MSG_OPTION_CLEARABLE))
      {
        if ((TESTBIT(pMessage->Options, (UINT32)MSG_OPTION_ACK_AFT_MIN_TOUT)) &&
             (GET_SEMAPHORE(seq_NewMessageFlags, l_msg_instance_array[inst].seq_CurrentMessageID)))
        {
          MSG_START_SW_TIMER(HMI_MSG_ACK_AFT_MIN_TIME, hmi_msg_inst_config_table[inst].seq_AckAftMinToutTimer);
        }
      }

#ifdef MSG_CYCLE_OPTION_WITH_TIMEOUT
      /*------------------------------------------------------------------*/
      /* Start 1sec timer                                                 */
      /*------------------------------------------------------------------*/
      MSG_START_SW_TIMER(HMI_MSG_1SEC_TIME, hmi_msg_inst_config_table[inst].seq_1secTimer);
#endif

      /*------------------------------------------------------------------*/
      /* Get timeout for this message.  If a valid time then we start     */
      /* the timer otherwise the timer is cleared.                        */
      /*------------------------------------------------------------------*/
      if ((UINT16)MSG_NO_TIMEOUT != pMessage->DisplayTimeout)
      {
        MSG_START_SW_TIMER(pMessage->DisplayTimeout, hmi_msg_inst_config_table[inst].seq_DisplayTimer);
      }
      else
      {
        MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_DisplayTimer);
      }
      /* This flag gives an information that it was previously
      ** displayed once and application can take appropriate actions  */
      SET_SEMAPHORE(seq_DisplayedOnceFlags, l_msg_instance_array[inst].seq_CurrentMessageID);
    }
  }
}
#if MSG_NUM_INSTANCES > 1
void msg_SequencerHide(UINT8 p_inst)
#else 
void msg_SequencerHide(void)
#endif
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Called by display client to indicate that the message is no
**                  longer being displayed.
**
**  Parameters:     None.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 12/Apr/2010
**==========================================================================*/
{

#if (MSG_NUM_INSTANCES > 1)
  UINT8 inst = p_inst;
  if(inst < MSG_NUM_INSTANCES)
#else 
  UINT8 inst = 0u;
#endif
  {
    if (MSG_INDEX_UNDEFINED != l_msg_instance_array[inst].seq_CurrentMessageID)
    {
      MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_DisplayTimer);
    }
  }
}

#if (MSG_NUM_INSTANCES > 1)
UINT8 msg_SequencerAction(UINT16 Button, UINT8 p_inst)
#else
UINT8 msg_SequencerAction(UINT16 Button)
#endif
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Request to cancel the current message.
**
**  Parameters:     Button: Button ID and status
**
**  Returns:        One of the following:
**                  MSG_BTN_NONE        Button event to consumed.
**                  MSG_BTN_NOACTION    Button event consumed but no action taken
**                  MSG_BTN_CHANGED     Message changed
**----------------------------------------------------------------------------
** Created: AFERRIS2 14/Apr/2010
**==========================================================================*/
{

  UINT8 retValue = MSG_BTN_NONE;

#if (MSG_NUM_INSTANCES > 1)
  UINT8 inst = p_inst;
  if(inst < MSG_NUM_INSTANCES)
#else 
  UINT8 inst = 0u;
#endif
  {
    MSG_MESSAGE_STRUCT const * thisMessage;
    BOOLEAN isDeactivated;
    BOOLEAN isButtonChanged = FALSE;
    UINT8 ackAftMinToutTimerStatus;
    UINT32 i;
    if ((MSG_ACKNOWLEDGE_ALL_BUTTON_EVENT == Button) && (MSG_INDEX_UNDEFINED != l_msg_instance_array[inst].seq_CurrentMessageID))
    {    
      /*------------------------------------------------------------------------------*/
      /* Only process if this is the right button event to acknowledge all warnings   */
      /*------------------------------------------------------------------------------*/

      for (i = SEQ_LAST_INDEX(inst); i != 0UL; i--)
      {
        eMessageIdentity MessageID = l_msg_instance_array[inst].seq_MessageList[i - 1UL];

        if(MSG_INDEX_UNDEFINED != MessageID)
        {
          thisMessage = &messageList[MessageID];
          /*--------------------------------------------------------------*/
          /* Check if current message supports button events.             */
          /*--------------------------------------------------------------*/
          if (TESTBIT(thisMessage->Options, (UINT32)MSG_OPTION_CLEARABLE))
          {
            retValue = (UINT8)MSG_BTN_NOACTION;
            /*----------------------------------------------------------*/
            /* Remove message but don't change the current message ID.  */
            /* This will be done by the main task when it next runs.    */
            /*----------------------------------------------------------*/
            isDeactivated = seq_RemoveMessage(MessageID);

            if (FALSE != isDeactivated)
            {
              seq_Callback(MessageID, MSG_EVENT_ACKNOWLEDGED);
              if(MSG_INDEX_UNDEFINED == l_msg_instance_array[inst].seq_HoldMessageID)
              {
                MSG_SEQUENCER_CLIENT_ADD(MessageID);
              }
              isButtonChanged = TRUE;
            }
            l_msg_instance_array[inst].seq_HoldMessageID = MSG_INDEX_UNDEFINED;

            if (MessageID == l_msg_instance_array[inst].seq_CurrentMessageID)
            {
              MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_HoldTimer);
            }

            if(TESTBIT(thisMessage->Options, (UINT32)MSG_OPTION_DISP_INDICATIONTIME))
            {
              CLR_SEMAPHORE(seq_NewMessageFlags, MessageID);
              if (MessageID == l_msg_instance_array[inst].seq_CurrentMessageID)
              {
                MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_DispIndTimer);
              }
            }
          }
        }
      }

      if (isButtonChanged == TRUE)
      {            
        retValue = (UINT8)MSG_BTN_CHANGED;
      }
    }      

    /*------------------------------------------------------------------*/
    /* Only process if this is the right button event and the button    */
    /* press has happened for the currently displayed msg.              */
    /*------------------------------------------------------------------*/
    else if (((MSG_ACKNOWLEDGE_BUTTON_EVENT == Button) ||  (MSG_ACKNOWLEDGE_CATEGORY_BUTTON_EVENT == Button)) &&
      (MSG_INDEX_UNDEFINED != l_msg_instance_array[inst].seq_CurrentMessageID) && (l_msg_instance_array[inst].seq_CurrentMessageID < MSG_NUM_MESSAGES))
    {
      thisMessage = &messageList[l_msg_instance_array[inst].seq_CurrentMessageID];

      /*--------------------------------------------------------------*/
      /* Check if current message supports button events.             */
      /*--------------------------------------------------------------*/
      if (TESTBIT(thisMessage->Options, (UINT32)MSG_OPTION_CLEARABLE))
      {
        ackAftMinToutTimerStatus = MSG_CHECK_SW_TIMER(hmi_msg_inst_config_table[inst].seq_AckAftMinToutTimer);
        /*---------------------------------------------------------------------*/
        /*  If MSG_OPTION_ACK_AFT_MIN_TOUT is set then msg can be acknowledged */
        /*  only when the seq_AckAftMinToutTimer had expired. If the timer has */
        /*  not expired then button press is ignored.                          */
        /*---------------------------------------------------------------------*/
        if((!TESTBIT(thisMessage->Options, (UINT32)MSG_OPTION_ACK_AFT_MIN_TOUT)) ||
          (TIMER_RUNNING != ackAftMinToutTimerStatus))
        {
          retValue = (UINT8)MSG_BTN_NOACTION;
          /*----------------------------------------------------------*/
          /* Remove message but don't change the current message ID.  */
          /* This will be done by the main task when it next runs.    */
          /*----------------------------------------------------------*/
          isDeactivated = seq_RemoveMessage(l_msg_instance_array[inst].seq_CurrentMessageID);
          if (FALSE != isDeactivated)
          {
            seq_Callback(l_msg_instance_array[inst].seq_CurrentMessageID, MSG_EVENT_ACKNOWLEDGED);
            if(MSG_INDEX_UNDEFINED == l_msg_instance_array[inst].seq_HoldMessageID)
            {
              MSG_SEQUENCER_CLIENT_ADD(l_msg_instance_array[inst].seq_CurrentMessageID);
            }
#ifdef MSG_ENABLE_GROUP_ACKNOWLEDGEMENT
            if(thisMessage->AckGroup != MSG_ACK_GROUP_UNDEFINED)
            {
              for (i = SEQ_LAST_INDEX(inst); i != 0UL; i--)
              {
                eMessageIdentity MessageID = l_msg_instance_array[inst].seq_MessageList[i - 1UL];
                if ((MSG_INDEX_UNDEFINED != MessageID) && (MessageID < MSG_NUM_MESSAGES))
                {
                  if (TESTBIT(messageList[MessageID].Options, (UINT32)MSG_OPTION_CLEARABLE))
                  {
                    if (((messageList[MessageID].AckGroup == thisMessage->AckGroup) &&
                      (MSG_ACKNOWLEDGE_BUTTON_EVENT == Button)) ||
                      ((MSG_ACKNOWLEDGE_CATEGORY_BUTTON_EVENT == Button) &&
                        (TESTBIT(messageList[MessageID].AckGroupCateg, thisMessage->AckGroupCateg)))
                      )
                    {
                      isDeactivated = seq_RemoveMessage(MessageID);
                      if (FALSE != isDeactivated)
                      {
                        seq_Callback(MessageID, MSG_EVENT_ACKNOWLEDGED);
                        MSG_SEQUENCER_CLIENT_ADD(MessageID);
                      }
                    }
                  }
                }
              }
            }
#endif            
            retValue = (UINT8)MSG_BTN_CHANGED;
          }
          l_msg_instance_array[inst].seq_HoldMessageID = MSG_INDEX_UNDEFINED;
          MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_HoldTimer);
          if(TESTBIT(thisMessage->Options, (UINT32)MSG_OPTION_DISP_INDICATIONTIME))
          {
            CLR_SEMAPHORE(seq_NewMessageFlags, l_msg_instance_array[inst].seq_CurrentMessageID);
            MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_DispIndTimer);
          }
        }
      }
    }
    else
    {
      /* To fix MISRA warning */
    }
  }
  return retValue;
}

void msg_SequencerRetrigger(eMessageIdentity MessageID)
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Message Retrigger:
**                  1. Store the Retrigger Msd ID if requested message is
**                     seq current message ID.
**
**  Parameters:     MessageID:  ID of the message which is retriggered.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: VSARAVA2 01/Mar/2012
**==========================================================================*/
{

  if(MessageID < MSG_NUM_MESSAGES)
  {
    MSG_MESSAGE_STRUCT const * pMessage; 
    UINT8 inst = 0u;
    pMessage = &messageList[MessageID];
    inst = pMessage->InstanceID;

    if(inst < MSG_NUM_INSTANCES)
    {
      if (MessageID == l_msg_instance_array[inst].seq_CurrentMessageID)
      {
        /*------------------------------------------------------------------*/
        /* Store the retrigger msg ID as requested ID only if the requested */
        /* msg is on top of Sequencer Q.                                    */
        /*------------------------------------------------------------------*/
        l_msg_instance_array[inst].seq_RetriggerMessageID = MessageID;
        /* Since the message is newly triggered the newmessage flag is forcefully set here */
        SET_SEMAPHORE(seq_NewMessageFlags, l_msg_instance_array[inst].seq_CurrentMessageID);

        MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_DisplayTimer);  
#ifdef MSG_CYCLE_OPTION_WITH_TIMEOUT
        /*-----------------------------------------------------------------*/
        /* Load the total timeout for the retriggered warning, so that it  */
        /* will extend the total display time                              */
        /*-----------------------------------------------------------------*/
        seq_DsplyTimeList[MessageID] = seq_MsgDisplayTime(MessageID);
#endif
      }
    }
  }
}

void msg_SequencerForcedActive(eMessageIdentity MessageID)
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Message Forced Active:
**                  1. Store the Forced Active Msd ID if requested message is
**                     seq current message ID.
**
**  Parameters:     MessageID:  ID of the message which is retriggered.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: CSAKTHIV 06/Aug/2020
**==========================================================================*/
{
  if(MessageID < MSG_NUM_MESSAGES)
  {	  
    UINT8 inst = 0u;
    MSG_MESSAGE_STRUCT const * pMessage; 
    pMessage = &messageList[MessageID];
    inst = pMessage->InstanceID;

    if(inst < MSG_NUM_INSTANCES)
    {
      if (MessageID == l_msg_instance_array[inst].seq_CurrentMessageID)
      {
        /*------------------------------------------------------------------*/
        /* Store the retrigger msg ID as requested ID only if the requested */
        /* msg is on top of Sequencer Q.                                    */
        /*------------------------------------------------------------------*/
        l_msg_instance_array[inst].seq_ForcedActiveMessageID = MessageID;

      }
    }
  }
}

#ifdef WARN_MSG_ENABLE_NEW_MESSAGE_SEQ_QUEUE_TIMEOUT
void msg_SequencerNewMsgQTimeoutUpdate(UINT8 p_inst)
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Will check the Seq msg Q timeout and remove if timer expired
**
**  Parameters:     None
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: VSARAVA2  20/Sep/2013
**==========================================================================*/
{

#if (MSG_NUM_INSTANCES > 1)
  UINT8 inst = p_inst;
  if(inst < MSG_NUM_INSTANCES) 
#else 
  UINT8 inst = 0u;
#endif
  {
    const MSG_MESSAGE_STRUCT *pMessage;
    eMessageIdentity MessageID;
    UINT8 MsgTimerStatus_U8;
    UINT32 i;
    MsgTimerStatus_U8 = MSG_CHECK_SW_TIMER(hmi_msg_inst_config_table[inst].seq_MsgQTimeout_1SecTimer);
    if (TIMER_RUNNING != MsgTimerStatus_U8)
    {
      /*------------------------------------------------------------------*/
      /* Restart the timer at every 1 seconds at the expiry               */
      /*------------------------------------------------------------------*/
      MSG_START_SW_TIMER(HMI_MSG_Q_TIMER_VAL, hmi_msg_inst_config_table[inst].seq_MsgQTimeout_1SecTimer);
      /*------------------------------------------------------------------*/
      /* Check the timer atleast once before expiry to get correct status */
      /*------------------------------------------------------------------*/
      (void)MSG_CHECK_SW_TIMER(hmi_msg_inst_config_table[inst].seq_MsgQTimeout_1SecTimer);

      /*------------------------------------------------------------------*/
      /* Here, loop thro the active message present in sequencer list has */
      /* NewMsg Q Timeout option and has valid timeout value to process   */
      /*------------------------------------------------------------------*/

      for (i=0UL; i <= (UINT32)hmi_msg_inst_config_count[inst]; i++)
      {
        MessageID = l_msg_instance_array[inst].seq_MessageList[i];
        /*------------------------------------------------------------------*/
        /* Misra warning fix: Loop thro the dynamic queue list to identify the end of */
        /* the active messages in the sequencer list and once the end of queue reached */
        /* it will have the value of undefined so dont consider the last element in the list */
        /*------------------------------------------------------------------*/
        if((MSG_INDEX_UNDEFINED != MessageID) && (MessageID < MSG_NUM_MESSAGES))
        {
          pMessage = &messageList[MessageID];
          if(TESTBIT(pMessage->Options, (UINT32)MSG_OPTION_NEW_MSG_SEQ_Q_TIMEOUT))
          {
            if(HMI_MSG_SEQ_TIMEOUT_INVALID_U8 != Seq_NewMsgQTimeout_U8[MessageID])
            {
              if(Seq_NewMsgQTimeout_U8[MessageID] >= HMI_MSG_VALUE_1)
              {
                Seq_NewMsgQTimeout_U8[MessageID] = Seq_NewMsgQTimeout_U8[MessageID] - HMI_MSG_VALUE_1;
              }
              else
              {
                Seq_NewMsgQTimeout_U8[MessageID] = 0;
              }
              if(0u == Seq_NewMsgQTimeout_U8[MessageID])
              {
                /*----------------------------------------------*/
                /* Is the message is currently displaying       */
                /*----------------------------------------------*/
                if(MessageID != l_msg_instance_array[inst].seq_CurrentMessageID)
                {
                  /*------------------------------------------*/
                  /* New Msg Q Timer expired, So remove the   */
                  /* msg from Seq Q                           */
                  /*------------------------------------------*/
                  (void)msg_SequencerRemove(MessageID,0);
                  seq_Callback(MessageID, MSG_EVENT_NEW_MSGQ_TIMEOUT);
                }
                /*----------------------------------------------*/
                /* Load the Invalid count, so that it won't     */
                /* check this in next time.                     */
                /*----------------------------------------------*/
                Seq_NewMsgQTimeout_U8[MessageID] = HMI_MSG_SEQ_TIMEOUT_INVALID_U8;
              }
            }
          }
        }
        else
        {
          /*----------------------------------------------------------*/
          /* Sequence Msg list is empty, so terminate the check       */
          /*----------------------------------------------------------*/
          break;
        }
      }
    }
  }
}
#endif

#if MSG_NUM_INSTANCES > 1
NULSIF_STANDARD_INTERFACE_MULTI_INST(msg_SequencerGetAlertInfo)
#else 
NULSIF_STANDARD_INTERFACE(msg_SequencerGetAlertInfo)
#endif
/*============================================================================
**  Visibility:     Private Public (.h)
**----------------------------------------------------------------------------
**  Description:    Standard interface function to obtain information about
**                  the current alert message.  Message information is placed
**                  in the caller-supplied MSG_VIEWINFO_T structure.
**
**  Parameters:     Data:       Pointer to a MSG_VIEWINFO_T structure that will
**                              be populated with the message information.
**
**  Returns:        sif_OK (always)
**----------------------------------------------------------------------------
** Created: AFERRIS2 07/Sep/2010
**==========================================================================*/
{

#if (MSG_NUM_INSTANCES > 1)
  UINT8 inst = p_inst;
  if(inst < MSG_NUM_INSTANCES)
#else 
  UINT8 inst = 0u;
#endif
  {
    MSG_VIEWINFO_T *retData;
    retData = (MSG_VIEWINFO_T *)SIF_GET_DATA_REF();


    /*----------------------------------------------------------*/
    /* Get data for caller.                                     */
    /*----------------------------------------------------------*/
    if (SIF_ISVALID_DATA())
    {
      retData->Id = l_msg_instance_array[inst].seq_CurrentMessageID;
      retData->Count = 0u;
      retData->Position = 0u;
      retData->Status = 0u;
      retData->InstanceID = inst;
      if(l_msg_instance_array[inst].seq_CurrentMessageID < MSG_NUM_MESSAGES)
      {
        retData->Count = SEQ_LAST_INDEX(inst);
        if (GET_SEMAPHORE(seq_MsgRecycleFlags, l_msg_instance_array[inst].seq_CurrentMessageID))
        {
          SETBIT(retData->Status, (UINT8)MSG_RECYCLE);
        }
        else
        {
          /* do nothing */
        }

        /*--------------------------------------------------------------*/
        /* Set the newmessgae flag  bit based on newmsessage flags condition         */
        /*--------------------------------------------------------------*/
        if (GET_SEMAPHORE(seq_NewMessageFlags, l_msg_instance_array[inst].seq_CurrentMessageID))
        {
          SETBIT(retData->Status, (UINT8)MSG_NEW);
        }
        else
        {
          /* do nothing */
        }

        /*--------------------------------------------------------------*/
        /* Set the MSG_DISPLAYED_ONCE flag  bit based on displayedonce flags condition         */
        /*--------------------------------------------------------------*/

        if (GET_SEMAPHORE(seq_DisplayedOnceFlags, l_msg_instance_array[inst].seq_CurrentMessageID))
        {
          SETBIT(retData->Status, (UINT8)MSG_DISPLAYED_ONCE);
        }
        else
        {
          /* do nothing */
        }
      }
    }
  }
  return sif_OK;
}

#if MSG_NUM_INSTANCES > 1
NULSIF_STANDARD_INTERFACE_MULTI_INST(msg_SequencerSelectFirst)
#else 
NULSIF_STANDARD_INTERFACE(msg_SequencerSelectFirst)
#endif
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Standard interface function to select the first message in
**                  the sequencer list that matches the given category mask.
**
**  Parameters:     Data:       ID of first message
**                              (MSG_INDEX_UNDEFINED if none available)
**
**  Returns:        sif_OK (always)
**----------------------------------------------------------------------------
** Created: AFERRIS2 27/Apr/2010
**==========================================================================*/
{

#if (MSG_NUM_INSTANCES > 1)
  UINT8 inst = p_inst;
  if(inst < MSG_NUM_INSTANCES)
#else 
  UINT8 inst = 0u;
#endif
  {
    eMessageIdentity messageID;
    MSG_VIEWINFO_T *retData;
    UINT32 index;

    retData = (MSG_VIEWINFO_T *)SIF_GET_DATA_REF();

    /*----------------------------------------------------------------------*/
    /* Obtain value that has been requested.                                */
    /*----------------------------------------------------------------------*/
    index = seq_FindFirstIndex(seq_ViewMask,inst);
    if (index <= hmi_msg_inst_config_count[inst])
    {
      messageID = l_msg_instance_array[inst].seq_MessageList[index];

      l_msg_instance_array[inst].seq_ViewMessage.Id = messageID;
      l_msg_instance_array[inst].seq_ViewMessage.Position = 0;
      l_msg_instance_array[inst].seq_ViewMessage.Count = seq_GetViewCount(seq_ViewMask,inst);
      l_msg_instance_array[inst].seq_ViewMessage.InstanceID = inst;
      if ((messageID < MSG_NUM_MESSAGES) && (GET_SEMAPHORE(seq_MsgRecycleFlags, messageID)))
      {
        SETBIT(l_msg_instance_array[inst].seq_ViewMessage.Status, ((UINT8)MSG_RECYCLE));
      }
      else
      {
        l_msg_instance_array[inst].seq_ViewMessage.Status = l_msg_instance_array[inst].seq_ViewMessage.Status & (~((UINT8)(MSG_RECYCLE)));
      }

      /*-------------------------------------------------------------------*/
      /* Set the newmessgae flag  bit based on newmsessage flags condition */
      /*-------------------------------------------------------------------*/
      if ((messageID < MSG_NUM_MESSAGES) && (GET_SEMAPHORE(seq_NewMessageFlags, messageID)))
      {
        SETBIT(l_msg_instance_array[inst].seq_ViewMessage.Status, ((UINT8)MSG_NEW));
      }
      else
      {
        l_msg_instance_array[inst].seq_ViewMessage.Status = l_msg_instance_array[inst].seq_ViewMessage.Status & (~((UINT8)(MSG_NEW)));
      }
      /*--------------------------------------------------------------*/
      /* Set the MSG_DISPLAYED_ONCE flag  bit based on displayedonce flags condition         */
      /*--------------------------------------------------------------*/
      if ((messageID < MSG_NUM_MESSAGES) && (GET_SEMAPHORE(seq_DisplayedOnceFlags, messageID)))
      {
        SETBIT(l_msg_instance_array[inst].seq_ViewMessage.Status, ((UINT8)(MSG_DISPLAYED_ONCE)));
      }
      else
      {
        l_msg_instance_array[inst].seq_ViewMessage.Status = l_msg_instance_array[inst].seq_ViewMessage.Status & (~((UINT8)(MSG_DISPLAYED_ONCE)));
      }

      /*----------------------------------------------------------------------*/
      /* Store data if caller provided a valid pointer.                       */
      /*----------------------------------------------------------------------*/
      if (SIF_ISVALID_DATA())
      {
        seq_GetViewMessage(retData,inst);
      }
    }
  }
  return sif_OK;
}

#if MSG_NUM_INSTANCES > 1
NULSIF_STANDARD_INTERFACE_MULTI_INST(msg_SequencerSelectNext)
#else 
NULSIF_STANDARD_INTERFACE(msg_SequencerSelectNext)
#endif
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Standard interface function to obtain the next message in
**                  the sequencer list that matches the given category mask.
**
**  Parameters:     Data:       ID of next message
**                              (MSG_INDEX_UNDEFINED if none available)
**
**  Returns:        sif_OK:     Next message is valid
**                  sif_ERROR:  Next message not available
**----------------------------------------------------------------------------
** Created: AFERRIS2 27/Apr/2010
**==========================================================================*/
{

  SIF_STATUS retVal = sif_OK;
#if (MSG_NUM_INSTANCES > 1)
  UINT8 inst = p_inst;
  if(inst < MSG_NUM_INSTANCES)
#else 
  UINT8 inst = 0u;
#endif
  {
    MSG_VIEWINFO_T *retData;
    UINT32 index;

    retData = (MSG_VIEWINFO_T *)SIF_GET_DATA_REF();

    /*----------------------------------------------------------------------*/
    /* Obtain value that has been requested.                                */
    /*----------------------------------------------------------------------*/
    index = seq_GetViewIndex(l_msg_instance_array[inst].seq_ViewMessage.Id, MSG_ALL_CATEGORIES,inst);
    index = seq_FindNextIndex(index + 1UL, seq_ViewMask,inst);

    /*----------------------------------------------------------------------*/
    /* Handle attempt to go past the end of the list                        */
    /*----------------------------------------------------------------------*/
    if (index >= SEQ_LAST_INDEX(inst))
    {
#if(MSG_SEQUENCER_VIEWER_OPTIONS == OPTION_VIEWER_WRAP)
      {
        /*--------------------------------------------------------------*/
        /* Find first if wrapping is enabled                            */
        /*--------------------------------------------------------------*/
        index = seq_FindFirstIndex(seq_ViewMask,inst);
        seq_SetViewMessage(l_msg_instance_array[inst].seq_MessageList[index],inst);
      }
#else
      {
        /*--------------------------------------------------------------*/
        /* Otherwise return error condition (data not available)        */
        /*--------------------------------------------------------------*/
        retVal = sif_ERROR;
      }
#endif
    }

    /*----------------------------------------------------------------------*/
    /* Otherwise get message ID and position.                               */
    /*----------------------------------------------------------------------*/
    else
    {
      seq_SetViewMessage(l_msg_instance_array[inst].seq_MessageList[index],inst);
    }

    /*----------------------------------------------------------------------*/
    /* Store data if caller provided a valid pointer.                       */
    /*----------------------------------------------------------------------*/
    if (SIF_ISVALID_DATA())
    {
      seq_GetViewMessage(retData,inst);
    }
  }
  return retVal;
}

#if MSG_NUM_INSTANCES > 1
NULSIF_STANDARD_INTERFACE_MULTI_INST(msg_SequencerSelectPrevious)
#else 
NULSIF_STANDARD_INTERFACE(msg_SequencerSelectPrevious)
#endif
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Standard interface function to obtain the previous message in
**                  the sequencer list that matches the given category mask.
**
**  Parameters:     Data:       ID of next message
**                              (MSG_INDEX_UNDEFINED if none available)
**
**  Returns:        sif_OK:     Next message is valid
**                  sif_ERROR:  Next message not available
**----------------------------------------------------------------------------
** Created: AFERRIS2 27/Apr/2010
**==========================================================================*/
{

  SIF_STATUS retVal = sif_OK;

#if (MSG_NUM_INSTANCES > 1)
  UINT8 inst = p_inst;
  if(inst < MSG_NUM_INSTANCES)
#else 
  UINT8 inst = 0u;
#endif
  {
    MSG_VIEWINFO_T *retData;
    UINT32 index;

    retData = (MSG_VIEWINFO_T *)SIF_GET_DATA_REF();

    /*----------------------------------------------------------------------*/
    /* Obtain value that has been requested.                                */
    /*----------------------------------------------------------------------*/
    index = seq_GetViewIndex(l_msg_instance_array[inst].seq_ViewMessage.Id, MSG_ALL_CATEGORIES,inst);
    index = seq_FindPreviousIndex(index, seq_ViewMask,inst);

    /*----------------------------------------------------------------------*/
    /* Handle attempt to go past the end of the list                        */
    /*----------------------------------------------------------------------*/
    if (index >= SEQ_LAST_INDEX(inst))
    {
#if(MSG_SEQUENCER_VIEWER_OPTIONS == OPTION_VIEWER_WRAP)
      {
        /*--------------------------------------------------------------*/
        /* Find first if wrapping is enabled                            */
        /*--------------------------------------------------------------*/
        index = (UINT16)seq_FindPreviousIndex(SEQ_LAST_INDEX(inst), seq_ViewMask,inst);

        seq_SetViewMessage(l_msg_instance_array[inst].seq_MessageList[index],inst);
      }
#else
      {
        /*--------------------------------------------------------------*/
        /* Otherwise return error condition (data not available)        */
        /*--------------------------------------------------------------*/
        retVal = sif_ERROR;
      }
#endif
    }

    /*----------------------------------------------------------------------*/
    /* Otherwise get message ID and position.                               */
    /*----------------------------------------------------------------------*/
    else
    {
      seq_SetViewMessage(l_msg_instance_array[inst].seq_MessageList[index],inst);
    }

    /*----------------------------------------------------------------------*/
    /* Store data if caller provided a valid pointer.                       */
    /*----------------------------------------------------------------------*/
    if (SIF_ISVALID_DATA())
    {
      seq_GetViewMessage(retData,inst);
    }
  }
  return retVal;
}

#if MSG_NUM_INSTANCES > 1
NULSIF_STANDARD_INTERFACE_MULTI_INST(msg_SequencerGetCurrent)
#else 
NULSIF_STANDARD_INTERFACE(msg_SequencerGetCurrent)
#endif
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Standard interface function to obtain information about the
**                  current message in the list.
**
**  Parameters:     Data:       This must be a pointer to a MSG_VIEWINFO_T structure
**
**  Returns:        sif_OK (always)
**----------------------------------------------------------------------------
** Created: AFERRIS2 27/Apr/2010
**==========================================================================*/
{

#if (MSG_NUM_INSTANCES > 1)
  UINT8 inst = p_inst;
#else 
  UINT8 inst = 0u;
#endif

  MSG_VIEWINFO_T *retData;
  retData = (MSG_VIEWINFO_T *)SIF_GET_DATA_REF();

  /*----------------------------------------------------------------------*/
  /* Obtain value to return, but only if there is a valid data pointer.   */
  /*----------------------------------------------------------------------*/
  if (SIF_ISVALID_DATA())
  {
    seq_GetViewMessage(retData,inst);
  }

  return sif_OK;
}

#if MSG_NUM_INSTANCES > 1
U32SIF_STANDARD_INTERFACE_MULTI_INST(msg_SequencerGetMessage)
#else 
U32SIF_STANDARD_INTERFACE(msg_SequencerGetMessage)
#endif
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Standard interface function to find if a specified message is active
**
**  Parameters:     Data:       This must be a pointer to a MSG_VIEWINFO_T structure
**                  Qualifier:  ID of message
**
**  Returns:        sif_OK (always)
**----------------------------------------------------------------------------
** Created: AFERRIS2 27/Apr/2010
**==========================================================================*/
{

  SIF_STATUS retValue = sif_ERROR;
#if (MSG_NUM_INSTANCES > 1)
  UINT8 inst = p_inst;
  if(inst < MSG_NUM_INSTANCES)
#else 
  UINT8 inst = 0u;
#endif
  {
    UINT32 MessageID;

    MessageID = SIF_GET_QUALIFIER();
    /*----------------------------------------------------------------------*/
    /* Obtain value to return, but only if there is a valid data pointer.   */
    /*----------------------------------------------------------------------*/
    if (SIF_ISVALID_DATA())
    {
      UINT16 index;

      index = seq_GetViewIndex((eMessageIdentity)MessageID, MSG_ALL_CATEGORIES,inst);

      if (index < SEQ_LAST_INDEX(inst))
      {
        SIF_SET_DATA(1);
      }
      else
      {
        SIF_SET_DATA(0);
      }

      /*------------------------------------------------------------------*/
      /* Valid data is obtained and msg status is updated in ref pointer  */
      /*------------------------------------------------------------------*/
      retValue = sif_OK;
    }
  }
  return (retValue);
}

#ifdef ALLOW_UNDISPLAYED_MSG_IMMEDIATELY
static eMessageIdentity seq_GetHighPrioNewMessage(eMessageCategory Category,UINT8 inst)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Gets only the highest priority New message in selected category.
**
**  Parameters:     Category:   Category to search.
**
**  Returns:        ID of message.
**----------------------------------------------------------------------------
** Created: ADEVI 20/04/2015
**==========================================================================*/
{

  eMessageIdentity retMessage;

  retMessage = MSG_INDEX_UNDEFINED;
  if(inst < MSG_NUM_INSTANCES)
  {  
    UINT32 thisIndex;
    eMessageIdentity aMessage;
    BOOLEAN IsNew;
    BOOLEAN IsDisplayedOnce;
    thisIndex = l_msg_instance_array[inst].seq_Categories[(UINT32)Category];
    if (thisIndex <= hmi_msg_inst_config_count[inst])
    {
      aMessage = l_msg_instance_array[inst].seq_MessageList[thisIndex]; 
      IsNew = (GET_SEMAPHORE(seq_NewMessageFlags, aMessage))? TRUE:FALSE;
      IsDisplayedOnce = (GET_SEMAPHORE(seq_DisplayedOnceFlags, aMessage))? TRUE:FALSE;

      if ((FALSE != IsNew) && (IsDisplayedOnce == FALSE))
      {
        retMessage = l_msg_instance_array[inst].seq_MessageList[thisIndex];
      }
    }
  }
  return (retMessage);
}
#endif
static eMessageIdentity seq_GetTopMostMessage(UINT8 inst)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Get top most valid message from the seq_MessageList.
**
**  Returns:        ID of message.
**----------------------------------------------------------------------------
** Created: ARAJASE2 14/03/2018
**==========================================================================*/
{

  eMessageIdentity retMessage = MSG_INDEX_UNDEFINED;
  if ((inst < MSG_NUM_INSTANCES) && (hmi_msg_inst_config_count[inst] > 0))
  {
    const MSG_MESSAGE_STRUCT* pMessage;
    UINT32 thisIndex = 0U;
    UINT32 startIndex = 0U;
    UINT32 endIndex = 0U;
    UINT32 i;
    while (thisIndex <= (UINT32)hmi_msg_inst_config_count[inst])
    {
      eMessageIdentity currentMessageID = l_msg_instance_array[inst].seq_MessageList[thisIndex++];
      /*Active messages*/
      if ((MSG_INDEX_UNDEFINED != currentMessageID) && (MSG_INDEX_UNDEFINED == retMessage))
      {
        pMessage = &messageList[currentMessageID];
        /*If the top most message is new message or non auto cancel warning,
        return it without further checks*/
        if ((GET_SEMAPHORE(seq_NewMessageFlags, currentMessageID)) ||
          (!TESTBIT(pMessage->Options, (UINT32)MSG_OPTION_AUTO_CANCEL)))
        {
          retMessage = currentMessageID;
        }
        /*Check whether is there any non auto cancel warnings are exist
        during cycling*/
        else
        {
          BOOLEAN fl_nonAutoCancelWrngsExists = FALSE;
          if (pMessage->Category < MSG_NUM_MESSAGE_CATEGORIES)
          {
            startIndex = l_msg_instance_array[inst].seq_Categories[(UINT32)pMessage->Category];
            endIndex = l_msg_instance_array[inst].seq_Categories[((UINT32)pMessage->Category) + 1UL];

            for (i = startIndex; i < endIndex; i++)
            {
              BOOLEAN fl_break_out_of_loop = FALSE;
              eMessageIdentity curCategoryMsg = l_msg_instance_array[inst].seq_MessageList[i];
              if (curCategoryMsg < MSG_NUM_MESSAGES)
              {
                /*If the message is new, then return this new message id*/
                if (GET_SEMAPHORE(seq_NewMessageFlags, curCategoryMsg))
                {
                  retMessage = curCategoryMsg;
                  fl_break_out_of_loop = TRUE; /*Break the for loop*/
                }
                /*Non auto cancel warning with cycle option enabled*/
                else if ((!TESTBIT(messageList[curCategoryMsg].Options, (UINT32)MSG_OPTION_AUTO_CANCEL)) &&
                  (TESTBIT(messageList[curCategoryMsg].Options, (UINT32)MSG_OPTION_CYCLE)))
                {
                  fl_nonAutoCancelWrngsExists = TRUE;
                  fl_break_out_of_loop = TRUE;
                }
                else
                {
                  /* Comment added to remove MISRA Warning 5736205 */
                }
              }
              if (fl_break_out_of_loop == TRUE)
              {
                break;
              }
            }
          }
          else
          {
            break;
          }
          /*If there is any non auto cancel warnings exist in the current category, then
          return the first message of the current category in the queue. Else check with
          the next category*/
          if (FALSE != fl_nonAutoCancelWrngsExists)
          {
            retMessage = currentMessageID;
          }
          else
          {
            thisIndex = endIndex;
          }
        }
      }
      else
      {
        break;
      }
    }
  }
  return (retMessage);
}


static eMessageIdentity seq_GetNewMessage(eMessageCategory Category,UINT8 inst)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Get highest priority New message in selected category.
**
**  Parameters:     Category:   Category to search.
**
**  Returns:        ID of message.
**----------------------------------------------------------------------------
** Created: AFERRIS2 27/04/2011
**==========================================================================*/
{

  eMessageIdentity retMessage;

  retMessage = MSG_INDEX_UNDEFINED;
  if((inst < MSG_NUM_INSTANCES) && (Category < MSG_NUM_MESSAGE_CATEGORIES))
  { 
    UINT32 thisIndex;
    UINT32 endIndex;
    eMessageIdentity aMessage;
    BOOLEAN IsNew;
    thisIndex = l_msg_instance_array[inst].seq_Categories[(UINT32)Category];

    /*-----------------------------------------------------------------------*/
    /* Check whether warning cycle needs to performed for all category       */
    /* and Change the end index accordingly                                  */
    /*-----------------------------------------------------------------------*/
#ifdef MSG_CYCLE_OPTION_ALL_CATEGORY
    endIndex = l_msg_instance_array[inst].seq_Categories[(UINT32)mcMaximum];
#else
    endIndex = l_msg_instance_array[inst].seq_Categories[(UINT32)(Category) + 1UL];
#endif



    while (thisIndex < endIndex)
    {
      if(thisIndex <= (UINT32)hmi_msg_inst_config_count[inst])
      {
        aMessage = l_msg_instance_array[inst].seq_MessageList[thisIndex];
        if(aMessage < MSG_NUM_MESSAGES)
        {
          IsNew = (GET_SEMAPHORE(seq_NewMessageFlags, aMessage)) ? TRUE : FALSE;
          if (FALSE != IsNew)
          {
            retMessage = l_msg_instance_array[inst].seq_MessageList[thisIndex];
            break;
          }
        }
      }
      thisIndex++;
    }
  }
  return (retMessage);
}

static eMessageIdentity seq_GetNextMessage(eMessageCategory Category, eMessageIdentity Message,UINT8 inst)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Get next message in selected category.
**
**  Parameters:     Category:   Category to search.
**                  Message:    Current message ID
**
**  Returns:        ID of next message.
**----------------------------------------------------------------------------
** Created: AFERRIS2 27/04/2011
**==========================================================================*/
{

  eMessageIdentity retMessage = MSG_INDEX_UNDEFINED;

  if((inst < MSG_NUM_INSTANCES) && (Category < MSG_NUM_MESSAGE_CATEGORIES))
  {  
    UINT32 startIndex;
    UINT32 endIndex;
    UINT32 i;
    const MSG_MESSAGE_STRUCT *currentMessage = MSG_NULL_PTR;
    startIndex = l_msg_instance_array[inst].seq_Categories[(UINT32)Category];
    if (startIndex <= hmi_msg_inst_config_count[inst])
    {
      /*-----------------------------------------------------------------------*/
      /* By default, load the start index of that category as next message     */
      /*-----------------------------------------------------------------------*/
      retMessage = l_msg_instance_array[inst].seq_MessageList[startIndex];

      /*-----------------------------------------------------------------------*/
      /* Check whether warning cycle needs to performed for all category       */
      /* and Change the end index accordingly                                  */
      /*-----------------------------------------------------------------------*/
#ifdef MSG_CYCLE_OPTION_ALL_CATEGORY
      endIndex = (UINT32)l_msg_instance_array[inst].seq_Categories[(UINT32)mcMaximum] - 1UL;
#else
      endIndex = (UINT32)l_msg_instance_array[inst].seq_Categories[(UINT32)Category+1UL] - 1UL;
#endif


      /*----------------------------------------------------------------------*/
      /* Search for the first message with same or higher ID than Message.    */
      /*----------------------------------------------------------------------*/
      for (i = startIndex; i < endIndex; i++)
      {
        if (Message == l_msg_instance_array[inst].seq_MessageList[i])
        {
          retMessage = l_msg_instance_array[inst].seq_MessageList[i+1UL];
          break;
        }
      }

      if (retMessage < MSG_NUM_MESSAGES)
      {
        currentMessage = &messageList[retMessage];

        /*Below code to handle auto cancel warnings
        AUTO_CANCEL_WARNING - This option should be specified by the application in
        MSG_MESSAGE_STRUCT.Options for each message. Setting this option indicates that
        this warning should be cycled only when non auto cancel warnings are active in
        the current category. If all other warnings other than auto cancel warnings,
        this warnings will not be cycled eventhough it is in the queue. It will be
        recycled again when any non auto cancel warnings are activated*/
        if(TESTBIT(currentMessage->Options, (UINT16)MSG_OPTION_AUTO_CANCEL))
        {
          BOOLEAN fl_nonAutoCancelWrngsExists = FALSE;
          /*To check only one message present with MSG_OPTION_AUTO_CANCEL is true*/  
          if(startIndex == endIndex)
          {
            fl_nonAutoCancelWrngsExists = FALSE;
          }
          else
          {
            if (endIndex <= hmi_msg_inst_config_count[inst])
            {
              for (i = startIndex; i <= endIndex; i++)
              {
                eMessageIdentity curMessage = l_msg_instance_array[inst].seq_MessageList[i];
                if (curMessage < MSG_NUM_MESSAGES)
                {
                  /*Non auto cancel warning with cycle option enabled*/
                  if((!TESTBIT(messageList[curMessage].Options, (UINT32)MSG_OPTION_AUTO_CANCEL)) &&
                    (TESTBIT(messageList[curMessage].Options, (UINT32)MSG_OPTION_CYCLE)))
                  {
                    fl_nonAutoCancelWrngsExists = TRUE;
                    break;
                  }
                }
              }
            }
          }
          /*If there is no non auto cancel warnings are exists then send MSG_INDEX_UNDEFINED since, auto cancel
          warnings should be cycled only with non auto cancel warnings*/
          if(FALSE == fl_nonAutoCancelWrngsExists)
          {
            retMessage = MSG_INDEX_UNDEFINED;
          }
        }
      }
    }
  }
  /*----------------------------------------------------------------------*/
  /* If we have got here then no message has been found.  Return the      */
  /* first mesage in this category.                                       */
  /*----------------------------------------------------------------------*/
  return (retMessage);
}

static eMessageIdentity seq_FindActiveMessage(eMessageCategory Category, eMessageIdentity Message,UINT8 inst)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Find the active message in selected category.  This will be
**                  either the current message or the highest priority message
**                  in this category if it is no longer active.
**
**  Parameters:     Category:   Category to search.
**                  Message:    Current message ID
**
**  Returns:        ID of next message.
**----------------------------------------------------------------------------
** Created: AFERRIS2 27/04/2011
**==========================================================================*/
{

  eMessageIdentity retMessage = MSG_INDEX_UNDEFINED;;

  if((inst < MSG_NUM_INSTANCES) && (Category < MSG_NUM_MESSAGE_CATEGORIES))
  {  
    UINT32 startIndex;
    UINT32 endIndex;
    UINT32 i;
    startIndex = l_msg_instance_array[inst].seq_Categories[(UINT32)Category];
    if (startIndex <= hmi_msg_inst_config_count[inst])
    {
      /*-----------------------------------------------------------------------*/
      /* By default, load the start index of that category as active message   */
      /*-----------------------------------------------------------------------*/
      retMessage = l_msg_instance_array[inst].seq_MessageList[startIndex];  
      /*-----------------------------------------------------------------------*/
      /* Check whether warning cycle needs to performed for all category       */
      /* and Change the end index accordingly                                  */
      /*-----------------------------------------------------------------------*/
#ifdef MSG_CYCLE_OPTION_ALL_CATEGORY
      endIndex = l_msg_instance_array[inst].seq_Categories[(UINT32)mcMaximum];
#else
      endIndex = l_msg_instance_array[inst].seq_Categories[(UINT32)Category+1UL];
#endif


      /*----------------------------------------------------------------------*/
      /* Search for the first message with same or higher ID than Message.    */
      /*----------------------------------------------------------------------*/
      for (i = startIndex; i < endIndex; i++)
      {
        if (Message == l_msg_instance_array[inst].seq_MessageList[i])
        {
          retMessage = Message;
          break;
        }
      }

    }
  }
  /*----------------------------------------------------------------------*/
  /* If we have got here then no message has been found.  Return the      */
  /* first mesage in this category.                                       */
  /*----------------------------------------------------------------------*/

  return (retMessage);
}

static void seq_GetViewMessage(MSG_VIEWINFO_T *ViewInfo,UINT8 inst)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Get information about current view
**
**  Parameters:     *ViewInfo:  Structure that will be populated.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 27/04/2011
**==========================================================================*/
{
  if(inst < MSG_NUM_INSTANCES)
  {
    ViewInfo->Count = l_msg_instance_array[inst].seq_ViewMessage.Count;
    ViewInfo->Id = l_msg_instance_array[inst].seq_ViewMessage.Id;
    ViewInfo->Position = l_msg_instance_array[inst].seq_ViewMessage.Position;
    ViewInfo->Status = l_msg_instance_array[inst].seq_ViewMessage.Status;
    ViewInfo->InstanceID = l_msg_instance_array[inst].seq_ViewMessage.InstanceID;
  }
}

static void seq_SetViewMessage(eMessageIdentity MessageID,UINT8 inst)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Set up information for message being viewed.
**
**  Parameters:     Index:  Index number of message in the message list
**                          (NOT the message ID!)
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 27/04/2011
**==========================================================================*/
{
  if(inst < MSG_NUM_INSTANCES)
  {
    l_msg_instance_array[inst].seq_ViewMessage.Id = MessageID;
    l_msg_instance_array[inst].seq_ViewMessage.Position = seq_GetViewIndex(l_msg_instance_array[inst].seq_ViewMessage.Id, seq_ViewMask,inst);
    l_msg_instance_array[inst].seq_ViewMessage.Count = seq_GetViewCount(seq_ViewMask,inst);
    l_msg_instance_array[inst].seq_ViewMessage.InstanceID = inst;
    if ((MessageID < MSG_NUM_MESSAGES) && (GET_SEMAPHORE(seq_MsgRecycleFlags, MessageID)))
    {
      SETBIT(l_msg_instance_array[inst].seq_ViewMessage.Status, (UINT8)MSG_RECYCLE);
    }
    else
    {
      l_msg_instance_array[inst].seq_ViewMessage.Status = l_msg_instance_array[inst].seq_ViewMessage.Status & (~((UINT8)(MSG_RECYCLE)));
    }
    /*-------------------------------------------------------------------*/
    /* Set the newmessgae flag  bit based on newmsessage flags condition */
    /*-------------------------------------------------------------------*/
    if ((MessageID < MSG_NUM_MESSAGES) && (GET_SEMAPHORE(seq_NewMessageFlags, MessageID)))
    {
      SETBIT(l_msg_instance_array[inst].seq_ViewMessage.Status, (UINT8)MSG_NEW);
    }
    else
    {
      l_msg_instance_array[inst].seq_ViewMessage.Status = l_msg_instance_array[inst].seq_ViewMessage.Status & (~((UINT8)(MSG_NEW)));
    }
    /*--------------------------------------------------------------*/
    /* Set the MSG_DISPLAYED_ONCE flag  bit based on displayedonce flags condition         */
    /*--------------------------------------------------------------*/
    if ((MessageID < MSG_NUM_MESSAGES) && (GET_SEMAPHORE(seq_DisplayedOnceFlags, MessageID)))
    {
      SETBIT(l_msg_instance_array[inst].seq_ViewMessage.Status, (UINT8)MSG_DISPLAYED_ONCE);
    }
    else
    {
      l_msg_instance_array[inst].seq_ViewMessage.Status = l_msg_instance_array[inst].seq_ViewMessage.Status & (~((UINT8)(MSG_DISPLAYED_ONCE)));
    }
  }
}

static UINT16 seq_GetViewCount(UINT32 CategoryMask,UINT8 inst)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Get number of messages that match the categories supplied
**
**  Parameters:     CategoryMask:   the categories being searched.
**
**  Returns:        Numbr of messages found
**----------------------------------------------------------------------------
** Created: AFERRIS2 06/Jul/2010
**==========================================================================*/
{

  UINT16 numEntries;

  numEntries = 0;
  if(inst < MSG_NUM_INSTANCES)
  {  
    MSG_MESSAGE_STRUCT const * thisMessage;
    UINT32 iMessage;
    UINT32 i;
    UINT32 categoryValue;
    /*------------------------------------------------------------------*/
    /* Loop through the whole list to find all entries that match.      */
    /*------------------------------------------------------------------*/
    for (i=0; i < SEQ_LAST_INDEX(inst); i++)
    {
      /*--------------------------------------------------------------*/
      /* Get pointer to message definition.                           */
      /*--------------------------------------------------------------*/
      iMessage = (UINT32)l_msg_instance_array[inst].seq_MessageList[i];
      if (iMessage < (UINT32)MSG_NUM_MESSAGES)
      {
        thisMessage = &messageList[iMessage];

        categoryValue = (1UL << (UINT8)thisMessage->Category);
        if (TESTBIT(CategoryMask, categoryValue))
        {
          /*----------------------------------------------------------*/
          /* Found matching category, so icrement count.              */
          /*----------------------------------------------------------*/
          numEntries++;
        }
      }
    }
  }
  return numEntries;
}

static UINT32 seq_InsertMessage(const MSG_MESSAGE_STRUCT *theMessage, eMessageIdentity MessageID)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Insert message into the message list.
**
**  Parameters:     *theMessage:    Configuration settings for the message.
**                  MessageID:      Message ID.
**
**  Returns:        Position of the message in the list.
**----------------------------------------------------------------------------
** Created: AFERRIS2 27/04/2011
**==========================================================================*/
{
  UINT32 indexToInsert = 0xFFFFFFFFUL;//Invalid index
  UINT8 inst = theMessage->InstanceID;
  if((inst < MSG_NUM_INSTANCES) && (theMessage->Category < MSG_NUM_MESSAGE_CATEGORIES))
  {
    UINT32 thisIndex;
    UINT32 endIndex;
    thisIndex = l_msg_instance_array[inst].seq_Categories[(UINT32)theMessage->Category];
    endIndex = l_msg_instance_array[inst].seq_Categories[(UINT32)theMessage->Category + 1UL];
    //Below logic to insert the new incoming message immediate to the current active message.
    //Check whether is there any active message and incoming message is of the same category
    if(TESTBIT(theMessage->Options, (UINT32)MSG_OPTION_INS_AFT_CUR))//Option to insert the msg next to the current active
      //As per the requirement, if the option is set new incoming message is added next to the
      //current active message irrespective of the priority
    {
      if (((MSG_INDEX_UNDEFINED != l_msg_instance_array[inst].seq_CurrentMessageID) && (l_msg_instance_array[inst].seq_CurrentMessageID < MSG_NUM_MESSAGES)))
      {
        const MSG_MESSAGE_STRUCT *curMessage = &messageList[l_msg_instance_array[inst].seq_CurrentMessageID];
        if(curMessage->Category == theMessage->Category)//should be same category
        {
          UINT32 loopIndex;

          for (loopIndex = thisIndex; loopIndex < endIndex;loopIndex++)
          {
            if (l_msg_instance_array[inst].seq_CurrentMessageID == l_msg_instance_array[inst].seq_MessageList[loopIndex])
            {
              indexToInsert = loopIndex + 1UL;
              break;
            }
          }
        }
      }
    }

    /*--------------------------------------------------------------*/
    /* Locate priority position and insert message in list.         */
    /*--------------------------------------------------------------*/

    if(indexToInsert == 0xFFFFFFFFUL)
    {
      while (thisIndex < endIndex)
      {
        UINT32 aMessage = (UINT32)l_msg_instance_array[inst].seq_MessageList[thisIndex];
        if (aMessage < (UINT32)MSG_NUM_MESSAGES)
        {
          MSG_MESSAGE_STRUCT const *ptrMessage = &messageList[aMessage];

#ifdef SEQ_QUEUE_FIFO
          /* If the sequncer queue is expected to be in last in first out manner */
          if (((TESTBIT(theMessage->Options, MSG_OPTION_SEQ_LIFO) && (theMessage->Priority <= ptrMessage->Priority)) ||
            /*  If the sequncer queue is expected to be in first in first out manner */
            (theMessage->Priority < ptrMessage->Priority)))
          {
            break;
          }
          else
          {
            /* Do nothing */
          }
#else
          if ((theMessage->Priority <= ptrMessage->Priority))
          {
            break;
          }
#endif
        }
        thisIndex++;
      }
      indexToInsert = thisIndex;
    }
    seq_Insert(indexToInsert, MessageID);
    seq_IndexUp((UINT16)theMessage->Category + 1U,inst);
  }
  return indexToInsert;
}
#if MSG_NUM_INSTANCES > 1
UINT32 seq_GetCategories(UINT32 Threshold,UINT8 p_inst)
#else
UINT32 seq_GetCategories(UINT32 Threshold)
#endif
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Check if there are more than "Threshold" messages active.
**                  Each category is checked and the appropriate bit in the
**                  return status set if the threshold has been exceeded.
**
**  Parameters:     Threshold:  More than this number of messages must be active
**                              in a category to set the output bit.
**
**  Returns:        Category message status.
**----------------------------------------------------------------------------
** Created: AFERRIS2 20/Oct/2010
**==========================================================================*/
{
  UINT32 retValue = 0;

#if (MSG_NUM_INSTANCES > 1)
  UINT8 inst = p_inst;
  if(inst < MSG_NUM_INSTANCES)
#else 
  UINT8 inst = 0u;
#endif

  {
    UINT32 i;
    for (i=0UL; i < (UINT32)MSG_NUM_MESSAGE_CATEGORIES; i++)
    {
      if ((l_msg_instance_array[inst].seq_Categories[i] + (UINT16)Threshold) < l_msg_instance_array[inst].seq_Categories[i+1UL])
      {
        SETBIT(retValue, (1UL << i));
      }
    }
  }
  return retValue;
}

static void seq_RemoveHoldMessage(UINT8 inst)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Remove message that is being held due to minimum display
**                  time requirements.
**
**  Parameters:     None.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 06/Sep/2010
**==========================================================================*/
{
  if(inst < MSG_NUM_INSTANCES)
  {
    BOOLEAN found;
    if (MSG_INDEX_UNDEFINED != l_msg_instance_array[inst].seq_HoldMessageID)
    {
      UINT32 msgIndex = seq_GetViewIndex(l_msg_instance_array[inst].seq_HoldMessageID, MSG_ALL_CATEGORIES,inst);
      found = seq_RemoveMessage(l_msg_instance_array[inst].seq_HoldMessageID);

      if (FALSE != found)
      {
        seq_UpdateViewer(l_msg_instance_array[inst].seq_HoldMessageID, msgIndex,inst);
      }

      l_msg_instance_array[inst].seq_HoldMessageID = MSG_INDEX_UNDEFINED;
    }
  }
}

static void seq_UpdateViewer(eMessageIdentity MessageID, UINT32 MsgIndex,UINT8 inst)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Notify VIEWER if we need to show a different message.
**                  (removed message has same or higher priority than the msg
**                  being viewed). Next message to be viewed can be found using
**                  the FindNext function.
**
**  Parameters:     MessageID:  ID of message being removed.
**                  MsgIndex:   original index of message that has been removed.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 04/May/2011
**==========================================================================*/
{

  if(inst < MSG_NUM_INSTANCES)
  {
    UINT32 index;
    eMessageIdentity newMessage = MSG_INDEX_UNDEFINED;
    if (MessageID == l_msg_instance_array[inst].seq_ViewMessage.Id)
    {
      /*------------------------------------------------------------------*/
      /* Have just removed the message being viewed....                   */
      /* Search for next message from original message position.          */
      /*------------------------------------------------------------------*/
      index = seq_FindNextIndex(MsgIndex, seq_ViewMask,inst);
      if (index <= hmi_msg_inst_config_count[inst])
      {
        newMessage = l_msg_instance_array[inst].seq_MessageList[index];
      }
    }
    else
    {
      /*------------------------------------------------------------------*/
      /* Have removed another message ...                                 */
      /* keep the existing message.                                       */
      /*------------------------------------------------------------------*/
      newMessage = l_msg_instance_array[inst].seq_ViewMessage.Id;
    }

    /*----------------------------------------------------------------------*/
    /* Check that message ID is still valid.  If not choose the first       */
    /* message in selected categories.                                      */
    /*----------------------------------------------------------------------*/
    if (MSG_INDEX_UNDEFINED == newMessage)
    {
      index = seq_FindFirstIndex(seq_ViewMask,inst);
      if (index <= hmi_msg_inst_config_count[inst])
      {
        newMessage = l_msg_instance_array[inst].seq_MessageList[index];
      }
    }

    /*----------------------------------------------------------------------*/
    /* Finally, update view information and inform viewer that something    */
    /* has changed.                                                         */
    /*----------------------------------------------------------------------*/
    seq_SetViewMessage(newMessage,inst);
    MSG_SEQUENCER_NOTIFY_VIEWER();
  }
}

static BOOLEAN seq_RemoveMessage(eMessageIdentity MessageID)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Remove a message from the sequencer.
**
**  Parameters:     MessageID:  ID of the message to be removed.
**
**  Returns:        FALSE:  Message not found in list
**                  TRUE:   Message has been removed.
**----------------------------------------------------------------------------
** Created: AFERRIS2 12/Apr/2010
**==========================================================================*/
{
  BOOLEAN found = FALSE;
  if (MessageID < MSG_NUM_MESSAGES)
  {
    MSG_MESSAGE_STRUCT const * thisMessage;
    UINT32 thisIndex = 0;
    UINT32 endIndex = 0;
    UINT8 inst = 0u;
    thisMessage = &messageList[MessageID];
    inst = thisMessage->InstanceID;
    if(inst < MSG_NUM_INSTANCES)
    {
      CLR_SEMAPHORE(seq_NewMessageFlags, MessageID);  /* ### QAC ERROR:4130 ### */

      /*----------------------------------------------------------------------*/
      /* Indicate the Message is not recycling                                */
      /*----------------------------------------------------------------------*/
      CLR_SEMAPHORE(seq_MsgRecycleFlags, MessageID); /* ### QAC WARNING:4130 ### */

#ifdef MSG_CYCLE_OPTION_WITH_TIMEOUT
      /*----------------------------------------------------------------------*/
      /* Clear the counter value once the message is removed from the Seq Q   */
      /*----------------------------------------------------------------------*/
      seq_DsplyTimeList[MessageID] = 0;
#endif

#ifdef WARN_MSG_ENABLE_NEW_MESSAGE_SEQ_QUEUE_TIMEOUT
      /*----------------------------------------------------------------------*/
      /* Message is getting removed from Seq Q, So the NewMsg Q Timeout is    */
      /* not applicable for this message, So load invalid timeout value       */
      /*----------------------------------------------------------------------*/
      Seq_NewMsgQTimeout_U8[MessageID] = HMI_MSG_SEQ_TIMEOUT_INVALID_U8;
#endif

      if ((TESTBIT(thisMessage->Options, (UINT32)MSG_OPTION_CYCLE) ) && (MessageID == l_msg_instance_array[inst].seq_CurrentMessageID))
      {
        /*------------------------------------------------------------------*/
        /* Message no longer valid for cycling. So, Clear it. Otherwise     */
        /* sequencerUpdate() will not pick the next new message from Q      */
        /*------------------------------------------------------------------*/
        MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_CycleTimer);

#ifdef MSG_CYCLE_OPTION_WITH_TIMEOUT
        /*-------------------------------------------------------------------*/
        /*   Clear 1 sec timer                                              */
        /*------------------------------------------------------------------*/
        MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].seq_1secTimer);
#endif
      }

#ifdef MSG_OLD_WRNG_REPETITION
      if(TESTBIT(thisMessage->Options, (UINT32)MSG_OPTION_OLD_WRNG_REPEAT))
      {
        /*--------------------------------------------------------------*/
        /* Load invalid value in old warning repetition duration array  */
        /*--------------------------------------------------------------*/
        seq_Old_Wrng_RepDuration[MessageID] = HMI_MSG_OLD_WRNG_REP_INVALID_U16;
      }
#endif

      if (TESTBIT(thisMessage->Options, (UINT32)MSG_OPTION_SEQUENCE) )
      {

        /*------------------------------------------------------------------*/
        /* Message can be sequenced.                                        */
        /*------------------------------------------------------------------*/
        if (thisMessage->Category < MSG_NUM_MESSAGE_CATEGORIES)
        {
          thisIndex = l_msg_instance_array[inst].seq_Categories[(UINT32)(thisMessage->Category)];
          endIndex = l_msg_instance_array[inst].seq_Categories[(UINT32)(thisMessage->Category) + 1UL];

        /*------------------------------------------------------------------*/
        /* Locate message in the list and remove it.                        */
        /*------------------------------------------------------------------*/     
          while (thisIndex < endIndex)
          {
            if (l_msg_instance_array[inst].seq_MessageList[thisIndex] == MessageID)
            {
#ifdef CYCLE_IN_ORDER_WITHIN_CATEGORY
              /*------------------------------------------------------------------*/
              /* Before the message is removed, save the next message to be cycled*/
              /* in that category. If the next message is the last message, top   */
              /* of the queue will be the next message to be cycled               */
              /*------------------------------------------------------------------*/
              l_msg_instance_array[inst].seq_NextCycleMessageID = seq_GetNextMessage(thisMessage->Category,MessageID,inst);
              /*------------------------------------------------------------------*/
              /* If the next message to cycle and the message ID to be removed is */
              /* the same, it means that it is the only cycling message in that   */
              /* category. So, there is no more valid messages for the next cycle */ 
              /*------------------------------------------------------------------*/
              if(l_msg_instance_array[inst].seq_NextCycleMessageID == MessageID)
              {
                l_msg_instance_array[inst].seq_NextCycleMessageID = MSG_INDEX_UNDEFINED;
              }
#endif
              seq_Delete(thisIndex,inst);
              seq_IndexDown((UINT16)thisMessage->Category + 1U,inst);
              found = TRUE;
              break;
            }
            thisIndex++;
          }
        }
      }
    }
  }
  return found;
}

static UINT16 seq_GetViewIndex(eMessageIdentity MessageID, UINT32 CategoryMask,UINT8 inst)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Get the index of the message within the list of messages that
**                  match the specified categories.
**
**  Parameters:     MessageID:      The Message ID
**                  CategoryMask:   The Categories to search in.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 06/Jul/2010
**==========================================================================*/
{
  UINT16 index = 0u;

  if (MessageID < MSG_NUM_MESSAGES)
  {
    UINT32 i;
    eMessageIdentity iMessage;
    MSG_MESSAGE_STRUCT const *pMessage;

    if (inst < MSG_NUM_INSTANCES)
    {
      for (i = 0; i < SEQ_LAST_INDEX(inst); i++)
      {
        iMessage = l_msg_instance_array[inst].seq_MessageList[i];
        if (iMessage < (eMessageIdentity)MSG_NUM_MESSAGES)
        {
          if (MessageID == iMessage)
          {
            /*----------------------------------------------------------*/
            /* Found the message we are looking for....                 */
            /*----------------------------------------------------------*/
            break;
          }
          else
          {
            /*-----------------------------------------------------------*/
            /* Check if this message is in one of the categories being   */
            /* searched                                                  */
            /*-----------------------------------------------------------*/
            pMessage = &messageList[iMessage];
            if (TESTBIT(CategoryMask, (1UL << (UINT8)pMessage->Category)))
            {
              /*------------------------------------------------------*/
              /* It is, so increment count.                           */
              /*------------------------------------------------------*/
              index++;
            }
          }
        }
      }
    }
  }
  return index;
}

static void seq_IndexUp(UINT16 BaseCategory,UINT8 inst)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Update category index values when a new message is added.
**
**  Parameters:     BaseCategory:   First category to be updated.  All categroies
**                                  following this one will also be updated.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 12/Apr/2010
**==========================================================================*/
{

  /*----------------------------------------------------------------------*/
  /* Increase the index value of all categories above the base category.  */
  /*----------------------------------------------------------------------*/
  if(inst < MSG_NUM_INSTANCES)
  {
    UINT32 iCategory = BaseCategory;
    while (iCategory <= (UINT32)MSG_NUM_MESSAGE_CATEGORIES )
    {
      l_msg_instance_array[inst].seq_Categories[iCategory]++;
      iCategory++;
    }
  }
}

static void seq_IndexDown(UINT16 BaseCategory,UINT8 inst)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Update category index values when a message is removed.
**
**  Parameters:     BaseCategory:   First category to be updated.  All categroies
**                                  following this one will also be updated.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 12/Apr/2010
**==========================================================================*/
{

  /*----------------------------------------------------------------------*/
  /* Decrease the index value of all categories above the base category.  */
  /*----------------------------------------------------------------------*/
  if(inst < MSG_NUM_INSTANCES)
  {
    UINT32 iCategory = BaseCategory;
    while (iCategory <= (UINT32)MSG_NUM_MESSAGE_CATEGORIES )
    {
      l_msg_instance_array[inst].seq_Categories[iCategory]--;
      iCategory++;
    }
  }
}

static void seq_Delete(UINT32 Index,UINT8 inst)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Delete the message at the given position. All messages
**                  following this one are moved up one position.
**
**  Parameters:     Index:  Position of the message to delete.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 12/Apr/2010
**==========================================================================*/
{
  /*----------------------------------------------------------------------*/
  /* Shift messages up.                                                   */
  /*----------------------------------------------------------------------*/
  if(inst < MSG_NUM_INSTANCES)
  {
    UINT32 fl_index = Index;
    while (fl_index < SEQ_LAST_INDEX(inst))
    {
      l_msg_instance_array[inst].seq_MessageList[fl_index] = l_msg_instance_array[inst].seq_MessageList[fl_index + 1UL];
      fl_index++;
    }
    /*----------------------------------------------------------------------*/
    /* Set last position to invalid message ID.                             */
    /*----------------------------------------------------------------------*/
    l_msg_instance_array[inst].seq_MessageList[fl_index] = MSG_INDEX_UNDEFINED;
  }
}

static void seq_Insert(UINT32 Index, eMessageIdentity MessageID)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Insert a message at the given position.  All messages from
**                  this index downwards are shifted down one place to make room
**                  for the new message.
**
**  Parameters:     Index:  Position of the message in the list.
**                  Value:  New Message ID.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 12/Apr/2010
**==========================================================================*/
{
  if (MessageID < MSG_NUM_MESSAGES)
  {
    UINT8 inst = 0u;
    UINT32 i;
    MSG_MESSAGE_STRUCT const *pMessage;
    pMessage = &messageList[MessageID];
    inst = pMessage->InstanceID;

    if (inst < MSG_NUM_INSTANCES)
    {
      /*----------------------------------------------------------------------*/
      /* Shift messages down.                                                 */
      /*----------------------------------------------------------------------*/
      i = (UINT32)SEQ_LAST_INDEX(inst) + 1UL;
      while (i > Index)
      {
        if (i <= (UINT32)MSG_NUM_MESSAGES)
        {
          l_msg_instance_array[inst].seq_MessageList[i] = l_msg_instance_array[inst].seq_MessageList[i - 1UL];
        }
        i--;
      }

      /*----------------------------------------------------------------------*/
      /* Save message ID to this position.                                    */
      /*----------------------------------------------------------------------*/
      if (Index <= (UINT32)MSG_NUM_MESSAGES)
      {
        l_msg_instance_array[inst].seq_MessageList[Index] = MessageID;
      }
    }
  }
}

static void seq_InitIndex(UINT8 inst)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Initialise the category indexes.
**
**  Parameters:     None.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 12/Apr/2010
**==========================================================================*/
{

  if(inst < MSG_NUM_INSTANCES)
  {
    UINT32 i;
    for (i=0; i <= (UINT32)(MSG_NUM_MESSAGE_CATEGORIES); i++)
    {
      l_msg_instance_array[inst].seq_Categories[i] = 0;
    }
  }
}

static void seq_InitList(UINT8 inst)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Initialise the message indexes.
**
**  Parameters:     None.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 12/Apr/2010
**==========================================================================*/
{

  if(inst < MSG_NUM_INSTANCES)
  {
    UINT32 i;
    for (i=0UL; i <= (UINT32)MSG_NUM_MESSAGES; i++)
    {
      l_msg_instance_array[inst].seq_MessageList[i] = MSG_INDEX_UNDEFINED;

#ifdef MSG_CYCLE_OPTION_WITH_TIMEOUT
      seq_DsplyTimeList[i] = 0;
#endif

#ifdef WARN_MSG_ENABLE_NEW_MESSAGE_SEQ_QUEUE_TIMEOUT
      /*------------------------------------------------------------------*/
      /* Initialize with 0xffff, indicates that the Seq msg Q timeout     */
      /* is not applicable for that warning                               */
      /*------------------------------------------------------------------*/
      Seq_NewMsgQTimeout_U8[i] = HMI_MSG_SEQ_TIMEOUT_INVALID_U8;
#endif

#ifdef MSG_OLD_WRNG_REPETITION
      /*------------------------------------------------------------------*/
      /* Initialize with 0xffff, indicates that the old warning repetition*/
      /* is not applicable for that warning                               */
      /*------------------------------------------------------------------*/
      seq_Old_Wrng_RepDuration[i] = HMI_MSG_OLD_WRNG_REP_INVALID_U16;
#endif

    }
  }
}

static void seq_InitView(UINT8 inst)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Initialise the View message information structure to default
**                  values.
**
**  Parameters:     None.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 27/04/2011
**==========================================================================*/
{
  if(inst < MSG_NUM_INSTANCES)
  {
    l_msg_instance_array[inst].seq_ViewMessage.Id = MSG_INDEX_UNDEFINED;
    l_msg_instance_array[inst].seq_ViewMessage.Count = 0;
    l_msg_instance_array[inst].seq_ViewMessage.Position = 0;
    l_msg_instance_array[inst].seq_ViewMessage.Status = 0;
  }
  seq_ViewMask = MSG_ALL_CATEGORIES;
}

static UINT32 seq_FindFirstIndex(UINT32 CategoryMask,UINT8 inst)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Get index of the first message that matches the category mask
**                  supplied
**
**  Parameters:     CategoryMask:   Mask of categories to search.
**
**  Returns:        Index of first message.
**----------------------------------------------------------------------------
** Created: AFERRIS2 06/Jul/2010
**==========================================================================*/
{
  return seq_FindNextIndex(0, CategoryMask,inst);
}

static UINT32 seq_FindNextIndex(UINT32 Start, UINT32 CategoryMask,UINT8 inst)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Get index of the next message that matches the category mask
**                  supplied
**
**  Parameters:     Start:  The index to search from
**                  CategoryMask:   Mask of categories to search.
**
**  Returns:        Index of next message.
**----------------------------------------------------------------------------
** Created: AFERRIS2 06/Jul/2010
**==========================================================================*/
{
  UINT32 index = 0u;

  if(inst < MSG_NUM_INSTANCES)
  {

    UINT32 i;
    eMessageIdentity iMessage;
    MSG_MESSAGE_STRUCT const *pMessage;
    index = SEQ_LAST_INDEX(inst);
    for (i = Start; i < SEQ_LAST_INDEX(inst); i++)
    {
      if(i <= (UINT32)MSG_NUM_MESSAGES)
      {
        /*--------------------------------------------------------------*/
        /* Get pointer to message definition.                           */
        /*--------------------------------------------------------------*/
        iMessage = l_msg_instance_array[inst].seq_MessageList[i];

        if (iMessage < (eMessageIdentity)MSG_NUM_MESSAGES)
        {
          pMessage = &messageList[iMessage];

          if (TESTBIT(CategoryMask, (1UL << (UINT8)pMessage->Category)) )
          {
            /*----------------------------------------------------------*/
            /* Match found....                                          */
            /*----------------------------------------------------------*/
            index = i;
            break;
          }
        }
      }
    }
  }

  return index;
}

static UINT32 seq_FindPreviousIndex(UINT32 Start, UINT32 CategoryMask, UINT8 inst)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Get index of the previous message that matches the category
**                  mask supplied
**
**  Parameters:     Start:  The index to search from
**                  CategoryMask:   Mask of categories to search.
**
**  Returns:        Index of previous message.
**----------------------------------------------------------------------------
** Created: AFERRIS2 06/Jul/2010
**==========================================================================*/
{
  UINT32 index = 0u;
  if(inst < MSG_NUM_INSTANCES) 
  {
    UINT32 i;
    MSG_MESSAGE_STRUCT const * pMessage;
    eMessageIdentity iMessage;
    index = SEQ_LAST_INDEX(inst);
    for (i = Start; i != 0UL; i--)
    {
      /*--------------------------------------------------------------*/
      /* Get pointer to message definition.                           */
      /*--------------------------------------------------------------*/
      iMessage = l_msg_instance_array[inst].seq_MessageList[i-1UL];
      if (iMessage < (eMessageIdentity)MSG_NUM_MESSAGES)
      {
        pMessage = &messageList[iMessage];

        if (TESTBIT(CategoryMask, (1UL << (UINT8)pMessage->Category)))
        {
          /*----------------------------------------------------------*/
          /* Match found....                                          */
          /*----------------------------------------------------------*/
          index = i - 1UL;
          break;
        }
      }
    }
  }

  return index;
}

static void seq_Callback(eMessageIdentity MessageID, UINT16 Action)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Wrapper for the callback to notify the source feature of
**                  actions taken by the sequencer.
**
**  Parameters:     MessageID:  ID of message
**                  Action:     Action performed.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 03/Sep/2010
**==========================================================================*/
{
  UINT16 fl_action = Action;
  if (MessageID < MSG_NUM_MESSAGES)
  {
    MSG_MESSAGE_STRUCT const * pMessage;
    pMessage = &messageList[MessageID];

    /*--------------------------------------------------------------*/
    /* Only notify if this action has been configured for this      */
    /* message and callback is enabled.                             */
    /*--------------------------------------------------------------*/
    if (TESTBIT(pMessage->EventQualifier, fl_action) )
    {
      if (NULL != pMessage->MsgEventCallback) /* ### QAC ERROR:0307 ### */
      {				
#if MSG_NUM_INSTANCES > 1
        (void)SIF_EXEC_INST(pMessage->MsgEventCallback, (fl_action), pMessage->ConditionQualifier,pMessage->InstanceID);
#else
        (void)SIF_EXEC(pMessage->MsgEventCallback, (fl_action), pMessage->ConditionQualifier);
#endif
      }
    }
  }
}

#ifdef MSG_CYCLE_OPTION_WITH_TIMEOUT
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    callback function to get total Display timeout of
**                  cuurently active  msg ID.
**
**  Parameter:      MessageID:  ID of message
**
**  Returns:        Timeouit value.
**----------------------------------------------------------------------------
** Created: pvazhung 26/Jun/2012
**==========================================================================*/
static UINT16 seq_MsgDisplayTime(eMessageIdentity MessageID)
{
  UINT16 Ret_Value_U16 = 0;

  if (MessageID < MSG_NUM_MESSAGES)
  {
    MSG_MESSAGE_STRUCT const * pMessage;
    pMessage = &messageList[MessageID];
    Ret_Value_U16 = pMessage->DisplayTimeout;
  }
  return(Ret_Value_U16);
}
#endif

#ifdef MSG_OLD_WRNG_REPETITION
void msg_SequencerOldWrngRepUpdate(UINT8 p_inst)
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Will check the old warning repetition duration expiry for
**  the messages where MSG_OPTION_OLD_WRNG_REPEAT option is enabled.  If the old
**  warning duration expires then the old warning is made new by setting the
**  newmessage flag of the particular warning.
**
**  Parameters:     None
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: adevi  13/Dec/2013
**==========================================================================*/
{


#if (MSG_NUM_INSTANCES > 1)
  UINT8 inst = p_inst;
  if(inst < MSG_NUM_INSTANCES) 
#else 
  UINT8 inst = 0u;
#endif
  {
    const MSG_MESSAGE_STRUCT *pMessage;
    eMessageIdentity MessageID;
    UINT8 MsgTimerStatus_U8;
    UINT32 i;
    MsgTimerStatus_U8 = MSG_CHECK_SW_TIMER(hmi_msg_inst_config_table[inst].seq_OldWrng_Rep_1SecTimer);
    if (TIMER_RUNNING != MsgTimerStatus_U8)
    {
      /*------------------------------------------------------------------*/
      /* Restart the timer during the expiry of every 1 second.           */
      /*------------------------------------------------------------------*/
      MSG_START_SW_TIMER(HMI_MSG_OLD_WRNG_1SEC_TMR_VAL, hmi_msg_inst_config_table[inst].seq_OldWrng_Rep_1SecTimer);
      /*------------------------------------------------------------------*/
      /* All the active messages present in sequencer list which has      */
      /* MSG_OPTION_OLD_WRNG_REPEAT option enabled and has valid old      */
      /* warning repetition time is short listed. Old warning repetition  */
      /* duration is decremented every one second.  When the value is 0   */
      /* then the message is made new by setting the new message flag     */
      /*------------------------------------------------------------------*/

      for (i=0UL; i <= (UINT32)hmi_msg_inst_config_count[inst]; i++)
      {
        MessageID = l_msg_instance_array[inst].seq_MessageList[i];
        /*------------------------------------------------------------------*/
        /* Misra warning fix: Loop thro the dynamic queue list to identify the end of */
        /* the active messages in the sequencer list and once the end of queue reached */
        /* it will have the value of undefined so dont consider the last element in the list */
        /*------------------------------------------------------------------*/
        if((MSG_INDEX_UNDEFINED != MessageID) && (MessageID < MSG_NUM_MESSAGES))
        {
          pMessage = &messageList[MessageID];
          if(TESTBIT(pMessage->Options, (UINT32)MSG_OPTION_OLD_WRNG_REPEAT))
          {
            if(HMI_MSG_OLD_WRNG_REP_INVALID_U16 != seq_Old_Wrng_RepDuration[MessageID])
            {
              if(seq_Old_Wrng_RepDuration[MessageID] >= HMI_MSG_OLD_WRNG_1SEC_TIMEOUT_VALUE)
              {
                seq_Old_Wrng_RepDuration[MessageID] = (seq_Old_Wrng_RepDuration[MessageID] - HMI_MSG_OLD_WRNG_1SEC_TIMEOUT_VALUE);
              }
              else
              {
                seq_Old_Wrng_RepDuration[MessageID] = 0U;
              }
              if(0U == seq_Old_Wrng_RepDuration[MessageID])
              {
                /*-----------------------------------------------------------*/
                /* Set the seq_NewMessageFlags flag of the message ID passed */
                /*-----------------------------------------------------------*/
                SET_SEMAPHORE(seq_NewMessageFlags, MessageID);
                /*--------------------------------------------------------------------*/
                /* Msg is made new so clear the recycle flag of the message ID passed */
                /*--------------------------------------------------------------------*/
                CLR_SEMAPHORE(seq_MsgRecycleFlags, MessageID);
              }
            }
          }
        }
        else
        {
          /*----------------------------------------------------------*/
          /* Sequence list is empty, so terminate the check           */
          /*----------------------------------------------------------*/
          break;
        }
      }
    }
  }
}
#endif
/*--------------------------------------------------------------------------*/
/* Test functions                                                           */
/*--------------------------------------------------------------------------*/
#if defined MSG_UNIT_TEST
#if defined ENABLE_PRIVATE_TIMERS
TIMER seqtest_GetSetDisplayTimer(TIMER NewValue)
{
  TIMER retval = hmi_msg_inst_config_table[inst].seq_DisplayTimer;
  hmi_msg_inst_config_table[inst].seq_DisplayTimer = NewValue;

  return retval;
}

TIMER seqtest_GetSetHoldTimer(TIMER NewValue)
{
  TIMER retval = hmi_msg_inst_config_table[inst].seq_HoldTimer;
  hmi_msg_inst_config_table[inst].seq_HoldTimer = NewValue;

  return retval;
}

TIMER seqtest_GetSetCycleTimer(TIMER NewValue)
{
  TIMER retval = hmi_msg_inst_config_table[inst].seq_CycleTimer;
  hmi_msg_inst_config_table[inst].seq_CycleTimer = NewValue;

  return retval;
}
#endif
#endif


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
**  Change: 1.  Add support for local and kernel timers.
**          2.  Update interface functions to use the formal Standard Interface
**          3.  Add interface for the number of viewable messages
**          4.  Add notification (to viewer) when viewed message changes.
**          5.  Corrected actions of ViewFirst and ViewNext functions.
**
**  Checks: COMPILER - NO WARNINGS       QAC - NO WARNINGS
*****************************************************************************/
/****************************************************************************
**  Date: 07/Jul/2010     by: AFERRIS2        Ref:
**  Change: 1.  Updated interfaces to include message ID, position, and count.
**              We now use msg_SequencerGetCurrent(), msg_SequencerSelectFirst(),
**              msg_SequencerSelectNext(), and msg_SequencerSelectPrevious() functions
**          2.  Made wrapping an option via the configuration file.
**          3.  QAC reports one error (nested comment within swtmr.h)
**
**  Checks: COMPILER - NO WARNINGS       QAC - 1 warning
*****************************************************************************/

/****************************************************************************
**  Date: 03/Sep/2010     by: AFERRIS2        Ref:
**  Change: 1.  Add callback to source feature to notify special actions taken
**              by sequencer.
**          2.  Corrected the checking of message ID for timeout detection.
**              (uninitialised variable seq_CurrentMessageID)
**          3.  Add minimum display time for alerts.
**          4.  Add standard interface function to obtain the current alert
**              message information.
**
**  Checks: COMPILER - NO WARNINGS       QAC - 2 warnings
*****************************************************************************/

/****************************************************************************
**  Date: 15/Sep/2010     by: AFERRIS2        Ref:
**  Change: 1.  Change interface for MSG_DISPLAY_SHOW().  We now pass a pointer
**              to a MSG_VIEWINFO_T structure so that the ID and number of
**              messages are available.
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 16/Sep/2010     by: AFERRIS2        Ref:
**  Change: 1.  Corrected actions when a message is re-triggered and that message
**              has already been transferred t0 the client.  In this instance,
**              the message also needs to be cleared from the client.
**
**  Checks: COMPILER - NO WARNINGS       QAC - 2 WARNINGS
*****************************************************************************/

/****************************************************************************
**  Date: 01/Oct/2010     by: AFERRIS2        Ref:
**  Change: 1.  Changed event callback qualifier to the condition qualifier value
**              to allow one function to be used (in the same way as the condition
**              active detection).
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 19/Oct/2010     by: AFERRIS2        Ref: BSDI00094247, BSDI00094325
**  Change: 1.  Remove Hold Message if this is no longer the message being
**              displayed (held message was not being removed from Message list
**              when a higher priority message was triggered) (BSDI00094247)
**          2.  Remove a new message before adding it to the message list.  This
**              stops a message being registered many times (normally due to
**              re-triggering the message). (BSDI00094325)
**          3.  New function seq_GetCategories() to obtain which categories
**              contain active messages. (work in progress)
**
**  Checks: COMPILER - NO WARNINGS       QAC - 2 WARNINGS
*****************************************************************************/

/****************************************************************************
**  Date: 20/Oct/2010     by: AFERRIS2        Ref:
**  Change: 1.  Updated seq_GetCategories() to allow checking for more than a
**              specified number of messages in a category.
**
**  Checks: COMPILER - NO WARNINGS       QAC - 2 WARNINGS
*****************************************************************************/

/****************************************************************************
**  Date: 27/04/2011     by: AFERRIS2        Ref: DCR 2131
**  Change: 1.  New feature: Add message cycling if enabled in the configuration
**              for each message.
**
**  Checks: COMPILER - NO WARNINGS       QAC - 3 WARNINGS
*****************************************************************************/

/****************************************************************************
**  Date: 04/05/2011     by: AFERRIS2        Ref: BSDI00100084, BSDI00102410
**  Change: 1.  Updated view message handling so that removing the currently
**              viewed message causes the next message to be shown.
**          2.  Corrected typo in seq_GetViewCount() parameter name.
**          3.  Added new standard interface to check if specified message is active
**
**  Checks: COMPILER - NO WARNINGS       QAC - 3 WARNINGS
*****************************************************************************/

/****************************************************************************
**  Date: 18/05/2011     by: AFERRIS2        Ref: BSDI00104411
**  Change: 1.  Clear HOLD message when the held message is re-triggered. This
**              is needed since the re-triggered message is no longer being HELD,
**              and thus prevents the message from being removed when the HOLD
**              timer expires.
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 25/06/2011     by: jmanojku        Ref: BSDI00106827
**  Change: 1.  add to store msg queue only if the HOLD msg id is undefined
**              This is to avoid to store the deactivated msg in the store queue
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 12/07/2011     by: vsarava2        Ref: PR-45788
**  Change: 1. Msg ID condition check updated to confirm coding standard.
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 12/07/2011     by: vsarava2        Ref: BSDI00105821 (DCR 2131)
**  Change: 1. Msg Recycle bitwise flag added to identify whether message is
**             already shown or not.
**          2. Status added in VIEW_INFO_T to indicate message cycled first time
**             or it is a RECYCLED message
**  Checks: COMPILER - NOT CHECKED       QAC - 8 warning
*****************************************************************************/

/****************************************************************************
**  Date: 26/07/2011     by: vsarava2        Ref: PR 46208
**  Change: 1. Peer review comments fixed.
**
**  Checks: COMPILER - NOT CHECKED       QAC - 8 warning
*****************************************************************************/

/****************************************************************************
**  Date: 01/08/2011     by: vsarava2        Ref: PR 46208
**  Change: 1. PR Fix. Clearing of Msg_recyleflag moved to Seq Removemessage
**             function to avoid to clearing of held message recycle flag.
**
**  Checks: COMPILER - NOT CHECKED       QAC - 8 warning
*****************************************************************************/

/****************************************************************************
**  Date: 02/08/2011     by: vsarava2        Ref: BSDI00107717
**  Change: Clear the CYCLE timer when warning is removed from sequncer Q by
**          acknowledge, removal trigger condition or timeout
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 11/10/2011     by: vsarava2        Ref: PR-46795
**  Change: Clear the CYCLE timer when warning is removed from sequncer Q only
**          if seq_CurrentMessageID is same as removable message ID.
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 1/11/2011     by: vsarava2        Ref: Functional test defect
**  Change: Update the Seq ViewMessage structure when message is timedout.
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 12/Mar/2012     by: vsarava2        Ref: BSDI00112440 /BSDI00111853
**  Change: 1. Seq Retrigger option added to restart the message again if it
**             is currently showing in display
**
**  Checks: COMPILER - NO WARNINGS       QAC - 2 WARNINGS
*****************************************************************************/

/****************************************************************************
**  Date: 04/JUL/2012     by: vsarava2        Ref: BSDI00113831 / PR-46795
**  Change: The minimum hold time shall be maintained whenever the
**          SequencerShow is called by application.
**
**  Checks: COMPILER - NO WARNINGS       QAC - 2 WARNINGS
*****************************************************************************/
/****************************************************************************
**  Date: 04/Jul/2012     by: pvazhung        Ref: BSDI00115725
**  Change: Upadted the msg_SequencerUpdate function inorder to handle cycle
**          option till warnings total time out.
**          added one couter array, seq_DsplyTimeList to store warnings
**          total display time out, this counter value will be decremented
**          appropriately and remove the message from the que if the value
**          reaches zero.
**
**  Checks: COMPILER - NO WARNINGS       QAC - 2 WARNINGS
*****************************************************************************/
/****************************************************************************
**  Date: 09/Jul/2012     by: pvazhung        Ref: PR56812
**  Change: 1. Removal of warnings has been done by checking
**             total display time.
**  Checks: COMPILER - NO WARNINGS       QAC - 2 WARNINGS
*****************************************************************************/
/****************************************************************************
**  Date: 09/Jul/2012     by: pvazhung        Ref: PR56812
**  Change: 1. Moved seq_MsgeDisplayTime() above the test function.
**          2. SEQ_1SEC_TIMER_ID cleared in msg_SequencerInitialise fn.
**          3. Renamed static UINT16 seq_MsgeDisplayTime() to
**          static UINT16 seq_MsgDisplayTime()
**  Checks: COMPILER - NO WARNINGS       QAC - 2 WARNINGS
*****************************************************************************/
/****************************************************************************
**  Date: 05/Apr/2013     by: adevi        Ref: PR64284
**  Change: 1. Introduced compiler switch DISP_TOUT_NO_TOUT_MSG_BY_PRIORITY to
**          display the time out and no time out messages based on priority.
**          2. Compiler switch ALLOW_CURRENT_DURING_DISP_INDICATION_TIME to
**          continue with the currently displayed message for which
**          MSG_OPTION_DISP_INDICATIONTIME is enabled.
**          3. MSG_OPTION_ALLOW_INACTIVE_TO_TIMEOUT which allows the message
**          to get timed out even if it gets deactivated.
**  Checks: COMPILER - NO WARNINGS       QAC - 2 WARNINGS
*****************************************************************************/

/****************************************************************************
**  Date: 05/Jun/2013     by: vsarava2        Ref: RTC 65395
**  Change: 1. Ack Aft Min timer started in Seq Show, and macro defined for
that timer.
**  Checks: COMPILER - NO WARNINGS       QAC -
*****************************************************************************/

/****************************************************************************
**  Date: 26/Jul/2013     by: vsarava2        Ref: RTC 73978
**  Fixed the Compiler(IAR) prototype warning as per project request.
*****************************************************************************/

/****************************************************************************
**  Date: 10/Aug/2013     by: vsarava2        Ref: RTC 60620
**  Msg Option-Allow Inactive Msg to Timeout is checked along with Powermode
**  based on P552 requirement.
*****************************************************************************/

/****************************************************************************
**  Date: 25/Aug/2013     by: vsarava2        Ref: RTC 91916
**  New warning Seq Q timeout implementation to support Honda requirements.
*****************************************************************************/


/****************************************************************************
**  Date: 27/Dec/2013     by: adevi        Ref: RTC 91916, PR 70887, PR68669
**  Change: Peer review comments for New message queue time out and
acknowledge after minimum time out implementation fixed. Improvements
added for compiler switch DISP_TOUT_NO_TOUT_MSG_BY_PRIORITY
1. Seq_NewMsgQTimeout_U16[] array declared as UINT8.
2. seq_AckAftMinToutTimer cleared in init & change in messageID.
3. CurrentlyDisplayingNewMsgFlag is reset when queue is empty.
4. seq_DispIndTimer started only when NewMessageFlag is set.
5. HMI_MSG_Q_1SEC_TIMER_VAL is loaded to start NewMsgQueue timer
6. seq_MsgQTimeout_1SecTimer cleared when list is empty.

*****************************************************************************/

/****************************************************************************
**  Date: 27/Dec/2013     by: adevi            Ref: RTC 91917
**  Change: 1. Introduced compiler switch   MSG_OLD_WRNG_REPETITION to allow
**  repetition of an old warning. 
**  2.  If MSG_OPTION_OLD_WRNG_REPEAT is enabled then warnings which are old
**  will be made new after the old warning repetition duration.
*****************************************************************************/

/****************************************************************************
**  Date: 09/Jan/2014     by: adevi            Ref: PR 72449
**  Change: 1. Array Seq_NewMsgQTimeout_U16 changed to Seq_NewMsgQTimeout_U8
**  2. HMI_MSG_SEQ_TIMEOUT_INVALID_U16 --> HMI_MSG_SEQ_TIMEOUT_INVALID_U8.
**  3. In msg_SequencerRetrigger function changes on 26 Nov merged.
**     Ref: RTC 101534, 102995.
**  4. Clearing seq_OldWrng_Rep_1SecTimer & seq_MsgQTimeout_1SecTimer removed
**     from msg_SequencerOldWrngRepUpdate & msg_SequencerNewMsgQTimeoutUpdate.
**  5. Flag MsgAddedFromStoreQueue added.
*****************************************************************************/

/****************************************************************************
**  Date: 28/Apr/2014     by: adevi            Ref: Bug 192
**  Change: 1. Introduced compiler switch HMI_MSG_UNIQUE_DISP_IND_TIME to allow
**  configuration of unique new warning display time for every message.
**  If the new warning display time is the same for all the messages then
**  HMI_MSG_UNIQUE_DISP_IND_TIME need not be defined.  The common new warning
**  display time can be configured in the macro HMI_MSG_DISP_IND_TIME.
*****************************************************************************/

/****************************************************************************
**  Date: 28/Apr/2014     by: adevi            Ref: Bug 192, PR 75682
**  Change: 1. Peer review comments fixed.  Timeout value of hold timeout and
**  dispIndTimeout checked against 0 before starting.
*****************************************************************************/

/****************************************************************************
**  Date: 06/Jun/2014     by: adevi            Ref: 206
**  Change: 1. Implemented new feature of showing message from a category 
**  alternately.  The category from which msg need to be displayed alternately
**  will be configured in the sequencer.cfg file.
*****************************************************************************/

/****************************************************************************
**  Date: 18/Jun/2014     by: adevi            Ref: 206, RTC ID: 154152
**  Change: 1. Peer review comments of PR ID 77295 updated.  Recycle flag of
**  message to be shown alternately set during cycling.
*****************************************************************************/

/****************************************************************************
**  Date: 6/Oct/2014     by: adevi            Ref: RTC ID: 203838, 212587
**  Change: 1. New message Queue timer resolution changed from 1 sec.  It can
**             be configured from 100ms to 1000ms.
**          2. Hold timer and display timer status is checked along with the
**             time out values.
**          3. New message status informed to application throught MSG_NEW bit
**          4.  Ack after min timeout will be applicable only for new messages.  
*****************************************************************************/

/****************************************************************************
**  Date: 10/Feb/2015     by: adevi        Ref:RTC 270544
**  Change: Compiler warnings resolved for Honda THAA
*****************************************************************************/

/****************************************************************************
**  Date: 19/Feb/2015     by: adevi        Ref:RTC 203838, PR 79993
**  Change: Review comment fix.  MSG_NEW status updated in seq_SetViewMessage
**          and msg_SequencerSelectFirst. 
*****************************************************************************/

/****************************************************************************
**  Date: 06/Apr/2015     by: adevi        Ref:RTC 309113, 319901
**  Change: Issue fix 1 - Issue in W207, where the timers were not started in the
**  next round robin cycle after MSG_DISPLAY_SHOW, so the display indication
**  timer was not getting started and since the status was not running, the 
**  new message flag was getting cleared.
**  Issue fix 2 - Issue in Honda TG7A where an old warning which was cycling was
**  retriggered, since the warning is old the low priority new warning was coming 
**  to display, the retriggered warning was getting replaced by the low priority new
**  warning.  So the new message flag was forcefully set whenever retrigger is given.
*****************************************************************************/

/****************************************************************************
**  Date: 10/Apr/2015     by: adevi        Ref:RTC 319901
**  Change: MSG_EVENT_OLD provided when seq_dispIndTimer expires and the newmessage
**  flag is getting cleared due to timer expiry.
*****************************************************************************/ 

/****************************************************************************
**  Date: 29/Apr/2015     by: adevi        Ref:RTC 324544, 324551, 321446
**  Introduced new option MSG_OPTION_REM_FRM_SEQ_IN_NA_IGN_MODE for Hyundai.
**  seq_GetHighPrioNewMessage function added and used for Hyundai req to display
**  only the highest priority message of a low priority category and not to interrupt
**  same priority messages in same category.
**  RTC 324544 - Issue in P552 since when display timer status is checked the display time
**  out value should be of the seqCurrentMessageId but pMessage was holding MessageList[0]
**  so issue corrected by using currentMessage.
**  Peer review comment fix for 79993.  Variable currentMessageOptions introduced.
*****************************************************************************/ 

/****************************************************************************
**  Date: 29/Jun/2015     by: adevi        Ref: RTC 365702, 366678
**  Change: QAC warnings resolved for Honda THAA. 
**  Change: Introduced event MSG_EVENT_NEW_MSGQ_TIMEOUT for hyundai. When the 
**  seq_NewMessgaeQueueTimeout value configured for the message, the message will
**  be removed from sequencer queue and seq_callback will be invoked by message
**  core with this event.
*****************************************************************************/

/****************************************************************************
**  Date: 13/Aug/2015     by: adevi        Ref: RTC 341916, 373891
**  Change: Issue fix for Honda TG7A.  The cycle timer will be cleared only when
**  a message of high priority category or message in the same category gets 
**  added in the sequencer queue.
*****************************************************************************/
/****************************************************************************
**  Date: 21/Sep/2015     by: aperumal        Ref: RTC 427405
**  Change: Included Undefined message check to avoid out of bound access
**  to messageList and seq_Old_Wrng_RepDuration
*****************************************************************************/

/****************************************************************************
**  Date: 24/Sep/2015     by: adevi        Ref: RTC 430173
**  Change: Introduced configuration ALLOW_HIGH_PRIORITY_IMMEDIATELY_DURING_OVERRIDE 
**  Details about the macro provided in hmi_msgSequencer.cfg. 
*****************************************************************************/

/****************************************************************************
**  Date: 21/Dec/2015     by: adevi        Ref: RTC 448272
**  Change: Introduced configuration ALLOW_LOW_PRIORITY_UNDISPLAYED_MSG_IMMEDIATELY
**  Removed configuration ALLOW_HIGH_PRIORITY_IMMEDIATELY_DURING_OVERRIDE 
**  Details about the macro provided in hmi_msgSequencer.cfg. 
*****************************************************************************/

/****************************************************************************
**  Date: 04/Nov/2016     by: adevi        Ref: RTC 739040
**  Change: Validation done while adding msg with new message queue timeout.
*****************************************************************************/

/****************************************************************************
**  Date: 04/May/2017     by: arajase2
**  Ref: RTC 859438: CMFB MISRA Warning fixes - message.core
**  Change: MISRA warnings resolved for CMFB
*****************************************************************************/
/****************************************************************************
**  Date: 14/Jun/2017     by: arajase2
**  Ref: RTC 888114: CMFB MISRA Warning fixes message core- SPRINT 43
**  Change: MISRA warnings resolved for CMFB
*****************************************************************************/
/****************************************************************************
**  Date: 13/Jul/2017     by: arajase2
**  Ref: 910159: Message core update for insert new message after the current one
**  Change: Added MSG_OPTION_INS_AFT_CUR macro in message options and seq_InsertMessage
**  function modified to insert the message after the current active message.
**  Assumption:
**      1. Incoming message should be of the same category of the current message
**      2. If MSG_OPTION_INS_AFT_CUR is set for the new incoming message, priority
**    will not be considered for the message insertion
*****************************************************************************/
/****************************************************************************
**  Date: 12/Mar/2018     by: arajase2
**  Ref: 1063563: MMC : Msg Core - update for Auto cancel warning requirement
**  Change: Added MSG_OPTION_AUTO_CANCEL macro in message options and seq_GetNextMessage
**  function modified to handle auto cancel warnings
**  Requirement:
**      1. New option should be provided to handle auto cancel warnings
**      2. If MSG_OPTION_AUTO_CANCEL is set, then this warnings should be cycled only when
**  there is any non auto cancel warnings exists in the queue
*****************************************************************************/
/****************************************************************************
**  Date: 7/June/2018     by: adevi
**  Ref: 1126131: Warning hold time needs to be continued for deactivated warnings.
**  Change: New configuration MSG_MMC_RETAIN_NEW_MSG_DURING_HOLD introduced
*****************************************************************************/
/* end of file =============================================================*/

