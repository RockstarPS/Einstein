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

/* System libraries */
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <termios.h>
#include <pthread.h>
#include <stdbool.h>
#include <inttypes.h>
#include <getopt.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/siginfo.h>
#include <sys/neutrino.h>
#include <sys/procmgr.h>
#include <sys/mman.h>
#include <stdarg.h>
#include <screen/screen.h>

#include "osa_define.h"
#include "osa_time.h"
#ifdef VXD_DEC_RESOURCE_MANAGER
#include "../cli/vxd_dec-cli.h"
#else
#include "mm_dec.h"
#endif
#include "input.h"

#define INPUT_BUFFER_NUM 7
#define OUTPUT_BUFFER_NUM 18

static int g_log_lvl = _SLOG_INFO;
/* Meaningful bailing values */
typedef enum
{
    NOT_BAILING,
    BAIL_BY_INPUT_EOS,
    BAIL_BY_OUTPUT_EOS,
    BAIL_BY_ERROR,
    BAIL_BY_USER,
} bail_e;

/* Global control variable */
bail_e g_bail = NOT_BAILING;

/* Mutexes and condition variables */
pthread_mutex_t g_video_decode_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t g_video_decode_cond = PTHREAD_COND_INITIALIZER;

typedef struct mm_buffer mm_buffer_t;

typedef struct {
    const char *name;
    uint16_t read_index;
    uint16_t write_index;
    uint16_t max_index;
    void** item;
} qfifo_t;

typedef struct qvdec_handle_s {
#ifdef VXD_DEC_RESOURCE_MANAGER
    vxd_dec_t *dec_hdl;
#else
    uint32_t dec_ch_id;
#endif
    input_handle_t *input_hdl;

    const char *in_path;
    int      out_fd;
    uint32_t rsize;
    int32_t stride;
    uint32_t num_in_bufs;
    uint32_t num_out_bufs;
    uint32_t input_buf_size;
    int planar_offsets[3];

    screen_context_t screen_ctx;
    screen_window_t screen_win;

    pthread_t input_push;

    qfifo_t          *inbuf_q;
    qfifo_t          *outbuf_q;
    mm_buffer_t      input_bufs[INPUT_BUFFER_NUM];
    mm_buffer_t      output_bufs[OUTPUT_BUFFER_NUM];

    uint64_t         last_frame_ts;
    uint32_t         frame_duration;
} qvdec_handle_t;
qvdec_handle_t dec_hdl = { 0 };

static void set_bail(uint32_t reason)
{
    char *reason_str;
    switch (reason) {
    case BAIL_BY_INPUT_EOS:
        reason_str = "Input End of Stream";
        break;
    case BAIL_BY_OUTPUT_EOS:
        reason_str = "Output End of Stream";
        break;
    case BAIL_BY_ERROR:
        reason_str = "Error";
        break;
    case BAIL_BY_USER:
        reason_str = "User request";
        break;
    default:
        reason_str = "Unknown";
    }
    OSA_PR_ERR("Bail reason: %s\n", reason_str);
    pthread_mutex_lock(&g_video_decode_mutex);
    g_bail = reason;
    pthread_cond_signal(&g_video_decode_cond);
    pthread_mutex_unlock(&g_video_decode_mutex);
}

static int fourcc2screenformat(uint32_t fourcc)
{
    int fmt = 0;
    if(fourcc == MM_PIX_FMT_NV12) {
        fmt = SCREEN_FORMAT_NV12;
    }
    else if(fourcc == MM_PIX_FMT_FORCE32BITS) {
        fmt = SCREEN_FORMAT_RGBA8888;
    }
    else {
        OSA_PR_ERR("Unsupported input format %x", fourcc);
    }

    return fmt;
}

//a simple fifo for buffer management
static qfifo_t *qfifo_create( uint32_t nbuf, const char *name )
{
    qfifo_t *pfifo = calloc(1, sizeof(qfifo_t));
    if( pfifo ) {
        pfifo->max_index = nbuf + 1;
        pfifo->item = (void **)calloc( pfifo->max_index, sizeof(void *) );
        if( pfifo->item == NULL ) {
            OSA_PR_ERR("CreateQueue memory failure for item (%zu)",
                    pfifo->max_index * sizeof(void *));
            free(pfifo);
            return NULL;
        }

        pfifo->name = name;
    }
    return pfifo;
}

static inline bool qfifo_empty( qfifo_t *q )
{
    return (q->read_index == q->write_index);
}

static inline bool qfifo_full( qfifo_t *q )
{
    return ( ( ( q->write_index + 1 ) % q->max_index ) == q->read_index );
}

static bool qfifo_put( qfifo_t *q, void *item )
{
    bool result = false;

    //check if buf header queue is full
    if( qfifo_full( q ) ) {
        OSA_PR_ERR("QueuePut(%s) queue is full(write_index %d,read_index %d)",
                               q->name, q->write_index, q->read_index);
        return result;
    }

    q->item[q->write_index] = item;
    q->write_index = (q->write_index + 1) % q->max_index;
    result = true;

    return result;
}

static void *qfifo_get( qfifo_t *q)
{
    void *ritem = NULL;

    //check if buf header queue is empty
    if( qfifo_empty( q ) ) {
        OSA_PR_DEBUG("QueueGet(%s) queue is empty(write_index %d,read_index %d)",
                               q->name, q->write_index, q->read_index);
        return NULL;
    }

    ritem = q->item[q->read_index];
    q->item[q->read_index] = NULL;
    q->read_index = ( q->read_index + 1 ) % q->max_index;

    return ritem;
}

static void qfifo_destroy( qfifo_t *q )
{
    free( q->item);
    free( q );
}

static mm_buffer_t *get_frame(qvdec_handle_t *hdl)
{
    pthread_mutex_lock(&g_video_decode_mutex);
    mm_buffer_t *buffer = (mm_buffer_t *)qfifo_get(hdl->inbuf_q);
    pthread_mutex_unlock(&g_video_decode_mutex);
    if(buffer != NULL) {
        OSA_PR_INFO("%s:%d get input buffer(%p:%d->%p, %llx)", __func__, __LINE__, buffer, buffer->size[0],buffer->buf_addr[0], buffer->physic_addr[0]);
        buffer->size[0] = 0;
        readFrame(hdl->input_hdl, buffer->buf_addr[0], &(buffer->size[0]));
    }
    return buffer;
}

//main loop to feed input and handle output.
static void *input_push_thread(void *args)
{
    pthread_setname_np(pthread_self(), "input_push_thread");
    OSA_PR_INFO("input_push_thread has started");

    qvdec_handle_t *hdl = (qvdec_handle_t *)args;

    for (;;) {
        pthread_mutex_lock(&g_video_decode_mutex);
        bail_e bail = g_bail;
        pthread_mutex_unlock(&g_video_decode_mutex);
        if (bail == BAIL_BY_INPUT_EOS || bail == BAIL_BY_OUTPUT_EOS  || bail == BAIL_BY_ERROR || bail == BAIL_BY_USER) {
            break;
        }

        mm_buffer_t *ibuffer = get_frame(hdl);
        pthread_mutex_lock(&g_video_decode_mutex);
        if(ibuffer == NULL) {
            OSA_PR_DEBUG("input_push_thread wait for input");
            pthread_cond_wait(&g_video_decode_cond, &g_video_decode_mutex);
            pthread_mutex_unlock(&g_video_decode_mutex);
            continue;
        }

        mm_buffer_t *obuffer = NULL;
        do {
            obuffer = (mm_buffer_t *)qfifo_get(hdl->outbuf_q);
            if(obuffer == NULL) {
                OSA_PR_DEBUG("input_push_thread wait for output");
                pthread_cond_wait(&g_video_decode_cond, &g_video_decode_mutex);

                bail = g_bail;
                if (bail == BAIL_BY_INPUT_EOS || bail == BAIL_BY_OUTPUT_EOS  || bail == BAIL_BY_ERROR || bail == BAIL_BY_USER)
                    break;
            }
            else
                break;
        } while(1);

        pthread_mutex_unlock(&g_video_decode_mutex);

        OSA_PR_INFO("input_push_thread send input(%p:%d), output(%p)", ibuffer, ibuffer ? ibuffer->size[0] : 0, obuffer);
        if(ibuffer->size[0] > 0) {
#ifdef VXD_DEC_RESOURCE_MANAGER
            if(0 != vxd_dec_decode(hdl->dec_hdl, ibuffer, obuffer)) {
#else
            if(0 != MM_DEC_Process(ibuffer, obuffer, hdl->dec_ch_id)) {
#endif
                set_bail(BAIL_BY_ERROR);
                OSA_PR_ERR("input_push_thread decode error");
                break;
            }
            struct timespec ts;
            clock_gettime(CLOCK_MONOTONIC, &ts);
            uint64_t curr_time = (ts.tv_sec * 1000000) + (ts.tv_nsec / 1000);
            uint64_t curr_ts = hdl->last_frame_ts + hdl->frame_duration;
            if(curr_ts > curr_time) {
                usleep((curr_ts - curr_time));
            }
            hdl->last_frame_ts = curr_time;
        }
        else {
            OSA_PR_INFO("input_push_thread send EOS");
            //this is how mmlib set eos in decoder
#ifdef VXD_DEC_RESOURCE_MANAGER
            vxd_dec_stop_streaming(hdl->dec_hdl, MM_BUF_TYPE_VIDEO_INPUT);
#else
            MM_DEC_StopStreaming(hdl->dec_ch_id, MM_BUF_TYPE_VIDEO_INPUT);
#endif
            break;
        }
    }
    OSA_PR_INFO("input_push_thread has stopped");
    return NULL;
}

static int32_t handle_output_buffers(qvdec_handle_t *hdl)
{
    int v;
    screen_buffer_t screen_buf[OUTPUT_BUFFER_NUM];

    OSA_PR_INFO("Creating screen context");
    if (screen_create_context(&(hdl->screen_ctx), SCREEN_DISPLAY_MANAGER_CONTEXT) != 0) {
        OSA_PR_ERR("Failed to create screen context! Error: %s", strerror(errno));
        return EINVAL;
    }

    if (screen_create_window(&(hdl->screen_win), hdl->screen_ctx) != 0) {
        OSA_PR_ERR("Failed to create screen window! Error: %s", strerror(errno));
        return EINVAL;
    }

    int size[] = { ALIGN(hdl->input_hdl->mWidth, 64), ALIGN(hdl->input_hdl->mHeight, 16) };
    if (screen_set_window_property_iv(hdl->screen_win, SCREEN_PROPERTY_SOURCE_SIZE, size) != 0) {
        OSA_PR_ERR("Failed to set source dimensions for window! Error: %s", strerror(errno));
        return EINVAL;
    }

    if (screen_set_window_property_iv(hdl->screen_win, SCREEN_PROPERTY_BUFFER_SIZE, size) < 0) {
        OSA_PR_ERR("Failed to set SCREEN_PROPERTY_BUFFER_SIZE for window! Error: %s", strerror(errno));
        return EINVAL;
    }

    v = SCREEN_USAGE_READ | SCREEN_USAGE_WRITE | SCREEN_USAGE_NATIVE | SCREEN_USAGE_VIDEO;
    if (screen_set_window_property_iv(hdl->screen_win, SCREEN_PROPERTY_USAGE, &v) < 0) {
        OSA_PR_ERR("Failed to set SCREEN_PROPERTY_USAGE for window! Error: %s", strerror(errno));
        return EINVAL;
    }

    v = fourcc2screenformat(MM_PIX_FMT_NV12);
    if (screen_set_window_property_iv(hdl->screen_win, SCREEN_PROPERTY_FORMAT, &v) < 0) {
        OSA_PR_ERR("Failed to set SCREEN_PROPERTY_FORMAT for window! Error: %s", strerror(errno));
        return EINVAL;
    }

    if (screen_create_window_buffers(hdl->screen_win, hdl->num_out_bufs) < 0) {
        OSA_PR_ERR("Failed to create window buffers for window! Error: %s", strerror(errno));
        return EINVAL;
    }

    if (screen_get_window_property_pv(hdl->screen_win, SCREEN_PROPERTY_RENDER_BUFFERS, (void **)&screen_buf) < 0) {
        OSA_PR_ERR("Failed to get SCREEN_PROPERTY_RENDER_BUFFERS for window! Error: %s", strerror(errno));
        return EINVAL;
    }

    if (screen_get_buffer_property_iv(screen_buf[0], SCREEN_PROPERTY_STRIDE, &hdl->stride) != 0) {
        OSA_PR_ERR("Failed to get SCREEN_PROPERTY_STRIDE! Error: %s", strerror(errno));
        return EINVAL;
    }

    if (screen_get_buffer_property_iv(screen_buf[0], SCREEN_PROPERTY_PLANAR_OFFSETS, hdl->planar_offsets) != 0) {
        OSA_PR_ERR("Failed to get SCREEN_PROPERTY_PLANAR_OFFSETS! Error: %s", strerror(errno));
        return EINVAL;
    }

    for (int i = 0; i < hdl->num_out_bufs; i++) {
        void *pointer;
        int size;
        long long offset;

        if (screen_get_buffer_property_pv(screen_buf[i], SCREEN_PROPERTY_POINTER, &pointer) != EOK) {
            OSA_PR_ERR("Failed to get SCREEN_PROPERTY_POINTER for buf[%d]! Error: %s",i, strerror(errno));
            return EINVAL;
        }

        if (screen_get_buffer_property_llv(screen_buf[i], SCREEN_PROPERTY_PHYSICAL_ADDRESS, &offset) != EOK) {
            OSA_PR_ERR("Failed to get SCREEN_PROPERTY_PHYSICAL_ADDRESS for buf[%d]! Error: %s",i, strerror(errno));
            return EINVAL;
        }

        if (screen_get_buffer_property_iv(screen_buf[i], SCREEN_PROPERTY_SIZE, &size)) {
            OSA_PR_ERR("Failed to get SCREEN_PROPERTY_POINTER for buf[%d]! Error: %s",i, strerror(errno));
            return EINVAL;
        }
#ifndef VXD_DEC_RESOURCE_MANAGER
        hdl->output_bufs[i].chId = hdl->dec_ch_id;
#endif
        hdl->output_bufs[i].type = MM_BUF_TYPE_VIDEO_OUTPUT;
        hdl->output_bufs[i].buf_addr[0] = pointer;
        hdl->output_bufs[i].size[0] = size;
        hdl->output_bufs[i].alloc_size[0] = size;
        hdl->output_bufs[i].num_planes = 1;
        hdl->output_bufs[i].buf_private = screen_buf[i];
        hdl->output_bufs[i].physic_addr[0] = (uintptr_t)offset;
#ifdef VXD_DEC_RESOURCE_MANAGER
        if(0 != vxd_dec_buf_prepare(hdl->dec_hdl, &(hdl->output_bufs[i]))) {
#else
        if(0 != MM_DEC_BufPrepare(&(hdl->output_bufs[i]), hdl->dec_ch_id)) {
#endif
            OSA_PR_ERR("%s: Error returned from MM_DEC_BufPrepare for buf[%d]",__func__,i);
            return EINVAL;
        }
        qfifo_put(hdl->outbuf_q, &hdl->output_bufs[i]);
        OSA_PR_INFO("Get output buffer for buf[%d]: %d, %p",i, size, pointer);
    }

    return EOK;
}

static int32_t handle_input_buffers(qvdec_handle_t *hdl)
{
    int32_t i;
    off64_t  offset;

    hdl->input_buf_size = hdl->input_hdl->mWidth * hdl->input_hdl->mHeight *3 / 2;

    for(i = 0; i < hdl->num_in_bufs; i++) {
#ifndef VXD_DEC_RESOURCE_MANAGER
        hdl->input_bufs[i].chId = hdl->dec_ch_id;
#endif
        hdl->input_bufs[i].type = MM_BUF_TYPE_VIDEO_INPUT;
        hdl->input_bufs[i].num_planes = 1;
        hdl->input_bufs[i].size[0] = hdl->input_buf_size;
        hdl->input_bufs[i].alloc_size[0] = hdl->input_buf_size;
        hdl->input_bufs[i].buf_addr[0] = mmap64(NULL, hdl->input_buf_size,
                PROT_NOCACHE | PROT_READ | PROT_WRITE,
                MAP_ANON | MAP_PHYS | MAP_SHARED | MAP_NOINIT,
                NOFD,
                0);

        if (MAP_FAILED == hdl->input_bufs[i].buf_addr[0]) {
            OSA_PR_ERR("%s: Failed allocated memory for output buffer[%d]", __func__,i);
            goto err_exit;
        }

        if(mem_offset64(hdl->input_bufs[i].buf_addr[0], NOFD, 1, &offset, NULL) == -1) {
            OSA_PR_ERR("%s: Failed allocated memory for input buffer[%d]", __func__,i);
            goto err_exit;
        }
        hdl->input_bufs[i].physic_addr[0] = (uintptr_t)offset;
#ifdef VXD_DEC_RESOURCE_MANAGER
        if(0 != vxd_dec_buf_prepare(hdl->dec_hdl, &(hdl->input_bufs[i]))) {
#else
        if(0 != MM_DEC_BufPrepare(&(hdl->input_bufs[i]), hdl->dec_ch_id)) {
#endif
            OSA_PR_ERR("%s: Error returned from MM_DEC_BufPrepare for buf[%d]",__func__,i);
            goto err_exit;
        }
        qfifo_put(hdl->inbuf_q, &hdl->input_bufs[i]);
        OSA_PR_INFO("Get input buffer for buf[%d]: %p",i, hdl->input_bufs[i].buf_addr[0]);
    }
    return EOK;

err_exit:
    for(i = 0; i < hdl->num_in_bufs; i++) {
        if(hdl->input_bufs[i].buf_addr[0])
            munmap(hdl->input_bufs[i].buf_addr[0], hdl->input_buf_size);
        else
            break;
    }
    hdl->num_in_bufs = 0;
    return ENOMEM;
}

static int32_t init(qvdec_handle_t *hdl)
{
    int ret;
    hdl->num_in_bufs = INPUT_BUFFER_NUM;
    hdl->num_out_bufs = OUTPUT_BUFFER_NUM;

    //create buffer queue for input
    hdl->inbuf_q = qfifo_create(hdl->num_in_bufs, "input");
    if(hdl->inbuf_q == NULL) {
        OSA_PR_ERR("Error: unable to create input queue");
        return ENOMEM;
    }

    //create buffer queue for output
    hdl->outbuf_q = qfifo_create(hdl->num_out_bufs, "output");
    if(hdl->outbuf_q == NULL) {
        OSA_PR_ERR("Error: unable to create output queue");
        return ENOMEM;
    }

    ret = handle_input_buffers(hdl);
    if(ret != EOK) {
        return ret;
    }

    ret = handle_output_buffers(hdl);
    if(ret != EOK) {
        return ret;
    }
#ifdef VXD_DEC_RESOURCE_MANAGER
    vxd_dec_start_streaming(hdl->dec_hdl, MM_BUF_TYPE_VIDEO_INPUT);
    vxd_dec_start_streaming(hdl->dec_hdl, MM_BUF_TYPE_VIDEO_OUTPUT);
#else
    MM_DEC_StartStreaming(hdl->dec_ch_id, MM_BUF_TYPE_VIDEO_INPUT);
    MM_DEC_StartStreaming(hdl->dec_ch_id, MM_BUF_TYPE_VIDEO_OUTPUT);
#endif

    return ret;
}

static void buf_done(void *item, mm_dec_process_cb type, void *ctx)
{
    qvdec_handle_t *hdl = &dec_hdl;
    if(type == MM_CB_STRUNIT_PROCESSED) {
        struct mm_buffer *buf = (struct mm_buffer *)item;
        OSA_PR_INFO("%s:%d return input buffer(%p:%d->%p, %llx)", __func__, __LINE__, buf, buf->size[0],buf->buf_addr[0], buf->physic_addr[0]);
        pthread_mutex_lock(&g_video_decode_mutex);
        qfifo_put(hdl->inbuf_q, buf);
        pthread_cond_signal(&g_video_decode_cond);
        pthread_mutex_unlock(&g_video_decode_mutex);
    }
    else if(type == MM_CB_PICT_DECODED) {
        OSA_PR_INFO("%s:%d frame decoded", __func__, __LINE__);
    }
    else if(type == MM_CB_PICT_DISPLAY) {
        struct mm_buffer *buf = (struct mm_buffer *)item;
        OSA_PR_INFO("%s:%d Post frame with size(%d)", __func__, __LINE__, buf->size[0]);
        //screen_buffer_t screen_buf = (screen_buffer_t)buf->buf_private;
        //if (screen_post_window(hdl->screen_win, screen_buf, 0, NULL, 0) != 0) {
        //    OSA_PR_WARN("%s:%d screen_post_windo error", __func__, __LINE__);
        //}
    }
    else if(type == MM_CB_PICT_RELEASE) {
        struct mm_buffer *buf = (struct mm_buffer *)item;
        OSA_PR_INFO("%s:%d release buf(%p)", __func__, __LINE__, buf);
        pthread_mutex_lock(&g_video_decode_mutex);
        qfifo_put(hdl->outbuf_q, buf);
        pthread_cond_signal(&g_video_decode_cond);
        pthread_mutex_unlock(&g_video_decode_mutex);
    }
    else if(type == MM_CB_STR_END) {
        set_bail(BAIL_BY_OUTPUT_EOS);
        OSA_PR_INFO("%s:%d EOS received", __func__, __LINE__);
    }
    else if(type == MM_CB_ERROR) {
        OSA_PR_ERR("%s:%d Error received", __func__, __LINE__);
        set_bail(BAIL_BY_ERROR);
    }
    else {
        OSA_PR_ERR("%s:%d unknown cb type %d", __func__, __LINE__, type);
    }
}

static void close_dec(qvdec_handle_t *hdl)
{
#ifdef VXD_DEC_RESOURCE_MANAGER
    vxd_dec_stop_streaming(hdl->dec_hdl, MM_BUF_TYPE_VIDEO_INPUT);
    vxd_dec_stop_streaming(hdl->dec_hdl, MM_BUF_TYPE_VIDEO_OUTPUT);
    vxd_dec_close(hdl->dec_hdl);
#else

    MM_DEC_StopStreaming(hdl->dec_ch_id, MM_BUF_TYPE_VIDEO_INPUT);
    MM_DEC_StopStreaming(hdl->dec_ch_id, MM_BUF_TYPE_VIDEO_OUTPUT);
    MM_DEC_Destroy(hdl->dec_ch_id);
    MM_DEC_Deinit();
#endif

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

    if (level <= g_log_lvl ) {
        vslogf(_SLOG_SETCODE(_SLOGC_MEDIA, 2), level, fmt, arglist);
    }
    va_end(arglist);
}

void osa_qnx_dev_logger(int level, const void *dev, const char *fmt, ...)
{
    va_list arglist;
    va_start(arglist, fmt);

    if (level <= g_log_lvl) {
        vslogf(_SLOG_SETCODE(_SLOGC_MEDIA, 2), level, fmt, arglist);
    }
    va_end(arglist);
}

static void print_usage_and_exit(const char *argv0)
{
    printf("Usage: %s [options] \n"
           "  Command line options:\n"
           "    -i: input file\n"
           "    -v: increase verbosity, max 7\n",
           argv0
           );
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        print_usage_and_exit(argv[0]);
    }

    dec_hdl.out_fd = -1;
    dec_hdl.dec_ch_id = -1;

    int opt;
    int log_lvl = 0;
    while ((opt = getopt(argc, argv, "i:v")) != -1) {
        switch (opt) {
        case 'i':
            dec_hdl.in_path = optarg;
        case 'v':
            log_lvl++;
            break;
        default:
            print_usage_and_exit(argv[0]);
        }
    }

    if(log_lvl > 0) {
        g_log_lvl = log_lvl;
    }

    if(dec_hdl.in_path == NULL) {
        print_usage_and_exit(argv[0]);
        return 0;
    }
    printf("Get input %s\n", dec_hdl.in_path);

#ifndef VXD_DEC_RESOURCE_MANAGER
    if (procmgr_ability(0,
                        PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_KEYDATA,
                        PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_IO,
                        PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_MEM_PHYS,
                        PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_PRIORITY,
                        PROCMGR_AOP_DENY  | PROCMGR_ADN_NONROOT | PROCMGR_AOP_LOCK      | PROCMGR_AID_EOL)
        != EOK) {
        OSA_PR_ERR("Unable to gain procmgr abilities for nonroot operation.");
        return -1;
    }

    ThreadCtl( _NTO_TCTL_IO, 0);

    if(MM_DEC_Init() != 0) {
        OSA_PR_ERR("Error: MM_DEC_Init failed");
        goto bail;
    }
#endif

    dec_hdl.input_hdl = createInput(dec_hdl.in_path);
    if(dec_hdl.input_hdl == NULL) {
        OSA_PR_ERR("Error: createInput failed");
        goto bail;
    }
    dec_hdl.frame_duration = 1000000 / dec_hdl.input_hdl->mFrameRate;
    mm_vid_create_params cparams = { .width = dec_hdl.input_hdl->mWidth,
                                     .height = dec_hdl.input_hdl->mHeight,
                                     .in_pixelformat = MM_PIX_FMT_H264,
                                     .out_pixelformat = MM_PIX_FMT_NV12};
    mm_dec_ctrl_params ctrlp = {0};
#ifdef VXD_DEC_RESOURCE_MANAGER
    dec_hdl.dec_hdl = vxd_dec_open();
    if(dec_hdl.dec_hdl == NULL) {
        OSA_PR_ERR("decoder open failed");
        goto bail;
    }
    if(vxd_dec_init(dec_hdl.dec_hdl, &cparams, &ctrlp) != 0) {
        OSA_PR_ERR("Create decoder failed");
        goto bail;
    }
    vxd_dec_register_callback(dec_hdl.dec_hdl,buf_done, &dec_hdl);
#else
    if(MM_DEC_Create(&cparams, &ctrlp, &dec_hdl.dec_ch_id) != 0) {
        OSA_PR_ERR("Create decoder failed");
        goto bail;
    }
    MM_DEC_RegisterCb(buf_done, dec_hdl.dec_ch_id, NULL);
#endif

    if( EOK != init(&dec_hdl) ) {
        OSA_PR_ERR("Init input failed");
        goto bail;
    }

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    pthread_create(&dec_hdl.input_push, &attr, input_push_thread, (void *)&(dec_hdl));
    pthread_attr_destroy(&attr);

    /* Modifying terminal to allow key-press interaction */
    struct termios new_termios;
    struct termios orig_termios;
    tcgetattr(STDIN_FILENO, &orig_termios);
    new_termios = orig_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO | ECHOCTL | ECHONL);
    new_termios.c_cflag |= HUPCL;
    new_termios.c_cc[VMIN] = 0;
    new_termios.c_cc[VTIME] = 10;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);

    printf("Press 'q' to quit.\n");
    for (;;) {
        pthread_mutex_lock(&g_video_decode_mutex);
        bail_e bail = g_bail;
        pthread_mutex_unlock(&g_video_decode_mutex);
        if (bail == BAIL_BY_USER || bail == BAIL_BY_ERROR || bail == BAIL_BY_OUTPUT_EOS) {
            break;
        }
        pthread_mutex_unlock(&g_video_decode_mutex);
        char ch[8];
        int chnum = 0;

        chnum = read(STDIN_FILENO, ch, 8);
        if (chnum == 1) {
            switch (ch[0]) {
                case 'q':
                case 'Q':
                    set_bail(BAIL_BY_USER);
                    goto bail;
                default:
                    printf("Unkown command [%x], valid commands are :\n"
                            "-----------------------------------------\n"
                            " q : stop decoding and quit program.\n"
                            "-----------------------------------------\n",
                            ch[0]);
            }
        }
        else if(chnum == -1) {
            OSA_PR_ERR("Error happened while read from STDIN (%s)", strerror(errno));
            set_bail(BAIL_BY_ERROR);
            goto bail;
        }
        else
            continue;
    }

bail:
    if(dec_hdl.input_hdl != NULL)
        destroyInput(dec_hdl.input_hdl);
    if(dec_hdl.out_fd != -1)
        close(dec_hdl.out_fd);
    if(dec_hdl.inbuf_q)
        qfifo_destroy(dec_hdl.inbuf_q);
    if(dec_hdl.outbuf_q)
        qfifo_destroy(dec_hdl.outbuf_q);
#ifdef VXD_DEC_RESOURCE_MANAGER
    if(dec_hdl.dec_hdl != NULL) {
#else
    if(dec_hdl.dec_ch_id != -1) {
#endif
        close_dec(&dec_hdl);
    }
    if (dec_hdl.screen_win)
        screen_destroy_window(dec_hdl.screen_win);
    if (dec_hdl.screen_ctx)
        screen_destroy_context(dec_hdl.screen_ctx);

    for(int i = 0; i < dec_hdl.num_out_bufs; i++)
        munmap(dec_hdl.output_bufs[i].buf_addr[0], dec_hdl.input_buf_size);

    /* Restore the terminal to its original state */
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
    return 0;
}
