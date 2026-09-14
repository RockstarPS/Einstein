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
*  File Name         :  Port.c                                                *
*  Module Short Name :  PortDrv                                               *
*  Description       :  This file contains implementations of the Port Driver *
*                       for AM62PX series microcontrollers.               *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  Clang Compiler                                          *
* Target Hardware  :  AM62PX micro based Hardware Platform                *
*                                                                            *
******************************************************************************/
#ifndef PORT_C
#define PORT_C

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Port.h"
#include "Port_Cfg.h"
#include "Port_Types.h"
#include "Dio.h"
#include "DioApp.h"
#include <Dio/dio_hw/V0/lld_gpio.h>
#include "Det.h"

/*****************************************************************************
*                     Locally used Variable Declarations                     *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
static const Port_ConfigType_t* Port_currentconfig = NULL;

/***************************************************************************************************************************
*                                            Function Prototypes                                                           *
****************************************************************************************************************************/
extern void Pinmux_init(void);

/***************************************************************************************************************************
*                                            Functions Implementation                                                      *
****************************************************************************************************************************/

/***************************************************************************************************************************
** Function Name     : void Port_GetVersionInfo (Std_VersionInfoType* versioninfo)
**
** Description       : Returns the version information of this module
**
** Invocation        :  
**
** Parameters        : versioninfo : Pointer to where to store the version information of this module.
**
** Return Value      : None
**
** Critical Section  : None
***************************************************************************************************************************/
void Port_GetVersionInfo (const Std_VersionInfoType* versioninfo)
{
    (void)versioninfo;
}
/***************************************************************************************************************************
** Function Name     : void Port_Init(Port_ConfigType ConfigPtr)
**
** Description       : Initializes the Port Driver module.
**
** Invocation        :  
**
** Parameters        : ConfigPtr : Pointer to configuration set.
**
** Return Value      : None
**
** Critical Section  : None
***************************************************************************************************************************/
void Port_Init (const Port_ConfigType_t * ConfigPtr)
{
    (void)Pinmux_init();

    CSL_GpioHandle hGpio;
    uint32                          PinId;
    uint32                          PortNum;
    uint32                          PinMsk;
    uint32                          PinNum;
    uint32                          Set_PinNum;
    Port_currentconfig = ConfigPtr;

    if(ConfigPtr!= NULL)
    {
        for(PinId=0; PinId< Port_currentconfig->NumOfPins; PinId++)
        {
            const Port_PinConfigType* pinConfig = &Port_currentconfig->Pins[PinId];

            Set_PinNum = ((pinConfig->Port_Instance * PORT_MAX_PIN_ID) + pinConfig->Port_Pin);

            Port_SetPinDirection(Set_PinNum, pinConfig->Port_Direction);

            PortNum = pinConfig->Port_Pin / PORT_WIDTH;
            PinNum  = pinConfig->Port_Pin % PORT_WIDTH;

            if(pinConfig->Port_Direction == PORT_PIN_OUT)
            {
                hGpio = (CSL_GpioHandle)Dio_GPIOBaseAddr[pinConfig->Port_Instance];

                PinMsk = ((uint32)1u << PinNum);

                if(pinConfig->Port_DefaultValue != 0u)
                {
                    hGpio->BANK_REGISTERS[PortNum].SET_DATA = PinMsk;
                }
                else
                {
                    hGpio->BANK_REGISTERS[PortNum].CLR_DATA = PinMsk;
                }
            }
        }
    }
    else
    {
        (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,PORT_INIT,PORT_E_PARAM_POINTER);
    }
}
/***************************************************************************************************************************
** Function Name     : void Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType Direction)
**
** Description       : Sets the port pin direction
**
** Invocation        :  
**
** Parameters        : Pin: Port Pin ID number
**                     Direction : Port Pin Direction
**
** Return Value      : None
**
** Critical Section  : None
***************************************************************************************************************************/
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
    uint32 PinMsk, Instance, port_num, Port_pin;
    CSL_GpioHandle hGpio;

    Instance = Pin / PORT_MAX_PIN_ID;
    Port_pin= ((Pin % PORT_MAX_PIN_ID)% PORT_WIDTH);
    port_num = (Pin % PORT_MAX_PIN_ID) / PORT_WIDTH;
    
    hGpio= (CSL_GpioHandle)Dio_GPIOBaseAddr[Instance];
    PinMsk= ((uint32)1u << Port_pin);

    if(Direction == PORT_PIN_OUT)
    {
        hGpio->BANK_REGISTERS[port_num].DIR &= ~PinMsk;  //direction as output
    }
    else
    {
        hGpio->BANK_REGISTERS[port_num].DIR |= PinMsk;   //direction as input
    }
}
/***************************************************************************************************************************
** Function Name     : void Port_RefreshPortDirection(void)
**
** Description       : Refreshes port direction
**
** Invocation        :  
**
** Parameters        : 
**
** Return Value      : None
**
** Critical Section  : None
***************************************************************************************************************************/
void Port_RefreshPortDirection(void)
{
    uint32 PinId;

    if(Port_currentconfig!= NULL)
    {
        for(PinId=0; PinId < Port_currentconfig->NumOfPins; PinId++)
        {
            const Port_PinConfigType* PinConfig = &Port_currentconfig->Pins[PinId];

            Port_SetPinDirection(PinConfig->Port_Pin, PinConfig->Port_Direction);
        }
    }
}
/***************************************************************************************************************************
** Function Name     : voidPort_SetPinMode(Port_PinType Pin,Port_PinModeType Mode)
**
** Description       : Sets the port pin mode.
**
** Invocation        :  
**
** Parameters        : Pin: Port Pin ID number
**                     Mode : New Port Pin mode to be set on port pin
**
** Return Value      : None
**
** Critical Section  : None
***************************************************************************************************************************/
// void Port_SetPinMode (Port_PinType Pin, Port_PinModeType Mode)
// {

// }

#endif