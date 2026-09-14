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
 *          File:  TSC_CCDD_EcuPowerM.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Client server interfaces */
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_ADC_GetAsyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *AsyncRawAdc, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_ADC_GetProcessedAdc(IoHwAb_AdcSignalIdType AdcId, SInt32 *ProcessedAdc, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_ADC_GetSyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *SyncRawAdc, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_DOut_SetOutputGroup(IoHwAb_DOutGroupIdType InputId, UInt32 OutputGroup, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_DOut_SetOutputPin(IoHwAb_DOutSignalIdType InputId, Boolean OutputSignal, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_Din_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *AsyncInput, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_Din_GetInputGroup(IoHwAb_DInGroupIdType InputId, UInt32 *SyncInput, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_Din_GetProcessedInput(IoHwAb_DInSignalIdType InputId, Boolean *InputSignal, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_Din_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *SyncInput, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_PWM_PwmSetDuty(IoHwAb_PwmSignalIdType PwmId, UInt16 Pwm_Duty, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_PWM_PwmSetDutyAndPeriod(IoHwAb_PwmSignalIdType PwmId, UInt32 Pwm_Period, UInt16 Pwm_Duty, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_PWM_PwmSetIdeal(IoHwAb_PwmSignalIdType PwmId, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_ADC_GetAsyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *AsyncRawAdc, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_ADC_GetProcessedAdc(IoHwAb_AdcSignalIdType AdcId, SInt32 *ProcessedAdc, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_ADC_GetSyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *SyncRawAdc, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_DOut_SetOutputGroup(IoHwAb_DOutGroupIdType InputId, UInt32 OutputGroup, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_DOut_SetOutputPin(IoHwAb_DOutSignalIdType InputId, Boolean OutputSignal, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_Din_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *AsyncInput, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_Din_GetInputGroup(IoHwAb_DInGroupIdType InputId, UInt32 *SyncInput, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_Din_GetProcessedInput(IoHwAb_DInSignalIdType InputId, Boolean *InputSignal, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_Din_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *SyncInput, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_PWM_PwmSetDuty(IoHwAb_PwmSignalIdType PwmId, UInt16 Pwm_Duty, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_PWM_PwmSetDutyAndPeriod(IoHwAb_PwmSignalIdType PwmId, UInt32 Pwm_Period, UInt16 Pwm_Duty, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_PWM_PwmSetIdeal(IoHwAb_PwmSignalIdType PwmId, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_ADC_GetAsyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *AsyncRawAdc, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_ADC_GetProcessedAdc(IoHwAb_AdcSignalIdType AdcId, SInt32 *ProcessedAdc, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_ADC_GetSyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *SyncRawAdc, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_DOut_SetOutputGroup(IoHwAb_DOutGroupIdType InputId, UInt32 OutputGroup, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_DOut_SetOutputPin(IoHwAb_DOutSignalIdType InputId, Boolean OutputSignal, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_Din_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *AsyncInput, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_Din_GetInputGroup(IoHwAb_DInGroupIdType InputId, UInt32 *SyncInput, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_Din_GetProcessedInput(IoHwAb_DInSignalIdType InputId, Boolean *InputSignal, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_Din_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *SyncInput, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_PWM_PwmSetDuty(IoHwAb_PwmSignalIdType PwmId, UInt16 Pwm_Duty, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_PWM_PwmSetDutyAndPeriod(IoHwAb_PwmSignalIdType PwmId, UInt32 Pwm_Period, UInt16 Pwm_Duty, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CCDD_EcuPowerM_Rte_Call_rpIoHwAb_PWM_PwmSetIdeal(IoHwAb_PwmSignalIdType PwmId, IoHwAb_ErrorType *ErrorStatus);




