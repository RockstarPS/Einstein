/******************************************************************************
 * $Revision: 10546 $
 * $Date: 2014-09-17 10:04:52 +0200 (Wed, 17 Sep 2014) $
 *****************************************************************************/
/* __DISCLAIMER_START__                                                      */
/******************************************************************************
* Copyright (C) 2013 Spansion LLC. All Rights Reserved. 
*
* This software is owned and published by: 
* Spansion LLC, 915 DeGuigne Dr. Sunnyvale, CA  94088-3453 ("Spansion").
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND 
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with Spansion 
* components. This software is licensed by Spansion to be adapted only 
* for use in systems utilizing Spansion components. Spansion shall not be 
* responsible for misuse or illegal use of this software for devices not 
* supported herein.  Spansion is providing this software "AS IS" and will 
* not be responsible for issues arising from incorrect user implementation 
* of the software.  
*
* SPANSION MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
* REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS), 
* ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING, 
* WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED 
* WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED 
* WARRANTY OF NONINFRINGEMENT.  
* SPANSION SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT, 
* NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT 
* LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION, 
* LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR 
* INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA, 
* SAVINGS OR PROFITS, 
* EVEN IF SPANSION HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. 
* YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
* INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED 
* FROM, THE SOFTWARE.  
*
* This software may be replicated in part or whole for the licensed use, 
* with the restriction that this Disclaimer and Copyright notice must be 
* included with each copy of this software, whether used in part or whole, 
* at all times.
******************************************************************************/
/* __DISCLAIMER_END__                                                        */
/*****************************************************************************/
/** \file button_definition.h
 **
 ** Basic functions for buttons using GPIO, featuring debouncing (no interrupts)
 ** The timer module is used (TIMER_ID_BUTTON). It must be initialized before
 ** and the Timer_Main function must be called cyclically (for callback function
 ** support).
 **
 ** History:
 ** - 2011-11-08  1.00  JWa  First version for MB9D126
 ** - 2013-18-12  1.00s Mkoe Change to Spansion Disclaimer
 ** - 2014-03-07  1.01  MKoe Added version check
 ** - 2014-03-07  1.02  CEy  Fixed button define for BB SW4
 *****************************************************************************/

#ifndef __BUTTON_DEFINITION_H__
#define __BUTTON_DEFINITION_H__

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "base_types.h"
#include "mcu_settings.h"

/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define')                           */
/*****************************************************************************/
/** Button ID for button up */
#define BUTTON_ID_SW1   ((uint16_t)0xA)
/** Button ID for button right */
#define BUTTON_ID_SW2   ((uint16_t)0xB)        
/** Button ID for button down */
#define BUTTON_ID_SW3   ((uint16_t)0xC)
/** Button ID for button left */
#define BUTTON_ID_SW4   ((uint16_t)0xD)        
/** Button ID for button centre */
#define BUTTON_ID_SW5   ((uint16_t)0xE)        


/** Button port number for shared Starter Kit SW3 and Base Board FR5-BASE-001 SW1 */
#define BUTTON_PORT_SK_SW3_BB_SW1    2
/** Button pin number for shared Starter Kit SW3 and Base Board FR5-BASE-001 SW1 */
#define BUTTON_PIN_SK_SW3_BB_SW1     18

/** Button port number for shared Starter Kit SW4 and Base Board FR5-BASE-001 SW2 */
#define BUTTON_PORT_SK_SW4_BB_SW2    2
/** Button pin number for shared Starter Kit SW3 and Base Board FR5-BASE-001 SW1 */
#define BUTTON_PIN_SK_SW4_BB_SW2     21


/** Button port number for Base Board FR5-BASE-001 SW3 */
#define BUTTON_PORT_BB_SW3          3
/** Button pin number for Base Board FR5-BASE-001 SW3 */
#define BUTTON_PIN_BB_SW3           12

/** Button port number for Base Board FR5-BASE-001 SW4 */
#define BUTTON_PORT_BB_SW4          2
/** Button pin number for Base Board FR5-BASE-001 SW4 */
#define BUTTON_PIN_BB_SW4           26

/** Button port number for Base Board FR5-BASE-001 SW5 */
#define BUTTON_PORT_BB_SW5          3
/** Button pin number for Base Board FR5-BASE-001 SW5 */
#define BUTTON_PIN_BB_SW5           0  


/**
** Assignement of buttons to GPIO pins (GPIO port and appropriate pin number).
** Create a list as follows: { {port number, pin mask, button ID, idle state}, {port number, pin mask, button ID, idle state}, ... } */
//#define BUTTON_ASSIGNMENT       {   {BUTTON_PORT_SK_SW3_BB_SW1  , BUTTON_PIN_SK_SW3_BB_SW1 , BUTTON_ID_SW1, StateHigh},\
//                                    {BUTTON_PORT_SK_SW4_BB_SW2  , BUTTON_PIN_SK_SW4_BB_SW2 , BUTTON_ID_SW2, StateHigh} }

 #define BUTTON_ASSIGNMENT       {   {BUTTON_PORT_SK_SW3_BB_SW1  , BUTTON_PIN_SK_SW3_BB_SW1 , BUTTON_ID_SW1, StateHigh},\
                                       {BUTTON_PORT_SK_SW4_BB_SW2  , BUTTON_PIN_SK_SW4_BB_SW2 , BUTTON_ID_SW2, StateHigh},\
                                       {BUTTON_PORT_BB_SW3         , BUTTON_PIN_BB_SW3        , BUTTON_ID_SW3, StateHigh},\
                                       {BUTTON_PORT_BB_SW4         , BUTTON_PIN_BB_SW4        , BUTTON_ID_SW4, StateHigh},\
                                       {BUTTON_PORT_BB_SW5         , BUTTON_PIN_BB_SW5        , BUTTON_ID_SW5, StateHigh} }                                    
                                    
/*****************************************************************************/
/* Global type definitions ('typedef')                                       */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source)           */
/*****************************************************************************/

/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source)             */
/*****************************************************************************/

#endif /* __BUTTON_DEFINITION_H__ */
