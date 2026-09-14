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
 * \file vHsmCrypt_Sha2_256.c
 *
 * \brief
 * Visteon HSM SHA 2 256 Main Implementation File
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 ******************************************************************************/

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "vHsmCrypt.h"
#include "sa2ul_crypto.h"
#ifdef LOCAL
#define LOCAL static
#endif

#define VHSMCRYPT_SHA1_SIZE 20
#define VHSMCRYPT_WORD_SIZE 32u
#define VHSMCRYPT_SHA384_SIZE 48u
#define VHSMCRYPT_SHA512_SIZE 64u
#if (VHSMCRYPT_SHA2_256_ENABLED == STD_ON)
/******************************************************************************
 *  INTERNAL TYPES
 *****************************************************************************/
/**
 *  \enum te_Sha2_256_StateType
 *  \brief Enumeration of general states of cry services.
 *
 *  \var te_Sha2_256_StateType::e_Sha2_256_Idle
 *  \brief The service is in Finished / Idle State.
 *
 *  \var te_Sha2_256_StateType::e_Sha2_256_Start
 *  \brief The service has been started.
 *
 *  \var te_Sha2_256_StateType::e_Sha2_256_Update
 *  \brief The service is in update state.
 *
 */
typedef enum
{
    e_Sha2_256_Idle   = 0,
    e_Sha2_256_Start  = 1,
    e_Sha2_256_Update = 2,
} te_Sha2_256_StateType;

/******************************************************************************
 *  INTERNAL VARIABLES
 *****************************************************************************/

/**
 ******************************************************************************
 ** \var vHsmCrypt_CurrentState_U8
 **
 ** \brief Tracks the current state of the SHA 2 256 Hashing Engine.
 **
 *****************************************************************************/
LOCAL te_Sha2_256_StateType vHsmCrypt_CurrentState_U8 = e_Sha2_256_Idle;


#if 0
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_Sha2_256_Start(void)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    if (e_Sha2_256_Idle == vHsmCrypt_CurrentState_U8)
    {
        HsmCrpt_Sha2_256_Start();
        vHsmCrypt_CurrentState_U8 = e_Sha2_256_Start;
        l_RetVal_e = E_OK;
#ifdef TVII_SECURE_REFLASH_ENABLE
        vHsmSecureReflashDone();
#endif
    }
    else
    {
        /* Do Nothing */
    }
    return l_RetVal_e;
}

FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_Sha2_256_Update(const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    if ((NULL_PTR != p_MsgPtr_pU8) &&
        ((e_Sha2_256_Start == vHsmCrypt_CurrentState_U8) || (e_Sha2_256_Update == vHsmCrypt_CurrentState_U8)))
    {
        if ((p_MsgPtr_pU8 >= CODEMEM_START_ADDR) && (p_MsgPtr_pU8 <= CODEMEM_END_ADDR))
        {
            vHsmCrypt_CurrentState_U8 = e_Sha2_256_Idle;
            l_RetVal_e = E_NOT_OK;
        }
        else
        {
            VHSMCRYPT_START_CRITICAL_SECTION();
            HsmCrpt_Sha2_256_Update(p_MsgPtr_pU8, p_MsgLength_U32);
            vHsmCrypt_CurrentState_U8 = e_Sha2_256_Update;
            VHSMCRYPT_STOP_CRITICAL_SECTION();
            l_RetVal_e = E_OK;
        }
    }
    else
    {
        /* Do Nothing */
    }
    return l_RetVal_e;
}

FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_Sha2_256_Finish(uint8* const p_DigestPtr_pU8, const uint32 p_DigestLength_U32)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    if ((NULL_PTR != p_DigestPtr_pU8) && (VHSMCRYPT_WORD_SIZE == p_DigestLength_U32) &&
        (e_Sha2_256_Update == vHsmCrypt_CurrentState_U8))
    {
        VHSMCRYPT_START_CRITICAL_SECTION();
        HsmCrpt_Sha2_256_Finish(p_DigestPtr_pU8, p_DigestLength_U32);
        vHsmCrypt_CurrentState_U8 = e_Sha2_256_Idle;
        VHSMCRYPT_STOP_CRITICAL_SECTION();
        l_RetVal_e = E_OK;
    }
    else
    {
        vHsmCrypt_CurrentState_U8 = e_Sha2_256_Idle;
        l_RetVal_e = E_NOT_OK;
    }
    return l_RetVal_e;
}
#endif
FUNC(Std_ReturnType, CRYPT_CODE)vHsmCrypt_Sha2_256(const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32, uint8* const p_DigestPtr_pU8,
                   const uint32 p_DigestLength_U32)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr l_retsa2ul_e;
    if((NULL_PTR != p_DigestPtr_pU8) && (VHSMCRYPT_WORD_SIZE == p_DigestLength_U32) && (NULL_PTR != p_MsgPtr_pU8) && (vHsmCrypt_CurrentState_U8 == e_Sha2_256_Idle))
    {
        l_retsa2ul_e = sa2ul_hash_dmsc((void *)p_MsgPtr_pU8,p_MsgLength_U32,HASH_ALGO_SHA2_256,p_DigestPtr_pU8);
        if(EFTOK == l_retsa2ul_e)
        {
            l_RetVal_e = E_OK;
        }
    }
    else
    {
            /*do nothing*/
    }
    return l_RetVal_e;
}

FUNC(Std_ReturnType, CRYPT_CODE)vHsmCrypt_Sha2_384(const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32, uint8* const p_DigestPtr_pU8,
                   const uint32 p_DigestLength_U32)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr l_retsa2ul_e;
    if((NULL_PTR != p_DigestPtr_pU8) && (VHSMCRYPT_SHA384_SIZE == p_DigestLength_U32) && (NULL_PTR != p_MsgPtr_pU8) && (vHsmCrypt_CurrentState_U8 == e_Sha2_256_Idle))
    {
        l_retsa2ul_e = sa2ul_hash_dmsc((void *)p_MsgPtr_pU8,p_MsgLength_U32,HASH_ALGO_SHA2_384,p_DigestPtr_pU8);
        if(EFTOK == l_retsa2ul_e)
        {
            l_RetVal_e = E_OK;
        }
    }
    else
    {
            /*do nothing*/
    }
    return l_RetVal_e;
}

FUNC(Std_ReturnType, CRYPT_CODE)vHsmCrypt_Sha2_512(const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32, uint8* const p_DigestPtr_pU8,
                   const uint32 p_DigestLength_U32)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr l_retsa2ul_e;
    if((NULL_PTR != p_DigestPtr_pU8) && (VHSMCRYPT_SHA512_SIZE == p_DigestLength_U32) && (NULL_PTR != p_MsgPtr_pU8) && (vHsmCrypt_CurrentState_U8 == e_Sha2_256_Idle))
    {
        l_retsa2ul_e = sa2ul_hash_dmsc((void *)p_MsgPtr_pU8,p_MsgLength_U32,HASH_ALGO_SHA2_512,p_DigestPtr_pU8);
        if(EFTOK == l_retsa2ul_e)
        {
            l_RetVal_e = E_OK;
        }
    }
    else
    {
            /*do nothing*/
    }
    return l_RetVal_e;
}




#endif /* VHSMCRYPT_SHA2_256_ENABLED */

#if (VHSMCRYPT_SHA1_ENABLED == STD_ON)

FUNC(Std_ReturnType, CRYPT_CODE)vHsmCrypt_Sha1(const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32, uint8* const p_DigestPtr_pU8,
    const uint32 p_DigestLength_U32)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr l_retsa2ul_e;
    if((NULL_PTR != p_DigestPtr_pU8) && (VHSMCRYPT_SHA1_SIZE == p_DigestLength_U32) && (NULL_PTR != p_MsgPtr_pU8) && (vHsmCrypt_CurrentState_U8 == e_Sha2_256_Idle))
    {
        l_retsa2ul_e = sa2ul_hash_dmsc((void *)p_MsgPtr_pU8,p_MsgLength_U32,HASH_ALGO_SHA1,p_DigestPtr_pU8);
        if(EFTOK == l_retsa2ul_e)
        {
            l_RetVal_e = E_OK;
        }
    }
    else
    {
    /*do nothing*/
    }
    return l_RetVal_e;
}
#endif
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
