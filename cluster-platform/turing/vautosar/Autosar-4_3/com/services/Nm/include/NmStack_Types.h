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
*   @file       Nm_Types.h
*   @ingroup    Nm
*   @brief      This file provides the declaration of the Nm Types. This header file should be included by
*   other modules that use the Nm Types.
*   @defgroup   Services
*   @brief      The Network Management (Nm) module coordinates network sleep and wake-up for ECUs, ensuring 
*   efficient communication and power management. It handles network state transitions and monitors node presence
*   in automotive networks.
********************************************************************************************************************/
#ifndef NMSTACK_TYPES_H
#define NMSTACK_TYPES_H
/* Includes */
#include "Std_Types.h"

/* NM Types */
/*!
 *  @brief Defines the Operational modes of the network management
 */
typedef enum
{
    NM_MODE_BUS_SLEEP = 0, /*! @brief Bus-Sleep Mode of NM */
    NM_MODE_PREPARE_BUS_SLEEP, /*! @brief Prepare-Bus Sleep Mode */
    NM_MODE_SYNCHRONIZE, /*! @brief Synchronize Mode of NM */
    NM_MODE_NETWORK /*! @brief Network Mode of NM */
}Nm_ModeType;

/*!
 *  @brief Defines the States of the network management state machine.
 */
typedef enum
{
    NM_STATE_UNINIT = 0,        /*! @brief Uninitialized State of NM state machine*/
    NM_STATE_BUS_SLEEP,         /*! @brief Bus-Sleep State of NM state machine */
    NM_STATE_PREPARE_BUS_SLEEP, /*! @brief Prepare-Bus State of NM state machine */
    NM_STATE_READY_SLEEP,       /*! @brief Ready Sleep State of NM state machine */
    NM_STATE_NORMAL_OPERATION,  /*! @brief Normal Operation State of NM state machine */
    NM_STATE_REPEAT_MESSAGE,    /*! @brief Repeat Message State of NM state machine */
    NM_STATE_SYNCHRONIZE,       /*! @brief Synchronize State of NM state machine */
    NM_STATE_OFFLINE,           /*! @brief Offline State of NM state machine */
    NM_STATE_NUMBER_OF_STATES   /*! @brief Number of NM states */
}Nm_StateType;

/*!
 *  @brief Defines the BusNm type.
 */
typedef enum
{
    NM_BUSNM_CANNM = 0U,        /*! @brief BusNm type as CAN NM */
    NM_BUSNM_FRNM = 1U,         /*! @brief BusNm type as FR NM */
    NM_BUSNM_LINNM = 2U,        /*! @brief BusNm type as LIN NM */
    NM_BUSNM_UDPNM = 3U,        /*! @brief BusNm type as UDP NM */
    NM_BUSNM_GENERICNM = 4U,    /*! @brief BusNm type as Generic NM */
    NM_BUSNM_J1939NM = 5U,      /*! @brief BusNm type as SAE J1939 NM */
    NM_BUSNM_UNDEF = 0xFFU     /*! @brief BusNm type as undefined */
}Nm_BusNmType;

/*!
 *  @brief  This type contains the implementation-specific post build configuration structure of NM .
            Dummy config is used as post build not supported
 */
typedef struct
{
    uint8 Dummy;
}Nm_ConfigType;

#endif /* NMSTACK_TYPES_H */

/*****************************************************************************************************************
*                                 END OF FILE                                                                    *
******************************************************************************************************************/
