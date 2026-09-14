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
 * @file dlt_gateway_shm_reader.h
 * @brief Maps a physical shared-memory window and provides per-buffer copy-out.
 *
 * @details
 * @ref SharedMemoryReader maps the entire core window (defined by
 * @c ShmParams::start_address and @c ShmParams::size) into the process address
 * space with a single @c mmap() call.  Individual buffers are then accessed by
 * computing their byte offset from the core base address
 * (@c BufferConfig::start_address - @c ShmParams::start_address).
 *
 * @author  dmuruge5/gsoundar
 * @version 1.0
 */

#ifndef DLT_GATEWAY_SHM_READER_H
#define DLT_GATEWAY_SHM_READER_H

#include <sys/mman.h>
#include <unistd.h>
#include "dlt_gateway_types.h"

/**
 * @brief Maps a core's physical shared-memory window and copies buffer payloads.
 *
 * One instance is created per @ref CoreHandler for a SharedMemory-transport core.
 * The instance is non-copyable; ownership is held by the CoreHandler.
 *
 * @par Lifecycle
 * @code{.cpp}
 * SharedMemoryReader reader;
 * reader.open(coreConfig);             // map the window
 * DltMessage msg = reader.readBuffer(buf, "VIP", 2048);  // copy one buffer
 * // destructor unmaps automatically
 * @endcode
 */
class DltShmReader {
public:
    /// @brief Default constructor — no mapping performed until open() is called.
    DltShmReader() = default;

    /// @brief Non-copyable — ownership must be unique.
    DltShmReader(const DltShmReader&)            = delete;
    /// @brief Non-copy-assignable.
    DltShmReader& operator=(const DltShmReader&) = delete;
    /// @brief Move-constructible so CoreHandler can store it by value.
    DltShmReader(DltShmReader&&)                 = default;

    /**
     * @brief Unmap the shared-memory window and close the file descriptor.
     *
     * Safe to call on an instance that was never opened (no-op in that case).
     */
    ~DltShmReader()
    {
        if (mpMapAddr && mpMapAddr != MAP_FAILED)
            (void) munmap(mpMapAddr, mMapSize);

        if (mMapfd >= 0)
            (void) close(mMapfd);
    }

    /**
     * @brief Map the shared-memory window for the given core configuration.
     *
     * Opens and maps @c /dev/mem (physical address)
     *
     * @param core  Core configuration describing the window base address and size.
     * @return      @c true on success, @c false if the device could not be opened
     *              or the mapping failed.
     */
    bool openDevice(const SCoreConfig_t& core);

    /**
     * @brief Copy data from one named buffer's region within the mapped window.
     *
     * Computes the buffer's byte offset as
     * @c (buf.start_address - core_base_address), then performs a @c memcpy
     * of @p data_len bytes (or @c buf.size if @p data_len is zero) into a newly
     * allocated @ref SDltMsg_t.
     *
     * @param buf        Buffer descriptor from @ref CoreConfig::buffers.
     * @param data_len   Number of valid bytes to copy.  Pass @c 0 to copy the
     *                   full @c buf.size.
     * @return           Populated @ref SDltMsg_t, or an empty one on error.
     */
    SDltMsg_t readBuffer(const SCoreBuffConfig_t& bufConfig,
                        const uint32_t data_len) const;

private:
    uint64_t mBaseAddr {0};         ///< Physical core base address from ShmParams::start_address.
    std::size_t mWindowSize {0};    ///< Total mapped window size in bytes.
    int mMapfd {-1};                ///< File descriptor (/dev/mem or shm fd).
    void* mpMapAddr {nullptr};      ///< Raw pointer returned by mmap().
    void* mEffectiveBase {nullptr}; ///< map_ptr_ + page_offset_ (points to first byte of core window).
    std::size_t mMapSize {0};       ///< Total mmap size ( includes page_offset_).
    std::size_t mPage_offset {0};   ///< Bytes between page-aligned mmap start and core base.
};

#endif //DLT_GATEWAY_SHM_READER_H