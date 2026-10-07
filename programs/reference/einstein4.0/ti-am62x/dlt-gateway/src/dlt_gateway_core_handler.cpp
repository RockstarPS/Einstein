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
#include "dlt_gateway_payload_validate.h"
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

bool DltCoreHandler::readShmBuffer(uint8_t position)
{
    if (!mRunning)
    {
        LOGE(&gDLTGWLogContext, "BufferError: core ", mCoreConfig.CoreName, " not running, Position: ", static_cast<uint32_t>(position));
        return false;
    }

    auto it = mPos_to_buffer.find(position);
    if (it == mPos_to_buffer.end())
    {
        LOGE(&gDLTGWLogContext, "BufferError: unknown position ", mCoreConfig.CoreName, " Position: ", static_cast<uint32_t>(position));
        return false;
    }

    const SCoreBuffConfig_t& bufConfig = *it->second;

    SDltMsg_t msg = mShmReader.readBuffer(bufConfig, bufConfig.BufSize);
    if (msg.length == 0)
    {
        LOGE(&gDLTGWLogContext, "BufferError: ", mCoreConfig.CoreName, " ", bufConfig.name, " Position: ", static_cast<uint32_t>(position), " shared memory read failed");
        return false;
    }

    // Validate before the ACK/NACK is sent so that the response reflects the buffer content
    const SScanResult_t scanResult = DltValidator::scanBuffer(msg.payload.data(), static_cast<uint32_t>(msg.length));
    const bool ret = (scanResult.frames_ok > 0U) && (scanResult.frames_bad == 0U);

    if (!ret)
    {
        SValidationResult_t res;
        res.error = scanResult.error;
        LOGE(&gDLTGWLogContext, "BufferError: ", mCoreConfig.CoreName, " ", bufConfig.name, " Position: ", static_cast<uint32_t>(position),
             " Frames ok: ", scanResult.frames_ok, " Frames bad: ", scanResult.frames_bad,
             " Reason: ", (scanResult.frames_bad > 0U) ? res.reason() : "no DLT frame in buffer");
    }

    // Forward the valid leading frames even if the rest of the buffer is corrupt
    if (scanResult.valid_bytes > 0U)
    {
        msg.payload.resize(scanResult.valid_bytes);
        msg.length      = scanResult.valid_bytes;
        msg.core_name   = mCoreConfig.CoreName;
        msg.buffer_name = bufConfig.name;
        enqueue(std::move(msg));
    }

    return ret;
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