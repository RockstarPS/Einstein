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
#include "IoHwAb_Adc.h"

#if (IOHWAB_ADC_ENABLE == STD_ON)
/*****************************************************************************
 *  Configuration Definitions                                                 *                                                                                       *
 ******************************************************************************/
#define IoHwAb_START_SEC_CONST_UNSPECIFIED
#include <IoHwAb_MemMap.h>

/**
* @brief Filters and their array index used for Analog signals
*/

const uint8 IoHwAb_AdcFilterIndex_SOC_BATT_MON[IOHWAB_MAX_FILTER_INDEX] =
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

const uint8 IoHwAb_AdcFilterIndex_SOC_TEMP_SENS1[IOHWAB_MAX_FILTER_INDEX] =
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
const uint8 IoHwAb_AdcFilterIndex_SOC_TEMP_SENS3[IOHWAB_MAX_FILTER_INDEX] =
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
const uint8 IoHwAb_AdcFilterIndex_IOEXP_AI_TFT_LED_TEMP[IOHWAB_MAX_FILTER_INDEX] =
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
const uint8 IoHwAb_AdcFilterIndex_IOEXP_AI_FALD_BL_TEMP[IOHWAB_MAX_FILTER_INDEX] =
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
const uint8 IoHwAb_AdcFilterIndex_IOEXP_AI_30V0_BL_PWR_UC[IOHWAB_MAX_FILTER_INDEX] =
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
const uint8 IoHwAb_AdcFilterIndex_IOEXP_AI_CABLE_DEATECT_TT[IOHWAB_MAX_FILTER_INDEX] =
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
const uint8 IoHwAb_AdcFilterIndex_IOEXP_AI_SBATT2_MON[IOHWAB_MAX_FILTER_INDEX] =
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
    {IoExp_AdcConf_AdcGroupId_AdcGroup_ANA_COM, 0, 5, IOHWAB_GROUP_NON_MUX},
    {PmicCdd_AdcConf_AdcGroupId_AdcGroup_ANA_COM, 5, 1, IOHWAB_GROUP_MUX},
    {PmicCdd_AdcConf_AdcGroupId_AdcGroup_ANA_COM, 6, 1, IOHWAB_GROUP_MUX},
    {PmicCdd_AdcConf_AdcGroupId_AdcGroup_ANA_COM, 7, 1, IOHWAB_GROUP_MUX},
  
};

/**
 * @brief Definition of configuration parameters for Analog inputs
 */
const IoHwAb_AdcCfgType IoHwAb_AdcCfg[IOHWAB_NUM_ADC_INPUT] = 
{
    {
      {
        {
          /* Variant 1 */
          0u, /* Ratioed Adc Multiplier*/
          IoExp_AdcConf_AdcGroupId_AdcGroup_ANA_COM,  
          IOEXP_AI_TFT_LED_TEMP,
          0u,
          0u,
          IOHWAB_SOURCE_ADC_EXTERNAL_IOEXP,
          #if (IOHWAB_ADC_MUX == STD_ON)
          FALSE, /* Is This Mux Channel? */
          0u, /* Mux Channel Id*/
          0u /* Mux Group Id*/
          #endif
        }
      },
      (uint8 *)&IoHwAb_AdcFilterIndex_IOEXP_AI_TFT_LED_TEMP[0],
      IOHWAB_NOFILTER_ADC, /* Adc filter type*/
      eIO_IOEXP_AI_TFT_LED_TEMP
    },
    {
      {
        {
          /* Variant 1 */
          0u, /* Ratioed Adc Multiplier*/
          IoExp_AdcConf_AdcGroupId_AdcGroup_ANA_COM,  
          IOEXP_AI_FALD_BL_TEMP,
          1u,
          0u,
          IOHWAB_SOURCE_ADC_EXTERNAL_IOEXP,
          #if (IOHWAB_ADC_MUX == STD_ON)
          FALSE, /* Is This Mux Channel? */
          0u, /* Mux Channel Id*/
          0u /* Mux Group Id*/
          #endif
        }
      },
      (uint8 *)&IoHwAb_AdcFilterIndex_IOEXP_AI_FALD_BL_TEMP[0],
      IOHWAB_NOFILTER_ADC, /* Adc filter type*/
      eIO_IOEXP_AI_FALD_BL_TEMP
    },
    {
      { 
        {
          /* Variant 1 */
          0u, /* Ratioed Adc Multiplier*/
          IoExp_AdcConf_AdcGroupId_AdcGroup_ANA_COM,  
          IOEXP_AI_30V0_BL_PWR_UC,
          2u,
          0u,
          IOHWAB_SOURCE_ADC_EXTERNAL_IOEXP,
          #if (IOHWAB_ADC_MUX == STD_ON)
          FALSE, /* Is This Mux Channel? */
          0u, /* Mux Channel Id*/
          0u /* Mux Group Id*/
          #endif
        }
      },
    (uint8 *)&IoHwAb_AdcFilterIndex_IOEXP_AI_30V0_BL_PWR_UC[0],
    IOHWAB_NOFILTER_ADC, /* Adc filter type*/
    eIO_IOEXP_AI_30V0_BL_PWR_UC
    },
    {
      {
        {
          /* Variant 1 */
          0u, /* Ratioed Adc Multiplier*/
          IoExp_AdcConf_AdcGroupId_AdcGroup_ANA_COM,  
          IOEXP_AI_CABLE_DEATECT_TT,
          3u,
          0u,
          IOHWAB_SOURCE_ADC_EXTERNAL_IOEXP,
          #if (IOHWAB_ADC_MUX == STD_ON)
          FALSE, /* Is This Mux Channel? */
          0u, /* Mux Channel Id*/
          0u /* Mux Group Id*/
          #endif
        }
      },
    (uint8 *)&IoHwAb_AdcFilterIndex_IOEXP_AI_CABLE_DEATECT_TT[0],
    IOHWAB_NOFILTER_ADC, /* Adc filter type*/
    eIO_IOEXP_AI_CABLE_DEATECT_TT
    },
    {
      {
        {
          /* Variant 1 */
          0u, /* Ratioed Adc Multiplier*/
          IoExp_AdcConf_AdcGroupId_AdcGroup_ANA_COM,  
          IOEXP_AI_SBATT2_MON,
          4u,
          0u,
          IOHWAB_SOURCE_ADC_EXTERNAL_IOEXP,
          #if (IOHWAB_ADC_MUX == STD_ON)
          FALSE, /* Is This Mux Channel? */
          0u, /* Mux Channel Id*/
          0u /* Mux Group Id*/
          #endif
        }
      },
    (uint8 *)&IoHwAb_AdcFilterIndex_IOEXP_AI_SBATT2_MON[0],
    IOHWAB_NOFILTER_ADC, /* Adc filter type*/
    eIO_IOEXP_AI_SBATT2_MON
    },
    {
      {
        {
          /* Variant 1 */
          0u, /* Ratioed Adc Multiplier*/
          PmicCdd_AdcConf_AdcGroupId_AdcGroup_ANA_COM, /* Single Channel Group ID*/
          PmicCdd_AdcConf_AdcGroupId_AdcGroup_ANA_COM, /* Multi Channel Group ID*/
          0u, /* Adc Index for Multi Channel*/
          0u, /* Ratioed Adc Ref Channel Index*/
          IOHWAB_SOURCE_ADC_EXTERNAL_PMIC,
          #if (IOHWAB_ADC_MUX == STD_ON)
          TRUE, /* Is This Mux Channel? */
          0u, /* Mux Channel Id*/
          0u /* Mux Group Id*/
          #endif
        }
      },
    (uint8 *)&IoHwAb_AdcFilterIndex_SOC_BATT_MON[0], /* Adc filter id*/
    IOHWAB_NOFILTER_ADC, /* Adc filter type*/
    eIO_SOC_BATT_MON /* Adc software signal id*/
    },
    {
      {
        {
          /* Variant 1 */
          0u, /* Ratioed Adc Multiplier*/
          PmicCdd_AdcConf_AdcGroupId_AdcGroup_ANA_COM, /* Single Channel Group ID*/
          PmicCdd_AdcConf_AdcGroupId_AdcGroup_ANA_COM, /* Multi Channel Group ID*/
          0u, /* Adc Index for Multi Channel*/
          0u, /* Ratioed Adc Ref Channel Index*/
          IOHWAB_SOURCE_ADC_EXTERNAL_PMIC,
          #if (IOHWAB_ADC_MUX == STD_ON)
          TRUE, /* Is This Mux Channel? */
          1u, /* Mux Channel Id*/
          0u /* Mux Group Id*/
          #endif
        }
      },
    (uint8 *)&IoHwAb_AdcFilterIndex_SOC_TEMP_SENS1[0], /* Adc filter id*/
    IOHWAB_NOFILTER_ADC, /* Adc filter type*/
    eIO_SOC_TEMP_SENS1 /* Adc software signal id*/
    },
    {
      {
        {
          /* Variant 1 */
          0u, /* Ratioed Adc Multiplier*/
          PmicCdd_AdcConf_AdcGroupId_AdcGroup_ANA_COM, /* Single Channel Group ID*/
          PmicCdd_AdcConf_AdcGroupId_AdcGroup_ANA_COM, /* Multi Channel Group ID*/
          0u, /* Adc Index for Multi Channel*/
          0u, /* Ratioed Adc Ref Channel Index*/
          IOHWAB_SOURCE_ADC_EXTERNAL_PMIC,
          #if (IOHWAB_ADC_MUX == STD_ON)
          TRUE, /* Is This Mux Channel? */
          2u, /* Mux Channel Id*/
          0u /* Mux Group Id*/
          #endif
        }
      },
    (uint8 *)&IoHwAb_AdcFilterIndex_SOC_TEMP_SENS3[0], /* Adc filter id*/
    IOHWAB_NOFILTER_ADC, /* Adc filter type*/
    eIO_SOC_TEMP_SENS3 /* Adc software signal id*/
    },
    
};

#if (IOHWAB_ADC_MUX == STD_ON)
const IoHwAb_AdcDioMuxGroupCfgType IoHwAb_AdcDioMuxGroup[IOHWAB_NUM_OF_MUX_GROUP] = {
{
    {
        {Main_GPIO1_Channel_13, 0u},
        {Main_GPIO1_Channel_12, 0u}
    },
    PmicCdd_AdcConf_AdcGroupId_AdcGroup_ANA_COM
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



Std_ReturnType IoHwAb_Adc_SetupResultBuffer(Adc_GroupType Group, uint16* DataResultBufferPtr)
{
    Std_ReturnType IoHwAb_Adc_SetBufferResult = E_NOT_OK;
    uint8 GroupIndex = 0U;
    uint8 AdcGroupIndex = 0U;
    uint8 VariantId = 0U;
    uint8 AdcVariantId = 0U;
    uint8 Found = 0U;

  for(GroupIndex = 0; GroupIndex < IOHWAB_NUM_ADC_INPUT; GroupIndex++)
  {
    for(VariantId = 0; VariantId < IOHWAB_ADC_NUM_OF_VARIANTS; VariantId++)
    {
      if((Group == IoHwAb_AdcCfg[GroupIndex].IoHwAb_AdcGroup[VariantId].MultiCh_Adc_GroupId) || (Group == IoHwAb_AdcCfg[GroupIndex].IoHwAb_AdcGroup[VariantId].SingleCh_Adc_GroupId))
      {
        AdcGroupIndex = GroupIndex;
        AdcVariantId = VariantId;
        Found = 1U;
        break;
      }
    }
    if(Found == 1U)
    {
      break;
    }
  }

  if(1U == Found) //Expression 'AdcGroupIndex < 8' used in the condition always yields the same result
  {
    if(IOHWAB_SOURCE_ADC_MCAL == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId)
    {
      //IoHwAb_Adc_SetBufferResult = Adc_SetupResultBuffer((Adc_GroupType)Group, DataResultBufferPtr);
    }
    else if(IOHWAB_SOURCE_ADC_EXTERNAL_PMIC == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId) 
    {
      #if (PMICCDD_ENABLE_ADC == STD_ON)
      IoHwAb_Adc_SetBufferResult = PmicCdd_IoHwAb_Adc_SetupResultBuffer((PmicCdd_Adc_GroupType)Group, DataResultBufferPtr);
      #endif
    }
    else if(IOHWAB_SOURCE_ADC_EXTERNAL_IOEXP == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId)
    {
      IoHwAb_Adc_SetBufferResult = IoExp_Adc_SetupResultBuffer((IoExp_ChannelType)Group, DataResultBufferPtr);
    }
    else
    {
      /* Do Nothing */
    }
  }
  return IoHwAb_Adc_SetBufferResult;
}


void IoHwAb_Adc_StartGroupConversion(Adc_GroupType Group)
{
  uint8 GroupIndex = 0U;
  uint8 AdcGroupIndex = 0U;
  uint8 VariantId = 0U;
  uint8 AdcVariantId = 0U;
  uint8 Found = 0U;

  for(GroupIndex = 0; GroupIndex < IOHWAB_NUM_ADC_INPUT; GroupIndex++)
  {
    for(VariantId = 0; VariantId < IOHWAB_ADC_NUM_OF_VARIANTS; VariantId++)
    {
      if((Group == IoHwAb_AdcCfg[GroupIndex].IoHwAb_AdcGroup[VariantId].MultiCh_Adc_GroupId) || (Group == IoHwAb_AdcCfg[GroupIndex].IoHwAb_AdcGroup[VariantId].SingleCh_Adc_GroupId))
      {
        AdcGroupIndex = GroupIndex;
        AdcVariantId = VariantId;
        Found = 1U;
        break;
      }
    }
    if(Found == 1U)
    {
      break;
    }
  }
  if(1U == Found) //Expression 'AdcGroupIndex < 8' used in the condition always yields the same result
  {
    if(IOHWAB_SOURCE_ADC_MCAL == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId)
    {
      //Adc_StartGroupConversion((Adc_GroupType)Group);

    }
    else if(IOHWAB_SOURCE_ADC_EXTERNAL_PMIC == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId) 
    {
      #if (PMICCDD_ENABLE_ADC == STD_ON)
      PmicCdd_IoHwAb_Adc_StartGroupConversion((PmicCdd_Adc_GroupType)Group);
      #endif
    }
    else if(IOHWAB_SOURCE_ADC_EXTERNAL_IOEXP == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId)
    {
      IoExp_Adc_StartGroupConversion((IoExp_ChannelType)Group);
    }
    else
    {
      /* Do Nothing */
    }
  }
}


void IoHwAb_Adc_StopGroupConversion(Adc_GroupType Group)
{
  uint8 GroupIndex = 0U;
  uint8 AdcGroupIndex = 0U;
  uint8 VariantId = 0U;
  uint8 AdcVariantId = 0U;
  uint8 Found = 0U;

  for(GroupIndex = 0; GroupIndex < IOHWAB_NUM_ADC_INPUT; GroupIndex++)
  {
    for(VariantId = 0; VariantId < IOHWAB_ADC_NUM_OF_VARIANTS; VariantId++)
    {
      if((Group == IoHwAb_AdcCfg[GroupIndex].IoHwAb_AdcGroup[VariantId].MultiCh_Adc_GroupId) || (Group == IoHwAb_AdcCfg[GroupIndex].IoHwAb_AdcGroup[VariantId].SingleCh_Adc_GroupId))
      {
        AdcGroupIndex = GroupIndex;
        AdcVariantId = VariantId;
        Found = 1U;
        break;
      }
    }
    if(Found == 1U)
    {
      break;
    }
  }
  if(1U == Found) //Expression 'AdcGroupIndex < 8' used in the condition always yields the same result
  {
    if(IOHWAB_SOURCE_ADC_MCAL == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId)
    {
      //Adc_StopGroupConversion((Adc_GroupType)Group);
    }
    else if(IOHWAB_SOURCE_ADC_EXTERNAL_PMIC == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId) 
    {
      #if (PMICCDD_ENABLE_ADC == STD_ON)
      PmicCdd_IoHwAb_Adc_StopGroupConversion((PmicCdd_Adc_GroupType)Group);
      #endif
    }
    else if(IOHWAB_SOURCE_ADC_EXTERNAL_IOEXP == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId)
    {
      IoExp_Adc_StopGroupConversion((IoExp_ChannelType)Group);
    }
    else
    {
      /* Do Nothing */
    }
  }
}

Std_ReturnType IoHwAb_Adc_ReadGroup(Adc_GroupType Group, uint16* DataResultBufferPtr)
{
  Std_ReturnType IoHwAb_Adc_SetBufferResult = E_NOT_OK;
  uint8 GroupIndex = 0u;
  uint8 AdcGroupIndex = 0u;
  uint8 VariantId = 0U;
  uint8 AdcVariantId = 0U;
  uint8 Found = 0U;

  for(GroupIndex = 0; GroupIndex < IOHWAB_NUM_ADC_INPUT; GroupIndex++)
  {
    for(VariantId = 0; VariantId < IOHWAB_ADC_NUM_OF_VARIANTS; VariantId++)
    {
      if((Group == IoHwAb_AdcCfg[GroupIndex].IoHwAb_AdcGroup[VariantId].MultiCh_Adc_GroupId) || (Group == IoHwAb_AdcCfg[GroupIndex].IoHwAb_AdcGroup[VariantId].SingleCh_Adc_GroupId))
      {
        AdcGroupIndex = GroupIndex;
        AdcVariantId = VariantId;
        Found = 1U;
        break;
      }
    }
    if(Found == 1U)
    {
      break;
    }
  }

  if(1U == Found) //Expression 'AdcGroupIndex < 8' used in the condition always yields the same result
  {
    if(IOHWAB_SOURCE_ADC_MCAL == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId)
    {
      //IoHwAb_Adc_SetBufferResult = Adc_ReadGroup((Adc_GroupType)Group, DataResultBufferPtr);
    }
    else if(IOHWAB_SOURCE_ADC_EXTERNAL_PMIC == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId) 
    {
      #if (PMICCDD_ENABLE_ADC == STD_ON)
      IoHwAb_Adc_SetBufferResult = PmicCdd_IoHwAb_Adc_ReadGroup((PmicCdd_Adc_GroupType)Group, DataResultBufferPtr);
      #endif
    }
    else if(IOHWAB_SOURCE_ADC_EXTERNAL_IOEXP == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId)
    {
      IoHwAb_Adc_SetBufferResult = IoExp_GetAdcGroupResult((uint8)Group, DataResultBufferPtr);
    }
    else
    {
      /* Do Nothing */
    }
  }
  return IoHwAb_Adc_SetBufferResult;
}

IoHwAb_Adc_StatusType IoHwAb_Adc_GetGroupStatus(Adc_GroupType Group)
{
  PmicCdd_Adc_StatusType IoHwAb_PmicCdd_Adc_ResultStatus = PMICCDD_ADC_IDLE;
  IoHwAb_Adc_StatusType  IoHwAb_Adc_ResultStatus = IOHWAB_ADC_IDLE;
  Std_ReturnType IoHwAb_IoExp_ResultStatus = E_NOT_OK;
  uint8 GroupIndex = 0U;
  uint8 AdcGroupIndex = 0U;
  uint8 VariantId = 0U;
  uint8 AdcVariantId = 0U;
  uint8 Found = 0U;

  for(GroupIndex = 0; GroupIndex < IOHWAB_NUM_ADC_INPUT; GroupIndex++)
  {
    for(VariantId = 0; VariantId < IOHWAB_ADC_NUM_OF_VARIANTS; VariantId++)
    {
      if((Group == IoHwAb_AdcCfg[GroupIndex].IoHwAb_AdcGroup[VariantId].MultiCh_Adc_GroupId) || (Group == IoHwAb_AdcCfg[GroupIndex].IoHwAb_AdcGroup[VariantId].SingleCh_Adc_GroupId))
      {
        AdcGroupIndex = GroupIndex;
        AdcVariantId = VariantId;
        Found = 1U;
        break;
      }
    }
    if(Found == 1U)
    {
      break;
    }
  }

  if(1U == Found) //Expression 'AdcGroupIndex < 8' used in the condition always yields the same result
  {
    if(IOHWAB_SOURCE_ADC_MCAL == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId)
      {
        /*IoHwAb_Adc_ResultStatus = Adc_GetGroupStatus((Adc_GroupType)Group);
        if(ADC_IDLE == IoHwAb_Adc_ResultStatus)
        {
          IoHwAb_Adc_ResultStatus = IOHWAB_ADC_IDLE;
        }
        else if (ADC_BUSY == IoHwAb_Adc_ResultStatus)
        {
          IoHwAb_Adc_ResultStatus = IOHWAB_ADC_BUSY;
        }
        else if  (ADC_COMPLETED == IoHwAb_Adc_ResultStatus)
        {
          IoHwAb_Adc_ResultStatus = IOHWAB_ADC_COMPLETED;
        }
        else
        {
          IoHwAb_Adc_ResultStatus = IOHWAB_ADC_STREAM_COMPLETED;
        }*/
      }
      else if(IOHWAB_SOURCE_ADC_EXTERNAL_PMIC == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId) 
      {
        #if (PMICCDD_ENABLE_ADC == STD_ON)
        IoHwAb_PmicCdd_Adc_ResultStatus = PmicCdd_IoHwAb_Adc_GetGroupStatus((PmicCdd_Adc_GroupType)Group);
        if(PMICCDD_ADC_IDLE == IoHwAb_PmicCdd_Adc_ResultStatus)
        {
          IoHwAb_Adc_ResultStatus = IOHWAB_ADC_IDLE;
        }
        else if (PMICCDD_ADC_BUSY == IoHwAb_PmicCdd_Adc_ResultStatus)
        {
          IoHwAb_Adc_ResultStatus = IOHWAB_ADC_BUSY;
        }
        else if  (PMICCDD_ADC_COMPLETED == IoHwAb_PmicCdd_Adc_ResultStatus)
        {
            IoHwAb_Adc_ResultStatus = IOHWAB_ADC_COMPLETED;
        }
        else
        {
            IoHwAb_Adc_ResultStatus = IOHWAB_ADC_STREAM_COMPLETED;
        }
        #endif
      }
      else if(IOHWAB_SOURCE_ADC_EXTERNAL_IOEXP == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId)
      {
        IoHwAb_IoExp_ResultStatus = IoExp_Adc_GetGroupStatus((IoExp_ChannelType)Group);
        if(E_OK == IoHwAb_IoExp_ResultStatus)
        {
            IoHwAb_Adc_ResultStatus = IOHWAB_ADC_STREAM_COMPLETED;
        }
      }
      else
      {
        /* Do Nothing */
      }
  }
    return IoHwAb_Adc_ResultStatus;
}

void IoHwAb_Adc_EnableHardwareTrigger(Adc_GroupType Group)
{
  uint8 GroupIndex = 0U;
  uint8 AdcGroupIndex = 0U;
  uint8 VariantId = 0U;
  uint8 AdcVariantId = 0U;
  uint8 Found = 0U;

  for(GroupIndex = 0; GroupIndex < IOHWAB_NUM_ADC_INPUT; GroupIndex++)
  {
    for(VariantId = 0; VariantId < IOHWAB_ADC_NUM_OF_VARIANTS; VariantId++)
    {
      if((Group == IoHwAb_AdcCfg[GroupIndex].IoHwAb_AdcGroup[VariantId].MultiCh_Adc_GroupId) || (Group == IoHwAb_AdcCfg[GroupIndex].IoHwAb_AdcGroup[VariantId].SingleCh_Adc_GroupId))
      {
        AdcGroupIndex = GroupIndex;
        AdcVariantId = VariantId;
        Found = 1U;
        break;
      }
    }
    if(Found == 1U)
    {
      break;
    }
  }

  if(1U == Found) //Expression 'AdcGroupIndex < 8' used in the condition always yields the same result
  {
    if(IOHWAB_SOURCE_ADC_MCAL == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId)
    {
      //Adc_EnableHardwareTrigger((Adc_GroupType)Group);
    }
    else if(IOHWAB_SOURCE_ADC_EXTERNAL_PMIC == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId) 
    {
      #if (PMICCDD_ENABLE_ADC == STD_ON)
      PmicCdd_IoHwAb_Adc_EnableHardwareTrigger((PmicCdd_Adc_GroupType)Group);
      #endif
    }
    else if(IOHWAB_SOURCE_ADC_EXTERNAL_IOEXP == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId)
    {
        IoExp_Adc_EnableHardwareTrigger((IoExp_ChannelType)Group);
    }
    else
    {
      /* Do Nothing */
    }
  }
}

void IoHwAb_Adc_DisableHardwareTrigger(Adc_GroupType Group)
{
  uint8 GroupIndex = 0U;
  uint8 AdcGroupIndex = 0U;
  uint8 VariantId = 0U;
  uint8 AdcVariantId = 0U;
  uint8 Found = 0U;

  for(GroupIndex = 0; GroupIndex < IOHWAB_NUM_ADC_INPUT; GroupIndex++)
  {
    for(VariantId = 0; VariantId < IOHWAB_ADC_NUM_OF_VARIANTS; VariantId++)
    {
      if((Group == IoHwAb_AdcCfg[GroupIndex].IoHwAb_AdcGroup[VariantId].MultiCh_Adc_GroupId) || (Group == IoHwAb_AdcCfg[GroupIndex].IoHwAb_AdcGroup[VariantId].SingleCh_Adc_GroupId))
      {
        AdcGroupIndex = GroupIndex;
        AdcVariantId = VariantId;
        Found = 1U;
        break;
      }
    }
    if(Found == 1U)
    {
      break;
    }
  }
  if(1U == Found) //Expression 'AdcGroupIndex < 8' used in the condition always yields the same result
  {
    if(IOHWAB_SOURCE_ADC_MCAL == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId)
    {
      //Adc_DisableHardwareTrigger((Adc_GroupType)Group);
    }
    else if(IOHWAB_SOURCE_ADC_EXTERNAL_PMIC == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId) 
    {
      #if (PMICCDD_ENABLE_ADC == STD_ON)
      PmicCdd_IoHwAb_Adc_DisableHardwareTrigger((PmicCdd_Adc_GroupType)Group);
      #endif
    }
    else if(IOHWAB_SOURCE_ADC_EXTERNAL_IOEXP == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId)
    {
        IoExp_Adc_DisableHardwareTrigger((IoExp_ChannelType)Group);
    }
    else
    {
      /* Do Nothing */
    }
  }
}

void IoHwAb_Adc_EnableGroupNotification(Adc_GroupType Group)
{
  uint8 GroupIndex = 0U;
  uint8 AdcGroupIndex = 0U;
  uint8 VariantId = 0U;
  uint8 AdcVariantId = 0U;
  uint8 Found = 0U;

  for(GroupIndex = 0; GroupIndex < IOHWAB_NUM_ADC_INPUT; GroupIndex++)
  {
    for(VariantId = 0; VariantId < IOHWAB_ADC_NUM_OF_VARIANTS; VariantId++)
    {
      if((Group == IoHwAb_AdcCfg[GroupIndex].IoHwAb_AdcGroup[VariantId].MultiCh_Adc_GroupId) || (Group == IoHwAb_AdcCfg[GroupIndex].IoHwAb_AdcGroup[VariantId].SingleCh_Adc_GroupId))
      {
        AdcGroupIndex = GroupIndex;
        AdcVariantId = VariantId;
        Found = 1U;
        break;
      }
    }
    if(Found == 1U)
    {
      break;
    }
  }
  if(1U == Found) // Expression 'AdcGroupIndex < 8' used in the condition always yields the same result
  {
    if(IOHWAB_SOURCE_ADC_MCAL == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId)
    {
      //Adc_EnableGroupNotification((Adc_GroupType)Group);
    }
    else if(IOHWAB_SOURCE_ADC_EXTERNAL_PMIC == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId) 
    {
      #if (PMICCDD_ENABLE_ADC == STD_ON)
      PmicCdd_IoHwAb_Adc_EnableGroupNotification((PmicCdd_Adc_GroupType)Group);
      #endif
    }
    else if(IOHWAB_SOURCE_ADC_EXTERNAL_IOEXP == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId)
    {
        IoExp_Adc_EnableGroupNotification((IoExp_ChannelType)Group);
    }
    else
    {
      /* Do Nothing */
    }
  }
}

void IoHwAb_Adc_DisableGroupNotification(Adc_GroupType Group)
{
  uint8 GroupIndex = 0U;
  uint8 AdcGroupIndex = 0U;
  uint8 VariantId = 0U;
  uint8 AdcVariantId = 0U;
  uint8 Found = 0U;

  for(GroupIndex = 0; GroupIndex < IOHWAB_NUM_ADC_INPUT; GroupIndex++)
  {
    for(VariantId = 0; VariantId < IOHWAB_ADC_NUM_OF_VARIANTS; VariantId++)
    {
      if((Group == IoHwAb_AdcCfg[GroupIndex].IoHwAb_AdcGroup[VariantId].MultiCh_Adc_GroupId) || (Group == IoHwAb_AdcCfg[GroupIndex].IoHwAb_AdcGroup[VariantId].SingleCh_Adc_GroupId))
      {
        AdcGroupIndex = GroupIndex;
        AdcVariantId = VariantId;
        Found = 1U;
        break;
      }
    }

    if(Found == 1U)
    {
      break;
    }
  }
  if(1U == Found) //Expression 'AdcGroupIndex < 8' used in the condition always yields the same result
  {
    if(IOHWAB_SOURCE_ADC_MCAL == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId)
    {
      //Adc_DisableGroupNotification((Adc_GroupType)Group);
    }
    else if(IOHWAB_SOURCE_ADC_EXTERNAL_PMIC == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId) 
    {
      #if (PMICCDD_ENABLE_ADC == STD_ON)
      PmicCdd_IoHwAb_Adc_DisableGroupNotification((PmicCdd_Adc_GroupType)Group);
      #endif
    }
    else if(IOHWAB_SOURCE_ADC_EXTERNAL_IOEXP == IoHwAb_AdcCfg[AdcGroupIndex].IoHwAb_AdcGroup[AdcVariantId].SourceSignalId)
    {
        IoExp_Adc_DisableGroupNotification((IoExp_ChannelType)Group);
    }
    else
    {
      /* Do Nothing */
    }
  }
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
