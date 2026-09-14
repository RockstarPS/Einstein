/*
 * System Firmware Security Management
 *
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sa2ul_pkt_descr.c
 *
 * \brief Helper functions for UDMAP descriptors for packets sent to SA2UL
 */

#include <string.h>
#include <sa2ul_pkt_descr.h>
#include "trace.h"

/*
 * sa2ul_descr_epi.sw_word0 fields
 */
#define SA2UL_SWWORD0_BYP_CMD_LBL_LEN_MASK  (0x80000000U)
#define SA2UL_SWWORD0_BYP_CMD_LBL_LEN_SHIFT (31U)

#define SA2UL_SWWORD0_CPPI_DST_INFO_PRESENT_MASK  (0x40000000U)
#define SA2UL_SWWORD0_CPPI_DST_INFO_PRESENT_SHIFT (30U)

#define SA2UL_SWWORD0_ENGINE_ID_MASK  (0x3e000000U)
#define SA2UL_SWWORD0_ENGINE_ID_SHIFT (25U)

#define SA2UL_SWWORD0_CMD_LBL_PRESENT_MASK  (0x1000000U)
#define SA2UL_SWWORD0_CMD_LBL_PRESENT_SHIFT (24U)

#define SA2UL_SWWORD0_CMD_LBL_OFFSET_MASK   (0xf00000U)
#define SA2UL_SWWORD0_CMD_LBL_OFFSET_SHIFT  (20U)

#define SA2UL_SWWORD0_FRAGMENT_MASK   (0x80000U)
#define SA2UL_SWWORD0_FRAGMENT_SHIFT  (19U)

#define SA2UL_SWWORD0_NO_PAYLOAD_MASK   (0x40000U)
#define SA2UL_SWWORD0_NO_PAYLOAD_SHIFT  (18U)

#define SA2UL_SWWORD0_TEARDOWN_MASK   (0x20000U)
#define SA2UL_SWWORD0_TEARDOWN_SHIFT  (17U)

#define SA2UL_SWWORD0_EVICT_MASK  (0x10000U)
#define SA2UL_SWWORD0_EVICT_SHIFT (16U)

#define SA2UL_SWWORD0_SCID_MASK   (0xffffU)
#define SA2UL_SWWORD0_SCID_SHIFT  (0U)

#define SA2UL_SCPTRH_EGRESS_CPPI_STATUS_LEN_MASK   (0xff000000U)
#define SA2UL_SCPTRH_EGRESS_CPPI_STATUS_LEN_SHIFT  (24U)

/*
 * sa2ul_descr_psdata_tx.in_psi_info fields
 */
#define SA2UL_INPSIINFO_EGRESS_CPPI_DEST_QUEUE_NUM_MASK  (0xffff0000U)
#define SA2UL_INPSIINFO_EGRESS_CPPI_DEST_QUEUE_NUM_SHIFT (16U)

#define SA2UL_INPSIINFO_NONSEC_CRYPTO_MASK  (0x8U)
#define SA2UL_INPSIINFO_NONSEC_CRYPTO_SHIFT (3U)

#define SA2UL_INPSIINFO_DEMOTE_MASK  (0x4U)
#define SA2UL_INPSIINFO_DEMOTE_SHIFT (2U)

#define SA2UL_INPSIINFO_PROMOTE_MASK  (0x2U)
#define SA2UL_INPSIINFO_PROMOTE_SHIFT (1U)

/*
 * sa2ul_descr_psdata_tx.cmd_lbl_hdr1 fields
 */
#define SA2UL_CMDLBLHDR1_LEN_TO_BE_PROCESSESED_MASK  (0xffffU)
#define SA2UL_CMDLBLHDR1_LEN_TO_BE_PROCESSESED_SHIFT (0U)

#define SA2UL_CMDLBLHDR1_CMD_LABEL_LEN_MASK  (0xff0000U)
#define SA2UL_CMDLBLHDR1_CMD_LABEL_LEN_SHIFT (16U)

#define SA2UL_CMDLBLHDR1_NEXT_ENGINE_SELECT_CODE_MASK  (0xff000000U)
#define SA2UL_CMDLBLHDR1_NEXT_ENGINE_SELECT_CODE_SHIFT (24U)

/*
 * sa2ul_descr_psdata_tx.cmd_lbl_hdr2 fields
 */
#define SA2UL_CMDLBLHDR2_OPTION1_CTX_OFFSET_MASK  (0xf80000U)
#define SA2UL_CMDLBLHDR2_OPTION1_CTX_OFFSET_SHIFT (19U)

#define SA2UL_CMDLBLHDR2_OPTION1_LEN_MASK  (0x70000U)
#define SA2UL_CMDLBLHDR2_OPTION1_LEN_SHIFT (16U)

#define SA2UL_CMDLBLHDR2_OPTION2_CTX_OFFSET_MASK  (0xf800U)
#define SA2UL_CMDLBLHDR2_OPTION2_CTX_OFFSET_SHIFT (11U)

#define SA2UL_CMDLBLHDR2_OPTION2_LEN_MASK  (0x700U)
#define SA2UL_CMDLBLHDR2_OPTION2_LEN_SHIFT (8U)

#define SA2UL_CMDLBLHDR2_OPTION3_CTX_OFFSET_MASK  (0xf8U)
#define SA2UL_CMDLBLHDR2_OPTION3_CTX_OFFSET_SHIFT (3U)

#define SA2UL_CMDLBLHDR2_OPTION3_LEN_MASK  (0x7U)
#define SA2UL_CMDLBLHDR2_OPTION3_LEN_SHIFT (0U)

#define SA2UL_CMDLBLHDR2_SOP_BYPASS_LEN_MASK  (0xff000000U)
#define SA2UL_CMDLBLHDR2_SOP_BYPASS_LEN_SHIFT (24U)

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * SA2UL PKT DESCR Visible APIs
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void sa2ul_u32le_to_u8(u8 *dest, const u32 *src, u32 len)
{
	u32 i, t;

	for (i = 0U; i < len; i += 4U) {
		t = src[(i >> 2)];
		dest[i] = (u8) ((t >> 24) & 0xFFU);
		dest[i + 1U] = (u8) ((t >> 16) & 0xFFU);
		dest[i + 2U] = (u8) ((t >> 8) & 0xFFU);
		dest[i + 3U] = (u8) (t & 0xFFU);
	}
}

void sa2ul_u8_to_u32le(u32 *dest, const u8 *src, u32 len)
{
	u32 i, t = 0U;

	for (i = 0U; i < len; i++) {
		t = (t << 8) | src[i];
		if ((i & 3U) == 3U) {
			dest[(i >> 2)] = t;
			t = 0U;
		}
	}
	if ((i & 3U) != 0U) {
		dest[(i >> 2)] = t << ((4U - (i & 3U)) << 3);
	}
}

fterr sa2ul_pkt_descr_setup_epi_tx(
	struct sa2ul_descr_epi	*epi,
	soc_phys_addr_t		sec_ctx_ptr,
	ftbool			last_pkt,
	u16			context_id,
	u8			engine_id,
	u16			egress_cppi_status_len)
{
	fterr ret = EFTOK;

	(void) memset(epi, 0, sizeof(struct sa2ul_descr_epi));

	/* Software word 0 */
	epi->sw_word0 = (1U << SA2UL_SWWORD0_CPPI_DST_INFO_PRESENT_SHIFT) &
			SA2UL_SWWORD0_CPPI_DST_INFO_PRESENT_MASK;

	epi->sw_word0 |= (1U << SA2UL_SWWORD0_CMD_LBL_PRESENT_SHIFT) &
			 SA2UL_SWWORD0_CMD_LBL_PRESENT_MASK;

	epi->sw_word0 |= ((u32) context_id << SA2UL_SWWORD0_SCID_SHIFT) &
			 SA2UL_SWWORD0_SCID_MASK;

	epi->sw_word0 |= ((u32) engine_id << SA2UL_SWWORD0_ENGINE_ID_SHIFT) &
			 SA2UL_SWWORD0_ENGINE_ID_MASK;

	if (ft_is_true(last_pkt)) {
		/*
		 * Evict and teardown security context after last packet
		 * (default behavior)
		 */
		epi->sw_word0 |= (1U << SA2UL_SWWORD0_TEARDOWN_SHIFT) &
				 SA2UL_SWWORD0_TEARDOWN_MASK;

		epi->sw_word0 |= (1U << SA2UL_SWWORD0_EVICT_SHIFT) &
				 SA2UL_SWWORD0_EVICT_MASK;
	} else {
		if ((engine_id == SA2UL_ENGINE_CODE_AUTHENTICATION_MODULE_P1) ||
		    (engine_id == SA2UL_ENGINE_CODE_AUTHENTICATION_MODULE_P2)) {
			/*
			 * Set the fragment bit
			 */
			epi->sw_word0 |= (1U << SA2UL_SWWORD0_FRAGMENT_SHIFT) &
					 SA2UL_SWWORD0_FRAGMENT_MASK;

			epi->sw_word0 |= (1U << SA2UL_SWWORD0_BYP_CMD_LBL_LEN_SHIFT) &
					 SA2UL_SWWORD0_BYP_CMD_LBL_LEN_MASK;
		}
	}

	epi->scptr_l = soc_phys_low_u32(sec_ctx_ptr);
	epi->scptrl_h = soc_phys_high_u32(sec_ctx_ptr);

	epi->scptrl_h |= ((u32) egress_cppi_status_len <<
			  SA2UL_SCPTRH_EGRESS_CPPI_STATUS_LEN_SHIFT) &
			 SA2UL_SCPTRH_EGRESS_CPPI_STATUS_LEN_MASK;
	return ret;
}

fterr sa2ul_pkt_descr_setup_psdata_auth(
	struct sa2ul_descr_psdata_tx	*psdata,
	u32				len_to_be_processed,
	u64				auth_len,
	u32				*psdata_len)
{
	fterr ret = EFTOK;
	u64 alen;

	(void) memset(psdata, 0, sizeof(struct sa2ul_descr_psdata_tx));

	/*
	 * Set destination queue number to 0xFFFF so that the destination queue
	 * number from the flow is used
	 */
	psdata->in_psi_info =
		(0xFFFFU << SA2UL_INPSIINFO_EGRESS_CPPI_DEST_QUEUE_NUM_SHIFT) &
		SA2UL_INPSIINFO_EGRESS_CPPI_DEST_QUEUE_NUM_MASK;

	psdata->cmd_lbl_hdr1 = (len_to_be_processed <<
				SA2UL_CMDLBLHDR1_LEN_TO_BE_PROCESSESED_SHIFT) &
			       SA2UL_CMDLBLHDR1_LEN_TO_BE_PROCESSESED_MASK;

	psdata->cmd_lbl_hdr1 |=
		(SA2UL_ENGINE_CODE_DEFAULT_EGRESS_PORT <<
		 SA2UL_CMDLBLHDR1_NEXT_ENGINE_SELECT_CODE_SHIFT) &
		SA2UL_CMDLBLHDR1_NEXT_ENGINE_SELECT_CODE_MASK;

	/*
	 * 16 bytes of command label length, cmd_lbl_hdr1/2 (8) +
	 * 2 option_words (8)
	 */
	psdata->cmd_lbl_hdr1 |=
		(16U << SA2UL_CMDLBLHDR1_CMD_LABEL_LEN_SHIFT) &
		SA2UL_CMDLBLHDR1_CMD_LABEL_LEN_MASK;

	psdata->cmd_lbl_hdr2 =
		(1U << SA2UL_CMDLBLHDR2_OPTION1_CTX_OFFSET_SHIFT) &
		SA2UL_CMDLBLHDR2_OPTION1_CTX_OFFSET_MASK;

	psdata->cmd_lbl_hdr2 |=
		(1U << SA2UL_CMDLBLHDR2_OPTION1_LEN_SHIFT) &
		SA2UL_CMDLBLHDR2_OPTION1_LEN_MASK;

	/* Authentication length is in bits */
	alen = auth_len << 3;

	psdata->option_words[0] = (u32) (alen >> 32);
	psdata->option_words[1] = (u32) alen;

	*psdata_len = 20U;

	return ret;
}

fterr sa2ul_pkt_descr_setup_psdata_enc(struct sa2ul_descr_psdata_tx *psdata,
				       u32 len_to_be_processed,
				       const u8 *aux1, const u8 *aux2,
				       const u8 *aux3,
				       u32 *psdata_len)
{
	fterr ret = EFTOK;
	u32 c_len[3], c_off[3], len;
	s32 i, j;
	const u8 *c_data[3];

	(void) memset(psdata, 0, sizeof(struct sa2ul_descr_psdata_tx));

	/*
	 * Set destination queue number to 0xFFFF so that the destination queue
	 * number from the flow is used
	 */
	psdata->in_psi_info =
		(0xFFFFU << SA2UL_INPSIINFO_EGRESS_CPPI_DEST_QUEUE_NUM_SHIFT) &
		SA2UL_INPSIINFO_EGRESS_CPPI_DEST_QUEUE_NUM_MASK;

	psdata->cmd_lbl_hdr1 = (len_to_be_processed <<
				SA2UL_CMDLBLHDR1_LEN_TO_BE_PROCESSESED_SHIFT) &
			       SA2UL_CMDLBLHDR1_LEN_TO_BE_PROCESSESED_MASK;

	psdata->cmd_lbl_hdr1 |=
		(SA2UL_ENGINE_CODE_DEFAULT_EGRESS_PORT <<
		 SA2UL_CMDLBLHDR1_NEXT_ENGINE_SELECT_CODE_SHIFT) &
		SA2UL_CMDLBLHDR1_NEXT_ENGINE_SELECT_CODE_MASK;

	len = 12U;
	for (i = 0; i < 3; i++) {
		c_len[i] = 0U;
		c_off[i] = 0U;
	}
	i = 0;
	if (aux1 != NULL) {
		c_len[i] = 32U;
		c_off[i] = 8U;
		c_data[i] = aux1;
		len += 32U;
		i++;
	}
	if (aux2 != NULL) {
		c_len[i] = 16U;
		c_off[i] = 12U;
		c_data[i] = aux2;
		len += 16U;
		i++;
	}
	if ((aux3 != NULL) &&
	    ((len + 16U) < sizeof(struct sa2ul_descr_psdata_tx))) {
		c_len[i] = 16U;
		c_off[i] = 14U;
		c_data[i] = aux3;
		len += 16U;
		i++;
	}

	*psdata_len = len;

	psdata->cmd_lbl_hdr1 |=
		((len - 4U) << SA2UL_CMDLBLHDR1_CMD_LABEL_LEN_SHIFT) &
		SA2UL_CMDLBLHDR1_CMD_LABEL_LEN_MASK;

	psdata->cmd_lbl_hdr2 =
		(c_off[0] << SA2UL_CMDLBLHDR2_OPTION1_CTX_OFFSET_SHIFT) &
		SA2UL_CMDLBLHDR2_OPTION1_CTX_OFFSET_MASK;

	psdata->cmd_lbl_hdr2 |=
		((c_len[0] >> 3) << SA2UL_CMDLBLHDR2_OPTION1_LEN_SHIFT) &
		SA2UL_CMDLBLHDR2_OPTION1_LEN_MASK;

	psdata->cmd_lbl_hdr2 |=
		(c_off[1] << SA2UL_CMDLBLHDR2_OPTION2_CTX_OFFSET_SHIFT) &
		SA2UL_CMDLBLHDR2_OPTION2_CTX_OFFSET_MASK;

	psdata->cmd_lbl_hdr2 |=
		((c_len[1] >> 3) << SA2UL_CMDLBLHDR2_OPTION2_LEN_SHIFT) &
		SA2UL_CMDLBLHDR2_OPTION2_LEN_MASK;

	psdata->cmd_lbl_hdr2 |=
		(c_off[2] << SA2UL_CMDLBLHDR2_OPTION3_CTX_OFFSET_SHIFT) &
		SA2UL_CMDLBLHDR2_OPTION3_CTX_OFFSET_MASK;

	psdata->cmd_lbl_hdr2 |=
		((c_len[2] >> 3) << SA2UL_CMDLBLHDR2_OPTION3_LEN_SHIFT) &
		SA2UL_CMDLBLHDR2_OPTION3_LEN_MASK;

	len = 0U;
	for (j = 0; j < i; j++) {
		sa2ul_u8_to_u32le(&psdata->option_words[len], c_data[j],
				  c_len[j]);
		len += (c_len[j] >> 2);
	}

	return ret;
}

fterr sa2ul_pkt_descr_read_result(const struct sa2ul_host_descr_rx *descr,
				  u32 pkt_len, u32 result_len, u8 *result_ptr)
{
	fterr ret = EFTOK;

	u32 reg;

	/*
	 * Check protocol-specific flags for SA2UL errors
	 */
	reg = (descr->base.pkt_info1 & UDMAP_PD_PKTINFO1_PSFLGS_MASK) >>
	      UDMAP_PD_PKTINFO1_PSFLGS_SHIFT;

	if (reg != 0U) {
		/*
		 * SA2UL has returned an error
		 *
		 * TODO: Log a error
		 */
		TRACE_info("\r\n Failed");
		TRACE_info_arg_hsm("\r\n reg value",reg);
		ret = -EFAIL;
	}

	if (ret == EFTOK) {
		reg =
			(descr->base.desc_info &
			 UDMAP_PD_DESCINFO_PKTLEN_MASK) >>
			UDMAP_PD_DESCINFO_PKTLEN_SHIFT;

		if (pkt_len != reg) {
			/*
			 * Unexpected packet length
			 */
			TRACE_info("\r\n Failed 2");
			ret = -EFAIL;
		}
	}

	if ((ret == EFTOK) && (result_len != 0U)) {
		/*
		 * Check if protocol-specific data is present
		 */
		reg = (descr->base.desc_info & UDMAP_PD_DESCINFO_PSWCNT_MASK)
		      >> UDMAP_PD_DESCINFO_PSWCNT_SHIFT;

		/*
		 * PS data size is in words
		 */
		reg <<= 2;

		if (reg != result_len) {
			/*
			 * Result length not as expected
			 */
			TRACE_info("\r\n Failed 3");
			ret = -EFAIL;
		}
	}

	if ((ret == EFTOK) && (result_len != 0U)) {
		/*
		 * Copy final hash value from the descriptor's ps data
		 */
		sa2ul_u32le_to_u8(result_ptr, &descr->psdata_rx.trailer_data[0],
				  result_len);
	}
	return ret;
}
