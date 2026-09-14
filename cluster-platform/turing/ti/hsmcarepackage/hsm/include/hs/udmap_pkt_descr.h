/*
 * System Firmware NAVSS UDMAP Library
 *
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file udmap_pkt_descr.h
 *
 * \brief Include file for UDMAP packet descriptor types for
 *	  private use of drivers
 */

#ifndef UDMAP_PKT_DESCR_H
#define UDMAP_PKT_DESCR_H

#include <types/fterr.h>
#include <types/ftbool.h>
#include <types/short_types.h>
#include <types/address_types.h>

/**
 * \brief Extended Packet Info (EPI) block
 *
 *  This optional structure is used for time-stamp and software information
 *  storage.
 *
 *  \param ts_info Extended packet info block word 0 (timestamp)
 *  \param sw_info0 Extended packet info block word 1
 *  \param sw_info1 Extended packet info block word 2
 *  \param sw_info2 Extended packet info block word 3
 */
struct udmap_descr_epi {
	u32	ts_info;
	u32	sw_info0;
	u32	sw_info1;
	u32	sw_info2;
};

/**
 * \brief Host-mode packet and buffer descriptor
 *
 *  This structure is used for host-mode packet descriptors and buffer
 *  descriptors.
 *
 *  \param desc_info word 0: Packet information word 0
 *                  (not used in Buffer descriptors)
 *  \param pkt_info1 word 1: Packet information word 1
 *                  (not used in Buffer descriptors)
 *  \param pkt_info2 word 2: Packet information word 2
 *                  (Buffer reclamation information for buffer descriptors)
 *  \param src_dst_tag word 3: Packet information word 3
 *                  (not used in Buffer descriptors)
 *  \param next_desc_ptr words 4/5: Linking word
 *
 *  \param buf_ptr words 6/7: Buffer 0 information words 0 and 1 (PD words 6,7)
 *
 *  \param buf_info1 word 8: Buffer 0 information word 2 (PD word 8)
 *
 *  \param org_buf_len word 9: Original buffer 0 information word 0 (PD word 9)
 *
 *  \param org_buf_ptr words 10/11: Original buffer 0 information words 1 and 2
 *                    (PD words 10 and 11)
 *
 */
struct udmap_descr_host {
	u32	desc_info;
	u32	pkt_info1;
	u32	pkt_info2;
	u32	src_dst_tag;
	u64	next_desc_ptr;
	u64	buf_ptr;
	u32	buf_info1;
	u32	org_buf_len;
	u64	org_buf_ptr;
};

/**
 * \brief A full sized host descriptor (128 bytes)
 *
 * \param base Base descriptor
 * \param epi Extended packet info
 * \param psdata Protocol-specific data words
 */
struct udmap_descr_host_full {
	struct udmap_descr_host base;
	struct udmap_descr_epi	epi;
	u32			psdata[16];
};

/**
 * \brief Monolithic-mode packet descriptor
 *
 * This structure is used for monolithic-mode packet descriptors.
 *
 * \param desc_info word 0: Monolithic Packet Descriptor Word 0
 *
 * \param pkt_info1 word 1: Monolithic Packet Descriptor Word 1
 *
 * \param pkt_info2 word 2: Monolithic Packet Descriptor Word 2
 *
 * \param src_dst_tag word 3: Source/Dest Tag
 */
struct udmap_descr_monolithic {
	u32	desc_info;
	u32	pkt_info1;
	u32	pkt_info2;
	u32	src_dst_tag;
};


/**
 * \brief TR Descriptor
 *
 * \param desc_info word 0: TR Descriptor Info
 *
 * \param pkt_info word 1: TR Packet Info
 *
 * \param ret_info word 2: TR Return Info
 *
 * \param src_dst_tag word 3: Source/Dest Tag
 */
struct udmap_descr_tr {
	u32	desc_info;
	u32	pkt_info;
	u32	ret_info;
	u32	src_dst_tag;
};

/*-----------------------------------------------------------------------------
// Packet and Buffer Descriptor field manipulation macros
//---------------------------------------------------------------------------*/
#define UDMAP_PD_DESCINFO_DTYPE_SHIFT             (30U)
#define UDMAP_PD_DESCINFO_DTYPE_MASK		  \
	(((u32) 0x3U) << UDMAP_PD_DESCINFO_DTYPE_SHIFT)

#define UDMAP_PD_DESCINFO_DTYPE_VAL_HOST          (1U)
#define UDMAP_PD_DESCINFO_DTYPE_VAL_MONO          (2U)
#define UDMAP_PD_DESCINFO_DTYPE_VAL_TR            (3U)

#define UDMAP_PD_DESCINFO_EINFO_SHIFT             (29U)
#define UDMAP_PD_DESCINFO_EINFO_MASK		  \
	(((u32) 0x1U) << UDMAP_PD_DESCINFO_EINFO_SHIFT)

#define UDMAP_PD_DESCINFO_EINFO_VAL_NOT_PRESENT   (0)
#define UDMAP_PD_DESCINFO_EINFO_VAL_IS_PRESENT    (1U)

#define UDMAP_PD_DESCINFO_PSINFO_SHIFT            (28U)
#define UDMAP_PD_DESCINFO_PSINFO_MASK		  \
	(((u32) 0x1U) << UDMAP_PD_DESCINFO_PSINFO_SHIFT)

#define UDMAP_PD_DESCINFO_PSINFO_VAL_IN_DESC        (0)
#define UDMAP_PD_DESCINFO_PSINFO_VAL_IN_SOP_BUFFER  (1U)
#define UDMAP_PD_DESCINFO_PSWCNT_SHIFT              (22U)
#define UDMAP_PD_DESCINFO_PSWCNT_MASK		    \
	(((u32) 0x3FU) << UDMAP_PD_DESCINFO_PSWCNT_SHIFT)

#define UDMAP_PD_DESCINFO_PKTLEN_SHIFT            (0)
#define UDMAP_PD_DESCINFO_PKTLEN_MASK		  \
	(((u32) 0x3FFFFFU) << UDMAP_PD_DESCINFO_PKTLEN_SHIFT)

#define UDMAP_PD_PKTINFO1_PKTERROR_SHIFT          (28U)
#define UDMAP_PD_PKTINFO1_PKTERROR_MASK		  \
	(((u32) 0xFU) << UDMAP_PD_PKTINFO1_PKTERROR_SHIFT)

#define UDMAP_PD_PKTINFO1_PSFLGS_SHIFT            (24U)
#define UDMAP_PD_PKTINFO1_PSFLGS_MASK		  \
	(((u32) 0xFU) << UDMAP_PD_PKTINFO1_PSFLGS_SHIFT)

#define UDMAP_PD_PKTINFO1_PKTID_SHIFT             (14U)
#define UDMAP_PD_PKTINFO1_PKTID_MASK		  \
	(((u32) 0x3FFU) << UDMAP_PD_PKTINFO1_PKTID_SHIFT)

#define UDMAP_PD_PKTINFO1_FLOWID_SHIFT            (0)
#define UDMAP_PD_PKTINFO1_FLOWID_MASK		  \
	(((u32) 0x3FFFU) << UDMAP_PD_PKTINFO1_FLOWID_SHIFT)

#define UDMAP_PD_PKTINFO2_PKTTYPE_SHIFT           (27U)
#define UDMAP_PD_PKTINFO2_PKTTYPE_MASK		  \
	(((u32) 0x1FU) << UDMAP_PD_PKTINFO2_PKTTYPE_SHIFT)

#define UDMAP_PD_PKTINFO2_RETPOLICY_SHIFT         (18U)
#define UDMAP_PD_PKTINFO2_RETPOLICY_MASK	  \
	(((u32) 0x1U) << UDMAP_PD_PKTINFO2_RETPOLICY_SHIFT)

#define UDMAP_PD_PKTINFO2_RETPOLICY_VAL_ENTIRE_PKT  (0)
#define UDMAP_PD_PKTINFO2_RETPOLICY_VAL_BREAKUP_PKT (1U)

#define UDMAP_PD_PKTINFO2_DATA_OFFSET_SHIFT       (18U)
#define UDMAP_PD_PKTINFO2_DATA_OFFSET_MASK	  \
	(((u32) 0x1FFU) << UDMAP_PD_PKTINFO2_DATA_OFFSET_SHIFT)

#define UDMAP_PD_PKTINFO2_EARLYRET_SHIFT          (17U)
#define UDMAP_PD_PKTINFO2_EARLYRET_MASK		  \
	(((u32) 0x1U) << UDMAP_PD_PKTINFO2_EARLYRET_SHIFT)

#define UDMAP_PD_PKTINFO2_EARLYRET_VAL_NO           (0)
#define UDMAP_PD_PKTINFO2_EARLYRET_VAL_YES          (1U)

#define UDMAP_PD_PKTINFO2_RETPUSHPOLICY_SHIFT     (16U)
#define UDMAP_PD_PKTINFO2_RETPUSHPOLICY_MASK	  \
	(((u32) 0x1U) << UDMAP_PD_PKTINFO2_RETPUSHPOLICY_SHIFT)

#define UDMAP_PD_PKTINFO2_RETPUSHPOLICY_VAL_TO_TAIL (0)
#define UDMAP_PD_PKTINFO2_RETPUSHPOLICY_VAL_TO_HEAD (1U)

#define UDMAP_PD_PKTINFO2_RETQ_SHIFT              (0)
#define UDMAP_PD_PKTINFO2_RETQ_MASK		  \
	(((u32) 0xFFFFU) << UDMAP_PD_PKTINFO2_RETQ_SHIFT)

#define UDMAP_PD_SRCDSTTAG_SRCTAG_SHIFT           (16U)
#define UDMAP_PD_SRCDSTTAG_SRCTAG_MASK		  \
	(((u32) 0xFFFFU) << UDMAP_PD_SRCDSTTAG_SRCTAG_SHIFT)

#define UDMAP_PD_SRCDSTTAG_DSTTAG_SHIFT           (0)
#define UDMAP_PD_SRCDSTTAG_DSTTAG_MASK		  \
	(((u32) 0xFFFFU) << UDMAP_PD_SRCDSTTAG_DSTTAG_SHIFT)

#define UDMAP_PD_BUFINFO1_ASPACE_SHIFT            (28U)
#define UDMAP_PD_BUFINFO1_ASPACE_MASK		  \
	(((u32) 0xFU) << UDMAP_PD_BUFINFO1_ASPACE_SHIFT)

#define UDMAP_PD_BUFINFO1_LEN_SHIFT               (0)
#define UDMAP_PD_BUFINFO1_LEN_MASK		  \
	(((u32) 0x3FFFFFU) << UDMAP_PD_BUFINFO1_LEN_SHIFT)

#define UDMAP_PD_BUFINFO2_POOLIDX_SHIFT           (28U)
#define UDMAP_PD_BUFINFO2_POOLIDX_MASK		  \
	(((u32) 0xFU) << UDMAP_PD_BUFINFO2_POOLIDX_SHIFT)

#define UDMAP_PD_BUFINFO2_REFS_SHIFT              (22U)
#define UDMAP_PD_BUFINFO2_REFS_MASK		  \
	(((u32) 0x3FU) << UDMAP_PD_BUFINFO2_REFS_SHIFT)

#define UDMAP_PD_BUFINFO2_OLEN_SHIFT              (0)
#define UDMAP_PD_BUFINFO2_OLEN_MASK		  \
	(((u32) 0x3FFFFFU) << UDMAP_PD_BUFINFO2_OLEN_SHIFT)

/*
 * TR Descriptor field manipulation macros
 */
#define UDMAP_TRPD_DESCINFO_DTYPE_SHIFT           (30U)
#define UDMAP_TRPD_DESCINFO_DTYPE_MASK		  \
	(((u32) 0x3U) << UDMAP_TRPD_DESCINFO_DTYPE_SHIFT)

#define UDMAP_TRPD_DESCINFO_RELOAD_SHIFT          (20U)
#define UDMAP_TRPD_DESCINFO_RELOAD_MASK		  \
	(((u32) 0x1FFU) << UDMAP_TRPD_DESCINFO_RELOAD_SHIFT)

#define UDMAP_TRPD_DESCINFO_RLDIDX_SHIFT          (14U)
#define UDMAP_TRPD_DESCINFO_RLDIDX_MASK		  \
	(((u32) 0x3FU) << UDMAP_TRPD_DESCINFO_RLDIDX_SHIFT)

#define UDMAP_TRPD_DESCINFO_LASTIDX_SHIFT         (0)
#define UDMAP_TRPD_DESCINFO_LASTIDX_MASK	  \
	(((u32) 0x3FFFU) << UDMAP_TRPD_DESCINFO_LASTIDX_SHIFT)

#define UDMAP_TRPD_PKTINFO_PKTERROR_SHIFT         (28U)
#define UDMAP_TRPD_PKTINFO_PKTERROR_MASK	  \
	(((u32) 0xFU) << UDMAP_TRPD_PKTINFO_PKTERROR_SHIFT)

#define UDMAP_TRPD_PKTINFO_RECSIZE_SHIFT          (24U)
#define UDMAP_TRPD_PKTINFO_RECSIZE_MASK		  \
	(((u32) 0x7U) << UDMAP_TRPD_PKTINFO_RECSIZE_SHIFT)

#define UDMAP_TRPD_PKTINFO_RECSIZE_VAL_16B          (0)
#define UDMAP_TRPD_PKTINFO_RECSIZE_VAL_32B          (1U)
#define UDMAP_TRPD_PKTINFO_RECSIZE_VAL_64B          (2U)
#define UDMAP_TRPD_PKTINFO_RECSIZE_VAL_128B         (3U)

#define UDMAP_TRPD_PKTINFO_PKTID_SHIFT            (14U)
#define UDMAP_TRPD_PKTINFO_PKTID_MASK		  \
	(((u32) 0x3FFU) << UDMAP_TRPD_PKTINFO_PKTID_SHIFT)

#define UDMAP_TRPD_PKTINFO_FLOWID_SHIFT           (0)
#define UDMAP_TRPD_PKTINFO_FLOWID_MASK		  \
	(((u32) 0x3FFFU) << UDMAP_TRPD_PKTINFO_FLOWID_SHIFT)

#define UDMAP_TRPD_RETINFO_RETPOLICY_SHIFT        (16U)
#define UDMAP_TRPD_RETINFO_RETPOLICY_MASK	  \
	(((u32) 0x1U) << UDMAP_TRPD_RETINFO_RETPOLICY_SHIFT)

#define UDMAP_TRPD_RETINFO_RETPOLICY_VAL_TO_TAIL    (0)
#define UDMAP_TRPD_RETINFO_RETPOLICY_VAL_TO_HEAD    (1U)

#define UDMAP_TRPD_RETINFO_RETQ_SHIFT             (0)
#define UDMAP_TRPD_RETINFO_RETQ_MASK		  \
	(((u32) 0xFFFFU) << UDMAP_TRPD_RETINFO_RETQ_SHIFT)

#define UDMAP_TRPD_SRCDSTTAG_SRCTAG_SHIFT         (16U)
#define UDMAP_TRPD_SRCDSTTAG_SRCTAG_MASK	  \
	(((u32) 0xFFFFU) << UDMAP_TRPD_SRCDSTTAG_SRCTAG_SHIFT)

#define UDMAP_TRPD_SRCDSTTAG_DSTTAG_SHIFT         (0)
#define UDMAP_TRPD_SRCDSTTAG_DSTTAG_MASK	  \
	(((u32) 0xFFFFU) << UDMAP_TRPD_SRCDSTTAG_DSTTAG_SHIFT)

/**
 * \brief helper function to clear and setup a base host packet descriptor
 *        with one buffer for Tx.
 *
 * \param descr - Pointer to host descriptor
 *
 * \param pkt_buf_ptr - Physical address of the packet buffer
 *
 * \param pkt_len - Packet length
 *
 * \param einfo_present  Extended packet information is present
 *
 * \param psdata_wcnt - Protocol specific data length in words (word count)
 *
 * \param flow_id - Flow-ID to which the packet belongs to
 *
 * \param ret_qnum - Return queue number for descriptor after tx completion
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr udmap_pkt_descr_init_host_tx(struct udmap_descr_host *descr, soc_phys_addr_t pkt_buf_ptr, u32 pkt_len, ftbool einfo_present, u32 psdata_wcnt, u16 flow_id, u16 ret_qnum);

/**
 * \brief helper function to clear and setup a base host packet descriptor
 *        with one buffer for Rx.
 *
 * \param descr - Pointer to host descriptor
 *
 * \param pkt_buf_ptr - Physical address of the packet buffer
 *
 * \param pkt_len - Packet length
 *
 * \return SUCCESS if all went fine, else return corresponding error
 */
fterr udmap_pkt_descr_init_host_rx(struct udmap_descr_host *descr, soc_phys_addr_t pkt_buf_ptr, u32 pkt_len);


#endif
