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
 *          File:  Rte_CCtrl_Telltale.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <CCtrl_Telltale>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CCTRL_TELLTALE_H
# define _RTE_CCTRL_TELLTALE_H

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

# include "Rte_CCtrl_Telltale_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(HMIReadySts_Type, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_HMIReady_HMI_ReadyStatus; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(IgntionSubstateType, RTE_VAR_INIT) Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_TurnHazard_pp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_TurnHazard_pp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(ClusterModes, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode; /* PRQA S 0850 */ /* MD_MSR_19.8 */

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

#  define Rte_InitValue_ppBlinkStatusArray_TTdummyDataForTypes (0U)
#  define Rte_InitValue_rpETMBulbTest_CurrentBulbTestStatus (0U)
#  define Rte_InitValue_rpHmiReadyState_HMI_ReadyStatus (0U)
#  define Rte_InitValue_rpIgnBlankOutCheck_IgnBlankOutCheck (0U)
#  define Rte_InitValue_rpIgnSubstate_IgnitionSubstate (0U)
#  define Rte_InitValue_rpTelltaleIndexStatus_TTIndex (0U)
#  define Rte_InitValue_rpTelltaleIndexStatus_TTStatus (0U)
#  define Rte_InitValue_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus (0U)
#  define Rte_InitValue_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus (0U)
#  define Rte_InitValue_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus (0U)
#  define Rte_InitValue_rp_ClusterMode_WSSCurrentClusterMode (0U)
#  define Rte_InitValue_rp_EtmSts_CurrentBulbTestStatus (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CCtrl_Telltale_ppBlinkStatusArray_TTBlinkStatusArray(P2CONST(Rte_DT_TTBlinkArray_0, AUTOMATIC, RTE_CCTRL_TELLTALE_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CCtrl_Telltale_ppBlinkStatusArray_TTBlinkStatusArray(P2CONST(TTBlinkArray, AUTOMATIC, RTE_CCTRL_TELLTALE_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CCtrl_Telltale_ppTelltaleStatusOP_TelltaleOpArray(P2CONST(Rte_DT_TT_OP_Type_0, AUTOMATIC, RTE_CCTRL_TELLTALE_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CCtrl_Telltale_ppTelltaleStatusOP_TelltaleOpArray(P2CONST(TT_OP_Type, AUTOMATIC, RTE_CCTRL_TELLTALE_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_rpETMBulbTest_CurrentBulbTestStatus Rte_Read_CCtrl_Telltale_rpETMBulbTest_CurrentBulbTestStatus
#  define Rte_Read_CCtrl_Telltale_rpETMBulbTest_CurrentBulbTestStatus(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpHmiReadyState_HMI_ReadyStatus Rte_Read_CCtrl_Telltale_rpHmiReadyState_HMI_ReadyStatus
#  define Rte_Read_CCtrl_Telltale_rpHmiReadyState_HMI_ReadyStatus(data) (*(data) = Rte_Ctrl_WSS_pp_HMIReady_HMI_ReadyStatus, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpIgnBlankOutCheck_IgnBlankOutCheck Rte_Read_CCtrl_Telltale_rpIgnBlankOutCheck_IgnBlankOutCheck
#  define Rte_Read_CCtrl_Telltale_rpIgnBlankOutCheck_IgnBlankOutCheck(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpIgnSubstate_IgnitionSubstate Rte_Read_CCtrl_Telltale_rpIgnSubstate_IgnitionSubstate
#  define Rte_Read_CCtrl_Telltale_rpIgnSubstate_IgnitionSubstate(data) (*(data) = Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpTelltaleIndexStatus_TTIndex Rte_Read_CCtrl_Telltale_rpTelltaleIndexStatus_TTIndex
#  define Rte_Read_CCtrl_Telltale_rpTelltaleIndexStatus_TTIndex(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpTelltaleIndexStatus_TTStatus Rte_Read_CCtrl_Telltale_rpTelltaleIndexStatus_TTStatus
#  define Rte_Read_CCtrl_Telltale_rpTelltaleIndexStatus_TTStatus(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus Rte_Read_CCtrl_Telltale_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus
#  define Rte_Read_CCtrl_Telltale_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus(data) (*(data) = Rte_Mdl_Airbag_pp_Airbag_TT_Status_CurrentTelltaleStatus, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus Rte_Read_CCtrl_Telltale_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus
#  define Rte_Read_CCtrl_Telltale_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus(data) (*(data) = Rte_Mdl_TurnHazard_pp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus Rte_Read_CCtrl_Telltale_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus
#  define Rte_Read_CCtrl_Telltale_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus(data) (*(data) = Rte_Mdl_TurnHazard_pp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_ClusterMode_WSSCurrentClusterMode Rte_Read_CCtrl_Telltale_rp_ClusterMode_WSSCurrentClusterMode
#  define Rte_Read_CCtrl_Telltale_rp_ClusterMode_WSSCurrentClusterMode(data) (*(data) = Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_EtmSts_CurrentBulbTestStatus Rte_Read_CCtrl_Telltale_rp_EtmSts_CurrentBulbTestStatus
#  define Rte_Read_CCtrl_Telltale_rp_EtmSts_CurrentBulbTestStatus(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_ppBlinkStatusArray_TTBlinkStatusArray Rte_Write_CCtrl_Telltale_ppBlinkStatusArray_TTBlinkStatusArray
#  define Rte_Write_ppBlinkStatusArray_TTdummyDataForTypes Rte_Write_CCtrl_Telltale_ppBlinkStatusArray_TTdummyDataForTypes
#  define Rte_Write_CCtrl_Telltale_ppBlinkStatusArray_TTdummyDataForTypes(data) (Rte_CCtrl_Telltale_ppBlinkStatusArray_TTdummyDataForTypes = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppGetTelltaleStatus_TelltaleFunctionalOpStatus Rte_Write_CCtrl_Telltale_ppGetTelltaleStatus_TelltaleFunctionalOpStatus
#  define Rte_Write_CCtrl_Telltale_ppGetTelltaleStatus_TelltaleFunctionalOpStatus(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppTelltaleStatusOP_TelltaleOpArray Rte_Write_CCtrl_Telltale_ppTelltaleStatusOP_TelltaleOpArray


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CCDD_ECUBATTERYM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCDD_ECUBATTERYM_APPL_CODE) EcuBatteryM_GetChannelStatus(UInt8 Channel, P2VAR(UInt8, AUTOMATIC, RTE_CCDD_ECUBATTERYM_APPL_VAR) Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCDD_ECUBATTERYM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetChannelStatus EcuBatteryM_GetChannelStatus
#  define RTE_START_SEC_CCDD_ECUBATTERYM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCDD_ECUBATTERYM_APPL_CODE) EcuBatteryM_GetDIOStatus(UInt8 InputId, P2VAR(UInt8, AUTOMATIC, RTE_CCDD_ECUBATTERYM_APPL_VAR) Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCDD_ECUBATTERYM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetDIOStatus EcuBatteryM_GetDIOStatus


# endif /* !defined(RTE_CORE) */


# define CCtrl_Telltale_START_SEC_CODE
# include "CCtrl_Telltale_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CCtrl_Telltale_Adapter_Task CCtrl_Telltale_Adapter_Task
#  define RTE_RUNNABLE_CCtrl_Telltale_Impl_MainFunction CCtrl_Telltale_Impl_MainFunction
#  define RTE_RUNNABLE_CCtrl_Telltale_Impl_OnCommand CCtrl_Telltale_Impl_OnCommand
#  define RTE_RUNNABLE_CCtrl_Telltale_Init CCtrl_Telltale_Init
# endif

FUNC(void, CCtrl_Telltale_CODE) CCtrl_Telltale_Adapter_Task(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CCtrl_Telltale_CODE) CCtrl_Telltale_Impl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, CCtrl_Telltale_CODE) CCtrl_Telltale_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CCtrl_Telltale_CODE) CCtrl_Telltale_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CCtrl_Telltale_STOP_SEC_CODE
# include "CCtrl_Telltale_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_TI_EcuBatteryMData_E_NOT_OK (1U)

#  define RTE_E_if_CS_ModeOnCommand_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CCTRL_TELLTALE_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
