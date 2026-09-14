/**
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2024. Visteon Corporation owns all rights to
 this work and intends to maintain it in confidence to preserve
 its trade secret status. Visteon Corporation reserves the right,
 under the copyright laws of the United States or those of any
 other country that may have jurisdiction, to protect this work
 as an unpublished work, in the event of an inadvertent or
 deliberate unauthorized publication. Visteon Corporation also
 reserves its rights under all copyright laws to protect this
 work as a published work, when appropriate. Those having access
 to this work may not copy it, use it, modify it or disclose the
 information contained in it without the written authorization
 of Visteon Corporation.
 * @endverbatim
 * @file        FltM_FlsIntegrity.c
 * @details     <b> Fault Manager to handle TI SDL - ESM </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2025
 *
 */
#ifndef  FLTM_SOC_FLSINTEGRITY_C_
#define  FLTM_SOC_FLSINTEGRITY_C_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "FltM_Soc_FlsIntegrity.h"
#include "FltM_Soc_Types.h"
#include "FltM_Soc_Cfg.h"

#define FLTM_SEC_CODE_START
#define FLTM_CORE_CONST_SEC_START
#define FLTM_CORE_DATA_SEC_START
#define FLTM_CORE_BSS_SEC_START

#include "MemMap.h"


#ifdef VIP_UART_TEST
#include "DltExt.h"
#endif

#if(FLTM_FLSINTEGRITY_ENABLE == STD_ON)
/*****************************************************************************
*                            Macro Definitions                                *
******************************************************************************/
#define CHECKSUM_CALCULATION_WORD_JUNKS         (CHECKSUM_CALCULATION_BYTE_JUNKS / 2U)
#define OSTASK_METHOD                           1U
#define RUNNABLE_METHOD                         2U
#define MAX_UINT32 								(0xFFFFFFFFu)
/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

__attribute__((used, section(".textchecksum")))volatile const uint16 g_checksum[1] = {0xFFFFu};
static uint32 CheckSum_Address_Processed = 0u;      /*Offset position within the block*/
static uint32 RegionBlock_Length = 0u;                 /*Length of the Block*/
static uint32 RegionHalfBlock_Length = 0u;                  /*Half Block Length*/
static uint32 CheckSum_TextRegionIdx = 0u;          /*Which descriptor Region are we on */
static uint16 CheckSum_Result = 0u;                 /*Result of ChecksumCalculation*/
static boolean CheckSum_Process = FALSE;            /*Checksum Completion indication*/
static eFltM_FlsIntegrityStatusType Checksum_Status = FLTM_FLSINTEGRITY_NOT_STARTED;

/*============================================================================
**
** Function Name    :   FltM_FlashIntegrity_Init
**
** Visibility       :   Public
**
** Description      :   The Init function is called to initialise the Global
**                      and Static variables of this module.
**
** Invocation       :   FltM_Init
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
Std_ReturnType FltM_FlashIntegrity_Init(void)
{
    Std_ReturnType retVal = E_OK;
    CheckSum_Address_Processed = 0u;                 /*Offset position within the block*/
    RegionBlock_Length = 0u;                         /*Length of the Block*/
    RegionHalfBlock_Length = 0u;                     /*Length of half Block*/
    CheckSum_TextRegionIdx = 0u;                     /*Which descriptor Region are we on */
    CheckSum_Result = 0u;                            /*Result of ChecksumCalculation*/
    CheckSum_Process = FALSE;                        /*Checksum Completion indication*/
    Checksum_Status = FLTM_FLSINTEGRITY_NOT_STARTED; /*Checksum Progress/completion status*/
    return retVal;
}

#if (FLASH_INTEGRITY_CHECKSUMCALCULATE_TYPE == OSTASK_METHOD)
/*============================================================================
**
** Function Name    :   OsTask_FlsIntegrity_Checksum
**
** Visibility       :   Private
**
** Description      :   This task is configured with a priority one level higher 
**                      than the IdleTask. It performs checksum calculation and 
**                      completes within the task execution.
**
** Invocation       :   User configurable option Runnable/Task
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
TASK(OsTask_FlsIntegrity_Checksum)
{
  while (CheckSum_Process == FALSE)
  {
    FltM_FlashIntegrity();
  }
  (void)TerminateTask();
}
#endif

/*============================================================================
**
** Function Name    :   FltM_FlashIntegrity
**
** Visibility       :   Public
**
** Description      :   The function to be invoked for calculating checksum for 
**                      configured text regions
**
** Invocation       :   Runnable/Task
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
boolean FltM_FlashIntegrity(void)
{
    uint32 Block_Start = 0u;
    uint32 Block_End   = 0u;
    uint32 Block_Size  = 0u;
    uint32 ChunkEnd = 0u;
    uint16 *Checksum_DataPtr = NULL;
    uint16 CheckSum_Data = 0u;

    /* ---------- pick current region limits ---------- */
    Block_Start  = FltM_FlsIntegrityConfig[CheckSum_TextRegionIdx].StartAddress;
    Block_End   = FltM_FlsIntegrityConfig[CheckSum_TextRegionIdx].EndAddress;
    Checksum_DataPtr = (uint16 *)(Block_Start);

    if(Block_Start > Block_End)
    {
        FltM_Soc_Det_ReportError(FLTM_CHECKSUMCALCULATE, FLTM_ERR_INVALID_ADDRESS_RANGE);
    }
    else
    {
        Block_Size  = Block_End - Block_Start;
    }
    
    /* when we switch to a new region, reload length */
    if ((RegionBlock_Length == 0u) && (CheckSum_Process == FALSE))
    {
        RegionBlock_Length = Block_Size;
        RegionHalfBlock_Length= RegionBlock_Length/2u;
        CheckSum_Address_Processed = 0u;        /* offset inside this region */
    }

    if (CheckSum_Process == FALSE)
    {
        Checksum_Status = FLTM_FLSINTEGRITY_INPROGRESS;
        if (RegionBlock_Length > 0u)
        {
            if ((MAX_UINT32 - CHECKSUM_CALCULATION_WORD_JUNKS) < CheckSum_Address_Processed)
            {
                ChunkEnd = MAX_UINT32;
            }
            else
            {
                ChunkEnd = CheckSum_Address_Processed + CHECKSUM_CALCULATION_WORD_JUNKS;
            }
            for (uint32 l_incr = CheckSum_Address_Processed; l_incr < ChunkEnd; l_incr++)
            {
                CheckSum_Data = Checksum_DataPtr[l_incr];
                if(l_incr < RegionHalfBlock_Length)
                {
                    CheckSum_Result += CheckSum_Data;
                }
                else
                {
                    /*Do Nothing*/
                }
            }
            CheckSum_Address_Processed += CHECKSUM_CALCULATION_WORD_JUNKS;
            RegionBlock_Length = (RegionBlock_Length >= CHECKSUM_CALCULATION_BYTE_JUNKS) ? (RegionBlock_Length - CHECKSUM_CALCULATION_BYTE_JUNKS) : 0u;
            if (RegionBlock_Length == 0u)
            {
                if (CheckSum_TextRegionIdx < (FLS_INTEGRITY_TOTAL_TEXT_REGIONS - 1u))
                {
                    CheckSum_TextRegionIdx++;
                }
                else
                {
                    CheckSum_Process = TRUE;
                    if(g_checksum[0] != CheckSum_Result)
                    {
                        #ifdef VIP_UART_TEST
                        #if (DLTEXT_UART_PRINT == STD_ON)
                            (void)DltExt_Uart_Printf("\r\n Checksum not Matched !! \r\n");
                        #endif
                        #endif
                        Checksum_Status = FLTM_FLSINTEGRITY_COMPLETED_FAIL;
                        FltM_ReportError(FLTM_ERR_CBK_WKUP_DOMIAN,FLTM_FLSINTEGRITY_ERROR, 0xAAu); // intSrc = 0xAAu as this doesn't come from ESM
                    }
                    else
                    {
                        #ifdef VIP_UART_TEST
                        #if (DLTEXT_UART_PRINT == STD_ON)
                            (void)DltExt_Uart_Printf("\r\n Checksum Matched !! \r\n");
                        #endif
                        #endif
                        Checksum_Status = FLTM_FLSINTEGRITY_COMPLETED_PASS;
                    }
                }
            }
        }
        else
        {
            FltM_Soc_Det_ReportError(FLTM_CHECKSUMCALCULATE, FLTM_ERR_ZEROLENGTH_CHECKSUM);
        }
    }
    return CheckSum_Process;
}

void FltM_FlsIntegrity_GetStatus(eFltM_FlsIntegrityStatusType *Status)
{
    if (Status != NULL)
    {
        *Status = (eFltM_FlsIntegrityStatusType)Checksum_Status;
    }
    else
    {
        FltM_Soc_Det_ReportError(FLTM_FLSINTEGRITY_GETSTATUS_API, FLTM_ERR_NULL_POINTER);
    }
}


#endif /*FLTM_FLSINTEGRITY_ENABLE*/

#define FLTM_SEC_CODE_STOP
#define FLTM_CORE_CONST_SEC_END
#define FLTM_CORE_DATA_SEC_END
#define FLTM_CORE_BSS_SEC_END

#include "MemMap.h"

#endif
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
/*----------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :5-Aug-2025
By                :KPORKODI
Traceability      :PE4TI29141-9645
Change Description:Flash Integrity Implementation
-----------------------------------------------------------------------------*/
