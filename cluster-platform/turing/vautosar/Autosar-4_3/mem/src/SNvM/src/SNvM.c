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
*  File Name         :  SNvM.c                                                 *
*  Module Short Name :  SNvM                                                   *
*  VOBName           :                                                       *
*  Author            : praj1                                                 *
*  Description       : Request handling of SNvM data module                    *
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
#ifndef SNVM_C
#define SNVM_C
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "SNvM.h"
#include "Os.h"
#define SNVM_CODE_SEC_START
#include "MemMap.h"

#define SNVM_DATA_SEC_START
#include "MemMap.h"
#include "Std_Types.h"
#include "MemIf_Types.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

typedef enum
{
  SNvM_IDLE_State  = 0,
  SNvM_Sec_Read_Data_State,
  SNvM_Sec_Read_Data_Wait_State,
  SNvM_Erase_State,
  SNvM_Erase_Wait_State,
  SNvM_WRITE_Data_bkup1_State,
  SNvM_WRITE_Data_bkup1_Wait_State,
  SNvM_WRITE_Data_bkup2_State,
  SNvM_WRITE_Data_bkup2_Wait_State,
  SNvM_WRITE_Header1_State,
  SNvM_WRITE_Header1_Wait_State,
  SNvM_WRITE_Data_State,
  SNvM_WRITE_Data_Wait_State,
  SNvM_WRITE_Header2_State,
  SNvM_WRITE_Header2_Wait_State,
  SNvM_READ_Header_State,
  SNvM_READ_Header_Wait_State,
  SNvM_READ_data_State,
  SNvM_READ_data_Wait_State
}SNvM_States;


typedef struct  
{
  uint8* Data_Buff;
  uint16 SNvM_Offset;
  uint16 SNvM_Id;
  uint16 SNvM_Length;
}SNvM_datatype;

typedef struct
{
    uint32 StartTimeStamp;
    uint32 ElapsedTimeStamp;
    uint8 TimerIsRunning;
    uint8 TimerIsExpired;
    uint8 ReadRetryCount;
    uint8 EraseRetryCount;
    uint8 SectorSwitchRetryCount;
    uint8 BlankCheckRetryCount;
}SNvM_RetryManagementDataType;
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
static SNvM_datatype SNvM_data_value;
static SNvM_States SNvM_Process_State;
static uint8 SNvM_HeadBuff[Page_SIZE];
static uint8 SNvM_Read_HeadBuff[Page_SIZE*2U];
static uint8 SNvM_Backup_Buff[MAX_DATA_LENGTH];
static uint16 Head_Count;
static MemIf_JobResultType SNvM_JobResult;
static MemIf_StatusType SNvM_Status;
static SNvM_RetryManagementDataType SNvM_RetryManagementData;
/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/
static void SNvM_Sec_Read_Data(void);
static void SNvM_Sec_Read_Data_Wait(void);
static void SNvM_Erase(void);
static void SNvM_Erase_Wait(void);
static void SNvM_Write_bkup1_Data(void);
static void SNvM_Write_bkup1_Data_Wait(void);
static void SNvM_Write_bkup2_Data(void);
static void SNvM_Write_bkup2_Data_Wait(void);
static void SNvM_Write_Header1(void);
static void SNvM_Write_Header1_Wait(void);
static void SNvM_Write_Data(void);
static void SNvM_Write_Data_Wait(void);
static void SNvM_Write_Header2(void);
static void SNvM_Write_Header2_Wait(void);
static void SNvM_Read_Header(void);
static void SNvM_Read_Header_Wait(void);
static void SNvM_Read_Data(void);
static void SNvM_Read_Data_Wait(void);


/*****************************************************************************
*                   Functions                                                *
******************************************************************************/


void SNvM_Init(void)
{
  SNvM_data_value.SNvM_Id = (uint16) 0U;
  SNvM_data_value.Data_Buff =NULL;
  SNvM_data_value.SNvM_Offset = (uint16) 0U;
  SNvM_data_value.SNvM_Length = (uint16) 0U;
  
  SNvM_Process_State = SNvM_IDLE_State;
  SNvM_Status = MEMIF_IDLE;
}


/**************************************************************************
Function name   : Std_ReturnType SNvM_Write(uint16 SNvM_ID, const uint8* DataBufferPtr)
Arguments       : uint16 SNvM_ID, const uint8* DataBufferPtr
Return type     : Std_ReturnType
Description     : Write data in SNvM module.
**************************************************************************/

Std_ReturnType SNvM_Write(uint16 SNvM_ID, const uint8* DataBufferPtr)
{
	Std_ReturnType fl_RetVal = E_NOT_OK;
	SNvM_data_value.SNvM_Id = (uint16) SNvM_ID;
	SNvM_data_value.Data_Buff =(uint8 *)DataBufferPtr;
	SNvM_data_value.SNvM_Length = SNvM_BlockConfig[SNvM_ID].Length;

	if(SNvM_Status == MEMIF_IDLE)
	{
		SNvM_Status = MEMIF_BUSY;
		SNvM_JobResult=MEMIF_JOB_PENDING;
		if ((boolean)SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Fls_EepDrv==(boolean)FLS_drive)
	  	{
#if (SNVM_READ_MODIFY_WRITE == STD_ON)
		    SNvM_Process_State = SNvM_Sec_Read_Data_State;//backup data 
#else
			SNvM_Process_State = SNvM_Erase_State;
#endif
			fl_RetVal = E_OK;  
		}
		else 
		{
			SNvM_Process_State = SNvM_WRITE_Header1_State;
			fl_RetVal = E_OK; 
		}
	}
	else
	{
		fl_RetVal = E_NOT_OK;
	}
	return fl_RetVal;
}

static void SNvM_ResetRetryTimer(void)
{
    SNvM_RetryManagementData.TimerIsRunning = FALSE;
    SNvM_RetryManagementData.TimerIsExpired = FALSE;
}

static void SNvM_RetryTimeoutProcess(void)
{
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 Delay;
    /*
        Start OS based timer, If not already started.
    */
    if(FALSE == SNvM_RetryManagementData.TimerIsRunning)
    {
        /* Timer is not yet started, So Taking TimeStamp of Os Tick*/
        (void)GetCounterValue(SystemTimer,(TickRefType)(&SNvM_RetryManagementData.StartTimeStamp));
        /*Mark as timer running*/
        SNvM_RetryManagementData.TimerIsRunning = TRUE;
    }
    else
    {
        /* Timer is started, So we are checking for timer expiry*/
        (void)GetCounterValue(SystemTimer,(TickRefType)(&SNvM_RetryManagementData.ElapsedTimeStamp));
        StartTime = SNvM_RetryManagementData.StartTimeStamp;
        ElapsedTime = SNvM_RetryManagementData.ElapsedTimeStamp;
        
        if( ElapsedTime < StartTime )
        {
            Delay = (uint32)(0xFFFFFFFFU - StartTime ) + ElapsedTime;
        }
        else
        {
            Delay = (uint32)( ElapsedTime - StartTime );
        }

        if(Delay >= SNVM_RETRY_TIMEOUT_MS)
        {
            SNvM_RetryManagementData.TimerIsExpired = TRUE;
        }

    }
}

/**************************************************************************
Function name   : static void SNvM_Sec_Read_Data(void)
Arguments       : void
Return type     : void
Description     : Read sector for a backup .
**************************************************************************/
static void SNvM_Sec_Read_Data(void)
{
	
	Std_ReturnType fl_RequestStatus;
	uint32 Sec_start_Add=0;
	uint32 Length;
	Sec_start_Add=(uint32)(SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Base_Add);
	Length = (uint32)(SNvM_BlockConfig[SNvM_data_value.SNvM_Id].SectorCnt * (uint32)FLS_Sec_Size);
	 	fl_RequestStatus = SNvM_Fls_Eep_fun[SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Fls_EepDrv].SNvM_Read(Sec_start_Add,(uint8 *)&SNvM_Backup_Buff[0], Length);  
		if(fl_RequestStatus == E_OK)
	 		{
		 		SNvM_Process_State = SNvM_Sec_Read_Data_Wait_State;

	 		}
		else
	 		{
	 		    SNvM_JobResult=MEMIF_JOB_FAILED;
	 			SNVM_NVM_JOB_ERROR_NOTIFICATION();
	 		    SNvM_Process_State = SNvM_IDLE_State;
				SNvM_Status = MEMIF_IDLE;
	 		 }
  
}
/**************************************************************************
Function name   : static void SNvM_Sec_Read_Data_Wait(void)
Arguments       : void
Return type     : void
Description     : wait for Read sector for a backup .
**************************************************************************/
static void SNvM_Sec_Read_Data_Wait(void)
{
  MemIf_JobResultType fl_FlsJobStatus;
  fl_FlsJobStatus = SNvM_Fls_Eep_fun[SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Fls_EepDrv].SNvM_Status();
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
	  {
		if(fl_FlsJobStatus == MEMIF_JOB_OK)
		{
			SNvM_ResetRetryTimer();
            SNvM_RetryManagementData.ReadRetryCount = 0;
			SNvM_Process_State = SNvM_Erase_State;
		}
	    else
	    {
			SNvM_RetryTimeoutProcess();
            if(SNvM_RetryManagementData.ReadRetryCount > SNvM_READ_RETRY_COUNT)
            {
                if(FALSE != SNvM_RetryManagementData.TimerIsExpired)
                {
                    SNvM_ResetRetryTimer();
                    SNvM_RetryManagementData.ReadRetryCount = 0;

					SNvM_JobResult=MEMIF_JOB_FAILED;
					SNVM_NVM_JOB_ERROR_NOTIFICATION();
					SNvM_Process_State = SNvM_IDLE_State;
					SNvM_Status = MEMIF_IDLE;
				}
				else
				{
					SNvM_RetryManagementData.ReadRetryCount = 0;
                    SNvM_Process_State = SNvM_Sec_Read_Data_State;
				}
			}
			else
			{
				SNvM_RetryManagementData.ReadRetryCount += 1U;
                SNvM_Process_State = SNvM_Sec_Read_Data_State;
			}
	    }
	  }

}

/**************************************************************************
Function name   : static void SNvM_Erase(void)
Arguments       : void
Return type     : void
Description     : erase the sector .
**************************************************************************/
static void SNvM_Erase(void)
{
	Std_ReturnType fl_RequestStatus;
	uint32 Sec_start_Add=0;
	uint32 Length;
	Sec_start_Add=(uint32)(SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Base_Add);
	Length = (uint32)(SNvM_BlockConfig[SNvM_data_value.SNvM_Id].SectorCnt*(uint32)FLS_Sec_Size);
 
	  fl_RequestStatus = SNvM_Fls_Eep_fun[SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Fls_EepDrv].SNvM_Sector_Erase(Sec_start_Add, Length);
	  
	  if(fl_RequestStatus == E_OK)
	  {
		    SNvM_Process_State = SNvM_Erase_Wait_State;
	  }
	  else
	  {
		  	SNvM_JobResult=MEMIF_JOB_FAILED;
			SNVM_NVM_JOB_ERROR_NOTIFICATION();
		    SNvM_Process_State = SNvM_IDLE_State;
		    SNvM_Status = MEMIF_IDLE;  
	  }
  
}
/**************************************************************************
Function name   : static void SNvM_Erase_Wait(void)
Arguments       : void
Return type     : void
Description     : wait for sector  erase.
**************************************************************************/
static void SNvM_Erase_Wait(void)
{

  MemIf_JobResultType fl_FlsJobStatus;
  fl_FlsJobStatus = SNvM_Fls_Eep_fun[SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Fls_EepDrv].SNvM_Status();
		
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
	  {
		if(fl_FlsJobStatus == MEMIF_JOB_OK)
		{
#if (SNVM_READ_MODIFY_WRITE == STD_ON)
		    SNvM_Process_State = SNvM_WRITE_Data_bkup1_State;
#else
			SNvM_Process_State = SNvM_WRITE_Header1_State;
#endif
		}
	    else
	    {
	    	SNvM_JobResult=MEMIF_JOB_FAILED;
	    	SNVM_NVM_JOB_ERROR_NOTIFICATION();
	        SNvM_Process_State = SNvM_IDLE_State;
			SNvM_Status = MEMIF_IDLE;
	    }
	  }

}
/**************************************************************************
Function name   : static void SNvM_Write_bkup1_Data(void)
Arguments       : void
Return type     : void
Description     : write sector data backup1
**************************************************************************/
static void SNvM_Write_bkup1_Data(void)
{
	
	Std_ReturnType fl_RequestStatus;
	uint32 Sec_start_Add=0;
	Sec_start_Add=(uint32)(SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Base_Add);

	if(SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Sector_Offset!=0U)
	{

	 	fl_RequestStatus = SNvM_Fls_Eep_fun[SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Fls_EepDrv].SNvM_Write(Sec_start_Add,(const uint8 *)&SNvM_Backup_Buff[0], SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Sector_Offset);
		if(fl_RequestStatus == E_OK)
	 		{
		 		SNvM_Process_State = SNvM_WRITE_Data_bkup1_Wait_State;

	 		}
		else
	 		{
	 		    SNvM_JobResult=MEMIF_JOB_FAILED;
	 			SNVM_NVM_JOB_ERROR_NOTIFICATION();
	 		    SNvM_Process_State = SNvM_IDLE_State;
				SNvM_Status = MEMIF_IDLE;
	 		 }

	}
	else
	{
		 SNvM_Process_State = SNvM_WRITE_Data_bkup2_State;
	}

 
}
/**************************************************************************
Function name   : static void SNvM_Write_bkup1_Data_Wait(void)
Arguments       : void
Return type     : void
Description     : wait for write sector data backup1
**************************************************************************/
static void SNvM_Write_bkup1_Data_Wait(void)
{

  MemIf_JobResultType fl_FlsJobStatus;
  fl_FlsJobStatus = SNvM_Fls_Eep_fun[SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Fls_EepDrv].SNvM_Status();
		
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
	  {
		if(fl_FlsJobStatus == MEMIF_JOB_OK)
		{
			SNvM_Process_State = SNvM_WRITE_Data_bkup2_State;
		}
	    else
	    {
	    	SNvM_JobResult=MEMIF_JOB_FAILED;
	    	SNVM_NVM_JOB_ERROR_NOTIFICATION();
	        SNvM_Process_State = SNvM_IDLE_State;
			SNvM_Status = MEMIF_IDLE;
	    }
	  }

}

/**************************************************************************
Function name   : static void SNvM_Write_bkup2_Data(void)
Arguments       : void
Return type     : void
Description     : write sector data backup2,
					Write Sector backup data after data block
**************************************************************************/
static void SNvM_Write_bkup2_Data(void)
{
	
	Std_ReturnType fl_RequestStatus;
	uint32 Sec_Len=0;
	uint32 Sec_start_Add=0;
	uint32 Bk_st_add=0;
	Bk_st_add=SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Sector_Offset+SNvM_data_value.SNvM_Length+((uint32)Page_SIZE*2U);
	Sec_start_Add=(uint32)(SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Base_Add + Bk_st_add);
	Sec_Len=(SNvM_BlockConfig[SNvM_data_value.SNvM_Id].SectorCnt * FLS_Sec_Size)-Bk_st_add;
	if (Sec_Len!=0U)
	{
		fl_RequestStatus = SNvM_Fls_Eep_fun[SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Fls_EepDrv].SNvM_Write(Sec_start_Add,(const uint8 *)&SNvM_Backup_Buff[Bk_st_add], Sec_Len);
				if(fl_RequestStatus == E_OK)
			 		{
				 		SNvM_Process_State = SNvM_WRITE_Data_bkup2_Wait_State;

			 		}
				else
			 		{
			 		    SNvM_JobResult=MEMIF_JOB_FAILED;
			 			SNVM_NVM_JOB_ERROR_NOTIFICATION();
			 		    SNvM_Process_State = SNvM_IDLE_State;
						SNvM_Status = MEMIF_IDLE;
			 		 }

	}
	else
	{
		SNvM_Process_State = SNvM_WRITE_Header1_State;
	}

}
/**************************************************************************
Function name   : static void SNvM_Write_bkup2_Data_Wait(void)
Arguments       : void
Return type     : void
Description     : wait for write sector data backup2,
					Write Sector backup data after data block
**************************************************************************/
static void SNvM_Write_bkup2_Data_Wait(void)
{

  MemIf_JobResultType fl_FlsJobStatus;
  fl_FlsJobStatus = SNvM_Fls_Eep_fun[SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Fls_EepDrv].SNvM_Status();
		
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
	  {
		if(fl_FlsJobStatus == MEMIF_JOB_OK)
		{
			SNvM_Process_State = SNvM_WRITE_Header1_State;
		}
	    else
	    {
	    	SNvM_JobResult=MEMIF_JOB_FAILED;
	    	SNVM_NVM_JOB_ERROR_NOTIFICATION();
	        SNvM_Process_State = SNvM_IDLE_State;
			SNvM_Status = MEMIF_IDLE;
	    }
	  }

}


/**************************************************************************
Function name   : static void SNvM_Write_Header1(void)
Arguments       : void
Return type     : void
Description     : write header 1 for data
**************************************************************************/
static void SNvM_Write_Header1(void)
{
	Std_ReturnType fl_RequestStatus;
	uint32 Sec_start_Add=0;

	Sec_start_Add=(uint32)(SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Base_Add + SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Sector_Offset);

	 SNvM_HeadBuff[0]=(uint8)((uint16)0x00ff & (uint16)SNvM_data_value.SNvM_Id);
	SNvM_HeadBuff[1]=(uint8)(((uint16)0xff00 & (uint16)SNvM_data_value.SNvM_Id)>>8U);
	SNvM_HeadBuff[2]=(uint8)((uint16)0x00ff & (uint16)Head_Count);
	SNvM_HeadBuff[3]=(uint8)(((uint16)0xff00 & (uint16)Head_Count)>>8U);
	
 	fl_RequestStatus = SNvM_Fls_Eep_fun[SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Fls_EepDrv].SNvM_Write(Sec_start_Add,(const uint8 *)&SNvM_HeadBuff[0], Page_SIZE);
	
    if(fl_RequestStatus == E_OK)
    {
		Head_Count++;
        SNvM_Process_State = SNvM_WRITE_Header1_Wait_State;
    }
    else
    {
    	SNvM_JobResult=MEMIF_JOB_FAILED;
    	SNVM_NVM_JOB_ERROR_NOTIFICATION();
        SNvM_Process_State = SNvM_IDLE_State;
		SNvM_Status = MEMIF_IDLE;
    }
  
}

/**************************************************************************
Function name   : static void SNvM_Write_Header1_Wait(void)
Arguments       : void
Return type     : void
Description     : wait for  write header 1 for data
**************************************************************************/
static void SNvM_Write_Header1_Wait(void)
{

  MemIf_JobResultType fl_FlsJobStatus;
  fl_FlsJobStatus = SNvM_Fls_Eep_fun[SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Fls_EepDrv].SNvM_Status();
		
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
	  {
		if(fl_FlsJobStatus == MEMIF_JOB_OK)
		{
			SNvM_Process_State = SNvM_WRITE_Data_State;
		}
		else
		{
			SNvM_Process_State = SNvM_IDLE_State;
			SNvM_JobResult=MEMIF_JOB_FAILED;
			SNVM_NVM_JOB_ERROR_NOTIFICATION();
			SNvM_Status = MEMIF_IDLE;
		}

	  }

}

/**************************************************************************
Function name   : static void SNvM_Write_Data(void)
Arguments       : void
Return type     : void
Description     : write data in SNvM
**************************************************************************/
static void SNvM_Write_Data(void)
{
	Std_ReturnType fl_RequestStatus;
	uint32 Sec_start_Add=0;

	Sec_start_Add=(uint32)(SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Base_Add + SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Sector_Offset + ((uint32)Page_SIZE*2U));

	 	fl_RequestStatus = SNvM_Fls_Eep_fun[SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Fls_EepDrv].SNvM_Write(Sec_start_Add,(const uint8 *)&SNvM_data_value.Data_Buff[0], SNvM_data_value.SNvM_Length);  
		if(fl_RequestStatus == E_OK)
	 		{
		 		SNvM_Process_State = SNvM_WRITE_Data_Wait_State;

	 		}
		else
	 		{
	 		    SNvM_JobResult=MEMIF_JOB_FAILED;
	 			SNVM_NVM_JOB_ERROR_NOTIFICATION();
	 		    SNvM_Process_State = SNvM_IDLE_State;
				SNvM_Status = MEMIF_IDLE;
	 		 }
  
}

/**************************************************************************
Function name   : static void SNvM_Write_Data_Wait(void)
Arguments       : void
Return type     : void
Description     : wait for write data in SNvM
**************************************************************************/
static void SNvM_Write_Data_Wait(void)
{

  MemIf_JobResultType fl_FlsJobStatus;
  fl_FlsJobStatus = SNvM_Fls_Eep_fun[SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Fls_EepDrv].SNvM_Status();
		
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
	  {
		if(fl_FlsJobStatus == MEMIF_JOB_OK)
		{
			SNvM_Process_State = SNvM_WRITE_Header2_State;
		}
		else
		{
			SNvM_Process_State = SNvM_IDLE_State;
			SNvM_JobResult=MEMIF_JOB_FAILED;
			SNVM_NVM_JOB_ERROR_NOTIFICATION();
			SNvM_Status = MEMIF_IDLE;
		}

	  }

}

/**************************************************************************
Function name   : static void SNvM_Write_Header2(void)
Arguments       : void
Return type     : void
Description     : write header 1 for data
**************************************************************************/
static void SNvM_Write_Header2(void)
{
	Std_ReturnType fl_RequestStatus;
	uint8 byte_cnt=0;
	uint32 Sec_start_Add=0;

	Sec_start_Add=(uint32)(SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Base_Add + SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Sector_Offset + (uint32)Page_SIZE);
	
	for(byte_cnt=0;byte_cnt<Page_SIZE;byte_cnt++)
	{
		SNvM_HeadBuff[byte_cnt]=(uint8)SNvM_HeadBuff[byte_cnt]^(uint8)0xff;
	}
 	fl_RequestStatus = SNvM_Fls_Eep_fun[SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Fls_EepDrv].SNvM_Write(Sec_start_Add,(const uint8 *)&SNvM_HeadBuff[0], Page_SIZE);
	
    if(fl_RequestStatus == E_OK)
    {
          SNvM_Process_State = SNvM_WRITE_Header2_Wait_State;
    }
    else
    {
    	SNvM_JobResult=MEMIF_JOB_FAILED;
    	SNVM_NVM_JOB_ERROR_NOTIFICATION();
          SNvM_Process_State = SNvM_IDLE_State;
		  SNvM_Status = MEMIF_IDLE;
    }
  
}

/**************************************************************************
Function name   : static void SNvM_Write_Header2_Wait(void)
Arguments       : void
Return type     : void
Description     : wait for  write header 2 for data
**************************************************************************/
static void SNvM_Write_Header2_Wait(void)
{

  MemIf_JobResultType fl_FlsJobStatus;
  fl_FlsJobStatus = SNvM_Fls_Eep_fun[SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Fls_EepDrv].SNvM_Status();
		
  if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
	  {
		SNvM_Status = MEMIF_IDLE;
		if(fl_FlsJobStatus == MEMIF_JOB_OK)
		{
			SNvM_Process_State = SNvM_IDLE_State;
			SNvM_JobResult=MEMIF_JOB_OK;
			SNVM_NVM_JOB_END_NOTIFICATION();
		}
		else
		{
			SNvM_Process_State = SNvM_IDLE_State;
			SNvM_JobResult=MEMIF_JOB_FAILED;
			SNVM_NVM_JOB_ERROR_NOTIFICATION();
		}

	  }

}

/**************************************************************************
Function name   : static void SNvM_Read(void)
Arguments       : uint16 SNvM_ID, uint16 BlockOffset, uint8* DataBufferPtr, uint16 Length
Return type     : Std_ReturnType
Description     : Read data in SNvM module
**************************************************************************/
Std_ReturnType SNvM_Read(uint16 SNvM_ID, uint16 BlockOffset, uint8* DataBufferPtr, uint16 Length)
{
  Std_ReturnType fl_RetVal;
  SNvM_data_value.SNvM_Id = (uint16) SNvM_ID;
  SNvM_data_value.Data_Buff =(uint8 *)DataBufferPtr;
  SNvM_data_value.SNvM_Offset = (uint16) BlockOffset;
  SNvM_data_value.SNvM_Length = SNvM_BlockConfig[SNvM_ID].Length;
  
  (void)Length;
  if(SNvM_Status == MEMIF_IDLE)
  {
	SNvM_Status = MEMIF_BUSY;
	SNvM_JobResult=MEMIF_JOB_PENDING;
    SNvM_Process_State = SNvM_READ_Header_State;
    fl_RetVal = E_OK;
  }
  else
  {
    fl_RetVal = E_NOT_OK;
  }
  return fl_RetVal;
}


/**************************************************************************
Function name   : static void SNvM_Read_Header(void)
Arguments       : void
Return type     : void
Description     : Read header in SNvM module
**************************************************************************/
static void SNvM_Read_Header(void)
{
	Std_ReturnType fl_RequestStatus;
	uint32 Sec_start_Add=0;

	Sec_start_Add = (uint32)(SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Base_Add + SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Sector_Offset);
	  
	fl_RequestStatus = SNvM_Fls_Eep_fun[SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Fls_EepDrv].SNvM_Read(Sec_start_Add,(uint8 *)&SNvM_Read_HeadBuff[0], (uint32)(Page_SIZE*2U));
    if(fl_RequestStatus == E_OK)
    {
      SNvM_Process_State = SNvM_READ_Header_Wait_State;
    }
	else
	{

		SNvM_Process_State = SNvM_IDLE_State;
		SNvM_JobResult=MEMIF_JOB_FAILED;
		SNVM_NVM_JOB_ERROR_NOTIFICATION();
		SNvM_Status = MEMIF_IDLE;
	}
  
}
/**************************************************************************
Function name   : static void SNvM_Read_Header_Wait(void)
Arguments       : void
Return type     : void
Description     : wait for Read header in SNvM module
**************************************************************************/
static void SNvM_Read_Header_Wait(void)
{
	MemIf_JobResultType fl_FlsJobStatus;
	uint8 byte_cnt;
	boolean Cmp_result=TRUE;

	fl_FlsJobStatus = SNvM_Fls_Eep_fun[SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Fls_EepDrv].SNvM_Status();
		
	if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
	{
		if(fl_FlsJobStatus == MEMIF_JOB_OK)
		{
			SNvM_ResetRetryTimer();
			SNvM_RetryManagementData.ReadRetryCount = 0;

			for(byte_cnt=0;byte_cnt<Page_SIZE;byte_cnt++)
			{

				if(SNvM_Read_HeadBuff[byte_cnt]!=(SNvM_Read_HeadBuff[byte_cnt+Page_SIZE]^0xffU))
				{
					Cmp_result=FALSE;
				}
			}
			if(Cmp_result==TRUE)
			{
				SNvM_Process_State = SNvM_READ_data_State;

			}
			else
			{
				SNvM_Process_State = SNvM_IDLE_State;
				SNvM_JobResult=MEMIF_BLOCK_INCONSISTENT;
				SNVM_NVM_JOB_ERROR_NOTIFICATION();
				SNvM_Status = MEMIF_IDLE;
			}

		}
		else
		{
			SNvM_RetryTimeoutProcess();
			if(SNvM_RetryManagementData.ReadRetryCount > SNvM_READ_RETRY_COUNT)
			{
				if(FALSE != SNvM_RetryManagementData.TimerIsExpired)
				{
					SNvM_ResetRetryTimer();

					SNvM_Process_State = SNvM_IDLE_State;
					SNvM_JobResult=MEMIF_JOB_FAILED;
					SNVM_NVM_JOB_ERROR_NOTIFICATION();
					SNvM_Status = MEMIF_IDLE;
				}
				else
				{
					SNvM_RetryManagementData.ReadRetryCount = 0U;
					SNvM_Process_State = SNvM_READ_Header_State;
				}
			}
			else
			{
				SNvM_RetryManagementData.ReadRetryCount += 1U;
				SNvM_Process_State = SNvM_READ_Header_State;
			}
		}
	}
}

/**************************************************************************
Function name   : static void SNvM_Read_Data(void)
Arguments       : void
Return type     : void
Description     : Read data in SNvM module
**************************************************************************/
static void SNvM_Read_Data(void)
{	
	Std_ReturnType fl_RequestStatus;
	uint32 Sec_start_Add=0U;
	
	Sec_start_Add=(uint32)(SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Base_Add + SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Sector_Offset+(Page_SIZE*2U));
    
    fl_RequestStatus = SNvM_Fls_Eep_fun[SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Fls_EepDrv].SNvM_Read(Sec_start_Add,(uint8 *)&SNvM_data_value.Data_Buff[0], SNvM_data_value.SNvM_Length);

	if(fl_RequestStatus == E_OK)
	{
		SNvM_Process_State = SNvM_READ_data_Wait_State;

	}
	else
	{
		SNvM_JobResult=MEMIF_JOB_FAILED;
		SNVM_NVM_JOB_ERROR_NOTIFICATION();
		SNvM_Process_State = SNvM_IDLE_State;
		SNvM_Status = MEMIF_IDLE;
	}

  
}
/**************************************************************************
Function name   : static void SNvM_Read_Data_Wait(void)
Arguments       : void
Return type     : void
Description     : wait for Read data in SNvM module
**************************************************************************/
static void SNvM_Read_Data_Wait(void)
{

	MemIf_JobResultType fl_FlsJobStatus;
	fl_FlsJobStatus = SNvM_Fls_Eep_fun[SNvM_BlockConfig[SNvM_data_value.SNvM_Id].Fls_EepDrv].SNvM_Status();
	if(fl_FlsJobStatus != MEMIF_JOB_PENDING)
	{
		if(fl_FlsJobStatus == MEMIF_JOB_OK)
		{
			SNvM_ResetRetryTimer();
            SNvM_RetryManagementData.ReadRetryCount = 0;
			SNvM_Process_State = SNvM_IDLE_State;
			SNvM_JobResult=MEMIF_JOB_OK;
			SNVM_NVM_JOB_END_NOTIFICATION();
			SNvM_Status = MEMIF_IDLE;
		}
		else
		{
			SNvM_RetryTimeoutProcess();
            if(SNvM_RetryManagementData.ReadRetryCount > SNvM_READ_RETRY_COUNT)
            {
                if(FALSE != SNvM_RetryManagementData.TimerIsExpired)
                {
                    SNvM_ResetRetryTimer();
                    SNvM_RetryManagementData.ReadRetryCount = 0;
					SNvM_Process_State = SNvM_IDLE_State;
					SNvM_JobResult=MEMIF_JOB_FAILED;
					SNVM_NVM_JOB_ERROR_NOTIFICATION();
					SNvM_Status = MEMIF_IDLE;
				}
				else
				{
					SNvM_RetryManagementData.ReadRetryCount = 0;
                    SNvM_Process_State = SNvM_READ_data_State;
				}
			}
			else
			{
				SNvM_RetryManagementData.ReadRetryCount += 1U;
                SNvM_Process_State = SNvM_READ_data_State;
			}
		}
	}
}

/**************************************************************************
Function name   : static void SNvM_MainFunction(void)
Arguments       : void
Return type     : void
Description     : main fuction to handle SNvM states
**************************************************************************/
void SNvM_MainFunction(void)
{

switch(SNvM_Process_State)
    {
      case SNvM_IDLE_State:
      break;
	  
      case SNvM_Sec_Read_Data_State:
		   SNvM_Sec_Read_Data();
      break;
	  
      case SNvM_Sec_Read_Data_Wait_State:
		   SNvM_Sec_Read_Data_Wait();
      break;	  

      case SNvM_Erase_State:
		   SNvM_Erase();
      break;
      
      case SNvM_Erase_Wait_State:
		   SNvM_Erase_Wait();
      break;
	  
      case SNvM_WRITE_Data_bkup1_State:
		   SNvM_Write_bkup1_Data();
      break;	  
	  
      case SNvM_WRITE_Data_bkup1_Wait_State:
		   SNvM_Write_bkup1_Data_Wait();
      break;

      case SNvM_WRITE_Data_bkup2_State:
		   SNvM_Write_bkup2_Data();
      break;	  
	  
      case SNvM_WRITE_Data_bkup2_Wait_State:
		   SNvM_Write_bkup2_Data_Wait();
      break;
	  
      case SNvM_WRITE_Header1_State:
           SNvM_Write_Header1();
      break;
	  
	  case SNvM_WRITE_Header1_Wait_State:
			SNvM_Write_Header1_Wait();
      break;

      case SNvM_WRITE_Data_State:
			SNvM_Write_Data();
      break;
    
      case SNvM_WRITE_Data_Wait_State:
			SNvM_Write_Data_Wait();
      break;
      
      case SNvM_WRITE_Header2_State:
			SNvM_Write_Header2();
      break;
    
      case SNvM_WRITE_Header2_Wait_State:
         SNvM_Write_Header2_Wait();
      break;
    
      case SNvM_READ_Header_State:
			SNvM_Read_Header();
      break;
    
      case SNvM_READ_Header_Wait_State:
			SNvM_Read_Header_Wait();
      break;
      
      case SNvM_READ_data_State:
			SNvM_Read_Data();
      break;
	  
	  case SNvM_READ_data_Wait_State:
			SNvM_Read_Data_Wait();
      break;

      default:
      //do nothing
      break;
    }
 
}

/**************************************************************************
Function name   : void SNvM_SetMode(MemIf_ModeType Mode)
Arguments       : MemIf_ModeType Mode
Return type     : void
Description     : Service to call the Fls_SetMode function of the underlying flash driver. 
**************************************************************************/
void SNvM_SetMode(MemIf_ModeType Mode)
{
	(void)Mode;
	/* do nothing */
}

/**************************************************************************
Function name   : Std_ReturnType SNvM_Write(uint16 BlockNumber, const uint8* DataBufferPtr);
Arguments       : void
Return type     : void
Description     : Service to Cancel.
**************************************************************************/
void SNvM_Cancel(void)
{
	/* do nothing */
}

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
MemIf_StatusType SNvM_GetStatus(void)
{

  return SNvM_Status;
}

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
MemIf_JobResultType SNvM_GetJobResult(void)
{
  return SNvM_JobResult;
}

/**************************************************************************
Function name   : Std_ReturnType SNvM_InvalidateBlock( uint16 BlockNumber)
Arguments       : uint16 BlockNumber
Return type     : Std_ReturnType
                  E_OK: The requested job has been accepted by the module.
                  E_NOT_OK - only if DET is enabled: The requested job has not been accepted by the module.
Description     : Service to invalidate a logical block
**************************************************************************/
Std_ReturnType SNvM_InvalidateBlock( uint16 BlockNumber)
{
  (void)BlockNumber;
  return E_NOT_OK;
}

/**************************************************************************
Function name   : void SNvM_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr)
Arguments       : Std_VersionInfoType* VersionInfoPtr
Return type     : void
Description     : Service to return the version information of the SNvM module.
**************************************************************************/
void SNvM_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr)
{
	(void)VersionInfoPtr;
	/* do nothing */
}

/**************************************************************************
Function name   : Std_ReturnType SNvM_EraseImmediateBlock(uint16 BlockNumber)
Arguments       : uint16 BlockNumber
Return type     : Std_ReturnType
                  E_OK: The requested job has been accepted by the module.
                  E_NOT_OK - only if DET is enabled: The requested job has not been accepted by the module.
Description     : This function is called by App/Scheduler when there is an
                  init required. 
**************************************************************************/
Std_ReturnType SNvM_EraseImmediateBlock(uint16 BlockNumber)
{
  (void)BlockNumber;
  return E_NOT_OK;
}


#define SNVM_DATA_SEC_END
#include "MemMap.h"

#define SNVM_CODE_SEC_END
#include "MemMap.h"


#endif /* SNVM_C */
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
/*Date              : 29-03-2023                                                 */
/*Version           :                                                            */
/*By                : gthanapp                                                   */
/*Traceability      :   1883207                                                  */
/*Change Description:  NVM BookShelf Update with Quality fix                     */
/*-------------------------------------------------------------------------------*/
/**------------------------------------------------------------------------------*/
/*Date              : 13-07-2023                                                 */
/*Version           :                                                            */
/*By                : gthanapp                                                   */
/*Traceability      :                                                            */
/*Change Description:  Coverity Warning fix                                      */
/*-------------------------------------------------------------------------------*/
/**------------------------------------------------------------------------------*/
/*Date              : 19-07-2023                                                 */
/*Version           :                                                            */
/*By                : gthanapp                                                   */
/*Traceability      :                                                            */
/*Change Description:  Coverity,Misra,Certc Low Warning fix                      */
/*-------------------------------------------------------------------------------*/


