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
///  @file    : rc_mt_decoder.h
///  @brief   : Support function to decode images by multiple threads
///             to enable parallel decoding
//  Created on  : 02-Jul-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_mt_decoder_h
#define rc_mt_decoder_h

#if (RC_MTHREADS & RC_MTHREAD_IMGDECODE) != 0
#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <atomic>
#include <deque>

namespace rendercore_engine
{
    /// \ingroup Internal
    /// @{

    /// <summary>
    /// rc_mt_decoder helper class allows the rendercore to decode
    /// images in parallel using multiple threads. The maximum number
    /// of threads that can run in parallel is restricted by a compiler
    /// switch RC_MAX_DECODER_TASKS which can range from 1 to N
    /// </summary>
    class rc_mt_decoder
    {
    private:
        uint32_t maxThreadCount = 0U;           ///< holds the maximum number of worker threads to be used
        std::deque<gfx3d_scg_image *> queue;    ///< queue for image object waiting to be decoded 
        std::mutex data_mutex;                  ///< mutex to protect all data access by threads
        std::condition_variable data_condVar;   ///< event to be set when 
                                                ///< 1. there is new data added to queue or
                                                ///< 2. when any worker thread has finished
        std::condition_variable thread_condVar;     ///< event to be set when any worker thread has finished
        std::vector <std::thread> decoder_threads;  ///< holds the decoder worker thread object
        std::atomic_bool bdt_terminate{ false };    ///< indicates whether the thred need to terminate or not.
        volatile size_t activethreads = 0U;         ///< indicates active threads, if the decoder is busy or not..
        /// <summary>
        /// decoder worker thread entry point
        /// </summary>
        void decoder_th(void);
    public:
        /// <summary>
        /// constructor
        /// </summary>
        explicit rc_mt_decoder(const uint32_t p_maxTh);
        /// <summary>
        /// destructor
        /// </summary>
        ~rc_mt_decoder();
        /// <summary>
        /// Adds a decoder request for an image in to the queue.
        /// </summary>
        /// <param name="p_data">image object to be decoded</param>
        void Decode(gfx3d_scg_image * const p_src_image);
        /// <summary>
        /// Returns the busy state of the decoder. If all requested images are
        /// decoded then returns true. Else returns false.
        /// </summary>
        /// <returns>true if busy, false if not</returns>
        bool IsBusy(void);
        /// <summary>
        /// If the decoder is busy, then waits for atleast one worker thread to finish
        /// returns if not busy or any worker thread finished operation.
        /// Note : it doesnot says if an image is completed or not. It just says if the 
        /// threads are busy doing decoding or not. When an input image is specified,
        /// the wait returns when one of the thread finishes. Its callers responsibility
        /// to check the images status to see if its decoding is completed.
        /// </summary>
        /// <param name="p_src_image">
        /// the image which needs to be checked for completion. 
        /// If the image is still in the queue waiting for decode, then this call will 
        /// move the image to top of the queue to make it high priorty (i.e. when 
        /// any one thread finishes, the top of the queue is what is scheduled)</param>
        /// <param name="p_timeout_ms">a timeout in milli seconds to break the wait and return
        /// if no worker threads finishes. A value of zero (default) means indefinite wait.</param>
        /// <returns>true if busy, false if not</returns>
        bool Wait(gfx3d_scg_image * const p_src_image = nullptr, const size_t p_timeout_ms = 0U);
        /// <summary>
        /// Returns the maximum number of threads to be used for decoding.
        /// return of 0 means there is no HW threading support for decoding..
        /// </summary>
        /// <returns>maximum number of threads available (>=0) </returns>
        size_t GetMaxThreads(void) const;
        /// <summary>
        /// Returns the active number of threads decoding.
        /// return of 0 means there no threads decoding..
        /// </summary>
        /// <returns>number of threads performing decode</returns>
        size_t GetActiveThreads(void) const;
    };
    /// @}
}
#endif /*#if (RC_MTHREADS & RC_MTHREAD_IMGDECODE) != 0*/
#endif