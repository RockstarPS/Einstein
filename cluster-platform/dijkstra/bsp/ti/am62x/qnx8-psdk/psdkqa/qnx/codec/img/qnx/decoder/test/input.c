/*
 * Copyright 2022, QNX Software Systems.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject
 * to the following conditions:
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */
#include <inttypes.h>
#include <stdlib.h> 
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>

#include <osa_define.h>

#include "config_parser.h"
#include "input.h"

#define AOIFOURCC(FCC) (((uint32_t)FCC[0]<<24)|((uint8_t)FCC[1]<<16)|((uint8_t)FCC[2]<<8)|((uint8_t)FCC[3]) )
#define DEFAULT_BUFFER_SIZE (10*1024*1024)
#ifndef DIM
#  define DIM(a) (sizeof((a)) / sizeof((a)[0]))
#endif

enum {
    NAL_UNSPECIFIED = 0, // Derived from the definition described in P.48 of "T-REC-H.264-200305-S!!PDF-E.pdf"
    NAL_SLICE = 1,
    NAL_DPA,
    NAL_DPB,
    NAL_DPC,
    NAL_IDR_SLICE,
    NAL_SEI,
    NAL_SPS,
    NAL_PPS,
    NAL_AUD,
    NAL_END_SEQUENCE,
    NAL_END_STREAM,
    NAL_FILLER_DATA,
};

int32_t readConfig(input_handle_t *ihdl);

input_handle_t *createInput(const char* path)
{
    int32_t res = EOK;
    input_handle_t *hdl;

    hdl = (input_handle_t *)calloc(1, sizeof(input_handle_t));
    if(hdl == NULL) {
        OSA_PR_ERR("Failed to alloc input_handle_t ! %s", strerror(errno));
        return NULL;
    }

    hdl->m_fd = open(path, O_RDONLY);
    if (hdl->m_fd == -1) {
        OSA_PR_ERR("Failed to open input file! %s", strerror(errno));
        goto create_fail_exit;
    }
    
    hdl->m_inputBuffer = (uint8_t *)malloc(DEFAULT_BUFFER_SIZE);
    if(hdl->m_inputBuffer == NULL) {
        OSA_PR_ERR("Failed to allocate input buffer! %s", strerror(errno));
        goto create_fail_exit;
    }

    hdl->m_inputDataSize = read(hdl->m_fd, hdl->m_inputBuffer, DEFAULT_BUFFER_SIZE);
    if(hdl->m_inputDataSize < 0) {
        OSA_PR_ERR("Failed to read input data! %s", strerror(errno));
        goto create_fail_exit;
    }
    else if(hdl->m_inputDataSize < DEFAULT_BUFFER_SIZE) {
        OSA_PR_DEBUG("Reach the end of file");
        hdl->m_EOF = true;
    }

    hdl->m_currPtr = hdl->m_inputBuffer;
    OSA_PR_DEBUG("Read input data %d bytes", hdl->m_inputDataSize);

    res = readConfig(hdl);
    if(res != EOK) {
        OSA_PR_ERR("Failed to read config data!");
        goto create_fail_exit;
    }

    return hdl;

create_fail_exit:
    if (hdl->m_fd == -1)
        close(hdl->m_fd);
    free(hdl->m_inputBuffer);
    free(hdl);
    return NULL;
}

void destroyInput(input_handle_t *ihdl)
{
    if(ihdl == NULL)
        return;

    free(ihdl->m_inputBuffer);
    close(ihdl->m_fd);
    free(ihdl);
}

static inline bool CheckStartCode(
    const uint8_t *sc,
    uint32_t scsize,
    const uint8_t *inbuf,
    uint32_t isize,
    const uint32_t *byte_to_apply_mask,
    const uint8_t *start_code_mask )
{
    uint32_t sc_index = 0;

    if( isize < scsize ) {
        return false;
    }

    while( scsize ) {
        if( byte_to_apply_mask && start_code_mask && (sc_index == *byte_to_apply_mask) ) {
            if( *sc != (*inbuf & *start_code_mask) ) {
                return false;
            }
        } else {
            if( *sc != *inbuf ) {
                return false;
            }
        }
        scsize--;
        sc++;
        inbuf++;
        sc_index++;
    }

    return true;
}


static inline int FindStartCode(
    const uint8_t *sc,
    uint32_t scsize,
    const uint8_t *inbuf,
    uint32_t isize,
    const uint32_t *byte_to_apply_mask,
    const uint8_t *start_code_mask )
{
    int size = 0;

    while( isize ) {
        if( CheckStartCode( sc, scsize, inbuf, isize, byte_to_apply_mask, start_code_mask ) ) {
            break;
        }

        isize--;
        size++;
        inbuf++;
    }

    return size;
}

static int H264CheckNalType( const uint8_t *inbuf, int *sps_pps, int *frame_data )
{
    int nalType = 0;

    // detect SPS/PPS/Frame data
    nalType = ((*inbuf) & 0x1f);
    if( (nalType == NAL_SPS) || (nalType == NAL_PPS) ) {
        *sps_pps = 1;
    } else if( nalType > 0 && nalType <= NAL_IDR_SLICE) {
        *frame_data = 1;
    }

    return nalType;
}

int32_t readFrame(input_handle_t *ihdl, void *oBuf, uint32_t *oSize)
{
    static const uint8_t sc[] = {0x00, 0x00, 0x01};  /* start code */
    int initial_sc_offset = 0;
    int sps_pps_found = 0;
    int frame_found = 0;
    int au_delimiter_found = 0;
    int nalSize;
    uint8_t *buf;
    uint32_t      size;
    const uint8_t *inbuf = ihdl->m_currPtr;
    int32_t err = EOK;

    size = ihdl->m_inputDataSize;
    buf = ihdl->m_currPtr;
    *oSize = 0;

    OSA_PR_DEBUG("%s (m_currPtr=%p, m_inputDataSize=%d)", __func__, ihdl->m_currPtr, ihdl->m_inputDataSize);

    if(ihdl->m_inputDataSize < DIM(sc)+ 2) {
        if(ihdl->m_EOF) {
            OSA_PR_INFO("%s=> reach the end of data", __func__);
            return EOK;
        }
        else {
            void *rbuf = ihdl->m_inputBuffer;
            if(ihdl->m_inputDataSize > 0) {
                memcpy(rbuf, buf, ihdl->m_inputDataSize);
                rbuf += ihdl->m_inputDataSize;
            }
            ihdl->m_inputDataSize = read(ihdl->m_fd, rbuf, DEFAULT_BUFFER_SIZE);
            if(ihdl->m_inputDataSize <= 0) {
                OSA_PR_INFO("%s=> reach the end of data", __func__);
                ihdl->m_EOF = true;
                return EOK;
            }
        }
    }
    // check if the buffer starts with the start code, else skip the bytes
    initial_sc_offset = FindStartCode( sc, DIM(sc), inbuf, ihdl->m_inputDataSize, NULL, NULL );
    OSA_PR_DEBUG("%s=> start code was found at initial_sc_offset %d (skipping these bytes)", __func__, initial_sc_offset );
    if( initial_sc_offset > ihdl->m_inputDataSize) {
        OSA_PR_ERR("%s=> Wrong input stream initial_sc_offset=%d, m_inputDataSize=%d", __func__, initial_sc_offset, ihdl->m_inputDataSize);
        return EINVAL;
    }
    buf += initial_sc_offset;
    size -= initial_sc_offset;

    if (size < DIM(sc)+ 2) {
        OSA_PR_INFO("%s=> Only frame header found(size=%d), skip", __func__, size);
        return EOK;
    }

    while( ( size >= DIM(sc)+ 2 ) ) {
        // detect SPS/PPS/Frame data
        int nal_type = H264CheckNalType( (buf + DIM(sc)), &sps_pps_found, &frame_found );

        if( nal_type == NAL_AUD ) {
            //return access unit
            if( au_delimiter_found ) {
                break;
            }
            else {
                au_delimiter_found = 1;
            }
        }

        /* if we've already started pushing NALU to the buffer, check
         * if this next NALU starts a new access unit
         */
        nalSize = DIM(sc) + FindStartCode( sc, DIM(sc), buf+DIM(sc), size-DIM(sc), NULL, NULL );

        if( nalSize > size ) {
            OSA_PR_ERR("%s=> Wrong input stream nal_size=%d, size=%d", __func__, nalSize, size );
            err = EINVAL;
            break;
        }

        memcpy(oBuf + *oSize, buf, nalSize);
        buf += nalSize;
        size -= nalSize;
        *oSize += nalSize;

        //no access unit delimiter return once frame data found
        if( !au_delimiter_found && frame_found ) {
            break;
        }
    }
    if(size == 0 && !ihdl->m_EOF) {
        ihdl->m_inputDataSize = read(ihdl->m_fd, ihdl->m_inputBuffer, DEFAULT_BUFFER_SIZE);
        if(ihdl->m_inputDataSize > 0) {
            OSA_PR_DEBUG("%s:%d=> read more data=%d", __func__, __LINE__, ihdl->m_inputDataSize);
            buf = ihdl->m_inputBuffer;
            size = ihdl->m_inputDataSize;
            nalSize = FindStartCode( sc, DIM(sc), buf, size, NULL, NULL );
            if( nalSize > size ) {
                OSA_PR_ERR("%s:%d=> Wrong input stream nal_size=%d, size=%d", __func__, __LINE__, nalSize, size );
                err = EINVAL;
            }
            else {
                memcpy(oBuf + *oSize, buf, nalSize);
                *oSize += nalSize;
                buf += nalSize;
                size -= nalSize;
            }
            if(ihdl->m_inputDataSize < DEFAULT_BUFFER_SIZE) {
                OSA_PR_DEBUG("%s:%d=> reach end of file %d", __func__, __LINE__, ihdl->m_inputDataSize);
                ihdl->m_EOF = true;
            }
        }
        else {
            OSA_PR_ERR("%s=> failed to read data=%d", __func__, ihdl->m_inputDataSize);
            err = EINVAL;
        }

    }

    ihdl->m_inputDataSize = size;
    ihdl->m_currPtr = buf;

    OSA_PR_DEBUG("%s get one frame(%u) input buffer(m_currPtr=%p, m_inputDataSize=%d)", __func__,
            *oSize, ihdl->m_currPtr, ihdl->m_inputDataSize);

    return err;
}

int32_t readConfig(input_handle_t *ihdl)
{
    static const uint8_t sc[] = {0x00, 0x00, 0x01};  /* start code */
    int initial_sc_offset = 0;
    int sps_pps_found = 0;
    int frame_found = 0;
    int nalSize;
    uint8_t *buf;
    uint32_t      size;
    int32_t err = EOK;

    size = ihdl->m_inputDataSize;
    buf = ihdl->m_currPtr;
    ihdl->mConfigSize = 0;

    if(ihdl->m_inputDataSize < DIM(sc)+ 2) {
        OSA_PR_INFO("%s=> reach the end of data", __func__);
        return EINVAL;
    }
    // check if the buffer starts with the start code, else skip the bytes
    initial_sc_offset = FindStartCode( sc, DIM(sc), buf, ihdl->m_inputDataSize, NULL, NULL );
    OSA_PR_DEBUG("%s=> start code was found at initial_sc_offset %d (skipping these bytes)", __func__, initial_sc_offset );
    if( initial_sc_offset > ihdl->m_inputDataSize) {
        OSA_PR_ERR("%s=> Wrong input stream initial_sc_offset=%d, m_inputDataSize=%d", __func__, initial_sc_offset, ihdl->m_inputDataSize);
        return EINVAL;
    }
    buf += initial_sc_offset;
    size -= initial_sc_offset;

    if (size < DIM(sc)+ 2) {
        OSA_PR_ERR("%s=> Only frame header found(size=%d), skip", __func__, size);
        return EINVAL;
    }

    while( ( size >= DIM(sc)+ 2 ) ) {
        // detect SPS/PPS/Frame data
        sps_pps_found = 0;
        int nal_type = H264CheckNalType( (buf + DIM(sc)), &sps_pps_found, &frame_found );

        OSA_PR_DEBUG("%s=> nal_type=%d, sps_pps_found=%d", __func__, nal_type, sps_pps_found);
        /* if we've already started pushing NALU to the buffer, check
         * if this next NALU starts a new access unit
         */
        OSA_PR_DEBUG("%s=> %x %x %x %x %x", __func__, buf[0],buf[1],buf[2],buf[3],buf[4]);
        nalSize = DIM(sc) + FindStartCode( sc, DIM(sc), buf+DIM(sc), size-DIM(sc), NULL, NULL );
        OSA_PR_DEBUG("%s=> nalSize=%d", __func__, nalSize);

        // detect SPS/PPS/Frame data
        if( nalSize > size ) {
            OSA_PR_ERR("%s=> Wrong input stream nal_size=%d, size=%d", __func__, nalSize, size );
            err = EINVAL;
            break;
        }

        if(sps_pps_found) {
            if(nalSize + ihdl->mConfigSize < CONFIG_DATA_BUFFER_SIZE) {
                memcpy(ihdl->mpConfig + ihdl->mConfigSize, buf, nalSize);
                ihdl->mConfigSize += nalSize;
            }
            else {
                OSA_PR_ERR("%s=> config data buffer too small( nal_size=%d, size=%d)", __func__, nalSize, size );
                err = ENOMEM;
                break;
            }
        }
        else if(ihdl->mConfigSize > 0) {
            break;
        }

        buf += nalSize;
        size -= nalSize;
    }

    decoder_info_t decoder_info;
    if(h264_parse_decoder_config( ihdl->mpConfig, ihdl->mConfigSize, &decoder_info, NULL) == EOK ) {
        ihdl->mWidth = decoder_info.width;
        ihdl->mHeight = decoder_info.height;
        ihdl->mFrameRate = 30;
    }
    else {
        OSA_PR_ERR("%s=> Failed to get config data(%d) ", __func__, ihdl->mConfigSize);
        err = EINVAL;
    }

    OSA_PR_DEBUG("%s get config(%u) input buffer(m_currPtr=%p, m_inputDataSize=%d)", __func__,
            ihdl->mConfigSize, ihdl->m_currPtr, ihdl->m_inputDataSize);

    return err;
}

