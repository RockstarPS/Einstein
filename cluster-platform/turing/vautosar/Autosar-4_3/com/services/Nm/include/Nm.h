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
*   @file       Nm.h
*   @ingroup    Nm
*   @brief      This file provides the declaration of the Nm Callback API. This header file should be included by 
*   other modules that use the Nm Callback API.
*   @defgroup   Services
*   @brief      The Network Management (Nm) module coordinates network sleep and wake-up for ECUs, ensuring 
*   efficient communication and power management. It handles network state transitions and monitors node presence
*   in automotive networks.
********************************************************************************************************************/
#ifndef NM_H
#define NM_H

#include "Nm_Cfg.h"
/*******************************************************************************************************************/
/*  Version Information                                                                                            */
/*******************************************************************************************************************/
/* Software Version */
#define NM_SW_MAJOR_VERSION                                 (1u)
#define NM_SW_MINOR_VERSION                                 (0u)
#define NM_SW_PATCH_VERSION                                 (0u)
/* Autosar Release */
#define NM_AR_RELEASE_MAJOR_VERSION                         (4u)
#define NM_AR_RELEASE_MINOR_VERSION                         (3u)
#define NM_AR_RELEASE_REVISION_VERSION                      (1u)
/*******************************************************************************************************************/
/*  Module Information                                                                                             */
/*******************************************************************************************************************/
/* Vendor Id */
#define NM_VENDOR_ID                                        (51u)
/* Module Id */
#define NM_MODULE_ID                                        (29u)
/* Instance Id */
#define NM_INSTANCE_ID                                      (0u)
/*******************************************************************************************************************/
/*  Defines                                                                                                        */
/*******************************************************************************************************************/
/* API IDs for Error Reporting */
#define NM_SID_INIT_API                                     (0x00u)
#define NM_SID_PASSIVESTARTUP_API                           (0x01u)
#define NM_SID_NETWORKREQUEST_API                           (0x02u)
#define NM_SID_NETWORKRELEASE_API                           (0x03u)
#define NM_SID_DISABLECOMMUNICATION_API                     (0x04u)
#define NM_SID_ENABLECOMMUNICATION_API                      (0x05u)
#define NM_SID_SETUSERDATA_API                              (0x06u)
#define NM_SID_GETUSERDATA_API                              (0x07u)
#define NM_SID_GETPDUDATA_API                               (0x08u)
#define NM_SID_REPEATMESSAGEREQUEST_API                     (0x09u)
#define NM_SID_GETNODEIDENTIFIER_API                        (0x0Au)
#define NM_SID_GETLOCALNODEIDENTIFIER_API                   (0x0Bu)
#define NM_SID_CHECKREMOTESLEEPINDICATION_API               (0x0Du)
#define NM_SID_GETSTATE_API                                 (0x0Eu)
#define NM_SID_GETVERSIONINFO_API                           (0x0Fu)
#define NM_SID_MAINFUNCTION_API                             (0x10u)
#define NM_SID_INITMEMORY_API                               (0x20u)
/* API IDs for Callbacks Error Reporting */
#define NM_SID_NETWORKSTARTINDICATION_API                   (0x11u)
#define NM_SID_NETWORKMODE_API                              (0x12u)
#define NM_SID_PREPAREBUSSLEEPMODE_API                      (0x13u)
#define NM_SID_BUSSLEEPMODE_API                             (0x14u)
#define NM_SID_PDURXINDICATION_API                          (0x15u)
#define NM_SID_STATECHANGENOTIFICATION_API                  (0x16u)
#define NM_SID_REMOTESLEEPINDICATION_API                    (0x17u)
#define NM_SID_REMOTESLEEPCANCELLATION_API                  (0x18u)
#define NM_SID_SYNCHRONIZATIONPOINT_API                     (0x19u)
#define NM_SID_REPEATMESSAGEINDICATION_API                  (0x1Au)
#define NM_SID_TXTIMEOUTEXCEPTION_API                       (0x1Bu)
#define NM_SID_CARWAKEUPINDICATION_API                      (0x1Du)
#define NM_SID_COORDREADYTOSLEEPINDICATION_API              (0x1Eu)
#define NM_SID_COORDREADYTOSLEEPCANCELLATION_API            (0x1Fu)
/*******************************************************************************************************************/
/*  Development Errors                                                                                             */
/*******************************************************************************************************************/
#define NM_E_UNINIT                                         (0x00u)
#define NM_E_HANDLE_UNDEF                                   (0x01u)
#define NM_E_PARAM_POINTER                                  (0x02u)
#define NM_E_SYNCHRONIZATION_TIMEOUT                        (0x20u)
#define NM_E_FUNCTION_PTR_IS_NULL                           (0x21u)
#define NM_E_INVALID_STATE                                  (0x22u)
#define NM_E_SAME_STATES                                    (0x23u)
#define NM_E_NOT_AVAILABLE_IN_PASSIVE_MODE                  (0x24u)
#define NM_E_NO_ERROR                                       (0xFFu)
/*******************************************************************************************************************/
/*  Declaration of Public APIs                                                                                     */
/*******************************************************************************************************************/
/* Initializes the NM global variables */
extern void Nm_InitMemory(void);
/* Initializes the NM Interface */
extern void Nm_Init(const Nm_ConfigType* ConfigPtr);
/* Processes of the NM Interface which needs a fix cyclic scheduling */
extern void Nm_MainFunction(void);
/* Calls the <BusNm>_PassiveStartUp function */
extern Std_ReturnType Nm_PassiveStartUp(NetworkHandleType nmNetworkHandle);
#if (NM_PASSIVE_MODE_ENABLED == STD_OFF)
/* Calls the <BusNm>_NetworkRequest */
extern Std_ReturnType Nm_NetworkRequest(NetworkHandleType nmNetworkHandle);
/* Calls the <BusNm>_NetworkRelease bus specific function */
extern Std_ReturnType Nm_NetworkRelease(NetworkHandleType nmNetworkHandle);
#endif
#if (NM_COM_CONTROL_ENABLED == STD_ON)
/* Disables the NM PDU transmission ability */
extern Std_ReturnType Nm_DisableCommunication(NetworkHandleType nmNetworkHandle);
/* Enables the NM PDU transmission ability */
extern Std_ReturnType Nm_EnableCommunication(NetworkHandleType nmNetworkHandle);
#endif
#if (NM_USER_DATA_ENABLED == STD_ON)
#if ((NM_PASSIVE_MODE_ENABLED == STD_OFF) && (NM_COM_USER_DATA_SUPPORT == STD_OFF))
/* Sets user data for NM messages transmitted next on the bus */
extern Std_ReturnType Nm_SetUserData(NetworkHandleType nmNetworkHandle, uint8* nmUserDataPtr);
#endif
/* Gets user data out of the last successfully received NM message */
extern Std_ReturnType Nm_GetUserData(NetworkHandleType nmNetworkHandle, uint8* nmUserDataPtr);
#endif
#if ((NM_NODE_ID_ENABLED == STD_ON) || (NM_USER_DATA_ENABLED == STD_ON))
/* Gets the whole PDU data out of the most recently received NM message */
extern Std_ReturnType Nm_GetPduData(NetworkHandleType nmNetworkHandle, uint8* nmPduDataPtr);
#endif
#if (NM_NODE_DETECTION_ENABLED == STD_ON)
/* Sets Repeat Message Request Bit for NM messages transmitted next on the bus */
extern Std_ReturnType Nm_RepeatMessageRequest(NetworkHandleType nmNetworkHandle);
#endif
#if (NM_NODE_ID_ENABLED == STD_ON)
/* Gets node identifier out of the last successfully received NM message */
extern Std_ReturnType Nm_GetNodeIdentifier(NetworkHandleType nmNetworkHandle, uint8* nmNodeIdPtr);
/* Gets node identifier configured for the local node */
extern Std_ReturnType Nm_GetLocalNodeIdentifier(NetworkHandleType nmNetworkHandle, uint8* nmNodeIdPtr);
#endif
#if (NM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
/* Checks if remote sleep indication takes place or not */
extern Std_ReturnType Nm_CheckRemoteSleepIndication(NetworkHandleType nmNetworkHandle, boolean* nmRemoteSleepIndPtr);
#endif
/* Copies the NM state and the NM mode to the location provided by the pointers */
extern Std_ReturnType Nm_GetState(NetworkHandleType nmNetworkHandle, Nm_StateType* nmStatePtr, Nm_ModeType* nmModePtr);
#if (NM_VERSION_INFO_API == STD_ON)
/* Returns version information, vendor ID and AUTOSAR module ID of the component */
extern void Nm_GetVersionInfo(Std_VersionInfoType* nmVerInfoPtr);
#endif
#endif /* NM_H */

/*****************************************************************************************************************
*                                 END OF FILE                                                                    *
******************************************************************************************************************/
