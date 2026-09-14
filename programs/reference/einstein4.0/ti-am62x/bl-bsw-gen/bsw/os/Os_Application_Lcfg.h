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
*    @file Os_Application_Lcfg.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by MNATRAMI at 2026-04-06 16:31:56.335514900
********************************************************************************************************************/

#ifndef OS_APPLICATIONLCFG_H
#define OS_APPLICATIONLCFG_H


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/



/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
*****************************************************************************/


extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_InitTask;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_Ucl;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_Diagnostics;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_CANFun;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_WdgMngt;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_IdleTask;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_McuOsGptIsr;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_McuCan0RxTxIsr;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_McuCan1RxTxIsr;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_McuI2c3IoIsr;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_McuI2c0PmicIsr;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Gpt_Ch3Isr;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Gpt_Ch4Isr;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_PmicCdd_nINTGpioInterrupt;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsKernel_OsCoreAsr0;

extern CONST(OsAppConfigType, OS_CONST) OsAppConfig_TrustedSystem;

extern CONST (OsObjConfigRefType, OS_CONST) OsApplication_TrustedSystemObjConfigRef[16];

extern const OsObjConfigRefType  OsObjRefConfig[OsMaxNumOfObjectId];

extern OsAppConfigRefType OsAppRefListDyn[OsNumberOfApplications];


#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

