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
 * \file vHsmCrypt_EcdsaVer.c
 *
 * \brief
 * Visteon HSM Crypto Ecdsa Verify Main Implementation File
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
#include "vHsmCrypt.h"
#include "trace.h"
/* Macros */
#define CODE_FLASH_KEY_DEV                               ((uint8) 0xFE)

#define CODE_FLASH_KEY_PROD                              ((uint8) 0xFD)

#define ECSA_VERIFY_HASH_SIZE_OFFSET                 ((uint32)0)

#define ECSA_VERIFY_SIGN_R_SIZE_OFFSET               ((uint32)4)

#define ECSA_VERIFY_SIGN_S_SIZE_OFFSET               ((uint32)8)

#define ECSA_VERIFY_SIGN_HASH_DATA_OFFSET           ((uint32)12)

#define ECSA_VERIFY_EACH_FIELD_SIZE                  ((uint32)4)

#define SIZE_OF_KEY                                  (32u)
#define SIZE_OF_SIGNATURE                            (64u)
#if (VHSMCRYPT_ECDSA_ENABLED == STD_ON)

/*Curve Parameter for ECC_ECP_SECP256R1 */
/* prime: 0xFFFFFFFF 00000001 00000000 00000000 00000000 FFFFFFFF FFFFFFFF FFFFFFFF */
/* Curve Coefficient A (=-3): 0xFFFFFFFF 00000001 00000000 00000000 00000000 FFFFFFFF FFFFFFFF FFFFFFFC */
/* Curve Coefficient B:       0x5AC635D8 AA3A93E7 B3EBBD55 769886BC 651D06B0 CC53B0F6 3BCE3C3E 27D2604B */
/* order: 0xFFFFFFFF 00000000 FFFFFFFF FFFFFFFF BCE6FAAD A7179E84 F3B9CAC2 FC632551 */
/* base point x: 0x6B17D1F2 E12C4247 F8BCE6E5 63A440F2 77037D81 2DEB33A0 F4A13945 D898C296 */
/* base point y: 0x4FE342E2 FE1A7F9B 8EE7EB4A 7C0F9E16 2BCE3357 6B315ECE CBB64068 37BF51F5 */
#if 0
const struct ec_prime_curve_p secp256r1_params = {
    .prime = {
        0xFFFFFFFF, 0x00000001, 0x00000000, 0x00000000,
        0x00000000, 0xFFFFFFFF, 0xFFFFFFFF,0xFFFFFFFF
    },
    .order = {
        0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0xFFFFFFFF,
        0xBCE6FAAD, 0xA7179E84, 0xF3B9CAC2, 0xFC632551
    },
    .a = {
        0xFFFFFFFF, 0x00000001, 0x00000000, 0x00000000,
        0x00000000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFC
    },
    .b = {
        0x5AC635D8, 0xAA3A93E7, 0xB3EBBD55, 0x769886BC,
        0x651D06B0, 0xCC53B0F6, 0x3BCE3C3E, 0x27D2604B
    },
    .g = {
        .x = {
            0x6B17D1F2, 0xE12C4247, 0xF8BCE6E5, 0x63A440F2,
            0x77037D81, 0x2DEB33A0, 0xF4A13945, 0xD898C296
        },
        .y = {
            0x4FE342E2, 0xFE1A7F9B, 0x8EE7EB4A, 0x7C0F9E16,
            0x2BCE3357, 0x6B315ECE, 0xCBB64068, 0x37BF51F5
        }
    }
};
#endif
const struct ec_prime_curve_p secp256r1_params = {
    .prime = {
        0x8,
        0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000,
        0x00000000, 0x00000000, 0x00000001, 0xFFFFFFFF
    },
    .order = {
        0x8,
        0xFC632551, 0xF3B9CAC2, 0xA7179E84, 0xBCE6FAAD,
        0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF
    },
    .a = {
        0x8,
        0xFFFFFFFC, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000,
        0x00000000, 0x00000000, 0x00000001, 0xFFFFFFFF
    },
    .b = {
        0x8,
        0x27D2604B, 0x3BCE3C3E, 0xCC53B0F6, 0x651D06B0,
        0x769886BC, 0xB3EBBD55, 0xAA3A93E7, 0x5AC635D8
    },
    .g = {
        .x = {
            0x8,
            0xD898C296, 0xF4A13945, 0x2DEB33A0, 0x77037D81,
            0x63A440F2, 0xF8BCE6E5, 0xE12C4247, 0x6B17D1F2
        },
        .y = {
            0x8,
            0x37BF51F5, 0xCBB64068, 0x6B315ECE, 0x2BCE3357,
            0x7C0F9E16, 0x8EE7EB4A, 0xFE1A7F9B, 0x4FE342E2
        }
    }
};

static void vHsmCrypt_EcdsaVer_InvertEndianness(uint32 *arr, uint32 arraySize);
static void vHsmCrypt_uint8_to_uint32(const uint8 *input, uint32 *output, uint32 input_len);

static uint8 l_xyPublicKey_pU8[64];

/* Public key Structure*/
static struct ec_point l_PubKeyPtr_S ={0};

/* Sginature Structure*/
static struct ecdsa_sig l_SigPtr_S = {0};


static uint8 l_vHsmCryptHash_pU8[32] = {0};
static uint32 l_vHsmCryptHash_pU32[9] = {0};

static void vHsmCrypt_EcdsaVer_InvertEndianness(uint32 *arr, uint32 arraySize)
{
    uint32 start = 0;
    uint32 end = arraySize - 1;
    if (arraySize != 0u)
    {
        while (start < end) {
            uint32 temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            
            ++start;
            --end;
        }
    }
}


static void vHsmCrypt_uint8_to_uint32(const uint8 *input, uint32 *output, uint32 input_len) 
{
    uint32 num_u32;
    uint32 i;
    if ((input_len % 4) == 0)
    {
        num_u32 = input_len / 4;
        for (i = 0; i < num_u32; i++) 
        {
            output[i] = (input[i * 4] << 24) |
                        (input[i * 4 + 1] << 16) |
                        (input[i * 4 + 2] << 8)  |
                        (input[i * 4 + 3]);
        }
    }
}


/******************************************************************************
 *  INTERNAL TYPES
 *****************************************************************************/

/******************************************************************************
 *  INTERNAL VARIABLES
 *****************************************************************************/

/******************************************************************************
 *  PUBLIC FUNCTION IMPLEMENTATIONS
 *****************************************************************************/

/* ECDSA sign verify for message input */
FUNC (Std_ReturnType, CRYPT_CODE) vHsmCrypt_EcdsaVerFinish(const uint8 * p_xyPublicKey_pU8, const uint8 * p_rsSignature_pU8, const uint8 * p_MsgPtr_pU8, uint32 p_Msglen_U32,uint8 * output_buffer )
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    uint8 i =0;
    /*assign length of each element*/
    l_PubKeyPtr_S.x[0] = 8uL;
    l_PubKeyPtr_S.y[0] = 8uL;
    l_SigPtr_S.r[0] = 8uL;
    l_SigPtr_S.s[0] = 8uL;
    l_vHsmCryptHash_pU32[0] = 8uL;
    /* Find Hash here */
    l_RetVal_E = vHsmCrypt_Sha2_256(p_MsgPtr_pU8,p_Msglen_U32, 
                                    &l_vHsmCryptHash_pU8[0],32);
    if(E_OK == l_RetVal_E)
    {
        vHsmCrypt_uint8_to_uint32(&p_xyPublicKey_pU8[0],&l_PubKeyPtr_S.x[1],SIZE_OF_KEY);
        vHsmCrypt_EcdsaVer_InvertEndianness(&l_PubKeyPtr_S.x[1],8);
        vHsmCrypt_uint8_to_uint32(&p_xyPublicKey_pU8[32],&l_PubKeyPtr_S.y[1],SIZE_OF_KEY);
        vHsmCrypt_EcdsaVer_InvertEndianness(&l_PubKeyPtr_S.y[1],8);
        vHsmCrypt_uint8_to_uint32(&p_rsSignature_pU8[0],&l_SigPtr_S.r[1],32);
        vHsmCrypt_EcdsaVer_InvertEndianness(&l_SigPtr_S.r[1],8);
        vHsmCrypt_uint8_to_uint32(&p_rsSignature_pU8[32],&l_SigPtr_S.s[1],32);
        vHsmCrypt_EcdsaVer_InvertEndianness(&l_SigPtr_S.s[1],8);
        vHsmCrypt_uint8_to_uint32(&l_vHsmCryptHash_pU8[0],&l_vHsmCryptHash_pU32[1],32);
        vHsmCrypt_EcdsaVer_InvertEndianness(&l_vHsmCryptHash_pU32[1],8);
        TRACE_info("\r\n Signature R:");
        for (i = 0; i < 9; i++)
        {
           TRACE_info_arg_hsm(" ",l_SigPtr_S.r[i]);
        }
        TRACE_info("\r\n Signature S:");
        for (i = 0; i < 9; i++)
        {
           TRACE_info_arg_hsm(" ",l_SigPtr_S.s[i]);
        }
        TRACE_info("\r\n Public key X:");
        for (i = 0; i < 9; i++)
        {
           TRACE_info_arg_hsm(" ",l_PubKeyPtr_S.x[i]);
        }
        TRACE_info("\r\n Public key y:");
        for (i = 0; i < 9; i++)
        {
           TRACE_info_arg_hsm(" ",l_PubKeyPtr_S.y[i]);
        }
         TRACE_info("\r\n Hash :");
        for (i = 0; i < 9; i++)
        {
           TRACE_info_arg_hsm(" ",l_vHsmCryptHash_pU32[i]);
        }
        l_RetVal_E = vHsmCrypt_EcdsaVer((const struct ecdsa_sig *) &l_SigPtr_S,
                                        (const struct ec_point *)&l_PubKeyPtr_S,
                                        (const uint32 * )&l_vHsmCryptHash_pU32,
                                        8,
                                        output_buffer);
    }                            
    memset((uint8 *) &l_SigPtr_S,(uint8)0, sizeof(l_SigPtr_S));
    memset((uint8 *) &l_PubKeyPtr_S,(uint8)0, sizeof(l_PubKeyPtr_S));
    memset((uint8 *) &l_xyPublicKey_pU8,(uint8)0, sizeof(l_xyPublicKey_pU8));
    return(l_RetVal_E);
}

FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_EcdsaVer(
        const struct ecdsa_sig * p_SigPtr_pS,
        const struct ec_point * p_PubKeyPtr_pS,
        const uint32 * const  p_HashPtr_pU8,
        const uint32     p_HashSize_U32,
        uint8 * const    p_VerResultPtr_pU8)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr fl_RetVal_e = -EINVAL;
    if ((NULL_PTR != p_SigPtr_pS) &&
            (NULL_PTR != p_PubKeyPtr_pS) &&
            (NULL_PTR != p_HashPtr_pU8) &&
            (NULL_PTR != p_VerResultPtr_pU8) &&
            (p_HashSize_U32 != 0))
    {
        if((NULL_PTR != p_PubKeyPtr_pS->x) && (NULL_PTR != p_PubKeyPtr_pS->y) && (NULL_PTR != p_SigPtr_pS->r) && (NULL_PTR != p_SigPtr_pS->s))
        {
            //fl_RetVal_e = sa2ul_pka_ecdsa_verify(&secp256r1_params,p_PubKeyPtr_pS,p_SigPtr_pS,p_HashPtr_pU8);
            if(fl_RetVal_e == EFTOK)
            {
                * p_VerResultPtr_pU8 = 0;
                l_RetVal_e = E_OK;
            }
            else
            {
                * p_VerResultPtr_pU8 = 1;
            }
        }
        else
        {
            /* Do Nothing */
        }
        
    }
    else
    {
        /* Do Nothing */
    }
    return l_RetVal_e;
}

#endif /* VHSMCRYPT_AES_ECB_ENABLED */


/* EOF */
