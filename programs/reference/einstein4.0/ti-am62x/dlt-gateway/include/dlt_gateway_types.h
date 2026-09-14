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

#ifndef DLT_GATEWAY_TYPES_H
#define DLT_GATEWAY_TYPES_H

#include <cstdint>
#include <string>
#include <vector>
#include <atomic>

/**
 * @brief Identifies the physical transport used by a remote core.
 *
 * The value is read from the @c TransportType key inside
 * @c [DltGatewayConfiguration] of the INI file and stored in both
 * @ref DltConfig (global default) and each @ref CoreConfig (per-core override).
 */
enum class TransportType : uint8_t
{
    Unknown       = 0, ///< Uninitialised / parse error — must not be used at runtime.
    SharedMemory  = 1, ///< Physical shared-memory window mapped via /dev/mem or shm_open().
    Uart          = 2, ///< UART serial device (e.g. /dev/ttyS0).
    Spi           = 3  ///< SPI device (e.g. /dev/spidev0.0).
};

/**
 * @brief Parse a TransportType from its INI string representation.
 *
 * @param s  String as it appears in the INI file: @c "SharedMemory", @c "UART", @c "SPI".
 * @return   Corresponding @ref TransportType, or @c TransportType::Unknown on mismatch.
 */
inline TransportType parseTransportType(const std::string& s) {
    if (s == "SharedMemory") return TransportType::SharedMemory;
    if (s == "UART"        ) return TransportType::Uart;
    if (s == "SPI"         ) return TransportType::Spi;
    return TransportType::Unknown;
}

/**
 * @brief Return the canonical INI string for a TransportType value.
 *
 * @param t  Transport type to convert.
 * @return   Null-terminated string literal suitable for logging or writing back to INI.
 */
inline const char* transportTypeName(TransportType t) {
    switch (t) {
        case TransportType::SharedMemory: return "SharedMemory";
        case TransportType::Uart:         return "UART";
        case TransportType::Spi:          return "SPI";
        default:                          return "Unknown";
    }
}

/**
 * @brief Parameters specific to the SharedMemory transport.
 *
 * Populated when @c CoreConfig::transport == @c TransportType::SharedMemory.
 * The @c ShmAddress and @c ShmSize together define the physical memory window
 * that SharedMemoryReader will map into the process address space.
 */
struct ShmAddrConfig_t {
    uint64_t    ShmAddress {0}; ///< Physical base address (ShmStartAddress in INI). Hex or decimal.
    std::size_t ShmSize    {0}; ///< Total window size in bytes (ShmSize in INI).
};

/**
 * @brief Parameters shared by the UART and SPI serial transports.
 *
 * Populated when @c CoreConfig::transport is @c TransportType::Uart or
 * @c TransportType::Spi.  Both transports use the same INI keys
 * (@c DeviceId, @c Speed, @c FlowCtlr) because SPI in this project
 * operates in a UART-framed mode.
 */
struct UartSpiConfig_t
{
    std::string device_id;              ///< OS device path (DeviceId in INI), e.g. @c /dev/ttyS0.
    uint32_t    speed        {0};       ///< Baud rate / clock frequency in Hz (Speed in INI).
    int         flow_control {0};       ///< Hardware flow control: 0 = disabled, 1 = enabled (FlowCtlr in INI).
};

/**
 * @brief Configuration for a single named DLT buffer within a core's SHM window.
 *
 * Each @c [CoreNBufferM] section in the INI file maps to one @c BufferConfig.
 * The @c position field is the bit index inside the @c uint8_t notification
 * bitmask delivered by the IPCL callback; it must be unique across all buffers
 * of all cores.
 *
 * @note @c start_address is only meaningful for SharedMemory transport.
 *       For UART/SPI transport it is left as zero.
 */
struct SCoreBuffConfig_t
{
    std::string  name;                  ///< Section name from INI, e.g. @c "Core0Buffer0". Used for logging.
    uint64_t     BufStartAddress {0};   ///< Physical start address of this buffer (BufferStartAddress). SHM only.
    std::size_t  BufSize         {0};   ///< Maximum payload size in bytes (BufferSize in INI).
    int          Pos             {0};   ///< Bit position in the IPCL notification bitmask (Position in INI).
};

/**
 * @brief Configuration for one remote core.
 *
 * Maps to a @c [CoreN] section in the INI file.  The @c section_name field
 * holds the literal section name (e.g. @c "Core0"), while @c name holds the
 * human-readable core identifier (e.g. @c "VIP") read from the @c Name key.
 *
 * Only the transport-specific parameter block matching @c transport is
 * populated; the other remains default-initialised.
 */
struct SCoreConfig_t
{
    std::string   CoreName;                           ///< INI section name, e.g. @c "Core0".
    int32_t       ServerPort {0};                     ///< Server Port
    uint8_t       NumBuffers {0};                     ///< Number of buffers in each core
    TransportType transport {TransportType::Unknown}; ///< Physical transport for this core.

    ShmAddrConfig_t     Shm;                          ///< Shared-memory parameters. Valid only when transport == SharedMemory.
    UartSpiConfig_t Serial;                           ///< Serial parameters. Valid only when transport == Uart or Spi.

    std::vector<SCoreBuffConfig_t*> BuffConfig;       ///< Ordered list of buffers declared under this core.
};

/**
 * @brief Top-level gateway configuration.
 *
 * Maps to the @c [DltGatewayConfiguration] section in the INI file.
 * Populated by @ref ConfigParser and subsequently treated as
 * read-only by all other components.
 */
struct SDltGateWayConfig_t
{
    uint8_t      NumCores            {0};             ///< Number of cores supported.
    std::string  ServerIpAddr        {"127.0.0.1"};   ///< Server IP Address.
    int          ReconnectIntervalMs {2000};          ///< Base reconnect wait in ms (ReconnectIntervalMS).
    int          ReconnectMaxRetries {-1};            ///< Max reconnect attempts; -1 = unlimited (ReconnectMaxRetries).
    std::string  TransportTypeStr;
    TransportType transport {TransportType::Unknown}; ///< Global default transport (TransportType).
    std::vector<SCoreConfig_t *> CoreConfig;          ///< Ordered list of cores (Core_0 … Core_N).
};


/**
 * @brief Runtime message envelope carrying a raw DLT payload between components.
 *
 * A @c DltMessage is produced by @ref CoreHandler (after copying data from SHM
 * or reading a serial frame) and consumed by @ref DltGateway's dispatch thread,
 * which forwards it to dlt-daemon via @ref DltTcpClient.
 *
 * The @c payload vector contains the raw DLT bytes as they appear in shared
 * memory.  For SharedMemory transport the buffer typically holds multiple
 * back-to-back DLT frames; @ref DltValidator::scanBuffer() is used to find the
 * valid byte range before transmission.
 */
struct SDltMsg_t
{
    std::string           core_name;      ///< Human-readable core name (CoreConfig::name), e.g. @c "VIP".
    std::string           buffer_name;    ///< Buffer section name (BufferConfig::name), e.g. @c "Core0Buffer0".
    std::vector<uint8_t>  payload;        ///< Raw DLT bytes copied from SHM or read from serial device.
    std::size_t           length   {0};   ///< Number of valid bytes in @c payload.
};


#endif //DLT_GATEWAY_TYPES_H