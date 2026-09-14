/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2020. Visteon Corporation owns all rights to           *
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
/*****************************************************************************
 *  File Name         :  E2EXF_CFG_H                                          *
 *  Module Short Name :  E2EXF_CFG_H                                          *
 *  Description       :                                                       *
 *                                                                            *
 *                                                                            *
 * Organization     :  Driver Information Software Section,                   *
 *                     Visteon Software Operation                             *
 *                     Visteon Corporation                                    *
 *                                                                            *
 * ---------------------------------------------------------------------------*
 * Compiler Name    :  GHS Multi                                              *
 * Target Hardware  :  Platform Independent                                   *
 *                                                                            *
 ******************************************************************************/
/*This file contains the sample APIs that perform protect and check functionality*/

/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
/*E2EXf can be initialised by calling the E2EXf_Init function*/

#include "E2EXf_Cfg.h"
#include "Rte_Type.h"
#include "Can_GeneralTypes.h"
#include "Rte_ComCallout.h"

#define E2EXF_SEC_CODE_START
#define E2EXF_CORE_CONST_SEC_START
#define E2EXF_CORE_DATA_SEC_START
#define E2EXF_CORE_BSS_SEC_START
#include "MemMap.h"
const E2E_P01ConfigType E2EdataRx_config[NUM_CAN_MSG_RX] =
    // const E2Euserconfiginputtype E2EdataRx_config[NUM_CAN_MSG_RX]=
    /*DataIDMode ,CounterOffset, CRCOffset, DataID, DataIDNibbleOffset, DataLength, MaxDeltaCounterInit,  MaxNoNewOrRepeatedData,  SyncCounterInit*/
    {
        {E2E_P01_DATAID_BOTH, 40u, 48u, 0x102, 0u, 56u, 0u, 0u, 1u} /* 0 ABS_CONTROL*/
};
const E2E_P01ConfigType E2EdataTx_config[NUM_CAN_MSG_TX] =
    /*DataIDMode ,CounterOffset, CRCOffset, DataID, DataIDNibbleOffset, DataLength, MaxDeltaCounterInit,  MaxNoNewOrRepeatedData,  SyncCounterInit*/
    {
        {E2E_P01_DATAID_BOTH, 8u, 16u, 0x200, 0u, 24, 0u, 0u, 1u} /* 0 ABS_DATA_1*/
};
static E2E_P01CheckStateType E2EstateRx_status[NUM_CAN_MSG_RX] =

    {
        /* Status,LastValidCounter,MaxDeltaCounter,LostData,SyncCounter,NoNewOrRepeatedDataCounter,WaitForFirstData,NewDataAvailable*/
        {0U, 0u, 0u, 0u, 0u, 0u, 0u, TRUE}, /* 1 ABS_DATA_1*/
};
static E2E_P01ProtectStateType E2EstateTx_status[NUM_CAN_MSG_TX] =

    {
        /* Counter*/
        {0U}, /* 0 COM_HS*/
    };


void E2EXf_init(void)
{
	uint8 	fl_index_u8_rx = 0u;
    uint8 	fl_index_u8_tx = 0u;
	for (fl_index_u8_rx=0; fl_index_u8_rx < NUM_CAN_MSG_RX; fl_index_u8_rx++)
	{
		E2E_P01CheckInit(&E2EstateRx_status[fl_index_u8_rx]);
	}
    for( fl_index_u8_tx=0; fl_index_u8_tx < NUM_CAN_MSG_TX; fl_index_u8_tx++)
    {
        E2E_P01ProtectInit(&E2EstateTx_status[fl_index_u8_tx]);
    }
    
}
/**
 * @brief Invokes the integrity check for the signal group COM_ABS for the TrustecSWC_RP component.
 *
 * This function is responsible for performing the integrity check on the signal group
 * COM_ABS_SG_COM_ABS for the TrustecSWC_RP software component. It takes a buffer containing
 * the received data and its length as input, and returns a standard return type indicating
 * the success or failure of the integrity check.
 *
 * @param buffer Pointer to the buffer containing the received data.
 * @param bufferLength Pointer to the length of the received data buffer.
 * @param inputBufferLength The maximum length of the input buffer.
 * @return Std_ReturnType
 *         E_OK if the integrity check was successful, otherwise E_NOT_OK or E_SAFETY_HARD_RUNTIMEERROR.
 */
Std_ReturnType E2EXf_Inv_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS(uint8 *buffer, uint16 *bufferLength, uint16 inputBufferLength)
{

    E2E_P01ConfigType Configptr_Rx;
    E2E_P01ConfigType *ConfigPtr = &Configptr_Rx;
    uint8 fl_index_u8 = 0u;
    uint8 *DataPtr = buffer;
    Std_ReturnType ret = E_NOT_OK;
    if (fl_index_u8 < NUM_CAN_MSG_RX)
    {
        ConfigPtr->DataIDMode = E2EdataRx_config[fl_index_u8].DataIDMode;
        ConfigPtr->DataID = E2EdataRx_config[fl_index_u8].DataID;
        ConfigPtr->DataLength = E2EdataRx_config[fl_index_u8].DataLength;
        ConfigPtr->CounterOffset = E2EdataRx_config[fl_index_u8].CounterOffset;
        ConfigPtr->DataIDNibbleOffset = E2EdataRx_config[fl_index_u8].DataIDNibbleOffset;
        ConfigPtr->CRCOffset = E2EdataRx_config[fl_index_u8].CRCOffset;
        ConfigPtr->MaxDeltaCounterInit = E2EdataRx_config[fl_index_u8].MaxDeltaCounterInit;
        ConfigPtr->SyncCounterInit = E2EdataRx_config[fl_index_u8].SyncCounterInit;
        ConfigPtr->MaxNoNewOrRepeatedData = E2EdataRx_config[fl_index_u8].MaxNoNewOrRepeatedData;

         E2E_P01Check(ConfigPtr, &E2EstateRx_status[fl_index_u8], DataPtr);
        ret = E2EstateRx_status[fl_index_u8].Status;
    }
    
    return ret;
}
/**
 * @brief Transmits the signal group COM_HS for the TrustecSWC_PP component.
 *
 * This function is responsible for handling the transmission of the signal group
 * COM_HS_SG_COM_HS for the TrustecSWC_PP software component. It returns a standard
 * return type indicating the success or failure of the operation.
 *
 * @return Std_ReturnType
 *         E_OK if the transmission was successful, otherwise E_NOT_OK.
 */
Std_ReturnType E2EXf_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS (uint8 *buffer, uint16 *bufferLength, uint16 inputBufferLength)
{
    E2E_P01ConfigType Configptr_Tx;
    E2E_P01ConfigType *ConfigPtr = &Configptr_Tx;
    uint8 fl_index_u8 = 0u;
    uint8 *DataPtr = buffer;
    Std_ReturnType ret = E_NOT_OK;
    if (fl_index_u8 < NUM_CAN_MSG_TX)
    {
        ConfigPtr->DataIDMode = E2EdataTx_config[fl_index_u8].DataIDMode;
        ConfigPtr->DataID = E2EdataTx_config[fl_index_u8].DataID;
        ConfigPtr->DataLength = E2EdataTx_config[fl_index_u8].DataLength;
        ConfigPtr->CounterOffset = E2EdataTx_config[fl_index_u8].CounterOffset;
        ConfigPtr->DataIDNibbleOffset = E2EdataTx_config[fl_index_u8].DataIDNibbleOffset;
        ConfigPtr->CRCOffset = E2EdataTx_config[fl_index_u8].CRCOffset;
        ConfigPtr->MaxDeltaCounterInit = E2EdataTx_config[fl_index_u8].MaxDeltaCounterInit;
        ConfigPtr->SyncCounterInit = E2EdataTx_config[fl_index_u8].SyncCounterInit;
        ConfigPtr->MaxNoNewOrRepeatedData = E2EdataTx_config[fl_index_u8].MaxNoNewOrRepeatedData;

        ret = E2E_P01Protect(ConfigPtr, &E2EstateTx_status[fl_index_u8], DataPtr);
    }
    if (ret == E_OK)
    {
        *bufferLength = (ConfigPtr->DataLength + 7u) / 8u; /* Convert bits to bytes */
    }
    return ret;

}
#define E2EXF_SEC_CODE_STOP
#define E2EXF_CORE_CONST_SEC_END
#define E2EXF_CORE_DATA_SEC_END
#define E2EXF_CORE_BSS_SEC_END

#include "MemMap.h"
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

