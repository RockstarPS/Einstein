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
*   @file CanSM.h
*   @ingroup CanSM
*   @brief This file provides the declaration of the CanSM API. This header file should be included by other
*   modules that use the CanSM API.
*   @defgroup CanSM
*   @brief The CanSM module is responsible for the control flow abstraction of CAN networks.It changes the 
*          communication modes of the configured CAN networks depending on the mode requests from the ComM module.
********************************************************************************************************************/
#ifndef CANSM_H
#define CANSM_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComStack_Types.h"
#include "CanSM_Cfg.h"
#include "ComM.h"
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/* Software Version */
/*! @brief Defines the CanSM SW major version */
#define CANSM_SW_MAJOR_VERSION                              1u
/*! @brief Defines the CanSM SW minor version */
#define CANSM_SW_MINOR_VERSION                              0u
/*! @brief Defines the CanSM SW patch version */
#define CANSM_SW_PATCH_VERSION                              0u
/* Autosar Release */
/*! @brief Defines the CanSM AUTOSAR major version */
#define CANSM_AR_RELEASE_MAJOR_VERSION                      4u
/*! @brief Defines the CanSM AUTOSAR minor version */
#define CANSM_AR_RELEASE_MINOR_VERSION                      3u
/*! @brief Defines the CanSM AUTOSAR patch version */
#define CANSM_AR_RELEASE_REVISION_VERSION                   1u
/********************************************************************************************************************
*  MODULE INFORMATION                                                                                               *
********************************************************************************************************************/
/*! @brief Defines the Vendor Id of CanSM module. */
#define CANSM_VENDOR_ID                                     0x0033u
/*! @brief Defines the Module Id of CanSM module.*/
#define CANSM_MODULE_ID                                     140u
/*! @brief Defines the version Id of CanSM module.*/
#define CANSM_INSTANCE_ID                                   0u
/********************************************************************************************************************
*  API ID VALUES                                                                                                    *
********************************************************************************************************************/
/*! @brief Defines the service Id for CanSM_Init function */
#define CANSM_INIT_API                                      0x00
/*! @brief Defines the service Id for CanSM_DeInit function */
#define CANSM_DEINIT_API                                    0x14
/*! @brief Defines the service Id for CanSM_RequestComMode function */
#define CANSM_REQUESTCOMMODE_API                            0x02
/*! @brief Defines the service Id for CanSM_GetCurrentComMode function */
#define CANSM_GETCURRENTCOMMODE_API                         0x03
/*! @brief Defines the service Id for CanSM_StartWakeupSource function */
#define CANSM_STARTWAKEUPSOURCE_API                         0x11
/*! @brief Defines the service Id for CanSM_StopWakeupSource function */
#define CANSM_STOPWAKEUPSOURCE_API                          0x12
/*! @brief Defines the service Id for CanSM_GetVersionInfo function */
#define CANSM_GETVERSIONINFO_API                            0x01
/*! @brief Defines the service Id for CanSM_SetBaudrate function */
#define CANSM_SETBAUDRATE_API                               0x0d
/*! @brief Defines the service Id for CanSM_SetIcomConfiguration function */
#define CANSM_SETICOMCONFIGURATION_API                      0x0f
/*! @brief Defines the service Id for CanSM_SetEcuPassive function */
#define CANSM_SETECUPASSIVE_API                             0x13
/*! @brief Defines the service Id for CanSM_ControllerBusOff function */
#define CANSM_CONTROLLERBUSOFF_API                          0x04
/*! @brief Defines the service Id for CanSM_ControllerModeIndication function */
#define CANSM_CONTROLLERMODEINDICATION_API                  0x07
/*! @brief Defines the service Id for CanSM_TransceiverModeIndication function */
#define CANSM_TRANSCEIVERMODEINDICATION_API                 0x09
/*! @brief Defines the service Id for CanSM_TxTimeoutException function */
#define CANSM_TXTIMEOUTEXCEPTION_API                        0x0b
/*! @brief Defines the service Id for CanSM_ClearTrcvWufFlagIndication function */
#define CANSM_CLEARTRCVWUFFLAGINDICATION_API                0x08
/*! @brief Defines the service Id for CanSM_CheckTransceiverWakeFlagIndication function */
#define CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_API        0x0a
/*! @brief Defines the service Id for CanSM_ConfirmPnAvailability function */
#define CANSM_CONFIRMPNAVAILABILITY_API                     0x06
/*! @brief Defines the service Id for CanSM_CurrentIcomConfiguration function */
#define CANSM_CURRENTICOMCONFIGURATION_API                  0x10
/*! @brief Defines the service Id for CanSM_MainFunction function */
#define CANSM_MAINFUNCTION_API                              0x05
/********************************************************************************************************************
*  DEVELOPMENT ERRORS VALUES                                                                                        *
********************************************************************************************************************/
/*! @brief API service used without module initialization */
#define CANSM_E_UNINIT                                      0x01U
/*! @brief API service called with wrong pointer */
#define CANSM_E_PARAM_POINTER                               0x02U
/*! @brief API service called with wrong parameter */
#define CANSM_E_INVALID_NETWORK_HANDLE                      0x03U
/*! @brief API service called with wrong parameter */
#define CANSM_E_PARAM_CONTROLLER                            0x04U
/*! @brief API service called with wrong parameter */
#define CANSM_E_PARAM_TRANSCEIVER                           0x05U
/*! @brief DeInit API service called when not all CAN networks are in state CANSM_NO_COMMUNICATION */
#define CANSM_E_NOT_IN_NO_COM								0x0BU
/*! @brief Non Autosar dev error , internal error id */
#define CANSM_E_NON_ASR_START_ID							(CANSM_E_NOT_IN_NO_COM+1U)
/*! @brief Invalid network mode request by the upper layer in Api CanSM_RequestComMode */
#define CANSM_E_INVALID_COMM_REQUEST						CANSM_E_NON_ASR_START_ID
/*! @brief No Developement Error */
#define CANSM_E_NO_ERROR                                    0xFFU

#define CANSM_START_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
/*!******************************************************************************************************************
*   @brief      This service initializes the CanSM module
*   @param[in]  ConfigPtr  Pointer to init structure for the post build parameters of the CanSM
*   @ServiceID  0x00
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
*   @note       The CanSM_Init should be called before using the CanSM module for further processing.
********************************************************************************************************************/
extern FUNC(void,CANSM_CODE) CanSM_Init(P2CONST(CanSM_ConfigType,AUTOMATIC,CANSM_APPL_CONST) ConfigPtr);
/*!******************************************************************************************************************
*   @brief      This service de-initializes the CanSM module.
*   @ServiceID  0x14
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(void,CANSM_CODE) CanSM_DeInit(void);
/*!******************************************************************************************************************
*   @brief      This function shall be called by EcuM when a wakeup source shall be started
*   @param[in]  network  Affected CAN network
*   @return     Std_ReturnType E_OK: Service accepted E_NOT_OK: Service denied
*   @ServiceID  0x11
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,CANSM_CODE) CanSM_StartWakeupSource(NetworkHandleType Network);
/*!******************************************************************************************************************
*   @brief      This function shall be called by EcuM when a wakeup source shall be stopped
*   @param[in]  network  Affected CAN network
*   @return     Std_ReturnType E_OK: Service accepted E_NOT_OK: Service denied
*   @ServiceID  0x12
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,CANSM_CODE) CanSM_StopWakeupSource(NetworkHandleType Network);
#if (CANSM_VERSION_INFO_API == STD_ON)
/*!******************************************************************************************************************
*   @brief      This service puts out the version information of this module
*   @param[in]  VersionInfo  Pointer to where to store the version information of this module.
*   @ServiceID  0x01
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
extern FUNC(void,CANSM_CODE) CanSM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType,AUTOMATIC,CANSM_APPL_DATA) VersionInfo
);
#endif
#if (CANSM_SET_BAUD_RATE_API == STD_ON)
/*!******************************************************************************************************************
*   @brief      This service shall start an asynchronous process to change the baud rate for the configured CAN 
*               controllers of a certain CAN network. Depending on necessary baud rate modifications the controllers 
*               might have to reset.
*   @param[in]  Network  Handle of the addressed CAN network for the baud rate change
*   @param[in]  BaudRateConfigID  references a baud rate configuration by ID
*   @return     Std_ReturnType E_OK: Service request accepted, setting of (new) baud rate started 
*               E_NOT_OK: Service request not accepted
*   @ServiceID  0x0d
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different Networks. Non reentrant for the same Network.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,CANSM_CODE) CanSM_SetBaudrate(NetworkHandleType Network, uint16 BaudRateConfigID);
#endif
#if (CANSM_ICOM_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief      This service shall change the Icom Configuration of a CAN network to the requested one.
*   @param[in]  Network  Handle of destined communication network for request
*   @param[in]  ConfigurationId  Requested Configuration
*   @return     Std_ReturnType E_OK: Request accepted E_NOT_OK: Request denied
*   @ServiceID  0x0f
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant only for different network handles
********************************************************************************************************************/
extern FUNC(Std_ReturnType,CANSM_CODE) CanSM_SetIcomConfiguration
(
    NetworkHandleType Network,
    IcomConfigIdType ConfigurationId
);
#endif
#if(CANSM_TX_OFFLINE_ACTIVE_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief      This function can be used to set all CanSM channels of the ECU to a receive only mode. This mode will 
*               be kept either until it is set back, or the ECU is reset.
*   @param[in]  CanSM_Passive  TRUE: set all CanSM channels to passive, i.e. receive only 
*               FALSE: set all CanSM channels back to non-passive
*   @return     Std_ReturnType E_OK: Request accepted E_NOT_OK: Request denied
*   @ServiceID  0x13
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType,CANSM_CODE) CanSM_SetEcuPassive(boolean CanSM_Passive);
#endif

#define CANSM_START_SEC_CODE
#include "MemMap.h"

#endif /* CANSM_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

