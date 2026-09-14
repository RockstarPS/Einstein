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
/// @file       worker_thread.h
/// \brief      Implements worker thread support. 
///             Initial code is leverage from source : 
///             https://www.codeproject.com/Articles/1085494/A-Simple-Worker-Thread
///             and modified to meet Mainly threading concept for rendercore. 
///             Three threads will be used
///             1. Thread 1 :- for graphics rendering
///             2. Thread 2 :- for graphics background loading activities (shares EGL context with Thread 1)
///             3. Thread 3 :- for general activities
//              Created on  : 27-Sep-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef worker_thread_h
#define worker_thread_h

#include "gfx3d_config.h"
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
#include <functional>
#include <list>
#include <memory>
#endif

namespace rendercore_engine
{
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
    class RcWorkerThread;
    /// \ingroup Internal
    /// @{
    /// Worker thread type ID
    enum class RcWTType
    {
        Unset,
        MainGlOp,
        BgndGlOp,
        GeneralOp
    };
    /// @}
    /// \ingroup Internal
    /// @{
    /// Status of Tasks queued to Worker thread
    enum class WTStatus
    {
        Inactive,   ///< init state
        Queued,     ///< Task is queued
        Running,    ///< task is executing
        Completed,  ///< Task is completed
        Error       ///< indicating error
    };
    /// @}
    /// \ingroup Internal
    /// @{
    class WTAsyncTaskT
    {
    private:
        volatile bool highPrio = true;
        RcWorkerThread* parent = nullptr;
        volatile WTStatus status = WTStatus::Inactive;
        std::function<void()> task;
        friend class RcWorkerThread;
    public:
        WTAsyncTaskT(RcWorkerThread* const p_parent, const std::function<void()>& p_task, const bool p_highpriority = true);
        /// waits for the tasks completion and returns true
        /// incase of error conditions, returns false (task may not be complete)
        /// - currently error occurs if the WaitForCompletion() is invoked from same thread as task()'s thread.
        bool WaitForCompletion() const;
        // Returns true if task is busy (either queued or is running)
        bool IsBusy() const;
    };
    /// @}
    /// \ingroup Internal
    /// @{
    using WTAsyncTask = std::shared_ptr<WTAsyncTaskT>;
#endif
    class rc_mt_decoder;
    class RcMTTasking
    {
    private:
#if (RC_MTHREADS & RC_MTHREAD_IMGDECODE) != 0
        /// multi threaded image decode support..
        rc_mt_decoder* lmtDecoder = nullptr;///< multi threaded image decode support..
#endif
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
        RcWorkerThread* lGlMainOpTask = nullptr;
        RcWorkerThread* lGlBgndOpTask = nullptr;
        RcWorkerThread* lGenerlOpTask = nullptr;
    public:
        /// Main worker thread for rendering. EGL context is owned by this thread
        /// this API allows to asynchronously execute / submit a task
        /// returns a task pointer which can be used to track the completion
        WTAsyncTask WTDoAsyncGlMainOpTask(const std::function<void()>& p_task);
        /// Main worker thread for rendering. EGL context is owned by this thread
        /// this API allows synchronously execute something in renderer context
        void WTDoSyncGlMainOpTask(const std::function<void()>& p_task);
        /// Runs a task with background worker (render) thread asynchronously.
        /// Background worker thread for renderer. owns a shared context with 
        /// main renderer.. Will be used to load textures / materials in background
        /// Also to perform general non rendering / opengl activities
        /// CAUTION / Rule : p_task shall not perform any synchronous GlMainOpTask operations. 
        ///                  (WTDoSyncGlMainOpTask or  WTDoAsyncGlMainOpTask with WTAsyncTask::WaitForCompletion())
        ///                  It can cause a deadlock  
        WTAsyncTask WTDoAsyncGlBgndOpTask(const std::function<void()>& p_task);
        /// Runs a low priorty task with background worker (render) thread asynchronously.
        /// Low priority tasks are ran only when there are no high priority tasks waiting
        /// in queue.
        /// CAUTION / Rule : p_task shall not perform any synchronous GlMainOpTask operations. 
        ///                  (WTDoSyncGlMainOpTask or  WTDoAsyncGlMainOpTask with WTAsyncTask::WaitForCompletion())
        ///                  It can cause a deadlock  
        WTAsyncTask WTDoAsyncLowPrioGlBgndOpTask(const std::function<void()>& p_task);
        /// Background worker thread for rendering. owns a shared context
        /// this API allows synchronously execute something in Background renderer context
        /// CAUTION / Rule : p_task shall not perform any synchronous GlMainOpTask operations. 
        ///                  (WTDoSyncGlMainOpTask or  WTDoAsyncGlMainOpTask with WTAsyncTask::WaitForCompletion())
        ///                  It can cause a deadlock  
        void WTDoSyncGlBgndOpTask(const std::function<void()>& p_task);
        /// Worker thread to perform general non rendering / opengl activities
        WTAsyncTask WTDoAsyncGenerlOpTask(const std::function<void()>& p_task);
        /// Worker thread to perform general non rendering / opengl activities syncronously
        void WTDoSyncGenerlOpTask(const std::function<void()>& p_task);
        /// Wait for GenerlOpTask to finish all the jobs.
        void WTWaitForGenerlOpTask();
        /// Wait for all threads to finish the jobs.
        void WTWaitForAllCompletion(void);
        /// Terminate all threads.
        void WTTerminateAll(void);
        /// @}
        /// Debug information, check the status of task 
        WTStatus GetGlMainOpTaskState();
        /// Debug information, check the status of task 
        WTStatus GetGlBgndOpTaskState();
        /// Debug information, check the status of task 
        WTStatus GetGenerlOpTaskState();
        /// Debug information, check the status of task 
        size_t GetMaxDecoderTasks();
        size_t GetActiveDecoderTasks();
        /// <summary>
        /// Returns true if the calling thread is a GlMainOp thread 
        /// </summary>
        /// <returns>true or false</returns>
        bool IsGLMainThread();
        /// <summary>
        /// Returns true if the calling thread is a GlBgndOp thread 
        /// </summary>
        /// <returns>true or false</returns>
        bool IsGLBgThread();
        /// <summary>
        /// Returns true if the calling thread is a GlBgndOp or GlMainOp thread 
        /// </summary>
        /// <returns>true or false</returns>
        bool IsGLThread();
        void WTTerminateGenerlOpTask();
        void WTTerminateGlBgndOpTask();
        void WTTerminateGlMainOpTask();
#endif
#if (RC_MTHREADS & RC_MTHREAD_IMGDECODE) != 0
        void WTWaitMTImage(gfx3d_scg_image* const p_img);
        void WTDecodeMTImage(gfx3d_scg_image* const p_img);
        bool WTIsDecodeMTImageBusy(void);
#endif
    };
}
#endif