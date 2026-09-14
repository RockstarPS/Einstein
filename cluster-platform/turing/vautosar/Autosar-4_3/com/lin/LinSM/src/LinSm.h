/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2013. Visteon Corporation owns all rights to           *
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
* File Name         :  LinSm                                                 *
* Module Short Name :  LinSM                                                 *
* Description       :  Header file for LinSM component                       *
*                                                                            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :  Turing A                                               *
*                                                                            *
*****************************************************************************/
#ifndef LINSM_H
#define LINSM_H
/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "ComStack_Types.h"
#include "Std_Types.h"
#include "LinSm_Cfg.h"
#include "LinSm_Types.h"
#include "LinSm_PBCfg.h"
#include "LinSm_Cbk.h"
#include "Com_Types.h"
#include "ComM_Types.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Component version information (decimal version of ALM implementation package) */
# define LINSM_SW_MAJOR_VERSION                     (1u)
# define LINSM_SW_MINOR_VERSION                     (0u)
# define LINSM_SW_PATCH_VERSION                     (0u)

/* Vendor and module identification */
# define LINSM_VENDOR_ID                            (0u)
# define LINSM_MODULE_ID                            (0u)
/** @name Service id's */

/* Autosar Release */
/*! Defines the AUTOSAR LinSM Release major version */
#define LINSM_AR_RELEASE_MAJOR_VERSION                4U
/*! Defines the AUTOSAR LinSM Release major version */
#define LINSM_AR_RELEASE_MINOR_VERSION                3U
/*! Defines the AUTOSAR LinSM Release patch version */
#define LINSM_AR_RELEASE_REVISION_VERSION             1U

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

/* --- DET Service Ids  --- */

#define LINSM_INIT_SERVICE_ID 0x01u
#define LINSM_SID_GET_VERSION_INFO 0x02u
#define LINSM_GET_CURRENT_COM_MODE_SERVICE_ID 0x11u
#define LINSM_REQUEST_COM_MODE_SERVICE_ID 0x12u
#define LINSM_SCHEDULE_REQUEST_SERVICE_ID 0x10u
#define LINSM_SCHEDULE_REQUEST_CONF_SERVICE_ID 0x20u
#define LINSM_WAKEUP_CONF_SERVICE_ID 0x21u
#define LINSM_GOTO_SLEEP_CONF_SERVICE_ID 0x22u
#define LINSM_MAIN_FUNCTION_SERVICE_ID 0x30u

/* --- Error codes --- */

#define LINSM_E_UNINIT 0x00u
#define LINSM_E_INIT_FAILED 0x60u
#define LINSM_E_ALREADY_INITIALIZED 0x10u
#define LINSM_E_NONEXISTENT_NETWORK 0x20u
#define LINSM_E_PARAMETER 0x30u
#define LINSM_E_PARAMETER_POINTER 0x40u
#define LINSM_E_CONFIRMATION_TIMEOUT 0x50u /*Assigned by DEM*/
#define LINSM_E_NO_ERROR   0xFFU 
#define LINSM_INSTANCE_ID_DET                     (0x00u)


#if (LINSM_USE_BSW_INTERFACES_CC == STD_ON)
#error LINSM_USE_BSW_INTERFACES_CC Feature is not supported in this version \
Please disable this feature by selecting STD_OFF against LINSM_USE_BSW_INTERFACES_CC \
in LinSm_Cfg.h

#else

#endif

#if (LINSM_USE_COM_INTERFACES_CC == STD_ON)
#error LINSM_USE_COM_INTERFACES_CC Feature is not supported in this version \
Please disable this feature by selecting STD_OFF against LINSM_USE_COM_INTERFACES_CC \
in LinSm_Cfg.h
#endif

//=====================================================================================================================
//  PUBLIC API DECLARATIONS
//=====================================================================================================================
//---------------------------------------------------------------------------------------------------------------------
/// @brief LinSM_Init
/// @param LinSM_ConfigType *ConfigPtr - Pointer to the LinSM post-build configuration data.
/// @Description This function initializes the LinSM.
/// @return void
///<br>
//---------------------------------------------------------------------------------------------------------------------
void LinSM_Init(const LinSM_ConfigType *ConfigPtr);
//---------------------------------------------------------------------------------------------------------------------
/// @brief LinSM_DeInit
/// @param None.
/// @Description This function deinitializes the LinSM.
/// @return void
///<br>
//---------------------------------------------------------------------------------------------------------------------
void LinSM_DeInit(void); /*COVERITY FIX: void for no parameter*/
//---------------------------------------------------------------------------------------------------------------------
/// @brief LinSM_ScheduleRequest
/// @param NetworkHandleType network - Identification of the LIN channel.
///        LinIf_SchHandleType LinSM_schedule - Pointer to the new Schedule table
/// @Description The upper layer requests a schedule table to be changed on one LIN network.
/// @return Std_ReturnType - E_OK - Schedule table request has been accepted.
///         E_NOT_OK - Schedule table switch request has not been accepted due to one of the following reasons:
///         LinSM has not been initialized referenced channel does not exist (identification is out of range)
///         Referenced schedule table does not exist (identification is out of range)
///         Sub-state is not LINSM_FULL_COMMUNICATION
///<br>
//---------------------------------------------------------------------------------------------------------------------

Std_ReturnType LinSM_ScheduleRequest(NetworkHandleType network, LinIf_SchHandleType schedule);
//---------------------------------------------------------------------------------------------------------------------
/// @brief LinSM_GetVersionInfo
/// @param Std_VersionInfoType versioninfo - Identification of the version information
///        
/// @.
/// @return Std_ReturnType - None
///<br>
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
void LinSM_GetVersionInfo( Std_VersionInfoType* versioninfo );
//---------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------
/// @brief LinSM_GetCurrentComMode
/// @param NetworkHandleType network - Identification of the LIN channel.
///        ComM_ModeType* mode - Returns the active mode, see ComM_ModeType for descriptions of the modes
/// @Description Function to query the current communication mode.
/// @return Std_ReturnType - E_OK - Ok E_NOT_OK - Not possible to perform the request.
///<br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType LinSM_GetCurrentComMode(NetworkHandleType network, ComM_ModeType *mode);
//---------------------------------------------------------------------------------------------------------------------
/// @brief LinSM_RequestComMode
/// @param NetworkHandleType network - Identification of the LIN channel.
///        ComM_ModeType mode - Request mode
/// @Description Requesting of a communication mode. The mode switch will not be made instant.
///              The LinSM will notify the caller when mode transition is made..
/// @return Std_ReturnType - E_OK - Ok E_NOT_OK - Not possible to perform the request.
///<br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType LinSM_RequestComMode(NetworkHandleType network, ComM_ModeType mode);
//---------------------------------------------------------------------------------------------------------------------
/// @brief LinSM_MainFunction
/// @param None
/// @Description Periodic function that runs the timers of different request timeouts.
/// @return void.
///<br>
//---------------------------------------------------------------------------------------------------------------------
void LinSM_MainFunction(void);

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
**============================================================================ */
/*============================================================================
**Date               : 15-APR-2020
**CDSID              : BPANDURA
**Traceability       : RTC #724726 #835035 #835036 #835037 #724728
**Change Description : Added LinSM_GetVersionInfo(Std_VersionInfoType* versioninfo) function.
                       Changed LINSM_E_CONFIRMATION_TIMEOUT 0x50u.
                       Added LINSM_VENDOR_ID 0x01u

**============================================================================*/
/*============================================================================
**Date               : 15-SEP-2019
**CDSID              : BPANNEER
**Traceability       : RTC #1285296
**Change Description : .
**============================================================================*/
