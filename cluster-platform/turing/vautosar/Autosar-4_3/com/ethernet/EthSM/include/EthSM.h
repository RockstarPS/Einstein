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
*   @file EthSM.h
*   @ingroup EthSM
*   @brief This file provides the declaration of the EthSM API. This header file should be included by other
*   modules that use the EthSM API.
*   @defgroup EthSM
*   @brief The main task of the Ethernet State Manager can be summarized as follows:
*   - The Ethernet State Manager shall provide an abstract interface to the AUTOSAR Communication Manager to startup 
*   or shutdown the communication on an Ethernet cluster.
*   - The Ethernet State Manager does not directly access the Ethernet hardware (Ethernet Communication Controller and 
*   Ethernet Transceiver), but by means of the Ethernet Interface. The Ethernet Interface redirects the request to the
*   appropriate driver module.
********************************************************************************************************************/
#ifndef ETHSM_H
#define ETHSM_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "EthSM_Types.h"
#include "EthSM_Cfg.h"
#include "Eth_GeneralTypes.h"
#include "TcpIp_Types.h"
#include "ComM.h"               
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/* Software Version */
/*! @brief Defines the EthSM SW major version */
#define ETHSM_SW_MAJOR_VERSION              1u
/*! @brief Defines the EthSM SW minor version */
#define ETHSM_SW_MINOR_VERSION              0u
/*! @brief Defines the EthSM SW patch version */
#define ETHSM_SW_PATCH_VERSION              0u
/* Autosar Release */
/*! @brief Defines the EthSM AUTOSAR major version */
#define ETHSM_AR_RELEASE_MAJOR_VERSION      4u
/*! @brief Defines the EthSM AUTOSAR minor version */
#define ETHSM_AR_RELEASE_MINOR_VERSION      3u
/*! @brief Defines the EthSM AUTOSAR patch version */
#define ETHSM_AR_RELEASE_REVISION_VERSION   1u
/********************************************************************************************************************
*  MODULE INFORMATION                                                                                               *
********************************************************************************************************************/                      
/*! @brief Defines the Vendor Id of EthSM module. */
#define ETHSM_VENDOR_ID                     0x0033u
/*! @brief Defines the Module Id of EthSM module.*/
#define ETHSM_MODULE_ID                     143u
/*! @brief Defines the version Id of EthSM module.*/
#define ETHSM_INSTANCE_ID                   0u
/********************************************************************************************************************
*  API Id                                                                                                           *
********************************************************************************************************************/
/*! @brief Defines the service Id for EthSM_Init function */
#define ETHSM_INIT_API                      0x07u
/*! @brief Defines the service Id for EthSM_GetVersionInfo function */
#define ETHSM_GETVERSIONINFO_API            0x02u
/*! @brief Defines the service Id for EthSM_RequestComMode function */
#define ETHSM_REQUESTCOMMODE_API            0x05u
/*! @brief Defines the service Id for EthSM_GetCurrentComMode function */
#define ETHSM_GETCURRENTCOMMODE_API         0x04u
/*! @brief Defines the service Id for EthSM_TcpIpModeIndication function */
#define ETHSM_TCPIPMODEINDICATION_API       0x08u
/*! @brief Defines the service Id for EthSM_GetCurrentInternalMode function */
#define ETHSM_GETCURRENTINTERNALMODE_API    0x03u
/*! @brief Defines the service Id for EthSM_CtrlModeIndication function */
#define ETHSM_CTRLMODEINDICATION_API        0x09u
/*! @brief Defines the service Id for EthSM_TrcvModeIndication function */
#define ETHSM_TRCVMODEINDICATION_API        0x0Au
/*! @brief Defines the service Id for EthSM_TrcvLinkStateChg function */
#define ETHSM_TRCVLINKSTATECHG_API          0x06u
/*! @brief Defines the service Id for EthSM_MainFunction function */
#define ETHSM_MAINFUNCTION_API              0x01u
/********************************************************************************************************************
*  DEVELOPMENT ERRORS VALUES                                                                                        *
********************************************************************************************************************/
/*! @brief API service called with Invalid communication mode requested */
#define ETHSM_E_INVALID_NETWORK_MODE        0x01u
/*! @brief API service called with EthSM module was not initialized */
#define ETHSM_E_UNINIT                      0x02u
/*! @brief API service called with Invalid pointer in parameter list */
#define ETHSM_E_PARAM_POINTER               0x03u
/*! @brief API service called with Invalid parameter in parameter list network handle */
#define ETHSM_E_INVALID_NETWORK_HANDLE      0x04u
/*! @brief API service called with Invalid parameter in parameter list controller */
#define ETHSM_E_PARAM_CONTROLLER            0x07u
/*! @brief API service called with Invalid parameter in parameter list controller TcpIP mode */
#define ETHSM_E_INVALID_TCP_IP_MODE         0x05u
/*! @brief Defines No error id  */
#define ETHSM_E_NO_ERROR                    0xFFu
/* #! Production Error */
/*! @brief It shall be reported when the transceiver switches to “down” while communication has already been 
*   established and is requested because of communication request.
*   Detection Criteria: 
*   FAIL : During transition from ETHSM_STATE_ONLINE to ETHSM_STATE_ONHOLD, which is triggered by 
*   EthSM_TrcvLinkStateChg(ETHTRCV_LINK_STATE_DOWN)
*   PASS : During transition from ETHSM_STATE_ONHOLD to ETHSM_STATE_ONLINE, which is triggered by 
*   EthSM_TrcvLinkStateChg(ETHTRCV_LINK_STATE_ACTIVE)
*   Time Required: PRE_FAIL: Immediately PASS: Configuration dependent
*   Monitor Frequency : Continuous
*/
#define ETHSM_E_LINK_DOWN                   0x01u
/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
#define ETHSM_START_SEC_CODE
#include "MemMap.h"
/*!******************************************************************************************************************
*   @brief      This function initialize the EthSM.
*   @ServiceID  0x07
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(void, ETHSM_CODE) EthSM_Init( void );

/*!******************************************************************************************************************
*   @brief      This service puts out the version information of this module.
*   @param[out] versioninfo Pointer where to put out the version information
*   @ServiceID  0x02
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
extern FUNC(void, ETHSM_CODE) EthSM_GetVersionInfo(P2VAR(Std_VersionInfoType,AUTOMATIC,ETHSM_APPL_VAR) versioninfo ); 
/*!******************************************************************************************************************
*   @brief      Handles the communication mode and sets the Ethernet network active or passive.
*   @param[in]  NetworkHandle Handle of destinated communication network for request
*   @param[in]  ComM_Mode Requested communication mode
*   @return     E_OK: Service accepted E_NOT_OK: Service denied
*   @ServiceID  0x05
*   @Sync/Async Asynchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,ETHSM_CODE) EthSM_RequestComMode( NetworkHandleType NetworkHandle, ComM_ModeType ComM_Mode );
/*!******************************************************************************************************************
*   @brief      This service shall put out the current communication mode of a Ethernet network.
*   @param[in]  NetworkHandle Network handle whose current communication mode shall be put out
*   @param[out  ComM_ModePtr Pointer where to put out the current communication mode
*   @return     E_OK: Service accepted E_NOT_OK: Service denied
*   @ServiceID  0x04
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,ETHSM_CODE) EthSM_GetCurrentComMode
( 
    NetworkHandleType NetworkHandle,
    P2VAR(ComM_ModeType,AUTOMATIC,ETHSM_APPL_VAR) ComM_ModePtr 
);
/*!******************************************************************************************************************
*   @brief      This service shall put out the current internal mode of a Ethernet network.
*   @param[in]  NetworkHandle Network handle whose current communication mode shall be put out
*   @param[out  EthSM_InternalMode Pointer where to put out the current internal mode
*   @return     E_OK: Service accepted E_NOT_OK: Service denied
*   @ServiceID  0x03
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,ETHSM_CODE) EthSM_GetCurrentInternalMode
( 
    NetworkHandleType NetworkHandle, 
    P2VAR(EthSM_NetworkModeStateType,AUTOMATIC,ETHSM_APPL_VAR) EthSM_InternalMode
);

/*!******************************************************************************************************************
*   @brief      Cyclic Main Function which is called from the Scheduler.
*   @ServiceID  0x01
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(void,ETHSM_CODE) EthSM_MainFunction( void );

#define ETHSM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* ETHSM_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
