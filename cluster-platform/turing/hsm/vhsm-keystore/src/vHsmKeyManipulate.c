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
 * \file vHsmKeyManipulate.c
 *
 * \brief
 * Visteon HSM Key Manipulation
 *
 * This file shall serve as the keys manipulation (from M1,M2,M3 format to plain
 * key) existing in CM0Plus
 *
 * \version 1.1.2
 * |Version | Date       | Author   | Task Id | Description                                |
 * |--------|------------|----------|---------|--------------------------------------------|
 * |1.00.00 | 13/Jan/'21 | bjayara2 | 1170811 | M1,M2,M3 components of SHE keys            |
 * |1.01.00 | 15/Jan/'21 | bjayara2 | 1174465 | Added Doxygen Support                      |
 * |1.01.01 | 26/Jan/'21 | bjayara2 | 1091176 | M0+ StdTypes FUNC not working - fixed      |
 * |1.01.02 | 03/Feb/'21 | bjayara2 | 1214316 | Implement fail safe recovery in both cores |
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 *
 * \todo Add support for
 * 1. Erase of all the keys
 * 2. HW MP usage for key manipulations
 *
 ******************************************************************************/

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "Std_Types.h"
#include "vHsmKeyStore.h"
#include "vHsmKeyManipulate.h"
#include "string.h"
#include "vHsmCrypt.h"
#include "vHsmCryptoManager.h"

/******************************************************************************
 *  MACROS
 *****************************************************************************/
#ifdef LOCAL
#undef LOCAL
#endif /* LOCAL */
#define LOCAL static

/* Define the below macro KEYMAPPING_LUT for 
using the look up table meant for key mapping 
between key id, key slot, bank details used in 
Extended SHE keys*/

#define KEYMAPPING_LUT
#define SYM_KEY_WRAP

/*==[Types]===================================================================*/
typedef enum
{
    DECRYPT_LOGIC_IDLE =  0,
    FIND_K1,
    FIND_K2,
    FIND_K3,
    FIND_K4,
    SPLIT_M1_M2_M3,
    SPLIT_M2_ELEMENTS,
    VERIFY_MAC_M1_M2,
    COMPARE_KEY_WITH_FLASH_AND_WRITE,
    UNIQUE_ID_CHECK,
    ECC_KEY_WRITE_RESULT_CHECK,
    KEY_WRITE_WAIT_FOR_RESULT,
    KEY_MANIP_MAX_STATES,
    KEY_UPDATE,
}te_vHsmKeyManipStateMachineType;

#ifdef SYM_KEY_WRAP
typedef enum
{
    ENCRYPT_LOGIC_IDLE =  0,
    M1_GENERATION_STATE_IDLE,
    M2_GENERATION_STATE_IDLE,
    M2_GENERATION_STATE_LOAD_KEY,
    M2_GENERATION_STATE_ENCRYPT,
    M3_GENERATION_STATE_IDLE,
    M3_GENERATION_STATE_LOAD_KEY,
    M3_GENERATION_STATE_GENERATE_MAC,
    M1_M2_M3_COMBINE,
}te_vHsmKeyManipSymKeyWrapSMType;
#endif

typedef enum
{
    KEY_DERIVATION_STATE_IDLE = 0,
    KEY_DERIVATION_STATE_ENCRYPT1,
    KEY_DERIVATION_STATE_ENCRYPT2,
    KEY_DERIVATION_STATE_COMPLETED,

}te_vHsmKeyManipKeyDeriveSMType;

#ifdef KEYMAPPING_LUT
#define MAX_LUT_ENTRIES    ((uint8)21)
typedef struct
{
    uint8 keyID;
    uint8 bankID;
    uint8 slotID;
}te_extendedKeyOperations;

te_extendedKeyOperations vHsmKeyManip_ExtKeyMapArr[MAX_LUT_ENTRIES] = 
{
    {1, 0, 255},
    {4, 0, 1},
    {5, 0, 2},
    {6, 0, 3},
    {7, 0, 4},
    {8, 0, 5},
    {9, 0, 6},
    {10, 0, 7},
    {11, 0, 8},
    {12, 0, 9},
    {13, 0, 10},
    {4, 1, 11},
    {5, 1, 12},
    {6, 1, 13},
    {7, 1, 14},
    {8, 1, 15},
    {9, 1, 16},
    {10, 1, 17},
    {11, 1, 18},
    {12, 1, 19},
    {13, 1, 20}
};
#endif

/*==[Macros]==================================================================*/
#define cByte0                               (0u)
#define cByte1                               (1u)
#define cByte4                               (4u)
#define cByte7                               (7u)
#define cByte8                               (8u)
#define cByte12                              (12u)
#define cByte15                              (15u)
#define cByte16                              (16u)
#define cByte20                              (20u)
#define cByte24                              (24u)
#define cByte32                              (32u)
#define cByte48                              (48u)
#define cByte64                              (64u)
#define cByte0F                              (15u)
#define VERIFY_BIT_LENGTH                    (128u)
#define RAM_KEY_SIZE                         (16u)

/*Ram key Id Configuration*/
#define RAM_KEY_ID                           (0xF3uL)
#define SESSION_KEY_ID                       (0xF4uL)
#define IV_KEY_ID                            (0xF5uL)
#define RSA_PSS_2K_KEY_ID                    (0xF6uL)
#define RSA_OAEP_2K_KEY_ID                   (0xF7uL)
#define RSA_PSS_3K_KEY_ID                    (0xF8uL)
#define RSA_OAEP_3K_KEY_ID                   (0xF9uL)
#define ECDSA_KEY_ID                         (0xFAuL)
#define ED25519_KEY_ID                       (0xFBuL)
#define KDF_SESSION_KEY_ID                   (0xFDuL)

#define START_OF_RAMKEYID_INDX               (0xF3uL)
#define END_OF_RAMKEYID_INDX                 (0xFEuL)
/* End of RAM Key Id Configuration */

#define RSA_KEY_SIZE                         (256u)
#define RSA_3K_KEY_SIZE                      (384u)
#define ECDSA_P256_KEY_SIZE                (64u)
#define ECDSA_P384_KEY_SIZE                    (96u)
#define ED25519_KEY_SIZE                     (64u)

#define RAM_KEY_ID_M1_M2_M3_FORMAT           (14u)
#define FLASH_KEY_SIZE                       (64u)
#define ECDSA_KEY_SIZE                       (64u)
#define KDF_SESSION_KEY_SIZE_MSB                       (16u)
#define MASTER_ECU_KEY_ID                    (1u)
#define SFLASH_UID_ADDRESS                   (0x17000E30uL)
#define UID_SIZE                             (15u)
#define ECU_KEYID                            (255u)
#define KEY_USAGE                            (0x02u)
#define DEBUG_PROTECT                        (0x04u)
#define BOOT_PROTECT                         (0x08u)
#define KEY_USAGE_MASK                       (0x80u)
#define KEY_FIELD_MASK                       (0x7FuL)
#define EXTENDED_BANK_SLOTS                  (1u)
#define SIZE_EXTENDED_KEY                    (16u)
#define EXTENDED_KEY_BANK1_CONST             (0x80u)
#define EXTENDED_KEY_ID_CONST                (0x10u)
#define EXTENDED_KEY_SLOTNUM_MAX             (20u)       
#define EXTENDED_SLOTNUM_MASTER_KEY          (255u) 
#define EXTENDED_MAX_SLOTNUM_BANK0           (10u)
#define SAFEKEY_NUMBER_ID                    (7u)
#define TIMEOUT_THRESHOLD                    (30u)

#define CFLASH_ECDSA_PUB_KEY_SIZE              (0x40)

#define CFLASH_ECDSA_HARDENING_PUB_KEY_ID      (0xF1uL)
#define CFLASH_ECDSA_HARDENING_PUB_KEY_ADD_A_BANK     (0x1001FDF0uL)
#define CFLASH_ECDSA_HARDENING_PUB_KEY_ADD_B_BANK     (0x1003FDF0uL)

#define CFLASH_ECDSA_REFLASH_PUB_KEY_ID        (0xF2)
#define CFLASH_ECDSA_REFLASH_PUB_KEY_ADD_A_BANK       (0x1001FE30uL)
#define CFLASH_ECDSA_REFLASH_PUB_KEY_ADD_B_BANK       (0x1003FE30uL)

#define MAX_ALGOS   9U


#define M4_M5_GENERATION_REQ
#define Minkey		(1u)
#define Maxkey		(6u)	

#ifdef SYM_KEY_WRAP
#define M1_LENGTH	16u
#define M2_LENGTH	32u
#define M3_LENGTH	16u
#define M2_INPUT_LENGTH 32u
#define M2_INPUT_KEY_OFFSET 16u
#define M3_INPUT_LENGTH 48u
#define M3_INPUT_M2_OFFSET 16u
#define KEY_LENGTH 16u
#endif

/******************************************************************************
 *  LOCAL VARIABLES DEFINITIONS
 *****************************************************************************/
LOCAL const uint8 c_vHsmKeyManipKeyUpdateEncConst_U8A[16]={0x01,0x01,0x53,0x48,0x45,0x00,
        0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xb0};
LOCAL const uint8 c_vHsmKeyManipKeyUpdateMacConst_U8A[16]={0x01,0x02,0x53,0x48,0x45,0x00,
        0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xb0};
/* Default Auth Key is set to FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF */
LOCAL const uint8 c_vHsmKeyManipDefaultEmptyKey_U8A[16] = {0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
        //LOCAL const uint8 c_vHsmKeyManipDefaultEmptyKey_U8A[16] = {0x00,0x01,0x02,0x03,0x04,
//        0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f};
LOCAL uint32 keyelementid = 0x04;
LOCAL uint16 keysize = 16u;
LOCAL uint32 decryptsize = 16u;
LOCAL te_vHsmKeyManipStateMachineType l_vHsmKeyManip_SM_U8 = DECRYPT_LOGIC_IDLE;
LOCAL te_vHsmKeyManipKeyDeriveSMType  l_vHsmKeyManipKeyDerive_SM_U8 = KEY_DERIVATION_STATE_IDLE;

#ifdef SYM_KEY_WRAP
LOCAL te_vHsmKeyManipSymKeyWrapSMType l_vHsmKeyManipSymKeyWrap_SM_U8 = ENCRYPT_LOGIC_IDLE;
#endif

LOCAL uint8 l_vHsmKeyManip_M1_U8A[16];
LOCAL uint8 l_vHsmKeyManip_M2_U8A[32];
LOCAL uint8 l_vHsmKeyManip_M3_U8A[16];
LOCAL uint8 l_vHsmKeyManip_M1M2_U8A[48];
LOCAL uint8 l_vHsmKeyManip_AuthKeyData_U8A[16];
LOCAL uint8 l_vHsmKeyManip_M2_decrypt_U8A[32];
LOCAL uint8 l_vHsmKeyManipFirstDerivationKey_U8A[16];
LOCAL uint8 l_vHsmKeyManip_SecondDerivationKey_U8A[16];
LOCAL uint8 l_vHsmKeyManip_DerivationBuffer_U8A[16] = {0x00u,0x01u,0x02u,0x03u,0x04u,
        0x05u,0x06u,0x07u,0x08u,0x09u,0x0au,0x0bu,0x0cu,0x0du,0x0eu,0x0fu};
LOCAL uint8 l_vHsmKeyManip_Key_U8A[16];
LOCAL uint8 l_vHsmKeyManip_KeyStoreRAMKey_U8A[RAM_KEY_SIZE];
LOCAL uint8 l_vHsmKeyManip_KeyStoreSessionKey_U8A[RAM_KEY_SIZE];
LOCAL uint8 l_vHsmKeyManip_KeyStoreIVKey_U8A[RAM_KEY_SIZE];
//LOCAL uint8 l_vHsmKeyManipRAMKey_U8;
//LOCAL uint8 l_vHsmKeyManipSessionKey_U8;
// LOCAL uint8 l_vHsmKeyManipIVKey_U8;
// LOCAL uint8 l_vHsmKeyManipRSAPSSKey_2K_U8;
// LOCAL uint8 l_vHsmKeyManipRSAPSSKey_3K_U8;
// LOCAL uint8 l_vHsmKeyManipRSAOAEPKey_2K_U8;
// LOCAL uint8 l_vHsmKeyManipRSAOAEPKey_3K_U8;
LOCAL uint32 l_vHsmKeyID_U32;
//LOCAL uint8 l_vHsmKeyManipWriteTriggered_U8;
LOCAL uint8 l_vHsmKeyManip_authKeyId_U8;
LOCAL uint8 l_vHsmKeyManip_newKeyId_U8;
LOCAL uint8 l_vHsmKeyManip_flags_U8;
LOCAL uint32 l_vHsmKeyManip_counter_U32;
LOCAL uint8 l_vHsmKeyManip_KeyStore16Byte_U8A[16];
LOCAL uint8 l_vHsmKeyManip_aesCmacDerKey_st = {0};
LOCAL uint32 l_vHsmKeyManip_MACVerRes_U32;
LOCAL uint8 l_vHsmKeyManipNewKey_U8A[32];
LOCAL uint8 l_vHsmKeyManipKdfSessionKey_U8A[KDF_SESSION_KEY_SIZE_MSB];
LOCAL uint8 l_vHsmKeyManip_KeyStoreRSAPSSKey_2K_U8A[256] = {0};
LOCAL uint8 l_vHsmKeyManip_KeyStoreRSAPSSKey_3K_U8A[384] = {0};
LOCAL uint8 l_vHsmKeyManip_KeyStoreRSAOAEPKey_2K_U8A[256] = {0};
LOCAL uint8 l_vHsmKeyManip_KeyStoreRSAOAEPKey_3K_U8A[384] = {0};
LOCAL uint8 l_vHsmKeyManip_KeyStoreECDSAKey_96_U8A[96] = {0};
LOCAL uint8 l_vHsmKeyManip_KeyStoreED25519Key_64_U8A[64] = {0};
LOCAL uint8 l_vHsmKeyManip_derivedKey_U8A[16];
LOCAL uint8 l_vHsmKeyManip_InitialVector_U8A[16];
LOCAL ts_WriteStructKeyDataType l_vHsmKeyManip_KeyWriteData_st;
LOCAL ts_WriteStructKeyDataType l_KeyWrite_St;
LOCAL ts_vHsm_Cryptodata l_cryptodatasend_st = {0};
LOCAL uint8 l_vHsmKeyManip_EcdsaKeyValid = 0u;
LOCAL uint8 l_vHsmKeyManip_KdfSessionValid = 0u;
LOCAL uint32 l_vHsmKeyManip_EcdsaKeyID = 0u;
LOCAL uint8 l_vHsmKeyManip_KdfSessionKeyID = 0u;
LOCAL uint32 l_whileloopCounter = 0u;
LOCAL boolean l_whileloopCounterExceeded = FALSE;

#ifdef M4_M5_GENERATION_REQ
LOCAL uint8 l_vHsmKeyManip_M4_U8A[32];
LOCAL uint8 l_vHsmKeyManip_M5_U8A[16];
LOCAL uint8 l_vHsmKeyManipThirdDerivationKey_U8A[16];
LOCAL uint8 l_vHsmKeyManipFourthDerivationKey_U8A[16];
LOCAL uint8 l_vHsmKeyManip_aesCmacDerKey_M5 = {0};
LOCAL uint8 *fl_keyPtr_U8P;    //UID
LOCAL uint8 plaintext_u8[16];
LOCAL uint8 l_vHsmKeyManip_M4_encrypt_U8A[16];
#endif /*M4_M5_GENERATION_REQ*/

LOCAL uint8 *fl_UID_U8P;    //UID
LOCAL uint8 l_UniqueID_NZ[16]; //UID Non-Zero
LOCAL uint16 fl_counter_U16;
LOCAL uint8 l_UIDZeroFlag_U8;
LOCAL uint8 l_vHsmKeyManDeviceKey_U8A[UID_SIZE];
LOCAL uint32 l_keyID_U32;
LOCAL uint8 l_vHsmKeyManipExtKeyCount_U8;
LOCAL uint8 l_vHsmKeyManExtEncKeys_U8[16];
LOCAL uint8 l_vHsmKeyManExtMacKeys_U8[16];

#ifdef SYM_KEY_WRAP
LOCAL uint8 newkey_index_U8 = 0x0E;
LOCAL uint8 authkey_index_U8 = 0x0E;
LOCAL uint8 CID_counter_U8 = 0u;
LOCAL uint8 FID_flag_U8 = 0u;
LOCAL uint8 l_vHsmKeyMan_Wrap_M1_U8A[M1_LENGTH];
LOCAL uint8 l_vHsmKeyMan_Wrap_M2_U8A[M2_LENGTH];
LOCAL uint8 l_vHsmKeyMan_Wrap_M3_U8A[M3_LENGTH];
LOCAL uint8 l_vHsmKeyManip_Wrap_M2_plain_U8A[M2_INPUT_LENGTH];
LOCAL uint8 l_vHsmKeyMan_plainKey_U8[16];
LOCAL uint8 l_vHsmKeyManip_Wrap_M1M2_U8A[M3_INPUT_LENGTH];
LOCAL uint8 l_vHsmKeyMan_Wrap_AuthKeyData_U8A[16] = {0};
LOCAL uint8 l_vHsmKeyMan_Wrap_FirstDerivationKey_U8A[16];
LOCAL uint8 l_vHsmKeyMan_Wrap_SecondDerivationKey_U8A[16];
LOCAL uint8 l_vHsmKeyManip_Wrap_M1M2M3_U8A[65];
LOCAL uint8 l_vHsmKeyManWrap_aesCmacDerKey_M3 = {0};
#endif

LOCAL uint32 l_keySlotNumber_U32;

/******************************************************************************
 *  LOCAL FUNCTION DECLARATIONS
 *****************************************************************************/
LOCAL FUNC (Std_ReturnType, CRY_CODE) vHsmKeyMan_ManipDeriveKey (
                                         const uint8 * const pu8KeyP,
                                         const uint8 * const pu8ConstantP,
                                         uint8 * const pu8OutDataP
                                        );
LOCAL FUNC (void, CRY_CODE) vHsmKeyMan_UpdateFault(void);
FUNC (void, CRY_CODE) vHsmCrypt_SetInternalContext(void);
FUNC (void, CRY_CODE) vHsmCrypt_ClrtInternalContext(void);
FUNC (uint32, CRY_CODE) vHsmKeyman_GetCounter(void);
/******************************************************************************
 *  Public Function Implementations
 *****************************************************************************/

/**
 ******************************************************************************
 ** \fn vHsmKeyManip_Init
 **
 ** Init function to be called before the device key registration
 **
 ** This function returns None
 **
 ** \param [in] NONE
 **
 *****************************************************************************/
FUNC (void, CRY_CODE) vHsmKeyManip_Init(void)
{
    l_vHsmKeyManip_SM_U8 = DECRYPT_LOGIC_IDLE;
    l_vHsmKeyManipKeyDerive_SM_U8 = KEY_DERIVATION_STATE_IDLE;
    (void)memset(l_vHsmKeyManip_InitialVector_U8A, 0, sizeof(l_vHsmKeyManip_InitialVector_U8A));
    // l_vHsmKeyManipRAMKey_U8 = 0u;
   // l_vHsmKeyManipSessionKey_U8 = 0u;
    // l_vHsmKeyManipIVKey_U8 = 0u;
    // l_vHsmKeyManipRSAPSSKey_2K_U8 = 0u;
    // l_vHsmKeyManipRSAPSSKey_3K_U8 = 0u;
    // l_vHsmKeyManipRSAOAEPKey_2K_U8 = 0u;
    // l_vHsmKeyManipRSAOAEPKey_3K_U8 = 0u;
	(void)memcpy(l_vHsmKeyManip_AuthKeyData_U8A, c_vHsmKeyManipDefaultEmptyKey_U8A, 
	sizeof(l_vHsmKeyManip_AuthKeyData_U8A));
    l_vHsmKeyManip_EcdsaKeyValid = 0u;
    l_vHsmKeyManip_EcdsaKeyID = 0u;
    // l_vHsmKeyManipWriteTriggered_U8 = (uint8)0;
    l_vHsmKeyManipExtKeyCount_U8 = (uint8)0;
    (void)memcpy(l_vHsmKeyManExtEncKeys_U8, c_vHsmKeyManipKeyUpdateEncConst_U8A, sizeof(c_vHsmKeyManipKeyUpdateEncConst_U8A));
    (void)memcpy(l_vHsmKeyManExtMacKeys_U8, c_vHsmKeyManipKeyUpdateMacConst_U8A, sizeof(c_vHsmKeyManipKeyUpdateMacConst_U8A));
    l_keySlotNumber_U32 = 0u;
    l_vHsmKeyManipSymKeyWrap_SM_U8 = ENCRYPT_LOGIC_IDLE;
}

/**
 ******************************************************************************
 ** \fn vHsmKeyMan_ManipKeySlotSet
 ** KeySlot number will get set from application side for storing in workflash
 ** keyslot number being unique, can use the same for storing as KeyID
 ** This function returns
 ** - E_NOT_OK if the key slot number exceeds the value of 20 and not 255
 ** - E_OK otherwise.
 **
 ** \param [in] keySlot_U8 - key slot number
 **
 *****************************************************************************/
FUNC (Std_ReturnType, CRY_CODE) vHsmKeyMan_ManipKeySlotSet(uint32 p_keySlotnum_U32)
{
    Std_ReturnType fl_ret_val_E = E_NOT_OK;
    l_vHsmKeyID_U32 = p_keySlotnum_U32;
    if(DECRYPT_LOGIC_IDLE == l_vHsmKeyManip_SM_U8)
    {
        if(p_keySlotnum_U32 <= EXTENDED_KEY_SLOTNUM_MAX)
        {
            l_keySlotNumber_U32 = p_keySlotnum_U32;
            fl_ret_val_E = E_OK;
        }
        else if(p_keySlotnum_U32 == EXTENDED_SLOTNUM_MASTER_KEY)
        {
            l_keySlotNumber_U32 = p_keySlotnum_U32;
            fl_ret_val_E = E_OK;  
        }
        else if((p_keySlotnum_U32 >= START_OF_RAMKEYID_INDX) && (p_keySlotnum_U32 <= END_OF_RAMKEYID_INDX))
        {
            l_keySlotNumber_U32 = p_keySlotnum_U32;
            fl_ret_val_E = E_OK;  
        }
        else
        {
            fl_ret_val_E = E_NOT_OK;
        }
    }
   return (fl_ret_val_E);
}
/**
 ******************************************************************************
 ** \fn vHsmKeyMan_Manipulate
 ** Converts the 64 byte buffer containing M1, M2, M3 to plain key in
 ** the form of 16 bytes, after conversion, triggers keys write procedure
 **
 ** This function returns
 ** - E_NOT_OK if the input buffer pointer is NULL
 ** - E_OK otherwise.
 **
 ** \param [in] keyBuffer_P8 in M1, M2, M3 format
 **
 *****************************************************************************/
FUNC (Std_ReturnType, CRY_CODE) vHsmKeyMan_Manipulate(const uint8 *keyBuffer_P8, uint16 payload_size)
{
    Std_ReturnType fl_ret_val_e = E_NOT_OK;
    Std_ReturnType fl_IPC_ret_val_e = E_NOT_OK;
    static uint8 fl_manip_res_U8;    
	uint8 fl_bankDetail_U8 = 0u;
    uint8 fl_keySlotAuthId = 0u;
    uint8 index_u8 = 0u;        
    if ((DECRYPT_LOGIC_IDLE == l_vHsmKeyManip_SM_U8) && (keyBuffer_P8 != NULL))
    {
/* Update of RAM key can be allowed only when the debugger is connected 
for debug variants  */
        if ((payload_size == RAM_KEY_SIZE) || (payload_size == RSA_KEY_SIZE) || (payload_size == RSA_3K_KEY_SIZE) ||  (payload_size == ECDSA_P384_KEY_SIZE) || (payload_size == ED25519_KEY_SIZE))
   
        {     
        if (l_vHsmKeyID_U32 == SESSION_KEY_ID)
        {
            l_vHsmKeyManipExtKeyCount_U8 = 0u;
            (void)memcpy(l_vHsmKeyManip_KeyStoreSessionKey_U8A, keyBuffer_P8, RAM_KEY_SIZE);
           // l_vHsmKeyManipSessionKey_U8 = 1u;
            fl_ret_val_e = E_OK;
            fl_manip_res_U8 = (uint8)CRYPTO_JOB_DONE;
        }
        else if (l_vHsmKeyID_U32 == IV_KEY_ID)
        {
            l_vHsmKeyManipExtKeyCount_U8 = 0u;
            (void)memcpy(l_vHsmKeyManip_KeyStoreIVKey_U8A, keyBuffer_P8, RAM_KEY_SIZE);
            // l_vHsmKeyManipIVKey_U8 = 1u;
            fl_ret_val_e = E_OK;
            fl_manip_res_U8 = CRYPTO_JOB_DONE;
        }
        else if ((l_vHsmKeyID_U32 == RSA_PSS_2K_KEY_ID) && (RSA_KEY_SIZE == payload_size)){
            l_vHsmKeyManipExtKeyCount_U8 = 0u;
            (void)memcpy(l_vHsmKeyManip_KeyStoreRSAPSSKey_2K_U8A, keyBuffer_P8, RSA_KEY_SIZE);
            // l_vHsmKeyManipRSAPSSKey_2K_U8 = 1u;
            fl_ret_val_e = E_OK;
            fl_manip_res_U8 = (uint8)CRYPTO_JOB_DONE;
        }
        else if ((l_vHsmKeyID_U32 == RSA_PSS_3K_KEY_ID) && (RSA_3K_KEY_SIZE == payload_size)){
            l_vHsmKeyManipExtKeyCount_U8 = 0u;
            (void)memcpy(l_vHsmKeyManip_KeyStoreRSAPSSKey_3K_U8A, keyBuffer_P8, RSA_3K_KEY_SIZE);
            // l_vHsmKeyManipRSAPSSKey_3K_U8 = 1u;
            fl_ret_val_e = E_OK;
            fl_manip_res_U8 = CRYPTO_JOB_DONE;
        }
        else if ((l_vHsmKeyID_U32 == RSA_OAEP_2K_KEY_ID) && (RSA_KEY_SIZE == payload_size)){
            l_vHsmKeyManipExtKeyCount_U8 = 0u;
            (void)memcpy(l_vHsmKeyManip_KeyStoreRSAOAEPKey_2K_U8A, keyBuffer_P8, RSA_KEY_SIZE);
            // l_vHsmKeyManipRSAOAEPKey_2K_U8 = 1u;
            fl_ret_val_e = E_OK;
            fl_manip_res_U8 = CRYPTO_JOB_DONE;
        }
        else if ((l_vHsmKeyID_U32 == RSA_OAEP_3K_KEY_ID) && (RSA_3K_KEY_SIZE == payload_size)){
            l_vHsmKeyManipExtKeyCount_U8 = 0u;
            (void)memcpy(l_vHsmKeyManip_KeyStoreRSAOAEPKey_3K_U8A, keyBuffer_P8, RSA_3K_KEY_SIZE);
            // l_vHsmKeyManipRSAOAEPKey_3K_U8 = 1u;
            fl_ret_val_e = E_OK;
            fl_manip_res_U8 = (uint8)CRYPTO_JOB_DONE;
        }
        else if ((l_vHsmKeyID_U32 == ECDSA_KEY_ID) && (ECDSA_P256_KEY_SIZE == payload_size)){
            l_vHsmKeyManipExtKeyCount_U8 = 0u;
            (void)memcpy(l_vHsmKeyManip_KeyStoreECDSAKey_96_U8A, keyBuffer_P8, ECDSA_P256_KEY_SIZE);
            l_vHsmKeyManip_EcdsaKeyValid = 1u;
            l_vHsmKeyManip_EcdsaKeyID = l_vHsmKeyID_U32;
            fl_ret_val_e = E_OK;
            fl_manip_res_U8 = CRYPTO_JOB_DONE;
        }
        else if ((l_vHsmKeyID_U32 == ECDSA_KEY_ID) && (ECDSA_P384_KEY_SIZE == payload_size)){
            l_vHsmKeyManipExtKeyCount_U8 = 0u;
            (void)memcpy(l_vHsmKeyManip_KeyStoreECDSAKey_96_U8A, keyBuffer_P8, ECDSA_P384_KEY_SIZE);
            fl_ret_val_e = E_OK;
            fl_manip_res_U8 = CRYPTO_JOB_DONE;
        }
        else if ((l_vHsmKeyID_U32 == ED25519_KEY_ID) && (ED25519_KEY_SIZE == payload_size)){
            l_vHsmKeyManipExtKeyCount_U8 = 0u;
            (void)memcpy(l_vHsmKeyManip_KeyStoreED25519Key_64_U8A, keyBuffer_P8, ED25519_KEY_SIZE);
            fl_ret_val_e = E_OK;
            fl_manip_res_U8 = CRYPTO_JOB_DONE;
        }
        else
        {
            l_vHsmKeyManipExtKeyCount_U8 = 0u;
            (void)memcpy(l_vHsmKeyManip_KeyStoreRAMKey_U8A, keyBuffer_P8, RAM_KEY_SIZE);
            // l_vHsmKeyManipRAMKey_U8 = 1u;
            fl_ret_val_e = E_OK;
            fl_manip_res_U8 = (uint8)CRYPTO_JOB_DONE; 
        }
            l_cryptodatasend_st.jobId_E = CID_61_SYM_EXTRACT_CB;
            l_cryptodatasend_st.KeyId_U8 = 0u;
            l_cryptodatasend_st.priority_U8 = e_priorityunused;
            l_cryptodatasend_st.payLoadPtr_U8P = &fl_manip_res_U8;
            l_cryptodatasend_st.payLoadSize = (uint16)(1);
            fl_IPC_ret_val_e = vHsmCrypto_Manager_SendData(l_cryptodatasend_st);
            if(E_NOT_OK == fl_IPC_ret_val_e)
            {
                /* Message not sent through IPC */
                /* TBD */
            }
            else
            {
                /* Data sent through IPC */
            }
        }
        else if(payload_size == FLASH_KEY_SIZE)
        {
            l_vHsmKeyManipExtKeyCount_U8 = 0u;
            (void)memcpy(&l_vHsmKeyManip_M1_U8A[0], &keyBuffer_P8[cByte0], sizeof(l_vHsmKeyManip_M1_U8A));
            (void)memcpy(&l_vHsmKeyManip_M2_U8A[0], &keyBuffer_P8[cByte16], sizeof(l_vHsmKeyManip_M2_U8A));
            (void)memcpy(&l_vHsmKeyManip_M3_U8A[0], &keyBuffer_P8[cByte48], sizeof(l_vHsmKeyManip_M3_U8A));
            (void)memcpy(l_vHsmKeyManExtEncKeys_U8, c_vHsmKeyManipKeyUpdateEncConst_U8A, 
            sizeof(c_vHsmKeyManipKeyUpdateEncConst_U8A));
            (void)memcpy(l_vHsmKeyManExtMacKeys_U8, c_vHsmKeyManipKeyUpdateMacConst_U8A, 
            sizeof(c_vHsmKeyManipKeyUpdateMacConst_U8A));            
            if((l_keySlotNumber_U32 > EXTENDED_MAX_SLOTNUM_BANK0)&&(l_keySlotNumber_U32!=EXTENDED_SLOTNUM_MASTER_KEY))
            {
                fl_bankDetail_U8 = 1u;
                l_vHsmKeyManExtEncKeys_U8[1] += EXTENDED_KEY_BANK1_CONST;
                l_vHsmKeyManExtMacKeys_U8[1] += EXTENDED_KEY_BANK1_CONST;
            }
            else
            {
                /* Bank 0 can use the default values*/
            }          
            l_vHsmKeyManip_authKeyId_U8 = (uint8)(l_vHsmKeyManip_M1_U8A[15] & cByte0F);
            l_vHsmKeyManip_newKeyId_U8 = (uint8)((l_vHsmKeyManip_M1_U8A[15] >> 4U) & cByte0F);                       
            // l_vHsmKeyManipWriteTriggered_U8 = (uint8)1;
            /* Identify the relevant key slot number from the
            Auth Id in M1 */
            if(vHsmKeyManip_ExtKeyMapArr[0].keyID == l_vHsmKeyManip_authKeyId_U8)
            {
                fl_keySlotAuthId = 255u;
            }
            else
            {
                for(index_u8 = 0; index_u8 <MAX_LUT_ENTRIES; index_u8++)
                {
                    if((vHsmKeyManip_ExtKeyMapArr[index_u8].keyID == l_vHsmKeyManip_authKeyId_U8 )
                    &&(vHsmKeyManip_ExtKeyMapArr[index_u8].bankID == fl_bankDetail_U8))
                    {
                        fl_keySlotAuthId = vHsmKeyManip_ExtKeyMapArr[index_u8].slotID;
                        break;
                    }
                    else
                    {
                        if(l_vHsmKeyManip_authKeyId_U8 == authkey_index_U8 )
                        {
                            fl_keySlotAuthId = 22u;
                        }
                    }
                }
            }
            if(fl_keySlotAuthId == 0)
            {
                /* The combination of update slot and authentication slot is not allowed */
                vHsmKeyMan_UpdateFault_To_M7(CRY_SHE_ERR_AUTH_ID_INVALID);
                l_vHsmKeyManip_SM_U8 = DECRYPT_LOGIC_IDLE;
            }
            else
            {
                /*Normal Manipulate Flow will be followed*/
            }
            fl_ret_val_e = vHsmKeyStore_GetKey(fl_keySlotAuthId, keyelementid, l_vHsmKeyManip_AuthKeyData_U8A,&keysize);            
// #if (PROJECT_KEYMAN_VARIANT != GM_T1XX)

//             if(E_OK != fl_ret_val_e)
//             {
//                 (void)memcpy(l_vHsmKeyManip_AuthKeyData_U8A, c_vHsmKeyManipDefaultEmptyKey_U8A, 
//                 sizeof(l_vHsmKeyManip_AuthKeyData_U8A));
//             }
//             else
//             {
                /* Do nothing */
//             }
//             l_vHsmKeyManip_SM_U8 = FIND_K1;
//             fl_ret_val_e = E_OK;           
//             l_vHsmKeyManipWriteTriggered_U8 = (uint8)0;
//             if(l_vHsmKeyManip_newKeyId_U8 == RAM_KEY_ID)
//             {
//                 l_whileloopCounter=0;
//                 l_whileloopCounterExceeded = FALSE;
//                 while((l_vHsmKeyManip_SM_U8 != DECRYPT_LOGIC_IDLE) && (l_whileloopCounter < TIMEOUT_THRESHOLD))
//                 {   
//                     l_whileloopCounter++;
//                     vHsmKeyMan_ManipPeriodic();
//                 }
//                 if (l_whileloopCounter >= TIMEOUT_THRESHOLD)
//                 {
//                     l_whileloopCounterExceeded = TRUE;
//                     vHsmKeyMan_UpdateFault();
//                 }
//                 else
//                 {
                    /* Do nothing*/
//                 }
//             }
//             else
//             {
                /* Do nothing as it is the normal flow for flash key*/
//             }
// #elif (PROJECT_KEYMAN_VARIANT == GM_T1XX)
            if(E_OK != fl_ret_val_e)
            {
                if(l_vHsmKeyManip_authKeyId_U8 == l_vHsmKeyManip_newKeyId_U8)
                {
                    (void)memcpy(l_vHsmKeyManip_AuthKeyData_U8A, c_vHsmKeyManipDefaultEmptyKey_U8A, 
                    sizeof(l_vHsmKeyManip_AuthKeyData_U8A));

                    l_vHsmKeyManip_SM_U8 = FIND_K1;
                    fl_ret_val_e = E_OK;           
                    // l_vHsmKeyManipWriteTriggered_U8 = 0U;
                    if(l_vHsmKeyManip_newKeyId_U8 == RAM_KEY_ID_M1_M2_M3_FORMAT)
                    {
                        l_whileloopCounter = 0;
                        l_whileloopCounterExceeded = FALSE;
                        while((l_vHsmKeyManip_SM_U8 != DECRYPT_LOGIC_IDLE)  && (l_whileloopCounter < TIMEOUT_THRESHOLD))
                        {
                            l_whileloopCounter++;
                            vHsmKeyMan_ManipPeriodic();
                        }
                        if (l_whileloopCounter >= TIMEOUT_THRESHOLD)
                        {
                            l_whileloopCounterExceeded = TRUE;
                            vHsmKeyMan_UpdateFault();
                        }
                        else
                        {
                            /* Do nothing */
                        }
                    }
                    else
                    {
                        /* Do nothing as it is the normal flow for flash key*/
                    }
                }
                else
                {
                    /* The authentication slot is empty. */
                    vHsmKeyMan_UpdateFault_To_M7(CRY_SHE_ERR_KEY_SLOT_EMPTY);
                    l_vHsmKeyManip_SM_U8 = DECRYPT_LOGIC_IDLE;
                }
            }
            else
            {
                l_vHsmKeyManip_SM_U8 = FIND_K1;
                fl_ret_val_e = E_OK;           
                // l_vHsmKeyManipWriteTriggered_U8 = 0U;
            }
// #endif
        }
        else
        {
        }
    }
    return(fl_ret_val_e);
}

/**
 ******************************************************************************
 ** \fn vHsmKeyMan_Manipulate_16bytesKey
 ** Accept 16 bytes of Key for Keyman 
 ** This function returns
 ** - E_NOT_OK if the input buffer pointer is NULL
 ** - E_OK otherwise.
 **
 ** \param [in] keyBuffer_P8 in M1, M2, M3 format
 **
 *****************************************************************************/
FUNC (Std_ReturnType, CRY_CODE) vHsmKeyMan_Manipulate_16bytesKey( uint32 KeyId, uint8 *keydata, uint16 payload_size)
{
    Std_ReturnType fl_ret_val_e = E_NOT_OK;
    l_keyID_U32 = KeyId;
    if(payload_size != RAM_KEY_SIZE)
    {
       fl_ret_val_e = E_NOT_OK;   
    }
    else
    {
       (void)memcpy(l_vHsmKeyManip_KeyStore16Byte_U8A, keydata, RAM_KEY_SIZE);
       l_vHsmKeyManip_SM_U8 = KEY_UPDATE;
       fl_ret_val_e = E_OK; 
    }          
    return(fl_ret_val_e);
}

/**
 ******************************************************************************
 ** \fn vHsmKeyMan_GetECDSAKey
 ** Reads the ECDSA RAM Key and returns in the buffer 
 ** This function returns
 ** - E_NOT_OK if the key could not be found in RAM
 ** - E_OK otherwise.
 **
 ** \param [in] KeyId, pointer to the memory area where key needs to be copied
 **
 *****************************************************************************/
FUNC (Std_ReturnType, CRY_CODE) vHsmKeyMan_GetECDSAKey(uint32 KeyId, uint8 *keydata)
{
    Std_ReturnType fl_ret_val_e = E_NOT_OK;
    uint8 * ReflashKeyPtr_U8P;
    uint8 * HardeningKeyPtr_U8P;
    
    if( CFLASH_ECDSA_REFLASH_PUB_KEY_ID == KeyId)
    {
        #ifdef VHSMA
		{
			ReflashKeyPtr_U8P = (uint8*) CFLASH_ECDSA_REFLASH_PUB_KEY_ADD_A_BANK;
            (void) memcpy(keydata, ReflashKeyPtr_U8P, CFLASH_ECDSA_PUB_KEY_SIZE);
		}
        #else
        {
            ReflashKeyPtr_U8P = (uint8*) CFLASH_ECDSA_REFLASH_PUB_KEY_ADD_B_BANK;
            (void) memcpy(keydata, ReflashKeyPtr_U8P, CFLASH_ECDSA_PUB_KEY_SIZE);
        }
        #endif /* VHSMA */
    }
    else if( CFLASH_ECDSA_HARDENING_PUB_KEY_ID == KeyId)
    {
        #ifdef VHSMA
		{
			HardeningKeyPtr_U8P = (uint8*) CFLASH_ECDSA_HARDENING_PUB_KEY_ADD_A_BANK;
            (void) memcpy(keydata, HardeningKeyPtr_U8P, CFLASH_ECDSA_PUB_KEY_SIZE);
		}
        #else
        {
            HardeningKeyPtr_U8P = (uint8*) CFLASH_ECDSA_HARDENING_PUB_KEY_ADD_B_BANK;
            (void) memcpy(keydata, HardeningKeyPtr_U8P, CFLASH_ECDSA_PUB_KEY_SIZE);
        }
        #endif /* VHSMA */
    }
    else
    {
        if((l_vHsmKeyManip_EcdsaKeyValid != 0u) &&
        (l_vHsmKeyManip_EcdsaKeyID == KeyId) &&
        (keydata != NULL))
        {
            (void)memcpy(keydata, &l_vHsmKeyManip_KeyStoreECDSAKey_96_U8A[0],ECDSA_KEY_SIZE);
            fl_ret_val_e = E_OK;
        }
    }
    return(fl_ret_val_e);
}
/**
 ******************************************************************************
 ** \fn vHsmKeyMan_GetKdfSessionKey
 ** Reads the Session Key and returns in the buffer 
 ** This function returns
 ** - E_NOT_OK if the key could not be found in RAM
 ** - E_OK otherwise.
 **
 ** \param [in] KeyId, pointer to the memory area where key needs to be copied
 **
 *****************************************************************************/
FUNC (Std_ReturnType, CRY_CODE) vHsmKeyMan_GetKdfSessionKey(uint8 TargetKeyId, uint8 *keydata)
{
    Std_ReturnType fl_ret_val_e = E_NOT_OK;
    
    if((l_vHsmKeyManip_KdfSessionValid != 0u) &&
    (l_vHsmKeyManip_KdfSessionKeyID == TargetKeyId) &&
    (keydata != NULL))
    {
        (void)memcpy(keydata, &l_vHsmKeyManipKdfSessionKey_U8A[0],KDF_SESSION_KEY_SIZE_MSB);
        fl_ret_val_e = E_OK;
    }
    return(fl_ret_val_e);
}
/**
 ******************************************************************************
 ** \fn vHsmKeyMan_ManipPeriodic
 **
 ** Conversion logics for M1, M2, M3 to plain key in periodic call
 **
 ** This function returns void
 **
 ** \param [in] NONE
 **
 *****************************************************************************/
FUNC (void, CRY_CODE) vHsmKeyMan_ManipPeriodic(void)
{
    static uint8 fl_priodic_res_U8;
    uint8 u8IndexL;
#ifdef M4_M5_GENERATION_REQ
    uint8 l_vHsmKeyManip_M4M5_U8A[64]={0x00};
#endif    
  
    Std_ReturnType fl_retVal = E_NOT_OK;
    te_WriteResultType fl_retValWriteChk_e;
    
    switch(l_vHsmKeyManip_SM_U8)
    {
        case DECRYPT_LOGIC_IDLE:
            /* Do nothing */
            break;
        case FIND_K1:
           // // vHsmMcu_EnterCriticalSection();
            l_whileloopCounter = 0;
            l_whileloopCounterExceeded = FALSE;
            while((KEY_DERIVATION_STATE_COMPLETED !=  l_vHsmKeyManipKeyDerive_SM_U8) && (l_whileloopCounter < TIMEOUT_THRESHOLD))
            {
                l_whileloopCounter++;
                fl_retVal = vHsmKeyMan_ManipDeriveKey(l_vHsmKeyManip_AuthKeyData_U8A, l_vHsmKeyManExtEncKeys_U8, l_vHsmKeyManipFirstDerivationKey_U8A);
            }
            if (l_whileloopCounter >= TIMEOUT_THRESHOLD)
            {
                l_whileloopCounterExceeded = TRUE;
                vHsmKeyMan_UpdateFault();
                fl_retVal =E_NOT_OK;
            }
            else
            {
                /* Do nothing */
            }
            if(E_OK == fl_retVal)
            {
                l_vHsmKeyManipKeyDerive_SM_U8 = KEY_DERIVATION_STATE_IDLE;
                l_vHsmKeyManip_SM_U8 = FIND_K2;
            }
            else
            {
                vHsmKeyMan_UpdateFault();
            }
            // vHsmMcu_ExitCriticalSection();
            break;
        case FIND_K2:
            // vHsmMcu_EnterCriticalSection();
            l_whileloopCounter = 0;
            l_whileloopCounterExceeded = FALSE;
            while((KEY_DERIVATION_STATE_COMPLETED != l_vHsmKeyManipKeyDerive_SM_U8)  && (l_whileloopCounter < TIMEOUT_THRESHOLD))
            {
                l_whileloopCounter++;
                fl_retVal = vHsmKeyMan_ManipDeriveKey(l_vHsmKeyManip_AuthKeyData_U8A, l_vHsmKeyManExtMacKeys_U8, l_vHsmKeyManip_SecondDerivationKey_U8A);
            }
            if (l_whileloopCounter >= TIMEOUT_THRESHOLD)
            {
                l_whileloopCounterExceeded = TRUE;
                vHsmKeyMan_UpdateFault();
                fl_retVal = E_NOT_OK;
            }
            else
            {
                /* Do nothing */
            }
            if(E_OK == fl_retVal)
            {
                l_vHsmKeyManip_SM_U8 = VERIFY_MAC_M1_M2;
                l_vHsmKeyManipKeyDerive_SM_U8 = KEY_DERIVATION_STATE_IDLE;
            }
            else
            {
                vHsmKeyMan_UpdateFault();
            }
            // vHsmMcu_ExitCriticalSection();
            break;      
        case VERIFY_MAC_M1_M2:
            // vHsmMcu_EnterCriticalSection();
                (void) memcpy(&l_vHsmKeyManip_M1M2_U8A[0], &l_vHsmKeyManip_M1_U8A, 16);
                (void) memcpy(&l_vHsmKeyManip_M1M2_U8A[16], &l_vHsmKeyManip_M2_U8A, 32);
                fl_retVal =  vHsmCrypt_AesCmacVerify(&l_vHsmKeyManip_aesCmacDerKey_st, cByte16, &l_vHsmKeyManip_M1M2_U8A[0],
                        cByte48, &l_vHsmKeyManip_M3_U8A[0], VERIFY_BIT_LENGTH, &l_vHsmKeyManip_MACVerRes_U32);
                if((E_OK == fl_retVal) && (0u == l_vHsmKeyManip_MACVerRes_U32))
                {
                    l_vHsmKeyManip_SM_U8 = SPLIT_M1_M2_M3;
                }
                else
                {
                    /* Parameters M1 and M2 could not be verified due to unmatched parameter M3*/
                    vHsmKeyMan_UpdateFault_To_M7(CRY_SHE_ERR_VERIFICATION_FAILED);
                    l_vHsmKeyManip_SM_U8 = DECRYPT_LOGIC_IDLE;             
                }
            // vHsmMcu_ExitCriticalSection();
            break;
        case SPLIT_M1_M2_M3:
            // vHsmMcu_EnterCriticalSection();
            /* M1 split */
            (void)memset(l_vHsmKeyManip_M2_decrypt_U8A, 0 , sizeof(l_vHsmKeyManip_M2_decrypt_U8A));
            (void)memset(l_vHsmKeyManipNewKey_U8A, 0, sizeof(l_vHsmKeyManipNewKey_U8A));
            (void)memset(l_vHsmKeyManip_derivedKey_U8A, 0, sizeof(l_vHsmKeyManip_derivedKey_U8A));

            l_vHsmKeyManip_newKeyId_U8 = (uint8)((l_vHsmKeyManip_M1_U8A[15] >> 4U) & cByte0F);
            if(((l_vHsmKeyManip_newKeyId_U8 == l_vHsmKeyManip_authKeyId_U8) && (l_vHsmKeyManip_newKeyId_U8 != RAM_KEY_ID_M1_M2_M3_FORMAT)) ||
            ((l_vHsmKeyManip_authKeyId_U8 == MASTER_ECU_KEY_ID) && (l_vHsmKeyManip_newKeyId_U8 != RAM_KEY_ID_M1_M2_M3_FORMAT)) || 
            ((l_vHsmKeyManip_newKeyId_U8 == RAM_KEY_ID_M1_M2_M3_FORMAT) && (MASTER_ECU_KEY_ID != l_vHsmKeyManip_authKeyId_U8)))
            {
                /* M2 split */
                /* Get a derived key for all decryptions  */
                    fl_retVal = vHsmCrypt_AesEcbDecrypt(&l_vHsmKeyManip_derivedKey_U8A[0],cByte16,
                            &l_vHsmKeyManip_M2_U8A[16],16u, &l_vHsmKeyManip_M2_decrypt_U8A[16], &decryptsize);
                    if(E_OK == fl_retVal)
                    {
                        for(u8IndexL=cByte0;u8IndexL<cByte16;u8IndexL++) // Xor
                        {
                            l_vHsmKeyManipNewKey_U8A[u8IndexL] = l_vHsmKeyManip_M2_U8A[u8IndexL] ^ l_vHsmKeyManip_M2_decrypt_U8A[16u+u8IndexL];
                        }
                        l_vHsmKeyManip_SM_U8 = SPLIT_M2_ELEMENTS;
                    }
                    else
                    {
                        vHsmKeyMan_UpdateFault();
                    }
            }
            else
            {
                vHsmKeyMan_UpdateFault();                
            }
            // vHsmMcu_ExitCriticalSection();
            break;
        case SPLIT_M2_ELEMENTS:
            // vHsmMcu_EnterCriticalSection();
            fl_retVal = vHsmCrypt_AesEcbDecrypt(&l_vHsmKeyManip_derivedKey_U8A[0],cByte16,
                    &l_vHsmKeyManip_M2_U8A[0],cByte16, &l_vHsmKeyManip_M2_decrypt_U8A[0], &decryptsize);
            if(E_OK == fl_retVal)
            {
                l_vHsmKeyManip_flags_U8 = (l_vHsmKeyManip_M2_decrypt_U8A[4u] >> 7u) & (cByte1);
                l_vHsmKeyManip_flags_U8 |= (((l_vHsmKeyManip_M2_decrypt_U8A[3u]) & (cByte0F)) << 1);
                l_vHsmKeyManip_counter_U32 = (((uint32)l_vHsmKeyManip_M2_decrypt_U8A[3u] >> 4u) & (cByte0F));
                l_vHsmKeyManip_counter_U32 |= (((uint32)l_vHsmKeyManip_M2_decrypt_U8A[0u]) << 20u );
                l_vHsmKeyManip_counter_U32 |= (((uint32)l_vHsmKeyManip_M2_decrypt_U8A[1u]) << 12u );
                l_vHsmKeyManip_counter_U32 |= (((uint32)l_vHsmKeyManip_M2_decrypt_U8A[2u]) << 4u );
                
#ifdef M4_M5_GENERATION_REQ
                l_vHsmKeyManip_SM_U8 = FIND_K3;
#else
                l_vHsmKeyManip_SM_U8 = UNIQUE_ID_CHECK;
#endif /*M4_M5_GENERATION_REQ*/
            }
            else
            {
                vHsmKeyMan_UpdateFault();
            }
            // vHsmMcu_ExitCriticalSection();
            break;

#ifdef M4_M5_GENERATION_REQ
        case FIND_K3:
            // vHsmMcu_EnterCriticalSection();
            l_whileloopCounter = 0;
            l_whileloopCounterExceeded = FALSE;
            while((KEY_DERIVATION_STATE_COMPLETED !=  l_vHsmKeyManipKeyDerive_SM_U8) && (l_whileloopCounter < TIMEOUT_THRESHOLD))
            {
                l_whileloopCounter++;
                fl_retVal = vHsmKeyMan_ManipDeriveKey( l_vHsmKeyManipNewKey_U8A, l_vHsmKeyManExtEncKeys_U8, l_vHsmKeyManipThirdDerivationKey_U8A);
            }
            if (l_whileloopCounter >= TIMEOUT_THRESHOLD)
            {
                l_whileloopCounterExceeded = TRUE;
                vHsmKeyMan_UpdateFault();
                fl_retVal = E_NOT_OK;
            }
            else
            {
                /* Do nothing */
            }
            if(E_OK == fl_retVal)
            {
                l_vHsmKeyManipKeyDerive_SM_U8 = KEY_DERIVATION_STATE_IDLE;
                l_vHsmKeyManip_SM_U8 = FIND_K4;
            }
            else
            {
                vHsmKeyMan_UpdateFault();
            }
            break;
            case FIND_K4:
            l_whileloopCounter = 0;
            l_whileloopCounterExceeded = FALSE;
            while((KEY_DERIVATION_STATE_COMPLETED !=  l_vHsmKeyManipKeyDerive_SM_U8) && (l_whileloopCounter < TIMEOUT_THRESHOLD))
            {
                l_whileloopCounter++;
                fl_retVal = vHsmKeyMan_ManipDeriveKey( l_vHsmKeyManipNewKey_U8A, l_vHsmKeyManExtMacKeys_U8, l_vHsmKeyManipFourthDerivationKey_U8A);
            }
            if (l_whileloopCounter >= TIMEOUT_THRESHOLD)
            {
                l_whileloopCounterExceeded = TRUE;
                vHsmKeyMan_UpdateFault();
                fl_retVal = E_NOT_OK;
            }
            else
            {
                /* Do nothing */
            }
            if(E_OK == fl_retVal)
            {                
                l_vHsmKeyManip_SM_U8 = UNIQUE_ID_CHECK;
                l_vHsmKeyManipKeyDerive_SM_U8 = KEY_DERIVATION_STATE_IDLE;
            }
            else
            {
                vHsmKeyMan_UpdateFault();
            }
            // vHsmMcu_ExitCriticalSection();
            break;
#endif /*M4_M5_GENERATION_REQ*/
        case UNIQUE_ID_CHECK:
            // vHsmMcu_EnterCriticalSection();
            /*
                DESCRIPTION
            */
            fl_UID_U8P = (uint8 *)SFLASH_UID_ADDRESS;
            (void)memcpy(&l_vHsmKeyManDeviceKey_U8A[0], fl_UID_U8P,
                UID_SIZE);
            l_UIDZeroFlag_U8 = (uint8)1; //FLAG for UID if entirely zero
            for(fl_counter_U16 = 0u; fl_counter_U16 < UID_SIZE; fl_counter_U16++)
            {
                if (l_vHsmKeyManip_M1_U8A[fl_counter_U16] != 0u) //Comparing UID from M1 to 0
                {
                    l_UIDZeroFlag_U8 = (uint8)0; //Set to 0 as Non-Zero
                    //Reading and copy of UID as UID!=0
		            (void)memcpy(&l_UniqueID_NZ[0], &l_vHsmKeyManip_M1_U8A[0], UID_SIZE); //Reading l_UniqueID (Non-Zero) 
                    break;
                }
            }
            if(l_UIDZeroFlag_U8 != (uint8)0)
		    {
                l_vHsmKeyManip_SM_U8 = COMPARE_KEY_WITH_FLASH_AND_WRITE;
		    }
		    else
		    {
                /* Since UID field is not zero, compare with the UID field and
                move to next only when the UID matches, else, stop 
                further processing of key update procedure */             
                if (memcmp(l_UniqueID_NZ, l_vHsmKeyManDeviceKey_U8A, UID_SIZE) == (int)0) //M1 UID & stored UID Compare Check
                {
                    l_vHsmKeyManip_SM_U8 = COMPARE_KEY_WITH_FLASH_AND_WRITE;
                }
                else
                {
                    /* The non-zero UID parameter does not match the embedded SHE UID*/
                    vHsmKeyMan_UpdateFault_To_M7(CRY_SHE_ERR_UID_INVALID);
                    l_vHsmKeyManip_SM_U8 = DECRYPT_LOGIC_IDLE;
                }

		    }          
            // vHsmMcu_ExitCriticalSection();
            break;
        case COMPARE_KEY_WITH_FLASH_AND_WRITE:
            // vHsmMcu_EnterCriticalSection();
            /* pass Key Id, counter, flags and Key value to vHsmKeyMan.c API
             * for getting the compare results
             * Can write to flash only when the flags are already 0
             * Can write to flash only when the counter already present
             * for the specific Key Id is less than the new one from here
             * After the above checks turn out to be positive,
             * need to move to next state, result will be in pending state
             * till then,
             * Otherwise, result to IPC can be updated here for being negative
             * Components to go to other API are as below -
             * l_vHsmKeyManipNewKey_U8A
             * l_vHsmKeyManip_counter_U32
             * l_vHsmKeyManip_flags_U8
             * l_vHsmKeyManip_authKeyId_U8
             * l_vHsmKeyManip_newKeyId_U8*/
            if(RAM_KEY_ID_M1_M2_M3_FORMAT == l_vHsmKeyManip_newKeyId_U8)
            {
                (void)memcpy(l_vHsmKeyManip_KeyStoreRAMKey_U8A, &l_vHsmKeyManipNewKey_U8A[0], RAM_KEY_SIZE);
                // l_vHsmKeyManipRAMKey_U8 = 1u;
                fl_retVal = E_OK;
                fl_priodic_res_U8 = (uint8)CRYPTO_JOB_DONE;
                l_cryptodatasend_st.jobId_E = CID_61_SYM_EXTRACT_CB;
                l_cryptodatasend_st.KeyId_U8 = 0u;
                l_cryptodatasend_st.priority_U8 = e_priorityunused;
                l_cryptodatasend_st.payLoadPtr_U8P = &fl_priodic_res_U8;
                l_cryptodatasend_st.payLoadSize = (uint16)(1);
                fl_retVal = vHsmCrypto_Manager_SendData(l_cryptodatasend_st);
                if(E_NOT_OK == fl_retVal)
                {
                    /* Message not sent through IPC */
                    /* TBD */
                }
                else
                {
                    /* Data sent through IPC */
                }
                l_vHsmKeyManip_SM_U8 = DECRYPT_LOGIC_IDLE;
            }
            else
            {
#ifdef M4_M5_GENERATION_REQ
                /*  Generation of M4  */
                /*  M4=UID|ID|AUTH ID|M4*       M4* = ENCECB,K3(cid)  */
                
                (void)memset(l_vHsmKeyManip_M4_encrypt_U8A, 0 , sizeof(l_vHsmKeyManip_M4_encrypt_U8A));
                (void)memset(plaintext_u8, 0 , sizeof(plaintext_u8));
                (void)memcpy(plaintext_u8,&l_vHsmKeyManip_M2_decrypt_U8A[0],cByte4);
                plaintext_u8[3]&=~0x0fu;
                plaintext_u8[3]|=(uint8)0x08;     
                (void)memset(plaintext_u8+cByte4,0,cByte12);

                fl_retVal=vHsmCrypt_AesEcbEncrypt(&l_vHsmKeyManipThirdDerivationKey_U8A[0],cByte16, 
                &plaintext_u8[0] ,cByte16,&l_vHsmKeyManip_M4_encrypt_U8A[0],&decryptsize);
                
                if(E_OK == fl_retVal)
                    {
						(void)memcpy(l_vHsmKeyManip_M4_U8A,&l_vHsmKeyManDeviceKey_U8A[0],UID_SIZE);						
                        (void)memcpy(l_vHsmKeyManip_M4_U8A+UID_SIZE,&l_vHsmKeyManip_M1_U8A[UID_SIZE],1);
                        (void)memcpy(l_vHsmKeyManip_M4_U8A+cByte16,&l_vHsmKeyManip_M4_encrypt_U8A[0],sizeof(l_vHsmKeyManip_M4_encrypt_U8A));
                    }
                else
                    {  
                        vHsmKeyMan_UpdateFault();
                        break;
                    }
              
                 /*  Generation of M5  */
                 /*   CMAC K4 (M4)     */
                (void)vHsmCrypt_AesCmacGenerate(&l_vHsmKeyManip_aesCmacDerKey_M5,cByte16, &l_vHsmKeyManip_M4_U8A[0],(uint32)cByte32,
                            &l_vHsmKeyManip_M5_U8A[0],(uint32)cByte16);					   
#endif /* M4_M5_GENERATION_REQ */
                l_vHsmKeyManip_KeyWriteData_st.AlgoId = AES_128;
                l_vHsmKeyManip_KeyWriteData_st.AuthId = l_vHsmKeyManip_authKeyId_U8;
                if(l_vHsmKeyManipExtKeyCount_U8 != 0u)                
                {
                    if(l_vHsmKeyManip_newKeyId_U8 < ((uint8)UINT8_MAX - EXTENDED_KEY_ID_CONST))
                    {
                        l_vHsmKeyManip_newKeyId_U8 += EXTENDED_KEY_ID_CONST;
                    }
                    else
                    {
                        /* Defensive fallback: clamp at max value */
                        l_vHsmKeyManip_newKeyId_U8 = 0;
                    }
                }
                else
                {
                    /* Do nothing */
                }
                l_vHsmKeyManip_KeyWriteData_st.KeyId = l_keySlotNumber_U32;               
                l_vHsmKeyManip_KeyWriteData_st.Counter = l_vHsmKeyManip_counter_U32;
                l_vHsmKeyManip_KeyWriteData_st.FID_data = l_vHsmKeyManip_flags_U8;
                l_vHsmKeyManip_KeyWriteData_st.WrPayloadPtr = (uint8 *)&l_vHsmKeyManipNewKey_U8A[0];

                /* updating the key to the RAM in critically safe environment
                to avoid any corruption to RAM buffer formed */           
                fl_retVal = vHsmKeyMan_KeyUpdate(&l_vHsmKeyManip_KeyWriteData_st, l_UIDZeroFlag_U8);
                if(E_OK == fl_retVal)
                {
                    l_vHsmKeyManip_SM_U8 = KEY_WRITE_WAIT_FOR_RESULT;
                }
                else
                {
                    /* Update the negative result to M7 */
                    vHsmKeyMan_UpdateFault();
                }
            }
            // vHsmMcu_ExitCriticalSection();             
            break;
        case KEY_WRITE_WAIT_FOR_RESULT:
            // vHsmMcu_EnterCriticalSection();        
            fl_retValWriteChk_e = vHsmKeyMan_ResultCheck();
            if(WRITE_PENDING_STATE != fl_retValWriteChk_e)
            {
                /* Result is available to be sent to M7 */
                if(WRITE_OK == fl_retValWriteChk_e)
                {
                    fl_priodic_res_U8 = (uint8)CRYPTO_JOB_DONE;
                }
                else
                {
                    fl_priodic_res_U8 = (uint8)CRYPTO_JOB_NOT_DONE; /* negative result update */
                }
                l_cryptodatasend_st.jobId_E = CID_61_SYM_EXTRACT_CB;
                l_cryptodatasend_st.KeyId_U8 = 0u;
                l_cryptodatasend_st.priority_U8 = e_priorityunused;
#ifdef M4_M5_GENERATION_REQ
                l_vHsmKeyManip_M4M5_U8A[0]=fl_priodic_res_U8;
                (void)memcpy(&l_vHsmKeyManip_M4M5_U8A[1],&l_vHsmKeyManip_M4_U8A[0],cByte32);
                (void)memcpy(&l_vHsmKeyManip_M4M5_U8A[cByte32+1U],&l_vHsmKeyManip_M5_U8A[0],cByte16);
                l_cryptodatasend_st.payLoadPtr_U8P = &l_vHsmKeyManip_M4M5_U8A[0];
                l_cryptodatasend_st.payLoadSize = (uint16)49u;
#endif
                l_cryptodatasend_st.payLoadPtr_U8P = &fl_priodic_res_U8;
                l_cryptodatasend_st.payLoadSize = (uint16)1;                      
                fl_retVal = vHsmCrypto_Manager_SendData(l_cryptodatasend_st);
                if(E_NOT_OK == fl_retVal)
                {
                    /* Message not sent through IPC */
                    /* TBD */
                }
                else
                {
                    /* Data sent through IPC */
                }
                l_vHsmKeyManip_SM_U8 = DECRYPT_LOGIC_IDLE;
            }
            // vHsmMcu_ExitCriticalSection();             
            break;
        case ECC_KEY_WRITE_RESULT_CHECK:
            // vHsmMcu_EnterCriticalSection();
            fl_retValWriteChk_e = vHsmKeyMan_ResultCheck();
            if(WRITE_PENDING_STATE != fl_retValWriteChk_e)
            {
                /* Result is available to be sent to M7 */
                if(WRITE_OK == fl_retValWriteChk_e)
                {
                    fl_priodic_res_U8 = (uint8)CRYPTO_JOB_DONE;
                }
                else
                {
                    fl_priodic_res_U8 = (uint8)CRYPTO_JOB_NOT_DONE; /* negative result update */
                }
                l_cryptodatasend_st.jobId_E = CID_92_SET_ECDSA_KEY_CB;
                l_cryptodatasend_st.KeyId_U8 = 0u;
                l_cryptodatasend_st.priority_U8 = e_priorityunused;
                l_cryptodatasend_st.payLoadPtr_U8P = &fl_priodic_res_U8;
                l_cryptodatasend_st.payLoadSize = (uint16)(1);
                fl_retVal = vHsmCrypto_Manager_SendData(l_cryptodatasend_st);
                if(E_NOT_OK == fl_retVal)
                {
                    /* Message not sent through IPC */
                    /* TBD */
                }
                else
                {
                    /* Data sent through IPC */
                }
                l_vHsmKeyManip_SM_U8 = DECRYPT_LOGIC_IDLE;
            }
            // vHsmMcu_ExitCriticalSection();
            break;        
        case KEY_UPDATE:    
            // vHsmMcu_EnterCriticalSection();
                 l_KeyWrite_St.AlgoId = AES_128;
                 l_KeyWrite_St.KeyId = l_keyID_U32;
                 l_KeyWrite_St.AuthId = 1;
                 l_KeyWrite_St.Counter = 0x01;
                 l_KeyWrite_St.FID_data = 0;
                 l_KeyWrite_St.WrPayloadPtr = &l_vHsmKeyManip_KeyStore16Byte_U8A[0];
                 fl_retVal= vHsmKeyMan_KeyUpdate(&l_KeyWrite_St,(uint8)0);
                 if(E_OK == fl_retVal)
                  {
                    l_vHsmKeyManip_SM_U8 = KEY_WRITE_WAIT_FOR_RESULT;
                  }
                 else
                  {
                    /* Update the negative result to M7 */
                    vHsmKeyMan_UpdateFault();
                   }
            // vHsmMcu_ExitCriticalSection();
            break;  
        default:
        	/* do nothing*/
            break;
    }
}
//----------------------------------------------------------------------------------------------------------------------
///@brief   Derrive Key based on Constant
//----------------------------------------------------------------------------------------------------------------------
LOCAL FUNC (Std_ReturnType, CRY_CODE) vHsmKeyMan_ManipDeriveKey (
                                         const uint8 * const pu8KeyP,
                                         const uint8 * const pu8ConstantP,
                                         uint8 * const pu8OutDataP
                                        )
{
    uint8 u8IndexL;
    Std_ReturnType fl_ret = E_NOT_OK;
    switch(l_vHsmKeyManipKeyDerive_SM_U8)
    {
    case KEY_DERIVATION_STATE_IDLE:
        l_vHsmKeyManipKeyDerive_SM_U8 = KEY_DERIVATION_STATE_ENCRYPT1;
        (void)memset(pu8OutDataP, 0x00, (size_t)cByte16); // buffer init
        (void)memset(&l_vHsmKeyManip_Key_U8A[0], 0x00, (size_t)cByte16); // Key init
        break;
    case KEY_DERIVATION_STATE_ENCRYPT1:
        //encrypt based on authid key
        vHsmCrypt_SetInternalContext();  
        fl_ret = vHsmCrypt_AesEcbEncrypt(&l_vHsmKeyManip_Key_U8A[0],
                cByte16,
                pu8KeyP,cByte16,
                l_vHsmKeyManip_DerivationBuffer_U8A, &decryptsize);
        vHsmCrypt_ClrtInternalContext();
        if (E_OK == fl_ret)
        {
            for(u8IndexL=(uint8)0;u8IndexL<(uint8)16;u8IndexL++) // Miyaguchi-Preneel: Xor
            {
                l_vHsmKeyManip_DerivationBuffer_U8A[u8IndexL] = l_vHsmKeyManip_DerivationBuffer_U8A[u8IndexL]^pu8KeyP[u8IndexL];
                pu8OutDataP[u8IndexL]=pu8OutDataP[u8IndexL]^l_vHsmKeyManip_DerivationBuffer_U8A[u8IndexL];
            }
            l_vHsmKeyManipKeyDerive_SM_U8 = KEY_DERIVATION_STATE_ENCRYPT2;
        }
        else
        {
            l_vHsmKeyManipKeyDerive_SM_U8 = KEY_DERIVATION_STATE_COMPLETED;
        }
        break;
    case KEY_DERIVATION_STATE_ENCRYPT2:
        //load constant key to RAM_KEY
        (void)memcpy(&l_vHsmKeyManip_Key_U8A[0], pu8OutDataP, cByte16);
        //encrypt based on constant key
        vHsmCrypt_SetInternalContext();  
        fl_ret = vHsmCrypt_AesEcbEncrypt(&l_vHsmKeyManip_Key_U8A[0],
                cByte16,
                pu8ConstantP,cByte16,
                l_vHsmKeyManip_DerivationBuffer_U8A, & decryptsize);
        vHsmCrypt_ClrtInternalContext();
        if(E_OK == fl_ret)
        {
            for(u8IndexL=(uint8)0;u8IndexL<(uint8)16;u8IndexL++) // Miyaguchi-Preneel: Xor
            {
                l_vHsmKeyManip_DerivationBuffer_U8A[u8IndexL] = l_vHsmKeyManip_DerivationBuffer_U8A[u8IndexL]^pu8ConstantP[u8IndexL];
                pu8OutDataP[u8IndexL]=pu8OutDataP[u8IndexL]^l_vHsmKeyManip_DerivationBuffer_U8A[u8IndexL];
            }
        }
        l_vHsmKeyManipKeyDerive_SM_U8 = KEY_DERIVATION_STATE_COMPLETED;
        break;
    default:
    	/* do nothing */
        break;
    }
    return fl_ret;
}
FUNC (Std_ReturnType, CRY_CODE) vHsmKeyMan_ManipIdleCheck(void)
{
    Std_ReturnType fl_ret_val = E_NOT_OK;
    if (l_vHsmKeyManip_SM_U8 == DECRYPT_LOGIC_IDLE)
    {
        fl_ret_val = E_OK;
    }
    return(fl_ret_val);
}
LOCAL FUNC (void, CRY_CODE) vHsmKeyMan_UpdateFault(void)
{
    static uint8 fl_updfault_res_U8;

    fl_updfault_res_U8 = (uint8)CRYPTO_JOB_NOT_DONE; /* negative result update */
    l_cryptodatasend_st.jobId_E = CID_61_SYM_EXTRACT_CB;
    l_cryptodatasend_st.KeyId_U8 = 0u;
    l_cryptodatasend_st.priority_U8 = e_priorityunused;
    l_cryptodatasend_st.payLoadPtr_U8P = &fl_updfault_res_U8;
    l_cryptodatasend_st.payLoadSize = (uint16)(1);
    (void)vHsmCrypto_Manager_SendData(l_cryptodatasend_st);

    l_vHsmKeyManip_SM_U8 = DECRYPT_LOGIC_IDLE;

}

/**
 ******************************************************************************
 ** \fn vHsmKeyMan_GetM4M5FromRAM
 ** Reads the M4 M5 and returns in the buffer 
 ** This function returns
 ** - E_NOT_OK if the key could not be found in RAM
 ** - E_OK otherwise.
 **
 ** \param [in] KeyId,
 **
 *****************************************************************************/

FUNC (Std_ReturnType, CRY_CODE) vHsmKeyMan_GetM4M5FromRAM(uint32 KeyId, uint8 *keyptr, uint16 keyLength)
{
    Std_ReturnType fl_ret_val_e = E_NOT_OK;
#ifdef M4_M5_GENERATION_REQ    
    if((Maxkey>= KeyId)&&(Minkey<=KeyId)&&(keyptr != NULL))
    {
        (void)memcpy(keyptr,l_vHsmKeyManip_M4_U8A,sizeof(l_vHsmKeyManip_M4_U8A));
        (void)memcpy(keyptr+32,l_vHsmKeyManip_M5_U8A,sizeof(l_vHsmKeyManip_M5_U8A));
        fl_ret_val_e = E_OK;
    }
#endif    
    return(fl_ret_val_e);
}
/**
 ******************************************************************************
 ** \fn vHsmKeyMan_GetM4M5Key
 **
 ** This function is to calculate the m4 and m5 from work flash keyparameter
 **
 ** This function returns None
 **
 ** \param [in] KeyId and pointer to store M4M5 keydata
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRY_CODE)
vHsmKeyMan_GetM4M5Key(uint32 KeyId, uint8 *keydata) // p_Algo_Id_te = 0 AES_128
{
    Std_ReturnType fl_Ret_val_e = E_NOT_OK;
#ifdef M4_M5_GENERATION_REQ
    // uint8 *fl_sheId_AuthId_U8P;
    uint32 fl_sheId_AuthId;
    // uint8 fl_flagVal_U8;
    uint8 *fl_temp_ptr_U8P;
    uint32 fl_SheId;
    uint8 fl_AuthId;
    uint32 fl_counter_U32;
    ts_ReadStructKeyDataType *fl_keyData_st;

    fl_keyData_st = vHsmKeyMan_KeyRead(KeyId, AES_128, 1); // getting the keyparameter and value
    if (fl_keyData_st->ReadPerformed == E_NOT_OK)
    {
        fl_Ret_val_e = E_NOT_OK;
        return (fl_Ret_val_e);
    }
    else
    {
        // fl_flagVal_U8 = (fl_keyData_st->flag_val);
        fl_temp_ptr_U8P = fl_keyData_st->RdPayloadPtr; // knew
        fl_SheId = ((fl_keyData_st->Rd_KeyId) << 4) & (0xf0uL);
        fl_AuthId = (fl_keyData_st->authId) & (0x0fu);
        fl_sheId_AuthId = (fl_SheId | fl_AuthId);
        fl_counter_U32 = fl_keyData_st->counter;
        // fl_sheId_AuthId_U8P = &fl_sheId_AuthId;

        /* Generating M4 = M1 | M*
                      M4 = UID |SHEID | AuthID | M*  */

        /* to get UID */
        fl_keyPtr_U8P = (uint8 *)SFLASH_UID_ADDRESS;
        (void)memcpy(&l_vHsmKeyManDeviceKey_U8A[0], fl_keyPtr_U8P,
                     UID_SIZE);
        /* generating M4 */
        // loading M1
        (void)memset(&l_vHsmKeyManip_M4_U8A[0], 0, sizeof(l_vHsmKeyManip_M4_U8A));
        (void)memcpy(l_vHsmKeyManip_M4_U8A, &l_vHsmKeyManDeviceKey_U8A[0], UID_SIZE);
        (void)memcpy(l_vHsmKeyManip_M4_U8A + UID_SIZE, &fl_sheId_AuthId, 1);

        // finding K3
        (void)memset(&l_vHsmKeyManipThirdDerivationKey_U8A[0], 0,
                     sizeof(l_vHsmKeyManipThirdDerivationKey_U8A));
        l_whileloopCounter = 0;
        l_whileloopCounterExceeded = FALSE;
        while ((KEY_DERIVATION_STATE_COMPLETED != l_vHsmKeyManipKeyDerive_SM_U8) && (l_whileloopCounter < TIMEOUT_THRESHOLD))
        {
            l_whileloopCounter++;
            fl_Ret_val_e = vHsmKeyMan_ManipDeriveKey(fl_temp_ptr_U8P, c_vHsmKeyManipKeyUpdateEncConst_U8A, l_vHsmKeyManipThirdDerivationKey_U8A);
        }
        if (l_whileloopCounter >= TIMEOUT_THRESHOLD)
        {
            l_whileloopCounterExceeded = TRUE;
            vHsmKeyMan_UpdateFault();
            fl_Ret_val_e = E_NOT_OK;
        }
        else
        {
            /* Do nothing */
        }
        if (E_OK == fl_Ret_val_e)
        {

            l_vHsmKeyManipKeyDerive_SM_U8 = KEY_DERIVATION_STATE_IDLE;
        }
        // finding M*

        // Big endian conversion
        plaintext_u8[0] = (fl_counter_U32 & 0xff000000UL) >> 20;
        plaintext_u8[1] = (fl_counter_U32 & 0x00ff0000UL) >> 12;
        plaintext_u8[2] = (fl_counter_U32 & 0x0000ff00UL) >> 4;
        plaintext_u8[3] = (fl_counter_U32 & 0x000000ffUL);
        /* 32 bit to 28 bit CID */
        plaintext_u8[3] = plaintext_u8[3] << 4; // the value correct till the counter value to decimal 15
        plaintext_u8[3] |= (uint8)0x08;         // 29th  bit 1
        (void)memset(plaintext_u8 + cByte4, 0, cByte12);
        fl_Ret_val_e = vHsmCrypt_AesEcbEncrypt(&l_vHsmKeyManipThirdDerivationKey_U8A[0], cByte16,
                                               &plaintext_u8[0], cByte16, &l_vHsmKeyManip_M4_encrypt_U8A[0], &decryptsize);

        (void)memcpy(l_vHsmKeyManip_M4_U8A + cByte16, &l_vHsmKeyManip_M4_encrypt_U8A[0], sizeof(l_vHsmKeyManip_M4_encrypt_U8A)); // M4
        if (E_OK == fl_Ret_val_e)
        {
            (void)memcpy(keydata, &l_vHsmKeyManip_M4_U8A, sizeof(l_vHsmKeyManip_M4_U8A));
            fl_Ret_val_e = E_NOT_OK;
        }
        /* Generating M5
                      M5 = CMACK4 (M4)  */

        // finding K4
        l_whileloopCounter = 0;
        l_whileloopCounterExceeded = FALSE;
        while ((KEY_DERIVATION_STATE_COMPLETED != l_vHsmKeyManipKeyDerive_SM_U8) && (l_whileloopCounter < TIMEOUT_THRESHOLD))
        {
            l_whileloopCounter++;
            fl_Ret_val_e = vHsmKeyMan_ManipDeriveKey(fl_keyData_st->RdPayloadPtr, c_vHsmKeyManipKeyUpdateMacConst_U8A, l_vHsmKeyManipFourthDerivationKey_U8A);
        }
        if (l_whileloopCounter >= TIMEOUT_THRESHOLD)
        {
            l_whileloopCounterExceeded = TRUE;
            vHsmKeyMan_UpdateFault();
            fl_Ret_val_e = E_NOT_OK;
        }
        else
        {
            /* Do nothing */
        }
        if (E_OK == fl_Ret_val_e)
        {
            l_vHsmKeyManipKeyDerive_SM_U8 = KEY_DERIVATION_STATE_IDLE;
        }

        /*   CMAC K4 (M4)     */
            fl_Ret_val_e = vHsmCrypt_AesCmacGenerate(&l_vHsmKeyManip_aesCmacDerKey_M5, cByte16, &l_vHsmKeyManip_M4_U8A[0], (uint32)cByte32,
                                                     &l_vHsmKeyManip_M5_U8A[0], (uint32)cByte16);
            if (E_OK == fl_Ret_val_e)
            {
                (void)memcpy(keydata + cByte32, &l_vHsmKeyManip_M5_U8A, cByte16);
            }
    }
#endif
    return (fl_Ret_val_e);
}

FUNC (Std_ReturnType, CRY_CODE) vHsmKeyMan_SymKeyWrapSym(const uint8 *keyBuffer_P8, uint16 payload_size)
{
    Std_ReturnType fl_ret_val_e = E_NOT_OK;

    (void)memcpy(&l_vHsmKeyMan_plainKey_U8[0],keyBuffer_P8,payload_size);
    if ((ENCRYPT_LOGIC_IDLE == l_vHsmKeyManipSymKeyWrap_SM_U8) && (keyBuffer_P8 != NULL))
    {
        (void)memcpy(l_vHsmKeyManExtEncKeys_U8, c_vHsmKeyManipKeyUpdateEncConst_U8A, 
            sizeof(c_vHsmKeyManipKeyUpdateEncConst_U8A));
        (void)memcpy(l_vHsmKeyManExtMacKeys_U8, c_vHsmKeyManipKeyUpdateMacConst_U8A, 
            sizeof(c_vHsmKeyManipKeyUpdateMacConst_U8A));
        l_vHsmKeyManipSymKeyWrap_SM_U8 = M1_GENERATION_STATE_IDLE;
        fl_ret_val_e = E_OK;
        l_whileloopCounter = 0;
        l_whileloopCounterExceeded = FALSE;
        while((l_vHsmKeyManipSymKeyWrap_SM_U8 != ENCRYPT_LOGIC_IDLE) && (l_whileloopCounter < TIMEOUT_THRESHOLD))
        {
            l_whileloopCounter++;
            vHsmKeyMan_SymKeyWrapPeriodic();
        }
        if (l_whileloopCounter >= TIMEOUT_THRESHOLD)
        {
            l_whileloopCounterExceeded = TRUE;
            vHsmKeyMan_UpdateFault();
        }
        else
        {
            /* Do nothing */
        }
    }
    else
    {
        /* do nothing*/
    }
    return fl_ret_val_e;
}

FUNC(Std_ReturnType, CRY_CODE)vHsmKeyman_ManipGenerate_M1(uint8 new_key_index, uint8 auth_key_index, uint8* M1)
{	
	Std_ReturnType fl_Ret_val_e = E_OK;
	fl_UID_U8P = (uint8 *)SFLASH_UID_ADDRESS;
    (void)memset(&M1[0], 0,UID_SIZE);
	uint8 last_byte = (new_key_index << 4U) | auth_key_index;
	(void)memcpy(&M1[UID_SIZE], &last_byte, 1);
	return fl_Ret_val_e;
}

FUNC(Std_ReturnType, CRY_CODE)vHsmKeyman_ManipGenerate_M2(uint32 CID, uint8 FID, uint8 * new_key, uint8 * M2)
{	
	Std_ReturnType fl_Ret_val_e = E_NOT_OK;
    if (( CID <= 0x0fffffffu ) && ( FID <= 0x1fu ))
    {
	    l_vHsmKeyManip_Wrap_M2_plain_U8A[0] = CID >> 20 & 0xff;
	    l_vHsmKeyManip_Wrap_M2_plain_U8A[1] = CID >> 12 & 0xff;
	    l_vHsmKeyManip_Wrap_M2_plain_U8A[2] = CID >> 4 & 0xff;
	    l_vHsmKeyManip_Wrap_M2_plain_U8A[3] = (CID << 4 & 0xf0) | (FID >> 2 & 0x0f);
	    l_vHsmKeyManip_Wrap_M2_plain_U8A[4] = FID << 6 & 0xc0;
    
	    (void)memcpy(&l_vHsmKeyManip_Wrap_M2_plain_U8A[M2_INPUT_KEY_OFFSET], new_key, KEY_LENGTH);
        fl_Ret_val_e = E_OK;
    }
	return fl_Ret_val_e;
}

FUNC(Std_ReturnType, CRY_CODE)vHsmKeyman_ManipGenerate_M3(uint8 * M1, uint8 * M2)
{	
	Std_ReturnType fl_Ret_val_e = E_OK;

	(void)memcpy(&l_vHsmKeyManip_Wrap_M1M2_U8A[0],M1,M1_LENGTH);
	(void)memcpy(&l_vHsmKeyManip_Wrap_M1M2_U8A[M3_INPUT_M2_OFFSET],M2,M2_LENGTH);
	return fl_Ret_val_e;
}

/**
******************************************************************************
 ** \fn vHsmKeyMan_SymKeyWrapPeriodic
 **
 ** Conversion of plain key to M1, M2, M3 in periodic call
 **
 ** This function returns void
 **
 ** \param [in] NONE
 **
 *****************************************************************************/
FUNC (void, CRY_CODE) vHsmKeyMan_SymKeyWrapPeriodic(void)
{
    Std_ReturnType fl_retVal = E_NOT_OK;
    
    switch(l_vHsmKeyManipSymKeyWrap_SM_U8)
    {
        case ENCRYPT_LOGIC_IDLE:
            /* Do nothing */
            break;
        case M1_GENERATION_STATE_IDLE:
            // vHsmMcu_EnterCriticalSection();

            /*Generate M1*/
            (void)vHsmKeyman_ManipGenerate_M1(newkey_index_U8, authkey_index_U8, l_vHsmKeyMan_Wrap_M1_U8A);
            l_vHsmKeyManipSymKeyWrap_SM_U8 = M2_GENERATION_STATE_IDLE;
            // vHsmMcu_ExitCriticalSection();

            break;
        case M2_GENERATION_STATE_IDLE:
            // vHsmMcu_EnterCriticalSection();

            /*Generate M2 plain string*/
            (void)vHsmKeyman_ManipGenerate_M2(CID_counter_U8,FID_flag_U8,(uint8 *)l_vHsmKeyMan_plainKey_U8,
                                                    l_vHsmKeyMan_Wrap_M2_U8A);
            l_vHsmKeyManipSymKeyWrap_SM_U8 = M2_GENERATION_STATE_LOAD_KEY;
            // vHsmMcu_ExitCriticalSection();

            break;
        case M2_GENERATION_STATE_LOAD_KEY:
            /*Generate K1*/
            // vHsmMcu_EnterCriticalSection();
            l_whileloopCounter = 0;
            l_whileloopCounterExceeded = FALSE;
            while((KEY_DERIVATION_STATE_COMPLETED !=  l_vHsmKeyManipKeyDerive_SM_U8) && (l_whileloopCounter < TIMEOUT_THRESHOLD))
            {
                l_whileloopCounter++;
                fl_retVal = vHsmKeyMan_ManipDeriveKey(l_vHsmKeyMan_Wrap_AuthKeyData_U8A, l_vHsmKeyManExtEncKeys_U8, 
                                                      l_vHsmKeyMan_Wrap_FirstDerivationKey_U8A);
            }
            if (l_whileloopCounter >= TIMEOUT_THRESHOLD)
            {
                l_whileloopCounterExceeded = TRUE;
                vHsmKeyMan_UpdateFault();
                fl_retVal = E_NOT_OK;
            }
            else
            {
                /* Do nothing */
            }
            if(E_OK == fl_retVal)
            {
                l_vHsmKeyManipKeyDerive_SM_U8 = KEY_DERIVATION_STATE_IDLE;
                l_vHsmKeyManipSymKeyWrap_SM_U8 = M2_GENERATION_STATE_ENCRYPT;
            }
            else
            {
                vHsmKeyMan_UpdateFault();
            }
            // vHsmMcu_ExitCriticalSection();
            break;
        case M2_GENERATION_STATE_ENCRYPT:
            // vHsmMcu_EnterCriticalSection();

            /*Encrypt AES128 CBC the plain text using Derived key to get M2*/
            fl_retVal = vHsmCrypt_AesEcbEncrypt(&l_vHsmKeyMan_Wrap_FirstDerivationKey_U8A[0],cByte16, 
                                              &l_vHsmKeyManip_Wrap_M2_plain_U8A[0] ,(uint32)M2_LENGTH,
                                              &l_vHsmKeyMan_Wrap_M2_U8A[0], &decryptsize);
            if (E_OK == fl_retVal)
            {
                l_vHsmKeyManipSymKeyWrap_SM_U8 = M3_GENERATION_STATE_IDLE;
            }
            else
            {
                vHsmKeyMan_UpdateFault();
            }
            // vHsmMcu_ExitCriticalSection();

            break;
        case M3_GENERATION_STATE_IDLE:
            // vHsmMcu_EnterCriticalSection();

            /*Combine M1 and M2 for M3 generation*/
            (void)vHsmKeyman_ManipGenerate_M3(l_vHsmKeyMan_Wrap_M1_U8A, l_vHsmKeyMan_Wrap_M2_U8A);
            l_vHsmKeyManipSymKeyWrap_SM_U8 = M3_GENERATION_STATE_LOAD_KEY;
            // vHsmMcu_ExitCriticalSection();

            break;
        case M3_GENERATION_STATE_LOAD_KEY:
            /*Derive Key 2 for MAC*/
            // vHsmMcu_EnterCriticalSection();
            l_whileloopCounter = 0;
            l_whileloopCounterExceeded = FALSE;
            while((KEY_DERIVATION_STATE_COMPLETED !=  l_vHsmKeyManipKeyDerive_SM_U8)  && (l_whileloopCounter < TIMEOUT_THRESHOLD))
            {
                l_whileloopCounter++;
                fl_retVal = vHsmKeyMan_ManipDeriveKey(l_vHsmKeyMan_Wrap_AuthKeyData_U8A, l_vHsmKeyManExtMacKeys_U8, 
                                                      l_vHsmKeyMan_Wrap_SecondDerivationKey_U8A);
            }
            if (l_whileloopCounter >= TIMEOUT_THRESHOLD)
            {
                l_whileloopCounterExceeded = TRUE;
                vHsmKeyMan_UpdateFault();
                fl_retVal = E_NOT_OK;
            }
            else
            {
                /* Do nothing */
            }
            if(E_OK == fl_retVal)
            {
                l_vHsmKeyManipKeyDerive_SM_U8 = KEY_DERIVATION_STATE_IDLE;
                l_vHsmKeyManipSymKeyWrap_SM_U8 = M3_GENERATION_STATE_GENERATE_MAC;
            }
            else
            {
                vHsmKeyMan_UpdateFault();
            }
            // vHsmMcu_ExitCriticalSection();
            break;
        case M3_GENERATION_STATE_GENERATE_MAC:
            /*Generate MAC using Derived key2 for M1,M2 combined data*/
            // vHsmMcu_EnterCriticalSection();            
                fl_retVal = vHsmCrypt_AesCmacGenerate(&l_vHsmKeyManWrap_aesCmacDerKey_M3, cByte16, &l_vHsmKeyManip_Wrap_M1M2_U8A[0],(uint32)cByte48, &l_vHsmKeyMan_Wrap_M3_U8A[0],(uint32)cByte16);
                if(E_OK == fl_retVal)
                {
                    l_vHsmKeyManipSymKeyWrap_SM_U8 = M1_M2_M3_COMBINE;
                }
                else
                {                      
                    vHsmKeyMan_UpdateFault();
                }
            // vHsmMcu_ExitCriticalSection();                
                break;
            case M1_M2_M3_COMBINE:
            /*Combine M1, M2, M3 and export*/
            // vHsmMcu_EnterCriticalSection();            
            (void)memcpy((void *)&l_vHsmKeyManip_Wrap_M1M2M3_U8A[1], (const void *)&l_vHsmKeyMan_Wrap_M1_U8A,M1_LENGTH);
            (void)memcpy((void *)&l_vHsmKeyManip_Wrap_M1M2M3_U8A[M1_LENGTH + 1],(const void *)&l_vHsmKeyMan_Wrap_M2_U8A,M2_LENGTH);
            (void)memcpy((void *)&l_vHsmKeyManip_Wrap_M1M2M3_U8A[M1_LENGTH + M2_LENGTH + 1],(const void *)&l_vHsmKeyMan_Wrap_M3_U8A,M3_LENGTH);
            
            l_vHsmKeyManip_Wrap_M1M2M3_U8A[0] = (uint8)CRYPTO_JOB_DONE;

            l_cryptodatasend_st.jobId_E = CID_93_SYM_WRAPKEY_CB;

            l_cryptodatasend_st.KeyId_U8 = 0u;
            l_cryptodatasend_st.priority_U8 = e_priorityunused;
            l_cryptodatasend_st.payLoadPtr_U8P = &l_vHsmKeyManip_Wrap_M1M2M3_U8A[0];
            l_cryptodatasend_st.payLoadSize = (uint16)(65);
            fl_retVal = vHsmCrypto_Manager_SendData(l_cryptodatasend_st);
            if(E_NOT_OK == fl_retVal)
            {
                /* Message not sent through IPC */
                /* TBD */
            }
            else
            {
                /* Data sent through IPC */
            }
            l_vHsmKeyManipSymKeyWrap_SM_U8 = ENCRYPT_LOGIC_IDLE;
            // vHsmMcu_ExitCriticalSection();            
            break;
        default:
            /*Do Nothing*/
            break;
    }
    (void)l_whileloopCounterExceeded;
}


/*****************************************************************************
 Coverity violations and justifications
 *****************************************************************************/
/* module specific Coverity deviations:
 *
 * 1. sensitive_memory_access
 * Reason:     Memory leak due to speculative execution. CM0 plus processor does not support Speculative execution.
 *             CM0 plus has only two stage pipelining with in-order execution. So no need of lfence barrier.
 * Risk:       No functional risk.
 * Prevention: Not required.
 * Reference:  Arm Cortex-M0+ Processor Datasheet Page No:5
 */


/*****************************************************************************
Date              :04/Jan/2021
By                :bjayara2
Traceability      : 1170811: [VW FPK8] HSM: conversion logics for
M1, M2 and M3 to plain key
Change Description: Key storage implementation
 ******************************************************************************/
/* [] END OF FILE */
