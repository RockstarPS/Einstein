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

#ifndef VXD_DEC_H
#define VXD_DEC_H

#include "mm_dec.h"

#define MM_ERROR_RESOURCE (MM_ERROR_MAX + 1)

typedef struct vxd_dec_s {
    int fd;
    int chid;
    int coid;
    struct sigevent   event;
    void (*mm_ret_resource)(void *item, mm_dec_process_cb cb_type, void *cb_ctx);
    void *cb_ctx;
    pthread_t tid;         /* listener thread id                                    */
} vxd_dec_t;

/**
 *  open decoder
 *
 *  Return
 *  Success: pointer to decoder handle.
 *  Failure: NULL
 */
vxd_dec_t *vxd_dec_open(void);

/**
 *  close decoder
 *  hdl: pointer to decoder handle.
 */
void vxd_dec_close(vxd_dec_t *hdl);

/**
 *  Create an decoder instance
 *
 *  hdl: pointer to decoder handle.
 *  create_params: MM decoder create params
 *  ctrl_params  :   MM decoder control params
 *
 *  Return
 *  Success: 0.
 *  Failure: -1.
 */
int  vxd_dec_init(vxd_dec_t *hdl, mm_vid_create_params* create_params, mm_dec_ctrl_params *ctrl_params);

/**
 *  Destroy an decoder instance
 *
 *  hdl: pointer to decoder handle.
 *
 *  Return
 *  Success: 0.
 *  Failure: -1.
 */
int  vxd_dec_deinit(vxd_dec_t *hdl);


/**
 *  Register callback
 *  This is the callback function when decoder completes frame decoding
 *
 *  hdl: pointer to decoder handle.
 *  buf     : decoder output buffer (frame buffer)
 *  cb_type : callback Type.
 *  cb_ctx  : callback context.
 *
 *  Return
 *  Success: 0.
 *  Failure: -1.
 */
int  vxd_dec_register_callback(vxd_dec_t *hdl,
		void (*mm_ret_resource)(void *item, mm_dec_process_cb cb_type, void *cb_ctx),
		void *cb_ctx);

/**
 *  Start streaming of input or output
 *
 *  hdl: pointer to decoder handle.
 *  type : buffer type, input or output
 *
 *  Return
 *  Success: 0.
 *  Failure: -1.
 */
int  vxd_dec_start_streaming(vxd_dec_t *hdl,  mm_buffertype type);

/**
 *  Stop streaming of input or output
 *
 *  hdl: pointer to decoder handle.
 *  type : buffer type, input or output
 *
 *  Return
 *  Success: 0.
 *  Failure: -1.
 */
int  vxd_dec_stop_streaming(vxd_dec_t *hdl, mm_buffertype type);

/**
 *  Alloc/Prepare the decoder buffers
 *  This needs to be called for all input and output buffers
 *  at least once
 *
 *  hdl: pointer to decoder handle.
 *  buffer: buffer object
 *
 *  Return
 *  Success: 0.
 *  Failure: -1.
 */
int  vxd_dec_buf_prepare(vxd_dec_t *hdl, struct mm_buffer *buffer);

/**
 *  Perform the decode Process
 *  Non-blocking API, decode completion is notified by callback
 *
 *  hdl: pointer to decoder handle.
 *  in_buf : input buf object
 *  out_buf_slice1: output buf object
 *
 *  Return
 *  Success: 0.
 *  Failure: -1.
 */
int  vxd_dec_decode(vxd_dec_t *hdl, struct mm_buffer *in_buf,
		struct mm_buffer *out_buf);

#endif
