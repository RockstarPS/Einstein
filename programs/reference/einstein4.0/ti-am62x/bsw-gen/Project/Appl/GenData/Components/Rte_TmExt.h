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
 *          File:  Rte_TmExt.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <TmExt>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_TMEXT_H
# define _RTE_TMEXT_H

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

# include "Rte_TmExt_Type.h"
# include "Rte_DataHandleType.h"


# define TmExt_START_SEC_CODE
# include "TmExt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_TmExt_MainFunction TmExt_MainFunction
#  define RTE_RUNNABLE_TmExt_Timer_GetElapsedTime TmExt_Timer_GetElapsedTime
#  define RTE_RUNNABLE_TmExt_Timer_IsElapsed TmExt_Timer_IsElapsed
#  define RTE_RUNNABLE_TmExt_Timer_IsStarted TmExt_Timer_IsStarted
#  define RTE_RUNNABLE_TmExt_Timer_Start TmExt_Timer_Start
#  define RTE_RUNNABLE_TmExt_Timer_Stop TmExt_Timer_Stop
# endif

FUNC(void, TmExt_CODE) TmExt_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, TmExt_CODE) TmExt_Timer_GetElapsedTime(HTimer hTimer, P2VAR(UInt32, AUTOMATIC, RTE_TMEXT_APPL_VAR) ElapsedTime); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, TmExt_CODE) TmExt_Timer_IsElapsed(HTimer hTimer, UInt32 Timeout, P2VAR(Boolean, AUTOMATIC, RTE_TMEXT_APPL_VAR) IsElapsed); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, TmExt_CODE) TmExt_Timer_IsStarted(HTimer hTimer, P2VAR(Boolean, AUTOMATIC, RTE_TMEXT_APPL_VAR) IsStarted); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, TmExt_CODE) TmExt_Timer_Start(HTimer hTimer); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, TmExt_CODE) TmExt_Timer_Stop(HTimer hTimer); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define TmExt_STOP_SEC_CODE
# include "TmExt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_TMEXT_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
