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

#include <iostream>
#include <thread>
#include <cstring>
#include <atomic>
#ifdef _WIN32
#include <unistd.h>
#endif
#include "dk_runtime_ipcmsgif.h"
#include "dk_logger.h"

LOG_IMPORT_CONTEXT ( gRTELogContext );

using namespace dk::runtime::core;

IpcMsgIf::IpcMsgIf()
{
}

IpcMsgIf::~IpcMsgIf()
{
}

bool IpcMsgIf::connect ( const char *pProcessName, int32_t taskId )
{
#ifdef DK_VMF_ENABLED
    bool ret = false;
    uint8_t retryCount = 100U;
    ( void ) taskId;

    // Connect to VMF
    while ( 0U < retryCount )
    {
        mVmfClientId = nw_vmf_connect ( pProcessName, nullptr, 0, VMF_CLIENT_QUEUE_SIZE_BIG, DK_MSG_MAX_PAYLOAD_LEN );

        if ( 0 > mVmfClientId )
        {
            LOGE ( &gRTELogContext, "nw_vmf_connect Failed ", mVmfClientId );
            std::this_thread::sleep_for ( std::chrono::milliseconds ( 100 ) );
            retryCount--;
        }
        else
        {
            LOGI ( &gRTELogContext, "nw_vmf_connect Success ", mVmfClientId );
            ret = true;
            break;
        }
    }

    return ret;
#else
    LOGE ( &gRTELogContext, "Runtime Compiled without IPC" );
    return true;
#endif
}

void IpcMsgIf::disconnect()
{
#ifdef DK_VMF_ENABLED

    if ( 0 <= mVmfClientId )
    {
        ( void ) nw_vmf_disconnect ( mVmfClientId );

        LOGI ( &gRTELogContext, "nw_vmf_disconnect Success ", mVmfClientId );
    }

#else
    LOGE ( &gRTELogContext, "Runtime Compiled without IPC" );
#endif
}

bool IpcMsgIf::subscribe ( uint8_t *groupIdArray, uint8_t numGroups )
{
#ifdef DK_VMF_ENABLED
    bool ret = false;

    if ( 0 <= mVmfClientId )
    {
        if ( 0 > nw_vmf_register_msg_group ( mVmfClientId, static_cast<uint16_t> ( numGroups ), &groupIdArray[0] ) )
        {
            LOGE ( &gRTELogContext, "nw_vmf_register_msg_group Failed" );
        }
        else
        {
            LOGI ( &gRTELogContext, "nw_vmf_register_msg_group Success ", numGroups );
            ret = true;
        }
    }

    return ret;
#else
    LOGE ( &gRTELogContext, "Runtime Compiled without IPC" );
    return true;
#endif
}

bool IpcMsgIf::send ( uint8_t groupId, uint8_t eventId, uint8_t *pPayload, uint16_t size )
{
    bool ret = false;

#ifdef DK_VMF_ENABLED
    VMF_VAR_BASIC_MSG_TYP ( DK_MSG_MAX_PAYLOAD_LEN )
    vmfMsg;

    if ( 0 <= mVmfClientId )
    {
        VMF_BASIC_MSG_GROUP_ID ( &vmfMsg ) = groupId;
        VMF_BASIC_MSG_EVENT_ID ( &vmfMsg ) = eventId;
        VMF_BASIC_MSG_SET_FAR_DATA_LENGTH ( &vmfMsg, size );
        ( void ) std::memcpy ( ( void * ) VMF_BASIC_MSG_PTR_TO_FAR_DATA ( &vmfMsg ), pPayload, static_cast<uint64_t> ( size ) );

        if ( VMF_OK == nw_vmf_send_basic ( mVmfClientId, ( vmf_basic_msg_t * ) &vmfMsg ) )
        {
            ret = true;
        }
        else
        {
            LOGE ( &gRTELogContext, "nw_vmf_send_basic Failed Gx: ", groupId, ", Ex: ", eventId, " Size: ", size );
        }
    }

#else
    LOGE ( &gRTELogContext, "Runtime Compiled without IPC" );
    ret =  true;
#endif
    return ret;
}

bool IpcMsgIf::receive ( uint8_t &groupId, uint8_t &eventId, uint8_t *pPayload, uint16_t &size )
{
#ifdef DK_VMF_ENABLED
    bool ret = false;
    VMF_VAR_BASIC_MSG_TYP ( DK_MSG_MAX_PAYLOAD_LEN )
    vmfMsg = {0};

    if ( 0 <= mVmfClientId )
    {
        uint16_t rxLen = nw_vmf_timed_receive ( mVmfClientId, ( vmf_msg_t * ) &vmfMsg, static_cast<uint16_t> ( sizeof ( vmfMsg ) ), 1000U );

        if ( 0U < rxLen )
        {
            groupId = VMF_BASIC_MSG_GROUP_ID ( &vmfMsg );
            eventId = VMF_BASIC_MSG_EVENT_ID ( &vmfMsg );
            VMF_BASIC_MSG_RX_GET_FAR_DATA_LENGTH ( size, &vmfMsg );



            if ( DK_MSG_MAX_PAYLOAD_LEN > size )
            {
#ifndef _WIN32
                std::atomic_thread_fence ( std::memory_order_acquire );
                ( void ) std::memcpy ( pPayload,  static_cast<void *> ( &vmfMsg.data.pl[VMF_BASIC_MSG_NEAR_DATA_LENGTH] ), static_cast<uint16_t> ( size ) );

                std::atomic_thread_fence ( std::memory_order_release );
#else
                std::memcpy ( pPayload, ( uint8_t * ) VMF_BASIC_MSG_PTR_TO_FAR_DATA ( &vmfMsg ), size );
#endif

            }
            else
            {
                ( void ) std::memcpy ( pPayload, static_cast<void *> ( &vmfMsg.data.pl[VMF_BASIC_MSG_NEAR_DATA_LENGTH] ), DK_MSG_MAX_PAYLOAD_LEN );
            }

            ret = true;
        }
    }

    return ret;
#else
    LOGE ( &gRTELogContext, "Runtime Compiled without IPC" );
    return true;
#endif
}
