/*******************************************************************************
 * Copyright (C) 2025 Visteon Corporation., Ltd.
 * All rights reserved.
 *
 * NOTICE: This is an unpublished work of authorship, which contains trade
 * secrets. Visteon Corporation owns all rights to this work and intends to
 * maintain it in confidence to preserve its trade secret status.
 * Visteon Corporation reserves the right, under the copyright laws of the
 * United States or those of any other country that may have jurisdiction,
 * to protect this work as an unpublished work, in the event of an inadvertent
 * or deliberate unauthorized publication. Visteon Corporation also reserves its
 * rights under all copyright laws to protect this work as a published work,
 * when appropriate. Those having access to this work may not copy it, use it,
 * modify it, or disclose the information contained in it without the written
 * authorization of Visteon Corporation.
/*******************************************************************************
********************************************************************************
**                                                                            **
**  FILENAME         : SecOC_Types.h                                          **
**                                                                            **
**  Created on       : July - 2025                                            **
**  Author           : cvenkata                                               **
**  Vendor           :                                                        **
**  DESCRIPTION      :                                                        **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR CP Release 4.3.1                               **
**                                                                            **
*******************************************************************************/

#ifndef SECOC_TYPES_H
#define SECOC_TYPES_H

#include "ComStack_Types.h"


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#ifndef SECOC_CONST
#define SECOC_CONST
#endif

#ifndef SECOC_VAR
#define SECOC_VAR
#endif

#define SECOC_OVERRIDE_FAIL 0x00u
#define SECOC_OVERRIDE_FAIL_N_MESSAGES 0x01u
#define SECOC_OVERRIDE_CANCEL 0x02u
#define SECOC_OVERRIDE_PASS 0x28u
#define SECOC_OVERRIDE_PASS_N_MESSAGES 0x29u
#define SECOC_OVERRIDE_PASS_UNTIL_NOTICE 0x40
#define SECOC_OVERRIDE_PASS_UNTIL_LIMIT 0x42
#define SECOC_OVERRIDE_SKIP_UNTIL_LIMIT 0x41
#define SECOC_OVERRIDE_SKIP_UNTIL_NOTICE 0x43
#define SECOC_OVERRIDE_DROP_UNTIL_LIMIT 0x81
#define SECOC_OVERRIDE_DROP_UNTIL_NOTICE 0x83


/* States of the SecOC module */
typedef enum
{
    SECOC_UNINIT,
    SECOC_INIT
} SecOC_StateType;

/* SecOC_QueryFreshnessValueType */
typedef enum
{
	SECOC_CFUNC,
	SECOC_RTE
} SecOC_QueryFreshnessValueType;


typedef struct
{
    uint32 SecOCBufferLength;
    P2VAR(boolean, TYPEDEF, SECOC_CFG_DATA) SecOCSameBufferInUse;
    uint16 SecOCAuthenticPduBuffLength;
    P2VAR(uint8, TYPEDEF, SECOC_CFG_DATA) SecOCAuthenticPduBufferRef;
    uint16 SecOCSecuredPduBuffLength;
    P2VAR(uint8, TYPEDEF, SECOC_CFG_DATA) SecOCSecuredPduBufferRef;
    uint16 SecOCColAuthenticPduBuffLength;
    P2VAR(uint8, TYPEDEF, SECOC_APPL_DATA) SecOCColAuthenticPduBufferRef;
    uint16 SecOCCryptographicPduBuffLength;
    P2VAR(uint8, TYPEDEF, SECOC_APPL_DATA) SecOCCryptographicPduBufferRef;    
} SecOC_SameBufferPduCollectionType;


typedef struct
{

} SecOC_PduBufferHandleType;

typedef enum
{
    SECOC_QUEUE,
    SECOC_REJECT,
    SECOC_REPLACE
} SecOC_ReceptionOverflowStrategyType;

typedef enum
{
    SECOC_BOTH,         /*Both True and False AuthenticationStatus is propagated to SWC*/
    SECOC_FAILURE_ONLY, /*Only False AuthenticationStatus is propagated to SWC*/
    SECOC_NONE          /*No AuthenticationStatus is propagated to SWC*/
} SecOC_VeriStatusPropModeType;

typedef enum
{
	SECOC_VERIFICATIONSUCCESS,
	SECOC_VERIFICATIONFAILURE,
	SECOC_FRESHNESSFAILURE,
	SECOC_AUTHENTICATIONBUILDFAILURE,
    SECOC_NO_VERIFICATION,
    SECOC_VERIFICATIONFAILURE_OVERWRITTEN
} SecOC_VerificationResultType;

typedef enum
{
    SECOC_IFPDU,
    SECOC_TPPDU
} SecOC_PduType;

typedef enum
{
    SECOC_CRYPTO_PROCESSING_ASYNC,
    SECOC_CRYPTO_PROCESSING_SYNC
} SecOC_CryptoProcessingTypeType;

typedef enum
{
    SECOC_CSMMAC,
    SECOC_CSMSIGNATURE
} SecOC_CsmPrimitivesType;

typedef struct
{
    uint32 SecOCJobId;
    SecOC_CryptoProcessingTypeType SecOCCryptoProcessingType;
    SecOC_CsmPrimitivesType SecOCCsmPrimitives;
} SecOC_CsmJobType;

typedef struct
{
    PduIdType SecOCRxPduRAsUpLayerId; /*the up layer pdu id.*/
    SecOC_PduType SecOCPduType;
    PduLengthType SecOCPduLength;
} SecOC_RxAuthenticPduLayerType;

typedef struct
{
    uint8 SecOCAuthPduHeaderLength;
    PduIdType SecOCRxSecuredLayerPduId;
    PduIdType SecOCRxPduRAsLowerLayerPduId;
    boolean SecOCSecuredRxPduVerification;
    boolean SecOCDynamicLength;
    PduLengthType SecOCPduLength;
    uint16 SecOCRxSecuredPduBuffLength;
    P2VAR(uint8, TYPEDEF, SECOC_APPL_DATA) SecOCRxSecuredPduBufferRef;
} SecOC_RxSecuredPduType;

typedef struct
{
    uint8 SecOCAuthPduHeaderLength;
    PduIdType SecOCRxAuthenticPduId;
    PduIdType SecOCRxPduRAsLowerLayerPduId;
    boolean SecOCDynamicLength;
    PduLengthType SecOCPduLength;
    uint16 SecOCRxColAuthenticPduBuffLength;
    P2VAR(uint8, TYPEDEF, SECOC_APPL_DATA) SecOCRxColAuthenticPduBufferRef;
} SecOC_RxAuthenticPduType;

typedef struct
{
    PduIdType SecOCRxCryptographicPduId;
    PduIdType SecOCRxPduRAsLowerLayerPduId;
    boolean SecOCDynamicLength;
    PduLengthType SecOCPduLength;
    uint16 SecOCRxCryptographicPduBuffLength;
    P2VAR(uint8, TYPEDEF, SECOC_APPL_DATA) SecOCRxCryptographicPduBufferRef;
} SecOC_RxCryptographicPduType;

typedef struct
{
    uint16 SecOCMessageLinkLen;
    uint16 SecOCMessageLinkPos;
} SecOC_UseMessageLinkType;

typedef struct
{
    boolean SecOCSecuredRxPduVerification;
    P2CONST(SecOC_RxAuthenticPduType, TYPEDEF, SECOC_CONST) SecOCRxAuthenticPdu;
    P2CONST(SecOC_RxCryptographicPduType, TYPEDEF, SECOC_CONST) SecOCRxCryptographicPdu;
    P2CONST(SecOC_UseMessageLinkType, TYPEDEF, SECOC_CONST) SecOCUseMessageLink;
} SecOC_RxSecuredPduCollectionType;

typedef struct
{
    P2CONST(SecOC_RxSecuredPduType, TYPEDEF, SECOC_CONST) SecOCRxSecuredPdu;
    P2CONST(SecOC_RxSecuredPduCollectionType, TYPEDEF, SECOC_CONST)
    SecOCRxSecuredPduCollection;
} SecOC_RxSecuredPduLayerType;

typedef struct
{
    uint32 SecOCSecuredRxPduLength;
    uint32 SecOCSecuredRxPduOffset;
} SecOC_RxPduSecuredAreaType;

typedef struct
{
	uint16 freshnessValueID;
	SecOC_VerificationResultType verificationStatus;
	uint16 secOCDataId;
} SecOC_VerificationStatusType;

typedef struct
{
    uint16 SecOCAuthDataFreshnessLen;
    uint16 SecOCAuthDataFreshnessStartPosition;
    uint16 SecOCAuthenticationBuildAttempts;
    uint16 SecOCAuthenticationVerifyAttempts;
    uint16 SecOCAuthInfoTxLength;       /* Dbc Msg attr. SCP_AuthInfoTxLength */
    uint16 SecOCDataId;                 /* Dbc Msg attr. SCP_DataId */
    uint16 SecOCFreshnessValueId;
    uint8 SecOCFreshnessValueLength;    /* Dbc Msg attr. SCP_FreshnessValueLength */
    uint8 SecOCFreshnessValueTxLength;  /* Dbc Msg attr. SCP_FreshnessValueTxLength */
    SecOC_ReceptionOverflowStrategyType SecOCReceptionOverflowStrategy;
    uint16 SecOCReceptionQueueSize;
    P2VAR(uint8, TYPEDEF, SECOC_CFG_DATA) SecOCReceptionQueueRef;
    boolean SecOCUseAuthDataFreshness;
    SecOC_VeriStatusPropModeType SecOCVerificationStatusPropagationMode;
    P2CONST(SecOC_CsmJobType, TYPEDEF, SECOC_CONST) SecOCRxAuthServiceConfigRef;
    P2CONST(SecOC_SameBufferPduCollectionType, TYPEDEF, SECOC_CONST)
    SecOCSameBufferPduRef;
    P2CONST(SecOC_RxAuthenticPduLayerType, TYPEDEF, SECOC_CONST)
    SecOCRxAuthenticPduLayer;
    P2CONST(SecOC_RxPduSecuredAreaType, TYPEDEF, SECOC_CONST)
    SecOCRxPduSecuredArea;
    P2CONST(SecOC_RxSecuredPduLayerType, TYPEDEF, SECOC_CONST)
    SecOCRxSecuredPduLayer;
    uint16 SecOCAuthenticPduBuffLength;
    P2VAR(uint8, TYPEDEF, SECOC_CFG_DATA) SecOCAuthenticPduBufferRef;
    uint16 SecOCAuthFrsInfoLength;
} SecOC_RxPduProcessingType;

typedef struct
{
    SecOC_PduType SecOCPduType;
    PduIdType SecOCTxAuthenticLayerPduId; /*PDU identifier assigned by SecOC module.*/
    PduIdType SecOCTxPduRAsUpLayerId;     /* Save up layer pduid */
} SecOC_TxAuthenticPduLayerType;

typedef struct
{
    uint32 SecOCSecuredTxPduLength;
    uint32 SecOCSecuredTxPduOffset;
} SecOC_TxPduSecuredAreaType;

typedef struct
{
    uint8 SecOCAuthPduHeaderLength;
    PduIdType SecOCTxSecuredLayerPduId;  /*PDU identifier assigned by SecOC module.*/
    PduIdType SecOCTxPduRAsLowerLayerId; /* Save lower layer pduid */
    uint16 SecOCTxSecuredPduBuffLength;
    P2VAR(uint8, TYPEDEF, SECOC_APPL_DATA) SecOCTxSecuredPduBufferRef;
} SecOC_TxSecuredPduType;

typedef struct
{
    uint8 SecOCAuthPduHeaderLength;
    PduIdType SecOCTxAuthenticPduId;
    PduIdType SecOCTxPduRAsLowerLayerId; /* Save lower layer pduid */
    uint16 SecOCTxColAuthenticPduBuffLength;
    P2VAR(uint8, TYPEDEF, SECOC_APPL_DATA) SecOCTxColAuthenticPduBufferRef;
} SecOC_TxAuthenticPduType;

typedef struct
{
    PduIdType SecOCTxCryptographicPduId;
    PduIdType SecOCTxPduRAsLowerLayerId; /* Save lower layer pduid */
    uint16 SecOCTxCryptographicPduBuffLength;
    P2VAR(uint8, TYPEDEF, SECOC_APPL_DATA) SecOCTxCryptographicPduBufferRef;
} SecOC_TxCryptographicPduType;

typedef struct
{
    P2CONST(SecOC_TxAuthenticPduType, TYPEDEF, SECOC_CONST) SecOCTxAuthenticPdu;
    P2CONST(SecOC_TxCryptographicPduType, TYPEDEF, SECOC_CONST)
    SecOCTxCryptographicPdu;
    P2CONST(SecOC_UseMessageLinkType, TYPEDEF, SECOC_CONST) SecOCUseMessageLink;
} SecOC_TxSecuredPduCollectionType;

typedef struct
{
    P2CONST(SecOC_TxSecuredPduType, TYPEDEF, SECOC_CONST) SecOCTxSecuredPdu;
    P2CONST(SecOC_TxSecuredPduCollectionType, TYPEDEF, SECOC_CONST)
    SecOCTxSecuredPduCollection;
} SecOC_TxSecuredPduLayerType;

typedef struct
{
    uint16 SecOCAuthenticationBuildAttempts;
    uint16 SecOCAuthInfoTxLength;
    uint16 SecOCDataId;
    uint16 SecOCFreshnessValueId;
    uint8 SecOCFreshnessValueLength;
    uint8 SecOCFreshnessValueTxLength;
    boolean SecOCProvideTxTruncatedFreshnessValue;
    boolean SecOCUseTxConfirmation;
    P2CONST(SecOC_SameBufferPduCollectionType, TYPEDEF, SECOC_CONST)
    SecOCSameBufferPduRef;
    P2CONST(SecOC_CsmJobType, TYPEDEF, SECOC_CONST) SecOCTxAuthServiceConfigRef;
    P2CONST(SecOC_TxAuthenticPduLayerType, TYPEDEF, SECOC_CONST)
    SecOCTxAuthenticPduLayer;
    P2CONST(SecOC_TxPduSecuredAreaType, TYPEDEF, SECOC_CONST)
    SecOCTxPduSecuredArea;
    P2CONST(SecOC_TxSecuredPduLayerType, TYPEDEF, SECOC_CONST)
    SecOCTxSecuredPduLayer;
    uint16 SecOCAuthenticPduBuffLength;
    P2VAR(uint8, TYPEDEF, SECOC_CONST) SecOCAuthenticPduBufferRef;
    /* ((SecOCAuthInfoTxLength + SecOCFreshnessValueTxLength) + 7)/8 */
    uint16 SecOCAuthFrsInfoLength;
} SecOC_TxPduProcessingType;


typedef void (*SecOC_VerificationStatusCalloutType)(SecOC_VerificationStatusType);


/* SWS_SecOC_00104: Configuration data structure of SecOC module */
typedef struct
{
    P2CONST(SecOC_RxPduProcessingType, TYPEDEF, SECOC_CONST)
    SecOCRxPduProcessing;
    P2CONST(SecOC_SameBufferPduCollectionType, TYPEDEF, SECOC_CONST)
    SecOCSameBufferPduCollection;
    P2CONST(SecOC_TxPduProcessingType, TYPEDEF, SECOC_CONST)
    SecOCTxPduProcessing;
    P2CONST(SecOC_VerificationStatusCalloutType, TYPEDEF, SECOC_CONST)
    SecOCVerificationStatusCallout;
    P2VAR(boolean, TYPEDEF, SECOC_APPL_DATA) SecOCIgnoreVerificationResultRef;
} SecOC_ConfigType;

/*******************************************************************************
**                      Revision  History                                     **
*******************************************************************************/
/*---------------------------------------------------------------------------
Date              : 27/Jul/2025
By                : cvenkata
Traceability      : DICVA-19595
Change Description: SecOC module - Initial development.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 28/Jul/2025
By                : cvenkata
Traceability      : DICVA-19595
Change Description: SecOC module - Initial development Review comments fix.
-----------------------------------------------------------------------------*/

#endif /* SECOC_TYPES_H */
