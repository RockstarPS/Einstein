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
//---------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "infra_comm_doip_ringbuffer.h"
#include<vector>
#include "dk_logger.h"


LOG_IMPORT_CONTEXT ( gDoipLogContext );

void CRingBuffer::init ( SRingBufferType *buffer )
{
    /// Initialize variables
    buffer->read_index = 0u;
    buffer->write_index = 0u;
    buffer->fill_count = 0u;
    ( void ) memset ( buffer->data, 0xFF, RING_BUFFER_SIZE );
    LOGV ( &gDoipLogContext, "Ring Buffer initialized" );
}


uint16_t CRingBuffer::write ( SRingBufferType *buffer, const uint8_t *data, uint16_t size )
{
    uint16_t it = 0u;
    uint16_t wi = 0u;


    /// Check if we have enough space
    if ( size < ( RING_BUFFER_SIZE - buffer->fill_count ) )
    {
        wi = buffer->write_index;

        /// Copy data
        for ( it = 0u; it < size; it++ )
        {
            buffer->data[wi] = data[it];
            wi = ( wi + 1u ) % RING_BUFFER_SIZE;
        }

        /// Update the fill count and write index
        buffer->write_index = wi;
        buffer->fill_count += size;
        LOGI ( &gDoipLogContext, "Write Index ",  buffer->write_index,  buffer->fill_count );
    }
    else
    {
        size = 0u;
        LOGE ( &gDoipLogContext, "Size index fillcount ",  size, buffer->write_index, buffer->fill_count, RING_BUFFER_SIZE );
        LOGE ( &gDoipLogContext, "No enough Memory in Ring buffer" );
    }


    return size;
}

uint8_t CRingBuffer::poll ( SRingBufferType *buffer,uint8_t* headString)
{
    uint8_t ret=0U;
    uint16_t ri=0U;
    if(buffer->fill_count !=0)
    {

        ri = buffer->read_index;
        if(memcmp(buffer->data+ri,headString,2) != 0)
        {
            ret = 1;
        }
        else
        {
            ret = 0;
        }
    }
    return ret;

}
uint16_t CRingBuffer::read ( SRingBufferType *buffer, uint8_t *data, uint16_t size )
{
    uint16_t msg_len = 0u;
    uint16_t fill_cnt = 0u;
    uint16_t it = 0u;
    uint16_t ri = 0u;

    fill_cnt = buffer->fill_count;

    /// Check if buffer is empty
    if ( fill_cnt != 0u )
    {
        if ( size <= fill_cnt )
        {

            msg_len = size;
            ri = buffer->read_index;
            /// Copy data
            for ( it = 0u; it < msg_len; it++ )
            {
                data[it] = buffer->data[ri];
                ri = ( ri + 1u ) % RING_BUFFER_SIZE;
            }

            buffer->read_index = ri;
            buffer->fill_count -= msg_len;
            LOGI ( &gDoipLogContext, "Read Index",  buffer->read_index, buffer->fill_count );
        }
        else
        {
            LOGE ( &gDoipLogContext, "No Enough Data in Ring buffer" );
        }
    }

    return msg_len;
}

void CRingBuffer::reset (SRingBufferType *buffer)
{
    LOGW ( &gDoipLogContext, "Corrupted Ringbuffer,reseting buffer" );
    buffer->write_index =0;
    buffer->read_index=0;
    buffer->fill_count=0;

}


