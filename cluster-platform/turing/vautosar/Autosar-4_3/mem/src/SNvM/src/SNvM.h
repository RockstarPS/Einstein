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
*  File Name         :  SNvM.h                                                *
*  Module Short Name :  SNvM                                                  *
*  VOBName           :                                                       *
*  Author            : praj1                                              *
*  Description       :  External API interface for SNvM Module                *
*                                                                            *
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
#ifndef SNVM_H
#define SNVM_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "SNvM_Types.h"
#include "SNvM_Cfg.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#ifndef SNVM_C
#define EXTERN extern
#else
#define EXTERN
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
Function name   : void SNvM_Init(void)
Arguments       : void
Return type     : void
Description     : Service to initialize the SNVM module. 
**************************************************************************/
EXTERN void SNvM_Init(void);

/**************************************************************************
Function name   : void SNvM_SetMode(MemIf_ModeType Mode)
Arguments       : MemIf_ModeType Mode
Return type     : void
Description     : Service to call the Fls_SetMode function of the underlying flash driver. 
**************************************************************************/
EXTERN void SNvM_SetMode(MemIf_ModeType Mode);

/**************************************************************************
Function name   : Std_ReturnType SNvM_Read(uint16 SNvM_ID, uint16 BlockOffset, uint8* DataBufferPtr, uint16 Length);
Arguments       : uint16 SNvM_ID, uint16 BlockOffset, uint8* DataBufferPtr, uint16 Length
Return type     : Std_ReturnType
                    E_OK: The requested job has been accepted by the module.
                    E_NOT_OK: The requested job has not been accepted by the module.
Description     : Service to initiate a read job.
**************************************************************************/
EXTERN Std_ReturnType SNvM_Read(uint16 SNvM_ID, uint16 BlockOffset, uint8* DataBufferPtr, uint16 Length);


/**************************************************************************
Function name   : Std_ReturnType SNvM_Write(uint16 SNvM_ID, const uint8* DataBufferPtr);
Arguments       : uint16 SNvM_ID, const uint8* DataBufferPtr
Return type     : Std_ReturnType
                    E_OK: The requested job has been accepted by the module.
                    E_NOT_OK: The requested job has not been accepted by the module.
Description     : Service to initiate a write job.
**************************************************************************/
Std_ReturnType SNvM_Write(uint16 SNvM_ID, const uint8* DataBufferPtr);


/**************************************************************************
Function name   : void SNvM_MainFunction(void)
Arguments       : void
Return type     : void
Description     : Service to handle the requested read / write / erase jobs and the 
                  internal management operations
**************************************************************************/
EXTERN void SNvM_MainFunction(void);

/**************************************************************************
Function name   : void SNvM_Cancel(void)
Arguments       : void
Return type     : void
Description     : Service to Cancel.
**************************************************************************/
EXTERN void SNvM_Cancel(void);

/**************************************************************************
Function name   : MemIf_StatusType SNvM_GetStatus(void)
Arguments       : void
Return type     : Memif_StatusType
                  MEMIF_UNINIT: The SNvM module has not been initialized.
                  MEMIF_IDLE: The SNvM module is currently idle.
                  MEMIF_BUSY: The SNvM module is currently busy.
                  MEMIF_BUSY_INTERNAL: The SNvM module is busy with internal management operations.
Description     : Service to return the status.
**************************************************************************/
EXTERN MemIf_StatusType SNvM_GetStatus(void);

/**************************************************************************
Function name   : MemIf_JobResultType SNvM_GetJobResult(void)
Arguments       : void
Return type     : MemIf_JobResultType
                  MEMIF_JOB_OK: The last job has been finished successfully.
                  MEMIF_JOB_PENDING: The last job is waiting for execution or currently being executed.
                  MEMIF_JOB_CANCELED: The last job has been canceled (which means it failed).
                  MEMIF_JOB_FAILED: The last job has not been finished successfully (it failed).
                  MEMIF_BLOCK_INCONSISTENT: The requested block is inconsistent, it may contain corrupted data.
                  MEMIF_BLOCK_INVALID: The requested block has been invalidated, the requested read operation can not be performed.
Description     : Service to query the result of the last accepted job issued by the upper layer software.
**************************************************************************/
EXTERN MemIf_JobResultType SNvM_GetJobResult(void);

/**************************************************************************
Function name   : Std_ReturnType SNvM_InvalidateBlock( uint16 BlockNumber)
Arguments       : uint16 BlockNumber
Return type     : Std_ReturnType
                  E_OK: The requested job has been accepted by the module.
                  E_NOT_OK - only if DET is enabled: The requested job has not been accepted by the module.
Description     : Service to invalidate a logical block
**************************************************************************/
EXTERN Std_ReturnType SNvM_InvalidateBlock( uint16 BlockNumber);

/**************************************************************************
Function name   : void SNvM_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr)
Arguments       : Std_VersionInfoType* VersionInfoPtr
Return type     : void
Description     : Service to return the version information of the SNvM module.
**************************************************************************/
EXTERN void SNvM_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr);

/**************************************************************************
Function name   : Std_ReturnType SNvM_EraseImmediateBlock(uint16 BlockNumber)
Arguments       : uint16 BlockNumber
Return type     : Std_ReturnType
                  E_OK: The requested job has been accepted by the module.
                  E_NOT_OK - only if DET is enabled: The requested job has not been accepted by the module.
Description     : This function is called by App/Scheduler when there is an
                  init required. 
**************************************************************************/
EXTERN Std_ReturnType SNvM_EraseImmediateBlock(uint16 BlockNumber);

/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/

/*****************************************************************************
*                   Functions                                                *
******************************************************************************/
#undef EXTERN

#endif /* SNVM_H */
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
/**------------------------------------------------------------------------------*/
/*Date              : 23-02-2021                                                 */
/*Version           :                                                            */
/*By                : praj1                                                      */
/*Traceability      :   1222451                                                  */
/*Change Description: SNvM Datadesign And Framework implemented, Initial Version */
/*-------------------------------------------------------------------------------*/
/**------------------------------------------------------------------------------*/
/*Date              : 23-02-2022                                                 */
/*Version           :                                                            */
/*By                : gthanapp                                                   */
/*Traceability      : 1918257                                                  */
/*Change Description: SNvM Datadesign And Framework implemented, Initial Version */
/*-------------------------------------------------------------------------------*/

