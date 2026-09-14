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
**  Name:               hmi_msgDefinition.h
**
**  Description:        Definitions for the message core DEFINTION module.
**                  *** DO NOT INCLUDE THIS FILE FROM AN EXTERNAL PACKAGE ***
**
**  Organization:       Driver Information Software Section,
**                      DI Core Engineering Department
**
**===========================================================================*/
#ifndef hmi_msgDefinition_H
#define hmi_msgDefinition_H

/*==========================================================================*/
/* I N C L U D E   F I L E S                                                */
/*==========================================================================*/
#include "hmi_SIF.h"
#include "hmi_msgDefinition.cfg"

/*==========================================================================*/
/* T Y P E   D E F I N I T I O N S                                          */
/*==========================================================================*/
typedef float UI_MSG_FLOAT32;

/*--------------------------------------------------------------*/
/* Message categories.                                          */
/*--------------------------------------------------------------*/
typedef enum
{
  MSG_MESSAGE_CATEGORIES,

  mcMaximum
} eMessageCategory;

#define MSG_NUM_MESSAGE_CATEGORIES   (mcMaximum)
#define MSG_ALL_CATEGORIES  (0xFFFFFFFFUL)



/*--------------------------------------------------------------*/
/* Message Identities.                                          */
/*--------------------------------------------------------------*/
typedef enum
{
  MSG_MESSAGE_IDENTITIES

  miMaximum,
  miUndefined
} eMessageIdentity;
#define MSG_NUM_MESSAGES    (miMaximum)

#ifdef MSG_ENABLE_GROUP_ACKNOWLEDGEMENT
typedef enum
{
    MSG_MESSAGE_ACK_GROUPS,
    mgUndefined
} eMessageAcknowledgeGroup;
#define MSG_ACK_GROUP_UNDEFINED (mgUndefined)
#endif

/*--------------------------------------------------------------*/
/* Message definition structure.                                */
/*--------------------------------------------------------------*/
typedef struct msgMessageStruct
{

#if MSG_NUM_INSTANCES > 1
  U16SIF_GET_DATA_MULTI_INST  CheckActiveCondition;
  U16SIF_GET_DATA_MULTI_INST  MsgEventCallback;
#else
  U16SIF_GET_DATA  CheckActiveCondition;
  U16SIF_GET_DATA  MsgEventCallback;
#endif
  UINT8            InstanceID; 
#if defined SIF_SUPPORT_EXTENDED_QUALIFIER
  UINT16           *ConditionQualifier;
  UINT8            *EventQualifier;
#else
  UINT16            ConditionQualifier;
  UINT8             EventQualifier;        /* See callback indication */
#endif

  UINT16           DisplayTimeout;
#if defined MSG_GET_DYN_HOLD_TIME
  U16_GET_DATA     HoldTimeout;
#else
  UINT16           HoldTimeout;
#endif
  eMessageCategory Category;
  UINT16           Priority;
  UINT32           Options;
  UINT8            ActiveStates;
#ifdef HMI_MSG_ENABLE_NEW_MESSAGE_SEQ_QUEUE_TIMEOUT
  UINT8           SeqQTimeout;
#endif
#ifdef HMI_MSG_UNIQUE_DISP_IND_TIME
  UINT16          DispIndTimeout;
#endif
#ifdef MSG_ENABLE_GROUP_ACKNOWLEDGEMENT
  eMessageAcknowledgeGroup AckGroup;
#endif
} MSG_MESSAGE_STRUCT;

typedef struct msgInstTimerStruct{
  UINT8 seq_DisplayTimer; /* seq_DisplayTimer       - Total time allowed to disply the warning */
  UINT8 seq_HoldTimer;    /* seq_HoldTimer          - Minimum warning display time even if warning is get deactivated (i.e. deactivated before min hold time) */
  UINT8 seq_CycleTimer;   /* seq_CycleTimer         - Allowable warning display Time during cycling mode */
  UINT8 seq_DispIndTimer; /* seq_DispIndTimer       -  Minimum Warning display time without iterruption */
  UINT8 seq_AckAftMinToutTimer; /* seq_AckAftMinToutTimer -  Allow the warning acknowledgement after "HMI_MSG_ACK_AFT_MIN_TIME" period */
#ifdef MSG_CYCLE_OPTION_WITH_TIMEOUT
  UINT8 seq_1secTimer;
#endif		
#ifdef HMI_MSG_ENABLE_NEW_MESSAGE_SEQ_QUEUE_TIMEOUT
  UINT8 seq_MsgQTimeout_1SecTimer;/* seq_MsgQTimeout_1SecTimer -  Used for 1 second time calculation for message Q timeout check */
#endif
#ifdef MSG_OLD_WRNG_REPETITION
  UINT8 seq_OldWrng_Rep_1SecTimer;/* Timer used for 1 second calculation for old warning repetition */
#endif  
#ifdef MSG_ACK_WRNG_REPETITION  
  UINT8 stor_AckWrng_Rep_Timer;
#endif  
} MSG_INST_TIMER_CONFIG_T;



/*--------------------------------------------------------------------------*/
/* Valid return states for message active condition.                        */
/*--------------------------------------------------------------------------*/
#define MSG_CONDITION_OFF           (0U)
#define MSG_CONDITION_ACTIVE        (1U)
#define MSG_CONDITION_FORCED        (2U)
#define MSG_CONDITION_RETRIGGER     (3U)

/*--------------------------------------------------------------------------*/
/* Message Options.                                                         */
/*--------------------------------------------------------------------------*/
#define MSG_OPTION_SEQUENCE                     (BIT0)
#define MSG_OPTION_STORE                        (BIT1)
#define MSG_OPTION_CLEARABLE                    (BIT2)
#define MSG_OPTION_CYCLE                        (BIT3)
#define MSG_OPTION_ACK_AFT_MIN_TOUT             (BIT4)
#define MSG_OPTION_DISP_INDICATIONTIME          (BIT5)
#define MSG_OPTION_ALLOW_LOW                    (BIT6)
#define MSG_OPTION_OVERRIDE_HIGH                (BIT7)
#define MSG_OPTION_SEQ_LIFO                     (BIT8)
#define MSG_OPTION_ALLOW_INACTIVE_TO_TIMEOUT    (BIT9)
#define MSG_OPTION_NEW_MSG_SEQ_Q_TIMEOUT        (BIT10)
#define MSG_OPTION_OLD_WRNG_REPEAT              (BIT11)
#define MSG_OPTION_ACK_WRNG_REPEAT              (BIT12)
#define MSG_OPTION_REM_FRM_SEQ_IN_NA_IGN_MODE   (BIT13)
#define MSG_OPTION_INS_AFT_CUR                  (BIT14)
#define MSG_OPTION_AUTO_CANCEL                  (BIT15)
#define MSG_OPTION_STASH_LOW                    (BIT16)

#define MSG_NO_TIMEOUT      (0u)
#define MSG_INDEX_UNDEFINED (miUndefined)
#ifndef MSG_NULL_PTR
#define MSG_NULL_PTR         ((void *)0)
#endif

#ifndef HMI_MSG_UNUSED_VAR
#define HMI_MSG_UNUSED_VAR(X)  do { if((UINT32)0 == ((UINT32)(X))){} } while(0==1)
#endif

/*--------------------------------------------------------------------------*/
/* Message View                                                             */
/*--------------------------------------------------------------------------*/
typedef struct msg_viewinfo
{
  eMessageIdentity Id;          /* Message ID                   */
  UINT16 Position;    /* Position in current list     */
  UINT16 Count;       /* Number of messages in list.  */
  UINT8  Status;      /* Indicates status of msg ID   */
  UINT8 InstanceID;
} MSG_VIEWINFO_T;


/*--------------------------------------------------------------------------*/
/* Viewer display options                                                   */
/*--------------------------------------------------------------------------*/
#define OPTION_VIEWER_NONE  (0)
#define OPTION_VIEWER_WRAP  (BIT0)

/*--------------------------------------------------------------------------*/
/* Callback indication                                                      */
/*--------------------------------------------------------------------------*/
#define MSG_EVENT_NONE             (0)     /* No event                                 */
#define MSG_EVENT_ACKNOWLEDGED     (BIT0)  /* Message has been acknowledged            */
#define MSG_EVENT_TIMEOUT          (BIT1)  /* Message has timed-out                    */
#define MSG_EVENT_HIDDEN           (BIT2)  /* Message has been hidden (by another)     */
#define MSG_EVENT_SHOW             (BIT3)  /* Message has been displayed               */
#define MSG_EVENT_ACTIVE           (BIT4)  /* Message has been activated by msg core   */
#define MSG_EVENT_INACTIVE         (BIT5)  /* Message has been de-activated by msg core*/
#define MSG_EVENT_OLD              (BIT6)  /* Message has become old(Newmessage flag cleared due to seq_dispIndTimer expiry */
#define MSG_EVENT_NEW_MSGQ_TIMEOUT (BIT7)  /* New message queue timer has timed-out */


/*--------------------------------------------------------------------------*/
/* VIEW INFO_T - Status - Bit field definition                              */
/*--------------------------------------------------------------------------*/
#define MSG_RECYCLE             (BIT0)  /* Indicates the message is already show */
#define MSG_NEW                 (BIT1)  /* Indicates the message is new or not */
#define MSG_DISPLAYED_ONCE      (BIT2)  /* Indicates the message once showed on display */
/* MSG_DISPLAYED_ONCE   -  1  --> This message is once comes on display
-  0  --> This message is not yet comes on display */

#ifdef HMI_MSG_ENABLE_NEW_MESSAGE_SEQ_QUEUE_TIMEOUT
/*--------------------------------------------------------------------------*/
/* MSG Timeout value configurations                                         */
/*--------------------------------------------------------------------------*/
#define HMI_MSG_SEQ_TIMEOUT_INVALID_U8         (0xffu)
#define HMI_MSG_SEC_TO_MILLISEC                (1000u)
#define HMI_MSG_VALUE_1                           1u
#endif

#ifdef MSG_OLD_WRNG_REPETITION
/* Invalid value to be loaded in old wrng repetiion duration array */
#define HMI_MSG_OLD_WRNG_REP_INVALID_U16     (0xffffU)
/* One second value to be decremented from old wrng repetiion duration array */
#define HMI_MSG_OLD_WRNG_1SEC_TIMEOUT_VALUE    1u
#endif

#ifdef MSG_ACK_WRNG_REPETITION

typedef enum{
  MSG_NOT_ADDED_FROM_STORE_QUEUE = 0,
  MSG_ADDED_FROM_STORE_QUEUE
}MSG_FROM_STORE_INFO;
/* Invalid value to be loaded in ack wrng repetiion duration array */
#define HMI_MSG_ACK_WRNG_REP_INVALID_U8      (0xffu)

#ifdef MSG_ACK_WRNG_REPEAT_TIMER_CONTROL
typedef enum
{
  ACK_WRNG_REP_TIMER_RESTART,
  ACK_WRNG_REP_TIMER_RESUME,
  ACK_WRNG_REP_TIMER_PAUSE
}eAckWrngRepTimerStatus;
#endif
#endif


/*==========================================================================*/
/* E N T R Y   P O I N T S                                                  */
/*==========================================================================*/

extern const MSG_MESSAGE_STRUCT messageList[MSG_NUM_MESSAGES];
extern UINT16 const hmi_msg_inst_config_count[MSG_NUM_INSTANCES];
extern MSG_INST_TIMER_CONFIG_T const hmi_msg_inst_config_table[MSG_NUM_INSTANCES];

/*==========================================================================*/
/* F U N C T I O N  P R O T O T Y P E S                                     */
/*==========================================================================*/
UINT16 msg_DefinitionGetDisplayTimeout(eMessageIdentity aMessage);

/*==========================================================================*/
/* R E V I S I O N    N O T E S                                             */
/*==========================================================================*/
/* For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**==========================================================================*/

/****************************************************************************
**  Date  : 07/Apr/2010
**  by    : AFERRIS2
**  Ref   : None.
**  Change: Initial version.
**
*****************************************************************************/

/****************************************************************************
**  Date: 06/May/2010     by: AFERRIS2        Ref: None.
**  Change: 1.  Changes to message structure to handle the 2 variants of the
**              Standard Interface
**
**  Checks: COMPILER - NO WARNINGS       QAC - NO WARNINGS
*****************************************************************************/

/****************************************************************************
**  Date: 29/Jun/2010     by: AFERRIS2        Ref:
**  Change: 1.  Add structure for viewer actions (used by sequencer and store
*8              modules).
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 07/Jul/2010     by: AFERRIS2        Ref:
**  Change: 1.  Add options for the viewers to wrap round.
**              Used by the sequencer and store modules.
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 07/Sep/2010     by: AFERRIS2        Ref:
**  Change: 1.  Add callback to notify source feature of actions taken.
**          2.  Add calback qualifiers to control which callbacks are generated.
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 27/04/2011     by: AFERRIS2        Ref: DCR 2131
**  Change: 1.  Added new field "HoldTimeout" to message structure.
**          2.  Renamed field "Timeout" to "DisplayTimeout".
**          3.  Added new bit field MSG_OPTION_CYCLE to message options.
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 28/04/2011     by: AFERRIS2        Ref: DCR 2131
**  Change: Add public function msg_DefinitionGetDisplayTimeout()
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 14/07/2011     by: VSARAVA2        Ref: BSDI00105821 (DCR 2131)
**  Change: Added Status member in sturucture in VIEW_INFO_T to hold bitwise
**          status of that message ID.
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 02/03/2012     by: VSARAVA2        Ref: BSDI00110074
**  Change: Macro added for MSG_RETRIGGER. To start the display timer of the
**          message if the message is already is showing (current message).
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 05/04/2013     by: ADEVI        Ref: PR64284
**  Change: Introduced option MSG_OPTION_ALLOW_INACTIVE_TO_TIMEOUT to allow
**          deactivated messages to get timed out.
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 25/Aug/2013     by: vsarava2        Ref: RTC 91916
**  Change: The below changes are added to support New warning Seq Q timeout
implementation to support Honda requirements.
1. Seq_q_timeout added in Msg structure
2. New msg Seq Q timeout option added
*****************************************************************************/

/****************************************************************************
**  Date: 27/Dec/2013     by: adevi               Ref: RTC 91916, PR 70887
**  Change: Peer review comments for New message queue time out
implementation fixed.
1. Seq_q_timeout added in Msg structure declared as UINT8
2. HMI_MSG_SEQ_TIMEOUT_INVALID_U16 value changed to 0xff
3. HMI_MSG_Q_1SEC_TIMEOUT_VALUE value is 1 which will be
decremented from Seq_q_timeout value.
*****************************************************************************/

/****************************************************************************
**  Date: 27/Dec/2013     by: adevi           Ref: RTC 91917
**  Change : Done for Old & Ack warning repetition implementation to support
**           Honda requirements.
**           1. MSG_OPTION_OLD_WRNG_REPEAT and MSG_OPTION_ACK_WRNG_REPEAT are
**              the options added.
**           2. Macros added to support above functionality
*****************************************************************************/

/****************************************************************************
**  Date: 09/Jan/2014     by: adevi            Ref: PR 72449
**  Change:
**  1. HMI_MSG_SEQ_TIMEOUT_INVALID_U16 --> HMI_MSG_SEQ_TIMEOUT_INVALID_U8.
**  2. Enum MSG_FROM_STORE_INFO added.
*****************************************************************************/

/****************************************************************************
**  Date: 28/Apr/2014     by: adevi            Ref: Bug 192
**  Change: 1. Introduced compiler switch HMI_MSG_UNIQUE_DISP_IND_TIME.
**  DispIndTimeout added in Msg structure declared as UINT8.
*****************************************************************************/

/****************************************************************************
**  Date: 28/Apr/2014     by: adevi            Ref: Bug 192, PR 752682
**  Change: 1. Peer review comments fixed.
**  DispIndTimeout added in Msg structure declared as UINT16.
*****************************************************************************/

/****************************************************************************
**  Date: 06/Oct/2014     by: adevi            Ref: RTC defect 203838
**  Change: 1. HMI_MSG_SEC_TO_MILLISEC macro introduced for sec to ms conversion.
**          2. HMI_MSG_VALUE_1 indicates value 1.
**          3.  New message status informed to application throught MSG_NEW bit
*****************************************************************************/

/****************************************************************************
**  Date: 10/Apr/2015     by: adevi        Ref:RTC 319901
**  Change: MSG_EVENT_OLD provided when seq_dispIndTimer expires and the newmessage
**  flag is getting cleared due to timer expiry.
*****************************************************************************/

/****************************************************************************
**  Date: 28/May/2015     by: adevi        Ref:RTC 324551
**  Change: Introduced option MSG_OPTION_REM_FRM_SEQ_IN_NA_IGN_MODE for hyundai.
*****************************************************************************/ 

/****************************************************************************
**  Date: 29/Jun/2015     by: adevi        Ref:RTC 366678, 365702
**  Change: Introduced event MSG_EVENT_NEW_MSGQ_TIMEOUT for hyundai. When the 
**  seq_NewMessgaeQueueTimeout value configured for the message, the message will
**  be removed from sequencer queue and seq_callback will be invoked by message
**  core with this event. QAC warning fix.
*****************************************************************************/ 

/****************************************************************************
**  Date: 13/Aug/2015     by: adevi        Ref:RTC 399553
**  Change: eAckWrngRepTimerStatus enum added.
*****************************************************************************/ 

/****************************************************************************
**  Date: 04/May/2017     by: arajase2
**  Ref: RTC 859438: CMFB MISRA Warning fixes - message.core
**  Change: MISRA warnings resolved for CMFB
*****************************************************************************/

/****************************************************************************
**  Date: 19/May/2017     by: aperumal
**  Ref: RTC 819714: Message.Priority max value support above 255 - message.core
*****************************************************************************/

/****************************************************************************
**  Date: 13/Jul/2017     by: arajase2
**  Ref: 910159: Message core update for insert new message after the current one
**  Change: Added MSG_OPTION_INS_AFT_CUR macro in message options
*****************************************************************************/

/****************************************************************************
**  Date: 12/Mar/2018     by: arajase2
**  Ref: 1063563: MMC : Msg Core - update for Auto cancel warning requirement
**  Change: Added MSG_OPTION_AUTO_CANCEL macro in message options
*****************************************************************************/
#endif  /* hmi_msgDefinition_H */
/* end of file =============================================================*/
