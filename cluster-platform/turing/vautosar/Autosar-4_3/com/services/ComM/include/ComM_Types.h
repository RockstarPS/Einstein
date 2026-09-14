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
*    @file ComM_Types.h
*    @ingroup ComM
*    @brief This file provides the types for the ComM module.
********************************************************************************************************************/
#ifndef COMM_TYPES_H
#define COMM_TYPES_H

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

#ifndef COMM_CODE
#define COMM_CODE
#endif 

#ifndef COMM_CONST
#define COMM_CONST
#endif  

#ifndef COMM_APPL_DATA
#define COMM_APPL_DATA
#endif

#ifndef COMM_APPL_CONST
#define COMM_APPL_CODE
#endif

#ifndef COMM_CALLOUT_CODE
#define COMM_CALLOUT_CODE
#endif

#ifndef COMM_VAR
#define COMM_VAR
#endif

#ifndef COMM_VAR_INIT
#define COMM_VAR_INIT
#endif

#ifndef COMM_VAR_NOINIT
#define COMM_VAR_NOINIT
#endif

#ifndef COMM_VAR_POWER_ON_INIT
#define COMM_VAR_POWER_ON_INIT
#endif

#ifndef COMM_VAR_FAST
#define COMM_VAR_FAST
#endif

#ifndef COMM_VAR_SLOW
#define COMM_VAR_SLOW
#endif

#ifndef COMM_CONFIG_DATA
#define COMM_CONFIG_DATA
#endif

/*! @brief Initialization status of ComM. */
typedef enum
{
    /*! @brief The COM Manager is not initialized or not usable. This shall be the default value after reset.
        This status shall have the value 0. */
    COMM_UNINIT=0U,
    /*! @brief The COM Manager is initialized and usable. */
    COMM_INIT
} ComM_InitStatusType;

#ifndef Rte_TypeDef_ComM_InhibitionStatusType 
/*! @brief Bit 0 (LSB): Wake Up inhibition active */
#define COMM_INHIBITION_STATUS_WAKEUP_INHIBITION_ACTIVE 0x01U
/*! @brief Bit 1: Limit to COMM_NO_COMMUNICATION mode */
#define COMM_INHIBITION_STATUS_LIMITED_TO_NO_COM        0x02U
/*! @brief Defines whether a mode inhibition is active or not. Inhibition status of ComM.TODO Check with RTE Types  */
typedef uint8 ComM_InhibitionStatusType;
#endif

/*! @brief Current mode of a PNC */
typedef enum
{
    /*! @brief PNC is requested by a local ComM user  */
    COMM_PNC_REQUESTED=0U,
    /*! @brief PNC is requested by a remote ComM user */
    COMM_PNC_READY_SLEEP,
    /*! @brief PNC is active with no deadline monitoring */
    COMM_PNC_PREPARE_SLEEP,
    /*! @brief PNC does not communicate */
    COMM_PNC_NO_COMMUNICATION
} ComM_PncModeType;

/*! @brief Sub state of COMM_NO_COMMUNICATION state.No communication and no pending request to start communication. */
#define COMM_NO_COM_NO_PENDING_REQUEST      0U
/*! @brief Sub state of COMM_NO_COMMUNICATION state.No communication, but a pending request to start communication */
#define COMM_NO_COM_REQUEST_PENDING         1U
/*! @brief Sub state of COMM_FULL_COMMUNICATION*/
#define COMM_FULL_COM_NETWORK_REQUESTED     2U
/*! @brief Sub state of COMM_FULL_COMMUNICATION*/
#define COMM_FULL_COM_READY_SLEEP           3U
/*! @brief COMM_SILENT_COMMUNICATION state */
#define COMM_SILENT_COM                     4U
/*! @brief COMM_SILENT_COMMUNICATION state */
#define COMM_MAX_NUMBER_OF_STATES           5U
/*! @brief State and sub-state of ComM state machine */
typedef uint8 ComM_StateType;

#endif /* COMM_TYPES_H */

/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/

