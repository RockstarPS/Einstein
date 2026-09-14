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
* @file IoHwAb_Adc_Cfg.h
* @brief Configuration header file for adc inputs
* ****************************************************************************/
#ifndef IOHWAB_ADC_CFG_H
#define IOHWAB_ADC_CFG_H

/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/
#include "Rte_Type.h"

#define IOHWAB_ADC_MUX                      (STD_OFF)

#include "Adc.h"
#if (IOHWAB_ADC_MUX == STD_ON)
#include "Dio.h"
#endif


/*****************************************************************************
*  Public Macros Definitions                                                *                                                                                       *
******************************************************************************/
#define IOHWAB_ADC_ENABLE			            STD_ON
#define IOHWAB_ADC_TIMEOUT_ENABLE               STD_OFF
#define IOHWAB_ADC_HW_TRIGGER_ENABLE            STD_OFF
/*****************************************************************************
*  Private Macros Definitions                                                *                                                                                       *
******************************************************************************/
#if (IOHWAB_ADC_ENABLE == STD_ON)
/**
* @brief Number of analog input variants
*/
#define IOHWAB_ADC_NUM_OF_VARIANTS				1U
/**
* @brief Max Number of analog input variants
*/
#define IOHWAB_ADC_UNKNOWN_VARIANT  	1u
/**
* @brief Number of adc inputs configured
*/
#if (IOHWAB_ADC_MUX == STD_ON)

#define IOHWAB_NUM_ADC_INPUT                 13U
#define IOHWAB_NUM_OF_MUX_INPUT              8U
#define IOHWAB_NUM_OF_MUX_GROUP              1U


  #if (IOHWAB_NUM_OF_MUX_INPUT <= 1U)
    #define IOHWAB_NUM_OF_MUX_CHANNEL_SELECT     0U

  #elif ((IOHWAB_NUM_OF_MUX_INPUT > 1U) && (IOHWAB_NUM_OF_MUX_INPUT <= 2U))
    #define IOHWAB_NUM_OF_MUX_CHANNEL_SELECT    1U

  #elif ((IOHWAB_NUM_OF_MUX_INPUT > 2U) && (IOHWAB_NUM_OF_MUX_INPUT <= 4U))
    #define IOHWAB_NUM_OF_MUX_CHANNEL_SELECT     2U

  #elif ((IOHWAB_NUM_OF_MUX_INPUT > 4U) && (IOHWAB_NUM_OF_MUX_INPUT <= 8U))
    #define IOHWAB_NUM_OF_MUX_CHANNEL_SELECT     3U

  #elif ((IOHWAB_NUM_OF_MUX_INPUT > 8U) && (IOHWAB_NUM_OF_MUX_INPUT <= 16U))
    #define IOHWAB_NUM_OF_MUX_CHANNEL_SELECT     4U

  #elif ((IOHWAB_NUM_OF_MUX_INPUT > 16U) && (IOHWAB_NUM_OF_MUX_INPUT <= 32U))
    #define IOHWAB_NUM_OF_MUX_CHANNEL_SELECT     5U

  #elif ((IOHWAB_NUM_OF_MUX_INPUT > 32U) && (IOHWAB_NUM_OF_MUX_INPUT <= 64U))
    #define IOHWAB_NUM_OF_MUX_CHANNEL_SELECT     6U

  #elif ((IOHWAB_NUM_OF_MUX_INPUT > 64U) && (IOHWAB_NUM_OF_MUX_INPUT <= 128U))
    #define IOHWAB_NUM_OF_MUX_CHANNEL_SELECT     7U

  #elif ((IOHWAB_NUM_OF_MUX_INPUT > 128U) && (IOHWAB_NUM_OF_MUX_INPUT <= 256U))
    #define IOHWAB_NUM_OF_MUX_CHANNEL_SELECT     8U
  #endif

#else

#define IOHWAB_NUM_ADC_INPUT               13U
#endif

/**
* @brief Number of adc Groups configured
*/
#define IOHWAB_NUM_ADC_GROUP               13U

/**
* @brief Macro to indicate when no filtering/processing used
*/
#define IOHWAB_NOFILTER_ADC 					0U
/**
* @brief Macro to indicate when Ratioed calculation is used
*/
#define IOHWAB_RATIOED_ADC 						1U
/**
* @brief Macro to indicate when encoding is used for adc
*/
#define	IOHWAB_ENCODED_ADC 						2U
/**
* @brief Macro to indicate when resolution calculation is used
*/
#define IOHWAB_RESOLUTION_ADC 					4U
/**
* @brief Macro to indicate when debouncing is used
*/
#define IOHWAB_DEBOUNCE_ADC 					8U
/**
* @brief Macro to indicate when pt1 is used
*/
#define IOHWAB_PT1_ADC                          16U

#define IOHWAB_MOVING_AVERAGE_ADC               32U

#define IOHWAB_AVERAGE_ADC                      64U


/**
* @brief Filter index of encoded adc
*/
#define	IOHWAB_ENCODED_ADC_INDEX 				        1U
/**
* @brief Filter index of resolution adc
*/
#define IOHWAB_RESOLUTION_ADC_INDEX 			      2U
/**
* @brief Filter index of debounce adc
*/
#define IOHWAB_DEBOUNCE_ADC_INDEX				        3U
/**
* @brief Filter index of pt1 adc
*/
#define IOHWAB_PT1_ADC_INDEX                    4U
/**
* @brief Filter index of moving average adc
*/
#define IOHWAB_MOVINGAVG_ADC_INDEX              5U
/**
* @brief Filter index of average adc
*/
#define IOHWAB_AVG_ADC_INDEX                    6U
/**
* @brief Filter index of average adc
*/
#define IOHWAB_RATIOED_ADC_INDEX                7U
/**
* @brief Maximum number of filters
*/
#define IOHWAB_MAX_FILTER_INDEX        			    8U
/**
* @brief Maximum synchrounous adc reading timeout
*/
#define IOHWAB_ADC_MAX_SYNC_COUNT     0x100U

#if (IOHWAB_ADC_TIMEOUT_ENABLE == STD_ON)
/**
* @brief Maximum asynchrounous adc reading timeout
*/
#define IOHWAB_ADC_MAX_ASYNC_COUNT				12U   
#endif

#define IOHWAB_ADC_MAX_VALUE                    4096U

/**
* @brief Filter type for Adc input 0
*/
#define IOHWAB_ADC0_FILTER              IOHWAB_RESOLUTION_ADC

/**
* @brief Filter type for Adc input 1
*/
#define IOHWAB_ADC1_FILTER              IOHWAB_RESOLUTION_ADC | IOHWAB_MOVING_AVERAGE_ADC



/**
* @brief Filter type for Adc input 3
*/
#define IOHWAB_ADC3_FILTER              IOHWAB_RATIOED_ADC | IOHWAB_RESOLUTION_ADC

#define IOHWAB_ADC4_FILTER              IOHWAB_ENCODED_ADC | IOHWAB_DEBOUNCE_ADC

/*****************************************************************************
*  Type Declarations                                              			 *
******************************************************************************/
 
/**
* @brief This structure defines the configuration parameters for adc group
*/
typedef struct
{
    uint32					RatioMultiplier;			/**<Ratioed AD Multiplier*/
    Adc_GroupType  			Adc_GroupId;				/**<Single Channel Group ID*/
    Adc_ChannelType   		Adc_ChannelId;				/**<Adc Index for Multi Channel*/
    uint8					RatioRefChannelId;          /**<Ratioed Adc Ref Channel Index*/
#if (IOHWAB_ADC_MUX == STD_ON)
    uint8  MuxChannel;    /**< mux channel Supported */
    uint8  MuxChannelId;                                       /**< mux channel id */
    uint8  MuxGroupId;    /**< mux Group Id  */
#endif
} IoHwAb_AdcGroupType;
/**
* @brief This structure defines the configuration parameters for Adc module
*/
typedef struct
{
    IoHwAb_AdcGroupType 	IoHwAb_AdcGroup[IOHWAB_ADC_NUM_OF_VARIANTS];		/**< Adc configuration parameters*/
    uint8 *FilterId;											/**< Adc filter id*/
    uint8 FilterType;											/**< Adc filter type*/
    IoHwAb_AdcSignalIdType  SignalId;											/**< Adc input signal id*/
} IoHwAb_AdcCfgType;

#if (IOHWAB_ADC_MUX == STD_ON)
typedef struct
{
  Dio_ChannelType     Hw_ChannelId;   /**< Mcal dio channel id*/
  Dio_LevelType       InitValue;
}IoHwAb_AdcDioMuxCfgType;
typedef struct
{
  IoHwAb_AdcDioMuxCfgType IoHwAb_AdcDioMux[IOHWAB_NUM_OF_MUX_CHANNEL_SELECT];
  Adc_GroupType       Adc_GroupId;
}IoHwAb_AdcDioMuxGroupCfgType;
#endif

typedef struct
{
  Adc_GroupType AdcGroupId;
  uint8 Offset;
  uint8 Count;
}IoHwAb_AdcNumOfGroupType;


/*****************************************************************************
*  Public Forward Declarations                                          	 *
******************************************************************************/
#if (IOHWAB_NUM_ADC_INPUT != 0u)
  extern const IoHwAb_AdcCfgType IoHwAb_AdcCfg[IOHWAB_NUM_ADC_INPUT];
#else
  #error Macro IOHWAB_NUM_ADC_INPUT - Should not be a value of 0
#endif


#if (IOHWAB_NUM_ADC_GROUP != 0u)
  extern const IoHwAb_AdcNumOfGroupType IoHwAb_AdcNumOfGroup[IOHWAB_NUM_ADC_GROUP];
#else
  #error Macro IOHWAB_NUM_ADC_GROUP - Should not be a value of 0
#endif


#if (IOHWAB_ADC_MUX == STD_ON)
extern const IoHwAb_AdcDioMuxGroupCfgType IoHwAb_AdcDioMuxGroup[IOHWAB_NUM_OF_MUX_GROUP];
#endif

/*****************************************************************************
*  Private Forward Declarations                                          	 *
******************************************************************************/

Std_ReturnType IoHwAb_Adc_GetCurrentVariant(uint8* AdcVariantId);
Std_ReturnType IoHwAb_Adc_PreHook(void);



#endif
#endif /* IOHWAB_ADC_CFG_H */

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
/*------------------------------------------------------------------------------------------------------------------------
Date              : 22/Feb/2019
By                : asivalin
Traceability      : RTC #438805
Change Description: Moving "SBATTMON_ANG_MCU_IN" signal from Non-safe to Safe IoHwAb
---------------------------------------------------------------------------------------------------------------------------*/
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
Date              :13-Mar-2020
By                :MSAVARIY
Traceability      : 808643: [Honda BEV] IoHwAb configuration
Change Description: MUX ADC support added
******************************************************************************/


