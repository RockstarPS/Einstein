/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2016. Visteon Corporation owns all rights to           *
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
 *  File Name         :  Dcm.h                                                *
 *  Module Short Name :  DiagMgr                                               *
 *  VOBName           :                                                       *
 *  Author            : msavariy                                              *
 *  Description       : This file contains the Diagnostics request and        *
 *                       response handling functionlities.                    *
 *                                                                            *
 * Organization     :  Driver Information Software Section,                   *
 *                     Visteon Software Operation                             *
 *                     Visteon Corporation                                    *
 *                                                                            *
 * ---------------------------------------------------------------------------*
 * Compiler Name    :  GHS                                                    *
 * Target Hardware  :                                                         *
 *                                                                            *
 ******************************************************************************/
#ifndef DCM_H
#define DCM_H

/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
#include "Std_Types.h"
#include "Dcm_Cfg.h"
#include "Dcm_Types.h"

/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/
#ifndef DCM_C
#define EXTERN extern
#else
#define EXTERN
#endif

/*****************************************************************************
 *                                 Type Declarations                          *
 ******************************************************************************/

/*****************************************************************************
 *                   Functions                                                *
 ******************************************************************************/
/*****************************************************************************
 *                                Globally  accessed Variable Declarations    *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

/*****************************************************************************
 *                                 Locally used Variable Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

/*  Functions provided for other BSW components */
/**************************************************************************
 Function name   : void Dcm_Init
 Arguments       : const Dcm_ConfigType *ConfigPtr
 Return type     : void
 Description     : Service for basic initialization of DCM module. 
 **************************************************************************/

EXTERN void Dcm_Init(const Dcm_ConfigType *ConfigPtr);

/**************************************************************************
 Function name   : void Dcm_GetVersionInfo
 Arguments       : Std_VersionInfoType* versionInfo
 Return type     : void
 Description     : Returns the version information of this module. 
 **************************************************************************/

EXTERN void Dcm_GetVersionInfo(Std_VersionInfoType *versionInfo);

/**************************************************************************
 Function name   : Std_ReturnType Dcm_DemTriggerOnDTCStatus
 Arguments       : Std_VersionInfoType* versionInfo
 Return type     : Std_ReturnType
 Description     : Triggers on changes of the UDS DTC status byte. Allows to trigger on ROE Event
 for subservice OnDTCStatusChanged. 
 **************************************************************************/

EXTERN Std_ReturnType Dcm_DemTriggerOnDTCStatus(uint32 DTC, Dem_UdsStatusByteType DTCStatusOld,
                                                Dem_UdsStatusByteType DTCStatusNew);

/**************************************************************************
 Function name   : Std_ReturnType Dcm_GetVin
 Arguments       : uint8* Data
 Return type     : Std_ReturnType
 Description     : Callbackfunction to get the VIN 
 **************************************************************************/
EXTERN Std_ReturnType Dcm_GetVin(uint8 *Data);

/*    Scheduled Functions */
/**************************************************************************
 Function name   : void Dcm_MainFunction
 Arguments       : void
 Return type     : void
 Description     : This service is used for processing the tasks of the main loop. 
 **************************************************************************/
EXTERN void Dcm_MainFunction(void);

/* Functions provided to BSW modules and to SW-Cs */

/**************************************************************************
 Function name   : Std_ReturnType Dcm_GetSecurityLevel
 Arguments       : Dcm_SecLevelType *secLevel
 Return type     : Std_ReturnType
 Description     : This function provides the active security level value. 
 **************************************************************************/

EXTERN Std_ReturnType Dcm_GetSecurityLevel(Dcm_SecLevelType *secLevel);

/**************************************************************************
 Function name   : Std_ReturnType Dcm_GetSesCtrlType
 Arguments       : Dcm_SesCtrlType *sesCtrlType
 Return type     : Std_ReturnType
 Description     : This function provides the active session control type value. 
 **************************************************************************/
EXTERN Std_ReturnType Dcm_GetSesCtrlType(Dcm_SesCtrlType *sesCtrlType);

/**************************************************************************
 Function name   : Std_ReturnType Dcm_GetSesCtrlTypeIndex
 Arguments       : Dcm_SesCtrlType *sesCtrlTypeIndex
 Return type     : Std_ReturnType
 Description     : This function provides the active session control type value.
 **************************************************************************/
EXTERN Std_ReturnType Dcm_GetSesCtrlTypeIndex(Dcm_SesCtrlType *sesCtrlTypeIndex);

/**************************************************************************
 Function name   : Std_ReturnType Dcm_GetActiveProtocol
 Arguments       : Dcm_ProtocolType *activeProtocol
 Return type     : Std_ReturnType
 Description     : This function returns the active protocol name 
 **************************************************************************/
EXTERN Std_ReturnType Dcm_GetActiveProtocol(Dcm_ProtocolType *activeProtocol);

/**************************************************************************
 Function name   : Dcm_ResetToDefaultSession
 Arguments       : void
 Return type     : Std_ReturnType
 Description     : The call to this function allows the application to reset the current session to
 Default session. 
 **************************************************************************/
EXTERN Std_ReturnType Dcm_ResetToDefaultSession(void);

/**************************************************************************
 Function name   : Std_ReturnType Dcm_TriggerOnEvent
 Arguments       : uint8 RoeEventId
 Return type     : Std_ReturnType
 Description     : The call to this function allows to trigger an event linked to a ResponseOnEvent
 request. 
 **************************************************************************/
EXTERN Std_ReturnType Dcm_TriggerOnEvent(uint8 RoeEventId);

/**************************************************************************
 Function name   : Std_ReturnType Dcm_SetActiveDiagnostic
 Arguments       : boolean avtive
 Return type     : Std_ReturnType
 Description     : Allows to activate and de-activate the call of ComM_DCM_ActiveDiagnostic()
 function. 
 **************************************************************************/
EXTERN Std_ReturnType Dcm_SetActiveDiagnostic(boolean active);

/* External diagnostic service processing */
/**************************************************************************
 Function name   : void Dcm_ExternalSetNegResponse
 Arguments       : Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType ErrorCode
 Return type     : void
 Description     : Used by service interpreter outside of DCM to indicate that a the final response
 shall be a negative one. 
 **************************************************************************/
EXTERN void Dcm_ExternalSetNegResponse(Dcm_NegativeResponseCodeType ErrorCode);

/**************************************************************************
 Function name   : void Dcm_ExternalProcessingDone
 Arguments       : none
 Return type     : void
 Description     : Used by service interpreter outside of DCM to indicate that a final response can be
 sent. 
 **************************************************************************/
EXTERN void Dcm_ExternalProcessingDone(void);

EXTERN void Dcm_ResetP2StartServer(void);

/**************************************************************************
 Function name   : boolean Dcm_CheckTimerActive
 Arguments       : uint8 TmrId
 Return type     : boolean
 Description     : Used to check DCM timer is active, i.e. P2, P2*, S3Server
 **************************************************************************/
EXTERN boolean Dcm_CheckTimerActive( uint8 TmrId );

/**************************************************************************
 Function name   : boolean Dcm_CheckTesterPresentActive
 Arguments       : uint8 TmrId
 Return type     : boolean
 Description     : Used to check TesterPresent message is active
 **************************************************************************/
EXTERN boolean Dcm_CheckTesterPresentActive(void);

#if 0
/* Callout Definitions */

/**************************************************************************
Function name   : Dcm_ReturnReadMemoryType Dcm_ReadMemory
Arguments       : Dcm_OpStatusType OpStatus, uint8 MemoryIdentifier, uint32 MemoryAddress, uint32 MemorySize, uint8* MemoryData
Return type     : Dcm_ReturnReadMemoryType
Description     : The Dcm_ReadMemory callout is used to request memory data identified by the
                  parameter memoryAddress and memorySize from the UDS request message.
**************************************************************************/

EXTERN Dcm_ReturnReadMemoryType Dcm_ReadMemory(Dcm_OpStatusType OpStatus, uint8 MemoryIdentifier, uint32 MemoryAddress, uint32 MemorySize, uint8* MemoryData);


/**************************************************************************
Function name   : Dcm_ReturnWriteMemoryType Dcm_WriteMemory
Arguments       : Dcm_OpStatusType OpStatus, uint8 MemoryIdentifier, uint32 MemoryAddress, uint32 MemorySize, uint8* MemoryData
Return type     : Dcm_ReturnWriteMemoryType
Description     : The Dcm_WriteMemory callout is used to write memory data identified by the
                  parameter memoryAddress and memorySize.
**************************************************************************/

EXTERN Dcm_ReturnWriteMemoryType Dcm_WriteMemory(Dcm_OpStatusType OpStatus, uint8 MemoryIdentifier, uint32 MemoryAddress, uint32 MemorySize, uint8* MemoryData);


/**************************************************************************
Function name   : void Dcm_Confirmation
Arguments       : Dcm_IdContextType idContext, PduIdType dcmRxPduId, Dcm_ConfirmationStatusType status
Return type     : void
Description     : This function confirms the successful transmission or a transmission error of a
                  diagnostic service.
**************************************************************************/
EXTERN void Dcm_Confirmation(Dcm_IdContextType idContext, PduIdType dcmRxPduId, Dcm_ConfirmationStatusType status);

/**************************************************************************
Function name   : Std_ReturnType Dcm_SetProgConditions
Arguments       : Dcm_ProgConditionsType * ProgConditions
Return type     : Std_ReturnType
Description     : The Dcm_SetProgConditions callout allows the integrator to store relevant
                  information prior to jumping to bootloader.
**************************************************************************/

EXTERN Std_ReturnType Dcm_SetProgConditions(Dcm_ProgConditionsType * ProgConditions);

/**************************************************************************
Function name   : Dcm_EcuStartModeType Dcm_GetProgConditions
Arguments       : Dcm_ProgConditionsType * ProgConditions
Return type     : Dcm_EcuStartModeType
Description     : The Dcm_GetProgConditions callout is called upon DCM initialization and allows to
                  determine if a response ($50 or $51) has to be sent depending on request within
                  the bootloader. 
**************************************************************************/
EXTERN Dcm_EcuStartModeType Dcm_GetProgConditions(Dcm_ProgConditionsType * ProgConditions);

/**************************************************************************
Function name   : Std_ReturnType Dcm_ProcessRequestTransferExit
Arguments       : Dcm_OpStatusType OpStatus, uint8* ParameterRecord, uint32 ParameterRecordSize, Dcm_NegativeResponseCodeType* ErrorCode
Return type     : Std_ReturnType
Description     : DCM shall call this callout function to terminate a download or upload process. 
**************************************************************************/
EXTERN Std_ReturnType Dcm_ProcessRequestTransferExit(Dcm_OpStatusType OpStatus, uint8* ParameterRecord, uint32 ParameterRecordSize, \
                                                                                        Dcm_NegativeResponseCodeType* ErrorCode);

/**************************************************************************
Function name   : Std_ReturnType Dcm_ProcessRequestUpload
Arguments       : Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize,
                    uint32* BlockLength, Dcm_NegativeResponseCodeType* ErrorCode
Return type     : Std_ReturnType
Description     : DCM shall call this callout function to start an upload process. This service
                  is needed for the implementation of UDS service RequestUpload. 
**************************************************************************/

EXTERN Std_ReturnType Dcm_ProcessRequestUpload(Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize, \
                                                                            uint32* BlockLength, Dcm_NegativeResponseCodeType* ErrorCode);

/**************************************************************************
Function name   : Std_ReturnType Dcm_ProcessRequestDownload
Arguments       : Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize, uint32* BlockLength, 
                  Dcm_NegativeResponseCodeType* ErrorCode
Return type     : Std_ReturnType
Description     : DCM shall call this callout function to start an upload process. This service
                  is needed for the implementation of UDS service RequestUpload. 
**************************************************************************/

EXTERN Std_ReturnType Dcm_ProcessRequestDownload(Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize, \
                                                                              uint32* BlockLength, Dcm_NegativeResponseCodeType* ErrorCode);


/**************************************************************************
Function name   : Std_ReturnType Dcm_ProcessRequestFileTransfer
Arguments       : Dcm_OpStatusType OpStatus, uint8 modeofOperation, uint16 fileSizeParameterLength, 
                  uint8* filePathAndName, uint8 dataFormatIdentifier, uint8* fileSizeUncompressedOrDirInfoLength, 
                  uint8* fileSizeCompressed, uint32* BlockLength, Dcm_NegativeResponseCodeType* ErrorCode
Return type     : Std_ReturnType
Description     : DCM shall call this callout function to start a RequestFileTransferprocess. This
                  service is needed for the implementation of UDS service RequestFileTransfer. 
**************************************************************************/

EXTERN Std_ReturnType Dcm_ProcessRequestFileTransfer(Dcm_OpStatusType OpStatus, uint8 modeofOperation, uint16 fileSizeParameterLength, \
                                uint8* filePathAndName, uint8 dataFormatIdentifier, uint8* fileSizeUncompressedOrDirInfoLength, \
                                        uint8* fileSizeCompressed, uint32* BlockLength, Dcm_NegativeResponseCodeType* ErrorCode);


/**************************************************************************
Function name   : Std_ReturnType Dcm_GetResetConditions
Arguments       : Dcm_ResetConditionsType* ResetConditions
Return type     : Std_ReturnType
Description     : The Dcm_GetResetConditions callout is called upon DCM initialization and allows
                  to determine if a response ($51) has to be sent or not. 
**************************************************************************/
EXTERN Std_ReturnType Dcm_GetResetConditions(Dcm_ResetConditionsType* ResetConditions);


/**************************************************************************
Function name   : Std_ReturnType Dcm_SetResetConditions
Arguments       : Dcm_ResetConditionsType* ResetConditions
Return type     : Std_ReturnType
Description     : The Dcm_GetResetConditions callout is called upon DCM initialization and allows
                  to determine if a response ($51) has to be sent or not. 
**************************************************************************/
EXTERN Std_ReturnType Dcm_SetResetConditions(Dcm_ResetConditionsType* ResetConditions);

#endif

#undef EXTERN

#endif

/*****************************************************************************
 *     End of File
 *
 *******************************************************************************/
/****************************************************************************
 *   for each change to this file, be sure to record:                        *
 *      1.  who made the change and when the change was made                 *
 *      2.  why the change was made and the intended result                  *
 *   Following block needs to be repeated for each change                    *
 *****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 22-Feb-2015                                            */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      :                                                       */
/*Change Description: Datadesign And Framework implemented, Initial Version */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 13-May-2017                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : Rtc#                                                  */
/*Change Description: QAC warning fixes                                     */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 25-Feb-2021                                           */
/*Version           :                                                       */
/*By                : iiliev1                                               */
/*Traceability      :                                                       */
/*Change Description: Implement 0x87 and 0x27 services                      */
/*--------------------------------------------------------------------------*/

