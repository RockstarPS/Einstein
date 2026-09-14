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
*    @file CanTrcv_GeneralTypes.h
*    @ingroup CanTrcvConfiguration
*    @brief This is CanTrcv general configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the CanTrcv module. If Can General Types has trcv definitions , then include the
*    Can_GeneralTypes.h
*    @defgroup CanTrcvConfiguration
*    @brief This contains the configuration files for the CanTrcv module.
********************************************************************************************************************/
#ifndef CANTRCV_GENERALTYPES_H
#define CANTRCV_GENERALTYPES_H

/* Enable below macro if the Can_GeneralTypes.h includes the CanTrcv types */
/* #define CAN_GENERAL_TYPES_SUPPORT */

#ifdef CAN_GENERAL_TYPES_SUPPORT
#include "Can_GeneralTypes.h"
#else
/*! @brief Defines the type of transceiver's operating mode */
typedef enum
{
    CANTRCV_TRCVMODE_NORMAL = 0u, /*! Defines transceiver Normal mode */
    CANTRCV_TRCVMODE_SLEEP,       /*! Defines transceiver sleep mode */
    CANTRCV_TRCVMODE_STANDBY      /*! Defines transceiver standby mode */
} CanTrcv_TrcvModeType;

/*! @brief Defines the type to control the CAN transceiver concerning wake up events and
    wake up notifications. */
typedef enum
{
    CANTRCV_WUMODE_ENABLE = 0u,   /*! Defines wakeup mode to be enabled */
    CANTRCV_WUMODE_CLEAR,         /*! Defines wakeup reason to be cleared */
    CANTRCV_WUMODE_DISABLE        /*! Defines wakeup mode to be disabled */
} CanTrcv_TrcvWakeupModeType;


/*! @brief Defines the type of the wake up reason detected by the CAN transceiver */
typedef enum
{
    CANTRCV_WU_ERROR = 0u, /*! Due to an error wake up reason was not detected. */
    CANTRCV_WU_NOT_SUPPORTED, /*! The transceiver does not support any information for the wake up reason. */
    CANTRCV_WU_BY_BUS, /*! The transceiver has detected, that the network has caused the wake up of the ECU. */
    CANTRCV_WU_INTERNALLY,/*!  the network has woken up by the ECU via a request to NORMAL mode */
    CANTRCV_WU_RESET, /*! that the "wake up" is due to an ECU reset. */
    CANTRCV_WU_POWER_ON, /*! that the "wake up" is due to an ECU reset after power on. */
    CANTRCV_WU_BY_PIN, /*! detected a wake-up event at one of the transceiver's pins (not at the CAN bus). */
    CANTRCV_WU_BY_SYSERR /*! that the wake up of the ECU was caused by a HW related device failure. */
} CanTrcv_TrcvWakeupReasonType;

#endif /* CAN_GENERAL_TYPES_SUPPORT */

#endif /* CANTRCV_GENERALTYPES_H */


