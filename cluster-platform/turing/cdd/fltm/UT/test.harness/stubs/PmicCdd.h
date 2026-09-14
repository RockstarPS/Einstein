/**
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2024. Visteon Corporation owns all rights to
 this work and intends to maintain it in confidence to preserve
 its trade secret status. Visteon Corporation reserves the right,
 under the copyright laws of the United States or those of any
 other country that may have jurisdiction, to protect this work
 as an unpublished work, in the event of an inadvertent or
 deliberate unauthorized publication. Visteon Corporation also
 reserves its rights under all copyright laws to protect this
 work as a published work, when appropriate. Those having access
 to this work may not copy it, use it, modify it or disclose the
 information contained in it without the written authorization
 of Visteon Corporation.
 * @endverbatim
 * @file        PmicCdd.c
 * @details     <b> TI PMIC driver for TPS65224 </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2024
 *
 */
#ifndef  PMICCDD_H_
#define  PMICCDD_H_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "PmicCdd_Cfg.h"
#include "PmicCdd_Types.h"
#include "Crc.h"
#include "Crc_Cfg.h"
#include "WdgIf.h"
#include "PmicCdd_I2c.h"


/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "I2c_Types.h"
#include "I2c_Cfg.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/



/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
/*****************************************************************************
*                               Functions                                    *
******************************************************************************/

/*============================================================================
**
** Function Name    :   PmicCdd_Init
**
** Visibility       :   Public
**
** Description      :   The Init function is called to initialise the Global
**                      and Static variables of this module.
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
void PmicCdd_Init(void);

/*============================================================================
**
** Function Name    :   PmicCdd_MainFunction
**
** Visibility       :   Public
**
** Description      :   This function is invoked periodically by the Os.
**                      This function process the pending transmissions
**                      according to the priority.
**
** Invocation       :   Os Scheduleing.
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
void PmicCdd_MainFunction(void);

/* ADC MCAL Function */

/*============================================================================
**
** Function Name    :   PmicCdd_IoHwAb_Adc_SetupResultBuffer
**
** Visibility       :   Public
**
** Description      :   This function used in Setting up the result buffer for ADC
**
** Invocation       :   Application
**
** Inputs           :   PmicCdd_Adc_GroupType Group - ADC Group
**                      PmicCdd_Adc_ResultBufferType* DataResultBufferPtr - Pointer to ADC Result Buffer
**
** Outputs          :  E_OK: ADC Result buffer is setup successfully.
**                     E_NOT_OK: ADC Result buffer is not setup successfully.
**
** Critical Section :  Yes
**
**==========================================================================*/
Std_ReturnType PmicCdd_IoHwAb_Adc_SetupResultBuffer(PmicCdd_Adc_GroupType Group, uint16* DataResultBufferPtr);

/*============================================================================
**
** Function Name    :   PmicCdd_IoHwAb_Adc_StartGroupConversion
**
** Visibility       :   Public
**
** Description      :   This function used in start the ADC conversion
**
** Invocation       :   Application
**
** Inputs           :   PmicCdd_Adc_GroupType Group - ADC Group
**
** Outputs          :  None
**
** Critical Section :  Yes
**
**==========================================================================*/
void PmicCdd_IoHwAb_Adc_StartGroupConversion(PmicCdd_Adc_GroupType Group);

/*============================================================================
**
** Function Name    :   PmicCdd_IoHwAb_Adc_StopGroupConversion
**
** Visibility       :   Public
**
** Description      :   This function used in stop the ADC conversion
**
** Invocation       :   Application
**
** Inputs           :   PmicCdd_Adc_GroupType Group - ADC Group
**
** Outputs          :  None
**
** Critical Section :  Yes
**
**==========================================================================*/
void PmicCdd_IoHwAb_Adc_StopGroupConversion(PmicCdd_Adc_GroupType Group);

/*============================================================================
**
** Function Name    :   PmicCdd_IoHwAb_Adc_ReadGroup
**
** Visibility       :   Public
**
** Description      :   This function used to get the ADC result
**
** Invocation       :   Application
**
** Inputs           :   PmicCdd_Adc_GroupType Group - ADC Group
**                      uint16* DataResultBufferPtr - Pointer to ADC Result Buffer
**
** Outputs          :  E_OK - ADC Result is read successfully.
**                     E_NOT_OK - ADC Result is not read successfully.
**
** Critical Section :  Yes
**
**==========================================================================*/
Std_ReturnType PmicCdd_IoHwAb_Adc_ReadGroup(PmicCdd_Adc_GroupType Group, uint16* DataResultBufferPtr);

/*============================================================================
**
** Function Name    :   PmicCdd_IoHwAb_Adc_EnableHardwareTrigger
**
** Visibility       :   Public
**
** Description      :  
**
** Invocation       :  
**
** Inputs           :   
**
** Outputs          :  
**
** Critical Section :  
**
**==========================================================================*/
void PmicCdd_IoHwAb_Adc_EnableHardwareTrigger(PmicCdd_Adc_GroupType Group);

/*============================================================================
**
** Function Name    :   PmicCdd_IoHwAb_Adc_EnableHardwareTrigger
**
** Visibility       :   Public
**
** Description      :  
**
** Invocation       :  
**
** Inputs           :   
**
** Outputs          :  
**
** Critical Section :  
**
**==========================================================================*/
void PmicCdd_IoHwAb_Adc_DisableHardwareTrigger(PmicCdd_Adc_GroupType Group);

/*============================================================================
**
** Function Name    :   PmicCdd_IoHwAb_Adc_EnableGroupNotification
**
** Visibility       :   Public
**
** Description      :  This enables the ADC group notification
**
** Invocation       :  Public
**
** Inputs           :   PmicCdd_Adc_GroupType Group - ADC Group
**
** Outputs          :  None
**
** Critical Section :  No
**
**==========================================================================*/
void PmicCdd_IoHwAb_Adc_EnableGroupNotification(PmicCdd_Adc_GroupType Group);

/*============================================================================
**
** Function Name    :   PmicCdd_IoHwAb_Adc_DisableGroupNotification
**
** Visibility       :   Public
**
** Description      :  This disables the ADC group notification
**
** Invocation       :  Public
**
** Inputs           :   PmicCdd_Adc_GroupType Group - ADC Group
**
** Outputs          :  None
**
** Critical Section :  No
**
**==========================================================================*/
void PmicCdd_IoHwAb_Adc_DisableGroupNotification(PmicCdd_Adc_GroupType Group);

/*============================================================================
**
** Function Name    :   PmicCdd_IoHwAb_Adc_GetGroupStatus
**
** Visibility       :   Public
**
** Description      :  This disables the ADC group notification
**
** Invocation       :  Public
**
** Inputs           :   PmicCdd_Adc_GroupType Group - ADC Group
**
** Outputs          :  PMICCDD_ADC_BUSY - ADC is busy
**                     PMICCDD_ADC_STREAM_COMPLETED - ADC is completed
**                     PMICCDD_ADC_ERROR - ADC is in error state
**                     PMICCDD_ADC_IDLE - ADC is in idle state
**
** Critical Section :  No
**
**==========================================================================*/
PmicCdd_Adc_StatusType PmicCdd_IoHwAb_Adc_GetGroupStatus(PmicCdd_Adc_GroupType Group);


/* PMIC Interrupt clear request Functions */

/*============================================================================
**
** Function Name    :   PmicCdd_IntBuck_ClearAllInterrupts
**
** Visibility       :   Public
**
** Description      :  This clears all the Buck Interrupts
**
** Invocation       :  Public
**
** Inputs           :   void
**
** Outputs          :  void
**
** Critical Section :  No
**
**==========================================================================*/
void PmicCdd_IntBuck_ClearAllInterrupts(void);

/*============================================================================
**
** Function Name    :   PmicCdd_IntLdoVmon_ClearAllInterrupts
**
** Visibility       :   Public
**
** Description      :  This clears all the Ldo and Vmon Interrupts
**
** Invocation       :  Public
**
** Inputs           :   void
**
** Outputs          :  void
**
** Critical Section :  No
**
**==========================================================================*/
void PmicCdd_IntLdoVmon_ClearAllInterrupts(void);

/*============================================================================
**
** Function Name    :   PmicCdd_IntGpio_ClearAllInterrupts
**
** Visibility       :   Public
**
** Description      :  This clears all the Gpio Interrupts
**
** Invocation       :  Public
**
** Inputs           :   void
**
** Outputs          :  void
**
** Critical Section :  No
**
**==========================================================================*/
void PmicCdd_IntGpio_ClearAllInterrupts(void);

/*============================================================================
**
** Function Name    :   PmicCdd_IntStartup_ClearAllInterrupts
**
** Visibility       :   Public
**
** Description      :  This clears all the Startup Interrupts
**
** Invocation       :  Public
**
** Inputs           :   void
**
** Outputs          :  void
**
** Critical Section :  No
**
**==========================================================================*/
void PmicCdd_IntStartup_ClearAllInterrupts(void);

/*============================================================================
**
** Function Name    :   PmicCdd_IntMisc_ClearAllInterrupts
**
** Visibility       :   Public
**
** Description      :  This clears all the Miscellaneous Interrupts
**
** Invocation       :  Public
**
** Inputs           :   void
**
** Outputs          :  void
**
** Critical Section :  No
**
**==========================================================================*/
void PmicCdd_IntMisc_ClearAllInterrupts(void);

/*============================================================================
**
** Function Name    :   PmicCdd_IntModerateError_ClearAllInterrupts
**
** Visibility       :   Public
**
** Description      :  This clears all the Moderate Interrupts
**
** Invocation       :  Public
**
** Inputs           :   void
**
** Outputs          :  void
**
** Critical Section :  No
**
**==========================================================================*/
void PmicCdd_IntModerateError_ClearAllInterrupts(void);

/*============================================================================
**
** Function Name    :   PmicCdd_IntSevere_ClearAllInterrupts
**
** Visibility       :   Public
**
** Description      :  This clears all the Severe Interrupts
**
** Invocation       :  Public
**
** Inputs           :   void
**
** Outputs          :  void
**
** Critical Section :  No
**
**==========================================================================*/
void PmicCdd_IntSevere_ClearAllInterrupts(void);

/*============================================================================
**
** Function Name    :   PmicCdd_IntFsmErr_ClearAllInterrupts
**
** Visibility       :   Public
**
** Description      :  This clears all the Fsm Interrupts
**
** Invocation       :  Public
**
** Inputs           :   void
**
** Outputs          :  void
**
** Critical Section :  No
**
**==========================================================================*/
void PmicCdd_IntFsmErr_ClearAllInterrupts(void);

/*============================================================================
**
** Function Name    :   PmicCdd_IntEsm_ClearAllInterrupts
**
** Visibility       :   Public
**
** Description      :  This clears all the Esm Interrupts
**
** Invocation       :  Public
**
** Inputs           :   void
**
** Outputs          :  void
**
** Critical Section :  No
**
**==========================================================================*/
void PmicCdd_IntEsm_ClearAllInterrupts(void);

/*============================================================================
**
** Function Name    :   PmicCdd_WdErrStatus_ClearAllInterrupts
**
** Visibility       :   Public
**
** Description      :  This clears all the Watchdog Interrupts
**
** Invocation       :  Public
**
** Inputs           :   void
**
** Outputs          :  void
**
** Critical Section :  No
**
**==========================================================================*/
void PmicCdd_WdErrStatus_ClearAllInterrupts(void);

/*============================================================================
**
** Function Name    :   Gpt_ExtWDNotify
**
** Visibility       :   Public
**
** Description      :   Periodically checks and updates the watchdog timer.
**
** Invocation       :   ISR
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
void Gpt_ExtWDNotify (void);

/* WDT functions */

/*============================================================================
**
** Function Name    :   PmicCdd_WdgSetTriggerCondition
**
** Visibility       :   Public
**
** Description      :   Setting up a watchdog timer trigger condition.
**
** Invocation       :    WdgIf
**
** Inputs           :   uint8 DeviceIndex - Device Index
**                      uint16 Timeout - Timeout to trigger the watchdog
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
void PmicCdd_WdgSetTriggerCondition(uint8 DeviceIndex,uint16 Timeout);

/*============================================================================
**
** Function Name    :   PmicCdd_WdgSetMode
**
** Visibility       :   Public
**
** Description      :   Setting up a watchdog timer mode.
**
** Invocation       :   WdgIf
**
** Inputs           :  WdgIf_ModeType WdgMode - Mode of the watchdog
**
** Outputs          :  STD_OK - Success
**                     STD_NOT_OK - Failure
**
** Critical Section :  No
**
**==========================================================================*/
Std_ReturnType PmicCdd_WdgSetMode(WdgIf_ModeType WdgMode);

/*============================================================================
**
** Function Name    :   PmicCdd_EnterWdgLongWin
**
** Visibility       :   Public
**
** Description      :   Enter watchdog long window.
**
** Invocation       :   Application
**
** Inputs           :  NA
**
** Outputs          :  STD_OK - Success
**                     STD_NOT_OK - Failure
**
** Critical Section :  No
**
**==========================================================================*/
#if (PMICCDD_ENABLE_WDG == STD_ON)
Std_ReturnType PmicCdd_EnterWdgLongWin(void);
#endif

/*============================================================================
**
** Function Name    :   PmicCdd_ExitWdgLongWin
**
** Visibility       :   Public
**
** Description      :   Exit watchdog long window.
**
** Invocation       :   Application
**
** Inputs           :  NA
**
** Outputs          :  STD_OK - Success
**                     STD_NOT_OK - Failure
**
** Critical Section :  No
**
**==========================================================================*/
#if (PMICCDD_ENABLE_WDG == STD_ON)
Std_ReturnType PmicCdd_ExitWdgLongWin(void);
#endif


/* Init and Runnables */
extern void PmicCdd_Init(void);
extern void PmicCdd_MainFunction(void);

/* Interrupt functions */

/*============================================================================
**
** Function Name    :   PmicCdd_nINTGpioInt
**
** Visibility       :   Public
**
** Description      :  This handles the ADC Conversion by checking the status of Interrupt registers
**
** Invocation       :  ISR
**
** Inputs           :   void
**
** Outputs          :  None
**
** Critical Section :  yes
**
**==========================================================================*/
extern void PmicCdd_nINTGpioInt(void);

/*============================================================================
**
** Function Name    :   PmicCdd_GetResetReason
**
** Visibility       :   Public
**
** Description      :  This returns the reason for reason of reset
**
** Invocation       :  Application
**
** Inputs           :   void
**
** Outputs          :  PmicCdd_ResetReasonType - Reset Reason
**                    PmicCdd_PmicWdg_Reset - Pmic Wdg Reset
**                    PmicCdd_PowerOn_Reset - Power On Reset
**
** Critical Section :  yes
**
**==========================================================================*/
extern PmicCdd_ResetReasonType PmicCdd_GetResetReason(void);

/*============================================================================
**
** Function Name    :   PmicCdd_GetResetCount
**
** Visibility       :   Public
**
** Description      :  This returns the reset count from the PMIC register
**
** Invocation       :  Application
**
** Inputs           :   void
**
** Outputs          :  E_OK - Success
**                     E_NOT_OK - Fail
**
** Critical Section :  yes
**
**==========================================================================*/
extern Std_ReturnType PmicCdd_GetResetCount(uint8* PmicReset_Conut);

/*============================================================================
**
** Function Name    :   PmicCdd_ClearResetCount
**
** Visibility       :   Public
**
** Description      :  This function is used to clear Reset Counter
**
** Invocation       :  Application
**
** Inputs           :   void
**
** Outputs          :   void
**
** Critical Section :  yes
**
**==========================================================================*/
extern void PmicCdd_ClearResetCount(void);

extern void PmicCdd_PerformReset(void);



#endif

/*****************************************************************************
*     End of File
*
*******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/*----------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  05-Jun-2024
By                :  MSAVARIY
Traceability      : https://visteon.atlassian.net/browse/PE4TI29141-3280
Change Description: PmicCdd initial release, Added support for WDG and ADC
        Initialization and functionalities.
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :  26-Jun-2024
By                :  MSAVARIY
Traceability      : https://visteon.atlassian.net/browse/PE4TI29141-3709
Change Description: Added support for ESM configuration and Error interrupt checking,
            Reporting and clear functionalities.
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :  24-Sep-2024
By                :  sdv
Traceability      : https://visteon.atlassian.net/browse/PE4TI29141-4380
Change Description: PmicCdd ADC Interrupt Mechanism Handling Implementation
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :  24-Mar-2025
By                :  sdv
Traceability      : https://visteon.atlassian.net/browse/PE4TI29141-6866
Change Description: PmicCdd Formal Release - Long Window API update and 
                    required documents update like PG, IG, UTP, FTP, Design etc
-----------------------------------------------------------------------------*/