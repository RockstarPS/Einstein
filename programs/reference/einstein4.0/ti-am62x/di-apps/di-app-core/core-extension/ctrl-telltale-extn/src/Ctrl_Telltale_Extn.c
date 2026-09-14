//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2015] Visteon Corporation
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
#include "Ctrl_Telltale_Extn.h"
#include "Ctrl_Telltale_TypeCfg.h"
#include "Ctrl_TT_Cfg.h"
#include "Rte_CCtrl_Telltale.h"


/*============================================================================
 ** Function Name       : uint8 CtrlTtVoltageLviHvi(void)
 ** Description         : This function is used to check whether it is in normal voltage or undervoltage or OverVoltage
                          based on LVSD And HVSD Status
 **
 ** Input Parameters:   : index, l_turn_on_off, battery_status
 ** Outputs             : battery_Sts
 **==========================================================================*/

uint8 CtrlTtVoltageLviHvi(void)
{
    boolean fl_LVSD2_Status = FALSE;
    boolean fl_HVSD2_Status = FALSE;
    uint8 battery_Sts;

    RTE_READ_LVSD_FLAG(&fl_LVSD2_Status);

    RTE_READ_HVSD_FLAG(&fl_HVSD2_Status);  

    if(fl_LVSD2_Status == TRUE)
    {
        battery_Sts = eBatteryState_UnderVoltage;
    }
    else if(fl_HVSD2_Status == TRUE)
    {
        battery_Sts = eBatteryState_OverVoltage;
    }
    else
    {
        battery_Sts = eBatteryState_Normal;
    }

    return battery_Sts;
}

/*============================================================================
 ** Function Name       :uint8 CtrlTtCheckBatteryStatus(uint8 index, uint8 l_turn_on_off, uint8 battery_status)
 ** Description         :This function is used to check the Battery status for all the telltales.
 **
 ** Input Parameters:   : index, l_turn_on_off, battery_status
 ** Outputs             : TT_Status
 **==========================================================================*/

uint8 CtrlTtCheckBatteryStatus(uint8 index, uint8 l_turn_on_off, uint8 battery_status)
{

    uint8 TT_Status = l_turn_on_off;
    /*
    ** Check for LVI and HVI conditions and process the telltales
    */
    if (eBatteryState_UnderVoltage == battery_status)
    {
        if (tt_ctrl_ttconfig[index].LVSD_state == TT_TURN_ON)
       {
           /* If Low voltage is sensed and if the telltale's LVSD attribute is ON, turn the tt ON.*/
           TT_Status = TT_TURN_ON;
       }
        else
       {
           /* If Low voltage is sensed and if the telltale's LVSD attribute is OFF, turn the tt OFF.*/
           TT_Status = TT_TURN_OFF;

       }
    }
    else if (eBatteryState_OverVoltage == battery_status)
    {
        if (tt_ctrl_ttconfig[index].HVSD_state == TT_TURN_ON)
        {
            /* If High voltage is sensed and if the telltale's HVSD attribute is ON, turn the tt ON.*/
            TT_Status = TT_TURN_ON;
        }
        else
        {
            /* If High voltage is sensed and if the telltale's HVSD attribute is OFF, turn the tt OFF.*/
            TT_Status = TT_TURN_OFF;

        }
    }
    else
    {
    // do nothing
    }

    return TT_Status;
 }

/*============================================================================
 ** Function Name       : uint8 CtrlTtCheckProveout(uint8 index, uint8 l_turn_on_off, uint8 tt_state_byte)
 ** Description         : This function is used to check the Battery status for all the telltales.
 **
 ** Input Parameters:   : index, l_turn_on_off, tt_state_byte
 ** Outputs             : TT_Status
 **==========================================================================*/

uint8 CtrlTtCheckProveout(uint8 index, uint8 l_turn_on_off, uint8 tt_state_byte)
{
    uint8 TT_Status = l_turn_on_off;
	  return TT_Status;
}

/*============================================================================
 ** Function Name       : void CtrlTt_InitProveout (uint8 CtrlTtIgnSts)
 ** Description         : This function is used to initialize the proveout variable
 **
 ** Input Parameters:   : CtrlTtIgnSts
 ** Outputs             : void
 **==========================================================================*/
void CtrlTt_InitProveout (uint8 CtrlTtIgnSts)
{
    /*/Do nothing*/
}
