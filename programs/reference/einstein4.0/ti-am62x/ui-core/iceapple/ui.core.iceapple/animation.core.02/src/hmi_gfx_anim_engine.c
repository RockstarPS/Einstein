/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2011. Visteon Corporation owns all rights to this work and
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
** Name:           hmi_gfx_mgr02.c
**
** Description:    Main graphics manager 02 logic implementation module
**                 Manages the display building operations.
**
** Organization:   Driver Information Software Section,
**                 Visteon
**
**============================================================================
**
**==========================================================================*/
#define HMI_GFX_ANIM_ENGINE_C

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_anim_engine.h"
#include "hmi_gfx_anim_engine.cfg"

#if defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
#include <math.h>
#include <float.h>
#endif

#ifdef GFX_ANIM_DEBUG
#include <stdio.h>
#endif
#include "string.h"


#ifdef  __cplusplus
extern "C" {
#endif

/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/

#define GFX_ANIM_ARGB(a, r, g, b)     ((((UINT32)(a))<<24) | (((UINT32)(r))<<16) | (((UINT32)(g))<<8) | ((UINT32)(b)))
#define GFX_ANIM_SCLAMP(val, min, max) (((val)>(max))?(max):(((val)<(min))?(min):(val)))
#define GFX_ANIM_UCLAMP(val, max)      (((val)>(max))?(max):(val))

#define GFX_ANIM_DIR_FORWARD   (0U)
#define GFX_ANIM_DIR_BACKWORD  (1U)

#define GFX_ANIM_MAX_U8 0xFFU


#if defined(GFX_NUM_SINE_UP_ANIMATIONS) || defined(GFX_NUM_SINE_DOWN_ANIMATIONS) || defined(GFX_NUM_LOG_UP_ANIMATIONS) || defined(GFX_NUM_LOG_DOWN_ANIMATIONS)
#define GFX_ANIM_UP_DN_TABLE_NUM_ENTRIES 19u
#endif
#if defined(GFX_NUM_SINE_UPDOWN_ANIMATIONS) || defined(GFX_NUM_SINE_DOWNUP_ANIMATIONS) || defined(GFX_NUM_LOG_UPDOWN_ANIMATIONS) || defined(GFX_NUM_LOG_DOWNUP_ANIMATIONS)
#define GFX_ANIM_UPDN_DNUP_TABLE_NUM_ENTRIES 37u
#endif 
#if defined(GFX_NUM_EXPONENTIAL_ANIMATIONS)
#define GFX_ANIM_EXPONENTIAL_TABLE_NUM_ENTRIES (11u)
#endif
#define GFX_ANIM_TABLE_SCALE_FACTOR(X)  ((UINT32)(((UINT32)10000)/((UINT32)(X))))
typedef struct
{
   GFX_UINT  dir        :1;
   GFX_UINT  start      :1;
   GFX_UINT  end_reached:1;
   GFX_UINT  state      :2;
#if GFX_ANIM_GOTO_COUNT_ARRAY_SIZE > 0
   /* 
   ** This puts a limitation that there can be a maximum of 127
   ** frames only when a goto is used inside an animation
   */
   SINT8  goto_frame_cnt; 
#endif
}GFX_ANIM_FLAGS_T;

typedef struct
{
   UINT32                       anim_id;
   UINT32                       end_reached; 
   GFX_ANIM_DEF_T const       * def_sp;
   GFX_ANIM_FRAME_DEF_T const * frames_sp;
   GFX_ANIM_TYPES_DEF_T const * types_sp;
   UINT32                       timer_U32;
   UINT32                       prev_elap_time_U32;
}GFX_ANIM_CONTROL_T;

typedef void (* GFX_ANIM_HANDLER_CB)(GFX_ANIM_TYPES_DEF_T const * p_tdata, UINT32 p_cur_per, UINT32 p_pre_per);

/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/

#if GFX_NUM_ANIMATIONS > 0
static BOOLEAN hmi_gfx_anim_engine_run(GFX_ANIM_CONTROL_T * p_anim_ctrl_SP);
static void   hmi_gfx_anim_engine_stop(UINT32 p_anim_id);
#if defined GFX_NUM_LINEAR_ANIMATIONS
static UINT32 hmi_gfx_anim_engine_linear_interpolate(UINT32 p_cur_step, UINT32 p_max_step);
#endif
#if defined GFX_NUM_EXPONENTIAL_ANIMATIONS
static UINT32 hmi_gfx_anim_engine_exponential_interpolate(UINT32 p_cur_step, UINT32 p_max_step);
#endif
#if defined GFX_NUM_SINE_UP_ANIMATIONS
static UINT32 hmi_gfx_anim_engine_sine_up_interpolate(UINT32 p_cur_step, UINT32 p_max_step);
#endif
#if defined GFX_NUM_SINE_DOWN_ANIMATIONS
static UINT32 hmi_gfx_anim_engine_sine_down_interpolate(UINT32 p_cur_step, UINT32 p_max_step);
#endif
#if defined GFX_NUM_SINE_UPDOWN_ANIMATIONS
static UINT32 hmi_gfx_anim_engine_sine_updown_interpolate(UINT32 p_cur_step, UINT32 p_max_step);
#endif
#if defined GFX_NUM_SINE_DOWNUP_ANIMATIONS
static UINT32 hmi_gfx_anim_engine_sine_downup_interpolate(UINT32 p_cur_step, UINT32 p_max_step);
#endif
#if defined GFX_NUM_LOG_UP_ANIMATIONS
static UINT32 hmi_gfx_anim_engine_log_up_interpolate(UINT32 p_cur_step, UINT32 p_max_step);
#endif
#if defined GFX_NUM_LOG_DOWN_ANIMATIONS
static UINT32 hmi_gfx_anim_engine_log_down_interpolate(UINT32 p_cur_step, UINT32 p_max_step);
#endif
#if defined GFX_NUM_LOG_UPDOWN_ANIMATIONS
static UINT32 hmi_gfx_anim_engine_log_updown_interpolate(UINT32 p_cur_step, UINT32 p_max_step);
#endif
#if defined GFX_NUM_LOG_DOWNUP_ANIMATIONS 
static UINT32 hmi_gfx_anim_engine_log_downup_interpolate(UINT32 p_cur_step, UINT32 p_max_step);
#endif
#if defined GFX_NON_LINEAR_INTERPOLATIONS
static UINT32 hmi_gfx_anim_engine_table_interpolate(UINT16 const * p_table_U16AP, 
                                                    UINT32         p_table_max_index, 
                                                    UINT32         p_table_scale_factor, 
                                                    UINT32         p_percentage_in);
#endif
#if GFX_ANIM_GOTO_COUNT_ARRAY_SIZE > 0
static void hmi_gfx_anim_engine_set_frame(GFX_ANIM_CONTROL_T const * p_anim_ctrl_SP, UINT32 p_frame);
#endif
static void hmi_gfx_anim_engine_next_frame(GFX_ANIM_CONTROL_T const * p_anim_ctrl_SP);

static SINT32 hmi_gfx_anim_engine_find_idelta(SINT32 p_start_val, SINT32 p_end_val, UINT32 p_percentage);
#if defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
static GFX_FLOAT  hmi_gfx_anim_engine_find_fdelta(GFX_FLOAT p_start_val, GFX_FLOAT p_end_val, UINT32 p_percentage);
#endif
static void hmi_gfx_anim_engine_alpha(GFX_ANIM_TYPES_DEF_T const * p_tdata, UINT32 p_cur_per, UINT32 p_pre_per);   
static void hmi_gfx_anim_engine_area(GFX_ANIM_TYPES_DEF_T const * p_tdata, UINT32 p_cur_per, UINT32 p_pre_per);    
static void hmi_gfx_anim_engine_wd_ht(GFX_ANIM_TYPES_DEF_T const * p_tdata, UINT32 p_cur_per, UINT32 p_pre_per);   
static void hmi_gfx_anim_engine_color(GFX_ANIM_TYPES_DEF_T const * p_tdata, UINT32 p_cur_per, UINT32 p_pre_per);   
static void hmi_gfx_anim_engine_data(GFX_ANIM_TYPES_DEF_T const * p_tdata, UINT32 p_cur_per, UINT32 p_pre_per);    
static void hmi_gfx_anim_engine_mal(GFX_ANIM_TYPES_DEF_T const * p_tdata, UINT32 p_cur_per, UINT32 p_pre_per);     
static void hmi_gfx_anim_engine_map(GFX_ANIM_TYPES_DEF_T  const * p_tdata, UINT32 p_cur_per, UINT32 p_pre_per);     
static void hmi_gfx_anim_engine_screen(GFX_ANIM_TYPES_DEF_T const * p_tdata, UINT32 p_cur_per, UINT32 p_pre_per);  
#if defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
static void hmi_gfx_anim_engine_rotate(GFX_ANIM_TYPES_DEF_T const * p_tdata, UINT32 p_cur_per, UINT32 p_pre_per);  
static void hmi_gfx_anim_engine_scale(GFX_ANIM_TYPES_DEF_T const * p_tdata, UINT32 p_cur_per, UINT32 p_pre_per);   
static void hmi_gfx_anim_engine_transform(GFX_ANIM_TYPES_DEF_T const * p_tdata, UINT32 p_cur_per, UINT32 p_pre_per);
#endif
#ifdef GFX_DYN_DATA_ANIMATIONS
static UINT32 hmi_gfx_anim_engine_calculate_dduration(GFX_ANIM_CONTROL_T const * p_anim_ctrl_SP, UINT32 p_anim_duration);
#endif
#endif /* #if GFX_NUM_ANIMATIONS > 0 */

/*============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/

#if GFX_NUM_ANIMATIONS > 0
#include "hmi_gfx_anim_engine_data.rom"

static UINT32 l_anim_timer_cur_U32;
static UINT32 l_anim_timer_pre_U32;

static UINT32           l_current_anim_id_U32 = GFX_NUM_ANIMATIONS;
static UINT32           l_anim_time_elapsed_U32A[GFX_NUM_ANIMATIONS];
static UINT16           l_anim_client_id_U16A[GFX_NUM_ANIMATIONS];
static UINT8            l_anim_frame_U8A[GFX_NUM_ANIMATIONS];
static GFX_ANIM_FLAGS_T l_anim_flags_SA[GFX_NUM_ANIMATIONS];
#if defined(GFX_ANIM_DLAYOUT_ENABLED)
static UINT8 l_selected_anim_layout_U8;
#endif


#if defined GFX_NUM_EXPONENTIAL_ANIMATIONS
static UINT16 const lc_anim_exponential_table[GFX_ANIM_EXPONENTIAL_TABLE_NUM_ENTRIES]   = {0,4,9,29,63,127,220,343,514,730,1000};
#endif

#if defined GFX_NUM_SINE_UP_ANIMATIONS
static UINT16 const lc_anim_sineup_table[GFX_ANIM_UP_DN_TABLE_NUM_ENTRIES]   = {0,87,173,258,342,422,500,573,642,707,766,819,866,906,939,965,984,996,1000};
#endif
#if defined GFX_NUM_SINE_DOWN_ANIMATIONS
static UINT16 const lc_anim_sinedn_table[GFX_ANIM_UP_DN_TABLE_NUM_ENTRIES]   = {0, 4, 16, 35, 61, 94,134,181,234,293,358,427,500,578,658,742,827,913,1000};
#endif
#if defined GFX_NUM_SINE_UPDOWN_ANIMATIONS
static UINT16 const lc_anim_sineupdn_table[GFX_ANIM_UPDN_DNUP_TABLE_NUM_ENTRIES] = {0,43, 86,129,171,211,250,286,321,353,383,409,433,453,469,482,492,498, 500,502,508,517,530,547,567,590,617,646,679,713,750,789,829,871,913,956,1000};
#endif
#if defined GFX_NUM_SINE_DOWNUP_ANIMATIONS
static UINT16 const lc_anim_sinednup_table[GFX_ANIM_UPDN_DNUP_TABLE_NUM_ENTRIES] = {0, 2,  8, 17, 30, 47, 67, 90,117,146,179,213,250,289,329,371,413,456, 500,543,586,629,671,711,750,786,821,853,883,909,933,953,969,982,992,998,1000};
#endif
#if defined GFX_NUM_LOG_UP_ANIMATIONS
static UINT16 const lc_anim_logup_table[GFX_ANIM_UP_DN_TABLE_NUM_ENTRIES]    = {0,23,46,71,97,125,155,188,222,260,302,347,398,456,523,603,699,824,1000};
#endif
#if defined GFX_NUM_LOG_DOWN_ANIMATIONS
static UINT16 const lc_anim_logdn_table[GFX_ANIM_UP_DN_TABLE_NUM_ENTRIES]    = {0,176,301,397,477,544,602,653,698,740,778,812,845,875,903,929,954,977,1000};
#endif
#if defined GFX_NUM_LOG_UPDOWN_ANIMATIONS
static UINT16 const lc_anim_logupdn_table[GFX_ANIM_UPDN_DNUP_TABLE_NUM_ENTRIES]  = {0,11,23,35,48,62,77,94,111,130,151,173,199,228,261,301,349,412,500,588,650,698,738,772,801,826,849,870,889,906,922,937,951,964,977,988,1000};
#endif
#if defined GFX_NUM_LOG_DOWNUP_ANIMATIONS 
static UINT16 const lc_anim_logdnup_table[GFX_ANIM_UPDN_DNUP_TABLE_NUM_ENTRIES]  = {0,88,150,198,238,272,301,326,349,370,389,406,422,437,451,464,477,488,500,511,523,535,548,562,577,594,611,630,651,673,699,728,761,801,849,912,1000};
#endif
#endif /* #if GFX_NUM_ANIMATIONS > 0 */

/*============================================================================
** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

#if GFX_NUM_ANIMATIONS > 0
/*============================================================================
** Function Name:    hmi_gfx_anim_engine_init
** Visibility:       global
** Description:      initializes the anim engine. 
** Invocation:       By apps
** Inputs/Outputs:   Set all animations to stopped. Sets anim timer to 0
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
void hmi_gfx_anim_engine_init(void)
{
   (void)memset(&l_anim_time_elapsed_U32A[0],    0, sizeof(l_anim_time_elapsed_U32A));
   (void)memset(&l_anim_flags_SA[0],             0, sizeof(l_anim_flags_SA));
   (void)memset(&l_anim_client_id_U16A[0],       0, sizeof(l_anim_client_id_U16A));
   (void)memset(&l_anim_frame_U8A[0],            0, sizeof(l_anim_frame_U8A));
   l_anim_timer_cur_U32 = (UINT32)0;
   l_anim_timer_pre_U32 = (UINT32)0;
   l_current_anim_id_U32 = (UINT32)GFX_NUM_ANIMATIONS; 
   #if defined(GFX_ANIM_DLAYOUT_ENABLED)
	l_selected_anim_layout_U8=0;
   #endif
}

/*============================================================================
** Function Name:    hmi_gfx_anim_engine_tick
** Visibility:       global
** Description:      increments the anim timer. 
** Invocation:       By apps from vsync ISR or by software timer at 
**                   (GFX_BASE_ANIM_RATE_MSEC/GFX_BASE_ANIM_RATE_SCALE) mSec 
**                   rate 
** Inputs/Outputs:   increments the timer
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
void hmi_gfx_anim_engine_tick(void)
{
   UINT32 fl_anim_rate  =  (UINT32)GFX_BASE_ANIM_RATE_MSEC;  
   l_anim_timer_cur_U32 += fl_anim_rate;
}

/*============================================================================
** Function Name:    hmi_gfx_anim_command
** Visibility:       global
** Description:      Issues a command to the animation engine to control the
**                   animation
** Invocation:       By Application
** Inputs/Outputs:   In : Control paramters
**                        p_client_id  - Client id to be associated with the anim
**                        p_anim_id    - Animation Id
**                        p_param_flag - Command flags. See header file for 
**                                       detaled information.
**                   Out : GFX_ANIM_STATE_FAULT - request is invalid and
**                         therefor request ignored. Animation is not started
**                         If the requested is accepted the cur state of the 
**                         animation is returned. The current state can be 
**                         GFX_ANIM_STATE_STOPPED - if stopped
**                         GFX_ANIM_STATE_RUNNING - if running
**                         GFX_ANIM_STATE_PAUSED  - if paused
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
UINT32 hmi_gfx_anim_command(UINT32 p_client_id, UINT32 p_anim_id, UINT32 p_param_flag)
{
   UINT32                     * fl_anim_telapsed_U32AP;
   GFX_ANIM_FLAGS_T           * fl_anim_flags_SAP;
   UINT16                     * fl_anim_client_id_U16AP;
   UINT8                      * fl_anim_frame_U8AP;
   GFX_ANIM_DEF_T       const * fl_anim_def_SP;
   GFX_ANIM_FRAME_DEF_T const * fl_frames_SP;
   UINT32                       fl_status = GFX_ANIM_STATE_FAULT;

   if(p_anim_id < (UINT32)GFX_NUM_ANIMATIONS)
   {
      fl_anim_telapsed_U32AP   = &l_anim_time_elapsed_U32A[p_anim_id];
      fl_anim_flags_SAP        = &l_anim_flags_SA[p_anim_id];
      fl_anim_client_id_U16AP  = &l_anim_client_id_U16A[p_anim_id];
      fl_anim_frame_U8AP       = &l_anim_frame_U8A[p_anim_id];
      fl_anim_def_SP           = &lc_animation_table_S[p_anim_id];

      if(fl_anim_def_SP->num_frames > (UINT32)0)
      {
         if(fl_anim_flags_SAP->state == GFX_ANIM_STATE_RUNNING)
         {
            /*
            ** Animation is already in running state.
            ** So if Stop flag set => Stop animation
            ** If pause flag set   => Pause animation
            */
            if((((UINT8)p_param_flag) & GFX_ANIM_STOP) == GFX_ANIM_STOP)
            {
               fl_anim_flags_SAP->state = GFX_ANIM_STATE_STOPPED;
               fl_anim_flags_SAP->dir   = GFX_ANIM_DIR_FORWARD;
               *fl_anim_telapsed_U32AP  = (UINT32)0;
               *fl_anim_frame_U8AP      = (UINT8)0;
               if(fl_anim_def_SP->cb != GFX_ANIM02_NULL_PTR)
               {
                  /*
                  ** Animation is getting stopped by application while its still
                  ** running, so notify app handler if its configured with last 
                  ** frame status
                  */
                  #if defined (GFX_ANIM_APP_CB_WITH_ANIM_ID)
                  fl_anim_def_SP->cb(fl_anim_def_SP->num_frames, fl_anim_def_SP->num_frames, p_anim_id);
                  #else
                  fl_anim_def_SP->cb(fl_anim_def_SP->num_frames, fl_anim_def_SP->num_frames);    
                  #endif
               }
            }
            else if((((UINT8)p_param_flag) & GFX_ANIM_PAUSE) == GFX_ANIM_PAUSE)
            {
               fl_anim_flags_SAP->state = GFX_ANIM_STATE_PAUSED;
            }
            else
            {
            }
         }
         if((((UINT8)p_param_flag) & GFX_ANIM_PLAY) == GFX_ANIM_PLAY)
         {
            if(fl_anim_flags_SAP->state == GFX_ANIM_STATE_STOPPED)
            {
               if(GFX_ANIM_IS_DIR_FWD(((UINT8)p_param_flag)))
               {
                  /*
                  ** A stopped animation is started from the first
                  ** frame for forward direction PLAY.
                  */
                  fl_anim_flags_SAP->dir    = GFX_ANIM_DIR_FORWARD;
                  *fl_anim_frame_U8AP       = (UINT8)0;
                  *fl_anim_telapsed_U32AP   = (UINT32)0;

               }
               else
               {
                  /*
                  ** A stopped animation is started from the last
                  ** frame for backward direction PLAY.
                  ** For backward direction fl_anim_telapsed_U32AP
                  ** represents the duration pending for the animation
                  */
				  UINT32 fl_num_frames = fl_anim_def_SP->num_frames;
				  fl_num_frames--;
                  fl_anim_flags_SAP->dir    = GFX_ANIM_DIR_BACKWORD;
                  *fl_anim_frame_U8AP       = (UINT8)(fl_num_frames);
                  fl_frames_SP = &fl_anim_def_SP->frames[*fl_anim_frame_U8AP];
                  *fl_anim_telapsed_U32AP   = fl_frames_SP->duration;
               }
               fl_anim_flags_SAP->state = GFX_ANIM_STATE_RUNNING;
               fl_anim_flags_SAP->start = (UINT8)1;
               *fl_anim_client_id_U16AP  = (UINT16)p_client_id;
            #if GFX_ANIM_GOTO_COUNT_ARRAY_SIZE > 0
               fl_anim_flags_SAP->goto_frame_cnt = (SINT8)(*fl_anim_frame_U8AP);
            #endif
            }
            else if(fl_anim_flags_SAP->state == GFX_ANIM_STATE_PAUSED)
            {
               /*
               ** Accept the run request for a paused animation only if the
               ** lsh id matches with what is stored and what is given rightnow.
               ** Also accept change of direction
               */
               if(*fl_anim_client_id_U16AP == (UINT16)p_client_id)
               {
                  fl_anim_flags_SAP->state = GFX_ANIM_STATE_RUNNING;
                  if(GFX_ANIM_IS_DIR_FWD(p_param_flag))
                  {
                     fl_anim_flags_SAP->dir = GFX_ANIM_DIR_FORWARD;
                  }
                  else
                  {
                     fl_anim_flags_SAP->dir = GFX_ANIM_DIR_BACKWORD;
                  }
               }
            }
            else
            {
                  /* MISRA Warning C-2012 Rule 15.7 Fix */
            }
         }
         fl_status = fl_anim_flags_SAP->state;
      }
   }
   return(fl_status);
}

/*============================================================================
** Function Name:    hmi_gfx_anim_engine
** Visibility:       global
** Description:      Performs execution of active animations
** Invocation:       By GDG03  
** Inputs/Outputs:   Derives animation commands and issues to GDG03
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
void hmi_gfx_anim_engine(void)
{
   UINT32             fl_end_frame;
   UINT32             fl_cur_anim_id;
   UINT32             fl_anim_timer_cur_U32 = l_anim_timer_cur_U32;
   UINT32             fl_timer_delta_U32;
   GFX_ANIM_CONTROL_T fl_anim_ctrl_S;
   GFX_ANIM_FLAGS_T * fl_flags_SAP;
   UINT32             fl_retry_count;

   if(l_anim_timer_pre_U32 != fl_anim_timer_cur_U32)
   {
      fl_anim_ctrl_S.timer_U32 = (fl_anim_timer_cur_U32-l_anim_timer_pre_U32);
      l_anim_timer_pre_U32     = fl_anim_timer_cur_U32;

      for(fl_cur_anim_id = (UINT32)0; fl_cur_anim_id < (UINT32)GFX_NUM_ANIMATIONS; fl_cur_anim_id++)
      {
         fl_retry_count = (UINT32)2;
         fl_flags_SAP   = &l_anim_flags_SA[fl_cur_anim_id];
          
         while((fl_flags_SAP->state == GFX_ANIM_STATE_RUNNING) && (fl_retry_count > (UINT32)0))
         {
            UINT32 fl_frame_U32 = (UINT32)(l_anim_frame_U8A[fl_cur_anim_id]);

            fl_anim_ctrl_S.def_sp     = &lc_animation_table_S[fl_cur_anim_id];
            if(fl_frame_U32 < fl_anim_ctrl_S.def_sp->num_frames)
            {
               fl_anim_ctrl_S.frames_sp = &fl_anim_ctrl_S.def_sp->frames[fl_frame_U32];
               fl_anim_ctrl_S.types_sp = fl_anim_ctrl_S.frames_sp->types.static_types;
               fl_anim_ctrl_S.anim_id = fl_cur_anim_id;
               fl_flags_SAP->end_reached = (UINT8)0;
               l_current_anim_id_U32 = fl_anim_ctrl_S.anim_id;

               if (fl_flags_SAP->start != (UINT32)0)
               {
                  /*
                  ** If the start flag is set then force time as 0  to make sure
                  ** we execute the first step of the frame.
                  */
                  fl_timer_delta_U32 = (UINT32)0;
                  fl_flags_SAP->start = (UINT8)0;
                  if (fl_flags_SAP->dir == GFX_ANIM_DIR_BACKWORD)
                  {
                     UINT32 fl_num_frames = fl_anim_ctrl_S.def_sp->num_frames;
                     fl_num_frames--;
                     l_anim_time_elapsed_U32A[fl_cur_anim_id] = fl_anim_ctrl_S.frames_sp->duration;
                     fl_end_frame = (UINT32)(fl_num_frames);
                     if (l_anim_frame_U8A[fl_cur_anim_id] == fl_end_frame)
                     {
                        HMI_GFX_ANIM_SET_CLIENT(l_anim_client_id_U16A[fl_cur_anim_id]);
                        if (fl_anim_ctrl_S.def_sp->cb != GFX_ANIM02_NULL_PTR)
                        {
                          #if defined (GFX_ANIM_APP_CB_WITH_ANIM_ID)
                          fl_anim_ctrl_S.def_sp->cb(fl_end_frame, fl_anim_ctrl_S.def_sp->num_frames, fl_cur_anim_id);
                          #else
                          fl_anim_ctrl_S.def_sp->cb(fl_end_frame, fl_anim_ctrl_S.def_sp->num_frames);
                          #endif
                        }
                     }
                  }
                  else
                  {
                     l_anim_time_elapsed_U32A[fl_cur_anim_id] = (UINT32)0;
                     if (l_anim_frame_U8A[fl_cur_anim_id] == (UINT8)0)
                     {
                        HMI_GFX_ANIM_SET_CLIENT(l_anim_client_id_U16A[fl_cur_anim_id]);
                        if (fl_anim_ctrl_S.def_sp->cb != GFX_ANIM02_NULL_PTR)
                        {
                          #if defined (GFX_ANIM_APP_CB_WITH_ANIM_ID)
                          fl_anim_ctrl_S.def_sp->cb((UINT32)0, fl_anim_ctrl_S.def_sp->num_frames, fl_cur_anim_id);
                          #else
                          fl_anim_ctrl_S.def_sp->cb((UINT32)0, fl_anim_ctrl_S.def_sp->num_frames);
                          #endif
                        }
                     }
                  }
               }
               else
               {
                  /*
                  ** Animation already started, so pass the actual timer
                  ** values.
                  */
                  fl_timer_delta_U32 = fl_anim_ctrl_S.timer_U32;
               }

               if (fl_frame_U32 < (UINT32)(fl_anim_ctrl_S.def_sp->num_frames))
               {
                  fl_anim_ctrl_S.prev_elap_time_U32 = l_anim_time_elapsed_U32A[fl_cur_anim_id];
                  if (fl_flags_SAP->dir == GFX_ANIM_DIR_BACKWORD)
                  {
                     /*
                     ** For backward direction the timer is counted downwards.
                     */
                     if (l_anim_time_elapsed_U32A[fl_cur_anim_id] > fl_timer_delta_U32)
                     {
                        l_anim_time_elapsed_U32A[fl_cur_anim_id] -= fl_timer_delta_U32;
                     }
                     else
                     {
                        /*
                        ** Reached the begining (End of backward animation)
                        ** Clamp the elapsed time and set start bit to 1 so that the
                        ** next frame starts from 0 time.
                        */
                        l_anim_time_elapsed_U32A[fl_cur_anim_id] = (UINT32)0;
                        fl_flags_SAP->end_reached = (UINT8)1;
                     }
                  }
                  else
                  {
                     /*
                     ** For backward direction the timer is counted upwards.
                     */
                     l_anim_time_elapsed_U32A[fl_cur_anim_id] += fl_timer_delta_U32;
                     if (l_anim_time_elapsed_U32A[fl_cur_anim_id] > fl_anim_ctrl_S.frames_sp->duration)
                     {
                        /*
                        ** Reached the End (End of forward animation)
                        ** Clamp the elapsed time and set start bit to 1 so that the
                        ** next frame starts from 0 time.
                        */
                        l_anim_time_elapsed_U32A[fl_cur_anim_id] = fl_anim_ctrl_S.frames_sp->duration;
                        fl_flags_SAP->end_reached = (UINT8)1;
                     }
                  }
                  if (hmi_gfx_anim_engine_run(&fl_anim_ctrl_S) == FALSE)
                  {
                     /*
                     ** animation is not executed due to goto command, so give another try to run the
                     ** animation (else there will be delay of one frame for the animation to run)
                     */
                     fl_retry_count--;
                  }
                  else
                  {
                     fl_retry_count = (UINT32)0;
                  }
               }
               else
               {
                  fl_retry_count = (UINT32)0;
               }
            }
         }
      }
      for(fl_cur_anim_id = (UINT32)0; fl_cur_anim_id < (UINT32)GFX_NUM_ANIMATIONS; fl_cur_anim_id++)
      {
         fl_flags_SAP = &l_anim_flags_SA[fl_cur_anim_id];
         if(fl_flags_SAP->state == GFX_ANIM_STATE_RUNNING)
         {
            if((((UINT32)l_anim_frame_U8A[fl_cur_anim_id]) >= ((UINT32)lc_animation_table_S[fl_cur_anim_id].num_frames)) ||
               (l_anim_frame_U8A[fl_cur_anim_id] == (UINT8)GFX_ANIM_MAX_U8))
            {
               /*
               ** Frame number has gone ouside boundary.
               ** Stop the animation as the configuration is invalid
               ** or the animation has completed all frames.
               */
               hmi_gfx_anim_engine_stop(fl_cur_anim_id);
            }
         }
      }
   }
}

/*============================================================================
** Function Name:    hmi_gfx_anim_engine_fwd
** Visibility:       local
** Description:      Performs execution of animation in forward direction
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   Derives animation commands and issues to GDG03
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static BOOLEAN hmi_gfx_anim_engine_run(GFX_ANIM_CONTROL_T* p_anim_ctrl_SP)
{


  GFX_ANIM_HANDLER_CB const lc_anim_handler_FPA[ANIM_NUM_TYPES] =
  {
    hmi_gfx_anim_engine_alpha,     /* ANIM_TYPE_ALPHA     */
    hmi_gfx_anim_engine_area,      /* ANIM_TYPE_AREA      */
    hmi_gfx_anim_engine_wd_ht,     /* ANIM_TYPE_WD_HT     */
    hmi_gfx_anim_engine_color,     /* ANIM_TYPE_COLOR     */
    hmi_gfx_anim_engine_data,      /* ANIM_TYPE_DATA      */
    GFX_ANIM_NULL_HANDLER,         /* ANIM_TYPE_GO_TO     */
    hmi_gfx_anim_engine_mal,       /* ANIM_TYPE_MAL       */
    hmi_gfx_anim_engine_map,       /* ANIM_TYPE_MAP       */
    hmi_gfx_anim_engine_screen,    /* ANIM_TYPE_SCREEN    */
    GFX_ANIM_NULL_HANDLER,         /* ANIM_TYPE_SCROLL_UP */
    GFX_ANIM_NULL_HANDLER,         /* ANIM_TYPE_SCROLL_DN */
    #if defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_VGLITE)
    hmi_gfx_anim_engine_rotate,    /* ANIM_TYPE_ROTATE    */
    hmi_gfx_anim_engine_scale,     /* ANIM_TYPE_SCALE     */
    hmi_gfx_anim_engine_transform  /* ANIM_TYPE_TRANSFORM */
    #else
    GFX_ANIM_NULL_HANDLER,         /* ANIM_TYPE_ROTATE    */
    GFX_ANIM_NULL_HANDLER,         /* ANIM_TYPE_SCALE     */
    GFX_ANIM_NULL_HANDLER,         /* ANIM_TYPE_TRANSFORM */
    #endif
  };
#define GFX_ANIM_HANDLER_TABLE_ENTRIES (UINT8)((sizeof(lc_anim_handler_FPA))/(sizeof(GFX_ANIM_HANDLER_CB)))

  BOOLEAN fl_animation_sts = TRUE;
  UINT32 fl_anim_count;
  UINT32 fl_stime_U32;
  UINT32 fl_rate_U32;
  UINT32 fl_max_step;
  UINT32 fl_cur_step;
  UINT32 fl_pre_step;
  UINT32 fl_cur_anim_id = p_anim_ctrl_SP->anim_id;

  if (fl_cur_anim_id < (UINT32)GFX_NUM_ANIMATIONS)
  {

#if GFX_ANIM_GOTO_COUNT_ARRAY_SIZE > 0
    GFX_ANIM_FLAGS_T* fl_anim_flags_SAP = &l_anim_flags_SA[fl_cur_anim_id];
#endif
    UINT32 fl_type;
#ifdef GFX_DYN_DATA_ANIMATIONS
    /*
    ** This flag is added to see if all animations in a frame is completed.
    ** If all frames are completed and all the animations are dynamic
    ** MAL animations then this flag will result in immediately
    ** stoping the frame.
    */
    UINT32 fl_all_anim_done = (UINT32)TRUE;
#endif

    fl_anim_count = p_anim_ctrl_SP->frames_sp->num_types;

    if (fl_anim_count == (UINT32)0)
    {
      /*
      ** There are no animations in this frame. So move to next frame.
      */
      hmi_gfx_anim_engine_next_frame((GFX_ANIM_CONTROL_T const*)p_anim_ctrl_SP);
    }
    else
    {
      while (fl_anim_count > (UINT32)0)
      {
        fl_type = p_anim_ctrl_SP->types_sp->type;
#if GFX_ANIM_GOTO_COUNT_ARRAY_SIZE > 0
        if (fl_type == (UINT32)ANIM_TYPE_GO_TO)
        {
          /*
          ** When a goto element is reached we need to break the loop after
          ** executing it.
          */
          fl_anim_count = (UINT32)0;
          if (p_anim_ctrl_SP->types_sp->val.go_to == GFX_ANIM02_NULL_PTR)
          {
            /*
            ** If a condition check function is set by user, then the return value of user_goto
            ** function is set directly as the next frame.\
            */
            if (p_anim_ctrl_SP->types_sp->handler.user_goto == GFX_ANIM02_NULL_PTR)
            {
              /*
              ** Error condition, handler cannot be NULL.
              */
              hmi_gfx_anim_engine_stop(fl_cur_anim_id);
            }
            else
            {
              hmi_gfx_anim_engine_set_frame(p_anim_ctrl_SP, p_anim_ctrl_SP->types_sp->handler.user_goto(l_anim_frame_U8A[fl_cur_anim_id]));
            }
          }
          else if (p_anim_ctrl_SP->types_sp->handler.goto_count != GFX_ANIM_NULL_HANDLER)
          {
            /*
            ** We have to reset the goto count variable only for the first run of the
            ** animation. We do this by using the goto_frame_cnt variable.
            ** this one increments or decrements only for the first run based
            ** the direction of animation.
            */
            if (fl_anim_flags_SAP->dir == GFX_ANIM_DIR_FORWARD)
            {
              /*
              ** goto_frame_cnt is declared as SINT8 type to put the limitation of maximum 127.
              ** So typecasting to UINT8 will not cause any issue. This is done to fix MISRA
              ** warning
              */
              if ((UINT8)(fl_anim_flags_SAP->goto_frame_cnt) <= l_anim_frame_U8A[fl_cur_anim_id])
              {
                (*p_anim_ctrl_SP->types_sp->handler.goto_count) = 0;
                fl_anim_flags_SAP->goto_frame_cnt = (SINT8)(l_anim_frame_U8A[fl_cur_anim_id]);
                fl_anim_flags_SAP->goto_frame_cnt++;
              }
            }
            else
            {
              /*
              ** goto_frame_cnt is declared as SINT8 type to put the limitation of maximum 127.
              ** So typecasting to UINT8 will not cause any issue. This is done to fix MISRA
              ** warning
              */
              if ((UINT8)fl_anim_flags_SAP->goto_frame_cnt >= l_anim_frame_U8A[fl_cur_anim_id])
              {
                /*
                ** Frame just started so reset the goto counter
                */
                (*p_anim_ctrl_SP->types_sp->handler.goto_count) = 0;
                fl_anim_flags_SAP->goto_frame_cnt = (SINT8)(l_anim_frame_U8A[fl_cur_anim_id]);
                fl_anim_flags_SAP->goto_frame_cnt--;
              }
            }
            /*
            ** Increment goto_count. As long as the count is within the threshold
            ** frame is set to the configured frame.
            ** Once it reaches set threshold next frame is activated.
            */
            (*p_anim_ctrl_SP->types_sp->handler.goto_count)++;
            if (*p_anim_ctrl_SP->types_sp->handler.goto_count != 0U)
            {
              if (*p_anim_ctrl_SP->types_sp->handler.goto_count <= p_anim_ctrl_SP->types_sp->val.go_to->repeat_cnt)
              {
                hmi_gfx_anim_engine_set_frame(p_anim_ctrl_SP, p_anim_ctrl_SP->types_sp->val.go_to->goto_frame);
              }
              else
              {
                hmi_gfx_anim_engine_next_frame(p_anim_ctrl_SP);
              }
            }
            else
            {
              /*
              ** Error condition, overflow happened so stop the animation
              ** otherwise it may run indefinitely.
              */
              hmi_gfx_anim_engine_stop(fl_cur_anim_id);
            }
          }
          else
          {
            /*
            ** Error condition, goto count variable pointer cannot be NULL.
            */
            hmi_gfx_anim_engine_stop(fl_cur_anim_id);
          }
          if (fl_anim_flags_SAP->state != GFX_ANIM_STATE_STOPPED)
          {
            if (l_anim_frame_U8A[fl_cur_anim_id] < lc_animation_table_S[fl_cur_anim_id].num_frames)
            {
              /*
              ** goto frame executed and there are still frames to execute
              */
              fl_animation_sts = FALSE;
#ifdef GFX_DYN_DATA_ANIMATIONS
              fl_all_anim_done = (UINT32)FALSE;
#endif
            }
          }
        }
        else
#else
        if (fl_type != (UINT32)ANIM_TYPE_GO_TO)
#endif
        {
          fl_rate_U32 = p_anim_ctrl_SP->types_sp->rate;
          fl_stime_U32 = p_anim_ctrl_SP->types_sp->start_time;

          if ((l_anim_time_elapsed_U32A[fl_cur_anim_id] >= fl_stime_U32) && (fl_rate_U32 > (UINT32)0))
          {
            UINT32 fl_cur_incr_percetage;
            UINT32 fl_pre_incr_percetage;
            UINT32 fl_anim_duration = p_anim_ctrl_SP->types_sp->duration;
#ifdef GFX_DYN_DATA_ANIMATIONS
            if (p_anim_ctrl_SP->types_sp->dynamic_data != (UINT8)0)
            {
              /*
              ** For dynamic data animations, the duration needs to be dynamically calculated
              ** as well.
              ** The default configurations tell us duration for a certain range and
              ** depending on the current range we have to interpolate to find the
              ** duration
              */
              fl_anim_duration = hmi_gfx_anim_engine_calculate_dduration(p_anim_ctrl_SP, fl_anim_duration);
            }
#endif   
            if (fl_anim_duration > (UINT32)0)
            {
              /*
              ** Making sure the duration is atleast >= 1tick to have proper
              ** start and end for the animation.
              ** Otherwise if the duration is  < rate mSec, the current and
              ** previous percentage will evaluate to 100% in the first execution
              ** itself and there will not be any animation happening.
              */
              UINT32 fl_temp_U32 = (UINT32)9;
              fl_rate_U32 = (UINT32)((fl_rate_U32 + fl_temp_U32) / 10UL);
              if (fl_anim_duration < fl_rate_U32)
              {
                fl_anim_duration = fl_rate_U32;
              }
              /*
              ** Find the current incremant percentage
              */
              fl_stime_U32 = (l_anim_time_elapsed_U32A[fl_cur_anim_id] - fl_stime_U32);
              if (fl_stime_U32 > fl_anim_duration)
              {
                fl_stime_U32 = fl_anim_duration;
              }

              fl_max_step = (UINT32)((fl_anim_duration * 10u) / p_anim_ctrl_SP->types_sp->rate);
              fl_cur_step = (UINT32)((fl_stime_U32 * 10u) / p_anim_ctrl_SP->types_sp->rate);

              if (fl_cur_step == fl_max_step)
              {
                fl_cur_incr_percetage = 1000u;
              }
              else
              {
                fl_cur_incr_percetage = p_anim_ctrl_SP->types_sp->handler.user_ip(fl_cur_step, fl_max_step);
              }
              /*
              ** Find the previous incremant percentage for
              ** calculating delta movement incase of XY and WH
              */
              fl_stime_U32 = p_anim_ctrl_SP->types_sp->start_time;
              if (p_anim_ctrl_SP->prev_elap_time_U32 > fl_stime_U32)
              {
                fl_stime_U32 = (p_anim_ctrl_SP->prev_elap_time_U32 - fl_stime_U32);
              }
              else
              {
                fl_stime_U32 = (UINT32)0;
              }

              if (fl_stime_U32 > fl_anim_duration)
              {
                fl_stime_U32 = fl_anim_duration;
              }

              fl_pre_step = (UINT32)((fl_stime_U32 * 10u) / p_anim_ctrl_SP->types_sp->rate);

              if (fl_pre_step == fl_max_step)
              {
                fl_pre_incr_percetage = 1000u;
              }
              else
              {
                fl_pre_incr_percetage = p_anim_ctrl_SP->types_sp->handler.user_ip(fl_pre_step, fl_max_step);
              }
            }
            else if (l_anim_time_elapsed_U32A[fl_cur_anim_id] == fl_stime_U32)
            {
              fl_pre_incr_percetage = (UINT32)0;
              fl_cur_incr_percetage = 1000u;
            }
            else
            {
              fl_pre_incr_percetage = 1000u;
              fl_cur_incr_percetage = 1000u;
            }
#ifdef GFX_ANIM_DEBUG
            GFX_ANIM_DEBUG_PRINT("ElapsedTime : %d, Current Percentage : %d\n", l_anim_time_elapsed_U32A[fl_cur_anim_id], fl_cur_incr_percetage);
#endif

            /*
            ** Call the handler of the animation type to handle the animation
            */
            if (fl_type < (UINT32)GFX_ANIM_HANDLER_TABLE_ENTRIES)
            {
              GFX_ANIM_HANDLER_CB const fl_anim_handler_CBP = lc_anim_handler_FPA[fl_type];
              if (fl_anim_handler_CBP != GFX_ANIM_NULL_HANDLER)
              {
                fl_anim_handler_CBP(p_anim_ctrl_SP->types_sp, fl_cur_incr_percetage, fl_pre_incr_percetage);
              }
              else
              {
                HMI_UNUSED_VAR(fl_pre_incr_percetage);
              }
            }
#ifdef GFX_DYN_DATA_ANIMATIONS
            if (p_anim_ctrl_SP->types_sp->dynamic_data != 0u)
            {
              /*
              ** For dynamic animations, if the current and previous % reaches
              ** to 100% we stop saying anim_done=FALSE there by causing
              ** a stop and moving to next frame.
              */
              if ((fl_pre_incr_percetage != 1000u) || (fl_cur_incr_percetage != 1000u))
              {
                fl_all_anim_done = (UINT32)FALSE;
              }
            }
            else
            {
              /*
              ** For non dynamic data type, we will not say anim is done at all.
              ** It has to take normal path of finishing up the configured duration
              ** and then take a natural end
              */
              fl_all_anim_done = (UINT32)FALSE;
            }
#endif
            HMI_UNUSED_VAR(fl_pre_incr_percetage);
          }
          else
          {
#ifdef GFX_DYN_DATA_ANIMATIONS
            if (fl_rate_U32 > 0u)
            {
              fl_all_anim_done = (UINT32)FALSE;
            }
#endif
          }
          p_anim_ctrl_SP->types_sp++;
          fl_anim_count--;
        }
      }
      if (
        (l_anim_flags_SA[fl_cur_anim_id].end_reached != (UINT32)0)
#ifdef GFX_DYN_DATA_ANIMATIONS
        || (fl_all_anim_done != (UINT32)FALSE)
#endif
        )
      {
        /*
        ** If we reached end of frame then move to next frame.
        ** Next cycle will begin the next frame
        */
        hmi_gfx_anim_engine_next_frame((GFX_ANIM_CONTROL_T const*)p_anim_ctrl_SP);
      }
    }
  }
  return(fl_animation_sts);
}

/*============================================================================
** Function Name:    hmi_gfx_anim_engine_stop
** Visibility:       local
** Description:      Stops the animation
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   Notifies the application of completion
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static void hmi_gfx_anim_engine_stop(UINT32 p_anim_id)
{  if(p_anim_id< (UINT32)GFX_NUM_ANIMATIONS)
   {
     GFX_ANIM_FLAGS_T * fl_flags_SAP   = &l_anim_flags_SA[p_anim_id];

     if((fl_flags_SAP->state == GFX_ANIM_STATE_RUNNING) ||
        (fl_flags_SAP->state == GFX_ANIM_STATE_PAUSED))
     {
        fl_flags_SAP->state       = GFX_ANIM_STATE_STOPPED;
        fl_flags_SAP->end_reached = (UINT8)0;
        fl_flags_SAP->start       = (UINT8)0;
        HMI_GFX_ANIM_ENGINE_DONE_CB((UINT8)p_anim_id,(UINT32)l_anim_client_id_U16A[p_anim_id]);
     }
   }
}

/*============================================================================
** Function Name:    hmi_gfx_anim_engine_next_frame
** Visibility:       local
** Description:      Moves to the next frame
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static void hmi_gfx_anim_engine_next_frame(GFX_ANIM_CONTROL_T const * p_anim_ctrl_SP)
{
   UINT32             fl_cur_anim_id = p_anim_ctrl_SP->anim_id;
   if(fl_cur_anim_id<(UINT32)GFX_NUM_ANIMATIONS)
   {  
       GFX_ANIM_FLAGS_T * fl_flags_SAP   = &l_anim_flags_SA[fl_cur_anim_id];

       if(fl_flags_SAP->dir == GFX_ANIM_DIR_BACKWORD)
       {
          if(l_anim_frame_U8A[fl_cur_anim_id] == 0U)
          {
              l_anim_frame_U8A[fl_cur_anim_id] = (UINT8)(p_anim_ctrl_SP->def_sp->num_frames);
          }
          else
          {
             l_anim_frame_U8A[fl_cur_anim_id]--;
          }
       }
       else if(l_anim_frame_U8A[fl_cur_anim_id] < GFX_ANIM_MAX_U8)
       {
          l_anim_frame_U8A[fl_cur_anim_id]++;
       }
       else
       {
        /* MISRA Warning C-2012 Rule 15.7 Fix */
       }
       if(p_anim_ctrl_SP->def_sp->cb != GFX_ANIM02_NULL_PTR)
       {
          #if defined (GFX_ANIM_APP_CB_WITH_ANIM_ID)
          p_anim_ctrl_SP->def_sp->cb((UINT32)l_anim_frame_U8A[fl_cur_anim_id], p_anim_ctrl_SP->def_sp->num_frames, fl_cur_anim_id);
          #else
          p_anim_ctrl_SP->def_sp->cb((UINT32)l_anim_frame_U8A[fl_cur_anim_id], p_anim_ctrl_SP->def_sp->num_frames);
          #endif      
       }
       fl_flags_SAP->start       = (UINT8)1;
       fl_flags_SAP->end_reached = (UINT8)0;
   }
}

#if GFX_ANIM_GOTO_COUNT_ARRAY_SIZE > 0
/*============================================================================
** Function Name:    hmi_gfx_anim_engine_set_frame
** Visibility:       local
** Description:      Sets the frame to passed one
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   Derives animation commands and issues to GDG03
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static void hmi_gfx_anim_engine_set_frame(GFX_ANIM_CONTROL_T const * p_anim_ctrl_SP, UINT32 p_frame)
{
    UINT32 fl_cur_anim_id = p_anim_ctrl_SP->anim_id;
    if(fl_cur_anim_id < (UINT32)GFX_NUM_ANIMATIONS)
    {
       GFX_ANIM_FLAGS_T *fl_flags_SAP = &l_anim_flags_SA[fl_cur_anim_id];

       l_anim_frame_U8A[fl_cur_anim_id] = (UINT8)p_frame;
       fl_flags_SAP->start = 1;
       fl_flags_SAP->end_reached = 0;
    }
}
#endif

#if defined GFX_NUM_LINEAR_ANIMATIONS
/*============================================================================
** Function Name:    hmi_gfx_anim_engine_linear_interpolate
** Visibility:       global
** Description:      Performas a linear interpolation to find the current %
**                   of animation step  
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   In  - Current Step and Maximum Step
**                   Out - Calculated Percentage out in 0.1 resolution
**                         0 to 1000 integer value for 0.0 to 100.0% 
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static UINT32 hmi_gfx_anim_engine_linear_interpolate(UINT32 p_cur_step, UINT32 p_max_step)
{
   UINT32 fl_percentage = ((p_cur_step * ((UINT32)1000))/p_max_step);
   return(fl_percentage);
}
#endif

#if defined GFX_NON_LINEAR_INTERPOLATIONS
/*============================================================================
** Function Name:    hmi_gfx_anim_engine_table_interpolate
** Visibility:       global
** Description:      Performas a table based interpolation to find the current %
**                   of animation step. Depending on the table the output will  
**                   be non-linear w.r.t input percentage
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   In  - Table pointer, Maximum index possible for the table
**                         Table scale factor (10000 / p_table_max_index)
**                         input percentage value
**                   Out - Calculated Percentage out in 0.1 resolution
**                         0 to 1000 integer value for 0.0 to 100.0% 
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static UINT32 hmi_gfx_anim_engine_table_interpolate(UINT16 const * p_table_U16AP, 
                                                    UINT32         p_table_max_index, 
                                                    UINT32         p_table_scale_factor, 
                                                    UINT32         p_percentage_in)
{
   UINT32 fl_startindex   = (p_percentage_in*100UL)/p_table_scale_factor;
   UINT32 fl_endindex;
   UINT32 fl_error;

   fl_error      = (fl_startindex % 10UL);
   fl_endindex   = ((fl_startindex + 5UL)/10UL);
   fl_startindex = ((fl_startindex)/10UL);

   fl_startindex = GFX_ANIM_UCLAMP(fl_startindex, p_table_max_index);
   fl_startindex = (UINT32)p_table_U16AP[fl_startindex];

   if(fl_error != 0UL)
   {
      /* Interpolate */
      fl_endindex    = GFX_ANIM_UCLAMP(fl_endindex, p_table_max_index);
      fl_endindex    = (UINT32)p_table_U16AP[fl_endindex];
      fl_startindex += (((fl_endindex-fl_startindex)*fl_error)/10UL);
   }
   return(fl_startindex);
}
#endif

#if defined GFX_NUM_EXPONENTIAL_ANIMATIONS 
/*============================================================================
** Function Name:    hmi_gfx_anim_engine_exponential_interpolate
** Visibility:       global
** Description:      Performas a exponential interpolation to find the current %
**                   of animation step which maps 0-100% 
**                    
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   In  - Current Step and Maximum Step
**                   Out - Calculated Percentage out in 0.1 resolution
**                         0 to 1000 integer value for 0.0 to 100.0% 
** Critical Section: None.
** Created:          13-May-2019 by KKUBENDI
** Updated:          13-May-2019 by KKUBENDI
**==========================================================================*/
static UINT32 hmi_gfx_anim_engine_exponential_interpolate(UINT32 p_cur_step, UINT32 p_max_step)
{
   UINT32 fl_percentage = ((p_cur_step * ((UINT32)1000))/p_max_step);   
   fl_percentage = hmi_gfx_anim_engine_table_interpolate(lc_anim_exponential_table,
                                                         (GFX_ANIM_EXPONENTIAL_TABLE_NUM_ENTRIES-1u),
                                                         GFX_ANIM_TABLE_SCALE_FACTOR(GFX_ANIM_EXPONENTIAL_TABLE_NUM_ENTRIES - 1u),
                                                         fl_percentage);
   return(fl_percentage);
}
#endif

#if defined GFX_NUM_SINE_UP_ANIMATIONS 
/*============================================================================
** Function Name:    hmi_gfx_anim_engine_sine_up_interpolate
** Visibility:       global
** Description:      Performas a sine interpolation to find the current %
**                   of animation step which maps 0-100% to a 0-90Deg sine
**                   movement.   
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   In  - Current Step and Maximum Step
**                   Out - Calculated Percentage out in 0.1 resolution
**                         0 to 1000 integer value for 0.0 to 100.0% 
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static UINT32 hmi_gfx_anim_engine_sine_up_interpolate(UINT32 p_cur_step, UINT32 p_max_step)
{
   UINT32 fl_percentage = ((p_cur_step * ((UINT32)1000))/p_max_step);   
   fl_percentage = hmi_gfx_anim_engine_table_interpolate(lc_anim_sineup_table, 
                                                         (GFX_ANIM_UP_DN_TABLE_NUM_ENTRIES-1u),
                                                         GFX_ANIM_TABLE_SCALE_FACTOR(GFX_ANIM_UP_DN_TABLE_NUM_ENTRIES-1u),
                                                         fl_percentage);
   return(fl_percentage);
}
#endif


#if defined GFX_NUM_SINE_DOWN_ANIMATIONS
/*============================================================================
** Function Name:    hmi_gfx_anim_engine_sine_down_interpolate
** Visibility:       global
** Description:      Performas a sine interpolation to find the current %
**                   of animation step which maps 0-100% to a 90-0Deg sine
**                   movement.   
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   In  - Current Step and Maximum Step
**                   Out - Calculated Percentage out in 0.1 resolution
**                         0 to 1000 integer value for 0.0 to 100.0% 
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static UINT32 hmi_gfx_anim_engine_sine_down_interpolate(UINT32 p_cur_step, UINT32 p_max_step)
{
   UINT32 fl_percentage = ((p_cur_step * ((UINT32)1000))/p_max_step);
   
   fl_percentage = hmi_gfx_anim_engine_table_interpolate(lc_anim_sinedn_table, 
                                                         (GFX_ANIM_UP_DN_TABLE_NUM_ENTRIES-1u),
                                                         GFX_ANIM_TABLE_SCALE_FACTOR(GFX_ANIM_UP_DN_TABLE_NUM_ENTRIES-1u),
                                                         fl_percentage);
   return(fl_percentage);
}
#endif

#if defined GFX_NUM_SINE_UPDOWN_ANIMATIONS
/*============================================================================
** Function Name:    hmi_gfx_anim_engine_sine_updown_interpolate
** Visibility:       global
** Description:      Performas a sine interpolation to find the current %
**                   of animation step which maps 0-100% to a 0-180Deg sine
**                   movement.   
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   In  - Current Step and Maximum Step
**                   Out - Calculated Percentage out in 0.1 resolution
**                         0 to 1000 integer value for 0.0 to 100.0% 
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static UINT32 hmi_gfx_anim_engine_sine_updown_interpolate(UINT32 p_cur_step, UINT32 p_max_step)
{
   UINT32 fl_percentage = ((p_cur_step * 1000UL)/p_max_step);
   
   fl_percentage = hmi_gfx_anim_engine_table_interpolate(lc_anim_sineupdn_table, 
                                                         (GFX_ANIM_UPDN_DNUP_TABLE_NUM_ENTRIES-1u),
                                                         GFX_ANIM_TABLE_SCALE_FACTOR(GFX_ANIM_UPDN_DNUP_TABLE_NUM_ENTRIES-1u),
                                                         fl_percentage);
   return(fl_percentage);
}
#endif

#if defined GFX_NUM_SINE_DOWNUP_ANIMATIONS
/*============================================================================
** Function Name:    hmi_gfx_anim_engine_sine_downup_interpolate
** Visibility:       global
** Description:      Performas a sine interpolation to find the current %
**                   of animation step which maps 0-100% to a 180-0Deg sine
**                   movement.   
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   In  - Current Step and Maximum Step
**                   Out - Calculated Percentage out in 0.1 resolution
**                         0 to 1000 integer value for 0.0 to 100.0% 
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static UINT32 hmi_gfx_anim_engine_sine_downup_interpolate(UINT32 p_cur_step, UINT32 p_max_step)
{
   UINT32 fl_percentage = ((p_cur_step * ((UINT32)1000))/p_max_step);
   
   fl_percentage = hmi_gfx_anim_engine_table_interpolate(lc_anim_sinednup_table, 
                                                         (GFX_ANIM_UPDN_DNUP_TABLE_NUM_ENTRIES-1u),
                                                         GFX_ANIM_TABLE_SCALE_FACTOR(GFX_ANIM_UPDN_DNUP_TABLE_NUM_ENTRIES-1u),
                                                         fl_percentage);
   return(fl_percentage);
}
#endif

#if defined GFX_NUM_LOG_UP_ANIMATIONS
/*============================================================================
** Function Name:    hmi_gfx_anim_engine_log_up_interpolate
** Visibility:       global
** Description:      Performas a logerithimic interpolation to find the current %
**                   of animation step in upward direction (Slow start and fast end).
**                   movement.   
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   In  - Current Step and Maximum Step
**                   Out - Calculated Percentage out in 0.1 resolution
**                         0 to 1000 integer value for 0.0 to 100.0% 
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static UINT32 hmi_gfx_anim_engine_log_up_interpolate(UINT32 p_cur_step, UINT32 p_max_step)
{
   UINT32 fl_percentage = ((p_cur_step * 1000)/p_max_step);
   
   fl_percentage = hmi_gfx_anim_engine_table_interpolate(lc_anim_logup_table, 
                                                         (GFX_ANIM_UP_DN_TABLE_NUM_ENTRIES-1u),
                                                         GFX_ANIM_TABLE_SCALE_FACTOR(GFX_ANIM_UP_DN_TABLE_NUM_ENTRIES-1u),
                                                         fl_percentage);
   return(fl_percentage);
}
#endif

#if defined GFX_NUM_LOG_DOWN_ANIMATIONS
/*============================================================================
** Function Name:    hmi_gfx_anim_engine_log_down_interpolate
** Visibility:       global
** Description:      Performas a logerithimic interpolation to find the current %
**                   of animation step in upward direction (fast start and slow end).
**                   movement.   
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   In  - Current Step and Maximum Step
**                   Out - Calculated Percentage out in 0.1 resolution
**                         0 to 1000 integer value for 0.0 to 100.0% 
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static UINT32 hmi_gfx_anim_engine_log_down_interpolate(UINT32 p_cur_step, UINT32 p_max_step)
{
   UINT32 fl_percentage = ((p_cur_step * ((UINT32)1000))/p_max_step);
   
   fl_percentage = hmi_gfx_anim_engine_table_interpolate(lc_anim_logdn_table, 
                                                         (GFX_ANIM_UP_DN_TABLE_NUM_ENTRIES-1u),
                                                         GFX_ANIM_TABLE_SCALE_FACTOR(GFX_ANIM_UP_DN_TABLE_NUM_ENTRIES-1u),
                                                         fl_percentage);
   return(fl_percentage);
}
#endif

#if defined GFX_NUM_LOG_UPDOWN_ANIMATIONS
/*============================================================================
** Function Name:    hmi_gfx_anim_engine_log_updown_interpolate
** Visibility:       global
** Description:      Performas a logerithimic interpolation to find the current %
**                   of animation step in upward direction (Slow start, fast
**                   intermediate and slow end).
**                   movement.   
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   In  - Current Step and Maximum Step
**                   Out - Calculated Percentage out in 0.1 resolution
**                         0 to 1000 integer value for 0.0 to 100.0% 
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static UINT32 hmi_gfx_anim_engine_log_updown_interpolate(UINT32 p_cur_step, UINT32 p_max_step)
{
   UINT32 fl_percentage = ((p_cur_step * ((UINT32)1000))/p_max_step);
   
   fl_percentage = hmi_gfx_anim_engine_table_interpolate(lc_anim_logupdn_table, 
                                                         (GFX_ANIM_UPDN_DNUP_TABLE_NUM_ENTRIES-1u),
                                                         GFX_ANIM_TABLE_SCALE_FACTOR(GFX_ANIM_UPDN_DNUP_TABLE_NUM_ENTRIES-1u),
                                                         fl_percentage);
   return(fl_percentage);
}
#endif

#if defined GFX_NUM_LOG_DOWNUP_ANIMATIONS 
/*============================================================================
** Function Name:    hmi_gfx_anim_engine_log_downup_interpolate
** Visibility:       global
** Description:      Performas a logerithimic interpolation to find the current %
**                   of animation step in upward direction (Fast start, Slow
**                   intermediate and Fast end).
**                   movement.   
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   In  - Current Step and Maximum Step
**                   Out - Calculated Percentage out in 0.1 resolution
**                         0 to 1000 integer value for 0.0 to 100.0% 
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static UINT32 hmi_gfx_anim_engine_log_downup_interpolate(UINT32 p_cur_step, UINT32 p_max_step)
{
   UINT32 fl_percentage = ((p_cur_step * ((UINT32)1000))/p_max_step);
   
   fl_percentage = hmi_gfx_anim_engine_table_interpolate(lc_anim_logdnup_table, 
                                                         (GFX_ANIM_UPDN_DNUP_TABLE_NUM_ENTRIES-1u),
                                                         GFX_ANIM_TABLE_SCALE_FACTOR(GFX_ANIM_UPDN_DNUP_TABLE_NUM_ENTRIES-1u),
                                                         fl_percentage);
   return(fl_percentage);
}
#endif

/*============================================================================
** Function Name:    hmi_gfx_anim_engine_find_idelta
** Visibility:       global
** Description:      Calculates the delta corresponding to the percentage for
**                   int values  
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static SINT32 hmi_gfx_anim_engine_find_idelta(SINT32 p_start_val, SINT32 p_end_val, UINT32 p_percentage)
{
    return(((p_end_val-p_start_val)*((SINT32)p_percentage))/1000);
}
#if defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
/*============================================================================
** Function Name:    hmi_gfx_anim_engine_find_fdelta
** Visibility:       global
** Description:      Calculates the delta corresponding to the percentage for
**                   float values  
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static GFX_FLOAT hmi_gfx_anim_engine_find_fdelta(GFX_FLOAT p_start_val, GFX_FLOAT p_end_val, UINT32 p_percentage)
{
   GFX_FLOAT fl_end_val = p_end_val;
   fl_end_val -= p_start_val;
   fl_end_val *= (GFX_FLOAT)p_percentage;
   fl_end_val /= 1000.0f;
   return(fl_end_val);
}
#endif
/*============================================================================
** Function Name:    hmi_gfx_anim_engine_alpha
** Visibility:       global
** Description:      Calculates the alpha for the given current step percentage
**                   and applies to all elements in list. (p_pre_per is not used
**                   since alpha is calculated as direct data and not as an 
**                   offset.
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   In : Pointer to anim type data, current step percentage    and
**                   previous step percentage.  
**                   Out : Applies calculated alpha to all elements in list
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static void hmi_gfx_anim_engine_alpha(GFX_ANIM_TYPES_DEF_T const * p_tdata, UINT32 p_cur_per, UINT32 p_pre_per)
{
   GFX_ANIM_ALPHA_T const * fl_data; 
   SINT32                   fl_alpha;
   UINT32                   fl_num_elements   = p_tdata->num_elements;
   UINT32 const           * fl_elem_list_U32A = p_tdata->elem_list.static_elem_list;
   SINT32                   fl_data_start;

   if(p_tdata->dynamic_data != 0U)
   {
      fl_data = (GFX_ANIM_ALPHA_T const *)p_tdata->val.dyn_alpha->cur_val;
   }
   else
   {
      fl_data = (GFX_ANIM_ALPHA_T const *)p_tdata->val.alpha;
   }
   fl_alpha = hmi_gfx_anim_engine_find_idelta((SINT32)fl_data->start, (SINT32)fl_data->end, p_cur_per);   
   fl_data_start = (SINT32)fl_data->start;
   fl_alpha += fl_data_start;
   
   while(fl_num_elements > (UINT32)0)
   {
      fl_num_elements--;
      HMI_GFX_ANIM_SET_ALPHA(*fl_elem_list_U32A, (fl_alpha));
      fl_elem_list_U32A++;
   }
   HMI_UNUSED_VAR(p_pre_per);
}

/*============================================================================
** Function Name:    hmi_gfx_anim_engine_area
** Visibility:       global
** Description:      Calculates the area offset for the given step percentage
**                   and applies to all elements in list.
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   In : Pointer to anim type data, current step percentage    and
**                   previous step percentage.  
**                   Out : Applies calculated offset to all elements in list
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static void hmi_gfx_anim_engine_area(GFX_ANIM_TYPES_DEF_T const * p_tdata, UINT32 p_cur_per, UINT32 p_pre_per)
{
   GFX_ANIM_AREA_T const * fl_data;
   UINT32                  fl_num_elements   = p_tdata->num_elements;
   UINT32 const          * fl_elem_list_U32A = p_tdata->elem_list.static_elem_list;
   SINT32 fl_cur_x_incr; 
   SINT32 fl_cur_y_incr; 
   SINT32 fl_cur_w_incr; 
   SINT32 fl_cur_h_incr; 
   SINT32 fl_prev_x_incr;
   SINT32 fl_prev_y_incr;
   SINT32 fl_prev_w_incr;
   SINT32 fl_prev_h_incr;

   if(p_tdata->dynamic_data != 0U)
   {
      fl_data = (GFX_ANIM_AREA_T const *)p_tdata->val.dyn_area->cur_val;
   }
   else
   {
      fl_data = (GFX_ANIM_AREA_T const *)p_tdata->val.area;
   }
   /*
   ** Calculate current and previous values
   ** Apply the difference to elements in list
   */ 
   fl_cur_x_incr  = ((fl_data->end.x*(SINT32)p_cur_per)/1000);
   fl_cur_y_incr  = ((fl_data->end.y*(SINT32)p_cur_per)/1000);
   fl_cur_w_incr  = ((fl_data->end.w*(SINT32)p_cur_per)/1000);
   fl_cur_h_incr  = ((fl_data->end.h*(SINT32)p_cur_per)/1000);
   fl_prev_x_incr = ((fl_data->end.x*(SINT32)p_pre_per)/1000);
   fl_prev_y_incr = ((fl_data->end.y*(SINT32)p_pre_per)/1000);
   fl_prev_w_incr = ((fl_data->end.w*(SINT32)p_pre_per)/1000);
   fl_prev_h_incr = ((fl_data->end.h*(SINT32)p_pre_per)/1000);

   while(fl_num_elements > (UINT32)0)
   {
      fl_num_elements--;
      HMI_GFX_ANIM_SET_OFFSET_AREA(((GFX_MGR02_ANIM_ELEM_ID)(*fl_elem_list_U32A)), 
                                   (fl_cur_x_incr-fl_prev_x_incr),
                                   (fl_cur_y_incr-fl_prev_y_incr),
                                   (fl_cur_w_incr-fl_prev_w_incr),
                                   (fl_cur_h_incr-fl_prev_h_incr));
      fl_elem_list_U32A++;
   }
}

/*============================================================================
** Function Name:    hmi_gfx_anim_engine_wd_ht
** Visibility:       global
** Description:      Calculates the width/height offset for the given step percentage
**                   and applies to all elements in list.
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   In : Pointer to anim type data, current step percentage    and
**                   previous step percentage.  
**                   Out : Applies calculated offset to all elements in list
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static void hmi_gfx_anim_engine_wd_ht(GFX_ANIM_TYPES_DEF_T const * p_tdata, UINT32 p_cur_per, UINT32 p_pre_per)
{
   GFX_ANIM_WDHT_T const * fl_data           = (GFX_ANIM_WDHT_T const *)p_tdata->val.wd_ht;
   UINT32                  fl_num_elements   = p_tdata->num_elements;
   UINT32 const          * fl_elem_list_U32A = p_tdata->elem_list.static_elem_list;

   SINT32 fl_cur_w_incr  = ((fl_data->end.w*(SINT32)p_cur_per)/1000);
   SINT32 fl_cur_h_incr  = ((fl_data->end.h*(SINT32)p_cur_per)/1000);
   SINT32 fl_prev_w_incr = ((fl_data->end.w*(SINT32)p_pre_per)/1000);
   SINT32 fl_prev_h_incr = ((fl_data->end.h*(SINT32)p_pre_per)/1000);

   while(fl_num_elements > (UINT32)0)
   {
      fl_num_elements--;
      HMI_GFX_ANIM_SET_OFFSET_WH(((GFX_MGR02_ANIM_ELEM_ID)(*fl_elem_list_U32A)), 
                                 (fl_cur_w_incr-fl_prev_w_incr),
                                 (fl_cur_h_incr-fl_prev_h_incr));
      fl_elem_list_U32A++;
   }
}

/*============================================================================
** Function Name:    hmi_gfx_anim_engine_color
** Visibility:       global
** Description:      Calculates the Color for the given step percentage
**                   and applies to all elements in list.
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   In : Pointer to anim type data, current step percentage and
**                   previous step percentage.                              
**                   Out : Applies calculated color to all elements in list
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static void hmi_gfx_anim_engine_color(GFX_ANIM_TYPES_DEF_T const * p_tdata, UINT32 p_cur_per, UINT32 p_pre_per)
{
   GFX_ANIM_COLOR_T const * fl_data           = (GFX_ANIM_COLOR_T const *)p_tdata->val.color;
   UINT32                   fl_num_elements   = p_tdata->num_elements;
   UINT32 const           * fl_elem_list_U32A = p_tdata->elem_list.static_elem_list;

   SINT32 fl_a      = (SINT32)((UINT8)(fl_data->start.argb>>24));
   SINT32 fl_r      = (SINT32)((UINT8)(fl_data->start.argb>>16));
   SINT32 fl_g      = (SINT32)((UINT8)(fl_data->start.argb>>8));
   SINT32 fl_b      = (SINT32)((UINT8)(fl_data->start.argb));
   UINT32 fl_c_incr;

   fl_a += hmi_gfx_anim_engine_find_idelta(fl_a, (SINT32)((UINT8)(fl_data->end.argb>>24)), p_cur_per);
   fl_r += hmi_gfx_anim_engine_find_idelta(fl_r, (SINT32)((UINT8)(fl_data->end.argb>>16)), p_cur_per);
   fl_g += hmi_gfx_anim_engine_find_idelta(fl_g, (SINT32)((UINT8)(fl_data->end.argb>>8)),  p_cur_per);
   fl_b += hmi_gfx_anim_engine_find_idelta(fl_b, (SINT32)((UINT8)(fl_data->end.argb)),     p_cur_per);
   
   fl_c_incr = GFX_ANIM_ARGB(fl_a, fl_r, fl_g, fl_b);

   while(fl_num_elements > (UINT32)0)
   {
      fl_num_elements--;
      HMI_GFX_ANIM_SET_COLOR(*fl_elem_list_U32A, fl_c_incr);
      fl_elem_list_U32A++;
   }
   HMI_UNUSED_VAR(p_pre_per);
}

/*============================================================================
** Function Name:    hmi_gfx_anim_engine_data
** Visibility:       global
** Description:      Calculates the Data for the given step percentage
**                   and applies to all elements in list.
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   In : Pointer to anim type data, current step percentage and
**                   previous step percentage.                              
**                   Out : Applies calculated data to all elements in list
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static void hmi_gfx_anim_engine_data(GFX_ANIM_TYPES_DEF_T const * p_tdata, UINT32 p_cur_per, UINT32 p_pre_per)
{
    GFX_ANIM_DATA_T const * fl_data           = (GFX_ANIM_DATA_T const *)p_tdata->val.data;
    UINT32                  fl_num_elements   = p_tdata->num_elements;
    UINT32 const          * fl_elem_list_U32A = p_tdata->elem_list.static_elem_list;
    SINT32                  fl_data_val;
    
#if defined (GFX_ANIM_EQUAL_DISPLAY_TIME_TO_ALL_IMAGES)
    if (fl_data->end > fl_data->start)
    {
        fl_data_val = hmi_gfx_anim_engine_find_idelta((SINT32)fl_data->start, (SINT32)fl_data->end + 1, p_cur_per);
        
        /* When "p_cur_per" is 100%, computed value of "fl_data_val" will be outside of the configured range [start,end] */
        if (fl_data_val > ((SINT32)fl_data->end - (SINT32)fl_data->start))
        {
            fl_data_val = (SINT32)fl_data->end - (SINT32)fl_data->start;
        }
    }
    else if (fl_data->end < fl_data->start)
    {
        fl_data_val = hmi_gfx_anim_engine_find_idelta((SINT32)fl_data->start + 1, (SINT32)fl_data->end, p_cur_per);
        
        /* When "p_cur_per" is 100%, computed value of "fl_data_val" will be outside of the configured range [start,end] */
        if (fl_data_val < ((SINT32)fl_data->end - (SINT32)fl_data->start))
        {
            fl_data_val = (SINT32)fl_data->end - (SINT32)fl_data->start;
        }
    }
    else
#endif
    {
        fl_data_val = hmi_gfx_anim_engine_find_idelta((SINT32)fl_data->start, (SINT32)fl_data->end, p_cur_per);
    }
    
    fl_data_val += (SINT32)fl_data->start;

    while(fl_num_elements > (UINT32)0)
    {
       fl_num_elements--;
       HMI_GFX_ANIM_SET_DATA(*fl_elem_list_U32A, fl_data_val);
       fl_elem_list_U32A++;
    }
    HMI_UNUSED_VAR(p_pre_per);   
}

/*============================================================================
** Function Name:    hmi_gfx_anim_engine_mal
** Visibility:       global
** Description:      Calculates the x/y offset for the given step percentage
**                   and applies to all elements in list.
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   In : Pointer to anim type data, current step percentage    and
**                   previous step percentage.  
**                   Out : Applies calculated offset to all elements in list
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static void hmi_gfx_anim_engine_mal(GFX_ANIM_TYPES_DEF_T const * p_tdata, UINT32 p_cur_per, UINT32 p_pre_per)
{
   GFX_ANIM_MAL_T const * fl_data;
   UINT32                 fl_num_elements   = p_tdata->num_elements;
   UINT32 const         * fl_elem_list_U32A = p_tdata->elem_list.static_elem_list;
   SINT32 fl_cur_x_incr; 
   SINT32 fl_cur_y_incr; 
   SINT32 fl_prev_x_incr;
   SINT32 fl_prev_y_incr;

   if(p_tdata->dynamic_data != 0U)
   {
      fl_data = (GFX_ANIM_MAL_T const *)p_tdata->val.dyn_mal->cur_val;
   }
   else
   {
      fl_data = (GFX_ANIM_MAL_T const *)p_tdata->val.mal;
   }

   #if defined(GFX_ANIM_DLAYOUT_ENABLED)
		fl_data= &fl_data[l_selected_anim_layout_U8];
   #endif
   
   fl_cur_x_incr  = ((fl_data->end.x*(SINT32)p_cur_per)/1000);
   fl_cur_y_incr  = ((fl_data->end.y*(SINT32)p_cur_per)/1000);
   fl_prev_x_incr = ((fl_data->end.x*(SINT32)p_pre_per)/1000);
   fl_prev_y_incr = ((fl_data->end.y*(SINT32)p_pre_per)/1000);

   while(fl_num_elements > (UINT32)0)
   {
      fl_num_elements--;
      HMI_GFX_ANIM_SET_OFFSET_POS(((GFX_MGR02_ANIM_ELEM_ID)(*fl_elem_list_U32A)), 
                                  (fl_cur_x_incr-fl_prev_x_incr),
                                  (fl_cur_y_incr-fl_prev_y_incr));
      fl_elem_list_U32A++;
   }
}

/*============================================================================
** Function Name:    hmi_gfx_anim_engine_map
** Visibility:       global
** Description:      Calculates the x/y offset for the given step percentage
**                   and applies to all elements in list.
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   In : Pointer to anim type data, current step percentage    and
**                   previous step percentage.  
**                   Out : Applies calculated offset to all elements in list
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static void hmi_gfx_anim_engine_map(GFX_ANIM_TYPES_DEF_T const * p_tdata, UINT32 p_cur_per, UINT32 p_pre_per)
{
	GFX_ANIM_MAP_T const * fl_data           = (GFX_ANIM_MAP_T const *)p_tdata->val.map;
	UINT32                 fl_num_elements   = p_tdata->num_elements;
	UINT32 const         * fl_elem_list_U32A = p_tdata->elem_list.static_elem_list;
    UINT16 fl_num_points;
	SINT32 fl_cur_index;
	SINT32 fl_pre_index;
	SINT32 fl_delta_x;
	SINT32 fl_delta_y;
	/*
	** Calculate the current and previous point from the motion path data
	** Find the delta and apply to the element
	*/
   #if defined(GFX_ANIM_DLAYOUT_ENABLED)
		fl_data= &fl_data[l_selected_anim_layout_U8];
   #endif

	fl_cur_index = hmi_gfx_anim_engine_find_idelta(0, (SINT32)fl_data->num_points, p_cur_per);
	fl_pre_index = hmi_gfx_anim_engine_find_idelta(0, (SINT32)fl_data->num_points, p_pre_per);

	fl_num_points = fl_data->num_points;
	fl_num_points--;
	fl_cur_index = GFX_ANIM_UCLAMP(fl_cur_index, (SINT32)fl_num_points);
	fl_pre_index = GFX_ANIM_UCLAMP(fl_pre_index, (SINT32)fl_num_points);

	if(fl_cur_index != fl_pre_index)
	{
		fl_delta_x = ((SINT32)fl_data->points[fl_cur_index].x - (SINT32)fl_data->points[fl_pre_index].x);
		fl_delta_y = ((SINT32)fl_data->points[fl_cur_index].y - (SINT32)fl_data->points[fl_pre_index].y);
		while(fl_num_elements > (UINT32)0)
		{
			fl_num_elements--;
			HMI_GFX_ANIM_SET_OFFSET_POS(((GFX_MGR02_ANIM_ELEM_ID)(*fl_elem_list_U32A)), fl_delta_x, fl_delta_y);
			fl_elem_list_U32A++;
		}
	}
}

/*============================================================================
** Function Name:    hmi_gfx_anim_engine_screen
** Visibility:       global
** Description:      Calculates the screen index to be selected and activates it
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   In : Pointer to anim type data, current step percentage    and
**                   previous step percentage.  
**                   Out : Activates the current screen for the anim step.
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static void hmi_gfx_anim_engine_screen(GFX_ANIM_TYPES_DEF_T const * p_tdata, UINT32 p_cur_per, UINT32 p_pre_per)
{
   SINT32 fl_cur_index = hmi_gfx_anim_engine_find_idelta(0, (SINT32)p_tdata->num_elements, p_cur_per);
   UINT8  fl_num_elem   = p_tdata->num_elements;
   fl_num_elem--;   
   fl_cur_index = GFX_ANIM_UCLAMP(fl_cur_index,((SINT32)fl_num_elem));
   HMI_GFX_ANIM_SET_SCREEN(p_tdata->elem_list.static_elem_list[fl_cur_index]);
   HMI_UNUSED_VAR(p_pre_per);
}

#if defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
/*============================================================================
** Function Name:    hmi_gfx_anim_engine_rotate
** Visibility:       global
** Description:      Calculates the rotation angle for the given step percentage
**                   and applies to all elements in list.
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   In : Pointer to anim type data, current step percentage    and
**                   previous step percentage.  
**                   Out : Applies calculated factor to all elements in list
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
static void hmi_gfx_anim_engine_rotate(GFX_ANIM_TYPES_DEF_T const * p_tdata, UINT32 p_cur_per, UINT32 p_pre_per)
{
   GFX_ANIM_ROTATE_T const * fl_data = p_tdata->val.rotate;
   UINT32                    fl_num_elements   = p_tdata->num_elements;
   UINT32 const            * fl_elem_list_U32A = p_tdata->elem_list.static_elem_list;
   GFX_FLOAT fl_matrix_1[9];

   GFX_FLOAT fl_cur_angle  = hmi_gfx_anim_engine_find_fdelta((GFX_FLOAT)0, fl_data->angle, p_cur_per);
   GFX_FLOAT fl_prev_angle = hmi_gfx_anim_engine_find_fdelta((GFX_FLOAT)0, fl_data->angle, p_pre_per);

   fl_cur_angle -= fl_prev_angle;
   fl_cur_angle *= 3.141592654f;
   fl_cur_angle /=180.0f;

   fl_matrix_1[0] = cosf(fl_cur_angle);
   fl_matrix_1[1] = sinf(fl_cur_angle);
   fl_matrix_1[2] = (GFX_FLOAT)0;
   fl_matrix_1[3] = -fl_matrix_1[1];
   fl_matrix_1[4] = fl_matrix_1[0];
   fl_matrix_1[5] = (GFX_FLOAT)0;
   fl_matrix_1[6] = (GFX_FLOAT)0;
   fl_matrix_1[7] = (GFX_FLOAT)0;
   fl_matrix_1[8] = (GFX_FLOAT)1;

   while(fl_num_elements > (UINT32)0)
   {
      fl_num_elements--;
      HMI_GFX_ANIM_MUL_MATRIX(*fl_elem_list_U32A, fl_matrix_1);
      fl_elem_list_U32A++;
   }
}

/*============================================================================
** Function Name:    hmi_gfx_anim_engine_scale
** Visibility:       global
** Description:      Calculates the scale factor for the given step percentage
**                   and applies to all elements in list.
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   In : Pointer to anim type data, current step percentage    and
**                   previous step percentage.  
**                   Out : Applies calculated factor to all elements in list
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          10-Jul-2013 by EMANOJ1
**==========================================================================*/
static void hmi_gfx_anim_engine_scale(GFX_ANIM_TYPES_DEF_T const * p_tdata, UINT32 p_cur_per, UINT32 p_pre_per)
{
   GFX_ANIM_SCALE_T const * fl_data = p_tdata->val.scale;
   UINT32                   fl_num_elements   = p_tdata->num_elements;
   UINT32 const           * fl_elem_list_U32A = p_tdata->elem_list.static_elem_list;
   GFX_FLOAT         fl_matrix_1[9];
   GFX_FLOAT const * fl_cur_matrix; 
   GFX_FLOAT         fl_cur_scale_incr = hmi_gfx_anim_engine_find_fdelta((GFX_FLOAT)0, fl_data->scale, p_cur_per);
   GFX_FLOAT         fl_pre_scale_incr = hmi_gfx_anim_engine_find_fdelta((GFX_FLOAT)0, fl_data->scale, p_pre_per);

   fl_cur_scale_incr -= fl_pre_scale_incr;
   
   fl_matrix_1[0] = (1.0f + fl_cur_scale_incr);
   fl_matrix_1[1] = (GFX_FLOAT)0;
   fl_matrix_1[2] = (GFX_FLOAT)0;

   fl_matrix_1[3] = (GFX_FLOAT)0;
   fl_matrix_1[4] = fl_matrix_1[0];
   fl_matrix_1[5] = (GFX_FLOAT)0;

   fl_matrix_1[6] = (GFX_FLOAT)0;
   fl_matrix_1[7] = (GFX_FLOAT)0;
   fl_matrix_1[8] = (GFX_FLOAT)1;

   while(fl_num_elements > (UINT32)0)
   {
      fl_num_elements--;
      fl_cur_matrix = HMI_GFX_ANIM_GET_MATRIX(*fl_elem_list_U32A);
      if(fl_cur_matrix!= GFX_ANIM02_NULL_PTR)
      {
         /*
         ** Reset the matrix and then multiply with the scale transform
         */
         fl_matrix_1[0] = (fl_cur_matrix[0] + fl_cur_scale_incr);
         fl_matrix_1[1] = fl_cur_matrix[1];
         fl_matrix_1[2] = fl_cur_matrix[2];
         fl_matrix_1[3] = fl_cur_matrix[3];
         fl_matrix_1[4] = (fl_cur_matrix[4] + fl_cur_scale_incr);
         fl_matrix_1[5] = fl_cur_matrix[5];
         fl_matrix_1[6] = fl_cur_matrix[6];
         fl_matrix_1[7] = fl_cur_matrix[7];
         fl_matrix_1[8] = fl_cur_matrix[8];
         HMI_GFX_ANIM_SET_MATRIX(*fl_elem_list_U32A, fl_matrix_1);
      }
      fl_elem_list_U32A++;
   }
}

/*============================================================================
** Function Name:    hmi_gfx_anim_engine_transform
** Visibility:       global
** Description:      Calculates the transform factor for the given step percentage
**                   and applies to all elements in list.
** Invocation:       By hmi_gfx_anim_engine  
** Inputs/Outputs:   In : Pointer to anim type data, current step percentage    and
**                   previous step percentage.  
**                   Out : Applies calculated factor to all elements in list
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          10-Jul-2013 by EMANOJ1
**==========================================================================*/
static void hmi_gfx_anim_engine_transform(GFX_ANIM_TYPES_DEF_T const * p_tdata, UINT32 p_cur_per, UINT32 p_pre_per)
{
   GFX_ANIM_TRANSFORM_T const * fl_data = p_tdata->val.transform;
   UINT32                       fl_num_elements   = p_tdata->num_elements;
   UINT32 const               * fl_elem_list_U32A = p_tdata->elem_list.static_elem_list;
   GFX_FLOAT                        fl_next_matrix[9];
   GFX_FLOAT const                * fl_cur_matrix;
   UINT32                           fl_index;
   GFX_FLOAT                        fl_cur_value;
   GFX_FLOAT                        fl_pre_value;

   while(fl_num_elements > (UINT32)0)
   {
      fl_num_elements--;
      /*
      ** Read the default matrix for the element and find the
      ** new matrix by interpolating it with fl_data->matrix
      ** load the new matrix to elements animation property
      */
      fl_cur_matrix = HMI_GFX_ANIM_GET_MATRIX(*fl_elem_list_U32A);
      if(fl_cur_matrix != GFX_ANIM02_NULL_PTR)
      {
         for (fl_index=0; fl_index < 9U; fl_index++)
         {
            fl_next_matrix[fl_index] = fl_cur_matrix[fl_index];
            if(fabsf(fl_data->matrix[fl_index] - (GFX_FLOAT)0) > FLT_EPSILON)
            {
               fl_cur_value = hmi_gfx_anim_engine_find_fdelta((GFX_FLOAT)0, fl_data->matrix[fl_index], p_cur_per);
               fl_pre_value = hmi_gfx_anim_engine_find_fdelta((GFX_FLOAT)0, fl_data->matrix[fl_index], p_pre_per);
               fl_cur_value-= fl_pre_value;
               fl_next_matrix[fl_index] += fl_cur_value;
            }
         }
         HMI_GFX_ANIM_SET_MATRIX(*fl_elem_list_U32A, fl_next_matrix);
      }
      fl_elem_list_U32A++;
   }
}
#endif /* #if defined(GFX_MGR02_OPEN_VG) */

#ifdef GFX_DYN_DATA_ANIMATIONS
/*============================================================================
** Function Name:    hmi_gfx_anim_engine_calculate_dduration
** Visibility:       local
** Description:      Calculates the duration required for dynamic data animations
**                   based on the default duration/offset and the current offset
**                   Dynamic data animations are supported only for MAL for the
**                   moment.
** Invocation:       By hmi_gfx_anim_engine_run  
** Inputs/Outputs:   
** Critical Section: None.
** Created:          30-Apr-2013 by EMANOJ1
** Updated:          30-Apr-2013 by EMANOJ1
**==========================================================================*/
static UINT32 hmi_gfx_anim_engine_calculate_dduration(GFX_ANIM_CONTROL_T const * p_anim_ctrl_SP, UINT32 p_anim_duration)
{
   SINT32 fl_cdst_x;
   SINT32 fl_cdst_y;
   SINT32 fl_ddst_x = 0;
   SINT32 fl_ddst_y = 0;
   UINT32 fl_valid_type = (UINT32)TRUE;

   if(p_anim_ctrl_SP->types_sp->type == (UINT8)ANIM_TYPE_MAL)
   {
      GFX_ANIM_MAL_DYN_T const * fl_data = p_anim_ctrl_SP->types_sp->val.dyn_mal;
      fl_cdst_x = fl_data->cur_val->end.x;
      fl_cdst_y = fl_data->cur_val->end.y;
      fl_ddst_x = fl_data->def_val.end.x;
      fl_ddst_y = fl_data->def_val.end.y;
   }
   else if(p_anim_ctrl_SP->types_sp->type == (UINT8)ANIM_TYPE_AREA)
   {
      GFX_ANIM_AREA_DYN_T const * fl_data = p_anim_ctrl_SP->types_sp->val.dyn_area;
      fl_cdst_x = ((SINT32)fl_data->cur_val->end.x-(SINT32)fl_data->cur_val->end.w);
      fl_cdst_y = ((SINT32)fl_data->cur_val->end.y-(SINT32)fl_data->cur_val->end.h);
      fl_ddst_x = ((SINT32)fl_data->def_val.end.x-(SINT32)fl_data->def_val.end.w);
      fl_ddst_y = ((SINT32)fl_data->def_val.end.y-(SINT32)fl_data->def_val.end.h);
   }
   else
   {
      fl_cdst_x     = 0;
      fl_cdst_y     = 0;
      fl_valid_type = (UINT32)FALSE;
   }
   if(fl_cdst_x < 0)
   {
       fl_cdst_x = -fl_cdst_x;
   }
   if(fl_cdst_y < 0)
   {
       fl_cdst_y = -fl_cdst_y;
   }
   if(fl_ddst_x < 0)
   {
       fl_ddst_x = -fl_ddst_x;
   }
   if(fl_ddst_y < 0)
   {
       fl_ddst_y = -fl_ddst_y;
   }
   if((fl_cdst_x != 0) || (fl_cdst_y != 0))
   {
      SINT32 fl_cur_area;

      fl_cdst_x = (fl_ddst_x-fl_cdst_x);
      fl_cdst_y = (fl_ddst_y-fl_cdst_y);
      
      if(fl_cdst_x == 0)
      {
         fl_cur_area = fl_cdst_y;
      }
      else if(fl_cdst_y == 0)
      {
         fl_cur_area = fl_cdst_x;
      }
      else
      {
         fl_cur_area = (fl_cdst_x * fl_cdst_y);
      }

      if((fl_ddst_x != 0) || (fl_ddst_y != 0))
      {
         SINT32 fl_def_area;
         GFX_FLOAT  fl_duration;

         if(fl_ddst_x == 0)
         {
            fl_def_area = fl_ddst_y;
         }
         else if(fl_ddst_y == 0)
         {
            fl_def_area = fl_ddst_x;
         }
         else
         {
            fl_def_area = (fl_ddst_x * fl_ddst_y);
         }
         
         fl_duration  = (GFX_FLOAT)(p_anim_duration);
         fl_duration /= (GFX_FLOAT)(fl_def_area);
         fl_duration += 0.5f; /* Add the rounding value */
         fl_duration *= (GFX_FLOAT)(fl_cur_area);

         if(fl_duration < (GFX_FLOAT)0)
         {
            fl_duration = (-fl_duration);
         }
         fl_duration = ((GFX_FLOAT)p_anim_duration-fl_duration);
         if(fl_duration < (GFX_FLOAT)0)
         {
            p_anim_duration = 0;
         }
         else
         {
            p_anim_duration = (UINT32)(fl_duration);
         }
      }
      else
      {
         p_anim_duration = 0;
      }
      if(p_anim_duration == 0u)
      {
         p_anim_duration = 1;
      }
   }
   else if(fl_valid_type != (UINT32)FALSE)
   {
      p_anim_duration = 0;
   }
   else
   {
       /* MISRA Warning C-2012 Rule 15.7 Fix */
   }
   return(p_anim_duration);
}
#endif /* #ifdef GFX_DYN_DATA_ANIMATIONS */

/*============================================================================
** Function Name:    hmi_gfx_anim_get_client_id
** Visibility:       global
** Description:      Get the client of a running animation
** Invocation:       By Application
** Inputs/Outputs:   In :*p_client_id  - Pointer to UINT32 to store the Client id
**                        p_anim_id    - Animation Id for which client Id to be
**                                       read
**                   Out : Client id is written in to *p_client_id and returns TRUE
**                         if p_anim_id is valid and the state of the animation is 
**                         GFX_ANIM_STATE_RUNNING - if running
**                         GFX_ANIM_STATE_PAUSED  - if paused
**                         Else returns FALSE and nothing gets written to *p_client_id
**
** Critical Section: None.
** Created:          24-Mar-2014 by EMANOJ1
** Updated:          24-Mar-2014 by EMANOJ1
**==========================================================================*/
UINT32 hmi_gfx_anim_get_client_id(UINT32 p_anim_id, UINT32 * p_client_id)
{
   UINT32 fl_ret_status = 0; // (UINT32)FALSE - For MISRA fix FALSE is changed as 0
   if((p_anim_id < (UINT32)GFX_NUM_ANIMATIONS) && (p_client_id != GFX_ANIM02_NULL_PTR))
   {
      GFX_ANIM_FLAGS_T const * fl_anim_flags_SAP = (GFX_ANIM_FLAGS_T const *)(&l_anim_flags_SA[p_anim_id]);
      if((fl_anim_flags_SAP->state == GFX_ANIM_STATE_RUNNING) ||
         (fl_anim_flags_SAP->state == GFX_ANIM_STATE_PAUSED))
      {
         *p_client_id  = l_anim_client_id_U16A[p_anim_id];
         fl_ret_status = 1; // (UINT32)TRUE - For MISRA fix TRUE is changed as 1
      }
   }
   return(fl_ret_status);
}
/*============================================================================
** Function Name:    hmi_gfx_anim_get_current_anim_id
** Visibility:       global
** Description:      Get the running animation id
** Invocation:       By Application
** Inputs/Outputs:   None.
**                   current anim ID UINT32
**                   
** Critical Section: None.
** Created:          
** Updated:          
**==========================================================================*/
UINT32 hmi_gfx_anim_get_current_anim_id(void)
{
   return(l_current_anim_id_U32);
}

/*============================================================================
** Function Name:    hmi_gfx_anim_set_element_list
** Visibility:       global
** Description:      Sets the animation types element list 
** Invocation:       By Application
** Inputs/Outputs:   
**                   
**                   
** Critical Section: None.
** Created:          
** Updated:          
**==========================================================================*/
void hmi_gfx_anim_set_element_list(UINT32 p_anim_id,UINT32 p_frame_id,UINT8 p_index,UINT8 p_size,UINT32 * p_elem_list)
{
     GFX_ANIM_DEF_T       const * fl_anim_def_SP;
     GFX_ANIM_FRAME_DEF_T const * fl_frames_SP;
     GFX_ANIM_TYPES_DEF_T       * types_sp;
	 
	 if(p_anim_id < (UINT32)GFX_NUM_ANIMATIONS)
	 {
	    fl_anim_def_SP = &lc_animation_table_S[p_anim_id];
		if(p_frame_id < fl_anim_def_SP->num_frames)
		{
	      fl_frames_SP   = &fl_anim_def_SP->frames[p_frame_id];
		  if((fl_frames_SP->read_only_flag == 0u) && (p_index < fl_frames_SP->num_types))
		  {		  
     	     types_sp = &fl_frames_SP->types.dynamic_types[p_index];  		 	         
			 if(p_elem_list != NULL)
			 {
			   types_sp->num_elements = p_size;
	           types_sp->elem_list.dynamic_elem_list = p_elem_list;
			 }			 
		  }
		}
	 }	 
}


#if defined(GFX_ANIM_DLAYOUT_ENABLED)
/*============================================================================
** Function Name:    hmi_gfx_anim_engine_set_layout_selection
** Visibility:       global
** Description:      update to Animation core the selected GFX Animation Layout ID
** Invocation:       GFX MGR02
** Inputs/Outputs:   UINT8 p_layout_id.
** Critical Section: None.
** Created:          26-JUL-2016 by CMUTHUSA
** Updated:          26-JUL-2016 by CMUTHUSA          
**==========================================================================*/
void hmi_gfx_anim_engine_set_layout_selection(UINT8 p_layout_id)
{
	l_selected_anim_layout_U8=p_layout_id;	
}
#endif /* #if defined(GFX_ANIM_DLAYOUT_ENABLED) */
#endif /* #if GFX_NUM_ANIMATIONS > 0 */

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
** CMS Rev 1.27     13-MAY-19    KKUBENDI
** XXXXXX : Added function hmi_gfx_anim_engine_exponential_interpolate
**
** CMS Rev 1.27     11-APR-17    ARAJASE2
** 844701: CMFB MISRA Warning fixes - animation.core
**
** CMS Rev 1.26     02-OCT-16    APERUMAL             RTC: 735553
** Porsche Misra warning Fix
**
** CMS Rev 1.25      26-Jul-2016    CMUTHUSA
** 642213: Coding and implementation in GDT simulation for Arabic Design Layout support in gfx mgr 02.
**
** CMS Rev 1.24     08-JULY-16    APERUMAL             RTC: 639042
** Porsche Misra warning Fix
**
** CMS Rev 1.23     01-OCT-15    APERUMAL             RTC: 434948
** Fixed Compiler warning for Porsche
**
** CMS Rev 1.22     24-SEP-15    ADEVI             RTC: 368734
** Interface hmi_gfx_anim_get_current_anim_id added to get current anim id.
**
** CMS Rev 1.21     24-JUL-15    ARAJASE2
** Compiler warning fix for W207. GDT tool also changed for this fix.
**
** CMS Rev 1.20     10-FEB-15    KKUBENDI
** Compiler warning fix for Honda THAA.
**
** CMS Rev 1.19     06-oct-14    SSIGAMAN
** The conditional compilation macro for GFX_MGR02_AMBER is added.
** 
** CMS Rev 1.18     19-Apr-14    EMANOJ1
** hmi_gfx_anim_engine_calculate_dduration updated to fix P42M coverity issue
** 11090 and 11091
**
** CMS Rev 1.17     24-Mar-14    EMANOJ1
** Added interface to read the client id of a running animation 
** hmi_gfx_anim_get_client_id()
**
** CMS Rev 1.16     19-Aug-13    EMANOJ1
** Type in hmi_gfx_anim_engine_map function fixed which was using the 
** fl_cur_index insted of fl_pre_index
**
** CMS Rev 1.15     16-Aug-13    EMANOJ1
** Animations not running after execution of a goto frame when dynamic data 
** animations are present issue is fixed. The "fl_all_anim_done" flag was not 
** updated for goto animation case and was causing the animation to stop.
**
** CMS Rev 1.14     26-Jul-13    EMANOJ1
** Dynamic MAL animation getting compleated soon issue fix. 
** hmi_gfx_anim_engine_calculate_ddurationupdated to work with only positive 
** values. Updated rounding to be done immediately after division.
**
** CMS Rev 1.13     10-Jul-13    EMANOJ1
** Updated hmi_gfx_anim_engine_scale & hmi_gfx_anim_engine_transform also offset
** based from current matrix rather than from default matrix. This is to allow
** application to scale up and down in a same animation sequence. In earlier 
** implementation the scale was done with default matrix always so if the 
** scale up happens and followed by a scale down, the actual expectation was 
** that the after the scale up animation the object will remain in the scaled
** up position, and the scale down will bring it back to original state. But
** since we were operating with default matrix it wasn't happening this way.
**
** CMS Rev 1.12     19-Jun-13    EMANOJ1
** Updated to add dynamic AREA animation support for P552. Updated 
** hmi_gfx_anim_engine_calculate_dduration use float to avoid overflow while
** multiplications and to calculate time for the area moved rather than the
** area available after move.
** Updated hmi_gfx_anim_command to invoke the frame callback when this function
** terminates an already running animation. This is to fix an issue noted in
** TVM where the frame handler was doing some action on end of frame status
** and before the animation ends normally the hmi_gfx_anim_command invoked by
** view manager terminated it and the frame call back with end of frame did
** not get called and application failed to take the end of frame action.
** Fixed anim frame counter overflow, if application returns 0xFF from the goto
** callback handler.
** Handled a case where dynamic option is set to an unsupported type - in
** this case the duration is returned as is instead of returning 0
**
** CMS Rev 1.11     11-Jun-13    EMANOJ1
** Updated to fix the delay of one frame after execution of a goto frame
** by introducing a while loop to run the frame selected by goto in the 
** same cycle itself.
**
** CMS Rev 1.10     17-May-13    EMANOJ1
** Fixed an issue reported by jerome where an animation doesn't run if the value
** is too small for a dynamic MAL animation. The cause was that the duration was 
** calculated to a very low value which resulted in calculation of < a frame 
** needed to complete the animation and therefore the logic computed the 
** current and previous % to 100% and therefore no animation happened because 
** we the value says we reached 100%. This is fixed by adjusting the duration
** to atleast 1frame based on the rate configured for the animation.
** Enhancement done to stop the dynamic MAL animation as soon as the target
** is reached. Earlier it used to wait until the configured default duration 
** is elapsed.
** Roundup logic corrected in hmi_gfx_anim_engine_calculate_dduration()
**
** CMS Rev 1.9      06-May-13    EMANOJ1
** Fixed hmi_gfx_anim_engine_transform animation to match GDT behaviour. 
** The fl_data->matrix[] contains an offset value which should be added to
** current matrix. So hmi_gfx_anim_engine_find_fdelta, first param should be 0
**
** CMS Rev 1.8      30-Apr-13    EMANOJ1
** Added support for dynamic MAL animations by adding a new MAL data structure
** GFX_ANIM_MAL_DYN_T to hold the dynamic MAL data and its default MAL data
** Duration of the dynamic MAL animation is calculated by linearly interpolating
** or extrapolating based on the "default duration" & "default MAL data" ratio
** And applying this ratio to user modified "dynamic MAL data". Added function
** hmi_gfx_anim_engine_calculate_dduration to perform the duration calculation.
** Updated GFX_ANIM_HANDLER_CB typedef to fix an issue with gcc compiler not
** generating code for function invocation.
**
** CMS Rev 1.7      19-Apr-13    EMANOJ1
** Replaced MAL, MAP, AREA, WdHt with a single property set macro call to simplyfy
** implementation.
**
** CMS Rev 1.6      16-Apr-13    EMANOJ1
** QAC 7.1 fixes
**
** CMS Rev 1.5      12-Apr-13    EMANOJ1
** 1. MAL, AREA and WhHt handler fixed to use previous percentage in calculations
** 2. Fixed an issue in hmi_gfx_anim_engine which passed the previously set 
** fl_anim_ctrl_S pointer to hmi_gfx_anim_engine_stop which caused the incorrect
** animation to get stopped when there are multiple animations running. To fix
** passed animation id directly to hmi_gfx_anim_engine_stop
**
** CMS Rev 1.4      11-Apr-13    EMANOJ1
** Start value removed for MAL, AREA and WhHt Animations as they are offset based 
** and a start value doesn't matter. These animation functions updated accordingly
**
** CMS Rev 1.3      05-Apr-13    EMANOJ1
** Added support for goto condition check functionality by calling an application
** function. Added cur frame parameter to go to condition check function.
** Fixed an issue with initialization of goto count variable. It is fixed to 
** perform init only during the first run of frame for an animation sequence.
**
** CMS Rev 1.2      01-Apr-13    EMANOJ1
** hmi_gfx_anim_engine_run updated to fix
** 1. Overflow due to subtraction (p_anim_ctrl_SP->prev_elap_time_U32-fl_stime_U32)
**    for a case where fl_stime_U32 was != 0 in which case, prev_elap_time_U32 was
**    becoming < fl_stime_U32 during the initial comparisons.
** 2. Handled a case where duration == 0. When duration == 0, the cur and prev
**    position needs to be passed first as 100, 0% and 100, 100% respectively
**    to handle the XY, WH animations since they are handled as offset animations
**    based on previous and current positions.
**
** CMS Rev 1.1      21-Mar-13    EMANOJ1
** 1. Added support for OpenVG animations (Scale, Rotate and Transform).
** 2. Call back support added to provide application ability to set up the data
**    Callback will be called on start of every frame and on completion of all the
**    frames.
** 3. Issue with clamping to 100%, percentage was having a resolution of 0.1,
**    i.e. 100 percentage is represented as 1000, so updated all the places
**    where the percentage was assigned 100 to 1000.
** 4. hmi_gfx_anim_engine_next_frame updated to make current frame to max frame
**    count, when the direction is reverse and we are at frame 0.
** 5. Issue fix in Alpha and color animation handlers
** 6. l_anim_time_elapsed_U32A[] is initialized on every frame start becuase
**    earlier it continued to get accumulated and the second frame was getting 
**    shortened or not getting played.
**
** CMS Rev 1.0      27-Nov-12    EMANOJ1
** Creation.
**==========================================================================*/
#ifdef  __cplusplus
}
#endif

/* end of file =============================================================*/
