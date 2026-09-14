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
* @file IoHwAb_DOut_Cfg.h
* @brief Configuration header file for digital output
* ****************************************************************************/
#ifndef IOHWAB_PULSEINPUT_CFG_H
#define IOHWAB_PULSEINPUT_CFG_H
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/

//#include "Icu.h"
#include "IoHwAb_PwmIn_Cfg.h"
#include "IoHwAb_PwmIn.h"
#include "Gpt.h"
#include "Dio.h"
#include  "Std_Types.h"

/*****************************************************************************
*  Prublic Macros Definitions                                                *
******************************************************************************/
/**
* @brief Macro to enable the IoHwAb Digital output Module
*/
#define IOHWAB_PULSEINPUT_ENABLE      (STD_OFF)
/*****************************************************************************
*  Private Macros Definitions                                                *
******************************************************************************/
#if defined(IOHWAB_PULSEINPUT_ENABLE) && (IOHWAB_PULSEINPUT_ENABLE == STD_ON)
    
/*
** Number of pulse input channels going to be used
*/
#define IOHWAB_PULSEINPUT_NUMBER_OF_SIGNALS        1U


/*
** Periodicity of the IoHwAb Main function
*/
#define IOHWAB_PULSEINPUT_MAINFUNCTION_PERIODICITY  ((uint16)10)

//Period Related Configurations
#define PULSE_INPUT_CHECK_VALID_PERIOD       STD_ON
#define PULSE_INPUT_CHECK_HYST_FOR_PERIOD    STD_ON

//Duty Related Configurations
#define PULSE_INPUT_CAPTURE_DUTY_VALUE       STD_OFF
#define PULSE_INPUT_CHECK_VALID_DUTY         STD_OFF
#define PULSE_INPUT_CHECK_HYST_FOR_DUTY      STD_OFF


//Data Buffer for updating time ticks by Icu
#define PULSE_INPUT_BUFFER_SIZE    ((uint16)10)    /**<  Timestamp Buffer size*/


//Below definitions are in PwmIn_Cgh.harderr

/// Macro defines number of PWM period inputs
#define IoHwAb_PwmIn_PeriodInCfg_Count   1
 

/*
** Critical Sections Entry & Exit Definitions
*/
#define IOHWAB_PULSEINPUT_ENTER_CRITICAL_SECTION()             ((void)Os_DisableInterruptSource(OsIsr_PulseInputCapture))
#define IOHWAB_PULSEINPUT_EXIT_CRITICAL_SECTION()              ((void)Os_EnableInterruptSource(OsIsr_PulseInputCapture, FALSE))



/*****************************************************************************
*  Type Declarations                                              			 *
******************************************************************************/



/*****************************************************************************
*  Type Declarations                                                         *
******************************************************************************/

typedef struct
{
    uint8 MapPeriodId;  /*Map the respective period ID for the PulseInput signals*/
}IoHwAb_PulseInputCfgType;


/*****************************************************************************
*  Public Forward Declarations                                          	 *
******************************************************************************/

/*Configure the number of pulseinput signal mapped to periodId signals */
extern const IoHwAb_PulseInputCfgType IoHwAb_PulseInputCfg[IOHWAB_PULSEINPUT_NUMBER_OF_SIGNALS];


/*****************************************************************************
*  Private Forward Declarations                                          	 *
******************************************************************************/

#endif
#endif /* IOHWAB_PULSEINPUT_CFG_H */

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
By                :nrajaman
Traceability      :
Change Description:Initial Version for IoHwAb_PulseOut safe implementation
******************************************************************************/
/*****************************************************************************
Date              :5-Dec-2018
By                :nrajaman
Traceability      :1206553: Hyundai SP2: PIC component upgrade for ASIL compliance.
Change Description:Initial Version for IoHwAb_PulseInput safe implementation
******************************************************************************/
/*****************************************************************************
Date              :26-Dec-2018
By                :asivalin
Traceability      :1260028: Integrate the latest PIC Integrated IoHwAb base in SP2 & Release.
Change Description:PIC Configuration Update as per Hyundai SP2
******************************************************************************/
