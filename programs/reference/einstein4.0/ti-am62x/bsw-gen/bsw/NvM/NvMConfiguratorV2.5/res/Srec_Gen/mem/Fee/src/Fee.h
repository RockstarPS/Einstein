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
*  File Name         :  Fee.h                                                *
*  Module Short Name :  Fee                                                  *
*  VOBName           :                                                       *
*  Author            : vbalakr3                                              *
*  Description       :  External API interface for Fee Module                *
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
#ifndef FEE_H
#define FEE_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Fee_Types.h"
#include "Fee_Cfg.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#ifndef FEE_C
#define EXTERN extern
#else
#define EXTERN
#endif


#define FEE_START_INTERNAL_JOB                      0U
#define FEE_END_INTERNAL_JOB                        1U
#define FEE_SUSPEND_INTERNAL_JOB                    2U
#define FEE_RESUME_INTERNAL_JOB                     3U

#define FEE_BLOCK_VALIDITY_FLAG_VALID               0xFFU
#define FEE_BLOCK_VALIDITY_FLAG_INVALID             0x5AU


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
Function name   : void Fee_Init(void)
Arguments       : void
Return type     : void
Description     : Service to initialize the FEE module. 
**************************************************************************/
EXTERN void Fee_Init(void);

/**************************************************************************
Function name   : void Fee_SetMode(MemIf_ModeType Mode)
Arguments       : MemIf_ModeType Mode
Return type     : void
Description     : Service to call the Fls_SetMode function of the underlying flash driver. 
**************************************************************************/
EXTERN void Fee_SetMode(MemIf_ModeType Mode);

/**************************************************************************
Function name   : Std_ReturnType Fee_Read(uint16 BlockNumber, uint16 BlockOffset, uint8* DataBufferPtr, uint16 Length);
Arguments       : uint16 BlockNumber, uint16 BlockOffset, uint8* DataBufferPtr, uint16 Length
Return type     : Std_ReturnType
                    E_OK: The requested job has been accepted by the module.
                    E_NOT_OK: The requested job has not been accepted by the module.
Description     : Service to initiate a read job.
**************************************************************************/
EXTERN Std_ReturnType Fee_Read(uint16 BlockNumber, uint16 BlockOffset, uint8* DataBufferPtr, uint16 Length);


/**************************************************************************
Function name   : Std_ReturnType Fee_Write(uint16 BlockNumber, const uint8* DataBufferPtr);
Arguments       : uint16 BlockNumber, const uint8* DataBufferPtr
Return type     : Std_ReturnType
                    E_OK: The requested job has been accepted by the module.
                    E_NOT_OK: The requested job has not been accepted by the module.
Description     : Service to initiate a write job.
**************************************************************************/
Std_ReturnType Fee_Write(uint16 BlockNumber, const uint8* DataBufferPtr);


/**************************************************************************
Function name   : Std_ReturnType Fee_Write(uint16 BlockNumber, const uint8* DataBufferPtr);
Arguments       : void
Return type     : void
Description     : Service to initiate a write job.
**************************************************************************/
EXTERN void Fee_Cancel(void);

/**************************************************************************
Function name   : MemIf_StatusType Fee_GetStatus(void)
Arguments       : void
Return type     : Memif_StatusType
                  MEMIF_UNINIT: The FEE module has not been initialized.
                  MEMIF_IDLE: The FEE module is currently idle.
                  MEMIF_BUSY: The FEE module is currently busy.
                  MEMIF_BUSY_INTERNAL: The FEE module is busy with internal management operations.
Description     : Service to return the status.
**************************************************************************/
EXTERN MemIf_StatusType Fee_GetStatus(void);

/**************************************************************************
Function name   : MemIf_JobResultType Fee_GetJobResult(void)
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
EXTERN MemIf_JobResultType Fee_GetJobResult(void);

/**************************************************************************
Function name   : Std_ReturnType Fee_InvalidateBlock( uint16 BlockNumber)
Arguments       : uint16 BlockNumber
Return type     : Std_ReturnType
                  E_OK: The requested job has been accepted by the module.
                  E_NOT_OK - only if DET is enabled: The requested job has not been accepted by the module.
Description     : Service to invalidate a logical block
**************************************************************************/
EXTERN Std_ReturnType Fee_InvalidateBlock( uint16 BlockNumber);

/**************************************************************************
Function name   : void Fee_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr)
Arguments       : Std_VersionInfoType* VersionInfoPtr
Return type     : void
Description     : Service to return the version information of the FEE module.
**************************************************************************/
EXTERN void Fee_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr);

/**************************************************************************
Function name   : Std_ReturnType Fee_EraseImmediateBlock(uint16 BlockNumber)
Arguments       : uint16 BlockNumber
Return type     : Std_ReturnType
                  E_OK: The requested job has been accepted by the module.
                  E_NOT_OK - only if DET is enabled: The requested job has not been accepted by the module.
Description     : This function is called by App/Scheduler when there is an
                  init required. 
**************************************************************************/
EXTERN Std_ReturnType Fee_EraseImmediateBlock(uint16 BlockNumber);

/**************************************************************************
Function name   : void Fee_JobEndNotification(void)
Arguments       : void
Return type     : void
Description     : Service to report to this module the successful end of an asynchronous operation.
**************************************************************************/
EXTERN void Fee_SuspendInternalJob(void); // murali moved this into Fee_Cbk.h

/**************************************************************************
Function name   : void void Fee_JobErrorNotification(void)
Arguments       : void
Return type     : void
Description     : Service to report to this module the failure of an asynchronous operation.
**************************************************************************/
EXTERN void Fee_ResumeInternalJob(void); // murali moved this into Fee_Cbk.h

/**************************************************************************
Function name   : void Fee_MainFunction(void)
Arguments       : void
Return type     : void
Description     : Service to handle the requested read / write / erase jobs and the 
                  internal management operations
**************************************************************************/
EXTERN void Fee_MainFunction(void);


/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/

/*****************************************************************************
*                   Functions                                                *
******************************************************************************/
#undef EXTERN

#endif /* FEE_H */
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
