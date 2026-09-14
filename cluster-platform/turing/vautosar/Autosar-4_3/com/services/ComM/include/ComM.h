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
*   @file ComM.h
*   @ingroup ComM
*   @brief This file provides the declaration of the ComM API. This header file should be included by other
*   modules that use the ComM API.
*   @defgroup ComM
*   @brief The Communication Manager Module (COM Manager, ComM) is a Resource Manager, which encapsulates the control
*   of the underlying communication services. The ComM module controls basic software modules relating to
*   communication. The ComM module collects the bus communication access requests from communication requestors and
*   coordinates the bus communication access requests.
*   The purpose of the ComM module is:
*   - Simplifying the usage of the bus communication stack for the user. This includes a simplified network
*   management handling.
*   - Coordinating the availability of the bus communication stack (allow sending and receiving of signals) of
*   multiple independent software components on one ECU.
*   - Offer an API to disable sending of signals to prevent the ECU from (actively) waking up the communication
*   bus.
*   - Controlling of more than one communication bus channel of an ECU by implementing a channel state machine
*   for every channel.
*   - Offering the possibility to force an ECU that keeps the bus awake to the 'No Communication' mode.
*   - Simplifying the resource management by allocating all resources necessary for the requested Communication
*   Mode.
********************************************************************************************************************/

#ifndef COMM_H
#define COMM_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComM_Cfg.h"
#include "ComStack_Types.h"

/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/* Software Version */
/*! @brief Defines the ComM SW major version */
#define COMM_SW_MAJOR_VERSION                                   1U
/*! @brief Defines the ComM SW minor version */
#define COMM_SW_MINOR_VERSION                                   0U
/*! @brief Defines the ComM SW patch version */
#define COMM_SW_PATCH_VERSION                                   0U
/* Autosar Release */
/*! @brief Defines the ComM AUTOSAR major version */
#define COMM_AR_RELEASE_MAJOR_VERSION                           4U
/*! @brief Defines the ComM AUTOSAR major version */
#define COMM_AR_RELEASE_MINOR_VERSION                           3U
/*! @brief Defines the ComM AUTOSAR major version */
#define COMM_AR_RELEASE_REVISION_VERSION                        1U
/********************************************************************************************************************
*  MODULE INFORMATION                                                                                               *
********************************************************************************************************************/
/*! @brief Defines the Vendor Id of ComM module. */
#define COMM_VENDOR_ID                                          0x0033u
/*! @brief Defines the Module Id of ComM module.*/
#define COMM_MODULE_ID                                          12U
/*! @brief Defines the version Id of ComM module.*/
#define COMM_INSTANCE_ID                                        0U
/********************************************************************************************************************
*  API ID VALUES                                                                                                    *
********************************************************************************************************************/
/*! @brief Defines the service Id for ComM_Init function */
#define COMM_SID_INIT                                           0x01U
/*! @brief Defines the service Id for ComM_DeInit function */
#define COMM_SID_DEINIT                                         0x02U
/*! @brief Defines the service Id for ComM_GetState function */
#define COMM_SID_GETSTATE                                       0x34U
/*! @brief Defines the service Id for ComM_GetStatus function */
#define COMM_SID_GETSTATUS                                      0x03U
/*! @brief Defines the service Id for ComM_RequestComMode function */
#define COMM_SID_REQUESTCOMMODE                                 0x05U
/*! @brief Defines the service Id for ComM_GetMaxComMode function */
#define COMM_SID_GETMAXCOMMODE                                  0x06U
/*! @brief Defines the service Id for ComM_GetRequestedComMode function */
#define COMM_SID_GETREQUESTEDCOMMODE                            0x07U
/*! @brief Defines the service Id for ComM_GetCurrentComMode function */
#define COMM_SID_GETCURRENTCOMMODE                              0x08U
/*! @brief Defines the service Id for ComM_CommunicationAllowed function */
#define COMM_SID_COMMUNICATIONALLOWED                           0x35U
/*! @brief Defines the service Id for ComM_BusSM_ModeIndication function */
#define COMM_SID_BUSSM_MODEINDICATION                           0x33U
/*! @brief Defines the service Id for ComM_BusSM_ModeIndication function */
#define COMM_SID_COMCBK                                         0x36U
/*! @brief Defines the service Id for ComM_COMCbk function */
#define COMM_SID_MAINFUNCTION                                   0x60U
/*! @brief Defines the service Id for ComM_GetVersionInfo function */
#define COMM_SID_GETVERSIONINFO                                 0x10U
/*! @brief Defines the service Id for ComM_Nm_NetworkStartIndication function */
#define COMM_SID_NM_NETWORKSTARTINDICATION                      0x15U
/*! @brief Defines the service Id for ComM_Nm_NetworkMode function */
#define COMM_SID_NM_NETWORKMODE                                 0x18U
/*! @brief Defines the service Id for ComM_Nm_PrepareBusSleepMode function */
#define COMM_SID_NM_PREPAREBUSSLEEPMODE                         0x19U
/*! @brief Defines the service Id for ComM_Nm_BusSleepMode function */
#define COMM_SID_NM_BUSSLEEPMODE                                0x1AU
/*! @brief Defines the service Id for ComM_Nm_RestartIndication function */
#define COMM_SID_NM_RESTARTINDICATION                           0x1BU
/*! @brief Defines the service Id for ComM_DCM_ActiveDiagnostic function */
#define COMM_SID_DCM_ACTIVEDIAGNOSTIC                           0x1FU
/*! @brief Defines the service Id for ComM_DCM_InactiveDiagnostic function */
#define COMM_SID_DCM_INACTIVEDIAGNOSTIC                         0x20U
/*! @brief Defines the service Id for ComM_EcuM_WakeUpIndication function */
#define COMM_SID_ECUM_WAKEUPINDICATION                          0x2AU
/*! @brief Defines the service Id for ComM_EcuM_PNCWakeUpIndication function */
#define COMM_SID_ECUM_PNCWAKEUPINDICATION                       0x37U
/*! @brief Defines the service Id for ComM_GetInhibitionStatus function */
#define COMM_SID_GETINHIBITIONSTATUS                            0x04U
/*! @brief Defines the service Id for ComM_PreventWakeUp function */
#define COMM_SID_PREVENTWAKEUP                                  0x09U
/*! @brief Defines the service Id for ComM_LimitChannelToNoComMode function */
#define COMM_SID_LIMITCHANNELTONOCOMMODE                        0x0BU
/*! @brief Defines the service Id for ComM_LimitECUToNoComMode function */
#define COMM_SID_LIMITECUTONOCOMMODE                            0x0CU
/*! @brief Defines the service Id for ComM_ReadInhibitCounter function */
#define COMM_SID_READINHIBITCOUNTER                             0x0DU
/*! @brief Defines the service Id for ComM_ResetInhibitCounter function */
#define COMM_SID_RESETINHIBITCOUNTER                            0x0EU
/*! @brief Defines the service Id for ComM_SetECUGroupClassification function */
#define COMM_SID_SETECUGROUPCLASSIFICATION                      0x0FU
/********************************************************************************************************************
*  DEVELOPMENT ERRORS VALUES                                                                                        *
********************************************************************************************************************/
/*! @brief API service used without module initialization */
#define COMM_E_NOT_INITED                                       0x01U
/*! @brief API service used with wrong parameters */
#define COMM_E_WRONG_PARAMETERS                                 0x02U
/*! @brief API Service used with a null pointer */
#define COMM_E_PARAM_POINTER                                    0x03U
/*! @brief Initialization failed */
#define COMM_E_INIT_FAILED                                      0x04U
/*! @brief Not defined by AUTOSAR */
#define COMM_E_NO_ERROR                                         0xFFU
/*! @brief Function call has been successfully but mode can not be granted because of mode inhibition. Return type */
#define COMM_E_MODE_LIMITATION                                  0x02U

#define COMM_START_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
/*!******************************************************************************************************************
*   @brief      This method is used to initialize module init status (SRS_BSW_00406).
********************************************************************************************************************/
extern FUNC(void,COMM_CODE) ComM_InitMemory(void);
/*!******************************************************************************************************************
*   @brief      This method initializes the AUTOSAR Communication Manager and restarts the internal state machines.
*   @param[in]  ConfigPtr  Pointer to the ComM post-build configuration data.
*   @ServiceID  0x01
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
*   @note       The ComM_Init should be called before using the ComM module for further processing.
********************************************************************************************************************/
extern FUNC(void,COMM_CODE) ComM_Init(P2CONST(ComM_ConfigType,AUTOMATIC,COMM_APPL_CONST) ConfigPtr);
/*!******************************************************************************************************************
*   @brief      This method de-initializes the AUTOSAR Communication Manager.
*   @ServiceID  0x02
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(void,COMM_CODE) ComM_DeInit(void);
/*!******************************************************************************************************************
*   @brief      This method returns current state, including sub-state, of the ComM channel state machine.
*   @param[in]  Channel  The Network Channel for the requested state of ComM state machine.
*   @param[out] State  State of the ComM channel state machine:
*               - COMM_NO_COM_NO_PENDING_REQUEST
*               - COMM_NO_COM_REQUEST_PENDING
*               - COMM_FULL_COM_NETWORK_REQUESTED
*               - COMM_FULL_COM_READY_SLEEP
*               - COMM_SILENT_COM
*   @return     status of the request
*               - E_OK: Successfully return current state of ComM state machine
*               - E_NOT_OK: Return of current state of ComM state machine failed
*   @ServiceID  0x34
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
*   @note Usage of function only valid if EcuM/Fixed is used: To leave RUN: state/sub-state need to be
*   COMM_NO_COM_NO_PENDING_REQUEST (No communication and no pending request to start communication)
*   In POST RUN to return to RUN: state/sub-state need to be in COMM_NO_COM_REQUEST_PENDING
*   (No communication, but a pending request to start communication) If EcuM/Flex and BswM is used,
*   BswM instead use received mode indications from ComM (BswM_ComM_RequestedMode(..))
********************************************************************************************************************/
extern FUNC(Std_ReturnType,COMM_CODE) ComM_GetState
(
    NetworkHandleType Channel,
    P2VAR(ComM_StateType,AUTOMATIC,COMM_APPL_DATA) State
);
/*!******************************************************************************************************************
*   @brief      This method returns the initialization status of the AUTOSAR Communication Manager. After a call to
*   ComM_DeInit() ComM should have status COMM_UNINIT, and a new call to ComM_Init needed to make sure ComM restart
*   internal state machines to defailt values.
*   @param[out] Status  status of ComM module.
*               - COMM_UNINIT: The ComM is not initialized or not usable. Default value after startup or after
*               ComM_DeInit() is called.
*               - COMM_INIT: The ComM is initialized and usable.
*   @return     status of the request
*               - E_OK: Successfully return of initialization status
*               - E_NOT_OK: Return of initialization status failed
*   @ServiceID  0x03
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,COMM_CODE) ComM_GetStatus(P2VAR(ComM_InitStatusType,AUTOMATIC,COMM_APPL_DATA) Status);
/*!******************************************************************************************************************
*   @brief      This method returns the inhibition status of a ComM channel.
*   @param[in]  Channel The Network Channel for the requested state of ComM state machine.
*   @param[out] Status  Inhibition status of ComM.
*               -Bit 0(LSB): Wake Up inhibition active
*               -Bit 1: Limit to COMM_NO_COMMUNICATION mode
*   @return     status of the request
*               - E_OK: Successfully returned Inhibition Status
*               - E_NOT_OK: Return of Inhibition Status failed
*   @ServiceID  0x04
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,COMM_CODE) ComM_GetInhibitionStatus
(
    NetworkHandleType Channel,
    P2VAR(ComM_InhibitionStatusType,AUTOMATIC,COMM_APPL_DATA) Status
);
/*!******************************************************************************************************************
*   @brief      This method is used for requesting of a Communication Mode by a user.
*   @param[in]  User Handle of the user who requests a mode.
*   @param[in]  ComMode ComM mode requested by the user.
*               COMM_FULL_COMMUNICATION  - channel shall have both transmission and reception capability
*               COMM_NO_COMMUNICATION - channel shall stop both transmission and reception capability
*   @return     status of the request
*               - E_OK: Successfully changed to the new mode.
*               - E_NOT_OK: Changing to the new mode failed.
*               - COMM_E_MODE_LIMITATION: Mode can not be granted because of mode inhibition.
*   @ServiceID  0x05
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
*   @note Internally mode COMM_SILENT_COMMUNICATION is not a valid request for a user, mode used for synchronization
*   at shutdown. Valid modes are COMM_NO_COMMUNICATION and COMM_FULL_COMMUNICATION.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,COMM_CODE) ComM_RequestComMode(ComM_UserHandleType User, ComM_ModeType ComMode);
/*!******************************************************************************************************************
*   @brief      This method is used to query the maximum allowed Communication Mode of the corresponding user.
*   @param[in]  User Handle of the user who requests a mode.
*   @param[out] ComMode maximum allowed ComM mode.
*               COMM_FULL_COMMUNICATION - channel shall have both transmission and reception capability
*               COMM_NO_COMMUNICATION - channel shall stop both transmission and reception capability
*   @return     status of the request
*               - E_OK: Successfully returned maximum allowed Communication Mode.
*               - E_NOT_OK: Return of maximum allowed Communication Mode failed.
*   @ServiceID  0x06
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,COMM_CODE) ComM_GetMaxComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType,AUTOMATIC,COMM_APPL_DATA) ComMode
);
/*!******************************************************************************************************************
*   @brief      This method is used to query the currently requested Communication Mode of the corresponding user.
*   @param[in]  User Handle of the user who requests a mode.
*   @param[out] ComMode ComM mode which is already requested by the user.
*               COMM_FULL_COMMUNICATION - channel shall have both transmission and reception capability
*               COMM_NO_COMMUNICATION - channel shall stop both transmission and reception capability
*   @return     status of the request
*               - E_OK: Successfully returned requested Communication Mode.
*               - E_NOT_OK: Return of requested Communication Mode failed.
*   @ServiceID  0x07
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,COMM_CODE) ComM_GetRequestedComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType,AUTOMATIC,COMM_APPL_DATA) ComMode
);
/*!******************************************************************************************************************
*   @brief      This method is used to query  to query the current Communication Mode. ComM shall use the
*   corresponding interfaces of the Bus State Managers to get the current Communication Mode of the network.
*   @param[in]  User Handle of the user who requests a mode.
*   @param[out] ComMode current ComM mode.
*               COMM_FULL_COMMUNICATION - channel shall have both transmission and reception capability
*               COMM_NO_COMMUNICATION - channel shall stop both transmission and reception capability
*   @return     status of the request
*               - E_OK: Successfully returned Communication Mode from Bus State Manager.
*               - E_NOT_OK: Return of Communication Mode from Bus State Manager failed.
*   @ServiceID  0x08
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,COMM_CODE) ComM_GetCurrentComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType,AUTOMATIC,COMM_APPL_DATA) ComMode
);
/*!******************************************************************************************************************
*   @brief      This method is used to change the inhibition status COMM_NO_WAKEUP for the corresponding channel.
*   @param[in]  Channel The Network Channel for the requested state of ComM state machine.
*   @param[in]  Status Wake up inhibition status.
*               - FALSE: Wake up inhibition is switched off
*               - TRUE: Wake up inhibition is switched on Parameters
*   @return     status of the request
*               - E_OK: Successfully changed wake up status for the channel
*               - E_NOT_OK: Changed of wake up status for the channel failed
*   @ServiceID  0x09
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,COMM_CODE) ComM_PreventWakeUp(NetworkHandleType Channel, boolean Status);
/*!******************************************************************************************************************
*   @brief      This method is used to changes the inhibition status for the channel for changing from
*   COMM_NO_COMMUNICATION to a higher Communication Mode.
*   @param[in]  Channel The Network Channel for the requested state of ComM state machine.
*   @param[in]  Status channel limit status.
*               - FALSE: Limit channel to COMM_NO_COMMUNICATION disabled
*               - TRUE: Limit channel to COMM_NO_COMMUNICATION enabled
*   @return     status of the request
*               - E_OK: Successfully changed inhibition status for the channel
*               - E_NOT_OK: Changed of inhibition status for the channel failed
*   @ServiceID  0x0b
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,COMM_CODE) ComM_LimitChannelToNoComMode(NetworkHandleType Channel, boolean Status);
/*!******************************************************************************************************************
*   @brief      This method is used to Changes the inhibition status for the ECU (=all channels) for changing from
*   COMM_NO_COMMUNICATION to a higher Communication Mode.
*   @param[in]  Status channel limit status.
*               - FALSE: Limit ECU to COMM_NO_COMMUNICATION disabled.
*               - TRUE: Limit ECU to COMM_NO_COMMUNICATION enabled.
*   @return     status of the request
*               - E_OK: Successfully changed inhibition status for the ECU
*               - E_NOT_OK: Changed of inhibition status for the ECU failed
*   @ServiceID  0x0C
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,COMM_CODE) ComM_LimitECUToNoComMode(boolean Status);
/*!******************************************************************************************************************
*   @brief      This method returns the amount of rejected COMM_FULL_COMMUNICATION user requests.
*   @param[out] CounterValue Amount of rejected COMM_FULL_COMMUNICATION user requests.
*   @return     status of the request
*               - E_OK: Successfully returned Inhibition Counter
*               - E_NOT_OK: Return of Inhibition Counter failed
*   @ServiceID  0x0D
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,COMM_CODE) ComM_ReadInhibitCounter(P2VAR(uint16,AUTOMATIC,COMM_APPL_DATA) CounterValue);
/*!******************************************************************************************************************
*   @brief      This method resets the Inhibited COMM_FULL_COMMUNICATION request Counter.
*   @return     status of the request
*               - E_OK: Successfully reset of Inhibit COMM_FULL_COMMUNICATION Counter
*               - E_NOT_OK: Reset of Inhibit COMM_FULL_COMMUNICATION Counter failed
*   @ServiceID  0x0E
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,COMM_CODE) ComM_ResetInhibitCounter(void);
/*!******************************************************************************************************************
*   @brief      This method changes the ECU Group Classification status.
*   @param[in]  Status Inhibition status of ComM.
*               - Bit 0(LSB): Wake Up inhibition active
*               - Bit 1: Limit to COMM_NO_COMMUNICATION mode
*   @return     status of the request
*               - E_OK: Successfully change the ECU Group Classification Status
*               - E_NOT_OK: Change of the ECU Group Classification Status failed
*   @ServiceID  0x0F
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,COMM_CODE) ComM_SetECUGroupClassification(ComM_InhibitionStatusType Status);
/*!******************************************************************************************************************
*   @brief      This method returns the published information.
*   @param[out] Versioninfo Version information of ComM module.
*   @ServiceID  0x10
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
extern FUNC(void,COMM_CODE) ComM_GetVersionInfo(P2VAR(Std_VersionInfoType,AUTOMATIC,COMM_APPL_DATA) Versioninfo);
/*!******************************************************************************************************************
*   @brief      This method perform the processing of the AUTOSAR ComM activities that are not directly initiated by
*   the calls e.g. from the RTE. Each channel has seperate mainfunction which will call this method.
*   @param[in] Channel Network channel for which the main function processing should be done.
*   @ServiceID  0x60
********************************************************************************************************************/
extern FUNC(void,COMM_CODE) ComM_MainFunction(NetworkHandleType Channel);
#if (STD_ON == COMM_PNC_SUPPORT)
/*!******************************************************************************************************************
*   @brief      This method is used to udpate the ERA and EIRA changes. This method is called by the ComM_COMCbk_<sn>
*   from the ComM configuration source file.
*   @param[in] Channel Network channel for which the ERA and EIRA update.
*   @param[in] SiganalDataPtr pointer to the ERA and EIRA data
*   @param[in] SignalDataLength ERA and EIRA data length.
*
********************************************************************************************************************/
extern FUNC(void,COMM_CODE) ComM_UpdateEiraEraData
(
    NetworkHandleType Channel,
    P2CONST(uint8,AUTOMATIC,COMM_APPL_CONST)SiganalDataPtr,
    uint32 SignalDataLength
);
#endif

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#endif/* COMM_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


