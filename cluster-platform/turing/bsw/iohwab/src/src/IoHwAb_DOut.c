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
* @file IoHwAb_DOut.c
* @brief Capturing of external pulse input and calculate the period & duty values.
* ****************************************************************************/
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/
#include "IoHwAb_DOut.h"
#include "Rte_IoHwAb.h"
/* To check if Digital Output is enabled*/
#if (IOHWAB_DOUT_ENABLE == STD_ON)
/*****************************************************************************
*  Type Declarations                                                      	 *
******************************************************************************/
/**
* @brief This structure defines states of Digital output adapter
*/
/* MISRA C-2012 Rule 2.3 JUSTIFICATION: Type IoHwAb_DoutJobStatusType is defined as per design. It is used for future purpose.*/
typedef enum
{
    IOHWAB_DOUT_JOB_OK,
    IOHWAB_DOUT_JOB_NOT_OK,
} IoHwAb_DoutJobStatusType;

typedef struct
{
    boolean                     RefreshValue;
    boolean                     ValidRefreshValue;
} IoHwAb_DoutManagementType;
/**
* @brief This structure defines different status variables of Digital output adapter
*/
typedef struct
{
    uint16                  RefreshCount;
    uint8                   DOutVariantId;      /**< Digital Output Variant Id */
} IoHwAb_DOutStatusType;

/*****************************************************************************
*  Private Variable Definitions                                              *
******************************************************************************/
#define IoHwAb_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
/* MISRA C-2012 Rule 20.1 JUSTIFICATION: As per Autosar Standard,IoHwAb_MemMap.h is used to map memory segments in IoHwAb.*/
#include <IoHwAb_MemMap.h>

static IoHwAb_DOutStatusType IoHwAb_DOutStatus;                                     /**<  Digital output variant Id*/
static IoHwAb_DoutManagementType IoHwAb_DoutManagement[IOHWAB_NUM_DOUT_OUTPUT];     /**<  stores the digital output values for refreshing*/

#define IoHwAb_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
/* MISRA C-2012 Rule 20.1 JUSTIFICATION: As per Autosar Standard,IoHwAb_MemMap.h is used to map memory segments in IoHwAb.*/
#include <IoHwAb_MemMap.h>
/******************************************************************************
*  Private Function Declarations                                                *
*******************************************************************************/
static void IoHwAb_DOut_PeriodicRefresh(void);
/******************************************************************************
*  Public Function Definitions                                                *
*******************************************************************************/
#define IoHwAb_START_SEC_CODE
/* MISRA C-2012 Rule 20.1 JUSTIFICATION: As per Autosar Standard,IoHwAb_MemMap.h is used to map memory segments in IoHwAb.*/
#include <IoHwAb_MemMap.h>
/**
* This method initialize the IoHwAb digital output module
* @param     none
* @return    void
*/
void IoHwAb_DOut_Init(void)
{
    uint16 Index;
    Std_ReturnType VariantResult;

    VariantResult = IoHwAb_DOut_GetCurrentVariant(&IoHwAb_DOutStatus.DOutVariantId);

    if((uint8)E_OK != VariantResult)
    {
        IoHwAb_DOutStatus.DOutVariantId = IOHWAB_MAX_NUM_OF_DOUT_VARIANTS;
    }
    if( IoHwAb_DOutStatus.DOutVariantId >= IOHWAB_MAX_NUM_OF_DOUT_VARIANTS)
    {
        /* Init the Refresh value*/
        for(Index = 0u ; Index < IOHWAB_NUM_DOUT_OUTPUT; Index ++)
        {
            IoHwAb_DoutManagement[Index].RefreshValue = (boolean)FALSE;
            IoHwAb_DoutManagement[Index].ValidRefreshValue = (boolean)FALSE;
        }
    }
    else
    {
        /* Init the Refresh value*/
        for(Index = 0u ; Index < IOHWAB_NUM_DOUT_OUTPUT; Index ++)
        {
            IoHwAb_DoutManagement[Index].RefreshValue = (boolean)IoHwAb_DOutCfg[Index].IoHwAb_DOutChannel[IoHwAb_DOutStatus.DOutVariantId].InitValue;
            IoHwAb_DoutManagement[Index].ValidRefreshValue = (boolean)TRUE;
        }
    }
    /* Init the Refresh count*/
    IoHwAb_DOutStatus.RefreshCount = 0u;

}
/**
* This method Deinitialize the IoHwAb digital output module
* @param     none
* @return    void
*/
void IoHwAb_DOut_DeInit(void)
{
    uint16 Index;
    /* Init the Refresh value*/
    for(Index = 0u ; Index < IOHWAB_NUM_DOUT_OUTPUT; Index ++)
    {
        IoHwAb_DoutManagement[Index].RefreshValue = (boolean)IoHwAb_DOutCfg[Index].IoHwAb_DOutChannel[IoHwAb_DOutStatus.DOutVariantId].InitValue;
        IoHwAb_DoutManagement[Index].ValidRefreshValue = (boolean)TRUE;
    }
    /* Init the Refresh count*/
    IoHwAb_DOutStatus.RefreshCount = 0u;
}
/**
* This method is the main function for IoHwAb digital output module
* @param     none
* @return    void
*/
void IoHwAb_DOut_MainFunction(void)
{
    Std_ReturnType VariantResult;
    Std_ReturnType ProcessMainFunction = E_OK;
    if((uint8)E_OK != IoHwAb_DOut_PreHook())
    {
        ProcessMainFunction = E_NOT_OK;
    }
    VariantResult = IoHwAb_DOut_GetCurrentVariant(&IoHwAb_DOutStatus.DOutVariantId);
    if((uint8)E_OK != VariantResult)
    {
        IoHwAb_DOutStatus.DOutVariantId = IOHWAB_MAX_NUM_OF_DOUT_VARIANTS;
        ProcessMainFunction = E_NOT_OK;
    }
    if(IoHwAb_DOutStatus.DOutVariantId >= IOHWAB_MAX_NUM_OF_DOUT_VARIANTS)
    {
        ProcessMainFunction = E_NOT_OK;
    }
    if((uint8)E_OK == ProcessMainFunction)
    {
        IoHwAb_DOut_PeriodicRefresh();
    }
}

/**
* This method is used to set the Output Pin
* @param     OutputId 		- ID of the Output signal
* @param     OutputSignal   - Value needs to be set for Output signal
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_DOut_SetOutputPin(IoHwAb_DOutSignalIdType OutputId, boolean OutputSignal, IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType JobResult = E_OK;
    uint16 Index;
    Dio_LevelType OutputBuffer;
    IoHwAb_DOutSourceSignalType hwSourceSignal;

    if(IoHwAb_DOutStatus.DOutVariantId >= IOHWAB_MAX_NUM_OF_DOUT_VARIANTS)
    {
        JobResult = E_NOT_OK;
        *ErrorStatus = IOHWAB_E_DOUT_ID_INVALID;
    }
    else
    {
        for(Index = 0u ; Index < IOHWAB_NUM_DOUT_OUTPUT; Index ++)
        {
            if (OutputId == IoHwAb_DOutCfg[Index].SignalId)
            {
                break;
            }
        }
        if(Index >= IOHWAB_NUM_DOUT_OUTPUT)
        {
            JobResult = E_NOT_OK;
            *ErrorStatus = IOHWAB_E_DOUT_ID_INVALID;
        }
        else
        {  
            if((boolean)FALSE != OutputSignal)
            {
                OutputBuffer = (Dio_LevelType)1;
            }
            else
            {
                OutputBuffer = (Dio_LevelType)0;
            }
            /* Convert the output to active level*/
            if(IOHWAB_DOUT_ACTIVE_HIGH != IoHwAb_DOutCfg[Index].IoHwAb_DOutChannel[IoHwAb_DOutStatus.DOutVariantId].ActiveLevel)
            {
                if(0U != OutputBuffer)
                {
                    OutputBuffer = (Dio_LevelType)0;
                }
                else
                {
                    OutputBuffer = (Dio_LevelType)1;
                }
            }

            hwSourceSignal = IoHwAb_DOutCfg[Index].IoHwAb_DOutChannel[IoHwAb_DOutStatus.DOutVariantId].SourceSignalId;
            /* Write the output to mcal dio*/
            IoHwAb_Dio_WriteChannel(IoHwAb_DOutCfg[Index].IoHwAb_DOutChannel[IoHwAb_DOutStatus.DOutVariantId].Hw_ChannelId, OutputBuffer, hwSourceSignal);
            /* Update the output value to refresh value for periodic refreshing*/
            IoHwAb_DoutManagement[Index].RefreshValue = OutputBuffer;
            IoHwAb_DoutManagement[Index].ValidRefreshValue = (boolean)TRUE;
            /* Set the error status and return status to OK*/
            *ErrorStatus = IOHWAB_E_NO_ERROR;    
        }
    }
    return JobResult;
}

/**
* This method is used to set the output as a group of output pins
* @param     OutputGroupId 	- ID of the Output group
* @param     OutputGroup    - Value needs to be set for Output signal- each bit is considered as single output signal
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
/* MISRA C-2012 Rule 2.7 JUSTIFICATION: The parameter ErrorStatus is declared as per code design. It is used for future purpose.*/
/* MISRA C-2012 Rule 2.7 JUSTIFICATION: The parameter OutputGroup is declared as per code design. It is used for future purpose.*/
/* MISRA C-2012 Rule 2.7 JUSTIFICATION: The parameter OutputGroupId is declared as per code design. It is used for future purpose.*/
/* MISRA C-2012 Rule 8.13 JUSTIFICATION: As per code design, IoHwAb_DOut_SetOutputGroup parameters are declared. This implementation is used for future purpose.*/
Std_ReturnType IoHwAb_DOut_SetOutputGroup(IoHwAb_DOutGroupIdType OutputGroupId, uint32 OutputGroup,const IoHwAb_ErrorType* ErrorStatus)
{
    (void)OutputGroupId;
    (void)OutputGroup;
    (void)ErrorStatus;
    return E_NOT_OK;
}

/**
* This method will write the digital outputs periodically to refresh the state. Refreshing is done in specific counts per cycle
* to reduce the cpu load
* @param     none
* @return    void
*/
static void IoHwAb_DOut_PeriodicRefresh(void)
{
    uint16 Index;
    uint16 CurrentCycleRefreshCount = 0u;
    Dio_LevelType OutputBuffer;
    boolean Temp;
    IoHwAb_DOutSourceSignalType hwSourceSignal;

    /* Init the Refresh value*/
    for(Index = 0u ; Index < IOHWAB_NUM_DOUT_OUTPUT; Index ++)
    {
        if(IoHwAb_DoutManagement[Index].ValidRefreshValue == (boolean)FALSE)
        {
            IoHwAb_DoutManagement[Index].RefreshValue = (boolean)IoHwAb_DOutCfg[Index].IoHwAb_DOutChannel[IoHwAb_DOutStatus.DOutVariantId].InitValue;
            IoHwAb_DoutManagement[Index].ValidRefreshValue = (boolean)TRUE;
        }
    }

    /* Write the mcal dio for every pin in a fixed count per cycle*/
    for(Index = IoHwAb_DOutStatus.RefreshCount ; (Index < IOHWAB_NUM_DOUT_OUTPUT)&&(CurrentCycleRefreshCount < IOHWAB_REFRESH_PERCYCLE); Index ++)
    {
        if((boolean)FALSE != IoHwAb_DoutManagement[Index].ValidRefreshValue)
        {
            Temp = IoHwAb_DoutManagement[Index].RefreshValue;
            if((boolean)FALSE != Temp)
            {
                OutputBuffer = (Dio_LevelType)1;
            }
            else
            {
                OutputBuffer = (Dio_LevelType)0;
            }

            hwSourceSignal = IoHwAb_DOutCfg[Index].IoHwAb_DOutChannel[IoHwAb_DOutStatus.DOutVariantId].SourceSignalId;
            IoHwAb_Dio_WriteChannel(IoHwAb_DOutCfg[Index].IoHwAb_DOutChannel[IoHwAb_DOutStatus.DOutVariantId].Hw_ChannelId, OutputBuffer, hwSourceSignal);
        }
        /* MISRA C-2012 Rule 14.2 JUSTIFICATION: The value of CurrentCycleRefreshCount is checked and it is modified in the function as code design. Hence does not have any functional impact.*/
        CurrentCycleRefreshCount++;
        IoHwAb_DOutStatus.RefreshCount++;
    }
    /* Clear the refresh count when it is greater than or equal to number of outputs*/
    if(IoHwAb_DOutStatus.RefreshCount >= IOHWAB_NUM_DOUT_OUTPUT)
    {
        IoHwAb_DOutStatus.RefreshCount = 0u;
    }
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
