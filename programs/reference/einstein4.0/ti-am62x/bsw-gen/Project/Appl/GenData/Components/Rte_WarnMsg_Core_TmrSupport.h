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
 *          File:  Rte_WarnMsg_Core_TmrSupport.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <WarnMsg_Core_TmrSupport>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_WARNMSG_CORE_TMRSUPPORT_H
# define _RTE_WARNMSG_CORE_TMRSUPPORT_H

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

# include "Rte_WarnMsg_Core_TmrSupport_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_TMEXT_APPL_CODE) TmExt_Timer_IsElapsed(HTimer hTimer, UInt32 Timeout, P2VAR(Boolean, AUTOMATIC, RTE_TMEXT_APPL_VAR) IsElapsed); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_TmExt_Timer_Elapsed_Timer_IsElapsed(arg1, arg2, arg3) (TmExt_Timer_IsElapsed(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_TMEXT_APPL_CODE) TmExt_Timer_Start(HTimer hTimer); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_TmExt_Timer_Start_Timer_Start(arg1) (TmExt_Timer_Start(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_TMEXT_APPL_CODE) TmExt_Timer_IsStarted(HTimer hTimer, P2VAR(Boolean, AUTOMATIC, RTE_TMEXT_APPL_VAR) IsStarted); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_TmExt_Timer_Started_Timer_IsStarted(arg1, arg2) (TmExt_Timer_IsStarted(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_TMEXT_APPL_CODE) TmExt_Timer_Stop(HTimer hTimer); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_TMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_TmExt_Timer_Stop_Timer_Stop(arg1) (TmExt_Timer_Stop(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define WarnMsg_Core_TmrSupport_START_SEC_CODE
# include "WarnMsg_Core_TmrSupport_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_WarnMsg_Core_TmrSupport_Init WarnMsg_Core_TmrSupport_Init
#  define RTE_RUNNABLE_WarnMsg_Core_TmrSupport_Task WarnMsg_Core_TmrSupport_Task
# endif

FUNC(void, WarnMsg_Core_TmrSupport_CODE) WarnMsg_Core_TmrSupport_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, WarnMsg_Core_TmrSupport_CODE) WarnMsg_Core_TmrSupport_Task(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define WarnMsg_Core_TmrSupport_STOP_SEC_CODE
# include "WarnMsg_Core_TmrSupport_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_WARNMSG_CORE_TMRSUPPORT_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
