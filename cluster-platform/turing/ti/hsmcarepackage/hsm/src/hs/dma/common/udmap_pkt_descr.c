/*
 * System Firmware NAVSS UDMAP/DMSS PKTDMA Library
 *
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file udmap_pkt_descr.c
 *
 * \brief UDMAP packet descriptor setup/helper functions
 *
 * Most of the code in this file is common for UDMA and PKTDMA.
 * Only the address fields in the host packet are different between
 * UDMA and PKTDMA. These are handled using macros
 * CONFIG_SECURITY_DMA_UDMA and CONFIG_SECURITY_DMA_PKTDMA
 */

#include <config.h>
#include <string.h>
#include <common_funcs.h>
#include <udmap_pkt_descr.h>

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * UDMAP PKT DESCR Visible APIs
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
fterr udmap_pkt_descr_init_host_tx(struct udmap_descr_host *descr,
				   soc_phys_addr_t pkt_buf_ptr,
				   u32 pkt_len, ftbool einfo_present,
				   u32 psdata_wcnt,
				   u16 flow_id, u16 ret_qnum)
{
	fterr ret = EFTOK;
	u32 len;

	/* Check if packet length exceeds max */
	len = (0xffffffffU & UDMAP_PD_DESCINFO_PKTLEN_MASK) >>
	      UDMAP_PD_DESCINFO_PKTLEN_SHIFT;
	if (pkt_len > len) {
		ret = -EINVAL;
	}

	/* Check if padata length exceeds max */
	len = (0xffffffffU & UDMAP_PD_DESCINFO_PSWCNT_MASK) >>
	      UDMAP_PD_DESCINFO_PSWCNT_SHIFT;
	if (psdata_wcnt > len) {
		ret = -EINVAL;
	}

	if (ret == EFTOK) {
		(void) memset(descr, 0, sizeof(struct udmap_descr_host));

		/* Set descriptor type to host */
		descr->desc_info = UDMAP_PD_DESCINFO_DTYPE_VAL_HOST <<
				   UDMAP_PD_DESCINFO_DTYPE_SHIFT;

		if (ft_is_true(einfo_present)) {
			/* extended info is present */
			descr->desc_info |=
				(UDMAP_PD_DESCINFO_EINFO_VAL_IS_PRESENT <<
				 UDMAP_PD_DESCINFO_EINFO_SHIFT);
		}

		/* PS data word count */
		descr->desc_info |= (psdata_wcnt <<
				     UDMAP_PD_DESCINFO_PSWCNT_SHIFT);

		/* Packet length */
		descr->desc_info |= (pkt_len << UDMAP_PD_DESCINFO_PKTLEN_SHIFT);

		descr->pkt_info1 = ((u32) flow_id <<
				    UDMAP_PD_PKTINFO1_FLOWID_SHIFT) &
				   UDMAP_PD_PKTINFO1_FLOWID_MASK;

		descr->pkt_info2 = ((u32) ret_qnum <<
				    UDMAP_PD_PKTINFO2_RETQ_SHIFT) &
				   UDMAP_PD_PKTINFO2_RETQ_MASK;

		descr->buf_ptr = pkt_buf_ptr;
		descr->buf_info1 = pkt_len;
		/*
		 *  For UDMA, orig_buf_len/orig_buf_ptr need not be initialized on the
		 *  Tx path.
		 *
		 *  For PKTDMA, orig_buf_len/orig_buf_ptr are unused.
		 *
		 *  So, we have removed initialization of orig_buf_len/orig_buf_ptr
		 *
		 *  Below two lines are only to provide context to this comment.
		 */
		descr->org_buf_ptr = 0U;
		descr->org_buf_len = 0U;
	}

	return ret;
}

fterr udmap_pkt_descr_init_host_rx(struct udmap_descr_host	*descr,
				   soc_phys_addr_t		pkt_buf_ptr,
				   u32				pkt_len)
{
	fterr ret = EFTOK;
	u32 len;

	/* Check if packet length exceeds max */
	len = (0xffffffffU & UDMAP_PD_DESCINFO_PKTLEN_MASK) >>
	      UDMAP_PD_DESCINFO_PKTLEN_SHIFT;
	if (pkt_len > len) {
		ret = -EINVAL;
	}

	if (ret == EFTOK) {
		(void) memset(descr, 0, sizeof(struct udmap_descr_host));

		/* Set descriptor type to host */
		descr->desc_info = UDMAP_PD_DESCINFO_DTYPE_VAL_HOST <<
				   UDMAP_PD_DESCINFO_DTYPE_SHIFT;

#if defined(CONFIG_SECURITY_DMA_UDMA)
		/*
		 * orig_buf_len/orig_buf_ptr is only valid for UDMA.
		 * It is not applicable to PKTDMA
		 *
		 * buf_ptr/buf_info1 are written during reception.
		 */
		descr->org_buf_ptr = pkt_buf_ptr;
		descr->org_buf_len = pkt_len;
#elif defined(CONFIG_SECURITY_DMA_PKTDMA)
		/*
		 * orig_buf_len/orig_buf_ptr are reserved for PKTDMA.
		 *
		 * buf_ptr/buf_info1 are read from and written to
		 * during reception. This is combining the functions
		 * of UDMA's orig_buf_len/orig_buf_ptr + buf_ptr/buf_info1
		 */
		descr->buf_ptr = pkt_buf_ptr;
		descr->buf_info1 = pkt_len;
#endif
	}

	return ret;
}
