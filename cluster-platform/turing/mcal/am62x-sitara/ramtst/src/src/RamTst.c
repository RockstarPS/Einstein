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
#define RamTstJOBSTATE_IDLE           (FALSE)
#define ATOMIC_NOOFCELL                4096U
#define MARCH_1                  0xFFFFFFFFUL
#define MARCH_0 				0x00000000UL
#define MAX_HEX_32BIT   0xFFFFFFFFU
#define MAX_HEX_8BIT   0xFFU
#define VALUE_ONE_UL      1U
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
static RamTst_TestOverallResultType FgndResult;
static RamTst_TestOverallResultType BgndResult;

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
    RamTst_AlgParamsIdType Id = 0U;
    const RamTstAlgParamstype *AlgmPtr = NULL_PTR;
    uint32 index = 0U;
    uint32 algmindex = 0U;

    if ((RAMTST_EXECUTION_UNINIT == RamTst_State) && (NULL_PTR != ConfigPtr))
    {
        Id = ConfigPtr->RamTstDefaultAlgParamsId;
        if(NO_OF_ALGPARAMS > Id)
        {
            AlgmPtr = &Algconfig[Id];
        }
        else
        {
            RamTst_ReportDetError(RAMTST_API_INIT, RAMTST_E_OUT_OF_RANGE);
        }
        if(NULL_PTR != AlgmPtr)
        {
            RamTst_Infoptr.CurrentBgndAlgParamsId = Id;
            RamTst_Infoptr.CurrentFgndAlgParamsId = Id;
            RamTst_Infoptr.RamTst_NumberOfTestedCells =
                    AlgmPtr->RamTstNumberOfTestedCells;

            RamTst_Infoptr.CurrentBgndBlockID = AlgmPtr->BlockPtr->RamTstBlockId; 
            RamTst_Infoptr.CurrentBgndstartadress =
                    AlgmPtr->BlockPtr->RamTstStartAddress;
            RamTst_Infoptr.BgndExeStatus = RamTstJOBSTATE_IDLE;
            FgndResult.Result = RAMTST_RESULT_NOT_TESTED;
            BgndResult.Result = RAMTST_RESULT_NOT_TESTED;
            RamTst_State = RAMTST_EXECUTION_STOPPED;
            for (algmindex = 0U; algmindex < ConfigPtr->RamTstNumberOfAlgParamSets;
                    algmindex++)
            {
                for (index = 0; index < NO_OF_BLOCKS; index++)
                {
                    FgndResult.BlockResult[algmindex][index] =
                            RAMTST_RESULT_NOT_TESTED;
                    BgndResult.BlockResult[algmindex][index] =
                            RAMTST_RESULT_NOT_TESTED;
                }
            }
        }
        else
        {
            RamTst_ReportDetError(RAMTST_API_INIT, RamTst_E_PARAM_POINTER);
        }

    }
    else
    {
        RamTst_ReportDetError(RAMTST_API_INIT, RAMTST_E_STATUS_FAILURE);
    }
}
/**
 * This method is the main function for RamTst module
 * @param     none
 * @return    void
 */
void RamTst_MainFunction(void)
{
    RamTst_AlgParamsIdType AlgParamsID = 0x0U;
    static RamTstBlockParamstype AtomicBlockPtr;
    const RamTstBlockParamstype * TestblockPtr = NULL_PTR;
    const RamTstBlockParamstype * lBlockPtr;
    Std_ReturnType TestRet = E_OK;
    uint32 Noofcell = 0x0U;
    uint32 BlockcellCount = 0x0U;
    uint32 EndAdresss = 0x0U;
    uint32 StartAddress = 0x0U;
    uint16 blockCount = 0x0U;
    uint32 blockID = 0x0U;
    uint8 BlockLoopCount = 0x1U;
    uint32 nextstartAdress = 0x0U;
    uint32 testcellcount = 0x0U;
    if (RAMTST_EXECUTION_RUNNING == RamTst_State)
    {
        while (0UL != BlockLoopCount)
        {
            Mode = RAMTST_MODE_BACKGROUND;
            AlgParamsID = RamTst_Infoptr.CurrentBgndAlgParamsId;

            if (RamTstConfig.RamTstNumberOfAlgParamSets < AlgParamsID)
            {
                AlgParamsID = RamTstConfig.RamTstDefaultAlgParamsId;
            }
            if(AlgParamsID < NO_OF_ALGPARAMS)
            {
                blockCount = Algconfig[AlgParamsID].RamTstNumberOfBlocks;
                blockID = RamTst_Infoptr.CurrentBgndBlockID;
                lBlockPtr =Algconfig[AlgParamsID].BlockPtr;
                if(NO_OF_BLOCKS_ALG > blockID)
                {
                    TestblockPtr = &lBlockPtr[blockID];
                }
                else
                {
                    DEBUG_ASSERT( FALSE );
                }
                if(NULL_PTR != TestblockPtr)
                {
                    if (RamTst_Infoptr.CurrentBgndstartadress== TestblockPtr->RamTstStartAddress)
                    {
                        StartAddress = TestblockPtr->RamTstStartAddress;
                    }
                    else
                    {
                        StartAddress = RamTst_Infoptr.CurrentBgndstartadress;
                    }
                    RamTst_Infoptr.CurrentBgndstartadress = StartAddress;
                    if( TestblockPtr->RamTstEndAddress > StartAddress ) 
                    {
                        Noofcell = (TestblockPtr->RamTstEndAddress - StartAddress) + VALUE_ONE_UL; //1024
                    }
                    else
                    {
                        DEBUG_ASSERT( FALSE );
                    }
                    if(Noofcell <= (MAX_HEX_32BIT - BlockcellCount))
                    {
                        BlockcellCount += Noofcell; 
                    }
                    else
                    {
                        DEBUG_ASSERT( FALSE );
                    }
                    if (RamTst_Infoptr.RamTst_NumberOfTestedCells == BlockcellCount)
                    {
                        BlockLoopCount = 0x0U; 
                    }
                    else
                    {
                        BlockLoopCount = 0x1U;
                        if (RamTst_Infoptr.RamTst_NumberOfTestedCells < BlockcellCount)
                        {
                            nextstartAdress = (BlockcellCount- RamTst_Infoptr.RamTst_NumberOfTestedCells);
                            if( Noofcell > nextstartAdress ) 
                            {
                                Noofcell -= nextstartAdress;
                            }
                            else
                            {
                                DEBUG_ASSERT( FALSE );
                            }
                            RamTst_Infoptr.CurrentBgndstartadress = StartAddress+ Noofcell;
                            BlockLoopCount = 0x0U;
                        }
                    }
                    AtomicBlockPtr.RamTstBlockId = TestblockPtr->RamTstBlockId;
                    AtomicBlockPtr.RamTstFillPattern = TestblockPtr->RamTstFillPattern;
                    AtomicBlockPtr.RamTstTestPolicy = TestblockPtr->RamTstTestPolicy;
                    AtomicBlockPtr.RamTstDataBackUpAreaStart =TestblockPtr->RamTstDataBackUpAreaStart;
                    while(Noofcell > 0U)
                    {
                        if (ATOMIC_NOOFCELL < Noofcell)
                        {
                            if(ATOMIC_NOOFCELL <= (MAX_HEX_32BIT - StartAddress)) 
                            {
                                EndAdresss = (StartAddress + ATOMIC_NOOFCELL) - VALUE_ONE_UL;
                            }
                            else
                            {
                                DEBUG_ASSERT( FALSE );
                            }
                            Noofcell -= ATOMIC_NOOFCELL;
                            if(ATOMIC_NOOFCELL <= (MAX_HEX_32BIT - testcellcount))    //#issue Warning Problem ID 120592: The result of expression: 'testcellcount+4096U' generates 4-byte type while casting to a bigger size of 8-byte
                            {
                                testcellcount += ATOMIC_NOOFCELL;
                            }
                            else
                            {
                                DEBUG_ASSERT( FALSE );
                            }
                        }
                        else
                        {
                            if(Noofcell <= (MAX_HEX_32BIT - StartAddress)) 
                            {
                                EndAdresss = (StartAddress + Noofcell) - VALUE_ONE_UL;
                            }
                            else
                            {
                                DEBUG_ASSERT( FALSE );
                            }
                            if(Noofcell <= (MAX_HEX_32BIT - testcellcount)) 
                            {
                                testcellcount += Noofcell;
                            }
                            else
                            {
                                DEBUG_ASSERT( FALSE );
                            }
                            Noofcell = 0U;
                        }
                        AtomicBlockPtr.RamTstStartAddress = StartAddress;
                        AtomicBlockPtr.RamTstEndAddress = EndAdresss; 
                        if(VALUE_ONE_UL <= (MAX_HEX_32BIT - EndAdresss)) 
                        {
                            StartAddress = EndAdresss + VALUE_ONE_UL;
                        }
                        else
                        {
                            DEBUG_ASSERT( FALSE );
                        }

                        if (RAMTST_MARCH_TEST== Algconfig[AlgParamsID].RamTstAlgorithm)
                        {
                            RamTst_Infoptr.BgndExeStatus = STD_ON;
                            TestRet = RamTst_preprocess(&AtomicBlockPtr);
                        }

                        if (E_OK == TestRet)
                        {
                            if(NO_OF_BLOCKS > AtomicBlockPtr.RamTstBlockId)
                            {
                                if (RAMTST_RESULT_NOT_OK!= BgndResult.BlockResult[AlgParamsID][AtomicBlockPtr.RamTstBlockId])
                                {
                                    BgndResult.Result = RAMTST_RESULT_OK;
                                    BgndResult.BlockResult[AlgParamsID][AtomicBlockPtr.RamTstBlockId] =RAMTST_RESULT_OK;
                                }
                            }
                            else
                            {
                                DEBUG_ASSERT( FALSE );
                            }
                        }    /* if (E_OK == TestRet) */
                        else
                        {
                            if(NO_OF_BLOCKS > AtomicBlockPtr.RamTstBlockId)
                            {
                                BgndResult.BlockResult[AlgParamsID][AtomicBlockPtr.RamTstBlockId] = RAMTST_RESULT_NOT_OK;
                            }
                            else
                            {
                                DEBUG_ASSERT( FALSE );
                            }
                            BgndResult.Result = RAMTST_RESULT_NOT_OK;
                            /* Error notification */
                            if (NULL_PTR != RamTstConfig.RamTstTestErrorNotification)
                            {
                                RamTstConfig.RamTstTestErrorNotification();
                            }
                        }    /* end of if (E_OK == TestRet) */

                        RamTst_Infoptr.BgndExeStatus = STD_OFF;
                        if ((RAMTST_EXECUTION_SUSPENDED == RamTst_WaitingState)|| (RAMTST_EXECUTION_STOPPED == RamTst_WaitingState))
                        {
                            BlockLoopCount = 0x0U;
                            RamTst_State = RamTst_WaitingState;
                        }
                        
                    }    /* endof for loop */
                        /* if one block is tested, move to next block */
                    if (TestblockPtr->RamTstEndAddress == AtomicBlockPtr.RamTstEndAddress)
                    {
                        /* check block id and update the blockid */
                        if (blockCount == (AtomicBlockPtr.RamTstBlockId + VALUE_ONE_UL))
                        {
                            /* if it last block in AlgParam update the AlgParamId */
                            if (AlgParamsID
                                    != (RamTstConfig.RamTstNumberOfAlgParamSets - VALUE_ONE_UL))
                            {
                                if(MAX_HEX_8BIT > RamTst_Infoptr.CurrentBgndAlgParamsId) 
                                {
                                    RamTst_Infoptr.CurrentBgndAlgParamsId += VALUE_ONE_U;
                                }
                                else
                                {
                                    DEBUG_ASSERT( FALSE );
                                }
                                if (NO_OF_ALGPARAMS > RamTst_Infoptr.CurrentBgndAlgParamsId)
                                {
                                    RamTst_Infoptr.CurrentBgndBlockID =
                                            Algconfig[RamTst_Infoptr.CurrentBgndAlgParamsId].BlockPtr[0].RamTstBlockId;
                                    RamTst_Infoptr.RamTst_NumberOfTestedCells =Algconfig[RamTst_Infoptr.CurrentBgndAlgParamsId].RamTstNumberOfTestedCells;
                                }
                                else
                                {
                                    DEBUG_ASSERT( FALSE );
                                }
                            }
                            else
                            {
                                /* test_interval is completed */
                                BlockLoopCount = 0x0U;
                                if (NULL_PTR!= RamTstConfig.RamTstTestCompletedNotification)
                                {
                                    RamTstConfig.RamTstTestCompletedNotification();
                                }
                                RamTst_Infoptr.CurrentBgndAlgParamsId =RamTstConfig.RamTstDefaultAlgParamsId;
                                if (NO_OF_ALGPARAMS > RamTst_Infoptr.CurrentBgndAlgParamsId)
                                {
                                    RamTst_Infoptr.CurrentBgndBlockID =
                                        Algconfig[RamTst_Infoptr.CurrentBgndAlgParamsId].BlockPtr[0].RamTstBlockId;
                                    RamTst_Infoptr.CurrentBgndstartadress =
                                        Algconfig[RamTst_Infoptr.CurrentBgndAlgParamsId].BlockPtr[0].RamTstStartAddress;
                                    RamTst_Infoptr.RamTst_NumberOfTestedCells =Algconfig[RamTst_Infoptr.CurrentBgndAlgParamsId].RamTstNumberOfTestedCells;
                                }
                                else
                                {
                                    DEBUG_ASSERT( FALSE );
                                }
                                
                            }
                        }
                        else
                        {
                            /* if it is not last block in AlgParam update the BlockId */
                            RamTst_Infoptr.CurrentBgndBlockID =
                                    Algconfig[AlgParamsID].BlockPtr[blockID + VALUE_ONE_UL].RamTstBlockId;
                        }
                    }    /* endof if (TestblockPtr->RamTstEndAddress == AtomicBlockPtr.RamTstEndAddress) */
                }
                else
                {
                    RamTst_ReportDetError(RAMTST_API_MAIN_FUNCTION, RamTst_E_PARAM_POINTER);
                }
            }
            else
            {
                DEBUG_ASSERT( FALSE );
            }
        }
    }
    else
    {
        /*Do nothing*/
    }
    if (E_NOT_OK == TestRet)
    {
        /* DEM RAMTST_E_RAM_FAILURE */
    }
    else
    {
        /* DEM PASS */
    }
}

/**
 * This method De-initialize the RamTst module
 * @param     none
 * @return    void
 */
void RamTst_DeInit(void)
{
    RamTst_AlgParamsIdType Id = 0U;
    const RamTstAlgParamstype *AlgmPtr = NULL_PTR;
    uint32 index = 0U;
    uint32 algmindex = 0U;

    Id = RamTstConfig.RamTstDefaultAlgParamsId;
    if(NO_OF_ALGPARAMS > Id)
    {
        AlgmPtr = &Algconfig[Id];
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
    if(NULL_PTR != AlgmPtr)
    {
        RamTst_Infoptr.CurrentBgndAlgParamsId = Id;
        RamTst_Infoptr.CurrentFgndAlgParamsId = Id;
        RamTst_Infoptr.RamTst_NumberOfTestedCells =
                AlgmPtr->RamTstNumberOfTestedCells;

        RamTst_Infoptr.CurrentBgndBlockID = AlgmPtr->BlockPtr->RamTstBlockId;
        RamTst_Infoptr.CurrentBgndstartadress =
                AlgmPtr->BlockPtr->RamTstStartAddress;
        RamTst_Infoptr.BgndExeStatus = RamTstJOBSTATE_IDLE;
        FgndResult.Result = RAMTST_RESULT_NOT_TESTED;
        BgndResult.Result = RAMTST_RESULT_NOT_TESTED;
        RamTst_State = RAMTST_EXECUTION_UNINIT;
        for (algmindex = 0U; algmindex < RamTstConfig.RamTstNumberOfAlgParamSets;
                algmindex++)
        {
            for (index = 0; index < NO_OF_BLOCKS; index++)
            {
                FgndResult.BlockResult[algmindex][index] =
                        RAMTST_RESULT_NOT_TESTED;
                BgndResult.BlockResult[algmindex][index] =
                        RAMTST_RESULT_NOT_TESTED;
            }
        }
    }
    else
    {
        RamTst_ReportDetError(RAMTST_API_DEINIT, RamTst_E_PARAM_POINTER);
    }
}

/**
 * Service for stopping the RAM Test.
 * @param     none
 * @return    void
 */
void RamTst_Stop(void)
{
    if ((RAMTST_EXECUTION_RUNNING != RamTst_State)
            && (RAMTST_EXECUTION_SUSPENDED != RamTst_State))
    {
        RamTst_ReportDetError(RAMTST_API_ALLOW, RAMTST_E_STATUS_FAILURE);
    }
    else
    {
        if (STD_OFF == RamTst_Infoptr.BgndExeStatus)
        {
            RamTst_State = RAMTST_EXECUTION_STOPPED;
        }
        else
        {
            RamTst_WaitingState = RAMTST_EXECUTION_STOPPED;
        }
    }
}
/**
 * Service for continuing the RAM Test after calling 'RamTst_Stop.
 * @param     none
 * @return    void
 */
void RamTst_Allow(void)
{
    if (RAMTST_EXECUTION_STOPPED != RamTst_State)
    {
        RamTst_ReportDetError(RAMTST_API_ALLOW, RAMTST_E_STATUS_FAILURE);
    }
    else
    {
        if (STD_OFF == RamTst_Infoptr.BgndExeStatus)
        {
            RamTst_State = RAMTST_EXECUTION_RUNNING;
        }
        else
        {
            RamTst_WaitingState = RAMTST_EXECUTION_RUNNING;
        }
    }
}
/**
 * Service for suspending current operation of background RAM Test,
 * @param     none
 * @return    void
 */
void RamTst_Suspend(void)
{
    if (RAMTST_EXECUTION_RUNNING != RamTst_State)
    {
        RamTst_ReportDetError(RAMTST_API_SUSPEND, RAMTST_E_STATUS_FAILURE);
    }
    else
    {
        if (RAMTST_MODE_FOREGROUND == Mode)
        {
            RamTst_State = RAMTST_EXECUTION_SUSPENDED;
        }
        else
        {
            if (STD_OFF == RamTst_Infoptr.BgndExeStatus)
            {
                RamTst_State = RAMTST_EXECUTION_SUSPENDED;
            }
            else
            {
                RamTst_WaitingState = RAMTST_EXECUTION_SUSPENDED;
            }
        }
    }
}
/**
 * Service for allowing to continue the background RAM Test
 * @param     none
 * @return    void
 */
void RamTst_Resume(void)
{
    if (RAMTST_EXECUTION_UNINIT != RamTst_State)
    {
        if (RAMTST_EXECUTION_SUSPENDED == RamTst_State)
        {
            RamTst_State = RAMTST_EXECUTION_RUNNING;
        }
        else
        {
            RamTst_ReportDetError(RAMTST_API_RESUME,
            RAMTST_E_STATUS_FAILURE);
        }
    }
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
void RamTst_GetVersionInfo(const Std_VersionInfoType *versioninfo)
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
    RamTst_TestResultType Status = RAMTST_RESULT_UNDEFINED;
    if (RAMTST_MODE_FOREGROUND == Mode)
    {
        Status = FgndResult.Result;
    }
    else
    {
        Status = BgndResult.Result;
    }
    return Status;
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
    RamTst_AlgParamsIdType AlgParamsID = 0x0U;
    if (RAMTST_MODE_FOREGROUND == Mode)
    {
        AlgParamsID = RamTst_Infoptr.CurrentFgndAlgParamsId;
    }
    else
    {
        AlgParamsID = RamTst_Infoptr.CurrentBgndAlgParamsId;
    }
    if (RamTstConfig.RamTstNumberOfAlgParamSets < AlgParamsID)
    {
        AlgParamsID = RamTstConfig.RamTstDefaultAlgParamsId;
    }
    if (BlockID > Algconfig[AlgParamsID].RamTstNumberOfBlocks)
    {
        RamTst_ReportDetError(RAMTST_API_RUN_PARTIAL_TEST,
        RAMTST_E_OUT_OF_RANGE);
    }
    else
    {
        if (RAMTST_MODE_FOREGROUND == Mode)
        {
            Status = FgndResult.BlockResult[AlgParamsID][BlockID];
        }
        else
        {
            Status = BgndResult.BlockResult[AlgParamsID][BlockID];
        }
    }
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
    if (RAMTST_MODE_FOREGROUND == Mode)
    {
        ret = RamTst_Infoptr.CurrentFgndAlgParamsId;
    }
    else
    {
        ret = RamTst_Infoptr.CurrentBgndAlgParamsId;
    }
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
    if (RAMTST_MODE_FOREGROUND == Mode)
    {
        if(NO_OF_ALGPARAMS > RamTst_Infoptr.CurrentFgndAlgParamsId)
        {
            ret = Algconfig[RamTst_Infoptr.CurrentFgndAlgParamsId].RamTstAlgorithm;
        }
        else
        {
            DEBUG_ASSERT( FALSE );
        }
    }
    else
    {
        if(NO_OF_ALGPARAMS > RamTst_Infoptr.CurrentBgndAlgParamsId)
        {
            ret = Algconfig[RamTst_Infoptr.CurrentBgndAlgParamsId].RamTstAlgorithm;
        }
        else
        {
            DEBUG_ASSERT( FALSE );
        }
    }
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
    if (RamTstConfig.RamTstNumberOfAlgParamSets < NewAlgParamsId)
    {
        RamTst_ReportDetError(RAMTST_API_SELECT_ALG_PARAMS,
        RAMTST_E_OUT_OF_RANGE);
    }
    else if (RAMTST_EXECUTION_STOPPED != RamTst_State)
    {
        RamTst_ReportDetError(RAMTST_API_SELECT_ALG_PARAMS,
        RAMTST_E_STATUS_FAILURE);
    }
    else
    {
        RamTst_Infoptr.CurrentFgndAlgParamsId = NewAlgParamsId;
    }
}
/**
 * Service changes the current number of tested cells.
 * @param     RamTst_NumberOfTestedCellsType NewNumberOfTestedCells - New value to be changed for the number of tested cells
 * @return    void
 */
void RamTst_ChangeNumberOfTestedCells(
        RamTst_NumberOfTestedCellsType NewNumberOfTestedCells)
{
    if(NO_OF_ALGPARAMS > RamTst_Infoptr.CurrentBgndAlgParamsId)
    {
        if ((NewNumberOfTestedCells < RamTstConfig.RamTstMinNumberOfTestedCells)
                || (NewNumberOfTestedCells
                        > Algconfig[RamTst_Infoptr.CurrentBgndAlgParamsId].RamTstMaxNumberOfTestedCells))
        {
            RamTst_ReportDetError(RAMTST_API_CHANGE_NUMBER_OF_TESTED_CELLS,
            RAMTST_E_OUT_OF_RANGE);
        }
        else if (RAMTST_EXECUTION_STOPPED != RamTst_State)
        {
            RamTst_ReportDetError(RAMTST_API_CHANGE_NUMBER_OF_TESTED_CELLS,
            RAMTST_E_STATUS_FAILURE);
        }
        else
        {
            RamTst_Infoptr.RamTst_NumberOfTestedCells = NewNumberOfTestedCells;
        }
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
}
/**
 * Service for executing the full RAM Test in the foreground
 * @param     none
 * @return    void
 */
void RamTst_RunFullTest(void)
{
    RamTst_AlgParamsIdType AlgParamsID = RamTst_Infoptr.CurrentFgndAlgParamsId;
    const RamTstBlockParamstype *TestBlockPtr = NULL_PTR;
    uint16 index = 0U;
    Std_ReturnType TestRet = E_NOT_OK;
    RamTst_ExecutionStatusType localRamtstState = RAMTST_EXECUTION_STOPPED;
    if ((RAMTST_EXECUTION_STOPPED != RamTst_State)&& (RAMTST_EXECUTION_SUSPENDED != RamTst_State))
    {
        RamTst_ReportDetError(RAMTST_API_RUN_PARTIAL_TEST,RAMTST_E_STATUS_FAILURE);
    }
    else
    {
        if(NO_OF_ALGPARAMS > AlgParamsID)
        {
            localRamtstState = RamTst_State;
            RamTst_State = RAMTST_EXECUTION_RUNNING;
            Mode = RAMTST_MODE_FOREGROUND;

            TestBlockPtr = Algconfig[AlgParamsID].BlockPtr;
            for (index = 0U; index < Algconfig[AlgParamsID].RamTstNumberOfBlocks;index++)
            {
                if (RAMTST_MARCH_TEST == Algconfig[AlgParamsID].RamTstAlgorithm)
                {
                    TestRet = RamTst_preprocess(TestBlockPtr);
                }
                if (E_OK == TestRet)
                {
                    if(NO_OF_BLOCKS > TestBlockPtr->RamTstBlockId)
                    {
                        FgndResult.BlockResult[AlgParamsID][TestBlockPtr->RamTstBlockId] =RAMTST_RESULT_OK;
                    }
                    else
                    {
                        DEBUG_ASSERT(FALSE);
                    }
                    FgndResult.Result = RAMTST_RESULT_OK;
                }
                else
                {
                    if(NO_OF_BLOCKS > TestBlockPtr->RamTstBlockId)
                    {  
                        FgndResult.BlockResult[AlgParamsID][TestBlockPtr->RamTstBlockId] =RAMTST_RESULT_NOT_OK;
                    }
                    else
                    {
                        DEBUG_ASSERT(FALSE);
                    }
                    FgndResult.Result = RAMTST_RESULT_NOT_OK;
                }
                TestBlockPtr++;
            }
            RamTst_State = localRamtstState;
        }
        else
        {
            DEBUG_ASSERT( FALSE );
        }
    }
    if (E_NOT_OK == TestRet)
    {
        /* DEM RAMTST_E_RAM_FAILURE */
    }
    else
    {
        /* DEM FAIL */
    }
}
/**
 * Service for testing one RAM block in the foreground.
 * @param     RamTst_NumberOfBlocksType BlockId - BlockId to be tested
 * @return    void
 */
void RamTst_RunPartialTest(RamTst_NumberOfBlocksType BlockId)
{
    RamTst_AlgParamsIdType AlgParamsID = RamTst_Infoptr.CurrentFgndAlgParamsId;
    uint16 index = 0U;
    Std_ReturnType TestRet = E_NOT_OK;
    RamTst_ExecutionStatusType localRamtstState = RAMTST_EXECUTION_STOPPED;
    if ((RAMTST_EXECUTION_STOPPED != RamTst_State)
            && (RAMTST_EXECUTION_SUSPENDED != RamTst_State))
    {
        RamTst_ReportDetError(RAMTST_API_RUN_PARTIAL_TEST,RAMTST_E_STATUS_FAILURE);
    }
    else if ((NO_OF_ALGPARAMS <= AlgParamsID) || (BlockId >= Algconfig[AlgParamsID].RamTstNumberOfBlocks))
    {
        RamTst_ReportDetError(RAMTST_API_RUN_PARTIAL_TEST,RAMTST_E_OUT_OF_RANGE);
    }
    else
    {
        const RamTstBlockParamstype *TestBlockPtr;
        const RamTstBlockParamstype *TestBlockBasePtr;

        localRamtstState = RamTst_State;
        RamTst_State = RAMTST_EXECUTION_RUNNING;
        Mode = RAMTST_MODE_FOREGROUND;

        TestBlockBasePtr = Algconfig[AlgParamsID].BlockPtr;

        for (index = 0U; index < Algconfig[AlgParamsID].RamTstNumberOfBlocks; index++)
        {
            TestBlockPtr = &TestBlockBasePtr[index];

            if (BlockId == TestBlockPtr->RamTstBlockId)
            {
                if (RAMTST_MARCH_TEST == Algconfig[AlgParamsID].RamTstAlgorithm)
                {
                    TestRet = RamTst_preprocess(TestBlockPtr);
                }

                if (E_OK == TestRet)
                {
                    FgndResult.BlockResult[AlgParamsID][BlockId] = RAMTST_RESULT_OK;
                    FgndResult.Result = RAMTST_RESULT_OK;
                }
                else
                {
                    FgndResult.BlockResult[AlgParamsID][BlockId] = RAMTST_RESULT_NOT_OK;
                    FgndResult.Result = RAMTST_RESULT_NOT_OK;
                }

                break;
            }
        }

        RamTst_State = localRamtstState;
    }
    if (E_NOT_OK == TestRet)
    {
        /* DEM RAMTST_E_RAM_FAILURE */
    }
    else
    {
        /* DEM FAIL */
    }

}
/******************************************************************************
 *  Public Function Definitions                                                *
 *******************************************************************************/
/**
 * Service to process the job
 * @param     const RamTstBlockParamstype *RamTstBlockPtr - Pointer having data of block to be tested
 * @return    Std_ReturnType
 */
static Std_ReturnType RamTst_preprocess(
        const RamTstBlockParamstype *RamTstBlockPtr)
{
    Std_ReturnType status = E_OK;
    uint32 backupStartAddress = RamTstBlockPtr->RamTstDataBackUpAreaStart;
    uint32 RamTstAddress = RamTstBlockPtr->RamTstStartAddress;
    uint32 RamTstEndAddr = RamTstBlockPtr->RamTstEndAddress;
    static uint32 cur_addr =0x0U;
    static uint8 RamTst_ReadNMIStatus = STD_OFF;

    RamTst_SaveSPCacheData();
    RamTst_CacheDisable();
    if (RAMTEST_NON_DESTRUCTIVE == RamTstBlockPtr->RamTstTestPolicy)
    {
        /* copy the data */
        while (RamTstAddress <= RamTstEndAddr)
        {
            *((volatile uint32*)(uintptr_t)backupStartAddress) =
                *((volatile uint32*)(uintptr_t)RamTstAddress);

            if (RamTstAddress <= (MAX_HEX_32BIT - (uint32)sizeof(uint32)))
            {
                RamTstAddress += (uint32)sizeof(uint32);
            }
            else
            {
                DEBUG_ASSERT(FALSE);
                status = E_NOT_OK;
                break;
            }

            if (backupStartAddress <= (MAX_HEX_32BIT - (uint32)sizeof(uint32)))
            {
                backupStartAddress += (uint32)sizeof(uint32);
            }
            else
            {
                DEBUG_ASSERT(FALSE);
                status = E_NOT_OK;
                break;
            }
        }    
    }
/* start exclusive area  */
    RAMTST_ENTERCRITICALSECTION();
    cur_addr = RamTstBlockPtr->RamTstStartAddress;
    while ((E_OK == status) && (RamTstEndAddr > cur_addr))
    {
        if (STD_OFF == RamTst_ReadNMIStatus)
        {
            *((volatile uint32*)(uintptr_t)cur_addr) = (uint32)MARCH_1;            
            if ((uint32)MARCH_1 != *(volatile uint32*)(uintptr_t)cur_addr)
            {
                status = E_NOT_OK;
            }
            if(cur_addr <= (MAX_HEX_32BIT - (uint32)sizeof(uint32)))
            {
                cur_addr += (uint32)sizeof(uint32);
            }
            else
            {
                status = E_NOT_OK;
            }
        }
        else
        {
            status = E_NOT_OK;
        }
    }
    if (status == E_OK)
    {
        /* Test target form end address to start address */
        cur_addr = (RamTstEndAddr- (uint32)sizeof(uint32)) + (uint32)VALUE_ONE_UL;
    }
    if (STD_OFF == RamTst_ReadNMIStatus)
    {
        while ((E_OK == status) && (RamTstEndAddr > cur_addr)
                && (RamTstBlockPtr->RamTstStartAddress <= cur_addr))
        {
            *(volatile uint32*)(uintptr_t)cur_addr = (uint32)MARCH_0;
            if ((uint32)MARCH_0 != *((volatile uint32*)(uintptr_t)cur_addr))
            {
                status = E_NOT_OK;
            }
            if(cur_addr <= (MAX_HEX_32BIT - (uint32)sizeof(uint32)))
            {
                cur_addr += (uint32)sizeof(uint32);
            }
            else
            {
                status = E_NOT_OK;
            }
        }
    }

    if (RAMTEST_NON_DESTRUCTIVE == RamTstBlockPtr->RamTstTestPolicy)
    {
        /*restore the data*/
        RamTstAddress = RamTstBlockPtr->RamTstStartAddress;
        backupStartAddress = RamTstBlockPtr->RamTstDataBackUpAreaStart;
        while (RamTstEndAddr >= RamTstAddress)
        {
            *((volatile uint32*)(uintptr_t)RamTstAddress) = *((volatile uint32*)(uintptr_t)backupStartAddress);
            RamTstAddress += (uint32)sizeof(uint32);
            backupStartAddress += (uint32)sizeof(uint32);
        }
    }
    else
    {
        /* fill pattern value */
        RamTstAddress = RamTstBlockPtr->RamTstStartAddress;
        while (RamTstEndAddr >= RamTstAddress)
        {
            *((volatile uint32*)(uintptr_t)RamTstAddress) = RamTstBlockPtr->RamTstFillPattern;
            RamTstAddress += (uint32)sizeof(uint32);
        }
    }
    RAMTST_EXITCRITICALSECTION();
    RamTst_CacheEnable();
    RamTst_RestoreSPCacheData();
/* End exclusive area */
    return status;
}

static void RamTst_SaveSPCacheData(void)
{
}
static void RamTst_CacheDisable(void)
{
}
static void RamTst_CacheEnable(void)
{
}
static void RamTst_RestoreSPCacheData(void)
{
}
/**
 * Service to report the DET error
 * @param     uint32 APIID - Id of the function
 * @param     uint32 ErrorID - Particular error type Id
 * @return    void
 */
static void RamTst_ReportDetError(uint32 APIID, uint32 ErrorID)
{
    (void) APIID;
    (void) ErrorID;
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
