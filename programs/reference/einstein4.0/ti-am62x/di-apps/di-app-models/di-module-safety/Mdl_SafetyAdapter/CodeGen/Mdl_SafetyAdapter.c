/*---------------------------------------------------------------------------------------------------------------------
**
** VISTEON CORPORATION CONFIDENTIAL
** ________________________________
**
** [2015] Visteon Corporation
** All Rights Reserved.
**
** NOTICE: This is an unpublished work of authorship, which contains trade secrets.
** Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
** its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
** or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
** in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
** under all copyright laws to protect this work as a published work, when appropriate.
** Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
** without the written authorization of Visteon Corporation.
**
** ---------------------------------------------------------------------------------------------------------------------*/
#include "Mdl_SafetyAdapter.h"
#include "Std_Types.h"
#include "Rte_Type.h"
#include "Rte_Mdl_SafetyAdapter_Type.h"


/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
#define MDL_SAFETYADAPTER_RXCAN_SIG_NR_BIT_POS                 		0U
#define MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_BIT_POS            		1U
#define MDL_SAFETYADAPTER_RXCAN_SIG_INVALID_BIT_POS            		2U
#define MDL_SAFETYADAPTER_RXCAN_SIG_RETENTION_BIT_POS            	3U
#define MDL_SAFETYADAPTER_RXCAN_SIG_ISO_BIT_POS            	        4U
#define MDL_SAFETYADAPTER_RXCAN_MISSING_OW_BIT_POS            	    5U    /*FaultHandling_Nissan_Toyota*/
#define MDL_SAFETYADAPTER_RXCAN_INVALID_OW_BIT_POS           	    6U    /*FaultHandling_Nissan_Toyota*/


#define MDL_SAFETYADAPTER_TXCAN_IS_KEEP_ALIVE_SUPPORTED(props)   (((props) & MDL_SAFETYADAPTER_TXCAN_KEEP_ALIVE_BIT_ENABLED) == MDL_SAFETYADAPTER_TXCAN_KEEP_ALIVE_BIT_ENABLED)
#define MDL_SAFETYADAPTER_TXCAN_IS_CONFIRMATION_SUPPORTED(props) (((props) & MDL_SAFETYADAPTER_TXCAN_CONFIRMATION_ENABLED) == MDL_SAFETYADAPTER_TXCAN_CONFIRMATION_ENABLED)
#define MDL_SAFETYADAPTER_TXCAN_IS_ISO_SUPPORTED(props)          (((props) & MDL_SAFETYADAPTER_TXCAN_ISO_SUPPORTED) == MDL_SAFETYADAPTER_TXCAN_ISO_SUPPORTED)


#  ifndef COMM_NO_COMMUNICATION
#   define COMM_NO_COMMUNICATION (0U)
#  endif

#  ifndef COMM_SILENT_COMMUNICATION
#   define COMM_SILENT_COMMUNICATION (1U)
#  endif

#  ifndef COMM_FULL_COMMUNICATION
#   define COMM_FULL_COMMUNICATION (2U)
#  endif

/********************************************************************************************************************
*  PRIVATE TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/
/* Rx Functions */
static void Mdl_SafetyAdapter_RxCanSignalMissingProcessing(void);
static void Mdl_SafetyAdapter_RxCanSignalInvalidProcessing(void);
static boolean Mdl_SafetyAdapter_RxCanIsSignalMissing(tRxSafeSignalId SignalId);
static boolean Mdl_SafetyAdapter_RxCanIsSignalNR(tRxSafeSignalId SignalId);
static boolean Mdl_SafetyAdapter_RxCanIsSignalInvalid(tRxSafeSignalId SignalId);

tRxSafeSignalStatus Mdl_SafetyAdapter_RxCanGetSignalStatus(tRxSafeSignalId SignalId);
Std_ReturnType Mdl_SafetyAdapter_RxCanSetSignalValue(tRxSafeSignalId SignalId,uint8 * pSignalValue);
static void Mdl_SafetyAdapter_UtilMemSet(uint8 *pDest,uint8 Value,uint32 Length);
/* Tx Functions */


/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/
/* Buffers for Com Rx Signal */
uint8  Mdl_SafetyAdapter_RxCanSigBufferU8[MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8_BUFFERS];
static uint16 Mdl_SafetyAdapter_RxCanSigBufferU16[MDL_SAFETYADAPTER_RXCAN_NUM_OF_U16_BUFFERS];
static uint32 Mdl_SafetyAdapter_RxCanSigBufferU32[MDL_SAFETYADAPTER_RXCAN_NUM_OF_U32_BUFFERS];
static uint8 Mdl_SafetyAdapter_RxCanSigBufferU8NArr[MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8ARR_BUFFERS];
static uint32 Mdl_SafetyAdapter_RxCanSigBufferU8ArrLength[MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8ARR_LENGTH_BUFFERS];

static 	VehicleActiveModes PrevVehState;

/* Com Rx signal buffer status */
static uint8 Mdl_SafetyAdapter_RxCanSignalInvalidStatus[MDL_SAFETYADAPTER_RXCAN_NUM_OF_SIGNAL_INVALID_STATUS_BYTES];
static uint8 Mdl_SafetyAdapter_RxCanIsSignalMissingEnabled[MDL_SAFETYADAPTER_RXCAN_NUM_OF_MISSING_STATUS_BYTES];
static uint8 Mdl_SafetyAdapter_RxCanIsSignalNREnabled[MDL_SAFETYADAPTER_RXCAN_NUM_OF_NR_STATUS_BYTES];
static uint8 Mdl_SafetyAdapter_RxCanIsSignalInvalidEnabled[MDL_SAFETYADAPTER_RXCAN_NUM_OF_SIGNAL_INVALID_STATUS_BYTES];
static uint32 Mdl_SafetyAdapter_RxCanSignalMissingCounter[MDL_SAFETYADAPTER_RXCAN_NUM_OF_MISSING_SIGNALS];
static uint32 Mdl_SafetyAdapter_RxCanSignalInvalidCounter[MDL_SAFETYADAPTER_RXCAN_NUM_OF_INVALID_SIGNALS];

/* Retention Buffers for Com Tx and Rx Signal */
#define MDL_SAFETYADAPTER_BACKUP_RAM_SEC_START
#include "MemMap.h"
/* Retention Buffers for Com Rx signal */
uint8  Mdl_SafetyAdapter_RxCanRetentionSigBufferU8[MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8_RETENTION_BUFFERS];
static uint16 Mdl_SafetyAdapter_RxCanRetentionSigBufferU16[MDL_SAFETYADAPTER_RXCAN_NUM_OF_U16_RETENTION_BUFFERS];
static uint32 Mdl_SafetyAdapter_RxCanRetentionSigBufferU32[MDL_SAFETYADAPTER_RXCAN_NUM_OF_U32_RETENTION_BUFFERS];
static uint8  Mdl_SafetyAdapter_RxCanRetentionSigBufferU8Arr[MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8ARR_RETENTION_BUFFERS];
static uint32  Mdl_SafetyAdapter_RxCanRetentionSigBufferU8ArrLength[MDL_SAFETYADAPTER_RXCAN_NUM_OF_RETENTION_U8ARR_LENGTH_BUFFERS];

static uint8 Mdl_SafetyAdapter_TxCanRetentionBufferU8[MDL_SAFETYADAPTER_TXCAN_NUM_OF_U8_BUFFERS];
static uint16 Mdl_SafetyAdapter_TxCanRetentionBufferU16[MDL_SAFETYADAPTER_TXCAN_NUM_OF_U16_BUFFERS];
static uint32 Mdl_SafetyAdapter_TxCanRetentionBufferU32[MDL_SAFETYADAPTER_TXCAN_NUM_OF_U32_BUFFERS];
static uint8 Mdl_SafetyAdapter_CanTxRetentionBufferArr[MDL_SAFETYADAPTER_TXCAN_NUM_OF_U8ARR_BUFFERS];
static uint32 Mdl_SafetyAdapter_CanTxRetentionBufferU8ArrLength[MDL_SAFETYADAPTER_TXCAN_NUM_OF_U8ARR_SIGNAL];
#define MDL_SAFETYADAPTER_BACKUP_RAM_END
#include "MemMap.h"
/* Confirmation status for the transmit signal */
static uint8 Mdl_SafetyAdapter_TxCanSignalConfirmStatus[MDL_SAFETYADAPTER_TXCAN_NUM_OF_CONF_STATUS_BYTES];
//extern VAR(tResetReason, RTE_VAR_INIT) Rte_ModeMgr_ppSRModeResetReason_ResetReason;
extern uint8 Mdl_SafetyAdapter_RxCanSignal_currentStatus[MDL_SAFETYADAPTER_RXCAN_NUM_OF_NR_STATUS_BYTES];

/* @brief  Instance of life-cycle state-machine */
//CMPLIB_INSTANCE(Mdl_SafetyAdapter)

/*=====================================================================================================================
**  CONSTANTS & TYPES
**=====================================================================================================================*/
#define Channel_0 ((uint8)0)
#define IGNON_VALUE ((uint8)2)

/*=====================================================================================================================
**  FORWARD DECLARATIONS
**=====================================================================================================================*/

/* This variable will hold the 1 min timer for SleepCtrl */


/*=====================================================================================================================
**  PRIVATE
**=====================================================================================================================*/
static void Mdl_SafetyAdapter_Ign_Networkmode_status(void);
/*=====================================================================================================================
**  PRIVATE
**=====================================================================================================================*/

/********************************************************************************************************************
*   @brief   This method is used to set the Com Tx singal value from the retention buffer
*   @param[in] SignalId Tx signal id
********************************************************************************************************************/
Std_ReturnType Mdl_SafetyAdapter_TxCan_SetSignalFromRetentionBuffer(tTxSignalId SignalId)
{
    Std_ReturnType ReturnStatus = E_NOT_OK;
    uint8* pTxSignalData = NULL_PTR;
    uint32 SignalLength = 0;
    Mdl_SafetyAdapter_TxCanSignalConfigType const * pTxSignalConfig;
    Mdl_SafetyAdapter_TxCanSetSignalFunctPtrType pTxSetSignalFunct;
	Mdl_SafetyAdapter_TxCanSetSignalU8ArrFunctPtrType pTxSetSignalU8ArrFunct;

    if (SignalId < eEndOfTxSignal)
    {
        pTxSignalConfig = &Mdl_SafetyAdapter_TxCanSignalConfig[SignalId];

        if(MDL_SAFETYADAPTER_TXCAN_IS_KEEP_ALIVE_SUPPORTED(pTxSignalConfig->TxSigalProps))
        {
        	/* Get retention buffer */
            if ((pTxSignalConfig->SignalLengthInByte == 1U) &&
				(pTxSignalConfig->SignalBufferStartIdx < MDL_SAFETYADAPTER_TXCAN_NUM_OF_U8_BUFFERS))
            {
                pTxSignalData = &Mdl_SafetyAdapter_TxCanRetentionBufferU8[pTxSignalConfig->SignalBufferStartIdx];
            }
            else if ((pTxSignalConfig->SignalLengthInByte == 2U) &&
            		(pTxSignalConfig->SignalBufferStartIdx < MDL_SAFETYADAPTER_TXCAN_NUM_OF_U16_BUFFERS))
            {
                pTxSignalData = (uint8 *)&Mdl_SafetyAdapter_TxCanRetentionBufferU16[pTxSignalConfig->SignalBufferStartIdx];
            }
            else if (((pTxSignalConfig->SignalLengthInByte > 2U) && (pTxSignalConfig->SignalLengthInByte <= 4U)) &&
            		(pTxSignalConfig->SignalBufferStartIdx < MDL_SAFETYADAPTER_TXCAN_NUM_OF_U32_BUFFERS))
            {
                pTxSignalData = (uint8 *)&Mdl_SafetyAdapter_TxCanRetentionBufferU32[pTxSignalConfig->SignalBufferStartIdx];
            }
            else
            {
            	if ((pTxSignalConfig->SignalBufferStartIdx < MDL_SAFETYADAPTER_TXCAN_NUM_OF_U8ARR_BUFFERS) &&
					(pTxSignalConfig->TxSetSignalIdx < CANABSMDL_TXCAN_NUM_OF_SET_SIG_U8ARR_FUNCT))
            	{
            		pTxSignalData = &Mdl_SafetyAdapter_CanTxRetentionBufferArr[pTxSignalConfig->SignalBufferStartIdx];
            		SignalLength = Mdl_SafetyAdapter_CanTxRetentionBufferU8ArrLength[pTxSignalConfig->TxSetSignalIdx];
            	}

            }
            /* Invoke set functions */
            if ((pTxSignalConfig->SignalLengthInByte <= 4U) &&
				(pTxSignalConfig->TxSetSignalIdx < CANABSMDL_TXCAN_NUM_OF_SET_SIG_FUNCT))
            {
                if (MDL_SAFETYADAPTER_TXCAN_IS_ISO_SUPPORTED(pTxSignalConfig->TxSigalProps))
                {
                   // ReturnStatus = CMdl_SafetyAdapter_TxCan_SetIsoSignal(SignalId,pTxSignalData,pTxSignalConfig->SignalLengthInByte);
                }
                else
                {
                    pTxSetSignalFunct = Mdl_SafetyAdapter_TxCanSetSignalFunctPtrConfig[pTxSignalConfig->TxSetSignalIdx];
                    if (pTxSetSignalFunct != NULL_PTR)
                    {
                        ReturnStatus = (*pTxSetSignalFunct)(pTxSignalData);
                    }
                }
            }
            else
            {
                if (MDL_SAFETYADAPTER_TXCAN_IS_ISO_SUPPORTED(pTxSignalConfig->TxSigalProps))
                {
                    //ReturnStatus = CMdl_SafetyAdapter_TxCan_SetIsoSignal(SignalId,pTxSignalData,SignalLength);
                }
                else
                {
                    if (pTxSignalConfig->TxSetSignalIdx < CANABSMDL_TXCAN_NUM_OF_SET_SIG_U8ARR_FUNCT)
                    {
                        pTxSetSignalU8ArrFunct= Mdl_SafetyAdapter_TxCanSetSignalU8ArrFunctPtrConfig[pTxSignalConfig->TxSetSignalIdx];
                        if (pTxSetSignalU8ArrFunct != NULL_PTR)
                        {
                            ReturnStatus = (*pTxSetSignalU8ArrFunct)(pTxSignalData,SignalLength);
                        }
                    }
            	}
            }
        }
    }
    return ReturnStatus;
}


/********************************************************************************************************************
*   @brief   This method is used to set the Tx signal value to the COM for signal length less than or equal to 32 bit
*   @param[in] SignalId TX signal id
*   @param[in] pTxSignalData pointer to the data to be updated in COM
*   @return Std_ReturnType status of the request
*   E_OK status accepted
*   E_NOT_OK status not accepted
********************************************************************************************************************/
Std_ReturnType Mdl_SafetyAdapter_TxCan_SetSignalValue(tTxSignalId SignalId,uint8 *pTxSignalData)
{
    Std_ReturnType ReturnStatus = E_NOT_OK;
    Mdl_SafetyAdapter_TxCanSignalConfigType const * pTxSignalConfig;
    Mdl_SafetyAdapter_TxCanSetSignalFunctPtrType pTxSetSignalFunct;

    if (SignalId < eEndOfTxSignal)
    {
        if (pTxSignalData != NULL_PTR)
        {
            /* check for back ram retention */
            pTxSignalConfig = &Mdl_SafetyAdapter_TxCanSignalConfig[SignalId];
            if(MDL_SAFETYADAPTER_TXCAN_IS_KEEP_ALIVE_SUPPORTED(pTxSignalConfig->TxSigalProps))
            {
                // save message in the buffer
            	if ((pTxSignalConfig->SignalLengthInByte == 1U) &&
					(pTxSignalConfig->SignalBufferStartIdx < MDL_SAFETYADAPTER_TXCAN_NUM_OF_U8_BUFFERS))
                {
                    Mdl_SafetyAdapter_TxCanRetentionBufferU8[pTxSignalConfig->SignalBufferStartIdx] = *((uint8 *)pTxSignalData);
                }
                else if ((pTxSignalConfig->SignalLengthInByte == 2U) &&
                		(pTxSignalConfig->SignalBufferStartIdx < MDL_SAFETYADAPTER_TXCAN_NUM_OF_U16_BUFFERS))
                {
                    Mdl_SafetyAdapter_TxCanRetentionBufferU16[pTxSignalConfig->SignalBufferStartIdx] = *((uint16 *)pTxSignalData);
                }
                else if (((pTxSignalConfig->SignalLengthInByte > 2U) && (pTxSignalConfig->SignalLengthInByte <= 4U)) &&
                		(pTxSignalConfig->SignalBufferStartIdx < MDL_SAFETYADAPTER_TXCAN_NUM_OF_U32_BUFFERS))
                {
                    Mdl_SafetyAdapter_TxCanRetentionBufferU32[pTxSignalConfig->SignalBufferStartIdx] = *((uint32 *)pTxSignalData);
                }
                else
                {

                }
            }

            /* Invoke set functions */
			if (MDL_SAFETYADAPTER_TXCAN_IS_ISO_SUPPORTED(pTxSignalConfig->TxSigalProps))
            {
                //ReturnStatus = CMdl_SafetyAdapter_TxCan_SetIsoSignal(SignalId,pTxSignalData,pTxSignalConfig->SignalLengthInByte);
            }
            else
            {
                if ((pTxSignalConfig->SignalLengthInByte <= 4U) &&
                    (pTxSignalConfig->TxSetSignalIdx < CANABSMDL_TXCAN_NUM_OF_SET_SIG_FUNCT))
                {
                    pTxSetSignalFunct = Mdl_SafetyAdapter_TxCanSetSignalFunctPtrConfig[pTxSignalConfig->TxSetSignalIdx];
                    if (pTxSetSignalFunct != NULL_PTR)
                    {
                        ReturnStatus = (*pTxSetSignalFunct)(pTxSignalData);
                    }
                }
            }
        }
    }
    return ReturnStatus;
}

/********************************************************************************************************************
*   @brief   This method is used to set the Tx signal value to the COM for signal length of Unit Arr type
*   @param[in] SignalId TX signal id
*   @param[in] pTxSignalData pointer to the data to be updated in COM
*   @param[in] SignalLength length of the data to be udpated
*   @return Std_ReturnType status of the request
*   E_OK status accepted
*   E_NOT_OK status not accepted
********************************************************************************************************************/
Std_ReturnType Mdl_SafetyAdapter_TxCan_SetSignalValueU8Arr(tTxSignalId SignalId,uint8 *pTxSignalData,uint32 SignalLength)
{
	Std_ReturnType ReturnStatus = E_NOT_OK;
	Mdl_SafetyAdapter_TxCanSignalConfigType const * pTxSignalConfig;
	Mdl_SafetyAdapter_TxCanSetSignalU8ArrFunctPtrType pTxSetSignalU8ArrFunct;
	uint32 BuffIdx;

	if (SignalId < eEndOfTxSignal)
	{
		if (pTxSignalData != NULL_PTR)
		{
			/* check for back ram retention */
			pTxSignalConfig = &Mdl_SafetyAdapter_TxCanSignalConfig[SignalId];
			if(MDL_SAFETYADAPTER_TXCAN_IS_KEEP_ALIVE_SUPPORTED(pTxSignalConfig->TxSigalProps))
			{
				if (((pTxSignalConfig->SignalBufferStartIdx + SignalLength -1U) < MDL_SAFETYADAPTER_TXCAN_NUM_OF_U8ARR_BUFFERS) &&
					(pTxSignalConfig->TxSetSignalIdx < CANABSMDL_TXCAN_NUM_OF_SET_SIG_U8ARR_FUNCT))
				{
					for (BuffIdx = 0;BuffIdx<SignalLength;BuffIdx++)
					{
						Mdl_SafetyAdapter_CanTxRetentionBufferArr[pTxSignalConfig->SignalBufferStartIdx+BuffIdx] = pTxSignalData[BuffIdx];
					}
                    Mdl_SafetyAdapter_CanTxRetentionBufferU8ArrLength[pTxSignalConfig->TxSetSignalIdx]=SignalLength;
				}
			}
			/* call corresponding signal */
            if (MDL_SAFETYADAPTER_TXCAN_IS_ISO_SUPPORTED(pTxSignalConfig->TxSigalProps))
            {
                //ReturnStatus = CMdl_SafetyAdapter_TxCan_SetIsoSignal(SignalId,pTxSignalData,SignalLength);
            }
            else
            {
                if (pTxSignalConfig->TxSetSignalIdx < CANABSMDL_TXCAN_NUM_OF_SET_SIG_U8ARR_FUNCT)
                {
                    pTxSetSignalU8ArrFunct= Mdl_SafetyAdapter_TxCanSetSignalU8ArrFunctPtrConfig[pTxSignalConfig->TxSetSignalIdx];
                    if (pTxSetSignalU8ArrFunct != NULL_PTR)
                    {
                        ReturnStatus = (*pTxSetSignalU8ArrFunct)(pTxSignalData,SignalLength);
                    }
                }
            }
		}
	}
	return ReturnStatus;
}

/********************************************************************************************************************
*   @brief   This method is used for clearing the signal confirmation
*   @param[in] SignalId TX signal id
********************************************************************************************************************/
void Mdl_SafetyAdapter_TxCan_ClearCanSignalTxConfirmation(tTxSignalId SignalId)
{
    uint8 BytePosition;
	Mdl_SafetyAdapter_TxCanSignalConfigType const * pTxSignalConfig;
    if (SignalId < eEndOfTxSignal)
    {
        BytePosition = SignalId>>3U;
        pTxSignalConfig = &Mdl_SafetyAdapter_TxCanSignalConfig[SignalId];
        if((MDL_SAFETYADAPTER_TXCAN_IS_CONFIRMATION_SUPPORTED(pTxSignalConfig->TxSigalProps)) &&
            (BytePosition < MDL_SAFETYADAPTER_TXCAN_NUM_OF_CONF_STATUS_BYTES))
        {
            MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_TxCanSignalConfirmStatus[BytePosition],(SignalId & 0x7U));
        }
    }
}

/* Function for getting the signal confirmation status */
/********************************************************************************************************************
*   @brief   This method is used for get the signal confirmation status
*   @param[in] SignalId TX signal id
*	@param[in] pStatus pointer to the confirmation status
*	eTxConfirmStatus_Set : Confirmation received for last transmission request
*	eTxConfirmStatus_Cleared : Confirmation not received for last transmission request
********************************************************************************************************************/
void Mdl_SafetyAdapter_TxCan_GetCanSignalTxConfirmation(tTxSignalId SignalId,tTxSigConfirmStatus *pStatus)
{
    uint8 BytePosition;
    Mdl_SafetyAdapter_TxCanSignalConfigType const * pTxSignalConfig;
    tTxSigConfirmStatus Status = eTxSigConfirmStatus_NotSupported;
    if (SignalId < eEndOfTxSignal)
    {
        BytePosition = SignalId>>3U;
        pTxSignalConfig = &Mdl_SafetyAdapter_TxCanSignalConfig[SignalId];
        if((MDL_SAFETYADAPTER_TXCAN_IS_CONFIRMATION_SUPPORTED(pTxSignalConfig->TxSigalProps)) &&
            (BytePosition < MDL_SAFETYADAPTER_TXCAN_NUM_OF_CONF_STATUS_BYTES))
        {
            if (TRUE == MDL_SAFETYADAPTER_IS_BIT_SET(Mdl_SafetyAdapter_TxCanSignalConfirmStatus[BytePosition],(SignalId & 0x07)))
            {
                Status = eTxSigConfirmStatus_Set;
            }
            else
            {
                Status =  eTxSigConfirmStatus_Cleared;
            }
        }
    }
    *pStatus = Status;
}

/********************************************************************************************************************
*   @brief   This method is used to set the signal confirmation status
*   @param[in] SignalId TX signal id
********************************************************************************************************************/
void Mdl_SafetyAdapter_TxCan_SetCanSignalTxConfirmation(tTxSignalId SignalId)
{
	uint8 BytePosition;
	Mdl_SafetyAdapter_TxCanSignalConfigType const * pTxSignalConfig;

    if (SignalId < eEndOfTxSignal)
    {
        BytePosition = SignalId>>3U;
        pTxSignalConfig = &Mdl_SafetyAdapter_TxCanSignalConfig[SignalId];
        if((MDL_SAFETYADAPTER_TXCAN_IS_CONFIRMATION_SUPPORTED(pTxSignalConfig->TxSigalProps)) &&
            (BytePosition < MDL_SAFETYADAPTER_TXCAN_NUM_OF_CONF_STATUS_BYTES))
        {
            MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_TxCanSignalConfirmStatus[BytePosition],(SignalId & 0x7U));
        }
    }
}
/* Rx Implementation */
/********************************************************************************************************************
*   @brief   Main function Runnable for the Mdl_SafetyAdapter. Should be called in every
*   \MDL_SAFETYADAPTER_RXCAN_MAINFUNCTION_TIME_IN_MS. It process the missing and Invalid status
**************************************** ****************************************************************************/
// void Mdl_SafetyAdapter_Impl_RxCanMdlMainFunction(void)
// {
// 	Mdl_SafetyAdapter_RxCanSignalMissingProcessing();
// 	Mdl_SafetyAdapter_RxCanSignalInvalidProcessing();
// }

/********************************************************************************************************************
*   @brief   This method is used to clear the signal just received status
*   @param[in] SignalId RX signal id
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCan_SignalClearJustRcvdStatus(tRxSafeSignalId SignalId)
{
    uint8 BytePosition;

    if (SignalId < eEndOfRxSafeSignal)
    {
        BytePosition = SignalId>>3U;
        if(BytePosition < MDL_SAFETYADAPTER_RXCAN_NUM_OF_JUST_RCVD_STATUS_BYTES)
        {
            MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[BytePosition],(SignalId & 0x7U));
        }
    }
}


/********************************************************************************************************************
*   @brief   This method is used to get the signal just received status
*   @param[in] SignalId RX signal id
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCan_SignalGetJustRcvdStatus(tRxSafeSignalId SignalId, tRxSafeSignalJustRcvdStatus *pJustRcvdStatus)
{
    tRxSafeSignalJustRcvdStatus JustRcvdStatus=eNot_Just_Received;
    uint8 BytePosition;

    if (SignalId < eEndOfRxSafeSignal)
    {
        BytePosition = SignalId>>3U;
        if(BytePosition < MDL_SAFETYADAPTER_RXCAN_NUM_OF_JUST_RCVD_STATUS_BYTES)
        {
            if (TRUE == MDL_SAFETYADAPTER_IS_BIT_SET(Mdl_SafetyAdapter_RxCanJustRcvdStatus[BytePosition],(SignalId & 0x07)))
            {
                JustRcvdStatus = eJust_Received;
            }
        }
    }
    *pJustRcvdStatus = JustRcvdStatus;

}

/********************************************************************************************************************
*   @brief   This method is used to get the Rx Signal value and its status for signal length less than or equal
*   to 32.
*   @param[in] SignalId		Signal Id
*	@param[out] pSignalValue pointer to which the Rx signal value to be copied
*	@param[out] pSignalStatus pointer to which the Rx signal status to be copied. Below Bit value represents the
*	Signal status
*				eSIGNAL_OK(0x0) : No fault occurred
*				eSIGNAL_MISSING(0x1) : Signal missing status set
*				eSIGNAL_NEVER_RECEIVED(0x2) : Signal never received status set
*				eSIGNAL_INVALID(0x4): Signal invalid status set
*	@return Std_ReturnType status of the request.
*	E_OK :	request Supported
*	E_NOT_OK : request not supported
********************************************************************************************************************/
Std_ReturnType Mdl_SafetyAdapter_RxCan_GetSignalValue(tRxSafeSignalId SignalId,uint8 * pSignalValue,tRxSafeSignalStatus *pSignalStatus)
{
    Std_ReturnType ReturnStatus = E_NOT_OK;
    tRxSafeSignalStatus SigStatus = eSIGNAL_OK;
    boolean GetLocalBuffer = TRUE;
    boolean InvalidStatus = FALSE;
    boolean Skip_Invalid_Storage = FALSE;
    Mdl_SafetyAdapter_RxCanSignalConfigType const *pSignalConfig;
    Mdl_SafetyAdapter_RxCanSignalInvalidConfigType const * pSignalInvalidConfig;
    Mdl_SafetyAdapter_RxCanGetSignalFunctPtrType pGetSignalFunction;
    uint32 ByteIndex;
    ByteIndex = SignalId>>3U;

    if ((SignalId < eEndOfRxSafeSignal) &&
        (pSignalValue != NULL_PTR) &&
        (pSignalStatus != NULL_PTR))
    {
        /* Get signal value */
        pSignalConfig = &Mdl_SafetyAdapter_RxCanSignalConfig[SignalId];
        SigStatus = Mdl_SafetyAdapter_RxCanGetSignalStatus(SignalId);
		
		/*check if the signal value has to be fetched from COM buffer or retention buffer */
		if ( TRUE == MDL_SAFETYADAPTER_IS_BIT_SET(Mdl_SafetyAdapter_RxCanSignal_currentStatus[ByteIndex],(SignalId & 0x07)))
		{
            /* Check and update the signal status */
            if (SigStatus == eSIGNAL_OK)
            {	
            	if (pSignalConfig->SignalGetFunctIdx < MDL_SAFETYADAPTER_RXCAN_NUM_OF_GET_SIG_FUNCT)
		    	{
                   if ((TRUE == MDL_SAFETYADAPTER_IS_BIT_SET(pSignalConfig->RxSigMonitoringType,MDL_SAFETYADAPTER_RXCAN_SIG_INVALID_BIT_POS)) &&
                       (pSignalConfig->SignalInvalidIdx <  MDL_SAFETYADAPTER_RXCAN_NUM_OF_INVALID_SIGNALS))   

			        {
                        pSignalInvalidConfig =&Mdl_SafetyAdapter_RxCanSignalInvalidConfig[pSignalConfig->SignalInvalidIdx];
				        /* check if the received signal has Invalid  value*/
				        if (pSignalInvalidConfig->pSignalInvalidCheckFunc != NULL_PTR)
				        {
					       InvalidStatus = pSignalInvalidConfig->pSignalInvalidCheckFunc();
				        }

                        if(FALSE != InvalidStatus)
                        {
                            GetLocalBuffer = TRUE;
                            Skip_Invalid_Storage =  TRUE;
                        }
                    }
                    if(FALSE == Skip_Invalid_Storage)
                    {
            		    pGetSignalFunction = Mdl_SafetyAdapter_RxCanGetSignalFunctConfig[pSignalConfig->SignalGetFunctIdx].pGetSignalFunct;
		    	
		    		    if (pGetSignalFunction != NULL_PTR)
		    		    {
		    			    (*pGetSignalFunction)(pSignalValue);
		    			    /* Update local buffer */
		    			    Mdl_SafetyAdapter_RxCanSetSignalValue(SignalId,pSignalValue);
		    			    GetLocalBuffer = FALSE;
		    		    }
                    }
		    	}
		    
            }
            else
            {
                GetLocalBuffer = TRUE; //S2dot8 defect fix, shall be applicable for Ford PDC, HD, Tatagen2 Projects
            }		
		}
		else
		{
               GetLocalBuffer = TRUE; //S2dot8 defect fix, shall be applicable for Ford PDC, HD, Tatagen2 Projects
        }
		    
        if (GetLocalBuffer != FALSE)
        {
            /*FaultHandling_Nissan_Toyota*/
            if ((FALSE != MDL_SAFETYADAPTER_IS_BIT_SET(pSignalConfig->RxSigMonitoringType,MDL_SAFETYADAPTER_RXCAN_INVALID_OW_BIT_POS)) &&
			((Mdl_SafetyAdapter_RxCanIsSignalInvalid(SignalId) != FALSE) || Skip_Invalid_Storage != FALSE))
			{
                 Mdl_SafetyAdapter_RxCanSetSignalValue(SignalId,(uint8 *)&(pSignalConfig->SignalInvalidOWValue));
			}
			if ((FALSE != MDL_SAFETYADAPTER_IS_BIT_SET(pSignalConfig->RxSigMonitoringType,MDL_SAFETYADAPTER_RXCAN_MISSING_OW_BIT_POS)) &&
			(Mdl_SafetyAdapter_RxCanIsSignalMissing(SignalId) != FALSE))
			{
                Mdl_SafetyAdapter_RxCanSetSignalValue(SignalId,(uint8 *)&(pSignalConfig->SignalMissingOWValue));
			}
            /*FaultHandling_Nissan_Toyota*/
            if (FALSE != MDL_SAFETYADAPTER_IS_BIT_SET(pSignalConfig->RxSigMonitoringType,MDL_SAFETYADAPTER_RXCAN_SIG_RETENTION_BIT_POS))
            {
                if ((pSignalConfig->SignalLengthInByte == 1U) &&
        				(pSignalConfig->SignalBufferStartIdx < MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8_RETENTION_BUFFERS))
                {
                    *((uint8 *)pSignalValue) = Mdl_SafetyAdapter_RxCanRetentionSigBufferU8[pSignalConfig->SignalBufferStartIdx];
                }
                else if((pSignalConfig->SignalLengthInByte == 2U) &&
                        (pSignalConfig->SignalBufferStartIdx < MDL_SAFETYADAPTER_RXCAN_NUM_OF_U16_RETENTION_BUFFERS))
                {
                    *((uint16 *)pSignalValue) = Mdl_SafetyAdapter_RxCanRetentionSigBufferU16[pSignalConfig->SignalBufferStartIdx];
                }
                else if(((pSignalConfig->SignalLengthInByte > 2U) && (pSignalConfig->SignalLengthInByte <= 4U)) &&
                        (pSignalConfig->SignalBufferStartIdx < MDL_SAFETYADAPTER_RXCAN_NUM_OF_U32_RETENTION_BUFFERS))
                {
                    *((uint32 *)pSignalValue) = Mdl_SafetyAdapter_RxCanRetentionSigBufferU32[pSignalConfig->SignalBufferStartIdx];
                }
                else
                {
                    ReturnStatus = E_NOT_OK;
                }
            }
            else
            {
                if ((pSignalConfig->SignalLengthInByte == 1U) &&
        				(pSignalConfig->SignalBufferStartIdx < MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8_BUFFERS))
                {
                    *((uint8 *)pSignalValue) = Mdl_SafetyAdapter_RxCanSigBufferU8[pSignalConfig->SignalBufferStartIdx];
                }
                else if((pSignalConfig->SignalLengthInByte == 2U) &&
                        (pSignalConfig->SignalBufferStartIdx < MDL_SAFETYADAPTER_RXCAN_NUM_OF_U16_BUFFERS))
                {
                    *((uint16 *)pSignalValue) = Mdl_SafetyAdapter_RxCanSigBufferU16[pSignalConfig->SignalBufferStartIdx];
                }
                else if(((pSignalConfig->SignalLengthInByte > 2U) && (pSignalConfig->SignalLengthInByte <= 4U)) &&
                        (pSignalConfig->SignalBufferStartIdx < MDL_SAFETYADAPTER_RXCAN_NUM_OF_U32_BUFFERS))
                {
                    *((uint32 *)pSignalValue) = Mdl_SafetyAdapter_RxCanSigBufferU32[pSignalConfig->SignalBufferStartIdx];
                }
                else
                {
                    ReturnStatus = E_NOT_OK;
                }
            }
        }

        ReturnStatus = E_OK;
        *pSignalStatus =  SigStatus;
    }
    return ReturnStatus;
}

/********************************************************************************************************************
*   @brief   This method is used to get the Rx Signal value and its status for signal type of uint8 array
*   @param[in] SignalId		Signal Id
*	@param[out] pSignalValue pointer to which the Rx signal value to be copied
*	@param[out] pSignalStatus pointer to which the Rx signal status to be copied. Below Bit value represents the
*	Signal status
*				eSIGNAL_OK(0x0) : No fault occurred
*				eSIGNAL_MISSING(0x1) : Signal missing status set
*				eSIGNAL_NEVER_RECEIVED(0x2) : Signal never received status set
*				eSIGNAL_INVALID(0x4): Signal invalid status set
*	@param[out] pSignalLength pointer to which the received Rx signal length to be copied.
*	@return Std_ReturnType status of the request.
*	E_OK :	request Supported
*	E_NOT_OK : request not supported
********************************************************************************************************************/
Std_ReturnType Mdl_SafetyAdapter_RxCan_GetSignalValueU8Arr(tRxSafeSignalId SignalId,uint8 * pSignalValue,
												tRxSafeSignalStatus *pSignalStatus,uint32 *pSignalLength)
{
    Std_ReturnType ReturnStatus = E_NOT_OK;
    uint32 ByteIndex;
    uint16 LengthBufferIdx=0;
    tRxSafeSignalStatus SigStatus = eSIGNAL_OK;
    boolean GetLocalBuffer = TRUE;
    Mdl_SafetyAdapter_RxCanSignalConfigType const *pSignalConfig;
    Mdl_SafetyAdapter_RxCanGetSignalU8ArrFunctPtrType pGetSignalU8ArrFunction;

    if ((SignalId < eEndOfRxSafeSignal) &&
        (pSignalValue != NULL_PTR) &&
        (pSignalStatus != NULL_PTR))
    {
        /* Get signal value */
        pSignalConfig = &Mdl_SafetyAdapter_RxCanSignalConfig[SignalId];
        SigStatus = Mdl_SafetyAdapter_RxCanGetSignalStatus(SignalId);
        /* Check and update the signal status */
        if (SigStatus == eSIGNAL_OK)
        {
        	/* Get signal from Com Buffer */
        	if (pSignalConfig->SignalGetFunctIdx < MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8ARR_SIG_CFG)
        	{
        		pGetSignalU8ArrFunction = Mdl_SafetyAdapter_RxCanGetSignalU8ArrConfig[pSignalConfig->SignalGetFunctIdx].pGetSignalU8ArrFunct;
        		if (pGetSignalU8ArrFunction!= NULL_PTR)
        		{
        			(*pGetSignalU8ArrFunction)(pSignalValue,pSignalLength);
        			/* Update local buffer */
        			(void)Mdl_SafetyAdapter_RxCanSetSignalValueU8Arr(SignalId,pSignalValue,pSignalLength);
        			GetLocalBuffer = FALSE;
        		}
        	}
        }

        if (GetLocalBuffer != FALSE)
        {
        	/* Get Signal from the local buffer where init value for the missing, never received and invalid is
        	               updated */
            if ( FALSE != MDL_SAFETYADAPTER_IS_BIT_SET(pSignalConfig->RxSigMonitoringType,MDL_SAFETYADAPTER_RXCAN_SIG_RETENTION_BIT_POS))
            {
                if (pSignalConfig->SignalGetFunctIdx < MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8ARR_SIG_CFG)
                {
                    LengthBufferIdx = Mdl_SafetyAdapter_RxCanGetSignalU8ArrConfig[pSignalConfig->SignalGetFunctIdx].SignalU8ArrBufferLenIdx;
                    if (LengthBufferIdx < MDL_SAFETYADAPTER_RXCAN_NUM_OF_RETENTION_U8ARR_LENGTH_BUFFERS)
                    {
                        *pSignalLength = Mdl_SafetyAdapter_RxCanRetentionSigBufferU8ArrLength[LengthBufferIdx];
                    }
                    else
                    {
                        *pSignalLength = 0;
                    }

                    for(ByteIndex = 0;((ByteIndex < (*pSignalLength)) &&
                        ((ByteIndex+pSignalConfig->SignalLengthInByte-1U) < MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8ARR_RETENTION_BUFFERS));ByteIndex++)
                    {
                        pSignalValue[ByteIndex] = Mdl_SafetyAdapter_RxCanRetentionSigBufferU8Arr[ByteIndex+pSignalConfig->SignalBufferStartIdx];
                    }
                }
            }
            else
            {
                if (pSignalConfig->SignalGetFunctIdx < MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8ARR_SIG_CFG)
                {
                    LengthBufferIdx = Mdl_SafetyAdapter_RxCanGetSignalU8ArrConfig[pSignalConfig->SignalGetFunctIdx].SignalU8ArrBufferLenIdx;
                    if (LengthBufferIdx < MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8ARR_LENGTH_BUFFERS)
                    {
                        *pSignalLength = Mdl_SafetyAdapter_RxCanSigBufferU8ArrLength[LengthBufferIdx];
                    }
                    else
                    {
                        *pSignalLength = 0;
                    }
                    for(ByteIndex = 0;((ByteIndex < (*pSignalLength)) &&
                        ((ByteIndex+pSignalConfig->SignalLengthInByte-1U) < MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8ARR_BUFFERS));ByteIndex++)
                    {
                        pSignalValue[ByteIndex] = Mdl_SafetyAdapter_RxCanSigBufferU8NArr[ByteIndex+pSignalConfig->SignalBufferStartIdx];
                    }
                }
            }
        }

        ReturnStatus = E_OK;
        *pSignalStatus =  SigStatus;
    }
    return ReturnStatus;
}

/********************************************************************************************************************
*   @brief   This method is used to Enable/Disable the processing of the signal missing status.
*   @param[in] SignalId		Signal Id
*	@param[in] Status Enable/Disable the monitoring status
*	TRUE : Enable the monitoring status
*	FALSE : Disable the monitoring status
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCan_SignalMissingProcessingControl(tRxSafeSignalId SignalId,boolean Status)
{
    uint32 ByteIndex;
    Mdl_SafetyAdapter_RxCanSignalConfigType const *pSignalConfig;

    if (SignalId < eEndOfRxSafeSignal)
    {
    	pSignalConfig = &Mdl_SafetyAdapter_RxCanSignalConfig[SignalId];
        ByteIndex = SignalId>>3U;
        /* Check for missing monitoring support */
        if ((TRUE == MDL_SAFETYADAPTER_IS_BIT_SET(pSignalConfig->RxSigMonitoringType,MDL_SAFETYADAPTER_RXCAN_SIG_MISSING_BIT_POS)) &&
            (ByteIndex <  MDL_SAFETYADAPTER_RXCAN_NUM_OF_MISSING_STATUS_BYTES))
        {
            if (Status == TRUE)
            {
                MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanIsSignalMissingEnabled[ByteIndex],(SignalId & 0x07));

            }
            else
            {
                MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanIsSignalMissingEnabled[ByteIndex],(SignalId & 0x07));
                /*! Set Timer to Zero */
                Mdl_SafetyAdapter_RxCanSignalMissingCounter[SignalId] = pSignalConfig->SignalMissingCounterValue;
            }
        }
    }
}

/********************************************************************************************************************
*   @brief   This method is used to Enable/Disable the processing of the signal invalid status.
*   @param[in] SignalId		Signal Id
*	@param[in] Status Enable/Disable the monitoring status
*	TRUE : Enable the monitoring status
*	FALSE : Disable the monitoring status
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCan_SignalInvalidProcessingControl(tRxSafeSignalId SignalId,boolean Status)
{
    uint16 ByteIndex;
    Mdl_SafetyAdapter_RxCanSignalConfigType  const * pSignalConfig;
    Mdl_SafetyAdapter_RxCanSignalInvalidConfigType const *pSignalInvalidConfig;

    if (SignalId < eEndOfRxSafeSignal)
    {
        pSignalConfig = &Mdl_SafetyAdapter_RxCanSignalConfig[SignalId];
        if ((TRUE == MDL_SAFETYADAPTER_IS_BIT_SET(pSignalConfig->RxSigMonitoringType,MDL_SAFETYADAPTER_RXCAN_SIG_INVALID_BIT_POS)) &&
           (pSignalConfig->SignalInvalidIdx <  MDL_SAFETYADAPTER_RXCAN_NUM_OF_INVALID_SIGNALS))
        {
            ByteIndex = pSignalConfig->SignalInvalidIdx>>3U;
            if ((ByteIndex < MDL_SAFETYADAPTER_RXCAN_NUM_OF_SIGNAL_INVALID_STATUS_BYTES) &&
				(pSignalConfig->SignalInvalidIdx < MDL_SAFETYADAPTER_RXCAN_NUM_OF_INVALID_SIGNALS))
            {
            	pSignalInvalidConfig = &Mdl_SafetyAdapter_RxCanSignalInvalidConfig[pSignalConfig->SignalInvalidIdx];
            	if (Status == TRUE)
				{
					MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanIsSignalInvalidEnabled[ByteIndex],(pSignalConfig->SignalInvalidIdx & 0x07));
				}
				else
				{
					MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanIsSignalInvalidEnabled[ByteIndex],(pSignalConfig->SignalInvalidIdx & 0x07));
					/* clear the timer */
					Mdl_SafetyAdapter_RxCanSignalInvalidCounter[pSignalConfig->SignalInvalidIdx] = pSignalInvalidConfig->SignalInvalidCounterValue;
				}
            }
        }
    }
}

/********************************************************************************************************************
*   @brief   This method is used to Enable/Disable the processing of the signal never received status.
*   @param[in] SignalId		Signal Id
*	@param[in] Status Enable/Disable the monitoring status
*	TRUE : Enable the monitoring status
*	FALSE : Disable the monitoring status
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCan_SignalNRProcessingControl(tRxSafeSignalId SignalId,boolean Status)
{
    uint32 ByteIndex;
    if (SignalId < eEndOfRxSafeSignal)
    {
        ByteIndex = SignalId>>3U;
        if (ByteIndex <  MDL_SAFETYADAPTER_RXCAN_NUM_OF_NR_STATUS_BYTES)
        {
            if (Status == TRUE)
            {
            	/* Set the NR monitoring status enable flag to 1 */
                MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanIsSignalNREnabled[ByteIndex],(SignalId & 0x07));
                /* Set the NR flag to 1 */
                MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[ByteIndex],(SignalId & 0x07));
            }
            else
            {
            	/* clear the NR monitoring status enable flag  */
                MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanIsSignalNREnabled[ByteIndex],(SignalId & 0x07));
                /* Set the NR flag to 0 */
                MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalNRStatus[ByteIndex],(SignalId & 0x07));
            }
        }
    }
}

/********************************************************************************************************************
*   @brief   This method is used to set the initial Rx signal buffer value for signal length less than or equal to
*   uint32.
*   @param[in] SignalId		Signal Id
*	@param[in] pSignalValue pointer to the data value provided
*	@return Std_ReturnType status of the request.
*	E_OK :	request Supported
*	E_NOT_OK : request not supported
********************************************************************************************************************/
Std_ReturnType Mdl_SafetyAdapter_RxCan_SetSignalInitValue(tRxSafeSignalId SignalId,uint8 * pSignalValue)
{
   return Mdl_SafetyAdapter_RxCanSetSignalValue(SignalId,pSignalValue);
}

/********************************************************************************************************************
*   @brief   This method is used to set the initial Rx signal buffer value for signal uint8 array type.
*   @param[in] SignalId		Signal Id
*	@param[in] pSignalValue pointer to the data value provided.
*	@param[in] pSignalLength length of the data provided.
*	@return Std_ReturnType status of the request.
*	E_OK :	request Supported
*	E_NOT_OK : request not supported
********************************************************************************************************************/
Std_ReturnType CMdl_SafetyAdapter_RxCan_SetSignalInitValueU8Arr(tRxSafeSignalId SignalId,uint8 * pSignalValue,uint32 *pSignalLength)
{
	return Mdl_SafetyAdapter_RxCanSetSignalValueU8Arr(SignalId,pSignalValue,pSignalLength);
}

/********************************************************************************************************************
*   @brief     This method is used to reset the missing timer
*   @param[in] SignalId		Signal Id
********************************************************************************************************************/
void Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer(tRxSafeSignalId SignalId)
{
	Mdl_SafetyAdapter_RxCanSignalConfigType const * pSignalConfig;
    uint16 ByteIndex;
    if (SignalId < eEndOfRxSafeSignal)
	{
		pSignalConfig = &Mdl_SafetyAdapter_RxCanSignalConfig[SignalId];
        /* Check the timer count */
        Mdl_SafetyAdapter_RxCanSignalMissingCounter[SignalId] = pSignalConfig->SignalMissingCounterValue;
        ByteIndex = SignalId>>3U;
        if (ByteIndex <  MDL_SAFETYADAPTER_RXCAN_NUM_OF_MISSING_STATUS_BYTES)
        {
            MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalMissingStatus[ByteIndex],(SignalId & 0x07));
        }
    }
}
/********************************************************************************************************************
*   @brief   This method is used to initialize variables in the TxCanMdl
********************************************************************************************************************/
void Mdl_SafetyAdapter_TxCanVarInit(void)
{
	Mdl_SafetyAdapter_UtilMemSet(&Mdl_SafetyAdapter_TxCanRetentionBufferU8[0],0,MDL_SAFETYADAPTER_TXCAN_NUM_OF_U8_BUFFERS);
	Mdl_SafetyAdapter_UtilMemSet((uint8 *)&Mdl_SafetyAdapter_TxCanRetentionBufferU16[0],0,MDL_SAFETYADAPTER_TXCAN_NUM_OF_U16_BUFFERS*2);
	Mdl_SafetyAdapter_UtilMemSet((uint8 *)&Mdl_SafetyAdapter_TxCanRetentionBufferU32[0],0,MDL_SAFETYADAPTER_TXCAN_NUM_OF_U32_BUFFERS*4);
	Mdl_SafetyAdapter_UtilMemSet(&Mdl_SafetyAdapter_CanTxRetentionBufferArr[0],0,MDL_SAFETYADAPTER_TXCAN_NUM_OF_U8ARR_BUFFERS);
	Mdl_SafetyAdapter_UtilMemSet((uint8 *)&Mdl_SafetyAdapter_CanTxRetentionBufferU8ArrLength[0],0,MDL_SAFETYADAPTER_TXCAN_NUM_OF_U8ARR_SIGNAL*4);
	Mdl_SafetyAdapter_UtilMemSet(&Mdl_SafetyAdapter_TxCanSignalConfirmStatus[0],0,MDL_SAFETYADAPTER_TXCAN_NUM_OF_CONF_STATUS_BYTES);
}

/********************************************************************************************************************
*   @brief   This method is used to initialize variables in the Mdl_SafetyAdapter
********************************************************************************************************************/
void Mdl_SafetyAdapter_RxCanVarInit(void)
{
	
	uint16 SignalInvalidIdx = 0;
	tRxSafeSignalId SignalId = 0;
	uint16 ByteIndex = 0;
	Mdl_SafetyAdapter_RxCanSignalInvalidConfigType const *pSignalInvalidConfig;
	
	//reload the invalid counter and initialize InvalidStatus and Invalidenabled.
	for (SignalInvalidIdx = 0U; SignalInvalidIdx < MDL_SAFETYADAPTER_RXCAN_NUM_OF_INVALID_SIGNALS ;SignalInvalidIdx++)
	{
		pSignalInvalidConfig =&Mdl_SafetyAdapter_RxCanSignalInvalidConfig[SignalInvalidIdx];
		SignalId = pSignalInvalidConfig->SignalInvalidSigIdx;
		ByteIndex = SignalInvalidIdx >> 3U;
		Mdl_SafetyAdapter_RxCanSignalInvalidCounter[SignalInvalidIdx] = pSignalInvalidConfig->SignalInvalidCounterValue;
		Mdl_SafetyAdapter_RxCanSignalInvalidStatus[ByteIndex] = 0;
		Mdl_SafetyAdapter_RxCanIsSignalInvalidEnabled[ByteIndex] = 0;
	}
	
	//initialize the timers counters and missing related variables
	for (SignalId = 0U; SignalId < eEndOfRxSafeSignal ;SignalId++)
	{	
       Mdl_SafetyAdapter_ReloadMissingTimer(SignalId);
	}   
	   	
	/* initialize the buffers */
	Mdl_SafetyAdapter_UtilMemSet(&Mdl_SafetyAdapter_RxCanSigBufferU8[0],0U,MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8_BUFFERS);
	Mdl_SafetyAdapter_UtilMemSet((uint8 *)&Mdl_SafetyAdapter_RxCanSigBufferU16[0],0U,MDL_SAFETYADAPTER_RXCAN_NUM_OF_U16_BUFFERS*2);
	Mdl_SafetyAdapter_UtilMemSet((uint8 *)&Mdl_SafetyAdapter_RxCanSigBufferU32[0],0U,MDL_SAFETYADAPTER_RXCAN_NUM_OF_U32_BUFFERS*4);
	Mdl_SafetyAdapter_UtilMemSet(&Mdl_SafetyAdapter_RxCanSigBufferU8NArr[0],0U,MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8ARR_BUFFERS);
	Mdl_SafetyAdapter_UtilMemSet((uint8 *)&Mdl_SafetyAdapter_RxCanSigBufferU8ArrLength[0],0U,MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8ARR_LENGTH_BUFFERS*2);

	/* Initialize the status flags */
	Mdl_SafetyAdapter_UtilMemSet(&Mdl_SafetyAdapter_RxCanSignal_currentStatus[0],0x00U,MDL_SAFETYADAPTER_RXCAN_NUM_OF_NR_STATUS_BYTES);
	Mdl_SafetyAdapter_UtilMemSet(&Mdl_SafetyAdapter_RxCanJustRcvdStatus[0],0U,MDL_SAFETYADAPTER_RXCAN_NUM_OF_JUST_RCVD_STATUS_BYTES);
	/* Initialize the status enable flags */
	Mdl_SafetyAdapter_UtilMemSet(&Mdl_SafetyAdapter_RxCanIsSignalMissingEnabled[0],0x0U,MDL_SAFETYADAPTER_RXCAN_NUM_OF_MISSING_STATUS_BYTES);
	Mdl_SafetyAdapter_UtilMemSet(&Mdl_SafetyAdapter_RxCanIsSignalNREnabled[0],0xFFU,MDL_SAFETYADAPTER_RXCAN_NUM_OF_NR_STATUS_BYTES);
			            						            			
}


/********************************************************************************************************************
*   @brief   This method is used to process the missing signal status
********************************************************************************************************************/
static void Mdl_SafetyAdapter_RxCanSignalMissingProcessing(void)
{
	tRxSafeSignalId SignalId;
	uint32 ByteIndex;

	for (SignalId = 0;SignalId < eEndOfRxSafeSignal;SignalId++)
	{
		ByteIndex = SignalId>>3U;
		/* Missing processsing enabled */

		if ((TRUE == MDL_SAFETYADAPTER_IS_BIT_SET(Mdl_SafetyAdapter_RxCanIsSignalMissingEnabled[ByteIndex],(SignalId & 0x07))))

		{
			/* Check the timer count */
			if (Mdl_SafetyAdapter_RxCanSignalMissingCounter[SignalId] >0U)
			{
				Mdl_SafetyAdapter_RxCanSignalMissingCounter[SignalId]--;
				if (Mdl_SafetyAdapter_RxCanSignalMissingCounter[SignalId] == 0U)
				{
					MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignalMissingStatus[ByteIndex],(SignalId & 0x07));
                    MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanJustRcvdStatus[ByteIndex],(SignalId & 0x7U));
				}
			}
		}
	}
}

/********************************************************************************************************************
*   @brief   This is method is used to process the invalid status
********************************************************************************************************************/
static void Mdl_SafetyAdapter_RxCanSignalInvalidProcessing(void)
{
	uint32 SignalInvalidIdx;
	tRxSafeSignalId SignalId;
	uint32 ByteIndex;
	Mdl_SafetyAdapter_RxCanSignalInvalidConfigType const * pSignalInvalidConfig;
	boolean InvalidStatus = FALSE;

	for (SignalInvalidIdx = 0U; SignalInvalidIdx < MDL_SAFETYADAPTER_RXCAN_NUM_OF_INVALID_SIGNALS ;SignalInvalidIdx++)
	{
		pSignalInvalidConfig =&Mdl_SafetyAdapter_RxCanSignalInvalidConfig[SignalInvalidIdx];
		SignalId = pSignalInvalidConfig->SignalInvalidSigIdx;
		ByteIndex = SignalInvalidIdx >> 3U;

		if (SignalId < eEndOfRxSafeSignal)
		{
			/* Invalid processing enabled */
			if ((TRUE == MDL_SAFETYADAPTER_IS_BIT_SET(Mdl_SafetyAdapter_RxCanIsSignalInvalidEnabled[ByteIndex],(SignalInvalidIdx & 0x7U) )) &&
				((Mdl_SafetyAdapter_RxCanIsSignalNR(SignalId) != TRUE)))
			{
				/* check if the received signal is Invalid */
				if (pSignalInvalidConfig->pSignalInvalidCheckFunc != NULL_PTR)
				{
					InvalidStatus = pSignalInvalidConfig->pSignalInvalidCheckFunc();
				}

				if (InvalidStatus != FALSE)
				{
                    if ((FALSE == MDL_SAFETYADAPTER_IS_BIT_SET(Mdl_SafetyAdapter_RxCanSignalInvalidStatus[ByteIndex],(SignalInvalidIdx & 0x07))) &&
                        (Mdl_SafetyAdapter_RxCanSignalInvalidCounter[SignalInvalidIdx] == 0U))
					{
                        /* Reload timer */
                        Mdl_SafetyAdapter_RxCanSignalInvalidCounter[SignalInvalidIdx] = pSignalInvalidConfig->SignalInvalidCounterValue;
                    }

                    if (Mdl_SafetyAdapter_RxCanSignalInvalidCounter[SignalInvalidIdx] > 0U)
                    {
                        Mdl_SafetyAdapter_RxCanSignalInvalidCounter[SignalInvalidIdx]--;
                        if (Mdl_SafetyAdapter_RxCanSignalInvalidCounter[SignalInvalidIdx] == 0U)
                        {
                            MDL_SAFETYADAPTER_SET_BIT(Mdl_SafetyAdapter_RxCanSignalInvalidStatus[ByteIndex],(SignalInvalidIdx & 0x07));
                        }
                    }
				}
				else
				{
					Mdl_SafetyAdapter_RxCanSignalInvalidCounter[SignalInvalidIdx] = 0U;
					/* Clear status */
					MDL_SAFETYADAPTER_CLEAR_BIT(Mdl_SafetyAdapter_RxCanSignalInvalidStatus[ByteIndex],(SignalInvalidIdx & 0x07));
				}
			}
		}
	}
}

/********************************************************************************************************************
*   @brief   This method is used to get the missing status of the signal
*   @param[in] SignalId
*   @return boolean missing status
*   TRUE	Signal is missing
*   FALSE   Signal is not missing
********************************************************************************************************************/
static boolean Mdl_SafetyAdapter_RxCanIsSignalMissing(tRxSafeSignalId SignalId)
{
    uint32 ByteIndex;
    boolean status = FALSE;
    ByteIndex = SignalId>>3U;
    if (ByteIndex <  MDL_SAFETYADAPTER_RXCAN_NUM_OF_MISSING_STATUS_BYTES)
    {
        status = MDL_SAFETYADAPTER_IS_BIT_SET(Mdl_SafetyAdapter_RxCanSignalMissingStatus[ByteIndex],(SignalId & 0x07));
    }
    return status;
}

/********************************************************************************************************************
*   @brief   This method is used to get the never received status of the signal
*   @param[in] SignalId
*   @return boolean never received status
*   TRUE	Signal never received
*   FALSE   Signal is received
********************************************************************************************************************/
static boolean Mdl_SafetyAdapter_RxCanIsSignalNR(tRxSafeSignalId SignalId)
{
    uint32 ByteIndex;
    boolean status = FALSE;
    ByteIndex = SignalId>>3U;
    if (ByteIndex <  MDL_SAFETYADAPTER_RXCAN_NUM_OF_NR_STATUS_BYTES)
    {
        status = MDL_SAFETYADAPTER_IS_BIT_SET(Mdl_SafetyAdapter_RxCanSignalNRStatus[ByteIndex],(SignalId & 0x07));
    }
    return status;
}

/********************************************************************************************************************
*   @brief   This method is used to get the invalid status of the signal
*   @param[in] SignalId
*   @return boolean invalid status
*   TRUE	Signal Invalid
*   FALSE   Signal valid
********************************************************************************************************************/
static boolean Mdl_SafetyAdapter_RxCanIsSignalInvalid(tRxSafeSignalId SignalId)
{
    boolean status = FALSE;
    uint32 ByteIndex;
    Mdl_SafetyAdapter_RxCanSignalConfigType  const * pSignalConfig;
    pSignalConfig = &Mdl_SafetyAdapter_RxCanSignalConfig[SignalId];
    if (pSignalConfig->SignalInvalidIdx <  MDL_SAFETYADAPTER_RXCAN_NUM_OF_INVALID_SIGNALS)
	{
    	ByteIndex = pSignalConfig->SignalInvalidIdx >>3U;
		if (ByteIndex < MDL_SAFETYADAPTER_RXCAN_NUM_OF_SIGNAL_INVALID_STATUS_BYTES)
		{
			status = MDL_SAFETYADAPTER_IS_BIT_SET(Mdl_SafetyAdapter_RxCanSignalInvalidStatus[ByteIndex],(pSignalConfig->SignalInvalidIdx & 0x07U));
		}
	}
    return status;
}

/********************************************************************************************************************
*   @brief   This method is used to get the status of the signal
*   @param[in] SignalId
*   @return tRxSafeSignalStatus  status of the signal .Below Bit value represents the
*	Signal status
*				eSIGNAL_OK(0x0) : No fault occurred
*				eSIGNAL_MISSING(0x1) : Signal missing status set
*				eSIGNAL_NEVER_RECEIVED(0x2) : Signal never received status set
*				eSIGNAL_INVALID(0x4): Signal invalid status set
********************************************************************************************************************/
tRxSafeSignalStatus Mdl_SafetyAdapter_RxCanGetSignalStatus(tRxSafeSignalId SignalId)
{
	tRxSafeSignalStatus SigStatus = eSIGNAL_OK;

	if (Mdl_SafetyAdapter_RxCanIsSignalNR(SignalId) == TRUE)
	{
		SigStatus |= eSIGNAL_NEVER_RECEIVED;
	}

	if (Mdl_SafetyAdapter_RxCanIsSignalMissing(SignalId) == TRUE)
	{
		SigStatus |= eSIGNAL_MISSING;
	}

	if (Mdl_SafetyAdapter_RxCanIsSignalInvalid(SignalId) == TRUE)
	{
		SigStatus |= eSIGNAL_INVALID;
	}

	return SigStatus;
}

/********************************************************************************************************************
*   @brief   This method is used to signal value to local buffer of signal type uint8 Array
*   @param[in] SignalId	value of signal Id
*   @param[in] pSignalValue pointer to the signal value to be copied.
*   @param[in] pSignalLength pointer to the length of the signal value to be copied.
*   @return tRxSafeSignalStatus  status of the request.
*	E_OK		Request accepted
*	E_NOT_OK	Request not accepted
********************************************************************************************************************/
Std_ReturnType Mdl_SafetyAdapter_RxCanSetSignalValueU8Arr(tRxSafeSignalId SignalId,uint8 * pSignalValue,uint32 *pSignalLength)
{
	Std_ReturnType ReturnStatus = E_NOT_OK;
	uint32 ByteIndex;
    uint16 BufferLength=0;
	Mdl_SafetyAdapter_RxCanSignalConfigType const * pSignalConfig;

	if ((SignalId < eEndOfRxSafeSignal) &&
		(pSignalValue != NULL_PTR) &&
		(pSignalLength != NULL_PTR))
	{
		pSignalConfig = &Mdl_SafetyAdapter_RxCanSignalConfig[SignalId];
        /* pSignalConfig->SignalGetFunctIdx is same as the number of U8Arr signal */
		if (pSignalConfig->SignalGetFunctIdx < MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8ARR_SIG_CFG)
		{
            BufferLength = Mdl_SafetyAdapter_RxCanGetSignalU8ArrConfig[pSignalConfig->SignalGetFunctIdx].SignalU8ArrBufferLenIdx;
            if (FALSE != MDL_SAFETYADAPTER_IS_BIT_SET(pSignalConfig->RxSigMonitoringType,MDL_SAFETYADAPTER_RXCAN_SIG_RETENTION_BIT_POS))
            {
                if (BufferLength < MDL_SAFETYADAPTER_RXCAN_NUM_OF_RETENTION_U8ARR_LENGTH_BUFFERS)
                {
                    Mdl_SafetyAdapter_RxCanRetentionSigBufferU8ArrLength[BufferLength] = *pSignalLength;
                    for(ByteIndex = 0;((ByteIndex < (*pSignalLength)) &&
                         ((ByteIndex+pSignalConfig->SignalLengthInByte-1U) < MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8ARR_RETENTION_BUFFERS));ByteIndex++)
                    {
                        Mdl_SafetyAdapter_RxCanRetentionSigBufferU8Arr[ByteIndex+pSignalConfig->SignalBufferStartIdx] = pSignalValue[ByteIndex];
                    }
                }
            }
            else
            {
                if (BufferLength < MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8ARR_LENGTH_BUFFERS)
                {
                    Mdl_SafetyAdapter_RxCanSigBufferU8ArrLength[BufferLength] = *pSignalLength;
                    for(ByteIndex = 0;((ByteIndex < (*pSignalLength)) &&
                        ((ByteIndex+pSignalConfig->SignalLengthInByte-1U) < MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8ARR_BUFFERS));ByteIndex++)
                    {
                        Mdl_SafetyAdapter_RxCanSigBufferU8NArr[ByteIndex+pSignalConfig->SignalBufferStartIdx] = pSignalValue[ByteIndex];
                    }
                }
            }
		}

		ReturnStatus = E_OK;
	}
	return ReturnStatus;
}

/********************************************************************************************************************
*   @brief   This method is used to signal value to local buffer of signal length less than or equal to uint32
*   @param[in] SignalId	value of signal Id
*   @param[in] pSignalValue pointer to the signal value to be copied.
*   @return tRxSafeSignalStatus  status of the request.
*	E_OK		Request accepted
*	E_NOT_OK	Request not accepted
********************************************************************************************************************/
Std_ReturnType Mdl_SafetyAdapter_RxCanSetSignalValue(tRxSafeSignalId SignalId,uint8 * pSignalValue)
{
	Std_ReturnType ReturnStatus = E_OK;
	Mdl_SafetyAdapter_RxCanSignalConfigType const * pSignalConfig;

	if ((SignalId < eEndOfRxSafeSignal) &&
		(pSignalValue != NULL_PTR))
	{
		pSignalConfig = &Mdl_SafetyAdapter_RxCanSignalConfig[SignalId];

        if (FALSE != MDL_SAFETYADAPTER_IS_BIT_SET(pSignalConfig->RxSigMonitoringType,MDL_SAFETYADAPTER_RXCAN_SIG_RETENTION_BIT_POS))
        {
            if ((pSignalConfig->SignalLengthInByte == 1U) &&
                (pSignalConfig->SignalBufferStartIdx < MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8_RETENTION_BUFFERS))
            {
                /* set the value to retention buffer */
                Mdl_SafetyAdapter_RxCanRetentionSigBufferU8[pSignalConfig->SignalBufferStartIdx] = *((uint8 *)pSignalValue);
            }
            else if((pSignalConfig->SignalLengthInByte == 2U) &&
                    (pSignalConfig->SignalBufferStartIdx < MDL_SAFETYADAPTER_RXCAN_NUM_OF_U16_RETENTION_BUFFERS))
            {
                /* set the value to retention buffer */
                Mdl_SafetyAdapter_RxCanRetentionSigBufferU16[pSignalConfig->SignalBufferStartIdx] = *((uint16 *)pSignalValue);
            }
            else if(((pSignalConfig->SignalLengthInByte > 2U) && (pSignalConfig->SignalLengthInByte <= 4U)) &&
                    (pSignalConfig->SignalBufferStartIdx < MDL_SAFETYADAPTER_RXCAN_NUM_OF_U32_RETENTION_BUFFERS))
            {
                /* set the value to retention buffer */
                Mdl_SafetyAdapter_RxCanRetentionSigBufferU32[pSignalConfig->SignalBufferStartIdx] = *((uint32 *)pSignalValue);
            }
            else
            {
                ReturnStatus = E_NOT_OK;
            }
        }
        else
        {
            if ((pSignalConfig->SignalLengthInByte == 1U) &&
                (pSignalConfig->SignalBufferStartIdx < MDL_SAFETYADAPTER_RXCAN_NUM_OF_U8_BUFFERS))
            {
                /* set the value to retention buffer */
                Mdl_SafetyAdapter_RxCanSigBufferU8[pSignalConfig->SignalBufferStartIdx] = *((uint8 *)pSignalValue);
            }
            else if((pSignalConfig->SignalLengthInByte == 2U) &&
                    (pSignalConfig->SignalBufferStartIdx < MDL_SAFETYADAPTER_RXCAN_NUM_OF_U16_BUFFERS))
            {
                /* set the value to retention buffer */
                Mdl_SafetyAdapter_RxCanSigBufferU16[pSignalConfig->SignalBufferStartIdx] = *((uint16 *)pSignalValue);
            }
            else if(((pSignalConfig->SignalLengthInByte > 2U) && (pSignalConfig->SignalLengthInByte <= 4U)) &&
                    (pSignalConfig->SignalBufferStartIdx < MDL_SAFETYADAPTER_RXCAN_NUM_OF_U32_BUFFERS))
            {
                /* set the value to retention buffer */
                Mdl_SafetyAdapter_RxCanSigBufferU32[pSignalConfig->SignalBufferStartIdx] = *((uint32 *)pSignalValue);
            }
            else
            {
                ReturnStatus = E_NOT_OK;
            }
        }
	}
	return ReturnStatus;
}

/********************************************************************************************************************
*   @brief   This method is used to initialize the buffer to a provided value.
*   @param[out] pDest pointer to the buffer for updating the value
*   @param[in] Value value to be initialized.
*   @param[in] Length length of the buffer to be initialized.
********************************************************************************************************************/
static void Mdl_SafetyAdapter_UtilMemSet(uint8 *pDest,uint8 Value,uint32 Length)
{
    uint32 Idx;
    /* copy number of bytes from [pSrc] to [pDest]. */
    if (pDest!= NULL_PTR)
    {
    	for (Idx = 0; Idx < Length; Idx++)
		{
			pDest[Idx] = Value;
		}
    }
}

/********************************************************************************************************************
*   @brief   This method is used to get missing overflow bit status of signal.
*   @param[in] SignalId value of signal Id
********************************************************************************************************************/
boolean Mdl_SafetyAdapter_GetRXCAN_MissingOW_BITstatus(tRxSafeSignalId SignalId)
{
	boolean fl_Mdl_SafetyAdapterRet_bool = (boolean)E_OK; // Fail safe value is applicable for given signal
	Mdl_SafetyAdapter_RxCanSignalConfigType const *pSignalConfig;
    if(SignalId < eEndOfRxSafeSignal)
    {
	    pSignalConfig = &Mdl_SafetyAdapter_RxCanSignalConfig[SignalId];
		
	    if(TRUE != MDL_SAFETYADAPTER_IS_BIT_SET(pSignalConfig->RxSigMonitoringType,MDL_SAFETYADAPTER_RXCAN_MISSING_OW_BIT_POS))
	    {
		    fl_Mdl_SafetyAdapterRet_bool = (boolean)E_NOT_OK; // Fail safe value is not applicable for given signal
	    }
    }
    return fl_Mdl_SafetyAdapterRet_bool;
}
/****************************************************************************
** Function Name     : void Ctrl_WSS_Impl_MainFunction(void)
**
** Description       : 	This function process the batt drain and app sleep status to set the sleep condition

**
** Invocation        : Ctrl_WSS.c
**
** Parameters        :
**
** Return Value      : None
**
** Critical Section  : none
******************************************************************************/
void Mdl_SafetyAdapter_Task(void)
{
    ClusterModes fl_Current_Clustermode_Status_u8;

    /******************************************App team****************************************************************/
	(void)Rte_Read_Mdl_SafetyAdapter_rp_ctrlwss_Clustermode_WSSCurrentClusterMode(&fl_Current_Clustermode_Status_u8);
    if((CLUSTER_INACTIVE != fl_Current_Clustermode_Status_u8 )&&( CLUSTER_INACTIVE == PrevVehState))
    {
        (void)Rte_Write_pp_SafetyAdapter_Clustermode_SafetyAdapter_CurrentClusterMode(CLUSTER_INACTIVE);
       
        (void)Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_Ctrl_telltale_Impl_OnCommand(eCmpCmd_Init);
        (void)Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_View_telltale_Impl_OnCommand(eCmpCmd_Init);
        (void)Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_Ctrl_telltale_Impl_OnCommand(eCmpCmd_Activate);
        (void)Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_View_telltale_Impl_OnCommand(eCmpCmd_Activate);
         
        //Rte_Call_rp_Init_rp_Init_Mdl_Abs_Init();
        Rte_Call_rp_Init_rp_Init_Mdl_Airbag_Init();
        // Rte_Call_rp_Init_rp_Init_Mdl_Brake_Hold_Init();
        // Rte_Call_rp_Init_rp_Init_Mdl_Brake_Yellow_Init();
        // Rte_Call_rp_Init_rp_Init_Mdl_Parking_Brake_Init();
        // Rte_Call_rp_Init_rp_Init_Mdl_Traction_Control_Init();
        // Rte_Call_rp_Init_rp_Init_Mdl_VSC_OFF_Init();
        (void)Rte_Write_pp_SafetyAdapter_Clustermode_SafetyAdapter_CurrentClusterMode(CLUSTER_ACTIVE);
    }   
	if(fl_Current_Clustermode_Status_u8 == CLUSTER_ACTIVE)
    {
	    Mdl_SafetyAdapter_Ign_Networkmode_status();
    }
    PrevVehState = fl_Current_Clustermode_Status_u8;

    /******************************************Com team****************************************************************/
	Mdl_SafetyAdapter_RxCanSignalMissingProcessing();
	Mdl_SafetyAdapter_RxCanSignalInvalidProcessing();
    

}
/****************************************************************************
** Function Name     : void Mdl_SafetyAdapter_Ign_Networkmode_status(void)
**
** Description       : 	This function process the IGN,and vehicle app mode internal status

**
** Invocation        : Safety_Adater.c
**
** Parameters        :
**
** Return Value      : None
**
** Critical Section  : none
******************************************************************************/
static void Mdl_SafetyAdapter_Ign_Networkmode_status(void)
{
    //VehicleActiveModes fl_AppMode;
	//IgntionSubstateType fl_Ctrl_Wss_Ign_Status_u8;
	IoHwAb_ErrorType fl_get_error_status_u8;
	uint8 fl_network_mode_status_u8;
	SInt32 fl_Ign_IoHab_Status_S32 = (SInt32)IgnOff;

    /* Interface from ASIL*/
	(void)Rte_Call_rp_IoHwAb_ADC_GetProcessedAdc(((IoHwAb_AdcSignalIdType)eIO_ADC_IGN_AD), &fl_Ign_IoHab_Status_S32, &fl_get_error_status_u8);

    /* Interface from QM*/
	(void)ComMExt_CAN_GetCurrentComMode(Channel_0, &fl_network_mode_status_u8);
    

	if(fl_network_mode_status_u8 == COMM_FULL_COMMUNICATION)
	{
		//fl_AppMode = NETWORK_NORMAL;
	}
	else if(fl_network_mode_status_u8 == COMM_SILENT_COMMUNICATION)
	{
		//fl_AppMode = NETWORK_STANDALONE;      
	}
	else if(fl_network_mode_status_u8 == COMM_NO_COMMUNICATION)
	{
		//fl_AppMode = NETWORK_SLEEP;
	}
	else
	{
		/* as per misra rule, NOP */
	}

	if(fl_Ign_IoHab_Status_S32 == (SInt32)IGNON_VALUE) /*Value 2 --> IGN ON, Value 1 is IGN OFF*/
	{
		//fl_Ctrl_Wss_Ign_Status_u8 = IgnOn;
	}
	else
	{
		//fl_Ctrl_Wss_Ign_Status_u8 = IgnOff;
	}

	//(void)Rte_Write_pp_SafetyAdapter_Ign_Substate_SafetyAdapter_Ign_Substate(fl_Ctrl_Wss_Ign_Status_u8);
	//(void)Rte_Write_pp_SafetyAdapter_Appmode_SafetyAdapter_AppMode(fl_AppMode);

}

/**************************  the below functions are used to read the can signal values and status *****************************************************/
FUNC(Std_ReturnType, Mdl_SafetyAdapter_CODE) Mdl_SafetyAdapter_RxCan_GetSafeSignalValue(tRxSafeSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_MDL_SAFETYADAPTER_APPL_VAR) pSignalValue, P2VAR(tRxSafeSignalStatus, AUTOMATIC, RTE_MDL_SAFETYADAPTER_APPL_VAR) pSignalStatus)
{
	tRxSafeSignalStatus l_Signal_status = 0;
	uint8 l_signal_value = 0;

    Mdl_SafetyAdapter_RxCan_GetSignalValue(SignalId,&l_signal_value, &l_Signal_status);
	*pSignalValue = l_signal_value;
	
	if((l_Signal_status & eSIGNAL_MISSING) == eSIGNAL_MISSING)
	{		
		*pSignalStatus = RTE_E_MAX_AGE_EXCEEDED;
	}
	else if((l_Signal_status & eSIGNAL_NEVER_RECEIVED)  == eSIGNAL_NEVER_RECEIVED)
	{
		*pSignalStatus = RTE_E_NEVER_RECEIVED;
	}
	else
	{
		*pSignalStatus = ((uint8)RTE_E_OK);
	}	

return E_OK;
}



/*---------------------------------------------------------------------------
Date              : 04-Jan-2023
CDSID             : uganapat
Traceability      : Story: 1687828
Change Description: Toyota 38xD IC: (technical story)ï¿½ - Functional Safety
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 05-Jan-2023
CDSID             : uganapat
Traceability      : Story: 1687828
Change Description: Toyota 38xD IC: (technical story)ï¿½ - Functional Safety
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 05-Jan-2023
CDSID             : uganapat
Traceability      : Story: 1687828
Change Description: Toyota 38xD IC: (technical story)ï¿½ - FS design change
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 24-MAY-2023
CDSID             : tjayaram
Traceability      : Story: 2018932,2015801
Change Description: Toyota 38xD IC: Misra warning fix
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 01-SEP-2023
CDSID             : bprasant
Traceability      : T38XD29284-22641- Coverity, misra and Certc warning analyzes and deviation -  Minor Fix Removal of Header Files
Change Description: Toyota 38xD IC: Misra warning fix
-----------------------------------------------------------------------------*/

