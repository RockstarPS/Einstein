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

#ifndef VXE_ENC_H
#define VXE_ENC_H

#include "mm_enc.h"

typedef struct vxe_enc_s {
    int fd;
    int chid;
    int coid;
    struct sigevent   event;
    void (*mm_ret_resource)(struct mm_buffer *buf, mm_enc_process_cb cb_type, void *cb_ctx);
    void *cb_ctx;
    pthread_t tid;         /* listener thread id                                    */
} vxe_enc_t;

/**
 *  open encoder
 *
 *  Return
 *  Success: pointer to encoder handle.
 *  Failure: NULL
 */
vxe_enc_t *vxe_enc_open(void);

/**
 *  close encoder
 *  hdl: pointer to encoder handle.
 */
void vxe_enc_close(vxe_enc_t *hdl);

/**
 *  Create an encoder instance
 *
 *  hdl: pointer to encoder handle.
 *  create_params: MM Encoder create params
 *  ctrl_params  :   MM Encoder control params
 *
 *  Return
 *  Success: 0.
 *  Failure: -1.
 */
int  vxe_enc_init(vxe_enc_t *hdl, mm_vid_create_params* create_params, mm_enc_ctrl_params *ctrl_params);

/**
 *  Destroy an encoder instance
 *
 *  hdl: pointer to encoder handle.
 *
 *  Return
 *  Success: 0.
 *  Failure: -1.
 */
int  vxe_enc_deinit(vxe_enc_t *hdl);


/**
 *  Register callback
 *  This is the callback function when encoder completes frame encoding
 *
 *  hdl: pointer to encoder handle.
 *  buf     : Encoder output buffer (frame buffer)
 *  cb_type : callback Type.
 *  cb_ctx  : callback context.
 *
 *  Return
 *  Success: 0.
 *  Failure: -1.
 */
int  vxe_enc_register_callback(vxe_enc_t *hdl,
		void (*mm_ret_resource)(struct mm_buffer *buf, mm_enc_process_cb cb_type, void *cb_ctx),
        void *cb_ctx);

/**
 *  Start streaming of input or output
 *
 *  hdl: pointer to encoder handle.
 *  type : buffer type, input or output
 *
 *  Return
 *  Success: 0.
 *  Failure: -1.
 */
int  vxe_enc_start_streaming(vxe_enc_t *hdl,  mm_buffertype type);

/**
 *  Stop streaming of input or output
 *
 *  hdl: pointer to encoder handle.
 *  type : buffer type, input or output
 *
 *  Return
 *  Success: 0.
 *  Failure: -1.
 */
int  vxe_enc_stop_streaming(vxe_enc_t *hdl, mm_buffertype type);

/**
 *  Alloc/Prepare the encoder buffers
 *  This needs to be called for all input and output buffers
 *  at least once
 *
 *  hdl: pointer to encoder handle.
 *  buffer: buffer object
 *
 *  Return
 *  Success: 0.
 *  Failure: -1.
 */
int  vxe_enc_buf_prepare(vxe_enc_t *hdl, struct mm_buffer *buffer);

/**
 *  Perform the encode Process
 *  Non-blocking API, Encode completion is notified by callback
 *
 *  hdl: pointer to encoder handle.
 *  in_buf : input buf object
 *  out_buf_slice1: output buf object
 *
 *  Return
 *  Success: 0.
 *  Failure: -1.
 */
int  vxe_enc_encode(vxe_enc_t *hdl, struct mm_buffer *in_buf,
		struct mm_buffer *out_buf);

/**
 *  Query informations about output buffer
 *
 *  hdl: pointer to encoder handle.
 *  nbuffers: store number of output buffers.
 *  max_size: store the max size of output buffer.
 *
 *  Return
 *  Success: 0.
 *  Failure: -1.
 */
int  vxe_enc_get_buf_info(vxe_enc_t *hdl, uint32_t *nbuffers, uint32_t *max_size);

#endif
