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
*    @file ComM_Lcfg.c
*    @ingroup ComMConfiguration
*    @brief This is ComM Link time configuration source file. It contains definitions of Link time configuration
*     parameters for the ComM module.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComM.h"
#include "CanSM.h"
//#include "EthSM.h"
#include "CanSM_ComM.h"
#include "SchM_ComM.h"
/********************************************************************************************************************
* #! GLOBAL VARIABLES                                                                                               *
********************************************************************************************************************/
#define COMM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "MemMap.h"

/*! @brief It contains the status of Full Com request by DCM */
VAR(boolean,COMM_VAR_NOINIT) ComM_DcmFullComRequest[COMM_NUM_OF_CHANNELS];
/*! @brief It contains the Communication Allowed status of the channels*/
VAR(boolean,COMM_VAR_NOINIT) ComM_CommunicationAllowedStatus[COMM_NUM_OF_CHANNELS];
/*! @brief It contains the wakeup indication request for each channel */
VAR(boolean,COMM_VAR_NOINIT) ComM_EcuMWakeupIndicationStatus[COMM_NUM_OF_CHANNELS];

#if (STD_ON == COMM_USER_MODE_NOTIFICATION_SUPPORT )
/*! @brief It contains the Bus SM mode change indication request for each channel */
VAR(boolean,COMM_VAR_NOINIT) ComM_IsBusSmModeChanged[COMM_NUM_OF_CHANNELS];
#endif

#if (STD_ON == COMM_PNC_SUPPORT)
/*! @brief It contains the PNC wakeup indication request for each channel */
VAR(boolean,COMM_VAR_NOINIT) ComM_EcuMPncWakeupIndicationStatus[COMM_NUM_OF_PNC];
/*! @brief It contains the status EIRA fo each PNC */
VAR(boolean,COMM_VAR_NOINIT) ComM_PncEiraRequestStatus[COMM_NUM_OF_PNC];
#endif

#define COMM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_VAR_NO_INIT_8
#include "MemMap.h"

#if (STD_ON == COMM_PNC_SUPPORT)
VAR(uint8,COMM_VAR_NOINIT) ComM_PncComSignalBuffer[COMM_NUM_OF_PNC_COM_SIGNAL_BUFFER];
#endif

#define COMM_STOP_SEC_VAR_NO_INIT_8
#include "MemMap.h"

#define COMM_START_SEC_VAR_NO_INIT_32
#include "MemMap.h"

/*! @brief It is used for the Full com minimum timeout and Ready sleep Light timeout*/
VAR(uint32,COMM_VAR_NOINIT) ComM_Timer[COMM_NUM_OF_CHANNELS];

#if (STD_ON == COMM_PNC_SUPPORT)
VAR(uint32,COMM_VAR_NOINIT) ComM_PncPrepareSleepTimer[COMM_NUM_OF_PNC];
#endif

#define COMM_STOP_SEC_VAR_NO_INIT_32
#include "MemMap.h"

#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/*! @brief It contains the Requested ComM Mode by Users */
VAR(ComM_ModeType,COMM_VAR_NOINIT) ComM_UserRequestedMode[COMM_NUM_OF_USERS];
/*! @brief It contains the requested Mode  of the channels*/
VAR(ComM_ModeType,COMM_VAR_NOINIT) ComM_ChannelUserRequestedMode[COMM_NUM_OF_CHANNELS];
/*! @brief It contains the BusSM Mode of the channels*/
VAR(ComM_ModeType,COMM_VAR_NOINIT) ComM_BusSmMode[COMM_NUM_OF_CHANNELS];
/*! @brief It contains the Requested ComM Mode by Bus NM*/
VAR(ComM_StateType,COMM_VAR_NOINIT) ComM_BusNmRequestedState[COMM_NUM_OF_CHANNELS];
/*! @brief It contains the requested Bus mode for each channel */
VAR(ComM_StateType,COMM_VAR_NOINIT) ComM_BusComModeReq[COMM_NUM_OF_CHANNELS];
/*! @brief It contains the active ComM Mode of the channels*/
VAR(ComM_StateType,COMM_VAR_NOINIT) ComM_CurrentState[COMM_NUM_OF_CHANNELS];
/*! @brief It is used to store the inhibition status */
VAR(ComM_InhibitionType,COMM_VAR_NOINIT) ComM_Inhibition;

#if (STD_ON == COMM_USER_MODE_NOTIFICATION_SUPPORT )
/*! @brief It contains the old ComM Mode set by the BusSM for the user */
VAR(ComM_ModeType,COMM_VAR_NOINIT) ComM_OldBusSmMode[COMM_NUM_OF_USERS];
#endif

#if (STD_ON == COMM_PNC_SUPPORT)
/*! @brief It contains the current PNC mode */
VAR(ComM_PncModeType,COMM_VAR_NOINIT) ComM_PncCurrentMode[COMM_NUM_OF_PNC];
/*! @brief It defines the Prepare sleep timer for each PNC */
/*! @brief It contains the PNC Bus requested mode for each PNC */
VAR(ComM_PncModeType,COMM_VAR_NOINIT) ComM_PncBusRequestedMode[COMM_NUM_OF_PNC];
/*! @brief It contains the User notified old state for each Users */
VAR(ComM_ModeType,COMM_VAR_NOINIT) ComM_PncUserOldState[COMM_NUM_OF_USERS];
/*! @brief It contains the User request for each PNC */
VAR(ComM_ModeType,COMM_VAR_NOINIT) ComM_PncUserRequestComMode[COMM_NUM_OF_USERS];
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
P2CONST(ComM_ConfigType,AUTOMATIC,COMM_CONFIG_DATA) ComM_ConfigPtr = NULL_PTR;

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
    PncNmRequest            : the PNC state machine to PNC_REQUESTED Nm shall be called using the API 
                              Nm_NetworkRequest. Enabled if COMM_PNC_SUPPORT is STD_ON
    PncStartId              : the pnc config start Id.
                              Enabled if COMM_PNC_SUPPORT is STD_ON
    PncEndId                : the pnc config end Id.
                              Enabled if COMM_PNC_SUPPORT is STD_ON
    UsersToChannelMap       : the users to channel mapping for this channel Id.
                              Enabled if COMM_PNC_SUPPORT is STD_ON
*/
CONST(ComM_ChannelConfigType,COMM_CONFIG_DATA) ComM_ChannelConfig[COMM_NUM_OF_CHANNELS]=
{
    {
        COMM_BUS_TYPE_CAN,  /* BusType */
        COMM_NM_VARIANT_TYPE_FULL, /* NmVariantType */
        #if(STD_OFF == COM_FULL_COMM_REQUEST_NOTIFICATION_ENABLED)
        TRUE, /* FullCommRequestNotificationEnabled */
        #endif
        FALSE, /* NoCom */
        #if(STD_OFF == COMM_NVM_SUPPORT) 
        FALSE, /* NoWakeUpInhibitionNvmStorage */
        #endif
        FALSE, /* NoWakeup */
        0U,  /* BusSMFnConfigId */
        0U,  /* NmLightTimeout */
        0U, /* NmFullComTimeout */
        #if (STD_ON == COMM_PNC_SUPPORT)
        #if (STD_ON == COMM_PNC_GATEWAY_ENABLED )
        COMM_PNC_GATEWAY_TYPE_PASSIVE, /* PncGatewayType */
        #endif
        FALSE, /* PncNmRequest */
        0, /* PncStartId */
        0, /* PncEndId */
        #endif
        {0x01} /* UserToChannelMap */
    },
    {
        COMM_BUS_TYPE_CAN,  /* BusType */
        COMM_NM_VARIANT_TYPE_FULL, /* NmVariantType */
        #if(STD_OFF == COM_FULL_COMM_REQUEST_NOTIFICATION_ENABLED)
        TRUE, /* FullCommRequestNotificationEnabled */
        #endif
        FALSE, /* NoCom */
        #if(STD_OFF == COMM_NVM_SUPPORT) 
        FALSE, /* NoWakeUpInhibitionNvmStorage */
        #endif
        FALSE, /* NoWakeup */
        0U,  /* BusSMFnConfigId */
        0U,  /* NmLightTimeout */
        0U, /* NmFullComTimeout */
        #if (STD_ON == COMM_PNC_SUPPORT)
        #if (STD_ON == COMM_PNC_GATEWAY_ENABLED)
        COMM_PNC_GATEWAY_TYPE_PASSIVE, /* PncGatewayType */
        #endif
        FALSE, /* PncNmRequest */
        0, /* PncStartId */
        0, /* PncEndId */
        #endif
        {0x02} /* UserToChannelMap */
    },
    {
        COMM_BUS_TYPE_ETH,  /* BusType */
        COMM_NM_VARIANT_TYPE_NONE, /* NmVariantType */
        #if(STD_OFF == COM_FULL_COMM_REQUEST_NOTIFICATION_ENABLED)
        TRUE, /* FullCommRequestNotificationEnabled */
        #endif
        FALSE, /* NoCom */
        #if(STD_OFF == COMM_NVM_SUPPORT) 
        FALSE, /* NoWakeUpInhibitionNvmStorage */
        #endif
        FALSE, /* NoWakeup */
        0U,  /* BusSMFnConfigId */
        0U,  /* NmLightTimeout */
        0U, /* NmFullComTimeout */
        #if (STD_ON == COMM_PNC_SUPPORT)
        #if (STD_ON == COMM_PNC_GATEWAY_ENABLED)
        COMM_PNC_GATEWAY_TYPE_PASSIVE, /* PncGatewayType */
        #endif
        FALSE, /* PncNmRequest */
        0, /* PncStartId */
        0, /* PncEndId */
        #endif
        {0x04} /* UserToChannelMap */
    }
};

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
CONST(ComM_UserConfigType,COMM_CONFIG_DATA) ComM_UserConfig[COMM_NUM_OF_USERS] =
{
    {
        {0x01} /* channels to user map configuration */
        #if(STD_ON == COMM_USER_MODE_NOTIFICATION_SUPPORT )
        ,NULL_PTR /* the function for the user notification */
        #endif
        #if (STD_ON == COMM_PNC_SUPPORT)
        ,0U, /* PncStartId */
        0U /* PncEndId */
        #endif
    },
    {
        {0x02} /* channels to user map configuration */
        #if(STD_ON == COMM_USER_MODE_NOTIFICATION_SUPPORT )
        ,NULL_PTR /* the function for the user notification */
        #endif
        #if (STD_ON == COMM_PNC_SUPPORT)
        ,0U, /* PncStartId */
        0U /* PncEndId */
        #endif
    },
    {
        {0x04} /* channels to user map configuration */
        #if(STD_ON == COMM_USER_MODE_NOTIFICATION_SUPPORT )
        ,NULL_PTR /* the function for the user notification */
        #endif
        #if (STD_ON == COMM_PNC_SUPPORT)
        ,0U, /* PncStartId */
        0U /* PncEndId */
        #endif
    }
};

/*! @brief Defines the BusSM function configuration. 
    Elements                    : Description
    BusSMGetCurrentComModeFn    : the function for getting the current Com Mode of Bus SM
    CanSM_RequestComModeFn      : the function for requesting the new BusSM mode
*/
CONST(ComM_BusSMComMModeFnConfigType,COMM_CONFIG_DATA) ComM_BusSMComMModeFnConfig[COMM_NUM_OF_SUPPORTED_BUS]=
{
    /* CAN Bus */
    {
        &CanSM_GetCurrentComMode, /* function for getting the current Com Mode */
        &CanSM_RequestComMode /* function for requesting the new BusSM mode */
    },
    /* Eth Bus */
    /*{
        &EthSM_GetCurrentComMode,  function for getting the current Com Mode
        &EthSM_RequestComMode  function for requesting the new BusSM mode
    }*/
};

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
CONST(ComM_PncConfigType,COMM_CONFIG_DATA) ComM_PncConfig[COMM_NUM_OF_PNC] =
{
    {
        2U, /* PncHandle */
		0U, /* ByteOffset */
		0x02, /* BitMask */
		0U, /* PncUserStartId */
		0U, /* PncUserEndId */
		0U, /* PncChannelStartId */
		0U, /* PncChannelEndId */
		0U, /* PncComSignalStartId */
		0U /* PncComSignalEndId */
    }
};

/*! @brief Defines the ComM PNC Id to User mapping configuration */
CONST(ComM_UserHandleType,COMM_CONFIG_DATA) ComM_PncToUserMapConfig[COMM_NUM_OF_PNC_TO_USER_MAP]=
{
		0U /* User Id */
};

/*! @brief Defines the ComM PNC Id to Channel mapping configuration */
CONST(ComM_ChannelIdType,COMM_CONFIG_DATA) ComM_PncToChannelMapConfig[COMM_NUM_OF_PNC_TO_CHANNEL_MAP]=
{
		0U /* Channel Id */
};

/*! @brief Defines the ComM Network PNC signal configuration. 
    Elements                    : Description
    PncComSignalDirectionType   : the PncComSignals direction type
    PncComSignalType            : Indicates whether this PncComSignal represents EIRA or ERA PNC information.
    PncComSignalChanneId        : Reference to the ComMChannel whose PncComSignal participate in active or passive role
    PncComSignalId              : Reference to the ComSignal which used to tx the PN request information.
    PncComSignalBufferStartId   : the Buffer start Id of the ComM PNC signal buffer
*/
extern CONST(ComM_PncComSignalConfigType,COMM_CONFIG_DATA) ComM_PncComSignalConfig[COMM_NUM_OF_PNC_COM_SIGNAL]=
{
    {
        COMM_PNC_COM_SIGNAL_DIRECTION_TYPE_TX, /* PncComSignalDirectionType */
        COMM_PNC_COM_SIGNAL_TYPE_ERA, /* PncComSignalType */
        0U, /* PncComSignalChanneId */
        0U, /* PncComSignalId */
        0U /*  PncComSignalBufferStartId */
    },
    {
        COMM_PNC_COM_SIGNAL_DIRECTION_TYPE_RX,
        COMM_PNC_COM_SIGNAL_TYPE_ERA,
        0U,
        1U,
        1U
    }
};
#endif

#define COMM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


#define COMM_START_SEC_CODE
#include "MemMap.h"

/*!******************************************************************************************************************
*   @brief  This service performs the processing of ComM channel 0 state machine. ComM main function for channel 0
********************************************************************************************************************/
extern FUNC(void,COMM_CODE) ComM_MainFunction_0(void)
{
    /* Call the ComM_MainFunction() for the corresponding channel. */
    ComM_MainFunction((NetworkHandleType)0U);
}

/********************************************************************************************************************
*   @brief      This method invokes the ComM main function for channel 1
********************************************************************************************************************/
void ComM_MainFunction_1(void)
{
    /* Call the ComM_MainFunction() for the corresponding channel. */
    ComM_MainFunction((NetworkHandleType)1U);
}

/********************************************************************************************************************
*   @brief      This method invokes the ComM main function for channel 1
********************************************************************************************************************/
void ComM_MainFunction_2(void)
{
    /* Call the ComM_MainFunction() for the corresponding channel. */
    ComM_MainFunction((NetworkHandleType)2U);
}

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


