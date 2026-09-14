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
#define CORTSTJOBSTATE_IDLE           		0U
/*MISRA C-2012 Rule 2.5 : CORTSTJOBSTATE_BUSY is used in obtaining test execution status. It will be used in future implementations*/
#define CORTSTJOBSTATE_BUSY           		1U
#define CORTSTVALUE_ONE                     1U
#define CORTST_UINT32_MAX                   (0xFFFFFFFFu)
#define CORTST_UINT8_MAX 					(0xFFu)
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

static uint32 CorTst_BgndSignatureValue = 0U;
static uint32 CorTst_FgndSignatureValue = 0U;
/*MISRA C-2012 Rule 8.4 : cortst_memtest is declared as extern since it is used in Cortstcpu.asm file. It will not have any functional impact */
/*MISRA C-2012 Rule 8.7 : cortst_memtest is declared as extern since it is used in Cortstcpu.asm file. It will not have any functional impact */
uint32 cortst_memtest = 7U; 
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
static void CorTst_ReportDetError(uint8 APIID, uint8 ErrorID);
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
    if ((CORTST_UNINIT == CorTst_State) && (NULL_PTR != ConfigPtr))
    {
        CorTst_Infoptr.AtomicIntervalCount = 0U;
		CorTst_BgndSignatureValue = 0U;
		CorTst_FgndSignatureValue = 0U;
        CorTst_Infoptr.BgndExeStatus = CORTSTJOBSTATE_IDLE;
        if (CORTSTBGNDTESTNUMBER > 0U)
        {
            CorTst_Infoptr.CurrentBgndBlockID =
                ConfigPtr->CorTstBlockBgnd[0].testId;
        }
        else
        {
			/*MISRA C-2012 Rule 14.3 : Value of CORTSTBGNDTESTNUMBER is configurable and it can be configured to 0 in future Implementations. It will not have any functional impact*/
            CorTst_Infoptr.CurrentBgndBlockID = 0U;
        }
        CorTst_Infoptr.CurrentTestIntervalId = 0U;
        CorTst_Infoptr.OverallBngResultBuffer = CORTST_E_NOT_TESTED;
        CorTst_Infoptr.ResultBuffer = CORTST_E_NOT_TESTED;
        CorTst_State = CORTST_INIT;
    }
    else
    {
        CorTst_ReportDetError(CORTST_API_INIT, CORTST_E_ALREADY_INITIALIZED);
    }
}
#if (CORTSTBGNDTESTNUMBER > 0U)
/**
 * This method is the main function for CorTst module
 * @param     none
 * @return    void
 */
void CorTst_MainFunction(void)
{
	const CorTstSelect *BgndTestPtr;
	CorTst_ErrOkType ResultOfLastCorTstRun;
	CorTst_TestIdFgndType lastBlockId = CorTstBlockBgnd[CORTSTBGNDTESTNUMBER
										- CORTSTVALUE_ONE].testId;
	CorTst_ResultType CorTstStatus = CORTST_E_OKAY;
	static uint32 atomiccounter = 0U;
	static uint32 CorTstIndex = 0U;
	CorTst_TestIdFgndType TestId = 0x0U;

	if(CORTST_INIT == CorTst_State)
	{
		CorTst_State = CORTST_RUNNING_BGND;
		TestId = CorTst_Infoptr.CurrentBgndBlockID;
		for (CorTstIndex = 0; CorTstIndex < CORTSTBGNDTESTNUMBER; CorTstIndex++)
		{
			if (TestId == CorTstBlockBgnd[CorTstIndex].testId)
			{
				BgndTestPtr = &CorTstBlockBgnd[CorTstIndex];
				CorTstStatus = CorTst_Process(TestId, BgndTestPtr);
				if (CorTstNumberconfigurationAtomic <= atomiccounter)
				{
					CorTst_Infoptr.AtomicIntervalCount++;
				}
				else
				{
					atomiccounter++;
				}
			}
			if (CORTST_E_NOT_OK != CorTst_Infoptr.OverallBngResultBuffer)
			{
				CorTst_Infoptr.OverallBngResultBuffer = CorTstStatus;
			}
		}
		CorTst_State = CORTST_INIT;

		if (CORTST_E_OKAY == CorTstStatus)
		{
			/*DEM PASS*/
		}
		else
		{
			/*DEM FAILED*/
		}
		if (lastBlockId == TestId)
		{
			if (CorTstTestIntervalIdEndValue
					!= CorTst_Infoptr.CurrentTestIntervalId)
			{
				CorTst_Infoptr.CurrentTestIntervalId++;
			}
			else
			{
				CorTst_Infoptr.CurrentTestIntervalId = 0U;
				CorTst_Infoptr.AtomicIntervalCount = 0U;
				CorTst_BgndSignatureValue = 0U;
			}
			CorTst_Infoptr.CurrentBgndBlockID = CorTstBlockBgnd[0].testId;
			#if (CORTSTNOTIFICATIONSUPPORTED == STD_ON)
			/* call the callback notifications */
				if (NULL_PTR != CorTstBlock.CorTst_TestCompletedNotification)
			{
				ResultOfLastCorTstRun.CorTstTestIntervalId =
					CorTst_Infoptr.CurrentTestIntervalId;
				ResultOfLastCorTstRun.returnvalue =
					CorTst_Infoptr.OverallBngResultBuffer;
					CorTstBlock.CorTst_TestCompletedNotification(ResultOfLastCorTstRun);
			}
			#endif /* (CORTSTNOTIFICATIONSUPPORTED == STD_ON) */
		}
		else
		{
            if(CORTSTBGNDTESTNUMBER > (CorTstIndex + CORTSTVALUE_ONE))
            {
                    CorTst_Infoptr.CurrentBgndBlockID = CorTstBlockBgnd[CorTstIndex + CORTSTVALUE_ONE].testId;
            }
            else
            {
                DEBUG_ASSERT( FALSE );
            }
		}
		if (CORTST_ABORT == CorTst_WaitingState)
		{
			if (CORTSTVALUE_ONE == CorTst_Infoptr.AtomicIntervalCount)
			{
				CorTst_State = CorTst_WaitingState;
			}
		}
	}
	else
	{
		CorTst_ReportDetError(CORTST_API_MAINFUNCTION, CORTST_E_UNINIT);
	}
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
	if(CORTST_INIT == CorTst_State)
	{
		CorTst_BgndSignatureValue = 0U;
		CorTst_FgndSignatureValue = 0U;
		CorTst_Infoptr.AtomicIntervalCount = 0U;
		CorTst_Infoptr.BgndExeStatus = CORTSTJOBSTATE_IDLE;
		if (CORTSTBGNDTESTNUMBER > 0U)
		{
			CorTst_Infoptr.CurrentBgndBlockID = CorTstBlockBgnd[0].testId;
		}
		else
		{
			/*MISRA C-2012 Rule 14.3 : Value of CORTSTBGNDTESTNUMBER is configurable and it can be configured to 0 in future Implementations. It will not have any functional impact*/
			CorTst_Infoptr.CurrentBgndBlockID = 0U;
		}
		CorTst_Infoptr.CurrentTestIntervalId = 0U;
		CorTst_Infoptr.OverallBngResultBuffer = CORTST_E_NOT_TESTED;
		CorTst_Infoptr.ResultBuffer = CORTST_E_NOT_TESTED;
		CorTst_State = CORTST_UNINIT;
	}
	else
	{
		CorTst_ReportDetError(CORTST_API_DEINIT, CORTST_E_UNINIT);
	}
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
    if ((CORTST_INIT == CorTst_State) || (CORTST_RUNNING_BGND == CorTst_State))
    {
        if ((CORTSTVALUE_ONE == CorTst_Infoptr.AtomicIntervalCount)
                || (CORTST_INIT == CorTst_State))
        {
            CorTst_State = CORTST_ABORT;
            CorTst_Infoptr.OverallBngResultBuffer = CORTST_E_NOT_TESTED;
        }
        else
        {
            CorTst_WaitingState = CORTST_ABORT;
        }
    }
	else
	{
		CorTst_ReportDetError(CORTST_API_ABORT, CORTST_E_UNINIT);
    }
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
	if((CORTST_INIT == CorTst_State) || (CORTST_RUNNING_BGND == CorTst_State))
	{
		if(NULL_PTR != ErrOk)
		{
			ErrOk->CorTstTestIntervalId = CorTst_Infoptr.CurrentTestIntervalId;
			ErrOk->returnvalue = CorTst_Infoptr.ResultBuffer;
		}
		else
		{
			CorTst_ReportDetError(CORTST_API_GET_CURRENT_STATUS, CORTST_E_PARAM_POINTER);
		}
	}
	else
	{
		CorTst_ReportDetError(CORTST_API_GET_CURRENT_STATUS, CORTST_E_UNINIT);
	}
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
    Fl_CortstRet.CorTstTestIntervalId = 0x0U;
    Fl_CortstRet.SignatureValue = 0x0U;
	if(CORTST_INIT == CorTst_State)
	{
	  Fl_CortstRet.SignatureValue = CorTst_BgndSignatureValue;
	  Fl_CortstRet.CorTstTestIntervalId = CorTst_Infoptr.CurrentTestIntervalId;
	}
	else
	{
		CorTst_ReportDetError(CORTST_API_GET_SIGNATURE, CORTST_E_UNINIT);
	}
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
	CorTst_CsumSignatureType FgndSignatureValue = 0U;
	if(CORTST_INIT == CorTst_State)
	{
		FgndSignatureValue = CorTst_FgndSignatureValue;
	}
	else
	{
		CorTst_ReportDetError(CORTST_API_GET_FGND_SIGNATURE, CORTST_E_UNINIT);
	}
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
    CorTst_ResultType CorTstStatus = CORTST_E_OKAY;
    const CorTstSelect *FgndTestPtr;
    uint32 fl_CortexIndex = 0U;
	if((CORTST_INIT == CorTst_State) || (CORTST_RUNNING_BGND == CorTst_State))
	{
		if (CORTST_RUNNING_BGND == CorTst_State)
		{
			CorTstStatus = CORTST_E_OKAY;
			CorTst_Infoptr.ResultBuffer = CORTST_E_NOT_TESTED;

		}
		else if (CORTSTFGNDTESTNUMBER < TestId)
		{
			CorTstStatus = CORTST_E_NOT_OK;
		}
		else
		{
			for (fl_CortexIndex = 0U; fl_CortexIndex < CORTSTFGNDTESTNUMBER; fl_CortexIndex++)
			{
				if (TestId == CorTstBlockFgnd[fl_CortexIndex].testId)
				{
					FgndTestPtr = &CorTstBlockFgnd[fl_CortexIndex];
					CorTstStatus = CorTst_Process(TestId, FgndTestPtr);
				}
			}
		}
		if (CORTST_E_OKAY == CorTstStatus)
		{
			Retval = E_OK;
			/*DEM PASS*/
		}
		else
		{
			Retval = E_NOT_OK;
			/*DEM FAILED*/
		}
	}
    else
    {
		CorTst_ReportDetError(CORTST_API_START, CORTST_E_UNINIT);
	}
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
	if(NULL_PTR != versioninfo)
	{

		versioninfo->vendorID         = (uint16)CORTST_VENDOR_ID;
        versioninfo->moduleID         = (uint16)CORTST_MODULE_ID;
        versioninfo->sw_major_version = (uint8)CORTST_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)CORTST_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)CORTST_SW_PATCH_VERSION;
	}
	else
	{
		CorTst_ReportDetError(CORTST_API_GET_VERSION_INFO, CORTST_E_PARAM_POINTER);
	}
}
#endif /*#if (CORTST_VERSION_INFO_API == STD_ON)*/

/******************************************************************************
 *  Private Function Definitions                                                *
 *******************************************************************************/
/**
 * Service to process the job
 * @param     CorTst_TestIdFgndType TestId, const CorTstSelect *TestPtr
 * @return    CorTst_ResultType
 */
static CorTst_ResultType CorTst_Process(CorTst_TestIdFgndType TestId,
                                        const CorTstSelect *TestPtr)
{
    (void)TestId;
    CorTst_ResultType ret = CORTST_E_OKAY;
    if (SELECTED == TestPtr->CorTstAlu)
    {
        ret = CorTst_TestALU();
    }
	if (CORTST_E_OKAY == ret)
    {
        if (SELECTED == TestPtr->CorTstMemoryIf)
        {
            ret = CorTst_TestMemoryInterface();
        }
    }
	if (CORTST_E_OKAY == ret)
    {
        if (SELECTED == TestPtr->CorTstAddress)
        {
			ret = CorTst_TestAddressGeneration();
		}
    }
    if (CORTST_E_OKAY == ret)
    {
        if (SELECTED == TestPtr->CorTstRegister)
        {
            ret = CorTst_TestCoreRegister();
        }
    }	
    else
    {
        ret = CORTST_E_NOT_OK;
    }
    CorTst_Infoptr.ResultBuffer = ret;
    return ret;
}
/**
 * Service to test cpu fail
 * @param     none
 * @return    voids
 */
/*MISRA C-2012 Rule 8.7 : Cortst_CpuTestFail is declared as extern as it is called in Cortstcpu.asm file. It will not have any functional Impact*/
void Cortst_CpuTestFail(void)
{
    if (CorTst_CpuTestStatus < CORTST_UINT8_MAX)
    {
        CorTst_CpuTestStatus++;
    }
}
/*MISRA C-2012 Rule 8.7 : Cortst_AddressGenerationFail is declared extern since it is used in Cortstcpu.asm file.*/
void Cortst_AddressGenerationFail(void)
{
	if(CorTst_AddressGenerationStatus < CORTST_UINT8_MAX)
	{
		CorTst_AddressGenerationStatus++;
	}
}

/*MISRA C-2012 Rule 8.7 : Cortst_MemoryInterfaceFail is declared extern since it is used in Cortstcpu.asm file*/
void Cortst_MemoryInterfaceFail(void)
{
	if(CorTst_MemoryInterfaceTestStatus < CORTST_UINT8_MAX)
	{
		CorTst_MemoryInterfaceTestStatus++;
	}
}
/**
* Service to test the ALU
* @param     none
* @return    CorTst_ResultType
*/
static CorTst_ResultType CorTst_TestALU(void)
{
    static uint8 fl_firstNumber = 2U;
    static uint8 fl_SecondNumber = 2U;
    CorTst_ResultType ret = CORTST_E_OKAY;
    if ((4U != (fl_firstNumber + fl_SecondNumber))||(0U != (fl_firstNumber - fl_SecondNumber))||(4U != (fl_firstNumber * fl_SecondNumber))||(1U != (fl_firstNumber / fl_SecondNumber))||(2U != ((fl_firstNumber + CORTSTVALUE_ONE) & fl_SecondNumber))||(3U != ((fl_firstNumber + CORTSTVALUE_ONE) | fl_SecondNumber)))
    {
        ret = CORTST_E_NOT_OK;
    }
    else
    {
        if(CORTST_RUNNING_BGND == CorTst_State)
        {
            CorTst_BgndSignatureValue = ((CorTst_BgndSignatureValue > (CORTST_UINT32_MAX - CORTST_ALU_SIGNATURE)) ?
                                         CORTST_ALU_SIGNATURE :
                                         (CorTst_BgndSignatureValue + CORTST_ALU_SIGNATURE));
        }
        else
        {
            CorTst_FgndSignatureValue = ((CorTst_FgndSignatureValue > (CORTST_UINT32_MAX - CORTST_ALU_SIGNATURE)) ?
                                         CORTST_ALU_SIGNATURE :
                                         (CorTst_FgndSignatureValue + CORTST_ALU_SIGNATURE));
        }
    }
    return ret;
}
/**
 * Service is test the cpu register
 * @param     none
 * @return    CorTst_ResultType
 */
static CorTst_ResultType CorTst_TestCoreRegister(void)
{
    CorTst_ResultType ret = CORTST_E_NOT_OK;
    CorTst_TestRegister();
    if (0U == CorTst_CpuTestStatus)
    {
        ret = CORTST_E_OKAY;
        if(CORTST_RUNNING_BGND == CorTst_State)
        {
            CorTst_BgndSignatureValue = ((CorTst_BgndSignatureValue > (CORTST_UINT32_MAX - CORTST_REGISTER_SIGNATURE)) ?
                                         CORTST_REGISTER_SIGNATURE :
                                         (CorTst_BgndSignatureValue + CORTST_REGISTER_SIGNATURE));
        }
        else
        {
            CorTst_FgndSignatureValue = ((CorTst_FgndSignatureValue > (CORTST_UINT32_MAX - CORTST_REGISTER_SIGNATURE)) ?
                                         CORTST_REGISTER_SIGNATURE :
                                         (CorTst_FgndSignatureValue + CORTST_REGISTER_SIGNATURE));
        }
    }
    return ret;
}
static CorTst_ResultType CorTst_TestMemoryInterface(void)
{
    CorTst_ResultType ret = CORTST_E_NOT_OK;
    CorTst_TestMemIf();
    if(0U == CorTst_MemoryInterfaceTestStatus)
    {
        ret = CORTST_E_OKAY;
        if(CORTST_RUNNING_BGND == CorTst_State)
        {
            CorTst_BgndSignatureValue = ((CorTst_BgndSignatureValue > (CORTST_UINT32_MAX - CORTST_MEMORYIF_SIGNATURE)) ?
                                         CORTST_MEMORYIF_SIGNATURE :
                                         (CorTst_BgndSignatureValue + CORTST_MEMORYIF_SIGNATURE));
        }
        else
        {
            CorTst_FgndSignatureValue = ((CorTst_FgndSignatureValue > (CORTST_UINT32_MAX - CORTST_MEMORYIF_SIGNATURE)) ?
                                         CORTST_MEMORYIF_SIGNATURE :
                                         (CorTst_FgndSignatureValue + CORTST_MEMORYIF_SIGNATURE));
        }
    }
    return ret;
}
static CorTst_ResultType CorTst_TestAddressGeneration(void)
{
    CorTst_ResultType ret = CORTST_E_NOT_OK;
    CorTst_TestAddrGeneration();
    if(0U == CorTst_AddressGenerationStatus)
    {
        ret = CORTST_E_OKAY;
        if(CORTST_RUNNING_BGND == CorTst_State)
        {
            CorTst_BgndSignatureValue = ((CorTst_BgndSignatureValue > (CORTST_UINT32_MAX - CORTST_ADDRESS_SIGNATURE)) ?
                                         CORTST_ADDRESS_SIGNATURE :
                                         (CorTst_BgndSignatureValue + CORTST_ADDRESS_SIGNATURE));
        }
        else
        {
            CorTst_FgndSignatureValue = ((CorTst_FgndSignatureValue > (CORTST_UINT32_MAX - CORTST_ADDRESS_SIGNATURE)) ?
                                         CORTST_ADDRESS_SIGNATURE :
                                         (CorTst_FgndSignatureValue + CORTST_ADDRESS_SIGNATURE));
        }
    }
    return ret;
}
/**
 * Service to report DET error
 * @param     uint8 APIID, uint8 ErrorID
 * @return    void
 */
static void CorTst_ReportDetError(uint8 APIID, uint8 ErrorID)
{
	/*MISRA C-2012 Rule 10.3 : Values of Cortst APIID were within the range of uint8. It will not have any functional impact*/
	/*MISRA C-2012 Rule 10.3 : ErrorID values used in cortst were within the range of uint8 only. It will not have any functional Impact*/
	(void)Det_ReportError(CORTST_MODULE_ID,CORTST_INSTANCE_ID,APIID,ErrorID);
}

/*MISRA C-2012 Rule 2.5 : CORTST_STOP_SEC_CODE  is defined as per visteon standards. It will be used in CorTst_MemMap.h file. It will not have any functional impact*/
#define CORTST_STOP_SEC_CODE
#include "MemMap.h"

#endif
/*End of File*/
/*****************************************************************************
 *  for each change to this file, be sure to record:                         *
 *     1.  who made the change and when the change was made                  *
 *     2.  why the change was made and the intended result                   *
 *  Following block needs to be repeated for each change
 ******************************************************************************
 *  Note: In the trace-ability column we need to trace back to the Design Doc.*
 *  For the initial version it is traced to the Design Document section.     *
 *  For further changes it shall trace to the source of the change which may *
 *  be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  *
 *  other reason                                                            *
 ******************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 24-02-2025                                            */
/*Version           :                                                       */
/*By                : kporkodi                                              */
/*Traceability      :                                                       */
/*Change Description: Proveout, Initial Version                             */
/*--------------------------------------------------------------------------*/


