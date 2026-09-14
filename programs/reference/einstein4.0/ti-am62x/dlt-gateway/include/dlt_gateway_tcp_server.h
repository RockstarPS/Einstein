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
 * @file dlt_gateway_tcp_server.h
 * @brief TCP server that connects to dlt-daemon Gateway and forwards validated DLT frames to dlt-daemon.
 *
 * @details
 * @ref DltTcpServer manages a single outbound TCP connection to dlt-daemon
 *
 * @brief Reconnect back-off policy for the TCP connection to dlt-daemon.
 *
 * @details
 * @ref ReconnectPolicy encapsulates the retry strategy used by
 * @ref DltGateway when the TCP connection to dlt-daemon is lost or cannot
 * be established at startup.
 *
 * @author  dmuruge5
 * @version 1.0
 */
#ifndef DLT_GATEWAY_TCPSERVER_H
#define DLT_GATEWAY_TCPSERVER_H

#include <cstdint>
#include <string>
#include <vector>
#include <atomic>
#include <thread>

/**
 * @brief Outbound TCP server for forwarding DLT frames to dlt-daemon.
 *
 * The class is non-copyable.  A single instance is owned by @ref DltGateway
 * and shared (via method calls) with the dispatch thread.
 *
 * @par Thread safety
 * @ref connect(), @ref disconnect(), @ref send(), are
 * **not** internally synchronised — the caller (@ref DltGateway) must ensure
 * only the dispatch thread accesses the send path.  @ref isConnected() reads
 * an @c atomic<bool> and is safe to call from any thread.
 */
class DltTcpServer
{
public:
    /// @brief Default constructor.  No socket is created until configure() + connect().
    DltTcpServer() = default;
    /// @brief Non-copyable.
    DltTcpServer(const DltTcpServer&)            = delete;
    /// @brief Non-copy-assignable.
    DltTcpServer& operator=(const DltTcpServer&) = delete;

    /// @brief Destructor — closes connection if still open.
    ~DltTcpServer()
    {
        disconnect();
    }

    /**
     * @brief Store the server endpoint.
     *
     * Must be called before @ref openSocket(), connectClient().  Does not open any socket.
     *
     * @param host  IP address string (e.g. @c "127.0.0.1").
     * @param port  TCP port number (e.g. @c 3490).
     */
    void configure(std::string host, int32_t port);

    /**
     * @brief Opens server socket.
     *
     * Must be called before @ref connectClient().
     *
     * @return @c true if the socket was opened successfully.
     */
    bool openSocket();

    /**
     * @brief Establish a TCP connection to dlt-daemon gateway.
     *
     * @return @c true if the connection was established successfully.
     */
    bool connectClient();

    /**
     * @brief Write exactly @p len bytes to the socket, retrying on partial writes.
     * @param buf  Source buffer.
     * @param len  Number of bytes to write.
     * @return     @c true if all bytes were sent; @c false on error or disconnection.
     */
    bool sendAll(const void* buf, std::size_t len);

    /**
     * @brief Return @c true if a live TCP connection is currently open.
     *
     * Thread-safe (reads an @c atomic<bool>).
     */
    bool isConnected() const;

    /**
     * @brief Close the TCP connection if open.
     *
     */
    void disconnect();

    /**
     * @brief Close the TCP clinet connection if open.
     *
     */
    void disconnectClient();

private:
    std::string  mHost;                   ///< dlt-daemon IP address string.
    int32_t      mPort {3490};            ///< dlt-daemon TCP port.
    int32_t      mServerfd {-1};          ///< Active client socket file descriptor, or -1.
    int32_t      mClientFd {-1};          ///< Active client socket file descriptor, or -1.
    std::atomic<bool> mConnected {false}; ///< Whether a live connection exists.
    const int32_t mTcpBufSize = 2048;     ///< TCP socket maximum buffer size.
};

/**
 * @brief Manages retry timing and attempt counting for TCP reconnect logic.
 *
 * @par Usage
 * @code{.cpp}
 * ReconnectPolicy policy(2000, -1, true);  // 2 s base, unlimited, backoff on
 * policy.reset();
 * while (!connect()) {
 *     if (!policy.shouldRetry()) break;
 *     policy.waitInterval(running_flag);   // sleeps 2s, 4s, 8s … up to 30s
 * }
 * policy.reset();  // reset counters after a successful connection
 * @endcode
 */
class ReconnectPolicy {
public:
    /**
     * @brief Construct a reconnect policy.
     *
     * @param interval_ms  Base wait duration between retries in milliseconds.
     * @param max_retries  Maximum number of attempts before @ref shouldRetry()
     *                     returns @c false.  Pass @c -1 for unlimited retries.
     * @param use_backoff  If @c true, the wait interval doubles after each
     *                     failed attempt (exponential back-off), capped at 30 s.
     */
    explicit ReconnectPolicy(uint32_t interval_ms  = 2000,
                             int32_t max_retries  = -1,
                             bool use_backoff = false)
        : base_interval_ms_(interval_ms)
        , max_retries_(max_retries)
        , use_backoff_(use_backoff)
    {}

    /**
     * @brief Reset the attempt counter and interval to their initial values.
     *
     * Call this after a successful connection to ensure the next reconnect
     * cycle starts fresh.
     */
    void reset() {
        attempts_   = 0;
        current_ms_ = base_interval_ms_;
    }

    /**
     * @brief Return @c true if another reconnect attempt should be made.
     *
     * Always returns @c true when @c max_retries == -1 (unlimited).
     *
     * @return @c true if @c attemptCount() < @c max_retries or unlimited.
     */
    bool shouldRetry() const {
        if (max_retries_ < 0) return true;
        return attempts_ < max_retries_;
    }

    /**
     * @brief Block for the current back-off interval, then advance internal state.
     *
     * Sleeps in 100 ms increments so the wait can be interrupted early when
     * @p stop_flag becomes @c true (e.g. on application shutdown).
     *
     * After the wait, increments the attempt counter and, if back-off is enabled,
     * doubles the current interval (capped at 30 000 ms).
     *
     * @param stop_flag  Atomic flag checked every 100 ms.  When @c true the
     *                   function returns immediately without completing the interval.
     */
    void waitInterval(const std::atomic<bool>& running_flag) {
        auto deadline = std::chrono::steady_clock::now() +
                        std::chrono::milliseconds(current_ms_);
        while (running_flag.load() && std::chrono::steady_clock::now() < deadline)
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

        ++attempts_;
        if (use_backoff_)
            current_ms_ = std::min<int>(current_ms_ * 2, 30000);
    }

    /**
     * @brief Return the number of reconnect attempts made since the last reset().
     * @return Current attempt count.
     */
    int32_t attemptCount() const { return attempts_; }

private:
    int32_t  base_interval_ms_; ///< Base wait between retries in milliseconds.
    int32_t  max_retries_;       ///< Maximum attempts; -1 = unlimited.
    bool use_backoff_;       ///< Whether to double the interval on each failure.
    int32_t  attempts_   {0};    ///< Attempts since last reset().
    int32_t  current_ms_ {0};    ///< Current wait interval (grows with back-off).

};

#endif //DLT_GATEWAY_TCPSERVER_H