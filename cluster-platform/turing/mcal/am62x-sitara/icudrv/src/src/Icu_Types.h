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
*  File Name         :  Icu_Types.h                                          *
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

#ifndef ICU_TYPES_H
#define ICU_TYPES_H

#include "Std_Types.h"
#include <hw_include/cslr_soc.h>

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/* Maximum number of banks per instance/module */
#define GPIO_MAX_BANKS                  (9U)
/* Maximum number of pins per bank */
#define GPIO_MAX_PIN_PER_BANK           (16U)
/* Maximum number of pins per instance/module */
#define GPIO_MAX_PIN_PER_INSTANCE       (GPIO_MAX_BANKS * GPIO_MAX_PIN_PER_BANK)

/* Number of banks per register */
#define GPIO_BANKS_PER_REG              (2U)
/* Number of pins per register - 32 pins */
#define GPIO_PINS_PER_REG               (GPIO_BANKS_PER_REG * GPIO_MAX_PIN_PER_BANK)

/* Number of pins per register - shift value - used instead of divide operator */
#define GPIO_PINS_PER_REG_SHIFT         (5U)
/* Number of pins per bank - shift value - used instead of divide operator */
#define GPIO_PINS_PER_BANK_SHIFT        (4U)

/* Returns the bank index based on pin number */
#define GPIO_GET_BANK_INDEX(pinNum)     (((uint32) pinNum) >> GPIO_PINS_PER_BANK_SHIFT)
/* Returns the register index based on pin number */
#define GPIO_GET_REG_INDEX(pinNum)      (((uint32) pinNum) >> GPIO_PINS_PER_REG_SHIFT)
/* Returns the bit position within a register based on pin number */
#define GPIO_GET_BIT_POS(pinNum)        (pinNum - ((GPIO_GET_REG_INDEX(pinNum)) << GPIO_PINS_PER_REG_SHIFT)) // 42-32 = 10
/* Returns the bit mask within a register based on pin number */
#define GPIO_GET_BIT_MASK(pinNum)       (((uint32) 1U) << GPIO_GET_BIT_POS(pinNum))
/* Returns the bit position within a bank based on pin number */
#define GPIO_GET_BANK_BIT_POS(pinNum)   (pinNum - ((GPIO_GET_BANK_INDEX(pinNum)) << GPIO_PINS_PER_BANK_SHIFT))
/* Returns the bit mask within a bank based on pin number */
#define GPIO_GET_BANK_BIT_MASK(pinNum)  (((uint32) 1U) << GPIO_GET_BANK_BIT_POS(pinNum))


/*------------------[Service identifiers]-----------------------------------*/

/* Definition of the service identifier of Icu_Init. */
#define ICU_API_INIT                      ((uint8) 0x00U)
/* Definition of the service identifier of Icu_DeInit. */
#define ICU_API_DE_INIT                   ((uint8) 0x01U)
/* Definition of the service identifier of Icu_DisableNotification. */
#define ICU_API_DISABLE_NOTIFICATION      ((uint8) 0x06U)
/* Definition of the service identifier of Icu_EnableNotification. */
#define ICU_API_ENABLE_NOTIFICATION       ((uint8) 0x07U)

/*------------------[Development errors]------------------------------------*/

/* API service used with an invalid channel identifier or channel
   was not configured for the functionality of the calling API. */
#define ICU_E_PARAM_CHANNEL               ((uint8) 0x0BU)
/* Init function failed with an invalid configuration pointer. */
#define ICU_E_INIT_FAILED                 ((uint8) 0x0DU)
/* API service used without module initialization. */
#define ICU_E_UNINIT                      ((uint8) 0x14U)
/* API service Icu_Init is called when driver state is already initialized. */
#define ICU_E_ALREADY_INITIALIZED         ((uint8) 0x17U)

/* Icu Driver Module ID */
#define ICU_MODULE_ID 122U
/* Icu Driver Instance ID */
#define ICU_INSTANCE_ID 0u


/* WKUP_MCU GPIO interrupt router outputs */
#define WKUP_MCU_GPIOMUX_INTROUTER0_OUTP_6                                                          (6U)
#define WKUP_MCU_GPIOMUX_INTROUTER0_OUTP_7                                                          (7U)

/* MAIN GPIO interrupt router outputs */
#define MAIN_GPIOMUX_INTROUTER0_OUTP_34                                                             (34U)
#define MAIN_GPIOMUX_INTROUTER0_OUTP_35                                                             (35U)

#define NO_OF_MCU_GPIOBANKS                                                                         (2U)
#define NO_OF_MAIN0_GPIOBANKS                                                                       (6U)
#define NO_OF_MAIN1_GPIOBANKS                                                                       (6U)
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/* Channel identifier type for ICU channels */
typedef uint8 Icu_ChannelType;

/* Definition of the measurement mode type. */
typedef enum
{
  /* Mode for detecting signal edges. */
  ICU_MODE_SIGNAL_EDGE_DETECT = 1,
  /* Mode for measuring different times between various configurable edges. */
  ICU_MODE_SIGNAL_MEASUREMENT,
  /* Mode for capturing timer values on edges. */
  ICU_MODE_TIMESTAMP,
  /* Mode for counting edges. */
  ICU_MODE_EDGE_COUNTER
} Icu_MeasurementModeType;

/* Definition of the type of activation edge of an ICU channel. */
typedef enum
{
  ICU_GPIO_TRIG_TYPE_NONE = 0u,
  /* An appropriate action shall be executed when a rising edge occurs on the ICU input signal. */
  ICU_RISING_EDGE,
  /* An appropriate action shall be executed when a falling edge occurs on the ICU input signal. */
  ICU_FALLING_EDGE,
  /* An appropriate action shall be executed when either a rising or falling edge occur on the ICU input signal. */
  ICU_BOTH_EDGES
} Icu_ActivationType;


/* MCU Lookup Table*/
static const uint16_t Mcu_Table[NO_OF_MCU_GPIOBANKS] = {
    CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_BANK_0,
    CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_BANK_1
};

/* MAIN GPIO0 Bank lookup table */
static const uint16_t Main0_Table[NO_OF_MAIN0_GPIOBANKS] = {
    CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_BANK_0,
    CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_BANK_1,
    CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_BANK_2,
    CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_BANK_3,
    CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_BANK_4,
    CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_BANK_5
};

/* MAIN GPIO1 Bank lookup table */
static const uint16_t Main1_Table[NO_OF_MAIN1_GPIOBANKS] = {
    CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_BANK_0,
    CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_BANK_1,
    CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_BANK_2,
    CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_BANK_3,
    CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_BANK_4,
    CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_BANK_5
};

#endif /* ICU_TYPES_H */

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
