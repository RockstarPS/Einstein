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
#include <pthread.h>
#include <sys/mman.h>

#include <OMX_Component.h>
#include <OMX_Types.h>
#include <OMX_Core.h>
#include <OMX_Video.h>
#include <OMX_Extension_video_TI.h>

#include <vxe_enc-cli.h>

#include "log.h"
#include "omxil_enc_interface.h"

#define ALIGN16(X)  (((X)+15) &~15)

static const char *const ENC_COMPONENT_ROLES[] = {
    "video_encoder.avc",
};
static uint32_t SIZE_OF_ROLES = sizeof(ENC_COMPONENT_ROLES) / sizeof(ENC_COMPONENT_ROLES[0]);

typedef struct codec_handle
{
    vxe_enc_t         *hdl;

    struct mm_buffer  *input_bufs;
    struct mm_buffer  *output_bufs;
    int               input_buf_num;
    int               output_buf_num;
    uint32_t          output_buf_cnt;   //count of buffers send to codec
    uint32_t          output_frame_cnt; //count of frames returned from codec.
    bool              eos;
    pthread_mutex_t   mutex;

    omxil_encode_callback    callback;
    void*                    cb_ctx;
}codec_t;

void omxil_get_roles(const char** roles, OMX_U32 nSize)
{
    uint32_t i, rolesize;

    rolesize = SIZE_OF_ROLES > nSize ? nSize : SIZE_OF_ROLES;
    for(i = 0; i < rolesize; i++)
        roles[i] = ENC_COMPONENT_ROLES[i];

    return;
}

OMX_ERRORTYPE omxil_comp_role_enum(OMX_U8 *cRole, OMX_U32 nIndex)
{
    OMX_ERRORTYPE eError = OMX_ErrorNone;

    if ((NULL != cRole) && (nIndex < SIZE_OF_ROLES))
    {
        strcpy((char*)cRole, ENC_COMPONENT_ROLES[nIndex]);
    }
    else
    {
        eError = OMX_ErrorBadParameter;
    }

    return eError;
}

static void buf_done(struct mm_buffer *buf, mm_enc_process_cb type, void *ctx)
{
    codec_t *hdl = ctx;
    if(type == MM_CB_SRC_FRAME_RELEASE) {
        LOG(LOG_DEBUG2, "Returned input buffer->size(%p->%d)", buf, buf->size[0]);
        hdl->callback(hdl->cb_ctx, buf->buf_private, QOMX_EMPTY_BUFFER_DONE);
    }
    else if(type == MM_CB_CODED_BUFF_READY) {
        LOG(LOG_DEBUG2, "Encoded frame with size(%p->%d)", buf, buf->size[0]);
        pthread_mutex_lock(&hdl->mutex);
        hdl->output_frame_cnt++;
        OMX_BUFFERHEADERTYPE *pBufHdr = buf->buf_private;
        pBufHdr->nFilledLen = buf->size[0];
        if(hdl->eos && hdl->output_frame_cnt == hdl->output_buf_cnt)
            pBufHdr->nFlags |= OMX_BUFFERFLAG_EOS;
        pthread_mutex_unlock(&hdl->mutex);
        hdl->callback(hdl->cb_ctx, pBufHdr, QOMX_FILL_BUFFER_DONE);
    }
    else if(type == MM_CB_ENC_STR_END) {
        LOG(LOG_INFO, "%s:%d EOS received", __func__, __LINE__);
        hdl->callback(hdl->cb_ctx, NULL, QOMX_EOS);
    }
    else if(type == MM_CB_ENC_ERROR_FATAL) {
        LOG(LOG_ERROR, "%s:%d Error received", __func__, __LINE__);
        hdl->callback(hdl->cb_ctx, NULL, QOMX_ERROR);
    }
    else {
        LOG(LOG_ERROR, "%s:%d unknown cb type %d", __func__, __LINE__, type);
    }
}

void *omxil_create_encoder(omxil_encode_callback cb, void *cb_ctx)
{
    codec_t *hdl = NULL;

    if( (hdl = calloc(1,sizeof(*hdl))) == NULL ) {
        LOG(LOG_ERROR,"Couldn't allocate %zubytes",sizeof(*hdl));
        return NULL;
    }

    if((hdl->hdl = vxe_enc_open()) == NULL) {
        LOG(LOG_ERROR, "Error: vxe_enc_open failed");
        free(hdl);
        return NULL;
    }

    if(pthread_mutex_init( &hdl->mutex, NULL) != EOK) {
        LOG( LOG_ERROR, "%s failure, mutex init err ", __func__ );
        vxe_enc_close(hdl->hdl);
        free(hdl);
        return NULL;
    }

    hdl->callback = cb;
    hdl->cb_ctx = cb_ctx;

    return hdl;
}

OMX_ERRORTYPE omxil_query_buf_info(void *hdl, OMX_U32 *nBuffer, OMX_U32 *uBufferSize)
{
    codec_t *ehdl = (codec_t*)hdl;
    if(vxe_enc_get_buf_info(ehdl->hdl, nBuffer, uBufferSize) != 0) {
    	LOG(LOG_ERROR, "%s: vxe_enc_get_buf_info returns error", __func__);
    	return OMX_ErrorHardware;
    }

    return OMX_ErrorNone;
}

OMX_ERRORTYPE omxil_validate_inport_parameters(void *hdl, OMX_PARAM_PORTDEFINITIONTYPE *pPortDef)
{
    if((int)pPortDef->format.video.eColorFormat != (int)OMX_COLOR_FormatYUV420SemiPlanar) {
        LOG(LOG_ERROR, "%s: unsupported color format(%x)", __func__, pPortDef->format.video.eColorFormat);
        return OMX_ErrorBadParameter;
    }

    if(pPortDef->format.video.nFrameWidth == 0 ||
            pPortDef->format.video.nFrameHeight == 0 ||
            pPortDef->format.video.nStride == 0 ||
            pPortDef->format.video.xFramerate == 0) {
        LOG(LOG_ERROR, "%s: Invalid input parameters: stride(%d), resolution(%d, %d), framerate(%d)", __func__,
                pPortDef->format.video.nStride,
                pPortDef->format.video.nFrameWidth, pPortDef->format.video.nFrameHeight,
                pPortDef->format.video.xFramerate);
        return OMX_ErrorBadParameter;
    }
    if((pPortDef->format.video.nStride % 64) != 0) {
        LOG(LOG_ERROR, "%s: Invalid stride(%d), stride needs to be 64 byte aligned",
                __func__, pPortDef->format.video.nStride);
        return OMX_ErrorBadParameter;
    }
    if((pPortDef->format.video.nFrameHeight % 16) != 0) {
        LOG(LOG_INFO, "%s: Please make sure buffer height is 16 byte aligned", __func__);
    }

    pPortDef->nBufferSize = pPortDef->format.video.nStride * ALIGN16(pPortDef->format.video.nFrameHeight) * 3 / 2;
    return OMX_ErrorNone;
}

OMX_ERRORTYPE omxil_validate_outport_parameters(void *hdl, OMX_PARAM_PORTDEFINITIONTYPE *pPortDef)
{
    if(pPortDef->format.video.eCompressionFormat != OMX_VIDEO_CodingAVC) {
        LOG(LOG_ERROR, "%s: unsupported compression format(%x)", __func__, pPortDef->format.video.eCompressionFormat);
        return OMX_ErrorBadParameter;
    }

    return OMX_ErrorNone;
}

OMX_ERRORTYPE omxil_enc_config(void *hdl, const encoder_config *config)
{
    codec_t *ehdl = (codec_t*)hdl;

    mm_vid_create_params cparams = { .width = config->width,
        .height = ALIGN16(config->height),
        .in_pixelformat = MM_PIX_FMT_NV12,
        .out_pixelformat = MM_PIX_FMT_H264 };
    mm_enc_ctrl_params ctrl = {0};

    /** Bit flags for encoding features */
    ctrl.features = MM_ENC_FEATURE_CABAC ;
    /** RC Mode */
    if(config->rateControl == OMX_Video_ControlRateConstant)
        ctrl.rcmode = MM_ENC_SVBR;
    else if(config->rateControl == OMX_Video_ControlRateVariable)
        ctrl.rcmode = MM_ENC_VBR;
    else
        LOG(LOG_ERROR, "%s:%d unsupported rateControl(%d)", __func__, __LINE__, config->rateControl);
    /** IDR-period */
    ctrl.idr_period = config->keyFrameInterval ? config->keyFrameInterval : (60*config->framerate); /* 1 minute */
    /** I-period */
    ctrl.i_period = config->keyFrameInterval ? config->keyFrameInterval : config->framerate;
    /** Bitrate */
    ctrl.bitrate = config->bitrate ? config->bitrate : 20000000;
    /** Framerate */
    ctrl.framerate = config->framerate;
    /** # Slices */
    ctrl.nslices = 1;
    /** Qp Settings */
    ctrl.initial_qp_i = config->qpI;
    ctrl.initial_qp_p = config->qpP;
    ctrl.crop_bottom = cparams.height - config->height; //codec require height 16 byte aligned. this is to keep original height.
    /** Min Block Size for motion search */
    ctrl.min_blk_size = MM_ENC_BLK_SZ_DEFAULT;

    if(vxe_enc_init(ehdl->hdl, &cparams, &ctrl) != 0) {
    	LOG(LOG_ERROR, "Create encoder failed");
        return OMX_ErrorHardware;
    }
    vxe_enc_register_callback(ehdl->hdl, buf_done, hdl);

    return OMX_ErrorNone;
}

OMX_ERRORTYPE omxil_close_encoder(void *hdl)
{
    codec_t *ehdl = (codec_t*)hdl;

    free(ehdl->input_bufs);
    free(ehdl->output_bufs);
    vxe_enc_deinit(ehdl->hdl);
    vxe_enc_close(ehdl->hdl);
    pthread_mutex_destroy( &ehdl->mutex );

    free(ehdl);
    return OMX_ErrorNone;
}

OMX_ERRORTYPE omxil_enc_start(void *hdl)
{
    codec_t *ehdl = (codec_t*)hdl;

    vxe_enc_start_streaming(ehdl->hdl, MM_BUF_TYPE_VIDEO_INPUT);
    vxe_enc_start_streaming(ehdl->hdl, MM_BUF_TYPE_VIDEO_OUTPUT);
    return OMX_ErrorNone;
}

OMX_ERRORTYPE omxil_enc_stop(void *hdl)
{
    codec_t *ehdl = (codec_t*)hdl;

    vxe_enc_stop_streaming(ehdl->hdl, MM_BUF_TYPE_VIDEO_INPUT);
    vxe_enc_stop_streaming(ehdl->hdl, MM_BUF_TYPE_VIDEO_OUTPUT);
    return OMX_ErrorNone;
}

OMX_ERRORTYPE omxil_enc_register_buffers(void *hdl, BufferList *bufList)
{
    int i;
    codec_t *ehdl = (codec_t*)hdl;
    int nbuf = bufList->nAllocSize;
    mm_buffertype type;
    struct mm_buffer *bufs;

    if(bufList->eDir == OMX_DirInput) {
        type = MM_BUF_TYPE_VIDEO_INPUT;
        ehdl->input_bufs = (struct mm_buffer *)malloc(sizeof(struct mm_buffer) * nbuf);
        if(ehdl->input_bufs == NULL) {
            LOG(LOG_ERROR, "OMXIL omxil_enc_register_buffer error no memory for input buffers");
            return OMX_ErrorInsufficientResources;
        }
        ehdl->input_buf_num = nbuf;
        bufs = ehdl->input_bufs;
    }
    else {
        type = MM_BUF_TYPE_VIDEO_OUTPUT;
        ehdl->output_bufs = (struct mm_buffer *)malloc(sizeof(struct mm_buffer) * nbuf);
        if(ehdl->output_bufs == NULL) {
            LOG(LOG_ERROR, "OMXIL omxil_enc_register_buffer error no memory for output buffers");
            return OMX_ErrorInsufficientResources;
        }
        ehdl->output_buf_num = nbuf;
        bufs = ehdl->output_bufs;
    }

    for(i = 0; i < nbuf; i++) {
		off64_t  offset;
		if(mem_offset64(bufList->pAllocHdr[i]->pBuffer, NOFD, 1, &offset, NULL) == -1) {
			LOG(LOG_ERROR, "%s:%d Failed to get physic address ", __func__, __LINE__);
			return OMX_ErrorInsufficientResources;
		}

        bufs[i].type = type;
        bufs[i].buf_addr[0] = bufList->pAllocHdr[i]->pBuffer;
        bufs[i].physic_addr[0] = (uintptr_t)offset;
        bufs[i].alloc_size[0] = bufList->pAllocHdr[i]->nAllocLen;
        bufs[i].size[0] = bufList->pAllocHdr[i]->nAllocLen;
        bufs[i].num_planes = 1; //set UV buffer if memory is not continuous
        bufs[i].buf_private = bufList->pAllocHdr[i];
        if(0 != vxe_enc_buf_prepare(ehdl->hdl, &(bufs[i]))) {
            LOG(LOG_ERROR, "%s: Error returned from vxe_enc_buf_prepare for buf[%d]",__func__,i);
            return OMX_ErrorHardware;
        }
    }

    return OMX_ErrorNone;
}

static inline struct mm_buffer *get_mm_buf(struct mm_buffer *mbufs, int nbuf, void *buf_hdr)
{
    for(int i = 0; i < nbuf; i++) {
        if(mbufs[i].buf_private == buf_hdr)
            return &(mbufs[i]);
    }
    return NULL;
}

OMX_ERRORTYPE omxil_enc_encodeFrame(void *hdl, OMX_BUFFERHEADERTYPE *input, OMX_BUFFERHEADERTYPE *output)
{
    OMX_ERRORTYPE err = OMX_ErrorNone;
    codec_t *ehdl = (codec_t *)hdl;

    if(input->nFilledLen > 0){
        struct mm_buffer *ibuf = get_mm_buf(ehdl->input_bufs, ehdl->input_buf_num, (void *)input);
        struct mm_buffer *obuf = get_mm_buf(ehdl->output_bufs, ehdl->output_buf_num, (void *)output);
        if(0 != vxe_enc_encode(ehdl->hdl, ibuf, obuf)) {
            LOG(LOG_ERROR, "%s:%d encode error", __func__, __LINE__);
            err = OMX_ErrorHardware;
        }
        else {
            pthread_mutex_lock(&ehdl->mutex);
            ehdl->output_buf_cnt++;
            pthread_mutex_unlock(&ehdl->mutex);
        }

        if(input->nFlags & OMX_BUFFERFLAG_EOS) {
            LOG(LOG_DEBUG1, "%s:%d EOS received", __func__, __LINE__);
            //this is how mmlib set eos in encoder
            vxe_enc_stop_streaming(ehdl->hdl, MM_BUF_TYPE_VIDEO_INPUT);
            pthread_mutex_lock(&ehdl->mutex);
            ehdl->eos=true;
            pthread_mutex_unlock(&ehdl->mutex);
        }
    }
    else {
        if(input->nFlags & OMX_BUFFERFLAG_EOS) {
            LOG(LOG_DEBUG1, "%s:%d EOS received", __func__, __LINE__);
            //this is how mmlib set eos in encoder
            vxe_enc_stop_streaming(ehdl->hdl, MM_BUF_TYPE_VIDEO_INPUT);
            pthread_mutex_lock(&ehdl->mutex);
            ehdl->eos=true;
            if(ehdl->output_frame_cnt == ehdl->output_buf_cnt)
                output->nFlags |= OMX_BUFFERFLAG_EOS;
            pthread_mutex_unlock(&ehdl->mutex);
        }

        //return the buffer header
        ehdl->callback(ehdl->cb_ctx, input, QOMX_EMPTY_BUFFER_DONE);
        ehdl->callback(ehdl->cb_ctx, output, QOMX_FILL_BUFFER_DONE);
    }

    return err;
}

OMX_ERRORTYPE omxil_enc_forceKeyFrame(void *hdl)
{
    //TODO
    LOG(LOG_INFO, "OMXIL J7 enc comp:%s:%d Not support yet",__func__, __LINE__);
    return OMX_ErrorNone;
}

