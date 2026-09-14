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
#ifndef RAMTST_C
#define RAMTST_C
/*****************************************************************************
*  File Name         :  RamTst.c                                             *
*  Module Short Name :  RamTst                                               *
*  Description       :  RamTst main layer which handles the Init,            *
*                       Mainfunctions and APIs for SWCs                      *
*  Organization     :   Driver Information Software Section,                 *
*                       Visteon Software Operation                           *
*                       Visteon Corporation                                  *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  Clang Compiler                                         *
* Target Hardware  :  AM62PX micro based Hardware Platform                   *
*                                                                            *
******************************************************************************/
/*****************************************************************************
 *  Include Files                                                             *
 ******************************************************************************/
#include "RamTst.h"
#include "SchM_RamTst.h"
#include "AssertLib.h"
/*****************************************************************************
 *  Private Macros Definitions                                                **
 ******************************************************************************/
#define RamTstJOBSTATE_IDLE           (boolean)0
#define RamTstJOBSTATE_BUSY           (boolean)1
#define ATOMIC_NOOFCELL                4096UL
#define MARCH_1                  0xFFFFFFFFUL
#define MARCH_0 				0x00000000UL
#define MAX_HEX_32BIT   0xFFFFFFFFU
#define MAX_HEX_8BIT   0xFFU
#define VALUE_ONE_UL      1UL
#define VALUE_ONE_U       1U
/******************************************************************************
 *  Private Variable Definitions                                               *
 *******************************************************************************/
#define RAMTST_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

/**<  Initialize the status variable*/
static RamTst_ExecutionStatusType RamTst_State = RAMTST_EXECUTION_UNINIT;
static RamTst_ExecutionStatusType RamTst_WaitingState = RAMTST_EXECUTION_UNINIT;
static RamTst_TestModeType Mode = RAMTST_MODE_NONE;

#define RAMTST_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RAMTST_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

static RamTst_StateInfotype RamTst_Infoptr;
static uint8 RamTst_ReadNMIStatus;
static RamTst_TestOverallResultType FgndResult;
static RamTst_TestOverallResultType BgndResult;
static RamTstBlockParamstype AtomicBlockPtr;

#define RAMTST_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
/******************************************************************************
 *  Private Function Declaration                                                *
 *******************************************************************************/
static Std_ReturnType RamTst_preprocess(const RamTstBlockParamstype *RamTstBlockPtr);
static void RamTst_SaveSPCacheData(void);
static void RamTst_CacheDisable(void);
static void RamTst_CacheEnable(void);
static void RamTst_RestoreSPCacheData(void);
static void RamTst_ReportDetError(uint32 APIID, uint32 ErrorID);
/******************************************************************************
 *  Public Function Definitions                                                *
 *******************************************************************************/
#define RAMTST_START_SEC_CODE
#include "MemMap.h"
/**
 * This method initialize the RamTst module
 * @param     const RamTst_ConfigType *ConfigPtr - Pointer consisting of values for initializing the Ramtst component
 * @return    void
 */
void RamTst_Init(const RamTst_ConfigType *ConfigPtr)
{
	
}
/**
 * This method is the main function for RamTst module
 * @param     none
 * @return    void
 */
void RamTst_MainFunction(void)
{
	
}

/**
 * This method De-initialize the RamTst module
 * @param     none
 * @return    void
 */
void RamTst_DeInit(void)
{
 
}

/**
 * Service for stopping the RAM Test.
 * @param     none
 * @return    void
 */
void RamTst_Stop(void)
{
    
}
/**
 * Service for continuing the RAM Test after calling 'RamTst_Stop.
 * @param     none
 * @return    void
 */
void RamTst_Allow(void)
{
    
}
/**
 * Service for suspending current operation of background RAM Test,
 * @param     none
 * @return    void
 */
void RamTst_Suspend(void)
{
    
}
/**
 * Service for allowing to continue the background RAM Test
 * @param     none
 * @return    void
 */
void RamTst_Resume(void)
{

}
/**
 *Service returns the current RAM Test execution status.
 * @param     none
 * @return    RamTst_ExecutionStatusType
 */
RamTst_ExecutionStatusType RamTst_GetExecutionStatus(void)
{
    return RamTst_State;
}

/**
 * Service returns the version information of RamTst module
 * @param     Std_VersionInfoType *versioninfo - version info pointer
 * @return    void
 */
void RamTst_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
    (void)versioninfo;
}
/**
 * Service returns the current RAM Test result.
 * @param     none
 * @return    RamTst_TestResultType
 */
RamTst_TestResultType RamTst_GetTestResult(void)
{

}
/**
 * Service returns the current RAM Test result for the specified block.
 * @param     RamTst_NumberOfBlocksType BlockID - Block Id for which the test result per block to be obtained
 * @return    RamTst_TestResultType
 */
RamTst_TestResultType RamTst_GetTestResultPerBlock(
        RamTst_NumberOfBlocksType BlockID)
{
    RamTst_TestResultType Status = RAMTST_RESULT_UNDEFINED;

    return Status;
}
/**
 * Service returns the ID of the current RAM Test algorithm parameter set.
 * @param     none
 * @return    RamTst_AlgParamsIdType
 */
RamTst_AlgParamsIdType RamTst_GetAlgParams(void)
{
    RamTst_AlgParamsIdType ret = 0x0U;

    return ret;
}
/**
 * Service returns the current RAM Test algorithm.
 * @param     none
 * @return    RamTst_AlgorithmType
 */
RamTst_AlgorithmType RamTst_GetTestAlgorithm(void)
{
    RamTst_AlgorithmType ret = RAMTST_ALGORITHM_UNDEFINED;

    return ret;
}
/**
 * Service returns the current number of tested cells per main-function cycle
 * @param     none
 * @return    RamTst_NumberOfTestedCellsType
 */
RamTst_NumberOfTestedCellsType RamTst_GetNumberOfTestedCells(void)
{
    return RamTst_Infoptr.RamTst_NumberOfTestedCells;
}
/**
 * Service used to set the test algorithm and its parameter set.
 * @param     RamTst_AlgParamsIdType NewAlgParamsId - Parameter set Id to be assigned as new
 * @return    void
 */
void RamTst_SelectAlgParams(RamTst_AlgParamsIdType NewAlgParamsId)
{

}
/**
 * Service changes the current number of tested cells.
 * @param     RamTst_NumberOfTestedCellsType NewNumberOfTestedCells - New value to be changed for the number of tested cells
 * @return    void
 */
void RamTst_ChangeNumberOfTestedCells(
        RamTst_NumberOfTestedCellsType NewNumberOfTestedCells)
{

}
/**
 * Service for executing the full RAM Test in the foreground
 * @param     none
 * @return    void
 */
void RamTst_RunFullTest(void)
{
    
}
/**
 * Service for testing one RAM block in the foreground.
 * @param     RamTst_NumberOfBlocksType BlockId - BlockId to be tested
 * @return    void
 */
void RamTst_RunPartialTest(RamTst_NumberOfBlocksType BlockId)
{

}

#define RAMTST_STOP_SEC_CODE
#include "MemMap.h"
#endif /*RAMTST_C*/
/*****************************************************************************
*     End of File
*
*******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 25-02-2025                                            */
/*Version           :                                                       */
/*By                : sgopal1                                               */
/*Traceability      :                                                       */
/*Change Description: Proveout, Initial Version                             */
/*--------------------------------------------------------------------------*/
