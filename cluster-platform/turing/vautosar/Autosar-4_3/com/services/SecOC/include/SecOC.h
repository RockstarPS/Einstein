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
**  FILENAME         : SecOC.h                                                **
**                                                                            **
**  Created on       : July - 2025                                            **
**  Author           : cvenkata                                               **
**  Vendor           :                                                        **
**  DESCRIPTION      :                                                        **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR CP Release 4.3.1                               **
**                                                                            **
*******************************************************************************/

#ifndef SECOC_H
#define SECOC_H

#include "SecOC_Types.h"
#include "SecOC_Cfg.h"
#include "SecOC_Cbk.h"
#include "Rte_Csm_Type.h"
#if (SECOC_CFUNC == SECOC_QUERY_FRESHNESS_VALUE)
#include "SecOC_Callout.h"
#else
#include "Rte_SecOC.h"
#endif

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define SECOC_VENDOR_ID          0x0033u
#define SECOC_MODULE_ID          150u
#define SECOC_INSTANCE_ID        0u
#define SECOC_H_AR_MAJOR_VERSION 4u
#define SECOC_H_AR_MINOR_VERSION 3u
#define SECOC_H_AR_PATCH_VERSION 1u
#define SECOC_H_SW_MAJOR_VERSION 1u
#define SECOC_H_SW_MINOR_VERSION 0u
#define SECOC_H_SW_PATCH_VERSION 0u

/* Service Id */
#define SECOC_INIT_ID                                 0x01u
#define SECOC_DEINIT_ID                               0x05u
#define SECOC_GETVERSIONINFO_ID                       0x02u
#define SECOC_IFTRANSMIT_ID                           0x49u
#define SECOC_TPTRANSMIT_ID                           0x49u
#define SECOC_IFCANCELTRANSMIT_ID                     0x4au
#define SECOC_TPCANCELTRANSMIT_ID                     0x4au
#define SECOC_TPCANCELRECEIVE_ID                      0x4cu
#define SECOC_VERIFYSTATUSOVERRIDE_ID                 0x0bu
#define SECOC_SENDDEFAULTAUTHENTICATIONINFORMATION_ID 0x04u
#define SECOC_RXINDICATION_ID                         0x42u
#define SECOC_TPRXINDICATION_ID                       0x45u
#define SECOC_TXCONFIRMATION_ID                       0x40u
#define SECOC_TPTXCONFIRMATION_ID                     0x48u
#define SECOC_TRIGGERTRANSMIT_ID                      0x41u
#define SECOC_COPYRXDATA_ID                           0x44u
#define SECOC_COPYTXDATA_ID                           0x43u
#define SECOC_STARTOFRECEPTION_ID                     0x46u
#define SECOC_MAINFUNCTIONRX_ID                       0x06u
#define SECOC_MAINFUNCTIONTX_ID                       0x03u
#define SECOC_CSMGENERATEJOBFINISHEDINDICATION_ID     0x50u
#define SECOC_CSMVERIFYJOBFINISHEDINDICATION_ID       0x51u

/* Development Errors */
#define SECOC_E_PARAM_POINTER      0x01u
#define SECOC_E_UNINIT             0x02u
#define SECOC_E_INVALID_PDU_SDU_ID 0x03u
#define SECOC_E_CRYPTO_FAILURE     0x04u
#define SECOC_E_INIT_FAILED        0x07u

/* Runtime Errors */
#define SECOC_E_FRESHNESS_FAILURE 0x08u

#if !defined(SECOC_PARA_UNUSED)
#define SECOC_PARA_UNUSED(x) ((void)(x))
#endif /* SECOC_PARA_UNUSED */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

extern CONST(SecOC_ConfigType, SECOC_CONST) SecOC_ConfigData;

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

 /******************************************************************************
/*
 *    @brief               Initializes the the SecOC module.
 *    @ServiceId           0x01
 *    @Sync/Async          Synchronous
 *    @Reentrancy          Non Reentrant
 *    @param[in]      config: Pointer to a selected configuration structure
 *    @param[out]     None
 *    @param[in/out]  None
 *    @return              None
 */
/******************************************************************************/
FUNC(void, SECOC_CODE) SecOC_Init(P2CONST(SecOC_ConfigType, AUTOMATIC, SECOC_CFG_CONST) config);

 /******************************************************************************
/*
 *    @brief               This service stops the secure onboard communication.
 *                     All buffered I-PDU are removed and have to be obtained
 *                     again, if needed, after SecOC_Init has been called.
 *    @ServiceId           0x05
 *    @Sync/Async          Synchronous
 *    @Reentrancy          Non Reentrant
 *    @param[in]      None
 *    @param[out]     None
 *    @param[in/out]  None
 *    @return              None
 */
/******************************************************************************/
FUNC(void, SECOC_CODE) SecOC_DeInit(void);

 /******************************************************************************
/*
 *    @brief               Returns the version information of this module.
 *    @ServiceId           0x02
 *    @Sync/Async          Synchronous
 *    @Reentrancy          Reentrant
 *    @param[in]      None
 *    @param[out]     versioninfo: Pointer to where to store the version
 *                                  information of this module.
 *    @param[in/out]  None
 *    @return              None
 */
/******************************************************************************/

FUNC(void, SECOC_CODE) SecOC_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, SECOC_APPL_DATA) versioninfo);

 /******************************************************************************
/*
 *    @brief               Requests transmission of a PDU.
 *    @ServiceId           0x49
 *    @Sync/Async          Synchronous
 *    @Reentrancy          Reentrant for different PduIds.
 *    @param[in]      TxPduId: Identifier of the PDU to be transmitted.
 *                     PduInfoPtr: Length of and pointer to the PDU data and
 *                                 pointer to MetaData.
 *    @param[out]     None
 *    @param[in/out]  None
 *    @return              E_OK: Transmit request has been accepted.
 *                     E_NOT_OK: Transmit request has not been accepted.
 */
/******************************************************************************/
FUNC(Std_ReturnType, SECOC_CODE)
SecOC_IfTransmit(PduIdType TxPduId, P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_CONST) PduInfoPtr);

 /******************************************************************************
/*
 *    @brief               Requests transmission of a PDU.
 *    @ServiceId           0x49
 *    @Sync/Async          Synchronous
 *    @Reentrancy          Reentrant for different PduIds.
 *    @param[in]      TxPduId: Identifier of the PDU to be transmitted.
 *                     PduInfoPtr: Length of and pointer to the PDU data and
 *                                 pointer to MetaData.
 *    @param[out]     None
 *    @param[in/out]  None
 *    @return              E_OK: Transmit request has been accepted.
 *                     E_NOT_OK: Transmit request has not been accepted.
 */
/******************************************************************************/
FUNC(Std_ReturnType, SECOC_CODE)
SecOC_TpTransmit(PduIdType TxPduId, P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_CONST) PduInfoPtr);

 /******************************************************************************
/*
 *    @brief               Requests cancellation of an ongoing transmission of a PDU
 *                     in a lower layer communication module.
 *    @ServiceId           0x4a
 *    @Sync/Async          Synchronous
 *    @Reentrancy          Reentrant for different PduIds.
 *    @param[in]      TxPduId: Identification of the PDU to be cancelled.
 *    @param[out]     None
 *    @param[in/out]  None
 *    @return              E_OK: Cancellation was executed successfully by the
 *                           destination module.
 *                     E_NOT_OK: Cancellation was rejected by the destination
 *                               module.
 */
/******************************************************************************/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_IfCancelTransmit(PduIdType TxPduId);

 /******************************************************************************
/*
 *    @brief               Requests cancellation of an ongoing transmission of a PDU
 *                     in a lower layer communication module.
 *    @ServiceId           0x4a
 *    @Sync/Async          Synchronous
 *    @Reentrancy          Reentrant for different PduIds.
 *    @param[in]      TxPduId: Identification of the PDU to be cancelled.
 *    @param[out]     None
 *    @param[in/out]  None
 *    @return              E_OK: Cancellation was executed successfully by the
 *                           destination module.
 *                     E_NOT_OK: Cancellation was rejected by the destination
 *                               module.
 */
/******************************************************************************/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_TpCancelTransmit(PduIdType TxPduId);

 /******************************************************************************
/*
 *    @brief               Requests cancellation of an ongoing reception of a PDU in
 *                     a lower layer transport protocol module.
 *    @ServiceId           0x4c
 *    @Sync/Async          Synchronous
 *    @Reentrancy          Non Reentrant
 *    @param[in]      TxPduId: Identification of the PDU to be cancelled.
 *    @param[out]     None
 *    @param[in/out]  None
 *    @return              E_OK: Cancellation was executed successfully by the
 *                           destination module.
 *                     E_NOT_OK: Cancellation was rejected by the destination
 *                               module.
 */
/******************************************************************************/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_TpCancelReceive(PduIdType RxPduId);

 /******************************************************************************
/*
 *    @brief               This service provides the ability to force specific
 *                     behaviour of SecOc: accept or drop an I-PDU with or
 *                     without performing the verification of authenticator or
 *                     independent of the authenticator verification result, and
 *                     force a specific result for SecOC_VerificationResultType
 *                     allowing additional fault handling in the application.
 *    @ServiceId           0x0b
 *    @Sync/Async          Synchronous
 *    @Reentrancy          Reentrant for different Freshness ValueIDs
 *    @param[in]      ValueID: ID of the Freshness Value used to control the
 *                     verification behaviour of all assigned Secured I-PDUs
 *                     according to the override Status.Or ValueID is the DataID
 *                     of a Secured I-PDU that shall be controlled by the
 *                     overrideStatus.
 *                     overrideStatus: Defines whether verification is executed
 *                     and whether the I-PDU is passed on, and for how long the
 *                     override is active.
 *                     numberOfMessagesToOverride: Number of sequential
 *                     verification to override when using a specific counter
 *                     for authentication verification.
 *    @param[out]     None
 *    @param[in/out]  None
 *    @return              E_OK: request successful
 *                     E_NOT_OK: request failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, SECOC_CODE)
SecOC_VerifyStatusOverride(uint16 ValueID, uint8 overrideStatus, uint8 numberOfMessagesToOverride);

#if defined(SECOC_DEFAULT_AUTHENTICATION_INFORMATION_PATTERN)
 /******************************************************************************
/*
 *    @brief               The service provides the ability to enable the sending of
 *                     un-authenticated PDU to lower layer.
 *    @ServiceId           0x04
 *    @Sync/Async          Synchronous
 *    @Reentrancy          Reentrant for different FreshnessValueIDs.
 *    @param[in]      FreshnessValueID: ID of the Freshness Value for which
 *                     sending SecOCDefaultAuthenticationInformationPattern
 *                     should be enabled.
 *                     sendDefaultAuthenticationInformation: FALSE - sending
 *                     SecOCDefaultAuthenticationInformation Pattern shall be
 *                     disabled for given FreshnessValueID TRUE - sending
 *                     SecOCDefaultAuthenticationInformationPattern shall be
 *                     enabled for given FreshnessValueID
 *    @param[out]     None
 *    @param[in/out]  None
 *    @return              E_OK: request successful
 *                     E_NOT_OK: request failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, SECOC_CODE)
SecOC_SendDefaultAuthenticationInformation(uint16 FreshnessValueID, boolean sendDefaultAuthenticationInformation);
#endif

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

#endif /* SECOC_H */
