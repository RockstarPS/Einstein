/*
 * System Firmware
 *
 * Copyright (C) 2020-2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef SA2UL_RNG_H
#define SA2UL_RNG_H

#include <types/sbool.h>
#include <types/short_types.h>
#include <config.h>
#include <string.h>

/* sa2ul instance whose trng will be reserved for use by tifs only */
#define SA2UL_INSTANCE_TIFS_TRNG 0U

/* sa2ul eip76 timeout in uS */
#define SA2UL_TRNG_SETUP_TIMEOUT_US 100U

/* The 'sample div' field in TRNG CONFIG
 * determines the rate of sampling FROs.
 *
 * However, the fields 'sample cycles' and
 * 'scale' determine the number of samples
 * xor-ed before getting shifted in the 
 * main register.
 */
/* Number of FRO samples to be xored*/
#define SA2UL_TRNG_CONFIG_SAMPLE_CYCLES 5U

enum {   
        SA2UL_TRNG_MODE_NO_DRBG = 0, 
        SA2UL_TRNG_MODE_AES256_DRBG, 
};

/**
 * \brief Initialize SA2UL RNG state.
 *
 * \return EFTOK if successful
 */
fterr sa2ul_rng_init(void);

/**
 * \brief Enable the sa2ul rng engine and set it up
 * 
 * \param instance sa2ul instance number
 * \param md sa2ul trng mode (unused right now)
 *
 * \return EFTOK is successful
*/
fterr sa2ul_rng_setup( u32 instance, u8 md __attribute__((unused)) );

/**
 * \brief Setup eip76 within a sa2ul instance for number generation without drbg
 * 
 * \param instance The sa2ul instance whose trng must be setup
 * \param md The rng mode (not used right now)
 *
 * \return EFTOK is sucessful
*/
fterr sa2ul_rng_setup_eip76( u32 instance, u8 md __attribute__((unused)));

/**
 * \brief Non-blocking read 128-bit random number from TRNG
 *
 * \param instance sa2ul instance number
 * \param out pointer to output buffer
 *
 * \return EFTOK if successful
 * 
 * \note out buffer must be atleast 4 words long
*/
#ifdef CONFIG_SECURITY_SA2UL_TRNG
fterr sa2ul_rng_read( u32 instance, u32 *out );
#else
inline fterr sa2ul_rng_read( u32       instance __attribute__((unused)),
			        u32     *out __attribute__((unused)) )
{
	return EFTOK;
}
#endif

/**
 * \brief Non-blocking read 128-bit random number from TRNG
 *
 * \param instance sa2ul instance number
 * \param out pointer to output buffer
 * \param timeout read timeout in uS
 *
 * \return EFTOK if successful
 * 
 * \note out buffer must be atleast 4 words long
*/
#ifdef CONFIG_SECURITY_SA2UL_TRNG
fterr sa2ul_rng_read_with_timeout( u32 instance, u32 *out, u32 timeout );
#else
inline fterr sa2ul_rng_read_with_timeout( u32       instance __attribute__((unused)),
			        u32	*out __attribute__((unused)),
                                u32     timeout __attribute__((unused)) )
{
	return EFTOK;
}
#endif

#endif
