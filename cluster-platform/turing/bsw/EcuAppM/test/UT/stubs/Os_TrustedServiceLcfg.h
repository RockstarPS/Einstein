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
*    @file Os_TrustedServiceLcfg.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by TGUNASEK at 2025-06-17 16:35:54.629068700
********************************************************************************************************************/

#ifndef OS_TRUSTEDSERVICELCFG_H
#define OS_TRUSTEDSERVICELCFG_H


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/



/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
*****************************************************************************/
                                                                              
                                                                              
/*****************************************************************************
*                                 Type Declarations                          *
*****************************************************************************/


extern Std_ReturnType IoHwAb_SetOutputPin(IoHwAb_DOutSignalIdType Arg1,boolean Arg2,IoHwAb_ErrorType* Arg3);
extern void EcuMExt_McuSetMode(Mcu_ModeType Arg1);
extern uint8 EcuMExt_EnableInterruptSource(ISRType Arg1,boolean Arg2);
extern void McuExt_TrustedPerformReset(void);
extern void CDD_BswFit_SafeMemUpdate(void);
extern Std_ReturnType CDD_FitManager_SupervisorCallFaultInjectionHandler(uint8 Arg1,uint8 Arg2,uint8 Arg3,uint8* Arg4);
extern uint8 EcuAppM_SafeGroupStateChangeRequestProcessing(uint8 Arg1,uint8 Arg2);
extern Std_ReturnType IoHwAb_PwmSetDuty(IoHwAb_PwmSignalIdType Arg1,uint16 Arg2,IoHwAb_ErrorType* Arg3);
extern Std_ReturnType IoHwAb_PwmSetDutyAndPeriod(IoHwAb_PwmSignalIdType Arg1,uint32 Arg2,uint16 Arg3,IoHwAb_ErrorType* Arg4);
extern Std_ReturnType IoHwAb_GetProcessedAdc(IoHwAb_AdcSignalIdType Arg1,sint32* Arg2,IoHwAb_ErrorType* Arg3);
extern Std_ReturnType OsTrustedCall_IoHwAb_SetOutputPin(IoHwAb_DOutSignalIdType Arg1,boolean Arg2,IoHwAb_ErrorType* Arg3);
extern void OsTrustedCall_IoHwAb_SetOutputPin_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
extern void OsTrustedCall_EcuMExt_McuSetMode(Mcu_ModeType Arg1);
extern void OsTrustedCall_EcuMExt_McuSetMode_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
extern uint8 OsTrustedCall_EcuMExt_EnableInterruptSource(ISRType Arg1,boolean Arg2);
extern void OsTrustedCall_EcuMExt_EnableInterruptSource_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
extern void OsTrustedCall_McuExt_TrustedPerformReset(void);
extern void OsTrustedCall_McuExt_TrustedPerformReset_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
extern void OsTrustedCall_CDD_BswFit_SafeMemUpdate(void);
extern void OsTrustedCall_CDD_BswFit_SafeMemUpdate_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
extern Std_ReturnType OsTrustedCall_CDD_FitManager_SupervisorCallFaultInjectionHandler(uint8 Arg1,uint8 Arg2,uint8 Arg3,uint8* Arg4);
extern void OsTrustedCall_CDD_FitManager_SupervisorCallFaultInjectionHandler_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
extern uint8 OsTrustedCall_EcuAppM_SafeGroupStateChangeRequestProcessing(uint8 Arg1,uint8 Arg2);
extern void OsTrustedCall_EcuAppM_SafeGroupStateChangeRequestProcessing_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
extern Std_ReturnType OsTrustedCall_IoHwAb_PwmSetDuty(IoHwAb_PwmSignalIdType Arg1,uint16 Arg2,IoHwAb_ErrorType* Arg3);
extern void OsTrustedCall_IoHwAb_PwmSetDuty_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
extern Std_ReturnType OsTrustedCall_IoHwAb_PwmSetDutyAndPeriod(IoHwAb_PwmSignalIdType Arg1,uint32 Arg2,uint16 Arg3,IoHwAb_ErrorType* Arg4);
extern void OsTrustedCall_IoHwAb_PwmSetDutyAndPeriod_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
extern Std_ReturnType OsTrustedCall_IoHwAb_GetProcessedAdc(IoHwAb_AdcSignalIdType Arg1,sint32* Arg2,IoHwAb_ErrorType* Arg3);
extern void OsTrustedCall_IoHwAb_GetProcessedAdc_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);

#if(OS_CFG_MEMORY_PROTECTION == STD_ON)
extern const OsTrustedCallConfigType OsCfgTrustedCallConfig[OsNumberOfTrustedFns];
#endif

#endif    /* */


/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

