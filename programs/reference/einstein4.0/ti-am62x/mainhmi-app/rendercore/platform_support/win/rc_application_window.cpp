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
//  Description : Platform specific window handling for windows
//  Created on  : 20-Feb-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#if defined(WIN32)
#include <windows.h>
#include <cstdlib>  
#include <tchar.h>
#include "gfx3d_scg.h"
#include "rc_version.h"
#include "rc_application_window.h"

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

using namespace rendercore_engine;

// Windows class name to register
#define WINDOW_CLASS_NAME _T("glTFDemoClass")
// Name of the application
#if !defined(GLES3_RENDERER) || (GLES3_RENDERER < 30)
#define APPLICATION_NAME _T("renderCore | OpenGL ES 2.0")
#else
#define APPLICATION_NAME _T("renderCore | OpenGL ES 3.0")
#endif
// Title to display for errors.
#define ERROR_TITLE _T("Error")

#include "rc_imgui.h"

#ifndef DUMP_FRAME_BUFFER
#define DUMP_FRAME_BUFFER (0)
#endif

namespace
{
    bool windowTitleBarVisibility = true;
}

namespace rendercore_engine
{
    void SetWindowTitleBarVisibility(const bool p_visibility)
    {
        windowTitleBarVisibility = p_visibility;
    }
    class rc_win_handles
    {
    private:
        std::string windowTitle;
    public:
        int32_t winWidth = 1920;
        int32_t winHeight = 720;
        bool resizeReq = false;
        static std::map<HWND, rc_win_handles*> lwin2handle_map;
        HWND nativeWindow = nullptr;
        HDC deviceContext = nullptr;
        rc_generic_ws* winConfig = nullptr;

        rc_win_handles(rc_generic_ws* p_winConfig)
        {
            winConfig = p_winConfig;
            if (p_winConfig != nullptr)
            {
                const gfx3d_scg_display* const fl_disp = p_winConfig->GetParent();
                if (fl_disp != nullptr)
                {
                    if (fl_disp->IsBorderLessWindow())
                    {
                        windowTitleBarVisibility = false;
                    }
                    windowTitle = fl_disp->GetDisplayTitle();
                }
            }
        }
        ~rc_win_handles()
        {
            releaseWindowAndDisplay();
        }
        /*!*********************************************************************************************************************
        \param			nativeWindow                Handle to the window
        \param			message                     The message to handle
        \param			windowParameters            Additional message information
        \param			longWindowParameters        Additional message information
        \return	Result code to send to the OS
        \brief	Processes event messages for the main window
        ***********************************************************************************************************************/
        static LRESULT CALLBACK rc_ws_handle_WindowMessages(HWND nativeWindow, UINT message, WPARAM windowParameters, LPARAM longWindowParameters)
        {
            ImGui_ImplWin32_WndProcHandler(nativeWindow, message, windowParameters, longWindowParameters);

            const auto it = lwin2handle_map.find(nativeWindow);
            if (it != lwin2handle_map.end())
            {
                rc_win_handles* fl_winhandle = it->second;

                if (fl_winhandle != nullptr)
                {
                    switch (message)
                    {
                    case WM_COMMAND:
                        fl_winhandle->winConfig->PostKey(rcwinUETypeE::ueMenuEvent, (GLuint)windowParameters);
                        break;
                    case WM_CREATE:
                        printf("window has been created \n");
                        break;

                    case WM_SYSCOMMAND:
                        // Handle 2 system messages: screen saving and monitor power. We need to prevent them whilst we're rendering for a short time.
                    {
                        switch (windowParameters)
                        {
                        case SC_SCREENSAVE:
                        case SC_MONITORPOWER:
                        {
                            // Return 0 to let Windows know we don't want to sleep or turn the monitor off right now.
                            return 0;
                        }
                        }
                        break;
                    }
                    case WM_CLOSE:
                    {
                        // Handle the close message when a user clicks the quit icon of the window
                        PostQuitMessage(0);
                        fl_winhandle->winConfig->PostQuit();
                        return 1;
                    }
                    case WM_DESTROY:
                    {
                        PostQuitMessage(0);
                        return 0;
                    }
                    case WM_KEYDOWN:
                    {
                        fl_winhandle->winConfig->PostKey(rcwinUETypeE::ueKeyDown, (GLuint)windowParameters);
                    }
                    case WM_KEYUP:
                    {
                        fl_winhandle->winConfig->PostKey(rcwinUETypeE::ueKeyUp, (GLuint)windowParameters);
                    }
                    case WM_MOUSEMOVE:
                    {
                        fl_winhandle->winConfig->PostMouse(rcwinUETypeE::ueMouseMove, LOWORD(longWindowParameters), HIWORD(longWindowParameters), 0);
                    }
                    break;
                    case  WM_MOUSEWHEEL:
                    {
                        fl_winhandle->winConfig->PostMouse(rcwinUETypeE::ueMouseWheel, LOWORD(longWindowParameters), HIWORD(longWindowParameters), -(GET_WHEEL_DELTA_WPARAM(windowParameters) / 120.0f));
                    }
                    break;
                    case WM_LBUTTONDOWN:
                    {
                        fl_winhandle->winConfig->PostMouse(rcwinUETypeE::ueMouseDown, LOWORD(longWindowParameters), HIWORD(longWindowParameters), 0);
                    }
                    break;
                    case WM_LBUTTONUP:
                    {
                        fl_winhandle->winConfig->PostMouse(rcwinUETypeE::ueMouseUp, LOWORD(longWindowParameters), HIWORD(longWindowParameters), 0);
                    }
                    break;
                    case WM_GETMINMAXINFO:
                    {
                        RECT actualDesktop;
                        LPMINMAXINFO lpmmi = (LPMINMAXINFO)longWindowParameters;
                        actualDesktop.left = fl_winhandle->winConfig->GetX();
                        actualDesktop.top = fl_winhandle->winConfig->GetY();
                        actualDesktop.right = actualDesktop.left + fl_winhandle->winConfig->GetWidth();
                        actualDesktop.bottom = actualDesktop.top + fl_winhandle->winConfig->GetHeight();
                        if(AdjustWindowRect(&actualDesktop, WS_TILEDWINDOW, FALSE) != 0)
                        {
                            fl_winhandle->winWidth = actualDesktop.right - actualDesktop.left;
                            fl_winhandle->winHeight = actualDesktop.bottom - actualDesktop.top;

                            if ((lpmmi->ptMaxSize.x < fl_winhandle->winWidth) || (lpmmi->ptMaxSize.y < fl_winhandle->winHeight))
                            {
                                lpmmi->ptMaxSize.x = fl_winhandle->winWidth;
                                lpmmi->ptMaxSize.y = fl_winhandle->winHeight;
                                lpmmi->ptMaxTrackSize.x = fl_winhandle->winWidth;
                                lpmmi->ptMaxTrackSize.y = fl_winhandle->winHeight;
                                fl_winhandle->resizeReq = true;
                            }
                        }
                    }
                    break;
                    }
                }
            }
            // Calls the default window procedure for messages we did not handle
            return DefWindowProc(nativeWindow, message, windowParameters, longWindowParameters);
        }
        /*!*********************************************************************************************************************
        \param[out]	nativeWindow			    Native window type to create
        \param[out]	deviceContext			    Native device context to create
        \return	Whether the function succeeded or not.
        \brief	Creates a native window and display for the application to render into.
        ***********************************************************************************************************************/
        bool createNativeWindow(void)
        {
            // Describe the native window in a window class structure
            WNDCLASS nativeWindowDescription;
            TCHAR buffer[1024];
            DWORD fl_style;

            _sntprintf(buffer, (sizeof(buffer) / sizeof(TCHAR)) - 1, "%s_%p", WINDOW_CLASS_NAME, this);

            if (windowTitleBarVisibility)
            {
                fl_style = WS_TILEDWINDOW;
            }
            else
            {
                fl_style = 0;
            }

            nativeWindowDescription.style = CS_HREDRAW | CS_VREDRAW;
            nativeWindowDescription.lpfnWndProc = this->rc_ws_handle_WindowMessages;
            nativeWindowDescription.cbClsExtra = 0;
            nativeWindowDescription.cbWndExtra = 0;
            nativeWindowDescription.hInstance = GetModuleHandle(nullptr);
            nativeWindowDescription.hIcon = LoadIcon(nativeWindowDescription.hInstance, "ICON");
            nativeWindowDescription.hCursor = 0;
            nativeWindowDescription.lpszMenuName = 0;
            nativeWindowDescription.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
            nativeWindowDescription.lpszClassName = buffer;
            // Register the windows class with the OS.
            ATOM registerClass = RegisterClass(&nativeWindowDescription);
            if (!registerClass)
            {
                MessageBox(0, _T("Failed to register the window class"), ERROR_TITLE, MB_OK | MB_ICONEXCLAMATION);
            }
            // Create a rectangle describing the area of the window
            RECT windowRectangle;
            SetRect(&windowRectangle, winConfig->GetX(), winConfig->GetY(), winConfig->GetX() + winConfig->GetWidth(), winConfig->GetY() + winConfig->GetHeight());
            AdjustWindowRectEx(&windowRectangle, fl_style, false, 0);
            winWidth = (windowRectangle.right - windowRectangle.left);
            winHeight = (windowRectangle.bottom - windowRectangle.top);
            // Create the window from the available information
            CHAR8* fl_version = RcGetVersionString();
#if defined(_UNICODE)
#error "TODO : Handle it for unicode build..\n"
#else
            CHAR8 fl_appInfo[256];
            if (windowTitle.empty())
            {
                snprintf(fl_appInfo, sizeof(fl_appInfo) - 1, "%s | Ver%s", APPLICATION_NAME, fl_version);
            }
            else
            {
                snprintf(fl_appInfo, sizeof(fl_appInfo) - 1, "%s", windowTitle.c_str());
            }
            fl_appInfo[sizeof(fl_appInfo) - 1] = 0;
#endif
            nativeWindow = CreateWindow(
                buffer, fl_appInfo,
                WS_MAXIMIZE | fl_style, 0, 10,
                winWidth,
                winHeight,
                nullptr, nullptr,
                nativeWindowDescription.hInstance, nullptr);
            if (!windowTitleBarVisibility)
            {
                SetWindowLong(nativeWindow, GWL_STYLE, 0);
            }
            if (!nativeWindow)
            {
                MessageBox(0, _T("Failed to create the window"), ERROR_TITLE, MB_OK | MB_ICONEXCLAMATION);
                return false;
            }
            ShowWindow(nativeWindow, SW_SHOWNORMAL);
            MoveWindow(nativeWindow,
                winConfig->GetX(), winConfig->GetY(),
                winWidth,
                winHeight, TRUE);
            lwin2handle_map.insert(std::make_pair(nativeWindow, this));
            // Get the associated device context from the window
            deviceContext = GetDC(nativeWindow);
            if (!deviceContext)
            {
                MessageBox(nativeWindow, _T("Failed to create the device context"), ERROR_TITLE, MB_OK | MB_ICONEXCLAMATION);
                return false;
            }
            return true;
        }
        GLint Swap(void)
        {
            MSG msg;
            if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }

            if (resizeReq)
            {
                RECT windowRectangle;
                GetWindowRect(nativeWindow, &windowRectangle);
                MoveWindow(nativeWindow,
                    windowRectangle.left, windowRectangle.top,
                    winWidth + windowRectangle.left,
                    winHeight + windowRectangle.top, TRUE);
                resizeReq = false;
            }
            return(EGL_TRUE);
        }
        /*!*********************************************************************************************************************
         \param			nativeWindow                The native window to release
         \param			deviceContext               The native display to release
         \brief	Releases all resources allocated by the windowing system
         ***********************************************************************************************************************/
        void releaseWindowAndDisplay(void)
        {
            // Release the device context.
            if (deviceContext)
            {
                if (ReleaseDC(nativeWindow, deviceContext) == 0)
                {
                    RcDebugErrorLogId(rc_error_logId::elPlatWsReleaseDCFailed);
                }
                deviceContext = nullptr;
            }
            // Destroy the window
            if (nativeWindow)
            {
                DestroyWindow(nativeWindow);
                nativeWindow = nullptr;
            }
        }
    };
    rc_application_window::rc_application_window()
    {
        if (gfx3d_scg_project::GetProjGlesConfig() != GLES3_RENDERER)
        {
            RcDebugErrorLogId(rc_error_logId::elPlatWsBuildOptionMismatchGlesRenderer);
            WLOG("Library build option & application build mismatch GLES3_RENDERER (lib=%d,app=%d)\n", gfx3d_scg_project::GetProjGlesConfig(), GLES3_RENDERER);
        }
        if (gfx3d_scg_project::GetProjMthreadsConfig() != RC_MTHREADS)
        {
            RcDebugErrorLogId(rc_error_logId::elPlatWsBuildOptionMismatchMthreads);
            WLOG("Library build option & application build mismatch RC_MTHREADS (lib=%d,app=%d)\n", gfx3d_scg_project::GetProjMthreadsConfig(), RC_MTHREADS);
        }
    }
	bool rc_application_window::Open(rc_generic_ws* p_parent)
    {
        bool fl_sts;
        if (p_parent != nullptr)
        {
            handle = new rc_win_handles(p_parent);
            display = p_parent->GetParent();
            fl_sts = true;
        }
        else
        {
            fl_sts = false;
        }
        return fl_sts;
    }
    rc_application_window::~rc_application_window()
    {
        delete handle;
    }
    bool rc_application_window::createNativeWindow(void)
    {
        bool fl_sts = false;
        if (handle != nullptr)
        {
            if (handle->createNativeWindow())
            {
                fl_sts = true;
            }
        }
        return(fl_sts);
    }
    EGLNativeWindowType rc_application_window::GetNativeWindow() const
    {
        EGLNativeWindowType fl_nativeWindow = (EGLNativeWindowType)0;
        if (handle != nullptr)
        {
            fl_nativeWindow = handle->nativeWindow;
        }
        return(fl_nativeWindow);
    }
    EGLNativeDisplayType rc_application_window::GetDeviceContext() const
    {
        EGLNativeDisplayType fl_displayType = (EGLNativeDisplayType)0;
        if (handle != nullptr)
        {
            fl_displayType = handle->deviceContext;
        }
        return(fl_displayType);
    }

    void rc_application_window::releaseNativeWindow(void)
    {
        if (handle != nullptr)
        {
            handle->releaseWindowAndDisplay();
        }
    }
    bool rc_application_window::Close(void)
    {
        rc_imgui::Clear(display);
        releaseNativeWindow();
        return(true);
    }
    bool rc_application_window::Swap(const bool p_changed)
    {
#if DUMP_FRAME_BUFFER == 1
        if (p_changed)
        {
            GLvoid* fl_pix_data = rc_malloc(GetWidth() * GetHeight() * 4);
            GLCALL(glReadPixels(0, 0, GetWidth(), GetHeight(), GL_RGBA, GL_UNSIGNED_BYTE, fl_pix_data));
            Debug::WritePpm("window.ppm", GetWidth(), GetHeight(), (CHAR8*)fl_pix_data, 32);
            rc_free<GLvoid>(fl_pix_data);
        }
#endif
        rc_imgui::Render(display);
        //ignoring p_changed flag, as windows always imgui used and always wanted to swap
        //handle->Swap() always returns true
        return(handle->Swap());
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
    std::map<HWND, rc_win_handles*> rc_win_handles::lwin2handle_map;
}
#endif
