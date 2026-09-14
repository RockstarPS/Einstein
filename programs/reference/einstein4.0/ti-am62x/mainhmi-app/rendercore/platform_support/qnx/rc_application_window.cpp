///////////////////////////////////////////////////////////////////////////////
//
//                     CONFIDENTIAL VISTEON CORPORATION
//
// This is an unpublished work of authorship, which contains trade secrets,
// created in 2018. Visteon Corporation owns all rights to this work and
// intends to maintain it in confidence to preserve its trade secret status.
// Visteon Corporation reserves the right, under the copyright laws of the
// United States or those of any other country that may have jurisdiction,
// to protect this work as an unpublished work, in the event of an
// inadvertent or deliberate unauthorized publication. Visteon Corporation
// also reserves its rights under all copyright laws to protect this work as
// a published work, when appropriate. Those having access to this work may
// not copy it, use it, modify it or disclose the information contained in
// it without the written authorization of Visteon Corporation.
//
//  Filename    : rc_ws_windows.h
//  Description : Platform specific window handling for QNX
//  Created on  : 20-Feb-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#include "gfx3d_scg.h"
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <screen/screen.h>
#include <cstdlib>
#include <iostream>
#include <sys/procmgr.h>
#include <sys/mman.h>
#include <sys/neutrino.h>
#include <hw/inout.h>
#include <ctime>
#include <cerrno>
#include <pthread.h>
#include <unistd.h>
#include <cstring>
#include <unistd.h>
#include <cstdlib>
#if defined(RCIMGUI_ENABLE)
#include "rc_imgui.h"
#endif
#include "rc_application_window.h"

namespace
{
    // private variables
    int32_t pipeline = -1;
    int32_t zorder = -1;
    // display index to choose. 
    // -1 means direct indexing is not used, innstead selection may be made using 
    // lookup of  display_type / display_id
    int32_t display = -1;
    int32_t usrTransp = -1;
}
namespace rendercore_engine
{
    void SetupQNXScreenPipeline(const int32_t p_pipeline, const int32_t p_zorder, const int32_t p_display, const int32_t p_transp)
    {
        pipeline = p_pipeline;
        zorder = p_zorder;
        display = p_display;
        usrTransp = p_transp;
        ILOG("pipeline=%d zorder =%d transp=%d\n", pipeline, zorder, usrTransp);
    }
    /// class rc win handles has the main handle for the window
    class rc_win_handles
    {
    private:
        screen_context_t screen_ctx = nullptr;					///< screen context
        screen_window_t  screen_win = nullptr;					///< screen window	
        const int32_t usage = SCREEN_USAGE_OPENGL_ES2;			///< usage type for screen
        int32_t size[2];                						///< resolultion for screen
        int32_t pos[2];								            ///< position of screen
        const int32_t nbuffers = 3;						        ///< total number of buffers
        int32_t scrformat = SCREEN_FORMAT_RGBA8888;		        ///< screen format
        int32_t transp = SCREEN_TRANSPARENCY_NONE;              ///< screen transparancy
        const EGLint interval = 1;				                ///< opengl es interval
        EGLNativeWindowType nativeWindow = static_cast<EGLNativeWindowType>(nullptr);	///<native window
        rc_generic_ws* winConfig = nullptr;   		            ///<window config object
    public:
        /// constructor
        rc_win_handles(rc_generic_ws* const p_winConfig)
        {
            winConfig = p_winConfig;
            if (winConfig != nullptr)
            {
                const GLsizei flw = winConfig->GetWidth();
                if (flw <= 0)
                {
                    // load default values
                    size[0] = 1920;
                    size[1] = 720;
                    pos[0] = 0;
                    pos[1] = 0;
                }
                else
                {
                    const GLsizei flh = winConfig->GetHeight();
                    if (flh <= 0)
                    {
                        // load default values
                        size[0] = 1920;
                        size[1] = 720;
                        pos[0] = 0;
                        pos[1] = 0;
                    }
                    else
                    {
                        const GLint flx = winConfig->GetX();
                        const GLint fly = winConfig->GetY();
                        size[0] = static_cast<int32_t>(flw);
                        size[1] = static_cast<int32_t>(flh);
                        pos[0] = static_cast<int32_t>(flx);
                        pos[1] = static_cast<int32_t>(fly);
                    }
                }
                rtColorDepthE const fl_cf = winConfig->GetColorSize();
                switch (fl_cf)
                {
                case rtColorDepthE::wcColor16bpp:
                    scrformat = SCREEN_FORMAT_RGB565;
                    break;
                case rtColorDepthE::wcColor24bpp:
                    scrformat = SCREEN_FORMAT_RGB888;
                    break;
                case rtColorDepthE::wcColor32bpp:
                    scrformat = SCREEN_FORMAT_RGBA8888;
                    break;
                default:
                    RcDebugLog("rc_win_handles", rc_message_type::mtErr, "Unsupported format\n");
                    break;
                }
            }
            else
            {
                // load default values
                size[0] = 1920;
                size[1] = 720;
                pos[0] = 0;
                pos[1] = 0;
            }
            if (screen_create_context(&screen_ctx, SCREEN_APPLICATION_CONTEXT) != 0)
            {
                ELOG("screen_create_context failed\n");
            }
            else if (screen_create_window(&screen_win, screen_ctx) != 0)
            {
                ELOG("screen_create_window failed\n");
            }
            else
            {
                //< display type to lookup.
                // -1 for no lookup  OR below for lookup      
                // SCREEN_DISPLAY_TYPE_INTERNAL;
                // SCREEN_DISPLAY_TYPE_COMPOSITE;
                // SCREEN_DISPLAY_TYPE_SVIDEO;
                // SCREEN_DISPLAY_TYPE_COMPONENT_YPbPr;
                // SCREEN_DISPLAY_TYPE_COMPONENT_RGB;
                // SCREEN_DISPLAY_TYPE_COMPONENT_RGBHV;
                // SCREEN_DISPLAY_TYPE_DVI;
                // SCREEN_DISPLAY_TYPE_HDMI;
                // SCREEN_DISPLAY_TYPE_OTHER;
                const int32_t fl_display_type = -1;
                // display id to lookup. -1 for no lookup
                const int32_t fl_display_id = display;
                if ((fl_display_type >= 0) || (fl_display_id >= 0))
                {
                    int32_t fl_screen_ndisplays = 0;
                    if (screen_get_context_property_iv(screen_ctx, SCREEN_PROPERTY_DISPLAY_COUNT, &fl_screen_ndisplays) == 0)
                    {
                        screen_display_t fl_screen_displays[4U];
                        const int32_t fl_display_count = static_cast<int32_t>(sizeof(fl_screen_displays) / sizeof(fl_screen_displays[0]));
                        if (fl_screen_ndisplays > fl_display_count)
                        {
                            ELOG("Not enough space allocated to read all available displays\n");
                            WLOG("Number of displays in QNX target : % d, Space allocated for only%d\n", fl_screen_ndisplays, fl_display_count);
                        }
                        else
                        {
                            if (screen_get_context_property_pv(screen_ctx, SCREEN_PROPERTY_DISPLAYS, reinterpret_cast<void**>(fl_screen_displays)) == 0)
                            {
                                for (int32_t fl_screen_target_display = 0; fl_screen_target_display < fl_screen_ndisplays; fl_screen_target_display++)
                                {
                                    int32_t fl_dtype = -1;
                                    int32_t fl_did = -1;
                                    bool fl_dtypematch;
                                    bool fl_didmatch;
                                    if (screen_get_display_property_iv(fl_screen_displays[fl_screen_target_display], SCREEN_PROPERTY_TYPE, &fl_dtype) == 0)
                                    {
                                        fl_dtypematch = ((fl_display_type < 0) || (fl_dtype == fl_display_type));
                                    }
                                    else
                                    {
                                        ELOG("get SCREEN_PROPERTY_TYPE failed\n");
                                        fl_dtypematch = false;
                                    }
                                    if (screen_get_display_property_iv(fl_screen_displays[fl_screen_target_display], SCREEN_PROPERTY_ID, &fl_did) == 0)
                                    {
                                        fl_didmatch = ((fl_display_id < 0) || (fl_did == fl_display_id));
                                    }
                                    else
                                    {
                                        ELOG("get SCREEN_PROPERTY_ID failed\n");
                                        fl_didmatch = false;
                                    }
                                    ILOG("Display index=%d, id=%d, type=%d\n", fl_screen_target_display, fl_did, fl_dtype);
                                    if (fl_dtypematch && fl_didmatch)
                                    {
                                        ILOG("Selecting Display\n");
                                        // this display can be selected as id and type is matched.
                                        if (screen_set_window_property_pv(screen_win, SCREEN_PROPERTY_DISPLAY, reinterpret_cast<void**>(&fl_screen_displays[fl_screen_target_display])) != 0)
                                        {
                                            ELOG("set SCREEN_PROPERTY_DISPLAY failed\n");
                                        }
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                ELOG("get SCREEN_PROPERTY_DISPLAYS failed\n");
                            }
                        }
                    }
                    else
                    {
                        ELOG("get SCREEN_PROPERTY_DISPLAY_COUNT failed\n");
                    }
                }
                // Success
            }
        }
        /// create window fn, sets up parameters and creates window
        bool createNativeWindow(void)
        {
            bool sts;
            if ((screen_ctx != nullptr) && (screen_win != nullptr))
            {
                if (screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_FORMAT, &scrformat) != 0)
                {
                    sts = false;
                    ELOG("screen_set_window_property_iv failed\n");
                }
                else if (screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_USAGE, &usage) != 0)
                {
                    sts = false;
                    ELOG("screen_set_window_property_iv SCREEN_PROPERTY_USAGE failed\n");
                }
                else
                {
                    bool fl_pipeline_sts;
                    if (pipeline != -1)
                    {
                        if (screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_PIPELINE, &pipeline) != 0)
                        {
                            fl_pipeline_sts = false;
                            ELOG("screen_set_window_property_iv SCREEN_PROPERTY_PIPELINE failed\n");
                        }
                        else
                        {
                            fl_pipeline_sts = true;
                        }
                    }
                    else
                    {
                        fl_pipeline_sts = true;
                    }
                    if (fl_pipeline_sts)
                    {
                        bool fl_zorder_sts;
                        if (zorder != -1)
                        {
                            if (screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_ZORDER, &zorder) != 0)
                            {
                                fl_zorder_sts = false;
                            }
                            else
                            {
                                fl_zorder_sts = true;
                            }
                        }
                        else
                        {
                            fl_zorder_sts = true;
                        }
                        if (!fl_zorder_sts)
                        {
                            sts = false;
                            ELOG("screen_set_window_property_iv SCREEN_PROPERTY_ZORDER failed\n");
                        }
                        else if (screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_SWAP_INTERVAL, &interval) != 0)
                        {
                            sts = false;
                            ELOG("screen_set_window_property_iv SCREEN_PROPERTY_SWAP_INTERVAL failed\n");
                        }
                        else if (screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_SIZE, size) != 0)
                        {
                            sts = false;
                            ELOG("screen_set_window_property_iv SCREEN_PROPERTY_SIZE failed\n");
                        }
                        else if (screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_POSITION, pos) != 0)
                        {
                            sts = false;
                            ELOG("screen_set_window_property_iv SCREEN_PROPERTY_POSITION failed\n");
                        }
                        else if (screen_create_window_buffers(screen_win, nbuffers) != 0)
                        {
                            sts = false;
                            ELOG("screen_create_window_buffers failed\n");
                        }
                        else
                        {
                            switch(usrTransp)
                            {
                                case 0:
                                {
                                    transp = SCREEN_TRANSPARENCY_SOURCE;
                                }
                                break;
                                case 1:
                                {
                                    transp = SCREEN_TRANSPARENCY_SOURCE_OVER;
                                }
                                break;
                                default:
                                {
                                    // leave at default
                                }
                                break;
                            }
                            if (screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_TRANSPARENCY, &transp) != 0)
                            {
                                sts = false;
                                ELOG("screen_create_window_buffers failed\n");
                            }
                            else
                            {
                                nativeWindow = static_cast<EGLNativeWindowType>(screen_win);
                                sts = true;
                            }
                        }
                    }
                    else
                    {
                        sts = false;
                    }
                }
            }
            else
            {
                sts = false;
            }
            return sts;
        }
        /// release the objects
        void releaseWindowAndDisplay(void) const
        {
            (void)screen_destroy_window(screen_win);
            (void)screen_destroy_context(screen_ctx);
        }
        EGLNativeWindowType GetNativeWindow() const
        {
            return(nativeWindow);
        }
    };
    rc_application_window::rc_application_window()
    {
        if (gfx3d_scg_project::GetProjGlesConfig() != GLES3_RENDERER)
        {
            ELOG("Build option mismatch GLES3_RENDERER\n");
            WLOG("Library build option & application build mismatch GLES3_RENDERER (lib=%d,app=%d)\n", gfx3d_scg_project::GetProjGlesConfig(), GLES3_RENDERER);
        }
        if (gfx3d_scg_project::GetProjMthreadsConfig() != RC_MTHREADS)
        {
            ELOG("Build option mismatch RC_MTHREADS\n");
            WLOG("Library build option & application build mismatch RC_MTHREADS (lib=%d,app=%d)\n", gfx3d_scg_project::GetProjMthreadsConfig(), RC_MTHREADS);
        }
    }
    rc_application_window::~rc_application_window()
    {
        delete handle;
    }
    void rc_application_window::releaseNativeWindow(void)
    {
        if (handle != nullptr)
        {
            handle->releaseWindowAndDisplay();
        }
    }
    bool rc_application_window::createNativeWindow(void)
    {
        bool fl_sts;
        if (handle != nullptr)
        {
            if (handle->createNativeWindow())
            {
                fl_sts = true;
            }
            else
            {
                fl_sts = false;
            }
        }
        else
        {
            fl_sts = false;
        }
        return(fl_sts);
    }
    EGLNativeWindowType rc_application_window::GetNativeWindow() const
    {
        EGLNativeWindowType fl_nativeWindow;
        if (handle != nullptr)
        {
            fl_nativeWindow = handle->GetNativeWindow();
        }
        else
        {
            fl_nativeWindow = static_cast<EGLNativeWindowType>(nullptr);
        }
        return(fl_nativeWindow);
    }
    EGLNativeDisplayType rc_application_window::GetDeviceContext() const
    {
        return(static_cast<EGLNativeDisplayType>(EGL_DEFAULT_DISPLAY));
    }
    bool rc_application_window::Open(rc_generic_ws* p_parent)
    {
        handle = new rc_win_handles(p_parent);
		if (p_parent != nullptr)
    	{
        	display = p_parent->GetParent();
		}
        return true;
    }
    bool rc_application_window::Close(void)
    {
        releaseNativeWindow();
        return(false);
    }
    bool rc_application_window::Swap(const bool p_changed)
    {
#if defined(RCIMGUI_ENABLE)
        rc_imgui::Render(display);
        (void)p_changed;
        return true; //always swap buffer as drawn with imgui 
#else
        return(p_changed);
#endif	
    }
    bool rc_application_window::FrameEnd()
    {
	    return true;
    }
    EGLDisplay rc_application_window::GetPlatformDisplay() const
    {
        return(EGL_NO_DISPLAY);
    }
    EGLint rc_application_window::GetPlatformVisualID() const
    {
        return(static_cast<EGLint>(EGL_DONT_CARE));
    }
}
