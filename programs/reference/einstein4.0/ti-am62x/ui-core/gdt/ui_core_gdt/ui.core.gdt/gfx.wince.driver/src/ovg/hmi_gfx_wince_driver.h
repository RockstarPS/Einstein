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

File Name        :  hmi_gfx_wince_driver.h
Module Short Name:  
VOBName          :  sw_hmi_ss
Author           :  abalaji
Description      :  Graphics Driver w/ OpenVG support for Windows CE 6.0 target

Organization     :  Visteon Corporation
List the compiler name with the ersion number
List the Target processor with the variant information

******************************************************************************/

#ifndef HMI_GFX_WINCE_DRIVER_H
#define HMI_GFX_WINCE_DRIVER_H

#include "hmi_gfx_wince_driver.cfg"

#ifndef HMI_GFX_WINCE_DRIVER_C
#define EXTERN  extern
#else
#define EXTERN
#endif

/*****************************************************************************
  Begin C in a C++ environment
******************************************************************************/
#if defined (__cplusplus)
extern "C" {
#endif

/*****************************************************************************
*                                 Constant Declarations                      *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the constant.                                                        *
* purpose, unit, and resolution                                              *
******************************************************************************/


/*****************************************************************************
*                                 Global Macro Definitions                   *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Type Decleration                           *
*----------------------------------------------------------------------------*
* Decleration of type shall be accompanied by a comment that explains the    *
* purpose and usage of the type.                                             *
******************************************************************************/

/*****************************************************************************
*                                 Global Variable Declarations               *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                                 Global Function Prototypes                 *
******************************************************************************/


EXTERN void GfxOvgRefresh (void);

/*****************************************************************************
  End C in a C++ environment
******************************************************************************/
#if defined (__cplusplus)
}
#endif

#undef EXTERN
#endif

/*End of File*/
/*****************************************************************************
*   for each change to this file, be sure to record:                         *
*      1.  who made the change and when the change was made                  *
*      2.  why the change was made and the intended result                   *
*   Following block needs to be repeated for each change
******************************************************************************
*   Note: In the traceability column we need to trace back to the Design Doc.*
*   For the initial version it is traced to the Design Document section.     *
*   For further changes it shall trace to the source of the change which may *
*   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  *
*   other reason                                                            *
******************************************************************************/
/*---------------------------------------------------------------------------
  Date              : 11/29/2010
  By                : abalaji
  Traceability      : Initial version
  Change Description: WinCE graphics driver with OpenVG support
-----------------------------------------------------------------------------*/
