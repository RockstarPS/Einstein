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
**  Name:               hmi_msgSequencer.h
**
**  Description:        Definitions for the message core SEQUENCER module.
**                  *** DO NOT INCLUDE THIS FILE FROM AN EXTERNAL PACKAGE ***
**
**  Organization:       Driver Information Software Section,
**                      DI Core Engineering Department
**
**===========================================================================*/
#ifndef hmi_msgSequencer_H
#define hmi_msgSequencer_H

/*==========================================================================*/
/* I N C L U D E   F I L E S                                                */
/*==========================================================================*/
#include "system.h"
#include "hmi_SIF.h"
#include "hmi_msgDefinition.h"

/*==========================================================================*/
/* T Y P E   D E F I N I T I O N S                                          */
/*==========================================================================*/


/*==========================================================================*/
/* E N T R Y   P O I N T S                                                  */
/*==========================================================================*/

/*==========================================================================*/
/* F U N C T I O N  P R O T O T Y P E S                                     */
/*==========================================================================*/
void msg_SequencerInitialise(UINT8 inst);
void msg_SequencerUpdate(UINT8 Ignition,UINT8 inst);

void msg_SequencerAdd(eMessageIdentity MessageID);
UINT8 msg_SequencerRemove(eMessageIdentity MessageID, UINT8 Ignition);
void msg_SequencerRetrigger(eMessageIdentity MessageID);
void msg_SequencerForcedActive(eMessageIdentity MessageID);


#ifdef MSG_OLD_WRNG_REPETITION
void msg_SequencerOldWrngRepUpdate(UINT8 p_inst);
#endif
#ifdef HMI_MSG_ENABLE_NEW_MESSAGE_SEQ_QUEUE_TIMEOUT
void msg_SequencerNewMsgQTimeoutUpdate(UINT8 p_inst);
#endif
#if (MSG_NUM_INSTANCES > 1)
void msg_SequencerShow(UINT8 p_inst);
UINT8 msg_SequencerAction(UINT16 Button,UINT8 p_inst);
UINT32 seq_GetCategories(UINT32 Threshold,UINT8 p_inst);
void msg_SequencerHide(UINT8 p_inst);
#else
void msg_SequencerShow(void);
UINT8 msg_SequencerAction(UINT16 Button);
UINT32 seq_GetCategories(UINT32 Threshold);
void msg_SequencerHide(void);
#endif



#ifdef MSG_ACK_WRNG_REPETITION
void msg_ClearNewMessageFlag(eMessageIdentity MessageID);
#ifdef MSG_OLD_WRNG_REPETITION
void msg_SetOldWrngRepDur(eMessageIdentity MessageID);
#endif
#endif

#if (MSG_NUM_INSTANCES > 1)
/*----------------------------------------------------------------------*/
/* Alert interface                                                      */
/*----------------------------------------------------------------------*/
NULSIF_STANDARD_INTERFACE_MULTI_INST(msg_SequencerGetAlertInfo);
U32SIF_STANDARD_INTERFACE_MULTI_INST(msg_SequencerGetMessage);

/*----------------------------------------------------------------------*/
/* Viewer interface                                                     */
/*----------------------------------------------------------------------*/
NULSIF_STANDARD_INTERFACE_MULTI_INST(msg_SequencerGetCurrent);
NULSIF_STANDARD_INTERFACE_MULTI_INST(msg_SequencerSelectFirst);
NULSIF_STANDARD_INTERFACE_MULTI_INST(msg_SequencerSelectNext);
NULSIF_STANDARD_INTERFACE_MULTI_INST(msg_SequencerSelectPrevious);



#else
NULSIF_STANDARD_INTERFACE(msg_SequencerGetAlertInfo);
U32SIF_STANDARD_INTERFACE(msg_SequencerGetMessage);

/*----------------------------------------------------------------------*/
/* Viewer interface                                                     */
/*----------------------------------------------------------------------*/
NULSIF_STANDARD_INTERFACE(msg_SequencerGetCurrent);
NULSIF_STANDARD_INTERFACE(msg_SequencerSelectFirst);
NULSIF_STANDARD_INTERFACE(msg_SequencerSelectNext);
NULSIF_STANDARD_INTERFACE(msg_SequencerSelectPrevious);


#endif


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
**  Change: 1.  Change return type of msg_SequencerRemove() to void.
**          2.  Update public access functions to use the formal Standard Interface.
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 29/Jun/2010     by: AFERRIS2        Ref:
**  Change: 1. Add function prototypes for new viewer interface.
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 07/Jul/2010     by: AFERRIS2        Ref:
**  Change: 1. Modified public interface using the standard interface.
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 07/Sep/2010     by: AFERRIS2        Ref:
**  Change: 1.  Standard Interface Function to get current alert information.
**          2.  Add test functions to manipulate internal timers.
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 19/Oct/2010     by: AFERRIS2        Ref:
**  Change: 1. New public function seq_GetCategories().
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 20/Oct/2010     by: AFERRIS2        Ref:
**  Change: 1.  Updated interface seq_GetCategories().
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 27/04/2011     by: AFERRIS2        Ref: DCR 2131
**  Change: 1.  Add new timer access function for HOLD timer
**              (used for unit test only)
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 04/05/2011     by: AFERRIS2        Ref: BSDI00102410
**  Change: 1.  Add standard interface to check if a specified message is active.
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 13/03/2012     by: VSARAVA2        Ref: BSDI00112440 /BSDI00111853
**  Change: 1.  Add prototype for msg SequencerRetrgger().
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 10/Aug/2013     by: vsarava2        Ref: RTC 60620
**  MsgSequencerRemove shall return the msg removed status from Sequencer.
**
*****************************************************************************/

/****************************************************************************
**  Date: 25/Aug/2013     by: vsarava2        Ref: RTC 91916
**  New warning Seq Q timeout implementation to support Honda requirements.
*****************************************************************************/

/****************************************************************************
**  Date: 27/Dec/2013     by: adevi           Ref: RTC 91917
**  Old & Ack warning repetition implementation to support Honda requirements.
*****************************************************************************/

/****************************************************************************
**  Date: 09/Jan/2014     by: adevi            Ref: PR 72449
**  Change: 1. msgClearNewMessageFlag name changed to msg_ClearNewMessageFlag.
**  2.  msgSetOldWrngRepDur name changed to msg_SetOldWrngRepDur.
*****************************************************************************/


#endif  /* hmi_msgSequencer_H */
/* end of file =============================================================*/
