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
*    @file CanSM_Cfg.h
*    @ingroup CanSMConfiguration
*    @brief This is CanSM Pre-compile time configuration header file. It contains definitions of pre-compile time 
*    configuration parameters for the CanSM module.
*    @defgroup CanSMConfiguration
*    @brief This contains the configuration files for the CanSM module.
********************************************************************************************************************/
#ifndef CANSM_CFG_H
#define CANSM_CFG_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "CanSM_Types.h"
#include "Dem.h" /* if CANSM_DEM_ERROR_REPORT is STD_ON */
#include "Can_GeneralTypes.h"
/********************************************************************************************************************
*  #! Precompile Configuration                                                                                      *
********************************************************************************************************************/
/*! @brief Switches the Default Error Tracer (Det) detection and notification ON or OFF */
#define CANSM_DEV_ERROR_DETECT                                  STD_ON
/*! @brief  This parameter configures the name of the <User_GetBusOffDelay> call-out function,
            which is used by CanSM to acquire an additional L1/L2 delay time.This function is
            only called for channels where CanSMEnableBusOffDelay is enabled. */
#define CANSM_GET_BUS_OFF_DELAY_FUNCTION                        STD_OFF
/*! @brief  Selects support of Pretended Network features in CanSM. */
#define CANSM_ICOM_SUPPORT                                      STD_OFF
/*! @brief Enables or disables support of partial networking. */
#define CANSM_PNC_SUPPORT                                       STD_OFF
/*! @brief  Enables or disables support Can_SetBaudrate API */
#define CANSM_SET_BAUD_RATE_API                                 STD_OFF
/*! @brief  Determines whether the ECU passive feature is supported by CanSM. */
#define CANSM_TX_OFFLINE_ACTIVE_SUPPORT                         STD_OFF
/*! @brief  Activate/Deactivate the version information API (CanSM_GetVersionInfo). */
#define CANSM_VERSION_INFO_API                                  STD_ON
/*! @brief  This parameter defines the cycle time of the function CanSM_MainFunction in milliseconds */
#define CANSM_MAIN_FUNCTION_TIME_PERIOD                         5U
/*! @brief  Specifies the maximum amount of mode request repetitions without a respective mode indication from the 
            CanIf module until the CanSM module reports a Default Error to the Det and tries to go back to no 
            communication.*/
#define CANSM_MODE_REQUEST_REPETITION_MAX                       10U
/*! @brief  Specifies in which time duration(ms) the CanSM module shall repeat mode change requests by using the 
            API of the CanIf module*/
#define CANSM_MODE_REQUEST_REPETITION_TIME                      10U
/********************************************************************************************************************
*  #! CanSM Internal feature support                                                                                *
********************************************************************************************************************/
/*! @brief  Enables or disables CanSM Transceiver support. Enabled if any of the network supports Transceiver */
#define CANSM_TRCV_HANDLING                                     STD_OFF
/*! @brief  Specifies Whether DEM event notification is enable or not. Enabled if CanSMDemEventParameterRefs 
            enabled */
#define CANSM_DEM_ERROR_REPORT                                  STD_OFF
/********************************************************************************************************************
*  #! SW and AUTOSAR Version Macros                                                                                 *
********************************************************************************************************************/
/* Software Version */
/*! @brief Defines the CanSM configuration software Major version */
#define CANSM_CFG_SW_MAJOR_VERSION                               1u
/*! @brief Defines the CanSM configuration software Minor version */
#define CANSM_CFG_SW_MINOR_VERSION                               0u
/*! @brief Defines the CanSM configuration software Patch version */
#define CANSM_CFG_SW_PATCH_VERSION                               0u
/* Autosar Release */
/*! @brief Defines the AUTOSAR Release Major version supported by CanSM configuration  */
#define CANSM_CFG_AR_RELEASE_MAJOR_VERSION                       4u
/*! @brief Defines the AUTOSAR Release Minor version supported by CanSM configuration  */
#define CANSM_CFG_AR_RELEASE_MINOR_VERSION                       3u
/*! @brief Defines the AUTOSAR Release Patch version supported by CanSM configuration  */
#define CANSM_CFG_AR_RELEASE_REVISION_VERSION                    1u
/*******************************************************************************************************************
*  #! CanSM module configuration                                                                                   *
*******************************************************************************************************************/
/*! @brief Defines the number of bus off configuration supported */
#define CANSM_NUM_OF_BUS_OFF_CONFIGURATIONS                     2U
/*! @brief Defines the number of number of networks supported */
#define CANSM_NUM_OF_NETWORKS                                   2U
/*! @brief Defines the invalid channel id type */
#define CANSM_INVALID_CHANNEL                                   CANSM_NUM_OF_NETWORKS
/*! @brief Defines the ComM to CanSM mapping */
#define CANSM_COMM_NUM_OF_NETWORKS                              1
/*! @brief Defines that no transceiver is configured  */
#define CANSM_NO_TRCV_CONFIG                                    0xFF
#ifndef CANSM_DUMMY_STATEMENT
#define CANSM_DUMMY_STATEMENT(v) (v)=(v)
#endif
/********************************************************************************************************************
* #! CanSM types                                                                                                    *
* #! macro , typedef declaration                                                                                    *
********************************************************************************************************************/
/*! @brief Defines the types for the controller id */
typedef uint8 CanSM_ControllerIdType;
/*! @brief Defines the types for the transceiver id */
typedef uint8 CanSM_TransceiverIdType;
/*! @brief Defines the types for the bus off configuration id */
typedef uint8 CanSM_BusOffIdType;
#if (CANSM_GET_BUS_OFF_DELAY_FUNCTION == STD_ON)
/*! @brief Defines the types for the call out function BusOffDelay which returns the number of CanSM base 
    cycles to wait additionally to L1/L2 after a BusOff occurred.*/
typedef P2FUNC(void,CANSM_APPL_CODE,CanSM_UserGetBusOffBeginDelayFunctType)
(
    NetworkHandleType network,
    P2VAR(uint8,AUTOMATIC,CANSM_APPL_DATA) delayCyclesPtr
);
/*! @brief Defines the types for the call out function BusOffEnd which notifies that BusOff recovered.This is used 
    for OSEK NM , not AUTOSAR API*/
typedef P2FUNC(void,CANSM_APPL_CODE,CanSM_UserGetBusOffEndFunctType)(NetworkHandleType network);
#endif

/*! @brief Defines the configuration for the Bus Off handling */
typedef struct
{
    /*! @brief This threshold defines the count of bus-offs until the bus-off recovery switches from
        level 1 (short recovery time) to level 2 (long recovery time). */
    uint8                                   BorCounterL1ToL2;
    /*! @brief This time parameter defines in seconds the duration of the bus-off recovery time in level 1 
        (short recovery time). */
    uint32                                  BorTimeL1;
    /*! @brief This time parameter defines in seconds the duration of the bus-off recovery time in level 2 
        (long recovery time). */
    uint32                                  BorTimeL2;
    /*! @brief This parameter defines in seconds the duration of the bus-off event check.
        This check assesses, if the recovery has been successful after the recovery re-enables the transmit path */
    uint32                                  BorTimeTxEnsured;
    /*! @brief This parameter shall configure, if the CanSM polls the CanIf_GetTxConfirmationState API to decide 
        the bus-off state to be recovered instead of using the CanSMBorTimeTxEnsured parameter for this decision. */
    boolean                                 BorTxConfirmationPolling;
    #if (CANSM_GET_BUS_OFF_DELAY_FUNCTION == STD_ON)
    /*! @brief This parameter defines if the <User_GetBusOffDelay> shall be called for this network. */
    boolean                                 EnableBusOffDelay;
    /*! @brief This parameter defines the call out function which returns the number of CanSM base cycles to 
        wait additionally to L1/L2 after a BusOff occurred.  This can also be used for bus off begin with 
        delay time 0. */
    CanSM_UserGetBusOffBeginDelayFunctType  UserGetBusOffDelayFunctPtr;
    /*! @brief This parameter defines the call out function notifies the bus-off end */
    CanSM_UserGetBusOffEndFunctType         UserGetBusOffEndFunctPtr;
    #endif
    #if(CANSM_DEM_ERROR_REPORT == STD_ON)
    /*! @brief This parameter defines the DEM event Id used to report bus off errors for this CAN network. 
        CANSM_E_BUS_OFF */
    Dem_EventIdType                         BoEventId;
    #endif
}CanSM_BusOffConfigType;

/*! @brief Defines the network specific parameters of each CAN network */
typedef struct
{
    /*! @brief ID of the CAN Controller assigned to the configured network handle.
        Reference to one of the Controller managed by the CanIf module. */
    CanSM_ControllerIdType      ControllerId;
    /*! @brief ID of the CAN transceiver assigned to the configured network handle.
        Reference to one of the transceivers managed by the CanIf module. */
    CanSM_TransceiverIdType     TransceiverId;
    /*! @brief ID of the Bus off configuration . */
    CanSM_BusOffIdType          BusOffId;
}CanSM_NetworkConfigType;

#endif /* CANSM_CFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

