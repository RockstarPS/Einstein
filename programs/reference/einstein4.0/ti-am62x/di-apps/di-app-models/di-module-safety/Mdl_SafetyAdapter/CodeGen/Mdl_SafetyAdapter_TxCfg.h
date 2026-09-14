/********************************************************************************************************************
* C O P Y R I G H T                                                                                                 *
*********************************************************************************************************************
* Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
*                                                                                                                   *
* NOTICE: This Is an unpublished work Of authorship, which contains trade secrets.                                  *
* Visteon Corporation owns all rights to this work And intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
* Or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
* in the event of an inadvertent Or deliberate unauthorized publication. Visteon Corporation also reserves its      *
* rights under all copyright laws to protect this work as a published work, when appropriate.                       *
* Those having access to this work may Not copy it, use it, modify it, Or disclose the information contained in it  *
* without the written authorization of Visteon Corporation.                                                         *
********************************************************************************************************************/
/*!*****************************************************************************************************************
*    @file Mdl_SafetyAdapter_TxCfg.h
*    @ingroup Mdl_SafetyAdapter
*    @brief This file contains the configuration of the Mdl_SafetyAdapter component.
*    Auto generated code in RPERIYAS at 2024-11-29 12:02:25.276099
********************************************************************************************************************/
#ifndef MDL_SAFETYADAPTER_TX_CFG_H_
#define MDL_SAFETYADAPTER_TX_CFG_H_

/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
#define MDL_SAFETYADAPTER_TXCAN_NUM_OF_U8_BUFFERS		 1U
#define MDL_SAFETYADAPTER_TXCAN_NUM_OF_U16_BUFFERS		 1U
#define MDL_SAFETYADAPTER_TXCAN_NUM_OF_U32_BUFFERS		 1U
#define MDL_SAFETYADAPTER_TXCAN_NUM_OF_U8ARR_BUFFERS		 1U
#define MDL_SAFETYADAPTER_TXCAN_NUM_OF_CONF_STATUS_BYTES		 1U
#define MDL_SAFETYADAPTER_TXCAN_NUM_OF_U8ARR_SIGNAL		 1U
#define CANABSMDL_TXCAN_NUM_OF_SET_SIG_FUNCT		 1U
#define MDL_SAFETYADAPTER_TXCAN_NO_SET_SIG_FUNCT		     CANABSMDL_TXCAN_NUM_OF_SET_SIG_FUNCT
#define CANABSMDL_TXCAN_NUM_OF_SET_SIG_U8ARR_FUNCT		 1U
#define MDL_SAFETYADAPTER_TXCAN_NO_SET_SIG_U8ARR_FUNCT		     CANABSMDL_TXCAN_NUM_OF_SET_SIG_U8ARR_FUNCT

#define eEndOfTxSignal 1
#define eTxSigConfirmStatus_Set 0
#define eTxSigConfirmStatus_NotSupported 0 
#define eTxSigConfirmStatus_Cleared 0
/********************************************************************************************************************
*  PUBLIC TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/
typedef Std_ReturnType (*Mdl_SafetyAdapter_TxCanSetSignalFunctPtrType)(uint8 * pSignalValue);
typedef Std_ReturnType (*Mdl_SafetyAdapter_TxCanSetSignalU8ArrFunctPtrType)(uint8 * pSignalValue,uint32 SignalLength);

#define MDL_SAFETYADAPTER_TXCAN_SIG_STATUS_NONE        0x0U
#define MDL_SAFETYADAPTER_TXCAN_KEEP_ALIVE_BIT_ENABLED 0x1U
#define MDL_SAFETYADAPTER_TXCAN_CONFIRMATION_ENABLED   0x2U
#define MDL_SAFETYADAPTER_TXCAN_ISO_SUPPORTED          0x4U
typedef uint8 Mdl_SafetyAdapter_TxCanSigalPropsType;

typedef struct
{
    uint16    SignalLengthInByte;
    uint16    SignalBufferStartIdx;
    uint16	  TxSetSignalIdx;
    Mdl_SafetyAdapter_TxCanSigalPropsType TxSigalProps;
}Mdl_SafetyAdapter_TxCanSignalConfigType;

/********************************************************************************************************************
*  PUBLIC CONSTANT AND VARIABLE DECLARTAION                                                                         *
********************************************************************************************************************/
extern const Mdl_SafetyAdapter_TxCanSignalConfigType Mdl_SafetyAdapter_TxCanSignalConfig[eEndOfTxSignal];
extern const Mdl_SafetyAdapter_TxCanSetSignalFunctPtrType Mdl_SafetyAdapter_TxCanSetSignalFunctPtrConfig[CANABSMDL_TXCAN_NUM_OF_SET_SIG_FUNCT];
extern const Mdl_SafetyAdapter_TxCanSetSignalU8ArrFunctPtrType Mdl_SafetyAdapter_TxCanSetSignalU8ArrFunctPtrConfig[CANABSMDL_TXCAN_NUM_OF_SET_SIG_U8ARR_FUNCT];

/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPE                                                                         			    *
********************************************************************************************************************/


#ifdef MDL_SAFETYADAPTER_TXCAN_ISO_SIGNAL_SUPPORTED
/*!******************************************************************************************************************
*   @brief   This method is used to transmit the Iso signal value to the COM.
*   @param[in] SignalId TX signal id
*   @param[in] pTxSignalData pointer to the data to be updated in COM
*   @param[in] SignalLength length of the data to be udpated
*   @return Std_ReturnType status of the request
*   E_OK status accepted
*   E_NOT_OK status not accepted
********************************************************************************************************************/
extern Std_ReturnType CMdl_SafetyAdapter_TxCan_SetIsoSignal(tTxSignalId SignalId,uint8 *pTxSignalData,uint32 SignalLength);

/*!******************************************************************************************************************
*   @brief   This method is called from Mdl_SafetyAdapter_Tx on successful transmission of the signal CanTp signal.
*   Based on the last transmission request the corresponding ISO signal confirmation to be udpated.
********************************************************************************************************************/
extern void CMdl_SafetyAdapter_TxCan_SetIsoSignalConfirmation(tTxSignalId SignalId);
#endif

/********************************************************************************************************************
*  Below are the set of signals that can be send via CMdl_SafetyAdapter_TxCan_SetSignalValue API               			    *
********************************************************************************************************************/
/* SignalEnum SignalEnumValue SignalNameInDbc MessageName
*/
/********************************************************************************************************************
*  Below are the set of signals that can be send via CMdl_SafetyAdapter_TxCan_SetSignalValueU8Arr API          			    *
********************************************************************************************************************/
/* SignalEnum SignalEnumValue SignalNameInDbc MessageName
*/

#endif /* MDL_SAFETYADAPTER_TX_CFG_H_ */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


