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
/*!******************************************************************************************************************
*   @file Com.h
*   @ingroup Com
*   @brief This file provides the declaration of the Com API. This header file should be included by other  
*   modules that use the Com API.
*   @defgroup Com
*   @brief The Com module is located between the PDU Router and the RTE . It provides the signal signal oriented data
*   interface for the RTE.
*   @details Main-Features of AUTOSAR COM are:
*   -Provision of signal oriented data interface for the RTE
*   -Packing of AUTOSAR signals to I-PDUs to be transmitted
*   -Unpacking of received I-PDUs and provision of received signals to RTE
*   -Routing of signals from received I-PDUs into I-PDUs to become transmitted
*   -Routing of signal groups from received I-PDUs into I-PDUs to become transmitted
*   -Communication transmission control (start/ stop of I-PDU groups)
*   -Replications of send requests
*   -Guarantee of minimum distances between transmit I-PDUs
*   -Monitoring of receive signals (signals timeout)
*   -Filter mechanisms for incoming signals
*   -Different notification mechanisms
*   -Provision of init values and update indications
*   -Byte order conversion
*   -Sign extension
*   -Support of two different transmission modes per I-PDU
*   -Signal based gateway
*   -Support of large and dynamic length data types
*   -Support of I-PDU counters and I-PDU replication
********************************************************************************************************************/
#ifndef COM_H
#define COM_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "Com_Cfg.h"
#include "Com_Cbk.h"
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/* Software Version */
/*! Defines the COM SW major version */
#define COM_SW_MAJOR_VERSION                        1U
/*! Defines the COM SW minor version */
#define COM_SW_MINOR_VERSION                        0U
/*! Defines the COM SW patch version */
#define COM_SW_PATCH_VERSION                        0U
/* Autosar Release */
/*! Defines the AUTOSAR Com Release major version */
#define COM_AR_RELEASE_MAJOR_VERSION                4U
/*! Defines the AUTOSAR Com Release major version */
#define COM_AR_RELEASE_MINOR_VERSION                3U
/*! Defines the AUTOSAR Com TP Release major version */
#define COM_AR_RELEASE_REVISION_VERSION             1U
/********************************************************************************************************************
*  MODULE INFORMATION                                                                                               *
********************************************************************************************************************/
/*! Defines the Vendor ID of Com module. TODO: Vendor ID needs to be updated. Current value is Invalid*/
#define COM_VENDOR_ID                               51U
/*! Defines the Module ID of Com module.*/
#define COM_MODULE_ID                               50U
/*! Defines the Instance ID of Com module.*/
#define COM_INSTANCE_ID                             0U
/********************************************************************************************************************
*  API ID VALUES                                                                                                    *
********************************************************************************************************************/
/*! Defines the service Id for Com_Init function */
#define COM_SID_INIT                                0x01U
/*! Defines the service Id for Com_DeInit function */
#define COM_SID_DEINIT                              0x02U
/*! Defines the service Id for Com_IpduGroupStart function */
#define COM_SID_IPDUGROUPSTART                      0x03U
/*! Defines the service Id for Com_IpduGroupStop function */
#define COM_SID_IPDUGROUPSTOP                       0x04U
/*! Defines the service Id for Com_EnableReceptionDM function */
#define COM_SID_ENABLERECEPTIONDM                   0x06U
/*! Defines the service Id for Com_DisableReceptionDM function */
#define COM_SID_DISABLERECEPTIONDM                  0x05U
/*! Defines the service Id for Com_GetStatus function */
#define COM_SID_GETSTATUS                           0x07U
/*! Defines the service Id for Com_GetVersionInfo function */
#define COM_SID_GETVERSIONINFO                      0x09U
/*! Defines the service Id for Com_SendSignal function */
#define COM_SID_SENDSIGNAL                          0x0AU
/*! Defines the service Id for Com_SendDynSignal function */
#define COM_SID_SENDDYNSIGNAL                       0x21U 
/*! Defines the service Id for Com_ReceiveSignal function */
#define COM_SID_RECEIVESIGNAL                       0x0BU 
/*! Defines the service Id for Com_ReceiveDynSignal function */
#define COM_SID_RECEIVEDYNSIGNAL                    0x22U 
/*! Defines the service Id for Com_SendSignalGroup function */
#define COM_SID_SENDSIGNALGROUP                     0x0DU 
/*! Defines the service Id for Com_ReceiveSignalGroup function */
#define COM_SID_RECEIVESIGNALGROUP                  0x0EU 
/*! Defines the service Id for Com_SendSignalGroupArray function */
#define COM_SID_SENDSIGNALGROUPARRAY                0x23U 
/*! Defines the service Id for Com_ReceiveSignalGroupArray function */
#define COM_SID_RECEIVESIGNALGROUPARRAY             0x24U 
/*! Defines the service Id for Com_InvalidateSignal function */
#define COM_SID_INVALIDATESIGNAL                    0x10U 
/*! Defines the service Id for Com_InvalidateSignalGroup function */
#define COM_SID_INVALIDATESIGNALGROUP               0x1BU 
/*! Defines the service Id for Com_TriggerIPDUSend function */
#define COM_SID_TRIGGERIPDUSEND                     0x17U 
/*! Defines the service Id for Com_TriggerIPDUSendWithMetaData function */
#define COM_SID_TRIGGERIPDUSENDWITHMETADATA         0x28U 
/*! Defines the service Id for Com_SwitchIpduTxMode function */
#define COM_SID_SWITCHIPDUTXMODE                    0x27U 
/*! Defines the service Id for Com_TriggerTransmit function */
#define COM_SID_TRIGGERTRANSMIT                     0x41U 
/*! Defines the service Id for Com_RxIndication function */
#define COM_SID_RXINDICATION                        0x42U 
/*! Defines the service Id for Com_TpRxIndication function */
#define COM_SID_TPRXINDICATION                      0x45U 
/*! Defines the service Id for Com_TxConfirmation function */
#define COM_SID_TXCONFIRMATION                      0x40U 
/*! Defines the service Id for Com_TpTxConfirmation function */
#define COM_SID_TPTXCONFIRMATION                    0x48U 
/*! Defines the service Id for Com_StartOfReception function */
#define COM_SID_STARTOFRECEPTION                    0x46U 
/*! Defines the service Id for Com_CopyRxData function */
#define COM_SID_COPYRXDATA                          0x44U 
/*! Defines the service Id for Com_CopyTxData function */
#define COM_SID_COPYTXDATA                          0x43U 
/*! Defines the service Id for Com_MainFunctionRx function */
#define COM_SID_MAINFUNCTIONRX                      0x18U 
/*! Defines the service Id for Com_MainFunctionTx function */
#define COM_SID_MAINFUNCTIONTX                      0x19U 
/*! Defines the service Id for Com_MainFunctionRouteSignals function */
#define COM_SID_MAINFUNCTIONROUTESIGNALS            0x1AU 
/********************************************************************************************************************
*  DEVELOPMENT ERRORS VALUES                                                                                        *
********************************************************************************************************************/
/*! @brief Defines the error ID for API service called with wrong parameter */
#define COM_E_PARAM                                 0x01U
/*! @brief Defines the error ID for any other API service, except Com_GetStatus, is called before the AUTOSAR COM 
    module was initialized with Com_Init or after a call to Com_Deinit*/
#define COM_E_UNINIT                                0x02U
/*! @brief Defines the error ID for API service with NULL pointer checking*/
#define COM_E_PARAM_POINTER                         0x03U
/*! @brief Defines the error ID for Invalid configuration set selection*/
#define COM_E_INIT_FAILED                           0x04U
/*! @brief Defines the ID for NO error */
#define COM_E_NO_ERROR                              0xFFU
/********************************************************************************************************************
*  RUN TIME ERRORS VALUES                                                                                           *
********************************************************************************************************************/
/*! @brief Defines the Run time Error Code when Transmission request was skipped */
#define COM_E_SKIPPED_TRANSMISSION                  0x05
/********************************************************************************************************************
*  RETURN TYPES VALUES                                                                                              *
********************************************************************************************************************/
/*! @brief Defines the Return type when service is currently not available e.g. the corresponding I-PDU group is 
    stopped (or a development error has been detected) */
#define COM_SERVICE_NOT_AVAILABLE                   0x80U
/*! @brief Defines the Return type when successful execution of this function is currently not possible, because a 
    re-source is currently in use. For example, the buffer of a large I-PDU is locked. */
#define COM_BUSY                                    0x81U


#define COM_START_SEC_CODE
#include "MemMap.h"
/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
/*!******************************************************************************************************************
*   @brief      This service initializes internal and external interfaces and variables of the AUTOSAR COM module 
*   layer for the further processing. After calling this function the inter-ECU communication is still disabled.
*   @param[in]  config  Pointer to the Com post-build configuration data.
*   @ServiceID  0x01
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant.
*   @note       The Com module’s environment shall call Com_Init before using the Com module for further
*               processing
********************************************************************************************************************/
extern FUNC(void,COM_CODE) Com_Init(P2CONST(Com_ConfigType,AUTOMATIC,COM_APPL_CONST) config);
/*!******************************************************************************************************************
*   @brief      This service stops the inter-ECU communication. All started I-PDU groups are stopped and have
*   to be started again, if needed, after Com_Init is called. By a call to Com_DeInit the AUTOSAR COM module
*   is put into an not initialized state.
*   @ServiceID  0x02
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(void,COM_CODE) Com_DeInit(void);
/*!******************************************************************************************************************
*   @brief      This service starts a preconfigured I-PDU group. For example, cyclic I-PDUs will be sent out 
*               cyclically after the call of Com_IpduGroupStart(). If Initialize is true all I-PDUs of the 
*               I-PDU group shall be (re-)initialized before the I-PDU group is started. That is they shall behave
*               like after a start-up of COM, for example the old_value of the filter objects and shadow buffers of 
*               signal groups have to be (re-)initialized
*   @param[in]  IpduGroupId Id of I-PDU group to be started.
*   @param[in]  initialize  flag to request initialization of the data in the I-PDUs of this I-PDU group.
*   @ServiceID  0x03
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant for different I-PDU groups. Non reentrant for the same I-PDU group.
********************************************************************************************************************/
extern FUNC(void,COM_CODE) Com_IpduGroupStart( Com_IpduGroupIdType IpduGroupId, boolean initialize );
/*!******************************************************************************************************************
*   @brief      Stops a preconfigured I-PDU group. For example, cyclic I-PDUs will be stopped after the call of 
*               Com_IpduGroupStop().
*   @param[in]  IpduGroupId Id of I-PDU group to be stopped
*   @ServiceID  0x04
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant for different I-PDU groups. Non reentrant for the same I-PDU group.
********************************************************************************************************************/
extern FUNC(void,COM_CODE) Com_IpduGroupStop(Com_IpduGroupIdType IpduGroupId);
/*!******************************************************************************************************************
*   @brief      Enables the reception deadline monitoring for the I-PDUs within the given I-PDU group.
*   @param[in]  Id of I-PDU group where reception DM shall be enabled.
*   @ServiceID  0x06
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant for different I-PDU groups. Non reentrant for the same I-PDU group.
********************************************************************************************************************/
extern FUNC(void,COM_CODE) Com_EnableReceptionDM( Com_IpduGroupIdType IpduGroupId );
/*!******************************************************************************************************************
*   @brief      Disables the reception deadline monitoring for the I-PDUs within the given I-PDU group.
*   @param[in]  Id of I-PDU group where reception DM shall be enabled.
*   @ServiceID  0x05
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant for different I-PDU groups. Non reentrant for the same I-PDU group.
********************************************************************************************************************/
extern FUNC(void,COM_CODE) Com_DisableReceptionDM( Com_IpduGroupIdType IpduGroupId );
/*!******************************************************************************************************************
*   @brief      This service returns the status of the AUTOSAR COM module
*   @Return     Com_StatusType status of COM module
*               - COM_UNINIT : the AUTOSAR COM module is not initialized and not usable 
*               - COM_INIT   : the AUTOSAR COM module is initialized and usable
*   @ServiceID  0x07
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant.
********************************************************************************************************************/
extern FUNC(Com_StatusType,COM_CODE) Com_GetStatus(void);
/*!******************************************************************************************************************
*   @brief      This service returns the version information of this module.
*   @param[in]  VersionInfo Pointer to where to store the version information of this module. 
*   @ServiceID  0x09
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant.
********************************************************************************************************************/
extern FUNC(void,COM_CODE) Com_GetVersionInfo(P2VAR(Std_VersionInfoType,AUTOMATIC,COM_APPL_DATA) VersionInfo);
/*!******************************************************************************************************************
*   @brief      The service Com_SendSignal updates the signal object identified by SignalId with the signal 
*   referenced by the SignalDataPtr parameter.
*   @param[in]  SignalId Id of signal to be sent.
*   @param[in]  SignalDataPtr Reference to the signal data to be transmitted.
*   @return     uint8 status of the request 
*               - E_OK: service has been accepted.
*               - COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped (or service failed due to 
*               development error).
*               - COM_BUSY: in case the TP-Buffer is locked for large data types handling
*   @ServiceID  0x0A
*   @Sync/Async Asynchronous 
*   @Reentrancy Non Reentrant for the same signal. Reentrant for different signals.
********************************************************************************************************************/
extern FUNC(uint8,COM_CODE) Com_SendSignal
(
    Com_SignalIdType SignalId,
    P2CONST(void,AUTOMATIC,COM_APPL_CONST) SignalDataPtr
);
/*!******************************************************************************************************************
*   @brief      The service Com_SendDynSignal shall update the signal ob-ject identified by SignalId with the signal 
*   referenced by the SignalDataPtr parameter.
*   @param[in]  SignalId Id of signal to be sent.
*   @param[in]  SignalDataPtr Reference to the signal data to be transmitted.
*   @param[in]  Length Length of the dynamic length signal
*   @return     uint8 status of the request 
*               - E_OK: service has been accepted.
*               - E_NOT_OK: in case the Length is greater than the configured ComSignalLength of this sent signal
*               - COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped (or service failed due to 
*               development error).
*               - COM_BUSY: in case the TP-Buffer is locked for large data types handling
*   @ServiceID  0x21
*   @Sync/Async Asynchronous 
*   @Reentrancy Non Reentrant for the same signal. Reentrant for different signals.
********************************************************************************************************************/
extern FUNC(uint8,COM_CODE) Com_SendDynSignal
(
    Com_SignalIdType SignalId,
    P2CONST(void,AUTOMATIC,COM_APPL_CONST) SignalDataPtr,
    uint16 Length
);
/*!******************************************************************************************************************
*   @brief      The service Com_ReceiveSignal shall copy the data of the signal object identified by SignalId to the 
*   position referenced by SignalDataPtr.
*   @param[in]  SignalId Id of signal to be received
*   @param[out]  SignalDataPtr Reference to the location where the received signal data shall be stored
*   @return     uint8 status of the request 
*               - E_OK: service has been accepted.
*               - COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped (or service failed due to 
*               development error).
*               - COM_BUSY: in case the TP-Buffer is locked for large data types handling
*   @ServiceID  0x0B
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant for the same signal. Reentrant for different signals.
*   @Note The AUTOSAR COM module relies on the fact the SignalDataPtr is properly aligned with respect to the data 
*   type of the signal with the given SignalId. The caller of Com_ReceiveSignal has to ensure this.
********************************************************************************************************************/
extern FUNC(uint8,COM_CODE) Com_ReceiveSignal
(
    Com_SignalIdType SignalId, 
    P2VAR(void,AUTOMATIC,COM_APPL_DATA) SignalDataPtr
);
/*!******************************************************************************************************************
*   @brief      The service  Com_ReceiveDynSignal copies the data of the signal identified by SignalId to the location
*   specified by SignalDataPtr and stores the length of the dynamical length signal at the position given by the Length 
*   parameter.
*   @param[in]  SignalId Id of signal to be received
*   @param[in,out]  Length length of the signal
*                   - in: maximum length that could be received 
*                   - out: length of the dynamic length signal
*   @param[out] SignalDataPtr Reference to the location where the received signal data shall be stored
*   @return     uint8 status of the request 
*               - E_OK: service has been accepted.
*               - E_NOT_OK: in case the Length (as in-parameter) is smaller than the received length of the dynamic 
*               length signal
*               - COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped (or service failed due to 
*               development error).
*               - COM_BUSY: in case the TP-Buffer is locked for large data types handling
*   @ServiceID  0x22
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant for the same signal. Reentrant for different signals.
********************************************************************************************************************/
extern FUNC(uint8,COM_CODE) Com_ReceiveDynSignal
(
    Com_SignalIdType SignalId, 
    P2VAR(void,AUTOMATIC,COM_APPL_DATA) SignalDataPtr,
    P2VAR(uint16,AUTOMATIC,COM_APPL_DATA) Length
);
/*!******************************************************************************************************************
*   @brief      The service Com_SendSignalGroup shall copy the content of the shadow buffer referenced by parameter 
*   SignalGroupId to the associated I-PDU
*   @param[in]  SignalGroupId Id of signal group to be sent.
*   @Return     uint8 status of the request .
*               - E_OK: service has been accepted. 
*               - COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped (or service failed due to 
*                 development error). 
*               - COM_BUSY: in case the TP-Buffer is locked for large data types handling.
*   @ServiceID  0x0D
*   @Sync/Async Asynchronous 
*   @Reentrancy Non Reentrant for the same group signal. Reentrant for different group signals.
*   @Note To send out the shadow buffer, Com_SendSignalGroup has to be called.
********************************************************************************************************************/
extern FUNC(uint8,COM_CODE) Com_SendSignalGroup(Com_SignalGroupIdType SignalGroupId);
/*!******************************************************************************************************************
*   @brief      The service Com_ReceiveSignalGroup shall copy the received signal group from the I-PDU to the shadow 
*   buffer.
*   @param[in]  SignalGroupId Id of signal group to be received
*   @Return     uint8 status of the request .
*               - E_OK: service has been accepted. 
*               - COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped (or service failed due to 
*                 development error). 
*               - COM_BUSY: in case the TP-Buffer is locked for large data types handling.
*   @ServiceID  0x0E
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant for the same group signal. Reentrant for different group signals.
*   @Note After this call, the group signals could be copied from the shadow buffer to the RTE by calling 
*   Com_ReceiveSignal.
********************************************************************************************************************/
extern FUNC(uint8,COM_CODE) Com_ReceiveSignalGroup(Com_SignalGroupIdType SignalGroupId);
/*!******************************************************************************************************************
*   @brief      The service Com_SendSignalGroupArray copies the content of the provided SignalGroupArrayPtr to the 
*   associated I-PDU. The provided data shall correspond to the array representation of the signal group
*   @param[in]  SignalGroupId Id of group signal to be received
*   @param[in]  SignalGroupArrayPtr Reference to the signal group array.
*   @return     uint8 status of the request.
*               - E_OK: service has been accepted 
*               - COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped (or service failed due to 
*               development error) 
*               - COM_BUSY: in case the TP-Buffer is locked for large data types handling
*   @ServiceID  0x23
*   @Sync/Async Asynchronous 
*   @Reentrancy Non Reentrant for the same signal group. Reentrant for different signal groups.
********************************************************************************************************************/
extern FUNC(uint8,COM_CODE) Com_SendSignalGroupArray
(
    Com_SignalGroupIdType SignalGroupId, 
    P2CONST(uint8,AUTOMATIC,COM_APPL_CONST) SignalGroupArrayPtr
);
/*!******************************************************************************************************************
*   @brief      The service Com_ReceiveSignalGroupArray copies the received signal group array representation from 
*               the PDU to the location designated by SignalGroupArrayPtr.
*   @param[in]  SignalGroupId Id of signal group to be received.
*   @param[out] SignalGroupArrayPtr reference to the location where the received signal group array shall be stored
*   @return     uint8 status of the request.
*               - E_OK: service has been accepted 
*               - COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped (or service failed due to 
*               development error) 
*               - COM_BUSY: in case the TP-Buffer is locked for large data types handling
*   @ServiceID  0x24
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant for the same signal group. Reentrant for different signal groups.
********************************************************************************************************************/
extern FUNC(uint8,COM_CODE) Com_ReceiveSignalGroupArray
(
    Com_SignalGroupIdType SignalGroupId,
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) SignalGroupArrayPtr
);
/*!******************************************************************************************************************
*   @brief      The service Com_InvalidateSignal invalidates the signal with the given SignalId by setting its value 
*   to its configured ComSignalDataInvalidValue.
*   @param[in]  SignalId Id of signal to be invalidated..
*   @return     uint8 status of the request.
*               - E_OK: service has been accepted 
*               - COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group is stopped, no ComSignalDataInvalidValue is 
*               configured for the given signalId or service fails due to development error
*               - COM_BUSY: in case the TP-Buffer is locked for large data types handling
*   @ServiceID  0x10
*   @Sync/Async Asynchronous 
*   @Reentrancy Non Reentrant for the same signal. Reentrant for different signals.
********************************************************************************************************************/
extern FUNC(uint8,COM_CODE) Com_InvalidateSignal(Com_SignalIdType SignalId);
/*!******************************************************************************************************************
*   @brief      The service Com_InvalidateSignalGroup invalidates all group signals of the signal group with the 
*   given SignalGroupId by setting their values to their configured ComSignalDataInvalidValues.
*   @param[in]  SignalGroupId Id of signal group to be invalidated.
*   @ServiceID  0x1B
*   @Sync/Async Asynchronous 
*   @Reentrancy Non Reentrant for the same signal group. Reentrant for different signal groups.
********************************************************************************************************************/
extern FUNC(uint8,COM_CODE) Com_InvalidateSignalGroup(Com_SignalGroupIdType SignalGroupId);
/*!******************************************************************************************************************
*   @brief      The service shall trigger the I-PDU with the given ID for transmission only if the I-PDU is started
*   @param[in]  PduId The I-PDU-ID of the I-PDU that shall be triggered for sending.
*   @return     Std_ReturnType status of the request.
*               - E_OK: I-PDU was triggered for transmission 
*               - E_NOT_OK: I-PDU is stopped, the transmission could not be triggered
*   @ServiceID  0x17
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType,COM_CODE) Com_TriggerIPDUSend(PduIdType PduId);
/*!******************************************************************************************************************
*   @brief      The service updates its internal metadata for the I-PDU with the given ID by copying the meta-data 
*   from the given position and with respect to the globally configured metadata length of the I-PDU.
*   Then the I-PDU is triggered for transmission.
*   @param[in]  PduId The I-PDU-ID of the I-PDU that shall be triggered for sending
*   @param[in]  MetaData A pointer to the metadata for the triggered send-request
*   @return     Std_ReturnType status of the request.
*               - E_OK: I-PDU was triggered for transmission 
*               - E_NOT_OK: I-PDU is stopped, the transmission could not be triggered
*   @ServiceID  0x28
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType,COM_CODE) Com_TriggerIPDUSendWithMetaData
(
    PduIdType PduId, 
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) MetaData
);
/*!******************************************************************************************************************
*   @brief      The service Com_SwitchIpduTxMode sets the transmission mode of the I-PDU referenced by PduId to Mode. 
*   In case the transmission mode changes, the new mode shall immediately be effective . 
*   In case the requested transmission mode was already active for this I-PDU, the call will have no effect.
*   @param[in]  PduId Id of the I-PDU of which the transmission mode shall be changed
*   @param[in]  Mode the transmission mode that shall be set
*   @ServiceID  0x27
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant for different PduIds. Non Reentrant for the same PduId.
********************************************************************************************************************/
extern FUNC(void,COM_CODE) Com_SwitchIpduTxMode(PduIdType PduId, boolean Mode);
#define COM_STOP_SEC_CODE
#include "MemMap.h" 

#endif /* COM_H */

/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/
