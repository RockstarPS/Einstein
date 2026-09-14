/*********************************************************************************
 **  \file CDio_Ioctl.h
 **
 **  \brief Ioctl Header file for DIO for TIAM62P
 **
 **  This file provides functional defines for a DIO module
 **
 **  Component Name: DIO
 **  Archive:
 **  Date: 07-FEB-2025
 **  \author:
 **
 **  | Date       	| Author   	 |Description |
 **  |--------------|------------|-------------------------------- |
 **  | 02-FEB-2025 	|  PKRISH12  | Initial Version.
 **
 **  \copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (“Materials”) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, estoppel or otherwise, any rights in these Materials.
 **
 *****************************************************************************/
#ifndef _DIO_H_
#define _DIO_H_
/*============================================================================
** Kernel Header Files
**==========================================================================*/
#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stdint.h>
#endif
/**********************************************************************************************************************
 *  DEFINES
 *********************************************************************************************************************/
#define EOK 0
/**********************************************************************************************************************
 *  STRUCTURE
 *********************************************************************************************************************/
/*!
 * \struct       ts_dio_data_t
 * \brief        GPIO Pin details.
 *
 *  \var         ts_dio_data_t::gpio_pin_num
 *  \brief       gpio pin number
 *
 *  \var         ts_dio_data_t::gpio_value
 *  \brief       GPIO pin value.
 *
 *  \var         ts_dio_data_t::gpio_direction
 *  \brief       GPIO pin direction.
 */
typedef struct {
  uint32_t gpio_pin_num;
  int32_t gpio_direction;
  bool gpio_value;
} ts_dio_data_t;
typedef enum {
    e_gpio_dir_in = 0,
    e_gpio_dir_out
} e_gpiodirection;

typedef enum {
  GPIO0_0 = 0, /* GPIO Bank 0 - no: 0 */
  GPIO0_1,
  GPIO0_2,
  GPIO0_3,
  GPIO0_4,
  GPIO0_5,
  GPIO0_6,
  GPIO0_7,
  GPIO0_8,
  GPIO0_9,
  GPIO0_10,
  GPIO0_11,
  GPIO0_12,
  GPIO0_13,
  GPIO0_14,
  GPIO0_15,
  GPIO0_16,
  GPIO0_17,
  GPIO0_18,
  GPIO0_19,
  GPIO0_20,
  GPIO0_21,
  GPIO0_22,
  GPIO0_23,
  GPIO0_24,
  GPIO0_25,
  GPIO0_26,
  GPIO0_27,
  GPIO0_28,
  GPIO0_29,
  GPIO0_30,
  GPIO0_31,
  GPIO0_32,
  GPIO0_33,
  GPIO0_34,
  GPIO0_35,
  GPIO0_36,
  GPIO0_37,
  GPIO0_38,
  GPIO0_39,
  GPIO0_40,
  GPIO0_41,
  GPIO0_42,
  GPIO0_43,
  GPIO0_44,
  GPIO0_45,
  GPIO0_46,
  GPIO0_47,
  GPIO0_48,
  GPIO0_49,
  GPIO0_50,
  GPIO0_51,
  GPIO0_52,
  GPIO0_53,
  GPIO0_54,
  GPIO0_55,
  GPIO0_56,
  GPIO0_57,
  GPIO0_58,
  GPIO0_59,
  GPIO0_60,
  GPIO0_61,
  GPIO0_62,
  GPIO0_63,
  GPIO0_64,
  GPIO0_65,
  GPIO0_66,

  GPIO0_67,
  GPIO0_68,
  GPIO0_69,
  GPIO0_70,
  GPIO0_71,
  GPIO0_72,
  GPIO0_73,
  GPIO0_74,
  GPIO0_75,
  GPIO0_76,
  GPIO0_77,
  GPIO0_78,
  GPIO0_79,
  GPIO0_80,
  GPIO0_81,
  GPIO0_82,
  GPIO0_83,
  GPIO0_84,
  GPIO0_85,
  GPIO0_86,
  GPIO0_87,
  GPIO0_88,
  GPIO0_89,
  GPIO0_90,
  GPIO0_91, /* GPIO Bank 0 - no: 91 */
  GPIO1_0,  /* GPIO Bank 1 - no: 92 */
  GPIO1_1,
  GPIO1_2,
  GPIO1_3,
  GPIO1_4,
  GPIO1_5,
  GPIO1_6,
  GPIO1_7,
  GPIO1_8,
  GPIO1_9,
  GPIO1_10,
  GPIO1_11,
  GPIO1_12,
  GPIO1_13,
  GPIO1_14,
  GPIO1_15,
  GPIO1_16,
  GPIO1_17,
  GPIO1_18,
  GPIO1_19,
  GPIO1_20,
  GPIO1_21,
  GPIO1_22,
  GPIO1_23,
  GPIO1_24,
  GPIO1_25,
  GPIO1_26,
  GPIO1_27,
  GPIO1_28,
  GPIO1_29,
  GPIO1_30,
  GPIO1_31,
  GPIO1_32,
  GPIO1_33,
  GPIO1_34,
  GPIO1_35,
  GPIO1_36,
  GPIO1_37,
  GPIO1_38,
  GPIO1_39,
  GPIO1_40,
  GPIO1_41,
  GPIO1_42,
  GPIO1_43,
  GPIO1_44,

  GPIO1_45,
  GPIO1_46,
  GPIO1_47,
  GPIO1_48,
  GPIO1_49,
  GPIO1_50,
  GPIO1_51 /* GPIO Bank 1 - no: 143 */
} eGpioPinNo;
// Define IOCTL commands
#define IOCTL_TYPE_DIO 'G'
#define GPIO_VALUE_READ _IOW(IOCTL_TYPE_DIO, 1, unsigned long)
#define GPIO_VALUE_WRITE _IOR(IOCTL_TYPE_DIO, 2, unsigned long)
#define GPIO_DIRECTION_READ _IOW(IOCTL_TYPE_DIO, 3, unsigned long)
#define GPIO_DIRECTION_WRITE _IOR(IOCTL_TYPE_DIO, 4, unsigned long)
#endif //_DIO_H_

