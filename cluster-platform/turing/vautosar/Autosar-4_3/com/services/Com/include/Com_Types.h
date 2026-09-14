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
*    @file Com_Types.h
*    @ingroup Com
*    @brief This file provides the private types for the Com module. This header file should be included only by  
*    the Com module.
********************************************************************************************************************/
#ifndef COM_TYPES_H
#define COM_TYPES_H

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

#ifndef COM_CODE
#define COM_CODE
#endif 

#ifndef COM_CONST
#define COM_CONST
#endif  

#ifndef COM_APPL_DATA
#define COM_APPL_DATA
#endif

#ifndef COM_APPL_CONST
#define COM_APPL_CODE
#endif

#ifndef COM_CALLOUT_CODE
#define COM_CALLOUT_CODE
#endif

#ifndef COM_VAR
#define COM_VAR
#endif

#ifndef COM_VAR_INIT
#define COM_VAR_INIT
#endif

#ifndef COM_VAR_NOINIT
#define COM_VAR_NOINIT
#endif

#ifndef COM_VAR_POWER_ON_INIT
#define COM_VAR_POWER_ON_INIT
#endif

#ifndef COM_VAR_FAST
#define COM_VAR_FAST
#endif

#ifndef COM_VAR_SLOW
#define COM_VAR_SLOW
#endif

#ifndef COM_CONFIG_DATA
#define COM_CONFIG_DATA
#endif

/*! @brief  This type contains the implementation-specific post build configuration structure . Dummy config is used 
    as post-build not supported. SWS_Com_00825 */
typedef struct
{
    uint8 Dummy;
}Com_ConfigType;

/* Com Types */
/*! @brief Defines the Com module status . SWS_Com_00819 */
typedef enum
{
    /*! @brief The AUTOSAR COM module is not initialized or not usable. This shall be the default value after reset */
    COM_UNINIT = 0U,
    /*! @brief The AUTOSAR COM module is initialized and usable. */
    COM_INIT
}Com_StatusType;

/*! @brief Defines the AUTOSAR COM module's signal object identifier SWS_Com_00820 */
typedef uint16 Com_SignalIdType;

/*! @brief Defines the AUTOSAR COM module's signal group object identifier SWS_Com_00821 */
typedef uint16 Com_SignalGroupIdType;

/*! @brief Defines the AUTOSAR COM I-PDU module's group object identifier Com_IpduGroupIdType */
typedef uint16 Com_IpduGroupIdType;

#endif /* COM_TYPES_H */

/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/
