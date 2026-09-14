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
 *          File:  Rte_Mdl_Airbag.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <Mdl_Airbag>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_MDL_AIRBAG_H
# define _RTE_MDL_AIRBAG_H

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

# include "Rte_Mdl_Airbag_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(IgntionSubstateType, RTE_VAR_INIT) Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(ClusterModes, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(VehicleActiveModes, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_VehicleAppMode_WSSCurrentVehicleState; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_Airbag_pp_Airbag_TT_Status_CurrentTelltaleStatus; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_pp_Airbag_TT_Status_CurrentTelltaleStatus (0U)
#  define Rte_InitValue_rpIgnSubstate_IgnitionSubstate (0U)
#  define Rte_InitValue_rp_ClusterMode_WSSCurrentClusterMode (0U)
#  define Rte_InitValue_rp_VehicleAppMode_WSSCurrentVehicleState (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_rpIgnSubstate_IgnitionSubstate Rte_Read_Mdl_Airbag_rpIgnSubstate_IgnitionSubstate
#  define Rte_Read_Mdl_Airbag_rpIgnSubstate_IgnitionSubstate(data) (*(data) = Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_ClusterMode_WSSCurrentClusterMode Rte_Read_Mdl_Airbag_rp_ClusterMode_WSSCurrentClusterMode
#  define Rte_Read_Mdl_Airbag_rp_ClusterMode_WSSCurrentClusterMode(data) (*(data) = Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_VehicleAppMode_WSSCurrentVehicleState Rte_Read_Mdl_Airbag_rp_VehicleAppMode_WSSCurrentVehicleState
#  define Rte_Read_Mdl_Airbag_rp_VehicleAppMode_WSSCurrentVehicleState(data) (*(data) = Rte_Ctrl_WSS_pp_VehicleAppMode_WSSCurrentVehicleState, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_pp_Airbag_TT_Status_CurrentTelltaleStatus Rte_Write_Mdl_Airbag_pp_Airbag_TT_Status_CurrentTelltaleStatus
#  define Rte_Write_Mdl_Airbag_pp_Airbag_TT_Status_CurrentTelltaleStatus(data) (Rte_Mdl_Airbag_pp_Airbag_TT_Status_CurrentTelltaleStatus = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CCOMABSMDLSAFE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDLSAFE_APPL_CODE) CComAbsMdlSafe_RxCan_GetSignalValue(tSafeRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDLSAFE_APPL_VAR) pSignalValue, P2VAR(tSafeRxSignalStatus, AUTOMATIC, RTE_CCOMABSMDLSAFE_APPL_VAR) pSignalStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDLSAFE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_CanAdapterRx_RxCan_GetSignalValue CComAbsMdlSafe_RxCan_GetSignalValue
#  define RTE_START_SEC_CCOMABSMDLSAFE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDLSAFE_APPL_CODE) CComAbsMdlSafe_RxCan_GetSignalValueU8Arr(tSafeRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDLSAFE_APPL_VAR) pSignalValue, P2VAR(tSafeRxSignalStatus, AUTOMATIC, RTE_CCOMABSMDLSAFE_APPL_VAR) pSignalStatus, P2VAR(UInt32, AUTOMATIC, RTE_CCOMABSMDLSAFE_APPL_VAR) pSignalLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDLSAFE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_CanAdapterRx_RxCan_GetSignalValueU8Arr CComAbsMdlSafe_RxCan_GetSignalValueU8Arr
#  define RTE_START_SEC_CCOMABSMDLSAFE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDLSAFE_APPL_CODE) CComAbsMdlSafe_RxCan_SetSignalInitValue(tSafeRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDLSAFE_APPL_VAR) pSignalValue); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDLSAFE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_CanAdapterRx_RxCan_SetSignalInitValue CComAbsMdlSafe_RxCan_SetSignalInitValue
#  define RTE_START_SEC_CCOMABSMDLSAFE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDLSAFE_APPL_CODE) CComAbsMdlSafe_RxCan_SetSignalInitValueU8Arr(tSafeRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDLSAFE_APPL_VAR) pSignaValue, P2VAR(UInt32, AUTOMATIC, RTE_CCOMABSMDLSAFE_APPL_VAR) pSignalLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDLSAFE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_CanAdapterRx_RxCan_SetSignalInitValueU8Arr CComAbsMdlSafe_RxCan_SetSignalInitValueU8Arr
#  define RTE_START_SEC_CCOMABSMDLSAFE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDLSAFE_APPL_CODE) CComAbsMdlSafe_RxCan_SignalClearJustRcvdStatus(tSafeRxSignalId SignalId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDLSAFE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_CanAdapterRx_RxCan_SignalClearJustRcvdStatus(arg1) (CComAbsMdlSafe_RxCan_SignalClearJustRcvdStatus(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDLSAFE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDLSAFE_APPL_CODE) CComAbsMdlSafe_RxCan_SignalGetJustRcvdStatus(tSafeRxSignalId SignalId, P2VAR(tSafeRxSignalJustRcvdStatus, AUTOMATIC, RTE_CCOMABSMDLSAFE_APPL_VAR) pJustRcvdStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDLSAFE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_CanAdapterRx_RxCan_SignalGetJustRcvdStatus(arg1, arg2) (CComAbsMdlSafe_RxCan_SignalGetJustRcvdStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDLSAFE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDLSAFE_APPL_CODE) CComAbsMdlSafe_RxCan_SignalInvalidProcessingControl(tSafeRxSignalId SignalId, Boolean Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDLSAFE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_CanAdapterRx_RxCan_SignalInvalidProcessingControl(arg1, arg2) (CComAbsMdlSafe_RxCan_SignalInvalidProcessingControl(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDLSAFE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDLSAFE_APPL_CODE) CComAbsMdlSafe_RxCan_SignalMissingProcessingControl(tSafeRxSignalId SignalId, Boolean Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDLSAFE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_CanAdapterRx_RxCan_SignalMissingProcessingControl(arg1, arg2) (CComAbsMdlSafe_RxCan_SignalMissingProcessingControl(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CCOMABSMDLSAFE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CCOMABSMDLSAFE_APPL_CODE) CComAbsMdlSafe_RxCan_SignalNRProcessingControl(tSafeRxSignalId SignalId, Boolean Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDLSAFE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_CanAdapterRx_RxCan_SignalNRProcessingControl(arg1, arg2) (CComAbsMdlSafe_RxCan_SignalNRProcessingControl(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
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


# endif /* !defined(RTE_CORE) */


# define Mdl_Airbag_START_SEC_CODE
# include "Mdl_Airbag_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Mdl_Airbag_Init Mdl_Airbag_Init
#  define RTE_RUNNABLE_Mdl_Airbag_Task Mdl_Airbag_Task
# endif

FUNC(void, Mdl_Airbag_CODE) Mdl_Airbag_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Mdl_Airbag_CODE) Mdl_Airbag_Task(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define Mdl_Airbag_STOP_SEC_CODE
# include "Mdl_Airbag_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_if_CS_ComAbsRx_E_NOT_OK (1U)

#  define RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_MDL_AIRBAG_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
