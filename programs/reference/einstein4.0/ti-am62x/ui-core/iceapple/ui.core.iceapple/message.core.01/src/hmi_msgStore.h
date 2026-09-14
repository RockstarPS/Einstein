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
**  Name:               hmi_msgStore.h
**
**  Description:        Definitions for the message core STORE module.
**                  *** DO NOT INCLUDE THIS FILE FROM AN EXTERNAL PACKAGE ***
**
**  Organization:       Driver Information Software Section,
**                      DI Core Engineering Department
**
**===========================================================================*/
#ifndef hmi_msgStore_H
#define hmi_msgStore_H

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

extern eMessageIdentity stor_MessageList[MSG_NUM_INSTANCES][MSG_NUM_MESSAGES+1];

/*==========================================================================*/
/* F U N C T I O N  P R O T O T Y P E S                                     */
/*==========================================================================*/
void msg_StoreInitialise(UINT8 inst);

void msg_StoreAdd(eMessageIdentity MessageID);
BOOLEAN msg_StoreRemove(eMessageIdentity MessageID);
BOOLEAN msg_StoreIsMsgPresentInStoreQueue(const eMessageIdentity MessageID);
void msg_StorePurgeFromList(UINT32 FilterOptions,UINT8 inst);
UINT32 stor_GetCategories(UINT32 Threshold,UINT8 inst);

#ifdef MSG_ACK_WRNG_REPETITION
extern BOOLEAN l_MsgAddedFromStoreQueue[MSG_NUM_INSTANCES];
void msg_StorAckWrngRepUpdate(UINT8 p_inst);
#endif 

#ifdef MSG_ACK_WRNG_REPEAT_TIMER_CONTROL
#if MSG_NUM_INSTANCES > 1
void msg_StorAckWrngRepTimerControl(eAckWrngRepTimerStatus p_AckWrngRepTimerAction,UINT8 p_inst);
#else
void msg_StorAckWrngRepTimerControl(eAckWrngRepTimerStatus p_AckWrngRepTimerAction);
#endif
#endif
/*----------------------------------------------------------------------*/
/* Viewer interface                                                     */
/*----------------------------------------------------------------------*/
#if MSG_NUM_INSTANCES > 1
NULSIF_STANDARD_INTERFACE_MULTI_INST(msg_StoreGetCurrent);
NULSIF_STANDARD_INTERFACE_MULTI_INST(msg_StoreSelectFirst);
NULSIF_STANDARD_INTERFACE_MULTI_INST(msg_StoreSelectNext);
NULSIF_STANDARD_INTERFACE_MULTI_INST(msg_StoreSelectPrevious);
#else 
NULSIF_STANDARD_INTERFACE(msg_StoreGetCurrent);
NULSIF_STANDARD_INTERFACE(msg_StoreSelectFirst);
NULSIF_STANDARD_INTERFACE(msg_StoreSelectNext);
NULSIF_STANDARD_INTERFACE(msg_StoreSelectPrevious);
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
**  Change: 1.  Update interface functions to use the formal Standard Interface.
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 07/Jul/2010     by: AFERRIS2        Ref:
**  Change: 1.  Updated public interface using the standard interface.
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 19/Oct/2010     by: AFERRIS2        Ref:
**  Change: 1. New public function stor_GetCategories()
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 20/Oct/2010     by: AFERRIS2        Ref:
**  Change: 1.  Updated interface stor_GetCategories().
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 27/Dec/2013     by: adevi           Ref: RTC 91917
**  Ack warning repetition implementation to support Honda requirements.
*****************************************************************************/

/****************************************************************************
**  Date: 09/Jan/2014     by: adevi            Ref: PR 72449
**  Change: 1. MsgAddedFromStoreQueue declared extern
*****************************************************************************/

/****************************************************************************
**  Date: 13/Aug/2015     by: adevi        Ref:RTC 399553
**  Change: msg_StorAckWrngRepTimerControl function added.
*****************************************************************************/ 

/****************************************************************************
**  Date: 04/May/2017     by: arajase2
**  Ref: RTC 859438: CMFB MISRA Warning fixes - message.core
**  Change: MISRA warnings resolved for CMFB
*****************************************************************************/

#endif  /* hmi_msgStore_H */
/* end of file =============================================================*/
