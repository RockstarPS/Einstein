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
 * @file        OsMessage.h
 * @details     <b>file externs the generic APIs of the OS</b>
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

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#ifndef OSMESSAGE_H
#define OSMESSAGE_H

#define COM_FALSE 0 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define COM_TRUE  1 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

#define E_COM_ID    0 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define E_COM_NOMSG 1 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define E_COM_LIMIT 2 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

#define OsMESSAGE_ACTION_NONE       0 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OsMESSAGE_ACTION_TASK       1 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OsMESSAGE_ACTION_EVENT      2 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OsMESSAGE_ACTION_CALLBACK   3 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OsMESSAGE_ACTION_FLAG       4 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

#define COMErrorGetServiceId()       0 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
/* COM Typedefs*/ 
typedef osuint16 MessageIdentifier;
typedef void *ApplicationDataRef;
typedef osuint8 COMApplicationModeType;
typedef osuint8 COMShutdownModeType;
typedef osuint16 COMServiceIdType; /*MISRA RULE 2.3 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
typedef void (*osComCbFct)(void); /*MISRA RULE 2.3 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
typedef osuint8 FlagType; /*MISRA RULE 2.3 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

/*****************************************************************************
*                                 External Variables                         *
*---------------------------------------------------------------------------*/
extern COMApplicationModeType osCOMStartupMode; /*MISRA RULE 8.6 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

#if OsNumberOfRxMessages
   extern const osuint16  OsMsgTxToRxIndex[OsNumberOfTxMessages];
   extern const osuint8 OsMsgNumberOfMsgReceivers[OsNumberOfTxMessages];
   extern const osuint8 OsMsgLength[OsNumberOfTxMessages];
   extern const osuint8 OsMsgQueueSize[OsNumberOfRxMessages];
   extern const osuint16 OsMsgSourceIDofReceiver[OsNumberOfRxMessages];
   extern const osuint8 OsMsgIndexToQueueIndex[OsNumberOfRxMessages];
   extern const osuint8* OsMsgDataBufferRef[OsNumberOfRxMessages];

   extern const osuint8 OsMsgNotifications[OsNumberOfRxMessages];
   extern const TaskType OsMsgNotifyTask[OsNumberOfRxMessages];
   extern const EventMaskType OsMsgNotifyEvent[OsNumberOfRxMessages];
#endif

#if OsNumberOfMsgCallbackNotifications
extern const osComCbFct OsMsgNotifyCallBack[OsNumberOfRxMessages];
#endif

#if OsNumberOfMsgFlagNotifications
extern const FlagType OsMsgNotifyFlagIndex[OsNumberOfRxMessages];
#endif

/*****************************************************************************
*                                 External APIs                              *
******************************************************************************/
StatusType osStartCOM(COMApplicationModeType Mode);
StatusType osStopCOM(COMShutdownModeType Mode);
StatusType osInitMessage(MessageIdentifier MessageID, ApplicationDataRef DataRef);
StatusType osSendMessage(MessageIdentifier MessageID, ApplicationDataRef DataRef);
StatusType osReceiveMessage(MessageIdentifier MessageID, ApplicationDataRef DataRef);
StatusType osSendZeroMessage (MessageIdentifier MessageID);
StatusType osGetMessageStatus(MessageIdentifier MessageID);
#ifndef osdGetCOMApplicationModeNotUsed
#define GetCOMApplicationMode() (osCOMStartupMode) /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#endif /*osdGetCOMApplicationModeNotUsed*/


#define StartCOM(x)             (osStartCOM(x)) /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define StopCOM(x)              (osStopCOM()) /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define InitMessage(x, y)       (osInitMessage((x), (y))) /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define SendMessage(x, y)       (osSendMessage((x), (y))) /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define ReceiveMessage(x, y)    (osReceiveMessage((x), (y))) /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define SendZeroMessage(x, y)   (osSendZeroMessage((x), (y))) /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define GetMessageStatus(x)     (osGetMessageStatus(x)) /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

#endif /* OSMESSAGE_H */
/*----------------------------------------------------------------------------------**
**  ------------------------------------------------------------------------------- **
**   ****************************************************************************   **
**      for each change to this file, be sure to record:                            **
**         1.  who made the change and when the change was made                     **
**         2.  why the change was made and the intended result                      **
**      Following block needs to be repeated for each change                        **
**   ****************************************************************************   **
**      Note: In the traceability column we need to trace back to the Design Doc.   **
**      For the initial version it is traced to the Design Document section.        **
**      For further changes it shall trace to the source of the change which may    **
**      be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any     **
**      other reason                                                                **
**   ****************************************************************************   **
**  ------------------------------------------------------------------------------- **
**                                                                                  **
**  ------------------------------------------------------------------------------- **
**   Date              : 16-Jun-2017                                                **
**   CDSID             : ssebast1                                                   **
**   Traceability      :------------                                                **
**   RTC Version       : ------                                                     **
**   Change Description: Initial version.                                           **
**   ------------------------------------------------------------------------------ **
**----------------------------------------------------------------------------------*/
