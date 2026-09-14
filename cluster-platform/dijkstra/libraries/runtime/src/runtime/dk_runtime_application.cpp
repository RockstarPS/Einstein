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

#include "dk_runtime_application.h"
#include "dk_logger.h"
#include <cstdlib>

LOG_IMPORT_CONTEXT ( gRTELogContext );

using namespace dk::runtime::core;

bool Application::onInit()
{
    LOGI ( &gRTELogContext, "Application::onInit" );

    mpDispatchQueueSem = new osal::Semaphore ( 0U );

    for ( auto container : mContainerList )
    {
        ( void ) container->onInit();
    }

    return true;
}

bool Application::onExit()
{
    LOGI ( &gRTELogContext, "Application::onExit" );

    for ( auto container : mContainerList )
    {
        ( void ) container->onExit();
    }

    delete mpDispatchQueueSem;
    return true;
}

bool Application::onStart()
{
    LOGI ( &gRTELogContext, "Application::onStart" );

    for ( auto container : mContainerList )
    {
        ( void ) container->onStart();
    }

    return true;
}

bool Application::onStop()
{
    LOGI ( &gRTELogContext, "Application::onStop" );

    for ( auto container : mContainerList )
    {
        ( void ) container->onStop();
    }

    return true;
}

int32_t Application::onRun()
{
    LOGI ( &gRTELogContext, "Application::onRun" );
    return true;
}

int32_t Application::stop()
{
    mIsRunning = false;
    ( void ) onStop();
    ( void ) onExit();

    // Disconnect Services
    mIpcMsgIf.disconnect();

    if ( mWdgIf.getWatchdogEnabled() )
    {
        ( void ) mWdgIf.disconnect();
    }

    return 0U;
}

int32_t Application::run()
{
    int32_t ret = -1;

    // Initialize IPC communication
    if ( initIpcMsgIf() )
    {
        // Initialize Watchdog connection
        if ( mWdgIf.getWatchdogEnabled() )
        {
            if ( mWdgIf.connect ( mAppName.c_str() ) )
            {
                mIsRunning = true;
            }
            else
            {
                mIsRunning = false;
            }
        }
        else
        {
            LOGI ( &gRTELogContext, "Watchdog is disabled" );
            mIsRunning = true;
        }
    }

    if ( mIsRunning )
    {
        if ( onInit() )
        {
            if ( onStart() )
            {
                ret = onRun();
            }
            else
            {
                //TODO: Handle onStart Failure
            }
        }
        else
        {
            //TODO: Handle onInit Failure
        }
    }

    return ret;
}

bool Application::getIsRunning()
{
    return mIsRunning;
}

void Application::setWatchdogEnabled ( bool enable )
{
    mWdgIf.setWatchdogEnabled ( enable );
}

uint32_t Application::getWdgWaitTimeout()
{
    return mWdgIf.getGrantedTimeoutMs();
}

bool Application::WdgStart ( uint32_t timeout )
{
    return mWdgIf.start(timeout);
}

void  Application::WdgSendHeartbeat()
{
    mWdgIf.sendHeartbeat();
}

bool Application::WdgStop()
{
    return mWdgIf.stop();
}

void Application::sendMsgToDisplatchQueue ( MsgSerializer *pMsgSer )
{
    mDispatchQueue.push ( pMsgSer );
    mpDispatchQueueSem->post();
}

void Application::sendMsgToIpc ( std::shared_ptr<MsgSerializer> &pMsgSer )
{
    uint8_t groupId = ( pMsgSer->mMsgId >> 8U ) & 0xFFU;
    uint8_t eventId = ( pMsgSer->mMsgId & 0xFFU );
    uint16_t size = pMsgSer->getSerializedDataSize() + 2U;
#ifndef _WIN32
    uint8_t payload[size];
#else
    uint8_t *payload;
    payload = (uint8_t*)malloc(size);
#endif

    payload[0U] = pMsgSer->mSenderId;
    payload[1U] = pMsgSer->mMsgCnt;

    ( void ) std::memcpy ( &payload[2U], static_cast<uint8_t *> ( ( void * ) pMsgSer->getSerializedData() ),
            pMsgSer->getSerializedDataSize() );

    if ( !mIpcMsgIf.send ( groupId, eventId, static_cast<uint8_t *> ( payload ), size ) )
    {
        LOGE ( &gRTELogContext, "sendMsgToIpc Failed" );
    }
#ifdef _WIN32
    free(payload);
#endif
}

void Application::runDispatchQueue()
{
    /// wait 1s for message, if no msg process because of the heart beat
    if ( mpDispatchQueueSem->timedWaitMS ( 1000U ) )
    {
        /// pump out the queue
        MsgSerializer *pMsgSer = mDispatchQueue.pull();

        if ( pMsgSer != nullptr )
        {
            while ( pMsgSer != nullptr )
            {
                for ( auto container : mContainerList )
                {
                    MsgDeserializer msgDes ( pMsgSer );
                    /// filter is inside the onRxMessage function
                    container->onRxMessage ( msgDes );
                }

                delete pMsgSer;
                pMsgSer = mDispatchQueue.pull();
            }
        }
    }
    else
    {
        LOGV ( &gRTELogContext, "Dispatch Queue HB" );
    }
}

void Application::runIpcMessagePump()
{
#ifdef DK_VMF_ENABLED
    uint8_t groupId = 0U;
	uint8_t eventId = 0U;
    uint16_t size = 0U;
#ifndef _WIN32
    uint8_t payload[mIpcMsgIf.getMaxPayloadSize()];
#else
    uint8_t *payload;
    payload = (uint8_t*)malloc(mIpcMsgIf.getMaxPayloadSize());
#endif

    std::shared_ptr<MsgDeserializer> pMsgDes = nullptr;

    if ( mIpcMsgIf.receive ( groupId, eventId, static_cast<uint8_t *> ( payload ), size ) )
    {
        if ( size > 0U )
        {
            uint8_t msgSenderId = payload[0U];
            uint8_t msgCnt = payload[1U];

            pMsgDes = std::make_shared<MsgDeserializer> ( ( static_cast<uint16_t> ( eventId ) | ( ( static_cast<std::uint16_t> ( groupId ) << 8U )  & 0xFF00U ) ),
                            msgSenderId,
                            msgCnt,
                            static_cast<uint8_t *> ( &payload[2] ),
                            static_cast<uint32_t> ( size - 2U ) );

            if ( nullptr != pMsgDes )
            {
                for ( auto container : mContainerList )
                {
                    container->onRxMessage ( *pMsgDes );
                }

                pMsgDes.reset();
            }
        }
    }
    else
    {
        LOGV ( &gRTELogContext, "IpcMessagePump HB" );
    }

#else
    LOGE ( &gRTELogContext, "Runtime Compiled without IPC. Disable IPC Message Pump." );
    std::this_thread::sleep_for ( std::chrono::seconds ( 10U ) );
#endif
#ifdef _WIN32
    free(payload);
#endif
}

///< Private Functions
bool Application::initIpcMsgIf()
{
    bool ret = false;

    // Initialize IPC communication
    if ( mIpcMsgIf.connect ( mAppName.c_str(), 0 ) )
    {
        // Collected interested groups from containers
        std::set < uint8_t > msgGroups;

        for ( auto container : mContainerList )
        {
            container->getMessageGroups ( msgGroups );
        }

        // Convert to array
        uint8_t numGroups = 0U;
        uint8_t groupIdArray[MAX_GROUP_NUM];

        for ( std::set<uint8_t>::iterator it = msgGroups.begin(); it != msgGroups.end(); ++it )
        {
            groupIdArray[numGroups] = *it;
            numGroups++;
        }

        // Subscribe to the groups
        if ( mIpcMsgIf.subscribe ( static_cast<std::uint8_t *> ( groupIdArray ), numGroups ) )
        {
            ret = true;
        }
    }

    return ret;
}
