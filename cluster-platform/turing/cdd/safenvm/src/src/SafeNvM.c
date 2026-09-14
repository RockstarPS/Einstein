/**
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2025. Visteon Corporation owns all rights to
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
 * @file        SafeNvM.c
 * @details     
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2025
 *
 */

 #ifndef SAFENVM_C_
 #define SAFENVM_C_
 
 /*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/

#include "SafeNvM.h"
#include "SafeNvM_Cfg.h"
#include "Std_Types.h"
#include "MemLib.h"
#include "NvM.h" /* PE4TI29141-1883*/
#include <string.h>
#include "CmpLib.h" 

#define SAFENVM_SEC_CODE_START
#define SAFENVM_CORE_CONST_SEC_START
#define SAFENVM_CORE_DATA_SEC_START
#define SAFENVM_CORE_BSS_SEC_START

#include "MemMap.h"

/*! @brief  Instance of cmplib life-cycle */
CMPLIB_INSTANCE(SafeNvM)
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/



/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef struct
{
  uint8 lNvMWriteBlkReq;
  uint8 lNvMWriteInProgress;
  uint8 lNvMWriteChain;
  uint8 lNvMDataCompare;
}NvMSafe_InternalType;

/*****************************************************************************
*                              Locally used Variable Declarations            *
******************************************************************************/
static NvMSafe_InternalType NvMSafe_Internal[NUM_OF_SAFE_NVM_BLKS];

/*****************************************************************************
 *                              Locally used Functions declaration              *
 ******************************************************************************/
static void SafeNvmWriteData(uint8 SafeBlkIndex);
static uint8 SafeNvM_Write_Success_Count = 0;
static Std_ReturnType CmpInit(void);
static Std_ReturnType CmpDeInit(void);
static Std_ReturnType CmpActivation(void);
static Std_ReturnType CmpDeActivation(void);
static Std_ReturnType CmpActive(void);
static Std_ReturnType CmpDiagReturn(void);

/*****************************************************************************
 *                             FUNCTIONS                                       *
 ******************************************************************************/
/*============================================================================
**
** Function Name    :   CmpInit
**
** Visibility       :   Static
**
** Description      :   SafeNvM Module Component Initialize routine
**
** Invocation       :   Internal
**
** Inputs           :   None
**
** Outputs          :   E_OK: Succeed
**                      E_NOT_READY: In progress
**                      E_NOT_OK: Failed
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType CmpInit(void)
{
  SafeNvM_Init();
  return E_OK;
}

/*============================================================================
**
** Function Name    :   CmpDeInit
**
** Visibility       :   Static
**
** Description      :   SafeNvM Module Component De-Initialize routine
**
** Invocation       :   Internal
**
** Inputs           :   None
**
** Outputs          :   E_OK: Succeed
**                      E_NOT_READY: In progress
**                      E_NOT_OK: Failed
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType CmpDeInit(void)
{
  return E_OK;
}

/*============================================================================
**
** Function Name    :   CmpActivation
**
** Visibility       :   Static
**
** Description      :   SafeNvM Module Component Activation routine
**
** Invocation       :   Internal
**
** Inputs           :   None
**
** Outputs          :   E_OK: Succeed
**                      E_NOT_READY: In progress
**                      E_NOT_OK: Failed
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType CmpActivation(void)
{
  return E_OK;
}

/*============================================================================
**
** Function Name    :   CmpDeActivation
**
** Visibility       :   Static
**
** Description      :   SafeNvM Module Component De-Activation routine
**
** Invocation       :   Internal
**
** Inputs           :   None
**
** Outputs          :   E_OK: Succeed
**                      E_NOT_READY: In progress
**                      E_NOT_OK: Failed
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType CmpDeActivation(void)
{
  return E_OK;
}

/*============================================================================
**
** Function Name    :   CmpActive
**
** Visibility       :   Static
**
** Description      :   SafeNvM Module Component Active routine
**
** Invocation       :   Internal
**
** Inputs           :   None
**
** Outputs          :   E_OK: Succeed
**                      E_NOT_READY: In progress
**                      E_NOT_OK: Failed
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType CmpActive(void)
{
  SafeNvM_MainFunction();
  return E_OK;
}

/*============================================================================
**
** Function Name    :   CmpDiag
**
** Visibility       :   Static
**
** Description      :   SafeNvM Module Component Diagnostic routine
**
** Invocation       :   Internal
**
** Inputs           :   None
**
** Outputs          :   E_OK: Succeed
**                      E_NOT_READY: In progress
**                      E_NOT_OK: Failed
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType CmpDiag(void)
{
  return E_OK;
}

/*============================================================================
**
** Function Name    :   CmpDiagReturn
**
** Visibility       :   Static
**
** Description      :   Transitional state to clean up after diagnostic state
**
** Invocation       :   Internal
**
** Inputs           :   None
**
** Outputs          :   E_OK: Succeed
**                      E_NOT_READY: In progress
**                      E_NOT_OK: Failed
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType CmpDiagReturn(void)
{
  return E_OK;
}
/*****************************************************************************
 * @brief Initializes the SafeNvM module.
 *
 * This function initializes the SafeNvM module by setting up the necessary
 * configurations and internal states. It prepares the module for subsequent
 * operations related to safe data management.
 *
 * @return None
 ****************************************************************************/
void SafeNvM_Init(void)
{
  uint8 flNumOfSafeNvMBlks = 0; /* Loop counter for Safe NvM blocks */
  for(flNumOfSafeNvMBlks = 0; flNumOfSafeNvMBlks < NUM_OF_SAFE_NVM_BLKS; flNumOfSafeNvMBlks++)
  {
    const NvMSafeBlockConfigType* cNvMSafeBlockConfig = &NvMSafe_Blockconfig[flNumOfSafeNvMBlks];

    if((cNvMSafeBlockConfig->NvmRamMirrorBuf_OriginalPtr == NULL_PTR) ||
       (cNvMSafeBlockConfig->NvmRamMirrorBuf_Copy1Ptr == NULL_PTR) ||
       (cNvMSafeBlockConfig->NvmRamMirrorBuf_Copy2Ptr == NULL_PTR))
    {
      /* Handle error: Original buffer pointer is NULL */
      SafeNvM_Det_ReportError(SAFENVM_INIT, SAFENVM_INVALID_RAM_BUFFER);
    }
    else if((cNvMSafeBlockConfig->DefaultRomPtr == NULL_PTR))
    {
      /* Handle error: Default ROM pointer is NULL */
      SafeNvM_Det_ReportError(SAFENVM_INIT, SAFENVM_INVALID_ROM_BUFFER);
    }
    else
    {
      NvMSafe_Internal[flNumOfSafeNvMBlks].lNvMWriteBlkReq = FALSE;
      NvMSafe_Internal[flNumOfSafeNvMBlks].lNvMWriteInProgress = FALSE;
      NvMSafe_Internal[flNumOfSafeNvMBlks].lNvMWriteChain = FALSE;
      NvMSafe_Internal[flNumOfSafeNvMBlks].lNvMDataCompare = FALSE;

    // All three buffers mismatch, use default ROM values
      MemLib_MemCpy(cNvMSafeBlockConfig->AsilCopyPtr, cNvMSafeBlockConfig->DefaultRomPtr, \
                            cNvMSafeBlockConfig->NvM_BlockSize);

    }
  }
}


/*****************************************************************************
 * @brief Writes data to the SafeNvM block if no write operation is currently in progress.
 *
 * This function handles the process of writing data to the SafeNvM block. It ensures
 * that the write operation is initiated only if no other write operation is in progress
 * for the specified block. The function updates the internal state to reflect the
 * initiation of the write operation.
 *
 * @param SafeBlkIndex The ID of the original block to be written.
 *
 * @return None
 ****************************************************************************/
static void SafeNvmWriteData(uint8 SafeBlkIndex)
{
  const NvMSafeBlockConfigType* cNvMSafeBlockConfig = &NvMSafe_Blockconfig[SafeBlkIndex];

  MemLib_MemCpy(cNvMSafeBlockConfig->NvmRamMirrorBuf_OriginalPtr, \
    cNvMSafeBlockConfig->AsilCopyPtr, \
      cNvMSafeBlockConfig->NvM_BlockSize);
  (void)NvM_WriteBlock(cNvMSafeBlockConfig->NvM_BlockId_Original, NULL_PTR);
  NvMSafe_Internal[SafeBlkIndex].lNvMWriteInProgress = TRUE;
  NvMSafe_Internal[SafeBlkIndex].lNvMWriteChain = TRUE;
  NvMSafe_Internal[SafeBlkIndex].lNvMWriteBlkReq = FALSE;
}

/*****************************************************************************
 * @brief Main function for SafeNvM module.
 *
 * This function iterates through all SafeNvM blocks and, for each block,
 * checks if a write operation is not in progress. If a write block request
 * is set for the block, it triggers the write operation by calling
 * SafeNvmWriteData. This ensures that write requests are handled only when
 * the block is ready, maintaining data integrity and preventing concurrent
 * write operations.
 *
 * @param None
 * @return None
 ****************************************************************************/
void SafeNvM_MainFunction(void)
{
  uint8 flNumOfSafeNvMBlks;

  for (flNumOfSafeNvMBlks = 0; flNumOfSafeNvMBlks < NUM_OF_SAFE_NVM_BLKS; flNumOfSafeNvMBlks++)
  {
    // Process only if no write operation is in progress for the current block
    if((NvMSafe_Internal[flNumOfSafeNvMBlks].lNvMWriteInProgress == FALSE) && \
                      (NvMSafe_Internal[flNumOfSafeNvMBlks].lNvMDataCompare != FALSE))
    {
      // Trigger write operation if a write block request is set
      if(NvMSafe_Internal[flNumOfSafeNvMBlks].lNvMWriteBlkReq != FALSE)
      {
        SafeNvmWriteData(flNumOfSafeNvMBlks);
      }
    }
  }
}


/*****************************************************************************
 * @brief Triggers data comparison and synchronization for SafeNvM blocks.
 *
 * This function iterates through all SafeNvM blocks and performs data comparison between
 * the original, copy1, and copy2 RAM mirror buffers for each block. If no write operation
 * is currently in progress and data comparison has not yet been performed, the function:
 *   - Checks for NULL pointers in the buffer configuration and reports an error if found.
 *   - Compares the contents of the buffers:
 *       - If Original and Copy1 match, updates the ASIL memory and, if Copy2 mismatches,
 *         updates Copy2 and triggers a write operation.
 *       - If Original and Copy2 match, updates the ASIL memory, updates Copy1, and triggers
 *         a write operation.
 *       - If Copy1 and Copy2 match, updates the ASIL memory, updates Original, and triggers
 *         a write operation.
 *       - If none match, a diagnostic trouble code (DTC) may be triggered (implementation TBD).
 *   - Calls the configured function to write ASIL elements.
 *   - Marks the data comparison as completed for the current block.
 *
 * Error handling is performed for invalid buffer pointers.
 *
 * @note This function assumes that the NvMSafe_Internal and NvMSafe_Blockconfig arrays,
 *       as well as the NUM_OF_SAFE_NVM_BLKS constant, are properly defined and initialized.
 *       It also assumes the existence of the SafeNvM_Det_ReportError and NvM_WriteBlock functions.
 ****************************************************************************/

void SafeNvM_TriggerDataCompare(void)
{
  uint8 flNumOfSafeNvMBlks;
  for (flNumOfSafeNvMBlks = 0; flNumOfSafeNvMBlks < NUM_OF_SAFE_NVM_BLKS; flNumOfSafeNvMBlks++)
  {
    // Process only if no write operation is in progress for the current block
    if(NvMSafe_Internal[flNumOfSafeNvMBlks].lNvMWriteInProgress == FALSE)
    {
      if(NvMSafe_Internal[flNumOfSafeNvMBlks].lNvMDataCompare == FALSE)
      {
        const NvMSafeBlockConfigType* cNvMSafeBlockConfig = &NvMSafe_Blockconfig[flNumOfSafeNvMBlks];

        if((cNvMSafeBlockConfig->NvmRamMirrorBuf_OriginalPtr == NULL_PTR) ||
                    (cNvMSafeBlockConfig->NvmRamMirrorBuf_Copy1Ptr == NULL_PTR) ||
                          (cNvMSafeBlockConfig->NvmRamMirrorBuf_Copy2Ptr == NULL_PTR))
        {
          /* Handle error: Original buffer pointer is NULL */
          SafeNvM_Det_ReportError(SAFENVM_MAIN_FUNCTION, SAFENVM_INVALID_RAM_BUFFER);
        }
        else
        {
          // /https://visteon.atlassian.net/browse/PE4TI29141-1875
          // Check if Original and AsilCopy buffers match
          if(MemLib_MemCmp(cNvMSafeBlockConfig->NvmRamMirrorBuf_OriginalPtr, \
                cNvMSafeBlockConfig->NvmRamMirrorBuf_Copy1Ptr, \
                cNvMSafeBlockConfig->NvM_BlockSize) != 0u)
          {
            // Copy data to ASIL memory
           MemLib_MemCpy(cNvMSafeBlockConfig->AsilCopyPtr, \
                  cNvMSafeBlockConfig->NvmRamMirrorBuf_OriginalPtr, \
                                  cNvMSafeBlockConfig->NvM_BlockSize);

            // Check if AsilCopy and Copy2 buffers match
            if(MemLib_MemCmp(cNvMSafeBlockConfig->NvmRamMirrorBuf_Copy1Ptr, \
                  cNvMSafeBlockConfig->NvmRamMirrorBuf_Copy2Ptr, \
                      cNvMSafeBlockConfig->NvM_BlockSize) == 0u)
            {
              // Copy2 mismatch, update Copy2 and trigger write operation
              MemLib_MemCpy(cNvMSafeBlockConfig->NvmRamMirrorBuf_Copy2Ptr, \
                    cNvMSafeBlockConfig->NvmRamMirrorBuf_OriginalPtr, \
                        cNvMSafeBlockConfig->NvM_BlockSize);
              (void)NvM_WriteBlock(cNvMSafeBlockConfig->NvM_BlockId_Copy2, NULL_PTR);
              NvMSafe_Internal[flNumOfSafeNvMBlks].lNvMWriteInProgress = TRUE;
            }
          }
          // Check if Original and Copy2 buffers match
          else if(MemLib_MemCmp(cNvMSafeBlockConfig->NvmRamMirrorBuf_OriginalPtr, \
              cNvMSafeBlockConfig->NvmRamMirrorBuf_Copy2Ptr,\
                  cNvMSafeBlockConfig->NvM_BlockSize) != 0u)
          {
            // Copy data to ASIL memory
            MemLib_MemCpy(cNvMSafeBlockConfig->AsilCopyPtr, \
                      cNvMSafeBlockConfig->NvmRamMirrorBuf_OriginalPtr, \
                                  cNvMSafeBlockConfig->NvM_BlockSize);

            // AsilCopy mismatch, update AsilCopy and trigger write operation
            MemLib_MemCpy(cNvMSafeBlockConfig->NvmRamMirrorBuf_Copy1Ptr, \
                  cNvMSafeBlockConfig->NvmRamMirrorBuf_OriginalPtr, \
                      cNvMSafeBlockConfig->NvM_BlockSize);
            (void)NvM_WriteBlock(cNvMSafeBlockConfig->NvM_BlockId_Copy1, NULL_PTR);
            NvMSafe_Internal[flNumOfSafeNvMBlks].lNvMWriteInProgress = TRUE;
          }
          // Check if copy1 and Copy2 buffers match
          else if(MemLib_MemCmp(cNvMSafeBlockConfig->NvmRamMirrorBuf_Copy1Ptr, \
              cNvMSafeBlockConfig->NvmRamMirrorBuf_Copy2Ptr, \
                      cNvMSafeBlockConfig->NvM_BlockSize) != 0u)
          {
            // Copy data to ASIL memory
            MemLib_MemCpy(cNvMSafeBlockConfig->AsilCopyPtr, \
              cNvMSafeBlockConfig->NvmRamMirrorBuf_Copy1Ptr, \
                          cNvMSafeBlockConfig->NvM_BlockSize);

            // Original mismatch, update Original and trigger write operation
            MemLib_MemCpy(cNvMSafeBlockConfig->NvmRamMirrorBuf_OriginalPtr, \
                cNvMSafeBlockConfig->NvmRamMirrorBuf_Copy1Ptr, \
                    cNvMSafeBlockConfig->NvM_BlockSize);
            (void)NvM_WriteBlock(cNvMSafeBlockConfig->NvM_BlockId_Original, NULL_PTR);
            NvMSafe_Internal[flNumOfSafeNvMBlks].lNvMWriteInProgress = TRUE;
          }
          else
          {
            /* DTC ? */// raise defect for CallBack
            SAFENVM_DTC_HOOK();
          }
          cNvMSafeBlockConfig->SafeNvM_Write_Asil_ElementsPtr();
          NvMSafe_Internal[flNumOfSafeNvMBlks].lNvMDataCompare = TRUE;
        }
      }
    }
  }
}


/*****************************************************************************
 * @brief Sets a write block request for a specified block ID in the SafeNvM module.
 *
 * This function marks the specified block ID as requiring a write operation
 * in the SafeNvM internal structure, provided the block ID is within the valid range.
 *
 * @param SafeBlockIndex The block ID for which the write block request is to be set.
 *               Must be less than NUM_OF_SAFE_NVM_BLKS.
 *
 * @return None
 ****************************************************************************/
Std_ReturnType SafeNvM_SetWriteBlockReq(uint8 SafeBlockIndex)
{
  Std_ReturnType flRetVal = E_NOT_OK;
  if(SafeBlockIndex < NUM_OF_SAFE_NVM_BLKS)
  {
    NvMSafe_Internal[SafeBlockIndex].lNvMWriteBlkReq = TRUE;
    flRetVal = E_OK;
  }
  else
  {
    SafeNvM_Det_ReportError(SAFENVM_SET_WRITE_BLOCK, SAFENVM_INVALID_SAFE_BLOCK);
    flRetVal = E_NOT_OK;
  }
  return flRetVal;
}

/*****************************************************************************
 * @brief Handles the safe write callback mechanism for a specified block ID.
 *
 * This function is responsible for managing the chaining design through a callback.
 * It checks if the write chaining is enabled for the given block ID and performs
 * a memory copy operation followed by initiating a write operation for the copy block.
 * If write chaining is not enabled, it sets the write-in-progress flag.
 *
 * @param SafeBlockIndex The block ID for which the safe write callback is being executed.
 *
 * @return void This function does not return a value.
 ****************************************************************************/
/*Chaining Design through call back */

void SafeNvM_NvM_WriteCallback_Original(uint8 SafeBlockIndex, uint8 ServiceId, NvM_RequestResultType JobResult)
{
  const NvMSafeBlockConfigType* cNvMSafeBlockConfig = &NvMSafe_Blockconfig[SafeBlockIndex];
  if(NvMSafe_Internal[SafeBlockIndex].lNvMWriteChain != FALSE)
  {
    if(ServiceId == NVM_WRITE_BLOCK)
    {
      if(NVM_REQ_OK == JobResult)
      {
        SafeNvM_Write_Success_Count++;
      }
      if(NVM_REQ_PENDING != JobResult)
      {
        MemLib_MemCpy(cNvMSafeBlockConfig->NvmRamMirrorBuf_Copy1Ptr,\
          cNvMSafeBlockConfig->NvmRamMirrorBuf_OriginalPtr, \
              cNvMSafeBlockConfig->NvM_BlockSize);
        (void)NvM_WriteBlock(cNvMSafeBlockConfig->NvM_BlockId_Copy1, NULL_PTR);
      }
    }
  }
  else
  {
    NvMSafe_Internal[SafeBlockIndex].lNvMWriteInProgress = FALSE;//TBD
  }
}

/*****************************************************************************
 * @brief Handles the safe write callback for a specific block ID.
 *
 * This function is responsible for managing the safe write operation
 * for a given block ID. It performs a memory copy from the original
 * RAM mirror buffer to the secondary RAM mirror buffer and initiates
 * a write operation to the secondary NVM block if the write chain is active.
 * Otherwise, it sets the write-in-progress flag.
 *
 * @param SafeBlockIndex The block ID for which the safe write callback is executed.
 *
 * @return void This function does not return a value.
 ****************************************************************************/
void SafeNvM_NvM_WriteCallback_Copy1(uint8 SafeBlockIndex, uint8 ServiceId, NvM_RequestResultType JobResult)
{
  const NvMSafeBlockConfigType* cNvMSafeBlockConfig = &NvMSafe_Blockconfig[SafeBlockIndex];
  if(NvMSafe_Internal[SafeBlockIndex].lNvMWriteChain != FALSE)
  {
    if(ServiceId == NVM_WRITE_BLOCK)
    {
      if(NVM_REQ_OK == JobResult)
      {
        SafeNvM_Write_Success_Count++;
      }
      if(NVM_REQ_PENDING != JobResult)
      {
        MemLib_MemCpy(cNvMSafeBlockConfig->NvmRamMirrorBuf_Copy2Ptr, \
          cNvMSafeBlockConfig->NvmRamMirrorBuf_OriginalPtr, \
            cNvMSafeBlockConfig->NvM_BlockSize);
        (void)NvM_WriteBlock(cNvMSafeBlockConfig->NvM_BlockId_Copy2, NULL_PTR);
      }
    }
  }
  else
  {
    NvMSafe_Internal[SafeBlockIndex].lNvMWriteInProgress = FALSE; //TBD
  }
}

/*****************************************************************************
 * @brief Callback function to handle post-write operations for a specific block ID.
 *
 * This function is responsible for resetting the write chain and marking the
 * write operation as complete for the given block ID in the NvMSafe_Internal structure.
 *
 * @param SafeBlockIndex The block ID for which the write operation is being finalized.
 *
 * @return void This function does not return a value.
 ****************************************************************************/
void SafeNvM_NvM_WriteCallback_Copy2(uint8 SafeBlockIndex, uint8 ServiceId, NvM_RequestResultType JobResult)
{
  const NvMSafeBlockConfigType* cNvMSafeBlockConfig = &NvMSafe_Blockconfig[SafeBlockIndex];
  if(ServiceId == NVM_WRITE_BLOCK)
  {
    if(NVM_REQ_OK == JobResult)
    {
      SafeNvM_Write_Success_Count++;
    }
    if(NVM_REQ_PENDING != JobResult)
    {
      NvMSafe_Internal[SafeBlockIndex].lNvMWriteChain = FALSE;
      NvMSafe_Internal[SafeBlockIndex].lNvMWriteInProgress = FALSE;
      if(SafeNvM_Write_Success_Count >= 2u)
      {
        cNvMSafeBlockConfig->SafeNvM_MemAbstract_JobEnd_Notify(ServiceId, NVM_REQ_OK);
      }
      else
      {
        cNvMSafeBlockConfig->SafeNvM_MemAbstract_JobEnd_Notify(ServiceId, NVM_REQ_NOT_OK);
      }
      SafeNvM_Write_Success_Count = 0;
    }
  }
}


#define SAFENVM_SEC_CODE_END
#define SAFENVM_CORE_CONST_SEC_END
#define SAFENVM_CORE_DATA_SEC_END
#define SAFENVM_CORE_BSS_SEC_END

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
Date              :  12-May-2025
By                :  MSAVARIY
Traceability      : https://visteon.atlassian.net/browse/PE4TI29141-8071
Change Description: Initial Triple Buffer Platform solution Implementation
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  27-May-2025
By                :  MSAVARIY
Traceability      : https://visteon.atlassian.net/browse/PE4TI29141-8584
Change Description: Design update and review fix
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  28-May-2025
By                :  MSAVARIY
Traceability      : https://visteon.atlassian.net/browse/PE4TI29141-8584
Change Description: Design update and review fix
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  24-Jul-2025
By                :  abasavar
Traceability      : https://visteon.atlassian.net/browse/PE4TI29141-9515
Change Description: CMPLIB_INSTANCE update
-----------------------------------------------------------------------------*/
