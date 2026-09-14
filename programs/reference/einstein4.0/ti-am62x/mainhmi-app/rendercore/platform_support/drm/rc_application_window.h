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
//  Filename    : rc_application_window.h
//  Description : Platform specific window creation interface implementation
//  Created on  : 20-Feb-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_application_window_h
#define rc_application_window_h

#include "rc_platform_ws.h" 

namespace rendercore_engine
{
    class rc_win_handles;
    class rc_generic_ws;
    /// \ingroup Internal
    /// @{
    /// Interface class for creating a platform window for the rendercore
    class rc_application_window : public rc_platform_window
    {
    private:
        gfx3d_scg_display* display = nullptr;
    public:
        ~rc_application_window();
        rc_application_window();
        /// <summary>
        /// Called prior to eglSwapBuffers call
        /// </summary>
        /// <param name="p_changed">true indicates there are draw calls issued and swap will be performed</param>
        /// <returns>true will perform a swap, false will prevent the eglSwapBuffers</returns>
        bool Swap(const bool p_changed) override;
        /// <summary>
        /// Called after the eglSwapBuffers
        /// </summary>
        /// <returns>true on success</returns>
        bool FrameEnd() override;
        /// <summary>
        /// Creates the native window. Invoked internally
        /// </summary>
        /// <returns>true on success</returns>
        bool createNativeWindow(void) override;
        /// <summary>
        /// Releases the native window. Invoked internally
        /// </summary>
        void releaseNativeWindow(void) override;
        /// <summary>
        /// Cleanup the native wndow
        /// </summary>
        /// <returns>true on success</returns>
        bool Open(rc_generic_ws* const p_parent) override;
        /// <summary>
        /// Cleanup the native wndow
        /// </summary>
        /// <returns>true on success</returns>
        bool Close(void) override;
        EGLNativeWindowType GetNativeWindow() const override;	///< native window
        EGLNativeDisplayType GetDeviceContext() const override;	///< native display device context
        EGLDisplay GetPlatformDisplay() const override;          ///< get the platform specifc display handle
        EGLint GetPlatformVisualID() const override;             ///< return the platform visual ID to match in EGL Config
    };
    /// @}
}

#endif