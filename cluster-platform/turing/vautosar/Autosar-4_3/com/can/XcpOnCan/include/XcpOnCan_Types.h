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
*    @file XcpOnCan_Types.h
*    @ingroup XcpOnCan
*    @brief This file provides the types for the XcpOnCan module.
********************************************************************************************************************/
#ifndef XCPONCAN_TYPES_H
#define XCPONCAN_TYPES_H
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

#ifndef XCPONCAN_CODE
#define XCPONCAN_CODE
#endif 

#ifndef XCPONCAN_CONST
#define XCPONCAN_CONST
#endif  

#ifndef XCPONCAN_APPL_DATA
#define XCPONCAN_APPL_DATA
#endif

#ifndef XCPONCAN_APPL_CONST
#define XCPONCAN_APPL_CONST
#endif

#ifndef XCPONCAN_CALLOUT_CODE
#define XCPONCAN_CALLOUT_CODE
#endif

#ifndef XCPONCAN_VAR
#define XCPONCAN_VAR
#endif

#ifndef XCPONCAN_VAR_INIT
#define XCPONCAN_VAR_INIT
#endif

#ifndef XCPONCAN_VAR_NOINIT
#define XCPONCAN_VAR_NOINIT
#endif

#ifndef XCPONCAN_VAR_POWER_ON_INIT
#define XCPONCAN_VAR_POWER_ON_INIT
#endif

#ifndef XCPONCAN_VAR_FAST
#define XCPONCAN_VAR_FAST
#endif

#ifndef XCPONCAN_VAR_SLOW
#define XCPONCAN_VAR_SLOW
#endif

/* #! XcpOnCan Types */
/*! @brief Defines the type of XcpOnCan Init status */
typedef enum
{
    XcpOnCan_InitStateUnInitialized = 0U, /*! @brief Defines the type of XcpOnCan Init status UnInitialized */
    XcpOnCan_InitStateInitialized  /*! @brief Defines the type of XcpOnCan Init status Initialized */
}XcpOnCan_InitStateType;

/*! @brief Defines the type of XcpOnCan Tx state */
typedef enum
{
    XCPONCAN_TX_STATE_IDLE=0U, /*! @brief Defines the type of XcpOnCan Tx state Idle */
    XCPONCAN_TX_STATE_PENDING /*! @brief Defines the type of XcpOnCan Tx state Pending */
}XcpOnCan_TxStateType;

/*! @brief Defines the type of XcpOnCan control state */
typedef enum
{
    XcpOnCan_ControlStateDisable=0U, /*! @brief Defines the type of XcpOnCan control state disable */
    XcpOnCan_ControlStateEnable /*! @brief Defines the type of XcpOnCan control state enable */
}XcpOnCan_ControlStateType;

/*! @brief Defines the type of XcpOnCan pdu state */
typedef enum
{
    XcpOnCan_PduSetStateOffline=0U, /*! @brief Defines the type of XcpOnCan pdu state offline */
    XcpOnCan_PduSetStateOnline /*! @brief Defines the type of XcpOnCan pdu state online */
}XcpOnCan_PduSetStateType;

#endif /* XCPONCAN_TYPES_H */

/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/
