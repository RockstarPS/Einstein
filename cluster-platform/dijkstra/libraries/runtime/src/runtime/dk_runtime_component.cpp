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
#ifdef _WIN32
#include <ciso646>
#endif
#include "dk_runtime_component.h"
#include "dk_logger.h"
#include <pthread.h>

LOG_IMPORT_CONTEXT ( gRTELogContext );

using namespace dk::runtime::core;

///< Public Functions
bool Component::onInit()
{
    LOGV ( &gRTELogContext, "Component::onInit" );
    mIsStarted = false;
    return true;
}

bool Component::onExit()
{
    LOGV ( &gRTELogContext, "Component::onExit" );
    return true;
}

bool Component::onStart()
{
    bool ret = false;
    LOGV ( &gRTELogContext, "Component::onStart" );

    if ( ( !mIsStarted ) && ( mvTasks.size() > 0U ) )
    {
        const uint32_t nowMs = nowTimeMs();

        for ( auto &t : mvTasks )
        {
            t.start = nowMs;
        }

        mIsStarted = true;
        mpPthreadTask = new std::thread ( [this]()
        {
            this->periodicTaskThread();
        } );

#ifndef _WIN32
        std::string lThreadName(mCompName);
        lThreadName += "PeriodicTask";
        auto handle = mpPthreadTask->native_handle();
        (void)pthread_setname_np(handle, lThreadName.c_str());
#endif

        ret = true;
    }

    return ret;
}

bool Component::onStop()
{
    bool ret = false;
    LOGV ( &gRTELogContext, "Component::onStop" );

    if ( mIsStarted )
    {
        mIsStarted = false;
        mpPthreadTask->join();
        delete mpPthreadTask;
        mpPthreadTask = nullptr;
        ret = true;
    }

    return ret;
}

void Component::onRxMessage ( MsgDeserializer &msgDes )
{
    if ( ( mMsgMap->find ( msgDes.mMsgId ) ) != ( mMsgMap->end() ) )
    {
        std::lock_guard<std::mutex> guard ( mExecGuardMutex );
        ( *mMsgMap ) [msgDes.mMsgId] ( msgDes );
    }
}

///< Protected Functions
int32_t Component::registerTask ( const TaskCallback_t &taskCbk, const uint32_t periodMs )
{
    int32_t taskId = -1;

    if ( ( 0U == periodMs ) || ( mIsStarted ) || ( MAX_TASKS_COUNT <= mvTasks.size() ) )
    {
        LOGE ( &gRTELogContext, "registerTask Failed" );
    }
    else
    {
        LOGI ( &gRTELogContext, "registerTask success" );
        TaskControl_t task{true, periodMs, 0U, taskCbk};
        mvTasks.push_back ( task );
        taskId = static_cast<int32_t> ( mvTasks.size() - 1U );
    }

    return taskId;
}

bool Component::startTask ( int32_t taskId )
{
    bool ret = false;

    if ( ( taskId ) < static_cast<int32_t> ( mvTasks.size() ) )
    {
        mvTasks[taskId].start = nowTimeMs();
        mvTasks[taskId].running = true;
        ret = true;
    }

    return ret;
}

bool Component::stopTask ( int32_t taskId )
{
    bool ret = false;

    if ( ( taskId ) < static_cast<int32_t> ( mvTasks.size() ) )
    {
        mvTasks[taskId].running = false;
        ret = true;
    }

    return ret;
}

void Component::periodicTaskThread()
{
    while ( mIsStarted )
    {
        uint32_t startMs = nowTimeMs();
        uint32_t nextRunMs = MAX_SLEEP_TIME_MS;

        for ( auto &t : mvTasks )
        {
            if ( t.running )
            {
                const uint32_t newStart = t.start + t.period;

                if ( newStart <= startMs )
                {
                    std::lock_guard<std::mutex> guard ( mExecGuardMutex );
                    t.cbk();

                    //Did we starve for too long
                    if ( ( newStart + t.period ) < startMs )
                    {
                        t.start = startMs;
                    }
                    else
                    {
                        t.start = newStart;
                    }
                }

                const uint32_t timeRemaining = ( t.start + t.period ) - startMs;

                if ( nextRunMs > timeRemaining )
                {
                    nextRunMs = timeRemaining;
                }
            }
        }

        if ( nextRunMs < MIN_SLEEP_TIME_MS )
        {
            nextRunMs = MIN_SLEEP_TIME_MS;
        }

        std::this_thread::sleep_for ( std::chrono::milliseconds ( nextRunMs ) );
    }
}

uint32_t Component::nowTimeMs()
{
    return static_cast<uint32_t> ( std::chrono::steady_clock::now().time_since_epoch() / std::chrono::milliseconds ( 1U ) );
}
