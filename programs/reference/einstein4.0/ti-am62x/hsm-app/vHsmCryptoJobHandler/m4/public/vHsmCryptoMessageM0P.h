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
 * \file vHsmCryptoMessageM0P.h
 *
 * \brief
 * Visteon HSM IPC driver header file for IPC Host Manager between cores.
 *
 * \version 1.00.00
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 | 30/Jul/'24 | kjohn    | xxxxxx  | Initial version                       |
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          krithik B John           | kjohn     | VTSC, Bengaluru, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 ******************************************************************************/

#ifndef V_HSM_CRYPTO_MESSM0P_H
#define V_HSM_CRYPTO_MESSM0P_H
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "Std_Types.h"

/******************************************************************************
 *  MACROS
 *****************************************************************************/


/* X-Macro to create a jump table to map the message ID's to the corresponding Application Functions */
/*******************Message_ID*************************FunctionName**************/
#define CRYPTO_JOB_TABLE \
ENTRY(    CID_0,                              Crypto_Dummy_Function        )\
ENTRY(    CID_1_ASYM_EXTRACT_CB,              Crypto_Dummy_Function        )\
ENTRY(    CID_2_ASYM_EXTRACT_FINISH,          Crypto_Dummy_Function        )\
ENTRY(    CID_3_ASYM_EXTRACT_FN,              Crypto_Dummy_Function        )\
ENTRY(    CID_4_ASYM_EXTRACT_START,           Crypto_Dummy_Function        )\
ENTRY(    CID_5_ASYM_EXTRACT_UPDATE,          Crypto_Dummy_Function        )\
ENTRY(    CID_6_CHECKSUM_CB,                  Crypto_Dummy_Function        )\
ENTRY(    CID_7_CHECKSUM_FINISH,              Crypto_Dummy_Function        )\
ENTRY(    CID_8_CHECKSUM_FN,                  Crypto_Dummy_Function        )\
ENTRY(    CID_9_CHECKSUM_START,               Crypto_Dummy_Function        )\
ENTRY(    CID_10_CHECKSUM_UPDATE,             Crypto_Dummy_Function        )\
ENTRY(    CID_11_VERSION_INFO,                Crypto_Dummy_Function        )\
ENTRY(    CID_12_HASH_ALGO_ID,                Crypto_Dummy_Function        )\
ENTRY(    CID_13_HASH_CB,                     Crypto_Dummy_Function        )\
ENTRY(    CID_14_HASH_FINISH,                 Crypto_Dummy_Function        )\
ENTRY(    CID_15_HASH_FN,                     vHsm_HashCalc                )\
ENTRY(    CID_16_HASH_START,                  Crypto_Dummy_Function        )\
ENTRY(    CID_17_HASH_UPDATE,                 Crypto_Dummy_Function        )\
ENTRY(    CID_18_HSM_INIT,                    Crypto_Dummy_Function        )\
ENTRY(    CID_19_MAC_GEN_CB,                  Crypto_Dummy_Function        )\
ENTRY(    CID_20_MAC_GEN_FINISH,              Crypto_Dummy_Function        )\
ENTRY(    CID_21_MAC_GEN_FN,                  vHsm_MacGenerate             )\
ENTRY(    CID_22_MAC_GEN_START,               Crypto_Dummy_Function        )\
ENTRY(    CID_23_MAC_GEN_UPDATE,              Crypto_Dummy_Function        )\
ENTRY(    CID_24_MAC_VER_CB,                  Crypto_Dummy_Function        )\
ENTRY(    CID_25_MAC_VER_FINISH,              Crypto_Dummy_Function        )\
ENTRY(    CID_26_MAC_VER_FN,                  vHsm_MacVerify        )\
ENTRY(    CID_27_MAC_VER_START,               Crypto_Dummy_Function        )\
ENTRY(    CID_28_MAC_VER_UPDATE,              Crypto_Dummy_Function        )\
ENTRY(    CID_29_HSM_MAIN_FUNC,               Crypto_Dummy_Function        )\
ENTRY(    CID_30_RANDOM_CB,                   Crypto_Dummy_Function        )\
ENTRY(    CID_31_RANDOM_GEN,                  vHsm_RandomGenerate          )\
ENTRY(    CID_32_RANDOM_SEED_FINISH,          Crypto_Dummy_Function        )\
ENTRY(    CID_33_RANDOM_SEED_START,           Crypto_Dummy_Function        )\
ENTRY(    CID_34_RANDOM_SEED_UPDATE,          Crypto_Dummy_Function        )\
ENTRY(    CID_35_RANDOM_FN,                   Crypto_Dummy_Function        )\
ENTRY(    CID_36_SIG_VERIFY_CB,               Crypto_Dummy_Function        )\
ENTRY(    CID_37_SIG_VERIFY_FINISH,           Crypto_Dummy_Function        )\
ENTRY(    CID_38_SIG_VERIFY_FN,               Crypto_Dummy_Function        )\
ENTRY(    CID_39_SIG_VERIFY_START,            Crypto_Dummy_Function        )\
ENTRY(    CID_40_SIG_VERIFY_UPDATE,           Crypto_Dummy_Function        )\
ENTRY(    CID_41_SYM_BLOCK_DECRYPT_CB,        Crypto_Dummy_Function        )\
ENTRY(    CID_42_SYM_BLOCK_DECRYPT_FINISH,    Crypto_Dummy_Function        )\
ENTRY(    CID_43_SYM_BLOCK_DECRYPT_FN,        vHsm_AesEcbDecrypt        )\
ENTRY(    CID_44_SYM_BLOCK_DECRYPT_START,     Crypto_Dummy_Function        )\
ENTRY(    CID_45_SYM_BLOCK_DECRYPT_UPDATE,    Crypto_Dummy_Function        )\
ENTRY(    CID_46_SYM_BLOCK_ENCRYPT_CB,        Crypto_Dummy_Function        )\
ENTRY(    CID_47_SYM_BLOCK_ENCRYPT_FINISH,    Crypto_Dummy_Function        )\
ENTRY(    CID_48_SYM_BLOCK_ENCRYPT_FN,        vHsm_AesEcbEncrypt        )\
ENTRY(    CID_49_SYM_BLOCK_ENCRYPT_START,     Crypto_Dummy_Function        )\
ENTRY(    CID_50_SYM_BLOCK_ENCRYPT_UPDATE,    Crypto_Dummy_Function        )\
ENTRY(    CID_51_SYM_DECRYPT_CB,              Crypto_Dummy_Function        )\
ENTRY(    CID_52_SYM_DECRYPT_FINISH,          Crypto_Dummy_Function        )\
ENTRY(    CID_53_SYM_DECRYPT_FN,              vHsm_AesCbcDecrypt        )\
ENTRY(    CID_54_SYM_DECRYPT_START,           Crypto_Dummy_Function        )\
ENTRY(    CID_55_SYM_DECRYPT_UPDATE,          Crypto_Dummy_Function        )\
ENTRY(    CID_56_SYM_ENCRYPT_CB,              Crypto_Dummy_Function        )\
ENTRY(    CID_57_SYM_ENCRYPT_FINISH,          Crypto_Dummy_Function        )\
ENTRY(    CID_58_SYM_ENCRYPT_FN,              vHsm_AesCbcEncrypt        )\
ENTRY(    CID_59_SYM_ENCRYPT_START,           Crypto_Dummy_Function        )\
ENTRY(    CID_60_SYM_ENCRYPT_UPDATE,          Crypto_Dummy_Function        )\
ENTRY(    CID_61_SYM_EXTRACT_CB,              Crypto_Dummy_Function        )\
ENTRY(    CID_62_SYM_EXTRACT_FINISH,          Crypto_Dummy_Function        )\
ENTRY(    CID_63_SYM_EXTRACT_FN,              Crypto_Dummy_Function        )\
ENTRY(    CID_64_SYM_EXTRACT_START,           Crypto_Dummy_Function        )\
ENTRY(    CID_65_SYM_EXTRACT_UPDATE,          Crypto_Dummy_Function        )\
ENTRY(    CID_66_CRYPTO_JOB_CANCEL_CB,        Crypto_Dummy_Function        )\
ENTRY(    CID_67_CRYPTO_JOB_CANCEL_UPDATE,    Crypto_Dummy_Function        )\
ENTRY(    CID_68_KEYSTORE_CB,                 Crypto_Dummy_Function        )\
ENTRY(    CID_69_KEYSSETKEY_FN,               vHsm_KeySet                  )\
ENTRY(    CID_70_KEYSGETKEY_FN,               vHsm_KeyGet                  )

/* X-Macro to create a jump table to map the message ID's to the corresponding Application Functions */
/*******************Message_ID*************************FunctionName**************/
#define COMMAND_JOB_TABLE \
ENTRY(    SID_0,                              Command_Dummy_Function        )\
ENTRY(    SID_1_HARD_RESET_CMD,               Command_Dummy_Function        )\
ENTRY(    SID_2_HSM_WDG_PROXY_NOTIF,          Command_Dummy_Function        )\
ENTRY(    SID_3_DMNMGR_REQ_CB,                Command_Dummy_Function        )\
ENTRY(    SID_4_DMNMGR_REQ_FN,                vHsm_DmnMgrReq                )\
ENTRY(    SID_5_DLTBUFFCLR_CB,                vDLT_BufferClearNotify        )\
ENTRY(    SID_6_DLTBUFFFULL_FN,               Command_Dummy_Function        )
/******************************************************************************
 * Exported type declarations
 *****************************************************************************/
#define ENTRY(a,b)             a,
typedef enum
{
    CRYPTO_JOB_TABLE
    CRYPTO_UNUSED_JOBID
}te_cryptojobid;
#undef ENTRY

typedef enum
{
    CRYPTO_JOB_DONE = 0,
    CRYPTO_JOB_NOT_DONE,
    CRYPTO_JOB_KEY_NOT_THERE
}te_cryptojobresult;
#define HSMCRPT_AES_BLOCK_SIZE_BYTE       (16UL)
#define HSMCRPT_AES_BLOCK_SIZE_WORD       (HSMCRPT_AES_BLOCK_SIZE_BYTE / 4UL)
typedef enum
{
    HSMCRPT_AES_AES128_KEYSIZE_BYTE = 16,
    HSMCRPT_AES_AES192_KEYSIZE_BYTE = 24,
    HSMCRPT_AES_AES256_KEYSIZE_BYTE = 32
} HsmCrpt_AesKeySizeType;
typedef struct
{
    uint8                  AesKey[HSMCRPT_AES_AES256_KEYSIZE_BYTE];
    uint32                 K1[HSMCRPT_AES_BLOCK_SIZE_WORD];
    uint32                 K2[HSMCRPT_AES_BLOCK_SIZE_WORD];
    HsmCrpt_AesKeySizeType KeySize;
} HsmCrpt_AesCmacKeyDataType;
typedef enum
{
    COMMAND_JOB_DONE = 0,
    COMMAND_JOB_NOT_DONE,
}te_commandjobresult;
#undef ENTRY

#define ENTRY(a,b)             a,
typedef enum
{
    COMMAND_JOB_TABLE
    COMMAND_UNUSED_JOBID
}te_commandid;
#undef ENTRY

/* Priority id for the crypto job */
typedef enum
{
    e_priority0 = 0,
    e_priorityunused = 0xFF,
} te_jobpriority;

/* Crypto Job for cancellation */
typedef enum
{
    e_aescbcencrypt = 0,
    e_aescbcdecrypt,
    e_aesecbencrypt,
    e_aesecbdecrypt,
    e_aescmaccommon,
    e_hashsha256,
    e_allcancel,
    e_canceljobunused = 0xFF,
} te_canceljobid;

typedef struct
{
    uint16         payLoadSize;
    uint8 *        payLoadPtr_U8P;
    te_cryptojobid jobId_E;
    te_jobpriority priority_U8;
    uint8          KeyId_U8;
} ts_vHsm_Cryptodata;

typedef struct
{
    uint16         payLoadSize;
    te_jobpriority priority_U8;
    uint8 *        payLoadPtr_U8P;
    te_commandid   jobId_E;
} ts_vHsm_Commanddata;

/******************************************************************************
 *  PUBLIC FUNCTION DECLARATIONS
 *****************************************************************************/
#endif /* V_HSM_CRYPTO_MESSM0P_H */
/* EOF */
