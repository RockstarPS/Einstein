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
 *          File:  Rte_CBattMdl.h
 *        Config:  BMW.dpa
 *   ECU-Project:  EcuInstance
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <CBattMdl>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CBATTMDL_H
# define _RTE_CBATTMDL_H

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

# include "Rte_CBattMdl_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_ppSR_BattMdl_AVP_HVP0Flag (FALSE)
#  define Rte_InitValue_ppSR_BattMdl_AVP_HVSD0Flag (FALSE)
#  define Rte_InitValue_ppSR_BattMdl_AVP_HVSD1Flag (FALSE)
#  define Rte_InitValue_ppSR_BattMdl_AVP_HVSD2Flag (FALSE)
#  define Rte_InitValue_ppSR_BattMdl_AVP_HVSD3Flag (FALSE)
#  define Rte_InitValue_ppSR_BattMdl_AVP_HVSD4Flag (FALSE)
#  define Rte_InitValue_ppSR_BattMdl_AVP_LVP0Flag (FALSE)
#  define Rte_InitValue_ppSR_BattMdl_AVP_LVP1Flag (FALSE)
#  define Rte_InitValue_ppSR_BattMdl_AVP_LVSD0Flag (FALSE)
#  define Rte_InitValue_ppSR_BattMdl_AVP_LVSD1Flag (FALSE)
#  define Rte_InitValue_ppSR_BattMdl_AVP_LVSD2Flag (FALSE)
#  define Rte_InitValue_ppSR_BattMdl_AVP_LVSD3Flag (FALSE)
#  define Rte_InitValue_ppSR_BattMdl_AVP_LVSD4Flag (FALSE)
#  define Rte_InitValue_ppSR_BattMdl_AVP_SVPFlag (FALSE)
#  define Rte_InitValue_ppSR_BattMdl_Voltage_OverVoltageInterruptFlag (FALSE)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_ppSR_BattMdl_AVP_HVP0Flag Rte_Write_CBattMdl_ppSR_BattMdl_AVP_HVP0Flag
#  define Rte_Write_CBattMdl_ppSR_BattMdl_AVP_HVP0Flag(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_BattMdl_AVP_HVSD0Flag Rte_Write_CBattMdl_ppSR_BattMdl_AVP_HVSD0Flag
#  define Rte_Write_CBattMdl_ppSR_BattMdl_AVP_HVSD0Flag(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_BattMdl_AVP_HVSD1Flag Rte_Write_CBattMdl_ppSR_BattMdl_AVP_HVSD1Flag
#  define Rte_Write_CBattMdl_ppSR_BattMdl_AVP_HVSD1Flag(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_BattMdl_AVP_HVSD2Flag Rte_Write_CBattMdl_ppSR_BattMdl_AVP_HVSD2Flag
#  define Rte_Write_CBattMdl_ppSR_BattMdl_AVP_HVSD2Flag(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_BattMdl_AVP_HVSD3Flag Rte_Write_CBattMdl_ppSR_BattMdl_AVP_HVSD3Flag
#  define Rte_Write_CBattMdl_ppSR_BattMdl_AVP_HVSD3Flag(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_BattMdl_AVP_HVSD4Flag Rte_Write_CBattMdl_ppSR_BattMdl_AVP_HVSD4Flag
#  define Rte_Write_CBattMdl_ppSR_BattMdl_AVP_HVSD4Flag(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_BattMdl_AVP_LVP0Flag Rte_Write_CBattMdl_ppSR_BattMdl_AVP_LVP0Flag
#  define Rte_Write_CBattMdl_ppSR_BattMdl_AVP_LVP0Flag(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_BattMdl_AVP_LVP1Flag Rte_Write_CBattMdl_ppSR_BattMdl_AVP_LVP1Flag
#  define Rte_Write_CBattMdl_ppSR_BattMdl_AVP_LVP1Flag(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_BattMdl_AVP_LVSD0Flag Rte_Write_CBattMdl_ppSR_BattMdl_AVP_LVSD0Flag
#  define Rte_Write_CBattMdl_ppSR_BattMdl_AVP_LVSD0Flag(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_BattMdl_AVP_LVSD1Flag Rte_Write_CBattMdl_ppSR_BattMdl_AVP_LVSD1Flag
#  define Rte_Write_CBattMdl_ppSR_BattMdl_AVP_LVSD1Flag(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_BattMdl_AVP_LVSD2Flag Rte_Write_CBattMdl_ppSR_BattMdl_AVP_LVSD2Flag
#  define Rte_Write_CBattMdl_ppSR_BattMdl_AVP_LVSD2Flag(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_BattMdl_AVP_LVSD3Flag Rte_Write_CBattMdl_ppSR_BattMdl_AVP_LVSD3Flag
#  define Rte_Write_CBattMdl_ppSR_BattMdl_AVP_LVSD3Flag(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_BattMdl_AVP_LVSD4Flag Rte_Write_CBattMdl_ppSR_BattMdl_AVP_LVSD4Flag
#  define Rte_Write_CBattMdl_ppSR_BattMdl_AVP_LVSD4Flag(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_BattMdl_AVP_SVPFlag Rte_Write_CBattMdl_ppSR_BattMdl_AVP_SVPFlag
#  define Rte_Write_CBattMdl_ppSR_BattMdl_AVP_SVPFlag(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSR_BattMdl_Voltage_OverVoltageInterruptFlag Rte_Write_CBattMdl_ppSR_BattMdl_Voltage_OverVoltageInterruptFlag
#  define Rte_Write_CBattMdl_ppSR_BattMdl_Voltage_OverVoltageInterruptFlag(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetAsyncRawAdc(IoHwAb_AdcSignalIdType AdcId, P2VAR(UInt16, AUTOMATIC, RTE_IOHWAB_APPL_VAR) AsyncRawAdc, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpIoHwAb_ADC_GetAsyncRawAdc IoHwAb_GetAsyncRawAdc
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetProcessedAdc(IoHwAb_AdcSignalIdType AdcId, P2VAR(SInt32, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ProcessedAdc, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpIoHwAb_ADC_GetProcessedAdc IoHwAb_GetProcessedAdc
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetSyncRawAdc(IoHwAb_AdcSignalIdType AdcId, P2VAR(UInt16, AUTOMATIC, RTE_IOHWAB_APPL_VAR) SyncRawAdc, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpIoHwAb_ADC_GetSyncRawAdc IoHwAb_GetSyncRawAdc
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetOutputGroup(IoHwAb_DOutGroupIdType InputId, UInt32 OutputGroup, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpIoHwAb_DOut_SetOutputGroup IoHwAb_SetOutputGroup
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetOutputPin(IoHwAb_DOutSignalIdType InputId, Boolean OutputSignal, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpIoHwAb_DOut_SetOutputPin IoHwAb_SetOutputPin
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, P2VAR(Boolean, AUTOMATIC, RTE_IOHWAB_APPL_VAR) AsyncInput, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpIoHwAb_Din_GetAsyncRawInput IoHwAb_GetAsyncRawInput
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetInputGroup(IoHwAb_DInGroupIdType InputId, P2VAR(UInt32, AUTOMATIC, RTE_IOHWAB_APPL_VAR) SyncInput, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpIoHwAb_Din_GetInputGroup IoHwAb_GetInputGroup
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetProcessedInput(IoHwAb_DInSignalIdType InputId, P2VAR(Boolean, AUTOMATIC, RTE_IOHWAB_APPL_VAR) InputSignal, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpIoHwAb_Din_GetProcessedInput IoHwAb_GetProcessedInput
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, P2VAR(Boolean, AUTOMATIC, RTE_IOHWAB_APPL_VAR) SyncInput, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpIoHwAb_Din_GetSyncRawInput IoHwAb_GetSyncRawInput


# endif /* !defined(RTE_CORE) */


# define CBattMdl_START_SEC_CODE
# include "CBattMdl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CBattMdl_Impl_MainFunction CBattMdl_Impl_MainFunction
#  define RTE_RUNNABLE_CBattMdl_Impl_OnCommand CBattMdl_Impl_OnCommand
# endif

FUNC(void, CBattMdl_CODE) CBattMdl_Impl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, CBattMdl_CODE) CBattMdl_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CBattMdl_STOP_SEC_CODE
# include "CBattMdl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK (1U)

#  define RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK (1U)

#  define RTE_E_TI_IOHWAB_SetDout_E_NOT_OK (1U)

#  define RTE_E_if_CS_ModeOnCommand_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CBATTMDL_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
