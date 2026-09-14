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
 * @file IoHwAb_Adc_Cfg.c
 * @brief Configuration definitions for adc inputs
 * ****************************************************************************/
/*****************************************************************************
 *  Include Files                                                             *
 ******************************************************************************/
#include "IoHwAb_Adc_Cfg.h"
#include "Rte_IoHwAb.h"

#if (IOHWAB_ADC_ENABLE == STD_ON)
/*****************************************************************************
 *  Configuration Definitions                                                 *                                                                                       *
 ******************************************************************************/
#define IoHwAb_START_SEC_CONST_UNSPECIFIED
#include <IoHwAb_MemMap.h>

/**
* @brief Filters and their array index used for Analog signals
*/

const uint8 IoHwAb_AdcFilterIndex_AI_SAMPLE_1[IOHWAB_MAX_FILTER_INDEX] =
{
    0u,  /* Reserved*/
    0u,  /* IOHWAB_ENCODED_ADC   */
    0u,  /* IOHWAB_RESOLUTION_ADC       */
    0u,  /* IOHWAB_DEBOUNCE_ADC  */
    0u,  /* IOHWAB_PT1_ADC*/
    0u,  /* Reserved*/
    0u,  /* Reserved*/
    0u   /* Reserved*/
};
const uint8 IoHwAb_AdcFilterIndex_AI_SAMPLE_2[IOHWAB_MAX_FILTER_INDEX] =
{
    0u,  /* Reserved*/
    0u,  /* IOHWAB_ENCODED_ADC   */
    0u,  /* IOHWAB_RESOLUTION_ADC       */
    0u,  /* IOHWAB_DEBOUNCE_ADC  */
    0u,  /* IOHWAB_PT1_ADC*/
    0u,  /* Reserved*/
    0u,  /* Reserved*/
    0u   /* Reserved*/
};
const IoHwAb_AdcNumOfGroupType IoHwAb_AdcNumOfGroup[IOHWAB_NUM_ADC_GROUP] =
{
  {0, 9, 1},
  {1, 14, 1},
};

/**
 * @brief Definition of configuration parameters for Analog inputs
 */
const IoHwAb_AdcCfgType IoHwAb_AdcCfg[IOHWAB_NUM_ADC_INPUT] = 
{
    {
        {
            /* Variant 1 */
            {
                0U,                                                    /* Ratioed Adc Multiplier*/
                0U,        /* Single Channel Group ID*/
                0u,                                                      /* Adc Index for Multi Channel*/
                0u,                                                      /* Ratioed Adc Ref Channel Index*/
                #if (IOHWAB_ADC_MUX == STD_ON)
                FALSE, /* Is This Mux Channel? */
                0u, /* Mux Channel Id*/
                0u /* Mux Group Id*/
                #endif
            }
        },
        (uint8 *)&IoHwAb_AdcFilterIndex_AI_SAMPLE_1[0], /* Adc filter id*/
        IOHWAB_ADC0_FILTER,                                        /* Adc filter type*/
        eIO_ADC_AI_SAMPLE_1                             /* Adc software signal id*/
    },
    {
        {
            /* Variant 1 */
            {
                0U,                                                   /* Ratioed Adc Multiplier*/
                1U,       /* Single Channel Group ID*/
                1u,                                                    /* Adc Index for Multi Channel*/
                0u,                                                    /* Ratioed Adc Ref Channel Index*/
                #if (IOHWAB_ADC_MUX == STD_ON)
                FALSE, /* Is This Mux Channel? */
                0u, /* Mux Channel Id*/
                0u /* Mux Group Id*/
                #endif
            }
        },
        (uint8 *)&IoHwAb_AdcFilterIndex_AI_SAMPLE_2[0],/* Adc filter id*/
        IOHWAB_ADC1_FILTER,                                      /* Adc filter type*/
        eIO_ADC_AI_SAMPLE_2                            /* Adc software signal id*/
    },
};

#if (IOHWAB_ADC_MUX == STD_ON)
const IoHwAb_AdcDioMuxGroupCfgType IoHwAb_AdcDioMuxGroup[IOHWAB_NUM_OF_MUX_GROUP] = {
  {
    {
      {DioConf_DioChannel_DioChannel_ANA_MUX_S0, 0u},
      {DioConf_DioChannel_DioChannel_ANA_MUX_S1, 0u},
      {DioConf_DioChannel_DioChannel_ANA_MUX_S2, 0u}
    },
    AdcConf_AdcGroupId_AdcGroup_ANA_COM
  }
};
#endif

#define IoHwAb_STOP_SEC_CONST_UNSPECIFIED
#include <IoHwAb_MemMap.h>

/*****************************************************************************
 *  Private Function Definitions                                              *                                                                                       *
 ******************************************************************************/

#define IoHwAb_START_SEC_CODE
#include <IoHwAb_MemMap.h>

/**
 * This method is used to get the current vehicle variant for adc inputs
 * @param     AdcVariantId   - variable to get the varient number
 * @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
 */
Std_ReturnType IoHwAb_Adc_GetCurrentVariant(uint8* AdcVariantId)
{
  *AdcVariantId = 0U;
  return E_OK;
}

/**
 * This method is used to check any precondition before reading the adc inputs
 * @param     void
 * @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
 */
Std_ReturnType IoHwAb_Adc_PreHook(void)
{
  return E_OK;
}



Std_ReturnType IoHwAb_Adc_SetupResultBuffer(uint8 Group, uint16* Buffer)
{
    return 0;
}
void IoHwAb_Adc_StartGroupConversion(uint8 Group)
{
}
void IoHwAb_Adc_StopGroupConversion(uint8 Group)
{
}
Std_ReturnType IoHwAb_Adc_ReadGroup(uint8 Group, uint16* Buffer)
{
    return 0;
}
void IoHwAb_Adc_EnableHardwareTrigger(uint8 Group)
{
}
void IoHwAb_Adc_DisableHardwareTrigger(uint8 Group)
{
}
void IoHwAb_Adc_EnableGroupNotification(uint8 Group)
{
}
void IoHwAb_Adc_DisableGroupNotification(uint8 Group)
{
}
uint8 IoHwAb_Adc_GetGroupStatus(uint8 Group)
{
    return 0;
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
/*****************************************************************************
 Date              :22-Aug-2018
 By                :pragesh
 Traceability      :RTC-1181436:MMC: Safe IoHwAb Delivery
 Change Description:Initial Version for IoHwAb safe implementation
 ******************************************************************************/
/*****************************************************************************
Date              :13-Mar-2020
By                :MSAVARIY
Traceability      : 808643: [Honda BEV] IoHwAb configuration
Change Description: MUX ADC support added
******************************************************************************/
