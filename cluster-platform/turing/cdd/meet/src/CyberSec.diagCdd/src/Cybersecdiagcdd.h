/*===================================================================================================================
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
**===================================================================================================================
**
** Name:           Cybersecdiagcdd.h
**
** Description:    contains function prototypes for Memory services
**
**
**====================================================================================================================*/
#ifndef CYBERSECDIAGCDD_H
#define CYBERSECDIAGCDD_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/

#include "Cybersecdiagcdd_cfg.h"

#ifdef CYBERSECDIAGCDD_ADAPTER
#include "Cybersecdiagcdd_Adapter.h"
#else
#include "Mgrdiagcdd_cfg.h"
#include "Mgrdiagcdd.h"
#endif
#ifndef CRYPTO_KEY_MANAGEMENT_IMX8
#include "Fls.h" /* EXP37-C CERT FIX - Changed type of length from uint16 to Fls_LengthType, so added necessary header file */
#endif
/*====================================================================================================================
**   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/

/*======================================================================================================================
** T Y P E  D E F I N I T I O N S
**======================================================================================================================*/

/** Shared memory related enums **/
typedef enum
{
    Erase,
    Erase_Wait,
    Program_Header,
    Program_Header_Wait,
    Program_PayLoad,
    Program_PayLoad_Wait,
    Program_Footer,
    Program_Footer_Wait,
    Idle
} EAction;

typedef enum
{
    Undefined,
    Erased,
    Valid,
    Corrupted
} ESectorStatus;

#if defined(CYBERSECDIAG_FLS_ENABLE) || defined(CYBERSECDIAG_SECURE_KEY_WRITE_AES_IV) || defined(CYBERSECDIAG_SECURE_KEY_WRITE_RSA)
typedef enum
{
    UnInit = 0,
    Init,
    Busy,
    Failiure,
    Normal
} Key_StatusType;

typedef struct
{
    ESectorStatus SectorStatus;
    EAction Action;
} Key_Sector_Struct;

typedef struct
{
    uint8 *RamBuffer;
    uint16 Length; /* EXP37-C CERT FIX - Changed type of length from uint16 to Fls_LengthType */
} Key_PayLoad_Struct;

static Key_Sector_Struct AES_IV_Key;
static Key_Sector_Struct RSA_Key;

static Key_PayLoad_Struct AES_IV_key_PayLoad;
static Key_PayLoad_Struct RSA_key_PayLoad;

#endif

#ifdef CYBERSECDIAG_SECURE_KEY_PROGRAMMING_SHE
typedef enum cryptocdd_TestSeq
{
    e_Cybersecdiag_SHE_Idle = 0u,
    e_Cybersecdiag_SHE_LoadKeyPdStart,
    e_Cybersecdiag_SHE_LoadKeyPdStart_main,
    e_Cybersecdiag_SHE_LoadKeyPdUpdate,
    e_Cybersecdiag_SHE_LoadKeyPdUpdate_main,
    e_Cybersecdiag_SHE_LoadKeyPdFinish,
    e_Cybersecdiag_SHE_LoadKeyPdFinish_main,
    e_Cybersecdiag_SHE_done,
    e_Cybersecdiag_SHE_MaxStates
} e_Cybersecdiag_SHE_StateMachine;
#endif

#ifdef CYBERSECDIAG_CSM_SAFE_KEY_NUMBER
typedef enum CyberSecKeyElementWriteRequest
{
    eKeyElementSet_Request,
    eKeyElementSet_Valid
} CyberSecKeyElementWriteStateType;
#endif

#ifdef CYBERSECDIAG_JTAG_PASSWORD_WRITE_LOCK_ENABLE
typedef enum CyberSecJatgPasswordStateRequest
{
    eJtag_VerfitySafeKeyNum,
    eJtag_PasswordWrite
} CyberSecJatgPasswordStateType;
#endif
/*=====================================================================================================================
 *  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
 **===================================================================================================================*/

/*=====================================================================================================================
 *   P U B L I C
 **=====================================================================================================================*/

#ifdef CYBERSECDIAG_SECURE_KEY_PROGRAMMING_AES_IV
Std_ReturnType Cybersecdiag_AES_IV_Key_Storage_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Cybersecdiag_AES_IV_Key_Storage_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef CYBERSECDIAG_SECURE_KEY_PROGRAMMING_RSA
Std_ReturnType Cybersecdiag_RSA_Key_Storage_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Cybersecdiag_RSA_Key_Storage_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef CYBERSECDIAG_SECURE_KEY_WRITE_AES_IV
Std_ReturnType Cybersecdiag_AES_IV_Key_Write(uint8 *Data);
#endif

#ifdef CYBERSECDIAG_SECURE_KEY_WRITE_RSA
Std_ReturnType Cybersecdiag_RSA_Key_Write(uint8 *Data);
#endif

#ifdef CYBERSECDIAG_FLS_ENABLE
Std_ReturnType Cybersecdiag_GET_Fls_WRITE_STATUS(void);
void Cybersecdiag_Fls_Init(void);
void Cybersecdiag_Fls_MainFunction(void);
#endif

#if (defined(CYBERSECDIAG_SECURE_KEY_PROGRAMMING_AES_IV) || defined(CYBERSECDIAG_SECURE_KEY_PROGRAMMING_RSA))
Std_ReturnType Cybersecdiag_CompareArray(uint8 *array1, uint8 *array2, uint16 arraysize);
#endif

#ifdef CYBERSECDIAG_DATA_LOCK_AES_IV
Std_ReturnType Cybersecdiag_AES_IV_Key_lock_unlock_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Cybersecdiag_AES_IV_Key_lock_unlock_Write(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef CYBERSECDIAG_DATA_LOCK_RSA
Std_ReturnType Cybersecdiag_RSA_Key_lock_unlock_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Cybersecdiag_RSA_Key_lock_unlock_Write(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef CYBERSECDIAG_SECURE_KEY_PROGRAMMING_AES
Std_ReturnType Cybersecdiag_AES_Key_Storage_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Cybersecdiag_AES_Key_Storage_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef CYBERSECDIAG_SECURE_KEY_PROGRAMMING_SHE
void Cybersecdiag_She_MainFunction(void);
void Cybersecdiag_SHE_Key_Storage(uint8 *key, uint32 length); /* EXP37-C CERT FIX - Changed type of length from uint8 to uint32 */
#endif

#ifdef CYBERSECDIAG_JTAG_LOCK_ENABLE
Std_ReturnType Cybersecdiag_JTAG_passwordWrite_Lock(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef CYBERSECDIAG_UART_UNLOCK_ENABLE
Std_ReturnType Cybersecdiag_UART_password_UnLock(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef CYBERSECDIAG_CRYPTO_KEY_VERIFICATION
Std_ReturnType Cybersecdiag_key_verification_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Cybersecdiag_Key_verification_RCStatus(uint8 *Data, uint8 *ErrorCode);
void CybersecDiag_AES_Key_Verification_Process(void);
#endif

#ifdef CYBERSECDIAG_SECURE_FUSE_PROGRAMMING
Std_ReturnType Cybersecdiag_SecureFuseProgramming_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Cybersecdiag_SecureFuse_Reading_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Cybersecdiag_SecureLock_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Cybersecdiag_SecureLock_RCStatus(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Cybersecdiag_SecureLock_Read_RCStart(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef CYBERSECDIAG_SYMMETRIC_KEY_PROGRAMMING
Std_ReturnType Cybersecdiag_SymmetricKeyProgramming_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Cybersecdiag_SymmetricKeyProgramming_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef CYBERSECDIAG_BACKUPBANK_VERIFICATION
void Cybersecdiag_backUpbankVerification(void);
#endif

#ifdef CYBERSECDIAG_BACKUPBANK_VERIFICATION_ONLY_CMAC
void Cybersecdiag_backUpbankVerification_only_CMAC(void);
#endif

#if (defined(CYBERSECDIAG_BACKUPBANK_VERIFICATION_ONLY_CMAC) || defined(CYBERSECDIAG_BACKUPBANK_VERIFICATION))
Std_ReturnType Cybersecdiag_Backup_bank_verification_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Cybersecdiag_Backup_bank_verification_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef CYBERSECDIAG_ENCRYPT_DECRYPT_NOTIFYHANDLER
void CybersecDiag_DecryptionNotifyHandler(uint8 Data);
void CybersecDiag_EncryptionNotifyHandler(uint8 Data);
#endif

#ifdef CYBERSECDIAG_SHESLOTS_READ
Std_ReturnType CybersecDiag_SHESlots_Read(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef CYBERSECDIAG_CSM_SAFE_KEY_NUMBER
Std_ReturnType Cybersecdiag_SafeKey_Write(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Cybersecdiag_SafeKey_Read(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef CYBERSECDIAG_JTAG_PASSWORD_ROUTINE_LOCK_ENABLE
Std_ReturnType Cybersecdiag_JtagPasswordLock_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Cybersecdiag_JtagPasswordLock_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif

#if defined(CYBERSECDIAG_JTAG_PASSWORD_WRITE_LOCK_ENABLE) || defined(CYBERSECDIAG_JTAG_PASSWORD_READ_LOCK)
Std_ReturnType Cybersecdiag_JTAG_passwordProtection_Write(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Cybersecdiag_JTAG_passwordProtection_Status(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef CYBERSECDIAG_SECURE_SYMMETRIC_KEY_PROGRAMMING
Std_ReturnType Cybersecdiag_SecureSymmetricKeyProgramming_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Cybersecdiag_SecureSymmetricKeyProgramming_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef CYBERSECDIAG_SYMMETRIC_KEY_VERIFICATION
Std_ReturnType Cybersecdiag_Symmetrickey_Verification_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Cybersecdiag_SymmetricKey_Verification_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif
/*======================================================================================================================
**  for each change to this file, be sure to record:
**  1.who made the change and when the change was made
**  2.why the change was made and the intended result
**  following block needs to be repeated for each change
**====================================================================================================================*/
/*   Note: In the traceability column we need to trace back to the Design Doc.
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
** Date              :  18/Aug/2021
** CDSID             :  razhakes, rmunisa1
** Traceability      :  RTC - 1344039
** Change Description:  Adaptation for Mazda J30.
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
** Date              :  4/Aug/2020
** CDSID             :  razhakes
** Traceability      :  RTC-880214, RTC-880217
** Change Description:  Cybersecurity Key verification and backup bank verification implementation
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  10/March/2020
** CDSID             :  razhakes and dkasiman
** Traceability      :  RTC - 760543
** Change Description:  Initial version of security DID implementation
**====================================================================================================================*/
#endif /* CYBERSECDIAGCDD_H */
