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
 *          File:  Rte_IoHwAb.h
 *        Config:  BMW.dpa"
 *   ECU-Project:  EcuInstance
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <IoHwAb>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_IOHWAB_H
# define _RTE_IOHWAB_H

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

# include "Rte_IoHwAb_Type.h"
# include "Rte_DataHandleType.h"


# define IoHwAb_START_SEC_CODE
# include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_IoHwAb_GetAsyncRawAdc IoHwAb_GetAsyncRawAdc
#  define RTE_RUNNABLE_IoHwAb_GetAsyncRawInput IoHwAb_GetAsyncRawInput
#  define RTE_RUNNABLE_IoHwAb_GetCurrentSignalStatus_PulseInput IoHwAb_GetCurrentSignalStatus_PulseInput
#  define RTE_RUNNABLE_IoHwAb_GetCurrentSpeed_PulseInput IoHwAb_GetCurrentSpeed_PulseInput
#  define RTE_RUNNABLE_IoHwAb_GetInputGroup IoHwAb_GetInputGroup
#  define RTE_RUNNABLE_IoHwAb_GetProcessedAdc IoHwAb_GetProcessedAdc
#  define RTE_RUNNABLE_IoHwAb_GetProcessedInput IoHwAb_GetProcessedInput
#  define RTE_RUNNABLE_IoHwAb_GetRollingCount_PulseInput IoHwAb_GetRollingCount_PulseInput
#  define RTE_RUNNABLE_IoHwAb_GetSyncRawAdc IoHwAb_GetSyncRawAdc
#  define RTE_RUNNABLE_IoHwAb_GetSyncRawInput IoHwAb_GetSyncRawInput
#  define RTE_RUNNABLE_IoHwAb_MainFunction IoHwAb_MainFunction
#  define RTE_RUNNABLE_IoHwAb_PwmSetDuty IoHwAb_PwmSetDuty
#  define RTE_RUNNABLE_IoHwAb_PwmSetDutyAndPeriod IoHwAb_PwmSetDutyAndPeriod
#  define RTE_RUNNABLE_IoHwAb_PwmSetIdeal IoHwAb_PwmSetIdeal
#  define RTE_RUNNABLE_IoHwAb_ResetRollingCount_PulseInput IoHwAb_ResetRollingCount_PulseInput
#  define RTE_RUNNABLE_IoHwAb_SetOutputGroup IoHwAb_SetOutputGroup
#  define RTE_RUNNABLE_IoHwAb_SetOutputPin IoHwAb_SetOutputPin
#  define RTE_RUNNABLE_IoHwAb_Start_Signal_Measurement_PulseInput IoHwAb_Start_Signal_Measurement_PulseInput
#  define RTE_RUNNABLE_IoHwAb_Stop_Signal_Measurement_PulseInput IoHwAb_Stop_Signal_Measurement_PulseInput
#  define RTE_RUNNABLE_IoHwAb_Update_CalibParam_PulseInput IoHwAb_Update_CalibParam_PulseInput
# endif

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_GetAsyncRawAdc(IoHwAb_AdcSignalIdType AdcId, P2VAR(UInt16, AUTOMATIC, RTE_IOHWAB_APPL_VAR) AsyncRawAdc, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, P2VAR(Boolean, AUTOMATIC, RTE_IOHWAB_APPL_VAR) AsyncInput, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_GetCurrentSignalStatus_PulseInput(eIOPulseInputId PulseInputId, P2VAR(UInt16, AUTOMATIC, RTE_IOHWAB_APPL_VAR) SignalStatus, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_GetCurrentSpeed_PulseInput(eIOPulseInputId PulseInputId, P2VAR(UInt32, AUTOMATIC, RTE_IOHWAB_APPL_VAR) SpeedVal, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_GetInputGroup(IoHwAb_DInGroupIdType InputId, P2VAR(UInt32, AUTOMATIC, RTE_IOHWAB_APPL_VAR) SyncInput, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_GetProcessedAdc(IoHwAb_AdcSignalIdType AdcId, P2VAR(SInt32, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ProcessedAdc, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_GetProcessedInput(IoHwAb_DInSignalIdType InputId, P2VAR(Boolean, AUTOMATIC, RTE_IOHWAB_APPL_VAR) InputSignal, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_GetRollingCount_PulseInput(eIOPulseInputId PulseInputId, P2VAR(UInt8, AUTOMATIC, RTE_IOHWAB_APPL_VAR) EdgeCount, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_GetSyncRawAdc(IoHwAb_AdcSignalIdType AdcId, P2VAR(UInt16, AUTOMATIC, RTE_IOHWAB_APPL_VAR) SyncRawAdc, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, P2VAR(Boolean, AUTOMATIC, RTE_IOHWAB_APPL_VAR) SyncInput, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, IoHwAb_CODE) IoHwAb_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_PwmSetDuty(IoHwAb_PwmSignalIdType PwmId, UInt16 Pwm_Duty, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_PwmSetDutyAndPeriod(IoHwAb_PwmSignalIdType PwmId, UInt32 Pwm_Period, UInt16 Pwm_Duty, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_PwmSetIdeal(IoHwAb_PwmSignalIdType PwmId, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_ResetRollingCount_PulseInput(eIOPulseInputId PulseInputId, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_SetOutputGroup(IoHwAb_DOutGroupIdType InputId, UInt32 OutputGroup, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_SetOutputPin(IoHwAb_DOutSignalIdType InputId, Boolean OutputSignal, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_Start_Signal_Measurement_PulseInput(eIOPulseInputId PulseInputId, P2VAR(SPulseInputConfigParam, AUTOMATIC, RTE_IOHWAB_APPL_VAR) PulseInputChnlCfgParam, P2VAR(SSpeedCalcParam, AUTOMATIC, RTE_IOHWAB_APPL_VAR) SpdCalParam, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_Stop_Signal_Measurement_PulseInput(eIOPulseInputId PulseInputId, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_Update_CalibParam_PulseInput(eIOPulseInputId PulseInputId, P2VAR(SSpeedCalcParam, AUTOMATIC, RTE_IOHWAB_APPL_VAR) SpdCalParam, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define IoHwAb_STOP_SEC_CODE
# include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK (1U)

#  define RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK (1U)

#  define RTE_E_TI_IOHWAB_PWM_E_NOT_OK (1U)

#  define RTE_E_TI_IOHWAB_Pulse_E_NOT_OK (1U)

#  define RTE_E_TI_IOHWAB_SetDout_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_IOHWAB_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
