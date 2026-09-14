/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2012. Visteon Corporation owns all rights to           *
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
*  File Name         :  NvM_Types.h                                          *
*  Module Short Name :  NvMMgr                                               *
*  VOBName           :                                                       *
*  Author            : vbalakr3                                              *
*  Description       : This file contains the typedefs for nvM               *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :                                                         *
*                                                                            *
******************************************************************************/

#ifndef FEE_TRACE_H
#define FEE_TRACE_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Std_Types.h"
#include "MemIf_Types.h"
#include "CanIf.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/


/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/


/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

//#define FEE_TRACE_ENABLE
#ifdef FEE_TRACE_ENABLE

#define FEE_TRACE_BUFFER_LOG     STD_OFF
#define FEE_TRACE_CAN_LOG        STD_ON
#define FEE_TRACE_PERF_RESET     STD_OFF


typedef enum{
    FEE_INIT=0,
    WRITE_ACCEPTED,
    WRITE_REJECTED_BUSY,
    WRITE_REJECTED_OUT_OF_RANGE,
    WRITE_RESET_INFO_JOB_ACCEPTED,
    WRITE_RESET_INFO_JOB_REJECTED,
    WRITE_RESET_INFO_JOB_FAILED,
    WRITE_RESET_INFO_JOB_SUCCESS,
    WRITE_HEADER_JOB_ACCEPTED,
    WRITE_JOB_REJECTED,
    WRITE_JOB_FAILED,
    WRITE_PAYLOAD_JOB_REJECTED,
    WRITE_PAYLOAD_JOB_FAILED,
    WRITE_HEADER2_JOB_REJECTED,
    WRITE_HEADER2_JOB_FAILED,
    WRITE_IDLE_RESET_INFO_JOB_ACCEPTED,
    WRITE_IDLE_RESET_INFO_JOB_REJECTED,
    WRITE_IDLE_RESET_INFO_JOB_FAILED,
    ERASE_RESET_INFO_JOB_ACCEPTED,
    ERASE_RESET_INFO_JOB_REJECTED,
    ERASE_RESET_INFO_JOB_SUCCESS,
    ERASE_RESET_INFO_JOB_FAILED,
    SECTOR_ERASE_ACCEPTED,
    SECTOR_ERASE_REJECTED,
    SECTOR_ERASE_FAILED,
    SECTOR_ERASE_COMPLETED,
    ERASE_IDLE_RESET_INFO_JOB_ACCEPTED,
    ERASE_IDLE_RESET_INFO_JOB_REJECTED,
    ERASE_IDLE_RESET_INFO_JOB_FAILED,
    ERASE_IDLE_RESET_INFO_JOB_SUCCESS,
    SECTOR_SW_RESET_INFO_JOB_ACCEPTED,
    SECTOR_SW_RESET_INFO_JOB_REJECTED,
    SECTOR_SW_RESET_INFO_JOB_FAILED,
    SECTOR_SW_RESET_INFO_JOB_SUCCESS,
    SECTOR_SW_HEADER_WRITE_ACCEPTED,
    SECTOR_SW_HEADER_WRITE_REJECTED,
    SECTOR_SW_HEADER_WRITE_SUCCESS,
    SECTOR_SW_HEADER_WRITE_FAILED,
    SECTOR_SW_BLOCK_READ_JOB_REJECTED,
    SECTOR_SW_BLOCK_READ_JOB_VALIDATION_FAILED,
    SECTOR_SW_TRAVERSE_READ_JOB_REJECTED,
    SECTOR_SW_TRAVERSE_READ_FINISHED_NO_FOUND,
    SECTOR_SWITCH_TRAVERSE_VALIDATE_JOB_REJECTED,
    SECTOR_SW_TRAVERSE_READ_JOB_FAILED,
    SECTOR_SW_BLOCK_WRITE_JOB_REJECTED,
    SECTOR_SW_BLOCK_WRITE_JOB_FAILED,
    SECTOR_SW_FOOTER_WRITE_JOB_ACCEPTED,
    SECTOR_SW_FOOTER_WRITE_JOB_REJECTED,
    SECTOR_SW_FOOTER_WRITE_JOB_SUCCESS,
    SECTOR_SW_FOOTER_WRITE_JOB_FAILED,
    TEST_RESET,
    TEST_READALL_RESET,
    DET_RESET,
    RESET_INFO_TRAVERSE_COMPLETED,
    READ_REJECTED_BUSY,
    READ_ACCEPTED,
	PART_0_NFA,
	PART_1_NFA,
	PART_2_NFA,
	PART_3_NFA,
	PART_4_NFA,
	PART_5_NFA,
	PART_6_NFA,
	PART_TRAVERSE_RESULT,
	PART_RESET_INFO,
	RESET_INFO_PART,
	UPDATE_RESET_INFO_COMPLETED,
    __fls_read_failures_start_marker,
    READ_PARTITION_SEC_HEAD_FAILED,
    READ_PARTITION_SEC_FOOT_FAILED,
    READ_PARTITION_BLOCK_HEAD_FAILED,
    READ_PARTITION_BLOCK_READ_FST_FAILED,
    SECTOR_SW_BLOCK_READ_JOB_FAILED,
    READ_SEC_SWITCH_BLOCK_READ_TRV_FAILED,
    READ_SEC_SWITCH_BLOCK_READ_TRV_VALIDATE_FAILED,
    __fls_read_failures_end_marker
}Fee_TraceCallerIDType;

#if(FEE_TRACE_BUFFER_LOG == STD_ON)
typedef struct
{
    Fee_TraceCallerIDType  Caller_Id;
    uint8                  BlockId;
    uint8                  SectorId;
    uint16                  Address;
}Fee_TraceBufferType;

#define TRACE_COUNT        450
#define RESET_TRACE_COUNT  5
# pragma ghs section bss = ".reset_safe_noinit"
static volatile uint16 Fee_TraceBufferIndex;
static volatile Fee_TraceBufferType Fee_TraceBuffer[TRACE_COUNT];
static volatile Fee_InterruptedJobAdminDataType Fee_TraceInterruptedJobAdminData[RESET_TRACE_COUNT][FEE_NUM_PARTITIONS];
static volatile uint8 Fee_ResetTraceCount;
volatile uint8 SystemResetCount;
# pragma ghs section bss =default
#endif

#if(FEE_TRACE_CAN_LOG == STD_ON)
typedef struct 
{
    uint8   Head;
    uint8   Foot;
    uint8   CallId;
    uint8   SecId;
    uint32  Address;
}Fee_TraceDataType;
static Fee_TraceDataType u8JobReqHookData;
static PduInfoType  JobReqHook_PDU;
#endif


void FEE_TRACE(Fee_TraceCallerIDType CallerId, uint8 SectorId, uint16 Address);

void FEE_TRACE(Fee_TraceCallerIDType CallerId, uint8 SectorId, uint16 Address)
{
#if(FEE_TRACE_BUFFER_LOG == STD_ON)
    uint8 fl_PartionNo = Fee_Job.CurPartition;
    uint8 blkcfg_fl_PartionNo = Fee_BlockConfig[Fee_Job.BlockId].PartitionNo;
	if(SystemResetCount < 4)
	{
		Fee_TraceBuffer[Fee_TraceBufferIndex].Caller_Id = CallerId;
		Fee_TraceBuffer[Fee_TraceBufferIndex].BlockId = Fee_Job.BlockId;
		Fee_TraceBuffer[Fee_TraceBufferIndex].SectorId = SectorId;
		Fee_TraceBuffer[Fee_TraceBufferIndex].Address = Address;
		Fee_TraceBufferIndex += 1;            

		if(Fee_TraceBufferIndex >= TRACE_COUNT)
		{
			Fee_TraceBufferIndex = 0;
		} 
	}
#endif

#if(FEE_TRACE_CAN_LOG == STD_ON)
    if ((__fls_read_failures_start_marker < CallerId) && (__fls_read_failures_end_marker > CallerId))
    {
        u8JobReqHookData.Head = 0x1D;
        u8JobReqHookData.Foot = 0xD1;
        u8JobReqHookData.CallId = CallerId;
        u8JobReqHookData.SecId = SectorId;
        u8JobReqHookData.Address = Address;
        JobReqHook_PDU.SduDataPtr = (uint8 *)u8JobReqHookData.Head;
        JobReqHook_PDU.SduLength = sizeof(Fee_TraceDataType);
        CanIf_Transmit(CANIF_PDU_DEV_KOMBI_SUP12, &JobReqHook_PDU);
    }
#endif
}

#if (FEE_TRACE_PERF_RESET == STD_ON)
extern void Mcu_PerformReset(void);

void Fee_TracePerformReset(uint8 id)
{
    if(id == 1)
    {
		FEE_TRACE(RESET_INFO_PART,0,Fee_ResetInfoData.PartitionState);
		FEE_TRACE(RESET_INFO_PART,0,Fee_ResetInfoData.InterruptedJobSectorState);
		FEE_TRACE(PART_0_NFA,Fee_Partition[0].CurrentSectorId,(uint16)Fee_Partition[0].NextFreeAddress);
		FEE_TRACE(PART_1_NFA,Fee_Partition[1].CurrentSectorId,(uint16)Fee_Partition[1].NextFreeAddress);
		FEE_TRACE(PART_2_NFA,Fee_Partition[2].CurrentSectorId,(uint16)Fee_Partition[2].NextFreeAddress);
		FEE_TRACE(PART_3_NFA,Fee_Partition[3].CurrentSectorId,(uint16)Fee_Partition[3].NextFreeAddress);
		FEE_TRACE(PART_4_NFA,Fee_Partition[4].CurrentSectorId,(uint16)Fee_Partition[4].NextFreeAddress);
		FEE_TRACE(PART_5_NFA,Fee_Partition[5].CurrentSectorId,(uint16)Fee_Partition[5].NextFreeAddress);
		FEE_TRACE(PART_6_NFA,Fee_Partition[6].CurrentSectorId,(uint16)Fee_Partition[6].NextFreeAddress);
		FEE_TRACE(TEST_RESET,0,0);
        Mcu_PerformReset();
    }
    if(id ==2)
    {
        FEE_TRACE(TEST_READALL_RESET,0,0);
        Mcu_PerformReset();
    }
    if(id == 3)
    {
        FEE_TRACE(DET_RESET,0,0);
    }
    
}

extern Std_ReturnType NvM_Test_ReadAll_Notify(void);
static void Fee_TraceBackupTraversedResetInfoData(void);
void Fee_TraceBackupTraversedResetInfoData(void)
{
}
#endif

#endif

#endif /* NVM_TYPES_H */

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
/*Date              : 21-08-2015                                            */
/*Version           :                                                       */
/*By                : vbalakr3                                              */
/*Traceability      :                                                       */
/*Change Description: Datadesign And Framework implemented, Initial Version */
/*--------------------------------------------------------------------------*/
