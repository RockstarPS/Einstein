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
*    @file EthTrcv_Types.h
*    @ingroup EthTrcv
*    @brief This file provides the types for the EthTrcv module.
********************************************************************************************************************/
#ifndef ETHTRCV_TYPES_H
#define ETHTRCV_TYPES_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "Eth_GeneralTypes.h" 
/********************************************************************************************************************
*   MACRO AND DATA TYPES                                                                                            *
********************************************************************************************************************/
/********************************************************************************************************************
*                                 #! memory and pointer classes.                                                    *
********************************************************************************************************************/
#ifndef AUTOMATIC
#define AUTOMATIC
#endif

#ifndef ETHTRCV_CODE
#define ETHTRCV_CODE
#endif 

#ifndef ETHTRCV_CONST
#define ETHTRCV_CONST
#endif  

#ifndef ETHTRCV_APPL_DATA
#define ETHTRCV_APPL_DATA
#endif

#ifndef ETHTRCV_APPL_CONST
#define ETHTRCV_APPL_CODE
#endif

#ifndef ETHTRCV_CALLOUT_CODE
#define ETHTRCV_CALLOUT_CODE
#endif

#ifndef ETHTRCV_VAR
#define ETHTRCV_VAR
#endif

#ifndef ETHTRCV_VAR_INIT
#define ETHTRCV_VAR_INIT
#endif

#ifndef ETHTRCV_VAR_NOINIT
#define ETHTRCV_VAR_NOINIT
#endif

#ifndef ETHTRCV_VAR_POWER_ON_INIT
#define ETHTRCV_VAR_POWER_ON_INIT
#endif

#ifndef ETHTRCV_VAR_FAST
#define ETHTRCV_VAR_FAST
#endif

#ifndef ETHTRCV_VAR_SLOW
#define ETHTRCV_VAR_SLOW
#endif

/*! @brief This type defines the transceiver modes */
typedef enum
{
    ETHTRCV_MODE_DOWN   = 0x00u, /*! @brief 0x00: Transceiver disabled */
    ETHTRCV_MODE_ACTIVE = 0x01u  /*! @brief 0x01: Transceiver enabled */
}EthTrcv_ModeType;


/*! @brief This type defines the Ethernet link state. The link state changes after an Ethernet cable gets plugged in 
and the transceivers on both ends negotiated the transmission parameters (i.e. baud rate and duplex mode) */
typedef enum
{
    ETHTRCV_LINK_STATE_DOWN     = 0x00u, /*! @brief No physical Ethernet connection established */
    ETHTRCV_LINK_STATE_ACTIVE   = 0x01u  /*! @brief 0x01: Physical Ethernet connection established */
}EthTrcv_LinkStateType;

/*! @brief This type defines the Status supervision used for Development Error Detection. The state shall be available
 for debugging. */
typedef enum
{
    ETHTRCV_STATE_UNINIT    = 0x00u, /*! @brief 0x00: Driver is not yet configured */
    ETHTRCV_STATE_INIT      = 0x01u  /*! @brief 0x01: Driver is configured */
}EthTrcv_StateType;

/*! @brief This type defines the Ethernet baud rate. The baud rate gets either negotiated between the connected 
transceivers or has to be configured. */
typedef enum
{
    ETHTRCV_BAUD_RATE_10MBIT    = 0x00u, /*! @brief 10MBIT Ethernet connection */
    ETHTRCV_BAUD_RATE_100MBIT   = 0x01u, /*! @brief 100MBIT Ethernet connection */
    ETHTRCV_BAUD_RATE_1000MBIT  = 0x02u  /*! @brief 1000MBIT Ethernet connection */
}EthTrcv_BaudRateType;

/*! @brief This type defines the Ethernet duplex mode. The duplex mode gets either negotiated between the connected
    transceivers or has to be configured */
typedef enum
{
    ETHTRCV_DUPLEX_MODE_HALF = 0x00u, /*! @brief Half duplex Ethernet connection */
    ETHTRCV_DUPLEX_MODE_FULL = 0x01u  /*! @brief Full duplex Ethernet connection */
}EthTrcv_DuplexModeType;

/*! @brief This type controls the transceiver wake up modes and/or clears the wake-up reason. */
typedef enum 
{
    ETHTRCV_WUM_DISABLE = 0x00u, /*! @brief Transceiver wake up disabled */
    ETHTRCV_WUM_ENABLE  = 0x01u, /*! @brief Transceiver wake up enabled */
    ETHTRCV_WUM_CLEAR   = 0x02u  /*! @brief Transceiver wake up reason cleared. */
}EthTrcv_WakeupModeType;

/*! @brief This type defines the transceiver wake up reasons. */
typedef enum
{
    ETHTRCV_WUR_NONE        = 0x00u, /*! @brief No wake up reason detected. */
    ETHTRCV_WUR_GENERAL     = 0x01u, /*! @brief General wake up detected, no distinct reason supported by hardware.*/
    ETHTRCV_WUR_BUS         = 0x02u, /*! @brief Bus wake up detected. Available if supported by hardware. */
    ETHTRCV_WUR_INTERNAL    = 0x03u, /*! @brief Internal wake up detected. Available if supported by hardware. */
    ETHTRCV_WUR_RESET       = 0x04u, /*! @brief Reset wake up detected. Available if supported by hardware. */
    ETHTRCV_WUR_POWER_ON    = 0x05u, /*! @brief Power on wake up detected. Available if supported by hardware. */
    ETHTRCV_WUR_PIN         = 0x06u, /*! @brief Pin wake up detected. Available if supported by hardware. */
    ETHTRCV_WUR_SYSERR      = 0x07u  /*! @brief System error wake up detected. Available if supported by hardware. */
}EthTrcv_WakeupReasonType;

#endif /* ETHTRCV_TYPES_H */

/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/

