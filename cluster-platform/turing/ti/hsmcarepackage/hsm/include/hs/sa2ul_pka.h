/*
 * Copyright (C) 2017-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sa2ul_pka.h
 *
 * \brief SA2_UL PKA driver
 */
#ifndef SA2UL_PKA_H_
#define SA2UL_PKA_H_

#include <types/short_types.h>
#include <types/address_types.h>
#include <types/fterr.h>
#include <crypto_types.h>
#include <sa2ul.h>

/** Max size of bigint in words - for RSA */
#define PKA_BIGINT_MAX                 130U

/** Max size of bigint in words - for ECDSA */
#define PKA_EC_BIGINT_MAX              18U

/**
 * \brief Initialize SA2UL PKA module.
 *
 * \return EFTOK if successful
 */
fterr sa2ul_pka_init(void);

/**
 * \brief Modular exponentiation CRT primitive function result = m^d mod(n)
 *
 * \param m       m value in bigint format.
 * \param k       RSA private key
 *
 * \param result  Result of the operation in bigint format. caller must allocate
 *                memory size of (2 * sizeof(p)) for the result.
 *
 * \return EFTOK if successful
 */
fterr sa2ul_pka_modexp_crt(const u32 m[PKA_BIGINT_MAX], const struct rsa_privkey *k, u32 result[PKA_BIGINT_MAX]);

/**
 * \brief Modular exponentiation primitive function result = m^e mod(n)
 *
 * \param m       m value in bigint format.
 * \param k       RSA public key
 * \param result  Result of the operation in bigint format. caller must allocate
 *                the same memory as s and n for this array.
 *
 * \return EFTOK if successful
 */
fterr sa2ul_pka_modexp(const u32 m[PKA_BIGINT_MAX], const struct rsa_pubkey *k, u32 result[PKA_BIGINT_MAX]);

/**
 * \brief ECDSA sign primitive function
 *
 * \param cp      EC curve parameters
 * \param priv    EC private key
 * \param k       Random number for each signing
 * \param h       Hash value of message to sign in bigint format
 * \param sig     ECDSA Signature - 'r' and 's' values
 * \return True if the operation is successful
 *
 * \return EFTOK if successful
 */
fterr sa2ul_pka_ecdsa_sign(const struct ec_prime_curve_p *cp, const u32 priv[
				   PKA_EC_BIGINT_MAX], const u32 k[
				   PKA_EC_BIGINT_MAX], const u32 h[
				   PKA_EC_BIGINT_MAX], struct ecdsa_sig *sig);

/**
 * \brief ECDSA verify primitive function
 *
 * \param cp      EC curve parameters
 * \param pub     EC Public key
 * \param sig     ECDSA Signature - 'r' & 's' value in bigint format
 * \param h       Hash value of message to verify in bigint format
 *
 * \return EFTOK if successful
 */
fterr sa2ul_pka_ecdsa_verify(const struct ec_prime_curve_p *cp, const struct ec_point *pub, const struct ecdsa_sig *sig, const u32 h[
				     PKA_EC_BIGINT_MAX]);

/**
 * \brief Get PKA Firmware Load Address based on SOC and PG version
 *
 * \return Address to load the PKA Firmware
 */
u32 get_pka_firmware_load_addr(void);

#endif /* SA2UL_PKA_H_ */
