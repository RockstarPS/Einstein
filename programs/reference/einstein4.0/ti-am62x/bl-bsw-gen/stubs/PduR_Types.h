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
*    @file PduR_Types.h
*    @ingroup PduRConfiguration
*    @brief This is PduR types  header file. It contains definitions of types for the PduR module.
*    @defgroup PduRConfiguration
*    @brief This contains the  PduR types  header file
********************************************************************************************************************/
#ifndef PDUR_TYPES_H
#define PDUR_TYPES_H

/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComStack_Types.h"
/********************************************************************************************************************
*   MACRO AND DATA TYPES                                                                                            *
********************************************************************************************************************/
/********************************************************************************************************************
*                                 #! memory and pointer classes.                                                    *
********************************************************************************************************************/
#ifndef AUTOMATIC
#define AUTOMATIC
#endif

#ifndef PDUR_CODE
#define PDUR_CODE
#endif 

#ifndef PDUR_CONST
#define PDUR_CONST
#endif  

#ifndef PDUR_APPL_DATA
#define PDUR_APPL_DATA
#endif

#ifndef PDUR_APPL_CONST
#define PDUR_APPL_CODE
#endif

#ifndef PDUR_CALLOUT_CODE
#define PDUR_CALLOUT_CODE
#endif

#ifndef PDUR_VAR
#define PDUR_VAR
#endif

#ifndef PDUR_VAR_INIT
#define PDUR_VAR_INIT
#endif

#ifndef PDUR_VAR_NOINIT
#define PDUR_VAR_NOINIT
#endif

#ifndef PDUR_VAR_POWER_ON_INIT
#define PDUR_VAR_POWER_ON_INIT
#endif

#ifndef PDUR_VAR_FAST
#define PDUR_VAR_FAST
#endif

#ifndef PDUR_VAR_SLOW
#define PDUR_VAR_SLOW
#endif

#ifndef PDUR_CONFIG_DATA
#define PDUR_CONFIG_DATA
#endif

/*! @brief Identification of the post-build configuration currently used for routing I-PDUs */
typedef uint16 PduR_PBConfigIdType;

/*! @brief Identification of a Routing Table */
typedef uint16 PduR_RoutingPathGroupIdType;

/*! @brief States of the PDU Router */
typedef enum
{
    PDUR_UNINIT=0U, /*! @brief PDU Router not initialized */
    PDUR_ONLINE     /*! @brief PDU Router initialized successfully */
} PduR_StateType;

/*! @brief The PDUR module shall call the transmit function in the destination module.
    The destination module will request the I-PDU using the triggerTransmit function. The I-PDU is shall be
    buffered.*/
#define PDUR_DATA_PROVISIONING_TRIGGER_TRANSMIT 0U
/*! @brief The PDUR module shall call the transmit function in the destination module and not buffer the I-PDU*/
#define PDUR_DATA_PROVISIONING_DIRECT_TRANSMIT  1U
/*! @brief The PDUR module does nothing. This should be used for receive direction type*/
#define PDUR_DATA_PROVISIONING_NONE             2U
/*! @brief Defines how the data are provided to the other layer*/
typedef uint8 PduR_DataProvisioningType;


#endif /* PDUR_TYPES_H */

/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/
