/*
 * System Firmware
 *
 * TISCI Data structures and macros for DSMEK access
 *
 * Copyright (C) 2020-2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */
#ifndef TISCI_DSMEK_H_
#define TISCI_DSMEK_H_

#include <tisci_protocol.h>
#include <types/short_types.h>

/**
 * \brief Derived key length 32 bytes always
 */
#define SA2UL_DSMEK_KEY_LEN (32U)

/**
 * \brief key derivation label and context length
 */
#define KDF_LABEL_AND_CONTEXT_LEN_MAX       41U

/**
 * \brief TISCI Request for setting DSMEK in SA2UL registers
 * \param hdr Generic TISCI message header.
 *
 * \param sa2ul_instance SA2UL instance number - set to 0
 * \param kdf_label_len Length of "Label" input to KDF
 * \param kdf_context_len Length of "Context" input to KDF
 * \param kdf_label_and_context "Label" and "Context" bytes are stored in this
 *                              array one after another. Maximum length of
 *                              this field is KDF_LABEL_AND_CONTEXT_LEN_MAX
 */
struct tisci_msg_sa2ul_set_dsmek_req {
	struct tisci_header	hdr;
	u8			sa2ul_instance;
	u8			kdf_label_len;
	u8			kdf_context_len;
	u8			kdf_label_and_context[KDF_LABEL_AND_CONTEXT_LEN_MAX];
} __attribute__((__packed__));

/**
 * \brief TISCI Response for setting DSMEK in SA2UL registers
 * \param hdr Generic TISCI message header.
 */
struct tisci_msg_sa2ul_set_dsmek_resp {
	struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief TISCI Request for releasing DSMEK
 * \param hdr Generic TISCI message header.
 *
 * \param sa2ul_instance SA2UL instance number - set to 0
 */
struct tisci_msg_sa2ul_release_dsmek_req {
	struct tisci_header	hdr;
	u8			sa2ul_instance;
} __attribute__((__packed__));

/**
 * \brief TISCI Response for Releasing DSMEK
 * \param hdr Generic TISCI message header.
 */
struct tisci_msg_sa2ul_release_dsmek_resp {
	struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief TISCI Request for getting DSMEK via TISCI
 * \param hdr Generic TISCI message header.
 *
 * \param sa2ul_instance SA2UL instance number - set to 0
 * \param kdf_label_len Length of "Label" input to KDF
 * \param kdf_context_len Length of "Context" input to KDF
 * \param kdf_label_and_context "Label" and "Context" bytes are stored in this
 *                              array one after another. Maximum length of
 *                              this field is KDF_LABEL_AND_CONTEXT_LEN_MAX
 */
struct tisci_msg_sa2ul_get_dsmek_req {
	struct tisci_header	hdr;
	u8			sa2ul_instance;
	u8			kdf_label_len;
	u8			kdf_context_len;
	u8			kdf_label_and_context[KDF_LABEL_AND_CONTEXT_LEN_MAX];
} __attribute__((__packed__));

/**
 * \brief TISCI Response for requesting DSMEK
 * \param hdr Generic TISCI message header.
 * \param dsmek Array containing Derived KEK. Length is 32 bytes
 */
struct tisci_msg_sa2ul_get_dsmek_resp {
	struct tisci_header	hdr;
	u8			dsmek[SA2UL_DSMEK_KEY_LEN];
} __attribute__((__packed__));

#endif
