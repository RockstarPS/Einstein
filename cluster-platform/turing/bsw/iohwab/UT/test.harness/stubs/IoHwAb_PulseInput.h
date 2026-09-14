/* ===========================================================================
                 CONFIDENTIAL VISTEON CORPORATION

  This is an unpublished work of authorship, which contains trade
  secrets, created in 2018.  Visteon Corporation owns all rights
  to this work and intends to maintain it in confidence to preserve
  its trade secret status.  Visteon Corporation reserves the right,
  under the copyright laws of the United States or those of any other
  country that may have jurisdiction, to protect this work as an
  unpublished work, in the event of an inadvertent or deliberate
  unauthorized publication.  Visteon Corporation also reserves its
  rights under all copyright laws to protect this work as a published
  work, when appropriate.  Those having access to this work may not
  copy it, use it, modify it, or disclose the information contained
  in it without the written authorization of Visteon Corporation.
======================================================================== */
/*!*************************************************************************************************
   @ingroup IoHwAb
   @defgroup PulseInputCapture
   @ingroup PulseInputCapture
   @file IoHwAb_PulseInput.h
   @brief IoHwAb_PulseInput Interfaces.
***************************************************************************************************/
#ifndef IoHwAb_PulseInput_H
#define IoHwAb_PulseInput_H


#include "IoHwAb_PulseInput_Cfg.h"

#if defined(IOHWAB_PULSEINPUT_ENABLE) && (IOHWAB_PULSEINPUT_ENABLE == STD_ON)
   
/***************************************************************************************************
*    P U B L I C   T Y P E   D E F I N I T I O N S                                                 *
***************************************************************************************************/

/**
* @brief This structure defines signal status, invalid & valid period/duty detection attributes
*/
typedef struct
{
  uint16   ChannelCurrentStatus;        /**<  variable whose bit definition has been defined conveys the signal status */
  uint16   ChannelStatus;               /**<  variable whose bit definition has been defined conveys the debounced signal status */
  uint16  MissingSignalCount;           /**<  variable that gets incremented during missing isr.*/
  uint16  MissingIgnoreCount;           /**<  variable that holds the ignored pulse count while signal status is missing.*/
#if(PULSE_INPUT_CHECK_VALID_PERIOD == STD_ON)
  uint16  InValidPeriodDetectionCount;  /**< timeout count used for detection of invalid period.*/
  uint16  ValidPeriodDetectionCount;    /**< timeout count used for detection of valid period.*/
#endif
#if(PULSE_INPUT_CHECK_VALID_DUTY == STD_ON)
  uint16  InValidDutyDetectionCount;    /**< timeout count used for detection of invalid duty.*/
  uint16  ValidDutyDetectionCount;      /**< timeout count used for detection of valid duty.*/
#endif
}SPulseInputChannel_Param;

/**
* @brief This structure defines configuration attributes of timeout for invalid and signal missing cases
*/
typedef struct
{
#if((PULSE_INPUT_CHECK_VALID_PERIOD == STD_ON) || (PULSE_INPUT_CHECK_VALID_DUTY == STD_ON))
  uint16  InValidTimeoutCount;         /**< configurable timeout count(in millisec) used for detection of invalid period/duty.*/
  uint16  InValidRecoveryTimeoutCount; /**< configurable timeout count(in millisec) used for detection of recovery from invalid period/duty.*/
#endif
  uint16  MissingTimeoutCount;         /**< configurable timeout count(in millisec) used for detection of signal missing status.*/
  uint32  MissingRecoveryTimeoutCount; /**< configurable timeout count(in microsec) used for detection of recovery of the signal from missing status.*/
}SPulseInputChannel_Config;

/**
* @brief This structure defines the index of filter configurations in period and duty
*/
typedef struct
{
    uint16  FilterCfgIndexForPeriod;  /**< Index of corresponding Filter Configuration(Attribute "SafeFilters") for period.*/
#if(PULSE_INPUT_CAPTURE_DUTY_VALUE == STD_ON)
    uint16  FilterCfgIndexForDuty;    /**< Index of corresponding Filter Configuration(Attribute "SafeFilters") for duty.*/
#endif
}SPulseInput_FilterCfgIndex;

#if((PULSE_INPUT_CHECK_HYST_FOR_PERIOD == STD_ON) || (PULSE_INPUT_CHECK_HYST_FOR_DUTY == STD_ON))
/**
* @brief This structure defines the hysteresis related attributes
*/
typedef struct
{
    uint32 HystLimit;              /**< Configurable lower(limit) hysteresis value */
    uint32 HystRcvry;              /**< Configurable higher(recovery) hysteresis value */
    uint8  HystFlow;               /**< Specify hysteresis flow(either incrmental or decremental) */
    uint32 CurrentVal;             /**< current value for which hysteresis needs to be applied */
    uint8  CurrentState;           /**< current hysteresis state(either OK or NotGood) */
}SHysteresis_Config;
#endif

#if((PULSE_INPUT_CHECK_VALID_PERIOD == STD_ON) || (PULSE_INPUT_CHECK_VALID_DUTY == STD_ON))
/**
* @brief This structure defines configuration attributes of valid period & duty range
*/
typedef struct
{
#if(PULSE_INPUT_CHECK_VALID_PERIOD == STD_ON)
	uint32 ValidPeriodMin;  /**< Configurable Valid Period Minimum Value in microsec */
	uint32 ValidPeriodMax;  /**< Configurable Valid Period Maximum Value in microsec*/
#endif
#if(PULSE_INPUT_CHECK_VALID_DUTY == STD_ON)
	uint16 ValidDutyMin;    /**< Configurable Valid Duty Minimum Value in percentage*/
	uint16 ValidDutyMax;    /**< ConfigurableValid Duty Maximum Value in percentage*/
#endif
}SSignal_Valid_Config;
#endif


/**
* @brief This structure defines calibration parameters which are required for speed calculation.
*/

#define PULSE_INPUT_CHANNEL_OPENED            ((uint16)0x01)
#define PULSE_INPUT_SIGNAL_NEVER_RECEIVED     ((uint16)0x02)
#define PULSE_INPUT_MISSING_LOW               ((uint16)0x04)
#define PULSE_INPUT_MISSING_HIGH              ((uint16)0x08)

#define PULSE_INPUT_INVALID_PERIOD_DETECTED   ((uint16)0x10)
#define PULSE_INPUT_VALID_PERIOD_DETECTED     ((uint16)0x20)
#define PULSE_INPUT_PERIOD_INVALID            ((uint16)0x40)
#define PULSE_INPUT_PERIOD_VALID              ((uint16)0x80)

#define PULSE_INPUT_INVALID_DUTY_DETECTED     ((uint16)0x100)
#define PULSE_INPUT_VALID_DUTY_DETECTED       ((uint16)0x200)
#define PULSE_INPUT_DUTY_INVALID              ((uint16)0x400)
#define PULSE_INPUT_DUTY_VALID                ((uint16)0x800)




//=====================================================================================================================
//  DECLARATIONS
//=====================================================================================================================

extern void IoHwAb_PulseInput_Init(void);
extern void IoHwAb_PulseInput_DeInit(void);
extern void IoHwAb_PulseInput_MainFunction(void);


/* Functions for the SWC*/
extern Std_ReturnType IoHwAb_PulseInput_Start_Signal_Measurement(IoHwAb_PulseInputSignalIdType PulseInputId, SPulseInputConfigParam *PulseInputChnlCfgParam, SSpeedCalcParam *SpdCalParam, IoHwAb_ErrorType* ErrorStatus);
extern Std_ReturnType IoHwAb_PulseInput_Stop_Signal_Measurement(IoHwAb_PulseInputSignalIdType PulseInputId, IoHwAb_ErrorType* ErrorStatus);
extern Std_ReturnType IoHwAb_PulseInput_Update_CalibParam(IoHwAb_PulseInputSignalIdType PulseInputId, SSpeedCalcParam *SpdCalParam, IoHwAb_ErrorType* ErrorStatus);
extern Std_ReturnType IoHwAb_PulseInput_GetRollingCount(IoHwAb_PulseInputSignalIdType PulseInputId, uint8 *EdgeCount, IoHwAb_ErrorType* ErrorStatus);
extern Std_ReturnType IoHwAb_PulseInput_ResetRollingCount(IoHwAb_PulseInputSignalIdType PulseInputId, IoHwAb_ErrorType* ErrorStatus);
extern Std_ReturnType IoHwAb_PulseInput_GetCurrentSignalStatus(IoHwAb_PulseInputSignalIdType PulseInputId, uint16 *SignalStatus, IoHwAb_ErrorType* ErrorStatus);
extern Std_ReturnType IoHwAb_PulseInput_GetCurrentSpeed(IoHwAb_PulseInputSignalIdType PulseInputId, uint32* SpeedVal, IoHwAb_ErrorType* ErrorStatus);

/* ISR function which calculate the period and duty*/
extern void IoHwAb_PulseInput_CalculatePeriod(IoHwAb_PwmIn_PeriodId Id, Icu_ValueType *TimeStamp_DataBuffer, uint16 BufferLength);
#if(PULSE_INPUT_CAPTURE_DUTY_VALUE == STD_ON)
    extern void IoHwAb_PulseInput_CalculateDuty(IoHwAb_PwmIn_DutyId Id, Icu_ValueType *TimeStamp_DataBuffer, uint16 BufferLength);
#endif


Icu_ValueType* IoHwAb_PulseInput_GetTimeStampBufferPointer(IoHwAb_PwmIn_PeriodId Id, uint16 *BufferLength);


#endif

#endif /* IoHwAb_PulseInput_H*/

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
/*-----------------------------------------------------------------------------
Date              : 08/June/2018
By                : asivalin
Traceability      : RTC #1128591
Change Description: Pulse input capture state management(Initial)
-------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
Date              :5-Dec-2018
By                :nrajaman
Traceability      :1206553: Hyundai SP2: PIC component upgrade for ASIL compliance.
Change Description:Updated for IoHwAb_PulseInput safe implementation
-------------------------------------------------------------------------------*/

