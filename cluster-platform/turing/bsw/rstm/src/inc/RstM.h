/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2024. Visteon Corporation owns all rights to           *
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
*  File Name         :  RstM.h                                               *
*  Module Short Name :  RstM                                                 *
*  Description       :  This file contains include for Reset Manager         *
*                                                                            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  Compiler Independent                                   *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/
#ifndef RSTM_H
#define RSTM_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Std_Types.h"
#include "RstM_Cfg.h"
#include "RstM_Types.h"
#include "Os.h"
#include "RstM_Irq.h"
#if defined (SOC_AM62PX) || defined (SOC_AM62P)
#include "soc.h"
#endif
#include "Mcu.h"

#define RSTM_SEC_CODE_START
#define RSTM_CORE_CONST_SEC_START
#define RSTM_CORE_DATA_SEC_START
#define RSTM_CORE_BSS_SEC_START

#include "MemMap.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define RSTM_BYTE_BIT_SHIFT (8U)    
#define RSTM_LOG_DATA_SIZE          (5U)
#define RSTM_IDX_BYTE_0             (0U)
#define RSTM_IDX_BYTE_1             (1U)
#define RSTM_IDX_BYTE_2             (2U)
#define RSTM_IDX_BYTE_3             (3U)
#define RSTM_SHIFT_8                (8U)
#define RSTM_SHIFT_16               (16U)
#define RSTM_SHIFT_24               (24U)
#define RSTM_BYTE_MASK              (0xFFu)
/*============================================================================
** Function Name    :   RstM_Init
**
** Visibility       :   Public
**
** Description      :   Function to initialize RstM module
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**==========================================================================*/
extern void RstM_Init(void);

/*============================================================================
** Function Name    :   RstM_MainFunction
**
** Visibility       :   Public
**
** Description      :   Function to be called from the main function for
**
**                      periodic processing
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**==========================================================================*/
void RstM_MainFunction(void);

#if defined (SOC_AM62PX) || defined (SOC_AM62P)
/*============================================================================
** Function Name    :   RstM_EnableResetIsolation
**
** Visibility       :   Public
**
** Description      :   Function to be called to enable the Reset Isolation.
**
**                      MCU domain is exempt from domain resets
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**==========================================================================*/
extern Std_ReturnType RstM_EnableResetIsolation(void);

/*============================================================================
** Function Name    :   RstM_ProcessResetIsolationReq
**
** Visibility       :   Public
** Description      :   Function to be called to process the Reset Isolation
**
**                      request and perform domain reset
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**==========================================================================*/
extern void RstM_ProcessResetIsolationReq(void);
#endif

/*============================================================================
** Function Name    :   RstM_StageOsArmDump
**
** Visibility       :   Public
** Description      :   Function to be called to process the Reset Isolation
**
**                      request and perform domain reset
**
** Invocation       :   Application
**
** Inputs           :   eFltM_FaultIdType fid, const void *Dump, uint16 DumpLen
**
** Outputs          :   Std_ReturnType
**
** Critical Section :   Yes
**==========================================================================*/

extern Std_ReturnType RstM_StageOsArmDump(eFltM_FaultIdType fid, const void *Dump, uint16 DumpLen);

#if 0
/*============================================================================
** Function Name    :   RstM_GetResetCount
**
** Visibility       :   Public
**
** Description      :   Retrieves the reset count for a specific fault ID.
**
** Invocation       :   Application
**
** Inputs           :   FaultId - The fault ID for which the reset count is requested.
**
** Outputs          :   Count - Pointer to store the retrieved reset count.
**
** Return           :   Std_ReturnType E_OK if successful, otherwise E_NOT_OK.
**
** Critical Section :   No
**==========================================================================*/
extern Std_ReturnType RstM_GetResetCount(eFltM_FaultIdType FaultId, uint8* Count);

/*============================================================================
** Function Name    :   RstM_ClearResetHistory
**
** Visibility       :   Public
**
** Description      :   Clears the reset history.
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Return           :   Std_ReturnType E_OK if successful, otherwise E_NOT_OK.
**
** Critical Section :   No
**==========================================================================*/
extern Std_ReturnType RstM_ClearResetHistory(void);

/*============================================================================
** Function Name    :   RstM_GetResetHistory
**
** Visibility       :   Public
**
** Description      :   Retrieves the reset history.
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   ResetHistory - Pointer to store the retrieved reset history.
**
** Return           :   Std_ReturnType E_OK if successful, otherwise E_NOT_OK.
**
** Critical Section :   No
**==========================================================================*/
extern Std_ReturnType RstM_GetResetHistory(uint8* ResetHistory);

/*============================================================================
** Function Name    :   RstM_RequestSwReset
**
** Visibility       :   Public
**
** Description      :   Requests a software reset for a specific fault ID.
**
** Invocation       :   Application
**
** Inputs           :   FaultId    - The fault ID for which the software reset is requested.
**                      ResetType  - The type of reset to perform.
**                      LogData    - Pointer to the log data to be stored.
**                      LogLength  - Length of the log data.
**
** Outputs          :   None
**
** Return           :   Std_ReturnType E_OK if successful, otherwise E_NOT_OK.
**
** Critical Section :   Yes
**==========================================================================*/
extern Std_ReturnType RstM_RequestSwReset(const eFltM_FaultIdType FaultId, uint8 *LogData, uint16 LogLength);

/*============================================================================
** Function Name    :   RstM_GetLastResetReason
**
** Visibility       :   Public
**
** Description      :   Retrieves the last reset reason information.
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   lastResetInfo - Pointer to store the last reset reason information.
**
** Return           :   Std_ReturnType E_OK if successful, otherwise E_NOT_OK.
**
** Critical Section :   No
**==========================================================================*/
extern Std_ReturnType RstM_GetLastResetReason(eFltM_FaultIdType* lastResetInfo);

#endif

extern Std_ReturnType RstM_GetEarlyResetCount(eFltM_FaultIdType FaultId, uint8 *Count);

#define RSTM_SEC_CODE_STOP
#define RSTM_CORE_CONST_SEC_END
#define RSTM_CORE_DATA_SEC_END
#define RSTM_CORE_BSS_SEC_END

#include "MemMap.h"

#endif /* RSTM_H */
/*============================================================================
**================================-============================================
** R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
**===========================================================================*/
/*---------------------------------------------------------------------------
Date               : 27 Aug 2024
CDSID              : nchellap
Traceability       : PE4TI29141-4360
Change Description : Initial Framework version of RstM
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 11 Sep 2024
CDSID              : nchellap
Traceability       : PE4TI29141-3922
Change Description : RstM - Bookshelf Release & Delivery
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 16 June 2025
CDSID              : sdv
Traceability       : PE4TI29141-8732
Change Description : RstM design change and Initial Implementation of RstM
-----------------------------------------------------------------------------*/
/******************************* End of File *********************************/
