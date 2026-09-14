/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2013. Visteon Corporation owns all rights to           *
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
*  File Name         :  Ea.h                                                 *
*  Module Short Name :  Ea                                                   *
*  Description       :  External API interface for Ea Module                 *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :                                                         *
*                                                                            *
******************************************************************************/
#ifndef EA_H
#define EA_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Ea_Types.h"
#include "Ea_Cfg.h"
#include "MemLib.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#ifndef EA_C
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

/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/

/*****************************************************************************
*                   Functions                                                *
******************************************************************************/

/**************************************************************************
Function name       : void Ea_Init(void)
Description         : Initializes the EEPROM abstraction module
Parameters (in)     : None. 
Parameters (out)    : None
Return value        : None 
Design Information  : 
**************************************************************************/
EXTERN void Ea_Init(void);

/**************************************************************************
Function name       : void Ea_SetMode(MemIf_ModeType Mode)
Description         : Service to call the Eep_SetMode function of the 
                      underlying EEEPROM driver 
Parameters (in)     : Mode - Desired mode for the underlying EEPROM driver slow/fast 
Parameters (out)    : None
Return value        : None 
Design Information  :
**************************************************************************/
EXTERN void Ea_SetMode(MemIf_ModeType Mode);

/**************************************************************************
Function name       : Std_ReturnType Ea_Read(uint16 BlockNumber, uint16 BlockOffset, 
                                                uint8* DataBufferPtr, uint16 Length);
Description         : Service to initiate a read job. 
Parameters (in)     : BlockNumber   - Number of logical block, also denoting start address 
                                      of that block in EEPROM.
                      BlockOffset   - Read address offset inside the block
                      Length        - Number of bytes to read
Parameters (out)    : DataBufferPtr - Pointer to data buffer
Return value        : E_OK: The requested job has been accepted by the module. 
                      E_NOT_OK: The requested job has not been accepted by the EA module. 
Design Information  :
**************************************************************************/
EXTERN Std_ReturnType Ea_Read(uint16 BlockNumber, uint16 BlockOffset, uint8* DataBufferPtr, uint16 Length);


/**************************************************************************
Function name       : Std_ReturnType Ea_Write(uint16 BlockNumber, 
                                             const uint8* DataBufferPtr);
Description         : Service to initiate a write job.
Parameters (in)     : BlockNumber   - Number of logical block, also denoting 
                                      start address of that block in EEPROM.
                      DataBufferPtr - Pointer to data buffer
Parameters (out)    : DataBufferPtr - Pointer to data buffer
Return value        : E_OK: The requested job has been accepted by the module. 
                      E_NOT_OK: The requested job has not been accepted by the EA module. 
Design Information  :
**************************************************************************/
Std_ReturnType Ea_Write(uint16 BlockNumber, const uint8* DataBufferPtr);


/**************************************************************************
Function name       : void Ea_Cancel(void)
Description         : service to Cancels the ongoing asynchronous operation.
Parameters (in)     : None
Parameters (out)    : None
Return value        : None 
Design Information  :
**************************************************************************/
EXTERN void Ea_Cancel(void);

/**************************************************************************
Function name       : MemIf_StatusType Ea_GetStatus(void)
Description         : Service to return the Status.
Parameters (in)     : None
Parameters (out)    : None
Return value        : MemIf_StatusType   
                      MEMIF_UNINIT: The EA module has not been initialized (yet). 
                      MEMIF_IDLE: The EA module is currently idle. 
                      MEMIF_BUSY: The EA module is currently busy. 
                      MEMIF_BUSY_INTERNAL: The EA module is currently busy with 
                                           internal management operations.
Design Information  :                                                              
**************************************************************************/
EXTERN MemIf_StatusType Ea_GetStatus(void);

/**************************************************************************
Function name       : MemIf_JobResultType Ea_GetJobResult(void)
Description         : Service to return the JobResult.
Parameters (in)     : None
Parameters (out)    : None
Return value        : MemIf_JobResultType - 
                      MEMIF_JOB_OK: The last job has been finished successfully. 
                      MEMIF_JOB_PENDING: The last job is waiting for execution or 
                                         currently being executed. 
                      MEMIF_JOB_CANCELED: The last job has been cancelled. 
                      MEMIF_JOB_FAILED: The last job was not finished successfully (it failed). 
                      MEMIF_BLOCK_INCONSISTENT: The requested block is inconsistent, 
                                                it may contain corrupted data. 
                      MEMIF_BLOCK_INVALID: The requested block has been invalidated, 
                                            the requested operation can not be performed
Design Information  : 
**************************************************************************/
EXTERN MemIf_JobResultType Ea_GetJobResult(void);

/**************************************************************************
Function name       : Std_ReturnType Ea_InvalidateBlock( uint16 BlockNumber)
Description         : Invalidates the block BlockNumber.
Parameters (in)     : BlockNumber - Number of logical block, also denoting 
                                    start address of that block in EEPROM.
Parameters (out)    : None
Return value        : E_OK - The requested job has been accepted by the module. 
                      E_NOT_OK - only if DET is enabled: The requested job 
                                 has not been accepted by the EA module.
Design Information  : 
**************************************************************************/
EXTERN Std_ReturnType Ea_InvalidateBlock( uint16 BlockNumber);

/**************************************************************************
Function name       : void Ea_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr)
Description         : Service to return the version information of the Ea module.
Parameters (in)     : None
Parameters (out)    : VersionInfoPtr - Pointer to standard version information structure.
Return value        : None
Design Information  : 
**************************************************************************/
EXTERN void Ea_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr);

/**************************************************************************
Function name       : Std_ReturnType Ea_EraseImmediateBlock(uint16 BlockNumber)
Description         : Service to Erases the block BlockNumber..
Parameters (in)     : BlockNumber - 
                      Number of logical block, also denoting start address of that block in EEPROM.
Parameters (out)    : None
Return value        : E_OK: The requested job has been accepted by the module. 
                      E_NOT_OK - only if DET is enabled: The requested job 
                                 has not been accepted by the EA module.
Design Information  : 
**************************************************************************/
EXTERN Std_ReturnType Ea_EraseImmediateBlock(uint16 BlockNumber);

/**************************************************************************
Function name       : void Ea_MainFunction(void)
Description         : Service to handle the requested jobs and the internal 
                      management operations
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
EXTERN void Ea_MainFunction(void);

#undef EXTERN

#endif /* EA_H */
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
/*Date              : 13-01-2016                                            */
/*Version           :                                                       */
/*By                : kshaik1                                               */
/*Traceability      :                                                       */
/*Change Description: Datadesign And Framework implemented, Initial Version */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 22-02-2016                                            */
/*Version           :                                                       */
/*By                : kshaik1                                               */
/*Traceability      : 528464                                                */
/*Change Description: Fixing Coverity Warnings                              */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 25-02-2016                                            */
/*Version           :                                                       */
/*By                : kshaik1                                               */
/*Traceability      : 513221                                                */
/*Change Description: Updated for code review comments                      */
/*--------------------------------------------------------------------------*/
