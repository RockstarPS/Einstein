/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2020. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
* File Name         :  DisplayCdd_Types.h                                      *
* Module Short Name :  DisplayCdd_Types                                        *
* Description       :  Header file for DisplayCdd component                    *
*                                                                            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  Turing Platform                                        *
*                                                                            *
******************************************************************************/
#ifndef DISPLAYCDDTYPES_H
#define DISPLAYCDDTYPES_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "DisplayCdd_Cfg.h"
#include "Std_Types.h"

/********************************************************************************************
*  Compiler Switches                                                   
**********************************************************************************************/

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/


#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TIANMA

/*!Used for SPI  Write Bits */
#define DISPLAYCDD_SPIWRITE_BITS_9    0u
#define DISPLAYCDD_SPIWRITE_BITS_18   1u

/*!enum EDisplaypowerStatesHelper defines the different phases of activation */
typedef enum
{
	eDisplayIdleState = 0u,
	eDisplayPowerONStatePinupdate= 1u,
	eDisplayPowerONState = 2u,
	eDisplayPowerOn_PhaseOneState = 3u,
	eDisplayPowerOn_PhaseTwoState = 4u,
	eDisplayPowerNormalState = 5u,
	eDisplayPowerOFFState = 6u,
	eDisplayPowerOff_PhaseOneState = 7u,
	eDisplayPowerOff_CompleteState = 8u,
	eDisplayFaultState = 9u
}EDisplaypowerStatesHelper;

/*
Description: To hold the details related to Display config
*/
typedef struct
{
	EDisplayType			   DisplayDeviceId;                          /* Represent the device ID     				 */
	uint16			           DisplayResetPin;                          /* Represent the device reset pin		         */
	uint16   				   DisplayTouchResetPin;
	uint16			           DisplayFaultStatusPin;                    /*Represent the device fault status pin		 */
	uint8   		       	   SpiSetCommandChannel;            
	uint8			           SpiSetpageChannel;
	uint8 					   SpiSequencewriteChannel;
}SDisplayDB;

#endif

#ifdef CDISPLAYCDD_ENABLE_DISPLAY_SHARP
/*!enum EDisplaypowerStatesHelper defines the different phases of activation */
typedef enum
{
	eDisplaySharp_PowerON_IdleState = 0u,
	eDisplaySharp_PowerON_SupplyPinupdate= 1u,
	eDisplaySharp_PowerON_ResetPinupdate = 2u,
	eDisplaySharp_PowerON_StandbyPinupdate = 3u,
	eDisplaySharp_PowerON_EnableBacklight = 4u,
	eDisplaySharp_NormalState = 5u,
	eDisplaySharp_PowerON_FailDetection = 6u,
	eDisplaySharp_FaultState = 7u
}EDisplaySharpPowerUpStates;

/*!enum EDisplaypowerStatesHelper defines the different phases of activation */
typedef enum
{
	eDisplaySharp_PowerOFF_IdleState = 0u,
	eDisplaySharp_PowerOFFState= 1u,
	eDisplaySharp_PowerOFF_DisableBacklight = 2u,
	eDisplaySharp_PowerOFF_StandbyPinUpdate = 3u,
	eDisplaySharp_PowerOFF_FailDetection = 4u,
	eDisplaySharp_PowerOFF_SupplyResetPinsUpdate = 5u,
	eDisplaySharp_PowerOFFState_Complete = 6u
}EDisplaySharpPowerDownStates;

/*
Description: To hold the details related to Display config
*/
typedef struct
{
	EDisplayType			   DisplayDeviceId;                          /* Represent the device ID     				 */
	uint16 					   DisplaySupplyPin;                         /* Represent the device supply pin		         */
    uint16 					   DisplayResetPin;                          /* Represent the device reset pin		         */
	uint16 					   DisplayStandbyPin;                        /* Represent the device standby pin		     */
	uint16 					   DisplayBacklightPin;                      /* Represent the device backlight pin		     */
	uint16    				   DisplayFaultStatusPin;                    /*Represent the device fault status pin		 */
}SDisplaySharpDB;
#endif

#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TRULY
/*!enum EDisplaypowerStatesHelper defines the different phases of activation */
typedef enum
{
	eDisplayTruly_PowerON_IdleState = 0u,
	eDisplayTruly_PowerON_SupplyPinupdate= 1u,
	eDisplayTruly_PowerON_ResetStandbyPinupdate = 2u,
	eDisplayTruly_PowerON_FailDetPinupdate = 3u,
	eDisplayTruly_PowerON_EnableBacklight = 4u,
	eDisplayTruly_NormalState = 5u,
	eDisplayTruly_PowerON_FailDetection = 6u,
	eDisplayTruly_FaultState = 7u
}EDisplayTrulyPowerUpStates;

/*!enum EDisplaypowerStatesHelper defines the different phases of activation */
typedef enum
{
	eDisplayTruly_PowerOFF_IdleState = 0u,
	eDisplayTruly_PowerOFFState = 1u,
	eDisplayTruly_PowerOFF_DisableBacklight = 2u,
	eDisplayTruly_PowerOFF_StandbyPinUpdate = 3u,
	eDisplayTruly_PowerOFF_FailDetection = 4u,
	eDisplayTruly_PowerOFF_SupplyResetPinsUpdate = 5u,
	eDisplayTruly_PowerOFFState_Complete = 6u
}EDisplayTrulyPowerDownStates;

/*
Description: To hold the details related to Display config
*/
typedef struct
{
	EDisplayType			   DisplayDeviceId;                          /* Represent the device ID     				 */
	uint16 					   DisplaySupplyPin;                         /* Represent the device supply pin		         */
    uint16 					   DisplayResetPin;                          /* Represent the device reset pin		         */
	uint16 					   DisplayStandbyPin;                        /* Represent the device standby pin		     */
	uint16 					   DisplayBacklightPin;                      /* Represent the device backlight pin		     */
	uint16    				   DisplayFaultStatusPin;                    /*Represent the device fault status pin		 */
}SDisplayTrulyDB;
#endif


/*============================================================================
**
**============================================================================
** C M S    R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================*/
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
#endif

/* end of file =============================================================*/

