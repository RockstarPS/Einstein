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
 * \file vHsmVKMS.h
 *
 * \brief
 * Visteon HSM VKMS Key Manager header file
 *
 *  This file shall give the APIs available external to vHsmKeyMan component
 *  used in Key storage in Traveo II product
 *
 * \version 1.0.0
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 |            |          |         |                                       |
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Krithik B John           | kjohn     | VTSC, Bengaluru, India
 *          Vetcha Sree Divya        | svetcha   | VTSC, Bengaluru, India
 ******************************************************************************/

#ifndef V_HSM_VKMS_H
#define V_HSM_VKMS_H

#include "Std_Types.h"
#include "vHsmVKMS_Cfg.h"
#include "vHsmCryptoManager.h"

/**
 * ****************************************************************************
 * \brief VKMS Provision State
 * ****************************************************************************
 */
typedef enum
{
    e_VKMS_NotProvisioned      = 0,
    e_VKMS_Provisioned_Limited = 1,
    e_VKMS_Provisioned_Normal  = 2,
    e_VKMS_Provisioned_Reset   = 3,
} te_VKMS_ProvisionStateType;

/**
 * ****************************************************************************
 * \brief VKMS Error Types
 *
 * Error types returned by VKMS APIs. Created to support LH_VKMS_Core_43 from
 * the core document.
 * ****************************************************************************
 */
typedef enum
{
    VKMS_ERR_NONE                              =  0, /* E_OK */
    VKMS_ERR_GENERAL                           =  1, /* E_NOT_OK */
    VKMS_E_PARAM_POINTER                       = 12, /* Null pointer */
    VKMS_ERR_TYPEID_NOT_PRESENT                = 20, /* The key with this type ID was not
                                                        included in the last provisioning. */
    VKMS_ERR_TYPEID_NOT_SUPPORTED              = 21, /* The key with this type ID
                                                        cannot be read in cleartext */
    VKMS_ERR_CORRUPTED_KEY_DATA                = 22, /* Corrupted key material was detected
                                                        when checking the verification checksum */
    VKMS_ERR_BUSY                              = 23, /* Function not available, as a DLC is
                                                        currently being processed */
    VKMS_ERR_PRECONDITION_NOT_MET              = 24, /* The prerequisites for running this
                                                        function are not being met */
    VKMS_ERR_SMALL_BUFFER                      = 25, /* The passed buffer was too small to store
                                                        the requested data. */
    /* 26, 27, 28, 29 - not used in VKMS core component */
    VKMS_ERR_DLC_INVALID_MAC                   = 30, /* The DLC could not be decrypted or the
                                                        message authentication code (MAC) check failed. */
    VKMS_ERR_DLC_MALFORMATTED                  = 31, /* Invalid DLC format */
    VKMS_ERR_DLC_DEPRECATED                    = 32, /* The ECU training counter in the DLC is
                                                        smaller than the one persisted on the ECU. */
    VKMS_ERR_DLC_VERIFICATION_MISMATCH         = 33, /* The checksum over the key material
                                                        that was introduced does not match the
                                                        one specified in the DLC. */
    VKMS_ERR_DLC_UNSUPPORTED_VERSION           = 34, /* The DLC version is not supported. */
    VKMS_ERR_DLC_KEYGENUS_NOT_DERIVABLE        = 35, /* The DLC contained a key type with the
                                                        ECUSIDE_DERIVATION flag for whose key
                                                        genus derivation on the ECU is not possible */
    VKMS_ERR_DLC_MISSING_KEY                   = 36, /* The DLC did not include all configured
                                                        key types */
    VKMS_ERR_DLC_CONFLICTING_FLAGS             = 37, /* The key flags conflict with each other
                                                        (ECUSIDE_DERIVATION and ABSTRACT_KEY) */
    VKMS_ERR_NOT_AVAILABLE_FOR_ABSTRACT_KEY    = 38, /* The requested key has the ABSTRACT_KEY
                                                        flag and the function is not available
                                                        for keys with this flag. */
    VKMS_ERR_CONFIG_NVM_RAM_BUFFER_SIZE_TOO_SMALL          = 40, /* The configured size for storing
                                                                     metadata, certificates, or
                                                                     application-specific data is
                                                                     too small. */
    VKMS_ERR_CONFIG_MAX_DLC_LENGTH_TOO_SMALL              = 41, /* The configured maximum size for
                                                                     a DLC is smaller than the size
                                                                     of the passed DLC */
    VKMS_ERR_CONFIG_TYPEID_NOT_CONFIGURED                 = 42, /* A key type ID that has not been
                                                                     configured was requested or
                                                                     added through the DLC */
    VKMS_ERR_HW_KEY_READ_FAIL                             = 45, /* Error while attempting to read a
                                                                     key in the secure hardware
                                                                     environment key store. */
    VKMS_ERR_HW_KEY_WRITE_FAIL                            = 46, /* Error while attempting to write to
                                                                     a key in the secure hardware
                                                                     environment key store. */
    VKMS_ERR_HW_CRYPTO_KEY_SIZE_MISMATCH                  = 47, /* Error when attempting to write a
                                                                     key in the secure hardware
                                                                     environment key store: Wrong key
                                                                     length. */
    VKMS_ERR_HW_CRYPTO_OTHER                               = 48, /* Other error when attempting to
                                                                     access the secure hardware
                                                                     environment key store or
                                                                     cryptographic library. */
    /* 50, 51, 52, 53, 54, 60, 61, 62 - not used in VKMS core component */
} te_VKMS_ErrorType;

/******************************************************************************
 *                       VKMS API FUNCTION DECLARATIONS
 *****************************************************************************/

/**
 ******************************************************************************
 ** \fn vHsmVKMS_Init
 **
 ** \brief Initialize the VKMS key manager
 **
 ** This function initializes the VKMS key manager module. Must be called
 ** before any other VKMS API.
 **
 ** \param [in] NONE
 **
 ** \return void
 **
 *****************************************************************************/
void vHsmVKMS_Init(void);

/**
 ******************************************************************************
 ** \fn HSM_VKMS_handleDLC_start
 **
 ** \brief Start processing a DLC (Downloadable Key Container)
 **
 ** This function initiates the processing of a DLC. It parses the DLC header,
 ** validates the MAC, and updates the key material. A list of changed keys
 ** is returned.
 **
 ** \param [in]  p_dlcLength_U32        Length of the DLC data in bytes
 ** \param [in]  p_dlcDataPtr_pU8       Pointer to the DLC data buffer
 ** \param [out] p_changedKeylistPtr_pU8  Pointer to buffer for changed key list
 ** \param [out] p_changedKeyListLength_U32  Pointer to store the length of
 **                                          the changed key list
 **
 ** \return te_VKMS_ErrorType
 **         VKMS_ERR_NONE       - DLC processing started successfully
 **         VKMS_ERR_BUSY       - VKMS not in idle state
 **         VKMS_E_PARAM_POINTER - Null pointer parameter
 **         VKMS_ERR_DLC_*      - DLC format or content error
 **
 *****************************************************************************/
te_VKMS_ErrorType HSM_VKMS_handleDLC_start(
    const uint32  p_dlcLength_U32,
    const uint8 * p_dlcDataPtr_pU8,
    uint8 *       p_changedKeylistPtr_pU8,
    uint32 *      p_changedKeyListLength_U32);

/**
 ******************************************************************************
 ** \fn HSM_VKMS_handleDLC_finish
 **
 ** \brief Finalize a DLC provisioning sequence
 **
 ** This function completes the DLC processing by persisting the updated key
 ** material to non-volatile storage.
 **
 ** \param [in] NONE
 **
 ** \return te_VKMS_ErrorType
 **         VKMS_ERR_NONE       - DLC finalized successfully
 **         VKMS_ERR_BUSY       - VKMS not in idle state
 **
 *****************************************************************************/
te_VKMS_ErrorType HSM_VKMS_handleDLC_finish(void);

/**
 ******************************************************************************
 ** \fn HSM_VKMS_getVerificationHash
 **
 ** \brief Get the verification hash
 **
 ** This function returns the verification hash used for key material
 ** integrity verification.
 **
 ** \param [out] p_VerHashPtr_pU8  Pointer to buffer for the verification hash
 **
 ** \return te_VKMS_ErrorType
 **         VKMS_ERR_NONE        - Hash retrieved successfully
 **         VKMS_E_PARAM_POINTER  - Null pointer parameter
 **
 *****************************************************************************/
te_VKMS_ErrorType HSM_VKMS_getVerificationHash(uint8 * p_VerHashPtr_pU8);

/**
 ******************************************************************************
 ** \fn HSM_VKMS_getPssHash
 **
 ** \brief Get the PSS hash
 **
 ** This function returns the PSS hash used for provisioning verification.
 **
 ** \param [out] p_PssHashPtr_pU8  Pointer to buffer for the PSS hash
 **
 ** \return te_VKMS_ErrorType
 **         VKMS_ERR_NONE        - Hash retrieved successfully
 **         VKMS_E_PARAM_POINTER  - Null pointer parameter
 **
 *****************************************************************************/
te_VKMS_ErrorType HSM_VKMS_getPssHash(uint8 * p_PssHashPtr_pU8);

/**
 ******************************************************************************
 ** \fn HSM_VKMS_getIdentityHash
 **
 ** \brief Get the identity hash with challenge
 **
 ** This function returns the identity hash computed from the provided
 ** challenge data.
 **
 ** \param [out] p_IdHashPtr_pU8    Pointer to buffer for the identity hash
 ** \param [in]  p_ChallengePtr_pU8 Pointer to challenge data buffer
 **
 ** \return te_VKMS_ErrorType
 **         VKMS_ERR_NONE        - Hash retrieved successfully
 **         VKMS_E_PARAM_POINTER  - Null pointer parameter
 **
 *****************************************************************************/
te_VKMS_ErrorType HSM_VKMS_getIdentityHash(
    uint8 * p_IdHashPtr_pU8,
    uint8 * p_ChallengePtr_pU8);

/**
 ******************************************************************************
 ** \fn HSM_VKMS_getStatus
 **
 ** \brief Get the VKMS status information
 **
 ** This function retrieves the current VKMS provisioning status.
 **
 ** This function returns VKMS error code
 **      VKMS_ERR_NONE - No error
 **      VKMS_ERR_BUSY - VKMS not in idle state
 **      VKMS_E_PARAM_POINTER - Null pointer parameter
 **      VKMS_ERR_HW_CRYPTO_OTHER - Hardware crypto failure
 **        
 ** \param [out] status_ptr Output buffer for VKMS status data
 **
 ** \return te_VKMS_ErrorType
 **
 *****************************************************************************/
te_VKMS_ErrorType HSM_VKMS_getStatus(uint8 * status_ptr);

/**
 ******************************************************************************
 ** \fn HSM_VKMS_getKey
 **
 ** \brief Retrieve a key by its Key ID
 **
 ** This function reads the key material for the specified Key ID. The caller
 ** provides a buffer to receive the key data and its length.
 **
 ** \param [in]  KeyId_U16       Key identifier
 ** \param [out] KeyLength_U16P  Pointer to store the key length
 ** \param [out] KeyData_U8P     Pointer to buffer for key material
 ** \param [in]  shareInfoFlg    Sharing information flag
 **
 ** \return te_VKMS_ErrorType
 **         VKMS_ERR_NONE        - Key retrieved successfully
 **         VKMS_ERR_BUSY        - VKMS not in idle state
 **         VKMS_E_PARAM_POINTER - Null pointer parameter
 **         VKMS_ERR_TYPEID_NOT_PRESENT - Key not provisioned
 **         VKMS_ERR_CONFIG_TYPEID_NOT_CONFIGURED - KeyId not configured
 **         VKMS_ERR_HW_KEY_READ_FAIL - Hardware key read failure
 **
 *****************************************************************************/
te_VKMS_ErrorType HSM_VKMS_getKey(
    uint16  KeyId_U16,
    uint16 *KeyLength_U16P,
    uint8 * KeyData_U8P,
    uint8   shareInfoFlg);

/**
 ******************************************************************************
 ** \fn HSM_VKMS_getTrainingCounter
 **
 ** \brief Get the ECU training counter
 **
 ** This function returns the current ECU training counter value used for
 ** replay protection of DLCs.
 **
 ** \param [out] p_TrainingCounterPtr_pU16  Pointer to store training counter
 **
 ** \return te_VKMS_ErrorType
 **         VKMS_ERR_NONE        - Training counter retrieved successfully
 **         VKMS_E_PARAM_POINTER  - Null pointer parameter
 **
 *****************************************************************************/
te_VKMS_ErrorType HSM_VKMS_getTrainingCounter(
    uint16 * p_TrainingCounterPtr_pU16);

/**
 ******************************************************************************
 ** \fn HSM_VKMS_getVkmsVIN
 **
 ** \brief Get the VKMS VIN
 **
 ** This function retrieves the VIN (Vehicle Identification Number) stored
 ** during VKMS provisioning.
 **
 ** \param [out] p_BuffPtr_pU8  Pointer to buffer for the VIN data
 **
 ** \return te_VKMS_ErrorType
 **         VKMS_ERR_NONE        - VIN retrieved successfully
 **         VKMS_E_PARAM_POINTER  - Null pointer parameter
 **
 *****************************************************************************/
te_VKMS_ErrorType HSM_VKMS_getVkmsVIN(uint8 * p_BuffPtr_pU8);

/**
 ******************************************************************************
 ** \fn HSM_VKMS_getMetaData
 **
 ** \brief Get the metadata of a key or all keys
 **
 ** This function retrieves the metadata (key flags, genus, etc.) for a
 ** specific key or for all configured keys.
 **
 ** This function returns VKMS error code
 **      VKMS_ERR_NONE - No error
 **      VKMS_ERR_BUSY - VKMS not in idle state
 **      VKMS_E_PARAM_POINTER - Null pointer parameter
 **      VKMS_ERR_SMALL_BUFFER - Output buffer too small
 **      VKMS_ERR_HW_KEY_READ_FAIL - Key read failure
 **      VKMS_ERR_TYPEID_NOT_PRESENT - Training counter zero
 **      VKMS_ERR_CONFIG_TYPEID_NOT_CONFIGURED - KeyId not configured
 **
 ** \param [in]  p_KeyId_U16         Key identifier (0 for all keys)
 ** \param [out] p_metaData_U8P      Output buffer for key metadata
 ** \param [i/o] p_metaDataLength_U32P Input: buffer size; Output: written bytes
 **
 ** \return te_VKMS_ErrorType
 **
 *****************************************************************************/
te_VKMS_ErrorType HSM_VKMS_getMetaData(
    uint16  p_KeyId_U16,
    uint8 * p_metaData_U8P,
    uint32 *p_metaDataLength_U32P);

/**
 ******************************************************************************
 ** \fn HSM_VKMS_InvertEndianness
 **
 ** \brief Invert the endianness of a byte array
 **
 ** This function reverses the byte order (endianness) of the given array
 ** in place.
 **
 ** \param [in/out] inArrPtr   Pointer to the array to invert
 ** \param [in]     byteSize   Size of the array in bytes
 **
 ** \return void
 **
 *****************************************************************************/
void HSM_VKMS_InvertEndianness(void * inArrPtr, uint32 byteSize);

/**
 ******************************************************************************
 ** \fn HSM_VKMS_DebugSignCalc
 **
 ** \brief Calculate debug signature
 **
 ** This function computes a debug signature over the provided input data.
 **
 ** \param [in]  p_inputBuff_pU8   Pointer to input data buffer
 ** \param [in]  p_inputLen_U32    Length of input data
 ** \param [out] p_BuffPtr_pU8     Pointer to buffer for the signature
 ** \param [out] p_DataLen_pU32    Pointer to store the signature length
 **
 ** \return te_VKMS_ErrorType
 **         VKMS_ERR_NONE       - Signature calculated successfully
 **         VKMS_E_PARAM_POINTER - Null pointer parameter
 **
 *****************************************************************************/
te_VKMS_ErrorType HSM_VKMS_DebugSignCalc(
    uint8 *  p_inputBuff_pU8,
    uint32   p_inputLen_U32,
    uint8 *  p_BuffPtr_pU8,
    uint32 * p_DataLen_pU32);

/**
 ******************************************************************************
 ** \fn vHsmVKMS_SetInitKey
 **
 ** \brief Set the initial key material
 **
 ** This function sets the initial key used for VKMS provisioning and
 ** derivation.
 **
 ** \param [in] InitKey      Pointer to the initial key material
 ** \param [in] InitKeySize  Size of the initial key in bytes
 **
 ** \return Std_ReturnType
 **         E_OK      - Initial key set successfully
 **         E_NOT_OK  - Failed to set initial key
 **
 *****************************************************************************/
Std_ReturnType vHsmVKMS_SetInitKey(const uint8 * InitKey, uint16 InitKeySize);

#endif /* V_HSM_VKMS_H */

/*END OF FILE */
