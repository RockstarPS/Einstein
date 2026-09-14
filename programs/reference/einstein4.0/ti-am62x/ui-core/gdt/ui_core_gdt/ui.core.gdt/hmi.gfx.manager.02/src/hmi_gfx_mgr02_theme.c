/*=============================================================================
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
 ** Name:           hmi_gfx_mgr02_theme.c
 **
 ** Description:    Implements the dirty region redraw support functions to 
 **                 maintain active elements area and to derive dirty area
 **                 based on new list of area.
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#define HMI_GFX_MGR02_THEME_C
/*=============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "hmi_gfx_mgr02_generic.h"
#ifdef GFX_MGR02_THEME_ENABLED
#include "hmi_gfx_mgr02_theme.h"
#include "hmi_gfx_mgr02_dirty_area.h"

#ifdef  __cplusplus
extern "C" {
#endif

/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/

#if !defined(GFX_MGR02_OPEN_VG)
 #ifdef GFX_MGR02_THEME_ENABLED
  #error "GFX_MGR02_THEME is valid only for OpenVG/Software"
 #endif
#endif

			 
/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/

/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/


#if defined(WIN32) || defined(MATLAB_MEX_FILE)
   #define GFX_MGR02_THEME_MAX                3
   #define GFX_MGR02_THEME_MAX_FILE_PATH_SIZE 200
   static char * lc_theme_resource_path[GFX_MGR02_THEME_MAX]= 
   {
      "gresfiles/",  /* always default path  index o should be default path*/
      "gresfiles/theme1/",
      "gresfiles/theme2/"
   };
   static char const lc_theme_target_path[GFX_MGR02_THEME_MAX_FILE_PATH_SIZE]= {"C:/apps/jazz_4.0.2.1/OpenVG Simulation/UI_IA_GDT_Test/ui.core.iceapple.test/iceapple.gdt.test.fw/Curopenvg_target/make/"};
#else
   extern  char const * lc_theme_resource_path[];
   extern  char const lc_theme_target_path[];
#endif

/* hold the currently active theme */
static UINT32        l_active_theme_U32;

/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/


/****************************************************************************
Function Name        : hmi_gfx_mgr02_theme_init
Description          : Init function
Invocation           : 
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void hmi_gfx_mgr02_theme_init(void)
{
   l_active_theme_U32 = 0;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_theme_set_theme
Description          : Set the selected theme
Invocation           : 
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void hmi_gfx_mgr02_theme_set_active_theme(UINT32 fl_theme_U32)
{
   if(fl_theme_U32 < GFX_MGR02_THEME_MAX)
   {
      l_active_theme_U32 = fl_theme_U32;
#if defined(GFX_MGR02_DIRTY_REGION_REDRAW)
	  hmi_gfx_mgr02_dar_init();
	  hmi_gfx_mgr02_layout_force_set_screen();
#endif
   }
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_theme_get_active_theme
Description          : Set the selected theme
Invocation           : 
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
UINT32 hmi_gfx_mgr02_theme_get_active_theme(void)
{
   return l_active_theme_U32;
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_theme_set_theme
Description          : Set the selected theme
Invocation           : 
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
FILE * hmi_gfx_mgr02_theme_fopen(char const * fl_file_name_ptr)
{
   char fl_dest_file_path[GFX_MGR02_THEME_MAX_FILE_PATH_SIZE+1];
   FILE * fl_image_file = NULL;
   if(l_active_theme_U32 < GFX_MGR02_THEME_MAX)
   {
	  fl_dest_file_path[0] = '\0';
      strncpy(&fl_dest_file_path[0],lc_theme_target_path,GFX_MGR02_THEME_MAX_FILE_PATH_SIZE);
      strncat(&fl_dest_file_path[0],lc_theme_resource_path[l_active_theme_U32],GFX_MGR02_THEME_MAX_FILE_PATH_SIZE);
	  strncat(&fl_dest_file_path[0],fl_file_name_ptr,GFX_MGR02_THEME_MAX_FILE_PATH_SIZE);
      fl_image_file = fopen((const char*)&fl_dest_file_path, "r");
      if(fl_image_file == 0)
      {
		  /* load target path*/
         strncpy((char *)&fl_dest_file_path[0],(char *)&lc_theme_target_path,GFX_MGR02_THEME_MAX_FILE_PATH_SIZE);
		 /* load default theme path*/
         strncat(&fl_dest_file_path[0],lc_theme_resource_path[0],GFX_MGR02_THEME_MAX_FILE_PATH_SIZE);
		 /* load default theme resource path*/
	     strncat(&fl_dest_file_path[0],fl_file_name_ptr,GFX_MGR02_THEME_MAX_FILE_PATH_SIZE);
         fl_image_file = fopen((const char*)&fl_dest_file_path, "r");
	  }
   }
   return fl_image_file;
}
#endif /* #ifdef GFX_MGR02_THEME */

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
 ** CMS Rev 1.3      06-Mar-2016     CSAKTHIV
 ** 564659 for B515 Theme. Interface added to force screen change.
 ** 
 ** CMS Rev 1.2      23-Jan-2016     aperumal
 ** In hmi_gfx_mgr02_theme_fopen(), the size of fl_dest_file_path changed to 
 ** GFX_MGR02_THEME_MAX_FILE_PATH_SIZE+1 to fix the coverity warning on 
 ** Out of bounds access of fl_dest_file_path
 **
 ** CMS Rev 1.2      06-Jan-2016     csakthiv
 ** fopen with rb not working for B515. so changed to only r
 ** CMS Rev 1.1      27-Nov-2015     csakthiv
 ** Creation.
 ** Theme support added for user type image.
 ** CMS Rev 1.0      27-Nov-2015     csakthiv
 ** Creation.
 ** Theme support for B515	460855
 **==========================================================================*/
#ifdef  __cplusplus
}
#endif
/* end of file =============================================================*/
