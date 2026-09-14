
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

#ifndef ART_PROC_CSEMAPHORE_HPP
#define ART_PROC_CSEMAPHORE_HPP

#include <mutex>
#include <condition_variable>
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

class  CSemaphore
{
private:
    unsigned int count;
	std::mutex mutex;
    std::condition_variable condition;

public:
    inline CSemaphore(unsigned int uiCount)
       : count(uiCount) { }

    inline void wait()
    {
        std::unique_lock< std::mutex > lock(mutex);
        condition.wait(lock,[&]()->bool{ return count>0; });
        --count;
    }

    bool wait( const unsigned ms )
    {
        std::unique_lock< std::mutex > lock(mutex);
        if (!condition.wait_for(lock,std::chrono::milliseconds(ms),[&]()->bool{ return count>0; }))
            return false;
        --count;
        return true;
    }

    inline void signal()
    {
        std::unique_lock< std::mutex > lock(mutex);
        ++count;
        condition.notify_one();
    }
};

}   // namespace dk
}   // namespace runtime2
}   // namespace core

#endif //ART_PROC_CSEMAPHORE_HPP
