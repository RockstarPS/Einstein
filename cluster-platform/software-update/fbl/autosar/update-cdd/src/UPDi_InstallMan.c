/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2023. Visteon Corporation owns all rights to           *
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

#include <string.h>
#include "UPDi.h"
#include "UPDi_Target.h"
#include "UPDi_InstallMan.h"
#include "UPDi_Types.h"
#include "UpdateCdd_Types.h"
//=====================================================================================================================
//  CONSTANTS ,TYPES,GLOBAL VARIABLES

uint32_t NextOffset;
tUPDiOpType curentOperation;
tUPDiInstallSession Session;

//==========================================================================================================================================

//=============================================Static variables=============================================================================
static tUPDdPackageName g_UPDi_filename; // TODO EBX : dont need to be static
//=============================================End of static variables======================================================================


//============================================Static Functions===============================================================================
static uint8_t UPDInstallMan_GetPackageLen(const char* arr);
static void parsePackageName(const char* arr, uint8_t packageNameLen, uint8_t* targetNameLen, uint8_t* extensionStartIdx);
static void FindTargetAndInstaller(const char* PackageName, tUPDdPackageName* ChildName, tUPDiAbstractInstaller** ppInstaller,tUPDiTarget** ppTarget)
{
    uint8_t extensionstartindex = 0u;
    uint8_t packageLen = 0u;
    uint8_t targetNameLen = 0u;

    if(PackageName)
    {
		/*get the package length*/
		packageLen = UPDInstallMan_GetPackageLen(PackageName);

		/*get the file extension starting index and the target name size without extension*/
		parsePackageName(PackageName, packageLen, &targetNameLen, &extensionstartindex);

		strncpy(&(*ChildName)[0], PackageName, extensionstartindex);
		(*ChildName)[extensionstartindex-1] = '\0';

		/*get the installer*/
		*ppInstaller = UPDi_AcquireInstaller((PackageName + extensionstartindex),(packageLen - extensionstartindex));
		/*check if target is already calculated or not*/
		(void) strncpy(g_UPDi_filename,PackageName,targetNameLen);
		g_UPDi_filename[targetNameLen]=0;
		*ppTarget = UPDUpdateCdd_GetTargetByName(g_UPDi_filename);
    }
}

//===========================================End of Static Functions==========================================================================


/*===========================================================================================================================================
* Std_ReturnType UPDInstallMan_TransferStart(char* PackageName, uint32_t PackageSize)
* Function description : This function shall trigger the start download service
* Input arguments      : package name , package size
* Return type          : E_OK      - start download service completed successfully
*                        E_PENDING - start download service is ongoing
*                        E_NOT_OK  - start download service is failed
* Function scope       : Private function
*============================================================================================================================================*/ 
Std_ReturnType UPDInstallMan_TransferStart(const char* PackageName, uint32_t PackageSize)
{
    Std_ReturnType status = E_NOT_OK;
    tUPDdPackageName ChildName = {0};
    tUPDiAbstractInstaller* pInstaller = NULL;
    tUPDiTarget* pTarget =NULL;

    FindTargetAndInstaller(PackageName,&ChildName,&pInstaller,&pTarget);

    if(pTarget==NULL )
    {
    	UPDd_ERROR("UPDInstallMan_TransferStart failed, no target detected");
    }
    else if( pInstaller==NULL)
    {
    	UPDd_ERROR("UPDInstallMan_TransferStart failed, no installer detected");
    }
    else if((status = UPDiSession_StartUpdate(&Session,pTarget,pInstaller,PackageSize) )!=E_OK)
    {
    	UPDd_ERROR("UPDiSession_StartUpdate() failed");
    }
    else if((status = UPDTarget_InstallStart(pTarget,&Session) )!=E_OK)
    {
    	if( status != E_PENDING)
    	{
    		UPDd_ERROR("UPDTarget_InstallStart() failed");
    	}
    }
    else
    {
        NextOffset = 0u;
    	curentOperation = eUPDOpInstalling;
    	status = UPDAbstractInstaller_InstallStart(pInstaller,&Session,ChildName,PackageSize);
        if( status==E_NOT_OK )
        {
        	UPDd_ERROR("UPDAbstractInstaller_InstallStart failed");
        }
    }
    return status;
}

/*===========================================================================================================================================
* Std_ReturnType UPDInstallMan_Resume(char* PackageName, uint32_t PackageSize)
* Function description : This function shall resume the ongoing transfer session
* Input arguments      : package name , package size
* Return type          : E_OK      - start download service completed successfully
*                        E_PENDING - start download service is ongoing
*                        E_NOT_OK  - start download service is failed
* Function scope       : Private function
*============================================================================================================================================*/
Std_ReturnType UPDInstallMan_Resume(const char* PackageName, uint32_t PackageSize, uint32_t* pOffset)
{
    Std_ReturnType Status = E_NOT_OK;
    tUPDdPackageName ChildName = {0};
    tUPDiAbstractInstaller* pInstaller = NULL;
    tUPDiTarget* pTarget =NULL;

	FindTargetAndInstaller(PackageName,&ChildName,&pInstaller,&pTarget);

    if( (pTarget==NULL) || (pInstaller==NULL) )
    {}
    else if (UPDiSession_Resume(&Session,pTarget,pInstaller,PackageSize)!=E_OK)
    {}
    else if (NextOffset<=PackageSize)
	{
		*pOffset = NextOffset;

		Status = E_OK;
		if( NextOffset == 0 )
		{
			Status = UPDAbstractInstaller_InstallStart(pInstaller,&Session,ChildName,PackageSize);
		}
		curentOperation = eUPDOpInstalling;
	}

	return Status;
}
/*===========================================================================================================================================
* Std_ReturnType UPDInstallMan_TransferData(uint32_t Size, uint8_t* data)
* Function description : This function shall initiate transfer data service
* Input arguments      : session id,chunk size,data buffer
* Return type          : E_OK       - transfer service data accepted
*                        E_PENDING  - transfer data service not accepted 
*============================================================================================================================================*/
Std_ReturnType UPDInstallMan_TransferData(uint32_t Size, uint8_t* data)
{ 
    Std_ReturnType status = E_NOT_OK;

	status = UPDAbstractInstaller_InstallData(Session.RootInstaller,&Session,data,Size);
	if( status == E_OK )
	{
		NextOffset += Size;
	}

    /*return*/
    return status; 
}
/*===========================================================================================================================================
* Private function     : Std_ReturnType UPDInstallMan_TransferExit(void)
* Function description : This function shall exit the last happend download service
* Input arguments      : none
* Return               : E_OK      - transfer exit service completed successfully
*                        E_PENDING - transfer exit service is ongoing
*                        E_NOT_OK  - transfer exit service failed
*============================================================================================================================================*/
Std_ReturnType UPDInstallMan_TransferExit(void)
{ 
    Std_ReturnType status = E_NOT_OK;
    status = UPDAbstractInstaller_InstallExit(Session.RootInstaller, &Session);
	if(status==E_OK )
	{
		status =  UPDTarget_InstallExit(Session.Target,&Session);
		UPDiSession_ExitUpdate(&Session);
		curentOperation = eUPDOpNone;
	}
    
    return status; 
}
/*===========================================================================================================================================
* Private function     : static uint8_t UPDInstallMan_GetPackageLen(char* arr)
* Function description : This function shall return package length
* Input arguments      : pointer to package name
* Return               : length of the package name
*============================================================================================================================================*/
static uint8_t UPDInstallMan_GetPackageLen(const char* arr)
{
    uint8_t j = 0u;

    while((*(arr + j)) != '\0')
    {
        j++;
    }
    return j;
}

/*===========================================================================================================================================
* Private function     : tUPDiTarget* selectNextTarget(void)
* Function description : This function select the next target to be executed
* Input arguments      : pointer to package name
* Return               : length of the package name
*============================================================================================================================================*/
static tUPDiTarget* selectNextTarget(void)
{
	tUPDiTarget* pNextTarget=NULL;
	uint16_t iTargetCount = UPDi_GetTargetCount();
	uint16_t iTarget;
	tUPDUpdateState UpdateState = UPDUpdateMan_GetUpdateState();

	curentOperation = eUPDOpNone;
	for(iTarget=0; iTarget<iTargetCount; iTarget++)
	{
		tUPDiTarget* pTarget = UPDi_GetTarget(iTarget);
		tUPDiOpType  op =  UPDTarget_GetNextOperation(pTarget,UpdateState);
		if(op>curentOperation )
		{
			curentOperation = op;
			pNextTarget = pTarget;
		}
	}

	return pNextTarget;
}

/*===========================================================================================================================================
* Private function     : UPDInstallMan_PorcessTargets()
* Function description : This function trigger the UPDInstallMan_Task() the re-examine pending targets asking for operations
* Input arguments      : pointer to package name
* Return               : length of the package name
*============================================================================================================================================*/
void UPDInstallMan_PorcessTargets()
{
	if(curentOperation==eUPDOpNone )
	{
		curentOperation = eUPDOpSchedule;
	}
}

/*===========================================================================================================================================
* Private function     : static Std_ReturnType UPDInstallMan_ProcessIO(char* arr)
* Function description : This function select a target and ask to process its IO requests
* Return               : length of the package name
*============================================================================================================================================*/
Std_ReturnType UPDInstallMan_ProcessIO(void)
{
	Std_ReturnType status = E_OK;
	do
	{
		boolean opStart=FALSE;
		tUPDiTarget* pActiveTarget = UPDiSession_GetActiveTarget(&Session);

		// if there is no ongoing operation, let's select a new one
		if(pActiveTarget==NULL)
		{
			pActiveTarget = selectNextTarget();
			if(pActiveTarget!=NULL)
			{
				status = UPDiSession_StartUpdate(&Session,pActiveTarget,NULL,0);
				opStart = TRUE;
			}
		}
		else if((curentOperation==eUPDOpNone ) || (curentOperation == eUPDOpSchedule))
		{
			UPDd_ERROR("UPDInstallMan_ProcessIO() Invalid state");
			UPDiSession_ExitUpdate(&Session);
		}

		// Let's check what's the next operation type
		if( (curentOperation & eUPDOpOperatingMask) == eUPDOpOperating  )
		{
			// Let's execute the ongoing operation
			status = UPDTarget_ProcessIO(pActiveTarget,&Session,curentOperation,opStart);

			if(status!=E_PENDING)
			{
				UPDiSession_ExitUpdate(&Session);
				curentOperation = eUPDOpSchedule;
			}
		}
		else if( curentOperation == eUPDOpInstalling)
		{
			status=E_PENDING;
		}
		else
		{
			curentOperation=eUPDOpNone;
		}
	}
	while( (curentOperation!=eUPDOpNone) && (status != E_PENDING) );
	return status;
}

/*===========================================================================================================================================
* Private function     : static void parsePackageName(char* arr, uint8_t packageNameLen, uint8_t* targetNameLen, uint8_t* extensionStartIdx)
* Function description : This function shall return start index of top most file extension and the size of the target name.
*                        Assumes null terminated string.
* Input arguments      : arr - pointer to package name
*                        packageNameLen - Array length
*                        targetNameLen - returning length of the target
*                        extensionStartIdx - target extension
* Return               : void
*============================================================================================================================================*/
static void parsePackageName(const char* arr, uint8_t packageNameLen, uint8_t* targetNameLen, uint8_t* extensionStartIdx)
{
    uint8_t j = packageNameLen;
    *extensionStartIdx = packageNameLen;
    do
    {
        //Look for dots in the array from end to start
        if(arr[j] == '.')
        {
            //Only catch the first dot found,
            if(*extensionStartIdx == packageNameLen) *extensionStartIdx = j + 1;
            *targetNameLen = j;
        }
    } while( j-- );
}
/*===========================================================================================================================================
* Private function     : static void SetPackageName(char* PackageName ,uint8_t len)
* Function description : This function shall set the target name
* Input arguments      : package name
* Return : void
*============================================================================================================================================*/
Std_ReturnType UPDInstallMan_CopyAllToInactive(void)
{
	Std_ReturnType GlobalStatus = E_OK;
	uint16_t iTargetCount = UPDi_GetTargetCount();
	uint16_t iTarget;
	for(iTarget=0; iTarget<iTargetCount; iTarget++)
	{
		tUPDiTarget* pTarget = UPDi_GetTarget(iTarget);
		Std_ReturnType status = UPDTarget_CopyToInactive(pTarget);
		if(status == E_PENDING)
		{
			if(GlobalStatus == E_OK )
			{
				GlobalStatus = E_PENDING;
			}
		}
		else if(status != E_OK)
		{
			GlobalStatus = status;
		}
	}

	return GlobalStatus;
}
/*===========================================================================================================================================
* Private function     : Std_ReturnType  UPDiInstallMan_Suspend(void)
* Function description : serialize the variables that need to be persisted in NVM
* Input arguments      : stream
* Return : void
*============================================================================================================================================*/
Std_ReturnType  UPDiInstallMan_Suspend(void)
{
	Std_ReturnType status = UPDiSession_Suspend(&Session);
	if( (curentOperation & eUPDOpOperatingMask) ==  eUPDOpOperating  )
	{
		UPDiSession_ExitUpdate(&Session);
		curentOperation = eUPDOpNone;
	}
	return status;
}

/*===========================================================================================================================================
* Private function     : void  UPDiInstallMan_Serialize(tUPDiInstallSession* This,tUPDStream *pStream)
* Function description : serialize the variables that need to be persisted in NVM
* Input arguments      : stream
* Return : void
*============================================================================================================================================*/
void  UPDiInstallMan_Serialize(tUPDStream *pStream)
{
	UPDi_Serialize(pStream, (uint8_t*)&NextOffset, sizeof(NextOffset));
	UPDiSession_Serialize(&Session,pStream);}

/*===========================================================================================================================================
* Private function     : void  UPDiInstallMan_Deserialize(tUPDiInstallSession* This,tUPDStream *pStream)
* Function description : deserialize the variables persisted in NVM
* Input arguments      : stream
* Return : void
*============================================================================================================================================*/
void UPDiInstallMan_Deserialize(tUPDStream *pStream)
{
	UPDi_Deserialize(pStream, (uint8_t*)&NextOffset, sizeof(NextOffset));
	UPDiSession_Deserialize(&Session,pStream);
}

/*===========================================================================================================================================
* Private function     : uint32_t UPDiInstallMan_GetImageOffset(void)
* Function description : return the next offset to be proceed
* Input arguments      : stream
* Return : void
*============================================================================================================================================*/
uint32_t UPDiInstallMan_GetImageOffset(void)
{
	return NextOffset;
}

/*===========================================================================================================================================
* Private function     : Std_ReturnType UPDiInstallMan_Rewind(uint32_t ImageOffset)
* Function description : return to the lastest resumable point
* Input arguments      : offset
* Return : void
*============================================================================================================================================*/
Std_ReturnType UPDiInstallMan_Rewind(uint32_t ImageOffset)
{
	Std_ReturnType status = E_NOT_OK;
	if( ImageOffset<=NextOffset)
	{
		NextOffset -= ImageOffset;
		status = E_OK;
	}
	else
	{
		NextOffset = 0;
	}
	return status;
}

/*===========================================================================================================================================
* void UPDInstallMan_Init(void)
* Return : void
*============================================================================================================================================*/
void UPDInstallMan_Init(void) 
{  
	UPDiSession_Init(&Session);
	curentOperation = eUPDOpNone;
	//NextOffset = 0; TODO when set to zero the Sparse install test case fails
}

/*===========================================================================================================================================
* void UPDInstallMan_Init(void)
* Return : void
*============================================================================================================================================*/
Std_ReturnType UPDInstallMan_VerifyTarget(tUPDiTarget* pTarget, tUPDHashInfo *pHash)
{
	// let's wake-up the target processing, this target may need to be processed, 
	UPDInstallMan_PorcessTargets();

	return UPDTarget_Verify(pTarget, &Session, pHash);
}

/*===========================================================================================================================================
* void UPDInstallMan_Init(void)
* Return : void
*============================================================================================================================================*/
Std_ReturnType UPDInstallMan_GetTargetHash(tUPDiTarget* pTarget, tUPDHashInfo* pHash)
{
	// let's wake-up the target processing, this target need to processed, 
	UPDInstallMan_PorcessTargets();

	// If the session is busy with another target, the target hash need to re-calculated
	boolean reHash = (Session.Target != pTarget);
	return UPDTarget_GetHash(pTarget, &Session, pHash, reHash);
}

/*===========================================================================================================================================
 * Std_ReturnType UPDiInstallMan_Task(void)
 * Function description : Main task
 * Return : none
 * Function scope : public
 *============================================================================================================================================*/
void UPDiInstallMan_Task(void)
{
	UPDiSession_Task(&Session);
}

/*===========================================================================================================================================
 * boolean UPDiInstallMan_IsBusy(void)
 * Function description : This function return true if some IO operations are pending
 * Return : boolean
 * Function scope : public
 *============================================================================================================================================*/
boolean UPDiInstallMan_IsBusy(void)
{
	boolean Busy = UPDiSession_IsBusy(&Session);
	return Busy;
}

/*===========================================================================================================================================
 * tUPDWorkload UPDiInstallMan_GetWorkload(void)
 * Function description : This function return the component business status:
 * Return :
  * eUPD_eWlIdle => No operation pending, calling the task is not required
  * eUPD_eWlLow  => The component load is low, it's the right time to accept a new bunch of data transfer
  * eUPD_eWlHigh => The component load is high, it can accept a new request (at least one).
  *                 The component may not be capable to accept multiple transfer requests.
  * eUPD_eWlFull => The component queue is full, it wont be capable to accept any new request
 * Function scope : public
 *============================================================================================================================================*/
tUPDWorkload UPDiInstallMan_GetWorkload(void)
{
	tUPDWorkload load = Session.Load;
	return load;
}



