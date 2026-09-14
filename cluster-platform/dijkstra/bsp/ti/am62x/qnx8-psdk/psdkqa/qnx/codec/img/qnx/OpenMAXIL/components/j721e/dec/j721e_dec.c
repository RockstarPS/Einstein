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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>

#include <OMX_Component.h>
#include <OMX_Types.h>
#include <OMX_Core.h>
#include <OMX_Video.h>
#include <OMX_Extension_video_TI.h>


#include "log.h"
#include "omxil_dec_interface.h"

static const char *const DEC_COMPONENT_ROLES[] = {
    "video_decoder.avc",
    "video_decoder.hevc",
};
static uint32_t SIZE_OF_ROLES = sizeof(DEC_COMPONENT_ROLES) / sizeof(DEC_COMPONENT_ROLES[0]);

void omxil_get_roles(const char** roles, OMX_U32 nSize)
{
    uint32_t i, rolesize;

    rolesize = SIZE_OF_ROLES > nSize ? nSize : SIZE_OF_ROLES;
    for(i = 0; i < rolesize; i++)
        roles[i] = DEC_COMPONENT_ROLES[i];

    return;
}

OMX_ERRORTYPE omxil_comp_role_enum(OMX_U8 *cRole, OMX_U32 nIndex)
{
    OMX_ERRORTYPE eError = OMX_ErrorNone;

    if ((NULL != cRole) && (nIndex < SIZE_OF_ROLES))
    {
        strcpy((char*)cRole, DEC_COMPONENT_ROLES[nIndex]);
    }
    else
    {
        eError = OMX_ErrorBadParameter;
    }

    return eError;
}

static void buf_done(void *item, mm_dec_process_cb type, void *ctx)
{
    codec_t *hdl = ctx;
    if(type == MM_CB_STRUNIT_PROCESSED) {
        struct mm_buffer *buf = (struct mm_buffer *)item;
        LOG(LOG_DEBUG2, "%s:%d Returned input buffer(%p)", __func__, __LINE__, buf);
        hdl->callback(hdl->cb_ctx, buf->buf_private, QOMX_EMPTY_BUFFER_DONE);
    }
    else if(type == MM_CB_PICT_RELEASE) {
        struct mm_buffer *buf = (struct mm_buffer *)item;
        LOG(LOG_DEBUG2, "%s:%d Release frame (%p->%d)", __func__, __LINE__, buf->buf_private, buf->size[0]);
        OMX_BUFFERHEADERTYPE *pBufHdr = buf->buf_private;
        pBufHdr->nFilledLen = 0;
        hdl->callback(hdl->cb_ctx, pBufHdr, QOMX_RELEASE_OUTPUT_BUFFER);
    }
    else if(type == MM_CB_PICT_DISPLAY) {
        struct mm_buffer *buf = (struct mm_buffer *)item;
        LOG(LOG_DEBUG2, "%s:%d Display frame (%p->%d)", __func__, __LINE__, buf->buf_private, buf->size[0]);
        hdl->output_frame_cnt++;
        OMX_BUFFERHEADERTYPE *pBufHdr = buf->buf_private;
        pBufHdr->nFilledLen = buf->size[0];
        pBufHdr->nFlags |= OMXQ_BUFFERFLAG_DISPLAY;
        if(hdl->eos && hdl->output_frame_cnt == hdl->output_buf_cnt)
            pBufHdr->nFlags |= OMX_BUFFERFLAG_EOS;
        hdl->callback(hdl->cb_ctx, pBufHdr, QOMX_FILL_BUFFER_DONE);
    }
    else if(type == MM_CB_STR_END) {
        LOG(LOG_INFO, "%s:%d EOS received", __func__, __LINE__);
        hdl->callback(hdl->cb_ctx, NULL, QOMX_EOS);
    }
    else if(type == MM_CB_ERROR) {
        LOG(LOG_ERROR, "%s:%d Error received", __func__, __LINE__);
        hdl->callback(hdl->cb_ctx, item, QOMX_ERROR);
    }
    else {
        LOG(LOG_DEBUG2, "%s:%d Unprocessed cb type %d", __func__, __LINE__, type);
    }
}

codec_t *omxil_create_decoder(omxil_decode_callback cb, void *cb_ctx)
{
    codec_t *hdl = NULL;

    if( (hdl = calloc(1,sizeof(*hdl))) == NULL ) {
        LOG(LOG_ERROR,"Couldn't allocate %zubytes",sizeof(*hdl));
        return NULL;
    }

    if((hdl->hdl = vxd_dec_open()) == NULL) {
        LOG(LOG_ERROR, "Error: vxd_dec_open failed");
        free(hdl);
        return NULL;
    }

    hdl->callback = cb;
    hdl->cb_ctx = cb_ctx;

    return hdl;
}

OMX_ERRORTYPE omxil_validate_outport_parameters(codec_t *hdl, OMX_PARAM_PORTDEFINITIONTYPE *pPortDef)
{
    if(pPortDef->format.video.nFrameWidth == 0 ||
            pPortDef->format.video.nFrameHeight == 0 ||
            pPortDef->format.video.nStride == 0) {
        LOG(LOG_ERROR, "%s: Invalid stride(%d) or resolution(%d, %d)", __func__, pPortDef->format.video.nStride,
                pPortDef->format.video.nFrameWidth, pPortDef->format.video.nFrameHeight);
        return OMX_ErrorBadParameter;
    }

    if((int)pPortDef->format.video.eColorFormat == OMX_COLOR_FormatYUV420SemiPlanar)
        pPortDef->nBufferSize = pPortDef->format.video.nFrameWidth * pPortDef->format.video.nFrameHeight * 3 / 2;
    else if ((int)pPortDef->format.video.eColorFormat != (OMX_COLOR_FORMATTYPE)OMXQ_COLOR_FormatNV16 ||
             (int)pPortDef->format.video.eColorFormat != (OMX_COLOR_FORMATTYPE)OMXQ_COLOR_Format1210 ||
             (int)pPortDef->format.video.eColorFormat != (OMX_COLOR_FORMATTYPE)OMXQ_COLOR_Format1610)
        pPortDef->nBufferSize = pPortDef->format.video.nFrameWidth * pPortDef->format.video.nFrameHeight * 2;
    else {
        LOG(LOG_ERROR, "%s: unsupported color format(%x)", __func__, pPortDef->format.video.eColorFormat);
        return OMX_ErrorBadParameter;
    }

    return OMX_ErrorNone;
}

OMX_ERRORTYPE omxil_validate_inport_parameters(codec_t *hdl, OMX_PARAM_PORTDEFINITIONTYPE *pPortDef)
{
    if(pPortDef->format.video.eCompressionFormat != OMX_VIDEO_CodingAVC &&
        pPortDef->format.video.eCompressionFormat != (OMX_VIDEO_CODINGTYPE)OMXQ_VIDEO_CodingHEVC) {
        LOG(LOG_ERROR, "%s: unsupported compression format(%x)", __func__, pPortDef->format.video.eCompressionFormat);
        return OMX_ErrorBadParameter;
    }

    pPortDef->nBufferSize = pPortDef->format.video.nFrameWidth * pPortDef->format.video.nFrameHeight * 3 / 2;
    return OMX_ErrorNone;
}

static uint32_t infmtxi2vxd(OMX_VIDEO_CODINGTYPE eCompressionFormat)
{
    uint32_t fmt = 0;
    if(eCompressionFormat == OMX_VIDEO_CodingAVC) {
        fmt = MM_PIX_FMT_H264;
    }
    else if(eCompressionFormat == (OMX_VIDEO_CODINGTYPE)OMXQ_VIDEO_CodingHEVC) {
        fmt = MM_PIX_FMT_HEVC;
    }
    else {
        LOG(LOG_ERROR, "%s: unsupported compression format(%x)", __func__, eCompressionFormat);
    }

    return fmt;
}

static uint32_t outfmtxi2vxd(OMX_COLOR_FORMATTYPE eColorFormat)
{
    uint32_t fmt = 0;
    if(eColorFormat == OMX_COLOR_FormatYUV420SemiPlanar) {
        fmt = MM_PIX_FMT_NV12;
    }
    else if(eColorFormat == (OMX_COLOR_FORMATTYPE)OMXQ_COLOR_Format1210) {
        fmt = MM_PIX_FMT_TI1210;
    }
    else if(eColorFormat == (OMX_COLOR_FORMATTYPE)OMXQ_COLOR_FormatNV16) {
        fmt = MM_PIX_FMT_NV16;
    }
    else if(eColorFormat == (OMX_COLOR_FORMATTYPE)OMXQ_COLOR_Format1610) {
        fmt = MM_PIX_FMT_TI1610;
    }
    else {
        LOG(LOG_ERROR, "%s: unsupported color format(%x)", __func__, eColorFormat);
    }

    return fmt;

}

OMX_ERRORTYPE omxil_init_decoder(codec_t *hdl, OMX_VIDEO_PORTDEFINITIONTYPE *pInPortFormat,OMX_VIDEO_PORTDEFINITIONTYPE *pOutPortFormat)
{
    mm_vid_create_params cparams = { .width = pInPortFormat->nFrameWidth,
        .height = pInPortFormat->nFrameHeight,
        .framerate = (pInPortFormat->xFramerate >> 16),
        .in_pixelformat = infmtxi2vxd(pInPortFormat->eCompressionFormat),
        .out_pixelformat = outfmtxi2vxd(pOutPortFormat->eColorFormat) };
    mm_dec_ctrl_params ctrl = {0};

    if(vxd_dec_init(hdl->hdl, &cparams, &ctrl) != 0) {
    	LOG(LOG_ERROR, "Init decoder failed");
        return OMX_ErrorHardware;
    }
    vxd_dec_register_callback(hdl->hdl, buf_done, hdl);

    return OMX_ErrorNone;
}

void omxil_close_decoder(codec_t *hdl)
{
    free(hdl->input_bufs);
    free(hdl->output_bufs);
    vxd_dec_deinit(hdl->hdl);
    vxd_dec_close(hdl->hdl);

    free(hdl);
}

OMX_ERRORTYPE omxil_dec_start(codec_t *hdl)
{
    vxd_dec_start_streaming(hdl->hdl, MM_BUF_TYPE_VIDEO_INPUT);
    vxd_dec_start_streaming(hdl->hdl, MM_BUF_TYPE_VIDEO_OUTPUT);
    return OMX_ErrorNone;
}

OMX_ERRORTYPE omxil_dec_stop(codec_t *hdl)
{
    vxd_dec_stop_streaming(hdl->hdl, MM_BUF_TYPE_VIDEO_OUTPUT);
    return OMX_ErrorNone;
}

OMX_ERRORTYPE omxil_dec_register_buffers(codec_t *hdl, BufferList *bufList)
{
    int i;
    int nbuf = bufList->nAllocSize;
    mm_buffertype type;
    struct mm_buffer *bufs;

    if(bufList->eDir == OMX_DirInput) {
        type = MM_BUF_TYPE_VIDEO_INPUT;
        hdl->input_bufs = (struct mm_buffer *)malloc(sizeof(struct mm_buffer) * nbuf);
        if(hdl->input_bufs == NULL) {
            LOG(LOG_ERROR, "OMXIL omxil_dec_register_buffer error no memory for input buffers");
            return OMX_ErrorInsufficientResources;
        }
        hdl->input_buf_num = nbuf;
        bufs = hdl->input_bufs;
    }
    else {
        type = MM_BUF_TYPE_VIDEO_OUTPUT;
        hdl->output_bufs = (struct mm_buffer *)malloc(sizeof(struct mm_buffer) * nbuf);
        if(hdl->output_bufs == NULL) {
            LOG(LOG_ERROR, "OMXIL omxil_dec_register_buffer error no memory for output buffers");
            return OMX_ErrorInsufficientResources;
        }
        hdl->output_buf_num = nbuf;
        bufs = hdl->output_bufs;
    }

    for(i = 0; i < nbuf; i++) {
        off64_t  offset;
        if(mem_offset64(bufList->pAllocHdr[i]->pBuffer, NOFD, 1, &offset, NULL) == -1) {
            LOG(LOG_ERROR, "%s:%d Failed to get physic address for %p Error '%s'", __func__, __LINE__, bufList->pAllocHdr[i]->pBuffer, strerror(errno));
            return OMX_ErrorInsufficientResources;
        }

        bufs[i].type = type;
        bufs[i].buf_addr[0] = bufList->pAllocHdr[i]->pBuffer;
        bufs[i].physic_addr[0] = (uintptr_t)offset;
        bufs[i].alloc_size[0] = bufList->pAllocHdr[i]->nAllocLen;
        bufs[i].size[0] = bufList->pAllocHdr[i]->nAllocLen;
        bufs[i].num_planes = 1; //set UV buffer if memory is not continuous
        bufs[i].buf_private = bufList->pAllocHdr[i];
        if(0 != vxd_dec_buf_prepare(hdl->hdl, &(bufs[i]))) {
            LOG(LOG_ERROR, "%s: Error returned from vxd_dec_buf_prepare for buf[%d]",__func__,i);
            return OMX_ErrorHardware;
        }
    }

    return OMX_ErrorNone;
}

static inline struct mm_buffer *get_mm_buf(struct mm_buffer *mbufs, int nbuf, void *buf_hdr)
{
    struct mm_buffer *rbuf = NULL;

    for(int i = 0; i < nbuf; i++) {
        if(mbufs[i].buf_private == buf_hdr) {
            rbuf = &(mbufs[i]);
            break;
        }
    }
    return rbuf;
}

OMX_ERRORTYPE omxil_decodeFrame(codec_t *hdl, OMX_BUFFERHEADERTYPE *input, OMX_BUFFERHEADERTYPE *output)
{
    OMX_ERRORTYPE err = OMX_ErrorNone;

    if(input->nFilledLen > 0){
        struct mm_buffer *ibuf = get_mm_buf(hdl->input_bufs, hdl->input_buf_num, (void *)input);
        if(ibuf == NULL) {
            LOG(LOG_ERROR, "%s:%d Failed to find mm_buffer for %p", __func__, __LINE__, input);
            return OMX_ErrorBadParameter;
        }
        ibuf->size[0] = input->nFilledLen;
        struct mm_buffer *obuf = get_mm_buf(hdl->output_bufs, hdl->output_buf_num, (void *)output);
        if(obuf == NULL) {
            LOG(LOG_ERROR, "%s:%d Failed to find mm_buffer for %p", __func__, __LINE__, output);
            return OMX_ErrorBadParameter;
        }

        if(0 != vxd_dec_decode(hdl->hdl, ibuf, obuf)) {
            LOG(LOG_ERROR, "%s:%d decode error", __func__, __LINE__);
            err = OMX_ErrorHardware;
        }
        else
            hdl->output_buf_cnt++;

        if(input->nFlags & OMX_BUFFERFLAG_EOS) {
            LOG(LOG_DEBUG1, "%s:%d EOS received", __func__, __LINE__);
            //this is how mmlib set eos in decoder
            vxd_dec_stop_streaming(hdl->hdl, MM_BUF_TYPE_VIDEO_INPUT);
            hdl->eos=true;
        }
    }
    else {
        if(input->nFlags & OMX_BUFFERFLAG_EOS) {
            LOG(LOG_DEBUG1, "%s:%d EOS received", __func__, __LINE__);
            //this is how mmlib set eos in decoder
            vxd_dec_stop_streaming(hdl->hdl, MM_BUF_TYPE_VIDEO_INPUT);
            hdl->eos=true;
            if(hdl->output_frame_cnt == hdl->output_buf_cnt)
                output->nFlags |= OMX_BUFFERFLAG_EOS;
        }

        //return the buffer header
        hdl->callback(hdl->cb_ctx, input, QOMX_EMPTY_BUFFER_DONE);
        hdl->callback(hdl->cb_ctx, output, QOMX_FILL_BUFFER_DONE);
    }

    return err;
}

OMX_ERRORTYPE omxil_get_error_type(uint32_t error)
{
    OMX_ERRORTYPE ret = OMX_ErrorNone;
    if ( error & MM_ERROR_MMU_FAULT ||
         error & MM_ERROR_DEVICE ||
         error & MM_ERROR_SERVICE_TIMER_EXPIRY ) {
       ret = OMX_ErrorHardware;
    }
    else if ( error & MM_ERROR_SR_ERROR ||
              error & MM_ERROR_FEHW_DECODE ||
              error & MM_ERROR_MISSING_REFERENCES ||
              error & MM_ERROR_CORRUPTED_REFERENCE ||
              error & MM_ERROR_MMCO ||
              error & MM_ERROR_MBS_DROPPED) {
       ret = OMX_ErrorStreamCorrupt;
    }
    else if ( error & MM_ERROR_FEHW_TIMEOUT ||
              error & MM_ERROR_BEHW_TIMEOUT) {
       ret = OMX_ErrorTimeout;
    }

    return ret;
}
