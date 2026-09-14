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
** Name:           Memdiagcdd.h
**
** Description:    contains function prototypes for Memory services
**
**
**====================================================================================================================*/
#ifndef MEMDIAGCDD_H
#define MEMDIAGCDD_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/
#include "Mgrdiagcdd_cfg.h"
#include "Mgrdiagcdd.h"
/*====================================================================================================================
**   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/
#define NVM_VALIDITY_OK                 0x01
#define NVM_VALIDITY_NOT_OK             0x0

#define NVM_VALIDITYCHECK_NONE          (uint8)0
#define NVM_VALIDITYCHECK_START         (uint8)1
#define NVM_VALIDITYCHECK_PROGRESS      (uint8)2
#define NVM_VALIDITYCHECK_DONE          (uint8)3

#define NVM_CONFIGVERIFY_NONE           (uint8)0
#define NVM_CONFIGVERIFY_START          (uint8)1
#define NVM_CONFIGVERIFY_COMPARE        (uint8)2
#define NVM_CONFIGVERIFY_RESULTS        (uint8)3

#define PROGRAM_NVM_FROM_ROM_NONE       (uint8)0
#define PROGRAM_NVM_FROM_ROM_RESTORE    (uint8)1
#define PROGRAM_NVM_FROM_ROM_WRITE      (uint8)2

#define MEM_WRITING_TEST_DATA           0x55
#define TCRAM                           (uint8)1
#define HYPERRAM                        (uint8)8

#define UINT16_MAXIMUMVALUE             (uint16)(0xFFFFU)
/*======================================================================================================================
** T Y P E  D E F I N I T I O N S
**======================================================================================================================*/
typedef enum
{
    eMEMMGR_INACTIVE,
    eMEMMGR_TCRAM_MEM_TEST,
    eMEMMGR_HYPERRAM_MEM_TEST,
} eMemMgrAction;

typedef enum
{
    eNVM_NOT_STARTED = 1,
    eNVM_STARTED,
    eNVM_COMPLETED,
    eNVM_FAILED,
} eNvmStatus;

/*=====================================================================================================================
 *  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
 **===================================================================================================================*/

/*=====================================================================================================================
 *   P U B L I C
 **=====================================================================================================================*/
#ifdef MFGMODEREQENABLE
Std_ReturnType Memdiag_ManufacturingModeRequested_Read(uint8 *Data, const uint8 *ErrorCode);
Std_ReturnType Memdiag_ManufacturingModeRequested_Write(const uint8 *Data, uint8 *ErrorCode);
Std_ReturnType MemDiag_MfgModeRequest_Read(uint16 *Data);
Std_ReturnType MemDiag_MfgModeRequest_Write(uint16 Data, uint8 *ErrorCode);
void MemDiag_Manuf_Flag_Write_Status(void);
Std_ReturnType Memdiag_Write_Mfg_Flag(const uint16 *Data);
#ifdef MFGMODESTATUS
Std_ReturnType Memdiag_Read_ManufModeStatus(EMeetModeStatus *currentstate);
#endif
#endif

#ifdef NVMVALIDITYCHKENABLE
Std_ReturnType Memdiag_NVMValidityCheck_Read(uint8 *Data, uint8 *ErrorCode);
#endif

#if defined(NVMVALIDITYCHKENABLE) || defined(MEMDIAG_MEMORY_VALIDITY_CHECK)
void MemDiag_NVMReadAllBlocks(void);
#endif

#if defined(NVMACCESSBYBLOCKIDREADWRITEENABLE) || defined(EXTNVMACCESSBYBLOCKIDREADWRITEENABLE)
Std_ReturnType Memdiag_DataflashNVMaccessbyblockID_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_DataflashNVMaccessbyblockID_Write(const uint8 *Data, uint8 *ErrorCode);
#endif

#if defined(HYPERFLASHCHKSUMTSTENABLE) || defined(MEMDIAG_MEMORY_VALIDITY_CHECK)
Std_ReturnType Memdiag_HyperflashChecksumTest_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_HyperflashChecksumTest_RCStop(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_HyperflashChecksumTest_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef MEMWRITETESTENABLE
Std_ReturnType Memdiag_MemoryWritingTest_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_MemoryWritingTest_RCStop(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_MemoryWritingTest_RCStatus(uint8 *Data, uint8 *ErrorCode);
void MemDiag_Main_Task(void);
Std_ReturnType MemDiag_MemWritingTest_Start(uint8 *Data, uint8 *ErrorCode, eMemMgrAction MemAction);
#endif

#ifdef NVMACCESSBYBLOCKIDRCENABLE
Std_ReturnType Memdiag_DataflashNVMaccessbyblockID_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_DataflashNVMaccessbyblockID_RCStop(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_DataflashNVMaccessbyblockID_RCStatus(uint8 *Data, uint8 *ErrorCode);
void MemDiag_NVMReadbyBlockIDStatus(void);
#endif

#ifdef PROGRAM_NVM_FROM_ROM
Std_ReturnType Memdiag_Program_NVM_from_ROM_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_Program_NVM_from_ROM_RCStop(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_Program_NVM_from_ROM_RCStatus(uint8 *Data, uint8 *ErrorCode);
void MemDiag_Restoring_NVM_defaultValues(void);
#endif

#ifdef MEMDIAG_MEMORY_VALIDITY_CHECK
Std_ReturnType Memdiag_Memory_Validity_Check_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_Memory_Validity_Check_RCStop(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_Memory_Validity_Check_RCStatus(uint8 *Data, uint8 *ErrorCode);

Std_ReturnType Memdiag_NVMValidityCheck_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_NVMValidityCheck_RCStop(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_NVMValidityCheck_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef MEMDIAG_VIP_GIP_MEMORY_CHECKSUM_TEST
Std_ReturnType Memdiag_VIP_GIP_Memory_Checksum_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_VIP_GIP_Memory_Checksum_RCStop(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_VIP_GIP_Memory_Checksum_RCStatus(uint8 *Data, uint8 *ErrorCode);

Std_ReturnType Memdiag_DisplayMicroROMChecksum_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_DisplayMicro_ROMChecksum_Check_RCStop(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_DisplayMicro_ROMChecksum_Check_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef AUTO_CONFIGURE_OR_VERIFY
Std_ReturnType Memdiag_AutoConfigureorVerify_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_AutoConfigureorVerify_RCStatus(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_AutoConfigureorVerify_RCStop(uint8 *Data, uint8 *ErrorCode);
void MemDiag_NVMConfigureorVerify(void);
#endif

#ifdef MEMDIAG_ODOMETER_NVM_READWRITE
Std_ReturnType Memdiag_OdometerNVMRead(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_OdometerNVMWrite(const uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef MEMDIAG_ODOMETER_NVM_ROUTINE
Std_ReturnType Memdiag_Odometer_NVM_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_Odometer_NVM_RCStop(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_Odometer_NVM_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef NVMACCESSBYADDRESSRCENABLE
Std_ReturnType Memdiag_Data_Write_NVM_Address_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_Data_Write_NVM_Address_RCStatus(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_Data_Read_NVM_Address_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Memdiag_Data_Read_NVM_Address_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif

#endif /* MEMDIAGCDD_H */

/*======================================================================================================================
**  for each change to this file, be sure to record:
**  1.who made the change and when the change was made
**  2.why the change was made and the intended result
**  following block needs to be repeated for each change
**======================================================================================================================*/
/*   Note: In the traceability column we need to trace back to the Design Doc.
**   For the initial version it is traced to the Design Document section.
**   For further changes it shall trace to the source of the change which may
**   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any
**   other reason
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
**======================================================================================================================*/
/*=====================================================================================================================
** Date              :  26/12/2022
** CDSID             :  rsubra13
** Traceability      :  RTC 1861099
** Change Description:  EEPROM Read Write by Address service newly implemented.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  16/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1632871, 1655512, 1660171
** Change Description:  Odometer routine interfaces are added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  9/11/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1365920
** Change Description:  Odometer NVM read write service newly implemented
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
** Traceability      :  RTC-1306675
** Change Description:  Auto configure/verify service added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  02/march/2019
** CDSID             :  razhakes
** Traceability      :  RTC-1262817
** Change Description:  Checksum test VIP - GIP communication added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/7/2018
** CDSID             :  dkasiman
** Traceability      :  RTC-1148640
** Change Description:  Review comments fix:Check program dependency macro/function renamed as Memory validity
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
** Date              :  06/06/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1126958
** Change Description:  removed keyword for function prototypes,comments updated
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
