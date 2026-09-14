/*============================================================================
 **
 **  \file CDio_Devctl.h
 **
 **  \brief Interface to interact with the DIO of iMX8
 **
 **  This file provides functional defines for a DIO module
 **
 **  Component Name: DIO
 **  Archive:
 **  Date: Feb 8 2020
 **  Author: Dinakar Babu
 **
 ** Copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (“Materials”) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, estoppel or otherwise, any rights in these Materials.
 **
 **==========================================================================*/

#ifndef CDIO_DEVCTL_H_
#define CDIO_DEVCTL_H_

#include <devctl.h>

typedef enum
{
    e_gpio_direction_in = 0,
    e_gpio_direction_out
} EDirection;

///
/// @brief struct gpio_buffer_type used by devctl
///
/// @param gpio_value [in/out] gpio value
///
typedef struct
{
    uint8_t gpio_value;
    EDirection e_direction;
} gpio_buffer_type;

// ##################### DEFINE DEVCTL COMMANDS ##############################

#define CMD_CODE 1
#define GPIO_VALUE_READ      __DIOF(_DCMD_MISC, CMD_CODE + 0,  gpio_buffer_type)
#define GPIO_VALUE_WRITE     __DIOT(_DCMD_MISC, CMD_CODE + 1,  gpio_buffer_type)
#define GPIO_DIRECTION_READ  __DIOF(_DCMD_MISC, CMD_CODE + 2,  gpio_buffer_type)
#define GPIO_DIRECTION_WRITE __DIOT(_DCMD_MISC, CMD_CODE + 3,  gpio_buffer_type)

#endif /* SRC_DIO_DIODEVCTL_H_ */
