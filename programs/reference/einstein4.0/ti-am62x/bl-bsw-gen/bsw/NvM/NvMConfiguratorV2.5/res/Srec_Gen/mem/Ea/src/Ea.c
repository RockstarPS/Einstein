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
*  File Name         :  Ea.c                                                 *
*  Module Short Name :  Ea                                                   *
*  Description       : Request handling of Ea data module                    *
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
#ifndef EA_C
#define EA_C
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Ea.h"
#include "Ea_Cbk.h"
#define EA_CODE_SEC_START
#include "MemMap.h"


#define EA_DATA_SEC_START
#include "MemMap.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define EA_INVALIDATION_BIT         (uint8)1 // BIT 0

#define EA_DATASET_SELECTION_MASK   ((1 << Ea_DatasetSelectionBits) -1)

#define EA_ERASED_EEPROM_VALUE      (uint8)255

#define EA_INVALID_INSTANCE_COUNT   (uint8)255

#define EA_VERIFICATION_ENABLED     (uint8)2

/* Job JobActiveId */
#define EA_JOB_IDLE                      (uint8)0
#define EA_JOB_READ                      (uint8)1
#define EA_JOB_WRITE                     (uint8)2
#define EA_JOB_ERASE                     (uint8)3
#define EA_JOB_INVALIDATE                (uint8)4

/* Ea Internal States */
#define EA_STATE_IDLE                    (uint8)0

#define EA_STATE_READ_START              (uint8)1
#define EA_STATE_READ_FIND_INSTANCE      (uint8)2
#define EA_STATE_READ_HEADER             (uint8)3
#define EA_STATE_READ_HEADER_VALIDATE    (uint8)4
#define EA_STATE_READ_PAYLOAD            (uint8)5
#define EA_STATE_READ_PAYLOAD_CBK_WAIT   (uint8)6
#define EA_STATE_READ_END_NOTIFY         (uint8)7
#define EA_STATE_READ_ERROR_NOTIFY       (uint8)8

#define EA_STATE_WRITE_START             (uint8)9
#define EA_STATE_WRITE_FIND_INSTANCE     (uint8)10
#define EA_STATE_WRITE_HEADER1           (uint8)11
#define EA_STATE_WRITE_HEADER1_CBK_WAIT  (uint8)12
#define EA_STATE_VERIFY_HEADER1          (uint8)13
#define EA_STATE_VERIFY_HEADER1_CBK_WAIT (uint8)14
#define EA_STATE_WRITE_PAYLOAD           (uint8)15
#define EA_STATE_WRITE_PAYLOAD_CBK_WAIT  (uint8)16
#define EA_STATE_VERIFY_PAYLOAD          (uint8)17
#define EA_STATE_VERIFY_PAYLOAD_CBK_WAIT (uint8)18
#define EA_STATE_WRITE_HEADER2           (uint8)19
#define EA_STATE_WRITE_HEADER2_CBK_WAIT  (uint8)20
#define EA_STATE_VERIFY_HEADER2          (uint8)21
#define EA_STATE_VERIFY_HEADER2_CBK_WAIT (uint8)22
#define EA_STATE_WRITE_END_NOTIFY        (uint8)23
#define EA_STATE_WRITE_ERROR_NOTIFY      (uint8)24
 
#define EA_STATE_ERASE                   (uint8)25
#define EA_STATE_ERASE_CBK_WAIT          (uint8)26



#define EA_MAX_INSTANCE_COUNTER			(uint8)127


/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef struct{
  uint8*                ClientAddress;
  uint16                BlockNumber;
  uint16                Offset;
  uint16                Length;
  uint16                BlockIndex;
  uint8                 JobActiveId;
  uint8                 JobState;
  MemIf_JobResultType   JobResult;
  MemIf_JobResultType   Eep_JobResult;
  uint8                 ManagementData[2];
  boolean               BlockInvalid;
  boolean               CbkServiced;
  boolean               ProcessState;
}Ea_Descriptor_Type;

typedef struct{
  uint8 ValidCounter;
  uint8 ValidInstance;
  uint8 ReadInstance;
  uint8 ReadCounter;
  uint8 HeaderValue[EA_BLOCK_OVERHEAD];
}Ea_InstanceSearch_Type;

typedef struct{
  uint8 CurrentInstanceIndex;
  uint8 CurrentInstanceCounter;
}Ea_BlockInformation_Type;


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

static Ea_Descriptor_Type       Ea_Descriptor;
static Ea_InstanceSearch_Type   Ea_InstanceSearch;
static Ea_BlockInformation_Type Ea_BlockInformation[EA_NUM_BLOCKS];

/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/
static void Ea_ProcessJob(void);
static void Ea_ProcessJob_Read(void);
static void Ea_ProcessJob_Write(void);
static void Ea_ProcessJob_Erase(void);

static uint16 Ea_GetBlockIndex(uint16 BlockNumber_u16);
static uint8 Ea_ValidateManagementData(uint8* p_Value_u8);
static boolean Ea_JobEndNote_Flg;
static void Ea_CheckForValidInstance(void);
static void Ea_FindInstance(void);
static uint8 Ea_GetCounterFromHeader(uint8 *Header);
static void Ea_ReadHeader(void);
static void Ea_ReadHeaderValidate(void);
static void Ea_ReadPayLoad(void);
static void Ea_ReadPayLoadCbkWait(void);
static void Ea_ReadEndNotify(void);
static void Ea_ReadErrorNotify(void);

static void Ea_WriteHeader1(void);
static void Ea_WriteHeader1CbkWait(void);
static void Ea_WritePayload(void);
static void Ea_WritePayloadCbkWait(void);
static void Ea_WriteHeader2(void);
static void Ea_WriteHeader2CbkWait(void);
static void Ea_WriteEndNotify(void);
static void Ea_WriteErrorNotify(void);

static void Ea_VerifyHeader1(void);
static void Ea_VerifyHeader1CbkWait(void);
static void Ea_VerifyPayload(void);
static void Ea_VerifyPayloadCbkWait(void);
static void Ea_VerifyHeader2(void);
static void Ea_VerifyHeader2CbkWait(void);

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
void Ea_Init(void)
{
    uint8 Count;
    
    MemLib_MemSet(&Ea_Descriptor, 0, sizeof(Ea_Descriptor_Type));
    
	Ea_InstanceSearch.ReadCounter = EA_ERASED_EEPROM_VALUE;
	Ea_InstanceSearch.ReadInstance = EA_ERASED_EEPROM_VALUE;
	Ea_InstanceSearch.ValidCounter = EA_ERASED_EEPROM_VALUE;
    Ea_InstanceSearch.ValidInstance = EA_INVALID_INSTANCE_COUNT;
    for (Count=0U; Count < EA_NUM_BLOCKS;  Count++)
    {
		Ea_BlockInformation[Count].CurrentInstanceCounter = EA_ERASED_EEPROM_VALUE;
		Ea_BlockInformation[Count].CurrentInstanceIndex = EA_INVALID_INSTANCE_COUNT;
    }

}

/**************************************************************************
Function name       : void Ea_SetMode(MemIf_ModeType Mode)
Description         : Service to call the Eep_SetMode function of the 
                      underlying EEEPROM driver 
Parameters (in)     : Mode - Desired mode for the underlying EEPROM driver slow/fast 
Parameters (out)    : None
Return value        : None 
Design Information  :
**************************************************************************/
void Ea_SetMode(MemIf_ModeType Mode)
{
}

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
Std_ReturnType Ea_Read(uint16 BlockNumber, uint16 BlockOffset, uint8* DataBufferPtr, uint16 Length)
{
    Std_ReturnType retVal;
    retVal = E_NOT_OK ;
    if (Ea_Descriptor.JobActiveId == EA_JOB_IDLE)
    {
        MemLib_MemSet(&Ea_Descriptor, 0, sizeof(Ea_Descriptor_Type));
        Ea_Descriptor.BlockNumber   = BlockNumber;
        Ea_Descriptor.Offset        = BlockOffset;
        Ea_Descriptor.Length        = Length;
        Ea_Descriptor.ClientAddress = DataBufferPtr;
        Ea_Descriptor.JobActiveId   = EA_JOB_READ;
        Ea_Descriptor.JobResult     = MEMIF_JOB_PENDING;
        Ea_Descriptor.JobState      = EA_STATE_READ_START;
        retVal = E_OK;
    }
    
    return retVal;
}

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
Std_ReturnType Ea_Write(uint16 BlockNumber, const uint8* DataBufferPtr)
{
    Std_ReturnType retVal;
    retVal = E_NOT_OK ;
    if (Ea_Descriptor.JobActiveId == EA_JOB_IDLE)
    {
        MemLib_MemSet(&Ea_Descriptor, 0, sizeof(Ea_Descriptor_Type));
        Ea_Descriptor.BlockNumber   = BlockNumber;
        Ea_Descriptor.ClientAddress = (uint8 *)DataBufferPtr;
        Ea_Descriptor.JobActiveId   = EA_JOB_WRITE;
        Ea_Descriptor.JobResult     = MEMIF_JOB_PENDING;
        Ea_Descriptor.JobState      = EA_STATE_WRITE_START;
        retVal = E_OK;
    }
    
    return retVal;
}
/**************************************************************************
Function name       : void Ea_Cancel(void)
Description         : service to Cancels the ongoing asynchronous operation.
Parameters (in)     : None
Parameters (out)    : None
Return value        : None 
Design Information  :
**************************************************************************/
void Ea_Cancel(void)
{
}
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
MemIf_StatusType Ea_GetStatus(void)
{
    MemIf_StatusType retVal;
    retVal = MEMIF_BUSY;
    if (Ea_Descriptor.JobActiveId == EA_JOB_IDLE)
    {
        /* Ea Module is idle */
        retVal = MEMIF_IDLE;
    }
    return retVal;
}

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
MemIf_JobResultType Ea_GetJobResult(void)
{
  return (Ea_Descriptor.JobResult);
}

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
Std_ReturnType Ea_InvalidateBlock( uint16 BlockNumber)
{
    Std_ReturnType retVal;
    retVal = E_NOT_OK ;
    return retVal;
}

/**************************************************************************
Function name       : void Ea_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr)
Description         : Service to return the version information of the Ea module.
Parameters (in)     : None
Parameters (out)    : VersionInfoPtr - Pointer to standard version information structure.
Return value        : None
Design Information  : 
**************************************************************************/
void Ea_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr)
{
}

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
Std_ReturnType Ea_EraseImmediateBlock(uint16 BlockNumber)
{
  return E_NOT_OK;
}

/**************************************************************************
Function name       : void Ea_JobEndNotification(void)
Description         : Service to report to this module the successful end of 
                      an asynchronous operation
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
void Ea_JobEndNotification(void)
{
	if (Ea_JobEndNote_Flg==1)
	{
		Ea_JobEndNote_Flg=0;
		Ea_Descriptor.CbkServiced = TRUE;
	    Ea_Descriptor.Eep_JobResult = MEMIF_JOB_OK;	
	}

}

/**************************************************************************
Function name       : void void Ea_JobErrorNotification(void)
Description         : Service to report to this module the failure of an 
                      asynchronous operation.
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
void Ea_JobErrorNotification(void)
{
    uint8 DeviceIndex;
	if (Ea_JobEndNote_Flg==1)
	{
		Ea_JobEndNote_Flg = 0;
	    Ea_Descriptor.CbkServiced = TRUE;

    DeviceIndex = Ea_Config[Ea_Descriptor.BlockIndex].DeviceIndex;

	    if ( NULL != Ea_DeviceFunctionPointer[DeviceIndex].GetEepJobResultPointer )
	    {
	        Ea_Descriptor.Eep_JobResult = Ea_DeviceFunctionPointer[DeviceIndex].GetEepJobResultPointer();
	    }
	    else
	    {
	       /* TODO: Issue Det error */
	    }
	}
}

/**************************************************************************
Function name       : void Ea_MainFunction(void)
Description         : Service to handle the requested jobs and the internal 
                      management operations
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
void Ea_MainFunction(void)
{
    if (Ea_Descriptor.JobActiveId != EA_JOB_IDLE)
    {
        do
        {
        Ea_ProcessJob();
        }while(FALSE != Ea_Descriptor.ProcessState);
    }
}


/**************************************************************************
Function name       : void Ea_ProcessJob(void)
Description         : Service to handle the requested jobs and the internal 
                      management operations
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_ProcessJob(void)
{
    switch(Ea_Descriptor.JobActiveId)
    {
        case EA_JOB_READ:
            Ea_ProcessJob_Read();
            break;
        case EA_JOB_WRITE:
            Ea_ProcessJob_Write();
            break;
        case EA_JOB_ERASE:
            Ea_ProcessJob_Erase();
            break;
        default:
            //do nothing
            break;
    }
}

/**************************************************************************
Function name       : void Ea_ProcessJob_Read(void)
Description         : Service to handle the read request job 
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_ProcessJob_Read(void)
{
    switch(Ea_Descriptor.JobState)
    {
        case EA_STATE_READ_START:
            Ea_CheckForValidInstance();
            break;
        case EA_STATE_READ_FIND_INSTANCE:
            Ea_FindInstance();
            break;
        case EA_STATE_READ_HEADER:
            Ea_ReadHeader();
            break;
        case EA_STATE_READ_HEADER_VALIDATE:
            Ea_ReadHeaderValidate();
            break;
        case EA_STATE_READ_PAYLOAD:
            Ea_ReadPayLoad();
            break;
        case EA_STATE_READ_PAYLOAD_CBK_WAIT:
            Ea_ReadPayLoadCbkWait();
            break;
        case EA_STATE_READ_END_NOTIFY:
            Ea_ReadEndNotify();
            break;
        case EA_STATE_READ_ERROR_NOTIFY:
            Ea_ReadErrorNotify();
            break;
        default:
            //do nothing
            break;
    }

}

/**************************************************************************
Function name       : void Ea_ProcessJob_Write(void)
Description         : Service to handle the write request job 
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_ProcessJob_Write(void)
{
    switch(Ea_Descriptor.JobState)
    {
        case EA_STATE_WRITE_START:
            Ea_CheckForValidInstance();
            break;
        case EA_STATE_WRITE_FIND_INSTANCE:
            Ea_FindInstance();
            break;        
        case EA_STATE_WRITE_HEADER1:
            Ea_WriteHeader1();
            break;
        case EA_STATE_WRITE_HEADER1_CBK_WAIT:
            Ea_WriteHeader1CbkWait();
            break;
        case EA_STATE_VERIFY_HEADER1:
            Ea_VerifyHeader1();
            break;
        case EA_STATE_VERIFY_HEADER1_CBK_WAIT:
            Ea_VerifyHeader1CbkWait();
            break;
        case EA_STATE_WRITE_PAYLOAD:
            Ea_WritePayload();
            break;
        case EA_STATE_WRITE_PAYLOAD_CBK_WAIT:
            Ea_WritePayloadCbkWait();
            break;
        case EA_STATE_VERIFY_PAYLOAD:
            Ea_VerifyPayload();
            break;
        case EA_STATE_VERIFY_PAYLOAD_CBK_WAIT:
            Ea_VerifyPayloadCbkWait();
            break;
        case EA_STATE_WRITE_HEADER2:
            Ea_WriteHeader2();
            break;
        case EA_STATE_WRITE_HEADER2_CBK_WAIT:
            Ea_WriteHeader2CbkWait();
            break;
        case EA_STATE_VERIFY_HEADER2:
            Ea_VerifyHeader2();
            break;
        case EA_STATE_VERIFY_HEADER2_CBK_WAIT:
            Ea_VerifyHeader2CbkWait();
            break;
        case EA_STATE_WRITE_END_NOTIFY:
            Ea_WriteEndNotify();
            break;
        case EA_STATE_WRITE_ERROR_NOTIFY:
            Ea_WriteErrorNotify();
            break;
        default:
            //do nothing
            break;
    }
}
/**************************************************************************
Function name       : void Ea_ProcessJob_Erase(void)
Description         : Service to handle the Erase request job 
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_ProcessJob_Erase(void)
{
    switch(Ea_Descriptor.JobState)
    {
        case EA_STATE_ERASE:
            break;
        case EA_STATE_ERASE_CBK_WAIT:
            break;
        default:
            //do nothing
            break;
        
    }
}
/**************************************************************************
Function name       : uint16 Ea_GetBlockIndex(uint16 BlockNumber_u16)
Description         : Service to get the Real Block Number 
Parameters (in)     : BlockNumber_u16
Parameters (out)    : None
Return value        : RealBlockNumber_u16
Design Information  : 
**************************************************************************/
static uint16 Ea_GetBlockIndex(uint16 BlockNumber_u16)
{
     return (uint16)((uint16)(BlockNumber_u16 >> (uint16)EA_DATASET_SELECTION_MASK) - (uint16)1u); /*CERT C 17224483*/
}

/**************************************************************************
Function name       : void Ea_ReadStart(void);
Description         : service start the internal read start state 
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_CheckForValidInstance(void)
{
    uint16 PhyEepAddr;
    uint8 DeviceIndex;
    Std_ReturnType ErrorStatus;

    Ea_Descriptor.BlockIndex = Ea_GetBlockIndex(Ea_Descriptor.BlockNumber);
    

    if(Ea_Config[Ea_Descriptor.BlockIndex].NoOfInstances > 1U)
    {
        if(Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceIndex != EA_INVALID_INSTANCE_COUNT)
        {

            if(Ea_Descriptor.JobActiveId == EA_JOB_READ)
            {
                Ea_Descriptor.JobState = EA_STATE_READ_HEADER;
            }
            else
            {
                Ea_Descriptor.JobState = EA_STATE_WRITE_HEADER1;
            }
            Ea_Descriptor.ProcessState = TRUE;
        }
        else
        {
            PhyEepAddr = Ea_Config[Ea_Descriptor.BlockIndex].BlockBaseAddress;
            DeviceIndex = Ea_Config[Ea_Descriptor.BlockIndex].DeviceIndex;

            if ( NULL != Ea_DeviceFunctionPointer[DeviceIndex].ReadEepPointer )
            {
                ErrorStatus = Ea_DeviceFunctionPointer[DeviceIndex].ReadEepPointer(PhyEepAddr,
                                                                             &Ea_InstanceSearch.HeaderValue[0],
                                                                             EA_BLOCK_OVERHEAD);
                if ( E_OK == ErrorStatus )
                {
					Ea_JobEndNote_Flg=1;
                    Ea_InstanceSearch.ReadCounter   = EA_ERASED_EEPROM_VALUE;
                    Ea_InstanceSearch.ReadInstance  = 0U;
                    Ea_InstanceSearch.ValidCounter  = EA_ERASED_EEPROM_VALUE;
                    Ea_InstanceSearch.ValidInstance = EA_INVALID_INSTANCE_COUNT;

                    if ( Ea_Descriptor.JobActiveId == EA_JOB_READ )
                    {
                        Ea_Descriptor.JobState = EA_STATE_READ_FIND_INSTANCE;
                    }
                    else
                    {
                        Ea_Descriptor.JobState = EA_STATE_WRITE_FIND_INSTANCE;
                    }
                    Ea_Descriptor.ProcessState = FALSE;
                }
                else
                {
                    Ea_Descriptor.JobResult = MEMIF_JOB_FAILED;
                    if ( Ea_Descriptor.JobActiveId == EA_JOB_READ )
                    {
                        Ea_Descriptor.JobState = EA_STATE_READ_ERROR_NOTIFY;
                    }
                    else
                    {
                        Ea_Descriptor.JobState = EA_STATE_WRITE_ERROR_NOTIFY;
                    }
                    Ea_Descriptor.ProcessState = TRUE;
                }
            }
		    else
		    {
		       /* TODO: Issue Det error */
		    }
        }
    }
    else
    {
        Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceIndex = 0U;
		if(Ea_Descriptor.JobActiveId == EA_JOB_READ)
		{
	        Ea_Descriptor.JobState  = EA_STATE_READ_HEADER;
		}
		else
		{
			Ea_Descriptor.JobState = EA_STATE_WRITE_HEADER1;	
		}
        Ea_Descriptor.ProcessState = TRUE;
    }
}
static uint8 Ea_GetCounterFromHeader(uint8 *Header)
{
    return ((uint8)(*Header << 1));
}

/**************************************************************************
Function name       : void Ea_ReadFindInstance(void);
Description         : Service to find the Instance Position
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_FindInstance(void)
{
    uint16 PhyEepAddr;
    uint8 NotifyError;
    boolean CbkStatus;
    Std_ReturnType ErrorStatus;
    uint16 DeviceIndex;
	uint8 EaConfigIndex;

    NotifyError = FALSE;
    EA_ENTER_CRITICAL_SECTION();
    CbkStatus = Ea_Descriptor.CbkServiced;  
    EA_EXIT_CRITICAL_SECTION();    
    
	EaConfigIndex = Ea_Config[Ea_Descriptor.BlockIndex].NoOfInstances - 1U;
    if(FALSE != CbkStatus)
    {
        EA_ENTER_CRITICAL_SECTION();
        Ea_Descriptor.CbkServiced = FALSE;  
        EA_EXIT_CRITICAL_SECTION();    

        
        if(Ea_Descriptor.Eep_JobResult == MEMIF_JOB_OK)
        { 
            if(FALSE != Ea_ValidateManagementData(&Ea_InstanceSearch.HeaderValue[0]))
            {
				Ea_InstanceSearch.ReadCounter = Ea_GetCounterFromHeader(&Ea_InstanceSearch.HeaderValue[0]);
				if(Ea_InstanceSearch.ValidInstance == EA_INVALID_INSTANCE_COUNT) 
				{
					Ea_InstanceSearch.ValidInstance = Ea_InstanceSearch.ReadInstance;	
					Ea_InstanceSearch.ValidCounter = Ea_InstanceSearch.ReadCounter;
				}
				else
				{
					if(Ea_InstanceSearch.ValidInstance > (EA_MAX_INSTANCE_COUNTER - EaConfigIndex) 
					&& Ea_InstanceSearch.ReadInstance  < EaConfigIndex)
					{
						Ea_InstanceSearch.ValidInstance = Ea_InstanceSearch.ReadInstance;	
						Ea_InstanceSearch.ValidCounter = Ea_InstanceSearch.ReadCounter;
					}
					else if(Ea_InstanceSearch.ReadInstance > (EA_MAX_INSTANCE_COUNTER - EaConfigIndex) 
					     && Ea_InstanceSearch.ValidInstance < EaConfigIndex)
					{
						 /* Do Nothing */
					}
					else
					{
						if(Ea_InstanceSearch.ReadInstance > Ea_InstanceSearch.ValidInstance)
						{
							Ea_InstanceSearch.ValidInstance = Ea_InstanceSearch.ReadInstance;	
							Ea_InstanceSearch.ValidCounter = Ea_InstanceSearch.ReadCounter;							
						}
					}
				}
			}
				/* This has been checked against (Ea_InstanceSearch.ReadInstance + 1). Since instance configuration ranges from 1 to n */
				/* and Search instance valid from 0 to n-1 */
			if((Ea_InstanceSearch.ReadInstance + 1U) < Ea_Config[Ea_Descriptor.BlockIndex].NoOfInstances )
			{
				Ea_InstanceSearch.ReadInstance = Ea_InstanceSearch.ReadInstance + 1U;
			    PhyEepAddr = ( Ea_Config[Ea_Descriptor.BlockIndex].BlockBaseAddress + \
			                         (( Ea_Config[Ea_Descriptor.BlockIndex].BlockSize + EA_BLOCK_OVERHEAD)* \
			                                Ea_InstanceSearch.ReadInstance)) ;

                DeviceIndex = Ea_Config[Ea_Descriptor.BlockIndex].DeviceIndex;
                if ( NULL != Ea_DeviceFunctionPointer[DeviceIndex].ReadEepPointer )
                {
                    ErrorStatus = Ea_DeviceFunctionPointer[DeviceIndex].ReadEepPointer(PhyEepAddr,
                                                                                 &Ea_InstanceSearch.HeaderValue[0],
                                                                                 EA_BLOCK_OVERHEAD);
                   if ( E_OK == ErrorStatus )
                   {
					   Ea_JobEndNote_Flg=1;
                        if ( Ea_Descriptor.JobActiveId == EA_JOB_READ )
                        {
                            Ea_Descriptor.JobState = EA_STATE_READ_FIND_INSTANCE;
                        }
                        else
                        {
                            Ea_Descriptor.JobState = EA_STATE_WRITE_FIND_INSTANCE;
                        }
                        Ea_Descriptor.ProcessState = FALSE;
                   }
                   else
                   {
                        NotifyError = TRUE;
                   }
                }
			    else
			    {
			       /* TODO: Issue Det error */
			    }
			}
			else
			{
				if(Ea_InstanceSearch.ValidInstance != EA_INVALID_INSTANCE_COUNT)
				{
					Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceIndex = Ea_InstanceSearch.ValidInstance;
					Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceCounter = Ea_InstanceSearch.ValidCounter;
					Ea_Descriptor.ProcessState = TRUE;
					if(Ea_Descriptor.JobActiveId == EA_JOB_READ)
					{
						Ea_Descriptor.JobState = EA_STATE_READ_HEADER;
					}
					else
					{
						Ea_Descriptor.JobState = EA_STATE_WRITE_HEADER1;	
					}
				}
				else
				{
					if(Ea_Descriptor.JobActiveId == EA_JOB_READ)
					{
						Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceIndex = 0U;
						Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceCounter = 0U;
						NotifyError = TRUE;
					}
					else
					{
						Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceIndex = 0U;
						Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceCounter = 0U;
						Ea_Descriptor.JobState = EA_STATE_WRITE_HEADER1;
					}
				}
			}

		}
        else
        {
			NotifyError = TRUE;
        }    
		if(NotifyError == TRUE)
		{
			Ea_Descriptor.JobResult = MEMIF_JOB_FAILED;
            Ea_Descriptor.ProcessState = TRUE;
            Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceCounter = 0xFFU;
            Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceIndex = 0xFFU;
			if(Ea_Descriptor.JobActiveId == EA_JOB_READ)
			{
				Ea_Descriptor.JobState = EA_STATE_READ_ERROR_NOTIFY;
			}
			else
			{
				Ea_Descriptor.JobState = EA_STATE_WRITE_ERROR_NOTIFY;	
			}
		}
    }
    else
    {
        /* do nothing */
    }
}
/**************************************************************************
Function name       : void Ea_ReadHeader(void)
Description         : Service to read Header
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_ReadHeader(void)
{
    uint16 PhyEepAddr;
    uint8 DeviceIndex;
    Std_ReturnType ErrorStatus;

    /* Header Physical Address = Block Base Addr +  ((block size + Overhead) * instance Number) */
    PhyEepAddr = ( Ea_Config[Ea_Descriptor.BlockIndex].BlockBaseAddress + \
                         (( Ea_Config[Ea_Descriptor.BlockIndex].BlockSize + EA_BLOCK_OVERHEAD)* \
                                Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceIndex)) ;

    DeviceIndex = Ea_Config[Ea_Descriptor.BlockIndex].DeviceIndex;

    if ( Ea_DeviceFunctionPointer[DeviceIndex].ReadEepPointer != NULL )
    {
        ErrorStatus = Ea_DeviceFunctionPointer[DeviceIndex].ReadEepPointer(PhyEepAddr,
                                                                     &Ea_Descriptor.ManagementData[0],
                                                                     EA_BLOCK_OVERHEAD);
        if ( E_OK == ErrorStatus )
        {
			Ea_JobEndNote_Flg=1;
            Ea_Descriptor.JobState     = EA_STATE_READ_HEADER_VALIDATE;
            Ea_Descriptor.ProcessState = FALSE;
        }
        else
        {
            Ea_Descriptor.JobResult    = MEMIF_JOB_FAILED;
            Ea_Descriptor.JobState     = EA_STATE_READ_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }
    else
    {
       /* TODO: Issue Det error */
    }

}

/**************************************************************************
Function name       : void Ea_ReadHeaderValidate(void)
Description         : Service to read wait for call back and validate Header
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_ReadHeaderValidate(void)
{
    boolean CbkStatus;
    EA_ENTER_CRITICAL_SECTION();
    CbkStatus = Ea_Descriptor.CbkServiced;  
    EA_EXIT_CRITICAL_SECTION();    

    if(FALSE != CbkStatus)
    {
        EA_ENTER_CRITICAL_SECTION();
        Ea_Descriptor.CbkServiced = FALSE;  
        EA_EXIT_CRITICAL_SECTION();    
        
        if(Ea_Descriptor.Eep_JobResult == MEMIF_JOB_OK)
        {
            /* Validate the Header Data */
            if(FALSE != Ea_ValidateManagementData(&Ea_Descriptor.ManagementData[0]))
            {
                /*Check for the Invalid Block */
				Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceCounter = Ea_GetCounterFromHeader(&Ea_Descriptor.ManagementData[0]);		
                /* Valid Block */
                Ea_Descriptor.JobState  = EA_STATE_READ_PAYLOAD;
                Ea_Descriptor.ProcessState = TRUE;
            }
            else
            {
                Ea_Descriptor.JobResult = MEMIF_BLOCK_INCONSISTENT;
                Ea_Descriptor.JobState  = EA_STATE_READ_ERROR_NOTIFY;
                Ea_Descriptor.ProcessState = TRUE;
            } 
        }
        else
        {
            Ea_Descriptor.JobResult = Ea_Descriptor.Eep_JobResult;
            Ea_Descriptor.JobState  = EA_STATE_READ_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }
}

/**************************************************************************
Function name       : void Ea_ReadPayLoad(void)
Description         : Service to read data
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_ReadPayLoad(void)
{
    uint16 PhyEepAddr;
    uint8 DeviceIndex;
    Std_ReturnType ErrorStatus;

    /* Pay Load Physical Address = Block Base Addr +  ((block size + Overhead) * instance Number) + OverHead + Offset*/
    PhyEepAddr = ( Ea_Config[Ea_Descriptor.BlockIndex].BlockBaseAddress + \
                         (( Ea_Config[Ea_Descriptor.BlockIndex].BlockSize + EA_BLOCK_OVERHEAD)* \
                            Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceIndex) + \
                            EA_BLOCK_OVERHEAD + \
                            Ea_Descriptor.Offset);
    DeviceIndex = Ea_Config[Ea_Descriptor.BlockIndex].DeviceIndex;
    
    if ( NULL != Ea_DeviceFunctionPointer[DeviceIndex].ReadEepPointer )
    {
        ErrorStatus = Ea_DeviceFunctionPointer[DeviceIndex].ReadEepPointer(PhyEepAddr,
                                                                     Ea_Descriptor.ClientAddress,
                                                                     Ea_Descriptor.Length);
        if ( E_OK == ErrorStatus )
        {
			Ea_JobEndNote_Flg=1;
        	Ea_Descriptor.JobState  = EA_STATE_READ_PAYLOAD_CBK_WAIT;
            Ea_Descriptor.ProcessState = FALSE;
        }
        else
        {
            Ea_Descriptor.JobResult    = MEMIF_JOB_FAILED;
            Ea_Descriptor.JobState     = EA_STATE_READ_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }
    else
    {
       /* TODO: Issue Det error */
    }
}


/**************************************************************************
Function name       : void Ea_ReadPayLoadCbkWait(void)
Description         : Service to wait for read data call back
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_ReadPayLoadCbkWait(void)
{
    boolean CbkStatus;
    EA_ENTER_CRITICAL_SECTION();
    CbkStatus = Ea_Descriptor.CbkServiced;  
    EA_EXIT_CRITICAL_SECTION();    
    
    if(FALSE != CbkStatus)
    {
        EA_ENTER_CRITICAL_SECTION();
        Ea_Descriptor.CbkServiced = FALSE;  
        EA_EXIT_CRITICAL_SECTION();    

        Ea_Descriptor.JobResult = Ea_Descriptor.Eep_JobResult;
        Ea_Descriptor.JobState  = EA_STATE_READ_ERROR_NOTIFY;
        Ea_Descriptor.ProcessState = TRUE;
        if(Ea_Descriptor.Eep_JobResult == MEMIF_JOB_OK)
        {
            Ea_Descriptor.JobState  = EA_STATE_READ_END_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }

}

/**************************************************************************
Function name       : void Ea_ReadEndNotify(void)
Description         : Service to send read end notification to Upper Layer
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_ReadEndNotify(void)
{
    Ea_Descriptor.JobActiveId = EA_JOB_IDLE;
    Ea_Descriptor.JobState = EA_STATE_IDLE;
    Ea_Descriptor.ProcessState = FALSE;
    Ea_Descriptor.JobResult = MEMIF_JOB_OK;
    Ea_CbkJobEndNotification();
}


/**************************************************************************
Function name       : void Ea_ReadErrorNotify(void)
Description         : Service to send read error notification to Upper Layer
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_ReadErrorNotify(void)
{
    Ea_Descriptor.JobActiveId = EA_JOB_IDLE;
    Ea_Descriptor.JobState = EA_STATE_IDLE;
    Ea_Descriptor.ProcessState = FALSE;
    Ea_CbkJobErrorNotification();
}
/**************************************************************************
Function name       : uint8 Ea_ValidateManagementData(uint8* )
Description         : Service to validate Header  bytes
Parameters (in)     : HeaderValue
Parameters (out)    : None
Return value        : TRUE/FALSE
Design Information  : 
**************************************************************************/
static uint8 Ea_ValidateManagementData(uint8* p_HeaderValue_u8)
{
	uint8 RetVal;
	RetVal = FALSE;
	if(p_HeaderValue_u8[0] == (uint8)(~p_HeaderValue_u8[1]))
	{
		RetVal = TRUE;
	}
    return  RetVal;
}
/**************************************************************************
Function name       : static void Ea_WriteHeader1(void)
Description         : Service to write Header
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_WriteHeader1(void)
{
    uint16 PhyEepAddr;
    uint8 DeviceIndex;
    Std_ReturnType ErrorStatus;

    Ea_Descriptor.BlockIndex = Ea_GetBlockIndex(Ea_Descriptor.BlockNumber);
        
    PhyEepAddr  = ( Ea_Config[Ea_Descriptor.BlockIndex].BlockBaseAddress + \
                           ((Ea_Config[Ea_Descriptor.BlockIndex].BlockSize + EA_BLOCK_OVERHEAD)* \
                             Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceIndex)) ;
    
    if(Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceCounter < EA_MAX_INSTANCE_COUNTER)
    {
        Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceCounter ++;
    }
    else
    {
		Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceCounter = 0U;
    }
    Ea_Descriptor.ManagementData[0] = (uint8)(Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceCounter << 1);
    DeviceIndex = Ea_Config[Ea_Descriptor.BlockIndex].DeviceIndex;

    if ( NULL != Ea_DeviceFunctionPointer[DeviceIndex].WriteEepPointer )
    {
        ErrorStatus = Ea_DeviceFunctionPointer[DeviceIndex].WriteEepPointer(PhyEepAddr,
                                                                      &Ea_Descriptor.ManagementData[0],
                                                                      EA_HEADER1_SIZE);
        if ( E_OK == ErrorStatus )
        {
			Ea_JobEndNote_Flg=1;
            Ea_Descriptor.JobState     = EA_STATE_WRITE_HEADER1_CBK_WAIT;
            Ea_Descriptor.ProcessState = FALSE;
        }
        else
        {
            Ea_Descriptor.JobResult    = MEMIF_JOB_FAILED;
            Ea_Descriptor.JobState     = EA_STATE_WRITE_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }
    else
    {
       /* TODO: Issue Det error */
    }
}
/**************************************************************************
Function name       : static void Ea_WriteHeader1CbkWait(void)
Description         : Service to write Header call back wait
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_WriteHeader1CbkWait(void)
{
    boolean CbkStatus;
    EA_ENTER_CRITICAL_SECTION();
    CbkStatus = Ea_Descriptor.CbkServiced;  
    EA_EXIT_CRITICAL_SECTION();    
    
    if(FALSE != CbkStatus)
    {
        EA_ENTER_CRITICAL_SECTION();
        Ea_Descriptor.CbkServiced = FALSE;  
        EA_EXIT_CRITICAL_SECTION();    
        
        if(Ea_Descriptor.Eep_JobResult == MEMIF_JOB_OK)
        {
             if((Ea_Config[Ea_Descriptor.BlockIndex].BlockFlags & EA_VERIFICATION_ENABLED) == EA_VERIFICATION_ENABLED)
             {
                 Ea_Descriptor.JobState  = EA_STATE_VERIFY_HEADER1;
                 Ea_Descriptor.ProcessState = TRUE;
             }
             else
             {
                 Ea_Descriptor.JobState  = EA_STATE_WRITE_PAYLOAD;
                 Ea_Descriptor.ProcessState = TRUE;
             }
        }
        else
        {
            Ea_Descriptor.JobResult = Ea_Descriptor.Eep_JobResult;
            Ea_Descriptor.JobState  = EA_STATE_WRITE_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }

}

/**************************************************************************
Function name       : static void Ea_VerifyHeader1(void)
Description         : Service to verify header
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_VerifyHeader1(void)
{
    uint16 PhyEepAddr;
    uint8 DeviceIndex;
    Std_ReturnType ErrorStatus;
    
    PhyEepAddr  = ( Ea_Config[Ea_Descriptor.BlockIndex].BlockBaseAddress + \
                           ((Ea_Config[Ea_Descriptor.BlockIndex].BlockSize + EA_BLOCK_OVERHEAD)* \
                             Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceIndex)) ;
    DeviceIndex = Ea_Config[Ea_Descriptor.BlockIndex].DeviceIndex;

    if ( NULL != Ea_DeviceFunctionPointer[DeviceIndex].CompareEepPointer )
    {
        ErrorStatus = Ea_DeviceFunctionPointer[DeviceIndex].CompareEepPointer(PhyEepAddr,
                                                                        &Ea_Descriptor.ManagementData[0],
                                                                        EA_HEADER1_SIZE);
        if ( E_OK == ErrorStatus )
        {
			Ea_JobEndNote_Flg=1;
            Ea_Descriptor.JobState     = EA_STATE_VERIFY_HEADER1_CBK_WAIT;
            Ea_Descriptor.ProcessState = FALSE;
        }
        else
        {
            Ea_Descriptor.JobResult    = MEMIF_JOB_FAILED;
            Ea_Descriptor.JobState     = EA_STATE_WRITE_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }
    else
    {
       /* TODO: Issue Det error */
    }
}

/**************************************************************************
Function name       : static void Ea_VerifyHeader1CbkWait(void)
Description         : Service to wait for verify header call back
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_VerifyHeader1CbkWait(void)
{
    boolean CbkStatus;
    EA_ENTER_CRITICAL_SECTION();
    CbkStatus = Ea_Descriptor.CbkServiced;  
    EA_EXIT_CRITICAL_SECTION();    
    
    if(FALSE != CbkStatus)
    {
        EA_ENTER_CRITICAL_SECTION();
        Ea_Descriptor.CbkServiced = FALSE;  
        EA_EXIT_CRITICAL_SECTION();    
        
        if(Ea_Descriptor.Eep_JobResult == MEMIF_JOB_OK)
        {
             Ea_Descriptor.JobState  = EA_STATE_WRITE_PAYLOAD;
             Ea_Descriptor.ProcessState = TRUE;
        }
        else
        {
            Ea_Descriptor.JobResult = Ea_Descriptor.Eep_JobResult;
            Ea_Descriptor.JobState  = EA_STATE_WRITE_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }

}

/**************************************************************************
Function name       : static void Ea_WritePayload(void)
Description         : Service to write data in EEPROM
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_WritePayload(void)
{
    uint16 PhyEepAddr;
    uint8 DeviceIndex;
    Std_ReturnType ErrorStatus = E_NOT_OK;
    
    /* Pay Load Physical Address = Block Base Addr +  ((block size + Overhead) * instance Number) + OverHead */
    PhyEepAddr = ( Ea_Config[Ea_Descriptor.BlockIndex].BlockBaseAddress + \
                          ((Ea_Config[Ea_Descriptor.BlockIndex].BlockSize + EA_BLOCK_OVERHEAD)* Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceIndex) + \
                          EA_BLOCK_OVERHEAD) ;
    DeviceIndex = Ea_Config[Ea_Descriptor.BlockIndex].DeviceIndex;

    if ( NULL != Ea_DeviceFunctionPointer[DeviceIndex].WriteEepPointer )
    {
        ErrorStatus = Ea_DeviceFunctionPointer[DeviceIndex].WriteEepPointer(PhyEepAddr,
                                                                      Ea_Descriptor.ClientAddress,
                                                                      Ea_Config[Ea_Descriptor.BlockIndex].BlockSize);
        if ( E_OK == ErrorStatus )
        {
			Ea_JobEndNote_Flg=1;
            Ea_Descriptor.JobState     = EA_STATE_WRITE_PAYLOAD_CBK_WAIT;
            Ea_Descriptor.ProcessState = FALSE;
        }
        else
        {
            Ea_Descriptor.JobResult    = MEMIF_JOB_FAILED;
            Ea_Descriptor.JobState     = EA_STATE_WRITE_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }
    else
    {
       /* TODO: Issue Det error */
    }
}
/**************************************************************************
Function name       : static void Ea_WritePayloadCbkWait(void)
Description         : Service to write data call back wait
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_WritePayloadCbkWait(void)
{
    boolean CbkStatus;
    EA_ENTER_CRITICAL_SECTION();
    CbkStatus = Ea_Descriptor.CbkServiced;  
    EA_EXIT_CRITICAL_SECTION();    
    
    if(FALSE != CbkStatus)
    {
        EA_ENTER_CRITICAL_SECTION();
        Ea_Descriptor.CbkServiced = FALSE;  
        EA_EXIT_CRITICAL_SECTION();    
        
        if(Ea_Descriptor.Eep_JobResult == MEMIF_JOB_OK)
        {
             if((Ea_Config[Ea_Descriptor.BlockIndex].BlockFlags & EA_VERIFICATION_ENABLED) == EA_VERIFICATION_ENABLED)
             {
                 Ea_Descriptor.JobState  = EA_STATE_VERIFY_PAYLOAD;
                 Ea_Descriptor.ProcessState = TRUE;
             }
             else
             {
                 Ea_Descriptor.JobState  = EA_STATE_WRITE_HEADER2;
                 Ea_Descriptor.ProcessState = TRUE;
             }
             
        }
        else
        {
            Ea_Descriptor.JobResult = Ea_Descriptor.Eep_JobResult;
            Ea_Descriptor.JobState  = EA_STATE_WRITE_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }
    
}

/**************************************************************************
Function name       : static void Ea_VerifyPayload(void)
Description         : Service to verify payload
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_VerifyPayload(void)
{
    uint16 PhyEepAddr;
    uint8 DeviceIndex;
    Std_ReturnType ErrorStatus;
    
    /* Pay Load Physical Address = Block Base Addr +  ((block size + Overhead) * instance Number) + OverHead */
    
    PhyEepAddr      = ( Ea_Config[Ea_Descriptor.BlockIndex].BlockBaseAddress + \
                               ((Ea_Config[Ea_Descriptor.BlockIndex].BlockSize + EA_BLOCK_OVERHEAD)* \
                                  Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceIndex) + \
                               EA_BLOCK_OVERHEAD) ;
    DeviceIndex = Ea_Config[Ea_Descriptor.BlockIndex].DeviceIndex;

    if ( NULL != Ea_DeviceFunctionPointer[DeviceIndex].CompareEepPointer )
    {
        ErrorStatus = Ea_DeviceFunctionPointer[DeviceIndex].CompareEepPointer(PhyEepAddr,
                                                                        Ea_Descriptor.ClientAddress,
                                                                        Ea_Config[Ea_Descriptor.BlockIndex].BlockSize);
        if ( E_OK == ErrorStatus )
        {
			Ea_JobEndNote_Flg=1;
            Ea_Descriptor.JobState     = EA_STATE_VERIFY_PAYLOAD_CBK_WAIT;
            Ea_Descriptor.ProcessState = FALSE;
        }
        else
        {
            Ea_Descriptor.JobResult    = MEMIF_JOB_FAILED;
            Ea_Descriptor.JobState     = EA_STATE_WRITE_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }
    else
    {
       /* TODO: Issue Det error */
    }
}

/**************************************************************************
Function name       : static void Ea_VerifyPayloadCbkWait(void)
Description         : Service to verify header
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_VerifyPayloadCbkWait(void)
{
    boolean CbkStatus;
    EA_ENTER_CRITICAL_SECTION();
    CbkStatus = Ea_Descriptor.CbkServiced;  
    EA_EXIT_CRITICAL_SECTION();    
    
    if(FALSE != CbkStatus)
    {
        EA_ENTER_CRITICAL_SECTION();
        Ea_Descriptor.CbkServiced = FALSE;
        EA_EXIT_CRITICAL_SECTION();    
        
        
        if(Ea_Descriptor.Eep_JobResult == MEMIF_JOB_OK)
        {
             Ea_Descriptor.JobState  = EA_STATE_WRITE_HEADER2;
             Ea_Descriptor.ProcessState = TRUE;
        }
        else
        {
            Ea_Descriptor.JobResult = Ea_Descriptor.Eep_JobResult;
            Ea_Descriptor.JobState  = EA_STATE_WRITE_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }

}


/**************************************************************************
Function name       : static void Ea_WriteHeader2(void)
Description         : Service to write footer
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_WriteHeader2(void)
{
    uint16 PhyEepAddr;
    uint8 DeviceIndex;
    Std_ReturnType ErrorStatus;

    /* Header 2 Physical Address = Block Base Addr +  ((block size + Overhead) * instance Number) + Header1 Size */
    
    PhyEepAddr = ( Ea_Config[Ea_Descriptor.BlockIndex].BlockBaseAddress + \
                          ((Ea_Config[Ea_Descriptor.BlockIndex].BlockSize + EA_BLOCK_OVERHEAD)* \
                            Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceIndex) + \
                           EA_HEADER1_SIZE );
	Ea_Descriptor.ManagementData[1] = (uint8)(~Ea_Descriptor.ManagementData[0]);

    DeviceIndex = Ea_Config[Ea_Descriptor.BlockIndex].DeviceIndex;
    
    if( NULL != Ea_DeviceFunctionPointer[DeviceIndex].WriteEepPointer )
    {
        ErrorStatus = Ea_DeviceFunctionPointer[DeviceIndex].WriteEepPointer(PhyEepAddr,
                                                                      &Ea_Descriptor.ManagementData[1],
                                                                      EA_HEADER2_SIZE);
        if ( E_OK == ErrorStatus )
        {
			Ea_JobEndNote_Flg=1;
            Ea_Descriptor.JobState     = EA_STATE_WRITE_HEADER2_CBK_WAIT;
            Ea_Descriptor.ProcessState = FALSE;
        }
        else
        {
            Ea_Descriptor.JobResult    = MEMIF_JOB_FAILED;
            Ea_Descriptor.JobState     = EA_STATE_WRITE_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }
    else
    {
       /* TODO: Issue Det error */
    }
}

/**************************************************************************
Function name       : static void Ea_WriteHeader2CbkWait(void)
Description         : Service to write footer
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_WriteHeader2CbkWait(void)
{
    boolean CbkStatus;
    EA_ENTER_CRITICAL_SECTION();
    CbkStatus = Ea_Descriptor.CbkServiced;  
    EA_EXIT_CRITICAL_SECTION();    
    
    if(FALSE != CbkStatus)
    {
        EA_ENTER_CRITICAL_SECTION();
        Ea_Descriptor.CbkServiced = FALSE;
        EA_EXIT_CRITICAL_SECTION();    
        
        if(Ea_Descriptor.Eep_JobResult == MEMIF_JOB_OK)
        {
             if((Ea_Config[Ea_Descriptor.BlockIndex].BlockFlags & EA_VERIFICATION_ENABLED) == EA_VERIFICATION_ENABLED)
             {
                 Ea_Descriptor.JobState  = EA_STATE_VERIFY_HEADER2;
                 Ea_Descriptor.ProcessState = TRUE;
             }
             else
             {
                 Ea_Descriptor.JobState  = EA_STATE_WRITE_END_NOTIFY;
                 Ea_Descriptor.ProcessState = TRUE;
             }
        }
        else
        {
            Ea_Descriptor.JobResult = Ea_Descriptor.Eep_JobResult;
            Ea_Descriptor.JobState  = EA_STATE_WRITE_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }
}

/**************************************************************************
Function name       : static void Ea_VerifyHeader2(void)
Description         : Service to verify footer with EEPROM Data
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_VerifyHeader2(void)
{
    uint16 PhyEepAddr;
    uint8 DeviceIndex;
    Std_ReturnType ErrorStatus = E_NOT_OK;
    
    /* Header 2 Physical Address = Block Base Addr +  ((block size + Overhead) * instance Number) + Header1 Size */
    
    PhyEepAddr = ( Ea_Config[Ea_Descriptor.BlockIndex].BlockBaseAddress + \
                          ((Ea_Config[Ea_Descriptor.BlockIndex].BlockSize + EA_BLOCK_OVERHEAD)* \
                            Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceIndex) + \
                            EA_HEADER1_SIZE) ;
    DeviceIndex = Ea_Config[Ea_Descriptor.BlockIndex].DeviceIndex;
                                
    if ( NULL != Ea_DeviceFunctionPointer[DeviceIndex].CompareEepPointer )
    {
        ErrorStatus = Ea_DeviceFunctionPointer[DeviceIndex].CompareEepPointer(PhyEepAddr,
                                                                        &Ea_Descriptor.ManagementData[1],
                                                                        EA_HEADER2_SIZE);
        if ( E_OK == ErrorStatus )
        {
			Ea_JobEndNote_Flg=1;
            Ea_Descriptor.JobState     = EA_STATE_VERIFY_HEADER2_CBK_WAIT;
            Ea_Descriptor.ProcessState = FALSE;
        }
        else
        {
            Ea_Descriptor.JobResult    = MEMIF_JOB_FAILED;
            Ea_Descriptor.JobState     = EA_STATE_WRITE_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }
    else
    {
       /* TODO: Issue Det error */
    }
}

/**************************************************************************
Function name       : static void Ea_VerifyHeader2CbkWait(void)
Description         : Service to wait for verify footer call back wait
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_VerifyHeader2CbkWait(void)
{
    boolean CbkStatus;
    EA_ENTER_CRITICAL_SECTION();
    CbkStatus = Ea_Descriptor.CbkServiced;  
    EA_EXIT_CRITICAL_SECTION();    
    
    if(FALSE != CbkStatus)
    {
        EA_ENTER_CRITICAL_SECTION();
        Ea_Descriptor.CbkServiced = FALSE;
        EA_EXIT_CRITICAL_SECTION();    
        
        if(Ea_Descriptor.Eep_JobResult == MEMIF_JOB_OK)
        {
             Ea_Descriptor.JobState  = EA_STATE_WRITE_END_NOTIFY;
             Ea_Descriptor.ProcessState = TRUE;
        }
        else
        {
            Ea_Descriptor.JobResult = Ea_Descriptor.Eep_JobResult;
            Ea_Descriptor.JobState  = EA_STATE_WRITE_ERROR_NOTIFY;
            Ea_Descriptor.ProcessState = TRUE;
        }
    }
}

/**************************************************************************
Function name       : static void Ea_WriteEndNotify(void)
Description         : Service to provide end notification to upper layer
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_WriteEndNotify(void)
{

    Ea_Descriptor.JobResult = MEMIF_JOB_OK;
    Ea_Descriptor.JobState  = EA_STATE_IDLE;
    Ea_Descriptor.ProcessState = FALSE;
    Ea_Descriptor.JobActiveId = EA_JOB_IDLE;
    Ea_CbkJobEndNotification();
}

/**************************************************************************
Function name       : static void Ea_WriteErrorNotify(void)
Description         : Service to provide error notification to upper layer
Parameters (in)     : None
Parameters (out)    : None
Return value        : None
Design Information  : 
**************************************************************************/
static void Ea_WriteErrorNotify(void)
{
    Ea_Descriptor.JobActiveId = EA_JOB_IDLE;
    Ea_Descriptor.JobState  = EA_STATE_IDLE;
    Ea_Descriptor.ProcessState = FALSE;
    if(Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceIndex == 0U)
    {
        Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceIndex = Ea_Config[Ea_Descriptor.BlockIndex].NoOfInstances - 1;
    }
	else
	{
		Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceIndex--;
	}
	if(Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceCounter == 0U)
	{
		Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceCounter = EA_MAX_INSTANCE_COUNTER;
	}
	else
	{
		Ea_BlockInformation[Ea_Descriptor.BlockIndex].CurrentInstanceCounter --;
	}
   Ea_CbkJobErrorNotification();
}

#define EA_DATA_SEC_END
#include "MemMap.h"

#define EA_CODE_SEC_END
#include "MemMap.h"


#endif /* EA_C */
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
/*Change Description: Data design And Framework implemented, Initial Version*/
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 22-01-2016                                            */
/*Version           :                                                       */
/*By                : kshaik1                                               */
/*Traceability      : 506324,506325                                         */
/*Change Description: Read, Write Implementation                            */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 04-02-2016                                            */
/*Version           :                                                       */
/*By                : kshaik1                                               */
/*Traceability      : 515730                                                */
/*Change Description: Ea and Eep Integration                               */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 10-02-2016                                            */
/*Version           :                                                       */
/*By                : kshaik1                                               */
/*Traceability      : 516513                                                */
/*Change Description: Updated Search Algorithm                              */
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
/**-------------------------------------------------------------------------*/
/*Date              : 09-07-2020                                            */
/*Version           :                                                       */
/*By                : lthanga1                                              */
/*Traceability      : 878613                                                */
/*Change Description: Support multiple EEPROM                               */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 23-02-2021                                            */
/*Version           :                                                       */
/*By                : praj1                                                 */
/*Traceability      :   1222451                                             */
/*Change Description: job end and err notification protected from SNvM      */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 28-03-2022                                            */
/*Version           :                                                       */
/*By                : gthanapp                                              */
/*Traceability      : RTC#1564070                                           */
/*Change Description: Cert-C warning analysis and fix                       */
/*--------------------------------------------------------------------------*/


