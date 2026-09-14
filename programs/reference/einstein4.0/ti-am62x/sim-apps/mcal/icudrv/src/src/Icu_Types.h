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

/* One MCU and two MAIN domain's base address*/
#define CSL_MCU_GPIO0_BASE                                                                         (0x4201000UL)
#define CSL_GPIO0_BASE                                                                             (0x600000UL)
#define CSL_GPIO1_BASE                                                                             (0x601000UL)

/* WKUP_MCU GPIO interrupt router outputs */
#define WKUP_MCU_GPIOMUX_INTROUTER0_OUTP_6                                                          (6U)
#define WKUP_MCU_GPIOMUX_INTROUTER0_OUTP_7                                                          (7U)

/* MAIN GPIO interrupt router outputs */
#define MAIN_GPIOMUX_INTROUTER0_OUTP_34                                                             (34U)
#define MAIN_GPIOMUX_INTROUTER0_OUTP_35                                                             (35U)

/*
* List of intr sources for receiver: WKUP_MCU_GPIOMUX_INTROUTER0
*/

#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_0                                       (0U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_1                                       (1U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_2                                       (2U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_3                                       (3U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_4                                       (4U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_5                                       (5U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_6                                       (6U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_7                                       (7U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_8                                       (8U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_9                                       (9U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_10                                      (10U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_11                                      (11U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_12                                      (12U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_13                                      (13U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_14                                      (14U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_15                                      (15U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_16                                      (16U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_17                                      (17U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_18                                      (18U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_19                                      (19U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_20                                      (20U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_21                                      (21U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_22                                      (22U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_23                                      (23U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_BANK_0                                  (30U)
#define CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_BANK_1                                  (31U)


/*
* List of intr sources for receiver: MAIN_GPIOMUX_INTROUTER0
*/

#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_0                                               (0U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_1                                               (1U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_2                                               (2U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_3                                               (3U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_4                                               (4U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_5                                               (5U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_6                                               (6U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_7                                               (7U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_8                                               (8U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_9                                               (9U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_10                                              (10U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_11                                              (11U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_12                                              (12U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_13                                              (13U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_14                                              (14U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_15                                              (15U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_16                                              (16U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_17                                              (17U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_18                                              (18U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_19                                              (19U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_20                                              (20U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_21                                              (21U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_22                                              (22U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_23                                              (23U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_24                                              (24U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_25                                              (25U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_26                                              (26U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_27                                              (27U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_28                                              (28U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_29                                              (29U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_30                                              (30U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_31                                              (31U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_32                                              (32U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_33                                              (33U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_34                                              (34U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_35                                              (35U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_36                                              (36U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_37                                              (37U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_38                                              (38U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_39                                              (39U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_40                                              (40U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_41                                              (41U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_42                                              (42U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_43                                              (43U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_44                                              (44U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_45                                              (45U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_46                                              (46U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_47                                              (47U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_48                                              (48U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_49                                              (49U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_50                                              (50U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_51                                              (51U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_52                                              (52U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_53                                              (53U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_54                                              (54U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_55                                              (55U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_56                                              (56U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_57                                              (57U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_58                                              (58U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_59                                              (59U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_60                                              (60U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_61                                              (61U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_62                                              (62U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_63                                              (63U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_64                                              (64U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_65                                              (65U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_66                                              (66U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_67                                              (67U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_68                                              (68U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_69                                              (69U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_70                                              (70U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_71                                              (71U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_72                                              (72U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_73                                              (73U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_74                                              (74U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_75                                              (75U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_76                                              (76U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_77                                              (77U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_78                                              (78U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_79                                              (79U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_80                                              (80U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_81                                              (81U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_82                                              (82U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_83                                              (83U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_84                                              (84U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_85                                              (85U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_86                                              (86U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_87                                              (87U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_88                                              (88U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_89                                              (89U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_0                                               (90U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_1                                               (91U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_2                                               (92U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_3                                               (93U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_4                                               (94U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_5                                               (95U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_6                                               (96U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_7                                               (97U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_8                                               (98U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_9                                               (99U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_10                                              (100U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_11                                              (101U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_12                                              (102U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_13                                              (103U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_14                                              (104U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_15                                              (105U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_16                                              (106U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_17                                              (107U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_18                                              (108U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_19                                              (109U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_20                                              (110U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_21                                              (111U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_22                                              (112U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_23                                              (113U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_24                                              (114U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_25                                              (115U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_26                                              (116U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_27                                              (117U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_28                                              (118U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_29                                              (119U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_30                                              (120U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_31                                              (121U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_32                                              (122U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_33                                              (123U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_34                                              (124U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_35                                              (125U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_36                                              (126U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_37                                              (127U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_38                                              (128U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_39                                              (129U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_40                                              (130U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_41                                              (131U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_42                                              (132U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_43                                              (133U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_44                                              (134U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_45                                              (135U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_46                                              (136U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_47                                              (137U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_48                                              (138U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_49                                              (139U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_50                                              (140U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_51                                              (141U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_52                                              (142U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_53                                              (143U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_54                                              (144U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_55                                              (145U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_56                                              (146U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_57                                              (147U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_58                                              (148U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_59                                              (149U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_60                                              (150U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_61                                              (151U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_62                                              (152U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_63                                              (153U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_64                                              (154U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_65                                              (155U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_66                                              (156U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_67                                              (157U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_68                                              (158U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_69                                              (159U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_70                                              (160U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_71                                              (161U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_TIMER0_TIMER_PWM_0                                         (162U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_TIMER1_TIMER_PWM_0                                         (163U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_TIMER2_TIMER_PWM_0                                         (164U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_TIMER3_TIMER_PWM_0                                         (165U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_TIMER4_TIMER_PWM_0                                         (166U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_TIMER5_TIMER_PWM_0                                         (167U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_TIMER6_TIMER_PWM_0                                         (168U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_TIMER7_TIMER_PWM_0                                         (169U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_MCU_TIMER0_TIMER_PWM_0                                     (170U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_MCU_TIMER1_TIMER_PWM_0                                     (171U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_MCU_TIMER2_TIMER_PWM_0                                     (172U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_MCU_TIMER3_TIMER_PWM_0                                     (173U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_WKUP_TIMER0_TIMER_PWM_0                                    (174U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_WKUP_TIMER1_TIMER_PWM_0                                    (175U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_90                                              (176U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_91                                              (177U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_BANK_0                                          (180U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_BANK_1                                          (181U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_BANK_2                                          (182U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_BANK_3                                          (183U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_BANK_4                                          (184U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO1_GPIO_BANK_5                                          (185U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_BANK_0                                          (190U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_BANK_1                                          (191U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_BANK_2                                          (192U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_BANK_3                                          (193U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_BANK_4                                          (194U)
#define CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_BANK_5                                          (195U)

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
  ICU_GPIO_TRIG_TYPE_NONE,
  /* An appropriate action shall be executed when a rising edge occurs on the ICU input signal. */
  ICU_RISING_EDGE,
  /* An appropriate action shall be executed when a falling edge occurs on the ICU input signal. */
  ICU_FALLING_EDGE,
  /* An appropriate action shall be executed when either a rising or falling edge occur on the ICU input signal. */
  ICU_BOTH_EDGES
} Icu_ActivationType;


/* MCU Lookup Table*/
static const uint32 Mcu_Table[2] = {
    CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_BANK_0,
    CSLR_WKUP_MCU_GPIOMUX_INTROUTER0_IN_MCU_GPIO0_GPIO_BANK_1
};

/* MAIN GPIO0 Bank lookup table */
static const uint32 Main0_Table[6] = {
    CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_BANK_0,
    CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_BANK_1,
    CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_BANK_2,
    CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_BANK_3,
    CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_BANK_4,
    CSLR_MAIN_GPIOMUX_INTROUTER0_IN_GPIO0_GPIO_BANK_5
};

/* MAIN GPIO1 Bank lookup table */
static const uint32 Main1_Table[6] = {
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
