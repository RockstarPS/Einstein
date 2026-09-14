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
** Name:          
**
** Description:   Implements the screen logic and presentation for opening
**                screen
**
** Organization:  GUI Software Section
**
**============================================================================
**
**==========================================================================*/

#define HMI_SPECIFIC_C

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/


#include "Std_Types.h"
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_anim_engine.h"
#include "hmi_logic_state_handler.h"
#include "hmi_dss_interface.h"
#include "HmiSpecific.h"
#ifdef BOOT_KPI_LOG_EN
#include "boot_kpi_r5_asr.h"
#endif   /*BOOT_KPI_LOG_EN*/

#ifdef  __cplusplus
extern "C" {
#endif


boolean hmi_gfx_mgr02_get_vsync_status(void);
void hmi_gfx_mgr02_set_vsync_status(boolean p_vsync_status);

typedef enum
{
  EHMI_STATUS_NOT_INITIALIZED = 0,
  EHMI_STATUS_ACTIVATE,
  EHMI_STATUS_LSH_UPDATE,
  EHMI_STATUS_RENDER_START,
  EHMI_STATUS_RENDER_DONE,
  EHMI_STATUS_VSYNC_EVENT,
  EHMI_STATUS_SHUTDOWN
} EHMI_STATUS;

static EHMI_STATUS l_ehmi_status_flag = EHMI_STATUS_NOT_INITIALIZED;

static boolean l_vsync_event = 0;

/*****************************************************************************
Function Name        : HmiSpecific_Init
Invocation           : Called by GdtCdd::OnCommand(eCmpCmd_Activate): IsEarlyWakeup
Return Value         : E_OK:           Succeed
                       E_NOT_READY:    In progress. Keeps the component in this state.
                       E_NOT_OK:       Failed
Critical Section     : None
Parameters           : None
******************************************************************************/
void HmiSpecific_Init(void)
{

}

/*****************************************************************************
Function Name        : HmiSpecific_Activate
Invocation           : Called by GdtCdd::OnCommand(eCmpCmd_Activate)
Return Value         : E_OK:           Succeed
                       E_NOT_READY:    In progress. Keeps the component in this state.
                       E_NOT_OK:       Failed
Critical Section     : None
Parameters           : None
******************************************************************************/
Std_ReturnType HmiSpecific_Activate(void)
{
    return E_OK;
}

/*****************************************************************************
Function Name        : HmiSpecific_Deactivate
Invocation           : Called by GdtCdd::OnCommand(eCmpCmd_Deactivate)
Return Value         : E_OK:           Succeed
                       E_NOT_READY:    In progress. Keeps the component in this state.
                       E_NOT_OK:       Failed
Critical Section     : None
Parameters           : None
******************************************************************************/
Std_ReturnType HmiSpecific_Deactivate(void)
{
    return E_OK;
}

/*****************************************************************************
Function Name        : HmiSpecific_Active
Invocation           : Called by Gdtcdd::OnCommand(eCmpCmd_Active)
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void HmiSpecific_Active(void)
{
    LSH_ADD_STATE(GFX_SCR_MAIN, 255);
}

boolean hmi_gfx_mgr02_get_vsync_status(void)
{
    return (l_vsync_event);
}

void hmi_gfx_mgr02_set_vsync_status(boolean p_vsync_status)
{
/* since the invocation from rte is mapped to a 10ms task temporarily. 2 cycles are skipped to realize the state changes. Once the 16ms task is mapped, this skipcounter logic can be removed */
    static int32_t skipcounter = 0;
    skipcounter++; 
    if(skipcounter > 2)
    {
        l_vsync_event = p_vsync_status;
        l_ehmi_status_flag = EHMI_STATUS_VSYNC_EVENT;
        skipcounter = 0;
    }

}

/****************************************************************************
                Presentation handler
****************************************************************************/

void scr_main_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{  
   if(p_presen_hndl_status_SP->presentation_status == LSH_ACTIVATED_STATUS)
   {
    #ifdef BOOT_KPI_LOG_EN
        BOOT_KPI_LOG(KPI_ID_VIP_EARLY_HMI, "VIPHMI");
    #endif   /*BOOT_KPI_LOG_EN*/
    hmi_gfx_mgr02_layout_set_screen((GFX_MGR02_SCR_ELEM_ID)p_presen_hndl_status_SP->logic_state_id, 1);
   }
   else if(p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
   {
      hmi_gfx_mgr02_layout_set_screen((GFX_MGR02_SCR_ELEM_ID)p_presen_hndl_status_SP->logic_state_id, 0);
   }
   else
   {
    /*Do nothing*/
   }
}


#ifdef  __cplusplus
}
#endif
