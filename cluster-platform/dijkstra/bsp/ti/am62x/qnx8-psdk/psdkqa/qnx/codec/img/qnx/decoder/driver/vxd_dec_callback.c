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
#include "vxd_dec_priv.h"
#include "dcmd_vxd_dec.h"
#include "mm_dec.h"

#define PRIORITY_REALTIME_LOW 29

/*!
 *  @brief  Keeps the information related to Event.
 */
struct vxd_dec_event {
    struct clist_head     buf_list;
    vxd_dec_ocb_t         *ocb;
    int attached;
};

struct vxd_dec_EventPacket {
    struct clist_head list;
    uint32_t ch_id;
    struct mm_buffer buf;
    mm_dec_process_cb cb_type;
    uint32_t error_flags;
    struct vxd_dec_EventPacket * next;
    struct vxd_dec_EventPacket * prev;
};

/*!
 *  @brief  Module state object
 */
typedef struct vxd_dec_ModuleObject_tag {
    struct vxd_dec_event eventState [MAX_NUM_CHANNELS];
    pthread_mutex_t lock;
    pthread_cond_t  cond;
} vxd_dec_ModuleObject;

static vxd_dec_ModuleObject vxd_dec_state =
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
static struct vxd_dec_EventPacket *uBuf_cache;
static int num_uBuf = 0;

static void flush_uBuf(void)
{
    struct vxd_dec_EventPacket *uBuf = NULL;

    while(uBuf_cache) {
        num_uBuf--;
        uBuf = uBuf_cache;
        uBuf_cache = (struct vxd_dec_EventPacket *)uBuf_cache->next;
        free(uBuf);
    }
}

static struct vxd_dec_EventPacket *get_uBuf(void)
{
    struct vxd_dec_EventPacket *uBuf;
    uBuf = uBuf_cache;
    if (uBuf != NULL) {
        uBuf_cache = (struct vxd_dec_EventPacket *)uBuf_cache->next;
        num_uBuf--;
    } else {
        uBuf = calloc(1, sizeof(struct vxd_dec_EventPacket));
    }
    return(uBuf);
}

static void put_uBuf(struct vxd_dec_EventPacket * uBuf)
{
    if (num_uBuf >= CACHE_NUM) {
        free(uBuf);
    } else {
        uBuf->next = (struct vxd_dec_EventPacket *)uBuf_cache;
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
 *  @sa         vxd_dec_attach
 */
int vxd_dec_attach (vxd_dec_ocb_t * ocb)
{
    pthread_mutex_lock(&vxd_dec_state.lock);

    INIT_OSA_LIST_HEAD(&vxd_dec_state.eventState[ocb->ch_id].buf_list);
    vxd_dec_state.eventState[ocb->ch_id].ocb = ocb;
    vxd_dec_state.eventState[ocb->ch_id].attached = true;

    pthread_mutex_unlock(&vxd_dec_state.lock);

    return 0;
}

int vxd_dec_addBufByObj(vxd_dec_ocb_t *ocb,
                        void *item,
                        mm_dec_process_cb cb_type)
{
    int32_t status = EOK;
    struct vxd_dec_EventPacket * uBuf = NULL;

    if (!ocb) {
        return -1;
    }

    /* Allocate memory for the buf */
    pthread_mutex_lock(&vxd_dec_state.lock);
    uBuf = get_uBuf();

    if (uBuf == NULL) {
        status = -ENOMEM;
        OSA_PR_ERR("Failed to allocate memory for event packet");
    }
    else {
        if (cb_type != MM_CB_ERROR && item)
            memcpy(&uBuf->buf, item, sizeof(struct mm_buffer));
        else if(cb_type == MM_CB_ERROR)
            uBuf->error_flags = *(uint32_t*)item;
        else
            memset(&uBuf->buf, 0, sizeof(struct mm_buffer));

        uBuf->cb_type = cb_type;
        osa_list_add_tail(&uBuf->list, &vxd_dec_state.eventState[ocb->ch_id].buf_list);
        ocb->nitems++;

        // notify clients who may have asked to be notified when there is out of band data.
        if( IOFUNC_NOTIFY_OBAND_CHECK(ocb->notify, ocb->nitems, 0)) {
            iofunc_notify_trigger(ocb->notify, ocb->nitems, IOFUNC_NOTIFY_OBAND);
        }
    }
    pthread_mutex_unlock(&vxd_dec_state.lock);

    return status;
}

int vxd_dec_detach (vxd_dec_ocb_t * ocb)
{
    struct vxd_dec_EventPacket * packet;
    struct clist_head *head = &vxd_dec_state.eventState [ocb->ch_id].buf_list;
    struct clist_head *list = head->next;

    pthread_mutex_lock(&vxd_dec_state.lock);

    vxd_dec_state.eventState [ocb->ch_id].ocb = NULL;
    vxd_dec_state.eventState[ocb->ch_id].attached = false;

    /* Check for pending ionotify/select calls */
    // notify clients who may have asked to be notified when there is out of band data.
    if( IOFUNC_NOTIFY_OBAND_CHECK(ocb->notify, ocb->nitems, 0)) {
        iofunc_notify_trigger(ocb->notify, ocb->nitems, IOFUNC_NOTIFY_OBAND);
    }

    /* Free event packets for any received but unprocessed events. */
    while(list != head ) {
        packet = osa_list_entry(list, struct vxd_dec_EventPacket, list);
        list = list->next;
        free (packet);
    }

    pthread_mutex_unlock(&vxd_dec_state.lock);
    return EOK;
}

int vxd_dec_handle_outband(resmgr_context_t *ctp, io_devctl_t *msg, iofunc_ocb_t* i_ocb )
{
    int32_t err = EOK;
    vxd_dec_ocb_t * ocb = (vxd_dec_ocb_t *)i_ocb;
    VXDDEC_GetOutBand_t io;
    struct vxd_dec_EventPacket * uBuf = NULL;

    pthread_mutex_lock(&vxd_dec_state.lock);
    if ((!ocb->created) ||
        (!vxd_dec_state.eventState[ocb->ch_id].attached)) {
        pthread_mutex_unlock(&vxd_dec_state.lock);
        OSA_PR_ERR("%s Invalid status", __func__);
        return EINVAL;
    }

    uBuf = osa_list_first_entry(&vxd_dec_state.eventState [ocb->ch_id].buf_list,
                                struct vxd_dec_EventPacket, list);
    if(uBuf == NULL) {
        pthread_mutex_unlock(&vxd_dec_state.lock);
        OSA_PR_ERR("%s Error: empty list for uBuf", __func__);
        return EINVAL;
    }

    memcpy(&io.buf, &uBuf->buf, sizeof(struct mm_buffer));
    io.type = uBuf->cb_type;
    io.error_flags = uBuf->error_flags;

    osa_list_del(&uBuf->list);
    put_uBuf(uBuf);
    ocb->nitems--;

    // setup the reply
    msg->o.nbytes  = 0;
    msg->o.ret_val = EOK;
    SETIOV(&ctp->iov[0], &msg->o, sizeof(msg->o));
    if( resmgr_msgwrite(ctp, &io, sizeof(io), sizeof(msg->o)) < 0 ) {
        err = errno;
        OSA_PR_ERR("VXDDEC_OUTBAND resmgr_msgwrite failed err=%d:'%s'", err, strerror(err));
    }
    pthread_mutex_unlock(&vxd_dec_state.lock);
    return err;
}

int vxd_dec_destroy_callback()
{
    uint32_t i;
    vxd_dec_ocb_t* ocb = NULL;

    for (i = 0 ; i < MAX_NUM_CHANNELS ; i++) {
        pthread_mutex_lock(&vxd_dec_state.lock);
        ocb = vxd_dec_state.eventState[i].ocb;
        /* Check for pending ionotify/select calls */
        if (ocb) {
            // notify clients who may have asked to be notified when there is out of band data.
            if( IOFUNC_NOTIFY_OBAND_CHECK(ocb->notify, ocb->nitems, 0)) {
                iofunc_notify_trigger(ocb->notify, ocb->nitems, IOFUNC_NOTIFY_OBAND);
            }        
        }
        vxd_dec_state.eventState [i].ocb = NULL;
        pthread_mutex_unlock(&vxd_dec_state.lock);
    }

    /* Free the cached list */
    pthread_mutex_lock(&vxd_dec_state.lock);
    flush_uBuf();
    pthread_mutex_unlock(&vxd_dec_state.lock);

    return 0;
}
