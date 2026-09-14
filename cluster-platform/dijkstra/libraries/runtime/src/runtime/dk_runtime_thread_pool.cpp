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

#include "dk_runtime_thread_pool.h"

using namespace dk::runtime::core;

ThreadPool threads;

void ThreadPool::start ( const uint32_t tid ) noexcept
{

    if ( tid < size() )
    {
        DkThread *const ptr = operator[] ( tid );

        {
            std::lock_guard<std::mutex> guard ( ptr->mMutex );
            ptr->mIsRunning = true;
        }

        ptr->start ( ptr->mThreadConfigId );
    }
}

void ThreadPool::stop ( const uint32_t tid ) noexcept
{
    if ( tid < size() )
    {
        DkThread *const ptr = operator[] ( tid );

        {
            std::lock_guard<std::mutex> guard ( ptr->mMutex );
            ptr->mIsRunning = false;
        }

        ( void ) ptr->join();

        ptr->mThreadConfigId = 0;
    }
}

bool ThreadPool::getIsRunning ( const uint32_t tid ) noexcept
{
    bool ret = false;

    if ( tid < size() )
    {
        DkThread *const ptr = operator[] ( tid );

        {
            std::lock_guard<std::mutex> guard ( ptr->mMutex );
            ret = ptr->mIsRunning;
        }
    }

    return ret;
}
