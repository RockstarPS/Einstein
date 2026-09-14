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
*    @file Os_TrustedServiceLcfg.h
*    @ingroup Os Configuration
*    @brief This is Os Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by SGOPAL1 at 2026-03-31 13:17:24.194759200
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


extern void SafeNvM_NvM_WriteCallback_Original(uint8 Arg1,uint8 Arg2,NvM_RequestResultType Arg3);
extern void SafeNvM_NvM_WriteCallback_Copy1(uint8 Arg1,uint8 Arg2,NvM_RequestResultType Arg3);
extern void SafeNvM_NvM_WriteCallback_Copy2(uint8 Arg1,uint8 Arg2,NvM_RequestResultType Arg3);
extern void SafeNvM_TriggerDataCompare(void);
extern void CDD_BswFit_SafeMemUpdate(void);
extern Std_ReturnType CDD_FitManager_SupervisorCallFaultInjectionHandler(uint8 Arg1,uint8 Arg2,uint8 Arg3,uint8* Arg4);
extern uint8 EcuAppM_SafeGroupStateChangeRequestProcessing(uint8 Arg1,uint8 Arg2);
extern Std_ReturnType FltM_ReportFault(FltM_FaultIdType Arg1,eFltM_FaultStatusType Arg2,uint8* Arg3,uint16 Arg4);
extern void CComAbsMdlSafeRxCan_SignalMissingProcessingControl(tRxSafeSignalId Arg1,boolean Arg2);
extern Std_ReturnType IoHwAb_SetOutputPin(IoHwAb_DOutSignalIdType Arg1,boolean Arg2,IoHwAb_ErrorType* Arg3);
extern void OsTrustedCall_SafeNvM_NvM_WriteCallback_Original(uint8 Arg1,uint8 Arg2,NvM_RequestResultType Arg3);
extern void OsTrustedCall_SafeNvM_NvM_WriteCallback_Original_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
extern void OsTrustedCall_SafeNvM_NvM_WriteCallback_Copy1(uint8 Arg1,uint8 Arg2,NvM_RequestResultType Arg3);
extern void OsTrustedCall_SafeNvM_NvM_WriteCallback_Copy1_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
extern void OsTrustedCall_SafeNvM_NvM_WriteCallback_Copy2(uint8 Arg1,uint8 Arg2,NvM_RequestResultType Arg3);
extern void OsTrustedCall_SafeNvM_NvM_WriteCallback_Copy2_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
extern void OsTrustedCall_SafeNvM_TriggerDataCompare(void);
extern void OsTrustedCall_SafeNvM_TriggerDataCompare_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
extern void OsTrustedCall_CDD_BswFit_SafeMemUpdate(void);
extern void OsTrustedCall_CDD_BswFit_SafeMemUpdate_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
extern Std_ReturnType OsTrustedCall_CDD_FitManager_SupervisorCallFaultInjectionHandler(uint8 Arg1,uint8 Arg2,uint8 Arg3,uint8* Arg4);
extern void OsTrustedCall_CDD_FitManager_SupervisorCallFaultInjectionHandler_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
extern uint8 OsTrustedCall_EcuAppM_SafeGroupStateChangeRequestProcessing(uint8 Arg1,uint8 Arg2);
extern void OsTrustedCall_EcuAppM_SafeGroupStateChangeRequestProcessing_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
extern Std_ReturnType OsTrustedCall_FltM_ReportFault(FltM_FaultIdType Arg1,eFltM_FaultStatusType Arg2,uint8* Arg3,uint16 Arg4);
extern void OsTrustedCall_FltM_ReportFault_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
extern void OsTrustedCall_CComAbsMdlSafeRxCan_SignalMissingProcessingControl(tRxSafeSignalId Arg1,boolean Arg2);
extern void OsTrustedCall_CComAbsMdlSafeRxCan_SignalMissingProcessingControl_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
extern Std_ReturnType OsTrustedCall_IoHwAb_SetOutputPin(IoHwAb_DOutSignalIdType Arg1,boolean Arg2,IoHwAb_ErrorType* Arg3);
extern void OsTrustedCall_IoHwAb_SetOutputPin_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);

#if(OS_CFG_MEMORY_PROTECTION == STD_ON)
extern const OsTrustedCallConfigType OsCfgTrustedCallConfig[OsNumberOfTrustedFns];
#endif

#endif    /* */


/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

