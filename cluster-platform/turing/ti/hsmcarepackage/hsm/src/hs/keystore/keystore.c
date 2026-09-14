/*
 * Copyright (C) 2017-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file keystore.c
 *
 * \brief Functions to import and export symmetric keys
 *
 */

#include <types/short_types.h>
#include <types/fterr.h>
#include <string.h>
#include <stdbool.h>

#include <config.h>
#include <socmem.h>
#include <keystore.h>
#include <security_manager.h>
#include <sec_mem_mgr.h>
#include <crypto_types.h>
#include <hosts.h>
#include <hosts_internal.h>
#include <sec_dma.h>
#include <sec_mem_mgr.h>

/**
 * flag indicating if the key import status was OK
 */
#define KEYSTORE_KEY_IMPORT_STATUS_OK          0x5AU

/* Direction for keystore_safe_copy */
#define TO_DMSC                         0x0U
#define FROM_DMSC                       0x1U

/* Identifier of Keystore structure */
#define KEYSTORE_STATE_ITEM_ID          0xFFU

#define KEYSTORE_SKEY_KEY_LEN          32U

/**
 * Maximum number of keys defined as number of descriptors for the smallest
 * possible key type (AES-128 is 16 bytes) can fit in the configured keystore
 * memory, less top-level overhead.
 */
#define MAX_NUM_KEYS    ((CONFIG_SECURITY_KEYSTORE_SIZE - \
			  sizeof(struct keystore_top)) / \
			 (sizeof(struct key_desc) + 16U))
/**
 * \brief Module global state
 *
 * \param top  Keystore top-level information
 * \param key  Metadata descriptor for each key
 * \param data Static allocation of keystore memory
 */
union {
	struct {
		struct keystore_top	top;
		struct key_desc		desc[MAX_NUM_KEYS];
	} meta __attribute__((packed));
	u8 data[CONFIG_SECURITY_KEYSTORE_SIZE];
} keystore __attribute__((__section__(".sec_rt_keystore")));

/*
 * Function prototypes
 */


fterr keystore_read_skey(u8 id, u8 owner, u32 usage, u8 *skey)
{
	struct key_desc *key = NULL;
	fterr ret = -EINVAL;

	/* Get the key descriptor if the index is valid */
	if (id < keystore.meta.top.num_keys) {
		key = &keystore.meta.desc[id];
	}

	/*
	 * Check if this host is the owner, key slot holds a valid key, and
	 * usage_flags for accessing is acceptable.
	 */
	if ((key != NULL) &&
	    (key->owner == owner) &&
	    (key->status == KEYSTORE_KEY_IMPORT_STATUS_OK) &&
	    ((key->usage_flags & usage) == usage)) {
		/* Copy the key data */
		(void) memcpy(skey,
			      (void *) &keystore.data[key->offset],
			      KEYSTORE_SKEY_KEY_LEN);
		ret = EFTOK;
	}
	return ret;
}




