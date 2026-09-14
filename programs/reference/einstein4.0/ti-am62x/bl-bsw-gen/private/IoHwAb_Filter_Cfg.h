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
* @file IoHwAb_Filter_Cfg.h
* @brief Configuration types for Filters
* ****************************************************************************/
#ifndef IOHWAB_FILTER_CFG_H
#define IOHWAB_FILTER_CFG_H

/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/
#include  "Std_Types.h"

/*****************************************************************************
*  Public Macros Definitions                                                *                                                                                       *
******************************************************************************/
/**
* @brief Macro to enable the IoHwAb filter Module
*/
#define IOHWAB_FILTER_ENABLE		STD_ON
/*****************************************************************************
*  Private Macros Definitions                                                *                                                                                       *
******************************************************************************/
#if (IOHWAB_FILTER_ENABLE == STD_ON)
/**
* @brief Number of digital debounce group
*/
#define  IOHWAB_NUM_OF_DIGITAL_DEBOUNCE_GROUP           1U
/**
* @brief Number of Maximum digital debounce channels per group. Equal to the number of bits in uint32
*/
#define  IOHWAB_NUM_OF_MAX_DIGDEBCHANNELS_PERGROUP		32U
/**
* @brief Number of resolution calculation channels
*/
#define  IOHWAB_NUM_OF_RES_CALC							2U
/**
* @brief Number of encoded calculation channels
*/
#define  IOHWAB_NUM_OF_ENCODED							0U
/**
* @brief Number of maximum range of Encoded values
*/
#define  IOHWAB_NUM_OF_MAX_ENCODED_RANGE				10U
/**
* @brief Number of normal debounce channels
*/
#define  IOHWAB_NUM_OF_DEBOUNCE							0U

/*Define the movingAvg and Avg32 filter datatypes*/
#define  IOHWAB_NUM_OF_MOVINGAVGFILTER                  0U
#define  IOHWAB_NUM_OF_AVGFILTER                        0U
#define  IOHWAB_NUM_OF_PT1FILTER                        0

/*Define the number of data for the avg filter */
#define  IOHWAB_NUM_OF_AVGFILTER_DATAS                  5U


/*****************************************************************************
*  Type Declarations                                                         *
******************************************************************************/
#if (IOHWAB_NUM_OF_DIGITAL_DEBOUNCE_GROUP > 0U)
/**
* @brief Digital debounce On debounce counts
*/
typedef struct
{
	uint32 b0_counter_On_restart;		/**< On Count bit 0 */
	uint32 b1_counter_On_restart;		/**< On Count bit 1 */
	uint32 b2_counter_On_restart;		/**< On Count bit 2 */
	uint32 b3_counter_On_restart;		/**< On Count bit 3 */
	uint32 b4_counter_On_restart;		/**< On Count bit 4 */
	uint32 b5_counter_On_restart;		/**< On Count bit 5 */
	uint32 b6_counter_On_restart;		/**< On Count bit 6 */
	uint32 b7_counter_On_restart;		/**< On Count bit 7 */
}IoHwAb_DigitalDebounceOnCountType;

/**
* @brief Digital debounce Off debounce counts
*/
typedef struct
{
	uint32 b0_counter_Off_restart;		/**< Off Count bit 0 */
	uint32 b1_counter_Off_restart;		/**< Off Count bit 1 */
	uint32 b2_counter_Off_restart;		/**< Off Count bit 2 */
	uint32 b3_counter_Off_restart;		/**< Off Count bit 3 */
	uint32 b4_counter_Off_restart;		/**< Off Count bit 4 */
	uint32 b5_counter_Off_restart;		/**< Off Count bit 5 */
	uint32 b6_counter_Off_restart;		/**< Off Count bit 6 */
	uint32 b7_counter_Off_restart;		/**< Off Count bit 7 */
}IoHwAb_DigitalDebounceOffCountType;

/**
* @brief Digital debounce refresh counts to store the ON/OFF counts when input states are changing
*/
typedef struct
{
	uint32 b0_counter_Refresh;			/**< Refresh Count bit 0 */
	uint32 b1_counter_Refresh;			/**< Refresh Count bit 1 */
	uint32 b2_counter_Refresh;			/**< Refresh Count bit 2 */
	uint32 b3_counter_Refresh;			/**< Refresh Count bit 3 */
	uint32 b4_counter_Refresh;			/**< Refresh Count bit 4 */
	uint32 b5_counter_Refresh;			/**< Refresh Count bit 5 */
	uint32 b6_counter_Refresh;			/**< Refresh Count bit 6 */
	uint32 b7_counter_Refresh;			/**< Refresh Count bit 7 */
}IoHwAb_DigitalDebounceRefreshCountType;
#endif

#if (IOHWAB_NUM_OF_RES_CALC > 0U)
/**
* @brief Configuration parameters for Resolution calculation
*/
typedef struct
{
	sint32 	Offset;						/**< Offset for resolution calculation*/
	uint32 	ResolutionMultiplier;		/**< Multiplier for resolution calculation*/
	uint32 	ResolutionDivisor;			/**< Divisor for resolution calculation*/
	uint8	ResolutionId;				/**< Resolution channel Id*/
}IoHwAb_ResoultionCalcType;
#endif

#if (IOHWAB_NUM_OF_ENCODED > 0U)
/**
* @brief Configuration parameters for Encoding calculation range
*/
typedef struct
{
	uint32 	EncodedMin;					/**< Encoder Min value*/
	uint32 	EncodedMax;					/**< Encoder Max value*/
}IoHwAb_EncodedRangeType;

/**
* @brief Configuration parameters for Encoder
*/
typedef struct
{
	IoHwAb_EncodedRangeType 	EncodedRange[IOHWAB_NUM_OF_MAX_ENCODED_RANGE];		/**< Encoder Range*/
	uint8						EncodedId;											/**< Encoder channel Id*/
	uint8   					RangeCount;											/**< encoder range count*/
}IoHwAb_EncodedType;
#endif

#if (IOHWAB_NUM_OF_DEBOUNCE > 0U)
/**
* @brief Configuration parameters for normal debounce calculation
*/
typedef struct
{
	uint32 DebounceValue; 	/**< Debounced value */
	uint32 NewValue;	  	/**< New received value */
	uint32 PreviousValue; 	/**< Previous received value */
	uint16 Count;		  	/**< Consecutive count of last values different from FilteredValue */
	uint8  DebounceState;	/**< Debounce completion status */
} IoHwAb_DebounceType;

/**
* @brief Configuration parameter for Normal debounce
*/
typedef struct
{
    uint8 DebounceCount; 	/**< Number of identical consecutive values needed to output this value to filtered value */
    uint8 InitValue;		/**< Init value */
} IoHwAb_DebounceCfgType;
#endif

#if (IOHWAB_NUM_OF_MOVINGAVGFILTER > 0U)
/// Moving Average filter configuration
typedef struct
{
	uint8 Count; ///< Number of elements in average
} IoHwAb_Filter_MovingAvgFilter_CfgType;
#endif

#if (IOHWAB_NUM_OF_AVGFILTER > 0U)
/// Average filter configuration for uint32
typedef struct
{
    /// @brief Length of the filtered array.
    uint8 Count; ///< Number of elements in average
} IoHwAb_Filter_AvgFilter_CfgType;
#endif

#if (IOHWAB_NUM_OF_PT1FILTER > 0U)
/// PT1 filter configuration
typedef struct
{
  uint16 InitValue; ///< Init value
  uint16 DampingConstant; ///< Damping Value
} IoHwAb_Filter_PT1Filter_CfgType;
#endif

/*****************************************************************************
*  Public Forward Declarations                                          	 *
******************************************************************************/
extern const IoHwAb_DigitalDebounceOnCountType IoHwAb_DigitalDebounceOnCount[IOHWAB_NUM_OF_DIGITAL_DEBOUNCE_GROUP];
extern const IoHwAb_DigitalDebounceOffCountType IoHwAb_DigitalDebounceOffCount[IOHWAB_NUM_OF_DIGITAL_DEBOUNCE_GROUP];

#if (IOHWAB_NUM_OF_RES_CALC > 0U)
extern const IoHwAb_ResoultionCalcType IoHwAb_ResoultionCalcCfg[IOHWAB_NUM_OF_RES_CALC];
#endif

#if (IOHWAB_NUM_OF_MOVINGAVGFILTER > 0U)
extern const IoHwAb_Filter_MovingAvgFilter_CfgType IoHwAb_Filter_MovingAvgFilter_Cfg[IOHWAB_NUM_OF_MOVINGAVGFILTER];
#endif
#if (IOHWAB_NUM_OF_AVGFILTER > 0U)
extern const IoHwAb_Filter_AvgFilter_CfgType IoHwAb_Filter_AvgFilter_Cfg[IOHWAB_NUM_OF_AVGFILTER];
#endif
#if (IOHWAB_NUM_OF_PT1FILTER > 0U)
extern const IoHwAb_Filter_PT1Filter_CfgType IoHwAb_Filter_PT1Filter_Cfg[IOHWAB_NUM_OF_PT1FILTER];
#endif
#if (IOHWAB_NUM_OF_ENCODED > 0U)
extern const IoHwAb_EncodedType IoHwAb_EncodedCfg[IOHWAB_NUM_OF_ENCODED];
#endif
#if (IOHWAB_NUM_OF_DEBOUNCE > 0U)
extern const IoHwAb_DebounceCfgType IoHwAb_DebounceCfg[IOHWAB_NUM_OF_DEBOUNCE];
extern const IoHwAb_DebounceType IoHwAb_DebounceInit[IOHWAB_NUM_OF_DEBOUNCE];
#endif
#endif
#endif /*IOHWAB_FILTER_CFG_H*/

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
Date              :5-Dec-2018
By                :nrajaman
Traceability      :1206553: Hyundai SP2: PIC component upgrade for ASIL compliance.
Change Description:Updated for IoHwAb_PulseInput safe implementation
******************************************************************************/
/*****************************************************************************
Date              :22-Mar-2019
By                :asivalin
Traceability      :RTC-1302411: Hyundai SP2: [Hyundai_SP2 Color] Battery charge TT HW pin
				   (with OFF condition) throws ERROR status upon battery connect in Normal mode (461677)
Change Description:Removed IoHwAb_DigitalDebounceInitValue from configuration
******************************************************************************/


