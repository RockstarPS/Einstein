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
*    @file CanTrcv_Tja1443_Cfg.h
*    @ingroup CanTrcvConfiguration
*    @brief This is CanTrcv Tja1443 Pre-compile time configuration header file. It contains definitions of
*    pre-compile time configuration parameters for the CanTrcv module.
********************************************************************************************************************/
#ifndef CANTRCV_TJA1040_CFG_H
#define CANTRCV_TJA1040_CFG_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComStack_Types.h"
#include "CanTrcv_GeneralTypes.h"
#include "CanTrcv_Cfg.h"
#include "Dio.h"

/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/*! @brief Defines whether the bus wakup feature is used */
#define CANTRCV_TJA1040_WAKEUP_BY_BUS_USED 	STD_OFF
/*! @brief Defines the number of channels used */
#define CANTRCV_TJA1040_NUM_OF_CHANNELS 	1U


/********************************************************************************************************************
*  PUBLIC TYPE DEFINITIONS                                                                                          *
********************************************************************************************************************/
/*! @brief Defines the type of CanTrcv Tja1040 configuration */
typedef struct
{
    /*! Defines the  stb pin DIO channel Id*/
	Dio_ChannelType CanTrcv_Tja1040_StbPin;
#if(CANTRCV_TJA1040_WAKEUP_BY_BUS_USED == STD_ON)
    /*! Defines the CAN Rx pin DIO channel Id*/
	Dio_ChannelType CanTrcv_Tja1040_RxPin;
#endif
}CanTrcv_Tja1040_PinCfgType;
/********************************************************************************************************************
*  PUBLIC VARIABLE AND CONSTANT DECLARATION                                                                         *
********************************************************************************************************************/
/* @brief Defines the configuration for the supported Tja1040 HW  */
extern const CanTrcv_Tja1040_PinCfgType CanTrcv_Tja1040_PinCfg[CANTRCV_TJA1040_NUM_OF_CHANNELS];

#endif /* CANTRCV_TJA1040_CFG_H */

