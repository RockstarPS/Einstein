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
* @file IoHwAb_Adc.h
* @brief Types for IoHwAb analog input signals
* ****************************************************************************/
#ifndef IOHWAB_ADC_H
#define IOHWAB_ADC_H
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/
#include "IoHwAb_Adc_Cfg.h"
 /*To check if Analog Input is enabled */
#if (IOHWAB_ADC_ENABLE == STD_ON)
/*****************************************************************************
*  Type Declarations                                              			 *
******************************************************************************/

typedef struct
{
    uint16    HwTrigger;           /* Variable for flag used in IoHwAb_Adc_HardwareTrigger function */
    uint16    Main;                /* Variable for flag used in IoHwAb_Adc_MainFunction function */
    uint16    MuxNotification;     /* Variable for flag used in IoHwAb_AdcMuxNotification function */
} IoHwAb_AdcFlagType;

/*****************************************************************************
*  Public Forward Declarations                                          	 *
******************************************************************************/
extern void IoHwAb_Adc_Init(void);
extern void IoHwAb_Adc_DeInit(void);
extern void IoHwAb_Adc_MainFunction(void);
extern Std_ReturnType  IoHwAb_Adc_GetSyncRawAdc(IoHwAb_AdcSignalIdType AdcId,uint16* SyncRawValue, IoHwAb_ErrorType* ErrorStatus);
extern Std_ReturnType  IoHwAb_Adc_GetAsyncRawAdc(IoHwAb_AdcSignalIdType AdcId,uint16* AsyncRawValue, IoHwAb_ErrorType* ErrorStatus);
extern Std_ReturnType  IoHwAb_Adc_GetProcessedAdc(IoHwAb_AdcSignalIdType AdcId,sint32* ProcessedValue, IoHwAb_ErrorType* ErrorStatus);
#if (IOHWAB_ADC_HW_TRIGGER_ENABLE == STD_ON)
extern void IoHwAb_Adc_HardwareTrigger(uint8 GroupIndex);
#endif
#endif
#endif /* IOHWAB_ADC_H*/


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
Date              :13-Mar-2020
By                :MSAVARIY
Traceability      : 808643: [Honda BEV] IoHwAb configuration
Change Description: MUX ADC support added
******************************************************************************/
