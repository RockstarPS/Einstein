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
*    @file Os_TrustedServiceCfg.c
*    @ingroup Os Configuration
*    @brief This is Os link time configuration source file. It contains definitions of link time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by SGOPAL1 at 2026-03-31 13:17:24.206449600
********************************************************************************************************************/


#ifndef OS_TRUSTEDSERVICECFG_C
#define OS_TRUSTEDSERVICECFG_C


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/

#include "Os_Lcfg.h"


#define OS_CORE_CODE_SEC_START
#define OS_CORE_CONST_SEC_START
#define OS_CORE_DATA_SEC_START
#define OS_CORE_DATA_NOCACHE_SEC_START
#define OS_CORE_BSS_SEC_START
#include "Os_IntMemMap.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
*****************************************************************************/
                                                                              
                                                                                
/*****************************************************************************
*                                 Type Declarations                          *
*****************************************************************************/

/* Argument Type Definition of SafeNvM_NvM_WriteCallback_Original*/
typedef struct
{
	uint8 Arg1;	//OsTrustedFunctionParam
	uint8 Arg2;	//OsTrustedFunctionParam1
	NvM_RequestResultType Arg3;	//OsTrustedFunctionParam2
}OsTrusted_SafeNvM_NvM_WriteCallback_OriginalPkgType;


/* Argument Type Definition of SafeNvM_NvM_WriteCallback_Copy1*/
typedef struct
{
	uint8 Arg1;	//OsTrustedFunctionParam
	uint8 Arg2;	//OsTrustedFunctionParam1
	NvM_RequestResultType Arg3;	//OsTrustedFunctionParam2
}OsTrusted_SafeNvM_NvM_WriteCallback_Copy1PkgType;


/* Argument Type Definition of SafeNvM_NvM_WriteCallback_Copy2*/
typedef struct
{
	uint8 Arg1;	//OsTrustedFunctionParam
	uint8 Arg2;	//OsTrustedFunctionParam1
	NvM_RequestResultType Arg3;	//OsTrustedFunctionParam2
}OsTrusted_SafeNvM_NvM_WriteCallback_Copy2PkgType;


/* Argument Type Definition of CDD_FitManager_SupervisorCallFaultInjectionHandler*/
typedef struct
{
	uint8 Arg1;	//OsTrustedFunctionParam
	uint8 Arg2;	//OsTrustedFunctionParam1
	uint8 Arg3;	//OsTrustedFunctionParam2
	uint8* Arg4;	//OsTrustedFunctionParam3
	Std_ReturnType* RetVal;	//Std_ReturnType
}OsTrusted_CDD_FitManager_SupervisorCallFaultInjectionHandlerPkgType;


/* Argument Type Definition of EcuAppM_SafeGroupStateChangeRequestProcessing*/
typedef struct
{
	uint8 Arg1;	//OsTrustedFunctionParam
	uint8 Arg2;	//OsTrustedFunctionParam1
	uint8* RetVal;	//uint8
}OsTrusted_EcuAppM_SafeGroupStateChangeRequestProcessingPkgType;


/* Argument Type Definition of FltM_ReportFault*/
typedef struct
{
	FltM_FaultIdType Arg1;	//OsTrustedFunctionParam
	eFltM_FaultStatusType Arg2;	//OsTrustedFunctionParam1
	uint8* Arg3;	//OsTrustedFunctionParam2
	uint16 Arg4;	//OsTrustedFunctionParam3
	Std_ReturnType* RetVal;	//Std_ReturnType
}OsTrusted_FltM_ReportFaultPkgType;


/* Argument Type Definition of CComAbsMdlSafeRxCan_SignalMissingProcessingControl*/
typedef struct
{
	tRxSafeSignalId Arg1;	//OsTrustedFunctionParam
	boolean Arg2;	//OsTrustedFunctionParam1
}OsTrusted_CComAbsMdlSafeRxCan_SignalMissingProcessingControlPkgType;


/* Argument Type Definition of IoHwAb_SetOutputPin*/
typedef struct
{
	IoHwAb_DOutSignalIdType Arg1;	//OsTrustedFunctionParam
	boolean Arg2;	//OsTrustedFunctionParam1
	IoHwAb_ErrorType* Arg3;	//OsTrustedFunctionParam2
	Std_ReturnType* RetVal;	//Std_ReturnType
}OsTrusted_IoHwAb_SetOutputPinPkgType;



/* Local UnPacker for Calling the Trusted Function SafeNvM_NvM_WriteCallback_Original */
void OsTrustedCall_SafeNvM_NvM_WriteCallback_Original_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)
{
	(void)FunctionIndex;
	OsTrusted_SafeNvM_NvM_WriteCallback_OriginalPkgType *pPkg;
	pPkg = (OsTrusted_SafeNvM_NvM_WriteCallback_OriginalPkgType*)FunctionParams;
	
	SafeNvM_NvM_WriteCallback_Original
	(
	pPkg->Arg1,
	pPkg->Arg2,
	pPkg->Arg3
	);
}
/* Local UnPacker for Calling the Trusted Function SafeNvM_NvM_WriteCallback_Copy1 */
void OsTrustedCall_SafeNvM_NvM_WriteCallback_Copy1_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)
{
	(void)FunctionIndex;
	OsTrusted_SafeNvM_NvM_WriteCallback_Copy1PkgType *pPkg;
	pPkg = (OsTrusted_SafeNvM_NvM_WriteCallback_Copy1PkgType*)FunctionParams;
	
	SafeNvM_NvM_WriteCallback_Copy1
	(
	pPkg->Arg1,
	pPkg->Arg2,
	pPkg->Arg3
	);
}
/* Local UnPacker for Calling the Trusted Function SafeNvM_NvM_WriteCallback_Copy2 */
void OsTrustedCall_SafeNvM_NvM_WriteCallback_Copy2_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)
{
	(void)FunctionIndex;
	OsTrusted_SafeNvM_NvM_WriteCallback_Copy2PkgType *pPkg;
	pPkg = (OsTrusted_SafeNvM_NvM_WriteCallback_Copy2PkgType*)FunctionParams;
	
	SafeNvM_NvM_WriteCallback_Copy2
	(
	pPkg->Arg1,
	pPkg->Arg2,
	pPkg->Arg3
	);
}
/* Local UnPacker for Calling the Trusted Function SafeNvM_TriggerDataCompare */
void OsTrustedCall_SafeNvM_TriggerDataCompare_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)
{
	(void)FunctionIndex;
	SafeNvM_TriggerDataCompare();
}
/* Local UnPacker for Calling the Trusted Function CDD_BswFit_SafeMemUpdate */
void OsTrustedCall_CDD_BswFit_SafeMemUpdate_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)
{
	(void)FunctionIndex;
	CDD_BswFit_SafeMemUpdate();
}
/* Local UnPacker for Calling the Trusted Function CDD_FitManager_SupervisorCallFaultInjectionHandler */
void OsTrustedCall_CDD_FitManager_SupervisorCallFaultInjectionHandler_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)
{
	(void)FunctionIndex;
	OsTrusted_CDD_FitManager_SupervisorCallFaultInjectionHandlerPkgType *pPkg;
	pPkg = (OsTrusted_CDD_FitManager_SupervisorCallFaultInjectionHandlerPkgType*)FunctionParams;
	
	*(pPkg->RetVal) = CDD_FitManager_SupervisorCallFaultInjectionHandler
	(
	pPkg->Arg1,
	pPkg->Arg2,
	pPkg->Arg3,
	pPkg->Arg4
	);
}
/* Local UnPacker for Calling the Trusted Function EcuAppM_SafeGroupStateChangeRequestProcessing */
void OsTrustedCall_EcuAppM_SafeGroupStateChangeRequestProcessing_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)
{
	(void)FunctionIndex;
	OsTrusted_EcuAppM_SafeGroupStateChangeRequestProcessingPkgType *pPkg;
	pPkg = (OsTrusted_EcuAppM_SafeGroupStateChangeRequestProcessingPkgType*)FunctionParams;
	
	*(pPkg->RetVal) = EcuAppM_SafeGroupStateChangeRequestProcessing
	(
	pPkg->Arg1,
	pPkg->Arg2
	);
}
/* Local UnPacker for Calling the Trusted Function FltM_ReportFault */
void OsTrustedCall_FltM_ReportFault_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)
{
	(void)FunctionIndex;
	OsTrusted_FltM_ReportFaultPkgType *pPkg;
	pPkg = (OsTrusted_FltM_ReportFaultPkgType*)FunctionParams;
	
	*(pPkg->RetVal) = FltM_ReportFault
	(
	pPkg->Arg1,
	pPkg->Arg2,
	pPkg->Arg3,
	pPkg->Arg4
	);
}
/* Local UnPacker for Calling the Trusted Function CComAbsMdlSafeRxCan_SignalMissingProcessingControl */
void OsTrustedCall_CComAbsMdlSafeRxCan_SignalMissingProcessingControl_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)
{
	(void)FunctionIndex;
	OsTrusted_CComAbsMdlSafeRxCan_SignalMissingProcessingControlPkgType *pPkg;
	pPkg = (OsTrusted_CComAbsMdlSafeRxCan_SignalMissingProcessingControlPkgType*)FunctionParams;
	
	CComAbsMdlSafeRxCan_SignalMissingProcessingControl
	(
	pPkg->Arg1,
	pPkg->Arg2
	);
}
/* Local UnPacker for Calling the Trusted Function IoHwAb_SetOutputPin */
void OsTrustedCall_IoHwAb_SetOutputPin_Unpacker(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)
{
	(void)FunctionIndex;
	OsTrusted_IoHwAb_SetOutputPinPkgType *pPkg;
	pPkg = (OsTrusted_IoHwAb_SetOutputPinPkgType*)FunctionParams;
	
	*(pPkg->RetVal) = IoHwAb_SetOutputPin
	(
	pPkg->Arg1,
	pPkg->Arg2,
	pPkg->Arg3
	);
}

/* Global Packer for Calling the Trusted Function SafeNvM_NvM_WriteCallback_Original */
void OsTrustedCall_SafeNvM_NvM_WriteCallback_Original
(
    uint8 Arg1,
    uint8 Arg2,
    NvM_RequestResultType Arg3
)
{
	OsTrusted_SafeNvM_NvM_WriteCallback_OriginalPkgType Pkg;
	Pkg.Arg1 = Arg1;
	Pkg.Arg2 = Arg2;
	Pkg.Arg3 = Arg3;
	
	(void)CallTrustedFunction(OS_CFG_TRUSTED_CALL_ID_0,(TrustedFunctionParameterRefType)&Pkg);
}


/* Global Packer for Calling the Trusted Function SafeNvM_NvM_WriteCallback_Copy1 */
void OsTrustedCall_SafeNvM_NvM_WriteCallback_Copy1
(
    uint8 Arg1,
    uint8 Arg2,
    NvM_RequestResultType Arg3
)
{
	OsTrusted_SafeNvM_NvM_WriteCallback_Copy1PkgType Pkg;
	Pkg.Arg1 = Arg1;
	Pkg.Arg2 = Arg2;
	Pkg.Arg3 = Arg3;
	
	(void)CallTrustedFunction(OS_CFG_TRUSTED_CALL_ID_1,(TrustedFunctionParameterRefType)&Pkg);
}


/* Global Packer for Calling the Trusted Function SafeNvM_NvM_WriteCallback_Copy2 */
void OsTrustedCall_SafeNvM_NvM_WriteCallback_Copy2
(
    uint8 Arg1,
    uint8 Arg2,
    NvM_RequestResultType Arg3
)
{
	OsTrusted_SafeNvM_NvM_WriteCallback_Copy2PkgType Pkg;
	Pkg.Arg1 = Arg1;
	Pkg.Arg2 = Arg2;
	Pkg.Arg3 = Arg3;
	
	(void)CallTrustedFunction(OS_CFG_TRUSTED_CALL_ID_2,(TrustedFunctionParameterRefType)&Pkg);
}


/* Global Packer for Calling the Trusted Function SafeNvM_TriggerDataCompare */
void OsTrustedCall_SafeNvM_TriggerDataCompare(void)
{
	 #if(OS_CFG_MEMORY_PROTECTION == STD_ON)
	 (void)CallTrustedFunction(OS_CFG_TRUSTED_CALL_ID_3,NULL_PTR);
	 #endif
}
/* Global Packer for Calling the Trusted Function CDD_BswFit_SafeMemUpdate */
void OsTrustedCall_CDD_BswFit_SafeMemUpdate(void)
{
	 #if(OS_CFG_MEMORY_PROTECTION == STD_ON)
	 (void)CallTrustedFunction(OS_CFG_TRUSTED_CALL_ID_4,NULL_PTR);
	 #endif
}
/* Global Packer for Calling the Trusted Function CDD_FitManager_SupervisorCallFaultInjectionHandler */
Std_ReturnType OsTrustedCall_CDD_FitManager_SupervisorCallFaultInjectionHandler
(
    uint8 Arg1,
    uint8 Arg2,
    uint8 Arg3,
    uint8* Arg4
)
{
	OsTrusted_CDD_FitManager_SupervisorCallFaultInjectionHandlerPkgType Pkg;
	Std_ReturnType fl_RetVal;
	Pkg.RetVal = &fl_RetVal;
	Pkg.Arg1 = Arg1;
	Pkg.Arg2 = Arg2;
	Pkg.Arg3 = Arg3;
	Pkg.Arg4 = Arg4;
	
	(void)CallTrustedFunction(OS_CFG_TRUSTED_CALL_ID_5,(TrustedFunctionParameterRefType)&Pkg);
	return fl_RetVal;
}


/* Global Packer for Calling the Trusted Function EcuAppM_SafeGroupStateChangeRequestProcessing */
uint8 OsTrustedCall_EcuAppM_SafeGroupStateChangeRequestProcessing
(
    uint8 Arg1,
    uint8 Arg2
)
{
	OsTrusted_EcuAppM_SafeGroupStateChangeRequestProcessingPkgType Pkg;
	uint8 fl_RetVal;
	Pkg.RetVal = &fl_RetVal;
	Pkg.Arg1 = Arg1;
	Pkg.Arg2 = Arg2;
	
	(void)CallTrustedFunction(OS_CFG_TRUSTED_CALL_ID_6,(TrustedFunctionParameterRefType)&Pkg);
	return fl_RetVal;
}


/* Global Packer for Calling the Trusted Function FltM_ReportFault */
Std_ReturnType OsTrustedCall_FltM_ReportFault
(
    FltM_FaultIdType Arg1,
    eFltM_FaultStatusType Arg2,
    uint8* Arg3,
    uint16 Arg4
)
{
	OsTrusted_FltM_ReportFaultPkgType Pkg;
	Std_ReturnType fl_RetVal;
	Pkg.RetVal = &fl_RetVal;
	Pkg.Arg1 = Arg1;
	Pkg.Arg2 = Arg2;
	Pkg.Arg3 = Arg3;
	Pkg.Arg4 = Arg4;
	
	(void)CallTrustedFunction(OS_CFG_TRUSTED_CALL_ID_7,(TrustedFunctionParameterRefType)&Pkg);
	return fl_RetVal;
}


/* Global Packer for Calling the Trusted Function CComAbsMdlSafeRxCan_SignalMissingProcessingControl */
void OsTrustedCall_CComAbsMdlSafeRxCan_SignalMissingProcessingControl
(
    tRxSafeSignalId Arg1,
    boolean Arg2
)
{
	OsTrusted_CComAbsMdlSafeRxCan_SignalMissingProcessingControlPkgType Pkg;
	Pkg.Arg1 = Arg1;
	Pkg.Arg2 = Arg2;
	
	(void)CallTrustedFunction(OS_CFG_TRUSTED_CALL_ID_8,(TrustedFunctionParameterRefType)&Pkg);
}


/* Global Packer for Calling the Trusted Function IoHwAb_SetOutputPin */
Std_ReturnType OsTrustedCall_IoHwAb_SetOutputPin
(
    IoHwAb_DOutSignalIdType Arg1,
    boolean Arg2,
    IoHwAb_ErrorType* Arg3
)
{
	OsTrusted_IoHwAb_SetOutputPinPkgType Pkg;
	Std_ReturnType fl_RetVal;
	Pkg.RetVal = &fl_RetVal;
	Pkg.Arg1 = Arg1;
	Pkg.Arg2 = Arg2;
	Pkg.Arg3 = Arg3;
	
	(void)CallTrustedFunction(OS_CFG_TRUSTED_CALL_ID_9,(TrustedFunctionParameterRefType)&Pkg);
	return fl_RetVal;
}



#if(OS_CFG_MEMORY_PROTECTION == STD_ON)
const OsTrustedCallConfigType OsCfgTrustedCallConfig[OsNumberOfTrustedFns] =
{
	{
		/*Service						= */ (TrustedFunctionType)OsTrustedCall_SafeNvM_NvM_WriteCallback_Original_Unpacker,
		/*OsAppConfigRefType			= */ (OsAppConfigRefType)&OsAppConfig_TrustedSystem,
		/*Context						= */ osdCtxTask
	},
	{
		/*Service						= */ (TrustedFunctionType)OsTrustedCall_SafeNvM_NvM_WriteCallback_Copy1_Unpacker,
		/*OsAppConfigRefType			= */ (OsAppConfigRefType)&OsAppConfig_TrustedSystem,
		/*Context						= */ osdCtxTask
	},
	{
		/*Service						= */ (TrustedFunctionType)OsTrustedCall_SafeNvM_NvM_WriteCallback_Copy2_Unpacker,
		/*OsAppConfigRefType			= */ (OsAppConfigRefType)&OsAppConfig_TrustedSystem,
		/*Context						= */ osdCtxTask
	},
	{
		/*Service						= */ (TrustedFunctionType)OsTrustedCall_SafeNvM_TriggerDataCompare_Unpacker,
		/*OsAppConfigRefType			= */ (OsAppConfigRefType)&OsAppConfig_TrustedSystem,
		/*Context						= */ osdCtxTask
	},
	{
		/*Service						= */ (TrustedFunctionType)OsTrustedCall_CDD_BswFit_SafeMemUpdate_Unpacker,
		/*OsAppConfigRefType			= */ (OsAppConfigRefType)&OsAppConfig_TrustedSystem,
		/*Context						= */ osdCtxTask
	},
	{
		/*Service						= */ (TrustedFunctionType)OsTrustedCall_CDD_FitManager_SupervisorCallFaultInjectionHandler_Unpacker,
		/*OsAppConfigRefType			= */ (OsAppConfigRefType)&OsAppConfig_TrustedSystem,
		/*Context						= */ osdCtxTask
	},
	{
		/*Service						= */ (TrustedFunctionType)OsTrustedCall_EcuAppM_SafeGroupStateChangeRequestProcessing_Unpacker,
		/*OsAppConfigRefType			= */ (OsAppConfigRefType)&OsAppConfig_TrustedSystem,
		/*Context						= */ osdCtxTask
	},
	{
		/*Service						= */ (TrustedFunctionType)OsTrustedCall_FltM_ReportFault_Unpacker,
		/*OsAppConfigRefType			= */ (OsAppConfigRefType)&OsAppConfig_TrustedSystem,
		/*Context						= */ osdCtxTask
	},
	{
		/*Service						= */ (TrustedFunctionType)OsTrustedCall_CComAbsMdlSafeRxCan_SignalMissingProcessingControl_Unpacker,
		/*OsAppConfigRefType			= */ (OsAppConfigRefType)&OsAppConfig_TrustedSystem,
		/*Context						= */ osdCtxTask
	},
	{
		/*Service						= */ (TrustedFunctionType)OsTrustedCall_IoHwAb_SetOutputPin_Unpacker,
		/*OsAppConfigRefType			= */ (OsAppConfigRefType)&OsAppConfig_TrustedSystem,
		/*Context						= */ osdCtxTask
	}
};
#endif


#define OS_CORE_CODE_SEC_END
#define OS_CORE_CONST_SEC_END
#define OS_CORE_DATA_SEC_END
#define OS_CORE_DATA_NOCACHE_SEC_END
#define OS_CORE_BSS_SEC_END
#include "Os_IntMemMap.h"


#endif    /* */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

