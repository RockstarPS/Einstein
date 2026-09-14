/*****************************************************************************
 * $Revision: 10544 $
 * $Date: 2014-09-16 10:22:04 +0200 (Tue, 16 Sep 2014) $
 *****************************************************************************/
/* __DISCLAIMER_START__                                                      */
/******************************************************************************
* Copyright (C) 2014 Spansion LLC. All Rights Reserved. 
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
/** \file main.h
 **
 ** Common project definitions
 **
 ** History:
 **   - 2014-08-07  ?.??    SWi     First version with HW specific port pin definitions
 **   - 2014-09-02  ?.??    MSt     Added Display 1 port definitions
 **   - 2014-10-18  0.23    CEy     Added LED_TOGGLE()
 *****************************************************************************/

#ifndef __MAIN_H__
#define __MAIN_H__

// File version 0xYYXX = vYY.XX
#define MAIN_H_VERSION          0x0004

#ifndef __FILE_VERSION_CHECK__

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "base_types.h"
#include "pdl.h"

/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define')                           */
/*****************************************************************************/

#define MAIN_DEVICE_AND_SAMPLE_TITLE        "TRAVEO S6J320CQXA Sample Application:\n"
#define MAIN_REQ_TOOL_STARTERKIT            " - SK-S6J320CQXA-001_S6T3J200000A000A2 \n"
#define MAIN_REQ_TOOL_MULTIIO               " - TBD\n"
#define MAIN_REQ_TOOL_CLUSTER               " - TBD\n"
#define MAIN_REQ_TOOL_DISPLAY               " - TBD\n"

#define USART_PORT                           2      ///< port number of used USART0 pins
#define USART_PIN_RX                        27      ///< pin number of used USART0 RX pin (within USART_PORT)
#define USART_PIN_TX                        25      ///< pin number of used USART0 TX pin (within USART_PORT)

#define GFX_DSP0_VPORT_A                    0
#define GFX_DSP0_VPORT_B                    5
#define GFX_DSP0_VPORT_C                    6

#define GFX_DSP0_PIN_DATA_CLOCK_OUT         18

#define GFX_DSP0_PIN_DATA_CONTROL_0         21 
#define GFX_DSP0_PIN_DATA_CONTROL_1         22 
#define GFX_DSP0_PIN_DATA_CONTROL_2         23 
#define GFX_DSP0_PIN_DATA_A0_0              27 
#define GFX_DSP0_PIN_DATA_A1_0              28 
#define GFX_DSP0_PIN_DATA_A0_1              29 
#define GFX_DSP0_PIN_DATA_A1_1              30 
#define GFX_DSP0_PIN_DATA_A0_2              31 
#define GFX_DSP0_PIN_DATA_A1_2              0

#define GFX_DSP0_PIN_DATA_A0_3              0 
#define GFX_DSP0_PIN_DATA_A1_3              1 
#define GFX_DSP0_PIN_DATA_A0_4              2 
#define GFX_DSP0_PIN_DATA_A1_4              3 
#define GFX_DSP0_PIN_DATA_A0_5              4 
#define GFX_DSP0_PIN_DATA_A1_5              5 
#define GFX_DSP0_PIN_DATA_A0_6              6 
#define GFX_DSP0_PIN_DATA_A1_6              7 
#define GFX_DSP0_PIN_DATA_A0_7              8 
#define GFX_DSP0_PIN_DATA_A1_7              9
#define GFX_DSP0_PIN_DATA_A0_8              10 
#define GFX_DSP0_PIN_DATA_A1_8              11 
#define GFX_DSP0_PIN_DATA_A0_9              12 
#define GFX_DSP0_PIN_DATA_A1_9              13 
#define GFX_DSP0_PIN_DATA_A0_10             14 
#define GFX_DSP0_PIN_DATA_A1_10             15 
#define GFX_DSP0_PIN_DATA_A0_11             16 
#define GFX_DSP0_PIN_DATA_A1_11             17 

#define GFX_DSP1_VPORT_A                    1
#define GFX_DSP1_VPORT_B                    2

#define GFX_DSP1_PIN_DATA_CLOCK_OUT         16

#define GFX_DSP1_PIN_DATA_CONTROL_0         10 
#define GFX_DSP1_PIN_DATA_CONTROL_1         11 
#define GFX_DSP1_PIN_DATA_CONTROL_2         12 

#define GFX_DSP1_PIN_DATA_A0_0              24 
#define GFX_DSP1_PIN_DATA_A1_0              25 
#define GFX_DSP1_PIN_DATA_A0_1              26 
#define GFX_DSP1_PIN_DATA_A1_1              27 
#define GFX_DSP1_PIN_DATA_A0_2              28 
#define GFX_DSP1_PIN_DATA_A1_2              29
#define GFX_DSP1_PIN_DATA_A0_3              30 
#define GFX_DSP1_PIN_DATA_A1_3              31 

#define GFX_DSP1_PIN_DATA_A0_4              0 
#define GFX_DSP1_PIN_DATA_A1_4              1 
#define GFX_DSP1_PIN_DATA_A0_5              2 
#define GFX_DSP1_PIN_DATA_A1_5              3 
#define GFX_DSP1_PIN_DATA_A0_6              4 
#define GFX_DSP1_PIN_DATA_A1_6              5 
#define GFX_DSP1_PIN_DATA_A0_7              6 
#define GFX_DSP1_PIN_DATA_A1_7              7
#define GFX_DSP1_PIN_DATA_A0_8              8 
#define GFX_DSP1_PIN_DATA_A1_8              9 
#define GFX_DSP1_PIN_DATA_A0_9              10 
#define GFX_DSP1_PIN_DATA_A1_9              11 
#define GFX_DSP1_PIN_DATA_A0_10             12 
#define GFX_DSP1_PIN_DATA_A1_10             13 
#define GFX_DSP1_PIN_DATA_A0_11             14 
#define GFX_DSP1_PIN_DATA_A1_11             15 

#define GFX_VIDEO_PORT_4                     4
#define GFX_VIDEO_PORT_5                     5

#define GFX_CAP0_PIN_DATA_0                 23
#define GFX_CAP0_PIN_DATA_1                 24
#define GFX_CAP0_PIN_DATA_2                 25
#define GFX_CAP0_PIN_DATA_3                 26
#define GFX_CAP0_PIN_DATA_4                 27
#define GFX_CAP0_PIN_DATA_5                 28
#define GFX_CAP0_PIN_DATA_6                 29
#define GFX_CAP0_PIN_DATA_7                 30
#define GFX_CAP0_PIN_DATA_8                 31
#define GFX_CAP0_PIN_DATA_9                  0

#define GFX_CAP0_PIN_DATA_10                 1
#define GFX_CAP0_PIN_DATA_11                 2
#define GFX_CAP0_PIN_DATA_12                 3
#define GFX_CAP0_PIN_DATA_13                 4
#define GFX_CAP0_PIN_DATA_14                 5
#define GFX_CAP0_PIN_DATA_15                 6
#define GFX_CAP0_PIN_DATA_16                 7
#define GFX_CAP0_PIN_DATA_17                 8
#define GFX_CAP0_PIN_DATA_18                 9
#define GFX_CAP0_PIN_DATA_19                10
#define GFX_CAP0_PIN_DATA_20                11
#define GFX_CAP0_PIN_DATA_21                12
#define GFX_CAP0_PIN_DATA_22                13
#define GFX_CAP0_PIN_DATA_23                14
#define GFX_CAP0_PIN_DATA_24                15
#define GFX_CAP0_PIN_DATA_25                16
#define GFX_CAP0_PIN_DATA_26                17
#define GFX_CAP0_PIN_DATA_27                18
#define GFX_CAP0_PIN_DATA_28                19
#define GFX_CAP0_PIN_DATA_29                20
#define GFX_CAP0_PIN_DATA_30                21
#define GFX_CAP0_PIN_DATA_31                22

#define GFX_CAP0_PIN_DATA_32                15
#define GFX_CAP0_PIN_DATA_33                16
#define GFX_CAP0_PIN_DATA_34                17
#define GFX_CAP0_PIN_DATA_35                18
#define GFX_CAP0_PIN_DATA_VLD               19
#define GFX_CAP0_PIN_DATA_CLK               20

#define LED_PORT                            3       ///< port number of used GPIO pins connected to FR5-BASE-001 LED bar
#define LED_PIN_SK_LD7_BB_LD1               13      ///< pin number of used LED1 pin (within LED_PORT) shared with LD7 on SK-AMBER-EVA. Please remove JP51 on SK, when LED on Base Board is applied. 
#define LED_PIN_SK_LD8_BB_LD2               14      ///< pin number of used LED2 pin (within LED_PORT) shared with LD8 on SK-AMBER-EVA. Please remove JP52 on SK, when LED on Base Board is applied.
#define LED_PIN_BB_LD3                      15      ///< pin number of used LED3 pin (within LED_PORT)
#define LED_PIN_BB_LD4                      16      ///< pin number of used LED4 pin (within LED_PORT)
#define LED_PIN_BB_LD5                      17      ///< pin number of used LED5 pin (within LED_PORT)
#define LED_PIN_BB_LD6                      18      ///< pin number of used LED6 pin (within LED_PORT)
#define LED_PIN_BB_LD7                      19      ///< pin number of used LED7 pin (within LED_PORT)
#define LED_PIN_BB_LD8                      20      ///< pin number of used LED8 pin (within LED_PORT)
#define LED_COUNT                           8       ///< number of total LEDs in LED bar

#define DDRHSSPI0_PORT_0                    0
#define DDRHSSPI0_PORT_1                    1
#define DDRHSSPI0_PIN_SSEL                  0 
#define DDRHSSPI0_PIN_SCLK                  29
#define DDRHSSPI0_PIN_SDATA0                2 
#define DDRHSSPI0_PIN_SDATA1                30
#define DDRHSSPI0_PIN_SDATA2                31
#define DDRHSSPI0_PIN_SDATA3                1 
/** Macro to switch on a LED*/
#define LED_ON( u8Led )       Port_SetPortPinLevel(LED_PORT, u8Led, PortGpioHigh)
/** Macro to switch off a LED*/
#define LED_OFF( u8Led )      Port_SetPortPinLevel(LED_PORT, u8Led, PortGpioLow)
/** Macro to toggle a LED*/
#define LED_TOGGLE( u8Led )   Port_TogglePortPin(LED_PORT, u8Led)

/*****************************************************************************/
/* Global type definitions ('typedef')                                       */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source)           */
/*****************************************************************************/

/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source)             */
/*****************************************************************************/

#endif /* __FILE_VERSION_CHECK__ */
#endif /* __MAIN_H__ */

