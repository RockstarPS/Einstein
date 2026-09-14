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
*    @ingroup ComMConfiguration
*    @brief This is ComM Pre-compile time configuration header file. It contains definitions of pre-compile time 
*    configuration parameters for the ComM module.
*    @defgroup ComMConfiguration
*    @brief This contains the configuration files for the COMM module.
********************************************************************************************************************/
#ifndef COMM_CFG_H
#define COMM_CFG_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "Rte_ComM_Type.h"
#include "ComM_Types.h"
#include "Com.h" /* Include only if PNC signal support is required */

#define COMM_CHANNEL_VCAN 0
#define COMM_CHANNEL_MCAN 0
/********************************************************************************************************************
*  #! Precompile Configuration                                                                                      *
********************************************************************************************************************/
/*! @brief This parameter avoids sending of 0-PNC-Vectors in case ComMPncGatewayEnabled is enabled.
 * 	dependency: ComMPncGatewayEnabled is enabled */
#define COMM_0_PNC_VECTOR_AVOIDANCE					STD_OFF
/*! @brief Switches the Default Error Tracer (Det) detection and notification ON or OFF.*/
#define COMM_DEV_ERROR_DETECT                       STD_ON
/*! @brief Enables/Disables the COMM limitation functionality */
#define COMM_MODE_LIMITATION_ENABLED                STD_OFF
/*! @brief Enables/Disables support of Partial Network Gateway */
#define COMM_PNC_GATEWAY_ENABLED                    STD_OFF
/*! @brief Enables/Disables support of partial networking */
#define COMM_PNC_SUPPORT                            STD_OFF
/*! @brief ComM shall perform a reset after entering "No Communication" mode because of an
 * active mode limitation to "No Communication" mode. Enables/Disables this feature */
#define COMM_RESET_AFTER_FORCING_NO_COMM            STD_OFF
/*! @brief Wake up of one channel shall lead to a wake up of all channels if true.
 *  Enables/Disables this feature*/
#define COMM_SYNCHRONOUS_WAKEUP                     STD_OFF
/*! @brief Switches the possibility to read the published information with the service
 * ComM_GetPublishedInformation().Enables/Disables this feature*/
#define COMM_VERSION_INFO_API                       STD_ON
/*! @brief Enables/Disables wake up inhibition functionality */
#define COMM_WAKEUP_INHIBITION_ENABLED              STD_OFF
/*! @brief Defines whether a mode inhibition affects the ECU or not.
 * 000: No mode inhibition can be activated 001: Wake up inhibition can be enabled
 * Default: 3
 * dependency: Shall be stored non volatile (value must be kept during a reset) at
 * least if Wake up inhibition is enabled/allowed. Can be changed during runtime with
 * ComM_SetECUGroupClassification() thus the default values shall be set only
 * once (first ECU initialization).*/
#define COMM_ECU_GROUP_CLASSIFICATION               0x00U
/*! @brief Time in seconds the PNC state machine shall wait in PNC_PREPARE_SLEEP. */
#define COMM_PNC_PREPARE_SLEEP_TIMER                0x0U
/*! @brief Minimum time duration in milliseconds, spent in the COMM_FULL_COMMUNICATION sub-state
    COMM_FULL_COM_NETWORK_REQUESTED. Time/Periodicity. \ref NmFullComTimeout*/
#define COMM_TMIN_FULL_COM_MODE_DURATION            500U
/*! @brief Reference to NVRAM block containing the none volatile data. If this
 *  parameter is not configured it means that no NVRam is used at all. */
#define COMM_GLOBAL_NVM_BLOCK_DESCRIPTOR			0x00
/********************************************************************************************************************
*  #! ComM Internal feature support                                                                                 *
********************************************************************************************************************/
/*! @brief Enables/Disables support of Passive Mode . Enabled if any of the ComM channel support passive mode */
#define COMM_NM_PASSIVE_MODE_ENABLE                 STD_OFF
/*! @brief Enables/Disables the User mode notification support.Enabled if any of the ComM channel supports user mode 
    notification  */
#define COMM_USER_MODE_NOTIFICATION_SUPPORT         STD_ON

/*! @brief Enables/Disables the DCM mode notification support. Enabled if any of the ComM channel supports 
    notification to DCM  */
#define COMM_DCM_MODE_INDICATION_SUPPORT            STD_ON
/*! @brief Enables/Disables the NM module support. Enabled if any of the ComM channel supports Nm */
#define COMM_NM_MODULE_USED                         STD_ON
/*! @brief Enables/Disables the support of EIRA Tx signal */
#define COMM_EIRA_TX_TYPE_OF_PNC_SIGNAL	            STD_OFF
/*! @brief Enables/Disables the NVM support. Enabled if Reference to NVRAM block is provided to store the Inhibition 
    values */
#define COMM_NVM_SUPPORT                            STD_OFF
/*! @brief Enables/Disables the  optional SenderReceiver Port of Interface ComM_CurrentChannelRequest for a channel.
    Enabled if any channel support this feature */
#define COM_FULL_COMM_REQUEST_NOTIFICATION_ENABLED  STD_OFF

/********************************************************************************************************************
*  #! SW and AUTOSAR Version Macros                                                                                 *
********************************************************************************************************************/
/*! @brief Defines the ComM configuration software Major version */
#define COMM_CFG_SW_MAJOR_VERSION                   1U
/*! @brief Defines the ComM configuration software Minor version */
#define COMM_CFG_SW_MINOR_VERSION                   0U
/*! @brief Defines the ComM configuration software Patch version */
#define COMM_CFG_SW_PATCH_VERSION                   0U
/* Autosar Release */
/*! @brief Defines the AUTOSAR Release Major version supported by ComM configuration  */
#define COMM_CFG_AR_RELEASE_MAJOR_VERSION           4U
/*! @brief Defines the AUTOSAR Release Minor version supported by ComM configuration  */
#define COMM_CFG_AR_RELEASE_MINOR_VERSION           3U
/*! @brief Defines the AUTOSAR Release Patch version supported by ComM configuration  */
#define COMM_CFG_AR_RELEASE_REVISION_VERSION        1U
/*! @brief Defines the number of Bus supported by ComM */
/*******************************************************************************************************************
*  #! ComM module configuration                                                                                    *
*******************************************************************************************************************/
/*! @brief Defines the number of supported com bus */
#define COMM_NUM_OF_SUPPORTED_BUS                   2U
/*! @brief ID for the User 1 */
#define COMM_USER_CAN_USER_ID1                      0U
/*! @brief ID for the User 2 */
#define COMM_USER_CAN_USER_ID2                      1U
/*! @brief ID for the User 3 */
#define COMM_USER_ETH_USER_ID                       2U
/*! @brief Total number of users supported */
#define COMM_NUM_OF_USERS                           3U
/*! @brief ID for the network channel 1 */
#define COMM_CAN_CHANNEL_ID1                            0U
/*! @brief ID for the network channel 2 */
#define COMM_CAN_CHANNEL_ID2                            1U
/*! @brief ID for the network channel 2 */
#define COMM_ETH_CHANNEL_ID3                            2U
/*! @brief Total number of channels supported */
#define COMM_NUM_OF_CHANNELS                        3U
/*! @brief Number of bytes used to represent all users in bit for user to single channel mapping*/
#define COMM_NUM_OF_USERS_TO_CHANNEL_MAP_BYTES      ((COMM_NUM_OF_USERS/8U)+1U)
/*! @brief Number of bytes used to represent all channel in bit for channels to single user mapping */
#define COMM_NUM_OF_CHANNELS_TO_USER_MAP_BYTES      ((COMM_NUM_OF_CHANNELS/8U)+1U)
/*! Specifies the period in seconds that the MainFunction has to be triggered with. */
#define COMM_MAIN_FUNCTION_PERIOD                   10U

#if (STD_ON == COMM_PNC_SUPPORT)
/*! @brief Total number of PNC configuration supported */
#define COMM_NUM_OF_PNC               				1U
/*! @brief Total number of PNC Com Signal configuration supported */
#define COMM_NUM_OF_PNC_COM_SIGNAL    				2U
/*! @brief Defines the size of Pnc to user config */
#define COMM_NUM_OF_PNC_TO_USER_MAP                 1U
/*! @brief Defines the size of Pnc to channel config */
#define COMM_NUM_OF_PNC_TO_CHANNEL_MAP              1U
/*! @brief Defines the size of Pnc to com signal config */
#define COMM_NUM_OF_PNC_TO_COM_SIGNAL_MAP	        1U
/*! @brief Defines the size of Pnc to com signal buffer config */
#define COMM_NUM_OF_PNC_COM_SIGNAL_BUFFER	        2U
/*! @brief Number of bytes used to represent all users in bit for user to PNC mapping*/
#define COMM_NUM_OF_USERS_TO_PNC_MAP_BYTES          ((COMM_NUM_OF_USERS/8U)+1U)
/*! @brief Number of bytes used to represent all channels in bit for channels to PNC mapping*/
#define COMM_NUM_OF_CHANNELS_TO_PNC_MAP_BYTES       ((COMM_NUM_OF_CHANNELS/8U)+1U)
#endif

/********************************************************************************************************************
* #! ComM types                                                                                                     *
* #! macro , typedef declaration                                                                                    *
********************************************************************************************************************/
/* if the ComM_Mode values not defined in Rte_ComM_Type */
#ifndef COMM_NO_COMMUNICATION  
/*! @brief ComM state machine is in "No Communication" mode. Configured channel shall have no transmission or reception 
    capability.*/
#define COMM_NO_COMMUNICATION           0U 
#endif 
#ifndef COMM_SILENT_COMMUNICATION 
/*! @brief ComM state machine is in "Silent Communication" mode. Configured channel shall have only reception 
    capability, no transmission capability. */
#define COMM_SILENT_COMMUNICATION       1U 
#endif 
#ifndef COMM_FULL_COMMUNICATION 
/*! @brief ComM state machine is in "Full Communication" mode. Configured channel shall have both transmission and 
    reception capability. */
#define COMM_FULL_COMMUNICATION         2U 
#endif 

#ifndef RTE_E_OK
#define RTE_E_OK 0
#endif

/*! @brief The bus type of the channel is CAN.*/
#define COMM_BUS_TYPE_CAN               0U  
/*! @brief The bus type of the channel is a CDD(User defined).*/
#define COMM_BUS_TYPE_CDD               1U  
/*! @brief The bus type of the channel is Ethernet.*/
#define COMM_BUS_TYPE_ETH               2U  
/*! @brief The bus type of the channel is FlexRay.*/
#define COMM_BUS_TYPE_FR                3U  
/*! @brief The bus type of the channel is Internal Bus type.*/
#define COMM_BUS_TYPE_INTERNAL          4U  
/*! @brief The bus type of the channel is LIN.*/
#define COMM_BUS_TYPE_LIN               5U  
/*! @brief Identifies the bus type of the channel.*/

/*! @brief AUTOSAR NM available (default). */
#define COMM_NM_VARIANT_TYPE_FULL       0U  
/*! @brief No AUTOSAR NM available but functionality to shut down a channel */
#define COMM_NM_VARIANT_TYPE_LIGHT      1U  
/*! @brief No NM available */
#define COMM_NM_VARIANT_TYPE_NONE       2U  
/*! @brief AUTOSAR NM running in passive mode available. */
#define COMM_NM_VARIANT_TYPE_PASSIVE    3U 

#if (STD_ON == COMM_PNC_SUPPORT)
/*! PNC gateway type is active  */
#define COMM_PNC_GATEWAY_TYPE_ACTIVE    0U  
/*! PNC gateway type is passive */
#define COMM_PNC_GATEWAY_TYPE_PASSIVE   1U  

/*! @brief Defines the PncComSignals direction type as transmit */
#define COMM_PNC_COM_SIGNAL_DIRECTION_TYPE_TX   0U
/*! @brief Defines the PncComSignals direction type as receive */
#define COMM_PNC_COM_SIGNAL_DIRECTION_TYPE_RX   1U
/*! @brief Defines the PncComSignals type as EIRA . Applicable for Rx signal */
#define COMM_PNC_COM_SIGNAL_TYPE_EIRA   0U
/*! @brief Defines the PncComSignals type as ERA . Applicable for Rx signal*/
#define COMM_PNC_COM_SIGNAL_TYPE_ERA    1U
#endif

#ifndef Rte_TypeDef_ComM_UserHandleType 
/*! @brief defines the user handle data type */
typedef uint8 ComM_UserHandleType;
#endif
#ifndef Rte_TypeDef_ComM_ModeType 
/*! @brief defines the ComM Mode type  */
typedef uint8 ComM_ModeType;
#endif
/*! @brief Defines the type for ComM channel configuration index */
typedef uint8 ComM_ChannelIdType;
/*! @brief Defines the type for ComM User configuration index */
typedef uint8 ComM_UserIdType;
/*! ComMChannel config type */
typedef uint8 ComM_BusType;
/*! @brief Defines the functionality of the network management */
typedef uint8 ComM_NmVariantType;
/*! @brief Type for mapping users to channel . Each user is represented as a bit mask */
typedef uint8 ComM_UsersToChannelMapType[COMM_NUM_OF_USERS_TO_CHANNEL_MAP_BYTES];
/*! @brief Type for the mapping channels to users.Each channel is represented as a bit mask */
typedef uint8 ComM_ChannelsToUserMapType[COMM_NUM_OF_CHANNELS_TO_USER_MAP_BYTES];
#if (STD_ON == COMM_USER_MODE_NOTIFICATION_SUPPORT )
/*! @Brief Defines the function type for ComM state change for the user 
*   @param[in] ComMMode New ComM Mode  
*              - COMM_NO_COMMUNICATION : channel shall stop both transmission and reception capability
*              - COMM_SILENT_COMMUNICATION : channel shall have only reception capability and stop both transmission
*              - COMM_FULL_COMMUNICATION : channel shall have both transmission and reception capability
*/
typedef P2FUNC(Std_ReturnType,COMM_APPL_CODE,UserNotificationFnType)(uint8 ComMMode);
/*! @brief Defines the type for the Bus SM get current Com mode function.
*   @param[in] Network network handle for which the mode is requested.
*              - COMM_NO_COMMUNICATION : channel shall stop both transmission and reception capability
*              - COMM_SILENT_COMMUNICATION : channel shall have only reception capability and stop both transmission
*              - COMM_FULL_COMMUNICATION : channel shall have both transmission and reception capability
*   @param[out] ComMModePtr current ComM type of this network.
*   @return status of the request.
*           -E_OK Request accepted
*           -E_NOT_OK Request not accepted
*/
typedef P2FUNC(Std_ReturnType,COMM_APPL_CODE,ComM_BusSMGetCurrentComModeFnType)
(
    NetworkHandleType Network,
    P2VAR(ComM_ModeType,AUTOMATIC,COMM_APPL_DATA) ComMModePtr
);
/*! @brief Defines the type for the Bus SM get current Com mode function.
*   @param[in] Network network handle for which the mode is requested.
*               - COMM_NO_COMMUNICATION : channel shall stop both transmission and reception capability
*               - COMM_SILENT_COMMUNICATION : channel shall have only reception capability and stop both transmission
*               - COMM_FULL_COMMUNICATION : channel shall have both transmission and reception capability
*   @param[in] ComMMode current ComM type of this network.
*   @return status of the request.
*           -E_OK Request accepted
*           -E_NOT_OK Request not accepted
*/
typedef P2FUNC(Std_ReturnType,COMM_APPL_CODE,CanSM_RequestComModeFnType)
(
    NetworkHandleType Network,
    ComM_ModeType ComMMode
);
#endif
#if (STD_ON == COMM_PNC_SUPPORT)
/*! @brief Defines the type for ComM PNC id */
typedef uint8 ComM_PncIdType;
/*! @brief Defines the type for ComM PNC to User Map config id */
typedef uint8 ComM_PncToUserMapIdType;
/*! @brief Defines the type for ComM PNC to channel Map config id */
typedef uint8 ComM_PncToChannelMapIdType;
/*! @brief Defines the type for ComM PNC to signal Map config id */
typedef uint8 ComM_PncToComSignalMapIdType;
/*! @brief Identifies the Partial Network Gateway behavior of a ComMChannel. */
typedef uint8 ComM_PncGatewayType;
#if(COMM_PNC_SUPPORT == STD_ON)
/*! @brief Defines the types for ComM PNC signals configuration index */
typedef uint8 ComM_PncComSignalIdType;
#endif
/*! @brief Defines the types for Users to PNC mapping .Each Bit represent the users.*/
typedef uint8 ComM_UsersToPncMapType[COMM_NUM_OF_USERS_TO_PNC_MAP_BYTES];
/*! @brief Defines the types for ComMChannels to channel mapping .Each Bit represent the ComMChannels.*/
typedef uint8 ComM_ChannelsToPncMapType[COMM_NUM_OF_CHANNELS_TO_PNC_MAP_BYTES];
/*! @brief Defines the PncComSignals direction type*/
typedef uint8 ComM_PncComSignalDirectionType;
/*! @brief Indicates whether this PncComSignal represents EIRA or ERA PNC information.
This parameter ComMPncComSignalKind is optional and shall be ignored when ComMPncComSignalDirection equals TX. */
typedef uint8 ComM_PncComSignalType;
/*! @brief Defines the PncComSignals buffer id type*/
typedef uint8 ComM_PncComSignalBufferIdType;
#endif

/*! @brief  This type contains the implementation-specific post build configuration structure . 
    Dummy config is used as post build not supported.*/
typedef struct
{
    uint8 Dummy;
}ComM_ConfigType;

/*! Defines the type for the Inhibition status */
typedef struct
{
    /*! Defines the ECUGroupClassification's Inhibition Status */
    uint16                      InhibitionCount;
    /*! It defines the Inhibition status for the ECU */
    ComM_InhibitionStatusType   EcuInhibitionStatus;
    /*! It defines the Inhibition status for the channels */
    ComM_InhibitionStatusType   ChannelInhibitionStatus[COMM_NUM_OF_CHANNELS];
} ComM_InhibitionType;

/*! @brief Defines the configuration (parameters) of the bus channel(s) */
typedef struct
{
    /*!@brief Identifies the bus type of the channel.*/
    ComM_BusType                    BusType;
    /*! @brief Defines the functionality of the network management */
    ComM_NmVariantType              NmVariantType;
    #if(STD_OFF == COM_FULL_COMM_REQUEST_NOTIFICATION_ENABLED)                        
    /*! @brief Defines if the optional SenderReceiver Port of Interface ComM_CurrentChannelRequest will be provided 
        for this channel.True means enabled. False means disabled . */
    boolean                         FullCommRequestNotificationEnabled;
    #endif
    /*! @brief Defines whether the change state of ComM channel is allowed to COMM_SILENT_COMMUNICATION or 
        COMM_FULL_COMMUNICATION.
        true: Enabled - Not allowed to switch to Communication Modes above. 
        false: Disabled - Allowed to switch Communication Modes above*/
    boolean                         NoCom;
    #if(STD_OFF == COMM_NVM_SUPPORT)                        
    /*! @brief If this parameter is set to "true", the NoWakeUp inhibition state of the channel shall be stored
               in the block pointed to by ComMGlobalNvmBlockDescriptor. */
    boolean                         NoWakeUpInhibitionNvmStorage;
    #endif
    /*! @brief Defines if an ECU is not allowed to wake-up the channel.
        true: Enabled (not allowed to wake-up)) false: Disabled */
    boolean                         NoWakeup;
    /*! @brief Defines the index of the ComM_BusSMComMModeFunctionConfig table for getting BUS SM functions */
    uint8                           BusSMFnConfigId;
    /*! @brief Defines the timeout (in Milliseconds) after COMM_FULL_COMMUNICATION sub-state COMM_FULL_COM_READY_SLEEP 
        is left. The range shall be greater than 0 and less or equal to 255 Seconds. */
    uint32                          NmLightTimeout;
    /*! @brief This value specifies the minimum time duration, spent in the COMM_FULL_COMMUNICATION sub-state 
        COMM_FULL_COM_NETWORK_REQUESTED.To use this parameter if the corresponding BusNm does not support the 
        Repeat Message Time functionality (e.g. NmOsek).*/
    uint32                          NmFullComTimeout;
	#if (STD_ON == COMM_PNC_SUPPORT)
    #if(COMM_PNC_GATEWAY_ENABLED == STD_ON)
    /*! @brief Identifies the Partial Network Gateway behavior of a ComMChannel. */
    ComM_PncGatewayType             PncGatewayType;
    #endif
    /*! @brief If this parameter equals true then every time a FULL Communication is requested due to a change 
        in the PNC state machine to PNC_REQUESTED Nm shall be called using the API Nm_NetworkRequest. */
    boolean                         PncNmRequest;
    /*! @brief Defines the pnc config start Id. */
    ComM_PncIdType	                PncStartId;
    /*! @brief Defines the pnc config end Id. */
    ComM_PncIdType	                PncEndId;
	#endif
    /*! @brief Defines the users to channel mapping for this channel Id. */
    ComM_UsersToChannelMapType      UsersToChannelMap;
}ComM_ChannelConfigType;

/*! @brief Defines the configuration type for the ComM users */
typedef struct
{
    /*! Defines the channels to user map configuration */
    ComM_ChannelsToUserMapType  ChannelsToUserMap;
    #if (STD_ON == COMM_USER_MODE_NOTIFICATION_SUPPORT )
    /*! Defines the function for the user notification */
    UserNotificationFnType      UserNotificationFn;
    #endif
    #if (STD_ON == COMM_PNC_SUPPORT)
    /*! @brief Defines the pnc config start Id. */
    ComM_PncIdType	            PncStartId;
    /*! @brief Defines the pnc config end Id. */
    ComM_PncIdType	            PncEndId;
	#endif
}ComM_UserConfigType;

/*! @brief Defines the configuration type for the function list for the BusSM */
typedef struct
{
    /*! @brief Defines the function for getting the current Com Mode */
    ComM_BusSMGetCurrentComModeFnType   BusSMGetCurrentComModeFn;
    /*! @brief Defines the function for requesting the new BusSM mode*/
    CanSM_RequestComModeFnType          CanSM_RequestComModeFn;
}ComM_BusSMComMModeFnConfigType;

#if(COMM_PNC_SUPPORT == STD_ON)

/*! @brief Defines the configuration of the partial network cluster (PNC) */
typedef struct
{
	/*! @brief Defines the PNC Handle value of the PNC */
	PNCHandleType					PncHandle;
	/*! @brief Defines the PNC User Byte Offset */
	uint8							PncByteOffset;
	/*! @brief Defines the PNC User Bit Mask */
	uint8							PncBitMask;
    /*!@brief Defines the start of user Id mapped to this PNC */
    ComM_PncToUserMapIdType         PncUserStartId;
    /*!@brief Defines the end of user Id mapped to this PNC */
    ComM_PncToUserMapIdType         PncUserEndId;
    /*!@brief Defines the start of user Id mapped to this PNC */
    ComM_PncToChannelMapIdType      PncChannelStartId;
    /*!@brief Defines the start of user Id mapped to this PNC */
    ComM_PncToChannelMapIdType      PncChannelEndId;
    /*!@brief Defines the PncComSignals configuration start index*/
    ComM_PncToComSignalMapIdType    PncComSignalStartId;
    /*!@brief Defines the PncComSignals configuration end index*/
    ComM_PncToComSignalMapIdType    PncComSignalEndId;
}ComM_PncConfigType;

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
    /*! @brief Defines the Buffer start Id of the ComM PNC signal buffer */
    ComM_PncComSignalBufferIdType  PncComSignalBufferStartId;
}ComM_PncComSignalConfigType;
#endif

/* Added declaration of SchM functions to resolve compiler warnings */
extern void ComM_EnterCriticalSection(void);
extern void ComM_ExitCriticalSection(void);

#endif /* COMM_CFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

