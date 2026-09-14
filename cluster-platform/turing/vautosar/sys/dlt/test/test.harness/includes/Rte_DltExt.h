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
 *          File:  Rte_DltExt.h
 *        Config:  Traveo2.dpa
 *   ECU-Project:  CLU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <DltExt>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_DLTEXT_H
# define _RTE_DLTEXT_H

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

# include "Rte_DltExt_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL(P2VAR(Boolean, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL MemAbstractMdl_Get_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_DG_16_vehicle_type_U8(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_DG_16_vehicle_type_U8 MemAbstractMdl_Get_NVM_DG_16_vehicle_type_U8
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Diag_config_var_16_padding_U8A(P2VAR(Rte_DT_Nvm_U8ArrType_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Diag_config_var_16_padding_U8A(P2VAR(Nvm_U8ArrType_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_Diag_config_var_16_padding_U8A MemAbstractMdl_Get_NVM_Diag_config_var_16_padding_U8A
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Diag_config_var_5_padding_U8A(P2VAR(Rte_DT_Nvm_U8ArrType_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Diag_config_var_5_padding_U8A(P2VAR(Nvm_U8ArrType_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_Diag_config_var_5_padding_U8A MemAbstractMdl_Get_NVM_Diag_config_var_5_padding_U8A
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Dlt_Fetal_Storage(P2VAR(Rte_DT_Nvm_U8ArrType_20_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Dlt_Fetal_Storage(P2VAR(Nvm_U8ArrType_20, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_Dlt_Fetal_Storage MemAbstractMdl_Get_NVM_Dlt_Fetal_Storage
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Dlt_Main_Storage(P2VAR(Rte_DT_Nvm_U8ArrType_160_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Dlt_Main_Storage(P2VAR(Nvm_U8ArrType_160, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_Dlt_Main_Storage MemAbstractMdl_Get_NVM_Dlt_Main_Storage
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_EOL_Mfg_Mode_Entry(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_EOL_Mfg_Mode_Entry MemAbstractMdl_Get_NVM_EOL_Mfg_Mode_Entry
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL(Boolean NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL(arg1) (MemAbstractMdl_Set_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_DG_16_vehicle_type_U8(UInt8 NVM_DG_16_vehicle_type_U8); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_DG_16_vehicle_type_U8(arg1) (MemAbstractMdl_Set_NVM_DG_16_vehicle_type_U8(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Diag_config_var_16_padding_U8A(P2CONST(Rte_DT_Nvm_U8ArrType_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Diag_config_var_16_padding_U8A); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Diag_config_var_16_padding_U8A(P2CONST(Nvm_U8ArrType_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Diag_config_var_16_padding_U8A); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_Diag_config_var_16_padding_U8A(arg1) (MemAbstractMdl_Set_NVM_Diag_config_var_16_padding_U8A(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Diag_config_var_5_padding_U8A(P2CONST(Rte_DT_Nvm_U8ArrType_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Diag_config_var_5_padding_U8A); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Diag_config_var_5_padding_U8A(P2CONST(Nvm_U8ArrType_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Diag_config_var_5_padding_U8A); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_Diag_config_var_5_padding_U8A(arg1) (MemAbstractMdl_Set_NVM_Diag_config_var_5_padding_U8A(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Dlt_Fetal_Storage(P2CONST(Rte_DT_Nvm_U8ArrType_20_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Dlt_Fetal_Storage); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Dlt_Fetal_Storage(P2CONST(Nvm_U8ArrType_20, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Dlt_Fetal_Storage); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_Dlt_Fetal_Storage(arg1) (MemAbstractMdl_Set_NVM_Dlt_Fetal_Storage(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Dlt_Main_Storage(P2CONST(Rte_DT_Nvm_U8ArrType_160_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Dlt_Main_Storage); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Dlt_Main_Storage(P2CONST(Nvm_U8ArrType_160, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Dlt_Main_Storage); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_Dlt_Main_Storage(arg1) (MemAbstractMdl_Set_NVM_Dlt_Main_Storage(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_EOL_Mfg_Mode_Entry(UInt16 NVM_EOL_Mfg_Mode_Entry); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_EOL_Mfg_Mode_Entry(arg1) (MemAbstractMdl_Set_NVM_EOL_Mfg_Mode_Entry(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_NvmWriteStatus(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbs_NvMWriteStatus_NvmWriteStatus MemAbstractMdl_NvmWriteStatus


# endif /* !defined(RTE_CORE) */


# define DltExt_START_SEC_CODE
# include "DltExt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_DltExt_MainFunction DltExt_MainFunction
#  define RTE_RUNNABLE_DltExt_SendLogMessage DltExt_SendLogMessage
#  define RTE_RUNNABLE_DltExt_SetCounterToDefault DltExt_SetCounterToDefault
#  define RTE_RUNNABLE_DltExt_SetLogsToDefault DltExt_SetLogsToDefault
# endif

FUNC(void, DltExt_CODE) DltExt_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, DltExt_CODE) DltExt_SendLogMessage(P2VAR(UInt8, AUTOMATIC, RTE_DLTEXT_APPL_VAR) payLoadHeader, P2VAR(UInt8, AUTOMATIC, RTE_DLTEXT_APPL_VAR) payLoad, UInt16 payLoadHeaderLength, UInt16 payLoadLength, UInt8 logLevel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, DltExt_CODE) DltExt_SetCounterToDefault(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, DltExt_CODE) DltExt_SetLogsToDefault(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define DltExt_STOP_SEC_CODE
# include "DltExt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_If_CS_DltExt_SendLogMessage_E_NOT_OK (1U)

#  define RTE_E_if_CS_MemAbsGet_E_NOT_OK (1U)

#  define RTE_E_if_CS_MemAbs_NvMWriteStatus_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_DLTEXT_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
