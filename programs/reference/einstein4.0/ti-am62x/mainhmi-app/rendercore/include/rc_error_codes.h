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
//  Filename    : rc_error_codes.h
//  Description : Error codes and logging
//  Created on  : 21-Jul-2021 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_error_codes_h
#define rc_error_codes_h

#include <mutex>
#include <bitset>

namespace rendercore_engine
{
    enum class rcErrorCode
    {
        /// <summary>
        /// Initialization failed (native window / EGL context)
        /// </summary>
        ecInitFailed,
        /// <summary>
        /// EGL Swap buffer operation failed
        /// </summary>
        ecSwapFailed,
        /// <summary>
        /// Memory allocation attempt is failed
        /// </summary>
        ecMemoryAllocFailed,
        /// <summary>
        /// A gl GL_OUT_OF_MEMORY error is being reported
        /// </summary>
        ecGLCritical,
        /// <summary>
        /// Any of the below EGL errors are being reported
        /// EGL_NOT_INITIALIZED,EGL_BAD_ALLOC,EGL_BAD_DISPLAY,EGL_BAD_SURFACE,EGL_CONTEXT_LOST
        /// </summary>
        ecEGLCritical,
        /// <summary>
        /// Total number of error codes
        /// </summary>
        ecMaxErrorCode
    };
    /// <summary>
    /// Maintains the error codes which are reported by engine
    /// Only critical errors that affect the functionality is maintained
    /// Application must periodically monitor for errors and recover by
    /// restarting the rendercore application if errors are present
    /// </summary>
    class rcErrorReport
    {
    private:
        std::bitset<static_cast<size_t>(rcErrorCode::ecMaxErrorCode)> errFlags;
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
        std::recursive_mutex writeMutex;
#endif
    protected:
        /// <summary>
        /// Sets the error code (internally invoked)
        /// </summary>
        /// <param name="p_code">error code to set</param>
        void set_error(const rcErrorCode p_code);
        /// <summary>
        /// Check for any GL and EGL errors and sets the code if active
        /// This is internally invoked..
        /// </summary>
        void update_gl_errors();
    public:
        /// <summary>
        /// Clears the error code
        /// </summary>
        /// <param name="p_code">error code to clear</param>
        void ClearError(const rcErrorCode p_code);
        /// <summary>
        /// Check if an error code is active
        /// </summary>
        /// <param name="p_code">error code to check</param>
        /// <returns>true if error is present</returns>
        bool IsErrorPresent(const rcErrorCode p_code) const;
        /// <summary>
        /// Check if any error code is active
        /// </summary>
        /// <returns>true if any error is present</returns>
        bool IsAnyErrorPresent() const;
    };
}

#endif
