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
** Name:           Cybersecdiagcdd.c
**
** Description:    contains memory related services.checks if software in Manufacturing mode before executing service request
**
**
**===================================================================================================================*/

#ifndef CYBERSECDIAGCDD_C
#define CYBERSECDIAGCDD_C

/*====================================================================================================================
**  I N C L U D E   F I L E S
**===================================================================================================================*/

#include "Cybersecdiagcdd.h"
#include "Cybersecdiagcdd_cfg.h"

#ifdef CYBERSECDIAGCDD_ADAPTER
#include "Rte_MeetCdd.h" /* Equivalent to Rte_CMeetCdd.h in Mazda J30 program */
#include "Meet_Common.h" /* Equivalent to Mgrdiagcdd.h in Mazda J30 program */
#else
#include "Mgrdiagcdd_cfg.h"
#include "Mgrdiagcdd.h"
#endif

#include "MemLib.h"

#ifdef CYBERSECDIAG_FLS_ENABLE
#include "Fls.h"
#endif

#ifdef SHAREDIAG_SERVICE_ENABLE_3
#include "SharedBootDiagcdd.h"
#endif

#ifdef CYBERSECDIAG_VISTEONOBFUCATELIB_ENABLE
#include "VisteonObfuscateLib.h"
#endif

/*====================================================================================================================
**   I N T E R N A L   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/

/*=====================================================================================================================
**  T Y P E    D E C L A R A T I O N S
**====================================================================================================================*/

/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/

/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/
#ifdef CRYPTO_KEY_MANAGEMENT
static uint16 Crc_StartValue16 = 0xFFFFu; /* EXP37-C CERT FIX - Changed type of Crc_StartValue16 from uint32 to uint16 */
#endif

#if (defined(CYBERSECDIAG_FLS_ENABLE) || defined(CYBERSECDIAG_SECURE_KEY_WRITE_AES_IV) || defined(CYBERSECDIAG_SECURE_KEY_WRITE_RSA))
Key_StatusType Key_Fls_Write_Status;
uint8 Cybersecdiag_AES_IV_Key_RCStatus = 0U; // i.e.eROUTINE_INACTIVE
uint8 Cybersecdiag_RSA_Key_RCStatus = 0U;	 // i.e.eROUTINE_INACTIVE

static void Cybersecdiag_Fls_SectorCheck(Key_Sector_Struct *Key, const uint32 PAddress, Key_PayLoad_Struct *PayLoad);
static void Cybersecdiag_Fls_Process(Key_Sector_Struct *Key, const uint32 PAddress, Key_PayLoad_Struct *PayLoad);
#endif

#ifdef CYBERSECDIAG_SECURE_KEY_PROGRAMMING_RSA
#ifndef CRYPTO_KEY_MANAGEMENT_IMX8
static uint8 RSA_Key_ID;
static uint8 RSA_Key_array[RSA_key_DATA_PAYLOAD] = {0U};
#endif
static uint8 Cybersecdiag_RSA_ASymmetricStatus;
#endif

#ifdef CYBERSECDIAG_SECURE_KEY_PROGRAMMING_AES_IV
#ifndef CRYPTO_KEY_MANAGEMENT_IMX8
static uint8 AES_IV_Key_ID;
static uint8 AES_IV_Key_array[AES_IV_SINGLE_Key_ACTUAL_DATA_SIZE] = {0U};
#endif
static uint8 Cybersecdiag_IV_SecureSymmetricStatus;
#endif

#if (defined(CRYPTO_KEY_MANAGEMENT_IMX8) && defined(CYBERSECDIAG_CRYPTO_KEY_VERIFICATION))
static uint8 Cybersecdiag_KEY_VerificationStatus;
#endif

#if (defined(CYBERSECDIAG_BACKUPBANK_VERIFICATION_ONLY_CMAC) || defined(CYBERSECDIAG_BACKUPBANK_VERIFICATION))
static uint8 Cybersecdiag_Backup_bankVerificationStatus;
#endif

#ifdef CYBERSECDIAG_SECURE_KEY_PROGRAMMING_AES
static uint8 Cybersecdiag_AES_SecureSymmetricStatus;
#endif

#ifdef CYBERSECDIAG_FLS_ENABLE
#ifdef __ghs__
#pragma alignvar(8)
#endif

static uint8 GlHeader[HeaderOffset];

#ifdef __ghs__
#pragma alignvar(8)
#endif

static uint8 GlFooter[FooterOffset];

#if (defined(CYBERSECDIAG_FLS_ENABLE) || defined(CYBERSECDIAG_SECURE_KEY_PROGRAMMING_AES_IV))
static const uint32 AES_IV_Key_PAddress = AES_IV_KEY_WFLASH_OFFSET;

#ifdef __ghs__
#pragma alignvar(8)
#endif

static uint8 AES_IV_Key_TOTAL_Ram_Buffer[AES_IV_TOTAL_Key_DATA_PAYLOAD] = {0U};
#endif

#if (defined(CYBERSECDIAG_FLS_ENABLE) || defined(CYBERSECDIAG_SECURE_KEY_PROGRAMMING_RSA))
static const uint32 RSA_Key_PAddress = RSA_KEY_WFLASH_OFFSET;

#ifdef __ghs__
#pragma alignvar(8)
#endif

static uint8 RSA_Key_Ram_Buffer[RSA_key_DATA_PAYLOAD] = {0U};
#endif
#endif

#ifdef CYBERSECDIAG_SECURE_KEY_WRITE_AES_IV
static uint8 AES_IV_SINGLE_Key_Ram_Buffer[AES_IV_SINGLE_Key_DATA_PAYLOAD] = {0U};
static uint16 AES_IV_Total_Key_length = AES_IV_TOTAL_Key_DATA_PAYLOAD;
#endif

#if (defined(CYBERSECDIAG_SECURE_KEY_WRITE_AES_IV) || defined(CYBERSECDIAG_SECURE_KEY_PROGRAMMING_AES_IV))
#ifndef CRYPTO_KEY_MANAGEMENT_IMX8
static uint32 AES_IV_Single_Key_length = AES_IV_SINGLE_Key_DATA_PAYLOAD; /* EXP37-C CERT FIX - Changed type of AES_IV_Single_Key_length from uint16 to uint32 */
#endif
#endif

#if (defined(CYBERSECDIAG_SECURE_KEY_PROGRAMMING_SHE) || defined(CYBERSECDIAG_SECURE_KEY_PROGRAMMING_AES))
uint8 Cybersecdiag_AES_Key_RCStatus = 0U; // i.e.eROUTINE_INACTIVE

#ifdef CRYPTO_KEY_SHE
static uint8 AES_Key_RCStart_Flag = 0u;
static uint8 AES_Key_array_M1M2M3[CYBERSECDIAG_AES_M1M2M3_SIZE];
static e_Cybersecdiag_SHE_StateMachine e_Cybersecdiag_SHE_State = e_Cybersecdiag_SHE_Idle;
static Std_ReturnType Cybersecdiag_SHE_response[e_Cybersecdiag_SHE_MaxStates] = {E_OK, E_NOT_OK, E_NOT_OK, E_NOT_OK, E_NOT_OK, E_NOT_OK, E_NOT_OK, E_NOT_OK};

/** Type for default call-backs in order to record their calling **/
typedef struct s_Cybersecdiag_Callback
{
    uint32 CbkCount; /* count the number callback notifications */
} ts_CybersecdiagCallback;

/* Collection of all default callback data */
typedef struct s_Cybersecdiag_Callbacks
{
    ts_CybersecdiagCallback SymKeyExtract;
} ts_CybersecdiagCallbacks;

ts_CybersecdiagCallbacks stcCsmCbk;

static uint32 Cybersecdiag_SHE_Timeout = 0U;
static uint8 Cybersecdiag_SHE_M4_M5_MSG[48];
static uint32 Cybersecdiag_SHE_M4_M5_LEN = 48U;
static CSM_SymKeyType Cybersecdiag_SHE_KeyHandler;
#endif

#ifdef CRYPTO_KEY_SHE_DECRYPTION
static uint8 AES_Enc_Key_array[SHE_ENC_AES_KEY_SIZE];
static uint8 AES_Key_array_M4M5[CYBERSECDIAG_AES_M4M5_SIZE];
#endif
#endif

#ifdef CYBERSECDIAG_SECURE_KEY_PROGRAMMING_AES
#ifndef CRYPTO_KEY_MANAGEMENT_IMX8
static uint8 AES_Key_array[AES_KEY_SIZE];
#endif
uint8 Key_length;
uint8 Csm_AES_Key_Status = 0U;
#endif

#ifdef CYBERSECDIAG_JTAG_PASSWORD_ROUTINE_LOCK_ENABLE
static eRoutineStatus Cybersecdiag_JtagPswdLock_RCStatus = eROUTINE_INACTIVE;
#endif

#if defined(CYBERSECDIAG_JTAG_LOCK_ENABLE)
#ifndef CRYPTO_KEY_MANAGEMENT_IMX8
uint8 JTAG_ENC_BUFF[JTAG_ENC_PASSWORD_SIZE] = {0U};
uint8 JTAG_DEC_BUFF[JTAG_DEC_PASSWORD_SIZE] = {0U};
static boolean JTAG_WRITE_INITIATED = FALSE;
#endif
#endif

#ifdef CYBERSECDIAG_CRYPTO_KEY_VERIFICATION
#ifdef CYBERSECDIAGCDD_ADAPTER
eRoutineStatus2 Cybersecdiag_CyberSecKeyVerify_RCStatus = eROUTINE_INACTIVE;
#else
eRoutineStatus Cybersecdiag_CyberSecKeyVerify_RCStatus = eROUTINE_INACTIVE;
#endif

#ifndef CRYPTO_KEY_MANAGEMENT_IMX8
static uint8 Cybersecurity_Key_Status = 0u;
static uint8 AES_IV_WF_DefaultData[AES_IV_TOTAL_Key_DATA_PAYLOAD];
static uint8 RSA_key_WF_DefaultData[RSA_key_DATA_PAYLOAD];
#endif

typedef enum
{
    ENCRYPTION,
    ENCRYPTION_WAIT,
    DECRYPTION,
    DECRYPTION_WAIT,
    COMPARE,
    AES_VERIFICATION_IDLE
} ESysAES_VerificationState;
typedef enum
{
    INACTIVE,
    ACTIVE
} ESysAES_VerificationStatus;

/*for Cybersecurity key verification*/
ESysAES_VerificationState AES_VerificationState = AES_VERIFICATION_IDLE;
ESysAES_VerificationStatus AES_VerificationStatus = INACTIVE;

#ifndef CRYPTO_KEY_MANAGEMENT_IMX8
static uint8 SampleInputbuffer[AES_KEY_VERIFY_SAMPLE_INPUT_LENGTH];
static uint8 SampleEncResult[AES_KEY_VERIFY_SAMPLE_INPUT_LENGTH];
static uint8 SampleDecResult[AES_KEY_VERIFY_SAMPLE_INPUT_LENGTH];
static uint32 SampleInpBuffLength = AES_KEY_VERIFY_SAMPLE_INPUT_LENGTH;
static uint32 SampleEncResultLen = AES_KEY_VERIFY_SAMPLE_INPUT_LENGTH;
static uint32 SampleDecResultLen = AES_KEY_VERIFY_SAMPLE_INPUT_LENGTH;
static uint8 Valid_AES_Key_idx = 0;
static uint8 AES_Key_ID;
static boolean IsCMAC = FALSE;
#endif
const uint8 SampleEncBuff[16] = {138u, 87u, 245u, 137u, 198u, 120u, 230u, 138u, 135u, 16u, 166u, 211u, 62u, 138u, 182u, 17u}; // encrypted value of 16 0xFF's

#ifdef CRYPTO_KEY_VERIFICATION_GIP
#ifndef CRYPTO_KEY_MANAGEMENT_IMX8
static boolean GIP_KeyVerify_STATUS_IS_PENDING = FALSE;
#endif
#endif
#endif

#ifdef CYBERSECDIAG_ENCRYPT_DECRYPT_NOTIFYHANDLER
static uint8 Encrypt_status = ENCRYPTION_DEFAULT;
static uint8 Decrypt_status = DECRYPTION_DEFAULT;
#endif

#if (defined(CYBERSECDIAG_BACKUPBANK_VERIFICATION_ONLY_CMAC) || defined(CYBERSECDIAG_BACKUPBANK_VERIFICATION))
typedef enum
{
    DECRYPT_HYPERFLASH_DATA,
    COMPARE_WITH_INTERNALFLASH,
    IDLE
} ESysbackUpBankState;

/*Below are for backup bank verification*/
ESysbackUpBankState BackUpBankVerify_State = IDLE;
eRoutineStatus Cybersecdiag_BackupBankVerif_RCStatus = eROUTINE_INACTIVE;

#ifndef CRYPTO_KEY_MANAGEMENT_IMX8
static uint32 Current_Hyperflash_StartAddr = HYPERFLASH_FOTA_START_ADDRESS;
static uint32 Current_InternalFlash_StartAddr = INTERNALFLASH_FOTA_START_ADDRESS;
static uint8 DecResult[512];
#endif

#endif

#ifdef CYBERSECDIAG_SYMMETRIC_KEY_PROGRAMMING
eRoutineStatus Cybersecdiag_GIPSymmetricKey_RCStatus = eROUTINE_INACTIVE; // i.e.eROUTINE_INACTIVE
#endif

#ifdef CYBERSECDIAG_SECURE_SYMMETRIC_KEY_PROGRAMMING
static eRoutineStatus Cybersecdiag_SecureSymmetricKey_RCStatus = eROUTINE_INACTIVE;
#endif

#ifdef CYBERSECDIAG_SYMMETRIC_KEY_VERIFICATION
static eRoutineStatus Cybersecdiag_SymmetricKeyVerfication_RCStatus = eROUTINE_INACTIVE;
#endif

#ifdef CYBERSECDIAG_SECURE_FUSE_PROGRAMMING
eRoutineStatus Cybersecdiag_SecureLockProgramming_RCStatus = eROUTINE_INACTIVE;
#endif

#if (defined(CYBERSECDIAG_BACKUPBANK_VERIFICATION_ONLY_CMAC) || defined(CYBERSECDIAG_BACKUPBANK_VERIFICATION))
#ifndef CRYPTO_KEY_MANAGEMENT_IMX8
static uint8 IVectorData[16];
static uint8 Encbuffer[512];
#endif
#endif

#ifdef CYBERSECDIAG_BACKUPBANK_VERIFICATION
#ifndef CRYPTO_KEY_MANAGEMENT_IMX8
static uint32 DecLength = PERIODIC_DECRYPT_LENGTH;
static uint32 DecResultLen = PERIODIC_DECRYPT_LENGTH;
static uint16 BackUpBankPeriodic_TotalCount = (uint16)(TOTAL_APPL_SIZE / PERIODIC_DECRYPT_LENGTH);
static uint16 BackUpBankPeriodic_CurrentCount = 0u;
#endif
#endif

#ifdef CYBERSECDIAG_BACKUPBANK_VERIFICATION_ONLY_CMAC
static uint32 DecCMAC_Length = PERIODIC_DECRYPT_CMAC_LENGTH;
static uint32 DecResultLen_OnlyCMAC = PERIODIC_DECRYPT_CMAC_LENGTH;
#endif

#ifdef CYBERSECDIAG_CSM_SAFE_KEY_NUMBER
static CyberSecKeyElementWriteStateType Cybersecdiag_KeyElementWriteState = eKeyElementSet_Request;
#endif

#ifdef CYBERSECDIAG_JTAG_PASSWORD_WRITE_LOCK_ENABLE
static CyberSecJatgPasswordStateType Cybersecdiag_JtagPasswordState = eJtag_VerfitySafeKeyNum;
#endif

#ifdef CYBERSECDIAG_FLS_ENABLE
//---------------------------------------------------------------------------------------------------------------------
/// @brief Cybersecdiag_Fls_Init
///
/// @arg  uint8 * PBuffer
///
/// @return Std_ReturnType
///< br>
//---------------------------------------------------------------------------------------------------------------------

void Cybersecdiag_Fls_Init(void)
{
    AES_IV_Key.Action = Idle;
    AES_IV_key_PayLoad.RamBuffer = (uint8 *)AES_IV_Key_TOTAL_Ram_Buffer;
    AES_IV_key_PayLoad.Length = AES_IV_TOTAL_Key_DATA_PAYLOAD;

    RSA_Key.Action = Idle;
    RSA_key_PayLoad.RamBuffer = (uint8 *)RSA_Key_Ram_Buffer;
    RSA_key_PayLoad.Length = RSA_key_DATA_PAYLOAD;

    Cybersecdiag_Fls_SectorCheck(&AES_IV_Key, AES_IV_Key_PAddress, &AES_IV_key_PayLoad); // need to call this function 3 times for 3 offset
    Cybersecdiag_Fls_SectorCheck(&RSA_Key, RSA_Key_PAddress, &RSA_key_PayLoad);

    Key_Fls_Write_Status = Init;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief Cybersecdiag_Fls_SectorCheck
///
/// This function will check the validity of Sector
///
/// @arg  uint8 * PBuffer
///
/// @return Std_ReturnType
///< br>
//---------------------------------------------------------------------------------------------------------------------
static void Cybersecdiag_Fls_SectorCheck(Key_Sector_Struct *Key, const uint32 PAddress, Key_PayLoad_Struct *PayLoad)
{
    uint8 Index;
    Key->SectorStatus = Erased;
    for (Index = 0; Index < Key_MaxLimit; Index++)
    {
        if (*((uint8 *)PAddress + Index) != WorkFlash_ErasedValue)
        {
            Key->SectorStatus = Undefined;
            break;
        }
    }
    // Check the sector if it is not in erased state, for valid data.
    if (Key->SectorStatus == Undefined)
    {
        (void)MemLib_MemCpy(GlHeader, (uint8 *)PAddress, HeaderOffset);
        (void)MemLib_MemCpy(GlFooter, (uint8 *)(PAddress + PayLoad->Length + HeaderOffset), HeaderOffset);
        Key->SectorStatus = Corrupted;
        if ((GlHeader[0] == (uint8)(Key_WorkFlash_Header & (uint8)0xffu)) && (GlHeader[1] == (uint8)((Key_WorkFlash_Header >> (uint8)8u) & (uint8)0xffu)))
        {
            if ((GlFooter[0] == (uint8)(Key_WorkFlash_Footer & (uint8)0xffu)) && (GlFooter[1] == (uint8)((Key_WorkFlash_Footer >> (uint8)8u) & (uint8)0xffu)))
            {
                Key->SectorStatus = Valid;
            }
        }
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief Cybersecdiag_Fls_MainFunction
///
/// @arg  uint8 * PBuffer
///
/// @return Std_ReturnType
///< br>
//---------------------------------------------------------------------------------------------------------------------
void Cybersecdiag_Fls_MainFunction(void)
{
    if (Key_Fls_Write_Status != UnInit)
    {
        Cybersecdiag_Fls_Process(&AES_IV_Key, AES_IV_Key_PAddress, &AES_IV_key_PayLoad);
        Cybersecdiag_Fls_Process(&RSA_Key, RSA_Key_PAddress, &RSA_key_PayLoad);
    }
}

static void Cybersecdiag_Fls_Process(Key_Sector_Struct *Key, const uint32 PAddress, Key_PayLoad_Struct *PayLoad)
{

    MemIf_StatusType MemIf_Status;
    MemIf_JobResultType MemIf_JobResult;

    switch (Key->Action)
    {

    case Idle:
        break;

    case Erase:
        MemIf_Status = Fls_GetStatus();
        if (MEMIF_IDLE == MemIf_Status)
        {
            if (Key->SectorStatus != Erased)
            {
                if (E_OK == Fls_Erase((uint32)(PAddress & SECTOR_ADDRESS_OFFSET_MASK), SECTOR_SIZE))
                {
                    Key->Action = Erase_Wait;
                }
            }
            else
            {
                GlHeader[0] = (Key_WorkFlash_Header & (uint8)0xffu);
                GlHeader[1] = ((Key_WorkFlash_Header >> (uint8)8u) & (uint8)0xffu);
                Key->Action = Program_Header;
            }
        }
        break;

    case Erase_Wait:
        MemIf_JobResult = Fls_GetJobResult();
        if (MEMIF_JOB_PENDING != MemIf_JobResult)
        {
            if (MEMIF_JOB_OK == MemIf_JobResult)
            {
                Cybersecdiag_Fls_SectorCheck(Key, PAddress, PayLoad);
                Key->Action = Erase;
            }
            else
            {
                Cybersecdiag_Fls_SectorCheck(Key, PAddress, PayLoad);
                Key_Fls_Write_Status = Failiure;
                Key->Action = Idle;
            }
        }
        break;

    case Program_Header:
        MemIf_Status = Fls_GetStatus();
        if (MEMIF_IDLE == MemIf_Status)
        {
            if (E_OK == Fls_Write(((uint32)(PAddress & SECTOR_ADDRESS_OFFSET_MASK)), (uint8 *)&GlHeader[0], HeaderOffset))
            {
                Key->Action = Program_Header_Wait;
            }
        }
        break;

    case Program_Header_Wait:
        MemIf_JobResult = Fls_GetJobResult();
        if (MEMIF_JOB_PENDING != MemIf_JobResult)
        {
            if (MEMIF_JOB_OK == MemIf_JobResult)
            {
                Key->Action = Program_PayLoad;
            }
            else
            {
                Cybersecdiag_Fls_SectorCheck(Key, PAddress, PayLoad);
                Key_Fls_Write_Status = Failiure;
                Key->Action = Idle;
            }
        }
        break;

    case Program_PayLoad:
        MemIf_Status = Fls_GetStatus();
        if (MEMIF_IDLE == MemIf_Status)
        {
            if (E_OK == Fls_Write(((uint32)(PAddress & SECTOR_ADDRESS_OFFSET_MASK) + HeaderOffset),
                                  (uint8 *)PayLoad->RamBuffer, PayLoad->Length))
            {
                Key->Action = Program_PayLoad_Wait;
            }
        }
        break;

    case Program_PayLoad_Wait:
        MemIf_JobResult = Fls_GetJobResult();
        if (MEMIF_JOB_PENDING != MemIf_JobResult)
        {
            if (MEMIF_JOB_OK == MemIf_JobResult)
            {
                GlFooter[0] = (Key_WorkFlash_Footer & (uint8)0xffu);
                GlFooter[1] = ((Key_WorkFlash_Footer >> (uint8)8u) & (uint8)0xffu);
                Key->Action = Program_Footer;
            }
            else
            {
                Cybersecdiag_Fls_SectorCheck(Key, PAddress, PayLoad);
                Key_Fls_Write_Status = Failiure;
                Key->Action = Idle;
            }
        }
        break;

    case Program_Footer:
        MemIf_Status = Fls_GetStatus();
        if (MEMIF_IDLE == MemIf_Status)
        {
            if (E_OK == Fls_Write(((uint32)(PAddress & SECTOR_ADDRESS_OFFSET_MASK) + HeaderOffset + PayLoad->Length), (uint8 *)&GlFooter[0], FooterOffset))
            {
                Key->Action = Program_Footer_Wait;
            }
        }
        break;

    case Program_Footer_Wait:
        MemIf_JobResult = Fls_GetJobResult();
        if (MEMIF_JOB_PENDING != MemIf_JobResult)
        {
            if (MEMIF_JOB_OK == MemIf_JobResult)
            {
                Cybersecdiag_Fls_SectorCheck(Key, PAddress, PayLoad);
                Key->Action = Idle;
                Key_Fls_Write_Status = Normal;
            }
            else
            {
                Cybersecdiag_Fls_SectorCheck(Key, PAddress, PayLoad);
                Key_Fls_Write_Status = Failiure;
                Key->Action = Idle;
            }
        }
        break;

    default:
        /*No action required in default case*/
        break;
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief Cybersecdiag_GET_Fls_WRITE_STATUS
///
/// @arg  void
///
/// @return Std_ReturnType
///< br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType Cybersecdiag_GET_Fls_WRITE_STATUS(void)
{
    Std_ReturnType RetVal = E_NOT_OK;

    if (Key_Fls_Write_Status == Normal)
    {
        RetVal = E_OK;
    }
    else if (Key_Fls_Write_Status == Busy)
    {
        RetVal = CYBERSEC_E_PENDING;
    }
    else
    {
        RetVal = E_NOT_OK;
    }
    return RetVal;
}
#endif

#ifdef CYBERSECDIAG_SECURE_KEY_PROGRAMMING_AES_IV
/*=====================================================================================================================
**
** Function Name    :  Cybersecdiag_AES_IV_Key_Storage_RCStart
**
** Visibility       :  Public
**
** Description      :  Starts Routine Control to store AES IV(Initial Vector) Key via Fls
**
**
** Invocation       :  MeetMgr.diagcdd  , Function:RC_START_Diag_FEF1
**
** Inputs           :  Data[In]:Key ID,Key length,Key,Checksum
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Cybersecdiag_AES_IV_Key_Storage_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0u;
    #ifndef CRYPTO_KEY_MANAGEMENT_IMX8
    Std_ReturnType JobResult;
    uint8 WorkFlash_Status[1];
    WorkFlash_Status[0] = 0u;
    uint8 idx = 0u;
    AES_IV_Key_ID = Data[0];
    #endif
    uint16 Calculated_CRC = 0u;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        Calculated_CRC = Crc_CalculateCRC16((uint8 *)Data, (uint32)(AES_IV_length + 2u), Crc_StartValue16, TRUE);
        if (Calculated_CRC == ((uint16)(Data[AES_IV_length + 2u] << (uint16)8U) + Data[AES_IV_length + 3u])) /* INT31-C CERT FIX - Magic numbers should be declared as unsigned integers */
        {
            #ifndef CRYPTO_KEY_MANAGEMENT_IMX8
            uint8 key_start_idx = 2u;
            for (idx = 0; idx < AES_IV_length; idx++)
            {
                AES_IV_Key_array[idx] = Data[key_start_idx];
                key_start_idx++;
            }
            WorkFlashProtectionConfig[0].CybersecDiag_WorkFlash_Sector_Protection_Status_Read(WorkFlash_Status);
            if (WorkFlash_Status[0] == 0u)
            {
                JobResult = Cybersecdiag_AES_IV_Key_Write((uint8 *)Data); /* EXP37-C CERT FIX - Changed type of Data from void* to uint8*, since function declaration and definition has type as uint8* */
                if (JobResult == CYBERSEC_E_PENDING)
                {
                    Cybersecdiag_AES_IV_Key_RCStatus = 0x01u; // i.e.eROUTINE_INPROGRESS
                }
                else
                {
                    Cybersecdiag_AES_IV_Key_RCStatus = 0x03u; // i.e.eROUTINE_FINISH_NOK
                }
            }
            else
            {
                Cybersecdiag_AES_IV_Key_RCStatus = 0x03u; // i.e.eROUTINE_FINISH_NOK
            }
            Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_AES_IV_KEY_STORAGE_RCTYPE, (uint8)Cybersecdiag_AES_IV_Key_RCStatus);
            ret = E_OK;
            #else
            ret = Cybersecdiag_IV_SecureSymmetricKeyConfig.SecureSymmetricKey_Programming_Start(Data, ErrorCode);
            if (ret != DCM_E_PENDING)
            {
                if (DCM_E_OK == ret)
                {
                    ret = E_OK;
                    Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_AES_IV_KEY_STORAGE_RCTYPE, (uint8)0);
                    Cybersecdiag_IV_SecureSymmetricStatus = (uint8)eROUTINE_FINISH_OK;
                }
                else
                {
                    ret = E_NOT_OK;
                    ErrorCode[0] = DCM_E_GENERALPROGRAMMINGFAILURE; /*failure from GIP side Fuse write*/
                    Cybersecdiag_IV_SecureSymmetricStatus = (uint8)eROUTINE_FINISH_NOK;
                }
            }
            #endif
        }
        else
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            #ifdef CRYPTO_KEY_MANAGEMENT_IMX8
            Cybersecdiag_IV_SecureSymmetricStatus = (uint8)eROUTINE_FINISH_NOK;
            #endif
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
** Function Name    :  Cybersecdiag_AES_IV_Key_Storage_RCStatus
**
** Visibility       :  Public
**
** Description      :  Gives Routine Control Status of AES IV Key via Fls
**
**
** Invocation       :  MeetMgr.diagcdd , Function:RC_RESULTS_Diag_FEF1
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
Std_ReturnType Cybersecdiag_AES_IV_Key_Storage_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    #ifndef CRYPTO_KEY_MANAGEMENT_IMX8
    Std_ReturnType JobResult;
    uint8 AES_IV_Key_Read[AES_IV_length];
    Std_ReturnType array_status = E_NOT_OK;
    #endif
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        #ifndef CRYPTO_KEY_MANAGEMENT_IMX8
        JobResult = Cybersecdiag_GET_Fls_WRITE_STATUS();
        if (JobResult == E_OK)
        {
            if (AES_IV_Key_ID == AES_IV_KEY1_SLOT_ID)
            {
                (void)MemLib_MemCpy(AES_IV_Key_Read, (uint8 *)(AES_IV_Key_PAddress + HeaderOffset), AES_IV_length);
                array_status = Cybersecdiag_CompareArray(AES_IV_Key_array, AES_IV_Key_Read, AES_IV_length);
            }
            else if (AES_IV_Key_ID == AES_IV_KEY2_SLOT_ID)
            {
                    (void)MemLib_MemCpy(AES_IV_Key_Read, (uint8 *)(AES_IV_Key_PAddress + HeaderOffset+((uint8)1u * AES_IV_Single_Key_length), AES_IV_length);
                    array_status = Cybersecdiag_CompareArray( AES_IV_Key_array ,	 AES_IV_Key_Read,AES_IV_length);
            }
            else if (AES_IV_Key_ID == AES_IV_KEY3_SLOT_ID)
            {
                (void)MemLib_MemCpy(AES_IV_Key_Read, (uint8 *)(AES_IV_Key_PAddress + HeaderOffset + ((uint8)2u * AES_IV_Single_Key_length)), AES_IV_length);
                array_status = Cybersecdiag_CompareArray(AES_IV_Key_array, AES_IV_Key_Read, AES_IV_length);
            }
            else if (AES_IV_Key_ID == AES_IV_KEY4_SLOT_ID)
            {
                (void)MemLib_MemCpy(AES_IV_Key_Read, (uint8 *)(AES_IV_Key_PAddress + HeaderOffset + ((uint8)3u * AES_IV_Single_Key_length)), AES_IV_length);
                array_status = Cybersecdiag_CompareArray(AES_IV_Key_array, AES_IV_Key_Read, AES_IV_length);
            }
            else
            {
                array_status = E_NOT_OK;
            }
            if (E_OK == array_status)
            {
                Cybersecdiag_AES_IV_Key_RCStatus = 0x02u; // i.e.eROUTINE_FINISH_OK
            }
            else
            {
                Cybersecdiag_AES_IV_Key_RCStatus = 0x03u; // i.e.eROUTINE_FINISH_NOK
            }
        }
        else if (JobResult == CYBERSEC_E_PENDING)
        {
            Cybersecdiag_AES_IV_Key_RCStatus = 0x01u; // i.e.eROUTINE_INPROGRESS
        }
        else
        {
            Cybersecdiag_AES_IV_Key_RCStatus = 0x03u; // i.e.eROUTINE_FINISH_NOK
        }
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_AES_IV_KEY_STORAGE_RCTYPE, (uint8)Cybersecdiag_AES_IV_Key_RCStatus);
        #else
        ret = E_OK;
        #endif
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    #ifdef CRYPTO_KEY_MANAGEMENT_IMX8
    Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_AES_IV_KEY_STORAGE_RCTYPE, (uint8)Cybersecdiag_IV_SecureSymmetricStatus);
    #endif
    return ret;
}
#endif

#ifdef CYBERSECDIAG_SECURE_KEY_PROGRAMMING_RSA
/*=====================================================================================================================
**
** Function Name    :  Cybersecdiag_RSA_Key_Storage_RCStart
**
** Visibility       :  Public
**
** Description      :  Starts Routine Control to store RSA Key
**
**
** Invocation       :  MeetMgr.diagcdd  , Function:RC_START_Diag_FEF2
**
** Inputs           :  Data[In]:Key ID,Key length,Key,Checksum
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Cybersecdiag_RSA_Key_Storage_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    #ifndef CRYPTO_KEY_MANAGEMENT_IMX8
    Std_ReturnType JobResult;
    uint8 WorkFlash_Status[1];
    WorkFlash_Status[0] = 0u;
    uint16 idx = 0u;
    RSA_Key_ID = Data[0];
    #endif
    uint16 Calculated_CRC = 0u;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {

        Calculated_CRC = Crc_CalculateCRC16((uint8 *)Data, (uint32)(RSA_Key_length + 3u), Crc_StartValue16, TRUE);
        if (Calculated_CRC == ((uint16)(Data[RSA_Key_length + 3u] << (uint16)8U) + Data[RSA_Key_length + 4u])) /* INT31-C CERT FIX - Magic numbers should be declared as unsigned integers */
        {
            #ifndef CRYPTO_KEY_MANAGEMENT_IMX8
            uint16 key_start_idx = 3u;
            for (idx = 0; idx < RSA_Key_length; idx++)
            {
                RSA_Key_array[idx] = Data[key_start_idx];
                key_start_idx++;
            }
            WorkFlashProtectionConfig[1].CybersecDiag_WorkFlash_Sector_Protection_Status_Read(WorkFlash_Status);
            if (WorkFlash_Status[0] == 0)
            {
                JobResult = Cybersecdiag_RSA_Key_Write((uint8 *)Data); /* EXP37-C CERT FIX - Changed type of Data from void* to uint8*, since function declaration and definition has type as uint8* */
                if (JobResult == CYBERSEC_E_PENDING)
                {
                    Cybersecdiag_RSA_Key_RCStatus = 0x01u; // i.e.eROUTINE_INPROGRESS
                }
                else
                {
                    Cybersecdiag_RSA_Key_RCStatus = 0x03u; // i.e.eROUTINE_FINISH_NOK
                }
            }
            else
            {
                Cybersecdiag_RSA_Key_RCStatus = 0x03u; // i.e.eROUTINE_FINISH_NOK
            }
            Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_RSA_KEY_STORAGE_RCTYPE, (uint8)Cybersecdiag_RSA_Key_RCStatus);
            ret = E_OK;
            #else
            ret = Cybersecdiag_AES_SecureASymmetricKeyConfig.SecureASymmetricKey_Programming_Start(Data, ErrorCode);
            if (ret != DCM_E_PENDING)
            {
                if (DCM_E_OK == ret)
                {
                    ret = E_OK;
                    Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_RSA_KEY_STORAGE_RCTYPE, (uint8)0);
                    Cybersecdiag_RSA_ASymmetricStatus = (uint8)eROUTINE_FINISH_OK;
                }
                else
                {
                    ret = E_NOT_OK;
                    ErrorCode[0] = DCM_E_GENERALPROGRAMMINGFAILURE; /*failure from GIP side Fuse write*/
                    Cybersecdiag_RSA_ASymmetricStatus = (uint8)eROUTINE_FINISH_NOK;
                }
            }

            #endif
        }
        else
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            #ifdef CRYPTO_KEY_MANAGEMENT_IMX8
            Cybersecdiag_RSA_ASymmetricStatus = (uint8)eROUTINE_FINISH_NOK;
            #endif
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
** Function Name    :  Cybersecdiag_RSA_Key_Storage_RCStatus
**
** Visibility       :  Public
**
** Description      :  Gives Routine Control Status of RSA Key via Fls
**
**
** Invocation       :  MeetMgr.diagcdd , Function:RC_RESULTS_Diag_FEF2
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
Std_ReturnType Cybersecdiag_RSA_Key_Storage_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    #ifndef CRYPTO_KEY_MANAGEMENT_IMX8
    Std_ReturnType JobResult;
    uint8 RSA_Key_Read[RSA_Key_length];
    Std_ReturnType array_status = E_NOT_OK;
    #endif

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        #ifndef CRYPTO_KEY_MANAGEMENT_IMX8
        JobResult = Cybersecdiag_GET_Fls_WRITE_STATUS();
        if (JobResult == E_OK)
        {
            if (RSA_Key_ID == 1u)
            {
                (void)MemLib_MemCpy(RSA_Key_Read, (uint8 *)(RSA_Key_PAddress + HeaderOffset), RSA_Key_length);
                array_status = Cybersecdiag_CompareArray(RSA_Key_array, RSA_Key_Read, RSA_Key_length);
            }
            else
            {
                array_status = E_NOT_OK;
            }
            if (E_OK == array_status)
            {
                Cybersecdiag_RSA_Key_RCStatus = 0x02u; // i.e.eROUTINE_FINISH_OK
            }
            else
            {
                Cybersecdiag_RSA_Key_RCStatus = 0x03u; // i.e.eROUTINE_FINISH_NOK
            }
        }
        else if (JobResult == CYBERSEC_E_PENDING)
        {
            Cybersecdiag_RSA_Key_RCStatus = 0x01u; // i.e.eROUTINE_INPROGRESS
        }
        else
        {
            Cybersecdiag_RSA_Key_RCStatus = 0x03u; // i.e.eROUTINE_FINISH_NOK
        }
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_RSA_KEY_STORAGE_RCTYPE, (uint8)Cybersecdiag_RSA_Key_RCStatus);
        #endif
        ret = E_OK;
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    #ifdef CRYPTO_KEY_MANAGEMENT_IMX8
    Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_RSA_KEY_STORAGE_RCTYPE, (uint8)Cybersecdiag_RSA_ASymmetricStatus);
    #endif
    return ret;
}
#endif

#ifdef CYBERSECDIAG_COMPAREARRAY
//---------------------------------------------------------------------------------------------------------------------
/// @brief Cybersecdiag_CompareArray
///
/// @arg   uint8 * array1 , uint8 * array2,uint16 arraysize
///
/// @return Std_ReturnType
///< br>
//---------------------------------------------------------------------------------------------------------------------

Std_ReturnType Cybersecdiag_CompareArray(uint8 *array1, uint8 *array2, uint16 arraysize)
{
    for (uint16 idx = 0u; idx < arraysize; idx++)
    {
        if (array1[idx] != array2[idx])
        {
            return E_NOT_OK;
        }
    }

    // If all elements were same.
    return E_OK;
}
#endif

#ifdef CYBERSECDIAG_SECURE_KEY_WRITE_AES_IV
//---------------------------------------------------------------------------------------------------------------------
/// @brief Cybersecdiag_AES_IV_Key_Write
///
/// @arg  uint8 * Data
///
/// @return Std_ReturnType
///< br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType Cybersecdiag_AES_IV_Key_Write(uint8 *Data)
{
    Std_ReturnType RetVal = E_NOT_OK;
    if (AES_IV_Key.Action == Idle)
    {
        RetVal = CYBERSEC_E_PENDING;
        Key_Fls_Write_Status = Busy;

        // user data(single key)copied to single_key_RAM
        (void)MemLib_MemCpy(AES_IV_SINGLE_Key_Ram_Buffer, AES_IV_Key_array, AES_IV_Single_Key_length);

        Cybersecdiag_Fls_SectorCheck(&AES_IV_Key, AES_IV_Key_PAddress, &AES_IV_key_PayLoad);
        if ((AES_IV_Key.SectorStatus == Valid) || (AES_IV_Key.SectorStatus == Erased))
        {
            // From WorkFlash total AES_IV key size of data is copied to totalRAM
            (void)MemLib_MemCpy(AES_IV_Key_TOTAL_Ram_Buffer, (uint8 *)(AES_IV_Key_PAddress + HeaderOffset), AES_IV_Total_Key_length);
        }

        if (AES_IV_KEY1_SLOT_ID == Data[0]) // keyid == 1 means its first AES_IV_KEY
        {
            // first key copied to totalRAM along with Workflash data
            (void)MemLib_MemCpy(AES_IV_Key_TOTAL_Ram_Buffer, AES_IV_SINGLE_Key_Ram_Buffer, AES_IV_Single_Key_length);
        }
        else if (AES_IV_KEY2_SLOT_ID == Data[0])
        {
            // second key copied to totalRAM along with Workflash data
            (void)MemLib_MemCpy(AES_IV_Key_TOTAL_Ram_Buffer + ((uint8)1u * AES_IV_Single_Key_length), AES_IV_SINGLE_Key_Ram_Buffer, AES_IV_Single_Key_length);
        }
        else if (AES_IV_KEY3_SLOT_ID == Data[0])
        {
            // third key copied to totalRAM along with Workflash data
            (void)MemLib_MemCpy(AES_IV_Key_TOTAL_Ram_Buffer + ((uint8)2u * AES_IV_Single_Key_length), AES_IV_SINGLE_Key_Ram_Buffer, AES_IV_Single_Key_length);
        }
        else if (AES_IV_KEY4_SLOT_ID == Data[0])
        {
            // fourth key copied to totalRAM along with Workflash data
            (void)MemLib_MemCpy(AES_IV_Key_TOTAL_Ram_Buffer + ((uint8)3u * AES_IV_Single_Key_length), AES_IV_SINGLE_Key_Ram_Buffer, AES_IV_Single_Key_length);
        }
        else
        {
            // not a valid key ID
        }

        AES_IV_Key.Action = Erase;
    }
    return RetVal;
}
#endif

#ifdef CYBERSECDIAG_SECURE_KEY_WRITE_RSA
//---------------------------------------------------------------------------------------------------------------------
/// @brief Cybersecdiag_RSA_Key_Write
///
/// @arg  uint8 * Data
///
/// @return Std_ReturnType
///< br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType Cybersecdiag_RSA_Key_Write(uint8 *Data)
{
    Std_ReturnType RetVal = E_NOT_OK;
    if (RSA_Key.Action == Idle)
    {
        RetVal = CYBERSEC_E_PENDING;
        Key_Fls_Write_Status = Busy;
        (void)MemLib_MemCpy(RSA_key_PayLoad.RamBuffer, RSA_Key_array, RSA_key_PayLoad.Length);
        RSA_Key.Action = Erase;
    }
    return RetVal;
}
#endif

#ifdef CYBERSECDIAG_DATA_LOCK_AES_IV
/*=====================================================================================================================
**
** Function Name    :  Cybersecdiag_AES_IV_Key_lock_unlock_Read
**
** Visibility       :  Public
**
** Description      :  Reads lock/unlock status of AES IV Key
**
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FEF4
**
** Inputs           :  Data[Out]:0- unlocked/1-locked
                       Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Cybersecdiag_AES_IV_Key_lock_unlock_Read(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        WorkFlashProtectionConfig[0].CybersecDiag_WorkFlash_Sector_Protection_Status_Read(Data);

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
**
** Function Name    :  Cybersecdiag_AES_IV_Key_lock_unlock_Write
**
** Visibility       :  Public
**
** Description      :  Reads lock/unlock status of RSA Key
**
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FEF4
**
** Inputs           :  Data[In]:1 - lock/0 -unlock
                       Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Cybersecdiag_AES_IV_Key_lock_unlock_Write(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    boolean status = FALSE;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        status = (Data[0] == 1 ? FALSE : TRUE); // ACTIVE LOW
        ret = WorkFlashProtectionConfig[0].CybersecDiag_WorkFlash_Sector_Protection_Write(status);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef CYBERSECDIAG_DATA_LOCK_RSA
/*=====================================================================================================================
**
** Function Name    :  Cybersecdiag_RSA_Key_lock_unlock_Read
**
** Visibility       :  Public
**
** Description      :  Reads lock/unlock status of RSA Key
**
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FEF5
**
** Inputs           :  Data[In]:1 - lock/0 -unlock
                       Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Cybersecdiag_RSA_Key_lock_unlock_Read(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        WorkFlashProtectionConfig[1].CybersecDiag_WorkFlash_Sector_Protection_Status_Read(Data);
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
**
** Function Name    :  Cybersecdiag_RSA_Key_lock_unlock_Write
**
** Visibility       :  Public
**
** Description      :  lock/unlock RSA Key
**
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FEF5
**
** Inputs           :  Data[In]:1 - lock/0 -unlock
                       Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Cybersecdiag_RSA_Key_lock_unlock_Write(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    boolean status = FALSE;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        status = (Data[0] == 1 ? FALSE : TRUE); // ACTIVE LOW
        ret = WorkFlashProtectionConfig[1].CybersecDiag_WorkFlash_Sector_Protection_Write(status);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef CYBERSECDIAG_SECURE_KEY_PROGRAMMING_SHE
/*=====================================================================================================================
**
** Function Name    :  Cybersecdiag_She_MainFunction
**
** Visibility       :  Public
**
** Description      :  Periodic function to handle SHE functionalities
**
**
** Invocation       :  MeetCDD_10msRunnable.c  , Function:CmpActive
**
** Inputs           :  None
**
** Outputs          :  None
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
void Cybersecdiag_She_MainFunction(void)
{
    if (AES_Key_RCStart_Flag == CYBERSEC_AES_KEY_RCSTART_REQUESTED)
    {
        Cybersecdiag_SHE_Key_Storage(AES_Key_array_M1M2M3, CYBERSECDIAG_AES_M1M2M3_SIZE);
    }
    else
    {
        /* do nothing */
    }
}

/*=====================================================================================================================
**
** Function Name    :  CMeetCdd_MeetCryptoJobNotifyCallback
**
** Visibility       :  Private
**
** Description      :  Callback function to count the number of times SHE functions called
**
**
** Invocation       :  Cybersecdiagcdd.c  , Function:Cybersecdiag_SHE_Key_Storage
**
** Inputs           :  None
**
** Outputs          :  None
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
FUNC(void, CMeetCdd_CODE) CMeetCdd_MeetCryptoJobNotifyCallback(UInt8 Status) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    if ((Status == E_OK) && (stcCsmCbk.SymKeyExtract.CbkCount < (uint32)0xFFFFFFFFU)) /* INT30-C CERT FIX - Range of stcCsmCbk.SymKeyExtract.CbkCount is checked to be within uint32 range to avoid wrapping */
    {
        stcCsmCbk.SymKeyExtract.CbkCount++;
    }
    else
    {
        // do nothing
    }
}

/*=====================================================================================================================
**
** Function Name    :  Cybersecdiag_SHE_Key_Storage
**
** Visibility       :  Public
**
** Description      :  This function handles the steps to be followed when storing a key into SHE slot.
**
**
** Invocation       :  Cybersecdiagcdd.c  , Function:Cybersecdiag_She_MainFunction
**
** Inputs           :  key - AES key given from $FEF0 service
**                     length - length of the key
**
** Outputs          :  None
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
/* EXP37-C CERT FIX - Changed type of length from uint8 to uint32 */
void Cybersecdiag_SHE_Key_Storage(uint8 *key, uint32 length)
{
    static ts_CybersecdiagCallback *Cbk;
    boolean error_status = E_OK;
    uint8 SHE_StateIndex = 0u;

    if (e_Cybersecdiag_SHE_MaxStates != e_Cybersecdiag_SHE_State)
    {
        switch (e_Cybersecdiag_SHE_State)
        {
        case e_Cybersecdiag_SHE_Idle:
            Cybersecdiag_SHE_response[e_Cybersecdiag_SHE_Idle] = E_OK;
            break;
        case e_Cybersecdiag_SHE_LoadKeyPdStart:
            Cbk = &stcCsmCbk.SymKeyExtract;
            stcCsmCbk.SymKeyExtract.CbkCount = 0UL;

            Cybersecdiag_SHE_response[e_Cybersecdiag_SHE_LoadKeyPdStart] = CRYPTOCDD_LoadKeyPdStart(CRYPTOCDD_MeetCdd);

            if (CSM_E_OK != Cybersecdiag_SHE_response[e_Cybersecdiag_SHE_LoadKeyPdStart])
            {
                error_status = E_NOT_OK;
            }
            else
            {
                e_Cybersecdiag_SHE_State = e_Cybersecdiag_SHE_LoadKeyPdStart_main;
            }
            break;

        case e_Cybersecdiag_SHE_LoadKeyPdStart_main:
            #ifdef CYBERSECDIAG_SECURE_KEY_CBK_IDX
			if ((0UL >= Cbk->CbkCount) && (Cybersecdiag_SHE_Timeout < CYBERSECDIAG_SHE_TIMEOUT))
            #else
            if ((1UL != Cbk->CbkCount) && (Cybersecdiag_SHE_Timeout < CYBERSECDIAG_SHE_TIMEOUT))
            #endif
            {
                Cybersecdiag_SHE_Timeout++;
            }
            else
            {
                if (CYBERSECDIAG_SHE_TIMEOUT > Cybersecdiag_SHE_Timeout)
                {
                    e_Cybersecdiag_SHE_State = e_Cybersecdiag_SHE_LoadKeyPdUpdate;
                    Cybersecdiag_SHE_Timeout = 0U;
                    Cybersecdiag_SHE_response[e_Cybersecdiag_SHE_LoadKeyPdStart_main] = E_OK;
                }
                else
                {
                    error_status = E_NOT_OK;
                }
            }
            break;

        case e_Cybersecdiag_SHE_LoadKeyPdUpdate:
            Cybersecdiag_SHE_response[e_Cybersecdiag_SHE_LoadKeyPdUpdate] = CRYPTOCDD_LoadKeyPdUpdate(key, length);

            if (CSM_E_OK != Cybersecdiag_SHE_response[e_Cybersecdiag_SHE_LoadKeyPdUpdate])
            {
                error_status = E_NOT_OK;
            }
            else
            {
                e_Cybersecdiag_SHE_State = e_Cybersecdiag_SHE_LoadKeyPdUpdate_main;
            }
            break;

        case e_Cybersecdiag_SHE_LoadKeyPdUpdate_main:
            #ifdef CYBERSECDIAG_SECURE_KEY_CBK_IDX
			if ((1UL >= Cbk->CbkCount) && (Cybersecdiag_SHE_Timeout < CYBERSECDIAG_SHE_TIMEOUT))
            #else
            if ((2UL != Cbk->CbkCount) && (Cybersecdiag_SHE_Timeout < CYBERSECDIAG_SHE_TIMEOUT))
            #endif
            {
                Cybersecdiag_SHE_Timeout++;
            }
            else
            {
                if (CYBERSECDIAG_SHE_TIMEOUT > Cybersecdiag_SHE_Timeout)
                {
                    e_Cybersecdiag_SHE_State = e_Cybersecdiag_SHE_LoadKeyPdFinish;
                    Cybersecdiag_SHE_Timeout = 0U;
                    Cybersecdiag_SHE_response[e_Cybersecdiag_SHE_LoadKeyPdUpdate_main] = E_OK;
                }
                else
                {
                    error_status = E_NOT_OK;
                }
            }
            break;

        case e_Cybersecdiag_SHE_LoadKeyPdFinish:
            Cybersecdiag_SHE_response[e_Cybersecdiag_SHE_LoadKeyPdFinish] = CRYPTOCDD_LoadKeyPdFinish(&Cybersecdiag_SHE_KeyHandler, &Cybersecdiag_SHE_M4_M5_MSG[0], &Cybersecdiag_SHE_M4_M5_LEN);

            if (CSM_E_OK != Cybersecdiag_SHE_response[e_Cybersecdiag_SHE_LoadKeyPdFinish])
            {
                error_status = E_NOT_OK;
            }
            else
            {
                e_Cybersecdiag_SHE_State = e_Cybersecdiag_SHE_LoadKeyPdFinish_main;
            }
            break;

        case e_Cybersecdiag_SHE_LoadKeyPdFinish_main:

            #ifdef CYBERSECDIAG_SECURE_KEY_CBK_IDX
			if ((2UL >= Cbk->CbkCount) && (Cybersecdiag_SHE_Timeout < CYBERSECDIAG_SHE_TIMEOUT))
            #else
            if ((3UL != Cbk->CbkCount) && (Cybersecdiag_SHE_Timeout < CYBERSECDIAG_SHE_TIMEOUT))
            #endif
            {
                Cybersecdiag_SHE_Timeout++;
                #ifdef CYBERSECDIAG_SECURE_KEY_CBK_IDX
                Cry_She_SymKeyExtractMainFunction();
                #endif
            }
            else
            {
                if (CYBERSECDIAG_SHE_TIMEOUT > Cybersecdiag_SHE_Timeout)
                {
                    e_Cybersecdiag_SHE_State = e_Cybersecdiag_SHE_done;
                    Cybersecdiag_SHE_Timeout = 0U;
                    Cybersecdiag_SHE_response[e_Cybersecdiag_SHE_LoadKeyPdFinish_main] = E_OK;
                }
                else
                {
                    error_status = E_NOT_OK;
                }
            }
            break;

        case e_Cybersecdiag_SHE_done:
            Cybersecdiag_SHE_response[e_Cybersecdiag_SHE_done] = E_OK;
            break;

        default:
            /*No action required in default*/
            break;
        }

        for (SHE_StateIndex = 0; SHE_StateIndex < e_Cybersecdiag_SHE_MaxStates; SHE_StateIndex++)
        {
            if (SHE_StateIndex <= e_Cybersecdiag_SHE_State)
            {
                if ((SHE_StateIndex < e_Cybersecdiag_SHE_done) && (E_NOT_OK != error_status) && (Cybersecdiag_AES_Key_RCStatus != 0x03U))
                {
                    Cybersecdiag_AES_Key_RCStatus = 0x01u; // eROUTINE_INPROGRESS
                }
                else if ((SHE_StateIndex == e_Cybersecdiag_SHE_done) && (Cybersecdiag_SHE_response[SHE_StateIndex] == E_OK) && (Cybersecdiag_AES_Key_RCStatus == 0x01U))
                {
                    Cybersecdiag_AES_Key_RCStatus = 0x00u; // eROUTINE_FINISH_OK
                    AES_Key_RCStart_Flag = 0u;

                    /* Clear the Responses once Routine is complete */
                    for (SHE_StateIndex = 0U; SHE_StateIndex < e_Cybersecdiag_SHE_MaxStates; SHE_StateIndex++)
                    {
                        if (SHE_StateIndex == e_Cybersecdiag_SHE_Idle)
                        {
                            Cybersecdiag_SHE_response[SHE_StateIndex] = E_OK;
                        }
                        else
                        {
                            Cybersecdiag_SHE_response[SHE_StateIndex] = E_NOT_OK;
                        }
                    }

                    e_Cybersecdiag_SHE_State = e_Cybersecdiag_SHE_Idle;
                }
                else if ((SHE_StateIndex <= e_Cybersecdiag_SHE_done) && (E_NOT_OK == error_status))
                {
                    /* error */
                    CRYPTOCDD_CancelJobs();
                    e_Cybersecdiag_SHE_State = e_Cybersecdiag_SHE_Idle;
                    Cybersecdiag_AES_Key_RCStatus = 0x03u; // eROUTINE_FINISH_NOK
                    AES_Key_RCStart_Flag = 0u;
                }
                else
                {
                    /* do nothing */
                }
            }
            else
            {
                break;
            }
        }
    }
}
#endif

#ifdef CYBERSECDIAG_SECURE_KEY_PROGRAMMING_AES
/*=====================================================================================================================
**
** Function Name    :  Cybersecdiag_AES_Key_Storage_RCStart
**
** Visibility       :  Public
**
** Description      :  Starts Routine Control to store AES Key
**
**
** Invocation       :  MeetMgr.diagcdd  , Function:RC_START_Diag_FEF0
**
** Inputs           :  Data[In]:Key ID,Key Length,Key,Checksum
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Cybersecdiag_AES_Key_Storage_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    #ifndef CRYPTO_KEY_MANAGEMENT_IMX8
    uint16 Calculated_CRC = 0U;
    uint8 idx = 0U;
    uint8 key_start_idx = 2U;

    Key_length = Data[1];

    #if defined(CRYPTO_KEY_SHE_DECRYPTION) && defined(CRYPTO_KEY_SHE)
    if (SHE_ENC_AES_KEY_SIZE == Key_length)
    {
        Calculated_CRC = Crc_CalculateCRC16((uint8 *)Data, (uint32)(SHE_ENC_AES_KEY_SIZE + 2u), Crc_StartValue16, TRUE);

        if (Calculated_CRC == ((uint16)(Data[SHE_ENC_AES_KEY_SIZE + 2u] << (uint16)8U) + Data[SHE_ENC_AES_KEY_SIZE + 3u])) /* INT31-C CERT FIX - Magic numbers should be declared as unsigned integers */
        {
            for (idx = 0u; idx < Key_length; idx++)
            {
                AES_Enc_Key_array[idx] = Data[key_start_idx];
                key_start_idx++;
            }

            ret = VisteonObfiscateLib_DecryptItem_v2(AES_Enc_Key_array, SHE_ENC_AES_KEY_SIZE, AES_Key_array, AES_KEY_SIZE);

            if (E_NOT_OK == ret)
            {
                // JTAG password decryption failed
                *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
            }
            else
            {
                for (idx = 0u; idx < AES_KEY_SIZE; idx++)
                {
                    if (idx < CYBERSECDIAG_AES_M1M2M3_SIZE)
                    {
                        AES_Key_array_M1M2M3[idx] = AES_Key_array[idx];
                    }
                    else
                    {
                        #ifdef CRYPTO_KEY_SHE_VERIFICATION
                        AES_Key_array_M4M5[idx - CYBERSECDIAG_AES_M1M2M3_SIZE] = AES_Key_array[idx];
                        #else
                        break;
                        #endif
                    }
                }
            }

            MGRDIAG_GET_SESSION(&MfgModeActive);
            if (MfgModeActive == MEET_SESSION)
            {
                e_Cybersecdiag_SHE_State = e_Cybersecdiag_SHE_LoadKeyPdStart;
                AES_Key_RCStart_Flag = CYBERSEC_AES_KEY_RCSTART_REQUESTED; /*value - 1u */
                                                                           /*For a Type2 routine for standardization,
                                                                               Start routine will always return "IN_PROGRESS" status.
                                                                               Only in Result routine,actual status will get reflected.*/
                Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_AES_KEY_STORAGE_RCTYPE, (uint8)eROUTINE_INPROGRESS);
                ret = E_OK;
            }
            else
            {
                /*invalid mode*/
                *ErrorCode = INVALID_MODE;
            }
        }
        else
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
    }
    else
    {
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
    }
    #else
    if (AES_KEY_SIZE == Key_length)
    {
        Calculated_CRC = Crc_CalculateCRC16((uint8 *)Data, (uint32)(AES_KEY_SIZE + 2u), Crc_StartValue16, TRUE);
        if (Calculated_CRC == ((uint16)(Data[AES_KEY_SIZE + 2u] << (uint8)8U) + Data[AES_KEY_SIZE + 3u]))
        {
            for (idx = 0u; idx < Key_length; idx++)
            {
                #ifdef CRYPTO_KEY_SHE
                if (idx < CYBERSECDIAG_AES_M1M2M3_SIZE)
                {
                    AES_Key_array_M1M2M3[idx] = Data[key_start_idx];
                }
                else
                {
                    #ifdef CRYPTO_KEY_SHE_VERIFICATION
                    AES_Key_array_M4M5[idx - CYBERSECDIAG_AES_M1M2M3_SIZE] = Data[key_start_idx];
                    #else
                    break;
                    #endif
                }
                #else
                AES_Key_array[idx] = Data[key_start_idx];
                #endif
                key_start_idx++;
            }

            MGRDIAG_GET_SESSION(&MfgModeActive);
            if (MfgModeActive == MEET_SESSION)
            {
                #ifdef CRYPTO_KEY_SHE
                e_Cybersecdiag_SHE_State = e_Cybersecdiag_SHE_LoadKeyPdStart;
                AES_Key_RCStart_Flag = CYBERSEC_AES_KEY_RCSTART_REQUESTED; /*value - 1u */
                #else
                /* Below function is commented. Use as per the requirements.
                 * Csm_AES_Key_Status = CYBERSECDIAG_KEY_ELEMENT_SET(Enc_Dec_Key_ID, CSM_KEY_ELEMENT_ID,AES_Key_array,AES_Key_length); */

                if (Csm_AES_Key_Status == 0u) // OK
                {
                    Cybersecdiag_AES_Key_RCStatus = 0x02u; // i.e.eROUTINE_FINISH_OK
                }
                else if (Csm_AES_Key_Status == 2u) // busy
                {
                    Cybersecdiag_AES_Key_RCStatus = 0x01u; // i.e.eROUTINE_INPROGRESS
                }
                else // others
                {
                    Cybersecdiag_AES_Key_RCStatus = 0x03u; // i.e.eROUTINE_FINISH_NOK
                }
                #endif
                /*For a Type2 routine for standardization,
                    Start routine will always return "IN_PROGRESS" status.
                    Only in Result routine,actual status will get reflected.*/
                Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_AES_KEY_STORAGE_RCTYPE, (uint8)eROUTINE_INPROGRESS);
                ret = E_OK;
            }
            else
            {
                /*invalid mode*/
                *ErrorCode = INVALID_MODE;
            }
        }
        else
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
    }
    else
    {
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
    }
    #endif

    #else
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = Cybersecdiag_AES_SecureSymmetricKeyConfig.SecureSymmetricAESKey_Programming_Start(Data, ErrorCode);
        if (ret != DCM_E_PENDING)
        {
            if (DCM_E_OK == ret)
            {
                ret = E_OK;
                Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_AES_KEY_STORAGE_RCTYPE, (uint8)0);
                Cybersecdiag_AES_SecureSymmetricStatus = (uint8)eROUTINE_FINISH_OK;
            }
            else
            {
                ret = E_NOT_OK;
                ErrorCode[0] = DCM_E_GENERALPROGRAMMINGFAILURE; /*failure from GIP side Fuse write*/
                Cybersecdiag_AES_SecureSymmetricStatus = (uint8)eROUTINE_FINISH_NOK;
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    #endif
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Cybersecdiag_AES_Key_Storage_RCStatus
**
** Visibility       :  Public
**
** Description      :  Gives Routine Control Status of AES Key storage
**
**
** Invocation       :  MeetMgr.diagcdd , Function:RC_RESULTS_Diag_FEF0
**
** Inputs           :  Data[Out]: status of Routine Control to store AES Key
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Cybersecdiag_AES_Key_Storage_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;

    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        #ifndef CRYPTO_KEY_MANAGEMENT_IMX8
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_AES_KEY_STORAGE_RCTYPE, (uint8)Cybersecdiag_AES_Key_RCStatus);
        #else
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_AES_KEY_STORAGE_RCTYPE, (uint8)Cybersecdiag_AES_SecureSymmetricStatus);
        #endif
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

#ifdef CYBERSECDIAG_JTAG_LOCK_ENABLE
//---------------------------------------------------------------------------------------------------------------------
/// @brief Cybersecdiag_JTAG_passwordWrite_Lock
///
/// @arg  uint8 * Data
///
/// @return Std_ReturnType
///< br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType Cybersecdiag_JTAG_passwordWrite_Lock(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    #ifndef CRYPTO_KEY_MANAGEMENT_IMX8
    uint8 JTAG_DATA_WRITE_FORMAT[JTAG_DATA_WRITE_TOTAL_SIZE] = {0};

    // check whether first request for write or TCFlash write busy-repeat request
    if (FALSE == JTAG_WRITE_INITIATED)
    {
        // first time request for write - do all precondition check & then trigger write

        // verify serial number
        ret = Cybersecdiag_Verify_Serial_Number(Data);
        if (E_OK == ret)
        {
            // input serial number matches with stored serial number

            (void)MemLib_MemCpy(JTAG_ENC_BUFF, Data + SERIAL_NUMBER_ENCODED_SIZE, JTAG_ENC_PASSWORD_SIZE);
            // decrypt JTAG password
            ret = VisteonObfiscateLib_DecryptItem_v2(JTAG_ENC_BUFF, JTAG_ENC_PASSWORD_SIZE, JTAG_DEC_BUFF, JTAG_DEC_PASSWORD_SIZE);
            if (E_NOT_OK == ret)
            {
                // JTAG password decryption failed
                *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
            }
            else
            {
                // JTAG password decryption passed

                // assign JTAG password and security lock bytes to corresponding offset
                Cybersecdiag_Assign_JTAG_Data(JTAG_DEC_BUFF, JTAG_DATA_WRITE_FORMAT);
                // Write JTAG decrypted password and security lock bits to Boot Marker(TCFlash partition)
                ret = ShareDiag_Write_Service_3(JTAG_DATA_WRITE_FORMAT, ErrorCode);
                if (E_NOT_OK == ret)
                {
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                }
                else
                {
                    // Write initiated and pending
                    JTAG_WRITE_INITIATED = TRUE;
                }
            }
        }
        else
        {
            // input serial number doesn't matches with stored serial number
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
    }
    else
    {
        // TCFlash write busy repeat request

        // Write JTAG decrypted password and security lock bits to Boot Marker(TCFlash partition)
        ret = ShareDiag_Write_Service_5(JTAG_DATA_WRITE_FORMAT, ErrorCode);
        if (DCM_E_PENDING != ret)
        {
            // write completed; clear write initiated flag
            JTAG_WRITE_INITIATED = FALSE;
        }
    }

    #else

    ret = Cybersecdiag_Password_JtagLockingConfig.JtagLocking_Start(Data, ErrorCode);

    #endif
    return ret;
}
#endif
#ifdef CYBERSECDIAG_UART_UNLOCK_ENABLE
//---------------------------------------------------------------------------------------------------------------------
/// @brief Cybersecdiag_UART_password_UnLock
///
/// @arg  uint8 * Data
///
/// @return Std_ReturnType
///< br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType Cybersecdiag_UART_password_UnLock(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;

    ret = Cybersecdiag_Password_UART_UnLockingConfig.UART_UnLocking_Start(Data, ErrorCode);

    return ret;
}
#endif

#ifdef CYBERSECDIAG_CRYPTO_KEY_VERIFICATION
/*=====================================================================================================================
**
** Function Name    :  Cybersecdiag_key_verification_RCStart
**
** Visibility       :  Public
**
** Description      :  Starts Routine Control to verify all cybersecurity keys
**
**
** Invocation       :  MeetMgr.diagcdd  , Function:RC_START_Diag_FEFC
**
** Inputs           :  Data[In]:
**                     Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**                     E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Cybersecdiag_key_verification_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    #ifndef CRYPTO_KEY_MANAGEMENT_IMX8
    boolean Compare_ret = FALSE;
    uint8 MfgModeActive = 0U;
    #ifdef CRYPTO_KEY_VERIFICATION_GIP
    Std_ReturnType GIP_Verify_ret = E_NOT_OK;
    #endif

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        Cybersecdiag_CyberSecKeyVerify_RCStatus = eROUTINE_INPROGRESS;

        #ifdef CRYPTO_KEY_VERIFICATION_GIP
        if ((AES_VERIFICATION_IDLE == AES_VerificationState) && (FALSE == GIP_KeyVerify_STATUS_IS_PENDING))
        {
            /*Starting the verification from first or starting the next iteration of verification*/
            Cybersecurity_Key_Status = 0u; /*clear Key_Status before start of verification*/
            /* VERIFY_AES_KEY */
            MemLib_MemCpy(&IVectorData[0], (uint8 *)Initial_IV_Addr, 16u);

            /* Below function is commented. Use as per the requirements.
             * (void)CYBERSECDIAG_KEY_ELEMENT_SET(Enc_Dec_Key_ID, CRYPTO_KE_CIPHER_IV,&IVectorData[0],16u); */

            /* Below function is commented. Use as per the requirements.
             *  (void)CYBERSECDIAG_KEY_SET_VALID(Enc_Dec_Key_ID); */
            MemLib_MemSet(SampleInputbuffer, 0xFFu, AES_KEY_VERIFY_SAMPLE_INPUT_LENGTH);
            Valid_AES_Key_idx = 0;
            AES_VerificationStatus = ACTIVE;
            AES_VerificationState = ENCRYPTION;
        #endif

            /* VERIFY_AES_IV */
            MemLib_MemSet(AES_IV_WF_DefaultData, 0xFFu, AES_IV_TOTAL_Key_DATA_PAYLOAD);
            Compare_ret = MemLib_MemCmp((uint8 *)AES_IV_WF_DefaultData, (uint8 *)AES_IV_KEY_WFLASH_OFFSET, AES_IV_TOTAL_Key_DATA_PAYLOAD);
            if (FALSE == Compare_ret)
            {
                Cybersecurity_Key_Status = Cybersecurity_Key_Status | AES_IV_status_bit;
            }

            /* VERIFY_RSA_KEY */
            MemLib_MemSet(RSA_key_WF_DefaultData, 0xFFu, RSA_key_DATA_PAYLOAD);
            Compare_ret = MemLib_MemCmp((uint8 *)RSA_key_WF_DefaultData, (uint8 *)RSA_KEY_WFLASH_OFFSET, RSA_key_DATA_PAYLOAD);
            if (FALSE == Compare_ret)
            {
                Cybersecurity_Key_Status = Cybersecurity_Key_Status | RSA_status_bit;
            }

            #ifdef CRYPTO_KEY_VERIFICATION_GIP
            /* VERIFY_GIP_KEYS */
            GIP_Verify_ret = Cybersecdiag_KeyVerify.CybersecDiag_GIP_Key_Verification(Data, ErrorCode);
            if (GIP_Verify_ret != DCM_E_PENDING)
            {
                Cybersecurity_Key_Status = Cybersecurity_Key_Status | Data[DATA_BYTE_1];
                GIP_KeyVerify_STATUS_IS_PENDING = FALSE;
            }
            else
            {
                GIP_KeyVerify_STATUS_IS_PENDING = TRUE;
            }
        }
        else if ((AES_VERIFICATION_IDLE != AES_VerificationState) && (FALSE == GIP_KeyVerify_STATUS_IS_PENDING))
        {
            /*Already in Progress*/
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
        else if (FALSE != GIP_KeyVerify_STATUS_IS_PENDING)
        {
            /*Invoke CybersecDiag_GIP_Key_Verification till it respond E_OK/E_NOT_OK*/
            GIP_Verify_ret = Cybersecdiag_KeyVerify.CybersecDiag_GIP_Key_Verification(Data, ErrorCode);
            if (GIP_Verify_ret != DCM_E_PENDING)
            {
                /*Assign GIP returned KeyVerify status to Cybersecurity_Key_Status*/
                Cybersecurity_Key_Status = Cybersecurity_Key_Status | Data[DATA_BYTE_1];
                GIP_KeyVerify_STATUS_IS_PENDING = FALSE;
            }
            else
            {
                GIP_KeyVerify_STATUS_IS_PENDING = TRUE;
            }
        }
        else
        {
            /*NULL*/
        }
            #endif
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }

    #ifndef CRYPTO_KEY_VERIFICATION_GIP
    if (Cybersecurity_FullPASS_status_bit == Cybersecurity_Key_Status)
    {
        Cybersecdiag_CyberSecKeyVerify_RCStatus = (uint8)eROUTINE_FINISH_OK;
    }
    else
    {
        Cybersecdiag_CyberSecKeyVerify_RCStatus = (uint8)eROUTINE_FINISH_NOK;
    }
    #endif

    Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_CYBERSECURITY_KEY_VERIFY_RCTYPE, (uint8)eROUTINE_INPROGRESS);

    #ifdef CRYPTO_KEY_VERIFICATION_GIP
    return GIP_Verify_ret;
    #else
    return Compare_ret;
    #endif

    #else

    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = Cybersecdiag_KeyVerify.CybersecDiag_GIP_Key_Verification(Data, ErrorCode);
        if (ret != DCM_E_PENDING)
        {
            ret = E_OK;
        }
        else
        {
            /*GIP Request is in Progress */
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
#endif
}
/*=====================================================================================================================
**
** Function Name    :  Cybersecdiag_Key_verification_RCStatus
**
** Visibility       :  Public
**
** Description      :  Gives Routine Control Status of Cybersecurity keys verification
**
**
** Invocation       :  MeetMgr.diagcdd , Function:RC_RESULTS_Diag_FEFC
**
** Inputs           :  Data[Out]: status of Routine Control to verify all Ceybersecurity Keys
**                     Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**                     E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Cybersecdiag_Key_verification_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;

    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        #ifndef CRYPTO_KEY_MANAGEMENT_IMX8
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_CYBERSECURITY_KEY_VERIFY_RCTYPE, (uint8)Cybersecdiag_CyberSecKeyVerify_RCStatus); /* EXP37-C CERT FIX - TypeCasted Cybersecdiag_CyberSecKeyVerify_RCStatus to uint8 */
        Data[DATA_BYTE_1] = Cybersecurity_Key_Status;
        #else
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_CYBERSECURITY_KEY_VERIFY_RCTYPE, (uint8)Cybersecdiag_KEY_VerificationStatus);
        #endif
        ret = E_OK;
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

#ifndef CRYPTO_KEY_MANAGEMENT_IMX8
/*=====================================================================================================================
**
** Function Name    :  CybersecDiag_AES_Key_Verification_Process
**
** Visibility       :  Public
**
** Description      :  verify AES keys
**
** Invocation       :  Cybersec.diagcdd.c , Function:Cybersecdiag_key_verification_RCStart
**
** Inputs           :
**
** Outputs          :  Data[Out]: status of AES key verification
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
void CybersecDiag_AES_Key_Verification_Process()
{
    Std_ReturnType Encrypt_ret = E_NOT_OK;
    Std_ReturnType Decrypt_ret = E_NOT_OK;
    boolean Compare_ret = FALSE;
    uint8 CMAC_idx;

    switch (AES_VerificationState)
    {
    case ENCRYPTION:
        AES_Key_ID = ALL_VALID_VERIFIABLE_KEYIDs[Valid_AES_Key_idx];
        for (CMAC_idx = 0; CMAC_idx < NO_OF_VALID_CMAC_KEYS; CMAC_idx++)
        {
            if (AES_Key_ID == Valid_AES_CMAC_KeyIDs[CMAC_idx])
            {
                // CMAC can't be verified by encrypt. Hence set EncBuffer and go to decrypt directly
                MemLib_MemCpy((uint8 *)SampleEncResult, (uint8 *)SampleEncBuff, 16u);
                AES_VerificationState = DECRYPTION;
                IsCMAC = TRUE;
                CMAC_idx = NO_OF_VALID_CMAC_KEYS; /*to exist for loop once it's detected it's a CMAC Key*/
            }
            else
            {
                IsCMAC = FALSE;
                AES_VerificationState = AES_VERIFICATION_IDLE;
            }
        }
        if (TRUE != IsCMAC)
        {
            (void)CYBERSECDIAG_SET_KEY_ID(AES_Key_ID);
            Encrypt_ret = CYBERSECDIAG_ENCRYPT(Encryption_Job_ID, 7u, &SampleInputbuffer[0], SampleInpBuffLength, &SampleEncResult[0], &SampleEncResultLen);
            if (E_OK == Encrypt_ret)
            {
                Encrypt_status = ENCRYPTION_INPROGRESS;
                AES_VerificationState = ENCRYPTION_WAIT;
            }
            else
            {
                AES_VerificationState = AES_VERIFICATION_IDLE;
            }
        }
        break;
    case ENCRYPTION_WAIT:
        if (ENCRYPTION_COMPLETED == Encrypt_status)
        {
            Encrypt_status = ENCRYPTION_DEFAULT;
            AES_VerificationState = DECRYPTION;
        }
        else if (ENCRYPTION_FAILED == Encrypt_status)
        {
            Encrypt_status = ENCRYPTION_DEFAULT;
            AES_VerificationState = AES_VERIFICATION_IDLE;
        }
        else
        {
            /*No action required*/
        }
        break;
    case DECRYPTION:
        (void)CYBERSECDIAG_SET_KEY_ID(AES_Key_ID);
        Decrypt_ret = CYBERSECDIAG_DECRYPT(Decryption_Job_ID, 7u, &SampleEncResult[0], SampleEncResultLen, &SampleDecResult[0], &SampleDecResultLen);
        if (E_OK == Decrypt_ret)
        {
            Decrypt_status = DECRYPTION_INPROGRESS;
            AES_VerificationState = DECRYPTION_WAIT;
        }
        else
        {
            AES_VerificationState = AES_VERIFICATION_IDLE;
        }
        break;
    case DECRYPTION_WAIT:
        if (DECRYPTION_COMPLETED == Decrypt_status)
        {
            Decrypt_status = DECRYPTION_DEFAULT;
            AES_VerificationState = COMPARE;
        }
        else if (DECRYPTION_FAILED == Decrypt_status)
        {
            if (FALSE != IsCMAC)
            {
                // CMAC Key can't be verified by encrypt and decrypt method. Hence check if corresponding SHE reg shows not empty status
                if (CMAC_KEY_EMPTY_STATUS != SHE_ERC_CMDMAIN)
                {
                    /*Current CMAC key is valid since SHE returns not empty status*/
                    if (Valid_AES_Key_idx < (NO_OF_VALID_ENC_DEC_KEYS + NO_OF_VALID_CMAC_KEYS - 1u))
                    {
                        /* move on to verify next Key*/
                        Valid_AES_Key_idx++;
                        AES_VerificationState = ENCRYPTION;
                    }
                    else if (Valid_AES_Key_idx == (NO_OF_VALID_ENC_DEC_KEYS + NO_OF_VALID_CMAC_KEYS - 1u))
                    {
                        /* Has verified all Keys, hence update the status and move to IDLE*/
                        Cybersecurity_Key_Status = Cybersecurity_Key_Status | AES_Key_status_bit;
                        AES_VerificationState = AES_VERIFICATION_IDLE;
                    }
                }
                else
                {
                    AES_VerificationState = AES_VERIFICATION_IDLE;
                }
            }
            else
            {
                AES_VerificationState = AES_VERIFICATION_IDLE;
            }
            Decrypt_status = DECRYPTION_DEFAULT;
        }
        else
        {
        }
        break;
    case COMPARE:
        Compare_ret = MemLib_MemCmp((uint8 *)SampleInputbuffer, (uint8 *)SampleDecResult, AES_KEY_VERIFY_SAMPLE_INPUT_LENGTH);
        if (FALSE != Compare_ret)
        {
            if (Valid_AES_Key_idx < (NO_OF_VALID_ENC_DEC_KEYS + NO_OF_VALID_CMAC_KEYS - 1u))
            {
                Valid_AES_Key_idx++;
                AES_VerificationState = ENCRYPTION;
            }
            else if (Valid_AES_Key_idx == (NO_OF_VALID_ENC_DEC_KEYS + NO_OF_VALID_CMAC_KEYS - 1u))
            {
                Cybersecurity_Key_Status = Cybersecurity_Key_Status | AES_Key_status_bit;
                AES_VerificationState = AES_VERIFICATION_IDLE;
            }
            else
            {
                AES_VerificationState = AES_VERIFICATION_IDLE;
            }
        }
        else
        {
            AES_VerificationState = AES_VERIFICATION_IDLE;
        }
        break;
    default:
        /*No action required in default case*/
        break;
    }
    if ((AES_VERIFICATION_IDLE == AES_VerificationState) && (ACTIVE == AES_VerificationStatus))
    {
        AES_VerificationStatus = INACTIVE;
        if (Cybersecurity_FullPASS_status_bit == Cybersecurity_Key_Status)
        {
            Cybersecdiag_CyberSecKeyVerify_RCStatus = eROUTINE_FINISH_OK;
        }
        else
        {
            Cybersecdiag_CyberSecKeyVerify_RCStatus = eROUTINE_FINISH_NOK;
        }
    }
}
#endif
#endif

#ifdef CYBERSECDIAG_SECURE_FUSE_PROGRAMMING
/*=====================================================================================================================
**
** Function Name    :  Cybersecdiag_SecureFuseProgramming_RCStart
**
** Visibility       :  Public
**
** Description      :  Routine Control to program Secure Fuse
**
**
** Invocation       :  MeetMgr.diagcdd  , Function:RC_START_Diag_FEF6
**
** Inputs           :  Data[In]:Key ID,Key Length,Key,Checksum
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Cybersecdiag_SecureFuseProgramming_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    uint16 Calculated_CRC = 0;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        Calculated_CRC = Crc_CalculateCRC16((uint8 *)Data, (uint32)Data[2] + 3u, Crc_StartValue16, TRUE);
        if (Calculated_CRC == ((uint16)(Data[Data[2] + 3u] << 8u) + Data[Data[2] + 4u]))
        {
            ret = Cybersecdiag_SecureFuseConfig.CybersecDiag_Secure_Fuse_Programming(Data, ErrorCode);
            if (ret != DCM_E_PENDING)
            {
                if (DCM_E_OK == ret)
                {
                    ret = E_OK;
                    Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_GIP_SECURE_FUSE_RCTYPE, (uint8)0);
                }
                else
                {
                    ret = E_NOT_OK;
                    ErrorCode[0] = DCM_E_GENERALPROGRAMMINGFAILURE; /*failure from GIP side Fuse write*/
                }
            }
        }
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
** Function Name    :  Cybersecdiag_SecureFuse_Reading_RCStart
**
** Visibility       :  Public
**
** Description      :  Routine Control to get fused data of Secure Fuse Programming
**
**
** Invocation       :  MeetMgr.diagcdd , Function:RC_START_Diag_FEF9
**
** Inputs           :  Data[In]: Key ID
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Cybersecdiag_SecureFuse_Reading_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;

    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = Cybersecdiag_SecureFuseConfig.CybersecDiag_Secure_Fuse_Reading(Data, ErrorCode);
        if (ret != DCM_E_PENDING)
        {
            if (DCM_E_OK == ret)
            {
                ret = E_OK;
                Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_GIP_SECURE_FUSE_RCTYPE, (uint8)0);
            }
            else
            {
                ret = E_NOT_OK;
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
 ** Function Name    :  Cybersecdiag_SecureLock_RCStart
 **
 ** Visibility       :  Public
 **
 ** Description      :  Routine Control to lock/unlock Secure Fuse
 **
 **
 ** Invocation       :  MeetMgr.diagcdd  , Function:RC_START_Diag_FEF8
 **
 ** Inputs           :  Data[In]:Key ID,Key
 **					   Errorcode:to be updated with error code if any
 **
 ** Outputs          :  E_OK : Success
 **					   E_NOT_OK: Fail
 **
 ** Critical Section : Yes/No
 **
 **====================================================================================================================*/
Std_ReturnType Cybersecdiag_SecureLock_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = Cybersecdiag_SecureLockConfig.CybersecDiag_Secure_Fuse_Programming(Data, ErrorCode);
        if (ret != DCM_E_PENDING)
        {
            if (DCM_E_OK == ret)
            {
                Cybersecdiag_SecureLockProgramming_RCStatus = eROUTINE_INPROGRESS;
                Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_GIP_SECURE_FUSE_LOCK_RCTYPE, (uint8)Cybersecdiag_SecureLockProgramming_RCStatus);
            }
            else
            {
                ret = E_NOT_OK;
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
 ** Function Name    :  Cybersecdiag_SecureLock_RCStart
 **
 ** Visibility       :  Public
 **
 ** Description      :  Routine Control to lock/unlock Secure Fuse
 **
 **
 ** Invocation       :  MeetMgr.diagcdd  , Function:RC_STATUS_Diag_FEF8
 **
 ** Inputs           :  Data[In]:Key ID,Key
 **					   Errorcode:to be updated with error code if any
 **
 ** Outputs          :  E_OK : Success
 **					   E_NOT_OK: Fail
 **
 ** Critical Section : Yes/No
 **
 **====================================================================================================================*/
Std_ReturnType Cybersecdiag_SecureLock_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;

    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        #ifndef CRYPTO_KEY_MANAGEMENT_IMX8
        Cybersecdiag_SecureLockProgramming_RCStatus = eROUTINE_FINISH_OK;
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_GIP_SECURE_FUSE_LOCK_RCTYPE, (uint8)Cybersecdiag_SecureLockProgramming_RCStatus);
        #else
        ret = Cybersecdiag_SecureLockConfig.Cybersecdiag_SecureLock_programmingResult(Data, ErrorCode);
        if (ret != DCM_E_PENDING)
        {
            if (DCM_E_OK == ret)
            {
                Cybersecdiag_SecureLockProgramming_RCStatus = eROUTINE_FINISH_OK;
                Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_GIP_SECURE_FUSE_LOCK_RCTYPE, (uint8)Cybersecdiag_SecureLockProgramming_RCStatus);
            }
            else
            {
                Cybersecdiag_SecureLockProgramming_RCStatus = eROUTINE_FINISH_NOK;
                Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_GIP_SECURE_FUSE_LOCK_RCTYPE, (uint8)Cybersecdiag_SecureLockProgramming_RCStatus);
            }
            ret = E_OK;
        }
        #endif
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
 ** Function Name    :  Cybersecdiag_SecureLock_Read_RCStart
 **
 ** Visibility       :  Public
 **
 ** Description      :  Routine Control to get fused data of Secure Fuse Lock/Unlock
 **
 **
 ** Invocation       :  MeetMgr.diagcdd , Function:RC_START_Diag_FEFA
 **
 ** Inputs           :  Data[In]:Key ID
 **					   Errorcode:to be updated with error code if any
 **
 ** Outputs          :  E_OK : Success
 **					   E_NOT_OK: Fail
 **
 ** Critical Section : Yes/No
 **
 **====================================================================================================================*/
Std_ReturnType Cybersecdiag_SecureLock_Read_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;

    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = Cybersecdiag_SecureLockConfig.CybersecDiag_Secure_Fuse_Reading(Data, ErrorCode);
        if (ret != DCM_E_PENDING)
        {
            if (DCM_E_OK == ret)
            {
                ret = E_OK;
                Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_GIP_SECURE_FUSE_LOCK_RCTYPE, (uint8)0);
            }
            else
            {
                ret = E_NOT_OK;
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
#endif

#ifdef CYBERSECDIAG_SYMMETRIC_KEY_PROGRAMMING
/*=====================================================================================================================
**
** Function Name    :  Cybersecdiag_SymmetricKeyProgramming_RCStart
**
** Visibility       :  Public
**
** Description      :  Starts Routine Control to Symmetric Key Programming
**
**
** Invocation       :  MeetMgr.diagcdd  , Function:RC_START_Diag_FEF7
**
** Inputs           :  Data[In]:Key ID,Key Length,Key,Checksum
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Cybersecdiag_SymmetricKeyProgramming_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    uint16 Calculated_CRC = 0;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        Calculated_CRC = Crc_CalculateCRC16((uint8 *)Data, 33UL, Crc_StartValue16, TRUE);
        if (Calculated_CRC == ((uint16)(Data[33u] << 8u) + Data[34u]))
        {
            if (Cybersecdiag_GIPSymmetricKey_RCStatus == eROUTINE_INPROGRESS)
            {
                // Already Routine in progress
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }
            else
            {
                ret = Cybersecdiag_SymmetricKeyConfig.CybersecDiag_Symmetric_Key_Programming_Start(Data, ErrorCode);
                if (ret != DCM_E_PENDING)
                {
                    if (ret == 0U)
                    {
                        Cybersecdiag_GIPSymmetricKey_RCStatus = eROUTINE_FINISH_OK;
                    }
                    else
                    {
                        Cybersecdiag_GIPSymmetricKey_RCStatus = eROUTINE_FINISH_NOK;
                    }
                    /*For a Type2 routine for standardization, Start routine will always return "IN_PROGRESS" status.
                    Only in Result routine,actual status will get reflected.*/
                    Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_GIP_SYMMETRIC_KEY_RCTYPE, (uint8)eROUTINE_INPROGRESS);
                    ret = E_OK;
                }
            }
        }
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
** Function Name    :  Cybersecdiag_SymmetricKeyProgramming_RCStatus
**
** Visibility       :  Public
**
** Description      :  Gives Routine Control Status of Symmetric Key Programming
**
**
** Invocation       :  MeetMgr.diagcdd , Function:RC_RESULTS_Diag_FEF7
**
** Inputs           :  Data[Out]: status of Routine Control of Symmetric key Programming
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Cybersecdiag_SymmetricKeyProgramming_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;

    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        if (Cybersecdiag_GIPSymmetricKey_RCStatus != eROUTINE_INACTIVE)
        {
            Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_GIP_SYMMETRIC_KEY_RCTYPE, (uint8)Cybersecdiag_GIPSymmetricKey_RCStatus);
            ret = E_OK;
        }
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
#endif

#ifdef CYBERSECDIAG_BACKUPBANK_VERIFICATION_ONLY_CMAC
//---------------------------------------------------------------------------------------------------------------------
/// @brief Cybersecdiag_backUpbankVerification_only_CMAC
///
/// @arg  void
///
/// @return void
///< br>
//---------------------------------------------------------------------------------------------------------------------
void Cybersecdiag_backUpbankVerification_only_CMAC(void)
{
    Std_ReturnType Decrypt_ret = E_NOT_OK;
    boolean Compare_ret = FALSE;
    switch (BackUpBankVerify_State)
    {
    case DECRYPT_HYPERFLASH_DATA:
        Current_Hyperflash_StartAddr = HYPERFLASH_CMAC_ADDRESS;
        MemLib_MemCpy(&Encbuffer[0], (uint8 *)Current_Hyperflash_StartAddr, DecCMAC_Length);

        /* Below function is commented. Use as per the requirements.
         * Decrypt_ret = CYBERSECDIAG_DECRYPT(Decryption_Job_ID, 7,&Encbuffer[0], DecCMAC_Length,  &DecResult[0], &DecResultLen_OnlyCMAC); */

        if (E_OK == Decrypt_ret)
        {
            Decrypt_status = DECRYPTION_INPROGRESS;
            BackUpBankVerify_State = COMPARE_WITH_INTERNALFLASH;
        }
        else
        {
            Cybersecdiag_BackupBankVerif_RCStatus = eROUTINE_FINISH_NOK;
            BackUpBankVerify_State = IDLE;
        }
        break;

    case COMPARE_WITH_INTERNALFLASH:
        if (DECRYPTION_COMPLETED == Decrypt_status)
        {
            Current_InternalFlash_StartAddr = INTERNALFLASH_CMAC_ADDRESS;
            Compare_ret = MemLib_MemCmp((uint8 *)Current_InternalFlash_StartAddr, (uint8 *)DecResult, DecCMAC_Length);
            if (TRUE == Compare_ret)
            {
                Cybersecdiag_BackupBankVerif_RCStatus = eROUTINE_FINISH_OK;
                BackUpBankVerify_State = IDLE;
            }
            else
            {
                Cybersecdiag_BackupBankVerif_RCStatus = eROUTINE_FINISH_NOK;
                BackUpBankVerify_State = IDLE;
            }
        }
        else if (DECRYPTION_FAILED == Decrypt_status)
        {
            Cybersecdiag_BackupBankVerif_RCStatus = eROUTINE_FINISH_NOK;
            BackUpBankVerify_State = IDLE;
        }
        else
        {
            /*No action required*/
        }

        break;

    case IDLE:
        break;

    default:
        /*No action required in default case*/
        break;
    }
}
#endif

#ifdef CYBERSECDIAG_BACKUPBANK_VERIFICATION
#ifndef CRYPTO_KEY_MANAGEMENT_IMX8
//---------------------------------------------------------------------------------------------------------------------
/// @brief Cybersecdiag_backUpbankVerification
///
/// @arg  void
///
/// @return void
///< br>
//---------------------------------------------------------------------------------------------------------------------
void Cybersecdiag_backUpbankVerification(void)
{
    Std_ReturnType Decrypt_ret = E_NOT_OK;
    boolean Compare_ret = FALSE;

    switch (BackUpBankVerify_State)
    {
    case DECRYPT_HYPERFLASH_DATA:
        if (BackUpBankPeriodic_CurrentCount < BackUpBankPeriodic_TotalCount)
        {
            Current_Hyperflash_StartAddr = HYPERFLASH_FOTA_START_ADDRESS + (uint32)(BackUpBankPeriodic_CurrentCount * DecLength);
            MemLib_MemCpy(&Encbuffer[0], (uint8 *)Current_Hyperflash_StartAddr, DecLength);

            /* Below function is commented. Use as per the requirements.
             * Decrypt_ret = CYBERSECDIAG_DECRYPT(Decryption_Job_ID, 7u,&Encbuffer[0], DecLength,  &DecResult[0], &DecResultLen); */

            if (E_OK == Decrypt_ret)
            {
                Decrypt_status = DECRYPTION_INPROGRESS;
                BackUpBankVerify_State = COMPARE_WITH_INTERNALFLASH;
            }
            else
            {
                Cybersecdiag_BackupBankVerif_RCStatus = eROUTINE_FINISH_NOK;
                BackUpBankPeriodic_CurrentCount = 0u;
                BackUpBankVerify_State = IDLE;
            }
        }
        else
        {
            Cybersecdiag_BackupBankVerif_RCStatus = eROUTINE_FINISH_NOK;
            BackUpBankPeriodic_CurrentCount = 0u;
            BackUpBankVerify_State = IDLE;
        }
        break;
    case COMPARE_WITH_INTERNALFLASH:
        if (DECRYPTION_COMPLETED == Decrypt_status)
        {
            /*The IV to decrypt next block is the last 16 bytes of previous block*/
            MemLib_MemCpy(&IVectorData[0], &Encbuffer[240], 16u);

            /* Below function is commented. Use as per the requirements.
             * (void)CYBERSECDIAG_KEY_ELEMENT_SET(Enc_Dec_Key_ID, CRYPTO_KE_CIPHER_IV,&IVectorData[0],16u); */

            /* Below function is commented. Use as per the requirements.
             * (void)CYBERSECDIAG_KEY_SET_VALID(Enc_Dec_Key_ID); */

            Current_InternalFlash_StartAddr = INTERNALFLASH_FOTA_START_ADDRESS + (uint32)(BackUpBankPeriodic_CurrentCount * DecLength);
            Compare_ret = MemLib_MemCmp((uint8 *)Current_InternalFlash_StartAddr, (uint8 *)DecResult, PERIODIC_DECRYPT_LENGTH);
            if (TRUE == Compare_ret)
            {
                if (BackUpBankPeriodic_CurrentCount == (BackUpBankPeriodic_TotalCount - 1u))
                {
                    Cybersecdiag_BackupBankVerif_RCStatus = eROUTINE_FINISH_OK;
                    BackUpBankPeriodic_CurrentCount = 0u;
                    BackUpBankVerify_State = IDLE;
                }
                else
                {
                    BackUpBankPeriodic_CurrentCount++;
                    BackUpBankVerify_State = DECRYPT_HYPERFLASH_DATA;
                }
            }
            else
            {
                Cybersecdiag_BackupBankVerif_RCStatus = eROUTINE_FINISH_NOK;
                BackUpBankPeriodic_CurrentCount = 0u;
                BackUpBankVerify_State = IDLE;
            }
        }
        else if (DECRYPTION_FAILED == Decrypt_status)
        {
            Cybersecdiag_BackupBankVerif_RCStatus = eROUTINE_FINISH_NOK;
            BackUpBankPeriodic_CurrentCount = 0u;
            BackUpBankVerify_State = IDLE;
        }
        else
        {
            /*No action required*/
        }
        break;
    case IDLE:
        break;
    default:
        /*No action required in default case*/
        break;
    }
}
#endif
#endif

#if (defined(CYBERSECDIAG_BACKUPBANK_VERIFICATION_ONLY_CMAC) || defined(CYBERSECDIAG_BACKUPBANK_VERIFICATION))
/*=====================================================================================================================
**
** Function Name    :  Cybersecdiag_Backup_bank_verification_RCStart
**
** Visibility       :  Public
**
** Description      :  Starts Routine Control to verify backup bank
**
**
** Invocation       :  MeetMgr.diagcdd  , Function:RC_START_Diag_FEFB
**
** Inputs           :  Data[In]:
**                     Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**                     E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Cybersecdiag_Backup_bank_verification_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        #ifndef CRYPTO_KEY_MANAGEMENT_IMX8
        if (Cybersecdiag_BackupBankVerif_RCStatus == eROUTINE_INPROGRESS)
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
        else
        {
        #ifndef CYBERSECDIAG_BACKUPBANK_VERIFICATION_ONLY_CMAC
            MemLib_MemCpy(&IVectorData[0], (uint8 *)Initial_IV_Addr, 16);
        #else
            MemLib_MemCpy(&IVectorData[0], (uint8 *)Initial_IV_Addr_onlyCMAC, 16);
        #endif
            /* Below function is commented. Use as per the requirements.
             * (void)CYBERSECDIAG_KEY_ELEMENT_SET(Enc_Dec_Key_ID, CRYPTO_KE_CIPHER_IV,&IVectorData[0],16); */

            /* Below function is commented. Use as per the requirements.
             * (void)CYBERSECDIAG_KEY_SET_VALID(Enc_Dec_Key_ID); */

            BackUpBankVerify_State = DECRYPT_HYPERFLASH_DATA;
            Cybersecdiag_BackupBankVerif_RCStatus = eROUTINE_INPROGRESS;
            Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_BACKUP_BANK_VERIFY_RCTYPE, (uint8)Cybersecdiag_BackupBankVerif_RCStatus);
            ret = E_OK;
        }
        #else
        ret = Cybersecdiag_BackupBankConfig.BackupBank_Programming_Start(Data, ErrorCode);
        if (ret != DCM_E_PENDING)
        {
            if (DCM_E_OK == ret)
            {
                ret = E_OK;
                Cybersecdiag_Backup_bankVerificationStatus = (uint8)eROUTINE_INPROGRESS;
                Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_BACKUP_BANK_VERIFY_RCTYPE, (uint8)Cybersecdiag_Backup_bankVerificationStatus);
            }
            else
            {
                ErrorCode[0] = DCM_E_GENERALPROGRAMMINGFAILURE;
            }
        }
        #endif
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
** Function Name    :  Cybersecdiag_Backup_bank_verification_RCStatus
**
** Visibility       :  Public
**
** Description      :  Gives Routine Control Status of backup bank verification
**
**
** Invocation       :  MeetMgr.diagcdd , Function:RC_RESULTS_Diag_FEFB
**
** Inputs           :  Data[Out]: status of Routine Control to store backup bank verification status
**                     Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**                     E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Cybersecdiag_Backup_bank_verification_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        #ifndef CRYPTO_KEY_MANAGEMENT_IMX8
        if (DECRYPTION_FAILED == Decrypt_status)
        {
            *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
        }
        else
        #else
        {
            ret = Cybersecdiag_BackupBankConfig.BackupBank_Programming_Result(Data, ErrorCode);
            if (ret != DCM_E_PENDING)
            {
                if (DCM_E_OK == ret)
                {
                    Cybersecdiag_Backup_bankVerificationStatus = (uint8)eROUTINE_FINISH_OK;
                    Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_BACKUP_BANK_VERIFY_RCTYPE, (uint8)Cybersecdiag_Backup_bankVerificationStatus);
                }
                else
                {
                    Cybersecdiag_Backup_bankVerificationStatus = (uint8)eROUTINE_FINISH_NOK;
                    Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_BACKUP_BANK_VERIFY_RCTYPE, (uint8)Cybersecdiag_Backup_bankVerificationStatus);
                }
            }
        }
        #endif
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    #ifndef CRYPTO_KEY_MANAGEMENT_IMX8
    Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_BACKUP_BANK_VERIFY_RCTYPE, (uint8)Cybersecdiag_Backup_bankVerificationStatus);
    #endif
    return ret;
}
#endif

#ifdef CYBERSECDIAG_ENCRYPT_DECRYPT_NOTIFYHANDLER
/*=====================================================================================================================
**
** Function Name    :  CybersecDiag_DecryptionNotifyHandler
**
** Visibility       :  Public
**
** Description      :  Gives Decryption status
**
**
** Invocation       :  Crywrapper.c , Function:CsmCryWrapperDecryptionStatus
**
** Inputs           :  Data[In]: status of Decryption
**
** Outputs          :
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
void CybersecDiag_DecryptionNotifyHandler(uint8 Data)
{
    if (E_OK == Data)
    {
        if (DECRYPTION_INPROGRESS == Decrypt_status)
        {
            Decrypt_status = DECRYPTION_COMPLETED;
        }
    }
    else
    {
        if (DECRYPTION_INPROGRESS == Decrypt_status)
        {
            Decrypt_status = DECRYPTION_FAILED;
        }
    }
}
/*=====================================================================================================================
**
** Function Name    :  CybersecDiag_EncryptionNotifyHandler
**
** Visibility       :  Public
**
** Description      :  Gives Encryption status
**
**
** Invocation       :  Crywrapper.c , Function:CsmCryWrapperEncryptionStatus
**
** Inputs           :  Data[In]: status of Encryption
**
** Outputs          :
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
void CybersecDiag_EncryptionNotifyHandler(uint8 Data)
{
    if (E_OK == Data)
    {
        if (ENCRYPTION_INPROGRESS == Encrypt_status)
        {
            Encrypt_status = ENCRYPTION_COMPLETED;
        }
    }
    else
    {
        if (ENCRYPTION_INPROGRESS == Encrypt_status)
        {
            Encrypt_status = ENCRYPTION_FAILED;
        }
    }
}
#endif

#ifdef CYBERSECDIAG_SHESLOTS_READ
/*=====================================================================================================================
**
** Function Name    :  CybersecDiag_SHESlots_Read
**
** Visibility       :  Public
**
** Description      :  This function reads the M4/M5 of SlotX(*1).
** 					   This shall be used to confirm the written key when the record of its keys is lost.
**
** Invocation       :  Cybersecdiagcdd.c , Function: CybersecDiag_SHESlots_Read
**
** Inputs           :  Data[In]: M4/M5 slot number
**
** Outputs          :  Data[Out]: Read key
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType CybersecDiag_SHESlots_Read(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = CybersecDiag_SHESlotsConfig.WrittenKey_Read(Data, ErrorCode);
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef CYBERSECDIAG_CSM_SAFE_KEY_NUMBER
/*=====================================================================================================================
**
** Function Name    :  Cybersecdiag_SafeKey_Write
**
** Visibility       :  Public
**
** Description      :  Write Safe Key Number
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_010B
**
** Inputs           :  Data[In]: 16 Bytes
**                     Errorcode: To be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**					   CRYPTO_BUSY: Pending
**
**====================================================================================================================*/
Std_ReturnType Cybersecdiag_SafeKey_Write(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        switch (Cybersecdiag_KeyElementWriteState)
        {
        case eKeyElementSet_Request:

            ret = Cybersecdiag_SafeKeyNumberConfig.CybersecDiag_SafeKey_Number_Write(Data);

            if ((uint8)E_NOT_OK == ret)
            {
                *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE; /*failure from CSM side : write failed */
                ret = DCM_E_NOT_OK;
            }
            else if ((uint8)E_OK == ret)
            {
                Cybersecdiag_KeyElementWriteState = eKeyElementSet_Valid;
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = DCM_E_PENDING;
            }
            break;
        case eKeyElementSet_Valid:

            ret = Cybersecdiag_SafeKeyNumberConfig.CybersecDiag_SafeKey_Number_SetStatus(Data);

            if ((uint8)E_NOT_OK == ret)
            {
                Cybersecdiag_KeyElementWriteState = eKeyElementSet_Request;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                ret = DCM_E_NOT_OK;
            }
            else if ((uint8)E_OK == ret)
            {
                Cybersecdiag_KeyElementWriteState = eKeyElementSet_Request;
                ret = DCM_E_OK;
            }
            else
            {
                ret = DCM_E_PENDING;
            }
            break;
        default:
            ret = DCM_E_OK;
            break;
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
** Function Name    :  Cybersecdiag_SafeKey_Read
**
** Visibility       :  Public
**
** Description      :  Read Safe Key Number
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_010B
**
** Inputs           :  Data[In]
**                     Errorcode: To be updated with error code if any
**
** Outputs          :  Data[out] : 16 Bytes
**					   E_OK : Success
**					   E_NOT_OK: Fail
**
**====================================================================================================================*/
Std_ReturnType Cybersecdiag_SafeKey_Read(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Cybersecdiag_SafeKeyNumberConfig.CybersecDiag_SafeKey_Number_Read(Data, ErrorCode);
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef CYBERSECDIAG_JTAG_PASSWORD_ROUTINE_LOCK_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Cybersecdiag_JtagPasswordLock_RCStart
**
** Visibility       :  Public
**
** Description      :  Starts routine to lock Jtag
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In]: Key ID,Key Length,Key,Checksum
**                     Errorcode: To be updated with error code if any
**
** Outputs          :  E_OK : Success
**                     E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Cybersecdiag_JtagPasswordLock_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        if (eROUTINE_INPROGRESS == Cybersecdiag_JtagPswdLock_RCStatus)
        {
            /*Already Routine In-progress*/
            *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
        }
        else
        {
            ret = Cybersecdiag_JtagPswdLockRoutineConfig.JtagPswdLockRoutine_Start(Data, ErrorCode);

            if(ret == (uint8)E_OK)
            {
                Cybersecdiag_JtagPswdLock_RCStatus = eROUTINE_INPROGRESS;
            }
            
            /* Start routine will always return "IN_PROGRESS" status, Only in result routine, actual status will get reflected */
            Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_JTAGPASSWORDLOCK_RCTYPE, (uint8)Cybersecdiag_JtagPswdLock_RCStatus);
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
** Function Name    :  Cybersecdiag_JtagPasswordLock_RCStatus
**
** Visibility       :  Public
**
** Description      :  Result routine to get result of Jtag lock
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In]: Key ID,Key Length,Key,Checksum
**                     Errorcode: To be updated with error code if any
**
** Outputs          :  E_OK : Success
**                     E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Cybersecdiag_JtagPasswordLock_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        if (eROUTINE_INACTIVE != Cybersecdiag_JtagPswdLock_RCStatus)
        {
            ret = Cybersecdiag_JtagPswdLockRoutineConfig.JtagPswdLockRoutine_Status(Data, ErrorCode);

            if (ret == (uint8)E_OK)
            {
                Cybersecdiag_JtagPswdLock_RCStatus = eROUTINE_FINISH_OK;
            }
            else if (ret == (uint8)E_NOT_OK)
            {
                Cybersecdiag_JtagPswdLock_RCStatus = eROUTINE_FINISH_NOK;
            }
            else
            {
                /*No action required. RC status is in-progress*/
            }
        }
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_JTAGPASSWORDLOCK_RCTYPE, (uint8)Cybersecdiag_JtagPswdLock_RCStatus);
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

#ifdef CYBERSECDIAG_JTAG_PASSWORD_WRITE_LOCK_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Cybersecdiag_JTAG_passwordProtection_Write
**
** Visibility       :  Public
**
** Description      :  Write Jtag Password to lock the Jtag Port
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FD0D
**
** Inputs           :  Data[In]:56 Bytes (safe Key Number - 16 Bytes and Encrypted Blob - 40 Bytes)
**                     Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
**====================================================================================================================*/
Std_ReturnType Cybersecdiag_JTAG_passwordProtection_Write(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        switch (Cybersecdiag_JtagPasswordState)
        {
        case eJtag_VerfitySafeKeyNum:

            /* Verify Safe Key Number Stored in M0 */
            ret = Cybersecdiag_JtagPasswordLockingConfig.VerifySafekeyNumber(Data, ErrorCode);

            if ((uint8)E_NOT_OK == ret)
            {
                ret = DCM_E_NOT_OK;
            }
            else if ((uint8)E_OK == ret)
            {
                Cybersecdiag_JtagPasswordState = eJtag_PasswordWrite;
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = DCM_E_PENDING;
            }
            break;

        case eJtag_PasswordWrite:

            ret = Cybersecdiag_JtagPasswordLockingConfig.JtagPasswordLock_Write(Data, ErrorCode);

            if ((uint8)E_NOT_OK == ret)
            {
                Cybersecdiag_JtagPasswordState = eJtag_VerfitySafeKeyNum;
                ret = DCM_E_NOT_OK;
            }
            else if ((uint8)E_OK == ret)
            {
                Cybersecdiag_JtagPasswordState = eJtag_VerfitySafeKeyNum;
                ret = DCM_E_OK;
            }
            else
            {
                ret = DCM_E_PENDING;
            }
            break;

        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef CYBERSECDIAG_JTAG_PASSWORD_READ_LOCK
/*=====================================================================================================================
**
** Function Name    :  Cybersecdiag_JTAG_passwordProtection_Status
**
** Visibility       :  Public
**
** Description      :  Read Jtag Port status
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FD0D
**
** Inputs           :  Data[In]
**                     Errorcode: To be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**====================================================================================================================*/
Std_ReturnType Cybersecdiag_JTAG_passwordProtection_Status(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Cybersecdiag_JtagPasswordLockingConfig.JtagPasswordLock_Status(Data, ErrorCode);
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef CYBERSECDIAG_SECURE_SYMMETRIC_KEY_PROGRAMMING
/*=====================================================================================================================
**
** Function Name    :  Cybersecdiag_SecureSymmetricKeyProgramming_RCStart
**
** Visibility       :  Public
**
** Description      :  Starts Routine Control to Symmetric Key Programming
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In]: Key ID,Key Length,Key,Checksum
**					   Errorcode: To be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Cybersecdiag_SecureSymmetricKeyProgramming_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    uint16 Calculated_CRC = 0U;
    uint16 CRC_Provided = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        if (eROUTINE_INPROGRESS == Cybersecdiag_SecureSymmetricKey_RCStatus)
        {
            /*Already Routine In-progress*/
            *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
        }
        else
        {
            Calculated_CRC = Crc_CalculateCRC16((uint8 *)Data, (CYBERSECDIAG_KEY_PROGRAMMING_LENGTH + CYBERSECDIAG_ADDITIONALBYTES_LENGTH), Crc_StartValue16, TRUE);

            CRC_Provided = (((uint16)Data[CYBERSECDIAG_CRC_RECIEVED] << 8U) + Data[CYBERSECDIAG_CRC_RECIEVED + 1U]);

            if (Calculated_CRC == CRC_Provided)
            {
                ret = Cybersecdiag_SecureSymmetricKeyConfig.CybersecDiag_SecureSymmetric_Key_Programming_Start(Data, ErrorCode);
                Cybersecdiag_SecureSymmetricKey_RCStatus = eROUTINE_INPROGRESS;

                /* Start routine will always return "IN_PROGRESS" status, Only in Result routine,actual status will get reflected */
                Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_SECURE_SYMMETRIC_KEY_RCTYPE, (uint8)Cybersecdiag_SecureSymmetricKey_RCStatus);
            }
            else
            {
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }
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
** Function Name    :  Cybersecdiag_SecureSymmetricKeyProgramming_RCStatus
**
** Visibility       :  Public
**
** Description      :  Gives Routine Control Status of Symmetric Key Programming
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[Out]: Status of Routine Control of Symmetric key Programming
**					   Errorcode: To be updated with error code if any
**
** Outputs          :  E_OK : Success
**                     E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Cybersecdiag_SecureSymmetricKeyProgramming_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        if (eROUTINE_INACTIVE != Cybersecdiag_SecureSymmetricKey_RCStatus)
        {
            ret = Cybersecdiag_SecureSymmetricKeyConfig.CybersecDiag_SecureSymmetric_Key_Programming_Result(Data, ErrorCode);

            if (ret == (uint8)E_OK)
            {
                Cybersecdiag_SecureSymmetricKey_RCStatus = eROUTINE_FINISH_OK;
            }
            else if (ret == (uint8)E_NOT_OK)
            {
                Cybersecdiag_SecureSymmetricKey_RCStatus = eROUTINE_FINISH_NOK;
            }
            else
            {
                /*No action required. RC status is in-progress*/
            }
        }
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_SECURE_SYMMETRIC_KEY_RCTYPE, (uint8)Cybersecdiag_SecureSymmetricKey_RCStatus);
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

#ifdef CYBERSECDIAG_SYMMETRIC_KEY_VERIFICATION
/*=====================================================================================================================
**
** Function Name    :  Cybersecdiag_Symmetrickey_Verification_RCStart
**
** Visibility       :  Public
**
** Description      :  Starts Routine Control to verify all cybersecurity keys
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In]:
**                     Errorcode: To be updated with error code if any
**
** Outputs          :  E_OK : Success
**                     E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Cybersecdiag_Symmetrickey_Verification_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        if (eROUTINE_INPROGRESS == Cybersecdiag_SymmetricKeyVerfication_RCStatus)
        {
            /*Already Routine In-progress*/
            *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
        }
        else
        {
            ret = Cybersecdiag_SymmetricKeyVerify.SymmetricKey_Verification_Start(Data, ErrorCode);
            Cybersecdiag_SymmetricKeyVerfication_RCStatus = eROUTINE_INPROGRESS;

            /* Start routine will always return "IN_PROGRESS" status, Only in Result routine,actual status will get reflected */
            Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_KEY_VERIFICATION_RCTYPE, (uint8)Cybersecdiag_SymmetricKeyVerfication_RCStatus);
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
** Function Name    :  Cybersecdiag_SymmetricKey_Verification_RCStatus
**
** Visibility       :  Public
**
** Description      :  Gives Routine Control Status of Cybersecurity keys verification
**
** Invocation       :  MeetMgr.diagcdd , Function:RC_RESULTS_Diag_FEFC
**
** Inputs           :  Data[Out]: Status of Routine Control to verify all Ceybersecurity Keys
**                     Errorcode: To be updated with error code if any
**
** Outputs          :  E_OK : Success
**                     E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Cybersecdiag_SymmetricKey_Verification_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        if (eROUTINE_INACTIVE != Cybersecdiag_SymmetricKeyVerfication_RCStatus)
        {
            ret = Cybersecdiag_SymmetricKeyVerify.SymmetricKey_Verification_Status(Data, ErrorCode);
            if (ret == (uint8)E_OK)
            {
                Cybersecdiag_SymmetricKeyVerfication_RCStatus = eROUTINE_FINISH_OK;
            }
            else
            {
                Cybersecdiag_SymmetricKeyVerfication_RCStatus = eROUTINE_FINISH_NOK;
            }
        }
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CYBERSECDIAG_KEY_VERIFICATION_RCTYPE, (uint8)Cybersecdiag_SymmetricKeyVerfication_RCStatus);
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
** Date              :  02/05/2024
** CDSID             :  ddanecha
** Traceability      :  JIRA TCID31491-3053
** Change Description:  Added routine service for Jtag lock
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/09/2023
** CDSID             :  mprajapa
** Traceability      :  JIRA 3839
** Change Description:  Upddated identation.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  26/May/2023
** CDSID             :  spalan11
** Traceability      :  RTC - 2021383
** Change Description:  New feature implemented UART UNLOCK
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  03/Jan/2023
** CDSID             :  ddanecha
** Traceability      :  RTC - 1870396
** Change Description:  SafeKeyNumber Read/write, Secure key programming and verification interfaces added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  19/Dec/2022
** CDSID             :  ddanecha
** Traceability      :  RTC - 1857302
** Change Description:  Interface added to read M4M5 slots.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  14/Dec/2022
** CDSID             :  ddanecha
** Traceability      :  RTC - 1855833
** Change Description:  Restructured Cybersecdiagcdd interfaces. Binded all interfaces with unique Macros.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  03/Aug/2022
** CDSID             :  mpandey2
** Traceability      :  RTC - 1729486
** Change Description:  Key Verification Routine Start is updated as per updated requirements
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  19/Jul/2022
** CDSID             :  mpandey2
** Traceability      :  RTC - 1717947
** Change Description:  Secure Lock  Routine Result Service added and implemented .
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  19/Jul/2022
** CDSID             :  mpandey2
** Traceability      :  RTC - 1717947
** Change Description:  Backup Bank Routine Result Service added .
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  23/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1634375
** Change Description:  Coverity/MISRA Fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  18/Aug/2021
** CDSID             :  razhakes, rmunisa1
** Traceability      :  RTC - 1344039
** Change Description:  Adaptation to Mazda J30 program
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  16/April/2021
** CDSID             :  razhakes
** Traceability      :  RTC - 1214721
** Change Description:  New feature implemented JTAG_LOCK_ENABLE
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  30/Mar/2021
** CDSID             :  vkathir1
** Traceability      :  RTC-1231729
** Change Description:  CYBERSECDIAG_BACKUPBANK_VERIFICATION_ONLY_CMAC macro added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  30/Oct/2020
** CDSID             :  razhakes
** Traceability      :  RTC-1105439
** Change Description:  Static Analysis
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  28/Oct/2020
** CDSID             :  razhakes
** Traceability      :  RTC-1105439
** Change Description:  Static Analysis
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  03/Sep/2020
** CDSID             :  razhakes
** Traceability      :  RTC-997553
** Change Description:  Replace all CSM APIs and Type variables with Macro
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  03/Aug/2020
** CDSID             :  razhakes
** Traceability      :  RTC-880214, RTC-880217, RTC-880210
** Change Description:  Cybersecurity Key verification and backup bank verification implementation, CRC calculation addition to all Cybersecurity DIDs
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  10/March/2020
** CDSID             :  razhakes and dkasiman
** Traceability      :  RTC-760543
** Change Description:  Initial version of security DID implementation
**====================================================================================================================*/
#endif /* CYBERSECDIAGCDD_C */
