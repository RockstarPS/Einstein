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
#include "UPDd.h"
#include "UPD_IUpdate.h"
#include "UPD_IBootControl.h"
#include "UPDi_Target.h"


//=====================================================================================================================
/* CONSTANTS & TYPES */
//=====================================================================================================================
//=====================================================================================================================
//  Static Variables
//=====================================================================================================================
static tUPDBank UpdatedBank; // defined to which bank is the update related (active/inactive)
static uint8_t  ActiveSlot; // defined to which bank is the update related (active/inactive)
static tUPDUpdateState UpdateState;
static uint16_t HoldTimeout;

//=====================================================================================================================
//  Private Functions
//=====================================================================================================================
static void DeployAllTargets(void)
{
	uint16_t  iTarget,iTargetCount;
	iTargetCount = UPDi_GetTargetCount();
	for(iTarget=0; iTarget<iTargetCount; iTarget++)
	{
		tUPDiTarget* pTarget = UPDi_GetTarget(iTarget);
		UPDTarget_Deploy(pTarget);
	}
}

static void InvalidateInactivesTargets(void)
{
	uint16_t  iTarget,iTargetCount;
	iTargetCount = UPDi_GetTargetCount();
	for(iTarget=0; iTarget<iTargetCount; iTarget++)
	{
		tUPDiTarget* pTarget = UPDi_GetTarget(iTarget);
		if( pTarget->Type != eTargetTypeAOnly)
		{
			UPDTarget_Invalidate(pTarget, eUPDiUpdate_BankInactive);
		}
	}
}

/*=====================================================================================================================
* Private function  : Std_ReturnType BankVerfiedOk(tUPDBank Bank, boolean checkAOnly)
* Return : E_OK if all Targets are Verified, when checkAOnly is set the argument Bank shall be Active
* Return : E_PENDING if one Target is under verification
* Return : E_NOT_OK if other cases
*=====================================================================================================================*/
static Std_ReturnType BankVerfiedOk(tUPDBank Bank, boolean checkAOnly)
{
    Std_ReturnType status = E_OK;
    uint16_t  iTarget,iTargetCount;
    iTargetCount = UPDi_GetTargetCount();
    for(iTarget=0; iTarget<iTargetCount; iTarget++)
    {
    	tUPDiTarget* pTarget = UPDi_GetTarget(iTarget);
    	if( ((checkAOnly == FALSE) && (pTarget->Type!=eTargetTypeAOnly)) ||
    	    ((checkAOnly == TRUE)  && (pTarget->Type==eTargetTypeAOnly))    )
    	{
			tUPDiTargetState state = UPDTarget_GetState(pTarget, Bank);
			if( (state & eUPDiTarget_InstVerfiedMask) == eUPDiTarget_InstVerfied )
			{
				// OK, it's verified keep status unchanged ( OK initially)
			}
			else if( state == eUPDiTarget_InstUnVerified_Verfiyng )
			{
				status = E_PENDING;
			}
			else if( state == eUPDiTarget_Invalid )
			{
				// This target is A-Only, inactive state is considered as always OK
				status = E_OK; // TODO EBX : we should not touch status here
			}
			else
			{
				status = E_NOT_OK;
				break; // no need to continue
			}
    	}
    }
	return status;
}

/*=====================================================================================================================
* Private function  : Std_ReturnType InactiveBankSafelyUpdatable(void)
* Return : E_OK if inactive chain can be updated
* Return : E_PENDING if one Target is under verification
* Return : E_NOT_OK if other cases
*=====================================================================================================================*/
static Std_ReturnType InactiveBankSafelyUpdatable(void)
{
	Std_ReturnType status = BankVerfiedOk(eUPDiUpdate_BankInactive,FALSE);
	if( status == E_OK )
	{
		// Inactive bank is valid, the requested update may break it
		// Let's authorize the update only if Active bank is valid
		status = BankVerfiedOk(eUPDiUpdate_BankActive,FALSE);
	}
	else if( status != E_PENDING )
	{
		// Inactive bank is already invalid, Updating it cannot break it further
		status = E_OK;
	}

	return status;
}

//=====================================================================================================================
//  Update interface Functions
//=====================================================================================================================


/*=====================================================================================================================
* Private function  : Std_ReturnType     UPDUpdateMan_StartUPDate(tUPDBank Bank)
* Function description : Set the state from IDLE to Updating
* Input argument :tUPDBank - Bank info
* Return : E_OK and E_NOT_OK
* Developer : sananth2
*=====================================================================================================================*/
Std_ReturnType  UPDUpdateMan_StartUPDate(tUPDBank Bank) 
{
    Std_ReturnType status = E_NOT_OK;
    boolean ExpectedSlot;

	if(	(eUPDiUpdate_BankActive == Bank) && (eUPDiMode_App == oUPDCdd.Mode ))
	{
    	// Active bank cannot be updated in Application mode
    	status = E_NOT_OK;
    	UPDd_ERROR("UPDUpdateMan_StartUPDate() Active bank cannot be updated in Application mode");
	}
    else if( UpdateState == eUPDiUpdate_Idle_Booting )
    {
    	// let's wait the boot status before authorizing a new update
    	status = E_PENDING;
    }
    else if ((UpdateState & eUPDiUpdate_Idle_Mask) !=  eUPDiUpdate_Idle )
    {
    	// it's not possible to start a new update before the end of the previous
    	status = E_NOT_OK;
    	UPDd_ERROR("UPDUpdateMan_StartUPDate() Cannot start a new session before finishing the previous");
    }
    else if( (status = UPD_IBootControl_GetBootSlot(&ActiveSlot, &ExpectedSlot)) != E_OK )
    {
    	// boot slot is unknown or cannot be read
    	UPDd_ERROR("UPDUpdateMan_StartUPDate() actual boot slot is unknown or cannot be read");
    }
#ifdef UPDd_UPDATE_ONCE_ACTIVE_CHAIN_VERIFIED
    else if ((eUPDiUpdate_BankInactive == Bank) && ((status=InactiveBankSafelyUpdatable())!=E_OK)  )
    {
    	// The active chain is not verified OK
    	// Starting the update would invalidate the inactive chain,
    	// both chain would be invalid
    	// Note the ActiveChainVerfiedOk() may return E_PENDING, the return is propagated to UPDUpdateMan_StartUPDate()
    }
#endif
    else
    {
    	/*boot control interface shall be used here to get the state of the bank*/
        /*UpdateCdd is in reprogramming mode and set the status as idle*/
        UpdatedBank = Bank;
        UpdateState = eUPDiUpdate_Updating;
        if(eUPDiUpdate_BankActive == Bank)
        {
        	// The update is for active bank, we need to invalidate the application
    		status = UPD_IBootControl_SetAppValidity(FALSE);
        }
        else
        {
            status = E_OK;
        }
        UPDd_TriggerNvmWrite();
    }
    return status;
}

/*=====================================================================================================================
* Public function  : Std_ReturnType UPDUpdateMan_Validate(void)
* Function description : This function Make sure that the updated chain is ready for activation
* Input argument : void
* Return : Std_ReturnType
*=====================================================================================================================*/
Std_ReturnType UPDUpdateMan_Validate(void)
{
	Std_ReturnType status = E_NOT_OK;
    if( (eUPDiUpdate_Updating   != UpdateState) &&
        (eUPDiUpdate_Validation != UpdateState) &&
        (eUPDiUpdate_Validated  != UpdateState)    )
    {
    	// Validate cannot be called on that state
    }
    else
    {
    	// let's verify that the updated bank is properly verified
    	Std_ReturnType statusAB = BankVerfiedOk(UpdatedBank,FALSE);
    	Std_ReturnType statusAOnly = BankVerfiedOk(eUPDiUpdate_BankActive,TRUE);

		if( (statusAB == E_OK) && (statusAOnly == E_OK) )
		{
	    	// updated bank is properly verified
			// Custom validation allow to implement project custom condition
			// Typical,
			// - Verifying Secure boot signatures of the inactive chain
			// - Verifying dependencies between targets
			status = UPDd_CustomValidation();
		}


		if( (statusAB == E_PENDING) || (statusAOnly == E_PENDING)  )
		{
			UpdateState = eUPDiUpdate_Validation;
	        UPDd_TriggerNvmWrite();
	        status = E_PENDING;
		}
		else if( status == E_OK )
		{
			UpdateState = eUPDiUpdate_Validated;
	        UPDd_TriggerNvmWrite();
		}
		else
		{
			UPDUpdateMan_Reset();
		}
    }

	return status;
}

/*=====================================================================================================================
* Public function  : Std_ReturnType UPDUpdateMan_Activate(void)
* Function description : This function intend to activate the updated chain
* Input argumnet : void
* Return : tUPDUpdateState
* Developer : sananth2
*=====================================================================================================================*/
Std_ReturnType     UPDUpdateMan_Activate(void)
{
	Std_ReturnType status = E_NOT_OK;

	// Verify the Validation Status or state
	Std_ReturnType ValidationStatus=E_NOT_OK;
    if( (eUPDiUpdate_Updating   == UpdateState) ||
        (eUPDiUpdate_Validation == UpdateState)  )
    {
    	ValidationStatus = UPDUpdateMan_Validate();
    }
    else if(eUPDiUpdate_Validated  == UpdateState)
    {
    	ValidationStatus = E_OK;
    }

    if(  E_OK == ValidationStatus )
    {
    	if( eUPDiUpdate_BankActive == UpdatedBank )
    	{
    		// Update was on the active chain
    		status = UPD_IBootControl_SetAppValidity(TRUE);
    		if( status == E_OK )
    		{
    			UpdateState = eUPDiUpdate_Idle_InspectingAndSynching;
    			UpdatedBank = eUPDiUpdate_BankInactive;// UpdatedBank shall be inactive bank for synch operations
    	        UPDd_TriggerNvmWrite();
    		}
    	}
    	else
    	{
    		// Update was on the passive chain
			status = UPD_IBootControl_SetBootSlot(!ActiveSlot);
			if( status == E_OK )
			{
				UpdateState = eUPDiUpdate_Activation;
		        UPDd_TriggerNvmWrite();
				UPDd_INFO("Swapping boot slot after activation ");
			}
    	}

		if( (status != E_OK) && (status != E_PENDING))
		{
			UPDUpdateMan_Reset();
		}
    }

    return status;
}

//=====================================================================================================================
//  Health management interface
//=====================================================================================================================
Std_ReturnType UPDUpdateMan_BootStatus(boolean BootSuccess)
{
	boolean ExpectedSlot;
	Std_ReturnType status = UPD_IBootControl_GetBootSlot(&ActiveSlot, &ExpectedSlot);

	if( status==E_OK )
	{
		if(UpdateState == eUPDiUpdate_Idle_Booting)
		{
			UpdateState = eUPDiUpdate_Idle_Hold;
			if( ActiveSlot != ExpectedSlot )
			{
				status = UPD_IBootControl_SetBootSlot(ActiveSlot);
				UPDUpdateMan_InspectBank(eUPDiUpdate_BankInactive);
				UPDd_TriggerNvmWrite();
			}
		}
		else if(UpdateState == eUPDiUpdate_Activated_Booting)
		{
			// Reboot after Activation is done, let's check the status
			//DeployAllTargets(ActiveSlot);
			if( ActiveSlot != ExpectedSlot )
			{
				UpdateState = eUPDiUpdate_Activated_RollbackDone;
				status = UPD_IBootControl_SetBootSlot(ActiveSlot);
			}
			else if( BootSuccess )
			{
				UpdateState = eUPDiUpdate_Activated_Success;
			}
			else
			{
				UpdateState = eUPDiUpdate_Activated_Failure;
			}
			UPDd_TriggerNvmWrite();
		}
		else if(UpdateState == eUPDiUpdate_Activated_RollbackDone)
		{
			// Roll back is done, let's move back to idle
			UPDUpdateMan_Reset();
		}
		else if( (UpdateState == eUPDiUpdate_Activated_Success) ||
				 (UpdateState == eUPDiUpdate_Activated_Failure) )
		{
			// We are waiting for a  commit or rollback request,
			// but we did get any confirmation and a power cycle was done
			if( ActiveSlot != ExpectedSlot )
			{
				// something wrong happend, we're now back on the old software
				UpdateState = eUPDiUpdate_Activated_RollbackDone;
				status = UPD_IBootControl_SetBootSlot(ActiveSlot);
			}
			else
			{
				// the absence of explicit request is understood as an implicit roll-back request.
				UpdateState = eUPDiUpdate_RollingBack;
				status = UPD_IBootControl_SetBootSlot(!ActiveSlot);
			}
			UPDd_TriggerNvmWrite();
		}
		else if(UpdateState == eUPDiUpdate_RollingBack)
		{
			// Roll back is done, let's move back to idle
			UPDUpdateMan_Reset();
		}
		else
		{
			if( ActiveSlot != ExpectedSlot )
			{
				// Something wrong happened with the active chain, the passive become active
				// let's confirm the active chain and invalidate inactive targets.
				// since boot chain change, any ongoing update campaign need to be canceled
				status = UPD_IBootControl_SetBootSlot(ActiveSlot);
				UPDUpdateMan_Reset();
			}
		}
	}
	return status;
}
/*=====================================================================================================================
* Public function  : Std_ReturnType UPDUpdateMan_Reset(void)
* Function description : This function terminate any update operation and returns to IDLE state
* Input argument : Std_ReturnType
* Return : tUPDUpdateState
*=====================================================================================================================*/
Std_ReturnType UPDUpdateMan_Reset(void)
{
	UpdateState = eUPDiUpdate_Idle_InspectingAndSynching;
	InvalidateInactivesTargets();
	DeployAllTargets();
	UPDd_TriggerNvmWrite();
	return E_OK;
}

/*=====================================================================================================================
* Public function  : Std_ReturnType UPDUpdateMan_Rollback(void)
* Function description : This function terminate any update operation and returns to IDLE state
* Input argumnet : Std_ReturnType
* Return : tUPDUpdateState
* Developer : sananth2
*=====================================================================================================================*/
Std_ReturnType     UPDUpdateMan_Rollback(void)
{
	Std_ReturnType status = E_NOT_OK;
	if(UpdateState == eUPDiUpdate_Activated_Booting)
	{
		// ActiveSlot is unknown until the bootSuccess confirmation
		// let's wait the boot result
		status = E_PENDING;
	}
	else if( UpdateState == eUPDiUpdate_Activated_RollbackDone)
	{
		// Rollback is already done
		status = E_OK;
	}
	else if( (UpdateState == eUPDiUpdate_Activated_Success) || (UpdateState == eUPDiUpdate_Activated_Failure))
	{
		status = UPD_IBootControl_SetBootSlot(!ActiveSlot);
		if( status == E_OK )
		{
			UpdateState = eUPDiUpdate_RollingBack;
			UPDd_TriggerNvmWrite();
			UPDd_INFO("Swapping boot slot for rollback ");
		}
	}
	return status;
}

/*=====================================================================================================================
* Public function  : Std_ReturnType UPDUpdateMan_Commit(void)
* Function description : This function terminate any update operation and returns to IDLE state
* Input argumnet : Std_ReturnType
* Return : tUPDUpdateState
* Developer : sananth2
*=====================================================================================================================*/
Std_ReturnType UPDUpdateMan_Commit(void)
{
    Std_ReturnType status = E_NOT_OK;

	if(UpdateState == eUPDiUpdate_Activated_Booting)
	{
		// ActiveSlot is unknown until the bootSuccess confirmation
		status = E_PENDING;
	}
	else if( UpdateState == eUPDiUpdate_Activated_Success)
    {
		/*Commit is accepted, let's move back to idle*/
		status = UPDd_UpdateArbAnchor();
		if( status == E_OK )
		{
			UPDd_INFO("Committing");
			// return to Idle state
			UPDUpdateMan_Reset();
		}
		else if( status != E_PENDING )
		{
			UPDd_ERROR("Update of ARB index failed");
			// return to Idle state
			UPDUpdateMan_Reset();
		}
    }

    return status;
}

/*=====================================================================================================================
* Private function  : tUPDUpdateState UPDUpdateMan_UpdateLatestState(void) 
* Function description : This function shall return the updatecdd state machine state
* Input argumnet : void
* Return : tUPDUpdateState
* Developer : sananth2
*=====================================================================================================================*/
tUPDUpdateState UPDUpdateMan_GetUpdateState(void)
{
    return UpdateState;
}


/*=====================================================================================================================
* Private function  : Std_ReturnType UPDUpdateMan_InspectBank(tUPDBank Bank)
* Function description : This function trigger the inspection of all targets for this bank
* Input argument : void
* Return : void, the result of the inspection is known thru the targets states
*=====================================================================================================================*/
void UPDUpdateMan_InspectBank(tUPDBank Bank)
{
	uint16_t  iTarget,iTargetCount;
	iTargetCount = UPDi_GetTargetCount();
	for(iTarget=0; iTarget<iTargetCount; iTarget++)
	{
		tUPDiTarget* pTarget = UPDi_GetTarget(iTarget);
		UPDTarget_Inspect(pTarget, Bank);
	}
}


/*=====================================================================================================================
* Private function  : void UPDUpdateMan_Task(void)
* Function description : This function shall be call periodically when the system is active.
* Input argument : void
* Return : void
*=====================================================================================================================*/
void UPDUpdateMan_Task(void)
{
	if( UpdateState==eUPDiUpdate_Idle_Hold )
	{
		if(HoldTimeout)
		{
			HoldTimeout--;
		}
		else
		{
			UPDd_AutoInspect();
			UPDInstallMan_PorcessTargets(); // let's wake-up Install manager
			UpdateState = eUPDiUpdate_Idle_InspectingAndSynching;
		}
	}
	else if( UpdateState == eUPDiUpdate_Idle_InspectingAndSynching)
	{
		if( UPDInstallMan_ProcessIO() != E_PENDING)
		{
			boolean activeOk = BankVerfiedOk(eUPDiUpdate_BankActive,FALSE) == E_OK;
			boolean inactiveOk = BankVerfiedOk(eUPDiUpdate_BankInactive,FALSE) == E_OK;
			boolean aOnlyOk = BankVerfiedOk(eUPDiUpdate_BankInactive,TRUE) == E_OK;

			if( activeOk && inactiveOk && aOnlyOk)
			{
				UpdateState = eUPDiUpdate_Idle_Healthy;
				UPDd_TriggerNvmWrite();
			}
			else if( inactiveOk && !activeOk )
			{
				Std_ReturnType status = UPD_IBootControl_SetBootSlot(!ActiveSlot);
				if( status == E_OK )
				{
					UpdateState = eUPDiUpdate_Idle_AutoSwapPending;
				}
				UPDd_WARNING("Active Chain is damaged but Inactive is ok, swap expected at next reboot.");
			}
			else if( !activeOk  && !inactiveOk)
			{
				UpdateState = eUPDiUpdate_Idle_Damaged;
				UPDd_ERROR("Active and Inactive chain are both damaged, impossible to recover.");
			}
			else if( !aOnlyOk )
			{
				UpdateState = eUPDiUpdate_Idle_Damaged;
				UPDd_ERROR("AOnly content is damaged, impossible to recover.");
			}
			else
			{
				// aOnlyOk is ok, active is ok, inactive nok
				UpdateState = eUPDiUpdate_Idle_Damaged;
				UPDd_ERROR("Inactive chain is damaged, auto-reparation is not activated or failed.");
			}

		}
	}
	else if( (UpdateState==eUPDiUpdate_Updating  ) || (UpdateState==eUPDiUpdate_Validation ) )
	{
		UPDInstallMan_ProcessIO() ;
	}
}

//=====================================================================================================================
//  Management Interface
//=====================================================================================================================

#if (UPDd_HOLD_TIMEOUT_MS/UPDd_TASK_PERIOD_MS) > 0xFFFF
#error UPDd_HOLD_TIMEOUT_MS is too big to be represented with a uint16_t
#endif
Std_ReturnType UPDUpdateMan_Init(void)
{
	UpdateState = eUPDiUpdate_Idle;
	UpdatedBank = eUPDiUpdate_BankInactive;
	ActiveSlot = 0xFF;
	HoldTimeout = UPDd_HOLD_TIMEOUT_MS/UPDd_TASK_PERIOD_MS;
	return E_NOT_OK;
}

Std_ReturnType UPDUpdateMan_Serialize(tUPDStream *pStream)
{
	UPDi_SERIALIZE(pStream, UpdateState );
	UPDi_SERIALIZE(pStream, UpdatedBank );
	return E_OK;
}
Std_ReturnType UPDUpdateMan_Deserialize(tUPDStream *pStream)
{
	UPDi_DESERIALIZE(pStream, UpdateState, eUPDiUpdate_Idle );
	UPDi_DESERIALIZE(pStream, UpdatedBank, eUPDiUpdate_BankInactive); // The default value changed to Inactive to compute the hash and erase at the bootup.

	if((UpdateState & eUPDiUpdate_Idle_Mask) ==  eUPDiUpdate_Idle)
	{
		UpdateState = eUPDiUpdate_Idle_Booting;
	}
	else if ( UpdateState==eUPDiUpdate_Activation )
	{
		UpdateState = eUPDiUpdate_Activated_Booting;
	}

	return E_OK;
}



//=====================================================================================================================
//  UPD CDD Internal
//=====================================================================================================================


boolean UPDUpdateMan_GetSlot(tUPDBank Bank)
{
	boolean Slot=FALSE;

	if( ActiveSlot == 0xFF )
	{
		UPDd_ERROR("Reading slot before end of boot sequence");
	}
	if( Bank == eUPDiUpdate_BankActive)
	{
		Slot = ActiveSlot;
	}
	else if( Bank == eUPDiUpdate_BankInactive)
	{
		Slot = !ActiveSlot;
	}
	else
	{
		UPDd_ERROR("Invalid Bank");
	}

	return Slot;
}

tUPDBank UPDUpdateMan_GetUPDatedBank(void)
{
    return UpdatedBank;
}



