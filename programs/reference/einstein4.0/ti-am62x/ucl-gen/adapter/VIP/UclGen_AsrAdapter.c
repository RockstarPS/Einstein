//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2022] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
//
// File generated automatically using Visteon DiCore UCL configuration generator 1.3.3
// Date: Wed Sep 17 12:27:28 IST 2025
// User: SSRINI28
// Gateway: UCL_GW
// Configuration: Platform
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.10
//
//---------------------------------------------------------------------------------------------------------------------

#include <Rte_UclProxyCdd.h>
#include <UclILAdapter.h>
#include <UclILSched.h>
#include <UclCmnSerialize.h>
#include <UclGen_AsrSerialize.h>
#include <UclGen_AsrAdapter.h>
#include <string.h>

//---------------------------------------------------------------------------------------
// Message indexes inside transmit deployments
//---------------------------------------------------------------------------------------
#define PowerSystemStateReqChange_UclPowerDomainStateReqMsg_Index    ((uint8)0u)
#define HealthDumpGetHdr_UclHealthDumpGetMsg_Index    ((uint8)0u)
#define HealthDumpGetData_UclHealthDumpGetMsg_Index    ((uint8)1u)
#define DisplaySetPower_UclDisplaySetPower_Index    ((uint8)0u)
#define TT_Status_UclTelltaleStatusMsg_Index    ((uint8)0u)
#define RTT_Toggle_UclTelltaleStatusMsg_Index    ((uint8)1u)
#define FRTT_Status_UclTelltaleStatusMsg_Index    ((uint8)2u)
#define RTT_Icon_UclTelltaleStatusMsg_Index    ((uint8)3u)
#define RTT_Status_UclTelltaleStatusMsg_Index    ((uint8)4u)
#define WarningExtDisplay_UclWarningDisplayMsg_Index    ((uint8)0u)
#define WarningDisplay_UclWarningDisplayMsg_Index    ((uint8)1u)
#define SlowGaugeInfo_UclSlowGaugeMsg_Index    ((uint8)0u)
#define FastGaugeInfo_UclFastGuageCustomMsg_Index    ((uint8)0u)
#define ShiftPosIndStatus_UclShitPositionIndicatorMsg_Index    ((uint8)0u)
#define IlluminationData_UclIlluminationDataMsg_Index    ((uint8)0u)
#define UpdateShortServiceReq_UpdateShortServiceReq_Index    ((uint8)0u)
#define UpdateLongServiceReq_UpdateLongServiceReq_Index    ((uint8)0u)
#define DiagDIDRequest_UclDiagRequest_Index    ((uint8)0u)
#define DiagIOCtrlRequest_UclDiagRequest_Index    ((uint8)1u)
#define DiagRoutineRequest_UclDiagRequest_Index    ((uint8)2u)
#define DLTMessageReadRequest_UclDLTMessageReadRequest_Index    ((uint8)0u)
#define DLTControlMessageReponse_UclDLTControlMessageReponse_Index    ((uint8)0u)

//---------------------------------------------------------------------------------------
// Transmit deployment indexes
//---------------------------------------------------------------------------------------
#define Tx_UclPowerDomainStateReqMsg_Index    ((uint8)0u)
#define Tx_UclHealthDumpGetMsg_Index    ((uint8)1u)
#define Tx_UclDisplaySetPower_Index    ((uint8)2u)
#define Tx_UclTelltaleStatusMsg_Index    ((uint8)3u)
#define Tx_UclWarningDisplayMsg_Index    ((uint8)4u)
#define Tx_UclSlowGaugeMsg_Index    ((uint8)5u)
#define Tx_UclFastGuageCustomMsg_Index    ((uint8)6u)
#define Tx_UclShitPositionIndicatorMsg_Index    ((uint8)7u)
#define Tx_UclIlluminationDataMsg_Index    ((uint8)8u)
#define Tx_UpdateShortServiceReq_Index    ((uint8)9u)
#define Tx_UpdateLongServiceReq_Index    ((uint8)10u)
#define Tx_UclDiagRequest_Index    ((uint8)11u)
#define Tx_UclDLTMessageReadRequest_Index    ((uint8)12u)
#define Tx_UclDLTControlMessageReponse_Index    ((uint8)13u)

//---------------------------------------------------------------------------------------------------------------------
// Comparison of types
//---------------------------------------------------------------------------------------------------------------------
static boolean UclGenCompare_SPowerSystemStateReqChange(SPowerSystemStateReqChange *data1, SPowerSystemStateReqChange *data2);
static boolean UclGenCompare_SDisplaySetPower(SDisplaySetPower *data1, SDisplaySetPower *data2);
static boolean UclGenCompare_SRTT_Toggle(SRTT_Toggle *data1, SRTT_Toggle *data2);
static boolean UclGenCompare_SWarningExtDisplay(SWarningExtDisplay *data1, SWarningExtDisplay *data2);
static boolean UclGenCompare_SWarningDisplay(SWarningDisplay *data1, SWarningDisplay *data2);
static boolean UclGenCompare_SGaugeInfo_2(SGaugeInfo_2 data1, SGaugeInfo_2 data2);
static boolean UclGenCompare_SGaugeInfo(SGaugeInfo *data1, SGaugeInfo *data2);
static boolean UclGenCompare_SGaugeInfo_u32dyn_3(SGaugeInfo_u32dyn_3 data1, SGaugeInfo_u32dyn_3 data2);
static boolean UclGenCompare_SGaugeInfo_u32dyn(SGaugeInfo_u32dyn *data1, SGaugeInfo_u32dyn *data2);
static boolean UclGenCompare_SShiftInd(SShiftInd *data1, SShiftInd *data2);
static boolean UclGenCompare_SIlluminationData(SIlluminationData *data1, SIlluminationData *data2);
static boolean UclGenCompare_SUpdateShortServiceReq(SUpdateShortServiceReq *data1, SUpdateShortServiceReq *data2);
static boolean UclGenCompare_SUpdateLongServiceReq(SUpdateLongServiceReq *data1, SUpdateLongServiceReq *data2);
static boolean UclGenCompare_SDiagDIDRequest(SDiagDIDRequest *data1, SDiagDIDRequest *data2);
static boolean UclGenCompare_SDiagIOCtrlRequest(SDiagIOCtrlRequest *data1, SDiagIOCtrlRequest *data2);
static boolean UclGenCompare_SDiagRoutineRequest(SDiagRoutineRequest *data1, SDiagRoutineRequest *data2);

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Compare of data of type SPowerSystemStateReqChange.
///
/// @param  data1:         First data for comparison
/// @param  data2:         Second data for comparison
///
/// @return TRUE:     The data is identical
///         FALSE:    The data is not identical
//---------------------------------------------------------------------------------------------------------------------
static boolean UclGenCompare_SPowerSystemStateReqChange(SPowerSystemStateReqChange *data1, SPowerSystemStateReqChange *data2)
{
    boolean result = TRUE;

    if (FALSE != result)
    {
        result = (data1->domainId == data2->domainId);
    }
    if (FALSE != result)
    {
        result = (data1->state == data2->state);
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Compare of data of type SDisplaySetPower.
///
/// @param  data1:         First data for comparison
/// @param  data2:         Second data for comparison
///
/// @return TRUE:     The data is identical
///         FALSE:    The data is not identical
//---------------------------------------------------------------------------------------------------------------------
static boolean UclGenCompare_SDisplaySetPower(SDisplaySetPower *data1, SDisplaySetPower *data2)
{
    boolean result = TRUE;

    if (FALSE != result)
    {
        result = (data1->displayId == data2->displayId);
    }
    if (FALSE != result)
    {
        result = (data1->state == data2->state);
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Compare of data of type SRTT_Toggle.
///
/// @param  data1:         First data for comparison
/// @param  data2:         Second data for comparison
///
/// @return TRUE:     The data is identical
///         FALSE:    The data is not identical
//---------------------------------------------------------------------------------------------------------------------
static boolean UclGenCompare_SRTT_Toggle(SRTT_Toggle *data1, SRTT_Toggle *data2)
{
    boolean result = TRUE;

    if (FALSE != result)
    {
        result = (data1->positions == data2->positions);
    }
    if (FALSE != result)
    {
        result = (data1->display == data2->display);
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Compare of data of type SWarningExtDisplay.
///
/// @param  data1:         First data for comparison
/// @param  data2:         Second data for comparison
///
/// @return TRUE:     The data is identical
///         FALSE:    The data is not identical
//---------------------------------------------------------------------------------------------------------------------
static boolean UclGenCompare_SWarningExtDisplay(SWarningExtDisplay *data1, SWarningExtDisplay *data2)
{
    boolean result = TRUE;

    if (FALSE != result)
    {
        result = (data1->show == data2->show);
    }
    if (FALSE != result)
    {
        result = (data1->warningId == data2->warningId);
    }
    if (FALSE != result)
    {
        result = (0 == memcmp(data1->dynData, data2->dynData, sizeof(data_u8_8)));
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Compare of data of type SWarningDisplay.
///
/// @param  data1:         First data for comparison
/// @param  data2:         Second data for comparison
///
/// @return TRUE:     The data is identical
///         FALSE:    The data is not identical
//---------------------------------------------------------------------------------------------------------------------
static boolean UclGenCompare_SWarningDisplay(SWarningDisplay *data1, SWarningDisplay *data2)
{
    boolean result = TRUE;

    if (FALSE != result)
    {
        result = (data1->show == data2->show);
    }
    if (FALSE != result)
    {
        result = (data1->warningId == data2->warningId);
    }
    if (FALSE != result)
    {
        result = (0 == memcmp(data1->dynData, data2->dynData, sizeof(data_u8_8)));
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Compare of data of type SGaugeInfo_2.
///
/// @param  data1:         First data for comparison
/// @param  data2:         Second data for comparison
///
/// @return TRUE:     The data is identical
///         FALSE:    The data is not identical
//---------------------------------------------------------------------------------------------------------------------
static boolean UclGenCompare_SGaugeInfo_2(SGaugeInfo_2 data1, SGaugeInfo_2 data2)
{
    boolean result = TRUE;
    uint16 u16ArrayIndex;

    for (u16ArrayIndex = 0; (u16ArrayIndex < 2u) && (FALSE != result); u16ArrayIndex++)
    {
        result = UclGenCompare_SGaugeInfo(&(data1[u16ArrayIndex]), &(data2[u16ArrayIndex]));
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Compare of data of type SGaugeInfo.
///
/// @param  data1:         First data for comparison
/// @param  data2:         Second data for comparison
///
/// @return TRUE:     The data is identical
///         FALSE:    The data is not identical
//---------------------------------------------------------------------------------------------------------------------
static boolean UclGenCompare_SGaugeInfo(SGaugeInfo *data1, SGaugeInfo *data2)
{
    boolean result = TRUE;

    if (FALSE != result)
    {
        result = (data1->id == data2->id);
    }
    if (FALSE != result)
    {
        result = (data1->position == data2->position);
    }
    if (FALSE != result)
    {
        result = (data1->digitalData == data2->digitalData);
    }
    if (FALSE != result)
    {
        result = (data1->unit == data2->unit);
    }
    if (FALSE != result)
    {
        result = (data1->dynData == data2->dynData);
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Compare of data of type SGaugeInfo_u32dyn_3.
///
/// @param  data1:         First data for comparison
/// @param  data2:         Second data for comparison
///
/// @return TRUE:     The data is identical
///         FALSE:    The data is not identical
//---------------------------------------------------------------------------------------------------------------------
static boolean UclGenCompare_SGaugeInfo_u32dyn_3(SGaugeInfo_u32dyn_3 data1, SGaugeInfo_u32dyn_3 data2)
{
    boolean result = TRUE;
    uint16 u16ArrayIndex;

    for (u16ArrayIndex = 0; (u16ArrayIndex < 3u) && (FALSE != result); u16ArrayIndex++)
    {
        result = UclGenCompare_SGaugeInfo_u32dyn(&(data1[u16ArrayIndex]), &(data2[u16ArrayIndex]));
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Compare of data of type SGaugeInfo_u32dyn.
///
/// @param  data1:         First data for comparison
/// @param  data2:         Second data for comparison
///
/// @return TRUE:     The data is identical
///         FALSE:    The data is not identical
//---------------------------------------------------------------------------------------------------------------------
static boolean UclGenCompare_SGaugeInfo_u32dyn(SGaugeInfo_u32dyn *data1, SGaugeInfo_u32dyn *data2)
{
    boolean result = TRUE;

    if (FALSE != result)
    {
        result = (data1->id == data2->id);
    }
    if (FALSE != result)
    {
        result = (data1->position == data2->position);
    }
    if (FALSE != result)
    {
        result = (data1->digitalData == data2->digitalData);
    }
    if (FALSE != result)
    {
        result = (data1->unit == data2->unit);
    }
    if (FALSE != result)
    {
        result = (data1->dynData == data2->dynData);
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Compare of data of type SShiftInd.
///
/// @param  data1:         First data for comparison
/// @param  data2:         Second data for comparison
///
/// @return TRUE:     The data is identical
///         FALSE:    The data is not identical
//---------------------------------------------------------------------------------------------------------------------
static boolean UclGenCompare_SShiftInd(SShiftInd *data1, SShiftInd *data2)
{
    boolean result = TRUE;

    if (FALSE != result)
    {
        result = (data1->Shift_Ind_Pos == data2->Shift_Ind_Pos);
    }
    if (FALSE != result)
    {
        result = (data1->Shift_Ind_BlinkReq == data2->Shift_Ind_BlinkReq);
    }
    if (FALSE != result)
    {
        result = (data1->Shift_Ind_Up == data2->Shift_Ind_Up);
    }
    if (FALSE != result)
    {
        result = (data1->Shift_Ind_Down == data2->Shift_Ind_Down);
    }
    if (FALSE != result)
    {
        result = (data1->Shift_Ind_DisplayDecState == data2->Shift_Ind_DisplayDecState);
    }
    if (FALSE != result)
    {
        result = (data1->Shift_Ind_Screen_ShiftType == data2->Shift_Ind_Screen_ShiftType);
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Compare of data of type SIlluminationData.
///
/// @param  data1:         First data for comparison
/// @param  data2:         Second data for comparison
///
/// @return TRUE:     The data is identical
///         FALSE:    The data is not identical
//---------------------------------------------------------------------------------------------------------------------
static boolean UclGenCompare_SIlluminationData(SIlluminationData *data1, SIlluminationData *data2)
{
    boolean result = TRUE;

    if (FALSE != result)
    {
        result = (data1->data == data2->data);
    }
    if (FALSE != result)
    {
        result = (data1->dayStep == data2->dayStep);
    }
    if (FALSE != result)
    {
        result = (data1->nightStep == data2->nightStep);
    }
    if (FALSE != result)
    {
        result = (data1->daynightStatus == data2->daynightStatus);
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Compare of data of type SUpdateShortServiceReq.
///
/// @param  data1:         First data for comparison
/// @param  data2:         Second data for comparison
///
/// @return TRUE:     The data is identical
///         FALSE:    The data is not identical
//---------------------------------------------------------------------------------------------------------------------
static boolean UclGenCompare_SUpdateShortServiceReq(SUpdateShortServiceReq *data1, SUpdateShortServiceReq *data2)
{
    boolean result = TRUE;

    if (FALSE != result)
    {
        result = (data1->msgId == data2->msgId);
    }
    if (FALSE != result)
    {
        result = (data1->msgSize == data2->msgSize);
    }
    if (FALSE != result)
    {
        result = (data1->memoryType == data2->memoryType);
    }
    if (FALSE != result)
    {
        result = (data1->memoryCmd == data2->memoryCmd);
    }
    if (FALSE != result)
    {
        result = (data1->sid == data2->sid);
    }
    if (FALSE != result)
    {
        result = (data1->length == data2->length);
    }
    if (FALSE != result)
    {
        result = (0 == memcmp(data1->data, data2->data, sizeof(data_u8_64)));
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Compare of data of type SUpdateLongServiceReq.
///
/// @param  data1:         First data for comparison
/// @param  data2:         Second data for comparison
///
/// @return TRUE:     The data is identical
///         FALSE:    The data is not identical
//---------------------------------------------------------------------------------------------------------------------
static boolean UclGenCompare_SUpdateLongServiceReq(SUpdateLongServiceReq *data1, SUpdateLongServiceReq *data2)
{
    boolean result = TRUE;

    if (FALSE != result)
    {
        result = (data1->msgId == data2->msgId);
    }
    if (FALSE != result)
    {
        result = (data1->msgSize == data2->msgSize);
    }
    if (FALSE != result)
    {
        result = (data1->memoryType == data2->memoryType);
    }
    if (FALSE != result)
    {
        result = (data1->memoryCmd == data2->memoryCmd);
    }
    if (FALSE != result)
    {
        result = (data1->sid == data2->sid);
    }
    if (FALSE != result)
    {
        result = (data1->length == data2->length);
    }
    if (FALSE != result)
    {
        result = (0 == memcmp(data1->data, data2->data, sizeof(data_u8_2048)));
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Compare of data of type SDiagDIDRequest.
///
/// @param  data1:         First data for comparison
/// @param  data2:         Second data for comparison
///
/// @return TRUE:     The data is identical
///         FALSE:    The data is not identical
//---------------------------------------------------------------------------------------------------------------------
static boolean UclGenCompare_SDiagDIDRequest(SDiagDIDRequest *data1, SDiagDIDRequest *data2)
{
    boolean result = TRUE;

    if (FALSE != result)
    {
        result = (data1->did == data2->did);
    }
    if (FALSE != result)
    {
        result = (data1->didType == data2->didType);
    }
    if (FALSE != result)
    {
        result = (data1->dataLen == data2->dataLen);
    }
    if (FALSE != result)
    {
        result = (0 == memcmp(data1->data, data2->data, sizeof(data_u8_256)));
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Compare of data of type SDiagIOCtrlRequest.
///
/// @param  data1:         First data for comparison
/// @param  data2:         Second data for comparison
///
/// @return TRUE:     The data is identical
///         FALSE:    The data is not identical
//---------------------------------------------------------------------------------------------------------------------
static boolean UclGenCompare_SDiagIOCtrlRequest(SDiagIOCtrlRequest *data1, SDiagIOCtrlRequest *data2)
{
    boolean result = TRUE;

    if (FALSE != result)
    {
        result = (data1->did == data2->did);
    }
    if (FALSE != result)
    {
        result = (data1->optionCtrl == data2->optionCtrl);
    }
    if (FALSE != result)
    {
        result = (data1->dataLen == data2->dataLen);
    }
    if (FALSE != result)
    {
        result = (0 == memcmp(data1->data, data2->data, sizeof(data_u8_256)));
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Compare of data of type SDiagRoutineRequest.
///
/// @param  data1:         First data for comparison
/// @param  data2:         Second data for comparison
///
/// @return TRUE:     The data is identical
///         FALSE:    The data is not identical
//---------------------------------------------------------------------------------------------------------------------
static boolean UclGenCompare_SDiagRoutineRequest(SDiagRoutineRequest *data1, SDiagRoutineRequest *data2)
{
    boolean result = TRUE;

    if (FALSE != result)
    {
        result = (data1->routineId == data2->routineId);
    }
    if (FALSE != result)
    {
        result = (data1->routineType == data2->routineType);
    }
    if (FALSE != result)
    {
        result = (data1->dataLen == data2->dataLen);
    }
    if (FALSE != result)
    {
        result = (0 == memcmp(data1->data, data2->data, sizeof(data_u8_256)));
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
// Callouts for received messages
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message PowerSystemState. Deserialize received buffer and publish data to the RTE.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Data is deserialized and published to the RTE
///         FALSE: Not enough data 
///                Deserialization error 
///                RTE write error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_PowerSystemState(uint8 *pMsgBuff, uint16 Size)
{
    uint16 u16BytesConsumed = 0u;
    SPowerSystemState sPowerSystemStateLocal;
    uint8 result = FALSE;
  
    if(Size >= PowerSystemState_BufferSize)
    {
        result = (UCL_E_OK == UclCmnDeserialize_SPowerSystemState(&(sPowerSystemStateLocal), pMsgBuff, &u16BytesConsumed));
        if(FALSE != result)
        {
            result = (uint8)(E_OK == Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&sPowerSystemStateLocal));
        }
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message PowerExtendShutdownTime. Deserialize received buffer and publish data to the RTE.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Data is deserialized and published to the RTE
///         FALSE: Not enough data 
///                Deserialization error 
///                RTE write error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_PowerExtendShutdownTime(uint8 *pMsgBuff, uint16 Size)
{
    uint16 u16BytesConsumed = 0u;
    SPowerExtendShutdownTime sPowerExtendShutdownTimeLocal;
    uint8 result = FALSE;
  
    if(Size >= PowerExtendShutdownTime_BufferSize)
    {
        result = (UCL_E_OK == UclCmnDeserialize_SPowerExtendShutdownTime(&(sPowerExtendShutdownTimeLocal), pMsgBuff, &u16BytesConsumed));
        if(FALSE != result)
        {
            result = (uint8)(E_OK == Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&sPowerExtendShutdownTimeLocal));
        }
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message PowerKeepSystemAwake. Deserialize received buffer and publish data to the RTE.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Data is deserialized and published to the RTE
///         FALSE: Not enough data 
///                Deserialization error 
///                RTE write error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_PowerKeepSystemAwake(uint8 *pMsgBuff, uint16 Size)
{
    uint16 u16BytesConsumed = 0u;
    SPowerKeepSystemAwake sPowerKeepSystemAwakeLocal;
    uint8 result = FALSE;
  
    if(Size >= PowerKeepSystemAwake_BufferSize)
    {
        result = (UCL_E_OK == UclCmnDeserialize_SPowerKeepSystemAwake(&(sPowerKeepSystemAwakeLocal), pMsgBuff, &u16BytesConsumed));
        if(FALSE != result)
        {
            result = (uint8)(E_OK == Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&sPowerKeepSystemAwakeLocal));
        }
    }

    return result;
}










//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message HealthDomainHeartbeat. Deserialize received buffer and publish data to the RTE.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Data is deserialized and published to the RTE
///         FALSE: Not enough data 
///                Deserialization error 
///                RTE write error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_HealthDomainHeartbeat(uint8 *pMsgBuff, uint16 Size)
{
    uint16 u16BytesConsumed = 0u;
    SHealthDomainHeartbeat sHealthDomainHeartbeatLocal;
    uint8 result = FALSE;
  
    if(Size >= HealthDomainHeartbeat_BufferSize)
    {
        result = (UCL_E_OK == UclCmnDeserialize_SHealthDomainHeartbeat(&(sHealthDomainHeartbeatLocal), pMsgBuff, &u16BytesConsumed));
        if(FALSE != result)
        {
            result = (uint8)(E_OK == Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&sHealthDomainHeartbeatLocal));
        }
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message HealthDomainFatalError. Deserialize received buffer and publish data to the RTE.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Data is deserialized and published to the RTE
///         FALSE: Not enough data 
///                Deserialization error 
///                RTE write error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_HealthDomainFatalError(uint8 *pMsgBuff, uint16 Size)
{
    uint16 u16BytesConsumed = 0u;
    SHealthDomainFatalError sHealthDomainFatalErrorLocal;
    uint8 result = FALSE;
  
    if(Size >= HealthDomainFatalError_BufferSize)
    {
        result = (UCL_E_OK == UclCmnDeserialize_SHealthDomainFatalError(&(sHealthDomainFatalErrorLocal), pMsgBuff, &u16BytesConsumed));
        if(FALSE != result)
        {
            result = (uint8)(E_OK == Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&sHealthDomainFatalErrorLocal));
        }
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message HealthEventRecord. Deserialize received buffer and publish data to the RTE.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Data is deserialized and published to the RTE
///         FALSE: Not enough data 
///                Deserialization error 
///                RTE write error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_HealthEventRecord(uint8 *pMsgBuff, uint16 Size)
{
    uint16 u16BytesConsumed = 0u;
    SHealthEventRecord sHealthEventRecordLocal;
    uint8 result = FALSE;
  
    if(Size >= HealthEventRecord_BufferSize)
    {
        result = (UCL_E_OK == UclCmnDeserialize_SHealthEventRecord(&(sHealthEventRecordLocal), pMsgBuff, &u16BytesConsumed));
        if(FALSE != result)
        {
            result = (uint8)(E_OK == Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(&sHealthEventRecordLocal));
        }
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message HealthDumpHdrInfo. Deserialize received buffer and publish data to the RTE.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Data is deserialized and published to the RTE
///         FALSE: Not enough data 
///                Deserialization error 
///                RTE write error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_HealthDumpHdrInfo(uint8 *pMsgBuff, uint16 Size)
{
    uint16 u16BytesConsumed = 0u;
    SHealthDumpHdrInfo sHealthDumpHdrInfoLocal;
    uint8 result = FALSE;
  
    if(Size >= HealthDumpHdrInfo_BufferSize)
    {
        result = (UCL_E_OK == UclCmnDeserialize_uint32(&(sHealthDumpHdrInfoLocal.fileSize), pMsgBuff, &u16BytesConsumed));
        if(FALSE != result)
        {
            result = (uint8)(E_OK == Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&sHealthDumpHdrInfoLocal));
        }
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message HealthDumpData. Deserialize received buffer and publish data to the RTE.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Data is deserialized and published to the RTE
///         FALSE: Not enough data 
///                Deserialization error 
///                RTE write error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_HealthDumpData(uint8 *pMsgBuff, uint16 Size)
{
    uint16 u16BytesConsumed = 0u;
    SHealthDumpData sHealthDumpDataLocal;
    uint8 result = FALSE;
  
    if(Size >= HealthDumpData_BufferSize)
    {
        result = (UCL_E_OK == UclCmnDeserialize_SHealthDumpData(&(sHealthDumpDataLocal), pMsgBuff, &u16BytesConsumed));
        if(FALSE != result)
        {
            result = (uint8)(E_OK == Rte_Send_pSR_HealthDumpData_HealthDumpDataData(&sHealthDumpDataLocal));
        }
    }

    return result;
}





//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message DisplayCurrentState. Deserialize received buffer and publish data to the RTE.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Data is deserialized and published to the RTE
///         FALSE: Not enough data 
///                Deserialization error 
///                RTE write error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_DisplayCurrentState(uint8 *pMsgBuff, uint16 Size)
{
    uint16 u16BytesConsumed = 0u;
    SDisplayCurrentState sDisplayCurrentStateLocal;
    uint8 result = FALSE;
  
    if(Size >= DisplayCurrentState_BufferSize)
    {
        result = (UCL_E_OK == UclCmnDeserialize_SDisplayCurrentState(&(sDisplayCurrentStateLocal), pMsgBuff, &u16BytesConsumed));
        if(FALSE != result)
        {
            result = (uint8)(E_OK == Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&sDisplayCurrentStateLocal));
        }
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message EmmcErrorNotifier. Deserialize received buffer and publish data to the RTE.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Data is deserialized and published to the RTE
///         FALSE: Not enough data 
///                Deserialization error 
///                RTE write error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_EmmcErrorNotifier(uint8 *pMsgBuff, uint16 Size)
{
    uint16 u16BytesConsumed = 0u;
    SEmmcErrorNotifier sEmmcErrorNotifierLocal;
    uint8 result = FALSE;
  
    if(Size >= EmmcErrorNotifier_BufferSize)
    {
        result = (UCL_E_OK == UclCmnDeserialize_uint32(&(sEmmcErrorNotifierLocal.errorCode), pMsgBuff, &u16BytesConsumed));
        if(FALSE != result)
        {
            result = (uint8)(E_OK == Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(&sEmmcErrorNotifierLocal));
        }
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message WarningDisplayAvailable. Deserialize received buffer and publish data to the RTE.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Data is deserialized and published to the RTE
///         FALSE: Not enough data 
///                Deserialization error 
///                RTE write error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_WarningDisplayAvailable(uint8 *pMsgBuff, uint16 Size)
{
    uint16 u16BytesConsumed = 0u;
    SWarningDisplayAvailable sWarningDisplayAvailableLocal;
    uint8 result = FALSE;
  
    if(Size >= WarningDisplayAvailable_BufferSize)
    {
        result = (UCL_E_OK == UclCmnDeserialize_uint8(&(sWarningDisplayAvailableLocal.status), pMsgBuff, &u16BytesConsumed));
        if(FALSE != result)
        {
            result = (uint8)(E_OK == Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(&sWarningDisplayAvailableLocal));
        }
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message WarningStatus. Deserialize received buffer and publish data to the RTE.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Data is deserialized and published to the RTE
///         FALSE: Not enough data 
///                Deserialization error 
///                RTE write error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_WarningStatus(uint8 *pMsgBuff, uint16 Size)
{
    uint16 u16BytesConsumed = 0u;
    SWarningStatus sWarningStatusLocal;
    uint8 result = FALSE;
  
    if(Size >= WarningStatus_BufferSize)
    {
        result = (UCL_E_OK == UclCmnDeserialize_SWarningStatus(&(sWarningStatusLocal), pMsgBuff, &u16BytesConsumed));
        if(FALSE != result)
        {
            result = (uint8)(E_OK == Rte_Write_pSR_WarningStatus_WarningStatusData(&sWarningStatusLocal));
        }
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message SafeHMIReadyStatus. Deserialize received buffer and publish data to the RTE.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Data is deserialized and published to the RTE
///         FALSE: Not enough data 
///                Deserialization error 
///                RTE write error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_SafeHMIReadyStatus(uint8 *pMsgBuff, uint16 Size)
{
    uint16 u16BytesConsumed = 0u;
    SSafeHMIReadyStatus sSafeHMIReadyStatusLocal;
    uint8 result = FALSE;
  
    if(Size >= SafeHMIReadyStatus_BufferSize)
    {
        result = (UCL_E_OK == UclCmnDeserialize_uint8(&(sSafeHMIReadyStatusLocal.status), pMsgBuff, &u16BytesConsumed));
        if(FALSE != result)
        {
            result = (uint8)(E_OK == Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(&sSafeHMIReadyStatusLocal));
        }
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message MainHMIReadyStatus. Deserialize received buffer and publish data to the RTE.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Data is deserialized and published to the RTE
///         FALSE: Not enough data 
///                Deserialization error 
///                RTE write error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_MainHMIReadyStatus(uint8 *pMsgBuff, uint16 Size)
{
    uint16 u16BytesConsumed = 0u;
    SMainHMIReadyStatus sMainHMIReadyStatusLocal;
    uint8 result = FALSE;
  
    if(Size >= MainHMIReadyStatus_BufferSize)
    {
        result = (UCL_E_OK == UclCmnDeserialize_uint8(&(sMainHMIReadyStatusLocal.status), pMsgBuff, &u16BytesConsumed));
        if(FALSE != result)
        {
            result = (uint8)(E_OK == Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(&sMainHMIReadyStatusLocal));
        }
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message UpdateShortServiceResp. Deserialize received buffer and publish data to the RTE.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Data is deserialized and published to the RTE
///         FALSE: Not enough data 
///                Deserialization error 
///                RTE write error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_UpdateShortServiceResp(uint8 *pMsgBuff, uint16 Size)
{
    uint16 u16BytesConsumed = 0u;
    SUpdateShortServiceResp sUpdateShortServiceRespLocal;
    uint8 result = FALSE;
  
    if(Size >= UpdateShortServiceResp_BufferSize)
    {
        result = (UCL_E_OK == UclCmnDeserialize_SUpdateShortServiceResp(&(sUpdateShortServiceRespLocal), pMsgBuff, &u16BytesConsumed));
        if(FALSE != result)
        {
            result = (uint8)(E_OK == Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&sUpdateShortServiceRespLocal));
        }
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message DiagResponse. Deserialize received buffer and publish data to the RTE.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Data is deserialized and published to the RTE
///         FALSE: Not enough data 
///                Deserialization error 
///                RTE write error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_DiagResponse(uint8 *pMsgBuff, uint16 Size)
{
    uint16 u16BytesConsumed = 0u;
    SDiagResponse sDiagResponseLocal;
    uint8 result = FALSE;
  
    if(Size >= DiagResponse_BufferSize)
    {
        result = (UCL_E_OK == UclCmnDeserialize_SDiagResponse(&(sDiagResponseLocal), pMsgBuff, &u16BytesConsumed));
        if(FALSE != result)
        {
            result = (uint8)(E_OK == Rte_Send_pSR_DiagResponse_DiagResponseData(&sDiagResponseLocal));
        }
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message DLTMessageReadAck. Deserialize received buffer and publish data to the RTE.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Data is deserialized and published to the RTE
///         FALSE: Not enough data 
///                Deserialization error 
///                RTE write error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_DLTMessageReadAck(uint8 *pMsgBuff, uint16 Size)
{
    uint16 u16BytesConsumed = 0u;
    SDLTMessageReadAck sDLTMessageReadAckLocal;
    uint8 result = FALSE;
  
    if(Size >= DLTMessageReadAck_BufferSize)
    {
        result = (UCL_E_OK == UclCmnDeserialize_data_u8_2(&(sDLTMessageReadAckLocal.status), pMsgBuff, &u16BytesConsumed));
        if(FALSE != result)
        {
            result = (uint8)(E_OK == Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(&sDLTMessageReadAckLocal));
        }
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message DLTControlMessageRequest. Deserialize received buffer and publish data to the RTE.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Data is deserialized and published to the RTE
///         FALSE: Not enough data 
///                Deserialization error 
///                RTE write error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_DLTControlMessageRequest(uint8 *pMsgBuff, uint16 Size)
{
    uint16 u16BytesConsumed = 0u;
    SDLTControlMessageRequest sDLTControlMessageRequestLocal;
    uint8 result = FALSE;
  
    if(Size >= DLTControlMessageRequest_BufferSize)
    {
        result = (UCL_E_OK == UclCmnDeserialize_data_u8_2(&(sDLTControlMessageRequestLocal.status), pMsgBuff, &u16BytesConsumed));
        if(FALSE != result)
        {
            result = (uint8)(E_OK == Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(&sDLTControlMessageRequestLocal));
        }
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
// Transmited messages
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message PowerSystemStateReqChange
//---------------------------------------------------------------------------------------------------------------------
void OnDre_PowerSystemStateReqChange(void)
{
    UclILSched_NotifyMessageUpdate( 0u, Tx_UclPowerDomainStateReqMsg_Index, PowerSystemStateReqChange_UclPowerDomainStateReqMsg_Index, NULL, 0);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message PowerSystemStateReqChange
//---------------------------------------------------------------------------------------------------------------------
static const SPowerSystemStateReqChange sPowerSystemStateReqChangeStatic_Initializer = {.domainId = 0, .state = 0};
static SPowerSystemStateReqChange sPowerSystemStateReqChangeStatic = {.domainId = 0, .state = 0};

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: PowerSystemStateReqChange
///
/// @param  pMsgBuff:     Buffer to store serialized message
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return TRUE:  Data is retrieved and serialized successfully
///         FALSE: Invalid 'returnType'
///                Serialization failure
///                No new data in case of 'eUclILAdapterDataType_OnChange'
///                RTE communication error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_PowerSystemStateReqChange(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    SPowerSystemStateReqChange sPowerSystemStateReqChangeLocal;
    uint8 result = FALSE;
    Std_ReturnType resultRte = E_OK;
    static uint8 updated = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != updated )
            {
                result = (UCL_E_OK == UclCmnSerialize_SPowerSystemStateReqChange(&(sPowerSystemStateReqChangeStatic), pMsgBuff, pBytesCopied));
            }
            break;
            
        case eUclILAdapterDataType_OnChange:        ///< Adapter to return if the data is changed
            updated = FALSE;
            resultRte = Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&sPowerSystemStateReqChangeLocal);
            if(E_OK == resultRte)
            {
                boolean compare = UclGenCompare_SPowerSystemStateReqChange(&(sPowerSystemStateReqChangeLocal), &(sPowerSystemStateReqChangeStatic));
                if(FALSE == compare)
                {
                    updated = TRUE;
                    sPowerSystemStateReqChangeStatic = sPowerSystemStateReqChangeLocal;    // signal update only
                    result = (UCL_E_OK == UclCmnSerialize_SPowerSystemStateReqChange(&(sPowerSystemStateReqChangeStatic), pMsgBuff, pBytesCopied));
                }
            }
            break;
            
        case eUclILAdapterDataType_Always:          ///< Adapter to return the latest data, if available
            updated = TRUE;
            resultRte = Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&sPowerSystemStateReqChangeLocal);
            if(E_OK == resultRte)
            {
                sPowerSystemStateReqChangeStatic = sPowerSystemStateReqChangeLocal;    // signal update only
                result = (UCL_E_OK == UclCmnSerialize_SPowerSystemStateReqChange(&(sPowerSystemStateReqChangeStatic), pMsgBuff, pBytesCopied));
            }
            break;

        default:
            break;
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message HealthDumpGetHdr
//---------------------------------------------------------------------------------------------------------------------
void OnDre_HealthDumpGetHdr(void)
{
    UclILSched_NotifyMessageUpdate( 0u, Tx_UclHealthDumpGetMsg_Index, HealthDumpGetHdr_UclHealthDumpGetMsg_Index, NULL, 0);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message HealthDumpGetHdr
//---------------------------------------------------------------------------------------------------------------------
static const SHealthDumpGetHdr sHealthDumpGetHdrStatic_Initializer = {.encrypt = 0};
static SHealthDumpGetHdr sHealthDumpGetHdrStatic = {.encrypt = 0};

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: HealthDumpGetHdr
///
/// @param  pMsgBuff:     Buffer to store serialized message
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return TRUE:  Data is retrieved and serialized successfully
///         FALSE: Invalid 'returnType'
///                Serialization failure
///                No new data in case of 'eUclILAdapterDataType_OnChange'
///                RTE communication error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_HealthDumpGetHdr(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    SHealthDumpGetHdr sHealthDumpGetHdrLocal;
    uint8 result = FALSE;
    Std_ReturnType resultRte = E_OK;
    static uint8 updated = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != updated )
            {
                result = (UCL_E_OK == UclCmnSerialize_uint8(sHealthDumpGetHdrStatic.encrypt, pMsgBuff, pBytesCopied));
            }
            break;
            
        case eUclILAdapterDataType_OnChange:        ///< Adapter to return if the data is changed
            updated = FALSE;
            do
            {
                resultRte = Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&sHealthDumpGetHdrLocal);
                if(!Rte_IsInfrastructureError(resultRte) && (E_OK == Rte_ApplicationError(resultRte)))
                {
                    if(sHealthDumpGetHdrLocal.encrypt != sHealthDumpGetHdrStatic.encrypt)
                    {
                        updated = TRUE;
                        sHealthDumpGetHdrStatic.encrypt = sHealthDumpGetHdrLocal.encrypt;    // signal update only
                        result = (UCL_E_OK == UclCmnSerialize_uint8(sHealthDumpGetHdrStatic.encrypt, pMsgBuff, pBytesCopied));
                        break;
                    }
                }
            } while (!Rte_IsInfrastructureError(resultRte) && (E_OK == Rte_ApplicationError(resultRte)));
            break;
            
        case eUclILAdapterDataType_Always:          ///< Adapter to return the latest data, if available
            updated = TRUE;
            resultRte = Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&sHealthDumpGetHdrLocal);
            if(!Rte_IsInfrastructureError(resultRte) && (E_OK == Rte_ApplicationError(resultRte)))
            {
                sHealthDumpGetHdrStatic.encrypt = sHealthDumpGetHdrLocal.encrypt;    // signal update only
                result = (UCL_E_OK == UclCmnSerialize_uint8(sHealthDumpGetHdrStatic.encrypt, pMsgBuff, pBytesCopied));
            }
            break;

        default:
            break;
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message HealthDumpGetData
//---------------------------------------------------------------------------------------------------------------------
void OnDre_HealthDumpGetData(void)
{
    UclILSched_NotifyMessageUpdate( 0u, Tx_UclHealthDumpGetMsg_Index, HealthDumpGetData_UclHealthDumpGetMsg_Index, NULL, 0);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message HealthDumpGetData
//---------------------------------------------------------------------------------------------------------------------
static const SHealthDumpGetData sHealthDumpGetDataStatic_Initializer = {.reserved = 0};
static SHealthDumpGetData sHealthDumpGetDataStatic = {.reserved = 0};

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: HealthDumpGetData
///
/// @param  pMsgBuff:     Buffer to store serialized message
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return TRUE:  Data is retrieved and serialized successfully
///         FALSE: Invalid 'returnType'
///                Serialization failure
///                No new data in case of 'eUclILAdapterDataType_OnChange'
///                RTE communication error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_HealthDumpGetData(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    SHealthDumpGetData sHealthDumpGetDataLocal;
    uint8 result = FALSE;
    Std_ReturnType resultRte = E_OK;
    static uint8 updated = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != updated )
            {
                result = (UCL_E_OK == UclCmnSerialize_uint8(sHealthDumpGetDataStatic.reserved, pMsgBuff, pBytesCopied));
            }
            break;
            
        case eUclILAdapterDataType_OnChange:        ///< Adapter to return if the data is changed
            updated = FALSE;
            do
            {
                resultRte = Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&sHealthDumpGetDataLocal);
                if(!Rte_IsInfrastructureError(resultRte) && (E_OK == Rte_ApplicationError(resultRte)))
                {
                    if(sHealthDumpGetDataLocal.reserved != sHealthDumpGetDataStatic.reserved)
                    {
                        updated = TRUE;
                        sHealthDumpGetDataStatic.reserved = sHealthDumpGetDataLocal.reserved;    // signal update only
                        result = (UCL_E_OK == UclCmnSerialize_uint8(sHealthDumpGetDataStatic.reserved, pMsgBuff, pBytesCopied));
                        break;
                    }
                }
            } while (!Rte_IsInfrastructureError(resultRte) && (E_OK == Rte_ApplicationError(resultRte)));
            break;
            
        case eUclILAdapterDataType_Always:          ///< Adapter to return the latest data, if available
            updated = TRUE;
            resultRte = Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&sHealthDumpGetDataLocal);
            if(!Rte_IsInfrastructureError(resultRte) && (E_OK == Rte_ApplicationError(resultRte)))
            {
                sHealthDumpGetDataStatic.reserved = sHealthDumpGetDataLocal.reserved;    // signal update only
                result = (UCL_E_OK == UclCmnSerialize_uint8(sHealthDumpGetDataStatic.reserved, pMsgBuff, pBytesCopied));
            }
            break;

        default:
            break;
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message DisplaySetPower
//---------------------------------------------------------------------------------------------------------------------
void OnDre_DisplaySetPower(void)
{
    UclILSched_NotifyMessageUpdate( 0u, Tx_UclDisplaySetPower_Index, DisplaySetPower_UclDisplaySetPower_Index, NULL, 0);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message DisplaySetPower
//---------------------------------------------------------------------------------------------------------------------
static const SDisplaySetPower sDisplaySetPowerStatic_Initializer = {.displayId = 0, .state = 0};
static SDisplaySetPower sDisplaySetPowerStatic = {.displayId = 0, .state = 0};

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: DisplaySetPower
///
/// @param  pMsgBuff:     Buffer to store serialized message
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return TRUE:  Data is retrieved and serialized successfully
///         FALSE: Invalid 'returnType'
///                Serialization failure
///                No new data in case of 'eUclILAdapterDataType_OnChange'
///                RTE communication error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_DisplaySetPower(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    SDisplaySetPower sDisplaySetPowerLocal;
    uint8 result = FALSE;
    Std_ReturnType resultRte = E_OK;
    static uint8 updated = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != updated )
            {
                result = (UCL_E_OK == UclCmnSerialize_SDisplaySetPower(&(sDisplaySetPowerStatic), pMsgBuff, pBytesCopied));
            }
            break;
            
        case eUclILAdapterDataType_OnChange:        ///< Adapter to return if the data is changed
            updated = FALSE;
            resultRte = Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&sDisplaySetPowerLocal);
            if(E_OK == resultRte)
            {
                boolean compare = UclGenCompare_SDisplaySetPower(&(sDisplaySetPowerLocal), &(sDisplaySetPowerStatic));
                if(FALSE == compare)
                {
                    updated = TRUE;
                    sDisplaySetPowerStatic = sDisplaySetPowerLocal;    // signal update only
                    result = (UCL_E_OK == UclCmnSerialize_SDisplaySetPower(&(sDisplaySetPowerStatic), pMsgBuff, pBytesCopied));
                }
            }
            break;
            
        case eUclILAdapterDataType_Always:          ///< Adapter to return the latest data, if available
            updated = TRUE;
            resultRte = Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&sDisplaySetPowerLocal);
            if(E_OK == resultRte)
            {
                sDisplaySetPowerStatic = sDisplaySetPowerLocal;    // signal update only
                result = (UCL_E_OK == UclCmnSerialize_SDisplaySetPower(&(sDisplaySetPowerStatic), pMsgBuff, pBytesCopied));
            }
            break;

        default:
            break;
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message TT_Status
//---------------------------------------------------------------------------------------------------------------------
void OnDre_TT_Status(void)
{
    UclILSched_NotifyMessageUpdate( 0u, Tx_UclTelltaleStatusMsg_Index, TT_Status_UclTelltaleStatusMsg_Index, NULL, 0);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message TT_Status
//---------------------------------------------------------------------------------------------------------------------
static const STT_Status sTT_StatusStatic_Initializer = {.mask = 0};
static STT_Status sTT_StatusStatic = {.mask = 0};

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: TT_Status
///
/// @param  pMsgBuff:     Buffer to store serialized message
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return TRUE:  Data is retrieved and serialized successfully
///         FALSE: Invalid 'returnType'
///                Serialization failure
///                No new data in case of 'eUclILAdapterDataType_OnChange'
///                RTE communication error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_TT_Status(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    STT_Status sTT_StatusLocal;
    uint8 result = FALSE;
    Std_ReturnType resultRte = E_OK;
    static uint8 updated = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != updated )
            {
                result = (UCL_E_OK == UclCmnSerialize_data_u8_15(sTT_StatusStatic.mask, pMsgBuff, pBytesCopied));
            }
            break;
            
        case eUclILAdapterDataType_OnChange:        ///< Adapter to return if the data is changed
            updated = FALSE;
            resultRte = Rte_Read_rSR_TT_Status_TT_StatusData(&sTT_StatusLocal);
            if(E_OK == resultRte)
            {
                int compare = memcmp(sTT_StatusLocal.mask, sTT_StatusStatic.mask, sizeof(data_u8_15));
                if(0 != compare)
                {
                    updated = TRUE;
                    memcpy(sTT_StatusStatic.mask, sTT_StatusLocal.mask, sizeof(data_u8_15));    // signal update only
                    result = (UCL_E_OK == UclCmnSerialize_data_u8_15(sTT_StatusStatic.mask, pMsgBuff, pBytesCopied));
                }
            }
            break;
            
        case eUclILAdapterDataType_Always:          ///< Adapter to return the latest data, if available
            updated = TRUE;
            resultRte = Rte_Read_rSR_TT_Status_TT_StatusData(&sTT_StatusLocal);
            if(E_OK == resultRte)
            {
                memcpy(sTT_StatusStatic.mask, sTT_StatusLocal.mask, sizeof(data_u8_15));    // signal update only
                result = (UCL_E_OK == UclCmnSerialize_data_u8_15(sTT_StatusStatic.mask, pMsgBuff, pBytesCopied));
            }
            break;

        default:
            break;
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message RTT_Toggle
//---------------------------------------------------------------------------------------------------------------------
void OnDre_RTT_Toggle(void)
{
    UclILSched_NotifyMessageUpdate( 0u, Tx_UclTelltaleStatusMsg_Index, RTT_Toggle_UclTelltaleStatusMsg_Index, NULL, 0);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message RTT_Toggle
//---------------------------------------------------------------------------------------------------------------------
static const SRTT_Toggle sRTT_ToggleStatic_Initializer = {.positions = 0, .display = 0};
static SRTT_Toggle sRTT_ToggleStatic = {.positions = 0, .display = 0};

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: RTT_Toggle
///
/// @param  pMsgBuff:     Buffer to store serialized message
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return TRUE:  Data is retrieved and serialized successfully
///         FALSE: Invalid 'returnType'
///                Serialization failure
///                No new data in case of 'eUclILAdapterDataType_OnChange'
///                RTE communication error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_RTT_Toggle(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    SRTT_Toggle sRTT_ToggleLocal;
    uint8 result = FALSE;
    Std_ReturnType resultRte = E_OK;
    static uint8 updated = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != updated )
            {
                result = (UCL_E_OK == UclCmnSerialize_SRTT_Toggle(&(sRTT_ToggleStatic), pMsgBuff, pBytesCopied));
            }
            break;
            
        case eUclILAdapterDataType_OnChange:        ///< Adapter to return if the data is changed
            updated = FALSE;
            resultRte = Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&sRTT_ToggleLocal);
            if(E_OK == resultRte)
            {
                boolean compare = UclGenCompare_SRTT_Toggle(&(sRTT_ToggleLocal), &(sRTT_ToggleStatic));
                if(FALSE == compare)
                {
                    updated = TRUE;
                    sRTT_ToggleStatic = sRTT_ToggleLocal;    // signal update only
                    result = (UCL_E_OK == UclCmnSerialize_SRTT_Toggle(&(sRTT_ToggleStatic), pMsgBuff, pBytesCopied));
                }
            }
            break;
            
        case eUclILAdapterDataType_Always:          ///< Adapter to return the latest data, if available
            updated = TRUE;
            resultRte = Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&sRTT_ToggleLocal);
            if(E_OK == resultRte)
            {
                sRTT_ToggleStatic = sRTT_ToggleLocal;    // signal update only
                result = (UCL_E_OK == UclCmnSerialize_SRTT_Toggle(&(sRTT_ToggleStatic), pMsgBuff, pBytesCopied));
            }
            break;

        default:
            break;
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message FRTT_Status
//---------------------------------------------------------------------------------------------------------------------
void OnDre_FRTT_Status(void)
{
    UclILSched_NotifyMessageUpdate( 0u, Tx_UclTelltaleStatusMsg_Index, FRTT_Status_UclTelltaleStatusMsg_Index, NULL, 0);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message FRTT_Status
//---------------------------------------------------------------------------------------------------------------------
static const SFRTT_Status sFRTT_StatusStatic_Initializer = {.mask = 0};
static SFRTT_Status sFRTT_StatusStatic = {.mask = 0};

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: FRTT_Status
///
/// @param  pMsgBuff:     Buffer to store serialized message
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return TRUE:  Data is retrieved and serialized successfully
///         FALSE: Invalid 'returnType'
///                Serialization failure
///                No new data in case of 'eUclILAdapterDataType_OnChange'
///                RTE communication error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_FRTT_Status(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    SFRTT_Status sFRTT_StatusLocal;
    uint8 result = FALSE;
    Std_ReturnType resultRte = E_OK;
    static uint8 updated = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != updated )
            {
                result = (UCL_E_OK == UclCmnSerialize_data_u8_2(sFRTT_StatusStatic.mask, pMsgBuff, pBytesCopied));
            }
            break;
            
        case eUclILAdapterDataType_OnChange:        ///< Adapter to return if the data is changed
            updated = FALSE;
            resultRte = Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&sFRTT_StatusLocal);
            if(E_OK == resultRte)
            {
                int compare = memcmp(sFRTT_StatusLocal.mask, sFRTT_StatusStatic.mask, sizeof(data_u8_2));
                if(0 != compare)
                {
                    updated = TRUE;
                    memcpy(sFRTT_StatusStatic.mask, sFRTT_StatusLocal.mask, sizeof(data_u8_2));    // signal update only
                    result = (UCL_E_OK == UclCmnSerialize_data_u8_2(sFRTT_StatusStatic.mask, pMsgBuff, pBytesCopied));
                }
            }
            break;
            
        case eUclILAdapterDataType_Always:          ///< Adapter to return the latest data, if available
            updated = TRUE;
            resultRte = Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&sFRTT_StatusLocal);
            if(E_OK == resultRte)
            {
                memcpy(sFRTT_StatusStatic.mask, sFRTT_StatusLocal.mask, sizeof(data_u8_2));    // signal update only
                result = (UCL_E_OK == UclCmnSerialize_data_u8_2(sFRTT_StatusStatic.mask, pMsgBuff, pBytesCopied));
            }
            break;

        default:
            break;
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message RTT_Icon
//---------------------------------------------------------------------------------------------------------------------
void OnDre_RTT_Icon(void)
{
    UclILSched_NotifyMessageUpdate( 0u, Tx_UclTelltaleStatusMsg_Index, RTT_Icon_UclTelltaleStatusMsg_Index, NULL, 0);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message RTT_Icon
//---------------------------------------------------------------------------------------------------------------------
static const SRTT_Icon sRTT_IconStatic_Initializer = {.icon = 0};
static SRTT_Icon sRTT_IconStatic = {.icon = 0};

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: RTT_Icon
///
/// @param  pMsgBuff:     Buffer to store serialized message
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return TRUE:  Data is retrieved and serialized successfully
///         FALSE: Invalid 'returnType'
///                Serialization failure
///                No new data in case of 'eUclILAdapterDataType_OnChange'
///                RTE communication error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_RTT_Icon(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    SRTT_Icon sRTT_IconLocal;
    uint8 result = FALSE;
    Std_ReturnType resultRte = E_OK;
    static uint8 updated = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != updated )
            {
                result = (UCL_E_OK == UclCmnSerialize_data_u8_2(sRTT_IconStatic.icon, pMsgBuff, pBytesCopied));
            }
            break;
            
        case eUclILAdapterDataType_OnChange:        ///< Adapter to return if the data is changed
            updated = FALSE;
            resultRte = Rte_Read_rSR_RTT_Icon_RTT_IconData(&sRTT_IconLocal);
            if(E_OK == resultRte)
            {
                int compare = memcmp(sRTT_IconLocal.icon, sRTT_IconStatic.icon, sizeof(data_u8_2));
                if(0 != compare)
                {
                    updated = TRUE;
                    memcpy(sRTT_IconStatic.icon, sRTT_IconLocal.icon, sizeof(data_u8_2));    // signal update only
                    result = (UCL_E_OK == UclCmnSerialize_data_u8_2(sRTT_IconStatic.icon, pMsgBuff, pBytesCopied));
                }
            }
            break;
            
        case eUclILAdapterDataType_Always:          ///< Adapter to return the latest data, if available
            updated = TRUE;
            resultRte = Rte_Read_rSR_RTT_Icon_RTT_IconData(&sRTT_IconLocal);
            if(E_OK == resultRte)
            {
                memcpy(sRTT_IconStatic.icon, sRTT_IconLocal.icon, sizeof(data_u8_2));    // signal update only
                result = (UCL_E_OK == UclCmnSerialize_data_u8_2(sRTT_IconStatic.icon, pMsgBuff, pBytesCopied));
            }
            break;

        default:
            break;
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message RTT_Status
//---------------------------------------------------------------------------------------------------------------------
void OnDre_RTT_Status(void)
{
    UclILSched_NotifyMessageUpdate( 0u, Tx_UclTelltaleStatusMsg_Index, RTT_Status_UclTelltaleStatusMsg_Index, NULL, 0);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message RTT_Status
//---------------------------------------------------------------------------------------------------------------------
static const SRTT_Status sRTT_StatusStatic_Initializer = {.mask = 0};
static SRTT_Status sRTT_StatusStatic = {.mask = 0};

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: RTT_Status
///
/// @param  pMsgBuff:     Buffer to store serialized message
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return TRUE:  Data is retrieved and serialized successfully
///         FALSE: Invalid 'returnType'
///                Serialization failure
///                No new data in case of 'eUclILAdapterDataType_OnChange'
///                RTE communication error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_RTT_Status(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    SRTT_Status sRTT_StatusLocal;
    uint8 result = FALSE;
    Std_ReturnType resultRte = E_OK;
    static uint8 updated = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != updated )
            {
                result = (UCL_E_OK == UclCmnSerialize_data_u8_2(sRTT_StatusStatic.mask, pMsgBuff, pBytesCopied));
            }
            break;
            
        case eUclILAdapterDataType_OnChange:        ///< Adapter to return if the data is changed
            updated = FALSE;
            resultRte = Rte_Read_rSR_RTT_Status_RTT_StatusData(&sRTT_StatusLocal);
            if(E_OK == resultRte)
            {
                int compare = memcmp(sRTT_StatusLocal.mask, sRTT_StatusStatic.mask, sizeof(data_u8_2));
                if(0 != compare)
                {
                    updated = TRUE;
                    memcpy(sRTT_StatusStatic.mask, sRTT_StatusLocal.mask, sizeof(data_u8_2));    // signal update only
                    result = (UCL_E_OK == UclCmnSerialize_data_u8_2(sRTT_StatusStatic.mask, pMsgBuff, pBytesCopied));
                }
            }
            break;
            
        case eUclILAdapterDataType_Always:          ///< Adapter to return the latest data, if available
            updated = TRUE;
            resultRte = Rte_Read_rSR_RTT_Status_RTT_StatusData(&sRTT_StatusLocal);
            if(E_OK == resultRte)
            {
                memcpy(sRTT_StatusStatic.mask, sRTT_StatusLocal.mask, sizeof(data_u8_2));    // signal update only
                result = (UCL_E_OK == UclCmnSerialize_data_u8_2(sRTT_StatusStatic.mask, pMsgBuff, pBytesCopied));
            }
            break;

        default:
            break;
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message WarningExtDisplay
//---------------------------------------------------------------------------------------------------------------------
void OnDre_WarningExtDisplay(void)
{
    UclILSched_NotifyMessageUpdate( 0u, Tx_UclWarningDisplayMsg_Index, WarningExtDisplay_UclWarningDisplayMsg_Index, NULL, 0);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message WarningExtDisplay
//---------------------------------------------------------------------------------------------------------------------
static const SWarningExtDisplay sWarningExtDisplayStatic_Initializer = {.show = 0, .warningId = 0, .dynData = 0};
static SWarningExtDisplay sWarningExtDisplayStatic = {.show = 0, .warningId = 0, .dynData = 0};

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: WarningExtDisplay
///
/// @param  pMsgBuff:     Buffer to store serialized message
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return TRUE:  Data is retrieved and serialized successfully
///         FALSE: Invalid 'returnType'
///                Serialization failure
///                No new data in case of 'eUclILAdapterDataType_OnChange'
///                RTE communication error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_WarningExtDisplay(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    SWarningExtDisplay sWarningExtDisplayLocal;
    uint8 result = FALSE;
    Std_ReturnType resultRte = E_OK;
    static uint8 updated = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != updated )
            {
                result = (UCL_E_OK == UclCmnSerialize_SWarningExtDisplay(&(sWarningExtDisplayStatic), pMsgBuff, pBytesCopied));
            }
            break;
            
        case eUclILAdapterDataType_OnChange:        ///< Adapter to return if the data is changed
            updated = FALSE;
            resultRte = Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&sWarningExtDisplayLocal);
            if(E_OK == resultRte)
            {
                boolean compare = UclGenCompare_SWarningExtDisplay(&(sWarningExtDisplayLocal), &(sWarningExtDisplayStatic));
                if(FALSE == compare)
                {
                    updated = TRUE;
                    sWarningExtDisplayStatic = sWarningExtDisplayLocal;    // signal update only
                    result = (UCL_E_OK == UclCmnSerialize_SWarningExtDisplay(&(sWarningExtDisplayStatic), pMsgBuff, pBytesCopied));
                }
            }
            break;
            
        case eUclILAdapterDataType_Always:          ///< Adapter to return the latest data, if available
            updated = TRUE;
            resultRte = Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&sWarningExtDisplayLocal);
            if(E_OK == resultRte)
            {
                sWarningExtDisplayStatic = sWarningExtDisplayLocal;    // signal update only
                result = (UCL_E_OK == UclCmnSerialize_SWarningExtDisplay(&(sWarningExtDisplayStatic), pMsgBuff, pBytesCopied));
            }
            break;

        default:
            break;
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message WarningDisplay
//---------------------------------------------------------------------------------------------------------------------
void OnDre_WarningDisplay(void)
{
    UclILSched_NotifyMessageUpdate( 0u, Tx_UclWarningDisplayMsg_Index, WarningDisplay_UclWarningDisplayMsg_Index, NULL, 0);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message WarningDisplay
//---------------------------------------------------------------------------------------------------------------------
static const SWarningDisplay sWarningDisplayStatic_Initializer = {.show = 0, .warningId = 0, .dynData = 0};
static SWarningDisplay sWarningDisplayStatic = {.show = 0, .warningId = 0, .dynData = 0};

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: WarningDisplay
///
/// @param  pMsgBuff:     Buffer to store serialized message
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return TRUE:  Data is retrieved and serialized successfully
///         FALSE: Invalid 'returnType'
///                Serialization failure
///                No new data in case of 'eUclILAdapterDataType_OnChange'
///                RTE communication error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_WarningDisplay(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    SWarningDisplay sWarningDisplayLocal;
    uint8 result = FALSE;
    Std_ReturnType resultRte = E_OK;
    static uint8 updated = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != updated )
            {
                result = (UCL_E_OK == UclCmnSerialize_SWarningDisplay(&(sWarningDisplayStatic), pMsgBuff, pBytesCopied));
            }
            break;
            
        case eUclILAdapterDataType_OnChange:        ///< Adapter to return if the data is changed
            updated = FALSE;
            resultRte = Rte_Read_rSR_WarningDisplay_WarningDisplayData(&sWarningDisplayLocal);
            if(E_OK == resultRte)
            {
                boolean compare = UclGenCompare_SWarningDisplay(&(sWarningDisplayLocal), &(sWarningDisplayStatic));
                if(FALSE == compare)
                {
                    updated = TRUE;
                    sWarningDisplayStatic = sWarningDisplayLocal;    // signal update only
                    result = (UCL_E_OK == UclCmnSerialize_SWarningDisplay(&(sWarningDisplayStatic), pMsgBuff, pBytesCopied));
                }
            }
            break;
            
        case eUclILAdapterDataType_Always:          ///< Adapter to return the latest data, if available
            updated = TRUE;
            resultRte = Rte_Read_rSR_WarningDisplay_WarningDisplayData(&sWarningDisplayLocal);
            if(E_OK == resultRte)
            {
                sWarningDisplayStatic = sWarningDisplayLocal;    // signal update only
                result = (UCL_E_OK == UclCmnSerialize_SWarningDisplay(&(sWarningDisplayStatic), pMsgBuff, pBytesCopied));
            }
            break;

        default:
            break;
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message SlowGaugeInfo
//---------------------------------------------------------------------------------------------------------------------
void OnDre_SlowGaugeInfo(void)
{
    UclILSched_NotifyMessageUpdate( 0u, Tx_UclSlowGaugeMsg_Index, SlowGaugeInfo_UclSlowGaugeMsg_Index, NULL, 0);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message SlowGaugeInfo
//---------------------------------------------------------------------------------------------------------------------
static const SSlowGaugeInfo sSlowGaugeInfoStatic_Initializer = {.gaugeInfo = 0};
static SSlowGaugeInfo sSlowGaugeInfoStatic = {.gaugeInfo = 0};

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: SlowGaugeInfo
///
/// @param  pMsgBuff:     Buffer to store serialized message
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return TRUE:  Data is retrieved and serialized successfully
///         FALSE: Invalid 'returnType'
///                Serialization failure
///                No new data in case of 'eUclILAdapterDataType_OnChange'
///                RTE communication error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_SlowGaugeInfo(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    SSlowGaugeInfo sSlowGaugeInfoLocal;
    uint8 result = FALSE;
    Std_ReturnType resultRte = E_OK;
    static uint8 updated = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != updated )
            {
                result = (UCL_E_OK == UclCmnSerialize_SGaugeInfo_2(sSlowGaugeInfoStatic.gaugeInfo, pMsgBuff, pBytesCopied));
            }
            break;
            
        case eUclILAdapterDataType_OnChange:        ///< Adapter to return if the data is changed
            updated = FALSE;
            resultRte = Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&sSlowGaugeInfoLocal);
            if(E_OK == resultRte)
            {
                boolean compare = UclGenCompare_SGaugeInfo_2(sSlowGaugeInfoLocal.gaugeInfo, sSlowGaugeInfoStatic.gaugeInfo);
                if(FALSE == compare)
                {
                    updated = TRUE;
                    memcpy(sSlowGaugeInfoStatic.gaugeInfo, sSlowGaugeInfoLocal.gaugeInfo, sizeof(SGaugeInfo_2));    // signal update only
                    result = (UCL_E_OK == UclCmnSerialize_SGaugeInfo_2(sSlowGaugeInfoStatic.gaugeInfo, pMsgBuff, pBytesCopied));
                }
            }
            break;
            
        case eUclILAdapterDataType_Always:          ///< Adapter to return the latest data, if available
            updated = TRUE;
            resultRte = Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&sSlowGaugeInfoLocal);
            if(E_OK == resultRte)
            {
                memcpy(sSlowGaugeInfoStatic.gaugeInfo, sSlowGaugeInfoLocal.gaugeInfo, sizeof(SGaugeInfo_2));    // signal update only
                result = (UCL_E_OK == UclCmnSerialize_SGaugeInfo_2(sSlowGaugeInfoStatic.gaugeInfo, pMsgBuff, pBytesCopied));
            }
            break;

        default:
            break;
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message FastGaugeInfo
//---------------------------------------------------------------------------------------------------------------------
void OnDre_FastGaugeInfo(void)
{
    UclILSched_NotifyMessageUpdate( 0u, Tx_UclFastGuageCustomMsg_Index, FastGaugeInfo_UclFastGuageCustomMsg_Index, NULL, 0);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message FastGaugeInfo
//---------------------------------------------------------------------------------------------------------------------
static const SFastGaugeInfo sFastGaugeInfoStatic_Initializer = {.gaugeInfo = 0};
static SFastGaugeInfo sFastGaugeInfoStatic = {.gaugeInfo = 0};

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: FastGaugeInfo
///
/// @param  pMsgBuff:     Buffer to store serialized message
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return TRUE:  Data is retrieved and serialized successfully
///         FALSE: Invalid 'returnType'
///                Serialization failure
///                No new data in case of 'eUclILAdapterDataType_OnChange'
///                RTE communication error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_FastGaugeInfo(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    SFastGaugeInfo sFastGaugeInfoLocal;
    uint8 result = FALSE;
    Std_ReturnType resultRte = E_OK;
    static uint8 updated = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != updated )
            {
                result = (UCL_E_OK == UclCmnSerialize_SGaugeInfo_u32dyn_3(sFastGaugeInfoStatic.gaugeInfo, pMsgBuff, pBytesCopied));
            }
            break;
            
        case eUclILAdapterDataType_OnChange:        ///< Adapter to return if the data is changed
            updated = FALSE;
            resultRte = Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&sFastGaugeInfoLocal);
            if(E_OK == resultRte)
            {
                boolean compare = UclGenCompare_SGaugeInfo_u32dyn_3(sFastGaugeInfoLocal.gaugeInfo, sFastGaugeInfoStatic.gaugeInfo);
                if(FALSE == compare)
                {
                    updated = TRUE;
                    memcpy(sFastGaugeInfoStatic.gaugeInfo, sFastGaugeInfoLocal.gaugeInfo, sizeof(SGaugeInfo_u32dyn_3));    // signal update only
                    result = (UCL_E_OK == UclCmnSerialize_SGaugeInfo_u32dyn_3(sFastGaugeInfoStatic.gaugeInfo, pMsgBuff, pBytesCopied));
                }
            }
            break;
            
        case eUclILAdapterDataType_Always:          ///< Adapter to return the latest data, if available
            updated = TRUE;
            resultRte = Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&sFastGaugeInfoLocal);
            if(E_OK == resultRte)
            {
                memcpy(sFastGaugeInfoStatic.gaugeInfo, sFastGaugeInfoLocal.gaugeInfo, sizeof(SGaugeInfo_u32dyn_3));    // signal update only
                result = (UCL_E_OK == UclCmnSerialize_SGaugeInfo_u32dyn_3(sFastGaugeInfoStatic.gaugeInfo, pMsgBuff, pBytesCopied));
            }
            break;

        default:
            break;
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message ShiftPosIndStatus
//---------------------------------------------------------------------------------------------------------------------
void OnDre_ShiftPosIndStatus(void)
{
    UclILSched_NotifyMessageUpdate( 0u, Tx_UclShitPositionIndicatorMsg_Index, ShiftPosIndStatus_UclShitPositionIndicatorMsg_Index, NULL, 0);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message ShiftPosIndStatus
//---------------------------------------------------------------------------------------------------------------------
static const SShiftPosIndStatus sShiftPosIndStatusStatic_Initializer = {.status = 0};
static SShiftPosIndStatus sShiftPosIndStatusStatic = {.status = 0};

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: ShiftPosIndStatus
///
/// @param  pMsgBuff:     Buffer to store serialized message
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return TRUE:  Data is retrieved and serialized successfully
///         FALSE: Invalid 'returnType'
///                Serialization failure
///                No new data in case of 'eUclILAdapterDataType_OnChange'
///                RTE communication error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_ShiftPosIndStatus(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    SShiftPosIndStatus sShiftPosIndStatusLocal;
    uint8 result = FALSE;
    Std_ReturnType resultRte = E_OK;
    static uint8 updated = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != updated )
            {
                result = (UCL_E_OK == UclCmnSerialize_SShiftInd(&(sShiftPosIndStatusStatic.status), pMsgBuff, pBytesCopied));
            }
            break;
            
        case eUclILAdapterDataType_OnChange:        ///< Adapter to return if the data is changed
            updated = FALSE;
            resultRte = Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&sShiftPosIndStatusLocal);
            if(E_OK == resultRte)
            {
                boolean compare = UclGenCompare_SShiftInd(&(sShiftPosIndStatusLocal.status), &(sShiftPosIndStatusStatic.status));
                if(FALSE == compare)
                {
                    updated = TRUE;
                    sShiftPosIndStatusStatic.status = sShiftPosIndStatusLocal.status;    // signal update only
                    result = (UCL_E_OK == UclCmnSerialize_SShiftInd(&(sShiftPosIndStatusStatic.status), pMsgBuff, pBytesCopied));
                }
            }
            break;
            
        case eUclILAdapterDataType_Always:          ///< Adapter to return the latest data, if available
            updated = TRUE;
            resultRte = Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&sShiftPosIndStatusLocal);
            if(E_OK == resultRte)
            {
                sShiftPosIndStatusStatic.status = sShiftPosIndStatusLocal.status;    // signal update only
                result = (UCL_E_OK == UclCmnSerialize_SShiftInd(&(sShiftPosIndStatusStatic.status), pMsgBuff, pBytesCopied));
            }
            break;

        default:
            break;
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message IlluminationData
//---------------------------------------------------------------------------------------------------------------------
void OnDre_IlluminationData(void)
{
    UclILSched_NotifyMessageUpdate( 0u, Tx_UclIlluminationDataMsg_Index, IlluminationData_UclIlluminationDataMsg_Index, NULL, 0);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message IlluminationData
//---------------------------------------------------------------------------------------------------------------------
static const SIlluminationData sIlluminationDataStatic_Initializer = {.data = 0, .dayStep = 0, .nightStep = 0, .daynightStatus = 0};
static SIlluminationData sIlluminationDataStatic = {.data = 0, .dayStep = 0, .nightStep = 0, .daynightStatus = 0};

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: IlluminationData
///
/// @param  pMsgBuff:     Buffer to store serialized message
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return TRUE:  Data is retrieved and serialized successfully
///         FALSE: Invalid 'returnType'
///                Serialization failure
///                No new data in case of 'eUclILAdapterDataType_OnChange'
///                RTE communication error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_IlluminationData(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    SIlluminationData sIlluminationDataLocal;
    uint8 result = FALSE;
    Std_ReturnType resultRte = E_OK;
    static uint8 updated = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != updated )
            {
                result = (UCL_E_OK == UclCmnSerialize_SIlluminationData(&(sIlluminationDataStatic), pMsgBuff, pBytesCopied));
            }
            break;
            
        case eUclILAdapterDataType_OnChange:        ///< Adapter to return if the data is changed
            updated = FALSE;
            resultRte = Rte_Read_rSR_IlluminationData_IlluminationDataData(&sIlluminationDataLocal);
            if(E_OK == resultRte)
            {
                boolean compare = UclGenCompare_SIlluminationData(&(sIlluminationDataLocal), &(sIlluminationDataStatic));
                if(FALSE == compare)
                {
                    updated = TRUE;
                    sIlluminationDataStatic = sIlluminationDataLocal;    // signal update only
                    result = (UCL_E_OK == UclCmnSerialize_SIlluminationData(&(sIlluminationDataStatic), pMsgBuff, pBytesCopied));
                }
            }
            break;
            
        case eUclILAdapterDataType_Always:          ///< Adapter to return the latest data, if available
            updated = TRUE;
            resultRte = Rte_Read_rSR_IlluminationData_IlluminationDataData(&sIlluminationDataLocal);
            if(E_OK == resultRte)
            {
                sIlluminationDataStatic = sIlluminationDataLocal;    // signal update only
                result = (UCL_E_OK == UclCmnSerialize_SIlluminationData(&(sIlluminationDataStatic), pMsgBuff, pBytesCopied));
            }
            break;

        default:
            break;
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message UpdateShortServiceReq
//---------------------------------------------------------------------------------------------------------------------
void OnDre_UpdateShortServiceReq(void)
{
    UclILSched_NotifyMessageUpdate( 0u, Tx_UpdateShortServiceReq_Index, UpdateShortServiceReq_UpdateShortServiceReq_Index, NULL, 0);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message UpdateShortServiceReq
//---------------------------------------------------------------------------------------------------------------------
static const SUpdateShortServiceReq sUpdateShortServiceReqStatic_Initializer = {.msgId = 0, .msgSize = 0, .memoryType = 0, .memoryCmd = 0, .sid = 0, .length = 0, .data = 0};
static SUpdateShortServiceReq sUpdateShortServiceReqStatic = {.msgId = 0, .msgSize = 0, .memoryType = 0, .memoryCmd = 0, .sid = 0, .length = 0, .data = 0};

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: UpdateShortServiceReq
///
/// @param  pMsgBuff:     Buffer to store serialized message
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return TRUE:  Data is retrieved and serialized successfully
///         FALSE: Invalid 'returnType'
///                Serialization failure
///                No new data in case of 'eUclILAdapterDataType_OnChange'
///                RTE communication error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_UpdateShortServiceReq(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    SUpdateShortServiceReq sUpdateShortServiceReqLocal;
    uint8 result = FALSE;
    Std_ReturnType resultRte = E_OK;
    static uint8 updated = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != updated )
            {
                result = (UCL_E_OK == UclCmnSerialize_SUpdateShortServiceReq(&(sUpdateShortServiceReqStatic), pMsgBuff, pBytesCopied));
            }
            break;
            
        case eUclILAdapterDataType_OnChange:        ///< Adapter to return if the data is changed
            updated = FALSE;
            do
            {
                resultRte = Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&sUpdateShortServiceReqLocal);
                if(!Rte_IsInfrastructureError(resultRte) && (E_OK == Rte_ApplicationError(resultRte)))
                {
                    boolean compare = UclGenCompare_SUpdateShortServiceReq(&(sUpdateShortServiceReqLocal), &(sUpdateShortServiceReqStatic));
                    if(FALSE == compare)
                    {
                        updated = TRUE;
                        sUpdateShortServiceReqStatic = sUpdateShortServiceReqLocal;    // signal update only
                        result = (UCL_E_OK == UclCmnSerialize_SUpdateShortServiceReq(&(sUpdateShortServiceReqStatic), pMsgBuff, pBytesCopied));
                        break;
                    }
                }
            } while (!Rte_IsInfrastructureError(resultRte) && (E_OK == Rte_ApplicationError(resultRte)));
            break;
            
        case eUclILAdapterDataType_Always:          ///< Adapter to return the latest data, if available
            updated = TRUE;
            resultRte = Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&sUpdateShortServiceReqLocal);
            if(!Rte_IsInfrastructureError(resultRte) && (E_OK == Rte_ApplicationError(resultRte)))
            {
                sUpdateShortServiceReqStatic = sUpdateShortServiceReqLocal;    // signal update only
                result = (UCL_E_OK == UclCmnSerialize_SUpdateShortServiceReq(&(sUpdateShortServiceReqStatic), pMsgBuff, pBytesCopied));
            }
            break;

        default:
            break;
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message UpdateLongServiceReq
//---------------------------------------------------------------------------------------------------------------------
void OnDre_UpdateLongServiceReq(void)
{
    UclILSched_NotifyMessageUpdate( 0u, Tx_UpdateLongServiceReq_Index, UpdateLongServiceReq_UpdateLongServiceReq_Index, NULL, 0);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message UpdateLongServiceReq
//---------------------------------------------------------------------------------------------------------------------
static const SUpdateLongServiceReq sUpdateLongServiceReqStatic_Initializer = {.msgId = 0, .msgSize = 0, .memoryType = 0, .memoryCmd = 0, .sid = 0, .length = 0, .data = 0};
static SUpdateLongServiceReq sUpdateLongServiceReqStatic = {.msgId = 0, .msgSize = 0, .memoryType = 0, .memoryCmd = 0, .sid = 0, .length = 0, .data = 0};

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: UpdateLongServiceReq
///
/// @param  pMsgBuff:     Buffer to store serialized message
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return TRUE:  Data is retrieved and serialized successfully
///         FALSE: Invalid 'returnType'
///                Serialization failure
///                No new data in case of 'eUclILAdapterDataType_OnChange'
///                RTE communication error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_UpdateLongServiceReq(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    SUpdateLongServiceReq sUpdateLongServiceReqLocal;
    uint8 result = FALSE;
    Std_ReturnType resultRte = E_OK;
    static uint8 updated = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != updated )
            {
                result = (UCL_E_OK == UclCmnSerialize_SUpdateLongServiceReq(&(sUpdateLongServiceReqStatic), pMsgBuff, pBytesCopied));
            }
            break;
            
        case eUclILAdapterDataType_OnChange:        ///< Adapter to return if the data is changed
            updated = FALSE;
            do
            {
                resultRte = Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&sUpdateLongServiceReqLocal);
                if(!Rte_IsInfrastructureError(resultRte) && (E_OK == Rte_ApplicationError(resultRte)))
                {
                    boolean compare = UclGenCompare_SUpdateLongServiceReq(&(sUpdateLongServiceReqLocal), &(sUpdateLongServiceReqStatic));
                    if(FALSE == compare)
                    {
                        updated = TRUE;
                        sUpdateLongServiceReqStatic = sUpdateLongServiceReqLocal;    // signal update only
                        result = (UCL_E_OK == UclCmnSerialize_SUpdateLongServiceReq(&(sUpdateLongServiceReqStatic), pMsgBuff, pBytesCopied));
                        break;
                    }
                }
            } while (!Rte_IsInfrastructureError(resultRte) && (E_OK == Rte_ApplicationError(resultRte)));
            break;
            
        case eUclILAdapterDataType_Always:          ///< Adapter to return the latest data, if available
            updated = TRUE;
            resultRte = Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&sUpdateLongServiceReqLocal);
            if(!Rte_IsInfrastructureError(resultRte) && (E_OK == Rte_ApplicationError(resultRte)))
            {
                sUpdateLongServiceReqStatic = sUpdateLongServiceReqLocal;    // signal update only
                result = (UCL_E_OK == UclCmnSerialize_SUpdateLongServiceReq(&(sUpdateLongServiceReqStatic), pMsgBuff, pBytesCopied));
            }
            break;

        default:
            break;
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message DiagDIDRequest
//---------------------------------------------------------------------------------------------------------------------
void OnDre_DiagDIDRequest(void)
{
    UclILSched_NotifyMessageUpdate( 0u, Tx_UclDiagRequest_Index, DiagDIDRequest_UclDiagRequest_Index, NULL, 0);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message DiagDIDRequest
//---------------------------------------------------------------------------------------------------------------------
static const SDiagDIDRequest sDiagDIDRequestStatic_Initializer = {0};
static SDiagDIDRequest sDiagDIDRequestStatic;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: DiagDIDRequest
///
/// @param  pMsgBuff:     Buffer to store serialized message
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return TRUE:  Data is retrieved and serialized successfully
///         FALSE: Invalid 'returnType'
///                Serialization failure
///                No new data in case of 'eUclILAdapterDataType_OnChange'
///                RTE communication error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_DiagDIDRequest(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    SDiagDIDRequest sDiagDIDRequestLocal;
    uint8 result = FALSE;
    Std_ReturnType resultRte = E_OK;
    static uint8 updated = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != updated )
            {
                result = (UCL_E_OK == UclCmnSerialize_SDiagDIDRequest(&(sDiagDIDRequestStatic), pMsgBuff, pBytesCopied));
            }
            break;
            
        case eUclILAdapterDataType_OnChange:        ///< Adapter to return if the data is changed
            updated = FALSE;
            do
            {
                resultRte = Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&sDiagDIDRequestLocal);
                if(!Rte_IsInfrastructureError(resultRte) && (E_OK == Rte_ApplicationError(resultRte)))
                {
                    boolean compare = UclGenCompare_SDiagDIDRequest(&(sDiagDIDRequestLocal), &(sDiagDIDRequestStatic));
                    if(FALSE == compare)
                    {
                        updated = TRUE;
                        sDiagDIDRequestStatic = sDiagDIDRequestLocal;    // signal update only
                        result = (UCL_E_OK == UclCmnSerialize_SDiagDIDRequest(&(sDiagDIDRequestStatic), pMsgBuff, pBytesCopied));
                        break;
                    }
                }
            } while (!Rte_IsInfrastructureError(resultRte) && (E_OK == Rte_ApplicationError(resultRte)));
            break;
            
        case eUclILAdapterDataType_Always:          ///< Adapter to return the latest data, if available
            updated = TRUE;
            resultRte = Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&sDiagDIDRequestLocal);
            if(!Rte_IsInfrastructureError(resultRte) && (E_OK == Rte_ApplicationError(resultRte)))
            {
                sDiagDIDRequestStatic = sDiagDIDRequestLocal;    // signal update only
                result = (UCL_E_OK == UclCmnSerialize_SDiagDIDRequest(&(sDiagDIDRequestStatic), pMsgBuff, pBytesCopied));
            }
            break;

        default:
            break;
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message DiagIOCtrlRequest
//---------------------------------------------------------------------------------------------------------------------
void OnDre_DiagIOCtrlRequest(void)
{
    UclILSched_NotifyMessageUpdate( 0u, Tx_UclDiagRequest_Index, DiagIOCtrlRequest_UclDiagRequest_Index, NULL, 0);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message DiagIOCtrlRequest
//---------------------------------------------------------------------------------------------------------------------
static const SDiagIOCtrlRequest sDiagIOCtrlRequestStatic_Initializer = {0};
static SDiagIOCtrlRequest sDiagIOCtrlRequestStatic;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: DiagIOCtrlRequest
///
/// @param  pMsgBuff:     Buffer to store serialized message
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return TRUE:  Data is retrieved and serialized successfully
///         FALSE: Invalid 'returnType'
///                Serialization failure
///                No new data in case of 'eUclILAdapterDataType_OnChange'
///                RTE communication error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_DiagIOCtrlRequest(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    SDiagIOCtrlRequest sDiagIOCtrlRequestLocal;
    uint8 result = FALSE;
    Std_ReturnType resultRte = E_OK;
    static uint8 updated = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != updated )
            {
                result = (UCL_E_OK == UclCmnSerialize_SDiagIOCtrlRequest(&(sDiagIOCtrlRequestStatic), pMsgBuff, pBytesCopied));
            }
            break;
            
        case eUclILAdapterDataType_OnChange:        ///< Adapter to return if the data is changed
            updated = FALSE;
            do
            {
                resultRte = Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&sDiagIOCtrlRequestLocal);
                if(!Rte_IsInfrastructureError(resultRte) && (E_OK == Rte_ApplicationError(resultRte)))
                {
                    boolean compare = UclGenCompare_SDiagIOCtrlRequest(&(sDiagIOCtrlRequestLocal), &(sDiagIOCtrlRequestStatic));
                    if(FALSE == compare)
                    {
                        updated = TRUE;
                        sDiagIOCtrlRequestStatic = sDiagIOCtrlRequestLocal;    // signal update only
                        result = (UCL_E_OK == UclCmnSerialize_SDiagIOCtrlRequest(&(sDiagIOCtrlRequestStatic), pMsgBuff, pBytesCopied));
                        break;
                    }
                }
            } while (!Rte_IsInfrastructureError(resultRte) && (E_OK == Rte_ApplicationError(resultRte)));
            break;
            
        case eUclILAdapterDataType_Always:          ///< Adapter to return the latest data, if available
            updated = TRUE;
            resultRte = Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&sDiagIOCtrlRequestLocal);
            if(!Rte_IsInfrastructureError(resultRte) && (E_OK == Rte_ApplicationError(resultRte)))
            {
                sDiagIOCtrlRequestStatic = sDiagIOCtrlRequestLocal;    // signal update only
                result = (UCL_E_OK == UclCmnSerialize_SDiagIOCtrlRequest(&(sDiagIOCtrlRequestStatic), pMsgBuff, pBytesCopied));
            }
            break;

        default:
            break;
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message DiagRoutineRequest
//---------------------------------------------------------------------------------------------------------------------
void OnDre_DiagRoutineRequest(void)
{
    UclILSched_NotifyMessageUpdate( 0u, Tx_UclDiagRequest_Index, DiagRoutineRequest_UclDiagRequest_Index, NULL, 0);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message DiagRoutineRequest
//---------------------------------------------------------------------------------------------------------------------
static const SDiagRoutineRequest sDiagRoutineRequestStatic_Initializer = {0};
static SDiagRoutineRequest sDiagRoutineRequestStatic;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: DiagRoutineRequest
///
/// @param  pMsgBuff:     Buffer to store serialized message
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return TRUE:  Data is retrieved and serialized successfully
///         FALSE: Invalid 'returnType'
///                Serialization failure
///                No new data in case of 'eUclILAdapterDataType_OnChange'
///                RTE communication error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_DiagRoutineRequest(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    SDiagRoutineRequest sDiagRoutineRequestLocal;
    uint8 result = FALSE;
    Std_ReturnType resultRte = E_OK;
    static uint8 updated = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != updated )
            {
                result = (UCL_E_OK == UclCmnSerialize_SDiagRoutineRequest(&(sDiagRoutineRequestStatic), pMsgBuff, pBytesCopied));
            }
            break;
            
        case eUclILAdapterDataType_OnChange:        ///< Adapter to return if the data is changed
            updated = FALSE;
            do
            {
                resultRte = Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&sDiagRoutineRequestLocal);
                if(!Rte_IsInfrastructureError(resultRte) && (E_OK == Rte_ApplicationError(resultRte)))
                {
                    boolean compare = UclGenCompare_SDiagRoutineRequest(&(sDiagRoutineRequestLocal), &(sDiagRoutineRequestStatic));
                    if(FALSE == compare)
                    {
                        updated = TRUE;
                        sDiagRoutineRequestStatic = sDiagRoutineRequestLocal;    // signal update only
                        result = (UCL_E_OK == UclCmnSerialize_SDiagRoutineRequest(&(sDiagRoutineRequestStatic), pMsgBuff, pBytesCopied));
                        break;
                    }
                }
            } while (!Rte_IsInfrastructureError(resultRte) && (E_OK == Rte_ApplicationError(resultRte)));
            break;
            
        case eUclILAdapterDataType_Always:          ///< Adapter to return the latest data, if available
            updated = TRUE;
            resultRte = Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&sDiagRoutineRequestLocal);
            if(!Rte_IsInfrastructureError(resultRte) && (E_OK == Rte_ApplicationError(resultRte)))
            {
                sDiagRoutineRequestStatic = sDiagRoutineRequestLocal;    // signal update only
                result = (UCL_E_OK == UclCmnSerialize_SDiagRoutineRequest(&(sDiagRoutineRequestStatic), pMsgBuff, pBytesCopied));
            }
            break;

        default:
            break;
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message DLTMessageReadRequest
//---------------------------------------------------------------------------------------------------------------------
void OnDre_DLTMessageReadRequest(void)
{
    UclILSched_NotifyMessageUpdate( 0u, Tx_UclDLTMessageReadRequest_Index, DLTMessageReadRequest_UclDLTMessageReadRequest_Index, NULL, 0);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message DLTMessageReadRequest
//---------------------------------------------------------------------------------------------------------------------
static const SDLTMessageReadRequest sDLTMessageReadRequestStatic_Initializer = {0};
static SDLTMessageReadRequest sDLTMessageReadRequestStatic;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: DLTMessageReadRequest
///
/// @param  pMsgBuff:     Buffer to store serialized message
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return TRUE:  Data is retrieved and serialized successfully
///         FALSE: Invalid 'returnType'
///                Serialization failure
///                No new data in case of 'eUclILAdapterDataType_OnChange'
///                RTE communication error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_DLTMessageReadRequest(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    SDLTMessageReadRequest sDLTMessageReadRequestLocal;
    uint8 result = FALSE;
    Std_ReturnType resultRte = E_OK;
    static uint8 updated = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != updated )
            {
                result = (UCL_E_OK == UclCmnSerialize_data_u8_2(&(sDLTMessageReadRequestStatic.status), pMsgBuff, pBytesCopied));
            }
            break;
            
        case eUclILAdapterDataType_OnChange:        ///< Adapter to return if the data is changed
            updated = FALSE;
            resultRte = Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&sDLTMessageReadRequestLocal);
            if(E_OK == resultRte)
            {
                int compare = memcmp(&(sDLTMessageReadRequestLocal.status), &(sDLTMessageReadRequestStatic.status), sizeof(data_u8_2));
                if(0 != compare)
                {
                    updated = TRUE;
                    memcpy(&(sDLTMessageReadRequestStatic.status), &(sDLTMessageReadRequestLocal.status), sizeof(data_u8_2));    // signal update only
                    result = (UCL_E_OK == UclCmnSerialize_data_u8_2(&(sDLTMessageReadRequestStatic.status), pMsgBuff, pBytesCopied));
                }
            }
            break;
            
        case eUclILAdapterDataType_Always:          ///< Adapter to return the latest data, if available
            updated = TRUE;
            resultRte = Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&sDLTMessageReadRequestLocal);
            if(E_OK == resultRte)
            {
                memcpy(&(sDLTMessageReadRequestStatic.status), &(sDLTMessageReadRequestLocal.status), sizeof(data_u8_2));    // signal update only
                result = (UCL_E_OK == UclCmnSerialize_data_u8_2(&(sDLTMessageReadRequestStatic.status), pMsgBuff, pBytesCopied));
            }
            break;

        default:
            break;
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message DLTControlMessageReponse
//---------------------------------------------------------------------------------------------------------------------
void OnDre_DLTControlMessageReponse(void)
{
    UclILSched_NotifyMessageUpdate( 0u, Tx_UclDLTControlMessageReponse_Index, DLTControlMessageReponse_UclDLTControlMessageReponse_Index, NULL, 0);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message DLTControlMessageReponse
//---------------------------------------------------------------------------------------------------------------------
static const SDLTControlMessageReponse sDLTControlMessageReponseStatic_Initializer = {0};
static SDLTControlMessageReponse sDLTControlMessageReponseStatic;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: DLTControlMessageReponse
///
/// @param  pMsgBuff:     Buffer to store serialized message
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return TRUE:  Data is retrieved and serialized successfully
///         FALSE: Invalid 'returnType'
///                Serialization failure
///                No new data in case of 'eUclILAdapterDataType_OnChange'
///                RTE communication error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_DLTControlMessageReponse(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    SDLTControlMessageReponse sDLTControlMessageReponseLocal;
    uint8 result = FALSE;
    Std_ReturnType resultRte = E_OK;
    static uint8 updated = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != updated )
            {
                result = (UCL_E_OK == UclCmnSerialize_data_u8_2(&(sDLTControlMessageReponseStatic.status), pMsgBuff, pBytesCopied));
            }
            break;
            
        case eUclILAdapterDataType_OnChange:        ///< Adapter to return if the data is changed
            updated = FALSE;
            resultRte = Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&sDLTControlMessageReponseLocal);
            if(E_OK == resultRte)
            {
                int compare = memcmp(&(sDLTControlMessageReponseLocal.status), &(sDLTControlMessageReponseStatic.status), sizeof(data_u8_2));
                if(0 != compare)
                {
                    updated = TRUE;
                    memcpy(&(sDLTControlMessageReponseStatic.status), &(sDLTControlMessageReponseLocal.status), sizeof(data_u8_2));    // signal update only
                    result = (UCL_E_OK == UclCmnSerialize_data_u8_2(&(sDLTControlMessageReponseStatic.status), pMsgBuff, pBytesCopied));
                }
            }
            break;
            
        case eUclILAdapterDataType_Always:          ///< Adapter to return the latest data, if available
            updated = TRUE;
            resultRte = Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&sDLTControlMessageReponseLocal);
            if(E_OK == resultRte)
            {
                memcpy(&(sDLTControlMessageReponseStatic.status), &(sDLTControlMessageReponseLocal.status), sizeof(data_u8_2));    // signal update only
                result = (UCL_E_OK == UclCmnSerialize_data_u8_2(&(sDLTControlMessageReponseStatic.status), pMsgBuff, pBytesCopied));
            }
            break;

        default:
            break;
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Initialization of static variables
//---------------------------------------------------------------------------------------------------------------------
void UclGen_AsrAdapterInit(void)
{
    sPowerSystemStateReqChangeStatic = sPowerSystemStateReqChangeStatic_Initializer;
    sHealthDumpGetHdrStatic = sHealthDumpGetHdrStatic_Initializer;
    sHealthDumpGetDataStatic = sHealthDumpGetDataStatic_Initializer;
    sDisplaySetPowerStatic = sDisplaySetPowerStatic_Initializer;
    sTT_StatusStatic = sTT_StatusStatic_Initializer;
    sRTT_ToggleStatic = sRTT_ToggleStatic_Initializer;
    sFRTT_StatusStatic = sFRTT_StatusStatic_Initializer;
    sRTT_IconStatic = sRTT_IconStatic_Initializer;
    sRTT_StatusStatic = sRTT_StatusStatic_Initializer;
    sWarningExtDisplayStatic = sWarningExtDisplayStatic_Initializer;
    sWarningDisplayStatic = sWarningDisplayStatic_Initializer;
    sSlowGaugeInfoStatic = sSlowGaugeInfoStatic_Initializer;
    sFastGaugeInfoStatic = sFastGaugeInfoStatic_Initializer;
    sShiftPosIndStatusStatic = sShiftPosIndStatusStatic_Initializer;
    sIlluminationDataStatic = sIlluminationDataStatic_Initializer;
    sUpdateShortServiceReqStatic = sUpdateShortServiceReqStatic_Initializer;
    sUpdateLongServiceReqStatic = sUpdateLongServiceReqStatic_Initializer;
    sDiagDIDRequestStatic = sDiagDIDRequestStatic_Initializer;
    sDiagIOCtrlRequestStatic = sDiagIOCtrlRequestStatic_Initializer;
    sDiagRoutineRequestStatic = sDiagRoutineRequestStatic_Initializer;
    sDLTMessageReadRequestStatic = sDLTMessageReadRequestStatic_Initializer;
    sDLTControlMessageReponseStatic = sDLTControlMessageReponseStatic_Initializer;
}

//---------------------------------------------------------------------------------------------------------------------
// Status notifications
//---------------------------------------------------------------------------------------------------------------------
void UclGen_Adapter_ErrorNotification(uint8 DLInst, sint32 ErrorCode) 
{
    (void)Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(DLInst, ErrorCode);
}

void UclGen_Adapter_LinkStatusChanged(uint8 DLInst, sint32 Status) 
{
    (void)Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(DLInst, Status);
}

void UclGen_Adapter_MessageTransmitStatus(uint16 MsgId, sint32 Status) 
{
    switch (MsgId)
    {
        case UclHealthDumpGetMsg_DID:

            // Scheduler notification for queued and nonperiodic messages
            OnDre_HealthDumpGetHdr();
            OnDre_HealthDumpGetData();
            break;
        case UpdateShortServiceReq_DID:

            // Scheduler notification for queued and nonperiodic messages
            OnDre_UpdateShortServiceReq();
            break;
        case UpdateLongServiceReq_DID:

            // Scheduler notification for queued and nonperiodic messages
            OnDre_UpdateLongServiceReq();
            break;
        case UclDiagRequest_DID:

            // Scheduler notification for queued and nonperiodic messages
            OnDre_DiagDIDRequest();
            OnDre_DiagIOCtrlRequest();
            OnDre_DiagRoutineRequest();
            break;
    }
}

void UclGen_Adapter_ReceiveMissingStatus(uint16 MsgId, sint32 Status) 
{
    switch (MsgId)
    {
    }
}

