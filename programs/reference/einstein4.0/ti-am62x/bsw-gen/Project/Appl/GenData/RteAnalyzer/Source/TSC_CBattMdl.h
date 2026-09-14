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
 *          File:  TSC_CBattMdl.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit write services */
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_HVP0Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_HVSD0Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_HVSD1Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_HVSD2Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_HVSD3Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_HVSD4Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_LVP0Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_LVP1Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_LVSD0Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_LVSD1Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_LVSD2Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_LVSD3Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_LVSD4Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_SVPFlag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_Voltage_OverVoltageInterruptFlag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_HVP0Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_HVSD0Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_HVSD1Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_HVSD2Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_HVSD3Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_HVSD4Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_LVP0Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_LVP1Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_LVSD0Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_LVSD1Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_LVSD2Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_LVSD3Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_LVSD4Flag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_AVP_SVPFlag(Boolean data);
Std_ReturnType TSC_CBattMdl_Rte_Write_ppSR_BattMdl_Voltage_OverVoltageInterruptFlag(Boolean data);

/** Client server interfaces */
Std_ReturnType TSC_CBattMdl_Rte_Call_rpIoHwAb_ADC_GetAsyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *AsyncRawAdc, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CBattMdl_Rte_Call_rpIoHwAb_ADC_GetProcessedAdc(IoHwAb_AdcSignalIdType AdcId, SInt32 *ProcessedAdc, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CBattMdl_Rte_Call_rpIoHwAb_ADC_GetSyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *SyncRawAdc, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CBattMdl_Rte_Call_rpIoHwAb_DOut_SetOutputGroup(IoHwAb_DOutGroupIdType InputId, UInt32 OutputGroup, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CBattMdl_Rte_Call_rpIoHwAb_DOut_SetOutputPin(IoHwAb_DOutSignalIdType InputId, Boolean OutputSignal, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CBattMdl_Rte_Call_rpIoHwAb_Din_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *AsyncInput, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CBattMdl_Rte_Call_rpIoHwAb_Din_GetInputGroup(IoHwAb_DInGroupIdType InputId, UInt32 *SyncInput, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CBattMdl_Rte_Call_rpIoHwAb_Din_GetProcessedInput(IoHwAb_DInSignalIdType InputId, Boolean *InputSignal, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CBattMdl_Rte_Call_rpIoHwAb_Din_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *SyncInput, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CBattMdl_Rte_Call_rpIoHwAb_ADC_GetAsyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *AsyncRawAdc, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CBattMdl_Rte_Call_rpIoHwAb_ADC_GetProcessedAdc(IoHwAb_AdcSignalIdType AdcId, SInt32 *ProcessedAdc, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CBattMdl_Rte_Call_rpIoHwAb_ADC_GetSyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *SyncRawAdc, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CBattMdl_Rte_Call_rpIoHwAb_DOut_SetOutputGroup(IoHwAb_DOutGroupIdType InputId, UInt32 OutputGroup, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CBattMdl_Rte_Call_rpIoHwAb_DOut_SetOutputPin(IoHwAb_DOutSignalIdType InputId, Boolean OutputSignal, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CBattMdl_Rte_Call_rpIoHwAb_Din_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *AsyncInput, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CBattMdl_Rte_Call_rpIoHwAb_Din_GetInputGroup(IoHwAb_DInGroupIdType InputId, UInt32 *SyncInput, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CBattMdl_Rte_Call_rpIoHwAb_Din_GetProcessedInput(IoHwAb_DInSignalIdType InputId, Boolean *InputSignal, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_CBattMdl_Rte_Call_rpIoHwAb_Din_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *SyncInput, IoHwAb_ErrorType *ErrorStatus);




