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
*  File Name         :  IoExp_Types.h                                        *
*  Module Short Name :  IoExp_ads7138                                        *
*  VOBName           :                                                       *
*  Author            : gthanapp                                              *
*  Description       : This file contains the typedefs for nvM               *
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
#ifndef IOEXP_TYPES_H
#define IOEXP_TYPES_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Std_Types.h"
#include "IoExp_Cfg.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/


/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
/**
* @brief IoExp_LevelType is the type for the possible levels that a DIO
*        channel can have (input or output).
*/

typedef uint8 IoExp_LevelType;

/**
* @brief IoExp_ChannelType contain the numeric ID
*        of a DIO channel
*/

typedef uint32 IoExp_ChannelType;

/**
* @brief Type for reading the converted values of a 
*        channel group (raw, without further scaling)
*/

typedef uint16 IoExp_AdcValueType;

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#define IOEXP_NUM_OF_PIN_PER_DEVICE     8u
#define IOEXP_TOTAL_PIN_USED            (IOEXP_NUM_OF_DEVICES * IOEXP_NUM_OF_PIN_PER_DEVICE)

#if (IOEXP_TOTAL_PIN_USED < IOEXP_TOTAL_PIN_CONFIGURED)
   #error PIN Configuration Error in IOEXP
#elif (IOEXP_TOTAL_PIN_CONFIGURED == 0u)
   #error PIN Configuration Error in IOEXP
#endif

#endif /* IOEXP_TYPES_H */

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
/*Date              : 08-03-2024                                            */
/*Version           :                                                       */
/*By                : gthanapp                                              */
/*Traceability      :                                                       */
/*Change Description: Initial release                                       */
/*--------------------------------------------------------------------------*/
