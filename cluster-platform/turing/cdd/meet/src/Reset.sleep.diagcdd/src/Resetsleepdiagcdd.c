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
** Name:           Resetsleepdiagcdd.c
**
** Description:    contains Reset and Sleep related services.checks if software in Manufacturing mode before executing service request
**
**
**===================================================================================================================*/

#ifndef RESETSLEEPDIAGCDD_C
#define RESETSLEEPDIAGCDD_C

/*====================================================================================================================
**                 I N C L U D E   F I L E S
**===================================================================================================================*/
#include "Mgrdiagcdd_cfg.h"
#ifdef RESETDIAG_MODULE_ENABLE
#include "Resetsleepdiagcdd.h"
#include "Resetsleepdiagcdd_cfg.h"
#include "Mgrdiagcdd.h"
#include "Mgrdiagcdd_cfg.h"

/*====================================================================================================================
**   I N T E R N A L   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/

/*=====================================================================================================================
**  T Y P E    D E C L A R A T I O N S
**====================================================================================================================*/
#ifdef SLEEPMODEENABLE
static eRoutineStatus SlpModeReq_RCStatus = eROUTINE_INACTIVE;
#endif

#ifdef WDRSTENABLE
static eRoutineStatus WDRstReq_RCStatus = eROUTINE_INACTIVE;
#endif
/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/
#ifdef LOWQCURRENTENABLE
static uint8 LowQCurrent_Status = 0u;
#endif

#ifdef SWRSTENABLE
static boolean Ecu_Soft_Reset = cFALSE;
#endif
#ifdef WDRSTENABLE
static boolean Ecu_WD_Reset = cFALSE;
#endif

#ifdef SLEEPMODEENABLE
static boolean Sleep_DiagRequest = cFALSE;
#endif

#ifdef RSTCNTRREADINGENABLE
static NVMWriteRequestState ResetSleepDiag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
#endif
/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/
void ResetSleepdiag_Init(void)
{
#ifdef LOWQCURRENTENABLE
    LowQCurrent_Status = eLowQCmdOFF;
#endif
}

#ifdef SLEEPMODEENABLE
/*=====================================================================================================================
**
** Function Name    :  Resetsleepdiag_SleepingMode_RCStart
**
** Visibility       :  Public
**
** Description      :  makes the cluster to go to sleep.Wakes up on CAN/Ignition DIN
**
** Invocation       :  MeetMgr.diagcdd, Function:RC_START_Diag_F103
**
** Inputs           :  Data[Out]: contains status of Routine Control(sleeping mode control) start
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Resetsleepdiag_SleepingMode_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        /* set flag for sleep mode here */
        Sleep_DiagRequest = (boolean)cTRUE;
        SlpModeReq_RCStatus = eROUTINE_FINISH_OK;
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(SLPMODEREQRCTYPE, (uint8)SlpModeReq_RCStatus);
        ret = E_OK;
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Resetsleepdiag_SleepingMode_RCStop
**
** Visibility       :  Public
**
** Description      :  stops sleep mode
**
** Invocation       :  MeetMgr.diagcdd, Function:RC_STOP_Diag_F103
**
** Inputs           :  Data[Out]: contains status of Routine Control(sleeping mode control) stop
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Resetsleepdiag_SleepingMode_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        SlpModeReq_RCStatus = eROUTINE_FINISH_OK;
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(SLPMODEREQRCTYPE, (uint8)SlpModeReq_RCStatus);
        ret = E_OK;
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Resetsleepdiag_SleepingMode_RCStatus
**
** Visibility       :  Public
**
** Description      :  returns status of Sleep mode request routine
**
** Invocation       :  MeetMgr.diagcdd, Function:RC_RESULTS_Diag_F103
**
** Inputs           :  Data[Out]: contains status of Routine Control(sleeping mode control)
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Resetsleepdiag_SleepingMode_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        SlpModeReq_RCStatus = eROUTINE_INACTIVE;
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(SLPMODEREQRCTYPE, (uint8)SlpModeReq_RCStatus);
        ret = E_OK;
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
** Function Name    :  Manuf_Sleep_Task
**
** Visibility       :  Public
**
** Description      :  triggers sleep mode
**
** Invocation       :  MeetMgr.diagcdd , Function:CmpActive
**
** Inputs           :  NA
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
void Manuf_Sleep_Task(void)
{
    if (Sleep_DiagRequest == (boolean)cTRUE)
    {
        /* go to sleep mode*/
        SlpReqConfig.ResetSleepiag_Write();
        Sleep_DiagRequest = (boolean)cFALSE;
    }
}
#endif

#ifdef WDRSTENABLE
/*=====================================================================================================================
**
** Function Name    :  Resetsleepdiag_WDReset_RCStart
**
** Visibility       :  Public
**
** Description      :  triggers watch dog reset
**
** Invocation       :  MeetMgr.diagcdd, Function:RC_START_Diag_F10B
**
** Inputs           :  Data[Out]: contains status of Routine Control (watchdog reset trigger)Start
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Resetsleepdiag_WDReset_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {

#ifndef WDRESET_VIP_GIP_SUPPORT

#ifdef WDRESET_INC_WDCOUNT
        (void)WatchDogReset_Enable_Config.WatchDogResetIncCounter();
#endif

        Ecu_WD_Reset = (boolean)cTRUE;
        WDRstReq_RCStatus = eROUTINE_FINISH_OK;
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(WDRSTRCTYPE, (uint8)WDRstReq_RCStatus);
        ret = E_OK;

#else
        if (Data[DATA_BYTE_0] == WATCHDOG_RST_VIP)
        {
            Ecu_WD_Reset = cTRUE;
            WDRstReq_RCStatus = eROUTINE_FINISH_OK;
            Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(WDRSTRCTYPE, WDRstReq_RCStatus);
            ret = E_OK;
        }

        if (Data[DATA_BYTE_0] == WATCHDOG_RST_GIP)
        {

            Enable any single interface from the below as per the requirements.

                ret = WatchDogReset_control_Config[(Data[DATA_BYTE_0] - 1)].WatchDogReset(Data, ErrorCode);
            ret = WatchDogReset_control_Config.WatchDogReset(Data, ErrorCode);
        }

        if (Data[DATA_BYTE_0] == WATCHDOG_RST_VIP_AND_GIP)
        {
            ret = WatchDogReset_control_Config.WatchDogReset(Data, ErrorCode);
            if (ret == E_OK)
            {
                Ecu_WD_Reset = cTRUE;
                WDRstReq_RCStatus = eROUTINE_FINISH_OK;
                Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(WDRSTRCTYPE, WDRstReq_RCStatus);
                ret = E_OK;
            }
        }
#endif
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Resetsleepdiag_WDReset_RCStop
**
** Visibility       :  Public
**
** Description      :
**
** Invocation       :  MeetMgr.diagcdd, Function:RC_STOP_Diag_F10B
**
** Inputs           :  Data[Out]: contains status of Routine Control (watchdog reset trigger)Stop
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Resetsleepdiag_WDReset_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        WDRstReq_RCStatus = eROUTINE_FINISH_OK;
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(WDRSTRCTYPE, (uint8)WDRstReq_RCStatus);
        ret = E_OK;
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Resetsleepdiag_WDReset_RCStatus
**
** Visibility       :  Public
**
** Description      :  returns status of watch dog reset request
**
** Invocation       :  MeetMgr.diagcdd, Function:RC_RESULTS_Diag_F10B
**
** Inputs           :  Data[Out]: contains status of Routine Control (watchdog reset trigger)
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Resetsleepdiag_WDReset_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        WDRstReq_RCStatus = eROUTINE_INACTIVE;
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(WDRSTRCTYPE, (uint8)WDRstReq_RCStatus);
        ret = E_OK;
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef SWRSTENABLE
/*=====================================================================================================================
**
** Function Name    :  Resetsleepdiag_SWReset
**
** Visibility       :  Public
**
** Description      :  triggers SW reset
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           : Errorcode:to be updated with error code if any
**
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**Function definition: Std_ReturnType Resetsleepdiag_SWReset(uint8 *Data, uint8 *ErrorCode)
**====================================================================================================================*/
FUNC(Std_ReturnType, CMeetCdd_CODE) CMeetCdd_Resetsleepdiag_SWReset(P2VAR(UInt8, AUTOMATIC, RTE_MEETCDD_APPL_VAR) Data, P2VAR(UInt8, AUTOMATIC, RTE_MEETCDD_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        Ecu_Soft_Reset = cTRUE;
        ret = E_OK;
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#if defined(SWRSTENABLE) || defined(WDRSTENABLE)
/*=====================================================================================================================
**
** Function Name    :  ResetDiag_Periodic
**
** Visibility       :  Public
**
** Description      :  once watchdog reset request is received,debounces for configured time and then triggers WD Reset
**
** Invocation       :  MeetMgr.diagcdd, Function:CmpActive
**
** Inputs           :  NA
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
void ResetDiag_Periodic(void)
{
#ifdef SWRSTENABLE
    static uint8 WaitSoftResetCntr = 0U;
#endif

#ifdef WDRSTENABLE
    static uint8 WaitWDResetCntr = 0U;
#endif

#ifdef SWRSTENABLE
    if (Ecu_Soft_Reset == (boolean)cTRUE)
    {
        if (WaitSoftResetCntr > SWRSTDEBOUNCELIMIT)
        {
            RESETDIAG_PERFORM_RESET();
        }
        else
        {
            WaitSoftResetCntr++;
        }
    }

    else
#endif
    {
#ifdef WDRSTENABLE
        if (Ecu_WD_Reset == (boolean)cTRUE)
        {
            if (WaitWDResetCntr > WDRSTDEBOUNCELIMIT)
            {
                while ((boolean)1)
                {
                    /*
                     Intentional Infinite while loop, It is required to trigger WDG reset
                     Coverity warning associated to this has to be deviated
                    */
                }
            }
            else
            {
                WaitWDResetCntr++;
            }
        }
#endif
    }
}
#endif

#ifdef RSTCNTRREADINGENABLE
/*=====================================================================================================================
**
** Function Name    :  Resetsleepdiag_ResetCounters_Read
**
** Visibility       :  Public
**
** Description      :  The reason for reset is read at each start of manufacturing SW.
**					   Based on the reason ,dedicated NVM Counters are incremented.
**					   The reset counters are read in this service.
**
** Invocation       :  MeetMgr.diagcdd, Function:Read_Diag_FA47
**
** Inputs           :  Data[Out]:reset counters value
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Resetsleepdiag_ResetCounters_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = RstCntrReadingConfig_U8.ResetSleepDiag_Read(Data);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Resetsleepdiag_ResetCounters_Write
**
** Visibility       :  Public
**
** Description      :  Clear reset counters. if the data contains non zero values, request out of range is responded
**
** Invocation       :  MeetMgr.diagcdd, Function:Write_Diag_FA47
**
** Inputs           :  Data[In]:reset counters value
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Resetsleepdiag_ResetCounters_Write(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
#ifdef RESET_BY_PASS_ENABLE
    ret = RstCntrReadingConfig_U8.ResetSleepiag_Write(Data);
#else
    uint8 MfgModeActive = 0U, ErrFlg = cFALSE;
    uint8 idx;
    NvM_RequestResultType JobResult = 1U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        switch (ResetSleepDiag_CurrentNVMWriteReqState)
        {
        case eNVMWrite_InitiateRequest:
            for (idx = 0; idx < RSTCNTRDATALEN; idx++)
            {
                if (Data[idx] != (uint8)0) /*check if data contains any non-zero value, if so send negative response*/
                {
                    ErrFlg = cTRUE;
                    break;
                }
            }
            if (cTRUE == ErrFlg)
            {
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE; /*if the data contains non permitted values, request out of range is responded*/
            }
            else
            {

                ResetSleepDiag_NvmJobResult.ResetSleepDiagservice_NVMJob_Write(0);
                ret = RstCntrReadingConfig_U8.ResetSleepiag_Write(Data);
                if ((uint8)E_OK == ret)
                {
                    ret = DCM_E_PENDING;
                    ResetSleepDiag_CurrentNVMWriteReqState = eNVMWrite_WaitForResponse;
                }
                else
                {
                    *ErrorCode = Data[0];
                }
            }
            break;
        case eNVMWrite_WaitForResponse:
            ResetSleepDiag_NvmJobResult.ResetSleepDiagservice_NVMJob_Read(&JobResult);
            if (JobResult == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else if (JobResult == NVM_REQ_OK)
            {
                ResetSleepDiag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_OK;
            }
            else
            {
                ResetSleepDiag_CurrentNVMWriteReqState = eNVMWrite_InitiateRequest;
                ret = DCM_E_NOT_OK;
                *ErrorCode = MGRDIAG_INVALID_MODE;
            }
            break;
        default:
            ret = DCM_E_OK;
            break;
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
#endif
    return (ret);
}
#endif
#ifdef RESETSLEEPDIAG_ODOMETER_RESET
/*=====================================================================================================================
**
** Function Name    :  Resetsleepdiag_odometer_Reset
**
** Visibility       :  Public
**
** Description      :   Service to reset the odometer.
**
**
** Invocation       :  Meet_Mgrdiagcdd_Action
**
** Inputs           :  data and ErrorCode.
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Resetsleepdiag_odometer_Reset(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType fl_ret_U8 = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        fl_ret_U8 = ResetSleepDiag_Odo_Reset_Config.ResetSleepiag_Odo(Data);

        if ((uint8)E_NOT_OK == fl_ret_U8)
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (fl_ret_U8);
}
#endif

#ifdef LOWQCURRENTENABLE
Std_ReturnType ResetSleepdiag_SetLowQCurrent(ELowQCurrentSleepStatus *Data)
{
    Std_ReturnType Ret = E_NOT_OK;

    if (*Data == eLowQCmdON)
    {
        LowQCurrent_Status = eLowQCmdON;
    }
    else
    {
        LowQCurrent_Status = eLowQCmdOFF;
    }

#ifdef LOWQCURRENTENABLE_CONTROL
    Ret = LowQCurrentConfig.ResetSleepiag_Write(&LowQCurrent_Status);
#else
    Ret = E_OK;
#endif

    return Ret;
}

Std_ReturnType ResetSleepdiag_Get_LowQCurrent_Sleep_Status(ELowQCurrentSleepStatus *Data)
{
    Std_ReturnType Ret = E_NOT_OK;

    *Data = (ELowQCurrentSleepStatus)LowQCurrent_Status;

    Ret = E_OK;
    return Ret;
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
** Date              :  13/09/2023
** CDSID             :  mprajapa
** Traceability      :  JIRA 3839
** Change Description:  Upddated identation.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  29/Nov/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1842062
** Change Description:  Provision is given to increment wdg counter
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  27/Oct/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1811312
** Change Description:  Coverity/MISRA fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1744046
** Change Description:  Misra Fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  23/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1634375
** Change Description:  Coverity/MISRA Fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  16/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1632871, 1655512, 1660171
** Change Description:  SetLowQCurrent interface is updated to support configuration interface
** 						Datatype updated for GetLowQCurrent
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/01/2020
** CDSID             :  dkasiman
** Traceability      :  RTC 1380314
** Change Description:  Coverity/Misra fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  25/March/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1297724
** Change Description:  SW rest and WD rest splitted to corressponding MACRO's
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  18/6/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1137720
** Change Description:  warnings fixed and removed routine control status for SW Reset
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  6/6/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1126958
** Change Description:  comments updated
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  31/05/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1126958
** Change Description:  included conditional compilation of features,removed SW Reset RC Stop and status functions
                        as SW Reset is not routine control type.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 23/05/2018
** CDSID             : athiyag2
** Traceability      : RTC 1113499
** Change Description: Initial version - ResetSleepDiagCdd Implementation for Turing Bookshelf.
**====================================================================================================================*/
#endif
#endif
