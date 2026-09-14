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
 * @file        SafeNvM_Types.h
 * @details     
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2025
 *
 */

#ifndef SAFENVM_TYPES_H_
#define SAFENVM_TYPES_H_


/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Std_Types.h"
#include "SafeNvM_Cfg.h"
#include "SafeNvM.h"

#define SAFENVM_SEC_CODE_START
#define SAFENVM_CORE_CONST_SEC_START
#define SAFENVM_CORE_DATA_SEC_START
#define SAFENVM_CORE_BSS_SEC_START

#include "MemMap.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/* Det Api Id Definition */
#define SAFENVM_INIT                 (0x01U)
#define SAFENVM_SET_WRITE_BLOCK      (0x02U)
#define SAFENVM_REQ_READ_BLOCK       (0x03U)
#define SAFENVM_MAIN_FUNCTION        (0x04U)
#define SAFENVM_ORIGINAL_CALL_BACK   (0x05U)
#define SAFENVM_COPY1_CALL_BACK      (0x06U)


//RstM Report Erorr Macro
#define SAFENVM_INVALID_SAFE_BLOCK           (0x01U)
#define SAFENVM_INVALID_RAM_BUFFER           (0x02U)
#define SAFENVM_INVALID_ROM_BUFFER           (0x03U)



/* Det Error Definition */
#define SAFENVM_ERROR_I2C_PUSH_SEQUENCE_FAILED          (0x01U)
#define SAFENVM_ERROR_I2C_POP_SEQUENCE_FAILED           (0x02U)
#define SAFENVM_ERROR_I2C_ASYN_TRANSMIT_FAILED          (0x03U)
#define SAFENVM_ERROR_I2C_CB_SEQUENCE_FAILED            (0x04U)
#define SAFENVM_ERROR_I2C_RECEIVE_CRC_FAILED            (0x05U)
#define SAFENVM_ERROR_I2C_TRANSMIT_CRC_FAILED           (0x06U)

# define Rte_TypeDef_NvM_RequestResultType
typedef uint8 NvM_RequestResultType;

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef void (*SafeNvM_Write_Asil_ElementsPtrType)(void);

typedef struct {
  uint16 NvM_BlockId_Original; // PE4TI29141-1878
  uint16 NvM_BlockId_Copy1; // PE4TI29141-1878
  uint16 NvM_BlockId_Copy2; // PE4TI29141-1878
  uint16 NvM_BlockSize;
  const uint8* DefaultRomPtr;  // Pointer to ROM default values
  void* NvmRamMirrorBuf_OriginalPtr; // Local RAM mirror
  void* NvmRamMirrorBuf_Copy1Ptr;  // Local RAM mirror
  void* NvmRamMirrorBuf_Copy2Ptr; // Local RAM mirror
  void* AsilCopyPtr; // ASIL RAM Copy Pointer
  SafeNvM_Write_Asil_ElementsPtrType SafeNvM_Write_Asil_ElementsPtr; // Pointer to function for writing ASIL elements
  Std_ReturnType (*SafeNvM_MemAbstract_JobEnd_Notify)(uint8,NvM_RequestResultType);
} NvMSafeBlockConfigType;





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

