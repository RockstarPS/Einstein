/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2026 by Visteon Corporation.       All rights reserved.         
*                                                                                                                    
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                   
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve              
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States     
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,             
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its       
* rights under all copyright laws to protect this work as a published work, when appropriate.                        
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it   
* without the written authorization of Visteon Corporation.                                                          
********************************************************************************************************************/

/*******************************************************************************************************************
*    @file Os_CfgTypes.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by SGOPAL1 at 2026-03-31 13:17:24.147119900
********************************************************************************************************************/

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

/* End osTypeDefinitions */
#endif


//to be generated for cpu specific
typedef uint8                         osuint8;
typedef uint16                        osuint16;
typedef uint32                        osuint32;
typedef uint64                        osuint64;
typedef sint8                         osint8;
typedef sint16                        osint16;
typedef sint32                        osint32;
typedef sint64                        osint64;
typedef osuint8                       osbool;
typedef float32                       osfloat32;
typedef float64                       osfloat64;
typedef osuint32                      osCpuStackType;
typedef osuint32                      osCpuTaskAddressType;
typedef osuint32                      osCpuTaskPriorityBitType;
typedef osuint32                      osCpuIntGlobalType;
typedef osuint32                      osCpuMemoryAddressType;

#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

