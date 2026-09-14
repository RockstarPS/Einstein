/*
 * Copyright (C) 2017-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file crypto_types.h
 *
 * \brief Include file that has definitions for various crypto structures and
 *        defines for internal use.
 *
 */

#ifndef CRYPTO_TYPES_H_
#define CRYPTO_TYPES_H_

#include <types/short_types.h>

/* Public key crypto algo types */
#define PK_TYPE_RSA                       0
#define PK_TYPE_EC                        1

/* Hash algos */
#define HASH_ALGO_SHA2_256                0U
#define HASH_ALGO_SHA2_384                1U
#define HASH_ALGO_SHA2_512                2U
#define HASH_ALGO_SHA2_224                3U
#define HASH_ALGO_SHA1                    4U
#define HASH_ALGO_MD5                     5U
#define HASH_ALGO_N_ITEMS                 6U

/* Maximum length of hash in bytes */
#define HASH_MAX_LEN                      64U

/* MAC type - Simple Hash, HMAC or CMAC */
#define MAC_TYPE_HASH                     0U
#define MAC_TYPE_HMAC                     1U
#define MAC_TYPE_CMAC                     2U
#define MAC_TYPE_GMAC                     3U
#define MAC_TYPE_CBC_MAC                  4U
#define MAC_TYPE_N_ITEMS                  5U

/* Encryption algorithms */
#define ENC_ALGO_AES                      0U
#define ENC_ALGO_TDES                     1U
#define ENC_ALGO_N_ITEMS                  2U

/* Encryption direction */
#define ENC_DIR_ENCRYPT                   0U
#define ENC_DIR_DECRYPT                   1U
#define ENC_DIR_N_ITEMS                   2U

/* Encryption modes */
#define ENC_MODE_ECB                       0U
#define ENC_MODE_CBC                       1U
#define ENC_MODE_CTR                       2U
#define ENC_MODE_GCM                       3U
#define ENC_MODE_CCM                       4U
#define ENC_MODE_F8                        5U
#define ENC_MODE_OFB                       6U
#define ENC_MODE_CFB                       7U
#define ENC_MODE_GMAC_IPSEC_ESP            8U
#define ENC_MODE_GMAC_IPSEC_EH             9U
#define ENC_MODE_N_ITEMS                   10U

/* Key length */
#define ENC_KEYLEN_128                     0U
#define ENC_KEYLEN_192                     1U
#define ENC_KEYLEN_256                     2U
#define ENC_KEYLEN_MAX                     3U

#define ENC_MAX_KEY_LEN                    32U
#define ENC_MAX_IV_LEN                     16U

/* GCM Golais Hash length in bytes */
#define ENC_GCM_GHASH_LEN                  16U
/* GCM Tag length in words (16 bytes) */
#define ENC_GCM_IV_LEN_BYTES               12U
/* GCM tag length in bytes */
#define ENC_GCM_TAG_LEN_BYTES              16U
/* GCM tag length in words */
#define ENC_GCM_TAG_LEN_WORDS              4U
/* AES algorithm block size */
#define ENC_AES_BLOCK_SIZE_BYTES           16U

/* Signature algo types */
#define SIG_ALGO_SHA256_WITH_RSA          0
#define SIG_ALGO_SHA384_WITH_RSA          1
#define SIG_ALGO_SHA512_WITH_RSA          2
#define SIG_ALGO_SHA256_WITH_ECDSA        3
#define SIG_ALGO_SHA384_WITH_ECDSA        4
#define SIG_ALGO_SHA512_WITH_ECDSA        5
#define SIG_ALGO_RSA_PKCS_PSS             6
#define SIG_ALGO_N_ITEMS                  7

/* RSA signature type */
#define RSA_SIG_TYPE_PKCS_1_5             0
#define RSA_SIG_TYPE_PKCS_2_1             1
#define RSA_SIG_TYPE_N_ITEMS              2

/* ECDSA known curves */
#define EC_CURVE_BRAINPOOL_P256R1         0
#define EC_CURVE_BRAINPOOL_P256T1         1
#define EC_CURVE_BRAINPOOL_P320R1         2
#define EC_CURVE_BRAINPOOL_P320T1         3
#define EC_CURVE_BRAINPOOL_P384R1         4
#define EC_CURVE_BRAINPOOL_P384T1         5
#define EC_CURVE_BRAINPOOL_P512R1         6
#define EC_CURVE_BRAINPOOL_P512T1         7
#define EC_CURVE_PRIME256V1               8
#define EC_CURVE_SECP256K1                9
#define EC_CURVE_SECP384R1                10
#define EC_CURVE_SECP521R1                11
#define EC_CURVE_N_ITEMS                  12

#define EC_CURVE_EXPLICIT                (-1)

/**
 * Length of a biginteger array in words, the +1 is for the size
 */
#define BIGINT_LEN(bytelen)              (((bytelen) / 4U) + 1U)

/**
 * Size in bytes of a bigint element - subtract 4 bytes for size
 */
#define BIGINT_SIZEOF(elem)              (sizeof(elem) - 4U)

/** Maximum length of a hash when represented in bigint format */
#define HASH_BI_MAX_LEN (BIGINT_LEN(HASH_MAX_LEN))

/* RSA keys */
#define RSA_KEY_E_MAXLEN                  (8U)
#define RSA_KEY_N_MAXLEN                  (520U)
#define RSA_KEY_PQ_MAXLEN                 ((RSA_KEY_N_MAXLEN / 2U) + 4U)
#define RSA_SIG_MAXLEN                    RSA_KEY_N_MAXLEN

/**
 * \brief RSA public key. All values are in biginteger format (size followed
 *        by word value array, least significant word first)
 *
 * \param n RSA modulus (n)
 * \param e Public exponent (e)
 */
struct rsa_pubkey {
	u32	n[BIGINT_LEN(RSA_KEY_N_MAXLEN)];
	u32	e[BIGINT_LEN(RSA_KEY_E_MAXLEN)];
};

/**
 * \brief RSA private key. All values are in biginteger format (size followed
 *        by word value array, least significant word first)
 *
 * \param n RSA modulus (n)
 * \param e Public exponent (e)
 * \param d Private exponent (d)
 * \param p Prime 1 (p)
 * \param q Prime 2 (q)
 * \param dp d mod (p-1)
 * \param dq d mod (q-1)
 * \param coefficient crt coefficient q^(-1) mod p
 */
struct rsa_privkey {
	u32	n[BIGINT_LEN(RSA_KEY_N_MAXLEN)];
	u32	e[BIGINT_LEN(RSA_KEY_E_MAXLEN)];
	u32	d[BIGINT_LEN(RSA_KEY_N_MAXLEN)];
	u32	p[BIGINT_LEN(RSA_KEY_PQ_MAXLEN)];
	u32	q[BIGINT_LEN(RSA_KEY_PQ_MAXLEN)];
	u32	dp[BIGINT_LEN(RSA_KEY_PQ_MAXLEN)];
	u32	dq[BIGINT_LEN(RSA_KEY_PQ_MAXLEN)];
	u32	coefficient[BIGINT_LEN(RSA_KEY_PQ_MAXLEN)];
};

/* Elliptic curve crypto types */

/**
 * Maximum length of a big integer used in EC crypto in bytes, enough to
 * accomodate 521-bit prime curves
 */
#define EC_PARAM_MAXLEN                 (68U)

/**
 * \brief EC Point, also the public key
 *
 * \param x x-coordinate
 * \param y y-coordinate
 */
struct ec_point {
	u32	x[BIGINT_LEN(EC_PARAM_MAXLEN)];
	u32	y[BIGINT_LEN(EC_PARAM_MAXLEN)];
};

/**
 * \brief EC prime curve parameters
 *
 * \param prime Prime number for the group
 * \param order Order of the group
 * \param a "a" parameter in the equation x^3 + ax + b = y
 * \param b "b" parameter in the equation x^3 + ax + b = y
 * \param g Generator point on the Elliptic curve
 */
struct ec_prime_curve_p {
	u32		prime[BIGINT_LEN(EC_PARAM_MAXLEN)];
	u32		order[BIGINT_LEN(EC_PARAM_MAXLEN)];
	u32		a[BIGINT_LEN(EC_PARAM_MAXLEN)];
	u32		b[BIGINT_LEN(EC_PARAM_MAXLEN)];
	struct ec_point g;
};

/**
 * \brief ECDSA signature
 *
 * \param r "r" value in ECDSA signature
 * \param s "s" value in ECDSA signature
 */
struct ecdsa_sig {
	u32	r[BIGINT_LEN(EC_PARAM_MAXLEN)];
	u32	s[BIGINT_LEN(EC_PARAM_MAXLEN)];
};

/*
 * \brief EC private key
 *
 * \param ec_curve_type One of EC_CURVE_* types
 * \param curve_params EC Curve parameters
 * \param public_key Public key value
 * \param private_key Private key value
 */
struct ec_privkey {
	s32			ec_curve_type;
	struct ec_prime_curve_p curve_params;
	struct ec_point		public_curve_point;
	u32			private_key[BIGINT_LEN(EC_PARAM_MAXLEN)];
};

/*
 * \brief EC public key
 *
 * \param ec_curve_type One of EC_CURVE_* types
 * \param curve_params EC Curve parameters
 * \param public_key Public key value
 */
struct ec_pubkey {
	s32			ec_curve_type;
	struct ec_prime_curve_p curve_params;
	struct ec_point		public_curve_point;
};
#endif /* CRYPTO_TYPES_H_ */
