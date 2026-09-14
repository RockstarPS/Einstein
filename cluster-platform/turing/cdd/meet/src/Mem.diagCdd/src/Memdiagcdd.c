/*=================================================================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2001. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**==================================================================================================================
**
** Name:           Memdiagcdd.c
**
** Description:    contains memory related services.checks if software in Manufacturing mode before executing service request
**
**
**===================================================================================================================*/

#ifndef MEMDIAGCDD_C
#define MEMDIAGCDD_C

/*====================================================================================================================
**  I N C L U D E   F I L E S
**===================================================================================================================*/

#include "Mgrdiagcdd.h"
#include "Mgrdiagcdd_cfg.h"
#include "MemLib.h"
#include "Memdiagcdd.h"
#include "Memdiagcdd_cfg.h"
#include "NvM_Cfg.h"

/*====================================================================================================================
**   I N T E R N A L   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/
#ifdef MEMDIAG_MEMORY_READ_WRITE_BY_ADDRESS
#ifdef MEMDIAG_MAX_NUMBER_OF_BYTES_READ_WRITE
#if MEMDIAG_MAX_NUMBER_OF_BYTES_READ_WRITE > 500U
#error Value of MEMDIAG_MAX_NUMBER_OF_BYTES_READ_WRITE should be within 500
#else
#endif
#else
#error MEMDIAG_MAX_NUMBER_OF_BYTES_READ_WRITE macro should be defined within the value of 500
#endif
#endif

#ifdef MEMDIAG_MEMORY_VALIDITY_CHECK
#ifdef MEMDIAG_MAX_NUMBER_OF_RAM_BYTES_TO_BE_TEST
#if (MEMDIAG_MAX_NUMBER_OF_RAM_BYTES_TO_BE_TEST > 25U) || (MEMDIAG_MAX_NUMBER_OF_RAM_BYTES_TO_BE_TEST < 1U)
#error The value of MEMDIAG_BYTE_TO_BE_WRITE_IN_RAM should be within the range of 1 to 25
#else
#endif
#endif
#endif

/*=====================================================================================================================
**  T Y P E    D E C L A R A T I O N S
**====================================================================================================================*/
#ifdef MEMWRITETESTENABLE
static eRoutineStatus MemWriteTst_RCStatus = eROUTINE_INACTIVE;
#endif

#if defined(HYPERFLASHCHKSUMTSTENABLE) || defined(MEMDIAG_MEMORY_VALIDITY_CHECK)
static eRoutineStatus MemDiag_CheckSum_RCStatus[NUMBER_OF_HYPER_FLASH] = {eROUTINE_INACTIVE}; /*RC Status for Hyperflash*/
#endif

#if defined(NVMVALIDITYCHKENABLE) || defined(MEMDIAG_MEMORY_VALIDITY_CHECK)
static NvM_BlockIdType CurrentReadBlockId = 0;
#endif

#ifdef MEMWRITETESTENABLE
eMemMgrAction MemMgrFlag;
#endif

#ifdef MEMDIAG_MEMORY_VALIDITY_CHECK
static eRoutineStatus Memdiag_NvMValidity_RCStatus = eROUTINE_INACTIVE;
#endif

#ifdef MEMDIAG_MEMORY_VALIDITY_CHECK
static eRoutineStatus Memdiag_RAMValidity_RCStatus = eROUTINE_INACTIVE;
#endif

#if defined(MEMDIAG_MEMORY_VALIDITY_CHECK) || defined(MEMDIAG_VIP_GIP_MEMORY_CHECKSUM_TEST)
static eRoutineStatus Memdiag_IntFlashValidity_RCStatus = eROUTINE_INACTIVE;
#endif

#ifdef MEMDIAG_VIP_GIP_MEMORY_CHECKSUM_TEST
static eRoutineStatus Memdiag_NANDFlashChecksum_RCStatus = eROUTINE_INACTIVE;
static eRoutineStatus Memdiag_NORFlashChecksum_RCStatus = eROUTINE_INACTIVE;
static eRoutineStatus Memdiag_DisplayMicroROMChecksum_RCStatus = eROUTINE_INACTIVE;
#endif

#ifdef AUTO_CONFIGURE_OR_VERIFY
static eRoutineStatus Memdiag_AutoConfigorVerify_RCStatus = eROUTINE_INACTIVE;
static NVMWriteRequestState Memdiag_AutoConfig_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
eNvmStatus NvmStatus = eNVM_NOT_STARTED;
static int LAST_NVM_DR_STARTED = 0; // i.e 0-NONE; 1- AUTO_CONFIG_VERIFY
#endif

#ifdef PROGRAM_NVM_FROM_ROM
static eRoutineStatus Memdiag_ProgramNVM_Restore_RCStatus = eROUTINE_INACTIVE;
static NvM_BlockIdType Memdiag_NVM_BlockID = 0U;
static NVMWriteRequestState Memdiag_ProgramROM_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
#endif

#ifdef MEMDIAG_ODOMETER_NVM_ROUTINE
static eRoutineStatus Memdiag_OdometerNVM_RCStatus = eROUTINE_INACTIVE;
static boolean maxOdoResetDone = FALSE;
#endif
/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/
#ifdef MFGMODEREQENABLE
static NVMWriteRequestState Memdiag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
static boolean bManufMode_Write_Flag_EN = FALSE;
static boolean Manuf_NVM_Write_sync = FALSE;
static uint16 NVMWriteWaitCount = NVM_WRITE_TIMEOUT_COUNT_IN_10MS;
#endif

#if defined(NVMVALIDITYCHKENABLE) || defined(MEMDIAG_MEMORY_VALIDITY_CHECK)
static boolean NVMReadAllRequest = FALSE;
static uint8 NvmValidityCheckStatus = NVM_VALIDITYCHECK_NONE;
static uint8 NvmValidityStatusPtr[NUMBER_OF_NVBLOCKS] = {0};
#endif

#ifdef MEMDIAG_MEMORY_VALIDITY_CHECK
static uint8 NvmValidityStatus = NVM_VALIDITY_NOT_OK;
#endif

#ifdef NVMACCESSBYBLOCKIDRCENABLE
static boolean NVMReadBlockRCRequest = FALSE;
static uint8 NVM_RCRead_buffer_u8[MEMDIAG_MAX_BYTES_FOR_NVM];
static eRoutineStatus NvmAccessbyBlockID_RCStatus = eROUTINE_INACTIVE;
static uint16 Routine_nvm_blockID = 0U;
#endif

#ifdef MEMWRITETESTENABLE
uint8 MemDiag_RoutineState = 0U; /* status of MemDiag Routine Control in progress or NOT (Possible value 0 or 1)*/
uint8 MemDiag_PreviousLogicalMarker = 0U;
uint8 NumOfBytesToBeWritten = 0U;
uint8 WriteErrorCounter = 0U;
uint8 NumOfBytesToBeRead = 0U;
uint8 MemDiag_ReadBuffer[256] = {0}; /* to store response data of Read Start Routine control and transmit when requested by Status request */
uint8 MemDiag_WriteBuffer[256] = {0};
uint32 MemAddress = 0U;
#endif

#if defined(NVMACCESSBYBLOCKIDREADWRITEENABLE) || defined(EXTNVMACCESSBYBLOCKIDREADWRITEENABLE)
static boolean NVMReadBlockRequest = FALSE;
static boolean NVMWriteBlockRequest = FALSE;
static uint8 NVM_write_buffer_u8[MEMDIAG_MAX_BYTES_FOR_NVM];
#endif

#if defined(HYPERFLASHCHKSUMTSTENABLE) || defined(MEMDIAG_MEMORY_VALIDITY_CHECK)
static uint8 hyperflash_index = 0U;
#ifdef MARKERADDRESSCHECKENABLE
static uint8 MemDiag_CheckSum_Validity_Status[NUMBER_OF_HYPER_FLASH] = {0}; /* Checksum Validity Status for Hyperflash.*/
#endif
#endif

#if defined(NVMACCESSBYBLOCKIDREADWRITEENABLE) || defined(NVMVALIDITYCHKENABLE) || defined(EXTNVMACCESSBYBLOCKIDREADWRITEENABLE) || defined(MEMDIAG_MEMORY_VALIDITY_CHECK)
static uint8 NVM_read_buffer_u8[MEMDIAG_MAX_BYTES_FOR_NVM];
#endif

#ifdef MEMDIAG_MEMORY_VALIDITY_CHECK

#ifdef MEMDIAG_INTFLASH_VALIDITY_CHECK_VIA_MARKERS
static uint8  Memdiag_IntFlashValidity_Status = 0u;
#endif 
static uint8 Memdiag_RAMValidity_Status = 0U;
static uint8 l_RAM_buffer_U8A[MEMDIAG_MAX_NUMBER_OF_RAM_MEMORY_SETS][MEMDIAG_MAX_NUMBER_OF_RAM_BYTES_TO_BE_TEST];
static uint8 l_RAM_Write_Data[MEMDIAG_MAX_NUMBER_OF_RAM_BYTES_TO_BE_TEST];
#endif

#ifdef AUTO_CONFIGURE_OR_VERIFY
static uint8 NVMConfigorVerifyStatus = NVM_CONFIGVERIFY_NONE;
static uint8 NVM_Config_Verify_Buffer[CONFIG_OR_VERIFY_LENGTH];
static uint8 NVMreadbuffer[CONFIG_WRITE_DATA_LENGTH] = {0};
static Std_ReturnType AutoConfig_ret = E_NOT_OK;
#endif

#ifdef PROGRAM_NVM_FROM_ROM
static uint8 NvmRestore_RCStatus = PROGRAM_NVM_FROM_ROM_NONE;
#endif

/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/
#if defined(HYPERFLASHCHKSUMTSTENABLE) || defined(MEMDIAG_MEMORY_VALIDITY_CHECK)
#ifdef MARKERADDRESSCHECKENABLE
static Std_ReturnType HyperFlash_Validity_check(MemDiag_HyperFlashtype *hyperflash);
#endif
#endif

#ifdef MEMWRITETESTENABLE
static void MemDiag_SetRoutineStatus(uint8 state);
static Std_ReturnType Get_MEM_OperState(void);
static Std_ReturnType MemDiag_AddRangeCheck(uint8 Logical_Marker, uint32 address, uint8 Length);
static Std_ReturnType Is_MemoryOperFinish(uint8 state);
#endif

#if defined(NVMVALIDITYCHKENABLE) || defined(MEMDIAG_MEMORY_VALIDITY_CHECK)
static Std_ReturnType NvmAdapterMdl_ReadBlock(NvM_BlockIdType BlockId);
#endif

#ifdef MEMDIAG_MEMORY_VALIDITY_CHECK
/* Can be used for future purpose
 *
 *static Std_ReturnType Memdiag_IntFlash_Validity_check(Memdiag_IntFlashtype *Intflash);
 */
static Std_ReturnType MemDiag_RamTest_RCStart(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType MemDiag_RamTest_RCStop(uint8 *Data, const uint8 *ErrorCode);
static Std_ReturnType MemDiag_RamTest_RCStatus(uint8 *Data, const uint8 *ErrorCode);
static Std_ReturnType Memdiag_RAM_Validity_check(void);
#endif

#if defined(MEMDIAG_MEMORY_VALIDITY_CHECK) || defined(MEMDIAG_VIP_GIP_MEMORY_CHECKSUM_TEST)
static Std_ReturnType Memdiag_IntflashValidityCheck_RCStart(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType Memdiag_IntflashValidityCheck_RCStop(uint8 *Data, const uint8 *ErrorCode);
static Std_ReturnType Memdiag_IntflashValidityCheck_RCStatus(uint8 *Data, const uint8 *ErrorCode);
#endif

#if defined(MEMDIAG_MEMORY_READ_WRITE_BY_ADDRESS) || defined(MEMDIAG_MEMORY_VALIDITY_CHECK)
static void MemmDiag_MemCpy(void *const pDest, const void *const pSrc, const uint16 BytesCount);
#endif

#ifdef MEMDIAG_VIP_GIP_MEMORY_CHECKSUM_TEST
static uint8 checksum_index = 1U;
static Std_ReturnType Memdiag_NAND_Checksum_Check_RCStart(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType Memdiag_NAND_Checksum_Check_RCStop(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType Memdiag_NAND_Checksum_Check_RCStatus(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType Memdiag_NOR_Checksum_Check_RCStart(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType Memdiag_NOR_Checksum_Check_RCStop(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType Memdiag_NOR_Checksum_Check_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef MFGMODEREQENABLE
/*=====================================================================================================================
**
** Function Name    :  MemDiag_MfgModeRequest_Read
**
** Visibility       :  Private
**
** Description      :  calls API to read manufacturing mode request
**
** Invocation       :  Mem.diagcdd , Function:Memdiag_ManufacturingModeRequested_Read
**
** Inputs           :  Data[Out]:manufacturing mode request
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType MemDiag_MfgModeRequest_Read(uint16 *Data)
{
    Std_ReturnType ret = E_NOT_OK;
    ret = MfgModeReqConfig_U16.MemDiag_Read(Data);
    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  MemDiag_MfgModeRequest_Write
**
** Visibility       :  Private
**
** Description      :  calls API to write manufacturing mode request
**
** Invocation       :  Mem.diagcdd , Function:Memdiag_ManufacturingModeRequested_Write
**
** Inputs           :  Data[In]:manufacturing mode request
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType MemDiag_MfgModeRequest_Write(uint16 Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    NvM_RequestResultType JobResult = 0U;
    #ifdef MEETMODE_ENTRY_DISABLE
    uint16 MfgModeReq = 0U;
    #endif

    switch (Memdiag_CurrentNVMWriteReqState)
    {
    case eNVMWrite_InitiateRequest:
        #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
        MemDiagNvmJobResult_U8.MemDiag_Write(0); // clear NVM Jobresult
        #endif

        // Check whether manuf mode write is already in progress
        if (FALSE == Manuf_NVM_Write_sync)
        {
            #ifdef MEETMODE_ENTRY_DISABLE
            // Read Mfg mode
            (void)MfgModeReqConfig_U16.MemDiag_Read(&MfgModeReq);

            // If Mfg mode has disable meet entry then do not take any write requests
            if (MfgModeReq == MEET_ENTRY_DISABLE_NVM_FLAG)
            {
                ret = E_NOT_OK;
                ErrorCode[0U] = DCM_E_CONDITIONSNOTCORRECT;
            }
            else
            #endif
            {
                // Trigger NVM write
                (void)MfgModeReqConfig_U16.MemDiag_Write(Data);
                Manuf_NVM_Write_sync = TRUE; // Set sync_flag
                ret = DCM_E_PENDING;
                Memdiag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
        }
        else
        {
            ret = E_NOT_OK;
            ErrorCode[0U] = DCM_E_CONDITIONSNOTCORRECT;
        }
        break;

    case eNVMWrite_WaitForResponse:
        #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
        MemDiagNvmJobResult_U8.MemDiag_Read(&JobResult); // Read NVM Jobresult
        #else
        MfgModeReqConfig_U16.MemDiag_Jobstatus(&JobResult);
        #endif

        if (JobResult == (uint8)NVM_REQ_PENDING)
        {
            ret = DCM_E_PENDING;
        }
        else if (JobResult == (uint8)NVM_REQ_OK)
        {
            Memdiag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
            ret = DCM_E_OK;
            Manuf_NVM_Write_sync = FALSE; // Clear sync flag
        }
        else
        {
            Memdiag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
            ret = DCM_E_NOT_OK;
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            Manuf_NVM_Write_sync = FALSE; // Clear sync flag
        }
        break;

    default:
        ret = DCM_E_NOT_OK;
        break;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Memdiag_ManufacturingModeRequested_Read
**
** Visibility       :  Public
**
** Description      :  Reads manufacturing mode request based on values in NVM
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA4C
**
** Inputs           :  Data[Out]:updated with manufacturing mode request state
**                     Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_ManufacturingModeRequested_Read(uint8 *Data, const uint8 *ErrorCode)
{
    UNUSED(ErrorCode);
    Std_ReturnType ret = E_NOT_OK;
    uint16 MfgModeReq = 0U;

    ret = MemDiag_MfgModeRequest_Read(&MfgModeReq);

    if (MfgModeReq == CUST_NVM_FLAG)
    {
        Data[DATA_BYTE_0] = NORMAL_SESSION;
    }
    else if (MfgModeReq == MEET_NVM_FLAG)
    {
        Data[DATA_BYTE_0] = MEET_SESSION;
    }
    else if (MfgModeReq == CANWK_NVM_FLAG)
    {
        Data[DATA_BYTE_0] = CANWAKEUP_SESSION;
    }
    #ifdef MEETMODE_ENTRY_DISABLE
    else if (MfgModeReq == MEET_ENTRY_DISABLE_NVM_FLAG)
    {
        Data[DATA_BYTE_0] = MEET_ENTRY_DISABLE_SESSION;
    }
    #endif
    else
    {
        Data[DATA_BYTE_0] = UNDEFINED_SESSION;
    }

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Memdiag_ManufacturingModeRequested_Write
**
** Visibility       :  Public
**
** Description      :  Writes manufacturing mode request
**
** Invocation       :  MeetMgr.diagcdd, Function:Write_Diag_FA4C
**
** Inputs           :  Data[In]:contains manufacturing mode request state
**                     Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_ManufacturingModeRequested_Write(const uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;

    if (Data[DATA_BYTE_0] == MEET_SESSION)
    {
        ret = MemDiag_MfgModeRequest_Write(MEET_NVM_FLAG, ErrorCode);
    }
    else if (Data[DATA_BYTE_0] == NORMAL_SESSION)
    {
        ret = MemDiag_MfgModeRequest_Write(CUST_NVM_FLAG, ErrorCode);
    }
    #ifdef MEETMODE_ENTRY_DISABLE
    else if (Data[DATA_BYTE_0] == MEET_ENTRY_DISABLE_SESSION)
    {
        ret = MemDiag_MfgModeRequest_Write(MEET_ENTRY_DISABLE_NVM_FLAG, ErrorCode);
    }
    #endif
    else
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  MemDiag_Manuf_Flag_Write_Status
**
** Visibility       :  Private
**
** Description      :  to verify the NVM write status of Manuf Flag
**
** Invocation       :  Mem.diagcdd
**
** Inputs           :  None
**
** Outputs          :  None
**
** Critical Section :  No
**
**====================================================================================================================*/
void MemDiag_Manuf_Flag_Write_Status(void)
{
    NvM_RequestResultType ManufNVM_JobStatus = E_NOT_OK;
    boolean ManufMode_Write_Status = FALSE;

    // bManufMode_Write_Flag_EN - will be enabled once ManufMode_flag Write action is triggered
    if (TRUE == bManufMode_Write_Flag_EN)
    {
        MfgModeReqConfig_U16.MemDiag_Jobstatus(&ManufNVM_JobStatus);
        if ((uint8)NVM_REQ_PENDING == ManufNVM_JobStatus)
        {
            if (NVMWriteWaitCount != (uint16)0U)
            {
                NVMWriteWaitCount--;
            }

            // wait and check
            if (DIDZERO == NVMWriteWaitCount)
            {
                // WRITE TIMEOUT
                bManufMode_Write_Flag_EN = FALSE; // clear periodic function EN flag
                Manuf_NVM_Write_sync = FALSE;     // clear MfgMode write_sync flag

                ManufMode_Write_Status = FALSE;
                // NOTIFY_WRITE_STATUS
                MANUFMODE_NVM_WRITE_NOTIFY(ManufMode_Write_Status);
            }
        }
        else if ((uint8)NVM_REQ_OK == ManufNVM_JobStatus)
        {
            // WRITE_SUCCESS
            bManufMode_Write_Flag_EN = FALSE; // clear periodic function EN flag
            Manuf_NVM_Write_sync = FALSE;     // clear MfgMode write_sync flag

            ManufMode_Write_Status = TRUE;
            // NOTIFY_WRITE_STATUS
            MANUFMODE_NVM_WRITE_NOTIFY(ManufMode_Write_Status);
        }
        else
        {
            // WRITE FAILED
            bManufMode_Write_Flag_EN = FALSE; // clear periodic function EN flag
            Manuf_NVM_Write_sync = FALSE;     // clear MfgMode write_sync flag

            ManufMode_Write_Status = FALSE;
            // NOTIFY_WRITE_STATUS
            MANUFMODE_NVM_WRITE_NOTIFY(ManufMode_Write_Status);
        }
    }
}

Std_ReturnType Memdiag_Write_Mfg_Flag(const uint16 *Data)
{
    Std_ReturnType ret = E_NOT_OK;
    uint16 MfgFlag_data_u16 = DIDZERO;

    ret = MfgModeReqConfig_U16.MemDiag_Read(&MfgFlag_data_u16); // READ MANUF_FLAG from NVM

    if ((uint8)E_OK == ret)
    {
        if (Data[0] == MfgFlag_data_u16)
        {
            // NVM ALREADY HAS SAME DATA
            // NOTIFY_WRITE_STATUS
            MANUFMODE_NVM_WRITE_NOTIFY(TRUE);
        }
        else
        {
            // Check if mfg_mode_flag NVM variable write is already in progress
            if (FALSE == Manuf_NVM_Write_sync)
            {
                Manuf_NVM_Write_sync = TRUE;
                bManufMode_Write_Flag_EN = TRUE;
                (void)MfgModeReqConfig_U16.MemDiag_Write(Data[0]); // TRIGGER WRITE
                NVMWriteWaitCount = NVM_WRITE_TIMEOUT_COUNT_IN_10MS;
            }
            else
            {
                // Mfg_mode_flag NVM variable write is already in progress and can't trigger another write of same NVM element now
                ret = E_NOT_OK;
            }
            MANUFMODE_NVM_WRITE_NOTIFY(FALSE);
        }
    }

    return ret;
}

#ifdef MFGMODESTATUS
Std_ReturnType Memdiag_Read_ManufModeStatus(EMeetModeStatus *currentstate)
{
    Std_ReturnType ret = E_NOT_OK;
    ret = ManufMode_Status_Check(currentstate);
    return ret;
}
#endif
#endif

#ifdef NVMVALIDITYCHKENABLE
/*=====================================================================================================================
**
** Function Name    :  Memdiag_NVMValidityCheck_Read
**
** Visibility       :  Public
**
** Description      :  Starts and returns status of NVM Validity check
**
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA38
**
** Inputs           :  Data[Out]:NVM Validity Result
                       Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_NVMValidityCheck_Read(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        if (NvmValidityCheckStatus == NVM_VALIDITYCHECK_NONE)
        {
            NvmValidityStatusPtr[0] = Data[0];
            NVMReadAllRequest = TRUE;
            CurrentReadBlockId = 0;
            NvmValidityCheckStatus = NVM_VALIDITYCHECK_START;
            ret = DCM_E_PENDING;
        }
        else if (NvmValidityCheckStatus == NVM_VALIDITYCHECK_DONE)
        {
            /*
             * Below RTE call is commented. Use it as per requirement.
             *
             *  Rte_Call_rp_ProcessDone_ProcessingDone();
             */

            Data[0] = NvmValidityStatusPtr[0];
            NvmValidityCheckStatus = NVM_VALIDITYCHECK_NONE;
            ret = E_OK;
        }
        else
        {
            ret = DCM_E_PENDING;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif
#if defined(NVMVALIDITYCHKENABLE) || defined(MEMDIAG_MEMORY_VALIDITY_CHECK)
/*=====================================================================================================================
**
** Function Name    :  NvmAdapterMdl_ReadBlock
**
** Visibility       :  Private
**
** Description      :  Triggers NVM Read by block
**
**
** Invocation       :  Mem.diagcdd , Function:MemDiag_NVMReadAllBlocks
**
** Inputs           :  Memdiag_NVM_BlockID: Blockid of NVM to be read
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType NvmAdapterMdl_ReadBlock(NvM_BlockIdType BlockId)
{
    Std_ReturnType ret = E_NOT_OK;

    if (BlockId < NUMBER_OF_NVBLOCKS)
    {
        ret = NvmBlockConfig.MemDiag_ReadNvmBlock(Valid_NVBlocks[BlockId], &NVM_read_buffer_u8[2]);
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  MemDiag_NVMReadAllBlocks
**
** Visibility       :  Public
**
** Description      :  NVM Validity check done here by reading all valid NVM Blocks
**
**
** Invocation       :  MeetMgr.diagcdd, Function:CmpActive
**
** Inputs           :  NA

**
** Outputs          :  NA
**
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

void MemDiag_NVMReadAllBlocks(void)
{
    uint8 nvmStatus = NVM_REQ_NOT_OK;

    if (NVMReadAllRequest == TRUE)
    {
        switch (NvmValidityCheckStatus)
        {
        case NVM_VALIDITYCHECK_START:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            MemDiagNvmJobResult_U8.MemDiag_Write(0); /*clear NVM Jobresult*/
            #endif
            CurrentReadBlockId = 0U;
            if (NvmAdapterMdl_ReadBlock(CurrentReadBlockId) == (uint8)E_OK)
            {
                NvmValidityCheckStatus = NVM_VALIDITYCHECK_PROGRESS;
            }
            break;
        case NVM_VALIDITYCHECK_PROGRESS:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            MemDiagNvmJobResult_U8.MemDiag_Read(&nvmStatus); /*Read NVM Jobresult*/
            #else
            if (CurrentReadBlockId < NUMBER_OF_NVBLOCKS)
            {
                (void)MemDiagNvmBlkJobResult.MemDiag_JobResultRead_byBlkID(Valid_NVBlocks[CurrentReadBlockId], &nvmStatus); /*Read NVM Jobresult of the block*/
            }
            #endif
            if (nvmStatus == (uint8)NVM_REQ_OK)
            {
                #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
                nvmStatus = 0U;
                MemDiagNvmJobResult_U8.MemDiag_Write(nvmStatus); /*clear NVM Jobresult*/
                #endif
                CurrentReadBlockId = CurrentReadBlockId + (uint16)1U;
                if (CurrentReadBlockId < NUMBER_OF_NVBLOCKS)
                {
                    if (NvmAdapterMdl_ReadBlock(CurrentReadBlockId) != (uint8)E_OK)
                    {
                        CurrentReadBlockId--;
                    }
                }
                else
                {
                    CurrentReadBlockId = 0U;
                    NVMReadAllRequest = FALSE;
                    *NvmValidityStatusPtr = NVM_VALIDITY_OK;
                    NvmValidityCheckStatus = NVM_VALIDITYCHECK_DONE;
                }
            }
            else if (nvmStatus != (uint8)NVM_REQ_PENDING)
            {
                CurrentReadBlockId = 0U;
                NVMReadAllRequest = FALSE;
                *NvmValidityStatusPtr = NVM_VALIDITY_NOT_OK;
                NvmValidityCheckStatus = NVM_VALIDITYCHECK_DONE;
            }
            else
            {
                /*Do Nothing*/
            }
            break;
        case NVM_VALIDITYCHECK_DONE:
        case NVM_VALIDITYCHECK_NONE:
            break;
        default:
            /*Do Nothing*/
            break;
        }
    }
}
#endif

#if defined(NVMACCESSBYBLOCKIDREADWRITEENABLE) || defined(EXTNVMACCESSBYBLOCKIDREADWRITEENABLE)
/*=====================================================================================================================
**
** Function Name    :  Memdiag_DataflashNVMaccessbyblockID_Read
**
** Visibility       :  Public
**
** Description      :  NVM Read by block id
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA5F
**
** Inputs           :  Data[Out]:256 bytes: contains data of the given NVM Block
                       Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_DataflashNVMaccessbyblockID_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint16 nvm_blockID;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus = 0U, fl_idx_u8;
    boolean NVBlockIDValid = FALSE;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        nvm_blockID = (Data[DATA_BYTE_0] * 256U) + Data[DATA_BYTE_1];
        for (fl_idx_u8 = 0U; fl_idx_u8 < NUMBER_OF_NVBLOCKS; fl_idx_u8++)
        {
            if (Valid_NVBlocks[fl_idx_u8] == nvm_blockID)
            {
                NVBlockIDValid = TRUE;
                break;
            }
        }
        if (TRUE == NVBlockIDValid)
        {
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            MemDiagNvmJobResult_U8.MemDiag_Read(&nvmStatus); /*Read NVM Jobresult*/
            #else
            (void)MemDiagNvmBlkJobResult.MemDiag_JobResultRead_byBlkID(nvm_blockID, &nvmStatus);
            #endif
            if (FALSE == NVMReadBlockRequest)
            {
                if (nvmStatus != (uint8)NVM_REQ_PENDING)
                {
                    MemLib_MemSet(NVM_read_buffer_u8, 0U, MEMDIAG_MAX_BYTES_FOR_NVM); /*Clear the buffer*/
                    (void)NvmBlockConfig.MemDiag_ReadNvmBlock(nvm_blockID, (void *)NVM_read_buffer_u8);
                    NVMReadBlockRequest = TRUE;
                    ret = DCM_E_PENDING;
                }
            }
            else
            {
                if (nvmStatus == (uint8)NVM_REQ_PENDING)
                {
                    ret = DCM_E_PENDING;
                }
                else
                {
                    ret = E_NOT_OK;
                    if (nvmStatus == (uint8)NVM_REQ_OK)
                    {
                        MemLib_MemCpy(Data, NVM_read_buffer_u8, MEMDIAG_MAX_BYTES_FOR_NVM); /*copy data from buffer*/
                        ret = E_OK;
                    }
                    NVMReadBlockRequest = FALSE;
                    #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
                    nvmStatus = 0U;
                    MemDiagNvmJobResult_U8.MemDiag_Write(nvmStatus); /*clear NVM Jobresult*/
                    #endif
                }
            }
        }
        else
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT; /*Invalid NV Block ID*/
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Memdiag_DataflashNVMaccessbyblockID_Write
**
** Visibility       :  Public
**
** Description      :  Writes data to a given NVM Block
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA5F
**
** Inputs           :  Data[In]:contains block id and data to be written to a NVM Block ,Block ID: 2 bytes Data:256 bytes
                       Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_DataflashNVMaccessbyblockID_Write(const uint8 *Data, uint8 *ErrorCode)
{
    uint16 nvm_blockID;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus = 0U, fl_idx_u8;
    boolean NVBlockIDValid = FALSE;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        nvm_blockID = (Data[DATA_BYTE_0] * 256U) + Data[DATA_BYTE_1];
        for (fl_idx_u8 = 0U; fl_idx_u8 < NUMBER_OF_NVBLOCKS; fl_idx_u8++)
        {
            if (Valid_NVBlocks[fl_idx_u8] == nvm_blockID)
            {
                NVBlockIDValid = TRUE;
                break;
            }
        }
        if (TRUE == NVBlockIDValid)
        {
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            MemDiagNvmJobResult_U8.MemDiag_Read(&nvmStatus); /*Read NVM Jobresult*/
            #else
            (void)MemDiagNvmBlkJobResult.MemDiag_JobResultRead_byBlkID(nvm_blockID, &nvmStatus); /*Read NVM Jobresult of the block*/
            #endif
            if (FALSE == NVMWriteBlockRequest)
            {
                if (nvmStatus != (uint8)NVM_REQ_PENDING)
                {
                    NVMWriteBlockRequest = TRUE;
                    MemLib_MemCpy(NVM_write_buffer_u8, &Data[DATA_BYTE_2], MEMDIAG_MAX_BYTES_FOR_NVM); /*Copy input data to buffer*/
                    (void)NvmBlockConfig.MemDiag_WriteNvmBlock(nvm_blockID, (void *)(NVM_write_buffer_u8));
                    ret = DCM_E_PENDING;
                }
            }
            else
            {
                if (nvmStatus == (uint8)NVM_REQ_PENDING)
                {
                    ret = DCM_E_PENDING;
                }
                else if (nvmStatus == (uint8)NVM_REQ_OK)
                {
                    NVMWriteBlockRequest = FALSE;
                    ret = E_OK;
                    #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
                    nvmStatus = 0U;
                    MemDiagNvmJobResult_U8.MemDiag_Write(nvmStatus); /*clear NVM Jobresult*/
                    #endif
                }
                else
                {
                    NVMWriteBlockRequest = FALSE;
                    ret = E_NOT_OK;
                    #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
                    nvmStatus = 0U;
                    MemDiagNvmJobResult_U8.MemDiag_Write(nvmStatus); /*clear NVM Jobresult*/
                    #endif
                }
            }
        }
        else
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT; /*Invalid NV Block ID*/
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef NVMACCESSBYBLOCKIDRCENABLE
/*=====================================================================================================================
**
** Function Name    :  Memdiag_DataflashNVMaccessbyblockID_RCStart
**
** Visibility       :  Public
**
** Description      :  Starts Routine Control reading NVM Block based on input block Id
**
** Invocation       :  MeetMgr.diagcdd  , Function:RC_START_Diag_F20F
**
** Inputs           :  Data[In]:2 bytes: NVM Block ID to be read
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_DataflashNVMaccessbyblockID_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus = 0U;
    uint8 MfgModeActive = 0U;
    boolean NVBlockIDValid = FALSE;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        Routine_nvm_blockID = (Data[DATA_BYTE_0] * 256U) + Data[DATA_BYTE_1];

        #ifdef NVMACCESS_BYPASS_VALIDBLOCK_CHECK
        if ((Routine_nvm_blockID >= NUMBER_OF_NVBLOCKS_MIN) && (Routine_nvm_blockID < NUMBER_OF_NVBLOCKS_MAX))
        {
            NVBlockIDValid = TRUE;
        }
        #else
        for (uint8 fl_idx_u8 = 0; fl_idx_u8 < NUMBER_OF_NVBLOCKS; fl_idx_u8++)
        {
            if (Valid_NVBlocks[fl_idx_u8] == Routine_nvm_blockID)
            {
                NVBlockIDValid = TRUE;
                break;
            }
        }
        #endif

        if (TRUE == NVBlockIDValid)
        {
            if (NvmAccessbyBlockID_RCStatus == eROUTINE_INPROGRESS)
            {
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT; /*Already Routine in progress*/
            }
            else
            {
                #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
                MemDiagNvmJobResult_U8.MemDiag_Read(&nvmStatus); /*Read NVM Jobresult*/
                #else
                (void)MemDiagNvmBlkJobResult.MemDiag_JobResultRead_byBlkID(Routine_nvm_blockID, &nvmStatus); /*Read NVM Jobresult of the block*/
                #endif
                if (FALSE == NVMReadBlockRCRequest)
                {
                    if (nvmStatus != (uint8)NVM_REQ_PENDING)
                    {
                        MemLib_MemSet(NVM_RCRead_buffer_u8, 0U, MEMDIAG_MAX_BYTES_FOR_NVM); /*Clear the buffer*/
                        (void)NvmBlockConfig.MemDiag_ReadNvmBlock(Routine_nvm_blockID, NVM_RCRead_buffer_u8);
                        NVMReadBlockRCRequest = TRUE;
                    }
                    NvmAccessbyBlockID_RCStatus = eROUTINE_INPROGRESS;
                    Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(NVMACCESSBYBLOCKRCTYPE, (uint8)NvmAccessbyBlockID_RCStatus);
                    ret = E_OK;
                }
            }
        }
        else
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT; /*Invalid NV Block ID*/
        }
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  MemDiag_NVMReadbyBlockIDStatus
**
** Visibility       :  Private
**
** Description      :  Polls status of NVM Block Read
**
**
** Invocation       :  MeetMgr.diagcdd , Function:CmpActive
**
** Inputs           :  NA
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
void MemDiag_NVMReadbyBlockIDStatus(void)
{
    uint8 nvmStatus = 0U;
    if (TRUE == NVMReadBlockRCRequest)
    {
        #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
        MemDiagNvmJobResult_U8.MemDiag_Read(&nvmStatus); /*Read NVM Jobresult*/
        #else
        (void)MemDiagNvmBlkJobResult.MemDiag_JobResultRead_byBlkID(Routine_nvm_blockID, &nvmStatus); /*Read NVM Jobresult of the block*/
        #endif
        if (nvmStatus == (uint8)NVM_REQ_PENDING)
        {
            NvmAccessbyBlockID_RCStatus = eROUTINE_INPROGRESS;
        }
        else
        {
            if (nvmStatus == (uint8)NVM_REQ_OK)
            {
                NvmAccessbyBlockID_RCStatus = eROUTINE_FINISH_OK;
            }
            else
            {
                NvmAccessbyBlockID_RCStatus = eROUTINE_FINISH_NOK;
            }
            NVMReadBlockRCRequest = FALSE;
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            nvmStatus = 0U;
            MemDiagNvmJobResult_U8.MemDiag_Write(nvmStatus); /*clear NVM Jobresult*/
            #endif
        }
    }
}

/*=====================================================================================================================
**
** Function Name    :  Memdiag_DataflashNVMaccessbyblockID_RCStop
**
** Visibility       :  Public
**
** Description      :  Stops reading NVM Block based on input block Id
**
** Invocation       :  MeetMgr.diagcdd , Function: RC_STOP_Diag_F20F
**
** Inputs           :  Data[Out]: status of Routine Control Stop is updated
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_DataflashNVMaccessbyblockID_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        NvmAccessbyBlockID_RCStatus = eROUTINE_FINISH_OK;
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(NVMACCESSBYBLOCKRCTYPE, (uint8)NvmAccessbyBlockID_RCStatus);
        ret = E_OK;
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Memdiag_DataflashNVMaccessbyblockID_RCStatus
**
** Visibility       :  Public
**
** Description      :  Gives Routine Control Status for NVM read by block ID Operation
**
** Invocation       :  MeetMgr.diagcdd , Function:RC_RESULTS_Diag_F20F
**
** Inputs           :  Data[Out]: status of Routine Control , data read from NVM (256 bytes)
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_DataflashNVMaccessbyblockID_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        if ((NvmAccessbyBlockID_RCStatus == eROUTINE_FINISH_OK) || (NvmAccessbyBlockID_RCStatus == eROUTINE_INACTIVE))
        {
            MemLib_MemCpy(&Data[DATA_BYTE_1], NVM_RCRead_buffer_u8, MEMDIAG_MAX_BYTES_FOR_NVM); /*copy block data to output*/
        }
        else
        {
            MemLib_MemSet(&Data[DATA_BYTE_1], 0U, MEMDIAG_MAX_BYTES_FOR_NVM); /*Set '0' to data buffer*/
        }
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(NVMACCESSBYBLOCKRCTYPE, (uint8)NvmAccessbyBlockID_RCStatus);
        ret = E_OK;
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#if defined(HYPERFLASHCHKSUMTSTENABLE) || defined(MEMDIAG_MEMORY_VALIDITY_CHECK)
#ifdef MARKERADDRESSCHECKENABLE
/*=====================================================================================================================
**
** Function Name    :  HyperFlash_Validity_check
**
** Visibility       :  Private
**
** Description      :  compares if hyperflash start marker and end marker values are same as predefined values
**
**
** Invocation       :  Mem.diagCdd , Function: Memdiag_HyperflashChecksumTest_RCStart
**
** Inputs           :  hyperflash: pointer to start marker address,start marker value ,end marker address,end marker value

**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType HyperFlash_Validity_check(MemDiag_HyperFlashtype *hyperflash)
{
    Std_ReturnType ret = E_NOT_OK;
    typedef struct
    {
        uint32 hyper_start_mkr_U32;
    } hyper_start_mkr;
    typedef struct
    {
        uint32 end_start_mkr_U32;
    } hyper_end_mkr;

    hyper_start_mkr hyperflash_start_marker;
    hyper_end_mkr hyperflash_end_mkr;

    hyperflash_start_marker.hyper_start_mkr_U32 = *((uint32 *)hyperflash->start_marker_addr);
    hyperflash_end_mkr.end_start_mkr_U32 = *((uint32 *)hyperflash->end_marker_addr);
    if ((hyperflash_start_marker.hyper_start_mkr_U32 == hyperflash->start_marker_val) && (hyperflash_end_mkr.end_start_mkr_U32 == hyperflash->end_marker_val))
    {
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }
    return (ret);
}
#endif
/*=====================================================================================================================
**
** Function Name    :  Memdiag_HyperflashChecksumTest_RCStart
**
** Visibility       :  Public
**
** Description      :  triggers hyperflash validity check
**
** Invocation       :  MeetMgr.diagcdd , Function:RC_START_Diag_F11E
**
** Inputs           :  Data[In]:hyperflash index
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_HyperflashChecksumTest_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    #ifdef HYPER_FLASH_CHKSUM_TEST_FOR_ALL // coverity fix new CID :5637791 (Macro introduced for "All_Parameter")
    uint8 All_Parameter;               // coverity fix new CID : 1827596(All_Parameter = 0 -> All_Parameter)
    #endif

    hyperflash_index = Data[DATA_BYTE_0];

    #ifdef HYPER_FLASH_CHKSUM_TEST_FOR_ALL
    for (All_Parameter = 0; All_Parameter < NUMBER_OF_HYPER_FLASH; All_Parameter++) // Setting Default value to all Routine Status Record bytes
    {
        Data[All_Parameter] = (uint8)eROUTINE_CHECKSUM_DEFAULT;
    }
    #endif

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        if (hyperflash_index < (NUMBER_OF_HYPER_FLASH))
        {

            if (MemDiag_CheckSum_RCStatus[hyperflash_index] == eROUTINE_INPROGRESS)
            {
                /*Already Routine in progress*/
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }
            else
            {
                #ifdef MARKERADDRESSCHECKENABLE
                MemDiag_CheckSum_Validity_Status[hyperflash_index] = (uint8)HyperFlash_Validity_check((void *)&MemDiag_HyperFlashConfig[hyperflash_index]);
                MemDiag_CheckSum_RCStatus[hyperflash_index] = eROUTINE_INPROGRESS;
                #else
                MemDiag_CheckSum_RCStatus[hyperflash_index] = (eRoutineStatus)MemDiag_HyperFlashChksumConfig.MemDiag_HyperFlash_ChksumStart(hyperflash_index);
                #endif
                #ifdef HYPER_FLASH_CHKSUM_TEST_FOR_ALL
                Data[hyperflash_index] = RoutineCtrlStatusUpdate(HYPERFLASHCHKSUMRCTYPE, (uint8)MemDiag_CheckSum_RCStatus[hyperflash_index]);
                #else
                Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(HYPERFLASHCHKSUMRCTYPE, (uint8)MemDiag_CheckSum_RCStatus[hyperflash_index]);
                #endif
                ret = E_OK;
            }
        }
        #ifdef HYPER_FLASH_CHKSUM_TEST_FOR_ALL // Checksum Test for ALL
        else if (hyperflash_index == 0xFEU)
        {
            for (All_Parameter = 0; All_Parameter < NUMBER_OF_HYPER_FLASH; All_Parameter++) // Checksum Test for NAND, NOR, GIP and VIP
            {
                if (MemDiag_CheckSum_RCStatus[All_Parameter] == eROUTINE_INPROGRESS)
                {
                    /*Already Routine in progress*/
                    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                }
                else
                {
                    #ifdef MARKERADDRESSCHECKENABLE
                    MemDiag_CheckSum_Validity_Status[All_Parameter] = (uint8)HyperFlash_Validity_check((void *)&MemDiag_HyperFlashConfig[All_Parameter]);
                    MemDiag_CheckSum_RCStatus[All_Parameter] = eROUTINE_INPROGRESS;
                    #else
                    MemDiag_CheckSum_RCStatus[All_Parameter] = (eRoutineStatus)MemDiag_HyperFlashChksumConfig.MemDiag_HyperFlash_ChksumStart(All_Parameter);
                    #endif

                    #ifdef HYPER_FLASH_CHKSUM_TEST_FOR_ALL
                    Data[All_Parameter] = RoutineCtrlStatusUpdate(HYPERFLASHCHKSUMRCTYPE, (uint8)MemDiag_CheckSum_RCStatus[All_Parameter]);
                    #else
                    Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(HYPERFLASHCHKSUMRCTYPE, (uint8)MemDiag_CheckSum_RCStatus[All_Parameter]);
                    #endif

                    ret = E_OK;
                }
            }
        }
        #endif
        else
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Memdiag_HyperflashChecksumTest_RCStop
**
** Visibility       :  Public
**
** Description      :  stops hyperflash validity check
**
**
** Invocation       :  MeetMgr.diagcdd , Function:RC_STOP_Diag_F11E
**
** Inputs           :  Data[Out]:to send Routine Control Result
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_HyperflashChecksumTest_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    #ifdef HYPER_FLASH_CHKSUM_TEST_FOR_ALL // coverity fix new CID : 5637790(Macro introduced for "All_Parameter"))
    uint8 All_Parameter;               // coverity fix new CID : 1827605(All_Parameter = 0 -> All_Parameter)
    #endif
    MGRDIAG_GET_SESSION(&MfgModeActive);

    #ifdef HYPER_FLASH_CHKSUM_TEST_FOR_ALL
    for (All_Parameter = 0; All_Parameter < NUMBER_OF_HYPER_FLASH; All_Parameter++) // Setting Default value to all Routine Status Record bytes
    {
        Data[All_Parameter] = (uint8)eROUTINE_CHECKSUM_DEFAULT;
    }
    #endif
    if (MfgModeActive == MEET_SESSION)
    {
        if (hyperflash_index < (NUMBER_OF_HYPER_FLASH))
        {
            #ifdef MARKERADDRESSCHECKENABLE
            MemDiag_CheckSum_RCStatus[hyperflash_index] = eROUTINE_FINISH_OK;
            #else
            MemDiag_CheckSum_RCStatus[hyperflash_index] = (eRoutineStatus)MemDiag_HyperFlashChksumConfig.MemDiag_HyperFlash_ChksumStop(hyperflash_index);
            #endif

            #ifdef HYPER_FLASH_CHKSUM_TEST_FOR_ALL
            Data[hyperflash_index] = RoutineCtrlStatusUpdate(HYPERFLASHCHKSUMRCTYPE, (uint8)MemDiag_CheckSum_RCStatus[hyperflash_index]);
            #else
            Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(HYPERFLASHCHKSUMRCTYPE, (uint8)MemDiag_CheckSum_RCStatus[hyperflash_index]);
            #endif

            ret = E_OK;
        }
        #ifdef HYPER_FLASH_CHKSUM_TEST_FOR_ALL // Checksum Test for ALL
        else if (hyperflash_index == 0xFEU)
        {
            for (All_Parameter = 0; All_Parameter < NUMBER_OF_HYPER_FLASH; All_Parameter++) // Checksum Test for NAND memory,NOR memory,GIP and VIP
            {
                #ifdef MARKERADDRESSCHECKENABLE
                MemDiag_CheckSum_RCStatus[All_Parameter] = eROUTINE_FINISH_OK;
                #else
                MemDiag_CheckSum_RCStatus[All_Parameter] = (eRoutineStatus)MemDiag_HyperFlashChksumConfig.MemDiag_HyperFlash_ChksumStop(All_Parameter);
                #endif

                #ifdef HYPER_FLASH_CHKSUM_TEST_FOR_ALL
                Data[All_Parameter] = RoutineCtrlStatusUpdate(HYPERFLASHCHKSUMRCTYPE, (uint8)MemDiag_CheckSum_RCStatus[All_Parameter]);
                #else
                Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(HYPERFLASHCHKSUMRCTYPE, (uint8)MemDiag_CheckSum_RCStatus[All_Parameter]);
                #endif

                ret = E_OK;
            }
        }
        #endif
        else
        {
            /*No action required*/
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Memdiag_HyperflashChecksumTest_RCStatus
**
** Visibility       :  Public
**
** Description      :  returns raoutine control status for hyperflash validity check
**
** Invocation       :  MeetMgr.diagcdd , Function:RC_RESULTS_Diag_F11E
**
** Inputs           :  Data[Out]:to send Routine Control Result
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_HyperflashChecksumTest_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    #ifdef HYPER_FLASH_CHKSUM_TEST_FOR_ALL // coverity fix new CID : 5637788(Macro introduced for "All_Parameter")
    uint8 All_Parameter;               // coverity fix new CID : 1827603(All_Parameter = 0 -> All_Parameter)
    #endif

    #ifdef MARKERADDRESSCHECKENABLE
    Std_ReturnType tmp;
    #endif

    #ifdef HYPER_FLASH_CHKSUM_TEST_FOR_ALL
    for (All_Parameter = 0; All_Parameter < NUMBER_OF_HYPER_FLASH; All_Parameter++) // Setting Default value to all Routine Status Record bytes
    {
        Data[All_Parameter] = (uint8)eROUTINE_CHECKSUM_DEFAULT;
    }
    #endif

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        if (hyperflash_index < (NUMBER_OF_HYPER_FLASH))
        {
            if (MemDiag_CheckSum_RCStatus[hyperflash_index] != eROUTINE_INACTIVE)
            {
                #ifdef MARKERADDRESSCHECKENABLE
                tmp = MemDiag_CheckSum_Validity_Status[hyperflash_index];
                if ((uint8)E_OK == tmp)
                {
                    MemDiag_CheckSum_RCStatus[hyperflash_index] = eROUTINE_FINISH_OK;
                }
                else
                {
                    MemDiag_CheckSum_RCStatus[hyperflash_index] = eROUTINE_FINISH_NOK;
                }
                #else
                MemDiag_CheckSum_RCStatus[hyperflash_index] = (eRoutineStatus)MemDiag_HyperFlashChksumConfig.MemDiag_HyperFlash_ChksumResult(hyperflash_index);
                #endif
            }

            #ifdef HYPER_FLASH_CHKSUM_TEST_FOR_ALL
            Data[hyperflash_index] = RoutineCtrlStatusUpdate(HYPERFLASHCHKSUMRCTYPE, (uint8)MemDiag_CheckSum_RCStatus[hyperflash_index]);
            #else
            Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(HYPERFLASHCHKSUMRCTYPE, (uint8)MemDiag_CheckSum_RCStatus[hyperflash_index]);
            #endif
        }
        #ifdef HYPER_FLASH_CHKSUM_TEST_FOR_ALL // Checksum Test for ALL
        else if (hyperflash_index == 0xFEU)
        {
            for (All_Parameter = 0; All_Parameter < NUMBER_OF_HYPER_FLASH; All_Parameter++) // Checksum Test for NAND memory,NOR memory,GIP and VIP
            {
                if (MemDiag_CheckSum_RCStatus[All_Parameter] != eROUTINE_INACTIVE)
                {
                    #ifdef MARKERADDRESSCHECKENABLE
                    tmp = MemDiag_CheckSum_Validity_Status[All_Parameter];
                    if (tmp == (uint8)E_OK)
                    {
                        MemDiag_CheckSum_RCStatus[All_Parameter] = eROUTINE_FINISH_OK;
                    }
                    else
                    {
                        MemDiag_CheckSum_RCStatus[All_Parameter] = eROUTINE_FINISH_NOK;
                    }
                    #else
                    MemDiag_CheckSum_RCStatus[All_Parameter] = (eRoutineStatus)MemDiag_HyperFlashChksumConfig.MemDiag_HyperFlash_ChksumResult(All_Parameter);
                    #endif
                }

                #ifdef HYPER_FLASH_CHKSUM_TEST_FOR_ALL
                Data[All_Parameter] = RoutineCtrlStatusUpdate(HYPERFLASHCHKSUMRCTYPE, (uint8)MemDiag_CheckSum_RCStatus[All_Parameter]);
                #else
                Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(HYPERFLASHCHKSUMRCTYPE, (uint8)MemDiag_CheckSum_RCStatus[All_Parameter]);
                #endif
            }
        }
        #endif
        else
        {
            /*No action required*/
        }

        ret = E_OK;
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef MEMWRITETESTENABLE
/*=====================================================================================================================
**
** Function Name    :  Memdiag_MemoryWritingTest_RCStart
**
** Visibility       :  Public
**
** Description      :  starts memory write test for TCRAM /HYPERRAM
**
**
** Invocation       :  MeetMgr.diagcdd , Function:RC_START_Diag_F115
**
** Inputs           :  Data[In]:contains logical marker of memory to be tested,address of RAM,byte length
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_MemoryWritingTest_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 logical_mem_index = Data[DATA_BYTE_0]; /*Read Logical Marker*/
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        if ((logical_mem_index == 0U) || (logical_mem_index > NUMBER_OF_LOGICAL_MARKER) || (0U == MemTestLogicalMarker[logical_mem_index - 1].pFunc)) // max no. of logical marker
        {
            /*Not supported logical marker*/
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
        else if (MemWriteTst_RCStatus == eROUTINE_INPROGRESS)
        {
            /*Already Routine in progress*/
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
        else
        {
            ret = MemTestLogicalMarker[logical_mem_index - 1].pFunc(Data, ErrorCode, MemTestLogicalMarker[logical_mem_index - 1].pMemAction);
            if ((uint8)E_OK == ret)
            {
                MemDiag_SetRoutineStatus(1U);
                MemDiag_PreviousLogicalMarker = logical_mem_index;
                MemWriteTst_RCStatus = eROUTINE_INPROGRESS;
                Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMWRITETESTRCTYPE, MemWriteTst_RCStatus);
            }
            else
            {
                MemWriteTst_RCStatus = eROUTINE_FINISH_NOK;
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  MemDiag_MemWritingTest_Start
**
** Visibility       :  Public
**
** Description      :  validates address of TCRAM /HYPERRAM and triggers memory writing test
**
**
** Invocation       :  MeetMgr.diagcdd , Function:Memdiag_MemoryWritingTest_RCStart
**
** Inputs           :  Data[In]:contains logical marker of memory to be tested,address of RAM,byte length
**					   Errorcode:to be updated with error code if any
**					   MemAction:indicates what memory operation is performed on which memory
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType MemDiag_MemWritingTest_Start(uint8 *Data, uint8 *ErrorCode, eMemMgrAction MemAction)
{
    Std_ReturnType ret = E_NOT_OK;
    uint32 count, logical_marker;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        /*Extract the Address from the request buffer*/
        MemAddress = (uint32)(Data[DATA_BYTE_1] << 24 | Data[DATA_BYTE_2] << 16 | Data[DATA_BYTE_3] << 8 | Data[DATA_BYTE_4]);

        logical_marker = Data[DATA_BYTE_0];

        /*extract the no. of bytes to be written to memory*/
        NumOfBytesToBeWritten = Data[DATA_BYTE_5];

        /* Address range check */
        ret = MemDiag_AddRangeCheck(logical_marker, MemAddress, NumOfBytesToBeWritten);
        if ((uint8)E_OK == ret)
        {

            for (count = 0U; count < NumOfBytesToBeWritten; count++)
            {
                /*copy the data 0x55 in the WriteBuffer*/
                MemDiag_WriteBuffer[count] = MEM_WRITING_TEST_DATA;
            }
            /*Update the MemMgrFlag value to indicate that Memory write operation has started*/
            MemMgrFlag = MemAction;
        }
        else
        {
            /* Requested address is out of range */
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Memdiag_MemoryWritingTest_RCStop
**
** Visibility       :  Public
**
** Description      :  stops memory writing test
**
**
** Invocation       :  MeetMgr.diagcdd , Function:RC_STOP_Diag_F115
**
** Inputs           :  Data[Out]:used to return routine control stop status
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_MemoryWritingTest_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MemWriteTst_RCStatus = eROUTINE_FINISH_OK;
        MemMgrFlag = eMEMMGR_INACTIVE;
        MemDiag_SetRoutineStatus(0U);
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMWRITETESTRCTYPE, (uint8)MemWriteTst_RCStatus);
    }
    else
    {
        /*Invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Memdiag_MemoryWritingTest_RCStatus
**
** Visibility       :  Public
**
** Description      :  gives routine control status for memory writing test
**
**
** Invocation       :  MeetMgr.diagcdd , Function:RC_RESULTS_Diag_F115
**
** Inputs           :  Data[Out]:used to return routine control status
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Memdiag_MemoryWritingTest_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        if ((MemWriteTst_RCStatus == eROUTINE_FINISH_NOK) || (MemWriteTst_RCStatus == eROUTINE_INACTIVE))
        {
            /*do nothing*/
        }
        else
        {
            ret = Is_MemoryOperFinish(MemDiag_PreviousLogicalMarker); /* check memory operation based on previous memory marker */
            if (ret == 0U)
            {
                MemWriteTst_RCStatus = eROUTINE_FINISH_OK;
            }
            else
            {
                MemWriteTst_RCStatus = eROUTINE_INPROGRESS;
            }
        }
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMWRITETESTRCTYPE, MemWriteTst_RCStatus);
        ret = E_OK;
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  MemDiag_Main_Task
**
** Visibility       :  Public
**
** Description      :  executes memory writing test
**					1)reading is performed on any address of the configured range and store values on another area not impacted by the operation
**					2)writing sequence starts to overwrite values on configured range to $55
** 					3)reading is performed on any address of the configured range and every values are checked against $55
** 					4)writing sequence starts to overwrite values on configured range to the ones stored on first step
**			 		5)reading is performed on any address of the configured range and every values are checked against the ones stored on first step
**
**
** Invocation       :  MeetMgr.diagcdd, Function:CmpActive
**
** Inputs           :  NA
**
**
** Outputs          :  NA
**
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
void MemDiag_Main_Task(void)
{
    uint8 *WriteTestAddPtr = (uint8 *)MemAddress;
    uint8 LoopIndexL = 0U;

    if (MemMgrFlag == eMEMMGR_TCRAM_MEM_TEST || MemMgrFlag == eMEMMGR_HYPERRAM_MEM_TEST)
    {
        WriteErrorCounter = 0U;

        NumOfBytesToBeRead = NumOfBytesToBeWritten;

        MemLib_MemCpy(&MemDiag_ReadBuffer, (uint32 *)MemAddress, NumOfBytesToBeRead); // Step-1:Read from requested location of RAM

        MemLib_MemCpy((uint32 *)MemAddress, &MemDiag_WriteBuffer, NumOfBytesToBeWritten); // Step-2:Write data 0x55

        for (LoopIndexL = 0U; LoopIndexL < NumOfBytesToBeRead; LoopIndexL++) // Step-3:Read and Compare with data 0x55
        {
            if (*WriteTestAddPtr != MEM_WRITING_TEST_DATA)
            {
                WriteErrorCounter++;
            }
            WriteTestAddPtr++;
        }
        WriteTestAddPtr = (uint8 *)MemAddress;

        MemLib_MemCpy((uint32 *)MemAddress, &MemDiag_ReadBuffer, NumOfBytesToBeWritten); // Step-4:Write data which was stored in step-1

        for (LoopIndexL = 0U; LoopIndexL < NumOfBytesToBeRead; LoopIndexL++) // Step-5:Read and Compare with data of step-1
        {
            if (*WriteTestAddPtr != MemDiag_ReadBuffer[LoopIndexL])
            {
                WriteErrorCounter++;
            }
            WriteTestAddPtr++;
        }

        MemMgrFlag = eMEMMGR_INACTIVE;
        MemDiag_SetRoutineStatus(0U);
    }
}

/*=====================================================================================================================
**
** Function Name    :  Get_MEM_OperState
**
** Visibility       :  Private
**
** Description      :  Returns the status of the MemMgrFlag
**
**
** Invocation       :  Mem.diagcdd, Function:Is_MemoryOperFinish
**
** Inputs           :  NA
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType Get_MEM_OperState(void)
{
    return (MemMgrFlag);
}
/*=====================================================================================================================
**
** Function Name    :  MemDiag_AddRangeCheck
**
** Visibility       :  Private
**
** Description      :  Validates the address of TCRAM and HYPERRAM
**
**
** Invocation       :  Mem.diagcdd, Function:MemDiag_MemWritingTest_Start
**
** Inputs           : Logical_Marker:indicates TCRAM or HYPERRAM
**					  address: Start Address of memory location
**					  Length: byte length
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MemDiag_AddRangeCheck(uint8 Logical_Marker, uint32 address, uint8 Length)
{
    Std_ReturnType ret = E_NOT_OK;
    switch (Logical_Marker)
    {
    case TCRAM:
        if ((address + Length - 1U) < MemDiag_MemAddrConfig[DATA_BYTE_0].MemoryEndAddr)
        {
            ret = E_OK;
        }
        break;
    case HYPERRAM:
        if ((address >= MemDiag_MemAddrConfig[DATA_BYTE_1].MemoryStartAddr) && ((address + (Length - 1U)) < MemDiag_MemAddrConfig[DATA_BYTE_1].MemoryEndAddr))
        {
            ret = E_OK;
        }
        break;

    default:
        /*No action required in default case*/
        break;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  MemDiag_SetRoutineStatus
**
** Visibility       :  Private
**
** Description      :  updates MemDiag_RoutineState
**
**
** Invocation       :  Mem.diagcdd, Function:Memdiag_MemoryWritingTest_RCStart ,Memdiag_MemoryWritingTest_RCStop,MemDiag_Main_Task
**
** Inputs           :  state:value to be updated to MemDiag_RoutineState
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MemDiag_SetRoutineStatus(uint8 state)
{
    MemDiag_RoutineState = state;
}

/*=====================================================================================================================
**
** Function Name    :  Is_MemoryOperFinish
**
** Visibility       :  Private
**
** Description      :  checks if memory operation is completed
**
** Invocation       :  Mem.diagcdd, Function:Memdiag_MemoryWritingTest_RCStatus
**
** Inputs           :  state:mentions which memory operation status is to be checked
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType Is_MemoryOperFinish(uint8 state)
{
    Std_ReturnType ret = E_NOT_OK;
    switch (state)
    {
    case TCRAM:
    case HYPERRAM:
        ret = Get_MEM_OperState();
        break;
    default:
        /*No action required in default case*/
        break;
    }
    return (ret);
}
#endif
#ifdef MEMDIAG_MEMORY_VALIDITY_CHECK
/*=====================================================================================================================
**
** Function Name    :  Memdiag_Memory_Validity_Check_RCStart
**
** Visibility       :  Public
**
** Description      :  Triggers NVM validity /Internal flash validity/hyper flash validity check
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode
**
**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Memdiag_Memory_Validity_Check_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        if (Data[0] == 1U)
        {
            ret = Memdiag_NVMValidityCheck_RCStart(Data, ErrorCode);
        }
        else if (Data[0] == 2U)
        {
            ret = Memdiag_IntflashValidityCheck_RCStart(Data, ErrorCode);
        }
        else if ((Data[0] == 3U) || (Data[0] == 4U))
        {
            Data[0] = Data[0] - 3U;
            ret = Memdiag_HyperflashChecksumTest_RCStart(Data, ErrorCode);
        }
        else if (Data[0] == 5U)
        {
            ret = MemDiag_RamTest_RCStart(Data, ErrorCode);
        }
        else
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
    }
    else
    {
        /*Invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Memdiag_Memory_Validity_Check_RCStop
**
** Visibility       :  Public
**
** Description      :  Stops NVM validity /Internal flash validity/hyper flash validity check
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode

**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Memdiag_Memory_Validity_Check_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        if (Data[0] == 1U)
        {
            ret = Memdiag_NVMValidityCheck_RCStop(Data, ErrorCode);
        }
        else if (Data[0] == 2U)
        {
            ret = Memdiag_IntflashValidityCheck_RCStop(Data, ErrorCode);
        }
        else if ((Data[0] == 3U) || (Data[0] == 4U))
        {
            Data[0] = Data[0] - 3U;
            ret = Memdiag_HyperflashChecksumTest_RCStop(Data, ErrorCode);
        }
        else if (Data[0] == 5U)
        {
            ret = MemDiag_RamTest_RCStop(Data, ErrorCode);
        }
        else
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
    }
    else
    {
        /*Invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Memdiag_Memory_Validity_Check_RCStatus
**
** Visibility       :  Public
**
** Description      :  Returns results of NVM validity /Internal flash validity/hyper flash validity check
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode
**
** Outputs          :  E_OK : Success
**
** Critical Section :  No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_Memory_Validity_Check_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        if (Data[0] == 1U)
        {
            ret = Memdiag_NVMValidityCheck_RCStatus(Data, ErrorCode);
        }
        else if (Data[0] == 2U)
        {
            ret = Memdiag_IntflashValidityCheck_RCStatus(Data, ErrorCode);
        }
        else if ((Data[0] == 3U) || (Data[0] == 4U))
        {
            Data[0] = Data[0] - 3U;
            ret = Memdiag_HyperflashChecksumTest_RCStatus(Data, ErrorCode);
        }
        else if (Data[0] == 5U)
        {
            ret = MemDiag_RamTest_RCStatus(Data, ErrorCode);
        }
        else
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Memdiag_NVMValidityCheck_RCStart
**
** Visibility       :  Private
**
** Description      :  Triggers NVM validity check
**
**
** Invocation       :  Mem.diagCdd , Function: Memdiag_Memory_Validity_Check_RCStart
**
** Inputs           :  Data,ErrorCode

**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_NVMValidityCheck_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;

    if ((NvmValidityCheckStatus == NVM_VALIDITYCHECK_NONE) || (NvmValidityCheckStatus == NVM_VALIDITYCHECK_DONE))
    {
        *NvmValidityStatusPtr = NvmValidityStatus;
        NVMReadAllRequest = TRUE;
        CurrentReadBlockId = 0;
        NvmValidityCheckStatus = NVM_VALIDITYCHECK_START;
        Memdiag_NvMValidity_RCStatus = eROUTINE_INPROGRESS;
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_NVM_VALIDITY_CHECK_RCTYPE, (uint8)Memdiag_NvMValidity_RCStatus);
        ret = E_OK;
    }
    else
    {
        /*Already Routine in progress*/
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Memdiag_NVMValidityCheck_RCStop
**
** Visibility       :  Private
**
** Description      :  Stops NVM validity check
**
**
** Invocation       :  Mem.diagCdd , Function: Memdiag_Memory_Validity_Check_RCStop
**
** Inputs           :  Data,ErrorCode

**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_NVMValidityCheck_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    UNUSED(ErrorCode);
    Memdiag_NvMValidity_RCStatus = eROUTINE_FINISH_OK;
    Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_NVM_VALIDITY_CHECK_RCTYPE, (uint8)Memdiag_NvMValidity_RCStatus);
    return E_OK;
}
/*=====================================================================================================================
**
** Function Name    :  Memdiag_NVMValidityCheck_RCStatus
**
** Visibility       :  Private
**
** Description      :  returns NVM validity check result
**
** Invocation       :  Mem.diagCdd , Function: Memdiag_Memory_Validity_Check_RCStatus
**
** Inputs           :  Data,ErrorCode
**
** Outputs          :  E_OK : Success
**
** Critical Section :  No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_NVMValidityCheck_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    UNUSED(ErrorCode);

    if ((Memdiag_NvMValidity_RCStatus != eROUTINE_INACTIVE) && (NvmValidityCheckStatus == NVM_VALIDITYCHECK_DONE))
    {
        if (*NvmValidityStatusPtr == (uint8)NVM_VALIDITY_OK)
        {
            Memdiag_NvMValidity_RCStatus = eROUTINE_FINISH_OK;
            NvmValidityCheckStatus = NVM_VALIDITYCHECK_NONE;
        }
        else
        {
            Memdiag_NvMValidity_RCStatus = eROUTINE_FINISH_NOK;
            NvmValidityCheckStatus = NVM_VALIDITYCHECK_NONE;
        }
    }
    else if (NvmValidityCheckStatus == NVM_VALIDITYCHECK_PROGRESS)
    {
        Memdiag_NvMValidity_RCStatus = eROUTINE_INPROGRESS;
    }
    else
    {
        /*Do nothing*/
    }

    Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_NVM_VALIDITY_CHECK_RCTYPE, (uint8)Memdiag_NvMValidity_RCStatus);
    return E_OK;
}

#ifdef MEMDIAG_INTFLASH_VALIDITY_CHECK_VIA_MARKERS
/*=====================================================================================================================
**
** Function Name    :  Memdiag_IntFlash_Validity_check
**
** Visibility       :  Private 
**
** Description      :  compares if internal flash start marker and end marker values are same as predefined values
**                      
**
** Invocation       :  Mem.diagCdd , Function: Memdiag_Memory_Validity_Check_RCStart
**
** Inputs           :  Internal flash: pointer to start marker address,start marker value ,end marker address,end marker value
                       
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType Memdiag_IntFlash_Validity_check(Memdiag_IntFlashtype *Intflash)
{
    Std_ReturnType ret = E_NOT_OK;
    typedef union
    {
        uint8 IntFlash_start_mkr_U8[4];
        uint32 IntFlash_start_mkr_U32;
    }IntFlash_start_mkr;
    typedef union
    {
        uint8 IntFlash_end_mkr_U8[4];
        uint32 IntFlash_end_mkr_U32;
    }IntFlash_end_mkr;

    IntFlash_start_mkr IntFlash_start_marker;
    IntFlash_end_mkr IntFlash_end_marker;

    IntFlash_start_marker.IntFlash_start_mkr_U32 = *((uint32*) Intflash->start_marker_addr);
    IntFlash_end_marker.IntFlash_end_mkr_U32 = *((uint32*)Intflash->end_marker_addr);
    if((IntFlash_start_marker.IntFlash_start_mkr_U32  == Intflash->start_marker_val)&&(IntFlash_end_marker.IntFlash_end_mkr_U32 == Intflash->end_marker_val))
    {
       ret = E_OK;
    }
    else
    {
       ret = E_NOT_OK;
    }
    return (ret);
}
#endif

/*=====================================================================================================================
**
** Function Name    :  MemDiag_RamTest_RCStart
**
** Visibility       :  Private
**
** Description      :  triggers RAM test
**
**
** Invocation       :  MeetMgr.diagcdd , Function:Memdiag_Memory_Validity_Check_RCStart
**
** Inputs           :  Data[In]:RAM test index
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/
static Std_ReturnType MemDiag_RamTest_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    if (Memdiag_RAMValidity_RCStatus == eROUTINE_INPROGRESS)
    {
        /*Already Routine in progress*/
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
    }
    else
    {
        Memdiag_RAMValidity_Status = (uint8)Memdiag_RAM_Validity_check();
        Memdiag_RAMValidity_RCStatus = eROUTINE_INPROGRESS;
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_INT_RAM_RCTYPE, (uint8)Memdiag_RAMValidity_RCStatus);
        ret = E_OK;
    }
    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  MemDiag_RamTest_RCStop
**
** Visibility       :  Private
**
** Description      :  Stop RAM test
**
**
** Invocation       :  MeetMgr.diagcdd , Function:Memdiag_Memory_Validity_Check_RCStop
**
** Inputs           :  Data[In]:RAM test index
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/
static Std_ReturnType MemDiag_RamTest_RCStop(uint8 *Data, const uint8 *ErrorCode)
{
    UNUSED(ErrorCode);
    Std_ReturnType ret = E_NOT_OK;
    Memdiag_RAMValidity_RCStatus = eROUTINE_FINISH_OK;
    Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_INT_RAM_RCTYPE, (uint8)Memdiag_RAMValidity_RCStatus);
    ret = E_OK;
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  MemDiag_RamTest_RCStatus
**
** Visibility       :  Private
**
** Description      :  Status of RAM test
**
** Invocation       :  MeetMgr.diagcdd , Function:Memdiag_Memory_Validity_Check_RCStatus
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/
static Std_ReturnType MemDiag_RamTest_RCStatus(uint8 *Data, const uint8 *ErrorCode)
{
    UNUSED(ErrorCode);
    Std_ReturnType ret = E_OK;

    if (Memdiag_RAMValidity_RCStatus != eROUTINE_INACTIVE)
    {
        if ((uint8)E_OK == Memdiag_RAMValidity_Status)
        {
            Memdiag_RAMValidity_RCStatus = eROUTINE_FINISH_OK;
        }
        else
        {
            Memdiag_RAMValidity_RCStatus = eROUTINE_FINISH_NOK;
        }
    }

    Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_INT_FLASH_RCTYPE, (uint8)Memdiag_RAMValidity_RCStatus);
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Memdiag_RAM_Validity_check
**
** Visibility       :  Private
**
** Description      :  triggers RAM test
**
**
** Invocation       :  MeetMgr.diagcdd , Function:Memdiag_Memory_Validity_Check_RCStart
**
** Inputs           :  None
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/
static Std_ReturnType Memdiag_RAM_Validity_check(void)
{
    Std_ReturnType ret = E_NOT_OK;

    uint8 fl_Memory_index_U8;
    uint8 fl_no_of_bytes_U8;
    uint16 write_error_counter = 0U;
    const uint8 *fl_memory_addr_U8;

    MemLib_MemSet(l_RAM_Write_Data, MEMDIAG_BYTE_TO_BE_WRITE_IN_RAM, MEMDIAG_MAX_NUMBER_OF_RAM_BYTES_TO_BE_TEST);
    for (fl_Memory_index_U8 = 0U; fl_Memory_index_U8 < MEMDIAG_MAX_NUMBER_OF_RAM_MEMORY_SETS; fl_Memory_index_U8++)
    {
        if ((Memdiag_RAMConfig[fl_Memory_index_U8].MemoryStartAddr + (MEMDIAG_MAX_NUMBER_OF_RAM_BYTES_TO_BE_TEST - 1U)) <= Memdiag_RAMConfig[fl_Memory_index_U8].MemoryEndAddr)
        {
            ret = E_OK;
        }
    }
    if ((uint8)E_OK == ret)
    {
        // read oiginal value from the memory
        for (fl_Memory_index_U8 = 0U; fl_Memory_index_U8 < MEMDIAG_MAX_NUMBER_OF_RAM_MEMORY_SETS; fl_Memory_index_U8++)
        {
            // Read and store the data in the local buffer
            MemmDiag_MemCpy(l_RAM_buffer_U8A[fl_Memory_index_U8], (void *)(uint32 *)Memdiag_RAMConfig[fl_Memory_index_U8].MemoryStartAddr, MEMDIAG_MAX_NUMBER_OF_RAM_BYTES_TO_BE_TEST);
        }
        // Write predefined data in the configured location
        for (fl_Memory_index_U8 = 0U; fl_Memory_index_U8 < MEMDIAG_MAX_NUMBER_OF_RAM_MEMORY_SETS; fl_Memory_index_U8++)
        {
            // Read and store the data in the local buffer
            MemmDiag_MemCpy((uint32 *)Memdiag_RAMConfig[fl_Memory_index_U8].MemoryStartAddr, l_RAM_Write_Data, MEMDIAG_MAX_NUMBER_OF_RAM_BYTES_TO_BE_TEST);
        }
        // check data is written
        for (fl_Memory_index_U8 = 0U; fl_Memory_index_U8 < MEMDIAG_MAX_NUMBER_OF_RAM_MEMORY_SETS; fl_Memory_index_U8++)
        {
            fl_memory_addr_U8 = (uint8 *)Memdiag_RAMConfig[fl_Memory_index_U8].MemoryStartAddr;
            for (fl_no_of_bytes_U8 = 0U; fl_no_of_bytes_U8 < MEMDIAG_MAX_NUMBER_OF_RAM_BYTES_TO_BE_TEST; fl_no_of_bytes_U8++)
            {
                if (*fl_memory_addr_U8 != MEMDIAG_BYTE_TO_BE_WRITE_IN_RAM)
                {
                    if (write_error_counter < UINT16_MAXIMUMVALUE)
                    {
                        write_error_counter++;
                    }
                    else
                    {
                        write_error_counter = 0U;
                    }
                }
                fl_memory_addr_U8++;
            }
        }

        // Write back the original value
        for (fl_Memory_index_U8 = 0U; fl_Memory_index_U8 < MEMDIAG_MAX_NUMBER_OF_RAM_MEMORY_SETS; fl_Memory_index_U8++)
        {
            // Read and store the data in the local buffer
            MemmDiag_MemCpy((void *)(uint32 *)Memdiag_RAMConfig[fl_Memory_index_U8].MemoryStartAddr, &l_RAM_buffer_U8A[fl_Memory_index_U8], (uint16)MEMDIAG_MAX_NUMBER_OF_RAM_BYTES_TO_BE_TEST);
        }
        // Check whether original data is written
        for (fl_Memory_index_U8 = 0U; fl_Memory_index_U8 < MEMDIAG_MAX_NUMBER_OF_RAM_MEMORY_SETS; fl_Memory_index_U8++)
        {
            fl_memory_addr_U8 = (uint8 *)Memdiag_RAMConfig[fl_Memory_index_U8].MemoryStartAddr;

            for (fl_no_of_bytes_U8 = 0U; fl_no_of_bytes_U8 < MEMDIAG_MAX_NUMBER_OF_RAM_BYTES_TO_BE_TEST; fl_no_of_bytes_U8++)
            {
                if (*fl_memory_addr_U8 != l_RAM_buffer_U8A[fl_Memory_index_U8][fl_no_of_bytes_U8])
                {
                    write_error_counter++;
                }
                fl_memory_addr_U8++;
            }
        }
    }
    if (write_error_counter > 0U)
    {
        ret = E_NOT_OK;
        /*  write_error_counter = 0;   Coverity fix */
    }
    return ret;
}
#endif
#if defined(MEMDIAG_MEMORY_VALIDITY_CHECK) || defined(MEMDIAG_VIP_GIP_MEMORY_CHECKSUM_TEST)
/*=====================================================================================================================
**
** Function Name    :  Memdiag_IntflashValidityCheck_RCStart
**
** Visibility       :  Private
**
** Description      :  triggers internal flash validity check
**
**
** Invocation       :  MeetMgr.diagcdd , Function:Memdiag_Memory_Validity_Check_RCStart
**
** Inputs           :  Data[In]:hyperflash index
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/
static Std_ReturnType Memdiag_IntflashValidityCheck_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    
    #ifdef MEMDIAG_INTFLASH_VALIDITY_CHECK_VIA_MARKERS
	uint8 intflash_index = 0U;
    #endif

    if (Memdiag_IntFlashValidity_RCStatus == eROUTINE_INPROGRESS)
    {
        /*Already Routine in progress*/
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
    }
    else
    {
        #ifdef MEMDIAG_INTFLASH_VALIDITY_CHECK_VIA_MARKERS
        Memdiag_IntFlashValidity_Status   = Memdiag_IntFlash_Validity_check((void *)&MemDiag_IntFlashMarkerConfig[intflash_index]);
		Memdiag_IntFlashValidity_RCStatus = eROUTINE_INPROGRESS;
        #else
        Memdiag_IntFlashValidity_RCStatus = (eRoutineStatus)Memdiag_IntFlashConfig.MemDiag_IntFlash_ChksumStart();
	    #endif
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_INT_FLASH_RCTYPE, (uint8)Memdiag_IntFlashValidity_RCStatus);
        ret = E_OK;
    }

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Memdiag_IntflashValidityCheck_RCStop
**
** Visibility       :  Private
**
** Description      :  stops internal flash validity check
**
**
** Invocation       :  MeetMgr.diagcdd , Function:Memdiag_Memory_Validity_Check_RCStop
**
** Inputs           :  Data[Out]:to send Routine Control Result
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/
static Std_ReturnType Memdiag_IntflashValidityCheck_RCStop(uint8 *Data, const uint8 *ErrorCode)
{
    UNUSED(ErrorCode);
	#ifndef MEMDIAG_INTFLASH_VALIDITY_CHECK_VIA_MARKERS
    Memdiag_IntFlashValidity_RCStatus = (eRoutineStatus)Memdiag_IntFlashConfig.MemDiag_IntFlash_ChksumStop();
	#endif
    Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_INT_FLASH_RCTYPE, (uint8)Memdiag_IntFlashValidity_RCStatus);
    return E_OK;
}

/*=====================================================================================================================
**
** Function Name    :  Memdiag_IntflashValidityCheck_RCStatus
**
** Visibility       :  Public
**
** Description      :  returns routine control status for internal flash validity check
**
**
** Invocation       :  MeetMgr.diagcdd , Function:Memdiag_Memory_Validity_Check_RCStatus
**
** Inputs           :  Data[Out]:to send Routine Control Result
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/
static Std_ReturnType Memdiag_IntflashValidityCheck_RCStatus(uint8 *Data, const uint8 *ErrorCode)
{
    UNUSED(ErrorCode);
    if (Memdiag_IntFlashValidity_RCStatus != eROUTINE_INACTIVE)
    {  
		#ifdef MEMDIAG_INTFLASH_VALIDITY_CHECK_VIA_MARKERS
		if(Memdiag_IntFlashValidity_Status == E_OK)
		{
			Memdiag_IntFlashValidity_RCStatus = eROUTINE_FINISH_OK;
		}
		else
		{
		    Memdiag_IntFlashValidity_RCStatus = eROUTINE_FINISH_NOK;
		}
		#else
        Memdiag_IntFlashValidity_RCStatus = (eRoutineStatus)Memdiag_IntFlashConfig.MemDiag_IntFlash_ChksumResult();
	    #endif
    }
    Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_INT_FLASH_RCTYPE, (uint8)Memdiag_IntFlashValidity_RCStatus);
    return E_OK;
}
#endif

#ifdef MEMDIAG_MEMORY_READ_WRITE_BY_ADDRESS
/*=====================================================================================================================
**
** Function Name    :  Memdiag_Memory_Read_By_Address
**
** Visibility       :  Public
**
** Description      :  Read data from the requested location of TCRAM/HYPER RAM
**
**
** Invocation       :  Application
**
** Inputs           :  Data[out]:Data to be read from the requested location
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_Memory_Read_By_Address(uint8 *Data, uint8 *ErrorCode)
{
    uint32 fl_MemAddress_U32;
    uint16 fl_no_of_bytes_U16;
    uint8 fl_ret_U8 = E_NOT_OK;

    fl_MemAddress_U32 = (uint32)(Data[DATA_BYTE_0] << 24 | Data[DATA_BYTE_1] << 16 | Data[DATA_BYTE_2] << 8 | Data[DATA_BYTE_3]);
    fl_no_of_bytes_U16 = (Data[4] << 8) | (Data[5]);
    if (fl_no_of_bytes_U16 > MEMDIAG_MAX_NUMBER_OF_BYTES_READ_WRITE)
    {
        *ErrorCode = MGRDIG_REQUEST_OUT_OF_RANGE;
    }
    else
    {
        // Step-1:Read from requested location of RAM
        if (((fl_MemAddress_U32 >= MemDiag_MemAddrRWConfig[0].MemoryStartAddr) && ((fl_MemAddress_U32 + fl_no_of_bytes_U16) - 1U) <= MemDiag_MemAddrRWConfig[0].MemoryEndAddr) || (fl_MemAddress_U32 >= MemDiag_MemAddrRWConfig[1].MemoryStartAddr) && (((fl_MemAddress_U32 + fl_no_of_bytes_U16) - 1U) <= MemDiag_MemAddrRWConfig[1].MemoryEndAddr))
        {
            MemmDiag_MemCpy(Data, (uint32 *)fl_MemAddress_U32, fl_no_of_bytes_U16);
            fl_ret_U8 = E_OK;
        }
        /*
         * Below code snippet is commented. Use as per the requirement.
         *
         *  else if((fl_MemAddress_U32  >= MemDiag_MemAddrRWConfig[1].MemoryStartAddr) && (((fl_MemAddress_U32 + fl_no_of_bytes_U16) - 1U) <= MemDiag_MemAddrRWConfig[1].MemoryEndAddr))
         {
             MemmDiag_MemCpy(Data,(uint32 *)fl_MemAddress_U32,fl_no_of_bytes_U16);
             fl_ret_U8 = E_OK;
         }  */
        else
        {
            *ErrorCode = MGRDIG_REQUEST_OUT_OF_RANGE;
        }
    }
    return (fl_ret_U8);
}
/*=====================================================================================================================
**
** Function Name    :  Memdiag_Memory_Write_By_Address
**
** Visibility       :  Public
**
** Description      :  Write data to the requested location of TCRAM/HYPER RAM
**
**
** Invocation       :  Application
**
** Inputs           :  Data[in]:Data to be written to TCRAM/HYPER RAM,Memory Address,No of bytes to be written
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_Memory_Write_By_Address(uint8 *Data, uint8 *ErrorCode)
{
    uint32 fl_MemAddress_U32;
    uint16 fl_no_of_bytes_U16;
    uint8 fl_ret_U8 = E_NOT_OK;

    fl_MemAddress_U32 = (uint32)(Data[DATA_BYTE_0] << 24 | Data[DATA_BYTE_1] << 16 | Data[DATA_BYTE_2] << 8 | Data[DATA_BYTE_3]);
    fl_no_of_bytes_U16 = (Data[4] << 8) | (Data[5]);
    if (fl_no_of_bytes_U16 > MEMDIAG_MAX_NUMBER_OF_BYTES_READ_WRITE)
    {
        *ErrorCode = MGRDIG_REQUEST_OUT_OF_RANGE;
    }
    else
    {
        // Coverity warning Fix: CID 1616732 review comment
        if (((fl_MemAddress_U32 >= MemDiag_MemAddrRWConfig[0].MemoryStartAddr) && (((fl_MemAddress_U32 + fl_no_of_bytes_U16) - 1U) <= MemDiag_MemAddrRWConfig[0].MemoryEndAddr)) || ((fl_MemAddress_U32 >= MemDiag_MemAddrRWConfig[1].MemoryStartAddr) && (((fl_MemAddress_U32 + fl_no_of_bytes_U16) - 1U) <= MemDiag_MemAddrRWConfig[1].MemoryEndAddr)))
        {
            MemmDiag_MemCpy((uint32 *)fl_MemAddress_U32, &Data[6], fl_no_of_bytes_U16); // Write on requested location of TCRAM
            fl_ret_U8 = E_OK;
        }
        else
        {
            *ErrorCode = MGRDIG_REQUEST_OUT_OF_RANGE;
        }
    }
    return (fl_ret_U8);
}
#endif

#if defined(MEMDIAG_MEMORY_READ_WRITE_BY_ADDRESS) || defined(MEMDIAG_MEMORY_VALIDITY_CHECK)
static void MemmDiag_MemCpy(void *const pDest, const void *const pSrc, const uint16 BytesCount)
{
    uint8 *const pDestBuf = (uint8 *)pDest;
    const uint8 *const pSrcBuf = (const uint8 *)pSrc;
    uint16 fl_index_u16 = 0U;
    for (fl_index_u16 = 0U; fl_index_u16 < BytesCount; fl_index_u16++)
    {
        pDestBuf[fl_index_u16] = pSrcBuf[fl_index_u16];
    }
}

#endif

#ifdef MEMDIAG_VIP_GIP_MEMORY_CHECKSUM_TEST
/*=====================================================================================================================
**
** Function Name    :  Memdiag_VIP_GIP_Memory_Checksum_RCStart
**
** Visibility       :  Public
**
** Description      :  Triggers VIP Internal flash/ NAND/NOR checksum check
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode
**
**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Memdiag_VIP_GIP_Memory_Checksum_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    static Std_ReturnType fl_idx_u8 = 1U;
    checksum_index = Data[DATA_BYTE_0];
    static uint8 DataStatus[3U] = {0U, 0U, 0U};

    if (MfgModeActive == MEET_SESSION)
    {
        if (checksum_index == NAND_FLASH)
        {
            ret = Memdiag_NAND_Checksum_Check_RCStart(Data, ErrorCode);
        }
        else if (checksum_index == NOR_FLASH)
        {
            ret = Memdiag_NOR_Checksum_Check_RCStart(Data, ErrorCode);
        }
        else if (checksum_index == VIP_FLASH)
        {
            ret = Memdiag_IntflashValidityCheck_RCStart(Data, ErrorCode);
        }
        else if (checksum_index == FlashChksumTestForALl_ID)
        {
            switch (fl_idx_u8)
            {
            case NAND_FLASH:
                ret = Memdiag_NAND_Checksum_Check_RCStart(Data, ErrorCode);
                if (ret != DCM_E_PENDING)
                {
                    DataStatus[fl_idx_u8 - 1U] = Data[0U];
                    fl_idx_u8 = 2U;
                    ret = DCM_E_PENDING;
                }
                break;
            case NOR_FLASH:
                ret = Memdiag_NOR_Checksum_Check_RCStart(Data, ErrorCode);
                if (ret != DCM_E_PENDING)
                {
                    DataStatus[fl_idx_u8 - 1U] = Data[0U];
                    fl_idx_u8 = 3U;
                    ret = DCM_E_PENDING;
                }
                break;
            case VIP_FLASH:
                ret = Memdiag_IntflashValidityCheck_RCStart(Data, ErrorCode);
                if (ret != DCM_E_PENDING)
                {
                    DataStatus[fl_idx_u8 - 1U] = Data[0U];
                    for (fl_idx_u8 = 0U; fl_idx_u8 < 3U; fl_idx_u8++)
                    {
                        Data[fl_idx_u8] = DataStatus[fl_idx_u8];
                    }
                    ret = E_OK;
                    fl_idx_u8 = 1U;
                }
                break;
            default:
                /* no action */
                break;
            }
        }

        else
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
    }
    else
    {
        /*Invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Memdiag_VIP_GIP_Memory_Checksum_RCStop
**
** Visibility       :  Public
**
** Description      :  Stops VIP Internal flash/ NAND/NOR checksum check
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode

**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Memdiag_VIP_GIP_Memory_Checksum_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    Std_ReturnType DataStatus[3] = {0, 0, 0};
    static Std_ReturnType fl_idx_u8 = 1U;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        if (checksum_index == NAND_FLASH)
        {
            Data[checksum_index - 1U] = Memdiag_NAND_Checksum_Check_RCStop(Data, ErrorCode);
            ret = E_OK;
        }
        else if (checksum_index == NOR_FLASH)
        {
            Data[checksum_index - 1U] = Memdiag_NOR_Checksum_Check_RCStop(Data, ErrorCode);
            ret = E_OK;
        }
        else if (checksum_index == VIP_FLASH)
        {
            Data[checksum_index - 1U] = Memdiag_IntflashValidityCheck_RCStop(Data, ErrorCode);
            ret = E_OK;
        }
        else if (checksum_index == FlashChksumTestForALl_ID)
        {
            switch (fl_idx_u8)
            {
            case NAND_FLASH:
                ret = Memdiag_NAND_Checksum_Check_RCStop(Data, ErrorCode);
                if (ret != DCM_E_PENDING)
                {
                    DataStatus[fl_idx_u8 - 1U] = Data[0];
                    fl_idx_u8 = 2;
                    ret = DCM_E_PENDING;
                }
                break;
            case NOR_FLASH:
                ret = Memdiag_NOR_Checksum_Check_RCStop(Data, ErrorCode);
                if (ret != DCM_E_PENDING)
                {
                    DataStatus[fl_idx_u8 - 1U] = Data[0];
                    fl_idx_u8 = 3;
                    ret = DCM_E_PENDING;
                }
                break;
            case VIP_FLASH:
                ret = Memdiag_IntflashValidityCheck_RCStop(Data, ErrorCode);
                if (ret != DCM_E_PENDING)
                {
                    DataStatus[fl_idx_u8 - 1U] = Data[0];
                    for (fl_idx_u8 = 0U; fl_idx_u8 < 3U; fl_idx_u8++)
                    {
                        Data[fl_idx_u8] = DataStatus[fl_idx_u8];
                    }
                    ret = E_OK;
                    fl_idx_u8 = 1U;
                }
                break;
            default:
                /* no action */
                break;
            }
        }
        else
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
    }
    else
    {
        /*Invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Memdiag_VIP_GIP_Memory_Checksum_RCStatus
**
** Visibility       :  Public
**
** Description      :  Returns results of VIP Internal flash/ NAND/NOR checksum check
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode

**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_VIP_GIP_Memory_Checksum_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    static uint8 DataStatus[3U] = {0U, 0U, 0U};
    static uint8 DataResult[3U] = {0U, 0U, 0U};
    static uint8 fl_idx_u8 = 1U;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        if (checksum_index == NAND_FLASH)
        {
            ret = Memdiag_NAND_Checksum_Check_RCStatus(Data, ErrorCode);
        }
        else if (checksum_index == NOR_FLASH)
        {
            ret = Memdiag_NOR_Checksum_Check_RCStatus(Data, ErrorCode);
        }
        else if (checksum_index == VIP_FLASH)
        {
            ret = Memdiag_IntflashValidityCheck_RCStatus(Data, ErrorCode);
        }
        else if (checksum_index == FlashChksumTestForALl_ID)
        {
            switch (fl_idx_u8)
            {
            case NAND_FLASH:
                ret = Memdiag_NAND_Checksum_Check_RCStatus(Data, ErrorCode);
                if (ret != DCM_E_PENDING)
                {
                    DataStatus[fl_idx_u8 - 1U] = Data[0U];
                    DataResult[fl_idx_u8 - 1U] = Data[1U];
                    fl_idx_u8 = 2U;
                    ret = DCM_E_PENDING;
                }
                break;
            case NOR_FLASH:
                ret = Memdiag_NOR_Checksum_Check_RCStatus(Data, ErrorCode);
                if (ret != DCM_E_PENDING)
                {
                    DataStatus[fl_idx_u8 - 1U] = Data[0U];
                    DataResult[fl_idx_u8 - 1U] = Data[1U];
                    fl_idx_u8 = 3U;
                    ret = DCM_E_PENDING;
                }
                break;
            case VIP_FLASH:
                ret = Memdiag_IntflashValidityCheck_RCStatus(Data, ErrorCode);
                if (ret != DCM_E_PENDING)
                {
                    DataStatus[fl_idx_u8 - 1U] = Data[0U];
                    DataResult[fl_idx_u8 - 1U] = Data[1U];
                    ret = E_OK;
                    for (fl_idx_u8 = 0U; fl_idx_u8 < 3U; fl_idx_u8++)
                    {
                        Data[fl_idx_u8] = DataStatus[fl_idx_u8];
                        Data[fl_idx_u8 + 3U] = DataResult[fl_idx_u8];
                    }
                    fl_idx_u8 = 1U;
                }
                break;
            default:
                /* no action */
                break;
            }
        }
        else
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
    }
    else
    {
        /*Invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Memdiag_NAND_Checksum_Check_RCStart
**
** Visibility       :  Private
**
** Description      :  triggers NAND flash checksum check
**
**
** Invocation       :  MeetMgr.diagcdd , Function:Memdiag_VIP_GIP_Memory_Checksum_RCStart
**
** Inputs           :  Data[In]:NAND Flash index
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/
static Std_ReturnType Memdiag_NAND_Checksum_Check_RCStart(uint8 *Data, uint8 *ErrorCode)
{

    Std_ReturnType ret = E_NOT_OK;

    if (Memdiag_NANDFlashChecksum_RCStatus == eROUTINE_INPROGRESS)
    {
        // Already Routine in progress
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
    }
    else
    {
        ret = (eRoutineStatus)Memdiag_NANDFlashConfig.MemDiag_NANDFlash_ChksumStart(Data, ErrorCode);
        if (DCM_E_PENDING != ret)
        {
            Memdiag_NANDFlashChecksum_RCStatus = (eRoutineStatus)Data[0];
            Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_NAND_FLASH_RCTYPE, (uint8)Memdiag_NANDFlashChecksum_RCStatus);
            ret = E_OK;
        }
    }

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Memdiag_NAND_Checksum_Check_RCStop
**
** Visibility       :  Private
**
** Description      :  stops NAND flash checksum check
**
**
** Invocation       :  MeetMgr.diagcdd , Function:Memdiag_VIP_GIP_Memory_Checksum_RCStop
**
** Inputs           :  Data[Out]:to send Routine Control Result
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/
static Std_ReturnType Memdiag_NAND_Checksum_Check_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Memdiag_NANDFlashChecksum_RCStatus = (eRoutineStatus)Memdiag_NANDFlashConfig.MemDiag_NANDFlash_ChksumStop(Data, ErrorCode);
    Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_NAND_FLASH_RCTYPE, (uint8)Memdiag_NANDFlashChecksum_RCStatus);
    return E_OK;
}

/*=====================================================================================================================
**
** Function Name    :  Memdiag_NAND_Checksum_Check_RCStatus
**
** Visibility       :  Public
**
** Description      :  returns routine control status for NAND flash Checksum test
**
**
** Invocation       :  MeetMgr.diagcdd , Function:Memdiag_VIP_GIP_Memory_Checksum_RCStatus
**
** Inputs           :  Data[Out]:to send Routine Control Result
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/
static Std_ReturnType Memdiag_NAND_Checksum_Check_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;

    if (Memdiag_NANDFlashChecksum_RCStatus != eROUTINE_INACTIVE)
    {
        ret = Memdiag_NANDFlashConfig.MemDiag_NANDFlash_ChksumResult(Data, ErrorCode);
        if (DCM_E_PENDING != ret)
        {
            Memdiag_NANDFlashChecksum_RCStatus = (eRoutineStatus)Data[0];
            Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_NAND_FLASH_RCTYPE, (uint8)Memdiag_NANDFlashChecksum_RCStatus);
            ret = E_OK;
        }
    }
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Memdiag_NOR_Checksum_Check_RCStart
**
** Visibility       :  Private
**
** Description      :  triggers NOR flash checksum check
**
**
** Invocation       :  MeetMgr.diagcdd , Function:Memdiag_VIP_GIP_Memory_Checksum_RCStart
**
** Inputs           :  Data[In]:NOR Flash index
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/
static Std_ReturnType Memdiag_NOR_Checksum_Check_RCStart(uint8 *Data, uint8 *ErrorCode)
{

    Std_ReturnType ret = E_NOT_OK;

    if (Memdiag_NORFlashChecksum_RCStatus == eROUTINE_INPROGRESS)
    {
        // Already Routine in progress
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
    }
    else
    {
        ret = (eRoutineStatus)Memdiag_NORFlashConfig.MemDiag_NORFlash_ChksumStart(Data, ErrorCode);
        if (DCM_E_PENDING != ret)
        {
            Memdiag_NORFlashChecksum_RCStatus = (eRoutineStatus)Data[0];
            Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_NOR_FLASH_RCTYPE, (uint8)Memdiag_NORFlashChecksum_RCStatus);
            ret = E_OK;
        }
    }

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Memdiag_NOR_Checksum_Check_RCStop
**
** Visibility       :  Private
**
** Description      :  stops NOR flash checksum check
**
**
** Invocation       :  MeetMgr.diagcdd , Function:Memdiag_VIP_GIP_Memory_Checksum_RCStop
**
** Inputs           :  Data[Out]:to send Routine Control Result
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/
static Std_ReturnType Memdiag_NOR_Checksum_Check_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Memdiag_NORFlashChecksum_RCStatus = (eRoutineStatus)Memdiag_NORFlashConfig.MemDiag_NORFlash_ChksumStop(Data, ErrorCode);
    Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_NOR_FLASH_RCTYPE, (uint8)Memdiag_NORFlashChecksum_RCStatus);
    return E_OK;
}

/*=====================================================================================================================
**
** Function Name    :  Memdiag_NOR_Checksum_Check_RCStatus
**
** Visibility       :  Public
**
** Description      :  returns routine control status for NOR flash checksum test
**
**
** Invocation       :  MeetMgr.diagcdd , Function:Memdiag_VIP_GIP_Memory_Checksum_RCStatus
**
** Inputs           :  Data[Out]:to send Routine Control Result
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/
static Std_ReturnType Memdiag_NOR_Checksum_Check_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;

    if (Memdiag_NORFlashChecksum_RCStatus != eROUTINE_INACTIVE)
    {
        ret = Memdiag_NORFlashConfig.MemDiag_NORFlash_ChksumResult(Data, ErrorCode);
        if (DCM_E_PENDING != ret)
        {
            Memdiag_NORFlashChecksum_RCStatus = (eRoutineStatus)Data[0];
            Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_NOR_FLASH_RCTYPE, (uint8)Memdiag_NORFlashChecksum_RCStatus);
            ret = E_OK;
        }
    }
    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Memdiag_DisplayMicroROMChecksum_RCStart
**
** Visibility       :  Private
**
** Description      :  triggers GIP Micro flash checksum check
**
**
** Invocation       :  MeetMgr.diagcdd , Function:Memdiag_VIP_GIP_Memory_Checksum_RCStart
**
** Inputs           :  Data[In]:NAND Flash index
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_DisplayMicroROMChecksum_RCStart(uint8 *Data, uint8 *ErrorCode)
{

    Std_ReturnType ret = E_NOT_OK;

    if (Memdiag_DisplayMicroROMChecksum_RCStatus == eROUTINE_INPROGRESS)
    {
        // Already Routine in progress
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
    }
    else
    {
        ret = (eRoutineStatus)Memdiag_DispMicroROMConfig.MemDiag_DisplayMicroROM_ChksumStart(Data, ErrorCode);
        if (DCM_E_PENDING != ret)
        {
            Memdiag_DisplayMicroROMChecksum_RCStatus = (eRoutineStatus)Data[0];
            Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_DISPLAY_MICRO_ROM_RCTYPE, (uint8)Memdiag_DisplayMicroROMChecksum_RCStatus);
            ret = E_OK;
        }
    }

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Memdiag_DisplayMicro_ROMChecksum_Check_RCStop
**
** Visibility       :  Private
**
** Description      :  stops GIP Micro checksum check
**
**
** Invocation       :  MeetMgr.diagcdd , Function:Memdiag_VIP_GIP_Memory_Checksum_RCStop
**
** Inputs           :  Data[Out]:to send Routine Control Result
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_DisplayMicro_ROMChecksum_Check_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Memdiag_DisplayMicroROMChecksum_RCStatus = (eRoutineStatus)Memdiag_DispMicroROMConfig.MemDiag_DisplayMicroROM_ChksumStop(Data, ErrorCode);
    Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_DISPLAY_MICRO_ROM_RCTYPE, (uint8)Memdiag_DisplayMicroROMChecksum_RCStatus);
    return E_OK;
}

/*=====================================================================================================================
**
** Function Name    :  Memdiag_DisplayMicro_ROMChecksum_Check_RCStatus
**
** Visibility       :  Public
**
** Description      :  returns routine control status for GIP Micro Checksum test
**
**
** Invocation       :  MeetMgr.diagcdd , Function:Memdiag_VIP_GIP_Memory_Checksum_RCStatus
**
** Inputs           :  Data[Out]:to send Routine Control Result
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_DisplayMicro_ROMChecksum_Check_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;

    if (Memdiag_DisplayMicroROMChecksum_RCStatus != eROUTINE_INACTIVE)
    {
        ret = (eRoutineStatus)Memdiag_DispMicroROMConfig.MemDiag_DisplayMicroROM_ChksumResult(Data, ErrorCode);
        if (DCM_E_PENDING != ret)
        {
            Memdiag_DisplayMicroROMChecksum_RCStatus = (eRoutineStatus)Data[0];
            Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_DISPLAY_MICRO_ROM_RCTYPE, (uint8)Memdiag_DisplayMicroROMChecksum_RCStatus);
            ret = E_OK;
        }
    }
    return ret;
}
#endif

#ifdef AUTO_CONFIGURE_OR_VERIFY
/*=====================================================================================================================
**
** Function Name    :  Memdiag_AutoConfigureorVerify_RCStart
**
** Visibility       :  Public
**
** Description      :  triggers configuration or verification of prefix and suffix of Visteon part number
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In]: Configure or verify option, prefix and suffix characters
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_AutoConfigureorVerify_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {

        if (eNVM_STARTED == NvmStatus)
        {
            if (LAST_NVM_DR_STARTED == 1)
            {
                /*Already Routine in progress*/
                *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
            }
            else
            {
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }
        }
        else
        {
            if ((CONFIGURE == Data[DATA_BYTE_0]) || (VERIFY == Data[DATA_BYTE_0]))
            {
                // check whether the variants are valid
                ret = MemDiag_ConfigorVerify.MemDiag_ValidateInput(Data);
                if ((uint8)E_OK == ret)
                {
                    MemLib_MemCpy(NVM_Config_Verify_Buffer, Data, CONFIG_OR_VERIFY_LENGTH);
                    NVMConfigorVerifyStatus = NVM_CONFIGVERIFY_START;
                    Memdiag_AutoConfigorVerify_RCStatus = eROUTINE_INPROGRESS;
                    NvmStatus = eNVM_STARTED;
                    LAST_NVM_DR_STARTED = 1; // AUTO_CONFIG_OR_VERIFY
                    Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_AUTOCONFIGORVERIFY_RCTYPE, (uint8)Memdiag_AutoConfigorVerify_RCStatus);
                    Data[DATA_BYTE_1] = (uint8)NvmStatus;
                    Data[DATA_BYTE_2] = NVM_Config_Verify_Buffer[DATA_BYTE_0]; // Nvm SubFunction
                }
                else
                {
                    // not a valid variant
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    NvmStatus = eNVM_NOT_STARTED;
                    LAST_NVM_DR_STARTED = 0; // NONE
                }
            }
            else
            {
                // not a valid function,only configure or verify is allowed
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                NvmStatus = eNVM_NOT_STARTED;
                LAST_NVM_DR_STARTED = 0; // NONE
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  MemDiag_NVMConfigureorVerify
**
** Visibility       :  Private
**
** Description      :  configuration or verification of prefix and suffix of Visteon part number
**
**
** Invocation       :  Mem.diagcdd
**
** Inputs           :  None
**
** Outputs          :  None
**
** Critical Section : No
**
**====================================================================================================================*/
void MemDiag_NVMConfigureorVerify(void)
{

    uint8 nvmStatus = NVM_REQ_NOT_OK;
    uint8 index;

    switch (NVMConfigorVerifyStatus)
    {
    case NVM_CONFIGVERIFY_START:

        if (CONFIGURE == NVM_Config_Verify_Buffer[DATA_BYTE_0])
        {
            // configure - write
            switch (Memdiag_AutoConfig_CurrentNVMWriteReqState)
            {
            case eNVMWrite_InitiateRequest:
                #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
                MemDiagNvmJobResult_U8.MemDiag_Write(0); /*clear NVM Jobresult RTE var*/
                #endif
                AutoConfig_ret = MemDiag_ConfigorVerify.MemDiag_Configure(NVMwriteBuffer);
                if (AutoConfig_ret == (uint8)E_OK)
                {
                    Memdiag_AutoConfig_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
                }
                else
                {
                    NVMConfigorVerifyStatus = NVM_CONFIGVERIFY_RESULTS;
                }

                break;
            case eNVMWrite_WaitForResponse:
                #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
                MemDiagNvmJobResult_U8.MemDiag_Read(&nvmStatus);
                #else
                MemDiag_ConfigorVerify.MemDiag_ReadNVMJobStatus(&nvmStatus);
                #endif
                if (nvmStatus == (uint8)NVM_REQ_OK)
                {
                    nvmStatus = 0U;
                    NVMConfigorVerifyStatus = NVM_CONFIGVERIFY_RESULTS;
                    Memdiag_AutoConfig_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                }
                else if (nvmStatus == (uint8)NVM_REQ_PENDING)
                {
                }
                else
                {
                    AutoConfig_ret = E_NOT_OK;
                    NVMConfigorVerifyStatus = NVM_CONFIGVERIFY_RESULTS;
                    Memdiag_AutoConfig_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                }

                break;
            default:
                /*No action is required in default case*/
                break;
            }
        }
        else
        {
            // verify - read
            AutoConfig_ret = MemDiag_ConfigorVerify.MemDiag_Verify(NVMreadbuffer);
            NVMConfigorVerifyStatus = NVM_CONFIGVERIFY_COMPARE;
        }
        break;

    case NVM_CONFIGVERIFY_COMPARE:
        // verify - comparing data after read
        if ((VERIFY == NVM_Config_Verify_Buffer[DATA_BYTE_0]) && ((uint8)E_OK == AutoConfig_ret))
        {
            for (index = 0; index < CONFIG_WRITE_DATA_LENGTH; index++)
            {

                if (NVMwriteBuffer[index] != NVMreadbuffer[index])
                {
                    AutoConfig_ret = E_NOT_OK;
                    break;
                }
            }
        }
        else
        {
            AutoConfig_ret = E_NOT_OK;
        }
        NVMConfigorVerifyStatus = NVM_CONFIGVERIFY_RESULTS;
        break;

    case NVM_CONFIGVERIFY_RESULTS:
        // update routine status
        if ((uint8)E_OK == AutoConfig_ret)
        {
            Memdiag_AutoConfigorVerify_RCStatus = eROUTINE_FINISH_OK;
            NvmStatus = eNVM_COMPLETED;
        }
        else
        {
            Memdiag_AutoConfigorVerify_RCStatus = eROUTINE_FINISH_NOK;
            NvmStatus = eNVM_FAILED;
        }
        NVMConfigorVerifyStatus = NVM_CONFIGVERIFY_NONE;
        break;

    case NVM_CONFIGVERIFY_NONE:
        break;

    default:
        /*No action required in default case*/
        break;
    }
}
/*=====================================================================================================================
**
** Function Name    :  Memdiag_AutoConfigureorVerify_RCStatus
**
** Visibility       :  Private
**
** Description      :  provides status of configuration/verification of prefix and suffix of Visteon part number
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In]: Configure or verify option
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_AutoConfigureorVerify_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        if (eNVM_NOT_STARTED == NvmStatus)
        {
            *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
            NvmStatus = eNVM_NOT_STARTED;
            LAST_NVM_DR_STARTED = 0; // NONE
        }
        else
        {
            if (LAST_NVM_DR_STARTED == 1)
            {
                Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_AUTOCONFIGORVERIFY_RCTYPE, (uint8)Memdiag_AutoConfigorVerify_RCStatus);
                Data[DATA_BYTE_1] = (uint8)NvmStatus;
                Data[DATA_BYTE_2] = NVM_Config_Verify_Buffer[DATA_BYTE_0];
                ret = E_OK;
            }
            else
            {
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Memdiag_AutoConfigureorVerify_RCStop
**
** Visibility       :  Private
**
** Description      :  provides status of configuration/verification of prefix and suffix of Visteon part number
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In]: Configure or verify option
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_AutoConfigureorVerify_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_AUTOCONFIGORVERIFY_RCTYPE, (uint8)Memdiag_AutoConfigorVerify_RCStatus);
        ret = E_OK;
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif
#ifdef PROGRAM_NVM_FROM_ROM
/*=====================================================================================================================
**
** Function Name    :  Memdiag_Program_NVM_from_ROM_RCStart
**
** Visibility       :  Public
**
** Description      :  Starts Routine Control of restoring and writing default values of NVM
**
** Invocation       :  MeetMgr.diagcdd  , Function:RC_START_Diag_FE22
**
** Inputs           :  Data[In]:0 byte
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_Program_NVM_from_ROM_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        if (eROUTINE_INPROGRESS == Memdiag_ProgramNVM_Restore_RCStatus)
        {
            /*Already Routine in progress*/
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
        else
        {
			// starts from 0th index of Valid NVM blocks when routine starts
            Memdiag_NVM_BlockID = 0x0U; 
            NvmRestore_RCStatus = PROGRAM_NVM_FROM_ROM_RESTORE;
            Memdiag_ProgramNVM_Restore_RCStatus = eROUTINE_INPROGRESS;
            Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_PROGRAM_NVM_FROM_ROM_RCTYPE, (uint8)Memdiag_ProgramNVM_Restore_RCStatus);
            ret = E_OK;
        }
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  MemDiag_Restoring_NVM_defaultValues
**
** Visibility       :  Private
**
** Description      :  Restore Default values from ROM and write it to NVM
**
**
** Invocation       :  MeetMgr.diagcdd , Function:CmpActive
**
** Inputs           :  NA
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
void MemDiag_Restoring_NVM_defaultValues(void)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus = NVM_REQ_NOT_OK;

    switch (NvmRestore_RCStatus)
    {
    case PROGRAM_NVM_FROM_ROM_RESTORE:
        switch (Memdiag_ProgramROM_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            MemDiagNvmJobResult_U8.MemDiag_Write(0); /*clear NVM Jobresult RTE var*/
            #endif
            #ifndef PROGRAM_NVM_FROM_ROM_LIMITED_BLOCK
            if (Memdiag_NVM_BlockID < NUMBER_OF_NVBLOCKS)
            #else
            if (Memdiag_NVM_BlockID < NUMBER_OF_LIMITED_NVBLOCKS)
            #endif
            {
                // Restoring default value from ROM to RAM
                #ifndef PROGRAM_NVM_FROM_ROM_LIMITED_BLOCK
                ret = MemDiag_ProgNVMfromROM[Memdiag_NVM_BlockID].MemDiag_RestoreNVM_MappingBlkIDtoRTE(Valid_NVBlocks[Memdiag_NVM_BlockID]);
                #else
                #ifdef PROGRAM_NVM_FROM_ROM_BLOCKWISE
                ret = MemDiag_ProgNVMfromROM.MemDiag_RestoreNVM_MappingBlkIDtoRTE(ProgramNVMfromROM_ValidBlock[Memdiag_NVM_BlockID]);
                #else
                ret = MemDiag_ProgNVMfromROM[Memdiag_NVM_BlockID].MemDiag_RestoreNVM_MappingBlkIDtoRTE(ProgramNVMfromROM_ValidBlock[Memdiag_NVM_BlockID]);
                #endif
                #endif

                if (ret == (uint8)E_OK)
                {
                    Memdiag_ProgramROM_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
                }
            }
            else
            {
                Memdiag_ProgramNVM_Restore_RCStatus = eROUTINE_FINISH_OK;
                NvmRestore_RCStatus = PROGRAM_NVM_FROM_ROM_NONE;
            }
            break;
        case eNVMWrite_WaitForResponse:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            MemDiagNvmJobResult_U8.MemDiag_Read(&nvmStatus);
            #else
            #ifndef PROGRAM_NVM_FROM_ROM_LIMITED_BLOCK
            if (Memdiag_NVM_BlockID < NUMBER_OF_NVBLOCKS)
            {
                (void)MemDiagNvmBlkJobResult.MemDiag_JobResultRead_byBlkID(Valid_NVBlocks[Memdiag_NVM_BlockID], &nvmStatus); /*Read NVM Jobresult of the block*/
            }
            #else
            if (Memdiag_NVM_BlockID < NUMBER_OF_LIMITED_NVBLOCKS)
            {
                (void)MemDiagNvmBlkJobResult.MemDiag_JobResultRead_byBlkID(ProgramNVMfromROM_ValidBlock[Memdiag_NVM_BlockID], &nvmStatus); /*Read NVM Jobresult of the block*/
            }
            #endif
            #endif
            if (nvmStatus == (uint8)NVM_REQ_OK)
            {
                #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
                nvmStatus = 0U;
                #endif
                NvmRestore_RCStatus = PROGRAM_NVM_FROM_ROM_WRITE;
                Memdiag_ProgramROM_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
            }
            else if (nvmStatus == (uint8)NVM_REQ_PENDING)
            {
                /*No action required*/
            }
            else
            {
                NvmRestore_RCStatus = PROGRAM_NVM_FROM_ROM_NONE;
                Memdiag_ProgramROM_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                Memdiag_ProgramNVM_Restore_RCStatus = eROUTINE_FINISH_NOK;
            }
            break;
        default:
            /*No action required in default case*/
            break;
        }
        break;

    case PROGRAM_NVM_FROM_ROM_WRITE:
        switch (Memdiag_ProgramROM_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            MemDiagNvmJobResult_U8.MemDiag_Write(0); /*clear NVM Jobresult*/
            #endif
            // Writing restored default value from RAM to NVM
            #ifndef PROGRAM_NVM_FROM_ROM_LIMITED_BLOCK
            if (Memdiag_NVM_BlockID < NUMBER_OF_NVBLOCKS)
            {
                ret = MemDiag_ProgNVMFromRam.MemDiag_WriteNVM_MappingBlkIDtoRTE(Valid_NVBlocks[Memdiag_NVM_BlockID]);
            }
            #else
            if (Memdiag_NVM_BlockID < NUMBER_OF_LIMITED_NVBLOCKS)
            {
                ret = MemDiag_ProgNVMFromRam.MemDiag_WriteNVM_MappingBlkIDtoRTE(ProgramNVMfromROM_ValidBlock[Memdiag_NVM_BlockID]);
            }
            #endif
            if (ret == (uint8)E_OK)
            {
                Memdiag_ProgramROM_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            break;
        case eNVMWrite_WaitForResponse:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            MemDiagNvmJobResult_U8.MemDiag_Read(&nvmStatus);
            #else
            #ifndef PROGRAM_NVM_FROM_ROM_LIMITED_BLOCK
            if (Memdiag_NVM_BlockID < NUMBER_OF_NVBLOCKS)
            {
                (void)MemDiagNvmBlkJobResult.MemDiag_JobResultRead_byBlkID(Valid_NVBlocks[Memdiag_NVM_BlockID], &nvmStatus);
            }
            #else
            if (Memdiag_NVM_BlockID < NUMBER_OF_LIMITED_NVBLOCKS)
            {
                (void)MemDiagNvmBlkJobResult.MemDiag_JobResultRead_byBlkID(ProgramNVMfromROM_ValidBlock[Memdiag_NVM_BlockID], &nvmStatus);
            }
            #endif
            #endif
            if (nvmStatus == (uint8)NVM_REQ_OK)
            {
                Memdiag_NVM_BlockID++;
                NvmRestore_RCStatus = PROGRAM_NVM_FROM_ROM_RESTORE;
                Memdiag_ProgramROM_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
            }
            else if (nvmStatus == (uint8)NVM_REQ_PENDING)
            {
                /*Wait state. No action required*/
            }
            else
            {
                NvmRestore_RCStatus = PROGRAM_NVM_FROM_ROM_NONE;
                Memdiag_ProgramROM_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                Memdiag_ProgramNVM_Restore_RCStatus = eROUTINE_FINISH_NOK;
            }

            break;
        default:
            /*No action required in default case*/
            break;
        }
        break;

    case PROGRAM_NVM_FROM_ROM_NONE:
        /*No action required*/
        break;

    default:
        /*No action required in default case*/
        break;
    }
}

/*=====================================================================================================================
**
** Function Name    :  Memdiag_Program_NVM_from_ROM_RCStop
**
** Visibility       :  Public
**
** Description      :  Stops routine ProgramNVMfromROM
**
** Invocation       :  MeetMgr.diagcdd , Function: RC_STOP_Diag_FE22
**
** Inputs           :  Data[Out]: status of Routine Control Stop is updated
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_Program_NVM_from_ROM_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        Memdiag_ProgramNVM_Restore_RCStatus = eROUTINE_FINISH_OK;
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_PROGRAM_NVM_FROM_ROM_RCTYPE, (uint8)Memdiag_ProgramNVM_Restore_RCStatus);
        ret = E_OK;
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Memdiag_Program_NVM_from_ROM_RCStatus
**
** Visibility       :  Public
**
** Description      :  Gives Routine Control Status for Program NVM from ROM
**
** Invocation       :  MeetMgr.diagcdd , Function:RC_RESULTS_Diag_FE22
**
** Inputs           :  Data[Out]: status of Routine Control is updated
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_Program_NVM_from_ROM_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_PROGRAM_NVM_FROM_ROM_RCTYPE, (uint8)Memdiag_ProgramNVM_Restore_RCStatus);
        ret = E_OK;
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef MEMDIAG_ODOMETER_NVM_READWRITE
/*=====================================================================================================================
**
** Function Name    :  Memdiag_OdometerNVMRead
**
** Visibility       :  Public
**
** Description      :  Reads Odometer values from NVM
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA4C
**
** Inputs           :  Data[Out]:Odometer value
**                     Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_OdometerNVMRead(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint32 Data32Bits = 0UL;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = OdometerRW.MemDiag_Odo_Read(&Data32Bits);

        #ifdef MEMDIAG_ODOMETER_READWRIE_4BYTES
        Data[DATA_BYTE_0] = (uint8)((Data32Bits & 0xFF000000UL) >> 24UL);
        Data[DATA_BYTE_1] = (uint8)((Data32Bits & 0xFF0000UL) >> 16UL);
        Data[DATA_BYTE_2] = (uint8)((Data32Bits & 0xFF00UL) >> 8UL);
        Data[DATA_BYTE_3] = (uint8)((Data32Bits & 0xFFUL));
        #else
        Data[DATA_BYTE_0] = (uint8)((Data32Bits & 0xFF0000UL) >> 16UL);
        Data[DATA_BYTE_1] = (uint8)((Data32Bits & 0xFF00UL) >> 8UL);
        Data[DATA_BYTE_2] = (uint8)((Data32Bits & 0xFFUL));
        #endif
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Memdiag_OdometerNVMWrite
**
** Visibility       :  Public
**
** Description      :  Writes Odometer value in NVM
**
** Invocation       :  MeetMgr.diagcdd, Function:Write_Diag_FA4C
**
** Inputs           :  Data[In]:contains Odometer value
**                     Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_OdometerNVMWrite(const uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    uint32 CurrentData = 0UL;

    #ifdef MEMDIAG_ODOMETER_NVM_READCHECK
    uint32 OriginalData = 0UL;
    #endif

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        #ifdef MEMDIAG_ODOMETER_READWRIE_4BYTES
        CurrentData = ((uint32)Data[0U] << 24U) + ((uint32)Data[1U] << 16U) + ((uint32)Data[2U] << 8U) + ((uint32)Data[3U]);
        #else
        CurrentData = ((uint32)Data[0U] << 16U) + ((uint32)Data[1U] << 8U) + ((uint32)Data[2U]);
        #endif

        #ifdef MEMDIAG_ODOMETER_NVM_READCHECK
        (void)OdometerRW.MemDiag_Odo_Read(&OriginalData);

        if (CurrentData < OriginalData)
        {
            ret = E_NOT_OK;
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
        else if (CurrentData > MEET_ODO_MAX_VALUE)
        {
            CurrentData = MEET_ODO_MAX_VALUE;
            ret = OdometerRW.MemDiag_Odo_Write(CurrentData);
        }
        else
        {
            ret = OdometerRW.MemDiag_Odo_Write(CurrentData);
        }
        #else
        ret = OdometerRW.MemDiag_Odo_Write(CurrentData);
        #endif
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef MEMDIAG_ODOMETER_NVM_ROUTINE
/*=====================================================================================================================
** Function Name    :  Memdiag_OdometerNVM_RCStart
**
** Visibility       :  Public
**
** Description      :  Reads Odometer values from NVM
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[Out]:Odometer value
**                     Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**====================================================================================================================*/
Std_ReturnType Memdiag_Odometer_NVM_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 odoReset = 0u;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        if (eROUTINE_INPROGRESS == Memdiag_OdometerNVM_RCStatus)
        {
            /*Already Routine in progress*/
            *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
        }
        else
        {
            Memdiag_OdometerNVM_RCStatus = eROUTINE_INPROGRESS;

            ret = OdometerRW.MemDiag_Odo_Write(odoReset);

            if ((uint8)E_OK == ret)
            {
                maxOdoResetDone = FALSE;
                Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_ODOMETER_NVM_RCTYPE, (uint8)Memdiag_OdometerNVM_RCStatus);
            }
            else
            {
                maxOdoResetDone = TRUE;
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
** Function Name    :  Memdiag_OdometerNVM_RCStop
**
** Visibility       :  Public
**
** Description      :  Writes Odometer value in NVM
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In]:contains Odometer value
**                     Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**====================================================================================================================*/
Std_ReturnType Memdiag_Odometer_NVM_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        Memdiag_OdometerNVM_RCStatus = eROUTINE_STOPPED;

        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_ODOMETER_NVM_RCTYPE, (uint8)Memdiag_OdometerNVM_RCStatus);

        ret = E_OK;
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}

/*=====================================================================================================================
** Function Name    :  Memdiag_OdometerNVM_RCStatus
**
** Visibility       :  Private
**
** Description      :  returns Odometer check result
**
** Invocation       :  Mem.diagCdd , Function: Memdiag_Memory_Validity_Check_RCStatus
**
** Inputs           :  Data,ErrorCode
**
** Outputs          :  E_OK : Success
**
** Critical Section :  No
**====================================================================================================================*/
Std_ReturnType Memdiag_Odometer_NVM_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        if (eROUTINE_INACTIVE != Memdiag_OdometerNVM_RCStatus)
        {
            if (FALSE == maxOdoResetDone)
            {
                Memdiag_OdometerNVM_RCStatus = eROUTINE_FINISH_OK;
            }
            else
            {
                Memdiag_OdometerNVM_RCStatus = eROUTINE_FINISH_NOK;
            }
            Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(MEMDIAG_ODOMETER_NVM_RCTYPE, (uint8)Memdiag_OdometerNVM_RCStatus);
            ret = E_OK;
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef NVMACCESSBYADDRESSRCENABLE
/*=====================================================================================================================
**
** Function Name    :  Memdiag_Data_Write_NVM_Address_RCStart
**
** Visibility       :  Public
**
** Description      :  Writes data to a given NVM address
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_F0FA
**
** Inputs           :  Data[In]:contains data to be written to a NVM address ,Block ID: 2 bytes Data:256 bytes
                       Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_Data_Write_NVM_Address_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = (uint8)0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = MemDiagDataReadWrite_U8.MemDiag_Data_Write(Data);
    }
    else
    {
        *ErrorCode = MGRDIAG_INVALID_MODE;
    }

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Memdiag_Data_Write_NVM_Address_RCStatus
**
** Visibility       :  Public
**
** Description      :  Writes data to a given NVM address
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_F0FA
**
** Inputs           :  Data[In]:contains data to be written to a NVM address ,Block ID: 2 bytes Data:256 bytes
                       Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_Data_Write_NVM_Address_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = (uint8)0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        Data[DATA_BYTE_0] = MEMDIAG_WRITE_PROCESS;
        MemDiagDataReadWrite_U8.MemDiag_JobResult(Data);
        ret = E_OK;
    }
    else
    {
        *ErrorCode = MGRDIAG_INVALID_MODE;
    }

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Memdiag_Data_Read_NVM_Address_RCStart
**
** Visibility       :  Public
**
** Description      :  Gives Routine Control Status for NVM read by address Operation
**
**
** Invocation       :  MeetMgr.diagcdd , Function:RC_RESULTS_Diag_F0FB
**
** Inputs           :  Data[Out]: status of Routine Control , data read from NVM (256 bytes)
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_Data_Read_NVM_Address_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = (uint8)0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = MemDiagDataReadWrite_U8.MemDiag_Data_Read(Data);
    }
    else
    {
        *ErrorCode = MGRDIAG_INVALID_MODE;
    }

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Memdiag_Data_Read_NVM_Address_RCStatus
**
** Visibility       :  Public
**
** Description      :  Gives Routine Control Status for NVM read by address Operation
**
**
** Invocation       :  MeetMgr.diagcdd , Function:RC_RESULTS_Diag_F0FB
**
** Inputs           :  Data[Out]: status of Routine Control , data read from NVM (256 bytes)
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Memdiag_Data_Read_NVM_Address_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = (uint8)0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        Data[DATA_BYTE_0] = MEMDIAG_READ_PROCESS;
        MemDiagDataReadWrite_U8.MemDiag_JobResult(Data);
        ret = E_OK;
    }
    else
    {
        *ErrorCode = MGRDIAG_INVALID_MODE;
    }

    return ret;
}
#endif

/*=====================================================================================================================
**  for each change to this file, be sure to record:
**  1.  who made the change and when the change was made
**  2.  why the change was made and the intended result
**  Following block needs to be repeated for each change
**====================================================================================================================*/
/*=====================================================================================================================
**   Note: In the traceability column we need to trace back to the Design Doc.
**   For the initial version it is traced to the Design Document section.
**   For further changes it shall trace to the source of the change which may
**   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any
**   other reason
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  01/Mar/2024
** CDSID             :  ddanecha
** Traceability      :  JIRA - TCID31491-3167
** Change Description:  Manu flag write corrected
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/09/2023
** CDSID             :  mprajapa
** Traceability      :  JIRA 3839
** Change Description:  Upddated identation.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  17/03/2023
** CDSID             :  rsubra13
** Traceability      :  RTC 1951466
** Change Description:  EEPROM Read/Write by address Response updated.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  06/02/2023
** CDSID             :  ddanecha
** Traceability      :  RTC 1936400
** Change Description:  MEET mode disable feature implemented.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  26/12/2022
** CDSID             :  rsubra13
** Traceability      :  RTC 1861099
** Change Description:  EEPROM Read Write by Address service newly implemented.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  27/Oct/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1811312
** Change Description:  Compiler warning fixed and Coverity/MISRA fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1744046
** Change Description:  UT uncovered issue fixed and Coverity-Misra Fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  03/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1707104
** Change Description:  MeetCdd Coverity-MISRA fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  23/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1634375
** Change Description:  Coverity/MISRA Fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  16/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1632871, 1655512, 1660171
** Change Description:  Odometer routine interfaces are added.
                        MemDiag_Restoring_NVM_defaultValues interface is updated to support single configuration function
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 6/May/2021
** CDSID             : razhakes
** Traceability      : RTC-1291863
** Change Description: COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM introduced and Manuf Mode service modified for SessionExit handling
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 15/March/2021
** CDSID             : razhakes
** Traceability      : RTC-1272178
** Change Description: MeetModeReadStatus API added for external components ref
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  10/March/2020
** CDSID             :  dkasiman
** Traceability      :  RTC-760543
** Change Description:  Coverity/Misra fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/01/2020
** CDSID             :  dkasiman
** Traceability      :  RTC 1380314
** Change Description:  Coverity/Misra fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  12/12/2019
** CDSID             :  dkasiman
** Traceability      :  RTC 1389704
** Change Description:  Checksum status update sequence corrected.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  9/11/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1365920
** Change Description:  Odometer NVM read write service newly implemented
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  28/06/2019
** CDSID             :  razhakes
** Traceability      :  RTC-1339061,1335642
** Change Description:  Added nvm status and Nvm callback in Auto configure/verify service
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  10/06/2019
** CDSID             :  razhakes
** Traceability      :  RTC-1334319
** Change Description:  program NVM from ROM service added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  10/04/2019
** CDSID             :  athiyag2
** Traceability      :  RTC-1331232
** Change Description:  Auto configure/verify service added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  26/02/2019
** CDSID             :  dkasiman / KCHIRUVO
** Traceability      :  RTC-1289796
** Change Description: Support provided to read/write in NVM more than 256 bytes.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  02/march/2019
** CDSID             :  razhakes
** Traceability      :  RTC-1262817
** Change Description:  Checksum test VIP - GIP communication added.
**====================================================================================================================*/
/*====================================================================================================================*/
/** Date              :  11/1/2019
** CDSID             :  athiyag2
** Traceability      :  RTC 1262820
** Change Description:  NVM Read by block id function updated
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  06/10/2018
** CDSID             :  dkasiman
** Traceability      :  RTC-1211436
** Change Description: RAM test feature added for TCRAM and HYPER RAM.User can configure 6 ranges of memory to test.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  01/10/2018
** CDSID             :  dkasiman/MCHANDR2
** Traceability      :  RTC-1208647
** Change Description: MARKERADDRESSCHECKENABLE macro introduced to use either marker validity check or checksum status.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  25/9/2018
** CDSID             :  dkasiman
** Traceability      :  RTC-1175981
** Change Description:  Code modified to access from 0th address of TCRAM and Errorcode updated.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  11/8/2018
** CDSID             :  dkasiman
** Traceability      :  RTC-1175981
** Change Description:  Read/Write memory by address support for TCRAM and Hyper RAM
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/7/2018
** CDSID             :  dkasiman
** Traceability      :  RTC-1148640
** Change Description:  Review comments fix:Check program dependency macro renamed as Memory validity
                        check.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  10/7/2018
** CDSID             :  dkasiman
** Traceability      :  RTC-1148640
** Change Description:  NVM,Internal flash and hyper flash validity check in a single Routine of
**                      Check program dependencies DR.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  18/6/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1137720
** Change Description:  warnings fixed
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  6/6/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1126958
** Change Description:  comments updated
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  31/05/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1126958
** Change Description:  included conditional compilation of features
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 23/05/2018
** CDSID             : athiyag2
** Traceability      : RTC 1113493
** Change Description: Initial version - MemDiagCdd Implementation for Turing Bookshelf.
**====================================================================================================================*/
#endif /* MEMDIAGCDD_C */
