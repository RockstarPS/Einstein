/*=================================================================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2001. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**==================================================================================================================
**
** Name:           Ioctrlrd_dio_diagcdd
**
** Description:
**
**
**===================================================================================================================*/

#ifndef IOCTRLRD_ANALOG_DIAGCDD_C
#define IOCTRLRD_ANALOG_DIAGCDD_C

/*====================================================================================================================
**                 I N C L U D E   F I L E S
**===================================================================================================================*/

#include "Ioctrlrd_analog_diagcdd_cfg.h"
#include "Ioctrlrd_analog_diagcdd.h"
#include "Mgrdiagcdd_cfg.h"
#include "Mgrdiagcdd.h"

#ifdef IOCTRLRD_FUEL_INPUT_READING_THREE_POINT_CALIB

/* Enable this header file as per need.
 *
 * #include "AssertLib.h"
 */
#include <arm_ghs.h>
#endif

#ifdef IOCONTOLRD_ADC_READ_SAFE_ENABLE
#include <Adc.h>
#endif

/*====================================================================================================================
**   I N T E R N A L   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/

/*=====================================================================================================================
**  T Y P E    D E C L A R A T I O N S
**====================================================================================================================*/

#ifdef IOCONTOLRD_ADC_READ_SAFE_ENABLE
static uint16 l_Meet_CIoHwAbSafe_AIn_Voltage[Meet_IoHwAbSafe_AIn_MaxChannelsInGroup];
#endif

#ifdef IOCTRLRD_ANALOG_DIAG
static uint8 Manuf_ADC_Finished[MANUF_ANA_NUM_CHANNELS];
static uint16 Manuf_ADC_Count[MANUF_ANA_NUM_CHANNELS];
static uint16 Manuf_ADC_NumSamples[MANUF_ANA_NUM_CHANNELS];
static uint16 Manuf_ADC_Result[MANUF_ANA_NUM_CHANNELS];
static uint8 Manuf_ADC_StartFlag[MANUF_ANA_NUM_CHANNELS];
static uint16 Manuf_ADC_Array[MANUF_ANA_NUM_CHANNELS][MANUF_ANA_MAX_NUM_SAMPLES];
static uint16 Manuf_CollectedResult[MANUF_ANA_NUM_CHANNELS];
static uint16 Manuf_CollectedArray[MANUF_ANA_NUM_CHANNELS][MANUF_ANA_MAX_NUM_SAMPLES];
/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/

/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/
static uint16 Manuf_Cmp_ADCReading(uint16 channel_id);
#ifdef MANUF_ALL_CHANNEL_SUPPORT_REQUIRED
static uint8 Manuf_ANA_GetResAllChannels(uint8 *Data, uint8 *NegRespCode);
static uint8 Manuf_ANA_StartAllChannels(uint8 No_of_Sample, uint8 *Data, uint8 *NegRespCode);
static uint8 Manuf_ANA_StopAllChannels(uint8 *Data, uint8 *NegRespCode);
#endif
static uint8 Manuf_ADCMeasurement(uint8 cmd_type, uint8 ch_index, uint16 no_samples, uint16 *outbuffer);
#endif
#if defined(IOCTRLRD_ANALOG_DIAG) || defined(IOCTRLRD_ANALOG_DIAG_BY_UNIT)
static void Manuf_BubbleSort(uint16 list[], uint16 n);
#endif

#ifdef IOCTRLRD_ANALOG_DIAG_BY_UNIT
static uint8 Ioctrlrd_ADC_Finished_by_unit[IOCTRLRD_ANA_NUM_CHANNELS_UNIT];
static uint16 Ioctrlrd_ADC_Count_by_unit[IOCTRLRD_ANA_NUM_CHANNELS_UNIT];
static uint16 Ioctrlrd_ADC_NumSamples_by_unit[IOCTRLRD_ANA_NUM_CHANNELS_UNIT];
static uint16 Ioctrlrd_ADC_Result_by_unit[IOCTRLRD_ANA_NUM_CHANNELS_UNIT];
static uint8 Ioctrlrd_ADC_StartFlag_by_unit[IOCTRLRD_ANA_NUM_CHANNELS_UNIT];
static uint16 Ioctrlrd_ADC_Array_by_unit[IOCTRLRD_ANA_NUM_CHANNELS_UNIT][IOCTRLRD_MAX_NO_OF_SAMPLES_BY_UNIT];
static uint16 Ioctrlrd_CollectedResult_by_unit[IOCTRLRD_ANA_NUM_CHANNELS_UNIT];
static uint16 Ioctrlrd_CollectedArray_by_unit[IOCTRLRD_ANA_NUM_CHANNELS_UNIT][IOCTRLRD_MAX_NO_OF_SAMPLES_BY_UNIT];

static uint16 Ioctrlrd_Cmp_ADCReading_by_unit(uint16 channel_id);
static uint8 Ioctrlrd_ADCMeasurement_by_unit(uint8 cmd_type, uint8 ch_index, uint16 no_samples, uint16 *outbuffer);

#endif

#ifdef IOCTRLRD_FUEL_INPUT_READING_BY_UNIT_WCalib
static sint32 Ioctrlrd_analog_ReadByUnit_StateMachine(uint32 ADC_Val, uint8 index, uint8 *status);

#ifndef IOCTRLRD_FUEL_INPUT_READING_THREE_POINT_CALIB
#if 0
static uint8 Ioctrlrd_analog_Fuel_level_input_cal = IOCTRLRD_FUEL_INPUT_BY_UNIT_WITH_CALIB;// Coverity fix
#endif
static uint8 Ioctrlrd_analog_fuel_level_status = IOCTRLRD_NFUEL_CAL_CMPLT;

static uint8 Ioctrlrd_Analog_Finished_unit_WCalib[IOCTRLRD_ANA_NUM_CHANNELS_UNIT_WCalib];
#if 0
static uint16  Ioctrlrd_Analog_Count_unit_WCalib[IOCTRLRD_ANA_NUM_CHANNELS_UNIT_WCalib]; // Coverity fix
static uint16 Ioctrlrd_Analog_NumSamples_unit_WCalib[IOCTRLRD_ANA_NUM_CHANNELS_UNIT_WCalib] ; // Coverity fix
#endif
static uint16 Ioctrlrd_Analog_Result_unit_WCalib[IOCTRLRD_ANA_NUM_CHANNELS_UNIT_WCalib];
#if 0
static uint8  Ioctrlrd_Analog_StartFlag_unit_WCalib[IOCTRLRD_ANA_NUM_CHANNELS_UNIT_WCalib] ;   // Coverity fix
static uint16 Ioctrlrd_Analog_CollectedResult_unit_WCalib[IOCTRLRD_ANA_NUM_CHANNELS_UNIT_WCalib]; // Coverity fix
#endif
static uint32 Ioctrlrd_analog_nfuel = IOCTRLRD_ANALOG_CLR_0_WCalib;

static uint16 Ioctrlrd_analog_Cmp_ADCReading_by_unit_WCalib(uint16 channel_id);
static uint8 Ioctrlrd_ADCMeasurement_UnitWC(uint8 cmd_type, uint8 ch_index, uint16 no_samples, uint16 *outbuffer);

#else

static uint8 Ioctrlrd_Analog_Finished_unit_Three_Point_Calib[IOCTRLRD_ANA_NUM_CHANNELS_THREE_POINT_CALIB];
static uint16 Ioctrlrd_Analog_Count_unit_Three_Point_Calib[IOCTRLRD_ANA_NUM_CHANNELS_THREE_POINT_CALIB];
static uint8 Ioctrlrd_Analog_NumSamples_unit_Three_Point_Calib[IOCTRLRD_ANA_NUM_CHANNELS_THREE_POINT_CALIB];
static uint32 Ioctrlrd_Analog_Result_unit_Three_Point_Calib[IOCTRLRD_ANA_NUM_CHANNELS_THREE_POINT_CALIB];
static uint8 Ioctrlrd_Analog_StartFlag_unit_Three_Point_Calib[IOCTRLRD_ANA_NUM_CHANNELS_THREE_POINT_CALIB];
static uint32 Ioctrlrd_Analog_Array_unit_Three_Point_Calib[IOCTRLRD_ANA_NUM_CHANNELS_THREE_POINT_CALIB];
static uint8 Ioctrlrd_Analog_TimeOut_Counter_Three_Point_Calib[IOCTRLRD_ANA_NUM_CHANNELS_THREE_POINT_CALIB];
static uint8 Ioctrlrd_ADCMeasurement_Three_Point_Calib(uint8 cmd_type, uint8 ch_index, uint16 no_samples, uint32 *outbuffer, uint32 size);
static uint16 Ioctrlrd_analog_Cmp_ADCReading_Three_Point_Calib(uint16 channel_id);
static Std_ReturnType Ioctrlrd_LIB_Math_InterpolateLinearU32(const uint32 *const pu32XPointsP,
                                                             const uint32 *const pu32ZPointsP,
                                                             const uint32 *const pu32YPointsP,
                                                             const uint32 u32CountP,
                                                             const uint32 u32XValueP,
                                                             uint32 *const pu32YValueP);
static uint32 Ioctrlrd_InterpolateU32(const uint32 u32XeP,
                                      const uint32 u32Z1P,
                                      const uint32 u32Z2P,
                                      const uint32 u32X1P,
                                      const uint32 u32Y1P,
                                      const uint32 u32X2P,
                                      const uint32 u32Y2P,
                                      boolean *const bpStateP);

static uint32 Ioctrlrd_ExtrapolateU32(const uint32 *const pu32XPointP,
                                      const uint32 *const pu32ZPointP,
                                      const uint32 *const pu32YPointP,
                                      const uint32 u32CountP,
                                      const uint32 u32XeP,
                                      boolean *const bpStateP);
#endif
#endif

#ifdef IOCTRlRD_ALALOGIC_SIGNAL_CTRL
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_analog_diag_AdcInputReading_RCStop
**
** Visibility       :  Public
**
** Description      :  31 Routine control for get ADC value
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Routine Type , routine output , error code
**
** Outputs          :  Std_ReturnType
**
** Critical Section : Yes
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_analog_diag_InternalAnalogicSignalControl_STA(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 PWM_Index = 0U;
    uint16 u16Scale_duty;
    #if ((BCDMANIPUTATION_ENABLE_ANALOG_DIAG == 0x01) || (DECIMALMANIPUTATION_ENABLE_ANALOG_DIAG == 0x01))
    uint16 u16Dimm = 0U;
    uint16 u16Dimm_temp;
    #endif
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        #if ((BCDMANIPUTATION_ENABLE_ANALOG_DIAG == 0x01) || (DECIMALMANIPUTATION_ENABLE_ANALOG_DIAG == 0x01))
        PWM_Index = Data[MEET_INDEX_ZERO];
        u16Dimm = Data[MEET_INDEX_ONE];      // MSB Byte of the dimming value from CAN message
        u16Dimm_temp = Data[MEET_INDEX_TWO]; // 2 bytes PWM value is 0 to 1000. 1000=100%
        #endif

        #if (BCDMANIPUTATION_ENABLE_ANALOG_DIAG == 0x01)
        u16Scale_duty = DutyManipulateWithBCD(u16Dimm, u16Dimm_temp);
        #endif
        #if (DECIMALMANIPUTATION_ENABLE_ANALOG_DIAG == 0x01)
        u16Scale_duty = DutyManipulateWitDecimal(u16Dimm, u16Dimm_temp);

        #endif
        #ifdef DUTY_COTROL_WITH_ONE_CHANNEL
        u16Scale_duty = Data[MEET_INDEX_ZERO];
        Meet_DutyControlConfig[PWM_Index].DutyControlFunction(u16Scale_duty);
        ret = E_OK;
        #else
        if (((Data[MEET_INDEX_ZERO] <= MEET_MAX_DUTY_CHANNELS) && (u16Scale_duty <= MEET_MAX_DUTY_RESOL_VALUE)))
        {

            if (PWM_Index != 0U) // check for condition
            {
                PWM_Index--; // Array index starts from 0
                Meet_DutyControlConfig[PWM_Index].DutyControlFunction(u16Scale_duty);
                ret = E_OK;
            }
            else
            {
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }
        }
        else
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
        #endif
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_analog_diag_AdcInputReading_RCStop
**
** Visibility       :  Public
**
** Description      :  31 Routine control for get ADC value
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Routine Type , routine output , error code
**
** Outputs          :  Std_ReturnType
**
** Critical Section : Yes
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_analog_diag_InternalAnalogicSignalControl_RCTE(uint8 *ErrorCode)
{

    Std_ReturnType ret = E_NOT_OK;
    uint8 PWM_Index = 0U;

    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = E_OK;
        for (PWM_Index = 0U; PWM_Index < MEET_MAX_DUTY_CHANNELS; PWM_Index++)
        {
            Meet_DutyControlConfig[PWM_Index].DutyControlFunction(0U);
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
        ret = E_NOT_OK;
    }
    return ret;
}

#endif

#ifdef IOCTRLRD_ANALOG_DIAG

/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_analog_diag_AdcInputReading_RCStart
**
** Visibility       :  Public
**
** Description      :  31 service analog input reading START
**
**
** Invocation       :	MeetMgr.diagcdd
**
** Inputs           :  DcmDspStartRoutineIn_AI , Number of samples , output ,Error code
**
** Outputs          :  DcmDspStartRoutineOutSignal
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_analog_diag_AdcInputReading_RCStart(uint8 DcmDspStartRoutineIn_AI, uint8 DcmDspStartRoutineIn_NOS, uint8 *DcmDspStartRoutineOutSignal, uint8 *ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    uint8 ResultL = MANUF_FAIL;
    uint8 Index = 0U;
    uint16 num_samples = 0U;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;

    if (MfgModeActive == (uint8)MEET_SESSION)
    {
        Index = DcmDspStartRoutineIn_AI;

        #ifdef MANUF_ALL_CHANNEL_SUPPORT_REQUIRED
        if ((MANUF_MAX_NO_OF_SAMPLES >= DcmDspStartRoutineIn_NOS) && (IOCTRLRD_ZERO_SAMPLE != DcmDspStartRoutineIn_NOS) && ((MANUF_ANA_ALL_CHANNELS == Index) || ((MANUF_ANA_NUM_CHANNELS >= Index) && (0U < Index))))
        #else
        if ((MANUF_MAX_NO_OF_SAMPLES >= DcmDspStartRoutineIn_NOS) && (IOCTRLRD_ZERO_SAMPLE != DcmDspStartRoutineIn_NOS) && ((MANUF_ANA_NUM_CHANNELS >= Index) && (0U < Index)))
        #endif
        {
            #ifndef MANUF_ALL_CHANNEL_SUPPORT_REQUIRED
            if (Manuf_ANAMap[Index - 1U] == (MANUF_ANA_ALL_CHANNELS - 1U))
            {
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
            else
            #else
            if (MANUF_ANA_ALL_CHANNELS == Index)
            {
                #if 0 
                DcmDspStartRoutineOutSignal[DATA_BYTE_0] = DcmDspStartRoutineIn_NOS; 			//coverity-misra fix
                #endif
                ResultL = Manuf_ANA_StartAllChannels(DcmDspStartRoutineIn_NOS, DcmDspStartRoutineOutSignal, ErrorCode); // All channels selected  //Manuf_KK
            }
            else
            #endif
            {
                Index--;
                num_samples = DcmDspStartRoutineIn_NOS;

                if ((uint8)IOCTRLRD_RC_IN_PROGRESS == Manuf_RoutineControlStatus[Index].ADCInputReading)
                {
                    ResultL = MANUF_FAIL;
                    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                    Manuf_RoutineControlStatus[Index].ADCInputReading = (uint8)IOCTRLRD_RC_FINISHED_NOK;
                    DcmDspStartRoutineOutSignal[DATA_BYTE_0] = (uint8)IOCTRLRD_RC_FINISHED_NOK;
                }
                else
                {
                    ResultL = Manuf_ADCMeasurement(MANUF_ADCCMD_START, Index, num_samples, (uint16)0);
                    Manuf_RoutineControlStatus[Index].ADCInputReading = (uint8)IOCTRLRD_RC_IN_PROGRESS;
                    DcmDspStartRoutineOutSignal[DATA_BYTE_0] = (uint8)IOCTRLRD_RC_IN_PROGRESS;
                }
            }
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return (ResultL);
}

#ifdef MANUF_ALL_CHANNEL_SUPPORT_REQUIRED
/*=====================================================================================================================
**
** Function Name    :  Manuf_ANA_StartAllChannels
**
** Visibility       :  Public
**
** Description      :  Used to trigger all analog channel conversion
**
**
** Invocation       :	Ioctrlrd_analog_diag_AdcInputReading_RCStart
**
** Inputs           :   Number of samples , data ,Error code
**
** Outputs          :  Status
**
** Critical Section : No
**
**====================================================================================================================*/
static uint8 Manuf_ANA_StartAllChannels(uint8 No_of_Sample, uint8 *Data, uint8 *NegRespCode)
{
    uint8 ResultL = MANUF_OK;
    uint16 num_samples = 0U;
    uint8 Index = 0U;

    for (Index = 0U; Index < MANUF_ANA_NUM_CHANNELS; Index++)
    {
        if ((uint8)IOCTRLRD_RC_IN_PROGRESS == Manuf_RoutineControlStatus[Index].ADCInputReading)
        {
            ResultL = MANUF_FAIL;
            Manuf_RoutineControlStatus[Index].ADCInputReading = (uint8)IOCTRLRD_RC_FINISHED_NOK;
            break; // Break for loop
        }
    }

    if (MANUF_OK == ResultL)
    {
        num_samples = No_of_Sample;

        for (Index = 0U; Index < MANUF_ANA_NUM_CHANNELS; Index++)
        {
            if (Manuf_ANAMap[Index] != ANA_UNUSED_CHANNEL_ID)
            {
                ResultL = Manuf_ADCMeasurement(MANUF_ADCCMD_START, Index, num_samples, (uint16)0); // cmd type, channel id, num_samples, response buffer(not used)
                Manuf_RoutineControlStatus[Index].ADCInputReading = (uint8)IOCTRLRD_RC_IN_PROGRESS;
            }
        }

        Data[DATA_BYTE_0] = (uint8)IOCTRLRD_RC_IN_PROGRESS;
        *NegRespCode = MANUF_OK;
    }
    else
    {
        Manuf_RoutineControlStatus[Index].ADCInputReading = (uint8)IOCTRLRD_RC_FINISHED_NOK;
        Data[DATA_BYTE_0] = (uint8)IOCTRLRD_RC_FINISHED_NOK;
        *NegRespCode = DCM_E_CONDITIONSNOTCORRECT;
    }

    return (ResultL);
}
/*=====================================================================================================================
**
** Function Name    :  Manuf_ANA_GetResAllChannels
**
** Visibility       :  Private
**
** Description      :  Used to Get ANA Results reading for All Channels
**
** Invocation       :  Ioctrlrd_analog_diag_AdcInputReading_RCStatus
**
** Inputs           :  data ,Error code
**
** Outputs          :  Status : MANUF_OK   - operation successful
**                              MANUF_FAIL - operation failed
** Critical Section :  No
**
**====================================================================================================================*/

static uint8 Manuf_ANA_GetResAllChannels(uint8 *Data, uint8 *NegRespCode)
{
    uint8 ResultL = MANUF_FAIL; // U8_t ResultL = MANUF_OK;
    uint8 Index;
    uint8 flag_not_active = MANUF_FALSE;
    uint16 tempBuffer;
    #if (ADC_RESULTION_FACTOR == 100)
    uint32 tempBuffer_32;
    #endif

    for (Index = 0U; Index < MANUF_ANA_NUM_CHANNELS; Index++)
    {
        if (((uint8)IOCTRLRD_RC_FINISHED_OK == Manuf_RoutineControlStatus[Index].ADCInputReading) || ((uint8)IOCTRLRD_RC_NOT_ACTIVE == Manuf_RoutineControlStatus[Index].ADCInputReading))
        {
            flag_not_active = MANUF_TRUE;
        }
    }

    if (flag_not_active == MANUF_TRUE)
    {
        Data[DATA_BYTE_0] = (uint8)IOCTRLRD_RC_NOT_ACTIVE;
        *NegRespCode = MANUF_OK;
        ResultL = MANUF_OK; // TBD
    }
    else
    {
        for (Index = 0U; Index < MANUF_ANA_NUM_CHANNELS; Index++)
        {
            ResultL = Manuf_ADCMeasurement(MANUF_ADCCMD_GETRESULTS, Index, (uint16)0, &tempBuffer); // cmd type, channel id, num_samples, response buffer

            if (ResultL == MANUF_WAIT)
            {
                ResultL = MANUF_OK;
                *NegRespCode = MANUF_OK;
                Data[DATA_BYTE_0] = (uint8)IOCTRLRD_RC_IN_PROGRESS;
                break;
            }
            else
            {
                Data[DATA_BYTE_0] = (uint8)IOCTRLRD_RC_FINISHED_OK;
                Manuf_RoutineControlStatus[Index].ADCInputReading = (uint8)IOCTRLRD_RC_FINISHED_OK;
                Data[DATA_BYTE_1] = (uint8)255;

// 255 ALL Channels
                #if (ADC_RESULTION_FACTOR == 100U)
                tempBuffer_32 = ((uint32)tempBuffer * ADC_RESULTION_FACTOR);
                Data[(Index * 4U) + DATA_BYTE_2] = (uint8)((tempBuffer_32 >> 24UL) & 0xFFUL); // MSbyte of ADC value
                Data[(Index * 4U) + DATA_BYTE_3] = (uint8)((tempBuffer_32 >> 16UL) & 0xFFUL); // MSbyte of ADC value
                Data[(Index * 4U) + DATA_BYTE_4] = (uint8)((tempBuffer_32 >> 8UL) & 0xFFUL);  // MSbyte of ADC value
                Data[(Index * 4U) + DATA_BYTE_5] = (uint8)(tempBuffer_32 & 0xFFUL);           // LSbyte of ADC value
                #else
                Data[((Index * 2U) + DATA_BYTE_2)] = (uint8)((tempBuffer >> 8U) & 0xFFU); // MSbyte of ADC value
                Data[((Index * 2U) + DATA_BYTE_3)] = (uint8)(tempBuffer & 0xFFU);         // LSbyte of ADC value
                #endif

                *NegRespCode = MANUF_OK;
            }
        }
    }
    return (ResultL);
}
/*=====================================================================================================================
**
** Function Name    :  Manuf_ANA_StopAllChannels
**
** Visibility       :  Private
**
** Description      :  Used to Stop ANA reading for All Channels
**
**
** Invocation       :	Ioctrlrd_analog_diag_AdcInputReading_RCStop
**
** Inputs           :   data ,Error code,data length
**
** Outputs          :  Status :MANUF_OK - operation successful
**                             MANUF_FAIL - operation failed
** Critical Section : No
**
**====================================================================================================================*/
static uint8 Manuf_ANA_StopAllChannels(uint8 *Data, uint8 *NegRespCode)
{
    uint8 ResultL = MANUF_FAIL;
    uint8 Index;

    for (Index = 0U; Index < MANUF_ANA_NUM_CHANNELS; Index++)
    {
        ResultL = Manuf_ADCMeasurement(MANUF_ADCCMD_STOP, Index, (uint16)0, (uint16)0); // cmd type, channel id, num_samples(not used), response buffer(not used)
        *NegRespCode = MANUF_OK;
        Data[DATA_BYTE_0] = (uint8)IOCTRLRD_RC_STOPPED; // GMSR As per GMSR,status updated as IOCTRLRD_RC_STOPPED instead of IOCTRLRD_RC_FINISHED_OK;
        Manuf_RoutineControlStatus[Index].ADCInputReading = (uint8)IOCTRLRD_RC_FINISHED_OK;
    }

    return (ResultL);
}
#endif
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_analog_diag_AdcInputReading_RCStatus
**
** Visibility       :  Public
**
** Description      :  31 service analog input reading
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  DcmDspStartRoutineIn_AI , Number of samples , output ,Error code
**
** Outputs          :  DcmDspStartRoutineOutSignal
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_analog_diag_AdcInputReading_RCStatus(uint8 DcmDspStartRoutineIn_AI, uint8 *DcmDspStartRoutineOutSignal, uint8 *ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    uint8 ResultL = MANUF_FAIL;
    uint8 Index = 0U;
    uint8 MfgModeActive = 0U;
    uint16 tempBuffer = 0U;
    #if ADC_RESULTION_FACTOR > 1U
    uint32 tempBuffer_32 = 0U;
    #endif

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        Index = DcmDspStartRoutineIn_AI;
        DcmDspStartRoutineOutSignal[DATA_BYTE_0] = DCM_E_CONDITIONSNOTCORRECT;
        #ifdef MANUF_ALL_CHANNEL_SUPPORT_REQUIRED
        if (MANUF_ANA_ALL_CHANNELS == Index)
        {
            ResultL = Manuf_ANA_GetResAllChannels(DcmDspStartRoutineOutSignal, ErrorCode);
        }
        else
        #endif
        {
            if ((Index > 0U) && (Index <= MANUF_ANA_NUM_CHANNELS))
            {
                Index--;

                if (((uint8)IOCTRLRD_RC_FINISHED_OK == Manuf_RoutineControlStatus[Index].ADCInputReading) || ((uint8)IOCTRLRD_RC_NOT_ACTIVE == Manuf_RoutineControlStatus[Index].ADCInputReading))
                {
                    DcmDspStartRoutineOutSignal[DATA_BYTE_0] = (uint8)IOCTRLRD_RC_NOT_ACTIVE;
                    ResultL = MANUF_OK;
                }
                else
                {
                    ResultL = Manuf_ADCMeasurement(MANUF_ADCCMD_GETRESULTS, Index, (uint16)0, &tempBuffer); // cmd type, channel id, num_samples, response buffer

                    if (ResultL == MANUF_WAIT)
                    {
                        DcmDspStartRoutineOutSignal[DATA_BYTE_0] = (uint8)IOCTRLRD_RC_IN_PROGRESS;
                        ResultL = MANUF_OK;
                    }
                    else
                    {
                        DcmDspStartRoutineOutSignal[DATA_BYTE_0] = (uint8)IOCTRLRD_RC_FINISHED_OK; // Routine Status
                        Manuf_RoutineControlStatus[Index].ADCInputReading = (uint8)IOCTRLRD_RC_FINISHED_OK;
                        DcmDspStartRoutineOutSignal[DATA_BYTE_1] = (uint8)(Index + 1U); // Channel Number

                        #if ADC_RESULTION_FACTOR > 1
                        tempBuffer_32 = ((uint32)tempBuffer * ADC_RESULTION_FACTOR);
                        DcmDspStartRoutineOutSignal[DATA_BYTE_2] = (uint8)((tempBuffer_32 >> 24U) & 0xFFU); // MSbyte of ADC value
                        DcmDspStartRoutineOutSignal[DATA_BYTE_3] = (uint8)((tempBuffer_32 >> 16U) & 0xFFU); // MSbyte of ADC value
                        DcmDspStartRoutineOutSignal[DATA_BYTE_4] = (uint8)((tempBuffer_32 >> 8U) & 0xFFU);  // MSbyte of ADC value
                        DcmDspStartRoutineOutSignal[DATA_BYTE_5] = (uint8)(tempBuffer_32 & 0xFFU);          // LSbyte of ADC value
                        #else
                        DcmDspStartRoutineOutSignal[DATA_BYTE_2] = (uint8)((tempBuffer >> 8U) & 0xFFU); // MSbyte of ADC value
                        DcmDspStartRoutineOutSignal[DATA_BYTE_3] = (uint8)(tempBuffer & 0xFFU);         // LSbyte of ADC value
                        #endif
                    }
                }
            }
            else
            {
                /*Index out of range*/
                ResultL = MANUF_FAIL;
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ResultL;
}

/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_analog_diag_AdcInputReading_RCStop
**
** Visibility       :  Public
**
** Description      :  31 service analog input reading STOP
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  DcmDspStartRoutineIn_AI , Number of samples , output ,Error code
**
** Outputs          :  DcmDspStartRoutineOutSignal
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_analog_diag_AdcInputReading_RCStop(uint8 DcmDspStartRoutineIn_AI, uint8 *DcmDspStartRoutineOutSignal, uint8 *ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    UNUSED(DcmDspStartRoutineOutSignal);
    uint8 ResultL = MANUF_FAIL;
    uint8 Index = 0U;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        Index = DcmDspStartRoutineIn_AI;
        DcmDspStartRoutineOutSignal[DATA_BYTE_0] = DCM_E_CONDITIONSNOTCORRECT;
        #ifdef MANUF_ALL_CHANNEL_SUPPORT_REQUIRED
        if (MANUF_ANA_ALL_CHANNELS == Index)
        {
            ResultL = Manuf_ANA_StopAllChannels(DcmDspStartRoutineOutSignal, ErrorCode);
        }
        else
        #endif
        {
            if ((Index > 0U) && (Index <= MANUF_ANA_NUM_CHANNELS))
            {
                Index--;
                ResultL = Manuf_ADCMeasurement(MANUF_ADCCMD_STOP, Index, (uint16)0U, (uint16)0U); // cmd type, channel id, num_Samples(not used), response buffer(not used)
                DcmDspStartRoutineOutSignal[DATA_BYTE_0] = (uint8)IOCTRLRD_RC_STOPPED;            // A sper GMSR stop status is updated as IOCTRLRD_RC_STOPPED instead of IOCTRLRD_RC_FINISHED_OK;
                Manuf_RoutineControlStatus[Index].ADCInputReading = (uint8)IOCTRLRD_RC_FINISHED_OK;
            }
            else
            {
                /*Index out of range*/
                ResultL = MANUF_FAIL;
            }
        }
    }
    else
    {
        DcmDspStartRoutineOutSignal[DATA_BYTE_0] = INVALID_MODE;
    }

    return ResultL;
}
//----------------------------------------------------------------------------------------------------------------------
// DESCRIPTION:          Used to control ADC
//
// PARAMETERS:          cmd_type - Start, Stop or GetResults
//						ch_index - ADC channel index
//                      no_samples - Number of ADC Samples with sampling frequency of 5msec
//						outbuffer  - The output buffer
//
// RETURN VALUE:        Std_ReturnType: MANUF_OK - operation successful
//                                      MANUF_FAIL - operation failed
//										MANUF_WAIT - operation is waiting, can't be done now
//
// DESIGN INFORMATION:  None
//----------------------------------------------------------------------------------------------------------------------
static uint8 Manuf_ADCMeasurement(uint8 cmd_type, uint8 ch_index, uint16 no_samples, uint16 *outbuffer)
{
    uint8 ResultL = MANUF_OK;

    if (ch_index < MANUF_ANA_NUM_CHANNELS)
    {
        switch (cmd_type)
        {
        case MANUF_ADCCMD_START:
        {

            Manuf_ADC_Finished[ch_index] = MANUF_FALSE;
            Manuf_ADC_Count[ch_index] = 0U; // array index and up counter up to no_samples
            Manuf_ADC_NumSamples[ch_index] = no_samples;
            Manuf_ADC_Result[ch_index] = 0U;
            Manuf_ADC_StartFlag[ch_index] = MANUF_TRUE;
            break;
        }
        case MANUF_ADCCMD_STOP:
        {
            Manuf_ADC_StartFlag[ch_index] = MANUF_FALSE;
            Manuf_ADC_Finished[ch_index] = MANUF_FALSE;
            Manuf_ADC_Result[ch_index] = 0U;
            break;
        }
        case MANUF_ADCCMD_GETRESULTS:
        {
            if (Manuf_ADC_Finished[ch_index] == MANUF_TRUE)
            {
                *outbuffer = Manuf_ADC_Result[ch_index];
                ResultL = MANUF_OK;
            }
            else
            {
                ResultL = MANUF_WAIT;
            }
            break;
        }
        default:
        {
            ResultL = MANUF_FAIL;
            break;
        }
        }
    }
    else
    {
        /*Index out of range*/
        ResultL = MANUF_FAIL;
    }

    return ResultL;
}

//----------------------------------------------------------------------------------------------------------------------
// DESCRIPTION:         Manuf_Cmp_ADCReading
//
// PARAMETERS:
//
// RETURN VALUE:
//
// DESIGN INFORMATION:  None
//----------------------------------------------------------------------------------------------------------------------
static uint16 Manuf_Cmp_ADCReading(uint16 channel_id)
{
    uint32 ADC_Val = 0U;

    if (channel_id < MANUF_ANA_NUM_CHANNELS)
    {
        MEET_Direct_ANAMap_fun[channel_id].ADC_ReadFunction(&ADC_Val);
    }

    return ((uint16)ADC_Val);
}
#endif

#ifdef IOCTRLRD_ANALOG_DIAG
//----------------------------------------------------------------------------------------------------------------------
// DESCRIPTION:         Cyclic function called every 5ms
//
// PARAMETERS:          None
//
// RETURN VALUE:        None
//
// DESIGN INFORMATION:  None
//----------------------------------------------------------------------------------------------------------------------
void Manuf_ANA_AnalogValue_Update(void)
{
    #if defined(IOCTRLRD_ANALOG_DIAG) || defined(IOCTRLRD_ANALOG_DIAG_BY_UNIT) // coverity fix new CID : 5637791(Macro introduced for "Index")
    uint8 Index;                                                           // coverity fix new CID : 1827604(Index=0U -> Index)
    #endif

    #ifdef IOCTRLRD_FUEL_INPUT_READING_THREE_POINT_CALIB
    uint8 status;
    #endif

    #ifdef IOCTRLRD_ANALOG_DIAG
    // ADC Input Reading
    for (Index = 0U; Index < MANUF_ANA_NUM_CHANNELS; Index++)
    {
        if ((Manuf_ADC_StartFlag[Index] == MANUF_TRUE) && (Manuf_ADC_Count[Index] < MANUF_ANA_MAX_NUM_SAMPLES))
        {
            Manuf_ADC_Array[Index][Manuf_ADC_Count[Index]] = Manuf_Cmp_ADCReading(Manuf_ANAMap[Index]);
            Manuf_ADC_Count[Index]++;

            if ((Manuf_ADC_Count[Index] >= SAMPLE_COLLECTION) && (Manuf_CollectedResult[Index] < MANUF_ANA_MAX_NUM_SAMPLES)) // Manuf_Partial_ADC_NumSamples[Index]) //Manuf_ADC_NumSamples[Index])
            {
                Manuf_ADC_Count[Index] = 0U;
                Manuf_BubbleSort(Manuf_ADC_Array[Index], SAMPLE_COLLECTION); // Manuf_Partial_ADC_NumSamples[Index]);
                Manuf_CollectedArray[Index][Manuf_CollectedResult[Index]] = Manuf_ADC_Array[Index][(SAMPLE_COLLECTION / 2U) + 1U];
                Manuf_CollectedResult[Index]++;

                if (Manuf_ADC_NumSamples[Index] == 1U)
                {
                    Manuf_CollectedResult[Index] = 0U;
                    Manuf_ADC_Result[Index] = (uint16)Manuf_CollectedArray[Index][0U];
                    Manuf_ADC_StartFlag[Index] = MANUF_FALSE;
                    Manuf_ADC_Finished[Index] = MANUF_TRUE;
                }
                else if (Manuf_CollectedResult[Index] >= Manuf_ADC_NumSamples[Index])
                {
                    Manuf_CollectedResult[Index] = 0U;
                    Manuf_BubbleSort(Manuf_CollectedArray[Index], Manuf_ADC_NumSamples[Index]);

                    if (Manuf_ADC_NumSamples[Index] == 2U)
                    {
                        Manuf_ADC_Result[Index] = (uint16)Manuf_CollectedArray[Index][((Manuf_ADC_NumSamples[Index] / 2U) + 1U) - 1U];
                    }
                    else
                    {
                        Manuf_ADC_Result[Index] = (uint16)Manuf_CollectedArray[Index][(Manuf_ADC_NumSamples[Index] / 2U) + 1U];
                    }

                    Manuf_ADC_StartFlag[Index] = MANUF_FALSE;
                    Manuf_ADC_Finished[Index] = MANUF_TRUE;
                }
                else
                {
                    ; // coverity
                }
            }
        }
    }
    #endif

    #ifdef IOCTRLRD_ANALOG_DIAG_BY_UNIT
    // ADC input reading by unit
    for (Index = 0U; Index < IOCTRLRD_ANA_NUM_CHANNELS_UNIT; Index++)
    {
        if ((Ioctrlrd_ADC_StartFlag_by_unit[Index] == MANUF_TRUE) && (Ioctrlrd_ADC_Count_by_unit[Index] < IOCTRLRD_MAX_NO_OF_SAMPLES_BY_UNIT))
        {
            Ioctrlrd_ADC_Array_by_unit[Index][Ioctrlrd_ADC_Count_by_unit[Index]] = Ioctrlrd_Cmp_ADCReading_by_unit(Ioctrlrd_ANAMap_BY_UNIT[Index]);
            Ioctrlrd_ADC_Count_by_unit[Index]++;

            if ((Ioctrlrd_ADC_Count_by_unit[Index] >= SAMPLE_COLLECTION) && (Ioctrlrd_CollectedResult_by_unit[Index] < IOCTRLRD_MAX_NO_OF_SAMPLES_BY_UNIT))
            {
                Ioctrlrd_ADC_Count_by_unit[Index] = 0U;
                Manuf_BubbleSort(Ioctrlrd_ADC_Array_by_unit[Index], SAMPLE_COLLECTION);
                Ioctrlrd_CollectedArray_by_unit[Index][Ioctrlrd_CollectedResult_by_unit[Index]] = (uint16)Ioctrlrd_ADC_Array_by_unit[Index][(SAMPLE_COLLECTION / 2U) + 1U];
                Ioctrlrd_CollectedResult_by_unit[Index]++;

                if (Ioctrlrd_ADC_NumSamples_by_unit[Index] == 1U)
                {
                    Ioctrlrd_CollectedResult_by_unit[Index] = 0U;
                    Ioctrlrd_ADC_Result_by_unit[Index] = (uint16)Ioctrlrd_CollectedArray_by_unit[Index][0U];
                    Ioctrlrd_ADC_StartFlag_by_unit[Index] = MANUF_FALSE;
                    Ioctrlrd_ADC_Finished_by_unit[Index] = MANUF_TRUE;
                }
                else if (Ioctrlrd_CollectedResult_by_unit[Index] >= Ioctrlrd_ADC_NumSamples_by_unit[Index])
                {
                    Ioctrlrd_CollectedResult_by_unit[Index] = 0U;
                    Manuf_BubbleSort(Ioctrlrd_CollectedArray_by_unit[Index], Ioctrlrd_ADC_NumSamples_by_unit[Index]);

                    if (Ioctrlrd_ADC_NumSamples_by_unit[Index] == 2U)
                    {
                        Ioctrlrd_ADC_Result_by_unit[Index] = (uint16)Ioctrlrd_CollectedArray_by_unit[Index][((Ioctrlrd_ADC_NumSamples_by_unit[Index] / 2U) + 1U) - 1U];
                    }
                    else
                    {
                        Ioctrlrd_ADC_Result_by_unit[Index] = (uint16)Ioctrlrd_CollectedArray_by_unit[Index][(Ioctrlrd_ADC_NumSamples_by_unit[Index] / 2U) + 1U];
                    }

                    Ioctrlrd_ADC_StartFlag_by_unit[Index] = MANUF_FALSE;
                    Ioctrlrd_ADC_Finished_by_unit[Index] = MANUF_TRUE;
                }
                else
                {
                    /* no action */
                }
            }
        }
    }
    #endif
    #ifdef IOCTRLRD_FUEL_INPUT_READING_THREE_POINT_CALIB

    for (Index = 0U; Index < IOCTRLRD_ANA_NUM_CHANNELS_THREE_POINT_CALIB; Index++) // 0xF106
    {
        if (Ioctrlrd_Analog_StartFlag_unit_Three_Point_Calib[Index] == (uint8)IOCTRLRD_TRUE_THREE_POINT_CALIB)
        {
            if (Ioctrl_ANAMap_Three_Point_Calib_TimeOut[Index] > Ioctrlrd_Analog_TimeOut_Counter_Three_Point_Calib[Index])
            {
                Ioctrlrd_Analog_TimeOut_Counter_Three_Point_Calib[Index]++;
            }
            else
            {
                Ioctrlrd_Analog_Array_unit_Three_Point_Calib[Index] = Ioctrlrd_Analog_Array_unit_Three_Point_Calib[Index] + Ioctrlrd_analog_Cmp_ADCReading_Three_Point_Calib(Ioctrl_ANAMap_Three_Point_Calib[Index]);
                Ioctrlrd_Analog_Count_unit_Three_Point_Calib[Index]++;

                if (Ioctrlrd_Analog_Count_unit_Three_Point_Calib[Index] >= Ioctrlrd_Analog_NumSamples_unit_Three_Point_Calib[Index])
                {
                    if (Ioctrlrd_Analog_NumSamples_unit_Three_Point_Calib[Index] > 0U)
                    {
                        Ioctrlrd_Analog_Result_unit_Three_Point_Calib[Index] = (Ioctrlrd_Analog_Array_unit_Three_Point_Calib[Index] * 100U) / Ioctrlrd_Analog_NumSamples_unit_Three_Point_Calib[Index];
                        Ioctrlrd_Analog_Result_unit_Three_Point_Calib[Index] = (uint32)(Ioctrlrd_analog_ReadByUnit_StateMachine(Ioctrlrd_Analog_Result_unit_Three_Point_Calib[Index], Index, &status));

                        /*
                         * Below commented code snippet use as per the requirement
                         *
                         *intpolTableThree_Point_Calib[Index].Func(Ioctrlrd_Analog_Result_unit_Three_Point_Calib[Index],Index,&status);*/

                        if (status == 1U)
                        {
                            Ioctrlrd_Analog_StartFlag_unit_Three_Point_Calib[Index] = (uint8)IOCTRLRD_FALSE_THREE_POINT_CALIB;
                            Ioctrlrd_Analog_Finished_unit_Three_Point_Calib[Index] = (uint8)IOCTRLRD_TRUE_THREE_POINT_CALIB;
                        }
                    }
                    else
                    {
                        Ioctrlrd_Analog_StartFlag_unit_Three_Point_Calib[Index] = (uint8)IOCTRLRD_FALSE_THREE_POINT_CALIB;
                        Ioctrlrd_Analog_Finished_unit_Three_Point_Calib[Index] = (uint8)IOCTRLRD_TRUE_THREE_POINT_CALIB;
                    }
                }
            }
        }
    }

    #endif
}
#endif

#ifdef IOCTRLRD_FUEL_INPUT_READING_BY_UNIT_WCalib
#ifndef IOCTRLRD_FUEL_INPUT_READING_THREE_POINT_CALIB
//----------------------------------------------------------------------------------------------------------------------
// FUNCTION_NAME:		Ioctrlrd_analog_fuel_level_periodic_func
//
// DESCRIPTION:         periodic function to compute fuel
//
// PARAMETERS:
//
// RETURN VALUE:
//
// DESIGN INFORMATION:  None
//----------------------------------------------------------------------------------------------------------------------

void Ioctrlrd_analog_fuel_level_periodic_func(void) /// periodic function
{
    static uint8 counter = IOCTRLRD_ANALOG_CLR_0_WCalib;
    uint16 adc_val = IOCTRLRD_ANALOG_CLR_0_WCalib;
    uint16 flag = IOCTRLRD_ANALOG_CLR_0_WCalib;
    uint8 status = IOCTRLRD_ANALOG_SET_1_WCalib;
    uint8 Ioctrlrd_Adc_Resolution = 4U;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        if (Ioctrlrd_analog_fuel_level_status == IOCTRLRD_NFUEL_CAL_REQD) // start adc reading when service activated
        {
            if (counter < IOCTRLRD_FUEL_SAMPLING_TIME)
            {
                counter++;
                flag = IOCTRLRD_ANALOG_CLR_0_WCalib;

                while (flag < IOCTRLRD_FUEL_SAMPLING_ACQUISITION)
                {
                    adc_val = Ioctrlrd_analog_Cmp_ADCReading_by_unit_WCalib(Ioctrlrd_analog_BY_UNIT_WCalib[IOCTRLRD_ANA_NUM_CHANNELS_UNIT_WCalib - 1U]);
                    adc_val = adc_val / Ioctrlrd_Adc_Resolution;
                    Ioctrlrd_analog_nfuel = Ioctrlrd_analog_nfuel + adc_val;
                    flag++;
                }
            }
            else
            {
                counter = IOCTRLRD_ANALOG_CLR_0_WCalib;
                Ioctrlrd_analog_fuel_level_status = IOCTRLRD_NFUEL_CAL_CMPLT;
                (void)Ioctrlrd_analog_ReadByUnit_StateMachine(0U, Fuel_level_input, &status);
            }
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------
// FUNCTION_NAME:		Ioctrlrd_analog_Cmp_ADCReading_by_unit_WCalib
//
// DESCRIPTION:          Used to get adc value
//
// PARAMETERS:			channel_id - channel id to get adc value
//
// RETURN VALUE:		ADC_Val - ADC value of the channel
//
// DESIGN INFORMATION:  None
//----------------------------------------------------------------------------------------------------------------------
static uint16 Ioctrlrd_analog_Cmp_ADCReading_by_unit_WCalib(uint16 channel_id)
{
    uint16 ADC_Val = 0U;
    Ioctrlrd_analog_fun_by_unit_WCalib[channel_id - 1U].ADC_ReadFunction(&ADC_Val);
    return (ADC_Val);
}
#endif
//----------------------------------------------------------------------------------------------------------------------
// FUNCTION_NAME:		Ioctrlrd_analog_ReadByUnit_StateMachine
//
// DESCRIPTION:         Function to compute ADC reading by state machine which needs special implementations
//
// PARAMETERS:			ADC_Val - The input adc value to be computed,index 	- ADC channel index, status - Adc completion status
//
// RETURN VALUE:		ADC_Val - Std_ReturnType: Computed ADC value in Units
//
// DESIGN INFORMATION:  None
//----------------------------------------------------------------------------------------------------------------------

static sint32 Ioctrlrd_analog_ReadByUnit_StateMachine(uint32 ADC_Val, uint8 index, uint8 *status)
{
    #ifdef IOCTRLRD_FUEL_INPUT_READING_THREE_POINT_CALIB
    uint32 res = 0U;
    sint32 s32CurrentTemp = 0;
    *status = 0;
    uint8 fuelIndex, oilIndex;

    uint32 YRealFuelBuff[MANUF_CALIB_NUM_POINTS_FUEL] = {0U};
    uint32 XRealFuelBuff[MANUF_CALIB_NUM_POINTS_FUEL] = {0U};
    uint32 ZRealFuelBuff[MANUF_CALIB_NUM_POINTS_FUEL] = {0U};

    uint32 YRealOilBuff[MANUF_CALIB_NUM_POINTS_OIL] = {0U};
    uint32 XRealOilBuff[MANUF_CALIB_NUM_POINTS_OIL] = {0U};
    uint32 ZRealOilBuff[MANUF_CALIB_NUM_POINTS_OIL] = {0U};

    uint8 division_factor = 1;

    #else
    static boolean fuel_level_entry = IOCTRLRD_ANALOG_SET_1_WCalib; // To avoid two times fuel measurement
    #endif

    switch (index)
    {
    case Fuel_level_input:
    {
        #ifndef IOCTRLRD_FUEL_INPUT_READING_THREE_POINT_CALIB

        if ((Ioctrlrd_analog_fuel_level_status == IOCTRLRD_NFUEL_CAL_CMPLT) && (fuel_level_entry == IOCTRLRD_ANALOG_SET_1_WCalib))
        {
            if (Ioctrlrd_analog_RoutineControlStatus_Unit_WCalib[Fuel_level_input].ADCInputReading == (uint8)IOCTRLRD_RC_IN_PROGRESS) // With Fuel Calibration
            {

                Ioctrlrd_Analog_Result_unit_WCalib[0U] = Ioctrlrd_analog_GetByUnit_StateMachine_WCalib[IOCTRLRD_ANA_NUM_CHANNELS_UNIT_WCalib - 1].Ioctrlrd_GetByUnit_StateMachine(Ioctrlrd_analog_nfuel);
                #if 0
                    Ioctrlrd_Analog_StartFlag_unit_WCalib[0U] = MANUF_FALSE; /* Coverity fix */
                #endif
                Ioctrlrd_Analog_Finished_unit_WCalib[0U] = MANUF_TRUE;
            }
            else
            {
            }
            Ioctrlrd_analog_nfuel = IOCTRLRD_ANALOG_CLR_0_WCalib;
            *status = IOCTRLRD_ANALOG_SET_1_WCalib;
        }
        else
        {
            fuel_level_entry = IOCTRLRD_ANALOG_SET_1_WCalib;
            *status = IOCTRLRD_ANALOG_CLR_0_WCalib;
            Ioctrlrd_analog_fuel_level_status = IOCTRLRD_NFUEL_CAL_REQD;
        }
        #else

        if (Ioctrlrd_analog_RoutineControlStatus_Three_Point_Calib[Fuel_level_input].ADCInputReading == (uint8)IOCTRLRD_RC_IN_PROGRESS)
        {
            /* Perform calibration with measured values */

            for (fuelIndex = 0U; fuelIndex < MANUF_CALIB_NUM_POINTS_FUEL; fuelIndex++)
            {
                XRealFuelBuff[fuelIndex] = Ioctrlrd_analog_Read_Fuel_Average_Value[fuelIndex].Read_NVMAverageADC_value();

                ZRealFuelBuff[fuelIndex] = Ioctrlrd_analog_Read_Fuel_Expected_Value[fuelIndex].Read_NVMExpectedADC_value();

                YRealFuelBuff[fuelIndex] = Ioctrlrd_analog_Read_Fuel_RealPoint_Value[fuelIndex].Read_NVMRealpoint_value();
            }

            #ifdef IOCTRLRD_INPUT_READING_TWO_POINT_INTERPOLATION
            (void)Ioctrlrd_MathLib_InterpolateLinearU32_U32(XRealFuelBuff, YRealFuelBuff, MANUF_CALIB_NUM_POINTS_FUEL, ADC_Val, &res);

            #else
            (void)Ioctrlrd_LIB_Math_InterpolateLinearU32(XRealFuelBuff,
                                                         ZRealFuelBuff,
                                                         YRealFuelBuff,
                                                         MANUF_CALIB_NUM_POINTS_FUEL,
                                                         ADC_Val,
                                                         &res);
            #endif
            s32CurrentTemp = (sint32)res;
            *status = 1;
        }
        else if (Ioctrlrd_analog_RoutineControlStatus_Three_Point_Calib[Fuel_level_input].ADCInputReading == (uint8)IOCTRLRD_RC_IN_PROGRESS)
        {
            /* Perform calibration with default values*/

            ADC_Val = ADC_Val * 100U;

            #ifdef IOCTRLRD_INPUT_READING_TWO_POINT_INTERPOLATION
            (void)Ioctrlrd_MathLib_InterpolateLinearU32_U32(XRealFuelBuff, YRealFuelBuff, MANUF_CALIB_NUM_POINTS_FUEL, ADC_Val, &res);

            #else
            (void)Ioctrlrd_LIB_Math_InterpolateLinearU32(XRealFuelBuff,
                                                         ZRealFuelBuff,
                                                         YRealFuelBuff,
                                                         MANUF_CALIB_NUM_POINTS_FUEL,
                                                         ADC_Val,
                                                         &res);
            #endif
            s32CurrentTemp = (sint32)res;
            *status = 1;
        }
        else
        {
            /*No action required*/
        }
        s32CurrentTemp = (s32CurrentTemp / (sint32)division_factor);
        #endif
        break;
    }
    case Oil_level_input:
    {
        #ifndef IOCTRLRD_FUEL_INPUT_READING_THREE_POINT_CALIB

        /*Space reserved for WCalib implementation*/

        #else
        if (Ioctrlrd_analog_RoutineControlStatus_Three_Point_Calib[Oil_level_input].ADCInputReading == (uint8)IOCTRLRD_RC_IN_PROGRESS)
        {
            /* Perform calibration with measured values */

            for (oilIndex = 0U; oilIndex < MANUF_CALIB_NUM_POINTS_OIL; oilIndex++)
            {
                XRealOilBuff[oilIndex] = Ioctrlrd_analog_Read_Oil_Average_Value[oilIndex].Read_NVMAverageADC_value();

                ZRealOilBuff[oilIndex] = Ioctrlrd_analog_Read_Oil_Expected_Value[oilIndex].Read_NVMExpectedADC_value();

                YRealOilBuff[oilIndex] = Ioctrlrd_analog_Read_Oil_RealPoint_Value[oilIndex].Read_NVMRealpoint_value();
            }

            #ifdef IOCTRLRD_INPUT_READING_TWO_POINT_INTERPOLATION
            (void)Ioctrlrd_MathLib_InterpolateLinearU32_U32(XRealOilBuff, YRealOilBuff, MANUF_CALIB_NUM_POINTS_OIL, ADC_Val, &res);

            #else
            (void)Ioctrlrd_LIB_Math_InterpolateLinearU32(XRealOilBuff,
                                                         ZRealOilBuff,
                                                         YRealOilBuff,
                                                         MANUF_CALIB_NUM_POINTS_OIL,
                                                         ADC_Val,
                                                         &res);
            #endif
            s32CurrentTemp = (sint32)res;
            *status = 1;
        }
        else
        {
            /*No action required*/
        }
        s32CurrentTemp = s32CurrentTemp / division_factor;
        #endif
        break;
    }
    default:
    {
        /*No action required in default case*/
        break;
    }
    }
    #ifdef IOCTRLRD_FUEL_INPUT_READING_THREE_POINT_CALIB
    return (s32CurrentTemp);
    #else
    return E_OK;
    #endif
}
#endif
#if defined(IOCTRLRD_ANALOG_DIAG) || defined(IOCTRLRD_ANALOG_DIAG_BY_UNIT)
//----------------------------------------------------------------------------------------------------------------------
// DESCRIPTION:         Manuf_BubbleSort
//
// PARAMETERS:
//
// RETURN VALUE:
//
// DESIGN INFORMATION:  None
//----------------------------------------------------------------------------------------------------------------------
static void Manuf_BubbleSort(uint16 list[], uint16 n) // in ascending order
{
    uint16 c, d, temp;

    for (c = 0U; c < (n - 1U); c++)
    {
        for (d = 0U; d < ((n - c) - 1U); d++)
        {
            if (list[d] > list[d + 1U])
            {
                // Swapping
                temp = list[d];
                list[d] = list[d + 1U];
                list[d + 1U] = temp;
            }
        }
    }
}
#endif

#ifdef IOCTRLRD_ANALOG_DIAG_BY_UNIT

//----------------------------------------------------------------------------------------------------------------------
// DESCRIPTION:          Used to control ADC by unit
//
// PARAMETERS:          cmd_type - Start, Stop or GetResults
//						ch_index - ADC channel index
//                      no_samples - Number of ADC Samples with sampling frequency of 5msec
//						outbuffer  - The output buffer
//
// RETURN VALUE:        Std_ReturnType: MANUF_OK - operation successful
//                                      MANUF_FAIL - operation failed
//										MANUF_WAIT - operation is waiting, can't be done now
//
// DESIGN INFORMATION:  None
//----------------------------------------------------------------------------------------------------------------------
static uint8 Ioctrlrd_ADCMeasurement_by_unit(uint8 cmd_type, uint8 ch_index, uint16 no_samples, uint16 *outbuffer)
{
    uint8 ResultL = MANUF_OK;

    if (ch_index < IOCTRLRD_ANA_NUM_CHANNELS_UNIT)
    {
        switch (cmd_type)
        {
        case MANUF_ADCCMD_START:
        {
            Ioctrlrd_ADC_Finished_by_unit[ch_index] = MANUF_FALSE;
            Ioctrlrd_ADC_Count_by_unit[ch_index] = 0U; // array index and up counter up to no_samples
            Ioctrlrd_ADC_NumSamples_by_unit[ch_index] = no_samples;
            Ioctrlrd_ADC_Result_by_unit[ch_index] = 0U;
            Ioctrlrd_ADC_StartFlag_by_unit[ch_index] = MANUF_TRUE;
            break;
        }
        case MANUF_ADCCMD_STOP:
        {
            Ioctrlrd_ADC_StartFlag_by_unit[ch_index] = MANUF_FALSE;
            Ioctrlrd_ADC_Finished_by_unit[ch_index] = MANUF_FALSE;
            Ioctrlrd_ADC_Result_by_unit[ch_index] = 0U;
            break;
        }
        case MANUF_ADCCMD_GETRESULTS:
        {
            if (Ioctrlrd_ADC_Finished_by_unit[ch_index] == MANUF_TRUE)
            {
                *outbuffer = Ioctrlrd_ADC_Result_by_unit[ch_index];
                ResultL = MANUF_OK;
            }
            else
            {
                ResultL = MANUF_WAIT;
            }

            break;
        }
        default:
        {
            ResultL = MANUF_FAIL;
            break;
        }
        }
    }
    else
    {
        /*Index out of range*/
        ResultL = MANUF_FAIL;
    }
    return ResultL;
}

/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_analog_diag_AdcInputReading_byunit_RCStart
**
** Visibility       :  Public
**
** Description      :  31 service analog input reading START
**
**
** Invocation       :	MeetMgr.diagcdd
**
** Inputs           :  DcmDspStartRoutineIn_AI - Analog channel selection , DcmDspStartRoutineIn_NOS - Number of samples , Errorcode
**
** Outputs          :  DcmDspStartRoutineOutSignal - return value of start signal
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_analog_diag_AdcInputReading_byunit_RCStart(uint8 DcmDspStartRoutineIn_AI, uint8 DcmDspStartRoutineIn_NOS, uint8 *DcmDspStartRoutineOutSignal, uint8 *ErrorCode)
{
    uint8 ResultL = MANUF_FAIL;
    uint8 Index = IOCTRLRD_CLR_0;
    uint16 num_samples = IOCTRLRD_CLR_0;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        Index = DcmDspStartRoutineIn_AI;

        if ((IOCTRLRD_MAX_NO_OF_SAMPLES_BY_UNIT >= DcmDspStartRoutineIn_NOS) && (IOCTRLRD_ZERO_SAMPLE_BY_UNIT != DcmDspStartRoutineIn_NOS) && (IOCTRLRD_ANA_NUM_CHANNELS_UNIT >= Index) && (IOCTRLRD_INDEX_0 < Index)) // Checking No of Samples not more than FF and Not equal to 0,Index should not more than maximum(0x0F) and Not less than 0
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;

            if (Ioctrlrd_ANAMap_BY_UNIT[Index - IOCTRLRD_RES_LEN_1] == ANA_UNUSED_CHANNEL_ID) // Check if it is unused channel,if so update ErrorCode
            {
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
            else
            {
                Index--; // Index starts from 0 while in request it starts from 1

                num_samples = DcmDspStartRoutineIn_NOS;

                ResultL = Ioctrlrd_ADCMeasurement_by_unit(MANUF_ADCCMD_START, Index, num_samples, (uint16)IOCTRLRD_CLR_0);
                if (ResultL == MANUF_OK)
                {

                    Ioctrlrd_RoutineControlStatus_Unit[Index].ADCInputReading = (uint8)IOCTRLRD_RC_IN_PROGRESS;
                    DcmDspStartRoutineOutSignal[DATA_BYTE_0] = (uint8)IOCTRLRD_RC_IN_PROGRESS;
                }
                else
                {
                    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                }
            }
        }
        else
        {
            ResultL = MANUF_FAIL;
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return (ResultL);
}

/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_analog_diag_AdcInputReading_byunit_RCStatus
**
** Visibility       :  Public
**
** Description      :  31 service analog input reading
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  DcmDspStartRoutineIn_AI - Analog channel selection, Errorcode
**
** Outputs          :  DcmDspStartRoutineOutSignal
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_analog_diag_AdcInputReading_byunit_RCStatus(uint8 DcmDspStartRoutineIn_AI, uint8 *DcmDspStartRoutineOutSignal, uint8 *ErrorCode)
{
    uint8 ResultL = MANUF_FAIL;
    uint8 Index = IOCTRLRD_CLR_0;
    uint16 tempBuffer = IOCTRLRD_CLR_0;
    #if 0
    uint32 ExttempBuffer=IOCTRLRD_CLR_0; /* Coverity fix CID : 1827632,1827630 */
    sint16 Signed_tempBuffer=IOCTRLRD_CLR_0;/*Coverity fix CID : 1827631,1827629 */
    #endif
    uint32 Unit_conv_Result = 0U;

    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {

        // Case of one entry
        Index = DcmDspStartRoutineIn_AI;

        if ((Index > 0U) && (Index <= IOCTRLRD_ANA_NUM_CHANNELS_UNIT))
        {
            Index--;

            if (((uint8)IOCTRLRD_RC_FINISHED_OK == Ioctrlrd_RoutineControlStatus_Unit[Index].ADCInputReading) ||
                ((uint8)IOCTRLRD_RC_NOT_ACTIVE == Ioctrlrd_RoutineControlStatus_Unit[Index].ADCInputReading))
            {
                DcmDspStartRoutineOutSignal[DATA_BYTE_0] = (uint8)IOCTRLRD_RC_NOT_ACTIVE;
                ResultL = MANUF_FAIL;
                *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
            }
            else
            {
                ResultL = Ioctrlrd_ADCMeasurement_by_unit(MANUF_ADCCMD_GETRESULTS, Index, (uint16)0, &tempBuffer); // cmd type, channel id, num_samples, response buffer
                if (ResultL == MANUF_WAIT)
                {
                    DcmDspStartRoutineOutSignal[DATA_BYTE_0] = (uint8)IOCTRLRD_RC_IN_PROGRESS;
                    ResultL = MANUF_OK;
                }
                else
                {
                    Ioctrlrd_RoutineControlStatus_Unit[Index].ADCInputReading = (uint8)IOCTRLRD_RC_FINISHED_OK;
                    ADC_GetByUnit_Formula_by_unit[Index].ADC_Conversion_Function(tempBuffer, &Unit_conv_Result);

                    DcmDspStartRoutineOutSignal[DATA_BYTE_0] = (uint8)IOCTRLRD_RC_FINISHED_OK; // Routine Status
                    DcmDspStartRoutineOutSignal[DATA_BYTE_1] = (uint8)(Index + MEET_INC_BY_1); // Channel Number
                    DcmDspStartRoutineOutSignal[DATA_BYTE_2] = (uint8)((Unit_conv_Result >> 24UL) & 0xFFUL);
                    DcmDspStartRoutineOutSignal[DATA_BYTE_3] = (uint8)((Unit_conv_Result >> 16UL) & 0xFFUL);
                    DcmDspStartRoutineOutSignal[DATA_BYTE_4] = (uint8)((Unit_conv_Result >> 8UL) & 0xFFUL);
                    DcmDspStartRoutineOutSignal[DATA_BYTE_5] = (uint8)(Unit_conv_Result & 0xFFUL);
                }
            }
        }
        else
        {
            /*Index out of range*/
            ResultL = MANUF_FAIL;
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ResultL;
}

/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_analog_diag_AdcInputReading_byunit_RCStop
**
** Visibility       :  Public
**
** Description      :  31 service analog input reading STOP
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  DcmDspStartRoutineIn_AI - Analog channel selection, Errorcode
**
** Outputs          :  DcmDspStartRoutineOutSignal
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_analog_diag_AdcInputReading_byunit_RCStop(uint8 DcmDspStartRoutineIn_AI, uint8 *DcmDspStartRoutineOutSignal, uint8 *ErrorCode)
{
    uint8 ResultL = MANUF_FAIL;
    uint8 Index = IOCTRLRD_CLR_0;
    uint16 num_samples = IOCTRLRD_CLR_0;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        Index = DcmDspStartRoutineIn_AI;
        if ((IOCTRLRD_ANA_NUM_CHANNELS_UNIT >= Index) && (IOCTRLRD_INDEX_0 < Index)) // Index should not more than maximum(0x0F) and Not less than 0
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;

            if (Ioctrlrd_ANAMap_BY_UNIT[Index - IOCTRLRD_RES_LEN_1] == ANA_UNUSED_CHANNEL_ID) // Check if it is unused channel,if so update ErrorCode and comeout
            {
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
            else
            {
                Index--; // Index starts from 0 while in request it starts from 1

                ResultL = Ioctrlrd_ADCMeasurement_by_unit(MANUF_ADCCMD_STOP, Index, num_samples, (uint16)IOCTRLRD_CLR_0);
                if (ResultL == MANUF_OK)
                {

                    Ioctrlrd_RoutineControlStatus_Unit[Index].ADCInputReading = (uint8)IOCTRLRD_RC_FINISHED_OK;
                    DcmDspStartRoutineOutSignal[DATA_BYTE_0] = (uint8)IOCTRLRD_RC_FINISHED_OK;
                }
                else
                {
                    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                }
            }
        }
        else
        {
            ResultL = MANUF_FAIL;
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return (ResultL);
}

//----------------------------------------------------------------------------------------------------------------------
// DESCRIPTION:         Ioctrlrd_Cmp_ADCReading_by_unit
//
// PARAMETERS:
//
// RETURN VALUE:
//
// DESIGN INFORMATION:  None
//----------------------------------------------------------------------------------------------------------------------
static uint16 Ioctrlrd_Cmp_ADCReading_by_unit(uint16 channel_id)
{
    uint16 ADC_Val = 0U;

    if (channel_id < IOCTRLRD_ANA_NUM_CHANNELS_UNIT)
    {
        Ioctrlrd_Direct_ANAMap_fun_by_unit[channel_id].ADC_ReadFunction(&ADC_Val);
    }

    return (ADC_Val);
}

#endif

#ifdef IOCTRLRD_FUEL_INPUT_READING_BY_UNIT_WCalib
#ifndef IOCTRLRD_FUEL_INPUT_READING_THREE_POINT_CALIB
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_ADCMeasurement_UnitWC
**
** Visibility       :  Public
**
** Description      :  Used to control ADC - Start, Stop or GetResults
**
** Invocation       :  Ioctrlrd_analog_diag_FuelInputReading_byunit_RCStart_WCalib
**
** Inputs           :  cmd_type - Start, Stop or GetResults , ch_index - ADC channel index , no_samples - Number of ADC Samples with sampling frequency of 5msec
**
** Outputs          :  outbuffer - Std_ReturnType: MANUF_OK operation successful/MANUF_FAIL - operation failed
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

static uint8 Ioctrlrd_ADCMeasurement_UnitWC(uint8 cmd_type, uint8 ch_index, uint16 no_samples, uint16 *outbuffer)
{
    uint8 ResultL = IOCTRLRD_OK_WCalib;

    switch (cmd_type)
    {
    case IOCTRLRD_ADCCMD_START_WCalib:
    {
        Ioctrlrd_Analog_Finished_unit_WCalib[ch_index] = IOCTRLRD_FALSE_WCalib;
        #if 0
        Ioctrlrd_Analog_Count_unit_WCalib[ch_index] = (uint16)IOCTRLRD_ANALOG_CLR_0_WCalib;  // Coverity fix	//array index and up counter upto no_samples 
        Ioctrlrd_Analog_NumSamples_unit_WCalib[ch_index] = no_samples; // Coverity fix
        Ioctrlrd_Analog_StartFlag_unit_WCalib[ch_index] = IOCTRLRD_TRUE_WCalib; // Coverity fix
        #endif
        Ioctrlrd_Analog_Result_unit_WCalib[ch_index] = (uint16)IOCTRLRD_ANALOG_CLR_0_WCalib;
        break;
    }
    case IOCTRLRD_ADCCMD_STOP_WCalib:
    {
        #if 0
        Ioctrlrd_Analog_StartFlag_unit_WCalib[ch_index] = IOCTRLRD_FALSE_WCalib; //Coverity fix
        #endif
        Ioctrlrd_Analog_Finished_unit_WCalib[ch_index] = IOCTRLRD_FALSE_WCalib;
        Ioctrlrd_Analog_Result_unit_WCalib[ch_index] = (uint16)IOCTRLRD_ANALOG_CLR_0_WCalib;
        break;
    }
    case IOCTRLRD_ADCCMD_GETRESULTS_WCalib:
    {
        if (Ioctrlrd_Analog_Finished_unit_WCalib[ch_index] == IOCTRLRD_TRUE_WCalib)
        {
            *outbuffer = Ioctrlrd_Analog_Result_unit_WCalib[ch_index];
            ResultL = IOCTRLRD_OK_WCalib;
        }
        else
        {
            ResultL = IOCTRLRD_WAIT_WCalib;
        }
        break;
    }
    default:
        ResultL = IOCTRLRD_FAIL_WCalib;
        break;
    }
    return ResultL;
}

/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_analog_diag_FuelInputReading_byunit_RCStart_WCalib
**
** Visibility       :  Public
**
** Description      :  Internal routine called for start ADC reading with unit with calibration
**
**
** Invocation       :	MeetMgr.diagcdd
**
** Inputs           :  DcmDspStartRoutineIn_AI - Analog channel selection , DcmDspStartRoutineIn_NOS - Number of samples , Errorcode
**
** Outputs          :  DcmDspStartRoutineOutSignal - return value of start signal
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_analog_diag_FuelInputReading_byunit_RCStart_WCalib(uint8 DcmDspStartRoutineIn_AI, uint8 DcmDspStartRoutineIn_NOS, uint8 *DcmDspStartRoutineOutSignal, uint8 *ErrorCode)
{
    uint8 ResultL = MANUF_FAIL;
    uint8 Index = IOCTRLRD_ANALOG_CLR_0_WCalib;
    uint16 num_samples = IOCTRLRD_ANALOG_CLR_0_WCalib;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        Index = DcmDspStartRoutineIn_AI + 1U;

        if ((Index == 1U) && (IOCTRLRD_ZERO_SAMPLE_BY_UNIT_WCalib != DcmDspStartRoutineIn_NOS))
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;

            if (Ioctrlrd_analog_BY_UNIT_WCalib[Index - IOCTRLRD_ANALOG_RES_LEN_1_WCalib] == IOCTRLRD_ANA_UNUSED_CHANNEL_ID_WCalib)
            {
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
            else
            {
                Index--;
                #if 0
                Ioctrlrd_analog_Fuel_level_input_cal = IOCTRLRD_FUEL_INPUT_BY_UNIT_WITH_CALIB; // Coverity fix
                #endif
                Ioctrlrd_analog_fuel_level_status = IOCTRLRD_NFUEL_CAL_REQD;

                num_samples = DcmDspStartRoutineIn_NOS;

                ResultL = Ioctrlrd_ADCMeasurement_UnitWC(IOCTRLRD_ADCCMD_START_WCalib, Index, num_samples, (uint16)0);
                if (ResultL == MANUF_OK)
                {
                    Ioctrlrd_analog_RoutineControlStatus_Unit_WCalib[Index].ADCInputReading = (uint8)IOCTRLRD_RC_IN_PROGRESS;
                    DcmDspStartRoutineOutSignal[IOCTRLRD_ANALOG_INDEX_0_WCalib] = (uint8)IOCTRLRD_RC_IN_PROGRESS;
                }
                else
                {
                    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                }
            }
        }
        else
        {
            ResultL = MANUF_FAIL;
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }
    else
    {
        // invalid length
        *ErrorCode = INVALID_MODE;
    }
    return (ResultL);
}

/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_analog_diag_FuelInputReading_byunit_RCStatus_WCalib
**
** Visibility       :  Public
**
** Description      :  Internal routine called for status ADC reading with unit with calibration
**
**
** Invocation       :	MeetMgr.diagcdd
**
** Inputs           :  DcmDspStartRoutineIn_AI - Analog channel selection , DcmDspStartRoutineIn_NOS - Number of samples , Errorcode - Error code in case there is a problem during execution
**
** Outputs          :  DcmDspStartRoutineOutSignal - return value of start signal,Std_ReturnType: MANUF_OK operation successful/MANUF_FAIL - operation failed
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_analog_diag_FuelInputReading_byunit_RCStatus_WCalib(uint8 DcmDspStartRoutineIn_AI, uint8 DcmDspStartRoutineIn_NOS, uint8 *DcmDspStartRoutineOutSignal, uint8 *ErrorCode)
{
    uint8 ResultL = MANUF_FAIL;
    uint8 Index = IOCTRLRD_ANALOG_CLR_0_WCalib;
    uint16 tempBuffer = IOCTRLRD_ANALOG_CLR_0_WCalib;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        Index = DcmDspStartRoutineIn_AI;

        if (Index == 0U)
        {

            if (((uint8)IOCTRLRD_RC_FINISHED_OK == Ioctrlrd_analog_RoutineControlStatus_Unit_WCalib[Index].ADCInputReading) || ((uint8)IOCTRLRD_RC_NOT_ACTIVE == Ioctrlrd_analog_RoutineControlStatus_Unit_WCalib[Index].ADCInputReading))
            {
                DcmDspStartRoutineOutSignal[DATA_BYTE_0] = (uint8)IOCTRLRD_RC_NOT_ACTIVE;
                ResultL = MANUF_OK;
            }
            else
            {
                ResultL = Ioctrlrd_ADCMeasurement_UnitWC(MANUF_ADCCMD_GETRESULTS, Index, (uint16)0, &tempBuffer); // cmd type, channel id, num_samples, response buffer
                if (ResultL == MANUF_WAIT)
                {
                    DcmDspStartRoutineOutSignal[DATA_BYTE_0] = (uint8)IOCTRLRD_RC_IN_PROGRESS;
                    ResultL = MANUF_OK;
                }
                else
                {
                    if (Ioctrlrd_analog_fuel_level_status == IOCTRLRD_NFUEL_CAL_CMPLT)
                    {
                        DcmDspStartRoutineOutSignal[DATA_BYTE_0] = (uint8)IOCTRLRD_RC_FINISHED_OK; // Routine Status
                        Ioctrlrd_analog_RoutineControlStatus_Unit_WCalib[Index].ADCInputReading = (uint8)IOCTRLRD_RC_FINISHED_OK;
                        DcmDspStartRoutineOutSignal[DATA_BYTE_1] = (uint8)((tempBuffer >> IOCTRLRD_SHIFT_BY_8) & IOCTRLRD_FF_MASK_BYTE); // MSbyte of ADC value
                        DcmDspStartRoutineOutSignal[DATA_BYTE_2] = (uint8)(tempBuffer & IOCTRLRD_FF_MASK_BYTE);                          // LSbyte of ADC value
                        ResultL = MANUF_OK;
                    }
                    else
                    {
                        *ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
                        ResultL = MANUF_FAIL;
                    }
                }
            }
        }
        else
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ResultL;
}

#else
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_ADCMeasurement_Three_Point_Calib
**
** Visibility       :  Public
**
** Description      :  Used to control ADC - Start, Stop or GetResults
**
** Invocation       :  Ioctrlrd_analog_diag_FuelInputReading_byunit_RCStart_WCalib
**
** Inputs           :  cmd_type - Start, Stop or GetResults , ch_index - ADC channel index , no_samples - Number of ADC Samples with sampling frequency of 5msec
**
** Outputs          :  outbuffer - Std_ReturnType: IOCTRLRD_OK_THREE_POINT_CALIB operation successful/IOCTRLRD_FAIL_THREE_POINT_CALIB - operation failed
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

static uint8 Ioctrlrd_ADCMeasurement_Three_Point_Calib(uint8 cmd_type, uint8 ch_index, uint16 no_samples, uint32 *outbuffer, uint32 size)
{
    uint8 ResultL = IOCTRLRD_FAIL_THREE_POINT_CALIB;

    switch (cmd_type)
    {
    case IOCTRLRD_ADCCMD_START_THREE_POINT_CALIB:
    {
        Ioctrlrd_Analog_Finished_unit_Three_Point_Calib[ch_index] = IOCTRLRD_FALSE_THREE_POINT_CALIB;
        Ioctrlrd_Analog_Count_unit_Three_Point_Calib[ch_index] = (uint16)0; // array index and up counter upto no_samples
        Ioctrlrd_Analog_NumSamples_unit_Three_Point_Calib[ch_index] = (uint8)no_samples;
        Ioctrlrd_Analog_Result_unit_Three_Point_Calib[ch_index] = 0UL;
        Ioctrlrd_Analog_Array_unit_Three_Point_Calib[ch_index] = 0UL;
        Ioctrlrd_Analog_StartFlag_unit_Three_Point_Calib[ch_index] = IOCTRLRD_TRUE_THREE_POINT_CALIB;
        Ioctrlrd_Analog_TimeOut_Counter_Three_Point_Calib[ch_index] = 0u;
        ResultL = IOCTRLRD_OK_THREE_POINT_CALIB;
        break;
    }
    case IOCTRLRD_ADCCMD_STOP_THREE_POINT_CALIB:
    {
        Ioctrlrd_Analog_StartFlag_unit_Three_Point_Calib[ch_index] = IOCTRLRD_FALSE_THREE_POINT_CALIB;
        Ioctrlrd_Analog_Finished_unit_Three_Point_Calib[ch_index] = IOCTRLRD_TRUE_THREE_POINT_CALIB;
        Ioctrlrd_Analog_Result_unit_Three_Point_Calib[ch_index] = 0UL;
        Ioctrlrd_Analog_Array_unit_Three_Point_Calib[ch_index] = 0UL;
        Ioctrlrd_Analog_TimeOut_Counter_Three_Point_Calib[ch_index] = 0u;
        ResultL = IOCTRLRD_OK_THREE_POINT_CALIB;
        break;
    }
    case IOCTRLRD_ADCCMD_GETRESULTS_THREE_POINT_CALIB:
    {
        if (Ioctrlrd_Analog_Finished_unit_Three_Point_Calib[ch_index] == IOCTRLRD_TRUE_THREE_POINT_CALIB)
        {
            /*if(size > sizeof(uint16))
            {
                Meet_Separate_U32Variable_To_U8Array(Manuf_ADC_Result_unit_WCalib[ch_index], outbuffer, size );
            }
            else
            {
                Meet_Separate_U16Variable_To_U8Array((uint16)Manuf_ADC_Result_unit_WCalib[ch_index], outbuffer, size );
            }*/

            *outbuffer = Ioctrlrd_Analog_Result_unit_Three_Point_Calib[ch_index];

            ResultL = IOCTRLRD_OK_THREE_POINT_CALIB;
        }
        else
        {
            ResultL = IOCTRLRD_WAIT_THREE_POINT_CALIB;
        }
        break;
    }
    default:
    {
        ResultL = IOCTRLRD_FAIL_THREE_POINT_CALIB;
        break;
    }
    }

    return ResultL;
}
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_analog_diag_FuelInputReading_three_point_Calib_RCStart
**
** Visibility       :  Public
**
** Description      :  Internal routine called for start ADC reading with unit with calibration
**
**
** Invocation       :	MeetMgr.diagcdd
**
** Inputs           :  DcmDspStartRoutineIn_AI - Analog channel selection , DcmDspStartRoutineIn_NOS - Number of samples , Errorcode
**
** Outputs          :  DcmDspStartRoutineOutSignal - return value of start signal
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_analog_diag_InputReading_three_point_Calib_RCStart(uint8 DcmDspStartRoutineIn_AI, uint8 DcmDspStartRoutineIn_NOS, uint8 *DcmDspStartRoutineOutSignal, uint8 *ErrorCode)
{
    uint8 ResultL = IOCTRLRD_FAIL_THREE_POINT_CALIB;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        if ((IOCTRLRD_ANA_NUM_CHANNELS_THREE_POINT_CALIB > DcmDspStartRoutineIn_AI) &&
            (Ioctrlrd_analog_Three_Point_Calib[DcmDspStartRoutineIn_AI] != IOCTRLRD_ANA_UNUSED_CHL_ID_THREE_POINT_CALIB))
        {
            if (IOCTRLRD_RC_IN_PROGRESS == Ioctrlrd_analog_RoutineControlStatus_Three_Point_Calib[DcmDspStartRoutineIn_AI].ADCInputReading)
            {
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }
            else
            {
                ResultL = Ioctrlrd_ADCMeasurement_Three_Point_Calib(IOCTRLRD_ADCCMD_START_THREE_POINT_CALIB, DcmDspStartRoutineIn_AI, DcmDspStartRoutineIn_NOS, (uint32)0, 0);

                if (ResultL == MANUF_OK)
                {
                    #if 0
                    if(Mai_Oil_Level == DcmDspStartRoutineIn_AI)
                    {
                        CIoHwAb_Impl_SetPin(eIOPinOutId_Oil_En, 1);
                    }
                    #endif

                    Ioctrlrd_analog_RoutineControlStatus_Three_Point_Calib[DcmDspStartRoutineIn_AI].ADCInputReading = (uint8)IOCTRLRD_RC_IN_PROGRESS;
                    DcmDspStartRoutineOutSignal[DATA_BYTE_0] = (uint8)IOCTRLRD_RC_IN_PROGRESS;
                    DcmDspStartRoutineOutSignal[DATA_BYTE_1] = DcmDspStartRoutineIn_AI;
                }
            }
        }
        else
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ResultL;
}

/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_analog_diag_FuelInputReading_three_point_Calib_RCStatus
**
** Visibility       :  Public
**
** Description      :  Internal routine called for status ADC reading with unit with calibration
**
**
** Invocation       :	MeetMgr.diagcdd
**
** Inputs           :  DcmDspStartRoutineIn_AI - Analog channel selection , DcmDspStartRoutineIn_NOS - Number of samples , Errorcode - Error code in case there is a problem during execution
**
** Outputs          :  DcmDspStartRoutineOutSignal - return value of start signal,Std_ReturnType: IOCTRLRD_OK_THREE_POINT_CALIB operation 				successful/IOCTRLRD_FAIL_THREE_POINT_CALIB - operation failed
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_analog_diag_InputReading_three_point_Calib_RCStatus(uint8 DcmDspStartRoutineIn_AI, uint8 DcmDspStartRoutineIn_NOS, uint8 *DcmDspStartRoutineOutSignal, uint8 *ErrorCode)
{
    Std_ReturnType ResultL = IOCTRLRD_FAIL_THREE_POINT_CALIB;
    *DcmDspStartRoutineOutSignal = (uint8)0UL;
    uint32 tempBuffer[2];
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        if ((IOCTRLRD_ANA_NUM_CHANNELS_THREE_POINT_CALIB > DcmDspStartRoutineIn_AI) &&
            (Ioctrlrd_analog_Three_Point_Calib[DcmDspStartRoutineIn_AI] != IOCTRLRD_ANA_UNUSED_CHL_ID_THREE_POINT_CALIB))
        {
            if ((IOCTRLRD_RC_NOT_ACTIVE == Ioctrlrd_analog_RoutineControlStatus_Three_Point_Calib[DcmDspStartRoutineIn_AI].ADCInputReading) ||
                (IOCTRLRD_RC_FINISHED_NOK == Ioctrlrd_analog_RoutineControlStatus_Three_Point_Calib[DcmDspStartRoutineIn_AI].ADCInputReading))
            {
                #if 0
                if( Mai_Oil_Level == DcmDspRoutineRequestResIn_AI)
                {
                    CIoHwAb_Impl_SetPin(eIOPinOutId_Oil_En, 0);
                }
                #endif

                DcmDspStartRoutineOutSignal[DATA_BYTE_0] = Ioctrlrd_analog_RoutineControlStatus_Three_Point_Calib[DcmDspStartRoutineIn_AI].ADCInputReading;
                ResultL = IOCTRLRD_OK_THREE_POINT_CALIB;
            }
            else
            {
                ResultL = Ioctrlrd_ADCMeasurement_Three_Point_Calib(IOCTRLRD_ADCCMD_GETRESULTS_THREE_POINT_CALIB, DcmDspStartRoutineIn_AI, (uint16)0, (uint32 *)tempBuffer, sizeof(uint32));

                if (ResultL == IOCTRLRD_WAIT_THREE_POINT_CALIB)
                {
                    DcmDspStartRoutineOutSignal[DATA_BYTE_0] = (uint8)IOCTRLRD_RC_IN_PROGRESS;
                    ResultL = IOCTRLRD_OK_THREE_POINT_CALIB;
                }
                else
                {
                    Ioctrlrd_analog_RoutineControlStatus_Three_Point_Calib[DcmDspStartRoutineIn_AI].ADCInputReading = (uint8)IOCTRLRD_RC_FINISHED_OK;

                    DcmDspStartRoutineOutSignal[DATA_BYTE_0] = (uint8)IOCTRLRD_RC_FINISHED_OK;
                    DcmDspStartRoutineOutSignal[DATA_BYTE_1] = DcmDspStartRoutineIn_AI;
                    DcmDspStartRoutineOutSignal[DATA_BYTE_2] = (uint8)((tempBuffer[0] >> IOCTRLRD_THREE_POINT_CALIB_SHIFT_BY_24) & IOCTRLRD_THREE_POINT_CALIB_FF_MASK_BYTE);
                    DcmDspStartRoutineOutSignal[DATA_BYTE_3] = (uint8)((tempBuffer[0] >> IOCTRLRD_THREE_POINT_CALIB_SHIFT_BY_16) & IOCTRLRD_THREE_POINT_CALIB_FF_MASK_BYTE);
                    DcmDspStartRoutineOutSignal[DATA_BYTE_4] = (uint8)((tempBuffer[0] >> IOCTRLRD_THREE_POINT_CALIB_SHIFT_BY_8) & IOCTRLRD_THREE_POINT_CALIB_FF_MASK_BYTE);
                    DcmDspStartRoutineOutSignal[DATA_BYTE_5] = (uint8)(tempBuffer[0] & IOCTRLRD_THREE_POINT_CALIB_FF_MASK_BYTE);
                }
            }
        }
        else
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ResultL;
}

//----------------------------------------------------------------------------------------------------------------------
// FUNCTION_NAME:		Ioctrlrd_analog_Cmp_ADCReading_Three_Point_Calib
//
// DESCRIPTION:         Used to get adc value
//
// PARAMETERS:			channel_id - channel id to get adc value
//
// RETURN VALUE:		ADC_Val - ADC value of the channel
//
// DESIGN INFORMATION:  None
//----------------------------------------------------------------------------------------------------------------------
static uint16 Ioctrlrd_analog_Cmp_ADCReading_Three_Point_Calib(uint16 channel_id)
{
    uint16 ADC_Val = 0U;
    Ioctrlrd_analog_fun_Three_Point_Calib[channel_id - 1U].ADC_ReadFunction(&ADC_Val);
    return (ADC_Val);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType Ioctrlrd_LIB_Math_InterpolateLinearU32(const uint32 *const pu32XPointsP,
                                                             const uint32 *const pu32ZPointsP,
                                                             const uint32 *const pu32YPointsP,
                                                             const uint32 u32CountP,
                                                             const uint32 u32XValueP,
                                                             uint32 *const pu32YValueP)
{

    Std_ReturnType Ioctrlrd_TPC_ResL = E_NOT_OK;
    boolean Ioctrlrd_TPC_bStateL = FALSE;
    uint32_least Ioctrlrd_TPC_u32IndexL;
    const uint32 *Ioctrlrd_TPC_pu32PointL;

    if ((NULL == pu32XPointsP) || (NULL == pu32ZPointsP) || (NULL == pu32YPointsP) || (NULL == pu32YValueP) || ((uint32)0 == u32CountP))
    {
        Ioctrlrd_TPC_ResL = E_NOT_OK;
    }
    else
    {
        if ((u32XValueP < pu32XPointsP[0]) ||
            (u32XValueP > pu32XPointsP[u32CountP - (uint32)1]))
        {
            // The input value is outside of the interpolation table

            *pu32YValueP = Ioctrlrd_ExtrapolateU32(pu32XPointsP, pu32ZPointsP, pu32YPointsP, u32CountP, u32XValueP, &Ioctrlrd_TPC_bStateL);
        }
        else if (u32XValueP == pu32XPointsP[0])
        {
            *pu32YValueP = pu32YPointsP[0];
            Ioctrlrd_TPC_ResL = E_OK;
        }
        else if (u32XValueP == pu32XPointsP[u32CountP - (uint32)1])
        {
            *pu32YValueP = pu32YPointsP[u32CountP - (uint32)1];
            Ioctrlrd_TPC_ResL = E_OK;
        }
        else
        {

            // The input value is inside from the interpolation table
            // Result = Y-Value from the last interpolation point
            Ioctrlrd_TPC_u32IndexL = (uint32_least)(u32CountP - (uint32)1);

            // divide array in two parts for faster search
            // polyspace<RTE:IDP> If the client supplies the correct array address and size there is no danger of failure here.
            if (u32XValueP < pu32XPointsP[u32CountP >> 1])
            {
                Ioctrlrd_TPC_u32IndexL = (uint32_least)(u32CountP >> 1);
            }

            Ioctrlrd_TPC_pu32PointL = &pu32XPointsP[Ioctrlrd_TPC_u32IndexL];

            do
            {
                Ioctrlrd_TPC_u32IndexL--;
                // QACJ 0489: aspasom: Optimization of CPU time, fast execution is important for LIBs
                Ioctrlrd_TPC_pu32PointL--;
            }
            // polyspace<RTE:IDP> If the client supplies the correct array address and size there is no danger of failure here.
            while ((*Ioctrlrd_TPC_pu32PointL) > u32XValueP);

            // polyspace<RTE:IDP> If the client supplies the correct array address and size there is no danger of failure here.

            *pu32YValueP = Ioctrlrd_InterpolateU32(u32XValueP, pu32ZPointsP[Ioctrlrd_TPC_u32IndexL], pu32ZPointsP[Ioctrlrd_TPC_u32IndexL + 1UL], pu32XPointsP[Ioctrlrd_TPC_u32IndexL], pu32YPointsP[Ioctrlrd_TPC_u32IndexL], pu32XPointsP[Ioctrlrd_TPC_u32IndexL + 1UL], pu32YPointsP[Ioctrlrd_TPC_u32IndexL + 1UL], &Ioctrlrd_TPC_bStateL);
        }

        if (Ioctrlrd_TPC_bStateL != FALSE)
        {
            Ioctrlrd_TPC_ResL = E_OK;
        }
    }

    return Ioctrlrd_TPC_ResL;
}

//----------------------------------------------------------------------------------------------------------------------
// DESCRIPTION:    Linear extrapolation function
//
// PARAMETERS  :   const uint32 * const pu32XPointP   - Table with X-values
//                 const uint32 * const pu32YPointP   - Table with Y-values
//                 const uint32         u32CountP     - Number of points (1..4294967295)
//                 const uint32         u32XeP        - Input value Xe
//                 boolean      * const bpStateP      - FALSE if there's overflow or underflow and TRUE if there isn't
//
// RETURN VALUE :  uint32 - The calculated Y value from the linear extrapolation
//
//
// DESIGN INFORMATION: On overflow returned value is 4294967295 and when underflow returned value is 0
//----------------------------------------------------------------------------------------------------------------------
static uint32 Ioctrlrd_ExtrapolateU32(const uint32 *const pu32XPointP,
                                      const uint32 *const pu32ZPointP,
                                      const uint32 *const pu32YPointP,
                                      const uint32 u32CountP,
                                      const uint32 u32XeP,
                                      boolean *const bpStateP)
{
    /* QACJ 0506: aulivei: Dereferencing pointer value cannot be NULL, because it's already checked */
    const uint32 Ioctrlrd_TPC_u32ProductBeginL = Ioctrlrd_MathLib_AbsDelta(pu32YPointP[1], pu32YPointP[0]);
    /*  End of characteristic */
    /*  polyspace<RTE:IDP> If the client supplies the correct array address and size there is no danger of failure here. */
    const uint32 Ioctrlrd_TPC_u32ProductEndL = Ioctrlrd_MathLib_AbsDelta(pu32YPointP[u32CountP - (uint32)1], pu32YPointP[u32CountP - (uint32)2]);

    // QACJ 0506: aulivei: Dereferencing pointer value cannot be NULL, because it's already checked
    const uint32 Ioctrlrd_TPC_u32DivisorBeginL = Ioctrlrd_MathLib_AbsDelta(pu32XPointP[1], pu32XPointP[0]);
    const uint32 Ioctrlrd_TPC_u32DivisorEndL = Ioctrlrd_MathLib_AbsDelta(pu32XPointP[u32CountP - (uint32)1], pu32XPointP[u32CountP - (uint32)2]);
    #if 0
    const float32 Ioctrlrd_TPC_u32DivisorBeginH = (float32)(u32XeP - pu32XPointP[0]);
    ddanecha: const float32 Ioctrlrd_TPC_u32DivisorBeginH = (float32)( pu32XPointP[0] - u32XeP);
    ddanecha: const float32 Ioctrlrd_TPC_u32DivisorEndH = (float32)(u32XeP - pu32XPointP[u32CountP - (uint32) 1]);
    #endif

    const float32 Ioctrlrd_TPC_u32DivisorBeginH = (float32)Ioctrlrd_MathLib_AbsDelta(pu32XPointP[0], u32XeP);
    const float32 Ioctrlrd_TPC_u32DivisorEndH = (float32)Ioctrlrd_MathLib_AbsDelta(u32XeP, pu32XPointP[u32CountP - (uint32)1]);

    uint32 Ioctrlrd_TPC_u32ResultL = 0;
    float32 Ioctrlrd_TPC_u32TempL = (float32)0.0;
    uint32 Ioctrlrd_TPC_u32BPXc = 0;
    uint32 zIndex;
    float32 Z[u32CountP];
    // QACJ 0506: aulivei: Dereferencing pointer value cannot be NULL, because it's already checked
    *bpStateP = TRUE;

    /*DDANECHA:
    const float32 Z0 = pu32ZPointP[0];
    const float32 Z1 = pu32ZPointP[1];
    const float32 Z2 = pu32ZPointP[2];*/

    for (zIndex = 0U; zIndex < u32CountP; zIndex++)
    {
        Z[zIndex] = (float32)pu32ZPointP[zIndex];
    }

    // The point is less than the first point from the array
    if (((pu32XPointP[0] > u32XeP) && (Ioctrlrd_TPC_u32DivisorBeginL > (uint32)0)) || (u32CountP == 2U))
    {
        #if 0
        const float32 DivRatio1 = (Z0/ pu32XPointP[0]) ;
        const float32 DivRatio2 = (Z1/ pu32XPointP[1]);
        const float32 Difference = (float32)(DivRatio2 - DivRatio1);
        const float32 DivRatio3 = (Ioctrlrd_TPC_u32DivisorBeginH/Ioctrlrd_TPC_u32DivisorBeginL);
        const float32 MultAdd = (DivRatio1 - (Difference * DivRatio3));
        Ioctrlrd_TPC_u32BPXc = (uint32)(MultAdd * u32XeP);
        #endif
        Ioctrlrd_TPC_u32TempL = (Z[0] / (float32)pu32XPointP[0]) - ((Z[1] / (float32)pu32XPointP[1]) - (Z[0] / (float32)pu32XPointP[0])) * Ioctrlrd_TPC_u32DivisorBeginH / (float32)Ioctrlrd_TPC_u32DivisorBeginL;

        Ioctrlrd_TPC_u32BPXc = (uint32)(Ioctrlrd_TPC_u32TempL)*u32XeP;

        Ioctrlrd_TPC_u32ResultL = (uint32)((Ioctrlrd_TPC_u32BPXc * Ioctrlrd_TPC_u32ProductBeginL) / Ioctrlrd_TPC_u32DivisorBeginL);
    }
    // The point is bigger than the last point from the array
    else if ((u32XeP > pu32XPointP[u32CountP - (uint32)1]) && (Ioctrlrd_TPC_u32DivisorEndL > (uint32)0))
    {
        #if 0
        const float32 DivRatio1 = (Z1/ pu32XPointP[1]) ;
        const float32 DivRatio2 = (Z2/ pu32XPointP[2]);
        const float32 Difference = (float32)(DivRatio2 - DivRatio1);
        const float32 DivRatio3 = (Ioctrlrd_TPC_u32DivisorEndH/Ioctrlrd_TPC_u32DivisorEndL);
        const float32 MultAdd = (DivRatio1 + (Difference * DivRatio3));
        Ioctrlrd_TPC_u32BPXc = (uint32)(MultAdd * u32XeP);
        
        Ioctrlrd_TPC_u32ResultL = (uint32)((Ioctrlrd_TPC_u32BPXc * Ioctrlrd_TPC_u32ProductEndL)/ Ioctrlrd_TPC_u32DivisorEndL);
        #endif
        Ioctrlrd_TPC_u32TempL = (Z[1] / (float32)pu32XPointP[1]) + ((Z[2] / (float32)pu32XPointP[2]) - (Z[1] / (float32)pu32XPointP[1])) * Ioctrlrd_TPC_u32DivisorEndH / (float32)Ioctrlrd_TPC_u32DivisorEndL;

        Ioctrlrd_TPC_u32BPXc = (uint32)(Ioctrlrd_TPC_u32TempL)*u32XeP;
        Ioctrlrd_TPC_u32ResultL = (uint32)((Ioctrlrd_TPC_u32BPXc * Ioctrlrd_TPC_u32ProductEndL) / Ioctrlrd_TPC_u32DivisorEndL);
    }
    else
    {
        *bpStateP = FALSE;
    }
    return Ioctrlrd_TPC_u32ResultL;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------
static uint32 Ioctrlrd_InterpolateU32(const uint32 u32XeP,
                                      const uint32 u32Z1P,
                                      const uint32 u32Z2P,
                                      const uint32 u32X1P,
                                      const uint32 u32Y1P,
                                      const uint32 u32X2P,
                                      const uint32 u32Y2P,
                                      boolean *const bpStateP)
{

    uint32 Ioctrlrd_TPC_u32ResultL = 0;
    const float32 Z0 = (float32)u32Z1P;
    const float32 Z1 = (float32)u32Z2P;

    // polyspace<RTE:OVFL> There isn't a problem when the result is bigger than MAX INT32
    const volatile uint32 Ioctrlrd_TPC_u32DivisorL = Ioctrlrd_MathLib_AbsDelta(u32X2P, u32X1P);
    const volatile float32 Ioctrlrd_TPC_u32DivisorH = (float32)Ioctrlrd_MathLib_AbsDelta(u32XeP, u32X1P);
    const volatile uint32 Ioctrlrd_TPC_u32HalfDivisorL = (uint32)0;
    // polyspace<RTE:OVFL> There isn't a problem when the result is bigger than MAX INT32
    const volatile uint32 Ioctrlrd_TPC_u32MultL = Ioctrlrd_MathLib_AbsDelta(u32Y1P, u32Y2P);
    #if 0
    const float32 DivRatio1 = (Z0/ u32X1P) ;
    const float32 DivRatio2 = (Z1/ u32X2P);
    const float32 Difference = (float32)(DivRatio2 - DivRatio1);
    const float32 DivRatio3 = (Ioctrlrd_TPC_u32DivisorH/Ioctrlrd_TPC_u32DivisorL);
    const float32 MultAdd = (DivRatio1 + (Difference * DivRatio3));
    const uint32 Ioctrlrd_TPC_u32BPXc = (uint32)(MultAdd * u32XeP);
    #endif
    const float32 DivRatio1 = (Z0 / (float32)u32X1P);
    const float32 DivRatio2 = (Z1 / (float32)u32X2P);
    const float32 Difference = (float32)(DivRatio2 - DivRatio1);
    const float32 MultAdd = DivRatio1 + Difference * Ioctrlrd_TPC_u32DivisorH / (float32)Ioctrlrd_TPC_u32DivisorL;
    const uint32 Ioctrlrd_TPC_u32BPXc = (uint32)(MultAdd * (float32)u32XeP);
    if (Ioctrlrd_TPC_u32DivisorL > (uint32)0)
    {
        // Used Intrinsic instruction for multiplying 32x32->64 and sum the product 64-bit

        Ioctrlrd_TPC_u32ResultL = (uint32)(__UMLAL(Ioctrlrd_TPC_u32HalfDivisorL, Ioctrlrd_TPC_u32BPXc, Ioctrlrd_TPC_u32MultL) / Ioctrlrd_TPC_u32DivisorL);

        *bpStateP = TRUE;
    }

    return Ioctrlrd_TPC_u32ResultL;
}
#endif
#endif

#endif

#ifdef IOCONTOLRD_ADC_READ_GROUP
#if IOCONTOLRD_ADC_READ_GROUP > 0
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_analog_diag_read_ADC_Group_00
**
** Visibility       :  Public
**
** Description      :  Reads ADC value individual channe1 or Group wise.
**
**
** Invocation       :  MeetMgr.diagcdd, Function:Read_Diag_FA51
**
** Inputs           :  Data[Out]: Reads Battery voltage
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_analog_diag_read_ADC_Group_00(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        (void)Meet_ADCReadConfig_group[0].ADCGroupReadFunction(Data);
        ret = E_OK;
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif
#if IOCONTOLRD_ADC_READ_GROUP > 1
Std_ReturnType Ioctrlrd_analog_diag_read_ADC_Group_01(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        (void)Meet_ADCReadConfig_group[1].ADCGroupReadFunction(Data);
        ret = E_OK;
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif
#if IOCONTOLRD_ADC_READ_GROUP > 2
Std_ReturnType Ioctrlrd_analog_diag_read_ADC_Group_02(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        (void)Meet_ADCReadConfig_group[2].ADCGroupReadFunction(Data);
        ret = E_OK;
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif
#if IOCONTOLRD_ADC_READ_GROUP > 3
Std_ReturnType Ioctrlrd_analog_diag_read_ADC_Group_03(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        (void)Meet_ADCReadConfig_group[3].ADCGroupReadFunction((void *)Data);
        ret = E_OK;
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif
#if IOCONTOLRD_ADC_READ_GROUP > 4
Std_ReturnType Ioctrlrd_analog_diag_read_ADC_Group_04(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        (void)Meet_ADCReadConfig_group[4].ADCGroupReadFunction((void *)Data);
        ret = E_OK;
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif
#endif
#ifdef IOCONTOLRD_ADC_READ_SAFE_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_analog_diag_IoHwSafe_Read_ADC_Value
**
** Visibility       :  Public
**
** Description      :  Reads ADC value Safe channels.
**
**
** Invocation       :  Read_ADC_channel_CH0.....CHN
**
** Inputs           :  Data[Out]: Read safe channel ADC
**					   index: To be read ADC channel
**
** Outputs          :  Data[Out] -ADC vlaue
**
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
void Ioctrlrd_analog_diag_IoHwSafe_Read_ADC_Value(uint16 *data, uint8 index)
{
    *data = l_Meet_CIoHwAbSafe_AIn_Voltage[index];
}
/*=====================================================================================================================
 **
 ** Function Name    :  Ioctrlrd_analog_diag_IoHwSafe_ADC_Perioc_Task
 **
 ** Visibility       :  Public
 **
 ** Description      :  ADC conversion for safe channels
 **
 **
 ** Invocation       : CMPLIB_INSTANCE(MeetCdd Active) 10ms Runnable
 **
 ** Inputs           :
 **
 **
 ** Outputs          :
 **
 **
 ** Critical Section : Yes/No
 **
 **====================================================================================================================*/
void Ioctrlrd_analog_diag_IoHwSafe_ADC_Perioc_Task(void)
{
    Std_ReturnType fl_Adc_Result_U8;

    fl_Adc_Result_U8 = (uint8)Adc_GetGroupStatus((Adc_GroupType)AdcConf_AdcGroup_IoHwAbSafe);

    if ((uint8)ADC_STREAM_COMPLETED == fl_Adc_Result_U8)
    {
        (void)Adc_ReadGroup((Adc_GroupType)AdcConf_AdcGroup_IoHwAbSafe, l_Meet_CIoHwAbSafe_AIn_Voltage);
    }
    if ((uint8)ADC_BUSY != fl_Adc_Result_U8)
    {

        Adc_StartGroupConversion((Adc_GroupType)AdcConf_AdcGroup_IoHwAbSafe);
    }

} /*=====================================================================================================================
  **
  ** Function Name    :  Ioctrlrd_analog_diag_IoHwSafe_ADC_Init
  **
  ** Visibility       :  Public
  **
  ** Description      :  Initialize Converting ADC safe channel buffer
  **
  **
  ** Invocation       :  CMPLIB_INSTANCE(MeetCdd Activation)
  **
  ** Inputs           :
  **
  **
  ** Outputs          :
  **
  **
  ** Critical Section : Yes/No
  **
  **====================================================================================================================*/
void Ioctrlrd_analog_diag_IoHwSafe_ADC_Init(void)
{
    Std_ReturnType fl_Adc_Result_U8;
    fl_Adc_Result_U8 = Adc_GetGroupStatus((Adc_GroupType)AdcConf_AdcGroup_IoHwAbSafe);

    if (ADC_BUSY != fl_Adc_Result_U8)
    {
        (void)Ioctrlrd_analog_Adc_SetupResultBuffer((Adc_GroupType)AdcConf_AdcGroup_IoHwAbSafe, &l_Meet_CIoHwAbSafe_AIn_Voltage[0]);
    }
}

#endif

#ifdef IOCTRL_ANALOG_READ_ALL_ADC
Std_ReturnType Ioctrlrd_analog_diag_read_All_Adc(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType Ret = E_NOT_OK;
    uint8 fl_u8Index;
    uint16 fl_AnalogData[MAX_ADC_CHANNEL_INDEX];
    uint16 fl_TempArray[MAXANALOGPORTS];

    uint16 Read_adc_voltage = 0U;

    for (fl_u8Index = DIDZERO; fl_u8Index < MAX_ADC_CHANNEL_INDEX; fl_u8Index++)
    {
        Ret = MEET_Read_Direct_ANAMap_fun[fl_u8Index].ADC_channel_ReadFunction(&Read_adc_voltage);
        if ((uint8)E_OK == Ret)
        {
            fl_AnalogData[fl_u8Index] = (uint16)Read_adc_voltage;
        }
        else
        {
            break;
        }
    }
    if ((uint8)E_OK == Ret)
    {
        for (fl_u8Index = DIDZERO; fl_u8Index < MAXANALOGPORTS; fl_u8Index++)
        {
            if (fl_u8Index >= MAX_ADC_CHANNEL_INDEX)
            {
                fl_TempArray[fl_u8Index] = DIDZERO;
            }
            else
            {
                fl_TempArray[fl_u8Index] = fl_AnalogData[fl_u8Index];
            }
        }

        for (fl_u8Index = DIDZERO; fl_u8Index < MAXANALOGPORTS; fl_u8Index++)
        {
            /*converting uint16 array to uint8 array*/
            #ifdef IOCTRLRD_ANALOGREAD_RESULT_4BYTES
            *Data = 0u;
            *(Data + DATA_BYTE_1) = 0u;
            *(Data + DATA_BYTE_2) = fl_TempArray[fl_u8Index] >> DIDSHIFT1BYTE;
            *(Data + DATA_BYTE_3) = fl_TempArray[fl_u8Index] & 0xFFU;
            Data += DATA_BYTE_4;
            #else
            *Data = (uint8)(fl_TempArray[fl_u8Index] >> DIDSHIFT1BYTE);
            *(Data + DATA_BYTE_1) = fl_TempArray[fl_u8Index] & 0xFFU;
            Data += DATA_BYTE_2;
            #endif
        }
    }
    else
    {
        ErrorCode[DATA_BYTE_0] = DCM_E_CONDITIONSNOTCORRECT;
        Data[DATA_BYTE_0] = ErrorCode[DATA_BYTE_0];
    }
    return (Ret);
}
#endif

#ifdef IOCTRL_ANALOG_READ_ADC_SINGLE_CH
Std_ReturnType Ioctrlrd_analog_diag_read_Adc_SingleChannel(uint8 channel_id, uint16 *AdcValue)
{
    Std_ReturnType ret = E_NOT_OK;
    ret = Ioctrld_analog_Read_ADC_channel(channel_id, AdcValue);
    return (ret);
}
#endif

#ifdef IOCTRL_FILTER_BYPASS_MODE_ENABLE
Std_ReturnType Ioctrlrd_Filter_Bypass_Mode_STA(uint8 *Data)
{
    Std_ReturnType ret = E_NOT_OK;
    ret = Ioctrlrd_Filter_Bypass_Mode_Adjust(Data);
    return ret;
}

Std_ReturnType Ioctrlrd_Filter_Bypass_Mode_RCTE(uint8 *Data)
{
    Std_ReturnType ret = E_NOT_OK;
    ret = Ioctrlrd_Filter_Bypass_Mode_Return_Ctrl(Data);
    return ret;
}
#endif
/*=====================================================================================================================
**  for each change to this file, be sure to record:
**  1.  who made the change and when the change was made
**  2.  why the change was made and the intended result
**  Following block needs to be repeated for each change
**====================================================================================================================*/
/*=====================================================================================================================
**   Note: In the traceability column we need to trace back to the Design Doc.
**   For the initial version it is traced to the Design Document section.
**   For further changes it shall trace to the source of the change which may
**   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any
**   other reason
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/09/2023
** CDSID             :  mprajapa
** Traceability      :  JIRA 3839
** Change Description:  Upddated identation and MEET Pre-Condition check.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  27/Oct/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1811312
** Change Description:  Coverity/MISRA fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/Sep/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1707104
** Change Description:  Oil Input is Implemented for input calibration
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  03/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1707104
** Change Description:  MeetCdd Coverity-MISRA fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  23/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1634375
** Change Description:  Coverity/MISRA Fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/01/2020
** CDSID             :  dkasiman
** Traceability      :  RTC 1380314
** Change Description:  Coverity/Misra fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  12/12/2019
** CDSID             :  dkasiman
** Traceability      :  RTC 1388229, RTC 1380380 and RTC 1388242
** Change Description:  1.ADC result buffer initialization done via trusted call
**                      2.Correction done to avoid doubling of fuel level resistence.
**                      3.Feul periodic task execution done only in manufacturing mode
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  17/05/2019
** CDSID             :  dkasiman & mganapat
** Traceability      :  RTC 1310400
** Change Description:  Three point fuel measurement added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  11/1/2019
** CDSID             :  athiyag2
** Traceability      :  RTC 1265368
** Change Description:  compiler warning fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  18/march/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1297724
** Change Description:  DutyManipulateWitDecimal and DutyManipulateWithBCD functions moved to mgrdiagcdd.c
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 22/Dec/2018
** CDSID             : dkasiman
** Traceability      : RTC-1258974
** Change Description: Coverity fix done.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  01/11/2018
** CDSID             :  gdhilipr
** Traceability      :  RTC 1229036
** Change Description:  Implementation : Fuel Input Reading - F106
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  05/10/2018
** CDSID             :  gdhilipr
** Traceability      :  RTC 1210657
** Change Description:  Analog input reading by Unit
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  29/09/2018
** CDSID             :  dksiman
** Traceability      :  RTC 1166710
** Change Description:  In ADC start and Stop routine,routine status is updated as per GMSR.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  05/09/2018
** CDSID             :  rkathir1
** Traceability      :  RTC 1190004
** Change Description:  New implementation for handling and read ADC values
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  28/08/2018
** CDSID             :  rkathir1
** Traceability      :  RTC 1185614
** Change Description:  Defect fixed defect324483
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 12/07/2018
** CDSID             : rkathir1
** Traceability      : RTC 1159221
** Change Description: ADC Group wise or individual Channel read function implemented.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 23/05/2018
** CDSID             : rkathir1
** Traceability      : RTC 1113544
** Change Description: Initial version - Ioctrl analog Implementation for Turing Bookshelf.
**====================================================================================================================*/
