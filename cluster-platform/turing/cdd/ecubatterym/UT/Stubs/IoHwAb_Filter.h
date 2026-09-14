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
* @file IoHwAb_Filter.h
* @brief Header for Filtering or processing the IoHwAb signals
* ****************************************************************************/
#ifndef IOHWAB_FILTER_H
#define IOHWAB_FILTER_H
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/
#include "IoHwAb_Filter_Cfg.h"
 /*To check if Filter is enabled */
#if (IOHWAB_FILTER_ENABLE == STD_ON)
//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
/* MISRA C-2012 Rule 2.3 JUSTIFICATION: Type EFilterMethod is defined as per design. It is used for future purpose.*/
typedef enum
{
    eFilter_MovingAvg = 0u,
    eFilter_Avg = 1u,
    eFilter_Max = 2u
}EFilterMethod;
/*****************************************************************************
*  Public Forward Declarations                                              *
******************************************************************************/
extern void IoHwAb_Filter_Init(void);
extern void IoHwAb_Filter_DeInit(void);
extern void IoHwAb_Filter_MainFunction(void);

#if (IOHWAB_NUM_OF_DIGITAL_DEBOUNCE_GROUP > 0U)
extern Std_ReturnType IoHwAb_Filter_GetDigitalDebounceValue(uint8 DebGroupId, uint8 DebChannelId, boolean *DebounceValue);
extern Std_ReturnType IoHwAb_Filter_SetDigitalDebounce(uint8 DebGroupId, uint8 DebChannelId, boolean RawValue);
#endif

#if (IOHWAB_NUM_OF_RES_CALC > 0U)
extern Std_ReturnType IoHwAb_Filter_ResolutionCalc(uint8 ResolutionCalcId, uint32 RawValue, sint32* CalcValue);
#endif

#if (IOHWAB_NUM_OF_DEBOUNCE > 0U)
extern Std_ReturnType IoHwAb_Filter_SetDebounce(uint8 DebounceId, uint32 RawValue);
extern Std_ReturnType IoHwAb_Filter_GetDebounceValue(uint8 DebounceId, uint32 *DebounceValue);
#endif

#if (IOHWAB_NUM_OF_ENCODED > 0U)
extern Std_ReturnType IoHwAb_Filter_Encoded(uint8 EncodeId, uint32 RawValue, uint32* EncodedValue);
#endif


#if (IOHWAB_NUM_OF_AVGFILTER > 0U)
extern Std_ReturnType IoHwAb_Filter_AvgFilter(const uint8 FilterCfgIx, const uint32 NewValue, uint32 * const pFilteredValue);
#endif

#if (IOHWAB_NUM_OF_MOVINGAVGFILTER > 0U)
extern Std_ReturnType IoHwAb_Filter_MovingAvgFilter(const uint8 FilterCfgIx, const uint32 NewValue, uint32 * const pFilteredValue);
#endif

#if ((IOHWAB_NUM_OF_MOVINGAVGFILTER > 0U) || (IOHWAB_NUM_OF_AVGFILTER > 0U))
/*This function is used to reset the filter data to zero.*/
extern Std_ReturnType IoHwAb_Filter_ResetFilter(EFilterMethod FilterName , uint8 FilterIndexId);
#endif

#if (IOHWAB_NUM_OF_PT1FILTER > 0U)
extern Std_ReturnType IoHwAb_Filter_PT1Filter(const uint8 Pt1Index, const uint32 NewValue, uint32 * const pFilteredValue);
#endif
#endif
#endif /* IOHWAB_FILTER_H*/


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
Date              :14-May-2019
By                :msavariy
Traceability      :1323692: Bookshelf Safe component PT1 Filter Implementation
Change Description: Added support for PT1 Filtering for Analog Inputs
******************************************************************************/

