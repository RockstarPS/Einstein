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
 * @file dlt_gateway_shm_adaptor.cpp
 * @author dmuruge5/gsoundar
 * @brief 
 * @version 0.1
 * @date 2026-06-01
 * 
 */

#include <cstring>
#include <algorithm>
#include "dlt_gateway_shm_reader.h"
#include "dk_logger.h"

LOG_IMPORT_CONTEXT ( gDLTGWLogContext );

bool DltShmReader::openDevice(const SCoreConfig_t& core)
{
    bool ret = true;
    if (core.transport == TransportType::SharedMemory)
    {
        mBaseAddr = core.Shm.ShmAddress;
        mWindowSize = core.Shm.ShmSize;

        mMapfd = open("/dev/mem", O_RDONLY | O_SYNC);
        if (mMapfd < 0)
        {
            LOGE(&gDLTGWLogContext, "Failed to open dev/mem()", strerror(errno));
            ret = false;
        }
        else
        {
            // mmap offset must be page-aligned
            const long page   = sysconf(_SC_PAGESIZE);
            uint64_t aligned  = mBaseAddr & ~static_cast<uint64_t>(page - 1);
            mPage_offset      = static_cast<std::size_t>(mBaseAddr - aligned);
            std::size_t msize = mWindowSize + mPage_offset;

            mpMapAddr = mmap(nullptr, msize, PROT_READ, MAP_SHARED, mMapfd, static_cast<off_t>(aligned));
            if (mpMapAddr == MAP_FAILED)
            {
                LOGE(&gDLTGWLogContext, "Failed to open mmap()", strerror(errno));
                close(mMapfd);
                mMapfd = -1;
                ret = false;
            }
            else
            {
                mMapSize       = msize;
                mEffectiveBase = static_cast<uint8_t*>(mpMapAddr) + mPage_offset;
            }
        }
    }
    return ret;
}

SDltMsg_t DltShmReader::readBuffer(const SCoreBuffConfig_t& bufConfig,
                        const uint32_t data_len) const
{
    if (!mEffectiveBase)
        return {};

    // Byte offset of this buffer within the mapped window
    if (bufConfig.BufStartAddress < mBaseAddr)
        return {};

    uint64_t offset = bufConfig.BufStartAddress - mBaseAddr;

    if (offset + bufConfig.BufSize > mWindowSize)
    {
        LOGE(&gDLTGWLogContext, "buffer is out of range");
        return {};
    }

    std::size_t copy_len =(data_len > 0)? std::min(static_cast<std::size_t>(data_len), bufConfig.BufSize): bufConfig.BufSize;

    SDltMsg_t msg;
    msg.length = copy_len;
    msg.payload.resize(copy_len);
    std::memcpy(msg.payload.data(),
                    static_cast<const uint8_t*>(mEffectiveBase) + offset,
                    copy_len);
    return msg;
}