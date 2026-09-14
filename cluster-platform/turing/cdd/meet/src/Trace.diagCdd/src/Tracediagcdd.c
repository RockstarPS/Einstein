/*=================================================================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2001. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**==================================================================================================================
**
** Name:           Tracediagcdd.c
**
** Description:
**
**
**===================================================================================================================*/

#ifndef TRACEDIAGCDD_C
#define TRACEDIAGCDD_C

/*====================================================================================================================
**                 I N C L U D E   F I L E S
**===================================================================================================================*/
#include "Mgrdiagcdd.h"
#include "Mgrdiagcdd_cfg.h"
#include "Tracediagcdd_cfg.h"
#include "Tracediagcdd.h"
/*====================================================================================================================
**   I N T E R N A L   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/
#ifdef TRACEDIAG_TRACEABILITY_BYTES
#define TRACE_MANF_SETBIT(temp, i)      (temp |= (uint8)(0x01U << (i)))
#define TRACE_MANF_RESETBIT(temp, i)    (temp &= (uint8)(~((uint8)(0x01U << (i)))))

#define TRACE_START_STAT            ((uint8)(1U))
#define TRACE_GOOD_STAT             ((uint8)(2U))
#define TRACE_CLEAR_STAT            ((uint8)(3U))

#define TRACE_MAX_STN               ((uint8)(15U)) // MAX station number for tracabiltiy
#define TRACE_STN_CNT_MASK          (0x0FU)

#define TRACE_STATION_INC_BY_4      ((uint8)(4U))
#define TRACE_STATION_MASK_BYTE     (0xF0U)
#endif
/*=====================================================================================================================
**  T Y P E    D E C L A R A T I O N S
**====================================================================================================================*/

/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/
#ifdef TRACEDIAG_NVM_WRITE_SERVICE_REQUIRED
static NVMWriteRequestState Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
#endif
/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/
#ifdef TRACEDIAG_TRACEABILITY_BYTES
static Std_ReturnType Tracediag_Read_Station_Traceability_status(uint8 StationIndex, uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType Tracediag_identify_station_and_write(uint8 StationIndex, uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType Tracediag_Write_Station_Traceability_status(uint8 StationIndex, uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRACEDIAG_SERVICE_1
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Service_1
**
** Visibility       :  Public
**
** Description      :  Service to read the data from the NVM
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Read_Service_1(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_1.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Write_Service_1
**
** Visibility       :  Public
**
** Description      :  Service to write the data to the NVM.
**
** Invocation       :   Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Write_Service_1(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            #endif
            ret = Tracediag_Service_1.Tracediagservice_SetNVM(Data);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = Data[0];
            }
            break;
        case eNVMWrite_WaitForResponse:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            #else
            Tracediag_Service_1.Tracediagservice_GetJobStatus(&JobResult);
            #endif

            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }
            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif
#ifdef TRACEDIAG_SERVICE_2
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Service_2
**
** Visibility       :  Public
**
** Description      :   Service to read the data from the NVM
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Read_Service_2(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_2.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Write_Service_2
**
** Visibility       :  Public
**
** Description      :  Service to write the data to the NVM
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Write_Service_2(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            #endif
            ret = Tracediag_Service_2.Tracediagservice_SetNVM(Data);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = Data[0];
            }
            break;
        case eNVMWrite_WaitForResponse:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            #else
            Tracediag_Service_2.Tracediagservice_GetJobStatus(&JobResult);
            #endif
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }
            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif
#ifdef TRACEDIAG_SERVICE_3
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Service_3
**
** Visibility       :  Public
**
** Description      :  Service to read the data from the NVM
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Read_Service_3(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_3.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Write_Service_3
**
** Visibility       :  Public
**
** Description      :  Service to write the data to the NVM.
**
** Invocation       :   Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Write_Service_3(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            #endif
            ret = Tracediag_Service_3.Tracediagservice_SetNVM(Data);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = Data[0];
            }
            break;
        case eNVMWrite_WaitForResponse:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            #else
            Tracediag_Service_3.Tracediagservice_GetJobStatus(&JobResult);
            #endif
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }

            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }

            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif
#ifdef TRACEDIAG_SERVICE_4
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Service_4
**
** Visibility       :  Public
**
** Description      :  Service to read the data from the NVM
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Read_Service_4(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_4.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Write_Service_4
**
** Visibility       :  Public
**
** Description      :  Service to write the data to the NVM
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Write_Service_4(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            #endif
            ret = Tracediag_Service_4.Tracediagservice_SetNVM(Data);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = Data[0];
            }
            break;
        case eNVMWrite_WaitForResponse:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            #else
            Tracediag_Service_4.Tracediagservice_GetJobStatus(&JobResult);
            #endif
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }

            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }

            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif
#ifdef TRACEDIAG_SERVICE_5
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Service_5
**
** Visibility       :  Public
**
** Description      :   Service to read the data from the NVM
**
** Invocation       :   Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Read_Service_5(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_5.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Write_Service_5
**
** Visibility       :  Public
**
** Description      :  Service to write the data to the NVM
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Write_Service_5(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            #endif
            ret = Tracediag_Service_5.Tracediagservice_SetNVM(Data);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = Data[0];
            }
            break;
        case eNVMWrite_WaitForResponse:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            #else
            Tracediag_Service_5.Tracediagservice_GetJobStatus(&JobResult);
            #endif
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }

            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif
#ifdef TRACEDIAG_SERVICE_6
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Service_6
**
** Visibility       :  Public
**
** Description      :  Service to read the data from the NVM
**
** Invocation       :   Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Read_Service_6(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_6.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Write_Service_6
**
** Visibility       :  Public
**
** Description      :  Service to write the data to the NVM
**
** Invocation       :   Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Write_Service_6(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            #endif
            ret = Tracediag_Service_6.Tracediagservice_SetNVM(Data);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = Data[0];
            }
            break;
        case eNVMWrite_WaitForResponse:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            #else
            Tracediag_Service_6.Tracediagservice_GetJobStatus(&JobResult);
            #endif
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }

            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif
#ifdef TRACEDIAG_SERVICE_7
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Service_7
**
** Visibility       :  Public
**
** Description      :  Service to read the data from the NVM
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Read_Service_7(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_7.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Write_Service_7
**
** Visibility       :  Public
**
** Description      :  Service to write the data to the NVM
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Write_Service_7(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            #endif
            ret = Tracediag_Service_7.Tracediagservice_SetNVM(Data);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = Data[0];
            }
            break;
        case eNVMWrite_WaitForResponse:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            #else
            Tracediag_Service_7.Tracediagservice_GetJobStatus(&JobResult);
            #endif
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }
            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif
#ifdef TRACEDIAG_SERVICE_8
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Service_8
**
** Visibility       :  Public
**
** Description      :  Service to read the data from the NVM
**
** Invocation       :   Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Read_Service_8(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_8.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Write_Service_8
**
** Visibility       :  Public
**
** Description      :  Service to write the data to the NVM
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Write_Service_8(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    NvM_RequestResultType JobResult = 0U;

    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            #endif
            ret = Tracediag_Service_8.Tracediagservice_SetNVM(Data);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = Data[0];
            }
            break;
        case eNVMWrite_WaitForResponse:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            #else
            Tracediag_Service_8.Tracediagservice_GetJobStatus(&JobResult);
            #endif
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }
            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif
#ifdef TRACEDIAG_SERVICE_9
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Service_9
**
** Visibility       :  Public
**
** Description      :  Service to read the data from the NVM
**
** Invocation       :   Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Read_Service_9(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_9.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Write_Service_9
**
** Visibility       :  Public
**
** Description      :  Service to write the data to the NVM
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Write_Service_9(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            #endif
            ret = Tracediag_Service_9.Tracediagservice_SetNVM(Data);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = Data[0];
            }
            break;
        case eNVMWrite_WaitForResponse:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            #else
            Tracediag_Service_9.Tracediagservice_GetJobStatus(&JobResult);
            #endif
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }

            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif
#ifdef TRACEDIAG_SERVICE_10
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Service_10
**
** Visibility       :  Public
**
** Description      :  Service to read the data from the NVM
**
**
** Invocation       :   Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Read_Service_10(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_10.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Write_Service_10
**
** Visibility       :  Public
**
** Description      :  Service to write the data to the NVM
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Write_Service_10(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            #endif
            ret = Tracediag_Service_10.Tracediagservice_SetNVM(Data);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = Data[0];
            }
            break;
        case eNVMWrite_WaitForResponse:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            #else
            Tracediag_Service_10.Tracediagservice_GetJobStatus(&JobResult);
            #endif
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }

            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif
#ifdef TRACEDIAG_SERVICE_11
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Service_11
**
** Visibility       :  Public
**
** Description      :  Service to read the data from the NVM
**
**
** Invocation       :   Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Read_Service_11(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_11.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Write_Service_11
**
** Visibility       :  Public
**
** Description      :  Service to write the data to the NVM
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Write_Service_11(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            #endif
            ret = Tracediag_Service_11.Tracediagservice_SetNVM(Data);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = Data[0];
            }
            break;
        case eNVMWrite_WaitForResponse:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            #else
            Tracediag_Service_11.Tracediagservice_GetJobStatus(&JobResult);
            #endif
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }

            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif
#ifdef TRACEDIAG_SERVICE_12
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Service_12
**
** Visibility       :  Public
**
** Description      :  Service to read the data from the NVM
**
**
** Invocation       :   Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Read_Service_12(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_12.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Write_Service_12
**
** Visibility       :  Public
**
** Description      :  Service to write the data to the NVM
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Write_Service_12(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            #endif
            ret = Tracediag_Service_12.Tracediagservice_SetNVM(Data);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = Data[0];
            }
            break;
        case eNVMWrite_WaitForResponse:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            #else
            Tracediag_Service_12.Tracediagservice_GetJobStatus(&JobResult);
            #endif
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }

            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif
#ifdef TRACEDIAG_SERVICE_13
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Service_13
**
** Visibility       :  Public
**
** Description      :  Service to read the data from the NVM
**
** Invocation       :   Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Read_Service_13(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_13.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Write_Service_13
**
** Visibility       :  Public
**
** Description      :  Service to write the data to the NVM
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Write_Service_13(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            #endif
            ret = Tracediag_Service_13.Tracediagservice_SetNVM(Data);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = Data[0];
            }
            break;
        case eNVMWrite_WaitForResponse:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            #else
            Tracediag_Service_13.Tracediagservice_GetJobStatus(&JobResult);
            #endif
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }

            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }

            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif
#ifdef TRACEDIAG_SERVICE_14
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Service_14
**
** Visibility       :  Public
**
** Description      :  Service to read the data from the NVM
**
** Invocation       :   Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Read_Service_14(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_14.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Write_Service_14
**
** Visibility       :  Public
**
** Description      :  Service to write the data to the NVM
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Write_Service_14(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            #endif
            ret = Tracediag_Service_14.Tracediagservice_SetNVM(Data);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = Data[0];
            }
            break;
        case eNVMWrite_WaitForResponse:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            #else
            Tracediag_Service_14.Tracediagservice_GetJobStatus(&JobResult);
            #endif
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }

            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif
#ifdef TRACEDIAG_SERVICE_15
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Service_15
**
** Visibility       :  Public
**
** Description      :  Service to read the data from the NVM
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Read_Service_15(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_15.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Write_Service_15
**
** Visibility       :  Public
**
** Description      :  Service to write the data to the NVM
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Write_Service_15(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            #endif
            ret = Tracediag_Service_15.Tracediagservice_SetNVM(Data);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = Data[0];
            }
            break;
        case eNVMWrite_WaitForResponse:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            #else
            Tracediag_Service_15.Tracediagservice_GetJobStatus(&JobResult);
            #endif
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }

            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif
#ifdef TRACEDIAG_SERVICE_16
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Service_16
**
** Visibility       :  Public
**
** Description      :  Service to read the data from the NVM
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Read_Service_16(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_16.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Write_Service_16
**
** Visibility       :  Public
**
** Description      :  Service to write the data to the NVM
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Write_Service_16(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            #endif
            ret = Tracediag_Service_16.Tracediagservice_SetNVM(Data);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = Data[0];
            }
            break;
        case eNVMWrite_WaitForResponse:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            #else
            Tracediag_Service_16.Tracediagservice_GetJobStatus(&JobResult);
            #endif
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }
            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef TRACEDIAG_SERVICE_17
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Service_17
**
** Visibility       :  Public
**
** Description      :  Service to read the data from the NVM
**
**
** Invocation       :   Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Read_Service_17(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_17.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Write_Service_17
**
** Visibility       :  Public
**
** Description      :  Service to write the data to the NVM
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Write_Service_17(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            #endif
            ret = Tracediag_Service_17.Tracediagservice_SetNVM(Data);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = Data[0];
            }
            break;
        case eNVMWrite_WaitForResponse:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            #else
            Tracediag_Service_17.Tracediagservice_GetJobStatus(&JobResult);
            #endif
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }

            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }

            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif
#ifdef TRACEDIAG_SERVICE_18
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Service_18
**
** Visibility       :  Public
**
** Description      :  Service to read the data from the NVM
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Read_Service_18(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_18.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Tracediag_Write_Service_18
**
** Visibility       :  Public
**
** Description      : Service to write the data to the NVM
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Write_Service_18(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            #endif
            ret = Tracediag_Service_18.Tracediagservice_SetNVM(Data);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = Data[0];
            }
            break;
        case eNVMWrite_WaitForResponse:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            #else
            Tracediag_Service_18.Tracediagservice_GetJobStatus(&JobResult);
            #endif
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }

            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef TRACEDIAG_SERVICE_19
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Service_19
**
** Visibility       :  Public
**
** Description      :   Service to read the data from the NVM.
**
**
** Invocation       :   Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Read_Service_19(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_19.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Write_Service_19
**
** Visibility       :  Public
**
** Description      :  Service to write the data to the NVM
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Write_Service_19(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            #endif
            ret = Tracediag_Service_19.Tracediagservice_SetNVM(Data);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = Data[0];
            }
            break;
        case eNVMWrite_WaitForResponse:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            #else
            Tracediag_Service_19.Tracediagservice_GetJobStatus(&JobResult);
            #endif
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }

            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif
#ifdef TRACEDIAG_SERVICE_20
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Service_20
**
** Visibility       :  Public
**
** Description      :  Service to read the data from GP core
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Read_Service_20(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_20.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Tracediag_Write_Service_20
**
** Visibility       :  Public
**
** Description      :  Service to write the data to memory/Fuse of GP core
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Write_Service_20(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            #endif
            ret = Tracediag_Service_20.Tracediagservice_SetNVM(Data);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = Data[0];
            }
            break;
        case eNVMWrite_WaitForResponse:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            #else
            Tracediag_Service_20.Tracediagservice_GetJobStatus(&JobResult);
            #endif
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }

            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef TRACEDIAG_SERVICE_21
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Service_21
**
** Visibility       :  Public
**
** Description      :  Service to read the data from Health logger
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Read_Service_21(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_21.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Tracediag_Write_Service_21
**
** Visibility       :  Public
**
** Description      :  Service to write the data to Health Logger.
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Write_Service_21(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            #endif
            ret = Tracediag_Service_21.Tracediagservice_SetNVM(Data);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = Data[0];
            }
            break;
        case eNVMWrite_WaitForResponse:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            #else
            Tracediag_Service_21.Tracediagservice_GetJobStatus(&JobResult);
            #endif
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }
            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}

#endif

#ifdef TRACEDIAG_SERVICE_22
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Service_22
**
** Visibility       :  Public
**
** Description      :  Service to read the data from the NVM.
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Read_Service_22(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_22.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Tracediag_Write_Service_22
**
** Visibility       :  Public
**
** Description      :  Service to write the data to the NVM
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Write_Service_22(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            #endif
            ret = Tracediag_Service_22.Tracediagservice_SetNVM(Data);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                *ErrorCode = Data[0];
            }
            break;
        case eNVMWrite_WaitForResponse:
            #ifdef COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            #else
            Tracediag_Service_22.Tracediagservice_GetJobStatus(&JobResult);
            #endif
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }
            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef TRACEDIAG_SERVICE_23
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Service_23
**
** Visibility       :  Public
**
** Description      :  Service to read the data from Health logger
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Read_Service_23(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_23.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}

#endif

#ifdef TRACEDIAG_SERVICE_24
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Service_24
**
** Visibility       :  Public
**
** Description      :  Service to reset the logs
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Read_Service_24(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_24.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Tracediag_Write_Service_24
**
** Visibility       :  Public
**
** Description      :  Service to write
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Write_Service_24(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_24.Tracediagservice_SetNVM((void *)Data);
        if (E_NOT_OK == ret)
        {
            ErrorCode[DATA_BYTE_0] = Data[DATA_BYTE_0];
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef TRACEDIAG_SERVICE_25
static eRoutineStatusTFT Tracediag_TPFWUpdate_Status = eROUTINE_TFT_NOTACTIVE;
/*=====================================================================================================================
**
** Function Name    :  Tracediag_TPFirmware_Update_RCStart
**
** Visibility       :  Public
**
** Description      :  Starts Routine Control to update Touch Firmware Update
**
**
** Invocation       :  MeetMgr.diagcdd  , Function:RC_START_Diag_FD01
**
** Inputs           :  Data[In]:
**                     Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**                     E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_TPFirmware_Update_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        if (Tracediag_TPFWUpdate_Status != eROUTINE_TFT_INPROGRESS)
        {
            ret = TPFirmwareUpdate.TraceDiag_Start(Data, ErrorCode);
            if (ret == (uint8)E_OK)
            {
                Tracediag_TPFWUpdate_Status = eROUTINE_TFT_INPROGRESS;
            }
            else
            {
                Tracediag_TPFWUpdate_Status = eROUTINE_TFT_FAILURE;
            }
            ret = (uint8)E_OK;
            Data[0] = Tracediag_TPFWUpdate_Status;
        }
        else
        {
            ret = E_NOT_OK;
            ErrorCode[0U] = DCM_E_CONDITIONSNOTCORRECT;
        }
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_TPFirmware_Update_RCStatus
**
** Visibility       :  Public
**
** Description      :  Gives Routine Control Status of Cybersecurity keys verification
**
**
** Invocation       :  MeetMgr.diagcdd , Function:RC_RESULTS_Diag_FD01
**
** Inputs           :  Data[Out]: status of Routine Control to verify all Ceybersecurity Keys
**                     Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**                     E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_TPFirmware_Update_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = TPFirmwareUpdate.TraceDiag_Results(Data, ErrorCode);
        Tracediag_TPFWUpdate_Status = (eRoutineStatusTFT)Data[0];
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef TRACEDIAG_TRACEBYTES_STATION_1
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Traceability_Bytes_TRACE_STATION_1_Read
**
** Visibility       :  Public
**
** Description      :  Service to read traceability bytes TRACE_STATION_1
**
**
** Invocation       :   Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Traceability_Bytes_TRACE_STATION_1_Read(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_TraceBytesTRACE_STATION_1.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Traceability_Bytes_TRACE_STATION_1_Write
**
** Visibility       :  Public
**
** Description      :  Service to write Traceability bytes TRACE_STATION_1
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Traceability_Bytes_TRACE_STATION_1_Write(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;
    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            ret = Tracediag_Write_Station_Traceability_status(TRACE_STATION_1, Data, ErrorCode);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                /*Use below code as per the requirements
                 *
                 * (*ErrorCode = DCM_E_CONDITIONSNOTCORRECT);
                 */
            }
            break;
        case eNVMWrite_WaitForResponse:
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }

            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif
#ifdef TRACEDIAG_TRACEBYTES_STATION_2
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Traceability_Bytes_TRACE_STATION_2_Read
**
** Visibility       :  Public
**
** Description      :  Service to read traceability bytes TRACE_STATION_2
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Traceability_Bytes_TRACE_STATION_2_Read(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_TraceBytesTRACE_STATION_2.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Traceability_Bytes_TRACE_STATION_2_Write
**
** Visibility       :  Public
**
** Description      :  Service to write Traceability bytes TRACE_STATION_2
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Traceability_Bytes_TRACE_STATION_2_Write(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;
    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            ret = Tracediag_Write_Station_Traceability_status(TRACE_STATION_2, Data, ErrorCode);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                /*Use below code as per the requirements
                 *
                 * (*ErrorCode = DCM_E_CONDITIONSNOTCORRECT);
                 */
            }
            break;
        case eNVMWrite_WaitForResponse:
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }

            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif
#ifdef TRACEDIAG_TRACEBYTES_STATION_3

/*=====================================================================================================================
**
** Function Name    :  Tracediag_Traceability_Bytes_TRACE_STATION_3_Read
**
** Visibility       :  Public
**
** Description      :  Service to read traceability bytes TRACE_STATION_3
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Traceability_Bytes_TRACE_STATION_3_Read(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_TraceBytesTRACE_STATION_3.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Traceability_Bytes_TRACE_STATION_3_Write
**
** Visibility       :  Public
**
** Description      :  Service to write Traceability bytes TRACE_STATION_3
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Traceability_Bytes_TRACE_STATION_3_Write(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;
    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            ret = Tracediag_Write_Station_Traceability_status(TRACE_STATION_3, Data, ErrorCode);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                /*Use below code as per the requirements
                 *
                 * (*ErrorCode = DCM_E_CONDITIONSNOTCORRECT);
                 */
            }
            break;
        case eNVMWrite_WaitForResponse:
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }

            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif
#ifdef TRACEDIAG_TRACEBYTES_STATION_4
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Traceability_Bytes_TRACE_STATION_4_Read
**
** Visibility       :  Public
**
** Description      : Service to read traceability bytes TRACE_STATION_4
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Traceability_Bytes_TRACE_STATION_4_Read(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_TraceBytesTRACE_STATION_4.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Traceability_Bytes_TRACE_STATION_4_Write
**
** Visibility       :  Public
**
** Description      :  Service to write Traceability bytes TRACE_STATION_4
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Traceability_Bytes_TRACE_STATION_4_Write(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;
    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            ret = Tracediag_Write_Station_Traceability_status(TRACE_STATION_4, Data, ErrorCode);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                /*Use below code as per the requirements
                 *
                 * (*ErrorCode = DCM_E_CONDITIONSNOTCORRECT);
                 */
            }
            break;
        case eNVMWrite_WaitForResponse:
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }
            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef TRACEDIAG_TRACEBYTES_STATION_5
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Traceability_Bytes_TRACE_STATION_5_Read
**
** Visibility       :  Public
**
** Description      :  Service to read traceability bytes TRACE_STATION_5
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Traceability_Bytes_TRACE_STATION_5_Read(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_TraceBytesTRACE_STATION_5.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Traceability_Bytes_TRACE_STATION_5_Write
**
** Visibility       :  Public
**
** Description      :  Service to write Traceability bytes TRACE_STATION_5
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Traceability_Bytes_TRACE_STATION_5_Write(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;
    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            ret = Tracediag_Write_Station_Traceability_status(TRACE_STATION_5, Data, ErrorCode);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
                /*Use below code as per the requirements
                 *
                 * (*ErrorCode = DCM_E_CONDITIONSNOTCORRECT);
                 */
            }
            break;
        case eNVMWrite_WaitForResponse:
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }

            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif
#ifdef TRACEDIAG_RESERVEDBYTES
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Reserved_Bytes_Read
**
** Visibility       :  Public
**
** Description      :  Service to read Reserved bytes.
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Reserved_Bytes_Read(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Tracediag_Service_Reservedytes.Tracediagservice_GetNVM((void *)Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Reserved_Bytes_Write
**
** Visibility       :  Public
**
** Description      :  Service to write reserved bytes
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Tracediag_Reserved_Bytes_Write(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            ret = Tracediag_Service_Reservedytes.Tracediagservice_SetNVM(Data);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            break;
        case eNVMWrite_WaitForResponse:
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }

            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }

            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef TRACEDIAG_TRACEABILITY_BYTES
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Traceability_Bytes_Read
**
** Visibility       :  Public
**
** Description      :  Service to read traceability bytes
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Traceability_Bytes_Read(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 fl_station_index_U8;
    uint8 MfgModeActive = 0U;
    
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        fl_station_index_U8 = Data[0];
        ret = Tracediag_Read_Station_Traceability_status(fl_station_index_U8, Data, ErrorCode);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Tracediag_Traceability_Bytes_Write
**
** Visibility       :  Public
**
** Description      :  Service to write traceability bytes.
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
Std_ReturnType Tracediag_Traceability_Bytes_Write(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 fl_station_index_U8;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        switch (Tracediag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Write(0);
            fl_station_index_U8 = Data[0];
            ret = Tracediag_Write_Station_Traceability_status(fl_station_index_U8, Data, ErrorCode);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            else
            {
            }
            break;

        case eNVMWrite_WaitForResponse:
            Tracediag_NvmJobResult.Tracediagservice_NVMJob_Read(&JobResult);
            if (JobResult == (uint8)NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == (uint8)NVM_REQ_OK)
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                Tracediag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }
            break;

        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Read_Station_Traceability_status
**
** Visibility       :  Private
**
** Description      :  Used to read traceability status by station wise
**
** Invocation       :  Tracediag_Write_Station_Traceability_status/Tracediag_Traceability_Bytes_Read
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static Std_ReturnType Tracediag_Read_Station_Traceability_status(uint8 StationIndex, uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType fl_ret_U8 = E_NOT_OK;

    switch (StationIndex)
    {
    
    #ifdef TRACE_STATION_1
    case TRACE_STATION_1:
        (void)Tracediag_Service_Station_Traceability_Bytes.Tracediagservice_GetNVM_TRACE_STATION_1(Data);
        fl_ret_U8 = E_OK;
        break;
    #endif

    #ifdef TRACE_STATION_2
    case TRACE_STATION_2:
        (void)Tracediag_Service_Station_Traceability_Bytes.Tracediagservice_GetNVM_TRACE_STATION_2(Data);
        fl_ret_U8 = E_OK;
        break;
    #endif

    #ifdef TRACE_STATION_3
    case TRACE_STATION_3:
        (void)Tracediag_Service_Station_Traceability_Bytes.Tracediagservice_GetNVM_TRACE_STATION_3(Data);
        fl_ret_U8 = E_OK;
        break;
    #endif

    #ifdef TRACE_STATION_4
    case TRACE_STATION_4:
        (void)Tracediag_Service_Station_Traceability_Bytes.Tracediagservice_GetNVM_TRACE_STATION_4(Data);
        fl_ret_U8 = E_OK;
        break;
    #endif

    #ifdef TRACE_STATION_5
    case TRACE_STATION_5:
        (void)Tracediag_Service_Station_Traceability_Bytes.Tracediagservice_GetNVM_TRACE_STATION_5(Data);
        fl_ret_U8 = E_OK;
        break;
    #endif

    #ifdef TRACE_STATION_6
    case TRACE_STATION_6:
        (void)Tracediag_Service_Station_Traceability_Bytes.Tracediagservice_GetNVM_TRACE_STATION_6(Data);
        fl_ret_U8 = E_OK;
        break;
    #endif
    
    default:
        *ErrorCode = MGRDIG_REQUEST_OUT_OF_RANGE;
        break;
    }

    return fl_ret_U8;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_Write_Station_Traceability_status
**
** Visibility       :  Private
**
** Description      :  Update station counter and station status based on the trigger condition
**
** Invocation       :  Tracediag_Write_Station_Traceability_status/Tracediag_Traceability_Bytes_Read
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static Std_ReturnType Tracediag_Write_Station_Traceability_status(uint8 StationIndex, uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType fl_ret_U8 = E_NOT_OK;
    uint8 fl_station_counter_U8 = 0;
    uint8 Tmp[2] = {0};
    uint8 State = 0;

    (void)Tracediag_Read_Station_Traceability_status(StationIndex, Tmp, ErrorCode);
    fl_station_counter_U8 = (Tmp[0] & TRACE_STN_CNT_MASK);
    State = Data[STATION_STATE]; // STATION_STATE can be DATA_BYTE_1 or DATA_BYTE_0
    Data[0] = Tmp[0];            // Move tracabiltiy status to Data[0]

    switch (State)
    {
    case TRACE_START_STAT:

        TRACE_MANF_RESETBIT(Data[0], TRACE_STATION_INC_BY_4);
        if (fl_station_counter_U8 < TRACE_MAX_STN)
        {
            fl_station_counter_U8++;
            Data[0] &= TRACE_STATION_MASK_BYTE;
            Data[0] |= (fl_station_counter_U8 & TRACE_STN_CNT_MASK);
            fl_ret_U8 = Tracediag_identify_station_and_write(StationIndex, Data, ErrorCode);
        }
        else
        {
            #ifdef TRACEABILITY_OVERFLOW_CHECK
            fl_station_counter_U8 = TRACEABILITY_OVERFLOW_VALUE;
            Data[0] &= TRACE_STATION_MASK_BYTE;
            Data[0] |= (fl_station_counter_U8 & TRACE_STN_CNT_MASK);
            fl_ret_U8 = Tracediag_identify_station_and_write(StationIndex, Data, ErrorCode);
            #else
            fl_ret_U8 = E_NOT_OK;
            *ErrorCode = MGRDIG_REQUEST_OUT_OF_RANGE;
            #endif
        }
        break;

    case TRACE_GOOD_STAT:
        TRACE_MANF_SETBIT(Data[0], TRACE_STATION_INC_BY_4);
        fl_ret_U8 = Tracediag_identify_station_and_write(StationIndex, Data, ErrorCode);
        break;

    case TRACE_CLEAR_STAT:
        TRACE_MANF_RESETBIT(Data[0], TRACE_STATION_INC_BY_4);
        fl_ret_U8 = Tracediag_identify_station_and_write(StationIndex, Data, ErrorCode);
        break;

    default:
        fl_ret_U8 = E_NOT_OK;
        *ErrorCode = MGRDIG_REQUEST_OUT_OF_RANGE;
        break;
    }

    return fl_ret_U8;
}
/*=====================================================================================================================
**
** Function Name    :  Tracediag_identify_station_and_write
**
** Visibility       :  Private
**
** Description      :  Identify the station and write status in NVM
**
** Invocation       :  Tracediag_Write_Station_Traceability_status
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static Std_ReturnType Tracediag_identify_station_and_write(uint8 StationIndex, uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType fl_ret_U8 = E_NOT_OK;

    switch (StationIndex)
    {
    #ifdef TRACE_STATION_1
    case TRACE_STATION_1:
        fl_ret_U8 = Tracediag_Service_Station_Traceability_Bytes.Tracediagservice_SetNVM_TRACE_STATION_1(Data);
        break;
    #endif

    #ifdef TRACE_STATION_2
    case TRACE_STATION_2:
        fl_ret_U8 = Tracediag_Service_Station_Traceability_Bytes.Tracediagservice_SetNVM_TRACE_STATION_2(Data);
        break;
    #endif

    #ifdef TRACE_STATION_3
    case TRACE_STATION_3:
        fl_ret_U8 = Tracediag_Service_Station_Traceability_Bytes.Tracediagservice_SetNVM_TRACE_STATION_3(Data);
        break;
    #endif

    #ifdef TRACE_STATION_4
    case TRACE_STATION_4:
        fl_ret_U8 = Tracediag_Service_Station_Traceability_Bytes.Tracediagservice_SetNVM_TRACE_STATION_4(Data);
        break;
    #endif

    #ifdef TRACE_STATION_5
    case TRACE_STATION_5:
        fl_ret_U8 = Tracediag_Service_Station_Traceability_Bytes.Tracediagservice_SetNVM_TRACE_STATION_5(Data);
        break;
    #endif

    #ifdef TRACE_STATION_6
    case TRACE_STATION_6:
        fl_ret_U8 = Tracediag_Service_Station_Traceability_Bytes.Tracediagservice_SetNVM_TRACE_STATION_6(Data);
        break;
    #endif

    default:
        *ErrorCode = MGRDIG_REQUEST_OUT_OF_RANGE;
        break;
    }

    return fl_ret_U8;
}
#endif

/*=====================================================================================================================
**  for each change to this file, be sure to record:
**  1.  who made the change and when the change was made
**  2.  why the change was made and the intended result
**  Following block needs to be repeated for each change
**====================================================================================================================*/
/*=====================================================================================================================
**   Note: In the traceability column we need to trace back to the Design Doc.
**   For the initial version it is traced to the Design Document section.
**   For further changes it shall trace to the source of the change which may
**   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any
**   other reason
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  01/Mar/2024
** CDSID             :  ddanecha
** Traceability      :  JIRA - TCID31491-3218
** Change Description:  Traceability overflow corrected and confiuration added for stations
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/09/2023
** CDSID             :  mprajapa
** Traceability      :  JIRA 3839
** Change Description:  Upddated identation and MEET Pre-Condition check.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  12/Apr/2023
** CDSID             :  spalan11
** Traceability      :  RTC-1977277
** Change Description:  Added Tracediag_Write_Service_24() and removed Tracediag_Read_Status_24()
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/Mar/2023
** CDSID             :  tsubrama
** Traceability      :  RTC-1934747
** Change Description:  Added start and stop routine for TFT FW update
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  03/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1707104
** Change Description:  MeetCdd Coverity-MISRA fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  23/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1634375
** Change Description:  Coverity/MISRA Fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 6/May/2021
** CDSID             : razhakes
** Traceability      : RTC-1291863
** Change Description: COMMON_JOBSTATUS_RTE_VAR_FOR_FULL_NVM introduced
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/01/2020
** CDSID             :  dkasiman
** Traceability      :  RTC 1380314
** Change Description:  Coverity/Misra fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  12/12/2019
** CDSID             :  dkasiman
** Traceability      :  RTC 1389704
** Change Description:  For TRACE service 17, ret variable updated from user function to get data grom GIP.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 10/Oct/2018
** CDSID             : gdhilipr
** Traceability      : RTC 1215565
** Change Description: Precondition check for product visteon part number
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 01/Oct/2018
** CDSID             : gdhilipr
** Traceability      : RTC 1208270
** Change Description: Traceability services update(FD4D )– For the station WS2 & Generalizing the Station names
                       (ICT - Station1,FCT- Station2,AC  - Station3,FC  -  Station4,WS2 - Station5,AMS to Station6)
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/July/2018
** CDSID             :  dkasiman
** Traceability      :  RTC-1148605/RTC-1148623
** Change Description:  Review comments fix: START_STAT,GOOD_STAT and CLEAR_STAT macros are appended with TRACE.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  11/July/2018
** CDSID             :  dkasiman
** Traceability      :  RTC-1148605/RTC-1148623
** Change Description:  Traceability bytes implementation
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  10/Jul/2018
** CDSID             :  gnataraj
** Traceability      :  RTC-1152264, RTC-1153689
** Change Description:  Peer review comments fixed
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  09/Jul/2018
** CDSID             :  gnataraj
** Traceability      :  RTC-1152264
** Change Description:  Generalized the function for Read and Write Services
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  06/Jun/2018
** CDSID             :  dkasiman
** Traceability      :  RTC-1098594
** Change Description:  Review comments fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 20/May/2018
** CDSID             : dkasiman
** Traceability      : RTC-1098594
** Change Description: Initial version for MeetCdd bookshelf - Traceability services
**====================================================================================================================*/
#endif /* TRACEDIAGCDD_C */
