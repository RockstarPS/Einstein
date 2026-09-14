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
*    @file EthSM_Lcfg.c
*    @ingroup EthSMConfiguration
*    @brief This is EthSM Link time configuration source file. It contains definitions of Link time configuration
*     parameters for the EthSM module.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "EthSM_Lcfg.h"
/********************************************************************************************************************
* #! GLOBAL VARIABLES                                                                                               *
********************************************************************************************************************/

/********************************************************************************************************************
* #! EthSM const config  data                                                                                       *
********************************************************************************************************************/
/*! @brief Defines the configuration for the Ethernet network-specific parameters of each Ethernet network. 
*   EthSMEthIfControllerId  : EthIf Controller Id
*   EthSMComMNetworkHandle  : the ComM network handle Id
*   EthSMIsEthTrcvAvailable : Trcv supported or not
*   EthSMLinkDownDemEventId : DEM event Id to report bus off errors. Supported if ETHSM_DEM_ERROR_DETECT == STD_ON
*/
const EthSM_NetworkConfigType EthSM_NetworkConfig[ETHSM_NUM_OF_NETWORKS]=
{
    {
        0u
        , 0u
        , TRUE
#if (ETHSM_DEM_ERROR_DETECT == STD_ON)
        ,0u
#endif
    }
};

/*! @brief Defines the configuration for the Ethernet SM configuration 
*   NumOfNetworks  : Number of configured networks 
*   pNetworkConfig : pointer to the configured networks list
*/
const EthSM_ConfigType EthSM_Config =
{
    1u,
    &EthSM_NetworkConfig[0]
};

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


