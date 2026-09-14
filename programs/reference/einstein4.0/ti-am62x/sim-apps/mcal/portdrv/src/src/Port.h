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
*  File Name         :  PortDrv.h                                              *
*  Module Short Name :  PortDrv                                                *
*  Description       :  This file contains implementations of the Port Driver  *
*                       for AM62PX series microcontrollers.                   *
*                                                                             *
* Organization     :  Driver Information Software Section,                    *
*                     Visteon Software Operation                              *
*                     Visteon Corporation                                     *
*                                                                             *
* ----------------------------------------------------------------------------*
* Compiler Name    :  Clang Compiler                                          *
* Target Hardware  :  AM62PX micro based Hardware Platform                    *
*                                                                             *
******************************************************************************/
#ifndef PORT_H
#define PORT_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Port_Cfg.h"
#include "Std_Types.h"
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
extern void Port_GetVersionInfo (Std_VersionInfoType* versioninfo);
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
extern void Port_Init (const Port_ConfigType_t* ConfigPtr);
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
extern void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);
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
extern void Port_RefreshPortDirection(void);
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
// extern void Port_SetPinMode (Port_PinType Pin, Port_PinModeType Mode);



#endif