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
*    @file CanTrcv_Tja1145ATK_Cfg.h
*    @ingroup CanTrcvConfiguration
*    @brief This is Tja1145ATK CanTrcv Link time configuration source file. It contains definitions of Link time 
*    configuration parameters for the ComM module.
********************************************************************************************************************/
#ifndef CANTRCV_TJA1145ATK_CFG_H
#define CANTRCV_TJA1145ATK_CFG_H

/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "CanTrcv_Tja1145ATK.h"
#include "Spi.h"
#include "CanTrcv_Cfg.h"
#include "CanTrcv_Tja1145ATK_Cfg.h"

/********************************************************************************************************************
*  PUBLIC TYPE DEFINITIONS                                                                                          *
********************************************************************************************************************/
/** @brief Defines the SPI configuration for the supported Tja1145 HW */
typedef struct
{
    Spi_ChannelType SpiChannelId;
    uint8 WufId;
    uint8 WufMask;
} CanTrcv_Tja1145ATK_SpiCfgType;

/********************************************************************************************************************
*   MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
#define CANTRCV_TJA1145ATK_SPI_CHANNEL_ID               2U
#define CANTRCV_TJA1145ATK_NUM_OF_TRCV_CHANNELS         1U
#define CANTRCV_TJA1145ATK_INVALID_CHANNEL_ID           0xFFU
/********************************************************************************************************************
*  PUBLIC VARIABLE AND CONSTANT DECLARATION                                                                         *
********************************************************************************************************************/
/* @brief Defines the CantrvId to DriverId Tja145ATK HW  */
extern const uint8 CanTrcv_Tja1145ATK_TrcvToDriverId[CANTRCV_NUM_OF_TRCV_CHANNELS];
/* @brief Defines the configuration for the supported Tja145ATK HW  */
extern const CanTrcv_Tja1145ATK_SpiCfgType CanTrcv_Tja1145ATK_SpiCfg[CANTRCV_TJA1145ATK_NUM_OF_TRCV_CHANNELS];

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
#endif/* CANTRCV_TJA1145_CFG_H */

