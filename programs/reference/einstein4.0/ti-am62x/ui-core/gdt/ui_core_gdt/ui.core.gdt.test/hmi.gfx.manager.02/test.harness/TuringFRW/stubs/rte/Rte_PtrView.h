/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2015 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_PtrView.h
 *        Config:  Turing.dpa
 *   ECU-Project:  TuringECU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400814 for Visteon Corporation
 *
 *   Description:  Application header file for SW-C <PtrView>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_PTRVIEW_H
# define _RTE_PTRVIEW_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  define RTE_PTR2ARRAYBASETYPE_PASSING
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_PtrView_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(UInt8, RTE_VAR_INIT) Rte_EctMdl_EXT_CoolantTempCValue_EXT_CoolantTempCValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UFIX16_SP001, RTE_VAR_INIT) Rte_FuelMdl_FuelLevelCanS_de_FuelLevelOut; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_EngMdl_tiSR_TIEngMdl_Out_TachoF_Tacho; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_SpdMdl_tiSR_TISpdMdl_Out_SpdF_Speed; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_EXT_CoolantTempCValue_EXT_CoolantTempCValue (0U)
#  define Rte_InitValue_FuelLevelCanS_de_FuelLevelOut (0U)
#  define Rte_InitValue_FuelLevelCanS_de_Tau (0U)
#  define Rte_InitValue_tiSR_TIEngMdl_Out_TachoF_Tacho (0U)
#  define Rte_InitValue_tiSR_TISpdMdl_Out_SpdF_IsOverSpeed (FALSE)
#  define Rte_InitValue_tiSR_TISpdMdl_Out_SpdF_Speed (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PtrView_NV_Ect_Gauge_Mapping_Table_X_Value(P2VAR(Rte_DT_Gauge_Mapping_Table_X_0, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PtrView_NV_Ect_Gauge_Mapping_Table_X_Value(P2VAR(Gauge_Mapping_Table_X, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PtrView_NV_Ect_Gauge_Mapping_Table_Y_Value(P2VAR(Rte_DT_Gauge_Mapping_Table_Y_0, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PtrView_NV_Ect_Gauge_Mapping_Table_Y_Value(P2VAR(Gauge_Mapping_Table_Y, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PtrView_NV_Fuel_Gauge_Mapping_Table_X_Value(P2VAR(Rte_DT_Gauge_Mapping_Table_X_0, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PtrView_NV_Fuel_Gauge_Mapping_Table_X_Value(P2VAR(Gauge_Mapping_Table_X, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PtrView_NV_Fuel_Gauge_Mapping_Table_Y_Value(P2VAR(Rte_DT_Gauge_Mapping_Table_Y_0, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PtrView_NV_Fuel_Gauge_Mapping_Table_Y_Value(P2VAR(Gauge_Mapping_Table_Y, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PtrView_NV_RPM_Gauge_Mapping_Table_X_Value(P2VAR(Rte_DT_Gauge_Mapping_Table_X_0, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PtrView_NV_RPM_Gauge_Mapping_Table_X_Value(P2VAR(Gauge_Mapping_Table_X, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PtrView_NV_RPM_Gauge_Mapping_Table_Y_Value(P2VAR(Rte_DT_Gauge_Mapping_Table_Y_0, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PtrView_NV_RPM_Gauge_Mapping_Table_Y_Value(P2VAR(Gauge_Mapping_Table_Y, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PtrView_NV_Spd_Gauge_Mapping_Table_X_Value(P2VAR(Rte_DT_Gauge_Mapping_Table_X_0, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PtrView_NV_Spd_Gauge_Mapping_Table_X_Value(P2VAR(Gauge_Mapping_Table_X, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PtrView_NV_Spd_Gauge_Mapping_Table_Y_Value(P2VAR(Rte_DT_Gauge_Mapping_Table_Y_0, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PtrView_NV_Spd_Gauge_Mapping_Table_Y_Value(P2VAR(Gauge_Mapping_Table_Y, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_EXT_CoolantTempCValue_EXT_CoolantTempCValue Rte_Read_PtrView_EXT_CoolantTempCValue_EXT_CoolantTempCValue
#  define Rte_Read_PtrView_EXT_CoolantTempCValue_EXT_CoolantTempCValue(data) (*(data) = Rte_EctMdl_EXT_CoolantTempCValue_EXT_CoolantTempCValue, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_FuelLevelCanS_de_FuelLevelOut Rte_Read_PtrView_FuelLevelCanS_de_FuelLevelOut
#  define Rte_Read_PtrView_FuelLevelCanS_de_FuelLevelOut(data) (*(data) = Rte_FuelMdl_FuelLevelCanS_de_FuelLevelOut, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_NV_Ect_Gauge_Mapping_Table_X_Value Rte_Read_PtrView_NV_Ect_Gauge_Mapping_Table_X_Value
#  define Rte_Read_NV_Ect_Gauge_Mapping_Table_Y_Value Rte_Read_PtrView_NV_Ect_Gauge_Mapping_Table_Y_Value
#  define Rte_Read_NV_Fuel_Gauge_Mapping_Table_X_Value Rte_Read_PtrView_NV_Fuel_Gauge_Mapping_Table_X_Value
#  define Rte_Read_NV_Fuel_Gauge_Mapping_Table_Y_Value Rte_Read_PtrView_NV_Fuel_Gauge_Mapping_Table_Y_Value
#  define Rte_Read_NV_RPM_Gauge_Mapping_Table_X_Value Rte_Read_PtrView_NV_RPM_Gauge_Mapping_Table_X_Value
#  define Rte_Read_NV_RPM_Gauge_Mapping_Table_Y_Value Rte_Read_PtrView_NV_RPM_Gauge_Mapping_Table_Y_Value
#  define Rte_Read_NV_Spd_Gauge_Mapping_Table_X_Value Rte_Read_PtrView_NV_Spd_Gauge_Mapping_Table_X_Value
#  define Rte_Read_NV_Spd_Gauge_Mapping_Table_Y_Value Rte_Read_PtrView_NV_Spd_Gauge_Mapping_Table_Y_Value
#  define Rte_Read_tiSR_TIEngMdl_Out_TachoF_Tacho Rte_Read_PtrView_tiSR_TIEngMdl_Out_TachoF_Tacho
#  define Rte_Read_PtrView_tiSR_TIEngMdl_Out_TachoF_Tacho(data) (*(data) = Rte_EngMdl_tiSR_TIEngMdl_Out_TachoF_Tacho, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_tiSR_TISpdMdl_Out_SpdF_Speed Rte_Read_PtrView_tiSR_TISpdMdl_Out_SpdF_Speed
#  define Rte_Read_PtrView_tiSR_TISpdMdl_Out_SpdF_Speed(data) (*(data) = Rte_SpdMdl_tiSR_TISpdMdl_Out_SpdF_Speed, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_STPCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_STPCDD_APPL_CODE) CStpCdd_Impl_SetPosDeg(uint8 Id, uint16 Angle); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_STPCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_ppCS_pStpCdd_TIStpCdd_SetPosDeg CStpCdd_Impl_SetPosDeg
#  define RTE_START_SEC_STPCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_STPCDD_APPL_CODE) CStpCdd_Impl_WowGetMotSession(uint8 Id, P2VAR(uint8, AUTOMATIC, RTE_STPCDD_APPL_VAR) pWowSession); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_STPCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_ppCS_pStpCdd_TIStpCdd_WowGetMotSession CStpCdd_Impl_WowGetMotSession
#  define RTE_START_SEC_STPCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_STPCDD_APPL_CODE) CStpCdd_Impl_WowOpenSession(P2VAR(uint8, AUTOMATIC, RTE_STPCDD_APPL_VAR) pWowSession); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_STPCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_ppCS_pStpCdd_TIStpCdd_WowOpenSession CStpCdd_Impl_WowOpenSession
#  define RTE_START_SEC_STPCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_STPCDD_APPL_CODE) CStpCdd_Impl_WowRequest(uint8 WowSession, Boolean toStart); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_STPCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_ppCS_pStpCdd_TIStpCdd_WowRequest CStpCdd_Impl_WowRequest
#  define RTE_START_SEC_STPCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_STPCDD_APPL_CODE) CStpCdd_Impl_WowSessionSetMotor(uint8 WowSession, uint8 Id, uint16 TargetPos); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_STPCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_ppCS_pStpCdd_TIStpCdd_WowSessionSetMotor CStpCdd_Impl_WowSessionSetMotor
#  define RTE_START_SEC_STPCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_STPCDD_APPL_CODE) CStpCdd_Impl_WowSessionSetTime(uint8 WowSession, uint16 Time, uint8 TimeType); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_STPCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_ppCS_pStpCdd_TIStpCdd_WowSessionSetTime CStpCdd_Impl_WowSessionSetTime
#  define RTE_START_SEC_STPCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_STPCDD_APPL_CODE) CStpCdd_Impl_WowStop(uint8 WowSession); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_STPCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_ppCS_pStpCdd_TIStpCdd_WowStop CStpCdd_Impl_WowStop
#  define RTE_START_SEC_HMICTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_HMICTRL_APPL_CODE) CHmiCtrl_Ptr_Ready(EHmiSubId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_HMICTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_tiCS_TIHmiCtrl_SubReply_Ready(arg1) (CHmiCtrl_Ptr_Ready(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define PtrView_START_SEC_CODE
# include "PtrView_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CPtrEctView_Impl_MainFunction CPtrEctView_Impl_MainFunction
#  define RTE_RUNNABLE_CPtrEctView_Impl_OnCommand CPtrEctView_Impl_OnCommand
#  define RTE_RUNNABLE_CPtrFuelView_Impl_MainFunction CPtrFuelView_Impl_MainFunction
#  define RTE_RUNNABLE_CPtrFuelView_Impl_OnCommand CPtrFuelView_Impl_OnCommand
#  define RTE_RUNNABLE_CPtrSpdView_Impl_DiagAction CPtrSpdView_Impl_DiagAction
#  define RTE_RUNNABLE_CPtrSpdView_Impl_MainFunction CPtrSpdView_Impl_MainFunction
#  define RTE_RUNNABLE_CPtrSpdView_Impl_OnCommand CPtrSpdView_Impl_OnCommand
#  define RTE_RUNNABLE_CPtrTachoView_Impl_DiagAction CPtrTachoView_Impl_DiagAction
#  define RTE_RUNNABLE_CPtrTachoView_Impl_MainFunction CPtrTachoView_Impl_MainFunction
#  define RTE_RUNNABLE_CPtrTachoView_Impl_OnCommand CPtrTachoView_Impl_OnCommand
#  define RTE_RUNNABLE_PtrView_PrepareSub PtrView_PrepareSub
#  define RTE_RUNNABLE_PtrView_Start PtrView_Start
#  define RTE_RUNNABLE_PtrView_Stop PtrView_Stop
# endif

FUNC(void, PtrView_CODE) CPtrEctView_Impl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, PtrView_CODE) CPtrEctView_Impl_OnCommand(ECmpCmd Cmd); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, PtrView_CODE) CPtrFuelView_Impl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, PtrView_CODE) CPtrFuelView_Impl_OnCommand(ECmpCmd Cmd); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, PtrView_CODE) CPtrSpdView_Impl_DiagAction(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, PtrView_CODE) CPtrSpdView_Impl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, PtrView_CODE) CPtrSpdView_Impl_OnCommand(ECmpCmd Cmd); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, PtrView_CODE) CPtrTachoView_Impl_DiagAction(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, PtrView_CODE) CPtrTachoView_Impl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, PtrView_CODE) CPtrTachoView_Impl_OnCommand(ECmpCmd Cmd); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, PtrView_CODE) PtrView_PrepareSub(EHmiSubId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, PtrView_CODE) PtrView_Start(EHmiSubId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, PtrView_CODE) PtrView_Stop(EHmiSubId Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define PtrView_STOP_SEC_CODE
# include "PtrView_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_PtrEctView_SystemIf_E_NOT_OK (1U)

#  define RTE_E_PtrFuelView_SystemIf_E_NOT_OK (1U)

#  define RTE_E_PtrSpdView_SystemIf_E_NOT_OK (1U)

#  define RTE_E_PtrTachoView_SystemIf_E_NOT_OK (1U)

#  define RTE_E_TI_Diag_E_NOT_OK (1U)

#  define RTE_E_tiCS_TIHmiCtrl_SubCmd_E_NOT_OK (1U)

#  define RTE_E_tiCS_TIStpCdd_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_PTRVIEW_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
