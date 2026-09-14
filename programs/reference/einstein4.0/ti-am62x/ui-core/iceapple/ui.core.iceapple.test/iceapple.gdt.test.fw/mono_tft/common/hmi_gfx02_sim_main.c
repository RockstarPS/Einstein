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
 ** Name:          hmi_gfx02_sim_main.c
 **
 ** Description:   Implements the screen logic and presentation for opening 
 **                screen 
 **
 ** Organization:  GUI Software Section
 **
 **============================================================================
 **
 **==========================================================================*/
#define HMI_GFX02_SIM_MAIN_C

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include <windows.h>
#include "hmi_logic_state_handler.h"
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_mgr02_context.h"
#include "hmi_gfx_dcu_sim_w32.h"
#include "dm_swch.h"
#include "hmi_timer_support.h"
#include "hmi_msgTask.h"

#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/
#define BASE_TICK_RATE_MS   (2)

/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/
static void hmi_sim_app_2ms_task(void);
static void hmi_sim_app_4ms_task(void);
static void hmi_sim_app_16ms_task(void);
static void hmi_sim_app_32ms_task(void);
extern GFX_MGR02_LAYER_DEF_T const lc_layer_def_S[GFX_MGR02_NUM_LAYERS];

/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/
HANDLE gt_hThread;
int counter=0;

/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/

/****************************************************************************
Function Name        : main
Description          : 
Invocation           : 
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void main(void)
{
    HANDLE hTimer = NULL;
    LARGE_INTEGER liDueTime;
	unsigned int fl_tick = 0;
	MSG  msg;
	
	printf("Power           - p\n");
	printf("Menu            - m\n");
	printf("info warning    - e\n");
	printf("soft warning    - w\n");
	printf("hard warning    - q\n");
	printf("Warnoff         - r\n");
	printf("prog. popup     - f\n");
	printf("info popup      - a\n");
	printf("ack popup       - s\n");
	printf("Other keys 0-9, up/doen/left/right, enter\n");

	dm_switch_reset();
	hmi_language_initialize();
	//hmi_gfx_mgr02_if_KSColdInit();
	hmi_lsh_initialize(0);
	hmi_popup_core_initialize();
	hm_msg_KSColdInit();
	//hmi_gfx_mgr02_if_start();
	hmi_gfx_mgr02_layout_initialize();
	#ifdef LSH_ANIMATION_SUPPORT_ENABLED
	#if GFX_NUM_ANIMATIONS > 0
    hmi_gfx_anim_engine_init();
	#endif
	#endif
    DCU.DISP_SIZE.B.DELTA_X = GFX_MGR02_LAYERS_MAX_WIDTH /16;
    DCU.DISP_SIZE.B.DELTA_Y = GFX_MGR02_LAYERS_MAX_HEIGHT;
    hmi_gfx02_dcu_sim_init(1);
    DCU.DCU_MODE.B.DCU_MODE = 1;

    liDueTime.QuadPart = (BASE_TICK_RATE_MS * -10000LL);
    hTimer = CreateWaitableTimer(NULL, FALSE, NULL);
    SetWaitableTimer(hTimer, &liDueTime, BASE_TICK_RATE_MS, NULL, NULL, 0);

	while(1){
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)){
  		    TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		if(gt_hThread != NULL){
			if(WaitForSingleObject(gt_hThread, 0) == WAIT_OBJECT_0){
				CloseHandle(gt_hThread);
				gt_hThread = NULL;
//				Graphics_Task_Done();

			}
		}
		if (WaitForSingleObject(hTimer, 0) == WAIT_OBJECT_0){
            if((fl_tick % (2/BASE_TICK_RATE_MS))  == 0)hmi_sim_app_2ms_task();
            if((fl_tick % (4/BASE_TICK_RATE_MS))  == 0)hmi_sim_app_4ms_task();
            if((fl_tick % (16/BASE_TICK_RATE_MS)) == 0)hmi_sim_app_16ms_task();
            if((fl_tick % (32/BASE_TICK_RATE_MS)) == 0)hmi_sim_app_32ms_task();
			fl_tick++;
		#if (BASE_TICK_RATE_MS/2) > 0
			Sleep(BASE_TICK_RATE_MS/2);
		#endif
		}
	}
}

/****************************************************************************
Function Name        : GTThreadFunction
Description          : thread to handle the graphics rendering task
Invocation           : 
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void KernelTriggerGraphicsTask(void);
DWORD WINAPI GTThreadFunction( LPVOID lpParam ){
//	Graphics_Task();
	hmi_lsh_task();
	#if GFX_NUM_ANIMATIONS > 0
    hmi_gfx_anim_engine();
    #endif
	hmi_gfx_mgr02_layout_build_screen();
	KernelTriggerGraphicsTask();
	return 0;
}

/****************************************************************************
Function Name        : KernelTriggerGraphicsTask
Description          : triggers the graphics rendering task
Invocation           : By graphics manager
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void KernelTriggerGraphicsTask(void){
	if(gt_hThread == NULL){
        gt_hThread = CreateThread( 
            NULL,                   // default security attributes
            0,                      // use default stack size  
            GTThreadFunction,       // thread function name
            NULL,                   // argument to thread function 
            0,                      // use default creation flags 
            NULL);                  // out - thread identifier
	}
}

/****************************************************************************
Function Name        : KernelTriggerGraphicsTask
Description          : Configures the layers with updated frame buffer based
                       on availability
Invocation           : By hmi_gfx_dcu_sim_w32.c display controller
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_gfx_mgr02_driver_vsync_isr(void)
{
   int i;
   void * fbp1;
   for(i=0; i < GFX_MGR02_NUM_LAYERS; i++){
      fbp1 = (void *)hmi_gfx_mgr02_context_swap_layer(i);
      switch(lc_layer_def_S[i].pix_format){
		 case GFX_MGR02_PIX_FORMAT_RGB565  :DCU.LAYER[i].CTRLDESCL4.B.BPP = GFX_MGR02_16BPP_RGB565;break;
		 case GFX_MGR02_PIX_FORMAT_ARGB4444:DCU.LAYER[i].CTRLDESCL4.B.BPP = GFX_MGR02_16BPP_ARGB4444;break;
		 case GFX_MGR02_PIX_FORMAT_ARGB1555:DCU.LAYER[i].CTRLDESCL4.B.BPP = GFX_MGR02_16BPP_ARGB1555;break;
		 case GFX_MGR02_PIX_FORMAT_ARGB8888:DCU.LAYER[i].CTRLDESCL4.B.BPP = GFX_MGR02_32BPP;break;
		 case GFX_MGR02_PIX_FORMAT_4BPP    :DCU.LAYER[i].CTRLDESCL4.B.BPP = GFX_MGR02_4BPP;break;
		 default: fbp1 = 0;break; /* not supported for openvg */
	  }
	  if(fbp1 != 0)
      {
         /*
	     ** If there is a new buffer available, program it to the display controller
	     */
         DCU.LAYER[i].CTRLDESCL1.B.WIDTH   = lc_layer_def_S[i].area.width;
         DCU.LAYER[i].CTRLDESCL1.B.HEIGHT  = lc_layer_def_S[i].area.height;
         DCU.LAYER[i].CTRLDESCL3.R         = (UINT32)(fbp1);
         DCU.LAYER[i].CTRLDESCL4.B.TILE_EN = 0;
         DCU.LAYER[i].CTRLDESCL4.B.AB	   = 0;
         DCU.LAYER[i].CTRLDESCL4.B.BB	   = 0;
         DCU.LAYER[i].CTRLDESCL4.B.EN      = 1;
	  }
   }
}

/****************************************************************************
Function Name        : hmi_sim_app_2ms_task
Description          : 2mSec task entry point
Invocation           : invoked by hmi_gfx02_sim_main.c
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
static void hmi_sim_app_2ms_task(void){
}

/****************************************************************************
Function Name        : hmi_sim_app_4ms_task
Description          : 4mSec task entry point
Invocation           : invoked by hmi_gfx02_sim_main.c
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
static void hmi_sim_app_4ms_task(void){
	//hmi_gfx_mgr02_if_KSTimedTask();
	hm_msg_KSRRobin();
}

/****************************************************************************
Function Name        : hmi_sim_app_16ms_task
Description          : 16mSec task entry point
Invocation           : invoked by hmi_gfx02_sim_main.c
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
static void hmi_sim_app_16ms_task(void){
	dm_switch_check_for_events();
#if GFX_NUM_ANIMATIONS > 0
	hmi_gfx_anim_engine_tick();
#endif
	KernelTriggerGraphicsTask();
}

/****************************************************************************
Function Name        : hmi_sim_app_32ms_task
Description          : 32mSec task entry point
Invocation           : invoked by hmi_gfx02_sim_main.c
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
static void hmi_sim_app_32ms_task(void){
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
 ** CMS Rev 1.0      09-Mar-2015    EMANOJ1
 ** Creation.
 **==========================================================================*/
#ifdef  __cplusplus
}
#endif
