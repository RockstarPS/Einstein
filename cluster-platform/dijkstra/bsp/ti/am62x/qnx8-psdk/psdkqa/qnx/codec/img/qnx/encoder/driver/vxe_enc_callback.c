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


#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/neutrino.h>

#include "osa_define.h"
#include "osa_types.h"
#include "osa_list.h"
#include "vxe_enc_priv.h"
#include "dcmd_vxe_enc.h"
#include "mm_enc.h"

#define PRIORITY_REALTIME_LOW 29

/*!
 *  @brief  Keeps the information related to Event.
 */
struct vxe_enc_event {
    struct clist_head     buf_list;
    vxe_enc_ocb_t         *ocb;
    int attached;
};

struct vxe_enc_EventPacket {
    struct clist_head list;
    uint32_t ch_id;
    struct mm_buffer buf;
    mm_enc_process_cb cb_type;
    struct vxe_enc_EventPacket * next;
    struct vxe_enc_EventPacket * prev;
};

/*!
 *  @brief  Module state object
 */
typedef struct vxe_enc_ModuleObject_tag {
    struct vxe_enc_event eventState [MAX_NUM_CHANNELS];
    pthread_mutex_t lock;
    pthread_cond_t  cond;
} vxe_enc_ModuleObject;

static vxe_enc_ModuleObject vxe_enc_state =
{
    .lock = PTHREAD_MUTEX_INITIALIZER,
    .cond = PTHREAD_COND_INITIALIZER,
};

/** ============================================================================
 *  Internal functions
 *  ============================================================================
 */

/*
 * Instead of constantly allocating and freeing the uBuf structures
 * we just cache a few of them, and recycle them instead.
 * The cache count is set with CACHE_NUM in rpmsg-omxdrv.h.
 */
static struct vxe_enc_EventPacket *uBuf_cache;
static int num_uBuf = 0;

static void flush_uBuf()
{
    struct vxe_enc_EventPacket *uBuf = NULL;

    while(uBuf_cache) {
        num_uBuf--;
        uBuf = uBuf_cache;
        uBuf_cache = (struct vxe_enc_EventPacket *)uBuf_cache->next;
        free(uBuf);
    }
}

static struct vxe_enc_EventPacket *get_uBuf()
{
    struct vxe_enc_EventPacket *uBuf;
    uBuf = uBuf_cache;
    if (uBuf != NULL) {
        uBuf_cache = (struct vxe_enc_EventPacket *)uBuf_cache->next;
        num_uBuf--;
    } else {
        uBuf = calloc(1, sizeof(struct vxe_enc_EventPacket));
    }
    return(uBuf);
}

static void put_uBuf(struct vxe_enc_EventPacket * uBuf)
{
    if (num_uBuf >= CACHE_NUM) {
        free(uBuf);
    } else {
        uBuf->next = (struct vxe_enc_EventPacket *)uBuf_cache;
        uBuf_cache = uBuf;
        num_uBuf++;
    }
    return;
}

/*!
 *  @brief      Attach a process to the user support framework.
 *
 *  @param      ocb  instance
 *
 *  @sa         vxe_enc_attach
 */
int vxe_enc_attach (vxe_enc_ocb_t * ocb)
{
    pthread_mutex_lock(&vxe_enc_state.lock);

    INIT_OSA_LIST_HEAD(&vxe_enc_state.eventState[ocb->ch_id].buf_list);
    vxe_enc_state.eventState[ocb->ch_id].ocb = ocb;
    vxe_enc_state.eventState[ocb->ch_id].attached = true;

    pthread_mutex_unlock(&vxe_enc_state.lock);

    return 0;
}

int vxe_enc_addBufByObj(vxe_enc_ocb_t *ocb,
                        struct mm_buffer *buf,
                        mm_enc_process_cb cb_type)
{
    int32_t status = EOK;
    struct vxe_enc_EventPacket * uBuf = NULL;

    if (!ocb) {
        return -1;
    }

    /* Allocate memory for the buf */
    pthread_mutex_lock(&vxe_enc_state.lock);
    uBuf = get_uBuf();
    pthread_mutex_unlock(&vxe_enc_state.lock);

    if (uBuf == NULL) {
        status = -ENOMEM;
        OSA_PR_ERR("Failed to allocate memory for event packet");
    }
    else {
        if (buf)
            memcpy(&uBuf->buf, buf, sizeof(struct mm_buffer));
        else
            memset(&uBuf->buf, 0, sizeof(struct mm_buffer));

        uBuf->cb_type = cb_type;

        osa_list_add_tail(&uBuf->list, &vxe_enc_state.eventState[ocb->ch_id].buf_list);
        ocb->nitems++;

        // notify clients who may have asked to be notified when there is out of band data.
        if( IOFUNC_NOTIFY_OBAND_CHECK(ocb->notify, ocb->nitems, 0)) {
            iofunc_notify_trigger(ocb->notify, ocb->nitems, IOFUNC_NOTIFY_OBAND);
        }        
    }

    return status;
}

int vxe_enc_detach (vxe_enc_ocb_t * ocb)
{
    struct vxe_enc_EventPacket * packet;
    struct clist_head *head = &vxe_enc_state.eventState [ocb->ch_id].buf_list;
    struct clist_head *list = head->next;

    pthread_mutex_lock(&vxe_enc_state.lock);

    vxe_enc_state.eventState [ocb->ch_id].ocb = NULL;
    vxe_enc_state.eventState[ocb->ch_id].attached = false;

    /* Check for pending ionotify/select calls */
    // notify clients who may have asked to be notified when there is out of band data.
    if( IOFUNC_NOTIFY_OBAND_CHECK(ocb->notify, ocb->nitems, 0)) {
        iofunc_notify_trigger(ocb->notify, ocb->nitems, IOFUNC_NOTIFY_OBAND);
    }

    /* Free event packets for any received but unprocessed events. */
    while(list != head ) {
        packet = osa_list_entry(list, struct vxe_enc_EventPacket, list);
        list = list->next;
        free (packet);
    }

    pthread_mutex_unlock(&vxe_enc_state.lock);
    return EOK;
}

int vxe_enc_handle_outband(resmgr_context_t *ctp, io_devctl_t *msg, iofunc_ocb_t* i_ocb )
{
    int32_t err = EOK;
    vxe_enc_ocb_t * ocb = (vxe_enc_ocb_t *)i_ocb;
    VXEENC_GetOutBand_t io;
    struct vxe_enc_EventPacket * uBuf = NULL;

    pthread_mutex_lock(&vxe_enc_state.lock);
    if ((!ocb->created) ||
        (!vxe_enc_state.eventState[ocb->ch_id].attached)) {
        pthread_mutex_unlock(&vxe_enc_state.lock);
        OSA_PR_ERR("%s Invalid status", __func__);
        return EINVAL;
    }

    uBuf = osa_list_first_entry(&vxe_enc_state.eventState [ocb->ch_id].buf_list,
                                struct vxe_enc_EventPacket, list);
    if(uBuf == NULL) {
        pthread_mutex_unlock(&vxe_enc_state.lock);
        OSA_PR_ERR("%s Error: empty list for uBuf", __func__);
        return EINVAL;
    }

    memcpy(&io.buf, &uBuf->buf, sizeof(struct mm_buffer));
    io.type = uBuf->cb_type;

    osa_list_del(&uBuf->list);
    put_uBuf(uBuf);
    ocb->nitems--;

    // setup the reply
    msg->o.nbytes  = 0;
    msg->o.ret_val = EOK;
    SETIOV(&ctp->iov[0], &msg->o, sizeof(msg->o));
    if( resmgr_msgwrite(ctp, &io, sizeof(io), sizeof(msg->o)) < 0 ) {
        err = errno;
        OSA_PR_ERR("VXEENC_OUTBAND resmgr_msgwrite failed err=%d:'%s'", err, strerror(err));
    }
    pthread_mutex_unlock(&vxe_enc_state.lock);
    return err;
}

int vxe_enc_destroy_callback()
{
    uint32_t i;
    vxe_enc_ocb_t* ocb = NULL;

    for (i = 0 ; i < MAX_NUM_CHANNELS ; i++) {
        pthread_mutex_lock(&vxe_enc_state.lock);
        ocb = vxe_enc_state.eventState[i].ocb;
        /* Check for pending ionotify/select calls */
        if (ocb) {
            // notify clients who may have asked to be notified when there is out of band data.
            if( IOFUNC_NOTIFY_OBAND_CHECK(ocb->notify, ocb->nitems, 0)) {
                iofunc_notify_trigger(ocb->notify, ocb->nitems, IOFUNC_NOTIFY_OBAND);
            }        
        }
        vxe_enc_state.eventState [i].ocb = NULL;
        pthread_mutex_unlock(&vxe_enc_state.lock);
    }

    /* Free the cached list */
    pthread_mutex_lock(&vxe_enc_state.lock);
    flush_uBuf();
    pthread_mutex_unlock(&vxe_enc_state.lock);

    return 0;
}
