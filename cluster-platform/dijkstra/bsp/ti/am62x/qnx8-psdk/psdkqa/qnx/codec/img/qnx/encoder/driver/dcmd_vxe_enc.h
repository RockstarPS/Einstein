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

/*!
 *  @file       dcmd_vxe_enc.h
 *
 *  @brief      DCMD definitions for vxe device
 */
#ifndef DCMD_VXEENC_H
#define DCMD_VXEENC_H

#include <devctl.h>

#include "mm_enc.h"

#if defined (__cplusplus)
extern "C" {
#endif

#define VXE_ENC_DEVICE_PATH        "/dev/vxe-enc"
#define _DCMD_VXEENC 0x2A

typedef struct VXEENC_CmdArgs_s {
    union {
        struct {
            mm_vid_create_params params;
            mm_enc_ctrl_params   ctrlp;
        } create;
        struct {
            struct mm_buffer buffer;
        } buf_prepare;
        struct {
            mm_buffertype type;
        } start;
        struct {
            mm_buffertype type;
        } stop;
        struct {
            struct mm_buffer in_buf;
            struct mm_buffer out_buf;
        } process;
    } args;
    uint32_t status;
} VXEENC_CmdArgs_t;

typedef struct VXEENC_GetOutBand_s {
    struct mm_buffer  buf;
    mm_enc_process_cb type;
} VXEENC_GetOutBand_t;

typedef struct VXEENC_BufInfo_s{
    uint32_t buf_num;
    uint32_t max_size;
} VXEENC_BufInfo_t;

/*  ----------------------------------------------------------------------------
 * DEVCTL command IDs for mm_enc_create.c
 *  ----------------------------------------------------------------------------
 */
#define DCMD_MM_ENC_CREATE       __DIOTF(_DCMD_VXEENC,\
                                         1,\
                                         VXEENC_CmdArgs_t)

#define DCMD_MM_ENC_BUF_PREPARE  __DIOTF(_DCMD_VXEENC,\
                                         2,\
                                         VXEENC_CmdArgs_t)

#define DCMD_MM_ENC_DESTROY      __DIOTF(_DCMD_VXEENC,\
                                         3,\
                                         VXEENC_CmdArgs_t)

#define DCMD_MM_ENC_START        __DIOTF(_DCMD_VXEENC,\
                                         4,\
                                         VXEENC_CmdArgs_t)

#define DCMD_MM_ENC_STOP         __DIOTF(_DCMD_VXEENC,\
                                         5,\
                                         VXEENC_CmdArgs_t)

#define DCMD_MM_ENC_PROCESS      __DIOTF(_DCMD_VXEENC,\
                                         6,\
                                         VXEENC_CmdArgs_t)

#define DCMD_MM_ENC_BUF_INFO     __DIOTF(_DCMD_VXEENC,\
                                         7,\
                                         VXEENC_BufInfo_t)

#define DCMD_MM_ENC_GETOUTBAND   __DIOTF(_DCMD_VXEENC,\
                                         8,\
                                         VXEENC_GetOutBand_t)

#if defined (__cplusplus)
}
#endif

#endif
