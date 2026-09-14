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
* @file IoHwAb_Filter_Cfg.c
* @brief Configuration definition for filters
* ****************************************************************************/
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/
#include "IoHwAb_Filter_Cfg.h"
#include "Rte_IoHwAb.h"

#if (IOHWAB_FILTER_ENABLE == STD_ON)
/*****************************************************************************
*  Configuration Definitions                                                 *                                                                                       *
******************************************************************************/
#define IoHwAb_START_SEC_CONST_UNSPECIFIED
#include <IoHwAb_MemMap.h>
/**
* @brief Definition of configuration parameters for Digital input ON debounce count
*/
const IoHwAb_DigitalDebounceOnCountType IoHwAb_DigitalDebounceOnCount[IOHWAB_NUM_OF_DIGITAL_DEBOUNCE_GROUP] =
{
    {
        15uL,
        15uL,
        15uL,
        15uL,
        15uL,
        15uL,
        15uL,
        15uL
    }
};

/**
* @brief Definition of configuration parameters for Digital input OFF debounce count
*/

const IoHwAb_DigitalDebounceOffCountType IoHwAb_DigitalDebounceOffCount[IOHWAB_NUM_OF_DIGITAL_DEBOUNCE_GROUP] =
{
    {
        15uL,
        15uL,
        15uL,
        15uL,
        15uL,
        15uL,
        15uL,
        15uL
    }
};
#if (IOHWAB_NUM_OF_RES_CALC > 0U)
const IoHwAb_ResoultionCalcType IoHwAb_ResoultionCalcCfg[IOHWAB_NUM_OF_RES_CALC]  =
{
	/*  */
    {
		0uL,
        32768uL,
        10000uL,
        0
	},
	/* */
    {
		0uL,
		1000uL, 
		10000uL,
		1
	}
};
#endif

/*Define the moving avg and the avg filter constant*/
#if (IOHWAB_NUM_OF_MOVINGAVGFILTER > 0U)
const IoHwAb_Filter_MovingAvgFilter_CfgType IoHwAb_Filter_MovingAvgFilter_Cfg[IOHWAB_NUM_OF_MOVINGAVGFILTER] =
                                                                                                                {
                                                                                                                    5u
                                                                                                                };
#endif
#if (IOHWAB_NUM_OF_AVGFILTER > 0U)
const IoHwAb_Filter_AvgFilter_CfgType IoHwAb_Filter_AvgFilter_Cfg[IOHWAB_NUM_OF_AVGFILTER] =
                                                                                                                {
                                                                                                                    5u
                                                                                                                };
#endif

#if (IOHWAB_NUM_OF_PT1FILTER > 0U)
const IoHwAb_Filter_PT1Filter_CfgType IoHwAb_Filter_PT1Filter_Cfg[IOHWAB_NUM_OF_PT1FILTER] =
{
    {
      0uL,
      7uL
    },
	{
      0uL,
      5uL
    }
};
#endif
#if (IOHWAB_NUM_OF_ENCODED > 0U)
const IoHwAb_EncodedType IoHwAb_EncodedCfg[IOHWAB_NUM_OF_ENCODED] = 
{
	{
		{
			{
				2805,
				4095,
			},
			{
				2404,
				2642,
			},
      {
        1093,
        1339,
      },
      {
        0,
        16,
      }
		},
		eIOVoltageInId_HLL_CONTROL_SW,
		4,
	},
  {
    {
      {
        2805,
        4095,
      },
      {
        640,
        2404,
      },
      {
        31,
        119,
      },
      {
        244,
        918,
      },
      {
        4,
        16,
      }
    },
    eIOVoltageInId_LKAS_OR_DISTANCE_SW,
    5,
  },
  {
    {
      {
        2805,
        4095,
      },
      {
        2404,
        2642,
      },
      {
        119,
        237,
      },
      {
        415,
        586,
      },
      {
        918,
        1151,
      },
      {
        1509,
        1774,
      },
      {
        0,
        15,
      }
    },
    eIOVoltageInId_CRUISE_SW,
    7,
  },
  {
    {
      {
        2805,
        4095,
      },
      {
        2404,
        2642,
      },
      {
        1093,
        1339,
      },
      {
        0,
        15,
      }
    },
    eIOVoltageInId_BRAKE_HOLD_SW,
    5,
  }
};
#endif
#if (IOHWAB_NUM_OF_DEBOUNCE > 0U)
const IoHwAb_DebounceCfgType IoHwAb_DebounceCfg[IOHWAB_NUM_OF_DEBOUNCE] =
{
    {
	    5,
		0
	}
};
const IoHwAb_DebounceType IoHwAb_DebounceInit[IOHWAB_NUM_OF_DEBOUNCE] =
{
    {
	    0,
		0,
		0,
		0,
		0
	}
};
#endif
#define IoHwAb_STOP_SEC_CONST_UNSPECIFIED
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
Date              :26-Dec-2018
By                :asivalin
Traceability      :1260028: Integrate the latest PIC Integrated IoHwAb base in SP2 & Release.
Change Description:PIC Configuration Update as per Hyundai SP2
******************************************************************************/
/*------------------------------------------------------------------------------------------------------------------------
Date              : 22/Feb/2019
By                : asivalin
Traceability      : RTC #438805
Change Description: Moving "SBATTMON_ANG_MCU_IN" signal from Non-safe to Safe IoHwAb and corresponding Filter Cfg Update
---------------------------------------------------------------------------------------------------------------------------*/
/*****************************************************************************
Date              :22-Mar-2019
By                :asivalin
Traceability      :RTC-1302411: Hyundai SP2: [Hyundai_SP2 Color] Battery charge TT HW pin
				   (with OFF condition) throws ERROR status upon battery connect in Normal mode (461677)
Change Description:Removed IoHwAb_DigitalDebounceInitValue from configuration
******************************************************************************/
/*****************************************************************************
Date              :14-May-2019
By                :msavariy
Traceability      :1323692: Bookshelf Safe component PT1 Filter Implementation
Change Description: Added support for PT1 Filtering for Analog Inputs
******************************************************************************/
