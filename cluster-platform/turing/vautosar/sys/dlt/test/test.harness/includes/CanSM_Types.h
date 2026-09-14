/********************************************************************************************************************
|  File Name: CanSM_Types.h
|
|  Description: Implementation of the AUTOSAR CanSM Types
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
| 2020-04-14  00.00.04  MA     Review Comments fixed (Task 808498)
| 2020-03-13  00.00.03  MA     Transceiver and wakeup support State Machine Added
| 2020-02-04  00.00.02  MA     Review Comments fixed (Task 1394516)
| 2019-12-23  00.00.01  MA     Initial Version
|*******************************************************************************************************************/
#ifndef CAN_SM_TYPES_H
#define CAN_SM_TYPES_H

#include "ComStack_Types.h"
#include "CanSM_Cfg.h"

#if(CANSM_DEM_ERROR_REPORT == STD_ON)
#include "Dem.h" /* TODO: Need to verify the includes for DEM Id */
#endif
/* CanSM Types */

/*!
@brief Defines the values of the internal states of the CanSM module
*/
typedef enum
{
    CANSM_INITED=0U,    /*! @brief Defines the internal state CANSM_INITED */
    CANSM_UNINITED      /*! @brief Defines the internal state CANSM_UNINITED */
}CanSM_StateType;

/*! @brief  This type contains the implementation-specific post build configuration structure of CanSM .
            Dummy config is used as post build not supported*/
typedef struct
{
    uint8 Dummy;
}CanSM_ConfigType;

/*! @brief Defines the CAN specific communication modes / states notified to the BswM module */
typedef enum
{
    CANSM_BSWM_NO_COMMUNICATION=0U,     /*! @brief State representing CAN No communication */
    CANSM_BSWM_SILENT_COMMUNICATION,    /*! @brief State representing CAN silent communication */
    CANSM_BSWM_FULL_COMMUNICATION,      /*! @brief State representing CAN full communication */
    CANSM_BSWM_BUS_OFF,                 /*! @brief State representing CAN bus off */
    CANSM_BSWM_CHANGE_BAUDRATE          /*! @brief State representing CAN baud rate change */
}CanSM_BswMCurrentStateType;

/* CanSM Configuration Types */
/*! @brief Defines the types for the controller id */
typedef uint8 CanSM_ControllerIdType;
/*! @brief Defines the types for the transceiver id */
typedef uint8 CanSM_TransceiverIdType;
/*! @brief Defines the types for the bus off configuration id */
typedef uint8 CanSM_BusOffIdType;

#if (CANSM_GET_BUS_OFF_DELAY_FUNCTION == STD_ON)
/*! @brief Defines the types for the call out function BusOffDelay which returns the number of CanSM base cycles to wait additionally to L1/L2 after a BusOff occurred.*/
typedef void (*CanSM_UserGetBusOffBeginDelayFunctType)(NetworkHandleType, uint8*);
/*! @brief Defines the types for the call out function BusOffEnd which notifies that BusOff recovered.This is used for OSEK NM , not AUTOSAR API*/
typedef void (*CanSM_UserGetBusOffEndFunctType)(NetworkHandleType);
#endif

/*! @brief Defines the configuration for the Bus Off handling */
typedef struct
{
    /*! @brief This threshold defines the count of bus-offs until the bus-off recovery switches from
        level 1 (short recovery time) to level 2 (long recovery time). */
    uint8   BorCounterL1ToL2;
    /*! @brief This time parameter defines in seconds the duration of the bus-off recovery time in level 1 (short recovery time). */
    uint32  BorTimeL1;
    /*! @brief This time parameter defines in seconds the duration of the bus-off recovery time in level 2 (long recovery time). */
    uint32  BorTimeL2;
    /*! @brief This parameter defines in seconds the duration of the bus-off event check.
        This check assesses, if the recovery has been successful after the recovery re-enables the transmit path */
    uint32  BorTimeTxEnsured;
    /*! @brief This parameter shall configure, if the CanSM polls the CanIf_GetTxConfirmationState API to decide the bus-off state to
        be recovered instead of using the CanSMBorTimeTxEnsured parameter for this decision. */
    boolean BorTxConfirmationPolling;
    #if (CANSM_GET_BUS_OFF_DELAY_FUNCTION == STD_ON)
    /*! @brief This parameter defines if the <User_GetBusOffDelay> shall be called for this network. */
    boolean EnableBusOffDelay;
    /*! @brief This parameter defines the call out function which returns the number of CanSM base cycles to wait additionally
        to L1/L2 after a BusOff occurred.  This can also be used for bus off begin with delay time 0. */
    CanSM_UserGetBusOffBeginDelayFunctType UserGetBusOffDelayFunctPtr;
    /*! @brief This parameter defines the call out function notifies the bus-off end */
    CanSM_UserGetBusOffEndFunctType   UserGetBusOffEndFunctPtr;
    #endif
    #if(CANSM_DEM_ERROR_REPORT == STD_ON)
    /*! @brief This parameter defines the DEM event Id used to report bus off errors for this CAN network. CANSM_E_BUS_OFF */
    Dem_EventIdType BoEventId;
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
    CanSM_BusOffIdType         BusOffId;
}CanSM_NetworkConfigType;

#endif
