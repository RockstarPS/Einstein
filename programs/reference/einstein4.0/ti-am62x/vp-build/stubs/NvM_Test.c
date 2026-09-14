/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2013. Visteon Corporation owns all rights to           *
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
/*****************************************************************************
*  File Name         :  NvM_Test.c                                           *
*  Module Short Name :  NvM                                                  *
*  Description       :                                                       *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :                                                         *
*                                                                            *
******************************************************************************/
#ifndef NVM_TEST_C

#include "NvM.h"
#include "MemLib.h"
#include "Gpt.h"
#include "NvM_Test.h"
typedef enum
{
    NVM_TEST_IDLE,
    NVM_TEST_INITIATE,
    NVM_TEST_ENABLE_WRITE_PROTECT_ALL_BLOCKS,
    NVM_TEST_WAIT_EXISTING_BLOCKS_COMPLETE,
    NVM_TEST_WRITE_BLOCK_INITATE,
    NVM_TEST_WRITE_BLOCK_WAIT,
    NVM_TEST_READ_BLOCK_INITIATE,
    NVM_TEST_READ_BLOCK_WAIT,
    NVM_TEST_VALIDATE_WRITE_AND_READ,
    NVM_TEST_COMPLETE,
    NVM_TEST_DISABLE_WRITE_PROTECT_ALL_BLOCKS
}NvM_TestStateMachineType;

typedef enum
{
    NVM_BLOCK_TEST_NOT_INITIATED,
    NVM_BLOCK_TEST_INITAITED,
    NVM_BLOCK_TEST_WRITE_REQUEST_NOT_ACCEPTED,
    NVM_BLOCK_TEST_WRITE_REQUEST_ACCEPTED_RESULT_PENDING,
    NVM_BLOCK_TEST_WRITE_REQUEST_FAILED,
    NVM_BLOCK_TEST_WRITE_REQUEST_COMPLETED,
    NVM_BLOCK_TEST_READ_REQUEST_NOT_ACCEPTED,
    NVM_BLOCK_TEST_READ_REQUEST_ACCEPTED_RESULT_PENDING,
    NVM_BLOCK_TEST_READ_REQUEST_FAILED,
    NVM_BLOCK_TEST_READ_REQUEST_COMPLETED,
    NVM_BLOCK_TEST_COMPLETED_VALIDATION_FAILED,
    NVM_BLOCK_TEST_COMPLETED_SUCCESSFULLY,
}NvM_BlockTestResultType;


typedef enum
{
    NVM_TEST_INITAITED,
    NVM_TEST_FAILED,
    NVM_TEST_SUCCESS
}NvM_TestResultType;


typedef struct
{
    uint16                      CurrentTestBlockId;
    NvM_BlockTestResultType     NvMBlockTestResult[NVM_NUM_OF_BLOCKS+1U];
    NvM_TestResultType          TestStatus;
    uint16                      NvMTestFailiureCount;
}NvM_TestDataStructType;


NvM_TestStateMachineType NvM_TestStateMachine = NVM_TEST_IDLE;

NvM_TestDataStructType NvM_TestDataStruct;

uint8 NvM_TestWriteBuffer[NVM_WRITE_VERIFICATION_DATASIZE];
uint8 NvM_TestReadBuffer[NVM_WRITE_VERIFICATION_DATASIZE];
uint16 BlockId;


volatile uint8 InitiateNvMTesting = 0;
uint8 status;
uint8  flashconstantsValidStarttest[16];
static void NvM_BlockTest(void);

#define NVM_METRICS_GPT_FREQ_IN_MHZ					                    (25u)
#define NVM_METRICS_GPT_SRC                                             GptConf_GptChannelConfiguration_MCU_TIMER1
#define NVM_METRICS_GET_CURRENT_TIME()                                  Gpt_GetTimeElapsed(NVM_METRICS_GPT_SRC)


typedef struct
{
    uint32 ReadAllStartTime;
    uint32 ReadAllEndTime;
    uint32 ReadAllTime;
    uint32 Phase1StartTime;
    uint32 Phase1EndTime;
    uint32 Phase1Time;
    uint32 Phase2StartTime;
    uint32 Phase2EndTime;
    uint32 Phase2Time;
    uint32 Phase3StartTime;
    uint32 Phase3EndTime;
    uint32 Phase3Time;
}NvM_MetricsType;

NvM_MetricsType NvM_Metrics;

void NvM_MetricsCaptureTimeStamp(uint8 TimeStampID, uint8 Status)
{
    switch(TimeStampID)
    {
        /* ReadAll*/
        case 0U:
            if(Status == 0U)
            {
                NvM_Metrics.ReadAllStartTime = NVM_METRICS_GET_CURRENT_TIME();
            }
            if(Status == 1U)
            {
                NvM_Metrics.ReadAllEndTime = NVM_METRICS_GET_CURRENT_TIME();
                NvM_Metrics.ReadAllTime = (NvM_Metrics.ReadAllEndTime - NvM_Metrics.ReadAllStartTime)/NVM_METRICS_GPT_FREQ_IN_MHZ;
            }
        break;

        case 1U:
            if(Status == 0U)
            {
                NvM_Metrics.Phase1StartTime = NVM_METRICS_GET_CURRENT_TIME();
            }
            if(Status == 1U)
            {
                NvM_Metrics.Phase1EndTime = NVM_METRICS_GET_CURRENT_TIME();
                NvM_Metrics.Phase1Time = (NvM_Metrics.Phase1EndTime - NvM_Metrics.Phase1StartTime)/NVM_METRICS_GPT_FREQ_IN_MHZ;
            }
        break;

        case 2U:
            if(Status == 0U)
            {
                NvM_Metrics.Phase2StartTime = NVM_METRICS_GET_CURRENT_TIME();
            }
            if(Status == 1U)
            {
                NvM_Metrics.Phase2EndTime = NVM_METRICS_GET_CURRENT_TIME();
                NvM_Metrics.Phase2Time = (NvM_Metrics.Phase2EndTime - NvM_Metrics.Phase2StartTime)/NVM_METRICS_GPT_FREQ_IN_MHZ;
            }
        break;


        case 3U:
            if(Status == 0U)
            {
                NvM_Metrics.Phase3StartTime = NVM_METRICS_GET_CURRENT_TIME();
            }
            if(Status == 1U)
            {
                NvM_Metrics.Phase3EndTime = NVM_METRICS_GET_CURRENT_TIME();
                NvM_Metrics.Phase3Time = (NvM_Metrics.Phase3EndTime - NvM_Metrics.Phase3StartTime)/NVM_METRICS_GPT_FREQ_IN_MHZ;
            }
        break;

        default:
            /* No action required */
        break;
    }
}




void NvM_TestFunction(void)
{
	NvM_BlockTest();
    uint16 fl_TempBlockId;
    uint16 fl_BlockIdIteration;
    uint16 BlockLength;
    NvM_RequestResultType NvM_Result;
    Std_ReturnType RetVal;

    switch(NvM_TestStateMachine)
    {
        case NVM_TEST_IDLE:
            if(FALSE != InitiateNvMTesting)
            {
                NvM_TestStateMachine = NVM_TEST_INITIATE;
                InitiateNvMTesting = FALSE;
                for(fl_BlockIdIteration = 2U; fl_BlockIdIteration <= NVM_NUM_OF_BLOCKS; fl_BlockIdIteration++)
                {
                    NvM_TestDataStruct.NvMBlockTestResult[fl_BlockIdIteration] = NVM_BLOCK_TEST_NOT_INITIATED;
                }
                NvM_TestDataStruct.TestStatus = NVM_TEST_INITAITED;
            }
        break;
        case NVM_TEST_INITIATE:
            NvM_TestDataStruct.CurrentTestBlockId = 2U;
            MemLib_MemSet((uint8*)(&(NvM_TestWriteBuffer[0])), 0x28U, NVM_WRITE_VERIFICATION_DATASIZE);
            MemLib_MemSet((uint8*)(&(NvM_TestReadBuffer[0])), 0xFFU, NVM_WRITE_VERIFICATION_DATASIZE);
            NvM_TestStateMachine = NVM_TEST_ENABLE_WRITE_PROTECT_ALL_BLOCKS;
            BlockId = 2;
        break;

        case NVM_TEST_ENABLE_WRITE_PROTECT_ALL_BLOCKS:
            for(fl_BlockIdIteration = 2U; fl_BlockIdIteration <= NVM_NUM_OF_BLOCKS; fl_BlockIdIteration++)
            {
                NvM_SetBlockProtection(fl_BlockIdIteration, TRUE);
            }
            NvM_TestStateMachine = NVM_TEST_WAIT_EXISTING_BLOCKS_COMPLETE;
        break;

        case NVM_TEST_WAIT_EXISTING_BLOCKS_COMPLETE:
            fl_TempBlockId = 0xFFFF;
            for(fl_BlockIdIteration = 2U; fl_BlockIdIteration <= NVM_NUM_OF_BLOCKS; fl_BlockIdIteration++)
            {
                (void)NvM_GetErrorStatus(fl_BlockIdIteration, &NvM_Result);
                if(NVM_REQ_PENDING == NvM_Result)
                {
                    fl_TempBlockId = fl_BlockIdIteration;
                    break;
                }
            }
            if(fl_TempBlockId == 0xFFFFU)
            {
                NvM_TestStateMachine = NVM_TEST_WRITE_BLOCK_INITATE;
                NvM_TestDataStruct.CurrentTestBlockId = 2U;
            }
        break;

        case NVM_TEST_WRITE_BLOCK_INITATE:
        	NvM_SetBlockProtection(NvM_TestDataStruct.CurrentTestBlockId, FALSE);
        	RetVal = NvM_WriteBlock(NvM_TestDataStruct.CurrentTestBlockId,&NvM_TestWriteBuffer[0]);
        	NvM_SetBlockProtection(NvM_TestDataStruct.CurrentTestBlockId, TRUE);
            if(RetVal == E_OK)
            {
                NvM_TestStateMachine = NVM_TEST_WRITE_BLOCK_WAIT;
                NvM_TestDataStruct.NvMBlockTestResult[NvM_TestDataStruct.CurrentTestBlockId] = NVM_BLOCK_TEST_WRITE_REQUEST_ACCEPTED_RESULT_PENDING;
            }
            else
            {
                NvM_TestDataStruct.NvMBlockTestResult[NvM_TestDataStruct.CurrentTestBlockId] = NVM_BLOCK_TEST_WRITE_REQUEST_NOT_ACCEPTED;
                NvM_TestDataStruct.CurrentTestBlockId++;
                if(NvM_TestDataStruct.CurrentTestBlockId > NVM_NUM_OF_BLOCKS)
                {
                    NvM_TestStateMachine = NVM_TEST_COMPLETE;
                }
                else
                {
                    /* Stay in this state and initate Next write */
                }
            }
        break;

        case NVM_TEST_WRITE_BLOCK_WAIT:
            (void)NvM_GetErrorStatus(NvM_TestDataStruct.CurrentTestBlockId, &NvM_Result);
            if(NVM_REQ_PENDING != NvM_Result)
            {
                if(NvM_Result == NVM_REQ_OK)
                {
                    NvM_TestDataStruct.NvMBlockTestResult[NvM_TestDataStruct.CurrentTestBlockId] = NVM_BLOCK_TEST_WRITE_REQUEST_COMPLETED;
                    NvM_TestStateMachine = NVM_TEST_READ_BLOCK_INITIATE;
                }
                else
                {
                    NvM_TestDataStruct.NvMBlockTestResult[NvM_TestDataStruct.CurrentTestBlockId] = NVM_BLOCK_TEST_WRITE_REQUEST_FAILED;
                    NvM_TestDataStruct.CurrentTestBlockId++;
                    if(NvM_TestDataStruct.CurrentTestBlockId > NVM_NUM_OF_BLOCKS)
                    {
                        NvM_TestStateMachine = NVM_TEST_COMPLETE;
                    }
                    else
                    {
                        NvM_TestStateMachine = NVM_TEST_WRITE_BLOCK_INITATE;
                    }
                }
            }
        break;

        case NVM_TEST_READ_BLOCK_INITIATE:
            MemLib_MemSet((uint8*)(&(NvM_TestReadBuffer[0])), 0xFF, NVM_WRITE_VERIFICATION_DATASIZE);
            RetVal = NvM_ReadBlock(NvM_TestDataStruct.CurrentTestBlockId, &NvM_TestReadBuffer[0]);
            if(E_OK == RetVal)
            {
                NvM_TestDataStruct.NvMBlockTestResult[NvM_TestDataStruct.CurrentTestBlockId] = NVM_BLOCK_TEST_READ_REQUEST_ACCEPTED_RESULT_PENDING;
                NvM_TestStateMachine = NVM_TEST_READ_BLOCK_WAIT;
            }
            else
            {
                NvM_TestDataStruct.NvMBlockTestResult[NvM_TestDataStruct.CurrentTestBlockId] = NVM_BLOCK_TEST_READ_REQUEST_NOT_ACCEPTED;
                NvM_TestDataStruct.CurrentTestBlockId++;
                if(NvM_TestDataStruct.CurrentTestBlockId > NVM_NUM_OF_BLOCKS)
                {
                    NvM_TestStateMachine = NVM_TEST_COMPLETE;
                }
                else
                {
                    NvM_TestStateMachine = NVM_TEST_WRITE_BLOCK_INITATE;
                }
            }
        break;

        case NVM_TEST_READ_BLOCK_WAIT:
            (void)NvM_GetErrorStatus(NvM_TestDataStruct.CurrentTestBlockId, &NvM_Result);
            if(NVM_REQ_PENDING != NvM_Result)
            {
                if(NvM_Result == NVM_REQ_OK)
                {
                    NvM_TestDataStruct.NvMBlockTestResult[NvM_TestDataStruct.CurrentTestBlockId] = NVM_BLOCK_TEST_READ_REQUEST_COMPLETED;
                    NvM_TestStateMachine = NVM_TEST_VALIDATE_WRITE_AND_READ;
                }
                else
                {
                    NvM_TestDataStruct.NvMBlockTestResult[NvM_TestDataStruct.CurrentTestBlockId] = NVM_BLOCK_TEST_READ_REQUEST_FAILED;
                    NvM_TestDataStruct.CurrentTestBlockId++;
                    if(NvM_TestDataStruct.CurrentTestBlockId > NVM_NUM_OF_BLOCKS)
                    {
                        NvM_TestStateMachine = NVM_TEST_COMPLETE;
                    }
                    else
                    {
                        NvM_TestStateMachine = NVM_TEST_WRITE_BLOCK_INITATE;
                    }
                }
            }
        break;

        case NVM_TEST_VALIDATE_WRITE_AND_READ:
            BlockLength = NvM_BlockConfig[NvM_TestDataStruct.CurrentTestBlockId].NvBlockLength;
            if(FALSE != MemLib_MemCmp(&NvM_TestWriteBuffer[0],&NvM_TestReadBuffer[0],BlockLength))
            {
                NvM_TestDataStruct.NvMBlockTestResult[NvM_TestDataStruct.CurrentTestBlockId] = NVM_BLOCK_TEST_COMPLETED_SUCCESSFULLY;
            }
            else
            {
                NvM_TestDataStruct.NvMBlockTestResult[NvM_TestDataStruct.CurrentTestBlockId] = NVM_BLOCK_TEST_COMPLETED_VALIDATION_FAILED;
            }
            NvM_TestDataStruct.CurrentTestBlockId++;
            if(NvM_TestDataStruct.CurrentTestBlockId > NVM_NUM_OF_BLOCKS)
            {
                NvM_TestStateMachine = NVM_TEST_COMPLETE;
            }
            else
            {
                NvM_TestStateMachine = NVM_TEST_WRITE_BLOCK_INITATE;
            }
        break;

        case NVM_TEST_COMPLETE:
            NvM_TestDataStruct.NvMTestFailiureCount = 0;
            for(fl_BlockIdIteration = 2U; fl_BlockIdIteration < NVM_NUM_OF_BLOCKS; fl_BlockIdIteration++)
            {
                if(NvM_TestDataStruct.NvMBlockTestResult[fl_BlockIdIteration] != NVM_BLOCK_TEST_COMPLETED_SUCCESSFULLY)
                {
                    NvM_TestDataStruct.NvMTestFailiureCount++;
                }
            }
            if(NvM_TestDataStruct.NvMTestFailiureCount > 0U)
            {
                NvM_TestDataStruct.TestStatus = NVM_TEST_FAILED;
            }
            else
            {
                NvM_TestDataStruct.TestStatus = NVM_TEST_SUCCESS;
            }
            NvM_TestStateMachine = NVM_TEST_DISABLE_WRITE_PROTECT_ALL_BLOCKS;
        break;

        case NVM_TEST_DISABLE_WRITE_PROTECT_ALL_BLOCKS:
            for(fl_BlockIdIteration = 2U; fl_BlockIdIteration < NVM_NUM_OF_BLOCKS; fl_BlockIdIteration++)
            {
                RetVal = NvM_SetBlockProtection(fl_BlockIdIteration, FALSE);
            }
            NvM_TestStateMachine = NVM_TEST_IDLE;
        break;

        default:

        break;
    }
}

void NvM_BlockTest(void)
{
    volatile uint8 t_state_u8 = 0;
    uint8 t_blockStatus_u8 = 0;
    volatile uint16 t_blockId_u16 = 0xFFFFU;
    switch (t_state_u8)
    {
        case 1:
            t_state_u8 =3U;
            NvM_WriteBlock(t_blockId_u16, NULL);
            break;

        case 2:
            t_state_u8 =3U;
            NvM_ReadBlock(t_blockId_u16, NULL);
            break;

        case 3:
            if (E_OK == NvM_GetErrorStatus(t_blockId_u16, &t_blockStatus_u8))
            {
                if (NVM_REQ_PENDING!= t_blockStatus_u8)
                {
                    t_state_u8 = 0;
                }
            }
            break;

        case 4:
            t_state_u8 =3U;
            NvM_WriteBlock(t_blockId_u16,&NvM_TestWriteBuffer[0]);
            break;

        case 5:
            t_state_u8 =3U;
            NvM_ReadBlock(t_blockId_u16, &NvM_TestReadBuffer[0]);
            break;
            
        default:
            break;
    }

}

#endif /* NVM_TEST_C */
