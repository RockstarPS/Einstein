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
*    @file CanIf_Types.h
*    @ingroup CanIf
*    @brief This file provides the types for the CanIf module.
********************************************************************************************************************/
#ifndef CANIF_TYPES_H
#define CANIF_TYPES_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComStack_Types.h"
#include "Can_GeneralTypes.h"

/********************************************************************************************************************
*   MACRO AND DATA TYPES                                                                                            *
********************************************************************************************************************/
/********************************************************************************************************************
*                                 #! memory and pointer classes.                                                    *
********************************************************************************************************************/
#ifndef AUTOMATIC
#define AUTOMATIC
#endif

#ifndef CANIF_CODE
#define CANIF_CODE
#endif 

#ifndef CANIF_CONST
#define CANIF_CONST
#endif  

#ifndef CANIF_APPL_DATA
#define CANIF_APPL_DATA
#endif

#ifndef CANIF_APPL_CONST
#define CANIF_APPL_CODE
#endif

#ifndef CANIF_CALLOUT_CODE
#define CANIF_CALLOUT_CODE
#endif

#ifndef CANIF_VAR
#define CANIF_VAR
#endif

#ifndef CANIF_VAR_INIT
#define CANIF_VAR_INIT
#endif

#ifndef CANIF_VAR_NOINIT
#define CANIF_VAR_NOINIT
#endif

#ifndef CANIF_VAR_POWER_ON_INIT
#define CANIF_VAR_POWER_ON_INIT
#endif

#ifndef CANIF_VAR_FAST
#define CANIF_VAR_FAST
#endif

#ifndef CANIF_VAR_SLOW
#define CANIF_VAR_SLOW
#endif

#ifndef CANIF_CONFIG_DATA
#define CANIF_CONFIG_DATA
#endif

/* CanIf Types */
/*! @brief  This type contains the implementation-specific post build configuration structure .
    Dummy config is used as post build not supported*/
typedef struct
{
    uint8 Dummy;
}CanIf_ConfigType;

/*! @brief Return value of CAN L-PDU notification status */
typedef enum
{
    /*! @brief No transmit or receive event occurred for the requested L-PDU.*/
    CANIF_NO_NOTIFICATION = 0u,
    /*! @brief The requested Rx/Tx CAN L-PDU was successfully transmitted or received.*/
    CANIF_TX_RX_NOTIFICATION
} CanIf_NotifStatusType;

#endif /* CANIF_TYPES_H */

/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/
