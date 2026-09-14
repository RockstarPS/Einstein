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
*    @file ComAbsMdlSafe_RxCfg.h
*    @ingroup COMABSMDLSAFE
*    @brief This file contains the configuration of the COMABSMDLSAFE component.
*    Auto generated code in ABASAVAR at 2025-11-14 16:05:41.216111
********************************************************************************************************************/
#ifndef COMABSMDLSAFE_RX_CFG_H_
#define COMABSMDLSAFE_RX_CFG_H_
#include "Rte_CComAbsMdlSafe_Type.h"
#include "ComAbsMdlSafe.h"
#include "Rte_Type.h"
#define COMABSMDLSAFE_SEC_CODE_START
#define COMABSMDLSAFE_CORE_CONST_SEC_START
#define COMABSMDLSAFE_CORE_DATA_SEC_START
#define COMABSMDLSAFE_CORE_BSS_SEC_START
#include "MemMap.h"
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/* Number of signal buffers */
#define COMABSMDLSAFE_RXCAN_NUM_OF_U8_BUFFERS                       3U
#define COMABSMDLSAFE_RXCAN_NUM_OF_U16_BUFFERS                      1U
#define COMABSMDLSAFE_RXCAN_NUM_OF_U32_BUFFERS                      1U
#define COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_BUFFERS                    1U
#define COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_LENGTH_BUFFERS             1U
#define COMABSMDLSAFE_RXCAN_NUM_OF_U8_RETENTION_BUFFERS             1U
#define COMABSMDLSAFE_RXCAN_NUM_OF_U16_RETENTION_BUFFERS            1U
#define COMABSMDLSAFE_RXCAN_NUM_OF_U32_RETENTION_BUFFERS            1U
#define COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_RETENTION_BUFFERS          1U
#define COMABSMDLSAFE_RXCAN_NUM_OF_RETENTION_U8ARR_LENGTH_BUFFERS   1U
#define COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_SIG_CFG                    1U

/* Number of signal status bytes */

#define COMABSMDLSAFE_RXCAN_NUM_OF_NR_STATUS_BYTES                  1U
#define COMABSMDLSAFE_RXCAN_NUM_OF_MISSING_STATUS_BYTES             1U
#define COMABSMDLSAFE_RXCAN_NUM_OF_JUST_RCVD_STATUS_BYTES           1U
#define COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_INVALID_STATUS_BYTES      1U
#define COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_INVALID_CRC_STATUS_BYTES  1U
#define COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_INVALID_ALIVE_COUNTER_STATUS_BYTES 1U
#define COMABSMDLSAFE_RXCAN_NUM_OF_SIGNAL_REPETATION_STATUS_BYTES   1U

/* Number of invalid signals */

#define COMABSMDLSAFE_RXCAN_NUM_OF_INVALID_SIGNALS                  1U
#define COMABSMDLSAFE_RXCAN_NO_INVALDID_SIGNAL                      COMABSMDLSAFE_RXCAN_NUM_OF_INVALID_SIGNALS
#define COMABSMDLSAFE_RXCAN_NUM_OF_MISSING_SIGNALS                   eEndOfSafeRxSignal
#define COMABSMDLSAFE_RXCAN_MAINFUNCTION_TIME_IN_MS                 10U
#define COMABSMDLSAFE_RXCAN_NUM_OF_GET_SIG_FUNCT                    4U
#define COMABSMDLSAFE_RXCAN_NO_GET_SIG_FUNCT_IDX                    COMABSMDLSAFE_RXCAN_NUM_OF_GET_SIG_FUNCT
#define COMABSMDLSAFE_RXCAN_NUM_OF_GET_SIG_U8ARR_FUNCT              1U
#define COMABSMDLSAFE_RXCAN_NO_GET_SIG_U8ARR_FUNCT_IDX              COMABSMDLSAFE_RXCAN_NUM_OF_GET_SIG_U8ARR_FUNCT

#define COMABSMDLSAFE_RXCAN_SIG_NR_ENABLE          0x01U
#define COMABSMDLSAFE_RXCAN_SIG_MISSING_ENABLE     0x02U
#define COMABSMDLSAFE_RXCAN_SIG_INVALID_ENABLE     0x04U
#define COMABSMDLSAFE_RXCAN_SIG_RETENTION_ENABLE   0x08U
#define COMABSMDLSAFE_RXCAN_SIG_ISO_SUPPORTED      0x10U
#define COMABSMDLSAFE_SET_BIT(datau8,bitpos)     ((datau8) |= (uint8)(1u<<(bitpos))) 
#define COMABSMDLSAFE_CLEAR_BIT(datau8,bitpos)   ((datau8) &= (uint8)(~(1U << (bitpos))))  
#define COMABSMDLSAFE_IS_BIT_SET(datau8,bitpos)  ((( (datau8) & ((uint8)(1u<<(bitpos)))) != 0U) ? TRUE : FALSE) 
/********************************************************************************************************************
*  PUBLIC TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/
typedef void(* ComAbsMdlSafe_RxCanGetSignalFunctPtrType)(uint8 *pSignalValue);
typedef void(* ComAbsMdlSafe_RxCanGetSignalU8ArrFunctPtrType)(uint8 *pSignalValue, uint32 *pSignalLength);
typedef boolean(*ComAbsMdlSafe_RxCanSignalInvalidCheckFuncPtrType)(void);
typedef uint8 ComAbsMdlSafe_RxCanSigMonitoringType;
typedef struct
{
    uint16 SignalLengthInByte;
    uint16 SignalBufferStartIdx;
    uint16 SignalInvalidIdx;
    uint16 SignalGetFunctIdx;
    ComAbsMdlSafe_RxCanSigMonitoringType RxSigMonitoringType;
    uint32 SignalMissingCounterValue;
} ComAbsMdlSafe_RxCanSignalConfigType;
typedef struct
{
    ComAbsMdlSafe_RxCanGetSignalFunctPtrType pGetSignalFunct;
} ComAbsMdlSafe_RxCanGetSignalFunctConfigType;
typedef struct
{
    uint16 SignalU8ArrBufferLenIdx;
    ComAbsMdlSafe_RxCanGetSignalU8ArrFunctPtrType pGetSignalU8ArrFunct;
} ComAbsMdlSafe_RxCanGetSignalU8ArrConfigType;
typedef struct
{
    uint32 SignalInvalidSigIdx;
    uint32 SignalInvalidCounterValue;
    ComAbsMdlSafe_RxCanSignalInvalidCheckFuncPtrType pSignalInvalidCheckFunc;
} ComAbsMdlSafe_RxCanSignalInvalidConfigType;
/********************************************************************************************************************
*  PUBLIC CONSTANT AND VARIABLE DECLARATIONS                                                                        *
********************************************************************************************************************/
extern const ComAbsMdlSafe_RxCanGetSignalFunctConfigType ComAbsMdlSafe_RxCanGetSignalFunctConfig[COMABSMDLSAFE_RXCAN_NUM_OF_GET_SIG_FUNCT];
extern const ComAbsMdlSafe_RxCanGetSignalU8ArrConfigType ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_SIG_CFG];
extern const ComAbsMdlSafe_RxCanSignalConfigType ComAbsMdlSafe_RxCanSignalConfig[eEndOfSafeRxSignal];
extern const ComAbsMdlSafe_RxCanSignalInvalidConfigType ComAbsMdlSafe_RxCanSignalInvalidConfig[COMABSMDLSAFE_RXCAN_NUM_OF_INVALID_SIGNALS]; 
#ifdef COMABSMDLSAFE_RXCAN_ISO_SIGNAL_SUPPORTED
extern void ComAbsMdlSafe_RxIsoMainFunction(void);
#endif
extern void ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core(void);
Std_ReturnType Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS(
    SG_ABS *data,
    Rte_TransformerError *transformerError
);

#define COMABSMDLSAFE_SEC_CODE_STOP
#define COMABSMDLSAFE_CORE_CONST_SEC_END
#define COMABSMDLSAFE_CORE_DATA_SEC_END
#define COMABSMDLSAFE_CORE_BSS_SEC_END
#endif
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

