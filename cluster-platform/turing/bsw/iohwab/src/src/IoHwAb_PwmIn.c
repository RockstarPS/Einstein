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

/*!********************************************************************************************************************
* @ingroup PulseInputCapture
* @file IoHwAb_PwmIn.c
* @brief Provide interfaces for getting the period & duty values.
* ********************************************************************************************************************/
/**********************************************************************************************************************
*  Include Files                                                                                                      *
*********************************************************************************************************************/

#include "Rte_IoHwAb.h"
#include "IoHwAb_PwmIn.h"


#if defined(IOHWAB_PWMIN_ENABLE) && (IOHWAB_PWMIN_ENABLE == STD_ON)

#define RESOLUTION_IN_0_POINT_01  ((uint32)100)
#define RESOLUTION_IN_0_POINT_1   ((uint32)10)
//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

typedef struct
{
    uint32 RawValue;
    sint32 FilteredValue;
} IoHwAb_PwmInElementType;

//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================
#define IoHwAb_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include <IoHwAb_MemMap.h>

/* Structure is used to hold the raw and filtered data for period*/
static IoHwAb_PwmInElementType  IoHwAb_PwmInPeriodValInfo[IOHWAB_NUM_OF_PERIOD_SIGNALS];
/* Structure is used to hold the raw and filtered data for Duty*/
static IoHwAb_PwmInElementType  IoHwAb_PwmInDutyValInfo[IOHWAB_NUM_OF_DUTY_SIGNALS];

#define IoHwAb_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include <IoHwAb_MemMap.h>

//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================

#define IoHwAb_START_SEC_CODE
#include <IoHwAb_MemMap.h>
/**
* This method initialize the IoHwAb PwmIn module
* @param     none
* @return    void
*/
void IoHwAb_PwmIn_Init(void)
{
    uint8 Index;

    /* Init the required data*/
    for(Index = 0u ; Index < IOHWAB_NUM_OF_PERIOD_SIGNALS; Index ++)
    {
        IoHwAb_PwmInPeriodValInfo[Index].RawValue        = 0U;
        IoHwAb_PwmInPeriodValInfo[Index].FilteredValue   = 0U;

    }

    for(Index = 0u ; Index < IOHWAB_NUM_OF_DUTY_SIGNALS; Index ++)
    {
        IoHwAb_PwmInDutyValInfo[Index].RawValue         = 0U;
        IoHwAb_PwmInDutyValInfo[Index].FilteredValue    = 0U;
    }
}


/**
* This method Deinit the IoHwAb PwmIn module
* @param     none
* @return    void
*/
void IoHwAb_PwmIn_DeInit(void)
{

    uint8 Index;

    /* Init the required data*/
    for(Index = 0u ; Index < IOHWAB_NUM_OF_PERIOD_SIGNALS; Index ++)
    {
        IoHwAb_PwmInPeriodValInfo[Index].RawValue        = 0U;
        IoHwAb_PwmInPeriodValInfo[Index].FilteredValue   = 0U;

    }

    for(Index = 0u ; Index < IOHWAB_NUM_OF_DUTY_SIGNALS; Index ++)
    {
        IoHwAb_PwmInDutyValInfo[Index].RawValue         = 0U;
        IoHwAb_PwmInDutyValInfo[Index].FilteredValue    = 0U;
    }

}



/**
* In this function , the input from the PIC is evaluated for the Period
* @param  PeriodId   - Represent the period ID
* @param  NewHwValue - Value for which validity should be done
* @param  Period     -  Evaluated Period value
* @return Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_PwmIn_ValidatePeriod_Using_Filter_ResolutionCalc(IoHwAb_PwmIn_PeriodId PeriodId,  const uint32 NewHwValue, sint64* Period)
{
    Std_ReturnType Result;
    sint32 Filtdvalue;

    Result = E_NOT_OK;
    if(PeriodId < IOHWAB_NUM_OF_PERIOD_SIGNALS)
    {

        Result  = IoHwAb_Filter_ResolutionCalc(IoHwAb_PwmInPeriodCfg[PeriodId].ResolutionCalc_FilterCfgIx_period, NewHwValue, &Filtdvalue);
        if(E_OK == Result)
        {
            IoHwAb_PwmInPeriodValInfo[PeriodId].RawValue = Filtdvalue;
            *Period = (sint64)IoHwAb_PwmInPeriodValInfo[PeriodId].RawValue;
        }

    }
    else
    {
        Result = E_INVALID_ARG;
    }


    return Result;
}


/**
* In this function , the input from the PIC is evaluated for the Duty
* @param  DutyId     - Represent the Duty ID
* @param  NewHwValue - Value for which validity should be done
* @param  Duty       -  Evaluated Duty value
* @return Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_PwmIn_ValidateDuty_Using_Filter_ResolutionCalc(IoHwAb_PwmIn_DutyId DutyId,  const uint32 NewHwValue,sint64* Duty)
{
    Std_ReturnType Result;
    sint32 Filtdvalue;

    Result = E_NOT_OK;

    if(DutyId < IOHWAB_NUM_OF_DUTY_SIGNALS)
    {
        Result = IoHwAb_Filter_ResolutionCalc(IoHwAb_PwmInDutyCfg[DutyId].ResolutionCalc_FilterCfgIx_duty, NewHwValue, &Filtdvalue);

        if(E_OK == Result)
        {
            IoHwAb_PwmInDutyValInfo[DutyId].RawValue = Filtdvalue;

            *Duty = (sint64)IoHwAb_PwmInDutyValInfo[DutyId].RawValue;
        }
    }
    else
    {
        Result = E_INVALID_ARG;
    }


    return Result;
}

/**
* In this function , filter is applied depending on cfg and period is calculated
* @param  PeriodId     - Represent the period ID
* @param  NewHwValue   - Value for which period is calculated
* @return Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_PwmIn_CalculatePeriod(IoHwAb_PwmIn_PeriodId PeriodId,  const uint32 NewHwValue)
{

    Std_ReturnType Status;
    uint32 TmpValue;
    uint32 TmpFilteredValue = 0U;
    sint32 ResolCalFiltdvalue = 0;
    EFilterMethod TempFilterKindPeriod;

    TmpValue = NewHwValue;

    Status = E_NOT_OK;

    if(PeriodId < IOHWAB_NUM_OF_PERIOD_SIGNALS)
    {
        TempFilterKindPeriod = IoHwAb_PwmInPeriodCfg[PeriodId].FilterType_period;


        switch(TempFilterKindPeriod)
        {
        case eFilter_MovingAvg:
            /* Apply moving avg filter*/
            Status = IoHwAb_Filter_MovingAvgFilter(IoHwAb_PwmInPeriodCfg[PeriodId].FilterCfgIx_period, TmpValue, & TmpFilteredValue);
            break;

        case  eFilter_Avg:
            /* Apply avg filter*/
            Status = IoHwAb_Filter_AvgFilter(IoHwAb_PwmInPeriodCfg[PeriodId].FilterCfgIx_period, TmpValue, & TmpFilteredValue);
            break;

        default:
            Status = E_NOT_OK;
            break;
        }

        if(E_OK == Status)
        {

            Status = IoHwAb_Filter_ResolutionCalc(IoHwAb_PwmInPeriodCfg[PeriodId].ResolutionCalc_FilterCfgIx_period, TmpFilteredValue, &ResolCalFiltdvalue);

            /* Store the result in the period buffer*/
            IoHwAb_PwmInPeriodValInfo[PeriodId].FilteredValue = ResolCalFiltdvalue;
        }
    }
    else
    {
        Status = E_INVALID_ARG;
    }

    return Status;
}


/**
* In this function , filter is applied depending on cfg and duty is calculated
* @param  DutyId     - Represent the Duty ID
* @param  NewHwValue   - Value for which duty is calculated
* @return Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_PwmIn_CalculateDuty(IoHwAb_PwmIn_DutyId DutyId,  const uint32 NewHwValue)
{
    Std_ReturnType Status;
    uint32 TmpFilteredValue = 0U;
    sint32 ResolCalFiltdvalue = 0;
    uint32 TmpValue;
    EFilterMethod TempFilterKindDuty;

    TmpValue = NewHwValue;

    Status = E_NOT_OK;

    if(DutyId < IOHWAB_NUM_OF_DUTY_SIGNALS)
    {

        TempFilterKindDuty = IoHwAb_PwmInDutyCfg[DutyId].FilterType_duty;


        switch(TempFilterKindDuty)
        {
        case eFilter_MovingAvg:
            /* Apply moving avg filter*/
            Status = IoHwAb_Filter_MovingAvgFilter( IoHwAb_PwmInDutyCfg[DutyId].FilterCfgIx_duty, TmpValue, & TmpFilteredValue);
            break;

        case eFilter_Avg:
            /* Apply avg filter*/
            Status = IoHwAb_Filter_AvgFilter(IoHwAb_PwmInDutyCfg[DutyId].FilterCfgIx_duty, TmpValue, & TmpFilteredValue);
            break;

        default:
            Status = E_NOT_OK;
            break;
        }

        if(E_OK == Status)
        {

            Status = IoHwAb_Filter_ResolutionCalc(IoHwAb_PwmInDutyCfg[DutyId].ResolutionCalc_FilterCfgIx_duty, TmpFilteredValue, &ResolCalFiltdvalue);

            /* Store the result in the duty buffer*/
            IoHwAb_PwmInDutyValInfo[DutyId].FilteredValue = ResolCalFiltdvalue;
        }
    }
    else
    {
        Status = E_INVALID_ARG;
    }


    return Status;
}


/**
  This method is used to get the calculated period value for the given signal
* @param PeriodId - period Id
* @param uint32* Period - Pointer to get the period value
* @return    Std_ReturnType E_OK-period Value is updated, E_NOT_OK-period value is not updated
*/
Std_ReturnType IoHwAb_PwmIn_GetPeriod(IoHwAb_PwmIn_PeriodId PeriodId, uint32* Period)
{
    Std_ReturnType Ret = E_NOT_OK;

    if(PeriodId < IOHWAB_NUM_OF_PERIOD_SIGNALS)
    {
        *Period = IoHwAb_PwmInPeriodValInfo[PeriodId].FilteredValue;
        Ret = E_OK;
    }
    else
    {
        Ret = E_INVALID_ARG;
    }

    return Ret;

}

/**
  This method is used to get the calculated duty value for the given signal
* @param[in] DutyId - Duty Id
* @param[in] sint32* Duty - Pointer to get the duty value
* @return    Std_ReturnType E_OK-duty Value is updated, E_NOT_OK-duty value is not updated
*/
Std_ReturnType IoHwAb_PwmIn_GetDuty(IoHwAb_PwmIn_DutyId DutyId, sint32* Duty)
{
    Std_ReturnType Ret = E_NOT_OK;


    if(DutyId < IOHWAB_NUM_OF_DUTY_SIGNALS)
    {
        *Duty = IoHwAb_PwmInDutyValInfo[DutyId].FilteredValue;
        Ret = E_OK;
    }
    else
    {
        Ret = E_INVALID_ARG;
    }

    return Ret;
}

/**
  This method is used to get the calculated duty value  in percentage for the given signal
* @param[in] PeriodId - Period Id
* @param[in] DutyId - Duty Id
* @param[in] uint16* Duty - Pointer to get the duty value
* @return    Std_ReturnType E_OK-duty Value is updated, E_NOT_OK-duty value is not updated
*/
Std_ReturnType IoHwAb_PwmIn_GetDuty_InPercentage(IoHwAb_PwmIn_PeriodId PeriodId, IoHwAb_PwmIn_DutyId DutyId, uint16* Duty)
{
    Std_ReturnType Ret = E_NOT_OK;
    uint32 PulsePeriodInMicroSec=0U;
    uint32 DutyVal=0U;
    uint16 DutyInPercentage=0U;


    if((DutyId >= IOHWAB_NUM_OF_DUTY_SIGNALS) || (PeriodId >= IOHWAB_NUM_OF_PERIOD_SIGNALS))
    {
        Ret = E_INVALID_ARG;
    }

    if(E_INVALID_ARG != Ret)
    {
        DutyVal = IoHwAb_PwmInDutyValInfo[DutyId].FilteredValue;

        PulsePeriodInMicroSec = IoHwAb_PwmInPeriodValInfo[PeriodId].FilteredValue;

        if(PulsePeriodInMicroSec != 0U)
        {
            DutyInPercentage = (uint16)((DutyVal *RESOLUTION_IN_0_POINT_01 * RESOLUTION_IN_0_POINT_1)/PulsePeriodInMicroSec); // with 0.1 resolution
            (*Duty) = DutyInPercentage;
            Ret = E_OK;
        }
    }

    return Ret;

}

/**
  This method is used to reset the data buffer for the particular period Id
* @param[in] PeriodId - Period Id
* @return    Std_ReturnType E_OK-duty Value is updated, E_NOT_OK-duty value is not updated
*/
Std_ReturnType IoHwAb_PwmIn_ResetPeriodData(IoHwAb_PwmIn_PeriodId PeriodId)
{
    Std_ReturnType Status;
    EFilterMethod TempFilterKindPeriod;


    Status = E_NOT_OK;

    if(PeriodId < IOHWAB_NUM_OF_PERIOD_SIGNALS)
    {
        TempFilterKindPeriod = IoHwAb_PwmInPeriodCfg[PeriodId].FilterType_period;

        IoHwAb_PwmInPeriodValInfo[PeriodId].RawValue        = 0U;
        IoHwAb_PwmInPeriodValInfo[PeriodId].FilteredValue   = 0U;

        switch(TempFilterKindPeriod)
        {
        case eFilter_MovingAvg:
            /* Apply moving avg filter*/
            Status = IoHwAb_Filter_ResetFilter(eFilter_MovingAvg, IoHwAb_PwmInPeriodCfg[PeriodId].FilterCfgIx_period);
            break;

        case  eFilter_Avg:
            /* Apply avg filter_32*/
            Status = IoHwAb_Filter_ResetFilter(eFilter_Avg, IoHwAb_PwmInPeriodCfg[PeriodId].FilterCfgIx_period);
            break;

        default:
            Status = E_NOT_OK;
            break;
        }
    }
    else
    {
        Status = E_INVALID_ARG;
    }

    return Status;
}

/**
  This method is used to reset the data buffer for the particular duty Id
* @param[in] DutyId - Duty Id
* @return    Std_ReturnType E_OK-duty Value is updated, E_NOT_OK-duty value is not updated
*/
Std_ReturnType IoHwAb_PwmIn_ResetDutyData(IoHwAb_PwmIn_DutyId DutyId)
{
    Std_ReturnType Status;
    EFilterMethod TempFilterKindPeriod;

    Status = E_NOT_OK;

    if(DutyId < IOHWAB_NUM_OF_DUTY_SIGNALS)
    {
        TempFilterKindPeriod = IoHwAb_PwmInDutyCfg[DutyId].FilterType_duty;

        IoHwAb_PwmInDutyValInfo[DutyId].RawValue         = 0U;
        IoHwAb_PwmInDutyValInfo[DutyId].FilteredValue    = 0U;

        switch(TempFilterKindPeriod)
        {
        case eFilter_MovingAvg:
            /* Apply moving avg filter*/
            Status = IoHwAb_Filter_ResetFilter(eFilter_MovingAvg, IoHwAb_PwmInDutyCfg[DutyId].FilterCfgIx_duty);
            break;

        case  eFilter_Avg:
            /* Apply avg filter_32*/
            Status = IoHwAb_Filter_ResetFilter(eFilter_Avg, IoHwAb_PwmInDutyCfg[DutyId].FilterCfgIx_duty);
            break;

        default:
            Status = E_NOT_OK;
            break;
        }

    }
    else
    {
        Status = E_INVALID_ARG;
    }

    return Status;

}

#define IoHwAb_STOP_SEC_CODE
#include <IoHwAb_MemMap.h>

#endif

/* End of File*/
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
/*-----------------------------------------------------------------------------
Date              : 18/Apr/2018
By                : asivalin
Traceability      : RTC #194482
Change Description: Initial
-------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
Date              : 08/June/2018
By                : asivalin
Traceability      : RTC #1128591
Change Description: Updated the duty value in percentage unit
-------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
Date              :5-Dec-2018
By                :nrajaman
Traceability      :1206553: Hyundai SP2: PIC component upgrade for ASIL compliance.
Change Description:Updated for IoHwAb_PulseInput safe implementation
-------------------------------------------------------------------------------*/
/*****************************************************************************
Date              :21-Dec-2018
By                :nrajaman
Traceability      :1206553: Hyundai SP2: PIC component upgrade for ASIL compliance.
Change Description:PR comments updated
******************************************************************************/
/*****************************************************************************
Date              :02-Aug-2022
By                :jkanikal
Traceability      :1710112:[vautosar]iohwab quality
Change Description:IoHwAb Audit Fix Coverity Misra warnings fix
******************************************************************************/
/*****************************************************************************
Date              :17-Aug-2022
By                :jkanikal
Traceability      :1736922: [vautosar]BSW general requirements for IOHW
Change Description:Added Misra warning comments as per bsw generalrequiremenr
******************************************************************************/
