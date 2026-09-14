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
#include "hmi_gfx_mgr02_layout.h"
#include "ui_presentation.h"

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
int tgt = 0;

/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/

void KernelTriggerGraphicsTask(void){
  tgt = 1;
}

void main(void){
   hmi_gfx_mgr02_if_KSColdInit();
   hmi_gfx_mgr02_if_start();
   hmi_lsh_initialize(0);
   LSH_ADD_STATE(GFX_SCR_ECOPEDAL_MENU, 255);
   while(!kbhit()){
	   hmi_gfx_mgr02_if_KSTimedTask();
	   hmi_gfx_anim_engine_tick();
//	   hmi_gfx_mgr02_if_set_screen(GFX_SCR_P42M_COMPASS, 1 );
	  if(tgt){
	    tgt = 0;
	    Graphics_Task();
	    Graphics_Task_Done();
	  }
   }
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
