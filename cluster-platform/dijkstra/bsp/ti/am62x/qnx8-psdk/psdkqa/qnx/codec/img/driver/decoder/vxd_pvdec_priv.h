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
 * VXD PVDEC Private header file
 */

#ifndef _VXD_PVDEC_PRIV_H
#define _VXD_PVDEC_PRIV_H

#include "osal/inc/osa_interrupt.h"
#include "osal/inc/osa_err.h"
#include "img_dec_common.h"
#include "vxd_pvdec_regs.h"
#include "vxd_dec.h"

struct vxd_boot_poll_params {
	uint32 msleep_cycles;
};

struct vxd_ena_params {
	struct vxd_boot_poll_params boot_poll;

	size_t fw_buf_size;
	uint32 fw_buf_virt_addr; /*
			       * VXD's MMU virtual address of a firmware
			       * buffer.
			       */
	uint32 ptd; /* Shifted physical address of PTD */

	/* Required for firmware upload via registers. */
	struct {
		const uint8 *buf; /* Firmware blob buffer */

	} regs_data;

	struct {
		unsigned secure:1;  /* Secure flow indicator. */
		unsigned wait_dbg_fifo:1; /*
					   * Indicates that fw shall use
					   * blocking mode when putting logs
					   * into debug fifo
					   */
	};

	/* Structure containing memory staller configuration */
	struct {
		uint32 *data;          /* Configuration data array */
		uint8 size;            /* Configuration size in dwords */

	} mem_staller;

	uint32 fwwdt_ms;      /* Firmware software watchdog timeout value */

	uint32 crc; /* HW signatures to be enabled by firmware */
	uint32 rendec_addr; /* VXD's virtual address of a rendec buffer */
	uint16 rendec_size; /* Size of a rendec buffer in 4K pages */
};

int32 vxd_pvdec_init(const void *dev, void __iomem *reg_base);

int32 vxd_pvdec_ena(const void *dev, void __iomem *reg_base,
		  struct vxd_ena_params *ena_params, struct vxd_fw_hdr *hdr,
		  uint32 *freq_khz);

int32 vxd_pvdec_dis(const void *dev, void __iomem *reg_base);

int32 vxd_pvdec_mmu_flush(const void *dev, void __iomem *reg_base);

int32 vxd_pvdec_send_msg(const void *dev, void __iomem *reg_base,
		       uint32 *msg, size_t msg_size, uint16 msg_id,
		       struct vxd_dev *ctx);

int32 vxd_pvdec_pend_msg_info(const void *dev, void __iomem *reg_base,
			    size_t *size, uint16 *msg_id, osa_bool *not_last_msg);

int32 vxd_pvdec_recv_msg(const void *dev, void __iomem *reg_base,
		       uint32 *buf, size_t buf_size, struct vxd_dev *ctx);

int32 vxd_pvdec_check_fw_status(const void *dev, void __iomem *reg_base);

size_t vxd_pvdec_peek_mtx_fifo(const void *dev,
			       void __iomem *reg_base);

size_t vxd_pvdec_read_mtx_fifo(const void *dev, void __iomem *reg_base,
			       uint32 *buf, size_t size);

osa_irqreturn_t vxd_pvdec_clear_int(void __iomem *reg_base, uint32 *irq_status);

int32 vxd_pvdec_check_irq(const void *dev, void __iomem *reg_base,
			uint32 irq_status);

int32 vxd_pvdec_msg_fit(const void *dev, void __iomem *reg_base,
		      size_t msg_size);

void vxd_pvdec_get_state(const void *dev, void __iomem *reg_base,
			 uint32 num_pipes, struct vxd_hw_state *state);

int32 vxd_pvdec_get_props(const void *dev, void __iomem *reg_base,
			struct vxd_core_props *props);

size_t vxd_pvdec_get_dbg_fifo_size(void __iomem *reg_base);

int32 vxd_pvdec_dump_mtx_ram(const void *dev, void __iomem *reg_base,
			   uint32 addr, uint32 count, uint32 *buf);

int32 vxd_pvdec_dump_mtx_status(const void *dev, void __iomem *reg_base,
			      uint32 *array, uint32 array_size);

#endif /* _VXD_PVDEC_PRIV_H */
