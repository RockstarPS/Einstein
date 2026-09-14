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
**  Name:               ui_msgTypes.h
**
**  Description:
**
**  Organization:       Driver Information Software Section,
**                      DI Core Engineering Department
**
**===========================================================================*/

/*==========================================================================*/
/* I N C L U D E   F I L E S                                                */
/*==========================================================================*/
#ifndef warn_msgTypes_H
#define warn_msgTypes_H

//#include "Rte_UiCtrl_Button_Type.h"
#include "Mdl_Button.h"
/*==========================================================================*/
/* T Y P E   D E F I N I T I O N S                                          */
/*==========================================================================*/

/*----------------------------------------------------------------------*/
/* Software timer support.                                              */
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/* Button event handling.                                               */
/* Set these macros to the values expected by the button event handler. */
/*----------------------------------------------------------------------*/
#define MSG_ACKNOWLEDGE_BUTTON_EVENT    HM_BTN_EV_BACK_SHORT
#define MSG_UP_BUTTON_EVENT             HM_BTN_EV_LEFT_SHORT
#define MSG_DOWN_BUTTON_EVENT           HM_BTN_EV_RIGHT_SHORT

#define MSG_BTN_NONE                   (0x00)
#define MSG_BTN_NOACTION               (0x01)
#define MSG_BTN_CHANGED                (0x01)

#define MSG_ACKNOWLEDGE_ALL_BUTTON_EVENT HM_BTN_EV_BACK_LONG_IN
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
**  Date  : 07/July/2010
**  by    : spandian
**  Ref   : None.
**  Change: Up , down and Set events configured.
**
*****************************************************************************/

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
/*---------------------------------------------------------------------------
Date              : 24-Sept-2012
CDSID             : nsatyapr
Traceability      : 
Change Description: Initial Version
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :	15-Feb-2013
By                :	nsatyapr
Traceability      :	
Change Description: Warning acknowledgment change to DISP left, DISP right and
                    Back buttons
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 16-01-2023
By                : pkc
Traceability      : 1884947
Change Description: replaced new butten event for Message Tab Implimentation
-----------------------------------------------------------------------------*/
#endif  /* hmi_msgTypes_H */
/* end of file =============================================================*/
