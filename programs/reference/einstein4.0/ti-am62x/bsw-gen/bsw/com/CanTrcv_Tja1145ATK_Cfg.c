/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2025 by Visteon Corporation.       All rights reserved.                                             *
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
*    @file CanTrcv_Tja1145ATk.c
*    @ingroup CanTrcvConfiguration
*    @brief This is Tja1145ATK CanTrcv Link time configuration source file. It contains definitions of Link time 
*    configuration parameters for the ComM module.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "CanTrcv_Tja1145ATK_Cfg.h"
/********************************************************************************************************************
*  LINK TIME CONFIGURATION GLOBAL CONSTANT                                                                          *
********************************************************************************************************************/
/* @brief Defines the CantrvId to DriverId Tja145ATK HW  */
const uint8 CanTrcv_Tja1145ATK_TrcvToDriverId[CANTRCV_NUM_OF_TRCV_CHANNELS] =
{
    0xFF,   /* Invalid Trcv Index */
    0U      /* Channel Index For CanTrcvTja1145 */
};

/* @brief Defines the configuration for the supported Tja145ATK HW  */
const CanTrcv_Tja1145ATK_SpiCfgType CanTrcv_Tja1145ATK_SpiCfg[CANTRCV_TJA1145ATK_NUM_OF_TRCV_CHANNELS] =
{
    /* Channel 0 configuration */
    {
        2U,
        200U,
        7U
    }
};

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


