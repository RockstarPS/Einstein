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
 *          File:  Rte_FastGaugeAdapter.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <FastGaugeAdapter>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_FASTGAUGEADAPTER_H
# define _RTE_FASTGAUGEADAPTER_H

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

# include "Rte_FastGaugeAdapter_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(IgntionSubstateType, RTE_VAR_INIT) Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Tacho_pp_Analog_Tacho_Analog_Tacho; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(ClusterModes, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Tacho_pp_Digital_Tacho_Digital_Tacho; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_View_Speed_pp_Display_speed_Value_Digital_Speed_Value; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(HMIReadySts_Type, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_HMIReady_HMI_ReadyStatus; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Tacho_pp_Needle_Transparent_Needle_TR; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_View_Speed_pp_SubDisplaySpeed_Value_SubDispSpeedVal; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_Mdl_Tacho_pp_TC_Unit_Digital_TachoUnit; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Tacho_pp_Tacho_RED_Start_RPM_RED_Start_RPM; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Tacho_pp_Tacho_RPM_MAX_REVP_RPM_MAX; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_rpIgnSubstate_IgnitionSubstate (0U)
#  define Rte_InitValue_rp_Analog_Tacho_Analog_Tacho (0U)
#  define Rte_InitValue_rp_ClusterMode_WSSCurrentClusterMode (0U)
#  define Rte_InitValue_rp_Dcm_appStop_AppId (0U)
#  define Rte_InitValue_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value (0U)
#  define Rte_InitValue_rp_Digital_Tacho_Digital_Tacho (0U)
#  define Rte_InitValue_rp_DispDistanceUnit_DisplayUnit (0U)
#  define Rte_InitValue_rp_DispSpeedA_DispSpeedVal (0U)
#  define Rte_InitValue_rp_Display_speed_Value_Digital_Speed_Value (0U)
#  define Rte_InitValue_rp_HMIReadyState_HMI_ReadyStatus (0U)
#  define Rte_InitValue_rp_Needle_Transparent_Needle_TR (0U)
#  define Rte_InitValue_rp_PowerTrain_State_PowerTrain_Flag (0U)
#  define Rte_InitValue_rp_SubDisplaySpeed_Value_SubDispSpeedVal (0U)
#  define Rte_InitValue_rp_TC_Unit_Digital_TachoUnit (FALSE)
#  define Rte_InitValue_rp_Tacho_RED_Start_RPM_RED_Start_RPM (0U)
#  define Rte_InitValue_rp_Tacho_RPM_MAX_REVP_RPM_MAX (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_FastGaugeAdapter_pp_FastGaugeInfo_FastGaugeInfoData(P2CONST(SFastGaugeInfo, AUTOMATIC, RTE_FASTGAUGEADAPTER_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_rpIgnSubstate_IgnitionSubstate Rte_Read_FastGaugeAdapter_rpIgnSubstate_IgnitionSubstate
#  define Rte_Read_FastGaugeAdapter_rpIgnSubstate_IgnitionSubstate(data) (*(data) = Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_Analog_Tacho_Analog_Tacho Rte_Read_FastGaugeAdapter_rp_Analog_Tacho_Analog_Tacho
#  define Rte_Read_FastGaugeAdapter_rp_Analog_Tacho_Analog_Tacho(data) (*(data) = Rte_Mdl_Tacho_pp_Analog_Tacho_Analog_Tacho, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_ClusterMode_WSSCurrentClusterMode Rte_Read_FastGaugeAdapter_rp_ClusterMode_WSSCurrentClusterMode
#  define Rte_Read_FastGaugeAdapter_rp_ClusterMode_WSSCurrentClusterMode(data) (*(data) = Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_Dcm_appStop_AppId Rte_Read_FastGaugeAdapter_rp_Dcm_appStop_AppId
#  define Rte_Read_FastGaugeAdapter_rp_Dcm_appStop_AppId(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value Rte_Read_FastGaugeAdapter_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value
#  define Rte_Read_FastGaugeAdapter_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_Digital_Tacho_Digital_Tacho Rte_Read_FastGaugeAdapter_rp_Digital_Tacho_Digital_Tacho
#  define Rte_Read_FastGaugeAdapter_rp_Digital_Tacho_Digital_Tacho(data) (*(data) = Rte_Mdl_Tacho_pp_Digital_Tacho_Digital_Tacho, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_DispDistanceUnit_DisplayUnit Rte_Read_FastGaugeAdapter_rp_DispDistanceUnit_DisplayUnit
#  define Rte_Read_FastGaugeAdapter_rp_DispDistanceUnit_DisplayUnit(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_DispSpeedA_DispSpeedVal Rte_Read_FastGaugeAdapter_rp_DispSpeedA_DispSpeedVal
#  define Rte_Read_FastGaugeAdapter_rp_DispSpeedA_DispSpeedVal(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_Display_speed_Value_Digital_Speed_Value Rte_Read_FastGaugeAdapter_rp_Display_speed_Value_Digital_Speed_Value
#  define Rte_Read_FastGaugeAdapter_rp_Display_speed_Value_Digital_Speed_Value(data) (*(data) = Rte_View_Speed_pp_Display_speed_Value_Digital_Speed_Value, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_HMIReadyState_HMI_ReadyStatus Rte_Read_FastGaugeAdapter_rp_HMIReadyState_HMI_ReadyStatus
#  define Rte_Read_FastGaugeAdapter_rp_HMIReadyState_HMI_ReadyStatus(data) (*(data) = Rte_Ctrl_WSS_pp_HMIReady_HMI_ReadyStatus, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_Needle_Transparent_Needle_TR Rte_Read_FastGaugeAdapter_rp_Needle_Transparent_Needle_TR
#  define Rte_Read_FastGaugeAdapter_rp_Needle_Transparent_Needle_TR(data) (*(data) = Rte_Mdl_Tacho_pp_Needle_Transparent_Needle_TR, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_PowerTrain_State_PowerTrain_Flag Rte_Read_FastGaugeAdapter_rp_PowerTrain_State_PowerTrain_Flag
#  define Rte_Read_FastGaugeAdapter_rp_PowerTrain_State_PowerTrain_Flag(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SubDisplaySpeed_Value_SubDispSpeedVal Rte_Read_FastGaugeAdapter_rp_SubDisplaySpeed_Value_SubDispSpeedVal
#  define Rte_Read_FastGaugeAdapter_rp_SubDisplaySpeed_Value_SubDispSpeedVal(data) (*(data) = Rte_View_Speed_pp_SubDisplaySpeed_Value_SubDispSpeedVal, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_TC_Unit_Digital_TachoUnit Rte_Read_FastGaugeAdapter_rp_TC_Unit_Digital_TachoUnit
#  define Rte_Read_FastGaugeAdapter_rp_TC_Unit_Digital_TachoUnit(data) (*(data) = Rte_Mdl_Tacho_pp_TC_Unit_Digital_TachoUnit, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_Tacho_RED_Start_RPM_RED_Start_RPM Rte_Read_FastGaugeAdapter_rp_Tacho_RED_Start_RPM_RED_Start_RPM
#  define Rte_Read_FastGaugeAdapter_rp_Tacho_RED_Start_RPM_RED_Start_RPM(data) (*(data) = Rte_Mdl_Tacho_pp_Tacho_RED_Start_RPM_RED_Start_RPM, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_Tacho_RPM_MAX_REVP_RPM_MAX Rte_Read_FastGaugeAdapter_rp_Tacho_RPM_MAX_REVP_RPM_MAX
#  define Rte_Read_FastGaugeAdapter_rp_Tacho_RPM_MAX_REVP_RPM_MAX(data) (*(data) = Rte_Mdl_Tacho_pp_Tacho_RPM_MAX_REVP_RPM_MAX, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_pp_FastGaugeInfo_FastGaugeInfoData Rte_Write_FastGaugeAdapter_pp_FastGaugeInfo_FastGaugeInfoData


# endif /* !defined(RTE_CORE) */


# define FastGaugeAdapter_START_SEC_CODE
# include "FastGaugeAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_FastGaugeAdapter_Init FastGaugeAdapter_Init
#  define RTE_RUNNABLE_FastGaugeAdapter_Task FastGaugeAdapter_Task
# endif

FUNC(void, FastGaugeAdapter_CODE) FastGaugeAdapter_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, FastGaugeAdapter_CODE) FastGaugeAdapter_Task(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define FastGaugeAdapter_STOP_SEC_CODE
# include "FastGaugeAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_FASTGAUGEADAPTER_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
