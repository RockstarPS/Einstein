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
 * @file dlt_shm_writer.cpp
 * @author dmuruge5
 * @brief Frames a DLT (Diagnostic Log and Trace) protocol message per the
 *        AUTOSAR/GENIVI DLT specification and writes the framed buffer into
 *        a fixed physical shared-memory region on a Linux target, using /dev/mem + mmap().
 *
 */

#include <cstdint>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <stdexcept>

#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
/*****************************************************************************************************
+---------------------------+
| Standard Header (4bytes)  |
+---------------------------+
| ECU ID (optional)(4bytes) |
+---------------------------+
| Session ID (4bytes)       |
+---------------------------+
| Timestamp (4bytes)        |
+---------------------------+
| Extended Header (10bytes) |
+------------------+
| Payload          |
+------------------+


+----------------------------------------------------------------+
Standared Header (4bytes)
+----------------------------------------------------------------+
htyp (1byte) - Header type file_handle

Bit 0 : UEH  -> Extended Header present
Bit 1 : MSBF -> Big Endian
Bit 2 : WEID -> ECU ID present
Bit 3 : WSID -> Session ID present
Bit 4 : WTMS -> Timestamp present
Bit 5-7 : Protocol version

mcnt (1byte) - Message counter

len (2bytes) - Total DLT message length (Standard Header+ ECU ID + Session ID + Timestamp + Extended Header + Payload)
====================================================================

+----------------------------------------------------------------+
Extended Header (10bytes)
+----------------------------------------------------------------+
msin (1byte) - Message info field

Bit 0     : VERB
Bit 1-3   : MSTP (Message Type)
Bit 4-7   : MTIN (Type Info)

MSTP values
0 = LOG
1 = APP_TRACE
2 = NW_TRACE
3 = CONTROL

MTIN values (log value)
1 = FATAL
2 = ERROR
3 = WARN
4 = INFO
5 = DEBUG
6 = VERBOSE

noar (1 byte) - Number Of ARguments.

apid (4 bytes) - Application ID.

ctid (4 bytes) - Context ID.
=============================================================================

********************************************************************************************************/

namespace dlt {

// ---------------------------------------------------------------------------
// DLT protocol constants (see AUTOSAR/GENIVI DLT specification)
// ---------------------------------------------------------------------------

/// HTYP bit masks (standard header "type" byte)
namespace HtypBits {
    constexpr uint8_t UEH  = 0x01; ///< Use Extended Header
    constexpr uint8_t MSBF = 0x02; ///< Most Significant Byte First (big endian payload)
    constexpr uint8_t WEID = 0x04; ///< With ECU ID
    constexpr uint8_t WSID = 0x08; ///< With Session ID
    constexpr uint8_t WTMS = 0x10; ///< With Timestamp
    constexpr uint8_t VERS_SHIFT = 5; ///< Version number occupies bits 5-7
}

/// MSIN bit masks / shifts (extended header "message info" byte)
namespace MsinBits {
    constexpr uint8_t VERB       = 0x01; ///< Verbose mode
    constexpr uint8_t MSTP_SHIFT = 1;    ///< Message type, bits 1-3
    constexpr uint8_t MTIN_SHIFT = 4;    ///< Message type info, bits 4-7
}

/// Type Info bit masks for verbose-mode arguments (one 32-bit Type Info
/// field precedes every argument's data when MSIN.VERB is set). See the
/// AUTOSAR/GENIVI DLT specification, "Basic DLT Message Format".
namespace TypeInfoBits {
    constexpr uint32_t TYLE_MASK   = 0x0000000F; ///< type length, bits 0-3
    constexpr uint32_t TYLE_8BIT   = 0x00000001;
    constexpr uint32_t TYLE_16BIT  = 0x00000002;
    constexpr uint32_t TYLE_32BIT  = 0x00000003;
    constexpr uint32_t TYLE_64BIT  = 0x00000004;
    constexpr uint32_t TYLE_128BIT = 0x00000005;

    constexpr uint32_t BOOL = 0x00000010; ///< Boolean
    constexpr uint32_t SINT = 0x00000020; ///< Signed integer
    constexpr uint32_t UINT = 0x00000040; ///< Unsigned integer
    constexpr uint32_t FLOA = 0x00000080; ///< Float
    constexpr uint32_t STRG = 0x00000200; ///< String
    constexpr uint32_t RAWD = 0x00000400; ///< Raw data

    constexpr uint32_t SCOD_SHIFT = 15;   ///< String coding, bits 15-17
    constexpr uint32_t SCOD_ASCII = 0x00000000;
    constexpr uint32_t SCOD_UTF8  = (1u << SCOD_SHIFT);
}

enum class MessageType : uint8_t {
    DLT_TYPE_LOG   = 0x0,
    DLT_TYPE_APP_TRACE = 0x1,
    DLT_TYPE_NW_TRACE  = 0x2,
    DLT_TYPE_CONTROL   = 0x3,
};

enum class LogLevel : uint8_t {
    DLT_LOG_FATAL = 0x1,
    DLT_LOG_ERROR = 0x2,
    DLT_LOG_WARN  = 0x3,
    DLT_LOG_INFO  = 0x4,
    DLT_LOG_DEBUG = 0x5,
    DLT_LOG_VERBOSE = 0x6,
};

/**
 * @brief Helper to append multi-byte fields to a byte buffer in a chosen
 *        endianness (DLT standard/extended header IDs are 4 raw ASCII bytes;
 *        numeric fields such as LEN/timestamp are big-endian by convention
 *        unless MSBF signals otherwise for the payload).
 */
class ByteWriter {
public:
    explicit ByteWriter(std::vector<uint8_t>& buf) : buf_(buf) {}

    void putU8(uint8_t v)
    {
        buf_.push_back(v);
    }

    void putU16BE(uint16_t v)
    {
        buf_.push_back(static_cast<uint8_t>((v >> 8) & 0xFF));
        buf_.push_back(static_cast<uint8_t>(v & 0xFF));
    }

    void putU32BE(uint32_t v)
    {
        buf_.push_back(static_cast<uint8_t>((v >> 24) & 0xFF));
        buf_.push_back(static_cast<uint8_t>((v >> 16) & 0xFF));
        buf_.push_back(static_cast<uint8_t>((v >> 8) & 0xFF));
        buf_.push_back(static_cast<uint8_t>(v & 0xFF));
    }

    /// Writes a 4-character ID (ECU ID / APID / CTID), space-padded/truncated.
    void putId4(const std::string& id)
    {
        char raw[4] = {'-', '-', '-', '-'};
        std::memcpy(raw, id.data(), std::min<size_t>(4, id.size()));
        buf_.insert(buf_.end(), raw, raw + 4);
    }

    void putBytes(const uint8_t* data, size_t len)
    {
        buf_.insert(buf_.end(), data, data + len);
    }

    // --- Little-endian putters -------------------------------------------
    // Used for verbose-mode argument Type Info + argument data: since this
    // framer never sets HTYP.MSBF, payload data is little-endian per the
    // DLT spec (only the standard-header numeric fields are always BE).
    void putU16LE(uint16_t v)
    {
        buf_.push_back(static_cast<uint8_t>(v & 0xFF));
        buf_.push_back(static_cast<uint8_t>((v >> 8) & 0xFF));
    }

    void putU32LE(uint32_t v)
    {
        buf_.push_back(static_cast<uint8_t>(v & 0xFF));
        buf_.push_back(static_cast<uint8_t>((v >> 8) & 0xFF));
        buf_.push_back(static_cast<uint8_t>((v >> 16) & 0xFF));
        buf_.push_back(static_cast<uint8_t>((v >> 24) & 0xFF));
    }

    void putI32LE(int32_t v)
    {
        putU32LE(static_cast<uint32_t>(v));
    }

    void putF64LE(double v)
    {
        uint64_t bits;
        std::memcpy(&bits, &v, sizeof(bits));
        for (int i = 0; i < 8; ++i)
        {
            buf_.push_back(static_cast<uint8_t>((bits >> (8 * i)) & 0xFF));
        }
    }

private:
    std::vector<uint8_t>& buf_;
};

/**
 * @brief Describes the fields needed to frame one non-verbose or verbose
 *        DLT log message. Only the subset commonly needed for a gateway /
 *        forwarder is exposed here.
 */
struct DltMessageParams {
    std::string ecuId    = "ECU1";
    std::string appId    = "APP1";
    std::string ctxId    = "CTX1";
    uint32_t    sessionId = 1;
    uint8_t     msgCounter = 0;
    LogLevel    logLevel   = LogLevel::DLT_LOG_INFO;
    bool        verbose    = false;
    std::vector<uint8_t> payload; ///< raw payload (non-verbose) or
                                   ///< concatenated [TypeInfo+data] arguments (verbose)
    uint8_t     argCount   = 0;   ///< NOAR: number of verbose arguments packed into payload
};

/**
 * @brief Appends one verbose-mode argument (Type Info field + data) to a
 *        DltMessageParams' payload and bumps its argument count (NOAR).
 *        Only used when DltMessageParams::verbose is true; for non-verbose
 *        messages, populate DltMessageParams::payload directly instead.
 */
class VerboseArgumentBuilder {
public:
    static void addBool(DltMessageParams& p, bool value)
    {
        ByteWriter w(p.payload);
        w.putU32LE(TypeInfoBits::BOOL | TypeInfoBits::TYLE_8BIT);
        w.putU8(value ? 1 : 0);
        ++p.argCount;
    }

    static void addInt32(DltMessageParams& p, int32_t value)
    {
        ByteWriter w(p.payload);
        w.putU32LE(TypeInfoBits::SINT | TypeInfoBits::TYLE_32BIT);
        w.putI32LE(value);
        ++p.argCount;
    }

    static void addUint32(DltMessageParams& p, uint32_t value)
    {
        ByteWriter w(p.payload);
        w.putU32LE(TypeInfoBits::UINT | TypeInfoBits::TYLE_32BIT);
        w.putU32LE(value);
        ++p.argCount;
    }

    static void addFloat64(DltMessageParams& p, double value)
    {
        ByteWriter w(p.payload);
        w.putU32LE(TypeInfoBits::FLOA | TypeInfoBits::TYLE_64BIT);
        w.putF64LE(value);
        ++p.argCount;
    }

    /// DLT strings carry an explicit 2-byte (LE) length that INCLUDES the
    /// terminating NUL, followed by the NUL-terminated string bytes.
    static void addString(DltMessageParams& p, const std::string& value, bool utf8 = true)
    {
        ByteWriter w(p.payload);
        uint32_t typeInfo = TypeInfoBits::STRG |
                             (utf8 ? TypeInfoBits::SCOD_UTF8 : TypeInfoBits::SCOD_ASCII);
        w.putU32LE(typeInfo);
        uint16_t lenWithNul = static_cast<uint16_t>(value.size() + 1);
        w.putU16LE(lenWithNul);
        w.putBytes(reinterpret_cast<const uint8_t*>(value.data()), value.size());
        w.putU8(0x00); // NUL terminator
        ++p.argCount;
    }
};

/**
 * @brief Frames a single DLT message (standard header + extended header +
 *        payload) per the DLT protocol and returns the serialized bytes,
 *        ready to be sent to dlt-daemon or stored/forwarded elsewhere.
 */
class DltMessageFramer {
public:
    std::vector<uint8_t> frame(const DltMessageParams& p) const
    {
        std::vector<uint8_t> out;
        ByteWriter w(out);

        // --- Standard header ---
        uint8_t htyp = HtypBits::UEH | HtypBits::WEID | HtypBits::WSID | HtypBits::WTMS;
        htyp |= (1 << HtypBits::VERS_SHIFT); // protocol version 1

        w.putU8(htyp);
        w.putU8(p.msgCounter);
        // LEN is patched after we know the full message size; reserve 2 bytes now.
        size_t lenFieldOffset = out.size();
        w.putU16BE(0);

        w.putId4(p.ecuId);                                   // WEID
        w.putU32BE(p.sessionId);                              // WSID
        w.putU32BE(static_cast<uint32_t>(currentTimestamp())); // WTMS (0.1ms ticks)

        // --- Extended header ---
        uint8_t msin = 0;
        if (p.verbose) msin |= MsinBits::VERB;
        msin |= (static_cast<uint8_t>(MessageType::DLT_TYPE_LOG) << MsinBits::MSTP_SHIFT);
        msin |= (static_cast<uint8_t>(p.logLevel) << MsinBits::MTIN_SHIFT);

        w.putU8(msin);
        // NOAR: number of arguments. For verbose messages this must match
        // the number of [TypeInfo+data] arguments packed into p.payload
        // (see VerboseArgumentBuilder); non-verbose messages carry raw
        // payload bytes with no argument framing, so NOAR is 0.
        w.putU8(p.verbose ? p.argCount : 0);
        w.putId4(p.appId);
        w.putId4(p.ctxId);

        // --- Payload ---
        // Non-verbose: p.payload is raw application bytes.
        // Verbose: p.payload is the concatenation of per-argument
        // [TypeInfo(4B LE)][data] blocks built via VerboseArgumentBuilder.
        w.putBytes(p.payload.data(), p.payload.size());

        // Patch LEN (total message length, big-endian, includes everything above)
        uint16_t totalLen = static_cast<uint16_t>(out.size());
        out[lenFieldOffset]     = static_cast<uint8_t>((totalLen >> 8) & 0xFF);
        out[lenFieldOffset + 1] = static_cast<uint8_t>(totalLen & 0xFF);

        printf("payload length %ld \n", p.payload.size());
        printf("Total length %d \n", totalLen);
        return out;
    }

private:
    /// DLT timestamps are typically 0.1ms resolution, free-running since boot.
    static uint64_t currentTimestamp()
    {
        struct timespec ts{};
        clock_gettime(CLOCK_MONOTONIC, &ts);
        uint64_t ticks = static_cast<uint64_t>(ts.tv_sec) * 10000ULL +
                          static_cast<uint64_t>(ts.tv_nsec) / 100000ULL;
        return ticks;
    }
};

// ---------------------------------------------------------------------------
// Shared memory writer: maps a fixed physical address via /dev/mem and
// writes a small framed record.
// ---------------------------------------------------------------------------

class SharedMemoryWriter {
public:
    SharedMemoryWriter(uintptr_t physAddr, size_t regionSize)
        : physAddr_(physAddr), regionSize_(regionSize)
    {
        openAndMap();
    }

    ~SharedMemoryWriter()
    {
        if (mapBase_ != MAP_FAILED && mapBase_ != nullptr)
        {
            munmap(mapBase_, regionSize_);
        }
        if (fd_ >= 0)
        {
            close(fd_);
        }
    }

    SharedMemoryWriter(const SharedMemoryWriter&) = delete;
    SharedMemoryWriter& operator=(const SharedMemoryWriter&) = delete;

    /// Writes [frame bytes] into the mapped region.
    void writeFrame(const std::vector<uint8_t>& frame)
    {
        const size_t recordSize = frame.size();

        if (recordSize > regionSize_)
        {
            throw std::runtime_error("DLT frame does not fit in mapped shared memory region");
        }
        if ((reinterpret_cast<uintptr_t>(mapBase_) % sizeof(uint32_t)) != 0)
        {
            throw std::runtime_error("Mapped base is not 4-byte aligned; cannot do safe word writes");
        }

        // Stage frame bytes in normal (cacheable, unaligned-
        // access-safe) heap memory, padded up to a whole number of words.
        const size_t paddedSize = (recordSize + (sizeof(uint32_t) - 1)) & ~(sizeof(uint32_t) - 1);
        std::vector<uint8_t> staging(paddedSize, 0);

        if (!frame.empty())
        {
            std::memcpy(staging.data(), frame.data(), frame.size());
        }

        // Push the staged record out as aligned 32-bit volatile writes.
        auto* dst = static_cast<volatile uint32_t*>(mapBase_);
        const size_t wordCount = paddedSize / sizeof(uint32_t);
        for (size_t i = 0; i < wordCount; ++i)
        {
            uint32_t word;
            std::memcpy(&word, staging.data() + i * sizeof(uint32_t), sizeof(word));
            dst[i] = word; // aligned 32-bit store; safe on device-type memory
        }
    }

private:
    void openAndMap()
    {
        fd_ = open(kMemDevicePath, O_RDWR | O_SYNC);
        if (fd_ < 0)
        {
            throw std::runtime_error(std::string("Failed to open ") + kMemDevicePath +
                                      ": " + std::strerror(errno));
        }

        long pageSize = sysconf(_SC_PAGESIZE);
        uintptr_t pageMask = static_cast<uintptr_t>(pageSize) - 1;
        uintptr_t alignedAddr = physAddr_ & ~pageMask;
        size_t offsetInPage = physAddr_ - alignedAddr;
        size_t mapLen = ((offsetInPage + regionSize_ + pageMask) & ~pageMask);

        void* mapped = mmap(nullptr, mapLen, PROT_READ | PROT_WRITE, MAP_SHARED,
                             fd_, static_cast<off_t>(alignedAddr));
        if (mapped == MAP_FAILED)
        {
            close(fd_);
            fd_ = -1;
            throw std::runtime_error(std::string("mmap() failed for physical address 0x") +
                                      toHex(physAddr_) + ": " + std::strerror(errno));
        }

        mapBase_ = static_cast<uint8_t*>(mapped) + offsetInPage;
        mapAllocBase_ = mapped;
        mapAllocLen_ = mapLen;
    }

    static std::string toHex(uintptr_t v)
    {
        char buf[32];
        std::snprintf(buf, sizeof(buf), "%lx", static_cast<unsigned long>(v));
        return buf;
    }

    static constexpr const char* kMemDevicePath = "/dev/mem";

    uintptr_t physAddr_;
    size_t regionSize_;
    int fd_ = -1;
    void* mapBase_ = nullptr;       ///< pointer adjusted to the exact requested address
    void* mapAllocBase_ = nullptr;  ///< page-aligned base actually returned by mmap
    size_t mapAllocLen_ = 0;        ///< page-aligned length actually mapped
};

} // namespace dlt

struct Args {
    std::string ecuId;
    uintptr_t   physAddr;
    size_t      regionSize;
};

void printUsage(const char* argv0)
{
    std::fprintf(stderr,
        "Usage: %s <ecu_id> <phys_addr_hex> <region_size_hex>\n"
        "  ecu_id            4-char (or shorter) ECU ID string, e.g. ECU1\n"
        "  phys_addr_hex     shared memory physical base address in hex,\n"
        "                    e.g. 0x82385000 or 82385000\n"
        "  region_size_hex   mapped region size in hex, e.g. 0x1000 or 1000\n",
        argv0);
}

/// Parses a hex string with an optional \"0x\"/\"0X\" prefix. Throws
/// std::invalid_argument if the string is empty or contains non-hex
/// characters after the optional prefix.
uintptr_t parseHex(const std::string& raw, const char* argName)
{
    std::string s = raw;
    if (s.size() > 1 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    {
        s = s.substr(2);
    }
    if (s.empty())
    {
        throw std::invalid_argument(std::string(argName) + ": empty hex value");
    }
    for (char c : s)
    {
        if (!std::isxdigit(static_cast<unsigned char>(c)))
        {
            throw std::invalid_argument(std::string(argName) + ": '" + raw +
                                         "' is not a valid hex value");
        }
    }

    errno = 0;
    char* end = nullptr;
    unsigned long long value = std::strtoull(s.c_str(), &end, 16);
    if (errno == ERANGE || end == s.c_str() || *end != '\0')
    {
        throw std::invalid_argument(std::string(argName) + ": '" + raw +
                                     "' could not be parsed as hex");
    }
    return static_cast<uintptr_t>(value);
}

Args parse(int argc, char** argv)
{
    if (argc != 4)
    {
        printUsage(argv[0]);
        throw std::invalid_argument("expected exactly 3 arguments");
    }

    Args args;
    args.ecuId = argv[1];
    if (args.ecuId.empty())
    {
        throw std::invalid_argument("ecu_id must not be empty");
    }
    if (args.ecuId.size() > 4)
    {
        std::fprintf(stderr,
            "Warning: ecu_id '%s' is longer than 4 characters; it will be "
            "truncated to '%.4s' in the DLT header.\n",
            args.ecuId.c_str(), args.ecuId.c_str());
    }

    args.physAddr   = parseHex(argv[2], "phys_addr_hex");
    args.regionSize = static_cast<size_t>(parseHex(argv[3], "region_size_hex"));
    if (args.regionSize == 0)
    {
        throw std::invalid_argument("region_size_hex must be non-zero");
    }

    return args;
}

int main(int argc, char** argv)
{
    Args args;
    try {
        args = parse(argc, argv);
    } catch (const std::invalid_argument& e) {
        std::fprintf(stderr, "Error: %s\n", e.what());
        return 1;
    }

    dlt::DltMessageFramer framer;

    // --- Non-verbose example ---------------------
    dlt::DltMessageParams nvParams;
    nvParams.ecuId      = args.ecuId;
    nvParams.appId      = "GATW";
    nvParams.ctxId      = "MAIN";
    nvParams.sessionId  = 42;
    nvParams.msgCounter = 1;
    nvParams.logLevel   = dlt::LogLevel::DLT_LOG_INFO;
    nvParams.verbose    = false;

    const char* text = "DLT gateway shared-memory test message";
    nvParams.payload.assign(reinterpret_cast<const uint8_t*>(text),
                             reinterpret_cast<const uint8_t*>(text) + std::strlen(text));

    std::vector<uint8_t> nvFrame = framer.frame(nvParams);
    std::printf("Framed non-verbose DLT message: %zu bytes\n", nvFrame.size());

    // --- Verbose example ------------------------------------------------
    // Each argument gets its own Type Info + data block; NOAR is filled in
    // automatically from argCount, so just add arguments in order.
    dlt::DltMessageParams vParams;
    vParams.ecuId      = args.ecuId;
    vParams.appId      = "GATW";
    vParams.ctxId      = "MAIN";
    vParams.sessionId  = 42;
    vParams.msgCounter = 2;
    vParams.logLevel   = dlt::LogLevel::DLT_LOG_INFO;
    vParams.verbose    = true;

    dlt::VerboseArgumentBuilder::addString(vParams, "shm write status");
    dlt::VerboseArgumentBuilder::addUint32(vParams, static_cast<uint32_t>(args.physAddr));
    dlt::VerboseArgumentBuilder::addBool(vParams, true);

    std::vector<uint8_t> vFrame = framer.frame(vParams);
    std::printf("Framed verbose DLT message: %zu bytes, %u argument(s)\n",
                vFrame.size(), vParams.argCount);

    try {
        dlt::SharedMemoryWriter shmWriter(args.physAddr, args.regionSize);
        // Writes one frame per run; swap nvFrame/vFrame as needed,
        // or extend writeFrame()/layout to hold both if you need them
        // resident simultaneously.
        shmWriter.writeFrame(vFrame);
        std::printf("Wrote verbose DLT frame to shared memory at 0x%lx\n",
                    static_cast<unsigned long>(args.physAddr));
    } catch (const std::exception& e) {
        std::fprintf(stderr, "Error: %s\n", e.what());
        return 1;
    }

    return 0;
}

/*
--------------------------------------------------------------
           Test Execution
--------------------------------------------------------------

++++++++++++++++++++++++++++++++++++++++++++++++++++
              Command to Write all buffers
++++++++++++++++++++++++++++++++++++++++++++++++++++
/system/usr/bin/dlt_shm_write VIP0 0x82385000 0x800
/system/usr/bin/dlt_shm_write VIP0 0x82385800 0x800
/system/usr/bin/dlt_shm_write VIP0 0x82386000 0x1000
/system/usr/bin/dlt_shm_write HSM- 0x82387000 0x800
/system/usr/bin/dlt_shm_write HSM- 0x82387800 0x800
/system/usr/bin/dlt_shm_write DM-- 0x82388000 0x800
/system/usr/bin/dlt_shm_write DM-- 0x82388800 0x800

+++++++++++++++++++++++++++++++++++++++++++++++++++++
Test case 1: Read Buffers one by one
+++++++++++++++++++++++++++++++++++++++++++++++++++++
vmf_sender -g137 -e0 -l4 -f00000100 -c1
vmf_sender -g137 -e0 -l4 -f00000200 -c1
vmf_sender -g137 -e0 -l4 -f00000400 -c1
vmf_sender -g137 -e0 -l4 -f00000800 -c1
vmf_sender -g137 -e0 -l4 -f00001000 -c1
vmf_sender -g137 -e0 -l4 -f00002000 -c1
vmf_sender -g137 -e0 -l4 -f00004000 -c1
vmf_sender -g137 -e0 -l4 -f00008000 -c1

++++++++++++++++++++++++++++++++++++++++++++++++++++++
Test case 2: Read all buffers at same time
++++++++++++++++++++++++++++++++++++++++++++++++++++++
vmf_sender -g137 -e0 -l4 -f00007F00 -c1

++++++++++++++++++++++++++++++++++++++++++++++++++++++
Test case 3: Read Each core buffers one by one
++++++++++++++++++++++++++++++++++++++++++++++++++++++
vmf_sender -g137 -e0 -l4 -f00000100 -c1
vmf_sender -g137 -e0 -l4 -f00000800 -c1
vmf_sender -g137 -e0 -l4 -f00002000 -c1

+++++++++++++++++++++++++++++++++++++++++++++++++++++
Test case 3: Read each core buffers at same time
+++++++++++++++++++++++++++++++++++++++++++++++++++++
vmf_sender -g137 -e0 -l4 -f00002900 -c1

--------------------------------------------------------------*/