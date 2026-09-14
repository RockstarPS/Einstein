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
 *          File:  Rte_CFltMExt.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <CFltMExt>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CFLTMEXT_H
# define _RTE_CFLTMEXT_H

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

# include "Rte_CFltMExt_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE

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
#  define RTE_START_SEC_CFLTM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CFLTM_APPL_CODE) FltM_ReportFault(eFltM_FaultIdType FaultId, eFltM_FaultStatusType FaultStatus, P2VAR(UInt8, AUTOMATIC, RTE_CFLTM_APPL_VAR) LogData, UInt16 LogLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CFLTM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_FltM_ReportFault_FltM_ReportFault FltM_ReportFault


# endif /* !defined(RTE_CORE) */


# define CFltMExt_START_SEC_CODE
# include "CFltMExt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CFltMExt_Impl_OnCommand CFltMExt_Impl_OnCommand
#  define RTE_RUNNABLE_CFltMExt_MainFunction CFltMExt_MainFunction
# endif

FUNC(Std_ReturnType, CFltMExt_CODE) CFltMExt_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CFltMExt_CODE) CFltMExt_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CFltMExt_STOP_SEC_CODE
# include "CFltMExt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_TI_EcuBatteryMData_E_NOT_OK (1U)

#  define RTE_E_TI_FltM_ReportFault_E_NOT_OK (1U)

#  define RTE_E_if_CS_ModeOnCommand_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CFLTMEXT_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
