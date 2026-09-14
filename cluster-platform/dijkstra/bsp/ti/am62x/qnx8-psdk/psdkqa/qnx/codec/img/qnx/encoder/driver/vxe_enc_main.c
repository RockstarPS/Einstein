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

/*QNX specific header include */
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <malloc.h>
#include <devctl.h>
#define THREAD_POOL_PARAM_T dispatch_context_t
#include <sys/iofunc.h>
#include <sys/dispatch.h>
#include <sys/mman.h>
#include <sys/select.h>
#include <sys/procmgr.h>
#include <sys/slog.h>

#include "osa_define.h"
#include "osa_types.h"
#include "osa_list.h"

#include "vxe_enc_priv.h"
#include "dcmd_vxe_enc.h"
#include "mm_enc.h"

#define NUM_BASE_PIPE	(2)
static int g_log_level = _SLOG_INFO;
static int g_enc_instance_cnt = 0;
struct phys_addrs {
    uint64_t addr;
    uint32_t len;
};

struct vxe_enc_buffer {
    struct clist_head list;
    struct mm_buffer buf_orig;
    struct mm_buffer buf;
    uint32_t num_planes;
    uint8 mapped;
};

static int release_mm_buffers(struct clist_head *head)
{
    struct clist_head *list = head->next;
    struct vxe_enc_buffer *buf = NULL;
    uint32_t plane;

    while(list != head) {
        buf = osa_list_entry(list, struct vxe_enc_buffer, list);
        for (plane = 0; plane < buf->num_planes; plane++) {
            munmap(buf->buf.buf_addr[plane], buf->buf.alloc_size[plane]);
        }
        list = list->next;
        free(buf);
    }
    return 0;
}

IOFUNC_OCB_T *
ocb_calloc (resmgr_context_t * ctp, IOFUNC_ATTR_T * device)
{
    vxe_enc_ocb_t *ocb = NULL;

    /* Allocate the OCB */
    ocb = (vxe_enc_ocb_t *) calloc (1, sizeof (vxe_enc_ocb_t));
    if (ocb == NULL){
        errno = ENOMEM;
        return (NULL);
    }

    ocb->ch_id = -1;
    ocb->created = false;
    ocb->pid = ctp->info.pid;
    IOFUNC_NOTIFY_INIT(ocb->notify);

    INIT_OSA_LIST_HEAD(&ocb->buffers);

    g_enc_instance_cnt++;
    return (IOFUNC_OCB_T *)(ocb);
}

void
ocb_free (IOFUNC_OCB_T * i_ocb)
{
    vxe_enc_ocb_t * ocb = (vxe_enc_ocb_t *)i_ocb;

    if (ocb) {
        if (ocb->ch_id != -1) {
            MM_ENC_Destroy(ocb->ch_id);
            ocb->created = false;
            release_mm_buffers(&ocb->buffers);
            ocb->ch_id = -1;
        }

        free (ocb);
        g_enc_instance_cnt--;
    }
}

int vxe_enc_close_ocb (resmgr_context_t *ctp, void *reserved, iofunc_ocb_t *i_ocb)
{
    vxe_enc_ocb_t * ocb = (vxe_enc_ocb_t *)i_ocb;
    iofunc_notify_remove(ctp, ocb->notify);
    return (iofunc_close_ocb_default(ctp, reserved, i_ocb));
}


int
vxe_enc_validate_chid (vxe_enc_ocb_t * ocb, uint32_t ch_id)
{
    if (ocb->ch_id != ch_id) {
        OSA_PR_ERR("Invalid ch_id for this process!");
        return -1;
    }

    return 0;
}

static struct vxe_enc_buffer *find_mm_buffer(struct mm_buffer *b, struct clist_head *head, bool orig)
{
        struct clist_head *list;
        struct vxe_enc_buffer *buf = NULL;

        osa_list_for_each(list, head) {
                buf = osa_list_entry(list, struct vxe_enc_buffer, list);
                if (orig && (buf->buf_orig.buf_addr[0] == b->buf_addr[0]))
                        break;
                else if (!orig && (buf->buf.buf_addr[0] == b->buf_addr[0]))
                        break;
                buf = NULL;
        }
        return buf;
}

static void vxe_enc_cb(struct mm_buffer *buf, mm_enc_process_cb cb_type, void *ctx)
{
    int32_t status;
    struct vxe_enc_buffer *vxe_buf = NULL;
    vxe_enc_ocb_t * ocb = (vxe_enc_ocb_t *)ctx;

    /* find original buffer obj */
    if(buf)
        vxe_buf = find_mm_buffer(buf, &ocb->buffers, false);

    if (vxe_buf) {
        if(cb_type == MM_CB_CODED_BUFF_READY) {
            vxe_buf->buf_orig.size[0] = vxe_buf->buf.size[0];
        }
        status = vxe_enc_addBufByObj (ocb, &vxe_buf->buf_orig, cb_type);
    }
    else
        status = vxe_enc_addBufByObj (ocb, NULL, cb_type);

    if (status < 0)
        OSA_PR_ERR("vxe_enc_cb failed to add event buf");
}

static int vxe_enc_handle_buf_prepare(resmgr_context_t * ctp, io_devctl_t * msg,
                   iofunc_ocb_t * i_ocb)
{
    vxe_enc_ocb_t * ocb = (vxe_enc_ocb_t *)i_ocb;
    VXEENC_CmdArgs_t * cargs = (VXEENC_CmdArgs_t *)(_DEVCTL_DATA (msg->i));
    struct mm_buffer *orig_buffer;
    struct vxe_enc_buffer *new_buffer;
    int32_t plane, num_planes;

    if (vxe_enc_validate_chid(ocb, ocb->ch_id))
        return (EINVAL);

    orig_buffer = &cargs->args.buf_prepare.buffer;
    orig_buffer->chId = ocb->ch_id;
    num_planes = orig_buffer->num_planes;

    new_buffer = calloc(1, sizeof(struct vxe_enc_buffer));
    if(new_buffer == NULL) {
        OSA_PR_ERR("vxe_enc:%s Failed to calloc mem: errno %d", __func__, errno);
        return (ENOMEM);
    }
    new_buffer->buf_orig = *orig_buffer;
    new_buffer->buf = *orig_buffer;
    new_buffer->num_planes = num_planes;

    /* map the address into our process space and set the new buf_addr */
    for (plane = 0; plane < num_planes; plane++) {
        /* get contiguous virtual memory space */
        void *va = mmap64(NULL, orig_buffer->alloc_size[plane],
                    PROT_READ|PROT_WRITE|PROT_NOCACHE,
                    MAP_SHARED|MAP_PHYS,
                    NOFD, orig_buffer->physic_addr[plane]);
        if (va == MAP_FAILED) {
            OSA_PR_ERR("vxe_enc:%s Failed to get the virt mem: errno %d", __func__, errno);
            while(plane > 0) {
                plane--;
                munmap(new_buffer->buf.buf_addr[plane], new_buffer->buf.alloc_size[plane]);
            }
            return (EINVAL);
        }
        new_buffer->buf.buf_addr[plane] = va;
        new_buffer->buf.alloc_size[plane] = orig_buffer->alloc_size[plane];
        new_buffer->buf.size[plane] = orig_buffer->size[plane];
    }
    /* now we have a va in this process space that we can access. */
    cargs->status = MM_ENC_BufPrepare(&new_buffer->buf,
            ocb->ch_id);

    if (!cargs->status)
        osa_list_add_tail(&new_buffer->list, &ocb->buffers);
    else
        OSA_PR_ERR("vxe_enc:%s Error returned from MM_ENC_BufPrepare ", __func__);

    return cargs->status;
}

int vxe_enc_devctl(resmgr_context_t * ctp, io_devctl_t * msg,
                   iofunc_ocb_t * i_ocb)
{
    int status =  (EOK);
    vxe_enc_ocb_t * ocb = (vxe_enc_ocb_t *)i_ocb;
    int nbytes;
    int dcmd = msg->i.dcmd;
    VXEENC_CmdArgs_t * cargs = (VXEENC_CmdArgs_t *)(_DEVCTL_DATA (msg->i));

    if ((status = iofunc_devctl_default(ctp, msg, i_ocb)) != _RESMGR_DEFAULT)
        return (status);

    status = nbytes = 0;

    switch (dcmd)
    {
        case DCMD_MM_ENC_CREATE:
        {
            uint32_t ch_id;
            if (ocb->created) {
                OSA_PR_ERR("Error: Only one instance allowed per connection.");
                return (EINVAL);
            }

            /** set base pipe */
            cargs->args.create.ctrlp.base_pipe = ((g_enc_instance_cnt-1) % NUM_BASE_PIPE);
            status = MM_ENC_Create(&cargs->args.create.params, &cargs->args.create.ctrlp, &ch_id);
            if (!status) {
                ocb->ch_id = ch_id;
                status = MM_ENC_RegisterCb(vxe_enc_cb, ch_id, (void*) ocb);
                if (!status) {
                    vxe_enc_attach(ocb);
                    ocb->created = true;
                }
                else {
                    OSA_PR_ERR("DCMD_MM_ENC_CREATE: MM_ENC_RegisterCb failed");
                    MM_ENC_Destroy(ch_id);
                }
            }
        }
        break;
        case DCMD_MM_ENC_DESTROY:
        {
            if (vxe_enc_validate_chid(ocb, ocb->ch_id))
                return (EINVAL);

            vxe_enc_detach(ocb);
            status = MM_ENC_Destroy(ocb->ch_id);

            ocb->created = false;

            release_mm_buffers(&ocb->buffers);

            ocb->ch_id = -1;
        }
        break;
        case DCMD_MM_ENC_BUF_PREPARE:
        {
            status = vxe_enc_handle_buf_prepare(ctp, msg, i_ocb);
        }
        break;
        case DCMD_MM_ENC_START:
        {
            if (vxe_enc_validate_chid(ocb, ocb->ch_id))
                return (EINVAL);

            cargs->status = MM_ENC_StartStreaming(ocb->ch_id,
                                                  cargs->args.start.type);
        }
        break;
        case DCMD_MM_ENC_STOP:
        {
            if (vxe_enc_validate_chid(ocb, ocb->ch_id))
                return (EINVAL);

            cargs->status = MM_ENC_StopStreaming(ocb->ch_id,
                                                 cargs->args.stop.type);
        }
        break;
        case DCMD_MM_ENC_PROCESS:
        {
            struct vxe_enc_buffer *in_buf = NULL;
            struct vxe_enc_buffer *out_buf = NULL;

            if (vxe_enc_validate_chid(ocb, ocb->ch_id))
                return (EINVAL);

            in_buf = find_mm_buffer(&cargs->args.process.in_buf, &ocb->buffers, true);
            if (in_buf)
                in_buf->buf.size[0] = cargs->args.process.in_buf.size[0];
            out_buf = find_mm_buffer(&cargs->args.process.out_buf, &ocb->buffers, true);

            if (!in_buf || !out_buf) {
                OSA_PR_ERR("Invalid input (0x%p) or output (0x%p) buffer",
                           in_buf, out_buf);
                return (EINVAL);
            }
            cargs->status = MM_ENC_Process(&in_buf->buf, &out_buf->buf, NULL,
                                           ocb->ch_id);
        }
        break;
        case DCMD_MM_ENC_BUF_INFO:
        {
            VXEENC_BufInfo_t io;
            if(MM_ENC_QueryBufInfo(ocb->ch_id, &io.buf_num, &io.max_size) != 0) {
                OSA_PR_ERR("%s: MM_ENC_QueryBufInfo returns error", __func__);
                return (EINVAL);
            }
            // setup the reply
            msg->o.nbytes  = 0;
            msg->o.ret_val = EOK;
            SETIOV(&ctp->iov[0], &msg->o, sizeof(msg->o));
            if( resmgr_msgwrite(ctp, &io, sizeof(io), sizeof(msg->o)) < 0 ) {
                status = errno;
                OSA_PR_ERR("VXEENC_OUTBAND resmgr_msgwrite failed err=%d:'%s'", status, strerror(status));
            }
        }
        break;
        case DCMD_MM_ENC_GETOUTBAND:
        {
            status = vxe_enc_handle_outband(ctp, msg, i_ocb);
        }
        break;
        default:
            OSA_PR_ERR("unknown dcmd %d", dcmd);
        break;
    }

    return (_RESMGR_STATUS(ctp, status));
}

static int vxe_enc_io_close_dup( resmgr_context_t *ctp, io_close_t* msg, iofunc_ocb_t *i_ocb )
{
  int ret;
  vxe_enc_ocb_t * ocb = (vxe_enc_ocb_t *)i_ocb;

  /*
  * A client has closed its file descriptor or has terminated.
  * Unblock any threads waiting for notification, then
  * remove the client from the notification list.
  */
  iofunc_notify_trigger_strict( ctp, ocb->notify, INT_MAX, IOFUNC_NOTIFY_OBAND );
  iofunc_notify_remove(ctp, ocb->notify);
  ret = iofunc_close_dup_default(ctp, msg, &ocb->ocb);
  return ret;
}

static int vxe_enc_io_notify( resmgr_context_t *ctp, io_notify_t *msg, iofunc_ocb_t *i_ocb )
{
  int32_t trigger = 0;
  int32_t ret;
  vxe_enc_ocb_t * ocb = (vxe_enc_ocb_t *)i_ocb;

  if( ocb->nitems > 0 )
    trigger = _NOTIFY_COND_OBAND;
  // the iofunc_notify() will do any necessary handling, including adding the client to the notification list if need be.
  ret = iofunc_notify( ctp, msg, ocb->notify, trigger, NULL, NULL);
  return ret;
}

/**
 * OSA logger.
 *
 * @param level Verbosity level
 * @param fmt format
 * @param ap Variadic argument list
 */
void osa_qnx_logger(int level, const char *fmt, ...)
{
    va_list arglist;
    va_start(arglist, fmt);

    if (level <= g_log_level) {
        vslogf(_SLOG_SETCODE(_SLOGC_MEDIA, 2), level, fmt, arglist);
    }
    va_end(arglist);
}

void osa_qnx_dev_logger(int level, const void *dev, const char *fmt, ...)
{
    va_list arglist;
    va_start(arglist, fmt);

    if (level <= g_log_level) {
        vslogf(_SLOG_SETCODE(_SLOGC_MEDIA, 2), level, fmt, arglist);
    }
    va_end(arglist);
}


/**
 * Parse input options.
 *
 * @param argc Number of options.
 * @param argv Array of options.
 */
static void options(int argc, char *const argv[])
{
    int opt;
    int loglevel = 0;

    while ((opt = getopt(argc, argv, "v")) != -1) {
        switch (opt) {
            case 'v':
                    loglevel++;
                break;
            default:
                break;
        }
    }
    if(loglevel > 0)
        g_log_level = loglevel;
}

static resmgr_connect_funcs_t    connect_funcs;
static resmgr_io_funcs_t         io_funcs;
static iofunc_mount_t            mattr;
static iofunc_funcs_t            ocb_funcs;
static iofunc_attr_t             attr;

int
main(int argc, char *const argv[])
{
    resmgr_attr_t        resmgr_attr;
    dispatch_t           *dpp;
    int                  id;
    int                  ret = 0;
    struct stat          sbuf;
    thread_pool_attr_t   tattr;
    thread_pool_t        *tpool;
    sigset_t             set;

    if (-1 != stat(VXE_ENC_DEVICE_PATH, &sbuf)) {
        printf ("VXE-ENC Already Running...\n");
        return EXIT_FAILURE;
    }
    printf ("Starting VXE-ENC resource manager...\n");

    options(argc, argv);

    ret = procmgr_ability(0,
                        PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_KEYDATA,
                        PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_IO,
                        PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_MEM_PHYS,
                        PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_PRIORITY,
                        PROCMGR_AOP_DENY  | PROCMGR_ADN_NONROOT | PROCMGR_AOP_LOCK      | PROCMGR_AID_EOL);
    if(ret != EOK) {
        printf("Unable to gain procmgr abilities for nonroot operation.\n");
        return ret;
    }

    /* Obtain I/O privity */
    ret = ThreadCtl_r (_NTO_TCTL_IO, 0);
    if(ret != EOK) {
        printf("Unable to obtain I/O privity\n");
        return ret;
    }

    /* Initialize the encoder */
    mm_enc_init_params init_params = {0};
    MM_ENC_SetDefaultInitParams(&init_params);
    ret = MM_ENC_Init(&init_params);
    if(ret != 0) {
        printf("Error: MM_ENC_Init failed\n");
        return ret;
    }

    /* initialize dispatch interface */
    if((dpp = dispatch_create()) == NULL) {
        printf("%s: Unable to allocate dispatch handle.\n",argv[0]);
        return EXIT_FAILURE;
    }

    /*
     * Mask out signals before creating a thread pool.
     * This prevents other threads in the thread pool
     * from intercepting signals such as SIGTERM.
     */
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGTERM);
    sigaddset(&set, SIGKILL);
    pthread_sigmask(SIG_BLOCK, &set, NULL);

    /* Initialize the thread pool */
    memset (&tattr, 0x00, sizeof (thread_pool_attr_t));
    tattr.handle = dpp;
    tattr.context_alloc = dispatch_context_alloc;
    tattr.context_free = dispatch_context_free;
    tattr.block_func = dispatch_block;
    tattr.unblock_func = dispatch_unblock;
    tattr.handler_func = dispatch_handler;
    tattr.lo_water = 2;
    tattr.hi_water = 8;
    tattr.increment = 1;
    tattr.maximum = 50;

    /* initialize resource manager attributes */
    memset(&resmgr_attr, 0, sizeof resmgr_attr);
    resmgr_attr.nparts_max = 10;
    resmgr_attr.msg_max_size = 16384;
    memset(&mattr, 0, sizeof(iofunc_mount_t));
    mattr.flags = 0;
    mattr.conf = IOFUNC_PC_CHOWN_RESTRICTED | IOFUNC_PC_NO_TRUNC | IOFUNC_PC_SYNC_IO;
    mattr.dev = 0;
    mattr.blocksize=0;
    mattr.funcs = &ocb_funcs;
    memset(&ocb_funcs, 0, sizeof(iofunc_funcs_t));
    ocb_funcs.nfuncs = _IOFUNC_NFUNCS;
    ocb_funcs.ocb_calloc = ocb_calloc;
    ocb_funcs.ocb_free = ocb_free;
    memset(&io_funcs, 0, sizeof(resmgr_io_funcs_t));
    iofunc_func_init(_RESMGR_CONNECT_NFUNCS, &connect_funcs, _RESMGR_IO_NFUNCS, &io_funcs);
    io_funcs.devctl = vxe_enc_devctl;
    io_funcs.notify = vxe_enc_io_notify;
    io_funcs.close_dup = vxe_enc_io_close_dup;

    iofunc_attr_init(&attr, S_IFNAM | 0777 , 0, 0);
    attr.mount = &mattr;

    /* attach our device name */
    id = resmgr_attach(
            dpp,            /* dispatch handle        */
            &resmgr_attr,   /* resource manager attrs */
            VXE_ENC_DEVICE_PATH,   /* device name            */
            _FTYPE_ANY,     /* open type              */
            0,              /* flags                  */
            &connect_funcs, /* connect routines       */
            &io_funcs,      /* I/O routines           */
            &attr);         /* handle                 */

    if (id == -1) {
        fprintf(stderr, "%s: Unable to attach name.\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Create the thread pool */
    if ((tpool = thread_pool_create(&tattr, 0)) == NULL) {
        fprintf(stderr, "VXE-ENC: thread pool create failed\n");
        return EXIT_FAILURE;
    }

    /* make this a daemon process */
    if (-1 == procmgr_daemon(0,
        PROCMGR_DAEMON_NOCLOSE | PROCMGR_DAEMON_NODEVNULL)) {
        fprintf(stderr, "VXE-ENC: procmgr_daemon() failed\n");
        return EXIT_FAILURE;
    }

    /* start the thread pool */
    thread_pool_start(tpool);

    /* Wait for one of these signals */
    sigemptyset (&set);
    sigaddset (&set, SIGINT);
    sigaddset (&set, SIGQUIT);
    sigaddset (&set, SIGTERM);

    OSA_PR_INFO("VXE-ENC resource manager started\n");

    /* Wait for a signal */
    while (1)
    {
        switch (sigwaitinfo(&set, NULL))
        {
            case SIGTERM:
            case SIGQUIT:
            case SIGINT:
                goto done;

            default:
                goto done;
        }
    }

done:
    printf("VXE-ENC resource manager exiting \n");

    ret = thread_pool_destroy(tpool);
    if (ret < 0) {
        fprintf(stderr, "VXE-ENC: thread_pool_destroy returned an error\n");
    }

    resmgr_detach(dpp, id, _RESMGR_DETACH_ALL);

    vxe_enc_destroy_callback();

    MM_ENC_Deinit();

    return (ret);
}
