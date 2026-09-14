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
**  Name:               hmi_msgTypes.h
**
**  Description:
**
**  Organization:       Driver Information Software Section,
**                      DI Core Engineering Department
**
**===========================================================================*/
#ifndef hmi_msgTypes_H
#define hmi_msgTypes_H

/*==========================================================================*/
/* I N C L U D E   F I L E S                                                */
/*==========================================================================*/

/*==========================================================================*/
/* T Y P E   D E F I N I T I O N S                                          */
/*==========================================================================*/

/*----------------------------------------------------------------------*/
/* Software timer support.                                              */
/*----------------------------------------------------------------------*/
/* Note: Private timers MUSt be used for this option. */
#define MSG_START_SW_TIMER(timeout, timer)  test_StartTimer(timeout, timer)
#define MSG_CLEAR_SW_TIMER(timer)           test_ClearTimer(timer)
#define MSG_CHECK_SW_TIMER(timer)           test_CheckTimer(timer)

/*----------------------------------------------------------------------*/
/* Button event handling.                                               */
/* Set these macros to the values expected by the button event handler. */
/*----------------------------------------------------------------------*/
#define MSG_ACKNOWLEDGE_BUTTON_EVENT    (0x0011)
#define MSG_UP_BUTTON_EVENT             (0x0011)
#define MSG_DOWN_BUTTON_EVENT           (0x0011)
#define MSG_BTN_NONE                    (0)
#define MSG_BTN_NOACTION                10
#define MSG_BTN_CHANGED                 20

/*==========================================================================*/
/* E N T R Y   P O I N T S                                                  */
/*==========================================================================*/

/*==========================================================================*/
/* F U N C T I O N  P R O T O T Y P E S                                     */
/*==========================================================================*/

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
**  Date: 18/Jun/2010     by: AFERRIS2        Ref:
**  Change:
**  1.  Corrected timer declarations for use with timers referenced by ID
**  2.  Added comment that the unit test option requires private timers.
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

#endif  /* hmi_msgTypes_H */
/* end of file =============================================================*/
