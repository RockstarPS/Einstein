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
 *          File:  Rte_Mdl_Speed.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <Mdl_Speed>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_MDL_SPEED_H
# define _RTE_MDL_SPEED_H

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

# include "Rte_Mdl_Speed_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Speed_pp_SPD_SP1_In_Status_SP1_In_Status; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Speed_pp_SPD_Selection_Table_Speed_Selection_Table; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Speed_pp_SPD_Target2_Status_Spd_Target2_Status; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Speed_pp_SPD_Target_Status_Spd_Target_Status; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Speed_pp_SPD_Trim2_Status_Spd_Trim2_Status; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Speed_pp_SPD_Trim_Status_Spd_Trim_Status; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(IgntionSubstateType, RTE_VAR_INIT) Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(ClusterModes, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_pp_SPD_SP1_In_Status_SP1_In_Status (0U)
#  define Rte_InitValue_pp_SPD_Selection_Table_Speed_Selection_Table (0U)
#  define Rte_InitValue_pp_SPD_Target2_Status_Spd_Target2_Status (0U)
#  define Rte_InitValue_pp_SPD_Target_Status_Spd_Target_Status (0U)
#  define Rte_InitValue_pp_SPD_Trim2_Status_Spd_Trim2_Status (0U)
#  define Rte_InitValue_pp_SPD_Trim_Status_Spd_Trim_Status (0U)
#  define Rte_InitValue_rpIgnSubstate_IgnitionSubstate (0U)
#  define Rte_InitValue_rp_ClusterMode_WSSCurrentClusterMode (0U)
#  define Rte_InitValue_rp_Countrycode_Func_CountryCode_Func (0U)
#  define Rte_InitValue_rp_Dcm_appStop_AppId (0U)
#  define Rte_InitValue_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value (0U)
#  define Rte_InitValue_rp_DispDistanceUnit_DisplayUnit (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_rpIgnSubstate_IgnitionSubstate Rte_Read_Mdl_Speed_rpIgnSubstate_IgnitionSubstate
#  define Rte_Read_Mdl_Speed_rpIgnSubstate_IgnitionSubstate(data) (*(data) = Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_ClusterMode_WSSCurrentClusterMode Rte_Read_Mdl_Speed_rp_ClusterMode_WSSCurrentClusterMode
#  define Rte_Read_Mdl_Speed_rp_ClusterMode_WSSCurrentClusterMode(data) (*(data) = Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_Countrycode_Func_CountryCode_Func Rte_Read_Mdl_Speed_rp_Countrycode_Func_CountryCode_Func
#  define Rte_Read_Mdl_Speed_rp_Countrycode_Func_CountryCode_Func(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_Dcm_appStop_AppId Rte_Read_Mdl_Speed_rp_Dcm_appStop_AppId
#  define Rte_Read_Mdl_Speed_rp_Dcm_appStop_AppId(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value Rte_Read_Mdl_Speed_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value
#  define Rte_Read_Mdl_Speed_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_DispDistanceUnit_DisplayUnit Rte_Read_Mdl_Speed_rp_DispDistanceUnit_DisplayUnit
#  define Rte_Read_Mdl_Speed_rp_DispDistanceUnit_DisplayUnit(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_pp_SPD_SP1_In_Status_SP1_In_Status Rte_Write_Mdl_Speed_pp_SPD_SP1_In_Status_SP1_In_Status
#  define Rte_Write_Mdl_Speed_pp_SPD_SP1_In_Status_SP1_In_Status(data) (Rte_Mdl_Speed_pp_SPD_SP1_In_Status_SP1_In_Status = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SPD_Selection_Table_Speed_Selection_Table Rte_Write_Mdl_Speed_pp_SPD_Selection_Table_Speed_Selection_Table
#  define Rte_Write_Mdl_Speed_pp_SPD_Selection_Table_Speed_Selection_Table(data) (Rte_Mdl_Speed_pp_SPD_Selection_Table_Speed_Selection_Table = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SPD_Target2_Status_Spd_Target2_Status Rte_Write_Mdl_Speed_pp_SPD_Target2_Status_Spd_Target2_Status
#  define Rte_Write_Mdl_Speed_pp_SPD_Target2_Status_Spd_Target2_Status(data) (Rte_Mdl_Speed_pp_SPD_Target2_Status_Spd_Target2_Status = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SPD_Target_Status_Spd_Target_Status Rte_Write_Mdl_Speed_pp_SPD_Target_Status_Spd_Target_Status
#  define Rte_Write_Mdl_Speed_pp_SPD_Target_Status_Spd_Target_Status(data) (Rte_Mdl_Speed_pp_SPD_Target_Status_Spd_Target_Status = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SPD_Trim2_Status_Spd_Trim2_Status Rte_Write_Mdl_Speed_pp_SPD_Trim2_Status_Spd_Trim2_Status
#  define Rte_Write_Mdl_Speed_pp_SPD_Trim2_Status_Spd_Trim2_Status(data) (Rte_Mdl_Speed_pp_SPD_Trim2_Status_Spd_Trim2_Status = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SPD_Trim_Status_Spd_Trim_Status Rte_Write_Mdl_Speed_pp_SPD_Trim_Status_Spd_Trim_Status
#  define Rte_Write_Mdl_Speed_pp_SPD_Trim_Status_Spd_Trim_Status(data) (Rte_Mdl_Speed_pp_SPD_Trim_Status_Spd_Trim_Status = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
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
#  define RTE_START_SEC_MDL_LINEAR_INTERPOLATION_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MDL_LINEAR_INTERPOLATION_APPL_CODE) Mdl_Linear_Interpolation_Get_LinearInterpolateByte(P2VAR(UInt8, AUTOMATIC, RTE_MDL_LINEAR_INTERPOLATION_APPL_VAR) ptr_table, UInt8 lookupvalue, P2VAR(UInt8, AUTOMATIC, RTE_MDL_LINEAR_INTERPOLATION_APPL_VAR) Ptr_Lin_Return); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MDL_LINEAR_INTERPOLATION_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_LinerInterpolation_Get_LinearInterpolateByte(arg1, arg2, arg3) (Mdl_Linear_Interpolation_Get_LinearInterpolateByte(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MDL_LINEAR_INTERPOLATION_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MDL_LINEAR_INTERPOLATION_APPL_CODE) Mdl_Linear_Interpolation_Get_LinearInterpolateSByte(P2VAR(SInt8, AUTOMATIC, RTE_MDL_LINEAR_INTERPOLATION_APPL_VAR) ptr_table, SInt8 lookupvalue, P2VAR(SInt8, AUTOMATIC, RTE_MDL_LINEAR_INTERPOLATION_APPL_VAR) Ptr_Lin_Return); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MDL_LINEAR_INTERPOLATION_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_LinerInterpolation_Get_LinearInterpolateSByte(arg1, arg2, arg3) (Mdl_Linear_Interpolation_Get_LinearInterpolateSByte(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MDL_LINEAR_INTERPOLATION_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MDL_LINEAR_INTERPOLATION_APPL_CODE) Mdl_Linear_Interpolation_Get_LinearInterpolateSWord(P2VAR(SInt16, AUTOMATIC, RTE_MDL_LINEAR_INTERPOLATION_APPL_VAR) ptr_table, SInt16 lookupvalue, P2VAR(SInt16, AUTOMATIC, RTE_MDL_LINEAR_INTERPOLATION_APPL_VAR) Ptr_Lin_Return); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MDL_LINEAR_INTERPOLATION_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_LinerInterpolation_Get_LinearInterpolateSWord(arg1, arg2, arg3) (Mdl_Linear_Interpolation_Get_LinearInterpolateSWord(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MDL_LINEAR_INTERPOLATION_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MDL_LINEAR_INTERPOLATION_APPL_CODE) Mdl_Linear_Interpolation_Get_LinearInterpolateWord(P2VAR(UInt16, AUTOMATIC, RTE_MDL_LINEAR_INTERPOLATION_APPL_VAR) ptr_table, UInt16 lookupvalue, P2VAR(UInt16, AUTOMATIC, RTE_MDL_LINEAR_INTERPOLATION_APPL_VAR) Ptr_Lin_Return); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MDL_LINEAR_INTERPOLATION_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_LinerInterpolation_Get_LinearInterpolateWord(arg1, arg2, arg3) (Mdl_Linear_Interpolation_Get_LinearInterpolateWord(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Audio_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Audio_Element(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Audio_Element MemAbstractMdl_Get_BsConst_Audio_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte(P2VAR(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte(P2VAR(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(P2VAR(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(P2VAR(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1 MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(P2VAR(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(P2VAR(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2 MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Communication_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Communication_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Communication_Element MemAbstractMdl_Get_BsConst_Communication_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1 MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2 MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1 MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2 MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_SafeCopy1(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy1 MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_SafeCopy1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_SafeCopy2(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy2 MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_SafeCopy2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_SafeCopy1(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy1 MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_SafeCopy1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_SafeCopy2(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy2 MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_SafeCopy2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_EngOffTimer_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_EngOffTimer_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_EngOffTimer_Element MemAbstractMdl_Get_BsConst_EngOffTimer_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_FuelGauge_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_FuelGauge_Element(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_FuelGauge_Element MemAbstractMdl_Get_BsConst_FuelGauge_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1 MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2 MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1 MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2 MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_OilGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_OilGauge_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_OilGauge_Element MemAbstractMdl_Get_BsConst_OilGauge_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1 MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2 MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1 MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2 MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_PowerGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_PowerGauge_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PowerGauge_Element MemAbstractMdl_Get_BsConst_PowerGauge_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Power_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Power_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Power_Element MemAbstractMdl_Get_BsConst_Power_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_RealTimeClock_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_RealTimeClock_Element(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_RealTimeClock_Element MemAbstractMdl_Get_BsConst_RealTimeClock_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_ServiceReminder_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_ServiceReminder_Element(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_ServiceReminder_Element MemAbstractMdl_Get_BsConst_ServiceReminder_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_SpeedoGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_SpeedoGauge_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_SpeedoGauge_Element MemAbstractMdl_Get_BsConst_SpeedoGauge_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_TachoGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_TachoGauge_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TachoGauge_Element MemAbstractMdl_Get_BsConst_TachoGauge_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_TempGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_TempGauge_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TempGauge_Element MemAbstractMdl_Get_BsConst_TempGauge_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1 MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2 MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1 MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2 MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_TripComputer_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_TripComputer_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TripComputer_Element MemAbstractMdl_Get_BsConst_TripComputer_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Warning_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Warning_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Warning_Element MemAbstractMdl_Get_BsConst_Warning_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsCys_Certicificate_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsCys_Certicificate_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsCys_Certicificate_Element MemAbstractMdl_Get_BsCys_Certicificate_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsDiag_Dtc_Element(P2VAR(Rte_DT_Arr_u8_2048_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsDiag_Dtc_Element(P2VAR(Arr_u8_2048, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_Dtc_Element MemAbstractMdl_Get_BsDiag_Dtc_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsDiag_ErrorRecord_Element(P2VAR(Rte_DT_Arr_u8_1024_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsDiag_ErrorRecord_Element(P2VAR(Arr_u8_1024, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_ErrorRecord_Element MemAbstractMdl_Get_BsDiag_ErrorRecord_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Audio_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Audio_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Audio_Element MemAbstractMdl_Get_BsReten_Audio_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Communication_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Communication_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Communication_Element MemAbstractMdl_Get_BsReten_Communication_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Display_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Display_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Display_Element MemAbstractMdl_Get_BsReten_Display_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Gauges_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Gauges_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Gauges_Element MemAbstractMdl_Get_BsReten_Gauges_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Illumination_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Illumination_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Illumination_Element MemAbstractMdl_Get_BsReten_Illumination_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Odometer_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Odometer_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Odometer_Element MemAbstractMdl_Get_BsReten_Odometer_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Personalization_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Personalization_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Personalization_Element MemAbstractMdl_Get_BsReten_Personalization_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Power_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Power_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Power_Element MemAbstractMdl_Get_BsReten_Power_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_RealTimeClock_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_RealTimeClock_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_RealTimeClock_Element MemAbstractMdl_Get_BsReten_RealTimeClock_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Tripcomputer_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Tripcomputer_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Tripcomputer_Element MemAbstractMdl_Get_BsReten_Tripcomputer_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Warning_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Warning_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Warning_Element MemAbstractMdl_Get_BsReten_Warning_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_CusDlt_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_CusDlt_Element(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_CusDlt_Element MemAbstractMdl_Get_BsRt_CusDlt_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_FuelGauge_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_FuelGauge_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_FuelGauge_Element MemAbstractMdl_Get_BsRt_FuelGauge_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_Illumination_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_Illumination_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Illumination_Element MemAbstractMdl_Get_BsRt_Illumination_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_Odometer_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_Odometer_Element(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Odometer_Element MemAbstractMdl_Get_BsRt_Odometer_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_OilGauge_Element(P2VAR(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_OilGauge_Element(P2VAR(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_OilGauge_Element MemAbstractMdl_Get_BsRt_OilGauge_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_Personalization_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_Personalization_Element(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Personalization_Element MemAbstractMdl_Get_BsRt_Personalization_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_PowerGauge_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_PowerGauge_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_PowerGauge_Element MemAbstractMdl_Get_BsRt_PowerGauge_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_RealTimeClock_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_RealTimeClock_Element(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_RealTimeClock_Element MemAbstractMdl_Get_BsRt_RealTimeClock_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_SpeedoGauge_Element(P2VAR(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_SpeedoGauge_Element(P2VAR(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_SpeedoGauge_Element MemAbstractMdl_Get_BsRt_SpeedoGauge_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_TachoGauge_Element(P2VAR(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_TachoGauge_Element(P2VAR(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TachoGauge_Element MemAbstractMdl_Get_BsRt_TachoGauge_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_TempGauge_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_TempGauge_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TempGauge_Element MemAbstractMdl_Get_BsRt_TempGauge_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_TripComputer_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_TripComputer_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TripComputer_Element MemAbstractMdl_Get_BsRt_TripComputer_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_Warning_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_Warning_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Warning_Element MemAbstractMdl_Get_BsRt_Warning_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_AssemblyManufacturingDate(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_AssemblyManufacturingDate(P2VAR(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyManufacturingDate MemAbstractMdl_Get_BsShare_AssemblyManufacturingDate
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_AssemblyPlantNumber(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_AssemblyPlantNumber(P2VAR(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyPlantNumber MemAbstractMdl_Get_BsShare_AssemblyPlantNumber
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_EcuPartNumber_Element(P2VAR(Rte_DT_Arr_u8_61_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_EcuPartNumber_Element(P2VAR(Arr_u8_61, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_EcuPartNumber_Element MemAbstractMdl_Get_BsShare_EcuPartNumber_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_HWModification(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_HWModification MemAbstractMdl_Get_BsShare_HWModification
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_PCBSerialNumber(P2VAR(Rte_DT_Arr_u8_9_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_PCBSerialNumber(P2VAR(Arr_u8_9, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_PCBSerialNumber MemAbstractMdl_Get_BsShare_PCBSerialNumber
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_ProductSerialNumber(P2VAR(Rte_DT_Arr_u8_10_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_ProductSerialNumber(P2VAR(Arr_u8_10, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_ProductSerialNumber MemAbstractMdl_Get_BsShare_ProductSerialNumber
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SMTManufacturingDate(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SMTManufacturingDate(P2VAR(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTManufacturingDate MemAbstractMdl_Get_BsShare_SMTManufacturingDate
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SMTPlantNumber(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SMTPlantNumber(P2VAR(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTPlantNumber MemAbstractMdl_Get_BsShare_SMTPlantNumber
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotaFinPrint_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotaFinPrint_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaFinPrint_Element MemAbstractMdl_Get_BsShare_SwUpdFotaFinPrint_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotaMode_Element(P2VAR(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotaMode_Element(P2VAR(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaMode_Element MemAbstractMdl_Get_BsShare_SwUpdFotaMode_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotaStatus_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotaStatus_Element(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaStatus_Element MemAbstractMdl_Get_BsShare_SwUpdFotaStatus_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotadecrypt_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotadecrypt_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotadecrypt_Element MemAbstractMdl_Get_BsShare_SwUpdFotadecrypt_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SwUpdReflash_Element(P2VAR(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SwUpdReflash_Element(P2VAR(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdReflash_Element MemAbstractMdl_Get_BsShare_SwUpdReflash_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_VehicleConfig_Element(P2VAR(Rte_DT_Arr_u8_256_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_VehicleConfig_Element(P2VAR(Arr_u8_256, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VehicleConfig_Element MemAbstractMdl_Get_BsShare_VehicleConfig_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_VisMeet_EOLEntry_Element(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_EOLEntry_Element MemAbstractMdl_Get_BsShare_VisMeet_EOLEntry_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_VisMeet_Element(P2VAR(Rte_DT_Arr_u8_46_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_VisMeet_Element(P2VAR(Arr_u8_46, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_Element MemAbstractMdl_Get_BsShare_VisMeet_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_VisteonPCBPartNumber(P2VAR(Rte_DT_Arr_u8_17_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_VisteonPCBPartNumber(P2VAR(Arr_u8_17, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPCBPartNumber MemAbstractMdl_Get_BsShare_VisteonPCBPartNumber
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_VisteonPartNumber(P2VAR(Rte_DT_Arr_u8_17_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_VisteonPartNumber(P2VAR(Arr_u8_17, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPartNumber MemAbstractMdl_Get_BsShare_VisteonPartNumber
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_RefCys_Certicificate1_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_RefCys_Certicificate1_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate1_Element MemAbstractMdl_Get_RefCys_Certicificate1_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_RefCys_Certicificate_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_RefCys_Certicificate_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate_Element MemAbstractMdl_Get_RefCys_Certicificate_Element


# endif /* !defined(RTE_CORE) */


# define Mdl_Speed_START_SEC_CODE
# include "Mdl_Speed_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Mdl_Speed_Init Mdl_Speed_Init
#  define RTE_RUNNABLE_Mdl_Speed_Task Mdl_Speed_Task
# endif

FUNC(void, Mdl_Speed_CODE) Mdl_Speed_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Mdl_Speed_CODE) Mdl_Speed_Task(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define Mdl_Speed_STOP_SEC_CODE
# include "Mdl_Speed_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK (1U)

#  define RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK (1U)

#  define RTE_E_if_CS_MemAbsGet_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_MDL_SPEED_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
