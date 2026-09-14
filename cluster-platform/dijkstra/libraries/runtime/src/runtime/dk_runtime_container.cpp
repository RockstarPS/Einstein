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
#include "dk_runtime_container.h"
#include "dk_logger.h"

LOG_IMPORT_CONTEXT ( gRTELogContext );

using namespace dk::runtime::core;

bool Container::onInit()
{
    LOGV ( &gRTELogContext, "Container::onInit" );

    for ( auto component : mComponentList )
    {
        ( void ) component->onInit();
    }

    return true;
}

bool Container::onExit()
{
    LOGV ( &gRTELogContext, "Container::onExit" );

    for ( auto component : mComponentList )
    {
        ( void ) component->onExit();
    }

    return true;
}

bool Container::onStart()
{
    LOGV ( &gRTELogContext, "Container::onStart" );

    for ( auto component : mComponentList )
    {
        ( void ) component->onStart();
    }

    return true;
}

bool Container::onStop()
{
    LOGV ( &gRTELogContext, "Container::onStop" );

    for ( auto component : mComponentList )
    {
        ( void ) component->onStop();
    }

    return true;
}

void Container::onRxMessage ( MsgDeserializer &msgDes )
{
    if ( ( mMsgIDs.find ( msgDes.mMsgId ) ) != ( mMsgIDs.end() ) )
    {
        mRxMsgQueue.push ( msgDes );
        mWaitMsgRxSem.post();
    }
}

int32_t Container::runMessagePump()
{
    /// wait 1s for message, if no msg process because of the heart beat
    if ( mWaitMsgRxSem.timedWaitMS ( 1000U ) )
    {
        /// pump out the queue
        MsgDeserializer *pMsgDes = mRxMsgQueue.pull();

        if ( nullptr != pMsgDes )
        {
            while ( pMsgDes != nullptr )
            {
                for ( auto component : mComponentList )
                {
                    /// filter is inside the onRxMessage function
                    component->onRxMessage ( *pMsgDes );
                }

                delete pMsgDes;
                pMsgDes = nullptr;
                pMsgDes = mRxMsgQueue.pull();
            }
        }
    }
    else
    {
        LOGV ( &gRTELogContext, "Containter HB" );
    }

    return true;
}

void Container::getMessageGroups ( std::set<uint8_t> &msgGroups )
{
    for ( auto component : mComponentList )
    {
        std::map<mid_t, func_t> *pMsgMap = component->getMsgMap();

        for ( std::map<mid_t, func_t>::iterator it = pMsgMap->begin(); it != pMsgMap->end(); ++it )
        {
            ( void ) msgGroups.insert ( ( it->first >> 8U ) & 0xFFU );
        }
    }
}
