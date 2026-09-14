/*
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file keystore.h
 *
 * \brief Functions to import and export keys
 *
 */

#ifndef KEYSTORE_H_
#define KEYSTORE_H_

#include <config.h>
#include <types/short_types.h>
#include <types/address_types.h>
#include <types/fterr.h>


/* Crypto algo types */
enum key_data_types {
	/** AES symmetric key size up to 256-bit */
	KEY_TYPE_AES = 0U,
	KEY_TYPES_MAX = 1U,
};

/**
 * \brief Keystore data ABI version.
 *
 * \param keystore_abi_maj Major Keystore data ABI version.
 * \param keystore_abi_min Minor Keystore data ABI version.
 */
struct keystore_abi_rev {
	u8	keystore_abi_maj;
	u8	keystore_abi_min;
} __attribute__((__packed__));

/**
 * \brief Keystore top-level information
 *
 * \param rev Keystore ABI revision
 * \param num_keys Number of keys in the keystore
 * \param owner Host ID of the host who owns the keystore structure. The
 *              ownership will be determined during key provisioning through the
 *              payload details contained in the keystore write API. Only the
 *              owner will be able to trigger bulk keystore export and import.
 * \param state Variable used to handle internal keystore state transitions and
 *              protect against out-of-order operations.
 */
struct keystore_top {
	struct keystore_abi_rev rev;
	u16			num_keys;
	u8			owner;
	u8			state;
} __attribute__((packed));

/**
 * \brief Key metadata descriptor structure
 *
 * \param owner Host ID of the host who owns this key slot. Only the owner will
 *              be able to write, erase, or access keys for this slot
 * \param usage_flags Or'ed value of all usage flags
 * \param status Status indicating whether the keyslot contains a valid key or
 *               is empty
 * \param key_type What type of key the slot holds
 * \param slot_size Size of the key slot in bytes. This may be used to restrict
 *                  a key slot to a subset of possible sizes for a given type of
 *                  key.
 * \param offset Offset from the keystore memory base adress containing the base
 *               for the key data coresponding to this descriptor index
 */
struct key_desc {
	u8	owner;
	u32	usage_flags;
	u8	status;
	u8	key_type;
	u16	slot_size;
	u32	offset;
} __attribute__((packed));

/**
 * \brief Read a key from key store
 *
 * Internal API to read a key from the key store to be used for various purposes
 *
 * \param id Key item id
 * \param owner Owner on whose behalf this request is made
 * \param purpose One or more of flags KEYSTORE_SKEY_USAGE_*
 * \param key If all checks pass, the key to copied into this location
 *
 * \return EFTOK if successful, errorcode otherwise
 */
fterr keystore_read_skey(u8 id, u8 owner, u32 purpose, u8 *key);


#endif /* KEYSTORE_H_ */
