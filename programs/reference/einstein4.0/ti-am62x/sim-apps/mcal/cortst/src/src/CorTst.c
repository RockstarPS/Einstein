/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2025. Visteon Corporation owns all rights to           *
 * this work and intends to maintain it in confidence to preserve             *
 * its trade secret status. Visteon Corporation reserves the right,           *
 * under the copyright laws of the United States or those of any              *
 * other country that may have jurisdiction, to protect this work             *
 * as an unpublished work, in the event of an inadvertent or                  *
 * deliberate unauthorized publication. Visteon Corporation also              *
 * reserves its rights under all copyright laws to protect this               *
 * work as a published work, when appropriate. Those having access            *
 * to this work may not copy it, use it, modify it or disclose the            *
 * information contained in it without the written authorization              *
 * of Visteon Corporation.                                                    *
 *                                                                            *
 ******************************************************************************/
#ifndef CORTST_C
#define CORTST_C
/*!***************************************************************************
 * @ingroup
 * @file CorTst.c
 * @brief CorTst main layer which handles the Init, Mainfunctions and APIs for SWCs
 * ****************************************************************************/
/*****************************************************************************
 *  Include Files                                                             *
 ******************************************************************************/
#include "CorTst.h"
#include "AssertLib.h"
/*****************************************************************************
 *  Private Macros Definitions                                                **
 ******************************************************************************/
#define CORTSTJOBSTATE_IDLE           (boolean)0
/*MISRA C-2012 Rule 2.5 : CORTSTJOBSTATE_BUSY is used in obtaining test execution status. It will be used in future implementations*/
#define CORTSTJOBSTATE_BUSY           (boolean)1
#define CORTSTVALUE_ONE                     1U

/******************************************************************************
 *  Private Variable Definitions                                               *
 *******************************************************************************/
/*MISRA C-2012 Rule 2.5 : CORTST_START_SEC_VAR_INIT_UNSPECIFIED  is defined as per visteon standards. It will be used in MemMap.h file. It will not have any functional impact*/
#define CORTST_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
/**<  Initialize the status variable*/
static CorTst_StateType CorTst_State = CORTST_UNINIT;
static CorTst_StateType CorTst_WaitingState = CORTST_UNINIT;
static uint8 CorTst_CpuTestStatus = 0U;
static uint8 CorTst_MemoryInterfaceTestStatus = 0U;
static uint8 CorTst_AddressGenerationStatus = 0U;

static uint32 CorTst_BgndSignatureValue = 0UL;
static uint32 CorTst_FgndSignatureValue = 0UL;
/*MISRA C-2012 Rule 8.4 : cortst_memtest is declared as extern since it is used in Cortstcpu.asm file. It will not have any functional impact */
/*MISRA C-2012 Rule 8.7 : cortst_memtest is declared as extern since it is used in Cortstcpu.asm file. It will not have any functional impact */
uint32 cortst_memtest = 7UL; 
/*MISRA C-2012 Rule 2.5 : CORTST_STOP_SEC_VAR_INIT_UNSPECIFIED is defined as per visteon standards. It will be used in MemMap.h file. It will not have any functional impact*/
#define CORTST_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

/*MISRA C-2012 Rule 2.5 : CORTST_START_SEC_VAR_NOINIT_UNSPECIFIED is defined as per visteon standards. It will be used in MemMap.h file. It will not have any functional impact*/
#define CORTST_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
static Cortst_StateInfotype CorTst_Infoptr;
/*MISRA C-2012 Rule 2.5 : CORTST_STOP_SEC_VAR_NOINIT_UNSPECIFIED is defined as per visteon standards. It will be used in MemMap.h file. It will not have any functional impact*/
#define CORTST_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
/******************************************************************************
 *  Private Function Declaration                                                *
 *******************************************************************************/
static CorTst_ResultType CorTst_Process(CorTst_TestIdFgndType TestId,
                                        const CorTstSelect *TestPtr);
static CorTst_ResultType CorTst_TestALU(void);
static CorTst_ResultType CorTst_TestCoreRegister(void);
static void CorTst_ReportDetError(uint32 APIID, uint32 ErrorID);
static CorTst_ResultType CorTst_TestMemoryInterface(void);
static CorTst_ResultType CorTst_TestAddressGeneration(void);
/******************************************************************************
 *  Public Function Definitions                                                *
 *******************************************************************************/
/*MISRA C-2012 Rule 2.5 : CORTST_START_SEC_CODE is defined as per visteon standards. It will be used in MemMap.h file. It will not have any functional impact*/
#define CORTST_START_SEC_CODE
/*MISRA C-2012 Rule 20.1 : #include "MemMap.h" is used as per visteon standard. It will not have any functional Impact*/
#include "MemMap.h"
/**
 * This method initialize the CorTst module
 * @param     const CorTst_ConfigType *ConfigPtr
 * @return    void
 */
/*MISRA C-2012 Directive 4.5 : CORTST_INIT macro and CorTst_Init function were defined as per Autosar requirements. It will not have any functional impact*/
void CorTst_Init(const CorTst_ConfigType *ConfigPtr)
{

}
#if (CORTSTBGNDTESTNUMBER > 0U)
/**
 * This method is the main function for CorTst module
 * @param     none
 * @return    void
 */
void CorTst_MainFunction(void)
{

}

#endif /*#if (CORTSTBGNDTESTNUMBER > 0)*/

/**
 * This method De-initialize the CorTst module
 * @param     none
 * @return    void
 */
/*MISRA C-2012 Rule 8.7 : CorTst_Deinit is defined as per Autosar Requirement. It will be called in  other functions in future Implementations. It will not have any functional impact*/
void CorTst_DeInit(void)
{

}
#if (CORTST_ABORT_API == STD_ON)
/**
 * Service to change from CORTST_INIT to CORTST_ABORT state
 * @param     none
 * @return    void
 */
/*MISRA C-2012 Rule 8.7 : CorTst_Abort is defined as per Autosar Requirement. It will be called in  other functions in future Implementations. It will not have any functional impact*/
/*MISRA C-2012 Directive 4.5 : CORTST_ABORT macro and CorTst_Abort function were defined as per Autosar requirements. It will not have any functional impact*/
void CorTst_Abort(void)
{

}
#endif /*#if (CORTST_ABORT_API == STD_ON)*/

#if (CORTST_GET_STATE_API == STD_ON)
/**
 * Service for Core Test to immediately return status of CorTst module
 * @param     none
 * @return    CorTst_StateType
 */
/*MISRA C-2012 Rule 8.7 : CorTst_GetState is defined as per Autosar Requirement. It will be called in  other functions in future Implementations. It will not have any functional impact*/
CorTst_StateType CorTst_GetState(void)
{
    return CorTst_State;
}
#endif /*#if (CORTST_GET_STATE_API == STD_ON)*/
#if (CORTST_GET_CURRENT_STATUS_API == STD_ON)
/**
 * Service for Core Test to get indicator of the last executed Core Test result
 * @param     CorTst_ErrOkType *ErrOk
 * @return    void
 */
void CorTst_GetCurrentStatus(CorTst_ErrOkType *ErrOk)
{

}
#endif /*#if (CORTST_GET_CURRENT_STATUS_API == STD_ON)*/
#if (CORTST_GET_SIGNATURE_API == STD_ON)
/**
 * Service to get signature of the last executed Core Test in background mode.
 * @param     none
 * @return    CorTst_CsumSignatureBgndType
 */
/*MISRA C-2012 Rule 8.7 : CorTst_GetSignature is declared as per Autosarrequirement. It will not have any functional impact*/
CorTst_CsumSignatureBgndType CorTst_GetSignature(void)
{
	CorTst_CsumSignatureBgndType Fl_CortstRet;
    Fl_CortstRet.CorTstTestIntervalId = 0x0UL;
    Fl_CortstRet.SignatureValue = 0x0UL;

	return Fl_CortstRet;

}
#endif /*#if (CORTST_GET_SIGNATURE_API == STD_ON)*/
#if (CORTST_GET_FGND_SIGNATURE_API == STD_ON)
/**
 * Service to get signature of the last executed Core Test in foreground mode.
 * @param     none
 * @return    CorTst_CsumSignatureType
 */
/*MISRA C-2012 Rule 8.7 : CorTst_GetFgndSignature is declared as per Autosarrequirement. It will not have any functional impact*/
CorTst_CsumSignatureType CorTst_GetFgndSignature(void)
{
	CorTst_CsumSignatureType FgndSignatureValue = 0UL;

    return FgndSignatureValue;
}
#endif /*#if (CORTST_GET_FGND_SIGNATURE_API == STD_ON)*/
#if (CORTST_START_API == STD_ON)
/**
 * Service for executing foreground Core Test
 * @param     CorTst_TestIdFgndType TestId
 * @return    Std_ReturnType
 */
/*MISRA C-2012 Rule 8.7 : CorTst_Start is defined as per Autosar Requirement. It will be called in  other functions in future Implementations. It will not have any functional impact*/
Std_ReturnType CorTst_Start(CorTst_TestIdFgndType TestId)
{
    Std_ReturnType Retval = E_OK;

    return Retval;
}
#endif /*#if (CORTST_START_API == STD_ON)*/
#if (CORTST_VERSION_INFO_API == STD_ON)
/**
 * Service returns the version information of CorTst module
 * @param     Std_VersionInfoType *versioninfo
 * @return    void
 */
/*MISRA C-2012 Rule 8.7 : CorTst_GetVersionInfo is defined as per Autosar Requirement. It will be called in  other functions in future Implementations. It will not have any functional impact*/
void CorTst_GetVersionInfo(Std_VersionInfoType *versioninfo)
{

}
#endif /*#if (CORTST_VERSION_INFO_API == STD_ON)*/

#endif
