/********************************************************************************************************************
|   File Name   : CanNm.h
|
|  Description: This header provides declaration of interface functions of Can AUTOSAR NM module .
|--------------------------------------------------------------------------------------------------------------------
|               C O P Y R I G H T
|--------------------------------------------------------------------------------------------------------------------
| Copyright (c) 2019 by Visteon Corporation.       All rights reserved.
|
| NOTICE: This is an unpublished work of authorship, which contains trade secrets.
| Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
| its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
| or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
| in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
| under all copyright laws to protect this work as a published work, when appropriate.
| Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
| without the written authorization of Visteon Corporation.
|--------------------------------------------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|--------------------------------------------------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| EA            Ashok Elavarasu          Visteon Corporation
|--------------------------------------------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|--------------------------------------------------------------------------------------------------------------------
| Date        Version   Author  Description
| ----------  --------  ------  -------------------------------------------------------------------------------------
| 2020-03-17  00.00.02  EA     Basic Funcitionality Realisation
| 2019-12-05  00.00.01  MA     Initial Version
|*******************************************************************************************************************/
#ifndef CANNM_H
#define CANNM_H

#include "ComStack_Types.h"
#include "NmStack_Types.h"
#include "CanNm_Types.h"
#include "CanNm_Cfg.h"
/*******************************************************************************************************************/
/*  Version Information                                                                                            */
/*******************************************************************************************************************/
/* Software Version */
#define CANNM_SW_MAJOR_VERSION                              (0u)
#define CANNM_SW_MINOR_VERSION                              (0u)
#define CANNM_SW_PATCH_VERSION                              (1u)
/* Autosar Release */
#define CANNM_AR_RELEASE_MAJOR_VERSION                      (4u)
#define CANNM_AR_RELEASE_MINOR_VERSION                      (3u)
#define CANNM_AR_RELEASE_REVISION_VERSION                   (1u)
/*******************************************************************************************************************/
/*  Module Information                                                                                             */
/*******************************************************************************************************************/
/* Vendor Id */
#define CANNM_VENDOR_ID                                     (51u)
/* Module Id */
#define CANNM_MODULE_ID                                     (31u)
/* Instance Id */
#define CANNM_INSTANCE_ID                                   (0u)
/*******************************************************************************************************************/
/*  Defines                                                                                                        */
/*******************************************************************************************************************/
/* API IDs for Error Reporting */
#define CANNM_SID_INIT_API                                  (0x00U)
#define CANNM_SID_PASSIVESTARTUP_API                        (0x01U)
#define CANNM_SID_NETWORKREQUEST_API                        (0x02U)
#define CANNM_SID_NETWORKRELEASE_API                        (0x03U)
#define CANNM_SID_SETUSERDATA_API                           (0x04U)
#define CANNM_SID_GETUSERDATA_API                           (0x05U)
#define CANNM_SID_GETNODEIDENTIFIER_API                     (0x06U)
#define CANNM_SID_GETLOCALNODEIDENTIFIER_API                (0x07U)
#define CANNM_SID_REPEATMESSAGEREQUEST_API                  (0x08U)
#define CANNM_SID_GETPDUDATA_API                            (0x0AU)
#define CANNM_SID_GETSTATE_API                              (0x0BU)
#define CANNM_SID_DISABLECOMMUNICATION_API                  (0x0CU)
#define CANNM_SID_ENABLECOMMUNICATION_API                   (0x0DU)
#define CANNM_SID_MAINFUNCTION_API                          (0x13U)
#define CANNM_SID_TRANSMIT_API                              (0x14U)
#define CANNM_SID_CONFIRMPNAVAILABILITY_API                 (0x16U)
#define CANNM_SID_SETSLEEPREADYBIT_API                      (0x17U)
#define CANNM_SID_REQUESTBUSSYNCHRONIZATION_API             (0xC0U)
#define CANNM_SID_CHECKREMOTESLEEPIND_API                   (0xD0U)
#define CANNM_SID_GETVERSIONINFO_API                        (0xF1U)
/* API IDs for Callbacks Error Reporting */
#define CANNM_SID_TXCONFIRMATION_API                        (0x40u)
#define CANNM_SID_RXINDICATION_API                          (0x42u)
/*******************************************************************************************************************/
/*  Development Errors                                                                                             */
/*******************************************************************************************************************/
#define CANNM_E_NO_ERROR                                    (0x00U)
#define CANNM_E_NO_INIT                                     (0x01U)
#define CANNM_E_INVALID_CHANNEL                             (0x02U)
#define CANNM_E_INVALID_PDUID                               (0x03U)
#define CANNM_E_NET_START_IND                               (0x04U)
#define CANNM_E_INIT_FAILED                                 (0x05U)
#define CANNM_E_NETWORK_TIMEOUT                             (0x11U)
#define CANNM_E_PARAM_POINTER                               (0x12U)
/*******************************************************************************************************************/
/*  Declaration of Public APIs                                                                                     */
/*******************************************************************************************************************/
/* Initializes the CanNm module init status */
extern void CanNm_InitMemory(void);
/* Initializes the CanNm module */
extern void CanNm_Init(const CanNm_ConfigType * const CannmConfigPtr);
/* Passive startup of the AUTOSAR CAN NM */
extern Std_ReturnType CanNm_PassiveStartUp(NetworkHandleType nmChannelHandle);
#if (CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
/* Requests the network */
extern Std_ReturnType CanNm_NetworkRequest(NetworkHandleType nmChannelHandle);
/* Releases the network */
extern Std_ReturnType CanNm_NetworkRelease(NetworkHandleType nmChannelHandle);
#endif
/* Returns the state and the mode of the network management */
extern Std_ReturnType CanNm_GetState(NetworkHandleType nmChannelHandle, Nm_StateType* nmStatePtr,
                                     Nm_ModeType* nmModePtr);
#if (CANNM_USER_DATA_ENABLED == STD_ON)
#if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_COM_USER_DATA_SUPPORT == STD_OFF))
/* Sets user data for NM PDUs transmitted next on the bus */
extern Std_ReturnType CanNm_SetUserData(NetworkHandleType nmChannelHandle, const uint8* nmUserDataPtr);
#endif
/* Gets user data out of the most recently received NM PDU */
extern Std_ReturnType CanNm_GetUserData(NetworkHandleType nmChannelHandle, uint8* const nmUserDataPtr);
#endif
#if (CANNM_NODE_ID_ENABLED == STD_ON)
/* Gets node identifier out of the most recently received NM PDU */
extern Std_ReturnType CanNm_GetNodeIdentifier(NetworkHandleType nmChannelHandle, uint8* nmNodeIdPtr);
/* Gets node identifier configured for the local node */
extern Std_ReturnType CanNm_GetLocalNodeIdentifier(NetworkHandleType nmChannelHandle, uint8* nmNodeIdPtr);
#endif
#if (CANNM_NODE_DETECTION_ENABLED == STD_ON)
/* Sets Repeat Message Request Bit for NM PDUs transmitted next on the bus */
extern Std_ReturnType CanNm_RepeatMessageRequest(NetworkHandleType nmChannelHandle);
#endif
#if ((CANNM_NODE_DETECTION_ENABLED == STD_ON) || (CANNM_USER_DATA_ENABLED == STD_ON) || \
     (CANNM_NODE_ID_ENABLED == STD_ON))
/* Gets the whole PDU data out of the most recently received NM PDU */
extern Std_ReturnType CanNm_GetPduData(NetworkHandleType nmChannelHandle, uint8* nmPduDataPtr);
#endif
#if (CANNM_BUS_SYNCHRONIZATION_ENABLED == STD_ON)
/* Requests bus synchronization */
extern Std_ReturnType CanNm_RequestBusSynchronization(NetworkHandleType nmChannelHandle);
#endif
#if (CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
/* Checks if remote sleep indication takes place or not */
extern Std_ReturnType CanNm_CheckRemoteSleepIndication(NetworkHandleType nmChannelHandle,
                                                       boolean* nmRemoteSleepIndPtr);
#endif
#if (CANNM_VERSION_INFO_API == STD_ON)
/* This service returns the version information of this module */
extern void CanNm_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif
#if (CANNM_COM_CONTROL_ENABLED == STD_ON)
/* Enables the NM PDU transmission ability */
extern Std_ReturnType CanNm_EnableCommunication(NetworkHandleType nmChannelHandle);
/* Disables the NM PDU transmission ability */
extern Std_ReturnType CanNm_DisableCommunication(NetworkHandleType nmChannelHandle);
#endif
#if (CANNM_COORDINATOR_SYNC_SUPPORT == STD_ON)
/* Sets the NM Coordinator Sleep Ready bit in the Control Bit Vector */
extern Std_ReturnType CanNm_SetSleepReadyBit(NetworkHandleType nmChannelHandle, const boolean nmSleepReadyBit);
#endif
#if ((CANNM_COM_USER_DATA_SUPPORT == STD_ON) || defined (CANNM_PN_CALC_FEATURE_ENABLED))
/* This function is used by the PduR to trigger a spontaneous transmission of an NM PDU with provided NM User Data */
extern Std_ReturnType CanNm_Transmit(PduIdType CanNmTxPduId, const PduInfoType* PduInfoPtr);
#endif
#if (CANNM_PN_ENABLED == STD_ON)
/* Enables the PN filter functionality on the indicated NM channel */
extern void CanNm_ConfirmPnAvailability(NetworkHandleType nmChannelHandle);
#endif
#endif /* CANNM_H */
