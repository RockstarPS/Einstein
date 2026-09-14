/******************************************************************************
**              CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2024. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have  jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation
**
******************************************************************************/
/******************************************************************************

File Name        :  Port_Cfg.c
Module Short Name:  Port_Cfg.c
VOBName          :  
Author           :  vbarad
Description      :  This file contains configurations needed for Portv module
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/
#ifndef PORT_CFG_C
#define PORT_CFG_C
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Port_Cfg.h"
#include "Port.h"
/*****************************************************************************
*                        Globally  accessed Variable Declarations            *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
const Port_ConfigType_t PortConfig_RUN = {
    .Pins = {
		{INSTANCE_MCU_GPIO0,  7u,  PORT_PIN_OUT,  0u},
        {INSTANCE_MCU_GPIO0,  11u, PORT_PIN_OUT,  0u},
		{INSTANCE_MCU_GPIO0,  19u, PORT_PIN_OUT,  0u},
		{INSTANCE_MCU_GPIO0,  21u, PORT_PIN_OUT,  0u},
        {INSTANCE_MCU_GPIO0,  22u, PORT_PIN_OUT,  0u},
        {INSTANCE_MCU_GPIO0,  23u, PORT_PIN_OUT,  0u},
		{INSTANCE_MAIN_GPIO0, 52u, PORT_PIN_OUT,  0u},
		{INSTANCE_MAIN_GPIO0, 71u, PORT_PIN_OUT,  0u},
		{INSTANCE_MAIN_GPIO0, 91u, PORT_PIN_OUT,  0u},
		{INSTANCE_MAIN_GPIO1, 2u,  PORT_PIN_OUT,  0u},
        {INSTANCE_MAIN_GPIO1, 5u,  PORT_PIN_OUT,  0u},
		{INSTANCE_MAIN_GPIO1, 9u,  PORT_PIN_OUT,  0u},
		{INSTANCE_MAIN_GPIO1, 45u, PORT_PIN_OUT,  0u},
		{INSTANCE_MAIN_GPIO1, 31u, PORT_PIN_IN,   0u},
    },
    .NumOfPins = NUM_OF_PINS 
};
#endif