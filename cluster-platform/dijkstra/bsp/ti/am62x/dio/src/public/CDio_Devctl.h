/***************************************************************************
 **
 **  \file CDio_Devctl.h
 **
 **  \brief Interface to interact with the DIO of TI-AM62P
 **
 **  This file provides functional defines for a DIO module
 **
 **  Component Name: DIO
 **  Archive:
 **  Date: Feb 8 2020
 **  \author: Dinakar Babu
 **
 **  \copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (“Materials”) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, estoppel or otherwise, any rights in these Materials.
 **
 **==========================================================================*/

/**********************************************************************************************************************
 *  HEADER FILE GUARD
 *********************************************************************************************************************/
#ifndef CDIO_DEVCTL_H_
#define CDIO_DEVCTL_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <devctl.h>

typedef enum
{
    e_gpio_direction_in = 0,
    e_gpio_direction_out
} EDirection;

/**********************************************************************************************************************
 *  STRUCTURE
 *********************************************************************************************************************/
/// \struct  gpio_buffer_type
/// \brief   struct gpio_buffer_type used by devctl

/// \var     gpio_buffer_type::gpio_value
/// \param   gpio_value [in/out] gpio value

/// \var     gpio_buffer_type::e_direction
/// \param   e_direction [in/out] e_direction
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
