/******************************************************************************
 * $Revision: 10547 $
 * $Date: 2014-09-22 09:49:09 +0200 (Mon, 22 Sep 2014) $
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
/** \file main.c
 **
 ** Application entry code.
 **
 ** History:
 **   - 2014-08-07  ?.??  SWi  Initial version 
 **   - 2014-08-25  ?.??  MSt  Added MPU for GFX register access
 **   - 2014-09-02  ?.??  MSt  Added port configuration for GFX1 interface
 **   - 2014-09-17  ?.??  CEy  some clean-ups
 **   - 2014-09-22  ?.??  SWi  Definition of input resources fixed
 **   - 2014-10-17  0.23  CEy  Clean-up main.c (moved functions to drivers)
 *****************************************************************************/

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "base_types.h"
#include "main.h"
#include "mcu_settings.h"
#include "start.h"
#include "abstract.h"
#include "pdl.h"
#include "semihosting\semihosting.h"
#include "display\display.h"
#include "timer\timer.h"
#include "button\button.h"
#include "button_definition.h"

#include "ui_presentation.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/
static void ButtonCallback(uint16_t u16ButtonId, en_button_state_t enState);

/*****************************************************************************/
/* Global variable definitions (declared in header file with 'extern')       */
/*****************************************************************************/
#ifdef __DEBUG_CODE_IN_SYSRAM
    #define SYSRAM_ECC_CLEAR_SIZE_BYTE  0
#else
    #define SYSRAM_ECC_CLEAR_SIZE_BYTE  SYSRAM_SIZE_BYTE
#endif
#ifdef __DEBUG_CODE_IN_TCMRAM
    #define TCMRAM_ECC_CLEAR_SIZE_BYTE  0
#else
    #define TCMRAM_ECC_CLEAR_SIZE_BYTE  TCMRAM_SIZE_BYTE
#endif

const   stc_clear_ecc_memories_t    Start_stcClearEccMemories   ={  
    /*.u32TcmRamStartAddress  =   */ TCMRAM_AXI_START_ADDRESS,
    /*.u32TcmRamSizeByte      =   */ TCMRAM_ECC_CLEAR_SIZE_BYTE,
    /*.u32SysRamStartAddress  =   */ SYSRAM_START_ADDRESS,
    /*.u32SysRamSizeByte      =   */ SYSRAM_ECC_CLEAR_SIZE_BYTE,
    /*.u32BuRamStartAddress   =   */ BURAM_START_ADDRESS,
    /*.u32BuRamSizeByte       =   */ BURAM_SIZE_BYTE,
    /*.u32EthRamStartAddress  =   */ 0,
    /*.u32EthRamSizeByte      =   */ 0,
    /*.u32VRamStartAddress    =   */ 0,
    /*.u32VRamSizeByte        =   */ 0
};

/*****************************************************************************/
/* Local type definitions ('typedef')                                        */
/*****************************************************************************/
/*typedef struct stc_port_pin_set
{
    uint8_t u8PortIndex;
    uint8_t u8PinNumber;
    stc_port_pin_config_t stcPortPinConfig;
} stc_port_pin_set_t;

typedef struct stc_input_resource_set
{
    uint8_t u8Index;
    en_port_input_port_t   enInputPort;
    en_port_input_source_t enInputSource;
} stc_input_resource_set_t;
*/
/*****************************************************************************/
/* Local function prototypes ('static')                                      */
/*****************************************************************************/
en_result_t Port_ConfigurePortPins(const stc_port_pin_set_t astcPortPins[], uint32_t u32Count);
//en_result_t Resource_ConfigureInputResources(const stc_input_resource_set_t astcInputResources[], uint32_t u32Count);
//en_result_t Set_Mpu(void);

/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/

/* Definition of all required MCU pins */
static const stc_port_pin_set_t m_astcPortPins[] = {
    { USART_PORT               , USART_PIN_RX               , { PortOutputResourceGPIO, PortOutputDriveA, PortPullResistorNone, PortInputLevelCmosA, TRUE,  FALSE, PortGpioInput,  PortGpioHigh } },  // USART0_RX
    { USART_PORT               , USART_PIN_TX               , { PortOutputResourceD   , PortOutputDriveA, PortPullResistorNone, PortInputLevelCmosA, FALSE, FALSE, PortGpioOutput, PortGpioHigh } },  // USART0_TX
    { BUTTON_PORT_SK_SW3_BB_SW1, BUTTON_PIN_SK_SW3_BB_SW1   , { PortOutputResourceGPIO, PortOutputDriveA, PortPullResistorNone, PortInputLevelCmosA, TRUE,  FALSE, PortGpioInput,  PortGpioHigh } },   // BUTTON SW1 on Base Board, shared with SK SW3
    { BUTTON_PORT_SK_SW4_BB_SW2, BUTTON_PIN_SK_SW4_BB_SW2   , { PortOutputResourceGPIO, PortOutputDriveA, PortPullResistorNone, PortInputLevelCmosA, TRUE,  FALSE, PortGpioInput,  PortGpioHigh } },  // BUTTON SW2 on Base Board, shared with SK SW4
    { BUTTON_PORT_BB_SW3       , BUTTON_PIN_BB_SW3          , { PortOutputResourceGPIO, PortOutputDriveA, PortPullResistorNone, PortInputLevelCmosA, TRUE,  FALSE, PortGpioInput,  PortGpioHigh } },   // BUTTON SW3 on Base Board
    { BUTTON_PORT_BB_SW4       , BUTTON_PIN_BB_SW4          , { PortOutputResourceGPIO, PortOutputDriveA, PortPullResistorNone, PortInputLevelCmosA, TRUE,  FALSE, PortGpioInput,  PortGpioHigh } },   // BUTTON SW4 on Base Board
    { BUTTON_PORT_BB_SW5       , BUTTON_PIN_BB_SW5          , { PortOutputResourceGPIO, PortOutputDriveA, PortPullResistorNone, PortInputLevelCmosA, TRUE,  FALSE, PortGpioInput,  PortGpioHigh } },   // BUTTON SW5 on Base Board
    { LED_PORT                 , LED_PIN_SK_LD7_BB_LD1      , { PortOutputResourceGPIO, PortOutputDriveA, PortPullResistorNone, PortInputLevelCmosA, TRUE,  FALSE, PortGpioOutput, PortGpioLow } },    // Base Board LED LD1, shared with SK LD7
    { LED_PORT                 , LED_PIN_SK_LD8_BB_LD2      , { PortOutputResourceGPIO, PortOutputDriveA, PortPullResistorNone, PortInputLevelCmosA, TRUE,  FALSE, PortGpioOutput, PortGpioLow } },    // Base Board LED LD2, shared with SK LD8
 // { LED_PORT                 , LED_PIN_BB_LD3             , { PortOutputResourceGPIO, PortOutputDriveA, PortPullResistorNone, PortInputLevelCmosA, TRUE,  FALSE, PortGpioOutput, PortGpioLow } },    // Base Board LED LD3
 // { LED_PORT                 , LED_PIN_BB_LD4             , { PortOutputResourceGPIO, PortOutputDriveA, PortPullResistorNone, PortInputLevelCmosA, TRUE,  FALSE, PortGpioOutput, PortGpioLow } },    // Base Board LED LD4
 // { LED_PORT                 , LED_PIN_BB_LD5             , { PortOutputResourceGPIO, PortOutputDriveA, PortPullResistorNone, PortInputLevelCmosA, TRUE,  FALSE, PortGpioOutput, PortGpioLow } },    // Base Board LED LD5
 // { LED_PORT                 , LED_PIN_BB_LD6             , { PortOutputResourceGPIO, PortOutputDriveA, PortPullResistorNone, PortInputLevelCmosA, TRUE,  FALSE, PortGpioOutput, PortGpioLow } },    // Base Board LED LD6
 // { LED_PORT                 , LED_PIN_BB_LD7             , { PortOutputResourceGPIO, PortOutputDriveA, PortPullResistorNone, PortInputLevelCmosA, TRUE,  FALSE, PortGpioOutput, PortGpioLow } },    // Base Board LED LD7
 // { LED_PORT                 , LED_PIN_BB_LD8             , { PortOutputResourceGPIO, PortOutputDriveA, PortPullResistorNone, PortInputLevelCmosA, TRUE,  FALSE, PortGpioOutput, PortGpioLow } },    // Base Board LED LD8
    { GFX_DSP0_VPORT_A         , GFX_DSP0_PIN_DATA_CLOCK_OUT, { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // GFX0_RGB_CLK
    { GFX_DSP0_VPORT_B         , GFX_DSP0_PIN_DATA_CONTROL_0, { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_HYSNC
    { GFX_DSP0_VPORT_B         , GFX_DSP0_PIN_DATA_CONTROL_1, { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_VSYNC
    { GFX_DSP0_VPORT_B         , GFX_DSP0_PIN_DATA_CONTROL_2, { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_DE
    { GFX_DSP0_VPORT_B         , GFX_DSP0_PIN_DATA_A0_0     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_R0
    { GFX_DSP0_VPORT_B         , GFX_DSP0_PIN_DATA_A1_0     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_R1
    { GFX_DSP0_VPORT_B         , GFX_DSP0_PIN_DATA_A0_1     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_R2
    { GFX_DSP0_VPORT_B         , GFX_DSP0_PIN_DATA_A1_1     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_R3
    { GFX_DSP0_VPORT_B         , GFX_DSP0_PIN_DATA_A0_2     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_R4    
    { GFX_DSP0_VPORT_C         , GFX_DSP0_PIN_DATA_A1_2     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_R5
    { GFX_DSP0_VPORT_A         , GFX_DSP0_PIN_DATA_A0_3     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_R6
    { GFX_DSP0_VPORT_A         , GFX_DSP0_PIN_DATA_A1_3     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_R7
    { GFX_DSP0_VPORT_A         , GFX_DSP0_PIN_DATA_A0_4     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_G0
    { GFX_DSP0_VPORT_A         , GFX_DSP0_PIN_DATA_A1_4     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_G1
    { GFX_DSP0_VPORT_A         , GFX_DSP0_PIN_DATA_A0_5     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_G2
    { GFX_DSP0_VPORT_A         , GFX_DSP0_PIN_DATA_A1_5     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_G3
    { GFX_DSP0_VPORT_A         , GFX_DSP0_PIN_DATA_A0_6     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_G4
    { GFX_DSP0_VPORT_A         , GFX_DSP0_PIN_DATA_A1_6     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_G5
    { GFX_DSP0_VPORT_A         , GFX_DSP0_PIN_DATA_A0_7     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_G6
    { GFX_DSP0_VPORT_A         , GFX_DSP0_PIN_DATA_A1_7     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_G7
    { GFX_DSP0_VPORT_A         , GFX_DSP0_PIN_DATA_A0_8     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_B0
    { GFX_DSP0_VPORT_A         , GFX_DSP0_PIN_DATA_A1_8     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_B1
    { GFX_DSP0_VPORT_A         , GFX_DSP0_PIN_DATA_A0_9     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_B2
    { GFX_DSP0_VPORT_A         , GFX_DSP0_PIN_DATA_A1_9     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_B3
    { GFX_DSP0_VPORT_A         , GFX_DSP0_PIN_DATA_A0_10    , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_B4
    { GFX_DSP0_VPORT_A         , GFX_DSP0_PIN_DATA_A1_10    , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_B5
    { GFX_DSP0_VPORT_A         , GFX_DSP0_PIN_DATA_A0_11    , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_B6
    { GFX_DSP0_VPORT_A         , GFX_DSP0_PIN_DATA_A1_11    , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP0_B7
    { GFX_DSP1_VPORT_A         , GFX_DSP1_PIN_DATA_CLOCK_OUT, { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // GFX1_RGB_CLK    
    { GFX_DSP1_VPORT_A         , GFX_DSP1_PIN_DATA_CONTROL_0, { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_HYSNC       
    { GFX_DSP1_VPORT_A         , GFX_DSP1_PIN_DATA_CONTROL_1, { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_VSYNC    
    { GFX_DSP1_VPORT_A         , GFX_DSP1_PIN_DATA_CONTROL_2, { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_DE           
    { GFX_DSP1_VPORT_A         , GFX_DSP1_PIN_DATA_A0_0     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_R0       
    { GFX_DSP1_VPORT_A         , GFX_DSP1_PIN_DATA_A1_0     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_R1       
    { GFX_DSP1_VPORT_A         , GFX_DSP1_PIN_DATA_A0_1     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_R2       
    { GFX_DSP1_VPORT_A         , GFX_DSP1_PIN_DATA_A1_1     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_R3       
    { GFX_DSP1_VPORT_A         , GFX_DSP1_PIN_DATA_A0_2     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_R4                                                                                                                                                                                                                                                                                                                                                                                                                                             
    { GFX_DSP1_VPORT_A         , GFX_DSP1_PIN_DATA_A1_2     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_R5                                                                                                                                                                                                                                                                                                                                                                                                                                               
    { GFX_DSP1_VPORT_A         , GFX_DSP1_PIN_DATA_A0_3     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_R6       
    { GFX_DSP1_VPORT_A         , GFX_DSP1_PIN_DATA_A1_3     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_R7       
    { GFX_DSP1_VPORT_B         , GFX_DSP1_PIN_DATA_A0_4     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_G0       
    { GFX_DSP1_VPORT_B         , GFX_DSP1_PIN_DATA_A1_4     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_G1       
    { GFX_DSP1_VPORT_B         , GFX_DSP1_PIN_DATA_A0_5     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_G2       
    { GFX_DSP1_VPORT_B         , GFX_DSP1_PIN_DATA_A1_5     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_G3       
    { GFX_DSP1_VPORT_B         , GFX_DSP1_PIN_DATA_A0_6     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_G4       
    { GFX_DSP1_VPORT_B         , GFX_DSP1_PIN_DATA_A1_6     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_G5       
    { GFX_DSP1_VPORT_B         , GFX_DSP1_PIN_DATA_A0_7     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_G6       
    { GFX_DSP1_VPORT_B         , GFX_DSP1_PIN_DATA_A1_7     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_G7       
    { GFX_DSP1_VPORT_B         , GFX_DSP1_PIN_DATA_A0_8     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_B0       
    { GFX_DSP1_VPORT_B         , GFX_DSP1_PIN_DATA_A1_8     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_B1       
    { GFX_DSP1_VPORT_B         , GFX_DSP1_PIN_DATA_A0_9     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_B2       
    { GFX_DSP1_VPORT_B         , GFX_DSP1_PIN_DATA_A1_9     , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_B3       
    { GFX_DSP1_VPORT_B         , GFX_DSP1_PIN_DATA_A0_10    , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_B4       
    { GFX_DSP1_VPORT_B         , GFX_DSP1_PIN_DATA_A1_10    , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_B5       
    { GFX_DSP1_VPORT_B         , GFX_DSP1_PIN_DATA_A0_11    , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_B6       
    { GFX_DSP1_VPORT_B         , GFX_DSP1_PIN_DATA_A1_11    , { PortOutputResourceB   , PortOutputDriveD, PortPullResistorNone, PortInputLevelCmosA, FALSE,  FALSE, PortGpioOutput, PortGpioLow } },      // DISP1_B7           
/* HSSPI-CPU
Port0_29-->SCK
Port1_0-->CS
Port1_1-->Data0
Port0_31-->Data1
Port0_30-->Data2
Port1_2-->Data3
*/
#if 0    
    { 1,  0, { PortOutputResourceB,  PortOutputDriveD,  PortPullResistorNone,  PortInputLevelCmosA,  FALSE, FALSE,  PortGpioOutput, PortGpioLow  } },   // HSSPI0-MCU_SS (/CE)
    { 0, 29, { PortOutputResourceB,  PortOutputDriveD,  PortPullResistorNone,  PortInputLevelCmosA,  FALSE, FALSE,  PortGpioOutput, PortGpioLow  } },   // HSSPI0-MCU_CLK (SCK)
    { 1,  2, { PortOutputResourceB,  PortOutputDriveD,  PortPullResistorNone,  PortInputLevelCmosA,  TRUE,  FALSE,  PortGpioInput,  PortGpioLow  } },   // HSSPI0-MCU_DATA3 (SIO3)
    { 0, 30, { PortOutputResourceB,  PortOutputDriveD,  PortPullResistorNone,  PortInputLevelCmosA,  TRUE,  FALSE,  PortGpioInput,  PortGpioLow  } },   // HSSPI0-MCU_DATA2 (SIO2)
    { 1, 31, { PortOutputResourceB,  PortOutputDriveD,  PortPullResistorNone,  PortInputLevelCmosA,  TRUE,  FALSE,  PortGpioInput,  PortGpioLow  } },   // HSSPI0-MCU_DATA1 (SIO1)
    { 1, 1,  { PortOutputResourceB,  PortOutputDriveD,  PortPullResistorNone,  PortInputLevelCmosA,  TRUE,  FALSE,  PortGpioInput,  PortGpioLow  } },   // HSSPI0-MCU_DATA0 (SIO0)
#endif
    { .u8PortIndex = DDRHSSPI0_PORT_1           , .u8PinNumber = DDRHSSPI0_PIN_SSEL         , .stcPortPinConfig = { .enOutputFunction = PortOutputResourceB ,   .enOutputDrive = PortOutputDriveB, .enPullResistor = PortPullResistorNone, .enInputLevel = PortInputLevelCmosA, .bInputEnable = FALSE, .bNoiseFilterEnable = FALSE, .enGpioDirection = PortGpioInput, } },   // HSSPI0_SS (/CE)
    { .u8PortIndex = DDRHSSPI0_PORT_0           , .u8PinNumber = DDRHSSPI0_PIN_SCLK         , .stcPortPinConfig = { .enOutputFunction = PortOutputResourceB ,   .enOutputDrive = PortOutputDriveB, .enPullResistor = PortPullResistorNone, .enInputLevel = PortInputLevelCmosA, .bInputEnable = FALSE, .bNoiseFilterEnable = FALSE, .enGpioDirection = PortGpioInput, } },   // HSSPI0_CLK (SCK)
    { .u8PortIndex = DDRHSSPI0_PORT_1           , .u8PinNumber = DDRHSSPI0_PIN_SDATA0       , .stcPortPinConfig = { .enOutputFunction = PortOutputResourceB ,   .enOutputDrive = PortOutputDriveB, .enPullResistor = PortPullResistorUp  , .enInputLevel = PortInputLevelCmosA, .bInputEnable = TRUE , .bNoiseFilterEnable = FALSE, .enGpioDirection = PortGpioInput, } },   // HSSPI0_DATA3 (SIO3)
    { .u8PortIndex = DDRHSSPI0_PORT_0           , .u8PinNumber = DDRHSSPI0_PIN_SDATA1       , .stcPortPinConfig = { .enOutputFunction = PortOutputResourceB ,   .enOutputDrive = PortOutputDriveB, .enPullResistor = PortPullResistorUp  , .enInputLevel = PortInputLevelCmosA, .bInputEnable = TRUE , .bNoiseFilterEnable = FALSE, .enGpioDirection = PortGpioInput, } },   // HSSPI0_DATA2 (SIO2)
    { .u8PortIndex = DDRHSSPI0_PORT_0           , .u8PinNumber = DDRHSSPI0_PIN_SDATA2       , .stcPortPinConfig = { .enOutputFunction = PortOutputResourceB ,   .enOutputDrive = PortOutputDriveB, .enPullResistor = PortPullResistorNone, .enInputLevel = PortInputLevelCmosA, .bInputEnable = TRUE , .bNoiseFilterEnable = FALSE, .enGpioDirection = PortGpioInput, } },   // HSSPI0_DATA1 (SIO1 / MISO)
    { .u8PortIndex = DDRHSSPI0_PORT_1           , .u8PinNumber = DDRHSSPI0_PIN_SDATA3       , .stcPortPinConfig = { .enOutputFunction = PortOutputResourceB ,   .enOutputDrive = PortOutputDriveB, .enPullResistor = PortPullResistorUp  , .enInputLevel = PortInputLevelCmosA, .bInputEnable = TRUE , .bNoiseFilterEnable = FALSE, .enGpioDirection = PortGpioInput, } },    // HSSPI0_DATA0 (SIO0 / MOSI)
/*
HSSPI-GFX
Port1_9-->SCK
Port1_6-->CS
Port1_7-->Data0
Port0_5-->Data1
Port0_4-->Data2
Port1_8-->Data3

*/    
    { 1, 6, { PortOutputResourceB,  PortOutputDriveD,  PortPullResistorNone,  PortInputLevelCmosA,  FALSE, FALSE,  PortGpioOutput, PortGpioLow  } }, // HSSPI0-GFX_SS (/CE)
    { 1, 9, { PortOutputResourceB,  PortOutputDriveD,  PortPullResistorNone,  PortInputLevelCmosA,  FALSE, FALSE,  PortGpioOutput, PortGpioLow  } }, // HSSPI0-GFX_CLK (SCK)
    { 1, 8, { PortOutputResourceB,  PortOutputDriveD,  PortPullResistorNone,  PortInputLevelCmosA,  TRUE,  FALSE,  PortGpioInput,  PortGpioLow  } }, // HSSPI0-GFX_DATA3 (SIO3)
    { 0, 4, { PortOutputResourceB,  PortOutputDriveD,  PortPullResistorNone,  PortInputLevelCmosA,  TRUE,  FALSE,  PortGpioInput,  PortGpioLow  } }, // HSSPI0-GFX_DATA2 (SIO2)
    { 0, 5, { PortOutputResourceB,  PortOutputDriveD,  PortPullResistorNone,  PortInputLevelCmosA,  TRUE,  FALSE,  PortGpioInput,  PortGpioLow  } }, // HSSPI0-GFX_DATA1 (SIO1)
    { 1, 7, { PortOutputResourceB,  PortOutputDriveD,  PortPullResistorNone,  PortInputLevelCmosA,  TRUE,  FALSE,  PortGpioInput,  PortGpioLow  } }, // HSSPI0-GFX_DATA0 (SIO0)
};


/* Definition of all required input resources  */
static const stc_input_resource_set_t m_astcInputResources[] = {
    { 0, PortInputPortE, PortInputSourceA } // USART0_RX
};

static unsigned int l_gt_req=0;
/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/

/*****************************************************************************
 ** \brief Application entry code
 ** 
 ** \e main() is called by the startup routines after each reset.
 **
 ** \pre The system has been initialized to a default setting and C-code
 ** can be executed.
 **
 ** \note \e Start_Init() should be called at the beginning of \e main()
 ** to finish initialization to default settings.
 **
 ** \post The application has finished and the system will be halted.
 *****************************************************************************/
int main(void)
{
    // Finalize initialization to default settings.
    // (this will do IRQ and NMI initialization and global IRQ/NMI enable)
    Start_Init();

    // Configure all requires port pins
    Port_ConfigurePortPins(m_astcPortPins, DIM(m_astcPortPins));
                
    // Configure all internal and external input signal connections and special signals
    Port_ConfigureInputResources(m_astcInputResources, DIM(m_astcInputResources));
    
    // Initialze timer module (can be used with timer IDs defined in timer.h)
    Timer_Init();
    
    // Initlialize button module (events provided in callback function ButtonCallback)
    Button_Init(&ButtonCallback);

    // Initialize semihosting for low level file I/O redirecting to USART0
    // (for printf() and scanf() usage)
    Semihosting_Init(&CPG_MFS00_UART, 115200);
    
    printf("\n"                                                           );
    printf("===========================================================\n");
    printf("Spansion LLC\n"                                               );
    printf(MAIN_DEVICE_AND_SAMPLE_TITLE                                   );
    printf("traveo_sample_template_S6J320CQX\n"                           );
    printf(" "                                                            );
    printf("\n"                                                           );
    printf("Required HW tools:\n"                                         );
    printf(MAIN_REQ_TOOL_STARTERKIT                                       );
    printf(MAIN_REQ_TOOL_MULTIIO                                          );
    printf(MAIN_REQ_TOOL_CLUSTER                                          );
    printf(MAIN_REQ_TOOL_DISPLAY                                          );
    printf("-----------------------------------------------------------\n");
    printf("See Spansion disclaimer for FOC SW before using this SW!   \n");
    printf("===========================================================\n");
 
    // enable CPU MPU for Gfx register access
    Mem_SetGfxRegsAsDeviceMem();
    hmi_lsh_initialize(1);
    hmi_gfx_mgr02_if_KSColdInit();
    hmi_gfx_mgr02_if_start();
   

    // Draw something.
    Timer_Start(TIMER_ID_KSTIMED_TASK,200, TRUE, hmi_gfx_mgr02_if_KSTimedTask);
    Timer_Start(TIMER_ID_PRESENTATION_TASK,200, TRUE, hmi_gfx_anim_engine_tick);

    //(void)LSH_ADD_STATE(GFX_TEST_SCREEN, 255);
    (void)LSH_ADD_STATE(GFX_SCR_ECOPEDAL_MENU, 255);

    printf("Wait until the Down button is pressed.\n");
    for (;;)
    {
        // Maintain Watchdog
        PDL_WAIT_LOOP_HOOK();
        // Timer function must be called cyclically to use callback functions
        Timer_Main();
	    if(l_gt_req !=0)
	    {
	       l_gt_req =0;
	       Graphics_Task();
	       Graphics_Task_Done();
	   }
    }
    printf("\nTerminated.\n");


#ifndef WIN32
    // Endless loop
    for (;;)
    {
        // Maintain Watchdog
        PDL_WAIT_LOOP_HOOK();    
    }
#endif /* WIN32 */
} // main

/*****************************************************************************
 ** \brief Callback function to handle button events.
 **
 ** \param u16ButtonId  ID of button that changed its state (BUTTON_ID_???)
 ** \param enState      new state of button
 **
 ** \return none
 *****************************************************************************/
static void ButtonCallback(uint16_t u16ButtonId, en_button_state_t enState)
{
     // Return if button was released only
     if (enState == StateHigh)
     {
         return;
     }
     
     // Handle the pressed button
     switch (u16ButtonId)
     {
         case BUTTON_ID_SW1:  
            LED_ON( LED_PIN_SK_LD7_BB_LD1 );
            LED_OFF( LED_PIN_SK_LD8_BB_LD2 );
            break;
             
         case BUTTON_ID_SW2:
            LED_OFF( LED_PIN_SK_LD7_BB_LD1 );
            LED_ON( LED_PIN_SK_LD8_BB_LD2 );
            break;
 
         case BUTTON_ID_SW3: // (only, when Base Board available)            
            break;
             
         case BUTTON_ID_SW4: // (only, when Base Board available)          
            break;         
             
         case BUTTON_ID_SW5: // (only, when Base Board available)
            break;
 
         default:
            break;
     }
}
#if 0
/**
 *****************************************************************************
 ** \brief Set Port Pin configuration
 **
 ** All Pins are access protected by single bits for each channel.
 ** Thus ensure protection against unwanted access by software. If Port Poin
 ** Enable is not set, an error (exception) is raised.
 **
 ** This function sets the Port Pin enable bits for each port pin given by the
 ** mask value and set the configuration
 **
 ** \pre Must be in privileged mode
 **
 ** \param [in]  astcPortPins[]     Struct with the individual settings
 **                                 for each Port Pin
 **
 ** \param [in]  u32Count           dimension of the astcPortPins[]
 *
 ** \retval Ok                      Set of Pin enable bits was successful
 ** \retval ErrorAccessRights If following conditions is met:
 **             - API is not in privileged mode.
 ** \retval ErrorInvalidParameter If one of the following conditions are met:
 **             - u32Count == 0 (no port pin to configure)
 *****************************************************************************/
en_result_t Port_ConfigurePortPins(const stc_port_pin_set_t astcPortPins[], uint32_t u32Count)
{
    uint32_t u32Index = 0;
    en_result_t enCheck = Ok;

    //  Check number of port pins to configure
    if (u32Count == 0)
    {
      return ErrorInvalidParameter;
    }

    // Walk through port pin list to configure  pins
    for (u32Index = 0; u32Index < u32Count; u32Index++)
    {
        // If port number is in valid range
        if (astcPortPins[u32Index].u8PortIndex < MCU_MAX_PORT_COUNT)
        {
            // If pin number is in valid range
            if (astcPortPins[u32Index].u8PinNumber < MCU_MAX_PORT_PIN_COUNT)
            {
                uint8_t u8Port = astcPortPins[u32Index].u8PortIndex;
                uint8_t u8Pin  = astcPortPins[u32Index].u8PinNumber;
                const stc_port_pin_set_t* pstcPortPinSet = &astcPortPins[u32Index];

                // Set port pin configuration
                enCheck = Port_SetPinConfig(u8Port, u8Pin, &pstcPortPinSet->stcPortPinConfig);
                if (enCheck != Ok)
                {
                    return enCheck;
                }
            }
        }
    }
    return Ok;
} // Port_ConfigurePortPins

/**
 *****************************************************************************
 ** \brief Set Port Pin input matrix
 **
 ** \param [in]  astcResources[]    Struct with the pointer to
 **                                 RICFG.un???.stcField register and the
 **                                 Parameters to set the input matrix
 **
 ** \param [in]  u32Count           size of the astcResources[]
 **
 ** \retval Ok                      Set of Pin enable bits was successful
 **
 ** \retval ErrorInvalidParameter If one of the following conditions are met:
 **             - u32Count out of range (0 .. MCU_MAX_PORT_COUNT-1)
 *****************************************************************************/
en_result_t Resource_ConfigureInputResources(const stc_input_resource_set_t astcInputResources[], uint32_t u32Count)
{
    uint32_t u32Index = 0;
    
    if (u32Count == 0)
    {
      return ErrorInvalidParameter;
    }
    
    // Walk through resources list
    for (u32Index = 0; u32Index < u32Count; u32Index++)
    {
    
        // Create parameters
        uint8_t u8Index = astcInputResources[u32Index].u8Index;
        en_port_input_port_t   enInputPort   = astcInputResources[u32Index].enInputPort;
        en_port_input_source_t enInputSource = astcInputResources[u32Index].enInputSource;

        // Set configuration register
        Port_SelectInputPort  (u8Index, enInputPort);
        Port_SelectInputSource(u8Index, enInputSource);
    }

    // Enable all now configured input ports
    Port_EnableInput();
    return Ok;
}

/**
 *****************************************************************************
 ** \brief Set CPU MPU for Graphic register access
 **
 ** \param [in]  none
 **
 ** \retval Ok                      Set of MPU configuration successfully done.
 ** \retval ErrorAccessRights       Function was not called in privileged (system) mode.
 ** \retval ErrorInvalidParameter   pstcConfig == NULL or invalid memory type.
 *****************************************************************************/
en_result_t Set_Mpu(void)
    {
#ifndef WIN32
    stc_mem_mpu_config_t stcMpuConfig;
    memset(&stcMpuConfig, 0, sizeof(stcMpuConfig));     // clear whole structure to zero (important to disable all regions by default!)
    
    stcMpuConfig.bEnableMpu              = TRUE;        // Enable MPU
    stcMpuConfig.bEnableBackgroundRegion = TRUE;        // Enable MPU background region (enable default memory map
                                                        // for all addresses not configured in regions)
	
	// Region 1
    stcMpuConfig.astcRegion[1].bEnable            = TRUE;                               // Enable memory region 0
    stcMpuConfig.astcRegion[1].enAccessPermission = MemMpuRWPRWNP;                      // Read and write possible in privileged and non privileged mode
    stcMpuConfig.astcRegion[1].u32StartAddress    = 0x50200000u;                        // Region start address = non-cacheable area buffer
    stcMpuConfig.astcRegion[1].enRegionSize       = MemMpuRegionSize2MB;                // Region size (buffer size)
    stcMpuConfig.astcRegion[1].stcRegionAttributes.enMainMemAttribute = MemMpuRegionMainAttribDeviceNonShareable;   // device memory type
    stcMpuConfig.astcRegion[1].stcRegionAttributes.enShareAttribute   = MemMpuRegionShareAttribNonShareable;        // Non-shareable
    
    return Mem_SetMpuConfig (&stcMpuConfig);  
#else 
    return Ok;
#endif
    }
#endif
void KernelTriggerGraphicsTask(void)
{
    l_gt_req =1;
}
