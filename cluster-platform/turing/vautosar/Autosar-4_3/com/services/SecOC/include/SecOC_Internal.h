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
**  FILENAME         : SecOC_Internals.h                                      **
**                                                                            **
**  Created on       : July - 2025                                            **
**  Author           : cvenkata                                               **
**  Vendor           :                                                        **
**  DESCRIPTION      :                                                        **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR CP Release 4.3.1                               **
**                                                                            **
*******************************************************************************/

#ifndef SECOC_INTERNAL_H
#define SECOC_INTERNAL_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "ComStack_Types.h"
#include "SecOC.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define SECOC_MAX_AUTHENTICATOR_LEN     (16u + 1u)
#define SECOC_MAX_RX_SECURED_MSG_LENGTH 100u

#define SECOC_DATAID_LEN                2u

/* Event */
#define SECOC_EVENT_TX_ALL                     0x00FFu
#define SECOC_TX_REQUEST                       0x0001u
#define SECOC_TX_DATA_ACQUIRED                 0x0002u
#define SECOC_TX_AUTHENTIC_PDU_CONFIRMED       0x0004u
#define SECOC_TX_CRYPTOGRAPHIC_PDU_CONFIRMED   0x0008u
#define SECOC_TX_GENERATE_FINISH_IND_WAITING   0x0010u
#define SECOC_TX_GENERATE_FINISH_IND_CONFIRMED 0x0020u

#define SECOC_EVENT_RX_ALL                     0x01FFu
#define SECOC_RX_INDICATION                    0x0001u
#define SECOC_RX_SECURED_PDU                   0x0002u
#define SECOC_RX_AUTHENTIC_PDU                 0x0004u
#define SECOC_RX_CRYPTOGRAPHIC_PDU             0x0008u
#define SECOC_RX_PARSED_MESSAGE                0x0010u
#define SECOC_RX_VERIFY_FINISH_IND_WAITING     0x0020u
#define SECOC_RX_VERIFY_FINISH_IND_CONFIRMED   0x0040u
#define SECOC_RX_TP_DATA_FROM_LOWER            0x0080u
#define SECOC_RX_TRANS_TP_DATA_TO_UPPER        0x0100u


/* Returns the remainder result, only for powers of 2 where the divisor is */
#define SECOC_MOD_SHIFT(dividend, divisor) ((dividend) & ((divisor)-1u))

typedef uint8 SecOC_FreshnessArrayType;

/* Returns the remainder form 8 */
static inline uint8 SECOC_MOD_FROM_EIGHT(uint16 dividend)
{
    return (uint8)(dividend) & 0X07u;
}

/* Returns the quotient, only for powers of 2 where the divisor is, y is raised to the power of 2*/
static inline uint16 SECOC_DIV_SHIFT(uint16 dividend, uint16 y)
{
    return (dividend) >> (y);
}

static uint16 SECOC_BIT_TO_BYTE(uint16 nbits)
{
    return SECOC_DIV_SHIFT(((nbits) + 7u), 3u);
}

/* Macro used to get configuration data */
/*******************************************************************************
**                      Private Type Definitions                               *
*******************************************************************************/
typedef enum
{
    SECOC_TX_NONE,
    SECOC_TX_CALC,
    SECOC_TX_TRANS,
    SECOC_TX_RETRY,
    SECOC_TX_CANCEL
} SecOC_TxStatusType;

typedef enum
{
    SECOC_RX_NONE,
    SECOC_RX_CALC,
    SECOC_RX_RETRY
} SecOC_RxStatusType;

#if (SECOC_TX_PDU_NUM > 0u)
/* Define transmit pdu runtime value */
typedef struct
{
    SecOC_TxStatusType txPduStatus;
    PduLengthType txPduLength;
    PduLengthType txSecuredPduLen;
    PduLengthType txAuthenticPduLen;
    PduLengthType txCryptographicPduLen;
    SecOC_FreshnessArrayType txFreshnessValue;
    boolean txPduReady;
    uint16 txAuthBuildCnt;
    uint8 txResultBuffer[SECOC_MAX_AUTHENTICATOR_LEN];
    uint32 txResultLength;
    boolean txDefaultAuthInfoEnable;
#if (SECOC_TX_TP_PDU_NUM > 0u)
    PduLengthType tpTxPduOffset;
#endif
} SecOC_TxPduRTType;
#endif /* SECOC_TX_PDU_NUM > 0u */

#if (SECOC_RX_PDU_NUM > 0u)
/* Queue Info type for SecOC rx process */
/* Data in queue buffer:
 * QUEUE_INFO|DATA|QUEUE_INFO|DATA...
 */
typedef struct
{
    PduLengthType pduLength; /* uint32 */
    PduIdType pduId; /* uint16 */
} SecOC_QueueInfoType;

typedef struct
{
    uint16 queueInfoIdx;
    uint16 freeQueSize;
    uint16 freeQueStartIdx;
    uint16 queueFrameCnt;
} SecOC_QueueManageType;

/* Define receive pdu runtime value */
typedef struct
{
    SecOC_RxStatusType rxPduStatus;
    PduIdType curPduId;
    PduLengthType rxSecuredPduLen;
    PduLengthType rxAuthenticPduLen;
    PduLengthType rxCryptographicPduLen;
    PduLengthType rxParsedAuthPduLen;
    SecOC_QueueManageType queueManage;
    uint8 rxParsedFreshnessValue[8u]; /* Max 64 bits */
    uint8 rxParsedAuthenticator[SECOC_MAX_AUTHENTICATOR_LEN];
    uint8* rxParsedAuthPduBufPtr;
    uint16 rxAuthBuildAttempts;
    uint16 rxVerifyAttempts;
    SecOC_FreshnessArrayType rxFreshnessValue;
    Crypto_VerifyResultType rxVerifyResult;
    uint8 rxOverrideStatus;
    uint8 rxNumOfMsgToOverride;
    uint8 rxBakNumOfMsgToOverride;
    SecOC_VerificationResultType rxVeryfyResult;
#if (SECOC_RX_TP_PDU_NUM > 0)
    P2VAR(uint8, TYPEDEF, SECOC_APPL_DATA) tpRxDestBufPtr;
    PduLengthType sduRemaining;
    PduLengthType upLayerBufSize;
    PduLengthType tpRxPduOffset;
#endif
} SecOC_RxPduRTType;
#endif /* SECOC_RX_PDU_NUM > 0u */

/*******************************************************************************
**                      Revision  History                                     **
*******************************************************************************/
/*---------------------------------------------------------------------------
Date              : 27/Jul/2025
By                : cvenkata
Traceability      : DICVA-19595
Change Description: SecOC module - Initial development.
-----------------------------------------------------------------------------*/

#endif /* SECOC_INTERNAL_H */
