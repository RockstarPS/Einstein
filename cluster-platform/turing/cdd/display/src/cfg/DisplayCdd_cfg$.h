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
*    @file DisplayCdd_cfg.h
*    @ingroup Display CDD Configuration
*    @brief This is Display Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Display module.
********************************************************************************************************************/
#ifndef DISPLAYCDD_CFG_H
#define DISPLAYCDD_CFG_H


#include "std_types.h"
#include "Rte_DisplayCdd.h"

#include "Dio.h"
#include "Spi.h"

/********************************************************************************************
*  Total number of backlight chip config                                                    
**********************************************************************************************/
/*!  Macro to inform the Display cdd about total number of Display config  in program */
#define cDISPLAYCDD_MAX_DEVICE							e_DisplayMaxDevice
	

/*!  Macro to map the  inital device status */
#define cDISPLAYCDD_INIT_DEVICE_STATUS			        eDisplayNotReady

/*!  Macro to map the  Initial power state*/
#define cDISPLAYCDD_INIT_POWER_STATE			        eDisplayIdle

/*!  Macro to map the  Initial power state*/
#define cDISPLAYCDD_MAX_POWERSTATES			            eDisplayMaxPowerState

/*!  Macro to map the  first deive*/
#define cDISPLAYCDD_DEVICE_1	                         (uint8)e_Display8Inch

/*!  Macro to define the SPI word size*/
#define cDISPLAYCDD_SPI_WORD_SIZE			 DISPLAYCDD_SPIWRITE_BITS_18

/*!  Macro to define the  POWERON_DELAY1
     Runnable - 10ms . Time is 13 * 10 = 130ms*/
#define cDISPLAYCDD_POWERON_DELAY1			 (uint8)13
/*!  Macro to define the POWERON_DELAY2
     Runnable - 10ms . Time is 20 * 10 = 200 ms*/
#define cDISPLAYCDD_POWERON_DELAY2			 (uint8)20
/*!  Macro to define the POWERON_DELAY3 
     Runnable - 10ms . Time is 10 * 10 = 100 ms*/
#define cDISPLAYCDD_POWERON_DELAY3			 (uint8)10


/*!  Macro to define the  POWEROFF_DELAY1 
     Runnable - 10ms . Time is 1 * 10 = 10 ms*/
#define cDISPLAYCDD_POWEROFF_DELAY1			 (uint8)1
/*!  Macro to define the POWEROFF_DELAY2 
     Runnable - 10ms . Time is 10 * 10 = 100 ms*/
#define cDISPLAYCDD_POWEROFF_DELAY2   		 (uint8)10

/*!  Macro to Enable the Bist Test */
#define CDISPLAYCDD_ENABLEBISTTEST

/*!  Macro to Enable the Bist Test */
//#define CDISPLAYCDD_ENABLE_AUTOMATICPOWERON


/*! Map the RTE calls*/
#define DisplayMgrCdd_RTE_TouchCddNotify(x , y)						Rte_Call_tiCS_TITouchCddlNotifyDisplayPower_cTouchCdd_NotifyDisplayPower(x , y)

#define DisplayMgrCdd_RTE_BacklightCddNotify(x , y)					Rte_Call_tiCS_TIBacklightCddlNotifyDisplayPower_cBacklightCddlNotifyDisplayPower(x , y)

#define DisplayMgrCdd_RTE_AppctrlNotify(x , y)					    Rte_Call_tiCS_TIAppCtrlNotifyDisplayPower_CAppCtrl_NotifyDisplayPower(x , y)

#ifdef CDISPLAYCDD_ENABLE_GAMMA_CORRECTION

#define  TFT_Display_ID  ePowerCdd_SubState_TFT

#define DISPLAY_POWER_ON    ePowerCdd_SubStateStatus_ON
#define DISPLAY_POWER_OFF    ePowerCdd_SubStateStatus_OFF

#define Rte_Call_Display_Powerup_Status{x,y)  PowerCdd_GetPowerSubState(x,y)

#define DisplayMgrCdd_RTE_GetDisplayType(x)	  SRV_Cfg_ReadDisplay_Type(x)

#define DisplayMgrCdd_RTE_ReadGammaSettingsFromNvM(x, y, z)	  SRV_Cfg_GetArray(x, y, z)

#endif

/*-------------------------------------------------------------------------------------------------*/
/*                                                                                                 */
/* NAME:         DISPLAY_CONFIG_DB                                                                 */
/*                                                                                                 */
/* TYPE:         Constants of type DISPLAY_CONFIG_DB_ST                                            */
/*                                                                                                 */
/*	uint8			           DisplayDeviceId;                          Represent the device ID     				 */
/*	uint16			           DisplayResetPin;                          Represent the device reset pin		         */
/*	uint16			           DisplayTouchResetPin;                     Represent the device touch reset pin		 */
/*	uint16			           DisplayFaultStatusPin;                    Represent the device fault status pin		 */
/*	uint8   		       	   SpiSetCommandChannel;     										   */       
/*	uint8			           SpiSetpageChannel;												   */
/*	uint8			           SpiSequencewriteChannel;												   */
/* DESCRIPTION:  Backlight config Database                                                         */
/*-------------------------------------------------------------------------------------------------*/
#define DISPLAY_CONFIG_DB\
                          {\
                           e_Display12Inch,\
						   DioConf_DioChannel_DioChannel_DCSD_TFT_RESET,\
						   DioConf_DioChannel_DioChannel_DCSD_TFT_TOUCH_RST,\
						   DioConf_DioChannel_DioChannel_DCSD_TFT_FAIL_DET,\
						   SpiConf_SpiChannel_SpiChannel_SetCmd,\
                           SpiConf_SpiChannel_SpiChannel_SetPageData,\
                           SpiConf_SpiSequence_SpiWriteSequence_DCSD_TFT,\
                          }\
				


/*----------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
Date              : 6/Apr/2020
By                : sgarg1
Traceability      : RTC #
Change Description: Initial Version
-------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 22/June/2020
By                : nrajaman
Traceability      : RTC # 835355
Change Description: Added Power and SPI sequence for 12 inch tianma display. 
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 22/June/2020
By                : nrajaman
Traceability      : RTC # 835355
Change Description: Updated PR comments 
-----------------------------------------------------------------------------------------*/

#endif /* DISPLAYCDD_CFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
