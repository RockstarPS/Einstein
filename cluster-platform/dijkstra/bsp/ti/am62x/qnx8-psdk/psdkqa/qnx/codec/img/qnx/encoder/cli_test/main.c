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

/* System libraries */
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <pthread.h>
#include <stdbool.h>
#include <inttypes.h>
#include <sys/mman.h>

#include "vxe_enc-cli.h"

void test_open_close(void)
{
    void *h = vxe_enc_open();
    if(h == NULL) {
        printf("Encoder open failed \n");
    }
    else {
        printf("Encoder open success\n");
        vxe_enc_close(h);
    }
}

static void init_enc_ctrl_params(mm_enc_ctrl_params *ctrl)
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
	ctrl->framerate = 30;
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
}

void test_init(void)
{
    void *h = vxe_enc_open();
    if(h == NULL) {
        printf("Encoder open failed \n");
    }
    else {
        printf("Encoder open success\n");

        mm_vid_create_params cparams = { .width = 1280,
            .height = 736,
            .in_pixelformat = MM_PIX_FMT_NV12,
            .out_pixelformat = MM_PIX_FMT_H264 };
        mm_enc_ctrl_params   ctrlp = {0};
        init_enc_ctrl_params(&ctrlp);
    
        int  ret = vxe_enc_init(h, &cparams, &ctrlp);
        if(ret == EOK) {
            printf("Encoder init success\n");

            ret = vxe_enc_deinit(h);
            if(ret == EOK)
                printf("Encoder deinit success\n");
            else
                printf("Encoder deinit falied (error=%d) \n", ret);
        }
        else
            printf("Encoder init failed(error=%d)\n", ret);

        vxe_enc_close(h);
    }
}

static void callback(struct mm_buffer *buf, mm_enc_process_cb type, void *ctx)
{
    printf("%s:%d type=%d, buf=%p ctx=%p\n", __func__, __LINE__,type,buf,ctx);
}

void test_register_callback(void)
{
    void *h = vxe_enc_open();
    if(h == NULL) {
        printf("Encoder open failed \n");
    }
    else {
        printf("Encoder open success\n");

        mm_vid_create_params cparams = { .width = 1280,
            .height = 736,
            .in_pixelformat = MM_PIX_FMT_NV12,
            .out_pixelformat = MM_PIX_FMT_H264 };
        mm_enc_ctrl_params   ctrlp = {0};
        init_enc_ctrl_params(&ctrlp);
    
        int  ret = vxe_enc_init(h, &cparams, &ctrlp);
        if(ret == EOK) {
            printf("Encoder init success\n");

            printf("Encoder vxe_enc_register_callback\n");

            int ret = vxe_enc_register_callback(h, callback, NULL);
            if(ret == EOK)
                printf("Encoder vxe_enc_register_callback success\n");
            else
                printf("Encoder vxe_enc_register_callback failed(error=%d)\n", ret);

            sleep(1);

            ret = vxe_enc_deinit(h);
            if(ret == EOK)
                printf("Encoder deinit success\n");
            else
                printf("Encoder deinit falied (error=%d) \n", ret);
        }
        else
            printf("Encoder init failed(error=%d)\n", ret);

        vxe_enc_close(h);
    }

}

void test_buffer_prepare(void)
{
    struct mm_buffer output_bufs[3];
    void *h = vxe_enc_open();
    if(h == NULL) {
        printf("Encoder open failed \n");
    }
    else {
        printf("Encoder open success\n");

        mm_vid_create_params cparams = { .width = 1280,
            .height = 736,
            .in_pixelformat = MM_PIX_FMT_NV12,
            .out_pixelformat = MM_PIX_FMT_H264 };
        mm_enc_ctrl_params   ctrlp = {0};
        init_enc_ctrl_params(&ctrlp);
    
        int  ret = vxe_enc_init(h, &cparams, &ctrlp);
        if(ret == EOK) {
            printf("Encoder init success\n");

            printf("Encoder vxe_enc_buf_prepare for input\n");
            int size = 1280*736*3/2;
            off64_t  offset;
            for(int i = 0; i < 8; i++) {
                output_bufs[i].type = MM_BUF_TYPE_VIDEO_INPUT;
                output_bufs[i].num_planes = 1;
                output_bufs[i].size[0] = size;
                output_bufs[i].buf_addr[0] = mmap64(NULL, size,
                        PROT_NOCACHE | PROT_READ | PROT_WRITE,
                        MAP_ANON | MAP_PHYS | MAP_SHARED | MAP_NOINIT,
                        NOFD,
                        0);

                if (MAP_FAILED == output_bufs[i].buf_addr[0]) {
                    printf("%s: Failed allocated memory for output buffer[%d]\n", __func__,i);
                    break;
                }


                if(mem_offset64(output_bufs[i].buf_addr[0], NOFD, 1, &offset, NULL) == -1) {
                    /* Error */
                    printf("%s: Failed get physic address for output buffer[%d]\n", __func__,i);
                }
                else {
                    /* offset contains the physical address of the memory
                       mapped at addr. */
                    output_bufs[i].physic_addr[0] = (uintptr_t)offset;
                    printf("%s: Get physic address for output buffer[%d] %ld\n", __func__,i,output_bufs[i].physic_addr[0]);
                }

                int ret = vxe_enc_buf_prepare(h, &(output_bufs[i]));
                if(ret == EOK)
                    printf("Encoder vxe_enc_register_callback success\n");
                else
                    printf("Encoder vxe_enc_register_callback failed(error=%d)\n", ret);
            }

            sleep(1);

            ret = vxe_enc_deinit(h);
            if(ret == EOK)
                printf("Encoder deinit success\n");
            else
                printf("Encoder deinit falied (error=%d) \n", ret);
        }
        else
            printf("Encoder init failed(error=%d)\n", ret);

        vxe_enc_close(h);
    }

}

void test_buffer_info(void)
{
    void *h = vxe_enc_open();
    if(h == NULL) {
        printf("Encoder open failed \n");
    }
    else {
        printf("Encoder open success\n");

        mm_vid_create_params cparams = { .width = 1280,
            .height = 736,
            .in_pixelformat = MM_PIX_FMT_NV12,
            .out_pixelformat = MM_PIX_FMT_H264 };
        mm_enc_ctrl_params   ctrlp = {0};
        init_enc_ctrl_params(&ctrlp);
    
        int  ret = vxe_enc_init(h, &cparams, &ctrlp);
        if(ret == EOK) {
            printf("Encoder init success\n");

            printf("Encoder vxe_enc_register_callback\n");

            uint32_t nbuf, nsize;
            int ret = vxe_enc_get_buf_info(h, &nbuf, &nsize);
            if(ret == EOK)
                printf("Encoder vxe_enc_get_buf_info success(%u, %u)\n", nbuf, nsize);
            else
                printf("Encoder vxe_enc_register_callback failed(error=%d)\n", ret);


            ret = vxe_enc_deinit(h);
            if(ret == EOK)
                printf("Encoder deinit success\n");
            else
                printf("Encoder deinit falied (error=%d) \n", ret);
        }
        else
            printf("Encoder init failed(error=%d)\n", ret);

        vxe_enc_close(h);
    }

}

void test_start_stop(void)
{
    void *h = vxe_enc_open();
    if(h == NULL) {
        printf("Encoder open failed \n");
    }
    else {
        printf("Encoder open success\n");

        mm_vid_create_params cparams = { .width = 1280,
            .height = 736,
            .in_pixelformat = MM_PIX_FMT_NV12,
            .out_pixelformat = MM_PIX_FMT_H264 };
        mm_enc_ctrl_params   ctrlp = {0};
        init_enc_ctrl_params(&ctrlp);
    
        int  ret = vxe_enc_init(h, &cparams, &ctrlp);
        if(ret == EOK) {
            printf("Encoder init success\n");

            ret = vxe_enc_start_streaming(h, MM_BUF_TYPE_VIDEO_INPUT);
            if(ret == EOK)
                printf("Encoder vxe_enc_start_streaming input success \n");
            else
                printf("Encoder vxe_enc_start_streaming input failed(error=%d)\n", ret);


            ret = vxe_enc_start_streaming(h, MM_BUF_TYPE_VIDEO_OUTPUT);
            if(ret == EOK)
                printf("Encoder vxe_enc_start_streaming output success \n");
            else
                printf("Encoder vxe_enc_start_streaming output failed(error=%d)\n", ret);


            ret = vxe_enc_stop_streaming(h, MM_BUF_TYPE_VIDEO_INPUT);
            if(ret == EOK)
                printf("Encoder vxe_enc_stop_streaming input success \n");
            else
                printf("Encoder vxe_enc_stop_streaming input failed(error=%d)\n", ret);


            ret = vxe_enc_stop_streaming(h, MM_BUF_TYPE_VIDEO_OUTPUT);
            if(ret == EOK)
                printf("Encoder vxe_enc_stop_streaming output success \n");
            else
                printf("Encoder vxe_enc_stop_streaming output failed(error=%d)\n", ret);

            ret = vxe_enc_deinit(h);
            if(ret == EOK)
                printf("Encoder deinit success\n");
            else
                printf("Encoder deinit falied (error=%d) \n", ret);
        }
        else
            printf("Encoder init failed(error=%d)\n", ret);

        vxe_enc_close(h);
    }

}



int main(int argc, char **argv)
{
    test_open_close();
    test_init();
    test_register_callback();
    test_buffer_prepare();
    test_buffer_info();
    test_start_stop();

    return 0;
}
