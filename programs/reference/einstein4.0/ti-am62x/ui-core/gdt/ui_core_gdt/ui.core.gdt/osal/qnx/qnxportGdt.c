/*=============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2019. Visteon Corporation owns all rights to this work and
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
 ** Name:           qnxportGdt.c
 **
 ** Description:    This module is created to use GDT using OpenGL in QNX.
 **                 It actually makes use of Screen library in QNX for creating 
 **                 the window and passing that to the OpenGL.
 **
 ** Organization:   UE COC, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#define QNXPORTGDT_C

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <screen/screen.h>
#include <EGL/egl.h>
#include <EGL/eglplatform.h>
#include <GLES/gl.h>
#include "qnxportGdt.h"
#include "hmi_gfx_mgr02_if.h"
#include "input/screen_helpers.h"


#include "gestures/tap.h"
#include "gestures/double_tap.h"
#include "gestures/two_finger_double_tap.h"
#include "gestures/two_finger_tap.h"
#include "gestures/two_finger_pan.h"
#include "gestures/pinch.h"
#include "gestures/set.h"
#include "gestures/swipe.h"
#include "gestures/rotate.h"
#include "gestures/triple_tap.h"
#include "gestures/press_and_tap.h"
#include "gestures/long_press.h"

#ifndef QNX_DISPLAY_TYPE
 // 
 // SCREEN_DISPLAY_TYPE_INTERNAL = 0x7660   
 // SCREEN_DISPLAY_TYPE_COMPOSITE = 0x7661   
 // SCREEN_DISPLAY_TYPE_SVIDEO = 0x7662   
 // SCREEN_DISPLAY_TYPE_COMPONENT_YPbPr = 0x7663   
 // SCREEN_DISPLAY_TYPE_COMPONENT_RGB = 0x7664   
 // SCREEN_DISPLAY_TYPE_COMPONENT_RGBHV = 0x7665   
 // SCREEN_DISPLAY_TYPE_DVI = 0x7666   
 // SCREEN_DISPLAY_TYPE_HDMI = 0x7667   
 // SCREEN_DISPLAY_TYPE_DISPLAYPORT = 0x7668   
 // SCREEN_DISPLAY_TYPE_OTHER = 0x7669   
 // 
    #define QNX_DISPLAY_TYPE (SCREEN_DISPLAY_TYPE_INTERNAL)
#endif

#ifndef QNX_DISPLAY_ID
/*Typically, there's only one egl display section. Therefore, conventionally, you set the display ID to 1.*/
  #define QNX_DISPLAY_ID (1)
#endif

extern GFX_MGR02_LAYER_DEF_T const lc_layer_def_S[GFX_MGR02_NUM_LAYERS];
static int Get_Screen_Format(void);
static void init_gestures(void);
static void gestures_cleanup(void);
static void gesture_callback(gesture_base_t* gesture, mtouch_event_t* event, void* param, int async);
screen_event_t screen_ev;		/* a screen event to handle */
screen_context_t screen_ctx;	/* a connection to the screen windowing system */

static screen_window_t screen_win = NULL;
static screen_display_t * displays = 0;
static int target_display = 0;
static int displaytype=0;
static int displayId=0;
const int nbuffers = 2;
const int usage = SCREEN_USAGE_OPENGL_ES1;
static int format;
static int buffer_size[2]={0,0};

static int l_screen_init=0;
struct gestures_set * set;
static int pos[2] = { 0, 0 };          /* the x,y position of your pointer */
/*============================================================================
** Function Name:    hmi_gfx_lm_init
** Visibility:       global
** Description:      Creates screen context and window and sharing that to OpenGL init routine.
** Invocation:       By hmi_gfx_mgr02_ogllib_init().
** Inputs/Outputs:   None
** Critical Section: None.
**==========================================================================*/
int hmi_gfx_lm_init(void)
{
    int ret = TRUE;
    int rc =0;
    int numofdisplays = 0;
    format = Get_Screen_Format();
    buffer_size[0]=lc_layer_def_S[0].area.width;
    buffer_size[1]=lc_layer_def_S[0].area.height;
    rc =screen_create_context(&screen_ctx, 0);
    if(0==rc)
    {
        rc= screen_get_context_property_iv(screen_ctx, SCREEN_PROPERTY_DISPLAY_COUNT, &numofdisplays);
        if(numofdisplays>0)
        {
            displays = (screen_display_t *)calloc((size_t)numofdisplays, (size_t)sizeof(screen_display_t));
            if(displays!=NULL)
            {
                rc= screen_get_context_property_pv(screen_ctx, SCREEN_PROPERTY_DISPLAYS, (void **)displays);
                if(0!=rc)
                {
                    numofdisplays=0;
                    perror("Error: Getting SCREEN_PROPERTY_DISPLAYS failed");
                }
                else
                {
                    for (target_display = 0; target_display < numofdisplays; target_display++)
                    {
                        rc= screen_get_display_property_iv(displays[target_display], SCREEN_PROPERTY_TYPE, &displaytype);
                        if(0!=rc)
                        {
                            numofdisplays=0;
                            perror("Error: Getting SCREEN_PROPERTY_TYPE failed");
                        }
                        else if(displaytype != QNX_DISPLAY_TYPE)
                        {
                            /* Display type is not matching. Look for next display.*/
                        }
                        else
                        {
                            rc= screen_get_display_property_iv(displays[target_display], SCREEN_PROPERTY_ID, &displayId);
                            if(0!=rc)
                            {
                                numofdisplays=0;
                                perror("Error: Getting SCREEN_PROPERTY_ID failed");
                            }
                            else if(displayId != QNX_DISPLAY_ID)
                            {
                                /* Display Id is not matching. Look for next display.*/
                            }
                            else
                            {
                                /*Display Type and Display ID got matched*/
                                break;
                            }
                        }
                    }
                }
            }
            else
            {
                numofdisplays=0;
                perror("Error: calloc failed");
            }
        }
        if(target_display >=numofdisplays)
        {
            perror("Error: Dispaly Lookup failed");
        }
        else
        {
            rc = screen_create_window(&screen_win, screen_ctx);
            if(0!=rc) {
                perror("Error: screen_create_window");
            }
            else
            {
                rc = screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_FORMAT, &format);
                if(0!=rc) {
	                perror("Error: screen_set_window_property_iv(SCREEN_PROPERTY_FORMAT)");
                }
                else
                {
                    rc = screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_USAGE, &usage);
                    if(0!=rc) {
	                    perror("Error: screen_set_window_property_iv(SCREEN_PROPERTY_USAGE) failed");
                    }
                    else
                    {
                        rc = screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_BUFFER_SIZE, buffer_size);
                        if(0!=rc) {
	                        perror("Error: screen_set_window_property_iv failed");
                        }
                        else
                        {
                            rc = screen_create_window_buffers(screen_win, nbuffers);
                            if(0!=rc) {
	                            perror("Error: screen_create_window_buffers failed");
                            }
                            else
                            {
                                rc = screen_create_event(&screen_ev);
                                if (0!=rc) {
	                                perror("Error: screen_create_event");
                                }
                            }
                        }
                    }
                }
            }
        }
	    if(0==rc){
	    	l_screen_init=1;
            init_gestures();
	    	ret=FALSE;
            fprintf(stderr,"Screen Lib Initialized\n");
	    }
        else
        {
            l_screen_init=0;
            cleanup();
		    fprintf(stderr,"Screen Lib Initialization Failed\n");
        }

	}
	else
	{
		l_screen_init=0;
		cleanup();
		fprintf(stderr,"Screen Lib Initialization Failed\n");
	}
	return ret;
}

/*============================================================================
** Function Name:    cleanup
** Visibility:       global
** Description:      Destroys the window and context.
** Invocation:       By hmi_gfx_lm_init() and in shutdown sequence.
** Inputs/Outputs:   None
** Critical Section: None.
**==========================================================================*/
void cleanup(void) {
    gestures_cleanup();
    screen_destroy_event(screen_ev);
	if (screen_win != NULL) {
		screen_destroy_window(screen_win);
		screen_win = NULL;
	}
	if (displays != 0)
	{
		free(displays);
	}
	if(screen_ctx!=0)
	{
		screen_destroy_context(screen_ctx);
	}
    l_screen_init=0;

}
/*============================================================================
** Function Name:    hmi_gfx_lm_get_x11_display
** Visibility:       Global
** Description:      Returning the display handle.
** Invocation:       By hmi_gfx_mgr02_ogllib_init()
** Inputs/Outputs:   Display handle.
** Critical Section: None.
**==========================================================================*/
EGLNativeDisplayType * hmi_gfx_lm_get_x11_display(void)
{
	return((EGLNativeDisplayType *) displays[target_display]);
}
/*============================================================================
** Function Name:    hmi_gfx_lm_get_x11_window
** Visibility:       Global
** Description:      Returning the window handle.
** Invocation:       By hmi_gfx_mgr02_ogllib_init()
** Inputs/Outputs:   Window handle.
** Critical Section: None.
**==========================================================================*/
EGLNativeWindowType hmi_gfx_lm_get_x11_window(void)
{
   return(screen_win);
}
/*============================================================================
** Function Name:    is_screenlib_initialized
** Visibility:       Global
** Description:      Returning whether the Screen lib initialization succeeded or not.
** Invocation:       
** Inputs/Outputs:   screen library initialization status.
** Critical Section: None.
**==========================================================================*/
int is_screenlib_initialized(void)
{
 return (l_screen_init);
}
/*============================================================================
** Function Name:    Get_Screen_Format
** Visibility:       Local
** Description:      Returning the screen format based on the GDT picel format settings..
** Invocation:       By hmi_gfx_lm_init() and in shutdown sequence.
** Inputs/Outputs:   screen format
** Critical Section: None.
**==========================================================================*/
static int Get_Screen_Format(void)
{
    int ret =SCREEN_FORMAT_RGBA8888;
    switch(lc_layer_def_S[0].pix_format)
    {
        case GFX_MGR02_PIX_FORMAT_8BPP:
            ret =SCREEN_FORMAT_BYTE;
         break;
        case GFX_MGR02_PIX_FORMAT_RGB565:
            ret =SCREEN_FORMAT_RGB565;
         break;
        case GFX_MGR02_PIX_FORMAT_ARGB4444:
            ret=SCREEN_FORMAT_RGBA4444;
         break;
        case GFX_MGR02_PIX_FORMAT_RGB666:
         break;
        case GFX_MGR02_PIX_FORMAT_RGB888:
            ret=SCREEN_FORMAT_RGB888;
         break;
        case GFX_MGR02_PIX_FORMAT_ARGB8888:
        default:
            ret= SCREEN_FORMAT_RGBA8888;
         break;
    }
    return ret;
}
/*============================================================================
** Function Name:    init_gestures
** Visibility:       Local
** Description:      This function initializes the gesture set.
** Invocation:       By hmi_gfx_lm_init().
** Inputs/Outputs:   None
** Critical Section: None.
**==========================================================================*/
static void init_gestures(void)
{
    set = gestures_set_alloc();
    if (NULL != set) {
        long_press_gesture_alloc(NULL, gesture_callback, set);
        tap_gesture_alloc(NULL, gesture_callback, set);
        double_tap_gesture_alloc(NULL, gesture_callback, set);
        pt_gesture_alloc(NULL, gesture_callback, set);
        tft_gesture_alloc(NULL, gesture_callback, set);
        tfpan_gesture_alloc(NULL, gesture_callback, set);
        pinch_gesture_alloc(NULL, gesture_callback, set);
        rotate_gesture_alloc(NULL, gesture_callback, set);
        swipe_gesture_alloc(NULL, gesture_callback, set);
        two_finger_double_tap_gesture_alloc(NULL, gesture_callback, set);
        triple_tap_gesture_alloc(NULL, gesture_callback, set);
    } else {
        fprintf(stderr, "Failed to allocate gestures set\n");
    }
}
/*============================================================================
** Function Name:    gestures_cleanup
** Visibility:       Local
** Description:      This function destroys the gesture set.
** Invocation:       By cleanup().
** Inputs/Outputs:   None
** Critical Section: None.
**==========================================================================*/
static void gestures_cleanup(void)
{
    if (NULL != set) {
        gestures_set_free(set);
        set = NULL;
    }
}
/*============================================================================
** Function Name:    handle_screen_event
** Visibility:       Global
** Description:      This function will detect the touch events and send that to the GDT.
** Invocation:       By .
** Inputs/Outputs:   None
** Critical Section: None.
**==========================================================================*/
void handle_screen_event(void)
{
    int screen_val, rc;
    mtouch_event_t mtouch_event;
    GFX_MGR02_TOUCH_QDATA fl_touch_data_SP;
    screen_get_event(screen_ctx,screen_ev,0);
    rc = screen_get_event_property_iv(screen_ev, SCREEN_PROPERTY_TYPE, &screen_val);
    if(screen_val == SCREEN_EVENT_POINTER)
    {
        fprintf(stderr, "mouse event got detected\n");
        rc= screen_get_event_property_iv(screen_ev, SCREEN_PROPERTY_BUTTONS, &screen_val);
        if (screen_val) 
        {
            screen_get_event_property_iv(screen_ev, SCREEN_PROPERTY_POSITION, pos);
            fprintf(stderr, "pointer x: %d, pointer y: %d\n", pos[0], pos[1]);
        }
    }
    if(screen_val == SCREEN_EVENT_MTOUCH_TOUCH || screen_val == SCREEN_EVENT_MTOUCH_MOVE || screen_val == SCREEN_EVENT_MTOUCH_RELEASE)
    {
        rc = screen_get_mtouch_event(screen_ev, &mtouch_event, 0);
        if (rc) {
            fprintf(stderr, "Error: failed to get mtouch event\n");
        }
        rc = gestures_set_process_event(set, &mtouch_event, NULL);
        /* rc value is non zero if configured gesture is got deducted.*/
        if(!rc)
        {
            fl_touch_data_SP.ext.gesture = GFX_MGR02_GESTURE_NONE;
            if (screen_val == SCREEN_EVENT_MTOUCH_TOUCH) {        
                fl_touch_data_SP.x = mtouch_event.x;   
                fl_touch_data_SP.y = mtouch_event.y;    
                fl_touch_data_SP.event = GFX_MGR02_MOUSE_DOWN_EV;

                hmi_gfx_mgr02_layout_push_touch_event(&fl_touch_data_SP);
            }
            else if (screen_val == SCREEN_EVENT_MTOUCH_MOVE) {        
                fl_touch_data_SP.x = mtouch_event.x;   
                fl_touch_data_SP.y = mtouch_event.y;    
                fl_touch_data_SP.event = GFX_MGR02_MOUSE_MOVE_EV;
                hmi_gfx_mgr02_layout_push_touch_event(&fl_touch_data_SP);
            }
            else if (screen_val == SCREEN_EVENT_MTOUCH_RELEASE) {
                fl_touch_data_SP.x = mtouch_event.x;   
                fl_touch_data_SP.y = mtouch_event.y;    
                fl_touch_data_SP.event = GFX_MGR02_MOUSE_UP_EV;
                hmi_gfx_mgr02_layout_push_touch_event(&fl_touch_data_SP);
            }
        }
    }
}
/*============================================================================
** Function Name:    gesture_callback
** Visibility:       Local
** Description:      The callback invoked when a gesture is recognized or updated..
** Invocation:       By gesture library upon detection of configured gestures.
** Inputs/Outputs:   None
** Critical Section: None.
**==========================================================================*/
static void gesture_callback(gesture_base_t* gesture, mtouch_event_t* event, void* param, int async)
{
    GFX_MGR02_TOUCH_QDATA fl_touch_data_SP;
    switch (gesture->type) {

        case GESTURE_TWO_FINGER_PAN: {
            gesture_tfpan_t* tfpan = (gesture_tfpan_t*)gesture;
            fprintf(stderr,"Two-finger pan: %d, %d", tfpan->centroid.x, tfpan->centroid.y);
            fl_touch_data_SP.x= tfpan->centroid.x;
            fl_touch_data_SP.y= tfpan->centroid.y;
            fl_touch_data_SP.ext.gesture = GFX_MGR02_GESTURE_TWO_FINGER_PAN;

            break;
        }
        case GESTURE_ROTATE:{
            gesture_rotate_t* rotate = (gesture_rotate_t*) gesture;
            fprintf(stderr,"Rotate ");
            if (rotate->angle != rotate->last_angle) {
                fprintf(stderr,"Rotate: %d degs", rotate->angle - rotate->last_angle);
                fl_touch_data_SP.x= rotate->centroid.x;
                fl_touch_data_SP.y= rotate->centroid.y;
                fl_touch_data_SP.ext.angle= (rotate->angle - rotate->last_angle);
                fl_touch_data_SP.ext.gesture = GFX_MGR02_GESTURE_ROTATE;
            }
            break;
        }
        case GESTURE_SWIPE:{
            gesture_swipe_t* swipe = (gesture_swipe_t*) gesture;
            fprintf(stderr,"Swipe ");
            if (swipe->direction & GESTURE_DIRECTION_UP) {
                fprintf(stderr,"up %d", swipe->last_coords.y - swipe->coords.y);
                fl_touch_data_SP.ext.gesture = GFX_MGR02_GESTURE_SWIPE_UP;
            } else if (swipe->direction & GESTURE_DIRECTION_DOWN) {
                fprintf(stderr,"down %d", swipe->coords.y - swipe->last_coords.y);
                fl_touch_data_SP.ext.gesture = GFX_MGR02_GESTURE_SWIPE_DOWN;
            } else if (swipe->direction & GESTURE_DIRECTION_LEFT) {
                fprintf(stderr,"left %d", swipe->last_coords.x - swipe->coords.x);
                fl_touch_data_SP.ext.gesture = GFX_MGR02_GESTURE_SWIPE_LEFT;
            } else if (swipe->direction & GESTURE_DIRECTION_RIGHT) {
                fprintf(stderr,"right %d", swipe->coords.x - swipe->last_coords.x);
                fl_touch_data_SP.ext.gesture = GFX_MGR02_GESTURE_SWIPE_RIGHT;
            }
            fl_touch_data_SP.x = swipe->coords.x;
            fl_touch_data_SP.y = swipe->coords.y;
            break;
        }
        case GESTURE_PINCH: {
            gesture_pinch_t* pinch = (gesture_pinch_t*)gesture;
            fprintf(stderr,"Pinch %d, %d", (pinch->last_distance.x - pinch->distance.x),
                                   (pinch->last_distance.y - pinch->distance.y));

            /*Pinch Inward or Outward can be detrermined using current and last distance */
            if((pinch->last_distance.x - pinch->distance.x)>0)
            {
                /*Pinch inward horizotally*/
                fl_touch_data_SP.ext.gesture = GFX_MGR02_GESTURE_PINCH_INWARD_HORZ;
            }
            else if((pinch->distance.x - pinch->last_distance.x)>0)
            {
                /*Pinch outward horizotally*/
                fl_touch_data_SP.ext.gesture = GFX_MGR02_GESTURE_PINCH_OUTWARD_HORZ;
            }
            else if((pinch->last_distance.y - pinch->distance.y)>0)
            {
                /*Pinch inward vertically*/
                fl_touch_data_SP.ext.gesture = GFX_MGR02_GESTURE_PINCH_INWARD_VERT;
            }
            else if((pinch->distance.y - pinch->last_distance.y)>0)
            {
                /*Pinch outward vertically*/
                fl_touch_data_SP.ext.gesture = GFX_MGR02_GESTURE_PINCH_OUTWARD_VERT;
            }
            fl_touch_data_SP.x = pinch->centroid.x;
            fl_touch_data_SP.y = pinch->centroid.y;
            break;
        }
        case GESTURE_TAP: {
            gesture_tap_t* tap = (gesture_tap_t*)gesture;
            if (tap->base.state == GESTURE_STATE_COMPLETE)  {
                fprintf(stderr,"Tap x:%d y:%d",tap->touch_coords.x, tap->touch_coords.y);
                fl_touch_data_SP.x = tap->touch_coords.x;
                fl_touch_data_SP.y = tap->touch_coords.y;
                fl_touch_data_SP.ext.gesture = GFX_MGR02_GESTURE_TAP;
            }
            break;
        }
        case GESTURE_DOUBLE_TAP: {
            gesture_double_tap_t* dtap = (gesture_double_tap_t*)gesture;
            fprintf(stderr,"Double tap");
            if (dtap->base.state == GESTURE_STATE_COMPLETE)  {
                fprintf(stderr,"Double tap first_touch x:%d y:%d", dtap->first_touch.x,
                                                          dtap->first_touch.y);
                fprintf(stderr,"Double tap first_release x:%d y:%d", dtap->first_release.x,
                                                            dtap->first_release.y);
                fprintf(stderr,"Double tap second_touch x:%d y:%d", dtap->second_touch.x,
                                                           dtap->second_touch.y);
                fprintf(stderr,"Double tap second_release x:%d y:%d", dtap->second_touch.x,
                                                             dtap->second_release.y);
                fl_touch_data_SP.x = dtap->first_touch.x;
                fl_touch_data_SP.y = dtap->first_touch.y;
                fl_touch_data_SP.ext.gesture = GFX_MGR02_GESTURE_DOUBLE_TAP;
            }
            break;
        }

        case GESTURE_TRIPLE_TAP:{
            gesture_triple_tap_t* ttap =(gesture_triple_tap_t*)gesture;
            fprintf(stderr,"Triple Tap ");
            if (ttap->base.state == GESTURE_STATE_COMPLETE)  {
                fprintf(stderr,"Triple tap first_touch x:%d y:%d", ttap->first_touch.x,
                                                          ttap->first_touch.y);
                fprintf(stderr,"Triple tap first_release x:%d y:%d", ttap->first_release.x,
                                                            ttap->first_release.y);
                fprintf(stderr,"Triple tap second_touch x:%d y:%d", ttap->second_touch.x,
                                                           ttap->second_touch.y);
                fprintf(stderr,"Triple tap second_release x:%d y:%d", ttap->second_touch.x,
                                                             ttap->second_release.y);
                fprintf(stderr,"Triple tap third_touch x:%d y:%d", ttap->third_touch.x,
                                                          ttap->second_touch.y);
                fprintf(stderr,"Triple tap third_release x:%d y:%d", ttap->third_touch.x,
                                                            ttap->second_release.y);
                fl_touch_data_SP.x = ttap->first_touch.x;
                fl_touch_data_SP.y = ttap->first_touch.y;
                fl_touch_data_SP.ext.gesture = GFX_MGR02_GESTURE_TRIPLE_TAP;
            }
            break;
        }
        case GESTURE_PRESS_AND_TAP:{
            gesture_pt_t* pt=(gesture_pt_t*) gesture;
            fprintf(stderr,"Press and Tap ");
            if (pt->base.state == GESTURE_STATE_COMPLETE)  {
                fprintf(stderr,"Initial press x:%d y:%d", pt->initial_coords[0].x,
                                                 pt->initial_coords[0].y);
                fprintf(stderr,"Initial tap x:%d y:%d", pt->initial_coords[1].x,
                                               pt->initial_coords[1].y);
                fprintf(stderr,"Press x:%d y:%d", pt->coords[0].x, pt->coords[0].y);
                fprintf(stderr,"Tap x:%d y:%d", pt->coords[1].x, pt->coords[1].y);
                fl_touch_data_SP.x = pt->coords[0].x;
                fl_touch_data_SP.y = pt->coords[0].y;
                fl_touch_data_SP.ext.gesture = GFX_MGR02_GESTURE_PRESS_AND_TAP;
            }
            break;
        }
        case GESTURE_TWO_FINGER_TAP:{
            gesture_tft_t* tftap=(gesture_tft_t*)gesture;
            fprintf(stderr,"Two Finger Tap ");
            if (tftap->base.state == GESTURE_STATE_COMPLETE)  {
                fprintf(stderr,"Coordinates of touch event (finger 1) x:%d y:%d",
                                                             tftap->touch_coords[0].x,
                                                             tftap->touch_coords[0].y);
                fprintf(stderr,"Coordinates of touch event (finger 2) x:%d y:%d",
                                                             tftap->touch_coords[1].x,
                                                             tftap->touch_coords[1].y);
                fprintf(stderr,"Coordinates of release event (finger 1) x:%d y:%d",
                                                             tftap->release_coords[0].x,
                                                             tftap->release_coords[0].y);
                fprintf(stderr,"Coordinates of release event (finger 2) x:%d y:%d",
                                                             tftap->release_coords[1].x,
                                                             tftap->release_coords[1].y);
                fprintf(stderr,"Midpoint between two touches x:%d y:%d", tftap->centroid.x,
                                                                tftap->centroid.y);

                fl_touch_data_SP.x = tftap->touch_coords[0].x;
                fl_touch_data_SP.y = tftap->touch_coords[0].y;
                fl_touch_data_SP.ext.gesture = GFX_MGR02_GESTURE_TWO_FINGER_TAP;
            }
            break;
        }
        case GESTURE_TWO_FINGER_DOUBLE_TAP:{
            gesture_two_finger_double_tap_t* tfdt=(gesture_two_finger_double_tap_t*)gesture;
            fprintf(stderr,"Two Finger Double Tap ");
            fl_touch_data_SP.x = tfdt->centroid.x;
            fl_touch_data_SP.y = tfdt->centroid.y;
            fl_touch_data_SP.ext.gesture = GFX_MGR02_GESTURE_TWO_FINGER_DOUBLE_TAP;
            break;
        }
        case GESTURE_LONG_PRESS: {
            gesture_long_press_t* longpress = (gesture_long_press_t*)gesture;
            fprintf(stderr,"Long Press");
            if (longpress->base.state == GESTURE_STATE_COMPLETE)  {
                fprintf(stderr,"Long press x:%d y:%d",longpress->coords.x, longpress->coords.y);
                fprintf(stderr,"Timer ID:%d",longpress->success_timer);
                fl_touch_data_SP.x = longpress->coords.x;
                fl_touch_data_SP.y = longpress->coords.y;
                fl_touch_data_SP.ext.gesture = GFX_MGR02_GESTURE_LONG_PRESS;
            }
            break;
        }
        default: {
            fl_touch_data_SP.ext.gesture = GFX_MGR02_GESTURE_INVALID;
            fprintf(stderr,"Unknown Gesture");
            break;
        }
    }
    if(GFX_MGR02_GESTURE_INVALID != fl_touch_data_SP.ext.gesture)
    {
        hmi_gfx_mgr02_layout_push_touch_event(&fl_touch_data_SP);
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
 ** CMS Rev 1.0      Initial version
 ** Creation.
 ** 
 **==========================================================================*/

#ifdef  __cplusplus
}
#endif


