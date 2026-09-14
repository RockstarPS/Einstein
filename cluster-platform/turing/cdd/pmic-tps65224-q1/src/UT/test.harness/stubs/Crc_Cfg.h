/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2013. Visteon Corporation owns all rights to           *
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
*  File Name         :  Crc.h                                                *
*  Module Short Name :  CRC_H                                                *
*  Description       :                                                       *
*                                                                            *
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
#ifndef CRC_CFG_H
#define CRC_CFG_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define CRC_ENABLE   0x48U
#define CRC_DISABLE   0x49U

/*SWS_Crc_00013 - FUNCTION CRC_ENABLE MACRO */

#define CRC_CALCULATECRC8_ENABLE  		CRC_ENABLE
#define CRC_CALCULATECRC8H2F_ENABLE  	CRC_ENABLE
#define CRC_CALCULATECRC16_ENABLE  		CRC_ENABLE
#define CRC_CALCULATECRC32_ENABLE  		CRC_ENABLE
#define CRC_CALCULATECRC32P4_ENABLE 	CRC_ENABLE
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/


/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                               Functions                                    *
******************************************************************************/

#endif //CRC_CFG_H
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
Date               : 30-Aug-2016
CDSID              : ssebast1
Traceability       : RTC #674918
Change Description : Initial Framework version of CRC
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 19-May-2020
CDSID              : bbaskara
Traceability       : RTC #883468
Change Description : Updated Source file as per SSR
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/


