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
*    @file Os_Application_Cfg.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by MNATRAMI at 2026-04-06 16:31:56.335514900
********************************************************************************************************************/

#ifndef OS_APPLICATIONCFG_H
#define OS_APPLICATIONCFG_H


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/


/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
*****************************************************************************/


#define OsNumberOfApplications                            1U

#define OsMaxNumOfObjectId                                (OsNumberOfTasks + OsNumberOfIsr + OsNumberOfCores)

/* Num of applications in core */
#define OsNumberOfApplicationsCore0                        1


/* Application Type  */
#define OS_CFG_OSAPPLICATION_TRUSTEDSYSTEM                 0UL
#define OS_CFG_APPLICATION_INVALID                        0xFFU

/* AccessRightsIdType */
#define OS_CFG_MPU_REGION_OsMpu_TrustedSystem             0UL
#define OS_CFG_MPU_REGION_INVALID                         0xFFFFFFFFU

#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

