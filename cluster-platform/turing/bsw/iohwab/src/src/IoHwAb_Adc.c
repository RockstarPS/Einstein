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
* @file IoHwAb_Adc.c
* @brief Capturing and processing of analog input signals
* ****************************************************************************/
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/

#include "IoHwAb_Adc.h"
#include "IoHwAb_Filter.h"
#include "IoHwAb_Gpt.h"
#include "Rte_IoHwAb.h"
/*To check if Analog Input is enabled*/
#if (IOHWAB_ADC_ENABLE == STD_ON)
/******************************************************************************
*  Type Definitions                                               *
*******************************************************************************/

typedef enum
{
    IOHWAB_ADC_JOB_OK,
    IOHWAB_ADC_JOB_ERROR
} IoHwAb_AdcJobResult;

typedef enum
{
    IOHWAB_ADC_BUFFER_NOT_INITIALISED,
    IOHWAB_ADC_BUFFER_INITIALISED,
    IOHWAB_ADC_CONVERSION_STARTED,
    IOHWAB_ADC_CONVERSION_COMPLETED,
    IOHWAB_ADC_MAX_STATE
} IoHwAb_AdcProcessStatusType;


typedef enum
{
    eAdcMux_Idle,
    eAdcMux_InProgressTimer,
    eAdcMux_InProgressADC,
    eAdcMux_NotInit,
    eAdcMux_ErrParam,
    eAdcMux_ErrTmOut,
    eAdcMux_ErrReadGroup,
} AdcMuxState_t;


/**
* @brief This structure defines different status variables of adc adapter
*/
typedef struct
{
    uint8                           AdcVariantId;                       /**<  Adc varient Id*/
    IoHwAb_AdcProcessStatusType     MultiChannelAdcReadStatus[IOHWAB_NUM_ADC_GROUP];          /**<  Adc read status*/
} IoHwAb_AdcStatusType;

/**
* @brief This structure defines value types for adc input
*/
typedef struct
{
    sint32 ProcessedValue;	        /**< Variable to store the processed value of adc signal */
    uint16 RawValue;                /**< Variable to store the raw value of adc signal */
    IoHwAb_AdcJobResult JobResult;
} IoHwAb_AdcResultType;

/******************************************************************************
*  Private Variable Definitions                                               *
*******************************************************************************/
#define IoHwAb_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include <IoHwAb_MemMap.h>

#define IOHWAB_START_SEC_NOCACHE_DATA
#include <IoHwAb_MemMap.h>
/**
* @brief This structure defines result type for adc input
*/

/* MISRA C-2012 Rule 8.9 JUSTIFICATION: The declaration AdcGroupBuffer will be used by other functions in future.*/
static Adc_ValueGroupType AdcGroupBuffer[IOHWAB_NUM_ADC_INPUT];        /**<  Buffer for storing the group of adc signals*/

#if (IOHWAB_ADC_TIMEOUT_ENABLE == STD_ON)

static uint16 AsyncConvTimeOutCount[IOHWAB_NUM_ADC_GROUP] = {0u};
static boolean flgConversionStarted[IOHWAB_NUM_ADC_GROUP]= {FALSE};

#endif
/******************************************************************************
*  Private Variable Definitions                                               *
*******************************************************************************/
#define IoHwAb_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
/* MISRA C-2012 Rule 20.1 JUSTIFICATION: As per Autosar Standard,IoHwAb_MemMap.h is used to map memory segments in IoHwAb*/
#include <IoHwAb_MemMap.h>
/**
* @brief Set of buffers used by Adc Mcal
*/
static IoHwAb_AdcResultType IoHwAb_AdcResult[IOHWAB_NUM_ADC_INPUT];     /**<  Buffer to store the adc signals for different variants*/
/**
* @brief Set of variables used by adc adapter
*/
static IoHwAb_AdcStatusType IoHwAb_AdcStatus;                           /**<  Adc status and varient details are stored in this structure*/
/**
* @brief Set of variables used to set flags for similar virtaul id's for raw value update
*/
static IoHwAb_AdcFlagType IoHwAb_AdcFlag[IOHWAB_NUM_ADC_INPUT];         /**< Flag to set/clear when raw value of virtual id's are updated */
#if (IOHWAB_ADC_MUX == STD_ON)
/* Variables for mux handling */
static AdcMuxState_t IoHwAb_AdcMuxStatus;
static uint8 IoHwAb_CurrentMuxGroup;
#endif

#define IOHWAB_STOP_SEC_NOCACHE_DATA
#include <IoHwAb_MemMap.h>

#define IoHwAb_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
/* MISRA C-2012 Rule 20.1 JUSTIFICATION: As per Autosar Standard,IoHwAb_MemMap.h is used to map memory segments in IoHwAb.*/
#include <IoHwAb_MemMap.h>

/******************************************************************************
*  Private Function Declarations                                              *
*******************************************************************************/
static Std_ReturnType IoHwAb_Adc_ProcessAdc(uint16 Index);
static Std_ReturnType IoHwAb_Adc_Ratioed(uint16 RawValue, uint16 RefValue, uint32 Multiplier, uint32 *RatioedValue);
#if (IOHWAB_ADC_MUX == STD_ON)
static void IoHwAb_AdcDioSelectMux(uint8 MuxGroup, uint8 MuxSelection);
#endif

/******************************************************************************
*  Public Function Definitions                                                *
*******************************************************************************/
#define IoHwAb_START_SEC_CODE
/* MISRA C-2012 Rule 20.1 JUSTIFICATION: As per Autosar Standard,IoHwAb_MemMap.h is used to map memory segments in IoHwAb.*/
#include <IoHwAb_MemMap.h>
/**
* This method initialize the IoHwAb adc module
* @param     none
* @return    void
*/
void IoHwAb_Adc_Init(void)
{
    Std_ReturnType Adc_SetBufferResult;
    uint16 InputIndex;
    Std_ReturnType VariantResult;
    uint8 GroupIndex;

    for(InputIndex = 0u ; InputIndex < IOHWAB_NUM_ADC_INPUT; InputIndex ++)
    {
        IoHwAb_AdcResult[InputIndex].RawValue = 0u;
        IoHwAb_AdcResult[InputIndex].ProcessedValue = (sint32)0;
        IoHwAb_AdcResult[InputIndex].JobResult = IOHWAB_ADC_JOB_ERROR;
    }

    GroupIndex = 0u;
#if (IOHWAB_NUM_ADC_GROUP > 1)
    for(GroupIndex = 0; GroupIndex < IOHWAB_NUM_ADC_GROUP; GroupIndex++)
#endif
    {
        /* Initialize the adc buffer*/
        Adc_SetBufferResult = IoHwAb_Adc_SetupResultBuffer((Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].AdcGroupId, &AdcGroupBuffer[IoHwAb_AdcNumOfGroup[GroupIndex].Offset]);

        /* Set the Adc initialize status*/
        if((uint8)E_OK == Adc_SetBufferResult)
        {
            IoHwAb_AdcStatus.MultiChannelAdcReadStatus[GroupIndex] = IOHWAB_ADC_BUFFER_INITIALISED;
        }
        else
        {
            IoHwAb_AdcStatus.MultiChannelAdcReadStatus[GroupIndex] = IOHWAB_ADC_BUFFER_NOT_INITIALISED;
        }
        VariantResult = IoHwAb_Adc_GetCurrentVariant(&IoHwAb_AdcStatus.AdcVariantId);
        if((uint8)E_OK != VariantResult)
        {
            IoHwAb_AdcStatus.AdcVariantId  = IOHWAB_ADC_UNKNOWN_VARIANT;
        }

#if (IOHWAB_ADC_TIMEOUT_ENABLE == STD_ON)
        flgConversionStarted[GroupIndex] = FALSE;
        AsyncConvTimeOutCount[GroupIndex] = 0;
#endif
#if (IOHWAB_ADC_HW_TRIGGER_ENABLE == STD_ON)
        if (TRUE == (Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].HardwareAdcTrigger)
        {
            IoHwAb_Adc_EnableHardwareTrigger((Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].AdcGroupId);
            IoHwAb_Adc_EnableGroupNotification((Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].AdcGroupId);
        }
#endif

#if (IOHWAB_ADC_MUX == STD_ON)
        IoHwAb_Adc_EnableGroupNotification((Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].AdcGroupId);
#endif

    } /* End initialize by GroupIndex*/


#if (IOHWAB_ADC_MUX == STD_ON)
//	IoHwAb_Adc_EnableGroupNotification((Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].AdcGroupId);
    /* Populate mux to index list */

    IoHwAb_AdcMuxStatus = eAdcMux_Idle;
    IoHwAb_CurrentMuxGroup = IOHWAB_FIRST_MUX_GROUP_ID;
    IoHwAb_Gpt_EnableNotification(IOHWAB_MUX_DELAY_TIMER);
#endif

}


void IoHwAb_Adc_DeInit(void)
{
    IoHwAb_Adc_StatusType Adc_Result;
    uint8 GroupIndex;

#if (IOHWAB_ADC_MUX == STD_ON)
    IoHwAb_AdcMuxStatus = eAdcMux_NotInit;
    IoHwAb_CurrentMuxGroup = IOHWAB_FIRST_MUX_GROUP_ID;
    IoHwAb_Gpt_DisableNotification(IOHWAB_MUX_DELAY_TIMER);
#endif

    GroupIndex = 0u;

#if (IOHWAB_NUM_ADC_GROUP > 1)
    for(GroupIndex = 0; GroupIndex < IOHWAB_NUM_ADC_GROUP; GroupIndex++)
#endif
    {
        Adc_Result = IoHwAb_Adc_GetGroupStatus((Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].AdcGroupId);
        if(IOHWAB_ADC_IDLE != Adc_Result)
        {
            IoHwAb_Adc_StopGroupConversion((Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].AdcGroupId);
        }
        IoHwAb_AdcStatus.MultiChannelAdcReadStatus[GroupIndex] = IOHWAB_ADC_BUFFER_NOT_INITIALISED;

#if (IOHWAB_ADC_TIMEOUT_ENABLE == STD_ON)
        flgConversionStarted[GroupIndex] = FALSE;
        AsyncConvTimeOutCount[GroupIndex] = 0;
#endif
#if (IOHWAB_ADC_HW_TRIGGER_ENABLE == STD_ON)
        /*To Disable Hardware trigger*/
        if (TRUE == (Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].HardwareAdcTrigger)
        {
            IoHwAb_Adc_DisableHardwareTrigger((Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].AdcGroupId);
            IoHwAb_Adc_DisableGroupNotification((Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].AdcGroupId);
        }
#endif

#if (IOHWAB_ADC_MUX == STD_ON)
        IoHwAb_Adc_DisableGroupNotification((Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].AdcGroupId);
#endif
    }
}

#if (IOHWAB_ADC_HW_TRIGGER_ENABLE == STD_ON)
void IoHwAb_Adc_HardwareTrigger(uint8 GroupIndex)
{
    IoHwAb_Adc_StatusType Adc_Result;
    Std_ReturnType ProcessResult;
    uint8 GroupOffSet = 0u;
    uint8 Index = 0U;

    Adc_Result =  IoHwAb_Adc_GetGroupStatus((Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].AdcGroupId);
    if(IOHWAB_ADC_STREAM_COMPLETED == Adc_Result)
    {
        if (E_OK == IoHwAb_Adc_ReadGroup((Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].AdcGroupId, &AdcGroupBuffer[IoHwAb_AdcNumOfGroup[GroupIndex].Offset]))   /* All other analog channels*/
        {
            const IoHwAb_AdcNumOfGroupType * const pIoHwAb_AdcNumOfGroup = &IoHwAb_AdcNumOfGroup[GroupIndex];
            GroupOffSet = pIoHwAb_AdcNumOfGroup -> Offset;
            IoHwAb_AdcFlagType * const pIoHwAb_AdcFlag = &IoHwAb_AdcFlag[GroupOffSet];
            if((pIoHwAb_AdcFlag -> HwTrigger) != 0x01u)    /* Flag check is done to prevent the overwrite of similar virtual id*/
            {
                IoHwAb_AdcResultType * const pIoHwAb_AdcResult = &IoHwAb_AdcResult[GroupOffSet];
                const IoHwAb_AdcGroupType * const pIoHwAb_AdcGroup = &IoHwAb_AdcCfg[GroupOffSet].IoHwAb_AdcGroup[IoHwAb_AdcStatus.AdcVariantId];
                pIoHwAb_AdcResult -> RawValue = AdcGroupBuffer[(pIoHwAb_AdcGroup->Adc_ChannelId) + GroupOffSet];

                for (Index = 1U; Index < (pIoHwAb_AdcNumOfGroup->Count); Index ++)
                {
                    IoHwAb_AdcFlagType * const pIoHwAb_AdcFlagCopy = &IoHwAb_AdcFlag[Index+GroupOffSet];
                    IoHwAb_AdcResultType * const pIoHwAb_AdcResultCopy = &IoHwAb_AdcResult[Index+GroupOffSet];
                    const IoHwAb_AdcGroupType * const pIoHwAb_AdcGroupCopy = &IoHwAb_AdcCfg[Index+GroupOffSet].IoHwAb_AdcGroup[IoHwAb_AdcStatus.AdcVariantId];
#if (IOHWAB_ADC_MUX == STD_ON)
                    if((pIoHwAb_AdcGroupCopy -> MuxChannel) != FALSE)
                    {
                        if(((pIoHwAb_AdcGroup->MuxGroupId) == (pIoHwAb_AdcGroupCopy -> MuxGroupId))    /* To Check the similar vitual id's (Mux Group)*/
                                && ((pIoHwAb_AdcFlagCopy -> HwTrigger) != 0x01u))    /* To check raw value is already updated or not*/
                        {
                            /* Update the same raw value for similar virtual id's*/
                            pIoHwAb_AdcResultCopy -> RawValue = AdcGroupBuffer[(pIoHwAb_AdcGroup -> Adc_ChannelId) + GroupOffSet];
                            pIoHwAb_AdcFlagCopy -> HwTrigger = 1;     /* Set the flag after raw values are updated*/
                        }
                    }
                    else
#endif
                    {
                        if(((pIoHwAb_AdcGroup->Adc_ChannelId) == (pIoHwAb_AdcGroupCopy -> Adc_ChannelId))    /* To Check the similar vitual id's*/
                                && ((pIoHwAb_AdcFlagCopy -> HwTrigger) != 0x01u))     /* To check raw value is already updated or not*/
                        {
                            pIoHwAb_AdcResultCopy -> RawValue = AdcGroupBuffer[(pIoHwAb_AdcGroup -> Adc_ChannelId) + GroupOffSet];
                            pIoHwAb_AdcFlagCopy -> HwTrigger = 1;     /* Set the flag after raw values are updated*/
                        }
                    }
                }
            }
            else
            {
                pIoHwAb_AdcFlag -> HwTrigger = 0;     /* Clear the flag if it is called for similar virtual id*/
            }

            if(IoHwAb_AdcResult[GroupOffSet].RawValue <= IOHWAB_ADC_MAX_VALUE)
            {
                ProcessResult = IoHwAb_Adc_ProcessAdc(GroupOffSet);
                if(ProcessResult == E_OK)
                {
                    IoHwAb_AdcResult[GroupOffSet].JobResult = IOHWAB_ADC_JOB_OK;
                }
                else
                {
                    IoHwAb_AdcResult[GroupOffSet].JobResult = IOHWAB_ADC_JOB_ERROR;
                }
            }
            else
            {
                IoHwAb_AdcResult[GroupOffSet].RawValue = 0;
                IoHwAb_AdcResult[GroupOffSet].JobResult = IOHWAB_ADC_JOB_ERROR;
            }
        }
    }
}
#endif
/**
* This method is the main function for IoHwAb adc module
* @param     none
* @return    void
*/
void IoHwAb_Adc_MainFunction(void)
{
    uint16 Index;
    uint16 Index_2 = 0U;
    Std_ReturnType ProcessMainFunction = E_OK;
    IoHwAb_Adc_StatusType Adc_Result;
    Std_ReturnType Adc_SetBufferResult = E_NOT_OK;
    Std_ReturnType VariantResult;
    Std_ReturnType ProcessResult;
    uint8 GroupIndex = 0u;
	#if (IOHWAB_ADC_MUX == STD_ON)
    static uint8 MuxSelect = 0u;
    #endif
    uint8 GroupOffSet = 0u;
    GroupIndex = 0u;

	VariantResult = IoHwAb_Adc_GetCurrentVariant(&IoHwAb_AdcStatus.AdcVariantId);

	if((uint8)E_OK != VariantResult)
	{
		/*	Receive the Adc varient id from swc*/
		IoHwAb_AdcStatus.AdcVariantId = IOHWAB_ADC_UNKNOWN_VARIANT;
	}
	if(IoHwAb_AdcStatus.AdcVariantId >= IOHWAB_ADC_UNKNOWN_VARIANT)
	{
		ProcessMainFunction = E_NOT_OK;
	}
	if((uint8)E_OK != IoHwAb_Adc_PreHook())
	{
		ProcessMainFunction = E_NOT_OK;
	}
	if((uint8)E_OK == ProcessMainFunction)
	{
		#if (IOHWAB_NUM_ADC_GROUP > 1)
		for(GroupIndex = 0u; GroupIndex < IOHWAB_NUM_ADC_GROUP; GroupIndex++)
		#endif
		{
			Adc_Result =  IoHwAb_Adc_GetGroupStatus((Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].AdcGroupId);
			/* Initialize the Adc buffer if failed in Adc init*/
			if((IoHwAb_AdcStatus.MultiChannelAdcReadStatus[GroupIndex] >= IOHWAB_ADC_MAX_STATE) || (IoHwAb_AdcStatus.MultiChannelAdcReadStatus[GroupIndex] == IOHWAB_ADC_BUFFER_NOT_INITIALISED))
			{
				if(IOHWAB_ADC_IDLE != Adc_Result)
				{
					IoHwAb_Adc_StopGroupConversion((Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].AdcGroupId);
				}
				Adc_SetBufferResult = IoHwAb_Adc_SetupResultBuffer((Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].AdcGroupId, &AdcGroupBuffer[IoHwAb_AdcNumOfGroup[GroupIndex].Offset]);
	#if (IOHWAB_ADC_HW_TRIGGER_ENABLE == STD_ON)
				if (TRUE == (Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].HardwareAdcTrigger)
				{
					IoHwAb_Adc_EnableHardwareTrigger((Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].AdcGroupId);
					IoHwAb_Adc_EnableGroupNotification((Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].AdcGroupId);
				}
	#endif
				/* Set the Adc initialize status*/
				if((uint8)E_OK == Adc_SetBufferResult)
				{
					IoHwAb_AdcStatus.MultiChannelAdcReadStatus[GroupIndex] = IOHWAB_ADC_BUFFER_INITIALISED;
				}
				else
				{
					IoHwAb_AdcStatus.MultiChannelAdcReadStatus[GroupIndex] = IOHWAB_ADC_BUFFER_NOT_INITIALISED;
				}
			}
			if(IoHwAb_AdcStatus.MultiChannelAdcReadStatus[GroupIndex] > IOHWAB_ADC_BUFFER_NOT_INITIALISED)
			{
	#if (IOHWAB_ADC_MUX == STD_ON)
				if(IoHwAb_AdcNumOfGroup[GroupIndex].MuxGroupType != IOHWAB_GROUP_MUX)
	#endif
				{
					/* Read the adc result if conversion is completed*/
					if(IOHWAB_ADC_STREAM_COMPLETED == Adc_Result)
					{
	#if (IOHWAB_ADC_TIMEOUT_ENABLE == STD_ON)
						AsyncConvTimeOutCount[GroupIndex] = 0;
						flgConversionStarted[GroupIndex] = FALSE;
	#endif
						if ((uint8)E_OK == IoHwAb_Adc_ReadGroup((Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].AdcGroupId, &AdcGroupBuffer[IoHwAb_AdcNumOfGroup[GroupIndex].Offset]))   /* All other analog channels*/
						{
							const IoHwAb_AdcNumOfGroupType * const pIoHwAb_AdcNumOfGroup = &IoHwAb_AdcNumOfGroup[GroupIndex];
							IoHwAb_AdcStatus.MultiChannelAdcReadStatus[GroupIndex] =  IOHWAB_ADC_CONVERSION_COMPLETED;
							GroupOffSet = pIoHwAb_AdcNumOfGroup -> Offset;

							for (Index = 0U; Index < (pIoHwAb_AdcNumOfGroup -> Count); Index ++) /* Set value to Signal*/
							{
								IoHwAb_AdcResultType * const pIoHwAb_AdcResult = &IoHwAb_AdcResult[Index+GroupOffSet];
								IoHwAb_AdcFlagType * const pIoHwAb_AdcFlag = &IoHwAb_AdcFlag[Index+GroupOffSet];
								const IoHwAb_AdcGroupType * const pIoHwAb_AdcGroup = &IoHwAb_AdcCfg[Index+GroupOffSet].IoHwAb_AdcGroup[IoHwAb_AdcStatus.AdcVariantId];

								if(pIoHwAb_AdcFlag -> Main != 0x01u)     /* Flag check is done to prevent the overwrite of similar virtual id*/
								{
									pIoHwAb_AdcResult -> RawValue = AdcGroupBuffer[pIoHwAb_AdcGroup -> Adc_ChannelId + GroupOffSet];
									for (Index_2 = Index + 1U; Index_2 < pIoHwAb_AdcNumOfGroup -> Count; Index_2 ++)
									{
										IoHwAb_AdcResultType * const pIoHwAb_AdcResultCopy = &IoHwAb_AdcResult[Index_2+GroupOffSet];
										IoHwAb_AdcFlagType * const pIoHwAb_AdcFlagCopy = &IoHwAb_AdcFlag[Index_2+GroupOffSet];
										const IoHwAb_AdcGroupType * const pIoHwAb_AdcGroupCopy = &IoHwAb_AdcCfg[Index_2+GroupOffSet].IoHwAb_AdcGroup[IoHwAb_AdcStatus.AdcVariantId];

										if(((pIoHwAb_AdcGroup->Adc_ChannelId) == (pIoHwAb_AdcGroupCopy->Adc_ChannelId))   /* To Check the similar vitual id's*/
												&& (pIoHwAb_AdcFlagCopy -> Main != 0x01u))    /* To check raw value is already updated or not*/
										{
											pIoHwAb_AdcResultCopy->RawValue = AdcGroupBuffer[pIoHwAb_AdcGroup->Adc_ChannelId + GroupOffSet];
											pIoHwAb_AdcFlagCopy ->Main = 1U;     /* Set the flag after raw values are updated*/
										}
									}
								}
								else
								{
									pIoHwAb_AdcFlag -> Main = 0;    /* Clear the flag if it is called for similar virtual id*/
								}
							}
						}
					}
	#if (IOHWAB_ADC_TIMEOUT_ENABLE == STD_ON)
					else
					{
						if(TRUE == flgConversionStarted[GroupIndex])
						{
							AsyncConvTimeOutCount[GroupIndex]++;
						}
					}
	#endif
				}
			}
		
			if(IoHwAb_AdcStatus.MultiChannelAdcReadStatus[GroupIndex] ==  IOHWAB_ADC_CONVERSION_COMPLETED)
			{
				GroupOffSet = IoHwAb_AdcNumOfGroup[GroupIndex].Offset;
				/* Processing is done for each adc inputs*/
				for (Index = 0U; Index < IoHwAb_AdcNumOfGroup[GroupIndex].Count; Index ++)
				{					
					if(IoHwAb_AdcResult[Index+GroupOffSet].RawValue <= IOHWAB_ADC_MAX_VALUE)
					{
						ProcessResult = IoHwAb_Adc_ProcessAdc(Index+GroupOffSet);
						if((uint8)E_OK == ProcessResult)
						{
							IoHwAb_AdcResult[Index+GroupOffSet].JobResult = IOHWAB_ADC_JOB_OK;
						}
						else
						{
							IoHwAb_AdcResult[Index+GroupOffSet].JobResult = IOHWAB_ADC_JOB_ERROR;
						}
					}
					else
					{
						IoHwAb_AdcResult[Index+GroupOffSet].RawValue = 0;
						IoHwAb_AdcResult[Index+GroupOffSet].JobResult = IOHWAB_ADC_JOB_ERROR;
					}
				}
			}

			
	#if (IOHWAB_ADC_TIMEOUT_ENABLE == STD_ON)
			/* check timeout before starting conversion
			Timeout can happen in following case:
			1) When ADC Buffer is initialised but conversion is not completed till given time.
			*/

			if(AsyncConvTimeOutCount[GroupIndex] >= IOHWAB_ADC_MAX_ASYNC_COUNT)
			{
				for( Index =IoHwAb_AdcNumOfGroup[GroupIndex].Offset; Index < (IoHwAb_AdcNumOfGroup[GroupIndex].Offset+IoHwAb_AdcNumOfGroup[GroupIndex].Count); Index++)
				{
					IoHwAb_AdcResult[Index].RawValue = 0;
					IoHwAb_AdcResult[Index].JobResult = IOHWAB_ADC_JOB_ERROR;
				}

				AsyncConvTimeOutCount[GroupIndex]=0;
				flgConversionStarted[GroupIndex] = FALSE;

				if(IOHWAB_ADC_IDLE != Adc_Result)
				{
					IoHwAb_Adc_StopGroupConversion((Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].AdcGroupId);
				}
			}
	#endif

		if(IoHwAb_AdcStatus.MultiChannelAdcReadStatus[GroupIndex] > IOHWAB_ADC_BUFFER_NOT_INITIALISED)
		{
			Adc_Result = IoHwAb_Adc_GetGroupStatus((Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].AdcGroupId);
			if(IOHWAB_ADC_BUSY != Adc_Result)
			{
#if (IOHWAB_ADC_MUX == STD_ON)
					if(IoHwAb_AdcNumOfGroup[GroupIndex].MuxGroupType != IOHWAB_GROUP_MUX)
					{
						IoHwAb_Adc_StartGroupConversion((Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].AdcGroupId);
					}
	#else
					IoHwAb_Adc_StartGroupConversion((Adc_GroupType)IoHwAb_AdcNumOfGroup[GroupIndex].AdcGroupId);
	#endif
					IoHwAb_AdcStatus.MultiChannelAdcReadStatus[GroupIndex] = IOHWAB_ADC_CONVERSION_STARTED;

	#if (IOHWAB_ADC_TIMEOUT_ENABLE == STD_ON)
	#if (IOHWAB_ADC_HW_TRIGGER_ENABLE == STD_ON)
					if (FALSE == IoHwAb_AdcNumOfGroup[GroupIndex].HardwareAdcTrigger)
	#endif
					{
						flgConversionStarted[GroupIndex] = TRUE;
					}
	#endif
				}
			}
		}


	#if (IOHWAB_ADC_MUX == STD_ON)
		/* Start muxes only if they are not in progress*/
		if((IoHwAb_AdcMuxStatus > eAdcMux_NotInit) || (IoHwAb_AdcMuxStatus == eAdcMux_Idle))
		{
			/* Start measuring MUX -ed ADCs*/
			IoHwAb_CurrentMuxGroup = IOHWAB_FIRST_MUX_GROUP_ID;
			/* Select group and input based on current mux group*/
			
			if(FALSE != IoHwAb_AdcCfg[IoHwAb_AdcNumOfGroup[IoHwAb_CurrentMuxGroup].Offset].IoHwAb_AdcGroup[IoHwAb_AdcStatus.AdcVariantId].MuxChannel )
			{
				MuxSelect = IoHwAb_AdcCfg[IoHwAb_AdcNumOfGroup[IoHwAb_CurrentMuxGroup].Offset].IoHwAb_AdcGroup[IoHwAb_AdcStatus.AdcVariantId].MuxChannelId;
				IoHwAb_AdcDioSelectMux( (IoHwAb_AdcNumOfGroup[IoHwAb_CurrentMuxGroup].AdcGroupId), MuxSelect );
				/* Start ADC gpt timer for delay*/
				SuspendAllInterrupts(); /* for setting up short delays, due to bug in NXP driver, interrupts must be disabled*/
				IoHwAb_AdcMuxStatus = eAdcMux_InProgressTimer;
				IoHwAb_Gpt_StartTimer((Gpt_ChannelType)IOHWAB_MUX_DELAY_TIMER, (Gpt_ValueType)(IOHWAB_MUX_DELAY_TIME_USEC * IOHWAB_MUX_TIMER_FREQ_MHZ));
				ResumeAllInterrupts();
			}

		}
		#endif

	}
}

/**
* This method is used to get the Adc singal value after processing
* @param     AdcId 	        - ID of the Adc signal
* @param     ProcessedValue   - parameter  to be get the processed adc value
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType  IoHwAb_Adc_GetProcessedAdc(IoHwAb_AdcSignalIdType AdcId, sint32* ProcessedValue, IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType JobResult = E_OK;
    uint16 Index;
    *ErrorStatus = IOHWAB_E_ERROR;
#if (IOHWAB_NUM_OF_RES_CALC > 0U)
    sint32 FilteredValue = 0;
#endif

    /* To check if resolution calculation or debouncing is required*/
#if ((IOHWAB_NUM_OF_RES_CALC > 0U)||(IOHWAB_NUM_OF_DEBOUNCE > 0U))
    uint32 TmpValue;
#endif
    if( IoHwAb_AdcStatus.AdcVariantId >= IOHWAB_ADC_UNKNOWN_VARIANT)
    {
        JobResult = E_NOT_OK;
        *ErrorStatus = IOHWAB_E_ADC_ID_INVALID;
    }
    for(Index = 0u ; Index < IOHWAB_NUM_ADC_INPUT; Index ++)
    {
        if (AdcId == IoHwAb_AdcCfg[Index].SignalId)
        {
            break;
        }
    }
    if(Index >= IOHWAB_NUM_ADC_INPUT)
    {
        JobResult = E_NOT_OK;
        *ErrorStatus = IOHWAB_E_ADC_ID_INVALID;
    }
    else
    {
        if(IoHwAb_AdcResult[Index].JobResult != IOHWAB_ADC_JOB_OK)
        {
            JobResult = E_NOT_OK;
            *ErrorStatus = IOHWAB_E_ADC_ID_INVALID;
        }
        if((uint8)E_OK == JobResult)
        {
            /* Raw value is moved to process value if no filter is used*/
            *ProcessedValue = IoHwAb_AdcResult[Index].ProcessedValue;
            *ErrorStatus = IOHWAB_E_NO_ERROR;
            /* Get the debounced value from filter if debouncing is used */
#if (IOHWAB_NUM_OF_DEBOUNCE > 0U)
            if (((IoHwAb_AdcCfg[Index].FilterType) & IOHWAB_DEBOUNCE_ADC) == IOHWAB_DEBOUNCE_ADC)
            {
                /* MISRA C-2012 Rule 11.3 JUSTIFICATION: The values of IoHwAb_AdcResult[Index].ProcessedValue checked and does not have any negative funtional impact.*/
                JobResult = IoHwAb_Filter_GetDebounceValue(IoHwAb_AdcCfg[Index].FilterId[IOHWAB_DEBOUNCE_ADC_INDEX], (uint32 *)&(IoHwAb_AdcResult[Index].ProcessedValue));
                if((uint8)E_OK != JobResult)
                {
                    IoHwAb_AdcResult[Index].JobResult = IOHWAB_ADC_JOB_ERROR;
                    *ErrorStatus = IOHWAB_E_ADC_ERROR;
                }
                else
                {
                    IoHwAb_AdcResult[Index].JobResult = IOHWAB_ADC_JOB_OK;
                    *ProcessedValue = IoHwAb_AdcResult[Index].ProcessedValue;
                    *ErrorStatus = IOHWAB_E_NO_ERROR;
                }
            }
#endif
            /* If resolution calculation is used, get the calculated value from Filter*/
#if (IOHWAB_NUM_OF_RES_CALC > 0U)
            if(((IoHwAb_AdcCfg[Index].FilterType) & IOHWAB_RESOLUTION_ADC) == IOHWAB_RESOLUTION_ADC)
            {
                TmpValue = (uint32)IoHwAb_AdcResult[Index].ProcessedValue;
                JobResult = IoHwAb_Filter_ResolutionCalc(IoHwAb_AdcCfg[Index].FilterId[IOHWAB_RESOLUTION_ADC_INDEX], TmpValue, &FilteredValue);
                if((uint8)E_OK != JobResult)
                {
                    IoHwAb_AdcResult[Index].JobResult = IOHWAB_ADC_JOB_ERROR;
                    *ErrorStatus = IOHWAB_E_ADC_ERROR;
                }
                else
                {
                    IoHwAb_AdcResult[Index].JobResult = IOHWAB_ADC_JOB_OK;
                    *ProcessedValue = FilteredValue;
                    *ErrorStatus = IOHWAB_E_NO_ERROR;
                }
            }
#endif
        }
    }
    return JobResult;
}

/**
* This method is used to get the raw adc value from stored buffer - Asynchronus
* @param     AdcId 	         - ID of the Adc signal
* @param     AsyncRawValue   - parameter  to be get the input adc raw value
* @return    Std_ReturnType  - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType  IoHwAb_Adc_GetAsyncRawAdc(IoHwAb_AdcSignalIdType AdcId,uint16* AsyncRawValue, IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType JobResult = E_OK;
    uint16 Index;
    *ErrorStatus = IOHWAB_E_ERROR;

    if( IoHwAb_AdcStatus.AdcVariantId >= IOHWAB_ADC_UNKNOWN_VARIANT)
    {
        JobResult = E_NOT_OK;
        *ErrorStatus = IOHWAB_E_ADC_ID_INVALID;
    }
    for(Index = 0u ; Index < IOHWAB_NUM_ADC_INPUT; Index ++)
    {
        if (AdcId == IoHwAb_AdcCfg[Index].SignalId)
        {
            break;
        }
    }
    if(Index >= IOHWAB_NUM_ADC_INPUT)
    {
        JobResult = E_NOT_OK;
        *ErrorStatus = IOHWAB_E_ADC_ID_INVALID;
    }
    else 
	{
		if(IoHwAb_AdcResult[Index].JobResult != IOHWAB_ADC_JOB_OK)
		{
		  JobResult = E_NOT_OK;
		  *ErrorStatus = IOHWAB_E_ADC_ID_INVALID;
		}
	
		if((uint8)E_OK == JobResult) 
		{
            /* Raw value is moved to process value if no filter is used*/
            *AsyncRawValue = IoHwAb_AdcResult[Index].RawValue;
            *ErrorStatus = IOHWAB_E_NO_ERROR;
		}
	}
	return JobResult;
}
/**
* This method is used to get the raw adc value synchronously from MCAL
* @param     AdcId 	        - ID of the Adc signal
* @param     SyncRawAdc     - parameter  to be get the input adc raw value
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_Adc_GetSyncRawAdc(IoHwAb_AdcSignalIdType AdcId, uint16* SyncRawValue, IoHwAb_ErrorType* ErrorStatus)
{

#if (IOHWAB_ADC_MUX == STD_ON)
    return IoHwAb_Adc_GetAsyncRawAdc(AdcId, SyncRawValue, ErrorStatus); /* sync value not supported, return latest async*/
#else
    Std_ReturnType JobResult = E_OK;
    uint16 Index;
    *ErrorStatus = IOHWAB_E_ERROR;
    /* MISRA C-2012 Directive 4.5 JUSTIFICATION: The other declaration of AdcGroupStatus is in Adc.h and does not have any functional impact.*/
    IoHwAb_Adc_StatusType AdcGroupStatus;
    uint32 TimeOutCount = 0uL;


    if( IoHwAb_AdcStatus.AdcVariantId >= IOHWAB_ADC_UNKNOWN_VARIANT)
    {
        JobResult = E_NOT_OK;
        *ErrorStatus = IOHWAB_E_ADC_ID_INVALID;
    }
    else
    {
        for(Index = 0u ; Index < IOHWAB_NUM_ADC_INPUT; Index ++)
        {
            if (AdcId == IoHwAb_AdcCfg[Index].SignalId)
            {
                break;
            }
        }
        if(Index >= IOHWAB_NUM_ADC_INPUT)
        {
            JobResult = E_NOT_OK;
            *ErrorStatus = IOHWAB_E_ADC_ID_INVALID;
        }
        else
        {
            AdcGroupStatus = IoHwAb_Adc_GetGroupStatus((Adc_GroupType)IoHwAb_AdcCfg[Index].IoHwAb_AdcGroup[IoHwAb_AdcStatus.AdcVariantId].SingleCh_Adc_GroupId);
            if(AdcGroupStatus != IOHWAB_ADC_IDLE)
            {
                IoHwAb_Adc_StopGroupConversion(IoHwAb_AdcCfg[Index].IoHwAb_AdcGroup[IoHwAb_AdcStatus.AdcVariantId].SingleCh_Adc_GroupId);
            }
            JobResult = IoHwAb_Adc_SetupResultBuffer((Adc_GroupType)IoHwAb_AdcCfg[Index].IoHwAb_AdcGroup[IoHwAb_AdcStatus.AdcVariantId].SingleCh_Adc_GroupId, SyncRawValue);
            if( (uint8)E_OK == JobResult)
            {
                IoHwAb_Adc_StartGroupConversion(IoHwAb_AdcCfg[Index].IoHwAb_AdcGroup[IoHwAb_AdcStatus.AdcVariantId].SingleCh_Adc_GroupId);
                /* Wait till the conversion completed with a timeout*/
                do
                {
                    TimeOutCount++;
                    AdcGroupStatus =  IoHwAb_Adc_GetGroupStatus((Adc_GroupType)IoHwAb_AdcCfg[Index].IoHwAb_AdcGroup[IoHwAb_AdcStatus.AdcVariantId].SingleCh_Adc_GroupId);
                }
                while((IOHWAB_ADC_BUSY == AdcGroupStatus)&&(TimeOutCount < IOHWAB_ADC_MAX_SYNC_COUNT));        // TODO: Value needs to be finalized
                if(AdcGroupStatus == IOHWAB_ADC_BUSY)
                {
                    JobResult = E_NOT_OK;
                    *ErrorStatus = IOHWAB_E_ADC_ERROR;
                }
                if(AdcGroupStatus == IOHWAB_ADC_STREAM_COMPLETED)
                {
                    JobResult =  IoHwAb_Adc_ReadGroup(IoHwAb_AdcCfg[Index].IoHwAb_AdcGroup[IoHwAb_AdcStatus.AdcVariantId].SingleCh_Adc_GroupId, SyncRawValue);   // All other analog channels
                }
                if( (uint8)E_OK == JobResult)
                {
                    *ErrorStatus = IOHWAB_E_NO_ERROR;
                }
                else
                {
                    JobResult = E_NOT_OK;
                    *ErrorStatus = IOHWAB_E_ADC_ERROR;
                }
            }
            AdcGroupStatus = IoHwAb_Adc_GetGroupStatus((Adc_GroupType)IoHwAb_AdcCfg[Index].IoHwAb_AdcGroup[IoHwAb_AdcStatus.AdcVariantId].SingleCh_Adc_GroupId);
            if(AdcGroupStatus != IOHWAB_ADC_IDLE)
            {
                IoHwAb_Adc_StopGroupConversion(IoHwAb_AdcCfg[Index].IoHwAb_AdcGroup[IoHwAb_AdcStatus.AdcVariantId].SingleCh_Adc_GroupId);
            }
        }
    }
    return JobResult;
#endif
}
/**
* This method is used to select and trigger the processing of different adc signals
* @param     none
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
static Std_ReturnType IoHwAb_Adc_ProcessAdc(uint16 Index)
{
    uint32 RatioedMultiplier;
    Std_ReturnType RetValue= E_NOT_OK;
    uint32 temp;
    uint8 RatioedChannelIndex;

    /* To check if encoded or debounce adc is used*/
#if ((IOHWAB_NUM_OF_ENCODED > 0U)||(IOHWAB_NUM_OF_DEBOUNCE > 0U) || (IOHWAB_NUM_OF_PT1FILTER > 0) || (IOHWAB_NUM_OF_MOVINGAVGFILTER > 0) || (IOHWAB_NUM_OF_AVGFILTER > 0))
    uint32 TmpValue;
#endif
    /* Raw value is moved to process value*/
    IoHwAb_AdcResult[Index].ProcessedValue = (sint32)IoHwAb_AdcResult[Index].RawValue;

    /* If no filters are used raw value is provided as processed value*/
    if ((IoHwAb_AdcCfg[Index].FilterType) == IOHWAB_NOFILTER_ADC)
    {
        IoHwAb_AdcResult[Index].ProcessedValue = (sint32)IoHwAb_AdcResult[Index].RawValue;
        RetValue= E_OK;
    }

    /* If Resolution filter is used, the filtering would be applied on debounced value when application is requesting the processed value.*/
    if ((IoHwAb_AdcCfg[Index].FilterType) == IOHWAB_RESOLUTION_ADC)
    {
        RetValue= E_OK;
    }

    RatioedChannelIndex = IoHwAb_AdcCfg[Index].IoHwAb_AdcGroup[IoHwAb_AdcStatus.AdcVariantId].RatioRefChannelId;
    RatioedMultiplier = IoHwAb_AdcCfg[Index].IoHwAb_AdcGroup[IoHwAb_AdcStatus.AdcVariantId].RatioMultiplier;
    /* Call the ratioed api for ratioed calculation*/
    if (((IoHwAb_AdcCfg[Index].FilterType) & IOHWAB_RATIOED_ADC) == IOHWAB_RATIOED_ADC)
    {
        temp = (uint32)IoHwAb_AdcResult[Index].ProcessedValue;
        RetValue = IoHwAb_Adc_Ratioed(IoHwAb_AdcResult[Index].RawValue, IoHwAb_AdcResult[RatioedChannelIndex].RawValue, RatioedMultiplier, &temp);
        if((uint8)E_OK == RetValue)
        {
            IoHwAb_AdcResult[Index].ProcessedValue = (sint32)temp;
        }
    }
#if (IOHWAB_NUM_OF_PT1FILTER > 0)
    if (((IoHwAb_AdcCfg[Index].FilterType) & IOHWAB_PT1_ADC) == IOHWAB_PT1_ADC)
    {
        TmpValue = (uint32)IoHwAb_AdcResult[Index].ProcessedValue;
        RetValue = IoHwAb_Filter_PT1Filter(IoHwAb_AdcCfg[Index].FilterId[IOHWAB_PT1_ADC_INDEX], TmpValue, (uint32 *) &(IoHwAb_AdcResult[Index].ProcessedValue));
    }
#endif

#if (IOHWAB_NUM_OF_MOVINGAVGFILTER > 0)
    if (((IoHwAb_AdcCfg[Index].FilterType) & IOHWAB_MOVING_AVERAGE_ADC) == IOHWAB_MOVING_AVERAGE_ADC)
    {
        TmpValue = (uint32)IoHwAb_AdcResult[Index].ProcessedValue;
        RetValue = IoHwAb_Filter_MovingAvgFilter(IoHwAb_AdcCfg[Index].FilterId[IOHWAB_MOVINGAVG_ADC_INDEX], TmpValue, (uint32 *) &(IoHwAb_AdcResult[Index].ProcessedValue));
    }
#endif

#if (IOHWAB_NUM_OF_AVGFILTER > 0)
    if (((IoHwAb_AdcCfg[Index].FilterType) & IOHWAB_AVERAGE_ADC) == IOHWAB_AVERAGE_ADC)
    {
        TmpValue = (uint32)IoHwAb_AdcResult[Index].ProcessedValue;
        RetValue = IoHwAb_Filter_AvgFilter(IoHwAb_AdcCfg[Index].FilterId[IOHWAB_AVG_ADC_INDEX], TmpValue, (uint32 *) &(IoHwAb_AdcResult[Index].ProcessedValue));
    }
#endif
    /* If encoded adc calculation is used call the encoded filter api*/
#if (IOHWAB_NUM_OF_ENCODED > 0U)
    if (((IoHwAb_AdcCfg[Index].FilterType) & IOHWAB_ENCODED_ADC) == IOHWAB_ENCODED_ADC)
    {
        TmpValue = (uint32)IoHwAb_AdcResult[Index].ProcessedValue;
        /* MISRA C-2012 Rule 11.3 JUSTIFICATION: The values of IoHwAb_AdcResult[Index].ProcessedValue checked and does not have any negative funtional impact.*/
        RetValue = IoHwAb_Filter_Encoded(IoHwAb_AdcCfg[Index].FilterId[IOHWAB_ENCODED_ADC_INDEX], TmpValue, (uint32 *) &(IoHwAb_AdcResult[Index].ProcessedValue));
    }
#endif
    /* If debouncing is required for the adc  call the normal debounce filter api*/
#if (IOHWAB_NUM_OF_DEBOUNCE > 0U)
    if (((IoHwAb_AdcCfg[Index].FilterType) & IOHWAB_DEBOUNCE_ADC) == IOHWAB_DEBOUNCE_ADC)
    {
		TmpValue = (uint32)IoHwAb_AdcResult[Index].ProcessedValue;
        RetValue = IoHwAb_Filter_SetDebounce(IoHwAb_AdcCfg[Index].FilterId[IOHWAB_DEBOUNCE_ADC_INDEX],  TmpValue);
    }
#endif
    return RetValue;
}
/**
* This method is used to calculate the ratio of the Adc
* @param     RawValue 	    - Raw value of the Adc
* @param     RefValue       - Reference adc value
* @param     Multiplier 	- Multiplier for the calculation
* @param     RatioedValue   - pointer to the result location
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/

static Std_ReturnType IoHwAb_Adc_Ratioed(uint16 RawValue, uint16 RefValue, uint32 Multiplier, uint32 *RatioedValue)
{
    Std_ReturnType RetValue = E_NOT_OK;

    /* The divisor should not be zero*/
    if(RefValue != 0u)
    {
        /* Calculate the ratio*/
        *RatioedValue = (RawValue * Multiplier) / RefValue;
        RetValue = E_OK;
    }
    return RetValue;
}

#if (IOHWAB_ADC_MUX == STD_ON)
/**
* This method is used select the desired mux channel
* @param     MuxSelection       -  Mux Address line selection
* @return    void
*/
static void IoHwAb_AdcDioSelectMux(uint8 MuxGroup, uint8 MuxSelection)
{
    uint8 Index;
    uint8 DioMuxGroupIndex;
    Dio_LevelType Level;

    for(DioMuxGroupIndex = 0; DioMuxGroupIndex < IOHWAB_NUM_OF_MUX_GROUP; DioMuxGroupIndex++)
    {
        if(MuxGroup == IoHwAb_AdcDioMuxGroup[DioMuxGroupIndex].Adc_GroupId)
        {
            break;
        }
    }   
    if(DioMuxGroupIndex < IOHWAB_NUM_OF_MUX_GROUP)
    {
        for(Index = 0; Index < IOHWAB_NUM_OF_MUX_CHANNEL_SELECT; Index++)
        {
            Level = STD_LOW;
            if(0U != (MuxSelection & (0x01U << Index)))
            {
                Level = STD_HIGH;
            }
            Dio_WriteChannel(IoHwAb_AdcDioMuxGroup[DioMuxGroupIndex].IoHwAb_AdcDioMux[Index].Hw_ChannelId, Level);
        }
    }
}

void IoHwAb_AdcNonMuxNotification (void)
{
}

void IoHwAb_AdcMuxNotification (void)
{
    IoHwAb_Adc_StatusType AdcGroupStatus;
    Std_ReturnType JobResult = E_NOT_OK;
    uint8 Index;
    uint8 Index_2;
    uint8 GroupOffSet;
    static uint8 MuxSelect;
	
    if (IoHwAb_AdcMuxStatus == eAdcMux_NotInit) return;

    /* Store current MUX channels in IohWab*/
    AdcGroupStatus =  IoHwAb_Adc_GetGroupStatus((Adc_GroupType)IoHwAb_AdcNumOfGroup[IoHwAb_CurrentMuxGroup].AdcGroupId);
    if(AdcGroupStatus == IOHWAB_ADC_STREAM_COMPLETED)
    {
        JobResult =  IoHwAb_Adc_ReadGroup((Adc_GroupType)IoHwAb_AdcNumOfGroup[IoHwAb_CurrentMuxGroup].AdcGroupId, &AdcGroupBuffer[IoHwAb_AdcNumOfGroup[IoHwAb_CurrentMuxGroup].Offset]);   // All other analog channels
    }
    if(JobResult == E_OK)
    {
        const IoHwAb_AdcNumOfGroupType * const pIoHwAb_AdcNumOfGroup = &IoHwAb_AdcNumOfGroup[IoHwAb_CurrentMuxGroup];
        IoHwAb_AdcStatus.MultiChannelAdcReadStatus[IoHwAb_CurrentMuxGroup] =  IOHWAB_ADC_CONVERSION_COMPLETED;
        for (Index = 0U; Index < (pIoHwAb_AdcNumOfGroup->Count); Index ++)
        {
            /* Set value to Signal*/
            GroupOffSet = pIoHwAb_AdcNumOfGroup -> Offset;
            IoHwAb_AdcResultType * const pIoHwAb_AdcResult = &IoHwAb_AdcResult[Index+GroupOffSet];
            IoHwAb_AdcFlagType * const pIoHwAb_AdcFlag = &IoHwAb_AdcFlag[Index+GroupOffSet];
            const IoHwAb_AdcGroupType * const pIoHwAb_AdcGroup = &IoHwAb_AdcCfg[Index+GroupOffSet].IoHwAb_AdcGroup[IoHwAb_AdcStatus.AdcVariantId];

            if((pIoHwAb_AdcGroup -> MuxChannel) != FALSE)
            {
                if((pIoHwAb_AdcFlag -> MuxNotification) != 0x01u)    /* Flag check is done to prevent the overwrite of similar virtual id*/
                {
                    pIoHwAb_AdcResult -> RawValue = AdcGroupBuffer[Index + GroupOffSet];
                    for (Index_2 = Index + 1U; Index_2 < (pIoHwAb_AdcNumOfGroup->Count); Index_2 ++)
                    {
                        IoHwAb_AdcResultType * const pIoHwAb_AdcResultCopy = &IoHwAb_AdcResult[Index_2+GroupOffSet];
                        IoHwAb_AdcFlagType * const pIoHwAb_AdcFlagCopy = &IoHwAb_AdcFlag[Index_2+GroupOffSet];
                        const IoHwAb_AdcGroupType * const pIoHwAb_AdcGroupCopy = &IoHwAb_AdcCfg[Index_2+GroupOffSet].IoHwAb_AdcGroup[IoHwAb_AdcStatus.AdcVariantId];

                        if(((pIoHwAb_AdcGroup -> MuxGroupId) == (pIoHwAb_AdcGroupCopy -> MuxGroupId))    /* To Check the similar vitual id's (Mux Group)*/
                                && (pIoHwAb_AdcFlagCopy -> MuxNotification != 0x01u))    /* To check raw value is already updated or not*/
                        {
                            /* Update the same raw value for similar virtual id's */
                            pIoHwAb_AdcResultCopy -> RawValue = AdcGroupBuffer[Index + GroupOffSet];
                            pIoHwAb_AdcFlagCopy -> MuxNotification = 1;    /* Set the flag after raw values are updated*/
                        }
                    }
                }
                else
                {
                    pIoHwAb_AdcFlag -> MuxNotification = 0;    /* Clear the flag if it is called for similar virtual id*/
                }
            }
        }

        /* Switch to next mux input*/
        IoHwAb_CurrentMuxGroup++;

        if((IoHwAb_CurrentMuxGroup < (IOHWAB_NUM_ADC_GROUP/*+IOHWAB_FIRST_MUX_GROUP_ID*/) )&&(IoHwAb_CurrentMuxGroup >= IOHWAB_FIRST_MUX_GROUP_ID))
        {
			if(FALSE != IoHwAb_AdcCfg[IoHwAb_AdcNumOfGroup[IoHwAb_CurrentMuxGroup].Offset].IoHwAb_AdcGroup[IoHwAb_AdcStatus.AdcVariantId].MuxChannel )
            {
                MuxSelect = IoHwAb_AdcCfg[IoHwAb_AdcNumOfGroup[IoHwAb_CurrentMuxGroup].Offset].IoHwAb_AdcGroup[IoHwAb_AdcStatus.AdcVariantId].MuxChannelId;
                /* Select group and input based on current mux group*/
                IoHwAb_AdcDioSelectMux( (IoHwAb_AdcNumOfGroup[IoHwAb_CurrentMuxGroup].AdcGroupId), MuxSelect );
                /* Start ADC gpt timer for delay*/
                SuspendAllInterrupts();
                IoHwAb_AdcMuxStatus = eAdcMux_InProgressTimer;
                IoHwAb_Gpt_StartTimer((Gpt_ChannelType)IOHWAB_MUX_DELAY_TIMER,(Gpt_ValueType)(IOHWAB_MUX_DELAY_TIME_USEC * IOHWAB_MUX_TIMER_FREQ_MHZ));
                ResumeAllInterrupts();
			}
        }
        else
        {
            /* Finished */
            IoHwAb_CurrentMuxGroup = IOHWAB_FIRST_MUX_GROUP_ID;
            IoHwAb_AdcMuxStatus = eAdcMux_Idle;
        }
    }
    else
    {
        IoHwAb_AdcMuxStatus = eAdcMux_ErrReadGroup;
    }
}


void IoHwAb_AdcTimerIsr(void)
{
    IoHwAb_Adc_StatusType AdcGroupStatus;
    Std_ReturnType JobResult = E_NOT_OK;

    if (IoHwAb_AdcMuxStatus == eAdcMux_NotInit) 
    {
        return;
    }

    AdcGroupStatus =  IoHwAb_Adc_GetGroupStatus((Adc_GroupType)IoHwAb_AdcNumOfGroup[IoHwAb_CurrentMuxGroup].AdcGroupId);
    if(AdcGroupStatus != IOHWAB_ADC_IDLE)
    {
        IoHwAb_Adc_StopGroupConversion((Adc_GroupType)IoHwAb_AdcNumOfGroup[IoHwAb_CurrentMuxGroup].AdcGroupId);
    }
    JobResult = IoHwAb_Adc_SetupResultBuffer((Adc_GroupType)IoHwAb_AdcNumOfGroup[IoHwAb_CurrentMuxGroup].AdcGroupId, &AdcGroupBuffer[IoHwAb_AdcNumOfGroup[IoHwAb_CurrentMuxGroup].Offset]);
    if(JobResult == E_OK)
    {
        
        IoHwAb_Adc_StartGroupConversion((Adc_GroupType)IoHwAb_AdcNumOfGroup[IoHwAb_CurrentMuxGroup].AdcGroupId);
        IoHwAb_AdcMuxStatus = eAdcMux_InProgressADC;
    }
    else
    {
        IoHwAb_AdcStatus.MultiChannelAdcReadStatus[IoHwAb_CurrentMuxGroup] = IOHWAB_ADC_BUFFER_NOT_INITIALISED;
        IoHwAb_AdcMuxStatus = eAdcMux_ErrParam;
    }


    /* Start timer for timeout  : TBD*/

    /* if timeout happens, Stop group conversion to reset it and start again.  : TBD*/

}

#endif


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
/*****************************************************************************
Date              :22-Aug-2018
By                :pragesh
Traceability      :RTC-1181436:MMC: Safe IoHwAb Delivery
Change Description:Initial Version for IoHwAb safe implementation
******************************************************************************/
/*****************************************************************************
Date              :21-Nov-2018
By                :bbaskara
Traceability      :RTC-1240711: MMC: IohwAb safe critical review comment fix
Change Description:Removed Jobstatus check in IoHwAb_DIn_GetSyncRawValue.
******************************************************************************/
/*****************************************************************************
Date              :23-Nov-2018
By                :bbaskara
Traceability      :RTC-1243011: MMC: IohwAb safe MISRA Fix
Change Description:Fixed MISRA warning.
******************************************************************************/
/*****************************************************************************
Date              :17-Feb-2019
By                :bjayara2
Traceability      :RTC-1273840: Integration of IoHWAb component from MMC and SP2
Change Description: Fixed an issue found in compilation
******************************************************************************/
/*****************************************************************************
Date              :04-Apr-2019
By                :asivalin
Traceability      :Defect #1308842: SP2: Battery voltage read value is not correct
Change Description:Removed IoHwAb_AdcResult[Index].ProcessedValue update in IoHwAb_Adc_GetProcessedAdc.
******************************************************************************/
/*****************************************************************************
Date              :12-Apr-2019
By                :msavariy
Traceability      :1312749: P33 Safe:- Integrate Bookshelf IoHwAb and implement multiple ADC HW group
Change Description: Added support for Multible ADC HW Unit.
******************************************************************************/
/*****************************************************************************
Date              :14-May-2019
By                :msavariy
Traceability      :1323692: Bookshelf Safe component PT1 Filter Implementation
Change Description: Added support for PT1 Filtering for Analog Inputs
******************************************************************************/
/*****************************************************************************
Date              :28-Oct-2019
By                :athiyag2
Traceability      :1381859: ADC timeout monitoring - Implementation
Change Description: Added timeout monitoring for asynchronous ADC Conversion
******************************************************************************/
/*****************************************************************************
Date              :30-Oct-2019
By                :svenka21
Traceability      :1362312: Misra warning fix based on Visteon_ruleset6.0
Change Description:Misra warning fixes
******************************************************************************/
/*****************************************************************************
Date              :24-Jan-2020
By                :PPARIMI1
Traceability      :1399148: Renault PY1B OSBSP - Functional safety ADC timeout monitoring
Change Description:Added timeout monitoring for asynchronous ADC Conversion
******************************************************************************/
/*****************************************************************************
Date              :13-Mar-2020
By                :MSAVARIY
Traceability      : 808643: [Honda BEV] IoHwAb configuration
Change Description: MUX ADC support added
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
/*****************************************************************************
Date              :18-Aug-2023
By                :abandlap
Traceability      :vAutosar IoHwAb Streamline Update
Change Description:Added a conditional check for mux implementation
******************************************************************************/
