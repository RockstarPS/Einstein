/********************************************************************************************************************
 *                                   C O P Y R I G H T                                                               *
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
 *    @file DisplayCdd_Cfg.c
 *    @ingroup Display CDD Configuration
 *    @brief This is Display Pre-compile time configuration header file. It contains definitions of pre-compile time
 *    configuration parameters for the Display module.
 ********************************************************************************************************************/
/*****************************************************************************
 *                                 Include Files                              *
 ******************************************************************************/
#include "DisplayCdd_Cfg.h"
#include "DisplayCdd_Types.h"
#include "DisplayIfCdd.h"
#include "CDD_EcuPowerM.h"
#include "Rte_CDisplayCdd_Type.h"
#include "Rte_CFltMExt_Type.h"
#include "FltM.h"
#include "Det.h"
#include "MemLib.h"

#ifdef VIP_UART_TEST
#include "DltExt.h"
#endif

#ifdef BOOT_KPI_LOG_EN
#include "boot_kpi_r5_asr.h"
#endif /*BOOT_KPI_LOG_EN*/

/*=====================================================================================================================
  CONSTANTS & TYPES
=====================================================================================================================*/

#define CDisplayCdd_START_SEC_CONST_UNSPECIFIED
#include <CDisplayCdd_MemMap.h>

/*! Hold the Display driver  related information  */
/*!!! Input DB also different for different displays*/

#define CDisplayCdd_STOP_SEC_CONST_UNSPECIFIED
#include <CDisplayCdd_MemMap.h>

#define CDisplayCdd_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include <CDisplayCdd_MemMap.h>

#define CDisplayCdd_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include <CDisplayCdd_MemMap.h>

static sDisplayCommonInfo DisplayDrvInfo[cDISPLAYCDD_MAX_DEVICE];
static SDisplayInfo DisplayCdd_Cfg_InfoTable[cDISPLAYCDD_MAX_DEVICE];
#define CDisplayCdd_START_SEC_CODE
#include <CDisplayCdd_MemMap.h>
/*!*****************************************************************************************************************
 *   @brief      The function used to do the preInit condition check
 *   @param[in]
 *   @return  void
 *	ALGO---
 *	1. Check basicPowerUP and NVM read all completed
 *	2. If not Wait until it is completed then retun E_OK
 *	3.. Decounce time of 500msec at start - for toyota and hyundai program
 ********************************************************************************************************************/

Std_ReturnType DisplayCdd_Cfg_PreInitCheck(void)
{
  return 0u;
}
void DisplayCdd_Cfg_Init(void)
{
    uint8 u8DevIdx;

    for( u8DevIdx = 0U; u8DevIdx < cDISPLAYCDD_MAX_DEVICE; u8DevIdx++ )
    {
        DisplayDrvInfo[u8DevIdx].DisplayDrvStateMachine = eDisplayIdleState;
        DisplayDrvInfo[u8DevIdx].RequesterPowerState    = eDisplayIdle;
    }
}

void DisplayCdd_Cfg_DeInit(void)
{
    uint8 u8DevIdx;

    for( u8DevIdx = 0U; u8DevIdx < cDISPLAYCDD_MAX_DEVICE; u8DevIdx++ )
    {
        DisplayDrvInfo[u8DevIdx].DisplayDrvStateMachine = eDisplayIdleState;
        DisplayDrvInfo[u8DevIdx].RequesterPowerState    = eDisplayIdle;
    }
}
/*!*****************************************************************************************************************
 *   @brief       This function is used to set thw Display state
 *   @param[in]   None
 *   @return      None
 ********************************************************************************************************************/
Std_ReturnType DisplayCddCfg_SetState(EDisplayType DeviceId, EDisplayPowerState NewPowerState)
{
    Std_ReturnType Ret_Val = E_NOT_OK;
    if (DeviceId < cDISPLAYCDD_MAX_DEVICE) /*  Added For Coverity Fix*/
    {
        DisplayCdd_Cfg_InfoTable[DeviceId].DevicePowerState = NewPowerState;
        Ret_Val = E_OK;
    }
    else
    {
        /*do nothing*/
    }
    return Ret_Val;
}
EDisplaypowerStatesHelper DisplayCdd_Cfg_GetDisplayDrvStateMachine(void)
{
    return DisplayDrvInfo[Device].DisplayDrvStateMachine;
}

/*!*****************************************************************************************************************
 *   @brief      The function is to start BIST
 *   @param[in]  DeviceId, PatternId
 *   @return  Std_ReturnType
 ********************************************************************************************************************/
Std_ReturnType DisplayCddCfg_BistTest_Start(EDisplayType DeviceId, EBistPatternType BistPatternType, uint8 PatternHoldTime)
{

  (void)DeviceId;
  (void)BistPatternType;
  (void)PatternHoldTime;
  return E_OK;
}

/*!*****************************************************************************************************************
 *   @brief      The function is to stop BIST
 *   @param[in]  void
 *   @return     void
 *******************************************************************************************************************/
Std_ReturnType DisplayCddCfg_BistTest_Stop(EDisplayType DeviceId)
{
  (void)DeviceId;
  return E_OK;
}
/*!*****************************************************************************************************************
 *   @brief       This function is used to perform power handle and Fault Monitor of Tianma Display
 *   @param[in]   None
 *   @return      None
 ********************************************************************************************************************/

void DisplayCdd_TIMainFunction(uint8 DeviceIndex)
{
    (void)DeviceIndex;
    EcuPowerM_DevicePwrStatusType dispPowerstate = 255U;
    DisplaySetPowerL displayMgrPowerUp;
    DisplayCurrentStateL Displaystatus = {0};
#ifndef EHMI_ENABLE
    switch (DisplayDrvInfo[Device].DisplayDrvStateMachine)
    {
    case eDisplayIdleState:
        if (eDisplayPowerON == DisplayCdd_Cfg_InfoTable[DeviceIndex].DevicePowerState)
        {
            DisplayDrvInfo[Device].DisplayDrvStateMachine = eDisplayEnableState;
        }
        break;
    case eDisplayEnableState:
        displayMgrPowerUp.displayId = 0;
        displayMgrPowerUp.state = DisplayPowerL_On;
        (void)EcuPowerM_GetDeviceStatus(1u, &dispPowerstate);
        if (dispPowerstate == ECUPOWERM_DEV_PWR_STATUS_COMPLETED)
        {
#ifdef VIP_UART_TEST
#if (DLTEXT_UART_PRINT == STD_ON)
            (void)DltExt_Uart_Printf("\r\n Display Power Enabled ! \r\n");
#endif
#endif
            (void)EcuAppM_Ucl_DisplayMgrPowerUp(&displayMgrPowerUp);
            DisplayDrvInfo[Device].DisplayDrvStateMachine = eDisplayPowerWaitState;
        }
        else
        {
            (void)EcuPowerM_RequestPower(1u, ECUPOWERM_RQST_DEVICE_POWERUP);
        }
        break;
    case eDisplayPowerWaitState:
        (void)EcuAppM_Ucl_DisplayStatus(&Displaystatus);
        if (Displaystatus.state == EDisplayState_On)
        {
#ifdef BOOT_KPI_LOG_EN
            BOOT_KPI_LOG(KPI_ID_VIP_UCL_LINKUP, "UCLLINKUP");
#endif /*BOOT_KPI_LOG_EN*/
#ifdef VIP_UART_TEST
#if (DLTEXT_UART_PRINT == STD_ON)
            (void)DltExt_Uart_Printf("\r\n Display UCL Status Received !\r\n");
#endif
#endif
            DisplayDrvInfo[Device].DisplayDrvStateMachine = eBackLightEnableState;
        }
        break;
    case eBackLightEnableState:
        if (E_OK == CBacklightCdd_RequestPower(0U, BACKLIGHTDRVCDD_POWER_STATE_POWER_ON))
        {
            DisplayDrvInfo[Device].DisplayDrvStateMachine = eBackLightEnableWaitState;
        }
        break;
    case eBackLightEnableWaitState:
#ifdef VIP_UART_TEST
#if (DLTEXT_UART_PRINT == STD_ON)
        (void)DltExt_Uart_Printf("\r\n Display BL Enabled ! \r\n");
#endif
#endif
        DisplayDrvInfo[Device].DisplayDrvStateMachine = eDisplayWaitState;
        break;
    case eDisplayWaitState:
        if (eDisplayPowerOFF == DisplayCdd_Cfg_InfoTable[Device].DevicePowerState)
        {
            DisplayDrvInfo[Device].DisplayDrvStateMachine = eBackLightDisableState;
        }
        break;
    case eBackLightDisableState:
        if (E_OK == CBacklightCdd_RequestPower(0U, BACKLIGHTDRVCDD_POWER_STATE_POWER_OFF))                      
        {
            DisplayDrvInfo[Device].DisplayDrvStateMachine =
                eBackLightDisableWaitState;
        }
        break;
    case eBackLightDisableWaitState:
        DisplayDrvInfo[Device].DisplayDrvStateMachine =
            eDisplayDisableState;
        break;
    default:
        break;
    }
#endif
}
#define CDisplayCdd_STOP_SEC_CODE
#include <CDisplayCdd_MemMap.h>
/*******************************************************************************************************************
 *                                 END OF FILE                                                                      *
 ********************************************************************************************************************/

/*----------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
Date              : 20/May/2025
By                : abasavar
Traceability      : PE4TI29141-8109
Change Description: Updated Version
-------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
Date              : 30/Jun/2025
By                : abasavar
Traceability      : PE4TI29141-9005
Change Description: BL-Monitoring SM update
-------------------------------------------------------------------------------*/
