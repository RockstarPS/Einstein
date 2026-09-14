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
** Name:           SharedBootDiagcdd.c
**
** Description:
**
**
**===================================================================================================================*/

#ifndef SHAREDBOOTDIAGCDD_C
#define SHAREDBOOTDIAGCDD_C

#include "Mgrdiagcdd.h"
#include "Mgrdiagcdd_cfg.h"
#include "SharedBootDiagcdd_cfg.h"
#include "SharedBootDiagcdd.h"
// #include "Os.h"

static boolean IsWriteInBootloadePagesDIDCalled;
static uint8 ALLRAMData[SHAREDIAG_NVM_PAGE_SIZE];
static argumentBuffer_t action;
static argumentBuffer_t action_init;
static uint32 word;
static uint8 u8CurrentMirror;
static boolean CheckForBootloaderData;

static const uint32 NVMMirrors[1 + 1] = {SHAREDIAG_NVM_BLOCK_0_START_ADDRESS,
                                         SHAREDIAG_NVM_BLOCK_1_START_ADDRESS};
static const uint8 Buff_To_Com[SHAREDIAG_GRANULARITY_BYTES] =
    {0xFF, 0xFF, 0xFF, 0xFF,
     0xFF, 0xFF, 0xFF, 0xFF,
     0xFF, 0xFF, 0xFF, 0xFF,
     0xFF, 0xFF, 0xFF, 0xFF};

static NVMWriteRequestState ShareDiag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;

#ifdef SHAREDIAG_SERVICE_ENABLE_1
static uint8 ShareDiagData_1[SHAREDIAG_REAL_SIZE_1];
static boolean ShareDiagPresent_1;
static uint8 ShareDiagData_additional_write_1[SHAREDIAG_ADDITIONAL_DATA_REAL_SIZE_1];
static uint8 ShareDiagData_additional_write_2[SHAREDIAG_ADDITIONAL_DATA_REAL_SIZE_2];
static boolean ShareDiagPresent_additional_data_1;
static boolean ShareDiagPresent_additional_data_2;
// static boolean ShareDiag_add_write_trigger_bool = FALSE;
// static uint8 ShareDiag_ErrorCode_U8 = 0;
#endif

#ifdef SHAREDIAG_SERVICE_ENABLE_2
static uint8 ShareDiagData_2[SHAREDIAG_REAL_SIZE_2];
static boolean ShareDiagPresent_2;
#endif

#ifdef SHAREDIAG_SERVICE_ENABLE_3
static uint8 ShareDiagData_3[SHAREDIAG_REAL_SIZE_3];
static boolean ShareDiagPresent_3;
#endif

#ifdef SHAREDIAG_SERVICE_BOOT_READ
static uint8 ShareDiagData_boot[SHAREDIAG_REAL_SIZE_BOOT_READ];
static boolean ShareDiagPresent_boot;
#endif
//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------
static void Sec_InitVariables(void)
{
    action_init.pRAMBuff = (uint8 *)NULL;
    action_init.pAddrToProgram = 0;
    action_init.pAddrToErase = 0;
    action_init.Size = 0;
    action_init.speedup = 4;
    action_init.command = idle;
    action_init.nextcommand = idle;

    word = 0;

    IsWriteInBootloadePagesDIDCalled = FALSE;
    CheckForBootloaderData = FALSE;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------
static uint8 GetCurrentMirror(void)
{
    uint8 u8Result = 0;
    if (SHAREDIAG_MIRROR_VALID(u8Result) == FALSE)
    {
        u8Result = 1;
    }

    return u8Result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------
static void DATNvmGetOneShotValue(const uint32 StartAddress, const uint16 RecordSize, uint8 *const pDestAddress, boolean *present)
{
    *present = FALSE;

    if (*(uint8 *)(NVMMirrors[u8CurrentMirror] + StartAddress + RecordSize) != SHAREDIAG_ERASED_VALUE)
    {
        MemLib_MemCpy((uint32 *)pDestAddress, (uint32 *)(NVMMirrors[u8CurrentMirror] + StartAddress), RecordSize);
        *present = TRUE;
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------
static void DATNvmWriteOneShotValue(uint8 *const pData, boolean *present, const uint16 sizetowrite, const uint16 size, const uint32 StartAddress)
{
    uint8 u8NextMirrorL;

    // set full access
    /* SHAREDIAG_MPU_REGIONS_FUNC(
             SHAREDIAG_MPU_REGION_ENABLE_ACCESS,
             SHAREDIAG_NVM_BLOCK_0_START_ADDRESS,
             SHAREDIAG_BOOTLOADER_PAGES_MPU_REGION_NUM,
             SHAREDIAG_BOOTLOADER_PAGES_MPU_REGION_SIZE,
             TRUE); */

    MemLib_MemSet(&ALLRAMData[StartAddress], SHAREDIAG_ERASED_VALUE, sizetowrite);
    MemLib_MemCpy(&ALLRAMData[StartAddress], pData, size);
    ALLRAMData[StartAddress + size] = 0x00;

    /* Note - if data is present in the current mirror, the write function
     * will erase the data and write the data into the next mirror location */
    //    else if (idle == action.command)
    if ((FALSE == *present) && (idle == action.command))
    {
        u8CurrentMirror = SHAREDIAG_GET_NEXT_MIRROR(u8CurrentMirror);
        u8NextMirrorL = SHAREDIAG_GET_NEXT_MIRROR(u8CurrentMirror);

        action.pAddrToProgram = NVMMirrors[u8CurrentMirror];
        action.Size = SHAREDIAG_NVM_PAGE_SIZE;
        action.pRAMBuff = (uint8 *)&ALLRAMData[0];
        action.speedup = 4; // one write is 4bytes - 4 * 4 = 16bytes speedup
        // erase current page
        action.pAddrToErase = NVMMirrors[u8NextMirrorL];
        action.command = program;
        action.nextcommand = blockErase;
        *present = TRUE;
    }
    else
    {
    }
}
static void DATNvmWriteOneShotValue1(uint8 *const pData, boolean *present, const uint16 sizetowrite, const uint16 size, const uint32 StartAddress)
{
    MemLib_MemSet(&ALLRAMData[StartAddress], SHAREDIAG_ERASED_VALUE, sizetowrite);
    MemLib_MemCpy(&ALLRAMData[StartAddress], pData, size);
    ALLRAMData[StartAddress + size] = 0x00;

    if ((FALSE == *present) && (idle == action.command))
    {
        *present = TRUE;
    }
    else
    {
    }
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------
void ShareDiag_PreInit(void)
{
    uint16 k;
    boolean bBlank = TRUE;
    uint32 u32IndexL;
    uint8 u8NextMirrorL;

    Sec_InitVariables();

    action = action_init;

    /*  SHAREDIAG_MPU_REGIONS_FUNC(
              SHAREDIAG_MPU_REGION_ENABLE_ACCESS,
              SHAREDIAG_SECURITY_MARKER_START_ADDRESS,
              SHAREDIAG_SECURITY_MARKER_MPU_REGION_NUM,
              SHAREDIAG_SECURITY_MARKER_MPU_REGION_SIZE,
              TRUE);


      // Set code execution in TCRAM - size 4K
      SHAREDIAG_MPU_REGIONS_FUNC(
              SHAREDIAG_CODE_EXECUTE_ENABLE_ACCESS,
              SHAREDIAG_CODE_EXECUTE_START_ADDRESS,
              SHAREDIAG_CODE_EXECUTE_MPU_REGION_NUM,
              SHAREDIAG_CODE_EXECUTE_MPU_REGION_SIZE,
              TRUE);
      // set full access to bootloader pages
      SHAREDIAG_MPU_REGIONS_FUNC(
              SHAREDIAG_MPU_REGION_ENABLE_ACCESS,
              SHAREDIAG_NVM_BLOCK_0_START_ADDRESS,
              SHAREDIAG_BOOTLOADER_PAGES_MPU_REGION_NUM,
              SHAREDIAG_BOOTLOADER_PAGES_MPU_REGION_SIZE,
              TRUE);	*/

    u8CurrentMirror = GetCurrentMirror();
    u8NextMirrorL = SHAREDIAG_GET_NEXT_MIRROR(u8CurrentMirror);

    // Copy all NVM data to RAM
    action.pAddrToProgram = (NVMMirrors[u8CurrentMirror]);
    action.Size = SHAREDIAG_NVM_PAGE_SIZE;
    action.pRAMBuff = (uint8 *)&ALLRAMData[0];
    action.command = read;
    action.nextcommand = idle;
    MeetCdd_process();

    for (u32IndexL = 0; (u32IndexL < SHAREDIAG_NVM_PAGE_SIZE) && (bBlank != FALSE); u32IndexL++)
    {
        if (*((uint8 *)(NVMMirrors[u8NextMirrorL] + u32IndexL)) != SHAREDIAG_ERASED_VALUE)
        {
            bBlank = FALSE;
        }
    }

    if ((bBlank == FALSE) || (SHAREDIAG_NVM_FIRST_FLASH(u8CurrentMirror) != FALSE))
    {
        // erase next page
        action.pAddrToErase = NVMMirrors[u8NextMirrorL];
        action.command = blockErase;
        action.nextcommand = idle;
        MeetCdd_process();
    }

    if (SHAREDIAG_NVM_FIRST_FLASH(u8CurrentMirror) != FALSE)
    {
        // Set page valid
        ALLRAMData[0] = 0;

        u8CurrentMirror = SHAREDIAG_GET_NEXT_MIRROR(u8CurrentMirror);
        u8NextMirrorL = SHAREDIAG_GET_NEXT_MIRROR(u8CurrentMirror);

        for (k = 0; k < SHAREDIAG_NVM_PAGE_SIZE; k += SHAREDIAG_GRANULARITY_BYTES)
        {

            action.pAddrToProgram = NVMMirrors[u8CurrentMirror];
            action.Size = SHAREDIAG_NVM_PAGE_SIZE;
            action.pRAMBuff = (uint8 *)&ALLRAMData[0];
            action.speedup = 4; // one write is 4bytes - 4 * 4 = 16bytes speedup
            action.command = program;
            action.nextcommand = idle;
            MeetCdd_process();
        }

        // erase current page
        action.pAddrToErase = NVMMirrors[u8NextMirrorL];
        action.command = blockErase;
        action.nextcommand = idle;
        MeetCdd_process();
    }

    if ((SHAREDIAG_MIRROR_VALID(u8CurrentMirror)) ||
        (SHAREDIAG_MIRROR_VALID(u8NextMirrorL)))
    {
        CheckForBootloaderData = TRUE;
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------
void ShareDiag_Init(void)
{

    u8CurrentMirror = GetCurrentMirror();

    #ifdef SHAREDIAG_SERVICE_ENABLE_1
    // Get data and fill NVMData structure
    DATNvmGetOneShotValue(SHAREDIAG_NVM_ADDRESS_1,
                          SHAREDIAG_REAL_SIZE_1,
                          ShareDiagData_1,
                          &ShareDiagPresent_1);

    DATNvmGetOneShotValue(SHAREDIAG_ADDITIONAL_WRITE_NVM_ADDRESS_1,
                          SHAREDIAG_ADDITIONAL_DATA_REAL_SIZE_1,
                          ShareDiagData_additional_write_1,
                          &ShareDiagPresent_additional_data_1);

    DATNvmGetOneShotValue(SHAREDIAG_ADDITIONAL_WRITE_NVM_ADDRESS_2,
                          SHAREDIAG_ADDITIONAL_DATA_REAL_SIZE_2,
                          ShareDiagData_additional_write_2,
                          &ShareDiagPresent_additional_data_2);
    #endif

    #ifdef SHAREDIAG_SERVICE_ENABLE_2
    // Get data and fill NVMData structure
    DATNvmGetOneShotValue(SHAREDIAG_NVM_ADDRESS_2,
                          SHAREDIAG_REAL_SIZE_2,
                          ShareDiagData_2,
                          &ShareDiagPresent_2);
    #endif
    #ifdef SHAREDIAG_SERVICE_ENABLE_3
    // Get data and fill NVMData structure
    DATNvmGetOneShotValue(SHAREDIAG_NVM_ADDRESS_3,
                          SHAREDIAG_REAL_SIZE_3,
                          ShareDiagData_3,
                          &ShareDiagPresent_3);
    #endif
    #ifdef SHAREDIAG_SERVICE_BOOT_READ
    // Get data and fill NVMData structure
    DATNvmGetOneShotValue(SHAREDIAG_NVM_ADDRESS_BOOT_READ,
                          SHAREDIAG_REAL_SIZE_BOOT_READ,
                          ShareDiagData_boot,
                          &ShareDiagPresent_boot);
    #endif
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------
void MeetCdd_process(void)
{
    uint32 value;
    uint32 speedup = 0;
    sint8 k;
    boolean bResult = TRUE;

    switch (action.command)
    {
    case blockErase:
    {
        if (FALSE != SHAREDIAG_CHECKFLASH_ACCESS_FUNC_CALL())
        {
            SHAREDIAG_FLS_ERASE_FUNC_CALL(action.pAddrToErase);
            action.command = action.nextcommand;
            action.nextcommand = idle;
        }
    }
    break;

    case program:
    {
        if (FALSE != SHAREDIAG_CHECKFLASH_ACCESS_FUNC_CALL())
        {
            bResult = MemLib_MemCmp((uint8 *)Buff_To_Com, (uint8 *)&action.pRAMBuff[0U + word],
                                    SHAREDIAG_GRANULARITY_BYTES);
            if (FALSE == bResult)
            {
                SuspendAllInterrupts();
                SHAREDIAG_TCFLS_WRITE_ENABLE_FUNC_CALL();

                for (speedup = 0; speedup < action.speedup; speedup++)
                {
                    if (word < action.Size)
                    {

                        value = 0;
                        k = 0;

                        for (k = (sint8)3; k >= (sint8)0; k--)
                        {
                            if (word + k >= action.Size)
                            {
                                action.pRAMBuff[word + k] = 0xFF;
                            }

                            value = value << 8;
                            value |= action.pRAMBuff[word + k];
                        }

                        SHAREDIAG_TCFLS_WRITE_FUNC_CALL(value, (action.pAddrToProgram + word));
                        action.command = program;
                    }
                    else
                    {
                        action.command = action.nextcommand;
                        action.nextcommand = idle;
                        word = 0;
                        break;
                    }
                    word += 4U;
                }

                if (word >= action.Size)
                {
                    action.command = action.nextcommand;
                    action.nextcommand = idle;
                    word = 0;
                }

                SHAREDIAG_TCFLS_WRITE_DISABLE_FUNC_CALL();
                ResumeAllInterrupts();
            }
            else
            {
                word += SHAREDIAG_GRANULARITY_BYTES;
                if (word >= action.Size)
                {
                    action.command = action.nextcommand;
                    action.nextcommand = idle;
                    word = 0;
                }
            }
        }
    }
    break;

    case read:
    {
        MemLib_MemCpy((uint32 *)action.pRAMBuff, (uint32 *)action.pAddrToProgram, action.Size);
        action.command = action.nextcommand;
        action.nextcommand = idle;
    }
    break;

    default:
    {
        if (FALSE != IsWriteInBootloadePagesDIDCalled)
        {
            // Privileged/User read-only access to bootloader pages region
            /*                SHAREDIAG_MPU_REGIONS_FUNC(
                                    SHAREDIAG_MPU_REGION_DISABLE_ACCESS,
                                    SHAREDIAG_NVM_BLOCK_0_START_ADDRESS,
                                    SHAREDIAG_BOOTLOADER_PAGES_MPU_REGION_NUM,
                                    SHAREDIAG_BOOTLOADER_PAGES_MPU_REGION_SIZE,
                                    TRUE);
            */
            IsWriteInBootloadePagesDIDCalled = FALSE;
        }
    }
    break;
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------
static void ShareDiag_Get_NVM_JobStatus(uint8 *data)
{
    if (action.command == idle)
    {
        *data = NVM_REQ_OK;
    }
    else
    {
        *data = NVM_REQ_PENDING;
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------
#ifdef SHAREDIAG_SERVICE_ENABLE_1
static void ShareDiag_Read_Data_1(uint8 *Data)
{
    if (ShareDiagPresent_1 == FALSE)
    {
        /* Enable Full access to Bootloader Default Page */
        /* SHAREDIAG_MPU_REGIONS_FUNC(
                 SHAREDIAG_MPU_REGION_ENABLE_ACCESS,
                 SHAREDIAG_ROM_DEFAULT_START_ADDRESS,
                 SHAREDIAG_BOOTLOADER_PAGES_MPU_REGION_NUM,
                 SHAREDIAG_BOOTLOADER_DEFAULT_PAGE_MPU_REGION_SIZE,
                 TRUE);  */

        /* Copy from Nvm to buffer */
        MemLib_MemCpy((uint32 *)Data,
                      (uint32 *)(SHAREDIAG_ROM_DEFAULT_START_ADDRESS + SHAREDIAG_NVM_ADDRESS_1),
                      SHAREDIAG_REAL_SIZE_1);

        /* Disable read-only access to bootloader pages region */
        /*    SHAREDIAG_MPU_REGIONS_FUNC(
                     SHAREDIAG_MPU_REGION_DISABLE_ACCESS,
                     SHAREDIAG_NVM_BLOCK_0_START_ADDRESS,
                     SHAREDIAG_BOOTLOADER_PAGES_MPU_REGION_NUM,
                     SHAREDIAG_BOOTLOADER_PAGES_MPU_REGION_SIZE,
                     TRUE);  */
    }
    else
    {
        MemLib_MemCpy((uint32 *)Data, ShareDiagData_1, SHAREDIAG_REAL_SIZE_1);
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType ShareDiag_Read_Service_1(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ShareDiag_Read_Data_1(Data);
        ret = E_OK;
    }
    else
    {
        *ErrorCode = MGRDIAG_INVALID_MODE;
    }
    return ret;
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------

static void ShareDiag_Write_Additional_Data_1(void)
{
    MemLib_MemCpy(ShareDiagData_additional_write_1, ShareDiagData_1, SHAREDIAG_ADDITIONAL_DATA_REAL_SIZE_1);

    DATNvmWriteOneShotValue1(ShareDiagData_additional_write_1,
                             &ShareDiagPresent_additional_data_1,
                             SHAREDIAG_ADDITIONAL_DATA_SIZE_1,
                             SHAREDIAG_ADDITIONAL_DATA_REAL_SIZE_1,
                             SHAREDIAG_ADDITIONAL_WRITE_NVM_ADDRESS_1);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------

static void ShareDiag_Write_Additional_Data_2(void)
{
    MemLib_MemCpy(ShareDiagData_additional_write_2, ShareDiagData_1, SHAREDIAG_ADDITIONAL_DATA_REAL_SIZE_2);

    DATNvmWriteOneShotValue1(ShareDiagData_additional_write_2,
                             &ShareDiagPresent_additional_data_2,
                             SHAREDIAG_ADDITIONAL_DATA_SIZE_2,
                             SHAREDIAG_ADDITIONAL_DATA_REAL_SIZE_2,
                             SHAREDIAG_ADDITIONAL_WRITE_NVM_ADDRESS_2);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType ShareDiag_Write_Data_1(uint8 *Data)
{
    Std_ReturnType ret = E_NOT_OK;
    boolean bResult = FALSE;
    argumentBuffer_p var = (argumentBuffer_t *)&action;

    if ((idle == var->command) && (FALSE != CheckForBootloaderData))
    {
        if (FALSE == ShareDiagPresent_1)
        {
            MemLib_MemCpy((uint32 *)ShareDiagData_1, (uint32 *)Data, SHAREDIAG_REAL_SIZE_1);
            ShareDiag_Write_Additional_Data_1();
            ShareDiag_Write_Additional_Data_2();
            DATNvmWriteOneShotValue(ShareDiagData_1,
                                    &ShareDiagPresent_1,
                                    SHAREDIAG_SIZE_1,
                                    SHAREDIAG_REAL_SIZE_1,
                                    SHAREDIAG_NVM_ADDRESS_1);

            IsWriteInBootloadePagesDIDCalled = TRUE;
            ret = E_OK;
        }
        else
        {
            bResult = MemLib_MemCmp(Data, ShareDiagData_1, SHAREDIAG_REAL_SIZE_1);
            if (FALSE != bResult)
            {
                ret = E_OK;
            }
            else
            {
                #ifdef SHAREDIAG_ONE_TIME_WRITE_1
                ret = E_NOT_OK;
                Data[0] = DCM_E_CONDITIONSNOTCORRECT;
                #else
                MemLib_MemCpy((uint32 *)ShareDiagData_1, (uint32 *)Data, SHAREDIAG_REAL_SIZE_1);
                DATNvmWriteOneShotValue(ShareDiagData_1,
                                        &ShareDiagPresent_1,
                                        SHAREDIAG_SIZE_1,
                                        SHAREDIAG_REAL_SIZE_1,
                                        SHAREDIAG_NVM_ADDRESS_1);

                IsWriteInBootloadePagesDIDCalled = TRUE;
                ret = E_OK;
                #endif
            }
        }
    }
    else
    {
        ret = E_OK; /* Calling function will return PENDING */
    }
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType ShareDiag_Write_Service_1(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        switch (ShareDiag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            ret = ShareDiag_Write_Data_1(Data);
            if (E_OK == ret)
            {
                ret = DCM_E_PENDING;
                ShareDiag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                ret = E_NOT_OK;
            }
            break;
        case eNVMWrite_WaitForResponse:
            ShareDiag_Get_NVM_JobStatus(&JobResult);
            if (JobResult == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else /*if(JobResult == NVM_REQ_OK)*/
            {
                ShareDiag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = E_OK;
            }
            /*
            else
            {
                ShareDiag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = E_NOT_OK;
                *ErrorCode = MGRDIAG_INVALID_MODE;
            }*/
            break;
        default:
            ret = E_NOT_OK;
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            ShareDiag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
            break;
        }
    }
    else
    {
        *ErrorCode = MGRDIAG_INVALID_MODE;
    }
    return ret;
}

#endif /*SHAREDIAG_SERVICE_ENABLE_1 */

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------
#ifdef SHAREDIAG_SERVICE_ENABLE_2
static void ShareDiag_Read_Data_2(uint8 *Data)
{
    if (ShareDiagPresent_2 == FALSE)
    {
        /* Enable Full access to Bootloader Default Page */
        /*    SHAREDIAG_MPU_REGIONS_FUNC(
                    SHAREDIAG_MPU_REGION_ENABLE_ACCESS,
                    SHAREDIAG_ROM_DEFAULT_START_ADDRESS,
                    SHAREDIAG_BOOTLOADER_PAGES_MPU_REGION_NUM,
                    SHAREDIAG_BOOTLOADER_DEFAULT_PAGE_MPU_REGION_SIZE,
                    TRUE);  */

        /* Copy from Nvm to buffer */
        MemLib_MemCpy((uint32 *)Data,
                      (uint32 *)(SHAREDIAG_ROM_DEFAULT_START_ADDRESS + SHAREDIAG_NVM_ADDRESS_2),
                      SHAREDIAG_REAL_SIZE_2);

        // Privileged/User read-only access to bootloader pages region
        /*  SHAREDIAG_MPU_REGIONS_FUNC(
                   SHAREDIAG_MPU_REGION_DISABLE_ACCESS,
                   SHAREDIAG_NVM_BLOCK_0_START_ADDRESS,
                   SHAREDIAG_BOOTLOADER_PAGES_MPU_REGION_NUM,
                   SHAREDIAG_BOOTLOADER_PAGES_MPU_REGION_SIZE,
                   TRUE);  */
    }
    else
    {
        MemLib_MemCpy((uint32 *)Data, ShareDiagData_2, SHAREDIAG_REAL_SIZE_2);
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------

Std_ReturnType ShareDiag_Read_Service_2(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ShareDiag_Read_Data_2(Data);
        ret = E_OK;
    }
    else
    {
        *ErrorCode = MGRDIAG_INVALID_MODE;
    }
    return ret;
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType ShareDiag_Write_Data_2(uint8 *Data)
{
    Std_ReturnType ret = E_NOT_OK;
    boolean bResult = FALSE;
    argumentBuffer_p var = (argumentBuffer_t *)&action;

    if (idle == var->command)
    {
        if (FALSE == ShareDiagPresent_2)
        {
            MemLib_MemCpy((uint32 *)ShareDiagData_2, (uint32 *)Data, SHAREDIAG_REAL_SIZE_2);
            DATNvmWriteOneShotValue(ShareDiagData_2,
                                    &ShareDiagPresent_2,
                                    SHAREDIAG_SIZE_2,
                                    SHAREDIAG_REAL_SIZE_2,
                                    SHAREDIAG_NVM_ADDRESS_2);

            IsWriteInBootloadePagesDIDCalled = TRUE;
            ret = E_OK;
        }
        else
        {
            bResult = MemLib_MemCmp(Data, ShareDiagData_2, SHAREDIAG_REAL_SIZE_2);
            if (FALSE != bResult)
            {
                ret = E_OK;
            }
            else
            {
                #ifdef SHAREDIAG_ONE_TIME_WRITE_2
                ret = E_NOT_OK;
                Data[0] = DCM_E_CONDITIONSNOTCORRECT;
                #else
                MemLib_MemCpy((uint32 *)ShareDiagData_2, (uint32 *)Data, SHAREDIAG_REAL_SIZE_2);
                DATNvmWriteOneShotValue(ShareDiagData_2,
                                        &ShareDiagPresent_2,
                                        SHAREDIAG_SIZE_2,
                                        SHAREDIAG_REAL_SIZE_2,
                                        SHAREDIAG_NVM_ADDRESS_2);

                IsWriteInBootloadePagesDIDCalled = TRUE;
                ret = E_OK;
                #endif
            }
        }
    }
    else
    {
        ret = E_OK; /* Calling function will return PENDING */
    }
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType ShareDiag_Write_Service_2(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        switch (ShareDiag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            ret = ShareDiag_Write_Data_2(Data);
            if (E_OK == ret)
            {
                ret = DCM_E_PENDING;
                ShareDiag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = Data[0];
                ret = DCM_E_NOT_OK;
            }
            break;
        case eNVMWrite_WaitForResponse:
            ShareDiag_Get_NVM_JobStatus(&JobResult);
            if (JobResult == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else /*if(JobResult == NVM_REQ_OK)*/
            {
                ShareDiag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            /* else
             {
                 ShareDiag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                 ret = DCM_E_NOT_OK;
                 *ErrorCode = MGRDIAG_INVALID_MODE;
             }*/
            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = MGRDIAG_INVALID_MODE;
    }
    return ret;
}
#endif /*SHAREDIAG_SERVICE_ENABLE_2 */

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------
#ifdef SHAREDIAG_SERVICE_ENABLE_3
static void ShareDiag_Read_Data_3(uint8 *Data)
{
    if (ShareDiagPresent_3 == FALSE)
    {
        /* Enable Full access to Bootloader Default Page */
        /*  SHAREDIAG_MPU_REGIONS_FUNC(
                  SHAREDIAG_MPU_REGION_ENABLE_ACCESS,
                  SHAREDIAG_ROM_DEFAULT_START_ADDRESS,
                  SHAREDIAG_BOOTLOADER_PAGES_MPU_REGION_NUM,
                  SHAREDIAG_BOOTLOADER_DEFAULT_PAGE_MPU_REGION_SIZE,
                  TRUE);  */

        /* Copy from Nvm to buffer */
        MemLib_MemCpy((uint32 *)Data,
                      (uint32 *)(SHAREDIAG_ROM_DEFAULT_START_ADDRESS + SHAREDIAG_NVM_ADDRESS_3),
                      SHAREDIAG_REAL_SIZE_3);

        // Privileged/User read-only access to bootloader pages region
        /*  SHAREDIAG_MPU_REGIONS_FUNC(
                   SHAREDIAG_MPU_REGION_DISABLE_ACCESS,
                   SHAREDIAG_NVM_BLOCK_0_START_ADDRESS,
                   SHAREDIAG_BOOTLOADER_PAGES_MPU_REGION_NUM,
                   SHAREDIAG_BOOTLOADER_PAGES_MPU_REGION_SIZE,
                   TRUE);  */
    }
    else
    {
        MemLib_MemCpy((uint32 *)Data, (uint32 *)ShareDiagData_3, SHAREDIAG_REAL_SIZE_3);
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType ShareDiag_Read_Service_3(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ShareDiag_Read_Data_3(Data);
        ret = E_OK;
    }
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType ShareDiag_Write_Data_3(uint8 *Data)
{
    Std_ReturnType ret = E_NOT_OK;
    boolean bResult = FALSE;
    argumentBuffer_p var = (argumentBuffer_t *)&action;

    if (idle == var->command)
    {
        if (FALSE == ShareDiagPresent_3)
        {
            MemLib_MemCpy((uint32 *)ShareDiagData_3, (uint32 *)Data, SHAREDIAG_REAL_SIZE_3);
            DATNvmWriteOneShotValue(ShareDiagData_3,
                                    &ShareDiagPresent_3,
                                    SHAREDIAG_SIZE_3,
                                    SHAREDIAG_REAL_SIZE_3,
                                    SHAREDIAG_NVM_ADDRESS_3);

            IsWriteInBootloadePagesDIDCalled = TRUE;
            ret = E_OK;
        }
        else
        {
            bResult = MemLib_MemCmp(Data, ShareDiagData_3, SHAREDIAG_REAL_SIZE_3);
            if (FALSE != bResult)
            {
                ret = E_OK;
            }
            else
            {
                #ifdef SHAREDIAG_ONE_TIME_WRITE_3
                ret = E_NOT_OK;
                Data[0] = DCM_E_CONDITIONSNOTCORRECT;
                #else
                MemLib_MemCpy((uint32 *)ShareDiagData_3, (uint32 *)Data, SHAREDIAG_REAL_SIZE_3);
                DATNvmWriteOneShotValue(ShareDiagData_3,
                                        &ShareDiagPresent_3,
                                        SHAREDIAG_SIZE_3,
                                        SHAREDIAG_REAL_SIZE_3,
                                        SHAREDIAG_NVM_ADDRESS_3);

                IsWriteInBootloadePagesDIDCalled = TRUE;
                ret = E_OK;
                #endif
            }
        }
    }
    else
    {
        ret = E_OK; /* Calling function will return PENDING */
    }
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType ShareDiag_Write_Service_3(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        switch (ShareDiag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            ret = ShareDiag_Write_Data_3(Data);
            if (E_OK == ret)
            {
                ret = DCM_E_PENDING;
                ShareDiag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = Data[0];
            }
            break;
        case eNVMWrite_WaitForResponse:
            ShareDiag_Get_NVM_JobStatus(&JobResult);
            if (JobResult == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else /*if(JobResult == NVM_REQ_OK)*/
            {
                ShareDiag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            /*else
            {
                ShareDiag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = MGRDIAG_INVALID_MODE;
            } */
            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = MGRDIAG_INVALID_MODE;
    }
    return ret;
}
#endif /*SHAREDIAG_SERVICE_ENABLE_3 */

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///< br>
//---------------------------------------------------------------------------------------------------------------------

#ifdef SHAREDIAG_SERVICE_BOOT_READ
void Shareddiag_ReadBootVersion(uint8 *pBuffer)
{
    if (ShareDiagPresent_boot == FALSE)
    {
        MemLib_MemCpy(pBuffer,
                      (uint32 *)(SHAREDIAG_ROM_DEFAULT_START_ADDRESS + SHAREDIAG_NVM_ADDRESS_BOOT_READ),
                      SHAREDIAG_REAL_SIZE_BOOT_READ);
    }
    else
    {
        MemLib_MemCpy(pBuffer, (uint32 *)ShareDiagData_boot, SHAREDIAG_REAL_SIZE_BOOT_READ);
    }
}
#endif
/*=====================================================================================================================
** Date              :  04/08/2020
** CDSID             :  razhakes
** Traceability      :  RTC 880207
** Change Description: Instead of making whole MeetcddProcess() as Trusted , only inside functions are made trusted
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/09/2023
** CDSID             :  mprajapa
** Traceability      :  JIRA 3839
** Change Description:  Upddated identation.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/07/2020
** CDSID             :  dkasiman and Vela
** Traceability      :  RTC 969188
** Change Description: Additional write while F0 $12 write service triggered.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/Mar/2020
** CDSID             :  dkasiman
** Traceability      :  RTC-811699
** Change Description:  MPU region related functions are commented
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/01/2020
** CDSID             :  dkasiman
** Traceability      :  RTC 1380314
** Change Description:  Coverity/Misra fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  18/Sept/2019
** CDSID             :  razhakes
** Traceability      :  RTC-1370043
** Change Description:  Call_MeetcddProcess() redefined as a MACRO MEETCDD_PROCESS_FUNC_CALL()
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  17/05/2019
** CDSID             :  dkasiman
** Traceability      :  RTC 1310401
** Change Description:  Uncovered VCAST code removed.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 05/Apr/2019
** CDSID             : dkasiman
** Traceability      : RTC 1308973
** Change Description: Shared memory service 1 updated to support to write in additional location
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  27/Mar/2019
** CDSID             :  MGANAPAT
** Traceability      :  RTC 1303833
** Change Description: Read boot version function added
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :
** CDSID             :
** Traceability      :
** Change Description: Initial version for MeetCdd bookshelf - Shared Boot
**====================================================================================================================*/
#endif
