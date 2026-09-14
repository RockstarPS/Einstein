/********************************************************************************************************************
|   File Name   : Nm_Cfg.h
|
|   Description : This header provides the pre-compile time configurable parameters 
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
| MA            Muthu Alexander          Visteon Corporation
|--------------------------------------------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|--------------------------------------------------------------------------------------------------------------------
| Date        Version   Author  Description
| ----------  --------  ------  -------------------------------------------------------------------------------------
| 2019-12-05  00.00.01  MA     Initial Version
|*******************************************************************************************************************/
#ifndef NM_CFG_H
#define NM_CFG_H

#include "ComStack_Types.h"
#include "NmStack_Types.h"
#include "Com_Types.h"
#include "SchM_Nm.h"

/*******************************************************************************************************************/
/*  Version Information                                                                                            */
/*******************************************************************************************************************/
/* Software Version */
#define NM_CFG_SW_MAJOR_VERSION                               1u
#define NM_CFG_SW_MINOR_VERSION                               0u
#define NM_CFG_SW_PATCH_VERSION                               0u
/* Autosar Release */
#define NM_CFG_AR_RELEASE_MAJOR_VERSION                       4u
#define NM_CFG_AR_RELEASE_MINOR_VERSION                       3u
#define NM_CFG_AR_RELEASE_REVISION_VERSION                    1u

/*! @brief Defines the Number of NM channels supported */
#define NM_NUMBER_OF_CHANNELS           2U
/*! @brief Defines the Number of NM clusters supported */
#define NM_NUMBER_OF_CLUSTERS           1U
/*! @brief Defines the value of the NM zero constant */
#define NM_ZERO                         0U
/*! @brief Defines the value of the NM maximum clusters constant */
#define NM_MAX_CLUSTERS                 0xFFU
/*! @brief Defines the period between successive calls to the Main Function of the NM Interface in seconds. */
#define NM_CYCLE_TIME_MAIN_FUNCTION     10U
/*! @brief Enables/Disables the Default Error Tracer (Det) detection and notification ON or OFF*/ 
#define NM_DEV_ERROR_DETECT             STD_ON
/*! @brief Enables/Disables the Version Info API support */
#define NM_VERSION_INFO_API             STD_ON
/*! @brief Enables/Disables bus synchronization support of the <BusNm>s. This feature is required 
    for NM Coordinator nodes only.*/
#define NM_BUS_SYNCHRONIZATION_ENABLED  STD_ON
/*! @brief Enables or disables CWU detection. FALSE - CarWakeUp not
    supported TRUE - CarWakeUp supported*/
#define NM_CAR_WAKE_UP_RX_ENABLED       STD_ON
/*! @brief Enables/Disables Communication Control support*/
#define NM_COM_CONTROL_ENABLED          STD_ON
/*! @brief Enable/Disable setting of NMUserData via SW-C. If NmComUserDataSupport is enabled the API Nm_SetUserData 
    shall not be available.*/
#define NM_COM_USER_DATA_SUPPORT        STD_ON
/*! @brief Enable/Disable NM Coordinator support . Only valid if NmRemoteSleepIndEnabled AND
    NmNumberOfChannels > 1 */
#define NM_COORDINATOR_SUPPORT_ENABLED  STD_ON
/*! @brief Enables/disables the coordinator synchronization support. 
    NmCoordinatorSyncSupport shall only be valid if NmCoordinatorSupportEnabled is TRUE.*/
#define NM_COORDINATOR_SYNC_SUPPORT     STD_ON
/*! @brief Defines the maximum shutdown time of a connected and coordinated NM-Cluster in milliseconds.
    NmGlobalCoordinatorTime shall only be valid if NmCoordinatorSupportEnabled is TRUE.*/
#define NM_GLOBAL_COORDINATOR_TIME      (uint32)5000U
/*! @brief Enables/disables the Node Detection feature . Only valid if NmNodeIdEnabled is set to TRUE*/
#define NM_NODE_DETECTION_ENABLED       STD_ON
/*! @brief Enables/disables the transmission of the source node identifier in NM messages. */
#define NM_NODE_ID_ENABLED              STD_ON
/*! @brief Enables/disables the support of Passive Mode of the <BusNm>s.*/
#define NM_PASSIVE_MODE_ENABLED         STD_OFF
/*! @brief Enables/disables the support of enabling the PDU Rx Indication*/
#define NM_PDU_RX_INDICATION_ENABLED    STD_ON
/*! @brief Enables/disables the Remote Sleep Indication support. This feature is required for a Gateway or  
    NM Coordinator functionality. It must not be enabled if NmPassiveModeEnabled is enabled. */
#define NM_REMOTE_SLEEP_IND_ENABLED     STD_ON
/*! @brief Enables/disables the Repeat Message Bit Indication support.*/
#define NM_REPEAT_MSG_IND_ENABLED       STD_ON
/*! @brief Enables/disables the Network Management state change notification.*/
#define NM_STATE_CHANGE_IND_ENABLED     STD_ON
/*! @brief Enables/disables the User Data support */
#define NM_USER_DATA_ENABLED            STD_ON
/*! @brief Defines the number of channels supported in ComM */
#define NM_COMM_NUMBER_OF_CHANNELS      2U
/*! @brief Enables or Disables the support of Generic NM . */
#define NM_BUSNM_GENERIC_NM_SUPPORT     STD_ON
/*! @brief Defines the number of unique BUS NM supported by the NM .*/
#define NM_NUM_OF_BUS_NM_SUPPORTED      2U
/*! @brief Defines the unused ComM channel indexes .*/
#define NM_NO_COMM_TO_NM_CHIND          255U
/*! @brief Defines the callout function to be called if Nm_CarWakeUpIndication()
    is called. If this parameter is not configured, the NmIf will call BswM_CarWakeUpIndication. 
    only available if NmCarWakeUpRxEnabled == TRUE 
*/ 
#if (NM_CAR_WAKE_UP_RX_ENABLED == STD_ON)
#define NM_CAR_WAKEUP_CALLOUT           CalloutFn 
#endif

#ifndef NM_UNUSED_PARAM
#define NM_UNUSED_PARAM(param) ((void)(param))
#endif

#define Nm_EnterCriticalSection()    SchM_Enter_Nm_NM_EXCLUSIVE_AREA_0()
#define Nm_ExitCriticalSection()     SchM_Exit_Nm_NM_EXCLUSIVE_AREA_0()

/*! @brief Defines the function prototype for the API to Passive startup of the NM. It triggers the 
    transition from Bus-Sleep Mode to the Network Mode without requesting the network. */
typedef Std_ReturnType (*Nm_BusNmPassiveStartUp)(NetworkHandleType nmNetworkHandle);
/*! @brief Defines the function prototype for the API to Get the state and the mode of the network management.*/
typedef Std_ReturnType (*Nm_BusNmGetStateFunctType)(NetworkHandleType nmNetworkHandle, Nm_StateType* nmStatePtr, Nm_ModeType* nmModePtr);
#if(NM_PASSIVE_MODE_ENABLED == STD_OFF)
/*! @brief Defines the function prototype for the API to Request the network, since ECU needs to communicate on 
    the bus.*/
typedef Std_ReturnType (*Nm_BusNmNetworkRequestFunctType)(NetworkHandleType nmNetworkHandle);
/*! @brief Defines the function prototype for the API to Release the network, since ECU doesn't have to communicate
    on the bus.*/
typedef Std_ReturnType (*Nm_BusNmNetworkReleaseFunctType)(NetworkHandleType nmNetworkHandle);
#endif
#if(NM_COM_CONTROL_ENABLED == STD_ON)
/*! @brief Defines the function prototype for the API to Disable the NM PDU transmission ability.*/
typedef Std_ReturnType (*Nm_BusNmDisableCommunicationFunctType)(NetworkHandleType nmNetworkHandle);
/*! @brief Defines the function prototype for the API to Enable the NM PDU transmission ability.*/
typedef Std_ReturnType (*Nm_BusNmEnableCommunicationFunctType)(NetworkHandleType nmNetworkHandle);
#endif
#if(NM_USER_DATA_ENABLED == STD_ON) 
#if ((NM_PASSIVE_MODE_ENABLED == STD_OFF) && (NM_COM_USER_DATA_SUPPORT == STD_OFF))
/*! @brief Defines the function prototype for the API to Set user data for NM messages transmitted next on the bus.*/
typedef Std_ReturnType (*Nm_BusNmSetUserDataFunctType)(NetworkHandleType nmNetworkHandle, const uint8* nmUserDataPtr);
#endif
/*! @brief Defines the function prototype for the API to Get user data out of the most recently received NM PDU.*/
typedef Std_ReturnType (*Nm_BusNmGetUserDataFunctType)(NetworkHandleType nmNetworkHandle, uint8* nmUserDataPtr);
#endif
#if(NM_NODE_ID_ENABLED == STD_ON)
/*! @brief Defines the function prototype for the API to Get node identifier out of the last successfully received
    NM-message.*/
typedef Std_ReturnType (*Nm_BusNmGetNodeIdentifierFunctType)(NetworkHandleType nmNetworkHandle, uint8* nmNodeIdPtr);
/*! @brief Defines the function prototype for the API to Get node identifier configured for the local node.*/
typedef Std_ReturnType (*Nm_BusNmGetLocalNodeIdentifierFunctType)(NetworkHandleType nmNetworkHandle, uint8* nmNodeIdPtr);
#endif
#if(NM_NODE_DETECTION_ENABLED == STD_ON)
/*! @brief Defines the function prototype for the API to Set Repeat Message Request Bit for NM PDUs transmitted 
    next on the bus. Request a Repeat Message Request to be transmitted next on the bus.*/
typedef Std_ReturnType (*Nm_BusNmRepeatMessageRequestFunctType)(NetworkHandleType nmNetworkHandle);
#endif
#if ((NM_NODE_ID_ENABLED == STD_ON) || (NM_USER_DATA_ENABLED == STD_ON))
/*! @brief Defines the function prototype for the API to Get the whole PDU data out of the most recently 
    received NM PDU. */
typedef Std_ReturnType (*Nm_BusNmGetPduDataFunctType)(NetworkHandleType nmNetworkHandle, uint8* nmPduDataPtr);
#endif
#if(NM_PDU_RX_INDICATION_ENABLED == STD_ON)
/*! @brief Defines the function prototype for the API to notify reception of NM message.*/
typedef void (*Nm_BusNmPduRxIndicationCallOutFunctType)(NetworkHandleType nmNetworkHandle);
#endif
#if(NM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
/*! @brief Defines the function prototype for the API to Check if remote sleep indication takes place or not.*/
typedef Std_ReturnType (*Nm_BusNmCheckRemoteSleepIndicationFunctType)(NetworkHandleType nmNetworkHandle, boolean* nmRemoteSleepIndPtr);
#endif
#if(NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
/*! @brief Defines the function prototype for the API to Set the NM Coordinator Sleep Ready bit in the Control
    Bit Vector.*/
typedef Std_ReturnType (*Nm_BusNmSetSleepReadyBitFunctType)(NetworkHandleType nmNetworkHandle, boolean nmSleepReadyBit);
/*! @brief Defines the function prototype for the API to Request bus synchronization.*/
typedef Std_ReturnType (*Nm_BusNmRequestBusSynchronizationFunctType)(NetworkHandleType nmNetworkHandle);
#endif
#if (NM_CAR_WAKE_UP_RX_ENABLED == STD_ON)
typedef void (*Nm_BusNmCarWakeUpCalloutFunctType)(NetworkHandleType nmNetworkHandle);
#endif
#if (NM_REPEAT_MSG_IND_ENABLED == STD_ON)
typedef void (*Nm_RepeatMessageIndicationFunctType)(NetworkHandleType nmNetworkHandle);
#endif
#if (NM_PASSIVE_MODE_ENABLED == STD_OFF)
typedef void (*Nm_TxTimeoutExceptionFunctType)(NetworkHandleType nmNetworkHandle);
#endif

/*! @brief Defines the Bus specific NM function configuration types */
typedef struct 
{
    /*! @brief Defines the function to Passive startup of the NM.*/
    Nm_BusNmPassiveStartUp                      BusNmPassiveStartUpFunctPtr;  
    /*! @brief Defines the function to Get the state and the mode of the network management.*/
    Nm_BusNmGetStateFunctType                   BusNmGetStateFunctPtr;
    #if(NM_PASSIVE_MODE_ENABLED == STD_OFF)
    /*! @brief Defines the function to Request the network.*/
    Nm_BusNmNetworkRequestFunctType             BusNmNetworkRequestFunctPtr;
    /*! @brief Defines the function to Release the network.*/
    Nm_BusNmNetworkReleaseFunctType             BusNmNetworkReleaseFunctPtr;
    #endif
    #if(NM_COM_CONTROL_ENABLED == STD_ON)
    /*! @brief Defines the function to Disable the NM PDU transmission ability.*/
    Nm_BusNmDisableCommunicationFunctType       BusNmDisableCommunicationFunctPtr;
    /*! @brief Defines the function to Enable the NM PDU transmission ability.*/
    Nm_BusNmEnableCommunicationFunctType        BusNmEnableCommunicationFunctPtr;
    #endif
    #if(NM_USER_DATA_ENABLED == STD_ON) 
    #if ((NM_PASSIVE_MODE_ENABLED == STD_OFF) && (NM_COM_USER_DATA_SUPPORT == STD_OFF))
    /*! @brief Defines the function to Set user data for NM messages transmitted next on the bus.*/
    Nm_BusNmSetUserDataFunctType                BusNmSetUserDataFunctPtr;
    #endif
    /*! @brief Defines the function to Get user data out of the most recently received NM PDU.*/
    Nm_BusNmGetUserDataFunctType                BusNmGetUserDataFunctPtr;
    #endif
    #if(NM_NODE_ID_ENABLED == STD_ON)
    /*! @brief Defines the function Get node identifier out of the last successfully received NM-message.*/
    Nm_BusNmGetNodeIdentifierFunctType          BusNmGetNodeIdentifierFunctPtr;
    /*! @brief Defines the function to Get node identifier configured for the local node.*/
    Nm_BusNmGetLocalNodeIdentifierFunctType     BusNmGetLocalNodeIdentifierFunctPtr;
    #endif
    #if(NM_NODE_DETECTION_ENABLED == STD_ON)
    /*! @brief Defines the function to Request a Repeat Message Request to be transmitted next on the bus.*/
    Nm_BusNmRepeatMessageRequestFunctType       BusNmRepeatMessageRequestFunctPtr;
    #endif
    #if ((NM_NODE_ID_ENABLED == STD_ON) || (NM_USER_DATA_ENABLED == STD_ON))
    /*! @brief Defines the function Get the whole PDU data out of the most recently received NM PDU. */
    Nm_BusNmGetPduDataFunctType                 BusNmGetPduDataFunctPtr;
    #endif
    #if(NM_PDU_RX_INDICATION_ENABLED == STD_ON)
    /*! @brief Defines the function prototype for the API to notify reception of NM message.*/
    Nm_BusNmPduRxIndicationCallOutFunctType     BusNmPduRxIndicationFunctPtr;
    #endif
    #if(NM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
    /*! @brief Defines the function to Check if remote sleep indication takes place or not.*/
    Nm_BusNmCheckRemoteSleepIndicationFunctType BusNmCheckRemoteSleepIndicationFunctPtr;
    #endif
    #if(NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
    /*! @brief Defines the function to Request bus synchronization.*/
    Nm_BusNmRequestBusSynchronizationFunctType  BusNmRequestBusSynchronizationFunctPtr;
    /*! @brief Defines the function to Set the NM Coordinator Sleep Ready bit in the Control Bit Vector.*/
    Nm_BusNmSetSleepReadyBitFunctType           BusNmSetSleepReadyBitFunctPtr;
    #endif
    #if (NM_CAR_WAKE_UP_RX_ENABLED == STD_ON)
    /*! @brief Defines the function to callout if Nm_CarWakeUpIndication() is called. */
    Nm_BusNmCarWakeUpCalloutFunctType           BusNmCarWakeUpCalloutFunctPtr;
    #endif
}Nm_BusNmFunctConfigType;

/*! @brief Defines the type for the NM OEM specific callback configuration */
typedef struct
{
#if (NM_REPEAT_MSG_IND_ENABLED == STD_ON)
    /*! @brief Function pointer for the NM Repeat Message Indication callback */
    Nm_RepeatMessageIndicationFunctType         UlRepeatMessageIndicationFunctPtr;
#endif
#if (NM_PASSIVE_MODE_ENABLED == STD_OFF)
    /*! @brief Function pointer for the NM Tx Timeout Exception callback */
    Nm_TxTimeoutExceptionFunctType              UlTxTimeoutExceptionFunctPtr;
#endif
}Nm_OemFunctType;

/*! @brief Defines the type for the Bus specific NM configuration ID type */
typedef uint8 Nm_BusNmInterfaceConfigIdType;

/*! @brief Defines the bus specific shutdown time type */
typedef uint32 Nm_ShutdownTimeType;

/*! @brief Defines the type for the shutdown timer */
typedef uint32 Nm_ShutdownTimerType;

/*! @brief Defines the configuration for NM Channels*/
typedef struct
{
    /*! @brief Defines the Bus specific NM configuration ID */
    Nm_BusNmInterfaceConfigIdType    BusNmFunctConfigId; 
    /*! @brief Defines the BusNm type.*/
    Nm_BusNmType                     BusNmType;
    /*! @brief Defines the ComM channel reference.*/
    NetworkHandleType                ComMChRef;
    #if(NM_COORDINATOR_SUPPORT_ENABLED == STD_ON) 
    #if (NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
    /*! @brief This parameter indicates whether a NM channel - part of a NM Coordination cluster - will be coordinated 
        actively (NmActiveCoordinator = TRUE) or passively (NmActiveCoordinator = FALSE). */
    boolean                          NmActiveCoordinator;
    #endif
    /*! @brief This parameter shall be set to indicate if the sleep of this network can be absolutely decided by the 
        local node only and that no other nodes can oppose that decision.*/
    boolean                          NmChannelSleepMaster;
    /*! @brief This parameter defines the NM coordination cluster index to which it belongs*/
    uint8                            NmCoordClusterIndex;
    /*! @brief If this parameter is true, then this network is a synchronizing network for the NM coordination 
        cluster which it belongs to. The network is expected to call Nm_SynchronizationPoint() at regular intervals.*/
    boolean                          NmSynchronizingNetwork;
    /*! @brief Bus specific Shutdown Time */
    Nm_ShutdownTimeType              NmBusNmShutdownTime;
    #endif
    #if(NM_STATE_CHANGE_IND_ENABLED == STD_ON)
    /*! @brief This parameter shall be set to update the Network Management State (NMS) via ComSignal*/
    boolean                          NmStateReportEnabled;
    /*! @brief Reference to the signal for setting the NMS by calling
        Com_SendSignal for the respective channel. */
    Com_SignalIdType                 NmStateReportSignalId;
    #endif
    #if (NM_BUSNM_GENERIC_NM_SUPPORT == STD_ON)
    /*! @brief This parameter shall be used to calculate shutdown delay time in milliseconds. */
    uint32                           NmGenericBusNmShutdownTime;
    #endif
}Nm_ChannelConfigType;

#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)

/* NM Shutdown Coordination State Type */
typedef enum
{
    /*! @brief Shutdown Coordination Initialization */
    NM_SHUTDOWN_INIT = 0x0u,
    /*! @brief Shutdown Coordination Start */
    NM_SHUTDOWN_START,
    /*! @brief Shutdown Coordination Abort */
    NM_SHUTDOWN_ABORT,
    /*! @brief Shutdown Coordination Running (Network cannot be released) */
    NM_SHUTDOWN_RUN,
    /*! @brief Shutdown Coordination Stop (Network can be released) */
    NM_SHUTDOWN_STOP,
} Nm_ShutdownStateType;

/* Defines the per-cluster configuration for the NM Coordinator */
typedef struct
{
#if (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)
    /*! @brief Indicates whether this node is the top most coordinator in the NM coordination cluster */
    boolean NmTopMostCoordinator;
#endif /* STD_ON == NM_COORDINATOR_SYNC_SUPPORT */
    /*! @brief Indicates whether this node is a synchronizing network in the NM coordination cluster */
    boolean NmSyncNetFlag;
    /*! @brief Defines the cluster index */
    uint8 NmCoorClusterIndex;
    /*! @brief Defines the number of channels included in the NM coordination cluster */
    uint8 NmClusterIncNumChannel;
    /*! @brief Defines the included channels in the NM coordination cluster */
    const uint8* NmClusterIncChannel;
}Nm_PerClusterConfigType;

/* Defines the overall configuration for the NM Coordinator */
typedef struct
{
    /*! @brief Defines the number of clusters in the NM coordination cluster */
    uint8 NmNumOfClusters;
    /*! @brief Defines the pointer to the per-cluster configuration */
    const Nm_PerClusterConfigType* NmPerClusterPtr;
}Nm_CoordConfigType;

/* NM Shutdown Coordination Status Type */
typedef struct
{
    /*! @brief Holds the Shutdown Timer for each cluster */
    Nm_ShutdownTimerType Nm_ShutdownTimer;
    /*! @brief Holds the Remote Sleep Indication flag for each channel */
    boolean Nm_RemoteSleepInd;
    /*! @brief Holds the Bus Awake flag for each channel */
    boolean Nm_BusAwake;
    /*! @brief Holds the Lower Layer Network Request flag for each channel */
    boolean Nm_IsLowerLayNetworkRequested;
    /*! @brief Holds the Upper Layer Network Request flag for each channel */
    boolean Nm_UpperLayNetworkReq;
    /*! @brief Holds the Shutdown flag for each channel */
    boolean Nm_AllowShutdown;
    /*! @brief Holds the Lower Layer Bus Sync Point flag for each channel */
    boolean Nm_LowerLayBusSyncPoint;
#if (NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
    /*! @brief Holds the Ready Sleep Bit flag for each channel */
    boolean Nm_CoorRsbFlag;
#endif
} Nm_CoordStatusType;

#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */

void CanNmCallOut_PduRxIndication(NetworkHandleType Channel);

/*! @brief It defines the mapping between the ComM channel and NM channel */
extern const NetworkHandleType Nm_ComMToNmChannelMapping[NM_COMM_NUMBER_OF_CHANNELS];
/*! @brief It defines the supported function by the bus specific NM */
extern const Nm_BusNmFunctConfigType Nm_BusNmFunctConfig[NM_NUM_OF_BUS_NM_SUPPORTED];
/*! @brief It defines the channel configuration of each supported NM */
extern const Nm_ChannelConfigType Nm_ChannelConfig[NM_NUMBER_OF_CHANNELS];
/*! @brief It defines the supported function by the generic NM */
extern const Nm_OemFunctType Nm_OemFunctConfig[NM_NUMBER_OF_CHANNELS];

#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
/*! @brief It defines the channels included in the coordination cluster */
extern const uint8 Nm_ClusterChannels_0[NM_NUMBER_OF_CHANNELS];
/*! @brief It defines the per-cluster configuration of the NM Coordinator */
extern const Nm_PerClusterConfigType Nm_PerClusterConfig[NM_NUMBER_OF_CLUSTERS];
/*! @brief It defines the configuration of the NM */
extern const Nm_CoordConfigType Nm_CoordConfig;
/*! @brief Defines the status of the NM Coordinator */
extern Nm_CoordStatusType Nm_CoordStatus[NM_NUMBER_OF_CHANNELS];
/*! @brief Holds the Shutdown Status for each cluster */
extern Nm_ShutdownStateType Nm_ShutdownState[NM_NUMBER_OF_CLUSTERS];
#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */

#endif /* NM_CFG_H */

/*****************************************************************************************************************
*                                 END OF FILE                                                                    *
******************************************************************************************************************/
/*****************************************************************************************************************
*   For each change to this file, be sure to record:                                                             *
*      1.  who made the change and when the change was made                                                      *
*      2.  why the change was made and the intended result                                                       *
*   Following block needs to be repeated for each change                                                         *
******************************************************************************************************************/
/*!***************************************************************************************************************
*  @date            14-Jul-2023
*  @version         0.0.1
*  @author          EA
*  @brief           Initial Version
*  @tracability     
*******************************************************************************************************************/
/*!*****************************************************************************************************************
*  @date            14-Jul-2025
*  @version         1.0.0
*  @author          MHISHAMU
*  @brief           Implemented Coordination Support
*  @tracability     DICVA-19335
*******************************************************************************************************************/
