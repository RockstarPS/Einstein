//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2022] Visteon Corporation
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
 * @file core_handler.hpp
 * @brief Per-core DLT data handler supporting SharedMemory and serial transports.
 *
 * @details
 * @ref CoreHandler abstracts the physical transport for a single remote core.
 * Regardless of transport type, it presents an identical interface to
 * @ref DltGateway: messages are enqueued internally and retrieved via
 * @ref dequeue().
 *
 * @par SharedMemory transport
 * @ref DltGateway decodes the IPCL bitmask and calls @ref readShmBuffer()
 * for each set bit.  @ref readShmBuffer() looks up the @ref BufferConfig
 * by its @c Position field and copies the data from the mapped SHM window
 * via @ref SharedMemoryReader.
 * 
 * @par Queue back-pressure
 * The internal queue is bounded at 512 entries.  If the dispatch thread
 * cannot keep up, the oldest message is silently dropped and the
 * @ref dropped() counter is incremented.
 *
 * @author  dmuruge5/gsoundar
 * @version 1.0
 */

#ifndef DLT_GATEWAY_CORE_HANDLER_H
#define DLT_GATEWAY_CORE_HANDLER_H

#include <unordered_map>
#include <functional>
#include <optional>
#include <queue>
#include <chrono>
#include <thread>
#include <condition_variable>
#include "dlt_gateway_types.h"
#include "dlt_gateway_shm_reader.h"

/**
 * @brief Manages data reception for one remote core and queues DLT messages.
 *
 * @par Lifecycle
 * @code{.cpp}
 * CoreHandler handler(coreConfig, messageCb);
 * handler.start();           // open transport; launch reader thread (serial)
 * // ... messages enqueued asynchronously ...
 * DltMessage msg;
 * if (handler.dequeue(msg))  // block up to 100 ms
 *     process(msg);
 * handler.stop();            // shut down reader thread
 * @endcode
 */
class DltCoreHandler {
public:
    /**
     * @brief Callback invoked from the message queue whenever a new message is enqueued.
     *
     * Used by @ref DltGateway to wake its dispatch thread without polling.
     * The callback must be non-blocking (it is called under the queue mutex).
     */
    using MessageReadyCb = std::function<void()>;

    /**
     * @brief Construct a CoreHandler for the given core configuration.
     *
     * Builds an internal @c position → @c BufferConfig* lookup table from
     * @c cfg.buffers so that @ref readShmBuffer() can dispatch.
     *
     * @param cfg  Core configuration (transport type, SHM params, buffer list).
     * @param cb   Callback invoked each time a new message is added to the queue.
     */
    explicit DltCoreHandler(SCoreConfig_t cfg, MessageReadyCb cb)
             : mCoreConfig(std::move(cfg)),
               on_message_ready(std::move(cb))
    {
        for (const auto& buf : mCoreConfig.BuffConfig)
            mPos_to_buffer[buf->Pos] = buf;
    }

    /**
     * @brief Open the transport and start the reader thread (serial only).
     *
     * For SharedMemory: calls @ref SharedMemoryReader::open().
     * For UART/SPI: calls @ref SerialReader::open() and launches the
     * @ref serialReaderLoop() thread.
     *
     * @return @c true on success; @c false if the transport could not be opened.
     */
    bool start();

    /**
     * @brief Signal the reader thread to stop and wait for it to exit.
     *
     * Sets the @c mRunning flag to @c false, closes the serial device (which
     * unblocks any in-progress @c read()), notifies the condition variable,
     * and joins the reader thread.
     */
    void stop();

    /**
     * @brief Copy data from one SHM buffer into the message queue.
     *
     * Called by @ref DltGateway::onReceiveDLTMessageReadRequest() for each set
     * bit in the IPCL status byte.  Looks up the @ref BufferConfig for @p position,
     * copies the full @c BufferConfig::size bytes from shared memory via
     * @ref SharedMemoryReader::readBuffer(), and enqueues the result.
     *
     * This function must not block — it is called from the IPCL callback context.
     *
     * @param position  Bit number from the IPCL status byte; must match a
     *                  @c BufferConfig::position value in this core's buffer list.
     */
    void readShmBuffer(uint8_t position);

    /**
     * @brief Dequeue one @ref DltMessage, blocking up to @p timeout.
     *
     * populates @p msg if a message was available, @c false on timeout or
     * shutdown.
     *
     * @param msg   Output parameter populated with the dequeued message.
     * @param timeout  Maximum time to wait (default 100 ms).
     * @return @c true if @p msg was populated; @c false on timeout or stop.
     */
    bool dequeue(SDltMsg_t& msg, std::chrono::milliseconds timeout = std::chrono::milliseconds(100));

    /**
     * @brief Return @c true if at least one message is waiting in the queue.
     *
     * Non-blocking.  Used by @ref DltGateway to decide whether to wake the
     * dispatch thread.
     */
    bool hasMessages() const;

    SCoreConfig_t mCoreConfig;            ///< Immutable core config populated from INI.

private:
    /// @brief Maximum number of messages held in the queue before dropping oldest.
    static constexpr std::size_t mMaxQueueDepth {512};

    /// @brief Maps @c BufferConfig::position → pointer into @c mCoreConfig.buffers
    std::unordered_map<uint8_t, const SCoreBuffConfig_t*> mPos_to_buffer;

    DltShmReader mShmReader;              ///< SHM transport reader (SHM cores only).

    std::atomic<bool> mRunning {false};   ///< Set by start(); cleared by stop().
    uint32_t mMsgDropped {0};             ///< Messages dropped due to queue overflow.

    MessageReadyCb on_message_ready;      ///< Callback fired when a message is enqueued.
    std::queue<SDltMsg_t>   mMsgQueue;    ///< Bounded FIFO of received messages.
    mutable std::mutex      mMsgQueMTX;   ///< Protects @c mMsgQueue.
    std::condition_variable mQueCV;       ///< Signalled when a message is enqueued or stop() is called.

    std::thread    mReaderThread;         ///< Reader thread (serial transport only).
    //DltSerialReader   mSerialReader;    ///< Serial transport reader (UART/SPI cores only).

    /**
     * @brief Add a message to the tail of the queue, dropping the head if full.
     *
     * Notifies the condition variable and fires the @ref MessageReadyCb after
     * releasing the lock.
     *
     * @param msg  Message to enqueue (moved in).
     */
    void enqueue(SDltMsg_t msg);

};

#endif //DLT_GATEWAY_CORE_HANDLER_H