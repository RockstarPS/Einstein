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
** Name:           hmi_msgStore.c
**
** Description:    Message Core Component.  This module handles the storage
**                  and erview of messages that have been dismissed.
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**==========================================================================*/
#define hmi_msgStore_C

/*==========================================================================*/
/*  I N C L U D E   F I L E S                                               */
/*==========================================================================*/
#include "system.h"
#include "hmi_msgStore.h"
#include "hmi_msgStore.cfg"
#include "localSemaphores.h"

/*==========================================================================*/
/* I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S    */
/*==========================================================================*/

/*----------------------------------------------------------------------*/
/* Set optimisation OFF (useful for debugging)                          */
/*----------------------------------------------------------------------*/
/* #pragma optimization_level as 0 */


/*==========================================================================*/
/* I N T E R N A L   F U N C T I O N   P R O T O T Y P E S                  */
/*==========================================================================*/
static void stor_InitIndex(UINT8 inst);
static void stor_InitList(UINT8 inst);

static void stor_UpdateViewer(eMessageIdentity MessageID,UINT8 inst);
static void stor_IndexUp(UINT16 BaseCategory,UINT8 inst);
static void stor_IndexDown(UINT16 BaseCategory,UINT8 inst);
static void stor_Delete(UINT32 Index,UINT8 inst);
static void stor_Insert(UINT32 Index, eMessageIdentity Value);
static UINT16 stor_GetViewCount(UINT32 CategaoryMask,UINT8 inst);
static UINT16 stor_GetViewIndex(eMessageIdentity MessageID, UINT32 CategoryMask,UINT8 inst);

static UINT32 stor_FindFirstIndex(UINT32 CategoryMask,UINT8 inst);
static UINT32 stor_FindNextIndex(UINT32 Start, UINT32 CategoryMask,UINT8 inst);
static UINT32 stor_FindPreviousIndex(UINT32 Start, UINT32 CategoryMask,UINT8 inst);

/*==========================================================================*/
/* M E M O R Y   A L L O C A T I O N                                        */
/*==========================================================================*/
eMessageIdentity stor_MessageList[MSG_NUM_INSTANCES][MSG_NUM_MESSAGES + 1];

#ifdef MSG_ACK_WRNG_REPETITION
BOOLEAN l_MsgAddedFromStoreQueue[MSG_NUM_INSTANCES];
#ifdef MSG_ACK_WRNG_REPEAT_TIMER_CONTROL
static eAckWrngRepTimerStatus stor_AckWrng_Rep_TimerStatus[MSG_NUM_INSTANCES];
#endif
#endif
static UINT16 stor_Categories[MSG_NUM_INSTANCES][MSG_NUM_MESSAGE_CATEGORIES + 1];
static MSG_VIEWINFO_T stor_ViewMessage[MSG_NUM_INSTANCES];
static UINT32 stor_ViewMask;

/*-------------------------------------------------------------------------------*/
/* Bitfield flag to indicate whether the message is present in store queue or not */
/*-------------------------------------------------------------------------------*/
static LOCAL_SEMAPHORES(stor_StoredFlags, MSG_NUM_MESSAGES);

#define STOR_LAST_INDEX(inst)    (stor_Categories[inst][MSG_NUM_MESSAGE_CATEGORIES])


#ifdef MSG_ACK_WRNG_REPETITION
/*--------------------------------------------------------------------------*/
/* Array that holds the ack warning repetition duration of every message    */
/*--------------------------------------------------------------------------*/


static UINT8 stor_Ack_Wrng_RepDuration[MSG_NUM_MESSAGES + 1];
#if defined ENABLE_PRIVATE_TIMERS
/* Timer used for calculation for ack warning repetition */
#if MSG_NUM_INSTANCES > 1
#error "More than one instance check is not available for private timers"
#else
static TIMER  stor_AckWrng_Rep_Timer;
#endif
#endif
#endif





/*==========================================================================*/
/* E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S      */
/*==========================================================================*/

void msg_StoreInitialise(UINT8 inst)
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Message store initialisation
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
    stor_InitIndex(inst);
    stor_InitList(inst);
    stor_ViewMessage[inst].Id = MSG_INDEX_UNDEFINED;
    stor_ViewMessage[inst].Count = 0;
    stor_ViewMessage[inst].Position = 0;
    stor_ViewMessage[inst].InstanceID     = inst;
    stor_ViewMask = MSG_ALL_CATEGORIES;
#ifdef MSG_ACK_WRNG_REPETITION
    /* Timer used for 1 second calculation for ack warning repetition */
    MSG_CLEAR_SW_TIMER(hmi_msg_inst_config_table[inst].stor_AckWrng_Rep_Timer);
    l_MsgAddedFromStoreQueue[inst] = (BOOLEAN)MSG_NOT_ADDED_FROM_STORE_QUEUE;
#ifdef MSG_ACK_WRNG_REPEAT_TIMER_CONTROL 
    stor_AckWrng_Rep_TimerStatus[inst] = ACK_WRNG_REP_TIMER_RESTART;
#endif
#endif
    CLEAR_ALL_SEMAPHORES(stor_StoredFlags);
  }
}



#if MSG_NUM_INSTANCES > 1
NULSIF_STANDARD_INTERFACE_MULTI_INST(msg_StoreSelectFirst)
#else 
NULSIF_STANDARD_INTERFACE(msg_StoreSelectFirst)
#endif
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Standard interface function to select the first message in
**                  the store list that matches the given category mask.
**
**  Parameters:     Data:       ID of first message
**                              (MSG_INDEX_UNDEFINED if none available)
**
**  Returns:        sif_OK (always)
**----------------------------------------------------------------------------
** Created: AFERRIS2 12/Apr/2010
**==========================================================================*/
{


  eMessageIdentity messageID;
  MSG_VIEWINFO_T *retData = (MSG_VIEWINFO_T *)SIF_GET_DATA_REF();
  UINT32 index;


#if (MSG_NUM_INSTANCES > 1)
  UINT8 inst = p_inst;
  if(inst < MSG_NUM_INSTANCES)
#else 
  UINT8 inst = 0u;
#endif
  /*----------------------------------------------------------------------*/
  /* Obtain value that has been requested.                                */
  /*----------------------------------------------------------------------*/

  {    
    index = stor_FindFirstIndex(stor_ViewMask,inst);
    if (index  <= hmi_msg_inst_config_count[inst])
    {
      messageID = stor_MessageList[inst][index];

      stor_ViewMessage[inst].Id       = messageID;
      stor_ViewMessage[inst].Position = 0;
      stor_ViewMessage[inst].Count    = stor_GetViewCount(stor_ViewMask,inst);
      stor_ViewMessage[inst].InstanceID     = inst;

      /*----------------------------------------------------------------------*/
      /* Store data if caller provided a valid pointer.                       */
      /*----------------------------------------------------------------------*/
      if (SIF_ISVALID_DATA())
      {
        retData->Count    = stor_ViewMessage[inst].Count;
        retData->Position = stor_ViewMessage[inst].Position;
        retData->Id       = stor_ViewMessage[inst].Id;
        retData->InstanceID = stor_ViewMessage[inst].InstanceID;
      }
    }
  }
  return sif_OK;
}

#if MSG_NUM_INSTANCES > 1
NULSIF_STANDARD_INTERFACE_MULTI_INST(msg_StoreSelectNext)
#else 
NULSIF_STANDARD_INTERFACE(msg_StoreSelectNext)
#endif
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Standard interface function to obtain the next message in
**                  the store list that matches the given category mask.
**
**  Parameters:     Data:       ID of next message
**                              (MSG_INDEX_UNDEFINED if none available)
**
**  Returns:        sif_OK:     Next message is valid
**                  sif_ERROR:  Next message not available
**----------------------------------------------------------------------------
** Created: AFERRIS2 12/Apr/2010
**==========================================================================*/
{

  MSG_VIEWINFO_T *retData = (MSG_VIEWINFO_T *)SIF_GET_DATA_REF();
  UINT32 index;
  SIF_STATUS retVal = sif_OK;

#if (MSG_NUM_INSTANCES > 1)
  UINT8 inst = p_inst;
  if(inst < MSG_NUM_INSTANCES)
#else 
  UINT8 inst = 0u;
#endif
  {

    /*----------------------------------------------------------------------*/
    /* Obtain value that has been requested.                                */
    /*----------------------------------------------------------------------*/
    index = stor_GetViewIndex(stor_ViewMessage[inst].Id, MSG_ALL_CATEGORIES,inst);
    index = stor_FindNextIndex(index + 1UL, stor_ViewMask,inst);

    /*----------------------------------------------------------------------*/
    /* Handle attempt to go past the end of the list                        */
    /*----------------------------------------------------------------------*/
    if (index == STOR_LAST_INDEX(inst))
    {
#if(MSG_STORE_VIEWER_OPTIONS == OPTION_VIEWER_WRAP)
      {
        /*--------------------------------------------------------------*/
        /* Find first if wrapping is enabled                            */
        /*--------------------------------------------------------------*/
        index = stor_FindFirstIndex(stor_ViewMask,inst);

        stor_ViewMessage[inst].Id = stor_MessageList[inst][index];
        stor_ViewMessage[inst].Position = stor_GetViewIndex(stor_ViewMessage[inst].Id, stor_ViewMask,inst);			
        stor_ViewMessage[inst].InstanceID     = inst;
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
      stor_ViewMessage[inst].Id = stor_MessageList[inst][index];
      stor_ViewMessage[inst].Position = stor_GetViewIndex(stor_ViewMessage[inst].Id, stor_ViewMask,inst);
      stor_ViewMessage[inst].InstanceID     = inst;
    }

    /*----------------------------------------------------------------------*/
    /* Store data if caller provided a valid pointer.                       */
    /*----------------------------------------------------------------------*/
    if (SIF_ISVALID_DATA())
    {
      retData->Count    = stor_ViewMessage[inst].Count;
      retData->Position = stor_ViewMessage[inst].Position;
      retData->Id       = stor_ViewMessage[inst].Id;
      retData->InstanceID     = stor_ViewMessage[inst].InstanceID;
    }
  }
  return retVal;
}

#if MSG_NUM_INSTANCES > 1
NULSIF_STANDARD_INTERFACE_MULTI_INST(msg_StoreSelectPrevious)
#else 
NULSIF_STANDARD_INTERFACE(msg_StoreSelectPrevious)
#endif
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Standard interface function to obtain the previous message in
**                  the store list that matches the given category mask.
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
    MSG_VIEWINFO_T *retData = (MSG_VIEWINFO_T *)SIF_GET_DATA_REF();
    UINT32 index;
    /*----------------------------------------------------------------------*/
    /* Obtain value that has been requested.                                */
    /*----------------------------------------------------------------------*/
    index = stor_GetViewIndex(stor_ViewMessage[inst].Id, MSG_ALL_CATEGORIES,inst);
    index = stor_FindPreviousIndex(index, stor_ViewMask,inst);

    /*----------------------------------------------------------------------*/
    /* Handle attempt to go past the end of the list                        */
    /*----------------------------------------------------------------------*/
    if (index == STOR_LAST_INDEX(inst))
    {
#if(MSG_STORE_VIEWER_OPTIONS == OPTION_VIEWER_WRAP)
      {
        /*--------------------------------------------------------------*/
        /* Find first if wrapping is enabled                            */
        /*--------------------------------------------------------------*/
        index = (UINT16)stor_FindPreviousIndex(STOR_LAST_INDEX(inst), stor_ViewMask,inst);
        stor_ViewMessage[inst].Id = stor_MessageList[inst][index];
        stor_ViewMessage[inst].Position = stor_GetViewIndex(stor_ViewMessage[inst].Id, stor_ViewMask,inst);
        stor_ViewMessage[inst].InstanceID     = inst;
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
      stor_ViewMessage[inst].Id = stor_MessageList[inst][index];
      stor_ViewMessage[inst].Position = stor_GetViewIndex(stor_ViewMessage[inst].Id, stor_ViewMask,inst);
      stor_ViewMessage[inst].InstanceID     = inst;
    }

    /*----------------------------------------------------------------------*/
    /* Store data if caller provided a valid pointer.                       */
    /*----------------------------------------------------------------------*/
    if (SIF_ISVALID_DATA())
    {
      retData->Count    = stor_ViewMessage[inst].Count;
      retData->Position = stor_ViewMessage[inst].Position;
      retData->Id       = stor_ViewMessage[inst].Id;
      retData->InstanceID     = stor_ViewMessage[inst].InstanceID;
    }
  }
  return retVal;
}

#if MSG_NUM_INSTANCES > 1
NULSIF_STANDARD_INTERFACE_MULTI_INST(msg_StoreGetCurrent)
#else 
NULSIF_STANDARD_INTERFACE(msg_StoreGetCurrent)
#endif
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Get number of messages in teh STORE list.
**
**  Parameters:     *Data:      Where data will be stored.
**                  *Unused:    Required by caller. Not used.
**                 [Size:       Number of elements to return]
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 27/Apr/2010
**==========================================================================*/
{
  MSG_VIEWINFO_T *retData = (MSG_VIEWINFO_T *)SIF_GET_DATA_REF();

#if (MSG_NUM_INSTANCES > 1)
  UINT8 inst = p_inst;
  if(inst < MSG_NUM_INSTANCES)
#else 
  UINT8 inst = 0u;
#endif
  {
    /*----------------------------------------------------------------------*/
    /* Get and store data if caller provided a valid pointer.               */
    /*----------------------------------------------------------------------*/
    if (SIF_ISVALID_DATA())
    {
      retData->Count    = stor_ViewMessage[inst].Count;
      retData->Position = stor_ViewMessage[inst].Position;
      retData->InstanceID = stor_ViewMessage[inst].InstanceID;
      retData->Id       = stor_ViewMessage[inst].Id;
    }
  }
  return sif_OK;
}

static UINT16 stor_GetViewCount(UINT32 CategaoryMask,UINT8 inst)
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
    eMessageIdentity iMessage;
    UINT32 fl_index;
    UINT32 categoryValue;
    /*------------------------------------------------------------------*/
    /* Loop through the whole list to find all entries that match.      */
    /*------------------------------------------------------------------*/
    for (fl_index=0; fl_index < STOR_LAST_INDEX(inst); fl_index++)
    {
      /*--------------------------------------------------------------*/
      /* Get pointer to message definition.                           */
      /*--------------------------------------------------------------*/
      iMessage = stor_MessageList[inst][fl_index];
      if (iMessage < MSG_NUM_MESSAGES)
      {
        thisMessage = &messageList[iMessage];

        categoryValue = (1UL << (UINT8)thisMessage->Category);
        if (TESTBIT(CategaoryMask, categoryValue))
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


void msg_StorePurgeFromList(UINT32 FilterOptions,UINT8 inst)
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Purge messages from the list.  Only Messages selected by the
**                  FilterOptions parameter are passed to the purge action function.
**
**  Parameters:     FilterOptions:  Mask to select which messages are purged
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 12/Apr/2010
**==========================================================================*/
{

  if(inst < MSG_NUM_INSTANCES)
  {
    UINT32 fl_index;

    for (fl_index = STOR_LAST_INDEX(inst); fl_index != 0UL; fl_index--)
    {
      eMessageIdentity aMessage = stor_MessageList[inst][fl_index-1UL];
      if (aMessage < MSG_NUM_MESSAGES)
      {
        if (TESTBIT(messageList[aMessage].Options, (UINT32)(FilterOptions)) )
        {
          UINT32 fl_remove_messageID;
          MSG_STORE_PURGE(aMessage);
          fl_remove_messageID = fl_index-1UL;
          (void)msg_StoreRemove((eMessageIdentity)(fl_remove_messageID));
        }
      }
    }
    stor_UpdateViewer((eMessageIdentity)0,inst);
  }
}


void msg_StoreAdd(eMessageIdentity MessageID)
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Adds a new message into the message store.  Action is dependant
**                  on the message options.  If MSG_OPTION_STORE is set, the
**                  message is added to the store, otherwise the message is
**                  transferred directly to the client (if defined).
**
**  Parameters:     MessageID:  ID of the message to be added.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 12/Apr/2010
**==========================================================================*/
{
    if (MessageID < MSG_NUM_MESSAGES)
    {
        MSG_MESSAGE_STRUCT const * thisMessage;
        UINT32 thisIndex;
        UINT32 endIndex;
        UINT8 inst;
        thisMessage = &messageList[MessageID];
        inst = thisMessage->InstanceID;
        if(inst < MSG_NUM_INSTANCES)
        {
            if (TESTBIT(thisMessage->Options, (UINT32)MSG_OPTION_STORE))
            {
                /*------------------------------------------------------------------*/
                /* Message can be stored.                                           */
                /*------------------------------------------------------------------*/
                thisIndex = stor_Categories[inst][(UINT32)thisMessage->Category];
                endIndex = stor_Categories[inst][(UINT32)thisMessage->Category + 1UL];

                /*--------------------------------------------------------------*/
                /* Locate priority position and insert message in list.         */
                /*--------------------------------------------------------------*/

                while (thisIndex < endIndex)
                {
                    if(thisIndex < hmi_msg_inst_config_count[inst])
                    {
                        eMessageIdentity aMessage = stor_MessageList[inst][thisIndex];
                        if (aMessage < MSG_NUM_MESSAGES)
                        {
                            MSG_MESSAGE_STRUCT const *ptrMessage = &messageList[aMessage];

#ifdef STORE_QUEUE_FIFO
                            /* If the store queue should have msg first validated at the top */
                            if ((thisMessage->Priority < ptrMessage->Priority))
                            {
                                break;
                            }
#else
                            if ((thisMessage->Priority <= ptrMessage->Priority))
                            {
                                break;
                            }
#endif
                        }
                    }
                    thisIndex++;
                }
                stor_Insert((UINT16)thisIndex, MessageID);
                stor_IndexUp((UINT16)thisMessage->Category + 1U,inst);
                stor_UpdateViewer(MessageID,inst);
                
                SET_SEMAPHORE(stor_StoredFlags, MessageID);
#ifdef MSG_ACK_WRNG_REPETITION
                if (TESTBIT(thisMessage->Options, (UINT32)MSG_OPTION_ACK_WRNG_REPEAT))
                {
                    /*--------------------------------------------------------------*/
                    /* The warning has now been acknowledged so load ack warning    */
                    /* repeat duration in the stor_Ack_Wrng_RepDuration array         */
                    /*--------------------------------------------------------------*/
                    UI_MSG_FLOAT32 stor_Ack_Wrng_RepDuration_f = ((UI_MSG_FLOAT32)HMI_MSG_ACK_WRNG_REP_DURATION * HMI_MSG_ACK_REP_TIMER_RESLN_FACTOR); /* Variable added to fix MISRA warning */
                    stor_Ack_Wrng_RepDuration[MessageID] = (UINT8)stor_Ack_Wrng_RepDuration_f;
                }
                else
                {
                    stor_Ack_Wrng_RepDuration[MessageID] = HMI_MSG_ACK_WRNG_REP_INVALID_U8;
                }
#endif
            }
            else
            {
                /*------------------------------------------------------------------*/
                /* Message is not stored.  Transfer to client.                      */
                /*------------------------------------------------------------------*/
                MSG_STORE_CLIENT_ADD(MessageID);
            }
        }
    }
}

BOOLEAN msg_StoreRemove(eMessageIdentity MessageID)
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Remove a message from the message store.
**
**  Parameters:     MessageID:  ID of the message to be removed.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 12/Apr/2010
**==========================================================================*/
{
    BOOLEAN found = FALSE;

    if (MessageID < MSG_NUM_MESSAGES)
    {
        MSG_MESSAGE_STRUCT const * thisMessage;
        UINT32 thisIndex;
        UINT32 endIndex;
        UINT8 inst;
        thisMessage = &messageList[MessageID];
        inst = thisMessage->InstanceID;
        if(inst < MSG_NUM_INSTANCES)
        {
            if (TESTBIT(thisMessage->Options, (UINT32)MSG_OPTION_STORE) )
            {
                /*------------------------------------------------------------------*/
                /* Message can be stored so could be in the list.                   */
                /*------------------------------------------------------------------*/
                thisIndex = stor_Categories[inst][(UINT32)thisMessage->Category];
                endIndex = stor_Categories[inst][(UINT32)thisMessage->Category + 1UL];

                /*------------------------------------------------------------------*/
                /* Locate message in the list and remove it.                        */
                /*------------------------------------------------------------------*/

                while (thisIndex < endIndex)
                {
                    if(thisIndex < hmi_msg_inst_config_count[inst])
                    {
                        if (stor_MessageList[inst][thisIndex] == MessageID)
                        {
                            stor_Delete(thisIndex,inst);
                            MSG_STORE_CLIENT_REMOVE(MessageID);
                            stor_IndexDown((UINT16)thisMessage->Category + 1U,inst);
                            stor_UpdateViewer(MessageID,inst);
                            CLR_SEMAPHORE(stor_StoredFlags, MessageID);
                      
                            found = TRUE;
                            break;
                        }
                    }
                    thisIndex++;
                }
#ifdef MSG_ACK_WRNG_REPETITION
                if (TESTBIT(thisMessage->Options, (UINT32)MSG_OPTION_ACK_WRNG_REPEAT))
                {
                    /*--------------------------------------------------------------*/
                    /* Load invalid value in ack warning repetition duration array  */                                           
                    /*--------------------------------------------------------------*/
                    stor_Ack_Wrng_RepDuration[MessageID] = HMI_MSG_ACK_WRNG_REP_INVALID_U8;
                }
#endif
            }
            else
            {
                /*------------------------------------------------------------------*/
                /* Message is not sequenced.  Notify client.                        */
                /*------------------------------------------------------------------*/
                MSG_STORE_CLIENT_REMOVE(MessageID);
            }
        }
    }
    return found;
}

BOOLEAN msg_StoreIsMsgPresentInStoreQueue(const eMessageIdentity MessageID)
/*============================================================================
**  Visibility:     Public
**  Description:    Interface to check whether a message is present in store queue or not
**  Parameters:     MessageID:  ID of message
**  Returns:        Message availablity status
**  Created:        MCHOUDHA
**==========================================================================*/
{
    BOOLEAN retStatus =  FALSE;
    if (MessageID < MSG_NUM_MESSAGES)
    {
        if (GET_SEMAPHORE(stor_StoredFlags, MessageID))
        {
            retStatus =  TRUE;
        }
    }
    return retStatus;
}

UINT32 stor_GetCategories(UINT32 Threshold,UINT8 inst)
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
** Created: AFERRIS2 18/Oct/2010
**==========================================================================*/
{
  UINT32 retValue = 0;
  if(inst < MSG_NUM_INSTANCES) 
  {
    UINT32 fl_index;
    for (fl_index = 0UL; fl_index < (UINT32)MSG_NUM_MESSAGE_CATEGORIES; fl_index++)
    {
      if ((stor_Categories[inst][fl_index] + (UINT16)Threshold) < stor_Categories[inst][fl_index + 1UL])
      {
        SETBIT(retValue, (1UL << fl_index));
      }
    }
  }
  return retValue;
}

static void stor_UpdateViewer(eMessageIdentity MessageID,UINT8 inst)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Notify VIEWER if we need to show a different message.
**                   (removed message has same or higher priority than the msg
**                   being viewed). Next message to be viewed can be found using
**                   the FindNext function.
**
**  Parameters:     MessageID:  ID of message being removed.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 27/Apr/2010
**==========================================================================*/
{

  if(inst < MSG_NUM_INSTANCES)
  {
#ifdef STORE_QUEUE_VIEW_CURRENT

    /* If the msg queue is empty */
    if (stor_ViewMessage[inst].Id == MSG_INDEX_UNDEFINED)
    {
      /* Get the first message from store list */

      if(stor_ViewMessage[inst].Position < (UINT16)hmi_msg_inst_config_count[inst]){
        stor_ViewMessage[inst].Id = stor_MessageList[inst][stor_ViewMessage[inst].Position];
      }
    }
    /* If the message currently being pointed is deleted */
    else if(MessageID == stor_ViewMessage[inst].Id)
    {
      /* If it is the first message in the queue */
      if(stor_ViewMessage[inst].Position == 0U)
      {
        /* Point to the first message from store list */
        stor_ViewMessage[inst].Id = stor_MessageList[inst][stor_ViewMessage[inst].Position];
      }
      /* If the message is in middle or bottom of queue */
      else
      {
        UINT32 index;
        /* Point to the previous message */
        index = stor_FindPreviousIndex(stor_ViewMessage[inst].Position, stor_ViewMask,inst);
        if (index  <= hmi_msg_inst_config_count[inst])
        {
          stor_ViewMessage[inst].Id = stor_MessageList[inst][index];
          stor_ViewMessage[inst].Position = (UINT16)index;
        }
      }
    }
    /* If new msg is added or if old messages are deleted */
    else
    {
      /* Update the position of the currently pointing message */
      stor_ViewMessage[inst].Position = stor_GetViewIndex(stor_ViewMessage[inst].Id, stor_ViewMask,inst);
    }

    /* Update the count always */
    stor_ViewMessage[inst].Count = stor_GetViewCount(stor_ViewMask,inst);
    MSG_STORE_NOTIFY_VIEWER();

#else

    if (MessageID <= stor_ViewMessage[inst].Id)
    {
      UINT32 index;

      /*----------------------------------------------------------*/
      /* Select next message in list.                             */
      /*----------------------------------------------------------*/
      index = stor_FindFirstIndex(stor_ViewMask,inst);
      stor_ViewMessage[inst].Id = stor_MessageList[inst][index];
      stor_ViewMessage[inst].Position = stor_GetViewIndex(stor_ViewMessage[inst].Id, stor_ViewMask,inst);
    }

    stor_ViewMessage[inst].Count = stor_GetViewCount(stor_ViewMask,inst);
    MSG_STORE_NOTIFY_VIEWER();

#endif
  }
}

static UINT16 stor_GetViewIndex(eMessageIdentity MessageID, UINT32 CategoryMask,UINT8 inst)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Get the index of the message within the list of messages that
**                  match the specified categories.
**
**  Parameters:     aMessage:   The Message ID
**                  CategoryMask:   The Categories to search in.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 06/Jul/2010
**==========================================================================*/
{
  UINT16 index = 0u;
  if(inst < MSG_NUM_INSTANCES)
  {	  
    UINT32 fl_index;
    eMessageIdentity iMessage;
    MSG_MESSAGE_STRUCT const * pMessage;
    for (fl_index = 0; fl_index < STOR_LAST_INDEX(inst); fl_index++)
    {
      iMessage = stor_MessageList[inst][fl_index];
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
        if (TESTBIT(CategoryMask, (1UL << (UINT8)pMessage->Category)) )
        {
          /*------------------------------------------------------*/
          /* It is, so increment count.                           */
          /*------------------------------------------------------*/
          index++;
        }
      }
    }
  }

  return index;
}


static void stor_IndexUp(UINT16 BaseCategory,UINT8 inst)
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
  if(inst < MSG_NUM_INSTANCES) 
  {

    UINT32 iCategory = BaseCategory;
    while (iCategory < ((UINT32)(MSG_NUM_MESSAGE_CATEGORIES) + 1UL) )
    {
      stor_Categories[inst][iCategory]++;
      iCategory++;
    }
  }
}

static void stor_IndexDown(UINT16 BaseCategory,UINT8 inst)
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
  if(inst < MSG_NUM_INSTANCES) 
  {

    UINT32 iCategory = BaseCategory;
    while (iCategory < ((UINT32)(MSG_NUM_MESSAGE_CATEGORIES) + 1UL) )
    {
      stor_Categories[inst][iCategory]--;
      iCategory++;
    }
  }
}

static void stor_Delete(UINT32 Index,UINT8 inst)
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
    UINT32 fl_Index = Index;

    while (fl_Index < STOR_LAST_INDEX(inst))
    {
      stor_MessageList[inst][fl_Index] = stor_MessageList[inst][fl_Index + 1UL];
      fl_Index++;
    }
    /*----------------------------------------------------------------------*/
    /* Set last position to invalid message ID.                             */
    /*----------------------------------------------------------------------*/
    stor_MessageList[inst][fl_Index] = MSG_INDEX_UNDEFINED;
  }
}

static void stor_Insert(UINT32 Index, eMessageIdentity Value)
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

  if (Value < MSG_NUM_MESSAGES)
  {

    UINT32 fl_index;
    UINT8 inst;
    MSG_MESSAGE_STRUCT const * pMessage;
    pMessage = &messageList[Value];
    inst = pMessage->InstanceID;
    /*----------------------------------------------------------------------*/
    /* Shift messages down.                                                 */
    /*----------------------------------------------------------------------*/
    if(inst < MSG_NUM_INSTANCES)
    {
      fl_index = (UINT32)STOR_LAST_INDEX(inst) + 1UL;
      while (fl_index > Index)
      {
        stor_MessageList[inst][fl_index] = stor_MessageList[inst][fl_index-1UL];
        fl_index--;
      }

      /*----------------------------------------------------------------------*/
      /* Save message ID to this position.                                    */
      /*----------------------------------------------------------------------*/
      stor_MessageList[inst][Index] = Value;
    }
  }
}

static void stor_InitIndex(UINT8 inst)
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
  UINT32 fl_index;
  if(inst < MSG_NUM_INSTANCES) 
  {
    for (fl_index=0; fl_index <= (UINT32)MSG_NUM_MESSAGE_CATEGORIES; fl_index++)
    {
      stor_Categories[inst][fl_index] = 0;
    }
  }
}

static void stor_InitList(UINT8 inst)
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
  UINT32 fl_index;

  if(inst < MSG_NUM_INSTANCES) 
  {
    for (fl_index = 0; fl_index <= (UINT32)MSG_NUM_MESSAGES; fl_index++)
    {
      stor_MessageList[inst][fl_index] = MSG_INDEX_UNDEFINED;
#ifdef MSG_ACK_WRNG_REPETITION
      /*------------------------------------------------------------------*/
      /* Initialize with 0xffff, indicates that the ack warning repetition*/
      /* is not applicable for that warning                               */
      /*------------------------------------------------------------------*/
#if MSG_NUM_INSTANCES > 1
      if(inst == 0)
#endif
      {
        stor_Ack_Wrng_RepDuration[fl_index] = HMI_MSG_ACK_WRNG_REP_INVALID_U8;
      }
#endif
    }
  }
}

static UINT32 stor_FindFirstIndex(UINT32 CategoryMask,UINT8 inst)
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
  return stor_FindNextIndex(0, CategoryMask,inst);
}

static UINT32 stor_FindNextIndex(UINT32 Start, UINT32 CategoryMask,UINT8 inst)
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
  UINT32 fl_index = 0u;
  UINT32 index = 0u;
  UINT32 ret_index = 0u;
  eMessageIdentity iMessage;
  if(inst < MSG_NUM_INSTANCES) 
  {

    MSG_MESSAGE_STRUCT const * pMessage;
    index = STOR_LAST_INDEX(inst);

    for (fl_index = Start; fl_index < index; fl_index++)
    {
      /*--------------------------------------------------------------*/
      /* Get pointer to message definition.                           */
      /*--------------------------------------------------------------*/
      iMessage = stor_MessageList[inst][fl_index];
      if (iMessage < MSG_NUM_MESSAGES)
      {
        pMessage = &messageList[iMessage];

        if (TESTBIT(CategoryMask, (1UL << (UINT8)pMessage->Category)))
        {
          /*----------------------------------------------------------*/
          /* Match found....                                          */
          /*----------------------------------------------------------*/
          ret_index = fl_index;
          break;
        }
      }
    }
  }
  return ret_index;
}

static UINT32 stor_FindPreviousIndex(UINT32 Start, UINT32 CategoryMask,UINT8 inst)
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
  UINT32 fl_index = 0u;
  UINT32 index = 0u;
  eMessageIdentity iMessage;
  if(inst < MSG_NUM_INSTANCES) 
  {    
    MSG_MESSAGE_STRUCT const * pMessage;
    index = STOR_LAST_INDEX(inst);

    for (fl_index = Start; fl_index != 0UL; fl_index--)
    {
      /*--------------------------------------------------------------*/
      /* Get pointer to message definition.                           */
      /*--------------------------------------------------------------*/
      iMessage = stor_MessageList[inst][fl_index-1UL];
      if (iMessage < MSG_NUM_MESSAGES)
      {
        pMessage = &messageList[iMessage];

        if (TESTBIT(CategoryMask, (1UL << (UINT8)pMessage->Category)))
        {
          /*----------------------------------------------------------*/
          /* Match found....                                          */
          /*----------------------------------------------------------*/
          index = fl_index - 1UL;
          break;
        }
      }
    }
  }
  return index;
}

#ifdef MSG_ACK_WRNG_REPETITION
#ifdef MSG_ACK_WRNG_REPEAT_TIMER_CONTROL
#if (MSG_NUM_INSTANCES > 1)
void msg_StorAckWrngRepTimerControl(eAckWrngRepTimerStatus p_AckWrngRepTimerAction,UINT8 p_inst)
#else
void msg_StorAckWrngRepTimerControl(eAckWrngRepTimerStatus p_AckWrngRepTimerAction)
#endif
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    The ack warning repeat timer status required by the 
**  application will be passed as an argument.  Three controls are available
**  either pause or resume or restart. Based on the control required by the
**  application actions will be taken.
**
**  Parameters:     eAckWrngRepTimerStatus
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: adevi  12/Aug/2015
**==========================================================================*/
{
  eMessageIdentity MessageID;
  UINT32 i;
  MSG_MESSAGE_STRUCT const * pMessage;
#if (MSG_NUM_INSTANCES > 1)
  UINT8 inst = p_inst;
  if(inst < MSG_NUM_INSTANCES) 
#else 
  UINT8 inst = 0u;
#endif
  {
    switch(p_AckWrngRepTimerAction)
    {
    case ACK_WRNG_REP_TIMER_PAUSE:
      stor_AckWrng_Rep_TimerStatus[inst] = ACK_WRNG_REP_TIMER_PAUSE;
      break;
    case ACK_WRNG_REP_TIMER_RESUME:
      stor_AckWrng_Rep_TimerStatus[inst] = ACK_WRNG_REP_TIMER_RESUME;
      break;
    case ACK_WRNG_REP_TIMER_RESTART:
      {
        stor_AckWrng_Rep_TimerStatus[inst] = ACK_WRNG_REP_TIMER_RESTART;
        /* Load all the warnings with option ack warning repeat with their repeat duration */

        for (i=0UL; i <= (UINT32)hmi_msg_inst_config_count[inst]; i++)
        {
          MessageID = stor_MessageList[inst][i];
          if(MSG_INDEX_UNDEFINED != MessageID)
          {
            pMessage = &messageList[MessageID];
            if(TESTBIT(pMessage->Options, (UINT32)MSG_OPTION_ACK_WRNG_REPEAT))
            {
              UI_MSG_FLOAT32 stor_Ack_Wrng_RepDuration_f = ((UI_MSG_FLOAT32)HMI_MSG_ACK_WRNG_REP_DURATION * HMI_MSG_ACK_REP_TIMER_RESLN_FACTOR); /* Variable added to fix MISRA warning */
              stor_Ack_Wrng_RepDuration[MessageID] = (UINT8)stor_Ack_Wrng_RepDuration_f; 
            }
          }
          /* there will be no more messages in the store queue */
          else
          {
            break;
          }
        }

      }
      break;
    default:
      /* Comment added to fix MISRA Warning 3599023 */
      break;      
    }
  }
}
#endif


void msg_StorAckWrngRepUpdate(UINT8 p_inst)
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Will check the ack warning repetition duration expiry for
**  the messages where MSG_OPTION_ACK_WRNG_REPEAT option is enabled.  If the ack
**  warning duration expires then the ack warning is made old by adding the
**  message in the sequencer queue.
**
**  Parameters:     None
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: adevi  13/Dec/2013
**==========================================================================*/
{
  const MSG_MESSAGE_STRUCT *pMessage;
  eMessageIdentity MessageID;
  UINT32 MsgTimerStatus_U32;
  UINT32 i;

#if (MSG_NUM_INSTANCES > 1)
  UINT8 inst = p_inst;
  if(inst < MSG_NUM_INSTANCES) 
#else 
  UINT8 inst = 0u;
#endif
  {
    MsgTimerStatus_U32 = MSG_CHECK_SW_TIMER(hmi_msg_inst_config_table[inst].stor_AckWrng_Rep_Timer);
    if ((TIMER_RUNNING != MsgTimerStatus_U32)
#ifdef MSG_ACK_WRNG_REPEAT_TIMER_CONTROL
      && (stor_AckWrng_Rep_TimerStatus[inst] != ACK_WRNG_REP_TIMER_PAUSE)
#endif
      )
    {
      /*------------------------------------------------------------------*/
      /* Restart the timer during the expiry of the scheduled time        */
      /*------------------------------------------------------------------*/
      MSG_START_SW_TIMER(HMI_MSG_ACK_REP_TIMER_VAL, hmi_msg_inst_config_table[inst].stor_AckWrng_Rep_Timer);
      /*------------------------------------------------------------------*/
      /* All the active messages present in stor list which has           */
      /* MSG_OPTION_ACK_WRNG_REPEAT option enabled and has valid ack      */
      /* warning repetition time is short listed. Ack warning repetition  */
      /* duration is decremented every one second.  When the value is 0   */
      /* then the message is added to the sequencer queue.                */
      /*------------------------------------------------------------------*/

      for (i=0UL; i <= (UINT32)hmi_msg_inst_config_count[inst]; i++)
      {
        MessageID = stor_MessageList[inst][i];			
        if(MSG_INDEX_UNDEFINED != MessageID)
        {
          pMessage = &messageList[MessageID];
          if(TESTBIT(pMessage->Options, (UINT32)MSG_OPTION_ACK_WRNG_REPEAT))
          {
            if(HMI_MSG_ACK_WRNG_REP_INVALID_U8 != stor_Ack_Wrng_RepDuration[MessageID])
            {
              if(stor_Ack_Wrng_RepDuration[MessageID] >= HMI_MSG_VALUE_1)
              {
                stor_Ack_Wrng_RepDuration[MessageID] = (stor_Ack_Wrng_RepDuration[MessageID] - HMI_MSG_VALUE_1);
              }
              else
              {
                stor_Ack_Wrng_RepDuration[MessageID] = 0U;
              }
              if(0u == stor_Ack_Wrng_RepDuration[MessageID])
              {
                /* To indicate msg_SequencerAdd that msg is added */
                /* from store queue due to ack warning repetition */
                l_MsgAddedFromStoreQueue[inst] = (BOOLEAN)MSG_ADDED_FROM_STORE_QUEUE;
                /*---------------------------------------------------------------*/
                /* Call sequencer add and add the message to the sequencer queue */
                /*---------------------------------------------------------------*/
                msg_SequencerAdd(MessageID);
                /* Reset the flag once msg_SequencerAdd is executed */
                l_MsgAddedFromStoreQueue[inst] = (BOOLEAN)MSG_NOT_ADDED_FROM_STORE_QUEUE;
                /*------------------------------------------------------------*/
                /* Clear the new message flag since the message should be old */
                /*------------------------------------------------------------*/
                msg_ClearNewMessageFlag(MessageID);
#ifdef MSG_OLD_WRNG_REPETITION
                /*---------------------------------------------------------*/
                /* Set the old warning repetition duration for the message */
                /*---------------------------------------------------------*/
                msg_SetOldWrngRepDur(MessageID);
#endif
              }
            }
          }
        }
        else
        {
          /*----------------------------------------------------------*/
          /* Stor list is empty, so terminate the check               */
          /*----------------------------------------------------------*/
          break;
        }
      }
    }
  }
}
#endif

/*==========================================================================*/
/* R E V I S I O N    N O T E S                                             */
/*==========================================================================*/
/* For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**==========================================================================*/

/****************************************************************************
**  Date  : 09/Apr/2010
**  by    : AFERRIS2
**  Ref   : None.
**  Change: Initial version.
**
*****************************************************************************/

/****************************************************************************
**  Date: 06/May/2010     by: AFERRIS2        Ref: None.
**  Change: 1.  Update interfaces to use the formal Standard Interface.
**          2. Corrected the FindFirst and FindNext functions.
**          3. Add FindPrevious function (missing from original submission)
**          4. Add interface to return the number of viewable messages.
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 07/Jul/2010     by: AFERRIS2        Ref:
**  Change: 1.  Updated interfaces to include message ID, position, and count.
**              We now use msg_StoreGetCurrent(), msg_StoreSelectFirst(),
**              msg_StoreSelectNext(), and msg_StoreSelectPrevious() functions
**          2.  Made wrapping an option via the configuration file.
**          3.  QAC reports one error (nested comment within swtmr.h)
**
**  Checks: COMPILER - NO WARNINGS       QAC - 1 warning
*****************************************************************************/

/****************************************************************************
**  Date: 07/Sep/2010     by: AFERRIS2        Ref:
**  Change: 1.  Removed unused local variables (QAC actions)
**
**  Checks: COMPILER - NO WARNINGS       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 19/Oct/2010     by: AFERRIS2        Ref:
**  Change: 1.  Add new function stor_GetCategories() to obtain which categories
**              contain active messages. (work in progress)
**
**  Checks: COMPILER - NO WARNINGS       QAC - NO WARNINGS
*****************************************************************************/

/****************************************************************************
**  Date: 20/Oct/2010     by: AFERRIS2        Ref:
**  Change: 1.  Updated stor_GetCategories() to allow checking for more than a
**              specified number of messages in a category.
**
**  Checks: COMPILER - NO WARNINGS       QAC - 2 WARNINGS
*****************************************************************************/

/****************************************************************************
**  Date: 26/Nov/2010     by: AFERRIS2        Ref:
**  Change: 1.  Corrected the purge function which was attempting to remove each
**              message twice.  This will lead to an underflow in the categories
**              array.
**
**  Checks: COMPILER - NO WARNINGS       QAC - NO WARNINGS
*****************************************************************************/

/****************************************************************************
**  Date: 25/Apr/2012     by: ADEVI          Ref:
**  Change: 1.  Introduced new compiler switch 	STORE_QUEUE_VIEW_CURRENT to
**              view the current message even if new messages are added or old
**              messages are deleted in the message queue.
**
**  Checks: COMPILER - NO WARNINGS       QAC - NO WARNINGS
*****************************************************************************/


/****************************************************************************
**  Date: 26/Jul/2013     by: vsarava2        Ref: RTC 73978
**  Fixed the Compiler(IAR) prototype warning as per project request.
**  Checks: COMPILER - NO WARNINGS       QAC -
*****************************************************************************/

/****************************************************************************
**  Date: 27/Dec/2013     by: adevi            Ref: RTC 91917
**  Change: 1. Introduced compiler switch MSG_ACK_WRNG_REPETITION to allow
**  repetition of an ack warning. 
**  2.  If MSG_OPTION_ACK_WRNG_REPEAT is enabled then warnings which are 
**  acknowledged will be made old after the ack warning repetition duration.
*****************************************************************************/

/****************************************************************************
**  Date: 09/Jan/2014     by: adevi            Ref: PR 72449
**  Change:
**  1. Clearstor_AckWrng_Rep_1SecTimer removed from msg_StorAckWrngRepUpdate
**  2. Flag MsgAddedFromStoreQueue added.
*****************************************************************************/

/****************************************************************************
**  Date: 10/Feb/2015     by: adevi        Ref:
**  Change: Compiler warnings resolved for Honda THAA
*****************************************************************************/

/****************************************************************************
**  Date: 29/Jun/2015     by: adevi        Ref: RTC 365702
**  Change: QAC warnings resolved for Honda THAA
*****************************************************************************/

/****************************************************************************
**  Date: 13/Aug/2015     by: adevi        Ref:RTC 399553
**  Change: msg_StorAckWrngRepTimerControl function added.
*****************************************************************************/ 

/****************************************************************************
**  Date: 25/Aug/2015     by: arajase2        Ref:RTC 408084
**  Change: eAckWrngRepTimerStatus hmi_msg_inst_config_table[inst].stor_AckWrng_Rep_TimerStatus declaration protected
**  with MSG_ACK_WRNG_REPEAT_TIMER_CONTROL macro.
*****************************************************************************/ 
/****************************************************************************
**  Date: 03/Sep/2015     by: aperumal        Ref:RTC 408084
**  Compiler warning for Honda Thaa
*****************************************************************************/ 

/****************************************************************************
**  Date: 04/May/2017     by: arajase2
**  Ref: RTC 859438: CMFB MISRA Warning fixes - message.core
**  Change: MISRA warnings resolved for CMFB
*****************************************************************************/

/* end of file =============================================================*/
