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
 *          File:  Rte_EcuM.h
 *        Config:  BMW.dpa"
 *   ECU-Project:  EcuInstance
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <EcuM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_ECUM_H
# define _RTE_ECUM_H

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

# include "Rte_EcuM_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_EcuM_currentMode_currentMode(EcuM_StateType nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_SwitchAck_EcuM_currentMode_currentMode(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_currentMode_currentMode Rte_Switch_EcuM_currentMode_currentMode


/**********************************************************************************************************************
 * Rte_Feedback_<p>_<m> (mode switch acknowledge)
 *********************************************************************************************************************/
#  define Rte_SwitchAck_currentMode_currentMode Rte_SwitchAck_EcuM_currentMode_currentMode


# endif /* !defined(RTE_CORE) */


# define EcuM_START_SEC_CODE
# include "EcuM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_EcuM_MainFunction EcuM_MainFunction
#  define RTE_RUNNABLE_GetBootTarget EcuM_GetBootTarget
#  define RTE_RUNNABLE_GetLastShutdownTarget EcuM_GetLastShutdownTarget
#  define RTE_RUNNABLE_GetShutdownCause EcuM_GetShutdownCause
#  define RTE_RUNNABLE_GetShutdownTarget EcuM_GetShutdownTarget
#  define RTE_RUNNABLE_GetStateWrapper EcuM_GetStateWrapper
#  define RTE_RUNNABLE_ReleasePOSTRUN EcuM_ReleasePOST_RUN
#  define RTE_RUNNABLE_ReleaseRUN EcuM_ReleaseRUN
#  define RTE_RUNNABLE_RequestPOSTRUN EcuM_RequestPOST_RUN
#  define RTE_RUNNABLE_RequestRUN EcuM_RequestRUN
#  define RTE_RUNNABLE_SelectBootTarget EcuM_SelectBootTarget
#  define RTE_RUNNABLE_SelectShutdownCause EcuM_SelectShutdownCause
#  define RTE_RUNNABLE_SelectShutdownTarget EcuM_SelectShutdownTarget
# endif

FUNC(void, EcuM_CODE) EcuM_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, EcuM_CODE) EcuM_GetBootTarget(P2VAR(EcuM_BootTargetType, AUTOMATIC, RTE_ECUM_APPL_VAR) BootTarget); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, EcuM_CODE) EcuM_GetLastShutdownTarget(P2VAR(EcuM_StateType, AUTOMATIC, RTE_ECUM_APPL_VAR) target, P2VAR(EcuM_ModeType, AUTOMATIC, RTE_ECUM_APPL_VAR) resetSleepMode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, EcuM_CODE) EcuM_GetShutdownCause(P2VAR(EcuM_ShutdownCauseType, AUTOMATIC, RTE_ECUM_APPL_VAR) shutdownCause); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, EcuM_CODE) EcuM_GetShutdownTarget(P2VAR(EcuM_StateType, AUTOMATIC, RTE_ECUM_APPL_VAR) target, P2VAR(EcuM_ModeType, AUTOMATIC, RTE_ECUM_APPL_VAR) resetSleepMode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, EcuM_CODE) EcuM_GetStateWrapper(EcuM_UserType parg0, P2VAR(EcuM_StateType, AUTOMATIC, RTE_ECUM_APPL_VAR) state); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, EcuM_CODE) EcuM_ReleasePOST_RUN(EcuM_UserType parg0); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, EcuM_CODE) EcuM_ReleaseRUN(EcuM_UserType parg0); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, EcuM_CODE) EcuM_RequestPOST_RUN(EcuM_UserType parg0); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, EcuM_CODE) EcuM_RequestRUN(EcuM_UserType parg0); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, EcuM_CODE) EcuM_SelectBootTarget(EcuM_BootTargetType BootTarget); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, EcuM_CODE) EcuM_SelectShutdownCause(EcuM_ShutdownCauseType shutdownCause); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, EcuM_CODE) EcuM_SelectShutdownTarget(EcuM_StateType targetState, EcuM_ModeType resetSleepMode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define EcuM_STOP_SEC_CODE
# include "EcuM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_EcuM_BootTarget_E_NOT_OK (1U)

#  define RTE_E_EcuM_ShutdownTarget_E_NOT_OK (1U)

#  define RTE_E_EcuM_StateRequest_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_ECUM_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_1330:  MISRA rule: 16.4
     Reason:     The RTE Generator uses default names for parameter identifiers of port defined arguments of service modules.
                 Therefore the parameter identifiers in the function declaration differs from those of the implementation of the BSW module.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
