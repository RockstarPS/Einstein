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
#include "mm_enc.h"

#define INPUT_BUFFER_NUM 8
#define OUTPUT_BUFFER_NUM 8

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
pthread_mutex_t g_video_encode_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t g_video_encode_cond = PTHREAD_COND_INITIALIZER;

typedef struct mm_buffer mm_buffer_t;
typedef int32_t (*f_read_frame)(void *handle, mm_buffer_t *buffer);

typedef struct {
    const char *name;
    uint16_t read_index;
    uint16_t write_index;
    uint16_t max_index;
    void** item;
} qfifo_t;

typedef struct qvenc_handle_s {
    uint32_t enc_ch_id;

    const char *in_path;
    const char *out_path;
    int      in_fd;
    int      out_fd;
    uint32_t rsize;
    int32_t stride;
    uint32_t num_in_bufs;
    uint32_t num_out_bufs;
    uint32_t output_buf_size;
    int planar_offsets[3];

    screen_context_t screen_ctx;
    screen_window_t screen_win;
    uint32_t         width;
    uint32_t         height;
    uint32_t         frame_rate;
    uint32_t         input_format;

    pthread_t encoder_push;

    qfifo_t          *inbuf_q;
    qfifo_t          *outbuf_q;
    mm_buffer_t      input_bufs[INPUT_BUFFER_NUM];
    mm_buffer_t      output_bufs[OUTPUT_BUFFER_NUM];

    f_read_frame     read_frame;
} qvenc_handle_t;
qvenc_handle_t enc_hdl = { 0 };

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
    pthread_mutex_lock(&g_video_encode_mutex);
    g_bail = reason;
    pthread_cond_signal(&g_video_encode_cond);
    pthread_mutex_unlock(&g_video_encode_mutex);
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

static mm_buffer_t *get_frame(qvenc_handle_t *hdl)
{
    pthread_mutex_lock(&g_video_encode_mutex);
    mm_buffer_t *buffer = (mm_buffer_t *)qfifo_get(hdl->inbuf_q);
    pthread_mutex_unlock(&g_video_encode_mutex);
    if(buffer != NULL) {
        hdl->read_frame(hdl, buffer);
    }
    return buffer;
}

//main loop to feed input and handle output.
static void *encoder_push_thread(void *args)
{
    pthread_setname_np(pthread_self(), "encoder_push_thread");
    OSA_PR_INFO("encoder_push_thread has started");

    qvenc_handle_t *hdl = (qvenc_handle_t *)args;

    for (;;) {
        pthread_mutex_lock(&g_video_encode_mutex);
        bail_e bail = g_bail;
        pthread_mutex_unlock(&g_video_encode_mutex);
        if (bail == BAIL_BY_INPUT_EOS || bail == BAIL_BY_OUTPUT_EOS  || bail == BAIL_BY_ERROR || bail == BAIL_BY_USER) {
            break;
        }

        mm_buffer_t *ibuffer = get_frame(hdl);
        pthread_mutex_lock(&g_video_encode_mutex);
        if(ibuffer == NULL) {
        	OSA_PR_DEBUG("encoder_push_thread wait for input");
            pthread_cond_wait(&g_video_encode_cond, &g_video_encode_mutex);
            pthread_mutex_unlock(&g_video_encode_mutex);
            continue;
        }

        mm_buffer_t *obuffer = NULL;
        do {
        	obuffer = (mm_buffer_t *)qfifo_get(hdl->outbuf_q);
        	if(obuffer == NULL) {
        		OSA_PR_DEBUG("encoder_push_thread wait for output");
        		pthread_cond_wait(&g_video_encode_cond, &g_video_encode_mutex);

        		bail = g_bail;
        		if (bail == BAIL_BY_INPUT_EOS || bail == BAIL_BY_OUTPUT_EOS  || bail == BAIL_BY_ERROR || bail == BAIL_BY_USER)
        			break;
        	}
        	else
        		break;
        }
        while(1);
        pthread_mutex_unlock(&g_video_encode_mutex);

        OSA_PR_INFO("encoder_push_thread send input(%p:%d), output(%p)", ibuffer, ibuffer ? ibuffer->size[0] : 0, obuffer);
        if(ibuffer->size[0] > 0) {
            if(0 != MM_ENC_Process(ibuffer, obuffer, NULL, hdl->enc_ch_id)) {
                set_bail(BAIL_BY_ERROR);
                OSA_PR_ERR("encoder_push_thread encode error");
                break;
            }
        }
        else {
            OSA_PR_INFO("encoder_push_thread send EOS");
            //this is how mmlib set eos in encoder
            MM_ENC_StopStreaming(hdl->enc_ch_id, MM_BUF_TYPE_VIDEO_INPUT);
            break;
        }
    }
    OSA_PR_INFO("encoder_push_thread has stopped");
    return NULL;
}

static int32_t read_nv12_frame(void *handle, mm_buffer_t *buffer)
{
    qvenc_handle_t *hdl = (qvenc_handle_t *)handle;
    int dsize = 0;
    int h, r;
    uint8_t *buf = (uint8_t *)buffer->buf_addr[0] + hdl->planar_offsets[0];
    // luma
    for( h = 0; h < hdl->height; h++ ) {
        r = read(hdl->in_fd, buf, hdl->rsize);
        if( r != hdl->rsize ) {
            OSA_PR_INFO("End of file");
            buffer->size[0] = 0;
            return 0;
        }
        buf += hdl->stride;
        dsize += hdl->stride;
    }
    // chroma
    buf = (uint8_t *)buffer->buf_addr[0] + hdl->planar_offsets[1];
    for( h = 0; h < hdl->height / 2; h++ ) {
        r = read(hdl->in_fd, buf, hdl->rsize);
        if( r != hdl->rsize ) {
            OSA_PR_INFO("End of file");
            buffer->size[0] = 0;
            return 0;
        }
        buf += hdl->stride;
        dsize += hdl->stride;
    }
    buffer->size[0] = dsize;
    return dsize;
}

static int32_t read_argb_frame(void *handle, mm_buffer_t *buffer)
{
    qvenc_handle_t *hdl = (qvenc_handle_t *)handle;
    void *buf = buffer->buf_addr[0];
    int dsize = 0;
    int rsize = hdl->rsize * hdl->height;
    int r;

    r = read(hdl->in_fd, buf, rsize);
    if(r != rsize) {
        OSA_PR_INFO("End of file");
        dsize = 0;
    }
    else {
        dsize = hdl->rsize * hdl->height;
    }

    buffer->size[0] = dsize;
    return dsize;
}

static int32_t handle_input_buffers(qvenc_handle_t *hdl)
{
    int v;
    screen_buffer_t screen_buf[INPUT_BUFFER_NUM];

    OSA_PR_INFO("Creating screen context");
    if (screen_create_context(&(hdl->screen_ctx), SCREEN_DISPLAY_MANAGER_CONTEXT) != 0) {
        OSA_PR_ERR("Failed to create screen context! Error: %s", strerror(errno));
        return EINVAL;
    }

    if (screen_create_window(&(hdl->screen_win), hdl->screen_ctx) != 0) {
        OSA_PR_ERR("Failed to create screen window! Error: %s", strerror(errno));
        return EINVAL;
    }

    int size[] = { ALIGN(hdl->width, 64), ALIGN(hdl->height, 16) };
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

    v = fourcc2screenformat(hdl->input_format);
    if (screen_set_window_property_iv(hdl->screen_win, SCREEN_PROPERTY_FORMAT, &v) < 0) {
        OSA_PR_ERR("Failed to set SCREEN_PROPERTY_FORMAT for window! Error: %s", strerror(errno));
        return EINVAL;
    }

    if (screen_create_window_buffers(hdl->screen_win, hdl->num_in_bufs) < 0) {
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

    for (int i = 0; i < hdl->num_in_bufs; i++) {
        void *pointer;
        int size;

        if (screen_get_buffer_property_pv(screen_buf[i], SCREEN_PROPERTY_POINTER, &pointer) != EOK) {
            OSA_PR_ERR("Failed to get SCREEN_PROPERTY_POINTER for buf[%d]! Error: %s",i, strerror(errno));
            return EINVAL;
        }
        if (screen_get_buffer_property_iv(screen_buf[i], SCREEN_PROPERTY_SIZE, &size)) {
            OSA_PR_ERR("Failed to get SCREEN_PROPERTY_POINTER for buf[%d]! Error: %s",i, strerror(errno));
            return EINVAL;
        }
        hdl->input_bufs[i].chId = hdl->enc_ch_id;
        hdl->input_bufs[i].type = MM_BUF_TYPE_VIDEO_INPUT;
        hdl->input_bufs[i].buf_addr[0] = pointer;
        hdl->input_bufs[i].size[0] = size;
        hdl->input_bufs[i].num_planes = 1; //TODO set UV buffer
        if(0 != MM_ENC_BufPrepare(&(hdl->input_bufs[i]), hdl->enc_ch_id)) {
            OSA_PR_ERR("%s: Error returned from MM_ENC_BufPrepare for buf[%d]",__func__,i);
            return EINVAL;
        }
        qfifo_put(hdl->inbuf_q, &hdl->input_bufs[i]);
        OSA_PR_INFO("Get input buffer for buf[%d]: %d, %p",i, size, pointer);
    }

    return EOK;
}

static int32_t handle_output_buffers(qvenc_handle_t *hdl)
{
    int32_t i;
    uint32_t num_bufs;

    if(MM_ENC_QueryBufInfo(hdl->enc_ch_id, &num_bufs, &hdl->output_buf_size) != 0) {
    	OSA_PR_ERR("%s: MM_ENC_QueryBufInfo returns error", __func__);
    	return EINVAL;
    }
//    if(num_bufs < OUTPUT_BUFFER_NUM) {
//        OSA_PR_INFO("Get output buffer number(%d) ", num_bufs);
//        hdl->num_out_bufs = num_bufs;
//    }
//    else {
        OSA_PR_INFO("Set output buffer number to default(%d)(%d) ", OUTPUT_BUFFER_NUM, num_bufs);
    	hdl->num_out_bufs = OUTPUT_BUFFER_NUM;
//    }

    for(i = 0; i < hdl->num_out_bufs; i++) {
        hdl->output_bufs[i].chId = hdl->enc_ch_id;
        hdl->output_bufs[i].type = MM_BUF_TYPE_VIDEO_OUTPUT;
        hdl->output_bufs[i].num_planes = 1;
        hdl->output_bufs[i].size[0] = hdl->output_buf_size;
        hdl->output_bufs[i].buf_addr[0] = mmap64(NULL, hdl->output_buf_size,
                PROT_NOCACHE | PROT_READ | PROT_WRITE,
                MAP_ANON | MAP_PHYS | MAP_SHARED | MAP_NOINIT,
                NOFD,
                0);

        if (MAP_FAILED == hdl->output_bufs[i].buf_addr[0]) {
            OSA_PR_ERR("%s: Failed allocated memory for output buffer[%d]", __func__,i);
            goto err_exit;
        }

        if(0 != MM_ENC_BufPrepare(&(hdl->output_bufs[i]), hdl->enc_ch_id)) {
            OSA_PR_ERR("%s: Error returned from MM_ENC_BufPrepare for buf[%d]",__func__,i);
            goto err_exit;
        }
        qfifo_put(hdl->outbuf_q, &hdl->output_bufs[i]);
        OSA_PR_INFO("Get output buffer for buf[%d]: %p",i, hdl->output_bufs[i].buf_addr[0]);
    }
    return EOK;

err_exit:
    for(i = 0; i < hdl->num_out_bufs; i++) {
        if(hdl->output_bufs[i].buf_addr[0])
            munmap(hdl->output_bufs[i].buf_addr[0], hdl->output_buf_size);
        else
            break;
    }
    hdl->num_out_bufs = 0;
    return ENOMEM;
}

static int32_t init(qvenc_handle_t *hdl)
{
    int ret;
    hdl->num_in_bufs = INPUT_BUFFER_NUM;
    hdl->num_out_bufs = OUTPUT_BUFFER_NUM;

    //Open input file
    hdl->in_fd = open(hdl->in_path, O_RDONLY);
    if(hdl->in_fd == -1) {
        OSA_PR_ERR("Error: unable to open input file (%s)", hdl->in_path);
        return EIO;
    }

    //Open input file
    hdl->out_fd = open(hdl->out_path, O_WRONLY | O_CREAT);
    if(hdl->out_fd == -1) {
        OSA_PR_ERR("Error: unable to open output file (%s)", hdl->out_path);
        return EIO;
    }

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

    if(hdl->input_format == MM_PIX_FMT_NV12) {
        hdl->rsize = hdl->width;
        hdl->read_frame = read_nv12_frame;
    }
    else if(hdl->input_format == MM_PIX_FMT_FORCE32BITS) {
        hdl->rsize = hdl->width * 4;
        hdl->read_frame = read_argb_frame;
    }
    else {
        OSA_PR_ERR("(%s:%d) Error: unsupported input format(%x)", __func__, __LINE__, hdl->input_format);
        return EINVAL;
    }

    ret = handle_input_buffers(hdl);
    if(ret != EOK) {
        return ret;
    }

    ret = handle_output_buffers(hdl);
    if(ret != EOK) {
        return ret;
    }

    MM_ENC_StartStreaming(hdl->enc_ch_id, MM_BUF_TYPE_VIDEO_INPUT);
    MM_ENC_StartStreaming(hdl->enc_ch_id, MM_BUF_TYPE_VIDEO_OUTPUT);
    return EOK;
}

static int32_t parse_input_format(const char *sformat, qvenc_handle_t* hdl)
{
    int n;
    int ret = EOK;

    char *res = strchr(sformat, ',');
    if(res == NULL) {
        OSA_PR_ERR("%s:%d failed to parse input format(%s)", __func__, __LINE__, sformat);
        return EINVAL;
    }

    n = res - sformat;
    if(n != 4) {
        OSA_PR_ERR("%s:%d failed to parse input format(%s)", __func__, __LINE__, sformat);
        return EINVAL;
    }

    if (sscanf(res + 1, "%ux%u@%u", &hdl->width, &hdl->height,
                &hdl->frame_rate) != 3) {
        OSA_PR_ERR("%s:%d failed to parse input format(%s)", __func__, __LINE__, sformat);
        return EINVAL;
    }

    if(hdl->width == 0 || hdl->height == 0 || hdl->frame_rate ==0) {
        OSA_PR_ERR("%s:%d Invalid input format", __func__, __LINE__);
        return EINVAL;
    }

    if (!strncasecmp(sformat, "nv12", n)) {
        hdl->input_format = MM_PIX_FMT_NV12;
    }
    else if (!strncasecmp(sformat, "argb", n)) {
        hdl->input_format = MM_PIX_FMT_FORCE32BITS;
    }
    else {
        ret = EINVAL;
    }

    return ret;
}

static void buf_done(struct mm_buffer *buf, mm_enc_process_cb type, void *ctx)
{
    qvenc_handle_t *hdl = &enc_hdl;
    if(type == MM_CB_SRC_FRAME_RELEASE) {
        pthread_mutex_lock(&g_video_encode_mutex);
        qfifo_put(hdl->inbuf_q, buf);
        pthread_cond_signal(&g_video_encode_cond);
        pthread_mutex_unlock(&g_video_encode_mutex);
    }
    else if(type == MM_CB_CODED_BUFF_READY) {
        OSA_PR_INFO("Write frame with size(%d)", buf->size[0]);
        size_t w = write(hdl->out_fd, buf->buf_addr[0], buf->size[0]);
        if(w != buf->size[0]) {
            OSA_PR_ERR("Error to write frame (%d)", buf->size[0]);
            set_bail(BAIL_BY_ERROR);
        }
        pthread_mutex_lock(&g_video_encode_mutex);
        qfifo_put(hdl->outbuf_q, buf);
        pthread_cond_signal(&g_video_encode_cond);
        pthread_mutex_unlock(&g_video_encode_mutex);
    }
    else if(type == MM_CB_ENC_STR_END) {
        set_bail(BAIL_BY_OUTPUT_EOS);
        OSA_PR_INFO("%s:%d EOS received", __func__, __LINE__);
    }
    else if(type == MM_CB_ENC_ERROR_FATAL) {
        OSA_PR_ERR("%s:%d Error received", __func__, __LINE__);
        set_bail(BAIL_BY_ERROR);
    }
    else {
        OSA_PR_ERR("%s:%d unknown cb type %d", __func__, __LINE__, type);
    }
}

static void close_enc(qvenc_handle_t *hdl)
{
    MM_ENC_StopStreaming(hdl->enc_ch_id, MM_BUF_TYPE_VIDEO_INPUT);
    MM_ENC_StopStreaming(hdl->enc_ch_id, MM_BUF_TYPE_VIDEO_OUTPUT);
    MM_ENC_Destroy(hdl->enc_ch_id);
    MM_ENC_Deinit();
}

static void init_enc_ctrl_params(qvenc_handle_t *hdl, mm_enc_ctrl_params *ctrl)
{
	/** Bit flags for encoding features */
	ctrl->features = MM_ENC_FEATURE_CABAC ;
	/** RC Mode */
	ctrl->rcmode = MM_ENC_VBR;
	/** IDR-period */
	ctrl->idr_period = 1800; /* 60 * 30fps */
	/** I-period */
	ctrl->i_period = 30;
	/** Bitrate */
	ctrl->bitrate = 20000000;
	/** Framerate */
	ctrl->framerate = hdl->frame_rate;
	/** Crop settings */
//	ctrl->crop_left = 0;
	//ctrl->crop_right = hdl->width;
	//ctrl->crop_top = 0;
	ctrl->crop_bottom = ALIGN(hdl->height, 16) - hdl->height;
	/** # Slices */
	ctrl->nslices = 1;
	/** base pipe */
	ctrl->base_pipe = 1;
	/** Qp Settings */
	ctrl->min_qp = 0;
	ctrl->max_qp = 0;
	/** Min Block Size for motion search */
	ctrl->min_blk_size = MM_ENC_BLK_SZ_DEFAULT;
	/** Controls H264COMP_INTRA_PRED_MODES register. Leave 0 for default. See TRM for details */
	//ctrl->intra_pred_modes = 0x3ffff;// leave at default for now.
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

    if (level <= g_log_lvl ) {
        vslogf(_SLOG_SETCODE(_SLOGC_MEDIA, 2), level, fmt, arglist);
    }
    va_end(arglist);
}


static void print_usage_and_exit(const char *argv0)
{
    printf("Usage: %s [options] \n"
           "  Command line options:\n"
           "    -v: increase verbosity, max 7\n"
           "    -i: input file\n"
           "    -o: output file\n"
           "    -f input format for raw input (.yuv/.rgba/etc.)\n"
           "       e.g.: nv12,1920x1080@30\n"
           "             nv12 is the input color format\n"
           "             1920x1080 is resolution(width x height)\n"
           "             30 is frame rate.\n"
           "  Supported input format: nv12, argb.\n",
           argv0
           );
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    if (argc < 4) {
        print_usage_and_exit(argv[0]);
    }

    enc_hdl.in_fd = -1;
    enc_hdl.out_fd = -1;

    int opt;
    int log_lvl = 0;
    while ((opt = getopt(argc, argv, "vi:o:f:")) != -1) {
        switch (opt) {
        case 'v':
            log_lvl++;
            break;
        case 'i':
            enc_hdl.in_path = optarg;
            OSA_PR_INFO("set input file %s", enc_hdl.in_path);
            break;
        case 'o':
            enc_hdl.out_path = optarg;
            OSA_PR_INFO("set output file %s", enc_hdl.out_path);
            break;
        case 'f':
            if(parse_input_format(optarg, &enc_hdl) != EOK) {
                print_usage_and_exit(argv[0]);
            }
            break;
        default:
            print_usage_and_exit(argv[0]);
        }
    }
    if(log_lvl > 0) {
        g_log_lvl = log_lvl;
    }

    if(enc_hdl.in_path == NULL || enc_hdl.out_path == NULL) {
        print_usage_and_exit(argv[0]);
        return 0;
    }

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

    mm_enc_init_params init_params = {0};
    MM_ENC_SetDefaultInitParams(&init_params);
    if(MM_ENC_Init(&init_params) != 0) {
        OSA_PR_ERR("Error: MM_ENC_Init failed");
        goto bail;
    }

    mm_vid_create_params cparams = { .width = enc_hdl.width,
                                     .height = ALIGN(enc_hdl.height, 16),
                                     .in_pixelformat = enc_hdl.input_format,
                                     .out_pixelformat = MM_PIX_FMT_H264 };
    mm_enc_ctrl_params   ctrlp = {0};
    init_enc_ctrl_params(&enc_hdl, &ctrlp);
    if(MM_ENC_Create(&cparams, &ctrlp, &enc_hdl.enc_ch_id) != 0) {
        OSA_PR_ERR("Create encoder failed");
        goto bail;
    }
    MM_ENC_RegisterCb(buf_done, enc_hdl.enc_ch_id, (void *)&enc_hdl);

    if( EOK != init(&enc_hdl) ) {
        OSA_PR_ERR("Init input failed");
        goto bail;
    }

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    pthread_create(&enc_hdl.encoder_push, &attr, encoder_push_thread, (void *)&(enc_hdl));
    pthread_attr_destroy(&attr);

    /* Modifying terminal to allow key-press interaction */
    struct termios new_termios;
    struct termios orig_termios;
    tcgetattr(STDIN_FILENO, &orig_termios);
    new_termios = orig_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO | ECHOCTL | ECHONL);
    new_termios.c_cflag |= HUPCL;
    new_termios.c_cc[VMIN] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);

    printf("Press 'q' to quit.\n");
    for (;;) {
        pthread_mutex_lock(&g_video_encode_mutex);
        bail_e bail = g_bail;
        pthread_mutex_unlock(&g_video_encode_mutex);
        if (bail == BAIL_BY_USER || bail == BAIL_BY_ERROR || bail == BAIL_BY_OUTPUT_EOS) {
            break;
        }
        pthread_mutex_unlock(&g_video_encode_mutex);
        int ch[8];
        int chnum = 0;

        fd_set rdfds;
        FD_ZERO(&rdfds);
        FD_SET(0, &rdfds);

        struct timeval tv = {.tv_sec = 0, .tv_usec = 250000 };
        int ret = select(1, &rdfds, NULL, NULL, &tv);
        if (-1 == ret) {
            break;
        }
        if (0 == ret) {
            continue;
        }
        while (chnum < 8 && (ch[chnum] = getchar()) != EOF) {
            chnum++;
        }
        if (chnum > 1) {
            ch[0] = ch[chnum - 1] | (ch[chnum - 2] << 8);
        }

        if (ch[chnum] == EOF && chnum == 0) {
            clearerr(stdin);
            continue;
        }

        switch (ch[0]) {
        case 'q':
            set_bail(BAIL_BY_USER);
            goto bail;
        default:
            printf("Unkown command [%x], valid commands are :\n"
                   "-----------------------------------------\n"
                   " q : stop encoding and quit program.\n"
                   "-----------------------------------------\n",
                   ch[0]);
        }
    }

bail:
    if(enc_hdl.in_fd != -1)
        close(enc_hdl.in_fd);
    if(enc_hdl.out_fd != -1)
        close(enc_hdl.out_fd);
    if(enc_hdl.inbuf_q)
        qfifo_destroy(enc_hdl.inbuf_q);
    if(enc_hdl.outbuf_q)
        qfifo_destroy(enc_hdl.outbuf_q);
    if(enc_hdl.enc_ch_id != -1) {
        close_enc(&enc_hdl);
    }
    if (enc_hdl.screen_win)
        screen_destroy_window(enc_hdl.screen_win);
    if (enc_hdl.screen_ctx)
        screen_destroy_context(enc_hdl.screen_ctx);

    for(int i = 0; i < enc_hdl.num_out_bufs; i++)
        munmap(enc_hdl.output_bufs[i].buf_addr[0], enc_hdl.output_buf_size);

    /* Restore the terminal to its original state */
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
    return 0;
}
