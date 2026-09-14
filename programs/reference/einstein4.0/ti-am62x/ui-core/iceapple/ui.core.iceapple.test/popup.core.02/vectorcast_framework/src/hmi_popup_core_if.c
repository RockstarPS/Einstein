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
**==========================================================================*/

/*============================================================================
**
** Name:           hmi_popup_core_if.c
**
** Description:    
                   This file has the implementation of the Interface file
                    from the Popup Core component to the Application SW
**                 
** Organization:   Driver Information Software Section,
**                 Visteon
**
**============================================================================
**
**==========================================================================*/
#define     HMI_POPUP_CORE_IF_C
#include "system.h"
#include "hmi_popup_core_if.h"
#include "hmi_logic_state_handler.h"

/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/

/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/

/*============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/
/*============================================================================
** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

/*============================================================================
* Function                  : hmi_popup_core_layer0_rx_button_handler
* Visibility                : Global
* Description               : 
                              This function receives all the button events from the 
                              LSH and pass it to the popup core
* Inputs/Outputs            : 
                              p_button_ID - Button Events
                               p_button_state - Press, Realase of a Button
* Invocation                : Invoked by the LSH when a popup is active
* Critical Section          : None
* Created                   : Autocreated on d
*                             Please do not modify
============================================================================*/
UINT8 hmi_popup_core_layer0_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
    return(hmi_popup_core_rx_button_handler(L_POPUP_LAYER0_ID, p_event_hndl_status_SP));
}

/*============================================================================
* Function                  : hmi_popup_core_layer0_disp_foucus_handler
* Visibility                : Global
* Description               : 
                              This function will be called by the LSH when ever Popu
                              p of this level is gaining focus or loosing its curren
                              t focus
* Inputs/Outputs            : 
                              p_button_ID - Button Events
                               p_focus_U8 - Gained Focus/ Lost Focus
* Invocation                : Invoked by the LSH when a popup is active
* Critical Section          : None
* Created                   : Autocreated on d
*                             Please do not modify
============================================================================*/
void hmi_popup_core_layer0_disp_foucus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP)
{
    hmi_popup_core_focus_handler(L_POPUP_LAYER0_ID, p_focus_hndl_status_SP);
}

/*============================================================================
* Function                  : hmi_popup_core_layer0_disp_presentation_handler
* Visibility                : Global
* Description               : 
                              This function will be called by the LSH when ever a po
                              pup has to be displayed or refreshed
* Inputs/Outputs            : 
                              p_button_ID - Button Events
                               p_status_U8 - Activated/ Deactivated/ Refresh
* Invocation                : Invoked by the LSH when a popup is active
* Critical Section          : None
* Created                   : Autocreated on d
*                             Please do not modify
============================================================================*/
void hmi_popup_core_layer0_disp_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
    hmi_popup_core_presentation_handler(L_POPUP_LAYER0_ID, p_presn_hndl_status_SP);
}

/*============================================================================
* Function                  : hmi_popup_core_layer1_rx_button_handler
* Visibility                : Global
* Description               : 
                              This function receives all the button events from the 
                              LSH and pass it to the popup core
* Inputs/Outputs            : 
                              p_button_ID - Button Events
                               p_button_state - Press, Realase of a Button
* Invocation                : Invoked by the LSH when a popup is active
* Critical Section          : None
* Created                   : Autocreated on d
*                             Please do not modify
============================================================================*/
UINT8 hmi_popup_core_layer1_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
    return(hmi_popup_core_rx_button_handler(L_POPUP_LAYER1_ID, p_event_hndl_status_SP));
}

/*============================================================================
* Function                  : hmi_popup_core_layer1_disp_foucus_handler
* Visibility                : Global
* Description               : 
                              This function will be called by the LSH when ever Popu
                              p of this level is gaining focus or loosing its curren
                              t focus
* Inputs/Outputs            : 
                              p_button_ID - Button Events
                               p_focus_U8 - Gained Focus/ Lost Focus
* Invocation                : Invoked by the LSH when a popup is active
* Critical Section          : None
* Created                   : Autocreated on d
*                             Please do not modify
============================================================================*/
void hmi_popup_core_layer1_disp_foucus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP)
{
    hmi_popup_core_focus_handler(L_POPUP_LAYER1_ID, p_focus_hndl_status_SP);
}

/*============================================================================
* Function                  : hmi_popup_core_layer1_disp_presentation_handler
* Visibility                : Global
* Description               : 
                              This function will be called by the LSH when ever a po
                              pup has to be displayed or refreshed
* Inputs/Outputs            : 
                              p_button_ID - Button Events
                               p_status_U8 - Activated/ Deactivated/ Refresh
* Invocation                : Invoked by the LSH when a popup is active
* Critical Section          : None
* Created                   : Autocreated on d
*                             Please do not modify
============================================================================*/
void hmi_popup_core_layer1_disp_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
    hmi_popup_core_presentation_handler(L_POPUP_LAYER1_ID, p_presn_hndl_status_SP);
}

/*============================================================================
* Function                  : hmi_popup_core_layer5_rx_button_handler
* Visibility                : Global
* Description               : 
                              This function receives all the button events from the 
                              LSH and pass it to the popup core
* Inputs/Outputs            : 
                              p_button_ID - Button Events
                               p_button_state - Press, Realase of a Button
* Invocation                : Invoked by the LSH when a popup is active
* Critical Section          : None
* Created                   : Autocreated on d
*                             Please do not modify
============================================================================*/
UINT8 hmi_popup_core_layer5_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
    return(hmi_popup_core_rx_button_handler(L_POPUP_LAYER5_ID, p_event_hndl_status_SP));
}

/*============================================================================
* Function                  : hmi_popup_core_layer5_disp_foucus_handler
* Visibility                : Global
* Description               : 
                              This function will be called by the LSH when ever Popu
                              p of this level is gaining focus or loosing its curren
                              t focus
* Inputs/Outputs            : 
                              p_button_ID - Button Events
                               p_focus_U8 - Gained Focus/ Lost Focus
* Invocation                : Invoked by the LSH when a popup is active
* Critical Section          : None
* Created                   : Autocreated on d
*                             Please do not modify
============================================================================*/
void hmi_popup_core_layer5_disp_foucus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP)
{
    hmi_popup_core_focus_handler(L_POPUP_LAYER5_ID, p_focus_hndl_status_SP);
}

/*============================================================================
* Function                  : hmi_popup_core_layer5_disp_presentation_handler
* Visibility                : Global
* Description               : 
                              This function will be called by the LSH when ever a po
                              pup has to be displayed or refreshed
* Inputs/Outputs            : 
                              p_button_ID - Button Events
                               p_status_U8 - Activated/ Deactivated/ Refresh
* Invocation                : Invoked by the LSH when a popup is active
* Critical Section          : None
* Created                   : Autocreated on d
*                             Please do not modify
============================================================================*/
void hmi_popup_core_layer5_disp_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
    hmi_popup_core_presentation_handler(L_POPUP_LAYER5_ID, p_presn_hndl_status_SP);
}

/*============================================================================
* Function                  : hmi_popup_core_layer9_rx_button_handler
* Visibility                : Global
* Description               : 
                              This function receives all the button events from the 
                              LSH and pass it to the popup core
* Inputs/Outputs            : 
                              p_button_ID - Button Events
                               p_button_state - Press, Realase of a Button
* Invocation                : Invoked by the LSH when a popup is active
* Critical Section          : None
* Created                   : Autocreated on d
*                             Please do not modify
============================================================================*/
UINT8 hmi_popup_core_layer9_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
    return(hmi_popup_core_rx_button_handler(L_POPUP_LAYER9_ID, p_event_hndl_status_SP));
}

/*============================================================================
* Function                  : hmi_popup_core_layer9_disp_foucus_handler
* Visibility                : Global
* Description               : 
                              This function will be called by the LSH when ever Popu
                              p of this level is gaining focus or loosing its curren
                              t focus
* Inputs/Outputs            : 
                              p_button_ID - Button Events
                               p_focus_U8 - Gained Focus/ Lost Focus
* Invocation                : Invoked by the LSH when a popup is active
* Critical Section          : None
* Created                   : Autocreated on d
*                             Please do not modify
============================================================================*/
void hmi_popup_core_layer9_disp_foucus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP)
{
    hmi_popup_core_focus_handler(L_POPUP_LAYER9_ID, p_focus_hndl_status_SP);
}

/*============================================================================
* Function                  : hmi_popup_core_layer9_disp_presentation_handler
* Visibility                : Global
* Description               : 
                              This function will be called by the LSH when ever a po
                              pup has to be displayed or refreshed
* Inputs/Outputs            : 
                              p_button_ID - Button Events
                               p_status_U8 - Activated/ Deactivated/ Refresh
* Invocation                : Invoked by the LSH when a popup is active
* Critical Section          : None
* Created                   : Autocreated on d
*                             Please do not modify
============================================================================*/
void hmi_popup_core_layer9_disp_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
    hmi_popup_core_presentation_handler(L_POPUP_LAYER9_ID, p_presn_hndl_status_SP);
}

/*============================================================================
* Function                  : hmi_popup_core_layer10_rx_button_handler
* Visibility                : Global
* Description               : 
                              This function receives all the button events from the 
                              LSH and pass it to the popup core
* Inputs/Outputs            : 
                              p_button_ID - Button Events
                               p_button_state - Press, Realase of a Button
* Invocation                : Invoked by the LSH when a popup is active
* Critical Section          : None
* Created                   : Autocreated on d
*                             Please do not modify
============================================================================*/
UINT8 hmi_popup_core_layer10_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
    return(hmi_popup_core_rx_button_handler(L_POPUP_LAYER10_ID, p_event_hndl_status_SP));
}

/*============================================================================
* Function                  : hmi_popup_core_layer10_disp_foucus_handler
* Visibility                : Global
* Description               : 
                              This function will be called by the LSH when ever Popu
                              p of this level is gaining focus or loosing its curren
                              t focus
* Inputs/Outputs            : 
                              p_button_ID - Button Events
                               p_focus_U8 - Gained Focus/ Lost Focus
* Invocation                : Invoked by the LSH when a popup is active
* Critical Section          : None
* Created                   : Autocreated on d
*                             Please do not modify
============================================================================*/
void hmi_popup_core_layer10_disp_foucus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP)
{
    hmi_popup_core_focus_handler(L_POPUP_LAYER10_ID, p_focus_hndl_status_SP);
}

/*============================================================================
* Function                  : hmi_popup_core_layer10_disp_presentation_handler
* Visibility                : Global
* Description               : 
                              This function will be called by the LSH when ever a po
                              pup has to be displayed or refreshed
* Inputs/Outputs            : 
                              p_button_ID - Button Events
                               p_status_U8 - Activated/ Deactivated/ Refresh
* Invocation                : Invoked by the LSH when a popup is active
* Critical Section          : None
* Created                   : Autocreated on d
*                             Please do not modify
============================================================================*/
void hmi_popup_core_layer10_disp_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
    hmi_popup_core_presentation_handler(L_POPUP_LAYER10_ID, p_presn_hndl_status_SP);
}


