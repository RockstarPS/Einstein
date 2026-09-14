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
 *          File:  Rte_Ctrl_WSS.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <Ctrl_WSS>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CTRL_WSS_H
# define _RTE_CTRL_WSS_H

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

# include "Rte_Ctrl_WSS_Type.h"
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
extern VAR(DisplayStatus, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_TFTDisplayOn_TFTDisplayOn; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(VehicleActiveModes, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_VehicleAppMode_WSSCurrentVehicleState; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_NvMExt_ppSRPhasedRead_Status_phase1readcompleted_PhasedRead_Status_phase1readcompleted; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_NvMExt_ppSRPhasedRead_Status_phase2readcompleted_PhasedRead_Status_phase2readcompleted; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_NvMExt_ppSRPhasedRead_Status_phase3readcompleted_PhasedRead_Status_phase3readcompleted; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Dim_pp_IlumDayNightStatus_illumDNStatus; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Gear_pp_ShiftPositionDisplay_ShiftPositionDisplay; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(TurnStates, RTE_VAR_INIT) Rte_Mdl_TurnHazard_pp_TurnHazard_TurnL_Sts_LeftIndicatorSts; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(TurnStates, RTE_VAR_INIT) Rte_Mdl_TurnHazard_pp_TurnHazard_TurnR_Sts_RightIndicatorSts; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(TTFlashMask, RTE_VAR_INIT) Rte_CCtrl_Telltale_ppBlinkStatusArray_TTdummyDataForTypes; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_ppAccModeState_WSSAccState (0U)
#  define Rte_InitValue_ppBaModeState_WSSBaState (0U)
#  define Rte_InitValue_ppBaOfModeState_WSSBaOfState (0U)
#  define Rte_InitValue_ppIgnModeBuzzer_IgnitioBuznstate (0U)
#  define Rte_InitValue_ppIgnSubstate_IgnitionSubstate (0U)
#  define Rte_InitValue_ppIgpCANModeState_WSSIGPCANState (0U)
#  define Rte_InitValue_ppIgpModeState_WSSIGPState (0U)
#  define Rte_InitValue_pp_ClusterMode_WSSCurrentClusterMode (0U)
#  define Rte_InitValue_pp_HMIReady_HMI_ReadyStatus (0U)
#  define Rte_InitValue_pp_Init_ClusterMode_WSSCurrentClusterInitMode (0U)
#  define Rte_InitValue_pp_SleepStatus_Sleep_Status (0U)
#  define Rte_InitValue_pp_TFTDisplayOn_TFTDisplayOn (0U)
#  define Rte_InitValue_pp_TFTDisplayOnExTurn_TFTDisplayOnExTurn (0U)
#  define Rte_InitValue_pp_VehicleAppMode_WSSCurrentVehicleState (0U)
#  define Rte_InitValue_rpSRPhasedRead_Status_phase1readcompleted_PhasedRead_Status_phase1readcompleted (FALSE)
#  define Rte_InitValue_rpSRPhasedRead_Status_phase2readcompleted_PhasedRead_Status_phase2readcompleted (FALSE)
#  define Rte_InitValue_rpSRPhasedRead_Status_phase3readcompleted_PhasedRead_Status_phase3readcompleted (FALSE)
#  define Rte_InitValue_rpTTStsData_TTIndex (0U)
#  define Rte_InitValue_rpTTStsData_TTStatus (0U)
#  define Rte_InitValue_rp_BlinkStsArray_TTdummyDataForTypes (0U)
#  define Rte_InitValue_rp_HMIOdo_Type_HMI_OdoType (0U)
#  define Rte_InitValue_rp_HMIScreenMode_HMIScreenMode_Status (0U)
#  define Rte_InitValue_rp_Head_Lamp_Status_Head_Lamp_st (0U)
#  define Rte_InitValue_rp_IlumDayNightStatus_illumDNStatus (0U)
#  define Rte_InitValue_rp_Mdl_Pwmout_TC_Dbc_PWMOut_TC_Dbc (0U)
#  define Rte_InitValue_rp_ShiftPositionDisp_ShiftPositionDisplay (0U)
#  define Rte_InitValue_rp_Tail_Light_Status_Tail_Light_st (0U)
#  define Rte_InitValue_rp_TurnHzdTurnL_Status_LeftIndicatorSts (0U)
#  define Rte_InitValue_rp_TurnHzdTurnR_Status_RightIndicatorSts (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_Ctrl_WSS_rpCS_EcuMExt_FuelLidStatus_FuelLidStatus(P2VAR(BOOL_TYPE, AUTOMATIC, RTE_CTRL_WSS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_Ctrl_WSS_rpCS_EcuMExt_HazardStatus_HazardStatus(P2VAR(BOOL_TYPE, AUTOMATIC, RTE_CTRL_WSS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_Ctrl_WSS_rpUclHMIReadySts_MainHMIReadyStatusData(P2VAR(SMainHMIReadyStatus, AUTOMATIC, RTE_CTRL_WSS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ctrl_WSS_rpTelltaleStatusOP_TelltaleOpArray(P2VAR(Rte_DT_TT_OP_Type_0, AUTOMATIC, RTE_CTRL_WSS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ctrl_WSS_rpTelltaleStatusOP_TelltaleOpArray(P2VAR(TT_OP_Type, AUTOMATIC, RTE_CTRL_WSS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ctrl_WSS_rp_BlinkStsArray_TTBlinkStatusArray(P2VAR(Rte_DT_TTBlinkArray_0, AUTOMATIC, RTE_CTRL_WSS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ctrl_WSS_rp_BlinkStsArray_TTBlinkStatusArray(P2VAR(TTBlinkArray, AUTOMATIC, RTE_CTRL_WSS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Receive_<p>_<d> (explicit S/R communication with isQueued = true)
 *********************************************************************************************************************/
#  define Rte_Receive_rpCS_EcuMExt_FuelLidStatus_FuelLidStatus Rte_Receive_Ctrl_WSS_rpCS_EcuMExt_FuelLidStatus_FuelLidStatus
#  define Rte_Receive_rpCS_EcuMExt_HazardStatus_HazardStatus Rte_Receive_Ctrl_WSS_rpCS_EcuMExt_HazardStatus_HazardStatus
#  define Rte_Receive_rpUclHMIReadySts_MainHMIReadyStatusData Rte_Receive_Ctrl_WSS_rpUclHMIReadySts_MainHMIReadyStatusData


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_rpSRPhasedRead_Status_phase1readcompleted_PhasedRead_Status_phase1readcompleted Rte_Read_Ctrl_WSS_rpSRPhasedRead_Status_phase1readcompleted_PhasedRead_Status_phase1readcompleted
#  define Rte_Read_Ctrl_WSS_rpSRPhasedRead_Status_phase1readcompleted_PhasedRead_Status_phase1readcompleted(data) (*(data) = Rte_NvMExt_ppSRPhasedRead_Status_phase1readcompleted_PhasedRead_Status_phase1readcompleted, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpSRPhasedRead_Status_phase2readcompleted_PhasedRead_Status_phase2readcompleted Rte_Read_Ctrl_WSS_rpSRPhasedRead_Status_phase2readcompleted_PhasedRead_Status_phase2readcompleted
#  define Rte_Read_Ctrl_WSS_rpSRPhasedRead_Status_phase2readcompleted_PhasedRead_Status_phase2readcompleted(data) (*(data) = Rte_NvMExt_ppSRPhasedRead_Status_phase2readcompleted_PhasedRead_Status_phase2readcompleted, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpSRPhasedRead_Status_phase3readcompleted_PhasedRead_Status_phase3readcompleted Rte_Read_Ctrl_WSS_rpSRPhasedRead_Status_phase3readcompleted_PhasedRead_Status_phase3readcompleted
#  define Rte_Read_Ctrl_WSS_rpSRPhasedRead_Status_phase3readcompleted_PhasedRead_Status_phase3readcompleted(data) (*(data) = Rte_NvMExt_ppSRPhasedRead_Status_phase3readcompleted_PhasedRead_Status_phase3readcompleted, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpTTStsData_TTIndex Rte_Read_Ctrl_WSS_rpTTStsData_TTIndex
#  define Rte_Read_Ctrl_WSS_rpTTStsData_TTIndex(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpTTStsData_TTStatus Rte_Read_Ctrl_WSS_rpTTStsData_TTStatus
#  define Rte_Read_Ctrl_WSS_rpTTStsData_TTStatus(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpTelltaleStatusOP_TelltaleOpArray Rte_Read_Ctrl_WSS_rpTelltaleStatusOP_TelltaleOpArray
#  define Rte_Read_rp_BlinkStsArray_TTBlinkStatusArray Rte_Read_Ctrl_WSS_rp_BlinkStsArray_TTBlinkStatusArray
#  define Rte_Read_rp_BlinkStsArray_TTdummyDataForTypes Rte_Read_Ctrl_WSS_rp_BlinkStsArray_TTdummyDataForTypes
#  define Rte_Read_Ctrl_WSS_rp_BlinkStsArray_TTdummyDataForTypes(data) (*(data) = Rte_CCtrl_Telltale_ppBlinkStatusArray_TTdummyDataForTypes, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_HMIOdo_Type_HMI_OdoType Rte_Read_Ctrl_WSS_rp_HMIOdo_Type_HMI_OdoType
#  define Rte_Read_Ctrl_WSS_rp_HMIOdo_Type_HMI_OdoType(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_HMIScreenMode_HMIScreenMode_Status Rte_Read_Ctrl_WSS_rp_HMIScreenMode_HMIScreenMode_Status
#  define Rte_Read_Ctrl_WSS_rp_HMIScreenMode_HMIScreenMode_Status(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_Head_Lamp_Status_Head_Lamp_st Rte_Read_Ctrl_WSS_rp_Head_Lamp_Status_Head_Lamp_st
#  define Rte_Read_Ctrl_WSS_rp_Head_Lamp_Status_Head_Lamp_st(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_IlumDayNightStatus_illumDNStatus Rte_Read_Ctrl_WSS_rp_IlumDayNightStatus_illumDNStatus
#  define Rte_Read_Ctrl_WSS_rp_IlumDayNightStatus_illumDNStatus(data) (*(data) = Rte_Mdl_Dim_pp_IlumDayNightStatus_illumDNStatus, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_Mdl_Pwmout_TC_Dbc_PWMOut_TC_Dbc Rte_Read_Ctrl_WSS_rp_Mdl_Pwmout_TC_Dbc_PWMOut_TC_Dbc
#  define Rte_Read_Ctrl_WSS_rp_Mdl_Pwmout_TC_Dbc_PWMOut_TC_Dbc(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_ShiftPositionDisp_ShiftPositionDisplay Rte_Read_Ctrl_WSS_rp_ShiftPositionDisp_ShiftPositionDisplay
#  define Rte_Read_Ctrl_WSS_rp_ShiftPositionDisp_ShiftPositionDisplay(data) (*(data) = Rte_Mdl_Gear_pp_ShiftPositionDisplay_ShiftPositionDisplay, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_Tail_Light_Status_Tail_Light_st Rte_Read_Ctrl_WSS_rp_Tail_Light_Status_Tail_Light_st
#  define Rte_Read_Ctrl_WSS_rp_Tail_Light_Status_Tail_Light_st(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_TurnHzdTurnL_Status_LeftIndicatorSts Rte_Read_Ctrl_WSS_rp_TurnHzdTurnL_Status_LeftIndicatorSts
#  define Rte_Read_Ctrl_WSS_rp_TurnHzdTurnL_Status_LeftIndicatorSts(data) (*(data) = Rte_Mdl_TurnHazard_pp_TurnHazard_TurnL_Sts_LeftIndicatorSts, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_TurnHzdTurnR_Status_RightIndicatorSts Rte_Read_Ctrl_WSS_rp_TurnHzdTurnR_Status_RightIndicatorSts
#  define Rte_Read_Ctrl_WSS_rp_TurnHzdTurnR_Status_RightIndicatorSts(data) (*(data) = Rte_Mdl_TurnHazard_pp_TurnHazard_TurnR_Sts_RightIndicatorSts, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_ppAccModeState_WSSAccState Rte_Write_Ctrl_WSS_ppAccModeState_WSSAccState
#  define Rte_Write_Ctrl_WSS_ppAccModeState_WSSAccState(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppBaModeState_WSSBaState Rte_Write_Ctrl_WSS_ppBaModeState_WSSBaState
#  define Rte_Write_Ctrl_WSS_ppBaModeState_WSSBaState(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppBaOfModeState_WSSBaOfState Rte_Write_Ctrl_WSS_ppBaOfModeState_WSSBaOfState
#  define Rte_Write_Ctrl_WSS_ppBaOfModeState_WSSBaOfState(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppIgnModeBuzzer_IgnitioBuznstate Rte_Write_Ctrl_WSS_ppIgnModeBuzzer_IgnitioBuznstate
#  define Rte_Write_Ctrl_WSS_ppIgnModeBuzzer_IgnitioBuznstate(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppIgnSubstate_IgnitionSubstate Rte_Write_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate
#  define Rte_Write_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate(data) (Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppIgpCANModeState_WSSIGPCANState Rte_Write_Ctrl_WSS_ppIgpCANModeState_WSSIGPCANState
#  define Rte_Write_Ctrl_WSS_ppIgpCANModeState_WSSIGPCANState(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppIgpModeState_WSSIGPState Rte_Write_Ctrl_WSS_ppIgpModeState_WSSIGPState
#  define Rte_Write_Ctrl_WSS_ppIgpModeState_WSSIGPState(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_ClusterMode_WSSCurrentClusterMode Rte_Write_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode
#  define Rte_Write_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode(data) (Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_HMIReady_HMI_ReadyStatus Rte_Write_Ctrl_WSS_pp_HMIReady_HMI_ReadyStatus
#  define Rte_Write_Ctrl_WSS_pp_HMIReady_HMI_ReadyStatus(data) (Rte_Ctrl_WSS_pp_HMIReady_HMI_ReadyStatus = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_Init_ClusterMode_WSSCurrentClusterInitMode Rte_Write_Ctrl_WSS_pp_Init_ClusterMode_WSSCurrentClusterInitMode
#  define Rte_Write_Ctrl_WSS_pp_Init_ClusterMode_WSSCurrentClusterInitMode(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SleepStatus_Sleep_Status Rte_Write_Ctrl_WSS_pp_SleepStatus_Sleep_Status
#  define Rte_Write_Ctrl_WSS_pp_SleepStatus_Sleep_Status(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_TFTDisplayOn_TFTDisplayOn Rte_Write_Ctrl_WSS_pp_TFTDisplayOn_TFTDisplayOn
#  define Rte_Write_Ctrl_WSS_pp_TFTDisplayOn_TFTDisplayOn(data) (Rte_Ctrl_WSS_pp_TFTDisplayOn_TFTDisplayOn = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_TFTDisplayOnExTurn_TFTDisplayOnExTurn Rte_Write_Ctrl_WSS_pp_TFTDisplayOnExTurn_TFTDisplayOnExTurn
#  define Rte_Write_Ctrl_WSS_pp_TFTDisplayOnExTurn_TFTDisplayOnExTurn(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_VehicleAppMode_WSSCurrentVehicleState Rte_Write_Ctrl_WSS_pp_VehicleAppMode_WSSCurrentVehicleState
#  define Rte_Write_Ctrl_WSS_pp_VehicleAppMode_WSSCurrentVehicleState(data) (Rte_Ctrl_WSS_pp_VehicleAppMode_WSSCurrentVehicleState = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_ActivateSilentCommunication(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_CAN_ActivateSilentCommunication ComMExt_CAN_ActivateSilentCommunication
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_CommControlActivateRx(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_CAN_CommControlActivateRx ComMExt_CAN_CommControlActivateRx
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_CommControlActivateTx(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_CAN_CommControlActivateTx ComMExt_CAN_CommControlActivateTx
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_CommControlDeActivateRx(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_CAN_CommControlDeActivateRx ComMExt_CAN_CommControlDeActivateRx
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_CommControlDeActivateTx(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_CAN_CommControlDeActivateTx ComMExt_CAN_CommControlDeActivateTx
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_CommControlSetDone(Boolean PduInitRequest); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_CAN_CommControlSetDone(arg1) (ComMExt_CAN_CommControlSetDone(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_DeActivateSilentCommunication(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_CAN_DeActivateSilentCommunication ComMExt_CAN_DeActivateSilentCommunication
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_GetCurrentComMode(UInt8 Channel, P2VAR(UInt8, AUTOMATIC, RTE_COMMEXT_APPL_VAR) ComMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_CAN_GetCurrentComMode ComMExt_CAN_GetCurrentComMode
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_ReleaseCommunication(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_CAN_ReleaseCommunication ComMExt_CAN_ReleaseCommunication
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_RequestCommunication(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_CAN_RequestCommunication ComMExt_CAN_RequestCommunication
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_GetBusOffStatus(UInt8 Channel, P2VAR(Boolean, AUTOMATIC, RTE_COMMEXT_APPL_VAR) BusOffStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_GetBusOffStatus ComMExt_GetBusOffStatus
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_Get_MCAN_ERR_PIN_Status(P2VAR(Boolean, AUTOMATIC, RTE_COMMEXT_APPL_VAR) fl_pin_status_BOOL); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_Get_MCAN_ERR_PIN_Status ComMExt_Get_MCAN_ERR_PIN_Status
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_COMMEXT_APPL_CODE) ComMExt_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_Init() (ComMExt_Init(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetAsyncRawAdc(IoHwAb_AdcSignalIdType AdcId, P2VAR(UInt16, AUTOMATIC, RTE_IOHWAB_APPL_VAR) AsyncRawAdc, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpIoHwAb_ADC_GetAsyncRawAdc IoHwAb_GetAsyncRawAdc
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetProcessedAdc(IoHwAb_AdcSignalIdType AdcId, P2VAR(SInt32, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ProcessedAdc, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpIoHwAb_ADC_GetProcessedAdc IoHwAb_GetProcessedAdc
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetSyncRawAdc(IoHwAb_AdcSignalIdType AdcId, P2VAR(UInt16, AUTOMATIC, RTE_IOHWAB_APPL_VAR) SyncRawAdc, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpIoHwAb_ADC_GetSyncRawAdc IoHwAb_GetSyncRawAdc
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, P2VAR(Boolean, AUTOMATIC, RTE_IOHWAB_APPL_VAR) AsyncInput, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpIoHwAb_Din_GetAsyncRawInput IoHwAb_GetAsyncRawInput
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetInputGroup(IoHwAb_DInGroupIdType InputId, P2VAR(UInt32, AUTOMATIC, RTE_IOHWAB_APPL_VAR) SyncInput, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpIoHwAb_Din_GetInputGroup IoHwAb_GetInputGroup
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetProcessedInput(IoHwAb_DInSignalIdType InputId, P2VAR(Boolean, AUTOMATIC, RTE_IOHWAB_APPL_VAR) InputSignal, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpIoHwAb_Din_GetProcessedInput IoHwAb_GetProcessedInput
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, P2VAR(Boolean, AUTOMATIC, RTE_IOHWAB_APPL_VAR) SyncInput, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpIoHwAb_Din_GetSyncRawInput IoHwAb_GetSyncRawInput
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_GetSignalValue(tRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalValue, P2VAR(tRxSignalStatus, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_ComAbsRx_RxCan_GetSignalValue CComAbsMdl_RxCan_GetSignalValue
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalValue, P2VAR(tRxSignalStatus, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalStatus, P2VAR(UInt32, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_ComAbsRx_RxCan_GetSignalValueU8Arr CComAbsMdl_RxCan_GetSignalValueU8Arr
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SetSignalInitValue(tRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalValue); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_ComAbsRx_RxCan_SetSignalInitValue CComAbsMdl_RxCan_SetSignalInitValue
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignaValue, P2VAR(UInt32, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_ComAbsRx_RxCan_SetSignalInitValueU8Arr CComAbsMdl_RxCan_SetSignalInitValueU8Arr
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_ComAbsRx_RxCan_SignalClearJustRcvdStatus(arg1) (CComAbsMdl_RxCan_SignalClearJustRcvdStatus(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, P2VAR(tRxSignalJustRcvdStatus, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pJustRcvdStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_ComAbsRx_RxCan_SignalGetJustRcvdStatus(arg1, arg2) (CComAbsMdl_RxCan_SignalGetJustRcvdStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_ComAbsRx_RxCan_SignalInvalidProcessingControl(arg1, arg2) (CComAbsMdl_RxCan_SignalInvalidProcessingControl(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_ComAbsRx_RxCan_SignalMissingProcessingControl(arg1, arg2) (CComAbsMdl_RxCan_SignalMissingProcessingControl(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_ComAbsRx_RxCan_SignalNRProcessingControl(arg1, arg2) (CComAbsMdl_RxCan_SignalNRProcessingControl(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_NvmWriteStatus(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbs_NvMWriteStatus_NvmWriteStatus MemAbstractMdl_NvmWriteStatus
#  define RTE_START_SEC_NVMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_NVMEXT_APPL_CODE) NvmExt_GetNvMReadAllStatus(P2VAR(Boolean, AUTOMATIC, RTE_NVMEXT_APPL_VAR) Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_NvMExt_GetNvMExtReadAllStatus_NvmExt_GetNvMReadAllStatus(arg1) (NvmExt_GetNvMReadAllStatus(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMEXT_APPL_CODE) NvMExt_CancelSleep(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_CancelSleep NvMExt_CancelSleep
#  define RTE_START_SEC_NVMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMEXT_APPL_CODE) NvMExt_ReadytoSleep(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_ReadytoSleep NvMExt_ReadytoSleep
#  define RTE_START_SEC_NVMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMEXT_APPL_CODE) NvMExt_RequestSleep(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_RequestSleep NvMExt_RequestSleep
#  define Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue CComAbsMdl_RxCan_GetSignalValue
#  define Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr CComAbsMdl_RxCan_GetSignalValueU8Arr
#  define Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue CComAbsMdl_RxCan_SetSignalInitValue
#  define Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr CComAbsMdl_RxCan_SetSignalInitValueU8Arr
#  define Rte_Call_rp_CS_RxCanMdl_RxCan_SignalClearJustRcvdStatus(arg1) (CComAbsMdl_RxCan_SignalClearJustRcvdStatus(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus(arg1, arg2) (CComAbsMdl_RxCan_SignalGetJustRcvdStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_RxCanMdl_RxCan_SignalInvalidProcessingControl(arg1, arg2) (CComAbsMdl_RxCan_SignalInvalidProcessingControl(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_RxCanMdl_RxCan_SignalMissingProcessingControl(arg1, arg2) (CComAbsMdl_RxCan_SignalMissingProcessingControl(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_RxCanMdl_RxCan_SignalNRProcessingControl(arg1, arg2) (CComAbsMdl_RxCan_SignalNRProcessingControl(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_TMEXT_APPL_CODE) TmExt_Timer_IsElapsed(HTimer hTimer, UInt32 Timeout, P2VAR(Boolean, AUTOMATIC, RTE_TMEXT_APPL_VAR) IsElapsed); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_TmExt_Timer_Elapsed_Timer_IsElapsed(arg1, arg2, arg3) (TmExt_Timer_IsElapsed(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_TMEXT_APPL_CODE) TmExt_Timer_Start(HTimer hTimer); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_TmExt_Timer_Start_Timer_Start(arg1) (TmExt_Timer_Start(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_TMEXT_APPL_CODE) TmExt_Timer_IsStarted(HTimer hTimer, P2VAR(Boolean, AUTOMATIC, RTE_TMEXT_APPL_VAR) IsStarted); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_TmExt_Timer_Started_Timer_IsStarted(arg1, arg2) (TmExt_Timer_IsStarted(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_TMEXT_APPL_CODE) TmExt_Timer_Stop(HTimer hTimer); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_TmExt_Timer_Stop_Timer_Stop(arg1) (TmExt_Timer_Stop(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CWARNMSG_CORE_OBSERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CWARNMSG_CORE_OBSERVER_APPL_CODE) CWarnMsg_Core_Observer_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CWARNMSG_CORE_OBSERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_Init_rp_Init_CWarnMsg_Core_Observer_Init() (CWarnMsg_Core_Observer_Init(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CTRL_ILLUMINATION_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CTRL_ILLUMINATION_APPL_CODE) Ctrl_Illumination_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CTRL_ILLUMINATION_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_Init_rp_Init_Ctrl_Illumination_Init() (Ctrl_Illumination_Init(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CTRL_WARNING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CTRL_WARNING_APPL_CODE) Ctrl_warning_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CTRL_WARNING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_Init_rp_Init_Ctrl_warning_Init() (Ctrl_warning_Init(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_FASTGAUGEADAPTER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_FASTGAUGEADAPTER_APPL_CODE) FastGaugeAdapter_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_FASTGAUGEADAPTER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_Init_rp_Init_FastGaugeAdapter_Init() (FastGaugeAdapter_Init(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MDL_DIM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MDL_DIM_APPL_CODE) Mdl_Dim_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MDL_DIM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_Init_rp_Init_Mdl_Dim_Init() (Mdl_Dim_Init(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MDL_GEAR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MDL_GEAR_APPL_CODE) Mdl_Gear_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MDL_GEAR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_Init_rp_Init_Mdl_Gear_Init() (Mdl_Gear_Init(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MDL_LINEAR_INTERPOLATION_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MDL_LINEAR_INTERPOLATION_APPL_CODE) Mdl_Linear_Interpolation_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MDL_LINEAR_INTERPOLATION_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_Init_rp_Init_Mdl_Linear_Interpolation_Init() (Mdl_Linear_Interpolation_Init(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MDL_SPEED_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MDL_SPEED_APPL_CODE) Mdl_Speed_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MDL_SPEED_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_Init_rp_Init_Mdl_Speed_Init() (Mdl_Speed_Init(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MDL_TACHO_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MDL_TACHO_APPL_CODE) Mdl_Tacho_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MDL_TACHO_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_Init_rp_Init_Mdl_Tacho_Init() (Mdl_Tacho_Init(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MDL_TURNHAZARD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MDL_TURNHAZARD_APPL_CODE) Mdl_TurnHazard_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MDL_TURNHAZARD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_Init_rp_Init_Mdl_TurnHazard_Init() (Mdl_TurnHazard_Init(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MDL_WAIRBAG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MDL_WAIRBAG_APPL_CODE) Mdl_wAirbag_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MDL_WAIRBAG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_Init_rp_Init_Mdl_wAirbag_Init() (Mdl_wAirbag_Init(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MDL_WFUELLIDOPEN_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MDL_WFUELLIDOPEN_APPL_CODE) Mdl_wFuelLidOpen_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MDL_WFUELLIDOPEN_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_Init_rp_Init_Mdl_wFuelLidOpen_Init() (Mdl_wFuelLidOpen_Init(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_SLOWGAUGEADAPTER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_SLOWGAUGEADAPTER_APPL_CODE) SlowGaugeAdapter_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_SLOWGAUGEADAPTER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_Init_rp_Init_SlowGaugeAdapter_Init() (SlowGaugeAdapter_Init(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_VIEW_SPEED_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_VIEW_SPEED_APPL_CODE) View_Speed_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_VIEW_SPEED_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_Init_rp_Init_View_Speed_Init() (View_Speed_Init(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_WARNMSG_CORE_TMRSUPPORT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_WARNMSG_CORE_TMRSUPPORT_APPL_CODE) WarnMsg_Core_TmrSupport_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_WARNMSG_CORE_TMRSUPPORT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_Init_rp_Init_WarnMsg_Core_TmrSupport_Init() (WarnMsg_Core_TmrSupport_Init(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define Ctrl_WSS_START_SEC_CODE
# include "Ctrl_WSS_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CtrlWSS_CancelSleep CtrlWSS_CancelSleep
#  define RTE_RUNNABLE_CtrlWSS_ReadytoSleep CtrlWSS_ReadytoSleep
#  define RTE_RUNNABLE_CtrlWSS_RequestSleep CtrlWSS_RequestSleep
#  define RTE_RUNNABLE_Ctrl_WSS_CtrlWSS_NotifyNetworkSleep Ctrl_WSS_CtrlWSS_NotifyNetworkSleep
#  define RTE_RUNNABLE_Ctrl_WSS_GetVariant_Status Ctrl_WSS_GetVariant_Status
#  define RTE_RUNNABLE_Ctrl_WSS_Impl_MainFunction Ctrl_WSS_Impl_MainFunction
#  define RTE_RUNNABLE_Ctrl_WSS_Impl_OnCommand Ctrl_WSS_Impl_OnCommand
#  define RTE_RUNNABLE_Ctrl_WSS_SWCEarlyWakeUpHandle Ctrl_WSS_SWCEarlyWakeUpHandle
#  define RTE_RUNNABLE_Ctrl_WSS_SWCSleepStatus Ctrl_WSS_SWCSleepStatus
# endif

FUNC(Std_ReturnType, Ctrl_WSS_CODE) CtrlWSS_CancelSleep(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Ctrl_WSS_CODE) CtrlWSS_ReadytoSleep(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Ctrl_WSS_CODE) CtrlWSS_RequestSleep(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Ctrl_WSS_CODE) Ctrl_WSS_CtrlWSS_NotifyNetworkSleep(P2VAR(UInt8, AUTOMATIC, RTE_CTRL_WSS_APPL_VAR) NotifyStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Ctrl_WSS_CODE) Ctrl_WSS_GetVariant_Status(UInt8 Variant_Ind, P2VAR(UInt8, AUTOMATIC, RTE_CTRL_WSS_APPL_VAR) Variant_Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Ctrl_WSS_CODE) Ctrl_WSS_Impl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, Ctrl_WSS_CODE) Ctrl_WSS_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Ctrl_WSS_CODE) Ctrl_WSS_SWCEarlyWakeUpHandle(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Ctrl_WSS_CODE) Ctrl_WSS_SWCSleepStatus(eAppMdl AppModule, eSleepSt SleepStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define Ctrl_WSS_STOP_SEC_CODE
# include "Ctrl_WSS_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_TI_ComMExt_E_NOT_OK (1U)

#  define RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK (1U)

#  define RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK (1U)

#  define RTE_E_TI_NvMExt_SleepOperations_E_NOT_OK (1U)

#  define RTE_E_TI_WSS_SWCNotifySleepStatus_E_NOT_OK (1U)

#  define RTE_E_TI_WSS_SleepOperations_E_NOT_OK (1U)

#  define RTE_E_if_CS_ComAbsRx_E_NOT_OK (1U)

#  define RTE_E_if_CS_MemAbs_NvMWriteStatus_E_NOT_OK (1U)

#  define RTE_E_if_CS_ModeOnCommand_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CTRL_WSS_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
