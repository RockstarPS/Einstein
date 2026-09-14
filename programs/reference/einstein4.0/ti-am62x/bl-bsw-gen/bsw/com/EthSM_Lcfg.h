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
*    @file EthSM_Lcfg.h
*    @ingroup EthSMConfiguration
*    @brief This is EthSM link time configuration header file. It contains definitions of link time
*    configuration parameters for the EthSM module.
*    @defgroup EthSMConfiguration
*    @brief This contains the link time configurations for the EthSM module.
********************************************************************************************************************/
#ifndef ETHSM_LCFG_H
#define ETHSM_LCFG_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "EthSM_Cfg.h"
/********************************************************************************************************************
* #! GLOBAL VARIABLES                                                                                               *
********************************************************************************************************************/
/********************************************************************************************************************
* #! EthSM const config  data                                                                                       *
********************************************************************************************************************/
/*! @brief Defines the configuration for the Ethernet network-specific parameters of each Ethernet network. */
extern const EthSM_NetworkConfigType EthSM_NetworkConfig[ETHSM_NUM_OF_NETWORKS];
/*! @brief Defines the configuration for the Ethernet SM configuration */
extern const EthSM_ConfigType EthSM_Config;
#endif /* ETHSM_LCFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


