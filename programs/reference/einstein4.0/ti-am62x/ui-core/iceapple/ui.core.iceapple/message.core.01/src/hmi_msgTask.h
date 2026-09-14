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
**  Name:               hmi_msgTask.h
**
**  Description:
**
**  Organization:       Driver Information Software Section,
**                      DI Core Engineering Department
**
**===========================================================================*/
#ifndef hmi_msgTask_H
#define hmi_msgTask_H

/*==========================================================================*/
/* I N C L U D E   F I L E S                                                */
/*==========================================================================*/
#include "hmi_msgArbitrator.h"
#include "hmi_msgDefinition.h"
#include "hmi_msgSequencer.h"
#include "hmi_msgStore.h"
#include "hmi_SIF.h"

/*==========================================================================*/
/* T Y P E   D E F I N I T I O N S                                          */
/*==========================================================================*/

/*------------------------------------------------------------------*/
/* Status: Module definitions                                       */
/*------------------------------------------------------------------*/
#define MSG_SEQUENCER_CATEGORY  (0x01UL)
#define MSG_STORE_CATEGORY      (0x02UL)
#define MSG_ALL_CATEGORY        (MSG_SEQUENCER_CATEGORY|MSG_STORE_CATEGORY)
#define MSG_NONE_CATEGORY       (0UL)

/*------------------------------------------------------------------*/
/* Status: Option definitions                                       */
/*  MSG_CATEGORY_LATCH_QUALIFIER: When set, qualification data is   */
/*      latched and used to automaticallly report status changes.   */
/*------------------------------------------------------------------*/
#define MSG_CATEGORY_LATCH_QUALIFIER    (0x00000100UL)

/*------------------------------------------------------------------*/
/* Status: Helper macro to define the threshold value               */
/*------------------------------------------------------------------*/
#define MSG_THRESHOLD_BITPOS    (16)
#define MSG_CATEGORY_THRESHOLD(n)   ((n) << (MSG_THRESHOLD_BITPOS))

/*==========================================================================*/
/* E N T R Y   P O I N T S                                                  */
/*==========================================================================*/

/*==========================================================================*/
/* F U N C T I O N  P R O T O T Y P E S                                     */
/*==========================================================================*/
void hm_msg_KSColdInit(void);
void hm_msg_KSWarmInit(void);
void hm_msg_KSRRobin(void);
void hm_msg_KSSleep(void);
void hm_msg_KSWakeup(void);
BOOLEAN hm_msg_KSNvRamCheck(void);

#if MSG_NUM_INSTANCES > 1
U32SIF_STANDARD_INTERFACE_MULTI_INST(hm_msg_GetStatus);
#else 
U32SIF_STANDARD_INTERFACE(hm_msg_GetStatus);
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
**  Date: 19/Oct/2010     by: AFERRIS2        Ref:
**  Change: 1.  New standard interface hm_msg_GetStatus()
**          2.  Added definitions for use with this interface.
**
**  Checks: COMPILER - NO WARNINGS       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 04/May/2017     by: arajase2
**  Ref: RTC 859438: CMFB MISRA Warning fixes - message.core
**  Change: MISRA warnings resolved for CMFB
*****************************************************************************/

#endif  /* hmi_msgTask_H */
/* end of file =============================================================*/
