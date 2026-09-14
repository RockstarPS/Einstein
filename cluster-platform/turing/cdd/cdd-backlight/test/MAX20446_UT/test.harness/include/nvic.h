/**
    @file       : nvic.h
    @brief      : Startup Application for iMX.
    @details   	: NVIC register definitions
    Platform    : iMX
   
    (c) Copyright 2006-2014 Freescale Semiconductor Inc
    All Rights Reserved.

    You can use this example for any purpose on any computer system with the following restrictions:
    1. This example is provided "as is", without warranty.
    2. You do not remove this copyright notice from this example or any direct derivation thereof.

*/

#ifndef NVIC_H_
#define NVIC_H_

		
/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "typedefs.h"
#include "Std_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define NVIC_BASEADDR 0xE000E100
#define NVIC_ISER_OFFSET(id)    (uint8)((id >> 5) << 2)
#define NVIC_ICER_OFFSET(id)    (0x80 + (uint8)((id >> 5) << 2))
#define NVIC_ISPRO_OFFSET(id)   (0x100 + (uint8)((id >> 5) << 2))
#define NVIC_ICPRO_OFFSET(id)   (0x180 + (uint8)((id >> 5) << 2))
#define NVIC_IABR_OFFSET(id)    (0x200 + (uint8)((id >> 2) << 2))
#define NVIC_IPRO_OFFSET(id)    (0x300 + (uint8)((id >> 2) << 2))
#define NVIC_IPRO_MASK(id)      (uint32)(0xFF << ((id % 4)*8))

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

void NVIC_Test_EnableIRQ(uint8 IRQn);
void NVIC_Test_DisableIRQ(uint8 IRQn);
void NVIC_Test_SetPriority(uint8 IRQn, uint8 priority);
void NVIC_Test_ClearPendingIRQ(uint8 IRQn);
void NVIC_Test_RegisterIsrHandler_basic(uint8_t IRQn, uint32 isr_handler);
void NVIC_Test_RegisterExceptionHandler_basic(uint8_t IRQn, uint32 excep_handler);

#endif /* end of file */
