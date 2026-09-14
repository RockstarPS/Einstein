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
 * VXD DEC Common low level core interface component
 */
#ifndef _VXD_INT_H
#define _VXD_INT_H

#include "fw_interface.h"
#include "scaler_setup.h"
#include "vdecdd_defs.h"
#include "vdecfw_shared.h"
#include "vdec_defs.h"
#include "vxd_ext.h"
#include "vxd_props.h"

/*
 * Size of buffer used for batching messages
 */
#define BATCH_MSG_BUFFER_SIZE           (8 * 4096)

#define INTRA_BUF_SIZE                  (1024 * 32)
#define AUX_LINE_BUFFER_SIZE            (512 * 1024)

#define MAX_PICTURE_WIDTH               (4096)
#define MAX_PICTURE_HEIGHT              (4096)

 /*
  * this macro returns the host address of device buffer.
  */
#define GET_HOST_ADDR(buf) ((buf)->dev_virt)

#define GET_HOST_ADDR_OFFSET(buf, offset) (((buf)->dev_virt) + (offset))

/*
 * The extended stride alignment for VXD.
 */
#define VDEC_VXD_EXT_STRIDE_ALIGNMENT_DEFAULT  (64)

struct vxd_buffers {
	struct vdecdd_ddpict_buf *recon_pict;
	struct vdecdd_ddpict_buf *alt_pict;
	struct vidio_ddbufinfo *intra_bufinfo;
	struct vidio_ddbufinfo *auxline_bufinfo;
	struct vidio_ddbufinfo *err_pict_bufinfo;
	uint32 intra_bufsize_per_pipe;
	uint32 auxline_bufsize_per_pipe;
	struct vidio_ddbufinfo *msb_bufinfo;
	uint8 btwopass;
};

struct pvdec_core_rev {
	uint32 maj_rev;
	uint32 min_rev;
	uint32 maint_rev;
	uint32 int_rev;
};

/*
 * this has all that it needs to translate a Stream Unit for a picture
 * into a transaction.
 */
void vxd_set_altpictcmds(const struct vdecdd_str_unit *str_unit,
			const struct vdec_str_configdata *str_configdata,
			const struct vdec_str_opconfig *output_config,
			const struct vxd_coreprops *coreprops,
			const struct vxd_buffers *buffers,
			uint32 *pict_cmds);

/*
 * this has all that it needs to translate a Stream Unit for
 * a picture into a transaction.
 */
void vxd_set_reconpictcmds(const struct vdecdd_str_unit *str_unit,
			  const struct vdec_str_configdata *str_configdata,
			  const struct vdec_str_opconfig *output_config,
			  const struct vxd_coreprops *coreprops,
			  const struct vxd_buffers *buffers,
			  uint32 *pict_cmds);

int32 vxd_getscalercmds(const struct scaler_config *scaler_config,
		      const struct scaler_pitch *pitch,
		      const struct scaler_filter *filter,
		      const struct pixel_pixinfo *out_loop_pixel_info,
		      struct scaler_params *params,
		      uint32 *pict_cmds);

/*
 * this creates value of MSVDX_CMDS_CODED_PICTURE_SIZE register.
 */
uint32 vxd_get_codedpicsize(uint16  width_min1, uint16 height_min1);

/*
 * return HW codec mode based on video standard.
 */
uint8 vxd_get_codedmode(enum vdec_vid_std vidstd);

/*
 * translates core properties to the form of the struct vxd_coreprops struct.
 */
void vxd_get_coreproperties(void *hndl_coreproperties,
			   struct vxd_coreprops *vxd_coreprops);

/*
 * translates picture attributes to the form of the VXD_sPictAttrs struct.
 */
int32 vxd_get_pictattrs(uint32 flags, struct vxd_pict_attrs *pict_attrs);

/*
 * translates message attributes to the form of the VXD_eMsgAttr struct.
 */
int32 vxd_get_msgerrattr(uint32 flags, enum vxd_msg_attr *msg_attr);

/*
 * sets a message flag.
 */
int32 vxd_set_msgflag(enum vxd_msg_flag input_flag, uint32 *flags);

#endif /* _VXD_INT_H */
