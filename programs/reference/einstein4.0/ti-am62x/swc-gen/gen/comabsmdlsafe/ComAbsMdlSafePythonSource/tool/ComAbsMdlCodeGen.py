import sys
import os 

def generate_code_comabsmdl(user_name, gen_time, output_dir="."):
    '''
    This method is used to generate the ComAbsMdlSafe.c and ComAbsMdlSafe.h file.
    :param user_name: User name for file generation
    :param gen_time: File generation time
    :param output_dir: Output directory where files will be saved
    :return: None
    '''
    # Ensure output directory exists
    os.makedirs(output_dir, exist_ok=True)

    # Full paths for output files
    h_file_path = os.path.join("..\gen-files", "ComAbsMdlSafe.h")
    c_file_path = os.path.join("..\gen-files", "ComAbsMdlSafe.c")

    # Generate ComAbsMdlSafe.h
    with open(h_file_path, "w") as file_cfg_h:
        stdout_fileno = sys.stdout
        sys.stdout = file_cfg_h
        print ("""/********************************************************************************************************************
                                   _C O P Y R I G H T_                                                               
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
*    @file ComAbsMdlSafe.h
*    @ingroup ComAbsMdlSafe
*    @brief This file contains the API provided by the ComAbsMdlSafe.
*    Auto generated code in """+user_name +" at "+ str(gen_time)+"""
********************************************************************************************************************/
#ifndef COMABSMDLSAFE_H_
#define COMABSMDLSAFE_H_

#include "ComAbsMdlSafe_TxCfg.h"
#include "ComAbsMdlSafe_RxCfg.h"
#include "Rte_DataHandleType.h"
#include "ComAbsCtrl_cfg.h"

#define COMABSMDLSAFE_SEC_CODE_START
#define COMABSMDLSAFE_CORE_CONST_SEC_START
#define COMABSMDLSAFE_CORE_DATA_SEC_START
#define COMABSMDLSAFE_CORE_BSS_SEC_START
#include "MemMap.h"
#ifndef ComAbsMdlSafe_DUMMY_STATEMENT
#define ComAbsMdlSafe_DUMMY_STATEMENT(param) ((void)(param))
#endif

/********************************************************************************************************************
*   @brief   This method is used to set the signal confirmation status
*   @param[in] SignalId TX signal id
********************************************************************************************************************/
void ComAbsMdlSafeTxCan_SetCanSignalTxConfirmation(tSafeTxSignalId SignalId);
/********************************************************************************************************************
*   @brief   This method is used to intialize the rx can variable
********************************************************************************************************************/
void ComAbsMdlSafeRxCanVarInit(void);
/********************************************************************************************************************
*   @brief   This method is used to tx can variable
********************************************************************************************************************/
//void ComAbsMdlSafeTxCanVarInit(void);

/********************************************************************************************************************
*   @brief     This method is used to reset the missing timer
*   @param[in] SignalId		Signal Id
********************************************************************************************************************/
void ComAbsMdlSafeReloadMissingTimer(tRxSafeSignalId SignalId);

/********************************************************************************************************************
*   @brief     This method is used to reset the missing timer
*   @param[in] SignalId		Signal Id
*   @param[in] pSignalValue	 pointer to signal value
*   @param[in] pSignalLength pointer to signal length
*   @return Std_ReturnType		pSignalLength
********************************************************************************************************************/
Std_ReturnType ComAbsMdlSafeRxCanSetSignalValueU8Arr(tRxSafeSignalId SignalId,uint8 * pSignalValue,uint32 *pSignalLength);

#define COMABSMDLSAFE_SEC_CODE_STOP
#define COMABSMDLSAFE_CORE_CONST_SEC_END
#define COMABSMDLSAFE_CORE_DATA_SEC_END
#define COMABSMDLSAFE_CORE_BSS_SEC_END

#include "MemMap.h"
#endif /* COMABSMDLSAFE_H_ */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
\n\n""")
        sys.stdout.close()
        sys.stdout = stdout_fileno

    # Generate ComAbsMdlSafe.c
    with open(c_file_path, "w") as file_cfg_c:
        stdout_fileno = sys.stdout
        sys.stdout = file_cfg_c
        print ('''/********************************************************************************************************************
                                   _C O P Y R I G H T_                                                               
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
*    @file ComAbsMdlSafe.c
*    @ingroup ComAbsMdlSafe
*    @brief This file implements the Abstraction for Com Rx and Tx signals between SWC's and the Com stack
*    Auto generated code in ''' + user_name +' at '+ str(gen_time) + '''
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/

#include "ComAbsMdlSafe.h"
#include "ComAbsMdlSafe_RxCfg.h"
#include "ComAbsMdlSafe_TxCfg.h"
#include "CmpLib.h"
#include "Rte_CComAbsMdlSafe_Type.h"
#define COMABSMDLSAFE_SEC_CODE_START
#define COMABSMDLSAFE_CORE_CONST_SEC_START
#define COMABSMDLSAFE_CORE_DATA_SEC_START
#define COMABSMDLSAFE_CORE_BSS_SEC_START
#include "MemMap.h"

/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
#define COMABSMDLSAFE_RXCAN_SIG_NR_BIT_POS                 		0U
#define COMABSMDLSAFE_RXCAN_SIG_MISSING_BIT_POS            		1U
#define COMABSMDLSAFE_RXCAN_SIG_INVALID_BIT_POS            		2U
#define COMABSMDLSAFE_RXCAN_SIG_RETENTION_BIT_POS            	3U
#define COMABSMDLSAFE_RXCAN_SIG_ISO_BIT_POS            	        4U


#define COMABSMDLSAFE_TXCAN_IS_KEEP_ALIVE_SUPPORTED(props)   (((props) & COMABSMDLSAFE_TXCAN_KEEP_ALIVE_BIT_ENABLED) == COMABSMDLSAFE_TXCAN_KEEP_ALIVE_BIT_ENABLED)
#define COMABSMDLSAFE_TXCAN_IS_CONFIRMATION_SUPPORTED(props) (((props) & COMABSMDLSAFE_TXCAN_CONFIRMATION_ENABLED) == COMABSMDLSAFE_TXCAN_CONFIRMATION_ENABLED)
#define COMABSMDLSAFE_TXCAN_IS_ISO_SUPPORTED(props)          (((props) & COMABSMDLSAFE_TXCAN_ISO_SUPPORTED) == COMABSMDLSAFE_TXCAN_ISO_SUPPORTED)

/********************************************************************************************************************
*  PRIVATE TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/
/* Rx Functions */
static void ComAbsMdlSafeRxCanSignalMissingProcessing(void);
static void ComAbsMdlSafeRxCanSignalInvalidProcessing(void);
static boolean ComAbsMdlSafeRxCanIsSignalMissing(tRxSafeSignalId SignalId);
static boolean ComAbsMdlSafeRxCanIsSignalNR(tRxSafeSignalId SignalId);
static boolean ComAbsMdlSafeRxCanIsSignalInvalid(tRxSafeSignalId SignalId);
tRxSafeSignalStatus ComAbsMdlSafeRxCanGetSignalStatus(tRxSafeSignalId SignalId);
Std_ReturnType ComAbsMdlSafeRxCanSetSignalValue(tRxSafeSignalId SignalId,uint8 * pSignalValue);
static void ComAbsMdlSafeUtilMemSet(uint8 *pDest,uint8 Value,uint32 Length);
/* Tx Functions */


/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/
/* Buffers for Com Rx Signal */
uint8  ComAbsMdlSafe_RxCanSigBufferU8[COMABSMDLSAFE_RXCAN_NUM_OF_U8_BUFFERS];
static uint16 ComAbsMdlSafe_RxCanSigBufferU16[COMABSMDLSAFE_RXCAN_NUM_OF_U16_BUFFERS];
static uint32 ComAbsMdlSafe_RxCanSigBufferU32[COMABSMDLSAFE_RXCAN_NUM_OF_U32_BUFFERS];
static uint8 ComAbsMdlSafe_RxCanSigBufferU8NArr[COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_BUFFERS];
static uint32 ComAbsMdlSafe_RxCanSigBufferU8ArrLength[COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_LENGTH_BUFFERS];

/* Com Rx signal buffer status */
static uint8 ComAbsMdlSafeRxCanSignalInvalidStatus[COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_INVALID_STATUS_BYTES];
static uint8 ComAbsMdlSafeRxCanIsSignalMissingEnabled[COMABSMDLSAFE_RXCAN_NUM_OF_MISSING_STATUS_BYTES];
static uint8 ComAbsMdlSafeRxCanIsSignalNREnabled[COMABSMDLSAFE_RXCAN_NUM_OF_NR_STATUS_BYTES];
static uint8 ComAbsMdlSafeRxCanIsSignalInvalidEnabled[COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_INVALID_STATUS_BYTES];
static uint32 ComAbsMdlSafeRxCanSignalMissingCounter[COMABSMDLSAFE_RXCAN_NUM_OF_MISSING_SIGNALS];
static uint32 ComAbsMdlSafeRxCanSignalInvalidCounter[COMABSMDLSAFE_RXCAN_NUM_OF_INVALID_SIGNALS];

/* Retention Buffers for Com Tx and Rx Signal */
#define COMABSMDLSAFE_BACKUP_RAM_SEC_START
#include "MemMap.h"
/* Retention Buffers for Com Rx signal */
uint8  ComAbsMdlSafeRxCanRetentionSigBufferU8[COMABSMDLSAFE_RXCAN_NUM_OF_U8_RETENTION_BUFFERS];
static uint16 ComAbsMdlSafeRxCanRetentionSigBufferU16[COMABSMDLSAFE_RXCAN_NUM_OF_U16_RETENTION_BUFFERS];
static uint32 ComAbsMdlSafeRxCanRetentionSigBufferU32[COMABSMDLSAFE_RXCAN_NUM_OF_U32_RETENTION_BUFFERS];
static uint8  ComAbsMdlSafe_RxCanRetentionSigBufferU8Arr[COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_RETENTION_BUFFERS];
static uint32  ComAbsMdlSafe_RxCanRetentionSigBufferU8ArrLength[COMABSMDLSAFE_RXCAN_NUM_OF_RETENTION_U8ARR_LENGTH_BUFFERS];
#ifdef ComAbsMdlSafeTx
static uint8 ComAbsMdlSafeTxCanRetentionBufferU8[COMABSMDLSAFE_TXCAN_NUM_OF_U8_BUFFERS];
static uint16 ComAbsMdlSafeTxCanRetentionBufferU16[COMABSMDLSAFE_TXCAN_NUM_OF_U16_BUFFERS];
static uint32 ComAbsMdlSafeTxCanRetentionBufferU32[COMABSMDLSAFE_TXCAN_NUM_OF_U32_BUFFERS];
static uint8 ComAbsMdlSafeCanTxRetentionBufferArr[COMABSMDLSAFE_TXCAN_NUM_OF_U8ARR_BUFFERS];
static uint32 ComAbsMdlSafeCanTxRetentionBufferU8ArrLength[COMABSMDLSAFE_TXCAN_NUM_OF_U8ARR_SIGNAL];
#endif
#define COMABSMDLSAFE_BACKUP_RAM_END
#include "MemMap.h"
/* Confirmation status for the transmit signal */
#ifdef ComAbsMdlSafeTx
static uint8 ComAbsMdlSafeTxCanSignalConfirmStatus[COMABSMDLSAFE_TXCAN_NUM_OF_CONF_STATUS_BYTES];
#endif
//extern VAR(tResetReason, RTE_VAR_INIT) Rte_ModeMgr_ppSRModeResetReason_ResetReason;
extern uint8 ComAbsMdlSafe_RxCanSignal_currentStatus[COMABSMDLSAFE_RXCAN_NUM_OF_NR_STATUS_BYTES];

/* @brief  Instance of life-cycle state-machine */
CMPLIB_INSTANCE(ComAbsMdlSafe)

/* Public Function Implementation */
/* Tx Implementation */
/********************************************************************************************************************
*   @brief   Main function Runnable for the RxCanMdl. Should be called in every
*   \COMABSMDLSAFE_RXCAN_MAINFUNCTION_TIME_IN_MS. It process the missing and Invalid status
********************************************************************************************************************/
void CComAbsMdlSafeImpl_TxCanMdlMainFunction(void)
{

}
#ifdef ComAbsMdlSafeTx
/********************************************************************************************************************
*   @brief   This method is used to set the Com Tx singal value from the retention buffer
*   @param[in] SignalId Tx signal id
********************************************************************************************************************/
Std_ReturnType CComAbsMdlSafeTxCan_SetSignalFromRetentionBuffer(tSafeTxSignalId SignalId)
{
    Std_ReturnType ReturnStatus = E_NOT_OK;
    uint8* pTxSignalData;
    uint32 SignalLength = 0;
    ComAbsMdlSafeTxCanSignalConfigType const * pTxSignalConfig;
    ComAbsMdlSafeTxCanSetSignalFunctPtrType pTxSetSignalFunct;
	ComAbsMdlSafeTxCanSetSignalU8ArrFunctPtrType pTxSetSignalU8ArrFunct;

    if (SignalId < eEndOfSafeTxSignal)
    {
        pTxSignalConfig = &ComAbsMdlSafeTxCanSignalConfig[SignalId];

        if(COMABSMDLSAFE_TXCAN_IS_KEEP_ALIVE_SUPPORTED(pTxSignalConfig->TxSigalProps))
        {
        	/* Get retention buffer */
            if ((pTxSignalConfig->SignalLengthInByte == 1U) &&
				(pTxSignalConfig->SignalBufferStartIdx < COMABSMDLSAFE_TXCAN_NUM_OF_U8_BUFFERS))
            {
                pTxSignalData = &ComAbsMdlSafeTxCanRetentionBufferU8[pTxSignalConfig->SignalBufferStartIdx];
            }
            else if ((pTxSignalConfig->SignalLengthInByte == 2U) &&
            		(pTxSignalConfig->SignalBufferStartIdx < COMABSMDLSAFE_TXCAN_NUM_OF_U16_BUFFERS))
            {
                pTxSignalData = (uint8 *)&ComAbsMdlSafeTxCanRetentionBufferU16[pTxSignalConfig->SignalBufferStartIdx];
            }
            else if (((pTxSignalConfig->SignalLengthInByte > 2U) && (pTxSignalConfig->SignalLengthInByte <= 4U)) &&
            		(pTxSignalConfig->SignalBufferStartIdx < COMABSMDLSAFE_TXCAN_NUM_OF_U32_BUFFERS))
            {
                pTxSignalData = (uint8 *)&ComAbsMdlSafeTxCanRetentionBufferU32[pTxSignalConfig->SignalBufferStartIdx];
            }
            else
            {
            	if ((pTxSignalConfig->SignalBufferStartIdx < COMABSMDLSAFE_TXCAN_NUM_OF_U8ARR_BUFFERS) &&
					(pTxSignalConfig->TxSetSignalIdx < CANABSMDL_TXCAN_NUM_OF_SET_SIG_U8ARR_FUNCT))
            	{
            		pTxSignalData = &ComAbsMdlSafeCanTxRetentionBufferArr[pTxSignalConfig->SignalBufferStartIdx];
            		SignalLength = ComAbsMdlSafeCanTxRetentionBufferU8ArrLength[pTxSignalConfig->TxSetSignalIdx];
            	}

            }
            /* Invoke set functions */
            if ((pTxSignalConfig->SignalLengthInByte <= 4U) &&
				(pTxSignalConfig->TxSetSignalIdx < CANABSMDL_TXCAN_NUM_OF_SET_SIG_FUNCT))
            {
                if (COMABSMDLSAFE_TXCAN_IS_ISO_SUPPORTED(pTxSignalConfig->TxSigalProps))
                {
                    //ReturnStatus = CComAbsMdlSafe_TxCan_SetIsoSignal(SignalId,pTxSignalData,pTxSignalConfig->SignalLengthInByte);
                }
                else
                {
                    pTxSetSignalFunct = ComAbsMdlSafeTxCanSetSignalFunctPtrConfig[pTxSignalConfig->TxSetSignalIdx];
                    if (pTxSetSignalFunct != NULL_PTR)
                    {
                        ReturnStatus = (*pTxSetSignalFunct)(pTxSignalData);
                    }
                }
            }
            else
            {
                if (COMABSMDLSAFE_TXCAN_IS_ISO_SUPPORTED(pTxSignalConfig->TxSigalProps))
                {
                    //ReturnStatus = CComAbsMdlSafeTxCan_SetIsoSignal(SignalId,pTxSignalData,SignalLength);
                }
                else
                {
                    if (pTxSignalConfig->TxSetSignalIdx < CANABSMDL_TXCAN_NUM_OF_SET_SIG_U8ARR_FUNCT)
                    {
                        pTxSetSignalU8ArrFunct= ComAbsMdlSafeTxCanSetSignalU8ArrFunctPtrConfig[pTxSignalConfig->TxSetSignalIdx];
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
Std_ReturnType CComAbsMdlSafeTxCan_SetSignalValue(tSafeTxSignalId SignalId,uint8 *pTxSignalData)
{
    Std_ReturnType ReturnStatus = E_NOT_OK;
    ComAbsMdlSafeTxCanSignalConfigType const * pTxSignalConfig;
    ComAbsMdlSafeTxCanSetSignalFunctPtrType pTxSetSignalFunct;

    if (SignalId < eEndOfSafeTxSignal)
    {
        if (pTxSignalData != NULL_PTR)
        {
            /* check for back ram retention */
            pTxSignalConfig = &ComAbsMdlSafeTxCanSignalConfig[SignalId];
            if(COMABSMDLSAFE_TXCAN_IS_KEEP_ALIVE_SUPPORTED(pTxSignalConfig->TxSigalProps))
            {
                // save message in the buffer
            	if ((pTxSignalConfig->SignalLengthInByte == 1U) &&
					(pTxSignalConfig->SignalBufferStartIdx < COMABSMDLSAFE_TXCAN_NUM_OF_U8_BUFFERS))
                {
                    ComAbsMdlSafeTxCanRetentionBufferU8[pTxSignalConfig->SignalBufferStartIdx] = *((uint8 *)pTxSignalData);
                }
                else if ((pTxSignalConfig->SignalLengthInByte == 2U) &&
                		(pTxSignalConfig->SignalBufferStartIdx < COMABSMDLSAFE_TXCAN_NUM_OF_U16_BUFFERS))
                {
                    ComAbsMdlSafeTxCanRetentionBufferU16[pTxSignalConfig->SignalBufferStartIdx] = *((uint16 *)pTxSignalData);
                }
                else if (((pTxSignalConfig->SignalLengthInByte > 2U) && (pTxSignalConfig->SignalLengthInByte <= 4U)) &&
                		(pTxSignalConfig->SignalBufferStartIdx < COMABSMDLSAFE_TXCAN_NUM_OF_U32_BUFFERS))
                {
                    ComAbsMdlSafeTxCanRetentionBufferU32[pTxSignalConfig->SignalBufferStartIdx] = *((uint32 *)pTxSignalData);
                }
                else
                {

                }
            }

            /* Invoke set functions */
			if (COMABSMDLSAFE_TXCAN_IS_ISO_SUPPORTED(pTxSignalConfig->TxSigalProps))
            {
                //ReturnStatus = CComAbsMdlSafeTxCan_SetIsoSignal(SignalId,pTxSignalData,pTxSignalConfig->SignalLengthInByte);
            }
            else
            {
                if ((pTxSignalConfig->SignalLengthInByte <= 4U) &&
                    (pTxSignalConfig->TxSetSignalIdx < CANABSMDL_TXCAN_NUM_OF_SET_SIG_FUNCT))
                {
                    pTxSetSignalFunct = ComAbsMdlSafeTxCanSetSignalFunctPtrConfig[pTxSignalConfig->TxSetSignalIdx];
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
Std_ReturnType CComAbsMdlSafeTxCan_SetSignalValueU8Arr(tSafeTxSignalId SignalId,uint8 *pTxSignalData,uint32 SignalLength)
{
	Std_ReturnType ReturnStatus = E_NOT_OK;
	ComAbsMdlSafeTxCanSignalConfigType const * pTxSignalConfig;
	ComAbsMdlSafeTxCanSetSignalU8ArrFunctPtrType pTxSetSignalU8ArrFunct;
	uint32 BuffIdx;

	if (SignalId < eEndOfSafeTxSignal)
	{
		if (pTxSignalData != NULL_PTR)
		{
			/* check for back ram retention */
			pTxSignalConfig = &ComAbsMdlSafeTxCanSignalConfig[SignalId];
			if(COMABSMDLSAFE_TXCAN_IS_KEEP_ALIVE_SUPPORTED(pTxSignalConfig->TxSigalProps))
			{
				if (((pTxSignalConfig->SignalBufferStartIdx + SignalLength -1U) < COMABSMDLSAFE_TXCAN_NUM_OF_U8ARR_BUFFERS) &&
					(pTxSignalConfig->TxSetSignalIdx < CANABSMDL_TXCAN_NUM_OF_SET_SIG_U8ARR_FUNCT))
				{
					for (BuffIdx = 0;BuffIdx<SignalLength;BuffIdx++)
					{
						ComAbsMdlSafeCanTxRetentionBufferArr[pTxSignalConfig->SignalBufferStartIdx+BuffIdx] = pTxSignalData[BuffIdx];
					}
                    ComAbsMdlSafeCanTxRetentionBufferU8ArrLength[pTxSignalConfig->TxSetSignalIdx]=SignalLength;
				}
			}
			/* call corresponding signal */
            if (COMABSMDLSAFE_TXCAN_IS_ISO_SUPPORTED(pTxSignalConfig->TxSigalProps))
            {
                //ReturnStatus = CComAbsMdlSafeTxCan_SetIsoSignal(SignalId,pTxSignalData,SignalLength);
            }
            else
            {
                if (pTxSignalConfig->TxSetSignalIdx < CANABSMDL_TXCAN_NUM_OF_SET_SIG_U8ARR_FUNCT)
                {
                    pTxSetSignalU8ArrFunct= ComAbsMdlSafeTxCanSetSignalU8ArrFunctPtrConfig[pTxSignalConfig->TxSetSignalIdx];
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
void CComAbsMdlSafeTxCan_ClearCanSignalTxConfirmation(tSafeTxSignalId SignalId)
{
    uint8 BytePosition;
	ComAbsMdlSafeTxCanSignalConfigType const * pTxSignalConfig;
    if (SignalId < eEndOfSafeTxSignal)
    {
        BytePosition = SignalId>>3U;
        pTxSignalConfig = &ComAbsMdlSafeTxCanSignalConfig[SignalId];
        if((COMABSMDLSAFE_TXCAN_IS_CONFIRMATION_SUPPORTED(pTxSignalConfig->TxSigalProps)) &&
            (BytePosition < COMABSMDLSAFE_TXCAN_NUM_OF_CONF_STATUS_BYTES))
        {
            COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafeTxCanSignalConfirmStatus[BytePosition],(SignalId & 0x7U));
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
void CComAbsMdlSafeTxCan_GetCanSignalTxConfirmation(tSafeTxSignalId SignalId,tTxSigConfirmStatus *pStatus)
{
    uint8 BytePosition;
    ComAbsMdlSafeTxCanSignalConfigType const * pTxSignalConfig;
    tTxSigConfirmStatus Status = eTxSigConfirmStatus_NotSupported;
    if (SignalId < eEndOfSafeTxSignal)
    {
        BytePosition = SignalId>>3U;
        pTxSignalConfig = &ComAbsMdlSafeTxCanSignalConfig[SignalId];
        if((COMABSMDLSAFE_TXCAN_IS_CONFIRMATION_SUPPORTED(pTxSignalConfig->TxSigalProps)) &&
            (BytePosition < COMABSMDLSAFE_TXCAN_NUM_OF_CONF_STATUS_BYTES))
        {
            if (TRUE == COMABSMDLSAFE_IS_BIT_SET(ComAbsMdlSafeTxCanSignalConfirmStatus[BytePosition],(SignalId & 0x07)))
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
void ComAbsMdlSafeTxCan_SetCanSignalTxConfirmation(tSafeTxSignalId SignalId)
{
	uint8 BytePosition;
	ComAbsMdlSafeTxCanSignalConfigType const * pTxSignalConfig;

    if (SignalId < eEndOfSafeTxSignal)
    {
        BytePosition = SignalId>>3U;
        pTxSignalConfig = &ComAbsMdlSafeTxCanSignalConfig[SignalId];
        if((COMABSMDLSAFE_TXCAN_IS_CONFIRMATION_SUPPORTED(pTxSignalConfig->TxSigalProps)) &&
            (BytePosition < COMABSMDLSAFE_TXCAN_NUM_OF_CONF_STATUS_BYTES))
        {
            COMABSMDLSAFE_SET_BIT(ComAbsMdlSafeTxCanSignalConfirmStatus[BytePosition],(SignalId & 0x7U));
        }
    }
}
#endif
/* Rx Implementation */
/********************************************************************************************************************
*   @brief   Main function Runnable for the ComAbsMdlSafe. Should be called in every
*   \COMABSMDLSAFE_RXCAN_MAINFUNCTION_TIME_IN_MS. It process the missing and Invalid status
**************************************** ****************************************************************************/
void CComAbsMdlSafe_Impl_RxCanMdlSafeMainFunction(void)
{
	ComAbsMdlSafeRxCanSignalMissingProcessing();
	ComAbsMdlSafeRxCanSignalInvalidProcessing();
}

/********************************************************************************************************************
*   @brief   This method is used to clear the signal just received status
*   @param[in] SignalId RX signal id
********************************************************************************************************************/
void CComAbsMdlSafeRxCan_SignalClearJustRcvdStatus(tRxSafeSignalId SignalId)
{
    uint8 BytePosition;

    if (SignalId < eEndOfSafeRxSignal)
    {
        BytePosition = SignalId>>3U;
        if(BytePosition < COMABSMDLSAFE_RXCAN_NUM_OF_JUST_RCVD_STATUS_BYTES)
        {
            COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanJustRcvdStatus[BytePosition],(SignalId & 0x7U));
        }
    }
}


/********************************************************************************************************************
*   @brief   This method is used to get the signal just received status
*   @param[in] SignalId RX signal id
********************************************************************************************************************/
void CComAbsMdlSafeRxCan_SignalGetJustRcvdStatus(tRxSafeSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus)
{
    tRxSignalJustRcvdStatus JustRcvdStatus=eNot_Just_Received;
    uint8 BytePosition;

    if (SignalId < eEndOfSafeRxSignal)
    {
        BytePosition = SignalId>>3U;
        if(BytePosition < COMABSMDLSAFE_RXCAN_NUM_OF_JUST_RCVD_STATUS_BYTES)
        {
            if (TRUE == COMABSMDLSAFE_IS_BIT_SET(ComAbsMdlSafe_RxCanJustRcvdStatus[BytePosition],(SignalId & 0x07)))
            {
                JustRcvdStatus = eJust_Received;
            }
        }
    }
    *pJustRcvdStatus = JustRcvdStatus;
}


/********************************************************************************************************************
 *  @brief   This method is used to get the Rx Signal value and its status for signal length less than or equal
 *  to 32.
 *  @param[in]  SignalId      Signal Id
 *	@param[out] pSignalValue  pointer to which the Rx signal value to be copied
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
Std_ReturnType CComAbsMdlSafe_RxCan_GetSignalValue(tRxSafeSignalId SignalId, uint8 *pSignalValue, tRxSafeSignalStatus *pSignalStatus)
{
    Std_ReturnType ReturnStatus = E_NOT_OK;
    tRxSafeSignalStatus SigStatus = eSIGNAL_OK;
    boolean GetLocalBuffer = TRUE;
    boolean InvalidStatus = FALSE;
    boolean Skip_Invalid_Storage = FALSE;
    ComAbsMdlSafe_RxCanSignalConfigType const *pSignalConfig;
    ComAbsMdlSafe_RxCanSignalInvalidConfigType const *pSignalInvalidConfig;
    ComAbsMdlSafe_RxCanGetSignalFunctPtrType pGetSignalFunction;
    uint32 ByteIndex;
    // ByteIndex = SignalId>>3U;

    if ((SignalId < eEndOfSafeRxSignal) &&
        (pSignalValue != NULL_PTR) &&
        (pSignalStatus != NULL_PTR))
    {
        /* Get signal value */
        pSignalConfig = &ComAbsMdlSafe_RxCanSignalConfig[SignalId];
        // SigStatus = ComAbsMdlSafe_RxCanGetSignalStatus(SignalId);

        if (pSignalConfig->SignalInvalidIdx < COMABSMDLSAFE_RXCAN_NUM_OF_INVALID_SIGNALS)
        {

            ByteIndex = pSignalConfig->SignalInvalidIdx >> 3U;
            if (COMABSMDLSAFE_IS_BIT_SET(ComAbsMdlSafe_RxCanSignalInvalidStatus[ByteIndex], (pSignalConfig->SignalInvalidIdx & 0x07U)) == TRUE)
            {
                SigStatus |= eSIGNAL_INVALID;
            }
        }
        ByteIndex = SignalId >> 3U;

        if (COMABSMDLSAFE_IS_BIT_SET(ComAbsMdlSafe_RxCanSignalNRStatus[ByteIndex], (SignalId & 0x07)) == TRUE)
        {
            SigStatus |= eSIGNAL_NEVER_RECEIVED;
        }

        if (COMABSMDLSAFE_IS_BIT_SET(ComAbsMdlSafe_RxCanSignalMissingStatus[ByteIndex], (SignalId & 0x07)) == TRUE)
        {
            SigStatus |= eSIGNAL_MISSING;
        }
        if (COMABSMDLSAFE_IS_BIT_SET(ComAbsMdlSafe_RxCanSignalRepetationCounterStatus[ByteIndex], (SignalId & 0x07)) == TRUE)
        {
            SigStatus |= eSIGNAL_REPEATED;
        }
        if(COMABSMDLSAFE_IS_BIT_SET(ComAbsMdlSafe_RxCanSignalInvalidCRCStatus[ByteIndex],(SignalId & 0x07)) == TRUE)
        {
            SigStatus |= eSIGNAL_INVALID_CRC;
        }
         if(COMABSMDLSAFE_IS_BIT_SET(ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus[ByteIndex],(SignalId & 0x07)) == TRUE)
        {
            SigStatus |= eSIGNAL_INVALID_ALIVE_COUNTER;
        }

        /*check if the signal value has to be fetched from COM buffer or retention buffer */
        if (TRUE == COMABSMDLSAFE_IS_BIT_SET(ComAbsMdlSafe_RxCanSignal_currentStatus[ByteIndex], (SignalId & 0x07)))
        {
            /* Check and update the signal status */
            if (SigStatus == eSIGNAL_OK)
            {
                if (pSignalConfig->SignalGetFunctIdx < COMABSMDLSAFE_RXCAN_NUM_OF_GET_SIG_FUNCT)
                {
                    if ((TRUE == COMABSMDLSAFE_IS_BIT_SET(pSignalConfig->RxSigMonitoringType, COMABSMDLSAFE_RXCAN_SIG_INVALID_BIT_POS)) &&
                        (pSignalConfig->SignalInvalidIdx < COMABSMDLSAFE_RXCAN_NUM_OF_INVALID_SIGNALS))

                    {
                        pSignalInvalidConfig = &ComAbsMdlSafe_RxCanSignalInvalidConfig[pSignalConfig->SignalInvalidIdx];
                        /* check if the received signal has Invalid  value*/
                        if (pSignalInvalidConfig->pSignalInvalidCheckFunc != NULL_PTR)
                        {
                            InvalidStatus = pSignalInvalidConfig->pSignalInvalidCheckFunc();
                        }

                        if (FALSE != InvalidStatus)
                        {
                            GetLocalBuffer = TRUE;
                            Skip_Invalid_Storage = TRUE;
                        }
                    }
                    if (FALSE == Skip_Invalid_Storage)
                    {
                        pGetSignalFunction = ComAbsMdlSafe_RxCanGetSignalFunctConfig[pSignalConfig->SignalGetFunctIdx].pGetSignalFunct;

                        if (pGetSignalFunction != NULL_PTR)
                        {
                            (*pGetSignalFunction)(pSignalValue);
                            /* Update local buffer */
                            ComAbsMdlSafeRxCanSetSignalValue(SignalId, pSignalValue);
                            COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignal_currentStatus[ByteIndex], (SignalId & 0x07U));
                            GetLocalBuffer = FALSE;
                        }
                    }
                }
            }
            else
            {
                GetLocalBuffer = TRUE; // S2dot8 defect fix, shall be applicable for Ford PDC, HD, Tatagen2 Projects
            }
        }
        else
        {
            GetLocalBuffer = TRUE; // S2dot8 defect fix, shall be applicable for Ford PDC, HD, Tatagen2 Projects
        }

        if (GetLocalBuffer != FALSE)
        {
            if (FALSE != COMABSMDLSAFE_IS_BIT_SET(pSignalConfig->RxSigMonitoringType, COMABSMDLSAFE_RXCAN_SIG_RETENTION_BIT_POS))
            {
                if ((pSignalConfig->SignalLengthInByte == 1U) &&
                    (pSignalConfig->SignalBufferStartIdx < COMABSMDLSAFE_RXCAN_NUM_OF_U8_RETENTION_BUFFERS))
                {
                    *((uint8 *)pSignalValue) = ComAbsMdlSafeRxCanRetentionSigBufferU8[pSignalConfig->SignalBufferStartIdx];
                }
                else if ((pSignalConfig->SignalLengthInByte == 2U) &&
                         (pSignalConfig->SignalBufferStartIdx < COMABSMDLSAFE_RXCAN_NUM_OF_U16_RETENTION_BUFFERS))
                {
                    *((uint16 *)pSignalValue) = ComAbsMdlSafeRxCanRetentionSigBufferU16[pSignalConfig->SignalBufferStartIdx];
                }
                else if (((pSignalConfig->SignalLengthInByte > 2U) && (pSignalConfig->SignalLengthInByte <= 4U)) &&
                         (pSignalConfig->SignalBufferStartIdx < COMABSMDLSAFE_RXCAN_NUM_OF_U32_RETENTION_BUFFERS))
                {
                    *((uint32 *)pSignalValue) = ComAbsMdlSafeRxCanRetentionSigBufferU32[pSignalConfig->SignalBufferStartIdx];
                }
                else
                {
                    ReturnStatus = E_NOT_OK;
                }
            }
            else
            {
                if ((pSignalConfig->SignalLengthInByte == 1U) &&
                    (pSignalConfig->SignalBufferStartIdx < COMABSMDLSAFE_RXCAN_NUM_OF_U8_BUFFERS))
                {
                    *((uint8 *)pSignalValue) = ComAbsMdlSafe_RxCanSigBufferU8[pSignalConfig->SignalBufferStartIdx];
                }
                else if ((pSignalConfig->SignalLengthInByte == 2U) &&
                         (pSignalConfig->SignalBufferStartIdx < COMABSMDLSAFE_RXCAN_NUM_OF_U16_BUFFERS))
                {
                    *((uint16 *)pSignalValue) = ComAbsMdlSafe_RxCanSigBufferU16[pSignalConfig->SignalBufferStartIdx];
                }
                else if (((pSignalConfig->SignalLengthInByte > 2U) && (pSignalConfig->SignalLengthInByte <= 4U)) &&
                         (pSignalConfig->SignalBufferStartIdx < COMABSMDLSAFE_RXCAN_NUM_OF_U32_BUFFERS))
                {
                    *((uint32 *)pSignalValue) = ComAbsMdlSafe_RxCanSigBufferU32[pSignalConfig->SignalBufferStartIdx];
                }
                else
                {
                    ReturnStatus = E_NOT_OK;
                }
            }
        }

        ReturnStatus = E_OK;
        *pSignalStatus = SigStatus;
    }
    return ReturnStatus;
}


/********************************************************************************************************************
 *  @brief   This method is used to get the Rx Signal value and its status for signal type of uint8 array
 *  @param[in]  SignalId	  Signal Id
 *	@param[out] pSignalValue  pointer to which the Rx signal value to be copied
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
Std_ReturnType CComAbsMdlSafe_RxCan_GetSignalValueU8Arr(tRxSafeSignalId SignalId, uint8 *pSignalValue,
                                                    tRxSafeSignalStatus *pSignalStatus, uint32 *pSignalLength)
{
Std_ReturnType ReturnStatus = E_NOT_OK;
    uint32 ByteIndex;
    uint16 LengthBufferIdx = 0;
    tRxSignalStatus SigStatus = eSIGNAL_OK;
    boolean GetLocalBuffer = TRUE;
    ComAbsMdlSafe_RxCanSignalConfigType const *pSignalConfig;
    ComAbsMdlSafe_RxCanGetSignalU8ArrFunctPtrType pGetSignalU8ArrFunction;

    if ((SignalId < eEndOfSafeRxSignal) &&
        (pSignalValue != NULL_PTR) &&
        (pSignalStatus != NULL_PTR))
    {
        /* Get signal value */
        pSignalConfig = &ComAbsMdlSafe_RxCanSignalConfig[SignalId];
        // SigStatus = ComAbsMdlSafe_RxCanGetSignalStatus(SignalId);

        if (pSignalConfig->SignalInvalidIdx < COMABSMDLSAFE_RXCAN_NUM_OF_INVALID_SIGNALS)
        {

            ByteIndex = pSignalConfig->SignalInvalidIdx >> 3U;
            if (COMABSMDLSAFE_IS_BIT_SET(ComAbsMdlSafe_RxCanSignalInvalidStatus[ByteIndex], (pSignalConfig->SignalInvalidIdx & 0x07U)) == TRUE)
            {
                SigStatus |= eSIGNAL_INVALID;
            }
        }
        ByteIndex = SignalId >> 3U;

        if (COMABSMDLSAFE_IS_BIT_SET(ComAbsMdlSafe_RxCanSignalNRStatus[ByteIndex], (SignalId & 0x07U)) == TRUE)
        {
            SigStatus |= eSIGNAL_NEVER_RECEIVED;
        }

        if (COMABSMDLSAFE_IS_BIT_SET(ComAbsMdlSafe_RxCanSignalMissingStatus[ByteIndex], (SignalId & 0x07U)) == TRUE)
        {
            SigStatus |= eSIGNAL_MISSING;
        }
        /* Check and update the signal status */
        if (SigStatus == eSIGNAL_OK)
        {
            /* Get signal from Com Buffer */
            if (pSignalConfig->SignalGetFunctIdx < COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_SIG_CFG)
            {
                pGetSignalU8ArrFunction = ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[pSignalConfig->SignalGetFunctIdx].pGetSignalU8ArrFunct;
                if (pGetSignalU8ArrFunction != NULL_PTR)
                {
                    (*pGetSignalU8ArrFunction)(pSignalValue, pSignalLength);
                    /* Update local buffer */
                    (void)ComAbsMdlSafeRxCanSetSignalValueU8Arr(SignalId, pSignalValue, pSignalLength);
                    COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignal_currentStatus[ByteIndex], (SignalId & 0x07U));
                    GetLocalBuffer = FALSE;
                }
            }
        }

        if (GetLocalBuffer != FALSE)
        {
            /* Get Signal from the local buffer where init value for the missing, never received and invalid is
                           updated */
            if (FALSE != COMABSMDLSAFE_IS_BIT_SET(pSignalConfig->RxSigMonitoringType, COMABSMDLSAFE_RXCAN_SIG_RETENTION_BIT_POS))
            {
                if (pSignalConfig->SignalGetFunctIdx < COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_SIG_CFG)
                {
                    LengthBufferIdx = ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[pSignalConfig->SignalGetFunctIdx].SignalU8ArrBufferLenIdx;
                    if (LengthBufferIdx < COMABSMDLSAFE_RXCAN_NUM_OF_RETENTION_U8ARR_LENGTH_BUFFERS)
                    {
                        *pSignalLength = ComAbsMdlSafe_RxCanRetentionSigBufferU8ArrLength[LengthBufferIdx];
                    }
                    else
                    {
                        *pSignalLength = 0;
                    }

                    for (ByteIndex = 0; ((ByteIndex < (*pSignalLength)) &&
                                         ((ByteIndex + pSignalConfig->SignalLengthInByte - 1U) < COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_RETENTION_BUFFERS));
                         ByteIndex++)
                    {
                        pSignalValue[ByteIndex] = ComAbsMdlSafe_RxCanRetentionSigBufferU8Arr[ByteIndex + pSignalConfig->SignalBufferStartIdx];
                    }
                }
            }
            else
            {
                if (pSignalConfig->SignalGetFunctIdx < COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_SIG_CFG)
                {
                    LengthBufferIdx = ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[pSignalConfig->SignalGetFunctIdx].SignalU8ArrBufferLenIdx;
                    if (LengthBufferIdx < COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_LENGTH_BUFFERS)
                    {
                        *pSignalLength = ComAbsMdlSafe_RxCanSigBufferU8ArrLength[LengthBufferIdx];
                    }
                    else
                    {
                        *pSignalLength = 0;
                    }
                    for (ByteIndex = 0; ((ByteIndex < (*pSignalLength)) &&
                                         ((ByteIndex + pSignalConfig->SignalLengthInByte - 1U) < COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_BUFFERS));
                         ByteIndex++)
                    {
                        pSignalValue[ByteIndex] = ComAbsMdlSafe_RxCanSigBufferU8NArr[ByteIndex + pSignalConfig->SignalBufferStartIdx];
                    }
                }
            }
        }

        ReturnStatus = E_OK;
        *pSignalStatus = SigStatus;
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
void CComAbsMdlSafeRxCan_SignalMissingProcessingControl(tRxSafeSignalId SignalId,boolean Status)
{
    uint32 ByteIndex;
    ComAbsMdlSafe_RxCanSignalConfigType const *pSignalConfig;

    if (SignalId < eEndOfSafeRxSignal)
    {
    	pSignalConfig = &ComAbsMdlSafe_RxCanSignalConfig[SignalId];
        ByteIndex = SignalId>>3U;
        /* Check for missing monitoring support */
        if ((TRUE == COMABSMDLSAFE_IS_BIT_SET(pSignalConfig->RxSigMonitoringType,COMABSMDLSAFE_RXCAN_SIG_MISSING_BIT_POS)) &&
            (ByteIndex <  COMABSMDLSAFE_RXCAN_NUM_OF_MISSING_STATUS_BYTES))
        {
            if (Status == TRUE)
            {
                COMABSMDLSAFE_SET_BIT(ComAbsMdlSafeRxCanIsSignalMissingEnabled[ByteIndex],(SignalId & 0x07));
                ComAbsMdlSafeRxCanSignalMissingCounter[SignalId] = pSignalConfig->SignalMissingCounterValue;
            }
            else
            {
                COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafeRxCanIsSignalMissingEnabled[ByteIndex],(SignalId & 0x07));
                ComAbsMdlSafeRxCanSignalMissingCounter[SignalId] = 0u;
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
void CComAbsMdlSafeRxCan_SignalInvalidProcessingControl(tRxSafeSignalId SignalId,boolean Status)
{
    uint32 ByteIndex;
    ComAbsMdlSafe_RxCanSignalConfigType  const * pSignalConfig;
    ComAbsMdlSafe_RxCanSignalInvalidConfigType const *pSignalInvalidConfig;

    if (SignalId < eEndOfSafeRxSignal)
    {
        pSignalConfig = &ComAbsMdlSafe_RxCanSignalConfig[SignalId];
        if ((TRUE == COMABSMDLSAFE_IS_BIT_SET(pSignalConfig->RxSigMonitoringType,COMABSMDLSAFE_RXCAN_SIG_INVALID_BIT_POS)) &&
           (pSignalConfig->SignalInvalidIdx <  COMABSMDLSAFE_RXCAN_NUM_OF_INVALID_SIGNALS))
        {
            ByteIndex = pSignalConfig->SignalInvalidIdx>>3U;
            if ((ByteIndex < COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_INVALID_STATUS_BYTES) &&
				(pSignalConfig->SignalInvalidIdx < COMABSMDLSAFE_RXCAN_NUM_OF_INVALID_SIGNALS))
            {
            	pSignalInvalidConfig = &ComAbsMdlSafe_RxCanSignalInvalidConfig[pSignalConfig->SignalInvalidIdx];
            	if (Status == TRUE)
				{
					COMABSMDLSAFE_SET_BIT(ComAbsMdlSafeRxCanIsSignalInvalidEnabled[ByteIndex],(pSignalConfig->SignalInvalidIdx & 0x07));
				}
				else
				{
					COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafeRxCanIsSignalInvalidEnabled[ByteIndex],(pSignalConfig->SignalInvalidIdx & 0x07));
					/* clear the timer */
					ComAbsMdlSafeRxCanSignalInvalidCounter[pSignalConfig->SignalInvalidIdx] = pSignalInvalidConfig->SignalInvalidCounterValue;
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
void CComAbsMdlSafeRxCan_SignalNRProcessingControl(tRxSafeSignalId SignalId,boolean Status)
{
    uint32 ByteIndex;
    if (SignalId < eEndOfSafeRxSignal)
    {
        ByteIndex = SignalId>>3U;
        if (ByteIndex <  COMABSMDLSAFE_RXCAN_NUM_OF_MISSING_STATUS_BYTES)
        {
            if (Status == TRUE)
            {
            	/* Set the NR monitoring status enable flag to 1 */
                COMABSMDLSAFE_SET_BIT(ComAbsMdlSafeRxCanIsSignalNREnabled[SignalId>>3U],(SignalId & 0x07));
                /* Set the NR flag to 1 */
                COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanSignalNRStatus[SignalId>>3U],(SignalId & 0x07));
            }
            else
            {
            	/* clear the NR monitoring status enable flag  */
                COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafeRxCanIsSignalNREnabled[SignalId>>3U],(SignalId & 0x07));
                /* Set the NR flag to 0 */
                COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalNRStatus[SignalId>>3U],(SignalId & 0x07));
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
Std_ReturnType CComAbsMdlSafeRxCan_SetSignalInitValue(tRxSafeSignalId SignalId,uint8 * pSignalValue)
{
   return ComAbsMdlSafeRxCanSetSignalValue(SignalId,pSignalValue);
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
Std_ReturnType CComAbsMdlSafeRxCan_SetSignalInitValueU8Arr(tRxSafeSignalId SignalId,uint8 * pSignalValue,uint32 *pSignalLength)
{
	return ComAbsMdlSafeRxCanSetSignalValueU8Arr(SignalId,pSignalValue,pSignalLength);
}

/********************************************************************************************************************
*   @brief     This method is used to reset the missing timer
*   @param[in] SignalId		Signal Id
********************************************************************************************************************/
void ComAbsMdlSafeReloadMissingTimer(tRxSafeSignalId SignalId)
{
	ComAbsMdlSafe_RxCanSignalConfigType const * pSignalConfig;

    if (SignalId < eEndOfSafeRxSignal)
	{
		pSignalConfig = &ComAbsMdlSafe_RxCanSignalConfig[SignalId];
        /* Check the timer count */
        ComAbsMdlSafeRxCanSignalMissingCounter[SignalId] = pSignalConfig->SignalMissingCounterValue;
        COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalMissingStatus[SignalId>>3U],(SignalId & 0x07));
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
	ComAbsMdlSafeRxCanVarInit();
	
	//Initialize the buffer values and status flags on bettery connect
	/*if (Rte_ModeMgr_ppSRModeResetReason_ResetReason == 0)  
	{
		ComAbsMdlSafeTxCanVarInit();
	}*/
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
#ifdef ComAbsMdlsafeTx
/********************************************************************************************************************
*   @brief   This method is used to initialize variables in the TxCanMdl
********************************************************************************************************************/
void ComAbsMdlSafeTxCanVarInit(void)
{
	ComAbsMdlSafeUtilMemSet(&ComAbsMdlSafeTxCanRetentionBufferU8[0],0,COMABSMDLSAFE_TXCAN_NUM_OF_U8_BUFFERS);
	ComAbsMdlSafeUtilMemSet((uint8 *)&ComAbsMdlSafeTxCanRetentionBufferU16[0],0,COMABSMDLSAFE_TXCAN_NUM_OF_U16_BUFFERS*2);
	ComAbsMdlSafeUtilMemSet((uint8 *)&ComAbsMdlSafeTxCanRetentionBufferU32[0],0,COMABSMDLSAFE_TXCAN_NUM_OF_U32_BUFFERS*4);
	ComAbsMdlSafeUtilMemSet(&ComAbsMdlSafeCanTxRetentionBufferArr[0],0,COMABSMDLSAFE_TXCAN_NUM_OF_U8ARR_BUFFERS);
	ComAbsMdlSafeUtilMemSet((uint8 *)&ComAbsMdlSafeCanTxRetentionBufferU8ArrLength[0],0,COMABSMDLSAFE_TXCAN_NUM_OF_U8ARR_SIGNAL*4);
	ComAbsMdlSafeUtilMemSet(&ComAbsMdlSafeTxCanSignalConfirmStatus[0],0,COMABSMDLSAFE_TXCAN_NUM_OF_CONF_STATUS_BYTES);
}
#endif
/********************************************************************************************************************
*   @brief   This method is used to initialize variables in the ComAbsMdlSafe
********************************************************************************************************************/
void ComAbsMdlSafeRxCanVarInit(void)
{
	
	uint16 SignalInvalidIdx = 0;
	tRxSafeSignalId SignalId = 0;
	uint16 ByteIndex = 0;
	ComAbsMdlSafe_RxCanSignalInvalidConfigType const *pSignalInvalidConfig;
	
	//reload the invalid counter and initialize InvalidStatus and Invalidenabled.
	for (SignalInvalidIdx = 0U; SignalInvalidIdx < COMABSMDLSAFE_RXCAN_NUM_OF_INVALID_SIGNALS ;SignalInvalidIdx++)
	{
		pSignalInvalidConfig =&ComAbsMdlSafe_RxCanSignalInvalidConfig[SignalInvalidIdx];
		SignalId = pSignalInvalidConfig->SignalInvalidSigIdx;
		ByteIndex = SignalInvalidIdx >> 3U;
		ComAbsMdlSafeRxCanSignalInvalidCounter[SignalInvalidIdx] = pSignalInvalidConfig->SignalInvalidCounterValue;
		ComAbsMdlSafeRxCanSignalInvalidStatus[ByteIndex] = 0;
		ComAbsMdlSafeRxCanIsSignalInvalidEnabled[ByteIndex] = 0;
	}
	
	//initialize the timers counters and missing related variables
	for (SignalId = 0U; SignalId < eEndOfSafeRxSignal ;SignalId++)
	{	
       ComAbsMdlSafeReloadMissingTimer(SignalId);
	}   
	   	
	/* initialize the buffers */
	ComAbsMdlSafeUtilMemSet(&ComAbsMdlSafe_RxCanSigBufferU8[0],0U,COMABSMDLSAFE_RXCAN_NUM_OF_U8_BUFFERS);
	ComAbsMdlSafeUtilMemSet((uint8 *)&ComAbsMdlSafe_RxCanSigBufferU16[0],0U,COMABSMDLSAFE_RXCAN_NUM_OF_U16_BUFFERS*2);
	ComAbsMdlSafeUtilMemSet((uint8 *)&ComAbsMdlSafe_RxCanSigBufferU32[0],0U,COMABSMDLSAFE_RXCAN_NUM_OF_U16_BUFFERS*4);
	ComAbsMdlSafeUtilMemSet(&ComAbsMdlSafe_RxCanSigBufferU8NArr[0],0U,COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_BUFFERS);
	ComAbsMdlSafeUtilMemSet((uint8 *)&ComAbsMdlSafe_RxCanSigBufferU8ArrLength[0],0U,COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_LENGTH_BUFFERS*2);

	/* Initialize the status flags */
	ComAbsMdlSafeUtilMemSet(&ComAbsMdlSafe_RxCanSignal_currentStatus[0],0x00U,COMABSMDLSAFE_RXCAN_NUM_OF_NR_STATUS_BYTES);
	ComAbsMdlSafeUtilMemSet(&ComAbsMdlSafe_RxCanJustRcvdStatus[0],0U,COMABSMDLSAFE_RXCAN_NUM_OF_JUST_RCVD_STATUS_BYTES);
	/* Initialize the status enable flags */
	ComAbsMdlSafeUtilMemSet(&ComAbsMdlSafeRxCanIsSignalMissingEnabled[0],0x0U,COMABSMDLSAFE_RXCAN_NUM_OF_MISSING_STATUS_BYTES);
	ComAbsMdlSafeUtilMemSet(&ComAbsMdlSafeRxCanIsSignalNREnabled[0],0xFFU,COMABSMDLSAFE_RXCAN_NUM_OF_NR_STATUS_BYTES);	
			            						            			
}


/********************************************************************************************************************
*   @brief   This method is used to process the missing signal status
********************************************************************************************************************/
static void ComAbsMdlSafeRxCanSignalMissingProcessing(void)
{
	tRxSafeSignalId SignalId;
	uint32 ByteIndex;

	for (SignalId = 0;SignalId < eEndOfSafeRxSignal;SignalId++)
	{
		ByteIndex = SignalId>>3U;
		/* Missing processsing enabled */

		if ((TRUE == COMABSMDLSAFE_IS_BIT_SET(ComAbsMdlSafeRxCanIsSignalMissingEnabled[ByteIndex],(SignalId & 0x07))))

		{
			/* Check the timer count */
			if (ComAbsMdlSafeRxCanSignalMissingCounter[SignalId] >0U)
			{
				ComAbsMdlSafeRxCanSignalMissingCounter[SignalId]--;
				if (ComAbsMdlSafeRxCanSignalMissingCounter[SignalId] == 0U)
				{
					COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanSignalMissingStatus[ByteIndex],(SignalId & 0x07));
                    COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanJustRcvdStatus[ByteIndex],(SignalId & 0x7U));
				}
			}
		}
	}
}

/********************************************************************************************************************
*   @brief   This is method is used to process the invalid status
********************************************************************************************************************/
static void ComAbsMdlSafeRxCanSignalInvalidProcessing(void)
{
	uint32 SignalInvalidIdx;
	tRxSafeSignalId SignalId;
	uint32 ByteIndex;
	ComAbsMdlSafe_RxCanSignalInvalidConfigType const * pSignalInvalidConfig;
	boolean InvalidStatus = FALSE;

	for (SignalInvalidIdx = 0U; SignalInvalidIdx < COMABSMDLSAFE_RXCAN_NUM_OF_INVALID_SIGNALS ;SignalInvalidIdx++)
	{
		pSignalInvalidConfig =&ComAbsMdlSafe_RxCanSignalInvalidConfig[SignalInvalidIdx];
		SignalId = pSignalInvalidConfig->SignalInvalidSigIdx;
		ByteIndex = SignalInvalidIdx >> 3U;

		if (SignalId < eEndOfSafeRxSignal)
		{
			/* Invalid processing enabled */
			if ((TRUE == COMABSMDLSAFE_IS_BIT_SET(ComAbsMdlSafeRxCanIsSignalInvalidEnabled[ByteIndex],(SignalInvalidIdx & 0x7U) )) &&
				((ComAbsMdlSafeRxCanIsSignalNR(SignalId) != TRUE)))
			{
				/* check if the received signal is Invalid */
				if (pSignalInvalidConfig->pSignalInvalidCheckFunc != NULL_PTR)
				{
					InvalidStatus = pSignalInvalidConfig->pSignalInvalidCheckFunc();
				}

				if (InvalidStatus != FALSE)
				{
                    if ((FALSE == COMABSMDLSAFE_IS_BIT_SET(ComAbsMdlSafeRxCanSignalInvalidStatus[ByteIndex],(SignalInvalidIdx & 0x07))) &&
                        (ComAbsMdlSafeRxCanSignalInvalidCounter[SignalInvalidIdx] == 0U))
					{
                        /* Reload timer */
                        ComAbsMdlSafeRxCanSignalInvalidCounter[SignalInvalidIdx] = pSignalInvalidConfig->SignalInvalidCounterValue;
                    }

                    if (ComAbsMdlSafeRxCanSignalInvalidCounter[SignalInvalidIdx] > 0U)
                    {
                        ComAbsMdlSafeRxCanSignalInvalidCounter[SignalInvalidIdx]--;
                        if (ComAbsMdlSafeRxCanSignalInvalidCounter[SignalInvalidIdx] == 0U)
                        {
                            COMABSMDLSAFE_SET_BIT(ComAbsMdlSafeRxCanSignalInvalidStatus[ByteIndex],(SignalInvalidIdx & 0x07));
                        }
                    }
				}
				else
				{
					ComAbsMdlSafeRxCanSignalInvalidCounter[SignalInvalidIdx] = 0U;
					/* Clear status */
					COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafeRxCanSignalInvalidStatus[ByteIndex],(SignalInvalidIdx & 0x07));
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
static boolean ComAbsMdlSafeRxCanIsSignalMissing(tRxSafeSignalId SignalId)
{
    uint32 ByteIndex;
    boolean status = FALSE;
    ByteIndex = SignalId>>3U;
    if (ByteIndex <  COMABSMDLSAFE_RXCAN_NUM_OF_MISSING_STATUS_BYTES)
    {
        status = COMABSMDLSAFE_IS_BIT_SET(ComAbsMdlSafe_RxCanSignalMissingStatus[ByteIndex],(SignalId & 0x07));
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
static boolean ComAbsMdlSafeRxCanIsSignalNR(tRxSafeSignalId SignalId)
{
    uint32 ByteIndex;
    boolean status = FALSE;
    ByteIndex = SignalId>>3U;
    if (ByteIndex <  COMABSMDLSAFE_RXCAN_NUM_OF_NR_STATUS_BYTES)
    {
        status = COMABSMDLSAFE_IS_BIT_SET(ComAbsMdlSafe_RxCanSignalNRStatus[ByteIndex],(SignalId & 0x07));
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
static boolean ComAbsMdlSafeRxCanIsSignalInvalid(tRxSafeSignalId SignalId)
{
    boolean status = FALSE;
    uint32 ByteIndex;
    ComAbsMdlSafe_RxCanSignalConfigType  const * pSignalConfig;
    pSignalConfig = &ComAbsMdlSafe_RxCanSignalConfig[SignalId];
    if (pSignalConfig->SignalInvalidIdx <  COMABSMDLSAFE_RXCAN_NUM_OF_INVALID_SIGNALS)
	{
    	ByteIndex = pSignalConfig->SignalInvalidIdx >>3U;
		if (ByteIndex < COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_INVALID_STATUS_BYTES)
		{
			status = COMABSMDLSAFE_IS_BIT_SET(ComAbsMdlSafeRxCanSignalInvalidStatus[ByteIndex],(pSignalConfig->SignalInvalidIdx & 0x07U));
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
tRxSafeSignalStatus ComAbsMdlSafeRxCanGetSignalStatus(tRxSafeSignalId SignalId)
{
	tRxSafeSignalStatus SigStatus = eSIGNAL_OK;

	if (ComAbsMdlSafeRxCanIsSignalNR(SignalId) == TRUE)
	{
		SigStatus |= eSIGNAL_NEVER_RECEIVED;
	}

	if (ComAbsMdlSafeRxCanIsSignalMissing(SignalId) == TRUE)
	{
		SigStatus |= eSIGNAL_MISSING;
	}

	if (ComAbsMdlSafeRxCanIsSignalInvalid(SignalId) == TRUE)
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
Std_ReturnType ComAbsMdlSafeRxCanSetSignalValueU8Arr(tRxSafeSignalId SignalId,uint8 * pSignalValue,uint32 *pSignalLength)
{
	Std_ReturnType ReturnStatus = E_NOT_OK;
	uint32 ByteIndex;
    uint16 BufferLength=0;
	ComAbsMdlSafe_RxCanSignalConfigType const * pSignalConfig;

	if ((SignalId < eEndOfSafeRxSignal) &&
		(pSignalValue != NULL_PTR) &&
		(pSignalLength != NULL_PTR))
	{
		pSignalConfig = &ComAbsMdlSafe_RxCanSignalConfig[SignalId];
        /* pSignalConfig->SignalGetFunctIdx is same as the number of U8Arr signal */
		if (pSignalConfig->SignalGetFunctIdx < COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_SIG_CFG)
		{
            BufferLength = ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[pSignalConfig->SignalGetFunctIdx].SignalU8ArrBufferLenIdx;
            if (FALSE != COMABSMDLSAFE_IS_BIT_SET(pSignalConfig->RxSigMonitoringType,COMABSMDLSAFE_RXCAN_SIG_RETENTION_BIT_POS))
            {
                if (BufferLength < COMABSMDLSAFE_RXCAN_NUM_OF_RETENTION_U8ARR_LENGTH_BUFFERS)
                {
                    ComAbsMdlSafe_RxCanRetentionSigBufferU8ArrLength[BufferLength] = *pSignalLength;
                    for(ByteIndex = 0;((ByteIndex < (*pSignalLength)) &&
                         ((ByteIndex+pSignalConfig->SignalLengthInByte-1U) < COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_RETENTION_BUFFERS));ByteIndex++)
                    {
                        ComAbsMdlSafe_RxCanRetentionSigBufferU8Arr[ByteIndex+pSignalConfig->SignalBufferStartIdx] = pSignalValue[ByteIndex];
                    }
                }
            }
            else
            {
                if (BufferLength < COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_LENGTH_BUFFERS)
                {
                    ComAbsMdlSafe_RxCanSigBufferU8ArrLength[BufferLength] = *pSignalLength;
                    for(ByteIndex = 0;((ByteIndex < (*pSignalLength)) &&
                        ((ByteIndex+pSignalConfig->SignalLengthInByte-1U) < COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_BUFFERS));ByteIndex++)
                    {
                        ComAbsMdlSafe_RxCanSigBufferU8NArr[ByteIndex+pSignalConfig->SignalBufferStartIdx] = pSignalValue[ByteIndex];
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
Std_ReturnType ComAbsMdlSafeRxCanSetSignalValue(tRxSafeSignalId SignalId,uint8 * pSignalValue)
{
	Std_ReturnType ReturnStatus = E_OK;
	ComAbsMdlSafe_RxCanSignalConfigType const * pSignalConfig;

	if ((SignalId < eEndOfSafeRxSignal) &&
		(pSignalValue != NULL_PTR))
	{
		pSignalConfig = &ComAbsMdlSafe_RxCanSignalConfig[SignalId];

        if (FALSE != COMABSMDLSAFE_IS_BIT_SET(pSignalConfig->RxSigMonitoringType,COMABSMDLSAFE_RXCAN_SIG_RETENTION_BIT_POS))
        {
            if ((pSignalConfig->SignalLengthInByte == 1U) &&
                (pSignalConfig->SignalBufferStartIdx < COMABSMDLSAFE_RXCAN_NUM_OF_U8_RETENTION_BUFFERS))
            {
                /* set the value to retention buffer */
                ComAbsMdlSafeRxCanRetentionSigBufferU8[pSignalConfig->SignalBufferStartIdx] = *((uint8 *)pSignalValue);
            }
            else if((pSignalConfig->SignalLengthInByte == 2U) &&
                    (pSignalConfig->SignalBufferStartIdx < COMABSMDLSAFE_RXCAN_NUM_OF_U16_RETENTION_BUFFERS))
            {
                /* set the value to retention buffer */
                ComAbsMdlSafeRxCanRetentionSigBufferU16[pSignalConfig->SignalBufferStartIdx] = *((uint16 *)pSignalValue);
            }
            else if(((pSignalConfig->SignalLengthInByte > 2U) && (pSignalConfig->SignalLengthInByte <= 4U)) &&
                    (pSignalConfig->SignalBufferStartIdx < COMABSMDLSAFE_RXCAN_NUM_OF_U32_RETENTION_BUFFERS))
            {
                /* set the value to retention buffer */
                ComAbsMdlSafeRxCanRetentionSigBufferU32[pSignalConfig->SignalBufferStartIdx] = *((uint32 *)pSignalValue);
            }
            else
            {
                ReturnStatus = E_NOT_OK;
            }
        }
        else
        {
            if ((pSignalConfig->SignalLengthInByte == 1U) &&
                (pSignalConfig->SignalBufferStartIdx < COMABSMDLSAFE_RXCAN_NUM_OF_U8_BUFFERS))
            {
                /* set the value to retention buffer */
                ComAbsMdlSafe_RxCanSigBufferU8[pSignalConfig->SignalBufferStartIdx] = *((uint8 *)pSignalValue);
            }
            else if((pSignalConfig->SignalLengthInByte == 2U) &&
                    (pSignalConfig->SignalBufferStartIdx < COMABSMDLSAFE_RXCAN_NUM_OF_U16_BUFFERS))
            {
                /* set the value to retention buffer */
                ComAbsMdlSafe_RxCanSigBufferU16[pSignalConfig->SignalBufferStartIdx] = *((uint16 *)pSignalValue);
            }
            else if(((pSignalConfig->SignalLengthInByte > 2U) && (pSignalConfig->SignalLengthInByte <= 4U)) &&
                    (pSignalConfig->SignalBufferStartIdx < COMABSMDLSAFE_RXCAN_NUM_OF_U32_BUFFERS))
            {
                /* set the value to retention buffer */
                ComAbsMdlSafe_RxCanSigBufferU32[pSignalConfig->SignalBufferStartIdx] = *((uint32 *)pSignalValue);
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
static void ComAbsMdlSafeUtilMemSet(uint8 *pDest,uint8 Value,uint32 Length)
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

#define COMABSMDLSAFE_SEC_CODE_STOP
#define COMABSMDLSAFE_CORE_CONST_SEC_END
#define COMABSMDLSAFE_CORE_DATA_SEC_END
#define COMABSMDLSAFE_CORE_BSS_SEC_END

#include "MemMap.h"
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

    ''')
    sys.stdout.close()
    sys.stdout = stdout_fileno
    file_cfg_h.close()

if __name__ == '__main__':
    import datetime
    import getpass

    current_time = datetime.datetime.now()
    username = getpass.getuser()
    generate_code_comabsmdl(username,current_time,output_dir=".")