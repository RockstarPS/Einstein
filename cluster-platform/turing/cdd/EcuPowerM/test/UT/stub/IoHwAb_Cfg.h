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
 * @file IoHwAb_Cfg.h
 * @brief Configuration header file for IoHwAb
 * ****************************************************************************/
#ifndef IOHWAB_CFG_H
#define IOHWAB_CFG_H
/*****************************************************************************
 *  Include Files                                                             *
 ******************************************************************************/
#include "IoHwAb_DIn.h"
#include "IoHwAb_DOut.h"
#include "IoHwAb_Adc.h"
#include "IoHwAb_Filter.h"
#include "IoHwAb_PulseOut.h"
#include "IoHwAb_PulseInput.h"
#include "IoHwAb_Pwm.h"
/* Refer stream MMC_2020_4P45_IC_OSBSP_DEV_ENG for getting the sample of file 
 IoHwAb_WdgM_Cfg.h
 di-gen-2020-mmc-4p45-ic-swc-osbsp - this component has the file
 #include "IoHwAb_WdgM_Cfg.h"
 */
/*****************************************************************************
 *  Public Macros Definitions                                                *                                                                                       *
 ******************************************************************************/
#define IOHWAB_VERSION_INFO_API STD_OFF



/*TODO:Needs to be removed when single safe component is used */
#define IoHwAb_Init          IoHwAb_Init
#define IoHwAb_MainFunction      IoHwAb_MainFunction
#define IoHwAb_DeInit        IoHwAb_DeInit

#define IoHwAb_SetOutputPin      IoHwAb_SetOutputPin
#define IoHwAb_SetOutputGroup      IoHwAb_SetOutputGroup

#define IoHwAb_GetProcessedInput    IoHwAb_GetProcessedInput
#define IoHwAb_GetAsyncRawInput    IoHwAb_GetAsyncRawInput
#define IoHwAb_GetSyncRawInput    IoHwAb_GetSyncRawInput
#define IoHwAb_GetInputGroup      IoHwAb_GetInputGroup

#define IoHwAb_GetProcessedAdc    IoHwAb_GetProcessedAdc
#define IoHwAb_GetAsyncRawAdc      IoHwAb_GetAsyncRawAdc
#define IoHwAb_GetSyncRawAdc      IoHwAb_GetSyncRawAdc

/*TODO:Needs to be removed when single safe component is used */
#define IoHwAb_Start_Signal_Measurement_PulseInput      IoHwAb_Start_Signal_Measurement_PulseInput
#define IoHwAb_Stop_Signal_Measurement_PulseInput       IoHwAb_Stop_Signal_Measurement_PulseInput
#define IoHwAb_Update_CalibParam_PulseInput             IoHwAb_Update_CalibParam_PulseInput
#define IoHwAb_GetRollingCount_PulseInput               IoHwAb_GetRollingCount_PulseInput
#define IoHwAb_ResetRollingCount_PulseInput             IoHwAb_ResetRollingCount_PulseInput
#define IoHwAb_GetCurrentSignalStatus_PulseInput        IoHwAb_GetCurrentSignalStatus_PulseInput
#define IoHwAb_GetCurrentSpeed_PulseInput               IoHwAb_GetCurrentSpeed_PulseInput

/*
 ** The required adapter init functions are configured here
 */
#define IOHWAB_ADAPTER_INIT()      \
  /**<  Filter init function should  be initialized before other adapters*/  \
     IoHwAb_Filter_Init();        \
      IoHwAb_DIn_Init();        \
      IoHwAb_DOut_Init();        \
      IoHwAb_Adc_Init();     \
	  IoHwAb_Pwm_Init();       \

/*
** The required adapter init functions are configured here
*/
#define IOHWAB_ADAPTER_DEINIT()      \
      IoHwAb_DIn_DeInit();        \
	  IoHwAb_DOut_DeInit();        \
      IoHwAb_Adc_DeInit();       \
	  IoHwAb_Pwm_DeInit();        \
      /**<  Filter init function should  be de-initialized before other adapters*/  \
     IoHwAb_Filter_DeInit();        \

/*
 ** The required adapter main functions are configured here
 */
#define IOHWAB_ADAPTER_MAINFUNCTION()  \
      IoHwAb_DIn_MainFunction();    \
      IoHwAb_DOut_MainFunction();    \
      IoHwAb_Adc_MainFunction();   \
      IoHwAb_Pwm_MainFunction();   \
     /*  TODO : IoHwAb Pwm Main function Not added - To be analysed  - vbalakr3*/\
      /**<  Filter init function should  be executed after other adapters*/  \
      IoHwAb_Filter_MainFunction();    \
	  
/*
 ** The Macro for Wdg checkpoint
 */
//msavariy - hondaBEV
//#define IOHWAB_WATCHDOG_SERVICE_CALL()             RTE_CALL_WACTHDOGEXTSERVICES()
#define IOHWAB_WATCHDOG_SERVICE_CALL()

#endif /* IOHWAB_CFG_H */

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
 Date              :22-Aug-2018
 By                :pragesh
 Traceability      :RTC- RTC #1240636: MMC:Callback function required in IoHwAb_MainFunction safe
 Change Description:Added macro for WdgM checkpoint
 ******************************************************************************/
/*****************************************************************************
 Date              :23-Nov-2018
 By                :bbaskara
 Traceability      :RTC-1243011: MMC: IohwAb safe MISRA Fix
 Change Description:Fixed MISRA warning.
 ******************************************************************************/
/*****************************************************************************
 Date              :5-Dec-2018
 By                :nrajaman
 Traceability      :1206553: Hyundai SP2: PIC component upgrade for ASIL compliance.
 Change Description:Updated for IoHwAb_PulseInput safe implementation
 ******************************************************************************/
/*****************************************************************************
 Date              :17-Feb-2019
 By                :bjayara2
 Traceability      :RTC-1273840: Integration of IoHWAb component from MMC and SP2
 Change Description: Fixed an issue found in compilation
 ******************************************************************************/
