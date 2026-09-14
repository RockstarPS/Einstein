//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2026] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef _BACKLIGHTDRVCDD_H_
#define _BACKLIGHTDRVCDD_H_

//=====================================================================================================================
//  INCLUDED FILES
//=====================================================================================================================
#include "BacklightCdd_Types.h"
#include "BacklightDrvCdd.h"



//------------------------------------------------------------------------------------------------------------------------
// Backlight CDD driver states
//------------------------------------------------------------------------------------------------------------------------

typedef enum
{
    BACKLIGHTDRVCDD_STATE_IDLE = 0u,
    BACKLIGHTDRVCDD_STATE_POWER_ON,
	BACKLIGHTDRVCDD_STATE_POWER_OFF,
    BACKLIGHTDRVCDD_STATE_POWER_ON_WAIT,
	BACKLIGHTDRVCDD_STATE_CONFIGURE,
	BACKLIGHTDRVCDD_STATE_NORMAL,
	BACKLIGHTDRVCDD_STATE_OV_UV_PROTECTION,
	BACKLIGHTDRVCDD_STATE_FAULTDIAG,
	BACKLIGHTDRVCDD_STATE_SAFETYREACTION,
    BACKLIGHTDRVCDD_STATE_ERROR,
	BACKLIGHTDRVCDD_STATE_ERRORRECOVERY,
    BACKLIGHTDRVCDD_STATE_SAFE,
	BACKLIGHTDRVCDD_STATE_PERMANENT_SAFESTATE
}BacklightDrvCdd_OpStateType;


typedef enum
{
	BACKLIGHTCDD_INIT_REGCFG_NOTSTARTED = 0,
	BACKLIGHTCDD_INIT_REGCFG_INPROGRESS,
	BACKLIGHTCDD_INIT_REGCFG_ERROR,
	BACKLIGHTCDD_INIT_REGCFG_SUCCESS,
	BACKLIGHTCDD_INIT_REGCFG_MAXSTATE,
    BACKLIGHTCDD_REG_WRITE_SUCCESS,
    BACKLIGHTCDD_REG_WRITE_ERROR

} BACKLIGHTCDD_InitRegCfgStateType;

typedef struct 
{
	void (*CalcDutyRegisters) (uint16 targetBrightness, uint8* txBuf);

}BacklightChipType;

//=====================================================================================================================
//  PREPROCEESSORS
//=====================================================================================================================

/* Dim Freq = 305Hz, Period = 3.278ms (1/305), 100% duty ON = 0x10025 (3.278msec / 50nsec) */
#define BACKLIGHTMGRCDD_PWM_BIT_RESOLUTION		(uint32)(0x10025)

/** \brief MACRO for indicating 0*/
#define BACKLIGHTDRVCDD_ZERO                              (0U)

/** \brief MACRO for indicating 1*/
#define BACKLIGHTDRVCDD_ONE                              (1U)

/** \brief MACRO for indicating 2*/
#define BACKLIGHTDRVCDD_TWO                               (2U)

/** \brief MACRO for indicating 3*/
#define BACKLIGHTDRVCDD_THREE                             (3U)

/** \brief MACRO for indicating 4*/
#define BACKLIGHTDRVCDD_FOUR                              (4U)

/** \brief MACRO for indicating 6*/
#define BACKLIGHTDRVCDD_SIX                               (6U)

/** \brief MACRO for indicating 10*/
#define BACKLIGHTDRVCDD_TEN                               (10U)

/** \brief MACRO for indicating 10*/
#define BACKLIGHTDRVCDD_FIFTEEN                           (15U)

/** \brief MACRO for indicating 100*/
#define BACKLIGHTDRVCDD_HUNDRED                           (100U)

//=====================================================================================================================
//  UNINITIALIZED DATA DECLARATIONS(.BSS)
//=====================================================================================================================

#define CBacklightCdd_START_SEC_CODE
#include "MemMap.h"

//======================================================================================================================
/** \brief BacklightDrvCdd_Init
 **
 ** This function initializes EcuPowerM.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, CBacklightCdd_CODE) BacklightDrvCdd_Init(void);

//======================================================================================================================
/** \brief BacklightDrvCdd_DeInit
 **
 ** This function initializes EcuPowerM.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, CBacklightCdd_CODE) BacklightDrvCdd_DeInit(void);


//======================================================================================================================
/** \brief BacklightDrvCdd_MainFunction
 **
 ** This function initializes .
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, CBacklightCdd_CODE) BacklightDrvCdd_MainFunction(void);

//======================================================================================================================
/** \brief BacklightDrvCdd_EnterSafeState
 **
 ** This function initializes .
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, CBacklightCdd_CODE) BacklightDrvCdd_EnterSafeState(void);

//======================================================================================================================
/** \brief BacklightDrvCdd_ExitSafeState
 **
 ** This function initializes .
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, CBacklightCdd_CODE) BacklightDrvCdd_ExitSafeState(void);

//======================================================================================================================
/** \brief BacklightDrvCdd_SetBrightness
 **
 ** This function updated Backligh driver pwm duty.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(Std_ReturnType, CBacklightCdd_CODE) BacklightDrvCdd_SetBrightness
(
	VAR(uint8, AUTOMATIC)deviceId, 
	VAR(uint16, AUTOMATIC)duty
);

//======================================================================================================================
/** \brief BacklightDrvCdd_RequestPower
 **
 ** This function initializes Backlight driver power up/down sequence.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(Std_ReturnType, CBacklightCdd_CODE) BacklightDrvCdd_RequestPower
(
	VAR(uint8, AUTOMATIC)deviceId, 
	VAR(BacklightDrvCdd_PwrStType, AUTOMATIC)state
);

//======================================================================================================================
/** \brief BacklightDrvCdd_GetStatus
 **
 ** This function returns device current status.
 **
 ** \param[in] device        device Id.
 **    
 **
 ** \return    DeviceStatus  Current status of device  
 **            
 **
 ** */
//======================================================================================================================
FUNC(EDeviceStatus, CBacklightCdd_CODE) BacklightDrvCdd_GetStatus
(
	VAR(uint8, AUTOMATIC)deviceId
);

#define CBacklightCdd_STOP_SEC_CODE
#include "MemMap.h"

#endif

/**********************************************************************************************************************************************
*                                 END OF FILE                                                                      
***********************************************************************************************************************************************/

/*---------------------------------------------------------------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------------------------------------------------------------*/
/*==============================================================================================================================================
Date              	: 03-12-25
CDSID             	: yviswana
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/
/*==============================================================================================================================================
Date              	: 03-17-26
CDSID             	: bmahesan
Traceability      	: ASCDD-241
Change Description	: Updated Version for MAX20446B/LP8867.
================================================================================================================================================*/


