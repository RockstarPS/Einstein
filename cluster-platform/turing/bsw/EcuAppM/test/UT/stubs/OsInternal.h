/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2025 by Visteon Corporation.       All rights reserved.         
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
*    @file OsInternal.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by TGUNASEK at 2025-06-17 16:35:54.763970400
********************************************************************************************************************/


#ifndef OSINTERNAL_H
#define OSINTERNAL_H


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/

#include "intvect.h"
#ifndef WIN_32
#ifndef __cplusplus
#include "cyt3dlabhs.h"
#include "core_cm7.h"
  #endif
    #endif
/* Timer reload value for generating Os ticks.*/
#define osdReloadValue                                    0x38A3FU



#define OS_INTERNAL_FPU_ENABLED           1


#endif	/* */


/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

