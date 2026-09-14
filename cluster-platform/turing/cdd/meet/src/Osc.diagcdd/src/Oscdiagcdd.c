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
** Name:           Oscdiagcdd
**
** Description:
**
**
**===================================================================================================================*/

#ifndef OSCDIAGCDD_C
#define OSCDIAGCDD_C

/*====================================================================================================================
**                 I N C L U D E   F I L E S
**===================================================================================================================*/
#include "Mgrdiagcdd.h"
#include "Mgrdiagcdd_cfg.h"
#ifdef OSCDIAG_MODULE_ENABLE
#include "Oscdiagcdd.h"
#include "Oscdiagcdd_cfg.h"

/*====================================================================================================================
**   I N T E R N A L   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/

/*=====================================================================================================================
**  T Y P E    D E C L A R A T I O N S
**====================================================================================================================*/
#ifdef OSCDIAG_QUARTZ_CORRECTION
/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/
static NVMWriteRequestState Oscdiag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;

/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/

/*=====================================================================================================================
**
** Function Name    :  OscDiag_Quartz_Correction_Read
**
** Visibility       :  Public
**
** Description      :  Service to read quartz correction value in ppm
**
**
** Invocation       : Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Oscdiag_Quartz_Correction_Read(uint8 *Data, const uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        (void)Oscdiag_Service_Map.Oscdiagservice_GetNVM((void *)Data);
        ret = E_OK;
    }
    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Oscdiag_Quartz_Correction_Write
**
** Visibility       :  Public
**
** Description      :  Service to write quartz correction value in ppm
**
**
** Invocation       : Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Oscdiag_Quartz_Correction_Write(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    NvM_RequestResultType JobResult = NVM_REQ_OK;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Oscdiag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            Oscdiag_Service_Map.Oscdiagservice_SetJobStatus(0);
            ret = Oscdiag_Service_Map.Oscdiagservice_SetNVM(Data);
            if ((uint8)E_OK == ret)
            {
                ret = DCM_E_PENDING;
                Oscdiag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
            }
            break;
        case eNVMWrite_WaitForResponse:
            Oscdiag_Service_Map.Oscdiagservice_GetJobStatus(&JobResult);
            if (JobResult == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == NVM_REQ_OK)
            {
                Oscdiag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                ret = DCM_E_NOT_OK;
                *ErrorCode = INVALID_MODE;
                Oscdiag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
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

#ifdef OSCDIAG_QUARTZ_CONTROL
/*=====================================================================================================================
**
** Function Name    :  Oscdiag_Quartz_Control_ShortTermAdjustment
**
** Visibility       :  Public
**
** Description      :  Service to test Quartz control
**
** Invocation       :  Mgrdiagcdd_cfg.c
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
Std_ReturnType Oscdiag_Quartz_Control_ShortTermAdjustment(const uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        if ((Data[0U] > (MIN_NUMBER_OF_QUARTZ_SIGNAL - 1U)) && (Data[0U] <= MAX_NUMBER_OF_QUARTZ_SIGNAL))
        {
            ret = OscdiagService_quartz_control_STA_Map[(Data[0U] - 1U)].Oscdiagservice_quartz_control_STA(ErrorCode);
        }
        else
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
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
** Function Name    :  Oscdiag_Quartz_Control_ReturnControlToECU
**
** Visibility       :  Public
**
** Description      :  Service to restore Quartz control
**
** Invocation       :  Mgrdiagcdd_cfg.c
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Oscdiag_Quartz_Control_ReturnControlToECU(uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = OscdiagService_quartz_control_RCTE_Map[0U].Oscdiagservice_quartz_control_RCTE(ErrorCode);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef OSCDIAG_CLOCKVALUE_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Oscdiag_Quartz_Control_ShortTermAdjustment
**
** Visibility       :  Public
**
** Description      :  Service to test Quartz control
**
**
** Invocation       :  Mgrdiagcdd_cfg.c
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Oscdiag_ClockValue_Read(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Meet_ClockConfig.ClockValueReadFunction(Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Oscdiag_Quartz_Control_ReturnControlToECU
**
** Visibility       :  Public
**
** Description      :  Service to restore Quartz control
**
**
** Invocation       :  Mgrdiagcdd_cfg.c
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Oscdiag_ClockValue_Write(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Meet_ClockConfig.ClockValueWriteFunction(Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

#endif
#ifdef OSCDIAG_CLOCK_MONITORING
Std_ReturnType Oscdiag_clock_Monitoring_RC_Start(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Oscdiag_ClockMonitoring_start(Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef OSCDIAG_QUARTZ_CRYSTAL_LOAD_CAPACITANCE_FUSE_ACCESS
/*=====================================================================================================================
**
** Function Name    :  Oscdiag_Quartz_Load_Capacitance_Fuse_Access_Read
**
** Visibility       :  Public
**
** Description      :  Service to read quartz crystal load capacitance fuse access
**
**
** Invocation       : Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Oscdiag_Quartz_Load_Capacitance_Fuse_Access_Read(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Oscdiagservice_quartz_fusesConfig.Oscdiagservice_quartz_Fuse_access_Read(Data, ErrorCode);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Oscdiag_Quartz_Correction_Write
**
** Visibility       :  Public
**
** Description      :  Service to write quartz crystal load capacitance fuse access
**
**
** Invocation       : Meet_Mgrdiagcdd_Action
**
** Inputs           :  Data,ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Oscdiag_Quartz_Load_Capacitance_Fuse_Access_Write(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Oscdiagservice_quartz_fusesConfig.Oscdiagservice_quartz_Fuse_access_Write(Data, ErrorCode);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

#endif

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
** Date              :  13/09/2023
** CDSID             :  mprajapa
** Traceability      :  JIRA 3839
** Change Description:  Upddated identation and error code update for MEET Pre-Condition check.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  20/Jun/2022
** CDSID             :  kkarupp1
** Traceability      :  RTC-1670983
** Change Description: Implementation of DRS  FE0B, FE0C
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  16/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1632871, 1655512, 1660171
** Change Description:  Clock value read and write interfaces are added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/01/2020
** CDSID             :  dkasiman
** Traceability      :  RTC 1380314
** Change Description:  Coverity/Misra fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  12/march/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1268470
** Change Description:  vip - gip communication communication for quartz control is added
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 23/May/2018
** CDSID             : dkasiman
** Traceability      : RTC-1111915
** Change Description: Initial verion for MeetCdd bookshelf - OScdiag services
**====================================================================================================================*/
/*======================================================================================================================
** Date              : 5/Jun/2018
** CDSID             : dkasiman
** Traceability      : RTC-1111915
** Change Description: Review comments fix - Osc diag services
**=======================================================================================================================*/
#endif /* OSCDIAGCDD_C */
