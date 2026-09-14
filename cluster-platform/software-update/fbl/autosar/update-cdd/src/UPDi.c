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

#include "UPD_IUpdate.h"
#include "UPD_ITargets.h"
#include "UPD_IInstallation.h"
#include "UPDi.h"
#include "stdio.h"
#include "string.h"
#include "UpdateCdd_Types.h"

//=====================================================================================================================
/* Global variables*/
//=====================================================================================================================
static const uint8_t NvmLayoutVersion = 1;

/*===========================================================================================================================================
 * Std_ReturnType UPD_IInstallation_TransferStart(char* PackageName, uint32 PackageSize)
 * Function description : TransferStart interface shall initiate request download service
 * Return : E_OK        - successfully initiated start download service
 E_PENDING   - requested start downloading service is ongoing
 E_NOT_OK    - requested start download service failed
 * Function scope : Public
 * ===========================================================================================================================================*/
Std_ReturnType UPD_IInstallation_TransferStart(const char *PackageName, uint32_t PackageSize)
{
	Std_ReturnType status;

	/*Call to installation manager*/
	status = UPDInstallMan_TransferStart(PackageName, PackageSize);

	/*return the status*/
	return status;
}

/*===========================================================================================================================================
 * Std_ReturnType UPD_IInstallation_Resume(const char *PackageName,uint32 PackageSize, uint32* pOffset)
 * Function description : Resume the transfer initiatied during the last power cycle
 * Return :
 *  E_OK        - successfully initiated start download service
 *  E_PENDING   - requested start downloading service is ongoing
 *  E_NOT_OK    - requested start download service failed
 * Function scope : Public
 * ===========================================================================================================================================*/
Std_ReturnType UPD_IInstallation_Resume(const char *PackageName,uint32_t PackageSize, uint32_t* pOffset)
{
	Std_ReturnType status = E_NOT_OK;
	if( (UPDUpdateMan_GetUpdateState()==eUPDiUpdate_Updating) && pOffset)
	{
		status = UPDInstallMan_Resume(PackageName,PackageSize,pOffset);
	}
	return status;
}
/*===========================================================================================================================================
 * Std_ReturnType UPD_IInstallation_TransferData(uint32 Size, uint8* data)
 * Function description : TransferData service shall download/program the installation package on target
 * Return : E_OK        - transfer data service accepted
 *          E_PENDING   - transfer data service not accepted
 *============================================================================================================================================*/
Std_ReturnType UPD_IInstallation_TransferData(uint32_t Size, uint8_t *data)
{
	Std_ReturnType status;
	/*call to installation manager*/
	status = UPDInstallMan_TransferData(Size, data);
	return status;
}


/*===========================================================================================================================================
 * Public user interface : Std_ReturnType UPD_IInstallation_TransferExit()
 * Function description : This function shall exit the transfer session
 * Return : E_OK        -  download service exited successfully
 *          E_PENDING   - Pending exit service
 *          E_NOT_OK    - Exit service failed
 *============================================================================================================================================*/
Std_ReturnType UPD_IInstallation_TransferExit(void)
{
	Std_ReturnType status;
	status = UPDInstallMan_TransferExit();
	return status;
}

/*===========================================================================================================================================
 * Public user interface : Std_ReturnType UPD_IInstallation_CopyToInactive(uint8 TargetId)
 * Function description : Request to copy the active to the inactive copy of the target ( useless if UPDd_AUTO_SYNCH is enabled )
 * Return : E_OK        - Job is done & is successfull
 *          E_PENDING   - Job is pending
 *          E_NOT_OK    - Job failed
 *============================================================================================================================================*/
Std_ReturnType UPD_IInstallation_CopyToInactive(uint8_t TargetId)
{
	Std_ReturnType Status = E_NOT_OK;
	if( (UPDUpdateMan_GetUpdateState()&eUPDiUpdate_Level1Mask)==eUPDiUpdate_Idle )
	{
		tUPDiTarget* pTarget = UPDi_GetTarget(TargetId);
		if(pTarget)
		{
			Status = UPDTarget_CopyToInactive(pTarget);
			if(Status!=E_PENDING)
			{
				UPDd_TriggerNvmWrite();
			}
		}
	}
	return Status;
}

/*===========================================================================================================================================
 * Public user interface : Std_ReturnType UPD_IInstallation_CopyAllToInactive(void)
 * Function description : Request to copy all target from active to the inactive ( useless if UPDd_AUTO_SYNCH is enabled )
 * Return : E_OK        - Job is done & is successfull
 *          E_PENDING   - Job is pending
 *          E_NOT_OK    - Job failed
 *============================================================================================================================================*/
Std_ReturnType UPD_IInstallation_CopyAllToInactive(void)
{
	Std_ReturnType Status = E_NOT_OK;
	if( (UPDUpdateMan_GetUpdateState()&eUPDiUpdate_Level1Mask)==eUPDiUpdate_Idle )
	{
		Status = UPDInstallMan_CopyAllToInactive();
        if(Status!=E_PENDING)
		{
			UPDd_TriggerNvmWrite();
		}
	}
	return Status;
}

/*===========================================================================================================================================
 * Public user interface : const char* UPD_ITargets_GetTargetNameById(uint8 TargetId)
 * Function description : return the name of the given target
 * Return : target name
 *============================================================================================================================================*/
const char* UPD_ITargets_GetTargetNameById(uint8_t TargetId)
{
	const char *TargetName = NULL;
	tUPDiTarget *TargetInfo = NULL;
	TargetInfo = UPDi_GetTarget(TargetId);
	TargetName = (const char*) (&(TargetInfo->Name[0u]));
	return TargetName;
}


//=====================================================================================================================
//  Update interface
//=====================================================================================================================

/*=====================================================================================================================
 * Public interface  : UPD_IUpdate
 * all services form UPD_IUpdate are delegated to  UPDUpdateMan
 *=====================================================================================================================*/
Std_ReturnType UPD_IUpdate_StartUPDate(tUPDBank Bank)
{
	/*Call to internal function*/
	return UPDUpdateMan_StartUPDate(Bank);
}
Std_ReturnType UPD_IUpdate_Validate(void)
{
	/*Call to internal function*/
	return UPDUpdateMan_Validate();
}
Std_ReturnType UPD_IUpdate_Activate(void)
{
	/*Call to internal function*/
	return UPDUpdateMan_Activate();
}
Std_ReturnType UPD_IUpdate_Rollback(void)
{
	/*Call to internal function*/
	return UPDUpdateMan_Rollback();
}
Std_ReturnType UPD_IUpdate_Terminate(void)
{
	/*Call to internal function*/
	return UPDUpdateMan_Reset();
}
Std_ReturnType UPD_IUpdate_Commit(void)
{
	/*Call to internal function*/
	return UPDUpdateMan_Commit();
}
tUPDUpdateState UPD_IUpdate_GetUpdateState(void)
{
	return UPDUpdateMan_GetUpdateState();
}
Std_ReturnType UPD_IUpdate_BootStatus(boolean BootSuccess)
{
	return UPDUpdateMan_BootStatus(BootSuccess);
}
tUPDUpdateState UPD_IUpdate_GetState(void)
{
	return UPDUpdateMan_GetUpdateState();
}

/*=====================================================================================================================
 * Public interface  : uint8 UPD_ITargetCount(void)
 * Function description : This function shall return the target count
 * Input argumnet : void
 * Return : return target count
 *=====================================================================================================================*/
uint8_t UPD_ITargetCount(void)
{
	return UPDi_GetTargetCount();
}

//=====================================================================================================================
//  Update interface
//=====================================================================================================================
Std_ReturnType UPD_ITargets_GetManifest(const char *TargetName, tUPDBank Bank)
{
	Std_ReturnType status = E_NOT_OK;
	status = UPDUpdateCdd_GetManifest(TargetName, Bank);
	return status;
}

/*=====================================================================================================================
 * Public function  : Std_ReturnType UPD_ITargets_GetTargetState(const char* TargetName, tUPDBank Bank)
 * Function description : This function shall return target state
 * Input argumnet : pointer to target info , bank type(active/inactive bank)
 * Return : E_OK - successful download
 *          E_NOT_OK - failed
 *          E_PENDING - download is in progress
 *=====================================================================================================================*/
tUPDiTargetState UPD_ITargets_GetTargetState(const char *TargetName,
		tUPDBank Bank)
{
	tUPDiTargetState State = eUPDiTarget_Invalid;

	/*Get the target info using name*/
	tUPDiTarget *pTarget = UPDUpdateCdd_GetTargetByName((char*) TargetName);

	if (NULL != pTarget)
	{
		State = UPDTarget_GetState(pTarget, Bank);
	}

	return State;
}

/*=====================================================================================================================
 * Public function  : Std_ReturnType UPD_ITargets_GetTargetState(const char* TargetName, tUPDBank Bank)
 * Function description : This function shall return target state
 * Input argumnet : pointer to target info , bank type(active/inactive bank)
 * Return : E_OK - successful download
 *          E_NOT_OK - failed
 *          E_PENDING - download is in progress
 *=====================================================================================================================*/
tUPDiTargetState UPD_ITargets_GetTargetStateById(uint8_t TargetId,tUPDBank Bank)
{
	tUPDiTargetState State = eUPDiTarget_Invalid;
	if (TargetId < oUPDCdd.TargetsCount)
	{
		tUPDiTarget *pTarget = oUPDCdd.Targets[TargetId];
		State = UPDTarget_GetState(pTarget, Bank);
	}

	return State;
}

/*=====================================================================================================================
 * Public function  : tUPDdManifest*   UPD_ITargets_GetManifestById(uint8 TargetId, tUPDBank Bank)
 * Function description : This function shall return a pointer the the manifest
 * Input argumnet : pointer to target info , bank type(active/inactive bank)
 * Return : pManifest
 *=====================================================================================================================*/
tUPDdManifest*   UPD_ITargets_GetManifestById(uint8_t TargetId, tUPDBank Bank)
{
	tUPDdManifest* pMan = NULL;
	if (TargetId < oUPDCdd.TargetsCount)
	{
		tUPDiTarget *pTarget = oUPDCdd.Targets[TargetId];
		pMan = UPDTarget_GetManifest(pTarget, Bank);
	}

	return pMan;
}
/*===========================================================================================================================================
 * Std_ReturnType UPD_ITargets_VerifyAllTargets(tUPDHashingTypes HashingTypes, tUPDBank Bank)
 * Function description : This function shall perform verification for all targets
 * Return : E_OK - verification request accepted
 : E_NOT_OK - verification request not accepted
 * Function scope : public
 *============================================================================================================================================*/
Std_ReturnType UPD_ITargets_VerifyTarget(uint8_t TargetId, tUPDHashInfo *pHash)
{
	Std_ReturnType status = E_NOT_OK;
	if (TargetId < oUPDCdd.TargetsCount)
	{
		status = UPDInstallMan_VerifyTarget(oUPDCdd.Targets[TargetId], pHash);
	}
	return status;
}

/*===========================================================================================================================================
 * Std_ReturnType UPD_ITargets_VerifyAllTargets(tUPDHashingTypes HashingTypes, tUPDBank Bank)
 * Function description : This function shall perform verification for all targets
 * Return : E_OK - verification request accepted
 : E_NOT_OK - verification request not accepted
 * Function scope : public
 *============================================================================================================================================*/
Std_ReturnType UPD_ITargets_GetHash(uint8_t TargetId, tUPDHashInfo* pHash)
{
	Std_ReturnType status = E_NOT_OK;
	if (TargetId < oUPDCdd.TargetsCount)
	{
		tUPDiTarget *pTarget = oUPDCdd.Targets[TargetId];
		// The hash can be read from the manifest whatever is the state of the target
		// If the hash verification fails the manifest is updated with the actual hash value, and the target state is set to "undefined"
		status = UPDInstallMan_GetTargetHash(pTarget,pHash);
	}
	return status;
}

//=====================================================================================================================
//  Management functions
//=====================================================================================================================
/*===========================================================================================================================================
 * Std_ReturnType UPD_Init(void)
 * Function description : This function shall init IO adapter and target
 * Return :
 *============================================================================================================================================*/
Std_ReturnType UPD_Init(void)
{
	Std_ReturnType status = E_NOT_OK;
	UPDInstallMan_Init();
	UPDUpdateMan_Init();

	/*target initialization*/
	uint8_t TargetId;
	for (TargetId = 0u; TargetId < oUPDCdd.TargetsCount; TargetId++)
	{
		UPDTarget_Init(oUPDCdd.Targets[TargetId]);
	}
	return status;
}
/*===========================================================================================================================================
 * Std_ReturnType UPD_Task(void)
 * Function description : This function shall monitor already triggred operation
 * Return : E_OK -
 : E_NOT_OK
 : E_PENDING
 * Function scope : public
 *============================================================================================================================================*/
Std_ReturnType UPD_Task(void)
{
	Std_ReturnType status = E_OK;
	UPDUpdateMan_Task();
	UPDiInstallMan_Task();
	return status;
}

/*===========================================================================================================================================
 * boolean UPD_IsBusy(void)
 * Function description : This function return true if some IO operations are pending
 * Return : boolean
 * Function scope : public
 *============================================================================================================================================*/
boolean UPD_IsBusy(void)
{
	return UPDiInstallMan_IsBusy();
}

/*===========================================================================================================================================
 * tUPDWorkload UPD_GetWorkload(void)
 * Function description : This function return the component business status:
 * Return :
  * eUPD_eWlIdle => No operation pending, calling the task is not required
  * eUPD_eWlLow  => The component load is low, it's the right time to accept a new bunch of data transfer
  * eUPD_eWlHigh => The component load is high, it can accept a new request (at least one).
  *                 The component may not be capable to accept multiple transfer requests.
  * eUPD_eWlFull => The component queue is full, it wont be capable to accept any new request
 * Function scope : public
 *============================================================================================================================================*/
tUPDWorkload UPD_GetWorkload(void)
{
	return UPDiInstallMan_GetWorkload();
}

/*===========================================================================================================================================
 * Std_ReturnType UPDi_InitStream(tUPDStream *pStream, void *data, uint32 Size)
 * Function description : Initialize the stream structure for starting a serialization or de-serialization
 * Return : Std_ReturnType
 *============================================================================================================================================*/
Std_ReturnType UPDi_InitStream(tUPDStream *pStream, void *data, uint32_t Size)
{
	Std_ReturnType status = E_NOT_OK;
	if (! pStream )
	{
	}
	if (pStream && data && Size)
	{
		pStream->overflow = FALSE;
		pStream->data = data;
		pStream->size = Size;
		pStream->badData = FALSE;
		pStream->keepDefault = FALSE;
		status = E_OK;
	}
	else
	{
		pStream->overflow = FALSE;
		pStream->data = NULL;
		pStream->size = 0;
		pStream->badData = FALSE;
		pStream->keepDefault = TRUE;
		status = E_OK;
	}

	return status;

}

/*===========================================================================================================================================
 * Std_ReturnType UPDi_Deserialize(tUPDStream *pStream, void *data, uint32 Size)
 * Function description : Retreive a single data element form the stream
 * Return : Std_ReturnType
 *============================================================================================================================================*/
Std_ReturnType UPDi_Deserialize(tUPDStream *pStream, void *data, uint32_t Size)
{
	Std_ReturnType status = E_NOT_OK;
	if (pStream->keepDefault)
	{
		status = E_OK;
	}
	else if (Size < (pStream->size))
	{
		memcpy(data, pStream->data, Size);
		pStream->size -= Size;
		pStream->data = (uint8_t*)(pStream->data) + Size;
		status = E_OK;
	}
	else
	{
		pStream->overflow = TRUE;
	}
	return status;
}


/*===========================================================================================================================================
 * Std_ReturnType UPDi_Serialize(tUPDStream *pStream, void *data, uint32 Size)
 * Function description : push a single data element to the stream
 * Return : Std_ReturnType
 *============================================================================================================================================*/
Std_ReturnType UPDi_Serialize(tUPDStream *pStream, void *data, uint32_t Size)
{
	Std_ReturnType status = E_NOT_OK;
	if (Size < (pStream->size))
	{
		memcpy(pStream->data, data, Size);
		pStream->size -= Size;
		pStream->data = (uint8_t*)(pStream->data) + Size;
		status = E_OK;
	}
	else
	{
		pStream->overflow = TRUE;
	}
	return status;
}

/*===========================================================================================================================================
 * Std_ReturnType UPD_Deserialize(tUPDStream* pStream)
 * Function description : This function shall read the UPD persistent data from NVM buffer
 * Return : void
 *============================================================================================================================================*/
static void Deserialize(tUPDStream *pStream)
{
	if (pStream)
	{
		uint8_t TargetsCount,InstallersCount;
		uint8_t CurentNvmLayoutVersion;
		//uint8 CurentNvmLayoutVersionDeployed;

		UPDi_DESERIALIZE(pStream, CurentNvmLayoutVersion, NvmLayoutVersion );
		//UPDi_DESERIALIZE(pStream, CurentNvmLayoutVersionDeployed, UPDd_NvmLayoutVersionDeployed);
		UPDi_DESERIALIZE(pStream, TargetsCount, oUPDCdd.TargetsCount );
		UPDi_DESERIALIZE(pStream, InstallersCount, oUPDCdd.InstallersCount );

		UPDUpdateMan_Deserialize(pStream);
		UPDiInstallMan_Deserialize(pStream);

		if ( (oUPDCdd.TargetsCount != TargetsCount)       ||
			 (oUPDCdd.InstallersCount != InstallersCount) ||
			 (NvmLayoutVersion != CurentNvmLayoutVersion )/*||
			 (UPDd_NvmLayoutVersionDeployed != CurentNvmLayoutVersionDeployed)*/)
		{
			pStream->badData = TRUE;
			UPDd_WARNING("UPD_Deserialize() Incompatible NVM Layout");
		}
		else
		{
			uint8_t TargetId;
			uint8_t InstallerId;

			for (TargetId = 0u; TargetId < oUPDCdd.TargetsCount; TargetId++)
			{
				tUPDiTarget *pTarget = oUPDCdd.Targets[TargetId];
				UPDTarget_Deserialize(pTarget, pStream);
			}

			for (InstallerId = 0u; InstallerId < oUPDCdd.InstallersCount; InstallerId++)
			{
				tUPDiAbstractInstaller *pInstaller = oUPDCdd.Installers[InstallerId];
				UPDAbstractInstaller_Deserialize(pInstaller, pStream);
			}

			if(pStream->overflow )
			{
				UPDd_ERROR("UPD_Deserialize() Incompatible NVM Layout, stream underflowed");
				UPD_Init();
			}
		}
	}
}

/*===========================================================================================================================================
 * Std_ReturnType UPD_Deserialize(tUPDStream* pStream)
 * Function description : Deserialize the persistent state of the overall UPD component from the stream
 * Return : void
 *============================================================================================================================================*/
Std_ReturnType UPD_Deserialize(tUPDStream *pStream)
{
	Std_ReturnType status = E_NOT_OK;

	Deserialize(pStream);
	if ( pStream->overflow || pStream->badData )
	{
		// Let's deserialize with Default values.
		pStream->keepDefault=TRUE;
		Deserialize(pStream);
		UPDd_WARNING("UPD_Deserialize() NVM Data reinitialized");
	}
	else
	{
		status = E_OK;
	}
	return status;
}

/*===========================================================================================================================================
 * Std_ReturnType UPD_Suspend(void)
 * Function description : Suspend the ongoing activities before shutdown
 * Return : void
 *============================================================================================================================================*/
Std_ReturnType UPD_Suspend(void)
{
	Std_ReturnType status =	UPDiInstallMan_Suspend();
	if( status != E_PENDING )
	{
		for (uint8_t TargetId = 0u; TargetId < oUPDCdd.TargetsCount; TargetId++)
		{
			UPDTarget_Suspend(oUPDCdd.Targets[TargetId]);
		}
	}
	return status;
}

/*===========================================================================================================================================
 * Std_ReturnType UPD_Deserialize(tUPDStream* pStream)
 * Function description : This function shall write the UPD persistent data to NVM buffer
 * Return : void
 *============================================================================================================================================*/
Std_ReturnType UPD_Serialize(tUPDStream *pStream)
{
	Std_ReturnType status = E_NOT_OK;

	if (pStream)
	{
		uint8_t TargetId,InstallerId;
		uint8_t TargetsCount = oUPDCdd.TargetsCount;
		uint8_t InstallersCount = oUPDCdd.InstallersCount;

		UPDi_SERIALIZE(pStream, NvmLayoutVersion );
		//UPDi_SERIALIZE(pStream, UPDd_NvmLayoutVersionDeployed );
		UPDi_SERIALIZE(pStream, TargetsCount );
		UPDi_SERIALIZE(pStream, InstallersCount );

		UPDUpdateMan_Serialize(pStream);
		UPDiInstallMan_Serialize(pStream);

		for (TargetId = 0u; TargetId < oUPDCdd.TargetsCount; TargetId++)
		{
			tUPDiTarget *pTarget = oUPDCdd.Targets[TargetId];
			UPDTarget_Serialize(pTarget, pStream);
		}

		for (InstallerId = 0u; InstallerId < oUPDCdd.InstallersCount; InstallerId++)
		{
			tUPDiAbstractInstaller *pInstaller = oUPDCdd.Installers[InstallerId];
			UPDAbstractInstaller_Serialize(pInstaller, pStream);
		}

		if (pStream->overflow == FALSE)
		{
			status = E_OK;
		}
	}
	return status;
}

/*=====================================================================================================================
 * tUPDiAbstractInstaller* UPDi_AcquireInstaller(const char* Extension)
 * Function description : This function shall return the installer
 * Input argumnet : pointer to file extension
 * Return : Returns the installer type
 * Function scope : private method
 *=====================================================================================================================*/
tUPDiAbstractInstaller* UPDi_AcquireInstaller(const char *Extension, uint8_t len)
{
	tUPDiAbstractInstaller *pReturnedInstaller = NULL;
	static int ret = 0xFF;

	for (uint16_t i = 0u; i < oUPDCdd.InstallersCount; i++)
	{
		tUPDiAbstractInstaller * pInstaller = oUPDCdd.Installers[i];
		ret = strncmp(UPDAbstractInstaller_GetExtension(pInstaller), Extension,
				len);
		if (ret == 0)
		{
			pReturnedInstaller = pInstaller;
			break;
		}
	}
	if( pReturnedInstaller == NULL)
	{
		UPDd_WARNING("UpdAbtractInstaller() no decoder found for <%s> extension",Extension);
	}
	return pReturnedInstaller;
}

/*=====================================================================================================================
 * tUPDiTarget* UPDi_GetTarget(uint8 TargetId)
 * Function description : return a pointer to the target object thru its ID
 * Return : Returns a pointer to the target, NULL if target is invalid
 * Function scope : private method to UPD
 *=====================================================================================================================*/
tUPDiTarget* UPDi_GetTarget(uint8_t TargetId)
{
	tUPDiTarget *TargetInfo = NULL;
	if (TargetId < oUPDCdd.TargetsCount)
	{
		TargetInfo = oUPDCdd.Targets[TargetId];
	}
	/*return the target*/
	return TargetInfo;
}

/*=====================================================================================================================
 * uint8  UPDi_GetTargetId(tUPDiTarget*pTarget)
 * Function description : return a ID of a target thru the pointer
 * Return : Returns a  target ID
 * Function scope : private method to UPD
 *=====================================================================================================================*/
uint8_t  UPDi_GetTargetId(tUPDiTarget*pTarget)
{
	for (uint8_t TargetId = 0u; TargetId < oUPDCdd.TargetsCount; TargetId++)
	{
		if( pTarget == oUPDCdd.Targets[TargetId] )
		{
			return TargetId;
		}
	}
	return -1;
}

/*=====================================================================================================================
 * uint8 UPDi_GetTargetCount(void)
 * Function description : return the count of target. Valid target ID are with the range  [0; count[
 * Return : Target count
 * Function scope : private method to UPD
 *=====================================================================================================================*/
uint8_t UPDi_GetTargetCount(void)
{
	return oUPDCdd.TargetsCount;
}

/*=====================================================================================================================
 * tUPDiAbstractInstaller* UPDi_GetInstallerbyId(uint8 Id)
 * Function description : return a pointer to the installer thru its ID
 * Return : pointer to the installer
 * Function scope : private method to UPD
 *=====================================================================================================================*/
tUPDiAbstractInstaller* UPDi_GetInstallerbyId(uint8_t Id)
{
	if( Id<oUPDCdd.InstallersCount)
	{
		return oUPDCdd.Installers[Id];
	}
	return NULL;
}

/*=====================================================================================================================
 * uint8 UPDi_GetInstallerId(tUPDiAbstractInstaller* pInstaller)
 * Function description : return a ID to the installer thru its pointer
 * Return : ID of the installer
 * Function scope : private method to UPD
 *=====================================================================================================================*/
uint8_t UPDi_GetInstallerId(tUPDiAbstractInstaller* pInstaller)
{
	for (uint16_t i = 0u; i < oUPDCdd.InstallersCount; i++)
	{
		if(pInstaller == oUPDCdd.Installers[i] )
		{
			return i;
		}
	}
	return -1;
}

