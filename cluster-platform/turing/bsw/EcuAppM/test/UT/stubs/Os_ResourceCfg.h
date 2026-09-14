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
*    @file Os_ResourceCfg.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by TGUNASEK at 2025-06-17 16:35:54.647711400
********************************************************************************************************************/

#ifndef OS_RESOURCECFG_H
#define OS_RESOURCECFG_H


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/


/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
*****************************************************************************/

#define NumberOfResources                                 1U

#define OS_RES_TYPE_STANDARD                              0x00U
#define OS_RES_TYPE_INTERNAL                              0x01U
#define OS_RES_TYPE_LINKED                                0x02U


/* OsApp count accessing given resource */
#define OsNumberOfApplicationsSchedRes0                   2

#define OsMaxPriorityLevel                                16U

/* Resource IDs */
#define RES_SCHEDULER                                     0

#define osdMaxTaskOfPrio0 1
#define osdMaxTaskOfPrio1 1
#define osdMaxTaskOfPrio2 1
#define osdMaxTaskOfPrio3 1
#define osdMaxTaskOfPrio4 1
#define osdMaxTaskOfPrio5 1
#define osdMaxTaskOfPrio6 1
#define osdMaxTaskOfPrio7 1
#define osdMaxTaskOfPrio8 1
#define osdMaxTaskOfPrio9 1
#define osdMaxTaskOfPrio10 1
#define osdMaxTaskOfPrio11 1
#define osdMaxTaskOfPrio12 1
#define osdMaxTaskOfPrio13 1
#define osdMaxTaskOfPrio14 1
#define osdMaxTaskOfPrio15 1

#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

