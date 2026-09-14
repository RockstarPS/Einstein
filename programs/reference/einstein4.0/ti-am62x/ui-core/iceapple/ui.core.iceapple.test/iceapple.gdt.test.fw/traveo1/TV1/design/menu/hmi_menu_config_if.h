/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2012. Visteon Corporation owns all rights to this work and
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
** Name:           hmi_menu_config_if.h
**
** Description:    File contains Menu Definitions.
**
** Organization:   Driver Information Software Section,
**                 Visteon
**
**============================================================================
**
**==========================================================================*/
#include "hmiapp_stub.h"
#include "hmi_logic_state_handler.h"
#include "hmi_menu_core_01_logic.h"
#include "hmi_menu_core_01_types.h"

/*****************************************************************************
*                                 Global Constant Declarations		         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the constant.                                                        *
* Purpose, unit and resolution                                               *
******************************************************************************/

/*****************************************************************************
*                                 Global Macro Definitions                   *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/*****************************************************************************
*                                 Type Declaration                           *
*----------------------------------------------------------------------------*
* Declaration of type shall be accompanied by a comment that explains the    *
* purpose and usage of the type.                                             *
******************************************************************************/

/*****************************************************************************
*                                 Global Variable Declarations               *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, resolution, Valid Range and ValidityCheck *
******************************************************************************/

/*****************************************************************************
*                                 Global Function Prototypes                 *
******************************************************************************/
extern void hmi_menu_root_presentation_handler(MENU_CONTROL_T* p_menu_control_SP, UINT8_T p_lsh_status_U8);
extern void hmi_menu_tc_group_presentation_handler(MENU_CONTROL_T* p_menu_control_SP, UINT8_T p_lsh_status_U8);
extern MENU_CB_RESULT_T hmi_menu_root_callback(MENU_ACTION_T p_menu_action, MENU_CONTROL_T* hmi_menu_app, UINT16_T p_button_command_U16);
extern MENU_CB_RESULT_T hmi_menu_tc_group_callback(MENU_ACTION_T p_menu_action, MENU_CONTROL_T* hmi_menu_app, UINT16_T p_button_command_U16);
extern UINT8 hmi_menu_root_items_config_callback(UINT16 p_entry_val_U16, MENU_LIST_ID_T p_menu_ID_e);
extern UINT8 hmi_menu_tc_group_items_config_callback(UINT16 p_entry_val_U16, MENU_LIST_ID_T p_menu_ID_e);

extern UINT8 hmi_menu_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T* p_event_hndl_status_SP);
extern void hmi_menu_set_focus_handler(LSH_FOCUS_HANDLER_STATUS_T* p_presen_hndl_status_SP);
extern void hmi_menu_presentation_handler(LSH_PRESN_HANDLER_STATUS_T* p_presen_hndl_status_SP);

