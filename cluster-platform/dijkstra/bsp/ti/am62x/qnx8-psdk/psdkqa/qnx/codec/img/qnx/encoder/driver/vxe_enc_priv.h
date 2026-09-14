/*
 * Copyright 2022, QNX Software Systems Ltd.
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

#include <sys/iofunc.h>
#include <stdbool.h>

#include "mm_enc.h"

#ifndef VXE_ENC_PRIV_H
#define VXE_ENC_PRIV_H

/*!
 *  @brief  Number of event entries to cache
 */
#define  CACHE_NUM              10
#define  MAX_NUM_CHANNELS       8

typedef struct vxe_enc_ocb {
    iofunc_ocb_t       ocb;
    pid_t              pid;
    bool               created;
    uint32_t           ch_id;
    int32_t            nitems;
    struct clist_head  buffers;
    iofunc_notify_t    notify[3];
} vxe_enc_ocb_t;

int vxe_enc_attach(vxe_enc_ocb_t * ocb);
int vxe_enc_detach(vxe_enc_ocb_t * ocb);
int vxe_enc_destroy_callback(void);
int vxe_enc_addBufByObj(vxe_enc_ocb_t *ocb, struct mm_buffer *buf, mm_enc_process_cb cb_type);
int vxe_enc_handle_outband(resmgr_context_t *ctp, io_devctl_t *msg, iofunc_ocb_t* i_ocb );

#endif /* VXE_ENC_PRIV_H */
