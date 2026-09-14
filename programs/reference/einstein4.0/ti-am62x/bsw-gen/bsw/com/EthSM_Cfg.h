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
*    @file EthSM_Cfg.h
*    @ingroup EthSMConfiguration
*    @brief This is EthSM Pre-compile time configuration header file. It contains definitions of pre-compile time 
*    configuration parameters for the EthSM module.
*    @defgroup EthSMConfiguration
*    @brief This contains the configuration files for the EthSM module.
********************************************************************************************************************/
#ifndef ETHSM_CFG_H
#define ETHSM_CFG_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "EthSM_Types.h"

/********************************************************************************************************************
*  #! Precompile Configuration                                                                                      *
********************************************************************************************************************/
/*! @brief  Switches the development error detection and notification on or off.
    true: detection and notification is enabled.
    false: detection and notification is disabled. */
#define ETHSM_DEV_ERROR_DETECT          STD_ON
/*! @brief Disables the API to the EthIf. The API to the ComM is available but the functionality is deactivated.
    The function calls from the ComM will be answered with the return value E_OK. */ 
#define ETHSM_DUMMY_MODE                STD_OFF
/*! @brief Specifies the period in milliseconds that the MainFunction has to be triggered with. 5ms .. 1s*/
#define ETHSM_MAIN_FUNCTION_PERIOD      10
/*! @brief Enables and disables the version info API. */
#define ETHSM_VERSION_INFO_API          STD_ON
/********************************************************************************************************************
*  #! EthSM Internal feature support                                                                                *
********************************************************************************************************************/
/*! @brief Defines the dummy macro */
#ifndef ETHSM_DUMMY_STATEMENT
#define ETHSM_DUMMY_STATEMENT(v)
#endif
/*******************************************************************************************************************
*  #! EthSM module configuration                                                                                   *
*******************************************************************************************************************/
/*! @brief Defines the number of Eth controllers supported */
#define ETHSM_NUM_OF_NETWORKS    1U
/*! @brief Enables/Disables the production error for Link down detection and notification to Dem */
#define ETHSM_DEM_ERROR_DETECT   STD_OFF
/*! @brief Enables/Disables the Ethernet support */
#define ETHSM_ETH_TRCV_SUPPORT   STD_ON
/********************************************************************************************************************
*  #! SW and AUTOSAR Version Macros                                                                                 *
********************************************************************************************************************/
/* Software Version */
/*! @brief Defines the EthSM configuration software Major version */
#define ETHSM_CFG_SW_MAJOR_VERSION                      1u
/*! @brief Defines the EthSM configuration software Minor version */
#define ETHSM_CFG_SW_MINOR_VERSION                      0u
/*! @brief Defines the EthSM configuration software Patch version */
#define ETHSM_CFG_SW_PATCH_VERSION                      0u
/* Autosar Release */
/*! @brief Defines the AUTOSAR Release Major version supported by ComM configuration  */
#define ETHSM_CFG_AR_RELEASE_MAJOR_VERSION              4u
/*! @brief Defines the AUTOSAR Release Minor version supported by ComM configuration  */
#define ETHSM_CFG_AR_RELEASE_MINOR_VERSION              3u
/*! @brief Defines the AUTOSAR Release patch version supported by ComM configuration  */
#define ETHSM_CFG_AR_RELEASE_REVISION_VERSION           1u

/********************************************************************************************************************
* #! EthSM types                                                                                                    *
* #! macro , typedef declaration                                                                                    *
********************************************************************************************************************/
/*! @brief Defines the config type for the Ethernet network-specific parameters of each Ethernet network. */
typedef struct 
{
    /*! @brief EthIf Controller Id */
    uint8               EthSMEthIfControllerId; 
    /*! @brief the ComM network handle Id */
    uint8               EthSMComMNetworkHandle;
    /*! @brief TRCV suppoerted */
    boolean             EthSMIsEthTrcvAvailable; 
#if (ETHSM_DEM_ERROR_DETECT == STD_ON)
    /*! @brief Reference to configured DEM event Id to report bus off errors for this Eth network.*/
    Dem_EventIdType     EthSMLinkDownDemEventId; 
#endif
}EthSM_NetworkConfigType;

/*! @brief Defines the config type for the Ethernet SM configuration */
typedef struct 
{
    uint8                          NumOfNetworks;  /* No of configured networks */
    const EthSM_NetworkConfigType *pNetworkConfig;  /* Pointer to configured networks list */
}EthSM_ConfigType;

#endif /* ETHSM_CFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
*******************************************************************************************************************/
