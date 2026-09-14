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
/*!******************************************************************************************************************
*   @file CanTrcv.h
*   @ingroup CanTrcv
*   @brief This file provides the declaration of the CanTrcv API. This header file should be included by other  
*   modules that use the CanTrcv API.
*   @defgroup CanTrcv
*   @brief The The CAN Transceiver Driver module is responsible for handling the CAN transceiver hardware chips
*   on an ECU. The CAN Transceiver is a hardware device, which adapts the signal levels that are used on the CAN 
*   bus to the logical (digital) signal levels recognised by a microcontroller.The CAN transceiver driver abstracts 
*   the CAN transceiver hardware. It offers a hardware independent interface to the higher layers. It abstracts 
*   from the ECU layout by using APIs of MCAL layer to access the CAN transceiver hardware.
********************************************************************************************************************/
#ifndef CANTRCV_H
#define CANTRCV_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComStack_Types.h"
#include "CanTrcv_Cfg.h"
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/* Software Version */
/*! @brief Defines the CanTrcv SW major version */
#define CANTRCV_SW_MAJOR_VERSION                                0U
/*! @brief Defines the CanTrcv SW minor version */
#define CANTRCV_SW_MINOR_VERSION                                0U
/*! @brief Defines the CanTrcv SW patch version */
#define CANTRCV_SW_PATCH_VERSION                                1U
/* Autosar Release */
/*! @brief Defines the CanTrcv SW major version */
#define CANTRCV_AR_RELEASE_MAJOR_VERSION                        4U    
/*! @brief Defines the CanTrcv SW major version */                      
#define CANTRCV_AR_RELEASE_MINOR_VERSION                        3U                 
/*! @brief Defines the CanTrcv SW major version */                      
#define CANTRCV_AR_RELEASE_REVISION_VERSION                     1U

/********************************************************************************************************************
*  MODULE INFORMATION                                                                                               *
********************************************************************************************************************/
/*! @brief Defines the Vendor Id of CanTrcv module.*/
#define CANTRCV_VENDOR_ID                                          51U
/*! @brief Defines the Module Id of CanTrcv module.*/
#define CANTRCV_MODULE_ID                                          70U
/*! @brief Defines the version Id of CanTrcv module.*/
#define CANTRCV_INSTANCE_ID                                        0U
                                           
/********************************************************************************************************************
*  API ID VALUES                                                                                                    *
********************************************************************************************************************/
/*!@ brief Define the Error Id the CanTrcv APIs */
#define CANTRCV_SID_INIT                        0x00U
#define CANTRCV_SID_SETOPMODE                   0x01U
#define CANTRCV_SID_GETOPMODE                   0x02U               
#define CANTRCV_SID_GETBUSWUREASON              0x03U
#define CANTRCV_SID_GETVERSIONINFO              0x04U
#define CANTRCV_SID_SETWAKEUPMODE               0x05U
#define CANTRCV_SID_GETTRCVSYSTEMDATA           0x09U
#define CANTRCV_SID_CLEARTRCVWUFFLAG            0x0AU
#define CANTRCV_SID_READTRCVTIMEOUTFLAG         0x0BU
#define CANTRCV_SID_CLEARTRCVTIMEOUTFLAG        0x0CU    
#define CANTRCV_SID_READTRCVSILENCEFLAG         0x0DU  
#define CANTRCV_SID_CHECKWAKEUP                 0x07U
#define CANTRCV_SID_SETPNACTIVATIONSTATE        0x0FU    
#define CANTRCV_SID_CHECKWAKEFLAG               0x0EU
#define CANTRCV_SID_MAINFUNCTION                0x06U
#define CANTRCV_SID_MAINFUNCTIONDIAGNOSTICS     0x08U

/********************************************************************************************************************
*  DEVELOPMENT ERRORS VALUES                                                                                        *
********************************************************************************************************************/
/*! @brief It defines no Error for CanTrcv API processing */
#define CANTRCV_E_NO_ERROR                                          0x0U
/*! @brief  API called with wrong parameter for the CAN transceiver */
#define CANTRCV_E_INVALID_TRANSCEIVER                               0x1U
/*! @brief  API called with null pointer parameter */
#define CANTRCV_E_PARAM_POINTER                                     0x2U
/*! @brief  API service used without initialization */
#define CANTRCV_E_UNINIT                                            0x11U
/*! @brief  API service called in wrong transceiver operation mode */
#define CANTRCV_E_TRCV_NOT_STANDBY                                  0x21U
/*! @brief  API service called in wrong transceiver operation mode */
#define CANTRCV_E_TRCV_NOT_NORMAL                                   0x22U
/*! @brief  API service called with invalid parame-ter for TrcvWakeup-Mode */
#define CANTRCV_E_PARAM_TRCV_WAKEUP_MODE                            0x23U
/*! @brief  API service called with invalid parame-ter for OpMode */
#define CANTRCV_E_PARAM_TRCV_OPMODE                                 0x24U
/*! @brief  Configured baud rate is not supported by the transceiver */
#define CANTRCV_E_BAUDRATE_NOT_SUPPORTED                            0x25U
/*! @brief  No/incorrect communication to transceiver. */
#define CANTRCV_E_NO_TRCV_CONTROL                                   0x26U
/*! @brief  Module initialization has failed, e.g. CanTrcv_Init() called with an invalid point-er in postbuild. */
#define CANTRCV_E_INIT_FAILED                                       0x27U
/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
/*!******************************************************************************************************************
*   @brief      This method initializes the Can Transceiver internal variables to default values.
********************************************************************************************************************/
void CanTrcv_InitMemory(void);

/*!******************************************************************************************************************
*   @brief      This method initialize all the connected CAN transceivers based on their initialization sequences 
*               and configuration
*   @param[in]  ConfigPtr  Pointer to the CanTrcv configuration data.
*   @ServiceID  0x00
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
void CanTrcv_Init(const CanTrcv_ConfigType* ConfigPtr);

/*!******************************************************************************************************************
*   @brief      This method sets the mode of the Transceiver to the value OpMode.
*   @param[in]  Transceiver  CAN transceiver to which API call has to be applied.
*   @param[in]  OpMode  This parameter contains the desired operating mode
*   @return     status of the request      
*               - E_OK: will be returned if the request for transceiver mode change has been accepted. 
*               - E_NOT_OK: will be returned if the request for transceiver mode change has not been accepted or any 
*                 parameter is out of the allowed range.
*   @ServiceID  0x01
*   @Sync/Async Asynchronous 
*   @Reentrancy Reentrant for different transceivers
********************************************************************************************************************/
Std_ReturnType CanTrcv_SetOpMode(uint8 Transceiver, CanTrcv_TrcvModeType OpMode);

/*!******************************************************************************************************************
*   @brief      This method gets the mode of the Transceiver and returns it in OpMode.
*   @param[in]  Transceiver  CAN transceiver to which API call has to be applied.
*   @param[out] OpMode  Pointer to operation mode of the bus the API is applied to.
*   @return     status of the request      
*                   - E_OK: will be returned if the operation mode was detected.
*                   - E_NOT_OK: will be returned if the operation mode was not detected.
*   @ServiceID  0x02
*   @Sync/Async Asynchronous 
*   @Reentrancy Reentrant for different transceivers
********************************************************************************************************************/
Std_ReturnType CanTrcv_GetOpMode(uint8 Transceiver, CanTrcv_TrcvModeType* OpMode);

/*!******************************************************************************************************************
*   @brief      This method gets the wakeup reason for the Transceiver and returns it in parameter Reason.
*   @param[in]  Transceiver  CAN transceiver to which API call has to be applied.
*   @param[out] reason  Pointer to wake up reason of the bus the API is applied to.
*   @return     status of the request      
*                   - E_OK: will be returned if the transceiver wakeup reason was provided.
*                   - E_NOT_OK: will be returned if no wake up reason is available or if the service request failed 
*                     due to development errors.
*   @ServiceID  0x03
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant 
********************************************************************************************************************/
Std_ReturnType CanTrcv_GetBusWuReason(uint8 Transceiver, CanTrcv_TrcvWakeupReasonType* Reason);

/*!******************************************************************************************************************
*   @brief      This method gets the version of the module and returns it in VersionInfo.
*   @param[out] versioninfo  Pointer to version information of this module. 
*   @ServiceID  0x04
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant 
********************************************************************************************************************/
void CanTrcv_GetVersionInfo(Std_VersionInfoType * VersionInfo);

/*!******************************************************************************************************************
*   @brief      This method Enables, disables or clears wake-up events of the Transceiver according to TrcvWakeupMode.
*   @param[in]  Transceiver  CAN transceiver to which API call has to be applied.
*   @param[in]  TrcvWakeupMode  Requested transceiver wakeup reason
*   @return     status of the request      
*                   - E_OK: Will be returned, if the wakeup state has been changed to the requested mode.
*                   - E_NOT_OK: Will be returned, if the wakeup state change has failed or the parameter is out of 
*                     the allowed range. The previ-ous state has not been changed.
*   @ServiceID  0x05
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant for different transceivers 
********************************************************************************************************************/
Std_ReturnType CanTrcv_SetWakeupMode(uint8 Transceiver, CanTrcv_TrcvWakeupModeType TrcvWakeupMode);

#if (CANTRCV_HW_PN_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief      This method Reads the transceiver configuration/status data and returns it through parameter 
*               TrcvSysData. This API shall exist only if CanTrcvHwPnSupport = TRUE.
*   @param[in]  Transceiver  CAN transceiver to which API call has to be applied.
*   @param[out] TrcvSysData  pointer to be updated with the Configuration/Status data of the transceiver
*   @return     status of the request      
*                   - E_OK: will be returned if the transceiver status is successfully read.
*                   - E_NOT_OK: will be returned if the transceiver status data is not available or a development 
*                     error occurs.
*   @ServiceID  0x09
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_GetTrcvSystemData(uint8 Transceiver, const uint32* TrcvSysData);

/*!******************************************************************************************************************
*   @brief      This method Clears the WUF flag in the transceiver hardware. This API shall exist only if
*               CanTrcvHwPnSupport = TRUE.
*               TrcvSysData. This API shall exist only if CanTrcvHwPnSupport = TRUE.
*   @param[in]  Transceiver  CAN transceiver to which API call has to be applied.
*   @return     status of the request      
*                   - E_OK: will be returned if the WUF flag has been cleared.
*                   - E_NOT_OK: will be returned if the WUF flag has not been cleared or a development error occurs.
*   @ServiceID  0x0a
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant for different transceivers
********************************************************************************************************************/
Std_ReturnType CanTrcv_ClearTrcvWufFlag(uint8 Transceiver);

/*!******************************************************************************************************************
*   @brief      This method Reads the status of the timeout flag from the transceiver hardware. This API shall exist
*               only if CanTrcvHwPnSupport = TRUE.
*               TrcvSysData. This API shall exist only if CanTrcvHwPnSupport = TRUE.
*   @param[in]  Transceiver  CAN transceiver to which API call has to be applied.
*   @param[out] FlagState  pointer to be udpated with State of the timeout flag
*   @return     status of the request      
*                   - E_OK: Will be returned, if status of the timeout flag is success-fully read.
*                   - E_NOT_OK: Will be returned, if status of the timeout flag could not be read
*   @ServiceID  0x0b
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_ReadTrcvTimeoutFlag(uint8 Transceiver, CanTrcv_TrcvFlagStateType* FlagState);

/*!******************************************************************************************************************
*   @brief      This method Clears the status of the timeout flag in the transceiver hardware. This API shall exist 
*               only if CanTrcvHwPnSupport = TRUE
*               TrcvSysData. This API shall exist only if CanTrcvHwPnSupport = TRUE.
*   @param[in]  Transceiver  CAN transceiver to which API call has to be applied.
*   @return     status of the request      
*                   - E_OK: Will be returned, if the timeout flag is successfully cleared. 
*                   - E_NOT_OK: Will be returned, if the timeout flag could not be cleared.
*   @ServiceID  0x0c
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_ClearTrcvTimeoutFlag(uint8 Transceiver);

/*!******************************************************************************************************************
*   @brief      This method Reads the status of the silence flag from the transceiver hardware. This API shall 
*               exist only if CanTrcvHwPnSupport = TRUE.
*   @param[in]  Transceiver  CAN transceiver to which API call has to be applied.
*   @param[out] FlagState  pointer to be updated with State of the silence flag.
*   @return     status of the request      
*                   - E_OK: Will be returned, if status of the silence flag is success-fully read.
*                   - E_NOT_OK: Will be returned, if status of the silence flag could not be read.
*   @ServiceID  0x0d
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_ReadTrcvSilenceFlag(uint8 Transceiver, CanTrcv_TrcvFlagStateType* FlagState);
#endif

/*!******************************************************************************************************************
*   @brief      This method Service is called by underlying CANIF in case a wake up interrupt is detected.
*   @param[in]  Transceiver  CAN transceiver to which API call has to be applied.
*   @return     status of the request      
*                   - E_OK: API call has been accepted
*                   - E_NOT_OK: API call has not been accepted
*   @ServiceID  0x07
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_CheckWakeup(uint8 Transceiver);

#if (CANTRCV_HW_PN_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief      This method configures the wake-up of the transceiver for Standby and Sleep Mode: Either the CAN 
*               transceiver is woken up by a remote wake-up pattern (standard CAN wake-up) or by the configured 
*               remote wake-up frame.
*   @param[in]  ActivationState PN_ENABLED: PN wakeup functionality in CanTrcv shall be enabled. 
*               PN_DIABLED: PN wakeup functionality in CanTrcv shall be disabled.
*   @return     status of the request      
*                   - E_OK: Will be returned, if the PN has been changed to the requested configuration.
*                   - E_NOT_OK: Will be returned, if the PN configuration change has failed. The previous 
*                     configuration has not been changed.
*   @ServiceID  0x0f
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_SetPNActivationState(CanTrcv_PNActivationType ActivationState);
#endif

/*!******************************************************************************************************************
*   @brief      This method Requests to check the status of the wakeup flag from the transceiver hardware.
*   @param[in]  Transceiver CAN transceiver to which API call has to be applied.
*   @return     status of the request      
*                   - E_OK: Will be returned, if the request for checking the wakeup flag has been accepted.
*                   - E_NOT_OK: Will be returned, if the request for checking the wakeup flag has not been accepted.
*   @ServiceID  0x0e
*   @Sync/Async Asynchronous 
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_CheckWakeFlag(uint8 Transceiver);

/*!******************************************************************************************************************
*   @brief      This method Service to scan all busses for wake up events and perform these event.
*   @ServiceID  0x06
********************************************************************************************************************/
void CanTrcv_MainFunction(void);

/*!******************************************************************************************************************
*   @brief      This method Reads the transceiver diagnostic status periodically and sets product/development 
*               accordingly. 
*   @ServiceID  0x08
********************************************************************************************************************/
void CanTrcv_MainFunctionDiagnostics(void);


#endif /* CANTRCV_H */

