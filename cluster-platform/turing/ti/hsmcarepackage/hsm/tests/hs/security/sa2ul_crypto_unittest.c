/*
 * Copyright (C) 2017-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sa2ul_pka_unittest.c
 *
 * \brief SA2UL PKA driver unittests
 */

#include <config.h>
#include <string.h>
#include <sec_dma.h>
#include <sa2ul_crypto.h>
#include <unit_test.h>
#include <hosts.h>
#include <socmem.h>
#include <firewall.h>
#include <masters.h>
#include <hosts_internal.h>
#include <hosts.h>
#include <types/array_size.h>
#include <rat.h>
#include <crypto_ut_hosts.h>
#include <sa2ul_sec_ctx.h>
#include <lib/trace.h>
#include <arch/interrupt.h>
#include <sa2ul_rng.h>
#include <sa2ul_pka.h>
#include <hsm_core/hsm.h> 
#include <sec_proxy.h>
#include <firewall_control.h>

#define DBG(...)

/* HMAC SHA-512 length */
#define APP_CRYPTO_HMAC_SHA512_OUTPUT_LENGTH                  (64U)
/*Input buf length*/
#define APP_CRYPTO_HMAC_SHA512_INPUT_BUF_LENGTH                 (9U)
/* HMAC SHA-512 key length */
#define APP_CRYPTO_HMAC_SHA512_KEYLEN_IN_BYTES                  (128U)
/* HMAC SHA-512 output buffer maximum length */
#define APP_CRYPTO_HMAC_SHA512_OUTPUT_BUFFER_MAX_LENGTH         (192U)
/* HMAC-SHA512 input key length */
#define APP_CRYPTO_HMAC_SHA512_INPUT_KEY_LENGTH                 (20U)

#define SA2UL_HASH_ALG_SHA2_512         (0x16U)

/** \brief Key length for HMAC-SHA Process */
#define CRYPTO_HMAC_SHA_MAX_KEYLEN_BYTES      (128U)
/** \brief Key length for HMAC-SHA512 Process */
#define CRYPTO_HMAC_SHA512_KEYLEN_BYTES       (128U)
/** \brief Key length for HMAC-SHA1 Process */
#define CRYPTO_HMAC_SHA1_KEYLEN_BYTES         (64U)
/** \brief Key length for HMAC-SHA256 Process */
#define CRYPTO_HMAC_SHA256_KEYLEN_BYTES       (64U)
/** \brief Inner Padding value for HMAC */
#define CRYPTO_HMAC_SHA_IPAD                  (0x36U)
/** \brief Outer Padding value for HMAC */
#define CRYPTO_HMAC_SHA_OPAD                  (0x5CU)

#define SA2UL_CACHELINE_ALIGNMENT       (16U)

/** \brief Aes Cmac key length*/
#define CRYPTO_AES_CMAC_KEY_LENGTH            (16U)
/** \brief Aes block length*/
#define CRYPTO_AES_BLOCK_LENGTH               (16U)

#define SA2UL_STATUS_ADDR	0XC0000000U
#define SHA_TEST_STATUS		0x00000001U
#define AES_TEST_STATUS		0x00000010U
#define TRNG_TEST_STATUS	0x00000100U
#define HMAC_TEST_STATUS	0x00001000U

/*sa2ul status to pass to mcur5 to show status of sa2ul tests
	00000001 -> sa2ul sha test case status
	00000010 -> sa2ul hsm aes test case status
	00000100 -> sa2ul hsm trng test case status
	00001000 -> sa2ul hmac sha test case status
*/
uint32_t sa2ul_status=0x00000000;

/** \brief CRYPTO Parameters for various operations */
typedef struct
{
    /** Authentication mode.*/
    uint32_t                authMode;
    /** Key for Hmac sha algorithm */
    uint8_t                 key[CRYPTO_HMAC_SHA_MAX_KEYLEN_BYTES];
    /** Key size in bytes for Hmac algorithm */
    uint32_t                keySizeInBytes;
    /** iPad for hmac calculation */
    uint8_t                 iPad[CRYPTO_HMAC_SHA_MAX_KEYLEN_BYTES];
    /** oPad for hmac calculation */
    uint8_t                 oPad[CRYPTO_HMAC_SHA_MAX_KEYLEN_BYTES];
    /** Used to calculate key1 and key2 */
    uint8_t                 aesWithKeyAppliedToZeroInput[CRYPTO_AES_BLOCK_LENGTH];
    /** Key1 for Cmac operations*/
    uint8_t                 key1[CRYPTO_AES_CMAC_KEY_LENGTH];
    /** Key2 for Cmac operations*/
    uint8_t                 key2[CRYPTO_AES_CMAC_KEY_LENGTH];
} Crypto_Params;

const u8 rand_bin[] = {
	0x6f, 0xf5, 0x63, 0x9e, 0x82, 0x3f, 0x22, 0x7d, 0x99, 0xec, 0xaf, 0x86,
	0x13, 0x95, 0x5a, 0x17, 0xc1, 0xdf, 0x6a, 0x33, 0xc9, 0x00, 0x77, 0x8b,
	0x7c, 0xdc, 0x30, 0x25, 0x18, 0x4f, 0xba, 0x29, 0xd6, 0x39, 0x72, 0x32,
	0x44, 0x0d, 0xc6
};

const u8 rand_bin_sha512sum[] = {
	0xaa, 0x7f, 0x69, 0x15, 0x92, 0xa6, 0x3c, 0xfe, 0x95, 0xf8, 0xc0, 0x5c,
	0x66, 0x88, 0xb0, 0x27, 0xa9, 0xe2, 0xbe, 0x3b, 0x56, 0x7b, 0x8f, 0xbc,
	0x94, 0x8d, 0xa5, 0x87, 0xe2, 0x89, 0x38, 0x57, 0x08, 0xbb, 0xec, 0x50,
	0x5c, 0xda, 0x8f, 0x43, 0xff, 0xd5, 0x3a, 0x66, 0x03, 0xd7, 0xed, 0xb7,
	0x3f, 0x77, 0x26, 0x79, 0xaf, 0xb5, 0x51, 0xce, 0x72, 0x82, 0x40, 0xb0,
	0x1c, 0xaf, 0xfb, 0x64
};

static const u8 test_pt[] = {
	0x0d, 0x7a, 0xa9, 0xd6, 0x71, 0x85, 0xc5, 0x3d, 0x7a, 0xed, 0xd1, 0x86,
	0x3a, 0x57, 0x72, 0xe3, 0xf6, 0x77, 0x3f, 0xeb, 0x43, 0x63, 0x22, 0x69,
	0x4e, 0x44, 0x08, 0x85, 0xfe, 0x6f, 0x63, 0xcc
};

/*Input test buffer for hmac sha-512 computation */
static uint8_t gCryptoHmacSha512TestInputBuf[APP_CRYPTO_HMAC_SHA512_INPUT_BUF_LENGTH] = {"abcdefpra"};
/*Output test buffer for hmac sha computation */
uint8_t gCryptoHmacSha512TestOutputBuf[APP_CRYPTO_HMAC_SHA512_OUTPUT_BUFFER_MAX_LENGTH] __attribute__ ((aligned (SA2UL_CACHELINE_ALIGNMENT)));
/*For Inner pad*/
const uint8_t  gCryptoHmacSha512Ipad[APP_CRYPTO_HMAC_SHA512_KEYLEN_IN_BYTES];
/*For outer pad*/
const uint8_t  gCryptoHmacSha512Opad[APP_CRYPTO_HMAC_SHA512_KEYLEN_IN_BYTES];

const uint8_t gCryptoHmacTemp[APP_CRYPTO_HMAC_SHA512_KEYLEN_IN_BYTES+sizeof(gCryptoHmacSha512TestInputBuf)];

const uint8_t gCryptoHmacTemp2[APP_CRYPTO_HMAC_SHA512_KEYLEN_IN_BYTES+APP_CRYPTO_HMAC_SHA512_OUTPUT_LENGTH];

/* Expected output buffer for hmac sha-512 computation */
uint8_t gCryptoHmacSha512ExpectedOutput[APP_CRYPTO_HMAC_SHA512_OUTPUT_LENGTH] =
{
    0x5d, 0x9c, 0xf2, 0x02, 0xdf, 0xf4, 0x35, 0xce, 0x3f, 0xab,
    0x42, 0xcf, 0x35, 0xde, 0x4e, 0xc4, 0x32, 0xf2, 0x90, 0x87,
    0xf2, 0xef, 0xb5, 0x28, 0x89, 0xb6, 0xb2, 0xba, 0xe9, 0xb4,
    0x01, 0xac, 0xd3, 0x94, 0xd8, 0xd6, 0x3c, 0x3f, 0x3e, 0xbd,
    0x8b, 0xe2, 0xdb, 0x8f, 0x85, 0x54, 0xd2, 0xb2, 0x45, 0xbf,
    0x56, 0x95, 0x5e, 0x8d, 0xa3, 0x9e, 0xef, 0x01, 0xd2, 0x93,
    0x9c, 0xbb, 0x5e, 0x6f
};

/* Key buffer for hmac sha-512 computation */
static uint8_t gCryptoHmacSha512Key[APP_CRYPTO_HMAC_SHA512_INPUT_KEY_LENGTH] =
{
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 
    0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41, 0x42, 0x43
};

int32_t Crypto_hmacSha(Crypto_Params *params)
{
    int32_t status = EFTOK;
    int32_t i = 0;
    uint8_t hmacKey[CRYPTO_HMAC_SHA512_KEYLEN_BYTES];
    uint8_t tempOut[CRYPTO_HMAC_SHA512_KEYLEN_BYTES];
    uint8_t *pIpad, *pOpad;
    uint8_t  keybyte, maxKeyLengthInBytes, inputKeyLengthInBytes;

    if(NULL == params)
    {
        status = EFAIL;
    }
    else
    {
        switch(params->authMode)
        {
            case SA2UL_HASH_ALG_SHA2_512:
                maxKeyLengthInBytes  = CRYPTO_HMAC_SHA512_KEYLEN_BYTES;
                break;

            default:
                status = EFAIL;
                break;
        }

        if(EFTOK == status)
        {
            inputKeyLengthInBytes = ((uint32_t)params->keySizeInBytes);
            /* Check for KeyLength */
            if (inputKeyLengthInBytes > maxKeyLengthInBytes)
            {
                status = EFAIL;
            }
            else
            {
                /* Copy input Key */
                memcpy(hmacKey, (uint8_t *)&params->key, inputKeyLengthInBytes);
            }
        }
        if(EFTOK == status)
        {
            inputKeyLengthInBytes = ((uint32_t)params->keySizeInBytes);
            /* Check for KeyLength */
            if (inputKeyLengthInBytes > maxKeyLengthInBytes)
            {
                status = EFAIL;
            }
            else
            {
                /* Copy input Key */
                memcpy(hmacKey, (uint8_t *)&params->key, inputKeyLengthInBytes);

                /* Initialize the remaining bytes to zero if there are remaining bytes*/
                if(maxKeyLengthInBytes != inputKeyLengthInBytes)
                {
                    memset(hmacKey + inputKeyLengthInBytes, 0, maxKeyLengthInBytes - inputKeyLengthInBytes);
                }
                else
                {
                    /* Do nothing */
                }

                /* Stack optimization resue hmackey and tempOut buffers */
                pIpad = hmacKey;
                pOpad = tempOut;

                /* Compute Inner/Outer Padding  */
                for (i = 0; i < maxKeyLengthInBytes; i++)
                {
                    keybyte = hmacKey[i];
                    pIpad[i] = keybyte ^ CRYPTO_HMAC_SHA_IPAD;
                    pOpad[i] = keybyte ^ CRYPTO_HMAC_SHA_OPAD;
                }
                memcpy(&params->iPad, pIpad, maxKeyLengthInBytes);
                memcpy(&params->oPad, pOpad, maxKeyLengthInBytes);
            }
        }
    }
    return (status);
}


/**
 * \brief SA2UL crypto unit test
 *
 * Tests hash and decryption functions
 *
 * \param param test input (unused)
 *
 * \return retruns zero for no error, bit-field of functions failed in case
 *         of errors
 */

static const u8 test_ct_cbc[] = {
	0xcc, 0x39, 0xf2, 0x8c, 0x12, 0xd6, 0xcc, 0xce, 0xda, 0x64, 0x9c, 0x42,
	0x92, 0x38, 0x46, 0x69, 0xfd, 0xbf, 0xc4, 0xce, 0xc2, 0xae, 0x8e, 0x96,
	0x7c, 0xc1, 0xf4, 0xd8, 0x84, 0x40, 0x04, 0x06
};
static const u8 test_key[] = {
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03,
	0x04, 0x05, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07
};
static const u8 test_iv[] = {
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03,
	0x04, 0x05, 0x06, 0x07
};

#ifdef CONFIG_SECURITY_SA2UL_PKA
static u32 unittest_result[PKA_BIGINT_MAX + 1];

static fterr sa2ul_pka_changing_fwl_cfg()
{
    u32 ret = 0;
    ret = set_fw_region(2578, 1, 1, 0xA, 0x0000000004E00000, 0x0000000004E00FFF, ALL_RWCD,  ALL_RWCD, ALL_RWCD);

    if(ret == 0) {
        ret = set_fw_region(2578, 2, 1, 0xA, 0x0000000004E01000, 0x0000000004E011FF, ALL_RWCD,  ALL_RWCD, ALL_RWCD);
    }

    if(ret == 0) {
        ret = set_fw_region(2578, 3, 1, 0xA, 0x0000000004E10000, 0x0000000004E1007F, ALL_RWCD,  ALL_RWCD, ALL_RWCD);
    }

    if(ret == 0) {
        ret = set_fw_region(2578, 4, 1, 0xA, 0x0000000004E20000, 0x0000000004E2FFFF, ALL_RWCD,  ALL_RWCD, ALL_RWCD);
    }

    return ret ;
}


/**
 * \brief Unittest for RSA public key operation
 *
 * The keys used in this function are dummy/test keys and must not be used
 * for any other purpose.
 *
 * \return EFTOK if the test passed
 */
static fterr sa2ul_pka_unittest_rsa_publickey_op(void)
{
	fterr ret;
	static const struct rsa_pubkey pk = {
		{
			128UL,
			0xc0628553UL, 0x41822438UL, 0x6be272eaUL, 0x5eea0ed8UL,
			0x8964798aUL, 0x670429e0UL, 0x17251cd6UL, 0xc6a92ee6UL,
			0x385cc78cUL, 0xfea8f0c2UL, 0xfc0bb2eaUL, 0x9bbdf6b2UL,
			0xdefc66efUL, 0xacf33f30UL, 0x2ddb9a49UL, 0x2e8f8387UL,
			0xed6bf5f8UL, 0x36438d82UL, 0xbe9bc67fUL, 0x21c9521dUL,
			0xe9d69003UL, 0x45da7efaUL, 0x0b14fc02UL, 0x22e36226UL,
			0x290d7385UL, 0x0d69d33dUL, 0x7d1d9a43UL, 0xa3aa3c86UL,
			0xfa3eb699UL, 0x1eea74b3UL, 0xea871862UL, 0x2a08d378UL,
			0xc858dfb5UL, 0x8e528697UL, 0xc59e45ebUL, 0x3c49a74dUL,
			0x723c47eeUL, 0x56137b67UL, 0x17586eadUL, 0xe55f074bUL,
			0x02c59bfdUL, 0x9a8a3e7aUL, 0x4e30979cUL, 0xdf1f7f1fUL,
			0x489ef1d2UL, 0x0add0d95UL, 0x61a06facUL, 0x11e40cd3UL,
			0x984131a6UL, 0x4e176cfeUL, 0x05a48cf6UL, 0xfc2d479aUL,
			0x361a0abeUL, 0xdf3ff60bUL, 0x6d0c0551UL, 0xa7bf79b4UL,
			0x4433aefbUL, 0x7c686d34UL, 0x33855528UL, 0x3019be36UL,
			0x60d56e1eUL, 0xf0ef5a1cUL, 0x05075b78UL, 0x81c356b4UL,
			0x77f6eb73UL, 0xd8176711UL, 0x426bdc81UL, 0x7bddc862UL,
			0x6d3ecbb4UL, 0x157634e6UL, 0x96a1c437UL, 0x1f3eda96UL,
			0x011b6ac6UL, 0x0b275bcdUL, 0x68fca509UL, 0x871f4cd2UL,
			0x0512f388UL, 0x10907061UL, 0x0cfccc8eUL, 0x21a13dccUL,
			0x2d4067edUL, 0xf443840fUL, 0x91017002UL, 0x9e81b537UL,
			0x8896039bUL, 0x23f56551UL, 0xed7b8054UL, 0x59b40685UL,
			0xaa0ca240UL, 0x1f3f91baUL, 0x7aea7bd9UL, 0x0b11c6feUL,
			0x5b024e4cUL, 0x5b92b39fUL, 0x22be3ea5UL, 0x60de46f6UL,
			0xa55bee84UL, 0x8ce0ae19UL, 0x8983f6feUL, 0xc5e66470UL,
			0x1c528acaUL, 0xaa693ab6UL, 0x512dd24eUL, 0x8a09da02UL,
			0x16cf4357UL, 0xa8137625UL, 0xd107cb8dUL, 0x6236ea0fUL,
			0x7598eb79UL, 0x7c02360fUL, 0x5b8c18a3UL, 0x6794cdcdUL,
			0x6ef5a73fUL, 0x59a16edeUL, 0x3bde9bf0UL, 0xa6fc62afUL,
			0xe9ef1fedUL, 0x8f6c3526UL, 0xbb807be3UL, 0x001ffe16UL,
			0x687bea98UL, 0x21aa1e64UL, 0xb26e506bUL, 0x6a3f5082UL,
			0xd17b6c5eUL, 0x9e1cf115UL, 0xc16a2c30UL, 0xbc4e97e7UL,
		},
		{
			1UL,
			0x00010001UL
		}
	};

	static const u32 mesg[] = {
		128UL,
		0x567bb4acUL,0xf7481a00UL,  0x69b18f3eUL, 0x10be3c56UL,
		0xabe133f0UL,0xd2ce9cc6UL,  0xe4694e98UL, 0xbb2c557aUL,
		0x85f36e14UL,0xe73d002aUL,  0x7c271b8dUL, 0xc3867ef2UL,
		0xf4937eebUL,0x207059c1UL,  0x6e482f38UL, 0x8c973353UL,
		0xa2ee8ed6UL,0x3b55c1d3UL,  0x7a5c95d4UL, 0xbd7eddb9UL,
		0x3a513750UL,0x4ad3bcc3UL,  0x0722a4f8UL, 0xec37d8b0UL,
		0x3e908422UL,0x304df2cdUL,  0x655938e0UL, 0x700d0f17UL,
		0x9e0e48f6UL,0xb980c642UL,  0x9564a147UL, 0xef596ef0UL,
		0xd8c1be99UL,0x7ac9e5d3UL,  0xe4850abcUL, 0x6c3c2c2eUL,
		0x3f0df20eUL,0x7eff8401UL,  0x728d45b6UL, 0x580450dfUL,
		0x0b56f991UL,0xe339043aUL,  0xe932136bUL, 0xae65b3a9UL,
		0x6af9d57bUL,0x9d3ecef4UL,  0xf4eadfc7UL, 0xd9f67583UL,
		0x3d0ff3e2UL,0xd3d255ccUL,  0xc8cfddc1UL, 0x49fa11c0UL,
		0x4ae5316bUL,0x5330efc9UL,  0x7c632d6cUL, 0xb771d60eUL,
		0x8afae3e3UL,0xf4f141e7UL,  0x56d6d695UL, 0xa080ee8fUL,
		0x72a5c0a2UL,0x1392c8f1UL,  0xa4725410UL, 0x79e96983UL,
		0xc2b994b5UL,0xaae9926aUL,  0x4c93f260UL, 0x679526a4UL,
		0xd5fe9a0dUL,0x22f80e99UL,  0xc887ec46UL, 0x88121b64UL,
		0xecca17b9UL,0x7af0064fUL,  0x5f9baf7dUL, 0xa94b56a1UL,
		0x041f5279UL,0x68d34991UL,  0x7f2b1308UL, 0x910b54d6UL,
		0xc5b22f04UL,0x27e3c7abUL,  0x556a83b3UL, 0x65bf7aa1UL,
		0xe2a210deUL,0x080cc18aUL,  0xcf423214UL, 0x0dfb6dbdUL,
		0xbecf4aafUL,0xd04ab87dUL,  0xa315ad52UL, 0xcba6777bUL,
		0x451861d1UL,0x53b81631UL,  0x2162069aUL, 0x8ddc5143UL,
		0xffc0db62UL,0xbd35021bUL,  0x85b4bdcaUL, 0x69e888baUL,
		0x1d6e88abUL,0x4ee4d138UL,  0xe455b349UL, 0x8da47161UL,
		0x0a382746UL,0x09dc3296UL,  0x7c936578UL, 0xa85e6ee6UL,
		0x3d426609UL,0x9e36f456UL,  0x32e097ebUL, 0x03283f1fUL,
		0xaad8dbd8UL,0xe5e4ffedUL,  0x4c25e772UL, 0x04c53c77UL,
		0x226faa00UL,0xb49a27f7UL,  0x2f13fd1cUL, 0xfc87bf17UL,
		0x1bf97693UL,0x8f000eeaUL,  0xf1c91645UL, 0x9cdcaf24UL,
		0x4be21fdaUL,0x11f5cd3eUL,  0x4c2bc344UL, 0x55f47ebfUL,
	};

	static const u32 result[] = {
		128UL,
		0xc8e865c5UL,0x2c4d0a2bUL,  0x1285ffbfUL, 0xf12aeb26UL,
		0xe3de9a84UL,0x63091341UL,  0x9eaf7a5aUL, 0xaa1227a5UL,
		0xf06b8f1bUL,0xe28abd17UL,  0x265d2201UL, 0x4fe917bbUL,
		0x04232347UL,0x5dec325dUL,  0x807e406aUL, 0x44d78892UL,
		0x05000440UL,0x03040203UL,  0x86480165UL, 0x0d060960UL,
		0x00305130UL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0xffffffffUL,
		0xffffffffUL,0xffffffffUL,  0xffffffffUL, 0x0001ffffUL,
	};

	ret = sa2ul_pka_modexp(mesg, &pk, unittest_result);
	TRACE_info_arg_hsm("sa2ul_pka_modexp returned ", ret);

	if (EFTOK != ret) {
		return ret;
	}

	if (0 != memcmp(unittest_result, result, ((result[0] + 1) << 2))) {
		TRACE_info("\r\nsa2ul_pka_modexp output did not match reference value\n");
		return -EFAIL;
	}
    else
    {
		TRACE_err("\nsa2ul_pka_modexp output  matched reference value\n");
    }
	return ret;
}

/**
 * \brief Unittest for RSA private key operation
 *
 * The keys used in this function are dummy/test keys and must not be used
 * for any other purpose.
 *
 * \return EFTOK if the test passed
 */
static fterr sa2ul_pka_unittest_rsa_privatekey_op(void)
{
	fterr ret;
	static const struct rsa_pubkey publickey = {
		{
			128UL,
			0x7b0e1331UL, 0x21d93fafUL, 0xf24ace7cUL, 0x2e1c2805UL,
			0x2505b8eaUL, 0x789f6d3bUL, 0x1429332dUL, 0x410ebcb3UL,
			0x11765fc0UL, 0xa37281bcUL, 0xdcb72cd4UL, 0x057f8582UL,
			0xfbc664dbUL, 0x1c68e56dUL, 0x483dfb84UL, 0x01d8ce5fUL,
			0x666f510fUL, 0xd66bce5bUL, 0x53128269UL, 0x2a5bc8deUL,
			0x33224cf4UL, 0x404f5f67UL, 0xb9c4ddb2UL, 0x3108f01eUL,
			0xe96ef837UL, 0x832dd1d8UL, 0x9ce4657fUL, 0x1fc750e2UL,
			0xe56ddc7aUL, 0x3ca08e2bUL, 0xe1681392UL, 0x5349c63bUL,
			0x15573eaeUL, 0x5bd785baUL, 0xe1fa83ebUL, 0x5860ef1aUL,
			0x97a1a781UL, 0xe7c030a1UL, 0x3bf7f3beUL, 0x48fb8c89UL,
			0x33396e99UL, 0x3f5b1c31UL, 0x01d54503UL, 0x32c2a394UL,
			0x64a3442cUL, 0xf0649355UL, 0xe2f14dacUL, 0xf00003d4UL,
			0xa8682317UL, 0x36d2d946UL, 0x7baba2a1UL, 0x1b8bbc58UL,
			0xdbdc7cd8UL, 0xb61282d3UL, 0xcf7d65bfUL, 0x31b35f75UL,
			0x40be8c50UL, 0xf946f67aUL, 0x450c18daUL, 0xc5795ef1UL,
			0x4ccbbf3dUL, 0x43ebf4f2UL, 0xc142ea50UL, 0x743c5aa2UL,
			0xca0a694aUL, 0x32955c4fUL, 0x976a1201UL, 0xfb44d6d3UL,
			0xe3883664UL, 0xed0a2672UL, 0x254f61d6UL, 0xd69a18a0UL,
			0x8aa18f2eUL, 0xee03607fUL, 0x1efbf353UL, 0xa214f8efUL,
			0x327d7d42UL, 0x3d9c5f31UL, 0x5199a7feUL, 0xb26102f0UL,
			0x7141e13bUL, 0xbcdb90d9UL, 0xab5d6e43UL, 0x9fe13e24UL,
			0xd52cd201UL, 0x27be8644UL, 0x5e74f8d4UL, 0x7afa882bUL,
			0xbde373faUL, 0x33c610c5UL, 0x247565b1UL, 0xf3e2d8bcUL,
			0xf68276fcUL, 0xba47267fUL, 0xf73c50a0UL, 0xedf36518UL,
			0x54be80d8UL, 0x1e853affUL, 0x4177cdd7UL, 0xfcc9260dUL,
			0xe6990f32UL, 0x17123409UL, 0x56492020UL, 0xcf1cfbd2UL,
			0x5d69f234UL, 0x10cee084UL, 0x8ed5b7fcUL, 0x041fc1e1UL,
			0xcd5f19acUL, 0xb1014231UL, 0x777c44d3UL, 0x9fa34027UL,
			0x8bda12ccUL, 0xcb0f8867UL, 0x7d2ccacdUL, 0x2f6d136bUL,
			0xb79c5a8cUL, 0xaa330759UL, 0x35b7bc90UL, 0x1f42046cUL,
			0x590e87b9UL, 0x2dc89592UL, 0x2819e1ffUL, 0xdd1e9ca1UL,
			0x2690ed1dUL, 0x05034434UL, 0xab4633b2UL, 0xc44fc6efUL,
		},
		{   1UL,
		    0x00010001UL, }
	};

	static const struct rsa_privkey privatekey = {
		{
			128UL,
			0x7b0e1331UL, 0x21d93fafUL, 0xf24ace7cUL, 0x2e1c2805UL,
			0x2505b8eaUL, 0x789f6d3bUL, 0x1429332dUL, 0x410ebcb3UL,
			0x11765fc0UL, 0xa37281bcUL, 0xdcb72cd4UL, 0x057f8582UL,
			0xfbc664dbUL, 0x1c68e56dUL, 0x483dfb84UL, 0x01d8ce5fUL,
			0x666f510fUL, 0xd66bce5bUL, 0x53128269UL, 0x2a5bc8deUL,
			0x33224cf4UL, 0x404f5f67UL, 0xb9c4ddb2UL, 0x3108f01eUL,
			0xe96ef837UL, 0x832dd1d8UL, 0x9ce4657fUL, 0x1fc750e2UL,
			0xe56ddc7aUL, 0x3ca08e2bUL, 0xe1681392UL, 0x5349c63bUL,
			0x15573eaeUL, 0x5bd785baUL, 0xe1fa83ebUL, 0x5860ef1aUL,
			0x97a1a781UL, 0xe7c030a1UL, 0x3bf7f3beUL, 0x48fb8c89UL,
			0x33396e99UL, 0x3f5b1c31UL, 0x01d54503UL, 0x32c2a394UL,
			0x64a3442cUL, 0xf0649355UL, 0xe2f14dacUL, 0xf00003d4UL,
			0xa8682317UL, 0x36d2d946UL, 0x7baba2a1UL, 0x1b8bbc58UL,
			0xdbdc7cd8UL, 0xb61282d3UL, 0xcf7d65bfUL, 0x31b35f75UL,
			0x40be8c50UL, 0xf946f67aUL, 0x450c18daUL, 0xc5795ef1UL,
			0x4ccbbf3dUL, 0x43ebf4f2UL, 0xc142ea50UL, 0x743c5aa2UL,
			0xca0a694aUL, 0x32955c4fUL, 0x976a1201UL, 0xfb44d6d3UL,
			0xe3883664UL, 0xed0a2672UL, 0x254f61d6UL, 0xd69a18a0UL,
			0x8aa18f2eUL, 0xee03607fUL, 0x1efbf353UL, 0xa214f8efUL,
			0x327d7d42UL, 0x3d9c5f31UL, 0x5199a7feUL, 0xb26102f0UL,
			0x7141e13bUL, 0xbcdb90d9UL, 0xab5d6e43UL, 0x9fe13e24UL,
			0xd52cd201UL, 0x27be8644UL, 0x5e74f8d4UL, 0x7afa882bUL,
			0xbde373faUL, 0x33c610c5UL, 0x247565b1UL, 0xf3e2d8bcUL,
			0xf68276fcUL, 0xba47267fUL, 0xf73c50a0UL, 0xedf36518UL,
			0x54be80d8UL, 0x1e853affUL, 0x4177cdd7UL, 0xfcc9260dUL,
			0xe6990f32UL, 0x17123409UL, 0x56492020UL, 0xcf1cfbd2UL,
			0x5d69f234UL, 0x10cee084UL, 0x8ed5b7fcUL, 0x041fc1e1UL,
			0xcd5f19acUL, 0xb1014231UL, 0x777c44d3UL, 0x9fa34027UL,
			0x8bda12ccUL, 0xcb0f8867UL, 0x7d2ccacdUL, 0x2f6d136bUL,
			0xb79c5a8cUL, 0xaa330759UL, 0x35b7bc90UL, 0x1f42046cUL,
			0x590e87b9UL, 0x2dc89592UL, 0x2819e1ffUL, 0xdd1e9ca1UL,
			0x2690ed1dUL, 0x05034434UL, 0xab4633b2UL, 0xc44fc6efUL,
		},
		{
			1UL,
			0x00010001UL,
		},
		{
			128UL,
			0x10419db5UL, 0x3627a236UL, 0xd5849feaUL, 0x3282d947UL,
			0xd2ea3de8UL, 0x1b1e8b4bUL, 0x902fda40UL, 0x4c67aa7aUL,
			0xd498779bUL, 0x7487d923UL, 0x7a7eef40UL, 0x3d074813UL,
			0x0e15d488UL, 0xfe0ad4d1UL, 0x1bd3fa06UL, 0xcd4add45UL,
			0x9fbe8cc8UL, 0xc0a9a662UL, 0xd548522dUL, 0xdf2922e1UL,
			0xfe3de915UL, 0xc348fc61UL, 0xfe2ff563UL, 0xb812d879UL,
			0x6336a88fUL, 0x7fa5a7d0UL, 0x4ff33e9fUL, 0x251eb5a3UL,
			0xaeff0201UL, 0x4bcb2073UL, 0x2282f9b4UL, 0xe0d83f5aUL,
			0x41e440b4UL, 0x219afde3UL, 0x28559641UL, 0xf4abdcdaUL,
			0xe3b49b85UL, 0xf178d643UL, 0xa408c55dUL, 0x0ee6d9a5UL,
			0xa6781eb4UL, 0x0e991ebaUL, 0xa13398bfUL, 0x449e1b56UL,
			0xcf15116cUL, 0x11302565UL, 0x4edb594fUL, 0xd749c93dUL,
			0x838eac8aUL, 0x2ad2d58dUL, 0x55eb8d39UL, 0xaa15bd0eUL,
			0xc6c0ec10UL, 0xf977ba52UL, 0xfb8c380aUL, 0xda9cab52UL,
			0x88bf4b3fUL, 0x51a28f3bUL, 0xd1b2fec1UL, 0x0b9924f4UL,
			0x96e773a6UL, 0x28b28238UL, 0xdcd83accUL, 0xca8ab55cUL,
			0xd2db3868UL, 0x2ddbed80UL, 0x14c55619UL, 0x06f388afUL,
			0xe48436c4UL, 0x211ecf5fUL, 0x5213bfecUL, 0x4b7df219UL,
			0x46f80707UL, 0x2ce17127UL, 0xd8ad3061UL, 0x3da46129UL,
			0xd117f13dUL, 0x748feefcUL, 0x5c757effUL, 0xe857d95cUL,
			0xb4542a7bUL, 0x1498c4e4UL, 0xfa001cf0UL, 0xcf00c0beUL,
			0x56efbfcdUL, 0x9e803291UL, 0xb55023cbUL, 0x266005faUL,
			0xcb4dc5f2UL, 0x1710b011UL, 0x91443865UL, 0x9dbf9f2fUL,
			0x3b9cf301UL, 0x27716c63UL, 0x3a733ac0UL, 0xd8a9d375UL,
			0xd3b836a2UL, 0x597c61ffUL, 0xc72cd571UL, 0x29e252c5UL,
			0x17c4800dUL, 0x9a552400UL, 0xca817f97UL, 0xac48ac07UL,
			0xeb161001UL, 0x22489aa6UL, 0xe66e63f6UL, 0x6101a293UL,
			0xa866553dUL, 0x88e654bfUL, 0xcd49f414UL, 0xa1a179e0UL,
			0x209c323dUL, 0x0d67d0c1UL, 0x6e49cb85UL, 0x607f314aUL,
			0xe0171a47UL, 0xf45bc7cfUL, 0xff4699c2UL, 0xa53a5faeUL,
			0x43a9d8b6UL, 0x80311a85UL, 0xefd571d8UL, 0x1a2fc991UL,
			0xef87566bUL, 0x86524b55UL, 0xa81e866eUL, 0x86701fcbUL,
		},
		{
			64UL,
			0xbb427bfbUL, 0x20751184UL, 0xa3c30577UL, 0x57860858UL,
			0x91b400daUL, 0x039abd73UL, 0xde2ab0e0UL, 0x9f7461a7UL,
			0xb0a8eefaUL, 0xd243edeeUL, 0xfe98727eUL, 0x0e16b7a8UL,
			0x3ee2a197UL, 0xa4818a70UL, 0x0252031aUL, 0x0d319871UL,
			0x74000a85UL, 0x92322a99UL, 0x97528ccbUL, 0x379706b8UL,
			0xdec994aeUL, 0xa2b1c043UL, 0x9304d233UL, 0x1bb04a5aUL,
			0x7d5011f3UL, 0xc196fc5cUL, 0xa77e67c6UL, 0x93391a97UL,
			0x332579dbUL, 0x8fae025fUL, 0x916b27daUL, 0x9f68ff9cUL,
			0xd38bdc5bUL, 0x7f51ded1UL, 0x9e4b925cUL, 0x54fd6e39UL,
			0xf6018e7eUL, 0x037a0515UL, 0x0f37b15fUL, 0xa0c8abbdUL,
			0x775c6d6dUL, 0xc26846adUL, 0x822fc2e2UL, 0x81d88215UL,
			0x9dd17935UL, 0x5691073bUL, 0x90177682UL, 0xf2a7ee34UL,
			0x3464cd12UL, 0x1dc7785bUL, 0x90d5648fUL, 0x4c6aac82UL,
			0xc95e0ac0UL, 0x88aedb5fUL, 0x878e6626UL, 0xf792a736UL,
			0xd90fb07aUL, 0xc5b9583dUL, 0xa90c3640UL, 0xf21ba87aUL,
			0xcdb2dcf5UL, 0xe3a516b1UL, 0xbae16d87UL, 0xe28e0fc2UL,
		},
		{
			64UL,
			0xf77079c3UL, 0x49377587UL, 0x1e129263UL, 0x3c3f8120UL,
			0xb5a82126UL, 0x674d602dUL, 0x0e3c3073UL, 0x223eae9bUL,
			0xca12c56aUL, 0x8b9a6839UL, 0x7fb49cd3UL, 0xa8ee610fUL,
			0x696f7ec2UL, 0x282b3d3dUL, 0x4e387622UL, 0x5fff85a6UL,
			0x0d224c23UL, 0x35676878UL, 0x444eca3dUL, 0x62984d27UL,
			0xdc601db2UL, 0x4e7c65dbUL, 0x041c37c2UL, 0x5baf3823UL,
			0x228e69d6UL, 0xda9c94b6UL, 0xff406ed0UL, 0x32ee08d4UL,
			0x07edfe8fUL, 0x3c8f45d3UL, 0x9036cdafUL, 0x23eba296UL,
			0x09aa1a8bUL, 0x588982c1UL, 0xce249fe5UL, 0xccd0697fUL,
			0x2123fbd0UL, 0x872e4a00UL, 0xf8dd8629UL, 0xd3339685UL,
			0x0a8e7e7dUL, 0xc9c1db9dUL, 0x887b0dceUL, 0xab03b817UL,
			0x12a618f6UL, 0xf01a7a81UL, 0x804a6e25UL, 0x7c1f6999UL,
			0xecffb98eUL, 0x972a3c24UL, 0x71363317UL, 0x4ff950d6UL,
			0xf20754a5UL, 0xcd2bb01bUL, 0xdd44a55aUL, 0x547b9e5bUL,
			0x00be92bcUL, 0x1ab22b80UL, 0xd5ffa49cUL, 0xc52f5616UL,
			0xaa3f5d8eUL, 0x37dacba3UL, 0xdd2285f8UL, 0xddd375c9UL,
		},
		{
			64UL,
			0x385fa1d3UL, 0x25079e5dUL, 0x62c75315UL, 0x7c22bdafUL,
			0xf38f2b75UL, 0x33eabe6cUL, 0x7f4a901cUL, 0x232641d8UL,
			0x81dfbaffUL, 0x0dd63792UL, 0xc4d0aca6UL, 0xbe950e8bUL,
			0x635be3a3UL, 0x8f205599UL, 0xefb6225cUL, 0xc7eb6f0bUL,
			0x6ba2c01aUL, 0x3435bf4cUL, 0x2747711bUL, 0x41e4d8e8UL,
			0x4632b238UL, 0x39b36a11UL, 0xe4950e89UL, 0xe35ba249UL,
			0x28fa2a4aUL, 0xc48770a6UL, 0xc849e4d7UL, 0x2b773fceUL,
			0xc0af596bUL, 0xf67f0575UL, 0x7fc7056aUL, 0xadf756e4UL,
			0xe73fa862UL, 0x3e0b2254UL, 0x25e0db0fUL, 0xc7b6354dUL,
			0xc09cc298UL, 0xa6093906UL, 0xdd749008UL, 0x699e5d66UL,
			0x63a7d948UL, 0x86c4ad04UL, 0x9217cc60UL, 0xafdb7b53UL,
			0x862ca3efUL, 0x119de261UL, 0xe03fb34eUL, 0x374642a9UL,
			0xdc6932cfUL, 0x76a6d732UL, 0x28292b35UL, 0xb3ce65a2UL,
			0xcae36c2bUL, 0xd1d63ec9UL, 0x3b359689UL, 0x13ec8f26UL,
			0x09be568fUL, 0x81017021UL, 0x9b8cc5baUL, 0x969ead27UL,
			0xc7b84c86UL, 0xe5b509eeUL, 0xc07eafd5UL, 0xa6b1fa7cUL,
		},
		{
			64UL,
			0x81028f61UL, 0xb21c2fc0UL, 0x45eba179UL, 0x350e30b9UL,
			0xd96ea46aUL, 0x301f730bUL, 0x40f3af1dUL, 0xe0c6307dUL,
			0xf6954d0dUL, 0x801d8571UL, 0x7155d536UL, 0x9cafd2a8UL,
			0x2548c02fUL, 0xa672c802UL, 0x7eb96128UL, 0xbf96fcb1UL,
			0xd6e9149aUL, 0x90c61adbUL, 0x2bd62fb8UL, 0x2b6b7fc8UL,
			0xf2e97f86UL, 0x4d012c9eUL, 0x504d0dcfUL, 0xf9589109UL,
			0x57adda85UL, 0x52fc3692UL, 0x1452e502UL, 0xcfd04eb3UL,
			0x772411afUL, 0xc6a5c54fUL, 0x2ec8262eUL, 0xf4638629UL,
			0x6782ee0dUL, 0xcc07cf86UL, 0x71d67368UL, 0x1ed27a91UL,
			0x98e60189UL, 0x15235971UL, 0x145306deUL, 0x6b8531daUL,
			0xe552d84fUL, 0xe5c79574UL, 0x1db17d82UL, 0x364b68a8UL,
			0x7e75cf7bUL, 0xd620d18cUL, 0x68a3c932UL, 0xe634bc8dUL,
			0xa2e5261dUL, 0x23230d06UL, 0xb40ffb57UL, 0x5134fbb8UL,
			0x812aed7eUL, 0x27aef659UL, 0x648589bfUL, 0x17b41381UL,
			0xf588844eUL, 0x099272e0UL, 0xd0f71c74UL, 0xb05bf299UL,
			0xadb14466UL, 0x70fc7798UL, 0xab18606dUL, 0x7ac57e7bUL,
		},
		{
			64UL,
			0x2a234108UL, 0x26f10c77UL, 0x37e0a93eUL, 0xc94e27d0UL,
			0x620ab868UL, 0xc4866d92UL, 0x9501fbbbUL, 0x2d06af39UL,
			0xce96fc6fUL, 0x5ccdebb3UL, 0xea246fcbUL, 0xeddb7827UL,
			0x02ef25c5UL, 0x67599648UL, 0x27504ae2UL, 0x44d46183UL,
			0xa3f56968UL, 0x8d65fccaUL, 0x1bd53f81UL, 0x4d27cab5UL,
			0xaa24c5d1UL, 0x7270acc7UL, 0xa13ec3fdUL, 0x99180cc9UL,
			0xf18088ebUL, 0xdc972949UL, 0x59735d92UL, 0x0c860739UL,
			0x9fb2a99cUL, 0x0f25e5f2UL, 0x9bc17e3dUL, 0x97f5e8c0UL,
			0x63e7ee46UL, 0x0962df6bUL, 0x2c976df5UL, 0x88c0e9a9UL,
			0xb59730c0UL, 0x7efa7686UL, 0xebffbf5bUL, 0xaa4baeecUL,
			0xd5cec7b9UL, 0x4643bc53UL, 0xf736f7e8UL, 0x9ff978f6UL,
			0xdc563955UL, 0x04e95707UL, 0xb3ec6c74UL, 0x63db5cbaUL,
			0x12523994UL, 0x37986104UL, 0x09ed6e97UL, 0x1d635a00UL,
			0x3854fa3dUL, 0xfb3ebfecUL, 0x79c6d046UL, 0xa06c5cecUL,
			0xf6f3b75bUL, 0x17c3eb0aUL, 0xc92d3dd2UL, 0x18afbaebUL,
			0x1bbcc397UL, 0x4526cb3fUL, 0x76c2993fUL, 0x22bca33eUL,
		}
	};

	static const u32 signature[] = {
		128UL,
		0x3c2bdf16UL,0x4426b089UL,  0xc19b5111UL, 0xebf5e82aUL,
		0xeb87bff6UL,0x639b4588UL,  0xa7514915UL, 0x83ff77d8UL,
		0x007556a2UL,0x65061985UL,  0xc1b2252bUL, 0x96370d40UL,
		0x1a6a7c8aUL,0x53810104UL,  0x3b7137acUL, 0xae8ff417UL,
		0xe745c58fUL,0x3d78b4a6UL,  0x679258d6UL, 0x733d183eUL,
		0x3a455d3fUL,0x75ee7450UL,  0x4bdaea60UL, 0x0dcc2b2eUL,
		0x8d3be612UL,0x233be05aUL,  0x9ecbd99eUL, 0xa4fe1ccaUL,
		0x26c176cbUL,0x28726e29UL,  0x44e80046UL, 0x2c475bc6UL,
		0xdf1e3b08UL,0x53c3db73UL,  0x785cb9d5UL, 0xaa8db5d6UL,
		0xb3258545UL,0x30a5a698UL,  0xf1d908edUL, 0x96bd44cdUL,
		0x2b8cfda5UL,0x5f874cc7UL,  0xa3564a3dUL, 0xf84aa301UL,
		0xc46a6890UL,0x9fb6a407UL,  0x970c4896UL, 0x8b000586UL,
		0x37c97c10UL,0x9353b623UL,  0x55d07151UL, 0xdc965b03UL,
		0xf90afc05UL,0x9487cc6aUL,  0x26426ac0UL, 0xa6f25dd5UL,
		0xb9247e1dUL,0x8ed1204cUL,  0x01498a17UL, 0xa65219d2UL,
		0xfc9048d6UL,0x2bb83efaUL,  0xbc325407UL, 0x83ca4732UL,
		0x066da945UL,0xd1a58cb5UL,  0xbb2cad7dUL, 0xc6fdad15UL,
		0xce5fef80UL,0x03bfc867UL,  0x8147ab51UL, 0x0af6313cUL,
		0x22eb6c73UL,0x6950e9fcUL,  0x046c1bcbUL, 0x9b81b856UL,
		0xb64cc0e2UL,0x5b245797UL,  0x3e2fd20cUL, 0xcdc12a2fUL,
		0x179cf3c2UL,0xb38554aeUL,  0xfc187000UL, 0x0df189c7UL,
		0x3c74ce1aUL,0xe30e0cf6UL,  0x2299e7cfUL, 0xb6f7d36cUL,
		0x383d1721UL,0x2de9a694UL,  0x84f6c08cUL, 0xe7514144UL,
		0xf14b3243UL,0xc03b9a2bUL,  0x1ece1045UL, 0xb7d26375UL,
		0x06c23d6bUL,0x4a398ac9UL,  0xd277774cUL, 0xd3ae2286UL,
		0x4a99f3eaUL,0xd12e6b9eUL,  0x0eafd882UL, 0x666d017cUL,
		0x628ade73UL,0xc831d4d1UL,  0x94b6414aUL, 0x1f3d7d91UL,
		0x630073f1UL,0xa560dd74UL,  0x47d3ce78UL, 0x1582a2e3UL,
		0x002cead0UL,0xa00e6fa8UL,  0x971f3211UL, 0x95374ecdUL,
		0xf6f90e1fUL,0xb67c3029UL,  0x445d5590UL, 0xc0ea1286UL,
		0xfaed59f4UL,0x5f5db050UL,  0x7cd689f4UL, 0x464d5e77UL,
		0x04373960UL,0x7d7026f1UL,  0x1f083072UL, 0x2790e411UL,
	};

	ret = sa2ul_pka_modexp(signature, &publickey, unittest_result);
	TRACE_info_arg_hsm("\nsa2ul_pka_modexp returned ", ret);

	if (EFTOK != ret) {
		return ret;
	}

	ret = sa2ul_pka_modexp_crt(unittest_result, &privatekey,
				   unittest_result);
	TRACE_info_arg_hsm("\nsa2ul_pka_modexp_crt returned ", ret);

	if (EFTOK != ret) {
		return ret;
	}

	if (0 != memcmp(unittest_result, signature, sizeof(signature))) {
		TRACE_info("\r\nsa2ul_pka_modexp_crt op did not match reference op\n");
		ret = -EFAIL;
    }
    else
    { 
		TRACE_err("\nsa2ul_pka_modexp_crt op matched reference op\n");
    }
    
	return ret;
}
#endif
// /**
//  * \brief SA2UL crypto unit test
//  *
//  * Tests hash and decryption functions
//  *
//  * \param param test input (unused)
//  *
//  * \return retruns zero for no error, bit-field of functions failed in case
//  *         of errors
//  */

static fterr sa2ul_crypto_ut_decrypt(u8 *buf, u32 len,
				     const u8 *key, const u8 *iv)
{
	soc_phys_addr_t pbuf;
	fterr ret;

	ret = socmem_to_global((local_phys_addr_t) buf, &pbuf);

	if (ret == EFTOK) {
		ret = sa2ul_aes_256_cbc_decrypt(pbuf, len, HOST_ID_TIFS,
						key, iv);
	}
	return ret;
}

u32 sa2ul_crypto_unittest(void)
{
    u32 ret = 0UL;
    u8 op[140];
    u8 hash[HASH_MAX_LEN];
#ifdef CONFIG_SECURITY_SA2UL_TRNG
    u8 data[16U];
    u32 j;
#endif
	Crypto_Params       params;
    volatile u32 wait_in_loop = 0xABCD;

    mask_interrupts();
    memcpy(op, rand_bin, sizeof(rand_bin));

    /* Calling SA2UL operation for calculating HASH of input data*/
    if (EFTOK != sa2ul_hash_dmsc((void *) op, sizeof(rand_bin),
                     HASH_ALGO_SHA2_512, hash)) {
        ret = ret | (1U << 0);
    }
    
    if (0 != memcmp(op, rand_bin, sizeof(rand_bin))) {
    	while(wait_in_loop);
    }

#ifdef CONFIG_DEBUG_TRACE  
    TRACE_info("\r\n\n");
    TRACE_info("\r\nSA2UL SHA output\n ");
	TRACE_info("\r\n========================\n");

    for (j=0;j<sizeof(hash);j++){
        TRACE_info_arg_hsm("",hash[j]);
        if((j+1)%8 == 0){
            TRACE_info("\r\n");       
        }
    }

    TRACE_info("\r\n\n");
#endif

    if (0 !=
        memcmp(hash, rand_bin_sha512sum, sizeof(rand_bin_sha512sum))) {
        TRACE_info("\r\n SA2UL SHA EXMAPLE FAILED \n");
        while(wait_in_loop);
    }
    
    else
    {
		sa2ul_status |= SHA_TEST_STATUS;
        TRACE_info("\r\n SA2UL SHA EXMAPLE PASSED \n");
        TRACE_info("\r\n#############  END OF HSM SHA Example DEMO    ############## \n");
    }

    TRACE_info("\r\n#############  START OF HSM AES Example DEMO    ############## \n");
    
    memcpy(op, test_ct_cbc, sizeof(test_ct_cbc));
    if (EFTOK != sa2ul_crypto_ut_decrypt(op, sizeof(test_ct_cbc),
                         test_key, test_iv)) {
        while(wait_in_loop);
    }
    if (0 != memcmp(op, test_pt, sizeof(test_pt))) {
        TRACE_info("\r\n SA2UL AES EXMAPLE FAILED \n");
    }
    else{
		sa2ul_status |= AES_TEST_STATUS;
        TRACE_info("\r\n SA2UL AES EXMAPLE PASSED \n");   
    }

    TRACE_info("\r\n#############  END OF HSM AES Example DEMO    ############## \n");
/*For AM62A devices TRNG support not enabled with mcu sdk release V9.0*/
#ifdef CONFIG_SECURITY_SA2UL_TRNG
    TRACE_info("\r\nTRNG TEST\n ");
    TRACE_info("\r\n========================\n");

    ret = sa2ul_rng_init();
    if (ret == EFTOK) {
     ret = sa2ul_rng_setup(SA2UL_INSTANCE_TIFS_TRNG, SA2UL_TRNG_MODE_NO_DRBG);
    }
    else
    {
     TRACE_err("\nTRNG init fail\n");
    }
    if (ret == EFTOK)
    {
         if (ret == EFTOK) {
             ret = sa2ul_rng_read(SA2UL_INSTANCE_TIFS_TRNG, (u32 *) data);
         }
         if (ret == EFTOK) {
             TRACE_info("\r\nTRNG OUTPUT\n ");
             TRACE_info("\r\n========================\n");
             for (j=0;j<sizeof(data);j++){
                 TRACE_info_arg_hsm("",data[j]);
             }
		sa2ul_status |= TRNG_TEST_STATUS;

         }
         else
         {
             TRACE_err("\nTRNG read fail\n");
         }
    }
    else
    {
     TRACE_err("RNG setup fail\n");
    }

    if (ret == EFTOK)
    {
         if (ret == EFTOK) {
             ret = sa2ul_rng_read(SA2UL_INSTANCE_TIFS_TRNG, (u32 *) data);
         }
         if (ret == EFTOK) {
             TRACE_info("\r\nTRNG OUTPUT\n ");
             TRACE_info("\r\n========================\n");
             for (j=0;j<sizeof(data);j++){
                 TRACE_info_arg_hsm("",data[j]);
             }
         }
         else
         {
             TRACE_err("\nTRNG read fail\n");
         }
    }
    else
    {
     TRACE_err("RNG setup fail\n");
    }
#endif
    memcpy(op, gCryptoHmacSha512TestInputBuf, sizeof(gCryptoHmacSha512TestInputBuf));
    TRACE_info("\r\nInput data to SA2UL SHA\n");

    params.authMode                 = SA2UL_HASH_ALG_SHA2_512;    
    memcpy(&params.key, gCryptoHmacSha512Key, APP_CRYPTO_HMAC_SHA512_INPUT_KEY_LENGTH);
    params.keySizeInBytes           = sizeof(gCryptoHmacSha512Key);
    ret = Crypto_hmacSha(&params);

    memcpy((void *)gCryptoHmacSha512Ipad, params.iPad,APP_CRYPTO_HMAC_SHA512_KEYLEN_IN_BYTES);
    memcpy((void *)gCryptoHmacSha512Opad, params.oPad,APP_CRYPTO_HMAC_SHA512_KEYLEN_IN_BYTES);

    memcpy((void*)gCryptoHmacTemp,(void *)gCryptoHmacSha512Ipad,APP_CRYPTO_HMAC_SHA512_KEYLEN_IN_BYTES);
    memcpy((void*)&gCryptoHmacTemp[APP_CRYPTO_HMAC_SHA512_KEYLEN_IN_BYTES],(void*)gCryptoHmacSha512TestInputBuf,sizeof(gCryptoHmacSha512TestInputBuf));

    memcpy(op, gCryptoHmacTemp, sizeof(gCryptoHmacTemp));

    /* Calling SA2UL operation for calculating HASH of input data*/
    if (EFTOK != sa2ul_hash_dmsc((void *) op, sizeof(gCryptoHmacTemp),
                     HASH_ALGO_SHA2_512, hash)) {
        ret = ret | (1U << 0);
    }

    memcpy((void*)gCryptoHmacTemp2,(void *)gCryptoHmacSha512Opad,APP_CRYPTO_HMAC_SHA512_KEYLEN_IN_BYTES);
    memcpy((void*)&gCryptoHmacTemp2[APP_CRYPTO_HMAC_SHA512_KEYLEN_IN_BYTES],hash,APP_CRYPTO_HMAC_SHA512_OUTPUT_LENGTH);    

    if (EFTOK != sa2ul_hash_dmsc((void *) gCryptoHmacTemp2, APP_CRYPTO_HMAC_SHA512_KEYLEN_IN_BYTES+APP_CRYPTO_HMAC_SHA512_OUTPUT_LENGTH,
                     HASH_ALGO_SHA2_512, hash)) {
        ret = ret | (1U << 0);
    }
#ifdef CONFIG_DEBUG_TRACE  
    TRACE_info("\r\n\n");
    TRACE_info("\r\nSA2UL SHA HMAC output\n ");
    TRACE_info("\r\n========================\n");

    for (j=0;j<sizeof(hash);j++)
    {
        TRACE_info_arg_hsm("",hash[j]);
        if((j+1)%8 == 0){
             TRACE_info("\r\n");
        }
    }
#endif
    TRACE_info("\r\n\n");

    if (0 != memcmp(hash, gCryptoHmacSha512ExpectedOutput, sizeof(gCryptoHmacSha512ExpectedOutput))) 
    {
        TRACE_info("\r\n SA2UL SHA HMAC EXMAPLE FAILED \n");
        while(wait_in_loop);
    }
    else
    {
        TRACE_info("\r\n SA2UL SHA HMAC EXMAPLE PASSED \n");
		sa2ul_status |= HMAC_TEST_STATUS;

    }
#ifdef CONFIG_SECURITY_SA2UL_PKA
    TRACE_info("\r\nRSA TEST\n");
    TRACE_info("\r\n========================\n");
    if (EFTOK != sa2ul_pka_unittest_rsa_publickey_op())
    {
        while(wait_in_loop);
    }
    if(EFTOK != sa2ul_pka_unittest_rsa_privatekey_op())
    {
        while(wait_in_loop);
    }
    /*Remove filrewall once RSA operation completed*/
    sa2ul_pka_changing_fwl_cfg();
    TRACE_info("\r\nRSA PASSED\n");
#endif
#if defined(CONFIG_SOC_AM62X) || defined(CONFIG_SOC_AM62AX)  || defined(CONFIG_SOC_AM62PX)
	u32 volatile *const point = (u32 *)SA2UL_STATUS_ADDR;
	*point = sa2ul_status;
#endif

	while(wait_in_loop);        
	return ret;
}

