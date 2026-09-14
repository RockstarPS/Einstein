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
*    @file EthSM_Types.h
*    @ingroup EthSM
*    @brief This file provides the types for the EthSM module.
********************************************************************************************************************/
#ifndef ETHSM_TYPES_H
#define ETHSM_TYPES_H
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

#ifndef ETHSM_CODE
#define ETHSM_CODE
#endif 

#ifndef ETHSM_CONST
#define ETHSM_CONST
#endif  

#ifndef ETHSM_APPL_DATA
#define ETHSM_APPL_DATA
#endif

#ifndef ETHSM_APPL_CONST
#define ETHSM_APPL_CODE
#endif

#ifndef ETHSM_CALLOUT_CODE
#define ETHSM_CALLOUT_CODE
#endif

#ifndef ETHSM_VAR
#define ETHSM_VAR
#endif

#ifndef ETHSM_VAR_INIT
#define ETHSM_VAR_INIT
#endif

#ifndef ETHSM_VAR_NOINIT
#define ETHSM_VAR_NOINIT
#endif

#ifndef ETHSM_VAR_POWER_ON_INIT
#define ETHSM_VAR_POWER_ON_INIT
#endif

#ifndef ETHSM_VAR_FAST
#define ETHSM_VAR_FAST
#endif

#ifndef ETHSM_VAR_SLOW
#define ETHSM_VAR_SLOW
#endif

/* #! EthSM Types */
/*! @brief This type shall define the states of the network mode state machine */
typedef enum
{
    /*! @brief EthSM is initialized in this state. */
    ETHSM_STATE_OFFLINE=0U,
    /*! @brief ComM requests COMM_FULL_COMMUNICATION in this state. Controller and transceiver will be initialized and set to 
        ACTIVE. EthSM waits for transceiver link state (ACTIVE)*/
    ETHSM_STATE_WAIT_TRCVLINK,
    /*! @brief Transceiver link state is ACTIVE EthSM waits for IP communication (TcpIP state = ONLINE) */    
    ETHSM_STATE_WAIT_ONLINE,
    /*! @brief IP communication is available ComM state COMM_FULL_COMMUNICATION is reached */
    ETHSM_STATE_ONLINE, 
    /*! @brief EthSM lost active transceiver link state, TcpIP state is still ONLINE */
    ETHSM_STATE_ONHOLD,
    /*! @brief ComM requests COMM_NO_COMMUNICATION in this state. */
    ETHSM_STATE_WAIT_OFFLINE 
}EthSM_NetworkModeStateType;

#endif /* ETHSM_TYPES_H */


/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
*******************************************************************************************************************/
