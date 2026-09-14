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

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>     /* SIGIO */
#include <fcntl.h>      /* fcntl */
#include <pthread.h>
#include <sys/mman.h>   /* mmap */
#include <sys/ioctl.h>
#include <errno.h>
#include <inttypes.h>
#include <devctl.h>
#include <sys/iofunc.h>
#include <sys/dispatch.h>

#include <dcmd_vxe_enc.h>

#include "vxe_enc-cli.h"

#define MAX_OBAND_ERROR  5 // Tolerated maximum value of consecutive 'Out Of Band' event fetching errors

enum pulse_codes
{
    PULSE_CODE_VXEENC        = _PULSE_CODE_MINAVAIL,  // Event pulses from VXEENC when oband notification (callback)  needs processing
    PULSE_CODE_VXEENC_CLOSE,                          // Pulse we send to ourselves when an OCB is being closed
};

static int32_t notify_arm( vxe_enc_t *hdl )
{
    int32_t err;
    if( (err = ionotify(hdl->fd, _NOTIFY_ACTION_POLLARM,  _NOTIFY_COND_OBAND, &hdl->event)) == -1 ) {
        err= errno;
    }
    else if( err > 0 ) {
        // The condition is already satisfied
        if( (err = MsgSendPulse(hdl->coid, -1, PULSE_CODE_VXEENC, 0)) == -1) {
            err = errno;
        }
    }
    return err;
}

static void *notify_thread( void *arg )
{
    vxe_enc_t *hdl  = (vxe_enc_t *) arg;
    int32_t         di   = -1;
    int32_t         ecount = 0;
    int32_t         rcvid;
    struct _pulse   msg;
    int32_t         err;

    pthread_setname_np(0, "vxeenc_listener");
    while( 1 ) {
        if( (err = notify_arm(hdl)) != EOK ) {
            if(hdl->mm_ret_resource != NULL)
                hdl->mm_ret_resource(NULL, MM_CB_ENC_ERROR_FATAL, hdl->cb_ctx);
            break;
        }
        else {
            if( (rcvid = MsgReceive(hdl->chid, &msg, sizeof(msg), NULL)) != EOK ) {
                if(hdl->mm_ret_resource != NULL)
                    hdl->mm_ret_resource(NULL, MM_CB_ENC_ERROR_FATAL, hdl->cb_ctx);
                break;
            }

            if( msg.code != PULSE_CODE_VXEENC ) {
                break;
            }
            else {
                VXEENC_GetOutBand_t io = {0};
                if( (err = devctl(hdl->fd, DCMD_MM_ENC_GETOUTBAND, &io, sizeof(io), &di)) != EOK ) {
                    ecount++;
                    if( ecount >= MAX_OBAND_ERROR ) {
                        if(hdl->mm_ret_resource != NULL)
                            hdl->mm_ret_resource(NULL, MM_CB_ENC_ERROR_FATAL, hdl->cb_ctx);
                        break;
                    }
                }
                else {
                    // success
                    ecount = 0;
                    if(hdl->mm_ret_resource != NULL) {
                        struct mm_buffer *buf = io.buf.rm_private;
                        if(buf)
                            memcpy(buf, &io.buf, sizeof(struct mm_buffer));
                        hdl->mm_ret_resource(buf, io.type, hdl->cb_ctx);
                    }
                }
            }
        }
    }
    return NULL;
}

static int32_t notify_create( vxe_enc_t* hdl )
{
    int32_t err;
    // Create a channel where notifications can trickle in on the different events
    if( (hdl->chid = ChannelCreate(_NTO_CHF_PRIVATE)) == -1 ) {
        err =  errno;
        return err;
    }
    else {
        if( (hdl->coid = ConnectAttach(0, 0, hdl->chid, _NTO_SIDE_CHANNEL, _NTO_COF_REG_EVENTS )) == -1) {
            err = errno;
        }
        else {
            SIGEV_PULSE_INIT(&hdl->event, hdl->coid, SIGEV_PULSE_PRIO_INHERIT, PULSE_CODE_VXEENC, 0);
            if( (err = MsgRegisterEvent_r(&hdl->event, hdl->fd)) == EOK ) {
                if( (err = pthread_create( &hdl->tid, NULL, notify_thread, hdl ) ) == EOK ) {
                    // success
                    return err;
                }
                else {
                    MsgUnregisterEvent(&hdl->event);
                }
            }
            ConnectDetach(hdl->coid);
        }
        ChannelDestroy( hdl->chid );
    }
    return err;
}

static void notify_destroy( vxe_enc_t* hdl )
{
  MsgSendPulse(hdl->coid, -1, PULSE_CODE_VXEENC_CLOSE, 0);
  pthread_join(hdl->tid, NULL);
  MsgUnregisterEvent(&hdl->event);
  ConnectDetach(hdl->coid);
  ChannelDestroy(hdl->chid);
}

vxe_enc_t *vxe_enc_open()
{
    vxe_enc_t *hdl = (vxe_enc_t *)calloc(1, sizeof(vxe_enc_t));
    if(hdl == NULL) {
        return NULL;
    }

    hdl->fd = open(VXE_ENC_DEVICE_PATH, O_RDWR);
    if(hdl->fd == -1) {
        free(hdl);
        return NULL;
    }

    if( notify_create(hdl) != EOK ) {
        close(hdl->fd);
        free(hdl);
        return NULL;
    }

    return hdl;
}

void vxe_enc_close(vxe_enc_t *hdl)
{
    if(hdl == NULL) {
        return;
    }

    notify_destroy(hdl);
    close(hdl->fd);
    free(hdl);
}

int  vxe_enc_init(vxe_enc_t *hdl, mm_vid_create_params* create_params, mm_enc_ctrl_params *ctrl_params)
{
    if(hdl == NULL) {
        return EINVAL;
    }

    iov_t               iov_i[2];
    SETIOV(&(iov_i[0]), create_params, sizeof(mm_vid_create_params));
    SETIOV(&(iov_i[1]), ctrl_params, sizeof(mm_enc_ctrl_params));
    return devctlv(hdl->fd, DCMD_MM_ENC_CREATE, 2, 0, iov_i, NULL, NULL);
}

int  vxe_enc_deinit(vxe_enc_t *hdl)
{
    if(hdl == NULL) {
        return EINVAL;
    }

    return devctlv(hdl->fd, DCMD_MM_ENC_DESTROY, 0, 0, NULL, NULL, NULL);
}


int  vxe_enc_register_callback(vxe_enc_t *hdl,
        void (*mm_ret_resource)(struct mm_buffer *buf, mm_enc_process_cb cb_type, void *cb_ctx),
        void *cb_ctx)
{
    if(hdl == NULL) {
        return EINVAL;
    }
    hdl->mm_ret_resource = mm_ret_resource;
    hdl->cb_ctx = cb_ctx;

    return EOK;
}

int  vxe_enc_start_streaming(vxe_enc_t *hdl,  mm_buffertype type)
{
    if(hdl == NULL) {
        return EINVAL;
    }
    iov_t               iov_i[1];
    SETIOV(iov_i, &type, sizeof(type));
    return devctlv(hdl->fd, DCMD_MM_ENC_START, 1, 0, iov_i, NULL, NULL);;
}

int  vxe_enc_stop_streaming(vxe_enc_t *hdl, mm_buffertype type)
{
    if(hdl == NULL) {
        return EINVAL;
    }
    iov_t               iov_i[1];
    SETIOV(iov_i, &type, sizeof(type));
    return devctlv(hdl->fd, DCMD_MM_ENC_STOP, 1, 0, iov_i, NULL, NULL);
}

int  vxe_enc_buf_prepare(vxe_enc_t *hdl, struct mm_buffer *buffer)
{
    if(hdl == NULL) {
        return EINVAL;
    }
    buffer->rm_private = buffer;
    iov_t               iov_i[1];
    SETIOV(iov_i, buffer, sizeof(struct mm_buffer));
    return devctlv(hdl->fd, DCMD_MM_ENC_BUF_PREPARE, 1, 0, iov_i, NULL, NULL);
}

int  vxe_enc_encode(vxe_enc_t *hdl, struct mm_buffer *in_buf,
        struct mm_buffer *out_buf)
{
    iov_t               iov_i[2];
    if(hdl == NULL) {
        return EINVAL;
    }
    SETIOV(&(iov_i[0]), in_buf, sizeof(struct mm_buffer));
    SETIOV(&(iov_i[1]), out_buf, sizeof(struct mm_buffer));
    return  devctlv(hdl->fd, DCMD_MM_ENC_PROCESS, 2, 0, iov_i, NULL, NULL);
}

int  vxe_enc_get_buf_info(vxe_enc_t *hdl, uint32_t *nbuffers, uint32_t *max_size)
{
    int32_t err;
    VXEENC_BufInfo_t io = {0};

    if(hdl == NULL) {
        return EINVAL;
    }

    if( (err = devctl(hdl->fd, DCMD_MM_ENC_BUF_INFO, &io, sizeof(io), NULL)) == EOK ) {
        *nbuffers = io.buf_num;
        *max_size = io.max_size;
    }
    return err;
}

