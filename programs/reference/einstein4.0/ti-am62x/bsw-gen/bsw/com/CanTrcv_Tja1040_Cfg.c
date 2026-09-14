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
*    @file CanTrcv_Tja1040_Cfg.c
*    @ingroup CanTrcvConfiguration
*    @brief This is Tja1040 CanTrcv Link time configuration source file. It contains definitions of Link time 
*    configuration parameters for the ComM module.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "CanTrcv_Tja1040_Cfg.h"

/********************************************************************************************************************
*  LINK TIME CONFIGURATION GLOBAL CONSTANT                                                                          *
********************************************************************************************************************/

/* @brief Defines the configuration for the supported Tja1040 HW  */
const CanTrcv_Tja1040_PinCfgType CanTrcv_Tja1040_PinCfg[CANTRCV_TJA1040_NUM_OF_CHANNELS]=
{
	{
		DioConf_DioChannel_MCU_GPIO0_B01_Ch11
	}
};

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


