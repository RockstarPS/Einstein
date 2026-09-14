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

#include "vxd_dec_priv.h"
#include "dcmd_vxd_dec.h"
#include "mm_dec.h"

static int g_log_level = _SLOG_INFO;
struct phys_addrs {
    uint64_t addr;
    uint32_t len;
};

struct vxd_dec_buffer {
    struct clist_head list;
    struct mm_buffer buf_orig;
    struct mm_buffer buf;
    uint32_t num_planes;
    int32_t  refcnt;
};

static void logtofile(int fd, struct timespec *ts, const char *fmt, ... )
{
    static char linebuf[ LINE_MAX + 2 ];
    size_t offs = 0;
    size_t space = sizeof linebuf;
    int    len;
    struct tm tm;
    if ( localtime_r( &ts->tv_sec, &tm ) != NULL
            && ( len = strftime( linebuf, sizeof linebuf, "%F %T", &tm ) ) > 0 ) {
        offs  += len;
        space -= len;
        len = snprintf( linebuf+offs, space, ".%03u ", (unsigned)( ts->tv_nsec / 1000000 ) );
        if ( (size_t) len < space ) {
            offs  += len;
            space -= len;
        }
    }

    len = snprintf( linebuf+offs, space, "[OpenMAXIL.] ");
    if ( (size_t) len < space ) {
        offs  += len;
        space -= len;
    }
    va_list arglist;
    va_start(arglist, fmt);
    if ( ( len = vsnprintf( linebuf+offs, space, fmt, arglist ) ) > 0 ) {
        if ( len < (int)space ) {
            offs += len;
        } else {
            // It's been truncated.
            offs = sizeof linebuf - 1;
        }
        linebuf[ offs++ ] = '\n';
        write(fd, linebuf, offs);
    }
    va_end(arglist);
}

#define PERFORMANCE_LOG(fd, ...) (logtofile(fd, __VA_ARGS__))

static int32_t push_ts_entry(ts_q_t *theq, uint64_t new_ts)
{
    // Make sure we have space.
    if ((theq->tail_ind == (theq->head_ind + 1)) ||
            ((theq->tail_ind == 0) && (theq->head_ind == (MAX_TIMESTAMPS - 1) ))) {
        return ENOMEM;
    }

    theq->storage[theq->head_ind] = new_ts;
    theq->head_ind++;
    if (theq->head_ind == MAX_TIMESTAMPS) {
        theq->head_ind = 0;
    }

    return EOK;
}

static uint64_t pop_ts_entry(ts_q_t *theq)
{
    uint64_t ret;

    if (theq->tail_ind == theq->head_ind) {
        // No entries.
        return 0;
    }

    ret = theq->storage[theq->tail_ind];

    theq->tail_ind++;

    if (theq->tail_ind == MAX_TIMESTAMPS) {
        theq->tail_ind = 0;
    }

    return ret;
}

static int release_mm_buffers(struct clist_head *head)
{
    struct clist_head *list = head->next;
    struct vxd_dec_buffer *buf = NULL;
    uint32_t plane;

    while(list != head) {
        buf = osa_list_entry(list, struct vxd_dec_buffer, list);
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
    vxd_dec_ocb_t *ocb = NULL;

    /* Allocate the OCB */
    ocb = (vxd_dec_ocb_t *) calloc (1, sizeof (vxd_dec_ocb_t));
    if (ocb == NULL){
        errno = ENOMEM;
        return (NULL);
    }

    ocb->ch_id = -1;
    ocb->created = false;
    ocb->pid = ctp->info.pid;
    IOFUNC_NOTIFY_INIT(ocb->notify);

    INIT_OSA_LIST_HEAD(&ocb->buffers);
 
    return (IOFUNC_OCB_T *)(ocb);
}

void
ocb_free (IOFUNC_OCB_T * i_ocb)
{
    vxd_dec_ocb_t * ocb = (vxd_dec_ocb_t *)i_ocb;

    if (ocb) {
        if (ocb->ch_id != -1) {
            OSA_PR_INFO("Client exit improperly, clean up (ch_id=%d)!", ocb->ch_id);
            MM_DEC_Destroy(ocb->ch_id);
            ocb->created = false;
            release_mm_buffers(&ocb->buffers);
            ocb->ch_id = -1;
        }

        free (ocb);
    }
}

int vxd_dec_close_ocb (resmgr_context_t *ctp, void *reserved, iofunc_ocb_t *i_ocb)
{
    vxd_dec_ocb_t * ocb = (vxd_dec_ocb_t *)i_ocb;
    iofunc_notify_remove(ctp, ocb->notify);
    return (iofunc_close_ocb_default(ctp, reserved, i_ocb));
}


int
vxd_dec_validate_chid (vxd_dec_ocb_t * ocb, uint32_t ch_id)
{
    if (ocb->ch_id != ch_id) {
        OSA_PR_ERR("Invalid ch_id for this process!");
        return -1;
    }

    return 0;
}

static int return_mm_buffers(struct clist_head *head, vxd_dec_ocb_t * ocb)
{
    struct clist_head *list = head->next;
    struct vxd_dec_buffer *buf = NULL;

    while(list != head) {
        buf = osa_list_entry(list, struct vxd_dec_buffer, list);
        if(buf->refcnt > 0) {
            if(buf->buf_orig.type == MM_BUF_TYPE_VIDEO_INPUT)
                vxd_dec_addBufByObj (ocb, &buf->buf_orig, MM_CB_STRUNIT_PROCESSED);
            else
                vxd_dec_addBufByObj (ocb, &buf->buf_orig, MM_CB_PICT_RELEASE);
        }
        list = list->next;
    }
    return 0;
}

static struct vxd_dec_buffer *find_mm_buffer(struct mm_buffer *b, struct clist_head *head, bool orig)
{
    struct clist_head *list;
    struct vxd_dec_buffer *buf = NULL;

    osa_list_for_each(list, head) {
        buf = osa_list_entry(list, struct vxd_dec_buffer, list);
        if (orig && (buf->buf_orig.buf_addr[0] == b->buf_addr[0]))
            break;
        else if (!orig && (buf->buf.buf_addr[0] == b->buf_addr[0]))
            break;
        buf = NULL;
    }
    return buf;
}

static void vxd_dec_cb(void *item, mm_dec_process_cb cb_type, void *ctx)
{
    int32_t status;
    struct vxd_dec_buffer *vxd_buf = NULL;
    vxd_dec_ocb_t * ocb = (vxd_dec_ocb_t *)ctx;

    /* find original buffer obj */
    if(item && cb_type != MM_CB_ERROR) {
        vxd_buf = find_mm_buffer((struct mm_buffer*)item, &ocb->buffers, false);
    }

    if (vxd_buf) {
        vxd_buf->buf_orig.size[0] = vxd_buf->buf.size[0];
        if(cb_type == MM_CB_STRUNIT_PROCESSED || cb_type == MM_CB_PICT_RELEASE)
            vxd_buf->refcnt--;
        else if(ocb->plog_fd != -1) {
            struct timespec ts;
            clock_gettime(CLOCK_MONOTONIC, &ts);
            if(cb_type == MM_CB_PICT_DISPLAY){
                uint64_t curr_time = (ts.tv_sec * 1000000) + (ts.tv_nsec / 1000);
                PERFORMANCE_LOG(ocb->plog_fd, &ts, "Get frame %d out from codec\n", ocb->oframe_cnt);
                uint64_t sending_time = pop_ts_entry(&ocb->ts_q);
                int      delay = (curr_time - sending_time)/1000;
                PERFORMANCE_LOG(ocb->plog_fd, &ts, "Decoding delay for frame %d: %d ms\n", ocb->oframe_cnt, delay);
                ocb->oframe_cnt++;
            }

            if(ocb->status == STOPPED && ocb->iframe_cnt == ocb->oframe_cnt) {
                uint64_t stop_ts = (ts.tv_sec * 1000000) + (ts.tv_nsec / 1000);
                uint64_t dec_time = (stop_ts - ocb->dec_start_ts)/1000;
                float dec_frame_rate = ocb->oframe_cnt * 1000.0 / (float)dec_time;
                PERFORMANCE_LOG(ocb->plog_fd, &ts, "Total decoding time %lu ms.", dec_time);
                PERFORMANCE_LOG(ocb->plog_fd, &ts, "Number of decoded frames %d ", ocb->oframe_cnt);
                PERFORMANCE_LOG(ocb->plog_fd, &ts, "Decoding frame rate is %.2f fps.", dec_frame_rate);
                close(ocb->plog_fd);
                ocb->plog_fd = -1;
            }
        }

        status = vxd_dec_addBufByObj (ocb, &vxd_buf->buf_orig, cb_type);
    }
    else
        status = vxd_dec_addBufByObj (ocb, item, cb_type);

    if (status < 0)
        OSA_PR_ERR("vxd_dec_cb failed to add event buf");
}

static int vxd_dec_handle_buf_prepare(resmgr_context_t * ctp, io_devctl_t * msg,
                   iofunc_ocb_t * i_ocb)
{
    vxd_dec_ocb_t * ocb = (vxd_dec_ocb_t *)i_ocb;
    VXDDEC_CmdArgs_t * cargs = (VXDDEC_CmdArgs_t *)(_DEVCTL_DATA (msg->i));
    struct mm_buffer *orig_buffer;
    struct vxd_dec_buffer *new_buffer;
    int32_t plane, num_planes;

    if (vxd_dec_validate_chid(ocb, ocb->ch_id))
        return (EINVAL);

    orig_buffer = &cargs->args.buf_prepare.buffer;
    orig_buffer->chId = ocb->ch_id;
    num_planes = orig_buffer->num_planes;

    new_buffer = calloc(1, sizeof(struct vxd_dec_buffer));
    if(new_buffer == NULL) {
        OSA_PR_ERR("vxd_dec:%s Failed to calloc mem: errno %d", __func__, errno);
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
            OSA_PR_ERR("vxd_dec:%s Failed to get the virt mem: errno %d", __func__, errno);
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
    cargs->status = MM_DEC_BufPrepare(&new_buffer->buf,
            ocb->ch_id);

    if (!cargs->status)
        osa_list_add_tail(&new_buffer->list, &ocb->buffers);
    else
        OSA_PR_ERR("vxd_dec:%s Error returned from MM_DEC_BufPrepare ", __func__);

    return cargs->status;
}

int vxd_dec_devctl(resmgr_context_t * ctp, io_devctl_t * msg,
                   iofunc_ocb_t * i_ocb)
{
    int status =  (EOK);
    vxd_dec_ocb_t * ocb = (vxd_dec_ocb_t *)i_ocb;
    int nbytes;
    int dcmd = msg->i.dcmd;
    VXDDEC_CmdArgs_t * cargs = (VXDDEC_CmdArgs_t *)(_DEVCTL_DATA (msg->i));
    static const char logenvname[] = "VXDDEC_PERFORMANCE_LOG_DIR";
    char plog_path[128];

    if ((status = iofunc_devctl_default(ctp, msg, i_ocb)) != _RESMGR_DEFAULT)
        return (status);

    status = nbytes = 0;

    switch (dcmd)
    {
        case DCMD_MM_DEC_CREATE:
        {
            uint32_t ch_id;
            if (ocb->created) {
                OSA_PR_ERR("Error: Only one instance allowed per connection.");
                return (EINVAL);
            }

            status = MM_DEC_Create(&cargs->args.create.params, &cargs->args.create.ctrlp, &ch_id);
            if (!status) {
                ocb->ch_id = ch_id;
                status = MM_DEC_RegisterCb(vxd_dec_cb, ch_id, (void*) ocb);
                if (!status) {
                    vxd_dec_attach(ocb);
                    ocb->created = true;
                    const char *env;
                    if ( ( env = getenv( logenvname ) ) != NULL ) {
                        sprintf(plog_path, "%s/performance_log_ch_%d.log", env, ch_id);
                        ocb->plog_fd = open(plog_path, O_WRONLY | O_CREAT, 0644);
                        if(ocb->plog_fd == -1)
                            OSA_PR_INFO("Failed to open performance log file(%s).", plog_path);
                    }
                    else
                        ocb->plog_fd = -1;

                }
                else {
                    OSA_PR_ERR("DCMD_MM_DEC_CREATE: MM_DEC_RegisterCb failed");
                    MM_DEC_Destroy(ch_id);
                }
                ocb->status = CREATED;
            }
        }
        break;
        case DCMD_MM_DEC_DESTROY:
        {
            if (vxd_dec_validate_chid(ocb, ocb->ch_id))
                return (EINVAL);

            vxd_dec_detach(ocb);
            status = MM_DEC_Destroy(ocb->ch_id);

            ocb->created = false;

            release_mm_buffers(&ocb->buffers);

            ocb->ch_id = -1;
            ocb->status = IDLE;
        }
        break;
        case DCMD_MM_DEC_BUF_PREPARE:
        {
            status = vxd_dec_handle_buf_prepare(ctp, msg, i_ocb);
        }
        break;
        case DCMD_MM_DEC_START:
        {
            if (vxd_dec_validate_chid(ocb, ocb->ch_id))
                return (EINVAL);

            cargs->status = MM_DEC_StartStreaming(ocb->ch_id,
                                                  cargs->args.start.type);
            ocb->status = RUNNING;
        }
        break;
        case DCMD_MM_DEC_STOP:
        {
            if (vxd_dec_validate_chid(ocb, ocb->ch_id))
                return (EINVAL);

            cargs->status = MM_DEC_StopStreaming(ocb->ch_id,
                                                 cargs->args.stop.type);

            //return buffers that still hold in decoder
            return_mm_buffers(&ocb->buffers, ocb);
            ocb->status = STOPPED;
            if(ocb->plog_fd != -1 && ocb->iframe_cnt == ocb->oframe_cnt) {
                struct timespec ts;
                clock_gettime(CLOCK_MONOTONIC, &ts);

                uint64_t stop_ts = (ts.tv_sec * 1000000) + (ts.tv_nsec / 1000);
                uint64_t dec_time = (stop_ts - ocb->dec_start_ts)/1000;
                float dec_frame_rate = ocb->oframe_cnt * 1000.0 / (float)dec_time;
                PERFORMANCE_LOG(ocb->plog_fd, &ts, "Total decoding time %lu ms.", dec_time);
                PERFORMANCE_LOG(ocb->plog_fd, &ts, "Number of decoded frames %d ", ocb->oframe_cnt);
                PERFORMANCE_LOG(ocb->plog_fd, &ts, "Decoding frame rate is %.2f fps.", dec_frame_rate);
                close(ocb->plog_fd);
                ocb->plog_fd = -1;
            }
        
        }
        break;
        case DCMD_MM_DEC_PROCESS:
        {
            struct vxd_dec_buffer *in_buf = NULL;
            struct vxd_dec_buffer *out_buf = NULL;

            if (vxd_dec_validate_chid(ocb, ocb->ch_id))
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

            if(ocb->plog_fd != -1) {
                struct timespec ts;
                clock_gettime(CLOCK_MONOTONIC, &ts);
                uint64_t curr_time = (timespec2nsec( &ts ) / 1000LL);
                push_ts_entry(&ocb->ts_q, curr_time);
                PERFORMANCE_LOG(ocb->plog_fd, &ts, "Send frame %d in (frame length: %d)\n", ocb->iframe_cnt, in_buf->buf.size[0]);
                if(ocb->iframe_cnt == 0) {
                    ocb->dec_start_ts = curr_time;
                }
                ocb->iframe_cnt++;
            }

            in_buf->refcnt++;
            out_buf->refcnt++;
            cargs->status = MM_DEC_Process(&in_buf->buf, &out_buf->buf, ocb->ch_id);
        }
        break;
        case DCMD_MM_DEC_GETOUTBAND:
        {
            status = vxd_dec_handle_outband(ctp, msg, i_ocb);
        }
        break;
        default:
            OSA_PR_ERR("unknown dcmd %d", dcmd);
        break;
    }

    return (_RESMGR_STATUS(ctp, status));
}

static int vxd_dec_io_close_dup( resmgr_context_t *ctp, io_close_t* msg, iofunc_ocb_t *i_ocb )
{
  int ret;
  vxd_dec_ocb_t * ocb = (vxd_dec_ocb_t *)i_ocb;

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

static int vxd_dec_io_notify( resmgr_context_t *ctp, io_notify_t *msg, iofunc_ocb_t *i_ocb )
{
  int32_t trigger = 0;
  int32_t ret;
  vxd_dec_ocb_t * ocb = (vxd_dec_ocb_t *)i_ocb;

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
static int options(int argc, char *const argv[])
{
    int opt;
    int loglevel = 0;
    int err = EOK;

    while ((opt = getopt(argc, argv, "v")) != -1) {
        switch (opt) {
            case 'v':
                    loglevel++;
                break;
            case '?':
                err = EINVAL;
                break;
        }
    }
    if(loglevel > 0)
        g_log_level = loglevel;

    return err;
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

    if((options(argc, argv)) != EOK) {
        printf ("Starting VXD-DEC resource manager failed, invalid arguments\n");
        return EXIT_FAILURE;
    }

    if (-1 != stat(VXD_DEC_DEVICE_PATH, &sbuf)) {
        OSA_PR_ERR("VXD-DEC Already Running...");
        return EXIT_FAILURE;
    }
    OSA_PR_INFO("Starting VXD-DEC resource manager...");

    ret = procmgr_ability(0,
                        PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_KEYDATA,
                        PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_IO,
                        PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_MEM_PHYS,
                        PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_PRIORITY,
                        PROCMGR_AOP_DENY  | PROCMGR_ADN_NONROOT | PROCMGR_AOP_LOCK      | PROCMGR_AID_EOL);
    if(ret != EOK) {
        OSA_PR_ERR("Unable to gain procmgr abilities for nonroot operation.");
        return ret;
    }

    /* Obtain I/O privity */
    ret = ThreadCtl_r (_NTO_TCTL_IO, 0);
    if(ret != EOK) {
        OSA_PR_ERR("Unable to obtain I/O privity");
        return ret;
    }

    /* Initialize the decoder */
    ret = MM_DEC_Init();
    if(ret != 0) {
        OSA_PR_ERR("Error: MM_DEC_Init failed");
        return ret;
    }

    /* initialize dispatch interface */
    if((dpp = dispatch_create()) == NULL) {
        OSA_PR_ERR("%s: Unable to allocate dispatch handle.",argv[0]);
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
    sigaddset(&set, SIGQUIT);
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
    io_funcs.devctl = vxd_dec_devctl;
    io_funcs.notify = vxd_dec_io_notify;
    io_funcs.close_dup = vxd_dec_io_close_dup;

    iofunc_attr_init(&attr, S_IFNAM | 0777 , 0, 0);
    attr.mount = &mattr;

    /* attach our device name */
    id = resmgr_attach(
            dpp,            /* dispatch handle        */
            &resmgr_attr,   /* resource manager attrs */
            VXD_DEC_DEVICE_PATH,   /* device name            */
            _FTYPE_ANY,     /* open type              */
            0,              /* flags                  */
            &connect_funcs, /* connect routines       */
            &io_funcs,      /* I/O routines           */
            &attr);         /* handle                 */

    if (id == -1) {
        OSA_PR_ERR("%s: Unable to attach name.", argv[0]);
        return EXIT_FAILURE;
    }

    /* Create the thread pool */
    if ((tpool = thread_pool_create(&tattr, 0)) == NULL) {
        OSA_PR_ERR("VXD-DEC: thread pool create failed");
        return EXIT_FAILURE;
    }

    /* make this a daemon process */
    if (-1 == procmgr_daemon(0,
        PROCMGR_DAEMON_NOCLOSE | PROCMGR_DAEMON_NODEVNULL)) {
        OSA_PR_ERR("VXD-DEC: procmgr_daemon() failed");
        return EXIT_FAILURE;
    }

    /* start the thread pool */
    thread_pool_start(tpool);

    /* Wait for one of these signals */
    sigemptyset (&set);
    sigaddset (&set, SIGINT);
    sigaddset (&set, SIGQUIT);
    sigaddset (&set, SIGTERM);

    OSA_PR_INFO("VXD-DEC resource manager started");

    /* Wait for a signal */
    switch (sigwaitinfo(&set, NULL))
    {
        case SIGTERM:
        case SIGQUIT:
        case SIGINT:
            OSA_PR_INFO("VXD-DEC resource manager cought termination signal");
            goto done;

        default:
            OSA_PR_ERR( "VXD-DEC resource manager invalid signal received");
            goto done;
    }

done:
    OSA_PR_ERR("VXD-DEC resource manager exiting ");

    ret = thread_pool_destroy(tpool);
    if (ret < 0) {
        OSA_PR_ERR("VXD-DEC: thread_pool_destroy returned an error");
    }


    vxd_dec_destroy_callback();

    resmgr_detach(dpp, id, _RESMGR_DETACH_ALL);
    MM_DEC_Deinit();

    return (ret);
}
