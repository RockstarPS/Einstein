
#include "system.h"


#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_anim_engine.h"
#include "hmi_gfx_anim_engine.cfg"
#include "hmi_gfx_mgr02_generic.h"

#include "mm_gdc_hweb.h"

#include "ut_memman.h"
#include "ut_compatibility.h"
#include "sm_util.h"
#include <math.h>
//#include "hmi_veh_simulator.h"



void main()
{

	MM_S32 ret = MML_OK;
	hmi_gfx_mgr02_layout_initialize();

//	hmi_gfx_anim_play_fwd(GFX_SCR_P42M_COMPASS,GFX_NEW_ANIMATIONS_1);
	hmi_gfx_mgr02_layout_set_screen(GFX_SCR_P42M_COMPASS, 1 );
	while(1)
	{

		#if GFX_NUM_ANIMATIONS > 0
	    hmi_gfx_anim_engine_tick();
		hmi_gfx_anim_engine();
		
		#endif
	    hmi_gfx_mgr02_layout_build_screen();

	}

}

void hm_presentation_handler()
{
}

void KernelTriggerGraphicsTask(void)
{
}


void hmi_gfx_mgr02_app_anim_done_cb(UINT32 p_anim_id, UINT32 p_client_id)
{
}
void hmi_compass_anim_update_cb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}

#if GFX_MGR02_TOUCH_SCREEN_ENABLED > 0
void hmi_gfx_mgr02_app_touch_event_handler(UINT32 p_obj_id, GFX_MGR02_TOUCH_QDATA * p_event)
{

printf("hmi_gfx_mgr02_app_touch_event_handler(obj:%d, event:%d)\n", p_obj_id, p_event);


}
#endif

void hmi_gfx_mgr02_load_user_layer_def_info(UINT32 p_base_id, GFX_MGR02_IMAGE_DEF_T * p_image_def)
{

}

UINT32 needle_goto_callback(UINT32 p_cur_step)
{
    return(0);
}
