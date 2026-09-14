/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2018. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
* @ingroup Crypto Service Interface
* @file CryIf.h
* @brief CRYIF main layer which handles the Init, Mainfunctions and APIs for SWCs
* ****************************************************************************/

/*****************************************************************************
 *  INCLUDES
******************************************************************************/
#include "CryIf_Cfg.h"
#include "CryIf.h"
#include "Csm.h"
#include "Crypto.h"
#include "Crypto_Key.h"
/*****************************************************************************
 *  GLOBAL DATA 
******************************************************************************/

#define CRYIF_START_SEC_CONST_UNSPECIFIED
#include "Csm_MemMap.h" 

const CryIf_CryptoFunctionsType CryIf_CryptoFunctions[TotalnoDriver] = 
{
    {
        &Crypto_CancelJob,
        &Crypto_ProcessJob,
        &Crypto_She_GetKey,
        &Crypto_She_SetKey,
        &Crypto_She_KeysetValid,
        &Crypto_KeyGenerate,
        &Crypto_CertiParse,
        &Crypto_CertificateVerify,
        &Crypto_KeyDerive,
        &Crypto_KeyElementCopy,
        &Crypto_KeyCopy,
        &Crypto_KeyExchangeCalcSecret,
        &Crypto_KeyExchangeCalcPubVal
    }
};

const CryIf_CryptodriverType CryIf_Channel[TotalnoCryIfChannel] = 
{
    {CryptoJobId_EncryptECB},
    {CryptoJobId_RNG},
    {CryptoJobId_ECC256_SignatureVerify}
};

const CryIf_KeyType CryIf_Key[TotalnoCryIfKey] =
{
    {CryptochannelKeyID_EncryptECB},
    {CryptochannelKeyID_RNG},
    {CryptochannelKeyID_ECC256_SignatureVerify}
};

#define CRYIF_STOP_SEC_CONST_UNSPECIFIED
#include "Csm_MemMap.h" 