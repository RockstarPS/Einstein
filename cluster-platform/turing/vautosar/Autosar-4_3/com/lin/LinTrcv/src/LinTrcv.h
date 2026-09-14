// ===========================================================================
//
//                     CONFIDENTIAL VISTEON CORPORATION
//
//  This is an unpublished work of authorship, which contains trade secrets,
//  created in 2006.  Visteon Corporation owns all rights to this work and
//  intends to maintain it in confidence to preserve its trade secret status.
//  Visteon Corporation reserves the right, under the copyright laws of the
//  United States or those of any other country that may have jurisdiction, to
//  protect this work as an unpublished work, in the event of an inadvertent
//  or deliberate unauthorized publication.  Visteon Corporation also reserves
//  its rights under all copyright laws to protect this work as a published
//  work, when appropriate.  Those having access to this work may not copy it,
//  use it, modify it or disclose the information contained in it without the
//  written authorization of Visteon Corporation.
//
// =========================================================================
// ===========================================================================
//
//  Name:           LinTrcv.h
//
//  Description:    
//
//  Organization:       Driver Information Core Software,
//                      Visteon Automotive Systems
// =========================================================================
#ifndef LINTRCVCDD_H
#define LINTRCVCDD_H

#include "LinTrcv_Par_Cfg.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Component version information (decimal version of ALM implementation package) */
# define LINTRCV_SW_MAJOR_VERSION                     (1u)
# define LINTRCV_SW_MINOR_VERSION                     (0u)
# define LINTRCV_SW_PATCH_VERSION                     (0u)

/* Vendor and module identification */
# define LINTRCV_VENDOR_ID                            (0u)
# define LINTRCV_MODULE_ID                            (0u)
/** @name Service id's */

/* Autosar Release */
/*! Defines the AUTOSAR LinTrcv Release major version */
#define LINTRCV_AR_RELEASE_MAJOR_VERSION                4U
/*! Defines the AUTOSAR LinTrcv Release minor version */
#define LINTRCV_AR_RELEASE_MINOR_VERSION                3U
/*! Defines the AUTOSAR LinTrcv Release patch version */
#define LINTRCV_AR_RELEASE_REVISION_VERSION             1U

// ===========================================================================
//  P U B L I C   M A C R O S
// =========================================================================
/* Development error codes */
#define LINTRCV_E_NO_ERROR                     0x00U
#define LINTRCV_E_UNINIT                       0x11U
#define LINTRCV_E_PARAM_POINTER                0x02U
#define LINTRCV_E_INVALID_LIN_NETWORK          0x01U
#define LINTRCV_E_PARAM_TRCV_OPMODE            0x24U
#define LINTRCV_E_TRCV_NOT_SLEEP               0x21U
#define LINTRCV_E_PARAM_TRCV_WAKEUP_MODE       0x23U

/* ApiIDs for Error Reporting */
#define LINTRCV_SID_INIT                      0x00u
#define LINTRCV_SID_SETOPMODE                 0x01u
#define LINTRCV_SID_GETOPMODE                 0x02u
#define LINTRCV_SID_GETBUSWUREASON            0x03u
#define LINTRCV_SID_GETVERSIONINFO            0x04u
#define LINTRCV_SID_SETWAKEUPMODE             0x05u
#define LINTRCV_SID_CHECKWAKEUP               0x07u

#define SchM_Enter_LINTRCV_EXCLUSIVE_AREA_0()
#define SchM_Exit_LINTRCV_EXCLUSIVE_AREA_0()
// ===========================================================================
//  P U B L I C   T Y P E   D E F I N I T I O N S
// ===========================================================================
extern const LinTrcv_ChannelUsedType LinTrcv_ChannelUsed[NO_OF_LIN_CHANNEL_USED];
extern const LinTrcv_TrcvModeType LinTrcv_InitState[NO_OF_LIN_CHANNEL_USED];
extern const LinTrcv_DioConfigurationType LinTrcv_DioConfiguration[NO_OF_LIN_CHANNEL_USED];
extern const LinTrcv_Icu_ChannelType LinTrcv_Icu_Channel[NO_OF_LIN_CHANNEL_USED];
extern const LinTrcv_WakeupByBusUsedType LinTrcv_WakeupByBusUsed[NO_OF_LIN_CHANNEL_USED];
extern const LinTrcv_WakeupByPinUsedType LinTrcv_WakeupByPinUsed[NO_OF_LIN_CHANNEL_USED];
extern const LinTrcv_WakeSourceIdType LinTrcv_WakeSourceId[NO_OF_LIN_CHANNEL_USED];

//typedef uint8 LinTrcv_TrcvModeType;
typedef LinTrcv_TrcvWakeupModeType_enum LinTrcv_TrcvWakeupModeType;
typedef LinTrcv_TrcvWakeupReasonType_enum LinTrcv_TrcvWakeupReasonType;
//----------------------------------------------------------------------------------------------------------------------
// NAME:    LinTrcv_Prob_Type       
//                 
// TYPE:    struct       
//                                                                                                                      
// DESCRIPTION: The following type includes LIN transceiver channel specific settings.
//----------------------------------------------------------------------------------------------------------------------

typedef struct
{

  LinTrcv_TrcvModeType LinTrcv_State;
  /* ---- Common attributes ---- */

  /* ! Last detected wakeup reason */
  LinTrcv_TrcvWakeupReasonType LinTrcv_WakeupReason;

  /* ! Specifies whether or not to report wakeups */
  LinTrcv_TrcvWakeupModeType LinTrcv_WakeupMode;

  /* ! HW specific attributes */

} LinTrcv_Prob_Type; 


//----------------------------------------------------------------------------------------------------------------------
// NAME:    LinTrcv_ConfigType       
//                 
// TYPE:    struct       
//                                                                                                                      
// DESCRIPTION: Dummy Structure used in Init Function.
//----------------------------------------------------------------------------------------------------------------------

typedef struct LinTrcv_ConfigType_st
{
    uint8 dummy;
}LinTrcv_ConfigType;


// ===========================================================================
//  P U B L I C   F U N C T I O N   P R O T O T Y P E S
// ===========================================================================
void LinTrcv_Init (LinTrcv_ConfigType *ConfigPtr);
Std_ReturnType LinTrcv_SetOpMode (uint8 LinTrcvIndex, LinTrcv_TrcvModeType OpMode); 
Std_ReturnType LinTrcv_GetOpMode (uint8 LinTrcvIndex,LinTrcv_TrcvModeType *OpMode);
Std_ReturnType LinTrcv_CheckWakeup (uint8 LinTrcvIndex);
Std_ReturnType LinTrcv_SetWakeupMode (uint8 LinTrcvIndex,LinTrcv_TrcvWakeupModeType TrcvWakeupMode);
void LinTrcv_InitMemory (void);
Std_ReturnType LinTrcv_GetBusWuReason(uint8 LinTrcvIndex,  LinTrcv_TrcvWakeupReasonType *Reason);
#endif
/*============================================================================
**Date               : 24-Sep-2019
**CDSID              : ABAVALAT
**Traceability       : 1368881
**Change Description : Coverity fix.
**============================================================================*/
/*============================================================================
**Date               : 22-Jul-2019
**CDSID              : ABAVALAT
**Traceability       : 
**Change Description : Initial Version.
**============================================================================*/
