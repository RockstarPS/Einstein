/**
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2013. Visteon Corporation owns all rights to
 this work and intends to maintain it in confidence to preserve
 its trade secret status. Visteon Corporation reserves the right,
 under the copyright laws of the United States or those of any
 other country that may have jurisdiction, to protect this work
 as an unpublished work, in the event of an inadvertent or
 deliberate unauthorized publication. Visteon Corporation also
 reserves its rights under all copyright laws to protect this
 work as a published work, when appropriate. Those having access
 to this work may not copy it, use it, modify it or disclose the
 information contained in it without the written authorization
 of Visteon Corporation.
 * @endverbatim
 * @file        OsMessage.c
 * @details     <b>Contains implementations of the Os Message Functionality</b>
 * @note
 *              Compiler    : GHS \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2021
 *
 */

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "OsMain.h"
#include "OsMessage.h"

#define OS_CORE_CODE_SEC_START
#define OS_CORE_CONST_SEC_START
#define OS_CORE_DATA_SEC_START
#define OS_CORE_BSS_SEC_START
#include "Os_IntMemMap.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#define OSMESSAGE_START_CS()   OsPrvEnterCriticalSection() /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

#define OSMESSAGE_END_CS()     OsPrvEnterCriticalSection() /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
#define OS_IGNORE_UNREF_PARAM(param)                  ((void)(param))
typedef struct
{
    osuint8     osMsgQueueReceivedMessages;
    osuint8     osMsgQueueWriteIndex;
    osuint8     osMsgQueueReadIndex;
    StatusType  osMsgQueueStatus;
}osMessageQueueType; /*MISRA RULE 2.3 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
 
/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
#if (OsNumberOfTotalMessageQueues > 0)
COMApplicationModeType  osCOMStartupMode;

osMessageQueueType osQueuedMessages[OsNumberOfTotalMessageQueues];
#endif

#if (OsNumberOfTxMessages > 0)
static void osMemCpy(osuint8* dest, const osuint8* src, osuint16 bytes);
static void osMessageProcessNotification(MessageIdentifier MessageID);

/**
 * @brief osMemCpy -  MemCopy
 *
 * @param dest
 * @param src
 * @param bytes
 *
 * @return void
 */

static void osMemCpy(osuint8* dest, const osuint8* src, osuint16 bytes)
{
    while (bytes > 0)
    {
       *dest = *src;
       dest++;
       src++;
       bytes--;
    }
}
#endif //OsNumberOfTxMessages

/**
 * @brief osStartCOM -  Start the osekCom instance
 *
 * @param Mode
 *
 * @return StatusType
 */

/*MISRA RULE 2.7 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
StatusType osStartCOM(COMApplicationModeType Mode)
{
#if (OsNumberOfTxMessages > 0)
#if OsComStartComExtension
   StatusType retval = 0;
#endif
#if OsNumberOfMsgFlagNotifications || OsNumberOfTotalMessageQueues
   osuint8 i = 0;
#endif
    OSMESSAGE_START_CS();
    osCOMStartupMode= Mode;
#if OsNumberOfMsgFlagNotifications
    for(i=0; i<OsNumberOfMsgFlagNotifications; i++)
    {
       osMsgFlags[i]=COM_FALSE;
    }
#endif
#if OsNumberOfTotalMessageQueues
   for(i=0; i<OsNumberOfTotalMessageQueues; i++)
   {
      osQueuedMessages[i].osMsgQueueReceivedMessages = 0;
      osQueuedMessages[i].osMsgQueueWriteIndex = 0;
      osQueuedMessages[i].osMsgQueueReadIndex = 0;
      osQueuedMessages[i].osMsgQueueStatus = E_COM_NOMSG;
   }
#endif

#if OsComStartComExtension
   retval=osStartCOMExtension();
#endif

#if (OsNumberOfTxMessages > 0)
    OSMESSAGE_END_CS();
#endif
#if OsComStartComExtension
   return retval;
#else
   return E_OK;
#endif
#else
    OS_IGNORE_UNREF_PARAM(Mode);
   return E_NOT_OK;
#endif //OsNumberOfTxMessages
}

/**
 * @brief osStopCOM -  Stop the osekCom instance
 *
 * @param Mode
 *
 * @return StatusType
 */

StatusType osStopCOM(COMShutdownModeType Mode)
{
    (void)Mode;
#if OsNumberOfTotalMessageQueues
   osuint8 i = 0;
   for(i=0; i<OsNumberOfTotalMessageQueues; i++)
   {
      osQueuedMessages[i].osMsgQueueReceivedMessages = 0;
      osQueuedMessages[i].osMsgQueueWriteIndex = 0;
      osQueuedMessages[i].osMsgQueueReadIndex = 0;
      osQueuedMessages[i].osMsgQueueStatus = E_COM_NOMSG;
   }
#endif
    return E_OK;
}

/**
 * @brief osInitMessage -  Initialize the message; No Notification.
 *
 * @param MessageID
 * @param DataRef
 *
 * @return StatusType
 */

/*MISRA RULE 2.7 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
StatusType osInitMessage(MessageIdentifier MessageID, ApplicationDataRef DataRef)
{
    StatusType Ret = E_NOT_OK;
#if (OsNumberOfTxMessages > 0)
    osuint16 i = 0;
    osuint8 queueIndex = 0;
    osuint8* ptr = NULL;

    OSMESSAGE_START_CS();
#if OsComStartComExtension
    if(MessageID < OsNumberOfTxMessages)
    {
#endif
        /* Same Message can have multiple recievers */
        for(i=OsMsgTxToRxIndex[MessageID]; i<(OsMsgTxToRxIndex[MessageID]+OsMsgNumberOfMsgReceivers[MessageID]); i++)
        {
            if(OsMsgQueueSize[i] == 0)
            {
                /* Direct copy if not queue */
                osMemCpy((osuint8*)OsMsgDataBufferRef[i], DataRef, OsMsgLength[MessageID]);
            }
            else
            {
                /* Queue configured for this Receiver. Get the queue index for this RxMessage */
                queueIndex = OsMsgIndexToQueueIndex[i];
                if (osQueuedMessages[queueIndex].osMsgQueueReceivedMessages >= OsMsgQueueSize[i])
                {
                   /* fifo full */
                   osQueuedMessages[queueIndex].osMsgQueueStatus=E_COM_LIMIT;
                   Ret = E_COM_LIMIT;
                }
                else
                {
                   /* Queue has space for this message. Get the pointer to the oldest location */
                   ptr= (osuint8*)OsMsgDataBufferRef[i];
                   ptr+= osQueuedMessages[queueIndex].osMsgQueueWriteIndex * OsMsgLength[MessageID];

                   /* Copy Data to the queue */
                   osMemCpy(ptr, DataRef, OsMsgLength[MessageID]);
                   osQueuedMessages[queueIndex].osMsgQueueReceivedMessages++;

                   osQueuedMessages[queueIndex].osMsgQueueWriteIndex++;
                   if (osQueuedMessages[queueIndex].osMsgQueueWriteIndex >= OsMsgQueueSize[i])
                   {
                      /* Queue end reached. Start Over */
                      osQueuedMessages[queueIndex].osMsgQueueWriteIndex = 0;
                   }
                   osQueuedMessages[queueIndex].osMsgQueueStatus=E_OK;
                }
            }
            /* No Notification */
        }
        Ret = E_OK;
#if OsComStartComExtension
    }
    else
    {
        Ret = E_COM_ID;
    }
#endif
    OSMESSAGE_END_CS();
#endif
    OS_IGNORE_UNREF_PARAM(MessageID);
    OS_IGNORE_UNREF_PARAM(DataRef);
    return Ret;
}

/**
 * @brief osSendMessage -  Initialize the message; No Notification.
 *
 * @param MessageID
 * @param DataRef
 *
 * @return StatusType
 */

/*MISRA RULE 2.7 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

StatusType osSendMessage(MessageIdentifier MessageID, ApplicationDataRef DataRef)
{
    StatusType Ret = E_NOT_OK;

#if (OsNumberOfTxMessages > 0)
    osuint16 i = 0;
    osuint8 queueIndex = 0;
    osuint8* ptr = NULL;

    OSMESSAGE_START_CS();
#if OsComStartComExtension
    if(MessageID < OsNumberOfTxMessages)
    {
#endif
        /* Same Message can have multiple recievers */
        for(i=OsMsgTxToRxIndex[MessageID]; i<(OsMsgTxToRxIndex[MessageID]+OsMsgNumberOfMsgReceivers[MessageID]); i++)
        {
            if(OsMsgQueueSize[i] == 0)
            {
                /* Direct copy if not queue */
                osMemCpy((osuint8*)OsMsgDataBufferRef[i], DataRef, OsMsgLength[MessageID]);
            }
            else
            {
                /* Queue configured for this Receiver. Get the queue index for this RxMessage */
                queueIndex = OsMsgIndexToQueueIndex[i];
                if (osQueuedMessages[queueIndex].osMsgQueueReceivedMessages >= OsMsgQueueSize[i])
                {
                   /* fifo full */
                   osQueuedMessages[queueIndex].osMsgQueueStatus=E_COM_LIMIT;
                }
                else
                {
                   /* Queue has space for this message. Get the pointer to the oldest location */
                   ptr= (osuint8*)OsMsgDataBufferRef[i];
                   ptr+= osQueuedMessages[queueIndex].osMsgQueueWriteIndex * OsMsgLength[MessageID];

                   /* Copy Data to the queue */
                   osMemCpy(ptr, DataRef, OsMsgLength[MessageID]);
                   osQueuedMessages[queueIndex].osMsgQueueReceivedMessages++;

                   osQueuedMessages[queueIndex].osMsgQueueWriteIndex++;
                   if (osQueuedMessages[queueIndex].osMsgQueueWriteIndex >= OsMsgQueueSize[i])
                   {
                      /* Queue end reached. Start Over */
                      osQueuedMessages[queueIndex].osMsgQueueWriteIndex = 0;
                   }
                   osQueuedMessages[queueIndex].osMsgQueueStatus=E_OK;
                }
            }
            osMessageProcessNotification(i);
        }
        Ret = E_OK;
#if OsComStartComExtension
    }
    else
    {
        Ret = E_COM_ID;
    }
#endif
    OSMESSAGE_END_CS();
#endif
    OS_IGNORE_UNREF_PARAM(MessageID);
    OS_IGNORE_UNREF_PARAM(DataRef);
    return Ret;
}

#if (OsNumberOfTxMessages > 0)
/**
 * @brief osMessageProcessNotification -  Process the Notification for requested message.Triggers the configured notification type.
 *
 * @param MessageID
 *
 * @return void
 */

static void osMessageProcessNotification(MessageIdentifier MessageID)
{
    if(OsMsgNotifications[MessageID] == OsMESSAGE_ACTION_TASK)
    {
        if(OsMsgNotifyTask[MessageID] != 0)
        {
            (void) ActivateTask(OsMsgNotifyTask[MessageID]);
        }
    }
    else if(OsMsgNotifications[MessageID] == OsMESSAGE_ACTION_EVENT)
    {
        if((OsMsgNotifyTask[MessageID] != 0) && (OsMsgNotifyEvent[MessageID] != 0))
        {
            (void) SetEvent(OsMsgNotifyTask[MessageID], OsMsgNotifyEvent[MessageID]);
        }
    }
    else if(OsMsgNotifications[MessageID] == OsMESSAGE_ACTION_CALLBACK)
    {
        if(NULL != OsMsgNotifyCallBack[MessageID])
        {
            OsMsgNotifyCallBack[MessageID]();
        }
    }
    else if(OsMsgNotifications[MessageID] == OsMESSAGE_ACTION_FLAG)
    {
        osMsgFlags[OsMsgNotifyFlagIndex[MessageID]]=COM_TRUE;
    }
}
#endif

/**
 * @brief osReceiveMessage -  Copies the message to the application buffer.
 *
 * @param MessageID
 * @param DataRef
 *
 * @return StatusType
 */

/*MISRA RULE 2.7 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
StatusType osReceiveMessage(MessageIdentifier MessageID, ApplicationDataRef DataRef)
{
    StatusType Ret = E_NOT_OK;

#if (OsNumberOfRxMessages > 0)
    osuint8 queueIndex = 0;
    osuint8* ptr = NULL;

    OSMESSAGE_START_CS();
#if OsComStartComExtension
    if(MessageID < OsNumberOfRxMessages)
    {
#endif
        if(OsMsgQueueSize[MessageID] == 0)
        {
            /* No queue configured for the Source Tx of this Rx message */
            osMemCpy(DataRef, OsMsgDataBufferRef[MessageID], OsMsgLength[OsMsgSourceIDofReceiver[MessageID]]);
        }
        else
        {
            queueIndex= OsMsgIndexToQueueIndex[MessageID];

            if (osQueuedMessages[queueIndex].osMsgQueueReceivedMessages > 0)
            {
                /* Get the RxMessage Buffer Pointer */
                ptr= (osuint8*) OsMsgDataBufferRef[MessageID];
                /* Go to the first valid pointer of the queue */
                ptr+= osQueuedMessages[queueIndex].osMsgQueueReadIndex * OsMsgLength[OsMsgSourceIDofReceiver[MessageID]];
                osMemCpy(DataRef, ptr, OsMsgLength[OsMsgSourceIDofReceiver[MessageID]]);
                osQueuedMessages[queueIndex].osMsgQueueReceivedMessages--;
                osQueuedMessages[queueIndex].osMsgQueueReadIndex++;
                if (osQueuedMessages[queueIndex].osMsgQueueReadIndex >= OsMsgQueueSize[MessageID])
                {
                   osQueuedMessages[queueIndex].osMsgQueueReadIndex = 0;
                }
                if(osQueuedMessages[queueIndex].osMsgQueueStatus == E_COM_LIMIT)
                {
                    if(osQueuedMessages[queueIndex].osMsgQueueReceivedMessages == 0)
                    {
                        osQueuedMessages[queueIndex].osMsgQueueStatus = E_COM_NOMSG;
                    }
                    else
                    {
                        osQueuedMessages[queueIndex].osMsgQueueStatus = E_OK;;
                    }
                }
            }
            else
            {
                /* Queue Empty */
                osQueuedMessages[queueIndex].osMsgQueueStatus = E_COM_NOMSG;
                Ret = E_COM_NOMSG;
            }
        }
        Ret = E_OK;
#if OsComStartComExtension
    }
    else
    {
        Ret = E_COM_ID;
    }
#endif
    OSMESSAGE_END_CS();
#endif
    OS_IGNORE_UNREF_PARAM(MessageID);
    OS_IGNORE_UNREF_PARAM(DataRef);
    return Ret;
}

/**
 * @brief SendZeroMessage -  No Data will be send. Only Notification.
 *
 * @param MessageID
 *
 * @return StatusType
 */

/*MISRA RULE 2.7 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
StatusType osSendZeroMessage (MessageIdentifier MessageID)
{
    StatusType Ret = E_NOT_OK;

#if (OsNumberOfTxMessages > 0)
    osuint16 i = 0;

    OSMESSAGE_START_CS();
#if OsComStartComExtension
    if(MessageID < OsNumberOfTxMessages)
    {
#endif
        for(i=OsMsgTxToRxIndex[MessageID]; i<(OsMsgTxToRxIndex[MessageID]+OsMsgNumberOfMsgReceivers[MessageID]); i++)
        {
            /* No DataRef */
            osMessageProcessNotification(i);
        }
        Ret = E_OK;
#if OsComStartComExtension
    }
    else
    {
        Ret = E_COM_ID;
    }
#endif
    OSMESSAGE_END_CS();
#endif
    OS_IGNORE_UNREF_PARAM(MessageID);
    return Ret;
}


/**
 * @brief GetMessageStatus -  Returns the Message Status.
 *
 * @param MessageID
 *
 * @return StatusType
 */

/*MISRA RULE 2.7 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
StatusType osGetMessageStatus(MessageIdentifier MessageID)
{
    StatusType Ret = E_NOT_OK;

#if (OsNumberOfTxMessages > 0)
#if OsComStartComExtension
    if(MessageID < OsNumberOfRxMessages)
    {
        Ret = E_COM_ID;
    }
    else
    {
#endif
        if(OsMsgQueueSize[MessageID] != 0)
        {
            Ret = osQueuedMessages[OsMsgIndexToQueueIndex[MessageID]].osMsgQueueStatus;
        }
        else
        {
            Ret = E_OK;
        }
#if OsComStartComExtension
    }
#endif
#endif //OsNumberOfTxMessages
    OS_IGNORE_UNREF_PARAM(MessageID);
    return Ret;
}

#define OS_CORE_CODE_SEC_END
#define OS_CORE_CONST_SEC_END
#define OS_CORE_DATA_SEC_END
#define OS_CORE_DATA_NOCACHE_SEC_END
#define OS_CORE_BSS_SEC_END
#include "Os_IntMemMap.h"

/*============================================================================
**============================================================================
** R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
**===========================================================================*/
/*---------------------------------------------------------------------------
Date               : 12-Jun-17
CDSID              : ssebast1
Traceability       : 
Change Description : Initial version
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 13-May-2022                                             
CDSID             : eganesan                                               
RTC Id            : 1648619                                               
Change Description: Coverity & Misra Medium Warning Fix                    
**-------------------------------------------------------------------------- */
/**----------------------------------------------------------------------------------**
**   Date              : 09-June-2022                                               **
**   CDSID             : eganesan                                                   **
**   RTC Id            : 1679233                                                    **
**   Change Description: Coverity & Misra Low Warning Fix                           **
**----------------------------------------------------------------------------------**/
/* end of file =============================================================*/
