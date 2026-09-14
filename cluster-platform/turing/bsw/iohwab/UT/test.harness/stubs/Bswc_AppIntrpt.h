/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2004. Visteon Corporation owns all rights to           *
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
File Name      : Bswc_AppIntrpt.h
Short Name     : 
VOBName        : 
Author         : skarthi8
Description    : Implementation of logic to calculate 100ms counts and Distance Counts in BSW
Organization   : Driver Information Software Section,
                 Visteon Corporation
----------------------------------------------------------------------------
Compiler Name    :  MPC CW
Target Hardware  :
******************************************************************************/

#ifndef BSW_APPINTRPT_H
#define BSW_APPINTRPT_H


/*****************************************************************************
*                                 System Includes                            *
******************************************************************************/

/*****************************************************************************
*                                 Project Includes                           *
******************************************************************************/

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define ODO_DISTANCE_CONV_DENOM     ((uint8)45)
#define TIME_100MS_COUNT	        ((uint8)10)
#define TIME_COUNT_INIT		        ((uint8)0)
#define DIST_COUNT_INIT		        ((uint32)0)
#define MIN_VALID_VEHICLE_SPEED 	((uint16)0)
#define MAX_VALID_VEHICLE_SPEED     ((uint16)0xFFF)
#define BSWAppMSEC_TO_TICKS			((uint32)800000UL)
#define DUTY_50PER                  (uint16)(500)
/******************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/** 
 * @name "application specific" configurations and constant definitions
 */

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
#define RI_BswApp_StartTimer()                            \
    {                                                   \
       Gpt_EnableNotification((Gpt_ChannelType)GptConf_GptChannelConfiguration_IFE_FRTimer);              \
      Gpt_StartTimer((Gpt_ChannelType)GptConf_GptChannelConfiguration_IFE_FRTimer, (uint32)BSWAppMSEC_TO_TICKS);   \
    }

#define RI_BswApp_StopTimer()                            \
    {                                                   \
       Gpt_DisableNotification((Gpt_ChannelType)GptConf_GptChannelConfiguration_IFE_FRTimer);              \
        Gpt_StopTimer((Gpt_ChannelType)GptConf_GptChannelConfiguration_IFE_FRTimer);   \
    }

/*****************************************************************************
*                              File Scope Prototypes                         *
******************************************************************************/

/*****************************************************************************
*                   		  Functions		                                  *
******************************************************************************/
extern void Bswc_AppIntrpt_ISR(void);


#endif

/******************************************************************************
  Release Version     : Initial Version
  Date              : 03/10/2016
  By                : skarthi8
  Traceability      : 
  Change Description: Initial version.
******************************************************************************/  
