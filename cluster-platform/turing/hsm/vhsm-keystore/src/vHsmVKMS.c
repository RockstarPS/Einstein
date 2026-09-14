/***************************************************************************
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2026] Visteon Corporation
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
 * \file vHsmVKMS.c
 *
 * \brief
 * Visteon HSM VKMS source file
 *
 * This file shall be the VKMS key storage algorithms for TI AM62Px
 *
 * \version 1.0.0
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 | 19/May/'26 | Kjohn    |         |      Initial version                  |

 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Krithik B John           | kjohn     | VTSC, Bengaluru, India
 *          Vetcha Sree Divya        | svetcha   | VTSC, Bengaluru, India
 ******************************************************************************/


/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "vHsmVKMS.h"
#include "vHsmVKMS_Cfg.h"
#include "Std_Types.h"
#include "string.h"
#include "vHsmCrypt.h"
#include "vHsmCryptoManager.h"
#include "Fls.h"
#include "config.h"


#ifdef VKMS_DEBUG
#include "trace.h"
#endif

#if (VKMS_ENABLED == STD_ON)
/******************************************************************************
 *  MACROS
 *****************************************************************************/
#ifndef LOCAL
#define LOCAL static
#endif

#ifdef VKMS_DEBUG
#define VKMS_print(fmt) TRACE_info(fmt)
#define VKMS_printarg(fmt,arg) TRACE_info_arg_hsm(fmt,arg)
#else
#define VKMS_print(fmt) (void)
#define VKMS_printarg(fmt,arg) (void)
#endif

/*Compilation Macros for Misra*/
#define BYTEFF 0xFFu
#define BYTE0   (0U)
#define BYTE1   (1U)
#define BYTE2   (2U)
#define BYTE3   (3U)
#define BYTE4   (4U)
#define BYTE5   (5U)
#define BYTE6   (6U)
#define BYTE7   (7U)
#define BYTE8   (8U)
#define BYTE9   (9U)
#define BYTE10  (10U)
#define BYTE11  (11U)
#define BYTE12  (12U)
#define BYTE13  (13U)
#define BYTE14  (14U)
#define BYTE15  (15U)
#define BYTE16  (16U)
#define BYTE17  (17U)
#define BYTE18  (18U)
#define BYTE19  (19U)
#define BYTE20  (20U)

typedef enum
{
    e_VKMS_Idle         = 0,
    e_VKMS_Start        = 1,
    e_VKMS_Start_Finish = 2,
    e_VKMS_Finish       = 3,
    e_VKMS_WORK         = 4,
} te_VKMS_StateType;


typedef struct
{
    uint16 KeyId_U16;         /* Key Id */
    uint16 KeySize_U16;       /* Key size */
    uint8  KeyIntId;          /* Internal KeyID*/
    uint16 KeyconfSize;       /* Actul key Size*/
}ts_VKMSKeysConfig_st;

typedef struct
{
    uint8   DLCversion_U8;                   /* DLC version */
    uint8   InitVector_U8A[INIT_VECTOR_LENGTH]; /* Init Vector */
    uint16  EcuTrainingCounter_U16;          /* Ecu training counter*/
    uint8   EcuGrpVIN_U8A[VIN_OF_VKMS_LENGTH];   /* VIN of VKMS group */
    uint8   MasterKeyGrpId_U8A[MASTER_KEY_LENGTH];  /* Master key group Id */
    uint16  IdentityCounter_U16;             /* Identity counter */
    uint8   DLCVerificationChksum_U8A[DLC_VER_CHKSUM_LENGTH];   /* DLC verification chksum */
    uint8   NumberOfKeys_U8;      
}ts_VKMSDLCDataType_st;


typedef struct
{
    uint16 KeyTypeId_U16;                   /* Key type Id*/
    uint16 TypeTrainingCounter_U16;        /* Type training counter */
    uint8  KeyGenus_U8;                     /* Key Genus*/
    uint8  KeyFlags_U8;                     /* flags data to be written */
    uint16 KeyLength_U16;                   /* Key Length */
    uint8* Key_Payload_U8P;                 /* Pointer to key payload*/
    /* true - KeyId is located in read context */
    /* false - KeyId is not located in read context */      
    boolean KeyIdLocated_bool;
}ts_VKMSKeyDataType_st;

typedef struct
{
    uint16 KeyTypeId_U16; /* Key type Id*/
    uint16 TypeTrainingCounter_U16; /* Type training counter */
    uint8  KeyGenus_U8; /* Key Genus*/
    uint8  KeyFlags_U8; /* flags data to be written */
    uint16 KeyLength_U16; /* Key Length */
    uint8* Key_Payload_U8P; /* Pointer to key payload*/
    uint8  Key_EcuDeri_U8;
} ts_VKMSKeyData_st;

typedef struct 
{
    uint16 KeyTypeId_U16; /* Key type Id*/
    uint16 TypeTrainingCounter_U16; /* Type training counter */
    uint8  KeyGenus_U8; /* Key Genus*/
    uint8  KeyFlags_U8; /* flags data to be written */
    uint16 KeyLength_U16; /* Key Length */
    uint8  Key_Payload_U8[32]; /*key payload*/
} ts_VKMSKey_st;

typedef struct 
{
    uint32 KeyMarker;
    uint8  KeyValid;
    ts_VKMSKey_st key;
    uint8  keyTag[4];
}ts_VKMSKeySlot_st;

typedef struct 
{
    uint32 KeyHeader;
    ts_VKMSKeySlot_st VKMSKeys_st[MAX_CONFIGURED_KEYS];
    uint8 Reserved[84]; /*To make 256 bytes aligned*/
    uint32 KeyFooter;
}ts_VKMSKeysBuffer_st;


typedef struct
{
    uint32 DLCCounter;
    uint8 DLCValid;
    ts_VKMSDLCDataType_st DLCData;
    uint8 DLCTag[4];
    uint8 reserved[184];
    uint32 DLCMarker;
}ts_VKMSDlcSlot_st;


typedef enum
{
    HSM_VKMS_IDLE = 0,
    HSM_VKMS_SET_KEY,
    HSM_VKMS_SET_KEY_RESULT_CHECK,
    HSM_VKMS_SET_DLC,
    HSM_VKMS_SET_DLC_RESULT_CHECK,
    HSM_VKMS_CKSUM_VERIFY,
    HSM_VKMS_CKSUM_VERIFY_RESULT_CHECK,
    HSM_VKMS_PSS_RESULT_CHECK,
    HSM_VKMS_CKSUM_VERIFY_FAIL_CHECK,
    HSM_VKMS_CKSUM_FAIL_KEYSET,
    HSM_VKMS_CKSUM_FAIL_DLCSET,
    HSM_VKMS_CKSUM_FAIL_DLCSET_RESULT_CHECK
} te_vkmsFinishStateMachineType;

/******************************************************************************
 *  LOCAL VARIABLES DEFINITIONS
 *****************************************************************************/
LOCAL te_VKMS_StateType             CurrentVKMSState_U8                       = e_VKMS_Idle;
LOCAL uint8                         l_DLCDecrypted_U8A[MAX_BUFF_SIZE]         = {0};
LOCAL uint8                         l_DLCKeyData_U8A[MAX_BUFF_SIZE]           = {0};
LOCAL uint8                         l_currentDlcdata[DLC_METADATA_LEN]        = {0};
LOCAL uint8                         l_changedkeylist[MAX_KEYLIST_LEN]         = {0};
LOCAL uint8                         l_hashptr_U8A[MAX_VKMS_HASHLEN]           = {0};
LOCAL uint8                         l_hashdump_U8A[MAX_VKMS_HASHLEN]          = {0};
LOCAL uint8                         l_hashtmp_U8A[MAX_VKMS_HASHLEN]           = {0};
LOCAL uint8                         l_DlcHash_U8A[MAX_VKMS_HASHLEN]           = {0};
LOCAL uint8                         l_keyhash_U8A[MAX_VKMS_HASHLEN]           = {0};
LOCAL uint16                        l_keychangedLen                           = 0u;
LOCAL uint8                         l_ResetDLCFlag_U8                         = 0u;
LOCAL uint8                         l_ResetFlag_U8                            = 0u;
LOCAL ts_VKMSDLCDataType_st         l_CurrentDLC_st;
LOCAL ts_VKMSDLCDataType_st *       l_StoredDLC_st;
LOCAL ts_VKMSKeyData_st             l_currentKey_st;
LOCAL ts_VKMSKey_st                 l_StoreKey_St;
LOCAL ts_VKMSKeyDataType_st*        l_parentKey_St;
LOCAL uint16                        l_currentKeylen = 0u;
LOCAL ts_VKMSKey_st                 l_vHsmVKMSStoreKeys_stA[MAX_CONFIGURED_KEYS];
LOCAL uint16                        l_StoreKeysCounter_U16 = 0u;
LOCAL ts_VKMSKeysConfig_st          l_vHsmVKMSKeyConfigArray_stA[MAX_CONFIGURED_KEYS] = {VKMS_KEYS_CONFIG};
LOCAL uint8                         l_vHsmVMMSmissingKeyFlag_U8 = 0u;
LOCAL uint8                         l_signin_U8A[VKMS_DEBUGSIGN_SIZE] = {0};
LOCAL te_VKMS_ProvisionStateType    l_vHsmVKMSProvisionState_e;
LOCAL ts_VKMSKeyDataType_st         l_vHsmLocalKey_st = {0};
LOCAL ts_VKMSKeyDataType_st         l_vHsmParentKey_st = {0};
LOCAL ts_VKMSDLCDataType_st         l_VKMS_DLC_Rd_Auth_st = {0};
LOCAL uint8                         l_LocalKeyBuffer_U8A[KEYLEN_256] = {0};

/*KeyStorage Variables*/
LOCAL ts_VKMSDlcSlot_st             l_vHsmVKMSDlcSlot_ts = {0};
LOCAL ts_VKMSKeysBuffer_st          l_vHsmVKMSKeyFlash_ts;


/******************************************************************************
 *  LOCAL FUNCTION DECLARATIONS
 *****************************************************************************/
LOCAL te_VKMS_ErrorType HSM_VKMS_DLChash(uint8* p_DlcHashPtr_pU8);
LOCAL te_VKMS_ErrorType HSM_VKMS_Keyhash(uint8* p_HashPtr_pU8);
LOCAL te_VKMS_ErrorType SearchKeyId(uint16 p_KeyId_U16, uint16 p_Keylen_U16);
LOCAL te_VKMS_ErrorType HSM_VKMS_decryptDlcKeys(const uint8* p_keystart_pU8, const uint16 p_keysLen_U16);
LOCAL te_VKMS_ErrorType DeriveStoreKey(void);
LOCAL Std_ReturnType SearchForPss(void);
LOCAL Std_ReturnType ResetDlcCheck(void);
LOCAL uint32 HSM_VKMS_KEY_DLCLEN(uint8 p_NoofKeys_U8);
LOCAL te_VKMS_ErrorType HSM_VKMS_getVerificationHashRam(void);
LOCAL te_VKMS_ErrorType HSM_VKMS_DLChashRam(uint8* p_DlcHashPtr_pU8);
LOCAL te_VKMS_ErrorType HSM_VKMS_KeyhashRam(uint8* p_HashPtr_pU8);
LOCAL te_VKMS_ErrorType vHsmVKMS_SetSkippedKey(const uint16 KeyID);
LOCAL ts_VKMSKeyDataType_st * vHsmVKMS_GetParent(uint16 keyID,Std_ReturnType *p_recPresent_Ptr);
LOCAL te_VKMS_ErrorType Set_VKMSKeys(void);
LOCAL te_VKMS_ErrorType Set_VKMSDLC(void);
LOCAL te_VKMS_ErrorType vHsmVKMS_Validate(void);
LOCAL uint8 vHsmVKMSKEYMAP(const uint16 KeyId);
LOCAL ts_VKMSDLCDataType_st * vHsmVKMS_GetDLC(void);
LOCAL ts_VKMSKeyDataType_st * vHsmVKMS_GetKey(uint16 KeyId, Std_ReturnType *p_recPresent_Ptr);
LOCAL uint8 ResetNormalDLC(void);
LOCAL void vHsmVKMSKeySectorInit(void);
#ifdef VKMS_DEBUG
LOCAL const u8 * VKMS_ErrToString(te_VKMS_ErrorType errCode);
LOCAL const u8 * VKMS_ProvToString(te_VKMS_ProvisionStateType provCode);
#endif


/******************************************************************************
 *  LOCAL FUNCTION DEFINITIONS
 *****************************************************************************/

/**
 * @brief Maps a VKMS KeyId to its internal key index.
 *
 * Iterates through the configured key array looking for a matching KeyId.
 * Returns the corresponding internal key identifier (KeyIntId) if found,
 * otherwise returns VKMS_INVALID_KEYINDEX.
 *
 * @param[in] KeyId   The VKMS key ID to map.
 *
 * @return Internal key index (KeyIntId) on success, VKMS_INVALID_KEYINDEX if not found.
 */
LOCAL FUNC(uint8,VKMS_CODE) vHsmVKMSKEYMAP(const uint16 KeyId)
{
    uint8 keyIndex = 0u;
    uint8 keyIndexId = VKMS_INVALID_KEYINDEX;
    for(keyIndex = 0u;keyIndex <MAX_CONFIGURED_KEYS;keyIndex++)
    {
        if(KeyId == l_vHsmVKMSKeyConfigArray_stA[keyIndex].KeyId_U16)
        {
            keyIndexId = l_vHsmVKMSKeyConfigArray_stA[keyIndex].KeyIntId;
            break;
        }
    }
    return keyIndexId;
}

/**
 * @brief Initialises the VKMS Key sector.
 *
 * Selects Active sector and Gives VKMS Provision State:
 *  - e_VKMS_NotProvisioned     if DLC is not Provisioned.
 *  - e_VKMS_Provisioned_Normal if DLC tag and key validation pass.
 *  - e_VKMS_Provisioned_Reset  if DLC is valid but Reset DLC is present.
 *  - e_VKMS_Provisioned_Limited if DLC or key data are corrupted/unreadable.
 *
 * @return None
 */
LOCAL FUNC(void, VKMS_CODE) vHsmVKMSKeySectorInit(void)
{
    /*check which setor has Valid address*/
    uint32 Sector1Header_U32 = 0u;
    uint32 Sector1Footer_U32 = 0u;
    uint32 Sector2Header_U32 = 0u;
    uint32 Sector2Footer_U32 = 0u;
    uint32 ActiveSector_U32 = KEY_STORAGE_ADDRESS;
    (void)Fls_Read(KEY_STORAGE_ADDRESS,(uint8*)&Sector1Header_U32,4u);
    (void)Fls_Read(KEY_STORAGE_FOOTER,(uint8*)&Sector1Footer_U32,4u);
    (void)Fls_Read(KEY_STORAGE1_ADDRESS,(uint8*)&Sector1Header_U32,4u);
    (void)Fls_Read(KEY_STORAGE1_FOOTER,(uint8*)&Sector1Footer_U32,4u);
    /*Check Sector Integrity*/
    if(Sector1Header_U32 = (VKMSMAGICFLAG ^ Sector1Footer_U32))
    {
        if(Sector2Header_U32 = (VKMSMAGICFLAG ^ Sector2Footer_U32))
        {
            if(Sector1Header_U32 < Sector2Header_U32)
            {
                ActiveSector_U32 = KEY_STORAGE1_ADDRESS;
            }
        }
    }
    else if(Sector2Header_U32 = (VKMSMAGICFLAG ^ Sector2Footer_U32))
    {
        ActiveSector_U32 = KEY_STORAGE1_ADDRESS;
    }
    else
    {
        /*default Sector*/
    } /*Handle Data Integrity seperately*/
    VKMS_printarg("\r\n VKMS Active Key Sector",ActiveSector_U32);
    if(E_OK == Fls_Read(ActiveSector_U32,(uint8*)&l_vHsmVKMSKeyFlash_ts,sizeof(l_vHsmVKMSKeyFlash_ts)))
    {
        if((l_vHsmVKMSKeyFlash_ts.KeyHeader ^ VKMSMAGICFLAG) == l_vHsmVKMSKeyFlash_ts.KeyFooter)
        {
            l_vHsmVKMSProvisionState_e = e_VKMS_Provisioned_Limited;
            if(VKMS_ERR_NONE == vHsmVKMS_Validate())
            {
                l_vHsmVKMSProvisionState_e = e_VKMS_Provisioned_Normal;
            }
            else if(1u == ResetNormalDLC())
            {
                l_vHsmVKMSProvisionState_e = e_VKMS_Provisioned_Reset;
            }
            else
            {
                /*Do nothing*/
                VKMS_print("\r\n VKMS is in some state");
            }
        }
        else if((l_vHsmVKMSKeyFlash_ts.KeyHeader == 0xFFFFFFFFU) && (l_vHsmVKMSKeyFlash_ts.KeyFooter == 0xFFFFFFFFU))
        {
            /* Do nothing*/
            l_vHsmVKMSProvisionState_e = e_VKMS_NotProvisioned;
        }
        else
        {
            if(l_vHsmVKMSProvisionState_e != e_VKMS_NotProvisioned)
            {
                l_vHsmVKMSProvisionState_e = e_VKMS_Provisioned_Limited;
                VKMS_print("\r\n VKMS_ERR_CORRUPTED_DLC_DATA");
                /* VKMS_ERR_CORRUPTED_KEY_DATA*/
            }
            else
            {
                VKMS_print("\r\n VKMS is in some state1");
            }
            
        }
    }
    else
    {
        l_vHsmVKMSProvisionState_e = e_VKMS_Provisioned_Limited;
        VKMS_print("\r\n VKMS Key flash read Failed");
        /*Error Case*/
    }
}

/**
 * @brief Initialises the VKMS module.
 *
 * Reads DLC and key data from flash and determines the VKMS provision state:
 *  - e_VKMS_NotProvisioned     if DLC is not Provisioned.
 *  - e_VKMS_Provisioned_Normal if DLC tag and key validation pass.
 *  - e_VKMS_Provisioned_Reset  if DLC is valid but Reset DLC is present.
 *  - e_VKMS_Provisioned_Limited if DLC or key data are corrupted/unreadable.
 *
 * @return None
 */
FUNC(void, VKMS_CODE) vHsmVKMS_Init(void)
{
    
    l_vHsmVKMSProvisionState_e = e_VKMS_NotProvisioned;
    if(E_OK == Fls_Read(DLC_STORAGE_ADDRESS,(uint8*)&l_vHsmVKMSDlcSlot_ts,sizeof(l_vHsmVKMSDlcSlot_ts)))
    {
        if((l_vHsmVKMSDlcSlot_ts.DLCCounter == 0xFFFFFFFFu) && (l_vHsmVKMSDlcSlot_ts.DLCMarker == 0xFFFFFFFFu))
        {
            /* VKMS not provisioned*/
            l_vHsmVKMSProvisionState_e = e_VKMS_NotProvisioned;
        }
        else
        {
            /*check DLC tag for integrity*/
            if((l_vHsmVKMSDlcSlot_ts.DLCCounter ^ VKMSMAGICFLAG) == l_vHsmVKMSDlcSlot_ts.DLCMarker)
            {
                l_vHsmVKMSProvisionState_e = e_VKMS_Provisioned_Normal;
            }
            else
            {
                l_vHsmVKMSProvisionState_e = e_VKMS_Provisioned_Limited;
                /* VKMS_ERR_CORRUPTED_KEY_DATA*/
            }
        }
    }
    vHsmVKMSKeySectorInit();
    /* Read DLC and Key Data*/
    /* DLC verification checksum Calculation*/
    /* Move it to proper Provision state*/
    VKMS_print(VKMS_ProvToString(l_vHsmVKMSProvisionState_e));
}


/**
 * @brief Validates DLC integrity by comparing verification hash.
 *
 * Retrieves the current DLC via vHsmVKMS_GetDLC(), computes its verification
 * hash, and compares it byte-by-byte against the stored DLCVerificationChksum.
 *
 * @return VKMS_ERR_NONE                   on successful validation.
 * @return VKMS_ERR_DLC_VERIFICATION_MISMATCH if hash mismatch is found.
 * @return VKMS_ERR_HW_CRYPTO_OTHER        if DLC pointer is NULL.
 */
LOCAL FUNC(te_VKMS_ErrorType,VKMS_CODE) vHsmVKMS_Validate(void)
{
    te_VKMS_ErrorType retVal = VKMS_ERR_GENERAL;
    ts_VKMSDLCDataType_st * InitDlc_st = NULL;
    uint8 LocalVerHash_U8A[DLC_HASHLEN] = {0};
    uint8 LocalIndex_U8 = 0u;
    InitDlc_st = vHsmVKMS_GetDLC();
    if(NULL != InitDlc_st)
    {
        retVal = HSM_VKMS_getVerificationHash(&LocalVerHash_U8A[0]);
        if(retVal == VKMS_ERR_NONE)
        {
            for(LocalIndex_U8 = 0u;LocalIndex_U8 < DLC_HASHLEN;LocalIndex_U8++)
            {
                if(LocalVerHash_U8A[LocalIndex_U8] != InitDlc_st->DLCVerificationChksum_U8A[LocalIndex_U8])
                {
                    retVal = VKMS_ERR_DLC_VERIFICATION_MISMATCH;
                    break;
                }
            }
        }
    }
    else
    {
        retVal = VKMS_ERR_HW_CRYPTO_OTHER;
    }
    return retVal;
}


/**
 * @brief Processes an incoming DLC and builds a list of changed keys.
 *
 * Validates the DLC parameters (length, version, key count), parses DLC
 * metadata, decrypts the enclosed key data, and compares against stored DLC.
 * Populates the changed-key list with key IDs that differ from the stored
 * state. Transitions the VKMS state machine to e_VKMS_Start_Finish on success
 * or back to e_VKMS_Idle on failure.
 *
 * @param[in]     p_dlcLength_U32          Total length of the DLC payload.
 * @param[in]     p_dlcDataPtr_pU8         Pointer to the DLC data buffer.
 * @param[out]    p_changedKeylistPtr_pU8  Buffer to receive the list of
 *                                         changed key IDs (each 2 bytes).
 * @param[in,out] p_changedKeyListLength_U32 On input: capacity of the output
 *                                           buffer. On output: number of bytes
 *                                           written.
 *
 * @return VKMS_ERR_NONE                    DLC processed successfully.
 * @return VKMS_ERR_BUSY                    VKMS state not idle.
 * @return VKMS_E_PARAM_POINTER             NULL pointer argument.
 * @return VKMS_ERR_GENERAL                 Invalid length or key-count.
 * @return VKMS_ERR_DLC_UNSUPPORTED_VERSION DLC version mismatch.
 * @return VKMS_ERR_DLC_MALFORMATTED        DLC structure is malformed.
 * @return VKMS_ERR_DLC_DEPRECATED          Stored DLC training counter is
 *                                          newer.
 * @return VKMS_ERR_DLC_VERIFICATION_MISMATCH Verification checksum mismatch.
 * @return VKMS_ERR_HW_CRYPTO_OTHER         Hardware crypto failure.
 * @return VKMS_ERR_SMALL_BUFFER            Output buffer too small.
 */
FUNC(te_VKMS_ErrorType, VKMS_CODE)HSM_VKMS_handleDLC_start(const uint32 p_dlcLength_U32, const uint8 * p_dlcDataPtr_pU8, uint8* p_changedKeylistPtr_pU8,uint32* p_changedKeyListLength_U32)
{
    Std_ReturnType         l_KeyPresent_E = E_NOT_OK;
    te_VKMS_ErrorType      l_RetVal_E   = VKMS_ERR_NONE;
    Std_ReturnType         l_resetRet_E = E_NOT_OK;
    ts_VKMSKeyDataType_st* l_keydata_st;
    uint16                 l_currentDLCECUCounter_U16 = 0u;
    uint16                 l_currentIdCounter_U16     = 0u;
    uint8                  l_currentKeyNo_U8          = 0u;
    uint8                  l_decryptFlag_U8           = 0u;
    int8_t                 l_vinflag                  = 1;
    int8_t                 l_idCounterFlag            = 1;
    uint8                  l_iter_U8                  = 0u;
    uint8                  l_keyMetadata_U8A[KEYCONSTDATA_LEN] = {0};
    uint16                 l_keyId_U16;
    uint16                 l_keyLen_U16;
    uint16                 l_trainingcounter_U16;
    volatile uint16        l_KeyIdLen_U16             = 0u;
    uint8                  l_KeyIdList_U8A[MAX_KEYLIST_LEN] = {0};
    uint8                  l_KeyBufferIndex_U8 = 0u;
    if(CurrentVKMSState_U8 != e_VKMS_Idle)
    {
        l_RetVal_E = VKMS_ERR_BUSY;
    }
    else if((NULL == p_dlcDataPtr_pU8) || (NULL == p_changedKeylistPtr_pU8) || (NULL == p_changedKeyListLength_U32))
    {
        l_RetVal_E = VKMS_E_PARAM_POINTER;
    }
    else if((DLC_MAX_KEYLIST_SIZE < *p_changedKeyListLength_U32))
    {
        l_RetVal_E = VKMS_ERR_GENERAL;
    }
    else if((DLC_METADATA_LEN > p_dlcLength_U32) || (DLC_INPUT_MAX_LENGTH < p_dlcLength_U32))
    {
        l_RetVal_E = VKMS_ERR_GENERAL;
    }
    else if (VKMS_DLC_VERSION != p_dlcDataPtr_pU8[0])
    {
        l_RetVal_E = VKMS_ERR_DLC_UNSUPPORTED_VERSION;
    }
    else if((MAX_CONFIGURED_KEYS < p_dlcDataPtr_pU8[DLC_KEYNUMBER_OFFSET]) || (p_dlcLength_U32 != HSM_VKMS_KEY_DLCLEN(p_dlcDataPtr_pU8[DLC_KEYNUMBER_OFFSET])))
    {
        l_RetVal_E = VKMS_ERR_DLC_MALFORMATTED;
    }
    else
    {
        (void)memset(&l_DLCKeyData_U8A[0], 0, MAX_BUFF_SIZE);
        (void)memcpy(&l_currentDlcdata[0], p_dlcDataPtr_pU8,DLC_METADATA_LEN); /* loading current dlc preamble to RAM*/
        (void)memcpy(&l_DLCKeyData_U8A[0], &p_dlcDataPtr_pU8[DLC_METADATA_LEN],(p_dlcLength_U32 - DLC_METADATA_LEN)); /* Loading current key-metadata pair into RAM*/
        /* Loading Current DLC data to structure element*/
        l_CurrentDLC_st.DLCversion_U8 = l_currentDlcdata[0];
        (void)memcpy(&l_CurrentDLC_st.InitVector_U8A[0], &l_currentDlcdata[INIT_VECTOR_INDEX], INIT_VECTOR_LENGTH);
        (void)memcpy((uint8*)&l_currentDLCECUCounter_U16, &l_currentDlcdata[ECU_TRAINING_INDEX], 2);
        l_CurrentDLC_st.EcuTrainingCounter_U16 = (l_currentDLCECUCounter_U16 >> 8) | (l_currentDLCECUCounter_U16 << 8);
        (void)memcpy(&l_CurrentDLC_st.EcuGrpVIN_U8A[0], &l_currentDlcdata[VIN_OF_VKMS_INDEX], VIN_OF_VKMS_LENGTH);
        (void)memcpy(&l_CurrentDLC_st.MasterKeyGrpId_U8A[0], &l_currentDlcdata[MASTER_KEY_INDEX], 3);
        (void)memcpy((uint8*)&l_currentIdCounter_U16, &l_currentDlcdata[IDENTITY_COUNTER_INDEX], 2);
        l_CurrentDLC_st.IdentityCounter_U16 = (l_currentIdCounter_U16 >> 8) | (l_currentIdCounter_U16 << 8);
        (void)memcpy(&l_CurrentDLC_st.DLCVerificationChksum_U8A[0], &l_currentDlcdata[DLC_VER_CHKSUM_INDEX], DLC_VER_CHKSUM_LENGTH);
        l_currentKeyNo_U8                   = l_currentDlcdata[DLC_KEYNUMBER_OFFSET];
        l_currentKeylen                     = (uint16)p_dlcLength_U32 - (uint16)DLC_METADATA_LEN;
        l_CurrentDLC_st.NumberOfKeys_U8 = l_currentKeyNo_U8;
        
        l_StoredDLC_st = vHsmVKMS_GetDLC();
        if(NULL != l_StoredDLC_st)
        {
            if(e_VKMS_Provisioned_Normal == l_vHsmVKMSProvisionState_e)
            {
                l_vinflag = memcmp(&l_CurrentDLC_st.EcuGrpVIN_U8A[0], &l_StoredDLC_st->EcuGrpVIN_U8A[0], 17);
                if (l_StoredDLC_st->EcuTrainingCounter_U16 > l_CurrentDLC_st.EcuTrainingCounter_U16)
                {
                    l_RetVal_E = VKMS_ERR_DLC_DEPRECATED;
                }
                else if ((l_StoredDLC_st->EcuTrainingCounter_U16 == l_CurrentDLC_st.EcuTrainingCounter_U16) && (0 == l_vinflag))
                {
                    if (0 == memcmp(&l_StoredDLC_st->DLCVerificationChksum_U8A[0],
                                    &l_CurrentDLC_st.DLCVerificationChksum_U8A[0], DLC_VER_CHKSUM_LENGTH))
                    {
                        l_RetVal_E = VKMS_ERR_NONE;
                        
                    }
                    else
                    {
                        l_RetVal_E = VKMS_ERR_DLC_VERIFICATION_MISMATCH;
                    }
                    *p_changedKeyListLength_U32 = 0u;
                    l_keychangedLen             = 0u;
                }
                else
                {
                    /*Other Cases Continue*/
                    l_RetVal_E  = HSM_VKMS_decryptDlcKeys(&l_DLCKeyData_U8A[0], l_currentKeylen);
                    if(VKMS_ERR_NONE == l_RetVal_E)
                    {
                        l_decryptFlag_U8 = 1u;
                    }
                }
            }
            else
            {
                l_RetVal_E = HSM_VKMS_decryptDlcKeys(&l_DLCKeyData_U8A[0], l_currentKeylen);
                if(VKMS_ERR_NONE == l_RetVal_E)
                {
                    l_decryptFlag_U8 = 1u;
                }
            }
        }
        else
        {
            l_RetVal_E = VKMS_ERR_HW_CRYPTO_OTHER;
        }
        
        if(1u == l_decryptFlag_U8)
        {
            l_resetRet_E =  ResetDlcCheck();
            if(E_NOT_OK == l_resetRet_E) /* Not Reset DLC*/
            {
                if (e_VKMS_Provisioned_Normal == l_vHsmVKMSProvisionState_e)
                {
                    l_idCounterFlag = memcmp((uint8*)&l_CurrentDLC_st.IdentityCounter_U16, (uint8*)&l_StoredDLC_st->IdentityCounter_U16, 2);
                    if ((l_vinflag == 0) && (l_idCounterFlag == 0) && (MAX_CONFIGURED_KEYS == l_CurrentDLC_st.NumberOfKeys_U8))
                    {
                        l_KeyBufferIndex_U8 = 0u;
                        for (l_iter_U8 = 0u; (l_iter_U8 < l_CurrentDLC_st.NumberOfKeys_U8) && ((l_KeyBufferIndex_U8 + KEYCONSTDATA_LEN) < l_currentKeylen); l_iter_U8++)
                        {
                            (void)memcpy(&l_keyMetadata_U8A[0], &l_DLCDecrypted_U8A[l_KeyBufferIndex_U8], KEYCONSTDATA_LEN);
                            l_KeyBufferIndex_U8 += KEYCONSTDATA_LEN;
                            (void)memcpy((uint8*)&l_keyId_U16, &l_keyMetadata_U8A[0], 2);
                            HSM_VKMS_InvertEndianness(&l_keyId_U16, 2);
                            (void)memcpy((uint8*)&l_keyLen_U16, &l_keyMetadata_U8A[6], 2);
                            HSM_VKMS_InvertEndianness(&l_keyLen_U16, 2);
                            (void)memcpy((uint8*)&l_trainingcounter_U16, &l_keyMetadata_U8A[2], 2);
                            HSM_VKMS_InvertEndianness(&l_trainingcounter_U16, 2);
                            l_keydata_st = vHsmVKMS_GetKey(l_keyId_U16, &l_KeyPresent_E);
                            if ((TRUE == l_keydata_st->KeyIdLocated_bool) && (E_OK == l_KeyPresent_E))
                            {
                                if (l_trainingcounter_U16 == l_keydata_st->TypeTrainingCounter_U16)
                                {
                                    /*skip the storage*/
                                    (void)vHsmVKMS_SetSkippedKey(l_keyId_U16);
                                }
                                else
                                {
                                    (void)memcpy(&l_KeyIdList_U8A[l_KeyIdLen_U16], &l_keyMetadata_U8A[0], 2);
                                    l_KeyIdLen_U16 += 2u;
                                }
                            }
                            else
                            {
                                (void)memcpy(&l_KeyIdList_U8A[l_KeyIdLen_U16], &l_keyMetadata_U8A[0], 2);
                                l_KeyIdLen_U16 += 2u;
                            }
                            l_KeyBufferIndex_U8 += l_keyLen_U16;
                        }
                    }
                    else
                    {
                        l_KeyBufferIndex_U8 = 0u;
                        for (l_iter_U8 = 0u; (l_iter_U8 < l_currentKeyNo_U8)&&((l_KeyBufferIndex_U8 + KEYCONSTDATA_LEN) < l_currentKeylen); l_iter_U8++)
                        {
                            (void)memcpy(&l_keyMetadata_U8A[0], &l_DLCDecrypted_U8A[l_KeyBufferIndex_U8], KEYCONSTDATA_LEN);
                            l_KeyBufferIndex_U8 += KEYCONSTDATA_LEN;
                            if(l_KeyIdLen_U16 <= VKMS_CHANGESLIST_INDEX)
                            {
                                (void)memcpy(&l_KeyIdList_U8A[l_KeyIdLen_U16], &l_keyMetadata_U8A[0], 2);
                                l_KeyIdLen_U16 += 2u;
                            }
                            (void)memcpy((uint8*)&l_keyLen_U16, &l_keyMetadata_U8A[6], 2);
                            HSM_VKMS_InvertEndianness(&l_keyLen_U16, 2);
                            l_KeyBufferIndex_U8 += l_keyLen_U16;
                        }
                    }
                    l_RetVal_E = VKMS_ERR_NONE;
                }
                else
                {
                    if(l_CurrentDLC_st.NumberOfKeys_U8 == MAX_CONFIGURED_KEYS)
                    {
                        l_KeyBufferIndex_U8 = 0u;
                        for (l_iter_U8 = 0u; (l_iter_U8 < l_currentKeyNo_U8) && ((l_KeyBufferIndex_U8 + KEYCONSTDATA_LEN) < l_currentKeylen); l_iter_U8++)
                        {
                            (void)memcpy(&l_keyMetadata_U8A[0], &l_DLCDecrypted_U8A[l_KeyBufferIndex_U8], KEYCONSTDATA_LEN);
                            l_KeyBufferIndex_U8 += KEYCONSTDATA_LEN;
                            if(l_KeyIdLen_U16 <= VKMS_CHANGESLIST_INDEX)
                            {
                                (void)memcpy(&l_KeyIdList_U8A[l_KeyIdLen_U16], &l_keyMetadata_U8A[0], 2);
                                l_KeyIdLen_U16 += 2u;
                            }
                            (void)memcpy((uint8*)&l_keyLen_U16, &l_keyMetadata_U8A[6], 2);
                            HSM_VKMS_InvertEndianness(&l_keyLen_U16, 2u);
                            l_KeyBufferIndex_U8 += l_keyLen_U16;
                        }
                        l_RetVal_E = VKMS_ERR_NONE;
                    }
                    else
                    {
                        l_RetVal_E = VKMS_ERR_DLC_MALFORMATTED;
                    }
                }
            }
            else
            {
                /* Reset DLC to be having only PSS key nothing else*/
                (void)memcpy(&l_keyMetadata_U8A[0], &l_DLCDecrypted_U8A[0], KEYCONSTDATA_LEN);
                (void)memcpy((uint8*)&l_keyId_U16, &l_keyMetadata_U8A[0], 2);
                HSM_VKMS_InvertEndianness(&l_keyId_U16, 2);
                if(PSS_KEYID == l_keyId_U16)
                {
                    (void)memcpy(&l_KeyIdList_U8A[0], &l_keyMetadata_U8A[0], 2);
                    l_KeyIdLen_U16 += 2u;
                    l_ResetDLCFlag_U8 = 1u;
                    l_ResetFlag_U8 = 1u;
                    l_RetVal_E = VKMS_ERR_NONE;
                }
                else
                {
                    l_RetVal_E = VKMS_ERR_DLC_MALFORMATTED;
                }
            }
        }
    }
    if (VKMS_ERR_NONE == l_RetVal_E)
    {
        if (*p_changedKeyListLength_U32 >= (uint32)l_KeyIdLen_U16)
        {
            (void)memcpy(p_changedKeylistPtr_pU8, &l_KeyIdList_U8A[0], l_KeyIdLen_U16);
            (void)memcpy(&l_changedkeylist[0], &l_KeyIdList_U8A[0], l_KeyIdLen_U16);
            *p_changedKeyListLength_U32 = l_KeyIdLen_U16;
            CurrentVKMSState_U8         = e_VKMS_Start_Finish;
            l_keychangedLen             = l_KeyIdLen_U16;
        }
        else
        {
            l_RetVal_E = VKMS_ERR_SMALL_BUFFER;
            CurrentVKMSState_U8 = e_VKMS_Idle;
        }
    }
    else
    {
        CurrentVKMSState_U8 = e_VKMS_Idle;
    }
    VKMS_print(VKMS_ErrToString(l_RetVal_E));
    return l_RetVal_E;
}

/**
 * @brief Finalises DLC processing: derives and persists changed keys.
 *
 * Must be called after HSM_VKMS_handleDLC_start() when VKMS state is
 * e_VKMS_Start_Finish. Processes each key in the changed-key list:
 * validates key attributes, derives/store the key material, and handles
 * missing keys. On completion, writes DLC and key data to flash and
 * updates the provision state.
 *
 * @return VKMS_ERR_NONE                    VKMS DLC download successfull.
 * @return VKMS_ERR_PRECONDITION_NOT_MET    No DLC Start called prior.
 * @return VKMS_ERR_DLC_MALFORMATTED        PSS key missing or key flags invalid.
 * @return VKMS_ERR_HW_KEY_WRITE_FAIL       Key flash write failed.
 * @return VKMS_ERR_HW_CRYPTO_OTHER         Hardware crypto failure.
 * @return VKMS_ERR_DLC_VERIFICATION_MISMATCH DLC verification checksum mismatch.
 * @return VKMS_ERR_DLC_MISSING_KEY         One or more configured keys missing
 *                                          from DLC.
 */
FUNC(te_VKMS_ErrorType, VKMS_CODE) HSM_VKMS_handleDLC_finish(void)
{
    te_VKMS_ErrorType l_RetVal_E         = VKMS_ERR_GENERAL;
    Std_ReturnType    l_pssFound         = E_NOT_OK;
    uint16            l_counter_U16      = 0u;
    uint16            l_iter_U16         = l_keychangedLen/2u;
    uint16            l_KeyId_U16        = 0u;
    uint16            l_keyIdCounter_U16 = 0u;
    uint8             l_keyConfFlag_U8   = 0u;
    uint16            l_KeysConfigNeg_U16[MAX_CONFIGURED_KEYS] = {0};
    uint16            l_ConfigKeyCounter_U8 = 0u;
    uint16            l_tmpkeyId = 0u;
    uint8             l_counterKey_U8 = 0u;
    uint8             l_MissingKeyFlag_U8 = 0u;
    uint8             l_KeyIntID_U8 = 0u;
    if(e_VKMS_Start_Finish != CurrentVKMSState_U8)
    {
        l_RetVal_E = VKMS_ERR_PRECONDITION_NOT_MET;
    }
    else if(0u == l_keychangedLen) /* No keys to be persisted*/
    {
        l_RetVal_E = VKMS_ERR_NONE;
    }
    else
    {         
        (void)memset((uint8*)&l_vHsmVKMSStoreKeys_stA, 0, sizeof(l_vHsmVKMSStoreKeys_stA));
        l_StoreKeysCounter_U16 = 0u;
        for(l_ConfigKeyCounter_U8 = 0u; l_ConfigKeyCounter_U8 < l_iter_U16; l_ConfigKeyCounter_U8++)
        {
            (void)memcpy((uint8*)&l_tmpkeyId, &l_changedkeylist[l_ConfigKeyCounter_U8 * 2u], 2);
            HSM_VKMS_InvertEndianness(&l_tmpkeyId, 2u);
            l_KeysConfigNeg_U16[l_ConfigKeyCounter_U8] = l_tmpkeyId;
        }
        if((MAX_CONFIGURED_KEYS > l_iter_U16) && (0u == l_ResetDLCFlag_U8) && (MAX_CONFIGURED_KEYS != l_CurrentDLC_st.NumberOfKeys_U8)) /*For Missing Key*/
        {
            for(l_ConfigKeyCounter_U8 = 0u; l_ConfigKeyCounter_U8 < MAX_CONFIGURED_KEYS; l_ConfigKeyCounter_U8 ++)
            {
                l_MissingKeyFlag_U8 = 0u;
                for(l_counterKey_U8 = 0u; l_counterKey_U8 < l_iter_U16; l_counterKey_U8++)
                {
                    if(l_KeysConfigNeg_U16[l_counterKey_U8] == l_vHsmVKMSKeyConfigArray_stA[l_ConfigKeyCounter_U8].KeyId_U16)
                    {
                        l_MissingKeyFlag_U8 = 1u;
                        break;
                    }
                }
                if(0u == l_MissingKeyFlag_U8) /*Key is Missing in the DLC*/
                {
                    l_RetVal_E = vHsmVKMS_SetSkippedKey(l_vHsmVKMSKeyConfigArray_stA[l_ConfigKeyCounter_U8].KeyId_U16);
                    VKMS_printarg("\r\n Missing Key",l_vHsmVKMSKeyConfigArray_stA[l_ConfigKeyCounter_U8].KeyId_U16);
                }
            }
            l_vHsmVMMSmissingKeyFlag_U8 = 1u;
        }
        /*Check for PSS in the DLC*/
        l_pssFound = SearchForPss();
        if (E_NOT_OK == l_pssFound)
        {
            l_RetVal_E = VKMS_ERR_DLC_MALFORMATTED;
        }
        else /*Not Normal Mode*/
        {
            for (l_counter_U16 = 0u; l_counter_U16 < l_iter_U16; l_counter_U16++)
            {
                (void)memcpy((uint8*)&l_KeyId_U16, &l_changedkeylist[l_counter_U16 * 2u], 2);
                HSM_VKMS_InvertEndianness(&l_KeyId_U16, 2u);
                for (l_keyIdCounter_U16 = 0u; l_keyIdCounter_U16 < MAX_CONFIGURED_KEYS; l_keyIdCounter_U16++)
                {
                    if (l_vHsmVKMSKeyConfigArray_stA[l_keyIdCounter_U16].KeyId_U16 == l_KeyId_U16)
                    {
                        l_keyConfFlag_U8 = 1u;
                        break;
                    }
                    else
                    {
                        l_keyConfFlag_U8 = 0u;
                    }
                }

                if (l_keyConfFlag_U8 == 1u)
                {
                    l_RetVal_E = SearchKeyId(l_KeyId_U16, l_currentKeylen - 16u);
                    if(l_ResetDLCFlag_U8 == 0u) /* for reset DLC*/
                    {
                        if (((ECUSIDE_DERIVATION == (ECUSIDE_DERIVATION & l_currentKey_st.KeyFlags_U8)) ||
                            (ABSTARCT_KEY == (ABSTARCT_KEY & l_currentKey_st.KeyFlags_U8)) ||
                            (TRANSIENT_KEY == (TRANSIENT_KEY & l_currentKey_st.KeyFlags_U8))) &&
                            (PSS_KEYID == l_KeyId_U16 ))
                        {
                            l_RetVal_E = VKMS_ERR_DLC_MALFORMATTED;
                            break;
                        }
                        else
                        {
                            if (l_RetVal_E == VKMS_ERR_NONE)
                            {
                                l_RetVal_E = DeriveStoreKey();
                            }
                            else
                            {
                                /* do nothing*/
                                VKMS_print("\r\n Key not found");
                            }
                        }
                    }
                    else /*Given Reset DLC*/
                    {
                        if(l_RetVal_E == VKMS_ERR_NONE)
                        {
                            if(PSS_KEYID == l_KeyId_U16)
                            {
                                if((0u == (0x8E & l_currentKey_st.KeyFlags_U8)) && (SYMMETRIC256_P2 == l_currentKey_st.KeyGenus_U8))
                                {
                                    l_StoreKey_St.KeyTypeId_U16 = l_currentKey_st.KeyTypeId_U16;
                                    l_StoreKey_St.TypeTrainingCounter_U16 = 0u;
                                    l_StoreKey_St.KeyGenus_U8             = l_currentKey_st.KeyGenus_U8;
                                    l_StoreKey_St.KeyFlags_U8             = l_currentKey_st.KeyFlags_U8;
                                    l_StoreKey_St.KeyLength_U16           = l_currentKey_st.KeyLength_U16;
                                    (void)memcpy(&l_StoreKey_St.Key_Payload_U8[0],l_currentKey_st.Key_Payload_U8P,l_StoreKey_St.KeyLength_U16);
                                    l_KeyIntID_U8 = vHsmVKMSKEYMAP(l_StoreKey_St.KeyTypeId_U16);
                                    if(MAX_CONFIGURED_KEYS > l_KeyIntID_U8)
                                    {
                                        l_vHsmVKMSStoreKeys_stA[l_KeyIntID_U8] = l_StoreKey_St;
                                        l_StoreKeysCounter_U16 += 1;
                                        l_CurrentDLC_st.EcuTrainingCounter_U16 = 0u;
                                        (void)memset(&l_CurrentDLC_st.EcuGrpVIN_U8A[0],0x2d,17);
                                        l_RetVal_E = VKMS_ERR_NONE;
                                    }
                                }
                                else
                                {
                                    l_RetVal_E = VKMS_ERR_DLC_MALFORMATTED;
                                    break;
                                }
                            }
                            else
                            {
                                l_RetVal_E = VKMS_ERR_DLC_MALFORMATTED;
                                break;
                            }
                        }
                        else
                        {
                            /*do nothing this case needs to be checked*/
                        }
                        l_ResetDLCFlag_U8 = 0u;
                    }
                    
                }
                else
                {
                    l_RetVal_E = VKMS_ERR_CONFIG_TYPEID_NOT_CONFIGURED;
                    break;
                }
            }
        }
        if ((l_RetVal_E == VKMS_ERR_NONE) && (l_StoreKeysCounter_U16 > 0u))
        {
            l_RetVal_E = HSM_VKMS_getVerificationHashRam();
            if((l_RetVal_E != VKMS_ERR_DLC_VERIFICATION_MISMATCH) || (0u != l_ResetFlag_U8))
            {
                l_RetVal_E = Set_VKMSDLC();
                if(VKMS_ERR_NONE == l_RetVal_E)
                {
                    l_RetVal_E = Set_VKMSKeys();
                    if(VKMS_ERR_NONE != l_RetVal_E)
                    {
                        VKMS_print("\r\n Key write Failed");
                    }
                }
                else
                {
                    VKMS_print("\r\n DLC write Failed");
                }
            }
        }
        else
        {
            /*Do Nothing */
        }
    }
    if(VKMS_ERR_NONE == l_RetVal_E)
    {
        if(0u != l_ResetFlag_U8) /*Reset DLC*/
        {
            l_ResetFlag_U8 = 0u;
            l_vHsmVKMSProvisionState_e = e_VKMS_Provisioned_Reset;
        }
        else /*No error*/
        {
            if(l_vHsmVMMSmissingKeyFlag_U8 == 1u)
            {
                l_RetVal_E = VKMS_ERR_DLC_MISSING_KEY;
                l_vHsmVMMSmissingKeyFlag_U8 = 0u;
            }
            l_vHsmVKMSProvisionState_e = e_VKMS_Provisioned_Normal;
        }
    }
    else if(VKMS_ERR_DLC_VERIFICATION_MISMATCH == l_RetVal_E)
    {
        l_vHsmVKMSProvisionState_e = e_VKMS_Provisioned_Limited;
    }
    else if(VKMS_ERR_HW_KEY_WRITE_FAIL == l_RetVal_E)
    {
        l_vHsmVKMSProvisionState_e = e_VKMS_Provisioned_Limited; /*force into limited mode for key write fail */
    }
    else
    {
        /* Do nothing return the result to caller*/
    }
    CurrentVKMSState_U8 = e_VKMS_Idle;
    VKMS_print(VKMS_ErrToString(l_RetVal_E));
    VKMS_print(VKMS_ProvToString(l_vHsmVKMSProvisionState_e));
    return l_RetVal_E;
}

/**
 * @brief Checks whether the current DLC is a reset DLC.
 *
 * A reset DLC is identified by EcuTrainingCounter == 0xFFFF and
 * EcuGrpVIN filled with 0xFF.
 *
 * @return E_OK    if the DLC is a reset DLC.
 * @return E_NOT_OK otherwise.
 */
LOCAL FUNC(Std_ReturnType, VKMS_CODE) ResetDlcCheck(void)
{
    Std_ReturnType fl_RetVal_E = E_NOT_OK;
    const uint8 l_ResetVIN_U8A[17] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
    if((0xffffu == l_CurrentDLC_st.EcuTrainingCounter_U16) && (0 == memcmp(&l_CurrentDLC_st.EcuGrpVIN_U8A[0],&l_ResetVIN_U8A[0],17u)))
    {
        fl_RetVal_E = E_OK;
        VKMS_print("\r\n Reset DLC");
    }
    return fl_RetVal_E;
}

/**
 * @brief Checks whether the stored DLC indicates a reset or normal state.
 *
 * Reads the stored DLC via vHsmVKMS_GetDLC() and tests:
 *  - Reset:  EcuTrainingCounter == 0 and EcuGrpVIN filled with 0x2d
 *  - Normal: otherwise
 *
 * @return 1 if reset DLC, 0 if normal DLC, 0xFF if NULL DLC pointer.
 */
LOCAL FUNC(uint8, VKMS_CODE) ResetNormalDLC(void)
{
    static uint8 l_ResetNormal_U8 = 0xffu;
    const uint8 l_normalVin_U8A[17] = {0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d};
    static ts_VKMSDLCDataType_st* l_ResetnormalDlc_st;
    l_ResetnormalDlc_st = vHsmVKMS_GetDLC();
    if (NULL != l_ResetnormalDlc_st)
    {
        if((0u == l_ResetnormalDlc_st->EcuTrainingCounter_U16) && (0 == memcmp((uint8 *)&l_ResetnormalDlc_st->EcuGrpVIN_U8A[0],(uint8 *)&l_normalVin_U8A[0],17u)))
        {
            l_ResetNormal_U8 = 1u;
        }
        else
        {
            l_ResetNormal_U8 = 0u;
        }
    }
    return l_ResetNormal_U8;
}

/**
 * @brief Searches for the PSS key in the changed-key list.
 *
 * Iterates through l_changedkeylist looking for a key ID matching PSS_KEYID.
 *
 * @return E_OK    if PSS key is found.
 * @return E_NOT_OK otherwise.
 */
LOCAL FUNC(Std_ReturnType, VKMS_CODE) SearchForPss(void)
{
    Std_ReturnType l_Pssfound_E      = E_NOT_OK;
    uint16         l_counter_U16     = l_keychangedLen / 2u;
    uint16         l_ietrCounter_U16 = 0u;
    uint16         l_pssKeyId_U16;
    uint8*         l_tmpPtr_pU8;
    uint8          l_pssfound_U8;
    l_tmpPtr_pU8 = &l_changedkeylist[0];
    l_pssfound_U8 = 0u;
    for (l_ietrCounter_U16 = 0u; l_ietrCounter_U16 < l_counter_U16; l_ietrCounter_U16++)
    {
        (void)memcpy((uint8*)&l_pssKeyId_U16, l_tmpPtr_pU8, 2);
        l_tmpPtr_pU8 += 2;
        HSM_VKMS_InvertEndianness(&l_pssKeyId_U16, 2u);
        if (PSS_KEYID == l_pssKeyId_U16)
        {
            l_pssfound_U8 = 1u;
            break;
        }
        else
        {
            l_pssfound_U8 = 0u;
        }
    }
    if (1u == l_pssfound_U8)
    {
        l_Pssfound_E = E_OK;
    }
    return l_Pssfound_E;
}

/**
 * @brief Derives and stores a key according to the DLC rule set.
 *
 * Handles ECU-side KDF derivation (symmetric 128/256), abstract key mapping,
 * and plain key/certificate/data storage. On success the key is copied into
 * the l_vHsmVKMSStoreKeys_stA array at the index returned by vHsmVKMSKEYMAP().
 *
 * @return VKMS_ERR_NONE                        Key derived and stored.
 * @return VKMS_ERR_GENERAL                     KDF or unsupported genus failure.
 * @return VKMS_ERR_DLC_CONFLICTING_FLAGS       Both ECU and abstract flags set.
 * @return VKMS_ERR_DLC_MALFORMATTED            Parent key not found.
 * @return VKMS_ERR_CONFIG_TYPEID_NOT_CONFIGURED Key type ID not in config.
 */
LOCAL FUNC(te_VKMS_ErrorType, VKMS_CODE) DeriveStoreKey(void)
{
    te_VKMS_ErrorType l_Retval_E        = VKMS_ERR_NONE;
    Std_ReturnType    l_KeyPresent_E = E_NOT_OK;
    Std_ReturnType    fl_Retval_E       = E_NOT_OK;
    uint16            l_abstractkeyId   = 0u;
    uint16            l_EcuderKeyId_U16 = 0u;
    uint16            l_ecuDergenus_U16 = 0u;
    uint8             l_derivedkey_U8A[32];
    uint8             l_parameterset_U8A[4];
    const uint8       l_label_U8A[4]    = {0x56, 0x4B, 0x4D, 0x53};
    uint8             l_counterlen_U8   = 1u;
    uint8             l_KeystoreFlag_U8 = 0u;
    uint8             l_localKeyId_U8 = 0u;
    if (1 == l_currentKey_st.Key_EcuDeri_U8)
    {
        if ((ECUABSTRACT_KEY & l_currentKey_st.KeyFlags_U8) ==
                 ECUABSTRACT_KEY) /* both ecu and abstract flags enabled*/
        {
            l_Retval_E = VKMS_ERR_DLC_CONFLICTING_FLAGS;
        }
        else if ((ECUSIDE_DERIVATION & l_currentKey_st.KeyFlags_U8) == ECUSIDE_DERIVATION)
        {
            l_ecuDergenus_U16 = l_currentKey_st.KeyGenus_U8;
            (void)memset(&l_derivedkey_U8A[0], 0x00, 32u);
            (void)memcpy((uint8*)&l_EcuderKeyId_U16, l_currentKey_st.Key_Payload_U8P, 2);
            HSM_VKMS_InvertEndianness((uint8*)&l_EcuderKeyId_U16,2);
            l_parentKey_St = vHsmVKMS_GetParent(l_EcuderKeyId_U16, &l_KeyPresent_E);
            if ((TRUE == l_parentKey_St->KeyIdLocated_bool) && (E_OK == l_KeyPresent_E))
            {
                (void)memset(&l_parameterset_U8A[0], 0, 4);
                (void)memcpy(&l_parameterset_U8A[0], (uint8*)&l_currentKey_st.KeyTypeId_U16, 2);
                HSM_VKMS_InvertEndianness(&l_parameterset_U8A[0],2u);
                (void)memcpy(&l_parameterset_U8A[2], (uint8*)&l_currentKey_st.TypeTrainingCounter_U16, 2);
                HSM_VKMS_InvertEndianness(&l_parameterset_U8A[2],2u);
                switch (l_ecuDergenus_U16)
                {
                    case SYMMETRIC128_P2:
                        fl_Retval_E = vHsmCrypt_KDF_Counter(l_counterlen_U8, l_parentKey_St->Key_Payload_U8P,
                                                            l_parentKey_St->KeyLength_U16, &l_label_U8A[0], 4,
                                                            &l_parameterset_U8A[0], 4, KEYLEN_128, &l_derivedkey_U8A[0],
                                                            vHsmCrypt_Sha256SW);
                        if (E_OK == fl_Retval_E)
                        {
                            l_StoreKey_St.KeyLength_U16   = KEYLEN_128;
                            (void)memcpy(&l_StoreKey_St.Key_Payload_U8[0],&l_derivedkey_U8A[0],l_StoreKey_St.KeyLength_U16);
                            l_Retval_E                    = VKMS_ERR_NONE;
                        }
                        else
                        {
                            l_Retval_E = VKMS_ERR_GENERAL;
                        }
                        break;
                    case SYMMETRIC256_P2:
                        fl_Retval_E = vHsmCrypt_KDF_Counter(l_counterlen_U8, l_parentKey_St->Key_Payload_U8P,
                                                            l_parentKey_St->KeyLength_U16, &l_label_U8A[0], 4,
                                                            &l_parameterset_U8A[0], 4, KEYLEN_256, &l_derivedkey_U8A[0],
                                                            vHsmCrypt_Sha256SW);
                        if (E_OK == fl_Retval_E)
                        {
                            l_StoreKey_St.KeyLength_U16   = KEYLEN_256;
                            (void)memcpy(&l_StoreKey_St.Key_Payload_U8[0],&l_derivedkey_U8A[0],l_StoreKey_St.KeyLength_U16);
                            l_Retval_E                    = VKMS_ERR_NONE;
                        }
                        else
                        {
                            l_Retval_E = VKMS_ERR_GENERAL;
                        }
                        break;
                    case SYMMETRICAESECB:
                        l_StoreKey_St.KeyLength_U16   = KEYLEN_128;
                        l_Retval_E = VKMS_ERR_GENERAL;
                        break;
                    case ASYMMETRIC256:
                        l_StoreKey_St.KeyLength_U16   = KEYLEN_256;
                        l_Retval_E = VKMS_ERR_GENERAL;
                        break;
                    case ASYMMETRIC256FIP:
                        l_StoreKey_St.KeyLength_U16   = KEYLEN_256;
                        l_Retval_E = VKMS_ERR_GENERAL;
                        break;
                    default:
                        break;
                }
                if (VKMS_ERR_NONE == l_Retval_E)
                {
                    l_StoreKey_St.KeyTypeId_U16           = l_currentKey_st.KeyTypeId_U16;
                    l_StoreKey_St.TypeTrainingCounter_U16 = l_currentKey_st.TypeTrainingCounter_U16;
                    l_StoreKey_St.KeyGenus_U8             = l_currentKey_st.KeyGenus_U8;
                    l_StoreKey_St.KeyFlags_U8             = l_currentKey_st.KeyFlags_U8;
                    l_KeystoreFlag_U8                     = 1u;
                }
                else
                {
                    /* return Error code*/
                }
            }
            else
            {
                l_Retval_E = VKMS_ERR_DLC_MALFORMATTED;
            }
        }
        else if ((ABSTARCT_KEY & l_currentKey_st.KeyFlags_U8) == ABSTARCT_KEY)
        {
            (void)memcpy((uint8*)&l_abstractkeyId, l_currentKey_st.Key_Payload_U8P, 2);
            l_StoreKey_St.KeyTypeId_U16           = l_abstractkeyId;
            l_StoreKey_St.TypeTrainingCounter_U16 = l_currentKey_st.TypeTrainingCounter_U16;
            l_StoreKey_St.KeyGenus_U8             = l_currentKey_st.KeyGenus_U8;
            l_StoreKey_St.KeyFlags_U8             = l_currentKey_st.KeyFlags_U8;
            l_StoreKey_St.KeyLength_U16           = l_currentKey_st.KeyLength_U16;
            (void)memset(&l_StoreKey_St.Key_Payload_U8[0],0x00,sizeof(l_StoreKey_St.Key_Payload_U8));
            l_KeystoreFlag_U8                     = 1u;
        }
        else /* without ECUside derivation*/
        {
            l_StoreKey_St.KeyTypeId_U16           = l_currentKey_st.KeyTypeId_U16;
            l_StoreKey_St.TypeTrainingCounter_U16 = l_currentKey_st.TypeTrainingCounter_U16;
            l_StoreKey_St.KeyGenus_U8             = l_currentKey_st.KeyGenus_U8;
            l_StoreKey_St.KeyFlags_U8             = l_currentKey_st.KeyFlags_U8;
            l_StoreKey_St.KeyLength_U16           = l_currentKey_st.KeyLength_U16;
            (void)memcpy(&l_StoreKey_St.Key_Payload_U8[0],l_currentKey_st.Key_Payload_U8P,l_StoreKey_St.KeyLength_U16);
            l_KeystoreFlag_U8                     = 1u;
        }
    }
    else
    {
        if ((CERTIFICATE == l_currentKey_st.KeyGenus_U8) || (DATA == l_currentKey_st.KeyGenus_U8))
        {
            l_StoreKey_St.KeyTypeId_U16           = l_currentKey_st.KeyTypeId_U16;
            l_StoreKey_St.TypeTrainingCounter_U16 = l_currentKey_st.TypeTrainingCounter_U16;
            l_StoreKey_St.KeyGenus_U8             = l_currentKey_st.KeyGenus_U8;
            l_StoreKey_St.KeyFlags_U8             = 0u;
            l_StoreKey_St.KeyLength_U16           = l_currentKey_st.KeyLength_U16;
            (void)memcpy(&l_StoreKey_St.Key_Payload_U8[0],l_currentKey_st.Key_Payload_U8P,l_StoreKey_St.KeyLength_U16);
            l_KeystoreFlag_U8                     = 1u;
        }
        else /* Key genera  0x13, 0x14, 0x17, 0x1F, 0x2F, and 0x30*/
        {
            l_StoreKey_St.KeyTypeId_U16           = l_currentKey_st.KeyTypeId_U16;
            l_StoreKey_St.TypeTrainingCounter_U16 = l_currentKey_st.TypeTrainingCounter_U16;
            l_StoreKey_St.KeyGenus_U8             = l_currentKey_st.KeyGenus_U8;
            l_StoreKey_St.KeyFlags_U8             = l_currentKey_st.KeyFlags_U8;
            l_StoreKey_St.KeyLength_U16           = l_currentKey_st.KeyLength_U16;
            (void)memcpy(&l_StoreKey_St.Key_Payload_U8[0],l_currentKey_st.Key_Payload_U8P,l_StoreKey_St.KeyLength_U16);
            l_KeystoreFlag_U8                     = 1u;
        }
    }
    if ((VKMS_ERR_NONE == l_Retval_E) && (l_KeystoreFlag_U8 == 1u))
    {
        l_localKeyId_U8 = vHsmVKMSKEYMAP(l_StoreKey_St.KeyTypeId_U16);
        if(MAX_CONFIGURED_KEYS > l_localKeyId_U8)
        {
            l_vHsmVKMSStoreKeys_stA[l_localKeyId_U8] = l_StoreKey_St;
            l_StoreKeysCounter_U16 += 1u;
        }
        else
        {
            l_Retval_E = VKMS_ERR_CONFIG_TYPEID_NOT_CONFIGURED;
        }
    }
    return l_Retval_E;
}
/**
 * @brief Searches for a key ID in the decrypted DLC key area.
 *
 * Walks the decrypted key buffer (l_DLCDecrypted_U8A) looking for a matching
 * key ID. On match, populates the global l_currentKey_st structure with
 * the key metadata and payload pointer. Sets Key_EcuDeri_U8 according to
 * whether the key genus is a derivable type.
 *
 * @param[in] p_KeyId_U16   The key ID to search for.
 * @param[in] p_Keylen_U16  Total byte length of the decrypted key area.
 *
 * @return VKMS_ERR_NONE                    Key found and parsed.
 * @return VKMS_ERR_GENERAL                 Key not found.
 * @return VKMS_ERR_DLC_KEYGENUS_NOT_DERIVABLE Key genus does not support
 *                                             ECU-side derivation.
 */
LOCAL FUNC(te_VKMS_ErrorType, VKMS_CODE) SearchKeyId(uint16 p_KeyId_U16, uint16 p_Keylen_U16)
{
    te_VKMS_ErrorType l_RetVal_E = VKMS_ERR_GENERAL;
    uint8*            l_searchId_pU8;
    uint8*            l_searchEnd_pU8;
    uint16            l_tmpKeyId_U16;
    uint8             l_ReadRecordfound_U8 = 0;
    uint16            l_counter_U16        = 0;
    l_searchId_pU8                         = &l_DLCDecrypted_U8A[0];
    l_searchEnd_pU8                        = &l_DLCDecrypted_U8A[p_Keylen_U16 - 1];
    while (l_searchId_pU8 < l_searchEnd_pU8)
    {
        (void)memcpy((uint8*)&l_tmpKeyId_U16, l_searchId_pU8, 2);
        HSM_VKMS_InvertEndianness(&l_tmpKeyId_U16, 2);
        if (p_KeyId_U16 == l_tmpKeyId_U16)
        {
            l_searchId_pU8 += 2;
            l_currentKey_st.KeyTypeId_U16 = p_KeyId_U16;
            (void)memcpy((uint8*)&l_currentKey_st.TypeTrainingCounter_U16, l_searchId_pU8, 2);
            HSM_VKMS_InvertEndianness(&l_currentKey_st.TypeTrainingCounter_U16, 2);
            l_searchId_pU8 += 2;
            (void)memcpy((uint8*)&l_currentKey_st.KeyGenus_U8, l_searchId_pU8, 1);
            l_searchId_pU8 += 1;
            (void)memcpy((uint8*)&l_currentKey_st.KeyFlags_U8, l_searchId_pU8, 1);
            l_searchId_pU8 += 1;
            (void)memcpy((uint8*)&l_currentKey_st.KeyLength_U16, l_searchId_pU8, 2);
            HSM_VKMS_InvertEndianness(&l_currentKey_st.KeyLength_U16, 2);
            l_searchId_pU8 += 2;
            l_currentKey_st.Key_Payload_U8P = l_searchId_pU8;
            l_searchId_pU8 += l_currentKey_st.KeyLength_U16;
            l_ReadRecordfound_U8 = 1;
            break;
        }
        else
        {
            l_searchId_pU8 += 6;
            (void)memcpy((uint8*)&l_counter_U16, l_searchId_pU8, 2);
            HSM_VKMS_InvertEndianness(&l_counter_U16, 2);
            l_searchId_pU8       = l_searchId_pU8 + l_counter_U16 + 2;
            l_ReadRecordfound_U8 = 0;
        }
    }
    if (0 != l_ReadRecordfound_U8)
    {
        if (((l_currentKey_st.KeyGenus_U8 == SYMMETRIC128_P2) || (l_currentKey_st.KeyGenus_U8 == SYMMETRIC256_P2) ||
             (l_currentKey_st.KeyGenus_U8 == SYMMETRICAESECB) || (l_currentKey_st.KeyGenus_U8 == ASYMMETRIC256) ||
             (l_currentKey_st.KeyGenus_U8 == ASYMMETRIC256FIP)))
        {
            l_currentKey_st.Key_EcuDeri_U8 = 1;
            l_RetVal_E                     = VKMS_ERR_NONE;
        }
        else
        {
            l_currentKey_st.Key_EcuDeri_U8 = 0;
            if ((ECUSIDE_DERIVATION & l_currentKey_st.KeyFlags_U8) == ECUSIDE_DERIVATION)
            {
                l_RetVal_E = VKMS_ERR_DLC_KEYGENUS_NOT_DERIVABLE;
            }
            else
            {
                l_RetVal_E = VKMS_ERR_NONE;
            }
        }
    }
    else
    {
        /* do nothing*/
    }
    return l_RetVal_E;
}


/**
 * @brief Decrypts incoming DLC key data using AES-GCM.
 *
 * Retrieves the PSS key, derives a 32-byte security key via KDF_Counter
 * with label "VKMS", then decrypts the DLC key payload. Stores the
 * decrypted result in the global l_DLCDecrypted_U8A buffer.
 *
 * @param[in] p_keystart_pU8  Pointer to the encrypted DLC key data.
 * @param[in] p_keysLen_U16   Total length of the encrypted key data.
 *
 * @return VKMS_ERR_NONE          Decryption successful.
 * @return VKMS_ERR_DLC_INVALID_MAC Decryption failed or MAC mismatch.
 */
LOCAL FUNC(te_VKMS_ErrorType, VKMS_CODE) HSM_VKMS_decryptDlcKeys(const uint8* p_keystart_pU8, const uint16 p_keysLen_U16)
{
    Std_ReturnType         l_RetVal_E            = E_NOT_OK;
    te_VKMS_ErrorType      fl_RetVal_E = VKMS_ERR_DLC_INVALID_MAC;
    uint8                  l_securityKey_U8A[32] = {0}; /* security key after derivation*/
    uint8                  l_label_U8A[4]        = {0x56, 0x4B, 0x4D, 0x53}; /*VKMS*/
    uint8                  l_Context_U8A[4]      = {0x00, 0x07, 0x00, 0x01}; /* parameter set2 for pss*/
    uint8                  l_macVer_U8A[16] = {0};
    uint16                 l_keyLen_U16     = p_keysLen_U16 - 16u;
    ts_VKMSKeyDataType_st* l_Psskey_st;

    if ((NULL != p_keystart_pU8) && (0u != p_keysLen_U16))
    {
        l_Psskey_st = vHsmVKMS_GetKey(PSS_KEYID, &l_RetVal_E);
        if(E_OK == l_RetVal_E)
        {
            l_RetVal_E  = vHsmCrypt_KDF_Counter(1, l_Psskey_st->Key_Payload_U8P, DLCVER1_KEYLEN, l_label_U8A, 4,
                                            l_Context_U8A, 4, 32, &l_securityKey_U8A[0], vHsmCrypt_Sha256SW);
            if (E_OK == l_RetVal_E)
            {
                (void)memcpy(&l_macVer_U8A[0], &l_DLCKeyData_U8A[l_keyLen_U16], DLC_HASHLEN);
                l_RetVal_E = vHsmCrypt_AesGcmDecrypt(&l_securityKey_U8A[0], 32,
                                            &l_CurrentDLC_st.InitVector_U8A[0], 12, &l_currentDlcdata[0], 54,
                                            p_keystart_pU8, l_keyLen_U16, &l_DLCDecrypted_U8A[0], &l_macVer_U8A[0], 16);
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    else
    {
        /* D o nothing*/
    }
    if(E_OK == l_RetVal_E)
    {
        fl_RetVal_E = VKMS_ERR_NONE;
    }
    return fl_RetVal_E;
}
/**
 * @brief Reverses the byte order (endianness) of a buffer in-place.
 *
 * Swaps bytes symmetrically from the ends toward the middle.
 * Does nothing if byteSize <= 1.
 *
 * @param[in,out] inArrPtr  Pointer to the buffer to reverse.
 * @param[in]     byteSize  Number of bytes in the buffer.
 *
 * @return None
 */
FUNC(void, VKMS_CODE) HSM_VKMS_InvertEndianness(void* inArrPtr, uint32 byteSize)
{
    uint32 limit;
    uint32 i;
    uint32 j = 0;
    uint8  temp;
    uint8* tempPtr = (uint8*)inArrPtr;
    if (byteSize > 1u)
    {
        limit = byteSize / 2u;
        if (0u == (byteSize % 2u))
        {
            limit -= 1u;
        }
        for (i = byteSize - 1u, j = 0u; i > limit; i--, j++)
        {
            temp       = tempPtr[j];
            tempPtr[j] = tempPtr[i];
            tempPtr[i] = temp;
        }
    }
}
/**
 * @brief Computes the PSS key hash via HMAC-SHA-256.
 *
 * Retrieves the PSS key and performs HMAC-SHA-256 over the label
 * "VKMS_PSS_Hash" using the PSS key payload as the HMAC key.
 *
 * @param[out] p_PssHashPtr_pU8  Buffer to receive the 32-byte PSS hash.
 *
 * @return VKMS_ERR_NONE         Hash computed successfully.
 * @return VKMS_E_PARAM_POINTER  NULL output pointer.
 * @return VKMS_ERR_BUSY         VKMS state machine not idle.
 */
FUNC(te_VKMS_ErrorType, VKMS_CODE) HSM_VKMS_getPssHash(uint8* p_PssHashPtr_pU8)
{
    te_VKMS_ErrorType      l_RetVal_E                     = VKMS_ERR_GENERAL;
    Std_ReturnType         l_KeyPresent_E                 = E_NOT_OK;    
    Std_ReturnType         fl_RetVal_E                    = E_NOT_OK;
    uint8                  l_PSSdata_U8A[DLCVER1_KEYLEN]  = {0};
    uint8                  l_PSSstring_U8A[PSSSTRING_LEN] = {0x56, 0x4B, 0x4D, 0x53, 0x5F, 0x50, 0x53,
                                            0x53, 0x5F, 0x48, 0x61, 0x73, 0x68};
    ts_VKMSKeyDataType_st* l_PSS_St;
    if (NULL == p_PssHashPtr_pU8)
    {
        l_RetVal_E = VKMS_E_PARAM_POINTER;
    }
    else if (e_VKMS_Idle != CurrentVKMSState_U8)
    {
        l_RetVal_E = VKMS_ERR_BUSY;
    }
    else
    {
        l_PSS_St  = vHsmVKMS_GetKey(PSS_KEYID, &l_KeyPresent_E);
        if(E_OK == l_KeyPresent_E)
        {
            (void)memcpy(&l_PSSdata_U8A[0], l_PSS_St->Key_Payload_U8P, DLCVER1_KEYLEN);
            fl_RetVal_E = vHsmCrypt_Hmac_Sha2_256(&l_PSSdata_U8A[0], DLCVER1_KEYLEN, l_PSSstring_U8A, PSSSTRING_LEN, p_PssHashPtr_pU8,vHsmCrypt_Sha256SW);
            if (E_OK == fl_RetVal_E)
            {
                l_RetVal_E = VKMS_ERR_NONE;
            }
            else
            {
                /* Do nothing*/
            }
        }
    }      
    return l_RetVal_E;
}
/**
 * @brief Computes the DLC identity hash for authentication.
 *
 * Constructs a 55-byte identity buffer from the challenge (16 bytes),
 * the DLC verification checksum (16 bytes), and remaining challenge
 * data (23 bytes), then HMAC-SHA-256 hashes it with the PSS key.
 *
 * @param[out] p_IdHashPtr_pU8     Buffer to receive the 32-byte identity hash.
 * @param[in]  p_ChallengePtr_pU8  Pointer to the challenge data (39 bytes).
 *
 * @return VKMS_ERR_NONE         Identity hash computed successfully.
 * @return VKMS_E_PARAM_POINTER  NULL pointer argument.
 * @return VKMS_ERR_BUSY         VKMS state machine not idle.
 */
FUNC(te_VKMS_ErrorType, VKMS_CODE) HSM_VKMS_getIdentityHash(uint8* p_IdHashPtr_pU8, uint8* p_ChallengePtr_pU8)
{
    te_VKMS_ErrorType      l_RetVal_E                 = VKMS_ERR_GENERAL;
    Std_ReturnType         l_KeyPresent_E             = E_NOT_OK;    
    Std_ReturnType         fl_retVal_E                = E_NOT_OK;
    uint8                  l_IdentityBuff_U8A[55]     = {0};
    uint8                  l_PssData_U8A[32]          = {0};
    uint8                  l_VerificationHash_U8A[16] = {0};
    uint8                  l_Chcksum_U8A[DLC_HASHLEN] = {0};
    ts_VKMSKeyDataType_st* l_PSS_st;
    if ((NULL == p_IdHashPtr_pU8) || (NULL == p_ChallengePtr_pU8))
    {
        l_RetVal_E = VKMS_E_PARAM_POINTER;
    }
    else if(e_VKMS_Idle != CurrentVKMSState_U8)
    {
        l_RetVal_E = VKMS_ERR_BUSY;
    }
    else
    {
        l_RetVal_E = HSM_VKMS_getVerificationHash(&l_VerificationHash_U8A[0]);
        if(VKMS_ERR_NONE == l_RetVal_E)
        {
            l_PSS_st = vHsmVKMS_GetKey(PSS_KEYID, &l_KeyPresent_E);
            if(E_OK == l_KeyPresent_E)
            {
                /*copying dlc verification checksum*/
                (void)memcpy(&l_Chcksum_U8A[0], &l_VerificationHash_U8A[0], DLC_HASHLEN);
                /*copying pss */
                (void)memcpy(&l_PssData_U8A[0], l_PSS_st->Key_Payload_U8P, DLCVER1_KEYLEN);
                (void)memcpy((uint8*)&l_IdentityBuff_U8A[0], (uint8*)&p_ChallengePtr_pU8[0], 16);
                (void)memcpy((uint8*)&l_IdentityBuff_U8A[16], (uint8*)&l_Chcksum_U8A[0], 16);
                (void)memcpy((uint8*)&l_IdentityBuff_U8A[32], (uint8*)&p_ChallengePtr_pU8[16], 23);
                fl_retVal_E =
                    vHsmCrypt_Hmac_Sha2_256(&l_PssData_U8A[0], DLCVER1_KEYLEN, &l_IdentityBuff_U8A[0], 55, p_IdHashPtr_pU8,
                                            vHsmCrypt_Sha256SW);
                if (E_OK == fl_retVal_E)
                {
                    l_RetVal_E = VKMS_ERR_NONE;
                }
                else
                {
                    /*Do Nothing*/
                }
            }      
        }
        (void)memset(&l_VerificationHash_U8A[0],0x00,16);
    }
    return l_RetVal_E;
}

/**
 * @brief Computes the DLC verification checksum from RAM-resident keys.
 *
 * Calls HSM_VKMS_DLChashRam and HSM_VKMS_KeyhashRam, XORs their
 * 16-byte results, and compares against the stored DLCVerificationChksum.
 *
 * @return VKMS_ERR_NONE                    Checksum matches.
 * @return VKMS_ERR_DLC_VERIFICATION_MISMATCH Checksum mismatch.
 */
LOCAL FUNC(te_VKMS_ErrorType, VKMS_CODE) HSM_VKMS_getVerificationHashRam(void)
{
    te_VKMS_ErrorType l_retVal_E                  = VKMS_ERR_GENERAL;  
    uint8             l_counter_U8                = 0u;
    uint8             l_DlchashRam_U8[32] = {0};
    uint8             l_KeyhashRam_U8[32] = {0};
    uint8             l_hashtmpRam_U8A[32] = {0};
    l_retVal_E = HSM_VKMS_DLChashRam(&l_DlchashRam_U8[0]);
    if (VKMS_ERR_NONE == l_retVal_E)
    {
        l_retVal_E = HSM_VKMS_KeyhashRam(&l_KeyhashRam_U8[0]);
        if (VKMS_ERR_NONE == l_retVal_E)
        {
            for (l_counter_U8 = 0u; l_counter_U8 < DLC_HASHLEN; l_counter_U8++)
            {
                l_hashtmpRam_U8A[l_counter_U8] = l_DlchashRam_U8[l_counter_U8] ^ l_KeyhashRam_U8[l_counter_U8];
            }
            if(0u != memcmp((uint8 *)&l_CurrentDLC_st.DLCVerificationChksum_U8A[0],(uint8 *)&l_hashtmpRam_U8A[0],DLC_HASHLEN))
            {
                l_retVal_E = VKMS_ERR_DLC_VERIFICATION_MISMATCH;
            }
            else
            {

            }
        }
    }
    else
    {
        /* do nothing*/
    }
    return l_retVal_E;

}



/**
 * @brief Computes an HMAC-SHA-256 hash of RAM-resident DLC metadata.
 *
 * Hashes EcuTrainingCounter, EcuGrpVIN, MasterKeyGrpId, and
 * IdentityCounter from the in-RAM l_CurrentDLC_st structure.
 *
 * @param[out] p_DlcHashPtr_pU8  Buffer to receive the 32-byte DLC hash.
 *
 * @return VKMS_ERR_NONE   Hash computed successfully.
 * @return VKMS_ERR_GENERAL NULL pointer or crypto failure.
 */
LOCAL FUNC(te_VKMS_ErrorType, VKMS_CODE) HSM_VKMS_DLChashRam(uint8* p_DlcHashPtr_pU8)
{
    te_VKMS_ErrorType l_RetVal_E                                     = VKMS_ERR_GENERAL;
    Std_ReturnType    fl_RetVal_E                                    = E_NOT_OK;
    uint8             l_MetaDataHashVerRam_U8A[DLC_METADATA_HASHLENGTH] = {0};
    uint8             l_keydata_U8A[1]                               = {0};
    if ((NULL != p_DlcHashPtr_pU8))
    {
        (void)memcpy(&l_MetaDataHashVerRam_U8A[0], (uint8*)&l_CurrentDLC_st.EcuTrainingCounter_U16, 2);
        HSM_VKMS_InvertEndianness((uint8 *)&l_MetaDataHashVerRam_U8A[0], 2);
        (void)memcpy(&l_MetaDataHashVerRam_U8A[2], &l_CurrentDLC_st.EcuGrpVIN_U8A[0], 17);
        (void)memcpy(&l_MetaDataHashVerRam_U8A[19], &l_CurrentDLC_st.MasterKeyGrpId_U8A[0], 3);
        (void)memcpy(&l_MetaDataHashVerRam_U8A[22], (uint8*)&l_CurrentDLC_st.IdentityCounter_U16, 2);
        HSM_VKMS_InvertEndianness((uint8 *)&l_MetaDataHashVerRam_U8A[22], 2);
        fl_RetVal_E = vHsmCrypt_Hmac_Sha2_256(&l_keydata_U8A[0], 1, &l_MetaDataHashVerRam_U8A[0],
                                                DLC_METADATA_HASHLENGTH, p_DlcHashPtr_pU8, vHsmCrypt_Sha256SW);
        if (E_OK == fl_RetVal_E)
        {
            l_RetVal_E = VKMS_ERR_NONE;
        }
        else
        {
            /*Error*/
        }
    }
    else
    {
        /* Error */
    }
    return l_RetVal_E;
}

/**
 * @brief Computes a combined key hash from all RAM-resident stored keys.
 *
 * Iterates over l_vHsmVKMSStoreKeys_stA entries with a non-zero training
 * counter, computing an HMAC-SHA-256 per key and XOR-combining them into
 * a cumulative 16-byte checksum.
 *
 * @param[out] p_HashPtr_pU8  Buffer to receive the 16-byte combined key hash.
 *
 * @return VKMS_ERR_NONE   Hash computed successfully.
 * @return VKMS_ERR_GENERAL NULL pointer or crypto failure.
 */
LOCAL FUNC(te_VKMS_ErrorType, VKMS_CODE) HSM_VKMS_KeyhashRam(uint8* p_HashPtr_pU8)
{
    Std_ReturnType         l_retVal_e     = E_NOT_OK;
    te_VKMS_ErrorType l_RetVal_E  = VKMS_ERR_GENERAL;
    uint8                  l_iteration_U8 = 0u;
    uint8                  l_keygenus_U8  = 0u;
    uint8                  l_keyflag_U8   = 0u;
    uint8                  l_hashkey_U8A[1]  = {0};
    uint8                  l_KeymetadataRam_U8A[6];
    uint8                  l_itercount_U8 = 0u;
    if (NULL != p_HashPtr_pU8)
    {
        for (l_iteration_U8 = 0u; l_iteration_U8 < MAX_CONFIGURED_KEYS; l_iteration_U8++)
        {
            if((l_vHsmVKMSStoreKeys_stA[l_iteration_U8].TypeTrainingCounter_U16 != 0u))
            {
                l_keyflag_U8  = l_vHsmVKMSStoreKeys_stA[l_iteration_U8].KeyFlags_U8;
                l_keygenus_U8 = l_vHsmVKMSStoreKeys_stA[l_iteration_U8].KeyGenus_U8;
                if ((CERTIFICATE == l_keygenus_U8) || (DATA == l_keygenus_U8))
                {
                    l_retVal_e = vHsmCrypt_Hmac_Sha2_256(&l_hashkey_U8A[0], 1, &l_vHsmVKMSStoreKeys_stA[l_iteration_U8].Key_Payload_U8[0],
                                                    l_vHsmVKMSStoreKeys_stA[l_iteration_U8].KeyLength_U16, &l_hashdump_U8A[0],
                                                    vHsmCrypt_Sha256SW);
                }
                else
                {
                    (void)memcpy(&l_KeymetadataRam_U8A[0], (uint8*)&l_vHsmVKMSStoreKeys_stA[l_iteration_U8].KeyTypeId_U16, 2);
                    HSM_VKMS_InvertEndianness((uint8 *)&l_KeymetadataRam_U8A[0], 2);
                    (void)memcpy(&l_KeymetadataRam_U8A[2], (uint8*)&l_vHsmVKMSStoreKeys_stA[l_iteration_U8].TypeTrainingCounter_U16, 2);
                    HSM_VKMS_InvertEndianness((uint8 *)&l_KeymetadataRam_U8A[2], 2);
                    l_KeymetadataRam_U8A[4] = l_keygenus_U8;
                    l_KeymetadataRam_U8A[5] = l_keyflag_U8;
                    if ((ABSTARCT_KEY & l_keyflag_U8) == ABSTARCT_KEY)
                    {
                        l_retVal_e = vHsmCrypt_Hmac_Sha2_256(&l_hashkey_U8A[0], 1, &l_KeymetadataRam_U8A[0], 6,
                                                            &l_hashdump_U8A[0], vHsmCrypt_Sha256SW);
                    }
                    else
                    {
                        l_retVal_e = vHsmCrypt_Hmac_Sha2_256(&l_vHsmVKMSStoreKeys_stA[l_iteration_U8].Key_Payload_U8[0], l_vHsmVKMSStoreKeys_stA[l_iteration_U8].KeyLength_U16,
                                                                &l_KeymetadataRam_U8A[0], 6, &l_hashdump_U8A[0],
                                                                vHsmCrypt_Sha256SW);
                    }
                }
                if (0 == l_iteration_U8)
                {
                    for (l_itercount_U8 = 0; l_itercount_U8 < DLC_HASHLEN; l_itercount_U8++)
                    {
                        l_hashptr_U8A[l_itercount_U8] = l_hashdump_U8A[l_itercount_U8];
                    }
                }
                else
                {
                    for (l_itercount_U8 = 0; l_itercount_U8 < DLC_HASHLEN; l_itercount_U8++)
                    {
                        l_hashptr_U8A[l_itercount_U8] ^= l_hashdump_U8A[l_itercount_U8];
                    }
                }
            }
            else
            {
                l_retVal_e = E_OK;
            }
            if(E_OK == l_retVal_e)
            {
                (void)memcpy(p_HashPtr_pU8, &l_hashptr_U8A[0], DLC_HASHLEN);
                l_RetVal_E = VKMS_ERR_NONE;
            }          
        }
    }
    else
    {
        /*do nothing*/
    }
    return l_RetVal_E;
}


/* ENd  Hash Verfication for */
/**
 * @brief Computes the overall DLC verification hash.
 *
 * Obtains the DLC hash and key hash via HSM_VKMS_DLChash and
 * HSM_VKMS_Keyhash, then XORs them byte-by-byte to produce the
 * 16-byte verification checksum.
 *
 * @param[out] p_VerHashPtr_pU8  Buffer to receive the 16-byte verification hash.
 *
 * @return VKMS_ERR_NONE         Hash computed successfully.
 * @return VKMS_E_PARAM_POINTER  NULL output pointer.
 */
FUNC(te_VKMS_ErrorType, VKMS_CODE) HSM_VKMS_getVerificationHash(uint8* p_VerHashPtr_pU8)
{
    te_VKMS_ErrorType l_retVal_E                  = VKMS_ERR_GENERAL;  
    uint8             l_counter_U8                = 0u;
    if (NULL == p_VerHashPtr_pU8)
    {
        l_retVal_E = VKMS_E_PARAM_POINTER;
    }
    else
    { 
        l_retVal_E = HSM_VKMS_DLChash(&l_DlcHash_U8A[0]);
        if (VKMS_ERR_NONE == l_retVal_E)
        {
            l_retVal_E = HSM_VKMS_Keyhash(&l_keyhash_U8A[0]);
            if (VKMS_ERR_NONE == l_retVal_E)
            {
                for (l_counter_U8 = 0; l_counter_U8 < DLC_HASHLEN; l_counter_U8++)
                {
                    l_hashtmp_U8A[l_counter_U8] = l_DlcHash_U8A[l_counter_U8] ^ l_keyhash_U8A[l_counter_U8];
                }
                (void)memcpy(p_VerHashPtr_pU8, (uint8 *)&l_hashtmp_U8A[0], 16);
            }
        }
        else
        {
            /* do nothing*/
        }            
    }
    return l_retVal_E;
}

/**
 * @brief Computes the DLC hash from flash-stored DLC metadata.
 *
 * HMAC-SHA-256 hashes the DLC metadata fields (EcuTrainingCounter,
 * EcuGrpVIN, MasterKeyGrpId, IdentityCounter) from flash. In
 * non-provisioned or reset states a hardcoded default array is used.
 *
 * @param[out] p_DlcHashPtr_pU8  Buffer to receive the 32-byte DLC hash.
 *
 * @return VKMS_ERR_NONE            Hash computed successfully.
 * @return VKMS_ERR_HW_CRYPTO_OTHER DLC pointer retrieval failed.
 */
LOCAL FUNC(te_VKMS_ErrorType, VKMS_CODE) HSM_VKMS_DLChash(uint8* p_DlcHashPtr_pU8)
{
    te_VKMS_ErrorType l_RetVal_E                                     = VKMS_ERR_GENERAL;
    Std_ReturnType    fl_RetVal_E                                    = E_NOT_OK;
    uint8             l_MetaDataHashVer_U8A[DLC_METADATA_HASHLENGTH] = {0};
    uint8             l_keydata_U8A[1]                               = {0};
    uint8             l_dlcdatanprov_U8A[24] = {0x00, 0x00, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D,
                                    0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    uint8             l_hashout_U8A[32] = {0};
    ts_VKMSDLCDataType_st* l_Dlchash_st = NULL;
    if (NULL == p_DlcHashPtr_pU8)
    {
        l_RetVal_E = VKMS_E_PARAM_POINTER;
    }
    else if((e_VKMS_Provisioned_Normal == l_vHsmVKMSProvisionState_e) || (e_VKMS_Provisioned_Limited == l_vHsmVKMSProvisionState_e))
    {
        l_Dlchash_st = vHsmVKMS_GetDLC();
        if(l_Dlchash_st != NULL)
        {
            (void)memcpy(&l_MetaDataHashVer_U8A[0], (uint8*)&l_Dlchash_st->EcuTrainingCounter_U16, 2);
            HSM_VKMS_InvertEndianness((uint8 *)&l_MetaDataHashVer_U8A[0], 2);
            (void)memcpy(&l_MetaDataHashVer_U8A[2], &l_Dlchash_st->EcuGrpVIN_U8A[0], 17);
            (void)memcpy(&l_MetaDataHashVer_U8A[19], &l_Dlchash_st->MasterKeyGrpId_U8A[0], 3);
            (void)memcpy(&l_MetaDataHashVer_U8A[22], (uint8*)&l_Dlchash_st->IdentityCounter_U16, 2);
            HSM_VKMS_InvertEndianness((uint8 *)&l_MetaDataHashVer_U8A[22], 2);
            fl_RetVal_E = vHsmCrypt_Hmac_Sha2_256(&l_keydata_U8A[0], 1, &l_MetaDataHashVer_U8A[0],
                                                DLC_METADATA_HASHLENGTH, &l_hashout_U8A[0], vHsmCrypt_Sha256SW);
            if (E_OK == fl_RetVal_E)
            {
                l_RetVal_E = VKMS_ERR_NONE;
                (void)memcpy(p_DlcHashPtr_pU8,&l_hashout_U8A[0],16);
            }
            else
            {

            }
        }
        else
        {
            l_RetVal_E = VKMS_ERR_HW_CRYPTO_OTHER;
        }
    }
    else /*reset DLC or Unprovisioned*/
    {
        fl_RetVal_E = vHsmCrypt_Hmac_Sha2_256(&l_keydata_U8A[0], 1, &l_dlcdatanprov_U8A[0], DLC_METADATA_HASHLENGTH,
                                                &l_hashout_U8A[0], vHsmCrypt_Sha256SW);
        if (E_OK == fl_RetVal_E)
        {
            l_RetVal_E = VKMS_ERR_NONE;
            (void)memcpy(p_DlcHashPtr_pU8,&l_hashout_U8A[0],16);
        }
        else
        {
        }
    }
    return l_RetVal_E;
}
/**
 * @brief Computes a combined key hash from all flash-stored keys.
 *
 * Iterates over configured keys, reading each from flash and computing
 * an HMAC-SHA-256 per key (over payload or metadata depending on genus).
 * Individual hashes are XOR-combined; in non-provisioned states only
 * the PSS key is hashed.
 *
 * @param[out] p_HashPtr_pU8  Buffer to receive the 16-byte combined key hash.
 *
 * @return E_OK      Hash computed successfully.
 * @return E_NOT_OK  NULL pointer or crypto failure.
 */
LOCAL FUNC(te_VKMS_ErrorType, VKMS_CODE) HSM_VKMS_Keyhash(uint8* p_HashPtr_pU8)
{
    Std_ReturnType         l_KeyPresent_E = E_NOT_OK;
    Std_ReturnType         l_retVal_e     = E_NOT_OK;
    te_VKMS_ErrorType      l_RetVal_E     = VKMS_ERR_GENERAL;
    uint8                  l_iteration_U8 = 0u;
    uint8                  l_keygenus_U8  = 0u;
    uint8                  l_keyflag_U8   = 0u;
    uint16                 l_keyId_U16 = 0u;
    uint8                  l_hashkey_U8A[1]  = {0};
    uint8                  l_Keymetadata_U8A[6] = {0};
    uint8                  l_itercount_U8 = 0u;
    ts_VKMSKeyDataType_st* l_keyhash_st;
    if (NULL == p_HashPtr_pU8)
    {
        l_RetVal_E = VKMS_E_PARAM_POINTER;
    }
    else if ((e_VKMS_Provisioned_Normal == l_vHsmVKMSProvisionState_e) || (e_VKMS_Provisioned_Limited == l_vHsmVKMSProvisionState_e))
    {
        for (l_iteration_U8 = 0u; l_iteration_U8 < MAX_CONFIGURED_KEYS; l_iteration_U8++)
        {
            l_keyId_U16   = l_vHsmVKMSKeyConfigArray_stA[l_iteration_U8].KeyId_U16;
            l_keyhash_st  = vHsmVKMS_GetKey(l_keyId_U16, &l_KeyPresent_E);
            if((E_OK == l_KeyPresent_E) && (l_keyhash_st->TypeTrainingCounter_U16 != 0u))
            {
                l_keyflag_U8  = l_keyhash_st->KeyFlags_U8;
                l_keygenus_U8 = l_keyhash_st->KeyGenus_U8;
                if ((CERTIFICATE == l_keygenus_U8) || (DATA == l_keygenus_U8))
                {
                    if((l_keyhash_st->Key_Payload_U8P) != 0u)
                    {
                        l_retVal_e = vHsmCrypt_Hmac_Sha2_256(&l_hashkey_U8A[0], 1, l_keyhash_st->Key_Payload_U8P,
                                                        l_keyhash_st->KeyLength_U16, &l_hashdump_U8A[0],
                                                        vHsmCrypt_Sha256SW);
                    }

                }
                else
                {
                    (void)memcpy(&l_Keymetadata_U8A[0], (uint8*)&l_keyId_U16, 2u);
                    HSM_VKMS_InvertEndianness((uint8 *)&l_Keymetadata_U8A[0], 2u);
                    (void)memcpy(&l_Keymetadata_U8A[2], (uint8*)&l_keyhash_st->TypeTrainingCounter_U16, 2u);
                    HSM_VKMS_InvertEndianness((uint8 *)&l_Keymetadata_U8A[2], 2u);
                    l_Keymetadata_U8A[4] = l_keygenus_U8;
                    l_Keymetadata_U8A[5] = l_keyflag_U8;
                    if ((ABSTARCT_KEY & l_keyflag_U8) == ABSTARCT_KEY)
                    {
                        l_retVal_e = vHsmCrypt_Hmac_Sha2_256(&l_hashkey_U8A[0], 1, &l_Keymetadata_U8A[0], 6u,
                                                            &l_hashdump_U8A[0], vHsmCrypt_Sha256SW);
                    }
                    else
                    {
                        if((l_keyhash_st->Key_Payload_U8P) != 0u)
                        {
                            l_retVal_e = vHsmCrypt_Hmac_Sha2_256(l_keyhash_st->Key_Payload_U8P, l_keyhash_st->KeyLength_U16,
                                                                &l_Keymetadata_U8A[0], 6, &l_hashdump_U8A[0],
                                                                vHsmCrypt_Sha256SW);
                        }

                    }
                }
                if (0u == l_iteration_U8)
                {
                    for (l_itercount_U8 = 0u; l_itercount_U8 < DLC_HASHLEN; l_itercount_U8++)
                    {
                        l_hashptr_U8A[l_itercount_U8] = l_hashdump_U8A[l_itercount_U8];
                    }
                }
                else
                {
                    for (l_itercount_U8 = 0u; l_itercount_U8 < DLC_HASHLEN; l_itercount_U8++)
                    {
                        l_hashptr_U8A[l_itercount_U8] ^= l_hashdump_U8A[l_itercount_U8];
                    }
                }
            }
            else
            {
                l_retVal_e = E_OK; /*For Missing Keys*/
            }
        }
        (void)memcpy(p_HashPtr_pU8, &l_hashptr_U8A[0], DLC_HASHLEN);                   
    }
    else
    {
        l_keyhash_st  = vHsmVKMS_GetKey(PSS_KEYID, &l_KeyPresent_E);
        if(E_OK == l_KeyPresent_E)
        {
            l_Keymetadata_U8A[0] = 0x00u;
            l_Keymetadata_U8A[1] = 0x01u;
            l_Keymetadata_U8A[2] = 0x00u;
            l_Keymetadata_U8A[3] = 0x00u;
            l_Keymetadata_U8A[4] = 0x12u;
            l_Keymetadata_U8A[5] = 0u;
            if((l_keyhash_st->Key_Payload_U8P) != 0)
            {
                l_retVal_e = vHsmCrypt_Hmac_Sha2_256(l_keyhash_st->Key_Payload_U8P, l_keyhash_st->KeyLength_U16,    
                                                &l_Keymetadata_U8A[0], 6, p_HashPtr_pU8, vHsmCrypt_Sha256SW);
            }
        }
    }
    if(E_OK == l_retVal_e)
    {
        l_RetVal_E = VKMS_ERR_NONE;
    }
    return l_RetVal_E;
}

/**
 * @brief Calculates the total byte length of a DLC key section.
 *
 * Sums DLC_METADATA_LEN, the metadata+payload size for each key,
 * and DLC_HASHLEN for the MAC tag.
 *
 * @param[in] p_NoofKeys_U8  Number of keys in the DLC.
 *
 * @return Total DLC length in bytes.
 */
LOCAL FUNC(uint32, VKMS_CODE) HSM_VKMS_KEY_DLCLEN(uint8 p_NoofKeys_U8)
{
    uint32 fl_DlcLen_U32 = 0u;
    uint8 l_Keyflag_U8 = 0u;
    uint32 l_keymetadatasize_U32 = 0u;
    for(l_Keyflag_U8 = 0u; l_Keyflag_U8 < p_NoofKeys_U8; l_Keyflag_U8 ++)
    {
        l_keymetadatasize_U32 += (KEYCONSTDATA_LEN + l_vHsmVKMSKeyConfigArray_stA[l_Keyflag_U8].KeySize_U16);
    }
    fl_DlcLen_U32 = DLC_METADATA_LEN + l_keymetadatasize_U32 + DLC_HASHLEN;
    return fl_DlcLen_U32;
}


/**
 * @brief Retrieves the ECU training counter from the stored DLC.
 *
 * In Provisioned_Normal state reads the counter from flash. For Limited,
 * Reset, or NotProvisioned states returns 0.
 *
 * @param[out] p_TrainingCounterPtr_pU16  Buffer to receive the training counter.
 *
 * @return VKMS_ERR_NONE         Counter retrieved successfully.
 * @return VKMS_ERR_BUSY         VKMS state machine not idle.
 * @return VKMS_E_PARAM_POINTER  NULL output pointer.
 * @return VKMS_ERR_HW_CRYPTO_OTHER DLC read failure.
 */
FUNC(te_VKMS_ErrorType, VKMS_CODE) HSM_VKMS_getTrainingCounter(uint16* p_TrainingCounterPtr_pU16)
{
    te_VKMS_ErrorType          l_RetVal_E       = VKMS_ERR_GENERAL;
    te_VKMS_ProvisionStateType l_ProvisionState = l_vHsmVKMSProvisionState_e;
    ts_VKMSDLCDataType_st*     l_Dlc_st;
    uint16                     l_ECUcounter_U16 = 0;
    if (e_VKMS_Idle != CurrentVKMSState_U8)
    {
        l_RetVal_E = VKMS_ERR_BUSY;
    }
    else if(NULL == p_TrainingCounterPtr_pU16)
    {
        l_RetVal_E = VKMS_E_PARAM_POINTER;
    }
    else if ((e_VKMS_Provisioned_Normal == l_ProvisionState) || (e_VKMS_Provisioned_Limited == l_ProvisionState))
    {
        l_Dlc_st = vHsmVKMS_GetDLC();
        if (NULL != l_Dlc_st)
        {
            l_ECUcounter_U16 = l_Dlc_st->EcuTrainingCounter_U16;
            l_RetVal_E       = VKMS_ERR_NONE;
        }
        else
        {
            l_RetVal_E = VKMS_ERR_HW_CRYPTO_OTHER;
        }
    }
    else
    {
        l_ECUcounter_U16 = 0u; /* Reset DLC or Not Provisioned*/  
        l_RetVal_E = VKMS_ERR_NONE;
    }
    if(VKMS_ERR_NONE == l_RetVal_E)
    {
        (void)memcpy((uint8*)p_TrainingCounterPtr_pU16, (uint8*)&l_ECUcounter_U16, 2);
    }
    return l_RetVal_E;
}
/**
 * @brief Retrieves the 17-byte ECU group VIN from the stored DLC.
 *
 * In Provisioned_Normal state copies the VIN from flash. For all other
 * states fills the buffer with 0x2D (dash) characters.
 *
 * @param[out] p_BuffPtr_pU8  Buffer to receive the 17-byte VIN.
 *
 * @return VKMS_ERR_NONE         VIN retrieved successfully.
 * @return VKMS_ERR_BUSY         VKMS state machine not idle.
 * @return VKMS_E_PARAM_POINTER  NULL output pointer.
 * @return VKMS_ERR_HW_CRYPTO_OTHER DLC read failure.
 */
FUNC(te_VKMS_ErrorType, VKMS_CODE) HSM_VKMS_getVkmsVIN(uint8* p_BuffPtr_pU8)
{
    te_VKMS_ErrorType          l_RetVal_E       = VKMS_ERR_GENERAL;
    ts_VKMSDLCDataType_st*     l_Dlc_st;
    uint8                      l_Vin_U8A[BYTE17] = {0};
    if (e_VKMS_Idle != CurrentVKMSState_U8)
    {
        l_RetVal_E = VKMS_ERR_BUSY;
    }
    else if(NULL == p_BuffPtr_pU8)
    {
        l_RetVal_E = VKMS_E_PARAM_POINTER;
    }
    else if (e_VKMS_Provisioned_Normal == l_vHsmVKMSProvisionState_e)
    {
        l_Dlc_st = vHsmVKMS_GetDLC();
        if (NULL != l_Dlc_st)
        {
            (void)memcpy(&l_Vin_U8A[0], &l_Dlc_st->EcuGrpVIN_U8A[0], BYTE17);
            l_RetVal_E = VKMS_ERR_NONE;
        }
        else
        {
            l_RetVal_E = VKMS_ERR_HW_CRYPTO_OTHER;
        }
    }
    else /* TO be checked Limited mode during check sum failed DLC download*/
    {
        (void)memset(&l_Vin_U8A[0], 0x2D, BYTE17);
        l_RetVal_E = VKMS_ERR_NONE;
    }
    if(VKMS_ERR_NONE == l_RetVal_E)
    {
        (void)memcpy(p_BuffPtr_pU8, &l_Vin_U8A[0], BYTE17);
    }
    return l_RetVal_E;
}


/**
 * @brief Computes a debug signature via HMAC-SHA-256 using the PSS key.
 *
 * Takes an input buffer and produces a 32-byte HMAC-SHA-256 signature.
 * Validates VKMS state (must be idle), pointers, and output buffer size
 * before proceeding.
 *
 * @param[in]  p_inputBuff_pU8   Pointer to the input data to sign.
 * @param[in]  p_inputLen_U32    Length of the input data.
 * @param[out] p_BuffPtr_pU8     Buffer to receive the 32-byte signature.
 * @param[in,out] p_DataLen_pU32 On input: capacity of output buffer.
 *                               On output: number of bytes written (32).
 *
 * @return VKMS_ERR_NONE         Signature computed successfully.
 * @return VKMS_E_PARAM_POINTER  NULL pointer argument.
 * @return VKMS_ERR_GENERAL      Invalid output buffer size or input length.
 * @return VKMS_ERR_BUSY         VKMS state machine not idle.
 */
FUNC(te_VKMS_ErrorType, VKMS_CODE) HSM_VKMS_DebugSignCalc(uint8* p_inputBuff_pU8, uint32 p_inputLen_U32,uint8* p_BuffPtr_pU8, uint32* p_DataLen_pU32)
{
    te_VKMS_ErrorType fl_RetVal_E = VKMS_ERR_GENERAL;
    Std_ReturnType l_hmacRet_E = E_NOT_OK;
    Std_ReturnType l_KeyPresent_E = E_NOT_OK;
    ts_VKMSKeyDataType_st* l_SigPSS_St;
    uint32 l_InputLen_U32 = 0u;
    uint8 l_SignPssKey_U8A[32] = {0};
    if((NULL == p_BuffPtr_pU8) || (p_inputBuff_pU8 == NULL))
    {
        fl_RetVal_E = VKMS_E_PARAM_POINTER;
    }
    else if ((VKMS_DEBUG_SIGNLEN != (*p_DataLen_pU32)) && (0u == p_inputLen_U32))
    {
        fl_RetVal_E = VKMS_ERR_GENERAL;
    }
    else if (CurrentVKMSState_U8 != e_VKMS_Idle)
    {
        fl_RetVal_E = VKMS_ERR_BUSY;
    }
    else
    {
        l_InputLen_U32 = p_inputLen_U32;
        CurrentVKMSState_U8 = e_VKMS_WORK;
        l_SigPSS_St = vHsmVKMS_GetKey(PSS_KEYID, &l_KeyPresent_E);
        if(E_OK == l_KeyPresent_E)
        {
            (void)memcpy(&l_SignPssKey_U8A[0], l_SigPSS_St->Key_Payload_U8P, DLCVER1_KEYLEN);
            (void)memcpy(&l_signin_U8A[0], p_inputBuff_pU8, l_InputLen_U32);
            l_hmacRet_E =
                vHsmCrypt_Hmac_Sha2_256(&l_SignPssKey_U8A[0], DLCVER1_KEYLEN, &l_signin_U8A[0], l_InputLen_U32, p_BuffPtr_pU8,
                                        vHsmCrypt_Sha256SW);
            if (E_OK == l_hmacRet_E)
            {
                fl_RetVal_E = VKMS_ERR_NONE;
                *p_DataLen_pU32 = 32u;
            }
            else
            {
                /* Do nothing*/
            }
        } 
        CurrentVKMSState_U8 = e_VKMS_Idle;
    }
    return fl_RetVal_E;
}

/**
 * @brief Reads and decrypts a key from flash storage by KeyId.
 *
 * Maps KeyId to an internal index via vHsmVKMSKEYMAP, reads the encrypted
 * key from the flash key storage, decrypts it with vHsmBlob_DecryptKey,
 * and returns a pointer to the decrypted key.
 *
 * @param[in]  KeyId              VKMS key identifier to read.
 * @param[out] p_recPresent_Ptr   Set to E_OK if key is present and decrypted,
 *                                E_NOT_OK otherwise.
 *
 * @return Pointer to the decrypted ts_VKMSKeyDataType_st structure.
 *         KeyIdLocated_bool is TRUE on success.
 */
LOCAL FUNC (ts_VKMSKeyDataType_st, VKMS_CODE) * vHsmVKMS_GetKey(uint16 KeyId, Std_ReturnType *p_recPresent_Ptr)
{
    uint8 l_KeyIntId = 0u;
    ts_VKMSKeyDataType_st *fl_ret_Ptr = NULL;
    *p_recPresent_Ptr = E_NOT_OK;
    l_KeyIntId = vHsmVKMSKEYMAP(KeyId);
    if(MAX_CONFIGURED_KEYS > l_KeyIntId)
    {
        if(1u == l_vHsmVKMSKeyFlash_ts.VKMSKeys_st[l_KeyIntId].KeyValid)
        {
            l_vHsmLocalKey_st.KeyFlags_U8 = l_vHsmVKMSKeyFlash_ts.VKMSKeys_st[l_KeyIntId].key.KeyFlags_U8;
            l_vHsmLocalKey_st.KeyGenus_U8 = l_vHsmVKMSKeyFlash_ts.VKMSKeys_st[l_KeyIntId].key.KeyGenus_U8;
            l_vHsmLocalKey_st.KeyLength_U16 = l_vHsmVKMSKeyFlash_ts.VKMSKeys_st[l_KeyIntId].key.KeyLength_U16;
            l_vHsmLocalKey_st.KeyTypeId_U16 = l_vHsmVKMSKeyFlash_ts.VKMSKeys_st[l_KeyIntId].key.KeyTypeId_U16;
            l_vHsmLocalKey_st.TypeTrainingCounter_U16 = l_vHsmVKMSKeyFlash_ts.VKMSKeys_st[l_KeyIntId].key.TypeTrainingCounter_U16;
            if(E_OK == vHsmBlob_DecryptKey(&l_vHsmVKMSKeyFlash_ts.VKMSKeys_st[l_KeyIntId].key.Key_Payload_U8[0],l_vHsmVKMSKeyConfigArray_stA[l_KeyIntId].KeyconfSize,&l_LocalKeyBuffer_U8A[0],&l_vHsmVKMSKeyFlash_ts.VKMSKeys_st[l_KeyIntId].keyTag[0]))
            {
                l_vHsmLocalKey_st.Key_Payload_U8P = &l_LocalKeyBuffer_U8A[0];
                l_vHsmLocalKey_st.KeyIdLocated_bool = TRUE;
                *p_recPresent_Ptr = E_OK;
            }
            else
            {
                l_vHsmLocalKey_st.KeyIdLocated_bool = FALSE;
            }
        }
    }
    fl_ret_Ptr = &l_vHsmLocalKey_st;
    return(fl_ret_Ptr);
}

/**
 * @brief Reads and decrypts the DLC from flash storage.
 *
 * If DLCValid is set, decrypts the DLCData field using vHsmBlob_DecryptKey.
 * Returns a pointer to the authenticated DLC structure, or NULL on failure.
 *
 * @return Pointer to the decrypted ts_VKMSDLCDataType_st, or NULL.
 */
LOCAL FUNC(ts_VKMSDLCDataType_st,VKMS_CODE) * vHsmVKMS_GetDLC(void)
{
    ts_VKMSDLCDataType_st *fl_retVal_stP = &l_VKMS_DLC_Rd_Auth_st;
    if(1u == l_vHsmVKMSDlcSlot_ts.DLCValid)
    {
        /* After check for DLC authentication*/
        if(E_OK != vHsmBlob_DecryptKey((uint8*)&l_vHsmVKMSDlcSlot_ts.DLCData,sizeof(l_vHsmVKMSDlcSlot_ts.DLCData),(uint8*)&l_VKMS_DLC_Rd_Auth_st,&l_vHsmVKMSDlcSlot_ts.DLCTag[0]))
        {
            VKMS_print("\r\n vHsmVKMS_GetDLC Error");
            fl_retVal_stP = NULL;
        }
    }
    else
    {
        (void)memset((uint8*)&l_VKMS_DLC_Rd_Auth_st,0x00,sizeof(l_VKMS_DLC_Rd_Auth_st));
    }
    return (fl_retVal_stP);
}

/**
 * @brief Copies a skipped key from flash storage into the in-RAM store.
 *
 * A skipped key is one not present in the incoming DLC. Logically delete
 * the key.
 *
 * @param[in] KeyID  VKMS key identifier to preserve.
 *
 * @return VKMS_ERR_NONE Key copied successfully.
 */
static FUNC(te_VKMS_ErrorType,VKMS_CODE) vHsmVKMS_SetSkippedKey(const uint16 KeyID)
{
    te_VKMS_ErrorType fl_retVal_E = VKMS_ERR_GENERAL;
    uint8 l_LocalKeyId_U8 = vHsmVKMSKEYMAP(KeyID);
    Std_ReturnType l_KeyPresent_E = E_NOT_OK;
    ts_VKMSKeyDataType_st * l_LocalSkippedKey_st;
    if(MAX_CONFIGURED_KEYS > l_LocalKeyId_U8)
    {
        l_LocalSkippedKey_st = vHsmVKMS_GetKey(KeyID,&l_KeyPresent_E);
        if(l_KeyPresent_E == E_OK)
        {
            if(KeyID != PSS_KEYID)
            {
                l_vHsmVKMSStoreKeys_stA[l_LocalKeyId_U8].KeyFlags_U8 = l_LocalSkippedKey_st->KeyFlags_U8;
                l_vHsmVKMSStoreKeys_stA[l_LocalKeyId_U8].KeyGenus_U8 = l_LocalSkippedKey_st->KeyGenus_U8;
            }
            l_vHsmVKMSStoreKeys_stA[l_LocalKeyId_U8].KeyLength_U16 = l_LocalSkippedKey_st->KeyLength_U16;
            l_vHsmVKMSStoreKeys_stA[l_LocalKeyId_U8].KeyTypeId_U16 = l_LocalSkippedKey_st->KeyTypeId_U16;
            l_vHsmVKMSStoreKeys_stA[l_LocalKeyId_U8].TypeTrainingCounter_U16 = 0u;
            (void)memcpy(&l_vHsmVKMSStoreKeys_stA[l_LocalKeyId_U8].Key_Payload_U8[0],l_LocalSkippedKey_st->Key_Payload_U8P,l_vHsmVKMSStoreKeys_stA[l_LocalKeyId_U8].KeyLength_U16);
            fl_retVal_E = VKMS_ERR_NONE;
        }
    }
    return fl_retVal_E;
}

/**
 * @brief Looks up a parent key in the in-RAM store keys array.
 *
 * Maps keyID to an internal index and returns a pointer to the key
 * structure from the RAM store. Sets KeyIdLocated_bool to FALSE if
 * the training counter is zero or the key ID is not mapped.
 *
 * @param[in]  keyID             Key identifier of the parent key.
 * @param[out] p_recPresent_Ptr  Set to E_OK if found, E_NOT_OK otherwise.
 *
 * @return Pointer to the parent ts_VKMSKeyDataType_st, or NULL.
 */
static FUNC (ts_VKMSKeyDataType_st , VKMS_CODE) * vHsmVKMS_GetParent(uint16 keyID,Std_ReturnType *p_recPresent_Ptr)
{
    ts_VKMSKeyDataType_st *fl_retVal_stP = NULL;
    uint8 l_KeyIntId_U8 = vHsmVKMSKEYMAP(keyID);
    *p_recPresent_Ptr = E_NOT_OK;
    if(MAX_CONFIGURED_KEYS > l_KeyIntId_U8)
    {
        l_vHsmParentKey_st.KeyIdLocated_bool = FALSE;
        if(0u != l_vHsmVKMSStoreKeys_stA[l_KeyIntId_U8].KeyTypeId_U16)
        {
            l_vHsmParentKey_st.KeyFlags_U8 = l_vHsmVKMSStoreKeys_stA[l_KeyIntId_U8].KeyFlags_U8;
            l_vHsmParentKey_st.KeyGenus_U8 = l_vHsmVKMSStoreKeys_stA[l_KeyIntId_U8].KeyGenus_U8;
            l_vHsmParentKey_st.KeyLength_U16 = l_vHsmVKMSStoreKeys_stA[l_KeyIntId_U8].KeyLength_U16;
            l_vHsmParentKey_st.KeyTypeId_U16 = l_vHsmVKMSStoreKeys_stA[l_KeyIntId_U8].KeyTypeId_U16;
            l_vHsmParentKey_st.TypeTrainingCounter_U16 = l_vHsmVKMSStoreKeys_stA[l_KeyIntId_U8].TypeTrainingCounter_U16;
            l_vHsmParentKey_st.Key_Payload_U8P = &l_vHsmVKMSStoreKeys_stA[l_KeyIntId_U8].Key_Payload_U8[0];
            l_vHsmParentKey_st.KeyIdLocated_bool = TRUE;
            *p_recPresent_Ptr = E_OK;
        }
    }
    fl_retVal_stP = &l_vHsmParentKey_st;
    return fl_retVal_stP;
}

/**
 * @brief Encrypts and writes all in-RAM store keys to flash.
 *
 * Iterates over each key in l_vHsmVKMSStoreKeys_stA, encrypts the payload
 * with vHsmBlob_Encryptkey, populates the flash key storage structure,
 * updates KeyHeader/KeyFooter integrity markers, erases the key flash
 * sector, and writes the complete key data.
 *
 * @return VKMS_ERR_NONE               Keys written successfully.
 * @return VKMS_ERR_HW_CRYPTO_OTHER    Encryption failure.
 * @return VKMS_ERR_HW_KEY_WRITE_FAIL  Flash erase or write failure.
 */
LOCAL FUNC(te_VKMS_ErrorType,VKMS_CODE) Set_VKMSKeys(void)
{
    te_VKMS_ErrorType fl_RetVal_E = VKMS_ERR_NONE;
    Std_ReturnType retVal = E_NOT_OK;
    uint8 l_KeyIndex_U8 = 0u;
    for(l_KeyIndex_U8 = 0u;l_KeyIndex_U8 < MAX_CONFIGURED_KEYS;l_KeyIndex_U8++)
    {
        l_vHsmVKMSKeyFlash_ts.VKMSKeys_st[l_KeyIndex_U8].KeyMarker = VKMSKEYMARKER;
        l_vHsmVKMSKeyFlash_ts.VKMSKeys_st[l_KeyIndex_U8].key.KeyFlags_U8 = l_vHsmVKMSStoreKeys_stA[l_KeyIndex_U8].KeyFlags_U8;
        l_vHsmVKMSKeyFlash_ts.VKMSKeys_st[l_KeyIndex_U8].key.KeyGenus_U8 = l_vHsmVKMSStoreKeys_stA[l_KeyIndex_U8].KeyGenus_U8;
        l_vHsmVKMSKeyFlash_ts.VKMSKeys_st[l_KeyIndex_U8].key.KeyLength_U16 = l_vHsmVKMSStoreKeys_stA[l_KeyIndex_U8].KeyLength_U16;
        l_vHsmVKMSKeyFlash_ts.VKMSKeys_st[l_KeyIndex_U8].key.KeyTypeId_U16 = l_vHsmVKMSStoreKeys_stA[l_KeyIndex_U8].KeyTypeId_U16;
        l_vHsmVKMSKeyFlash_ts.VKMSKeys_st[l_KeyIndex_U8].key.TypeTrainingCounter_U16 = l_vHsmVKMSStoreKeys_stA[l_KeyIndex_U8].TypeTrainingCounter_U16;
        if((l_ResetFlag_U8 == 1u) && (l_KeyIndex_U8 != 0u))
        {
            l_vHsmVKMSKeyFlash_ts.VKMSKeys_st[l_KeyIndex_U8].key.TypeTrainingCounter_U16 = 0u;
        }
        l_vHsmVKMSKeyFlash_ts.VKMSKeys_st[l_KeyIndex_U8].KeyValid = 1u;
        if(E_OK != vHsmBlob_Encryptkey(&l_vHsmVKMSStoreKeys_stA[l_KeyIndex_U8].Key_Payload_U8[0],l_vHsmVKMSKeyConfigArray_stA[l_KeyIndex_U8].KeyconfSize,&l_vHsmVKMSKeyFlash_ts.VKMSKeys_st[l_KeyIndex_U8].key.Key_Payload_U8[0],&l_vHsmVKMSKeyFlash_ts.VKMSKeys_st[l_KeyIndex_U8].keyTag[0]))
        {
            fl_RetVal_E = VKMS_ERR_HW_CRYPTO_OTHER;
            break;
        }
    }
    if(VKMS_ERR_HW_CRYPTO_OTHER != fl_RetVal_E)
    {
        /* Implement Flash Erase and Write Logic here*/
        if((l_vHsmVKMSKeyFlash_ts.KeyHeader == 0xFFFFFFFFu) || (l_vHsmVKMSKeyFlash_ts.KeyHeader == 0x11223344u))
        {
            l_vHsmVKMSKeyFlash_ts.KeyHeader = 0u;
        }
        else
        {
            l_vHsmVKMSKeyFlash_ts.KeyHeader += 1u;
        }
        l_vHsmVKMSKeyFlash_ts.KeyFooter = VKMSMAGICFLAG ^ l_vHsmVKMSKeyFlash_ts.KeyHeader;
        retVal = Fls_Erase(KEY_STORAGE_ADDRESS,0x1000u);
        if(E_OK == retVal)
        {
            retVal = Fls_Write(KEY_STORAGE_ADDRESS,(uint8 *)&l_vHsmVKMSKeyFlash_ts,sizeof(l_vHsmVKMSKeyFlash_ts));
        }
        if(E_OK == retVal) /*Reduntant Sector Write*/
        {
            l_vHsmVKMSKeyFlash_ts.KeyHeader += 1u;
            l_vHsmVKMSKeyFlash_ts.KeyFooter = VKMSMAGICFLAG ^ l_vHsmVKMSKeyFlash_ts.KeyHeader;
            retVal = Fls_Erase(KEY_STORAGE1_ADDRESS,0x1000u);
            if(E_OK == retVal)
            {
                retVal = Fls_Write(KEY_STORAGE1_ADDRESS,(uint8 *)&l_vHsmVKMSKeyFlash_ts,sizeof(l_vHsmVKMSKeyFlash_ts));
            }
        }
        if(retVal != E_OK)
        {
            fl_RetVal_E = VKMS_ERR_HW_KEY_WRITE_FAIL;
            VKMS_print("\r\n VKMS_ERR_HW_KEY_WRITE_FAIL");
        }
    }
    return fl_RetVal_E;
}

/**
 * @brief Encrypts and writes the current DLC to flash.
 *
 * Encrypts l_CurrentDLC_st with vHsmBlob_Encryptkey, updates the
 * DLCCounter/DLCMarker integrity fields, erases the DLC flash sector,
 * and writes the complete DLC slot data.
 *
 * @return VKMS_ERR_NONE               DLC written successfully.
 * @return VKMS_ERR_HW_CRYPTO_OTHER    Encryption failure.
 * @return VKMS_ERR_HW_KEY_WRITE_FAIL  Flash erase or write failure.
 */
LOCAL FUNC(te_VKMS_ErrorType,VKMS_CODE) Set_VKMSDLC(void)
{
    te_VKMS_ErrorType fl_RetVal_E = VKMS_ERR_NONE;
    Std_ReturnType RetVal = E_NOT_OK;
    if(E_OK == vHsmBlob_Encryptkey((uint8 *)&l_CurrentDLC_st,sizeof(l_CurrentDLC_st),(uint8 *)&l_vHsmVKMSDlcSlot_ts.DLCData,&l_vHsmVKMSDlcSlot_ts.DLCTag[0]))
    {
        /*Implement DLC flash Erase and Write*/
        l_vHsmVKMSDlcSlot_ts.DLCValid = 1u;
        if(l_vHsmVKMSDlcSlot_ts.DLCCounter == 0xFFFFFFFFu)
        {
            l_vHsmVKMSDlcSlot_ts.DLCCounter = 0u;
        }
        else
        {
            l_vHsmVKMSDlcSlot_ts.DLCCounter += 1u;
        }
        l_vHsmVKMSDlcSlot_ts.DLCMarker = VKMSMAGICFLAG ^ l_vHsmVKMSDlcSlot_ts.DLCCounter;
        RetVal = Fls_Erase(DLC_STORAGE_ADDRESS,0x1000u);
        if(E_OK == RetVal)
        {
            RetVal = Fls_Write(DLC_STORAGE_ADDRESS,(uint8 *)&l_vHsmVKMSDlcSlot_ts,sizeof(l_vHsmVKMSDlcSlot_ts));
        }
        if(RetVal != E_OK)
        {
            fl_RetVal_E = VKMS_ERR_HW_KEY_WRITE_FAIL;
            VKMS_print("\r\n VKMS_ERR_HW_KEY_WRITE_FAIL");
        }
    }
    else
    {
        fl_RetVal_E = VKMS_ERR_HW_CRYPTO_OTHER;
    }
    return fl_RetVal_E;
}

/**
 * @brief Programs the initial (PSS) key into flash storage.
 *
 * Only operates when VKMS is NotProvisioned and the first key slot is
 * uninitialised (0xFF). Encrypts the provided key, sets header/footer
 * markers (0x11223344 / 0x44332211), and writes to flash.
 *
 * @param[in] InitKey      Pointer to the initial key material.
 * @param[in] InitKeySize  Size of the initial key.
 *
 * @return E_OK    Key programmed successfully.
 * @return E_NOT_OK Encryption failure, wrong state, or size mismatch.
 */
FUNC(Std_ReturnType, VKMS_CODE) vHsmVKMS_SetInitKey(const uint8 * InitKey, uint16 InitKeySize)
{
    Std_ReturnType retVal = E_NOT_OK;
    if((l_vHsmVKMSProvisionState_e == e_VKMS_NotProvisioned) && (l_vHsmVKMSKeyFlash_ts.VKMSKeys_st[0].KeyValid == 0xFFu))
    {
        if((InitKey != NULL) && (InitKeySize == l_vHsmVKMSKeyConfigArray_stA[0].KeyconfSize))
        {
            retVal = vHsmBlob_Encryptkey(InitKey,InitKeySize,&l_vHsmVKMSKeyFlash_ts.VKMSKeys_st[0].key.Key_Payload_U8[0],&l_vHsmVKMSKeyFlash_ts.VKMSKeys_st[0].keyTag[0]);
            if(retVal == E_OK)
            {
                l_vHsmVKMSKeyFlash_ts.KeyHeader = 0x11223344u;
                l_vHsmVKMSKeyFlash_ts.VKMSKeys_st[0].KeyValid = 1u;
                l_vHsmVKMSKeyFlash_ts.KeyFooter = 0x44332211u;
                /* write Logic to be implemented*/
                retVal = Fls_Erase(KEY_STORAGE_ADDRESS,0x1000u);
                if(retVal == E_OK)
                {
                    retVal = Fls_Write(KEY_STORAGE_ADDRESS,(uint8*)&l_vHsmVKMSKeyFlash_ts,sizeof(l_vHsmVKMSKeyFlash_ts));
                }
            }
            else
            {
                VKMS_print("\r\n Key encrypt fail");

            }
        }
    }
    else if(l_vHsmVKMSKeyFlash_ts.VKMSKeys_st[0].KeyValid == 1u)
    {
        VKMS_print("\r\n Init Key present");
    }
    else
    {
        VKMS_print("\r\n Init Key Error");
    }
    return retVal;
}

/**
 * @brief Retrieves metadata (KeyTypeId, TrainingCounter, Flags, Genus)
 *        for one key or all configured keys.
 *
 * If p_KeyId_U16 is 0, iterates all configured keys and packs 6 bytes
 * of metadata per key into the output buffer. Otherwise returns metadata
 * for the single matching key (5 bytes).
 *
 * @param[in]     p_KeyId_U16          Key identifier (0 = all keys).
 * @param[out]    p_metaData_U8P       Buffer to receive key metadata.
 * @param[in,out] p_metaDataLength_U32P On input: buffer capacity.
 *                                      On output: bytes written.
 *
 * @return VKMS_ERR_NONE                       Success.
 * @return VKMS_ERR_BUSY                       VKMS not idle.
 * @return VKMS_E_PARAM_POINTER                NULL pointer.
 * @return VKMS_ERR_SMALL_BUFFER               Output buffer too small.
 * @return VKMS_ERR_HW_KEY_READ_FAIL           Key read failure.
 * @return VKMS_ERR_TYPEID_NOT_PRESENT         Training counter is zero.
 * @return VKMS_ERR_CONFIG_TYPEID_NOT_CONFIGURED KeyId not in config.
 */
FUNC (te_VKMS_ErrorType, VKMS_CODE)HSM_VKMS_getMetaData(uint16 p_KeyId_U16,uint8 *p_metaData_U8P,uint32 *p_metaDataLength_U32P)
{
    uint32 fl_totalBytes_U32 = 0u;
    uint16 fl_counter_U16 = 0u;
    uint8 fl_keyFound_U8 = 0u;
    Std_ReturnType fl_retVal = E_NOT_OK;
    uint8 fl_BufferIndex_U8 = 0u;
    uint16 fl_keyIDall_U16 = VKMS_INVALID_KEYINDEX;
    uint8 l_vHsmGetMetadataAll_U8A[MAX_GETMETDATABUFF_LEN] = {0u};
    te_VKMS_ErrorType fl_retVal_e = VKMS_ERR_GENERAL;
    ts_VKMSKeyDataType_st * fl_dummyKey_ts = NULL;
    if(e_VKMS_Idle != CurrentVKMSState_U8)
    {
        fl_retVal_e = VKMS_ERR_BUSY;
    }
    else if((NULL == p_metaData_U8P) || (NULL == p_metaDataLength_U32P))
    {
        fl_retVal_e = VKMS_E_PARAM_POINTER;
    }
    else if (0u == p_KeyId_U16)
    {
        /* All key IDs must be considered here */
        /* Check for the data length before copying to the out buffer */
        fl_totalBytes_U32 = MAX_GETMETDATABUFF_LEN;
        if(*p_metaDataLength_U32P < fl_totalBytes_U32)
        {
            fl_retVal_e = VKMS_ERR_SMALL_BUFFER;
        }
        else
        {
            *p_metaDataLength_U32P = 0u;                    
            /* collect the meta data of individual keys and update to the output buffer */
            for(fl_counter_U16 = 0u; fl_counter_U16 < MAX_CONFIGURED_KEYS;fl_counter_U16++)
            {
                fl_keyIDall_U16 = l_vHsmVKMSKeyConfigArray_stA[fl_counter_U16].KeyId_U16;
                fl_dummyKey_ts = vHsmVKMS_GetKey(fl_keyIDall_U16,&fl_retVal);
                if(E_OK == fl_retVal)
                {
                    if(fl_dummyKey_ts->TypeTrainingCounter_U16 != 0u)
                    {                            
                        fl_retVal_e = VKMS_ERR_NONE;
                        (void)memcpy(&l_vHsmGetMetadataAll_U8A[fl_BufferIndex_U8], (uint8 *)&fl_dummyKey_ts->KeyTypeId_U16,BYTE2);
                        HSM_VKMS_InvertEndianness(&l_vHsmGetMetadataAll_U8A[fl_BufferIndex_U8], BYTE2);
                        fl_BufferIndex_U8 += 2u;
                        (void)memcpy(&l_vHsmGetMetadataAll_U8A[fl_BufferIndex_U8], (uint8 *)&fl_dummyKey_ts->TypeTrainingCounter_U16,BYTE2);
                        HSM_VKMS_InvertEndianness(&l_vHsmGetMetadataAll_U8A[fl_BufferIndex_U8], BYTE2);
                        fl_BufferIndex_U8 += 2u;
                        l_vHsmGetMetadataAll_U8A[fl_BufferIndex_U8] = fl_dummyKey_ts->KeyFlags_U8;
                        fl_BufferIndex_U8 += 1u;
                        l_vHsmGetMetadataAll_U8A[fl_BufferIndex_U8] = fl_dummyKey_ts->KeyGenus_U8;
                        fl_BufferIndex_U8 += 1u;
                        *p_metaDataLength_U32P += KEYS_META_DATA_BYTES;
                    }
                    else
                    {
                        if(1u == ResetNormalDLC())
                        {
                            fl_retVal_e = VKMS_ERR_NONE;
                            (void)memcpy(&l_vHsmGetMetadataAll_U8A[fl_BufferIndex_U8], (uint8 *)&fl_dummyKey_ts->KeyTypeId_U16,BYTE2);
                            HSM_VKMS_InvertEndianness(&l_vHsmGetMetadataAll_U8A[fl_BufferIndex_U8], BYTE2);
                            fl_BufferIndex_U8 += 2u;
                            (void)memcpy(&l_vHsmGetMetadataAll_U8A[fl_BufferIndex_U8], (uint8 *)&fl_dummyKey_ts->TypeTrainingCounter_U16,BYTE2);
                            HSM_VKMS_InvertEndianness(&l_vHsmGetMetadataAll_U8A[fl_BufferIndex_U8], BYTE2);
                            fl_BufferIndex_U8 += 2u;
                            l_vHsmGetMetadataAll_U8A[fl_BufferIndex_U8] = fl_dummyKey_ts->KeyFlags_U8;
                            fl_BufferIndex_U8 += 1u;
                            l_vHsmGetMetadataAll_U8A[fl_BufferIndex_U8] = fl_dummyKey_ts->KeyGenus_U8;
                            *p_metaDataLength_U32P += KEYS_META_DATA_BYTES;
                            break;
                        }
                    }
                }
                else
                {
                    fl_retVal_e = VKMS_ERR_HW_KEY_READ_FAIL;
                    break;
                }
            }
            if(VKMS_ERR_NONE == fl_retVal_e)
            {
                (void)memcpy(p_metaData_U8P,&l_vHsmGetMetadataAll_U8A[0],*p_metaDataLength_U32P);
            }
            else
            {
                (void)memset(p_metaData_U8P, 0, sizeof(l_vHsmGetMetadataAll_U8A));
            }
        }
    }
    else
    {
        fl_keyFound_U8 = vHsmVKMSKEYMAP(p_KeyId_U16);
        if(MAX_CONFIGURED_KEYS > fl_keyFound_U8)
        {
            if(*p_metaDataLength_U32P < KEYS_META_DATA_BYTES)
            {
                fl_retVal_e = VKMS_ERR_SMALL_BUFFER;
            }
            else
            {
                /* collect the meta data of the key and update to the output buffer */
                fl_dummyKey_ts = vHsmVKMS_GetKey(p_KeyId_U16,&fl_retVal);
                if(E_OK == fl_retVal)
                {
                    if(fl_dummyKey_ts->TypeTrainingCounter_U16 == 0u)
                    {
                        fl_retVal_e = VKMS_ERR_TYPEID_NOT_PRESENT;
                    }
                    else
                    {
                        fl_retVal_e = VKMS_ERR_NONE;
                        fl_BufferIndex_U8 = 0u;
                        (void)memcpy(&l_vHsmGetMetadataAll_U8A[fl_BufferIndex_U8], (uint8 *)&fl_dummyKey_ts->TypeTrainingCounter_U16, BYTE2);
                        HSM_VKMS_InvertEndianness(&l_vHsmGetMetadataAll_U8A[fl_BufferIndex_U8], BYTE2);
                        fl_BufferIndex_U8 += 2u;
                        l_vHsmGetMetadataAll_U8A[fl_BufferIndex_U8] = fl_dummyKey_ts->KeyFlags_U8;
                        fl_BufferIndex_U8 += 1u;
                        l_vHsmGetMetadataAll_U8A[fl_BufferIndex_U8] = fl_dummyKey_ts->KeyGenus_U8;
                        *p_metaDataLength_U32P = 5u;
                    }
                }
                else
                {
                    fl_retVal_e = VKMS_ERR_HW_KEY_READ_FAIL;
                }
            }
        }
        else
        {
            fl_retVal_e = VKMS_ERR_CONFIG_TYPEID_NOT_CONFIGURED;
        }    
    }  
    return (fl_retVal_e);
}

/**
 * @brief Populates an 8-byte status buffer with VKMS state information.
 *
 * Writes provision flags, master key group ID, and identity counter
 * into the status buffer, with content depending on the current
 * provision state (Normal, Limited, Reset, or NotProvisioned).
 *
 * @param[out] status_ptr  Buffer to receive the 8-byte status data.
 *
 * @return VKMS_ERR_NONE            Status written successfully.
 * @return VKMS_ERR_BUSY            VKMS not idle.
 * @return VKMS_E_PARAM_POINTER     NULL pointer.
 * @return VKMS_ERR_HW_CRYPTO_OTHER DLC read failure.
 */
FUNC (te_VKMS_ErrorType, VKMS_CODE) HSM_VKMS_getStatus(uint8 * status_ptr)
{
    te_VKMS_ErrorType fl_retVal_e = VKMS_ERR_GENERAL;
    ts_VKMSDLCDataType_st * l_VKMS_DLC_Auth_st = NULL;
    uint8 l_vHsmVKMS_Stats_U8A[BYTE8] = {0};
    if(e_VKMS_Idle != CurrentVKMSState_U8)
    {
        fl_retVal_e = VKMS_ERR_BUSY;
    }
    else if(NULL == status_ptr)
    {
        fl_retVal_e = VKMS_E_PARAM_POINTER;
    }
    else
    {
        fl_retVal_e = VKMS_ERR_NONE;
        if (l_vHsmVKMSProvisionState_e == e_VKMS_Provisioned_Normal)
        {
            /* unlimited mode */
            l_VKMS_DLC_Auth_st = vHsmVKMS_GetDLC();
            if(NULL != l_VKMS_DLC_Auth_st)
            {
                l_vHsmVKMS_Stats_U8A[0] = FLAG_0 | FLAG_3;
                (void)memcpy((uint8 *)&l_vHsmVKMS_Stats_U8A[2],(uint8 *)&l_VKMS_DLC_Auth_st->MasterKeyGrpId_U8A,MASTER_KEY_LENGTH);
                (void)memcpy((uint8 *)&l_vHsmVKMS_Stats_U8A[5],(uint8 *)&l_VKMS_DLC_Auth_st->IdentityCounter_U16,IDENTITY_COUNTER_LENGTH);
                (void)HSM_VKMS_InvertEndianness(&l_vHsmVKMS_Stats_U8A[5],BYTE2);
            }
            else
            {
                fl_retVal_e = VKMS_ERR_HW_CRYPTO_OTHER;
            }
        }
        else if (e_VKMS_Provisioned_Limited == l_vHsmVKMSProvisionState_e)
        {
            l_vHsmVKMS_Stats_U8A[0] = FLAG_0 | FLAG_2 | FLAG_3; /*This needs to be taken care*/
            l_VKMS_DLC_Auth_st = vHsmVKMS_GetDLC();
            if(NULL != l_VKMS_DLC_Auth_st)
            {
                (void)memcpy((uint8 *)&l_vHsmVKMS_Stats_U8A[2],(uint8 *)&l_VKMS_DLC_Auth_st->MasterKeyGrpId_U8A,MASTER_KEY_LENGTH);
                (void)memcpy((uint8 *)&l_vHsmVKMS_Stats_U8A[5],(uint8 *)&l_VKMS_DLC_Auth_st->IdentityCounter_U16,IDENTITY_COUNTER_LENGTH);
                (void)HSM_VKMS_InvertEndianness(&l_vHsmVKMS_Stats_U8A[5],BYTE2);
            }
            else
            {
                fl_retVal_e = VKMS_ERR_HW_CRYPTO_OTHER;
            }
        }
        else if(e_VKMS_Provisioned_Reset == l_vHsmVKMSProvisionState_e)
        {
            l_vHsmVKMS_Stats_U8A[0] = FLAG_0 | FLAG_2 | FLAG_3;
            (void)memset((uint8 *)&l_vHsmVKMS_Stats_U8A[2],0xFF,BYTE8);
        }
        else
        {
            l_vHsmVKMS_Stats_U8A[0] = FLAG_3;
        }
        if(fl_retVal_e == VKMS_ERR_NONE)
        {
            (void)memcpy(status_ptr, (uint8 *)&l_vHsmVKMS_Stats_U8A[0], BYTE7);
        }
    }        
    return (fl_retVal_e);
}


#ifdef VKMS_DEBUG
/**
 * @brief Converts a VKMS error code to a human-readable string.
 *
 * @param[in] errCode  The VKMS error code to translate.
 *
 * @return Pointer to a null-terminated string describing the error.
 *         Returns "VKMS_ERR_UNKNOWN" for unrecognised codes.
 */
LOCAL const u8 * VKMS_ErrToString(te_VKMS_ErrorType errCode)
{
    const u8 * retval;
    switch (errCode)
    {
        case VKMS_ERR_NONE:
            retval = "\r\nVKMS_ERR_NONE";
            break;
        case VKMS_ERR_GENERAL:                             
            retval = "\r\nVKMS_ERR_GENERAL";
            break;
        case VKMS_E_PARAM_POINTER:                         
            retval = "\r\nVKMS_E_PARAM_POINTER";
            break;
        case VKMS_ERR_TYPEID_NOT_PRESENT:                  
            retval = "\r\nVKMS_ERR_TYPEID_NOT_PRESENT";
            break;
        case VKMS_ERR_TYPEID_NOT_SUPPORTED:                
            retval = "\r\nVKMS_ERR_TYPEID_NOT_SUPPORTED";
            break;
        case VKMS_ERR_CORRUPTED_KEY_DATA:                  
            retval = "\r\nVKMS_ERR_CORRUPTED_KEY_DATA";
            break;
        case VKMS_ERR_BUSY:                                 
            retval = "\r\nVKMS_ERR_BUSY";
            break;
        case VKMS_ERR_PRECONDITION_NOT_MET:                
            retval = "\r\nVKMS_ERR_PRECONDITION_NOT_MET";
            break;
        case VKMS_ERR_SMALL_BUFFER:                        
            retval = "\r\nVKMS_ERR_SMALL_BUFFER";
            break;
        case VKMS_ERR_DLC_INVALID_MAC:                     
            retval = "\r\nVKMS_ERR_DLC_INVALID_MAC";
            break;
        case VKMS_ERR_DLC_MALFORMATTED:                    
            retval = "\r\nVKMS_ERR_DLC_MALFORMATTED";
            break;
        case VKMS_ERR_DLC_DEPRECATED:                      
            retval = "\r\nVKMS_ERR_DLC_DEPRECATED";
            break;
        case VKMS_ERR_DLC_VERIFICATION_MISMATCH:           
            retval = "\r\nVKMS_ERR_DLC_VERIFICATION_MISMATCH";
            break;
        case VKMS_ERR_DLC_UNSUPPORTED_VERSION:             
            retval = "\r\nVKMS_ERR_DLC_UNSUPPORTED_VERSION";
            break;
        case VKMS_ERR_DLC_KEYGENUS_NOT_DERIVABLE:          
            retval = "\r\nVKMS_ERR_DLC_KEYGENUS_NOT_DERIVABLE";
            break;
        case VKMS_ERR_DLC_MISSING_KEY:                     
            retval = "\r\nVKMS_ERR_DLC_MISSING_KEY";
            break;
        case VKMS_ERR_DLC_CONFLICTING_FLAGS:                
            retval = "\r\nVKMS_ERR_DLC_CONFLICTING_FLAGS";
            break;
        case VKMS_ERR_NOT_AVAILABLE_FOR_ABSTRACT_KEY:      
            retval = "\r\nVKMS_ERR_NOT_AVAILABLE_FOR_ABSTRACT_KEY";
            break;
        case VKMS_ERR_CONFIG_NVM_RAM_BUFFER_SIZE_TOO_SMALL: 
            retval = "\r\nVKMS_ERR_CONFIG_NVM_RAM_BUFFER_SIZE_TOO_SMALL";
            break;
        case VKMS_ERR_CONFIG_MAX_DLC_LENGTH_TOO_SMALL:     
            retval = "\r\nVKMS_ERR_CONFIG_MAX_DLC_LENGTH_TOO_SMALL";
            break;
        case VKMS_ERR_CONFIG_TYPEID_NOT_CONFIGURED:        
            retval = "\r\nVKMS_ERR_CONFIG_TYPEID_NOT_CONFIGURED";
            break;
        case VKMS_ERR_HW_KEY_READ_FAIL:                    
            retval = "\r\nVKMS_ERR_HW_KEY_READ_FAIL";
            break;
        case VKMS_ERR_HW_KEY_WRITE_FAIL:                   
            retval = "\r\nVKMS_ERR_HW_KEY_WRITE_FAIL";
            break;
        case VKMS_ERR_HW_CRYPTO_KEY_SIZE_MISMATCH:         
            retval = "\r\nVKMS_ERR_HW_CRYPTO_KEY_SIZE_MISMATCH";
            break;
        case VKMS_ERR_HW_CRYPTO_OTHER:                     
            retval = "\r\nVKMS_ERR_HW_CRYPTO_OTHER";
            break;
        default:                                           
            retval = "\r\nVKMS_ERR_UNKNOWN";
            break;
    }
    return retval;
}


/**
 * @brief Converts a VKMS Provision state to a human-readable string.
 *
 * @param[in] errCode  The VKMS Provision state to translate.
 *
 * @return Pointer to a null-terminated string describing the error.
 */
LOCAL const u8 * VKMS_ProvToString(te_VKMS_ProvisionStateType provCode)
{
    const u8 * retval;
    switch (provCode)
    {
        case e_VKMS_NotProvisioned:
            retval = "\r\ne_VKMS_NotProvisioned";
            break;
        case e_VKMS_Provisioned_Limited:                             
            retval = "\r\ne_VKMS_Provisioned_Limited";
            break;
        case e_VKMS_Provisioned_Normal:                         
            retval = "\r\ne_VKMS_Provisioned_Normal";
            break;
        case e_VKMS_Provisioned_Reset:                  
            retval = "\r\ne_VKMS_Provisioned_Reset";
            break;
        default:
            break;
    }
    return retval;
}
#endif /*VKMS_DEBUG*/

#endif /*VKMS_ENABLED*/
/*EOF*/
