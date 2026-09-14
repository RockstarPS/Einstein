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
*    @file Os_Application_Lcfg.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by BJAYARA3 at 2025-12-12 17:15:15.701843800
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


extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_BSW_COM_Periodic_2;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_BSW_EventPeriodic_0;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_Init_Task;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_IdleTask_OsCore_Core0;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_BSW_Periodic_0;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_BSW_Periodic_1;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_CAN_Periodic_0;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_CDD_FitPeriodic_1;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_CDD_Periodic_0;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_COM_EventPeriodic_0;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_CanDataRx_0;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_NvmSpeedup;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_SafeBsw_0;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_SafeBsw_1;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTask_LSH_16ms;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsTaskRender;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_SystemTimerISR;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_CAN0_ISR;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_GPT_ISR;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_BACKUP;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_PDMA48;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_PDMA49;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_PDMA50;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_PDMA51;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_PDMA52;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_cpuss_interrupts_ipc_6_IRQn;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_ISR_GFX2D;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_ISR_VIDEOIO_0;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_ISR_VIDEOIO_1;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_ISR_PDMA22;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_ISR_MDMA1;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_ISR_MDMA2;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_CAN1_ISR;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_SCB2;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_IGN_ISR;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_CAN_WAKEUP_ISR;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_ECC_ERROR_ISR;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_MCU_LVD_ISR;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_CSV_ERROR_ISR;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_SSV_ERROR_ISR;
extern CONST(OsObjConfigType, OS_CONST) OsObjConfig_OsKernel_OsCoreAsr0;

extern CONST(OsAppConfigType, OS_CONST) OsAppConfig_TrustedSystem;
extern CONST(OsAppConfigType, OS_CONST) OsAppConfig_QM;

extern CONST (OsObjConfigRefType, OS_CONST) OsApplication_TrustedSystemObjConfigRef[28];
extern CONST (OsObjConfigRefType, OS_CONST) OsApplication_QMObjConfigRef[13];

extern const OsObjConfigRefType  OsObjRefConfig[OsMaxNumOfObjectId];

extern OsAppConfigRefType OsAppRefListDyn[OsNumberOfApplications];


#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

