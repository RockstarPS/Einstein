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
 *          File:  Rte_Mdl_Gear.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <Mdl_Gear>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_MDL_GEAR_H
# define _RTE_MDL_GEAR_H

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

# include "Rte_Mdl_Gear_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Gear_pp_ShiftPositionDisplay_ShiftPositionDisplay; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(IgntionSubstateType, RTE_VAR_INIT) Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(VehicleActiveModes, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_VehicleAppMode_WSSCurrentVehicleState; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(ClusterModes, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(HMIReadySts_Type, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_HMIReady_HMI_ReadyStatus; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_pp_ShiftPositionDisplay_ShiftPositionDisplay (0U)
#  define Rte_InitValue_pp_Shift_ModeInd_ShiftModeIndicator (0U)
#  define Rte_InitValue_pp_Shift_Position_ShiftPosition (0U)
#  define Rte_InitValue_rpIgnSubstate_IgnitionSubstate (0U)
#  define Rte_InitValue_rpVehicleAppMode_WSSCurrentVehicleState (0U)
#  define Rte_InitValue_rp_ClusterMode_WSSCurrentClusterMode (0U)
#  define Rte_InitValue_rp_HMI_Ready_Status_HMI_ReadyStatus (0U)
#  define Rte_InitValue_rp_PowerTrainState_PowerTrain_Flag (0U)
#  define Rte_InitValue_rp_TT_PRND_blink_TIUpdateIndicatorStatus (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Mdl_Gear_pp_Shiftpos_ShiftPosIndStatus_ShiftPosIndStatusData(P2CONST(SShiftPosIndStatus, AUTOMATIC, RTE_MDL_GEAR_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_rpIgnSubstate_IgnitionSubstate Rte_Read_Mdl_Gear_rpIgnSubstate_IgnitionSubstate
#  define Rte_Read_Mdl_Gear_rpIgnSubstate_IgnitionSubstate(data) (*(data) = Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpVehicleAppMode_WSSCurrentVehicleState Rte_Read_Mdl_Gear_rpVehicleAppMode_WSSCurrentVehicleState
#  define Rte_Read_Mdl_Gear_rpVehicleAppMode_WSSCurrentVehicleState(data) (*(data) = Rte_Ctrl_WSS_pp_VehicleAppMode_WSSCurrentVehicleState, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_ClusterMode_WSSCurrentClusterMode Rte_Read_Mdl_Gear_rp_ClusterMode_WSSCurrentClusterMode
#  define Rte_Read_Mdl_Gear_rp_ClusterMode_WSSCurrentClusterMode(data) (*(data) = Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_HMI_Ready_Status_HMI_ReadyStatus Rte_Read_Mdl_Gear_rp_HMI_Ready_Status_HMI_ReadyStatus
#  define Rte_Read_Mdl_Gear_rp_HMI_Ready_Status_HMI_ReadyStatus(data) (*(data) = Rte_Ctrl_WSS_pp_HMIReady_HMI_ReadyStatus, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_PowerTrainState_PowerTrain_Flag Rte_Read_Mdl_Gear_rp_PowerTrainState_PowerTrain_Flag
#  define Rte_Read_Mdl_Gear_rp_PowerTrainState_PowerTrain_Flag(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_TT_PRND_blink_TIUpdateIndicatorStatus Rte_Read_Mdl_Gear_rp_TT_PRND_blink_TIUpdateIndicatorStatus
#  define Rte_Read_Mdl_Gear_rp_TT_PRND_blink_TIUpdateIndicatorStatus(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_pp_ShiftPositionDisplay_ShiftPositionDisplay Rte_Write_Mdl_Gear_pp_ShiftPositionDisplay_ShiftPositionDisplay
#  define Rte_Write_Mdl_Gear_pp_ShiftPositionDisplay_ShiftPositionDisplay(data) (Rte_Mdl_Gear_pp_ShiftPositionDisplay_ShiftPositionDisplay = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_Shift_ModeInd_ShiftModeIndicator Rte_Write_Mdl_Gear_pp_Shift_ModeInd_ShiftModeIndicator
#  define Rte_Write_Mdl_Gear_pp_Shift_ModeInd_ShiftModeIndicator(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_Shift_Position_ShiftPosition Rte_Write_Mdl_Gear_pp_Shift_Position_ShiftPosition
#  define Rte_Write_Mdl_Gear_pp_Shift_Position_ShiftPosition(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_Shiftpos_ShiftPosIndStatus_ShiftPosIndStatusData Rte_Write_Mdl_Gear_pp_Shiftpos_ShiftPosIndStatus_ShiftPosIndStatusData
#  define Rte_Write_pp_Shiftpos_ePRNDL_Status_ShiftPos_Data Rte_Write_Mdl_Gear_pp_Shiftpos_ePRNDL_Status_ShiftPos_Data
#  define Rte_Write_Mdl_Gear_pp_Shiftpos_ePRNDL_Status_ShiftPos_Data(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_GetSignalValue(tRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalValue, P2VAR(tRxSignalStatus, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_CanRx_RxCan_GetSignalValue CComAbsMdl_RxCan_GetSignalValue
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalValue, P2VAR(tRxSignalStatus, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalStatus, P2VAR(UInt32, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr CComAbsMdl_RxCan_GetSignalValueU8Arr
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SetSignalInitValue(tRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalValue); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValue CComAbsMdl_RxCan_SetSignalInitValue
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignaValue, P2VAR(UInt32, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr CComAbsMdl_RxCan_SetSignalInitValueU8Arr
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_CanRx_RxCan_SignalClearJustRcvdStatus(arg1) (CComAbsMdl_RxCan_SignalClearJustRcvdStatus(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, P2VAR(tRxSignalJustRcvdStatus, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pJustRcvdStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_CanRx_RxCan_SignalGetJustRcvdStatus(arg1, arg2) (CComAbsMdl_RxCan_SignalGetJustRcvdStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_CanRx_RxCan_SignalInvalidProcessingControl(arg1, arg2) (CComAbsMdl_RxCan_SignalInvalidProcessingControl(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_CanRx_RxCan_SignalMissingProcessingControl(arg1, arg2) (CComAbsMdl_RxCan_SignalMissingProcessingControl(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_CanRx_RxCan_SignalNRProcessingControl(arg1, arg2) (CComAbsMdl_RxCan_SignalNRProcessingControl(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue CComAbsMdl_RxCan_GetSignalValue
#  define Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr CComAbsMdl_RxCan_GetSignalValueU8Arr
#  define Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue CComAbsMdl_RxCan_SetSignalInitValue
#  define Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr CComAbsMdl_RxCan_SetSignalInitValueU8Arr
#  define Rte_Call_rp_CS_RxCanMdl_RxCan_SignalClearJustRcvdStatus(arg1) (CComAbsMdl_RxCan_SignalClearJustRcvdStatus(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus(arg1, arg2) (CComAbsMdl_RxCan_SignalGetJustRcvdStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_RxCanMdl_RxCan_SignalInvalidProcessingControl(arg1, arg2) (CComAbsMdl_RxCan_SignalInvalidProcessingControl(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_RxCanMdl_RxCan_SignalMissingProcessingControl(arg1, arg2) (CComAbsMdl_RxCan_SignalMissingProcessingControl(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_RxCanMdl_RxCan_SignalNRProcessingControl(arg1, arg2) (CComAbsMdl_RxCan_SignalNRProcessingControl(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_Get_Variant_Cfg_Get_Variant_Config_State(arg1, arg2) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CTRL_WSS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CTRL_WSS_APPL_CODE) Ctrl_WSS_GetVariant_Status(UInt8 Variant_Ind, P2VAR(UInt8, AUTOMATIC, RTE_CTRL_WSS_APPL_VAR) Variant_Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CTRL_WSS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_Variant_Status_GetVariant_Status(arg1, arg2) (Ctrl_WSS_GetVariant_Status(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define Mdl_Gear_START_SEC_CODE
# include "Mdl_Gear_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Mdl_Gear_Init Mdl_Gear_Init
#  define RTE_RUNNABLE_Mdl_Gear_Task Mdl_Gear_Task
# endif

FUNC(void, Mdl_Gear_CODE) Mdl_Gear_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Mdl_Gear_CODE) Mdl_Gear_Task(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define Mdl_Gear_STOP_SEC_CODE
# include "Mdl_Gear_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_if_CS_ComAbsRx_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_MDL_GEAR_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
