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
* @file IoHwAb_DIn.c
* @brief Capturing and processing of digital inputs
* ****************************************************************************/
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/
#include "IoHwAb_DIn.h"
#include "IoHwAb_Filter.h"
#include "Rte_IoHwAb.h"
/*To check if Digital Input is enabled */
#if (IOHWAB_DIN_ENABLE == STD_ON)

typedef enum
{
    IOHWAB_DIN_JOB_OK = 0,
    IOHWAB_DIN_JOB_ERROR
} IoHwAb_DinJobResultType;


/*****************************************************************************
*  Type Definitions                                                          *
******************************************************************************/
/**
* @brief This structure defines results for Digital input
*/
typedef struct
{
    boolean                 Hw_Value;                                       /**< variable to store the input value read from mcal */
    IoHwAb_DinJobResultType JobResult;
} IoHwAb_DInResultType;
/**
* @brief This structure defines different status variables of Digital input adapter
*/
typedef struct
{
    uint8                   DInVariantId;                   /**< Digital Inpt variant id */
} IoHwAb_DInStatusType;

/*****************************************************************************
*  Private Variable Definitions                                              *
******************************************************************************/
#define IoHwAb_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
/* MISRA C-2012 Rule 20.1 JUSTIFICATION: As per Autosar Standard,IoHwAb_MemMap.h is used to map memory segments in IoHwAb.*/
#include <IoHwAb_MemMap.h>

static IoHwAb_DInStatusType  IoHwAb_DInStatus;                                   /**<  Digital input variant Id*/
static IoHwAb_DInResultType  IoHwAb_DInResult[IOHWAB_NUM_DIN_INPUT];      /**< stores the results for of digital inputs different variants */

#define IoHwAb_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
/* MISRA C-2012 Rule 20.1 JUSTIFICATION: As per Autosar Standard,IoHwAb_MemMap.h is used to map memory segments in IoHwAb.*/
#include <IoHwAb_MemMap.h>

/******************************************************************************
*  Public Function Definitions                                                *
*******************************************************************************/
#define IoHwAb_START_SEC_CODE
/* MISRA C-2012 Rule 20.1 JUSTIFICATION: As per Autosar Standard,IoHwAb_MemMap.h is used to map memory segments in IoHwAb.*/
#include <IoHwAb_MemMap.h>
/**
* This method initialize the IoHwAb digital input module
* @param     none
* @return    void
*/
void IoHwAb_DIn_Init(void)
{
    uint16 InputIndex;
    Std_ReturnType Result;
    /* Init the hardware value*/
    for(InputIndex = 0u ; InputIndex < IOHWAB_NUM_DIN_INPUT; InputIndex ++)
    {
        IoHwAb_DInResult[InputIndex].Hw_Value =  (boolean)0;
        IoHwAb_DInResult[InputIndex].JobResult =  IOHWAB_DIN_JOB_ERROR;
    }
    /* Init digital input variant id*/
    /* Receive the Adc variant id from swc*/
    Result = IoHwAb_DIn_GetCurrentVariant(&IoHwAb_DInStatus.DInVariantId);

    if((uint8)E_OK != Result)
    {
        IoHwAb_DInStatus.DInVariantId = IOHWAB_MAX_NUM_OF_DIN_VARIANTS;
    }
}
/**
* This method initialize the IoHwAb digital input module
* @param     none
* @return    void
*/
void IoHwAb_DIn_DeInit(void)
{
    uint16 InputIndex;
    /* Init the hardware value*/
    for(InputIndex = 0u ; InputIndex < IOHWAB_NUM_DIN_INPUT; InputIndex ++)
    {
        IoHwAb_DInResult[InputIndex].Hw_Value =  (boolean)0;
        IoHwAb_DInResult[InputIndex].JobResult =  IOHWAB_DIN_JOB_ERROR;
    }
}

/**
* This method is the main function for IoHwAb digital input module
* @param     none
* @return    void
*/
void IoHwAb_DIn_MainFunction(void)
{
    uint16 Index;
    Std_ReturnType Result;
    Std_ReturnType ProcessMainFunction = E_OK;
    Dio_LevelType Temp;
    uint32 hwChannelId;
    IohwAb_DInSourceSignalType hwSourceSignal;

    Result = IoHwAb_DIn_GetCurrentVariant(&IoHwAb_DInStatus.DInVariantId);

    if (((uint8)E_OK != Result) || (IoHwAb_DInStatus.DInVariantId >= IOHWAB_MAX_NUM_OF_DIN_VARIANTS))
    {
        IoHwAb_DInStatus.DInVariantId =IOHWAB_MAX_NUM_OF_DIN_VARIANTS;
        ProcessMainFunction = E_NOT_OK;
    }
    else if ((uint8)E_OK != IoHwAb_DIn_PreHook())
    {
        ProcessMainFunction = E_NOT_OK;
    }
    else
    {
        //do nothing
    }
    if((uint8)E_OK == ProcessMainFunction)
    {
        for (Index = 0u; Index < IOHWAB_NUM_DIN_INPUT; Index++)
        {
            if(IoHwAb_DInStatus.DInVariantId < IOHWAB_MAX_NUM_OF_DIN_VARIANTS)
            {
                hwChannelId = IoHwAb_DInCfg[Index].IoHwAb_DInChannel[IoHwAb_DInStatus.DInVariantId].Hw_ChannelId;
                hwSourceSignal = IoHwAb_DInCfg[Index].IoHwAb_DInChannel[IoHwAb_DInStatus.DInVariantId].SourceSignalId;
                /* Read the input from MCAL dio */
                Temp = IoHwAb_Dio_ReadChannel(hwChannelId, hwSourceSignal);

                /* Determine the hardware value based on read input and active level */
                if (Temp != 0U)
                {
                    IoHwAb_DInResult[Index].Hw_Value = (boolean)TRUE;
                    if(IOHWAB_DIN_ACTIVE_LOW == IoHwAb_DInCfg[Index].IoHwAb_DInChannel[IoHwAb_DInStatus.DInVariantId].ActiveLevel)
                    {
                        IoHwAb_DInResult[Index].Hw_Value = (boolean)FALSE;
                    }
                }
                else
                {
                    IoHwAb_DInResult[Index].Hw_Value = (boolean)FALSE;
                    if(IOHWAB_DIN_ACTIVE_LOW == IoHwAb_DInCfg[Index].IoHwAb_DInChannel[IoHwAb_DInStatus.DInVariantId].ActiveLevel)
                    {
                        IoHwAb_DInResult[Index].Hw_Value = (boolean)TRUE;
                    }
                }
                /* Set the raw value to digital debounce filter*/
                Result = IoHwAb_Filter_SetDigitalDebounce(IoHwAb_DInCfg[Index].IoHwAb_DInChannel[IoHwAb_DInStatus.DInVariantId].DebGroupId, IoHwAb_DInCfg[Index].IoHwAb_DInChannel[IoHwAb_DInStatus.DInVariantId].DebChannelId, IoHwAb_DInResult[Index].Hw_Value);
                if((uint8)E_NOT_OK != Result)
                {
                    IoHwAb_DInResult[Index].JobResult = IOHWAB_DIN_JOB_OK;
                }
                else
                {
                    IoHwAb_DInResult[Index].JobResult = IOHWAB_DIN_JOB_ERROR;
                }
                
            }
            else
            {
                IoHwAb_DInResult[Index].JobResult = IOHWAB_DIN_JOB_ERROR;
            }
        }
	    
	}
}

/**
* This method is used to get the input value after processing
* @param     InputId 		- ID of the input signal
* @param     ProcessedValue - parameter to get the value of the input signal
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_DIn_GetProcessedValue(IoHwAb_DInSignalIdType InputId, boolean* ProcessedValue, IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType ResultStatus = E_OK;
    uint16 Index;
    if(IoHwAb_DInStatus.DInVariantId >= IOHWAB_MAX_NUM_OF_DIN_VARIANTS)
    {
        *ErrorStatus = IOHWAB_E_DIN_ID_INVALID;
        ResultStatus = E_NOT_OK;
    }
    else
    {
        for(Index = 0u ; Index < IOHWAB_NUM_DIN_INPUT; Index ++)
        {
            if (InputId == IoHwAb_DInCfg[Index].SignalId)
            {
                break;
            }
        }
        if(Index >= IOHWAB_NUM_DIN_INPUT)
        {
            *ErrorStatus = IOHWAB_E_DIN_ID_INVALID;
            ResultStatus = E_NOT_OK;
        }
        else
        {
            if(IOHWAB_DIN_JOB_OK != IoHwAb_DInResult[Index].JobResult)
            {
                *ErrorStatus = IOHWAB_E_ERROR;
                ResultStatus = E_NOT_OK;
            }
            
            if((uint8)E_OK == ResultStatus)
            {
                /* Get the debounced value from digital debounce filter*/
                ResultStatus = IoHwAb_Filter_GetDigitalDebounceValue(IoHwAb_DInCfg[Index].IoHwAb_DInChannel[IoHwAb_DInStatus.DInVariantId].DebGroupId, \
                            IoHwAb_DInCfg[Index].IoHwAb_DInChannel[IoHwAb_DInStatus.DInVariantId].DebChannelId, \
                            ProcessedValue);
                if((uint8)E_OK != ResultStatus)
                {
                    *ErrorStatus = IOHWAB_E_ERROR;
                    ResultStatus = E_NOT_OK;
                }
                else
                {
                    *ErrorStatus = IOHWAB_E_NO_ERROR;
                }
            }
        }
    }
    return ResultStatus;
}
/**
* This method is used to get the raw input value from the stored buffer- Asynchronous
* @param     InputId 		- ID of the input signal
* @param     AsyncRawValue  - parameter to get the value of the input signal
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_DIn_GetASyncRawValue(IoHwAb_DInSignalIdType InputId, boolean* AsyncRawValue, IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType ResultStatus = E_OK;
    uint16 Index;
    if(IoHwAb_DInStatus.DInVariantId >= IOHWAB_MAX_NUM_OF_DIN_VARIANTS)
    {
        *ErrorStatus = IOHWAB_E_DIN_ID_INVALID;
        ResultStatus = E_NOT_OK;
    }
    for(Index = 0u ; Index < IOHWAB_NUM_DIN_INPUT; Index ++)
    {
        if (InputId == IoHwAb_DInCfg[Index].SignalId)
        {
            break;
        }
    }
    if(Index >= IOHWAB_NUM_DIN_INPUT)
    {
        *ErrorStatus = IOHWAB_E_DIN_ID_INVALID;
        ResultStatus = E_NOT_OK;
    }
    else
    {
        if(IOHWAB_DIN_JOB_OK != IoHwAb_DInResult[Index].JobResult)
        {
            *ErrorStatus = IOHWAB_E_ERROR;
            ResultStatus = E_NOT_OK;
        }
    }
    if((uint8)E_OK == ResultStatus)
    {
        *AsyncRawValue = IoHwAb_DInResult[Index].Hw_Value;
        *ErrorStatus = IOHWAB_E_NO_ERROR;
    }
    return ResultStatus;
}

/**
* This method is used to get the raw input value synchronously reading MCAL
* @param     InputId 		- ID of the input signal
* @param     SyncRawValue   - parameter to get the value of the input signal
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_DIn_GetSyncRawValue(IoHwAb_DInSignalIdType InputId, boolean* SyncRawValue, IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType ResultStatus = E_OK;
    Dio_LevelType TempValue;
    uint16 Index;
    IohwAb_DInSourceSignalType hwSourceSignal;

    if(IoHwAb_DInStatus.DInVariantId >= IOHWAB_MAX_NUM_OF_DIN_VARIANTS)
    {
        *ErrorStatus = IOHWAB_E_DIN_ID_INVALID;
        ResultStatus = E_NOT_OK;
    }
    else
    {
        for(Index = 0u ; Index < IOHWAB_NUM_DIN_INPUT; Index ++)
        {
            if (InputId == IoHwAb_DInCfg[Index].SignalId)
            {
                break;
            }
        }
        if(Index >= IOHWAB_NUM_DIN_INPUT)
        {
            *ErrorStatus = IOHWAB_E_DIN_ID_INVALID;
            ResultStatus = E_NOT_OK;
        }
        else
        {
            /* Read the input from MCAL dio*/
            hwSourceSignal = IoHwAb_DInCfg[Index].IoHwAb_DInChannel[IoHwAb_DInStatus.DInVariantId].SourceSignalId;
            TempValue = IoHwAb_Dio_ReadChannel(IoHwAb_DInCfg[Index].IoHwAb_DInChannel[IoHwAb_DInStatus.DInVariantId].Hw_ChannelId, hwSourceSignal);

            if(0U != TempValue)
            {
                *SyncRawValue = (boolean)TRUE;
                if(IOHWAB_DIN_ACTIVE_LOW == IoHwAb_DInCfg[Index].IoHwAb_DInChannel[IoHwAb_DInStatus.DInVariantId].ActiveLevel)
                {
                    /* Convert the input to active level*/
                    *SyncRawValue = (boolean)FALSE;
                }
            }
            else
            {
                *SyncRawValue = (boolean)FALSE;
                if(IOHWAB_DIN_ACTIVE_LOW == IoHwAb_DInCfg[Index].IoHwAb_DInChannel[IoHwAb_DInStatus.DInVariantId].ActiveLevel)
                {
                    /* Convert the input to active level*/
                    *SyncRawValue = (boolean)TRUE;
                }
            }
            *ErrorStatus = IOHWAB_E_NO_ERROR;
        }
    }
    return ResultStatus;
}

/**
* This method is used to get the raw input value from the stored buffer- Asynchronous
* @param     InputGroupId 	- ID of the input signal
* @param     InputGroup     - parameter  to be get the input group- each bit holds the value of each single input signal
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
/* MISRA C-2012 Rule 2.7 JUSTIFICATION: The parameter InputGroup is declared as per code design. It is used for future purpose.*/
/* MISRA C-2012 Rule 2.7 JUSTIFICATION: The parameter InputGroupId is declared as per code design. It is used for future purpose.*/
/* MISRA C-2012 Rule 8.13 JUSTIFICATION: As per code design, IoHwAb_DIn_GetGroup parameters are declared. This implementation is used for future purpose.*/
Std_ReturnType IoHwAb_DIn_GetGroup(IoHwAb_DInGroupIdType InputGroupId, const uint32* InputGroup, IoHwAb_ErrorType* ErrorStatus)
{
    (void)InputGroupId;
    (void)InputGroup;
    *ErrorStatus = IOHWAB_E_ERROR;
    return E_NOT_OK;
}

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
