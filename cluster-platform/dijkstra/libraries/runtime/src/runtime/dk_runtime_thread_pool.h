//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2017] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//

#ifndef DK_RUNTIME_THREADPOOL_H
#define DK_RUNTIME_THREADPOOL_H

#include <mutex>
#include <vector>
#include "DKOsalThread.h"

namespace dk
{
namespace runtime
{
namespace core
{
struct DkThread : public dk::osal::Thread
{
        std::mutex mMutex;

        osal::ThreadConfigID mThreadConfigId;

        void * ( *pThreadBody ) ( void );
        bool mIsRunning;

        DkThread ( void * ( *pth ) ( void ), osal::ThreadConfigID _id ) :
            mThreadConfigId ( _id ), pThreadBody ( pth ), mIsRunning ( false )
        {
        }
    protected:
        void *run()
        {
            ( void ) pThreadBody();
            return NULL;
        }

};

class ThreadPool : public std::vector<DkThread *>
{
    public:
        void start ( const uint32_t tid ) noexcept;
        void stop ( const uint32_t tid ) noexcept;
        bool getIsRunning ( const uint32_t tid ) noexcept;
};
}
}
}

extern dk::runtime::core::ThreadPool threads;

#endif // DK_RUNTIME_THREADPOOL_H
