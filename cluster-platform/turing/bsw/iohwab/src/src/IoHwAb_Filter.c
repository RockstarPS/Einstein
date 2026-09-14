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
* @file IoHwAb_Filter.c
* @brief Functions for Filtering or processing the IoHwAb signals
* ****************************************************************************/
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/
#include "IoHwAb_Filter.h"
/*To check if Filter is enabled */
#if (IOHWAB_FILTER_ENABLE == STD_ON)
/*****************************************************************************
*  Type Definitions                                              *
******************************************************************************/
/**
* @brief Digital debounce calculation parameters
*/
typedef struct
{
    uint32 raw;               /**< Raw bit             */
    uint32 PreviousRaw;       /**< Old Raw bit         */
    uint32 level;             /**< Debounced State bit */
    uint32 b0_counter;        /**< Counter bit 0       */
    uint32 b1_counter;        /**< Counter bit 1       */
    uint32 b2_counter;        /**< Counter bit 2       */
    uint32 b3_counter;        /**< Counter bit 3       */
    uint32 b4_counter;        /**< Counter bit 4       */
    uint32 b5_counter;        /**< Counter bit 5       */
    uint32 b6_counter;        /**< Counter bit 6       */
    uint32 b7_counter;        /**< Counter bit 7       */
    uint32 DebounceCompletionState;
} IoHwAb_DigitalDebounceType;

/* MISRA C-2012 Rule 2.3 JUSTIFICATION: Type IoHwAb_MovingAvgFilter_DataType is defined as per design. It is used for future purpose.*/
typedef struct
{
    uint32 Sum;
    uint32 Avg;
    uint32 Previous_Avg;
#ifdef IOHWAB_WAIT_INITIAL_COUNT_ENABLED
    uint32 Count;
#endif
} IoHwAb_MovingAvgFilter_DataType;

/* MISRA C-2012 Rule 2.3 JUSTIFICATION: Type IoHwAb_AvgFilter_DataType is defined as per design. It is used for future purpose.*/
typedef struct
{
    uint32 Sum;
    uint8 MArrayPos;
    uint8 FiltArrayStartIndex;
} IoHwAb_AvgFilter_DataType;

#if (IOHWAB_NUM_OF_PT1FILTER > 0U)
/**
* @brief Configuration parameters for PT1 filter calculation
*/
typedef enum
{
    eFilterStatus_NOT_OK,
    eFilterStatus_Initialized,
    eFilterStatus_Calculated
} IoHwAb_Pt1FilterStatusType;

/// @brief This type contains the attributes elements for PT1 filtering.
typedef struct
{
    uint32 FilteredValue;
    /// @brief Damping time constant used for the filtering.
    uint16 DampingTime;
    /// @brief Output value after filtering.
    uint16 OutputValue;
    /// @brief Remainder after the filtering.
    uint16 Remainder;
    /// @brief Current status of the filter.
    IoHwAb_Pt1FilterStatusType Status;
} IoHwAb_Pt1FilterType;
#endif
/*****************************************************************************
*  Private Variable Definitions                                              *
******************************************************************************/

#define IoHwAb_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
/* MISRA C-2012 Rule 20.1 JUSTIFICATION: As per Autosar Standard,IoHwAb_MemMap.h is used to map memory segments in IoHwAb.*/
#include <IoHwAb_MemMap.h>

#if (IOHWAB_NUM_OF_DIGITAL_DEBOUNCE_GROUP > 0U)
static IoHwAb_DigitalDebounceType  IoHwAb_DigitalDebounce[IOHWAB_NUM_OF_DIGITAL_DEBOUNCE_GROUP];
static IoHwAb_DigitalDebounceRefreshCountType IoHwAb_DigitalDebounceRefreshCount[IOHWAB_NUM_OF_DIGITAL_DEBOUNCE_GROUP];
#endif
#if (IOHWAB_NUM_OF_DEBOUNCE > 0U)
static IoHwAb_DebounceType IoHwAb_Debounce[IOHWAB_NUM_OF_DEBOUNCE];
#endif

#if (IOHWAB_NUM_OF_MOVINGAVGFILTER > 0U)
/* Define the movingAvg and filter datatypes*/
static IoHwAb_MovingAvgFilter_DataType IoHwAb_MovingAvgFilter_Info[IOHWAB_NUM_OF_MOVINGAVGFILTER];
#endif

#if (IOHWAB_NUM_OF_AVGFILTER > 0U)
/* Define the Avg32 filter datatypes*/
static IoHwAb_AvgFilter_DataType IoHwAb_AvgFilter_Info[IOHWAB_NUM_OF_AVGFILTER];
/* This buffer hold the data for the mov avg filters*/
static uint32 IoHwAb_Filter_AvgFilter_DataBuffer[IOHWAB_NUM_OF_AVGFILTER_DATAS];
#endif
#if (IOHWAB_NUM_OF_PT1FILTER > 0U)
static IoHwAb_Pt1FilterType IoHwAb_Pt1Filter[IOHWAB_NUM_OF_PT1FILTER];
#endif

#define IoHwAb_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
/* MISRA C-2012 Rule 20.1 JUSTIFICATION: As per Autosar Standard,IoHwAb_MemMap.h is used to map memory segments in IoHwAb. */
#include <IoHwAb_MemMap.h>
/******************************************************************************
*  Private Function Declarations                                                *
*******************************************************************************/
#if (IOHWAB_NUM_OF_DEBOUNCE > 0U)
static void IoHwAb_Filter_Debounce(void);
static void IoHwAb_Filter_DebounceInit(void);
#endif

#if (IOHWAB_NUM_OF_DIGITAL_DEBOUNCE_GROUP > 0U)
static void IoHwAb_Filter_DigitalDebounceInit(void);
static void IoHwAb_Filter_ParallelDebounce(uint8 DebGroupId);
#endif

#if (IOHWAB_NUM_OF_MOVINGAVGFILTER > 0U)
static void IoHwAb_Filter_MovingAvgFilter_Init(void);
#endif
#if (IOHWAB_NUM_OF_AVGFILTER > 0U)
static void IoHwAb_Filter_AvgFilter_Init( void );
#endif
#if (IOHWAB_NUM_OF_PT1FILTER > 0U)
static void IoHwAb_Filter_PT1Filter_Init(void);
static void IoHwAb_Filter_PT1Filter_DeInit(void);
#endif

/******************************************************************************
*  Public Function Definitions                                                *
*******************************************************************************/
#define IoHwAb_START_SEC_CODE
/* MISRA C-2012 Rule 20.1 JUSTIFICATION: As per Autosar Standard,IoHwAb_MemMap.h is used to map memory segments in IoHwAb.*/
#include <IoHwAb_MemMap.h>
/**
* This method initialize the IoHwAb Filter Module
* @param     none
* @return    void
*/
void IoHwAb_Filter_Init(void)
{
    /* Initialize the digital debounce parameters*/
#if (IOHWAB_NUM_OF_DIGITAL_DEBOUNCE_GROUP > 0U)
    IoHwAb_Filter_DigitalDebounceInit();
#endif
    /* Initialize the normal debounce parameters*/
#if (IOHWAB_NUM_OF_DEBOUNCE > 0U)
    IoHwAb_Filter_DebounceInit();
#endif
    /* Initialize the AVG Filter datas*/
#if (IOHWAB_NUM_OF_AVGFILTER > 0U)
    IoHwAb_Filter_AvgFilter_Init();
#endif

    /* Initialize the MOV AVG Filter datas*/
#if (IOHWAB_NUM_OF_MOVINGAVGFILTER > 0U)
    IoHwAb_Filter_MovingAvgFilter_Init();
#endif
#if (IOHWAB_NUM_OF_PT1FILTER > 0U)
    IoHwAb_Filter_PT1Filter_Init();
#endif
}
/**
* This method deinitialize the IoHwAb Filter Module
* @param     none
* @return    void
*/
void IoHwAb_Filter_DeInit(void)
{
    /* Initialize the digital debounce parameters*/
#if (IOHWAB_NUM_OF_DIGITAL_DEBOUNCE_GROUP > 0U)
    IoHwAb_Filter_DigitalDebounceInit();
#endif
    /* Initialize the normal debounce parameters*/
#if (IOHWAB_NUM_OF_DEBOUNCE > 0U)
    IoHwAb_Filter_DebounceInit();
#endif

    /* Initialize the AVG Filter datas*/
#if (IOHWAB_NUM_OF_AVGFILTER > 0U)
    IoHwAb_Filter_AvgFilter_Init();
#endif

    /*Initialize the MOV AVG Filter datas*/
#if (IOHWAB_NUM_OF_MOVINGAVGFILTER > 0U)
    IoHwAb_Filter_MovingAvgFilter_Init();
#endif

#if (IOHWAB_NUM_OF_PT1FILTER > 0U)
    IoHwAb_Filter_PT1Filter_DeInit();
#endif
}
/**
* This method is the main function for IoHwAb filter module
* @param     none
* @return    void
*/
void IoHwAb_Filter_MainFunction(void)
{
    uint8 Index;
    /* Call the parallel debounce api for digital debounce for each debounce group*/
#if (IOHWAB_NUM_OF_DIGITAL_DEBOUNCE_GROUP > 0U)
    for(Index = 0u ; Index < IOHWAB_NUM_OF_DIGITAL_DEBOUNCE_GROUP; Index ++)
    {
        IoHwAb_Filter_ParallelDebounce(Index);
    }
#endif
    /* Call the normal debounce function*/
#if (IOHWAB_NUM_OF_DEBOUNCE > 0U)
    IoHwAb_Filter_Debounce();
#endif
}

#if (IOHWAB_NUM_OF_DIGITAL_DEBOUNCE_GROUP > 0U)
/**
* This method is used to set the digital debounce for inputs
* @param DebGroupId 	- ID of the debounce group
* @param DebChannelId 	- Id of the channel in the debounce group
* @param RawValue 		- Raw value of the input signal
* @return  Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_Filter_SetDigitalDebounce(uint8 DebGroupId, uint8 DebChannelId, boolean RawValue)
{
    Std_ReturnType RetValue = E_NOT_OK;

    /* Condition to check the maximum debounce group and debounce channel per group*/
    if((DebGroupId < IOHWAB_NUM_OF_DIGITAL_DEBOUNCE_GROUP)&&(DebChannelId<IOHWAB_NUM_OF_MAX_DIGDEBCHANNELS_PERGROUP))
    {
        if(RawValue != (boolean)0u)
        {
            /* Set the specific bit for each input when raw value is 1*/
            IoHwAb_DigitalDebounce[DebGroupId].raw |= ((uint32)1U << DebChannelId);
        }
        else
        {
            /* Clear the specific bit for each input when raw value is 0*/
            IoHwAb_DigitalDebounce[DebGroupId].raw &= ~((uint32)1U << DebChannelId);
        }
        RetValue = E_OK;
    }

    return RetValue;
}

/**
* This method is used to get the digital debounce for inputs
* @param DebGroupId 	- ID of the debounce group
* @param DebChannelId 	- Id of the channel in the debounce group
* @param DebounceValue 	- pointer to get the debounced value
* @return  Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_Filter_GetDigitalDebounceValue(uint8 DebGroupId, uint8 DebChannelId, boolean *DebounceValue)
{
    Std_ReturnType RetValue = E_NOT_OK;
    uint32 Temp;
    /* Condition to check the maximum debounce group and debounce channel per group*/
    if((DebGroupId < IOHWAB_NUM_OF_DIGITAL_DEBOUNCE_GROUP)&&(DebChannelId<IOHWAB_NUM_OF_MAX_DIGDEBCHANNELS_PERGROUP))
    {
        Temp = IoHwAb_DigitalDebounce[DebGroupId].level >> DebChannelId;
        Temp = Temp & (uint32)0x01;

        if(0U != Temp)
        {
            *DebounceValue = (boolean)TRUE;
        }
        else
        {
            *DebounceValue = (boolean)FALSE;
        }
        Temp = IoHwAb_DigitalDebounce[DebGroupId].DebounceCompletionState >> DebChannelId;
        Temp = Temp & (uint32)0x01;
        if(0U != Temp)
        {
            /* Get the debounced input from the specfic debounce group*/
            RetValue = E_OK;
        }
    }

    return RetValue;
}

/**
* This method is the used to initialize the digital debounce
* @param     none
* @return    void
*/
static void IoHwAb_Filter_DigitalDebounceInit(void)
{
    uint16 Index;

    for(Index = 0u ; Index < IOHWAB_NUM_OF_DIGITAL_DEBOUNCE_GROUP; Index ++)
    {
        IoHwAb_DigitalDebounceRefreshCountType * const Refreshptr = &IoHwAb_DigitalDebounceRefreshCount[Index];
        const IoHwAb_DigitalDebounceOffCountType * const Offptr = &IoHwAb_DigitalDebounceOffCount[Index];

        /* Initialize the digital debounce parameters*/
        IoHwAb_DigitalDebounce[Index].raw = 0u;
        IoHwAb_DigitalDebounce[Index].level = 0u;
        IoHwAb_DigitalDebounce[Index].DebounceCompletionState = 0u;

        /* As the signal Init Value is configured to OFF state,  Load the Counter's to OFF Debounce values*/
        IoHwAb_DigitalDebounce[Index].b0_counter = Offptr->b0_counter_Off_restart;
        IoHwAb_DigitalDebounce[Index].b1_counter = Offptr->b1_counter_Off_restart;
        IoHwAb_DigitalDebounce[Index].b2_counter = Offptr->b2_counter_Off_restart;
        IoHwAb_DigitalDebounce[Index].b3_counter = Offptr->b3_counter_Off_restart;
        IoHwAb_DigitalDebounce[Index].b4_counter = Offptr->b4_counter_Off_restart;
        IoHwAb_DigitalDebounce[Index].b5_counter = Offptr->b5_counter_Off_restart;
        IoHwAb_DigitalDebounce[Index].b6_counter = Offptr->b6_counter_Off_restart;
        IoHwAb_DigitalDebounce[Index].b7_counter = Offptr->b7_counter_Off_restart;

        /* Initialize the refresh count with OFF counters*/
        Refreshptr->b0_counter_Refresh = Offptr->b0_counter_Off_restart;
        Refreshptr->b1_counter_Refresh = Offptr->b1_counter_Off_restart;
        Refreshptr->b2_counter_Refresh = Offptr->b2_counter_Off_restart;
        Refreshptr->b3_counter_Refresh = Offptr->b3_counter_Off_restart;
        Refreshptr->b4_counter_Refresh = Offptr->b4_counter_Off_restart;
        Refreshptr->b5_counter_Refresh = Offptr->b5_counter_Off_restart;
        Refreshptr->b6_counter_Refresh = Offptr->b6_counter_Off_restart;
        Refreshptr->b7_counter_Refresh = Offptr->b7_counter_Off_restart;
    }

}
/**
* This method will debounce the digital inputs and store the result to the debounce group
* @param     DebGroupId		- Id of the debounce group
* @return    void
*/
static void IoHwAb_Filter_ParallelDebounce(uint8 DebGroupId)
{
    uint32 uLv = 0u;
    uint32 DebounceState = 0u;
    uint32 Difference = 0u;
    uint32 CounterUpdateBits = 0u;
    uint32 CounterExpiryStatus = 0xFFFFFFFFu;
    if (DebGroupId < IOHWAB_NUM_OF_DIGITAL_DEBOUNCE_GROUP)
    {
        IoHwAb_DigitalDebounceType * const dptr = &IoHwAb_DigitalDebounce[DebGroupId];
        const IoHwAb_DigitalDebounceOnCountType * const Onptr = &IoHwAb_DigitalDebounceOnCount[DebGroupId];
        const IoHwAb_DigitalDebounceOffCountType * const Offptr = &IoHwAb_DigitalDebounceOffCount[DebGroupId];
        IoHwAb_DigitalDebounceRefreshCountType * const Refreshptr = &IoHwAb_DigitalDebounceRefreshCount[DebGroupId];

        /* Generate the differences by Comparing the Current & Previous Raw values and store it in Difference*/
        /* Difference will hold 1 if there is any signal value changes*/
        Difference   =   dptr->raw ^ dptr->PreviousRaw;

        /*
         * Increment the counters for N-in-a-row debounce:
         */
        dptr->b7_counter ^=  (dptr->b6_counter) & (dptr->b5_counter) & (dptr->b4_counter) & (dptr->b3_counter) & (dptr->b2_counter) & (dptr->b1_counter) & (dptr->b0_counter);
        dptr->b6_counter ^=  (dptr->b5_counter) & (dptr->b4_counter) & (dptr->b3_counter) & (dptr->b2_counter) & (dptr->b1_counter) & (dptr->b0_counter);
        dptr->b5_counter ^=  (dptr->b4_counter) & (dptr->b3_counter) & (dptr->b2_counter) & (dptr->b1_counter) & (dptr->b0_counter);
        dptr->b4_counter ^=  (dptr->b3_counter) & (dptr->b2_counter) & (dptr->b1_counter) & (dptr->b0_counter);
        dptr->b3_counter ^=  (dptr->b2_counter) & (dptr->b1_counter) & (dptr->b0_counter);
        dptr->b2_counter ^=  (dptr->b1_counter) & (dptr->b0_counter);
        dptr->b1_counter ^=  (dptr->b0_counter);
        dptr->b0_counter  =  (~( dptr->b0_counter ));

        /* Retrieve the list of signals for which Counter Expired and Debouncing completed*/
        DebounceState = (dptr->b7_counter) | (dptr->b6_counter) | (dptr->b5_counter) | (dptr->b4_counter) | (dptr->b3_counter) | (dptr->b2_counter) | (dptr->b1_counter) | (dptr->b0_counter);
        DebounceState = (~( DebounceState ));

        /* Update the Debounce completed status*/
        dptr->DebounceCompletionState = ((dptr->DebounceCompletionState) | (DebounceState));

        /* Update the Counter Expired Status for all the signals. For the counter expired signals, the corresponding bit would be zero in CounterExpiryStatus*/
        CounterExpiryStatus = ( dptr->b0_counter|dptr->b1_counter|dptr->b2_counter|dptr->b3_counter|dptr->b4_counter|dptr->b5_counter|dptr->b6_counter|dptr->b7_counter);

        /* Reset the Current level of the signals for those counter has expired*/
        uLv = (dptr->level & CounterExpiryStatus);

        /* Update the Counter Expired Status for all the signals. For the counter expired signals, the corresponding bit would be One in CounterExpiryStatus*/
        CounterExpiryStatus         =  (~(CounterExpiryStatus));

        /* Update the Debounced Level of the signals for which counter expired and debouncing completed without disturbing other signals levels*/
        dptr->level  =  ( uLv | ((CounterExpiryStatus) & ((dptr->raw) ^ Difference)));

        /* Counter needs to be reloaded for the raw value or level changed signals and counter expired signals. Capture all those signals*/
        CounterUpdateBits = (CounterExpiryStatus | Difference);


        /* Load the ON/OFF debouning Values of corresponding Raw Values to reload the counter*/
        Refreshptr->b0_counter_Refresh = (Onptr->b0_counter_On_restart & dptr->raw);
        Refreshptr->b1_counter_Refresh = (Onptr->b1_counter_On_restart & dptr->raw);
        Refreshptr->b2_counter_Refresh = (Onptr->b2_counter_On_restart & dptr->raw);
        Refreshptr->b3_counter_Refresh = (Onptr->b3_counter_On_restart & dptr->raw);
        Refreshptr->b4_counter_Refresh = (Onptr->b4_counter_On_restart & dptr->raw);
        Refreshptr->b5_counter_Refresh = (Onptr->b5_counter_On_restart & dptr->raw);
        Refreshptr->b6_counter_Refresh = (Onptr->b6_counter_On_restart & dptr->raw);
        Refreshptr->b7_counter_Refresh = (Onptr->b7_counter_On_restart & dptr->raw);

        Refreshptr->b0_counter_Refresh |= (Offptr->b0_counter_Off_restart & (~(dptr->raw)));
        Refreshptr->b1_counter_Refresh |= (Offptr->b1_counter_Off_restart & (~(dptr->raw)));
        Refreshptr->b2_counter_Refresh |= (Offptr->b2_counter_Off_restart & (~(dptr->raw)));
        Refreshptr->b3_counter_Refresh |= (Offptr->b3_counter_Off_restart & (~(dptr->raw)));
        Refreshptr->b4_counter_Refresh |= (Offptr->b4_counter_Off_restart & (~(dptr->raw)));
        Refreshptr->b5_counter_Refresh |= (Offptr->b5_counter_Off_restart & (~(dptr->raw)));
        Refreshptr->b6_counter_Refresh |= (Offptr->b6_counter_Off_restart & (~(dptr->raw)));
        Refreshptr->b7_counter_Refresh |= (Offptr->b7_counter_Off_restart & (~(dptr->raw)));

        /* Clear the existing counter values for which counter needs to be reloaded*/
        dptr->b0_counter &= (~(CounterUpdateBits));
        dptr->b1_counter &= (~(CounterUpdateBits));
        dptr->b2_counter &= (~(CounterUpdateBits));
        dptr->b3_counter &= (~(CounterUpdateBits));
        dptr->b4_counter &= (~(CounterUpdateBits));
        dptr->b5_counter &= (~(CounterUpdateBits));
        dptr->b6_counter &= (~(CounterUpdateBits));
        dptr->b7_counter &= (~(CounterUpdateBits));

        /* Reload the counter values for the counter expired and pin level changed signals*/
        dptr->b0_counter |= (CounterUpdateBits & Refreshptr->b0_counter_Refresh);
        dptr->b1_counter |= (CounterUpdateBits & Refreshptr->b1_counter_Refresh);
        dptr->b2_counter |= (CounterUpdateBits & Refreshptr->b2_counter_Refresh);
        dptr->b3_counter |= (CounterUpdateBits & Refreshptr->b3_counter_Refresh);
        dptr->b4_counter |= (CounterUpdateBits & Refreshptr->b4_counter_Refresh);
        dptr->b5_counter |= (CounterUpdateBits & Refreshptr->b5_counter_Refresh);
        dptr->b6_counter |= (CounterUpdateBits & Refreshptr->b6_counter_Refresh);
        dptr->b7_counter |= (CounterUpdateBits & Refreshptr->b7_counter_Refresh);

        /* Update the current value to previous raw value to detect the raw value changes in the next iteration*/
        dptr->PreviousRaw = dptr->raw;
    }
}


#endif

#if (IOHWAB_NUM_OF_RES_CALC > 0U)
/**
* This method is used to calculate the resolution of a signal
* @param ResolutionCalcId 	- ID of the resolution channel
* @param RawValue 			- Rawvalue of the signal
* @param CalcValue 			- Pointer to get the calculated value
* @return  Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_Filter_ResolutionCalc(uint8 ResolutionCalcId, uint32 RawValue, sint32* CalcValue)
{

    Std_ReturnType RetValue= E_NOT_OK;
    uint64 calresult= 0;

    if(ResolutionCalcId < IOHWAB_NUM_OF_RES_CALC)
    {
        /*To check whether the divisor is not equal to zero*/
        if(IoHwAb_ResoultionCalcCfg[ResolutionCalcId].ResolutionDivisor != 0U)
        {
            /*Perform the resolution calculation*/
            /* MISRA C-2012 Rule 10.4 JUSTIFICATION: The values are verified and does not have negative functional impact as the value of IoHwAb_ResoultionCalcCfg[ResolutionCalcId].Offset is not negative.*/
            /* MISRA C-2012 Rule 10.8 JUSTIFICATION: The values are verified and it does not exceed the limit of calresult. Hence does not have functional impact.*/
            calresult  =((uint64)(RawValue + IoHwAb_ResoultionCalcCfg[ResolutionCalcId].Offset)* IoHwAb_ResoultionCalcCfg[ResolutionCalcId].ResolutionMultiplier)/(uint64)IoHwAb_ResoultionCalcCfg[ResolutionCalcId].ResolutionDivisor;

            *CalcValue = (sint32)calresult;

            RetValue = E_OK;
        }
    }

    return RetValue;

}
#endif

#if (IOHWAB_NUM_OF_DEBOUNCE > 0U)

/**
* This method is used to set the digital debounce for inputs
* @param DebounceId 	- ID of the debounce channel
* @param RawValue 		- Raw value of the input signal
* @return  Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_Filter_SetDebounce(uint8 DebounceId, uint32 RawValue)
{

    Std_ReturnType RetValue = E_NOT_OK;

    if(DebounceId < IOHWAB_NUM_OF_DEBOUNCE )
    {
        /* Set the Raw value as new value for debounce*/
        IoHwAb_Debounce[DebounceId].NewValue = RawValue;
        RetValue = E_OK;
    }

    return RetValue;

}

/**
* This method is used to get the normal debounced value
* @param DebounceId 	- ID of the debounce channel
* @param DebounceValue 	- pointer to get the debounced value
* @return  Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_Filter_GetDebounceValue(uint8 DebounceId, uint32 *DebounceValue)
{

    Std_ReturnType RetValue = E_NOT_OK;

    if(DebounceId < IOHWAB_NUM_OF_DEBOUNCE )
    {

        /* Update the processed value*/
        *DebounceValue = (uint32)IoHwAb_Debounce[DebounceId].DebounceValue;

        /* Return OK only when debounce state is set TRUE at least once*/
        if(IoHwAb_Debounce[DebounceId].DebounceState != 0U)
        {
            RetValue = E_OK;
        }
    }

    return RetValue;
}
/**
* This method is the used to initialize the normal debounce
* @param     none
* @return    void
*/
static void IoHwAb_Filter_DebounceInit(void)
{

    uint16 Index;
    /* Initialize the normal debounce parameters*/
    for(Index = 0u ; Index < IOHWAB_NUM_OF_DEBOUNCE; Index ++)
    {
        IoHwAb_Debounce[Index] = IoHwAb_DebounceInit[Index];
    }
}
/**
* This method will debounce the normal inputs and store the result to the debounce array
* @param     none
* @return    void
*/
static void IoHwAb_Filter_Debounce(void)
{
    uint16 Index;

    for(Index = 0u ; Index < IOHWAB_NUM_OF_DEBOUNCE; Index ++)
    {
        if(IoHwAb_Debounce[Index].NewValue == IoHwAb_Debounce[Index].PreviousValue)
        {
            /* Increment debounce count*/
            IoHwAb_Debounce[Index].Count++;
            /* polyspace<RTE: OBAI > Context index doesn't exceed range values.*/
            if(IoHwAb_Debounce[Index].Count >= IoHwAb_DebounceCfg[Index].DebounceCount)
            {
                IoHwAb_Debounce[Index].DebounceValue =IoHwAb_Debounce[Index].NewValue;
                IoHwAb_Debounce[Index].Count = 0U;
                /* Update the debounce state if debounce is completed atleast once*/
                IoHwAb_Debounce[Index].DebounceState = 1U;
            }
        }
        else
        {
            /* Clear the count and update the prev value with new value when both are different*/
            IoHwAb_Debounce[Index].Count = 0U;
            IoHwAb_Debounce[Index].PreviousValue = IoHwAb_Debounce[Index].NewValue;
        }
    }
}

#endif

#if (IOHWAB_NUM_OF_ENCODED > 0U)
/**
* This method is used for encoding the signals
* @param EncodeId 			- ID of the encoding channel
* @param RawValue 			- RawValue of the signal
* @param EncodedValue 		- Pointer to get the encoded value
* @return  Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_Filter_Encoded(uint8 EncodeId, uint32 RawValue, uint32* EncodedValue)
{


    Std_ReturnType RetValue = E_NOT_OK;
    uint16 Index;

    if(EncodeId < IOHWAB_NUM_OF_ENCODED )
    {
        for(Index = 0u ; Index < IoHwAb_EncodedCfg[EncodeId].RangeCount; Index ++)
        {
            /* Check the encoded range for each input signal*/
            if( (RawValue <= IoHwAb_EncodedCfg[EncodeId].EncodedRange[Index].EncodedMax) && (RawValue >= IoHwAb_EncodedCfg[EncodeId].EncodedRange[Index].EncodedMin) )
            {
                /* Update the encoded value with index value*/
                *EncodedValue =  Index + 1u;
                break;
            }
            else
            {
                /* Update as zero when input is out of range*/
                *EncodedValue = 0u;
            }
        }
        RetValue = E_OK;
    }

    return RetValue;
}
#endif


#if (IOHWAB_NUM_OF_MOVINGAVGFILTER > 0U)
/**
* This Function will initialize the number of configured moving avg buffers.
* @return  Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
static void IoHwAb_Filter_MovingAvgFilter_Init(void)
{
    uint8 Tmpcount;

    /* Initialize the moving avg filter data buffer*/
    for(Tmpcount = 0 ; Tmpcount< IOHWAB_NUM_OF_MOVINGAVGFILTER; Tmpcount++)
    {
        IoHwAb_MovingAvgFilter_Info[Tmpcount].Sum = 0u;
        IoHwAb_MovingAvgFilter_Info[Tmpcount].Avg = 0u;
        IoHwAb_MovingAvgFilter_Info[Tmpcount].Previous_Avg = 0u;
#ifdef IOHWAB_WAIT_INITIAL_COUNT_ENABLED
        IoHwAb_MovingAvgFilter_Info[Tmpcount].Count = 0u;
#endif
    }


}
#ifdef IOHWAB_WAIT_INITIAL_COUNT_ENABLED
/**
* This Function will initialize the count value of moving avg buffers.
* @return  void
*/
void IoHwAb_Filter_MovingAvgFilter_Count_Init (void)
{
    uint8 Tmpcount = 0U;

    /* Initialize the moving avg filter count value*/
    for(Tmpcount = 0U ; Tmpcount< IOHWAB_NUM_OF_MOVINGAVGFILTER; Tmpcount++)
    {
        IoHwAb_MovingAvgFilter_Info[Tmpcount].Count = 0u;
    }
}
#endif
/**
* This Function is used to find the moving avg value for the inputs.
* @param FilterCfgIx 		- Filter configuration index
* @param NewValue 			- new raw data
* @param pFilteredValue 	- Filtered output to application
* @return  Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_Filter_MovingAvgFilter(const uint8 FilterCfgIx, const uint32 NewValue, uint32 * const pFilteredValue)
{
    Std_ReturnType Ret = E_NOT_OK;

    if(FilterCfgIx < IOHWAB_NUM_OF_MOVINGAVGFILTER)
    {
        if(IoHwAb_MovingAvgFilter_Info[FilterCfgIx].Previous_Avg != 0U)
        {
            IoHwAb_MovingAvgFilter_Info[FilterCfgIx].Sum = IoHwAb_MovingAvgFilter_Info[FilterCfgIx].Sum - IoHwAb_MovingAvgFilter_Info[FilterCfgIx].Avg + NewValue;
            IoHwAb_MovingAvgFilter_Info[FilterCfgIx].Avg = IoHwAb_MovingAvgFilter_Info[FilterCfgIx].Sum / IoHwAb_Filter_MovingAvgFilter_Cfg[FilterCfgIx].Count;
            IoHwAb_MovingAvgFilter_Info[FilterCfgIx].Previous_Avg = IoHwAb_MovingAvgFilter_Info[FilterCfgIx].Avg;
        }
        else
        {
            IoHwAb_MovingAvgFilter_Info[FilterCfgIx].Avg = NewValue;
            IoHwAb_MovingAvgFilter_Info[FilterCfgIx].Previous_Avg = NewValue;
            IoHwAb_MovingAvgFilter_Info[FilterCfgIx].Sum = NewValue * IoHwAb_Filter_MovingAvgFilter_Cfg[FilterCfgIx].Count;
        }

        *pFilteredValue = IoHwAb_MovingAvgFilter_Info[FilterCfgIx].Avg;
        Ret = E_OK;

#ifdef IOHWAB_WAIT_INITIAL_COUNT_ENABLED
        if(IoHwAb_MovingAvgFilter_Info[FilterCfgIx].Count<IoHwAb_Filter_MovingAvgFilter_Cfg[FilterCfgIx].Count)
        {
            Ret = E_NOT_OK;
            IoHwAb_MovingAvgFilter_Info[FilterCfgIx].Count++;

        }
#endif

    }
    return Ret;

}

#endif


#if (IOHWAB_NUM_OF_AVGFILTER > 0U)
//----------------------------------------------------------------------------------------------------------------------
/// @brief   * This Function will initialize the number of configured avg filter buffers.
///
/// @return   None
//----------------------------------------------------------------------------------------------------------------------
static void IoHwAb_Filter_AvgFilter_Init( void )
{
    uint8 Index;
#if (IOHWAB_NUM_OF_AVGFILTER > 1U)
    uint8 Tmpcount;
    uint8 TmpIndexCal;
#endif


    /* Initialize the avf filter data buffers*/
    for(Index = 0 ; Index< IOHWAB_NUM_OF_AVGFILTER; Index++)
    {
        IoHwAb_AvgFilter_Info[Index].Sum                 = 0u;
#if (IOHWAB_NUM_OF_AVGFILTER > 1U)
        if(Index >= 1)
        {
            TmpIndexCal = Index - 1u;
            Tmpcount = IoHwAb_Filter_AvgFilter_Cfg[TmpIndexCal].Count;
            IoHwAb_AvgFilter_Info[Index].FiltArrayStartIndex = (IoHwAb_AvgFilter_Info[Index - 1].FiltArrayStartIndex + Tmpcount);
        }
        else
#endif
        {
            IoHwAb_AvgFilter_Info[Index].FiltArrayStartIndex = 0u;
        }
        IoHwAb_AvgFilter_Info[Index].MArrayPos           = IoHwAb_AvgFilter_Info[Index].FiltArrayStartIndex;

    }

    /* Initialize the data buffer*/
    for(Index = 0 ; Index< IOHWAB_NUM_OF_AVGFILTER_DATAS; Index++)
    {
        IoHwAb_Filter_AvgFilter_DataBuffer[Index] = 0u;

    }

}



/**
* This Function is used to find the avg value for the inputs.
* @param FilterCfgIx 	    - Indicate the filter index
* @param NewValue 			- New raw value which is to be filtered
* @param pFilteredValue 	- Result of the filtered value
* @return  Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_Filter_AvgFilter(const uint8 FilterCfgIx, const uint32 NewValue, uint32 * const pFilteredValue)
{

    Std_ReturnType Ret;
    uint32 PresentData;
    uint8 PresentIndex;

    Ret = E_NOT_OK;
    *pFilteredValue = 0;

    if(FilterCfgIx < IOHWAB_NUM_OF_AVGFILTER)
    {
        PresentIndex = IoHwAb_AvgFilter_Info[FilterCfgIx].MArrayPos;

        /* check the validity*/
        if((PresentIndex < (uint8)(IoHwAb_AvgFilter_Info[FilterCfgIx].FiltArrayStartIndex + IoHwAb_Filter_AvgFilter_Cfg[FilterCfgIx].Count))&&(PresentIndex >= IoHwAb_AvgFilter_Info[FilterCfgIx].FiltArrayStartIndex))
        {
            /* add new value to sum of numbers in filter*/
            IoHwAb_AvgFilter_Info[FilterCfgIx].Sum += NewValue;

            PresentData = IoHwAb_Filter_AvgFilter_DataBuffer[PresentIndex];


            IoHwAb_AvgFilter_Info[FilterCfgIx].Sum -= PresentData;

            IoHwAb_Filter_AvgFilter_DataBuffer[PresentIndex] = NewValue;

            /* move to next position in array*/
            IoHwAb_AvgFilter_Info[FilterCfgIx].MArrayPos = IoHwAb_AvgFilter_Info[FilterCfgIx].MArrayPos +1u;

            /* if end of array is reached, start from beginning*/
            if ( IoHwAb_AvgFilter_Info[FilterCfgIx].MArrayPos >= (IoHwAb_AvgFilter_Info[FilterCfgIx].FiltArrayStartIndex + IoHwAb_Filter_AvgFilter_Cfg[FilterCfgIx].Count))
            {
                IoHwAb_AvgFilter_Info[FilterCfgIx].MArrayPos = IoHwAb_AvgFilter_Info[FilterCfgIx].FiltArrayStartIndex;
            }


            /* calculate average value*/
            *pFilteredValue = (uint32)( IoHwAb_AvgFilter_Info[FilterCfgIx].Sum /IoHwAb_Filter_AvgFilter_Cfg[FilterCfgIx].Count );

            Ret = E_OK;
        }

    }
    else
    {
        Ret = E_INVALID_ARG;
    }

    return Ret;

}

#endif


#if ((IOHWAB_NUM_OF_MOVINGAVGFILTER > 0U) || (IOHWAB_NUM_OF_AVGFILTER > 0U))
//----------------------------------------------------------------------------------------------------------------------
/// @brief    This operation is used to reset the mentioned filter data buffers
///
/// @param    FilterName    : Indicate which filter buffer datas need to be cleared
/// @param    FilterIndexId : Indicate the particular index for the data buffer
///
/// @return   Std_ReturnType: E_OK-Operation successful, E_NOT_OK-Operation failure
///
///
//----------------------------------------------------------------------------------------------------------------------
Std_ReturnType IoHwAb_Filter_ResetFilter(EFilterMethod FilterName, uint8 FilterIndexId)
{
    Std_ReturnType Result;

    Result = E_NOT_OK;

    if(FilterName < eFilter_Max)
    {

        switch(FilterName)
        {
        case eFilter_MovingAvg:
#if (IOHWAB_NUM_OF_MOVINGAVGFILTER > 0U)
            if(FilterIndexId < IOHWAB_NUM_OF_MOVINGAVGFILTER)
#endif
            {
#if (IOHWAB_NUM_OF_MOVINGAVGFILTER > 0U)
                IoHwAb_MovingAvgFilter_Info[FilterIndexId].Sum = 0u;
                IoHwAb_MovingAvgFilter_Info[FilterIndexId].Avg = 0u;
                IoHwAb_MovingAvgFilter_Info[FilterIndexId].Previous_Avg = 0u;
#endif
                Result = E_OK;
            }
            break;

        case  eFilter_Avg:
#if (IOHWAB_NUM_OF_AVGFILTER > 0U)
            if(FilterIndexId < IOHWAB_NUM_OF_AVGFILTER)
            {
                IoHwAb_AvgFilter_Info[FilterIndexId].Sum                 = 0u;
                IoHwAb_AvgFilter_Info[FilterIndexId].MArrayPos           = IoHwAb_AvgFilter_Info[FilterIndexId].FiltArrayStartIndex;

                Result = E_OK;
            }
#endif
            break;

        default:
            Result = E_NOT_OK;
            break;
        }
    }
    else
    {
        Result = E_INVALID_ARG;
    }

    return Result;
}
#endif

#if (IOHWAB_NUM_OF_PT1FILTER > 0U)
/**
* This Function will initialize the number of configured PT1 buffers.
*/
static void IoHwAb_Filter_PT1Filter_Init(void)
{
    uint8 Index;

    for(Index=0; Index < IOHWAB_NUM_OF_PT1FILTER; Index++)
    {
        IoHwAb_Pt1Filter[Index].FilteredValue = 0uL;
        IoHwAb_Pt1Filter[Index].Remainder = 0U;
        IoHwAb_Pt1Filter[Index].OutputValue = IoHwAb_Filter_PT1Filter_Cfg[Index].InitValue;
        IoHwAb_Pt1Filter[Index].DampingTime = IoHwAb_Filter_PT1Filter_Cfg[Index].DampingConstant;
        IoHwAb_Pt1Filter[Index].Status = eFilterStatus_Initialized;
    }

}


/**
* This Function will De - initialize the number of configured PT1 buffers.
*/
static void IoHwAb_Filter_PT1Filter_DeInit(void)
{
    uint8 Index = 0U;

    for(Index=0; Index < IOHWAB_NUM_OF_PT1FILTER; Index++)
    {
        IoHwAb_Pt1Filter[Index].FilteredValue = 0uL;
        IoHwAb_Pt1Filter[Index].Remainder = 0U;
        IoHwAb_Pt1Filter[Index].OutputValue = 0U;
        IoHwAb_Pt1Filter[Index].DampingTime = 0U;
        IoHwAb_Pt1Filter[Index].Status = eFilterStatus_NOT_OK;
    }

}

/*
* @return  Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/

Std_ReturnType IoHwAb_Filter_PT1Filter(const uint8 Pt1Index, const uint32 NewValue, uint32 * const pFilteredValue)
{
    Std_ReturnType Result;

    Result = E_NOT_OK;
    uint32 Temp;
    uint32 DmpTime;
    if (Pt1Index < IOHWAB_NUM_OF_PT1FILTER)
    {
        if ((IoHwAb_Pt1Filter[Pt1Index].Status == eFilterStatus_Initialized) || (IoHwAb_Pt1Filter[Pt1Index].Status == eFilterStatus_Calculated))
        {
            DmpTime = (uint32)IoHwAb_Pt1Filter[Pt1Index].DampingTime;

            Temp = (uint32)IoHwAb_Pt1Filter[Pt1Index].OutputValue * DmpTime;

            Temp += (uint32)NewValue + (uint32)(IoHwAb_Pt1Filter[Pt1Index].Remainder);

            ++DmpTime;

            IoHwAb_Pt1Filter[Pt1Index].OutputValue = (uint16)(Temp / DmpTime);

            *pFilteredValue = IoHwAb_Pt1Filter[Pt1Index].OutputValue;

            IoHwAb_Pt1Filter[Pt1Index].Remainder = (uint16)(Temp % DmpTime);

            IoHwAb_Pt1Filter[Pt1Index].Status = eFilterStatus_Calculated;
        }
        else
        {
            *pFilteredValue = IoHwAb_Pt1Filter[Pt1Index].OutputValue;
        }
        Result = E_OK;
    }
    return Result;
}

#endif
#define IoHwAb_STOP_SEC_CODE
/* MISRA C-2012 Rule 20.1 JUSTIFICATION: As per Autosar Standard,IoHwAb_MemMap.h is used to map memory segments in IoHwAb.*/
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
/*****************************************************************************
Date              :22-Aug-2018
By                :pragesh
Traceability      :RTC-1181436:MMC: Safe IoHwAb Delivery
Change Description:Initial Version for IoHwAb safe implementation
******************************************************************************/
/*****************************************************************************
Date              :20-NOV-2018
By                :nrajaman
Traceability      :1206553: Hyundai SP2: PIC component upgrade for ASIL compliance.
Change Description:Added below filter functions:
                    1. IoHwAb_Filter_MovingAvgFilter
                    2. IoHwAb_Filter_AvgFilter
******************************************************************************/
/*****************************************************************************
Date              :23-Nov-2018
By                :bbaskara
Traceability      :RTC-1243011: MMC: IohwAb safe MISRA Fix
Change Description:Fixed MISRA warning.
******************************************************************************/
/*****************************************************************************
Date              :22-Mar-2019
By                :asivalin
Traceability      :RTC-1302411: Hyundai SP2: [Hyundai_SP2 Color] Battery charge TT HW pin
				   (with OFF condition) throws ERROR status upon battery connect in Normal mode (461677)
Change Description:IoHwAb Digital Debounce Logic Update
******************************************************************************/
/*****************************************************************************
Date              :14-May-2019
By                :msavariy
Traceability      :1323692: Bookshelf Safe component PT1 Filter Implementation
Change Description: Added support for PT1 Filtering for Analog Inputs
******************************************************************************/
/*****************************************************************************
Date              :10-May-2021
By                :akv
Traceability      :1313296: Compilation Warnings observed in PF team Components.
Change Description: Check added with macro.compilation warning fixed.
******************************************************************************/
/*****************************************************************************
Date              :15-Jul-2021
By                :praj1
Traceability      :1368377: Cluster backlight ramps up to 100% over time period
					of about 55seconds.  should ramp faster than that
Change Description: IOHWAB fliter wait to send adc err ok until TFT ON
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
