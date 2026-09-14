/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
*                                                                                                                   *
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                  *
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its      *
* rights under all copyright laws to protect this work as a published work, when appropriate.                       *
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it  *
* without the written authorization of Visteon Corporation.                                                         *
********************************************************************************************************************/
/*!*****************************************************************************************************************
*    @file ComAbsMdl.c
*    @ingroup ComAbsMdl
*    @brief This file implements the Abstraction for Com Rx and Tx signals between SWC's and the Com stack
*    Auto generated code in VTAMILAR at 2024-11-20 16:37:10.938021
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/

#include "ComAbsMdl.h"
#include "CmpLib.h"

/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
#define COMABSMDL_RXCAN_SIG_NR_BIT_POS                 		0U
#define COMABSMDL_RXCAN_SIG_MISSING_BIT_POS            		1U
#define COMABSMDL_RXCAN_SIG_INVALID_BIT_POS            		2U
#define COMABSMDL_RXCAN_SIG_RETENTION_BIT_POS            	3U
#define COMABSMDL_RXCAN_SIG_ISO_BIT_POS            	        4U


#define COMABSMDL_TXCAN_IS_KEEP_ALIVE_SUPPORTED(props)   (((props) & COMABSMDL_TXCAN_KEEP_ALIVE_BIT_ENABLED) == COMABSMDL_TXCAN_KEEP_ALIVE_BIT_ENABLED)
#define COMABSMDL_TXCAN_IS_CONFIRMATION_SUPPORTED(props) (((props) & COMABSMDL_TXCAN_CONFIRMATION_ENABLED) == COMABSMDL_TXCAN_CONFIRMATION_ENABLED)
#define COMABSMDL_TXCAN_IS_ISO_SUPPORTED(props)          (((props) & COMABSMDL_TXCAN_ISO_SUPPORTED) == COMABSMDL_TXCAN_ISO_SUPPORTED)

/********************************************************************************************************************
*  PRIVATE TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/
/* Rx Functions */
static void ComAbsMdl_RxCanSignalMissingProcessing(void);
static void ComAbsMdl_RxCanSignalInvalidProcessing(void);
static boolean ComAbsMdl_RxCanIsSignalMissing(tRxSignalId SignalId);
static boolean ComAbsMdl_RxCanIsSignalNR(tRxSignalId SignalId);
static boolean ComAbsMdl_RxCanIsSignalInvalid(tRxSignalId SignalId);
tRxSignalStatus ComAbsMdl_RxCanGetSignalStatus(tRxSignalId SignalId);
Std_ReturnType ComAbsMdl_RxCanSetSignalValue(tRxSignalId SignalId,const uint8 * pSignalValue);
static void ComAbsMdl_UtilMemSet(uint8 *pDest,uint8 Value,uint32 Length);
/* Tx Functions */


/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/
/* Buffers for Com Rx Signal */
uint8  ComAbsMdl_RxCanSigBufferU8[COMABSMDL_RXCAN_NUM_OF_U8_BUFFERS];
static uint16 ComAbsMdl_RxCanSigBufferU16[COMABSMDL_RXCAN_NUM_OF_U16_BUFFERS];
static uint32 ComAbsMdl_RxCanSigBufferU32[COMABSMDL_RXCAN_NUM_OF_U32_BUFFERS];
static uint8 ComAbsMdl_RxCanSigBufferU8NArr[COMABSMDL_RXCAN_NUM_OF_U8ARR_BUFFERS];
static uint32 ComAbsMdl_RxCanSigBufferU8ArrLength[COMABSMDL_RXCAN_NUM_OF_U8ARR_LENGTH_BUFFERS];

/* Com Rx signal buffer status */
static uint8 ComAbsMdl_RxCanSignalInvalidStatus[COMABS_RXCAN_NUM_OF_SIGNAL_INVALID_STATUS_BYTES];
static uint8 ComAbsMdl_RxCanIsSignalMissingEnabled[COMABSMDL_RXCAN_NUM_OF_MISSING_STATUS_BYTES];
static uint8 ComAbsMdl_RxCanIsSignalNREnabled[COMABSMDL_RXCAN_NUM_OF_NR_STATUS_BYTES];
static uint8 ComAbsMdl_RxCanIsSignalInvalidEnabled[COMABS_RXCAN_NUM_OF_SIGNAL_INVALID_STATUS_BYTES];
static uint32 ComAbsMdl_RxCanSignalMissingCounter[COMABSMDL_RXCAN_NUM_OF_MISSING_SIGNALS];
static uint32 ComAbsMdl_RxCanSignalInvalidCounter[COMABSMDL_RXCAN_NUM_OF_INVALID_SIGNALS];

/* Retention Buffers for Com Tx and Rx Signal */
#define COMABSMDL_BACKUP_RAM_SEC_START
#include "MemMap.h"
/* Retention Buffers for Com Rx signal */
uint8  ComAbsMdl_RxCanRetentionSigBufferU8[COMABSMDL_RXCAN_NUM_OF_U8_RETENTION_BUFFERS];
static uint16 ComAbsMdl_RxCanRetentionSigBufferU16[COMABSMDL_RXCAN_NUM_OF_U16_RETENTION_BUFFERS];
static uint32 ComAbsMdl_RxCanRetentionSigBufferU32[COMABSMDL_RXCAN_NUM_OF_U32_RETENTION_BUFFERS];
static uint8  ComAbsMdl_RxCanRetentionSigBufferU8Arr[COMABSMDL_RXCAN_NUM_OF_U8ARR_RETENTION_BUFFERS];
static uint32  ComAbsMdl_RxCanRetentionSigBufferU8ArrLength[COMABSMDL_RXCAN_NUM_OF_RETENTION_U8ARR_LENGTH_BUFFERS];

static uint8 ComAbsMdl_TxCanRetentionBufferU8[COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS];
static uint16 ComAbsMdl_TxCanRetentionBufferU16[COMABSMDL_TXCAN_NUM_OF_U16_BUFFERS];
static uint32 ComAbsMdl_TxCanRetentionBufferU32[COMABSMDL_TXCAN_NUM_OF_U32_BUFFERS];
static uint8 ComAbsMdl_CanTxRetentionBufferArr[COMABSMDL_TXCAN_NUM_OF_U8ARR_BUFFERS];
static uint32 ComAbsMdl_CanTxRetentionBufferU8ArrLength[COMABSMDL_TXCAN_NUM_OF_U8ARR_SIGNAL];
#define COMABSMDL_BACKUP_RAM_END
#include "MemMap.h"
/* Confirmation status for the transmit signal */
static uint8 ComAbsMdl_TxCanSignalConfirmStatus[COMABSMDL_TXCAN_NUM_OF_CONF_STATUS_BYTES];
//extern VAR(tResetReason, RTE_VAR_INIT) Rte_ModeMgr_ppSRModeResetReason_ResetReason;
extern uint8 ComAbsMdl_RxCanSignal_currentStatus[COMABSMDL_RXCAN_NUM_OF_NR_STATUS_BYTES];

/* @brief  Instance of life-cycle state-machine */
CMPLIB_INSTANCE(ComAbsMdl)

/* Public Function Implementation */
/* Tx Implementation */
/********************************************************************************************************************
*   @brief   Main function Runnable for the RxCanMdl. Should be called in every
*   \COMABSMDL_RXCAN_MAINFUNCTION_TIME_IN_MS. It process the missing and Invalid status
********************************************************************************************************************/
void CComAbsMdl_Impl_TxCanMdlMainFunction(void)
{

}

/********************************************************************************************************************
*   @brief   This method is used to set the Com Tx singal value from the retention buffer
*   @param[in] SignalId Tx signal id
********************************************************************************************************************/
Std_ReturnType CComAbsMdl_TxCan_SetSignalFromRetentionBuffer(tTxSignalId SignalId)
{
    Std_ReturnType ReturnStatus = E_NOT_OK;
    uint8* pTxSignalData = NULL_PTR;  /* Initialized to NULL */
    uint32 SignalLength = 0;
    ComAbsMdl_TxCanSignalConfigType const * pTxSignalConfig;
    ComAbsMdl_TxCanSetSignalFunctPtrType pTxSetSignalFunct;
	ComAbsMdl_TxCanSetSignalU8ArrFunctPtrType pTxSetSignalU8ArrFunct;

    if (SignalId < eEndOfTxSignal)
    {
        pTxSignalConfig = &ComAbsMdl_TxCanSignalConfig[SignalId];

        if(COMABSMDL_TXCAN_IS_KEEP_ALIVE_SUPPORTED(pTxSignalConfig->TxSigalProps))
        {
        	/* Get retention buffer */
            if ((pTxSignalConfig->SignalLengthInByte == 1U) &&
				(pTxSignalConfig->SignalBufferStartIdx < COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS))
            {
                pTxSignalData = &ComAbsMdl_TxCanRetentionBufferU8[pTxSignalConfig->SignalBufferStartIdx];
            }
            else if ((pTxSignalConfig->SignalLengthInByte == 2U) &&
            		(pTxSignalConfig->SignalBufferStartIdx < COMABSMDL_TXCAN_NUM_OF_U16_BUFFERS))
            {
                pTxSignalData = (uint8 *)&ComAbsMdl_TxCanRetentionBufferU16[pTxSignalConfig->SignalBufferStartIdx];
            }
            else if (((pTxSignalConfig->SignalLengthInByte > 2U) && (pTxSignalConfig->SignalLengthInByte <= 4U)) &&
            		(pTxSignalConfig->SignalBufferStartIdx < COMABSMDL_TXCAN_NUM_OF_U32_BUFFERS))
            {
                pTxSignalData = (uint8 *)&ComAbsMdl_TxCanRetentionBufferU32[pTxSignalConfig->SignalBufferStartIdx];
            }
            else if ((pTxSignalConfig->SignalBufferStartIdx < COMABSMDL_TXCAN_NUM_OF_U8ARR_BUFFERS) &&
                     (pTxSignalConfig->TxSetSignalIdx < CANABSMDL_TXCAN_NUM_OF_SET_SIG_U8ARR_FUNCT))
            {
                pTxSignalData = &ComAbsMdl_CanTxRetentionBufferArr[pTxSignalConfig->SignalBufferStartIdx];
                SignalLength = ComAbsMdl_CanTxRetentionBufferU8ArrLength[pTxSignalConfig->TxSetSignalIdx];
            }
            else
            {
                //donothing
            }
            /* Only proceed if pTxSignalData was successfully assigned */
            if (pTxSignalData != NULL_PTR)
            {
                if ((pTxSignalConfig->SignalLengthInByte <= 4U) &&
                    (pTxSignalConfig->TxSetSignalIdx < CANABSMDL_TXCAN_NUM_OF_SET_SIG_FUNCT))
                {
                    if (COMABSMDL_TXCAN_IS_ISO_SUPPORTED(pTxSignalConfig->TxSigalProps))
                    {
                        // ReturnStatus = CComAbsMdl_TxCan_SetIsoSignal(SignalId, pTxSignalData, pTxSignalConfig->SignalLengthInByte);
                    }
                    else
                    {
                        pTxSetSignalFunct = ComAbsMdl_TxCanSetSignalFunctPtrConfig[pTxSignalConfig->TxSetSignalIdx];
                        if (pTxSetSignalFunct != NULL_PTR)
                        {
                            ReturnStatus = (*pTxSetSignalFunct)(pTxSignalData);
                        }
                    }
                }
                else
                {
                    if (COMABSMDL_TXCAN_IS_ISO_SUPPORTED(pTxSignalConfig->TxSigalProps))
                    {
                        // ReturnStatus = CComAbsMdl_TxCan_SetIsoSignal(SignalId, pTxSignalData, SignalLength);
                    }
                    else
                    {
                        if (pTxSignalConfig->TxSetSignalIdx < CANABSMDL_TXCAN_NUM_OF_SET_SIG_U8ARR_FUNCT)
                        {
                            pTxSetSignalU8ArrFunct = ComAbsMdl_TxCanSetSignalU8ArrFunctPtrConfig[pTxSignalConfig->TxSetSignalIdx];
                            if (pTxSetSignalU8ArrFunct != NULL_PTR)
                            {
                                ReturnStatus = (*pTxSetSignalU8ArrFunct)(pTxSignalData, SignalLength);
                            }
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
Std_ReturnType CComAbsMdl_TxCan_SetSignalValue(tTxSignalId SignalId, uint8 *pTxSignalData)
{
    Std_ReturnType ReturnStatus = E_NOT_OK;
    ComAbsMdl_TxCanSignalConfigType const * pTxSignalConfig;
    ComAbsMdl_TxCanSetSignalFunctPtrType pTxSetSignalFunct;

    /* Input Validation */
    if ((SignalId < eEndOfTxSignal) && (pTxSignalData != NULL_PTR))
    {
        pTxSignalConfig = &ComAbsMdl_TxCanSignalConfig[SignalId];

        /* Check for back ram retention */
        if (COMABSMDL_TXCAN_IS_KEEP_ALIVE_SUPPORTED(pTxSignalConfig->TxSigalProps))
        {
            if ((pTxSignalConfig->SignalLengthInByte == 1U) &&
                (pTxSignalConfig->SignalBufferStartIdx < COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS))
            {
                ComAbsMdl_TxCanRetentionBufferU8[pTxSignalConfig->SignalBufferStartIdx] = *((uint8 *)pTxSignalData);
            }
            else if ((pTxSignalConfig->SignalLengthInByte == 2U) &&
                     (pTxSignalConfig->SignalBufferStartIdx < COMABSMDL_TXCAN_NUM_OF_U16_BUFFERS))
            {
                ComAbsMdl_TxCanRetentionBufferU16[pTxSignalConfig->SignalBufferStartIdx] = *((uint16 *)pTxSignalData);
            }
            else if (((pTxSignalConfig->SignalLengthInByte > 2U) && (pTxSignalConfig->SignalLengthInByte <= 4U)) &&
                     (pTxSignalConfig->SignalBufferStartIdx < COMABSMDL_TXCAN_NUM_OF_U32_BUFFERS))
            {
                ComAbsMdl_TxCanRetentionBufferU32[pTxSignalConfig->SignalBufferStartIdx] = *((uint32 *)pTxSignalData);
            }
            else
            {
                /* MISRA Rule 15.7: Final else required for if/else-if chain. 
                   Signal length not supported for retention or buffer index out of bounds. */
            }
        }
        else
        {
            //donothing
        }

        /* Invoke set functions */
        if (COMABSMDL_TXCAN_IS_ISO_SUPPORTED(pTxSignalConfig->TxSigalProps))
        {
            /* ReturnStatus = CComAbsMdl_TxCan_SetIsoSignal(SignalId, pTxSignalData, pTxSignalConfig->SignalLengthInByte); */
        }
        else
        {
            if ((pTxSignalConfig->SignalLengthInByte <= 4U) &&
                (pTxSignalConfig->TxSetSignalIdx < CANABSMDL_TXCAN_NUM_OF_SET_SIG_FUNCT))
            {
                pTxSetSignalFunct = ComAbsMdl_TxCanSetSignalFunctPtrConfig[pTxSignalConfig->TxSetSignalIdx];
                if (pTxSetSignalFunct != NULL_PTR)
                {
                    ReturnStatus = (*pTxSetSignalFunct)(pTxSignalData);
                }
                else
                {
                    //donothing
                }
            }
            else
            {
                //donothing
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
Std_ReturnType CComAbsMdl_TxCan_SetSignalValueU8Arr(tTxSignalId SignalId,uint8 *pTxSignalData,uint32 SignalLength)
{
	Std_ReturnType ReturnStatus = E_NOT_OK;
	ComAbsMdl_TxCanSignalConfigType const * pTxSignalConfig;
	ComAbsMdl_TxCanSetSignalU8ArrFunctPtrType pTxSetSignalU8ArrFunct;
	uint32 BuffIdx;

	if (SignalId < eEndOfTxSignal)
	{
		if (pTxSignalData != NULL_PTR)
		{
			/* check for back ram retention */
			pTxSignalConfig = &ComAbsMdl_TxCanSignalConfig[SignalId];
			if(COMABSMDL_TXCAN_IS_KEEP_ALIVE_SUPPORTED(pTxSignalConfig->TxSigalProps))
			{
				if (((pTxSignalConfig->SignalBufferStartIdx + SignalLength -1U) < COMABSMDL_TXCAN_NUM_OF_U8ARR_BUFFERS) &&
					(pTxSignalConfig->TxSetSignalIdx < CANABSMDL_TXCAN_NUM_OF_SET_SIG_U8ARR_FUNCT))
				{
					for (BuffIdx = 0;BuffIdx<SignalLength;BuffIdx++)
					{
						ComAbsMdl_CanTxRetentionBufferArr[pTxSignalConfig->SignalBufferStartIdx+BuffIdx] = pTxSignalData[BuffIdx];
					}
                    ComAbsMdl_CanTxRetentionBufferU8ArrLength[pTxSignalConfig->TxSetSignalIdx]=SignalLength;
				}
			}
			/* call corresponding signal */
            if (COMABSMDL_TXCAN_IS_ISO_SUPPORTED(pTxSignalConfig->TxSigalProps))
            {
               // ReturnStatus = CComAbsMdl_TxCan_SetIsoSignal(SignalId,pTxSignalData,SignalLength);
            }
            else
            {
                if (pTxSignalConfig->TxSetSignalIdx < CANABSMDL_TXCAN_NUM_OF_SET_SIG_U8ARR_FUNCT)
                {
                    pTxSetSignalU8ArrFunct= ComAbsMdl_TxCanSetSignalU8ArrFunctPtrConfig[pTxSignalConfig->TxSetSignalIdx];
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
void CComAbsMdl_TxCan_ClearCanSignalTxConfirmation(tTxSignalId SignalId)
{
    uint8 BytePosition;
	ComAbsMdl_TxCanSignalConfigType const * pTxSignalConfig;
    if (SignalId < eEndOfTxSignal)
    {
        BytePosition = SignalId>>3U;
        pTxSignalConfig = &ComAbsMdl_TxCanSignalConfig[SignalId];
        if((COMABSMDL_TXCAN_IS_CONFIRMATION_SUPPORTED(pTxSignalConfig->TxSigalProps)) &&
            (BytePosition < COMABSMDL_TXCAN_NUM_OF_CONF_STATUS_BYTES))
        {
            COMABSMDL_CLEAR_BIT(ComAbsMdl_TxCanSignalConfirmStatus[BytePosition],(SignalId & 0x7U));
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
void CComAbsMdl_TxCan_GetCanSignalTxConfirmation(tTxSignalId SignalId,tTxSigConfirmStatus *pStatus)
{
    uint8 BytePosition;
    ComAbsMdl_TxCanSignalConfigType const * pTxSignalConfig;
    tTxSigConfirmStatus Status = eTxSigConfirmStatus_NotSupported;
    if (SignalId < eEndOfTxSignal)
    {
        BytePosition = SignalId>>3U;
        pTxSignalConfig = &ComAbsMdl_TxCanSignalConfig[SignalId];
        if((COMABSMDL_TXCAN_IS_CONFIRMATION_SUPPORTED(pTxSignalConfig->TxSigalProps)) &&
            (BytePosition < COMABSMDL_TXCAN_NUM_OF_CONF_STATUS_BYTES))
        {
            if (TRUE == COMABSMDL_IS_BIT_SET(ComAbsMdl_TxCanSignalConfirmStatus[BytePosition],
                                             (uint8)(SignalId & 0x07U)))
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
void ComAbsMdl_TxCan_SetCanSignalTxConfirmation(tTxSignalId SignalId)
{
	uint8 BytePosition;
	ComAbsMdl_TxCanSignalConfigType const * pTxSignalConfig;

    if (SignalId < eEndOfTxSignal)
    {
        BytePosition = SignalId>>3U;
        pTxSignalConfig = &ComAbsMdl_TxCanSignalConfig[SignalId];
        if((COMABSMDL_TXCAN_IS_CONFIRMATION_SUPPORTED(pTxSignalConfig->TxSigalProps)) &&
            (BytePosition < COMABSMDL_TXCAN_NUM_OF_CONF_STATUS_BYTES))
        {
            COMABSMDL_SET_BIT(ComAbsMdl_TxCanSignalConfirmStatus[BytePosition],(SignalId & 0x7U));
        }
    }
}

/* Rx Implementation */
/********************************************************************************************************************
*   @brief   Main function Runnable for the ComAbsMdl. Should be called in every
*   \COMABSMDL_RXCAN_MAINFUNCTION_TIME_IN_MS. It process the missing and Invalid status
**************************************** ****************************************************************************/
void CComAbsMdl_Impl_RxCanMdlMainFunction(void)
{
	ComAbsMdl_RxCanSignalMissingProcessing();
	ComAbsMdl_RxCanSignalInvalidProcessing();
   // ComAbsMdl_RxIsoMainFunction();
}

/********************************************************************************************************************
*   @brief   This method is used to clear the signal just received status
*   @param[in] SignalId RX signal id
********************************************************************************************************************/
void CComAbsMdl_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId)
{
    uint8 BytePosition;

    if (SignalId < eEndOfRxSignal)
    {
        BytePosition = SignalId>>3U;
        if(BytePosition < COMABSMDL_RXCAN_NUM_OF_JUST_RCVD_STATUS_BYTES)
        {
            COMABSMDL_CLEAR_BIT(ComAbsMdl_RxCanJustRcvdStatus[BytePosition],(SignalId & 0x7U));
        }
    }
}


/********************************************************************************************************************
*   @brief   This method is used to get the signal just received status
*   @param[in] SignalId RX signal id
********************************************************************************************************************/
void CComAbsMdl_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus)
{
    tRxSignalJustRcvdStatus JustRcvdStatus=eNot_Just_Received;
    uint8 BytePosition;

    if (SignalId < eEndOfRxSignal)
    {
        BytePosition = SignalId>>3U;
        if (BytePosition < COMABSMDL_RXCAN_NUM_OF_JUST_RCVD_STATUS_BYTES)
        {
            if (TRUE == COMABSMDL_IS_BIT_SET(ComAbsMdl_RxCanJustRcvdStatus[BytePosition],
                                             (uint8)((uint32)SignalId & 0x07U)))
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
*				eSIGNAL_MISSING(0x64) : Signal missing status set
*				eSIGNAL_NEVER_RECEIVED(0x133) : Signal never received status set
*				eSIGNAL_INVALID(0x1): Signal invalid status set
*	@return Std_ReturnType status of the request.
*	E_OK :	request Supported
*	E_NOT_OK : request not supported
********************************************************************************************************************/
Std_ReturnType CComAbsMdl_RxCan_GetSignalValue(tRxSignalId SignalId,uint8 * pSignalValue,tRxSignalStatus *pSignalStatus)
{
    Std_ReturnType ReturnStatus = E_NOT_OK;
    tRxSignalStatus SigStatus = eSIGNAL_OK;
    boolean GetLocalBuffer = TRUE;
    boolean InvalidStatus = FALSE;
    boolean Skip_Invalid_Storage = FALSE;
    ComAbsMdl_RxCanSignalConfigType const *pSignalConfig;
    ComAbsMdl_RxCanSignalInvalidConfigType const * pSignalInvalidConfig;
    ComAbsMdl_RxCanGetSignalFunctPtrType pGetSignalFunction;
    uint32 ByteIndex;
    //ByteIndex = SignalId>>3U;

    if ((SignalId < eEndOfRxSignal) &&
        (pSignalValue != NULL_PTR) &&
        (pSignalStatus != NULL_PTR))
    {
        /* Get signal value */
        pSignalConfig = &ComAbsMdl_RxCanSignalConfig[SignalId];
        //SigStatus = ComAbsMdl_RxCanGetSignalStatus(SignalId);
        
        if (pSignalConfig->SignalInvalidIdx <  COMABSMDL_RXCAN_NUM_OF_INVALID_SIGNALS)
        {
          
          ByteIndex = pSignalConfig->SignalInvalidIdx >>3U;
          if (COMABSMDL_IS_BIT_SET(ComAbsMdl_RxCanSignalInvalidStatus[ByteIndex],
                                   (uint8)(pSignalConfig->SignalInvalidIdx & 0x07U)))
          {
              SigStatus |= eSIGNAL_INVALID;
          }
        }
        ByteIndex = (uint32)((uint32)SignalId >> 3U);
        if (COMABSMDL_IS_BIT_SET(ComAbsMdl_RxCanSignalNRStatus[ByteIndex], (uint8)((uint32)SignalId & 0x07U)))
        {
            SigStatus |= eSIGNAL_NEVER_RECEIVED;
        }

        if (COMABSMDL_IS_BIT_SET(ComAbsMdl_RxCanSignalMissingStatus[ByteIndex], (uint8)((uint32)SignalId & 0x07U)))
        {
            SigStatus |= eSIGNAL_MISSING;
        }

        /*check if the signal value has to be fetched from COM buffer or retention buffer */
        if (COMABSMDL_IS_BIT_SET(ComAbsMdl_RxCanSignal_currentStatus[ByteIndex], (uint8)((uint32)SignalId & 0x07U)))
        {
            /* Check and update the signal status */
            if (SigStatus == eSIGNAL_OK)
            {	
            	if (pSignalConfig->SignalGetFunctIdx < COMABSMDL_RXCAN_NUM_OF_GET_SIG_FUNCT)
		    	{
                   if ((TRUE == COMABSMDL_IS_BIT_SET(pSignalConfig->RxSigMonitoringType,COMABSMDL_RXCAN_SIG_INVALID_BIT_POS)) &&
                       (pSignalConfig->SignalInvalidIdx <  COMABSMDL_RXCAN_NUM_OF_INVALID_SIGNALS))   

			        {
                        pSignalInvalidConfig =&ComAbsMdl_RxCanSignalInvalidConfig[pSignalConfig->SignalInvalidIdx];
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
            		    pGetSignalFunction = ComAbsMdl_RxCanGetSignalFunctConfig[pSignalConfig->SignalGetFunctIdx].pGetSignalFunct;
		    	
		    		    if (pGetSignalFunction != NULL_PTR)
		    		    {
		    			    (*pGetSignalFunction)(pSignalValue);
		    			    /* Update local buffer */
		    			    ComAbsMdl_RxCanSetSignalValue(SignalId,pSignalValue);
                            COMABSMDL_CLEAR_BIT(ComAbsMdl_RxCanSignal_currentStatus[ByteIndex],(SignalId & 0x07U));
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
            if (FALSE != COMABSMDL_IS_BIT_SET(pSignalConfig->RxSigMonitoringType,COMABSMDL_RXCAN_SIG_RETENTION_BIT_POS))
            {
                if ((pSignalConfig->SignalLengthInByte == 1U) &&
        				(pSignalConfig->SignalBufferStartIdx < COMABSMDL_RXCAN_NUM_OF_U8_RETENTION_BUFFERS))
                {
                    *((uint8 *)pSignalValue) = ComAbsMdl_RxCanRetentionSigBufferU8[pSignalConfig->SignalBufferStartIdx];
                }
                else if((pSignalConfig->SignalLengthInByte == 2U) &&
                        (pSignalConfig->SignalBufferStartIdx < COMABSMDL_RXCAN_NUM_OF_U16_RETENTION_BUFFERS))
                {
                    *((uint16 *)pSignalValue) = ComAbsMdl_RxCanRetentionSigBufferU16[pSignalConfig->SignalBufferStartIdx];
                }
                else if(((pSignalConfig->SignalLengthInByte > 2U) && (pSignalConfig->SignalLengthInByte <= 4U)) &&
                        (pSignalConfig->SignalBufferStartIdx < COMABSMDL_RXCAN_NUM_OF_U32_RETENTION_BUFFERS))
                {
                    *((uint32 *)pSignalValue) = ComAbsMdl_RxCanRetentionSigBufferU32[pSignalConfig->SignalBufferStartIdx];
                }
                else
                {
                    ReturnStatus = E_NOT_OK;
                }
            }
            else
            {
                if ((pSignalConfig->SignalLengthInByte == 1U) &&
        				(pSignalConfig->SignalBufferStartIdx < COMABSMDL_RXCAN_NUM_OF_U8_BUFFERS))
                {
                    *((uint8 *)pSignalValue) = ComAbsMdl_RxCanSigBufferU8[pSignalConfig->SignalBufferStartIdx];
                }
                else if((pSignalConfig->SignalLengthInByte == 2U) &&
                        (pSignalConfig->SignalBufferStartIdx < COMABSMDL_RXCAN_NUM_OF_U16_BUFFERS))
                {
                    *((uint16 *)pSignalValue) = ComAbsMdl_RxCanSigBufferU16[pSignalConfig->SignalBufferStartIdx];
                }
                else if(((pSignalConfig->SignalLengthInByte > 2U) && (pSignalConfig->SignalLengthInByte <= 4U)) &&
                        (pSignalConfig->SignalBufferStartIdx < COMABSMDL_RXCAN_NUM_OF_U32_BUFFERS))
                {
                    *((uint32 *)pSignalValue) = ComAbsMdl_RxCanSigBufferU32[pSignalConfig->SignalBufferStartIdx];
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
*				eSIGNAL_MISSING(0x64) : Signal missing status set
*				eSIGNAL_NEVER_RECEIVED(0x133) : Signal never received status set
*				eSIGNAL_INVALID(0x1): Signal invalid status set
*	@param[out] pSignalLength pointer to which the received Rx signal length to be copied.
*	@return Std_ReturnType status of the request.
*	E_OK :	request Supported
*	E_NOT_OK : request not supported
********************************************************************************************************************/
Std_ReturnType CComAbsMdl_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId,uint8 * pSignalValue,
												tRxSignalStatus *pSignalStatus,uint32 *pSignalLength)
{
    Std_ReturnType ReturnStatus = E_NOT_OK;
    uint32 ByteIndex;
    uint16 LengthBufferIdx = 0U;
    tRxSignalStatus SigStatus = eSIGNAL_OK;
    boolean GetLocalBuffer = TRUE;
    ComAbsMdl_RxCanSignalConfigType const *pSignalConfig;
    ComAbsMdl_RxCanGetSignalU8ArrFunctPtrType pGetSignalU8ArrFunction;

    if ((SignalId < eEndOfRxSignal) &&
        (pSignalValue != NULL_PTR) &&
        (pSignalStatus != NULL_PTR))
    {
        /* Get signal value */
        pSignalConfig = &ComAbsMdl_RxCanSignalConfig[SignalId];

        if (pSignalConfig->SignalInvalidIdx < COMABSMDL_RXCAN_NUM_OF_INVALID_SIGNALS)
        {
            uint8 byteIndex = (uint8)(pSignalConfig->SignalInvalidIdx >> 3U);
            if (byteIndex < COMABS_RXCAN_NUM_OF_SIGNAL_INVALID_STATUS_BYTES)
            {
                if (COMABSMDL_IS_BIT_SET(ComAbsMdl_RxCanSignalInvalidStatus[byteIndex],
                                         (uint8)(pSignalConfig->SignalInvalidIdx & 0x07U)))
                {
                    SigStatus |= eSIGNAL_INVALID;
                }
            }
        }

        ByteIndex = (uint32)((uint32)SignalId >> 3U);
        if (COMABSMDL_IS_BIT_SET(ComAbsMdl_RxCanSignalNRStatus[ByteIndex], (uint8)((uint32)SignalId & 0x07U)))
        {
            SigStatus |= eSIGNAL_NEVER_RECEIVED;
        }

        if (COMABSMDL_IS_BIT_SET(ComAbsMdl_RxCanSignalMissingStatus[ByteIndex], (uint8)((uint32)SignalId & 0x07U)))
        {
            SigStatus |= eSIGNAL_MISSING;
        }
        /* Check and update the signal status */
        if (SigStatus == eSIGNAL_OK)
        {
        	/* Get signal from Com Buffer */
        	if (pSignalConfig->SignalGetFunctIdx < COMABSMDL_RXCAN_NUM_OF_U8ARR_SIG_CFG)
        	{
        		pGetSignalU8ArrFunction = ComAbsMdl_RxCanGetSignalU8ArrConfig[pSignalConfig->SignalGetFunctIdx].pGetSignalU8ArrFunct;
        		if (pGetSignalU8ArrFunction!= NULL_PTR)
        		{
        			(*pGetSignalU8ArrFunction)(pSignalValue,pSignalLength);
        			/* Update local buffer */
        			(void)ComAbsMdl_RxCanSetSignalValueU8Arr(SignalId,pSignalValue,pSignalLength);
                    COMABSMDL_CLEAR_BIT(ComAbsMdl_RxCanSignal_currentStatus[ByteIndex],(SignalId & 0x07U));
        			GetLocalBuffer = FALSE;
        		}
        	}
        }

        if (GetLocalBuffer != FALSE)
        {
            /* Get Signal from the local buffer where init value for the missing, never received and invalid is updated */
            if (FALSE != COMABSMDL_IS_BIT_SET(pSignalConfig->RxSigMonitoringType, COMABSMDL_RXCAN_SIG_RETENTION_BIT_POS))
            {
                if (pSignalConfig->SignalGetFunctIdx < COMABSMDL_RXCAN_NUM_OF_U8ARR_SIG_CFG)
                {
                    LengthBufferIdx = ComAbsMdl_RxCanGetSignalU8ArrConfig[pSignalConfig->SignalGetFunctIdx].SignalU8ArrBufferLenIdx;
                    if (LengthBufferIdx < COMABSMDL_RXCAN_NUM_OF_RETENTION_U8ARR_LENGTH_BUFFERS)
                    {
                        *pSignalLength = (uint32)ComAbsMdl_RxCanRetentionSigBufferU8ArrLength[LengthBufferIdx];
                    }
                    else
                    {
                        *pSignalLength = 0U;
                    }
                    for (ByteIndex = 0U; 
                         ((ByteIndex < (*pSignalLength)) &&
                          (((uint32)ByteIndex + (uint32)pSignalConfig->SignalLengthInByte - 1U) < COMABSMDL_RXCAN_NUM_OF_U8ARR_RETENTION_BUFFERS)); 
                         ByteIndex++)
                    {
                        pSignalValue[ByteIndex] = ComAbsMdl_RxCanRetentionSigBufferU8Arr[(uint32)ByteIndex + (uint32)pSignalConfig->SignalBufferStartIdx];
                    }
                }
            }
            else
            {
                if (pSignalConfig->SignalGetFunctIdx < COMABSMDL_RXCAN_NUM_OF_U8ARR_SIG_CFG)
                {
                    LengthBufferIdx = ComAbsMdl_RxCanGetSignalU8ArrConfig[pSignalConfig->SignalGetFunctIdx].SignalU8ArrBufferLenIdx;
                    if (LengthBufferIdx < COMABSMDL_RXCAN_NUM_OF_U8ARR_LENGTH_BUFFERS)
                    {
                        *pSignalLength = (uint32)ComAbsMdl_RxCanSigBufferU8ArrLength[LengthBufferIdx];
                    }
                    else
                    {
                        *pSignalLength = 0U;
                    }
                    for (ByteIndex = 0U; 
                         ((ByteIndex < (*pSignalLength)) &&
                          (((uint32)ByteIndex + (uint32)pSignalConfig->SignalLengthInByte - 1U) < COMABSMDL_RXCAN_NUM_OF_U8ARR_BUFFERS)); 
                         ByteIndex++)
                    {
                        pSignalValue[ByteIndex] = ComAbsMdl_RxCanSigBufferU8NArr[(uint32)ByteIndex + (uint32)pSignalConfig->SignalBufferStartIdx];
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
void CComAbsMdl_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId,boolean Status)
{
    uint32 ByteIndex;
    ComAbsMdl_RxCanSignalConfigType const *pSignalConfig;

    if (SignalId < eEndOfRxSignal)
    {
    	pSignalConfig = &ComAbsMdl_RxCanSignalConfig[SignalId];
        ByteIndex = SignalId>>3U;
        /* Check for missing monitoring support */
        if ((TRUE == COMABSMDL_IS_BIT_SET(pSignalConfig->RxSigMonitoringType,COMABSMDL_RXCAN_SIG_MISSING_BIT_POS)) &&
            (ByteIndex <  COMABSMDL_RXCAN_NUM_OF_MISSING_STATUS_BYTES))
        {
            if (Status == TRUE)
            {
                COMABSMDL_SET_BIT(ComAbsMdl_RxCanIsSignalMissingEnabled[ByteIndex],(SignalId & 0x07U));
                ComAbsMdl_RxCanSignalMissingCounter[SignalId] = pSignalConfig->SignalMissingCounterValue;

            }
            else
            {
                COMABSMDL_CLEAR_BIT(ComAbsMdl_RxCanIsSignalMissingEnabled[ByteIndex],(SignalId & 0x07U));
                ComAbsMdl_RxCanSignalMissingCounter[SignalId] = 0u;

                /*! Set Timer to Zero */
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
void CComAbsMdl_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId,boolean Status)
{
    uint32 ByteIndex;
    ComAbsMdl_RxCanSignalConfigType  const * pSignalConfig;
    ComAbsMdl_RxCanSignalInvalidConfigType const *pSignalInvalidConfig;

    if (SignalId < eEndOfRxSignal)
    {
        pSignalConfig = &ComAbsMdl_RxCanSignalConfig[SignalId];
        if ((TRUE == COMABSMDL_IS_BIT_SET(pSignalConfig->RxSigMonitoringType,COMABSMDL_RXCAN_SIG_INVALID_BIT_POS)) &&
           (pSignalConfig->SignalInvalidIdx <  COMABSMDL_RXCAN_NUM_OF_INVALID_SIGNALS))
        {
            ByteIndex = pSignalConfig->SignalInvalidIdx>>3U;
            if ((ByteIndex < COMABS_RXCAN_NUM_OF_SIGNAL_INVALID_STATUS_BYTES) &&
				(pSignalConfig->SignalInvalidIdx < COMABSMDL_RXCAN_NUM_OF_INVALID_SIGNALS))
            {
            	pSignalInvalidConfig = &ComAbsMdl_RxCanSignalInvalidConfig[pSignalConfig->SignalInvalidIdx];
            	if (Status == TRUE)
				{
					COMABSMDL_SET_BIT(ComAbsMdl_RxCanIsSignalInvalidEnabled[ByteIndex],(pSignalConfig->SignalInvalidIdx & 0x07U));
				}
				else
				{
					COMABSMDL_CLEAR_BIT(ComAbsMdl_RxCanIsSignalInvalidEnabled[ByteIndex],(pSignalConfig->SignalInvalidIdx & 0x07U));
					/* clear the timer */
					ComAbsMdl_RxCanSignalInvalidCounter[pSignalConfig->SignalInvalidIdx] = pSignalInvalidConfig->SignalInvalidCounterValue;
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
void CComAbsMdl_RxCan_SignalNRProcessingControl(tRxSignalId SignalId,boolean Status)
{
    uint32 ByteIndex;
    if (SignalId < eEndOfRxSignal)
    {
        ByteIndex = SignalId>>3U;
        if (ByteIndex <  COMABSMDL_RXCAN_NUM_OF_MISSING_STATUS_BYTES)
        {
            if (Status == TRUE)
            {
            	/* Set the NR monitoring status enable flag to 1 */
                COMABSMDL_SET_BIT(ComAbsMdl_RxCanIsSignalNREnabled[SignalId>>3U],(SignalId & 0x07U));
                /* Set the NR flag to 1 */
                COMABSMDL_SET_BIT(ComAbsMdl_RxCanSignalNRStatus[SignalId>>3U],(SignalId & 0x07U));
            }
            else
            {
            	/* clear the NR monitoring status enable flag  */
                COMABSMDL_CLEAR_BIT(ComAbsMdl_RxCanIsSignalNREnabled[SignalId>>3U],(SignalId & 0x07U));
                /* Set the NR flag to 0 */
                COMABSMDL_CLEAR_BIT(ComAbsMdl_RxCanSignalNRStatus[SignalId>>3U],(SignalId & 0x07U));
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
Std_ReturnType CComAbsMdl_RxCan_SetSignalInitValue(tRxSignalId SignalId,uint8 * pSignalValue)
{
   return ComAbsMdl_RxCanSetSignalValue(SignalId,pSignalValue);
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
Std_ReturnType CComAbsMdl_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId,uint8 * pSignalValue,uint32 *pSignalLength)
{
	return ComAbsMdl_RxCanSetSignalValueU8Arr(SignalId,pSignalValue,pSignalLength);
}

/********************************************************************************************************************
*   @brief     This method is used to reset the missing timer
*   @param[in] SignalId		Signal Id
********************************************************************************************************************/
void ComAbsMdl_ReloadMissingTimer(tRxSignalId SignalId)
{
	ComAbsMdl_RxCanSignalConfigType const * pSignalConfig;

    if (SignalId < eEndOfRxSignal)
	{
		pSignalConfig = &ComAbsMdl_RxCanSignalConfig[SignalId];
        /* Check the timer count */
        ComAbsMdl_RxCanSignalMissingCounter[SignalId] = pSignalConfig->SignalMissingCounterValue;
        COMABSMDL_CLEAR_BIT(ComAbsMdl_RxCanSignalMissingStatus[SignalId>>3U],(SignalId & 0x07U));
    }

}

/* Local Functions */
/********************************************************************************************************************
*   @brief     Transitional initialization state
*   @return E_OK:           Succeed
********************************************************************************************************************/
static Std_ReturnType CmpInit( void )
{
	return E_OK;
}

/********************************************************************************************************************
*   @brief     Transitional de-initialization state
*   @return E_OK:           Succeed
********************************************************************************************************************/
static Std_ReturnType CmpDeInit( void )
{
     return E_OK;
}

/********************************************************************************************************************
*   @brief     Transitional activation state
*   @return E_OK:           Succeed
*   <br>     E_NOT_READY:    In progress. Keeps the component in this state.
*   <br>     E_NOT_OK:       Failed
********************************************************************************************************************/
static Std_ReturnType CmpActivation( void )
{
	ComAbsMdl_RxCanVarInit();
	
	//Initialize the buffer values and status flags on bettery connect
/*	if (Rte_ModeMgr_ppSRModeResetReason_ResetReason == 0)  
	{
		
	}*/	
    ComAbsMdl_TxCanVarInit();
    return E_OK;
}

/********************************************************************************************************************
*   @brief     Transitional de-activation  state
*   @return E_OK:           Succeed
*   <br>     E_NOT_READY:    In progress. Keeps the component in this state.
*   <br>     E_NOT_OK:       Failed
********************************************************************************************************************/
static Std_ReturnType CmpDeActivation( void )
{
     return  E_OK;
}

/********************************************************************************************************************
*   @brief     State for normal operations
*   @return The return value is disregarded. Say E_OK
********************************************************************************************************************/
static Std_ReturnType CmpActive(void)
{
	return (E_OK);
}

/********************************************************************************************************************
*   @brief     Diagnostic state
*   @return E_OK:           Diagnostic has completed. Go to DiagReturn state.
*   br>     E_NOT_READY:    Keeps the component in this state.
********************************************************************************************************************/
static Std_ReturnType CmpDiag( void )
{
     return E_OK;
}


/********************************************************************************************************************
*   @brief     Transitional state to clean up after diagnostic state. Component behavior to be restored.
*   @return E_OK:           Diagnostic clean-up has completed. Return to the previous state (Active or Inactive).
*   <br>     E_NOT_READY:    Keeps the component in this state.
********************************************************************************************************************/
static Std_ReturnType CmpDiagReturn( void )
{
     return E_OK;
}

/********************************************************************************************************************
*   @brief   This method is used to initialize variables in the TxCanMdl
********************************************************************************************************************/
void ComAbsMdl_TxCanVarInit(void)
{
	ComAbsMdl_UtilMemSet(&ComAbsMdl_TxCanRetentionBufferU8[0],0,COMABSMDL_TXCAN_NUM_OF_U8_BUFFERS);
	ComAbsMdl_UtilMemSet((uint8 *)&ComAbsMdl_TxCanRetentionBufferU16[0],0,COMABSMDL_TXCAN_NUM_OF_U16_BUFFERS*2);
	ComAbsMdl_UtilMemSet((uint8 *)&ComAbsMdl_TxCanRetentionBufferU32[0],0,COMABSMDL_TXCAN_NUM_OF_U32_BUFFERS*4);
	ComAbsMdl_UtilMemSet(&ComAbsMdl_CanTxRetentionBufferArr[0],0,COMABSMDL_TXCAN_NUM_OF_U8ARR_BUFFERS);
	ComAbsMdl_UtilMemSet((uint8 *)&ComAbsMdl_CanTxRetentionBufferU8ArrLength[0],0,COMABSMDL_TXCAN_NUM_OF_U8ARR_SIGNAL*4);
	ComAbsMdl_UtilMemSet(&ComAbsMdl_TxCanSignalConfirmStatus[0],0,COMABSMDL_TXCAN_NUM_OF_CONF_STATUS_BYTES);
}

/********************************************************************************************************************
*   @brief   This method is used to initialize variables in the ComAbsMdl
********************************************************************************************************************/
void ComAbsMdl_RxCanVarInit(void)
{
	
	uint16 SignalInvalidIdx = 0;
	tRxSignalId SignalId = 0;
	uint16 ByteIndex = 0;
	ComAbsMdl_RxCanSignalInvalidConfigType const *pSignalInvalidConfig;
	
	//reload the invalid counter and initialize InvalidStatus and Invalidenabled.
	for (SignalInvalidIdx = 0U; SignalInvalidIdx < COMABSMDL_RXCAN_NUM_OF_INVALID_SIGNALS ;SignalInvalidIdx++)
	{
		pSignalInvalidConfig =&ComAbsMdl_RxCanSignalInvalidConfig[SignalInvalidIdx];
		SignalId = pSignalInvalidConfig->SignalInvalidSigIdx;
		ByteIndex = SignalInvalidIdx >> 3U;
		ComAbsMdl_RxCanSignalInvalidCounter[SignalInvalidIdx] = pSignalInvalidConfig->SignalInvalidCounterValue;
		ComAbsMdl_RxCanSignalInvalidStatus[ByteIndex] = 0;
		ComAbsMdl_RxCanIsSignalInvalidEnabled[ByteIndex] = 0;
	}
	
	//initialize the timers counters and missing related variables
	for (SignalId = 0U; SignalId < eEndOfRxSignal ;SignalId++)
	{	
       ComAbsMdl_ReloadMissingTimer(SignalId);
	}   
	   	
	/* initialize the buffers */
	ComAbsMdl_UtilMemSet(&ComAbsMdl_RxCanSigBufferU8[0],0U,COMABSMDL_RXCAN_NUM_OF_U8_BUFFERS);
	ComAbsMdl_UtilMemSet((uint8 *)&ComAbsMdl_RxCanSigBufferU16[0],0U,COMABSMDL_RXCAN_NUM_OF_U16_BUFFERS*2);
	ComAbsMdl_UtilMemSet((uint8 *)&ComAbsMdl_RxCanSigBufferU32[0],0U,COMABSMDL_RXCAN_NUM_OF_U16_BUFFERS*4);
	ComAbsMdl_UtilMemSet(&ComAbsMdl_RxCanSigBufferU8NArr[0],0U,COMABSMDL_RXCAN_NUM_OF_U8ARR_BUFFERS);
	ComAbsMdl_UtilMemSet((uint8 *)&ComAbsMdl_RxCanSigBufferU8ArrLength[0],0U,COMABSMDL_RXCAN_NUM_OF_U8ARR_LENGTH_BUFFERS*2);

	/* Initialize the status flags */
	ComAbsMdl_UtilMemSet(&ComAbsMdl_RxCanSignal_currentStatus[0],0x00U,COMABSMDL_RXCAN_NUM_OF_NR_STATUS_BYTES);
	ComAbsMdl_UtilMemSet(&ComAbsMdl_RxCanJustRcvdStatus[0],0U,COMABSMDL_RXCAN_NUM_OF_JUST_RCVD_STATUS_BYTES);
	/* Initialize the status enable flags */
	ComAbsMdl_UtilMemSet(&ComAbsMdl_RxCanIsSignalMissingEnabled[0],0x0U,COMABSMDL_RXCAN_NUM_OF_MISSING_STATUS_BYTES);
	ComAbsMdl_UtilMemSet(&ComAbsMdl_RxCanIsSignalNREnabled[0],0xFFU,COMABSMDL_RXCAN_NUM_OF_NR_STATUS_BYTES);	
			            						            			
}


/********************************************************************************************************************
*   @brief   This method is used to process the missing signal status
********************************************************************************************************************/
static void ComAbsMdl_RxCanSignalMissingProcessing(void)
{
	tRxSignalId SignalId;
	uint32 ByteIndex;

	for (SignalId = 0;SignalId < eEndOfRxSignal;SignalId++)
	{
		ByteIndex = SignalId>>3U;
		/* Missing processsing enabled */

		if ((TRUE == COMABSMDL_IS_BIT_SET(ComAbsMdl_RxCanIsSignalMissingEnabled[ByteIndex],(SignalId & 0x07U))))

		{
			/* Check the timer count */
			if (ComAbsMdl_RxCanSignalMissingCounter[SignalId] >0U)
			{
				ComAbsMdl_RxCanSignalMissingCounter[SignalId]--;
				if (ComAbsMdl_RxCanSignalMissingCounter[SignalId] == 0U)
				{
					COMABSMDL_SET_BIT(ComAbsMdl_RxCanSignalMissingStatus[ByteIndex],(SignalId & 0x07U));
                    COMABSMDL_CLEAR_BIT(ComAbsMdl_RxCanJustRcvdStatus[ByteIndex],(SignalId & 0x7U));
				}
			}
		}
	}
}

/********************************************************************************************************************
*   @brief   This is method is used to process the invalid status
********************************************************************************************************************/
static void ComAbsMdl_RxCanSignalInvalidProcessing(void)
{
	uint32 SignalInvalidIdx;
	tRxSignalId SignalId;
	uint32 ByteIndex;
	ComAbsMdl_RxCanSignalInvalidConfigType const * pSignalInvalidConfig;
	boolean InvalidStatus = FALSE;

	for (SignalInvalidIdx = 0U; SignalInvalidIdx < COMABSMDL_RXCAN_NUM_OF_INVALID_SIGNALS ;SignalInvalidIdx++)
	{
		pSignalInvalidConfig =&ComAbsMdl_RxCanSignalInvalidConfig[SignalInvalidIdx];
		SignalId = pSignalInvalidConfig->SignalInvalidSigIdx;
		ByteIndex = SignalInvalidIdx >> 3U;

		if (SignalId < eEndOfRxSignal)
		{
			/* Invalid processing enabled */
			if ((TRUE == COMABSMDL_IS_BIT_SET(ComAbsMdl_RxCanIsSignalInvalidEnabled[ByteIndex],(SignalInvalidIdx & 0x7U) )) &&
				((ComAbsMdl_RxCanIsSignalNR(SignalId) != TRUE)))
			{
				/* check if the received signal is Invalid */
				if (pSignalInvalidConfig->pSignalInvalidCheckFunc != NULL_PTR)
				{
					InvalidStatus = pSignalInvalidConfig->pSignalInvalidCheckFunc();
				}

				if (InvalidStatus != FALSE)
				{
                    if ((FALSE == COMABSMDL_IS_BIT_SET(ComAbsMdl_RxCanSignalInvalidStatus[ByteIndex],(SignalInvalidIdx & 0x07U))) &&
                        (ComAbsMdl_RxCanSignalInvalidCounter[SignalInvalidIdx] == 0U))
					{
                        /* Reload timer */
                        ComAbsMdl_RxCanSignalInvalidCounter[SignalInvalidIdx] = pSignalInvalidConfig->SignalInvalidCounterValue;
                    }

                    if (ComAbsMdl_RxCanSignalInvalidCounter[SignalInvalidIdx] > 0U)
                    {
                        ComAbsMdl_RxCanSignalInvalidCounter[SignalInvalidIdx]--;
                        if (ComAbsMdl_RxCanSignalInvalidCounter[SignalInvalidIdx] == 0U)
                        {
                            COMABSMDL_SET_BIT(ComAbsMdl_RxCanSignalInvalidStatus[ByteIndex],(SignalInvalidIdx & 0x07U));
                        }
                    }
				}
				else
				{
					ComAbsMdl_RxCanSignalInvalidCounter[SignalInvalidIdx] = 0U;
					/* Clear status */
					COMABSMDL_CLEAR_BIT(ComAbsMdl_RxCanSignalInvalidStatus[ByteIndex],(SignalInvalidIdx & 0x07U));
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
static boolean ComAbsMdl_RxCanIsSignalMissing(tRxSignalId SignalId)
{
    uint32 ByteIndex;
    boolean status = FALSE;
    ByteIndex = SignalId>>3U;
    if (ByteIndex <  COMABSMDL_RXCAN_NUM_OF_MISSING_STATUS_BYTES)
    {
        status = COMABSMDL_IS_BIT_SET(ComAbsMdl_RxCanSignalMissingStatus[ByteIndex],(SignalId & 0x07U));
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
static boolean ComAbsMdl_RxCanIsSignalNR(tRxSignalId SignalId)
{
    uint32 ByteIndex;
    boolean status = FALSE;
    ByteIndex = SignalId>>3U;
    if (ByteIndex <  COMABSMDL_RXCAN_NUM_OF_NR_STATUS_BYTES)
    {
        status = COMABSMDL_IS_BIT_SET(ComAbsMdl_RxCanSignalNRStatus[ByteIndex],(SignalId & 0x07U));
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
static boolean ComAbsMdl_RxCanIsSignalInvalid(tRxSignalId SignalId)
{
    boolean status = FALSE;
    uint32 ByteIndex;
    ComAbsMdl_RxCanSignalConfigType  const * pSignalConfig;
    pSignalConfig = &ComAbsMdl_RxCanSignalConfig[SignalId];
    if (pSignalConfig->SignalInvalidIdx <  COMABSMDL_RXCAN_NUM_OF_INVALID_SIGNALS)
	{
    	ByteIndex = pSignalConfig->SignalInvalidIdx >>3U;
		if (ByteIndex < COMABS_RXCAN_NUM_OF_SIGNAL_INVALID_STATUS_BYTES)
		{
			status = COMABSMDL_IS_BIT_SET(ComAbsMdl_RxCanSignalInvalidStatus[ByteIndex],(pSignalConfig->SignalInvalidIdx & 0x07U));
		}
	}
    return status;
}

/********************************************************************************************************************
*   @brief   This method is used to get the status of the signal
*   @param[in] SignalId
*   @return tRxSignalStatus  status of the signal .Below Bit value represents the
*	Signal status
*				eSIGNAL_OK(0x0) : No fault occurred
*				eSIGNAL_MISSING(0x64) : Signal missing status set
*				eSIGNAL_NEVER_RECEIVED(0x133) : Signal never received status set
*				eSIGNAL_INVALID(0x1): Signal invalid status set
********************************************************************************************************************/
tRxSignalStatus ComAbsMdl_RxCanGetSignalStatus(tRxSignalId SignalId)
{
	tRxSignalStatus SigStatus = eSIGNAL_OK;

	if (ComAbsMdl_RxCanIsSignalNR(SignalId) == TRUE)
	{
		SigStatus |= eSIGNAL_NEVER_RECEIVED;
	}

	if (ComAbsMdl_RxCanIsSignalMissing(SignalId) == TRUE)
	{
		SigStatus |= eSIGNAL_MISSING;
	}

	if (ComAbsMdl_RxCanIsSignalInvalid(SignalId) == TRUE)
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
*   @return tRxSignalStatus  status of the request.
*	E_OK		Request accepted
*	E_NOT_OK	Request not accepted
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_RxCanSetSignalValueU8Arr(tRxSignalId SignalId, const uint8 * pSignalValue, const uint32 *pSignalLength)
{
	Std_ReturnType ReturnStatus = E_NOT_OK;
	uint32 ByteIndex;
    uint16 BufferLength=0;
	ComAbsMdl_RxCanSignalConfigType const * pSignalConfig;

	if ((SignalId < eEndOfRxSignal) &&
		(pSignalValue != NULL_PTR) &&
		(pSignalLength != NULL_PTR))
	{
		pSignalConfig = &ComAbsMdl_RxCanSignalConfig[SignalId];
        /* pSignalConfig->SignalGetFunctIdx is same as the number of U8Arr signal */
		if (pSignalConfig->SignalGetFunctIdx < COMABSMDL_RXCAN_NUM_OF_U8ARR_SIG_CFG)
		{
            BufferLength = ComAbsMdl_RxCanGetSignalU8ArrConfig[pSignalConfig->SignalGetFunctIdx].SignalU8ArrBufferLenIdx;
            if (FALSE != COMABSMDL_IS_BIT_SET(pSignalConfig->RxSigMonitoringType,COMABSMDL_RXCAN_SIG_RETENTION_BIT_POS))
            {
                if (BufferLength < COMABSMDL_RXCAN_NUM_OF_RETENTION_U8ARR_LENGTH_BUFFERS)
                {
                    ComAbsMdl_RxCanRetentionSigBufferU8ArrLength[BufferLength] = *pSignalLength;
                    for(ByteIndex = 0;((ByteIndex < (*pSignalLength)) &&
                         ((ByteIndex+pSignalConfig->SignalLengthInByte-1U) < COMABSMDL_RXCAN_NUM_OF_U8ARR_RETENTION_BUFFERS));ByteIndex++)
                    {
                        ComAbsMdl_RxCanRetentionSigBufferU8Arr[ByteIndex+pSignalConfig->SignalBufferStartIdx] = pSignalValue[ByteIndex];
                    }
                }
            }
            else
            {
                if (BufferLength < COMABSMDL_RXCAN_NUM_OF_U8ARR_LENGTH_BUFFERS)
                {
                    ComAbsMdl_RxCanSigBufferU8ArrLength[BufferLength] = *pSignalLength;
                    for(ByteIndex = 0;((ByteIndex < (*pSignalLength)) &&
                        ((ByteIndex+pSignalConfig->SignalLengthInByte-1U) < COMABSMDL_RXCAN_NUM_OF_U8ARR_BUFFERS));ByteIndex++)
                    {
                        ComAbsMdl_RxCanSigBufferU8NArr[ByteIndex+pSignalConfig->SignalBufferStartIdx] = pSignalValue[ByteIndex];
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
*   @return tRxSignalStatus  status of the request.
*	E_OK		Request accepted
*	E_NOT_OK	Request not accepted
********************************************************************************************************************/
Std_ReturnType ComAbsMdl_RxCanSetSignalValue(tRxSignalId SignalId,const uint8 * pSignalValue)
{
	Std_ReturnType ReturnStatus = E_OK;
	ComAbsMdl_RxCanSignalConfigType const * pSignalConfig;

	if ((SignalId < eEndOfRxSignal) &&
		(pSignalValue != NULL_PTR))
	{
		pSignalConfig = &ComAbsMdl_RxCanSignalConfig[SignalId];

        if (FALSE != COMABSMDL_IS_BIT_SET(pSignalConfig->RxSigMonitoringType,COMABSMDL_RXCAN_SIG_RETENTION_BIT_POS))
        {
            if ((pSignalConfig->SignalLengthInByte == 1U) &&
                (pSignalConfig->SignalBufferStartIdx < COMABSMDL_RXCAN_NUM_OF_U8_RETENTION_BUFFERS))
            {
                /* set the value to retention buffer */
                ComAbsMdl_RxCanRetentionSigBufferU8[pSignalConfig->SignalBufferStartIdx] = *((uint8 *)pSignalValue);
            }
            else if((pSignalConfig->SignalLengthInByte == 2U) &&
                    (pSignalConfig->SignalBufferStartIdx < COMABSMDL_RXCAN_NUM_OF_U16_RETENTION_BUFFERS))
            {
                /* set the value to retention buffer */
                ComAbsMdl_RxCanRetentionSigBufferU16[pSignalConfig->SignalBufferStartIdx] = *((uint16 *)pSignalValue);
            }
            else if(((pSignalConfig->SignalLengthInByte > 2U) && (pSignalConfig->SignalLengthInByte <= 4U)) &&
                    (pSignalConfig->SignalBufferStartIdx < COMABSMDL_RXCAN_NUM_OF_U32_RETENTION_BUFFERS))
            {
                /* set the value to retention buffer */
                ComAbsMdl_RxCanRetentionSigBufferU32[pSignalConfig->SignalBufferStartIdx] = *((uint32 *)pSignalValue);
            }
            else
            {
                ReturnStatus = E_NOT_OK;
            }
        }
        else
        {
            if ((pSignalConfig->SignalLengthInByte == 1U) &&
                (pSignalConfig->SignalBufferStartIdx < COMABSMDL_RXCAN_NUM_OF_U8_BUFFERS))
            {
                /* set the value to retention buffer */
                ComAbsMdl_RxCanSigBufferU8[pSignalConfig->SignalBufferStartIdx] = *((uint8 *)pSignalValue);
            }
            else if((pSignalConfig->SignalLengthInByte == 2U) &&
                    (pSignalConfig->SignalBufferStartIdx < COMABSMDL_RXCAN_NUM_OF_U16_BUFFERS))
            {
                /* set the value to retention buffer */
                ComAbsMdl_RxCanSigBufferU16[pSignalConfig->SignalBufferStartIdx] = *((uint16 *)pSignalValue);
            }
            else if(((pSignalConfig->SignalLengthInByte > 2U) && (pSignalConfig->SignalLengthInByte <= 4U)) &&
                    (pSignalConfig->SignalBufferStartIdx < COMABSMDL_RXCAN_NUM_OF_U32_BUFFERS))
            {
                /* set the value to retention buffer */
                ComAbsMdl_RxCanSigBufferU32[pSignalConfig->SignalBufferStartIdx] = *((uint32 *)pSignalValue);
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
static void ComAbsMdl_UtilMemSet(uint8 *pDest,uint8 Value,uint32 Length)
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


/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

    
