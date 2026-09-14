/***************************************************************************/
/**
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
 * \file vHsmKeyStore.h
 *
 * \brief
 * Visteon HSM Key Store for symmetric and assymetric keys for TI AM62Px Header File
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Sree Divya Vetcha        | svetcha   | VTSC, Bengaluru, India
 *          Krithik B John           | kjohn     | VTSC, Bengaluru, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 ******************************************************************************/
#include "Std_Types.h"
/* static update policy errors */
#define CRY_SHE_ERR_KEY_SLOT_EMPTY             (0x00100E05UL)   /* The authentication slot is empty. */
#define CRY_SHE_ERR_KEY_WRITE_PROTECTED        (0x00101107UL)   /* The update slot is write protected and cannot be overwritten. */
#define CRY_SHE_ERR_VERIFICATION_FAILED        (0x00101B08UL)   /* Parameters M1 and M2 could not be verified due to unmatched parameter M3. */
#define CRY_SHE_ERR_COUNTER_INVALID            (0x00101A08UL)   /* The requested update counter is smaller than or equal to current update counter. */
#define CRY_SHE_ERR_AUTH_ID_INVALID            (0x00101C04UL)   /* The combination of update slot and authentication slot is not allowed. */
#define CRY_SHE_ERR_WILDCARD_PROTECTED         (0x00101308UL)   /* The update slot is wildcard protected but zero UID was provided. */
#define CRY_SHE_ERR_UID_INVALID                (0x00102708UL)   /* The non-zero UID parameter does not match the embedded SHE UID. */

/* dynamic update policy errors */
#define CRY_SHE_ERR_DEBUGGER_PROTECTED         (0x00100F03UL)   /* The authentication slot for RAM_KEY update is debugger protected but external debugger was found. */
#define CRY_SHE_ERR_BOOT_FAILURE_PROTECTED     (0x00100B03UL)   /* The authentication slot for RAM_KEY update is boot protected but secure boot failed. */

#define M4_M5_GENERATION_REQ

typedef enum
{
    AES_128 =  0,
    AES_192 =  1,
    AES_256 =  2,
    RSA_2048 = 3,
    RSA_3072 = 4,
    RSA_4096 = 5,
    ECC_P256 = 6,
    ECC_TBD1 = 7,
    ECC_TBD2 = 8,
    MAX_ALGOS = 9
}te_AlgoIdType;

 typedef struct
{
        uint32          KeyId;        /* Security key Id*/
        te_AlgoIdType  AlgoId;       /* Security Algorithm associated with the key */
        uint8          AuthId;       /* Auth ID to be written */
        uint8          FID_data;     /* flags data to be written */
        uint8 *        WrPayloadPtr; /* payload for key to be written */
        uint32         Counter;     /* Counter of the key to be written */
}ts_WriteStructKeyDataType;

typedef struct
{
        uint8 *            RdPayloadPtr; /* payload of the key that's read and to be used
                                    for security algorithm */
        uint32             counter;      /* counter of the key */
        uint16             KeySize;      /* Security key size*/
        Std_ReturnType     ReadPerformed;
        /* E_OK - workflash read
                           is done
                           E_NOT_OK - workflash read
                           cannot be done at present */
        boolean            KeyIdLocated;
        /* true -KeyId is located and
                           the below info are applicable,
                           if false, the below info
                           are not applicable */
        uint32              Rd_KeyId;     /* Security key Id*/
        uint8              authId;       /* key authenticating the new key */
        uint8              flag_val;     /* flag value from flash */
        te_AlgoIdType      algoId;       /* Algo Id value from flash */
}ts_ReadStructKeyDataType;

typedef enum
{
    WRITE_OK = 0,
    WRITE_NOT_OK,
    WRITE_PENDING_STATE,
}te_WriteResultType;

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
void vHsmKeyMan_ManipPeriodic(void);
/**
******************************************************************************
** \fn vHsmKeyMan_KeyUpdate
**
** KeyUpdate for specific key passed as parameter in the form of the structure
** ts_WriteStructKeyDataType, passing it as pointer
** This function gets used for both the fresh key creation in workflash
** Or update of the old key
** Conditions:
**  (1) Can write to flash only when the flags for already present key with
**  same key ID are 0
**  (2) Can write to flash only when the Algo for already present key with
**  same key ID match with the request provided
**  (3) Can write to flash only when the counter already present
**  for the specific Key Id is less than the new request for the same key ID
**  (4) Can write to flash if the key is not present at all and meets the
**  sanity check of all params
**  (5) Can update to RAM for using a RAM key in crypto jobs, for which the
**  Key ID is expected to be 14 only, other params except the pointer to
**  Key data will not be applicable
** This function returns
** - E_NOT_OK if any one of the above conditions not met
** - E_OK otherwise.
**
** \param [in] ts_WriteStructKeyDataType * - pointer to structure containing 
**                                           data for write to keys area
**
** \param [in] p_uidZeroChk_U8             - UID check to be done or not 
**                                           1 = need to do UID check
**                                           0 = no need to check UID
*****************************************************************************/
Std_ReturnType vHsmKeyMan_KeyUpdate(ts_WriteStructKeyDataType *p_KeyWriteParam_SP, 
                                    uint8 p_uidZeroChk_U8);
/**
 ******************************************************************************
 ** \fn vHsmKeyMan_ResultCheck
 **
 ** Result check after a key write/ update request is placed
 **
 ** This function returns te_WriteResultType
 **  WRITE_NOT_OK - write cannot be done due to sanity check failure
 **  WRITE_OK - write can be done
 **  WRITE_PENDING - write request in pending state
 ** \param [in] NONE
 **
 *****************************************************************************/
te_WriteResultType vHsmKeyMan_ResultCheck(void);
/**
******************************************************************************
** \fn vHsmKeyMan_KeyUpdate
**
** KeyUpdate for specific key passed as parameter in the form of the structure
** ts_WriteStructKeyDataType, passing it as pointer
** This function gets used for both the fresh key creation in workflash
** Or update of the old key
** Conditions:
**  (1) Can write to flash only when the flags for already present key with
**  same key ID are 0
**  (2) Can write to flash only when the Algo for already present key with
**  same key ID match with the request provided
**  (3) Can write to flash only when the counter already present
**  for the specific Key Id is less than the new request for the same key ID
**  (4) Can write to flash if the key is not present at all and meets the
**  sanity check of all params
**  (5) Can update to RAM for using a RAM key in crypto jobs, for which the
**  Key ID is expected to be 14 only, other params except the pointer to
**  Key data will not be applicable
** This function returns
** - E_NOT_OK if any one of the above conditions not met
** - E_OK otherwise.
**
** \param [in] ts_WriteStructKeyDataType * - pointer to structure containing 
**                                           data for write to keys area
**
** \param [in] p_uidZeroChk_U8             - UID check to be done or not 
**                                           1 = need to do UID check
**                                           0 = no need to check UID
*****************************************************************************/
Std_ReturnType vHsmKeyMan_KeyUpdate(ts_WriteStructKeyDataType *p_KeyWriteParam_SP, 
                                    uint8 p_uidZeroChk_U8);

/**
 ******************************************************************************
 ** \fn vHsmKeyMan_KeyRead
 **
 ** KeyRead for specific key passed as parameter
 **
 ** This function returns pointer to structure ts_ReadStructKeyDataType
 **
 ** \param [in] KeyId - key ID of the key to be read out in plain or encrypted from the workflash
 ** \param [in] p_Algo_Id_te - algo ID of the key to be read out of the key to be read out
 ** \param [in] decrypt_flag - set to 1 if the key is needed in plain form, else 0
 **
 *****************************************************************************/
ts_ReadStructKeyDataType * vHsmKeyMan_KeyRead(uint32 KeyId, te_AlgoIdType p_Algo_Id_te, uint8 decrypt_flag);
/**
 ******************************************************************************
 ** \fn vHsmKeyMan_SymKeyWrapPeriodic
 **
 ** Conversion logics to M1, M2, M3 to plain key in periodic call
 **
 ** This function returns void
 **
 ** \param [in] NONE
 **
 *****************************************************************************/
void vHsmKeyMan_SymKeyWrapPeriodic(void);
/*EOF*/
