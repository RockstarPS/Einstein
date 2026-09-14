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
//  Description : Platform specific window handling for X11
//  Created on  : 20-Feb-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#include "gfx3d_scg.h"
#include "rc_platform_ws.h"
#include "rc_application_window.h"
#include  <X11/Xlib.h>
#include  <X11/Xatom.h>
#include  <X11/Xutil.h>
#include <EGL/egl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/time.h>
#include <emscripten.h>
#include <emscripten/html5.h>
#include "rc_imgui.h"

#include "png.h"
#include <sys/stat.h>
#include "rdf_scg_project.h"

#include "rc_wasm_bindings.h"


extern bool screenshot_enabled;

using namespace rendercore_engine;

namespace rendercore_engine
{
    /// contains data about the window
    struct ContextData
    {
        int       width;                        ///< width 
        int       height;                        ///<height
        EGLNativeDisplayType eglNativeDisplay;    ///<native display for window
        EGLNativeWindowType  eglNativeWindow;    ///<native window
        EGLDisplay  eglDisplay;                    ///<opengl display object
        EGLContext  eglContext;                    ///<opengl context
        EGLSurface  eglSurface;                    ///<opengl surface
        Display *x_display;                        ///<display object
    };

    struct mouse_info   
    { 
        float last_mouse_x { 0.0F };
        float last_mouse_y { 0.0F };
        bool is_mouse_down { false }; 
    };

    /// class rc win handles has the main handle for the window
    class rc_win_handles
    {

    public:
        ContextData data; ///< context data object
        rc_generic_ws* winConfig = nullptr; ///< window config object
        mouse_info m_mouse_info;
        rc_imgui* rcImgui = nullptr;
        ///constructor
        rc_win_handles(rc_generic_ws* p_winConfig)
        {
            winConfig = p_winConfig;
            memset ( &data, 0, sizeof( data ) );
        }

        static long GenInterpolation(long x, long in_min, long in_max, long out_min, long out_max) 
        {
            return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
        }

        static void PosScreenInterpolation(rc_win_handles* handle, long in_targetX,long in_targetY,float * InterpX,float * InterpY)
        {
            double canvas_w = 0.0f;
            double canvas_h = 0.0f;
            emscripten_get_element_css_size( "#canvas", &canvas_w, &canvas_h );
            *InterpX= (float)GenInterpolation(in_targetX, 0, canvas_w, 0, handle->winConfig->GetWidth());
            *InterpY= (float)GenInterpolation(in_targetY, 0, canvas_h, 0, handle->winConfig->GetHeight());
        }

        static EM_BOOL key_down_callback(int event_type, const EmscriptenKeyboardEvent* event, void* user_data)
        {
            rc_win_handles* handle = reinterpret_cast<rc_win_handles*>(user_data);
            handle->winConfig->PostKey(rcwinUETypeE::ueKeyDown, event->keyCode);
            return EM_TRUE;
        }

        static EM_BOOL key_up_callback(int event_type, const EmscriptenKeyboardEvent* event, void* user_data)
        {
            rc_win_handles* handle = reinterpret_cast<rc_win_handles*>(user_data);
            handle->winConfig->PostKey(rcwinUETypeE::ueKeyUp, event->keyCode);
            return EM_TRUE;
        }

        static EM_BOOL mouse_move_callback(int event_type, const EmscriptenMouseEvent* event, void* user_data)
        {
            rc_win_handles* handle = reinterpret_cast<rc_win_handles*>(user_data);
            float interpTarget_x=0.0f;
            float interpTarget_y=0.0f;
            PosScreenInterpolation(handle, event->targetX,event->targetY,&interpTarget_x,&interpTarget_y);
            handle->winConfig->PostMouse(rcwinUETypeE::ueMouseMove, interpTarget_x, interpTarget_y, 0);
            handle->m_mouse_info.last_mouse_x = interpTarget_x;
            handle->m_mouse_info.last_mouse_y = interpTarget_y;

            return EM_TRUE;
        }

        static EM_BOOL mouse_up_callback(int event_type, const EmscriptenMouseEvent* event, void* user_data)
        {
            rc_win_handles* handle = reinterpret_cast<rc_win_handles*>(user_data);

            float interpTarget_x=0.0f;
            float interpTarget_y=0.0f;
            PosScreenInterpolation(handle, event->targetX,event->targetY,&interpTarget_x,&interpTarget_y);
            handle->winConfig->PostMouse(rcwinUETypeE::ueMouseUp, interpTarget_x, interpTarget_y, 0);
            handle->m_mouse_info.is_mouse_down = false;
            return EM_TRUE;
        }

        static EM_BOOL mouse_down_callback(int event_type, const EmscriptenMouseEvent* event, void* user_data)
        {
            rc_win_handles* handle = reinterpret_cast<rc_win_handles*>(user_data);
            handle->m_mouse_info.is_mouse_down = true;
            float interpTarget_x=0.0f;
            float interpTarget_y=0.0f;
            PosScreenInterpolation(handle, event->targetX,event->targetY,&interpTarget_x,&interpTarget_y);

            handle->winConfig->PostMouse(rcwinUETypeE::ueMouseDown, interpTarget_x, interpTarget_y, 0);
            handle->m_mouse_info.last_mouse_x = interpTarget_x;
            handle->m_mouse_info.last_mouse_y = interpTarget_y;
            return EM_TRUE;
        }

        ///create window using contextData and title
        int WinCreate(ContextData *contextData, const char *title)
        {
            Window root;
            XSetWindowAttributes swa;
            XSetWindowAttributes  xattr;
            Atom wm_state;
            XWMHints hints;
            XEvent xev;
            EGLConfig ecfg;
            EGLint num_config;
            Window win;

            contextData->x_display = XOpenDisplay(NULL);
            if ( contextData->x_display == NULL )
            {
                return EGL_FALSE;
            }

            root = DefaultRootWindow(contextData->x_display);

            swa.event_mask  =  ExposureMask | PointerMotionMask | KeyPressMask;
            win = XCreateWindow(
                    contextData->x_display, root,
                    0, 0, contextData->width, contextData->height, 0,
                    CopyFromParent, InputOutput,
                    CopyFromParent, CWEventMask,
                    &swa );

            xattr.override_redirect = 0;
            XChangeWindowAttributes ( contextData->x_display, win, CWOverrideRedirect, &xattr );

            hints.input = 1;
            hints.flags = InputHint;
            XSetWMHints(contextData->x_display, win, &hints);

            // make the window visible on the screen
            XMapWindow (contextData->x_display, win);
            XStoreName (contextData->x_display, win, title);

            // get identifiers for the provided atom name strings
            wm_state = XInternAtom (contextData->x_display, "_NET_WM_STATE", 0);

            memset ( &xev, 0, sizeof(xev) );
            xev.type                 = ClientMessage;
            xev.xclient.window       = win;
            xev.xclient.message_type = wm_state;
            xev.xclient.format       = 32;
            xev.xclient.data.l[0]    = 1;
            xev.xclient.data.l[1]    = 0;
            XSendEvent (
            contextData->x_display,
            DefaultRootWindow ( contextData->x_display ),
            0,
            SubstructureNotifyMask,
            &xev );

            contextData->eglNativeWindow = (EGLNativeWindowType) win;
            contextData->eglNativeDisplay = (EGLNativeDisplayType) contextData->x_display;

            emscripten_set_keydown_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, this, 1, key_down_callback);
            emscripten_set_keyup_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, this, 1, key_up_callback);
            emscripten_set_mousemove_callback("#canvas", this, 1, mouse_move_callback);
            emscripten_set_mousedown_callback("#canvas", this, 1, mouse_down_callback);
            emscripten_set_mouseup_callback("#canvas", this, 1, mouse_up_callback);

            return EGL_TRUE;
        }

        ///open window
        bool Open(void)
        {
            bool sts = false;
            if (winConfig != nullptr)
            {
                data.width = winConfig->GetWidth();
                data.height = winConfig->GetHeight();
            }
            else
            {
                data.width = 1920;
                data.height = 720;
            }
            sts = WinCreate(&data, "Rendercore");
            return(sts);
        }

        /// swap window
        GLint Swap(void)
        {
            if (nullptr == rcImgui)
            {
                rcImgui = rc_imgui::Get(winConfig->GetParent());
            }

            rcImgui->SendMouseEvent(
                m_mouse_info.is_mouse_down, 
                m_mouse_info.last_mouse_x, 
                m_mouse_info.last_mouse_y, 
                0.0F
            );
            return true;
        }
        EGLNativeWindowType GetNativeWindow()
        {
            return data.eglNativeWindow;
        }
    };
}
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
        //TODO
    }
}
bool rc_application_window::createNativeWindow(void)
{
    bool fl_sts;
    if (handle != nullptr)
    {
        if (handle->Open())
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
        fl_nativeWindow = static_cast<EGLNativeWindowType>(0);
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
    display = p_parent->GetParent();
    return true;
}
bool rc_application_window::Close(void)
{
    // TODO
    return(false);
}
bool rc_application_window::Swap(const bool p_changed)
{
    //Take the sreenshot immediately before swap() in order glReadPixels() to get the proper frameBuffer
    if(screenshot_enabled) {
        std::string fl_ssfile = std::string("/screenshots/screenshot.png");
        display->GetWindow()->MakeCurrent();
        std::string fileName = "screenshot.png";
        mountIndexedDB();
        save_screenshot(fl_ssfile, (uint32_t)display->GetDimension().x, (uint32_t)display->GetDimension().y);
        syncIndexedDB();
        downloadScreenshot();
        screenshot_enabled = false;
    }

    if (handle != nullptr)
    {
        handle->Swap();
    }
    rc_imgui::Render(display);
    (void)p_changed;
    return true; //always swap buffer as drawn with imgui 
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
