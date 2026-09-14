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
 * VXD DEC Low-level device interface component
 */

#ifndef _VXD_EXT_H
#define _VXD_EXT_H

#define VLR_COMPLETION_COMMS_AREA_SIZE             476

/* Word Size of buffer used to pass messages between LISR and HISR */
#define VXD_SIZE_MSG_BUFFER   (1 * 1024)

/* This structure describes macroblock coordinates. */
struct vxd_mb_coords {
	uint32 x;
	uint32 y;
};

/* This structure contains firmware and decoding pipe state information. */
struct vxd_pipestate {
	uint8 is_pipe_present;
	uint8 cur_codec;
	uint32 acheck_point[VDECFW_CHECKPOINT_MAX];
	uint32 firmware_action;
	uint32 fe_slices;
	uint32 be_slices;
	uint32 fe_errored_slices;
	uint32 be_errored_slices;
	uint32 be_mbs_dropped;
	uint32 be_mbs_recovered;
	struct vxd_mb_coords fe_mb;
	struct vxd_mb_coords be_mb;
};

/* This structure contains firmware and decoder core state information. */
struct vxd_firmware_state {
	uint32 fw_step;
	struct vxd_pipestate pipe_state[VDECFW_MAX_DP];
};

/* This structure contains the video decoder device state. */
struct vxd_states {
	struct vxd_firmware_state fw_state;
};

struct vxd_pict_attrs {
	uint32 dwrfired;
	uint32 mmufault;
	uint32 deverror;
};

/* This type defines the message attributes. */
enum vxd_msg_attr {
	VXD_MSG_ATTR_NONE     = 0,
	VXD_MSG_ATTR_DECODED  = 1,
	VXD_MSG_ATTR_FATAL    = 2,
	VXD_MSG_ATTR_CANCELED = 3,
	VXD_MSG_ATTR_FORCE32BITS = 0x7FFFFFFFU
};

enum vxd_msg_flag {
	VXD_MSG_FLAG_DROP     = 0,
	VXD_MSG_FLAG_EXCL     = 1,
	VXD_MSG_FLAG_FORCE32BITS = 0x7FFFFFFFU
};

#endif /* VXD_EXT_H */
