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
 *          File:  Rte_ComMExt.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <ComMExt>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_COMMEXT_H
# define _RTE_COMMEXT_H

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

# include "Rte_ComMExt_Type.h"
# include "Rte_DataHandleType.h"


# define ComMExt_START_SEC_CODE
# include "ComMExt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_ComMExt_CAN_ActivateSilentCommunication ComMExt_CAN_ActivateSilentCommunication
#  define RTE_RUNNABLE_ComMExt_CAN_CommControlActivateRx ComMExt_CAN_CommControlActivateRx
#  define RTE_RUNNABLE_ComMExt_CAN_CommControlActivateTx ComMExt_CAN_CommControlActivateTx
#  define RTE_RUNNABLE_ComMExt_CAN_CommControlDeActivateRx ComMExt_CAN_CommControlDeActivateRx
#  define RTE_RUNNABLE_ComMExt_CAN_CommControlDeActivateTx ComMExt_CAN_CommControlDeActivateTx
#  define RTE_RUNNABLE_ComMExt_CAN_CommControlSetDone ComMExt_CAN_CommControlSetDone
#  define RTE_RUNNABLE_ComMExt_CAN_DeActivateSilentCommunication ComMExt_CAN_DeActivateSilentCommunication
#  define RTE_RUNNABLE_ComMExt_CAN_GetCurrentComMode ComMExt_CAN_GetCurrentComMode
#  define RTE_RUNNABLE_ComMExt_CAN_ReleaseCommunication ComMExt_CAN_ReleaseCommunication
#  define RTE_RUNNABLE_ComMExt_CAN_RequestCommunication ComMExt_CAN_RequestCommunication
#  define RTE_RUNNABLE_ComMExt_GetBusOffStatus ComMExt_GetBusOffStatus
#  define RTE_RUNNABLE_ComMExt_Get_MCAN_ERR_PIN_Status ComMExt_Get_MCAN_ERR_PIN_Status
#  define RTE_RUNNABLE_ComMExt_Impl_MainFunction ComMExt_Impl_MainFunction
#  define RTE_RUNNABLE_ComMExt_Init ComMExt_Init
# endif

FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_ActivateSilentCommunication(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_CommControlActivateRx(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_CommControlActivateTx(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_CommControlDeActivateRx(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_CommControlDeActivateTx(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, ComMExt_CODE) ComMExt_CAN_CommControlSetDone(Boolean PduInitRequest); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_DeActivateSilentCommunication(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_GetCurrentComMode(UInt8 Channel, P2VAR(UInt8, AUTOMATIC, RTE_COMMEXT_APPL_VAR) ComMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_ReleaseCommunication(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_RequestCommunication(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_GetBusOffStatus(UInt8 Channel, P2VAR(Boolean, AUTOMATIC, RTE_COMMEXT_APPL_VAR) BusOffStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_Get_MCAN_ERR_PIN_Status(P2VAR(Boolean, AUTOMATIC, RTE_COMMEXT_APPL_VAR) fl_pin_status_BOOL); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, ComMExt_CODE) ComMExt_Impl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, ComMExt_CODE) ComMExt_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define ComMExt_STOP_SEC_CODE
# include "ComMExt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_TI_ComMExt_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_COMMEXT_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
