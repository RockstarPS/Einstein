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
* @brief Configuration definitions for digital output
* ****************************************************************************/
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/
#include "Rte_IoHwAb.h"
#include "IoHwAb_PulseInput.h"
#include "IoHwAb_PulseInputCbk.h"


#if defined(IOHWAB_PULSEINPUT_ENABLE) && (IOHWAB_PULSEINPUT_ENABLE == STD_ON)
/*****************************************************************************
*  Configuration Definitions                                                 *                                                                                       *
******************************************************************************/

const IoHwAb_PulseInputCfgType IoHwAb_PulseInputCfg[IOHWAB_PULSEINPUT_NUMBER_OF_SIGNALS] =
                                                                                            {
                                                                                               eIOPeriodInIdSafe_SpeedIn_PWMIN
                                                                                            };
                                                                                            
                                                                                            

/*****************************************************************************
*  ICU related Configuration Definitions                                      *                                                                                       *
******************************************************************************/
                                                                                           
//Data Buffer for updating time ticks by Icu
#define PULSE_INPUT_BUFFER_SIZE    ((uint16)10)    /**<  Timestamp Buffer size*/

Icu_ValueType PIC_Timer_DataBuffer[PULSE_INPUT_BUFFER_SIZE]; /**<  Timestamp Buffer*/


/**
* Callback notification function from ICU module on detection of configured edge(Rising/Falling/Both)
* @param  Id - Channel Id
* @param  BufferLength - Pointer to get the data length
* @return Icu_ValueType* - Timestamp Buffer Pointer
*/
Icu_ValueType* IoHwAb_PulseInput_GetTimeStampBufferPointer(IoHwAb_PwmIn_PeriodId Id, uint16 *BufferLength)
{
	Icu_ValueType *BuffPtr = NULL;
	if(Id == eIOPeriodInIdSafe_SpeedIn_PWMIN)
	{
		BuffPtr = PIC_Timer_DataBuffer;
		*BufferLength = PULSE_INPUT_BUFFER_SIZE;
	}
	return BuffPtr;
}

/**
* Callback notification function from ICU module on detection of configured edge(Rising/Falling/Both)
* @param  None
* @return void

*/
void IoHwAb_PulseInput_Notify_EdgeDetected(void)
{
#if(PULSE_INPUT_CAPTURE_DUTY_VALUE == STD_ON)
    if(Dio_ReadChannel(IoHwAb_PwmInDutyCfg[eIODutyInIdSafe_SpeedIn_PWMIN].DioChnlId) != IoHwAb_PwmInDutyCfg[eIODutyInIdSafe_SpeedIn_PWMIN].ActiveDutyPolarity)
	{
		IoHwAb_PulseInput_CalculateDuty(eIODutyInIdSafe_SpeedIn_PWMIN, PIC_Timer_DataBuffer, PULSE_INPUT_BUFFER_SIZE);
	}
	else
#endif
	{
		IoHwAb_PulseInput_CalculatePeriod(eIOPeriodInIdSafe_SpeedIn_PWMIN, PIC_Timer_DataBuffer, PULSE_INPUT_BUFFER_SIZE);
	}
}

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
Date              :5-Dec-2018
By                :nrajaman
Traceability      :1206553: Hyundai SP2: PIC component upgrade for ASIL compliance.
Change Description:Initial Version for IoHwAb_PulseInput safe implementation
******************************************************************************/

