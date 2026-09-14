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

#include "osal/inc/osa_types.h"
#include "osal/inc/osa_mem.h"
#include "osal/inc/osa_define.h"
#include "decoder.h"
#include "hw_control.h"
#include "img_msvdx_mtx_regs.h"
#include "img_msvdx_vdmc_regs.h"
#include "img_pvdec_core_regs.h"
#include "img_pvdec_entropy_regs.h"
#include "img_pvdec_pixel_regs.h"
#include "img_pvdec_test_regs.h"
#include "img_vdec_fw_msg.h"
#include "img_video_bus4_mmu_regs.h"
#include "img_msvdx_core_regs.h"
#include "reg_io2.h"
#include "vdecdd_defs.h"
#include "vxd_dec.h"
#include "vxd_ext.h"
#include "vxd_int.h"
#include "vxd_pvdec_priv.h"

#define MSG_GROUP_MASK  0xf0

struct hwctrl_ctx {
	uint32 is_initialised;
	uint32 is_on_seq_replay;
	uint32 replay_tid;
	uint32 num_pipes;
	struct vdecdd_dd_devconfig devconfig;
	void *hndl_vxd;
	void *dec_core;
	void *comp_init_userdata;
	struct vidio_ddbufinfo dev_ptd_bufinfo;
	struct lst_t pend_pict_list;
	struct hwctrl_msgstatus host_msg_status;
	void *hmsg_task_event;
	void *hmsg_task_kick;
	void *hmsg_task;
	uint32 is_msg_task_active;
	struct hwctrl_state state;
	struct hwctrl_state prev_state;
	uint32 is_prev_hw_state_set;
	uint32 is_fatal_state;
};

struct vdeckm_context {
	uint32 core_num;
	struct vxd_coreprops props;
	uint16 current_msgid;
	uint8 reader_active;
	void *comms_ram_addr;
	uint32 state_offset;
	uint32 state_size;
};

/*
 * Panic reason identifier.
 */
enum pvdec_panic_reason {
	PANIC_REASON_OTHER = 0,
	PANIC_REASON_WDT,
	PANIC_REASON_READ_TIMEOUT,
	PANIC_REASON_CMD_TIMEOUT,
	PANIC_REASON_MMU_FAULT,
	PANIC_REASON_MAX,
	PANIC_REASON_FORCE32BITS = 0x7FFFFFFFU
};

/*
 * Panic reason strings.
 * NOTE: Should match the pvdec_panic_reason ids.
 */
static char *apanic_reason[PANIC_REASON_MAX] = {
	[PANIC_REASON_OTHER] = "Other",
	[PANIC_REASON_WDT] = "Watch Dog Timeout",
	[PANIC_REASON_READ_TIMEOUT] = "Read Timeout",
	[PANIC_REASON_CMD_TIMEOUT] = "Command Timeout",
	[PANIC_REASON_MMU_FAULT] = "MMU Page Fault"
};

#ifdef ERROR_RECOVERY_SIMULATION
extern int disable_fw_irq_value;
#endif

/*
 * Maximum length of the panic reason string.
 */
#define PANIC_REASON_LEN  (255)

static struct vdeckm_context acore_ctx[VXD_MAX_CORES] = {0};

static int32 vdeckm_getregsoffsets(const void *hndl_vxd,
				 struct decoder_regsoffsets *regs_offsets)
{
	struct vdeckm_context *core_ctx = (struct vdeckm_context *)hndl_vxd;

	if (!core_ctx)
		return IMG_ERROR_INVALID_PARAMETERS;

	regs_offsets->vdmc_cmd_offset = MSVDX_CMD_OFFSET;
	regs_offsets->vec_offset = MSVDX_VEC_OFFSET;
	regs_offsets->entropy_offset = PVDEC_ENTROPY_OFFSET;
	regs_offsets->vec_be_regs_offset = PVDEC_VEC_BE_OFFSET;
	regs_offsets->vdec_be_codec_regs_offset = PVDEC_VEC_BE_CODEC_OFFSET;

	return IMG_SUCCESS;
}

static int32 vdeckm_send_message(const void *hndl_vxd,
			       struct hwctrl_to_kernel_msg *to_kernelmsg,
			       void *vxd_dec_ctx)
{
	struct vdeckm_context *core_ctx = (struct vdeckm_context *)hndl_vxd;
	uint32 count = 0;
	uint32 *msg;

	if (!core_ctx || !to_kernelmsg)
		return IMG_ERROR_INVALID_PARAMETERS;

	msg = osa_zalloc(VXD_SIZE_MSG_BUFFER, OSA_GFP_KERNEL);
	if (!msg)
		return IMG_ERROR_OUT_OF_MEMORY;

	msg[count++] = to_kernelmsg->flags;
	msg[count++] = to_kernelmsg->msg_size;

	memcpy(&msg[count], to_kernelmsg->msg_hdr, to_kernelmsg->msg_size);

	core_ctx->reader_active = 1;

	if (!(to_kernelmsg->msg_hdr)) {
		osa_free(msg);
		return IMG_ERROR_INVALID_PARAMETERS;
	}

	OSA_PR_DEBUG("[HWCTRL] adding message to vxd queue\n");
	vxd_send_msg(vxd_dec_ctx, (struct vxd_fw_msg *)msg);

	osa_free(msg);

	return 0;
}

static void vdeckm_return_msg(const void *hndl_vxd,
			      struct hwctrl_to_kernel_msg *to_kernelmsg)
{
	if (to_kernelmsg)
		osa_free(to_kernelmsg->msg_hdr);
}

static int32 vdeckm_handle_mtxtohost_msg(uint32 *msg, struct lst_t *pend_pict_list,
				       enum vxd_msg_attr *msg_attr,
				       struct dec_decpict  **decpict,
				       uint8 msg_type, uint32 trans_id)
{
	struct dec_decpict *pdec_pict;

	switch (msg_type) {
	case FW_DEVA_COMPLETED:
	{
	struct dec_pict_attrs *pict_attrs = NULL;
	uint16 error_flags = 0;
	uint32 no_bewdts = 0;
	uint32 mbs_dropped = 0;
	uint32 mbs_recovered = 0;
	osa_bool flag = 0;

	OSA_PR_DEBUG("Received message from firmware\n");
	error_flags = MEMIO_READ_FIELD(msg, FW_DEVA_COMPLETED_ERROR_FLAGS);

	no_bewdts = MEMIO_READ_FIELD(msg, FW_DEVA_COMPLETED_NUM_BEWDTS);

	mbs_dropped = MEMIO_READ_FIELD(msg, FW_DEVA_COMPLETED_NUM_MBSDROPPED);

	mbs_recovered = MEMIO_READ_FIELD(msg,
					 FW_DEVA_COMPLETED_NUM_MBSRECOVERED);

	pdec_pict = lst_first(pend_pict_list);
	while (pdec_pict) {
		if (pdec_pict->transaction_id == trans_id)
			break;
		pdec_pict = lst_next(pdec_pict);
	}
	/*
	 * We must have a picture in the list that matches
	 * the transaction id
	 */
	if (!pdec_pict)
		return IMG_ERROR_FATAL;
	if (!(pdec_pict->first_fld_fwmsg) ||
	    !(pdec_pict->second_fld_fwmsg))
		return IMG_ERROR_FATAL;
	flag =
	pdec_pict->first_fld_fwmsg->pict_attrs.first_fld_rcvd;
	if (flag) {
		pict_attrs =
		&pdec_pict->second_fld_fwmsg->pict_attrs;
	} else {
		pict_attrs =
		&pdec_pict->first_fld_fwmsg->pict_attrs;
		flag = 1;
	}
		pict_attrs->fe_err = (uint32)error_flags;
	pict_attrs->no_be_wdt = no_bewdts;
	pict_attrs->mbs_dropped = mbs_dropped;
	pict_attrs->mbs_recovered = mbs_recovered;
	/*
	 * We may successfully replayed the picture,
	 * so reset the error flags
	 */
	pict_attrs->pict_attrs.dwrfired = 0;
	pict_attrs->pict_attrs.mmufault = 0;
	pict_attrs->pict_attrs.deverror = 0;

	*msg_attr = VXD_MSG_ATTR_DECODED;
	*decpict = pdec_pict;
	break;
	}

	case FW_DEVA_PANIC:
	{
	uint32  panic_info =  MEMIO_READ_FIELD(msg, FW_DEVA_PANIC_ERROR_INT);
	char panic_reason[PANIC_REASON_LEN] = "Reason(s): ";
	uint8   is_panic_reson_identified = 0;
	/*
	 * Create panic reason string.
	 */
	if (REGIO_READ_FIELD(panic_info, PVDEC_CORE,
			     CR_PVDEC_HOST_INTERRUPT_STATUS,
			     CR_HOST_SYS_WDT)) {
		strncat(panic_reason,
			apanic_reason[PANIC_REASON_WDT],
			PANIC_REASON_LEN - 1);
		is_panic_reson_identified = 1;
	}
	if (REGIO_READ_FIELD(panic_info, PVDEC_CORE,
			     CR_PVDEC_HOST_INTERRUPT_STATUS,
			     CR_HOST_READ_TIMEOUT_PROC_IRQ)) {
		strncat(panic_reason,
			apanic_reason
			[PANIC_REASON_READ_TIMEOUT],
			PANIC_REASON_LEN - 1);
		is_panic_reson_identified = 1;
	}
	if (REGIO_READ_FIELD(panic_info, PVDEC_CORE,
			     CR_PVDEC_HOST_INTERRUPT_STATUS,
			     CR_HOST_COMMAND_TIMEOUT_PROC_IRQ)){
		strncat(panic_reason,
			apanic_reason[PANIC_REASON_CMD_TIMEOUT],
			PANIC_REASON_LEN - 1);
		is_panic_reson_identified = 1;
	}
	if (!is_panic_reson_identified) {
		strncat(panic_reason,
			apanic_reason[PANIC_REASON_OTHER],
			PANIC_REASON_LEN - 1);
	}
	panic_reason[strlen(panic_reason) - 2] = 0;
	if (trans_id != 0)
		OSA_PR_ERR("TID=0x%08X [FIRMWARE PANIC %s]\n",
		       trans_id, panic_reason);
	else
		OSA_PR_ERR("TID=NULL [GENERAL FIRMWARE PANIC %s]\n",
		       panic_reason);

	break;
	}

	case FW_ASSERT:
	{
	uint32 fwfile_namehash = MEMIO_READ_FIELD(msg, FW_ASSERT_FILE_NAME_HASH);
	uint32 fwfile_line = MEMIO_READ_FIELD(msg, FW_ASSERT_FILE_LINE);

	OSA_PR_ERR("ASSERT file name hash:0x%08X line number:%d\n",
	       fwfile_namehash, fwfile_line);
	break;
	}

	case FW_SO:
	{
	uint32 task_name = MEMIO_READ_FIELD(msg, FW_SO_TASK_NAME);
	uint8 sztaskname[sizeof(uint32) + 1];

	sztaskname[0] = task_name >> 24;
	sztaskname[1] = (task_name >> 16) & 0xff;
	sztaskname[2] = (task_name >> 8) & 0xff;
	sztaskname[3] = task_name & 0xff;
	if (sztaskname[3] != 0)
	{
		sztaskname[4] = 0;
	}
	OSA_PR_WARN("STACK OVERFLOW for %s task\n", sztaskname);
	break;
	}

	case FW_VXD_EMPTY_COMPL:
	/*
	 * Empty completion message sent as response to init,
	 * configure etc The architecture of vxd.ko module
	 * requires the firmware to send a reply for every
	 * message submitted by the user space.
	 */
	break;

	default:
	break;
	}

	return 0;
}

static int32 vdeckm_handle_hosttomtx_msg(uint32 *msg, struct lst_t *pend_pict_list,
				       enum vxd_msg_attr *msg_attr,
				       struct dec_decpict  **decpict,
				       uint8 msg_type, uint32 trans_id,
				       uint32 msg_flags)
{
	struct dec_decpict *pdec_pict;

    OSA_PR_DEBUG("Received message from HOST \n");

	switch (msg_type) {
	case FW_DEVA_PARSE:
	{
	struct dec_pict_attrs *pict_attrs = NULL;
	osa_bool flag = 0;

	pdec_pict = lst_first(pend_pict_list);
	while (pdec_pict) {
		if (pdec_pict->transaction_id == trans_id)
			break;

		pdec_pict = lst_next(pdec_pict);
	}

	/*
	 * We must have a picture in the list that matches
	 * the transaction id
	 */
	if (!pdec_pict) {
		OSA_PR_ERR("Firmware decoded message received\n");
		OSA_PR_ERR("no pending picture\n");
		return IMG_ERROR_FATAL;
	}

	if (!(pdec_pict->first_fld_fwmsg) ||
	    !(pdec_pict->second_fld_fwmsg)) {
		OSA_PR_ERR("invalid pending picture struct\n");
		return IMG_ERROR_FATAL;
	}

	flag =
	pdec_pict->first_fld_fwmsg->pict_attrs.first_fld_rcvd;
	if (flag) {
		pict_attrs =
		&pdec_pict->second_fld_fwmsg->pict_attrs;
	} else {
		pict_attrs =
		&pdec_pict->first_fld_fwmsg->pict_attrs;
		flag = 1;
	}

	/*
	 * The below info is fetched from firmware state
	 * afterwards, so just set this to zero for now.
	 */
	pict_attrs->fe_err = 0;
	pict_attrs->no_be_wdt = 0;
	pict_attrs->mbs_dropped = 0;
	pict_attrs->mbs_recovered = 0;

	vxd_get_pictattrs(msg_flags, &pict_attrs->pict_attrs);
	vxd_get_msgerrattr(msg_flags, msg_attr);

	if (*msg_attr == VXD_MSG_ATTR_FATAL)
		OSA_PR_ERR("[TID=0x%08X] [DECODE_FAILED]\n",
		       trans_id);
	if (*msg_attr == VXD_MSG_ATTR_CANCELED)
		OSA_PR_ERR("[TID=0x%08X] [DECODE_CANCELED]\n",
		       trans_id);

	*decpict = pdec_pict;
	break;
	}

	case FW_DEVA_PARSE_FRAGMENT:
	/*
	 * Do nothing - Picture holds the list of fragments.
	 * So, in case of any error those would be replayed
	 * anyway.
	 */
	break;
	default:
	OSA_PR_WARN("Unknown message received 0x%02x\n", msg_type);
	break;
	}

	return 0;
}

static int32 vdeckm_process_msg(const void *hndl_vxd, uint32 *msg,
			      struct lst_t *pend_pict_list, uint32 msg_flags,
			      enum vxd_msg_attr *msg_attr,
			      struct dec_decpict  **decpict)
{
	struct vdeckm_context *core_ctx = (struct vdeckm_context *)hndl_vxd;
	uint8 msg_type;
	uint8 msg_group;
	uint32 trans_id = 0;
	struct vdec_pict_hwcrc *pict_hwcrc = NULL;
	struct dec_decpict *pdec_pict;

	if (!core_ctx || !msg || !msg_attr || !pend_pict_list || !decpict)
		return IMG_ERROR_INVALID_PARAMETERS;

	*msg_attr = VXD_MSG_ATTR_NONE;
	*decpict = NULL;

	trans_id = MEMIO_READ_FIELD(msg, FW_DEVA_GENMSG_TRANS_ID);
	msg_type  = MEMIO_READ_FIELD(msg, FW_DEVA_GENMSG_MSG_TYPE);
	msg_group = msg_type & MSG_GROUP_MASK;

	switch (msg_group) {
	case MSG_TYPE_START_PSR_MTXHOST_MSG:
		vdeckm_handle_mtxtohost_msg(msg, pend_pict_list, msg_attr,
					    decpict, msg_type, trans_id);
		break;
	/*
	 * Picture decode has been returned as unprocessed.
	 * Locate the picture with corresponding TID and mark
	 * it as decoded with errors.
	 */
	case MSG_TYPE_START_PSR_HOSTMTX_MSG:
		vdeckm_handle_hosttomtx_msg(msg, pend_pict_list, msg_attr,
					    decpict, msg_type, trans_id,
					    msg_flags);
		break;

	case FW_DEVA_SIGNATURES_HEVC:
	case FW_DEVA_SIGNATURES_LEGACY:
	{
		uint32 *signatures = msg + (FW_DEVA_SIGNATURES_SIGNATURES_OFFSET / sizeof(uint32));
		uint8 sigcount  = MEMIO_READ_FIELD(msg, FW_DEVA_SIGNATURES_MSG_SIZE) -
				((FW_DEVA_SIGNATURES_SIZE / sizeof(uint32)) - 1);
		uint32 selected = MEMIO_READ_FIELD(msg, FW_DEVA_SIGNATURES_SIGNATURE_SELECT);
		uint8 i, j = 0;

		pdec_pict = lst_first(pend_pict_list);
		while (pdec_pict) {
			if (pdec_pict->transaction_id == trans_id)
				break;
			pdec_pict = lst_next(pdec_pict);
		}

		/* We must have a picture in the list that matches the tid */
		VDEC_ASSERT(pdec_pict);
		if (!pdec_pict) {
			OSA_PR_ERR("Firmware signatures message received with no pending picture\n");
			return IMG_ERROR_FATAL;
		}

		VDEC_ASSERT(pdec_pict->first_fld_fwmsg);
		VDEC_ASSERT(pdec_pict->second_fld_fwmsg);
		if (!pdec_pict->first_fld_fwmsg || !pdec_pict->second_fld_fwmsg) {
			OSA_PR_ERR("Invalid pending picture struct\n");
			return IMG_ERROR_FATAL;
		}
		if (pdec_pict->first_fld_fwmsg->pict_hwcrc.first_fld_rcvd) {
			pict_hwcrc = &pdec_pict->second_fld_fwmsg->pict_hwcrc;
		} else {
			pict_hwcrc = &pdec_pict->first_fld_fwmsg->pict_hwcrc;
			if (selected & (PVDEC_SIGNATURE_GROUP_20 | PVDEC_SIGNATURE_GROUP_24))
				pdec_pict->first_fld_fwmsg->pict_hwcrc.first_fld_rcvd = osa_true;
		}

		for (i = 0; i < 32; i++) {
			uint32 group = selected & (1 << i);

			switch (group) {
			case PVDEC_SIGNATURE_GROUP_20:
				pict_hwcrc->crc_vdmc_pix_recon = signatures[j++];
				break;

			case PVDEC_SIGNATURE_GROUP_24:
				pict_hwcrc->vdeb_sysmem_wrdata = signatures[j++];
				break;

			default:
				break;
			}
		}

		/* sanity check */
		sigcount -= j;
		VDEC_ASSERT(sigcount == 0);

		/*
		 * suppress PVDEC_SIGNATURE_GROUP_1 and notify
		 * only about groups used for verification
		 */
		if (selected & (PVDEC_SIGNATURE_GROUP_20 | PVDEC_SIGNATURE_GROUP_24))
			OSA_PR_INFO("[TID=0x%08X] [SIGNATURES]\n", trans_id);

		*decpict = pdec_pict;

		break;
	}

	default: {
		uint16 msg_size, i;

		OSA_PR_WARN("Unknown message type received: 0x%x",
			msg_type);

		msg_size = MEMIO_READ_FIELD(msg,
					    FW_DEVA_GENMSG_MSG_SIZE);

		for (i = 0; i < msg_size; i++)
			OSA_PR_INFO("0x%04x: 0x%08x\n", i, msg[i]);
		break;
	}
	}

	return 0;
}

static void vdeckm_vlr_copy(void *dst, void *src, uint32 size)
{
	uint32 *pdst = (uint32 *)dst;
	uint32 *psrc = (uint32 *)src;

	size /= 4;
	while (size--)
		*pdst++ = *psrc++;
}

static int32 vdeckm_get_core_state(const void *hndl_vxd, struct vxd_states *state)
{
	struct vdeckm_context *core_ctx = (struct vdeckm_context *)hndl_vxd;
	struct vdecfw_pvdecfirmwarestate firmware_state;
	uint8 pipe = 0;

#ifdef ERROR_RECOVERY_SIMULATION
	/*
	 * if disable_fw_irq_value is not zero, return error. If processed further
	 * the kernel will crash because we have ignored the interrupt, but here
	 * we will try to access comms_ram_addr which will result in crash.
	 */
	if (disable_fw_irq_value != 0)
		return IMG_ERROR_INVALID_PARAMETERS;
#endif

	if (!core_ctx || !state)
		return IMG_ERROR_INVALID_PARAMETERS;

	/*
	 * If state is requested for the first time.
	 */
	if (core_ctx->state_size == 0) {
		uint32 regval;
		/*
		 * get the state buffer info.
		 */
		regval = *((uint32 *)core_ctx->comms_ram_addr +
			(PVDEC_COM_RAM_STATE_BUF_SIZE_AND_OFFSET_OFFSET / sizeof(uint32)));
		core_ctx->state_size =
			PVDEC_COM_RAM_BUF_GET_SIZE(regval, STATE);
		core_ctx->state_offset =
			PVDEC_COM_RAM_BUF_GET_OFFSET(regval, STATE);
	}

	/*
	 * If state buffer is available.
	 */
	if (core_ctx->state_size) {
		/*
		 * Determine the latest transaction to have passed each
		 * checkpoint in the firmware.
		 * Read the firmware state from VEC Local RAM
		 */
		vdeckm_vlr_copy(&firmware_state,
				(uint8 *)core_ctx->comms_ram_addr +
				core_ctx->state_offset,
				core_ctx->state_size);

		for (pipe = 0; pipe < core_ctx->props.num_pixel_pipes; pipe++) {
			/*
			 * Set pipe presence.
			 */
			state->fw_state.pipe_state[pipe].is_pipe_present = 1;

			/*
			 * For checkpoints copy message ids here. These will
			 * be translated into transaction ids later.
			 */
			memcpy(state->fw_state.pipe_state[pipe].acheck_point,
			       firmware_state.pipestate[pipe].check_point,
			sizeof(state->fw_state.pipe_state[pipe].acheck_point));
			state->fw_state.pipe_state[pipe].firmware_action  =
				firmware_state.pipestate[pipe].firmware_action;
			state->fw_state.pipe_state[pipe].cur_codec =
				firmware_state.pipestate[pipe].curr_codec;
			state->fw_state.pipe_state[pipe].fe_slices =
				firmware_state.pipestate[pipe].fe_slices;
			state->fw_state.pipe_state[pipe].be_slices =
				firmware_state.pipestate[pipe].be_slices;
			state->fw_state.pipe_state[pipe].fe_errored_slices =
			firmware_state.pipestate[pipe].fe_errored_slices;
			state->fw_state.pipe_state[pipe].be_errored_slices =
			firmware_state.pipestate[pipe].be_errored_slices;
			state->fw_state.pipe_state[pipe].be_mbs_dropped =
				firmware_state.pipestate[pipe].be_mbs_dropped;
			state->fw_state.pipe_state[pipe].be_mbs_recovered =
			firmware_state.pipestate[pipe].be_mbs_recovered;
			state->fw_state.pipe_state[pipe].fe_mb.x =
			firmware_state.pipestate[pipe].last_fe_mb_xy & 0xFF;
			state->fw_state.pipe_state[pipe].fe_mb.y =
				(firmware_state.pipestate[pipe].last_fe_mb_xy >> 16)
			& 0xFF;
			state->fw_state.pipe_state[pipe].be_mb.x =
				REGIO_READ_FIELD(firmware_state.pipestate[pipe].last_be_mb_xy,
						 MSVDX_VDMC,
						 CR_VDMC_MACROBLOCK_NUMBER,
						 CR_VDMC_MACROBLOCK_X_OFFSET);
			state->fw_state.pipe_state[pipe].be_mb.y =
				REGIO_READ_FIELD(firmware_state.pipestate[pipe].last_be_mb_xy,
						 MSVDX_VDMC,
						 CR_VDMC_MACROBLOCK_NUMBER,
						 CR_VDMC_MACROBLOCK_Y_OFFSET);
		}
	}

	return 0;
}

static int32 vdeckm_prepare_batch(struct vdeckm_context *core_ctx,
				const struct hwctrl_batch_msgdata *batch_msgdata
				, uint8 **msg)
{
	uint8 vdec_flags = 0;
	uint16 flags = 0;
	uint8 *pmsg = osa_zalloc(FW_DEVA_DECODE_SIZE, OSA_GFP_KERNEL);
	struct vidio_ddbufinfo *pbatch_msg_bufinfo =
			batch_msgdata->batchmsg_bufinfo;

	if (!pmsg)
		return IMG_ERROR_MALLOC_FAILED;

	if (batch_msgdata->size_delimited_mode)
		vdec_flags |= FW_VDEC_NAL_SIZE_DELIM;

	flags |= FW_DEVA_RENDER_HOST_INT;

	/*
	 * Message type and stream ID
	 */
	MEMIO_WRITE_FIELD(pmsg, FW_DEVA_GENMSG_MSG_TYPE, FW_DEVA_PARSE, uint8*);

	MEMIO_WRITE_FIELD(pmsg, FW_DEVA_DECODE_CTRL_ALLOC_ADDR,
			  (uint32)pbatch_msg_bufinfo->dev_virt, uint8*);

	MEMIO_WRITE_FIELD(pmsg, FW_DEVA_DECODE_BUFFER_SIZE,
			  batch_msgdata->ctrl_alloc_bytes / sizeof(uint32), uint8*);

	/*
	 * Operating mode and decode flags
	 */
	MEMIO_WRITE_FIELD(pmsg, FW_DEVA_DECODE_OPERATING_MODE,
			  batch_msgdata->operating_mode, uint8*);

	MEMIO_WRITE_FIELD(pmsg, FW_DEVA_DECODE_FLAGS, flags, uint8*);

	MEMIO_WRITE_FIELD(pmsg, FW_DEVA_DECODE_VDEC_FLAGS, vdec_flags, uint8*);

	MEMIO_WRITE_FIELD(pmsg, FW_DEVA_DECODE_GENC_ID, batch_msgdata->genc_id, uint8*);

	MEMIO_WRITE_FIELD(pmsg, FW_DEVA_DECODE_MB_LOAD, batch_msgdata->mb_load, uint8*);

	MEMIO_WRITE_FIELD(pmsg, FW_DEVA_DECODE_STREAMID,
			  GET_STREAM_ID(batch_msgdata->transaction_id), uint8*);

	MEMIO_WRITE_FIELD(pmsg, FW_DEVA_DECODE_EXT_STATE_BUFFER,
			  (uint32)batch_msgdata->pvdec_fwctx->dev_virt, uint8*);

	MEMIO_WRITE_FIELD(pmsg, FW_DEVA_DECODE_MSG_ID,
			  ++core_ctx->current_msgid, uint8*);

	MEMIO_WRITE_FIELD(pmsg, FW_DEVA_DECODE_TRANS_ID,
			  batch_msgdata->transaction_id, uint8*);

	MEMIO_WRITE_FIELD(pmsg, FW_DEVA_DECODE_TILE_CFG,
			  batch_msgdata->tile_cfg, uint8*);

	/*
	 * size of message
	 */
	MEMIO_WRITE_FIELD(pmsg, FW_DEVA_GENMSG_MSG_SIZE,
			  FW_DEVA_DECODE_SIZE / sizeof(uint32), uint8*);

	*msg = pmsg;

	return 0;
}

static int32 vdeckm_prepare_fragment(struct vdeckm_context *core_ctx,
				   const struct hwctrl_fragment_msgdata
				   *fragment_msgdata,
				   uint8 **msg)
{
	struct vidio_ddbufinfo *pbatch_msg_bufinfo = NULL;
	uint8 *pmsg = NULL;

	pbatch_msg_bufinfo = fragment_msgdata->batchmsg_bufinfo;

	if (!(fragment_msgdata->batchmsg_bufinfo)) {
		OSA_PR_ERR("Batch message info missing!\n");
		return IMG_ERROR_INVALID_PARAMETERS;
	}

	pmsg = osa_zalloc(FW_DEVA_DECODE_FRAGMENT_SIZE, OSA_GFP_KERNEL);
	if (!pmsg)
		return IMG_ERROR_MALLOC_FAILED;
	/*
	 * message type and stream id
	 */
	MEMIO_WRITE_FIELD(pmsg, FW_DEVA_GENMSG_MSG_TYPE,
			  FW_DEVA_PARSE_FRAGMENT, uint8*);
	MEMIO_WRITE_FIELD(pmsg, FW_DEVA_DECODE_MSG_ID,
			  ++core_ctx->current_msgid, uint8*);

	MEMIO_WRITE_FIELD(pmsg, FW_DEVA_DECODE_FRAGMENT_CTRL_ALLOC_ADDR,
			  (uint32)pbatch_msg_bufinfo->dev_virt
			  + fragment_msgdata->ctrl_alloc_offset, uint8*);
	MEMIO_WRITE_FIELD(pmsg, FW_DEVA_DECODE_FRAGMENT_BUFFER_SIZE,
			  fragment_msgdata->ctrl_alloc_bytes / sizeof(uint32), uint8*);

	/*
	 * size of message
	 */
	MEMIO_WRITE_FIELD(pmsg, FW_DEVA_GENMSG_MSG_SIZE,
			  FW_DEVA_DECODE_FRAGMENT_SIZE / sizeof(uint32), uint8*);

	*msg = pmsg;

	return 0;
}

static int32 vdeckm_get_message(const void *hndl_vxd,
			      const enum hwctrl_msgid msgid,
			      const struct hwctrl_msgdata *msgdata,
			      struct hwctrl_to_kernel_msg *to_kernelmsg)
{
	uint32 result = 0;
	struct vdeckm_context *core_ctx = (struct vdeckm_context *)hndl_vxd;

	if (!core_ctx || !to_kernelmsg || !msgdata)
		return IMG_ERROR_INVALID_PARAMETERS;

	switch (msgid) {
	case HWCTRL_MSGID_BATCH:
		result = vdeckm_prepare_batch(core_ctx, &msgdata->batch_msgdata,
					      &to_kernelmsg->msg_hdr);
		break;

	case HWCTRL_MSGID_FRAGMENT:
		result = vdeckm_prepare_fragment(core_ctx,
						 &msgdata->fragment_msgdata,
						 &to_kernelmsg->msg_hdr);
		vxd_set_msgflag(VXD_MSG_FLAG_DROP, &to_kernelmsg->flags);
		break;

	default:
		result = IMG_ERROR_GENERIC_FAILURE;
		OSA_PR_ERR("got a message that is not supported by PVDEC");
		break;
	}

	if (result == 0) {
		/* Set the stream ID for the next message to be sent. */
		to_kernelmsg->km_str_id = msgdata->km_str_id;
		to_kernelmsg->msg_size =
		MEMIO_READ_FIELD(to_kernelmsg->msg_hdr,
				 FW_DEVA_GENMSG_MSG_SIZE) * sizeof(uint32);
	}

	return result;
}

static void hwctrl_dump_state(struct vxd_states *prev_state,
			      struct vxd_states *cur_state,
			      uint8 pipe_minus1)
{
	OSA_PR_INFO("Back-End MbX                          [% 10d]",
		prev_state->fw_state.pipe_state[pipe_minus1].be_mb.x);
	OSA_PR_INFO("Back-End MbY                          [% 10d]",
		prev_state->fw_state.pipe_state[pipe_minus1].be_mb.y);
	OSA_PR_INFO("Front-End MbX                         [% 10d]",
		prev_state->fw_state.pipe_state[pipe_minus1].fe_mb.x);
	OSA_PR_INFO("Front-End MbY                         [% 10d]",
		prev_state->fw_state.pipe_state[pipe_minus1].fe_mb.y);
	OSA_PR_INFO("VDECFW_CHECKPOINT_BE_PICTURE_COMPLETE [0x%08X]",
		cur_state->fw_state.pipe_state[pipe_minus1].acheck_point
		[VDECFW_CHECKPOINT_BE_PICTURE_COMPLETE]);
	OSA_PR_INFO("VDECFW_CHECKPOINT_BE_1SLICE_DONE      [0x%08X]",
		cur_state->fw_state.pipe_state[pipe_minus1].acheck_point
		[VDECFW_CHECKPOINT_BE_1SLICE_DONE]);
	OSA_PR_INFO("VDECFW_CHECKPOINT_BE_PICTURE_STARTED  [0x%08X]",
		cur_state->fw_state.pipe_state[pipe_minus1].acheck_point
		[VDECFW_CHECKPOINT_BE_PICTURE_STARTED]);
	OSA_PR_INFO("VDECFW_CHECKPOINT_FE_PICTURE_COMPLETE [0x%08X]",
		cur_state->fw_state.pipe_state[pipe_minus1].acheck_point
		[VDECFW_CHECKPOINT_FE_PICTURE_COMPLETE]);
	OSA_PR_INFO("VDECFW_CHECKPOINT_FE_PARSE_DONE       [0x%08X]",
		cur_state->fw_state.pipe_state[pipe_minus1].acheck_point
		[VDECFW_CHECKPOINT_FE_PARSE_DONE]);
	OSA_PR_INFO("VDECFW_CHECKPOINT_FE_1SLICE_DONE      [0x%08X]",
		cur_state->fw_state.pipe_state[pipe_minus1].acheck_point
		[VDECFW_CHECKPOINT_FE_1SLICE_DONE]);
	OSA_PR_INFO("VDECFW_CHECKPOINT_ENTDEC_STARTED      [0x%08X]",
		cur_state->fw_state.pipe_state[pipe_minus1].acheck_point
		[VDECFW_CHECKPOINT_ENTDEC_STARTED]);
	OSA_PR_INFO("VDECFW_CHECKPOINT_FIRMWARE_SAVED      [0x%08X]",
		cur_state->fw_state.pipe_state[pipe_minus1].acheck_point
		[VDECFW_CHECKPOINT_FIRMWARE_SAVED]);
	OSA_PR_INFO("VDECFW_CHECKPOINT_PICMAN_COMPLETE     [0x%08X]",
		cur_state->fw_state.pipe_state[pipe_minus1].acheck_point
		[VDECFW_CHECKPOINT_PICMAN_COMPLETE]);
	OSA_PR_INFO("VDECFW_CHECKPOINT_FIRMWARE_READY      [0x%08X]",
		cur_state->fw_state.pipe_state[pipe_minus1].acheck_point
		[VDECFW_CHECKPOINT_FIRMWARE_READY]);
	OSA_PR_INFO("VDECFW_CHECKPOINT_PICTURE_STARTED     [0x%08X]",
		cur_state->fw_state.pipe_state[pipe_minus1].acheck_point
		[VDECFW_CHECKPOINT_PICTURE_STARTED]);
}

static uint32 hwctrl_calculate_load(struct bspp_pict_hdr_info *pict_hdr_info)
{
	return (((pict_hdr_info->coded_frame_size.width + 15) / 16)
			* ((pict_hdr_info->coded_frame_size.height + 15) / 16));
}

static int32 hwctrl_send_batch_message(struct hwctrl_ctx *hwctx,
				     struct dec_decpict *decpict,
				     void *vxd_dec_ctx)
{
	int32 result;
	struct hwctrl_to_kernel_msg to_kernelmsg = {0};
	struct vidio_ddbufinfo *batchmsg_bufinfo =
			decpict->batch_msginfo->ddbuf_info;
	struct hwctrl_msgdata msg_data;
	struct hwctrl_batch_msgdata *batch_msgdata = &msg_data.batch_msgdata;

	memset(&msg_data, 0, sizeof(msg_data));

	msg_data.km_str_id = GET_STREAM_ID(decpict->transaction_id);

	batch_msgdata->batchmsg_bufinfo  = batchmsg_bufinfo;

	batch_msgdata->transaction_id    = decpict->transaction_id;
	batch_msgdata->pvdec_fwctx       = decpict->str_pvdec_fw_ctxbuf;
	batch_msgdata->ctrl_alloc_bytes = decpict->ctrl_alloc_bytes;
	batch_msgdata->operating_mode    = decpict->operating_op;
	batch_msgdata->genc_id           = decpict->genc_id;
	batch_msgdata->mb_load           =
			hwctrl_calculate_load(decpict->pict_hdr_info);
	batch_msgdata->size_delimited_mode =
		(decpict->pict_hdr_info->parser_mode != VDECFW_SCP_ONLY) ?
		(1) : (0);

	result = vdeckm_get_message(hwctx->hndl_vxd, HWCTRL_MSGID_BATCH,
				    &msg_data, &to_kernelmsg);
	if (result != 0) {
		OSA_PR_ERR("failed to get decode message\n");
		return result;
	}

	OSA_PR_DEBUG("[HWCTRL] send batch message\n");
	result = vdeckm_send_message(hwctx->hndl_vxd, &to_kernelmsg,
				     vxd_dec_ctx);
	if (result != 0)
		return result;

	vdeckm_return_msg(hwctx->hndl_vxd, &to_kernelmsg);

	return 0;
}

int32 hwctrl_process_msg(void *hndl_hwctx, uint32 msg_flags, uint32 *msg,
		       struct dec_decpict **decpict)
{
	int32 result;
	struct hwctrl_ctx *hwctx;
	enum vxd_msg_attr msg_attr = VXD_MSG_ATTR_NONE;
	struct dec_decpict *pdecpict = NULL;
	uint32 val_first = 0;
	uint32 val_sec = 0;

	if (!hndl_hwctx || !msg || !decpict) {
		VDEC_ASSERT(0);
		return IMG_ERROR_INVALID_PARAMETERS;
	}

	hwctx = (struct hwctrl_ctx *)hndl_hwctx;

	*decpict = NULL;

	OSA_PR_DEBUG("[HWCTRL] : process message\n");
	result = vdeckm_process_msg(hwctx->hndl_vxd, msg,
				    &hwctx->pend_pict_list, msg_flags,
				    &msg_attr, &pdecpict);

	/* validate pointers before using them */
	if((!pdecpict) || (!pdecpict->first_fld_fwmsg) || (!pdecpict->second_fld_fwmsg)) {
		VDEC_ASSERT(0);
		return -OSA_EIO;
	}

	val_first = pdecpict->first_fld_fwmsg->pict_attrs.pict_attrs.deverror;
	val_sec = pdecpict->second_fld_fwmsg->pict_attrs.pict_attrs.deverror;

	if (val_first || val_sec)
		OSA_PR_ERR("device signaled critical error!!!\n");

	if (msg_attr == VXD_MSG_ATTR_DECODED) {
		pdecpict->state = DECODER_PICTURE_STATE_DECODED;
		/*
		 * We have successfully decoded a picture as normally or
		 * after the replay.
		 * Mark HW is in good state.
		 */
		hwctx->is_fatal_state = 0;
	} else if (msg_attr == VXD_MSG_ATTR_FATAL) {
		struct hwctrl_state state;
		uint8 pipe_minus1 = 0;

		memset(&state, 0, sizeof(state));
		hwctx->is_fatal_state = 1;

		result = hwctrl_get_core_status(hwctx, &state);
		if (result == 0) {
			hwctx->is_prev_hw_state_set = 1;
			memcpy(&hwctx->prev_state, &state, sizeof(struct hwctrl_state));

			for (pipe_minus1 = 0; pipe_minus1 < hwctx->num_pipes;
					pipe_minus1++) {
				hwctrl_dump_state(&state.core_state, &state.core_state,
						pipe_minus1);
			}
		}
	}
	*decpict = pdecpict;

	return 0;
}

int32 hwctrl_getcore_cached_status(void *hndl_hwctx, struct hwctrl_state *state)
{
	struct hwctrl_ctx *hwctx = (struct hwctrl_ctx *)hndl_hwctx;

	if (hwctx->is_prev_hw_state_set)
		memcpy(state, &hwctx->prev_state, sizeof(struct hwctrl_state));
	else
		return IMG_ERROR_UNEXPECTED_STATE;

	return 0;
}

int32 hwctrl_get_core_status(void *hndl_hwctx, struct hwctrl_state *state)
{
	struct hwctrl_ctx *hwctx = (struct hwctrl_ctx *)hndl_hwctx;
	uint32 result = IMG_ERROR_GENERIC_FAILURE;

	if (!hwctx->is_fatal_state && state) {
		struct vxd_states *pcorestate = NULL;

			pcorestate  = &state->core_state;

		memset(pcorestate, 0, sizeof(*(pcorestate)));

		result = vdeckm_get_core_state(hwctx->hndl_vxd, pcorestate);
	}

	return result;
}

int32 hwctrl_is_on_seq_replay(void *hndl_hwctx)
{
	struct hwctrl_ctx *hwctx = (struct hwctrl_ctx *)hndl_hwctx;

	return hwctx->is_on_seq_replay;
}

int32 hwctrl_picture_submitbatch(void *hndl_hwctx, struct dec_decpict  *decpict,
			       void *vxd_dec_ctx)
{
	struct hwctrl_ctx *hwctx = (struct hwctrl_ctx *)hndl_hwctx;

	if (hwctx->is_initialised) {
		lst_add(&hwctx->pend_pict_list, decpict);
		if (!hwctx->is_on_seq_replay)
			return hwctrl_send_batch_message(hwctx, decpict,
							 vxd_dec_ctx);
	}

	return 0;
}

int32 hwctrl_getpicpend_pictlist(void *hndl_hwctx, uint32 transaction_id,
			       struct dec_decpict  **decpict)
{
	struct hwctrl_ctx *hwctx = (struct hwctrl_ctx *)hndl_hwctx;
	struct dec_decpict  *dec_pic;

	dec_pic = lst_first(&hwctx->pend_pict_list);
	while (dec_pic) {
		if (dec_pic->transaction_id == transaction_id) {
			*decpict = dec_pic;
			break;
		}
		dec_pic = lst_next(dec_pic);
	}

	if (!dec_pic)
		return IMG_ERROR_INVALID_ID;

	return 0;
}

int32 hwctrl_peekheadpiclist(void *hndl_hwctx, struct dec_decpict **decpict)
{
	struct hwctrl_ctx *hwctx = (struct hwctrl_ctx *)hndl_hwctx;

	if (hwctx)
		*decpict = lst_first(&hwctx->pend_pict_list);

	if (*decpict)
		return 0;

	return IMG_ERROR_GENERIC_FAILURE;
}

int32 hwctrl_getdecodedpicture(void *hndl_hwctx, struct dec_decpict **decpict)
{
	struct hwctrl_ctx *hwctx = (struct hwctrl_ctx *)hndl_hwctx;

	if (hwctx) {
		struct dec_decpict *cur_decpict;
		/*
		 * Ensure that this picture is in the list.
		 */
		cur_decpict = lst_first(&hwctx->pend_pict_list);
		while (cur_decpict) {
			if (cur_decpict->state ==
					DECODER_PICTURE_STATE_DECODED) {
				*decpict = cur_decpict;
				return 0;
			}

			cur_decpict = lst_next(cur_decpict);
		}
	}

	return IMG_ERROR_VALUE_OUT_OF_RANGE;
}

void hwctrl_removefrom_piclist(void *hndl_hwctx, struct dec_decpict  *decpict)
{
	struct hwctrl_ctx *hwctx = (struct hwctrl_ctx *)hndl_hwctx;

	if (hwctx) {
		struct dec_decpict *cur_decpict;
		/*
		 * Ensure that this picture is in the list.
		 */
		cur_decpict = lst_first(&hwctx->pend_pict_list);
		while (cur_decpict) {
			if (cur_decpict == decpict) {
				lst_remove(&hwctx->pend_pict_list, decpict);
				break;
			}

			cur_decpict = lst_next(cur_decpict);
		}
	}

	return;
}

int32 hwctrl_getregsoffset(void *hndl_hwctx,
			 struct decoder_regsoffsets *regs_offsets)
{
	struct hwctrl_ctx *hwctx = (struct hwctrl_ctx *)hndl_hwctx;

	return vdeckm_getregsoffsets(hwctx->hndl_vxd, regs_offsets);
}

static int32 pvdec_create(struct vxd_dev *vxd, struct vxd_coreprops *core_props,
			void **hndl_vdeckm_context)
{
	struct vdeckm_context  *corectx;
	struct vxd_core_props hndl_core_props;
	int32 result;

	if (!hndl_vdeckm_context || !core_props)
		return IMG_ERROR_INVALID_PARAMETERS;

	/*
	 * Obtain core context.
	 */
	corectx = &acore_ctx[0];

	memset(corectx, 0, sizeof(*corectx));

	corectx->core_num = 0;

	result = vxd_pvdec_get_props(vxd->dev, vxd->reg_base,
				     &hndl_core_props);
	if (result != 0)
		return result;

	vxd_get_coreproperties(&hndl_core_props, &corectx->props);


	memcpy(core_props, &corectx->props, sizeof(*core_props));

	*hndl_vdeckm_context = corectx;

	return 0;
}

int32 hwctrl_deinitialise(void *hndl_hwctx)
{
	struct hwctrl_ctx *hwctx = (struct hwctrl_ctx *)hndl_hwctx;

	if (hwctx->is_initialised) {
		osa_free(hwctx);
		hwctx = NULL;
	}

	return 0;
}

int32 hwctrl_initialise(void *dec_core, void *comp_int_userdata,
		      const struct vdecdd_dd_devconfig  *dd_devconfig,
		      struct vxd_coreprops *core_props, void **hndl_hwctx)
{
	struct hwctrl_ctx *hwctx = (struct hwctrl_ctx *)*hndl_hwctx;
	int32 result;

	if (!hwctx) {
		hwctx = osa_zalloc(sizeof(*(hwctx)), OSA_GFP_KERNEL);
		if (!hwctx)
			return IMG_ERROR_OUT_OF_MEMORY;

		*hndl_hwctx = hwctx;
	}

	if (!hwctx->is_initialised) {
		hwctx->hndl_vxd =
			((struct dec_core_ctx *)dec_core)->dec_ctx->dev_handle;
		result = pvdec_create(hwctx->hndl_vxd, core_props,
				      &hwctx->hndl_vxd);
		if (result != 0)
			goto error;

		lst_init(&hwctx->pend_pict_list);

		hwctx->devconfig = *dd_devconfig;
		hwctx->num_pipes = core_props->num_pixel_pipes;
		hwctx->comp_init_userdata = comp_int_userdata;
		hwctx->dec_core = dec_core;
		hwctx->is_initialised = 1;
		hwctx->is_on_seq_replay = 0;
		hwctx->is_fatal_state = 0;
	}

	return 0;
error:
	hwctrl_deinitialise(*hndl_hwctx);

	return result;
}

static int32 hwctrl_send_fragment_message(struct hwctrl_ctx *hwctx,
					struct dec_pict_fragment *pict_fragment,
					struct dec_decpict *decpict,
					void *vxd_dec_ctx)
{
	int32 result;
	struct hwctrl_to_kernel_msg to_kernelmsg = {0};
	struct hwctrl_msgdata msg_data;
	struct hwctrl_fragment_msgdata *pfragment_msgdata =
			&msg_data.fragment_msgdata;

	msg_data.km_str_id = GET_STREAM_ID(decpict->transaction_id);

	pfragment_msgdata->ctrl_alloc_bytes = pict_fragment->ctrl_alloc_bytes;

	pfragment_msgdata->ctrl_alloc_offset = pict_fragment->ctrl_alloc_offset;

	pfragment_msgdata->batchmsg_bufinfo =
			decpict->batch_msginfo->ddbuf_info;

	result = vdeckm_get_message(hwctx->hndl_vxd,
				    HWCTRL_MSGID_FRAGMENT,
				    &msg_data, &to_kernelmsg);
	if (result != 0) {
		OSA_PR_ERR("Failed to get decode message\n");
		return result;
	}

	result = vdeckm_send_message(hwctx->hndl_vxd, &to_kernelmsg,
				     vxd_dec_ctx);
	if (result != 0)
		return result;

	vdeckm_return_msg(hwctx->hndl_vxd, &to_kernelmsg);

	return 0;
}

int32 hwctrl_picture_submit_fragment(void *hndl_hwctx,
				   struct dec_pict_fragment  *pict_fragment,
				   struct dec_decpict *decpict,
				   void *vxd_dec_ctx)
{
	struct hwctrl_ctx *hwctx = (struct hwctrl_ctx *)hndl_hwctx;
	uint32 result = 0;

	if (hwctx->is_initialised) {
		result = hwctrl_send_fragment_message(hwctx, pict_fragment,
						      decpict, vxd_dec_ctx);
		if (result != 0)
			OSA_PR_ERR("Failed to send fragment message to firmware !");
	}

	return result;
}
