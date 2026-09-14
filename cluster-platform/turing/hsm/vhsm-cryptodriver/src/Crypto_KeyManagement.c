/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2022] Visteon Corporation
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
 * \file Crypto_KeyManagement.c
 *
 * \brief
 * Implementation of Key Management Interface 
 *
 * \detailed description
 *  This file shall be dispatch the crypto job in M7, IT Receives the Crypto job request from CRYIF and depends on the job request passes the data to to CRY-SHE 
 *  and receiving back data from CRY-SHE and pass this data to CRYIF
 *
 * \version 1.00.00
 * |Version | Date       | Author   | Task Id | Description                           ...................|
 * |--------|------------|----------|---------|----------------------------------------------------------|
 * |1.00.00 | 23/Aug/'21 | mmarimu2 | 1431692 |Initial Dispatch crpto services implementation            |
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Sree Divya Vetcha        | svetcha   | VTSC, Bengaluru, India
 *          Dhanalakshmi Kasimani    | dkasiman  | VTSC, Chennai, India
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 ******************************************************************************/

/*include files*/
#include "Crypto.h"
#include "CryIf_Cbk.h"
#include "Det.h"
#include "string.h"
#include "Crypto_KeyManagementn.h"
#include "Crypto_Key.h"
#define CRYPTO_KEY_COUNT 22u

/** \brief Different read access types for a key element. */
typedef uint8 Crypto_ReadAccessType;

/** \brief Different write access types for a key element. */
typedef uint8 Crypto_WriteAccessType;
typedef struct
{
  /* Id of key element. */
  uint32 Id;
  /* Indicates whether the key element can be read or written with size smaller than the size of
      the element. */
  boolean AllowPartialAccess;
  /* The initial value of the key element. */
  CONSTP2CONST(uint8, AUTOMATIC, CRYPTO_CONST) InitValue;
  /* Indicates whether the key element is persisted in non-volatile memory. */
  boolean Persist;
  /* Defines the read access rights. */
  CONST(Crypto_ReadAccessType, AUTOMATIC) ReadAccess;
  /* Maximum size of the key element in byte.s */
  uint32 Size;
  /* Defines the write access rights. */
  CONST(Crypto_WriteAccessType, AUTOMATIC) WriteAccess;
} Crypto_KeyElement;
typedef P2VAR(Crypto_KeyElement, AUTOMATIC, CRYPTO_APPL_DATA)
  Crypto_KeyElementPtr;
typedef boolean Crypto_KeyStateType;
#define CRYPTO_KEY_STATE_VALID 0x01U
typedef struct
{
  /* Iterations used in key derivation process. */
  CONST(uint32, AUTOMATIC) KeyDeriveIterations;
  /* Number of key elements referenced by the key. */
  CONST(uint32, AUTOMATIC) KeyElements;
  /* Reference to the key type structure. */
  CONSTP2CONST(Crypto_KeyElementPtr, AUTOMATIC, CRYPTO_APPL_DATA) KeyType;
  /* Current state of the key. */
  Crypto_KeyStateType KeyState;
} Crypto_Key;
extern VAR(Crypto_Key, CRYPTO_VAR) Crypto_Keys[CRYPTO_KEY_COUNT];


/* Static variables*/

/* Declaration of functions with External Linkage*/





/*..Process the KEyelementset request..*/
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyElementSet(uint32 cryptoKeyId, 
                                    uint32 keyElementId, 
                                    P2CONST(uint8, AUTOMATIC, CRY_APPL_DATA) keyPtr, 
                                    uint32 keyLength)
{
Std_ReturnType ret_val = E_NOT_OK;

    /* Check for null pointers */
    if (NULL_PTR == keyPtr)
    {
        ret_val = CRYPTO_E_KEY_NOT_AVAILABLE;
    }
    else if ((cryptoKeyId <= TotalnoCryptoKey) && (keyElementId == CRYPTO_WA_ENCRYPTED))
    {
        ret_val = (uint8)Crypto_She_SetKey(cryptoKeyId, keyElementId, keyPtr, keyLength);
    }
    else if ((cryptoKeyId <= TotalnoCryptoKey) && (keyElementId == CRYPTO_WA_ALLOWED))
    {
        ret_val = (uint8)Crypto_She_SetKey(cryptoKeyId, keyElementId, keyPtr, keyLength);
    }
    else
    {
        ret_val = CRYPTO_E_KEY_SIZE_MISMATCH;
    }
    return ret_val;
}


/*..Process the KEysetvalid request..*/
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeySetValid(uint32 cryptoKeyId)
{
    Std_ReturnType ret_val         = E_NOT_OK;
    static uint32  key_setvalid_ID = 0XFFFF;
    key_setvalid_ID                = crypto_Key[cryptoKeyId].RefOfKey;

    if (cryptoKeyId <= TotalnoCryptoKey)
    {
        /*invoked CRY_SHE API*/
        ret_val = (uint8)Crypto_She_KeysetValid(key_setvalid_ID);
    }
    else
    {
        ret_val = E_NOT_OK;
    }

    return ret_val;
}
/*.. Process the KeyElementGet request..*/
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyElementGet(
       uint32 cryptoKeyId, 
       uint32 keyElementId, 
       P2VAR(uint8, AUTOMATIC , CRY_APPL_DATA) resultPtr, 
       P2VAR(uint32, AUTOMATIC , CRY_APPL_DATA) resultLengthPtr)
{
   Std_ReturnType ret_val    = E_NOT_OK;
   // static uint32  key_get_ID = 0xFFFF;
   // key_get_ID                = crypto_Key[cryptoKeyId].RefOfKey;

    /* Check for null pointers */
    if ((NULL_PTR == resultPtr) || (cryptoKeyId > TotalnoCryptoKey))
    {
        ret_val = CRYPTO_E_PARAM_POINTER;
    }
    else if (cryptoKeyId <= TotalnoCryptoKey)
    {
        ret_val = (uint8)Crypto_She_GetKey(cryptoKeyId, keyElementId, resultPtr, resultLengthPtr);
    }
    else
    {
        ret_val = E_NOT_OK;
    }
    return ret_val;

}
FUNC(Std_ReturnType,CRY_CODE) Crypto_KeyVerify
        (
                 uint32 cryptoKeyId, P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR)payload_ptr,
                uint32 payload_size
        )
{
	 Std_ReturnType ret_val    = E_NOT_OK;
   // static uint32  key_get_ID = 0xFFFF;
   // key_get_ID                = crypto_Key[cryptoKeyId].RefOfKey;

    /* Check for null pointers */
    if ((NULL_PTR == payload_ptr) || (cryptoKeyId > TotalnoCryptoKey))
    {
        ret_val = CRYPTO_E_PARAM_POINTER;
    }
    else if (cryptoKeyId <= TotalnoCryptoKey)
    {
        ret_val = (uint8)Crypto_She_KeyVerify(cryptoKeyId, payload_ptr, payload_size);
    }
    else
    {
        ret_val = E_NOT_OK;
    }
    return ret_val;
}			
/*.. Process the KeyElementCopy request..*/
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyElementCopy(
         uint32 cryptoKeyId, uint32 keyElementId, 
         uint32 targetCryptoKeyId, uint32 targetKeyElementId)
{
  //dummy
 return CSM_E_NOT_OK;

}
/*.. Process the KeyCopy request..*/
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyCopy(uint32 cryptoKeyId, uint32 targetCryptoKeyId)
{
  //dummy
 return CSM_E_NOT_OK;

}
/*.. Process the KeyElementIdsGet request..*/
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyElementIdsGet(uint32 cryptoKeyId, 
         P2VAR(uint32, AUTOMATIC , CRY_APPL_DATA) keyElementIdsPtr, 
         P2VAR(uint32, AUTOMATIC , CRY_APPL_DATA) keyElementIdsLengthPtr)
{
  //dummy
 return CSM_E_NOT_OK;

}

FUNC(Std_ReturnType, CRY_CODE) Crypto_RandomSeed(uint32 cryptoKeyId, 
         P2CONST(uint8, AUTOMATIC, CRY_APPL_DATA) seedPtr, 
         uint32 seedLength)
{
  //dummy
 return CSM_E_NOT_OK;

}
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyGenerate(uint32 cryptoKeyId)
{
  //dummy
 return CSM_E_NOT_OK;

}

FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyDerive(
                 uint32 cryptoKeyId, 
                 uint32 targetCryptoKeyId)
{
  //dummy
 return CSM_E_NOT_OK;

}
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyExchangeCalcPubVal(
         uint32 cryptoKeyId, 
         P2VAR(uint8, AUTOMATIC , CRY_APPL_DATA) publicValuePtr, 
         P2VAR(uint32, AUTOMATIC , CRY_APPL_DATA) publicValueLengthPtr)
{
  //dummy
 return CSM_E_NOT_OK;

}

FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyExchangeCalcSecret(
          uint32 cryptoKeyId, 
          P2CONST(uint8, AUTOMATIC, CRY_APPL_DATA) partnerPublicValuePtr, 
          uint32 partnerPublicValueLength)
{
  //dummy
 return CSM_E_NOT_OK;

}

FUNC(Std_ReturnType, CRY_CODE) Crypto_CertificateParse(uint32 cryptoKeyId)
{
  //dummy
 return CSM_E_NOT_OK;

}

// FUNC(Std_ReturnType, CRY_CODE) Crypto_CertificateVerify(
//                 uint32 cryptoKeyId, 
//                 uint32 verifyCryptoKeyId, 
//                 Crypto_VerifyResultType* verifyPtr)
// {
//   //dummy
//  return CSM_E_NOT_OK;

// }
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_AL_KeyValidSet
(
  uint32 CryptoKeyId
)
{
#if (CRYPTO_ENABLED_NVM == STD_ON)
  uint32 KeyElementIndex;
  boolean NvMResult = E_NOT_OK;
#endif /* #if (CRYPTO_ENABLED_NVM == STD_ON) */
  Std_ReturnType RetVal = E_NOT_OK;

  /* !LINKSTO Crypto.Req.Gen/NvM/01017, 1 */
  //Crypto_Keys[CryptoKeyId].KeyState = CRYPTO_KEY_STATE_VALID;

  RetVal = E_OK;

#if (CRYPTO_ENABLED_NVM == STD_ON)
  for (
        KeyElementIndex = 0U;
        //KeyElementIndex < Crypto_Keys[CryptoKeyId].KeyElements;
        KeyElementIndex++
      )
  {

    /* if the Nvram block ID is not 0 that means the data is persistent */
    if(0U !=
        Crypto_AL_Keys_Data[
                                      CryptoKeyId
                                     ].KeyData[KeyElementIndex].RfKeyElemDataNvramBlockId
      )
    {
      /* !LINKSTO Crypto.Req.Gen/NvM/01001, 2 */
      /* !LINKSTO Crypto.Req.Gen/NvM/01002, 1 */
      NvMResult = NvM_WriteBlock
      (
        Crypto_AL_Keys_Data[
                                      CryptoKeyId
                                     ].KeyData[KeyElementIndex].RfKeyElemDataNvramBlockId,
        Crypto_AL_Keys_Data[CryptoKeyId].KeyData[KeyElementIndex].RfKeyElemData
      );
      if (E_OK != NvMResult)
      {
        RetVal = E_NOT_OK;
      }
    }
  }
#endif /* #if (CRYPTO_ENABLED_NVM == STD_ON) */
  return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_PL_KeyValidSet
(
  uint32 CryptoKeyId
)
{
  Std_ReturnType RetVal = E_NOT_OK;
  RetVal = Crypto_AL_KeyValidSet(CryptoKeyId);
  return RetVal;
}
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyValidSet
(
  uint32 CryptoKeyId
)
{
    Std_ReturnType ret_val         = E_NOT_OK;
    static uint32  key_setvalid_ID = 0XFFFF;
    key_setvalid_ID                = crypto_Key[CryptoKeyId].RefOfKey;

    if (CryptoKeyId <= TotalnoCryptoKey)
    {
        /*invoked CRY_SHE API*/
        ret_val = (uint8)Crypto_She_KeysetValid(key_setvalid_ID);
    }
    else
    {
        ret_val = E_NOT_OK;
    }

    return ret_val;
}
// {
//   Std_ReturnType RetVal = E_NOT_OK;

// #if (CRYPTO_DEV_ERROR_DETECT == STD_ON)
//   if (Crypto_Initialized == FALSE)
//   {
//     /* !LINKSTO SWS_Crypto_00082, 1 */
//     (void) Det_ReportError
//     (
//      CRYPTO_MODULE_ID,
//      CRYPTO_INSTANCE_ID,
//      CRYPTO_SID_KEYVALIDSET,
//      CRYPTO_E_UNINIT
//     );
//     RetVal = E_NOT_OK;
//   }
//   else if (CryptoKeyId >= CRYPTO_KEY_COUNT)
//   {
//     /* !LINKSTO SWS_Crypto_00083, 1 */
//     (void) Det_ReportError
//     (
//      CRYPTO_MODULE_ID,
//      CRYPTO_INSTANCE_ID,
//      CRYPTO_SID_KEYVALIDSET,
//      CRYPTO_E_PARAM_HANDLE
//     );
//     RetVal = E_NOT_OK;
//   }
//   else
// #endif
//   {
//     /* !LINKSTO EB_Crypto_01080, 1 */
//     RetVal = Crypto_PL_KeyValidSet(CryptoKeyId);
//   }
//   return RetVal;
// }


FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_AL_CertificateVerify
(
  uint32                                                      CryptoKeyId,
  uint32                                                      VerifyCryptoKeyId,
  P2VAR(Crypto_VerifyResultType, AUTOMATIC, CRYPTO_APPL_DATA) VerifyPtr
)
{
  Std_ReturnType RetVal = E_NOT_OK;
#if (CRYPTO_CERT_MANAGEMENT_ENABLED == STD_ON)
  Std_ReturnType RetValRefCertSignature = E_NOT_OK;
  Std_ReturnType RetValCertNotBefore = E_NOT_OK;
  Std_ReturnType RetValCertNotAfter = E_NOT_OK;
  Std_ReturnType RetValRefCertNotBefore = E_NOT_OK;
  Std_ReturnType RetValRefCertNotAfter = E_NOT_OK;
  P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) SignedDataPtr = NULL_PTR;
  uint32 SignedDataLength = 0U;
  P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) SignaturePtr = NULL_PTR;
  uint32 SignatureLength = 0U;
  uint8 SignatureAlgorithm[4U] = {0U, 0U, 0U, 0U};
  uint32 SignatureAlgorithmLength = 4U;
#if (CRYPTO_CERT_CURRENT_TIME_ENABLED == STD_ON)
  Std_ReturnType RetValCurrentTime = E_NOT_OK;
#endif

  Crypto_CVDateInfoType RefDate =
  {
#if (CRYPTO_CERT_CURRENT_TIME_ENABLED == STD_ON)
    {0U, 0U, 0U, 0U, 0U, 0U},
#endif
    {0U, 0U, 0U, 0U, 0U, 0U},
    {0U, 0U, 0U, 0U, 0U, 0U}
  };
  Crypto_CVDateInfoType VerfDate =
  {
#if (CRYPTO_CERT_CURRENT_TIME_ENABLED == STD_ON)
    {0U, 0U, 0U, 0U, 0U, 0U},
#endif
    {0U, 0U, 0U, 0U, 0U, 0U},
    {0U, 0U, 0U, 0U, 0U, 0U}
  };

  uint32 DateSize = CRYPTO_DATE_SIZE;

  SchM_Enter_Crypto_SCHM_CRYPTO_EXCLUSIVE_AREA_DRIVEROBJECT();
  /* !LINKSTO EB_Crypto_01300, 1 */
  if (FALSE == Crypto_BUSY_CERT_VERIFY)
  {
    Crypto_BUSY_CERT_VERIFY = TRUE;

    SchM_Exit_Crypto_SCHM_CRYPTO_EXCLUSIVE_AREA_DRIVEROBJECT();

    RetVal = E_OK;
  }
  else
  {
    SchM_Exit_Crypto_SCHM_CRYPTO_EXCLUSIVE_AREA_DRIVEROBJECT();

    RetVal = CRYPTO_E_BUSY;
  }

  if (E_OK == RetVal)
  {
    /*set the verify pointer to CRYPTO_E_VER_NOT_OK before verifing the certificate.*/
    *VerifyPtr = CRYPTO_E_VER_NOT_OK;

    /*Clearing the needed static Key.*/
    TS_MemBZero(Crypto_CertKey.data, CRYPTO_AL_ASYM_PUBLIC_MAX_KEY_ELEMENT_SIZE);
    Crypto_CertKey.length = CRYPTO_AL_ASYM_PUBLIC_MAX_KEY_ELEMENT_SIZE;

    /*set the verifyCryptoKeyId to invalid.*/
    Crypto_Keys[VerifyCryptoKeyId].KeyState = CRYPTO_KEY_STATE_INVALID;
    /* !LINKSTO EB_Crypto_01208,1 */
    /*Get keyelements of root and verify certifactes*/
    RetValCertNotBefore = Crypto_AL_KeyElementGet
                          (
                            CryptoKeyId,
                            CRYPTO_KE_CERTIFICATE_VALIDITY_NOT_BEFORE,
                            RefDate.EffectiveDate,
                            &DateSize
                          );
    RetValCertNotAfter = Crypto_AL_KeyElementGet
                         (
                           CryptoKeyId,
                           CRYPTO_KE_CERTIFICATE_VALIDITY_NOT_AFTER,
                           RefDate.ExpirationDate,
                           &DateSize
                         );
    RetValRefCertNotBefore = Crypto_AL_KeyElementGet
                             (
                               VerifyCryptoKeyId,
                               CRYPTO_KE_CERTIFICATE_VALIDITY_NOT_BEFORE,
                               VerfDate.EffectiveDate,
                               &DateSize
                             );
    RetValRefCertNotAfter = Crypto_AL_KeyElementGet
                            (
                              VerifyCryptoKeyId,
                              CRYPTO_KE_CERTIFICATE_VALIDITY_NOT_AFTER,
                              VerfDate.ExpirationDate,
                              &DateSize
                            );
#if (CRYPTO_CERT_CURRENT_TIME_ENABLED == STD_ON)
    RetValCurrentTime = Crypto_AL_KeyElementGet
                        (
                          VerifyCryptoKeyId,
                          CRYPTO_KE_CERTIFICATE_CURRENT_TIME,
                          VerfDate.CurrentDate,
                          &DateSize
                        );
#endif
#if (CRYPTO_CERT_CURRENT_TIME_ENABLED == STD_ON)
    if(
        (E_OK != RetValCertNotBefore) || (E_OK != RetValCertNotAfter)||
        (E_OK != RetValRefCertNotBefore) || (E_OK != RetValRefCertNotAfter) ||
        (E_OK != RetValCurrentTime) ||
        (CRYPTO_DATE_SIZE != DateSize)
      )
#else
    if(
        (E_OK != RetValCertNotBefore) || (E_OK != RetValCertNotAfter)||
        (E_OK != RetValRefCertNotBefore) || (E_OK != RetValRefCertNotAfter) ||
        (CRYPTO_DATE_SIZE != DateSize)
      )
#endif /*#if (CRYPTO_CERT_CURRENT_TIME_ENABLED == STD_ON)*/
    {
      RetVal = E_NOT_OK;
    }
  }

  /* !LINKSTO EB_Crypto_01203, 1 */
  /* !LINKSTO EB_Crypto_01204, 1 */
  /*Retrieving of the date keyelements was successful*/
  if(E_OK == RetVal)
  {
    if (E_OK == Crypto_CheckDates(RefDate, VerfDate))
    {
    /*Check if the dates are valid and in range and the for root and valid certificates are the same */
      if(E_OK == Crypto_AL_CompareSignatureAlgorithm(CryptoKeyId, VerifyCryptoKeyId))
      {
        /*get the signature algorithm by calling get element.*/
        RetVal = Crypto_AL_KeyElementGet
                 (
                   CryptoKeyId,
                   CRYPTO_KE_CERTIFICATE_SIGNATURE_ALGORITHM,
                   SignatureAlgorithm,
                   &SignatureAlgorithmLength
                 );
        if(E_OK == RetVal)
        {
          /* !LINKSTO EB_Crypto_01205, 1 */
          RetVal = Crypto_AL_KeyElementGet
                   (
                     CryptoKeyId,
                     CRYPTO_KE_CERTIFICATE_SUBJECT_PUBLIC_KEY,
                     Crypto_CertKey.data,
                     &Crypto_CertKey.length
                   );
          if (E_OK == RetVal)
          {
            RetValRefCertSignature = Crypto_AL_KeyElementGetPtr
                                     (
                                        VerifyCryptoKeyId,
                                        CRYPTO_KE_CERTIFICATE_SIGNATURE,
                                        &SignaturePtr,
                                        &SignatureLength
                                     );
            if
            (
              (
                E_OK ==
                Crypto_AL_KeyElementGetPtr
                (
                  VerifyCryptoKeyId,
                  CRYPTO_KE_CERTIFICATE_SUBJECT,
                  &SignedDataPtr,
                  &SignedDataLength
                )
              ) && (E_OK == RetValRefCertSignature)
            )
            {
              switch (SignatureAlgorithm[0U])
              {
                case CRYPTO_SIGNATURE_ALGORITHM_RSA:
                {
                  /*If the call is not successful, the VerifyPtr shall be CRYPTO_E_VER_NOT_OK,
                  the return value can be ignored.*/
                  /*Call RSA SHA 256 to verify the certificates.*/
                  RetVal = Crypto_AL_SIGNATUREVERIFY_RSA_RSASSA_PSS_Helper_SyncSingleCall
                  (
                    SignedDataPtr,
                    SignedDataLength,
                    SignaturePtr,
                    SignatureLength,
                    &Crypto_CertKey,
                    VerifyPtr
                  );
                  if(CRYPTO_E_VER_OK == *VerifyPtr)
                  {
                    /* !LINKSTO Crypto.Req.Adjustments/SWS_Crypto_00178, 1 */
                    RetVal = Crypto_KeyValidSet(VerifyCryptoKeyId);
                  }
                }
                break;

                default:
                {
                  /*Algorithm not supported.*/
                  RetVal = E_NOT_OK;
                }
                break;

              }
            }
            else
            {
              /* !LINKSTO EB_Crypto_01206, 1 */
              /* !LINKSTO EB_Crypto_01207, 1 */
              RetVal = E_NOT_OK;
            }
          }
          else
          {
            RetVal = E_NOT_OK;
          }
        }
      }
      else
      {
        RetVal = E_NOT_OK;
      }
    }
  }

  /* !LINKSTO EB_Crypto_01300, 1 */
  Crypto_BUSY_CERT_VERIFY = FALSE;

#else
TS_PARAM_UNUSED(CryptoKeyId);
TS_PARAM_UNUSED(VerifyCryptoKeyId);
TS_PARAM_UNUSED(VerifyPtr);
#endif /* #if (CRYPTO_CERT_MANAGEMENT_ENABLED == STD_ON) */
  return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_PL_CertificateVerify
(
  uint32 CryptoKeyId,
  uint32 VerifyCryptoKeyId,
  P2VAR(Crypto_VerifyResultType, AUTOMATIC, CRYPTO_APPL_DATA) VerifyPtr
)
{
  Std_ReturnType RetVal = E_NOT_OK;
  RetVal = Crypto_AL_CertificateVerify(CryptoKeyId, VerifyCryptoKeyId, VerifyPtr);
  return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_CertificateVerify
(
  uint32                                                                CryptoKeyId,
  uint32                                                                VerifyCryptoKeyId,
  P2VAR(Crypto_VerifyResultType, AUTOMATIC, CRYPTO_APPL_DATA) VerifyPtr
)
{
  Std_ReturnType RetVal = E_NOT_OK;

#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)
  if (FALSE == Crypto_Initialized)
  {
    /* !LINKSTO SWS_Crypto_00172, 1 */
    (void) Det_ReportError
    (
     CRYPTO_MODULE_ID,
     CRYPTO_INSTANCE_ID,
     CRYPTO_SID_CERTIFICATEVERIFY,
     CRYPTO_E_UNINIT
    );
    RetVal = E_NOT_OK;
  }
  else if (
           (CRYPTO_KEY_COUNT <= CryptoKeyId      ) ||
           (CRYPTO_KEY_COUNT <= VerifyCryptoKeyId)
          )
  {
    /* !LINKSTO SWS_Crypto_00173, 1 */
    /* !LINKSTO SWS_Crypto_00174_CORRECTION, 1 */
    (void) Det_ReportError
    (
     CRYPTO_MODULE_ID,
     CRYPTO_INSTANCE_ID,
     CRYPTO_SID_CERTIFICATEVERIFY,
     CRYPTO_E_PARAM_HANDLE
    );
    RetVal = E_NOT_OK;
  }
  else if (NULL_PTR == VerifyPtr)
  {
    /* !LINKSTO SWS_Crypto_00175, 1 */
    (void) Det_ReportError
    (
     CRYPTO_MODULE_ID,
     CRYPTO_INSTANCE_ID,
     CRYPTO_SID_CERTIFICATEVERIFY,
     CRYPTO_E_PARAM_POINTER
    );
    RetVal = E_NOT_OK;
  }

#if (CRYPTO_CERT_CURRENT_TIME_ENABLED == STD_ON)
  else if (E_NOT_OK == Crypto_CertificateCurrentDateVerify(VerifyCryptoKeyId))
  {
    /* !LINKSTO SWS_Crypto_00176, 1 */
    (void) Det_ReportError
    (
     CRYPTO_MODULE_ID,
     CRYPTO_INSTANCE_ID,
     CRYPTO_SID_CERTIFICATEVERIFY,
     CRYPTO_E_PARAM_HANDLE
    );
    RetVal = E_NOT_OK;
  }
#endif

  else
#endif
  {
    /* !LINKSTO EB_Crypto_00019, 1 */
    /* !LINKSTO Crypto.Req.Adjustments/SWS_Crypto_00177, 1 */
    RetVal = Crypto_PL_CertificateVerify(CryptoKeyId, VerifyCryptoKeyId, VerifyPtr);
  }
  return RetVal;
}


