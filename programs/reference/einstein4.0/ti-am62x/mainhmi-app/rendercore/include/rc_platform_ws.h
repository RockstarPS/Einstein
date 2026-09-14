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
//  Filename    : rc_platform_ws.h
//  Description : Platform specific common APIs
//  Created on  : 20-Feb-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_platform_ws_h
#define rc_platform_ws_h

namespace rendercore_engine
{
    class rc_win_handles;
    class rc_generic_ws;
    /// \ingroup Internal
    /// @{
    /// Interface class for creating a platform window for the rendercore
    class rc_platform_window
    {
    public:
        virtual ~rc_platform_window();
        rc_platform_window();
        /// Performs a shallow copy..
        rc_platform_window& operator=(const rc_platform_window& p_rhs) = delete;
        rc_platform_window(const rc_platform_window& p_rhs) = delete;
        /// <summary>
        /// Called prior to eglSwapBuffers call
        /// </summary>
        /// <param name="p_changed">true indicates there are draw calls issued and swap will be performed</param>
        /// <returns>true will perform a swap, false will prevent the eglSwapBuffers</returns>
        virtual bool Swap(const bool p_changed) = 0;
        /// <summary>
        /// Called after the eglSwapBuffers
        /// </summary>
        /// <returns>true on success</returns>
        virtual bool FrameEnd() = 0;
        /// <summary>
        /// Creates the native window. Invoked internally
        /// </summary>
        /// <returns>true on success</returns>
        virtual bool createNativeWindow(void) = 0;
        /// <summary>
        /// Releases the native window. Invoked internally
        /// </summary>
        virtual void releaseNativeWindow(void) = 0;
        /// <summary>
        /// Cleanup the native wndow
        /// </summary>
        /// <returns>true on success</returns>
        virtual bool Open(rc_generic_ws* const p_parent) = 0;
        /// <summary>
        /// Cleanup the native wndow
        /// </summary>
        /// <returns>true on success</returns>
        virtual bool Close(void) = 0;
        virtual EGLNativeWindowType GetNativeWindow() const = 0;	///< native window
        virtual EGLNativeDisplayType GetDeviceContext() const = 0;	///< native display device context
        virtual EGLDisplay GetPlatformDisplay() const = 0;          ///< get the platform specifc display handle
        virtual EGLint GetPlatformVisualID() const = 0;             ///< return the platform visual ID to match in EGL Config
    };
    /// @}
}

#endif