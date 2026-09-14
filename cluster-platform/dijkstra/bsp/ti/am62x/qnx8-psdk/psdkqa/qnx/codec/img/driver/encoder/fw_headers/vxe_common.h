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
 * firmware header
 */

#ifndef _VXECOMMON_H_
#define _VXECOMMON_H_

#include "topazscfwif.h"
#include "../common/vid_buf.h"

/*
 * Enum describing buffer lock status
 */
enum lock_status {
	BUFFER_FREE	= 1,  //!< Buffer is not locked
	HW_LOCK,          //!< Buffer is locked by hardware
	SW_LOCK,          //!< Buffer is locked by software
	NOTDEVICEMEMORY,  //!< Buffer is not a device memory buffer
	LOCK_ST_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * Struct describing a data buffer
 */
struct img_buffer {
	struct vidio_ddbufinfo mem_info;				//!< Pointer to the memory handle for the buffer
	enum lock_status lock;                  //!< Lock status for the buffer
	uint32	size;               //!< Size in bytes of the buffer
	uint32	bytes_written;       //!< Number of bytes written into buffer
};

/*
 * Struct describing a coded data buffer
 */
struct img_coded_buffer {
	struct vidio_ddbufinfo mem_info;				//!< Pointer to the memory handle for the buffer
	enum lock_status lock;                  //!< Lock status for the buffer
	uint32	size;               //!< Size in bytes of the buffer
	uint32	bytes_written;       //!< Number of bytes written into buffer
};

struct coded_info {
	struct img_buffer *code_package_fw_buffer;
	struct coded_package_dma_info *coded_package_fw;
};

// This structure is used by the Drivers
struct coded_package_host {
	struct coded_info mtx_info;
	struct img_coded_buffer *coded_buffer[MAX_CODED_BUFFERS_PER_PACKAGE]; // Array of pointers to buffers
	struct img_buffer *header_buffer;
	uint8 num_coded_buffers;
	uint8 busy;
};

/*
 * Struct describing surface component info
 */
struct img_surf_component_info {
	uint32	step;
	uint32	width;
	uint32	height;
	uint32	phys_width;
	uint32	phys_height;
};

/*
 * Struct describing a frame
 */
struct img_frame {
	struct img_buffer *y_plane_buffer;						//!< pointer to the image buffer
	struct img_buffer *u_plane_buffer;						//!< pointer to the image buffer
	struct img_buffer *v_plane_buffer;						//!< pointer to the image buffer
	uint32		width_bytes;							//!< stride of pBuffer
	uint32		height;							//!< height of picture in pBuffer

	uint32		component_count;					//!< number of colour components used
	enum img_format	format;

	uint32		component_offset[3];
	uint32		bottom_component_offset[3];
	struct img_surf_component_info 	component_info[3];

	int32		y_component_offset;
	int32		u_component_offset;
	int32		v_component_offset;

	int32		field0_y_offset, field1_y_offset;
	int32		field0_u_offset, field1_u_offset;
	int32		field0_v_offset, field1_v_offset;

	uint16		src_y_stride_bytes, src_uv_stride_bytes;
	osa_bool	imported;
};

/*
 * Struct describing an array of frames
 */
struct img_frame_array {
	uint32 array_size;   //!< Number of frames in array
	struct img_frame *frame;          //!< Pointer to start of frame array
};

/*
 * Struct describing list items
 */
struct list_item {
	struct list_item *next;		//!< Next item in the list
	void *data;				//!< pointer to list item data
};

/*
 * Struct describing rate control params
 */
struct img_rc_params {
	uint32	bits_per_second;			//!< Bit rate
	uint32	transfer_bits_per_second;	//!< Transfer rate of encoded data from encoder to the output
	uint32	initial_qp_i;				//!< Initial QP I frames (only field used by JPEG)
	uint32	initial_qp_p;				//!< Initial QP P frames (only field used by JPEG)
	uint32	initial_qp_b;				//!< Initial QP B frames (only field used by JPEG)
	uint32	bu_size;					//!< Basic unit size
	uint32	frame_rate;
	uint32	buffer_size;
	uint32	intra_freq;
	int16	min_qp;
	int16	max_qp;
	osa_bool rc_enable;
	int32	initial_level;
	int32	initial_delay;
	uint16	bframes;
	osa_bool	hierarchical;

	osa_bool  enable_slice_bob;	//!< Enable movement of slice boundary when Qp is high
	uint8  max_slice_bob;     //!< Maximum number of rows the slice boundary can be moved
	uint8  slice_bob_qp;		//!< Minimum Qp at which slice bobbing should take place

	int8	qcp_offset;
	osa_bool	sc_detect_disable;
	uint32	slice_byte_limit;
	uint32	slice_mb_limit;
	enum img_rcmode rc_mode;
	enum img_rc_vcm_mode rc_vcm_mode;
	uint32	rc_cfs_max_margin_perc;
	osa_bool	disable_frame_skipping;
	osa_bool	disable_vcm_hardware;
};

/*
 * Bit fields for ui32MmuFlags
 */
#define MMU_USE_MMU_FLAG		0x00000001
#define MMU_TILED_FLAG			0x00000002
#define MMU_EXTENDED_ADDR_FLAG	0x00000004
#define MMU_SECURE_FW_UPLOAD	0x00000008
#define MMU_TILED_INTERLEAVED	0x00000010

#endif
