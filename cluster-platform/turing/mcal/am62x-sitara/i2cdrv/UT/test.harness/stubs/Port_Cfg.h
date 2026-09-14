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

File Name        :  Port_Cfg.h
Module Short Name:  Port_Cfg.h
VOBName          :  
Author           :  vbarad
Description      :  This file contains configurations needed for Portv module
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/
#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Port_Types.h"
#include "Platform_Types.h"
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
#define NUM_OF_PINS 48u

typedef enum
{
    PORT_PIN_IN = 0,  /*Set port pin as input*/   
    PORT_PIN_OUT = 1 /*Set port pin as output*/ 
}Port_PinDirectionType;

typedef struct{
    uint32 Port_Instance;                      //MCU or Main domain
    uint32 Port_Pin;                         //Pin number
    Port_PinDirectionType Port_Direction;   //Input or output direction
    uint32 Port_DefaultValue;                //Default output level for ouput pins
}Port_PinConfigType;

typedef struct{
    Port_PinConfigType Pins[NUM_OF_PINS];  //Pin configuration
    uint8 NumOfPins;           //Number of pins in the configuration
}Port_ConfigType_t;

extern const Port_ConfigType_t PortConfig_RUN;

extern const Port_ConfigType_t PortConfig_SLEEP;

#endif