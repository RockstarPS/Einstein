/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
*                                                                                                                   *
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                  *
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its      *
* rights under all copyright laws to protect this work as a published work, when appropriate.                       *
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it  *
* without the written authorization of Visteon Corporation.                                                         *
********************************************************************************************************************/
/*!*****************************************************************************************************************
*    @file CanTp.h
*    @ingroup CanTp
*    @brief This file provides the declaration of the CanTp API. This header file should be included by other  
*    modules that use the CanTp API.
********************************************************************************************************************/
#ifndef CANTP_H
#define CANTP_H
/*******************************************************************************************************************
*  HEADER INCLUDES                                                                                                 *
********************************************************************************************************************/
#include "ComStack_Types.h"
#include "CanTp_Cfg.h"
/*******************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
/* Software Version */
/*! Defines the CAN TP SW major version */
#define CANTP_SW_MAJOR_VERSION                  0U
/*! Defines the CAN TP SW minor version */
#define CANTP_SW_MINOR_VERSION                  0U
/*! Defines the CAN TP SW patch version */  
#define CANTP_SW_PATCH_VERSION                  1U

/* AUTOSAR Release version*/
/*! Defines the AUTOSAR CAN TP Release major version */
#define CANTP_AR_RELEASE_MAJOR_VERSION          4u
/*! Defines the AUTOSAR CAN TP Release minor version */
#define CANTP_AR_RELEASE_MINOR_VERSION          2u
/*! Defines the AUTOSAR CAN TP Release revision version */
#define CANTP_AR_RELEASE_REVISION_VERSION       1u


/* Module Information  */
/*! Defines the Vendor Id of CAN TP module.*/
#define CANTP_VENDOR_ID                         51u
/*! Defines the Module Id of CAN TP module */
#define CANTP_MODULE_ID                         35u
/*! Defines the instance id of the CAN TP module */
#define CANTP_INSTANCE_ID                       0U
/* API Service IDs */
/*! Defines the service Id for CanTp_Init function */
#define CANTP_SID_INIT                          (0x01u)
/*! Defines the service Id for CanTp_Shutdown function */
#define CANTP_SID_SHUTDOWN                      (0x02u)
/*! Defines the service Id for CanTp_Transmit function */
#define CANTP_SID_TRANSMIT                      (0x03u)
/*! Defines the service Id for CanTp_RxIndication function */
#define CANTP_SID_RXINDICATION                  (0x04u)
/*! Defines the service Id for CanTp_TxConfirmation function */
#define CANTP_SID_TXCONFIRMATION                (0x05u)
/*! Defines the service Id for CanTp_MainFunction function */
#define CANTP_SID_MAINFUNCTION                  (0x06u)
/*! Defines the service Id for CanTp_GetVersionInfo function */
#define CANTP_SID_GETVERSIONINFO                (0x07u)
/*! Defines the service Id for CanTp_CancelTransmit function */
#define CANTP_SID_CANCELTRANSMIT                (0x08u)
/*! Defines the service Id for CanTp_CancelReceive function */
#define CANTP_SID_CANCELRECEIVE                 (0x09u)
/*! Defines the service Id for CanTp_ChangeParameter function */
#define CANTP_SID_CHANGEPARAMETER               (0x0Au)
/*! Defines the service Id for CanTp_ReadParameter function */
#define CANTP_SID_READPARAMETER                 (0x0Bu)

/* Error IDs*/
/*! Defines the no error type */
#define CANTP_E_NO_ERROR                        (0U)
/*! Defines the error Id for Module initialization failure. */
#define CANTP_E_INIT_FAILED                     (0x04U)
/*! Defines the error Id for accessing API service used without module initialization. */
#define CANTP_E_UNINIT                          (0x20U)
/*! Defines the error Id for Invalid Transmit PDU identifier. */
#define CANTP_E_INVALID_TX_ID                   (0x30U)
/*! Defines the error Id for Invalid Receive PDU identifier. */
#define CANTP_E_INVALID_RX_ID                   (0x40U)
/*! Defines the error Id for PDU received with a length smaller than 8 bytes. */
#define CANTP_E_PADDING                         (0x70U)
/*! Defines the error Id for API service called with wrong parameter(s). */
#define CANTP_E_PARAM_CONFIG                    (0x01U)
/*! Defines the error Id for API service called with wrong parameter(s). */
#define CANTP_E_PARAM_ID                        (0x02U)
/*! Defines the error Id for API service called with a NULL pointer. */
#define CANTP_E_PARAM_POINTER                   (0x03U)
/*! Defines the error Id when CanTp_Transmit() is called for a configured Tx I-Pdu with functional
addressing and the length parameter indicates, that the message can not be sent with a SF. */
#define CANTP_E_INVALID_TATYPE                  (0x90U)
/*! Defines the error Id when requested operation is not supported – a cancel transmission/reception request for an 
    N-SDU that it is not on transmission/reception process. */
#define CANTP_E_OPER_NOT_SUPPORTED              (0xA0U)
/*! Defines the error Id when error occurred during a reception or a transmission: any protocol timeout error or 
    implementation specific error */
#define CANTP_E_COM                             (0xB0U)
/*! Defines the error Id when error event reported on completion of a reception operation */
#define CANTP_E_RX_COM                          (0xC0U)
/*! Defines the error Id when error event reported on completion of a transmission operation */
#define CANTP_E_TX_COM                          (0xD0U)
/*Datatype Max Range*/
#define CANTP_UINT_32_MAX   (0xFFFFFFFFU)
#define CANTP_UINT_16_MAX   (0xFFFFU)
#define CANTP_UINT_8_MAX 	(0xFFU)
/*******************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPE                                                                                       *
********************************************************************************************************************/
/*!**************************************************************************************************************** 
*   @brief      This function initializes the CanTp module.
*   @param[in]  CfgPtr  Pointer to the CanTp post-build configuration data.
*   @ServiceID  0x01
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant.
*   @note       The CanTp module’s environment shall call CanTp_Init before using the CanTp module for further
*               processing
********************************************************************************************************************/
void CanTp_Init(const CanTp_ConfigType* CfgPtr); 

/*!***************************************************************************************************************** 
*   @brief      This function returns the version information of the CanTp module.
*   @param[out] VersionInfo  Indicator as to where to store the version information of this module
*   @ServiceID  0x07
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant.
********************************************************************************************************************/
void CanTp_GetVersionInfo(Std_VersionInfoType* VersionInfo); 

/*!***************************************************************************************************************** 
*   @brief      This function is called to shutdown the CanTp module.
*   @ServiceID  0x02
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
void CanTp_Shutdown(void); 
 
/*!***************************************************************************************************************** 
*   @brief      This service is used to request the transfer of segmented data.
*   @param[in]  CanTpTxSduId    This parameter contains the unique CanTp module identifier of the CAN N-SDU to be 
*               transmitted.
*   @param[in]  CanTpTxInfoPtr  A pointer to a structure with CAN N-SDU related data: the length of the N-SDU that 
*               shall be transmitted, and a pointer to SDU data, which contains the addressing information for N-SDUs 
*               with MetaData (generic connections), and NULL otherwise.
*   @return     Std_ReturnType
*               E_OK: The request can be started successfully 
*               E_NOT_OK: The request cannot be started (e.g. a transmit request is in progress with the same 
*                         N-SDU identifier)
*   @ServiceID  0x03
*   @Sync/Async Asynchronous 
*   @Reentrancy Reentrant
********************************************************************************************************************/
Std_ReturnType CanTp_Transmit(PduIdType CanTpTxSduId, const PduInfoType* CanTpTxInfoPtr); 

/*!***************************************************************************************************************** 
*   @brief      This service primitive is used to cancel the transfer of a pending CAN N-SDU. When the function returns,
*               no transmission is in progress anymore with the given N-SDU identifier.
*   @param[in]  CanTpTxSduId This parameter contains the unique CanTp module identifier of the N-SDU to be canceled 
*               for transmission.
*   @return     Std_ReturnType
*               E_OK: Cancellation request of the specified N-SDU is accepted.
*               E_NOT_OK: Cancellation request is rejected; the reason can be that request is issued for an N-SDU that 
*               is not segmented, request is issued after the last CF has been requested for transmission or 
*               cancellation is not possible for the related N-SDU due to configuration.
*   @ServiceID  0x08
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
Std_ReturnType CanTp_CancelTransmit(PduIdType CanTpTxSduId); 

/*!***************************************************************************************************************** 
*   @brief      This service is used to cancel the reception of an ongoing N-SDU.
*   @param[in]  CanTpRxSduId Identifier of the received N-SDU.
*   @return     Std_ReturnType
*               E_OK: Cancellation request of the specified N-SDU is accepted.
*               E_NOT_OK: Cancellation request is rejected; the reason can be that request is issued for an N-SDU that 
*               is not segmented or request is issued for an N-SDU that is not in the reception process.
*   @ServiceID  0x09
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
Std_ReturnType CanTp_CancelReceive(PduIdType CanTpRxSduId); 
#if (CANTP_CHANGE_PARAMETER_API == STD_ON)
/*!***************************************************************************************************************** 
*   @brief      This service is used to request the change of reception parameters BS and STmin for a specified N-SDU.
*   @param[in]  Id Identifier of the received N-SDU on which the reception parameter has to be changed.
*   @param[in]  Parameter Specify the parameter to which the value has to be changed (BS or STmin).
*   @param[in]  Value The new value of the parameter.
*   @return     Std_ReturnType
*               E_OK: request is accepted
*               E_NOT_OK: request is not accepted
*   @ServiceID  0x0a
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
Std_ReturnType CanTp_ChangeParameter(PduIdType Id,TPParameterType Parameter,uint16 Value);
#endif
#if(CANTP_READ_PARAMETER_API == STD_ON)
/*!***************************************************************************************************************** 
*   @brief      This service is used to read the current value of reception parameters BS and STmin for a specified 
*               N-SDU.
*   @param[in]  Id Identifier of the received N-SDU on which the reception parameter are read.
*   @param[in]  Parameter Specify the parameter to which the value has to be read (BS or STmin).
*   @param[out] Value Pointer where the parameter value will be provided.
*   @return     Std_ReturnType
*               E_OK: request is accepted
*               E_NOT_OK: request is not accepted
*   @ServiceID  0x0b
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
Std_ReturnType CanTp_ReadParameter(PduIdType Id,TPParameterType Parameter,uint16* Value); 
#endif

#ifndef SCHM_CANTP_H
/*!***************************************************************************************************************** 
*   @brief      The main function for scheduling the CAN TP.
*   @ServiceID  0x06
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant.
*   @note       CanTp_MainFunction is involved in handling of CAN TP timeouts N_As, N_Bs, N_Cs, N_Ar, N_Br,
*               N_Cr and STMmin.The function CanTp_MainFunction is affected by configuration parameter 
*               CanTpMainFunctionPeriod
********************************************************************************************************************/
void CanTp_MainFunction(void); 
#endif /* SCHM_CANTP_H */

#endif /* CANTP_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
/*!*****************************************************************************************************************
*  @date 3-Feb-2021
*  @author  pmanoj2
*  @brief Traceability - 1206950: 1206951: [hondabev] CERTC New rules(CAN)
*
*******************************************************************************************************************/


