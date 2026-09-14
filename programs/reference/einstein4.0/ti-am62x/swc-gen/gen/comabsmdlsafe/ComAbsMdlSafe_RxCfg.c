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
*    @file ComAbsMdlSafe_RxCfg.c
*    @ingroup COMABSMDLSAFE
*    @brief This file contains the configuration of the COMABSMDLSAFE component.
*    Auto generated code in ABASAVAR at 2025-11-14 16:05:41.216111
********************************************************************************************************************/
#include "ComAbsMdlSafe.h"
#include "ComAbsMdlSafe_RxCfg.h"
#include "Rte_CComAbsMdlSafe_Type.h"
#include "E2E_P01.h"
#define COMABSMDLSAFE_SEC_CODE_START
#define COMABSMDLSAFE_CORE_CONST_SEC_START
#define COMABSMDLSAFE_CORE_DATA_SEC_START
#define COMABSMDLSAFE_CORE_BSS_SEC_START
#include "MemMap.h"
// Last received message per message type
static SG_ABS msg1;

/********************************************************************************************************************
*   Static forward declarations for OnDataRx functions
********************************************************************************************************************/
void CComAbsMdlSafe_OnDataRx_VehicleSpeedABS(void);

/********************************************************************************************************************
*   Forward declarations of static getter functions
********************************************************************************************************************/
static void ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg(uint16 *pSignalValue);
static void ComAbsMdlSafe_RxCanGetAirbag_FromMsg(uint8 *pSignalValue);
static void ComAbsMdlSafe_RxCanGetAlive_101_FromMsg(uint8 *pSignalValue);
static void ComAbsMdlSafe_RxCanGetCRC_101_FromMsg(uint8 *pSignalValue);


const ComAbsMdlSafe_RxCanGetSignalFunctConfigType ComAbsMdlSafe_RxCanGetSignalFunctConfig[COMABSMDLSAFE_RXCAN_NUM_OF_GET_SIG_FUNCT] =
{
    { &ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg }, /* VehicleSpeedABS */
    { &ComAbsMdlSafe_RxCanGetAirbag_FromMsg }, /* Airbag */
    { &ComAbsMdlSafe_RxCanGetAlive_101_FromMsg }, /* Alive_101 */
    { &ComAbsMdlSafe_RxCanGetCRC_101_FromMsg } /* CRC_101 */
};

const ComAbsMdlSafe_RxCanGetSignalU8ArrConfigType ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[COMABSMDLSAFE_RXCAN_NUM_OF_U8ARR_SIG_CFG] =
    {
        /* { SignalU8ArrBufferLenIdx, ComAbsMdlSafe_RxCanGetSignalU8ArrFunctPtrType }*/
        {0u, NULL_PTR}
};

const ComAbsMdlSafe_RxCanSignalConfigType ComAbsMdlSafe_RxCanSignalConfig[eEndOfSafeRxSignal] =
    {
        /* { SignalLengthInByte ,  SignalBufferStartIdx , SignalInvalidIdx , SignalGetFunctIdx ,
            RxSigMonitoringType , SignalMissingCounterValue } */
        {2U, 0U, COMABSMDLSAFE_RXCAN_NO_INVALDID_SIGNAL, 0U, (COMABSMDLSAFE_RXCAN_SIG_NR_ENABLE | COMABSMDLSAFE_RXCAN_SIG_MISSING_ENABLE), 50U}, /* 0 VehicleSpeedABS eVehicleSpeedABSIn */
        {1U, 0U, COMABSMDLSAFE_RXCAN_NO_INVALDID_SIGNAL, 1U, (COMABSMDLSAFE_RXCAN_SIG_NR_ENABLE | COMABSMDLSAFE_RXCAN_SIG_MISSING_ENABLE), 50U}, /* 1 Airbag eAirbagIn */
        {1U, 1U, COMABSMDLSAFE_RXCAN_NO_INVALDID_SIGNAL, 2U, (COMABSMDLSAFE_RXCAN_SIG_NR_ENABLE | COMABSMDLSAFE_RXCAN_SIG_MISSING_ENABLE), 50U}, /* 2 Alive_101 eAlive_101In */
        {1U, 2U, COMABSMDLSAFE_RXCAN_NO_INVALDID_SIGNAL, 3U, (COMABSMDLSAFE_RXCAN_SIG_NR_ENABLE | COMABSMDLSAFE_RXCAN_SIG_MISSING_ENABLE), 50U} /* 3 CRC_101 eCRC_101In */
};

const ComAbsMdlSafe_RxCanSignalInvalidConfigType ComAbsMdlSafe_RxCanSignalInvalidConfig[COMABSMDLSAFE_RXCAN_NUM_OF_INVALID_SIGNALS] =
    {
        /* {  SignalInvalidSigIdx,  SignalInvalidCounterValue , pSignalInvalidCheckFunc } */
        {0U, 0U, NULL_PTR}
};

void ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core(void)
{
    Std_ReturnType ret = RTE_E_OK;
    uint8 sig_id = 0u;
    SG_ABS local_msg;
    Rte_TransformerError transformerError;
    ret = Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS(&local_msg, &transformerError);

    if (ret == RTE_E_NEVER_RECEIVED)
    {
        for (sig_id = 0u; sig_id < eEndOfSafeRxSignal; sig_id++)
        {
            COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanSignalNRStatus[(uint8)(sig_id >> 3U)], (uint8)(sig_id & 0x07U));
        }
    }
    else if (ret == RTE_E_HARD_TRANSFORMER_ERROR)
    {
        for (sig_id = 0u; sig_id < eEndOfSafeRxSignal; sig_id++)
        {
            COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanSignalInvalidStatus[(uint8)(sig_id >> 3U)], (uint8)(sig_id & 0x07U));
            COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalNRStatus[(uint8)(sig_id >> 3U)], (uint8)(sig_id & 0x07U));
            COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalMissingStatus[(uint8)(sig_id >> 3U)], (uint8)(sig_id & 0x07U));
        }
    }
    else if (ret == RTE_E_SOFT_TRANSFORMER_ERROR)
    {
        for (sig_id = 0u; sig_id < eEndOfSafeRxSignal; sig_id++)
        {
            CComAbsMdlSafe_OnDataRx_VehicleSpeedABS();
            if (transformerError.errorCode == (uint32)E2E_P01STATUS_WRONGCRC)
            {
                COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanSignalInvalidCRCStatus[(uint8)(sig_id >> 3U)], (uint8)(sig_id & 0x07U));
            }
            else if (transformerError.errorCode == (uint32)E2E_P01STATUS_WRONGSEQUENCE)
            {
                COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus[(uint8)(sig_id >> 3U)], (uint8)(sig_id & 0x07U));
            }
            else if (transformerError.errorCode == (uint32)E2E_P01STATUS_REPEATED)
            {
                COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanSignalRepetationCounterStatus[(uint8)(sig_id >> 3U)], (uint8)(sig_id & 0x07U));
            }
            else if ((transformerError.errorCode == (uint32)E2E_P01STATUS_SYNC) || (transformerError.errorCode == (uint32)E2E_P01STATUS_INITIAL))
            {
                for (sig_id = 0u; sig_id < eEndOfSafeRxSignal; sig_id++)
                {
                    COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalNRStatus[(uint8)(sig_id >> 3U)], (uint8)(sig_id & 0x07U));
                    COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalInvalidStatus[(uint8)(sig_id >> 3U)], (uint8)(sig_id & 0x07U));
                    COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalInvalidCRCStatus[(uint8)(sig_id >> 3U)], (uint8)(sig_id & 0x07U));
                    COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus[(uint8)(sig_id >> 3U)], (uint8)(sig_id & 0x07U));
                    COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalRepetationCounterStatus[(uint8)(sig_id >> 3U)], (uint8)(sig_id & 0x07U));
                }
                msg1 = local_msg;
            }
    else
    {
        // do nothing
    }
        }
    }
    else if (ret == RTE_E_OK)
    {
        CComAbsMdlSafe_OnDataRx_VehicleSpeedABS();
        for (sig_id = 0u; sig_id < eEndOfSafeRxSignal; sig_id++)
        {
            COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalNRStatus[(uint8)(sig_id >> 3U)], (uint8)(sig_id & 0x07U));
            COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalInvalidStatus[(uint8)(sig_id >> 3U)], (uint8)(sig_id & 0x07U));
            COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalInvalidCRCStatus[(uint8)(sig_id >> 3U)], (uint8)(sig_id & 0x07U));
            COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus[(uint8)(sig_id >> 3U)], (uint8)(sig_id & 0x07U));
            COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalRepetationCounterStatus[(uint8)(sig_id >> 3U)], (uint8)(sig_id & 0x07U));
        }
                msg1 = local_msg;
    }
    else
    {
        // do nothing
    }
}
/********************************************************************************************************************
*   Getter functions for signals (message-aware: uses correct msg1, msg2, ...)
********************************************************************************************************************/
static void ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg(uint16 *pSignalValue)
{
    *pSignalValue = msg1.VehicleSpeedABS;
}
static void ComAbsMdlSafe_RxCanGetAirbag_FromMsg(uint8 *pSignalValue)
{
    *pSignalValue = msg1.Airbag;
}
static void ComAbsMdlSafe_RxCanGetAlive_101_FromMsg(uint8 *pSignalValue)
{
    *pSignalValue = msg1.Alive_101;
}
static void ComAbsMdlSafe_RxCanGetCRC_101_FromMsg(uint8 *pSignalValue)
{
    *pSignalValue = msg1.CRC_101;
}
/********************************************************************************************************************
*   Message-level OnDataRx callbacks (updated for all signals in message)
********************************************************************************************************************/

void CComAbsMdlSafe_OnDataRx_VehicleSpeedABS(void)
{
    COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalNRStatus[eVehicleSpeedABSIn >> 3U], (eVehicleSpeedABSIn & 0x7U));
    COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanJustRcvdStatus[eVehicleSpeedABSIn >> 3U], (eVehicleSpeedABSIn & 0x7U));
    COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanSignal_currentStatus[eVehicleSpeedABSIn >> 3U], (eVehicleSpeedABSIn & 0x7U));
    ComAbsMdlSafeReloadMissingTimer(eVehicleSpeedABSIn);
    COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalNRStatus[eAirbagIn >> 3U], (eAirbagIn & 0x7U));
    COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanJustRcvdStatus[eAirbagIn >> 3U], (eAirbagIn & 0x7U));
    COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanSignal_currentStatus[eAirbagIn >> 3U], (eAirbagIn & 0x7U));
    ComAbsMdlSafeReloadMissingTimer(eAirbagIn);
    COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalNRStatus[eAlive_101In >> 3U], (eAlive_101In & 0x7U));
    COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanJustRcvdStatus[eAlive_101In >> 3U], (eAlive_101In & 0x7U));
    COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanSignal_currentStatus[eAlive_101In >> 3U], (eAlive_101In & 0x7U));
    ComAbsMdlSafeReloadMissingTimer(eAlive_101In);
    COMABSMDLSAFE_CLEAR_BIT(ComAbsMdlSafe_RxCanSignalNRStatus[eCRC_101In >> 3U], (eCRC_101In & 0x7U));
    COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanJustRcvdStatus[eCRC_101In >> 3U], (eCRC_101In & 0x7U));
    COMABSMDLSAFE_SET_BIT(ComAbsMdlSafe_RxCanSignal_currentStatus[eCRC_101In >> 3U], (eCRC_101In & 0x7U));
    ComAbsMdlSafeReloadMissingTimer(eCRC_101In);
}

#define COMABSMDLSAFE_SEC_CODE_STOP
#define COMABSMDLSAFE_CORE_CONST_SEC_END
#define COMABSMDLSAFE_CORE_DATA_SEC_END
#define COMABSMDLSAFE_CORE_BSS_SEC_END
#include "MemMap.h"
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

