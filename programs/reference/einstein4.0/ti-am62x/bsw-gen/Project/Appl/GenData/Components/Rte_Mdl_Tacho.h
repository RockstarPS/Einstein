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
 *          File:  Rte_Mdl_Tacho.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <Mdl_Tacho>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_MDL_TACHO_H
# define _RTE_MDL_TACHO_H

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

# include "Rte_Mdl_Tacho_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Tacho_pp_Analog_Tacho_Analog_Tacho; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Tacho_pp_Digital_Tacho_Digital_Tacho; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Tacho_pp_Needle_Transparent_Needle_TR; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_Mdl_Tacho_pp_TC_Unit_Digital_TachoUnit; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Tacho_pp_Tacho_RED_Start_RPM_RED_Start_RPM; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Tacho_pp_Tacho_RPM_MAX_REVP_RPM_MAX; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(IgntionSubstateType, RTE_VAR_INIT) Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(ClusterModes, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Speed_pp_SPD_SP1_In_Status_SP1_In_Status; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_pp_Analog_Tacho_Analog_Tacho (0U)
#  define Rte_InitValue_pp_Digital_Tacho_Digital_Tacho (0U)
#  define Rte_InitValue_pp_NE_Out_CalTachoValue (0U)
#  define Rte_InitValue_pp_Needle_Transparent_Needle_TR (0U)
#  define Rte_InitValue_pp_Revp_Disp_REVP_DISP (FALSE)
#  define Rte_InitValue_pp_TC_Unit_Digital_TachoUnit (FALSE)
#  define Rte_InitValue_pp_Tacho_RED_Start_RPM_RED_Start_RPM (0U)
#  define Rte_InitValue_pp_Tacho_RPM_MAX_REVP_RPM_MAX (0U)
#  define Rte_InitValue_pp_Tacho_Revp_RPM_REVP_RPM (0U)
#  define Rte_InitValue_rpIgnSubstate_IgnitionSubstate (0U)
#  define Rte_InitValue_rp_ClusterMode_WSSCurrentClusterMode (0U)
#  define Rte_InitValue_rp_Country_Code_Func_CountryCode_Func (0U)
#  define Rte_InitValue_rp_Dcm_appStop_AppId (0U)
#  define Rte_InitValue_rp_PowerTrain_State_PowerTrain_Flag (0U)
#  define Rte_InitValue_rp_SPD_SP1_In_Status_SP1_In_Status (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_rpIgnSubstate_IgnitionSubstate Rte_Read_Mdl_Tacho_rpIgnSubstate_IgnitionSubstate
#  define Rte_Read_Mdl_Tacho_rpIgnSubstate_IgnitionSubstate(data) (*(data) = Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_ClusterMode_WSSCurrentClusterMode Rte_Read_Mdl_Tacho_rp_ClusterMode_WSSCurrentClusterMode
#  define Rte_Read_Mdl_Tacho_rp_ClusterMode_WSSCurrentClusterMode(data) (*(data) = Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_Country_Code_Func_CountryCode_Func Rte_Read_Mdl_Tacho_rp_Country_Code_Func_CountryCode_Func
#  define Rte_Read_Mdl_Tacho_rp_Country_Code_Func_CountryCode_Func(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_Dcm_appStop_AppId Rte_Read_Mdl_Tacho_rp_Dcm_appStop_AppId
#  define Rte_Read_Mdl_Tacho_rp_Dcm_appStop_AppId(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_PowerTrain_State_PowerTrain_Flag Rte_Read_Mdl_Tacho_rp_PowerTrain_State_PowerTrain_Flag
#  define Rte_Read_Mdl_Tacho_rp_PowerTrain_State_PowerTrain_Flag(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SPD_SP1_In_Status_SP1_In_Status Rte_Read_Mdl_Tacho_rp_SPD_SP1_In_Status_SP1_In_Status
#  define Rte_Read_Mdl_Tacho_rp_SPD_SP1_In_Status_SP1_In_Status(data) (*(data) = Rte_Mdl_Speed_pp_SPD_SP1_In_Status_SP1_In_Status, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_pp_Analog_Tacho_Analog_Tacho Rte_Write_Mdl_Tacho_pp_Analog_Tacho_Analog_Tacho
#  define Rte_Write_Mdl_Tacho_pp_Analog_Tacho_Analog_Tacho(data) (Rte_Mdl_Tacho_pp_Analog_Tacho_Analog_Tacho = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_Digital_Tacho_Digital_Tacho Rte_Write_Mdl_Tacho_pp_Digital_Tacho_Digital_Tacho
#  define Rte_Write_Mdl_Tacho_pp_Digital_Tacho_Digital_Tacho(data) (Rte_Mdl_Tacho_pp_Digital_Tacho_Digital_Tacho = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_NE_Out_CalTachoValue Rte_Write_Mdl_Tacho_pp_NE_Out_CalTachoValue
#  define Rte_Write_Mdl_Tacho_pp_NE_Out_CalTachoValue(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_Needle_Transparent_Needle_TR Rte_Write_Mdl_Tacho_pp_Needle_Transparent_Needle_TR
#  define Rte_Write_Mdl_Tacho_pp_Needle_Transparent_Needle_TR(data) (Rte_Mdl_Tacho_pp_Needle_Transparent_Needle_TR = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_Revp_Disp_REVP_DISP Rte_Write_Mdl_Tacho_pp_Revp_Disp_REVP_DISP
#  define Rte_Write_Mdl_Tacho_pp_Revp_Disp_REVP_DISP(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_TC_Unit_Digital_TachoUnit Rte_Write_Mdl_Tacho_pp_TC_Unit_Digital_TachoUnit
#  define Rte_Write_Mdl_Tacho_pp_TC_Unit_Digital_TachoUnit(data) (Rte_Mdl_Tacho_pp_TC_Unit_Digital_TachoUnit = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_Tacho_RED_Start_RPM_RED_Start_RPM Rte_Write_Mdl_Tacho_pp_Tacho_RED_Start_RPM_RED_Start_RPM
#  define Rte_Write_Mdl_Tacho_pp_Tacho_RED_Start_RPM_RED_Start_RPM(data) (Rte_Mdl_Tacho_pp_Tacho_RED_Start_RPM_RED_Start_RPM = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_Tacho_RPM_MAX_REVP_RPM_MAX Rte_Write_Mdl_Tacho_pp_Tacho_RPM_MAX_REVP_RPM_MAX
#  define Rte_Write_Mdl_Tacho_pp_Tacho_RPM_MAX_REVP_RPM_MAX(data) (Rte_Mdl_Tacho_pp_Tacho_RPM_MAX_REVP_RPM_MAX = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_Tacho_Revp_RPM_REVP_RPM Rte_Write_Mdl_Tacho_pp_Tacho_Revp_RPM_REVP_RPM
#  define Rte_Write_Mdl_Tacho_pp_Tacho_Revp_RPM_REVP_RPM(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_GetSignalValue(tRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalValue, P2VAR(tRxSignalStatus, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue CComAbsMdl_RxCan_GetSignalValue
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalValue, P2VAR(tRxSignalStatus, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalStatus, P2VAR(UInt32, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr CComAbsMdl_RxCan_GetSignalValueU8Arr
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SetSignalInitValue(tRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalValue); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue CComAbsMdl_RxCan_SetSignalInitValue
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignaValue, P2VAR(UInt32, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr CComAbsMdl_RxCan_SetSignalInitValueU8Arr
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_RxCanMdl_RxCan_SignalClearJustRcvdStatus(arg1) (CComAbsMdl_RxCan_SignalClearJustRcvdStatus(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, P2VAR(tRxSignalJustRcvdStatus, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pJustRcvdStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus(arg1, arg2) (CComAbsMdl_RxCan_SignalGetJustRcvdStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_RxCanMdl_RxCan_SignalInvalidProcessingControl(arg1, arg2) (CComAbsMdl_RxCan_SignalInvalidProcessingControl(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_RxCanMdl_RxCan_SignalMissingProcessingControl(arg1, arg2) (CComAbsMdl_RxCan_SignalMissingProcessingControl(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_RxCanMdl_RxCan_SignalNRProcessingControl(arg1, arg2) (CComAbsMdl_RxCan_SignalNRProcessingControl(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_Get_Variant_Cfg_Get_Variant_Config_State(arg1, arg2) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_NE1_Notify_NE1_Recieve_Notify_Value(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define Mdl_Tacho_START_SEC_CODE
# include "Mdl_Tacho_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Mdl_Tacho_Init Mdl_Tacho_Init
#  define RTE_RUNNABLE_Mdl_Tacho_Task Mdl_Tacho_Task
# endif

FUNC(void, Mdl_Tacho_CODE) Mdl_Tacho_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Mdl_Tacho_CODE) Mdl_Tacho_Task(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define Mdl_Tacho_STOP_SEC_CODE
# include "Mdl_Tacho_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_if_CS_ComAbsRx_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_MDL_TACHO_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
