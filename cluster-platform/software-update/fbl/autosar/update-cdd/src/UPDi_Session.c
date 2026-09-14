//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2022] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
#include "UPD_Types.h"
#include "UPDi.h"
#include "UPDi_UpdateMan.h"
#include "UPDi_AbstractInstaller.h"
#include "UPD_ICry.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================


//=====================================================================================================================
//  Variables
//=====================================================================================================================


//=====================================================================================================================
//  Req Fifo management
//=====================================================================================================================

//=====================================================================================================================
/** * @brief Get the active target of an UPDI installation session. 
 * This function returns a pointer to the active target of an UPDI installation session. 
 * @param [in] This A valid pointer to an UPDI installation session structure. 
 * @return A pointer to the active target of the UPDI installation session, or NULL if the session is invalid. */
//=====================================================================================================================
tUPDiTarget* UPDiSession_GetActiveTarget(tUPDiInstallSession* This)
{
	tUPDiTarget* pTarget=NULL;
	if(This)
	{
		pTarget=This->Target;
	}
	return pTarget;
}

//===================================================================================================================== 
/** * @brief Checks if the UPDiSession is currently busy with a read or write operation. * 
 * @param [in] This pointer to an instance of tUPDiInstallSession. * 
 * @return TRUE if there is an ongoing read or write operation, FALSE otherwise.  */
//=====================================================================================================================
boolean UPDiSession_IsBusy(tUPDiInstallSession* This)
{
	boolean ret = FALSE;
	if(This)
	{
		if( This->pReadPartition || This->pWritePartition )
		{
			ret = TRUE;
		}
	}
	return ret;
}

//=====================================================================================================================
//  Public Interface
//=====================================================================================================================
//===================================================================================================================== 
/** @brief Initializes a session for an update installation 
   @param [in] This: pointer to the install session object 
   @param [in] pTarget: pointer to the target object 
   @param [in] RootInstaller: pointer to the root installer object 
   @param [in] PackageSize: size of the package to be installed 
   @return Std_ReturnType: E_OK if successful, or an error code otherwise */
// =====================================================================================================================
Std_ReturnType UPDiSession_StartUpdate( tUPDiInstallSession* This, const struct sUPDiTarget* pTarget, const struct sUPDiAbstractInstaller* RootInstaller, uint32_t PackageSize )
{
	Std_ReturnType Status = E_NOT_OK;
	if(This==NULL )
	{}
	else if(pTarget==NULL )
	{}
	else
    {
		tUPDiTargetState TargetState = UPDTarget_GetState(pTarget, UPDUpdateMan_GetUPDatedBank());
        /*Initialize the session attributes*/
		This->RootInstaller = RootInstaller;
		This->Target = pTarget;
		This->EraseUntil = (TargetState==eUPDiTarget_UninstIdleEmpty)?0:UPDi_ERASEALL;

		Status=E_OK;
    }
	return Status;
}

//===================================================================================================================== 
/** @brief Function to clean up resources during exit of update session 
   @param [in] This pointer to the UPDiInstallSession struct 
   @return Std_ReturnType indicating success or failure */
//=====================================================================================================================
Std_ReturnType UPDiSession_ExitUpdate( tUPDiInstallSession* This )
{
	Std_ReturnType Status = E_NOT_OK;
	if(This==NULL )
	{}
	else
    {
		This->RootInstaller = NULL;
		This->Target = NULL;
		Status=E_OK;
    }
	return Status;
}

//===================================================================================================================== 
/** @brief Initializes the session for updating a specific partition. 
   @param [in] This: pointer to the UPDiInstallSession instance. 
   @param [in] PartitionName: name of the partition to update. 
   @param [in] Size: size of the image to be written. 
   @param [in] Compose: flag indicating if the operation is a composition or not(for delta) 
   @return TRUE: if the operation was successful, FALSE otherwise.  */
//=====================================================================================================================
Std_ReturnType UPDiSession_StartPartitionUpdate(tUPDiInstallSession* This, const char* PartitionName, uint32_t Size, boolean Compose)
{
    Std_ReturnType Status = E_OK;
    tUPDdPackageName partName;
    char* OffsetStr;


    tUPDiTarget* pTarget = This->Target;
    if (!pTarget)
    {
        // We intend to install a an image that was not part of any target container.
        // This may be a single image for the full target
        // On that case the Target shall be made a of a single partition with the same name as the Target.
    	return E_NOT_OK;
    }

    // Check if an offset need to be applied.
    strncpy(partName, PartitionName, sizeof(partName));
    partName[sizeof(partName)-1] = 0; // Make sure that the string is NULL terminated
    OffsetStr = strstr(partName, "@");
    if( OffsetStr )
    {
    	*OffsetStr = 0;
    	This->WritePos = strtol(OffsetStr+1,NULL,0);
    }
    else
    {
    	This->WritePos=0;
    }
	This->InitialWritePos = This->WritePos;

    // Identify the partition
    tUPDiPartition* pWritePartition= UPDTarget_GetPartition(pTarget, partName,FALSE);

    if (!pWritePartition)
    {
        Status = E_NOT_OK;
        UPDd_ERROR("UPDiSession_StartPartitionUpdate() failed, write partition not identified");
    }
    else if (pWritePartition->Size < (Size+This->WritePos))
    {
        Status = E_NOT_OK;
        UPDd_ERROR("UPDiSession_StartPartitionUpdate() failed, image size is %lu, it's is too big for %s",(unsigned long)Size,partName);
    }
    else
    {
   	    if (!Compose)
		{
			This->pReadPartition = NULL;
		}
		else if (UPDUpdateMan_GetUPDatedBank() == eUPDiUpdate_BankInactive)
		{
			This->pReadPartition = UPDTarget_GetPartition(pTarget, partName, TRUE);
			if (!This->pReadPartition)
			{
		        UPDd_ERROR("UPDiSession_StartPartitionUpdate() failed, read partition not identified");
				Status = E_NOT_OK;
			}
			else if (This->pReadPartition->Size < Size)
			{
		        UPDd_ERROR("UPDiSession_StartPartitionUpdate() failed, image size is %lu, it's is too big for the read partition %s",(unsigned long)Size,partName);
				Status = E_NOT_OK;
			}
		}
		else
		{
			This->pReadPartition = pWritePartition;
			if (Size >= sizeof(This->CompBuffer))
			{
			    UPDd_ERROR("UPDiSession_StartPartitionUpdate() failed, image size is %lu, it's is too big for the composition buffer",(unsigned long)Size);
				Status = E_NOT_OK;
			}
		}
		if( (Status == E_OK) && ( pWritePartition != This->pWritePartition) )
		{
			 Status = UPDiIoAdapter_StartWriting(pWritePartition->IoAdapter, pWritePartition, This->WritePos, This->EraseUntil);
             This->Load = max( This->Load, eUPD_eWlLow);
             if( Status ==E_OK)
             {
            	 This->pWritePartition = pWritePartition;
             }
		}
    }

    return Status;
}

//===================================================================================================================== 
/** @brief Finishes pending operations in the UPDiSession object. 
   @param [in] This A pointer to an instance of tUPDiInstallSession. 
   @return TRUE if successful, otherwise an error code.  */
//=====================================================================================================================
Std_ReturnType UPDiSession_FinishPartitionUpdate(tUPDiInstallSession* This)// Finish pending operations
{
    Std_ReturnType Status= E_OK;
	uint32_t size = min(This->lastCompBufferPos - This->nextCompBufferPos, UPDd_LOAD_BUFFER_SIZE);
	while (size != 0 && Status == E_OK)
	{
		Status = UPDiIoAdapter_Write(This->pWritePartition->IoAdapter, /*This->nextCompBufferPos,*/ size, This->CompBuffer + This->nextCompBufferPos);
		if (Status == E_OK)
		{
			This->nextCompBufferPos += size;
			size = min(This->lastCompBufferPos - This->nextCompBufferPos, UPDd_LOAD_BUFFER_SIZE);
		}
	}

	if( Status == E_OK )
	{
		 Status = UPDiIoAdapter_FinishWriting(This->pWritePartition->IoAdapter, TRUE, &This->WritePos, NULL);
	}
    if (Status != E_PENDING)
    {
        This->pReadPartition = NULL;
        This->pWritePartition = NULL;
    }
    return Status;
}

//===================================================================================================================== 
/** @brief Performs tasks related to UPDiSession during installation. 
   @param [in] This: A pointer to the UPDiInstallSession structure. 
   @return void  */
//=====================================================================================================================
void UPDiSession_Task(tUPDiInstallSession* This)
{
    if (This == NULL )
    {
    }
    else
    {
        //UPDiSession_ProcessReq(This);
    	if( This->pReadPartition )
    	{
    		UPDiIoAdapter_Task( This->pReadPartition->IoAdapter );
    	}
    	if( This->pWritePartition )
    	{
    		This->Load = UPDiIoAdapter_Task( This->pWritePartition->IoAdapter );
    	}
    	else
    	{
    		This->Load = eUPD_eWlIdle;
    	}
    }
}

//===================================================================================================================== 
/** @brief Initializes the UPDiInstallSession structure. 
   @param [in] This: A pointer to an instance of tUPDiInstallSession. 
   @return None.  */
//=====================================================================================================================
void  UPDiSession_Init(tUPDiInstallSession* This)
{
	if(This)
	{
		memset( This, 0, sizeof(*This));
	}
}
//===================================================================================================================== 
/** @brief Suspends the ongoing update session in the given UPDiInstallSession object. 
   @param [in] This: A valid pointer to an instance of tUPDiInstallSession. 
   @return Std_ReturnType: E_PENDING if update is ongoing, E_OK or E_NOK once done. */
//=====================================================================================================================
Std_ReturnType  UPDiSession_Suspend(tUPDiInstallSession* This)
{
	Std_ReturnType Status=E_NOT_OK;
	if(This)
	{
		// Is there an ongoing update?
		if( This->Target && This->RootInstaller )
		{
			if( This->pWritePartition )
			{
				// read the current sector start & size
				uint32_t rewindOffset, ImageOffset;
				uint32_t sectorStart,EraseUntil;

				Status = UPDiIoAdapter_FinishWriting(This->pWritePartition->IoAdapter, FALSE, &sectorStart, &EraseUntil);
				// note that the flag <ProcessQueue> is set to FLASE on the call above
				// the reason is that the Adapter may be waiting data before being able to flash a full sector or page
				// as we want to suspend no new data will come.

				if( Status == E_OK)
				{
					if(This->EraseUntil != UPDi_ERASEALL)
					{
						This->EraseUntil = EraseUntil;
					}

					// rewind the InstallMan & installers back to sector start
					rewindOffset = (This->WritePos + This->pWritePartition->Address) - sectorStart;

					ImageOffset =  UPDiInstallMan_GetImageOffset();
					if( UPDAbstractInstaller_Rewind(This->RootInstaller, rewindOffset, &ImageOffset) )
					{
						This->WritePos         = sectorStart;
					}
					else
					{
						// We cannot rewind, let's move back the write pointer to the partition start or fragment start
						This->WritePos = This->InitialWritePos;
					}

					Status = UPDiInstallMan_Rewind(ImageOffset);
				}
			}
			else
			{
				// There is and installation ongoing, but we are in between two partition
				// The decoder is loading specific header/packaging info, it need to move back to the header start.
				uint32_t ImageOffset = UPDiInstallMan_GetImageOffset();
				UPDAbstractInstaller_Rewind(This->RootInstaller, 0, &ImageOffset);
				Status = UPDiInstallMan_Rewind(ImageOffset);
			}
		}
		else
		{
			Status = E_OK; // nothing to suspend
		}
	}
	return Status;
}

//===================================================================================================================== 
/** @brief Resume an update session previously suspended.
   @param [in] This: A valid pointer to an instance of tUPDiInstallSession. 
   @return Std_ReturnType: E_PENDING if update is ongoing, E_OK or E_NOK once done. */
//=====================================================================================================================
Std_ReturnType UPDiSession_Resume( tUPDiInstallSession* This, const struct sUPDiTarget* pTarget, const struct sUPDiAbstractInstaller* RootInstaller, uint32_t PackageSize )
{
	Std_ReturnType Status=E_NOT_OK;
	if( !This )
	{}
	else if( (pTarget==This->Target ) && (RootInstaller==This->RootInstaller )  )
	{
		if( This->pWritePartition )
		{
			Status=UPDiIoAdapter_StartWriting(This->pWritePartition->IoAdapter,This->pWritePartition,This->WritePos,This->EraseUntil);
			This->Load = max( This->Load, eUPD_eWlLow);
		}
		else
		{
			// We resumed in between 2 partitions
			Status = E_OK;
		}
	}

	return Status;
}

//===================================================================================================================== 
/** @brief Serialize the persistent state of the session
   @param [in] This: A valid pointer to an instance of tUPDiInstallSession. 
   @return none */
//=====================================================================================================================
void  UPDiSession_Serialize(tUPDiInstallSession* This,tUPDStream *pStream)
{
	if(This && pStream)
	{
		uint8_t wrRootInstallerId    = UPDi_GetInstallerId(This->RootInstaller);
		uint8_t wrTargetId    = UPDi_GetTargetId(This->Target);
		uint8_t wrPartitionId = UPDTarget_GetPartitionId(This->Target,This->pWritePartition);
		uint8_t rdPartitionId = UPDTarget_GetPartitionId(This->Target,This->pReadPartition);

		UPDi_SERIALIZE(pStream, wrRootInstallerId );
		UPDi_SERIALIZE(pStream, wrTargetId);
		UPDi_SERIALIZE(pStream, wrPartitionId);
		UPDi_SERIALIZE(pStream, rdPartitionId);
		UPDi_SERIALIZE(pStream, This->WritePos);
		UPDi_SERIALIZE(pStream, This->EraseUntil);
	}
}

//===================================================================================================================== 
/** @brief Deserialize the persistent state of the session
   @param [in] This: A valid pointer to an instance of tUPDiInstallSession. 
   @return none*/
//=====================================================================================================================
void  UPDiSession_Deserialize(tUPDiInstallSession* This,tUPDStream *pStream)
{
	if(This && pStream)
	{
		uint8_t wrRootInstallerId;
		uint8_t wrTargetId;
		uint8_t wrPartitionId;
		uint8_t rdPartitionId;

		UPDi_DESERIALIZE(pStream, wrRootInstallerId, (uint8_t)-1);
		UPDi_DESERIALIZE(pStream, wrTargetId, (uint8_t)-1);
		UPDi_DESERIALIZE(pStream, wrPartitionId, (uint8_t)-1);
		UPDi_DESERIALIZE(pStream, rdPartitionId, (uint8_t)-1);
		UPDi_DESERIALIZE(pStream, This->WritePos, 0);
		UPDi_DESERIALIZE(pStream, This->EraseUntil, 0);

		This->RootInstaller = UPDi_GetInstallerbyId(wrRootInstallerId);
		This->Target = UPDi_GetTarget(wrTargetId);
		This->pWritePartition = UPDTarget_GetPartitionById(This->Target,wrPartitionId);
		This->pReadPartition = UPDTarget_GetPartitionById(This->Target,rdPartitionId);
	}
}


//===================================================================================================================== 
/** @brief Writes the given data to the current output partition. 
   @param [in] This: A pointer to an instance of tUPDiInstallSession. 
   @param [in] Data: A pointer to the data to be written. 
   @param [in] Size: The size of the data in bytes. 
   @return Std_ReturnType: E_OK if successful, or an error code otherwise. */
//=====================================================================================================================*
Std_ReturnType UPDiSession_WriteNext(tUPDiInstallSession* This, uint8_t* Data, uint32_t Size)
{
	Std_ReturnType Status=E_NOT_OK;
	if(! This )
	{
	}
	else if( This->pWritePartition )
	{
		This->Load = max( This->Load, eUPD_eWlLow);
		Status=UPDiIoAdapter_Write(This->pWritePartition->IoAdapter, Size, Data );
		if( Status == E_OK)
		{
			This->WritePos += Size;
		}
	}
	return Status;
}


//===================================================================================================================== 
/** @brief Copy the  data from read partition to the current output partition. 
   @param [in] This: A pointer to an instance of tUPDiInstallSession. 
   @param [in] ReadOffset: The offest in the read partition where data are located. 
   @param [in] Size: The size of the data in bytes. 
   @return Std_ReturnType: E_OK if successful, or an error code otherwise.  */
//=====================================================================================================================*
Std_ReturnType UPDiSession_CopyNext(tUPDiInstallSession* This, uint32_t ReadOffset, uint32_t Size)
{
	Std_ReturnType Status=E_NOT_OK;
	if(! This )
	{
	}
	else if( This->pWritePartition && This->pReadPartition)
	{
		This->Load = max( This->Load, eUPD_eWlLow);
		Status=UPDiIoAdapter_Copy(This->pWritePartition->IoAdapter, This->pReadPartition, ReadOffset, Size );
		if( Status == E_OK)
		{
			This->WritePos += Size;
		}
	}
	return Status;
}

//===================================================================================================================== 
/** @brief Compose the data from read partition to the current output partition. 
   @param [in] This: A pointer to an instance of tUPDiInstallSession. 
   @param [in] ReadOffset: The offest in the read partition where data are located. 
   @param [in] Data: A pointer to the data to be composed with teh read data. 
   @param [in] Size: The size of the data in bytes. 
   @return Std_ReturnType: E_OK if successful, or an error code otherwise.  */
//=====================================================================================================================*
Std_ReturnType UPDiSession_ComposeNext(tUPDiInstallSession* This, uint32_t ReadOffset, uint8_t* Data, uint32_t Size)
{
	Std_ReturnType Status=E_NOT_OK;
	if(! This )
	{
	}
	else if( This->pWritePartition && This->pReadPartition )
	{
		This->Load = max( This->Load, eUPD_eWlLow);
		Status=UPDiIoAdapter_Compose(This->pWritePartition->IoAdapter,This->pReadPartition, ReadOffset, Size, Data, eUPDi_COMPOSITION_BYTEWIZE_ADD );
		if( Status == E_OK)
		{
			This->WritePos += Size;
		}
	}
	return Status;
}

//===================================================================================================================== 
/** @brief Erases the specified partition . 
   @param [in] This: A pointer to a valid UPD installation session structure. 
   @param [in] pPartition: A pointer to a valid UPD partition structure. 
   @return TRUE if the operation was successful, otherwise FALSE.  */
//=====================================================================================================================
Std_ReturnType UPDiSession_ErasePartition(tUPDiInstallSession* This, tUPDiPartition* pPartition)
{
	Std_ReturnType Status=E_NOT_OK;
	if(! This )
	{
	}
	else if( pPartition )
	{
		Status=UPDiIoAdapter_Erase(pPartition->IoAdapter,pPartition );
	}
	return Status;
}

//===================================================================================================================== 
/** @brief Initializes hashing session for a given UPDiTarget and IO adapter. 
   @param [in] This: pointer to an instance of tUPDiInstallSession. 
   @param [in] pTarget: pointer to a const sUPDiTarget structure. 
   @param [in] pIoAdapter: pointer to a tUPDiIoAdapter structure. 
   @return Std_ReturnType: E_NOT_OK if initialization failed, otherwise E_OK.  */
//=====================================================================================================================
Std_ReturnType UPDiSession_StartHashing(tUPDiInstallSession* This, const struct sUPDiTarget* pTarget, tUPDiIoAdapter* pIoAdapter)
{
    Std_ReturnType Status = E_NOT_OK;
    This->WritePos = 0;
    This->pReadPartition = NULL;
    This->pWritePartition = NULL;
	This->Target = pTarget;

    if(This)
    {
    	if( This->pHashingAdapter == NULL)
    	{
    		This->Load = max( This->Load, eUPD_eWlLow);
			Status = UPDiIoAdapter_StartHashing(pIoAdapter, UPDd_HASH_TYPE, UPDd_HASH_SIZE);
			if( Status == E_OK )
			{
	    		This->pHashingAdapter = pIoAdapter;
			}
    	}
    }
	return Status;
}

//===================================================================================================================== 
/** @brief Hash a block of data as part of the ongoing hashing session 
   @param [in] This: pointer to an instance of tUPDiInstallSession. 
   @param [in] pPartition: pointer to a tUPDiPartition structure. 
   @param [in] Offset: Offset in the partition. 
   @param [in] Size: Size to be hashed 
   @return Std_ReturnType: E_NOT_OK if initialization failed, otherwise E_OK.  */
//=====================================================================================================================
Std_ReturnType UPDiSession_Hash(tUPDiInstallSession* This, tUPDiPartition* pPartition, uint32_t Offset, uint32_t Size)
{
    Std_ReturnType Status = E_NOT_OK;
    if(This)
    {
    	if( This->pHashingAdapter )
    	{
    		This->Load = max( This->Load, eUPD_eWlLow);
			Status = UPDiIoAdapter_Hash(This->pHashingAdapter, pPartition, Offset, Size);
    	}
    }
	return Status;
}
//===================================================================================================================== 
/** @brief Exits the hashing session and provide the resulting the hash. 
   @param [in] This: A pointer to the UPDiInstallSession structure. 
   @param [in] pTarget: A pointer to the target structure. 
   @param [out] pHash: A pointer to the hash information structure to be filled with the hash data. 
   @return TRUE if the operation was successful, otherwise FALSE.  */
//================================================================================�����-=====================
Std_ReturnType UPDiSession_ExitHashing(tUPDiInstallSession* This, const struct sUPDiTarget* pTarget, tUPDHashInfo* pHash)
{
    Std_ReturnType Status = E_NOT_OK;
    if(This)
    {
    	if( (This->pHashingAdapter != NULL) && (This->Target == pTarget) && (pHash != NULL))
    	{
			pHash->HashSize = UPDd_HASH_SIZE;
			pHash->HashType = UPDd_HASH_TYPE;
			Status = UPDiIoAdapter_FinishHashing(This->pHashingAdapter, pHash);
			if( Status != E_PENDING )
			{
	    		This->pHashingAdapter = NULL;
				This->Target = NULL;
			}
    	}
    }
	return Status;
}
