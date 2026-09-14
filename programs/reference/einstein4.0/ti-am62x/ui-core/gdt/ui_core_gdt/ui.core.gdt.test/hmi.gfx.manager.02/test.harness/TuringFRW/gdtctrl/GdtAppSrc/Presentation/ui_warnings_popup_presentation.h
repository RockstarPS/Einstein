/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2014. Visteon Corporation owns all rights to this work and
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
** Name:           ui_warnings_presentation.h
**
** Description:    Header Footer Presentation header file.
**                 Kepler II Amber I/Amber P Platform.
**
** Organization:   Driver Information Software Section,
**
**============================================================================
**
**==========================================================================*/
#ifndef UI_WARNINGS_PRESENTATION_H
#define UI_WARNINGS_PRESENTATION_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif

/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

/*============================================================================
** D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/
/* Define the warning ids from highest to lowest priority */
typedef enum{
	NO_WARN,
	OVERSPEED_WARN,
	DOOR_AJAR_WARN,
	CHECK_BRAKE_WARN,
	TIRE_PRESSURE_WARN,
	NEUTRAL_TOW_ENABLED_WARN,
	NEUTRAL_TOW_DISABLED_WARN,
	MYKEY_ACTIVE_DRIVE_SAFELY_WARN,
	SLOW_HDC_WARN,
	MAX_WARNING_ID
} WARNING_ID;

/* Define warning status */
typedef enum{
	WARNING_STATE_NOT_ACTIVE,
	WARNING_STATE_ACTIVE,
	WARNING_STATE_ACKNOWLEDGED,
	WARNING_STATE_UNATTENDED,
	WARNING_STATE_INVALID = -1
} WARNING_STATE;

extern WARNING_STATE l_warning_interface[MAX_WARNING_ID];
extern int hmi_amethyst_is_any_warning_state(WARNING_STATE state);
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
** CMS Rev 0.1     20-Oct-2014    ASHEKHAR
** 
**==========================================================================*/
#ifdef  __cplusplus
}
#endif

/* end of file =============================================================*/
#endif
