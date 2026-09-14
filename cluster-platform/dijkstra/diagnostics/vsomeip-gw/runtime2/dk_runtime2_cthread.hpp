/**
 * VISTEON CORPORATION CONFIDENTIAL
 * ________________________________
 *
 * [2018] Visteon Corporation
 * All Rights Reserved.
 *
 * NOTICE: This is an unpublished work of authorship, which contains trade secrets.
 * Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
 * its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
 * or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
 * in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
 * under all copyright laws to protect this work as a published work, when appropriate.
 * Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
 * without the written authorization of Visteon Corporation.
 */

#ifndef ART_PROC_CTHREAD_HPP
#define ART_PROC_CTHREAD_HPP

#include <iostream>
#include <thread>
#include <atomic>
#include <functional>
#include <chrono>

#ifdef ART_EXPORT_LIB
    #ifndef ART_EXPORT
    #define ART_EXPORT   __declspec( dllexport )
    #endif
#else
    #ifndef ART_EXPORT
    #define ART_EXPORT
    #endif
#endif

namespace dk{
namespace runtime2{
namespace core{

class CThread
{
public:
    typedef std::function<void()> cbk_t;

    explicit CThread(cbk_t cbk, unsigned periodMs ) noexcept :
            cbk(cbk), periodMs(periodMs), th(nullptr)
    {
         requestStop.store(false);
         isRunning.store(false);
    }

    virtual void start() noexcept
    {
        try
        {
            th = new std::thread(run, this);
        }
        catch( std::exception & ex )
        {
            std::cerr << ex.what() << std::endl;
            th = nullptr;
        }
    }

    virtual void stop() noexcept
    {
        if ( th )
        {
            try
            {
                requestStop.store(true);
                th->join();
                delete th;
                th = nullptr;
            }
            catch( std::exception & ex )
            {
                std::cerr << ex.what() << std::endl;
            }
        }
    }

    bool getIsRunning() noexcept
    {
        return isRunning.load();
    }
private:
    cbk_t cbk;

    unsigned periodMs;

    std::thread * th;
    std::atomic_bool isRunning;
    std::atomic_bool requestStop;

    static void run(CThread * instance) noexcept
    {
        if (instance != nullptr)
        {
            instance->isRunning.store(true);
            instance->requestStop.store(false);

            while (!instance->requestStop.load())
            {
                instance->cbk();

                if ( instance->periodMs != 0 )
                {
                    waitMs( instance->periodMs );
                }
                else
                {
                    std::this_thread::yield();
                }
            }

            instance->isRunning.store(false);
            instance->requestStop.store(false);
        }
    }
public:
    static void waitMs ( unsigned ms ) noexcept
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    };
};

}   // namespace dk
}   // namespace runtime2
}   // namespace core

#endif  //ART_PROC_CTHREAD_HPP
