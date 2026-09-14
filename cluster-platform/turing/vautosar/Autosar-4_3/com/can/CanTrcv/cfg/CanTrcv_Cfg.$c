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
*    @file CanTrcv_Cfg.c
*    @ingroup CanTrcvConfiguration
*    @brief This is CanTrcv Link time configuration source file. It contains definitions of Link time configuration
*     parameters for the CanTrcv module.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComStack_Types.h"
#include "CanTrcv_Cfg.h"
#include "CanTrcv_Tja1040.h"
#include "CanTrcv_Tja1145ATK.h"

/********************************************************************************************************************
*  LINK TIME CONFIGURATION GLOBAL CONSTANT                                                                          *
********************************************************************************************************************/
/* @brief This is the type of the external data structure containing the overall initialization data for the CAN 
    transceiver driver and settings affecting all transceivers. */
const CanTrcv_ConfigType *CanTrcv_ConfigPtr = NULL_PTR;

/* @brief This defines the Can Transciver channel configuration */
const CanTrcv_ChannelCfgType CanTrcv_ChannelCfg[CANTRCV_NUM_OF_TRCV_CHANNELS]=
{
		{
			TRUE,
			0U,
			0U,
			CANTRCV_TRCVMODE_NORMAL
		},
		{
			TRUE,
			1U,
			1U,
			CANTRCV_TRCVMODE_NORMAL
		}
};

/* @brief This defines the Can Transciver HW functions configuration */
const CanTrcv_HWFunctCfgType CanTrcv_HWFunctCfg[CANTRCV_NUM_OF_HW_SUPPORTED]=
{
		{
				&CanTrcv_Tja1040_Init,
				&CanTrcv_Tja1040_SetOpMode,
				&CanTrcv_Tja1443_GetOpMode,
				&CanTrcv_Tja1040_GetBusWuReason
		},
		{
				&CanTrcv_Tja1145ATK_Init,
				&CanTrcv_Tja1145ATK_SetOpMode,
				&CanTrcv_Tja1145ATK_GetOpMode,
				&CanTrcv_Tja1145ATK_GetBusWuReason
#if (CANTRCV_HW_PN_SUPPORT == STD_ON)
				,&CanTrcv_TJA1145ATK_GetTrcvSystemData,
				&CanTrcv_TJA1145ATK_ClearTrcvWufFlag,
				&CanTrcv_TJA1145ATK_ReadTrcvTimeoutFlag,
				&CanTrcv_TJA1145ATK_ClearTrcvTimeoutFlag,
				&CanTrcv_TJA1145ATK_ReadTrcvSilenceFlag,
				NULL,
				&CanTrcv_TJA1145ATK_CheckWakeFlag
#endif
		}
};

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
