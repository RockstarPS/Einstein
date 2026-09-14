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
 *  @file       dcmd_vxd_dec.h
 *
 *  @brief      DCMD definitions for vxd device
 */
#ifndef DCMD_VXDDEC_H
#define DCMD_VXDDEC_H

#include <devctl.h>

#include "mm_dec.h"

#if defined (__cplusplus)
extern "C" {
#endif

#define VXD_DEC_DEVICE_PATH        "/dev/vxd-dec"
#define _DCMD_VXDDEC 0x2A

typedef struct VXDDEC_CmdArgs_s {
    union {
        struct {
            mm_vid_create_params params;
            mm_dec_ctrl_params   ctrlp;
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
} VXDDEC_CmdArgs_t;

typedef struct VXDDEC_GetOutBand_s {
    struct mm_buffer  buf;
    mm_dec_process_cb type;
    uint32_t error_flags;
} VXDDEC_GetOutBand_t;

/*  ----------------------------------------------------------------------------
 * DEVCTL command IDs for mm_dec_create.c
 *  ----------------------------------------------------------------------------
 */
#define DCMD_MM_DEC_CREATE       __DIOTF(_DCMD_VXDDEC,\
                                         1,\
                                         VXDDEC_CmdArgs_t)

#define DCMD_MM_DEC_BUF_PREPARE  __DIOTF(_DCMD_VXDDEC,\
                                         2,\
                                         VXDDEC_CmdArgs_t)

#define DCMD_MM_DEC_DESTROY      __DIOTF(_DCMD_VXDDEC,\
                                         3,\
                                         VXDDEC_CmdArgs_t)

#define DCMD_MM_DEC_START        __DIOTF(_DCMD_VXDDEC,\
                                         4,\
                                         VXDDEC_CmdArgs_t)

#define DCMD_MM_DEC_STOP         __DIOTF(_DCMD_VXDDEC,\
                                         5,\
                                         VXDDEC_CmdArgs_t)

#define DCMD_MM_DEC_PROCESS      __DIOTF(_DCMD_VXDDEC,\
                                         6,\
                                         VXDDEC_CmdArgs_t)

#define DCMD_MM_DEC_GETOUTBAND   __DIOTF(_DCMD_VXDDEC,\
                                         8,\
                                         VXDDEC_GetOutBand_t)

#if defined (__cplusplus)
}
#endif

#endif
