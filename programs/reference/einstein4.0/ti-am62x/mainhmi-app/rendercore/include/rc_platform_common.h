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
//  Filename    : rc_platform_common.h
//  Description : Platform specific common APIs
//  Created on  : 20-Feb-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_platform_common_h
#define rc_platform_common_h

#include <chrono>
#include <memory>
#include "rc_platform_ws.h" 

namespace rendercore_engine
{
    class gfx3dTexture2D;
    /// <summary>
    /// Platfrom specific implementation for reading a file as binary
    /// </summary>
    /// <param name="p_path">path to the file to be read</param>
    /// <param name="p_sizeout">reference to a location where the read file size to be written</param>
    /// <returns>pointer to the read binary data</returns>
    extern const CHAR8* RcReadWholeFile(const std::string& p_path, size_t& p_sizeout);
    /// <summary>
    /// Platfrom specific implementation for checking if a file exists
    /// </summary>
    /// <param name="p_path">path to the file to be read</param>
    /// <returns>true if file exists, else false</returns>
    extern bool RcFileExists(const std::string& p_path);
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)		
    /// \ingroup Internal
    /// @{
    /// <summary>	
    /// contains the shared EGL information 
    /// < / summary>	
    struct eglShared
    {
        EGLDisplay rcEglDisplay = EGL_NO_DISPLAY;	///<display object
        EGLConfig rcEglConfig = nullptr;		    ///<config object
        EGLSurface rcEglSurface = EGL_NO_SURFACE;	///<surface object
        EGLContext rcEglContext = EGL_NO_CONTEXT;	///<context object
    };
    /// @}
#endif
    class gfx3d_scg_display;

    /// \ingroup Internal
    /// @{

    /// <summary>	
    /// generic platform window class
    /// < / summary>	

    class rc_generic_ws
    {
    protected:
        /// for the performance monitoring..
        std::chrono::time_point<std::chrono::high_resolution_clock> frameStartTick = std::chrono::high_resolution_clock::now();
        /// for the performance monitoring..
        std::chrono::time_point<std::chrono::high_resolution_clock> framePrevTick = std::chrono::high_resolution_clock::now();
        uint64_t frameCounter = 0U;		///< for the performance monitoring..
        float32_t fpsAverage = 0.0F;	///< average fps of engine
        float32_t fps = 0.0F;			///< fps value
        float32_t frameDuarion = 0.0F;  ///< frame duration
#if defined(__EMSCRIPTEN__)
        EGLNativeWindowType nativeWindow = static_cast<EGLNativeWindowType>(0);	///<native window
#else
        EGLNativeWindowType nativeWindow = static_cast<EGLNativeWindowType>(nullptr);	///<native window
#endif
        EGLNativeDisplayType deviceContext = static_cast<EGLNativeDisplayType>(0);	    ///<native display context
    private:
        size_t rcDisplayID = 0U;
        rcwinUserEvent  user_event;		///< user event 
        uint64_t timeline = 0U;			///< timeline in ms
        std::chrono::high_resolution_clock::time_point lastTick;///< timeline last entry at
        IRcWinUserEventCbSp uv_callback = nullptr;  ///< call back for user events 
        gfx3d_scg_display* display = nullptr;    ///< parent display node
        rtColorDepthE colorSize = rtColorDepthE::wcColor32bpp;  ///< 16, 24 or 32bits
        uint32_t depthSize = 24U;            ///< 16 or 24
        GLint wX = 0;                       ///< window x
        GLint wY = 0;                       ///< window y
        GLsizei wWidth = 1920;              ///< window width
        GLsizei wHeight = 720;              ///< widnow height
        uint32_t msaaLevel = 0U;             ///< 0/1/2/3/4
        bool bOpened = false;				///< is opened
        bool bFRTimerActive = false;        ///< FRT is active or not
        bool bFRTimerReset = true;          ///< FRT should be reset or not
        bool bpropChanged = false;          ///< Any of the winodw property changed or not
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
        eglShared eglSh;                    ///< Data storage for shared rcEglContext
#endif
        EGLDisplay rcEglDisplay = EGL_NO_DISPLAY;   ///<display object
        EGLConfig rcEglConfig = static_cast<EGLConfig>(nullptr);    ///<config object
        EGLSurface rcEglSurface = EGL_NO_SURFACE;   ///<surface object
        EGLContext rcEglContext = EGL_NO_CONTEXT;   ///<context object
        /// Default EGL attributes.. First 7 settings are controlled by application
        EGLint configurationAttributes[21]
        {
            // 7 settings touched during init : based on user settings
            EGL_RED_SIZE, 8,
            EGL_GREEN_SIZE, 8,
            EGL_BLUE_SIZE, 8,
            EGL_ALPHA_SIZE, 8,
            EGL_DEPTH_SIZE, 24,
            EGL_SAMPLE_BUFFERS, 1,
            // MSAA Disabled by default (Win32 sim has EGL init failure when enables. So leaving it for application configuration).
            EGL_SAMPLES, 0,
            // untouched part
            EGL_STENCIL_SIZE, EGL_DONT_CARE,
            EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
            EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
            EGL_NONE
        };
        const EGLint contextAttributes[3]
        {
#if (GLES3_RENDERER >= 30)
            EGL_CONTEXT_CLIENT_VERSION, 3,
#else
            EGL_CONTEXT_CLIENT_VERSION, 2,
#endif
            EGL_NONE
        };
        std::shared_ptr<rc_platform_window> platformWindow = nullptr;
        EGLBoolean choose_config(const EGLDisplay p_display, const EGLint* const p_attributes, EGLConfig * const p_config);
    public:
        ///set size of window
        void SetSize(const GLint p_x, const GLint p_y, const GLsizei p_width, const GLsizei p_height);
        ///set render property
        void SetProperty(const uint32_t p_msaaLevel, const rtColorDepthE p_colorSize, const uint32_t p_depthSize);
        ///constructor
        rc_generic_ws(gfx3d_scg_display* const p_parent);
        rc_generic_ws(gfx3d_scg_display* const p_parent, std::shared_ptr<rc_platform_window> p_pwin);
        virtual ~rc_generic_ws();
        rc_generic_ws& operator= (const rc_generic_ws&) = delete;
        rc_generic_ws(const rc_generic_ws&) = delete;
        /// update
        virtual bool Update(void);
        ///open
        virtual bool Open(const size_t p_id);
        ///close 
        virtual bool Close(void);
        ///swap
        virtual bool Swap(const bool p_changed);
        ///make current
        virtual bool MakeCurrent(void);
        ///get frame rate count, in ms
        uint64_t GetFRTimerCountMS(void) const;
        ///get frame rate timer val
        float32_t GetFRTimerValue(void) const;
        ///Starts the FRTimer. Timer will be at stop state after init.
        void StartFRTimer();
        ///Stops the FRTimer. Timer will be at stop state after init.
        void StopFRTimer(void);
        ///Resets the FRTimer. Timer will start from 0 if when it starts.
        void ResetFRTimer();
        ///register user event
        void RegisterUEventCb(IRcWinUserEventCbSp p_uv_cb);
        ///called when user quits
        void PostQuit(void);
        ///called when user clicks on menu
        void PostMenu(const rcwinUETypeE p_ev, const size_t p_key);
        ///call to pass mouse event to rendercore
        void PostMouse(const rcwinUETypeE p_ev, const int32_t p_x, const int32_t p_y, const float32_t p_delta);
        ///call to pass multi touch events to rendercore
        void PostTouch(const rcwinUserEvent& p_data);
        /// <summary>
        /// Posts a Gesture event 
        /// </summary>
        /// <param name="p_touch_data">gesture data</param>
        void PostGesture(const rc_gesture_data& p_gest_data);
        ///called when any keys are pressed
        void PostKey(const rcwinUETypeE p_ev, const GLuint p_key);
        ///gives the current frame duration
        float32_t GetFrameDuration(void) const;
        ///gives the current fps
        float32_t GetFps(void) const;
        ///gives the average fps
        float32_t GetAverageFps(void) const;
        ///gives the current frame counter
        uint64_t GetFrameCounter(void) const;
        /// <summary>
        /// Function to return pointer of the parent display
        /// </summary>
        /// <returns>pointer to the parent</returns>
        gfx3d_scg_display* GetParent() const;
        /// <summary>
        /// Function to check if window is open
        /// </summary>
        /// <returns>true if window is open, false otherwise</returns>
        bool IsOpened() const;
        /// <summary>
        /// Set true if window is open, false otherwise
        /// </summary>
        /// <param name="p_opened">Set true if window is open, false otherwise</param>
        void SetOpened(const bool p_opened);
        /// <summary>
        /// Function to get x-coordinate of pixel of top left corner of window
        /// </summary>
        /// <returns>x-coordinate of pixel of top left corner of window</returns>
        GLint GetX() const;
        /// <summary>
        /// Set x-coordinate of pixel of top left corner of window
        /// </summary>
        /// <param name="p_x">x-coordinate of pixel of top left corner of window</param>
        void SetX(const GLint p_x);
        /// <summary>
        /// Function to get y-coordinate of pixel of top left corner of window
        /// </summary>
        /// <returns>y-coordinate of pixel of top left corner of window</returns>
        GLint GetY() const;
        /// <summary>
        /// Set y-coordinate of pixel of top left corner of window
        /// </summary>
        /// <param name="p_y">y-coordinate of pixel of top left corner of window</param>
        void SetY(const GLint p_y);
        /// <summary>
        /// Function to get width of window
        /// </summary>
        /// <returns>window width</returns>
        GLsizei GetWidth() const;
        /// <summary>
        /// Set Window width
        /// </summary>
        /// <param name="p_width">Window width</param>
        void SetWidth(const GLsizei p_width);
        /// <summary>
        /// Function to get height of window
        /// </summary>
        /// <returns>window height</returns>        
        GLsizei GetHeight() const;
        /// <summary>
        /// Set window height
        /// </summary>
        /// <param name="p_height">Window height</param>
        void SetHeight(const GLsizei p_height);
        /// <summary>
        /// Set MSAA level config
        /// </summary>
        /// <param name="p_level">MSAA level config</param>
        void SetMSAALevel(const uint32_t p_level);
        /// <summary>
        /// Function to get msaa level
        /// </summary>
        /// <returns>msaa level</returns>  
        uint32_t GetMSAALevel() const;
        /// <summary>
        /// Set color size config
        /// </summary>
        /// <param name="p_colorSize">color size config</param>
        void SetColorSize(const rtColorDepthE p_colorSize);
        /// <summary>
        /// Function to get color size
        /// </summary>
        /// <returns>color size</returns>  
        rtColorDepthE GetColorSize() const;
        /// <summary>
        /// Function to get depthsize config
        /// </summary>
        /// <returns>depthsize config</returns>  
        uint32_t GetDepthSize() const;
        /// <summary>
        /// Set depth size config
        /// </summary>
        /// <param name="p_depthSize">Depth Size config</param>
        void SetDepthSize(const uint32_t p_depthSize);
        /// <summary>
        /// get the native EGL window type. To be implemented by user
        /// </summary>
        virtual EGLNativeWindowType GetNativeWindow() const;
        /// <summary>
        /// get the EGL display object
        /// </summary>
        EGLDisplay GetEGLDisplay() const;
        /// <summary>
        /// get native EGL display type
        /// </summary>
        EGLNativeDisplayType GetNativeDisplayType() const;
        /// <summary>
        /// get the EGL context
        /// </summary>
        EGLContext GetEGLContext() const;
        /// <summary>
        /// set the timeline to p_timeline
        /// <param name="p_timeline">timeline</param>
        /// </summary>
        void SetTimeline(const uint64_t p_timeline);
        /// <summary>
        /// checks if timeline is running, returns a bool
        /// </summary>
        bool IsTimelineRunning() const;
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
        /// <summary>
        /// create EGL shared context
        /// </summary>
        void CreateEglSharedContext(void);
#endif
        /// <summary>
        /// setup the EGL context
        /// </summary>
        EGLBoolean setupEGLContext(void);
        /// <summary>
        /// Invokes internally when there is a change in Native window handle
        /// Tries to recreates the window surface for the new native window
        /// Returns true when the call succeeds. false on any error
        /// </summary>
        bool onNativeWindowChange(void);
        /// <summary>
        /// create the EGL surface
        /// </summary>
        bool createEGLSurface(void);
        /// <summary>
        /// choose EGL config
        /// </summary>
        EGLBoolean chooseEGLConfig(void);
        /// <summary>
        /// create the EGL display
        /// </summary>
        EGLBoolean createEGLDisplay(void);
        /// <summary>
        /// create the native EGL window. To be implemented by user
        /// </summary>
        virtual bool createNativeWindow(void);
        /// <summary>
        /// release the native EGL state
        /// </summary>
        void releaseEGLState(void);
        /// <summary>
        /// Grabs the current framebuffer contents to passed texture 2D object.
        /// </summary>
        /// <param name="p_tex2d">A texture 2D object to which the image to be loaded</param>
        /// <param name="p_direct">If true tries to use direct texture extensions if available</param>
        /// <returns></returns>
        bool FrameGrab(gfx3dTexture2D* const p_tex2d, const bool p_direct) const;
    };
    /// @}
}

#endif
