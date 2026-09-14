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
 * \file vHsmCrypt_KdfVKMS.c
 *
 * \brief
 * Visteon HSM Crypto Key Derivation in Counter Mode Main Implementation File
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

#include <stdlib.h>
#include <string.h>

/******************************************************************************
 *  INTERNAL MACROS
 *****************************************************************************/
#define HASH_LENGTH        32  // in bytes
#define MAX_KEY_LEN        32  // in bytes
#define I_LEN              1  // in bytes
#define K_LEN              2  // in bytes
#define LABEL              LEN 4  // in bytes
#define MAX_OUT_HASH_RATIO 0xffffffff
#define MIN_KDF_OUTLEN     14
#define MAX_OUTPUT         50
#define TWOBYTE_MAX        0xffff /* to check bits overflow */
#define VKMS_KDF           1
#if (VHSMCRYPT_KDF_VKMS == STD_ON)
/******************************************************************************
 *  PUBLIC FUNCTION IMPLEMENTATIONS
 *****************************************************************************/
#if (VKMS_KDF == 1)
#define VHSMCRYPT_START_SEC_CODE_QM_LOCAL
/* coverity[unnecessary_header] : FALSE */
/* coverity[misra_c_2012_rule_20_1_violation] : FALSE */
#include <vHsmCrypt_MemMap.h>

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_KDF_Counter(uint8 p_CounterLength_U8, const uint8* const p_KeyPtr_pU8, uint32 p_KeyLength_U32,
                      const uint8* const p_Label_pU8, uint32 p_LabelLength_U32, const uint8* const p_ContextPtr_pU8,
                      uint32 p_ContextLength_U32, uint16 p_DerivedKeyLength_U16, uint8* const p_DerivedKey_pU8,
                      Std_ReturnType (*p_funcSHA2_fn)(const uint8*, const uint32, uint8*, const uint32))
{
    Std_ReturnType l_RetVal_E     = E_NOT_OK;
    uint8*         l_databuff_pU8;
    uint8*         l_tmpbuff_pU8;
    uint8          l_tmpout_U8[32] = {0};
    uint8          l_iter_counter_U8 = 0;
    uint8          l_outlen_U8       = 0;
    uint32         l_datalength_U32  = 0;
    uint16         l_outlenbits_U16  = 0;
    uint8          l_counter_U8      = 0;
    if ((NULL != p_KeyPtr_pU8) && (NULL != p_Label_pU8) && (NULL != p_ContextPtr_pU8) && (NULL != p_DerivedKey_pU8) &&
        (0 != p_KeyLength_U32))
    {
        l_datalength_U32 =
            p_CounterLength_U8 + p_KeyLength_U32 + 1 + p_LabelLength_U32 + p_ContextLength_U32 + 2;  // for k_length;
        l_outlenbits_U16 = p_DerivedKeyLength_U16 * 8;
        /* Ceil value */
        if ((p_DerivedKeyLength_U16 % HASH_LENGTH) == 0)
        {
            l_counter_U8 = p_DerivedKeyLength_U16 / HASH_LENGTH;
        }
        else
        {
            l_counter_U8 = (p_DerivedKeyLength_U16 / HASH_LENGTH) + 1;
        }
        /* Creating hash Value H and initializing it as empty word */
        /* creating data buffer with (parent_Key||Counter_value||Label||0x00||Context||DerivedKeylength_in_bits) */
        l_databuff_pU8 = (uint8*)calloc(l_datalength_U32, sizeof(uint8));
        if(l_databuff_pU8 == NULL)
        {
            /* handle error*/
        }
        else
        {
            l_tmpbuff_pU8  = l_databuff_pU8;
            memcpy(l_tmpbuff_pU8, p_KeyPtr_pU8, p_KeyLength_U32);
            l_tmpbuff_pU8 += p_KeyLength_U32;

            /* for i = 0 for initial buffer */
            memset(l_tmpbuff_pU8, 0x00, sizeof(uint8));
            l_tmpbuff_pU8 += p_CounterLength_U8;

            if (p_LabelLength_U32 != 0)
            {
                memcpy(l_tmpbuff_pU8, p_Label_pU8, p_LabelLength_U32);
                l_tmpbuff_pU8 += p_LabelLength_U32;
            }
            (void)memset(l_tmpbuff_pU8, 0x00, I_LEN);
            l_tmpbuff_pU8 += I_LEN;
            if (p_ContextLength_U32 != 0)
            {
                memcpy(l_tmpbuff_pU8, p_ContextPtr_pU8, p_ContextLength_U32);
                l_tmpbuff_pU8 += p_ContextLength_U32;
            }
            memcpy(l_tmpbuff_pU8, (uint8*)&l_outlenbits_U16, 2);
            l_tmpbuff_pU8 += 2;
            /* for counter values greater or equal to 1 */
            /* Counter Value changes in each iteration in data buffer */
            for (l_iter_counter_U8 = 1; l_iter_counter_U8 <= l_counter_U8; l_iter_counter_U8++)
            {
                l_tmpbuff_pU8 = l_databuff_pU8;
                l_tmpbuff_pU8 += p_KeyLength_U32;
                (void)memcpy(l_tmpbuff_pU8, (uint8*)&l_iter_counter_U8, p_CounterLength_U8);
                l_tmpbuff_pU8 += p_CounterLength_U8;
                p_funcSHA2_fn(l_databuff_pU8, l_datalength_U32, l_tmpout_U8, HASH_LENGTH);
                (void)memcpy(p_DerivedKey_pU8 + l_outlen_U8, l_tmpout_U8, p_DerivedKeyLength_U16 - l_outlen_U8);
                (void)memset(l_tmpout_U8, 0x00, HASH_LENGTH);
                l_outlen_U8 += HASH_LENGTH;
            }
            l_RetVal_E = E_OK;
            free(l_databuff_pU8);
        } 
    }
    else
    {
        /*Sanity check failed */
    }
    return l_RetVal_E;
}
#define VHSMCRYPT_STOP_SEC_CODE_QM_LOCAL
/* coverity[unnecessary_header] : FALSE */
/* coverity[misra_c_2012_rule_20_1_violation] : FALSE */
#include <vHsmCrypt_MemMap.h>
#else
#define VHSMCRYPT_START_SEC_CODE_QM_LOCAL
/* coverity[unnecessary_header] : FALSE */
/* coverity[misra_c_2012_rule_20_1_violation] : FALSE */
#include <vHsmCrypt_MemMap.h>
FUNC(Std_ReturnType, CRYPT_CODE)
KDF_COUNTER(uint32 p_CounterLength_U32, const uint8* const p_KeyPtr_pU8, uint32 p_KeyLength_U32,
            const uint8* const p_Label_pU8, uint32 p_LabelLength_U32, const uint8* const p_ContextPtr_pU8,
            uint32 p_ContextLength_U32, uint32 p_DerivedKeyLength_U16, uint8* const p_DerivedKey_pU8)
{
    Std_ReturnType l_RetVal_E     = E_NOT_OK;
    uint8*         l_databuff_pU8 = NULL;
    uint8*         l_tmpbuff_pU8;
    uint8          l_tmpout_U8[32];
    uint32         l_iter_counter_U32 = 0;
    uint32         l_outlen_U32       = 0;
    uint32         l_datalength_U32   = 0;
    uint32         l_outlenbits_U32   = 0;
    uint32         l_counter_U32      = 0;
    if ((p_KeyPtr_pU8 != NULL) && (p_Label_pU8 != NULL) && (p_ContextPtr_pU8 != NULL) && (p_DerivedKey_pU8 != NULL) &&
        (p_KeyLength_U32 != 0) && (p_DerivedKeyLength_U16 >= 14))
    {
        if ((p_DerivedKeyLength_U16 % HASH_LENGTH) == 0)
        {
            l_counter_U32 = p_DerivedKeyLength_U16 / HASH_LENGTH;
        }
        else
        {
            l_counter_U32 = (p_DerivedKeyLength_U16 / HASH_LENGTH) + 1;
        }
        if (l_counter_U32 < MAX_OUT_HASH_RATIO)
        {
            l_outlenbits_U32 = p_DerivedKeyLength_U16 * 8;
            l_datalength_U32 =
                p_CounterLength_U32 + p_KeyLength_U32 + 1 + p_LabelLength_U32 + p_ContextLength_U32 + sizeof(uint32);
            l_databuff_pU8 = (uint8*)calloc(l_datalength_U32, sizeof(uint8));
            l_tmpbuff_pU8  = l_databuff_pU8;
            memset(l_tmpbuff_pU8, 0x00, p_CounterLength_U32);  // i
            l_tmpbuff_pU8 += p_CounterLength_U32;
            if (p_LabelLength_U32 != 0)
            {
                memcpy(l_tmpbuff_pU8, p_Label_pU8, p_LabelLength_U32);
                l_tmpbuff_pU8 += p_LabelLength_U32;  // i||label
            }
            (void)memset(l_tmpbuff_pU8, 0x00, I_LEN);  // i||label||0x00
            l_tmpbuff_pU8 += I_LEN;
            if (p_ContextLength_U32 != 0)
            {
                memcpy(l_tmpbuff_pU8, p_ContextPtr_pU8, p_ContextLength_U32);
                l_tmpbuff_pU8 += p_ContextLength_U32;  // i||label||0x00||context
            }
            memcpy(l_tmpbuff_pU8, (uint8*)&l_outlenbits_U32, sizeof(uint32));
            l_tmpbuff_pU8 += sizeof(uint32);  // i||label||0x00||context||L
            for (l_iter_counter_U32 = 1; l_iter_counter_U32 <= l_counter_U32; l_iter_counter_U32++)
            {
                l_tmpbuff_pU8 = l_databuff_pU8;
                l_tmpbuff_pU8 += p_KeyLength_U32;
                memcpy(l_tmpbuff_pU8, (uint8*)&l_iter_counter_U32, p_CounterLength_U32);
                l_tmpbuff_pU8 += p_CounterLength_U32;
                vHsmCrypt_Hmac_Sha2_256(p_KeyPtr_pU8, p_KeyLength_U32, l_databuff_pU8, l_datalength_U32, l_tmpout_U8,
                                        vHsmCrypt_Sha2_256_Start, vHsmCrypt_Sha2_256_Update, vHsmCrypt_Sha2_256_Finish);
                memcpy(p_DerivedKey_pU8 + l_outlen_U32, l_tmpout_U8, p_DerivedKeyLength_U16 - l_outlen_U32);
                memset(l_tmpout_U8, 0x00, HASH_LENGTH);
                l_outlen_U32 += HASH_LENGTH;
            }
            l_RetVal_E = E_OK;
        }
        else
        {
            /* Sanity check failed */
        }
    }
    else
    {
        /* Invalid Inputs */
    }
    return l_RetVal_E;
}
#define VHSMCRYPT_STOP_SEC_CODE_QM_LOCAL
/* coverity[unnecessary_header] : FALSE */
/* coverity[misra_c_2012_rule_20_1_violation] : FALSE */
#include <vHsmCrypt_MemMap.h>
#endif  // VKMS
#endif  // VHSMCRYPT_KDF_VKMS
