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
 *          File:  Rte_EcuMExt.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <EcuMExt>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_ECUMEXT_H
# define _RTE_ECUMEXT_H

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

# include "Rte_EcuMExt_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_ECUAPPM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_ECUAPPM_APPL_CODE) EcuAppM_SetWakeupSources(UInt32 WakeupSource); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_ECUAPPM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_EcuAppM_EcuAppM_SetWakeupSources(arg1) (EcuAppM_SetWakeupSources(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_ECUAPPM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_ECUAPPM_APPL_CODE) EcuAppM_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_ECUAPPM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_EcuAppM_Init() (EcuAppM_Init(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define EcuMExt_START_SEC_CODE
# include "EcuMExt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_EcuMExt_GetResetReason EcuMExt_GetResetReason
#  define RTE_RUNNABLE_EcuMExt_MainFunction EcuMExt_MainFunction
#  define RTE_RUNNABLE_EcuMExt_ReleaseRUN EcuMExt_ReleaseRUN
#  define RTE_RUNNABLE_EcuMExt_RequestRUN EcuMExt_RequestRUN
# endif

FUNC(Std_ReturnType, EcuMExt_CODE) EcuMExt_GetResetReason(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, EcuMExt_CODE) EcuMExt_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, EcuMExt_CODE) EcuMExt_ReleaseRUN(EcuM_UserType user); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, EcuMExt_CODE) EcuMExt_RequestRUN(EcuM_UserType user); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define EcuMExt_STOP_SEC_CODE
# include "EcuMExt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_TI_EcuMExt_GetResetReason_E_NOT_OK (1U)

#  define RTE_E_TI_EcuMExt_ReleaseRUN_E_NOT_OK (1U)

#  define RTE_E_TI_EcuMExt_RequestRUN_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_ECUMEXT_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
