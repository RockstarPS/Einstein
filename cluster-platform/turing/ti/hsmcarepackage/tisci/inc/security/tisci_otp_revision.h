/*
 * Copyright (C) 2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */
#ifndef REVISION_RD_WR_H
#define REVISION_RD_WR_H

/**
 *  \file tisci_otp_revision.h
 *
 *  \brief Declarations for all message structures to read and write SWREV and
 *         KEYREV
 */

#include <short_types.h>
#include <tisci_protocol.h>

/**
 * \brief Request message to set swrev
 *
 * This message can only be sent by the host that is tied to root of trust
 * through the secure boardcfg extended otp extension
 *
 * \param hdr           Standard TISCI header
 * \param identifier    One of the entries from enum tisci_otp_revision_identifier
 * \param value			Revision value (integer) to be bit encoded, and
 *                      programmed
 */
struct tisci_msg_set_swrev_req {
	struct tisci_header	hdr;
	u8			identifier;
	u32			value;
} __attribute__((__packed__));

/**
 * \brief Response message after seting swrev
 *
 * \param hdr			Standard TISCI header
 */
struct tisci_msg_set_swrev_resp {
	struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Request message to set keyrev
 *
 * This message can only be sent by the host that is tied to root of trust
 * through the secure boardcfg extended otp extension
 *
 * \param hdr           Standard TISCI header
 * \param value			Key Revision value (integer) to be bit encoded, and
 *                      programmed
 * \param cert_addr_lo	Lower 32 bit address (in LE format) of the Dual signed
 *                      certificate
 * \param cert_addr_hi	Higher 32 bit address (in LE format) of the Dual signed
 *                      certificate
 */
struct tisci_msg_set_keyrev_req {
	struct tisci_header	hdr;
	u32			value;
	u32			cert_addr_lo;
	u32			cert_addr_hi;
} __attribute__((__packed__));

/**
 * \brief Response message after setting keyrev
 *
 * \param hdr			Standard TISCI header
 */
struct tisci_msg_set_keyrev_resp {
	struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Request message to get swrev
 *
 * \param hdr           Standard TISCI header
 * \param identifier    One of the entries from enum tisci_otp_revision_identifier
 *                      (Current support only for OTP_REV_ID_SEC_BRDCFG)
 */
struct tisci_msg_get_swrev_req {
	struct tisci_header	hdr;
	u8			identifier;
} __attribute__((__packed__));

/**
 * \brief Response message to get swrev
 *
 * \param hdr			Standard TISCI header
 * \param value         Decoded Software Revision value (integer) from efuses
 */
struct tisci_msg_get_swrev_resp {
	struct tisci_header	hdr;
	u32			value;
} __attribute__((__packed__));

/**
 * \brief Request message to get keycnt, keyrev
 *
 * \param hdr           Standard TISCI header
 */
struct tisci_msg_get_keycnt_keyrev_req {
	struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Response message to get keycnt, keyrev
 *
 * \param hdr			Standard TISCI header
 * \param keycnt        Keycount integer value
 * \param keyrev		Keyrevision integer value
 */
struct tisci_msg_get_keycnt_keyrev_resp {
	struct tisci_header	hdr;
	u32			keycnt;
	u32			keyrev;
} __attribute__((__packed__));

/**
 * \brief OTP Revision Identifiers
 */
enum tisci_otp_revision_identifier {
	/** Sofware Revision SBL */
	OTP_REV_ID_SBL        = 0,
	/** Software Revision SYSFW */
	OTP_REV_ID_SYSFW      = 1,
	/** Software Revision Secure Board Configuration */
	OTP_REV_ID_SEC_BRDCFG = 2,
};

#endif
