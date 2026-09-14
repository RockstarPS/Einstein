/*****************************************************************************
*
* Copyright (c) Imagination Technologies Ltd.
* Copyright (c) 2018-22 Texas Instruments Incorporated - http://www.ti.com/
*
* The contents of this file are subject to the MIT license as set out below.
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHERa
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
* Alternatively, the contents of this file may be used under the terms of the
* GNU General Public License Version 2 ("GPL")in which case the provisions of
* GPL are applicable instead of those above.
*
* If you wish to allow use of your version of this file only under the terms
* of GPL, and not to allow others to use your version of this file under the
* terms of the MIT license, indicate your decision by deleting the provisions
* above and replace them with the notice and other provisions required by GPL
* as set out in the file called "GPLHEADER" included in this distribution. If
* you do not delete the provisions above, a recipient may use your version of
* this file under the terms of either the MIT license or GPL.
*
* This License is also included in this distribution in the file called
* "MIT_COPYING".
*
*****************************************************************************/
/*
 * VXD DEC Hardware control implementation
 */

#ifndef _HW_CONTROL_H
#define _HW_CONTROL_H

#include "bspp.h"
#include "decoder.h"
#include "fw_interface.h"
#include "img_dec_common.h"
#include "img_errors.h"
#include "lst.h"
#include "mem_io.h"
#include "vdecdd_defs.h"
#include "vdecfw_shared.h"
#include "vid_buf.h"
#include "vxd_ext.h"
#include "vxd_props.h"

/* Size of additional buffers needed for each HEVC picture */
#ifdef HAS_HEVC

/* Empirically defined */
#define MEM_TO_REG_BUF_SIZE 0x2000

/*
 * Max. no. of slices found in stream db: approx. 2200,
 * set MAX_SLICES to 2368 to get buffer size page aligned
 */
#define MAX_SLICES 2368
#define SLICE_PARAMS_SIZE 64
#define SLICE_PARAMS_BUF_SIZE (MAX_SLICES * SLICE_PARAMS_SIZE)

/*
 * Size of buffer for "above params" structure, sufficient for stream of width 8192
 * 192 * (8192/64) == 0x6000, see "above_param_size" in TRM
 */
#define ABOVE_PARAMS_BUF_SIZE 0x6000
#endif

enum hwctrl_msgid {
	HWCTRL_MSGID_BATCH = 0,
	HWCTRL_MSGID_FRAGMENT = 1,
	CORE_MSGID_MAX,
	CORE_MSGID_FORCE32BITS = 0x7FFFFFFFU
};

struct hwctrl_to_kernel_msg {
	uint32 msg_size;
	uint32 km_str_id;
	uint32 flags;
	uint8 *msg_hdr;
};

struct hwctrl_batch_msgdata {
	struct vidio_ddbufinfo *batchmsg_bufinfo;
	struct vidio_ddbufinfo *pvdec_fwctx;
	uint32 ctrl_alloc_bytes;
	uint32 operating_mode;
	uint32 transaction_id;
	uint32 tile_cfg;
	uint32 genc_id;
	uint32 mb_load;
	uint32 size_delimited_mode;
};

struct hwctrl_fragment_msgdata {
	struct vidio_ddbufinfo *batchmsg_bufinfo;
	uint32 ctrl_alloc_offset;
	uint32 ctrl_alloc_bytes;
};

struct hwctrl_msgdata {
	uint32 km_str_id;
	struct hwctrl_batch_msgdata batch_msgdata;
	struct hwctrl_fragment_msgdata fragment_msgdata;
};

/*
 * This structure contains MSVDX Message information.
 */
struct hwctrl_msgstatus {
	uint8 control_fence_id[VDECFW_MSGID_CONTROL_TYPES];
	uint8 decode_fence_id[VDECFW_MSGID_DECODE_TYPES];
	uint8 completion_fence_id[VDECFW_MSGID_COMPLETION_TYPES];
};

/*
 * this structure contains the HWCTRL Core state.
 */
struct hwctrl_state {
	struct vxd_states core_state;
	struct hwctrl_msgstatus fwmsg_status;
	struct hwctrl_msgstatus hostmsg_status;
};

int32 hwctrl_picture_submit_fragment(void *hndl_hwctx,
				   struct dec_pict_fragment  *pict_fragment,
				   struct dec_decpict *decpict,
				   void *vxd_dec_ctx);

int32 hwctrl_process_msg(void *hndl_hwct, uint32 msg_flags, uint32 *msg,
		       struct dec_decpict **decpict);

int32 hwctrl_getcore_cached_status(void *hndl_hwctx, struct hwctrl_state *state);

int32 hwctrl_get_core_status(void *hndl_hwctx, struct hwctrl_state *state);

int32 hwctrl_is_on_seq_replay(void *hndl_hwctx);

int32 hwctrl_picture_submitbatch(void *hndl_hwctx, struct dec_decpict  *decpict,
			       void *vxd_dec_ctx);

int32 hwctrl_getpicpend_pictlist(void *hndl_hwctx, uint32 transaction_id,
			       struct dec_decpict  **decpict);

int32 hwctrl_peekheadpiclist(void *hndl_hwctx, struct dec_decpict **decpict);

int32 hwctrl_getdecodedpicture(void *hndl_hwctx, struct dec_decpict **decpict);

void hwctrl_removefrom_piclist(void *hndl_hwctx, struct dec_decpict  *decpict);

int32 hwctrl_getregsoffset(void *hndl_hwctx,
			 struct decoder_regsoffsets *regs_offsets);

int32 hwctrl_initialise(void *dec_core, void *comp_int_userdata,
		      const struct vdecdd_dd_devconfig  *dd_devconfig,
		      struct vxd_coreprops *core_props, void **hndl_hwctx);

int32 hwctrl_deinitialise(void *hndl_hwctx);

#endif /* _HW_CONTROL_H */
