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
 *          File:  Rte_CView_Telltale.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <CView_Telltale>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CVIEW_TELLTALE_H
# define _RTE_CVIEW_TELLTALE_H

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

# include "Rte_CView_Telltale_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_TurnHazard_pp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_TurnHazard_pp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(ClusterModes, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(HMIReadySts_Type, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_HMIReady_HMI_ReadyStatus; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(TTFlashMask, RTE_VAR_INIT) Rte_CCtrl_Telltale_ppBlinkStatusArray_TTdummyDataForTypes; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_Airbag_pp_Airbag_TT_Status_CurrentTelltaleStatus; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_rpBlinkStatusArray_TTdummyDataForTypes (0U)
#  define Rte_InitValue_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus (0U)
#  define Rte_InitValue_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus (0U)
#  define Rte_InitValue_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus (0U)
#  define Rte_InitValue_rp_ClusterMode_WSSCurrentClusterMode (0U)
#  define Rte_InitValue_rp_HMIReady_HMI_ReadyStatus (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CView_Telltale_rpBlinkStatusArray_TTBlinkStatusArray(P2VAR(Rte_DT_TTBlinkArray_0, AUTOMATIC, RTE_CVIEW_TELLTALE_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CView_Telltale_rpBlinkStatusArray_TTBlinkStatusArray(P2VAR(TTBlinkArray, AUTOMATIC, RTE_CVIEW_TELLTALE_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CView_Telltale_rpTelltaleStatusOP_TelltaleOpArray(P2VAR(Rte_DT_TT_OP_Type_0, AUTOMATIC, RTE_CVIEW_TELLTALE_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CView_Telltale_rpTelltaleStatusOP_TelltaleOpArray(P2VAR(TT_OP_Type, AUTOMATIC, RTE_CVIEW_TELLTALE_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CView_Telltale_ppTelltaleSts_TT_StatusData(P2CONST(STT_Status, AUTOMATIC, RTE_CVIEW_TELLTALE_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_rpBlinkStatusArray_TTBlinkStatusArray Rte_Read_CView_Telltale_rpBlinkStatusArray_TTBlinkStatusArray
#  define Rte_Read_rpBlinkStatusArray_TTdummyDataForTypes Rte_Read_CView_Telltale_rpBlinkStatusArray_TTdummyDataForTypes
#  define Rte_Read_CView_Telltale_rpBlinkStatusArray_TTdummyDataForTypes(data) (*(data) = Rte_CCtrl_Telltale_ppBlinkStatusArray_TTdummyDataForTypes, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpTelltaleStatusOP_TelltaleOpArray Rte_Read_CView_Telltale_rpTelltaleStatusOP_TelltaleOpArray
#  define Rte_Read_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus Rte_Read_CView_Telltale_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus
#  define Rte_Read_CView_Telltale_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus(data) (*(data) = Rte_Mdl_Airbag_pp_Airbag_TT_Status_CurrentTelltaleStatus, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus Rte_Read_CView_Telltale_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus
#  define Rte_Read_CView_Telltale_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus(data) (*(data) = Rte_Mdl_TurnHazard_pp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus Rte_Read_CView_Telltale_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus
#  define Rte_Read_CView_Telltale_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus(data) (*(data) = Rte_Mdl_TurnHazard_pp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_ClusterMode_WSSCurrentClusterMode Rte_Read_CView_Telltale_rp_ClusterMode_WSSCurrentClusterMode
#  define Rte_Read_CView_Telltale_rp_ClusterMode_WSSCurrentClusterMode(data) (*(data) = Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_HMIReady_HMI_ReadyStatus Rte_Read_CView_Telltale_rp_HMIReady_HMI_ReadyStatus
#  define Rte_Read_CView_Telltale_rp_HMIReady_HMI_ReadyStatus(data) (*(data) = Rte_Ctrl_WSS_pp_HMIReady_HMI_ReadyStatus, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_ppTelltaleSts_TT_StatusData Rte_Write_CView_Telltale_ppTelltaleSts_TT_StatusData


# endif /* !defined(RTE_CORE) */


# define CView_Telltale_START_SEC_CODE
# include "CView_Telltale_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CView_Telltale_Impl_MainFunction CView_Telltale_Impl_MainFunction
#  define RTE_RUNNABLE_CView_Telltale_Impl_OnCommand CView_Telltale_Impl_OnCommand
#  define RTE_RUNNABLE_CView_Telltale_Init CView_Telltale_Init
# endif

FUNC(void, CView_Telltale_CODE) CView_Telltale_Impl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, CView_Telltale_CODE) CView_Telltale_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CView_Telltale_CODE) CView_Telltale_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CView_Telltale_STOP_SEC_CODE
# include "CView_Telltale_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_if_CS_ModeOnCommand_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CVIEW_TELLTALE_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
