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
 *          File:  Rte_CCDD_FitManager.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <CCDD_FitManager>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CCDD_FITMANAGER_H
# define _RTE_CCDD_FITMANAGER_H

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

# include "Rte_CCDD_FitManager_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_rpCS_FitHandler_rpCS_FitHandler_CCDD_BswFit_FaultInjectionHandler(arg1, arg2, arg3) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rpCS_FitHandler_rpCS_FitHandler_CCDD_McuFit_FaultInjectionHandler(arg1, arg2, arg3) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define CCDD_FitManager_START_SEC_CODE
# include "CCDD_FitManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CCDD_FitManager_Impl_MainFunction CCDD_FitManager_Impl_MainFunction
#  define RTE_RUNNABLE_CDD_FitManager_RouteFITDID CDD_FitManager_RouteFITDID
# endif

FUNC(void, CCDD_FitManager_CODE) CCDD_FitManager_Impl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, CCDD_FitManager_CODE) CDD_FitManager_RouteFITDID(P2VAR(UInt8, AUTOMATIC, RTE_CCDD_FITMANAGER_APPL_VAR) Data, UInt8 OpStatus, P2VAR(UInt8, AUTOMATIC, RTE_CCDD_FITMANAGER_APPL_VAR) pNrc); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CCDD_FitManager_STOP_SEC_CODE
# include "CCDD_FitManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_TI_FITDID_E_NOT_OK (1U)

#  define RTE_E_TI_FaultInjectionHandler_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CCDD_FITMANAGER_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
