/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2011. Visteon Corporation owns all rights to this work and
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
** Name:           hmi_button.h
**
** Description:    Defines the available button IDs and available button events
**
** Organization:   GUI Software Section
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_BUTTON_H
#define HMI_BUTTON_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/


#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
/*
** Available button events
*/
enum{
   BTN_EV_RELEASE,		  /* indicates that the button is released        */
   BTN_EV_PRESS,		  /*                              pressed         */
   BTN_EV_HELD,			  /*                              held for N sec  */
   BTN_EV_REPEAT,		  /* Generated at regular interval of N sec after 
                             the button is held for M sec  */
   BTN_EV_MAX			  /* Indicates end of event list */
};

/*
** List of available buttons
*/
enum{
   BTN_ID_POWER,
   BTN_ID_UP,
   BTN_ID_DN,
   BTN_ID_LT,
   BTN_ID_RT,
   BTN_ID_ENTER,
   BTN_ID_INFO_POPUP,
   BTN_ID_ACK_POPUP,
   BTN_ID_PROGRESS_POPUP,
   BTN_ID_KEYPAD_POPUP,
   BTN_ID_HARD_WRNG,
   BTN_ID_SOFT_WRNG,
   BTN_ID_INFO_WRNG,
   BTN_ID_DEACTIVATE_WRNG,
   BTN_ID_0,
   BTN_ID_1,
   BTN_ID_2,
   BTN_ID_3,
   BTN_ID_4,
   BTN_ID_5,
   BTN_ID_6,
   BTN_ID_7,
   BTN_ID_8,
   BTN_ID_9,
   BTN_ID_MENU,
   BTN_ID_ESC,
   BTN_ID_GENWRNG,
   BTN_ID_GENWRNG2,
   BTN_ID_GENWRNG3,
   BTN_ID_MAX
};


/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

/*============================================================================
** D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

/*============================================================================
**
**============================================================================
** C M S    R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================
**
** Rev 1.0         11-Mar-15     EMANOJ1
** Creation.
**
**==========================================================================*/
#ifdef  __cplusplus
}
#endif
/* end of file =============================================================*/
#endif
