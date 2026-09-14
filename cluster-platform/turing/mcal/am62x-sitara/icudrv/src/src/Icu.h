/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2024. Visteon Corporation owns all rights to           *
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
/*****************************************************************************
*  File Name         :  Icu.h                                                *
*  Module Short Name :  Icu                                                  *
*  Description       :  This file contains implementations of the Icu Driver *
*                       for AM62PX series microcontrollers.                  *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  Clang Compiler                                         *
* Target Hardware  :  AM62PX micro based Hardware Platform                   *
*                                                                            *
******************************************************************************/

#ifndef ICU_H
#define ICU_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "Icu_Types.h"
#include "Icu_Cfg.h"
#include <hw_include/cslr_soc.h>

#include <hw_include/soc.h>
#include <hw_include/lld_gpio.h>
#include <hw_include/arch/lld_arch.h>
#include <hw_include/cslr.h>
#include <drivers/sciclient.h>

/*****************************************************************************
*                               Functions                                    *
******************************************************************************/

/*============================================================================
**
** Function Name    :   Icu_Init
**
** Visibility       :   Public
**
** Description      :   The Init function sets up the ICU configuration based 
**                      on the provided ConfigPtr parameter.
**
** Invocation       :   EcumExt.c
**
** Inputs           :   Icu_ConfigType * ConfigPtr - Pointer to a configuration type.
**
** Outputs          :   None
**
** Critical Section :   None
**
**==========================================================================*/

extern void Icu_Init(const Icu_ConfigType* ConfigPtr);

/*============================================================================
**
** Function Name    :   Icu_DeInit
**
** Visibility       :   Public
**
** Description      :   The DeInit function sets the module variables to default
**                      state.
**
** Invocation       :   In Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   None
**
**==========================================================================*/

extern void Icu_DeInit(void);

/*============================================================================
**
** Function Name    :   Icu_EnableNotification
**
** Visibility       :   Public
**
** Description      :   This function enables interrupt notifications for a specific
**                      ICU channel configured for edge detection mode
**
** Invocation       :   Called when enabling ICU channel interrupts
**
** Inputs           :   Icu_ChannelType Channel - Channel index to enable
**
** Outputs          :   None
**
** Critical Section :   None
**
**==========================================================================*/

extern void Icu_EnableNotification(Icu_ChannelType Channel);

/*============================================================================
**
** Function Name    :   Icu_DisableNotification
**
** Visibility       :   Public
**
** Description      :   This function disables interrupt notifications for a specific
**                      ICU channel configured for edge detection mode
**
** Invocation       :   Called when disabling ICU channel interrupts
**
** Inputs           :   Icu_ChannelType Channel - Channel index to disable
**
** Outputs          :   None
**
** Critical Section :   None
**
**==========================================================================*/

extern void Icu_DisableNotification(Icu_ChannelType Channel);

/****************************************************************************
*     Interrupt Service Routine (ISR) for MCU GPIO0 (Bank0) interrupts      *
****************************************************************************/

extern void MCU_ISR_6func(void);

/****************************************************************************
*     Interrupt Service Routine (ISR) for MCU GPIO0 (Bank1) interrupts      *
****************************************************************************/

extern void MCU_ISR_7func(void);

/****************************************************************************
*     Interrupt Service Routine (ISR) for MAIN GPIO0  interrupts            *
****************************************************************************/

extern void MAIN_ISR_34func(void);

/****************************************************************************
*     Interrupt Service Routine (ISR) for MAIN GPIO1 interrupts             *
****************************************************************************/

extern void MAIN_ISR_35func(void);

/*============================================================================
**
** Function Name    :   Icu_IrqHandler
**
** Visibility       :   Public
**
** Description      :   This ISR handler checks the interrupt status of the 
**                      GPIO pin associated with the ICU channel and calls 
**                      the notification callback if the interrupt.
**
** Invocation       :   ISR
**
** Inputs           :   Icu_ChannelType Channel - The ICU channel number to handle
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/

extern void ICU_IrqHandler(Icu_ChannelType Channel);

#endif /* ICU_H */

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
/**-------------------------------------------------------------------------*/
/*Date              : 19-11-2024                                            */
/*Version           :                                                       */
/*By                : kporkodi                                              */
/*Traceability      :                                                       */
/*Change Description: Proveout, Initial Version                             */
/*--------------------------------------------------------------------------*/

/**-------------------------------------------------------------------------*/
/*Date              : 02-12-2024                                            */
/*Version           :                                                       */
/*By                : kporkodi                                              */
/*Traceability      :                                                       */
/*Change Description: Initial Version Platform Release                      */
/*--------------------------------------------------------------------------*/
