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
** Name:           ShareDiagcdd_cfg.h
**
** Description:    
**                
**
**====================================================================================================================*/
#ifndef SHAREDIAGCDDCFG_H
#define SHAREDIAGCDDCFG_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/
#include "Std_Types.h"
#include "Mgrdiagcdd_cfg.h"
#include "Trusted_Functions.h"

extern char __ghs_tcmram_code_start[];
/*====================================================================================================================
** CONTROLLER SPECIFIC PARAMETERS **
==================================================================================================================== */
 
#define CA0_OFFSET                              0xAA8
#define CA1_OFFSET                              0x554
#define TCFLASH_KEY_UNLOCK                      0xCF61F1A5
#define FCFG_WRITE_EN_USED                      0u
                                                     
#define SHAREDIAG_NVM_BLOCK_0_START_ADDRESS     0x19F2000UL
#define SHAREDIAG_NVM_BLOCK_1_START_ADDRESS     0x19F4000UL
#define SHAREDIAG_ROM_DEFAULT_START_ADDRESS     0x19FFE00UL
#define SHAREDIAG_CODE_EXECUTE_START_ADDRESS    (uint32)__ghs_tcmram_code_start 

#define SHAREDIAG_SECURITY_MARKER_START_ADDRESS    0x19F0000UL

#define SHAREDIAG_GRANULARITY_BYTES ((uint8)16UL)
#define SHAREDIAG_ERASED_VALUE      ((uint8)0xFFU)
#define SHAREDIAG_FIRST_FLASH       ((uint8)0xA5U)
#define SHAREDIAG_NOT_TESTED_STATE  ((uint8)0x10U)
#define SHAREDIAG_MASK_RESET_MPU_ENABLE   ((uint32)0xFFFFFFFE)

#define SHAREDIAG_NVM_PAGE_SIZE     (8192U)

/* Modify this function as required e.g.Call_MeetcddProcess	*/

/*====================================================================================================================
** SERVICE SPECIFIC PARAMETERS **
==================================================================================================================== */

//#define SHAREDIAG_ENABLE_1          /* Define this if the service is enabled */
//#define SHAREDIAG_ENABLE_2          /* Define this if the service is enabled */
//#define SHAREDIAG_ENABLE_3          /* Define this if the service is enabled */

#define SHAREDIAG_CHECKFLASH_ACCESS_FUNC_CALL         TrustF_Call_ShareDiag_CheckFlashAccess
#define SHAREDIAG_FLS_ERASE_FUNC_CALL(x)			  TrustF_Call_ShareDiag_FlsErase(x)
#define SHAREDIAG_TCFLS_WRITE_FUNC_CALL(x,y)		  TrustF_Call_ShareDiag_TCFlsWrite(x,y)
#define SHAREDIAG_TCFLS_WRITE_ENABLE_FUNC_CALL	  	  TrustF_Call_ShareDiag_TCFlsWriteEnable
#define SHAREDIAG_TCFLS_WRITE_DISABLE_FUNC_CALL	 	  TrustF_Call_ShareDiag_TCFlsWriteDisable


#ifdef SHAREDIAG_ENABLE_1
//#define SHAREDIAG_ONE_TIME_WRITE_1     /* Define this macro if write to the NVM is only */
                                         /* allowed one time when erased . 
                                          Second write with different input data will 
                                          result in Negative Response */
#define SHAREDIAG_WRITE_ENABLED_1       /*Define this if write is required for this DID */
#define SHAREDIAG_REAL_SIZE_1       10  /* No of bytes specified in the DID */
#define SHAREDIAG_SIZE_1            (SHAREDIAG_ROUNDUP_VALUE(SHAREDIAG_REAL_SIZE_1))  
#define SHAREDIAG_NVM_ADDRESS_1     ((uint32)0x00000010)  /* Offset address to store the data in the ROM */
#define SHAREDIAG_ADDITIONAL_DATA_REAL_SIZE_1       10  /* No of bytes specified in the DID */
#define SHAREDIAG_ADDITIONAL_DATA_SIZE_1            (SHAREDIAG_ROUNDUP_VALUE(SHAREDIAG_ADDITIONAL_DATA_REAL_SIZE_1))  
#define SHAREDIAG_ADDITIONAL_WRITE_NVM_ADDRESS_1	  ((uint32)0x00000060)
#define SHAREDIAG_ADDITIONAL_DATA_REAL_SIZE_2		10U  /* No of bytes specified in the DID */
#define SHAREDIAG_ADDITIONAL_DATA_SIZE_2            (SHAREDIAG_ROUNDUP_VALUE(SHAREDIAG_ADDITIONAL_DATA_REAL_SIZE_2))  
#define SHAREDIAG_ADDITIONAL_WRITE_NVM_ADDRESS_2	  ((uint32)0x00000050)/* Offset address to store the data in the ROM *///SparePartNumberAddress Renault
#endif


#ifdef SHAREDIAG_ENABLE_2
#define SHAREDIAG_ONE_TIME_WRITE_2     /* Define this macro if write to the NVM is only */
                                         /* allowed one time when erased . 
                                          Second write with different input data will 
                                          result in Negative Response */
#define SHAREDIAG_WRITE_ENABLED_2       /*Define this if write is required for this DID */
#define SHAREDIAG_REAL_SIZE_2       10  /* No of bytes specified in the DID */
#define SHAREDIAG_SIZE_2            (SHAREDIAG_ROUNDUP_VALUE(SHAREDIAG_REAL_SIZE_2))  
#define SHAREDIAG_NVM_ADDRESS_2     ((uint32)0x00000020)  /* Offset address to store the data in the ROM */
#endif


#ifdef SHAREDIAG_ENABLE_3
#define SHAREDIAG_ONE_TIME_WRITE_3     /* Define this macro if write to the NVM is only */
                                       /*   allowed one time when erased . 
                                          Second write with different input data will 
                                          result in Negative Response */
#define SHAREDIAG_WRITE_ENABLED_3       /*Define this macro if write is required for this DID */
#define SHAREDIAG_REAL_SIZE_3       4  /* No of bytes specified in the DID */
#define SHAREDIAG_SIZE_3            (SHAREDIAG_ROUNDUP_VALUE(SHAREDIAG_REAL_SIZE_3))  
#define SHAREDIAG_NVM_ADDRESS_3     ((uint32)0x00000030)  /* Offset address to store the data in the ROM */
#ifdef SHAREDIAG_SERVICE_BOOT_READ
#define SHAREDIAG_REAL_SIZE_BOOT_READ       2  /* No of bytes specified in the DID */
#define SHAREDIAG_SIZE_BOOT_READ            (SHAREDIAG_ROUNDUP_VALUE(SHAREDIAG_REAL_SIZE_BOOT_READ))  
#define SHAREDIAG_NVM_ADDRESS_BOOT_READ     ((uint32)0x00000040)  /* Offset address to store the data in the ROM */
#endif


/*====================================================================================================================
** FUNCTION DEFINITIONS **
==================================================================================================================== */

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///<br>
//---------------------------------------------------------------------------------------------------------------------
boolean ShareDiag_CheckFlashAccess(void);
//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///<br>
//---------------------------------------------------------------------------------------------------------------------
void ShareDiag_HWRefresh(void);
//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///<br>
//---------------------------------------------------------------------------------------------------------------------
boolean ShareDiag_CheckTCFlsReady(void);
//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///<br>
//---------------------------------------------------------------------------------------------------------------------
void ShareDiag_TCFlsWriteDisable(void);
//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///<br>
//---------------------------------------------------------------------------------------------------------------------
void ShareDiag_TCFlsWriteEnable(void);
//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///<br>
//---------------------------------------------------------------------------------------------------------------------
void ShareDiag_TCFlsWrite(uint32 Value, uint32 Address);
//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///<br>
//---------------------------------------------------------------------------------------------------------------------
void ShareDiag_FlsErase(uint32 Address);
//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///<br>
//---------------------------------------------------------------------------------------------------------------------
void HWdg_Refresh(void);
//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///<br>
//---------------------------------------------------------------------------------------------------------------------
void Meet_SetMpuRegions(uint32 access, uint32 address, uint32 reg_number, uint32 size, boolean enable);
//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///<br>
//---------------------------------------------------------------------------------------------------------------------
void Meet_MemoryProtectionReapply(void);
/*=====================================================================================================================
** Date              :  5/Aug/2020
** CDSID             :  razhakes
** Traceability      :  RTC-880207
** Change Description:  Instead of having whole Meetcdd_process() as Trusted function, Trusted fn Macro added for all function call within MeetcddProcess()
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/Mar/2020
** CDSID             :  dkasiman
** Traceability      :  RTC-811699 
** Change Description:  MPU related macros are removed.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  18/Sept/2019
** CDSID             :  razhakes
** Traceability      :  RTC-1370043
** Change Description:  Call_MeetcddProcess() redefined as a MACRO MEETCDD_PROCESS_FUNC_CALL()
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 05/Apr/2019 
** CDSID             : dkasiman
** Traceability      : RTC 1308973
** Change Description: SHAREDIAG_ADDITIONAL_DATA_REAL_SIZE_1,SHAREDIAG_ADDITIONAL_DATA_SIZE_1 and SHAREDIAG_ADDITIONAL_WRITE_NVM_ADDRESS_1 
                       macros are added in Shared memory service 1 updated to support to write in additional location
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  27/Mar/2019 
** CDSID             :  MGANAPAT
** Traceability      :  RTC 1303833
** Change Description: Read boot version function added
**====================================================================================================================*/
#endif /* SHAREDIAGCDDCFG_H */
