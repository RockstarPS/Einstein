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
*    @file CanSM_Lcfg.h
*    @ingroup CanSMConfiguration
*    @brief This is CanSM link time configuration header file. It contains definitions of link time
*    configuration parameters for the CanSM module.
*    @defgroup CanSMConfiguration
*    @brief This contains the link time configurations for the CanSM module.
********************************************************************************************************************/
#ifndef CANSM_LCFG_H
#define CANSM_LCFG_H
/********************************************************************************************************************
* #! GLOBAL VARIABLES                                                                                               *
********************************************************************************************************************/
#define CANSM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/*! @brief Defines the network Status */
extern VAR(CanSM_NetworkInfoType,CANSM_VAR_NOINIT) CanSM_NetworkInfo[CANSM_NUM_OF_NETWORKS];

#define CANSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#define CANSM_START_SEC_VAR_NO_INIT_8
#include "MemMap.h"

#if (CANSM_GET_BUS_OFF_DELAY_FUNCTION == STD_ON)
/*! @brief Defines the network user bufoff delay cycles */
extern VAR(uint8,CANSM_VAR_NOINIT) CanSM_UserBusOffDelay[CANSM_NUM_OF_NETWORKS];    
#endif

#define CANSM_STOP_SEC_VAR_NO_INIT_8
#include "MemMap.h"

/********************************************************************************************************************
* #! CanSM const config  data                                                                                        *
********************************************************************************************************************/
#define CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/*! @brief supported network specific configurations of each CAN network 
    Elements                    : Description
    BorCounterL1ToL2            : defines the count of bus-offs until the bus-off recovery switches from
                                  level 1 (short recovery time) to level 2 (long recovery time)
    BorTimeL1                   : time parameter defines in ms the duration of the bus-off recovery time 
                                  in level 1 (short recovery time)
    BorTimeL2                   : time parameter defines in ms the duration of the bus-off recovery 
                                  time in level 2 (long recovery time)
    BorTimeTxEnsured            : the duration of the bus-off event check.
    BorTxConfirmationPolling    : shall configure, if the CanSM polls the CanIf_GetTxConfirmationState API to 
                                  decide the bus-off state to
    EnableBusOffDelay           : defines if the <User_GetBusOffDelay> shall be called for this network.
    UserGetBusOffDelayFunctPtr  : defines the call out function which returns the number of CanSM base cycles to 
                                  wait additionally to L1/L2 after a BusOff occurred
    UserGetBusOffEndFunctPtr    : defines the call out function notifies the bus-off end 
    BoEventId                   : defines the DEM event Id used to report bus off errors for this CAN network
                                  CANSM_E_BUS_OFF
 */
extern CONST(CanSM_BusOffConfigType,CANSM_CONFIG_DATA) CanSM_BusOffConfig[CANSM_NUM_OF_BUS_OFF_CONFIGURATIONS];

/*! @brief supported Bus off configurations 
    Elements        : Description
    ControllerId    : ID of the CAN Controller assigned to the configured network handle    
    TransceiverId   : ID of the CAN transceiver assigned to the configured network handle
    BusOffId        : ID of the Bus off configuration 
*/
extern CONST(CanSM_NetworkConfigType,CANSM_CONFIG_DATA) CanSM_NetworkConfig[CANSM_NUM_OF_NETWORKS];
/*! @brief It defines the mapping between the ComM channel and CanSM channel */
extern CONST(NetworkHandleType,CANSM_CONFIG_DATA) CanSM_ComMToCanSMChannelMapping[CANSM_COMM_NUM_OF_NETWORKS];
#define CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#endif /* CANSM_LCFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
