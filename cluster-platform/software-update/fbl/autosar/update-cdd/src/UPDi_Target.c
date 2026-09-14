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
#include "UPDi.h"
#include "UPD.h"
#include "UpdateCdd_Types.h"

#include <stdlib.h> // for min() and max()  - TODO use Visteon STD lib
#include <string.h> // for memcmp()  - TODO use Visteon STD lib

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
#define BANKA_PARTITION_ID 0x80
#define BANKB_PARTITION_ID 0x40
#define BANKEXT_PARTITION_ID 0x00
#define MAX_GROUP_COUNT 0x40
#define GROUP_MASK 0x3F

//=====================================================================================================================
//  Static Variables
//=====================================================================================================================
//=====================================================================================================================
//  Private functions
//=====================================================================================================================
static boolean IsInvalid(tUPDiTarget* This)
{
    boolean ret = TRUE;
#ifndef UPDd_POINTER_TEST_DISABLED
    if (This != NULL)
    {
        ret = ( This->pRam == NULL);
    }
    if (ret)
    {
        UPDd_ERROR("UPDiGenDecoder IsInvalid()");
    }
#else
    ret = FALSE;
#endif
    return ret;
}

/*==============================================================================================================================================================
* static void InitIterator(tUPDiTarget* This)
* Function description : initialize nextByte and nextPartitionIndex
*===============================================================================================================================================================*/ 
static void InitIterator(tUPDiTarget* This)
{
	tUPDiTargetRam* pRam=This->pRam;
	pRam->nextByte=0;
	pRam->nextPartitionIndex=0;
}

/*==============================================================================================================================================================
* static tUPDdManifest* GetManifest(tUPDiTarget* This,tUPDBank Bank)
* Function description : helper function, get the manifest for the given bank
*===============================================================================================================================================================*/ 
static tUPDdManifest* GetManifest(tUPDiTarget* This,tUPDBank Bank)
{
	tUPDdManifest* pManifest = NULL;
	if( This->Type ==eTargetTypeAOnly)
	{
		if( Bank != eUPDiUpdate_BankActive )
		{
			UPDd_ERROR("Cannot access to the Inactive slot of an AOnly target <%s>",This->Name);
		}
		pManifest = &(This->pSlots[0].Manifest);
	}
	else
	{
		boolean Slot = UPDUpdateMan_GetSlot(Bank);
		// both AB and ABExt target have two slots.
		// the slot is implemented as a boolean value and used like an index to access related data
		if( Slot < UPD_AB_SLOT_COUNT )
		{
			pManifest = &(This->pSlots[Slot].Manifest);
		}
		else
		{
			UPDd_ERROR("Invalid slot");
		}
	}
	return pManifest;
}

/*==============================================================================================================================================================
* static tUPDiTargetState GetState(tUPDiTarget* This,tUPDBank Bank)
* Function description : helper function, get the state for the given bank
*===============================================================================================================================================================*/ 
static tUPDiTargetState GetState(tUPDiTarget* This,tUPDBank Bank)
{
	tUPDiTargetState State = eUPDiTarget_Invalid;
	if( This->Type ==eTargetTypeAOnly)
	{
		if( Bank != eUPDiUpdate_BankActive )
		{
			State = eUPDiTarget_Invalid;
		}
		else
		{
			State = This->pSlots[0].State;
		}
	}
	else
	{
		boolean Slot = UPDUpdateMan_GetSlot(Bank);
		// both AB and ABExt target have two slots.
		// the slot is implemented as a boolean value and used like an index to access related data
		if( Slot < UPD_AB_SLOT_COUNT )
		{

			State = This->pSlots[Slot].State;
		}
		else
		{
			UPDd_ERROR("Invalid slot");
		}
	}
	return State;
}

/*==============================================================================================================================================================
* static void SetState(tUPDiTarget* This, tUPDBank Bank, tUPDiTargetState State)
* Function description : helper function, set the state for the given bank
*===============================================================================================================================================================*/ 
static void SetState(tUPDiTarget* This, tUPDBank Bank, tUPDiTargetState State)
{
    /* Check if the target type is AOnly */
    if( This->Type == eTargetTypeAOnly)
    {
        /* If the bank is not active, throw an error */
        if( Bank != eUPDiUpdate_BankActive )
        {
            UPDd_ERROR("Cannot access to the Inactive slot of an AOnly target <%s>", This->Name);
        }
        /* Set the state of the only slot in an AOnly target */
        This->pSlots[0].State = State;
    }
    else
    {
        /* Get the slot based on the bank for AB or ABExt targets */
        boolean Slot = UPDUpdateMan_GetSlot(Bank);
        /* both AB and ABExt target have two slots.
           The slot is implemented as a boolean value and used like an index to access related data */
        if( Slot < UPD_AB_SLOT_COUNT )
        {
            /* Set the state of the selected slot */
            This->pSlots[Slot].State = State;
        }
        else
        {
            /* Throw an error if the slot is invalid */
            UPDd_ERROR("Invalid slot");
        }
    }
}

/*==============================================================================================================================================================
* static tUPDBank getUpdatedBank(tUPDiTarget* This)
* Function description : helper function, return the updated bank
*===============================================================================================================================================================*/ 
static tUPDBank getUpdatedBank(tUPDiTarget* This)
{
	tUPDBank Bank;
	if( This->Type != eTargetTypeAOnly)
	{
		 Bank = UPDUpdateMan_GetUPDatedBank();
	}
	else
	{
		Bank = eUPDiUpdate_BankActive;
	}
	return Bank;
}

/*==============================================================================================================================================================
* static tUPDiPartition* getPartition(tUPDiTarget* This,tUPDiPartitionGroup* pGroup, tUPDBank Bank)
* Function description : helper function, return the partion from a given partition group
*===============================================================================================================================================================*/ 
static tUPDiPartition* getPartition(tUPDiTarget* This,tUPDiPartitionGroup* pGroup, tUPDBank Bank)
{
	tUPDiPartition* pPartition = NULL;
	if( This->Type ==eTargetTypeAOnly)
	{
		if( Bank != eUPDiUpdate_BankActive )
		{
			UPDd_ERROR("Cannot access to the Inactive slot of an AOnly target <%s>",This->Name);
		}
		pPartition = pGroup->BankA;
	}
	else
	{
	#if UPDd_HW_PARTITION_SWICTH != STD_ON
		if( UPDUpdateMan_GetSlot(Bank) )
		{
			pPartition = pGroup->BankB;
		}
		else
		{
			pPartition = pGroup->BankA;
		}
	#else
		if( Bank != eUPDiUpdate_BankActive )
		{
			// BankB is always inactive, addresses are switched by HW
			pPartition = pGroup->BankB;
		}
		else
		{
			pPartition = pGroup->BankA;
		}

	#endif
	}
    return pPartition;
}


/*==============================================================================================================================================================
* static void UnDeploy(tUPDiTarget* This, tUPDBank Bank)
* Function description : Change state from eUPDiTarget_InstVerfiedDeployed to eUPDiTarget_InstVerfiedDeployable
* Input arguments : target , hashing contextFbl_Hash
* Return :none
*===============================================================================================================================================================*/ 
void UnDeploy(tUPDiTarget* This, tUPDBank Bank)
{
	tUPDiTargetState State = GetState(This,Bank);
	if( (State == eUPDiTarget_InstVerfiedDeployed ) ||
	    (State == eUPDiTarget_InstVerfiedDeploying)     )
	{
		SetState(This,Bank,eUPDiTarget_InstVerfiedDeployable);
	}
	else if( State == eUPDiTarget_InstVerfiedDeployable )
	{
		// nothing to do, we're already in the right state
	}
	else
	{
		SetState(This,Bank,eUPDiTarget_UninstIdleUndef);
	}
}

/*==============================================================================================================================================================
* static Std_ReturnType UPDTarget_RequestCopyStep(tUPDiTarget* This, tUPDiInstallSession* pSession, boolean opStart)
* Function description : This function shall copy the target from active to inactive
* Input arguments : target , hashing contextFbl_Hash
* Return : E_OK       - verified the hashes successfully
*          E_PENDING  - pending
*          E_NOT_OK   - failed while verifying the hashes
*===============================================================================================================================================================*/ 
static Std_ReturnType UPDTarget_RequestCopyStep(tUPDiTarget* This, tUPDiInstallSession* pSession, boolean opStart)
{
    Std_ReturnType status = E_OK;
	tUPDiTargetRam* pRam=This->pRam;
	if( opStart )
	{
		SetState(This,eUPDiUpdate_BankInactive,eUPDiTarget_UninstCopiyng);
		InitIterator(This);
		UPDd_INFO("Synching target <%s>",This->Name);
	}
	while( (pRam->nextPartitionIndex < This->GroupsCount) && (status == E_OK) )
    {
		tUPDiPartitionGroup* pGroup = &(This->pGroups[pRam->nextPartitionIndex]);
		if( (pRam->nextByte==0) && ( pSession->pWritePartition == NULL) )
		{
			// We are starting a new partition
			status = UPDiSession_StartPartitionUpdate(pSession,pGroup->Name,0,TRUE);
		}

		if( status != E_OK )
		{}
		else if( (pGroup->BankA==NULL) || (pGroup->BankB==NULL) )
		{
			status = E_NOT_OK;
		}
		else if( pGroup->BankA->Size != pGroup->BankB->Size)
		{
			status = E_NOT_OK;
		}
		else if(pRam->nextByte < pGroup->BankA->Size )
		{
			uint32_t size = min(pGroup->BankA->Size - pRam->nextByte, UPDd_LOAD_BUFFER_SIZE);
			status = UPDiSession_CopyNext(pSession,pRam->nextByte,size);

			if( status == E_OK )
			{
				pRam->nextByte+=size;
			}
		}

		if(pRam->nextByte>=pGroup->BankA->Size )
		{
			status = UPDiSession_FinishPartitionUpdate(pSession);
			if( status == E_OK)
			{
				pRam->nextByte =0;
				pRam->nextPartitionIndex++;
			}
		}
    }


	if( status == E_OK)
	{
		// Copy hash from inactive to active
		tUPDHashInfo Hash;
		UPDd_ReadHashFromManifest(GetManifest(This,eUPDiUpdate_BankActive), &Hash);
		UPDd_WriteHashToManifest(GetManifest(This,eUPDiUpdate_BankInactive), &Hash);
		SetState(This,eUPDiUpdate_BankInactive,eUPDiTarget_InstUnVerified_Verfiyng);
		UPDd_INFO("Inactive copy of target:<%s> is synched.",This->Name);
	}
	else if(status!=E_PENDING)
	{
		SetState(This,eUPDiUpdate_BankInactive,eUPDiTarget_UninstIdleUndef);
	}
    return status;
}
/*==============================================================================================================================================================
* static Std_ReturnType UPDTarget_RequestHashingStep(tUPDiTarget* This, boolean IsFirst,tUPDiHashingContext* pHashingContext)
* Function description : This function shall verify the target
* Input arguments : target , hashing contextFbl_Hash
* Return : E_OK       - verified the hashes successfully
*          E_PENDING  - pending
*          E_NOT_OK   - failed while verifying the hashes
*===============================================================================================================================================================*/ 
static Std_ReturnType UPDTarget_RequestHashingStep(tUPDiTarget* This,tUPDiInstallSession* pSession, tUPDBank Bank, boolean opStart)
{
    Std_ReturnType status = E_OK;
	tUPDiTargetRam* pRam=This->pRam;
	tUPDiPartition* pPartition;

	if( opStart)
	{
		InitIterator(This);
		pRam->hashingCycles =0;
	}

    while( (pRam->nextPartitionIndex < This->GroupsCount) && (status == E_OK) )
    {
        tUPDiPartitionGroup* pGroup = &(This->pGroups[pRam->nextPartitionIndex]);
        pPartition = getPartition(This,pGroup, Bank);

        if( pPartition != NULL)
        {
        	if( opStart)
        	{
        		UPDiSession_StartHashing(pSession,This,pPartition->IoAdapter);
        		opStart = FALSE;
        	}
			uint32_t size = min(pPartition->Size-pRam->nextByte, UPDd_LOAD_BUFFER_SIZE);
			status = UPDiSession_Hash(pSession,pPartition,pRam->nextByte,size);

			if( status == E_OK )
			{
				pRam->nextByte+=size;
				if(pRam->nextByte>=pPartition->Size )
				{
					pRam->nextByte =0;
					pRam->nextPartitionIndex++;
				}
			}
        }
        else
        {
        	status = E_NOT_OK;
        }
    }

    if( status == E_OK)
    {
		tUPDiTargetState State = GetState(This,Bank);
		if(State==eUPDiTarget_InstUnVerified_Hashing)
		{
			SetState(This,Bank,eUPDiTarget_InstUnVerified_Hashed);
			status = E_PENDING;
		}
		else if(State==eUPDiTarget_InstUnVerified_Hashed)
		{
			// the hash has been computed, it shall be accessed by calling UPDiSession_ExitHashing()		
			status = E_PENDING;
		}
		else if((State&eUPDiTarget_InstVerfiedMask)==eUPDiTarget_InstVerfied)
		{
			// the target has been verifed alreday
			status = E_OK;
		}
		else if(State==eUPDiTarget_InstUnVerified_Verfiyng)
		{
			tUPDHashInfo Hash;
			tUPDHashInfo GoldenHash;
			status = UPDiSession_ExitHashing(pSession,This,&Hash);
			if( status==E_OK)
			{
				UPDd_ReadHashFromManifest(GetManifest(This,Bank),&GoldenHash);
				// Hashing error need to be confirmed twice.
				// For the confirmation we expect to compute twice the same hash.
				// To limit the RAM requirements, we only keep a short version of the hash.
				// The short version is made of the 4 first bytes.
				uint32_t ShortHash = 0;
				memcpy((void*)&ShortHash,Hash.pHash,min( Hash.HashSize, sizeof(ShortHash)));

				status = E_NOT_OK;
				if( (GoldenHash.HashType!= Hash.HashType) || (GoldenHash.HashSize > Hash.HashSize) )
				{
					status = E_NOT_OK;
					UPDd_ERROR("Expected vs current hash type mismatch");
				}
				else if( memcmp(GoldenHash.pHash,Hash.pHash,GoldenHash.HashSize)==0 )
				{
					status = E_OK;
					SetState(This,Bank,eUPDiTarget_InstVerfiedDeployable);
					pRam->eraseCycles=0;
					UPDd_INFO("Valid hash detected on bank:<%s> of target <%s> ",(Bank==eUPDiUpdate_BankActive)?"Active":"Inactive",This->Name);
					if( pRam->hashingCycles !=0 )
					{
						UPDd_WARNING("Invalid hash suspicion was wrong, hash is valid. Bank:<%s>, target:<%s> ",(Bank==eUPDiUpdate_BankActive)?"Active":"Inactive",This->Name);
					}
				}
				else if((pRam->lastShortHash == ShortHash ) && (pRam->hashingCycles!=0))
				{
					// The hash is wrong but it is identical to the last computation
					// Indeed, we have double confirmed the error.
					status = E_NOT_OK;
					//UPDd_WriteHashToManifest(GetManifest(This,Bank),&Hash);
				}
				else if(pRam->hashingCycles<UPDd_MAX_HASHING_CYCLE)
				{
					// The hash is wrong and if it's not the first try, it is not the same as previous time.
					// We have not reached the maximun number of re-tries, let's hash again
					UPDd_INFO("Invalid hash suspected, hashing restarted to double confirm. Bank:<%s>, target:<%s> ",(Bank==eUPDiUpdate_BankActive)?"Active":"Inactive",This->Name);
					status = E_PENDING;
					UPDiSession_StartHashing(pSession,This,pPartition->IoAdapter);
				}
				else
				{
					// After multiple retries, we have not been able to compute twice the same hash.
					// The test is non-conclusive.
					// At least we know the we're not capable to read properly,  let's return E_NOT_OK.
					UPDd_WARNING("Inconsistent Hash calculation, impossible to read the same hash twice. Bank:<%s>, Target <%s> ",(Bank==eUPDiUpdate_BankActive)?"Active":"Inactive",This->Name);
					status = E_NOT_OK;
					//UPDd_WriteHashToManifest(GetManifest(This,Bank),&Hash);
				}
				pRam->hashingCycles++;
				pRam->lastShortHash = ShortHash;
				InitIterator(This);
			}
		}

		/*if(status==E_OK)
		{
			SetState(This,Bank,eUPDiTarget_InstVerfiedDeployable);
			pRam->eraseCycles=0;
			UPDd_INFO("Valid hash detected on bank:<%s> of target <%s> ",(Bank==eUPDiUpdate_BankActive)?"Active":"Inactive",This->Name);
		}
		else if(status!=E_PENDING)
		{
			UPDd_WARNING("Invalid hash detected on bank:<%s> of target <%s> ",(Bank==eUPDiUpdate_BankActive)?"Active":"Inactive",This->Name);
			SetState(This,Bank,eUPDiTarget_UninstIdleUndef);
		}*/
    }
	if((status!=E_PENDING) && (status!=E_OK))
	{
		SetState(This,Bank,eUPDiTarget_UninstIdleUndef);
	}
    return status;
}
/*===========================================================================================================================================
* Std_ReturnType UPDTarget_RequestEarseStep(tUPDiTarget* This, boolean IsFirst,char* PackageName)
* Function description : This function shall trigger erase operation
* Input arguments : target , package name 
* Return : E_OK       - successful erase operation
*          E_PENDING  - Pending erase operation
*          E_NOT_OK   - erase operation failed
*============================================================================================================================================*/ 
Std_ReturnType UPDTarget_RequestEraseStep(tUPDiTarget* This,tUPDiInstallSession* pSession, boolean opStart,tUPDBank Bank)
{
    Std_ReturnType status = E_OK;
	tUPDiTargetRam* pRam=This->pRam;
	if( opStart )
	{
    	tUPDiTargetState State = GetState(This,Bank);
		InitIterator(This);
		SetState(This,Bank,State=eUPDiTarget_UninstErasing);
		pRam->eraseCycles++;
		UPDd_INFO("Erasing bank:<%s> of target:<%s>",(Bank==eUPDiUpdate_BankActive)?"Active":"Inactive",This->Name);
	}

    while( (pRam->nextPartitionIndex < This->GroupsCount) && (status == E_OK) )
    {
        tUPDiPartitionGroup* pGroup = &(This->pGroups[pRam->nextPartitionIndex]);
        tUPDiPartition* pPartition = getPartition(This,pGroup, Bank);

        if( pPartition == NULL)
        {
        	status = E_NOT_OK;
        }
        else
        {
        	status = UPDiSession_ErasePartition(pSession,pPartition);
			if( status == E_OK )
			{
				pRam->nextPartitionIndex++;
			}
        }
    }

	if(status==E_OK)
	{
		SetState(This,Bank,eUPDiTarget_UninstIdleEmpty);
	}
	else if (status!=E_PENDING)
	{
		SetState(This,Bank,eUPDiTarget_UninstIdleUndef);
	}

    return status;
}
//=====================================================================================================================
//  User functions
//=====================================================================================================================



/*===========================================================================================================================================
* Std_ReturnType UPDTarget_CopyToInactive(tUPDiTarget* This)
* Function description : This function copy the active to the inactive bank
* Input arguments      : target , package name
* Return               : E_OK       - erase request accepted
*                        E_PENDING  - Pending
*============================================================================================================================================*/
Std_ReturnType UPDTarget_CopyToInactive(tUPDiTarget* This)
{
    Std_ReturnType status = E_NOT_OK;
    if( !IsInvalid(This) )
    {
    	tUPDiTargetState InactiveState = GetState(This,eUPDiUpdate_BankInactive); // return eUPDiTarget_Invalid if type is A-Only
    	tUPDiTargetState ActiveState = GetState(This,eUPDiUpdate_BankActive);
		tUPDiTargetRam* pRam=This->pRam;

		switch( InactiveState)
		{
			case(eUPDiTarget_UninstIdleEmpty):
				if((ActiveState & eUPDiTarget_InstVerfiedMask) == eUPDiTarget_InstVerfied)
				{
					SetState(This,eUPDiUpdate_BankInactive,InactiveState=eUPDiTarget_UninstCopiyng);
					status = E_PENDING;
				}
				else if(ActiveState == eUPDiTarget_InstUnVerified_Verfiyng)
				{
					status = E_PENDING;
				}
				else
				{
					UPDd_WARNING("Cannot copy the active to inactive, active is not verified");
					status = E_NOT_OK;
				}
			break;

			case(eUPDiTarget_UninstIdleUndef):
				if(pRam->eraseCycles>=UPDd_MAX_ERASE_CYCLE)
				{
					// we cannot sync because too much erase tries have been done.
					status = E_NOT_OK;
				}
				else
				{
					// erase will automatically start
					status = E_PENDING;
				}
				break;


			case(eUPDiTarget_UninstErasing):
			case(eUPDiTarget_UninstCopiyng):
			case(eUPDiTarget_InstUnVerified_Verfiyng):
				status = E_PENDING;
			break;

			case(eUPDiTarget_InstVerfiedDeployable):
				tUPDHashInfo ActiveHash,InactiveHash;
				UPDd_ReadHashFromManifest(GetManifest(This,eUPDiUpdate_BankInactive),&ActiveHash);
				UPDd_ReadHashFromManifest(GetManifest(This,eUPDiUpdate_BankActive),&InactiveHash);
				if( (ActiveHash.HashType== InactiveHash.HashType) && (ActiveHash.HashSize== InactiveHash.HashSize) )
				{
					if( memcmp(ActiveHash.pHash,InactiveHash.pHash,ActiveHash.HashSize)==0 )
					{
						status = E_OK;
					}
				}
			break;

			case(eUPDiTarget_Invalid):
				// nothing to copy, target is A-Only
				status = E_OK;
			break;

			default:
				// By default status is E_NOT_OK
			break;
		}
		UPDInstallMan_PorcessTargets();// wake-up the processing task
    }
    return status;
}
/*=====================================================================================================================
* Private function  : tUPDdManifest*   UPDTarget_GetManifest(tUPDiTarget* This, tUPDBank Bank)
* Function description : Returns the manifest information of the bank 
* Input argument : tUPDiTarget* , tUPDBank
* Return : tUPDdManifest*   - Return the manifest info 
*=====================================================================================================================*/
tUPDdManifest*   UPDTarget_GetManifest(tUPDiTarget* This, tUPDBank Bank)
{
	tUPDdManifest* pManifest=NULL;
	if( !IsInvalid(This))
	{
		pManifest = GetManifest(This, Bank);
	}
   return pManifest;
}

/*=====================================================================================================================
* tUPDiPartition*  UPDTarget_GetUpdatedPartition(tUPDiTarget* This, const char* PartitionName)
* Function description : This function shall returns the partition info of the target
* Return : Returns the partition info 
* Function scope : private method
*=====================================================================================================================*/
tUPDiPartition*  UPDTarget_GetPartition(tUPDiTarget* This, const char* PartitionName, boolean read)
{
    tUPDiPartition* pPartition = NULL;
	tUPDBank Bank= getUpdatedBank(This);
	if( read )
	{
		if( (Bank == eUPDiUpdate_BankInactive) && (This->Type!=eTargetTypeAOnly ) )
		{
			Bank= eUPDiUpdate_BankActive;
		}
		else
		{
			// reading from Inactive chain is not possible.
			return NULL;
		}
	}
	for (uint16_t idx = 0; idx < This->GroupsCount; idx++)
	{
		tUPDiPartitionGroup* pGroup = &(This->pGroups[idx]);
		if( strncmp(PartitionName, pGroup->Name, UPDd_MAX_PACKAGE_NAME_SIZE)==0)
		{
			pPartition = getPartition(This,pGroup, Bank);
			break;
		}
	}

    return pPartition;
}

/*=====================================================================================================================
* Triggers functions
* =====================================================================================================================*/

/*===========================================================================================================================================
* Private function : Std_ReturnType  UPDTarget_InstallStart(tUPDiTarget* This, struct sUPDInstallSession* Session)
* Function description : This function shall start the requested download service
* Input arguments : target,session
* Return : E_OK
* E_OK - requested start download service completed successfully
*============================================================================================================================================*/ 
Std_ReturnType  UPDTarget_InstallStart(tUPDiTarget* This, struct sUPDiInstallSession* pSession)
{
    Std_ReturnType status = E_NOT_OK;
    if( !IsInvalid(This) )
    {
		//don't need to check the state of the target, if it's not erased, it'll be during the update.
    	tUPDBank Bank = getUpdatedBank(This);
		SetState(This,Bank,eUPDiTarget_UninstInstalling);
		UPDd_INFO("Installing target <%s>",This->Name);
		status = E_OK;
    }
    return status;
}
/*===========================================================================================================================================
* Public function : Std_ReturnType  UPDTarget_InstallExit(tUPDiTarget* This, struct sUPDInstallSession* Session)
* Function description : This function shall exit the last happened downloadservice
* E_OK - Successful exit 
* E_PENDING - pending
* E_NOT_OK  - Error while exiting
*============================================================================================================================================*/
Std_ReturnType  UPDTarget_InstallExit(tUPDiTarget* This, struct sUPDiInstallSession* Session)
{
    Std_ReturnType status = E_NOT_OK;
    if( !IsInvalid(This) )
    {
    	tUPDBank Bank = getUpdatedBank(This);
    	tUPDiTargetState State = GetState(This,Bank);

    	if( State == eUPDiTarget_UninstInstalling)
		{
			 /*Set the target state as installing state*/
#if UPDd_ENABLE_AUTO_HASH==STD_OFF
    		SetState(This,Bank,eUPDiTarget_InstUnVerified_Verfiable);
#else
    		SetState(This,Bank,eUPDiTarget_InstUnVerified_Hashing);
#endif
    		status = E_OK;
		}
    	else
    	{
    		UPDd_ERROR("Unexpected UPDTarget_InstallExit() call");
    		SetState(This,Bank,eUPDiTarget_UninstIdleUndef);
    	}
    }
    return status;
}

/*===========================================================================================================================================
* Public function : Std_ReturnType  UPDTarget_InstallExit(tUPDiTarget* This, struct sUPDInstallSession* Session)
* Function description : This function shall exit the last happened downloadservice
* E_OK - Successful exit
* E_PENDING - pending
* E_NOT_OK  - Error while exiting
*============================================================================================================================================*/
Std_ReturnType UPDTarget_Verify(tUPDiTarget* This, tUPDiInstallSession* pSession, tUPDHashInfo* pGoldenHash)
{
    Std_ReturnType status = E_NOT_OK;
    if( !IsInvalid(This) )
    {
    	tUPDBank Bank = getUpdatedBank(This);
    	tUPDiTargetState State = GetState(This,Bank);
		switch( State)
		{
			case(eUPDiTarget_InstUnVerified_Hashing):
				//UPDd_ReadHashFromManifest(GetManifest(This,Bank),&Hash);
				if( (pGoldenHash->HashType!= UPDd_HASH_TYPE) || (pGoldenHash->HashSize !=UPDd_HASH_SIZE) )
				{
					status = E_NOT_OK;
					UPDd_ERROR("Requested Hash type and size do not match the auto hashing settings");
					break;
				}
				// else continue with next case
			case(eUPDiTarget_InstUnVerified_Verfiable):
				 /*Record the hash and start verifying*/
				UPDd_WriteHashToManifest(GetManifest(This,Bank),pGoldenHash);
				SetState(This,Bank,eUPDiTarget_InstUnVerified_Verfiyng);
				status = E_PENDING;
			break;

			case(eUPDiTarget_InstUnVerified_Hashed):
				tUPDHashInfo Hash;
				UPDd_ReadHashFromManifest(GetManifest(This,Bank),&Hash);
				if( (pGoldenHash->HashType!= Hash.HashType) || (pGoldenHash->HashSize<Hash.HashSize) )
				{
					status = E_NOT_OK;
					UPDd_ERROR("Expected vs current hash type mismatch");
				}
				else if( memcmp(pGoldenHash->pHash,Hash.pHash,Hash.HashSize)==0 )
				{
					status = E_OK;
					SetState(This,Bank,eUPDiTarget_InstVerfiedDeployable);
				}			
				else
				{
					status = E_NOT_OK;
					SetState(This,Bank,eUPDiTarget_UninstIdleUndef);
				}			
				break;

			case(eUPDiTarget_InstUnVerified_Verfiyng):
				status = E_PENDING;
			break;

			case(eUPDiTarget_InstVerfiedDeployable):
				status = E_OK;
			break;

			default:
				// By default status is E_NOT_OK
			break;
		}
    }
    return status;
}

/*===========================================================================================================================================
* Public function : UPDTarget_GetHash(tUPDiTarget* this, tUPDHashInfo* pHash, tUPDBank Bank)
* Function description : Computes and return the hash of of the target
* E_OK - Successful exit
* E_PENDING - job is pending, call the same function later with the same parameters to get the status
* E_NOT_OK  - Error while exiting
*============================================================================================================================================*/
Std_ReturnType UPDTarget_GetHash(tUPDiTarget* This, tUPDiInstallSession* pSession, tUPDHashInfo* pHash, boolean reHash)
{
   	Std_ReturnType status = E_NOT_OK;
    if( !IsInvalid(This) )
    {
    	tUPDBank Bank = getUpdatedBank(This);
    	tUPDiTargetState State = GetState(This,Bank);
		switch( State)
		{
			case(eUPDiTarget_InstUnVerified_Verfiable):
				SetState(This,Bank,eUPDiTarget_InstUnVerified_Hashing);				
				status = E_PENDING;
			break;
			case(eUPDiTarget_InstUnVerified_Hashing):
				status = E_PENDING;		
			break;
			case(eUPDiTarget_InstUnVerified_Hashed):
				if( reHash )
				{
					SetState(This,Bank,eUPDiTarget_InstUnVerified_Hashing);				
					status = E_PENDING;
				}
				else
				{
					status = UPDiSession_ExitHashing(pSession,This,pHash);
					UPDd_WriteHashToManifest(GetManifest(This,Bank),pHash);
				}
				break;
			default:
				// By default status is E_NOT_OK
			break;
		}
    }
    return status;
}

/*===========================================================================================================================================
* Public function : Std_ReturnType UPDTarget_Inspect(tUPDiTarget* This, boolean Slot)
* Function description : Verify the hash of the given slot
* E_OK - Successful exit
* E_PENDING - pending
* E_NOT_OK  - Error while exiting
*============================================================================================================================================*/
Std_ReturnType UPDTarget_Inspect(tUPDiTarget* This, tUPDBank Bank)
{
    Std_ReturnType status = E_NOT_OK;
    if( !IsInvalid(This) )
    {
    	tUPDiTargetState State = GetState(This,Bank);
		switch( State)
		{
			case(eUPDiTarget_InstVerfiedDeployable):
			case(eUPDiTarget_InstVerfiedDeploying):
			case(eUPDiTarget_InstVerfiedDeployed):
			 /*Record the hash and start verifying*/
			SetState(This,Bank,eUPDiTarget_InstUnVerified_Verfiyng);
			status = E_OK;
			break;

			case(eUPDiTarget_InstUnVerified_Verfiyng):
			status = E_OK;
			break;

			default:
				break;
			// By default status is E_NOT_OK
		}
		UPDInstallMan_PorcessTargets();// wake-up the processing task
    }
    return status;
}

/*===========================================================================================================================================
* Public function : Std_ReturnType UPDTarget_Deploy(tUPDiTarget* This)
* Function description : Deploy the slot requested
* E_OK - Successful exit
* E_PENDING - pending
* E_NOT_OK  - Error while exiting
*============================================================================================================================================*/
Std_ReturnType UPDTarget_Deploy(tUPDiTarget* This)
{
    Std_ReturnType status = E_NOT_OK;
    if( !IsInvalid(This) )
    {
    	tUPDiTargetState State = GetState(This,eUPDiUpdate_BankActive);
    	if( This->Type == eTargetTypeAOnly)
    	{
    		// nothing to do, target is AOnly
    		status = E_OK;
    	}
    	else if( State == eUPDiTarget_InstVerfiedDeployable )
		{
			// We are ready to deploy
    		// TODO: we assume here that no external partition need to be deployed
    		SetState(This,eUPDiUpdate_BankActive,eUPDiTarget_InstVerfiedDeployed);
    		UnDeploy(This,eUPDiUpdate_BankInactive);
    		status = E_OK;
		}
    	else if( State == eUPDiTarget_InstVerfiedDeploying )
		{
    	    status = E_PENDING;
		}
    	else if( State == eUPDiTarget_InstVerfiedDeployed )
    	{
    	    status = E_OK;
    	}
    }
    return status;
}

//=====================================================================================================================
//  Management functions
//=====================================================================================================================
/*=====================================================================================================================
* void static char* ValidateConfiguration(tUPDiTarget* This)
* Function description : This function validate the target configuration, it returns "" if the validation passed
* Return : "" if the validation passed, error string in other cases
*=====================================================================================================================*/
static char* ValidateConfiguration(tUPDiTarget* This)
{
	char* error="";
	if(  IsInvalid(This))
	{
		error = "<This> pointer is NULL";
	}
	else if( This->GroupsCount == 0)
	{
		error="UPDTarget_Init() GroupsCount cannot be 0";
	}
	else if( (This->GroupsCount == 1) && (strcmp(This->pGroups[0].Name,This->Name)!=0) )
	{
		error= "When a target is made of a single partition group, the group & target shall have a same name";
	}
	else if( This->SizeOfSlots != ( (This->Type==eTargetTypeAOnly) ? sizeof(tUPDiTargetSlot) : UPD_AB_SLOT_COUNT*sizeof(tUPDiTargetSlot)) )
	{
		error= "size of slots is inconsistent  with the target type";
	}
	else
	{
		for (uint16_t idx = 0; idx < This->GroupsCount; idx++)
		{
			tUPDiPartitionGroup* pGroup = &(This->pGroups[idx]);
			if( pGroup->BankA ==NULL )
			{
				error = "partition A cannot be NULL";
			}
			else
			{
				if( pGroup->BankB )
				{
					if( This->Type == eTargetTypeAOnly)
					{
						error= "partition B is not required for Target types AB and ABExt";
					}
					else if(pGroup->BankA->Size != pGroup->BankB->Size )
					{
						error= "partition A & B don't have the same size";
					}
				}
				else
				{
					if( This->Type != eTargetTypeAOnly)
					{
						error= "partition B is required for Target types AB and ABExt";
					}
				}
				if( pGroup->BankExt )
				{
					if( This->Type != eTargetTypeABExt)
					{
						error= "partition Ext is not required for Target types A and AB";
					}
					else if(pGroup->BankA->Size != pGroup->BankExt->Size )
					{
						error ="partition A & Ext don't have the same size";
					}
				}
				else
				{
					if( This->Type == eTargetTypeABExt)
					{
						error= "partition Ext is required for Target types ABExt";
					}
				}
			}
		}
	}
	return error;
}

/*=====================================================================================================================
* void void UPDTarget_Init(tUPDiTarget* This)
* Function description : This function shall initialize the target
* Return : void
* Functon type : Private function
*=====================================================================================================================*/
void UPDTarget_Init(tUPDiTarget* This)
{
	if( ! IsInvalid(This))
	{
		tUPDiTargetRam* pRam=This->pRam;
		memset(pRam,0,sizeof(*pRam));
		InitIterator(This);

		/*set the idle state for the A and B group partition of target*/
		This->pSlots[0].State = eUPDiTarget_UninstIdleUndef;
		memset(&(This->pSlots[0].Manifest), 0xFF, sizeof(This->pSlots[0].Manifest));
		if( This->Type != eTargetTypeAOnly )
		{
			This->pSlots[1].State = eUPDiTarget_UninstIdleUndef;
			memset(&(This->pSlots[1].Manifest), 0xFF, sizeof(This->pSlots[1].Manifest));
		}

		char* err = ValidateConfiguration(This);
		if(err[0])
		{
			UPDd_WARNING("UPDTarget_Init detected an unproper configuration of <%s> : %s",This->Name, err );
	    }
	}
}

/*=====================================================================================================================
* tUPDiTargetState UPDTarget_GetState(tUPDiTarget* This)
* Function description : This function shall return target state
* Return type : tUPDiTargetState
* Functon type : Private function
*=====================================================================================================================*/
tUPDiTargetState UPDTarget_GetState(tUPDiTarget* This,tUPDBank Bank)
{
    tUPDiTargetState State = eUPDiTarget_Invalid;
	if( !IsInvalid(This))
	{
		State = GetState(This, Bank );
    }
    return State;
}

/*=====================================================================================================================
* tUPDiTargetState UPDTarget_Deserialize(tUPDiTarget* This, tUPDStream* pStream)
* Function description : Read the target state from the stream
* Return type : Std_ReturnType
* Functon type : Public function
*=====================================================================================================================*/
Std_ReturnType UPDTarget_Deserialize(tUPDiTarget* This, tUPDStream* pStream)
{
	Std_ReturnType status = E_NOT_OK;
	if( !IsInvalid(This) && pStream)
	{
		uint16_t LastSizeOfSlots;
		UPDi_DESERIALIZE(pStream, LastSizeOfSlots, ((uint16_t)-1) );
		if( LastSizeOfSlots == This->SizeOfSlots)
		{
			UPDi_Deserialize(pStream, (uint8_t*)(This->pSlots), This->SizeOfSlots );
			status = E_OK;
		}
		else if( LastSizeOfSlots != ((uint16_t)-1) )
		{
			// let's ignore the data
			pStream->size -= LastSizeOfSlots;
			//pStream->data += LastSizeOfSlots;
			UPDd_WARNING("UPDTarget_Deserialize() No data found in NVM for slots of <%s>",This->Name);
		}
	}
    return status;
}

/*=====================================================================================================================
* tUPDiTargetState UPDTarget_Serialize(tUPDiTarget* This, tUPDStream* pStream)
* Function description : Write the target state to the stream
* Return type : Std_ReturnType
* Functon type : Public function
*=====================================================================================================================*/
Std_ReturnType UPDTarget_Serialize(tUPDiTarget* This, tUPDStream* pStream)
{
	Std_ReturnType status = E_NOT_OK;
	if( !IsInvalid(This) && pStream)
	{
		UPDi_SERIALIZE(pStream, This->SizeOfSlots);
		UPDi_Serialize(pStream,  (uint8_t*)(This->pSlots), This->SizeOfSlots);
		status = E_OK;
    }
    return status;
}

/*=====================================================================================================================
* uint8 UPDTarget_GetPartitionId(tUPDiTarget* This,tUPDiPartition* pPartition)
* Function description : Get the ID associated to a partition pointer
* Return type : ID
* Function type : Public function
*=====================================================================================================================*/
uint8_t UPDTarget_GetPartitionId(tUPDiTarget* This,tUPDiPartition* pPartition)
{
	uint8_t pId =-1;
	if( (This==NULL) || (pPartition==NULL))
	{
	}
	else if(This->GroupsCount>MAX_GROUP_COUNT)
	{
		UPDd_ERROR("The number of partition groups cannot exceed 64.");
	}
	else
	{
		for( uint8_t gId=0;gId<This->GroupsCount;gId++)
		{
			tUPDiPartitionGroup* pGroup = &This->pGroups[gId];
			if(pGroup->BankA == pPartition)
			{
				pId = gId + BANKA_PARTITION_ID;
			}
			else if(pGroup->BankB == pPartition)
			{
				pId = gId + BANKB_PARTITION_ID;
			}
			else if(pGroup->BankExt == pPartition)
			{
				pId = gId;
			}
		}
	}
	return pId;
}

/*=====================================================================================================================
* tUPDiPartition*	 UPDTarget_GetPartitionById(tUPDiTarget* This,uint8 pId)
* Function description : Get the pointer pointer associated to a partition ID
* Return type : tUPDiPartition*
* Function type : Public function
*=====================================================================================================================*/
tUPDiPartition*	 UPDTarget_GetPartitionById(tUPDiTarget* This,uint8_t pId)
{
	tUPDiPartition* pPartition=NULL;
	if(This!=NULL)
	{
		uint8_t gId= pId & GROUP_MASK;
		uint8_t PartitionType = pId - gId;
		if ( gId>=This->GroupsCount )
		{}
		else if(PartitionType==BANKA_PARTITION_ID)
		{
			pPartition =This->pGroups[gId].BankA;
		}
		else if(PartitionType==BANKB_PARTITION_ID)
		{
			pPartition =This->pGroups[gId].BankB;
		}
		else if(PartitionType==BANKEXT_PARTITION_ID)
		{
			pPartition =This->pGroups[gId].BankExt;
		}
	}
	return pPartition;
}

/*=====================================================================================================================
* tUPDiPartition*	 void UPDTarget_Suspend(tUPDiTarget* This)
* Function description : Suspend target operations
* Return type : none
* Function type : Public function
*=====================================================================================================================*/
void UPDTarget_Suspend(tUPDiTarget* This)
{
	if( ! IsInvalid(This) )
	{
		tUPDBank Bank = getUpdatedBank(This);
    	tUPDiTargetState State = GetState(This,Bank);
		if( (State == eUPDiTarget_UninstErasing) ||
			(State == eUPDiTarget_UninstCopiyng)    )
		{
			SetState(This,Bank,eUPDiTarget_UninstIdleUndef);
		}
	}
}
/*===========================================================================================================================================
* Std_ReturnType UPDTarget_GetNextOperation(tUPDiTarget* This)
* Function description : This function the next operation that the target requires
* Input arguments      : target
* Return               : operation
*============================================================================================================================================*/
tUPDiOpType    UPDTarget_GetNextOperation(tUPDiTarget* This,tUPDUpdateState UpdateState)
{
	tUPDiOpType op = eUPDOpNone;
    if( !IsInvalid(This) )
    {
		tUPDiTargetRam* pRam=This->pRam;
    	tUPDiTargetState ActiveState = GetState(This,eUPDiUpdate_BankActive);
    	tUPDiTargetState InactiveState =  GetState(This,eUPDiUpdate_BankInactive); // return eUPDiTarget_Invalid if type is AOnly

    	if( ActiveState==eUPDiTarget_UninstErasing )
    	{
		    op = eUPDOpErasingActive;
    	}
    	else if((ActiveState==eUPDiTarget_InstUnVerified_Verfiyng) || 
				(ActiveState==eUPDiTarget_InstUnVerified_Hashing ) || 
				(ActiveState==eUPDiTarget_InstUnVerified_Hashed  )    )
    	{
		    op = eUPDOpHashingActive;
    	}
    	else if((InactiveState==eUPDiTarget_UninstIdleUndef) && (pRam->eraseCycles<UPDd_MAX_ERASE_CYCLE) )
    	{
		    op = eUPDOpErasingInactive;
    	}
    	else if(InactiveState==eUPDiTarget_UninstErasing)
    	{
		    op = eUPDOpErasingInactive;
    	}
    	else if((InactiveState==eUPDiTarget_InstUnVerified_Verfiyng) || 
				(InactiveState==eUPDiTarget_InstUnVerified_Hashing ) || 
				(InactiveState==eUPDiTarget_InstUnVerified_Hashed  )    )
    	{
		    op = eUPDOpHashingInactive;
    	}
#ifdef UPDd_AUTO_SYNCH
    	else if( (InactiveState==eUPDiTarget_UninstIdleEmpty) &&
    			 ((ActiveState & eUPDiTarget_InstVerfiedMask) == eUPDiTarget_InstVerfied) &&
				 (UpdateState != eUPDiUpdate_Updating))
    	{
		    op = eUPDOpCopyng;
    	}
#endif
    	else if(InactiveState==eUPDiTarget_UninstCopiyng)
    	{
		    op = eUPDOpCopyng;
    	}
    	else
    	{
    		op = eUPDOpNone;
    	}


    }
    return op;
}

/*===========================================================================================================================================
* Std_ReturnType UPDTarget_ProcessIO(ttUPDiTarget* This, tUPDiInstallSession* pSession, boolean noSynch, boolean restart)
* Function description : This function implements the states of state machine target requesting IO operations.
* Input arguments      : target , Sesssion
* 						 noSynch : indicate is synching is permitted, for example during update synching may be disabled
* 						 initHashingContext: indicate that the hashing context as been reused and have been invalidated
* Return               : E_OK       - No IO operation pending
*                        E_PENDING  - Some operations pending
*                        E_NOT_OK   - Some operations pending
*============================================================================================================================================*/
Std_ReturnType UPDTarget_ProcessIO(tUPDiTarget* This, tUPDiInstallSession* pSession, tUPDiOpType operation, boolean opStart)
{
	Std_ReturnType status = E_NOT_OK;
	if( !IsInvalid(This) )
	{
		// Let's dispatch the call according the operation required
		switch(operation)
		{
			case(eUPDOpErasingActive):
				status = UPDTarget_RequestEraseStep(This,pSession,opStart,eUPDiUpdate_BankActive);
			break;
			case(eUPDOpErasingInactive):
				status = UPDTarget_RequestEraseStep(This,pSession,opStart,eUPDiUpdate_BankInactive);
			break;
			case(eUPDOpHashingActive):
				status = UPDTarget_RequestHashingStep(This,pSession, eUPDiUpdate_BankActive,opStart);
			break;
			case(eUPDOpHashingInactive):
				status = UPDTarget_RequestHashingStep(This,pSession, eUPDiUpdate_BankInactive,opStart);
			break;
			case(eUPDOpCopyng):
				status = UPDTarget_RequestCopyStep( This, pSession,opStart);
			break;
			default:
				UPDd_ERROR("UPDTarget_ProcessIO() Unexpected operation");
			break;
		}
    }
    return status;
}

/*===========================================================================================================================================
* Std_ReturnType UPDTarget_Invalidate(tUPDiTarget* this,tUPDBank Bank)
* Function description : This function invalidate the target (makes its state  undefined)
* Return               : E_OK       - target invalidated
*============================================================================================================================================*/
Std_ReturnType UPDTarget_Invalidate(tUPDiTarget* This, tUPDBank Bank)
{
	Std_ReturnType status = E_NOT_OK;
	if( !IsInvalid(This) )
	{
		SetState(This,Bank,eUPDiTarget_UninstIdleUndef);
		status = E_OK;
	}
	return status;
}
