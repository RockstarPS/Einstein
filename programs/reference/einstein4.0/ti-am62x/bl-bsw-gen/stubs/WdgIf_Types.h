/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2017. Visteon Corporation owns all rights to           *
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
*  File Name         :  WdgM_Types.h                                         *
*  Module Short Name :  WdgM_Types                                           *
*  Description       :  This file contains declations of the Autosar WDG     *
*                       Manager types and macros                             *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/
#ifndef WDGMIF_TYPES_H
#define WDGMIF_TYPES_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
/* Autosar Verison */
#define WDGIF_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define WDGIF_TYPES_AR_RELEASE_MINOR_VERSION     2

typedef enum {
  WDGIF_OFF_MODE  = 0u, /*!< Watchdog disabled                      */
  WDGIF_SLOW_MODE = 1u, /*!< Long timeout period (slow triggering)  */
  WDGIF_FAST_MODE = 2u  /*!< Short timeout period (fast triggering) */
} WdgIf_ModeType;


#endif //WDGMIF_TYPES_H
/*============================================================================
**============================================================================
** R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
**===========================================================================*/
/*---------------------------------------------------------------------------
Date               : 28-Mar-2020
CDSID              : ssebast1
Traceability       : RTC #806059
Change Description : Autosar Version Added
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/



