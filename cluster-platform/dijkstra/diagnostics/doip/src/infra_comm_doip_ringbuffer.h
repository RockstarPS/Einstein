//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2018] Visteon Corporation
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
///
/// @file infra_comm_doip_ringbuffer.h
/// @ingroup DOIP
///
/// @brief  CRingBuffer Class. CRingBuffer shall provide buffer to store the data in a queue.
///         The maximum size of the ring buffer is 7000 bytes. It provides interface for read and write into the ring
///         buffer. Ring buffer init should be invoked before write into the buffer
//---------------------------------------------------------------------------------------------------------------------
//

#ifndef INFRA_COMM_DOIP_RINGBUFFER_H
#define INFRA_COMM_DOIP_RINGBUFFER_H

#include <stdint.h>
#include <string.h>
#include <unistd.h>

#define RING_BUFFER_SIZE 263168

class CRingBuffer
{
public:

    ///  @brief  Ring Buffer Structure
    struct SRingBufferType
    {
        uint8_t  data[RING_BUFFER_SIZE];    ///< Buffer to hold the data
        uint16_t read_index;                ///< Last read position
        uint16_t write_index;               ///< Last write position
        uint16_t fill_count;                ///< Number of bytes in the buffer
    };

    ///
    ///  @brief     Initializes the Ring buffer with ReadIndex, write index and fill count
    ///
    ///  @param[in] *buffer  Pointer to the ring buffer to initialize
    ///
    ///  @return    None
    ///
    void init ( SRingBufferType *buffer );
    ///
    ///     @brief  Write the data into ring buffer and update the write index
    ///
    ///     @param[in]  *buffer Pointer to the ring buffer
    ///
    ///     @param[in]  *data  Pointer to the source buffer
    ///
    ///     @param[in]   size   Size of the data buffer
    ///
    ///     @return  0    - Not enough space to write the data
    ///          Non-Zero - Number of bytes actually written into the buffer
    ///
    uint16_t write ( SRingBufferType *buffer, const uint8_t *data, uint16_t size );
    ///
    ///     @brief  Write the data into ring buffer and update the write index
    ///
    ///     @param[in]  *buffer Pointer to the ring buffer
    ///
    ///     @param[in]  *data  Pointer to the destination buffer
    ///
    ///     @param[in]   size   Size of the data buffer
    ///
    ///     @return  Number of bytes actually written into the buffer
    ///
    uint16_t read ( SRingBufferType *buffer, uint8_t *data, uint16_t size );
    ///
    ///     @brief  Write the data into ring buffer and update the write index
    ///
    ///     @param[in]  *buffer Pointer to the ring buffer

    void    reset (SRingBufferType *buffer);
    ///
    ///     @brief  Check the integrity of the data in buffer
    ///
    ///     @param[in]  *buffer Pointer to the ring buffer
    ///     @param[in]  *the header string
    ///     @return  0 in case of success
    uint8_t poll ( SRingBufferType *buffer,uint8_t* headString);

};
#endif //INFRA_COMM_DOIP_H
