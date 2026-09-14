/*****************************************************************************
*                                                                            *
*             CONFIDENTIAL VISTEON CORPORATION                               *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2014.Visteon Corporation owns all rights to            *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/

/*****************************************************************************
File Name           :  ui_etm_presentation.c
Module Short Name   :  
RTC Comp Name       :  
Author              :  ebechi
Description         :  
Organization        :  Driver Information Software Section,
                       Visteon Corporation
Compiler Name       :
Target Processor    :  
******************************************************************************/
#define UI_ETM_PRESENTATION_C

#ifdef  __cplusplus
extern "C" {
#endif

/*****************************************************************************
*                                System Includes                             *
******************************************************************************/
#include "ui_etm_presentation.h"
#include "hmi_gfx_mgr02_if.h"
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_button.h"
/*****************************************************************************
*                                Manifest Constants                          *
*----------------------------------------------------------------------------*
* Definition of    constant shall be followed by a comment that explains the *
* purpose of the constant.                                                   *
******************************************************************************/


/*****************************************************************************
*                                Macro Definitions                           *
*----------------------------------------------------------------------------*
* Definition of    macro shall be followed by a comment that explains the    *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                Type Declarations                           *
******************************************************************************/

/*****************************************************************************
*                             File Scope Prototypes                          *
******************************************************************************/

/*****************************************************************************
*                               Globally  accessed Variable Declarations     *
*----------------------------------------------------------------------------*
* Declaration shall    be followed by a comment that gives the following info*
* about    the variable.                                                     *
* purpose, critical    section, unit, and resolution                         *
******************************************************************************/


/*****************************************************************************
*                                Locally used Variable Declarations          *
*----------------------------------------------------------------------------*
* Declaration shall    be followed by a comment that gives the following info*
* about    the variable.                                                     *
* purpose, critical    section, unit, and resolution                         *
******************************************************************************/
void hmi_etm_set_et100(void)
{

}


void hmi_etm_set_et110(void)
{

}

void hmi_etm_set_et120(void)
{

}

void hmi_etm_set_et130(void)
{

}

void hmi_etm_set_et230(void)
{
		
}

void hmi_etm_set_et233(void)
{

}

/*============================================================================
 ** Function Name:    hmi_etm_ev_hdnlr
 ** Visibility:       global
 ** Description:      Event Handler for header footer
 ** Invocation:       View Manager
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          20-Oct-2014 by ASHEKHAR
 ** Created:          20-Oct-2014 by ASHEKHAR
 **==========================================================================*/
UINT8 hmi_etm_ev_hdnlr(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
	return((UINT8)LSH_STATUS_ABSORBED);
}

/*============================================================================
 ** Function Name:    hmi_etm_focus_hdnlr
 ** Visibility:       global
 ** Description:      Focus Handler for header footer
 ** Invocation:       View Manager
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          20-Oct-2014 by ASHEKHAR
 ** Created:          20-Oct-2014 by ASHEKHAR
 **==========================================================================*/
void hmi_etm_focus_hdnlr(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP)
{
}

/*============================================================================
 ** Function Name:    hmi_etm_present_hdnlr
 ** Visibility:       global
 ** Description:      UI HEADER Footer Presentation Handler
 ** Invocation:       View Manager
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          20-Oct-2014 by ASHEKHAR
 ** Created:          20-Oct-2014 by ASHEKHAR
 **==========================================================================*/
void hmi_etm_present_hdnlr(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
	if((LSH_ACTIVATED_STATUS == p_presen_hndl_status_SP->presentation_status) ||
		(LSH_REFRESH_STATUS == p_presen_hndl_status_SP->presentation_status))
	{
		if (LSH_ACTIVATED_STATUS == p_presen_hndl_status_SP->presentation_status)
		{

		}
	}
	else if(LSH_DEACTIVATED_STATUS == p_presen_hndl_status_SP->presentation_status)
	{
	}
	else
	{
	}

}

#ifdef  __cplusplus
}

#endif
