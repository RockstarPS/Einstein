//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2018] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef IoHwAb_PwmIn_H
#define IoHwAb_PwmIn_H


#include "IoHwAb_PwmIn_Cfg.h"


#if defined(IOHWAB_PWMIN_ENABLE) && (IOHWAB_PWMIN_ENABLE == STD_ON)
//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
/*Define the type for periodId */
typedef   uint8   IoHwAb_PwmIn_PeriodId;
/*Define the type for DutyId  */
typedef   uint8   IoHwAb_PwmIn_DutyId;


//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================


extern void IoHwAb_PwmIn_Init(void);
extern void IoHwAb_PwmIn_DeInit(void);

/* Below function is used to validate whether the obtained input is valid or not*/
extern Std_ReturnType IoHwAb_PwmIn_ValidatePeriod_Using_Filter_ResolutionCalc(IoHwAb_PwmIn_PeriodId PeriodId ,  const uint32 NewHwValue , sint64* Period);
extern Std_ReturnType IoHwAb_PwmIn_ValidateDuty_Using_Filter_ResolutionCalc(IoHwAb_PwmIn_DutyId DutyId ,  const uint32 NewHwValue ,sint64* Duty);

/* Below function is used to calculate the filterd value for period and duty*/
extern Std_ReturnType IoHwAb_PwmIn_CalculatePeriod(IoHwAb_PwmIn_PeriodId PeriodId ,  const uint32 NewHwValue);
extern Std_ReturnType IoHwAb_PwmIn_CalculateDuty(IoHwAb_PwmIn_DutyId DutyId ,  const uint32 NewHwValue);

/* Below function is used to get the period and duty*/
extern Std_ReturnType IoHwAb_PwmIn_GetPeriod(IoHwAb_PwmIn_PeriodId PeriodId, uint32* Period);
extern Std_ReturnType IoHwAb_PwmIn_GetDuty(IoHwAb_PwmIn_DutyId DutyId, sint32* Duty);

/* Below function is used to get the duty in percentage*/
extern Std_ReturnType IoHwAb_PwmIn_GetDuty_InPercentage(IoHwAb_PwmIn_PeriodId PeriodId , IoHwAb_PwmIn_DutyId DutyId, uint16* Duty);

/* Below functions is used to reset the period and duty data */
extern Std_ReturnType IoHwAb_PwmIn_ResetPeriodData(IoHwAb_PwmIn_PeriodId PeriodId);
extern Std_ReturnType IoHwAb_PwmIn_ResetDutyData(IoHwAb_PwmIn_DutyId DutyId);

#endif

#endif /* IoHwAb_PwmIn_H*/
