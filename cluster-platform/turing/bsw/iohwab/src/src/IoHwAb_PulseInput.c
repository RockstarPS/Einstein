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
/*!********************************************************************************************************************
* @ingroup PulseInputCapture
* @file IoHwAb_PulseInput.c
* @brief Capturing of external pulse input and calculate the period & duty values.
* ********************************************************************************************************************/

/**********************************************************************************************************************
*  Include Files                                                                                                      *
*********************************************************************************************************************/

#include "Rte_IoHwAb.h"
#include "IoHwAb_PulseInput.h"
//#include "IoHwAb_Gpt.h"

#if defined(IOHWAB_PULSEINPUT_ENABLE) && (IOHWAB_PULSEINPUT_ENABLE == STD_ON)

#if((PULSE_INPUT_CHECK_HYST_FOR_PERIOD == STD_ON) && (PULSE_INPUT_CHECK_VALID_PERIOD == STD_OFF))
#error Hysteresis could be applied to Period, only when PULSE_INPUT_CHECK_VALID_PERIOD is enabled. So enable the same
#endif

#if(((PULSE_INPUT_CHECK_VALID_DUTY == STD_ON) || (PULSE_INPUT_CHECK_HYST_FOR_DUTY == STD_ON)) && (PULSE_INPUT_CAPTURE_DUTY_VALUE == STD_OFF))
#error Validity Check and Hysteresis could be applied to Duty, only when PULSE_INPUT_CAPTURE_DUTY_VALUE is enabled. So enable the same
#endif

#if((PULSE_INPUT_CHECK_HYST_FOR_DUTY == STD_ON) && (PULSE_INPUT_CHECK_VALID_DUTY == STD_OFF))
#error Hysteresis could be applied to Duty, only when PULSE_INPUT_CHECK_VALID_DUTY is enabled. So enable the same
#endif

/**********************************************************************************************************************
*  Private Macros Definitions                                                                                         *                                                                                       *
**********************************************************************************************************************/
#if((PULSE_INPUT_CHECK_HYST_FOR_PERIOD == STD_ON) || (PULSE_INPUT_CHECK_HYST_FOR_DUTY == STD_ON))
#define HYST_DECR                 ((uint8)0x00)
#define HYST_INCR                 ((uint8)0x01)

#define HYST_OK                   ((uint8)0x00)
#define HYST_NG                   ((uint8)0x01)
#endif

#define TIME_IN_SECONDS_PER_HOUR  ((uint32)3600)
#define RESOLUTION_IN_0_POINT_01  ((uint32)100)
#define RESOLUTION_IN_0_POINT_1   ((uint32)10)
#define CONVERT_TO_PERCENTAGE     ((uint32)100)

#define TESTBIT( operand, bit_mask )   		(((operand) &  (bit_mask)) != ((bit_mask) - (bit_mask)))
#define SETBIT( operand, bit_mask )         ((operand) |= (bit_mask))
#define CLEARBIT( operand, bit_mask )       ((operand) &= (~(bit_mask)))


#define IoHwAb_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include <IoHwAb_MemMap.h>

/**********************************************************************************************************************
*  Private Variable Definitions                                                                                       *
**********************************************************************************************************************/
static SPulseInputChannel_Param PulseInputChnlStatus[IOHWAB_PULSEINPUT_NUMBER_OF_SIGNALS];
static SPulseInputChannel_Config PulseInputChnlCfg[IOHWAB_PULSEINPUT_NUMBER_OF_SIGNALS];


#if(PULSE_INPUT_CHECK_HYST_FOR_PERIOD == STD_ON)
static SHysteresis_Config HystCfg_PeriodMin[IOHWAB_PULSEINPUT_NUMBER_OF_SIGNALS];
static SHysteresis_Config HystCfg_PeriodMax[IOHWAB_PULSEINPUT_NUMBER_OF_SIGNALS];
#endif

#if(PULSE_INPUT_CHECK_HYST_FOR_DUTY == STD_ON)
static SHysteresis_Config HystCfg_DutyMin[IOHWAB_PULSEINPUT_NUMBER_OF_SIGNALS];
static SHysteresis_Config HystCfg_DutyMax[IOHWAB_PULSEINPUT_NUMBER_OF_SIGNALS];
#endif

#if((PULSE_INPUT_CHECK_VALID_PERIOD == STD_ON) || (PULSE_INPUT_CHECK_VALID_DUTY == STD_ON))
static SSignal_Valid_Config SignalValidCfg[IOHWAB_PULSEINPUT_NUMBER_OF_SIGNALS];
#endif

static SSpeedCalcParam SpeedCalcParam[IOHWAB_PULSEINPUT_NUMBER_OF_SIGNALS];

#define IoHwAb_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include <IoHwAb_MemMap.h>


#define IOHWAB_START_SEC_BURAM_DATA
#include <IoHwAb_MemMap.h>
uint8 Pulse_Count[IOHWAB_PULSEINPUT_NUMBER_OF_SIGNALS]; /**< To store the pulse count value in backup ram */
#define IOHWAB_STOP_SEC_BURAM_DATA
#include <IoHwAb_MemMap.h>

static void IoHwAb_PulseInput_Channel_Initialization(IoHwAb_PwmIn_PeriodId ChannelId);
static void IoHwAb_PulseInput_Update_ConfigParam(IoHwAb_PwmIn_PeriodId ChannelId, SPulseInputConfigParam *PulseInputChnlCfgParam);
static void IoHwAb_PulseInput_UpdatePulseCount(IoHwAb_PwmIn_PeriodId Id);
static void IoHwAb_PulseInput_MissingStatus_Update(IoHwAb_PwmIn_PeriodId Id);

#if((PULSE_INPUT_CHECK_VALID_PERIOD == STD_ON) || (PULSE_INPUT_CHECK_VALID_DUTY == STD_ON))
static void IoHwAb_PulseInput_ValidityStatus_Update(IoHwAb_PwmIn_PeriodId Id);
#endif

#if((PULSE_INPUT_CHECK_HYST_FOR_PERIOD == STD_ON) || (PULSE_INPUT_CHECK_HYST_FOR_DUTY == STD_ON))
static void IoHwAb_PulseInput_Update_Hysteresis_State(IoHwAb_PwmIn_PeriodId Id, SHysteresis_Config *HystConfig);
static void IoHwAb_PulseInput_Update_Hysteresis_Flow(IoHwAb_PwmIn_PeriodId PeriodInId);
#endif


#define IoHwAb_START_SEC_CODE
#include <IoHwAb_MemMap.h>

/**
* This method Initialize pulse input capture module
* @param     None
* @return    void
*/
void IoHwAb_PulseInput_Init(void)
{
    IoHwAb_PwmIn_PeriodId PeriodInId=0U;

    for(PeriodInId = 0U; PeriodInId < ((uint32)IOHWAB_PULSEINPUT_NUMBER_OF_SIGNALS); PeriodInId++)
    {
        IoHwAb_PulseInput_Channel_Initialization(PeriodInId);
        SETBIT(PulseInputChnlStatus[PeriodInId].ChannelCurrentStatus, PULSE_INPUT_SIGNAL_NEVER_RECEIVED);
        SETBIT(PulseInputChnlStatus[PeriodInId].ChannelStatus, PULSE_INPUT_SIGNAL_NEVER_RECEIVED);
    }
}

/**
* This method de-initialize pulse input capture module
* @param     None
* @return    void
*/
void IoHwAb_PulseInput_DeInit(void)
{
    IoHwAb_PwmIn_PeriodId PeriodInId=0U;

    for(PeriodInId = 0U; PeriodInId < ((uint32)IOHWAB_PULSEINPUT_NUMBER_OF_SIGNALS); PeriodInId++)
    {
        IoHwAb_PulseInput_Channel_Initialization(PeriodInId);
        SETBIT(PulseInputChnlStatus[PeriodInId].ChannelCurrentStatus, PULSE_INPUT_SIGNAL_NEVER_RECEIVED);
        SETBIT(PulseInputChnlStatus[PeriodInId].ChannelStatus, PULSE_INPUT_SIGNAL_NEVER_RECEIVED);
    }
}


/**
* This is a periodic runnable to handle all the periodic activities of Pulse Input module
* @param None
* @return    void
*/
void IoHwAb_PulseInput_MainFunction(void)
{
    IoHwAb_PwmIn_PeriodId PeriodInId = 0U;

    IOHWAB_PULSEINPUT_ENTER_CRITICAL_SECTION();
    for (PeriodInId = 0U; PeriodInId < ((uint32)IOHWAB_PULSEINPUT_NUMBER_OF_SIGNALS); PeriodInId ++)
    {
        if(TESTBIT(PulseInputChnlStatus[PeriodInId].ChannelCurrentStatus,PULSE_INPUT_CHANNEL_OPENED) != 0)
        {
#if((PULSE_INPUT_CHECK_VALID_PERIOD == STD_ON) || (PULSE_INPUT_CHECK_VALID_DUTY == STD_ON))
            IoHwAb_PulseInput_ValidityStatus_Update(PeriodInId);
#endif

            if(TESTBIT((PulseInputChnlStatus[PeriodInId].ChannelCurrentStatus), PULSE_INPUT_SIGNAL_NEVER_RECEIVED) == 0)
            {
                IoHwAb_PulseInput_MissingStatus_Update(PeriodInId);
            }
        }
    }
    IOHWAB_PULSEINPUT_EXIT_CRITICAL_SECTION();
}



#if(PULSE_INPUT_CAPTURE_DUTY_VALUE == STD_ON)
/**
* This method is used to calculate the duty from the timestamp captured b/w rising and falling edge
* @param Id - Channel Id of PIC
* @param *TimeStamp_DataBuffer - TimeStamp Buffer
* @param BufferLength - Data length
* @return    void
*/
void IoHwAb_PulseInput_CalculateDuty(IoHwAb_PwmIn_DutyId Id, Icu_ValueType *TimeStamp_DataBuffer, uint16 BufferLength)
{
    uint32 TimerTicksCount=0U;
    Icu_IndexType CurIndex=0U,PrevIndex=0U;
    uint16 Index=0U;
#if(PULSE_INPUT_CHECK_VALID_DUTY == STD_ON)
    uint16 DutyInPercentage=0U;
    uint32 PulsePeriodInMicroSec=0U;
    uint32 ReceivedDuty=0U;
    sint64 DutyVal=0;
    Std_ReturnType ret=E_NOT_OK;
    Std_ReturnType ValDutyresult=E_NOT_OK;
#endif

    for (Index = 0U; (Index < IOHWAB_NUM_OF_DUTY_SIGNALS); Index ++)
    {
        if (Id == IoHwAb_PwmInDutyCfg[Index].DutyId)
        {
            CurIndex = Icu_GetTimestampIndex(IoHwAb_PwmInDutyCfg[Index].HwId);
            if(CurIndex == 0U)
            {
                CurIndex = (Icu_IndexType)(BufferLength-1); //BufferSize is hardcoded as of now
                PrevIndex = CurIndex - 1;
            }

            else
            {
                CurIndex--;
                if(CurIndex == 0U)
                {
                    PrevIndex = (Icu_IndexType)(BufferLength-1); //BufferSize is hardcoded as of now
                }
                else
                {
                    PrevIndex = CurIndex - 1;
                }
            }
            TimerTicksCount = TimeStamp_DataBuffer[CurIndex] - TimeStamp_DataBuffer[PrevIndex];

            if((TESTBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_MISSING_HIGH)==0) && (TESTBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_MISSING_LOW)==0))
            {
#if(PULSE_INPUT_CHECK_VALID_DUTY == STD_ON)
                if(TESTBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_VALID_PERIOD_DETECTED)!=0)
                {
                    ret = IoHwAb_PwmIn_GetPeriod(Id, &PulsePeriodInMicroSec);

                    if((PulsePeriodInMicroSec != 0U) && (ret == E_OK))
                    {
                        /* IoHwAb_PwmIn_ValidateDuty_Using_Filter_ResolutionCalc function is used to evaluate whether the obtained data is valid data.*/
                        ValDutyresult = IoHwAb_PwmIn_ValidateDuty_Using_Filter_ResolutionCalc(IoHwAb_PwmInDutyCfg[Index].DutyId, TimerTicksCount, &DutyVal);

                        if(E_NOT_OK != ValDutyresult)
                        {
                            ReceivedDuty = (uint32)DutyVal;
                        }

                        DutyInPercentage = (uint16)((ReceivedDuty *CONVERT_TO_PERCENTAGE * RESOLUTION_IN_0_POINT_1)/PulsePeriodInMicroSec); // with 0.1 resolution
                        if((DutyInPercentage >=  SignalValidCfg[Id].ValidDutyMin) && (DutyInPercentage <=  SignalValidCfg[Id].ValidDutyMax))
                        {
                            CLEARBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_INVALID_DUTY_DETECTED);
                            SETBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_VALID_DUTY_DETECTED);
                        }
                        else
                        {
                            SETBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_INVALID_DUTY_DETECTED);
                            CLEARBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_VALID_DUTY_DETECTED);
                        }
                    }

#if(PULSE_INPUT_CHECK_HYST_FOR_DUTY == STD_ON)
                    HystCfg_DutyMin[Id].CurrentVal = (uint32)DutyInPercentage;
                    IoHwAb_PulseInput_Update_Hysteresis_State((IoHwAb_PwmIn_PeriodId)Id, &HystCfg_DutyMin[Id]);

                    HystCfg_DutyMax[Id].CurrentVal = (uint32)DutyInPercentage;
                    IoHwAb_PulseInput_Update_Hysteresis_State((IoHwAb_PwmIn_PeriodId)Id, &HystCfg_DutyMax[Id]);

                    if((HystCfg_DutyMin[Id].CurrentState == HYST_OK) && (HystCfg_DutyMax[Id].CurrentState == HYST_OK))
                    {
                        CLEARBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_INVALID_DUTY_DETECTED);
                        SETBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_VALID_DUTY_DETECTED);
                    }
                    else
                    {
                        CLEARBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_VALID_DUTY_DETECTED);
                        SETBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_INVALID_DUTY_DETECTED);
                    }
#endif
                }
                else
                {
                    /* If Period is invalid, then there is no meaning of checking whether the duty has valid or not. So we will make the duty as invalid*/
                    SETBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_INVALID_DUTY_DETECTED);
                    CLEARBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_VALID_DUTY_DETECTED);
                }

#elif(PULSE_INPUT_CHECK_HYST_FOR_DUTY == STD_OFF)
                CLEARBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_INVALID_DUTY_DETECTED);
                SETBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_VALID_DUTY_DETECTED);

#endif
            }

            if(TESTBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_VALID_DUTY_DETECTED)!=0)
            {
                IoHwAb_PwmIn_CalculateDuty(IoHwAb_PwmInDutyCfg[Index].DutyId, (THwData)TimerTicksCount);
            }
            PulseInputChnlStatus[Id].MissingSignalCount = 0U;
        }
    }
}
#endif


/**
* This method is used to calculate the period from the timestamp captured at the two rising/falling edges
* @param Id - Channel Id of PIC
* @param *TimeStamp_DataBuffer - TimeStamp Buffer
* @param BufferLength - Data length
* @return    void
*/
void IoHwAb_PulseInput_CalculatePeriod(IoHwAb_PwmIn_PeriodId Id, Icu_ValueType *TimeStamp_DataBuffer, uint16 BufferLength)
{
    uint32 TimerTicksCount = 0U;
    Icu_IndexType CurIndex=0U;
    Icu_IndexType PrevIndex=0U;
    uint16 Index=0U;
    uint32 ReceivedPeriod=0U;
    sint64 PeriodVal=0;
    Std_ReturnType RetValue = E_NOT_OK;

    for (Index = 0U; (Index < ((uint32)IOHWAB_PULSEINPUT_NUMBER_OF_SIGNALS)); Index ++)
    {
        if (Id == IoHwAb_PwmInPeriodCfg[Index].PeriodId)
        {
            CurIndex = Icu_GetTimestampIndex(IoHwAb_PwmInPeriodCfg[Index].HwId);
            if(CurIndex == 0)
            {
                CurIndex = (Icu_IndexType)(BufferLength-1); /* BufferSize is hardcoded as of now*/
#if(PULSE_INPUT_CAPTURE_DUTY_VALUE == STD_ON)
                PrevIndex = CurIndex - 2;
#else
                PrevIndex = CurIndex - 1;
#endif
            }

            else
            {
                CurIndex--;
                if(CurIndex == 0U)
                {
#if(PULSE_INPUT_CAPTURE_DUTY_VALUE == STD_ON)
                    PrevIndex = BufferLength - 2;
#else
                    PrevIndex = BufferLength - 1;
#endif
                }
                else
                {
                    if(CurIndex == 1U)
                    {
#if(PULSE_INPUT_CAPTURE_DUTY_VALUE == STD_ON)
                        PrevIndex = (Icu_IndexType)(BufferLength - 1);
#else
                        PrevIndex = 0U;
#endif
                    }
                    else
                    {
#if(PULSE_INPUT_CAPTURE_DUTY_VALUE == STD_ON)
                        PrevIndex = CurIndex - 2;
#else
                        PrevIndex = CurIndex - 1;
#endif
                    }
                }
            }
            TimerTicksCount = TimeStamp_DataBuffer[CurIndex] - TimeStamp_DataBuffer[PrevIndex];
            /* IoHwAb_PwmIn_ValidatePeriod_Using_Filter_ResolutionCalc function is used to evaluate whether the obtained data is valid data.*/
            RetValue = IoHwAb_PwmIn_ValidatePeriod_Using_Filter_ResolutionCalc(IoHwAb_PwmInPeriodCfg[Index].PeriodId, TimerTicksCount, &PeriodVal);

            if(E_NOT_OK != RetValue)
            {
                ReceivedPeriod = (uint32)PeriodVal;
            }

            if((TESTBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_MISSING_HIGH)!=0) || (TESTBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_MISSING_LOW)!=0))
            {
                PulseInputChnlStatus[Id].MissingIgnoreCount++;
                if((ReceivedPeriod <= PulseInputChnlCfg[Id].MissingRecoveryTimeoutCount) && (PulseInputChnlStatus[Id].MissingIgnoreCount >1))
                {
                    CLEARBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_MISSING_HIGH);
                    CLEARBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_MISSING_HIGH);
                    CLEARBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_MISSING_LOW);
                    CLEARBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_MISSING_LOW);
                    PulseInputChnlStatus[Id].MissingIgnoreCount = 0U;
                }
            }

            CLEARBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_SIGNAL_NEVER_RECEIVED);
            CLEARBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_SIGNAL_NEVER_RECEIVED);

            if((TESTBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_MISSING_HIGH)==0) && (TESTBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_MISSING_LOW)==0))
            {
#if(PULSE_INPUT_CHECK_VALID_PERIOD == STD_ON)
                if((ReceivedPeriod <=  SignalValidCfg[Id].ValidPeriodMin) && (ReceivedPeriod >=  SignalValidCfg[Id].ValidPeriodMax))
                {
                    CLEARBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_INVALID_PERIOD_DETECTED);
                    SETBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_VALID_PERIOD_DETECTED);
                }
                else
                {
                    SETBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_INVALID_PERIOD_DETECTED);
                    CLEARBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_VALID_PERIOD_DETECTED);
                }

#elif(PULSE_INPUT_CHECK_HYST_FOR_PERIOD == STD_OFF)
                CLEARBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_INVALID_PERIOD_DETECTED);
                SETBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_VALID_PERIOD_DETECTED);

#endif

#if(PULSE_INPUT_CHECK_HYST_FOR_PERIOD == STD_ON)
                HystCfg_PeriodMin[Id].CurrentVal = ReceivedPeriod;
                IoHwAb_PulseInput_Update_Hysteresis_State(Id, &HystCfg_PeriodMin[Id]);

                HystCfg_PeriodMax[Id].CurrentVal = ReceivedPeriod;
                IoHwAb_PulseInput_Update_Hysteresis_State(Id, &HystCfg_PeriodMax[Id]);

                if((HystCfg_PeriodMin[Id].CurrentState == HYST_OK) && (HystCfg_PeriodMax[Id].CurrentState == HYST_OK))
                {
                    CLEARBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_INVALID_PERIOD_DETECTED);
                    SETBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_VALID_PERIOD_DETECTED);
                }
                else
                {
                    SETBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_INVALID_PERIOD_DETECTED);
                    CLEARBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_VALID_PERIOD_DETECTED);
                }
#endif
            }

            if(TESTBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_VALID_PERIOD_DETECTED)!=0)
            {
                RetValue = IoHwAb_PwmIn_CalculatePeriod(IoHwAb_PwmInPeriodCfg[Index].PeriodId, (THwData)TimerTicksCount);
#if(PULSE_INPUT_CAPTURE_DUTY_VALUE == STD_ON)
                if(TESTBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_VALID_DUTY_DETECTED)!=0)
#endif
                {
                    if(RetValue == E_OK)
                    {
                        IoHwAb_PulseInput_UpdatePulseCount(Id);
                    }
                }
            }
            PulseInputChnlStatus[Id].MissingSignalCount = 0U;
        }
    }
}



/**
* This method initialize all the variables of a channel
* @param ChannelId - Channel Id of PIC
* @return    void
*/
static void IoHwAb_PulseInput_Channel_Initialization(IoHwAb_PwmIn_PeriodId ChannelId)
{
    PulseInputChnlStatus[ChannelId].ChannelCurrentStatus = 0U;
    PulseInputChnlStatus[ChannelId].ChannelStatus = 0U;
    PulseInputChnlStatus[ChannelId].MissingSignalCount = 0U;
    PulseInputChnlStatus[ChannelId].MissingIgnoreCount = 0U;
    PulseInputChnlStatus[ChannelId].ChannelCurrentStatus = 0U;
    PulseInputChnlStatus[ChannelId].ChannelStatus = 0U;

#if(PULSE_INPUT_CHECK_VALID_PERIOD == STD_ON)
    PulseInputChnlStatus[ChannelId].InValidPeriodDetectionCount = 0U;
    PulseInputChnlStatus[ChannelId].ValidPeriodDetectionCount = 0U;
#endif

#if(PULSE_INPUT_CHECK_VALID_DUTY == STD_ON)
    PulseInputChnlStatus[ChannelId].InValidDutyDetectionCount = 0U;
    PulseInputChnlStatus[ChannelId].ValidDutyDetectionCount = 0U;
#endif

#if(PULSE_INPUT_CHECK_HYST_FOR_PERIOD == STD_ON)
    HystCfg_PeriodMin[ChannelId].CurrentVal = 0U;
    HystCfg_PeriodMin[ChannelId].CurrentState = 0U;

    HystCfg_PeriodMax[ChannelId].CurrentVal = 0U;
    HystCfg_PeriodMax[ChannelId].CurrentState = 0U;
#endif

#if(PULSE_INPUT_CHECK_HYST_FOR_DUTY == STD_ON)
    HystCfg_DutyMin[ChannelId].CurrentVal = 0U;
    HystCfg_DutyMin[ChannelId].CurrentState = 0U;

    HystCfg_DutyMax[ChannelId].CurrentVal = 0U;
    HystCfg_DutyMax[ChannelId].CurrentState = 0U;
#endif

    (void)IoHwAb_PwmIn_ResetPeriodData(IoHwAb_PwmInPeriodCfg[ChannelId].PeriodId);
    (void)IoHwAb_PwmIn_CalculatePeriod(IoHwAb_PwmInPeriodCfg[ChannelId].PeriodId, (THwData)0);

#if(PULSE_INPUT_CAPTURE_DUTY_VALUE == STD_ON)

    IoHwAb_PwmIn_ResetDutyData(IoHwAb_PwmInDutyCfg[ChannelId].DutyId);
    IoHwAb_PwmIn_CalculateDuty(IoHwAb_PwmInDutyCfg[ChannelId].DutyId, (THwData)0);
#endif
}

/**
  This method updates the configuration parameters of a pulse input channel
* @param ChannelId - Channel Id of PIC
* @param PulseInputChnlCfgParam - Structure Pointer having dynamic configuration parameters of a Pulse Input Channel
* @return    void
*/
static void IoHwAb_PulseInput_Update_ConfigParam(IoHwAb_PwmIn_PeriodId ChannelId, SPulseInputConfigParam *PulseInputChnlCfgParam)
{
    PulseInputChnlCfg[ChannelId].MissingTimeoutCount = (PulseInputChnlCfgParam->MissingTimeoutInMilliSec/IOHWAB_PULSEINPUT_MAINFUNCTION_PERIODICITY);
    PulseInputChnlCfg[ChannelId].MissingRecoveryTimeoutCount = PulseInputChnlCfgParam->MissingRecoveryTimeoutInMicroSec;

#if(PULSE_INPUT_CHECK_VALID_PERIOD == STD_ON)
    SignalValidCfg[ChannelId].ValidPeriodMin = PulseInputChnlCfgParam->ValidPeriodMinInMicroSec;
    SignalValidCfg[ChannelId].ValidPeriodMax = PulseInputChnlCfgParam->ValidPeriodMaxInMicroSec;
#endif

#if(PULSE_INPUT_CHECK_VALID_DUTY == STD_ON)
    SignalValidCfg[ChannelId].ValidDutyMin = PulseInputChnlCfgParam->ValidDutyMinInPercentage;
    SignalValidCfg[ChannelId].ValidDutyMax = PulseInputChnlCfgParam->ValidDutyMaxInPercentage;
#endif

#if((PULSE_INPUT_CHECK_VALID_PERIOD == STD_ON) || (PULSE_INPUT_CHECK_VALID_DUTY == STD_ON))
    PulseInputChnlCfg[ChannelId].InValidTimeoutCount = (PulseInputChnlCfgParam->InValidTimeoutInMilliSec/IOHWAB_PULSEINPUT_MAINFUNCTION_PERIODICITY);
    PulseInputChnlCfg[ChannelId].InValidRecoveryTimeoutCount = (PulseInputChnlCfgParam->InValidRecoveryTimeoutInMilliSec/IOHWAB_PULSEINPUT_MAINFUNCTION_PERIODICITY);
#endif

#if(PULSE_INPUT_CHECK_HYST_FOR_PERIOD == STD_ON)
    HystCfg_PeriodMin[ChannelId].HystLimit = PulseInputChnlCfgParam->HystLimitForPeriodMinInMicroSec;
    HystCfg_PeriodMin[ChannelId].HystRcvry = PulseInputChnlCfgParam->HystRcvryForPeriodMinInMicroSec;

    HystCfg_PeriodMax[ChannelId].HystLimit = PulseInputChnlCfgParam->HystLimitForPeriodMaxInMicroSec;
    HystCfg_PeriodMax[ChannelId].HystRcvry = PulseInputChnlCfgParam->HystRcvryForPeriodMaxInMicroSec;
#endif

#if(PULSE_INPUT_CHECK_HYST_FOR_DUTY == STD_ON)
    HystCfg_DutyMin[ChannelId].HystLimit = (uint32)PulseInputChnlCfgParam->HystLimitForDutyMinInPercentage;
    HystCfg_DutyMin[ChannelId].HystRcvry = (uint32)PulseInputChnlCfgParam->HystRcvryForDutyMinInPercentage;

    HystCfg_DutyMax[ChannelId].HystLimit = (uint32)PulseInputChnlCfgParam->HystLimitForDutyMaxInPercentage;
    HystCfg_DutyMax[ChannelId].HystRcvry = (uint32)PulseInputChnlCfgParam->HystRcvryForDutyMaxInPercentage;
#endif
}



/**
* This method is used to detect the signal missing status
* @param ChannelId - Channel Id of PIC
* @return    void
*/
static void IoHwAb_PulseInput_MissingStatus_Update(IoHwAb_PwmIn_PeriodId Id)
{
    PulseInputChnlStatus[Id].MissingSignalCount++;
    if(PulseInputChnlStatus[Id].MissingSignalCount >= PulseInputChnlCfg[Id].MissingTimeoutCount)
    {
        IoHwAb_PulseInput_Channel_Initialization(Id);
        SETBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus,PULSE_INPUT_CHANNEL_OPENED);
        if(Dio_ReadChannel(IoHwAb_PwmInPeriodCfg[Id].DioChnlId) == STD_HIGH)
        {
            SETBIT((PulseInputChnlStatus[Id].ChannelCurrentStatus), PULSE_INPUT_MISSING_HIGH);
            SETBIT((PulseInputChnlStatus[Id].ChannelStatus), PULSE_INPUT_MISSING_HIGH);
        }
        else
        {
            SETBIT((PulseInputChnlStatus[Id].ChannelCurrentStatus), PULSE_INPUT_MISSING_LOW);
            SETBIT((PulseInputChnlStatus[Id].ChannelStatus), PULSE_INPUT_MISSING_LOW);
        }
        PulseInputChnlStatus[Id].MissingSignalCount = 0U;
        PulseInputChnlStatus[Id].MissingIgnoreCount = 0U;
    }
}

#if((PULSE_INPUT_CHECK_VALID_PERIOD == STD_ON) || (PULSE_INPUT_CHECK_VALID_DUTY == STD_ON))
/**
* This method apply the debouncing mechanism for the following entities(InValid Period Detection,
* Valid Period Detection, InValid Duty Detection, Valid Duty Detection) of a channel
* @param[in] Id - Channel Id of PIC
* @return    void
*/
static void IoHwAb_PulseInput_ValidityStatus_Update(IoHwAb_PwmIn_PeriodId Id)
{
#if(PULSE_INPUT_CHECK_VALID_PERIOD == STD_ON)
    /* InValid Period Detection */
    if((TESTBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_INVALID_PERIOD_DETECTED) != 0))
    {
        PulseInputChnlStatus[Id].InValidPeriodDetectionCount++;
        if(TESTBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_INVALID_PERIOD_DETECTED) == 0)
        {
            CLEARBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_VALID_PERIOD_DETECTED);
            CLEARBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_PERIOD_INVALID);
            SETBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_INVALID_PERIOD_DETECTED);
            PulseInputChnlStatus[Id].InValidPeriodDetectionCount = 0U;
        }
        else if(PulseInputChnlStatus[Id].InValidPeriodDetectionCount >= PulseInputChnlCfg[Id].InValidTimeoutCount)
        {
            CLEARBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_VALID_PERIOD_DETECTED);
            CLEARBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_PERIOD_VALID);
            SETBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_PERIOD_INVALID);
            SETBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_INVALID_PERIOD_DETECTED);
        }
    }

    /* Valid Period Detection */
    if((TESTBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_VALID_PERIOD_DETECTED) != 0))
    {
        PulseInputChnlStatus[Id].ValidPeriodDetectionCount++;
        if(TESTBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_VALID_PERIOD_DETECTED) == 0)
        {
            CLEARBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_INVALID_PERIOD_DETECTED);
            CLEARBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_PERIOD_VALID);
            SETBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_VALID_PERIOD_DETECTED);
            PulseInputChnlStatus[Id].ValidPeriodDetectionCount = 0U;
        }
        else if(PulseInputChnlStatus[Id].ValidPeriodDetectionCount >= PulseInputChnlCfg[Id].InValidRecoveryTimeoutCount)
        {
            CLEARBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_INVALID_PERIOD_DETECTED);
            CLEARBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_PERIOD_INVALID);
            SETBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_PERIOD_VALID);
            SETBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_VALID_PERIOD_DETECTED);
        }
    }
#endif

#if(PULSE_INPUT_CHECK_VALID_DUTY == STD_ON)
    /* InValid Duty Detection*/
    if((TESTBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_INVALID_DUTY_DETECTED) != 0))
    {
        PulseInputChnlStatus[Id].InValidDutyDetectionCount++;
        if(TESTBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_INVALID_DUTY_DETECTED) == 0)
        {
            CLEARBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_VALID_DUTY_DETECTED);
            CLEARBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_DUTY_INVALID);
            SETBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_INVALID_DUTY_DETECTED);
            PulseInputChnlStatus[Id].InValidDutyDetectionCount = 0U;
        }
        else if(PulseInputChnlStatus[Id].InValidDutyDetectionCount >= PulseInputChnlCfg[Id].InValidTimeoutCount)
        {
            CLEARBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_VALID_DUTY_DETECTED);
            CLEARBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_DUTY_VALID);
            SETBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_DUTY_INVALID);
            SETBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_INVALID_DUTY_DETECTED);
        }
    }

    /* Valid Duty Detection */
    if((TESTBIT(PulseInputChnlStatus[Id].ChannelCurrentStatus, PULSE_INPUT_VALID_DUTY_DETECTED) != 0))
    {
        PulseInputChnlStatus[Id].ValidDutyDetectionCount++;
        if(TESTBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_VALID_DUTY_DETECTED) == 0)
        {
            CLEARBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_INVALID_DUTY_DETECTED);
            CLEARBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_DUTY_VALID);
            SETBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_VALID_DUTY_DETECTED);
            PulseInputChnlStatus[Id].ValidDutyDetectionCount = 0U;
        }
        else if(PulseInputChnlStatus[Id].ValidDutyDetectionCount >= PulseInputChnlCfg[Id].InValidRecoveryTimeoutCount)
        {
            CLEARBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_INVALID_DUTY_DETECTED);
            CLEARBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_DUTY_INVALID);
            SETBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_DUTY_VALID);
            SETBIT(PulseInputChnlStatus[Id].ChannelStatus, PULSE_INPUT_VALID_DUTY_DETECTED);
        }
    }
#endif
}
#endif



/**
* This method is used to update the pulse count of a channel
* @param Id - Channel Id of PIC
* @return    void
*/
static void IoHwAb_PulseInput_UpdatePulseCount(IoHwAb_PwmIn_PeriodId Id)
{
    Pulse_Count[Id] += IoHwAb_PwmInPeriodCfg[Id].NotificationInterval;
}

#if((PULSE_INPUT_CHECK_HYST_FOR_PERIOD == STD_ON) || (PULSE_INPUT_CHECK_HYST_FOR_DUTY == STD_ON))
/**
* This method is used to update the hysteresis status(either OK or NotGood) for the given value
* @param Id - Channel Id of PIC
* @param SHysteresis_Config *HystConfig - Structure Pointer having attributes used for hysteresis check
* @return    void
*/
static void IoHwAb_PulseInput_Update_Hysteresis_State(IoHwAb_PwmIn_PeriodId Id, SHysteresis_Config *HystConfig)
{
    if(HystConfig[Id].HystFlow == HYST_INCR)
    {
        if(HystConfig[Id].CurrentState == HYST_OK)
        {
            if(HystConfig[Id].CurrentVal < HystConfig[Id].HystLimit)
            {
                HystConfig[Id].CurrentState = HYST_NG;
            }
        }
        else
        {
            if(HystConfig[Id].CurrentVal >= HystConfig[Id].HystRcvry)
            {
                HystConfig[Id].CurrentState = HYST_OK;
            }
        }
    }
    else if(HystConfig[Id].HystFlow == HYST_DECR)
    {
        if(HystConfig[Id].CurrentState == HYST_OK)
        {
            if(HystConfig[Id].CurrentVal > HystConfig[Id].HystLimit)
            {
                HystConfig[Id].CurrentState = HYST_NG;
            }
        }
        else
        {
            if(HystConfig[Id].CurrentVal <= HystConfig[Id].HystRcvry)
            {
                HystConfig[Id].CurrentState = HYST_OK;
            }
        }
    }
    else
    {
    }
}

/**
* This method is used to check and update the hysteresis flow direction of a channel
* based on the hysteresis limit & recovery attributes configuration
* @param PeriodInId - Channel Id of PIC
* @return    void
*/
static void IoHwAb_PulseInput_Update_Hysteresis_Flow(IoHwAb_PwmIn_PeriodId PeriodInId)
{
#if(PULSE_INPUT_CHECK_HYST_FOR_PERIOD == STD_ON)
    if(HystCfg_PeriodMin[PeriodInId].HystLimit <= HystCfg_PeriodMin[PeriodInId].HystRcvry)
    {
        HystCfg_PeriodMin[PeriodInId].HystFlow = HYST_INCR;
    }
    else
    {
        HystCfg_PeriodMin[PeriodInId].HystFlow = HYST_DECR;
    }

    if(HystCfg_PeriodMax[PeriodInId].HystLimit <= HystCfg_PeriodMax[PeriodInId].HystRcvry)
    {
        HystCfg_PeriodMax[PeriodInId].HystFlow = HYST_INCR;
    }
    else
    {
        HystCfg_PeriodMax[PeriodInId].HystFlow = HYST_DECR;
    }
#endif

#if(PULSE_INPUT_CHECK_HYST_FOR_DUTY == STD_ON)
    if(HystCfg_DutyMin[PeriodInId].HystLimit <= HystCfg_DutyMin[PeriodInId].HystRcvry)
    {
        HystCfg_DutyMin[PeriodInId].HystFlow = HYST_INCR;
    }
    else
    {
        HystCfg_DutyMin[PeriodInId].HystFlow = HYST_DECR;
    }

    if(HystCfg_DutyMax[PeriodInId].HystLimit <= HystCfg_DutyMax[PeriodInId].HystRcvry)
    {
        HystCfg_DutyMax[PeriodInId].HystFlow = HYST_INCR;
    }
    else
    {
        HystCfg_DutyMax[PeriodInId].HystFlow = HYST_DECR;
    }
#endif
}
#endif


/* Function for the SWC*/

/**
 * This method starts the period & duty measurement on a specific Pulse Input Channel
 * @param PulseInputId - PulseInputId Id from application
 * @param PulseInputChnlCfgParam - Structure Pointer having dynamic configuration parameters of a Pulse Input Channel
 * @param SpdCalParam - Structure Pointer having attributes needed for Speed calculation
 * @return Std_ReturnType E_OK-Measurement Started, E_NOT_OK-Measurement NotStarted
 */
Std_ReturnType IoHwAb_PulseInput_Start_Signal_Measurement(IoHwAb_PulseInputSignalIdType PulseInputId, SPulseInputConfigParam *PulseInputChnlCfgParam, SSpeedCalcParam *SpdCalParam, IoHwAb_ErrorType* ErrorStatus)
{
    IoHwAb_PwmIn_PeriodId PeriodInId = 0U;
    uint16 BufferLength=0U;
    Std_ReturnType Ret = E_NOT_OK;
    Icu_ValueType *BufferPtr;
    *ErrorStatus = IOHWAB_E_ERROR;
    IoHwAb_ErrorType TempErrorStatus;


    if(PulseInputId < ((uint32)IOHWAB_PULSEINPUT_NUMBER_OF_SIGNALS))
    {
        /* Map the respective priodId which is configured*/
        PeriodInId = (uint32)IoHwAb_PulseInputCfg[PulseInputId].MapPeriodId;

        if((PulseInputChnlCfgParam != NULL) && (SpdCalParam != NULL))
        {
            IoHwAb_PulseInput_Channel_Initialization(PeriodInId);
            Ret = IoHwAb_PulseInput_Update_CalibParam(PeriodInId, SpdCalParam, &TempErrorStatus);
            IoHwAb_PulseInput_Update_ConfigParam(PeriodInId, PulseInputChnlCfgParam);
#if((PULSE_INPUT_CHECK_HYST_FOR_PERIOD == STD_ON) || (PULSE_INPUT_CHECK_HYST_FOR_DUTY == STD_ON))
            IoHwAb_PulseInput_Update_Hysteresis_Flow(PeriodInId);
#endif

            BufferPtr = IoHwAb_PulseInput_GetTimeStampBufferPointer(PeriodInId, &BufferLength);
            if((BufferPtr != NULL) && (Ret == E_OK) && (TempErrorStatus == IOHWAB_E_NO_ERROR))
            {
                Icu_EnableNotification(IoHwAb_PwmInPeriodCfg[PeriodInId].HwId);
                Icu_SetActivationCondition(IoHwAb_PwmInPeriodCfg[PeriodInId].HwId, IoHwAb_PwmInPeriodCfg[PeriodInId].ActivationEdge);
                IoHwAb_Gpt_StartTimer(IoHwAb_PwmInPeriodCfg[PeriodInId].TmrChannelId, IoHwAb_PwmInPeriodCfg[PeriodInId].TimerCountMax);
                Icu_StartTimestamp(IoHwAb_PwmInPeriodCfg[PeriodInId].HwId, BufferPtr, BufferLength, IoHwAb_PwmInPeriodCfg[PeriodInId].NotificationInterval);

                SETBIT(PulseInputChnlStatus[PeriodInId].ChannelCurrentStatus, PULSE_INPUT_SIGNAL_NEVER_RECEIVED);
                SETBIT(PulseInputChnlStatus[PeriodInId].ChannelCurrentStatus,PULSE_INPUT_CHANNEL_OPENED);
                SETBIT(PulseInputChnlStatus[PeriodInId].ChannelStatus, PULSE_INPUT_SIGNAL_NEVER_RECEIVED);
            }
        }

        /* Updating the Error status for passing to SWC*/
        if(Ret == E_OK)
        {
            *ErrorStatus =  IOHWAB_E_NO_ERROR;
        }
        else if(Ret == E_NOT_OK)
        {
            *ErrorStatus = IOHWAB_E_ERROR;
        }
        else
        {
            /* DO nothing */
        }

    }
    else
    {
        Ret = IOHWAB_E_PULSEINPUT_ID_INVALID;
    }

    return Ret;
}

/**
* This method stops the period & duty measurement on a specific Pulse Input Channel
* @param PulseInputId - PulseInputId Id from application
* @return    Std_ReturnType E_OK-Measurement Stopped, E_NOT_OK-Measurement NotStopped
*/
Std_ReturnType IoHwAb_PulseInput_Stop_Signal_Measurement(IoHwAb_PulseInputSignalIdType PulseInputId, IoHwAb_ErrorType* ErrorStatus)
{
    IoHwAb_PwmIn_PeriodId PeriodInId = 0U;
    Std_ReturnType Ret = E_NOT_OK;
    *ErrorStatus = IOHWAB_E_ERROR;

    if(PulseInputId < ((uint32)IOHWAB_PULSEINPUT_NUMBER_OF_SIGNALS))
    {
        /* Map the respective priodId which is configured*/
        PeriodInId = (uint32)IoHwAb_PulseInputCfg[PulseInputId].MapPeriodId;

        Icu_StopTimestamp(IoHwAb_PwmInPeriodCfg[PeriodInId].HwId);
        IoHwAb_Gpt_StopTimer(IoHwAb_PwmInPeriodCfg[PeriodInId].TmrChannelId);
        Icu_DisableNotification(IoHwAb_PwmInPeriodCfg[PeriodInId].HwId);

        IoHwAb_PulseInput_Channel_Initialization(PeriodInId);
        SETBIT(PulseInputChnlStatus[PeriodInId].ChannelCurrentStatus, PULSE_INPUT_SIGNAL_NEVER_RECEIVED);
        SETBIT(PulseInputChnlStatus[PeriodInId].ChannelStatus, PULSE_INPUT_SIGNAL_NEVER_RECEIVED);
        Ret = E_OK;

        *ErrorStatus =  IOHWAB_E_NO_ERROR;


    }
    else
    {
        Ret = IOHWAB_E_PULSEINPUT_ID_INVALID;
    }


    return Ret;
}



/**
  This method updates the calibration parameters(needed for speed calculation) of a pulse input channel
* @param  PulseInputId - PulseInputId Id from application
* @param  SpdCalParam - Structure Pointer having attributes needed for Speed calculation
* @return Std_ReturnType E_OK-Parameters Updated, E_NOT_OK-Parameters Not Updated
*/
Std_ReturnType IoHwAb_PulseInput_Update_CalibParam(IoHwAb_PulseInputSignalIdType PulseInputId, SSpeedCalcParam *SpdCalParam, IoHwAb_ErrorType* ErrorStatus)
{
    IoHwAb_PwmIn_PeriodId PeriodInId;
    Std_ReturnType Ret = E_NOT_OK;
    *ErrorStatus = IOHWAB_E_ERROR;

    if(PulseInputId < ((uint32)IOHWAB_PULSEINPUT_NUMBER_OF_SIGNALS))
    {
        /* Map the respective priodId which is configured*/
        PeriodInId = (uint32)IoHwAb_PulseInputCfg[PulseInputId].MapPeriodId;

        if(SpdCalParam != NULL)
        {
            SpeedCalcParam[PeriodInId].Pulses_Per_Revolution = SpdCalParam->Pulses_Per_Revolution;
            SpeedCalcParam[PeriodInId].Revolutions_Per_Unit = SpdCalParam->Revolutions_Per_Unit;
            SpeedCalcParam[PeriodInId].Tuning_Factor = SpdCalParam->Tuning_Factor;
            Ret = E_OK;

            *ErrorStatus =  IOHWAB_E_NO_ERROR;
        }
    }
    else
    {
        Ret = IOHWAB_E_PULSEINPUT_ID_INVALID;
    }


    return Ret;
}

/**
* This method is used to get the pulse count of a channel
* @param PulseInputId - PulseInputId Id from application
* @param uint8 *EdgeCount - Pointer to receive the edge count
* @return Std_ReturnType E_OK-successful returning of rolling count, E_NOT_OK-rolling count is not updated in data pointer
*/
Std_ReturnType IoHwAb_PulseInput_GetRollingCount(IoHwAb_PulseInputSignalIdType PulseInputId, uint8 *EdgeCount, IoHwAb_ErrorType* ErrorStatus)
{
    IoHwAb_PwmIn_PeriodId PeriodInId;
    Std_ReturnType Ret = E_NOT_OK;
    *ErrorStatus = IOHWAB_E_ERROR;

    if(PulseInputId < ((uint32)IOHWAB_PULSEINPUT_NUMBER_OF_SIGNALS))
    {
        /* Map the respective priodId which is configured*/
        PeriodInId = (uint32)IoHwAb_PulseInputCfg[PulseInputId].MapPeriodId;

        IOHWAB_PULSEINPUT_ENTER_CRITICAL_SECTION();
        *EdgeCount = Pulse_Count[PeriodInId];
        IOHWAB_PULSEINPUT_EXIT_CRITICAL_SECTION();
        Ret = E_OK;

        *ErrorStatus =  IOHWAB_E_NO_ERROR;

    }
    else
    {
        *ErrorStatus = IOHWAB_E_PULSEINPUT_ID_INVALID;
    }

    return Ret;
}

/**
* This method is used to reset the pulse count of a channel
* @param PulseInputId - PulseInputId Id from application
* @return Std_ReturnType E_OK-successful reset of rolling count, E_NOT_OK-rolling count is not reset
*/
Std_ReturnType IoHwAb_PulseInput_ResetRollingCount(IoHwAb_PulseInputSignalIdType PulseInputId, IoHwAb_ErrorType* ErrorStatus)
{
    IoHwAb_PwmIn_PeriodId PeriodInId;
    Std_ReturnType Ret = E_NOT_OK;
    *ErrorStatus = IOHWAB_E_ERROR;

    if(PulseInputId < ((uint32)IOHWAB_PULSEINPUT_NUMBER_OF_SIGNALS))
    {
        /* Map the respective priodId which is configured*/
        PeriodInId = (uint32)IoHwAb_PulseInputCfg[PulseInputId].MapPeriodId;

        IOHWAB_PULSEINPUT_ENTER_CRITICAL_SECTION();
        Pulse_Count[PeriodInId] = 0U;
        IOHWAB_PULSEINPUT_EXIT_CRITICAL_SECTION();
        Ret = E_OK;

        *ErrorStatus =  IOHWAB_E_NO_ERROR;


    }
    else
    {
        *ErrorStatus = IOHWAB_E_PULSEINPUT_ID_INVALID;
    }

    return Ret;
}

/**
* This method is used to get the signal status a channel
* @param PulseInputId - PulseInputId Id from application
* @param uint16 *SignalStatus - Pointer to receive the signal status
* @return Std_ReturnType E_OK-successful returning of signal status, E_NOT_OK-signal status is not updated in data pointer
*/
Std_ReturnType IoHwAb_PulseInput_GetCurrentSignalStatus(IoHwAb_PulseInputSignalIdType PulseInputId, uint16 *SignalStatus, IoHwAb_ErrorType* ErrorStatus)
{
    IoHwAb_PwmIn_PeriodId PeriodInId;
    Std_ReturnType Ret = E_NOT_OK;
    *ErrorStatus = IOHWAB_E_ERROR;


    if(PulseInputId < ((uint32)IOHWAB_PULSEINPUT_NUMBER_OF_SIGNALS))
    {

        /* Map the respective priodId which is configured*/
        PeriodInId = (uint32)IoHwAb_PulseInputCfg[PulseInputId].MapPeriodId;

#if(PULSE_INPUT_CAPTURE_DUTY_VALUE == STD_ON)
        *SignalStatus = PulseInputChnlStatus[PeriodInId].ChannelStatus & ( PULSE_INPUT_SIGNAL_NEVER_RECEIVED | PULSE_INPUT_MISSING_LOW | PULSE_INPUT_MISSING_HIGH | PULSE_INPUT_PERIOD_VALID | PULSE_INPUT_PERIOD_INVALID | PULSE_INPUT_DUTY_VALID | PULSE_INPUT_DUTY_INVALID );
#else
        *SignalStatus = PulseInputChnlStatus[PeriodInId].ChannelStatus & ( PULSE_INPUT_SIGNAL_NEVER_RECEIVED | PULSE_INPUT_MISSING_LOW | PULSE_INPUT_MISSING_HIGH | PULSE_INPUT_PERIOD_VALID | PULSE_INPUT_PERIOD_INVALID );
#endif

        Ret = E_OK;

        *ErrorStatus =  IOHWAB_E_NO_ERROR;



    }
    else
    {
        *ErrorStatus = IOHWAB_E_PULSEINPUT_ID_INVALID;
    }

    return Ret;
}


/**
* This method is used to get the Speed value
* @param PulseInputId - PulseInputId Id from application
* @param uint32 *SpeedVal - Pointer to receive the speed value
* @return Std_ReturnType E_OK-successful returning of speed value, E_NOT_OK-speed value is not updated in data pointer
*/
Std_ReturnType IoHwAb_PulseInput_GetCurrentSpeed(IoHwAb_PulseInputSignalIdType PulseInputId, uint32* SpeedVal,IoHwAb_ErrorType* ErrorStatus)
{
    uint32 PulsePeriodInMicroSec=0U, Frequency=0U;
    uint32 PulsesPerUnit = 0U;
    IoHwAb_PwmIn_PeriodId PeriodInId;
    Std_ReturnType Ret = E_NOT_OK;
    *ErrorStatus = IOHWAB_E_ERROR;

    *SpeedVal = 0U;

    if(PulseInputId < ((uint32)IOHWAB_PULSEINPUT_NUMBER_OF_SIGNALS))
    {

        /* Map the respective priodId which is configured*/
        PeriodInId = (uint32)IoHwAb_PulseInputCfg[PulseInputId].MapPeriodId;

        Ret = IoHwAb_PwmIn_GetPeriod(PeriodInId, &PulsePeriodInMicroSec);

        if((PulsePeriodInMicroSec != 0U) && (Ret == E_OK))
        {
            /* Convert period from microseconds to seconds unit and calculate the frequency with the resolution of 0.01*/
            Frequency = (((uint32)(1000000 * RESOLUTION_IN_0_POINT_01)) / PulsePeriodInMicroSec);
            PulsesPerUnit = (SpeedCalcParam[PeriodInId].Pulses_Per_Revolution * SpeedCalcParam[PeriodInId].Revolutions_Per_Unit * (SpeedCalcParam[PeriodInId].Tuning_Factor/((uint32)1000)));
            PulsesPerUnit = PulsesPerUnit / (RESOLUTION_IN_0_POINT_01); //For 0.01 resolution
            if(PulsesPerUnit != 0U)
            {
                *SpeedVal = ((Frequency * TIME_IN_SECONDS_PER_HOUR) / PulsesPerUnit);

                *ErrorStatus =  IOHWAB_E_NO_ERROR;
            }
        }
    }
    else
    {
        *ErrorStatus = IOHWAB_E_PULSEINPUT_ID_INVALID;
    }

    return Ret;
}

#define IoHwAb_STOP_SEC_CODE
#include <IoHwAb_MemMap.h>

#endif

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
Date              : 16/Apr/2018
By                : asivalin
Traceability      : RTC #1094482
Change Description: Pulse input capture state management(Initial)
-------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
Date              : 08/June/2018
By                : asivalin
Traceability      : RTC #1128591
Change Description: Duty Support, Period/Duty Validity check support & hysteresis implementation
-------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
Date              :5-Dec-2018
By                :nrajaman
Traceability      :1206553: Hyundai SP2: PIC component upgrade for ASIL compliance.
Change Description:Updated for IoHwAb_PulseInput safe implementation
-------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
Date              :21-Dec-2018
By                :nrajaman
Traceability      :1206553: Hyundai SP2: PIC component upgrade for ASIL compliance.
Change Description:PR comments updated
-------------------------------------------------------------------------------*/
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
