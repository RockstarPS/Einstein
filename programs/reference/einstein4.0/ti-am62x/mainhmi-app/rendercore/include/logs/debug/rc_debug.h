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
//  Filename    : rc_debug.h
//  Description : debug interfaces..
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file	rc_debug.h
///	\brief 		debug interfaces..
#ifndef rc_debug_h
#define rc_debug_h

#include <map>
#include <thread>

#if !defined(TRACY_ENABLE)
#define TracySetThreadName(x)
#else
#define TracySetThreadName(x) tracy::SetThreadName(x)
#endif

#if defined(RC_PROFILE)
/// <summary>
/// Generate the profile information with time stamp values
/// </summary>
#define RC_FPSTART(x_tag)           rendercore_engine::DebugMeasure fl_mes ## x_tag((#x_tag))
#define RC_FPBYTES(x_tag, x_bytes)  (fl_mes ## x_tag).SetBytes((x_bytes))
#define RC_FPSTARTM(x_tag, x_msg)   rendercore_engine::DebugMeasure fl_dbgfpmes ## x_tag((#x_tag), (x_msg))
#define RC_FPBYTESM(x_tag, x_bytes) (fl_dbgfpmes ## x_tag).SetBytes((x_bytes))
#define RC_PROF_PRINT(x)            rendercore_engine::RcProfilerPrint(x)
#define RESET_GL_PROFILE()      rendercore_engine::RcResetGLProfileData()		///< reset the OpenGL profile data
/// <summary>
/// If there are error detected in gl calls, print the gl call and the error code
/// </summary>
#define GLCALL(call)\
do{\
    if(RcIsGLCallProfileEnabled())\
    {\
       DebugMeasure fl_ms(nullptr);\
	   (call);\
       float32_t fl_cticks;\
       float32_t fl_duration;\
       fl_ms.Measure(fl_cticks, fl_duration);\
       RcDebugGLCallProfile(#call, fl_cticks, fl_duration);\
    }\
    else\
    {\
        RcDebugGLCallProfile(#call);\
        (call);\
    }\
    RcDebugHandleGLError(#call);\
}while(0)

#define EGLCALL(call) \
do{\
    if(RcIsGLCallProfileEnabled())\
    {\
       DebugMeasure fl_ms(nullptr);\
	   (call);\
       float32_t fl_cticks;\
       float32_t fl_duration;\
       fl_ms.Measure(fl_cticks, fl_duration);\
       RcDebugEGLCallProfile(#call, fl_cticks, fl_duration);\
    }\
    else\
    {\
        (call);\
    }\
    RcDebugHandleEGLError(#call);\
}while(0)
#else
#define RC_FPSTART(x_tag)
#define RC_FPBYTES(x_tag, x_bytes)
#define RC_FPSTARTM(x_tag, x_msg)
#define RC_FPBYTESM(x_tag, x_bytes)
#define RC_PROF_PRINT(x)
#define RESET_GL_PROFILE()
#define GLCALL(call) \
do{\
	(call);\
    RcDebugHandleGLError(#call);\
}while(0)
#define EGLCALL(call) \
do{\
	(call);\
    RcDebugHandleEGLError(#call);\
}while(0)
#endif

#if defined(RC_DEBUG_MSG) || defined(RC_PROFILE)
#define SUPPRESS_LOG_REPEATS(x) rendercore_engine::RcSuppressRepeatedLogs((x))  ///< suppress or allow repeated logs
#define IS_LOGONCE()            rendercore_engine::RcGetRepeatedLogsControl()   ///< is logs suppressed from repeating
#else
#define SUPPRESS_LOG_REPEATS(x)
#define IS_LOGONCE() false
#endif
#if defined(RC_DEBUG_MSG)
#define LOG_DISABLE_ALL()       rendercore_engine::RcFilteredlogDisable()		///< disable all logs				
#define LOG_DISABLE(x)          rendercore_engine::RcFilteredlogDisable(x)		///< disable specific log
#define LOG_ENABLE(x)           rendercore_engine::RcFilteredlogEnable(x)		///< enable specific log
#define RC_SET_THREAD_NAME(x)   TracySetThreadName(x);\
                                RcDebugSetThreadName(x)
#else //if defined(RC_DEBUG_MSG)
#define LOG_DISABLE_ALL()		///< disable all logs
#define LOG_DISABLE(x)			///< disable specific log
#define LOG_ENABLE(x)			///< enable specific log
#define RC_SET_THREAD_NAME(x)   TracySetThreadName(x);\
                                RcDebugSetThreadName(x)
#endif
#define LOG(...)  rendercore_engine::RcDebugFilteredlog(RC_FILENAME, rendercore_engine::rc_message_type::mtMsg, __VA_ARGS__)
#if defined(RC_DEBUG_MSG) || defined(RC_DEBUG_IMSG)
#define ILOG(...) rendercore_engine::RcDebugFilteredlog(RC_FILENAME, rendercore_engine::rc_message_type::mtInfo, __VA_ARGS__)
#else
#define ILOG(...)
#endif
#if defined(RC_DEBUG_MSG) || defined(RC_DEBUG_WMSG)
#define WLOG(...) rendercore_engine::RcDebugFilteredlog(RC_FILENAME, rendercore_engine::rc_message_type::mtWarn, __VA_ARGS__)
#else
#define WLOG(...)
#endif
#if defined(RC_DEBUG_MSG) || defined(RC_DEBUG_EMSG)
#define ELOG(p_msg) rendercore_engine::RcDebugLog(RC_FUNCTION, rendercore_engine::rc_message_type::mtErr, (p_msg))
#else
#define ELOG(p_msg)
#endif

#define LOG_RENDERLIST(x) RcDebugLogRenderList(x)
#define CLEAR_RENDERLIST() RcDebugClearRenderList()
#define GET_RENDERLIST() RcDebugGetRenderList()

namespace rendercore_engine
{
    class gfx3d_scg_scene;
    /// \defgroup Debug Debug functions
    /// <summary>
    /// Provides APIs for debugging..
    /// </summary>
#if defined(RC_PROFILE)
    class DebugMeasure
    {
    private:
        std::string tag;
        std::string msg;
        std::chrono::high_resolution_clock::time_point stime;
        std::chrono::high_resolution_clock::time_point etime;
        size_t sptick = 0;
        size_t eptick = 0;
        size_t epticklow = 0;
        size_t bytes = 0;
        bool active = false;
    public:
        DebugMeasure(const char* p_tag, const char* p_msg = nullptr);
        DebugMeasure(const char* p_tag, const std::string p_msg);
        void Measure(float32_t& p_pgm, float32_t& p_elap);
        void SetBytes(const size_t p_bytes);
        ~DebugMeasure();
    };
    void RcProfilerPrint(const float64_t p_threshold);
    /// profler init with scg project	
    void RcProfilerInit(const gfx3d_scg_project* const p_proj);
    /// resets gl call profiles
    void RcResetGLProfileData();
    /// enables GL call profiling
    void RcEnableGLCallProfile(const bool p_value);
    /// check if GL call profiling enabled or not
    bool RcIsGLCallProfileEnabled();
    /// <summary>
    /// Performs and updates profiling data for EGL calls
    /// </summary>
    /// <param name="p_msg">EGL call syntax</param>
    /// <param name="p_pgm">cpu time</param>
    /// <param name="p_elap">elapsed time</param>
    void RcDebugEGLCallProfile(const CHAR8* p_msg, float32_t p_pgm, float32_t p_elap);
    /// <summary>
    /// Performs and updates profiling data for GL calls
    /// </summary>
    /// <param name="p_msg">GL call syntax</param>
    /// <param name="p_pgm">cpu time</param>
    /// <param name="p_elap">elapsed time</param>
    void RcDebugGLCallProfile(const CHAR8* p_msg, float32_t p_pgm, float32_t p_elap);
    void RcDebugGLCallProfile(const CHAR8* p_msg);
    const std::map<std::string, int32_t>& RcGetGLCallProfileData();
#endif
    size_t RcDebugGetTotalMemory();
    float64_t RcDebugGetCPUPer();
    void RcDebugSetTotalVertices(const GLenum p_mode, const size_t p_vcount);
    size_t RcDebugGetTotalVertices();
    size_t RcDebugGetTotalTriangles();
    size_t RcDebugGetTotalDrawCalls();
    /// <summary>
    /// Prints the node hierarichy to console for debug purpose
    /// </summary>
    void RcDebugPrintNodeHierarichy(const gfx3d_scg_node* const p_node);
    /// <summary>
    /// Prints the node hierarichy to console for debug purpose
    /// </summary>
    void RcDebugPrintSceneHierarichy(const gfx3d_scg_scene* const p_scene);
    const std::map<std::string, bool>& RcGetFilteredLogList();
    /// <summary>
    /// Logs the EGL error message if any
    /// </summary>
    /// <param name="p_msg">EGL call</param>
    void RcDebugHandleEGLError(const CHAR8* p_msg);
    /// <summary>
    /// Logs the GL error message if any
    /// </summary>
    /// <param name="p_msg">EGL call</param>
    void RcDebugHandleGLError(const rendercore_engine::CHAR8* p_msg);
    std::string RcDebugGetThreadName(const std::thread::id p_thid);
    void RcDebugSetThreadName(const std::string& p_name);
    /// global enable log
    void RcFilteredlogEnable(const bool p_en);
    /// enable log for a tag 
    void RcFilteredlogEnable(const CHAR8* p_tag);
    /// disable log for a tag or globally disable for all tags
    bool RcFilteredlogDisable(const CHAR8* p_tag);
    /// global disable logs
    bool RcFilteredlogDisable(void);
    /// <summary>
    /// Globally supress or allow repeated log messages
    /// </summary>
    /// <param name="p_enable">true to suppress repeated messages</param>
    void RcSuppressRepeatedLogs(bool p_enable);
    /// <summary>
    /// Get the current seection of RcSuppressRepeatedLogs
    /// </summary>
    /// <returns>true or false</returns>
    bool RcGetRepeatedLogsControl();
    /// filtered message log to console and moves the curser to next line
    void RcDebugFilteredlogLine(const CHAR8* const p_tag, const rc_message_type p_msg, rc_string p_log);
    /// filtered and formatted message log to console
    void RcDebugFilteredlog(const CHAR8* const p_tag, const rc_message_type p_msg, const CHAR8* p_fmt, ...);
    void RcDebugListAvailableEGLConfigs(const EGLDisplay p_display, EGLint* p_reqConfig, const EGLint p_regConfigSize, const rtColorDepthE p_colordepth, const uint32_t p_depth, const uint32_t p_msaa);
    void RcDebugPrintEGLConfig(const EGLDisplay p_dpy, const EGLint p_numConfigs, const EGLConfig* const p_config, EGLint* p_reqConfig, const EGLint p_regConfigSize);
    void RcDebugPrintGLInfo(const EGLDisplay p_dpy);
    void RcDebugWritePpm(const CHAR8* p_filename, const int32_t p_w, const int32_t p_h, CHAR8* const p_pixels, const int32_t p_compSize);
    void RcDebugLogRenderList(const gfx3d_render_list& p_rlist);
    void RcDebugClearRenderList();
    std::vector<gfx3d_render_list>& RcDebugGetRenderList();
    /// @}
}
#endif