/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2013. Visteon Corporation owns all rights to this work and
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
 ** Name:           hmi_gfx_mar02_if.c
 **
 ** Description:    Application interface implementation file.
 **
 ** Organization:   Driver Information Software Section,
 **                 Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#define HMI_GFX_MGR02_IF_C

#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_mgr02_if.h"
#if defined(GFX_MGR02_KEPLER)
#include "hmi_gfx_mgr02_driver.h"
#endif
#if !defined(GFX_MGR02_AMBER) && !defined(GFX_MGR02_AMBER_IRIS)
#include "sched.h"
#endif
#include "hmi_gfx_mgr02_if_model_autocode.h"
#include "hmi_gfx_mgr02_if_chart.h"
#if defined(WIN32) || defined(MATLAB_MEX_FILE)
#if !defined(NUNIT_TESTING) && !defined(GFX_MGR02_OPEN_GL) && !defined(GFX_MGR02_AMBER) && !defined(GFX_MGR02_AMBER_IRIS) && !defined(GFX_MGR02_FUJITSU)
  #include <windows.h>
  #include <stdio.h>
  #include "hmi_gfx_dcu_sim_w32.h"
#endif
#endif
#if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED)
#include "tmwtypes.h"
#include "hmi_bidi_algo.h"
#endif
#ifdef GFX_MGR02_USE_PTHREAD_MUTEX
 #include <pthread.h>
#endif

#if defined(GFX_MGR02_OPEN_VG)
extern UINT32 hmi_gfx_mgr02_ovglib_cache_get_object(void const * pc_bitmap_def_S, GFX_MGR02_VG_OBJ_TYPES bitmap_def_type, UINT32 p_raw_data, UINT32  p_attributes);
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
static volatile UINT8 l_gfx_mgr02_if_update_pending;

#ifdef GFX_MGR02_USE_PTHREAD_MUTEX
 pthread_mutex_t l_gfx_if_build_mutex = PTHREAD_MUTEX_INITIALIZER;
 #define GFX_MGR02_IFBUILD_MUTEX_LOCK()   pthread_mutex_lock(&l_gfx_if_build_mutex)
 #define GFX_MGR02_IFBUILD_MUTEX_UNLOCK() pthread_mutex_unlock(&l_gfx_if_build_mutex)
#else
 #define GFX_MGR02_IFBUILD_MUTEX_LOCK()
 #define GFX_MGR02_IFBUILD_MUTEX_UNLOCK()
#endif

/*============================================================================
** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_KSColdInit
** Visibility:       global
** Description:      Initializes all internal variable data to its default
** Invocation:       By presentation layer when ever it wants to restart.
** Inputs/Outputs:   None
** Critical Section: None.
** Created:          21-Jun-2013 by EMANOJ1
** Created:          05-Apr-2012 by EMANOJ1
**==========================================================================*/
void hmi_gfx_mgr02_if_KSColdInit(void)
{
#ifdef GFX_MGR02_USE_PTHREAD_MUTEX
    pthread_mutexattr_t fl_mattr;
    if(pthread_mutexattr_settype(&fl_mattr, PTHREAD_MUTEX_RECURSIVE) == 0)
    {
       pthread_mutex_init(&l_gfx_if_build_mutex, &fl_mattr);
    }
#endif
    initialize_hmi_gfx_mgr02_if_chart();
#if !defined(MATLAB_MEX_FILE)
    hmi_gfx_mgr02_if_model_initializer();
#endif
    l_gfx_mgr02_if_update_pending = (UINT8)FALSE;
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
  #if GFX_NUM_ANIMATIONS > 0
    hmi_gfx_anim_engine_init();
  #endif
#endif
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_KSWarmInit
** Visibility:       global
** Description:      Initializes all internal variable data to its default
** Invocation:       By application.
** Inputs/Outputs:   None
** Critical Section: None.
** Created:          05-Apr-2012 by EMANOJ1
** Created:          05-Apr-2012 by EMANOJ1
**==========================================================================*/
void hmi_gfx_mgr02_if_KSWarmInit(void)
{
    hmi_gfx_mgr02_if_KSColdInit();
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_KSWakeUp
** Visibility:       global
** Description:      Initializes all internal variable data to its default
** Invocation:       By application
** Inputs/Outputs:   None
** Critical Section: None.
** Created:          05-Apr-2012 by EMANOJ1
** Created:          05-Apr-2012 by EMANOJ1
**==========================================================================*/
void hmi_gfx_mgr02_if_KSWakeUp(void)
{
    hmi_gfx_mgr02_if_KSColdInit();
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_KSSleep
** Visibility:       global
** Description:      Disables the DCU and QSPI
** Invocation:       By application before entry to sleep.
** Inputs/Outputs:   None
** Critical Section: None.
** Created:          05-Apr-2012 by EMANOJ1
** Created:          05-Apr-2012 by EMANOJ1
**==========================================================================*/
void hmi_gfx_mgr02_if_KSSleep(void)
{
#ifdef GFX_MGR02_KEPLER
    hmi_gfx_mgr02_driver_disable_dcu();
#endif
}

#ifdef GFX_MGR02_KEPLER
/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_enable_dcu
** Visibility:       global
** Description:      Enables the DCU
** Invocation:       By application after all peripherals initialisation and
**                   hmi_gfx_mgr02_if_start has been triggered.
** Inputs/Outputs:   None
** Critical Section: None.
** Created:          10-Dec-2012 by ASHEKHAR
** Created:          10-Dec-2012 by ASHEKHAR
**==========================================================================*/
void hmi_gfx_mgr02_if_enable_dcu(void)
{
    hmi_gfx_mgr02_driver_enable_dcu();
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_disable_dcu
** Visibility:       global
** Description:      Disables the DCU
** Invocation:       By application before entry to sleep.
** Inputs/Outputs:   None
** Critical Section: None.
** Created:          10-Dec-2012 by ASHEKHAR
** Created:          10-Dec-2012 by ASHEKHAR
**==========================================================================*/
void hmi_gfx_mgr02_if_disable_dcu(void)
{
    hmi_gfx_mgr02_driver_disable_dcu();
}

#endif

/*============================================================================
** Function Name:    hmi_gfx_mgr02_initialize
** Visibility:       global
** Description:      Initializes all internal variable data to its default
** Invocation:       By presentation layer when ever it wants to restart.
** Inputs/Outputs:   None
** Critical Section: None.
** Created:          05-Apr-2012 by EMANOJ1
** Updated:          03-Mar-2014 by EMANOJ1
**==========================================================================*/
UINT32 hmi_gfx_mgr02_if_presentation_task(void)
{
    UINT32 fl_update_pending;

	#if GFX_MGR02_TOUCH_SCREEN_ENABLED > 0
     hmi_gfx_mgr02_layout_process_touch_events();
    #endif
    GFX_MGR02_IF_APP_PRESENTATION_TASK();
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
  #if GFX_NUM_ANIMATIONS > 0
    hmi_gfx_anim_engine();
  #endif
#endif

    fl_update_pending = l_gfx_mgr02_if_update_pending;

    if(fl_update_pending != (UINT32)FALSE)
    {
        l_gfx_mgr02_if_update_pending = (UINT8)FALSE;
        KernelTriggerGraphicsTask();
    }

    return(fl_update_pending);
}


/*============================================================================
** Function Name:    Graphics_Task
** Visibility:       global
** Description:      Builds the screens that are active in  l_cur_screen_selection
**                   array
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   None
** Critical Section: None.
** Created:          05-May-2011 by EMANOJ1
** Updated:          19-Feb-2013 by ASHEKHAR
**==========================================================================*/
void Graphics_Task(void)
{
    #ifdef GFX_MGR02_AMBER
    UINT32 fl_is_amber_driver_free_u32;
    #endif
    GFX_MGR02_IFBUILD_MUTEX_LOCK();

    #ifdef GFX_MGR02_AMBER
    /* Get the amber driver status through hmi_gfx_mgr02_layout_is_render_done */
    fl_is_amber_driver_free_u32 = (UINT32)hmi_gfx_mgr02_layout_is_render_done();
    if(fl_is_amber_driver_free_u32 != (UINT32)FALSE)
    #endif
    {
      hmi_gfx_mgr02_layout_build_screen();
    }
#ifdef GFX02_DEBUG_ERROR
    if(l_gfx_mgr02_if_update_pending != (UINT8)FALSE)
    {
        /*
        ** This is an error condition, application is not supposed to call
        ** gfx manager APIs while build screen is in progress.
        */
        gfx_debug("ERROR   - Gfx manager API invoked while doing hmi_gfx_mgr02_layout_build_screen()!\n");
    }
#endif
    GFX_MGR02_IFBUILD_MUTEX_UNLOCK();
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_force_update
** Visibility:       global
** Description:      Selects the screen to be shown or not to be shown
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   The screen ID to be activated/deactivated in p_elem_id
**                   p_show = TRUE then the screen is shown
**                   p_show = FALSE then the screen is removed
** Critical Section: None.
** Created:          05-May-2011 by EMANOJ1
** Updated:          05-May-2011 by EMANOJ1
**==========================================================================*/
void hmi_gfx_mgr02_if_force_update(void)
{
    l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_set_screen
** Visibility:       global
** Description:      Selects the screen to be shown or not to be shown
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   The screen ID to be activated/deactivated in p_elem_id
**                   p_show = TRUE then the screen is shown
**                   p_show = FALSE then the screen is removed
** Critical Section: None.
** Created:          05-May-2011 by EMANOJ1
** Updated:          05-May-2011 by EMANOJ1
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_screen(GFX_MGR02_SCR_ELEM_ID p_elem_id, UINT32 p_show)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_screen(p_elem_id, p_show);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}

/*============================================================================
** Function Name:    GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_screen_dyn_priority \
                     (GFX_MGR02_SCR_ELEM_ID p_elem_id, UINT32 p_show, UINT8 priority)
** Visibility:       global
** Description:      Selects the screen to be shown or not to be shown acccording to the
                     requested priority.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   The screen ID to be activated/deactivated in p_elem_id
**                   p_show = TRUE then the screen is shown
**                   p_show = FALSE then the screen is removed
                     priortiy - This selects the GFX manager priority in which the new
					 screen has to be added.
** Critical Section: None.
** Created:          05-May-2011 by EMANOJ1
** Updated:          05-May-2011 by EMANOJ1
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_screen_dyn_priority(GFX_MGR02_SCR_ELEM_ID p_elem_id, \
UINT32 p_show, UINT8 priority)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_screen_dyn_priority(p_elem_id, p_show,priority);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}

#if GFX_MGR02_NUM_OF_DTEXTS > 0
/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_get_text_width
** Visibility:       global
** Description:      Interface to get text width with bidi logic and alignment based
**                   on text configuration in GDT.      
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   in - p_elem_id of the text element
**                   in - pointer to a locally allocated GFX_MGR02_TEXT_WIDTH_INFO structure
**                    p_text_info->iostring : load the pointer to string which
**                                            should be checked for fit
**                    p_text_info->ifont_id : font id to be used, leave as
**                                            GFX_MGR02_NUM_OF_FONTS to use
**                                            default font configured for the text
**                   out - p_text_info->iostring : modified string pointer
**                   out - p_text_info->owidth   : width of string that will fit
**                   out - p_text_info->ostr_length : length of string that will fit
**                   out - p_text_info->oclip_flag : 0 - no clipping, 1 - string is clipped
**					 in  - p_alignment: right or left aligned text
** Critical Section: None.
** Created:          12-May-2015 by CSAKTHIV
** Updated:          
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_get_text_width(GFX_MGR02_DTEXT_ID p_elem_id, 
                                                         GFX_MGR02_TEXT_WIDTH_INFO * p_text_info)
                                                         
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
	fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_get_text_width_ext(p_elem_id,p_text_info,GFX_MGR02_INVALID_TYPE);
	return 	fl_gfx_layout_error_code;

}
/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_get_text_width_ext
** Visibility:       global
** Description:      Interface to get text width with bidi logic and using the alignment
**                   input from user.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   in - p_elem_id of the text element
**                   in - pointer to a locally allocated GFX_MGR02_TEXT_WIDTH_INFO structure
**                    p_text_info->iostring : load the pointer to string which
**                                            should be checked for fit
**                    p_text_info->ifont_id : font id to be used, leave as
**                                            GFX_MGR02_NUM_OF_FONTS to use
**                                            default font configured for the text
**                   out - p_text_info->iostring : modified string pointer
**                   out - p_text_info->owidth   : width of string that will fit
**                   out - p_text_info->ostr_length : length of string that will fit
**                   out - p_text_info->oclip_flag : 0 - no clipping, 1 - string is clipped
**					 in  - p_alignment: right or left aligned text
** Critical Section: None.
** Created:          12-May-2015 by CSAKTHIV
** Updated:          
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_get_text_width_ext(GFX_MGR02_DTEXT_ID p_elem_id, 
                                                         GFX_MGR02_TEXT_WIDTH_INFO * p_text_info,
                                                         UINT32            p_alignment)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
	fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_get_text_width_ext(p_elem_id, p_text_info, p_alignment);
    return(fl_gfx_layout_error_code);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_set_text
** Visibility:       global
** Description:      Sets the text value for a Dynamic Text element
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   The Text element ID to which a new string needs to be copied
**                   p_string = Pointer to NULL terminated string
** Critical Section: None.
** Created:          05-May-2011 by EMANOJ1
** Updated:          03-Jul-2013 by JANANDAL
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_text(GFX_MGR02_DTEXT_ID p_elem_id, HMI_CHAR const * p_string)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_text(p_elem_id, p_string);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}


#if (defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)) && (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_set_multi_line_text
** Visibility:       global
** Description:      Sets the text value for a Dynamic Text element
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   The Text element ID to which a new string needs to be copied
**                   p_string = Pointer to NULL terminated string
**                   p_anim_id = anim Id of text element
** Critical Section: None.
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_multi_line_text(GFX_MGR02_DTEXT_ID p_elem_id, HMI_CHAR const * p_string, GFX_MGR02_ANIM_ELEM_ID p_anim_id)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_multi_line_text(p_elem_id, p_string, p_anim_id);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}

#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_set_inter_line_spacing
** Visibility:       global
** Description:      Sets the inter line spacing value for a Dynamic Text element
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   p_elem_id - The Text element ID to which a inter line spacing needs to be changed
**                   p_inter_line_spacing = spacing needs to updated. 
**                   Note:
**                   Valid value for interline spacing should be positive. Application team should test thoroughly
**                   with all languages if they want to use negative spacing to avoid overlapping issues.
**                   Negative spacing allowed specifically for MKTA.
** Critical Section: None.
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_inter_line_spacing(GFX_MGR02_ANIM_ELEM_ID p_elem_id, SINT8 p_inter_line_spacing)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_inter_line_spacing(p_elem_id, p_inter_line_spacing);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
      l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
  return(fl_gfx_layout_error_code);
}
#endif
#endif
#if HM_LANG_MAX_SID > 0
/*============================================================================
** Function Name:    hmi_gfx_mgr02_set_sid
** Visibility:       global
** Description:      Sets the text value for a Dynamic Text element
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   The Text element ID to which a new string needs to be copied
**                   p_string = Pointer to NULL terminated string
** Critical Section: None.
** Created:          05-May-2011 by EMANOJ1
** Updated:          03-Jul-2013 by JANANDAL
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_sid(GFX_MGR02_DTEXT_ID p_elem_id, LANG_SID_T p_sid)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
	fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_sid(p_elem_id, p_sid);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}
#if (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_OPEN_GL)) && (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_set_multi_line_sid
** Visibility:       global
** Description:      Sets the text value for a Dynamic Text element
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   The Text element ID to which a new string needs to be copied
**                   p_string = Pointer to NULL terminated string
**                   p_anim_id = anim Id of text element
** Critical Section: None.
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_multi_line_sid(GFX_MGR02_DTEXT_ID p_elem_id, LANG_SID_T p_sid, GFX_MGR02_ANIM_ELEM_ID p_anim_id)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
	fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_multi_line_sid(p_elem_id, p_sid, p_anim_id);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}
#endif /* (GFX_MGR02_OPEN_VG) && (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) */
#endif /* HM_LANG_MAX_SID > 0 */

#endif /*#if GFX_MGR02_NUM_OF_DTEXTS > 0*/
#if (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_select_gfont_index
** Visibility:       global
** Description:      Sets a selected font index and the right2left flag for a  
**                   passed font group ID
** Invocation:       Invoked by if_layer/application
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          10-Jun-2013 by EMANOJ1
** Updated:          10-Jun-2013 by EMANOJ1
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_select_gfont_index(UINT32 p_font_id, UINT32 p_selection_index, UINT32 p_right2left)
{
   if(hmi_gfx_mgr02_layout_select_gfont_index(p_font_id, p_selection_index, p_right2left) == GUI_GFX_MGR_NO_ERROR)
   {
      l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
   }
   return(GUI_GFX_MGR_NO_ERROR);
}
#endif
#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_set_text_prop
** Visibility:       global
** Description:      Sets the text element property for the passed text 
**                   element.
** Invocation:       Invoked by if_layer/application
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          10-Jun-2013 by EMANOJ1
** Updated:          10-Jun-2013 by EMANOJ1
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_text_prop(GFX_MGR02_ANIM_ELEM_ID p_elem_id,
                                                        UINT32                 p_alignment, 
                                                        UINT32                 p_draw_mode,
                                                        UINT32                 p_clip_mode)
{
   GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
   fl_gfx_layout_error_code = (GUI_GFX_MGR_ERROR_CODE_T)hmi_gfx_mgr02_layout_set_text_prop(p_elem_id,p_alignment,p_draw_mode,p_clip_mode);
   if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
   {
      l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
   }
   return(fl_gfx_layout_error_code);
}
/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_set_text_scroll_parameter
** Visibility:       global
** Description:      Sets the scroll offset value for a scrollable Text element
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   The anim ID and the scroll offset value
** Critical Section: None.
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_text_scroll_parameter(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT16 p_scroll)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_text_scroll_parameter(p_elem_id, p_scroll);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS))
/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_set_font
** Visibility:       global
** Description:      Sets the font for a Dynamic Text element
** Invocation:       By presentation layer or the graphics interface layer
** Critical Section: None.
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_font(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT8 p_font_id, UINT8 p_font_pt_size)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_error = GUI_GFX_MGR_INVALID_TARGET;

#if defined(GFX_MGR02_USE_EXT_FONT_ENGINE)

    fl_error = hmi_gfx_mgr02_layout_set_font(p_elem_id, p_font_id, p_font_pt_size);

#endif

    if (fl_error == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = TRUE;
    }

    return fl_error;
}
#endif
#endif

#if GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0
/*============================================================================
** Function Name:    hmi_gfx_mgr02_select_dwidget
** Visibility:       global
** Description:      Sets the selection index for a dynamic widget
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   The Dynamic widget element ID in p_elem_id
**                   Selection index in p_index
** Critical Section: None.
** Created:          05-May-2011 by EMANOJ1
** Updated:          05-May-2011 by EMANOJ1
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_select_dwidget(GFX_MGR02_DWDG_ELEM_ID p_elem_id, UINT32 p_index)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;

    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_select_dwidget(p_elem_id, p_index);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}
#endif /*#if GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0*/

#if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
/*============================================================================
** Function Name:    hmi_gfx_mgr02_select_dimage
** Visibility:       global
** Description:      Sets the selection index for a dynamic image
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   The Dynamic image element ID in p_elem_id
**                   Selection index in p_index
** Critical Section: None.
** Created:          05-May-2011 by EMANOJ1
** Updated:          05-May-2011 by EMANOJ1
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_select_dimage(GFX_MGR02_DIMG_ELEM_ID p_elem_id, UINT32 p_index)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_select_dimage(p_elem_id, p_index);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}
#endif /*#if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0*/

#if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0)
/*============================================================================
** Function Name:    hmi_gfx_mgr02_set_obj_clut
** Visibility:       global
** Description:      Sets the CLUT index for the requested element. The CLUT
**                   can be set only if the element type is other than
**                   GFX_MGR02_TYPE_DIMAGE or GFX_MGR02_TYPE_DWIDGET AND if the
**                   element is having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and clut index in p_clut_id
** Critical Section: None.
** Created:          05-May-2011 by EMANOJ1
** Updated:          05-May-2011 by EMANOJ1
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_clut(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT32 p_clut_id)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_obj_clut(p_elem_id, p_clut_id);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}
#endif /* (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0) */

#if (GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0) || \
    (GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0) || \
    ((GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0) && defined(GFX_MGR02_CLIPPED_WIDGETS))
/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_set_obj_area
** Visibility:       global
** Description:      Sets the element area Property can be set only if the element
**                   type is GFX_MGR02_TYPE_SWIDGET AND if the element is having 
**                   a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and clip data in p_clip
** Critical Section: None.
** Updated:          19-Feb-2013 by ASHEKHAR
** Updated:          19-Feb-2013 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_area(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_IAREA_DATA const * p_clip)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_obj_area(p_elem_id, p_clip);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}
#endif

#if ((GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0) && defined(GFX_MGR02_CLIPPED_WIDGETS))
/*============================================================================
** Function Name:    hmi_gfx_mgr02_set_obj_vclip
** Visibility:       global
** Description:      Sets the vertical clipping property for the requested
**                   element. Property can be set only if the element is having 
**                   a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and clip property in p_clip
** Critical Section: None.
** Created:          05-May-2011 by EMANOJ1
** Updated:          19-Feb-2013 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_vclip(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_VCLIP_DATA const * p_clip)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_obj_vclip(p_elem_id, p_clip);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}
 #if !defined(GFX_MGR02_KEPLER)
/*============================================================================
** Function Name:    hmi_gfx_mgr02_set_obj_hclip
** Visibility:       global
** Description:      Sets the horizontal clipping property for the requested
**                   element. Property can be set only if the element is having
**                   a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and clip property in p_clip
** Critical Section: None.
** Created:          05-Apr-2016 by SBOLLAM
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_hclip(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_HCLIP_DATA const * p_clip)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_obj_hclip(p_elem_id, p_clip);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = TRUE;
    }
    return(fl_gfx_layout_error_code);
}
 #endif
#endif /* ((GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0) && defined(GFX_MGR02_CLIPPED_WIDGETS)) */

/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_set_obj_alpha
** Visibility:       global
** Description:      Sets the alpha for the requested element.
**                   can be set only if the element type is other than
**                   GFX_MGR02_TYPE_DIMAGE or GFX_MGR02_TYPE_DWIDGET AND if the
**                   element is having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and alpha value in p_alpha
** Critical Section: None.
** Created:          19-Apr-2011 by EMANOJ1
** Updated:          19-Apr-2011 by EMANOJ1
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_alpha(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT32 p_alpha)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_obj_alpha(p_elem_id, (GFX_MGR02_ALPHA)p_alpha);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}

#if ((GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0))
/*============================================================================
** Function Name:    hmi_gfx_mgr02_set_obj_fg_color
** Visibility:       global
** Description:      Sets the foreground color for the requested element. Color
**                   can be set only if the element type is other than
**                   GFX_MGR02_TYPE_DIMAGE or GFX_MGR02_TYPE_DWIDGET AND if the
**                   element is having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and color in p_color
** Critical Section: None.
** Created:          05-May-2011 by EMANOJ1
** Updated:          19-Feb-2013 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_fg_color(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT32 p_color)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_obj_draw_color(p_elem_id, p_color);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}
#endif

/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_set_obj_pos
** Visibility:       global
** Description:      Sets the x, y coordinate property for the requested
**                   element. Property can be set only if the element is having 
**                   a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and x, y property in p_pos
** Critical Section: None.
** Created:          19-Feb-2013 by ASHEKHAR
** Updated:          19-Feb-2013 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_pos(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_ILOC_DATA const * p_pos)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_obj_pos(p_elem_id, (GFX_MGR02_ILOC_DATA const *)p_pos);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_set_obj_pos_x
** Visibility:       global
** Description:      Sets the x coordinate property for the requested
**                   element. Property can be set only if the element is 
**                   having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and x property in p_pos_x
** Critical Section: None.
** Created:          05-May-2011 by EMANOJ1
** Updated:          19-Feb-2013 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_pos_x(GFX_MGR02_ANIM_ELEM_ID p_elem_id, SINT16 p_pos_x)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_obj_pos_x(p_elem_id, p_pos_x);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_set_obj_pos_y
** Visibility:       global
** Description:      Sets the y coordinate property for the requested
**                   element. Property can be set only if the element is 
**                   having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and y property in p_pos_y
** Critical Section: None.
** Created:          19-Feb-2013 by ASHEKHAR
** Updated:          19-Feb-2013 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_pos_y(GFX_MGR02_ANIM_ELEM_ID p_elem_id, SINT16 p_pos_y)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_obj_pos_y(p_elem_id, p_pos_y);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_get_obj_pos
** Visibility:       global
** Description:      Gets the X, Y coordinates property for the requested
**                   element. Property can get only if the element is 
**                   having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and LOC DATA property in p_pos
** Critical Section: None.
** Created:          19-Feb-2013 by ASHEKHAR
** Updated:          19-Feb-2013 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_get_obj_pos(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_ILOC_DATA * p_pos)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_get_obj_pos(p_elem_id, p_pos);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_set_obj_default_properties
** Visibility:       global
** Description:      Sets the default properties for the requested
**                   element. Property can get only if the element is 
**                   having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id
** Critical Section: None.
** Created:          19-Feb-2013 by ASHEKHAR
** Updated:          19-Feb-2013 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_default_properties(GFX_MGR02_ANIM_ELEM_ID p_elem_id)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_obj_default_properties(p_elem_id);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}

#if (GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0)
/*============================================================================
** Function Name:    hmi_gfx_mgr02_set_obj_tile
** Visibility:       global
** Description:      Sets the Tile configuration for the requested element.Tile
**                   can be set only if the element type is other than
**                   GFX_MGR02_TYPE_DIMAGE or GFX_MGR02_TYPE_DWIDGET AND if the
**                   element is having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and tile parameters in p_tile
** Critical Section: None.
** Created:          05-May-2011 by EMANOJ1
** Updated:          05-May-2011 by EMANOJ1
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_tile(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_TILE_DATA const * p_tile)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    GFX_MGR02_IDIM_DATA fl_dim;
    fl_dim.height = p_tile->ver_size;
    fl_dim.width  = p_tile->hor_size;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_obj_dim(p_elem_id, (GFX_MGR02_IDIM_DATA const *)&fl_dim);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_set_obj_pos_y
** Visibility:       global
** Description:      Sets the y coordinate property for the requested
**                   element. Property can be set only if the element type is
**                   other than GFX_MGR02_TYPE_DIMAGE or GFX_MGR02_TYPE_DWIDGET
**                   AND if the element is having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and y property in p_pos_y
** Critical Section: None.
** Created:          19-Feb-2013 by ASHEKHAR
** Updated:          19-Feb-2013 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_dim_h(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT32 p_dim_h)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_obj_dim_h(p_elem_id, p_dim_h);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_set_obj_pos_y
** Visibility:       global
** Description:      Sets the y coordinate property for the requested
**                   element. Property can be set only if the element type is
**                   other than GFX_MGR02_TYPE_DIMAGE or GFX_MGR02_TYPE_DWIDGET
**                   AND if the element is having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and y property in p_pos_y
** Critical Section: None.
** Created:          19-Feb-2013 by ASHEKHAR
** Updated:          19-Feb-2013 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_dim_w(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT32 p_dim_w)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_obj_dim_w(p_elem_id, p_dim_w);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_set_obj_dim
** Visibility:       global
** Description:      Sets the y coordinate property for the requested
**                   element. Property can be set only if the element type is
**                   other than GFX_MGR02_TYPE_DIMAGE or GFX_MGR02_TYPE_DWIDGET
**                   AND if the element is having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and y property in p_pos_y
** Critical Section: None.
** Created:          19-Feb-2013 by ASHEKHAR
** Updated:          19-Feb-2013 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_dim(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_IDIM_DATA const * p_dim)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_obj_dim(p_elem_id, p_dim);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}
#endif /* (GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0) */

#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) ||defined(GFX_MGR02_FUJITSU)||defined (GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)

/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_set_obj_pivot_x
** Visibility:       global
** Description:      Sets the pivot x coordinate property for the requested
**                   element. Property can be set only if the element is 
**                   having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and x property in p_pos_x
** Critical Section: None.
** Created:          15-Mar-2018 by EMANOJ1
** Updated:          
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_pivot_x(GFX_MGR02_ANIM_ELEM_ID p_elem_id, SINT16 p_pos_x)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_obj_pivot_x(p_elem_id, p_pos_x);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_set_obj_pivot_y
** Visibility:       global
** Description:      Sets the pivot y coordinate property for the requested
**                   element. Property can be set only if the element is 
**                   having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and y property in p_pos_y
** Critical Section: None.
** Created:          15-Mar-2018 by CSAKTHIV
** Updated:          
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_pivot_y(GFX_MGR02_ANIM_ELEM_ID p_elem_id, SINT16 p_pos_y)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_obj_pivot_y(p_elem_id, p_pos_y);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}


/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_set_obj_transformation
** Visibility:       global
** Description:      Sets the transformation property for the requested
**                   element. Property can be set only if the element type is
**                   other than GFX_MGR02_TYPE_DIMAGE or GFX_MGR02_TYPE_DWIDGET
**                   AND if the element is having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and y property in p_pos_y
** Critical Section: None.
** Created:          19-Feb-2013 by ASHEKHAR
** Updated:          19-Feb-2013 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_mul_obj_transformation(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_FLOAT const * p_matrix)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_mul_obj_transformation(p_elem_id, p_matrix);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_set_obj_transformation
** Visibility:       global
** Description:      Sets the transformation property for the requested
**                   element. Property can be set only if the element type is
**                   other than GFX_MGR02_TYPE_DIMAGE or GFX_MGR02_TYPE_DWIDGET
**                   AND if the element is having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and y property in p_pos_y
** Critical Section: None.
** Created:          19-Feb-2013 by ASHEKHAR
** Updated:          19-Feb-2013 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_transformation(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_FLOAT const * p_matrix)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_obj_transformation(p_elem_id, p_matrix);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_set_obj_dim
** Visibility:       global
** Description:      Sets the y coordinate property for the requested
**                   element. Property can be set only if the element type is
**                   other than GFX_MGR02_TYPE_DIMAGE or GFX_MGR02_TYPE_DWIDGET
**                   AND if the element is having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and y property in p_pos_y
** Critical Section: None.
** Created:          19-Feb-2013 by ASHEKHAR
** Updated:          19-Feb-2013 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_scale(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_FLOAT p_scalex, GFX_FLOAT p_scaley)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_obj_scale(p_elem_id, p_scalex, p_scaley);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_set_obj_dim
** Visibility:       global
** Description:      Sets the y coordinate property for the requested
**                   element. Property can be set only if the element type is
**                   other than GFX_MGR02_TYPE_DIMAGE or GFX_MGR02_TYPE_DWIDGET
**                   AND if the element is having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and y property in p_pos_y
** Critical Section: None.
** Created:          19-Feb-2013 by ASHEKHAR
** Updated:          19-Feb-2013 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_rotate(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_FLOAT p_angle)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_gfx_layout_error_code;
    fl_gfx_layout_error_code = hmi_gfx_mgr02_layout_set_obj_rotate(p_elem_id, p_angle);
    if(fl_gfx_layout_error_code == GUI_GFX_MGR_NO_ERROR)
    {
       l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
    }
    return(fl_gfx_layout_error_code);
}
#endif  /* GFX_MGR02_OPEN_VG */

#if defined(GFX_MGR02_USE_PTHREAD_MUTEX)
/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_begin_update
** Visibility:       global
** Description:      In a multithreaded environment, and when the if apis are 
**                   called from multiple threads, chances are that (1) the 
**                   Graphics_Task() might execute before application finishes
**                   all the api calls necessary to set the data. In this case
**                   to gurantee that all the apis are invoked before the 
**                   Graphics_Task() begins and the Graphics_Task() might use
**                   half updated data resulting incomplete screen update
**                   (2) also there is another chance that the API calls can 
**                   change the data while Graphics_Task() is in progress. 
**                   This may have dangeraous effects such as corruot display
**                   or even a crash. So inorder to protect we have to stream 
**                   line the api calls to prevent reentrancy by a mutex. 
**                   So all application api calls to graphics manager has to be
**                   enclosed with in begin_update() and end_update() block.
**                   hmi_gfx_mgr02_if_begin_update()
**                     .. other if api calls such as hmi_gfx_mgr02_if_set_screen
**                     ..
**                   hmi_gfx_mgr02_if_end_update()
** Invocation:       Invoked by application
** Inputs/Outputs:   None
** Critical Section: None.
** Created:          16-MAY-2014
** Updated:          16-MAY-2014
**==========================================================================*/
void hmi_gfx_mgr02_if_begin_update(void)
{
   GFX_MGR02_IFBUILD_MUTEX_LOCK();
}
/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_end_update
** Visibility:       global
** Description:      see comments for hmi_gfx_mgr02_if_begin_update 
** Invocation:       Invoked by application
** Inputs/Outputs:   None
** Critical Section: None.
** Created:          16-MAY-2014
** Updated:          16-MAY-2014
**==========================================================================*/
void hmi_gfx_mgr02_if_end_update(void)
{
   GFX_MGR02_IFBUILD_MUTEX_UNLOCK();
}
#endif
#if ((GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) && defined(GFX_MGR02_OPEN_VG))
/****************************************************************************
Function Name        : hmi_gfx_mgr02_if_add_to_vgcache
Description          : Interface to add image to openvg cache. Used for faster animation
Invocation           : Invoked by application
Parameters           : None
Return Value         : GUI_GFX_MGR_NO_ERROR if  success
Critical Section     : None
External Interfaces  : None
******************************************************************************/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_add_to_vgcache(UINT32 fl_image_base_id)
{
   GUI_GFX_MGR_ERROR_CODE_T  fl_return_result = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;

   GFX_MGR02_IMAGE_DEF_T const * fl_element_def_SP;

   if(fl_image_base_id < GFX_MGR02_NUM_OF_IMAGE_LAYERS)
   {
      fl_return_result = GUI_GFX_MGR_NO_ERROR;
      #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        fl_element_def_SP =  hmi_gfx_mgr02_get_image_layer_def_ptr(fl_image_base_id);
      #else
        fl_element_def_SP =  &lc_image_layer_def_S[fl_image_base_id];
      #endif
      (void)hmi_gfx_mgr02_ovglib_cache_get_object(fl_element_def_SP, GFX_MGR02_BITMAP_TYPE_E,FALSE, 0);
   }
   return(fl_return_result);

}
#endif
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
/*============================================================================
** Function Name:    hmi_gfx_mgr02_if_select_dlayout_index
** Visibility:       global
** Description:      Sets a selected design layout index 
** Invocation:       Invoked by if_layer/application
** Inputs/Outputs:   GFX_MGR02_LAYOUT_ID p_selection_index
** Critical Section: None.
** Created:          15-Jul-2016 by CMUTHUSA
** Updated:          15-Jul-2016 by CMUTHUSA
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_select_dlayout_index(GFX_MGR02_LAYOUT_ID p_selection_index)
{
   GUI_GFX_MGR_ERROR_CODE_T  fl_return_sts = GUI_GFX_MGR_INVALID_DLAYOUT;

   fl_return_sts=hmi_gfx_mgr02_layout_select_dlayout_index(p_selection_index);
   if(fl_return_sts == GUI_GFX_MGR_NO_ERROR)
   {
      l_gfx_mgr02_if_update_pending = (UINT8)TRUE;
   }
   return(fl_return_sts);
}
#endif

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
** CMS Rev 1.25      03-Feb-2020    ARAJASE2
** 1408882: [MKTA & MKJH] - Upgradation in GDT tool to reduce the line - 
** spacing in case of Multi line text (709586)
**
** CMS Rev 1.24      30-Nov-2017    ARAJASE2
** 1005357: Graphics Manager update for Hebrew Text rendering
** Enabled existing arabic related code for GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED macro also
**
** CMS Rev 1.23      08-Aug-2017    ARAJASE2
** Added new function hmi_gfx_mgr02_if_set_inter_line_spacing to support dynamic update
** of inter line spacing
** 922409: Dynamic Inter-line spacing for multi-line text
**
** CMS Rev 1.22      22-Jul-2016    CMUTHUSA
** 642213: Coding and implementation in GDT simulation for Arabic Design Layout support in gfx mgr 02.
**
** CMS Rev 1.21     22-July-2016    ADEVI
** 610788: Multi - line data saved and new line requirement changes.
**
** CMS Rev 1.20      28-Apr-2016    ADEVI
** 546876: Add support to change the Text Size Dynamically when Font Engine is used.
**
** CMS Rev 1.19      06-Apr-2016    CSAKTHIV
** 557102: Interface to create openvg image handle before starting animation
**
** CMS Rev 1.18      04-Apr-2016    SBOLLAM
** 558616: Dynamic horizontal clip for widgets
** Added a new interface <hmi_gfx_mgr02_if_set_obj_hclip>
**
** CMS Rev 1.17     27-May-2015    CSAKTHIV
** Ref RTC: 338234
** hmi_gfx_mgr02_if_get_text_width interface added.
**
** CMS Rev 1.16     5-Feb-2015    ADEVI
** Ref RTC: 282879
** hmi_gfx_mgr02_if_set_screen_dyn_priority interface added.
**
** CMS Rev 1.15     25-Jul-2014    EMANOJ1
** hmi_gfx_mgr02_if_presentation_task updated to invoke 
** hmi_gfx_mgr02_layout_process_touch_events() to avoid unnecessary build
** screen invocation. 
**
** CMS Rev 1.14     19-May-2014    EMANOJ1
** >Mutex lock/unlock is contained to just begin_update() and end_update()
** so that application apply this to a set of api calls together rather than
** doing for each apis.
** >Fixed P42M coverifty issue in hmi_gfx_mgr02_layout_validate_layer_area()
** and hmi_gfx_mgr02_layout_process_touch_event()
** >fixed an issue reported by std.plus team that an invisible touch button
** beneath a screen which has no touch event is getting acted up on. So fix
** done in hmi_gfx_mgr02_layout_is_touch_object_visible.
**
** CMS Rev 1.13     15-May-2014    EMANOJ1
** Replaced HM_LANG_MAX_STRING_SIZE with GFX_MGR02_MAX_TEXT_LENGTH
**
** CMS Rev 1.12     12-May-2014    EMANOJ1
** Added pthread mutex lock/unlock support to prevent application from setting 
** graphics manager properties while the Graphics_Task is in progress.
**
** CMS Rev 1.11     25-Nov-2013    CMUTHUSA
** Fujitsu Platform modifications added to changeset base rel_UI.CORE.3.12.08 version
**
** CMS Rev 1.10     03-Mar-2014    EMANOJ1
** hmi_gfx_mgr02_if_presentation_task updated to fix compiler issue on non touch
** version.
**
** CMS Rev 1.9      20-Feb-2014    EMANOJ1
** Updated to fix RTC 122638
**
** CMS Rev 1.8      21-Nov-2013    SBOLLAM
** Fixed compiler issue related to fl_string for HM_LANG_USE_INERNAL_STRING_BUFFER
** configuration fixed in hmi_gfx_mgr02_if_set_sid
**
** CMS Rev 1.7      30-Oct-2013    EMANOJ1
** Integrated changes from TVM to support arabic language
**
** CMS Rev 1.6      29-Aug-2013    EMANOJ1
** Added more protection for invalid sid/pointer in hmi_gfx_mgr02_if_set_sid
**
** CMS Rev 1.5      10-Jun-2013    EMANOJ1
** hmi_gfx_mgr02_layout_initialize call removed from hmi_gfx_mgr02_if_KSColdInit
** since this will be called when hmi_gfx_mgr02_if_start() is performed. 
**
** CMS Rev 1.5      10-Jun-2013    EMANOJ1
** Added interface to set/get font group properties, text element properties
**
** CMS Rev 1.4      06-Jun-2013    EMANOJ1
** Animation engine call made after GFX_MGR02_IF_APP_PRESENTATION_TASK() since
** animation start command by VM is issued in the GFX_MGR02_IF_APP_PRESENTATION_TASK()
** context, so there will be a cycle delay if we schedule the anim engine before
** presentation task.
**
** CMS Rev 1.3      30-Apr-2013    EMANOJ1
** Compiler switch updated for functions hmi_gfx_mgr02_if_set_obj_area and
** hmi_gfx_mgr02_if_set_obj_vclip to support area animation for fill and tile
**
** CMS Rev 1.2      20-Mar-2013    EMANOJ1
** Added interface to expose matrix multiplication function.
**
** CMS Rev 1.1      19-Feb-2013    ASHEKHAR
** Updated all interfaces for layout manager compatible functions.
**
** CMS Rev 1.0      19-Feb-2013    EMANOJ1
** Creation.
**==========================================================================*/
#ifdef  __cplusplus
}
#endif

/* end of file =============================================================*/
