/*
 * System Firmware Security Management
 *
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sa2ul_pkt_descr.h
 *
 * \brief Include file for packet descriptor types and fields defined for
 *        use by SA2UL.
 */

#ifndef SA2UL_PKT_DESCR_H
#define SA2UL_PKT_DESCR_H

#include <types/ftbool.h>
#include <types/fterr.h>
#include <types/short_types.h>
#include <types/address_types.h>
#include <udmap_pkt_descr.h>

/**
 * \brief Extended Packet Info for SA2UL
 *
 *  \param ts_info Extended packet info block word 0 (timestamp)
 *  \param sw_word0 Software Info Word 0
 *  \param scptr_l Security context pointer (lower 32-bits)
 *  \param scptrl_h Security context pointer (upper 32-bits)
 */
struct sa2ul_descr_epi {
	u32	ts_info;
	u32	sw_word0;
	u32	scptr_l;
	u32	scptrl_h;
};

/**
 * Maximum number of command label option words
 */
#define SA2UL_PKT_MAX_CMD_LBL_OPTION_WORDS    (13)

/**
 * \brief Protocol-specific word in pkts sent to SA2UL
 *
 * \param in_psi_info Protocol Specific (PS) Info Words
 * \param cmd_lbl_hdr1 Command label (PS Data) Format (first 32 bits)
 *                     starting with "Next engine select code" and ending with
 *                     "Length to be processed"
 * \param cmd_lbl_hdr2 Command label (PS Data) Format (next 32 bits)
 *                     "SOP bypass length" and "Options control info"
 * \param option_words Command label (PS Data) option words as defined in
 *                     "Options control info"
 */
struct sa2ul_descr_psdata_tx {
	u32	in_psi_info;
	u32	cmd_lbl_hdr1;
	u32	cmd_lbl_hdr2;
	u32	option_words[SA2UL_PKT_MAX_CMD_LBL_OPTION_WORDS];
};

/**
 * Maximum number of trailer data words
 */
#define SA2UL_PKT_MAX_TRAILER_DATA_WORDS    (16)

/**
 * \brief Protocol specific data for packets recieved from SA2UL
 *
 * \param trailer_data Trailer data sent by SA2UL depending on the mode of
 *                     operation
 */
struct sa2ul_descr_psdata_rx {
	u32 trailer_data[SA2UL_PKT_MAX_TRAILER_DATA_WORDS];
};

/**
 * \brief Host descriptor for Tx packets sent to SA2UL
 *
 * \param base Base host descriptor
 * \param epi Extended packet info
 * \param psdata_tx Protocol-specific data for Tx packets
 */
struct sa2ul_host_descr_tx {
	struct udmap_descr_host		base;
	struct sa2ul_descr_epi		epi;
	struct sa2ul_descr_psdata_tx	psdata_tx;
};

/**
 * \brief Host descriptor for Rx packets from SA2UL
 *
 * \param base Base host descriptor
 * \param epi Extended packet info
 * \param psdata_rx Protocol-specific data for Rx packets
 */
struct sa2ul_host_descr_rx {
	struct udmap_descr_host		base;
	struct sa2ul_descr_epi		epi;
	struct sa2ul_descr_psdata_rx	psdata_rx;
};

/*
 * sa2ul engine codes
 */
#define SA2UL_ENGINE_CODE_DEFAULT_ENGINE_ID          0U
#define SA2UL_ENGINE_CODE_ENCRYPTION_MODULE_P1       2U
#define SA2UL_ENGINE_CODE_ENCRYPTION_MODULE_P2       3U
#define SA2UL_ENGINE_CODE_AUTHENTICATION_MODULE_P1   4U
#define SA2UL_ENGINE_CODE_AUTHENTICATION_MODULE_P2   5U
#define SA2UL_ENGINE_CODE_DEFAULT_EGRESS_PORT        20U

/**
 * \brief function to set up extended packet information for a SA2UL tx packet.
 *
 * \param epi - Pointer to extended packet info
 *
 * \param sec_ctx_ptr - Physical address of the security context
 *
 * \param last_pkt - Whether this is the last packet
 *
 * \param context_id - SA2UL context ID
 *
 * \param engine_id - SA2UL engine ID that processes this packet
 *
 * \param egress_cppi_status_len - Length of the cppi status (ps data) in egress
 *                                 packets. This depends on the algorithm.
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr sa2ul_pkt_descr_setup_epi_tx(struct sa2ul_descr_epi *epi, soc_phys_addr_t sec_ctx_ptr, ftbool last_pkt, u16 context_id, u8 engine_id, u16 egress_cppi_status_len);

/**
 * \brief function to set up protocol specific data for a SA2UL tx packet for
 *        authentication operation
 *
 * \param psdata - Pointer to extended packet info
 *
 * \param len_to_be_processed - Length of input packet to be processed
 *
 * \param auth_len - Authentication length (used if replace_auth_len is STRUE)
 *
 * \param psdata_len - PS data length (returned)
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr sa2ul_pkt_descr_setup_psdata_auth(struct sa2ul_descr_psdata_tx *psdata, u32 len_to_be_processed, u64 auth_len, u32 *psdata_len);

/**
 * \brief function to set up protocol specific data for a SA2UL tx packet for
 *        encryption operation
 *
 * \param psdata - Pointer to extended packet info
 *
 * \param len_to_be_processed - Length of input packet to be processed
 *
 * \param aux1 - If not null, 32-bytes from this pointer location will be used
 *               to overwrite aux1 in the security context
 * \param aux2 - If not null, 16-bytes from this pointer location will be used
 *               to overwrite aux2 in the security context
 * \param aux3 - If not null, 16-bytes from this pointer location will be used
 *               to overwrite aux3 in the security context
 *
 * \param psdata_len - PS data length (returned)
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr sa2ul_pkt_descr_setup_psdata_enc(struct sa2ul_descr_psdata_tx *psdata, u32 len_to_be_processed, const u8 *aux1, const u8 *aux2, const u8 *aux3, u32 *psdata_len);

/**
 * \brief function to check for errors and read the result data from SA2UL
 *        rx packet (optionally)
 *
 * \param descr - Pointer to packet descriptor
 *
 * \param pkt_len - Expected length of packet data received
 *
 * \param result_len - Length of result (in descriptor trailer data) to read
 *
 * \param result_ptr - Pointer of memory to read the result into
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr sa2ul_pkt_descr_read_result(const struct sa2ul_host_descr_rx *descr, u32 pkt_len, u32 result_len, u8 *result_ptr);

/**
 * \brief endian swap and copy from LE U32 to U8
 *
 * \param dest Destination pointer
 * \param src Source pointer
 * \param len length of the data to copied
 */
void sa2ul_u32le_to_u8(u8 *dest, const u32 *src, u32 len);

/**
 * \brief endian swap and copy from u8 array to u32 little endian array
 *
 * \param dest Destination pointer
 * \param src Source pointer
 * \param len length of the data to copied
 */
void sa2ul_u8_to_u32le(u32 *dest, const u8 *src, u32 len);

#endif
