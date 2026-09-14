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
 * MTX Firmware Interface
 */

#include "fw_headers/mtx_fwif.h"
#include "fw_headers/defs.h"
#include "fw_binaries/include_all_fw_variants.h"
#include "img_errors.h"
#include "osal/inc/osa_delay.h"
#include "osal/inc/osa_mem.h"
#include "osal/inc/osa_string.h"
#include "reg_headers/mtx_regs.h"
/* still used for DMAC regs */
#include "reg_headers/img_soc_dmac_regs.h"
#include "target_config.h"
#include "topaz_device.h"
#include "topazmmu.h"
#include "vxe_public_regdefs.h"

extern struct mem_space topaz_mem_space[];

/*
 * Static Function Decl
 */
static void mtx_get_mtx_ctrl_from_dash(struct img_fw_context * fw_ctx);

static uint32 mtx_read_core_reg(struct img_fw_context * fw_ctx,
				const uint32 reg);

static void mtx_write_core_reg(struct img_fw_context * fw_ctx,
			       const uint32 reg, const uint32 val);

static int32 mtx_select_fw_build(struct img_fw_context * fw_ctx,
				 enum img_codec codec);

static void mtx_reg_if_upload(struct img_fw_context * fw_ctx,
			      const uint32 data_mem, uint32 addr,
			      const uint32 words, const uint32 *const data);

/*
 * Polling Configuration for TAL
 */
#define TAL_REG_RD_WR_TRIES     1000 /* => try 1000 times before giving up */

/*
 * defines that should come from auto generated headers
 */
#define MTX_DMA_MEMORY_BASE (0x82880000)
#define PC_START_ADDRESS    (0x80900000)

#define MTX_CORE_CODE_MEM   (0x10)
#define MTX_CORE_DATA_MEM   (0x18)

#define MTX_PC              (0x05)

/*
 * Get control of the MTX.
 * @Input    fw_ctx         : Pointer to the context of the target MTX
 * @Return   None
 */
static void mtx_get_mtx_ctrl_from_dash(struct img_fw_context * fw_ctx)
{
	uint32 reg = 0;

	IMG_DBG_ASSERT(!fw_ctx->drv_has_mtx_ctrl);

	/* Request the bus from the Dash...*/
	reg = F_ENCODE(1, TOPAZHP_TOP_CR_MTX_MSTR_DBG_IS_SLAVE) | F_ENCODE(0x2, TOPAZHP_TOP_CR_MTX_MSTR_DBG_GPIO_IN);
	VXE_WR_REG32(fw_ctx->topaz_multicore_reg_addr,
		     TOPAZHP_TOP_CR_MTX_DEBUG_MSTR, reg);

	do {
		reg = VXE_RD_REG32(fw_ctx->topaz_multicore_reg_addr,
				   TOPAZHP_TOP_CR_MTX_DEBUG_MSTR);

	} while ((reg & 0x18) != 0);

	/* Save the access control register...*/
	fw_ctx->drv_has_mtx_ctrl = VXE_RD_REG32(fw_ctx->mtx_reg_mem_space_addr,
						MTX_CR_MTX_RAM_ACCESS_CONTROL);

	fw_ctx->drv_has_mtx_ctrl = osa_true;
}

/*
 * Release control of the MTX.
 * @Input    fw_ctx         : Pointer to the context of the target MTX
 * @Return   None
 */
static void mtx_release_mtx_ctrl_from_dash(struct img_fw_context * fw_ctx)
{
	uint32 reg = 0;

	IMG_DBG_ASSERT(fw_ctx->drv_has_mtx_ctrl);

	/* Restore the access control register...*/
	VXE_WR_REG32(fw_ctx->mtx_reg_mem_space_addr,
		     MTX_CR_MTX_RAM_ACCESS_CONTROL,
		     fw_ctx->access_control);

	/* Release the bus...*/
	reg = F_ENCODE(1, TOPAZHP_TOP_CR_MTX_MSTR_DBG_IS_SLAVE);
	VXE_WR_REG32(fw_ctx->topaz_multicore_reg_addr,
		     TOPAZHP_TOP_CR_MTX_DEBUG_MSTR,
		     reg);

	fw_ctx->drv_has_mtx_ctrl = osa_false;
}

/*
 * Read an MTX register.
 * @Input    fw_ctx         : Pointer to the context of the target MTX
 * @Input    reg : Offset of register to read
 * @Return   uint32       : Register value
 */
static uint32 mtx_read_core_reg(struct img_fw_context * fw_ctx,
				const uint32 reg)
{
	uint32 ret = 0;

	mtx_get_mtx_ctrl_from_dash(fw_ctx);

	/* Issue read request */
	VXE_WR_REG32(fw_ctx->mtx_reg_mem_space_addr,
		     MTX_CR_MTX_REGISTER_READ_WRITE_REQUEST,
		     MASK_MTX_MTX_RNW | (reg & ~MASK_MTX_MTX_DREADY));

	/* Wait for done */
	VXE_POLL_REG32_ISEQ(fw_ctx->mtx_reg_mem_space_addr,
			    MTX_CR_MTX_REGISTER_READ_WRITE_REQUEST,
			    MASK_MTX_MTX_DREADY,
			    MASK_MTX_MTX_DREADY,
			    TAL_REG_RD_WR_TRIES);

	/* Read */
	ret = VXE_RD_REG32(fw_ctx->mtx_reg_mem_space_addr,
			   MTX_CR_MTX_REGISTER_READ_WRITE_DATA);

	mtx_release_mtx_ctrl_from_dash(fw_ctx);

	return ret;
}

/*
 * Write an MTX register.
 * @Input    fw_ctx         : Pointer to the context of the target MTX
 * @Input    reg : Offset of register to write
 * @Input    val : Value to write to register
 */
static void mtx_write_core_reg(struct img_fw_context * fw_ctx,
			       const uint32 reg, const uint32 val)
{
	mtx_get_mtx_ctrl_from_dash(fw_ctx);

	/* Put data in MTX_RW_DATA */
	VXE_WR_REG32(fw_ctx->mtx_reg_mem_space_addr,
		     MTX_CR_MTX_REGISTER_READ_WRITE_DATA, val);

	/* DREADY is set to 0 and request a write*/
	VXE_WR_REG32(fw_ctx->mtx_reg_mem_space_addr,
		     MTX_CR_MTX_REGISTER_READ_WRITE_REQUEST,
		     (reg & ~MASK_MTX_MTX_DREADY));

	/* Wait for DREADY to become set*/
	VXE_POLL_REG32_ISEQ(fw_ctx->mtx_reg_mem_space_addr,
			    MTX_CR_MTX_REGISTER_READ_WRITE_REQUEST,
			    MASK_MTX_MTX_DREADY,
			    MASK_MTX_MTX_DREADY,
			    TAL_REG_RD_WR_TRIES);

	mtx_release_mtx_ctrl_from_dash(fw_ctx);
}

/* ****** Utility macroses for `mtx_select_fw_build` ************** */

#if FW_BIN_FORMAT_VERSION != 2
#	error Unsupported firmware format version
#endif

/*
 * Assign a firmware binary to an MTX.
 * @Input    fw_ctx         : Pointer to the context of the target MTX
 * @Input    codec           : Firmware version to use
 */
static int32 mtx_select_fw_build(struct img_fw_context * fw_ctx,
				 enum img_codec codec)
{
	osa_char *fmt, *rc_mode;
	uint32 target_fw_pipes = 0;
	uint32 codec_mask = 0;
	uint32 cur_hw_config;
	osa_bool force_specific_pipe_cnt = osa_false;

#	define HW_CONFIG_ALL_FEATURES 0
#	define HW_CONFIG_8CONTEXT	  1

#define CORE_REV_CONFIG_1_MIN 0x00030906
#define CORE_REV_CONFIG_1_MAX 0x0003090a


#	define CODEC_MASK_JPEG		0x0001
#	define CODEC_MASK_MPEG2		0x0002
#	define CODEC_MASK_MPEG4		0x0004
#	define CODEC_MASK_H263		0x0008
#	define CODEC_MASK_H264		0x0010
#	define CODEC_MASK_H264MVC	0x0020
#	define CODEC_MASK_VP8		0x0040
#	define CODEC_MASK_H265		0x0080
#	define CODEC_MASK_FAKE		0x007F

#	define _ALL_CODEC_CASE(CODEC) \
		case IMG_CODEC_ ## CODEC ## _NO_RC: \
		case IMG_CODEC_ ## CODEC ## _VBR: \
		case IMG_CODEC_ ## CODEC ## _CBR:
#	define _MVC_CODEC_CASE(RC) case IMG_CODEC_H264MVC_ ## RC: fmt = "H264MVC"; rc_mode = #RC; force_specific_pipe_cnt = osa_true; codec_mask = CODEC_MASK_H264MVC; break;

	switch (codec) {
	_ALL_CODEC_CASE(H264)
	case IMG_CODEC_H264_VCM:
		fmt = "H264";
		rc_mode = "ALL";
		force_specific_pipe_cnt = osa_true;
		codec_mask = CODEC_MASK_H264;
	break;
	_ALL_CODEC_CASE(H263)
		fmt = "LEGACY_VIDEO";
		rc_mode = "ALL";
		codec_mask = CODEC_MASK_H263;
	break;
	_ALL_CODEC_CASE(MPEG2)
		fmt = "LEGACY_VIDEO";
		rc_mode = "ALL";
		codec_mask = CODEC_MASK_MPEG2;
	break;
	_ALL_CODEC_CASE(MPEG4)
		fmt = "LEGACY_VIDEO";
		rc_mode = "ALL";
		codec_mask = CODEC_MASK_MPEG4;
	break;
	_MVC_CODEC_CASE(NO_RC);
	_MVC_CODEC_CASE(VBR);
	_MVC_CODEC_CASE(CBR);
	_MVC_CODEC_CASE(ERC);
	case IMG_CODEC_JPEG:
		fmt = "JPEG";
		rc_mode = "NO_RC";
		codec_mask = CODEC_MASK_JPEG;
	break;
	default:
		OSA_PR_ERR("Failed to locate firmware for codec %d \n", codec);
		return IMG_ERROR_UNDEFINED;
	}
#	undef _ALL_CODEC_CASE
#	undef _CODEC_CASE

	/* rc mode name fix */
	if (osa_strcmp(rc_mode, "NO_RC") == 0)
		rc_mode = "NONE";

	{
		/*
		 * Pick firmware type (done implicitly via determining number
		 * of pipes given firmware is expected to have
		 */
		const uint32 core_id = fw_ctx->core_rev;
#		define	IS_REV(name) ((core_id >= MIN_ ## name ## _REV) && \
				      (core_id <= MAX_ ## name ## _REV))

		if ((core_id >= CORE_REV_CONFIG_1_MIN) &&
		    (core_id <= CORE_REV_CONFIG_1_MAX)) {
			/*
			 * For now, it is assumed that this revision ID means 8
			 * context 2 pipe variant
			 */
			cur_hw_config = HW_CONFIG_8CONTEXT;
			target_fw_pipes = 2;
		}
		else {
			cur_hw_config = HW_CONFIG_ALL_FEATURES;
			if ((fw_ctx->hw_num_pipes < 3) &&
			    (force_specific_pipe_cnt))
				target_fw_pipes = 2;
			else
				target_fw_pipes = 4;

		}
#		undef IS_REV
	}

	{
		/* Search for matching firmwares */

		uint32 fmts_included = 0;
		uint32 ii;
		osa_bool preferred_fw_located = osa_false;
		uint32 req_size = 0;
		struct IMG_COMPILED_FW_BIN_RECORD *selected, *iter;

		selected = NULL;

		for (ii = 0; ii < all_fw_binaries_cnt; ii++) {
			iter = all_fw_binaries[ii];
			/*
			 * With HW_3_6, we want to allow 3 pipes if it was
			 * required, this is mainly for test purposes
			 */
			if ((osa_strcmp("JPEG_H264", iter->fmt) == 0) &&
			    (target_fw_pipes != 3)) {
				preferred_fw_located = osa_true;
				req_size = (4 * iter->data_size + (iter->data_origin - MTX_DMA_MEMORY_BASE));
				break;
			}
		}

		if (preferred_fw_located && (req_size <= fw_ctx->mtx_ram_size) &&
		    (cur_hw_config == iter->hw_config) &&
		    (iter->pipes >= target_fw_pipes) &&
		    ((codec_mask == CODEC_MASK_JPEG) || (codec_mask == CODEC_MASK_H264)) &&
		    ((iter->formats_mask & codec_mask) != 0)) {
			selected = iter;
		}
		else {
			for (ii = 0; ii < all_fw_binaries_cnt; ii++) {
				iter = all_fw_binaries[ii];
				/* The hardware config modes need to match */
				if (cur_hw_config != iter->hw_config) {
					OSA_PR_ERR("cur_hw_config %x iter->hw_config %x mismatch\n",
						   cur_hw_config, iter->hw_config);
					continue;
				}

				fmts_included = iter->formats_mask;

				if (((fmts_included & codec_mask) != 0) &&
				    (codec_mask == CODEC_MASK_JPEG ||
				     osa_strcmp(rc_mode, iter->rc_mode) == 0)) { /* no need to match RC for JPEG */
					/*
					 * This firmware matches by format/mode
					 * combination, now to check if it fits
					 * better than current best
					 */
					if ((!selected) &&
					    (iter->pipes >= target_fw_pipes)) {
						/*
						 * Select firmware ether if it
						 * is first matchin one we've
						 * encountered or if it better
						 * matches desired number of
						 * pipes.
						 */
						selected = iter;
					}

					if (iter->pipes == target_fw_pipes) {
						/* Found ideal firmware version */
						selected = iter;
						break;
					}
				}
			}
		}

		if (!selected) {
			OSA_PR_ERR("Failed to locate firmware for format '%s' and RC mode '%s'.\n",
				   fmt, rc_mode);
			return IMG_ERROR_UNDEFINED;
		}
		else {
			OSA_PR_INFO("Using firmware: %s with %i pipes, hwconfig=%i (text size = %i, data size = %i) for requested codec: %s RC mode %s\n",
				    selected->fmt, selected->pipes,
				    selected->hw_config, selected->text_size,
				    selected->data_size, fmt, rc_mode);
		}

		/* Export selected firmware to the fw context */
		fw_ctx->mtx_topaz_fw_text_size = selected->text_size;
		fw_ctx->mtx_topaz_fw_data_size = selected->data_size;
		fw_ctx->mtx_topaz_fw_text = selected->text;
		fw_ctx->mtx_topaz_fw_data = selected->data;
		fw_ctx->mtx_topaz_fw_data_origin = selected->data_origin;
		fw_ctx->num_pipes = selected->pipes;
		fw_ctx->int_defines.length = selected->int_define_cnt;
		fw_ctx->int_defines.names = selected->int_define_names;
		fw_ctx->int_defines.values = selected->int_defines;
		fw_ctx->supported_codecs = selected->formats_mask;
		fw_ctx->num_contexts = mtx_get_fw_config_int(fw_ctx, "TOPAZHP_MAX_NUM_STREAMS");
	}
	return IMG_SUCCESS;
}

/*
 * Upload MTX text and data sections via register interface
 * @Input    fw_ctx         : Pointer to the context of the target MTX
 * @Input    data_mem : RAM ID for text/data section
 * @Input    address : Address to upload data to
 * @Input    words : Number of words of data to upload
 * @Input    data : Pointer to data to upload
 */
static void mtx_reg_if_upload(struct img_fw_context * fw_ctx, const uint32 data_mem,
			      uint32 address, const uint32 words,
			      const uint32 *const data)
{
	uint32 loop;
	uint32 ctrl;
	uint32 ram_id;
	uint32 addr;
	uint32 curr_bank = ~0;
	uint32 uploaded = 0;

	mtx_get_mtx_ctrl_from_dash(fw_ctx);

	VXE_POLL_REG32_ISEQ(fw_ctx->mtx_reg_mem_space_addr,
			    MTX_CR_MTX_RAM_ACCESS_STATUS,
			    MASK_MTX_MTX_MTX_MCM_STAT,
			    MASK_MTX_MTX_MTX_MCM_STAT,
			    TAL_REG_RD_WR_TRIES);

	for (loop =0; loop < words; loop++) {
		ram_id = data_mem + (address / fw_ctx->mtx_bank_size);
		if (ram_id != curr_bank) {
			addr = address >> 2;
			ctrl = 0;
			ctrl = F_ENCODE(ram_id, MTX_MTX_MCMID) |
				F_ENCODE(addr, MTX_MTX_MCM_ADDR) |
				F_ENCODE(1, MTX_MTX_MCMAI);
			VXE_WR_REG32(fw_ctx->mtx_reg_mem_space_addr,
				     MTX_CR_MTX_RAM_ACCESS_CONTROL,
				     ctrl);
			curr_bank = ram_id;
		}
		address+= 4;

		if (uploaded > (1024*24)) /* should this be RAM bank size?? */
			break;
		uploaded += 4;

		VXE_WR_REG32(fw_ctx->mtx_reg_mem_space_addr,
			     MTX_CR_MTX_RAM_ACCESS_DATA_TRANSFER,
			     data[loop]);

		VXE_POLL_REG32_ISEQ(fw_ctx->mtx_reg_mem_space_addr,
				    MTX_CR_MTX_RAM_ACCESS_STATUS,
				    MASK_MTX_MTX_MTX_MCM_STAT,
				    MASK_MTX_MTX_MTX_MCM_STAT,
				    TAL_REG_RD_WR_TRIES);
	}

	mtx_release_mtx_ctrl_from_dash(fw_ctx);
}

/*
 * Transfer memory between the Host and MTX via DMA.
 * @Input    fw_ctx         : Pointer to the context of the target MTX
 * @Input    channel          : DMAC channel to use (0 for TopazSC)
 * @Input    hHostMemTransfer : void * for the host memory
 * @Input    hostMemOffset    : offset into the host memory
 * @Input    mtx_addr : Address on MTX
 * @Input    numWords         : size of transfer in 32-bit words (PW units)
 * @Input    bRNW             : Read not Write (osa_false to write to the MTX)
 */
void mtx_dmac_transfer(struct img_fw_context *fw_ctx, uint32 channel,
		       struct vidio_ddbufinfo *host_mem_transfer,
		       uint32 host_mem_offset, uint32 mtx_addr,
		       uint32 words, osa_bool rnw)
{
	uint32 irq_stat;
	uint32 count_reg;
	void * dmac_reg_addr;
	void * reg_addr;
	uint32 config_reg;
	uint32 mmu_status = 0;

	uint32 dmac_burst_size = DMAC_BURST_2; /* 2 * 128 bits = 32 bytes */
	uint32 mtx_burst_size = 4; /* 4 * 2 * 32 bits = 32 bytes */

	/* check the burst sizes */
	IMG_DBG_ASSERT(MTX_DMA_BURSTSIZE_BYTES == dmac_burst_size * 16);
	IMG_DBG_ASSERT(MTX_DMA_BURSTSIZE_BYTES == mtx_burst_size * 8);

	/* check transfer size matches burst width */
	IMG_DBG_ASSERT(0 == (words & ((MTX_DMA_BURSTSIZE_BYTES >> 2) - 1)));

	/* check DMA channel */
	IMG_DBG_ASSERT(channel < DMAC_MAX_CHANNELS);

	/* check that no transfer is currently in progress */
	dmac_reg_addr = (void *)topaz_mem_space[REG_DMAC].cpu_addr;
	count_reg = VXE_RD_REG32(dmac_reg_addr, IMG_SOC_DMAC_COUNT(channel));
	IMG_DBG_ASSERT(0 == (count_reg &
			     (MASK_IMG_SOC_EN | MASK_IMG_SOC_LIST_EN)));

	/* check we don't already have a page fault condition */
	reg_addr = (void *)topaz_mem_space[REG_TOPAZHP_MULTICORE].cpu_addr;
	mmu_status = VXE_RD_REG32(reg_addr, TOPAZHP_TOP_CR_MMU_STATUS);

	IMG_DBG_ASSERT(0 == mmu_status);

	if (mmu_status ||
	    (count_reg & (MASK_IMG_SOC_EN | MASK_IMG_SOC_LIST_EN))) {
		/* DMA engine not idle or pre-existing page fault condition */
		OSA_PR_ERR("DMA engine not idle or pre-existing page fault condition!\n");
		fw_ctx->initialized = osa_false;
		return;
	}

	/* clear status of any previous interrupts */
	VXE_WR_REG32(dmac_reg_addr, IMG_SOC_DMAC_IRQ_STAT(channel), 0);

	/* and that no interrupts are outstanding */
	irq_stat = VXE_RD_REG32(dmac_reg_addr, IMG_SOC_DMAC_IRQ_STAT(channel));
	IMG_DBG_ASSERT(0 == irq_stat);

	/* Write MTX DMAC registers (for current MTX) */
	/* MTX Address */
	VXE_WR_REG32(fw_ctx->mtx_reg_mem_space_addr, MTX_CR_MTX_SYSC_CDMAA,
		     mtx_addr);

	/* MTX DMAC Config */
	config_reg = F_ENCODE(mtx_burst_size, MTX_BURSTSIZE) |
			F_ENCODE((rnw ? 1 : 0), MTX_RNW) |
			F_ENCODE(1, MTX_ENABLE) |
			F_ENCODE(words, MTX_LENGTH);
	VXE_WR_REG32(fw_ctx->mtx_reg_mem_space_addr, MTX_CR_MTX_SYSC_CDMAC,
		     config_reg);

	/* Write System DMAC registers */
	/* per hold - allow HW to sort itself out */
	VXE_WR_REG32(dmac_reg_addr, IMG_SOC_DMAC_PER_HOLD(channel), 16);

	VXE_WR_REG32(dmac_reg_addr, IMG_SOC_DMAC_SETUP(channel),
			 host_mem_transfer->dev_virt + host_mem_offset);

	/* count reg */
	count_reg = DMAC_VALUE_COUNT(DMAC_BSWAP_NO_SWAP, DMAC_PWIDTH_32_BIT,
				     rnw, DMAC_PWIDTH_32_BIT, words);
	count_reg |= MASK_IMG_SOC_TRANSFER_IEN;	/* generate an interrupt at end of transfer */
	VXE_WR_REG32(dmac_reg_addr, IMG_SOC_DMAC_COUNT(channel), count_reg);

	/* don't inc address, set burst size */
	VXE_WR_REG32(dmac_reg_addr, IMG_SOC_DMAC_PERIPH(channel),
		     DMAC_VALUE_PERIPH_PARAM(DMAC_ACC_DEL_0, osa_false,
					     dmac_burst_size));

	/* Target correct MTX DMAC port */
	VXE_WR_REG32(dmac_reg_addr, IMG_SOC_DMAC_PERIPHERAL_ADDR(channel),
		     MTX_CR_MTX_SYSC_CDMAT + REG_START_TOPAZ_MTX_HOST);

	/*
	 * Finally, rewrite the count register with the enable bit set to kick
	 * off the transfer
	 */
	VXE_WR_REG32(dmac_reg_addr, IMG_SOC_DMAC_COUNT(channel),
		     (count_reg | MASK_IMG_SOC_EN));

	/* Wait for it to finish */
	VXE_POLL_REG32_ISEQ(dmac_reg_addr, IMG_SOC_DMAC_IRQ_STAT(channel),
			    F_ENCODE(1, IMG_SOC_TRANSFER_FIN),
			    F_ENCODE(1, IMG_SOC_TRANSFER_FIN),
			    TAL_REG_RD_WR_TRIES);
	count_reg = VXE_RD_REG32(dmac_reg_addr, IMG_SOC_DMAC_COUNT(channel));
	mmu_status = VXE_RD_REG32(reg_addr, TOPAZHP_TOP_CR_MMU_STATUS);
	if (mmu_status ||
	    (count_reg & (MASK_IMG_SOC_EN | MASK_IMG_SOC_LIST_EN))) {
		OSA_PR_ERR("DMA has failed or page faulted\n");
		/* DMA has failed or page faulted */
		fw_ctx->initialized = osa_false;
	}

	/* Clear the interrupt */
	VXE_WR_REG32(dmac_reg_addr, IMG_SOC_DMAC_IRQ_STAT(channel), 0);
}

/*
 * Sets target MTX for DMA and register writes
 * @Input    fw_ctx         : Pointer to the context of the target MTX
 * @Input    bTargetAll       : osa_true indicates register and DMA writes go to all MTX
 */
void mtx_set_target(struct img_fw_context * fw_ctx)
{
	uint32 reg = 0;
	reg = F_ENCODE(0, TOPAZHP_TOP_CR_WRITES_CORE_ALL);
	VXE_WR_REG32(fw_ctx->topaz_multicore_reg_addr,
		     TOPAZHP_TOP_CR_MULTICORE_CORE_SEL_0,
		     reg);
}

/*
 * Upload text and data sections via DMA
 * @Input    fw_ctx         : Pointer to the context of the target MTX
 */
static void mtx_uploadfw(void *dev_ctx, struct img_fw_context *fw_ctx)
{
	struct topaz_dev_ctx *ctx = (struct topaz_dev_ctx *)dev_ctx;
	struct vidio_ddbufinfo text, data;
	void * add_lin_text, * add_lin_data;
	uint32 text_size = fw_ctx->mtx_topaz_fw_text_size;
	uint32 data_size = fw_ctx->mtx_topaz_fw_data_size;

	if (topaz_mmu_alloc(ctx->topaz_mmu_ctx.mmu_context_handle,
			  ctx->vxe_arg, MMU_GENERAL_HEAP_ID, 1,
			  (enum sys_emem_attrib)(SYS_MEMATTRIB_UNCACHED | SYS_MEMATTRIB_WRITECOMBINE),
			  text_size * 4 + MTX_DMA_BURSTSIZE_BYTES, 64, &text)) {
					OSA_PR_ERR("mmu_alloc for text failed!\n");
		fw_ctx->initialized = osa_false;
		return;
	}
	if (topaz_mmu_alloc(ctx->topaz_mmu_ctx.mmu_context_handle,
			  ctx->vxe_arg, MMU_GENERAL_HEAP_ID, 1,
			  (enum sys_emem_attrib)(SYS_MEMATTRIB_UNCACHED | SYS_MEMATTRIB_WRITECOMBINE),
			  data_size * 4 + MTX_DMA_BURSTSIZE_BYTES, 64, &data)) {
		OSA_PR_ERR("mmu_alloc for data failed!\n");
		topaz_mmu_free(ctx->vxe_arg, &text);
		fw_ctx->initialized = osa_false;
		return;
	}

	add_lin_text = text.cpu_virt;
	osa_memcpy((void *)add_lin_text, fw_ctx->mtx_topaz_fw_text, text_size * 4);
	add_lin_data = data.cpu_virt;
	osa_memcpy((void *)add_lin_data, fw_ctx->mtx_topaz_fw_data, data_size * 4);

	topaz_update_device_mem(ctx->vxe_arg, &text);
	topaz_update_device_mem(ctx->vxe_arg, &data);

	/* adjust transfer sizes of text and data sections to match burst size */
	text_size = ((text_size * 4 + (MTX_DMA_BURSTSIZE_BYTES - 1)) & ~(MTX_DMA_BURSTSIZE_BYTES - 1)) / 4;
	data_size = ((data_size*4 + (MTX_DMA_BURSTSIZE_BYTES - 1)) & ~(MTX_DMA_BURSTSIZE_BYTES - 1)) / 4;

	/* ensure that data section (+stack) will not wrap in memory */
	IMG_DBG_ASSERT(fw_ctx->mtx_ram_size >= (fw_ctx->mtx_topaz_fw_data_origin + (data_size * 4) - MTX_DMA_MEMORY_BASE));
	if (fw_ctx->mtx_ram_size < (fw_ctx->mtx_topaz_fw_data_origin + (data_size * 4) - MTX_DMA_MEMORY_BASE))
		fw_ctx->initialized = osa_false;

	/* data section is already prepared/cached */
	/* Transfer the text section */
	if (fw_ctx->initialized) {
		mtx_dmac_transfer(fw_ctx, 0, &text, 0, MTX_DMA_MEMORY_BASE,
				  text_size, osa_false);
	}
	/* Transfer the data section */
	if (fw_ctx->initialized) {
		mtx_dmac_transfer(fw_ctx, 0, &data, 0,
				  fw_ctx->mtx_topaz_fw_data_origin, data_size,
				  osa_false);
	}

	topaz_mmu_free(ctx->vxe_arg, &text);
	topaz_mmu_free(ctx->vxe_arg, &data);

	/* Flush the MMU table cache used during code download */
	topaz_core_mmu_flush_cache();
	if (fw_ctx->initialized)
		OSA_PR_INFO("mtx_uploadfw complete!");
}

/*
 * Load text and data sections onto an MTX.
 * @Input    fw_ctx         : Pointer to the context of the target MTX
 * @Input    load_method      : Method to use for loading code
 * @Input    bTargetAll       : Load to one (osa_false) or all (osa_true) MTX
 */
void mtx_load(void *dev_ctx, struct img_fw_context *fw_ctx,
	      enum mtx_load_method load_method)
{
	struct topaz_dev_ctx *ctx = (struct topaz_dev_ctx *)dev_ctx;
	uint32 reg;
	uint16 i;

	IMG_DBG_ASSERT(fw_ctx->initialized);
	if (!fw_ctx->initialized)
		return;

	fw_ctx->load_method = load_method;

	/* set target to current or all MTXs */
	mtx_set_target(fw_ctx);

	/* MTX Reset */
	VXE_WR_REG32(fw_ctx->mtx_reg_mem_space_addr, MTX_CR_MTX_SOFT_RESET,
		     MASK_MTX_MTX_RESET);
	osa_ndelay(300);

	switch (load_method) {
	case MTX_LOADMETHOD_REGIF:
		/* Code Upload */
		mtx_reg_if_upload(fw_ctx, MTX_CORE_CODE_MEM, 0,
				  fw_ctx->mtx_topaz_fw_text_size,
				  fw_ctx->mtx_topaz_fw_text);

		/* Data Upload */
		mtx_reg_if_upload(fw_ctx, MTX_CORE_DATA_MEM,
				  fw_ctx->mtx_topaz_fw_data_origin - MTX_DMA_MEMORY_BASE,
				  fw_ctx->mtx_topaz_fw_data_size,
				  fw_ctx->mtx_topaz_fw_data);
	break;

	case MTX_LOADMETHOD_DMA:
		mtx_uploadfw(ctx, fw_ctx);
	break;

	case MTX_LOADMETHOD_NONE:
	break;

	default:
		IMG_DBG_ASSERT(osa_false);
	}

	/* if we have had any failures up to this point then return now */
	if (!fw_ctx->initialized)
		return;

	if (load_method != MTX_LOADMETHOD_NONE) {
		for (i = 5; i < 8; i++)
			mtx_write_core_reg(fw_ctx, 0x1 | (i << 4), 0);

		/* Restore 8 Registers of D1 Bank */
		/* D1Re0, D1Ar5, D1Ar3, D1Ar1, D1RtP, D1.5, D1.6 and D1.7 */
		for (i = 5; i < 8; i++)
			mtx_write_core_reg(fw_ctx, 0x2 | (i << 4), 0);

		/* Set Starting PC address */
		mtx_write_core_reg(fw_ctx, MTX_PC, PC_START_ADDRESS);

		/* Verify Starting PC */
		reg = mtx_read_core_reg(fw_ctx, MTX_PC);

		OSA_PR_INFO("PC_START_ADDRESS = 0x%08X\n", reg);
		IMG_DBG_ASSERT(reg == PC_START_ADDRESS);
	}
}

/*
 * Deinitialise the given MTX context structure
 * @Input    fw_ctx         : Pointer to the context of the target MTX
 */
void mtx_deinitialize(struct img_fw_context * fw_ctx)
{
	struct topaz_dev_ctx *ctx = (struct topaz_dev_ctx *)fw_ctx->dev_ctx;
	uint32 i;

	if (!fw_ctx->initialized)
		OSA_PR_WARN("Warning detected multi de-initialiseations\n");

	for (i = 0; i < TOPAZHP_MAX_POSSIBLE_STREAMS; i++) {
		if (fw_ctx->mtx_context_data_copy[i])
			topaz_mmu_free(ctx->vxe_arg, fw_ctx->mtx_context_data_copy[i]);
		fw_ctx->mtx_context_data_copy[i] = NULL;
	}

	if (fw_ctx->mtx_reg_copy) {
		osa_free(fw_ctx->mtx_reg_copy);
		fw_ctx->mtx_reg_copy = NULL;
	}

	fw_ctx->initialized = osa_false;
}

/*
 * Initialise the given MTX context structure
 * @Input    fw_ctx       : Pointer to the context of the target MTX
 * @Input    core_num : Core number of the MTX to target
 * @Input    codec         : version of codec specific firmware to associate with this MTX
 */
int32 mtx_populate_fw_ctx(enum img_codec codec, struct img_fw_context * fw_ctx)
{
	uint32 pipe_cnt;
	uint32 size;
	uint32 i;

	if (fw_ctx->initialized || fw_ctx->populated)
		return IMG_ERROR_INVALID_CONTEXT;

	/* initialise Context structure */
	fw_ctx->mtx_reg_mem_space_addr = (void *)topaz_mem_space[REG_MTX].cpu_addr;
	fw_ctx->topaz_multicore_reg_addr = (void *)topaz_mem_space[REG_TOPAZHP_MULTICORE].cpu_addr;

	fw_ctx->core_rev = VXE_RD_REG32(fw_ctx->topaz_multicore_reg_addr, TOPAZHP_TOP_CR_TOPAZHP_CORE_REV);
	fw_ctx->core_rev &= (MASK_TOPAZHP_TOP_CR_TOPAZHP_MAINT_REV | MASK_TOPAZHP_TOP_CR_TOPAZHP_MINOR_REV | MASK_TOPAZHP_TOP_CR_TOPAZHP_MAJOR_REV);
	fw_ctx->core_des1 = VXE_RD_REG32(fw_ctx->topaz_multicore_reg_addr, TOPAZHP_TOP_CR_TOPAZHP_CORE_DES1);

	/* Number of hw pipes */
	pipe_cnt = VXE_RD_REG32(fw_ctx->topaz_multicore_reg_addr, TOPAZHP_TOP_CR_MULTICORE_HW_CFG);
	pipe_cnt = (pipe_cnt & MASK_TOPAZHP_TOP_CR_NUM_CORES_SUPPORTED);
	fw_ctx->hw_num_pipes = pipe_cnt;

	IMG_DBG_ASSERT(fw_ctx->hw_num_pipes > 0 && fw_ctx->hw_num_pipes <= TOPAZHP_MAX_NUM_PIPES);

	if (fw_ctx->hw_num_pipes <= 0 || fw_ctx->hw_num_pipes > TOPAZHP_MAX_NUM_PIPES)
		return IMG_ERROR_INVALID_ID;

	for (i = 0; i < fw_ctx->hw_num_pipes; i++)
		fw_ctx->topaz_reg_mem_space_addr[i] = (void *)topaz_mem_space[REG_TOPAZHP_CORE_0 + (4 * i)].cpu_addr;

	fw_ctx->mtx_debug_val = VXE_RD_REG32(fw_ctx->topaz_multicore_reg_addr, TOPAZHP_TOP_CR_MTX_DEBUG_MSTR);

	/* last bank size */
	size = 0x1 << (F_EXTRACT(fw_ctx->mtx_debug_val, TOPAZHP_TOP_CR_MTX_MSTR_LAST_RAM_BANK_SIZE ) + 2);
	/* all other banks */
	fw_ctx->mtx_bank_size = 0x1 << (F_EXTRACT(fw_ctx->mtx_debug_val, TOPAZHP_TOP_CR_MTX_MSTR_RAM_BANK_SIZE ) + 2);
	/* total RAM size */
	fw_ctx->mtx_ram_size = size + (fw_ctx->mtx_bank_size * (F_EXTRACT(fw_ctx->mtx_debug_val, TOPAZHP_TOP_CR_MTX_MSTR_RAM_BANKS) - 1));

	fw_ctx->drv_has_mtx_ctrl = osa_false;
	fw_ctx->access_control = 0;

	fw_ctx->active_ctx_mask = 0;

	if (mtx_select_fw_build(fw_ctx, codec) != IMG_SUCCESS) {
		fw_ctx->populated = osa_false;
		fw_ctx->initialized = osa_false;
		return IMG_ERROR_UNDEFINED;
	}

	if (fw_ctx->mtx_topaz_fw_data_size != 0) {
		/* check FW fits in memory */
		/* could also add stack size estimate */
		size = 4 * fw_ctx->mtx_topaz_fw_data_size;
		size += (fw_ctx->mtx_topaz_fw_data_origin - MTX_DMA_MEMORY_BASE);
		if (size > fw_ctx->mtx_ram_size) {
			IMG_DBG_ASSERT(fw_ctx->mtx_ram_size > size);
			return IMG_ERROR_OUT_OF_MEMORY;
		}
	}

	fw_ctx->populated = osa_true;
	return IMG_SUCCESS;
}

void mtx_initialize(void *dev_ctx, struct img_fw_context * fw_ctx)
{
	struct topaz_dev_ctx *ctx = (struct topaz_dev_ctx *)dev_ctx;
	uint32 i = 0;

	if (fw_ctx->initialized)
		return;

	if (fw_ctx->mtx_topaz_fw_data_size != 0) {
		fw_ctx->mtx_reg_copy = osa_malloc((53 * 4), OSA_GFP_KERNEL);
		for (i = 0; i < TOPAZHP_MAX_POSSIBLE_STREAMS; i++) {
			fw_ctx->mtx_context_data_copy[i] = osa_malloc(sizeof(struct vidio_ddbufinfo), OSA_GFP_KERNEL);
			if (fw_ctx->mtx_context_data_copy[i] == NULL)
				goto alloc_failed;

			if (topaz_mmu_alloc(ctx->topaz_mmu_ctx.mmu_context_handle,
				      ctx->vxe_arg, MMU_GENERAL_HEAP_ID, 1,
				      (enum sys_emem_attrib)(SYS_MEMATTRIB_UNCACHED | SYS_MEMATTRIB_WRITECOMBINE),
				      MTX_CONTEXT_SIZE, 64,
				      fw_ctx->mtx_context_data_copy[i])) {
				OSA_PR_ERR("mmu_alloc for data copy failed!\n");
				osa_free(fw_ctx->mtx_context_data_copy[i]);
				fw_ctx->mtx_context_data_copy[i] = NULL;
				goto alloc_failed;
			}
		}

		fw_ctx->dev_ctx = dev_ctx;
		fw_ctx->initialized = osa_true;
	}

	return;

alloc_failed:
	while (i > 0) {
		topaz_mmu_free(ctx->vxe_arg, fw_ctx->mtx_context_data_copy[i-1]);
		osa_free(fw_ctx->mtx_context_data_copy[i-1]);
		fw_ctx->mtx_context_data_copy[i-1] = NULL;
		i--;
	}
}

int32 mtx_get_fw_config_int(struct img_fw_context const * const fw_ctx,
			    osa_char const * const name)
{
	const size_t max_len = 1024;
	unsigned int ii;

	if (fw_ctx->mtx_topaz_fw_data_size == 0) {
		IMG_DBG_ASSERT("FW context structure is not initialised!" == NULL);
		return -1;
	}

	for (ii = 0; ii < fw_ctx->int_defines.length; ii++) {
		if (osa_strncmp(fw_ctx->int_defines.names[ii],
		    name, max_len) == 0) {
			return fw_ctx->int_defines.values[ii];
		}
	}

	return -1;
}

/*
 * Start an MTX.
 * @Input    fw_ctx       : Pointer to the context of the target MTX
 */
void mtx_start(struct img_fw_context * fw_ctx)
{
	IMG_DBG_ASSERT(fw_ctx->initialized);
	if (!fw_ctx->initialized)
		return;

	/* target only the current MTX */
	mtx_set_target(fw_ctx);

	/* Turn on the thread */
	VXE_WR_REG32(fw_ctx->mtx_reg_mem_space_addr, MTX_CR_MTX_ENABLE,
		     MASK_MTX_MTX_ENABLE);
}

/*
 * Stop an MTX.
 * @Input    fw_ctx       : Pointer to the context of the target MTX
 */
void mtx_stop(struct img_fw_context * fw_ctx)
{
	IMG_DBG_ASSERT(fw_ctx->initialized);

	/* target only the current MTX */
	mtx_set_target(fw_ctx);

	/*
	 * Turn off the thread by writing one to the MTX_TOFF field of the MTX_ENABLE
	 * register.
	 */
	VXE_WR_REG32(fw_ctx->mtx_reg_mem_space_addr, MTX_CR_MTX_ENABLE,
		     MASK_MTX_MTX_TOFF);
}

/*
 * Kick an MTX.
 * @Input    fw_ctx     : Pointer to the context of the target MTX
 * @Input    kick_count : The number of kicks to register
 */
void mtx_kick(struct img_fw_context *fw_ctx, uint32 kick_count)
{
	IMG_DBG_ASSERT(fw_ctx->initialized);
	if (!fw_ctx->initialized)
		return;

	/* target only the current MTX */
	mtx_set_target(fw_ctx);

	VXE_WR_REG32(fw_ctx->mtx_reg_mem_space_addr, MTX_CR_MTX_KICK,
		     kick_count);
}

/*
 * Wait for MTX to halt
 * @Input    fw_ctx        : Pointer to the MTX context
 */
void mtx_wait_for_completion(struct img_fw_context *fw_ctx)
{
	IMG_DBG_ASSERT(fw_ctx->initialized);

	if (MTX_LOADMETHOD_NONE != fw_ctx->load_method) {
		/* target only the current MTX */
		mtx_set_target(fw_ctx);

		/* Wait for the Completion */
		VXE_POLL_REG32_ISEQ(fw_ctx->mtx_reg_mem_space_addr,
				    MTX_CR_MTX_ENABLE, MASK_MTX_MTX_TOFF,
				    (MASK_MTX_MTX_TOFF | MASK_MTX_MTX_ENABLE),
				    TAL_REG_RD_WR_TRIES);
	}
}

uint32 poll_hw_inactive(struct img_fw_context * fw_ctx)
{
	return VXE_POLL_REG32_ISEQ(fw_ctx->topaz_multicore_reg_addr,
				   MTX_SCRATCHREG_IDLE,
				   F_ENCODE(FW_IDLE_STATUS_IDLE, FW_IDLE_REG_STATUS),
				   MASK_FW_IDLE_REG_STATUS,
				   TAL_REG_RD_WR_TRIES);
}
