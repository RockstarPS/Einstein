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

#ifndef _OMXIL_DEC_INTERFACE_H_
#define _OMXIL_DEC_INTERFACE_H_

#include <OMX_Types.h>
#include <OMX_Component.h>
#include <OMX_Core.h>
#include <OMX_Video.h>

#include <list.h>
#include <vxd_dec-cli.h>

/**
 *  Event types of callback
 */
typedef enum {
	QOMX_EMPTY_BUFFER_DONE = 0,
	QOMX_FILL_BUFFER_DONE,
	QOMX_RELEASE_OUTPUT_BUFFER,
	QOMX_EOS,
	QOMX_ERROR
} decoder_cb_type;

typedef OMX_ERRORTYPE (*omxil_decode_callback)(void *ctx, void *data, decoder_cb_type type);

typedef struct codec_handle
{
    vxd_dec_t         *hdl;
    struct mm_buffer  *input_bufs;
    struct mm_buffer  *output_bufs;
    int               input_buf_num;    //number of input buffers
    int               output_buf_num;   //number of output buffers
    uint32_t          output_buf_cnt;   //count of buffers send to codec
    uint32_t          output_frame_cnt; //count of frames returned from codec.
    bool              eos;

    omxil_decode_callback    callback;
    void*                    cb_ctx;
}codec_t;

/*
 * Create decoder handle
 */
codec_t *omxil_create_decoder(omxil_decode_callback cb, void *cb_ctx);

/*
 * Init decoder
 */
OMX_ERRORTYPE omxil_init_decoder(codec_t *hdl, OMX_VIDEO_PORTDEFINITIONTYPE *pInPortFormat,OMX_VIDEO_PORTDEFINITIONTYPE *pOutPortFormat);

/*
 * Decode a frame
 */
OMX_ERRORTYPE omxil_decodeFrame(codec_t *hdl, OMX_BUFFERHEADERTYPE *input, OMX_BUFFERHEADERTYPE *output);

/*
 * Register output buffers
 */
OMX_ERRORTYPE omxil_dec_register_buffers(codec_t *hdl, BufferList *pBufList);

/*
 * Start decoder
 */
OMX_ERRORTYPE omxil_dec_start(codec_t *hdl);

/*
 * Stop decoder
 */
OMX_ERRORTYPE omxil_dec_stop(codec_t *hdl);

/*
 * Free decoder handle and resources.
 */
void omxil_close_decoder(codec_t *hdl);

/*
 * Validate parameters for input port.
 */
OMX_ERRORTYPE omxil_validate_inport_parameters(codec_t *hdl, OMX_PARAM_PORTDEFINITIONTYPE *pPortDef);

/*
 * Validate parameters for output port.
 */
OMX_ERRORTYPE omxil_validate_outport_parameters(codec_t *hdl, OMX_PARAM_PORTDEFINITIONTYPE *pPortDef);

/*
 * Convert codec error type to OMX_ERRORTYPE.
 */
OMX_ERRORTYPE omxil_get_error_type(uint32_t error);

#endif

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/multimedia/branches/7.1.0/lib/mmedia/codecs/OpenMAXIL/components/common/omxil_dec_interface.h $ $Rev: 947017 $")
#endif
