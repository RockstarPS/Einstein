/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2020] Visteon Corporation
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
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 *          Krithik B John...........| kjohn     | VTSC, Bengaluru, India
 ******************************************************************************/

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "vHsmCrypt_Internal.h"
#include <string.h>
/******************************************************************************
 *  INTERNAL MACROS
 *****************************************************************************/
#define LOCAL static
#define PBKDF2_MIN_KEY_LEN_BITS  14u
#define PBKDF2_MAX_KEY_LEN_DIGEST_RATIO 0xFFFFFFFF
#define PBKDF2_MIN_ITERATIONS 1000u
#define PBKDF2_MIN_SALT_LEN   16u
#define HMAC_HLEN   32u
#define HASH_SIZE     32u

LOCAL uint32 vHsmCrypt_Pbkdf2_Hmac_Sha256_Min(uint32 p_Variable1_U32, uint32 p_Variable2_U32);
/******************************************************************************
 *  LOCAL Function Implementations
 *****************************************************************************/
LOCAL uint32 vHsmCrypt_Pbkdf2_Hmac_Sha256_Min(uint32 p_Variable1_U32, uint32 p_Variable2_U32)
{
    uint32 l_ReturnVar_U32;
    if (p_Variable1_U32 < p_Variable2_U32)
    {
        l_ReturnVar_U32 = p_Variable1_U32;
    }
    else
    {
        l_ReturnVar_U32 = p_Variable2_U32;
    }
    return l_ReturnVar_U32;
}

#if (VHSMCRYPT_PBKDF2_HMAC_SHA256 == STD_ON)
/******************************************************************************
 *  PUBLIC FUNCTION IMPLEMENTATIONS
 *****************************************************************************/
#define VHSMCRYPT_START_SEC_CODE_QM_LOCAL
/* coverity[unnecessary_header] : FALSE */
/* coverity[misra_c_2012_rule_20_1_violation] : FALSE */
#include <vHsmCrypt_MemMap.h>

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_Pbkdf2_Hmac_Sha256(const uint8* const p_PasswordPtr_pU8, const uint32 p_PasswordLength_U32,
        const uint8* const p_SaltPtr_pU8, const uint32 p_SaltLength_U32, const uint32 p_Iteration_Count_U32,
        uint8* const p_DigestPtr_pU8, const uint32 p_DkLength_U32)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    uint8 l_Hash_U8[HASH_SIZE];
    uint8 l_TempHash_U8[HASH_SIZE];
    uint8 l_Counter_U8 = 1u;
    uint8 l_Pbkdf2C_U8[4];
    uint8 l_loopCounter_U8 = 0u;
    uint8 l_GenKeyLength_U8 = 0u;
    uint32 l_IterationCounter_U32 = 1u;
    uint32 l_BytestoWrite_U32;
    if ((NULL_PTR != p_PasswordPtr_pU8) && (NULL_PTR != p_SaltPtr_pU8) && (NULL_PTR != p_DigestPtr_pU8) && (HASH_SIZE <= p_PasswordLength_U32) && (PBKDF2_MIN_SALT_LEN <= p_SaltLength_U32) && (PBKDF2_MIN_ITERATIONS <= p_Iteration_Count_U32) && (PBKDF2_MIN_KEY_LEN_BITS <= p_DkLength_U32))
    {
        if((p_DkLength_U32/HMAC_HLEN) < PBKDF2_MAX_KEY_LEN_DIGEST_RATIO)
        {
            while (l_GenKeyLength_U8 < p_DkLength_U32)
            {
                l_Pbkdf2C_U8[0] = (l_Counter_U8 >> 24) & 0xff;
                l_Pbkdf2C_U8[1] = (l_Counter_U8 >> 16) & 0xff;
                l_Pbkdf2C_U8[2] = (l_Counter_U8 >> 8) & 0xff;
                l_Pbkdf2C_U8[3] = (l_Counter_U8 >> 0) & 0xff;

                vHsmCrypt_Hmac_Sha2_256_Start(p_PasswordPtr_pU8, p_PasswordLength_U32,vHsmCrypt_Sha2_256_Start,vHsmCrypt_Sha2_256_Update,vHsmCrypt_Sha2_256_Finish);
                vHsmCrypt_Hmac_Sha2_256_Update(p_SaltPtr_pU8, p_SaltLength_U32,vHsmCrypt_Sha2_256_Update);
                vHsmCrypt_Hmac_Sha2_256_Update(l_Pbkdf2C_U8, 4,vHsmCrypt_Sha2_256_Update);
                vHsmCrypt_Hmac_Sha2_256_Finish(l_Hash_U8,vHsmCrypt_Sha2_256_Start,vHsmCrypt_Sha2_256_Update,vHsmCrypt_Sha2_256_Finish);
                (void) memcpy(l_TempHash_U8, l_Hash_U8, HMAC_HLEN);
                for (l_IterationCounter_U32 = 1; l_IterationCounter_U32 < p_Iteration_Count_U32; l_IterationCounter_U32++)
                {
                    vHsmCrypt_Hmac_Sha2_256_Start(p_PasswordPtr_pU8, p_PasswordLength_U32,vHsmCrypt_Sha2_256_Start,vHsmCrypt_Sha2_256_Update,vHsmCrypt_Sha2_256_Finish);
                    vHsmCrypt_Hmac_Sha2_256_Update(l_Hash_U8, HMAC_HLEN,vHsmCrypt_Sha2_256_Update);
                    vHsmCrypt_Hmac_Sha2_256_Finish(l_Hash_U8,vHsmCrypt_Sha2_256_Start,vHsmCrypt_Sha2_256_Update,vHsmCrypt_Sha2_256_Finish);
                    for (l_loopCounter_U8 = 0; l_loopCounter_U8 < HMAC_HLEN; l_loopCounter_U8++)
                    {
                        l_TempHash_U8[l_loopCounter_U8] ^= l_Hash_U8[l_loopCounter_U8];
                    }
                }
                l_BytestoWrite_U32 = vHsmCrypt_Pbkdf2_Hmac_Sha256_Min((p_DkLength_U32-l_GenKeyLength_U8),HMAC_HLEN);
                (void) memcpy((p_DigestPtr_pU8+l_GenKeyLength_U8), l_TempHash_U8, l_BytestoWrite_U32);
                l_GenKeyLength_U8 += l_BytestoWrite_U32;
                ++l_Counter_U8;
                l_RetVal_E = E_OK;
            }
        }
        else
        {
            /* Do Nothing*/
        }
    }
    else
    {
        /* Sanity check fails*/
    }
    return l_RetVal_E;
}
#endif
