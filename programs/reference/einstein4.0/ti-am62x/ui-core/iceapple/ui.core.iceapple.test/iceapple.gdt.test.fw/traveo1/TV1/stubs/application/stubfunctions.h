/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2010. Visteon Corporation owns all rights to this work and
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
** Name:           stubfunctions.h
**
** Description:    Public header file for timer_support functionality
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**==========================================================================*/

#ifndef STUBFUNCTIONS_H
#define STUBFUNCTIONS_H

#include "hmi_SIF.h"

extern SIF_STATUS ui_msg_notify_status_cb(UINT8* Data, UINT8 Qualifier);
extern SIF_STATUS ui_msg_get_status(UINT8* Data, UINT8 Qualifier);
/*************************************************************************//**
 * \details     This function retrieves the requested warning details
 *
 * \param[in]   warning_id - UI_WARNING_ID_T system warning unique id
 *
 * \param[out]  ptr_warning_data - Pointer to UI_PTR_WARNING_DATA_T structure to get
 *              requested warning status and details
 *
 * \retval      None
 *
 ****************************************************************************/

extern void hmi_set_warning(void);
extern void hmi_clear_warning(void);
extern void hmi_add_menu(void);
extern void hmi_close_menu(void);
extern void hmi_toggle_mode(void);
#endif
