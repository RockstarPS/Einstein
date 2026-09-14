/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2012. Visteon Corporation owns all rights to           *
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
*****************************************************************************/
/*****************************************************************************
*  File Name         :  Port_Types.h                                          *
*  Module Short Name :  PortDrv                                            *
*  VOBName           :                                                       *
*  Author            : vbarad                                              *
*  Description       : This file contains the typedefs for Port               *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :                                                         *
*                                                                            *
******************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Std_Types.h"
/*******************************************************************************
**                      GLOBAL DATA TYPES                                     **
*******************************************************************************/
typedef uint32 Port_PinType;
typedef uint32 Port_PinModeType;

/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/
#define INSTANCE_MCU_GPIO0                                  0u
#define INSTANCE_MAIN_GPIO0                                 1u 
#define INSTANCE_MAIN_GPIO1                                 2u
#define PORT_MAX_PIN_ID                                     144u
#define PORT_WIDTH                                          32u
#define PORT_MODULE_ID                                      124u
#define PORT_INSTANCE_ID                                    0u


/*Can Driver Service Id*/
#define PORT_INIT                                           0u
#define PORT_SETPIN_DIRECTION_ID                            1u

/*------------------[Development errors]-------------------------------------*/
/*Invalid Port Pin ID requested*/
#define PORT_E_PARAM_PIN                                    10u
/*Port Pin not configured as changeable*/
#define PORT_E_DIRECTION_UNCHANGEABLE                       11u
/*Port_Init function called with wrong parameter*/
#define PORT_E_INIT_FAILED                                  12u
/*Port_SetPinMode function called when mode is invalid*/
#define PORT_E_PARAM_INVALID_MODE                           13u
/*Port_SetPinMode function called when mode is unchangeable*/
#define PORT_E_MODE_UNCHANGEABLE                            14u
/*service called without module initialization*/
#define PORT_E_UNINIT                                       15u
/*APIs called with a Null Pointer*/
#define PORT_E_PARAM_POINTER                                16u
#endif