//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2026] Visteon Corporation
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
//---------------------------------------------------------------------------------------------------------------------
/**
 * @file dlt_gateway_core_handler.cpp
 * @author dmuruge5/gsoundar
 * @brief 
 * @version 0.1
 * @date 2026-06-01
 * 
 */

#include "dlt_gateway_core_handler.h"
#include "dk_logger.h"

LOG_IMPORT_CONTEXT ( gDLTGWLogContext );

bool DltCoreHandler::start()
{
    bool ret = false;
    if (mCoreConfig.transport == TransportType::SharedMemory)
    {
        if (mShmReader.openDevice(mCoreConfig))
        {
            LOGI(&gDLTGWLogContext, mCoreConfig.CoreName, ": Started Transport: ", transportTypeName(mCoreConfig.transport)," Number of Buffers: ", mCoreConfig.BuffConfig.size());
            mRunning = true;
            ret = true;
        }
        else
        {
            LOGE(&gDLTGWLogContext, "SHM open device failed");
        }
    }
    else if ((mCoreConfig.transport == TransportType::Uart) || (mCoreConfig.transport == TransportType::Spi))
    {
        // UART / SPI: open device and launch reader thread
    }
    else
    {
        LOGE(&gDLTGWLogContext, "Transport type: ", transportTypeName(mCoreConfig.transport));
    }

    return ret;
}

void DltCoreHandler::stop()
{
    mRunning = false;
    mQueCV.notify_all();
}

void DltCoreHandler::readShmBuffer(uint8_t position)
{
    if (!mRunning)
        return;

    auto it = mPos_to_buffer.find(position);
    if (it == mPos_to_buffer.end())
    {
        LOGE(&gDLTGWLogContext, "unknown position ", mCoreConfig.CoreName, "Position", position);
        return;
    }

    const SCoreBuffConfig_t& bufConfig = *it->second;

    SDltMsg_t msg = mShmReader.readBuffer(bufConfig, bufConfig.BufSize);
    enqueue(std::move(msg));
}

bool DltCoreHandler::dequeue(SDltMsg_t& msg, std::chrono::milliseconds timeout)
{
    std::unique_lock<std::mutex> lk(mMsgQueMTX);
    mQueCV.wait_for(lk, timeout,
            [this]{ return !mMsgQueue.empty() || !mRunning; });

    if (mMsgQueue.empty())
        return false;

    msg = std::move(mMsgQueue.front());
    mMsgQueue.pop();

    return true;
}

bool DltCoreHandler::hasMessages() const
{
    std::lock_guard<std::mutex> lk(mMsgQueMTX);
    return !mMsgQueue.empty();
}

void DltCoreHandler::enqueue(SDltMsg_t msg)
{
    if (msg.length != 0)
    {
        std::lock_guard<std::mutex> lk(mMsgQueMTX);
        if (mMsgQueue.size() >= mMaxQueueDepth)
        {
            mMsgQueue.pop();
            ++mMsgDropped;
            LOGE(&gDLTGWLogContext, "queue full, oldest messages dropped. ", mMsgDropped);
        }
        mMsgQueue.push(std::move(msg));

        mQueCV.notify_one();
        if (on_message_ready)
        {
            on_message_ready();
        }
    }
}