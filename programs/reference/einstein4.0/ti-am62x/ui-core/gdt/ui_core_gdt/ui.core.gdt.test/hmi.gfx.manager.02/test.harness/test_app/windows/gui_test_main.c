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
 ** Name:           gui_test_main.c
 **
 ** Description:    
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#define gui_test_main_c
/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include <windows.h>
#include "system.h"
#include "hmi_gfx_mgr02_layout.h"
#if defined(GFX_MGR02_KEPLER)
#include "hmi_gfx_mgr02_dcu.h"
#endif
#include "hmi_gfx_mgr02_generic.h"
#if defined(GFX_MGR02_SOFWTARE)
#include "hmi_gfx_mgr02_swrlib.h"
#endif
#if defined(GFX_MGR02_OPEN_VG)
#include "hmi_gfx_mgr02_ovglib.h"
#endif
#include "hmi_gfx_anim_engine.h"
#include "hmi_gfx_mgr02_clut_table.h"
#include "hmi_gfx_mgr02_image_data.h"
#include "hmi_gfx_mgr02_context.h"
#include "hmi_gfx_mgr02_driver.h"
#include "hmi_gfx_dcu_sim_w32.h"
#include "hmi_logic_state_handler.h"
#include "hmi_button.h"
#include "hmi_gfx_mgr02_if.h"
#include "hmi_gfx_mgr02_if_chart.h"
#include "hmi_gfx_anim_engine_cfg.h"
#include "hmi_gfx_mgr02_cfg.h"

#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/

/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/

/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/
int l_gt_req = 0;
char current_cmd = -1;
char current_anim = -1;
int splash_screen = 0;
char previous_layer, current_layer;
/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/
void KernelTriggerGraphicsTask(void)
{
   l_gt_req = 1;
}

void gdg02_DCU_ISR(void)
{
#if defined(GFX_MGR02_KEPLER)
   hmi_gfx_mgr02_driver_dcu_isr();
#endif
   #if GFX_NUM_ANIMATIONS > 0
   hmi_gfx_anim_engine_tick();
   #endif
}

void hmi_app_demo_presentation_init(void)
{
   hmi_gfx_mgr02_if_KSColdInit();
   hmi_gfx_mgr02_if_start();
   #if defined(GFX_MGR02_KEPLER)
   hmi_gfx02_dcu_sim_init(1);
   hmi_gfx_mgr02_if_enable_dcu();
   #endif
   hmi_lsh_initialize(1);
}
static unsigned int ignition   = 0;
static volatile l_dummy = 0;

void hmi_app_demo_presentation_task(void)
{
   l_dummy = 1;
}
/*============================================================================
** Function Name:    
** Visibility:       
** Description:      
** Invocation:       
** Inputs/Outputs:   
** Critical Section: 
** Created:          09-Aug-2012 by EMANOJ1
** Updated:          09-Aug-2012 by EMANOJ1
**==========================================================================*/
int main(int argc, char * argv[])
{
    MSG  msg;
    char ch = -1;
    void * fbp1;
    void * fbp2;
    previous_layer = 0xFF;
    current_layer  = 0xFF;
    hmi_app_demo_presentation_init();
    ignition = 1;
    #if !defined(GFX_MGR02_KEPLER)
    DCU.DISP_SIZE.B.DELTA_X = 480 / 16;
    DCU.DISP_SIZE.B.DELTA_Y = 272;
    DCU.DCU_MODE.B.DCU_MODE = 1;
    hmi_gfx02_dcu_sim_init(1);

    #if defined(GFX_MGR02_OPEN_VG)
    fbp1 = hmi_gfx_mgr02_context_swap_fb(1);
    DCU.LAYER[0].CTRLDESCL1.B.WIDTH     = 480;
    DCU.LAYER[0].CTRLDESCL1.B.HEIGHT    = 272;
    DCU.LAYER[0].CTRLDESCL4.B.BPP       = GFX_MGR02_16BPP_RGB565;//GFX_MGR02_32BPP
    DCU.LAYER[0].CTRLDESCL3.R           = fbp1;
    DCU.LAYER[0].CTRLDESCL4.B.TILE_EN   = 0;
    DCU.LAYER[0].CTRLDESCL4.B.AB        = 0;
    DCU.LAYER[0].CTRLDESCL4.B.BB        = 0;
    if(fbp1 != 0)
    {
       DCU.LAYER[0].CTRLDESCL4.B.EN = 1;
    }
    #endif
    #if defined(GFX_MGR02_SOFWTARE)
    fbp2 = hmi_gfx_mgr02_context_swap_fb(2);
    DCU.LAYER[1].CTRLDESCL1.B.WIDTH     = 480;
    DCU.LAYER[1].CTRLDESCL1.B.HEIGHT    = 272;
    DCU.LAYER[1].CTRLDESCL4.B.BPP       = GFX_MGR02_16BPP_RGB565;//GFX_MGR02_32BPP
    DCU.LAYER[1].CTRLDESCL3.R           = fbp2;
    DCU.LAYER[1].CTRLDESCL4.B.TILE_EN   = 0;
    DCU.LAYER[1].CTRLDESCL4.B.AB        = 0;
    DCU.LAYER[1].CTRLDESCL4.B.BB        = 0;
    if(fbp2 != 0)
    {
       DCU.LAYER[1].CTRLDESCL4.B.EN = 1;
    }
    #endif
    #endif
    //hmi_gfx_anim_engine_init();
    while(1)
    {
        if(kbhit())
        {
            UINT16 fl_button_id;
            char prev_cmd = current_cmd;
            ch = getch();
            current_cmd = ch;
            if(((ch >= 48) && (ch <= 57)) || ((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')))
            {
                if(ch >= 'a')
                {
                    fl_button_id = ch - 'a' + ButtonID_A;
                }
                else if(ch >= 'A')
                {
                    fl_button_id = ch - 'A' + ButtonID_A;
                }
                else
                {
                    fl_button_id = ch - '0' + ButtonID_0;
                }
                hmi_lsh_post_button_event(fl_button_id, ButtonState_Pressed);
            }
            else if(ch == 13)
            {
                hmi_lsh_post_button_event(ButtonID_OK, ButtonState_Pressed);
            }
            else if(ch == -32)
            {
                ch = getch();
                switch(ch)
                {
                case 71:/* Home */
                    /* StartUp sequence */
                    if(ignition == 0)
                    {
                        hmi_app_demo_presentation_init();
                        ignition = 1;
                    }
                    break;
                case 72:/*up*/
                    hmi_lsh_post_button_event(ButtonID_UP, ButtonState_Pressed);
                    break;
                case 75:/*left*/
                    hmi_lsh_post_button_event(ButtonID_LEFT, ButtonState_Pressed);
                    break;
                case 77:/*right*/
                   hmi_lsh_post_button_event(ButtonID_RIGHT, ButtonState_Pressed);
                    break;
                case 79:/* End */
                    if(ignition == 1)
                    {
                        hmi_gfx_mgr02_if_shutdown(GFX_MGR02_SHUTDOWN_NORMAL);
                        while(hmi_gfx_mgr02_if_is_ready_to_sleep() == FALSE)
                        {
                        }
                        hmi_gfx_mgr02_if_KSSleep();
                        ignition = 0;
                    }
                    /* Normal shutdown sequence */
                    break;
                case 80:/*down*/
                    hmi_lsh_post_button_event(ButtonID_DOWN, ButtonState_Pressed);
                    break;
                case 83: /* Delete */
                    /* Abnormal Shutdown sequence */
                    if(ignition == 1)
                    {
                        hmi_gfx_mgr02_if_shutdown(GFX_MGR02_SHUTDOWN_EMERGENCY);
                        hmi_gfx_mgr02_if_KSSleep();
                        ignition = 0;
                    }
                    break;
                }
            }
        }
        else
        {
            MSG  msg;
            //Sleep(50);
            hmi_gfx_mgr02_if_KSTimedTask();
            switch(ch)
            {
            case 13:
                hmi_lsh_post_button_event(ButtonID_OK, ButtonState_Inactive);
                break;
            case 72:/*up*/
                hmi_lsh_post_button_event(ButtonID_UP, ButtonState_Inactive);
                break;
            case 80:/*down*/
                hmi_lsh_post_button_event(ButtonID_DOWN, ButtonState_Inactive);
                break;
            case 77:/*right*/
                hmi_lsh_post_button_event(ButtonID_RIGHT, ButtonState_Inactive);
                break;
            case 75:/*left*/
                hmi_lsh_post_button_event(ButtonID_LEFT, ButtonState_Inactive);
                break;
            }
            ch = 0;
            if(GetMessage(&msg, NULL, 0, 0))
            {
            if(l_gt_req != 0)
            {
                l_gt_req = 0;
                Graphics_Task();
                Graphics_Task_Done();
            }
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
    }
    return(0);
}

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
 ** CMS Rev 1.0      09-Aug-2012    EMANOJ1
 ** Creation.
 **==========================================================================*/
#ifdef  __cplusplus
}
#endif

/* end of file =============================================================*/
