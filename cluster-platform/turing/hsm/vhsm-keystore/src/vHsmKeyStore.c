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
 * \file vHsmKeyStore.c
 *
 * \brief
 * Visteon HSM Key Store for symmetric and assymetric keys for TI AM62Px 
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 *          Krithik B John           | kjohn     | VTSC, Chennai, India
 ******************************************************************************/
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "vHsmCrypt.h"
#include "trace.h"
#include "vHsmKeyStore.h"
#include "Fls.h"
#include "interrupt.h"

/******************************************************************************
 *  MACROS
 *****************************************************************************/
#define KEYVALID       ((uint8)1)
#define KEYNOTVALID    ((uint8)0)
#define TOTALSYMKEYS   (15)
#define TOTALASYMKEYS  (0x9)
#define TOTALNOOFKEYS  (TOTALSYMKEYS + TOTALASYMKEYS)
#define KEYLENSYMONE   (32u)
#define KEYLENSYMTWO   (16u)
#define KEYLENSYMTHREE (48u)
#define KEYLENSYMFOUR  (64u)
#define KEYLENASYM     (144u)
#define KEYBLOBHEADER  (48u)
#define KEYIDSYMMETRIC (0x5A)

#define KEYBLOBADD1    ((const uint32*)0xD0880000)
#define KEYBLOBADD2    ((const uint32*)0xD0881000)
#define KEYBLOBBANK1   ((uint32)0x00880000)
#define KEYBLOBBANK2   ((uint32)0x00881000)

#define KEYID1            (0x20)
#define KEYID2            (0x21)
#define KEYID3            (0x22)
#define KEYID4            (0x23)
#define KEYID5            (0x24)
#define KEYID6            (0x25)
#define KEYID7            (0x26)
#define KEYID8            (0x27)
#define KEYID9            (0x28)
#define KEYID10           (0x29)
#define KEYID11           (0x2A)
#define KEYID12           (0x2B)
#define KEYID13           (0x2C)
#define KEYID14           (0x2D)
#define KEYID15           (0x2E)
#define KEYID16           (0x2F)
#define KEYID17           (0x30)
#define KEYID18           (0x31)
#define KEYID19           (0x32)
#define KEYID20           (0x33)
#define KEYID21           (0x34)
#define KEYID22           (0x35)
#define KEYID23           (0x36)
#define KEYID24           (0x37)

/* Cert handling*/

#define CERTSTOREADD1        (0x882000)
#define CERTSTOREADD2        (0x883000)
#define CERTSTOREFLS1        ((const uint32*)0xD0882000)
#define CERTSTOREFLS2        ((const uint32*)0xD0883000)

#define CERT_CSM_ID_1  (18u) 
#define CERT_CSM_ID_2  (19u)
#define CERT_CSM_ID_3  (20u)
#define CERT_CSM_ID_4  (21u)
#define NO_CERTPERSIST (4u)

#define CERTOFFSET(x)   (x-18u)
#define MAXCERTSIZE     (780u)
#define CERTNORREADSIZE (832u)
#define CERTHEADOFFSET  (0u)
#define CERTTAILOFFSET  (831u)
#define CERT0CMACOFSSET (827u)
#define CERT1CMACOFSSET (828u)
#define CERT2CMACOFSSET (829u)
#define CERT3CMACOFSSET (830u)

/* Key Handling for IPSEC*/

#define ASYMKEYIDOFF      (15u)

#define KEYWRITE_ERROR      (10)
#define KEYERASE_ERROR      (11)

#define MAXSIZEKEYARRAY     (1300)
#define NOOFSYMKEYPERSIST   (6u)
#define NOOFASYMKEYPERSIST  (4u)

#define SYMKEYPERSIZE       (sizeof(vHsmKeyStorage_U8A[0])*NOOFSYMKEYPERSIST)
#define ASYMKEYPERSIZE      (sizeof(vHsmAsymKeys[0])*NOOFASYMKEYPERSIST)
#define PERSISTKEYSIZE      (SYMKEYPERSIZE + ASYMKEYPERSIZE)
#define KEYBLOBSIZE         (PERSISTKEYSIZE + KEYBLOBHEADER)

#define FLS_XOR_CONSTANT     (0xC0FFEE)
#define NOR_MAGIC_HEADOFF    (0x0)
#define NOR_MAGIC_TAILOFF    ((KEYBLOBSIZE/4)+2)
#define NOR_WRITE_SIZE      (((KEYBLOBSIZE) + 255) & ~255) /* round up to multiple of page size*/

#define FLS_READOFFSET(x)   (0xD0000000 + (uint32)x)
#define MAXFLSREADSIZE      (NOR_MAGIC_TAILOFF)
#define BANKSWTICHCONST     (0x1000)

#define CRYPTO_KE_KEYEXCHANGE_PRIVKEY 9u
#define CRYPTO_KE_KEYDERIVATION_ALGORITHM 15u
#define CRYPTO_KE_KEYEXCHANGE_OWNPUBKEY 1u
#define CRYPTO_KE_IPSECPRFKEYELEMENT  0x20u

#define ASYMKEY256  32u
#define ASYMKEY384  48u
#define ASYMPUBKEYLEN(x) (2*x)
/******************************************************************************
 *  INTERNAL TYPES
 *****************************************************************************/
typedef enum
{
    e_KeyStore_Idle = 0,
    e_KeyStore_KeyUnInit = 1,
    e_KeyStore_KeySet = 2,
    e_KeyStore_KeySetCopyData = 3,
    e_KeyStore_KeyErase = 4,
    e_KeyStore_KeyEraseWait = 5,
    e_KeyStore_KeyWrite = 6,
    e_KeyStore_CertSet = 7,
    e_KeyStore_CertErase = 8,
    e_KeyStore_CertEraseWait = 9,
    e_KeyStore_CertWrite = 10,
} te_KeyStore_StateMachine;

typedef enum
{
    e_KeyStoreKeyReadable = 1,
    e_KeyStoreKeyNotReadable = 0,
} te_KeyStore_KeyReadable;

typedef enum
{
    e_SymKeyOperation = 1,
    e_AsymKeyOperation = 2,
    e_IpsecOperation = 3,
}te_KeyStore_KeyUsage;

typedef struct
{
    uint16 KeyLen;
    te_KeyStore_KeyReadable KeyRead;
    boolean persist;
    uint32 privKeyLen; 
    te_KeyStore_KeyUsage KeyUsage;
} ts_KeyStore_Metadata;

typedef struct
{
    uint32 KeyId;
    uint32 KeyIntId;
} ts_KeyStore_KeyId;

typedef struct 
{
    uint8 keyValid;
    uint8 key[64];
} ts_KeyStore_Key;

typedef struct
{
    uint8 privatekey[48];
    uint8 Publickey [96];
}EccAsymKeys;
typedef struct 
{
    uint8 asymkeyvalid;
    EccAsymKeys asymkey;
}ts_KeyStore_AsymKey;

typedef struct 
{
    ts_KeyStore_Key symkey[NOOFSYMKEYPERSIST];
    ts_KeyStore_AsymKey asymkey[NOOFASYMKEYPERSIST];
}ts_Keystorekeys;

/*Cert Handling*/
typedef struct
{
    uint32 certlen;
    uint8 cert[MAXCERTSIZE];
}
Crypto_certs;

typedef struct
{
    uint8 valid;
    Crypto_certs certs;
}
Crypto_Certdata;


/******************************************************************************
 *  CONFIG VARIABLES
 *****************************************************************************/
const ts_KeyStore_Metadata vHsmKeyStore_Metadata[TOTALNOOFKEYS] = {
                                                                {KEYLENSYMTWO,e_KeyStoreKeyReadable,FALSE,0,e_SymKeyOperation},
                                                                {KEYLENSYMTWO,e_KeyStoreKeyReadable,FALSE,0,e_SymKeyOperation},
                                                                {KEYLENSYMTWO,e_KeyStoreKeyReadable,FALSE,0,e_SymKeyOperation},
                                                                {KEYLENSYMTWO,e_KeyStoreKeyReadable,FALSE,0,e_SymKeyOperation},
                                                                {KEYLENSYMTWO,e_KeyStoreKeyReadable,FALSE,0,e_SymKeyOperation},
                                                                {KEYLENSYMONE,e_KeyStoreKeyReadable,FALSE,0,e_SymKeyOperation},
                                                                {KEYLENSYMFOUR,e_KeyStoreKeyReadable,FALSE,0,e_IpsecOperation}, /*SK_d*/
                                                                {KEYLENSYMTHREE,e_KeyStoreKeyReadable,FALSE,0,e_IpsecOperation}, /*SK_ai*/
                                                                {KEYLENSYMTHREE,e_KeyStoreKeyReadable,FALSE,0,e_IpsecOperation}, /*SK_ar*/
                                                                {KEYLENSYMTHREE,e_KeyStoreKeyReadable,FALSE,0,e_IpsecOperation}, /*SK_ei*/
                                                                {KEYLENSYMTHREE,e_KeyStoreKeyReadable,FALSE,0,e_IpsecOperation}, /*SK_er*/
                                                                {KEYLENSYMTHREE,e_KeyStoreKeyReadable,FALSE,0,e_IpsecOperation}, /*SK_pi*/
                                                                {KEYLENSYMTHREE,e_KeyStoreKeyReadable,FALSE,0,e_IpsecOperation}, /*SK_pr*/
                                                                {KEYLENSYMTWO,e_KeyStoreKeyReadable,FALSE,0,e_SymKeyOperation},
                                                                {KEYLENSYMTWO,e_KeyStoreKeyReadable,FALSE,0,e_SymKeyOperation}, /* IV KEYID*/
                                                                {KEYLENASYM,e_KeyStoreKeyReadable,FALSE,ASYMKEY384,e_AsymKeyOperation}, /*CSR key*/
                                                                {KEYLENASYM,e_KeyStoreKeyReadable,FALSE,ASYMKEY384,e_AsymKeyOperation}, /*Ipsec Key*/
                                                                {KEYLENASYM,e_KeyStoreKeyReadable,FALSE,ASYMKEY384,e_AsymKeyOperation},
                                                                {KEYLENASYM,e_KeyStoreKeyReadable,FALSE,ASYMKEY384,e_AsymKeyOperation},
                                                                {KEYLENASYM,e_KeyStoreKeyReadable,FALSE,ASYMKEY384,e_AsymKeyOperation}, /*DH Key*/
                                                                {KEYLENASYM,e_KeyStoreKeyReadable,FALSE,ASYMKEY384,e_AsymKeyOperation},
                                                                {KEYLENASYM,e_KeyStoreKeyReadable,FALSE,ASYMKEY384,e_IpsecOperation},   /*PRF KEY*/
                                                                {KEYLENASYM,e_KeyStoreKeyReadable,FALSE,ASYMKEY384,e_IpsecOperation}, /*SK_CHild_ai*/
                                                                {KEYLENASYM,e_KeyStoreKeyReadable,FALSE,ASYMKEY384,e_IpsecOperation}      /*SK_CHild_ar*/                                                     
};

const ts_KeyStore_KeyId KeyStoreKeyID[TOTALNOOFKEYS] = {
                                                            {KEYID1,0},
                                                            {KEYID2,1},
                                                            {KEYID3,2},
                                                            {KEYID4,3},
                                                            {KEYID5,4},
                                                            {KEYID6,5},
                                                            {KEYID7,6},
                                                            {KEYID8,7},
                                                            {KEYID9,8},
                                                            {KEYID10,9},
                                                            {KEYID11,10},
                                                            {KEYID12,11},
                                                            {KEYID13,12},
                                                            {KEYID14,13},
                                                            {KEYID15,14},
                                                            {KEYID16,15},
                                                            {KEYID17,16},
                                                            {KEYID18,17},
                                                            {KEYID19,18},
                                                            {KEYID20,19},
                                                            {KEYID21,20},
                                                            {KEYID22,21},
                                                            {KEYID23,22},
                                                            {KEYID24,23}
};

static uint32 l_IpsecKeyLength[TOTALNOOFKEYS] = {0};


/******************************************************************************
 *  LOCAL VARIABLES
 *****************************************************************************/
static te_KeyStore_StateMachine vHsmKeyStore_State = e_KeyStore_KeyUnInit;
static ts_KeyStore_Key vHsmKeyStorage_U8A[TOTALSYMKEYS] = {0};
static ts_KeyStore_AsymKey vHsmAsymKeys[TOTALASYMKEYS] = {0};
static uint32 vHsmBlob_Nor[MAXSIZEKEYARRAY/4] = {0};
static uint8 vHsmBlob_Byte[MAXSIZEKEYARRAY] = {0};
static uint32 vHsmKeyStore_KeyAddr_U32 = 0;
u32 volatile * vHsmKeyStore_Nor =  (u32 *)FLS_READOFFSET(KEYBLOBBANK1);
static uint32 KeyBlobInit = 0;
static uint32 vHsmKeyStore_RetryCounter = 0u;

/*Certificate Queue for handling background*/
static uint32 vHsmCertQueuID_U32[NO_CERTPERSIST] = {0};
static uint32 l_QueueIndex = 0;
static Crypto_Certdata vHsmCertQueue[NO_CERTPERSIST] = {0};

/*Certificate Buffer in Different Address*/
#pragma DATA_SECTION(vHsmCertBuffer_U32A,".hsm_certhandle");
static uint32 vHsmCertBuffer_U32A[832];

Crypto_Certdata * vHsmCertPointer = (Crypto_Certdata *)(&vHsmCertBuffer_U32A[1]); /* cast pointer to first index*/
static uint32 CertAddress = 0;
static uint32 CertInitflag = 0;
uint32 volatile * CertRead = (uint32*)CERTSTOREADD1;
/******************************************************************************
 *  LOCAL FUNCTIONS
 *****************************************************************************/
static uint32 vHsmKeyStore_IntKeyId(uint32 KeyId);
static Std_ReturnType vHsmKeyStore_ValidkeyId(uint32 KeyId);
static void DeQueue_vHsmCertQueue(void);
static void CertWriteCheckBg(void);
/******************************************************************************
 *  PUBLIC FUNCTIONS
 *****************************************************************************/

/*De Queue the certificate Queue*/
static FUNC(void, KEYMAN_CODE) DeQueue_vHsmCertQueue(void)
{
    uint8 i = 0;
    for(i=1;i<NO_CERTPERSIST;i++)
    {
        vHsmCertQueue[i-1] = vHsmCertQueue[i];
        vHsmCertQueuID_U32[i-1] = vHsmCertQueuID_U32[i];
    }
}
/*Check the Background write for Certificate*/
static FUNC(void, KEYMAN_CODE) CertWriteCheckBg(void)
{
    if((l_QueueIndex > 0) && (vHsmKeyStore_State == e_KeyStore_Idle))
    {
        vHsmKeyStore_State = e_KeyStore_CertSet;
        TRACE_info("\r\n Hsm Cert write Req");
    }
}

static FUNC(uint32, KEYMAN_CODE) vHsmKeyStore_IntKeyId(uint32 KeyId)
{
    uint8 i = 0;
    uint32 intKeyId = 0;
    for(i=0;i<TOTALNOOFKEYS;i++)
    {
        if(KeyStoreKeyID[i].KeyId == KeyId)
        {
            intKeyId =  KeyStoreKeyID[i].KeyIntId;
            break;
        }
    }
    return intKeyId;
}

/**
 *********************************************************************************************
 ** \copydoc vHsmKeyStore_Init
 *********************************************************************************************
 */
FUNC(void, KEYMAN_CODE) vHsmKeyStore_Init(void)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    uint8 i = 0;
    /*Validity check for key banks*/
    vHsmKeyStore_KeyAddr_U32 = KEYBLOBBANK1;
    if(KEYBLOBADD1[NOR_MAGIC_HEADOFF] == (FLS_XOR_CONSTANT ^ KEYBLOBADD1[NOR_MAGIC_TAILOFF]))
    {
        if(KEYBLOBADD2[NOR_MAGIC_HEADOFF] == (FLS_XOR_CONSTANT ^ KEYBLOBADD2[NOR_MAGIC_TAILOFF]))
        {
            if(KEYBLOBADD1[NOR_MAGIC_HEADOFF] < KEYBLOBADD2[NOR_MAGIC_HEADOFF])
            {
                vHsmKeyStore_KeyAddr_U32 = KEYBLOBBANK2;
            }
        }
        KeyBlobInit = 0xff;
    }
    else
    {
        if(KEYBLOBADD2[NOR_MAGIC_HEADOFF] == (FLS_XOR_CONSTANT ^ KEYBLOBADD2[NOR_MAGIC_TAILOFF]))
        {
            vHsmKeyStore_KeyAddr_U32 = KEYBLOBBANK2;
            KeyBlobInit = 0xff;
        }
    }
    TRACE_info_arg_hsm("\r\n HSM Key BLob Addr",vHsmKeyStore_KeyAddr_U32);
    vHsmKeyStore_Nor =  (u32 *)FLS_READOFFSET(vHsmKeyStore_KeyAddr_U32);
    for(i=0;i<MAXFLSREADSIZE;i++)
    {
        vHsmBlob_Nor[i] = vHsmKeyStore_Nor[i];
    }

    l_RetVal_E = vHsmCrypt_BlobDecapsulation((uint8*)&vHsmBlob_Nor[1],KEYBLOBSIZE,&vHsmBlob_Byte[0],PERSISTKEYSIZE);
    if(E_NOT_OK == l_RetVal_E)
    {
        TRACE_info("\r\n HSM Empty Blob error");
        (void)memset((uint8*)vHsmBlob_Byte,0x00,sizeof(vHsmBlob_Byte));
    }
    else
    {
        TRACE_info("\r\n HSM blob decapsualted");
    }
    (void)memcpy((uint8*)vHsmKeyStorage_U8A,&vHsmBlob_Byte[0],SYMKEYPERSIZE);
    (void)memcpy((uint8*)vHsmAsymKeys,&vHsmBlob_Byte[SYMKEYPERSIZE],ASYMKEYPERSIZE);
#ifdef KEYDEBUG
    TRACE_info("\r\n Private Key");
    for(i=0;i<48;i++)
    {
        TRACE_info_arg_hsm(" ",vHsmAsymKeys[0].asymkey.privatekey[i]);
    }
    TRACE_info("\r\n Public Key");
    for(i=0;i<96;i++)
    {
        TRACE_info_arg_hsm(" ",vHsmAsymKeys[0].asymkey.Publickey[i]);
    }
#endif
    vHsmKeyStore_State = e_KeyStore_Idle;
}

/**
 *********************************************************************************************
 ** \copydoc vHsmKeyStore_CertInit
 *********************************************************************************************
 */
FUNC(void, KEYMAN_CODE) vHsmKeyStore_CertInit(void)
{
    uint32 i = 0;
    /*Cert reading on init*/
    CertAddress = CERTSTOREADD1;  /*By default set first address*/
    if(CERTSTOREFLS1[CERTHEADOFFSET] == (FLS_XOR_CONSTANT ^ CERTSTOREFLS1[CERTTAILOFFSET]))
    {
        if(CERTSTOREFLS2[CERTHEADOFFSET] == (FLS_XOR_CONSTANT ^ CERTSTOREFLS2[CERTTAILOFFSET]))
        {
            if(CERTSTOREFLS1[CERTHEADOFFSET] < CERTSTOREFLS2[CERTHEADOFFSET])
            {
                CertAddress = CERTSTOREADD2;
            }
        }
        CertInitflag = 0xff;
    }
    else
    {
        if(CERTSTOREFLS2[CERTHEADOFFSET] == (FLS_XOR_CONSTANT ^ CERTSTOREFLS2[CERTTAILOFFSET]))
        {
            CertAddress = CERTSTOREADD2;
            CertInitflag = 0xff;
        }
    }
    CertRead = (uint32 *)FLS_READOFFSET(CertAddress);
    for(i=0;i<CERTNORREADSIZE;i++)
    {
        vHsmCertBuffer_U32A[i] = CertRead[i];
    }
    l_QueueIndex = 0;
    TRACE_info_arg("\r\n Cert Init Done",CertAddress);
}

FUNC(Std_ReturnType, KEYMAN_CODE) vHsmKeyStore_ValidkeyId(uint32 KeyId)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    uint8 i = 0;
    for(i=0;i<TOTALNOOFKEYS;i++)
    {
        if(KeyStoreKeyID[i].KeyId == KeyId)
        {
            l_RetVal_E = E_OK;
            break;
        }
    }
    return l_RetVal_E;
}

/**
 *********************************************************************************************
 ** \copydoc vHsmKeyStore_SetKey
 *********************************************************************************************
 */
FUNC(Std_ReturnType, KEYMAN_CODE) vHsmKeyStore_SetKey(uint32 keyId, uint8 * key, uint16 keysize)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    uint32 IntkeyId_U32 = 0;
    if(NULL != key)
    {
        if(E_OK == vHsmKeyStore_ValidkeyId(keyId))
        {
            IntkeyId_U32 = vHsmKeyStore_IntKeyId(keyId);
            if((vHsmKeyStore_Metadata[IntkeyId_U32].KeyLen >= keysize))
            {
                if((keyId >= KEYID16) && (KEYID24 >= keyId))
                {
                    if(e_IpsecOperation != vHsmKeyStore_Metadata[IntkeyId_U32].KeyUsage)
                    {
                        (void)memcpy(&vHsmAsymKeys[IntkeyId_U32-ASYMKEYIDOFF].asymkey.privatekey[0],key,vHsmKeyStore_Metadata[IntkeyId_U32].privKeyLen);
                        (void)memcpy(&vHsmAsymKeys[IntkeyId_U32-ASYMKEYIDOFF].asymkey.Publickey[0],key+vHsmKeyStore_Metadata[IntkeyId_U32].privKeyLen,ASYMPUBKEYLEN(vHsmKeyStore_Metadata[IntkeyId_U32].privKeyLen));
                        vHsmAsymKeys[IntkeyId_U32-ASYMKEYIDOFF].asymkeyvalid = (uint8)1;
                        if(TRUE == vHsmKeyStore_Metadata[IntkeyId_U32].persist)
                        {
                            if(e_KeyStore_Idle == vHsmKeyStore_State)
                            {
                                vHsmKeyStore_State = e_KeyStore_KeySet;
                            }
                            else
                            {
                                vHsmKeyStore_RetryCounter++;
                                TRACE_info("\r\n Parellel Calls");
                            }
                        }
                        else
                        {
                            TRACE_info("\r\n Ram Key set");
                        }
                    }
                    else
                    {
                        (void)memcpy(&vHsmAsymKeys[IntkeyId_U32-ASYMKEYIDOFF].asymkey.Publickey[0],key,keysize);
                        vHsmAsymKeys[IntkeyId_U32-ASYMKEYIDOFF].asymkeyvalid = (uint8)1;
                        l_IpsecKeyLength[IntkeyId_U32] = keysize;
                        TRACE_info_arg_hsm("\r\n Ipsec PRF Key set",l_IpsecKeyLength[IntkeyId_U32]);
                    }
                    
                }
                else
                {
                    if(e_IpsecOperation != vHsmKeyStore_Metadata[IntkeyId_U32].KeyUsage)
                    {
                        vHsmKeyStorage_U8A[IntkeyId_U32].keyValid = (uint8)1;
                        (void)memcpy(&vHsmKeyStorage_U8A[IntkeyId_U32].key[0],key,vHsmKeyStore_Metadata[IntkeyId_U32].KeyLen);
                        if(TRUE == vHsmKeyStore_Metadata[IntkeyId_U32].persist)
                        {
                            if(e_KeyStore_Idle == vHsmKeyStore_State)
                            {
                                vHsmKeyStore_State = e_KeyStore_KeySet;
                            }
                            else
                            {
                                vHsmKeyStore_RetryCounter++;
                                TRACE_info("\r\n Parellel Calls");
                            }
                            
                        }
                        else
                        {
                            TRACE_info("\r\n Ram Key set");
                        }
                    }
                    else
                    {
                        vHsmKeyStorage_U8A[IntkeyId_U32].keyValid = (uint8)1;
                        (void)memcpy(&vHsmKeyStorage_U8A[IntkeyId_U32].key[0],key,keysize);
                        l_IpsecKeyLength[IntkeyId_U32] = keysize;
                        TRACE_info_arg_hsm("\r\n Ipsec Key set",l_IpsecKeyLength[IntkeyId_U32]);
                    }
                }
                l_RetVal_E = E_OK;
            }
        }
        else if((keyId >= CERT_CSM_ID_1) && (CERT_CSM_ID_4 >= keyId))
        {
            TRACE_info_arg("\r\n Queu Index, ",keysize);
            if((l_QueueIndex < NO_CERTPERSIST) && (keysize <= MAXCERTSIZE))
            {
                /*add to queue*/
                vHsmCertQueuID_U32[l_QueueIndex] = keyId;
                vHsmCertQueue[l_QueueIndex].valid = 1u;
                (void)memcpy(&vHsmCertQueue[l_QueueIndex].certs.cert[0],key,keysize);
                vHsmCertQueue[l_QueueIndex].certs.certlen = keysize;
                l_QueueIndex++;
                l_RetVal_E = E_OK;
            }
            else
            {
                /* Queue Full Error*/
            }
            
        }
        else
        {
            /*Error Case*/
        }
    }
    return l_RetVal_E;
}

/**
 *********************************************************************************************
 ** \copydoc vHsmKeyStore_GetKey
 *********************************************************************************************
 */
FUNC(Std_ReturnType, KEYMAN_CODE) vHsmKeyStore_GetKey(uint32 keyId, uint32 keyelementId ,uint8 * key, uint16 *keysize)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    uint32 KeyIntID = 0;
    if(NULL != key)
    {
        if(E_OK == vHsmKeyStore_ValidkeyId(keyId))
        {
            KeyIntID = vHsmKeyStore_IntKeyId(keyId);
            if((keyId >= KEYID16) && (KEYID24 >= keyId))
            {
                if((KEYNOTVALID != vHsmAsymKeys[KeyIntID-ASYMKEYIDOFF].asymkeyvalid) && (e_KeyStoreKeyReadable == vHsmKeyStore_Metadata[KeyIntID].KeyRead))
                {
                    if(0u == keyelementId)
                    {
                        if(e_IpsecOperation != vHsmKeyStore_Metadata[KeyIntID].KeyUsage)
                        {
                            (void)memcpy(key,&vHsmAsymKeys[KeyIntID-ASYMKEYIDOFF].asymkey.privatekey[0], vHsmKeyStore_Metadata[KeyIntID].privKeyLen);
                            (void)memcpy(key+vHsmKeyStore_Metadata[KeyIntID].privKeyLen,&vHsmAsymKeys[KeyIntID-ASYMKEYIDOFF].asymkey.Publickey[0],ASYMPUBKEYLEN(vHsmKeyStore_Metadata[KeyIntID].privKeyLen));
                            *keysize = vHsmKeyStore_Metadata[KeyIntID].KeyLen;
                        }
                        else
                        {
                            (void)memcpy(key,&vHsmAsymKeys[KeyIntID-ASYMKEYIDOFF].asymkey.Publickey[0],l_IpsecKeyLength[KeyIntID]);
                            *keysize = l_IpsecKeyLength[KeyIntID];
                            TRACE_info("\r\n Ipsec PRF Key Got");
                        }
                        l_RetVal_E = E_OK;
                    }
                    if(CRYPTO_KE_KEYEXCHANGE_PRIVKEY == keyelementId)
                    {
                        (void)memcpy(key,&vHsmAsymKeys[KeyIntID-ASYMKEYIDOFF].asymkey.privatekey[0], vHsmKeyStore_Metadata[KeyIntID].privKeyLen);
                        *keysize = vHsmKeyStore_Metadata[KeyIntID].privKeyLen;
                        TRACE_info("\r\n Ipsec Secret Key");
                        l_RetVal_E = E_OK;
                    }
                    if(CRYPTO_KE_KEYEXCHANGE_OWNPUBKEY == keyelementId)
                    {
                        (void)memcpy(key,&vHsmAsymKeys[KeyIntID-ASYMKEYIDOFF].asymkey.Publickey[0],ASYMPUBKEYLEN(vHsmKeyStore_Metadata[KeyIntID].privKeyLen));
                        *keysize = ASYMPUBKEYLEN(vHsmKeyStore_Metadata[KeyIntID].privKeyLen);
                        TRACE_info("\r\n Public Key");
                        l_RetVal_E = E_OK;
                    }
                }
                else
                {
                    TRACE_info("\r\n Key Not available");
                    l_RetVal_E = E_KEY_NOT_AVAILABLE;
                }
            }
            else
            {
                if((KEYNOTVALID != vHsmKeyStorage_U8A[KeyIntID].keyValid) && (e_KeyStoreKeyReadable == vHsmKeyStore_Metadata[KeyIntID].KeyRead))
                {
                    if(e_IpsecOperation != vHsmKeyStore_Metadata[KeyIntID].KeyUsage)
                    {
                        (void)memcpy(key,vHsmKeyStorage_U8A[KeyIntID].key,vHsmKeyStore_Metadata[KeyIntID].KeyLen);
                        *keysize = vHsmKeyStore_Metadata[KeyIntID].KeyLen;
                    }
                    else
                    {
                        (void)memcpy(key,vHsmKeyStorage_U8A[KeyIntID].key,l_IpsecKeyLength[KeyIntID]);
                        *keysize = l_IpsecKeyLength[KeyIntID];
                    }
                    l_RetVal_E = E_OK;
                    TRACE_info("\r\n Key Got");
                }
                else
                {
                    l_RetVal_E = E_KEY_NOT_AVAILABLE;
                }
            }
        }
    }
    return l_RetVal_E;
}

/**
 *********************************************************************************************
 ** \copydoc vHsmKeyStore_KeyCopy
 *********************************************************************************************
 */
FUNC(Std_ReturnType, KEYMAN_CODE) vHsmKeyStore_KeyCopy(uint8 keyId, uint8 TargetId, uint32 KeyElementId)
{
    Std_ReturnType l_retval_E = E_NOT_OK;
    uint32 KeyIntId, TargetKeyIntId = 0;
    if((E_OK == vHsmKeyStore_ValidkeyId(keyId)) && (E_OK == vHsmKeyStore_ValidkeyId(TargetId)))
    {
        KeyIntId = vHsmKeyStore_IntKeyId(keyId);
        TargetKeyIntId = vHsmKeyStore_IntKeyId(TargetId);
        if(KeyElementId == 0u)
        {
            if((keyId >= KEYID16) && (KEYID24 >= keyId))
            {
                if((KEYNOTVALID != vHsmAsymKeys[KeyIntId-ASYMKEYIDOFF].asymkeyvalid) && (e_KeyStoreKeyReadable == vHsmKeyStore_Metadata[KeyIntId].KeyRead))
                {
                    (void)memcpy(&vHsmAsymKeys[TargetKeyIntId-ASYMKEYIDOFF].asymkey.privatekey[0],&vHsmAsymKeys[KeyIntId-ASYMKEYIDOFF].asymkey.privatekey[0],vHsmKeyStore_Metadata[KeyIntId].privKeyLen);
                    (void)memcpy(&vHsmAsymKeys[TargetKeyIntId-ASYMKEYIDOFF].asymkey.Publickey[0],&vHsmAsymKeys[KeyIntId-ASYMKEYIDOFF].asymkey.Publickey[0],ASYMPUBKEYLEN(vHsmKeyStore_Metadata[KeyIntId].privKeyLen));
                    l_retval_E = E_OK;
                }
                else
                {
                    l_retval_E = E_KEY_NOT_AVAILABLE;
                }
            }
            else
            {
                if((KEYNOTVALID != vHsmKeyStorage_U8A[KeyIntId].keyValid) && (e_KeyStoreKeyReadable == vHsmKeyStore_Metadata[KeyIntId].KeyRead))
                {
                    (void)memcpy(&vHsmKeyStorage_U8A[TargetKeyIntId].key[0],&vHsmKeyStorage_U8A[KeyIntId-ASYMKEYIDOFF].key[0],vHsmKeyStore_Metadata[KeyIntId].KeyLen);
                    l_retval_E = E_OK;
                }
                else
                {
                    l_retval_E = E_KEY_NOT_AVAILABLE;
                }
            }
        }
        else if(KeyElementId == CRYPTO_KE_KEYEXCHANGE_PRIVKEY)
        {
            if((KEYNOTVALID != vHsmAsymKeys[KeyIntId-ASYMKEYIDOFF].asymkeyvalid) && (e_KeyStoreKeyReadable == vHsmKeyStore_Metadata[KeyIntId].KeyRead))
            {
                (void)memcpy(&vHsmAsymKeys[TargetKeyIntId-ASYMKEYIDOFF].asymkey.privatekey[0],&vHsmAsymKeys[KeyIntId-ASYMKEYIDOFF].asymkey.privatekey[0],vHsmKeyStore_Metadata[KeyIntId].privKeyLen);
                l_retval_E = E_OK;
            }
            else
            {
                l_retval_E = E_KEY_NOT_AVAILABLE;
            }

        }
        else if(KeyElementId == CRYPTO_KE_IPSECPRFKEYELEMENT)
        {
            if((KEYNOTVALID != vHsmKeyStorage_U8A[KeyIntId].keyValid))
            {
                (void)memcpy(&vHsmAsymKeys[TargetKeyIntId-ASYMKEYIDOFF].asymkey.Publickey[0],&vHsmKeyStorage_U8A[KeyIntId].key[0],l_IpsecKeyLength[KeyIntId]);
                l_IpsecKeyLength[TargetKeyIntId] = l_IpsecKeyLength[KeyIntId];
                vHsmAsymKeys[TargetKeyIntId-ASYMKEYIDOFF].asymkeyvalid = 1u;
                TRACE_info_arg_hsm("\r\n PRF Key Copied",l_IpsecKeyLength[TargetKeyIntId]);
                l_retval_E = E_OK;
            }
            else
            {
                l_retval_E = E_KEY_NOT_AVAILABLE;
            }
        }
        else
        {
            if((KEYNOTVALID != vHsmAsymKeys[KeyIntId-ASYMKEYIDOFF].asymkeyvalid) && (e_KeyStoreKeyReadable == vHsmKeyStore_Metadata[KeyIntId].KeyRead))
            {
                (void)memcpy(&vHsmAsymKeys[TargetKeyIntId-ASYMKEYIDOFF].asymkey.Publickey[0],&vHsmAsymKeys[KeyIntId-ASYMKEYIDOFF].asymkey.Publickey[0],ASYMPUBKEYLEN(vHsmKeyStore_Metadata[KeyIntId].privKeyLen));
                l_retval_E = E_OK;
            }
            else
            {
                l_retval_E = E_KEY_NOT_AVAILABLE;
            }
        }
    }
    return l_retval_E;
}

/**
 *********************************************************************************************
 ** \copydoc vHsmCert_StoreTrigger
 *********************************************************************************************
 */
FUNC(Std_ReturnType, KEYMAN_CODE) vHsmCert_StoreTrigger(void)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    
    return l_RetVal_E;
}


/**
 *********************************************************************************************
 ** \copydoc vHsmKeyStore_MainFunction
 *********************************************************************************************
 */
FUNC(void, KEYMAN_CODE) vHsmKeyStore_MainFunction(void)
{
    Std_ReturnType fl_RetVal_E = E_NOT_OK;
    uint32 MagicNumber = 0;
    CertWriteCheckBg();
    switch(vHsmKeyStore_State)
    {
        case e_KeyStore_KeySet:
            if(vHSMFLS_IDLE == Fls_GetStatus())
            {
                mask_interrupts();
                (void)memset((uint8*)vHsmBlob_Nor,0x00,sizeof(vHsmBlob_Nor));
                (void)memcpy(&vHsmBlob_Byte[0],(uint8*)vHsmKeyStorage_U8A,SYMKEYPERSIZE);
                (void)memcpy(&vHsmBlob_Byte[SYMKEYPERSIZE],(uint8*)vHsmAsymKeys,ASYMKEYPERSIZE);
                fl_RetVal_E = vHsmCrypt_BlobEncapsulation(&vHsmBlob_Byte[0],PERSISTKEYSIZE,(uint8*)&vHsmBlob_Nor[1],KEYBLOBSIZE);
                unmask_interrupts();
                if(E_OK == fl_RetVal_E)
                {
                    vHsmKeyStore_Nor = (uint32 *)FLS_READOFFSET(vHsmKeyStore_KeyAddr_U32);
                    MagicNumber = vHsmKeyStore_Nor[NOR_MAGIC_HEADOFF]+1;
                    if(0xff != KeyBlobInit)
                    {
                        MagicNumber = 0;
                        KeyBlobInit = 0xff;
                    }
                    vHsmKeyStore_KeyAddr_U32 = (vHsmKeyStore_KeyAddr_U32 ^ BANKSWTICHCONST);
                    vHsmBlob_Nor[NOR_MAGIC_HEADOFF] = MagicNumber;
                    vHsmBlob_Nor[NOR_MAGIC_TAILOFF] = (FLS_XOR_CONSTANT ^ MagicNumber);
                    vHsmKeyStore_State = e_KeyStore_KeyErase;
                    TRACE_info("\r\n keyset");
                }
                else
                {
                    /* log fail*/vHsmKeyStore_State = e_KeyStore_Idle;
                }
            }
            break;
        case e_KeyStore_KeyErase:
            mask_interrupts();
            fl_RetVal_E = Fls_Erase(vHsmKeyStore_KeyAddr_U32,256u);
            unmask_interrupts();
            if(E_OK == fl_RetVal_E)
            {
                TRACE_info_arg("\r\n Key Erase",vHsmKeyStore_KeyAddr_U32);
                vHsmKeyStore_State = e_KeyStore_KeyEraseWait;
            }
            else
            {
                /*  Log fail*/vHsmKeyStore_State = e_KeyStore_Idle;
            }
            break;
        case e_KeyStore_KeyEraseWait:
            if(vHSMFLS_IDLE == Fls_GetStatus())
            {
                TRACE_info("\r\n erase wait");
                vHsmKeyStore_State = e_KeyStore_KeyWrite;
            }
            break;
        case e_KeyStore_KeyWrite:
            TRACE_info_arg("\r\n blobsize ",NOR_WRITE_SIZE);
            mask_interrupts();
            fl_RetVal_E = Fls_Write(vHsmKeyStore_KeyAddr_U32,(uint8*)vHsmBlob_Nor,NOR_WRITE_SIZE);
            unmask_interrupts();
            if(E_OK == fl_RetVal_E)
            {
                TRACE_info_arg("\r\n Key write success",vHsmKeyStore_KeyAddr_U32);
            }
            else
            {
                /*Log error */
            }
            if(vHsmKeyStore_RetryCounter == 0u)
            {
                vHsmKeyStore_State = e_KeyStore_Idle ;
            }
            else
            {
                vHsmKeyStore_RetryCounter--;
            }
            break;
        case e_KeyStore_CertSet:
            if(vHSMFLS_IDLE == Fls_GetStatus())
            {
                if(l_QueueIndex > 0u)
                {
                    vHsmCertPointer[CERTOFFSET(vHsmCertQueuID_U32[0])] =  vHsmCertQueue[0];
                    DeQueue_vHsmCertQueue(); /*Dequeue after copying the data*/
                    CertRead = (uint32 *)FLS_READOFFSET(CertAddress);
                    MagicNumber = CertRead[CERTHEADOFFSET] + 1u;
                    if(0xff != CertInitflag)
                    {
                        MagicNumber = 0;
                        CertInitflag = 0xff;
                    }
                    CertAddress = CertAddress ^ BANKSWTICHCONST;
                    vHsmCertBuffer_U32A[CERTHEADOFFSET] = MagicNumber;
                    vHsmCertBuffer_U32A[CERTTAILOFFSET] = (MagicNumber ^ FLS_XOR_CONSTANT);
                    vHsmKeyStore_State = e_KeyStore_CertErase; /*set state to erase*/
                    l_QueueIndex--;
                }
                else
                {
                    vHsmKeyStore_State = e_KeyStore_Idle; /*No Queued Cert go to Idle*/
                }
            }
            break;
        case e_KeyStore_CertErase:
            fl_RetVal_E = Fls_Erase(CertAddress,256u);
            if(E_OK == fl_RetVal_E)
            {
                TRACE_info_arg("\r\n Cert Erase",CertAddress);
                vHsmKeyStore_State = e_KeyStore_CertEraseWait;
            }
            else
            {
                /*  Log fail*/vHsmKeyStore_State = e_KeyStore_Idle;
            }
            break;
        case e_KeyStore_CertEraseWait:
            if(vHSMFLS_IDLE == Fls_GetStatus())
            {
                TRACE_info("\r\n erase wait");
                vHsmKeyStore_State = e_KeyStore_CertWrite;
            }
            break;
        case e_KeyStore_CertWrite:
            mask_interrupts();
            fl_RetVal_E = Fls_Write(CertAddress,(uint8*)vHsmCertBuffer_U32A,sizeof(vHsmCertBuffer_U32A));
            unmask_interrupts();
            if(E_OK == fl_RetVal_E)
            {
                TRACE_info_arg("\r\n Cert write success",CertAddress);
            }
            else
            {
               /*log Error*/
            }
            vHsmKeyStore_State = e_KeyStore_Idle;
            break;
        default:
           break; 
    }
}

/*EOF*/

