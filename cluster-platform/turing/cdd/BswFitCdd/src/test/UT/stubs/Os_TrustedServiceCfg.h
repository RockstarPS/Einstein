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

File Name        :  Os_TrustedServiceCfg.h
Module Short Name:  Os_TrustedServiceCfg.h
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef OS_TRUSTEDSERVICECFG_H
#define OS_TRUSTEDSERVICECFG_H


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/
                                                                              
#include "Adc_Types.h"
#include "Pwm_Types.h"
#include "Port.h"
#include "Rte_Type.h"
#include "Mcu_Types.h"
#include "OsTypes.h"
#include "Os_Cfg.h"
                                                                              
                                                                              
                                                                              
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

#endif    /* */
/* end of file */
/****************************************************************
Created Time: 7/30/2024 11:57:23 AM
****************************************************************/
