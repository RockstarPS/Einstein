/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2018. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*!***************************************************************************
* @ingroup Input-Output Hardware Abstraction
* @file IoHwAb.h
* @brief Main header file for IoHwAb
* ****************************************************************************/
#ifndef IOHWAB_H
#define IOHWAB_H
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/
#include "Rte_Type.h"
#include "IoHwAb_Cfg.h"
#include "Std_Types.h"
/*****************************************************************************
*  Public Forward Declarations                                          	 *
******************************************************************************/
/* MISRA C-2012 Rule 5.5 JUSTIFICATION: As per visteon coding standard function IoHwAb_Init is verified and same as macro does not have any functional imapct. */
extern void IoHwAb_Init(void);
/* MISRA C-2012 Rule 5.5 JUSTIFICATION: As per visteon coding standard function IoHwAb_MainFunction is verified and same as macro does not have any functional imapct. */
/* MISRA C-2012 Rule 8.5 JUSTIFICATION: As per visteon coding standard, the other declaration of IoHwAb_MainFunction is in RTE does not have any functional impact.*/
extern void IoHwAb_MainFunction(void);
/* MISRA C-2012 Rule 8.5 JUSTIFICATION: As per visteon coding standard, the other declaration of IoHwAb_DeInit is in Os_TrustedServiceCfg.h does not have any functional impact.*/
extern void IoHwAb_DeInit(void);
#if (IOHWAB_VERSION_INFO_API == STD_ON)
extern void IoHwAb_GetVersionInfo(Std_VersionInfoType* VersionInfo);
#endif
#if (IOHWAB_DOUT_ENABLE == STD_ON)
/* MISRA C-2012 Rule 8.3 JUSTIFICATION: As per code design, the other declaration of IoHwAb_SetOutputPin is in Os_TrustedServiceCfg.h does not have any functional impact.*/
extern Std_ReturnType IoHwAb_SetOutputPin(IoHwAb_DOutSignalIdType OutputId, boolean OutputSignal, IoHwAb_ErrorType* ErrorStatus);
/* MISRA C-2012 Rule 8.3 JUSTIFICATION: As per code design, the other declaration of IoHwAb_SetOutputGroup is in RTE does not have any functional impact.*/
/* MISRA C-2012 Rule 5.5 JUSTIFICATION: As per visteon coding standard,function IoHwAb_SetOutputGroup is verified and same as macro does not have any functional imapct.*/
extern Std_ReturnType IoHwAb_SetOutputGroup(IoHwAb_DOutGroupIdType OutputGroupId, uint32 OutputGroup, IoHwAb_ErrorType* ErrorStatus);
#endif
#if (IOHWAB_DIN_ENABLE == STD_ON)
/* MISRA C-2012 Rule 8.3 JUSTIFICATION: As per code design, the other declaration of IoHwAb_GetProcessedInput is in Os_TrustedServiceCfg.h does not have any functional impact.*/
/* MISRA C-2012 Rule 8.5 JUSTIFICATION: As per code design, the other declaration of IoHwAb_GetProcessedInput is in Os_TrustedServiceCfg.h does not have any functional impact.*/
extern Std_ReturnType IoHwAb_GetProcessedInput(IoHwAb_DInSignalIdType InputId, boolean* InputSignal, IoHwAb_ErrorType* ErrorStatus);
/* MISRA C-2012 Rule 8.3 JUSTIFICATION: As per code design, the other declaration of IoHwAb_GetAsyncRawInput is in Os_TrustedServiceCfg.h does not have any functional impact.*/
extern Std_ReturnType IoHwAb_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, boolean* AsyncInput, IoHwAb_ErrorType* ErrorStatus);
/* MISRA C-2012 Rule 8.3 JUSTIFICATION: As per code design, the other declaration of IoHwAb_GetSyncRawInput is in Os_TrustedServiceCfg.h does not have any functional impact.*/
extern Std_ReturnType IoHwAb_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, boolean* SyncInput, IoHwAb_ErrorType* ErrorStatus);
/* MISRA C-2012 Rule 5.5 JUSTIFICATION: As per visteon coding standard,function IoHwAb_GetInputGroup is verified and same as macro does not have any functional imapct.*/
/* MISRA C-2012 Rule 8.3 JUSTIFICATION: As per visteon coding standard, the other declaration of IoHwAb_GetInputGroup in RTE does not have any functional impact.*/
/* MISRA C-2012 Rule 8.5 JUSTIFICATION: As per visteon coding standard, the other declaration of IoHwAb_GetInputGroup in RTE does not have any functional impact.*/
extern Std_ReturnType IoHwAb_GetInputGroup(IoHwAb_DInGroupIdType InputGroupId, uint32* InputGroup, IoHwAb_ErrorType* ErrorStatus);
#endif
#if (IOHWAB_ADC_ENABLE == STD_ON)
/* MISRA C-2012 Rule 8.3 JUSTIFICATION: As per code design, the other declaration of IoHwAb_GetProcessedAdc is in Os_TrustedServiceCfg.h does not have any functional impact.*/
/* MISRA C-2012 Rule 8.5 JUSTIFICATION: As per visteon coding standard, the other declaration of IoHwAb_GetProcessedAdc is in Os_TrustedServiceCfg.h does not have any functional impact.*/
extern Std_ReturnType IoHwAb_GetProcessedAdc(IoHwAb_AdcSignalIdType AdcId, sint32* ProcessedAdc, IoHwAb_ErrorType* ErrorStatus);
/* MISRA C-2012 Rule 8.5 JUSTIFICATION: As per visteon coding standard, the other declaration of IoHwAb_GetProcessedAdc is in Os_TrustedServiceCfg.h does not have any functional impact.*/
/* MISRA C-2012 Rule 8.3 JUSTIFICATION: As per code design, the other declaration of IoHwAb_GetAsyncRawAdc is in Os_TrustedServiceCfg.h does not have any functional impact.*/
extern Std_ReturnType IoHwAb_GetAsyncRawAdc(IoHwAb_AdcSignalIdType AdcId, uint16* AsyncRawAdc, IoHwAb_ErrorType* ErrorStatus);
/* MISRA C-2012 Rule 8.3 JUSTIFICATION: As per code design, the other declaration of IoHwAb_GetSyncRawAdc is in Os_TrustedServiceCfg.h does not have any functional impact.*/
/* MISRA C-2012 Rule 8.5 JUSTIFICATION: As per visteon coding standard, the other declaration of IoHwAb_GetSyncRawAdc is in Os_TrustedServiceCfg.h does not have any functional impact.*/
extern Std_ReturnType IoHwAb_GetSyncRawAdc(IoHwAb_AdcSignalIdType AdcId, uint16* SyncRawAdc, IoHwAb_ErrorType* ErrorStatus);
#endif
#if defined(IOHWAB_PULSEINPUT_ENABLE) && (IOHWAB_PULSEINPUT_ENABLE == STD_ON)
extern Std_ReturnType IoHwAb_Start_Signal_Measurement_PulseInput(IoHwAb_PulseInputSignalIdType PulseInputId, SPulseInputConfigParam *PulseInputChnlCfgParam, SSpeedCalcParam *SpdCalParam , IoHwAb_ErrorType* ErrorStatus);
extern Std_ReturnType IoHwAb_Stop_Signal_Measurement_PulseInput(IoHwAb_PulseInputSignalIdType PulseInputId, IoHwAb_ErrorType* ErrorStatus);
extern Std_ReturnType IoHwAb_Update_CalibParam_PulseInput(IoHwAb_PulseInputSignalIdType PulseInputId,SSpeedCalcParam *SpdCalParam, IoHwAb_ErrorType* ErrorStatus);
extern Std_ReturnType IoHwAb_GetRollingCount_PulseInput(IoHwAb_PulseInputSignalIdType PulseInputId, uint8 *EdgeCount ,  IoHwAb_ErrorType* ErrorStatus);
extern Std_ReturnType IoHwAb_ResetRollingCount_PulseInput(IoHwAb_PulseInputSignalIdType PulseInputId, IoHwAb_ErrorType* ErrorStatus);
extern Std_ReturnType IoHwAb_GetCurrentSignalStatus_PulseInput(IoHwAb_PulseInputSignalIdType PulseInputId, uint16 *SignalStatus , IoHwAb_ErrorType* ErrorStatus);
extern Std_ReturnType IoHwAb_GetCurrentSpeed_PulseInput(IoHwAb_PulseInputSignalIdType PulseInputId, uint32* SpeedVal, IoHwAb_ErrorType* ErrorStatus);

#endif

#if (IOHWAB_PWM_ENABLE == STD_ON)
/* MISRA C-2012 Rule 8.5 JUSTIFICATION: As per visteon coding standard, the other declaration of IoHwAb_PwmSetDuty is in Os_TrustedServiceCfg.h does not have any functional impact.*/
/* MISRA C-2012 Rule 8.3 JUSTIFICATION: As per code design, the other declaration of IoHwAb_PwmSetDuty is in Os_TrustedServiceCfg.h does not have any functional impact.*/
extern Std_ReturnType IoHwAb_PwmSetDuty(IoHwAb_PwmSignalIdType PwmId, uint16 Pwm_Duty, IoHwAb_ErrorType* ErrorStatus);
/* MISRA C-2012 Rule 8.5 JUSTIFICATION: As per visteon coding standard, the other declaration of IoHwAb_PwmSetDutyAndPeriod is in Os_TrustedServiceCfg.h does not have any functional impact.*/
/* MISRA C-2012 Rule 8.3 JUSTIFICATION: As per code design, the other declaration of IoHwAb_PwmSetDutyAndPeriod is in Os_TrustedServiceCfg.h does not have any functional impact.*/
extern Std_ReturnType IoHwAb_PwmSetDutyAndPeriod(IoHwAb_PwmSignalIdType PwmId , uint32 Pwm_Period, uint16 Pwm_Duty, IoHwAb_ErrorType* ErrorStatus);
/* MISRA C-2012 Rule 8.3 JUSTIFICATION: As per code design, the other declaration of IoHwAb_PwmSetIdeal is in Os_TrustedServiceCfg.h does not have any functional impact.*/
/* MISRA C-2012 Rule 8.5 JUSTIFICATION: As per visteon coding standard, the other declaration of IoHwAb_PwmSetIdeal is in Os_TrustedServiceCfg.h does not have any functional impact.*/
extern Std_ReturnType IoHwAb_PwmSetIdeal(IoHwAb_PwmSignalIdType PwmId,  IoHwAb_ErrorType* ErrorStatus);
#endif

#endif //IOHWAB_H

/*End of File*/
/*****************************************************************************
*  for each change to this file, be sure to record:                         *
*     1.  who made the change and when the change was made                  *
*     2.  why the change was made and the intended result                   *
*  Following block needs to be repeated for each change
******************************************************************************
*  Note: In the trace-ability column we need to trace back to the Design Doc.*
*  For the initial version it is traced to the Design Document section.     *
*  For further changes it shall trace to the source of the change which may *
*  be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  *
*  other reason                                                            *
******************************************************************************/
/*****************************************************************************
Date              :22-Aug-2018
By                :pragesh
Traceability      :RTC-1181436:MMC: Safe IoHwAb Delivery
Change Description:Initial Version for IoHwAb safe implementation
******************************************************************************/

