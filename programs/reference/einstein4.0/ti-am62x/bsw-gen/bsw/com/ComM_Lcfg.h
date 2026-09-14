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
*    @file ComM_Lcfg.h
*    @ingroup ComMConfiguration
*    @brief This is ComM link time configuration header file. It contains definitions of link time
*    configuration parameters for the ComM module.
*    @defgroup PduRConfiguration
*    @brief This contains the link time configurations for the ComM module.
********************************************************************************************************************/
#ifndef COMM_LCFG_H
#define COMM_LCFG_H
/********************************************************************************************************************
* #! GLOBAL VARIABLES                                                                                               *
********************************************************************************************************************/
#define COMM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "MemMap.h"

/*! @brief It contains the status of Full Com request by DCM */
extern VAR(boolean,COMM_VAR_NOINIT) ComM_DcmFullComRequest[COMM_NUM_OF_CHANNELS];
/*! @brief It contains the Communication Allowed status of the channels*/
extern VAR(boolean,COMM_VAR_NOINIT) ComM_CommunicationAllowedStatus[COMM_NUM_OF_CHANNELS];
/*! @brief It contains the wakeup indication request for each channel */
extern VAR(boolean,COMM_VAR_NOINIT) ComM_EcuMWakeupIndicationStatus[COMM_NUM_OF_CHANNELS];

#if (STD_ON == COMM_USER_MODE_NOTIFICATION_SUPPORT )
/*! @brief It contains the Bus SM mode change indication request for each channel */
extern VAR(boolean,COMM_VAR_NOINIT) ComM_IsBusSmModeChanged[COMM_NUM_OF_CHANNELS];
#endif

#if (STD_ON == COMM_PNC_SUPPORT)
/*! @brief It contains the PNC wakeup indication request for each channel */
extern VAR(boolean,COMM_VAR_NOINIT) ComM_EcuMPncWakeupIndicationStatus[COMM_NUM_OF_PNC];
/*! @brief It contains the status EIRA fo each PNC */
extern VAR(boolean,COMM_VAR_NOINIT) ComM_PncEiraRequestStatus[COMM_NUM_OF_PNC];
#endif

#define COMM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_VAR_NO_INIT_8
#include "MemMap.h"

#if (STD_ON == COMM_PNC_SUPPORT)
extern VAR(uint8,COMM_VAR_NOINIT) ComM_PncComSignalBuffer[COMM_NUM_OF_PNC_COM_SIGNAL_BUFFER];
#endif

#define COMM_STOP_SEC_VAR_NO_INIT_8
#include "MemMap.h"

#define COMM_START_SEC_VAR_NO_INIT_32
#include "MemMap.h"

/*! @brief It is used for the Full com minimum timeout and Ready sleep Light timeout*/
extern VAR(uint32,COMM_VAR_NOINIT) ComM_Timer[COMM_NUM_OF_CHANNELS];

#if (STD_ON == COMM_PNC_SUPPORT)
extern VAR(uint32,COMM_VAR_NOINIT) ComM_PncPrepareSleepTimer[COMM_NUM_OF_PNC];
#endif

#define COMM_STOP_SEC_VAR_NO_INIT_32
#include "MemMap.h"

#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/*! @brief It contains the Requested ComM Mode by Users */
extern VAR(ComM_ModeType,COMM_VAR_NOINIT) ComM_UserRequestedMode[COMM_NUM_OF_USERS];
/*! @brief It contains the requested Mode  of the channels*/
extern VAR(ComM_ModeType,COMM_VAR_NOINIT) ComM_ChannelUserRequestedMode[COMM_NUM_OF_CHANNELS];
/*! @brief It contains the BusSM Mode of the channels*/
extern VAR(ComM_ModeType,COMM_VAR_NOINIT) ComM_BusSmMode[COMM_NUM_OF_CHANNELS];
/*! @brief It contains the Requested ComM Mode by Bus NM*/
extern VAR(ComM_StateType,COMM_VAR_NOINIT) ComM_BusNmRequestedState[COMM_NUM_OF_CHANNELS];
/*! @brief It contains the requested Bus mode for each channel */
extern VAR(ComM_StateType,COMM_VAR_NOINIT) ComM_BusComModeReq[COMM_NUM_OF_CHANNELS];
/*! @brief It contains the active ComM Mode of the channels*/
extern VAR(ComM_StateType,COMM_VAR_NOINIT) ComM_CurrentState[COMM_NUM_OF_CHANNELS];
/*! @brief It is used to store the inhibition status */
extern VAR(ComM_InhibitionType,COMM_VAR_NOINIT) ComM_Inhibition;

#if (STD_ON == COMM_USER_MODE_NOTIFICATION_SUPPORT )
/*! @brief It contains the old ComM Mode set by the BusSM for the user */
extern VAR(ComM_ModeType,COMM_VAR_NOINIT) ComM_OldBusSmMode[COMM_NUM_OF_USERS];
#endif

#if (STD_ON == COMM_PNC_SUPPORT)
/*! @brief It contains the current PNC mode */
extern VAR(ComM_PncModeType,COMM_VAR_NOINIT) ComM_PncCurrentMode[COMM_NUM_OF_PNC];
/*! @brief It defines the Prepare sleep timer for each PNC */
/*! @brief It contains the PNC Bus requested mode for each PNC */
extern VAR(ComM_PncModeType,COMM_VAR_NOINIT) ComM_PncBusRequestedMode[COMM_NUM_OF_PNC];
/*! @brief It contains the User notified old state for each Users */
extern VAR(ComM_ModeType,COMM_VAR_NOINIT) ComM_PncUserOldState[COMM_NUM_OF_USERS];
/*! @brief It contains the User request for each PNC */
extern VAR(ComM_ModeType,COMM_VAR_NOINIT) ComM_PncUserRequestComMode[COMM_NUM_OF_USERS];
/*! @brief It is the Com signal buffer used for the Eira and Era signals */
#endif

#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/********************************************************************************************************************
* #! ComM const config  data                                                                                        *
********************************************************************************************************************/
#define COMM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/*! @brief pointer to the ComM configuration used in ComM_Init . No PB config , hence the value is NULL_PTR  */
extern P2CONST(ComM_ConfigType,AUTOMATIC,COMM_CONFIG_DATA) ComM_ConfigPtr;
/*! @brief Defines the ComM Network configuration. 
    Elements                : Description
    BusType                 : Identifies the bus type of the channel.
    NmVariantType           : Defines the functionality of the network management 
    FullCommRequestNotificationEnabled : Defines if the optional SenderReceiver Port of Interface 
                              ComM_CurrentChannelRequest will be provided for this channel
                              Enabled if COM_FULL_COMM_REQUEST_NOTIFICATION_ENABLED is STD_ON
    NoCom                   : Defines whether the change state of ComM channel is allowed to 
                              COMM_SILENT_COMMUNICATION or COMM_FULL_COMMUNICATION .
    NoWakeUpInhibitionNvmStorage : to save  NoWakeUp inhibition state in the NVM
                              Enabled if COMM_NVM_SUPPORT is STD_ON
    NoWakeup                : Defines if an ECU is not allowed to wake-up the channel
    BusSMFnConfigId         : the ComM_BusSMComMModeFunctionConfig table for getting BUS SM functions
    NmLightTimeout          : the timeout (in Milliseconds) after COMM_FULL_COMMUNICATION sub-state 
                              COMM_FULL_COM_READY_SLEEP is left
    NmFullComTimeout        : the minimum time duration, spent in the COMM_FULL_COMMUNICATION sub-state 
                              COMM_FULL_COM_NETWORK_REQUESTED
    PncGatewayType          : the Partial Network Gateway behavior of a ComMChannel. 
                              Enabled if COMM_PNC_GATEWAY_ENABLED and COMM_PNC_SUPPORT is STD_ON
    PncNmRequest            : the PNC state machine to PNC_REQUESTED Nm shall be called using the API Nm_NetworkRequest.
                              Enabled if COMM_PNC_SUPPORT is STD_ON
    PncStartId              : the pnc config start Id.
                              Enabled if COMM_PNC_SUPPORT is STD_ON
    PncEndId                : the pnc config end Id.
                              Enabled if COMM_PNC_SUPPORT is STD_ON
    UsersToChannelMap       : the users to channel mapping for this channel Id.
                              Enabled if COMM_PNC_SUPPORT is STD_ON
*/
extern CONST(ComM_ChannelConfigType,COMM_CONFIG_DATA) ComM_ChannelConfig[COMM_NUM_OF_CHANNELS];
/*! @brief Defines the ComM Network user configuration. 
    Elements                : Description
    ChannelsToUserMap       : the channels to user map configuration
    UserNotificationFn      : the function for the user notification
                              Enabled if COMM_USER_MODE_NOTIFICATION_SUPPORT is STD_ON
    PncStartId              : the pnc config start Id
                              Enabled if COMM_PNC_SUPPORT is STD_ON
    PncEndId                : the pnc config end Id.
                              Enabled if COMM_PNC_SUPPORT is STD_ON
*/
extern CONST(ComM_UserConfigType,COMM_CONFIG_DATA) ComM_UserConfig[COMM_NUM_OF_USERS];
/*! @brief Defines the BusSM function configuration. 
    Elements                    : Description
    BusSMGetCurrentComModeFn    : the function for getting the current Com Mode of Bus SM
    CanSM_RequestComModeFn      : the function for requesting the new BusSM mode
*/
extern CONST(ComM_BusSMComMModeFnConfigType,COMM_CONFIG_DATA) ComM_BusSMComMModeFnConfig[COMM_NUM_OF_SUPPORTED_BUS];

#if(COMM_PNC_SUPPORT == STD_ON)
/*! @brief Defines the ComM Network PNC configuration. 
    Elements                : Description
    PncHandle               : the PNC Handle value of the PNC
    PncByteOffset           : the PNC User Byte Offset
    PncBitMask              : the PNC User Bit Mask
    PncUserStartId          : the start of user Id mapped to this PNC
    PncUserEndId            : the end of user Id mapped to this PNC
    PncChannelStartId       : the start of user Id mapped to this PNC
    PncChannelEndId         : the start of user Id mapped to this PNC
    PncComSignalStartId     : the PncComSignals configuration start index
    PncComSignalEndId       : the PncComSignals configuration end index
*/
extern CONST(ComM_PncConfigType,COMM_CONFIG_DATA) ComM_PncConfig[COMM_NUM_OF_PNC];
/*! @brief Defines the ComM PNC Id to User mapping configuration */
extern CONST(ComM_UserHandleType,COMM_CONFIG_DATA) ComM_PncToUserMapConfig[COMM_NUM_OF_PNC_TO_USER_MAP];
/*! @brief Defines the ComM PNC Id to Channel mapping configuration */
extern CONST(ComM_ChannelIdType,COMM_CONFIG_DATA) ComM_PncToChannelMapConfig[COMM_NUM_OF_PNC_TO_CHANNEL_MAP];
/*! @brief Defines the ComM Network PNC signal configuration. 
    Elements                    : Description
    PncComSignalDirectionType   : the PncComSignals direction type
    PncComSignalType            : Indicates whether this PncComSignal represents EIRA or ERA PNC information.
    PncComSignalChanneId        : Reference to the ComMChannel whose PncComSignal participate in active or passive role
    PncComSignalId              : Reference to the ComSignal which used to tx the PN request information.
    PncComSignalBufferStartId   : the Buffer start Id of the ComM PNC signal buffer
*/
extern CONST(ComM_PncComSignalConfigType,COMM_CONFIG_DATA) ComM_PncComSignalConfig[COMM_NUM_OF_PNC_COM_SIGNAL];
#endif

#define COMM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#endif /* COMM_LCFG_H */

/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/
