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
*    @file ComM_Cfg.h
*    @ingroup ComM" Configuration
*    @brief This is ComM Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the ComM module.
*    Auto generated code in EASHOK at 2020-09-14 15:55:30.290345
********************************************************************************************************************/
#ifndef COMM_CFG_H
#define COMM_CFG_H

/* Includes */
#include "SchM_ComM.h"


/* Software Version */
/*! @brief Defines the ComM configuration software Major version */
#define COMM_CFG_SW_MAJOR_VERSION                   0U
/*! @brief Defines the ComM configuration software Minor version */
#define COMM_CFG_SW_MINOR_VERSION                   0U
/*! @brief Defines the ComM configuration software Patch version */
#define COMM_CFG_SW_PATCH_VERSION                   3U
/* Autosar Release */
/*! @brief Defines the AUTOSAR Release Major version supported by ComM configuration  */
#define COMM_CFG_AR_RELEASE_MAJOR_VERSION           4U
/*! @brief Defines the AUTOSAR Release Minor version supported by ComM configuration  */
#define COMM_CFG_AR_RELEASE_MINOR_VERSION           2U
/*! @brief Defines the AUTOSAR Release Patch version supported by ComM configuration  */
#define COMM_CFG_AR_RELEASE_REVISION_VERSION        1U

#define COMM_DEV_ERROR_DETECT                             STD_ON
#define COMM_MODE_LIMITATION_ENABLED                      STD_OFF
#define COMM_NM_PASSIVE_MODE_ENABLE                       STD_OFF
#define COMM_PNC_GATEWAY_ENABLED                          STD_OFF
#define COMM_PNC_SUPPORT                                  STD_OFF
#define COMM_RESET_AFTER_FORCING_NO_COMM                  STD_OFF
#define COMM_SYNCHRONOUS_WAKEUP                           STD_OFF
#define COMM_VERSION_INFO_API                             STD_ON
#define COMM_WAKEUP_INHIBITION_ENABLED                    STD_OFF
#define COMM_USER_MODE_NOTIFICATION_SUPPORT               STD_OFF
#define COMM_DCM_MODE_INDICATION_SUPPORT                  STD_ON
#define COMM_NM_MODULE_USED                               STD_OFF
#define COMM_ECU_GROUP_CLASSIFICATION                     0U
#define COMM_PNC_PREPARE_SLEEP_TIMER                      0U
#define COMM_TMIN_FULL_COM_MODE_DURATION                  500U
#define COMM_MAIN_FUNCTION_PERIOD                         10U
#define ComM_EnterCriticalSection()                       SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_0()
#define ComM_ExitCriticalSection()                        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_0()
#define COMM_NUM_OF_SUPPORTED_BUS                         2U

/* USER ID Config */
#define COMM_USER_BCAN                  0U
#define COMM_USER_FCAN                  1U
#define COMM_USER_MCAN                  2U
#define COMM_USER_LIN                   3U
#define COMM_NUM_OF_USERS               4U

/* ComM channel ID Config */
#define COMM_CHANNEL_BCAN                  0U
#define COMM_CHANNEL_FCAN                  1U
#define COMM_CHANNEL_MCAN                  2U
#define COMM_CHANNEL_LIN                   3U
#define COMM_NUM_OF_CHANNELS               4U

/*! @brief Number of bytes used to represent all users in bit for user to single channel mapping*/
#define COMM_NUM_OF_USERS_TO_CHANNEL_MAP_BYTES      ((COMM_NUM_OF_USERS/8U)+1U)
/*! @brief Number of bytes used to represent all channel in bit for channels to single user mapping */
#define COMM_NUM_OF_CHANNELS_TO_USER_MAP_BYTES      ((COMM_NUM_OF_CHANNELS/8U)+1U)
/*! @brief Total number of PNC configuration supported */
#define COMM_NUM_OF_PNC_CONFIGURATION               1U
/*! @brief Total number of PNC Com Signal configuration supported */
#define COMM_NUM_OF_PNC_COM_SIGNAL_CONFIGURATION    2U
/*! @brief Number of bytes used to represent all users in bit for user to PNC mapping*/
#define COMM_NUM_OF_USERS_TO_PNC_MAP_BYTES          ((COMM_NUM_OF_USERS/8U)+1U)
/*! @brief Number of bytes used to represent all channels in bit for channels to PNC mapping*/
#define COMM_NUM_OF_CHANNELS_TO_PNC_MAP_BYTES       ((COMM_NUM_OF_CHANNELS/8U)+1U)

/*! @brief  This type contains the implementation-specific post build configuration structure . 
    Dummy config is used as post build not supported.*/
typedef struct
{
    uint8 Dummy;
}ComM_ConfigType;

/* Configuration data types*/
/*! @brief Defines the types for ComM channel configuration index */
typedef uint8 ComM_ChannelIdType;
/*! @brief Defines the types for ComM User configuration index */
typedef uint8 ComM_UserIdType;

/*! @brief ComM state machine is in "No Communication" mode. Configured channel shall have no transmission or reception 
    capability.*/
#define COMM_NO_COMMUNICATION       0U 
/*! @brief ComM state machine is in "Silent Communication" mode. Configured channel shall have only reception 
    capability, no transmission capability. */
#define COMM_SILENT_COMMUNICATION   1U 
/*! @brief ComM state machine is in "Full Communication" mode. Configured channel shall have both transmission and 
    reception capability. */
#define COMM_FULL_COMMUNICATION     2U 

#ifndef _RTE_TYPE_H
/*! @brief Current mode of the Communication Manager.*/
typedef uint8 ComM_ModeType;
/*! @brief Handle to identify a user.*/
typedef uint8 ComM_UserHandleType;
#endif

#if(COMM_PNC_SUPPORT == STD_ON)
/*! @brief Defines the types for ComM PNC signals configuration index */
typedef uint8 ComM_PncComSignalIdType;
#endif

/*! ComMChannel config type */
/*! @brief The bus type of the channel is CAN.*/
#define COMM_BUS_TYPE_CAN       0U  
/*! @brief The bus type of the channel is a CDD(User defined).*/
#define COMM_BUS_TYPE_CDD       1U  
/*! @brief The bus type of the channel is Ethernet.*/
#define COMM_BUS_TYPE_ETH       2U  
/*! @brief The bus type of the channel is FlexRay.*/
#define COMM_BUS_TYPE_FR        3U  
/*! @brief The bus type of the channel is Internal Bus type.*/
#define COMM_BUS_TYPE_INTERNAL  4U  
/*! @brief The bus type of the channel is LIN.*/
#define COMM_BUS_TYPE_LIN       5U  
/*! @brief Identifies the bus type of the channel.*/
typedef uint8 ComM_BusType;

/*! PNC gateway type is active  */
#define COMM_PNC_GATEWAY_TYPE_ACTIVE    0U  
/*! PNC gateway type is passive */
#define COMM_PNC_GATEWAY_TYPE_PASSIVE   1U  
/*! @brief Identifies the Partial Network Gateway behavior of a ComMChannel. */
typedef uint8 ComM_PncGatewayType;

/*! @brief AUTOSAR NM available (default). */
#define COMM_NM_VARIANT_TYPE_FULL       0U  
/*! @brief No AUTOSAR NM available but functionality to shut down a channel */
#define COMM_NM_VARIANT_TYPE_LIGHT      1U  
/*! @brief No NM available */
#define COMM_NM_VARIANT_TYPE_NONE       2U  
/*! @brief AUTOSAR NM running in passive mode available. */
#define COMM_NM_VARIANT_TYPE_PASSIVE    3U  
/*! @brief Defines the functionality of the network management */
typedef uint8 ComM_NmVariantType;

/*! @brief Type for mapping users to channel . Each user is represented as a bit mask */
typedef uint8 ComM_UsersToChannelMapType[COMM_NUM_OF_USERS_TO_CHANNEL_MAP_BYTES];

/*! @brief Type for the mapping channels to users.Each channel is represented as a bit mask */
typedef uint8 ComM_ChannelsToUserMapType[COMM_NUM_OF_CHANNELS_TO_USER_MAP_BYTES];

/*! @brief Defines the configuration (parameters) of the bus channel(s) */
typedef struct
{
    /*!@brief Identifies the bus type of the channel.*/
    ComM_BusType                    BusType;
    /*! @brief Defines the functionality of the network management */
    ComM_NmVariantType              NmVariantType;
    /*! @brief Defines if the optional SenderReceiver Port of Interface ComM_CurrentChannelRequest will be provided 
        for this channel.True means enabled. False means disabled */
    boolean                         FullCommRequestNotificationEnabled;
    /*! @brief Defines whether the change state of ComM channel is allowed to COMM_SILENT_COMMUNICATION or 
        COMM_FULL_COMMUNICATION.
        true: Enabled - Not allowed to switch to Communication Modes above. 
        false: Disabled - Allowed to switch Communication Modes above*/
    boolean                         NoCom;
    /*! @brief If this parameter is set to "true", the NoWakeUp inhibition state of the channel shall be stored
               in the block pointed to by ComMGlobalNvmBlockDescriptor. */
    boolean                         NoWakeUpInhibitionNvmStorage;
    /*! @brief Defines if an ECU is not allowed to wake-up the channel.
        true: Enabled (not allowed to wake-up)) false: Disabled */
    boolean                         NoWakeup;
    /*! @brief If this parameter equals true then every time a FULL Communication is requested due to a change 
        in the PNC state machine to PNC_REQUESTED Nm shall be called using the API Nm_NetworkRequest. */
    boolean                         PncNmRequest;
    /*! @brief Defines the index of the ComM_BusSMComMModeFunctionConfig table for getting BUS SM functions */
    uint8                           BusSMFnConfigId;
    /*! @brief This value specifies the time duration spent in the COMM_SILENT_COMMUNICATION state after leaving 
    COMM_FULL_COM_READY_SLEEP state and before entering COMM_NO_COMMUNICATION state */
    uint32                          NmLightSilentTimeout;
    /*! @brief Defines the timeout (in Milliseconds) after COMM_FULL_COMMUNICATION sub-state COMM_FULL_COM_READY_SLEEP 
        is left. The range shall be greater than 0 and less or equal to 255 Seconds. */
    uint32                          NmLightTimeout;
    /*! @brief This value specifies the minimum time duration, spent in the COMM_FULL_COMMUNICATION sub-state 
        COMM_FULL_COM_NETWORK_REQUESTED.To use this parameter if the corresponding BusNm does not support the 
        Repeat Message Time functionality (e.g. NmOsek).*/
    uint32                          NmFullComTimeout;
    #if(COMM_PNC_GATEWAY_ENABLED == STD_ON)
    /*! @brief Identifies the Partial Network Gateway behavior of a ComMChannel. */
    ComM_PncGatewayType             PncGatewayType;
    #endif
    /*! @brief Defines the users to channel mapping for this channel Id. */
    ComM_UsersToChannelMapType      UsersToChannelMap;
}ComM_ChannelConfigType;

#if (STD_ON == COMM_USER_MODE_NOTIFICATION_SUPPORT )
/*! @Brief Defines the function type for ComM state change for the user 
*   @param[in] uint8 New ComMMode  
*              - COMM_NO_COMMUNICATION : channel shall stop both transmission and reception capability
*              - COMM_SILENT_COMMUNICATION : channel shall have only reception capability and stop both transmission
*              - COMM_FULL_COMMUNICATION : channel shall have both transmission and reception capability
*/
typedef void (*UserNotificationFnType)(uint8);
#endif

/*! @brief Defines the configuration type for the ComM users */
typedef struct
{
    /*! Defines the channels to user map configuration */
    ComM_ChannelsToUserMapType ChannelsToUserMap;
    #if (STD_ON == COMM_USER_MODE_NOTIFICATION_SUPPORT )
    /*! Defines the function for the user notification*/
    UserNotificationFnType UserNotificationFn;
    #endif
}ComM_UserConfigType;

/*! @brief Defines the type for the Bus SM get current Com mode function.
*   @param[in] NetworkHandleType network handle for which the mode is requested.
*              - COMM_NO_COMMUNICATION : channel shall stop both transmission and reception capability
*              - COMM_SILENT_COMMUNICATION : channel shall have only reception capability and stop both transmission
*              - COMM_FULL_COMMUNICATION : channel shall have both transmission and reception capability
*   @param[out] ComM_ModeType current ComM type of this network.
*   @return status of the request.
*           -E_OK Request accepted
*           -E_NOT_OK Request not accepted
*/
typedef Std_ReturnType (*ComM_BusSMGetCurrentComModeFnType)(NetworkHandleType, ComM_ModeType*);
/*! @brief Defines the type for the Bus SM get current Com mode function.
*   @param[in] NetworkHandleType network handle for which the mode is requested.
*               - COMM_NO_COMMUNICATION : channel shall stop both transmission and reception capability
*               - COMM_SILENT_COMMUNICATION : channel shall have only reception capability and stop both transmission
*               - COMM_FULL_COMMUNICATION : channel shall have both transmission and reception capability
*   @param[in] ComM_ModeType current ComM type of this network.
*   @return status of the request.
*           -E_OK Request accepted
*           -E_NOT_OK Request not accepted
*/
typedef Std_ReturnType (*CanSM_RequestComModeFnType)(NetworkHandleType,ComM_ModeType);

/*! @brief Defines the configuration type for the function list for the BusSM */
typedef struct
{
    /*! @brief Defines the function for getting the current Com Mode */
    ComM_BusSMGetCurrentComModeFnType   BusSMGetCurrentComModeFn;
    /*! @brief Defines the function for requesting the new BusSM mode*/
    CanSM_RequestComModeFnType          CanSM_RequestComModeFn;
}ComM_BusSMComMModeFnConfigType;

#if(COMM_PNC_SUPPORT == STD_ON)
/*! @brief Defines the types for Users to PNC mapping .Each Bit represent the users.*/
typedef uint8 ComM_UsersToPncMapType[COMM_NUM_OF_USERS_TO_PNC_MAP_BYTES];
/*! @brief Defines the types for ComMChannels to channel mapping .Each Bit represent the ComMChannels.*/
typedef uint8 ComM_ChannelsToPncMapType[COMM_NUM_OF_CHANNELS_TO_PNC_MAP_BYTES];

/*! @brief Defines the configuration of the partial network cluster (PNC) */
typedef struct
{
    /*!@brief Defines the Users to PNC mapping for this PNC */
    ComM_UsersToPncMapType      UsersToPncMap; 
    /*!@brief Defines the ComMChannels to PNC mapping for this PNC */
    ComM_ChannelsToPncMapType   ChannelsToPncMap; 
    /*!@brief Defines the PncComSignals configuration start index*/
    ComM_PncComSignalIdType     ComM_PncComSignalIdStart; 
    /*!@brief Defines the PncComSignals configuration end index*/
    ComM_PncComSignalIdType     ComM_PncComSignalIdEnd; 
}ComM_PncConfigType;


/*! @brief Defines the PncComSignals direction type as transmit */
#define COMM_PNC_COM_SIGNAL_DIRECTION_TYPE_TX   0U
/*! @brief Defines the PncComSignals direction type as receive */
#define COMM_PNC_COM_SIGNAL_DIRECTION_TYPE_RX   1U
/*! @brief Defines the PncComSignals direction type*/
typedef uint8 ComM_PncComSignalDirectionType;

/*! @brief Defines the PncComSignals type as EIRA . Applicable for Rx signal */
#define COMM_PNC_COM_SIGNAL_TYPE_EIRA   0U
/*! @brief Defines the PncComSignals type as ERA . Applicable for Rx signal*/
#define COMM_PNC_COM_SIGNAL_TYPE_ERA    1U
/*! @brief Defines the PncComSignals type as None . Applicable for Tx signal*/
#define COMM_PNC_COM_SIGNAL_TYPE_NONE   2U
/*! @brief Indicates whether this PncComSignal represents EIRA or ERA PNC information.
This parameter ComMPncComSignalKind is optional and shall be ignored when ComMPncComSignalDirection equals TX. */
typedef uint8 ComM_PncComSignalType;

/*! @brief Defines the configuration of the PncComSignals */
typedef struct
{
    /*! @brief Defines the PncComSignals direction type*/
    ComM_PncComSignalDirectionType PncComSignalDirectionType; 
    /*! @brief Indicates whether this PncComSignal represents EIRA or ERA PNC information.*/
    ComM_PncComSignalType          PncComSignalType;  
    /*! @brief  Reference to the ComMChannel which is used to determine whether this PncComSignal shall participate 
        in the active or passive role (via the parameter ComMPncGatewayType of the ComMChannel). */
    ComM_ChannelIdType             PncComSignalChanneId;
    /*! @brief Reference to the ComSignal which is used to transport the partial network channel request information.*/
    Com_SignalIdType               PncComSignalId;
}ComM_PncComSignalConfigType;
#endif

/*! @brief pointer to the ComM configuration used in ComM_Init . No PB config , hence the value is NULL_PTR  */
extern const ComM_ConfigType* ComM_ConfigPtr;
/*! @brief Defines the ComM Network configuration. */
extern const ComM_ChannelConfigType ComM_ChannelConfig[COMM_NUM_OF_CHANNELS];
/*! @brief Defines the ComM Network user configuration. */
extern const ComM_UserConfigType ComM_UserConfig[COMM_NUM_OF_USERS];
extern const ComM_BusSMComMModeFnConfigType ComM_BusSMComMModeFnConfig[COMM_NUM_OF_SUPPORTED_BUS];

#if(COMM_PNC_SUPPORT == STD_ON)
/*! @brief Defines the ComM Network PNC configuration. */
extern const ComM_PncComSignalConfigType ComM_PncComSignalConfig[COMM_NUM_OF_PNC_COM_SIGNAL_CONFIGURATION];
/*! @brief Defines the ComM Network PNC signal configuration. */
extern const ComM_PncConfigType ComM_PncConfig[COMM_NUM_OF_PNC_CONFIGURATION];
#endif


/*! @brief Main function for Channel 0 */
extern void ComM_MainFunction_0(void);

/*! @brief Main function for Channel 1 */
extern void ComM_MainFunction_1(void);

/*! @brief Main function for Channel 2 */
extern void ComM_MainFunction_2(void);

/*! @brief Main function for Channel 3 */
extern void ComM_MainFunction_3(void);


#endif /* COMM_CFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


