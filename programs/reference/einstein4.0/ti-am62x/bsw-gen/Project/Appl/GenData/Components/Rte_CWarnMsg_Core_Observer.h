/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_CWarnMsg_Core_Observer.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <CWarnMsg_Core_Observer>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CWARNMSG_CORE_OBSERVER_H
# define _RTE_CWARNMSG_CORE_OBSERVER_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_CWarnMsg_Core_Observer_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(IgntionSubstateType, RTE_VAR_INIT) Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(ClusterModes, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(HMIReadySts_Type, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_HMIReady_HMI_ReadyStatus; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Dim_pp_illumStarterstatus_StarterStatus_Out; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */

# ifndef RTE_CORE

#  define RTE_START_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* RTE Helper-Functions */
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);

#  define RTE_STOP_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_pp_WarnHighInt_WarningHighInterrupt_State (0U)
#  define Rte_InitValue_pp_WarnInt_WarningInterrupt_State (0U)
#  define Rte_InitValue_rpCS_ChimeRequest_Chime_Request (0U)
#  define Rte_InitValue_rpCS_GetChimeStatus_Chime_Status (0U)
#  define Rte_InitValue_rpIgnSubstate_IgnitionSubstate (0U)
#  define Rte_InitValue_rp_ClusterMode_WSSCurrentClusterMode (0U)
#  define Rte_InitValue_rp_FactoryMode_FactoryMode (0U)
#  define Rte_InitValue_rp_FactoryModeSts_FactoryModeStatus (0U)
#  define Rte_InitValue_rp_HMIReadySts_HMI_ReadyStatus (0U)
#  define Rte_InitValue_rp_HMIScreenMode_HMIScreenMode_Status (0U)
#  define Rte_InitValue_rp_HUDWakeupHwSts_WakeType_Hw (0U)
#  define Rte_InitValue_rp_HUDWakeupSwSts_WakeType_Int (0U)
#  define Rte_InitValue_rp_IllumStartSts_StarterStatus_Out (0U)
#  define Rte_InitValue_rp_NVM_HUD_CoordinateFlag_NvmData (0U)
#  define Rte_InitValue_rp_TargetSWStatus_TargetSw (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CWarnMsg_Core_Observer_rp_HUDWarningStatus_HudWarningStatusData(P2VAR(SHudWarningStatus, AUTOMATIC, RTE_CWARNMSG_CORE_OBSERVER_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CWarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData(P2VAR(SWarningStatus, AUTOMATIC, RTE_CWARNMSG_CORE_OBSERVER_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CWarnMsg_Core_Observer_pp_HUDWarningDisplay_HudWarningDisplayData(P2CONST(SHudWarningDisplay, AUTOMATIC, RTE_CWARNMSG_CORE_OBSERVER_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CWarnMsg_Core_Observer_pp_TPMSWarnPayload_TpmsWarningDataData(P2CONST(STpmsWarningData, AUTOMATIC, RTE_CWARNMSG_CORE_OBSERVER_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CWarnMsg_Core_Observer_pp_WarningDisplay_WarningDisplayData(P2CONST(SWarningDisplay, AUTOMATIC, RTE_CWARNMSG_CORE_OBSERVER_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_rpCS_ChimeRequest_Chime_Request Rte_Read_CWarnMsg_Core_Observer_rpCS_ChimeRequest_Chime_Request
#  define Rte_Read_CWarnMsg_Core_Observer_rpCS_ChimeRequest_Chime_Request(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpCS_GetChimeStatus_Chime_Status Rte_Read_CWarnMsg_Core_Observer_rpCS_GetChimeStatus_Chime_Status
#  define Rte_Read_CWarnMsg_Core_Observer_rpCS_GetChimeStatus_Chime_Status(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpIgnSubstate_IgnitionSubstate Rte_Read_CWarnMsg_Core_Observer_rpIgnSubstate_IgnitionSubstate
#  define Rte_Read_CWarnMsg_Core_Observer_rpIgnSubstate_IgnitionSubstate(data) (*(data) = Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_ClusterMode_WSSCurrentClusterMode Rte_Read_CWarnMsg_Core_Observer_rp_ClusterMode_WSSCurrentClusterMode
#  define Rte_Read_CWarnMsg_Core_Observer_rp_ClusterMode_WSSCurrentClusterMode(data) (*(data) = Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_FactoryMode_FactoryMode Rte_Read_CWarnMsg_Core_Observer_rp_FactoryMode_FactoryMode
#  define Rte_Read_CWarnMsg_Core_Observer_rp_FactoryMode_FactoryMode(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_FactoryModeSts_FactoryModeStatus Rte_Read_CWarnMsg_Core_Observer_rp_FactoryModeSts_FactoryModeStatus
#  define Rte_Read_CWarnMsg_Core_Observer_rp_FactoryModeSts_FactoryModeStatus(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_HMIReadySts_HMI_ReadyStatus Rte_Read_CWarnMsg_Core_Observer_rp_HMIReadySts_HMI_ReadyStatus
#  define Rte_Read_CWarnMsg_Core_Observer_rp_HMIReadySts_HMI_ReadyStatus(data) (*(data) = Rte_Ctrl_WSS_pp_HMIReady_HMI_ReadyStatus, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_HMIScreenMode_HMIScreenMode_Status Rte_Read_CWarnMsg_Core_Observer_rp_HMIScreenMode_HMIScreenMode_Status
#  define Rte_Read_CWarnMsg_Core_Observer_rp_HMIScreenMode_HMIScreenMode_Status(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_HUDWakeupHwSts_WakeType_Hw Rte_Read_CWarnMsg_Core_Observer_rp_HUDWakeupHwSts_WakeType_Hw
#  define Rte_Read_CWarnMsg_Core_Observer_rp_HUDWakeupHwSts_WakeType_Hw(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_HUDWakeupSwSts_WakeType_Int Rte_Read_CWarnMsg_Core_Observer_rp_HUDWakeupSwSts_WakeType_Int
#  define Rte_Read_CWarnMsg_Core_Observer_rp_HUDWakeupSwSts_WakeType_Int(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_HUDWarningStatus_HudWarningStatusData Rte_Read_CWarnMsg_Core_Observer_rp_HUDWarningStatus_HudWarningStatusData
#  define Rte_Read_rp_IllumStartSts_StarterStatus_Out Rte_Read_CWarnMsg_Core_Observer_rp_IllumStartSts_StarterStatus_Out
#  define Rte_Read_CWarnMsg_Core_Observer_rp_IllumStartSts_StarterStatus_Out(data) (*(data) = Rte_Mdl_Dim_pp_illumStarterstatus_StarterStatus_Out, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_NVM_HUD_CoordinateFlag_NvmData Rte_Read_CWarnMsg_Core_Observer_rp_NVM_HUD_CoordinateFlag_NvmData
#  define Rte_Read_CWarnMsg_Core_Observer_rp_NVM_HUD_CoordinateFlag_NvmData(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_TPMSPayload_Tpms_Payload Rte_Read_CWarnMsg_Core_Observer_rp_TPMSPayload_Tpms_Payload
#  define Rte_Read_CWarnMsg_Core_Observer_rp_TPMSPayload_Tpms_Payload(data) ( \
    Rte_MemCpy(data, Rte_CWarnMsg_Core_ObserverTpms_PayloadValue0, sizeof(Tpms_Arr_u8_5)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_TargetSWStatus_TargetSw Rte_Read_CWarnMsg_Core_Observer_rp_TargetSWStatus_TargetSw
#  define Rte_Read_CWarnMsg_Core_Observer_rp_TargetSWStatus_TargetSw(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_WarningStatus_WarningStatusData Rte_Read_CWarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_pp_HUDWarningDisplay_HudWarningDisplayData Rte_Write_CWarnMsg_Core_Observer_pp_HUDWarningDisplay_HudWarningDisplayData
#  define Rte_Write_pp_TPMSWarnPayload_TpmsWarningDataData Rte_Write_CWarnMsg_Core_Observer_pp_TPMSWarnPayload_TpmsWarningDataData
#  define Rte_Write_pp_WarnHighInt_WarningHighInterrupt_State Rte_Write_CWarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State
#  define Rte_Write_CWarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_WarnInt_WarningInterrupt_State Rte_Write_CWarnMsg_Core_Observer_pp_WarnInt_WarningInterrupt_State
#  define Rte_Write_CWarnMsg_Core_Observer_pp_WarnInt_WarningInterrupt_State(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_WarningDisplay_WarningDisplayData Rte_Write_CWarnMsg_Core_Observer_pp_WarningDisplay_WarningDisplayData


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CTRL_WARNING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CTRL_WARNING_APPL_CODE) Ctrl_warning_GetActiveWarningStatus(WarningId CurrentWarning, P2VAR(ExtWarningData, AUTOMATIC, RTE_CTRL_WARNING_APPL_VAR) CurrentWarningStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CTRL_WARNING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpActiveWarningStatus_GetActiveWarningStatus(arg1, arg2) (Ctrl_warning_GetActiveWarningStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CTRL_WARNING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CTRL_WARNING_APPL_CODE) Ctrl_warning_GetWarningActiveStatus(WarningId CurrentWarning, P2VAR(WarningDataS, AUTOMATIC, RTE_CTRL_WARNING_APPL_VAR) CurrentWarningStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CTRL_WARNING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_ActiveWarningSts_GetWarningActiveStatus(arg1, arg2) (Ctrl_warning_GetWarningActiveStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_TxCan_ClearCanSignalTxConfirmation(tTxSignalId SignalId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_TxCanMdl_TxCan_ClearCanSignalTxConfirmation(arg1) (CComAbsMdl_TxCan_ClearCanSignalTxConfirmation(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_TxCan_GetCanSignalTxConfirmation(tTxSignalId SignalId, P2VAR(tTxSigConfirmStatus, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_TxCanMdl_TxCan_GetCanSignalTxConfirmation(arg1, arg2) (CComAbsMdl_TxCan_GetCanSignalTxConfirmation(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_TxCan_SetSignalFromRetentionBuffer(tTxSignalId SignalId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalFromRetentionBuffer CComAbsMdl_TxCan_SetSignalFromRetentionBuffer
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_TxCan_SetSignalValue(tTxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pTxSignalData); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalValue CComAbsMdl_TxCan_SetSignalValue
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_TxCan_SetSignalValueU8Arr(tTxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pTxSignalData, UInt32 SignalLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalValueU8Arr CComAbsMdl_TxCan_SetSignalValueU8Arr
#  define RTE_START_SEC_CTRL_WARNING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_CTRL_WARNING_APPL_CODE) Ctrl_warning_SetWarningDisplayedPayload(WarningId CurWarningId, P2CONST(Rte_DT_PayloadArr_u8_8_0, AUTOMATIC, RTE_CTRL_WARNING_APPL_DATA) CurWarningDispPayload); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_CTRL_WARNING_APPL_CODE) Ctrl_warning_SetWarningDisplayedPayload(WarningId CurWarningId, P2CONST(PayloadArr_u8_8, AUTOMATIC, RTE_CTRL_WARNING_APPL_DATA) CurWarningDispPayload); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_CTRL_WARNING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_UpdateDisplayPayload_SetWarningDisplayedPayload(arg1, arg2) (Ctrl_warning_SetWarningDisplayedPayload(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CTRL_WARNING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CTRL_WARNING_APPL_CODE) Ctrl_warning_SetWarningDisplayedStatus(WarningId CurWarningId, WarningDisplayedStatus CurWarningDispStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CTRL_WARNING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_UpdateDisplayStatus_SetWarningDisplayedStatus(arg1, arg2) (Ctrl_warning_SetWarningDisplayedStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_VoiceOpButtonSts_GetButtonStatus(arg1, arg2, arg3) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define CWarnMsg_Core_Observer_START_SEC_CODE
# include "CWarnMsg_Core_Observer_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CWarnMsg_Core_Observer_GroupWrnAck CWarnMsg_Core_Observer_GroupWrnAck
#  define RTE_RUNNABLE_CWarnMsg_Core_Observer_Impl_MainFunction CWarnMsg_Core_Observer_Impl_MainFunction
#  define RTE_RUNNABLE_CWarnMsg_Core_Observer_Impl_OnCommand CWarnMsg_Core_Observer_Impl_OnCommand
#  define RTE_RUNNABLE_CWarnMsg_Core_Observer_Init CWarnMsg_Core_Observer_Init
#  define RTE_RUNNABLE_CWarnMsg_Core_Observer_SW_NoOperationTimer CWarnMsg_Core_Observer_SW_NoOperationTimer
#  define RTE_RUNNABLE_OnDre_UCL_HudWarnStatus OnDre_UCL_HudWarnStatus
#  define RTE_RUNNABLE_OnDre_UCL_WarnStatus OnDre_UCL_WarnStatus
# endif

FUNC(void, CWarnMsg_Core_Observer_CODE) CWarnMsg_Core_Observer_GroupWrnAck(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CWarnMsg_Core_Observer_CODE) CWarnMsg_Core_Observer_Impl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, CWarnMsg_Core_Observer_CODE) CWarnMsg_Core_Observer_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CWarnMsg_Core_Observer_CODE) CWarnMsg_Core_Observer_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CWarnMsg_Core_Observer_CODE) CWarnMsg_Core_Observer_SW_NoOperationTimer(EButtonId pEvent, EButtonSts pEventType); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CWarnMsg_Core_Observer_CODE) OnDre_UCL_HudWarnStatus(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CWarnMsg_Core_Observer_CODE) OnDre_UCL_WarnStatus(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CWarnMsg_Core_Observer_STOP_SEC_CODE
# include "CWarnMsg_Core_Observer_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_if_CS_ComAbsTx_E_NOT_OK (1U)

#  define RTE_E_if_CS_ModeOnCommand_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CWARNMSG_CORE_OBSERVER_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
