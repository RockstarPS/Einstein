/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2024] Visteon Corporation
 *       All Rights Reserved.
 *       NOTICE: This is an unpublished work of authorship, which contains trade
 *               secrets. Visteon Corporation owns all rights to this work and
 *               intends to maintain it in confidence to preserve its trade
 *               secret status. Visteon Corporation reserves the right, under
 *               the copyright laws of the United States or those of any other
 *               country that may have jurisdiction, to protect this work as an
 *               unpublished work, in the event of an inadvertent or deliberate
 *               unauthorized publication. Visteon Corporation also reserves
 *               its rights under all copyright laws to protect this work as a
 *               published work, when appropriate. Those having access to this
 *               work may not copy it, use it, modify it, or disclose the
 *               information contained in it without the written authorization
 *               of Visteon Corporation.
 *
 * \file vHsmCrypt_Hmac_Sha2_256.c
 *
 * \brief
 * Visteon HSM Crypto HMAC Main Implementation File
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 *          Krithik B John           | kjohn     | VTSC, Bengaluru, India
 ******************************************************************************/

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include <string.h>
#include "vHsmCrypt.h"
/******************************************************************************
 *  INTERNAL MACROS
 *****************************************************************************/
/**
 * \def          IPAD
 * \brief        0x36 as per RFC 2104
 */
#define IPAD 0x36

/**
 * \def          DK_BSPAL_MAX_FUSE_INDEX
 * \brief        0x5C as per RFC 2104
 */
#define OPAD 0x5C

#if (VHSMCRYPT_AES_HMAC_SHA2_256 == STD_ON)
/******************************************************************************
 *  PUBLIC FUNCTION IMPLEMENTATIONS
 *****************************************************************************/
#define VHSMCRYPT_START_SEC_CODE_QM_LOCAL

LOCAL uint8 l_BlockSize_U8 = 0; /* Block size in bytes (B) for SHA 2*/
LOCAL uint8 l_HashSize_U8 = 0; /* L the byte-length of hash outputs for SHA2 256 -> this is also the minimum size of key*/
LOCAL uint8 l_Step5_pU8[128];
LOCAL uint8 l_blockbuffer_U8[1500] = {0};

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_Hmac_Sha2_256(const uint8* const p_KeyPtr_pU8, const uint32 p_KeyLength_U32,
                        const uint8* const p_PlainTextPtr_pU8, const uint32 p_TextLength_U32, uint8* const p_Hmac_pU8,Std_ReturnType (*p_Sha_pf)(const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32, uint8* const p_DigestPtr_pU8,
                        const uint32 p_DigestLength_U32))
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    uint8          l_Step1_pU8[128];
    uint8          l_Step2_pU8[128];
    uint8          l_Step4_pU8[128];
    uint8          l_loopCounter_U8;
    
    if ((NULL_PTR != p_KeyPtr_pU8) && (p_KeyLength_U32 > 0u) && (p_PlainTextPtr_pU8 != NULL_PTR) && (NULL_PTR != p_Hmac_pU8))
    {
        if (p_Sha_pf == vHsmCrypt_Sha2_256)
        {
            l_HashSize_U8 = 32;
            l_BlockSize_U8 = 64;
        }
        else if(p_Sha_pf ==  vHsmCrypt_Sha2_384)
        {
            l_HashSize_U8 = 48;
            l_BlockSize_U8 = 128;
        }
        else
        {
            l_HashSize_U8 = 64;
            l_BlockSize_U8 = 128;
        }
        /* Step 0: Check if key size is acceptable -> else hash key */
        /* Step 1: append zeros to the end of K to create a B byte string */
        if (p_KeyLength_U32 > l_BlockSize_U8)
        {
            l_RetVal_E = p_Sha_pf(p_KeyPtr_pU8,p_KeyLength_U32,l_Step1_pU8,l_HashSize_U8);
            (void)memset(&l_Step1_pU8[l_HashSize_U8], 0x00, (l_BlockSize_U8 - l_HashSize_U8));
        }
        else
        {
            (void)memcpy(l_Step1_pU8, p_KeyPtr_pU8, p_KeyLength_U32);
            if(p_KeyLength_U32 < 128)
            {
            (void)memset(&l_Step1_pU8[p_KeyLength_U32], 0x00, (l_BlockSize_U8 - p_KeyLength_U32));
            }
            else
            {
                /* p_KeyLength_U32 out of bounds */
            }
        }
        /* Step 2: XOR (bitwise exclusive-OR) the B byte string computed in step(1) with ipad */
        /* Step 5: XOR (bitwise exclusive-OR) the B byte string computed in step (1) with opad */
        for (l_loopCounter_U8 = 0; l_loopCounter_U8 < l_BlockSize_U8; l_loopCounter_U8++)
        {
            l_Step2_pU8[l_loopCounter_U8] = l_Step1_pU8[l_loopCounter_U8] ^ IPAD;
            l_Step5_pU8[l_loopCounter_U8] = l_Step1_pU8[l_loopCounter_U8] ^ OPAD;
        }
        /* Step 3: append the stream of data 'text' to the B byte string resulting from step (2) */
        /* Step 4: apply H to the stream generated in step (3) */
        (void)memcpy(&l_blockbuffer_U8[0],&l_Step2_pU8[0],l_BlockSize_U8);
        (void)memcpy(&l_blockbuffer_U8[l_BlockSize_U8],p_PlainTextPtr_pU8,p_TextLength_U32);
        l_RetVal_E = p_Sha_pf(l_blockbuffer_U8,l_BlockSize_U8+p_TextLength_U32,l_Step4_pU8,l_HashSize_U8);
        /* Step 6: append the H result from step (4) to the B byte string resulting from step (5) */
        /* Step 7: apply H to the stream generated in step (6) and output the result */
        (void)memcpy(&l_blockbuffer_U8[0],&l_Step5_pU8[0],l_BlockSize_U8);
        (void)memcpy(&l_blockbuffer_U8[l_BlockSize_U8],l_Step4_pU8,l_HashSize_U8);
        l_RetVal_E = p_Sha_pf(l_blockbuffer_U8,l_BlockSize_U8+l_HashSize_U8,p_Hmac_pU8,l_HashSize_U8);
    }
    return l_RetVal_E;
}


#endif /* VHSMCRYPT_AES_HMAC_256 */
/*****************************************************************************
 Coverity violations and justifications
 *****************************************************************************/
/* module specific Coverity deviations:
 *
 * 1. unnecessary_header
 * Reason:     Memory Map Files are used to place code and variables in
 *             proper section maps.
 * Risk:       No functional risk.
 * Prevention: Not required.
 *
 */

/*****************************************************************************
 MISRA violations and justifications
 *****************************************************************************/
/* module specific MISRA deviations:
 *
 * 1. misra_c_2012_rule_20_1_violation: #include directive preceded by code.
 * Reason:     MemMap is included for every section and can be preceded by code.
 * Risk:       No functional risk.
 * Prevention: Not required.
 *
 * 2. misra_c_2012_rule_2_2_violation: Function call
 *             "HsmCrpt_AesCbcEncryptFinish(void)" has no effect and can be
 *             removed.
 * Reason:     HsmCrpt_AesCbc(Enc/Dec)ryptFinish is a scalable function provided
 *             by Cypress in HsmCrpt. Hence we will call it in our code to
 *             adapt.
 * Risk:       No functional risk.
 * Prevention: Not required.
 *
 */

/******************************************************************************
 *  REVISION HISTORY
 *  ---------------------------------------------------------------------------
 *  Refer to the module's public header file.
 *
 *  MODULE VERSION
 *  ---------------------------------------------------------------------------
 *  Refer to the VERSION INFORMATION SECTION in module's internal header file.
 ******************************************************************************/

/* EOF */
