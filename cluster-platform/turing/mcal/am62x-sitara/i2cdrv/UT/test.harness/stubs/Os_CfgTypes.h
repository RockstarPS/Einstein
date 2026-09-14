/******************************************************************************
**              CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2012. Visteon Corporation owns all rights to this work and
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

File Name        :  Os_CfgTypes.h
Module Short Name:  Os_CfgTypes.h
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef OS_CFGTYPES_H
#define OS_CFGTYPES_H


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/
                                                                              
#include "Std_Types.h"
                                                                              
                                                                              
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
*****************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
*****************************************************************************/
                                                                              
/* OS type definitions */
/* Begin osTypeDefinitions (default) */
#ifndef osTypesDefined
#define osTypesDefined
typedef unsigned char  osuint8;
typedef unsigned short osuint16;
typedef unsigned long  osuint32;
typedef unsigned long  long osuint64;
typedef signed   char  osint8;
typedef signed   short osint16;
typedef signed   long  osint32;
typedef signed   long  long osint64;
typedef osuint8 osbool;
/* End osTypeDefinitions */
#endif


//to be generated for cpu specific
typedef osuint32        osCpuStackType;
typedef osuint32        osCpuTaskAddressType;
typedef osuint32        osCpuTaskPriorityBitType;
typedef osuint32        osCpuIntGlobalType;
typedef osuint32        osCpuMemoryAddressType;



#endif    /* */
/* end of file */
/****************************************************************
Created Time: 2/19/2024 9:51:31 AM
****************************************************************/
