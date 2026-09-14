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
* File Name         :  LinIf                                              *
* Module Short Name :  LinIf                                                 *
* Description       :  Header file for LinIf component                      *
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
#ifndef LINIF_H
#define LINIF_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "Std_Types.h"
#include "LinIf_Types.h"
#include "EcuM_Types.h"
#include "ComStack_Types.h"
#include "ComM_Types.h"
#include "Lin_GeneralTypes.h"
#include <string.h>
#include "LinTrcv.h"
#include "LinSm.h"
/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/


/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

/* Component version information (decimal version of ALM implementation package) */
# define LINIF_SW_MAJOR_VERSION                     (1u)
# define LINIF_SW_MINOR_VERSION                     (0u)
# define LINIF_SW_PATCH_VERSION                     (0u)

/* Vendor and module identification */
# define LINIF_VENDOR_ID                            (0u)
# define LINIF_MODULE_ID                            (0u)
/** @name Service id's */

/* Autosar Release */
/*! Defines the AUTOSAR LinIf Release major version */
#define LINIF_AR_RELEASE_MAJOR_VERSION                4U
/*! Defines the AUTOSAR LinIf Release major version */
#define LINIF_AR_RELEASE_MINOR_VERSION                3U
/*! Defines the AUTOSAR LinIf Release patch version */
#define LINIF_AR_RELEASE_REVISION_VERSION             1U

//@{
#define LINIF_INIT_SERVICE_ID               0x00U
#define LINIF_GETVERSIONINFO_SERVICE_ID     0x03U
#define LINIF_SCHEDULEREQUEST_SERVICE_ID    0x05U
#define LINIF_GOTOSLEEP_SERVICE_ID    		0x06U
#define LINIF_WAKEUP_SERVICE_ID     		0x07U
#define LINIF_MAINFUNCTION_SERVICE_ID       0x80U
#define LINIF_GETTRCVMODE_SERVICE_ID        0x09U
#define LINIF_SETTRCVMODE_SERVICE_ID        0x0AU
# define LINIF_SID_WAKEUPCONFIRMATION       0x61u
# define LINIF_SID_CHECKWAKEUP              0x60u
#define LINIF_DEV_ERROR_REPORT              STD_OFF
# define LINIF_INSTANCE_ID_DET                      (0x00u)

#define LINIF_TRANSMIT                   0x41U

#define LINIF_GETTRCVWAKEUPREASON        0x0AU

#define LINIF_SID_SETTRCVWAKEUPMODE    0x0BU


//@}

/** @name Error Codes */
//@{
#define LINIF_E_UNINIT                      0x00
#define LINIF_E_ALREADY_INITIALIZED         0x10
#define LINIF_E_NONEXISTENT_CHANNEL         0x20
#define LINIF_E_PARAMETER                   0x30
#define LINIF_E_PARAMETER_POINTER           0x40
#define LINIF_E_SCHEDULE_OVERFLOW           0x50
#define LINIF_E_SCHEDULE_REQUEST_ERROR      0x51
#define LINIF_E_RESPONSE                    0x60
#define LINIF_E_NC_NO_RESPONSE              0x61
#define LINIF_E_TRCV_INV_MODE               0x53U
#define LINIF_E_TRCV_NOT_NORMAL             0x54U
#define LINIF_E_PARAM_WAKEUPSOURCE          0x55U
//@}

//=====================================================================================================================
//  PUBLIC API DECLARATIONS
//=====================================================================================================================

//---------------------------------------------------------------------------------------------------------------------
/// @brief LinIf_Init 
/// @param LinIf_ConfigType *ConfigPtr - Pointer to the Configuration Structure.always pass this parameter as NULL.
/// @Description Initializes the LIN Interface.
/// @return void
///<br>
//---------------------------------------------------------------------------------------------------------------------
void LinIf_Init( const LinIf_ConfigType* ConfigPtr );
//---------------------------------------------------------------------------------------------------------------------
/// @brief LinIf_DeInit 
/// @param void
/// @Description Deintializes the LIN If module 
/// @return void
///<br>
//---------------------------------------------------------------------------------------------------------------------
void LinIf_DeInit(void);
//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_SchedulerControl
/// @param : NetworkHandleType Channel - Identification of the LIN channel.
/// @Description : The function enables/disables the schedule table processing.
///<br>
//---------------------------------------------------------------------------------------------------------------------
void LinIf_SchedulerControl(NetworkHandleType Channel,boolean CtrlStatus);
//---------------------------------------------------------------------------------------------------------------------
/// @brief LinIf_ScheduleRequest 
/// @param NetworkHandleType Channel - Channel index. 
///        LinIf_SchHandleType NewScheduleRequest - Identification of the new schedule to be set. 
/// @Description To request a new schedule change. 
/// @return Std_ReturnType - E_OK: Schedule table request has been accepted. 
/// E_NOT_OK: Schedule table switch request has not been accepted due to one of the following reasons: - 
/// LIN Interface has not been initialized - referenced channel does not exist (identification is out of range) 
/// referenced schedule table does not exist (identification is out of range) -
/// State is sleep
/// Note: this function shall be called only after LinIf modules ins initialized using LinIf_Init
///<br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType LinIf_ScheduleRequest(NetworkHandleType Channel, LinIf_SchHandleType NewScheduleRequest);
//---------------------------------------------------------------------------------------------------------------------
/// @brief LinIf_SetTrcvMode 
/// @param NetworkHandleType Channel - Identification of the LIN channel 
///        LinTrcv_TrcvModeType TransceiverModePtr - pointer to a memory location where output value will be stored.   
/// @Description Set the given LIN transceiver to the given mode. 
/// @return Std_ReturnType - E_OK: Will be returned, if the transceiver state has been changed to the requested mode.. 
/// E_NOT_OK: Will be returned, if the transceiver state change has failed or the parameter is out of the allowed range. 
/// The previous state has not been changed.
///<br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType LinIf_SetTrcvMode( NetworkHandleType Channel, LinTrcv_TrcvModeType TransceiverMode );
//---------------------------------------------------------------------------------------------------------------------
/// @brief LinIf_GetTrcvMode 
/// @param NetworkHandleType Channel - Identification of the LIN channel 
///        LinTrcv_TrcvModeType* TransceiverModePtr - pointer to a memory location where output value will be stored.   
/// @Description To get the current lin transceiver mode. 
/// @return Std_ReturnType - E_OK: The call of the LIN Transceiver Driver's API service has returned E_OK. 
/// E_NOT_OK: The call of the LIN Transceiver Driver's API service has returned E_NOT_OK or 
/// channel parameter is invalid or pointer is NULL.
///<br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType LinIf_GetTrcvMode( NetworkHandleType Channel, LinTrcv_TrcvModeType* TransceiverModePtr );
//---------------------------------------------------------------------------------------------------------------------
/// @brief LinIf_MainFunction 
/// @param void
/// @Description This is the main processing function for LIN if module. 
///              This funcion will be shall be invoked periodically.
///              LinIf_MainFunction is resposible for transmitting Sleep/wake Up, Unconditonal frames. 
/// @return void
/// Note: this function shall be called only after LinIf modules ins initialized using LinIf_Init
///<br>
//---------------------------------------------------------------------------------------------------------------------
void LinIf_MainFunction(void);
//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_GotoSleep
/// @param : NetworkHandleType Channel - Identification of the LIN channel.
/// @Description : The function LinIf_GotoSleep initiates a transition into sleep mode on the selected
///                channel/controller.
/// @return : Std_ReturnType - E_OK: Request to go to sleep has been accepted 
///           or sleep transition is already in progress or controller is already in sleep state.
///           E_NOT_OK: Request to go to sleep has not been accepted due to one or more of the following reasons: 
///           LIN Interface has not been initialized - 
///           referenced channel does not exist (identification is out of range)
///<br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType LinIf_GotoSleep(NetworkHandleType Channel);
//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_Wakeup
/// @param : NetworkHandleType Channel - Identification of the LIN channel.
/// @Description : The function LinIf_GotoSleep initiates a transition into sleep mode on the selected
///                channel/controller.
/// @return : Std_ReturnType - E_OK: Request to wake up has been accepted or the controller is not in sleep state. 
///           E_NOT_OK: Request to wake up has not been accepted due to one or more of the following reasons: 
///           LIN Interface has not been initialized - 
///           referenced channel does not exist (identification is out of range)
///           Lin_Wakeup has returned E_NOT_OK
///<br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType LinIf_WakeUp(NetworkHandleType Channel);




/* -----------------------------------------------------------------------------------------------------------
*     Service name:       LinIf_CancelTransmit Syntax:
*     Service ID[hex]:    0x0c 
*     Parameters (in):    LinTxPduId
*     Parameters (inout): None 
*     Parameters (out):   None 
*     Return value:       Std_ReturnType E_NOT_OK: Cancel Transmit request has not been accepted. 
---------------------------------------------------------------------------------------------------------------*/
Std_ReturnType LinIf_CancelTransmit( PduIdType LinTxPduId );




/*------------------------------------------------------------------------------
* 
* Service name:    LinIf_Transmit
* Syntax:          Std_ReturnType LinIf_Transmit( PduIdType LinTxPduId, const PduInfoType* PduInfoPtr )
* Service ID[hex]: 0x04
*  Sync/Async:     Asynchronous 
* Reentrancy:      Non Reentrant 
* Parameters (in): LinTxPduId -  Upper layer identification of the LIN frame to be transmitted (not the LIN protected ID).
*                                  This parameter is used to determine the corresponding LIN protected ID (PID) and implicitly the 
* 								 LIN Driver instance    as well as the corresponding LIN Controller device. 
*                   PduInfoPtr  - Pointer to a structure with frame related data: DLC and pointer to frame data buffer. 
* 				                This parameter is not used by this call. 
*  Parameters (inout): None
*  Parameters (out):   None
*  Return value:      Std_ReturnType   - E_OK: Transmit request has been accepted. 
*                                      -  E_NOT_OK: Transmit request has not been accepted due to one or more of the following reasons: 
* 								       - LIN Interface has not been initialized 
* 									   - referenced PDU does not exist (identification is out of range) 
* 									   - NULL_SCHEDULE is set 
*  Description:       Indicates a request.
*/
Std_ReturnType LinIf_Transmit( PduIdType LinTxPduId, const PduInfoType* PduInfoPtr );


/*
* Service name:         LinIf_GetTrcvWakeupReason 
* Syntax:                Std_ReturnType LinIf_GetTrcvWakeupReason( NetworkHandleType Channel, LinTrcv_TrcvWakeupReasonType* TrcvWuReasonPtr )
* Service ID[hex]:        0x0a
* Sync/Async:           Synchronous 
*  Reentrancy:           Reentrant 
* Parameters (in):       Channel - Identification of the LIN channel 
* Parameters (inout):    None 
* Parameters (out):      TrcvWuReasonPtr - Pointer to a memory location where output value will be stored.
* Return value: -        Std_ReturnType - E_OK: The call of the LIN Transceiver Driver's API service has returned E_OK. 
 *                                        E_NOT_OK: The call of the LIN Transceiver Driver's API service has returned E_NOT_OK or
 *                                         channel parameter is invalid or pointer is NULL.
* Description:      Returns the reason for the wake up that has been detected by the LIN Transceiver Driver.
*/
Std_ReturnType LinIf_GetTrcvWakeupReason( NetworkHandleType Channel, LinTrcv_TrcvWakeupReasonType* TrcvWuReasonPtr );

/*
* Service name: LinIf_SetTrcvWakeupMode 
* Syntax: Std_ReturnType LinIf_SetTrcvWakeupMode( NetworkHandleType Channel,
* LinTrcv_TrcvWakeupModeType LinTrcvWakeupMode ) 
* Service ID[hex]: 0x0b 
* Sync/Async: Synchronous
* Reentrancy: Reentrant
*  Parameters (in): Channel - Identification of the LIN channel
*                   LinTrcvWakeupMode - Requested transceiver wake up reason.
*  Parameters (inout): None 
*  Parameters (out): None
*   Return value:  Std_ReturnType E_OK: The call of the LIN Transceiver Driver's API service has returned E_OK.
*                                E_NOT_OK: The call of the LIN Transceiver Driver's API service has returned E_NOT_OK or channel or mode parameter is invalid.
*  Description: This API enables, disables and clears the notification for wakeup events on the addressed network
*/
Std_ReturnType LinIf_SetTrcvWakeupMode( NetworkHandleType Channel,LinTrcv_TrcvWakeupModeType LinTrcvWakeupMode );

/***********************************************************************************************************************
 *  LinIf_GetVersionInfo()
 **********************************************************************************************************************/
/*!
Service name: LinIf_GetVersionInfo 
 Service ID[hex]: 0x03 
 Sync/Async: Synchronous
 Reentrancy: Reentrant
Parameters (in): None 
Parameters (inout): None
 Parameters (out): versioninfo Pointer to where to store the version information of this module. 
 Return value: None 
 Description: Returns the version information of this module.
 */
void LinIf_GetVersionInfo( Std_VersionInfoType* versioninfo );


/***********************************************************************************************************************
 *  LinIf_WakeupConfirmation()
 ********************************************************************************************************************
* Service name:LinIf_WakeupConfirmation 
* Syntax: void LinIf_WakeupConfirmation( EcuM_WakeupSourceType WakeupSource ) 
* Service ID[hex]:0x61 
* Sync/Async: Synchronous 
* Reentrancy:Reentrant 
* Parameters (in): WakeupSource Source device which initiated the wakeup event: LIN controller or LIN transceiver 
*  Parameters (inout): None 
* Parameters (out): None 
* Return value: None 
*  Description: The LIN Driver or LIN Transceiver Driver will call this function to report the wake up source after the successful wakeup detection during CheckWakeup or after power on by bus.
 */
void LinIf_WakeupConfirmation( EcuM_WakeupSourceType WakeupSource );





/*Check Whether the Lin Driver Wakeup support or Lin Transceiver wakeup support is enabled or not*/
#if ( LINIF_LIN_CHANNEL_WAKEUP_SUPPORT == STD_ON ) || ( LINIF_LINTRCV_WAKEUP_SUPPORT == STD_ON )
/***********************************************************************************************************************
 *  LinIf_CheckWakeup()
 **********************************************************************************************************************
* Service name: LinIf_CheckWakeup 
* Syntax: Std_ReturnType LinIf_CheckWakeup( EcuM_WakeupSourceType WakeupSource ) 
* Service ID[hex]: 0x60
*   Sync/Async: Synchronous
*    Reentrancy: Reentrant 
*    Parameters (in): WakeupSource - Source device, which initiated the wakeup event: LIN controller or LIN transceiver
*  Parameters (inout): None
* Parameters (out): None
*  Return value: Std_ReturnType  E_OK: No error has occurred during execution of the API 
*                               E_NOT_OK: An error has occurred during execution of the API or invalid WakeupSource 
* Description: Will be called when the EcuM has been notified about a wakeup on a specific LIN channel.
 */
Std_ReturnType LinIf_CheckWakeup( EcuM_WakeupSourceType WakeupSource );
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
**============================================================================
**============================================================================
**Date               : 10-APRIL-2019
**CDSID              : MKANNAN2
**Traceability       : RTC 
**Change Description :   Implement a API's LinIf_GetTrcvWakeupReason,LinIf_SetTrcvWakeupMode,LinIf_CancelTransmit
						 LinIf_CheckWakeup,LinIf_WakeupConfirmation
**============================================================================
**============================================================================
**Date               : 04-SEP-2019
**CDSID              : BPANNEER
**Traceability       : RTC #1352138 and 1352141
**Change Description : 1. Added function descriptions.
                       2. Removed Macro definition related versions
                       3. Removed all the extern functions 
**============================================================================
**============================================================================
**Date               : 26-July-2019
**CDSID              : BPANNEER
**Traceability       : RTC #1285296
**Change Description : Initial Version.
**============================================================================*/
#endif // LinIf_H
