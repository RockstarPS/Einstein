/********************************************************************************************************************
 * C O P Y R I G H T
 ********************************************************************************************************************
 * Copyright (c) 2019 by Visteon Corporation.       All rights reserved.
 *
 * NOTICE: This Is an unpublished work Of authorship, which contains trade secrets.
 * Visteon Corporation owns all rights to this work And intends to maintain it in confidence to preserve
 * its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
 * Or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
 * in the event of an inadvertent Or deliberate unauthorized publication. Visteon Corporation also reserves its
 * rights under all copyright laws to protect this work as a published work, when appropriate.
 * Those having access to this work may Not copy it, use it, modify it, Or disclose the information contained in it
 * without the written authorization of Visteon Corporation.
 ********************************************************************************************************************/
/*!*****************************************************************************************************************
 *    @file ComAbsMdlSafe_TxCfg.h
 *    @ingroup ComAbsMdlSafe
 *    @brief This file contains the configuration of the ComAbsMdlSafe component.
 *    Auto generated code in ABASAVAR at 2025-12-11 15:15:44.707512
 ********************************************************************************************************************/
#ifndef COMABSMDLSAFE_TX_CFG_H_
#define COMABSMDLSAFE_TX_CFG_H_

#include "Rte_CComAbsMdlSafe_Type.h"
#include "ComAbsMdlSafe.h"
#include "Rte_Type.h"

#define COMABSMDLSAFE_SEC_CODE_START
#define COMABSMDLSAFE_CORE_CONST_SEC_START
#define COMABSMDLSAFE_CORE_DATA_SEC_START
#define COMABSMDLSAFE_CORE_BSS_SEC_START
#include "MemMap.h"

/********************************************************************************************************************
 *  PUBLIC MACRO DEFINITIONS
 ********************************************************************************************************************/
#define COMABSMDLSAFE_TXCAN_NUM_OF_U8_BUFFERS            1U
#define COMABSMDLSAFE_TXCAN_NUM_OF_U16_BUFFERS           1U
#define COMABSMDLSAFE_TXCAN_NUM_OF_U32_BUFFERS           1U
#define COMABSMDLSAFE_TXCAN_NUM_OF_U8ARR_BUFFERS         1U
#define COMABSMDLSAFE_TXCAN_NUM_OF_U8ARR_SIGNAL          1U
#define COMABSMDLSAFE_TXCAN_NUM_OF_CONF_STATUS_BYTES     1U
#define CANCOMABSMDLSAFE_NUM_OF_SET_SIG_FUNCT            1U
#define COMABSMDLSAFE_TXCAN_NO_SET_SIG_FUNCT              CANCOMABSMDLSAFE_NUM_OF_SET_SIG_FUNCT
#define CANCOMABSMDLSAFE_NUM_OF_SET_SIG_U8ARR_FUNCT       1U
#define COMABSMDLSAFE_TXCAN_NO_SET_SIG_U8ARR_FUNCT         CANCOMABSMDLSAFE_NUM_OF_SET_SIG_U8ARR_FUNCT

#define COMABSMDLSAFE_TXCAN_SIG_STATUS_NONE               0x0U
#define COMABSMDLSAFE_TXCAN_KEEP_ALIVE_BIT_ENABLED        0x1U
#define COMABSMDLSAFE_TXCAN_CONFIRMATION_ENABLED          0x2U
#define COMABSMDLSAFE_TXCAN_ISO_SUPPORTED                 0x4U

/********************************************************************************************************************
 *  PUBLIC TYPE DEFINITIONS
 ********************************************************************************************************************/
typedef Std_ReturnType (*ComAbsMdlSafe_TxCanSetSignalFunctPtrType)(uint8 *pSignalValue);
typedef Std_ReturnType (*ComAbsMdlSafe_TxCanSetSignalU8ArrFunctPtrType)(uint8 *pSignalValue, uint32 SignalLength);
typedef uint8 ComAbsMdlSafe_TxCanSigalPropsType;

typedef struct
{
    uint16 SignalLengthInByte;
    uint16 SignalBufferStartIdx;
    uint16 TxSetSignalIdx;
    ComAbsMdlSafe_TxCanSigalPropsType TxSigalProps;
} ComAbsMdlSafe_TxCanSignalConfigType;

/********************************************************************************************************************
 *  PUBLIC CONSTANT AND VARIABLE DECLARATION
 ********************************************************************************************************************/
extern const ComAbsMdlSafe_TxCanSignalConfigType ComAbsMdlSafe_TxCanSignalConfig[eEndofSafeTxSignals];
extern const ComAbsMdlSafe_TxCanSetSignalFunctPtrType ComAbsMdlSafe_TxCanSetSignalFunctPtrConfig[CANCOMABSMDLSAFE_NUM_OF_SET_SIG_FUNCT];
extern const ComAbsMdlSafe_TxCanSetSignalU8ArrFunctPtrType ComAbsMdlSafe_TxCanSetSignalU8ArrFunctPtrConfig[CANCOMABSMDLSAFE_NUM_OF_SET_SIG_U8ARR_FUNCT];

/********************************************************************************************************************
 *  PUBLIC FUNCTION PROTOTYPE
 ********************************************************************************************************************/
extern Std_ReturnType ComAbsMdlSafe_TxCanSetSig_Battery_Voltage(uint8 *pSignalValue);

/********************************************************************************************************************
 *  Below are the set of signals that can be send via CComAbsMdl_TxCan_SetSignalValue API
 ********************************************************************************************************************/
/* SignalEnum SignalEnumValue SignalNameInDbc MessageName
   eBattery_VoltageOut    0     Battery_Voltage    SG_Cluster_Tx_Normal_COM_HS
*/

/********************************************************************************************************************
 *  Below are the set of signals that can be send via CComAbsMdl_TxCan_SetSignalValueU8Arr API
 ********************************************************************************************************************/
/* SignalEnum SignalEnumValue SignalNameInDbc MessageName
*/

#define COMABSMDLSAFE_SEC_CODE_STOP
#define COMABSMDLSAFE_CORE_CONST_SEC_END
#define COMABSMDLSAFE_CORE_DATA_SEC_END
#define COMABSMDLSAFE_CORE_BSS_SEC_END
#include "MemMap.h"
#endif /* COMABSMDLSAFE_TX_CFG_H_ */
/*******************************************************************************************************************
 *                                 END OF FILE
 ********************************************************************************************************************/
