/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2012. Visteon Corporation owns all rights to           *
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
*  File Name         :  NvM.h                                                *
*  Module Short Name :  NvMMgr                                               *
*  VOBName           :                                                       *
*  Author            : vbalakr3                                              *
*  Description       : This file contains the NvM Manager Request handling   *
*                       functionalities and invokes Fee/Ea                    *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :                                                         *
*                                                                            *
******************************************************************************/
#ifndef NVM_H
#define NVM_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "NvM_Types.h"
#include "NvM_Cfg.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#ifndef NVM_C
#define EXTERN extern
#else
#define EXTERN
#endif

#ifndef NVM_REQ_OK
#define NVM_REQ_OK                    0x00
#endif

#ifndef NVM_REQ_NOT_OK
#define NVM_REQ_NOT_OK                0x01
#endif

#ifndef NVM_REQ_PENDING
#define NVM_REQ_PENDING               0x02
#endif

#ifndef NVM_REQ_INTEGRITY_FAILED
#define NVM_REQ_INTEGRITY_FAILED      0x03
#endif

#ifndef NVM_REQ_BLOCK_SKIPPED
#define NVM_REQ_BLOCK_SKIPPED         0x04
#endif

#ifndef NVM_REQ_NV_INVALIDATED
#define NVM_REQ_NV_INVALIDATED        0x05
#endif

#ifndef NVM_REQ_CANCELED
#define NVM_REQ_CANCELED              0x06
#endif

#ifndef NVM_REQ_REDUNDANCY_FAILED
#define NVM_REQ_REDUNDANCY_FAILED     0x07
#endif

#ifndef NVM_REQ_RESTORED_FROM_ROM
#define NVM_REQ_RESTORED_FROM_ROM     0x08
#endif


/* These Sevice IDs are important to an SW-C, as they can be passed to it in the
"single block job end notification" callback.
Therefore they are also defined by the RTE */
#ifndef NVM_READ_BLOCK
#    define NVM_READ_BLOCK             (6u) /* Service ID NvM_ReadBlock() */
#endif
#ifndef NVM_WRITE_BLOCK
#    define NVM_WRITE_BLOCK            (7u) /* Service ID NvM_WriteBlock() */
#endif
#ifndef NVM_RESTORE_BLOCK_DEFAULTS
#    define NVM_RESTORE_BLOCK_DEFAULTS (8u) /* Service ID NvM_RestoreBlockDefaults() */
#endif
#ifndef NVM_ERASE_BLOCK
#    define NVM_ERASE_BLOCK            (9u) /* Service ID NvM_EraseNvBlock() */
#endif
#ifndef NVM_INVALIDATE_NV_BLOCK
#    define NVM_INVALIDATE_NV_BLOCK   (11u) /* Service ID NvM_InvalidateNvBlock() */
#endif
#ifndef NVM_READ_ALL
#    define NVM_READ_ALL              (12u) /* Service ID NvM_ReadAll() */
#endif

/* Service Ids of the different service routines of the NVM
 * These sevice IDs should never be defined by the RTE. However, it doesn't hurt to protect them ... */

#ifndef NVM_INIT
#    define NVM_INIT                   (0u) /* Service ID NvM_Init() */
#endif
#ifndef NVM_SET_DATA_INDEX
#    define NVM_SET_DATA_INDEX         (1u) /* Service ID NvM_SetDataIndex() */
#endif
#ifndef NVM_GET_DATA_INDEX
#    define NVM_GET_DATA_INDEX         (2u) /* Service ID NvM_GetDataIndex() */
#endif
#ifndef NVM_SET_BLOCK_PROTECTION
#    define NVM_SET_BLOCK_PROTECTION   (3u) /* Service ID NvM_SetBlockProtection() */
#endif
#ifndef NVM_GET_ERROR_STATUS
#    define NVM_GET_ERROR_STATUS       (4u) /* Service ID NvM_GetErrorStatus() */
#endif
#ifndef NVM_SET_RAM_BLOCK_STATUS
#    define NVM_SET_RAM_BLOCK_STATUS   (5u) /* Service ID NvM_SetRamBlockStatus() */
#endif

#ifndef NVM_CANCEL_WRITE_ALL
#    define NVM_CANCEL_WRITE_ALL      (10u) /* Service ID NvM_CancelRequest() */
#endif

#ifndef NVM_WRITE_ALL
#    define NVM_WRITE_ALL             (13u) /* Service ID NvM_WriteAll() */
#endif
#ifndef NVM_MAINFUNCTION
#    define NVM_MAINFUNCTION          (14u) /* Service ID NvM_MainFunction() */
#endif
#ifndef NVM_GET_VERSION_INFO
#    define NVM_GET_VERSION_INFO      (15u) /* Service ID NvM_GetVersionInfo() */
#endif

#ifndef NVM_CANCEL_JOBS
#    define NVM_CANCEL_JOBS           (16u) /* Service ID NvM_CancelJobs() */
#endif
#ifndef NVM_SET_BLOCK_LOCK_STATUS
#   define NVM_SET_BLOCK_LOCK_STATUS (19u) /* Service ID NvM_SetBlockProtection() */
#endif
#ifndef NVM_KILL_WRITE_ALL
#   define NVM_KILL_WRITE_ALL        (20u) /* Service ID NvM_KillWriteAll() */
#endif




/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/


/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/**************************************************************************
Function name   : void NvM_Init(void)
Arguments       : void
Return type     : void
Description     : This function is called by App/Scheduler when there is an
                  init required. 
**************************************************************************/
EXTERN void NvM_Init(void);

/**************************************************************************
Function name   : Std_ReturnType NvM_SetDataIndex(NvM_BlockIdType BlockId, uint8 DataIndex)
Arguments       : void
Return type     : void
Description     : This function is used to set the Data set index of the DatasetBlock 
**************************************************************************/
EXTERN Std_ReturnType NvM_SetDataIndex(NvM_BlockIdType BlockId, uint8 DataIndex);


/**************************************************************************
Function name   : Std_ReturnType NvM_GetDataIndex( NvM_BlockIdType BlockId, uint8* DataIndexPtr)
Arguments       : NvM_BlockIdType BlockId, uint8* DataIndexPtr
Return type     : Std_ReturnType
                  E_OK: The index position has been retrieved successfully.
                  E_NOT_OK: An error occurred
Description     : Service for getting the currently set DataIndex of a dataset NVRAM block
**************************************************************************/
EXTERN Std_ReturnType NvM_GetDataIndex( NvM_BlockIdType BlockId, uint8* DataIndexPtr);

/**************************************************************************
Function name   : Std_ReturnType NvM_SetBlockProtection(NvM_BlockIdType BlockId, boolean ProtectionEnabled)
Arguments       : NvM_BlockIdType BlockId, boolean ProtectionEnabled
Return type     : Std_ReturnType
                  E_OK: The block was enabled/disabled as requested
                  E_NOT_OK: An error occured
Description     : Service for setting/resetting the write protection for a NV block
**************************************************************************/
EXTERN Std_ReturnType NvM_SetBlockProtection(NvM_BlockIdType BlockId, boolean ProtectionEnabled);

/**************************************************************************
Function name   : Std_ReturnType NvM_GetErrorStatus( NvM_BlockIdType BlockId, NvM_RequestResultType* RequestResultPtr)
Arguments       : NvM_BlockIdType BlockId, NvM_RequestResultType* RequestResultPtr
Return type     : Std_ReturnType
                  E_OK: The block dependent error/status information was read successfully.
                  E_NOT_OK: An error occured.
Description     : Service to read the block dependent error/status information
**************************************************************************/
EXTERN Std_ReturnType NvM_GetErrorStatus( NvM_BlockIdType BlockId, NvM_RequestResultType* RequestResultPtr);

/**************************************************************************
Function name   : void NvM_GetVersionInfo( Std_VersionInfoType* versioninfo)
Arguments       : Std_VersionInfoType* versioninfo
Return type     : void
Description     : Service to get the version information of the NvM module.
**************************************************************************/	
EXTERN void NvM_GetVersionInfo( Std_VersionInfoType* versioninfo);

/**************************************************************************
Function name   : Std_ReturnType NvM_SetRamBlockStatus( NvM_BlockIdType BlockId, boolean BlockChanged)
Arguments       : NvM_BlockIdType BlockId, boolean BlockChanged
Return type     : Std_ReturnType
                  E_OK: The status of the RAM-Block was changed as requested.
                  E_NOT_OK: An error occurred.
Description     : Service for setting the RAM block status of an NVRAM block.
**************************************************************************/
EXTERN Std_ReturnType NvM_SetRamBlockStatus( NvM_BlockIdType BlockId, boolean BlockChanged);

/**************************************************************************
Function name   : void NvM_SetBlockLockStatus( NvM_BlockIdType BlockId, boolean BlockLocked)
Arguments       : NvM_BlockIdType BlockId, boolean BlockLocked
Return type     : void
Description     : Service for setting the lock status of a permanent RAM block or of the explicit
                  synchronization of a NVRAM block.
**************************************************************************/
EXTERN void NvM_SetBlockLockStatus( NvM_BlockIdType BlockId, boolean BlockLocked);

/**************************************************************************
Function name   : void NvM_CancelWriteAll(void)
Arguments       : void
Return type     : void
Description     : Service to Cancel the Write All Request
**************************************************************************/
EXTERN void NvM_CancelWriteAll(void);

/**************************************************************************
Function name   : Std_ReturnType NvM_CancelJobs( NvM_BlockIdType BlockId)
Arguments       : NvM_BlockIdType BlockId
Return type     : Std_ReturnType
                  E_OK: The job was successfully removed from queue.
                  E_NOT_OK: The job could not be found in the queue.
Description     : Service to cancel all jobs pending for a NV block.
***********************************************************************/
EXTERN Std_ReturnType NvM_CancelJobs( NvM_BlockIdType BlockId);

/**************************************************************************
Function name   : Std_ReturnType NvM_ReadBlock( NvM_BlockIdType BlockId,void* NvM_DstPtr)
Arguments       : NvM_BlockIdType BlockId,void* NvM_DstPtr
Return type     : Std_ReturnType
                   E_OK: request has been accepted
                   E_NOT_OK: request has not been accepted
Description     : Service to copy the data of the NV block to its corresponding RAM block
***********************************************************************/
EXTERN Std_ReturnType NvM_ReadBlock( NvM_BlockIdType BlockId,void* NvM_DstPtr);

/**************************************************************************
Function name   : Std_ReturnType NvM_WriteBlock(NvM_BlockIdType BlockId, const void* NvM_SrcPtr)
Arguments       : NvM_BlockIdType BlockId, const void* NvM_SrcPtr
Return type     : Std_ReturnType
                   E_OK: request has been accepted
                   E_NOT_OK: request has not been accepted
Description     : Service to copy the data of the RAM block to its corresponding NV block.
***********************************************************************/
EXTERN Std_ReturnType NvM_WriteBlock(NvM_BlockIdType BlockId, const void* NvM_SrcPtr);

/**************************************************************************
Function name   : Std_ReturnType NvM_RestoreBlockDefaults( NvM_BlockIdType BlockId, void* NvM_DestPtr)
Arguments       : NvM_BlockIdType BlockId, void* NvM_DestPtr
Return type     : Std_ReturnType
                   E_OK: request has been accepted
                   E_NOT_OK: request has not been accepted
Description     : Service to restore the default data to its corresponding RAM block
***********************************************************************/
EXTERN Std_ReturnType NvM_RestoreBlockDefaults( NvM_BlockIdType BlockId, void* NvM_DestPtr);

/**************************************************************************
Function name   : Std_ReturnType NvM_EraseNvBlock(NvM_BlockIdType BlockId)
Arguments       : NvM_BlockIdType BlockId
Return type     : Std_ReturnType
                   E_OK: request has been accepted
                   E_NOT_OK: request has not been accepted
Description     : Service to erase a NV block.
***********************************************************************/
EXTERN Std_ReturnType NvM_EraseNvBlock(NvM_BlockIdType BlockId);

/**************************************************************************
Function name   : void NvM_CancelWriteAll(void)
Arguments       : void
Return type     : void
Description     : Service to cancel a running NvM_WriteAll request.
***********************************************************************/
EXTERN void NvM_CancelWriteAll(void);

/**************************************************************************
Function name   : Std_ReturnType NvM_InvalidateNvBlock(NvM_BlockIdType BlockId)
Arguments       : NvM_BlockIdType BlockId
Return type     : Std_ReturnType
                   E_OK: request has been accepted
                   E_NOT_OK: request has not been accepted
Description     : Service to invalidate a NV block.
***********************************************************************/
EXTERN Std_ReturnType NvM_InvalidateNvBlock(NvM_BlockIdType BlockId);

/**************************************************************************
Function name   : Std_ReturnType NvM_ReadPRAMBlock(NvM_BlockIdType BlockId)
Arguments       : NvM_BlockIdType BlockId
Return type     : Std_ReturnType
                   E_OK: request has been accepted
                   E_NOT_OK: request has not been accepted
Description     : Service to copy the data of the NV block to its corresponding 
                  permanent RAM block.
***********************************************************************/
EXTERN Std_ReturnType NvM_ReadPRAMBlock(NvM_BlockIdType BlockId);

/**************************************************************************
Function name   : Std_ReturnType NvM_WritePRAMBlock(NvM_BlockIdType BlockId)
Arguments       : NvM_BlockIdType BlockId
Return type     : Std_ReturnType
                   E_OK: request has been accepted
                   E_NOT_OK: request has not been accepted
Description     : Service to copy the data of the RAM block to its corresponding 
                  permanent RAM Block
***********************************************************************/
EXTERN Std_ReturnType NvM_WritePRAMBlock(NvM_BlockIdType BlockId);

/**************************************************************************
Function name   : Std_ReturnType NvM_RestorePRAMBlockDefaults(NvM_BlockIdType BlockId)
Arguments       : NvM_BlockIdType BlockId
Return type     : Std_ReturnType
                   E_OK: request has been accepted
                   E_NOT_OK: request has not been accepted
Description     : Service to restore the default data to its corresponding permanent RAM block.
***********************************************************************/
EXTERN Std_ReturnType NvM_RestorePRAMBlockDefaults(NvM_BlockIdType BlockId);

/**************************************************************************
Function name   : void NvM_ReadAll(void)
Arguments       : void
Return type     : void
Description     : Initiates a multi block read request.
***********************************************************************/
EXTERN void NvM_ReadAll(void);

/**************************************************************************
Function name   : void NvM_WriteAll(void)
Arguments       : void
Return type     : void
Description     : Initiates a multi block write request.
***********************************************************************/
EXTERN void NvM_WriteAll(void);

/**************************************************************************
Function name   : void NvM_ValidateAll(void)
Arguments       : void
Return type     : void
Description     : Initiates a multi block validation request
***********************************************************************/
EXTERN void NvM_ValidateAll(void);

/**************************************************************************
Function name   : void NvM_MainFunction(void)
Arguments       : void
Return type     : void
Description     : Service for performing the processing of the NvM jobs.
***********************************************************************/
EXTERN void NvM_MainFunction(void);

EXTERN void NvM_KillWriteAll(void);

#undef EXTERN

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
/**-------------------------------------------------------------------------*/
/*Date              : 21-08-2015                                            */
/*Version           :                                                       */
/*By                : vbalakr3                                              */
/*Traceability      :                                                       */
/*Change Description: Datadesign And Framework implemented, Initial Version */
/*--------------------------------------------------------------------------*/
